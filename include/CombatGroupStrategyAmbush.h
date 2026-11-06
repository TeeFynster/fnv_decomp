#pragma once

#include "CombatGroupStrategy.h"

class CombatGroupStrategyAmbush : public CombatGroupStrategy
{
public:
    virtual bool CanFlank(MarkerStruct* apGroupData, ActorCombatGroup* apGroup) override;
    virtual void __thiscall vf01(ActorCombatGroup* apGroup, MarkerStruct* apGroupData) override;
    virtual bool __thiscall vf02(ActorCombatGroup* apGroup) override;
};
