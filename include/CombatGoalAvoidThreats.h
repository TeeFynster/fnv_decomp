#pragma once

#include "CombatGoal.h"

class CombatGoalAvoidThreats : public CombatGoal
{
public:
    CombatGoalAvoidThreats(CombatGoal::COMBAT_GOAL eType);
};
