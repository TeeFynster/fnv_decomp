#pragma once

#include "BSExtraData.h"

class CellImpactSwapValue;

class ExtraCellImpactSwap : public BSExtraData
{
public:
    ExtraCellImpactSwap();
    virtual ~ExtraCellImpactSwap();
    bool Compare(BSExtraData* extra) override;

    void FUN_0040f210();
    void* FUN_0040f1e0(unsigned int flags);
    bool ExtraCellImpactSwap_Compare(BSExtraData* apCompare);

    CellImpactSwapValue* m_pCellImpactSwapValue;
};
