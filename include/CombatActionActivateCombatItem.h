#pragma once

#include "CombatAction.h"

class CombatActionActivateCombatItem : public CombatAction
{
public:
    CombatActionActivateCombatItem(COMBAT_ACTION type);
    void Execute_0097cf10(CombatController* apCombatController, int aiActionValue);
};
