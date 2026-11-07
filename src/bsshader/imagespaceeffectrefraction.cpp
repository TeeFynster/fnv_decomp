// bsshader/imagespaceeffectrefraction.cpp: free functions (4 functions)

#include "imagespaceeffectrefraction_decls.h"

// @fnv 0x00bd9420
void RefractionImageSpaceEffect::Setup(ImageSpaceManager* manager, RefractionEffectParamLocalForm*)
{
    SetTextureArrayCount(1);
    pTextures.SetSize(3);
    ImageSpaceShaderParam* shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 1);
    WaterTintRecord_imagespaceeffectrefraction_decls waterTint = g_waterTintRecords[0];
    shaderParam->SetShaderConstantVector4(0, waterTint.r, waterTint.g, waterTint.b, waterTint.a);
    pEffectParamList.SetAt(0, shaderParam);
    SetTextureArrayAt(0, 1, 2, 0, 0);
    SetEffectAt(0, reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(manager->pEffectList)->m_pBase[41], shaderParam, 0);
}

// @fnv 0x00bd9380
BSRenderedTexture* RefractionImageSpaceEffect::GetRefractionTexture(bool create)
{
    if (!m_kRefractionTexture.GetTexture() && create)
    {
        DAT_011bf400 = 0;
        m_kRefractionTexture.ImageSpaceTexture_SetTexture(
            DAT_011f91a8->CreateRenderTargetTexture(NiRenderer::ms_pRenderer, 31, 0, 0, 0));
        DAT_011bf400 = 1;
    }
    return m_kRefractionTexture.GetRenderedTexture();
}

// @fnv 0x00bd93d0
RefractionImageSpaceEffect::RefractionImageSpaceEffect()
{
}

struct X
{
    void FUN_00bd9160();
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_00bd9160, then deallocates this via g_memoryManager if flag has bit 1 set, and returns this.
// @fnv 0x00bd9400
void* X::ReleaseIfFlagged(unsigned int flag)
{
    FUN_00bd9160();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
