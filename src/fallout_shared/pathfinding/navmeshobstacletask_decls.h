#include "../../../include/Interface.h"
#include "../../../include/NavMeshInfo.h"
// fallout_shared/pathfinding/navmeshobstacletask_decls.h: local obstacle task support declarations
#ifndef NAVMESHOBSTACLETASK_DECLS_H
#define NAVMESHOBSTACLETASK_DECLS_H

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../../include/NiPointer.h"
#undef FNV64_NIPOINTER_INLINE_BODIES

#include "../../../include/AutoMemContext.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/NavMeshObstacleManager.h"

#include "../../../include/ObstacleData.h"
#include "../../../include/NavMesh.h"
#include "../../../include/ObstacleTaskData.h"

class ObstacleSource
{
  public:
    char padding[8];
    unsigned int id;
};

#include "../../../include/OBSTACLE_TASK_TYPE.h"
class ObstacleTask
{
  public:
    NiPointer<ObstacleData> m_spRegisteredObstacle;
    OBSTACLE_TASK_TYPE eType;
    unsigned int m_kResult;
    NavMeshPtr apSearchNavMesh;
    ObstacleTask(const NiPointer<ObstacleData>&, OBSTACLE_TASK_TYPE, const NavMeshPtr&);
    ~ObstacleTask();
};
class NavMeshEdgeReference
{
  public:
    NavMeshInfo* pInfo;
    unsigned int triangle;
    unsigned int edge;
};
class BGSLoadGameBuffer;

#include "../../../include/MEM_CONTEXT.h"
NiPointer<NavMesh> MakeNavMeshPointer(NavMesh*);
#define OPERATION_AT(array, index) (array).GetAt(index)
#define EDGE_AT(array, index) (array).GetAt(index)
typedef NiPointer<NiNode> BoundSmartPointer;
#define NAVMESH_FROM(pointer)                                                                                          \
    (reinterpret_cast<const BoundSmartPointer&>(pointer).*                                                             \
     reinterpret_cast<NavMesh* (BoundSmartPointer::*)() const>(&BoundSmartPointer::operator->))()
#define OBSTACLE_FROM(pointer)                                                                                         \
    (reinterpret_cast<const BoundSmartPointer&>(pointer).*                                                             \
     reinterpret_cast<ObstacleData* (BoundSmartPointer::*)() const>(&BoundSmartPointer::operator->))()
#endif
