#pragma once

#include "hkpIterativeLinearCastAgent.h"

class hkpCdBody;
class hkpCdBodyPairCollector;
class hkpCdPointCollector;
class hkpCollisionDispatcher;
class hkpConstraintOwner;
class hkpContactMgr;
class hkContactPoint;
struct CollisionAgentContext;
struct GskAgentInput;
struct ShapeSweepParameters;
struct WorldOperationEntry;

typedef unsigned short hkContactPointId;
typedef float hkTime;

class hkpSphereCapsuleAgent : public hkpIterativeLinearCastAgent
{
public:
    virtual void getPenetrations(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdBodyPairCollector& kCollector);
    virtual void getClosestPoints(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdPointCollector& kPointDetails);
    virtual void linearCast(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const ShapeSweepParameters& kInput, hkpCdPointCollector& kCastCollector, hkpCdPointCollector* pStartCollector);
    virtual void ProcessAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const GskAgentInput& kInput, WorldOperationEntry& kResult);
    virtual void cleanup(hkpConstraintOwner& kInfo);
    virtual void ProcessContactPoints(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpConstraintOwner& kConstraintOwner);
    virtual void RemovePoint(const CollisionAgentContext& kInput);
    virtual void WarpTime(hkTime kOldTime, hkTime kNewTime, const CollisionAgentContext& kInput);
    virtual void removePoint(hkContactPointId kToRemove);
    virtual void CommitPotentialContactPoint(hkContactPointId kContactPointId);
    virtual void MarkContactPointAsZombie(hkContactPointId kTobecomeZombie);

    enum ClosestPointResult
    {
        ST_CP_MISS,
        ST_CP_HIT
    };

    hkpSphereCapsuleAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpContactMgr* pMgr);

    static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher* pDispatcher);
    static void __cdecl m_pVirtualFunction2(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdPointCollector& kCollector);
    static void __cdecl m_pVirtualFunction1(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdBodyPairCollector& kCollector);
    static hkpCollisionAgent* __cdecl createSphereCapsuleAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpContactMgr* pMgr);
    static hkpCollisionAgent* __cdecl createCapsuleSphereAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpContactMgr* pMgr);
    static ClosestPointResult getClosestPointInl(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkContactPoint& kCpoint);
    static ClosestPointResult __cdecl ComputeClosestPoints(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkContactPoint& kCpoint);

    hkContactPointId m_usContactPointId;
};
