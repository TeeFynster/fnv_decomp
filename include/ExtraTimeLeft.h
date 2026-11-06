#pragma once

#include "BSExtraData.h"

class ExtraTimeLeft : public BSExtraData
{
public:
    ExtraTimeLeft(float time);

    bool Compare(BSExtraData* extra) override;
    bool FUN_00431ef0(BSExtraData* extra);

    float fTime;
};
