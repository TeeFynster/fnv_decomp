#pragma once

#include "CombatGoal.h"

class CombatGoalHideFromTarget : public CombatGoal
{
public:
    CombatGoalHideFromTarget(CombatGoal::COMBAT_GOAL eType);
};
