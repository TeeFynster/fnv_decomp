// bsshader/imagespaceeffectnoise.cpp: free functions (2 functions)

#include "../../include/ImageSpaceEffectParam.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"
#include "imagespaceeffectnoise_decls.h"

// @fnv 0x00c05180
void NoiseImageSpaceEffect::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam*)
{
    SetTextureArrayCount(1);
    textures.SetSize(2);
    ImageSpaceShaderParam* shader = new ImageSpaceShaderParam;
    shader->AllocateShaderConstants(0, 4);
    params.SetAt(0, shader);
    SetEffectParamAt(0, 1, 0);
    // pEffectList is the manager's NiTPrimitiveArray<ImageSpaceEffect*> at +0x04;
    // Setup at 0x00C05180 reads effect entry 50 at base +0xC8.
    NiTPrimitiveArray<ImageSpaceEffect*>* effects =
        reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(manager->pEffectList);
    SetEffectAt(0, effects->m_pBase[50], shader, 0);
}

// Allocates an 8-byte parameter from two ints and stores it at uiIndex in the array at pThis+0x38.
// @fnv 0x00ba3b10
void __fastcall SetEffectParamAt(char* pThis, int, unsigned int uiIndex, int a2, int a3)
{
    int* p = (int*)g_memoryManager.Allocate(8);
    p[0] = a2;
    ImageSpaceEffectParam* param = (ImageSpaceEffectParam*)p;
    p[1] = a3;
    ((NiTPrimitiveArray<ImageSpaceEffectParam*>*)(pThis + 0x38))->SetAt(uiIndex, param);
}
