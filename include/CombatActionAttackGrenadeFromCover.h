#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackGrenadeFromCover : public CombatAction
{
public:
    CombatActionAttackGrenadeFromCover(COMBAT_ACTION type);

    void FUN_0097bab0(CombatController* apCombatController, int aiActionValue);
    float FUN_0097bb90(CombatController* apCombatController, int aiActionValue);
};
