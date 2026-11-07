#pragma once

#include "BSExtraData.h"

class ExtraWeaponModFlags : public BSExtraData
{
public:
    virtual bool Compare(BSExtraData* extra);

    bool IsModActive(unsigned char acSlot);
    bool Compare_00432140(BSExtraData* extra);

    unsigned char m_ucWeaponModFlags;
    unsigned char unk0D[3];
};
