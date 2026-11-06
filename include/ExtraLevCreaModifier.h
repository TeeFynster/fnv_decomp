#pragma once

#include "BSExtraData.h"

class ExtraLevCreaModifier : public BSExtraData
{
public:
    virtual ~ExtraLevCreaModifier();
    virtual bool Compare(BSExtraData* apCompare) override;

    ExtraLevCreaModifier();

    float GetMultiplier();
    int GetAllBelowForce();

    int m_iModifier;
};
