#pragma once

#include "BSWin32TaskletData.h"
#include "BSSimpleArray.h"
#include "NavMeshPtr.h"

class NavMeshInfo;
class NavMeshEdgeReference;
class ObstacleData;
class ObstacleTask;
template <class T> class NiPointer;
enum OBSTACLE_TASK_TYPE;

class ParentChildLinks
{
public:
    BSSimpleArray<NavMeshEdgeReference, 1024> children;
    BSSimpleArray<NavMeshEdgeReference, 1024> parents;
};

class ObstacleTaskData : public BSWin32TaskletData
{
public:
    virtual ~ObstacleTaskData();
    virtual void Process();

    NavMeshInfo* pInfo;
    NavMeshPtr m_spSourceNavMesh;
    NavMeshPtr m_spWorkingNavMesh;
    BSSimpleArray<ObstacleTask, 1024> Operations;
    ParentChildLinks m_kParentChildLinks;
    bool bForce;

    bool AddOperation(const NiPointer<ObstacleData>&, OBSTACLE_TASK_TYPE);
    void vfn_04();
    void Run();
    void SortOperations();
};
