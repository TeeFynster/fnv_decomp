#pragma once

#include "CombatActionAttackRanged.h"

struct CombatController;

class CombatActionMoveAndAttackRanged : public CombatActionAttackRanged
{
public:
    CombatActionMoveAndAttackRanged(COMBAT_ACTION type);

    void AddProcedureToController_0097c280(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097c310(CombatController* apCombatController, int aiActionValue);
};
