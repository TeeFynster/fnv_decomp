#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackMelee : public CombatAction
{
public:
    CombatActionAttackMelee(COMBAT_ACTION type);

    void FUN_0097b410(CombatController* apCombatController, int aiActionValue);
    float FUN_0097b4a0(CombatController* apCombatController, int aiActionValue);
};
