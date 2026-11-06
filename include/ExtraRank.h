#pragma once

#include "BSExtraData.h"

class ExtraRank : public BSExtraData
{
public:
    bool Compare(BSExtraData* apCompare) override;

    int m_iRank;
};
