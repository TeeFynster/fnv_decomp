// bsshader/imagespaceeffectvatsscan.cpp: free functions (3 functions)
#define FNV64_NIPOINTER_INLINE_BODIES
#include "NiRefObject_inline.h"
#include "../../include/BSShaderManager.h"
#include "../../include/NiColorA.h"
#include "../../include/ImageSpaceTexture.h"

#include "imagespaceeffectvatsscan_decls.h"
#include <new>

inline NiColorA::NiColorA(float fR, float fG, float fB, float fA)
{
    r = fR;
    g = fG;
    b = fB;
    a = fA;
}

// @fnv 0x00bc06c0
void ImageSpaceEffectMultiTexture::Setup(ImageSpaceManager* manager, VatsScanEffectParamLocalForm* params)
{
    SetTextureArrayCount(1);
    pTextures.NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> >::SetSize(5);
    BSShaderManager::GetTexture("Data\\Textures\\Pipboy3000\\PipboyScanlines.dds", true, DAT_01201f40, false, false);
    NiTexture* pScanTexture = DAT_01201f40.m_pObject;
    BSShaderManager::GetTexture("Data\\Textures\\Pipboy3000\\PipboyDistortEffectMap.dds", true, DAT_01201f48, false,
                                false);
    NiTexture* pDistortTexture = DAT_01201f48.m_pObject;
    ImageSpaceTexture* pTexture = new ImageSpaceTexture;
    pTextures.SetAt(3, pTexture);
    pTextures.m_pBase[3]->SetTexture(pScanTexture);
    pTextures.m_pBase[3]->NiShader_SetImplementation(3);
    pTexture = new ImageSpaceTexture;
    pTextures.SetAt(4, pTexture);
    pTextures.m_pBase[4]->SetTexture(pDistortTexture);
    pDistortTexture = (NiTexture*)new ImageSpaceTexture;
    pTextures.SetAt(2, (ImageSpaceTexture*&)pDistortTexture);
    pTextures.m_pBase[2]->SetTexture(0);
    char* effect = *(char**)(*(char**)((char*)manager + 8) + 0x12c);
    char* pAdjustedEffect = effect ? effect - 0x6c : 0;
    ImageSpaceShaderParam* pShaderParam = new ImageSpaceShaderParam;
    pShaderParam->AllocateShaderConstants(0, 3);
    pShaderParam->m_eClearFlags = (NiRenderer::ClearFlags)1;
    pShaderParam->SetShaderConstantVector4(1, DAT_011ae614, DAT_01201f2c, DAT_011ae618, 0.0f);
    pShaderParam->SetShaderConstantVector4(2, DAT_01201f30, DAT_01201f34, DAT_01201f38, DAT_01201f3c);
    pEffectParamList.SetAt(0, pShaderParam);
    SetEntryRanges(0, 1, 2, 3, 4, 0, 0, 0, 0);
    SetEffectAt(0, (ImageSpaceEffect*)(pAdjustedEffect ? pAdjustedEffect + 0x6c : 0), pShaderParam, 0);
}

struct Unknown
{
    void FUN_00bc0360();
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00bc06a0
void* Unknown::DestroyIfFlagged(unsigned int flags)
{
    FUN_00bc0360();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

class FUN_00bc0600 : public ImageSpaceEffect
{
  public:
    FUN_00bc0600();
};

// @fnv 0x00bc0600
FUN_00bc0600::FUN_00bc0600()
{
    NiColorA kWhiteColor;
    m_ppVirtualMethodTable = (void**)&DAT_010ba350;
    pTextures.SetSize(5);
    kWhiteColor.r = 1.0f;
    bIsActive = false;
    kWhiteColor.g = kWhiteColor.r;
    kWhiteColor.b = kWhiteColor.g;
    kWhiteColor.a = kWhiteColor.b;
    *(NiColorA*)&DAT_01201f30 = kWhiteColor;
}
