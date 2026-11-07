#pragma once

#include "BSSimpleArray.h"
#include "BSSimpleList.h"
#include "NiTMap.h"
#include "NiAVObject.h"
#include "RecursiveSpinLock.h"

class LockPrimitive;
class ObstacleData;
class ObstacleTaskData;
class TESObjectREFR;
class bhkRigidBody;

#include "LockFreeQueue.h"

// RTTI: NiTMap<bhkRigidBody *,NiPointer<ObstacleData> >, vftable 0x0106c600.
typedef NiTMap<bhkRigidBody*, NiPointer<ObstacleData> > RigidBodyObstacleMap;

class NavMeshObstacleManager
{
public:
    unsigned char layoutPadding0[0x3C];
    BSSimpleList<NiPointer<ObstacleData> > m_kActiveObstacles;
    unsigned char unk44[0x1C];
    LockFreeQueue<bhkRigidBody*> m_kActivatedRigidBodies;
    LockFreeQueue<bhkRigidBody*> m_kDeactivatedRigidBodies;
    RigidBodyObstacleMap RigidBodyObstacleLookup;
    unsigned char unkF0[0x4C];
    BSSimpleArray<ObstacleTaskData*, 1024> m_kProcessedTasks;
    BSSimpleArray<ObstacleTaskData*, 1024> m_kBackgroundTasks;
    unsigned char unk15C[4];
    RecursiveSpinLock m_kTaskLock;

    static NavMeshObstacleManager* __cdecl GetSingleton();
    void AddObstacleReference(TESObjectREFR*); // @ref 0x006c0f10 AddObstacleReference@NavMeshObstacleManager
    void RemoveObstacleReference(TESObjectREFR*); // @ref 0x006c0dc0 RemoveObstacleReference@NavMeshObstacleManager
    void Update();
    void AddProcessedTask(ObstacleTaskData*);
    void ResetObstacles();
    unsigned int GetProcessedTaskCount();
    unsigned int GetBackgroundTaskCount();
    bool ClearBackgroundTasks();
    void QueueObstacleTasks();
    void ClearObstacles();
    void RemoveObstaclesForReference(unsigned int);
    bool ProcessObstacleTask(ObstacleTaskData*);
    LockPrimitive* GetCharPtrAtOffset();
    void ProcessActivatedObstacles();
    void NavMeshObstacleManager_AddObstacleForReference(TESObjectREFR*);
    void NavMeshObstacleManager_RemoveObstacleForReference(TESObjectREFR*); // 0x006c0c80 (thiscall; called from TESObjectCELL code)
    void NavMeshObstacleManager_QueueUpdateAllObstacle();
    void NavMeshObstacleManager_OnDoorRemove(TESObjectREFR* object);
};
