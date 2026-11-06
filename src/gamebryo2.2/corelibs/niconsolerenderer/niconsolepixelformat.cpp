// gamebryo2.2/corelibs/niconsolerenderer/niconsolepixelformat.cpp: NiD3DTextureData (1 function)

#include "../../../../include/NiPixelFormat.h"
#include "../../../../include/NiPixelFormat.h"
#include "niconsolepixelformat_pc_types.h"

// Maps a NiPixelFormat to a D3DFORMAT: returns the renderer hint if set, otherwise selects a format from the pixel format, bit depth and channel masks.
// @fnv 0x00e7bd20
D3DFORMAT __cdecl NiD3DTextureData::ConvertPixelFormatToD3DFormat(const NiPixelFormat& kPixelFormat)
{
    unsigned int uiRendererHint = kPixelFormat.m_uiRendererHint;
    unsigned char ucBitsPerPixel = kPixelFormat.m_ucBitsPerPixel;
    if (uiRendererHint != 0xffffffff)
        return static_cast<D3DFORMAT>(uiRendererHint);

    D3DFORMAT eD3DFormat = D3DFMT_UNKNOWN;
    switch (kPixelFormat.m_eFormat)
    {
    case FORMAT_RGB:
        switch (ucBitsPerPixel)
        {
        case 8:
            if (kPixelFormat.GetMask(COMP_RED) == 0xe0)
                eD3DFormat = D3DFMT_R3G3B2;
            else if (kPixelFormat.GetMask(COMP_RED) == 0)
                eD3DFormat = D3DFMT_L8;
            break;
        case 16:
            if (kPixelFormat.GetMask(COMP_RED) == 0xf800)
                eD3DFormat = D3DFMT_R5G6B5;
            else if (kPixelFormat.GetMask(COMP_RED) == 0x7c00)
                eD3DFormat = D3DFMT_X1R5G5B5;
            else if (kPixelFormat.GetMask(COMP_RED) == 0x0f00)
                eD3DFormat = D3DFMT_X4R4G4B4;
            else if (kPixelFormat.GetMask(COMP_RED) == 0)
                eD3DFormat = D3DFMT_L16;
            break;
        case 24:
            eD3DFormat = D3DFMT_R8G8B8;
            break;
        case 32:
            if (kPixelFormat.GetMask(COMP_RED) == 0x00ff0000)
                eD3DFormat = D3DFMT_X8R8G8B8;
            else if (kPixelFormat.GetMask(COMP_RED) == 0x000000ff)
                eD3DFormat = D3DFMT_X8B8G8R8;
            else if (kPixelFormat.GetMask(COMP_RED) == 0xffff0000)
                eD3DFormat = D3DFMT_G16R16;
            break;
        default:
            eD3DFormat = D3DFMT_UNKNOWN;
            break;
        }
        break;
    case FORMAT_RGBA:
        switch (ucBitsPerPixel)
        {
        case 8:
            if (kPixelFormat.GetMask(COMP_LUMA) == 0)
                eD3DFormat = D3DFMT_A8;
            else if (kPixelFormat.GetMask(COMP_LUMA) == 0x0f)
                eD3DFormat = D3DFMT_A4L4;
            break;
        case 16:
            if (kPixelFormat.GetMask(COMP_RED) == 0x7c00)
                eD3DFormat = D3DFMT_A1R5G5B5;
            else if (kPixelFormat.GetMask(COMP_RED) == 0x0f00)
                eD3DFormat = D3DFMT_A4R4G4B4;
            else if (kPixelFormat.GetMask(COMP_RED) == 0xe0)
                eD3DFormat = D3DFMT_A8R3G3B2;
            else if (kPixelFormat.GetMask(COMP_RED) == 0)
                eD3DFormat = D3DFMT_A8L8;
            break;
        case 24:
            eD3DFormat = D3DFMT_UNKNOWN;
            break;
        case 32:
            if (kPixelFormat.GetMask(COMP_RED) == 0x00ff0000)
                eD3DFormat = D3DFMT_A8R8G8B8;
            else if (kPixelFormat.GetMask(COMP_RED) == 0x000003ff)
                eD3DFormat = D3DFMT_A2B10G10R10;
            else if (kPixelFormat.GetMask(COMP_RED) == 0x000000ff)
                eD3DFormat = D3DFMT_A8B8G8R8;
            else if (kPixelFormat.GetMask(COMP_RED) == 0x3ff00000)
                eD3DFormat = D3DFMT_A2R10G10B10;
            break;
        case 64:
            eD3DFormat = D3DFMT_A16B16G16R16F;
            break;
        case 128:
            eD3DFormat = D3DFMT_A32B32G32R32F;
            break;
        default:
            eD3DFormat = D3DFMT_UNKNOWN;
            break;
        }
        break;
    case FORMAT_PAL:
        eD3DFormat = D3DFMT_P8;
        break;
    case FORMAT_PALALPHA:
        eD3DFormat = D3DFMT_UNKNOWN;
        break;
    case FORMAT_DXT1:
        eD3DFormat = D3DFMT_DXT1;
        break;
    case FORMAT_DXT3:
        eD3DFormat = D3DFMT_DXT3;
        break;
    case FORMAT_DXT5:
        eD3DFormat = D3DFMT_DXT5;
        break;
    case FORMAT_RGB24NONINTERLEAVED:
        break;
    case FORMAT_BUMP:
        eD3DFormat = D3DFMT_V8U8;
        break;
    case FORMAT_BUMPLUMA:
        if (ucBitsPerPixel == 16)
            eD3DFormat = D3DFMT_L6V5U5;
        else if (ucBitsPerPixel == 32)
            eD3DFormat = D3DFMT_X8L8V8U8;
        break;
    case FORMAT_RENDERERSPECIFIC:
        eD3DFormat = D3DFMT_UNKNOWN;
        break;
    case FORMAT_ONE_CHANNEL:
        switch (ucBitsPerPixel)
        {
        case 8:
            eD3DFormat = kPixelFormat.GetMask(COMP_ALPHA) == 0 ? D3DFMT_L8 : D3DFMT_A8;
            break;
        case 16:
            eD3DFormat = D3DFMT_R16F;
            break;
        case 32:
            eD3DFormat = D3DFMT_R32F;
            break;
        }
        break;
    case FORMAT_TWO_CHANNEL:
        switch (ucBitsPerPixel)
        {
        case 16:
            eD3DFormat = D3DFMT_A8L8;
            break;
        case 32:
            eD3DFormat = D3DFMT_G16R16F;
            break;
        case 64:
            eD3DFormat = D3DFMT_G32R32F;
            break;
        }
        break;
    case FORMAT_THREE_CHANNEL:
        eD3DFormat = D3DFMT_UNKNOWN;
        break;
    case FORMAT_FOUR_CHANNEL:
        switch (ucBitsPerPixel)
        {
        case 32:
            eD3DFormat = D3DFMT_A8R8G8B8;
            break;
        case 64:
            eD3DFormat = D3DFMT_A16B16G16R16F;
            break;
        case 128:
            eD3DFormat = D3DFMT_A32B32G32R32F;
            break;
        }
        break;
    case FORMAT_DEPTH_STENCIL:
        switch (ucBitsPerPixel)
        {
        case 16:
            return kPixelFormat.GetPixelBitData(COMP_STENCIL) == 1 ? D3DFMT_D15S1 : D3DFMT_D16;
        case 32: {
            unsigned char ucStencilBits = kPixelFormat.GetPixelBitData(COMP_STENCIL);
            switch (ucStencilBits)
            {
            case 4:
                return D3DFMT_D24X4S4;
            case 8:
                return D3DFMT_D24S8;
            default:
                return kPixelFormat.GetPixelBitData(COMP_DEPTH) == 24 ? D3DFMT_D24X8 : D3DFMT_D32;
            }
        }
        }
        break;
    }
    return eD3DFormat;
}
