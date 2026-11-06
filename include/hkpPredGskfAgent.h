#pragma once

#include "hkpGskfAgent.h"

class hkpPredGskfAgent : public hkpGskfAgent
{
public:
    hkpPredGskfAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, hkpContactMgr* mgr);

    virtual void ProcessAgent(const hkpCdBody& a, const hkpCdBody& b, const GskAgentInput& input, WorldOperationEntry& result);

    static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher* dispatcher);
    static hkpCollisionAgent* __cdecl CreateCollisionAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, hkpContactMgr* mgr);
};
