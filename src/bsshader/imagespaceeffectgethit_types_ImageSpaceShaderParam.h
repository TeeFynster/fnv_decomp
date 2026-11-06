#ifndef FNV_IMAGESPACESHADERPARAM_H
#define FNV_IMAGESPACESHADERPARAM_H
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTObjectArray.h"
#include "../../include/DFALL.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMap.h"

#include "../../include/NiColorA.h"
#include "imagespaceeffectgethit_types_ImageSpaceEffectGetHit.h"
class NiD3DShaderConstantMap;
class NiTexture;
#include "../../include/NiRenderer.h"
#pragma pack(push, 4)
class GetHitEffectParamLocalForm
{ // local form of ImageSpaceEffectParam: 0x00c03740 needs the 0x24-byte vtable/two-array base; the frozen shared size-1 declaration fails the exe-derived size/offset assertions.
  public:
    void** m_ppVirtualMethodTable;                                                         // +0x0, 4 bytes
    NiTPrimitiveArray<BSTextureManager::eTextureType> m_kTextureTypes;  // +0x4, 16 bytes
    NiTPrimitiveArray<NiTexturingProperty::FilterMode> m_kFilterModes;  // +0x14, 16 bytes
    // GetHitEffectParamLocalForm
    // GetHitEffectParamLocalForm& __cdecl GetHitEffectParamLocalForm::*(const GetHitEffectParamLocalForm&)
    // void __cdecl GetHitEffectParamLocalForm::*()
};
#pragma pack(pop)
GETHIT_STATIC_ASSERT(sizeof(GetHitEffectParamLocalForm) == 36);
GETHIT_STATIC_ASSERT(offsetof(GetHitEffectParamLocalForm, m_ppVirtualMethodTable) == 0);
GETHIT_STATIC_ASSERT(offsetof(GetHitEffectParamLocalForm, m_kTextureTypes) == 4);
GETHIT_STATIC_ASSERT(offsetof(GetHitEffectParamLocalForm, m_kFilterModes) == 20);
#pragma pack(push, 4)
class ImageSpaceShaderParam : public GetHitEffectParamLocalForm
{
  public:
    ImageSpaceShaderParam();
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }

    ImageSpaceShaderParam* SetSize();

    void SetShaderConstantVector4(int, float, float, float, float);
    void AllocateShaderConstants(int, int);
    // base GetHitEffectParamLocalForm at +0x0, size 36
    NiTexturingProperty::FilterMode m_eShaderFilterMode;           // +0x24, 4 bytes
    NiRenderer::ClearFlags m_eClearFlags;                          // +0x28, 4 bytes
    NiColorA m_eTextureClampMode;                                 // +0x2C, 16 bytes
    float* m_pfVertexShaderConstants;                              // +0x3C, 4 bytes
    int m_iVertexShaderConstantCount;                              // +0x40, 4 bytes
    float* m_pfPixelShaderConstants;                               // +0x44, 4 bytes
    int m_iPixelShaderConstantCount;                               // +0x48, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_pVertexShaderConstantMap;  // +0x4C, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_pPixelShaderConstantMap;   // +0x50, 4 bytes
    bool m_bTextureFlags[3];                                       // +0x54, 3 bytes
    unsigned char layoutPadding57[1];
    NiTObjectArray<NiPointer<NiTexture> > m_kShaderTextures;                        // +0x58, 16 bytes
    NiTPrimitiveArray<NiTexturingProperty::FilterMode> m_kTextureFilterModes;  // +0x68, 16 bytes
    NiTMap<unsigned int, unsigned int> m_kRenderStateMap;                            // +0x78, 16 bytes
    // ImageSpaceShaderParam
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(int, int)
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(int, unsigned int, unsigned int)
    // SetShaderConstantVector4
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(unsigned int, unsigned int)
    // void __cdecl ImageSpaceShaderParam::*(NiD3DPass*)
    // ImageSpaceShaderParam& __cdecl ImageSpaceShaderParam::*(const ImageSpaceShaderParam&)
    // void __cdecl ImageSpaceShaderParam::*()
};
#pragma pack(pop)
GETHIT_STATIC_ASSERT(sizeof(ImageSpaceShaderParam) == 136);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eShaderFilterMode) == 36);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eClearFlags) == 40);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eTextureClampMode) == 44);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pfVertexShaderConstants) == 60);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_iVertexShaderConstantCount) == 64);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pfPixelShaderConstants) == 68);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_iPixelShaderConstantCount) == 72);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pVertexShaderConstantMap) == 76);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pPixelShaderConstantMap) == 80);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_bTextureFlags) == 84);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kShaderTextures) == 88);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kTextureFilterModes) == 104);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kRenderStateMap) == 120);
#endif
