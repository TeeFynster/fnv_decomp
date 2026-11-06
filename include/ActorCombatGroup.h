#pragma once

#include "CombatTargetTimestamp.h"

class Actor;
class BGSLoadGameBuffer;
class CombatActor;
class CombatStrategy;
struct Inner097;
struct Member;

class ActorCombatGroup
{
public:
    int pad;

    ~ActorCombatGroup();
    Actor* __thiscall GetIntAt(int index);
    CombatActor* GetIntAt(unsigned int index);
    unsigned int __thiscall GetCount();
    bool ContainsActor(Actor* actor);
    Member* FUN_00968630(int index);
    CombatActor* FUN_00968630(unsigned int index);
    void RemoveByTarget(Actor* actor);
    void RemoveByTarget(CombatActor* member);
    int FUN_005a4320();
    unsigned int FUN_00990890();
    void* __thiscall FUN_009865d0(int index);
    unsigned char __thiscall GetByteAtOffset100(int index);
    void* GetActorAtIndex(int index);
    void SetElementValue(int i, int a2);
    CombatTargetTimestamp GetLastDetectedTimestamp(Actor* actor);
    void RemoveActorsNotInGroup(BGSLoadGameBuffer* buffer);
    unsigned int GetVirtualNodeCount();
    bool TryGetQuadForState(int state, Inner097* quad, float value);
    void FUN_00986410(Actor* actor);
    void FUN_009862e0(CombatStrategy* strategy);
    unsigned char FUN_009865b0(void* controller);
    void FUN_009867d0(CombatActor* member);
    void FUN_00986740(ActorCombatGroup* oldGroup);
    void FUN_009869a0(CombatActor* member);
};
