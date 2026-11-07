#pragma once

#include "BSTextureManager.h"
#include "MemoryManager.h"
#include "NiPointer.h"
#include "NiTexturingProperty.h"

class BSRenderedTexture;
class NiObject;
class NiTexture;
extern MemoryManager g_memoryManager;

// Bethesda ImageSpaceTexture: one texture input of an ImageSpaceEffect, 0x10 bytes, no vtable.
// +1 says pTexture holds a BSRenderedTexture (0x00ba3770 returns it only then; 0x00ba37a0 sets it and the flag),
// +2 says the rendered texture came from BSTextureManager and must be handed back (0x00ba39a0).
// Destructor 0x00ba3a00, operator= 0x00ba3940, clear 0x00ba38b0.
class ImageSpaceTexture
{
  public:
    bool m_bTextureFlag1;                                  // +0x00
    bool m_bTextureFlag2;                                  // +0x01 pTexture is a BSRenderedTexture
    bool m_bTextureFlag3;                                  // +0x02 rendered texture owned by BSTextureManager
    NiPointer<NiObject> pTexture;                          // +0x04
    NiTexturingProperty::FilterMode m_eTextureFilterMode;  // +0x08
    NiTexturingProperty::ClampMode m_eClampMode;           // +0x0C

    // inline (0x004ebb70 is the /Od copy): flags false, NiPointer(0), FILTER_NEAREST, CLAMP_S_CLAMP_T
    inline ImageSpaceTexture()
        : m_bTextureFlag1(false), m_bTextureFlag2(false), m_bTextureFlag3(false), pTexture(0),
          m_eTextureFilterMode(NiTexturingProperty::FILTER_NEAREST), m_eClampMode(NiTexturingProperty::CLAMP_S_CLAMP_T)
    {
    }
    ~ImageSpaceTexture();                                  // 0x00ba3a00

    // heap objects go through the game's MemoryManager (MemoryManager::Allocate 0x00aa13e0, inlined at /O2)
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* pointer) { g_memoryManager.Deallocate(pointer); }

    BSRenderedTexture* GetRenderedTexture() const;         // 0x00ba3770
    BSRenderedTexture* ImageSpaceTexture_GetRenderedTexture();                     // 0x00ba3770
    NiTexture* GetTexture();                               // 0x00ba3780
    NiTexture* GetTexture() const;                         // 0x00ba3780
    void ImageSpaceTexture_SetTexture(BSRenderedTexture* texture);         // 0x00ba37a0 set rendered texture
    void NiShader_SetImplementation(unsigned int value);                 // 0x00ba3760 stores +0x0C (m_eClampMode); imagespacetexture_o2_variant.cpp
    void SetTexture(NiTexture* texture);                   // 0x00ba37f0
    void CreateRenderTargetTexture(BSTextureManager::RenderTargetType type); // 0x00ba3840
    void ImageSpaceTexture_BorrowRenderedTexture(unsigned int type);                  // 0x00ba3840
    void ImageSpaceTexture_ClearTexture();                                   // 0x00ba38b0 release texture, clear fields
    void InitializeFields_00ba3940(ImageSpaceTexture* other);           // 0x00ba3940 copy (operator=)
    void AddRenderedTexture();                             // 0x00ba39a0 hand the rendered texture back
    void ImageSpaceTexture_ReturnRenderedTexture();                                   // 0x00ba39a0
};
