#pragma once

#include "NiObjectNET.h"

class NiUpdateData;
class NiTexture;
class NiColor;

class NiProperty : public NiObjectNET
{
  public:
    enum Type
    {
        ALPHA,
        CULLING,
        MATERIAL,
        SHADE,
        STENCIL,
        TEXTURING,
        WIREFRAME,
        COUNT
    };

    NiProperty();
    virtual ~NiProperty();

    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual Type GetType() const;
    virtual void Update(NiUpdateData& data);

    int Type();
    void BSShaderNoLightingProperty_SetBaseMap(NiTexture* pTexture);
    void NiMaterialProperty_SetEmittance(const NiColor* color);
    void NiMaterialProperty_SetAlpha(float alpha);
    void BSShaderProperty_SetFlag(int, int);
    int FUN_00441110();
    void* DestroyAndFree(unsigned int flags);
};
