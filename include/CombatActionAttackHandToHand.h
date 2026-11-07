#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionAttackHandToHand : public CombatAction
{
public:
    CombatActionAttackHandToHand(COMBAT_ACTION type);

    float GetCost_0097b5a0(CombatController* c, int v);
};
