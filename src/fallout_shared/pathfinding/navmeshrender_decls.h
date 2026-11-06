#include "../../../include/BSSimpleList.h"
// fallout_shared/pathfinding/navmeshrender_decls.h: declares ObstacleTask, NavMeshObstacleManager
#ifndef FNV_NAVMESHRENDER_DECLS_H
#define FNV_NAVMESHRENDER_DECLS_H


#include "../../../include/NiPointer.h"
#include "layout_support.h"
#include "../../../include/NavMeshPtr.h"

class ObstacleData;
class bhkRigidBody;

#include "../../../include/OBSTACLE_TASK_TYPE.h"

enum OBSTACLE_TASK_RESULT
{
    OBSTACLE_TASK_RESULT_SUCCESS,
    OBSTACLE_TASK_RESULT_FAILLURE
};

class ObstacleTask
{
  public:
    NiPointer<ObstacleData> m_spRegisteredObstacle;
    OBSTACLE_TASK_TYPE eType;
    OBSTACLE_TASK_RESULT m_kResult;
    NavMeshPtr apSearchNavMesh;
    ObstacleTask(const NiPointer<ObstacleData>& obstacle, OBSTACLE_TASK_TYPE type, const NavMeshPtr& navMesh);
};

FNV_STATIC_ASSERT(sizeof(ObstacleTask) == 0x10);
FNV_STATIC_ASSERT(offsetof(ObstacleTask, apSearchNavMesh) == 0x0c);




#include "../../../include/NiTMap.h"
// NiTMap<bhkRigidBody *,NiPointer<ObstacleData> > (its GetAt is NiTMapBase<DFALL<...> >::GetAt)
typedef NiTMap<bhkRigidBody*, NiPointer<ObstacleData> > RigidBodyObstacleMap;
// After the BSSimpleList specialization above, which the manager instantiates.
#include "../../../include/NavMeshObstacleManager.h"


FNV_STATIC_ASSERT(sizeof(LockFreeQueue<bhkRigidBody*>) == 0x40);
FNV_STATIC_ASSERT(offsetof(NavMeshObstacleManager, m_kActiveObstacles) == 0x3c);
FNV_STATIC_ASSERT(offsetof(NavMeshObstacleManager, m_kActivatedRigidBodies) == 0x60);
FNV_STATIC_ASSERT(offsetof(NavMeshObstacleManager, RigidBodyObstacleLookup) == 0xe0);

#endif
