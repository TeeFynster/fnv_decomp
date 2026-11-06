#pragma once

#include "BSExtraData.h"

class ExtraCharge : public BSExtraData
{
public:
    bool Compare(BSExtraData* extra) override;

    float m_fCharge;
};
