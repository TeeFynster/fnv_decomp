#pragma once

#include "hkReferencedObject.h"
#include "hkVector4.h"
#include "hkAabb.h"
#include "hkBool.h"
#include "hkpCollisionFilter.h"

class hkWorldMemoryAvailableWatchDog;
class hkpConvexListFilter;
struct ClassMemberDescriptor;

typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef int hkInt32;
typedef unsigned int hkUint32;

class hkpWorldCinfo : public hkReferencedObject
{
  public:
    static const ClassMemberDescriptor Members[];

    enum SolverType
    {
        SOLVER_TYPE_INVALID = 0,
        SOLVER_TYPE_2ITERS_SOFT = 1,
        SOLVER_TYPE_2ITERS_MEDIUM = 2,
        SOLVER_TYPE_2ITERS_HARD = 3,
        SOLVER_TYPE_4ITERS_SOFT = 4,
        SOLVER_TYPE_4ITERS_MEDIUM = 5,
        SOLVER_TYPE_4ITERS_HARD = 6,
        SOLVER_TYPE_8ITERS_SOFT = 7,
        SOLVER_TYPE_8ITERS_MEDIUM = 8,
        SOLVER_TYPE_8ITERS_HARD = 9,
        SOLVER_TYPE_MAX_ID = 10
    };
    enum SimulationType
    {
        SIMULATION_TYPE_INVALID = 0,
        SIMULATION_TYPE_DISCRETE = 1,
        SIMULATION_TYPE_CONTINUOUS = 2,
        SIMULATION_TYPE_MULTITHREADED = 3
    };
    enum ContactPointGeneration
    {
        CONTACT_POINT_ACCEPT_ALWAYS = 0,
        CONTACT_POINT_REJECT_DUBIOUS = 1,
        CONTACT_POINT_REJECT_MANY = 2
    };
    enum BroadPhaseBorderBehaviour
    {
        BROADPHASE_BORDER_ASSERT = 0,
        BROADPHASE_BORDER_FIX_ENTITY = 1,
        BROADPHASE_BORDER_REMOVE_ENTITY = 2,
        BROADPHASE_BORDER_DO_NOTHING = 3
    };
    enum TreeUpdateType
    {
        REBUILD_ACTIVE = 0,
        REBUILD_ALL = 1
    };
    char pad8[0x8];
    hkVector4 m_kGravity;
    hkInt32 m_iBroadPhaseQuerySize;
    hkReal m_fContactRestingVelocity;
    hkInt8 m_iBroadPhaseBorderBehaviour;
    hkBool m_bPostponeAndSortBorderCallbacks;
    char pad2A[0x6];
    hkAabb m_kBroadPhaseWorldAabb;
    hkBool m_bUseKdTree;
    hkBool m_bUseMultipleTree;
    hkInt8 m_iTreeUpdateType;
    hkBool m_bAutoUpdateKdTree;
    hkReal m_fCollisionTolerance;
    hkpCollisionFilter* m_pCollisionFilter;
    hkpConvexListFilter* m_pConvexListCollisionFilter;
    hkReal m_fExpectedMaxLinearVelocity;
    hkInt32 m_sizeOfToiEventQueue;
    hkReal m_fExpectedMinPsiDeltaTime;
    hkWorldMemoryAvailableWatchDog* m_pMemoryWatchDog;
    hkInt32 m_iBroadPhaseNumMarkers;
    hkInt8 m_iContactPointGeneration;
    hkBool m_bAllowToSkipConfirmedCallbacks;
    char pad76[0x2];
    hkReal m_fSolverTau;
    hkReal m_fSolverDamp;
    hkInt32 m_iSolverIterations;
    hkInt32 m_iSolverMicrosteps;
    hkReal m_fMaxConstraintViolation;
    hkBool m_bForceCoherentConstraintOrderingInSolver;
    char pad8D[0x3];
    hkReal m_fSnapCollisionToConvexEdgeThreshold;
    hkReal m_fSnapCollisionToConcaveEdgeThreshold;
    hkBool m_bEnableToiWeldRejection;
    hkBool m_bEnableDeprecatedWelding;
    char pad9A[0x2];
    hkReal m_fValue;
    hkInt32 m_iValue;
    hkUint8 m_uiDeactivationNumInactiveFramesSelectFlag0;
    hkUint8 m_uiDeactivationNumInactiveFramesSelectFlag1;
    hkUint8 m_ucDeactivationIntegrateCounter;
    hkBool m_bActivateOnBodyTransformChange;
    hkReal m_fDeactivationReferenceDistance;
    hkReal m_fToiCollisionResponseRotateNormal;
    hkInt32 m_iMaxSectorsPerMidphaseTask;
    hkBool m_bProcessToisMultithreaded;
    char padB5[0x3];
    hkInt32 m_iMaxSectorsPerNarrowphaseTask;
    hkInt32 m_iMaxEntriesPerMidphaseToiTask;
    hkReal m_fSimplifiedToiPenetrationThreshold;
    hkReal m_fToiPenetrationThreshold;
    hkReal m_fHigherToiPenetrationThreshold;
    hkReal m_fForcedToiPenetrationThreshold;
    hkBool m_bRigidBodyFlag;
    hkInt8 m_iMaxEntriesPerNarrowphaseToiTask;
    hkBool m_bEnableSimulationIslands;
    char padD3[0x1];
    hkUint32 m_uiMinDesiredIslandSize;
    hkBool m_bProcessActionsInSingleThread;
    hkBool m_bAllowUnconstrainedIslandJob;
    char padDA[0x2];
    hkReal m_fFrameMarkerPsiSnap;
    hkBool m_bFireCollisionCallbacks;
    char padE1[0xF];
};
