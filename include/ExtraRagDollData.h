#pragma once

#include "BSExtraData.h"

class RagDollData;

class ExtraRagDollData : public BSExtraData
{
public:
    virtual ~ExtraRagDollData();

    ExtraRagDollData();
    bool CompareRagDollData(BSExtraData* apCompare);

    RagDollData* m_pRagDollData;
};
