#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackGrenade : public CombatAction
{
public:
    CombatActionAttackGrenade(COMBAT_ACTION type);

    void FUN_0097b6d0(CombatController* apCombatController, int aiActionValue);
};
