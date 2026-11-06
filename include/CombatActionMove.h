#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionMove : public CombatAction
{
public:
    CombatActionMove(COMBAT_ACTION type);

    bool FUN_0097bc80(CombatController* apCombatController, int aiActionValue);
    void FUN_0097bca0(CombatController* apCombatController, int aiActionValue);
    float FUN_0097bcc0(CombatController* apCombatController, int aiActionValue);
};
