#pragma once

#include "BSExtraData.h"

class ExtraRadius : public BSExtraData
{
public:
    bool Compare(BSExtraData* extra) override;
    bool Compare_00436bd0(BSExtraData* extra);

    ExtraRadius();

    float fRadius;
};
