#pragma once

#include "CombatActionMove.h"

class CombatActionMoveAndSwitchToMelee : public CombatActionMove
{
public:
    CombatActionMoveAndSwitchToMelee(COMBAT_ACTION type);
    void Execute_0097c090(CombatController* apCombatController, int aiActionValue);
};
