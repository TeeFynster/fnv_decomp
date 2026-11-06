// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACEEFFECTVATSSCAN_H
#define FNV_IMAGESPACEEFFECTVATSSCAN_H
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTPrimitiveArray.h"

#include "layout_support.h"
#include "layout_support.h"
class ImageSpaceEffect;
class ImageSpaceEffect__EffectInput;
class VatsScanEffectParamLocalForm;
class ImageSpaceManager;
class ImageSpaceEffectMultiTexture;
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<ImageSpaceEffect*> (the name spells the instantiation)
typedef NiTPrimitiveArray<ImageSpaceEffect*> NiTPrimitiveArray_ImageSpaceEffect___;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_ImageSpaceEffect___) == 16);
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<VatsScanEffectParamLocalForm*> (the name spells the instantiation)
typedef NiTPrimitiveArray<VatsScanEffectParamLocalForm*> NiTPrimitiveArray_VatsScanEffectParamLocalForm___;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_VatsScanEffectParamLocalForm___) == 16);
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<ImageSpaceTexture*> (the name spells the instantiation); declared here: void SetSize(unsigned int size);
typedef NiTPrimitiveArray<ImageSpaceTexture*> NiTPrimitiveArray_ImageSpaceTexture___;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_ImageSpaceTexture___) == 16);
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<ImageSpaceEffect__EffectInput*> (the name spells the instantiation)
typedef NiTPrimitiveArray<ImageSpaceEffect__EffectInput*> NiTPrimitiveArray_ImageSpaceEffect__EffectInput___;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_ImageSpaceEffect__EffectInput___) == 16);
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<int> (the name spells the instantiation)
typedef NiTPrimitiveArray<int> NiTPrimitiveArray_int_;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_int_) == 16);
#pragma pack(push, 4)
class ImageSpaceEffect
{
  public:
    void** m_ppVirtualMethodTable;      // +0x0, 4 bytes
    bool bIsActive;       // +0x4, 1 bytes
    bool bParamsChanged;  // +0x5, 1 bytes
    unsigned char layoutPadding6[2];
    NiTPrimitiveArray_ImageSpaceEffect___ pEffectList;                 // +0x8, 16 bytes
    NiTPrimitiveArray_VatsScanEffectParamLocalForm___ pEffectParamList;       // +0x18, 16 bytes
    NiTPrimitiveArray_ImageSpaceTexture___ pTextures;                  // +0x28, 16 bytes
    NiTPrimitiveArray_ImageSpaceEffect__EffectInput___ pEffectInputs;  // +0x38, 16 bytes
    NiTPrimitiveArray_int_ pEffectOutput;                              // +0x48, 16 bytes
    __declspec(noinline) ImageSpaceEffect();
    void SetTextureArrayCount(int count);
    void SetEffectAt(int index, ImageSpaceEffect* effect, VatsScanEffectParamLocalForm* params, int flags);
    // ImageSpaceEffect
    // void __cdecl ImageSpaceEffect::*(bool)
    // ImageSpaceTexture* __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int, ImageSpaceEffect*, VatsScanEffectParamLocalForm*, int)
    // void __cdecl ImageSpaceEffect::*(int, ImageSpaceTexture*, NiTexturingProperty::FilterMode)
    // ImageSpaceEffect& __cdecl ImageSpaceEffect::*(const ImageSpaceEffect&)
    // void __cdecl ImageSpaceEffect::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffect) == 88);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, bIsActive) == 4);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, bParamsChanged) == 5);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectList) == 8);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectParamList) == 24);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pTextures) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectInputs) == 56);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectOutput) == 72);
#pragma pack(push, 4)
class ImageSpaceEffectMultiTexture : public ImageSpaceEffect
{
  public:
    ImageSpaceEffectMultiTexture();
    void Setup(ImageSpaceManager* manager, VatsScanEffectParamLocalForm* params);
    void SetEntryRanges(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
    // base ImageSpaceEffect at +0x0, size 88
    // ImageSpaceEffectMultiTexture
    // void __cdecl ImageSpaceEffectMultiTexture::*()
    // void __cdecl ImageSpaceEffectMultiTexture::*(ImageSpaceManager*, VatsScanEffectParamLocalForm*)
    // void __cdecl ImageSpaceEffectMultiTexture::*(VatsScanEffectParamLocalForm*)
    // void __cdecl ImageSpaceEffectMultiTexture::*()
    // const char* __cdecl ImageSpaceEffectMultiTexture::*()
    // bool __cdecl ImageSpaceEffectMultiTexture::*(VatsScanEffectParamLocalForm*)
    // ImageSpaceEffectMultiTexture& __cdecl ImageSpaceEffectMultiTexture::*(const ImageSpaceEffectMultiTexture&)
    // void __cdecl ImageSpaceEffectMultiTexture::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffectMultiTexture) == 88);
#endif
