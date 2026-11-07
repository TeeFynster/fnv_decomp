#pragma once

#include "CombatActionAttackGrenade.h"

struct CombatController;

class CombatActionMoveAndAttackGrenade : public CombatActionAttackGrenade
{
public:
    CombatActionMoveAndAttackGrenade(COMBAT_ACTION type);

    void Execute_0097c620(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097c6b0(CombatController* c, int v);
};
