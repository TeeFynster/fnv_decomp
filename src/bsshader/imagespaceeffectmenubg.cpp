// bsshader/imagespaceeffectmenubg.cpp: free functions (1 function)
#include "NiRefObject_inline.h"

#include "imagespaceeffectmenubg_decls.h"

// @fnv 0x00c04730
void ImageSpaceEffectMenuBackground::Setup(ImageSpaceManager* manager, MenuBgEffectParamLocalForm* parameters)
{
    SetTextureArrayCount(1);
    pTextures.SetSize(3);
    m_pBackgroundTexture = new ImageSpaceTexture;
    if (!DAT_011f941e)
    {
        NiPointer<NiTexture> texture;
        BSShaderManager::GetTexture("Data\\Textures\\Interface\\Misc\\sepia.dds", true, texture, false, false);
        m_pBackgroundTexture->SetTexture(texture.m_pObject);
    }
    pTextures.SetAt(2, m_pBackgroundTexture);
    ImageSpaceShaderParam* shaderParameters = new ImageSpaceShaderParam;
    shaderParameters->AllocateShaderConstants(0, 1);
    shaderParameters->SetShaderConstantVector4(0, 0.0f, 0.0f, 0.0f, 0.0f);
    pEffectParamList.SetAt(0, shaderParameters);
    SetTextureArrayAt(0, 1, 2, NiTexturingProperty::FILTER_BILERP, NiTexturingProperty::FILTER_NEAREST);
    SetEffectAt(0, reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(manager->pEffectList)->m_pBase[ImageSpaceManager::EFFECT_SHADER_MENUBG], shaderParameters, 0);
}
