#pragma once

#include "NiAVObject.h"

class NiFixedString;
class NiTexture;

class SkyShaderProperty
{
public:
    unsigned char propertyData[0x70];
    NiPointer<NiTexture> m_spTexture;

    void SetTexture(NiTexture*);
    void SetTextureFile(const NiFixedString&);
    void SetTextureFile(int*);
    void SkyShaderProperty_SetBlendValue(float);
    void NiPhysXProp_SetSnapshot(NiTexture*);
    NiTexture* BGSCameraShot_GetImagespaceTarget();
};
