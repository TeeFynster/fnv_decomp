#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackRanged : public CombatAction
{
public:
    CombatActionAttackRanged(COMBAT_ACTION type);

    float FUN_0097ae00(CombatController* apCombatController, int aiActionValue);
};
