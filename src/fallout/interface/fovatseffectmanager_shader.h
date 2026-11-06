// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACESHADERPARAM_H
#define FNV_IMAGESPACESHADERPARAM_H
#include "../../../include/NiTMallocInterface.h"
#include "../../../include/NiTNewInterface.h"
#include "../../../include/NiTPrimitiveArray.h"
#include "../../../include/NiTMap.h"

#include "layout_support.h"
class NiD3DShaderConstantMap;
class NiTexture;
#include "../../../include/BSTextureManager.h"
#include "../../../include/NiTexturingProperty.h"
#include "../../../include/NiRenderer.h"
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<BSTextureManager::eTextureType> (the name spells the instantiation)
typedef NiTPrimitiveArray<BSTextureManager::eTextureType> NiTPrimitiveArray_enum_BSTextureManager__eTextureType_;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_enum_BSTextureManager__eTextureType_) == 16);
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<NiTexturingProperty::FilterMode> (the name spells the instantiation)
typedef NiTPrimitiveArray<NiTexturingProperty::FilterMode> NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_) == 16);
#pragma pack(push, 4)
class VatsManagerEffectParamLocalForm
{ // local form of ImageSpaceEffectParam: 0x00c82870 needs the 0x24-byte vtable/two-array base; the frozen shared size-1 declaration fails the exe-derived size/offset assertions.
  public:
    void** m_ppVirtualMethodTable;                                                         // +0x0, 4 bytes
    NiTPrimitiveArray_enum_BSTextureManager__eTextureType_ m_kTextureTypes;  // +0x4, 16 bytes
    NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_ m_kFilterModes;  // +0x14, 16 bytes
    // VatsManagerEffectParamLocalForm
    // VatsManagerEffectParamLocalForm& __cdecl VatsManagerEffectParamLocalForm::*(const VatsManagerEffectParamLocalForm&)
    // void __cdecl VatsManagerEffectParamLocalForm::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(VatsManagerEffectParamLocalForm) == 36);
FNV_STATIC_ASSERT(offsetof(VatsManagerEffectParamLocalForm, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(VatsManagerEffectParamLocalForm, m_kTextureTypes) == 4);
FNV_STATIC_ASSERT(offsetof(VatsManagerEffectParamLocalForm, m_kFilterModes) == 20);
FNV_STATIC_ASSERT(sizeof(NiColorA) == 16);
FNV_STATIC_ASSERT(offsetof(NiColorA, r) == 0);
FNV_STATIC_ASSERT(offsetof(NiColorA, g) == 4);
FNV_STATIC_ASSERT(offsetof(NiColorA, b) == 8);
FNV_STATIC_ASSERT(offsetof(NiColorA, a) == 12);
#pragma pack(push, 4)
class ImageSpaceShaderParam : public VatsManagerEffectParamLocalForm
{
  public:
    // base VatsManagerEffectParamLocalForm at +0x0, size 36
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
    NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_ m_kTextureFilterModes;  // +0x68, 16 bytes
    NiTMap<unsigned int, unsigned int> m_kRenderStateMap;                            // +0x78, 16 bytes
    ImageSpaceShaderParam();
    void AllocateShaderConstants(int, int);
    // ImageSpaceShaderParam
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(int, int)
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(int, unsigned int, unsigned int)
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(unsigned int, unsigned int)
    // void __cdecl ImageSpaceShaderParam::*(NiD3DPass*)
    // ImageSpaceShaderParam& __cdecl ImageSpaceShaderParam::*(const ImageSpaceShaderParam&)
    // void __cdecl ImageSpaceShaderParam::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceShaderParam) == 136);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eShaderFilterMode) == 36);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eClearFlags) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eTextureClampMode) == 44);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pfVertexShaderConstants) == 60);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_iVertexShaderConstantCount) == 64);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pfPixelShaderConstants) == 68);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_iPixelShaderConstantCount) == 72);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pVertexShaderConstantMap) == 76);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pPixelShaderConstantMap) == 80);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_bTextureFlags) == 84);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kShaderTextures) == 88);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kTextureFilterModes) == 104);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kRenderStateMap) == 120);
#endif
