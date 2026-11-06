#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackRangedFromCover : public CombatAction
{
public:
    CombatActionAttackRangedFromCover(COMBAT_ACTION type);

    void FUN_0097af70(CombatController* apCombatController, int aiActionValue);
    float FUN_0097b070(CombatController* apCombatController, int aiActionValue);
};
