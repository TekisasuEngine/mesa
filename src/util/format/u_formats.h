/**************************************************************************
 *
 * Copyright 2007 VMware, Inc.
 * Copyright (c) 2008 VMware, Inc.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

#ifndef U_FORMATS_H_
#define U_FORMATS_H_

#include "util/detect.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Formats for textures, surfaces and vertex data
 */
enum pipe_format {
   PIPE_FORMAT_NONE,
   /* Vertex formats must be first and must be <= 255. */
   PIPE_FORMAT_R64_UINT,    /**< raw doubles (ARB_vertex_attrib_64bit) */
   PIPE_FORMAT_R64G64_UINT,
   PIPE_FORMAT_R64G64B64_UINT,
   PIPE_FORMAT_R64G64B64A64_UINT,
   PIPE_FORMAT_R64_SINT,
   PIPE_FORMAT_R64G64_SINT,
   PIPE_FORMAT_R64G64B64_SINT,
   PIPE_FORMAT_R64G64B64A64_SINT,
   PIPE_FORMAT_R64_FLOAT,   /**< doubles converted to float */
   PIPE_FORMAT_R64G64_FLOAT,
   PIPE_FORMAT_R64G64B64_FLOAT,
   PIPE_FORMAT_R64G64B64A64_FLOAT,
   PIPE_FORMAT_R32_FLOAT,
   PIPE_FORMAT_R32G32_FLOAT,
   PIPE_FORMAT_R32G32B32_FLOAT,
   PIPE_FORMAT_R32G32B32A32_FLOAT,
   PIPE_FORMAT_R32_UNORM,
   PIPE_FORMAT_R32G32_UNORM,
   PIPE_FORMAT_R32G32B32_UNORM,
   PIPE_FORMAT_R32G32B32A32_UNORM,
   PIPE_FORMAT_R32_USCALED,
   PIPE_FORMAT_R32G32_USCALED,
   PIPE_FORMAT_R32G32B32_USCALED,
   PIPE_FORMAT_R32G32B32A32_USCALED,
   PIPE_FORMAT_R32_SNORM,
   PIPE_FORMAT_R32G32_SNORM,
   PIPE_FORMAT_R32G32B32_SNORM,
   PIPE_FORMAT_R32G32B32A32_SNORM,
   PIPE_FORMAT_R32_SSCALED,
   PIPE_FORMAT_R32G32_SSCALED,
   PIPE_FORMAT_R32G32B32_SSCALED,
   PIPE_FORMAT_R32G32B32A32_SSCALED,
   PIPE_FORMAT_R16_UNORM,
   PIPE_FORMAT_R16G16_UNORM,
   PIPE_FORMAT_R16G16B16_UNORM,
   PIPE_FORMAT_R16G16B16A16_UNORM,
   PIPE_FORMAT_R16_USCALED,
   PIPE_FORMAT_R16G16_USCALED,
   PIPE_FORMAT_R16G16B16_USCALED,
   PIPE_FORMAT_R16G16B16A16_USCALED,
   PIPE_FORMAT_R16_SNORM,
   PIPE_FORMAT_R16G16_SNORM,
   PIPE_FORMAT_R16G16B16_SNORM,
   PIPE_FORMAT_R16G16B16A16_SNORM,
   PIPE_FORMAT_R16_SSCALED,
   PIPE_FORMAT_R16G16_SSCALED,
   PIPE_FORMAT_R16G16B16_SSCALED,
   PIPE_FORMAT_R16G16B16A16_SSCALED,
   PIPE_FORMAT_R8_UNORM,
   PIPE_FORMAT_R8G8_UNORM,
   PIPE_FORMAT_R8G8B8_UNORM,
   PIPE_FORMAT_B8G8R8_UNORM,
   PIPE_FORMAT_R8G8B8A8_UNORM,
   PIPE_FORMAT_B8G8R8A8_UNORM,
   PIPE_FORMAT_R8_USCALED,
   PIPE_FORMAT_R8G8_USCALED,
   PIPE_FORMAT_R8G8B8_USCALED,
   PIPE_FORMAT_B8G8R8_USCALED,
   PIPE_FORMAT_R8G8B8A8_USCALED,
   PIPE_FORMAT_B8G8R8A8_USCALED,
   PIPE_FORMAT_A8B8G8R8_USCALED,
   PIPE_FORMAT_R8_SNORM,
   PIPE_FORMAT_R8G8_SNORM,
   PIPE_FORMAT_R8G8B8_SNORM,
   PIPE_FORMAT_B8G8R8_SNORM,
   PIPE_FORMAT_R8G8B8A8_SNORM,
   PIPE_FORMAT_B8G8R8A8_SNORM,
   PIPE_FORMAT_R8_SSCALED,
   PIPE_FORMAT_R8G8_SSCALED,
   PIPE_FORMAT_R8G8B8_SSCALED,
   PIPE_FORMAT_B8G8R8_SSCALED,
   PIPE_FORMAT_R8G8B8A8_SSCALED,
   PIPE_FORMAT_B8G8R8A8_SSCALED,
   PIPE_FORMAT_A8B8G8R8_SSCALED,
   PIPE_FORMAT_A8R8G8B8_UNORM,
   PIPE_FORMAT_R32_FIXED,
   PIPE_FORMAT_R32G32_FIXED,
   PIPE_FORMAT_R32G32B32_FIXED,
   PIPE_FORMAT_R32G32B32A32_FIXED,
   PIPE_FORMAT_R16_FLOAT,
   PIPE_FORMAT_R16G16_FLOAT,
   PIPE_FORMAT_R16G16B16_FLOAT,
   PIPE_FORMAT_R16G16B16A16_FLOAT,
   PIPE_FORMAT_R8_UINT,
   PIPE_FORMAT_R8G8_UINT,
   PIPE_FORMAT_R8G8B8_UINT,
   PIPE_FORMAT_B8G8R8_UINT,
   PIPE_FORMAT_R8G8B8A8_UINT,
   PIPE_FORMAT_B8G8R8A8_UINT,
   PIPE_FORMAT_R8_SINT,
   PIPE_FORMAT_R8G8_SINT,
   PIPE_FORMAT_R8G8B8_SINT,
   PIPE_FORMAT_B8G8R8_SINT,
   PIPE_FORMAT_R8G8B8A8_SINT,
   PIPE_FORMAT_B8G8R8A8_SINT,
   PIPE_FORMAT_R16_UINT,
   PIPE_FORMAT_R16G16_UINT,
   PIPE_FORMAT_R16G16B16_UINT,
   PIPE_FORMAT_R16G16B16A16_UINT,
   PIPE_FORMAT_R16_SINT,
   PIPE_FORMAT_R16G16_SINT,
   PIPE_FORMAT_R16G16B16_SINT,
   PIPE_FORMAT_R16G16B16A16_SINT,
   PIPE_FORMAT_R32_UINT,
   PIPE_FORMAT_R32G32_UINT,
   PIPE_FORMAT_R32G32B32_UINT,
   PIPE_FORMAT_R32G32B32A32_UINT,
   PIPE_FORMAT_R32_SINT,
   PIPE_FORMAT_R32G32_SINT,
   PIPE_FORMAT_R32G32B32_SINT,
   PIPE_FORMAT_R32G32B32A32_SINT,

   PIPE_FORMAT_R10G10B10A2_UNORM,
   PIPE_FORMAT_R10G10B10A2_SNORM,
   PIPE_FORMAT_R10G10B10A2_USCALED,
   PIPE_FORMAT_R10G10B10A2_SSCALED,

   PIPE_FORMAT_B10G10R10A2_UNORM,
   PIPE_FORMAT_B10G10R10A2_SNORM,
   PIPE_FORMAT_B10G10R10A2_USCALED,
   PIPE_FORMAT_B10G10R10A2_SSCALED,

   PIPE_FORMAT_R11G11B10_FLOAT,

   PIPE_FORMAT_R10G10B10A2_UINT,
   PIPE_FORMAT_R10G10B10A2_SINT,

   PIPE_FORMAT_B10G10R10A2_UINT,
   PIPE_FORMAT_B10G10R10A2_SINT,

   /* End of vertex formats. */

   /* Texture-only formats are below. */
   PIPE_FORMAT_B8G8R8X8_UNORM,
   PIPE_FORMAT_X8B8G8R8_UNORM,
   PIPE_FORMAT_X8R8G8B8_UNORM,
   PIPE_FORMAT_B5G5R5A1_UNORM,
   PIPE_FORMAT_R4G4B4A4_UNORM,
   PIPE_FORMAT_B4G4R4A4_UNORM,
   PIPE_FORMAT_R5G6B5_UNORM,
   PIPE_FORMAT_B5G6R5_UNORM,
   PIPE_FORMAT_L8_UNORM,    /**< ubyte luminance */
   PIPE_FORMAT_A8_UNORM,    /**< ubyte alpha */
   PIPE_FORMAT_I8_UNORM,    /**< ubyte intensity */
   PIPE_FORMAT_L8A8_UNORM,  /**< ubyte alpha, luminance */
   PIPE_FORMAT_L16_UNORM,   /**< ushort luminance */
   PIPE_FORMAT_UYVY,
   PIPE_FORMAT_YUYV,
   PIPE_FORMAT_Z16_UNORM,
   PIPE_FORMAT_Z16_UNORM_S8_UINT,
   PIPE_FORMAT_Z32_UNORM,
   PIPE_FORMAT_Z32_FLOAT,
   PIPE_FORMAT_Z24_UNORM_S8_UINT,
   PIPE_FORMAT_S8_UINT_Z24_UNORM,
   PIPE_FORMAT_Z24X8_UNORM,
   PIPE_FORMAT_X8Z24_UNORM,
   PIPE_FORMAT_S8_UINT,     /**< ubyte stencil */

   /* sRGB formats */
   PIPE_FORMAT_L8_SRGB,
   PIPE_FORMAT_R8_SRGB,
   PIPE_FORMAT_L8A8_SRGB,
   PIPE_FORMAT_R8G8_SRGB,
   PIPE_FORMAT_R8G8B8_SRGB,
   PIPE_FORMAT_B8G8R8_SRGB,
   PIPE_FORMAT_A8B8G8R8_SRGB,
   PIPE_FORMAT_X8B8G8R8_SRGB,
   PIPE_FORMAT_B8G8R8A8_SRGB,
   PIPE_FORMAT_B8G8R8X8_SRGB,
   PIPE_FORMAT_A8R8G8B8_SRGB,
   PIPE_FORMAT_X8R8G8B8_SRGB,
   PIPE_FORMAT_R8G8B8A8_SRGB,

   /* compressed formats */
   PIPE_FORMAT_DXT1_RGB,
   PIPE_FORMAT_DXT1_RGBA,
   PIPE_FORMAT_DXT3_RGBA,
   PIPE_FORMAT_DXT5_RGBA,

   /* sRGB, compressed */
   PIPE_FORMAT_DXT1_SRGB,
   PIPE_FORMAT_DXT1_SRGBA,
   PIPE_FORMAT_DXT3_SRGBA,
   PIPE_FORMAT_DXT5_SRGBA,

   /* rgtc compressed */
   PIPE_FORMAT_RGTC1_UNORM,
   PIPE_FORMAT_RGTC1_SNORM,
   PIPE_FORMAT_RGTC2_UNORM,
   PIPE_FORMAT_RGTC2_SNORM,

   PIPE_FORMAT_R8G8_B8G8_UNORM,
   PIPE_FORMAT_G8R8_G8B8_UNORM,

   /* mixed formats */
   PIPE_FORMAT_R8SG8SB8UX8U_NORM,
   PIPE_FORMAT_R5SG5SB6U_NORM,

   /* TODO: re-order these */
   PIPE_FORMAT_A8B8G8R8_UNORM,
   PIPE_FORMAT_B5G5R5X1_UNORM,
   PIPE_FORMAT_R9G9B9E5_FLOAT,
   PIPE_FORMAT_Z32_FLOAT_S8X24_UINT,
   PIPE_FORMAT_R1_UNORM,
   PIPE_FORMAT_R10G10B10X2_USCALED,
   PIPE_FORMAT_R10G10B10X2_SNORM,
   PIPE_FORMAT_L4A4_UNORM,
   PIPE_FORMAT_A2R10G10B10_UNORM,
   PIPE_FORMAT_A2B10G10R10_UNORM,
   PIPE_FORMAT_R10SG10SB10SA2U_NORM,
   PIPE_FORMAT_R8G8Bx_SNORM,
   PIPE_FORMAT_R8G8B8X8_UNORM,
   PIPE_FORMAT_B4G4R4X4_UNORM,

   /* some stencil samplers formats */
   PIPE_FORMAT_X24S8_UINT,
   PIPE_FORMAT_S8X24_UINT,
   PIPE_FORMAT_X32_S8X24_UINT,

   PIPE_FORMAT_R3G3B2_UNORM,
   PIPE_FORMAT_B2G3R3_UNORM,
   PIPE_FORMAT_L16A16_UNORM,
   PIPE_FORMAT_A16_UNORM,
   PIPE_FORMAT_I16_UNORM,

   PIPE_FORMAT_LATC1_UNORM,
   PIPE_FORMAT_LATC1_SNORM,
   PIPE_FORMAT_LATC2_UNORM,
   PIPE_FORMAT_LATC2_SNORM,

   PIPE_FORMAT_A8_SNORM,
   PIPE_FORMAT_L8_SNORM,
   PIPE_FORMAT_L8A8_SNORM,
   PIPE_FORMAT_I8_SNORM,
   PIPE_FORMAT_A16_SNORM,
   PIPE_FORMAT_L16_SNORM,
   PIPE_FORMAT_L16A16_SNORM,
   PIPE_FORMAT_I16_SNORM,

   PIPE_FORMAT_A16_FLOAT,
   PIPE_FORMAT_L16_FLOAT,
   PIPE_FORMAT_L16A16_FLOAT,
   PIPE_FORMAT_I16_FLOAT,
   PIPE_FORMAT_A32_FLOAT,
   PIPE_FORMAT_L32_FLOAT,
   PIPE_FORMAT_L32A32_FLOAT,
   PIPE_FORMAT_I32_FLOAT,

   PIPE_FORMAT_YV12,
   PIPE_FORMAT_YV16,
   PIPE_FORMAT_IYUV,  /**< aka I420 */
   PIPE_FORMAT_NV12,
   PIPE_FORMAT_NV21,

   PIPE_FORMAT_Y8_400_UNORM,
   /* PIPE_FORMAT_Y8_U8_V8_420_UNORM = IYUV */
   /* PIPE_FORMAT_Y8_U8V8_420_UNORM = NV12 */
   PIPE_FORMAT_Y8_U8_V8_422_UNORM,
   PIPE_FORMAT_Y8_U8V8_422_UNORM,
   PIPE_FORMAT_Y8_U8_V8_444_UNORM,

   PIPE_FORMAT_Y16_U16_V16_420_UNORM,
    /* PIPE_FORMAT_Y16_U16V16_420_UNORM */
   PIPE_FORMAT_Y16_U16_V16_422_UNORM,
   PIPE_FORMAT_Y16_U16V16_422_UNORM,
   PIPE_FORMAT_Y16_U16_V16_444_UNORM,

   PIPE_FORMAT_A4R4_UNORM,
   PIPE_FORMAT_R4A4_UNORM,
   PIPE_FORMAT_R8A8_UNORM,
   PIPE_FORMAT_A8R8_UNORM,

   PIPE_FORMAT_A8_UINT,
   PIPE_FORMAT_I8_UINT,
   PIPE_FORMAT_L8_UINT,
   PIPE_FORMAT_L8A8_UINT,

   PIPE_FORMAT_A8_SINT,
   PIPE_FORMAT_I8_SINT,
   PIPE_FORMAT_L8_SINT,
   PIPE_FORMAT_L8A8_SINT,

   PIPE_FORMAT_A16_UINT,
   PIPE_FORMAT_I16_UINT,
   PIPE_FORMAT_L16_UINT,
   PIPE_FORMAT_L16A16_UINT,

   PIPE_FORMAT_A16_SINT,
   PIPE_FORMAT_I16_SINT,
   PIPE_FORMAT_L16_SINT,
   PIPE_FORMAT_L16A16_SINT,

   PIPE_FORMAT_A32_UINT,
   PIPE_FORMAT_I32_UINT,
   PIPE_FORMAT_L32_UINT,
   PIPE_FORMAT_L32A32_UINT,

   PIPE_FORMAT_A32_SINT,
   PIPE_FORMAT_I32_SINT,
   PIPE_FORMAT_L32_SINT,
   PIPE_FORMAT_L32A32_SINT,

   PIPE_FORMAT_A8R8G8B8_UINT,
   PIPE_FORMAT_A8B8G8R8_UINT,
   PIPE_FORMAT_A2R10G10B10_UINT,
   PIPE_FORMAT_A2B10G10R10_UINT,
   PIPE_FORMAT_R5G6B5_UINT,
   PIPE_FORMAT_B5G6R5_UINT,
   PIPE_FORMAT_R5G5B5A1_UINT,
   PIPE_FORMAT_B5G5R5A1_UINT,
   PIPE_FORMAT_A1R5G5B5_UINT,
   PIPE_FORMAT_A1B5G5R5_UINT,
   PIPE_FORMAT_R4G4B4A4_UINT,
   PIPE_FORMAT_B4G4R4A4_UINT,
   PIPE_FORMAT_A4R4G4B4_UINT,
   PIPE_FORMAT_A4B4G4R4_UINT,
   PIPE_FORMAT_R3G3B2_UINT,
   PIPE_FORMAT_B2G3R3_UINT,

   PIPE_FORMAT_ETC1_RGB8,

   PIPE_FORMAT_R8G8_R8B8_UNORM,
   PIPE_FORMAT_G8R8_B8R8_UNORM,

   PIPE_FORMAT_R8G8B8X8_SNORM,
   PIPE_FORMAT_R8G8B8X8_SRGB,
   PIPE_FORMAT_R8G8B8X8_UINT,
   PIPE_FORMAT_R8G8B8X8_SINT,
   PIPE_FORMAT_B10G10R10X2_UNORM,
   PIPE_FORMAT_R16G16B16X16_UNORM,
   PIPE_FORMAT_R16G16B16X16_SNORM,
   PIPE_FORMAT_R16G16B16X16_FLOAT,
   PIPE_FORMAT_R16G16B16X16_UINT,
   PIPE_FORMAT_R16G16B16X16_SINT,
   PIPE_FORMAT_R32G32B32X32_FLOAT,
   PIPE_FORMAT_R32G32B32X32_UINT,
   PIPE_FORMAT_R32G32B32X32_SINT,

   PIPE_FORMAT_R8A8_SNORM,
   PIPE_FORMAT_R16A16_UNORM,
   PIPE_FORMAT_R16A16_SNORM,
   PIPE_FORMAT_R16A16_FLOAT,
   PIPE_FORMAT_R32A32_FLOAT,
   PIPE_FORMAT_R8A8_UINT,
   PIPE_FORMAT_R8A8_SINT,
   PIPE_FORMAT_R16A16_UINT,
   PIPE_FORMAT_R16A16_SINT,
   PIPE_FORMAT_R32A32_UINT,
   PIPE_FORMAT_R32A32_SINT,

   PIPE_FORMAT_B5G6R5_SRGB,

   PIPE_FORMAT_BPTC_RGBA_UNORM,
   PIPE_FORMAT_BPTC_SRGBA,
   PIPE_FORMAT_BPTC_RGB_FLOAT,
   PIPE_FORMAT_BPTC_RGB_UFLOAT,

   PIPE_FORMAT_G8R8_UNORM,
   PIPE_FORMAT_G8R8_SNORM,
   PIPE_FORMAT_G16R16_UNORM,
   PIPE_FORMAT_G16R16_SNORM,

   PIPE_FORMAT_A8B8G8R8_SNORM,
   PIPE_FORMAT_X8B8G8R8_SNORM,

   PIPE_FORMAT_ETC2_RGB8,
   PIPE_FORMAT_ETC2_SRGB8,
   PIPE_FORMAT_ETC2_RGB8A1,
   PIPE_FORMAT_ETC2_SRGB8A1,
   PIPE_FORMAT_ETC2_RGBA8,
   PIPE_FORMAT_ETC2_SRGBA8,
   PIPE_FORMAT_ETC2_R11_UNORM,
   PIPE_FORMAT_ETC2_R11_SNORM,
   PIPE_FORMAT_ETC2_RG11_UNORM,
   PIPE_FORMAT_ETC2_RG11_SNORM,

   PIPE_FORMAT_ASTC_4x4,
   PIPE_FORMAT_ASTC_5x4,
   PIPE_FORMAT_ASTC_5x5,
   PIPE_FORMAT_ASTC_6x5,
   PIPE_FORMAT_ASTC_6x6,
   PIPE_FORMAT_ASTC_8x5,
   PIPE_FORMAT_ASTC_8x6,
   PIPE_FORMAT_ASTC_8x8,
   PIPE_FORMAT_ASTC_10x5,
   PIPE_FORMAT_ASTC_10x6,
   PIPE_FORMAT_ASTC_10x8,
   PIPE_FORMAT_ASTC_10x10,
   PIPE_FORMAT_ASTC_12x10,
   PIPE_FORMAT_ASTC_12x12,

   PIPE_FORMAT_ASTC_4x4_SRGB,
   PIPE_FORMAT_ASTC_5x4_SRGB,
   PIPE_FORMAT_ASTC_5x5_SRGB,
   PIPE_FORMAT_ASTC_6x5_SRGB,
   PIPE_FORMAT_ASTC_6x6_SRGB,
   PIPE_FORMAT_ASTC_8x5_SRGB,
   PIPE_FORMAT_ASTC_8x6_SRGB,
   PIPE_FORMAT_ASTC_8x8_SRGB,
   PIPE_FORMAT_ASTC_10x5_SRGB,
   PIPE_FORMAT_ASTC_10x6_SRGB,
   PIPE_FORMAT_ASTC_10x8_SRGB,
   PIPE_FORMAT_ASTC_10x10_SRGB,
   PIPE_FORMAT_ASTC_12x10_SRGB,
   PIPE_FORMAT_ASTC_12x12_SRGB,

   PIPE_FORMAT_ASTC_3x3x3,
   PIPE_FORMAT_ASTC_4x3x3,
   PIPE_FORMAT_ASTC_4x4x3,
   PIPE_FORMAT_ASTC_4x4x4,
   PIPE_FORMAT_ASTC_5x4x4,
   PIPE_FORMAT_ASTC_5x5x4,
   PIPE_FORMAT_ASTC_5x5x5,
   PIPE_FORMAT_ASTC_6x5x5,
   PIPE_FORMAT_ASTC_6x6x5,
   PIPE_FORMAT_ASTC_6x6x6,

   PIPE_FORMAT_ASTC_3x3x3_SRGB,
   PIPE_FORMAT_ASTC_4x3x3_SRGB,
   PIPE_FORMAT_ASTC_4x4x3_SRGB,
   PIPE_FORMAT_ASTC_4x4x4_SRGB,
   PIPE_FORMAT_ASTC_5x4x4_SRGB,
   PIPE_FORMAT_ASTC_5x5x4_SRGB,
   PIPE_FORMAT_ASTC_5x5x5_SRGB,
   PIPE_FORMAT_ASTC_6x5x5_SRGB,
   PIPE_FORMAT_ASTC_6x6x5_SRGB,
   PIPE_FORMAT_ASTC_6x6x6_SRGB,

   PIPE_FORMAT_FXT1_RGB,
   PIPE_FORMAT_FXT1_RGBA,

   PIPE_FORMAT_P010,
   PIPE_FORMAT_P012,
   PIPE_FORMAT_P016,
   PIPE_FORMAT_P030,

   PIPE_FORMAT_Y210,
   PIPE_FORMAT_Y212,
   PIPE_FORMAT_Y216,

   PIPE_FORMAT_Y410,
   PIPE_FORMAT_Y412,
   PIPE_FORMAT_Y416,

   PIPE_FORMAT_R10G10B10X2_UNORM,
   PIPE_FORMAT_A1R5G5B5_UNORM,
   PIPE_FORMAT_A1B5G5R5_UNORM,
   PIPE_FORMAT_X1B5G5R5_UNORM,
   PIPE_FORMAT_R5G5B5A1_UNORM,
   PIPE_FORMAT_A4R4G4B4_UNORM,
   PIPE_FORMAT_A4B4G4R4_UNORM,

   PIPE_FORMAT_G8R8_SINT,
   PIPE_FORMAT_A8B8G8R8_SINT,
   PIPE_FORMAT_X8B8G8R8_SINT,

   PIPE_FORMAT_ATC_RGB,
   PIPE_FORMAT_ATC_RGBA_EXPLICIT,
   PIPE_FORMAT_ATC_RGBA_INTERPOLATED,

   PIPE_FORMAT_Z24_UNORM_S8_UINT_AS_R8G8B8A8,

   PIPE_FORMAT_AYUV,
   PIPE_FORMAT_XYUV,

   PIPE_FORMAT_R8_G8B8_420_UNORM,
   PIPE_FORMAT_G8_B8R8_420_UNORM,
   PIPE_FORMAT_G8_B8_R8_420_UNORM,
   PIPE_FORMAT_Y8_UNORM,

   PIPE_FORMAT_B8G8R8X8_SNORM,
   PIPE_FORMAT_B8G8R8X8_UINT,
   PIPE_FORMAT_B8G8R8X8_SINT,
   PIPE_FORMAT_A8R8G8B8_SNORM,
   PIPE_FORMAT_A8R8G8B8_SINT,
   PIPE_FORMAT_X8R8G8B8_SNORM,
   PIPE_FORMAT_X8R8G8B8_SINT,
   PIPE_FORMAT_R5G5B5X1_UNORM,
   PIPE_FORMAT_X1R5G5B5_UNORM,
   PIPE_FORMAT_R4G4B4X4_UNORM,
   PIPE_FORMAT_B10G10R10X2_SNORM,
   PIPE_FORMAT_R5G6B5_SRGB,
   PIPE_FORMAT_R10G10B10X2_SINT,
   PIPE_FORMAT_B10G10R10X2_SINT,
   PIPE_FORMAT_G16R16_SINT,

   PIPE_FORMAT_COUNT
};

#if UTIL_ARCH_LITTLE_ENDIAN
#define PIPE_FORMAT_RGBA8888_UNORM PIPE_FORMAT_R8G8B8A8_UNORM
#define PIPE_FORMAT_RGBX8888_UNORM PIPE_FORMAT_R8G8B8X8_UNORM
#define PIPE_FORMAT_BGRA8888_UNORM PIPE_FORMAT_B8G8R8A8_UNORM
#define PIPE_FORMAT_BGRX8888_UNORM PIPE_FORMAT_B8G8R8X8_UNORM
#define PIPE_FORMAT_ARGB8888_UNORM PIPE_FORMAT_A8R8G8B8_UNORM
#define PIPE_FORMAT_XRGB8888_UNORM PIPE_FORMAT_X8R8G8B8_UNORM
#define PIPE_FORMAT_ABGR8888_UNORM PIPE_FORMAT_A8B8G8R8_UNORM
#define PIPE_FORMAT_XBGR8888_UNORM PIPE_FORMAT_X8B8G8R8_UNORM
#define PIPE_FORMAT_RGBA8888_SNORM PIPE_FORMAT_R8G8B8A8_SNORM
#define PIPE_FORMAT_RGBX8888_SNORM PIPE_FORMAT_R8G8B8X8_SNORM
#define PIPE_FORMAT_ABGR8888_SNORM PIPE_FORMAT_A8B8G8R8_SNORM
#define PIPE_FORMAT_XBGR8888_SNORM PIPE_FORMAT_X8B8G8R8_SNORM
#define PIPE_FORMAT_RGBA8888_SRGB PIPE_FORMAT_R8G8B8A8_SRGB
#define PIPE_FORMAT_RGBX8888_SRGB PIPE_FORMAT_R8G8B8X8_SRGB
#define PIPE_FORMAT_BGRA8888_SRGB PIPE_FORMAT_B8G8R8A8_SRGB
#define PIPE_FORMAT_BGRX8888_SRGB PIPE_FORMAT_B8G8R8X8_SRGB
#define PIPE_FORMAT_ARGB8888_SRGB PIPE_FORMAT_A8R8G8B8_SRGB
#define PIPE_FORMAT_XRGB8888_SRGB PIPE_FORMAT_X8R8G8B8_SRGB
#define PIPE_FORMAT_ABGR8888_SRGB PIPE_FORMAT_A8B8G8R8_SRGB
#define PIPE_FORMAT_XBGR8888_SRGB PIPE_FORMAT_X8B8G8R8_SRGB
#define PIPE_FORMAT_RGBA8888_USCALED PIPE_FORMAT_R8G8B8A8_USCALED
#define PIPE_FORMAT_RGBA8888_SSCALED PIPE_FORMAT_R8G8B8A8_SSCALED
#define PIPE_FORMAT_RGBA8888_UINT PIPE_FORMAT_R8G8B8A8_UINT
#define PIPE_FORMAT_BGRA8888_UINT PIPE_FORMAT_B8G8R8A8_UINT
#define PIPE_FORMAT_ARGB8888_UINT PIPE_FORMAT_A8R8G8B8_UINT
#define PIPE_FORMAT_ABGR8888_UINT PIPE_FORMAT_A8B8G8R8_UINT
#define PIPE_FORMAT_RGBA8888_SINT PIPE_FORMAT_R8G8B8A8_SINT
#define PIPE_FORMAT_RG88_UNORM PIPE_FORMAT_R8G8_UNORM
#define PIPE_FORMAT_GR88_UNORM PIPE_FORMAT_G8R8_UNORM
#define PIPE_FORMAT_RG88_SNORM PIPE_FORMAT_R8G8_SNORM
#define PIPE_FORMAT_GR88_SNORM PIPE_FORMAT_G8R8_SNORM
#define PIPE_FORMAT_RG1616_UNORM PIPE_FORMAT_R16G16_UNORM
#define PIPE_FORMAT_GR1616_UNORM PIPE_FORMAT_G16R16_UNORM
#define PIPE_FORMAT_RG1616_SNORM PIPE_FORMAT_R16G16_SNORM
#define PIPE_FORMAT_GR1616_SNORM PIPE_FORMAT_G16R16_SNORM
#elif UTIL_ARCH_BIG_ENDIAN
#define PIPE_FORMAT_ABGR8888_UNORM PIPE_FORMAT_R8G8B8A8_UNORM
#define PIPE_FORMAT_XBGR8888_UNORM PIPE_FORMAT_R8G8B8X8_UNORM
#define PIPE_FORMAT_ARGB8888_UNORM PIPE_FORMAT_B8G8R8A8_UNORM
#define PIPE_FORMAT_XRGB8888_UNORM PIPE_FORMAT_B8G8R8X8_UNORM
#define PIPE_FORMAT_BGRA8888_UNORM PIPE_FORMAT_A8R8G8B8_UNORM
#define PIPE_FORMAT_BGRX8888_UNORM PIPE_FORMAT_X8R8G8B8_UNORM
#define PIPE_FORMAT_RGBA8888_UNORM PIPE_FORMAT_A8B8G8R8_UNORM
#define PIPE_FORMAT_RGBX8888_UNORM PIPE_FORMAT_X8B8G8R8_UNORM
#define PIPE_FORMAT_ABGR8888_SNORM PIPE_FORMAT_R8G8B8A8_SNORM
#define PIPE_FORMAT_XBGR8888_SNORM PIPE_FORMAT_R8G8B8X8_SNORM
#define PIPE_FORMAT_RGBA8888_SNORM PIPE_FORMAT_A8B8G8R8_SNORM
#define PIPE_FORMAT_RGBX8888_SNORM PIPE_FORMAT_X8B8G8R8_SNORM
#define PIPE_FORMAT_ABGR8888_SRGB PIPE_FORMAT_R8G8B8A8_SRGB
#define PIPE_FORMAT_XBGR8888_SRGB PIPE_FORMAT_R8G8B8X8_SRGB
#define PIPE_FORMAT_ARGB8888_SRGB PIPE_FORMAT_B8G8R8A8_SRGB
#define PIPE_FORMAT_XRGB8888_SRGB PIPE_FORMAT_B8G8R8X8_SRGB
#define PIPE_FORMAT_BGRA8888_SRGB PIPE_FORMAT_A8R8G8B8_SRGB
#define PIPE_FORMAT_BGRX8888_SRGB PIPE_FORMAT_X8R8G8B8_SRGB
#define PIPE_FORMAT_RGBA8888_SRGB PIPE_FORMAT_A8B8G8R8_SRGB
#define PIPE_FORMAT_RGBX8888_SRGB PIPE_FORMAT_X8B8G8R8_SRGB
#define PIPE_FORMAT_RGBA8888_USCALED PIPE_FORMAT_A8B8G8R8_USCALED
#define PIPE_FORMAT_RGBA8888_SSCALED PIPE_FORMAT_A8B8G8R8_SSCALED
#define PIPE_FORMAT_RGBA8888_UINT PIPE_FORMAT_A8B8G8R8_UINT
#define PIPE_FORMAT_BGRA8888_UINT PIPE_FORMAT_A8R8G8B8_UINT
#define PIPE_FORMAT_ARGB8888_UINT PIPE_FORMAT_B8G8R8A8_UINT
#define PIPE_FORMAT_ABGR8888_UINT PIPE_FORMAT_R8G8B8A8_UINT
#define PIPE_FORMAT_RGBA8888_SINT PIPE_FORMAT_A8B8G8R8_SINT
#define PIPE_FORMAT_RG88_UNORM PIPE_FORMAT_G8R8_UNORM
#define PIPE_FORMAT_GR88_UNORM PIPE_FORMAT_R8G8_UNORM
#define PIPE_FORMAT_RG88_SNORM PIPE_FORMAT_G8R8_SNORM
#define PIPE_FORMAT_GR88_SNORM PIPE_FORMAT_R8G8_SNORM
#define PIPE_FORMAT_RG1616_UNORM PIPE_FORMAT_G16R16_UNORM
#define PIPE_FORMAT_GR1616_UNORM PIPE_FORMAT_R16G16_UNORM
#define PIPE_FORMAT_RG1616_SNORM PIPE_FORMAT_G16R16_SNORM
#define PIPE_FORMAT_GR1616_SNORM PIPE_FORMAT_R16G16_SNORM
#endif

enum pipe_video_chroma_format
{
   PIPE_VIDEO_CHROMA_FORMAT_400,
   PIPE_VIDEO_CHROMA_FORMAT_420,
   PIPE_VIDEO_CHROMA_FORMAT_422,
   PIPE_VIDEO_CHROMA_FORMAT_444,
   PIPE_VIDEO_CHROMA_FORMAT_NONE
};

static inline enum pipe_video_chroma_format
pipe_format_to_chroma_format(enum pipe_format format)
{
   switch (format) {
      case PIPE_FORMAT_NV12:
      case PIPE_FORMAT_NV21:
      case PIPE_FORMAT_YV12:
      case PIPE_FORMAT_IYUV:
      case PIPE_FORMAT_P010:
      case PIPE_FORMAT_P012:
      case PIPE_FORMAT_P016:
      case PIPE_FORMAT_P030:
      case PIPE_FORMAT_Y16_U16_V16_420_UNORM:
         return PIPE_VIDEO_CHROMA_FORMAT_420;
      case PIPE_FORMAT_UYVY:
      case PIPE_FORMAT_YUYV:
      case PIPE_FORMAT_YV16:
      case PIPE_FORMAT_Y8_U8_V8_422_UNORM:
      case PIPE_FORMAT_Y8_U8V8_422_UNORM:
      case PIPE_FORMAT_Y16_U16_V16_422_UNORM:
      case PIPE_FORMAT_Y16_U16V16_422_UNORM:
         return PIPE_VIDEO_CHROMA_FORMAT_422;
      case PIPE_FORMAT_Y8_U8_V8_444_UNORM:
      case PIPE_FORMAT_Y16_U16_V16_444_UNORM:
         return PIPE_VIDEO_CHROMA_FORMAT_444;
      case PIPE_FORMAT_Y8_400_UNORM:
         return PIPE_VIDEO_CHROMA_FORMAT_400;
      default:
         return PIPE_VIDEO_CHROMA_FORMAT_NONE;
   }
}

#ifdef __cplusplus
}
#endif

#endif /* U_FORMATS_H_ */
