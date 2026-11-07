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
    Member* CombatGroup_GetTarget(int index);
    CombatActor* CombatGroup_GetTarget(unsigned int index);
    void RemoveByTarget(Actor* actor);
    void RemoveByTarget(CombatActor* member);
    int PathingSolution_GetVirtualNodeCount();
    unsigned int CombatGroup_GetMemberCount();
    void* __thiscall CombatGroup_GetCombatTargetForActor(int index);
    unsigned char __thiscall GetByteAtOffset100(int index);
    void* GetActorAtIndex(int index);
    void SetElementValue(int i, int a2);
    CombatTargetTimestamp GetLastDetectedTimestamp(Actor* actor);
    void RemoveActorsNotInGroup(BGSLoadGameBuffer* buffer);
    unsigned int GetVirtualNodeCount();
    bool TryGetQuadForState(int state, Inner097* quad, float value);
    void CombatGroup_AddTarget(Actor* actor);
    void CombatGroup_ForceGroupStrategy(CombatStrategy* strategy);
    unsigned char CombatGroup_IsTarget(void* controller);
    void CombatGroup_AddMember(CombatActor* member);
    void CombatGroup_CopyTargets(ActorCombatGroup* oldGroup);
    void CombatGroup_RemoveMember(CombatActor* member);
};
