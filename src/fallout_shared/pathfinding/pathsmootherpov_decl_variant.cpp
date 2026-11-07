
// src/fallout_shared/pathfinding/pathsmootherpov_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006b23d0: the skeleton of src/fallout_shared/pathfinding/pathsmootherpov.cpp
// with declarations corrected to what the original code does (pathsmootherpov_decls.h: PathSmootherPOVSearch += bool FindPath(const NavMeshEdgePoint& edge, const NiPoint3& point, NavMeshEdgePoint& location, float& cost);). Move the function to its real unit once
// that unit declares it this way.

#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshEdgeData.h"
#include "../../../include/NavMeshEdgePoint.h"
#include "../../../include/NavMeshEdgeVertexPair.h"
#include "../../../include/NavMeshPOVSearch.h"
#include "../../../include/NavMeshTriangleEdgeReference.h"
#include "../../../include/NavMeshTriangleReference.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathSmootherPOVAvoidanceNode.h"
#include "../../../include/PathSmootherPOVSearch.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/TES.h"

#include "pathsmootherpov_decls_decl_pathsmootherpov.h"
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

// @fnv 0x006b23d0
// src: COMMUNITY 0x006b23d0
bool PathSmootherPOVSearch::DoubleCheckArcAgainstNavMesh(const NavMeshEdgePoint& edge, Sphere& sphere, CircularArc arc)
{
    float firstRadius1 = arc.Direction == ANGLE_DIRECTION_AD_CCW ? sphere.Radius - pRequest->GetFloatAtOffset68() * 0.9f
                                                 : sphere.Radius + pRequest->GetFloatAtOffset68() * 0.9f;
    NiPoint3 firstDirection0 = arc.Start.MakePointOnCircle(firstRadius1);
    NavMeshEdgePoint firstLocation6;
    Sphere firstSphere2(sphere.Center, firstRadius1);
    float cost13 = 0.0f;
    if (!FindPath(edge, sphere.Center + firstDirection0, firstLocation6, cost13))
        return false;
    NavMeshEdgePoint firstExit15;
    if (!CheckArcAgainstNavMesh(firstLocation6, firstSphere2, arc, &firstExit15))
        return false;

    float secondRadius1 = arc.Direction == ANGLE_DIRECTION_AD_CCW ? sphere.Radius + pRequest->GetFloatAtOffset68() * 0.9f
                                                  : sphere.Radius - pRequest->GetFloatAtOffset68() * 0.9f;
    NiPoint3 secondDirection2 = arc.Start.MakePointOnCircle(secondRadius1);
    NavMeshEdgePoint secondLocation2;
    Sphere secondSphere12(sphere.Center, secondRadius1);
    if (!FindPath(edge, sphere.Center + secondDirection2, secondLocation2, cost13))
        return false;
    NavMeshEdgePoint secondExit9;
    if (!CheckArcAgainstNavMesh(secondLocation2, secondSphere12, arc, &secondExit9))
        return false;
    return true;
}
