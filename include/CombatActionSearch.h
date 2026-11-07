#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionSearch : public CombatAction
{
public:
    CombatActionSearch(COMBAT_ACTION type);

    void Execute_0097caf0(CombatController* c, int aiValue);
};
