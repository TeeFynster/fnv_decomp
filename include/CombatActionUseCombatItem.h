#pragma once

#include "CombatAction.h"

class CombatActionUseCombatItem : public CombatAction
{
public:
    CombatActionUseCombatItem(COMBAT_ACTION type);
    void Execute_0097d060(CombatController* apCombatController, int aiActionValue);
};
