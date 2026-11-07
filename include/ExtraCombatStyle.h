#pragma once

#include "BSExtraData.h"
struct TESCombatStyle;

class ExtraCombatStyle : public BSExtraData
{
public:
    bool Compare(BSExtraData* apCompare) override;
    bool Compare_00437300(BSExtraData* apCompare);

    TESCombatStyle* m_pCombatStyle;
};
