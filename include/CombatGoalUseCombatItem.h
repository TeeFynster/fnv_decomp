#pragma once

#include "CombatGoal.h"

class CombatGoalUseCombatItem : public CombatGoal
{
public:
    CombatGoalUseCombatItem(CombatGoal::COMBAT_GOAL eType);
};
