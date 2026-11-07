#pragma once

#include "CombatAction.h"

class CombatController;
struct CombatWorldStateArray;

class CombatActionAttackGrenadeFlushTarget : public CombatAction
{
public:
    CombatActionAttackGrenadeFlushTarget(COMBAT_ACTION type);

    bool CanExecute_0097b840(CombatController* apController, CombatWorldStateArray* w, int aiValue);
    void Execute_0097b880(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097b980(CombatController* apCombatController, int v);
};
