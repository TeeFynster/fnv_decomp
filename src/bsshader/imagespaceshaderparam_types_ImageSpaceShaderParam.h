#include "../../include/NiTMap.h"
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACESHADERPARAM_H
#define FNV_IMAGESPACESHADERPARAM_H
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTPrimitiveArray.h"

#include "layout_support.h"
#include "../../include/NiColorA.h"
class DFALL_NiTMapItem_unsigned_int_unsigned_int___;
class ShaderEffectParamLocal_00b8a9e0;
class ImageSpaceShaderParam;
class NiColorA;
class NiD3DShaderConstantMap;

class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_;
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator;
class NiTexture;
#include "../../include/BSTextureManager.h"
#include "../../include/NiTexturingProperty.h"
#include "../../include/NiRenderer.h"
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
// local form of ImageSpaceEffectParam: 0x00b8a9e0 needs the 0x24-byte base with arrays at +4/+0x14, as the unit offset checks require.
class ShaderEffectParamLocal_00b8a9e0
{
  public:
    void** m_ppVirtualMethodTable;                                                         // +0x0, 4 bytes
    NiTPrimitiveArray_enum_BSTextureManager__eTextureType_ m_kTextureTypes;  // +0x4, 16 bytes
    NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_ m_kFilterModes;  // +0x14, 16 bytes
    // ShaderEffectParamLocal_00b8a9e0
    // ShaderEffectParamLocal_00b8a9e0& __cdecl ShaderEffectParamLocal_00b8a9e0::*(const ShaderEffectParamLocal_00b8a9e0&)
    // void __cdecl ShaderEffectParamLocal_00b8a9e0::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShaderEffectParamLocal_00b8a9e0) == 36);
FNV_STATIC_ASSERT(offsetof(ShaderEffectParamLocal_00b8a9e0, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(ShaderEffectParamLocal_00b8a9e0, m_kTextureTypes) == 4);
FNV_STATIC_ASSERT(offsetof(ShaderEffectParamLocal_00b8a9e0, m_kFilterModes) == 20);
#pragma pack(push, 4)
class DFALL_NiTMapItem_unsigned_int_unsigned_int___
{
  public:
    // void* __cdecl DFALL<NiTMapItem<unsigned int,unsigned int> >::*()
    // void __cdecl DFALL<NiTMapItem<unsigned int,unsigned int> >::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DFALL_NiTMapItem_unsigned_int_unsigned_int___) == 1);
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator
    : public DFALL_NiTMapItem_unsigned_int_unsigned_int___
{
  public:
    // base DFALL<NiTMapItem<unsigned int,unsigned int> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator,
             m_uiCount) == 0);
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_
{
  public:
    void** m_ppVirtualMethodTable;                                          // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                // +0x4, 4 bytes
    NiTMapItem<unsigned int, unsigned int>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>
    // unsigned int __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int, unsigned int)
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int, unsigned int&)
    // void* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(void*&, unsigned int&, unsigned int&)
    // NiTMapItem<unsigned int,unsigned int>* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int)
    // NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>& __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(const NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>&)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_) == 16);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_kItemCount) == 12);
#pragma pack(push, 4)

#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTMap<unsigned int, unsigned int>) == 16);
#pragma pack(push, 4)
class ImageSpaceShaderParam : public ShaderEffectParamLocal_00b8a9e0
{
  public:
    // base ShaderEffectParamLocal_00b8a9e0 at +0x0, size 36
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
    NiTPointerMap<unsigned int, unsigned int> m_kRenderStateMap;                    // +0x78, 16 bytes
    void AllocateShaderConstants(int vertexCount, int pixelCount);
    void ClearConstantGroups();
    void SetBlurClearMode();
    void CopyParamData(int index, const float* data, unsigned int size);
    void SetShaderConstantVector4(int index, float x, float y, float z, float w);
    void SetRenderState(unsigned int state, unsigned int value);
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
