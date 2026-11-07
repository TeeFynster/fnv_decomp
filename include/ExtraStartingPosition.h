#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraStartingPosition : public BSExtraData
{
public:
    ExtraStartingPosition();
    ExtraStartingPosition(TESObjectREFR* apObject);

    bool Compare(BSExtraData* extra) override;
    bool Compare_00430850(BSExtraData* apCompare);

    float x;
    float y;
    float z;
    unsigned char unk18[0x0C];
};
