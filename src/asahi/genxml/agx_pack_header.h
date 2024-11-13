/*
 * Copyright 2016 Intel Corporation
 * Copyright 2016 Broadcom
 * Copyright 2020 Collabora, Ltd.
 * Copyright 2024 Alyssa Rosenzweig
 * SPDX-License-Identifier: MIT
 */

#pragma once

#ifndef __OPENCL_VERSION__
#include <inttypes.h>
#include <stdio.h>
#include "util/bitpack_helpers.h"
#include "util/half_float.h"
#define FILE_TYPE FILE
#define CONSTANT_ const
#define GLOBAL_
#else

#include "libagx.h"
#define assert(x)
#define FILE_TYPE void
#define CONSTANT_ constant
#define GLOBAL_   global

static uint64_t
util_bitpack_uint(uint64_t v, uint32_t start, uint32_t end)
{
   return v << start;
}

static uint64_t
util_bitpack_sint(int64_t v, uint32_t start, uint32_t end)
{
   const int bits = end - start + 1;
   const uint64_t mask = (bits == 64) ? ~((uint64_t)0) : (1ull << bits) - 1;
   return (v & mask) << start;
}

static uint32_t
util_bitpack_float(float v)
{
   union {
      float f;
      uint32_t dw;
   } x;
   x.f = v;
   return x.dw;
}

static inline float
uif(uint32_t ui)
{
   union {
      float f;
      uint32_t dw;
   } fi;
   fi.dw = ui;
   return fi.f;
}

#define DIV_ROUND_UP(A, B)      (((A) + (B) - 1) / (B))
#define CLAMP(X, MIN, MAX)      ((X) > (MIN) ? ((X) > (MAX) ? (MAX) : (X)) : (MIN))
#define ALIGN_POT(x, pot_align) (((x) + (pot_align) - 1) & ~((pot_align) - 1))

static inline unsigned
util_logbase2(unsigned n)
{
   return ((sizeof(unsigned) * 8 - 1) - __builtin_clz(n | 1));
}

static inline int64_t
util_sign_extend(uint64_t val, unsigned width)
{
   unsigned shift = 64 - width;
   return (int64_t)(val << shift) >> shift;
}

static inline uint16_t
_mesa_float_to_half(float f)
{
   union {
      half h;
      uint16_t w;
   } hi;
   hi.h = convert_half(f);
   return hi.w;
}

static inline float
_mesa_half_to_float(uint16_t w)
{
   union {
      half h;
      uint16_t w;
   } hi;
   hi.w = w;
   return convert_float(hi.h);
}

#endif

#define __gen_unpack_float(x, y, z) uif(__gen_unpack_uint(x, y, z))
#define __gen_unpack_half(x, y, z)                                             \
   _mesa_half_to_float(__gen_unpack_uint(x, y, z))

static inline uint64_t
__gen_unpack_uint(CONSTANT_ uint32_t *restrict cl, uint32_t start, uint32_t end)
{
   uint64_t val = 0;
   const int width = end - start + 1;
   const uint64_t mask =
      (width == 64) ? ~((uint64_t)0) : ((uint64_t)1 << width) - 1;

   for (unsigned word = start / 32; word < (end / 32) + 1; word++) {
      val |= ((uint64_t)cl[word]) << ((word - start / 32) * 32);
   }

   return (val >> (start % 32)) & mask;
}

/*
 * LODs are 4:6 fixed point. We must clamp before converting to integers to
 * avoid undefined behaviour for out-of-bounds inputs like +/- infinity.
 */
static inline uint32_t
__gen_pack_lod(float f, uint32_t start, uint32_t end)
{
   uint32_t fixed = CLAMP(f * (1 << 6), 0 /* 0.0 */, 0x380 /* 14.0 */);
   return util_bitpack_uint(fixed, start, end);
}

static inline float
__gen_unpack_lod(CONSTANT_ uint32_t *restrict cl, uint32_t start, uint32_t end)
{
   return ((float)__gen_unpack_uint(cl, start, end)) / (1 << 6);
}

static inline uint64_t
__gen_unpack_sint(CONSTANT_ uint32_t *restrict cl, uint32_t start, uint32_t end)
{
   int size = end - start + 1;
   int64_t val = __gen_unpack_uint(cl, start, end);

   return util_sign_extend(val, size);
}

static inline uint64_t
__gen_to_groups(uint32_t value, uint32_t group_size, uint32_t length)
{
   /* Zero is not representable, clamp to minimum */
   if (value == 0)
      return 1;

   /* Round up to the nearest number of groups */
   uint32_t groups = DIV_ROUND_UP(value, group_size);

   /* The 0 encoding means "all" */
   if (groups == (1ull << length))
      return 0;

   /* Otherwise it's encoded as the identity */
   assert(groups < (1u << length) && "out of bounds");
   assert(groups >= 1 && "exhaustive");
   return groups;
}

static inline uint64_t
__gen_from_groups(uint32_t value, uint32_t group_size, uint32_t length)
{
   return group_size * (value ? value : (1 << length));
}

#define agx_pack(dst, T, name)                                                 \
   for (struct AGX_##T name = {AGX_##T##_header},                              \
                       *_loop_count = (GLOBAL_ void *)((uintptr_t)0);          \
        (uintptr_t)_loop_count < 1; (                                          \
           {                                                                   \
              AGX_##T##_pack((GLOBAL_ uint32_t *)(dst), &name);                \
              _loop_count = (GLOBAL_ void *)(((uintptr_t)_loop_count) + 1);    \
           }))

#define agx_unpack(fp, src, T, name)                                           \
   struct AGX_##T name;                                                        \
   AGX_##T##_unpack(fp, (CONSTANT_ uint8_t *)(src), &name)

#define agx_print(fp, T, var, indent) AGX_##T##_print(fp, &(var), indent)

static inline void
agx_merge_helper(uint32_t *dst, const uint32_t *src, size_t bytes)
{
   assert((bytes & 3) == 0);

   for (unsigned i = 0; i < (bytes / 4); ++i)
      dst[i] |= src[i];
}

#define agx_merge(packed1, packed2, type)                                      \
   agx_merge_helper((packed1).opaque, (packed2).opaque, AGX_##type##_LENGTH)

#if defined(NDEBUG) || defined(__OPENCL_VERSION__)
#define agx_genxml_validate_bounds(a, b, c)
#define agx_genxml_validate_mask(a, b, c, d, e) true
#define agx_genxml_validate_exact(a, b, c, d)   true
#else
static inline void
agx_genxml_validate_bounds(const char *name, uint64_t value, uint64_t bound)
{
   if (unlikely(value >= bound)) {
      fprintf(stderr, "%s out-of-bounds, got 0x%" PRIx64 ", max %" PRIx64 "\n",
              name, value, bound);

      unreachable("Out-of-bounds pack");
   }
}

static inline bool
agx_genxml_validate_mask(FILE *fp, const char *name, const void *cl_,
                         uint32_t index, uint32_t bad_mask)
{
   const uint32_t *cl = (const uint32_t *)cl_;
   uint32_t bad = cl[index] & bad_mask;

   if (bad && fp != NULL) {
      fprintf(
         fp,
         "XXX: Unknown field of %s unpacked at word %u got %X, bad mask %X\n",
         name, index, cl[index], bad);
   }

   return bad == 0;
}

static bool
agx_genxml_validate_exact(FILE *fp, const char *name, uint64_t value,
                          uint64_t exact)
{
   if (value != exact && fp != NULL) {
      fprintf(fp, "XXX: Expected %s to equal %" PRIx64 " but got %" PRIx64 "\n",
              name, value, exact);
   }

   return value == exact;
}

#endif

/* Everything after this is autogenerated from XML. Do not hand edit. */
