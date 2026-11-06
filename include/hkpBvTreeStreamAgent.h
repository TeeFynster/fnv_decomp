#pragma once

#include "hkpCollisionAgent.h"
#include "hkAabb.h"
#include "AgentSectorPointerArray.h"

class hkpCollisionDispatcher;
class hkpCdBody;
class hkpCdBodyPairCollector;
class hkpCdPointCollector;
class hkpConstraintOwner;
class hkpContactMgr;
struct CollisionAgentContext;
struct ShapeSweepParameters;
struct GskAgentInput;
struct WorldOperationEntry;
struct AgentSubtypeMarker;
class hkStatisticsCollector;
class hkClass;
enum hkResult;

typedef unsigned int hkpShapeKey;
typedef float hkTime;
typedef unsigned short hkContactPointId;

class hkpBvTreeStreamAgent : public hkpCollisionAgent
{
public:
    virtual ~hkpBvTreeStreamAgent() throw();
    virtual void calcContentStatistics(hkStatisticsCollector* pCollector, const hkClass* pCls) const;
    virtual void getPenetrations(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdBodyPairCollector& kCollector);
    virtual void getClosestPoints(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdPointCollector& kCollector);
    virtual void linearCast(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const ShapeSweepParameters& kInput, hkpCdPointCollector& kCollector, hkpCdPointCollector* pStartCollector);
    virtual void vf06(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const GskAgentInput& kInput, WorldOperationEntry& kResult);
    virtual void cleanup(hkpConstraintOwner& kInfo);
    virtual void ProcessContactPoints(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpConstraintOwner& kConstraintOwner);
    virtual void RemovePoint(const CollisionAgentContext& kInput);
    virtual void WarpTime(hkTime kOldTime, hkTime kNewTime, const CollisionAgentContext& kInput);
    virtual void removePoint(hkContactPointId kToRemove);
    virtual void CommitPotentialContactPoint(hkContactPointId kContactPointId);
    virtual void MarkContactPointAsZombie(hkContactPointId kTobecomeZombie);

    hkpBvTreeStreamAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpContactMgr* pMgr);
    hkpBvTreeStreamAgent(void* pFirst, void* pSecond, void* pThird, void* pFourth);
    void Destroy();
    void* __thiscall FUN_00d2eae0(unsigned int uFlags);
    hkResult prepareCollisionPartnersProcess(AgentSubtypeMarker& kInput, hkArray<hkpShapeKey>& kHitList);

    static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher* pDispatcher);
    static void __cdecl registerConvexListAgent(hkpCollisionDispatcher* pDispatcher);
    static void __cdecl registerMultiRayAgent(hkpCollisionDispatcher* pDispatcher);
    static hkpCollisionAgent* __cdecl createShapeBvAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpContactMgr* pMgr);
    static hkpCollisionAgent* __cdecl createBvTreeShapeAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpContactMgr* pMgr);
    static hkpCollisionAgent* __cdecl dispatchBvTreeConvexList(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpContactMgr* pMgr);
    static hkpCollisionAgent* __cdecl dispatchConvexListBvTree(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpContactMgr* pMgr);

    hkpCollisionDispatcher* m_pCollisionDispatcher;
    hkAabb m_kBoundingBox;
    AgentSectorPointerArray m_kAgentNnTrack;
};
