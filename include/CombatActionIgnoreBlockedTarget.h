#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionIgnoreBlockedTarget : public CombatAction
{
public:
    CombatActionIgnoreBlockedTarget(COMBAT_ACTION type);

    virtual void vfn_0();

    void Execute_0097ccf0(CombatController* apCombatController, int aiActionValue);
};
