#include "../../../include/PathingGraphNode.h"
#include "../../../include/NavMeshTriangle.h"
// fallout_shared/pathfinding/pathsmootherpov.cpp: PathSmootherPOVSearch and pathfinding helpers (63 functions)

#include "../../../include/BSSimpleArray.h"
#include "../../../include/NavMeshEdgeData.h"

#include "../../../include/NavMeshEdgeVertexPair.h"
#include "../../../include/NavMeshTriangleEdgeReference.h"
#include "../../../include/NavMeshTriangleReference.h"
#include "../../../include/PathSmootherPOVAvoidanceNode.h"
#include "../../../include/NavMesh.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiBound.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NavMeshPOVSearch.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/TES.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/AStarSearch.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NavMeshClosedDoorInfo.h"
#include "../../../include/NavMeshEdgePoint.h"
#include "../../../include/PathSmootherPOVSearch.h"

// Shared NavMeshEdgePoint lacks the out-of-line copy constructor at 0x006a0e50.

// Shared PathSmootherPOVSearch lacks the operations declared below.
class Key6AE;
class PathSmootherPOVNode;
class PathSmootherPOVLink;
class PathSmootherPOVPoint;
class NavMeshEdgeSegment;
class NavMeshInfo;
class SineCosine;
class Sphere;
class CircularArc;

template <class N, class L> class AStarNode;
typedef AStarNode<PathSmootherPOVAvoidanceNode, NavMeshEdgeSegment> POVNode;



// Scalar, pointer-aligned backing avoids treating shared padding arrays as GS buffers.
template <unsigned int Size> struct ScalarStackStorage
{
    void* head;
    ScalarStackStorage<Size - sizeof(void*)> tail;
};
template <> struct ScalarStackStorage<sizeof(void*)>
{
    void* head;
};

namespace std {
float abs(float);
}
float sqrt_004019b0(float);
void BSClamp_float(float&, float, float);

class AvoidSphere
{
  public:
    const NiPoint3& FUN_006815c0();
    float GetRadius() const;
};
extern TES* g_TES;
class SineCosine
{
  public:
    float fCos, fSin;
    SineCosine(float);
    SineCosine& operator=(const SineCosine&);
    SineCosine operator-(const SineCosine&) const;
    NiPoint3 MakePointOnCircle(float) const;
    float AngleSinCos_GetAngle() const;
};
class CircularArc
{
  public:
    SineCosine Start, End;
    ANGLE_DIRECTION Direction;
    CircularArc(const SineCosine&, const SineCosine&, ANGLE_DIRECTION);
    CircularArc(const CircularArc&);
    float FUN_006a07a0(float) const;
    bool AngleSinCosArc_WithinRange(const SineCosine&) const;
};
class Sphere
{
  public:
    NiPoint3 Center;
    float Radius;
    Sphere(const NiPoint3&, float);
};
class SphereTangent
{
  public:
    ANGLE_DIRECTION Direction;
    SineCosine m_kStartAngle, m_kEnd;
};
class SphereTangents
{
  public:
    int Count;
    SphereTangent Tangents[2];
    SphereTangents();
};
class PathSmootherPOVPoint
{
  public:
    PathSmootherPOVPoint();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int eType;
    NiPoint3 Center;
    float fRadius;
    NavMeshEdgeData MeshEdgeRecord;
    NiPoint3 m_kFirstEdge, m_kSecondEdge;
    float m_fWeight;
    unsigned int m_uiListIndex, m_uiReferenceIndex, m_uiCompositeId;
    unsigned short m_usResult;
};
class NavMeshEdgeSegment
{
  public:
    SineCosine m_kStartAngle, m_kEnd;
    NavMeshEdgePoint m_kStartPoint, m_kEndPoint;
    NavMeshEdgeSegment& operator=(const NavMeshEdgeSegment&);
};
template <class N, class L> class AStarNode
{
  public:
    unsigned int m_uiSoundID;
    float m_fPathingCostCur;
    N Node;
    L Link;
    const N& FUN_00413f40() const;
    const L& FUN_007d6bb0() const;
    AStarNode* GetField54() const;
    float AStarSearch_EvaluateValue_006a7f50() const;
};
class NavMeshInfo;

float GetDirectionAngle(const NiPoint3&);
float cos(float);
float sin_004e44b0(float);
void WrapValueToRange(float&, float, float);

extern const NiPoint3 DAT_011a9484;
bool Pathing_FindClosestOpenEdge(const PathingLocation&, float, NavMeshEdgePoint&);
NiPoint3 NiPoint3_UpdateState_006ba550(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);
bool NavMeshMath_Find2DIntersection_2(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, NiPoint3&);
class Segment
{
  public:
    NiPoint3 start, end;
    Segment(const NiPoint3&, const NiPoint3&);
};
class SphereIntersection
{
  public:
    unsigned int type;
    NiPoint3 p1;
    float t1;
    NiPoint3 p2;
    float t2;
    SphereIntersection();
};
bool NavMeshMath_DoCircleAndSegmentIntersect(const NiPoint3&, float, const NiPoint3&, const NiPoint3&);
void IntersectLineCircle(const Sphere&, const Segment&, SphereIntersection&);
float DistanceToSegment(const NiPoint3&, const NiPoint3&, const NiPoint3&, float*);
extern SettingT_GameSettingCollection_ DAT_011d7084;
bool Actor_AreReferencedValuesEqual(NavMesh* const&, NavMesh* const&);

// @fnv 0x006afcc0
void PathSmootherPOVSearch::AddPathPoints(bool addGoal)
{
    for (unsigned int i = 0; i < Links.GetSize(); ++i)
    {
        NiPoint3 delta = reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kEndPoint.fc) -
                         reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kStartPoint.fc);
        float segmentLength = delta.FUN_00457990();
        bool bAdd = true;
        if (i > 0)
        {
            SineCosine difference =
                Links.GetBufferElementAddress(i).m_kStartAngle - Links.GetBufferElementAddress(i - 1).m_kEnd;
            CircularArc halfCircle(SineCosine(-1.5707963705062866f), SineCosine(1.5707963705062866f), ANGLE_DIRECTION_AD_CCW);
            if (difference.AngleSinCos_GetAngle() * Nodes.Object_GetIndexedValue_006a1440(i).m_pAvoidNode->fRadius < 50.0 &&
                halfCircle.AngleSinCosArc_WithinRange(difference))
                bAdd = false;
            if (m_bUnderwaterPath)
            {
                float water = g_TES->UpdateTESState(
                    reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kStartPoint.fc),
                    reinterpret_cast<NavMesh*&>(Links.GetBufferElementAddress(i).m_kStartPoint.f0)->GetCurrentMoveModeType());
                if (water >= reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kStartPoint.fc).z)
                    reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kStartPoint.fc).z = water;
            }
        }
        if (bAdd)
        {
            PathingLocation Location(reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kStartPoint.fc),
                                     reinterpret_cast<NavMesh*&>(Links.GetBufferElementAddress(i).m_kStartPoint.f0)->GetNavMeshInfo_0068efb0());
            NiPoint3 Dir =
                RotatePoint90(Links.GetBufferElementAddress(i).m_kStartAngle, Nodes.Object_GetIndexedValue_006a1440(i).Direction);
            if (i > 0)
            {
                SineCosine difference =
                    Links.GetBufferElementAddress(i).m_kStartAngle - Links.GetBufferElementAddress(i - 1).m_kEnd;
                float arcLength = std::abs(difference.AngleSinCos_GetAngle() * Nodes.Object_GetIndexedValue_006a1440(i).m_pAvoidNode->fRadius);
                Dir *= arcLength;
            }
            else
                Dir *= Nodes.Object_GetIndexedValue_006a1440(i).m_pAvoidNode->fRadius;
            Dir *= 3.0f;
            if (Dir.FUN_004a7290() > segmentLength * segmentLength)
            {
                Dir.ComputeMagnitude();
                Dir *= segmentLength;
            }
            m_pOutputSolution->ReserveIndex(Location, Dir);
        }
        if (m_bUnderwaterPath && (i < Links.GetSize() - 1 || m_pOutputSolution->IsIncomplete() || addGoal))
        {
            float water = g_TES->UpdateTESState(
                reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kEndPoint.fc),
                reinterpret_cast<NavMesh*&>(Links.GetBufferElementAddress(i).m_kEndPoint.f0)->GetCurrentMoveModeType());
            if (water >= reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kEndPoint.fc).z)
                reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kEndPoint.fc).z = water;
        }
        PathingLocation Location(reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kEndPoint.fc),
                                 reinterpret_cast<NavMesh*&>(Links.GetBufferElementAddress(i).m_kEndPoint.f0)->GetNavMeshInfo_0068efb0());
        NiPoint3 Dir = RotatePoint90(Links.GetBufferElementAddress(i).m_kEnd, Nodes.Object_GetIndexedValue_006a1440(i + 1).Direction);
        AddNavMeshEdgeRecord(reinterpret_cast<NavMesh*&>(Links.GetBufferElementAddress(i).m_kStartPoint.f0),
                             reinterpret_cast<unsigned short&>(Links.GetBufferElementAddress(i).m_kStartPoint.f4),
                             reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kStartPoint.fc),
                             reinterpret_cast<NiPoint3&>(Links.GetBufferElementAddress(i).m_kEndPoint.fc));
        if (i < Links.GetSize() - 1)
        {
            SineCosine difference =
                Links.GetBufferElementAddress(i + 1).m_kStartAngle - Links.GetBufferElementAddress(i).m_kEnd;
            float arcLength = std::abs(difference.AngleSinCos_GetAngle() * Nodes.Object_GetIndexedValue_006a1440(i + 1).m_pAvoidNode->fRadius);
            Dir *= arcLength;
        }
        else
            Dir *= Nodes.Object_GetIndexedValue_006a1440(i + 1).m_pAvoidNode->fRadius;
        Dir *= 3.0f;
        if (Dir.FUN_004a7290() > segmentLength * segmentLength)
        {
            Dir.ComputeMagnitude();
            Dir *= segmentLength;
        }
        m_pOutputSolution->ReserveIndex(Location, Dir);
    }
    if (pRequest->TESCombatStyle_GetPowerAttackF() && !Links.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        NiPoint3 Dir = m_pOutputSolution->PathingSolution_GetLastNode()->FUN_005d8a70();
        float fStartAngle = GetDirectionAngle(Dir);
        float goalAngle = pRequest->BGSProjectile_GetMuzzleFlashDuration();
        float difference = goalAngle - fStartAngle;
        WrapValueToRange(difference, -3.1415927410125732f, 3.1415927410125732f);
        if (std::abs(difference) < 1.5707963267948966)
        {
            float segmentLength = Dir.NiPoint3_XYLength();
            NiPoint3 NewTangent;
            NewTangent.x = cos(goalAngle) * segmentLength;
            NewTangent.y = sin_004e44b0(goalAngle) * segmentLength;
            NewTangent.z = 0.0f;
            m_pOutputSolution->PathingSolution_GetLastNode()->FORenderedMenu_SetScreenLightColor(NewTangent);
        }
    }
}

// @fnv 0x006af500
void PathSmootherPOVSearch::BuildSmoothedPath()
{
    NavMeshEdgePoint startEdge;
    PathingLocation StartLoc(m_kPathStartPosition, Triangles->GetFirstElement().m_pLocationNavMesh->GetNavMeshInfo_0068efb0(),
                             Triangles->GetFirstElement().m_usTriangleIdentifier);
    if (Pathing_FindClosestOpenEdge(StartLoc, pRequest->GetFloatAtOffset68(), startEdge))
    {
        NiPoint3 Diff = m_kPathStartPosition - reinterpret_cast<NiPoint3&>(startEdge.fc);
        NiPoint3 Perp = DAT_011a9484.CrossProduct(Diff);
        PathSmootherPOVPoint* pLeftPOV = new PathSmootherPOVPoint;
        pLeftPOV->eType = 4;
        pLeftPOV->m_kFirstEdge = NiPoint3::ZERO;
        pLeftPOV->m_kSecondEdge = NiPoint3::ZERO;
        pLeftPOV->Center = m_kPathStartPosition + Perp * pRequest->GetFloatAtOffset68() * 1.01f;
        pLeftPOV->m_fWeight = 1.0f;
        pLeftPOV->fRadius = pRequest->GetFloatAtOffset68();
        pLeftPOV->m_uiReferenceIndex = 0xffffffff;
        m_kPathPoints.Add(pLeftPOV);
        m_kRequestPathPoints.Add(pLeftPOV);
        PathSmootherPOVPoint* pPOV2 = new PathSmootherPOVPoint;
        pPOV2->eType = 4;
        pPOV2->m_kFirstEdge = NiPoint3::ZERO;
        pPOV2->m_kSecondEdge = NiPoint3::ZERO;
        pPOV2->Center = m_kPathStartPosition - Perp * pRequest->GetFloatAtOffset68() * 1.01f;
        pPOV2->m_fWeight = 1.0f;
        pPOV2->fRadius = pRequest->GetFloatAtOffset68();
        pPOV2->m_uiReferenceIndex = 0xffffffff;
        m_kPathPoints.Add(pPOV2);
        m_kRequestPathPoints.Add(pPOV2);
    }
    NavMeshEdgePoint GoalEdgeLoc;
    PathingLocation GoalPathLocation(m_kGoalPosition, Triangles->GetLastElement().m_pLocationNavMesh->GetNavMeshInfo_0068efb0(),
                                     Triangles->GetLastElement().m_usTriangleIdentifier);
    if (Pathing_FindClosestOpenEdge(GoalPathLocation, pRequest->GetFloatAtOffset68(), GoalEdgeLoc))
    {
        NiPoint3 Diff = m_kGoalPosition - reinterpret_cast<NiPoint3&>(GoalEdgeLoc.fc);
        NiPoint3 Perp = DAT_011a9484.CrossProduct(Diff);
        PathSmootherPOVPoint* pLeftPOV = new PathSmootherPOVPoint;
        pLeftPOV->eType = 4;
        pLeftPOV->m_kFirstEdge = NiPoint3::ZERO;
        pLeftPOV->m_kSecondEdge = NiPoint3::ZERO;
        pLeftPOV->Center = m_kGoalPosition + Perp * pRequest->GetFloatAtOffset68() * 1.01f;
        pLeftPOV->m_fWeight = 1.0f;
        pLeftPOV->fRadius = pRequest->GetFloatAtOffset68();
        pLeftPOV->m_uiReferenceIndex = 0xffffffff;
        m_kPathPoints.Add(pLeftPOV);
        m_kRequestPathPoints.Add(pLeftPOV);
        PathSmootherPOVPoint* pPOV2 = new PathSmootherPOVPoint;
        pPOV2->eType = 4;
        pPOV2->m_kFirstEdge = NiPoint3::ZERO;
        pPOV2->m_kSecondEdge = NiPoint3::ZERO;
        pPOV2->Center = m_kGoalPosition - Perp * pRequest->GetFloatAtOffset68() * 1.01f;
        pPOV2->m_fWeight = 1.0f;
        pPOV2->fRadius = pRequest->GetFloatAtOffset68();
        pPOV2->m_uiReferenceIndex = 0xffffffff;
        m_kPathPoints.Add(pPOV2);
        m_kRequestPathPoints.Add(pPOV2);
    }
}

#define link (*reinterpret_cast<NavMeshTriangleEdgeReference*>(&linkStorage))
// @fnv 0x006ad770
bool PathSmootherPOVSearch::SearchForPath(PathingRequest* request,
                                          const BSSimpleArray<NavMeshTriangleReference>& triangles,
                                          const BSSimpleArray<NavMeshTriangleEdgeReference>& edges,
                                          const NiPoint3& start, const NiPoint3& goal, PathingSolution* solution,
                                          BSSimpleArray<NavMeshTriangleEdgeReference>* extraEdges,
                                          BSSimpleArray<const NavMeshInfo*>* infos)
{
    pRequest = request;
    m_kPathStartPosition = start;
    m_kGoalPosition = goal;
    Triangles = &triangles;
    Edges = &edges;
    m_pOutputSolution = solution;
    m_pNavMeshInfos = infos;
    bool startUnderWater =
        triangles.GetFirstElement().m_pLocationNavMesh->GetCurrentMoveModeType()
            ? triangles.GetFirstElement().FastNavMeshTriLocation_GetLocation().z <
                  g_TES->UpdateTESState(start,
                                        triangles.GetFirstElement().m_pLocationNavMesh->GetCurrentMoveModeType()) +
                      50.0f
            : true;
    if (!startUnderWater)
    {
        float z = m_kPathStartPosition.z;
        triangles.GetFirstElement().m_pLocationNavMesh->GetTriangleHeightAtPoint(
            triangles.GetFirstElement().m_usTriangleIdentifier, m_kPathStartPosition, 180.0f, 64.0f, z);
        m_kPathStartPosition.z = z;
    }
    bool bGoalUnderWater = false;
    if (!request->NiAVObject_GetRotate_006a9540()->PathingLocation_QUnused() &&
        triangles.GetLastElement().m_pLocationNavMesh->GetCurrentMoveModeType() &&
        triangles.GetLastElement().FastNavMeshTriLocation_GetLocation().z <
            g_TES->UpdateTESState(goal, triangles.GetLastElement().m_pLocationNavMesh->GetCurrentMoveModeType()) +
                50.0f)
        bGoalUnderWater = true;
    if (!bGoalUnderWater)
    {
        float z = m_kGoalPosition.z;
        triangles.GetLastElement().m_pLocationNavMesh->GetTriangleHeightAtPoint(
            triangles.GetLastElement().m_usTriangleIdentifier, m_kGoalPosition, 180.0f, 64.0f, z);
        m_kGoalPosition.z = z;
    }
    if (startUnderWater && bGoalUnderWater)
        m_bUnderwaterPath = true;
    m_kPrimaryPathPoints.GrowCapacity(const_cast<BSSimpleArray<NavMeshTriangleEdgeReference>&>(edges).GetSize());
    m_kSecondaryPathPoints.GrowCapacity(const_cast<BSSimpleArray<NavMeshTriangleEdgeReference>&>(edges).GetSize());
    m_kPrimaryEdgeRecords.GrowCapacity(const_cast<BSSimpleArray<NavMeshTriangleEdgeReference>&>(edges).GetSize());
    m_kSecondaryEdgeRecords.GrowCapacity(const_cast<BSSimpleArray<NavMeshTriangleEdgeReference>&>(edges).GetSize());
    m_kRequestPathPoints.GrowCapacity(pRequest->GetString() ? pRequest->GetString()->GetSize() * 2 : 0);
    m_kPathPoints.GrowCapacity(const_cast<BSSimpleArray<NavMeshTriangleEdgeReference>&>(edges).GetSize() * 2 + m_kRequestPathPoints.GetHavokWorldObjectCountInSceneGraph_0084e3a0() + 2);
    AddAvoidanceNodes();
    PathSmootherPOVAvoidanceNode m_kStartingTriangle;
    m_kStartingTriangle.m_pAvoidNode = m_pStartPoint;
    m_kStartingTriangle.Direction = ANGLE_DIRECTION_AD_CCW;
    InsertNode(GetKeyForNode(m_pStartPoint, ANGLE_DIRECTION_AD_CCW), m_kStartingTriangle,
               (m_kGoalPosition - m_kPathStartPosition).FUN_00457990() * 0.75f);
    Nodes.Clear(false);
    Links.Clear(false);
    bool success = AStarSearch_PathSmootherPOVNode_PathSmootherPOVLink_Search(&Nodes, &Links, true);
    if (!success)
    {
        BuildFallbackPath();
        if (extraEdges)
        {
            AddIntersectingPOVsAsBadNodes(extraEdges);
            if (Nodes.GetLastEdge().m_pAvoidNode->eType == 0 || Nodes.GetLastEdge().m_pAvoidNode->eType == 1)
            {
                ScalarStackStorage<sizeof(NavMeshEdgeData)> EdgeStorage;
                reinterpret_cast<NavMeshEdgeData*>(&EdgeStorage)->NavMeshEdgeData::NavMeshEdgeData(
                    Nodes.GetLastEdge().m_pAvoidNode->MeshEdgeRecord);
                ScalarStackStorage<sizeof(NavMeshTriangleEdgeReference)> linkStorage;
                link.m_pLocationNavMesh = (*reinterpret_cast<NavMeshEdgeData*>(&EdgeStorage)).m_pLocationNavMesh;
                link.m_usTriangleIdentifier = (*reinterpret_cast<NavMeshEdgeData*>(&EdgeStorage)).m_usTriangleID;
                link.m_iEdgeIndex = (*reinterpret_cast<NavMeshEdgeData*>(&EdgeStorage)).m_iEdgeIndex;
                extraEdges->Add(link);
            }
        }
    }
    AddPathPoints(!success);
    for (unsigned int i = 0; i < const_cast<BSSimpleArray<NavMeshTriangleReference>&>(triangles).GetSize(); ++i)
    {
        if (triangles.GetIndexedValue_006b3160(i).NavMeshSearchNode_GetTriangle()->FUN_00691140(0x1000))
        {
            void* door = (void*)triangles.GetIndexedValue_006b3160(i)
                             .m_pLocationNavMesh->GetClosedDoorInfo(triangles.GetIndexedValue_006b3160(i).m_usTriangleIdentifier)
                             ->m_uiDoorFormID;
            reinterpret_cast<BSSimpleArray<void*>*>(&m_pOutputSolution->unk30)->Add(door);
        }
    }
    for (unsigned int i = 0; i < m_kPathPoints.GetSize(); ++i)
        delete m_kPathPoints[i];
    return success;
}

#undef link

// @fnv 0x006b0ad0
bool PathSmootherPOVSearch::CollectConnections(const POVNode* node, BSSimpleArray<POVNode*>* connections)
{
    const PathSmootherPOVAvoidanceNode& Node = node->FUN_00413f40();
    const int iMaxFailureCount = 4;
    unsigned int size = 0xffffffff;
    unsigned int failures = 0;
    FindPathToPoint(node, m_pGoalPoint, connections);
    if (Node.m_pAvoidNode->eType == 0)
    {
        size = m_kPrimaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = Node.m_pAvoidNode->m_uiListIndex + 1; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kPrimaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
        size = m_kSecondaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = Node.m_pAvoidNode->m_uiReferenceIndex; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kSecondaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
    }
    else if (Node.m_pAvoidNode->eType == 1)
    {
        size = m_kSecondaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = Node.m_pAvoidNode->m_uiListIndex + 1; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kSecondaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
        size = m_kPrimaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = Node.m_pAvoidNode->m_uiReferenceIndex; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kPrimaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
    }
    else if (Node.m_pAvoidNode->eType == 2)
    {
        size = m_kSecondaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = 0; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kSecondaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
        size = m_kPrimaryPathPoints.GetSize();
        failures = 0;
        for (unsigned int i = 0; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kPrimaryPathPoints[i];
            if (!FindPathToPoint(node, pov, connections))
            {
                ++failures;
                if (failures == iMaxFailureCount)
                    break;
            }
        }
    }
    else
    {
        size = m_kSecondaryPathPoints.GetSize();
        for (unsigned int i = 0; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kSecondaryPathPoints[i];
            FindPathToPoint(node, pov, connections);
        }
        size = m_kPrimaryPathPoints.GetSize();
        for (unsigned int i = 0; i < size; ++i)
        {
            PathSmootherPOVPoint* pov = m_kPrimaryPathPoints[i];
            FindPathToPoint(node, pov, connections);
        }
    }
    size = m_kRequestPathPoints.GetSize();
    for (unsigned int i = 0; i < size; ++i)
    {
        PathSmootherPOVPoint* pov = m_kRequestPathPoints[i];
        FindPathToPoint(node, pov, connections);
    }
    return true;
}

// Walks up to 1000 triangles from a start point toward an end point, smoothing the path across edges and adding pathing locations at crossings.
#define currentEdge (*reinterpret_cast<NavMeshEdgeData*>(&currentEdgeStorage))
#define exit (*reinterpret_cast<NavMeshEdgeData*>(&exitStorage))
#define entry (*reinterpret_cast<NavMeshEdgeData*>(&entryStorage))
// @fnv 0x006b05f0
void PathSmootherPOVSearch::AddNavMeshEdgeRecord(NavMesh* mesh, unsigned short triangle, const NiPoint3& from,
                                                 const NiPoint3& to)
{
    NiPoint3 start = from;
    NiPoint3 end = to;
    NiPoint3 pathDirection = end - start;
    pathDirection.ComputeMagnitude();
    NiPoint3 CurrentLoc = start;
    ScalarStackStorage<sizeof(NavMeshEdgeData)> currentEdgeStorage;
    reinterpret_cast<NavMeshEdgeData*>(&currentEdgeStorage)->NavMeshEdgeData::NavMeshEdgeData(mesh, triangle, -1);
    int iterations = 0;
    while (iterations < 1000)
    {
        ++iterations;
        int index = currentEdge.m_pLocationNavMesh->FindCrossedEdge(currentEdge.m_usTriangleID,
                                                                    currentEdge.m_iEdgeIndex, CurrentLoc, end);
        if (index == -1)
        {
            break;
        }
        else
        {
            ScalarStackStorage<sizeof(NavMeshEdgeData)> exitStorage;
            reinterpret_cast<NavMeshEdgeData*>(&exitStorage)->NavMeshEdgeData::NavMeshEdgeData(currentEdge.m_pLocationNavMesh, currentEdge.m_usTriangleID, index);
            ScalarStackStorage<sizeof(NavMeshEdgeData)> entryStorage;
            reinterpret_cast<NavMeshEdgeData*>(&entryStorage)->NavMeshEdgeData::NavMeshEdgeData();
            bool connected = exit.m_pLocationNavMesh->MatchNavMesh(exit, entry);
            if (connected)
            {
                if (currentEdge.m_pLocationNavMesh != entry.m_pLocationNavMesh)
                {
                    NavMeshEdgeVertexPair vertices =
                        entry.m_pLocationNavMesh->NavMesh_GetEdgeVertices_0(entry.m_usTriangleID, entry.m_iEdgeIndex);
                    NiPoint3 center = (*vertices.p1 + *vertices.p2) * 0.5f;
                    CurrentLoc = NiPoint3_UpdateState_006ba550(*vertices.p1, *vertices.p2, start, end);
                    CurrentLoc += (center - CurrentLoc) * 0.01f;
                }
                NiPoint3 exitNormal = exit.m_pLocationNavMesh->FUN_006971e0(exit.m_usTriangleID);
                NiPoint3 entryNormal = entry.m_pLocationNavMesh->FUN_006971e0(entry.m_usTriangleID);
                if (exitNormal.Dot(entryNormal) < 0.9f)
                {
                    NiPoint3 p1, p2;
                    exit.m_pLocationNavMesh->GetEdgeVertices_0068f0c0(exit.m_usTriangleID, exit.m_iEdgeIndex, p1, p2);
                    NiPoint3 Crossing;
                    if (NavMeshMath_Find2DIntersection_2(p1, p2, start, end, Crossing))
                    {
                        if ((Crossing - start).FUN_004a7290() > 1024.0f && (Crossing - end).FUN_004a7290() > 1024.0f &&
                            m_pOutputSolution->PathingSolution_GetLastNode() &&
                            (Crossing - m_pOutputSolution->PathingSolution_GetLastNode()->FUN_00717e50().FUN_005c3420())
                                    .FUN_004a7290() > 1024.0f)
                        {
                            if (m_bUnderwaterPath)
                            {
                                float water = g_TES->UpdateTESState(
                                    Crossing, reinterpret_cast<unsigned int>(m_pOutputSolution->PathingSolution_GetLastNode()->FUN_00717e50().FUN_006dd4f0()));
                                if (water >= Crossing.z)
                                    Crossing.z = water;
                            }
                            PathingLocation location(Crossing, exit.m_pLocationNavMesh->GetNavMeshInfo_0068efb0(),
                                                     exit.m_usTriangleID);
                            NiPoint3 Dir = pathDirection * pRequest->GetFloatAtOffset68();
                            m_pOutputSolution->ReserveIndex(location, Dir);
                        }
                    }
                }
                currentEdge = entry;
            }
            else
                break;
        }
    }
}

#undef currentEdge
#undef exit
#undef entry

// @fnv 0x006b2c00
bool PathSmootherPOVSearch::CalculatePathCost(PathSmootherPOVPoint* from, PathSmootherPOVPoint* to,
                                              const NiPoint3& start, const NiPoint3& end, float* pfCost)
{
    *pfCost = (end - start).FUN_00457990();
    if ((end - start).GetSquaredXYLength() < 0.001f)
        return true;
    for (unsigned int i = 0; i < m_kRequestPathPoints.GetSize(); ++i)
    {
        PathSmootherPOVPoint* pov = m_kRequestPathPoints[i];
        if (NavMeshMath_DoCircleAndSegmentIntersect(pov->Center, pov->fRadius, start, end))
        {
            Sphere sphere(pov->Center, pov->fRadius);
            Segment kSegment(start, end);
            SphereIntersection result;
            IntersectLineCircle(sphere, kSegment, result);
            NiPoint3 entryPoint, leavePoint;
            switch (result.type)
            {
            case 0:
            case 3:
                continue;
            case 5:
                entryPoint = start;
                leavePoint = end;
                break;
            case 4:
                entryPoint = start + (end - start) * result.t1;
                leavePoint = start + (end - start) * result.t2;
                break;
            case 1:
                entryPoint = start;
                leavePoint = start + (end - start) * result.t1;
                break;
            case 2:
                entryPoint = start + (end - start) * result.t1;
                leavePoint = end;
                break;
            }
            if (pov->eType == 5 && pov != to)
            {
                if (pRequest->GetByteAtOffset9B() && from->eType != 2)
                    return false;
                else
                    *pfCost *= 10.0f;
            }
            float segmentLength = (leavePoint - entryPoint).FUN_00457990();
            float fDist = DistanceToSegment(pov->Center, entryPoint, leavePoint, 0);
            float costFraction = (pov->fRadius - fDist) / pov->fRadius;
            if (costFraction < 0.0f)
                costFraction = 0.0f;
            *pfCost += (1.0f + costFraction * DAT_011d7084.Float()->f) * segmentLength;
        }
    }
    return true;
}

// Collects unique NavMesh pointers from Triangles, then for each mesh and triangle creates a POV object with center, radius and index and adds it to two arrays.
// @fnv 0x006af2b0
void PathSmootherPOVSearch::CollectUniqueNavMeshes()
{
    BSSimpleArray<NavMesh*> uniqueMeshes;
    for (unsigned int i = 0; i < const_cast<BSSimpleArray<NavMeshTriangleReference>*>(Triangles)->GetSize(); ++i)
    {
        if (uniqueMeshes.Find(Triangles->BSSimpleArray_CombatMember_1024_GetAt(i).m_pLocationNavMesh, 0, Actor_AreReferencedValuesEqual) == 0xffffffff)
            uniqueMeshes.Add(Triangles->BSSimpleArray_CombatMember_1024_GetAt(i).m_pLocationNavMesh);
    }
    for (unsigned int i = 0; i < uniqueMeshes.GetSize(); ++i)
    {
        NavMesh* mesh = uniqueMeshes[i];
        for (unsigned int j = 0; j < mesh->GetAvoidNodeCount(); ++j)
        {
            PathSmootherPOVPoint* pov = new PathSmootherPOVPoint;
            pov->eType = 4;
            pov->m_kFirstEdge = NiPoint3::ZERO;
            pov->m_kSecondEdge = NiPoint3::ZERO;
            pov->Center = mesh->NavMesh_GetAvoidNode(j).FUN_006815c0();
            pov->m_fWeight = 1.0f;
            pov->fRadius = mesh->NavMesh_GetAvoidNode(j).GetRadius() + pRequest->GetFloatAtOffset68() * 1.2f;
            pov->m_uiReferenceIndex = 0xffffffff;
            pov->m_uiCompositeId = i * 1000 + j;
            m_kPathPoints.Add(pov);
            m_kRequestPathPoints.Add(pov);
        }
    }
}

// Destructor for PathSmootherPOVSearch; the empty body performs no cleanup.
// @fnv 0x006ad690
PathSmootherPOVSearch::~PathSmootherPOVSearch()
{}

// Returns true when the node's FUN_00413f40 result has an eType field equal to 3.
// @fnv 0x006b1dc0
bool PathSmootherPOVSearch::HasReachedGoal(const POVNode* node)
{
    return node->FUN_00413f40().m_pAvoidNode->eType == 3;
}

// MSVC9 allocates these locals by identifier as well as scope.
// Semantic aliases preserve the verified stack layout while keeping the body readable.
#define currentNode iNumTangents
#define incomingLink pCurrentLink
#define centerDelta Tangents
#define xyDistanceSquared iTested
#define heightSquared fZDistSqr
#define startSphere Diff
#define endSphere Node
#define tangentData fXYDistSqr
#define tangentCount EndSphere
#define testedCount StartSphere
#define direction Dir
#define leftDirection Left
#define sourceArc EntryLoc
#define sourceLocation Arc
#define exitLocation ExitLoc
#define entryLocation ProjectedLoc
#define destination height
#define projectedPoint EndLoc
#define heightDelta StartLoc
#define discount fDiscount
#define cost m_fPathingCostCur
#define nextNode pListNode
#define radialDistance Right
#define rightDirection fScaleMultiplier
#define tangentLength Perp
#define perpendicular fTangentLength

// @fnv 0x006b0f40
bool PathSmootherPOVSearch::FindPathToPoint(const POVNode* node, PathSmootherPOVPoint* pov,
                                            BSSimpleArray<POVNode*>* connections)
{
    int failedCount;
    const NavMeshEdgeSegment* incomingLink;
    {
        const PathSmootherPOVAvoidanceNode& currentNode = node->FUN_00413f40();
        incomingLink = &node->FUN_007d6bb0();
        if (pov == currentNode.m_pAvoidNode)
            return true;
        if (node->GetField54() && pov == node->GetField54()->FUN_00413f40().m_pAvoidNode)
            return true;
        NiPoint3 centerDelta = pov->Center - currentNode.m_pAvoidNode->Center;
        float xyDistanceSquared = centerDelta.GetSquaredXYLength();
        float heightSquared = centerDelta.z * centerDelta.z;
        if (!m_bUnderwaterPath && xyDistanceSquared * 1.2000000476837158 * 1.2000000476837158 < heightSquared)
            return true;
        Sphere startSphere(currentNode.m_pAvoidNode->Center, currentNode.m_pAvoidNode->fRadius);
        Sphere endSphere(pov->Center, pov->fRadius);
        SphereTangents tangentData;
        int tangentCount =
            NavMeshPOVSearch::FindSphereTangents(startSphere, endSphere, currentNode.Direction, tangentData);
        if (!node->GetField54())
        {
            NiPoint3 direction = currentNode.m_pAvoidNode->Center - pov->Center;
            if (direction.FUN_004a7290() < pov->fRadius * pov->fRadius)
            {
                direction.z = 0.0f;
                float radialDistance = direction.GetLengthSquared();
                NiPoint3 leftDirection, rightDirection;
                if (pov->fRadius * 0.5 > radialDistance)
                {
                    leftDirection = direction;
                    rightDirection = direction;
                }
                else
                {
                    float tangentLength;
                    {
                        tangentLength = sqrt_004019b0(pov->fRadius * pov->fRadius - radialDistance * radialDistance);
                        NiPoint3 perpendicular(-direction.y, direction.x, 0.0f);
                        perpendicular *= tangentLength;
                        leftDirection = direction * radialDistance + perpendicular;
                        leftDirection.ComputeMagnitude();
                        rightDirection = direction * radialDistance - perpendicular;
                        rightDirection.ComputeMagnitude();
                    }
                }
                tangentData.Count = 2;
                tangentData.Tangents[0].Direction = ANGLE_DIRECTION_AD_CCW;
                tangentData.Tangents[0].m_kStartAngle.fCos = leftDirection.x;
                tangentData.Tangents[0].m_kStartAngle.fSin = leftDirection.y;
                tangentData.Tangents[0].m_kEnd.fCos = leftDirection.x;
                tangentData.Tangents[0].m_kEnd.fSin = leftDirection.y;
                tangentData.Tangents[1].Direction = ANGLE_DIRECTION_AD_CW;
                tangentData.Tangents[1].m_kStartAngle.fCos = rightDirection.x;
                tangentData.Tangents[1].m_kStartAngle.fSin = rightDirection.y;
                tangentData.Tangents[1].m_kEnd.fCos = rightDirection.x;
                tangentData.Tangents[1].m_kEnd.fSin = rightDirection.y;
                tangentCount = 2;
            }
        }
        if (!tangentCount)
            return true;
        int testedCount = 0;
        failedCount = 0;
        for (int i = 0; i < tangentCount; i++)
        {
            float fScaleMultiplier;
            {
                float discount;
                {
                    POVNode* nextNode;
                    {
                        float cost;
                        {
                            if (pov->eType == 0 && tangentData.Tangents[i].Direction == ANGLE_DIRECTION_AD_CW)
                                continue;
                            if (pov->eType == 1 && tangentData.Tangents[i].Direction == ANGLE_DIRECTION_AD_CCW)
                                continue;
                            if (node->GetField54() && (node->GetField54()->Node.m_pAvoidNode->eType == 0 ||
                                                       node->GetField54()->Node.m_pAvoidNode->eType == 1))
                            {
                                SineCosine angle = tangentData.Tangents[i].m_kStartAngle - incomingLink->m_kEnd;
                                if (currentNode.Direction == ANGLE_DIRECTION_AD_CCW)
                                {
                                    float radians = angle.AngleSinCos_GetAngle();
                                    if (radians < 0.0)
                                        radians += 6.2831854820251465;
                                    if (radians > 3.4906585216522217)
                                        continue;
                                }
                                else
                                {
                                    float radians = angle.AngleSinCos_GetAngle();
                                    if (radians > 0.0)
                                        radians -= 6.2831854820251465;
                                    if (radians < -3.4906585216522217)
                                        continue;
                                }
                            }
                            CircularArc sourceArc(incomingLink->m_kEnd, tangentData.Tangents[i].m_kStartAngle,
                                                  currentNode.Direction);
                            NavMeshEdgePoint sourceLocation;
                            if (!node->GetField54())
                            {
                                reinterpret_cast<NavMesh*&>(sourceLocation.f0) = Triangles->GetFirstElement().m_pLocationNavMesh;
                                reinterpret_cast<unsigned short&>(sourceLocation.f4) = Triangles->GetFirstElement().m_usTriangleIdentifier;
                                reinterpret_cast<int&>(sourceLocation.f8) = -1;
                                reinterpret_cast<NiPoint3&>(sourceLocation.fc) = m_kPathStartPosition;
                            }
                            else
                                sourceLocation = incomingLink->m_kEndPoint;
                            ++testedCount;
                            NavMeshEdgePoint exitLocation;
                            if (!node->GetField54())
                                exitLocation = sourceLocation;
                            else
                            {
                                reinterpret_cast<int&>(sourceLocation.f8) = -1;
                                if (!CheckArcAgainstNavMesh(sourceLocation, startSphere, sourceArc, &exitLocation))
                                {
                                    ++failedCount;
                                    continue;
                                }
                                if (std::abs((reinterpret_cast<NiPoint3&>(exitLocation.fc) - startSphere.Center).z) >= 180.0)
                                {
                                    ++failedCount;
                                    continue;
                                }
                            }
                            NavMeshEdgePoint entryLocation;
                            NiPoint3 destination =
                                endSphere.Center + tangentData.Tangents[i].m_kEnd.MakePointOnCircle(endSphere.Radius);
                            reinterpret_cast<int&>(exitLocation.f8) = -1;
                            discount = 0.0f;
                            if (!TripleCheckSegmentAgainstNavMesh(exitLocation, destination, &entryLocation,
                                              currentNode.m_pAvoidNode->eType == 2, pov->eType == 3, discount))
                            {
                                ++failedCount;
                                continue;
                            }
                            if (node->GetField54())
                            {
                                reinterpret_cast<int&>(sourceLocation.f8) = -1;
                                if (!m_bUnderwaterPath && !DoubleCheckArcAgainstNavMesh(sourceLocation, startSphere, sourceArc))
                                {
                                    ++failedCount;
                                    continue;
                                }
                            }
                            NiPoint3 projectedPoint = reinterpret_cast<NiPoint3&>(entryLocation.fc);
                            reinterpret_cast<NavMesh*&>(entryLocation.f0)->GetTriangleHeightAtPoint(
                                reinterpret_cast<unsigned short&>(entryLocation.f4), reinterpret_cast<NiPoint3&>(entryLocation.fc), 3.402823466e38f, 3.402823466e38f,
                                projectedPoint.z);
                            float heightDelta = projectedPoint.z - endSphere.Center.z;
                            if (!((reinterpret_cast<NiPoint3&>(entryLocation.fc).z <
                                       g_TES->UpdateTESState(
                                           reinterpret_cast<NiPoint3&>(entryLocation.fc),
                                           reinterpret_cast<NavMesh*&>(entryLocation.f0)->GetCurrentMoveModeType()) ||
                                   heightDelta > -64.0f) &&
                                  heightDelta < 180.0f))
                            {
                                ++failedCount;
                                continue;
                            }
                            fScaleMultiplier = 0.0f;
                            if (!m_bUnderwaterPath &&
                                !CalculatePathCost(currentNode.m_pAvoidNode, pov, reinterpret_cast<NiPoint3&>(exitLocation.fc),
                                                   reinterpret_cast<NiPoint3&>(entryLocation.fc), &fScaleMultiplier))
                                continue;
                            discount *= 0.8999999761581421;
                            BSClamp_float(discount, 0.0f, 1.0f);
                            cost = node->AStarSearch_EvaluateValue_006a7f50();
                            if (node->GetField54())
                                cost += sourceArc.FUN_006a07a0(currentNode.m_pAvoidNode->fRadius) * pov->m_fWeight *
                                        (1.0f - discount);
                            cost += fScaleMultiplier * pov->m_fWeight * (1.0f - discount);
                            switch (InsertOrUpdateNode(GetKeyForNode(pov, tangentData.Tangents[i].Direction), cost,
                                                       nextNode))
                            {
                            case 0:
                                SetPOVSearchNode(nextNode, pov, tangentData.Tangents[i].Direction);
                            case 1:
                                nextNode->Link.m_kStartPoint = exitLocation;
                                nextNode->Link.m_kEndPoint = entryLocation;
                                nextNode->Link.m_kStartAngle = tangentData.Tangents[i].m_kStartAngle;
                                nextNode->Link.m_kEnd = tangentData.Tangents[i].m_kEnd;
                                connections->Add(nextNode);
                            }
                        }
                    }
                }
            }
        }
        return testedCount == 0 || testedCount > failedCount;
    }
}

#undef currentNode
#undef incomingLink
#undef centerDelta
#undef xyDistanceSquared
#undef heightSquared
#undef startSphere
#undef endSphere
#undef tangentData
#undef tangentCount
#undef testedCount
#undef direction
#undef leftDirection
#undef sourceArc
#undef sourceLocation
#undef exitLocation
#undef entryLocation
#undef destination
#undef projectedPoint
#undef heightDelta
#undef discount
#undef cost
#undef nextNode
#undef radialDistance
#undef rightDirection
#undef tangentLength
#undef perpendicular

// @fnv 0x00505c00
// src: COMMUNITY 0x00505c00
bool PathingRequest::TESCombatStyle_GetPowerAttackF()
{
    return bFaceTargetAtGoal;
}

// @fnv 0x00507e10
// src: XBOX_PDB 0x00507e10
float PathingRequest::BGSProjectile_GetMuzzleFlashDuration()
{
    return m_fPathingRadius;
}

// @fnv 0x0069f900
// src: COMMUNITY 0x0069f900
unsigned int PathSmootherPOVSearch::GetKeyForNode(PathSmootherPOVPoint* apPOV, ANGLE_DIRECTION aDirection)
{
    return reinterpret_cast<unsigned int>(apPOV) + aDirection;
}

struct FUN_006a04b0_stand
{
    NiPoint3 center;
    float r;
    FUN_006a04b0_stand* SetCenterAndRadius(const NiPoint3* c, float radius);
};
// Copies the given NiPoint3 into center, stores radius in r, and returns this.
// @fnv 0x006a04b0
FUN_006a04b0_stand* FUN_006a04b0_stand::SetCenterAndRadius(const NiPoint3* apCenter, float radius)
{
    center = *apCenter;
    r = radius;
    return this;
}

// Initializes the object: sets index to -1, zeroes position and a float, constructs NiBound, initializes two AvoidSpheres, and sets a float to 1.0.
// @fnv 0x006ae120
// src: GUESS 0x006ae120 (confidence: medium)
void* __fastcall Object_InitializePathingFields(char* pObject)
{
    *(int*)pObject = -1;
    *(NiPoint3*)(pObject + 4) = NiPoint3::ZERO;
    *(float*)(pObject + 0x10) = 0.0f;
    ((NiBound*)(pObject + 0x14))->NiBound::NiBound();
    ((AvoidSphere*)(pObject + 0x20))->FUN_006815c0();
    ((AvoidSphere*)(pObject + 0x2c))->FUN_006815c0();
    *(float*)(pObject + 0x38) = 1.0f;
    return pObject;
}

// @fnv 0x006b05d0
// src: XBOX_PDB 0x006b05d0
bool PathingSolution::IsIncomplete()
{
    return m_bHasValidPath;
}

// @fnv 0x006b1df0
void PathSmootherPOVSearch::SetPOVSearchNode(POVNode* apNode, PathSmootherPOVPoint* apPOV, ANGLE_DIRECTION aDirection)
{
    reinterpret_cast<int*>(&reinterpret_cast<NiAVObject*>(apNode)->GetName())[0] = reinterpret_cast<int>(apPOV);
    reinterpret_cast<int*>(&reinterpret_cast<NiAVObject*>(apNode)->GetName())[1] = aDirection;

    *reinterpret_cast<float*>(reinterpret_cast<char*>(apNode) + 4) =
        (*reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(apPOV) + 4) -
         *reinterpret_cast<NiPoint3*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0x20c8) + 4))
            .FUN_00457990() *
        0.1f;
}

// @fnv 0x006b30e0
template <>
NavMeshEdgeSegment& BSSimpleArray<NavMeshEdgeSegment>::GetBufferElementAddress(unsigned int aiIndex)
{
    return pBuffer[aiIndex];
}

// @fnv 0x006b3160
template <>
// src: GUESS 0x006b3160 (confidence: low)
const NavMeshTriangleReference& BSSimpleArray<NavMeshTriangleReference>::GetIndexedValue_006b3160(unsigned int uiIndex) const
{
    return pBuffer[uiIndex];
}

// @fnv 0x006b3180
template <>
const NavMeshTriangleReference& BSSimpleArray<NavMeshTriangleReference>::GetFirstElement() const
{
    return GetIndexedValue_006b3160(0);
}

// @fnv 0x006b31a0
template <>
const NavMeshTriangleReference& BSSimpleArray<NavMeshTriangleReference>::GetLastElement() const
{
    return GetIndexedValue_006b3160(iSize - 1);
}

class Date
{
  public:
    ~Date();
};

class FUN_00982610_Type
{
  public:
    int pad[4];
    ~FUN_00982610_Type();
};

struct FUN_006b3270_Class
{
    virtual ~FUN_006b3270_Class();
    FUN_00982610_Type m_sub0;
    Date m_date1;
    char m_auiShapeKeys[0x1ff4 - 0x14 - sizeof(Date)];
    Date m_date2;
};

// Destroys the object; the body is empty, so the compiler-generated member destructors do the work.
// @fnv 0x006b3270
FUN_006b3270_Class::~FUN_006b3270_Class()
{}

// @fnv 0x006b35a0
template <>
BSSimpleArray<PathSmootherPOVPoint*>::~BSSimpleArray()
{
    Clear(true);
}

// @fnv 0x006b35f0
template <>
BSSimpleArray<PathSmootherPOVAvoidanceNode>::~BSSimpleArray()
{
    Clear(true);
}

// @fnv 0x006b3640
template <>
BSSimpleArray<NavMeshEdgeSegment>::~BSSimpleArray()
{
    Clear(true);
}

// @fnv 0x006b3710
template <>
BSSimpleArray<PathSmootherPOVSearch::NavMeshEdgeRecord>::~BSSimpleArray()
{
    Clear(true);
}

struct WaitableObject
{
    void NiRefObject_IncRefCount();
};
struct FUN_006b37b0_stand
{
    int* p;
    FUN_006b37b0_stand* SetObject(int* obj);
};
// Stores obj in p and, if non-null, calls FUN_0040f6e0 on the subobject at offset 0x10; returns this.
// @fnv 0x006b37b0
FUN_006b37b0_stand* FUN_006b37b0_stand::SetObject(int* pObject)
{
    p = pObject;
    if (p)
        ((WaitableObject*)((char*)p + 0x10))->NiRefObject_IncRefCount();
    return this;
}

namespace fnv_006b37e0 {
// If the object pointer at pThis is non-null, calls FUN_00401970 on the NiAVObject at offset 0x10 of that pointer.
// @fnv 0x006b37e0
// src: GUESS 0x006b37e0 (confidence: medium)
void __fastcall Object_ReleaseReferencedObject_006b37e0(char** pThis)
{
    if (*pThis)
    {
        ((NiAVObject*)(*pThis + 0x10))->NiRefObject_DecRefCount();
    }
}
}  // namespace fnv_006b37e0

// @fnv 0x006ced90
template <>
const PathSmootherPOVAvoidanceNode& BSSimpleArray<PathSmootherPOVAvoidanceNode>::GetLastEdge()
{
    return Object_GetIndexedValue_006a1440(iSize - 1);
}

// @fnv 0x006b3100
template <>
const NavMeshEdgeSegment& BSSimpleArray<NavMeshEdgeSegment>::GetLastEdge()
{
    return GetBufferElementAddress(iSize - 1);
}

// @fnv 0x006b3120
template <>
PathSmootherPOVSearch::NavMeshEdgeRecord&
BSSimpleArray<PathSmootherPOVSearch::NavMeshEdgeRecord>::GetBufferEntry(unsigned int aiIndex)
{
    return pBuffer[aiIndex];
}

// @fnv 0x006b3140
template <>
const PathSmootherPOVSearch::NavMeshEdgeRecord&
BSSimpleArray<PathSmootherPOVSearch::NavMeshEdgeRecord>::GetLastEdge()
{
    return GetBufferEntry(iSize - 1);
}

// @fnv 0x006b3570
template <>
BSSimpleArray<PathSmootherPOVPoint*>::BSSimpleArray()
{
    BSSimpleArray_float_1024_InitialSetup(0, false);
}

// @fnv 0x006b3780
template <>
PathSmootherPOVSearch::NavMeshEdgeRecord*
BSSimpleArray<PathSmootherPOVSearch::NavMeshEdgeRecord>::_Allocate(unsigned int size)
{
    void* p = ::operator new(size << 5);
    return static_cast<PathSmootherPOVSearch::NavMeshEdgeRecord*>(p);
}

// @fnv 0x006b35c0
template <>
BSSimpleArray<PathSmootherPOVAvoidanceNode>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x006b36b0
template <>
NavMeshEdgeSegment* BSSimpleArray<NavMeshEdgeSegment>::_Allocate(unsigned int count)
{
    void* mem = operator new(count * 64);
    return static_cast<NavMeshEdgeSegment*>(mem);
}

void __cdecl _Deallocate(void*);
// Destructs the PathSmootherPOVSearch object and frees it when the low bit of flags is set, then returns the object pointer.
// @fnv 0x006ad660
void* PathSmootherPOVSearch::DestroyPathSmootherPOVSearch(unsigned int flags)
{
    this->PathSmootherPOVSearch::~PathSmootherPOVSearch();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_006aeb70 {
struct BaseS
{
    char _d[8];
    BaseS();
};
struct FUN_006aeb70
{
    BaseS a;
    NiBound b;
    FUN_006aeb70();
};
// Constructs the object, default-constructing its BaseS member and NiBound member.
// @fnv 0x006aeb70
FUN_006aeb70::FUN_006aeb70()
{}
}  // namespace fnv_006aeb70

struct B006815c0
{
    char _d[8];
    B006815c0();
};
struct FUN_006b1d80
{
    B006815c0 m0;
    B006815c0 m1;
    NavMeshEdgePoint m2;
    NavMeshEdgePoint m3;
    FUN_006b1d80();
};
// @fnv 0x006b1d80
FUN_006b1d80::FUN_006b1d80()
{}

// @fnv 0x006b3610
template <>
BSSimpleArray<NavMeshEdgeSegment>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x006b3660
template <>
unsigned int BSSimpleArray<NavMeshEdgeSegment>::Add(const NavMeshEdgeSegment& value)
{
    int iIndex = ReserveIndex();
    InitializeItems(&pBuffer[iIndex], 1);
    pBuffer[iIndex] = value;
    return iIndex;
}

// @fnv 0x006b36e0
template <>
BSSimpleArray<PathSmootherPOVSearch::NavMeshEdgeRecord>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// The shared nested record does not yet declare its out-of-line assignment.
struct NavMeshEdgeRecordAssignment : PathSmootherPOVSearch::NavMeshEdgeRecord
{
    void Assign(const PathSmootherPOVSearch::NavMeshEdgeRecord&);
};

// @fnv 0x006b3730
template <>
unsigned int BSSimpleArray<PathSmootherPOVSearch::NavMeshEdgeRecord>::Add(
    const PathSmootherPOVSearch::NavMeshEdgeRecord& value)
{
    int iIndex;
    iIndex = ReserveIndex();
    InitializeItems(&pBuffer[iIndex], 1);
    reinterpret_cast<NavMeshEdgeRecordAssignment*>(&pBuffer[iIndex])->Assign(value);
    return iIndex;
}

// @fnv 0x006ad4c0
PathSmootherPOVSearch::PathSmootherPOVSearch()
{
    pRequest = 0;
    NiPoint3 m_kPathStartPosition = NiPoint3::ZERO;
    NiPoint3 m_kGoalPosition = NiPoint3::ZERO;
    Triangles = 0;
    Edges = 0;
    m_pOutputSolution = 0;
    m_pStartPoint = 0;
    m_pGoalPoint = 0;
    m_bUnderwaterPath = false;
    m_pNavMeshInfos = 0;
}

struct PSNode
{
    float m_fPathingCostCur;
    char pad04[0x5c];
    unsigned int uiKey;
    PSNode* pNext;
};
struct FUN_00996840_shell
{
    PSNode* m_ppNodes[2040];
    unsigned int AStarNodeMap_GetBucketIndex(unsigned int);
};
struct PSNodePool
{
    PSNode* AllocateAndConstructObject68();
    char pad[0x10];
};
struct PSOpenList
{
    void UnlinkFromList(PSNode*);
};
struct FUN_006b3420_shell
{
    void* pad00;
    PSNodePool kPool;
    FUN_00996840_shell kMap;
    PSOpenList kOpen;
    int InsertOrUpdateNode(unsigned int aiKey, float afCost, PSNode** aRetNode);
};

// @fnv 0x006b3420
int FUN_006b3420_shell::InsertOrUpdateNode(unsigned int aiKey, float afCost, PSNode** aRetNode)
{
    PSNode** pBucketHead = &kMap.m_ppNodes[kMap.AStarNodeMap_GetBucketIndex(aiKey)];
    if (*pBucketHead)
    {
        if ((*pBucketHead)->uiKey == aiKey)
        {
            if ((*pBucketHead)->m_fPathingCostCur > afCost)
            {
                *aRetNode = *pBucketHead;
                kOpen.UnlinkFromList(*aRetNode);
                (*aRetNode)->m_fPathingCostCur = afCost;
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            PSNode* pcurrent;
            PSNode* pprev;
            pprev = *pBucketHead;
            pcurrent = (*pBucketHead)->pNext;
            while (pcurrent)
            {
                if (pcurrent->uiKey == aiKey)
                {
                    if (pcurrent->m_fPathingCostCur > afCost)
                    {
                        *aRetNode = pcurrent;
                        kOpen.UnlinkFromList(*aRetNode);
                        (*aRetNode)->m_fPathingCostCur = afCost;
                        return 1;
                    }
                    else
                    {
                        return 2;
                    }
                }
                pprev = pcurrent;
                pcurrent = pcurrent->pNext;
            }
        }
    }
    *aRetNode = kPool.AllocateAndConstructObject68();
    (*aRetNode)->uiKey = aiKey;
    (*aRetNode)->m_fPathingCostCur = afCost;
    (*aRetNode)->pNext = *pBucketHead;
    *pBucketHead = *aRetNode;
    return 0;
}

// @fnv 0x006ae190
void PathSmootherPOVSearch::CreateStartPoint()
{
    struct POD12
    {
        unsigned int x;
        unsigned int y;
        unsigned int z;
    };

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4) = new PathSmootherPOVPoint;

    reinterpret_cast<unsigned int*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4))[0] = 2;

    *reinterpret_cast<POD12*>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4)) + 4) =
        *reinterpret_cast<POD12*>(reinterpret_cast<char*>(this) + 0x2060);

    *reinterpret_cast<float*>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4)) + 0x10) = 0.0f;

    *reinterpret_cast<unsigned short*>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x20c4)) + 0x48) = 0xffff;

    m_kPathPoints.Add(m_pStartPoint);
}

// Allocates and initializes the goal point, then appends it to the path.
// @fnv 0x006ae280
void PathSmootherPOVSearch::CreateGoalPoint()
{
    m_pGoalPoint = new PathSmootherPOVPoint;
    m_pGoalPoint->eType = 3;
    m_pGoalPoint->Center = m_kGoalPosition;
    m_pGoalPoint->fRadius = 0.0f;
    m_pGoalPoint->m_usResult = 0xffff;
    m_kPathPoints.Add(m_pGoalPoint);
}

class Key6AE
{
  public:
    Key6AE* Copy(const Key6AE* pkOther);

    int unk00;
    int unk04;
};

class Entry6AE
{
  public:
    Entry6AE();

    Key6AE m_kControlPoint;
    NavMeshEdgeData m_kData;
    int m_iCountA;
    int m_iCountB;
    int m_iIndex;
};


// Builds an Entry6AE from pkKey and kData, fills its counts from m_kOther and m_kEntries, sets index -1, and appends it to m_kEntries.
// @fnv 0x006aea90
void PathSmootherPOVSearch::AddEntry(const Key6AE* pkKey, const NavMeshEdgeData& kData)
{
    Entry6AE kEntry;
    kEntry.m_kControlPoint.Copy(pkKey);
    kEntry.m_kData = kData;
    kEntry.m_iCountA = m_kSecondaryEdgeRecords.GetSize();
    kEntry.m_iCountB = m_kPrimaryEdgeRecords.GetSize();
    kEntry.m_iIndex = -1;
    m_kPrimaryEdgeRecords.Add(reinterpret_cast<const NavMeshEdgeRecord&>(kEntry));
}

struct Point17
{
    float x, y, z;
    Point17 operator+(const Point17&) const;
    Point17 operator-(const Point17&) const;
    void Unitize_004a0c10();
    Point17& operator*=(float);
    Point17& Subtract(const Point17&);
};
struct Angle17
{
    float cosine, sine;
    Point17 MakePointOnCircle(float) const;
    Angle17& operator=(const Angle17&);
};
struct Arc17
{
    Angle17 start, end;
    ANGLE_DIRECTION direction;
    Arc17(const Angle17&, const Angle17&, ANGLE_DIRECTION);
    Arc17(const Arc17&);
};
struct Sphere17
{
    Point17 center;
    float radius;
    Sphere17(const Point17&, float);
};
struct MeshOps17
{
    unsigned int FUN_0059bb30();
};
struct Link17
{
    Angle17 m0, m1;
    NavMeshEdgePoint m2, m3;
    Link17();
};
int FUN_006bb570(const Sphere17&, const Sphere17&, ANGLE_DIRECTION, SphereTangents&);
struct PathSmootherPOVLastNodeCalls : PathSmootherPOVSearch
{
    bool CheckArcAgainstNavMesh(const NavMeshEdgePoint&, Sphere17&, Arc17, NavMeshEdgePoint*);
    bool DoubleCheckArcAgainstNavMesh(const NavMeshEdgePoint&, Sphere17&, Arc17);
};
// Computes tangents between the current node and the target, validates the path, adjusts the endpoint for water, and appends a link and node.
// @fnv 0x006b1970
bool PathSmootherPOVSearch::TryAddLastNode()
{
    if (Links.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        return false;
    const PathSmootherPOVAvoidanceNode& h = Nodes.GetLastEdge();
    const NavMeshEdgeSegment& eb = Links.GetLastEdge();
    Sphere17 f((const Point17&)h.m_pAvoidNode->Center, h.m_pAvoidNode->fRadius);
    Sphere17 k((const Point17&)m_pGoalPoint->Center, m_pGoalPoint->fRadius);
    SphereTangents b;
    int q = FUN_006bb570(f, k, h.Direction, b);
    if (!q)
        return false;
    Arc17 c((const Angle17&)eb.m_kEnd, (const Angle17&)b.Tangents[0].m_kStartAngle, h.Direction);
    NavMeshEdgePoint cf;
    if (!reinterpret_cast<PathSmootherPOVLastNodeCalls*>(this)->CheckArcAgainstNavMesh(eb.m_kEndPoint, f, c, &cf))
        return false;
    if (!reinterpret_cast<PathSmootherPOVLastNodeCalls*>(this)->DoubleCheckArcAgainstNavMesh(eb.m_kEndPoint, f, c))
        return false;
    NavMeshEdgePoint s;
    Point17 ba = k.center + ((const Angle17&)b.Tangents[0].m_kEnd).MakePointOnCircle(k.radius);
    reinterpret_cast<int&>(cf.f8) = -1;
    float p = 0;
    if (pRequest->GetFloatAtOffset68() >= 100.0)
    {
        if (TripleCheckSegmentAgainstNavMesh(cf, reinterpret_cast<const NiPoint3&>(ba), &s, false, true, p))
        {
            float radius = 0;
            if (!CalculatePathCost(h.m_pAvoidNode, m_pGoalPoint, reinterpret_cast<NiPoint3&>(cf.fc), reinterpret_cast<const NiPoint3&>(ba), &radius))
                return false;
        }
    }
    else
    {
        if (FindPath(cf, reinterpret_cast<const NiPoint3&>(ba), s, p))
        {
            float radius = 0;
            if (!CalculatePathCost(h.m_pAvoidNode, m_pGoalPoint, reinterpret_cast<NiPoint3&>(cf.fc), reinterpret_cast<const NiPoint3&>(ba), &radius))
                return false;
        }
    }
    if (m_bUnderwaterPath)
    {
        float water = g_TES->UpdateTESState(reinterpret_cast<NiPoint3&>(s.fc), ((MeshOps17*)reinterpret_cast<NavMesh*&>(s.f0))->FUN_0059bb30());
        if (water >= reinterpret_cast<NiPoint3&>(s.fc).z)
            reinterpret_cast<NiPoint3&>(s.fc).z = water;
    }
    Point17 l = ba - (const Point17&)reinterpret_cast<NiPoint3&>(cf.fc);
    l.Unitize_004a0c10();
    l *= pRequest->GetFloatAtOffset68() * 2.0f;
    ((Point17&)reinterpret_cast<NiPoint3&>(s.fc)).Subtract(l);
    Link17 a;
    a.m2 = cf;
    a.m3 = s;
    ((Angle17&)a.m0) = (const Angle17&)b.Tangents[0].m_kStartAngle;
    ((Angle17&)a.m1) = (const Angle17&)b.Tangents[0].m_kEnd;
    Links.Add((const NavMeshEdgeSegment&)a);
    PathSmootherPOVAvoidanceNode i;
    i.m_pAvoidNode = m_pGoalPoint;
    i.m_fPathDistance = 0;
    i.Direction = b.Tangents[0].Direction;
    Nodes.Add(i);
    return true;
}

// @fnv 0x006b2fc0
// src: COMMUNITY 0x006b2fc0
bool PathSmootherPOVSearch::AddIntersectingPOVsAsBadNodes(BSSimpleArray<NavMeshTriangleEdgeReference>* apEdges)
{
    if (apEdges == 0)
        return false;
    bool bStateChanged = false;
    for (unsigned int i = 0; i < const_cast<BSSimpleArray<NavMeshTriangleEdgeReference>*>(Edges)->GetSize(); i++)
    {
        NiPoint3 kStartPt;
        NiPoint3 kEndPt;
        Edges->operator[](i).m_pLocationNavMesh->GetEdgeVertices_0068f0c0(Edges->operator[](i).m_usTriangleIdentifier,
                                                              Edges->operator[](i).m_iEdgeIndex, kStartPt, kEndPt);
        if ((kStartPt - kEndPt).FUN_004a7290() < pRequest->GetFloatAtOffset68() * pRequest->GetFloatAtOffset68() * 4.0)
        {
            apEdges->Add(Edges->operator[](i));
            bStateChanged = true;
        }
    }
    return bStateChanged;
}

struct FUN_006b31c0_sub04
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    FUN_006b31c0_sub04();
    ~FUN_006b31c0_sub04();
};

struct FUN_006b31c0_sub14
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    int unk16B4;
    int unk16B8;
    int unk16BC;
    int unk16C0;
    int unk16C4;
    int unk16C8;
    int unk16CC;
    int unk16D0;
    int unk16D4;
    int unk16D8;
    int unk16DC;
    int unk16E0;
    int unk16E4;
    int unk16E8;
    int unk16EC;
    int unk16F0;
    int unk16F4;
    int unk16F8;
    int unk16FC;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170C;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171C;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172C;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173C;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174C;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175C;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176C;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177C;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178C;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179C;
    int unk17A0;
    int unk17A4;
    int unk17A8;
    int unk17AC;
    int unk17B0;
    int unk17B4;
    int unk17B8;
    int unk17BC;
    int unk17C0;
    int unk17C4;
    int unk17C8;
    int unk17CC;
    int unk17D0;
    int unk17D4;
    int unk17D8;
    int unk17DC;
    int unk17E0;
    int unk17E4;
    int unk17E8;
    int unk17EC;
    int unk17F0;
    int unk17F4;
    int unk17F8;
    int unk17FC;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180C;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181C;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182C;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183C;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184C;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185C;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186C;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187C;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188C;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189C;
    int unk18A0;
    int unk18A4;
    int unk18A8;
    int unk18AC;
    int unk18B0;
    int unk18B4;
    int unk18B8;
    int unk18BC;
    int unk18C0;
    int unk18C4;
    int unk18C8;
    int unk18CC;
    int unk18D0;
    int unk18D4;
    int unk18D8;
    int unk18DC;
    int unk18E0;
    int unk18E4;
    int unk18E8;
    int unk18EC;
    int unk18F0;
    int unk18F4;
    int unk18F8;
    int unk18FC;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190C;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191C;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192C;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193C;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194C;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195C;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196C;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197C;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198C;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199C;
    int unk19A0;
    int unk19A4;
    int unk19A8;
    int unk19AC;
    int unk19B0;
    int unk19B4;
    int unk19B8;
    int unk19BC;
    int unk19C0;
    int unk19C4;
    int unk19C8;
    int unk19CC;
    int unk19D0;
    int unk19D4;
    int unk19D8;
    int unk19DC;
    int unk19E0;
    int unk19E4;
    int unk19E8;
    int unk19EC;
    int unk19F0;
    int unk19F4;
    int unk19F8;
    int unk19FC;
    int unk1A00;
    int unk1A04;
    int unk1A08;
    int unk1A0C;
    int unk1A10;
    int unk1A14;
    int unk1A18;
    int unk1A1C;
    int unk1A20;
    int unk1A24;
    int unk1A28;
    int unk1A2C;
    int unk1A30;
    int unk1A34;
    int unk1A38;
    int unk1A3C;
    int unk1A40;
    int unk1A44;
    int unk1A48;
    int unk1A4C;
    int unk1A50;
    int unk1A54;
    int unk1A58;
    int unk1A5C;
    int unk1A60;
    int unk1A64;
    int unk1A68;
    int unk1A6C;
    int unk1A70;
    int unk1A74;
    int unk1A78;
    int unk1A7C;
    int unk1A80;
    int unk1A84;
    int unk1A88;
    int unk1A8C;
    int unk1A90;
    int unk1A94;
    int unk1A98;
    int unk1A9C;
    int unk1AA0;
    int unk1AA4;
    int unk1AA8;
    int unk1AAC;
    int unk1AB0;
    int unk1AB4;
    int unk1AB8;
    int unk1ABC;
    int unk1AC0;
    int unk1AC4;
    int unk1AC8;
    int unk1ACC;
    int unk1AD0;
    int unk1AD4;
    int unk1AD8;
    int unk1ADC;
    int unk1AE0;
    int unk1AE4;
    int unk1AE8;
    int unk1AEC;
    int unk1AF0;
    int unk1AF4;
    int unk1AF8;
    int unk1AFC;
    int unk1B00;
    int unk1B04;
    int unk1B08;
    int unk1B0C;
    int unk1B10;
    int unk1B14;
    int unk1B18;
    int unk1B1C;
    int unk1B20;
    int unk1B24;
    int unk1B28;
    int unk1B2C;
    int unk1B30;
    int unk1B34;
    int unk1B38;
    int unk1B3C;
    int unk1B40;
    int unk1B44;
    int unk1B48;
    int unk1B4C;
    int unk1B50;
    int unk1B54;
    int unk1B58;
    int unk1B5C;
    int unk1B60;
    int unk1B64;
    int unk1B68;
    int unk1B6C;
    int unk1B70;
    int unk1B74;
    int unk1B78;
    int unk1B7C;
    int unk1B80;
    int unk1B84;
    int unk1B88;
    int unk1B8C;
    int unk1B90;
    int unk1B94;
    int unk1B98;
    int unk1B9C;
    int unk1BA0;
    int unk1BA4;
    int unk1BA8;
    int unk1BAC;
    int unk1BB0;
    int unk1BB4;
    int unk1BB8;
    int unk1BBC;
    int unk1BC0;
    int unk1BC4;
    int unk1BC8;
    int unk1BCC;
    int unk1BD0;
    int unk1BD4;
    int unk1BD8;
    int unk1BDC;
    int unk1BE0;
    int unk1BE4;
    int unk1BE8;
    int unk1BEC;
    int unk1BF0;
    int unk1BF4;
    int unk1BF8;
    int unk1BFC;
    int unk1C00;
    int unk1C04;
    int unk1C08;
    int unk1C0C;
    int unk1C10;
    int unk1C14;
    int unk1C18;
    int unk1C1C;
    int unk1C20;
    int unk1C24;
    int unk1C28;
    int unk1C2C;
    int unk1C30;
    int unk1C34;
    int unk1C38;
    int unk1C3C;
    int unk1C40;
    int unk1C44;
    int unk1C48;
    int unk1C4C;
    int unk1C50;
    int unk1C54;
    int unk1C58;
    int unk1C5C;
    int unk1C60;
    int unk1C64;
    int unk1C68;
    int unk1C6C;
    int unk1C70;
    int unk1C74;
    int unk1C78;
    int unk1C7C;
    int unk1C80;
    int unk1C84;
    int unk1C88;
    int unk1C8C;
    int unk1C90;
    int unk1C94;
    int unk1C98;
    int unk1C9C;
    int unk1CA0;
    int unk1CA4;
    int unk1CA8;
    int unk1CAC;
    int unk1CB0;
    int unk1CB4;
    int unk1CB8;
    int unk1CBC;
    int unk1CC0;
    int unk1CC4;
    int unk1CC8;
    int unk1CCC;
    int unk1CD0;
    int unk1CD4;
    int unk1CD8;
    int unk1CDC;
    int unk1CE0;
    int unk1CE4;
    int unk1CE8;
    int unk1CEC;
    int unk1CF0;
    int unk1CF4;
    int unk1CF8;
    int unk1CFC;
    int unk1D00;
    int unk1D04;
    int unk1D08;
    int unk1D0C;
    int unk1D10;
    int unk1D14;
    int unk1D18;
    int unk1D1C;
    int unk1D20;
    int unk1D24;
    int unk1D28;
    int unk1D2C;
    int unk1D30;
    int unk1D34;
    int unk1D38;
    int unk1D3C;
    int unk1D40;
    int unk1D44;
    int unk1D48;
    int unk1D4C;
    int unk1D50;
    int unk1D54;
    int unk1D58;
    int unk1D5C;
    int unk1D60;
    int unk1D64;
    int unk1D68;
    int unk1D6C;
    int unk1D70;
    int unk1D74;
    int unk1D78;
    int unk1D7C;
    int unk1D80;
    int unk1D84;
    int unk1D88;
    int unk1D8C;
    int unk1D90;
    int unk1D94;
    int unk1D98;
    int unk1D9C;
    int unk1DA0;
    int unk1DA4;
    int unk1DA8;
    int unk1DAC;
    int unk1DB0;
    int unk1DB4;
    int unk1DB8;
    int unk1DBC;
    int unk1DC0;
    int unk1DC4;
    int unk1DC8;
    int unk1DCC;
    int unk1DD0;
    int unk1DD4;
    int unk1DD8;
    int unk1DDC;
    int unk1DE0;
    int unk1DE4;
    int unk1DE8;
    int unk1DEC;
    int unk1DF0;
    int unk1DF4;
    int unk1DF8;
    int unk1DFC;
    int unk1E00;
    int unk1E04;
    int unk1E08;
    int unk1E0C;
    int unk1E10;
    int unk1E14;
    int unk1E18;
    int unk1E1C;
    int unk1E20;
    int unk1E24;
    int unk1E28;
    int unk1E2C;
    int unk1E30;
    int unk1E34;
    int unk1E38;
    int unk1E3C;
    int unk1E40;
    int unk1E44;
    int unk1E48;
    int unk1E4C;
    int unk1E50;
    int unk1E54;
    int unk1E58;
    int unk1E5C;
    int unk1E60;
    int unk1E64;
    int unk1E68;
    int unk1E6C;
    int unk1E70;
    int unk1E74;
    int unk1E78;
    int unk1E7C;
    int unk1E80;
    int unk1E84;
    int unk1E88;
    int unk1E8C;
    int unk1E90;
    int unk1E94;
    int unk1E98;
    int unk1E9C;
    int unk1EA0;
    int unk1EA4;
    int unk1EA8;
    int unk1EAC;
    int unk1EB0;
    int unk1EB4;
    int unk1EB8;
    int unk1EBC;
    int unk1EC0;
    int unk1EC4;
    int unk1EC8;
    int unk1ECC;
    int unk1ED0;
    int unk1ED4;
    int unk1ED8;
    int unk1EDC;
    int unk1EE0;
    int unk1EE4;
    int unk1EE8;
    int unk1EEC;
    int unk1EF0;
    int unk1EF4;
    int unk1EF8;
    int unk1EFC;
    int unk1F00;
    int unk1F04;
    int unk1F08;
    int unk1F0C;
    int unk1F10;
    int unk1F14;
    int unk1F18;
    int unk1F1C;
    int unk1F20;
    int unk1F24;
    int unk1F28;
    int unk1F2C;
    int unk1F30;
    int unk1F34;
    int unk1F38;
    int unk1F3C;
    int unk1F40;
    int unk1F44;
    int unk1F48;
    int unk1F4C;
    int unk1F50;
    int unk1F54;
    int unk1F58;
    int unk1F5C;
    int unk1F60;
    int unk1F64;
    int unk1F68;
    int unk1F6C;
    int unk1F70;
    int unk1F74;
    int unk1F78;
    int unk1F7C;
    int unk1F80;
    int unk1F84;
    int unk1F88;
    int unk1F8C;
    int unk1F90;
    int unk1F94;
    int unk1F98;
    int unk1F9C;
    int unk1FA0;
    int unk1FA4;
    int unk1FA8;
    int unk1FAC;
    int unk1FB0;
    int unk1FB4;
    int unk1FB8;
    int unk1FBC;
    int unk1FC0;
    int unk1FC4;
    int unk1FC8;
    int unk1FCC;
    int unk1FD0;
    int unk1FD4;
    int unk1FD8;
    int unk1FDC;
    FUN_006b31c0_sub14();
    ~FUN_006b31c0_sub14();
};

struct FUN_006b31c0_sub1ff4
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    FUN_006b31c0_sub1ff4();
};

class FUN_006b31c0_cls
{
  public:
    virtual ~FUN_006b31c0_cls();
    FUN_006b31c0_sub04 m_04;
    FUN_006b31c0_sub14 m_14;
    FUN_006b31c0_sub1ff4 m_1ff4;
    int m_2048;
    int m_204c;
    int m_2050;
    char m_2054;
    FUN_006b31c0_cls();
};

// Initializes m_2048, m_204c, m_2050 and m_2054 to zero.
// @fnv 0x006b31c0
FUN_006b31c0_cls::FUN_006b31c0_cls()
{
    m_2048 = 0;
    m_204c = 0;
    m_2050 = 0;
    m_2054 = 0;
}

struct PSNodeSlot
{
    void InsertSorted(POVNode* pNode);
};

struct PSSearchView
{
    void* vtbl;
    char unk0004[0x1ff0];
    PSNodeSlot m_1ff4;
    char unk1ff5[0x2050 - 0x1ff5];
    POVNode* m_2050;
    int InsertOrUpdateNode(unsigned int aiKey, float afCost, POVNode*& aRetNode);
    POVNode* InsertNode(unsigned int aiKey, const PathSmootherPOVAvoidanceNode& aNode, float afCost);
};

// @fnv 0x006b32f0
POVNode* PSSearchView::InsertNode(unsigned int aiKey, const PathSmootherPOVAvoidanceNode& aNode, float afCost)
{
    POVNode* pNode;
    switch (InsertOrUpdateNode(aiKey, 0.0f, pNode))
    {
    case 0:
        pNode->m_fPathingCostCur = afCost;
        pNode->Node = aNode;
        m_1ff4.InsertSorted(pNode);
        m_2050 = pNode;
        return pNode;
    case 1:
        return pNode;
    case 2:
        return 0;
    default:
        return 0;
    }
}

struct FUN_006b3380_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned char v3(int);
};

FUN_006b3380_obj* FUN_00b00a00();
int FUN_0040fc90();

// @fnv 0x006b3380
// src: COMMUNITY 0x006b3380
bool PathSmootherPOVSearch::AStarSearch_PathSmootherPOVNode_PathSmootherPOVLink_Search(BSSimpleArray<PathSmootherPOVAvoidanceNode>* nodes,
                                      BSSimpleArray<NavMeshEdgeSegment>* links, bool bUseCached)
{
    bool result2;
    void* p4;
    void* cur;
    searchState[0x2050] = FUN_00b00a00()->v3(FUN_0040fc90());
    p4 = ComputePathNodes();
    if (p4 != 0)
    {
        result2 = true;
        cur = p4;
    }
    else if (bUseCached)
    {
        result2 = false;
        cur = *(void**)&searchState[0x2044];
    }
    else
    {
        result2 = false;
        cur = 0;
    }
    if (cur != 0)
        CopyNodeListToArrays(cur, nodes, links);
    return result2;
}

struct NiPoint3Cmp
{
    float x, y, z;
    bool IsEqual(const NiPoint3& other);
};
NiPoint3 operator*(float scale, const NiPoint3& point);

// @fnv 0x006ba550
// src: GUESS 0x006ba550 (confidence: low)
NiPoint3 NiPoint3_UpdateState_006ba550(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d)
{
    if (((NiPoint3Cmp*)&a)->IsEqual(b))
        return a;
    float fB = (c.x - b.x) * (d.y - b.y) - (c.y - b.y) * (d.x - b.x);
    float fA2 = (c.x - a.x) * (d.y - a.y) - (c.y - a.y) * (d.x - a.x);
    float fRatio = fA2 / (fA2 - fB);
    NiPoint3 kResult3 = a + fRatio * (b - a);
    if (fB * fA2 > 0.0)
    {
        if ((kResult3 - a).FUN_004a7290() < (kResult3 - b).FUN_004a7290())
            return a;
        else
            return b;
    }
    else
    {
        return kResult3;
    }
}

namespace AvoidNodes {
extern const NiPoint3 DAT_011a9484;
extern const float DAT_01016248, DAT_0101df44, DAT_01016410;
extern const double DAT_010290c0, DAT_010290b0;
struct FUN_006ae120
{
    int type;
    NiPoint3 center;
    float radius;
    int unk14, unk18, unk1c;
    NiPoint3 edge1, edge2;
    float cost;
    unsigned int thisSide, otherSide, avoidIndex;
    unsigned short vertex;
    FUN_006ae120();
};
struct Request
{
    bool GetTryToUseCurvedPath();
};
// Runs the search steps, then if the request passes, creates three type-4 avoidance nodes (center, left, right) and adds each to both node lists.
// @fnv 0x006adcb0
}  // namespace AvoidNodes

void PathSmootherPOVSearch::AddAvoidanceNodes()
{
    CreateStartPoint();
    BuildPOVLinks();
    CreateGoalPoint();
    CollectAvoidSpheres();
    CollectUniqueNavMeshes();
    BuildSmoothedPath();
    if (((AvoidNodes::Request*)pRequest)->GetTryToUseCurvedPath())
    {
        AvoidNodes::FUN_006ae120* centerSlot13 = new AvoidNodes::FUN_006ae120;
        centerSlot13->type = 4;
        centerSlot13->center =
            ((NiPoint3&)m_kPathStartPosition).FUN_00439e90((NiPoint3&)m_kGoalPosition).ApplyScaled(AvoidNodes::DAT_01016248);
        centerSlot13->radius =
            ((NiPoint3&)m_kPathStartPosition).SubtractIntoVector((NiPoint3&)m_kGoalPosition).FUN_00457990() * AvoidNodes::DAT_010290c0;
        centerSlot13->vertex = 0xffff;
        centerSlot13->cost = AvoidNodes::DAT_01016410;
        m_kPathPoints.Add(reinterpret_cast<PathSmootherPOVPoint*&>(centerSlot13));
        m_kRequestPathPoints.Add(reinterpret_cast<PathSmootherPOVPoint*&>(centerSlot13));
        NiPoint3 direction = ((NiPoint3&)m_kPathStartPosition).SubtractIntoVector((NiPoint3&)m_kGoalPosition);
        NiPoint3 perpendicularSlot2 = AvoidNodes::DAT_011a9484.FUN_004b3800(direction);
        AvoidNodes::FUN_006ae120* leftSlot15 = new AvoidNodes::FUN_006ae120;
        leftSlot15->type = 4;
        leftSlot15->center = ((NiPoint3&)m_kGoalPosition)
                                 .FUN_00439e90(direction.ApplyScaled(AvoidNodes::DAT_0101df44))
                                 .FUN_00439e90(perpendicularSlot2.ApplyScaled(AvoidNodes::DAT_0101df44));
        leftSlot15->radius =
            ((NiPoint3&)m_kPathStartPosition).SubtractIntoVector((NiPoint3&)m_kGoalPosition).FUN_00457990() * AvoidNodes::DAT_010290b0;
        leftSlot15->vertex = 0xffff;
        leftSlot15->cost = AvoidNodes::DAT_01016410;
        m_kPathPoints.Add(reinterpret_cast<PathSmootherPOVPoint*&>(leftSlot15));
        m_kRequestPathPoints.Add(reinterpret_cast<PathSmootherPOVPoint*&>(leftSlot15));
        AvoidNodes::FUN_006ae120* rightSlot10 = new AvoidNodes::FUN_006ae120;
        rightSlot10->type = 4;
        rightSlot10->center = ((NiPoint3&)m_kGoalPosition)
                                  .FUN_00439e90(direction.ApplyScaled(AvoidNodes::DAT_0101df44))
                                  .SubtractIntoVector(perpendicularSlot2.ApplyScaled(AvoidNodes::DAT_0101df44));
        rightSlot10->radius =
            ((NiPoint3&)m_kPathStartPosition).SubtractIntoVector((NiPoint3&)m_kGoalPosition).FUN_00457990() * AvoidNodes::DAT_010290b0;
        rightSlot10->vertex = 0xffff;
        rightSlot10->cost = AvoidNodes::DAT_01016410;
        m_kPathPoints.Add(reinterpret_cast<PathSmootherPOVPoint*&>(rightSlot10));
        m_kRequestPathPoints.Add(reinterpret_cast<PathSmootherPOVPoint*&>(rightSlot10));
    }
}

class AvoidSphereExt : public AvoidSphere
{
  public:
    int BGSSaveFormBuffer_GetForm();
};

class AvoidNodeArray
{
  public:
    unsigned int GetCount();
    AvoidSphere* At(unsigned int);
};

class AvoidNodeArrayHolder
{
  public:
    void* unk00;
    AvoidNodeArrayHolder(BSSimpleArray<void*>*);
    ~AvoidNodeArrayHolder();
    AvoidNodeArray* Get();
};

extern const NiPoint3 DAT_011f426c;

// @fnv 0x006aefc0
void PathSmootherPOVSearch::CollectAvoidSpheres()
{
    AvoidNodeArrayHolder holder(this->pRequest->GetString());
    if (holder.Get() != 0)
    {
        for (unsigned int i = 0; i < holder.Get()->GetCount(); i++)
        {
            AvoidSphereExt* avoid = (AvoidSphereExt*)holder.Get()->At(i);
            PathSmootherPOVPoint* cur = new PathSmootherPOVPoint();
            cur->eType = 4;
            cur->m_kFirstEdge = DAT_011f426c;
            cur->m_kSecondEdge = DAT_011f426c;
            cur->Center = avoid->FUN_006815c0();
            cur->m_fWeight = 1.0f;
            cur->fRadius = (float)(avoid->GetRadius() + this->pRequest->GetFloatAtOffset68() * 1.2f);
            cur->m_uiReferenceIndex = 0xffffffff;
            cur->m_uiCompositeId = i;
            this->m_kPathPoints.Add(cur);
            this->m_kRequestPathPoints.Add(cur);

            if (avoid->BGSSaveFormBuffer_GetForm() == 2)
            {
                PathSmootherPOVPoint* pov2 = new PathSmootherPOVPoint();
                pov2->eType = 5;
                pov2->m_kFirstEdge = DAT_011f426c;
                pov2->m_kSecondEdge = DAT_011f426c;
                pov2->Center = avoid->FUN_006815c0();
                pov2->m_fWeight = 10.0f;
                pov2->fRadius = (float)(avoid->GetRadius() * 0.25 + this->pRequest->GetFloatAtOffset68() * 1.2f);
                pov2->m_uiReferenceIndex = 0xffffffff;
                pov2->m_uiCompositeId = i;
                this->m_kPathPoints.Add(pov2);
                this->m_kRequestPathPoints.Add(pov2);
            }
        }
    }
}

struct Edge
{
    unsigned short a, b;
    Edge();
};
struct Mesh
{
    Edge GetEdge(unsigned short, int);
    const NiPoint3& Vertex(unsigned short);
    bool Previous(unsigned short, int, Mesh**, unsigned short*, int*);
};
struct Handle
{
    Mesh* mesh;
    unsigned short tri;
    int edge;
    Handle(Mesh*, unsigned short, int);
};
struct Vertex
{
    Mesh* mesh;
    unsigned short index;
    Vertex(Mesh*, unsigned short);
    bool Equals(const Vertex&) const;
};
class PathSmootherPOVLinkRecords : public PathSmootherPOVSearch
{
public:
    void AddLeft(const Vertex&, const Handle&);
    void AddRight(const Vertex&, const Handle&);
};

#define left m_kPrimaryEdgeRecords
#define right m_kSecondaryEdgeRecords
#define edges const_cast<BSSimpleArray<NavMeshTriangleEdgeReference>*>(Edges)
#define triangles Triangles
#define start reinterpret_cast<NiPoint3&>(m_kPathStartPosition)
#define leftPOVs m_kPrimaryPathPoints
#define rightPOVs m_kSecondaryPathPoints
// @fnv 0x006ae370
void PathSmootherPOVSearch::BuildPOVLinks()
{
    left.Clear(false);
    right.Clear(false);
    for (int i = 0; i < edges->GetSize(); ++i)
    {
        Handle c(reinterpret_cast<Mesh*>(edges->operator[](i).m_pLocationNavMesh), edges->operator[](i).m_usTriangleIdentifier, edges->operator[](i).m_iEdgeIndex);
        Edge j = reinterpret_cast<Mesh*>(edges->operator[](i).m_pLocationNavMesh)->GetEdge(edges->operator[](i).m_usTriangleIdentifier, edges->operator[](i).m_iEdgeIndex);
        Vertex l(reinterpret_cast<Mesh*>(edges->operator[](i).m_pLocationNavMesh), j.a);
        Vertex e(reinterpret_cast<Mesh*>(edges->operator[](i).m_pLocationNavMesh), j.b);
        if (i == 0)
        {
            NiPoint3 diffVal = l.mesh->Vertex(l.index) - e.mesh->Vertex(e.index);
            NiPoint3 crossVal = diffVal.Cross(l.mesh->Vertex(l.index) - start);
            if (crossVal.z > 0.0)
            {
                reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddLeft(e, c);
                reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddRight(l, c);
            }
            else
            {
                reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddLeft(l, c);
                reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddRight(e, c);
            }
        }
        else if (l.Equals(reinterpret_cast<const Vertex&>(left.GetLastEdge())))
        {
            reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddRight(e, c);
        }
        else if (l.Equals(reinterpret_cast<const Vertex&>(right.GetLastEdge())))
        {
            reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddLeft(e, c);
        }
        else if (e.Equals(reinterpret_cast<const Vertex&>(left.GetLastEdge())))
        {
            reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddRight(l, c);
        }
        else if (e.Equals(reinterpret_cast<const Vertex&>(right.GetLastEdge())))
        {
            reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddLeft(l, c);
        }
        else
        {
            Mesh* handle = 0;
            unsigned short edge5 = 0xffff;
            int edge = -1;
            if (reinterpret_cast<Mesh*>(triangles->BSSimpleArray_CombatMember_1024_GetAt(i - 1).m_pLocationNavMesh)->Previous(triangles->BSSimpleArray_CombatMember_1024_GetAt(i - 1).m_usTriangleIdentifier, edges->operator[](i - 1).m_iEdgeIndex, &handle, &edge5,
                                                     &edge))
            {
            }
            Handle edge2(handle, edge5, edge);
            Edge edge3 = handle->GetEdge(edge5, edge);
            Vertex edge9(reinterpret_cast<Mesh*>(edges->operator[](i).m_pLocationNavMesh), edge3.a);
            Vertex edge6(reinterpret_cast<Mesh*>(edges->operator[](i).m_pLocationNavMesh), edge3.b);
            if (l.Equals(edge9))
            {
                reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddRight(e, edge2);
            }
            else if (l.Equals(edge6))
            {
                reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddLeft(e, edge2);
            }
            else if (e.Equals(edge9))
            {
                reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddRight(l, edge2);
            }
            else if (e.Equals(edge6))
            {
                reinterpret_cast<PathSmootherPOVLinkRecords*>(this)->AddLeft(l, edge2);
            }
        }
    }
    for (unsigned int j = 0; j < left.GetSize(); ++j)
        InsertPOVPoint(&m_kPrimaryEdgeRecords, j, true);
    for (unsigned int k = 0; k < right.GetSize(); ++k)
        InsertPOVPoint(&m_kSecondaryEdgeRecords, k, false);
    for (unsigned int l = 0; l < left.GetSize(); ++l)
    {
        if (left.GetBufferEntry(l).m_uiTrailingValue != -1)
        {
            for (unsigned int m = left.GetBufferEntry(l).m_uiReferenceIndex; m < right.GetSize(); ++m)
            {
                if (right.GetBufferEntry(m).m_uiTrailingValue != -1)
                {
                    leftPOVs.operator[](left.GetBufferEntry(l).m_uiTrailingValue)->m_uiReferenceIndex = right.GetBufferEntry(m).m_uiTrailingValue;
                    break;
                }
            }
        }
    }
    for (unsigned int n = 0; n < right.GetSize(); ++n)
    {
        if (right.GetBufferEntry(n).m_uiTrailingValue != -1)
        {
            for (unsigned int o = right.GetBufferEntry(n).m_uiReferenceIndex; o < left.GetSize(); ++o)
            {
                if (left.GetBufferEntry(o).m_uiTrailingValue != -1)
                {
                    rightPOVs.operator[](right.GetBufferEntry(n).m_uiTrailingValue)->m_uiReferenceIndex = left.GetBufferEntry(o).m_uiTrailingValue;
                    break;
                }
            }
        }
    }
}
#undef left
#undef right
#undef edges
#undef triangles
#undef start
#undef leftPOVs
#undef rightPOVs

namespace fnv_006b1e50 {

struct ASC
{
    float fCos, fSin;
    void SetFromAngle(float);
    ASC& operator=(const ASC&);
    ASC Multiply(const ASC&) const;
    NiPoint3 MakePointOnCircle(float) const;
};

struct ASCArc
{
    ASC Start, End;
    int Direction;
    bool AngleSinCosArc_WithinRange(const ASC*) const;
};

struct PtEx
{
    float x, y, z, r;
    NiPoint3 FUN_00439e90(const NiPoint3&) const;
};

extern float DAT_01064f64;
extern float DAT_0106b3a8;

}  // namespace fnv_006b1e50

#define sphere reinterpret_cast<fnv_006b1e50::PtEx&>(sphereRef)
#define arc reinterpret_cast<fnv_006b1e50::ASCArc&>(arcValue)
// @fnv 0x006b1e50
// src: XBOX_PDB 0x006b1e50
bool PathSmootherPOVSearch::CheckArcAgainstNavMesh(const NavMeshEdgePoint& edgeRef, Sphere& sphereRef,
                                          CircularArc arcValue, NavMeshEdgePoint* outRef)
{
    using namespace fnv_006b1e50;
    ASC rot3;
    rot3.SetFromAngle(arc.Direction == 0 ? DAT_01064f64 : DAT_0106b3a8);
    ASC startAng5;
    startAng5 = arc.Start;
    ASC angTmp = startAng5.Multiply(rot3);
    NiPoint3 RunFourthVirtual = sphere.FUN_00439e90(angTmp.MakePointOnCircle(sphere.r));
    NavMeshEdgePoint cur4(edgeRef);
    NavMeshEdgePoint arr5;
    unsigned int count9 = 0;
    int idx4 = -1;
    float weight = 0.0f;
    while (arc.AngleSinCosArc_WithinRange(&angTmp) && count9 < 0x18)
    {
        reinterpret_cast<int&>(cur4.f8) = -1;
        if (!FindPath(reinterpret_cast<const NavMeshEdgePoint&>(cur4), reinterpret_cast<const NiPoint3&>(RunFourthVirtual), reinterpret_cast<NavMeshEdgePoint&>(arr5), weight))
        {
            *outRef = arr5;
            return false;
        }
        static_cast<NavMeshEdgePoint&>(cur4) = arr5;
        startAng5 = angTmp;
        angTmp = startAng5.Multiply(rot3);
        RunFourthVirtual = sphere.FUN_00439e90(angTmp.MakePointOnCircle(sphere.r));
        idx4 = reinterpret_cast<int&>(arr5.f8);
        count9 = count9 + 1;
    }
    if (count9 == 0x18)
    {
        *outRef = arr5;
        return false;
    }
    NiPoint3 q2 = sphere.FUN_00439e90(arc.End.MakePointOnCircle(sphere.r));
    reinterpret_cast<int&>(cur4.f8) = -1;
    if (!FindPath(reinterpret_cast<const NavMeshEdgePoint&>(cur4), reinterpret_cast<const NiPoint3&>(q2), reinterpret_cast<NavMeshEdgePoint&>(arr5), weight))
    {
        *outRef = arr5;
        return false;
    }
    *outRef = arr5;
    return true;
}
#undef sphere
#undef arc

struct TESFile;
struct EdgeExtraInfo
{
    void Clear();
    int GetSaveSize();
    int GetSaveSizeOld();
    void FillBuffer(char*);
    void SerializeToFile(TESFile*, char*);
    void DeserializeFromFile(TESFile*, char*);
    int eType;
    char Portal[8];
};
typedef char _sizecheck_EdgeExtraInfo[sizeof(EdgeExtraInfo) == 12 ? 1 : -1];

class TriangleAccess : public NavMeshTriangle
{
  public:
    bool HasFlag40();
    bool IsNoLargeCreature();
};
// This existing edge helper uses scalar fields so shared padding arrays do not change MSVC 2008 /GS.
class MeshEdgeRecord
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    int m_iEdgeIndex;
    MeshEdgeRecord();
    MeshEdgeRecord(const NavMeshEdgePoint&);
    MeshEdgeRecord(NavMesh*, unsigned short, int);
    MeshEdgeRecord& operator=(const MeshEdgeRecord&);
};
class EdgeLocation : public NavMeshEdgePoint
{
  public:
    EdgeLocation(const MeshEdgeRecord&, const NiPoint3&);
};
extern SettingT_GameSettingCollection_ DAT_011d6ef0;
bool NavMeshMath_Find2DIntersectionStable(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, NiPoint3&);

// @fnv 0x006b2060
#define output (&outputRef)
bool PathSmootherPOVSearch::FindPath(const NavMeshEdgePoint& start, const NiPoint3& goal, NavMeshEdgePoint& outputRef,
                                  float& ratio)
{
    NiPoint3 position2 = reinterpret_cast<const NiPoint3&>(start.fc);
    NiPoint3 position8 = goal;
    NiPoint3 normal = position8 - position2;
    normal.ComputeMagnitude();
    NiPoint3 position = position2;
    MeshEdgeRecord current(start);
    int count = 0;
    int index7 = 0;
    while (index7 < 1000)
    {
        ++index7;
        if (static_cast<TriangleAccess*>(
                current.m_pLocationNavMesh->FUN_005582f0(current.m_usTriangleID))
                ->HasFlag40())
            ++count;
        int NextEdge = current.m_pLocationNavMesh->FindCrossedEdge(current.m_usTriangleID, current.m_iEdgeIndex,
                                                                   position, position8);
        if (NextEdge == -1)
        {
            float Height = position8.z;
            current.m_pLocationNavMesh->GetTriangleHeightAtPoint(current.m_usTriangleID, position8, 3.402823466e38F,
                                                                 3.402823466e38F, Height);
            position8.z = Height;
            *output = EdgeLocation(current, position8);
            ratio = float(count) / index7;
            return true;
        }
        else
        {
            MeshEdgeRecord next2(current.m_pLocationNavMesh, current.m_usTriangleID, NextEdge);
            MeshEdgeRecord next;
            bool result9 = next2.m_pLocationNavMesh->MatchNavMesh(reinterpret_cast<const NavMeshEdgeData&>(next2), reinterpret_cast<NavMeshEdgeData&>(next));
            if (result9)
            {
                EdgeExtraInfo* info = next2.m_pLocationNavMesh
                                          ->GetEdgeExtraInfo(next2.m_usTriangleID, next2.m_iEdgeIndex);
                if (info && info->eType == 1)
                    result9 = false;
                if (pRequest->GetFloatAtOffset68() > DAT_011d6ef0.Float()->f &&
                    static_cast<TriangleAccess*>(
                        next.m_pLocationNavMesh->FUN_005582f0(next.m_usTriangleID))
                        ->IsNoLargeCreature())
                    result9 = false;
            }
            if (result9)
            {
                if (current.m_pLocationNavMesh != next.m_pLocationNavMesh)
                {
                    NavMeshEdgeVertexPair index =
                        next.m_pLocationNavMesh->NavMesh_GetEdgeVertices_0(next.m_usTriangleID, next.m_iEdgeIndex);
                    NiPoint3 point = (*index.p1 + *index.p2) * 0.5F;
                    position = NiPoint3_UpdateState_006ba550(*index.p1, *index.p2, position2, position8);
                    position += (point - position) * 0.01F;
                }
                current = next;
            }
            else
            {
                NavMeshEdgeVertexPair index = next2.m_pLocationNavMesh->NavMesh_GetEdgeVertices_0(next2.m_usTriangleID, NextEdge);
                NiPoint3 point;
                NavMeshMath_Find2DIntersectionStable(position2, position8, *index.p1, *index.p2, point);
                *output = EdgeLocation(next2, point);
                ratio = float(count) / index7;
                return false;
            }
        }
    }
    *output = EdgeLocation(current, position8);
    if (index7 > 0)
        ratio = float(count) / index7;
    else
        ratio = 0.0F;
    return false;
}
#undef output

namespace fnv_006aeb00 {
struct PathPos6AE
{
    int unk00;
    int unk04;
    PathPos6AE* FUN_0069a690(const PathPos6AE* pkOther);
};

struct PathLoc6AE
{
    int unk00;
    int unk04;
    int unk08;
    PathLoc6AE& CopyFromNavMeshEdge(const PathLoc6AE& kOther);
};

struct FUN_006aeb70
{
    PathPos6AE kPos;
    PathLoc6AE kLoc;
    int iCount1;
    int iCount2;
    int iIndex;
    FUN_006aeb70();
};


class SecondaryEdgeRecords : public PathSmootherPOVSearch
{
public:
    int AddEntry(const PathPos6AE*, const PathLoc6AE&);
};
// Copies the position and location into a request, sets counts from both lists, and returns the result of calling kList2.FUN_006b3730.
// @fnv 0x006aeb00
int SecondaryEdgeRecords::AddEntry(const PathPos6AE* pkPos, const PathLoc6AE& kLoc)
{
    FUN_006aeb70 kRequest;
    kRequest.kPos.FUN_0069a690(pkPos);
    kRequest.kLoc.CopyFromNavMeshEdge(kLoc);
    kRequest.iCount1 = m_kPrimaryEdgeRecords.GetSize();
    kRequest.iCount2 = m_kSecondaryEdgeRecords.GetSize();
    kRequest.iIndex = -1;
    return m_kSecondaryEdgeRecords.Add(reinterpret_cast<const NavMeshEdgeRecord&>(kRequest));
}
}  // namespace fnv_006aeb00

// Rotates a 2D point 90 degrees clockwise or counter-clockwise based on flag, storing the result in out with z set to zero.
// @fnv 0x006b0a60
NiPoint3 PathSmootherPOVSearch::RotatePoint90(const SineCosine& in, ANGLE_DIRECTION flag)
{
    NiPoint3 ptTmp;
    if (flag == ANGLE_DIRECTION_AD_CCW)
    {
        ptTmp.x = -in.fSin;
        ptTmp.y = in.fCos;
    }
    else
    {
        ptTmp.x = in.fSin;
        ptTmp.y = -in.fCos;
    }
    ptTmp.z = 0.0f;
    return ptTmp;
}

typedef PathSmootherPOVSearch::NavMeshEdgeRecord PathEdgeVertType;
typedef BSSimpleArray<PathEdgeVertType, 1024> EdgeVertArray;
struct NavMeshVertexAccess : NavMesh
{
    const NiPoint3* GetVertex_0068f0a0(unsigned short);
};
struct Unitizer
{
    void Unitize();
};
struct CrossAccess
{
    NiPoint3 FUN_004b3800(const NiPoint3&) const;
};
struct RequestAccess
{
    float GetFloatAtOffset68();
};
extern const double DAT_01012060;
extern const double DAT_0103c7c8;
extern const double DAT_0106b9d8;
extern const double DAT_010290f0;

// Checks the vertex directions, then adds a PathSmootherPOVPoint to the path lists when endpoint or cross and dot conditions select it.
// @fnv 0x006aeba0
void PathSmootherPOVSearch::InsertPOVPoint(EdgeVertArray* vertices, unsigned int index, bool left)
{
    NiPoint3 point =
        *reinterpret_cast<NavMeshVertexAccess*>(
             reinterpret_cast<PathEdgeVertType*>(&vertices->GetBufferEntry(index))
                 ->m_pLocationNavMesh)
             ->GetVertex_0068f0a0(
                 reinterpret_cast<PathEdgeVertType*>(&vertices->GetBufferEntry(index))
                     ->m_usVertexId);
    NiPoint3 prevDir;
    NiPoint3 right;
    if (index == 0)
    {
        prevDir = m_kPathStartPosition - point;
    }
    else
    {
        prevDir =
            *reinterpret_cast<NavMeshVertexAccess*>(
                 reinterpret_cast<PathEdgeVertType*>(&vertices->GetBufferEntry(index - 1))
                     ->m_pLocationNavMesh)
                 ->GetVertex_0068f0a0(reinterpret_cast<PathEdgeVertType*>(
                                    &vertices->GetBufferEntry(index - 1))
                                    ->m_usVertexId) -
            point;
    }
    if (index == vertices->GetSize() - 1)
    {
        right = m_kGoalPosition - point;
    }
    else
    {
        right =
            *reinterpret_cast<NavMeshVertexAccess*>(
                 reinterpret_cast<PathEdgeVertType*>(&vertices->GetBufferEntry(index + 1))
                     ->m_pLocationNavMesh)
                 ->GetVertex_0068f0a0(reinterpret_cast<PathEdgeVertType*>(
                                    &vertices->GetBufferEntry(index + 1))
                                    ->m_usVertexId) -
            point;
    }
    prevDir.z = 0.0f;
    right.z = 0.0f;
    reinterpret_cast<Unitizer*>(&prevDir)->Unitize();
    reinterpret_cast<Unitizer*>(&right)->Unitize();
    NiPoint3 cross = left ? reinterpret_cast<CrossAccess*>(&prevDir)->FUN_004b3800(right)
                          : reinterpret_cast<CrossAccess*>(&right)->FUN_004b3800(prevDir);
    float dot = right.Dot(prevDir);
    bool usePOV = false;
    if (index == 0 || index == vertices->GetSize() - 1)
    {
        usePOV = true;
    }
    else if (dot > DAT_01012060)
    {
        if (cross.z < DAT_0103c7c8)
        {
            usePOV = true;
        }
    }
    else if (cross.z < DAT_0106b9d8)
    {
        usePOV = true;
    }
    if (usePOV)
    {
        PathSmootherPOVPoint* pov = new PathSmootherPOVPoint;
        pov->eType = !left;
        pov->MeshEdgeRecord =
            reinterpret_cast<PathEdgeVertType*>(&vertices->GetBufferEntry(index))->Edge;
        pov->m_kFirstEdge = prevDir;
        pov->m_kSecondEdge = right;
        pov->Center = point;
        pov->m_fWeight = 1.0f;
        pov->fRadius = reinterpret_cast<RequestAccess*>(pRequest)->GetFloatAtOffset68() * DAT_010290f0;
        pov->m_usResult =
            reinterpret_cast<PathEdgeVertType*>(&vertices->GetBufferEntry(index))
                ->m_usVertexId;
        pov->m_uiReferenceIndex = -1;
        if (left)
        {
            pov->m_uiListIndex = m_kPrimaryPathPoints.GetSize();
        }
        else
        {
            pov->m_uiListIndex = m_kSecondaryPathPoints.GetSize();
        }
        reinterpret_cast<PathEdgeVertType*>(&vertices->GetBufferEntry(index))
            ->m_uiTrailingValue = pov->m_uiListIndex;
        m_kPathPoints.Add(pov);
        if (left)
        {
            m_kPrimaryPathPoints.Add(pov);
        }
        else
        {
            m_kSecondaryPathPoints.Add(pov);
        }
    }
}

struct VectorUnitizer
{
    void Unitize();
};
struct VectorNegation
{
    NiPoint3 GetNegatedVector() const;
};
extern const double DAT_0106b9e8;
extern const float DAT_01016248;
extern const float DAT_010177e8;
extern const float DAT_01016970;

// Finds a path from origin to target, then probes four lateral offsets around the route to verify clearance, adjusting the hit height if flipB is false.
// @fnv 0x006b25f0
// src: COMMUNITY 0x006b25f0
bool PathSmootherPOVSearch::TripleCheckSegmentAgainstNavMesh(const NavMeshEdgePoint& origin, const NiPoint3& target, NavMeshEdgePoint* hit,
                                   bool flipA, bool flipB, float& afDestinationHeight)
{
    if (!FindPath(origin, target, *hit, afDestinationHeight))
        return false;

    if (m_bUnderwaterPath)
    {
        hit->f14 = target.z;
        return true;
    }

    NiPoint3 delta = target - reinterpret_cast<const NiPoint3&>(origin.fc);
    NiPoint3 kDirection = delta;
    reinterpret_cast<VectorUnitizer*>(&kDirection)->Unitize();

    NiPoint3 offsetAVal, offsetBVal, aOffsetC, offsetD2;

    float spread9;
    if (pRequest->GetFloatAtOffset68() * pRequest->GetFloatAtOffset68() > delta.FUN_004a7290())
        spread9 = delta.FUN_00457990() * DAT_0106b9e8;
    else
        spread9 = pRequest->GetFloatAtOffset68() * DAT_0106b9e8;

    NiPoint3 advance3 = kDirection * spread9;
    NiPoint3 lateral4 = reinterpret_cast<const CrossAccess*>(&DAT_011a9484)->FUN_004b3800(kDirection);

    if (flipA)
    {
        offsetAVal = ((lateral4 * spread9) * DAT_01016248) + (advance3 * DAT_01016248);
        offsetBVal = ((reinterpret_cast<const VectorNegation*>(&lateral4)->GetNegatedVector() * spread9) * DAT_01016248) +
                     (advance3 * DAT_01016248);
    }
    else
    {
        offsetAVal = (lateral4 * pRequest->GetFloatAtOffset68()) * DAT_010177e8;
        offsetBVal =
            (reinterpret_cast<const VectorNegation*>(&lateral4)->GetNegatedVector() * pRequest->GetFloatAtOffset68()) *
            DAT_010177e8;
    }
    if (flipB)
    {
        aOffsetC = ((lateral4 * spread9) * DAT_01016248) - (advance3 * DAT_01016248);
        offsetD2 = ((reinterpret_cast<const VectorNegation*>(&lateral4)->GetNegatedVector() * spread9) * DAT_01016248) -
                   (advance3 * DAT_01016248);
    }
    else
    {
        aOffsetC = (lateral4 * pRequest->GetFloatAtOffset68()) * DAT_010177e8;
        offsetD2 =
            (reinterpret_cast<const VectorNegation*>(&lateral4)->GetNegatedVector() * pRequest->GetFloatAtOffset68()) *
            DAT_010177e8;
    }

    float height2;
    NavMeshEdgePoint firstVal;
    if (!FindPath(origin, reinterpret_cast<const NiPoint3&>(origin.fc) + offsetAVal, firstVal, height2))
        return false;
    NavMeshEdgePoint secondB;
    if (!FindPath(firstVal, target + aOffsetC, secondB, height2))
        return false;
    NavMeshEdgePoint third3;
    if (!FindPath(origin, reinterpret_cast<const NiPoint3&>(origin.fc) + offsetBVal, third3, height2))
        return false;
    NavMeshEdgePoint fourth;
    if (!FindPath(third3, target + offsetD2, fourth, height2))
        return false;
    if (!flipB)
    {
        float savedHeight = hit->f14;
        reinterpret_cast<NavMesh*&>(hit->f0)->GetTriangleHeightAtPoint(reinterpret_cast<unsigned short&>(hit->f4), reinterpret_cast<NiPoint3&>(hit->fc), DAT_01016970,
                                                          DAT_01016970, savedHeight);
        hit->f14 = savedHeight;
    }
    return true;
}
