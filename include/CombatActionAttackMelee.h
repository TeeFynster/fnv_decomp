#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackMelee : public CombatAction
{
public:
    CombatActionAttackMelee(COMBAT_ACTION type);

    void AddProcedureToController(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097b4a0(CombatController* apCombatController, int aiActionValue);
};
