// Private research declarations for this source unit; not a canonical header.
// PC field layout is supported by the covered instructions and clean JohnnyGuitar
// NiPixelFormat declarations. See identity_review.md for cross-platform limits.
#ifndef FNV_PIXELFORMAT_PC_TYPES_H
#define FNV_PIXELFORMAT_PC_TYPES_H

#include <stddef.h>
#include "../../../../include/NiPixelFormat.h"
#define FNV_PIXELFORMAT_JOIN_(a, b) a##b
#define FNV_PIXELFORMAT_JOIN(a, b) FNV_PIXELFORMAT_JOIN_(a, b)
#define FNV_PIXELFORMAT_ASSERT(x) typedef char FNV_PIXELFORMAT_JOIN(fnv_pixelformat_assert_, __LINE__)[(x) ? 1 : -1]

// Microsoft D3DFORMAT (D3D9Types.h), legacy PC D3D9 values.
// https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dformat
// These are enum/type facts; no renderer implementation was consulted.
#include "../../../../include/_D3DFORMAT.h"
typedef _D3DFORMAT D3DFORMAT;

class NiD3DTextureData : public NiPixelFormat
{
  public:
    // Genuine supplied candidate name. The machine ABI and enum values are PC.
    static D3DFORMAT __cdecl ConvertPixelFormatToD3DFormat(const NiPixelFormat& kPixelFormat);
};

FNV_PIXELFORMAT_ASSERT(sizeof(D3DFORMAT) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::Format) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::Component) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::TextureTileMode) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::Representation) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::NiComponentSpec) == 12);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat::NiComponentSpec, m_eComponent) == 0);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat::NiComponentSpec, m_eRepresentation) == 4);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat::NiComponentSpec, m_ucBitsPerComponent) == 8);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat::NiComponentSpec, m_bSigned) == 9);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat) == 68);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_uiObjectFlags) == 0);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_ucBitsPerPixel) == 1);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_eFormat) == 4);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_eTiling) == 8);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_uiRendererHint) == 12);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_uiExtraData) == 16);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_akComponents) == 20);
FNV_PIXELFORMAT_ASSERT(sizeof(NiD3DTextureData) == 68);
#endif
