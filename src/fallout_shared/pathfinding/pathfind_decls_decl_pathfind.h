
// Shared classes come from the canonical include/ headers: NiPoint3, AutoMemContext/MEM_CONTEXT, NiTPointerMap,
// MobileObject/TESObjectREFR forward declarations. Explicit ../../../include/ paths: pathfinding/PathingLocation.h
// and src/fallout_shared/layout_support.h shadow the canonical names (case-insensitive include lookup under Wine).
// Unit-local supersets of canonical types (same layout), for members the canonical headers do not declare yet:
//   PathingLocation: ctors/dtor, copy ctor, operator=, GetLocation and the navmesh queries used by matched code.
//   BSSimpleArray: Add.   NiPointer: smart-pointer API (canonical NiPointer bodies need a complete T).
#define NiPointer FNV_NiPointer_Canonical
#define PathingLocation FNV_PathingLocation_Canonical
#include "../../../include/layout_support.h"
#include "../../../include/NiPoint3.h"
#undef PathingLocation
#undef NiPointer
// packet's first-definition-wins type index shows them (not the renamed canonical text).
#include "pathfind_local_types_decl_pathfind.h"
// include/PathingLocation.h forwards to the shared class pathfind_local_types.h already read
#include "../../../include/AutoMemContext.h"
#pragma pack(push, 4)
class PathfindQueueStorage
{
  public:
    void ProcessArray_RemoveActor_0096aaf0(MobileObject*, int);
};
class ActorDeletionQueue
{
    unsigned int pad;
    PathfindQueueStorage storage;

  public:
    void ProcessLists_RemoveReference(MobileObject*, int);
};
class PathingLocation;
class FindTriangleForLocationFilter;
class NavMesh
{
  public:
    NiPoint3 GetNavMeshData(unsigned short);
};
class NavMeshPtr : public NiPointer<NavMesh>
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
};
FNV_STATIC_ASSERT(sizeof(NavMeshPtr) == 4);
class PathingLocationProxy
{
  protected:
    void* table;

  public:
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
};
#pragma pack(pop)
class NavMesh;
class PathingActorData;
class PathingPath
{
  public:
    void* a;
    unsigned int b, c, d;
    void* e;
    unsigned int f, g, h;
    float i, j, k, l, m, n;
    PathingPath();
    ~PathingPath();
    float CalculatePathDistance();
};
class TESObjectREFR;
class PathingSolution;
enum PATHING_REQUEST_TYPE
{
    RequestLocation = 0,
    RequestClosePoint = 3,
    RequestHide = 4,
    RequestFlee = 5,
    RequestLOS = 6,
    RequestOptimal = 7,
    RequestUnknown = 8
};
class PathingRequest
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual PATHING_REQUEST_TYPE GetType();
};
class PathingRequestClosePoint : public PathingRequest
{
};
class PathingRequestHide : public PathingRequest
{
};
class PathingRequestFlee : public PathingRequest
{
};
class PathingRequestLOS : public PathingRequest
{
};
class PathingRequestOptimalLocation : public PathingRequest
{
};
class PathingRequestUnknown : public PathingRequest
{
};
bool Pathing_Pathfind(PathingRequest*, PathingSolution*);
bool Pathing_BuildFleePath(PathingRequestClosePoint*, PathingSolution*);
bool Pathing_BuildCoveredMovePath(PathingRequestUnknown*, PathingSolution*);
class Pathing
{
    unsigned char pad[28];
    NiTPointerMap<unsigned int, TESObjectREFR*> map;

  public:
    static bool BuildPath(PathingRequest*, PathingSolution*);
    static bool CalculateHidePath(PathingRequestHide*, PathingSolution*);
    static bool CalculateFleePath(PathingRequestFlee*, PathingSolution*);
    static bool BuildLineOfSightPath(PathingRequestLOS*, PathingSolution*);
    static bool SelectOptimalLocation(PathingRequestOptimalLocation*, PathingSolution*);
    TESObjectREFR* FindReferenceByFormId(unsigned int);
    class CheckLineOfSightFilter;
    enum TELEPORT_DOOR_PATH_RESTRICTION
    {
        RestrictionNone = 0
    };
    enum DOOR_LOCK_DISPOSITION
    {
        LockDefault = 0
    };
    static bool FindRouteBetweenLocations(const PathingLocation&, const PathingLocation&, PathingPath*,
                                          TELEPORT_DOOR_PATH_RESTRICTION, float, PathingActorData*,
                                          DOOR_LOCK_DISPOSITION);
    static bool FindClosestPathingPoint(TESWorldSpace*, TESObjectCELL*, const NiPoint3&, NiPoint3*);
    static float FindPathDistance(const PathingLocation&, const PathingLocation&, float, PathingActorData*,
                                  DOOR_LOCK_DISPOSITION);
    static bool FindPathingLocationOnNavMesh(PathingLocation&, const NiPoint3&, NavMesh*, unsigned short,
                                             PathingLocation*, CheckLineOfSightFilter*);
    static bool FindPathingLocation(PathingLocation&, const NiPoint3&, PathingLocation*, CheckLineOfSightFilter*);
};
class TESPackage
{
  public:
    int GetProcedureType();
};
class PathingGraphNode
{
  public:
    PathingLocation& FUN_00717e50();
};
class PacketNodeRecord : public PathingGraphNode
{
  public:
    bool VirtualPathingNode_HasActualLocation();
};
class PathingSolution
{
  public:
    PacketNodeRecord* GetVirtualNode(unsigned int);
};
template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    T& GetAt(int index);
    unsigned int Add(const T&);
};
int CollectNearbyEdges(PathingLocation*, int, TESObjectREFR*);
class PathBuilder
{
  public:
    void* field0;
    PathingSolution* solution;
    void* field8;
    void* fieldC;
    bool skipTransitions;
    int AppendPathNodeLocations(int, BSSimpleArray<PathingLocation, 1024>*, TESObjectREFR*);
    bool BuildPathNodeLocation(PacketNodeRecord*, PacketNodeRecord*, PathingLocation&);
    int AppendNearbyPathLocations(PathingLocation*, BSSimpleArray<PathingLocation, 1024>*, int, TESObjectREFR*);
};
