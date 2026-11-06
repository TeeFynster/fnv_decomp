#pragma once

#include "AStarSearch.h"
#include "BSSimpleArray.h"
#include "NavMeshEdgeData.h"
#include "NavMeshPOVSearch.h"
#include "NiPoint3.h"

class PathSmootherPOVNode;
class Key6AE;
class PathSmootherPOVLink;
class PathSmootherPOVAvoidanceNode;
class PathSmootherPOVPoint;
class NavMesh;
class NavMeshEdgePoint;
class NavMeshEdgeSegment;
class NavMeshInfo;
class NavMeshTriangleReference;
class NavMeshTriangleEdgeReference;
class PathingRequest;
class PathingSolution;
class SineCosine;
class Sphere;
class CircularArc;

template <class N, class L> class AStarNode;
typedef AStarNode<PathSmootherPOVAvoidanceNode, NavMeshEdgeSegment> POVNode;

class PathSmootherPOVSearch : public AStarSearch<PathSmootherPOVNode, PathSmootherPOVLink>
{
public:
    void* DestroyPathSmootherPOVSearch(unsigned int);
    void CreateStartPoint();
    void CreateGoalPoint();
    void CollectAvoidSpheres();
    void* ComputePathNodes();
    void CopyNodeListToArrays(void*, BSSimpleArray<PathSmootherPOVAvoidanceNode, 1024>*,
                              BSSimpleArray<NavMeshEdgeSegment, 1024>*);
    void AddEntry(const Key6AE*, const NavMeshEdgeData&);

    PathSmootherPOVSearch();
    virtual ~PathSmootherPOVSearch();
    virtual bool CollectConnections(const POVNode*, BSSimpleArray<POVNode*, 1024>*);
    virtual bool HasReachedGoal(const POVNode*);

    class NavMeshEdgeRecord
    {
    public:
        NavMesh* m_pLocationNavMesh;
        unsigned short m_usVertexId;
        NavMeshEdgeData Edge;
        unsigned int m_uiReferenceIndex;
        unsigned int m_uiListIndex;
        unsigned int m_uiTrailingValue;
    };

    PathingRequest* pRequest;
    PathingSolution* m_pOutputSolution;
    NiPoint3 m_kPathStartPosition;
    NiPoint3 m_kGoalPosition;
    bool m_bUnderwaterPath;
    const BSSimpleArray<NavMeshTriangleReference, 1024>* Triangles;
    const BSSimpleArray<NavMeshTriangleEdgeReference, 1024>* Edges;
    BSSimpleArray<PathSmootherPOVPoint*, 1024> m_kPrimaryPathPoints;
    BSSimpleArray<PathSmootherPOVPoint*, 1024> m_kSecondaryPathPoints;
    BSSimpleArray<PathSmootherPOVPoint*, 1024> m_kRequestPathPoints;
    BSSimpleArray<PathSmootherPOVPoint*, 1024> m_kPathPoints;
    PathSmootherPOVPoint* m_pStartPoint;
    PathSmootherPOVPoint* m_pGoalPoint;
    BSSimpleArray<PathSmootherPOVAvoidanceNode, 1024> Nodes;
    BSSimpleArray<NavMeshEdgeSegment, 1024> Links;
    BSSimpleArray<NavMeshEdgeRecord, 1024> m_kPrimaryEdgeRecords;
    BSSimpleArray<NavMeshEdgeRecord, 1024> m_kSecondaryEdgeRecords;
    BSSimpleArray<const NavMeshInfo*, 1024>* m_pNavMeshInfos;

    bool FindPath(const NavMeshEdgePoint&, const NiPoint3&, NavMeshEdgePoint&, float&);
    bool SearchForPath(PathingRequest*, const BSSimpleArray<NavMeshTriangleReference, 1024>&,
                       const BSSimpleArray<NavMeshTriangleEdgeReference, 1024>&,
                       const NiPoint3&, const NiPoint3&, PathingSolution*,
                       BSSimpleArray<NavMeshTriangleEdgeReference, 1024>*,
                       BSSimpleArray<const NavMeshInfo*, 1024>*);
    void AddAvoidanceNodes();
    void InsertNode(unsigned int, const PathSmootherPOVAvoidanceNode&, float);
    bool FUN_006b3380(BSSimpleArray<PathSmootherPOVAvoidanceNode, 1024>*,
                      BSSimpleArray<NavMeshEdgeSegment, 1024>*, bool);
    void BuildPOVLinks();
    bool TryAddLastNode();
    void InsertPOVPoint(BSSimpleArray<NavMeshEdgeRecord, 1024>*, unsigned int, bool);
    void BuildFallbackPath();
    bool FUN_006b2fc0(BSSimpleArray<NavMeshTriangleEdgeReference, 1024>*);
    void CollectUniqueNavMeshes();
    void BuildSmoothedPath();
    void AddPathPoints(bool);
    void AddNavMeshEdgeRecord(NavMesh*, unsigned short, const NiPoint3&, const NiPoint3&);
    NiPoint3 RotatePoint90(const SineCosine&, ANGLE_DIRECTION);
    bool FindPathToPoint(const POVNode*, PathSmootherPOVPoint*, BSSimpleArray<POVNode*, 1024>*);
    bool CalculatePathCost(PathSmootherPOVPoint*, PathSmootherPOVPoint*,
                           const NiPoint3&, const NiPoint3&, float*);
    bool FUN_006b1e50(const NavMeshEdgePoint&, Sphere&, CircularArc, NavMeshEdgePoint*);
    bool FUN_006b23d0(const NavMeshEdgePoint&, Sphere&, CircularArc);
    bool FUN_006b25f0(const NavMeshEdgePoint&, const NiPoint3&, NavMeshEdgePoint*, bool, bool, float&);
    unsigned int FUN_0069f900(PathSmootherPOVPoint*, ANGLE_DIRECTION);
    int InsertOrUpdateNode(unsigned int, float, POVNode*&);
    void SetPOVSearchNode(POVNode*, PathSmootherPOVPoint*, ANGLE_DIRECTION);
};
