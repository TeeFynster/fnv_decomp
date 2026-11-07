#pragma once

#include "BSExtraData.h"

class ExtraSeed : public BSExtraData
{
public:
    virtual bool Compare(BSExtraData* apCompare);
    bool Compare_004325e0(BSExtraData* apCompare);

    ExtraSeed(unsigned char seed);

    unsigned char seed;
    unsigned char unk0D[3];
};
