#pragma once

#include "BSExtraData.h"

class ExtraHealthPerc : public BSExtraData
{
public:
    ExtraHealthPerc();
    bool Compare(BSExtraData* extra) override;
    bool Compare_00431db0(BSExtraData* extra);

    float m_fHealthPercentage;
};
