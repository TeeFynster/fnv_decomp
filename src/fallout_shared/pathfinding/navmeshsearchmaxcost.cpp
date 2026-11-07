#include "../../../include/NavMeshSearchMaxCost.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathBuilderDetailedPathInfos.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/DoorAccessData.h"

// src/fallout_shared/pathfinding/navmeshsearchmaxcost.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchmaxcost.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl _Deallocate(void*);
extern void* const NavMeshSearchMaxCost_vftable[];

// Destroys the search, frees this when flags has bit 1 set, and returns this.
// @fnv 0x006ab450
void* NavMeshSearchMaxCost::Destroy(unsigned int flags)
{
    UpdateFields_006ab480();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x006abb90
int __thiscall NavMeshSearchMaxCost::GetField2048()
{
    return unk2048;
}

// @fnv 0x006abb60
// src: XBOX_PDB 0x006abb60
bool __thiscall NavMeshSearchMaxCost::IsGoalNode_006abb60(const SearchNode* apNode)
{
    if (!hasGoal)
        return false;
    else
        return NavMeshSearch::HasReachedGoal(apNode);
}

struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
};
extern unsigned int DAT_010a2720;
struct FUN_006abcb0_shell
{
    char _pad[16];
    ScrapHeapBuffer* heap;
    void* __thiscall BSScrapArray_NavMeshSearchNode_1024_Allocate(unsigned int);
};
// Allocates n blocks of 0x14 bytes from the heap and returns the pointer.
// @fnv 0x006abcb0
// src: COMMUNITY 0x006abcb0
void* __thiscall FUN_006abcb0_shell::BSScrapArray_NavMeshSearchNode_1024_Allocate(unsigned int auiCount)
{
    void* tmp;
    tmp = heap->Allocate(auiCount * 0x14, DAT_010a2720);
    return tmp;
}

namespace fnv_006abce0 {
struct ScrapHeapBuffer
{
    void* __thiscall Allocate(unsigned int, unsigned int);
    void __thiscall Deallocate(void*);
};
// Exe 0x006abce0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshsearchmaxcostOffset08View
{
    unsigned int __thiscall GetFlags();
};
extern unsigned int DAT_010a2720;
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct FUN_006abce0_shell
{
    char _pad[0x10];
    ScrapHeapBuffer* heap;
    void* __thiscall BSScrapArray_NavMeshSearchNode_1024_Reallocate(void*, unsigned int);
};
// Allocates count*0x14 bytes, copies GetFlags()*0x14 bytes from src into it, frees src, and returns the new buffer.
// @fnv 0x006abce0
// src: COMMUNITY 0x006abce0
void* __thiscall FUN_006abce0_shell::BSScrapArray_NavMeshSearchNode_1024_Reallocate(void* pSource, unsigned int count)
{
    void* dst = heap->Allocate(count * 0x14, DAT_010a2720);
    __memcpy(dst, pSource, ((NavmeshsearchmaxcostOffset08View*)this)->GetFlags() * 0x14);
    heap->Deallocate(pSource);
    return dst;
}
}  // namespace fnv_006abce0

extern int DAT_0106b8c8;

struct GlobalObject_00869f00
{
    void __thiscall Clear(bool);
};

struct FUN_006abdc0_shell
{
    int* p;
    void __thiscall ResetVirtualTableAndClear_006abdc0();
};

// @fnv 0x006abdc0
// src: GUESS 0x006abdc0 (confidence: medium)
void __thiscall FUN_006abdc0_shell::ResetVirtualTableAndClear_006abdc0()
{
    p = &DAT_0106b8c8;
    ((GlobalObject_00869f00*)this)->Clear(true);
}

namespace fnv_006abde0 {
struct GlobalObject_00869f00
{
    void __thiscall Clear(bool);
};
struct FUN_006abdc0
{
    virtual ~FUN_006abdc0();
};
struct FUN_006abde0 : FUN_006abdc0
{
    virtual ~FUN_006abde0();
};
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x006abde0
FUN_006abde0::~FUN_006abde0()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_006abde0

namespace fnv_006abc30 {
struct GlobalObject_00869f00
{
    void __thiscall Clear(bool);
};
extern void* DAT_0106b8a0;

struct FUN_006abc30_shell
{
    void __thiscall SetVtableAndProcessState_006abc30();
};

// @fnv 0x006abc30
// src: GUESS 0x006abc30 (confidence: low)
void __thiscall FUN_006abc30_shell::SetVtableAndProcessState_006abc30()
{
    *(void**)this = &DAT_0106b8a0;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_006abc30

struct FUN_006abc30_Class
{
    virtual ~FUN_006abc30_Class();
};
struct FUN_006abc50 : FUN_006abc30_Class
{
    ~FUN_006abc50();
};
// @fnv 0x006abc50
FUN_006abc50::~FUN_006abc50()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}

struct FUN_006abf60
{
    virtual ~FUN_006abf60();
    FUN_006abf60();
    int unk04;
    int unk08;
    int unk0c;
};
struct FUN_00aa42e0_shell
{
    void* __thiscall FUN_00aa42e0();
};
FUN_00aa42e0_shell* __cdecl MemoryManager_Instance();
struct FUN_006abbb0 : FUN_006abf60
{
    void* unk10;
    FUN_006abbb0();
    virtual ~FUN_006abbb0();
    void __thiscall BSSimpleArray_WeaponData_1024_InitialSetup(int, int);
};
// Initializes unk10 from FUN_00401020()->FUN_00aa42e0() and calls FUN_009a3d00(0, 0).
// @fnv 0x006abbb0
FUN_006abbb0::FUN_006abbb0()
{
    unk10 = MemoryManager_Instance()->FUN_00aa42e0();
    BSSimpleArray_WeaponData_1024_InitialSetup(0, 0);
}

namespace fnv_006abd40 {
void* __cdecl MemoryManager_Instance();

struct NavMeshSearchHeapObj
{
    void* FUN_00aa42e0();
};

struct NavMeshSearchGraphBase
{
    NavMeshSearchGraphBase();
    virtual void unk00();
    ~NavMeshSearchGraphBase();
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_006abd40 : NavMeshSearchGraphBase
{
    void* m_10;

    FUN_006abd40();
    void BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(unsigned int a, unsigned int b);
};

// @fnv 0x006abd40
FUN_006abd40::FUN_006abd40()
{
    m_10 = ((NavMeshSearchHeapObj*)MemoryManager_Instance())->FUN_00aa42e0();
    BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(0, 0);
}
}  // namespace fnv_006abd40

struct NavMeshSearchLocation
{
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    NiPoint3 kPosition;
    NiPoint3* FastNavMeshTriLocation_GetLocation(NiPoint3* apResult);
    NiPoint3 FastNavMeshTriLocation_GetLocation();
};
// @fnv 0x006ab4a0
bool NavMeshSearchMaxCost::StartSearch(int aiSearchType, NavMeshSearchLocation* apStart, PathingLocation* apGoal,
                                     PathBuilderDetailedPathInfos* apInfos, PathBuilderDetailedPathInfos* apAltInfos)
{
    (*(NavMeshSearchLocation*)&unk205c) = *apStart;
    unk2058 = aiSearchType;
    apInfos->Clear(false);
    apAltInfos->Clear(false);
    FUN_006a7c40();
    if (!apGoal->PathingLocation_QUnused() && apGoal->FUN_006dd6f0(false))
    {
        NavMeshPtr spGoalNavMesh;
        unsigned short m_usTriangleID;
        if (apGoal->FUN_006dd640(&spGoalNavMesh, &m_usTriangleID))
        {
            (*(NavMeshSearchLocation*)&unk2070).m_pLocationNavMesh = spGoalNavMesh;
            (*(NavMeshSearchLocation*)&unk2070).m_usTriangleID = m_usTriangleID;
            float kGoalPos[3];
            (*(NavMeshSearchLocation*)&unk2070).m_pLocationNavMesh->FUN_00558220((NiPoint3*)kGoalPos, (*(NavMeshSearchLocation*)&unk2070).m_usTriangleID);
            (*(NavMeshSearchLocation*)&unk2070).kPosition.x = kGoalPos[0];
            (*(NavMeshSearchLocation*)&unk2070).kPosition.y = kGoalPos[1];
            (*(NavMeshSearchLocation*)&unk2070).kPosition.z = kGoalPos[2];
            bHasGoal = true;
        }
    }
    {
        float kStartPos[3];
        float kTmpGoalPos[3];
        FUN_006a7c90(GetKeyForNode_006a94f0(apStart->m_pLocationNavMesh, apStart->m_usTriangleID), apStart,
                     (*(*(NavMeshSearchLocation*)&unk205c).FastNavMeshTriLocation_GetLocation((NiPoint3*)kStartPos) - *(*(NavMeshSearchLocation*)&unk2070).FastNavMeshTriLocation_GetLocation((NiPoint3*)kTmpGoalPos)).Length());
    }
    bool bFoundPath = FUN_006a7d60(apInfos, apAltInfos, false);
    return bFoundPath;
}

struct Mesh
{
    NiPoint3 Center(unsigned short);
};
struct Location
{
    Mesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    float x, y, z;
    NiPoint3 Center();
};
struct OpenSet
{
    int a, b, c, d, e;
    OpenSet();
    ~OpenSet();
};
struct ClosedSet
{
    int a, b, c, d, e;
    ClosedSet();
    ~ClosedSet();
};
struct Node
{
    int a, b;
    Location location;
};
// Sets start and goal locations from mesh centers, runs the search, and returns the fallback point or result center.
// @fnv 0x006ab670
NiPoint3 NavMeshSearchMaxCost::FindPath(int unused, Location* initial, NiPoint3* fallback, Location* target, float cost)
{
    (*(Location*)&unk205c).mesh = initial->mesh;
    (*(Location*)&unk205c).triangle = initial->triangle;
    NiPoint3 center = (*(Location*)&unk205c).mesh->Center((*(Location*)&unk205c).triangle);
    (*(Location*)&unk205c).x = center.x;
    (*(Location*)&unk205c).y = center.y;
    (*(Location*)&unk205c).z = center.z;
    Add(Index((*(Location*)&unk205c).mesh, (*(Location*)&unk205c).triangle), &(*(Location*)&unk205c), ((*(Location*)&unk205c).Center() - (*(Location*)&unk2070).Center()).Length());
    if (target->mesh || target->triangle != 0xffff)
    {
        hasGoal = true;
        (*(Location*)&unk2070).mesh = target->mesh;
        (*(Location*)&unk2070).triangle = target->triangle;
        center = (*(Location*)&unk2070).mesh->Center((*(Location*)&unk2070).triangle);
        (*(Location*)&unk2070).x = center.x;
        (*(Location*)&unk2070).y = center.y;
        (*(Location*)&unk2070).z = center.z;
    }
    else
    {
        hasGoal = false;
    }
    maxCost = cost;
    OpenSet open;
    ClosedSet closed_2;
    if (Run(&open, &closed_2, 0))
        return *fallback;
    else
        return Result()->location.Center();
}

namespace fnv_006ab8e0 {
struct EdgeExtraInfo
{
    int type;
};
// NavMeshTriangleView: unit-local view (declares only what 0x006ab8e0 calls), not the shared NavMeshTriangle; renamed so no local type keeps the shared name
struct NavMeshTriangleView
{
    bool FUN_00691140(unsigned int);
};
}  // namespace fnv_006ab8e0

// NavMeshAStarNode: unit-local stand-in for the A* search node (AStarNode<NavMeshSearchNode,NavMeshSearchLink>; src: XBOX_PDB), not a NavMeshTriangleReference: 0x006ab8e0 ExpandNeighborNodes reads cost at +0 and the location at +8, writes the parent fields at +0x1c..+0x24
struct NavMeshAStarNode
{
    float cost;
    unsigned int unk04;
    NavMeshSearchLocation location;
    NavMesh* parentMesh;
    unsigned short parentTriangle;
    unsigned short unk22;
    int parentEdge;
};
namespace fnv_006ab8e0 {
struct DoorBase
{
    bool FUN_00518000();
};
struct Door
{
    DoorBase* BGSSaveFormBuffer_GetForm();
};
Door* __cdecl TESForm_GetFormByNumericID(unsigned int);
}  // namespace fnv_006ab8e0

struct NodeOutput
{
    unsigned int FUN_007cb2e0(NavMeshTriangleReference*&);
};

// @fnv 0x006ab8e0
bool NavMeshSearchMaxCost::ExpandNeighborNodes(NavMeshTriangleReference* source, NodeOutput* output)
{
    using namespace fnv_006ab8e0;
    for (int i = 0; i < 3; ++i)
    {
        NavMesh* mesh;
        unsigned short triangle;
        int linked;
        if (reinterpret_cast<NavMeshAStarNode*>(source)->location.m_pLocationNavMesh->FindAdjacentEdge(reinterpret_cast<NavMeshAStarNode*>(source)->location.m_usTriangleID, i, &mesh, &triangle, &linked))
        {
            fnv_006ab8e0::EdgeExtraInfo* edge = (fnv_006ab8e0::EdgeExtraInfo*)reinterpret_cast<NavMeshAStarNode*>(source)->location.m_pLocationNavMesh->GetEdgeExtraInfo(reinterpret_cast<NavMeshAStarNode*>(source)->location.m_usTriangleID, i);
            if (edge && edge->type == 1)
                continue;
            NiPoint3 center = mesh->FUN_00558220(triangle);
            float cost = (center - reinterpret_cast<NavMeshAStarNode*>(source)->location.FastNavMeshTriLocation_GetLocation()).NiPoint3_XYLength() + reinterpret_cast<NavMeshAStarNode*>(source)->cost;
            if (cost > maxCost)
                continue;
            if (((fnv_006ab8e0::NavMeshTriangleView*)mesh->FUN_005582f0(triangle))->FUN_00691140(0x1000))
            {
                if (((PathingRequest*)unk2058)->FUN_0073cb80())
                {
                    continue;
                }
                else
                {
                    unsigned int door = *mesh->FUN_00699af0(triangle);
                    Door* doorId = TESForm_GetFormByNumericID(door);
                    if (doorId)
                    {
                        const PathingActorData* actor;
                        bool unlocked;
                        {
                            DoorAccessData lock(reinterpret_cast<TESObjectREFR*>(doorId));
                            actor = ((PathingRequest*)unk2058)->GetActorLockData();
                            if (!lock.CanUnlockDoor(actor, reinterpret_cast<TESObjectREFR*>(doorId), unlocked))
                                continue;
                            if (doorId->BGSSaveFormBuffer_GetForm()->FUN_00518000())
                                continue;
                        }
                    }
                }
            }
            NavMeshTriangleReference* nodeA;
            switch (FUN_006a7e00(GetKeyForNode_006a94f0(mesh, triangle), cost, &nodeA))
            {
            case 0:
                FUN_006a6ef0(nodeA, mesh, triangle);
            case 1:
                reinterpret_cast<NavMeshAStarNode*>(nodeA)->parentMesh = reinterpret_cast<NavMeshAStarNode*>(source)->location.m_pLocationNavMesh;
                reinterpret_cast<NavMeshAStarNode*>(nodeA)->parentTriangle = reinterpret_cast<NavMeshAStarNode*>(source)->location.m_usTriangleID;
                reinterpret_cast<NavMeshAStarNode*>(nodeA)->parentEdge = i;
                output->FUN_007cb2e0(nodeA);
                break;
            }
        }
    }
    return true;
}
// This cleanup entry calls FUN_006a6b00 rather than the shared base destructor.

// @fnv 0x006ab480
// src: GUESS 0x006ab480 (confidence: low)
void NavMeshSearchMaxCost::UpdateFields_006ab480()
{
    *(void* const**)this = NavMeshSearchMaxCost_vftable;
    FUN_006a6b00();
}
