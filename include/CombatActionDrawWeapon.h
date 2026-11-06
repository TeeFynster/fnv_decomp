#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionDrawWeapon : public CombatAction
{
public:
    CombatActionDrawWeapon(COMBAT_ACTION type);

    void FUN_0097c790(CombatController* apCombatController, int aiActionValue);
    void FUN_0097c990(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
};
