#pragma once

#include "BSExtraData.h"

class ExtraModdingItem : public BSExtraData
{
public:
    virtual bool Compare(BSExtraData* extra);

    bool __thiscall IsDifferentFrom(BSExtraData* extra);

    unsigned char unk0C;
    unsigned char unk0D[3];
};
