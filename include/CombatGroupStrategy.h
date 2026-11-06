#pragma once

class ActorCombatGroup;
class MarkerStruct;

class CombatGroupStrategy
{
public:
    virtual bool CanFlank(MarkerStruct* apGroupData, ActorCombatGroup* apGroup);
    virtual void __thiscall vf01(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
    virtual bool __thiscall vf02(ActorCombatGroup* apGroup);

    bool CheckGroup(ActorCombatGroup* apGroup);

    int unk04;
};
