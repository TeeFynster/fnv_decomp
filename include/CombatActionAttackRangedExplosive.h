#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackRangedExplosive : public CombatAction
{
public:
    CombatActionAttackRangedExplosive(COMBAT_ACTION type);

    void CombatActionAttackRanged_AddProcedureToController(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097b240(CombatController* apCombatController, int aiActionValue);

    static void __cdecl Execute(int, CombatAction*);
};
