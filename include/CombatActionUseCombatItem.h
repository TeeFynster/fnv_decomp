#pragma once

#include "CombatAction.h"

class CombatActionUseCombatItem : public CombatAction
{
public:
    CombatActionUseCombatItem(COMBAT_ACTION type);
    void FUN_0097d060(CombatController* apCombatController, int aiActionValue);
};
