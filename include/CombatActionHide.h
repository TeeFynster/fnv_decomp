#pragma once

#include "CombatAction.h"

class CombatActionHide : public CombatAction
{
public:
    CombatActionHide(COMBAT_ACTION type);
    void GetDebugText_0097d370(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
    void Execute_0097d2d0(CombatController* apCombatController, int aiActionValue);
};
