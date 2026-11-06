#pragma once

#include "NiProperty.h"

class NiMaterialProperty : public NiProperty
{
  public:
    NiMaterialProperty();
    virtual void LoadBinary(NiStream& stream);

    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
};
