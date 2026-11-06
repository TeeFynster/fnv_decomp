#pragma once

#include "BSTextureSet.h"

class BSShaderTextureSet : public BSTextureSet
{
  public:
    BSShaderTextureSet();

    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual void GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& texture);
    virtual const char* GetTexture(BSShaderProperty::TextureTypeEnum textureType);
    virtual void SetTexture(BSShaderProperty::TextureTypeEnum textureType, const char* textureName);

    const NiRTTI* GetNiRTTI() const;

    char names[48];
};
