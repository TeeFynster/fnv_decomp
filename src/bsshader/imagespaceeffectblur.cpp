// bsshader/imagespaceeffectblur.cpp: free functions (1 function)

#include "imagespaceeffectblur_decls.h"

// Initializes the blur effect's shader params, texture slots and effect param list entries from the manager's effects 45, 19 and 46.
// @fnv 0x00c054c0
void ImageSpaceEffectFourTexturePass::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* param)
{
    SetTextureArrayCount(3);
    pTextures.SetSize(4);

    {
        ImageSpaceShaderParam* first = new ImageSpaceShaderParam;
        first->AllocateShaderConstants(0, 1);
        first->SetShaderConstantVector4(0, 0.0f, DAT_011ae6c8, DAT_011ae6cc, 0.0f);
        ImageSpaceEffectParam* effectParam = first;
        pEffectParamList.SetAt(0, effectParam);
        SetEffectParamAt(0, 1, 1);

        SetEffectAt(0, manager->GetEffect(45), first, 2);
        first = 0;
        ImageSpaceEffectParam* nullEffectParam = first;
        pEffectParamList.SetAt(1, nullEffectParam);
        SetTextureArrayAt(1, 2, 3, NiTexturingProperty::FILTER_NEAREST, NiTexturingProperty::FILTER_NEAREST);

        SetEffectAt(1, manager->GetEffect(19), first, 2);
    }
    ImageSpaceShaderParam* second = new ImageSpaceShaderParam;
    second->AllocateShaderConstants(0, 1);
    *((unsigned char*)second + 0x56) = 0;
    second->SetShaderConstantVector4(0, 1.0f, 1.0f, 1.0f, 1.0f);
    ImageSpaceEffectParam* effectParam = second;
    pEffectParamList.SetAt(2, effectParam);
    SetTextureArrayAt(2, 2, 1, NiTexturingProperty::FILTER_BILERP, NiTexturingProperty::FILTER_NEAREST);

    SetEffectAt(2, manager->GetEffect(46), second, 0);
}
