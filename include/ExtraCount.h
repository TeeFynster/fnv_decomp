#pragma once

#include "BSExtraData.h"

class ExtraCount : public BSExtraData
{
public:
    short iCount;
    unsigned char layoutPaddingE[2];

    virtual ~ExtraCount();

    ExtraCount();
    ExtraCount(short aCount);
    bool Compare_00431c50(BSExtraData* compare);
};
