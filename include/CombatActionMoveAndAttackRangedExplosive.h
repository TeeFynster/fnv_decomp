#pragma once

#include "CombatActionAttackRangedExplosive.h"

struct CombatController;
struct CombatWorldStateArray;

class CombatActionMoveAndAttackRangedExplosive : public CombatActionAttackRangedExplosive
{
public:
    CombatActionMoveAndAttackRangedExplosive(COMBAT_ACTION type);

    void FUN_0097c470();
    bool CombatActionMove_CanExecute(CombatController* apController, CombatWorldStateArray* apWorldState, int aiValue);
    float GetCost_0097c4d0(CombatController* apController, int aiValue);
    void CombatActionActivateCombatItem_GetDebugText(char* apBuffer, unsigned int aiSize, int aiValue);
};
