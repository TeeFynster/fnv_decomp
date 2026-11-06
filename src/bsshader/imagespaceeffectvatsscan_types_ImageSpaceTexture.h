// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACETEXTURE_H
#define FNV_IMAGESPACETEXTURE_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class NiTexture;
class ImageSpaceTexture;
#include "../../include/NiTexturingProperty.h"
#pragma pack(push, 4)
class ImageSpaceTexture
{
  public:
    bool m_bTextureFlag1;  // +0x0, 1 bytes
    bool m_bTextureFlag2;  // +0x1, 1 bytes
    bool m_bTextureFlag3;  // +0x2, 1 bytes
    unsigned char layoutPadding3[1];
    NiPointer<NiObject> pTexture;                          // +0x4, 4 bytes
    NiTexturingProperty::FilterMode m_eTextureFilterMode;  // +0x8, 4 bytes
    NiTexturingProperty::ClampMode m_eClampMode;           // +0xC, 4 bytes
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    ImageSpaceTexture()
    {
        m_bTextureFlag1 = false;
        m_bTextureFlag2 = false;
        m_bTextureFlag3 = false;
        pTexture.m_pObject = 0;
        m_eTextureFilterMode = (NiTexturingProperty::FilterMode)0;
        m_eClampMode = (NiTexturingProperty::ClampMode)0;
    }
    void SetTexture(NiTexture* texture);
    // ImageSpaceTexture
    // void __cdecl ImageSpaceTexture::*()
    // BSRenderedTexture* __cdecl ImageSpaceTexture::*()
    // NiTexture* __cdecl ImageSpaceTexture::*()
    // SetTexture
    // void __cdecl ImageSpaceTexture::*(bool)
    // void __cdecl ImageSpaceTexture::*()
    // void __cdecl ImageSpaceTexture::*()
    // void __cdecl ImageSpaceTexture::*(NiTexturingProperty::FilterMode)
    // void __cdecl ImageSpaceTexture::*(NiTexturingProperty::ClampMode)
    // ImageSpaceTexture& __cdecl ImageSpaceTexture::*(ImageSpaceTexture&)
    // void* __cdecl ImageSpaceTexture::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceTexture) == 16);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag1) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag2) == 1);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag3) == 2);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, pTexture) == 4);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_eTextureFilterMode) == 8);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_eClampMode) == 12);
#endif
