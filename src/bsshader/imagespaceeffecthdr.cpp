
#include "imagespaceeffecthdr_decls.h"

// @fnv 0x00BAD580
void HDRImageSpaceEffect::Setup(ImageSpaceManager* manager, HdrEffectParamLocalForm* param)
{
    SetTextureArrayCount(13);
    pTextures.SetSize(3);
    m_bUseLowResolutionPath = DAT_011f941f && DAT_011f9420 && NiRenderer::ms_pRenderer->GetDefaultRT()->Unk_23(0) <= 1280;

    ImageSpaceShaderParam* shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 0);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->SetBlurClearMode();
    pEffectParamList.SetAt(7, (HdrEffectParamLocalForm*)shaderParam);
    SetEffectAt(7, manager->GetEffect(34), shaderParam, 0);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->SetBlurClearMode();
    if (DAT_011f941f)
    {
        shaderParam->CopyParamData(3, DAT_011add48, 64);
        SetEffectAt(5, manager->GetEffect(65), shaderParam, 0);
    }
    else
    {
        shaderParam->CopyParamData(3, DAT_011add88, 256);
        SetEffectAt(5, manager->GetEffect(63), shaderParam, 0);
    }
    pEffectParamList.SetAt(5, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->SetBlurClearMode();
    if (DAT_011f941f)
    {
        shaderParam->CopyParamData(3, DAT_011add48, 64);
        SetEffectAt(12, manager->GetEffect(66), shaderParam, 0);
    }
    else
    {
        shaderParam->CopyParamData(3, DAT_011add88, 256);
        SetEffectAt(12, manager->GetEffect(68), shaderParam, 0);
    }
    pEffectParamList.SetAt(12, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[2] = false;
    shaderParam->SetBlurClearMode();
    if (DAT_011f941f)
    {
        shaderParam->CopyParamData(3, DAT_011add48, 64);
        SetEffectAt(11, manager->GetEffect(67), shaderParam, 0);
    }
    else
    {
        shaderParam->CopyParamData(3, DAT_011add88, 256);
        SetEffectAt(11, manager->GetEffect(69), shaderParam, 0);
    }
    pEffectParamList.SetAt(11, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->SetBlurClearMode();
    shaderParam->CopyParamData(3, DAT_011ade88, 144);
    SetEffectAt(6, manager->GetEffect(64), shaderParam, 0);
    pEffectParamList.SetAt(6, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->SetBlurClearMode();
    SetEffectAt(10, manager->GetEffect(71), shaderParam, 0);
    pEffectParamList.SetAt(10, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->m_bTextureFlags[2] = false;
    shaderParam->SetBlurClearMode();
    SetEffectAt(9, manager->GetEffect(70), shaderParam, 0);
    pEffectParamList.SetAt(9, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->SetBlurClearMode();
    SetEffectAt(8, manager->GetEffect(62), shaderParam, 0);
    pEffectParamList.SetAt(8, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    SetEffectAt(2, manager->GetEffect(58), shaderParam, 0);
    pEffectParamList.SetAt(2, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    SetEffectAt(3, manager->GetEffect(59), shaderParam, 0);
    pEffectParamList.SetAt(3, (HdrEffectParamLocalForm*)shaderParam);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    SetEffectAt(4, manager->GetEffect(60), shaderParam, 0);
    pEffectParamList.SetAt(4, (HdrEffectParamLocalForm*)shaderParam);
}
