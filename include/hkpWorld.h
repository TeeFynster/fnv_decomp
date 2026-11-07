#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkVector4.h"
#include "hkMultiThreadCheck.h"
#include "hkBool.h"
#include "hkaAnimation.h"

class hkpSimulation;
class hkpSimulationIsland;
class hkpPhantom;
class hkpCollisionDispatcher;
class hkpPhysicsSystem;
class hkpEntity;
class hkpRigidBody;
class hkpUnaryAction;
class hkpWorldCinfo;
class hkBoolH;
class hkBoolResult;

class hkpWorld : public hkReferencedObject
{
  public:
    enum ReintegrationRecollideMode
    {
        RR_MODE_REINTEGRATE = 1,
        RR_MODE_RECOLLIDE_BROADPHASE = 2,
        RR_MODE_RECOLLIDE_NARROWPHASE = 4,
        RR_MODE_ALL = 7
    };
    enum MtAccessChecking
    {
        MT_ACCESS_CHECKING_ENABLED = 0,
        MT_ACCESS_CHECKING_DISABLED = 1
    };
    enum CachedAabbUpdate
    {
        SHIFT_BROADPHASE_UPDATE_ENTITY_AABBS = 0,
        SHIFT_BROADPHASE_IGNORE_ENTITY_AABBS = 1
    };
    hkpSimulation* m_pSimulation;
    char padC[0x4];
    hkVector4 m_kGravity;
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArray<void*> m_kActiveSimulationIslands;
    hkArray<void*> m_kInactiveSimulationIslands;
    hkArray<void*> m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    hkBool m_bAssertOnRunningOutOfSolverMemory;
    char pad55[0x3];
    void* m_pJobSemaphore;
    void* m_pKdTreeManager;
    hkBool m_bUseKdTree;
    char pad61[0x3];
    void* m_pBroadPhaseDispatcher;
    void* m_pPhantomBroadPhaseListener;
    void* m_pEntityEntityBroadPhaseListener;
    void* m_pBroadPhaseBorderListener;
    void* m_pMultithreadedSimulationJobData;
    void* m_pCollisionInput;
    void* m_pCollisionFilter;
    void* m_pDispatcher;
    void* m_pConvexListCollisionFilter;
    void* m_pPendingOperations;
    hkInt32 m_iPendingOperationCount;
    hkInt32 m_iQueuedOperationCount;
    hkInt32 m_iCriticalOperationsLockCount;
    hkInt32 m_iCriticalOperationsLockCountForPhantoms;
    hkBool m_bBlockExecutingPendingOperations;
    hkBool m_bBlockExecutingPendingOperationQueues;
    char pad9E[0x2];
    void* m_pPendingOperationQueues;
    hkInt32 m_iPendingOperationQueueCount;
    hkMultiThreadCheck m_kMultiThreadCheck;
    hkBool m_bProcessActionsInSingleThread;
    hkBool m_bAllowUnconstrainedIslandJob;
    char padB2[0x2];
    unsigned int m_uiMinDesiredIslandSize;
    void* m_pModifyConstraintCriticalSection;
    hkInt32 m_iIsLocked;
    void* m_pIslandDirtyListCriticalSection;
    void* m_pPropertyMasterLock;
    hkBool m_bWantSimulationIslands;
    char padC9[0x3];
    hkReal m_fSnapCollisionToConvexEdgeThreshold;
    hkReal m_fSnapCollisionToConcaveEdgeThreshold;
    hkBool m_bEnableToiWeldRejection;
    hkBool m_bWantDeactivation;
    hkBool m_bActivateOnBodyTransformChange;
    char padD7[0x1];
    hkReal m_fDeactivationReferenceDistance;
    hkReal m_fToiCollisionResponseRotateNormal;
    hkInt32 m_iMaxSectorsPerMidphaseTask;
    hkBool m_bProcessToisMultithreaded;
    char padE5[0x3];
    hkInt32 m_iMaxSectorsPerNarrowphaseTask;
    hkInt32 m_iMaxEntriesPerMidphaseToiTask;
    hkInt32 m_iMaxEntriesPerNarrowphaseToiTask;
    hkReal m_fSimplifiedToiPenetrationThreshold;
    hkReal m_fToiPenetrationThreshold;
    hkReal m_fHigherToiPenetrationThreshold;
    hkReal m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid;
    unsigned int m_uiLastIslandUid;
    unsigned int m_uiLastConstraintUid;
    hkArray<hkpPhantom*> m_kPhantoms;
    hkArray<void*> m_kActionListeners;
    hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners;
    hkArray<void*> m_kConstraintListeners;
    hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners;
    hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners;
    hkArray<void*> m_kWorldPostCollideListeners;
    hkArray<void*> m_kIslandPostIntegrateListeners;
    hkArray<void*> m_kIslandPostCollideListeners;
    hkArray<void*> m_kContactListeners;
    hkArray<void*> m_kContactImpulseLimitBreachedListeners;
    void* m_pViolatedConstraintArray;
    void* m_pBroadPhaseBorder;
    void* m_pBroadPhaseQueryCache;
    void* m_pBroadPhaseRegionData;
    char pad1C8[0x148];
    hkVector4 m_kBroadPhaseAabb[2];
    hkInt32 m_iBroadPhaseNumMarkers;
    hkInt32 m_sizeOfToiEventQueue;
    hkInt32 m_iBroadPhaseQuerySize;
    hkInt32 m_iBroadPhaseNumObjects;
    signed char m_iContactPointGeneration;
    char pad341[0xF];

    hkpWorld(const hkpWorldCinfo* info) throw();
    static void* __cdecl operator new(std::size_t size) throw();

    hkpCollisionDispatcher* getCollisionDispatcher() const;
    void lockCriticalOperations();
    void unlockCriticalOperations();
    void unlockAndAttemptToExecutePendingOperations();
    void attemptToExecutePendingOperations(bool executeBodyOperations = true);
  private:
    void ExecutePendingOperations();
    void ExecutePendingOperationQueues();

  public:
    void allowCriticalOperations(hkBool allow);
    void allowCriticalOperations(hkBoolH allow);
    void lock();
    void unlock();
    hkpPhysicsSystem* getWorldAsOneSystem() const;
    void* getUserData() const;
    void ProcessPair(hkpEntity* a, hkpEntity* b);
    hkBoolResult ProcessTarget(hkpRigidBody* entity);
    void RemoveActionFromEntity(hkpUnaryAction* action, hkpEntity* entity);
    void __cdecl AddCollisionShape(void* entity) throw();

    float hkpWorld_getCurrentTime();
    float hkpWorld_getCurrentPsiTime();
    void nullsub_5(hkpSimulationIsland* island);
    void __thiscall nullsub_6();
    void FUN_00c91120();
    void UpdateFields_00c91140();
    void hkpWorld_queueOperation(void* operation);
    void* hkpWorld_addEntity(hkpRigidBody* entity, int activation);
    void hkpWorld_attachActionToEntity(hkpUnaryAction* action, hkpEntity* entity);
    int __thiscall hkpWorld_getMemoryWatchDog();
    void hkpWorld_addPhantom(hkpPhantom* phantom);
    void hkpWorld_addWorldPostSimulationListener(void* listener);
    void hkpWorld_addWorldDeletionListener(void* listener);
    void hkpWorld_updateCollisionFilterOnEntity(void* entity, void* collection, int updateShape);
    hkpWorld* hkpWorld_hkpWorld(const hkpWorldCinfo* info, unsigned int version = 0x111d4) throw();
    void hkpWorld_updateCollisionFilterOnWorld(int a, int b) throw();
    void hkpWorld_addPhysicsSystem(hkpPhysicsSystem* system) throw();
};
