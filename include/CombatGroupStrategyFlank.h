#pragma once

#include "CombatGroupStrategy.h"

class MarkerStruct;
class ActorCombatGroup;

class CombatGroupStrategyFlank : public CombatGroupStrategy
{
public:
    virtual bool CanFlank(MarkerStruct* apGroupData, ActorCombatGroup* apGroup) override;
    virtual void __thiscall vf01(ActorCombatGroup* apGroup, MarkerStruct* apGroupData) override;
};
