#ifndef FNV_IMAGESPACEEFFECTGETHIT_H
#define FNV_IMAGESPACEEFFECTGETHIT_H
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTPrimitiveArray.h"

#include <stddef.h>
#include "../../include/NiPointer.h"
#include "../../include/ImageSpaceTexture.h"

#define GETHIT_JOIN_IMPL(a, b) a##b
#define GETHIT_JOIN(a, b) GETHIT_JOIN_IMPL(a, b)
#define GETHIT_STATIC_ASSERT(condition) typedef char GETHIT_JOIN(gethit_static_assert_, __LINE__)[(condition) ? 1 : -1]
#include "../../include/NiObject.h"
class ImageSpaceEffect__EffectInput;
class ImageSpaceManager;
class GetHitEffectParamLocalForm;
#pragma pack(push, 4)
class ImageSpaceEffect
{
  public:
    ImageSpaceEffect();
    virtual ~ImageSpaceEffect();
    void SetTextureArrayCount(int);
    void SetEffectAt(int, ImageSpaceEffect*, GetHitEffectParamLocalForm*, int);
    void SetEffectAt(int, int, int, int, int);

    bool bIsActive;       // +0x4, 1 bytes
    bool bParamsChanged;  // +0x5, 1 bytes
    unsigned char layoutPadding6[2];
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;                 // +0x8, 16 bytes
    NiTPrimitiveArray<GetHitEffectParamLocalForm*> pEffectParamList;       // +0x18, 16 bytes
    NiTPrimitiveArray<ImageSpaceTexture*> pTextures;                  // +0x28, 16 bytes
    NiTPrimitiveArray<ImageSpaceEffect__EffectInput*> pEffectInputs;  // +0x38, 16 bytes
    NiTPrimitiveArray<int> pEffectOutput;                              // +0x48, 16 bytes
    // ImageSpaceEffect
    // void __cdecl ImageSpaceEffect::*(bool)
    // ImageSpaceTexture* __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int, ImageSpaceEffect*, GetHitEffectParamLocalForm*, int)
    // void __cdecl ImageSpaceEffect::*(int, ImageSpaceTexture*, NiTexturingProperty::FilterMode)
    // ImageSpaceEffect& __cdecl ImageSpaceEffect::*(const ImageSpaceEffect&)
    // void __cdecl ImageSpaceEffect::*()
};
#pragma pack(pop)
GETHIT_STATIC_ASSERT(sizeof(ImageSpaceEffect) == 88);

GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffect, bIsActive) == 4);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffect, bParamsChanged) == 5);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectList) == 8);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectParamList) == 24);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffect, pTextures) == 40);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectInputs) == 56);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectOutput) == 72);
#pragma pack(push, 4)
class ImageSpaceEffectWithTwoTextures : public ImageSpaceEffect
{
  public:
    ImageSpaceEffectWithTwoTextures();
    void SetEffectParamAt(int, int, int);

    void Setup(ImageSpaceManager*, GetHitEffectParamLocalForm*);
    bool UpdateParams(GetHitEffectParamLocalForm*);
    // base ImageSpaceEffect at +0x0, size 88
    float* pVector4;                         // +0x58, 4 bytes
    ImageSpaceTexture m_kEffectTextures[2];  // +0x5C, 32 bytes
    // ImageSpaceEffectWithTwoTextures
    // void __cdecl ImageSpaceEffectWithTwoTextures::*()
    // void __cdecl ImageSpaceEffectWithTwoTextures::*(ImageSpaceManager*, GetHitEffectParamLocalForm*)
    // void __cdecl ImageSpaceEffectWithTwoTextures::*(GetHitEffectParamLocalForm*)
    // void __cdecl ImageSpaceEffectWithTwoTextures::*()
    // bool __cdecl ImageSpaceEffectWithTwoTextures::*()
    // void __cdecl ImageSpaceEffectWithTwoTextures::*()
    // bool __cdecl ImageSpaceEffectWithTwoTextures::*(GetHitEffectParamLocalForm*)
    // const char* __cdecl ImageSpaceEffectWithTwoTextures::*()
    // ImageSpaceEffectWithTwoTextures& __cdecl ImageSpaceEffectWithTwoTextures::*(ImageSpaceEffectWithTwoTextures&)
    // void __cdecl ImageSpaceEffectWithTwoTextures::*()
};
#pragma pack(pop)
GETHIT_STATIC_ASSERT(sizeof(ImageSpaceEffectWithTwoTextures) == 124);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffectWithTwoTextures, pVector4) == 88);
GETHIT_STATIC_ASSERT(offsetof(ImageSpaceEffectWithTwoTextures, m_kEffectTextures) == 92);
#endif
