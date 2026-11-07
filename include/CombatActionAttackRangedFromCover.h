#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackRangedFromCover : public CombatAction
{
public:
    CombatActionAttackRangedFromCover(COMBAT_ACTION type);

    void Execute_0097af70(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097b070(CombatController* apCombatController, int aiActionValue);
};
