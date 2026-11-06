#pragma once

#include "CombatGoal.h"

class CombatGoalStayInCombatArea : public CombatGoal
{
public:
    CombatGoalStayInCombatArea(CombatGoal::COMBAT_GOAL eType);
};
