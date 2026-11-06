#pragma once

#include "CombatActionAttackRangedExplosive.h"

struct CombatController;
struct CombatWorldStateArray;

class CombatActionMoveAndAttackRangedExplosive : public CombatActionAttackRangedExplosive
{
public:
    CombatActionMoveAndAttackRangedExplosive(COMBAT_ACTION type);

    void FUN_0097c470();
    bool FUN_0097c490(CombatController* apController, CombatWorldStateArray* apWorldState, int aiValue);
    float FUN_0097c4d0(CombatController* apController, int aiValue);
    void FUN_0097c520(char* apBuffer, unsigned int aiSize, int aiValue);
};
