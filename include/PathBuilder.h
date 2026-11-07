#pragma once

#include "BSSimpleArray.h"
#include "NavMeshTriangleEdgeReference.h"
#include "NavMeshTriangleReference.h"
#include "FindTriangleForLocationFilter.h"
#include "NavMeshPtr.h"

template <class T, unsigned int N> class BSScrapArray;
class Actor;
class Embedded5;
class NavMeshEdgeData;
class NavMeshInfo;
class PacketNodeRecord;
struct OutNodes;
class Param2;
class Param3;
class PathDoorView;
class PathingInfoEntry;
class PathingLocation;
class PathingRequest;
class PathingSolution;
class NiPoint3;
class TESObjectREFR;
class ScrapHeapBuffer;

class PathBuilder
{
public:
    struct VirtualNodeSegment;
    // RTTI PathBuilder::FindTriangleForLocationWaterFilter : FindTriangleForLocationFilter, one vftable slot
    class FindTriangleForLocationWaterFilter : public FindTriangleForLocationFilter
    {
    public:
        FindTriangleForLocationWaterFilter();
    };

    // 52 bytes (src: XBOX_PDB size); the destructor 0x006d0b80 tears down the two arrays at +0x24 and +0x14
    PathingRequest* pRequest;
    PathingSolution* m_pOutputSolution;
    ScrapHeapBuffer* m_pAllocator;
    FindTriangleForLocationWaterFilter m_kTriangleLocationWaterFilter;
    bool m_bPathFound; // +0x10; implicit padding to +0x14 (a char padding array would make a local PathBuilder a /GS buffer: 0x006d0b10)
    BSSimpleArray<const NavMeshInfo*, 1024> DetailedPathInfoList;
    BSSimpleArray<NavMeshPtr, 1024> DetailedPathMeshList;

    ~PathBuilder();

    PathBuilder(PathingRequest*, PathingSolution*);
    bool BuildPath();
    bool PathBuilder_TryBuildStraightPath(PathingLocation*, PathingLocation*);
    int BuildStraightPathUsingRayCasts(PathingLocation&, PathingLocation&, void*);
    bool FindPath(PathingLocation*, PathingLocation*,
                  BSSimpleArray<NavMeshTriangleEdgeReference, 1024>&,
                  BSSimpleArray<NavMeshTriangleReference, 1024>&,
                  BSSimpleArray<NavMeshTriangleEdgeReference, 1024>&,
                  unsigned int, unsigned int);
    bool PathBuilder_RunPathSmoother(PathingLocation&, PathingLocation&,
                     BSSimpleArray<NavMeshTriangleEdgeReference, 1024>&,
                     BSSimpleArray<NavMeshTriangleReference, 1024>&,
                     BSSimpleArray<NavMeshTriangleEdgeReference, 1024>&);
    bool BuildPathSpans(OutNodes&);
    bool BuildPathSpans(BSScrapArray<NavMeshEdgeData, 1024>&); // exe 0x006ca500
    bool BuildPathSegment(unsigned int, unsigned int);
    bool PathBuilder_BuildTeleportDoorPath();
    bool BuildActorPathSegments(Actor*);
    bool BuildPathSpans(BSSimpleArray<NavMeshEdgeData, 1024>&);
    bool TryConnectPathNodes(unsigned int, unsigned int);
    bool IsNavMeshInfoCompatible(const NavMeshInfo*, const NavMeshInfo*);
    bool CanPathBetweenNavMeshes(const NavMeshInfo*, const NavMeshInfo*);
    bool BuildPathForActor(Actor*, unsigned int);
    void* AdvanceCounter();
    PathingInfoEntry* GetPathingInfoEntry(PathingInfoEntry&);
    int AppendPathNodeLocations(int, BSSimpleArray<PathingLocation, 1024>*, TESObjectREFR*);
    bool BuildPathNodeLocation(PacketNodeRecord*, PacketNodeRecord*, PathingLocation&);
    int AppendNearbyPathLocations(PathingLocation*, BSSimpleArray<PathingLocation, 1024>*, int, TESObjectREFR*);
    void* GetElementAddress30_006e8f40(void*);
    void* BSSimpleArray_VirtualPathingNode_1024_GetAt(void* a1);
    bool FindPath(const NiPoint3&, const NiPoint3&, void*, PathDoorView*);
    void* BSSimpleArray_VirtualPathingNode_1024_GetLast();
    int ProcessAndReturnValue_00d9a2a0(int a1, Param2* a2, Param3* a3, int a4, Embedded5* a5,
                     int a6, int a7, volatile int a8);
};
