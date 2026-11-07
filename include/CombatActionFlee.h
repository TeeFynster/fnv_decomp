#pragma once

#include "CombatAction.h"

class CombatActionFlee : public CombatAction
{
public:
    CombatActionFlee(COMBAT_ACTION type);
    void Execute_0097cdb0(CombatController* apCombatController, int aiActionValue);
};
