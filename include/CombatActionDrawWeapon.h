#pragma once

#include "CombatAction.h"

struct CombatController;

class CombatActionDrawWeapon : public CombatAction
{
public:
    CombatActionDrawWeapon(COMBAT_ACTION type);

    void AddProcedureToController_0097c790(CombatController* apCombatController, int aiActionValue);
    void GetDebugText_0097c990(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
};
