#pragma once

#include "hkpGskBaseAgent.h"
#include "ConvexContactManifold.h"
#include "hkpCollisionDispatcher.h"

class __declspec(align(16)) hkpGskfAgent : public hkpGskBaseAgent
{
public:
    hkpGskfAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, hkpContactMgr* mgr);
    virtual ~hkpGskfAgent() throw();

    virtual void ProcessAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const GskAgentInput& input, WorldOperationEntry& result);
    virtual void cleanup(hkpConstraintOwner& constraintOwner);
    virtual void removePoint(hkContactPointId idToRemove);
    virtual void CommitPotentialContactPoint(hkContactPointId iContactPointId);
    virtual void MarkContactPointAsZombie(hkContactPointId idTobecomeZombie);

    static void __cdecl InitAgentFunc(hkpCollisionDispatcher::CollisionAgentFunctionTable& f);
    static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher* dispatcher);
    static hkpCollisionAgent* __cdecl m_pVirtualFunction0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, hkpContactMgr* mgr);

    void ProcessGskCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const GskAgentInput& input, WorldOperationEntry& result);
    void __thiscall ClearSlotById(int a);
    void __thiscall AddPotential(int a);
    ConvexContactManifold m_kContactManifold;
};
