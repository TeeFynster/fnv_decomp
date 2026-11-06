#pragma once

#include "CombatGoal.h"

class CombatGoalFallBack : public CombatGoal
{
public:
    CombatGoalFallBack(CombatGoal::COMBAT_GOAL eType);
};
