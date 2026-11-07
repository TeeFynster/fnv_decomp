#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionSwitchWeapon : public CombatAction
{
public:
    CombatActionSwitchWeapon(COMBAT_ACTION type);
    float GetCost_0097c8e0(CombatController* apCombatController, int aiActionValue);
};
