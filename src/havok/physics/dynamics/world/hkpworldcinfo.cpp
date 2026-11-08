#include <xmmintrin.h>

// src/havok/physics/dynamics/world/hkpworldcinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpworldcinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpWorldCinfo.h"

extern "C" void _ReadWriteBarrier();
typedef ::__m128 __m128;
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" void _mm_store_ps(float*, __m128);
extern char DAT_0102f0ec[];
extern float DAT_01018180, DAT_01013d84;
__declspec(selectany) extern const float DAT_0104da48 = 3.402820018375656e38f;
__declspec(selectany) extern const float DAT_010141cc = 0.0001f;
extern const float DAT_01017718, DAT_0101e570, DAT_01017868, DAT_0102d934, DAT_010209a0, DAT_01013ea4, DAT_010c636c,
    DAT_010c6368, DAT_0102226c;

struct Obj_c90b80
{
    void FUN_00c905b0();
};

struct RefPtr_c90b80
{
    Obj_c90b80* m_pRetainedObject;
    RefPtr_c90b80() : m_pRetainedObject(0)
    {}
    void operator=(Obj_c90b80* e)
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = e;
    }
};

struct __declspec(align(16)) VectorC90
{
    union
    {
        __m128 q;
        struct
        {
            float x, y, z, w;
        };
    };
    __forceinline void set(float a, float b, float c, float d)
    {
        _mm_store_ps((float*)&q, _mm_setr_ps(a, b, c, d));
    }
};
struct BoundsC90
{
    VectorC90 m_kMinimumCorner, m_kMaximumCorner;
};
struct WorldFieldsC90
{
    const void* m_vft;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int unk08, unk0C;
    VectorC90 m_kGravity;
    hkInt32 m_iBroadPhaseQuerySize;
    hkReal m_fContactRestingVelocity;
    hkInt8 m_iBroadPhaseBorderBehaviour;
    hkBool m_bPostponeAndSortBorderCallbacks;
    unsigned short unk2A;
    unsigned int unk2C;
    BoundsC90 m_kBroadPhaseWorldAabb;
    hkBool m_bUseKdTree;
    hkBool m_bUseMultipleTree;
    hkInt8 m_iTreeUpdateType;
    hkBool m_bAutoUpdateKdTree;
    hkReal m_fCollisionTolerance;
    RefPtr_c90b80 m_pCollisionFilter;
    RefPtr_c90b80 m_pConvexListCollisionFilter;
    hkReal m_fExpectedMaxLinearVelocity;
    hkInt32 m_sizeOfToiEventQueue;
    hkReal m_fExpectedMinPsiDeltaTime;
    RefPtr_c90b80 m_pMemoryWatchDog;
    hkInt32 m_iBroadPhaseNumMarkers;
    hkInt8 m_iContactPointGeneration;
    hkBool m_bAllowToSkipConfirmedCallbacks;
    unsigned short unk76;
    hkReal m_fSolverTau;
    hkReal m_fSolverDamp;
    hkInt32 m_iSolverIterations;
    hkInt32 m_iSolverMicrosteps;
    hkReal m_fMaxConstraintViolation;
    hkBool m_bForceCoherentConstraintOrderingInSolver;
    char unk8D, unk8E, unk8F;
    hkReal m_fSnapCollisionToConvexEdgeThreshold;
    hkReal m_fSnapCollisionToConcaveEdgeThreshold;
    hkBool m_bEnableToiWeldRejection;
    hkBool m_bEnableDeprecatedWelding;
    unsigned short unk9A;
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
    char unkB5, unkB6, unkB7;
    hkInt32 m_iMaxSectorsPerNarrowphaseTask;
    hkInt32 m_iMaxEntriesPerMidphaseToiTask;
    hkReal m_fSimplifiedToiPenetrationThreshold;
    hkReal m_fToiPenetrationThreshold;
    hkReal m_fHigherToiPenetrationThreshold;
    hkReal m_fForcedToiPenetrationThreshold;
    hkBool m_bRigidBodyFlag;
    hkInt8 m_iMaxEntriesPerNarrowphaseToiTask;
    hkBool m_bEnableSimulationIslands;
    char unkD3;
    hkUint32 m_uiMinDesiredIslandSize;
    hkBool m_bProcessActionsInSingleThread;
    hkBool m_bAllowUnconstrainedIslandJob;
    unsigned short unkDA;
    hkReal m_fFrameMarkerPsiSnap;
    hkBool m_bFireCollisionCallbacks;
    char unkE1, unkE2, unkE3;
    unsigned int unkE4, unkE8, unkEC;
    WorldFieldsC90() : m_vft(DAT_0102f0ec), m_sReferenceCount(1)
    {}
    void setVecs(float zero, float a);
    void setToi(float v);
};

__forceinline void WorldFieldsC90::setVecs(float zero, float a)
{
    m_kGravity.set(zero, a, zero, zero);
    m_bEnableSimulationIslands = 1;
    m_iBroadPhaseQuerySize = 0x400;
    m_bPostponeAndSortBorderCallbacks = 0;
    m_kBroadPhaseWorldAabb.m_kMinimumCorner.set(-500.0f, -500.0f, -500.0f, zero);
    m_kBroadPhaseWorldAabb.m_kMaximumCorner.set(500.0f, 500.0f, 500.0f, zero);
}

__forceinline void WorldFieldsC90::setToi(float v)
{
    m_fSimplifiedToiPenetrationThreshold = v;
    m_fToiPenetrationThreshold = v;
}

struct FUN_00c90b80 : WorldFieldsC90
{
    FUN_00c90b80();
};

// Initializes the physics world configuration with Havok default values for gravity, solver, collision, and deactivation parameters.
// @fnv 0x00c90b80
FUN_00c90b80::FUN_00c90b80()
{
    setVecs(0.0f, -9.8f);
    m_pCollisionFilter = 0;
    m_pConvexListCollisionFilter = 0;
    m_fSolverTau = DAT_01018180;
    m_iBroadPhaseNumMarkers = 0;
    m_sizeOfToiEventQueue = 0xfa;
    m_fSolverDamp = 1.0f;
    m_iSolverMicrosteps = 1;
    m_fContactRestingVelocity = 1.0f;
    m_fMaxConstraintViolation = DAT_0104da48;
    m_iSolverIterations = 4;
    (volatile char&)m_bForceCoherentConstraintOrderingInSolver = 0;
    m_fSnapCollisionToConvexEdgeThreshold = DAT_010c636c;
    m_fSnapCollisionToConcaveEdgeThreshold = DAT_010c6368;
    (volatile char&)m_bEnableToiWeldRejection = 0;
    m_fCollisionTolerance = 0.1f;
    _ReadWriteBarrier();
    m_iBroadPhaseBorderBehaviour = 0;
    _ReadWriteBarrier();
    m_iTreeUpdateType = 0;
    m_bUseKdTree = 0;
    m_bUseMultipleTree = 0;
    m_bAutoUpdateKdTree = 1;
    (volatile float&)m_fToiCollisionResponseRotateNormal = 0.2f;
    m_bProcessToisMultithreaded = 1;
    (volatile float&)m_fSimplifiedToiPenetrationThreshold = 3.0f;
    (volatile int&)m_iMaxSectorsPerMidphaseTask = 4;
    (volatile float&)m_fToiPenetrationThreshold = 3.0f;
    m_iMaxSectorsPerNarrowphaseTask = 8;
    m_iMaxEntriesPerMidphaseToiTask = 1;
    (volatile float&)m_fHigherToiPenetrationThreshold = 4.0f;
    m_fForcedToiPenetrationThreshold = DAT_01017868;
    m_fDeactivationReferenceDistance = DAT_0102d934;
    m_fExpectedMaxLinearVelocity = DAT_0102226c;
    m_fExpectedMinPsiDeltaTime = DAT_010209a0;
    m_fValue = DAT_01013ea4;
    (volatile char&)m_bEnableDeprecatedWelding = 0;
    (volatile int&)m_iValue = 0x14;
    (volatile char&)m_bRigidBodyFlag = 1;
    (volatile char&)m_bActivateOnBodyTransformChange = 1;
    (volatile int&)m_uiMinDesiredIslandSize = 0x40;
    (volatile char&)m_uiDeactivationNumInactiveFramesSelectFlag0 = 0;
    (volatile char&)m_uiDeactivationNumInactiveFramesSelectFlag1 = 0;
    (volatile char&)m_ucDeactivationIntegrateCounter = 0;
    (volatile char&)m_iContactPointGeneration = 2;
    (volatile char&)m_bAllowToSkipConfirmedCallbacks = 0;
    (volatile float&)m_fFrameMarkerPsiSnap = DAT_010141cc;
    (volatile char&)m_iMaxEntriesPerNarrowphaseToiTask = 2;
    m_pMemoryWatchDog = 0;
    m_bProcessActionsInSingleThread = 1;
    _ReadWriteBarrier();
    m_bAllowUnconstrainedIslandJob = 0;
    m_bFireCollisionCallbacks = 0;
}
