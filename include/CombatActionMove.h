#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionMove : public CombatAction
{
public:
    CombatActionMove(COMBAT_ACTION type);

    bool CheckIdentical(CombatController* apCombatController, int aiActionValue);
    void Execute_0097bca0(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097bcc0(CombatController* apCombatController, int aiActionValue);
};
