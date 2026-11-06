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
    bool FUN_0040f2d0(BSExtraData* apCompare);

    CellImpactSwapValue* m_pCellImpactSwapValue;
};
