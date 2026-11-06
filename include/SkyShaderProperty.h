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
    void FUN_00634900(const NiFixedString&);
    void FUN_00634900(int*);
    void FUN_0051b8c0(float);
    void FUN_00bae930(NiTexture*);
    NiTexture* FUN_009c8680();
};
