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
    void FUN_00438230(NiTexture* pTexture);
    void FUN_004bc450(const NiColor* color);
    void FUN_0068c9f0(float alpha);
    void FUN_00441130(int, int);
    int FUN_00441110();
    void* DestroyAndFree(unsigned int flags);
};
