#pragma once

#include "BSExtraData.h"

class ExtraRadiation : public BSExtraData
{
public:
    virtual ~ExtraRadiation();
    bool Compare(BSExtraData* apCompare) override;

    ExtraRadiation();
    ExtraRadiation(float afRadiation);
    bool FUN_00436c40(BSExtraData* apCompare);

    float m_fRadiation;
};
