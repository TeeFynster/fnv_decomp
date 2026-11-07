#include "../../../include/NavMeshInfo.h"
// fallout_shared/pathfinding/pathbuilder.cpp: PathBuilder, PathBuilderCore, CheckLineOfSightFilterWater and shared pathing arrays (60 functions)

#include <stddef.h>
#include "../../../include/SettingT.h"
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#include "../../../include/BSStringT.h"
#include "../../../include/BSSimpleList.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/NiPointer.h"
#include "../../../include/FindTriangleForLocationFilter.h"
#include "../../../include/MemoryManager.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshEdgeData.h"
#include "../../../include/NavMeshTriangleReference.h"
#include "../../../include/NavMeshTriangleEdgeReference.h"
#include "../../../include/NavMeshGrid.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/TESRecipe.h"
#include "../../../include/TESObjectCELL.h"
class NavMeshInfo_const;
#include "../../../include/NiTMap.h"

#include "PointStorage.h"
#include "../../../include/NiColor.h"

#include "../../../include/NiPoint3.h"
#include "../../../include/PathingLocation.h"

#include "../../../include/NavMeshTriangle.h"
#include "../../../include/PathingAvoidNode.h"
#include "../../../include/NavMeshStaticAvoidNode.h"
#include "../../../include/PathingGraphNode.h"
#include "pathbuilder_types_CheckLineOfSightFilterWater.h"
#include "pathbuilder_types_PathBuilder.h"
#include "../../../include/PathingInfoEntry.h"
#include "../../../include/PathingInfoParams.h"
#include "pathbuilder_decls.h"

#include "../../../include/PathingSearchRayCast.h"

__if_not_exists(BaseFormComponent::Init)
{
#include "../../../include/BaseFormComponent.h"
}
#include "../../../include/TESFullName.h"
#include "../../../include/TESTexture.h"
#include "../../../include/BSWin32TaskletManager.h"

// @fnv 0x006cd5c0
bool CheckLineOfSightFilterWater::IsLineOfSightClear(unsigned int firstMesh, unsigned int firstTriangle,
                                                     unsigned int firstEdge, unsigned int secondMesh,
                                                     unsigned int secondTriangle, unsigned int secondEdge)
{
    NavMeshTriangle* triangle =
        ((PathingAvoidNode*)secondMesh)->GetAvoidanceAtPoint((unsigned short)secondTriangle);
    if (triangle->NavMeshTriangle_IsWater())
        return false;
    if (triangle->IsNoLargeCreature() && m_bCheckWater)
        return false;
    if (triangle->FUN_00691140(0x80000000))
        return false;
    if (triangle->FUN_00691140(0x1000))
        return false;
    return true;
}

// @fnv 0x006c8d30
PathBuilder::PathBuilder(PathingRequest* request, PathingSolution* solution)
{
    m_pAllocator = MemoryManager_Instance()->GetGeneralAllocator();
    pRequest = request;
    m_pOutputSolution = solution;
    m_bPathFound = false;
}

// Builds a path by comparing navmesh info from the request and its conditions, then validates the actor; returns false on mismatch or validation failure.
// @fnv 0x006c8e10
bool PathBuilder::BuildPath()
{
    struct BuildPathLocals
    {
        Actor* actor;
        unsigned int unused;
    } buildPathLocals;
    buildPathLocals.actor = 0;
    buildPathLocals.unused = 0;
    pRequest->GetOffsetC().ResetLocation();
    ((PathingLocation*)((TESRecipe*)pRequest)->GetConditions())->ResetLocation();
    if (!m_pOutputSolution->PathingSolution_GetVirtualNodeCount())
    {
        const NavMeshInfo* conditionInfo;
        const NavMeshInfo* requestInfo;
        conditionInfo = 0;
        requestInfo = 0;
        if (((PathingLocation&)pRequest->GetOffsetC()).FindContainingTriangle(&m_kTriangleLocationWaterFilter))
            conditionInfo = (const NavMeshInfo*)((PathingLocation&)pRequest->GetOffsetC()).GetAssociatedNavMesh();
        if (((PathingLocation*)((TESRecipe*)pRequest)->GetConditions())
                ->FindContainingTriangle(&m_kTriangleLocationWaterFilter))
            requestInfo = (const NavMeshInfo*)((PathingLocation*)((TESRecipe*)pRequest)->GetConditions())->GetAssociatedNavMesh();
        if (!IsNavMeshInfoCompatible(conditionInfo, requestInfo) && !m_pOutputSolution->PathingSolution_GetVirtualNodeCount())
            return false;
    }
    else
    {
        ((PathingLocation&)pRequest->GetOffsetC()).FindContainingTriangle(&m_kTriangleLocationWaterFilter);
        ((PathingLocation*)((TESRecipe*)pRequest)->GetConditions())
            ->FindContainingTriangle(&m_kTriangleLocationWaterFilter);
    }
    if (!BuildPathForActor(buildPathLocals.actor, 0))
        return false;
    return true;
}

// @fnv 0x006ca850
bool PathBuilder::BuildActorPathSegments(Actor* actor)
{
    unsigned int unused;
    BSScrapArray<NavMeshEdgeData, 1024> segments(0, 0, reinterpret_cast<unsigned int>(m_pAllocator));
    if (!BuildPathSpans(segments))
        return false;
    bool allowIncomplete = pRequest->GetByteAtOffsetA1();
    if (((GlobalObject_00869f00*)&segments)->GetSize() > 0x100063)
        unused = 0;
    for (unsigned int i = 0; i < ((GlobalObject_00869f00*)&segments)->GetSize(); ++i)
    {
        bool built = false;
        NavMeshEdgeData* segment = &segments.Object_GetIndexedValue_006a1440(i);
        if (*(bool*)((char*)segment + 8))
        {
            if (i > 0 && *(bool*)((char*)&segments.Object_GetIndexedValue_006a1440(i - 1) + 8) && !allowIncomplete)
            {
                m_pOutputSolution->SetByteAtOffset40(1);
                return false;
            }
            else
            {
                built = TryConnectPathNodes(*(unsigned int*)segment, *(unsigned int*)((char*)segment + 4));
                if (!built && !allowIncomplete)
                    return false;
            }
        }
        if (!built)
        {
            if (!BuildPathSegment(*(unsigned int*)segment, *(unsigned int*)((char*)segment + 4)))
                return false;
        }
    }
    return true;
}

void __fastcall FindTriangleForLocationFilter_FindTriangleForLocationFilter(void*);
extern int DAT_0106c92c;

// @fnv 0x006c8dd0
// src: EXE 0x006c8dd0
void* __fastcall PathBuilder_FindTriangleForLocationWaterFilter_FindTriangleForLocationWaterFilter(void* pThis)
{
    FindTriangleForLocationFilter_FindTriangleForLocationFilter(pThis);
    *(int**)pThis = &DAT_0106c92c;
    return pThis;
}

extern int DAT_0106c934;

// @fnv 0x006c8df0
// src: XBOX_PDB 0x006c8df0
void* __fastcall FindTriangleForLocationFilter_FindTriangleForLocationFilter(void** pThis)
{
    *pThis = &DAT_0106c934;
    return pThis;
}

struct Item48
{
    char pad[0x30];
    static void* __cdecl operator new(unsigned int, void*);
    static void __cdecl operator delete(void*, void*);
    Item48(const PathingInfoEntry&);
};

// @fnv 0x006c90d0
PathingInfoEntry* PathingSolution::GetPathingInfoEntry(PathingInfoEntry& aItem)
{
    void* v1 = ((PathBuilder*)((char*)this + 8))->AdvanceCounter();
    void* v2 = ((PathBuilder*)((char*)this + 8))->GetElementAddress30_006e8f40(v1);
    new (v2) Item48(aItem);
    return (PathingInfoEntry*)v1;
}

struct Dummy_006cf120
{
    void FUN_006cf120(int);
};

struct Dummy_006c93a0
{
    int pad[6];
    int f18;
    int f1c;
    Dummy_006cf120 f20;
};

// Calls FUN_006cf120 with 1, then sets f18 and f1c to -1.
// @fnv 0x006c93a0
// src: COMMUNITY 0x006c93a0
void __fastcall PathingSolution_ClearCurrentDetailedPath(Dummy_006c93a0* pThis)
{
    pThis->f20.FUN_006cf120(1);
    pThis->f18 = -1;
    pThis->f1c = -1;
}

struct PathingActorData;

// @fnv 0x006c9900
// src: XBOX_PDB 0x006c9900
PathingActorData* PathingRequest::GetActorLockData()
{
    return &PathingActorState;
}

// @fnv 0x006ca4c0
// src: COMMUNITY 0x006ca4c0
char __fastcall PathingRequest_GetInitialPathHeading(char* this_ptr)
{
    return this_ptr[0xa0];
}

// @fnv 0x006ca4e0
float __fastcall GetField90Float(char* pThis)
{
    return *(float*)(pThis + 0x90);
}

// @fnv 0x006ca830
// src: XBOX_PDB 0x006ca830
bool __fastcall VirtualPathingNode_HasNavMesh(const unsigned int* puiValue)
{
    return (*puiValue & 1) == 1;
}

// @fnv 0x006cac70
// src: COMMUNITY 0x006cac70
bool __fastcall VirtualPathingNode_HasActualLocation(const int* pFlags)
{
    return (*pFlags & 2) == 2;
}

extern int DAT_0106c93c;
void __fastcall SetVtable(void* pThis);

// @fnv 0x006cd5a0
// src: GUESS 0x006cd5a0 (confidence: low)
void* __fastcall Object_InitializeFields_006cd5a0(void* pThis)
{
    SetVtable(pThis);
    *(int**)pThis = &DAT_0106c93c;
    return pThis;
}

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct IDebugText;
struct blob24
{
    char b[24];
};
// @fnv 0x006e2330
// src: XBOX_PDB 0x006e2330
bool PathingGraphNode::PathingNode_IsTeleportDoorNode()
{
    return (iFlags & 3) == 3;
}

struct BGSEncounterZone;
class BGSLoadFormBuffer;
struct BGSMusicType;
class BGSSaveFormBuffer;
class BGSTerrainManager;
class BSPortalGraph;
class FormRecordHeader;
class IDebugText;
class TESClimate;
class TESFile;
struct TESImageSpace;
class TESObject;
struct TESWaterForm;
class TESWorldSpace;
namespace fnv_006c99c0 {
struct ImpactSwap;
struct GlobalVariableForm;
struct TESTerrainLODManager;
struct PacketNodeRecord;
struct PointerPairData;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
struct Item48
{
    char data[0x30];
    Item48(void* a, TESObjectREFR* b);
    static void* operator new(unsigned int, void*);
    static void operator delete(void*, void*);
};

}  // namespace fnv_006c99c0

// Gets an index and memory from the PathBuilder at offset 8, constructs an Item48 in that memory from a and b, and returns the index.
// @fnv 0x006c99c0
unsigned int PathingSolution::AddPathingItem(void* a, TESObjectREFR* pRefr)
{
    void* idx = ((PathBuilder*)((char*)this + 8))->AdvanceCounter();
    void* mem = ((PathBuilder*)((char*)this + 8))->GetElementAddress30_006e8f40(idx);
    new (mem) fnv_006c99c0::Item48(a, pRefr);
    return (unsigned int)idx;
}

struct FUN_006f4d00
{
    unsigned int flags;
    PathingLocation loc;
    int pad[1];
    FUN_006f4d00(const PathingLocation& l);
};

// @fnv 0x006f4d00
FUN_006f4d00::FUN_006f4d00(const PathingLocation& l)
{
    loc.PathingLocation::operator=(l);
    pad[0] = 0;
    flags = 2;
    if (((PathingLocation*)&loc)->FindContainingTriangle(0))
        flags |= 1;
}

// @fnv 0x006abfc0
template <> BSSimpleArray<PathingLocation, 1024>::~BSSimpleArray()
{
    Clear(true);
}

namespace fnv_006c93d0 {
struct Dummy_006c93a0
{
    int pad;
    void* vtable;
};

void __fastcall PathingSolution_ClearCurrentDetailedPath(Dummy_006c93a0*);

// @fnv 0x006c93d0
// src: COMMUNITY 0x006c93d0
int __fastcall PathBuilder_UpdatePathMoveToLow(Dummy_006c93a0* obj)
{
    PathingSolution_ClearCurrentDetailedPath((Dummy_006c93a0*)obj->vtable);
    return 1;
}
}  // namespace fnv_006c93d0

// @fnv 0x006c9fa0
void __thiscall PathingSolution::SetByteAtOffset40(int aucValue)
{
    *reinterpret_cast<unsigned char*>(&m_bHasValidPath) = (unsigned char)aucValue;
}

struct FUN_006cc5a0_shell
{
    int m_flags;
    void SetFlag4(bool value);
};

// @fnv 0x006cc5a0
void FUN_006cc5a0_shell::SetFlag4(bool abEnabled)
{
    if (abEnabled)
        m_flags |= 4;
    else
        m_flags &= ~4;
}

struct FUN_006cd1d0_shell
{
    unsigned char GetFlag() const;
};

// @fnv 0x006cd1d0
unsigned char FUN_006cd1d0_shell::GetFlag() const
{
    return ((const unsigned char*)this)[0xa3];
}

struct FUN_006cee10_shell
{
    char* __thiscall BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(int a);
};

// @fnv 0x006cee10
// src: COMMUNITY 0x006cee10
char* __thiscall FUN_006cee10_shell::BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(int aiIndex)
{
    return *(char**)(this + 4) + aiIndex * 0x18;
}

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class IDebugText;
namespace fnv_006cc5e0 {
struct PacketNodeRecord;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

typedef char _sizecheck_NavMeshSearchNode[sizeof(NavMeshTriangleReference) == 20 ? 1 : -1];
struct FUN_006cc5e0_shell : public PathBuilder
{
    int PathBuilder_AddNodesFromNavMesh(PathingLocation*, PathingLocation*, unsigned int, unsigned int);
};

struct PacketNodeRecord : public PathingGraphNode
{
};

// ProcessListsView: unit-local view (declares only what 0x006cc5e0 calls), not the shared ProcessLists; renamed so no local type keeps the shared name
struct ProcessListsView
{
    unsigned char* GetLifeStateControlFlag();
};
extern ProcessListsView g_011d73d8;
extern const float g_011e024c_arg1;
extern const NiPoint3 _NiPoint3_ZERO;

// Local request declarations retained: shared header lacks max-pass and incomplete-path accessors.

bool __cdecl BSSimpleArray_NavMeshPtr_1024_DefaultEqualFunction_NavMeshPtr(const NavMeshPtr&, const NavMeshPtr&);

void __cdecl ClampInt(int*, int, int);
void __cdecl Pathing_GetAllLoadedNavmeshes(BSSimpleArray<NavMeshPtr, 1024>*);

namespace std {
float __cdecl abs(float);
}

// @fnv 0x006cc5e0
// src: COMMUNITY 0x006cc5e0
int FUN_006cc5e0_shell::PathBuilder_AddNodesFromNavMesh(PathingLocation* aStartLocation, PathingLocation* aGoalLocation,
                                     unsigned int aiFirstVirtualNodeIndex, unsigned int aiLastVirtualNodeIndex)
{
    if (*g_011d73d8.GetLifeStateControlFlag() && !((PathingRequest*)pRequest)->GetString() &&
        !((PathingRequest*)pRequest)->TESCombatStyle_GetPowerAttackF() && !((PathingRequest*)pRequest)->GetTryToUseCurvedPath() &&
        ((::PathBuilder*)this)->PathBuilder_TryBuildStraightPath(aStartLocation, aGoalLocation))
        return 0;

    BSSimpleArray<NavMeshTriangleEdgeReference, 1024> BadNodes(0x20, 0);
    bool bAddNodesFromNavMeshIncomplete = false;
    int imaxPassCount = ((PathingRequest*)pRequest)->DialoguePackage_GetCurrentDialogItem();
    ClampInt(&imaxPassCount, 1, 10);
    ((BSSimpleArray<const NavMeshInfo*, 1024>*)((char*)this + 0x14))->Clear(false);
    ((BSSimpleArray<NavMeshPtr, 1024>*)((char*)this + 0x24))->Clear(false);

    for (unsigned int i = 0; i < m_pOutputSolution->PathingSolution_GetVirtualNodeCount(); ++i)
    {
        NavMeshPtr spmesh;
        if (((PacketNodeRecord*)m_pOutputSolution->GetVirtualNode(i))->FUN_00717e50().ResolveNavMesh(spmesh))
        {
            ((BSSimpleArray<NavMeshPtr, 1024>*)((char*)this + 0x24))->AppendValue((NavMeshPtr&)spmesh);
            ((BSSimpleArray<const NavMeshInfo*, 1024>*)((char*)this + 0x14))->Add(((NavMesh*)(NavMesh*)spmesh)->GetNavMeshInfo_0068efb0());
        }
    }

    for (int pass = 0; pass < imaxPassCount; ++pass)
    {
        if (pass == 1)
        {
            BSSimpleArray<NavMeshPtr, 1024> loadedNavmeshes;
            Pathing_GetAllLoadedNavmeshes(&loadedNavmeshes);
            for (unsigned int i = 0; i < loadedNavmeshes.GetSize(); ++i)
            {
                if (((BSSimpleArray<NavMeshPtr, 1024>*)((char*)this + 0x24))->Find(loadedNavmeshes.GetAt(i), 0, BSSimpleArray_NavMeshPtr_1024_DefaultEqualFunction_NavMeshPtr) == -1)
                {
                    ((BSSimpleArray<NavMeshPtr, 1024>*)((char*)this + 0x24))->AppendValue(loadedNavmeshes.GetAt(i));
                    ((BSSimpleArray<const NavMeshInfo*, 1024>*)((char*)this + 0x14))
                        ->Add(((NavMesh*)(NavMesh*)(NavMeshPtr&)loadedNavmeshes.GetAt(i))->GetNavMeshInfo_0068efb0());
                }
            }
        }

        BSSimpleArray<NavMeshTriangleReference, 1024> nodes(0x20, 0);
        BSSimpleArray<NavMeshTriangleEdgeReference, 1024> links(0x20, 0);
        PathingLocation smoothingStartLocation(*aStartLocation);
        PathingLocation smoothingGoalLocation(*aGoalLocation);

        if (!((::PathBuilder*)this)
                 ->FindPath(aStartLocation, aGoalLocation, BadNodes, nodes, links, aiFirstVirtualNodeIndex,
                            aiLastVirtualNodeIndex))
        {
            if (nodes.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() && pass >= 1)
                return 2;
            if (nodes.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
                continue;

            const NavMeshTriangleReference* lastNode = &nodes.GetLastElement();
            PathingLocation lastLoc(((NavMeshTriangleReference*)lastNode)->FastNavMeshTriLocation_GetLocation(),
                                     ((NavMesh*)lastNode->m_pLocationNavMesh)->GetNavMeshInfo_0068efb0(),
                                     lastNode->m_usTriangleIdentifier);
            if (m_pOutputSolution->FUN_00441110() == aiLastVirtualNodeIndex)
            {
                PacketNodeRecord* plastVirtualNode =
                    (PacketNodeRecord*)m_pOutputSolution->GetVirtualNode(aiLastVirtualNodeIndex);
                NiPoint3 delta = lastLoc.GetLocation() - plastVirtualNode->FUN_00717e50().GetLocation();
                float ftargetRadius;
                if (plastVirtualNode->IsTransitionNode())
                    ftargetRadius = g_011e024c_arg1;
                else
                    ftargetRadius = ((PathingRequest*)pRequest)->GetCenterRadius();
                if (delta.GetSquaredXYLength() < ftargetRadius * ftargetRadius && std::abs(delta.z) < 180.0)
                {
                    if (!((PathingRequest*)pRequest)->GetByteAtOffset9B())
                        return 2;
                    else if (!plastVirtualNode->IsTransitionNode())
                    {
                        bAddNodesFromNavMeshIncomplete = true;
                        m_pOutputSolution->SetByteAtOffset40(1);
                    }
                }
                else if (pass == 0)
                    continue;
                else
                {
                    bAddNodesFromNavMeshIncomplete = true;
                    m_pOutputSolution->SetByteAtOffset40(1);
                }
            }
            else
            {
                bAddNodesFromNavMeshIncomplete = true;
                m_pOutputSolution->SetByteAtOffset40(1);
            }
            if (!((PathingRequest*)pRequest)->GetByteAtOffset9B())
                return 2;
            else
                smoothingGoalLocation = lastLoc;
        }

        unsigned int icurrentNodeCount = m_pOutputSolution->GetObjectFlags();
        if (!((::PathBuilder*)this)->PathBuilder_RunPathSmoother(smoothingStartLocation, smoothingGoalLocation, BadNodes, nodes, links))
        {
            if (pass == imaxPassCount - 1 && ((PathingRequest*)pRequest)->FUN_006cd1d0())
            {
                bAddNodesFromNavMeshIncomplete = true;
                m_pOutputSolution->SetByteAtOffset40(1);
                for (unsigned int i = 0; i < nodes.GetSize(); ++i)
                {
                    PathingLocation loc(
                        ((const NavMeshTriangleReference*)&nodes.GetIndexedValue_006b3160(i))->FastNavMeshTriLocation_GetLocation(),
                        ((NavMesh*)nodes.GetIndexedValue_006b3160(i).m_pLocationNavMesh)->GetNavMeshInfo_0068efb0());
                    m_pOutputSolution->ReserveIndex(loc, _NiPoint3_ZERO);
                }
            }
            else
            {
                PathingGraphNode* plastNode = (PathingGraphNode*)m_pOutputSolution->PathingSolution_GetLastNode();
                if (plastNode && m_pOutputSolution->FUN_00441110() == aiLastVirtualNodeIndex)
                {
                    PacketNodeRecord* plastVirtualNode =
                        (PacketNodeRecord*)m_pOutputSolution->GetVirtualNode(aiLastVirtualNodeIndex);
                    NiPoint3 delta =
                        plastNode->FUN_00717e50().GetLocation() - plastVirtualNode->FUN_00717e50().GetLocation();
                    float ftargetRadius;
                    if (plastVirtualNode->IsTransitionNode())
                        ftargetRadius = g_011e024c_arg1;
                    else
                        ftargetRadius = ((PathingRequest*)pRequest)->GetCenterRadius();
                    if (delta.GetSquaredXYLength() < ftargetRadius * ftargetRadius && std::abs(delta.z) < 180.0)
                        break;
                }
                if (BadNodes.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() || pass == imaxPassCount - 1)
                {
                    if (plastNode)
                    {
                        bAddNodesFromNavMeshIncomplete = true;
                        m_pOutputSolution->SetByteAtOffset40(1);
                        if (((PathingRequest*)pRequest)->GetByteAtOffset9B())
                            return 1;
                        else
                        {
                            while (m_pOutputSolution->GetObjectFlags() != icurrentNodeCount)
                                m_pOutputSolution->RemoveLastNode();
                            return 2;
                        }
                    }
                    else
                        return 2;
                }
                else
                {
                    if (pass < imaxPassCount - 1)
                    {
                        while (m_pOutputSolution->GetObjectFlags() != icurrentNodeCount)
                            m_pOutputSolution->RemoveLastNode();
                    }
                    continue;
                }
            }
        }
        break;
    }

    if (bAddNodesFromNavMeshIncomplete)
        return 1;
    else
        return 0;
}
}  // namespace fnv_006cc5e0

namespace fnv_006cb4a0 {
struct FUN_006cb4a0_shell
{
    void* m_uiStandInValue;
    void* m_iValueAfterStandIn;
    BSSimpleArray<PathingLocation, 1024> m_losArray;
    void ClearLOSArray();
};

// @fnv 0x006cb4a0
void FUN_006cb4a0_shell::ClearLOSArray()
{
    m_losArray.BSSimpleArray<PathingLocation, 1024>::~BSSimpleArray();
}
}  // namespace fnv_006cb4a0

namespace fnv_006cedf0 {
struct FUN_006cee10_shell
{
    char* BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(int);
    char* GetFirstEntry();
};

// @fnv 0x006cedf0
char* FUN_006cee10_shell::GetFirstEntry()
{
    return BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(0);
}
}  // namespace fnv_006cedf0

// Calls RemoveAt on the object at this+0x20 with its current size minus one and 1.
// @fnv 0x006c9350
// src: COMMUNITY 0x006c9350
void PathingSolution::RemoveLastNode()
{
    ((BSSimpleArray<PathingGraphNode, 1024>*)((char*)this + 0x20))
        ->RemoveAt(((BSSimpleArray<PathingGraphNode, 1024>*)((char*)this + 0x20))->GetSize() - 1, 1u);
}

struct FUN_006cf000_shell
{
    void RemoveAt(int a, int b);
};
struct FUN_006c9380_shell
{
    void PathingSolution_RemoveNode(int a);
};
// @fnv 0x006c9380
// src: COMMUNITY 0x006c9380
void FUN_006c9380_shell::PathingSolution_RemoveNode(int aiValue)
{
    ((FUN_006cf000_shell*)((char*)this + 0x20))->RemoveAt(aiValue, 1);
}

void __fastcall FUN_006cf180(void*);

struct FUN_006cb480_shell
{
    void* ProcessAndReturnValue_006cb480();
};

// @fnv 0x006cb480
// src: GUESS 0x006cb480 (confidence: low)
void* FUN_006cb480_shell::ProcessAndReturnValue_006cb480()
{
    FUN_006cf180(this + 8);
    return this;
}

struct S00568fa0
{
    int TESObjectREFR_GetLinkedDoorTeleportPosition();
};
struct S006dd460
{
    void FUN_006dd460(int);
};
struct Mid
{
    int x;
    void PathingNode_SetActionAtNode(int);
};
// @fnv 0x006cc560
// src: COMMUNITY 0x006cc560
void Mid::PathingNode_SetActionAtNode(int aiValue)
{
    *(int*)((char*)this + 0x38) = aiValue;
    ((S006dd460*)((char*)this + 4))->FUN_006dd460((*(S00568fa0**)((char*)this + 0x38))->TESObjectREFR_GetLinkedDoorTeleportPosition());
    *(int*)this = *(int*)this | 3;
}

struct FUN_006cd880_shell
{
    void SetField2084(int param_2);
};

// @fnv 0x006cd880
void FUN_006cd880_shell::SetField2084(int aiValue)
{
    *(int*)((char*)this + 0x2084) = aiValue;
}

extern int DAT_0106c944;

struct FUN_006cd650_shell
{
    void* SetVtable();
};

// @fnv 0x006cd650
void* FUN_006cd650_shell::SetVtable()
{
    *(void**)this = &DAT_0106c944;
    return this;
}

struct P4_6cb4c0
{
    int a, b, c, d;
};
extern SettingT<INISettingCollection> g_011d7404;
BSWin32TaskletManager& GetTaskletManager();
unsigned int __cdecl gm_GetCurrentThreadId();
class PathManager
{
  public:
    static PathManager* GetRandomGenerator();
    int PathManager_GetRayCastPath(void*, PathingLocation*, PathingLocation*, void*);
};
struct Loc_6cb4c0
{
    P4_6cb4c0 a, b;
    int c, d;
};
struct FUN_006cb3a0
{
    int eType;
    void* pRequest;
    Loc_6cb4c0 kStart;
    Loc_6cb4c0 kGoal;
    int x1, x2, x3;
    FUN_006cb3a0();
    ~FUN_006cb3a0();
};
struct FUN_006cb480
{
    int a;
    int b;
    struct Path
    {
        void BSSimpleArray_CopyTo_0(void*);
        P4_6cb4c0 c;
    } kPath;
    FUN_006cb480();
    ~FUN_006cb480();
};

// @fnv 0x006cb4c0
// src: COMMUNITY 0x006cb4c0
int PathBuilder::BuildStraightPathUsingRayCasts(PathingLocation& aStartLocation, PathingLocation& aGoalLocation, void* aRetPath)
{
    if (*(unsigned char*)g_011d7404.Bool())
    {
        if (GetTaskletManager().IsTaskletThread(gm_GetCurrentThreadId()))
        {
            return PathManager::GetRandomGenerator()->PathManager_GetRayCastPath(pRequest, &aStartLocation, &aGoalLocation, aRetPath);
        }
        else
        {
            FUN_006cb3a0 rayCastRequest;
            *(PathingLocation*)&rayCastRequest.kStart = aStartLocation;
            *(PathingLocation*)&rayCastRequest.kGoal = aGoalLocation;
            rayCastRequest.eType = 2;
            rayCastRequest.pRequest = pRequest;
            FUN_006cb480 retPath;
            PathingSearchRayCast rayCastSearch;
            if (rayCastSearch.ProcessRayCast((RayCastParam*)&rayCastRequest, (PathingSolutionExt*)&retPath) == 1)
            {
                retPath.kPath.BSSimpleArray_CopyTo_0(aRetPath);
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    else
    {
        return 2;
    }
}

struct S5460
{
    bool BSSimpleArray_NavMeshInfo_1024_ShouldGrow();
    unsigned int BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
    void BSSimpleArray_VirtualPathingNode_1024_ReallocateBuffer(unsigned int, unsigned int);
    virtual void v0();
    virtual int v1(int);
    int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};
struct FUN_006cef10_shell : S5460
{
    unsigned int AdvanceCounter();
};
// @fnv 0x006cef10
unsigned int FUN_006cef10_shell::AdvanceCounter()
{
    if (BSSimpleArray_NavMeshInfo_1024_ShouldGrow())
    {
        if (m_0c == 0)
        {
            int n = 4;
            m_04 = v1(n);
            m_0c = n;
        }
        else
        {
            unsigned int u = BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
            BSSimpleArray_VirtualPathingNode_1024_ReallocateBuffer(u, m_08);
            m_0c = u;
        }
    }
    m_08 = m_08 + 1;
    return m_08 - 1;
}

// @fnv 0x006cedd0
// src: COMMUNITY 0x006cedd0
void __fastcall BSSimpleArray_PathingLocation_1024_GetTail(BSSimpleArray<NavMeshStaticAvoidNode, 1024>* self)
{
    self->GetAt((int)self->iSize - 1);
}

struct FUN_006c9920_sub08
{
    void* GetA();
    void* GetB(void* p);
};

struct FUN_006c9920_thing
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    static void* operator new(unsigned int size, void* p);
    static void operator delete(void* p, void* q);
    FUN_006c9920_thing(unsigned int a);
};

struct FUN_006c9920_cls
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_006c9920_sub08 m_08;
    void* ConstructThing(unsigned int a);
};

// Gets a buffer from m_08, constructs a FUN_006c9920_thing in it with a, and returns the buffer pointer.
// @fnv 0x006c9920
void* FUN_006c9920_cls::ConstructThing(unsigned int auiValue)
{
    void* r7 = m_08.GetA();
    void* s = m_08.GetB(r7);
    new (s) FUN_006c9920_thing(auiValue);
    return r7;
}

struct PathingStepA_006e78b0
{
    void* GetVirtualNode_006e78b0(int value);
};

struct PathingStepB_00717e50
{
    void* FUN_00717e50();
};

struct PathingStepC_006dd4f0
{
    void* FUN_006dd4f0();
};

struct PathingStepD_00450ff0
{
    bool TESObjectCELL_GetAttached();
};

struct PathingStepE_006ca0c0
{
    bool FUN_006ca0c0();
};

struct FUN_006c9fc0_cls
{
    int unk00;
    PathingSolution* m_04;
    bool FindPathSegmentEnd(int a1, int* p1, int* p2);
};

// Checks the path node at a1, then scans forward from a1+1 until a node is invalid or flagged, storing the start in p1 and the end index in p2.
// @fnv 0x006c9fc0
bool FUN_006c9fc0_cls::FindPathSegmentEnd(int aiStartIndex, int* piStartOut, int* piEndOut)
{
    void* pFirstNode = reinterpret_cast<PathingStepC_006dd4f0*>(
                           reinterpret_cast<PathingStepB_00717e50*>(
                               reinterpret_cast<PathingStepA_006e78b0*>(m_04)->GetVirtualNode_006e78b0(aiStartIndex))
                               ->FUN_00717e50())
                           ->FUN_006dd4f0();
    if (!(pFirstNode != 0 && reinterpret_cast<PathingStepD_00450ff0*>(pFirstNode)->TESObjectCELL_GetAttached()))
    {
        return false;
    }
    *piStartOut = aiStartIndex;
    *piEndOut = *piStartOut + 1;
    for (; *piEndOut < (int)m_04->PathingSolution_GetVirtualNodeCount(); *piEndOut = *piEndOut + 1)
    {
        void* item = reinterpret_cast<PathingStepC_006dd4f0*>(
                         reinterpret_cast<PathingStepB_00717e50*>(
                             reinterpret_cast<PathingStepA_006e78b0*>(m_04)->GetVirtualNode_006e78b0(*piEndOut))
                             ->FUN_00717e50())
                         ->FUN_006dd4f0();
        if (!(item != 0 && reinterpret_cast<PathingStepD_00450ff0*>(item)->TESObjectCELL_GetAttached()))
        {
            break;
        }
        if (reinterpret_cast<PathingStepE_006ca0c0*>(
                reinterpret_cast<PathingStepA_006e78b0*>(m_04)->GetVirtualNode_006e78b0(*piEndOut))
                ->FUN_006ca0c0())
        {
            *piEndOut = *piEndOut + 1;
            break;
        }
    }
    *piEndOut = *piEndOut - 1;
    return true;
}

class NavMeshInfo;

struct PathPoint3
{
    float x;
    float y;
    float z;
    PathPoint3 operator-(const PathPoint3& point) const;
    float Length() const;
};

struct PathLoc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    PathLoc();
    PathLoc(const PathPoint3& pos, const NavMeshInfo* info, unsigned short tri);
    ~PathLoc();
    PathLoc& operator=(const PathLoc&);
    bool FUN_006dd6f0(int);
    bool FUN_006dd6a0();
    PathPoint3 FUN_005c3420() const;
};

struct PathLocArray
{
    unsigned int FUN_006cf1b0(const PathLoc&);
};

struct VirtualNode
{
    PathLoc* FUN_00717e50();
    bool IsTransitionNode();
};

bool __fastcall VirtualPathingNode_HasActualLocation(VirtualNode* node);

struct PathRequest
{
    float GetCenterRadius();
};

struct DoorEntry
{
    const NavMeshInfo* pInfo;
    unsigned short m_usTriangleID;
    unsigned short unk06;
    int unk08;
    PathPoint3 kPos;
};

struct DoorEntryList
{
    unsigned int FUN_0044ddc0();
    DoorEntry* BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(int);
};

int __cdecl CollectNearbyEdges(PathLoc*, int, DoorEntryList*);

struct PathBuilderCore
{
    PathRequest* pRequest;
    PathingSolution* m_pOutputSolution;
    bool ComputePathingLocation(VirtualNode*, VirtualNode*, PathLoc&);
    int PathBuilder_BuildPathToValidNavMeshTriangle(PathLoc*, PathLocArray*, int, DoorEntryList*);
    int ProcessPathNode(int aIndex, PathLocArray* aArray, DoorEntryList* aDoors);
};

// @fnv 0x006cac90
int PathBuilderCore::ProcessPathNode(int aIndex, PathLocArray* aArray, DoorEntryList* aDoors)
{
    VirtualNode* pNode = (VirtualNode*)m_pOutputSolution->GetVirtualNode(aIndex);
    if (aIndex != (int)m_pOutputSolution->PathingSolution_GetVirtualNodeCount() - 1)
    {
        VirtualNode* pNext = (VirtualNode*)m_pOutputSolution->GetVirtualNode(aIndex + 1);
        if (aIndex < (int)m_pOutputSolution->FUN_00441110())
        {
            if (VirtualPathingNode_HasActualLocation(pNext))
            {
                PathLoc kLoc;
                if (ComputePathingLocation(pNode, pNext, kLoc))
                {
                    *pNode->FUN_00717e50() = kLoc;
                    aArray->FUN_006cf1b0(kLoc);
                    return 1;
                }
            }
        }
        else if (!pNode->IsTransitionNode())
        {
            PathLoc kLoc2;
            if (ComputePathingLocation(pNode, pNext, kLoc2))
            {
                *pNode->FUN_00717e50() = kLoc2;
                aArray->FUN_006cf1b0(kLoc2);
                return 1;
            }
        }
    }
    if (VirtualPathingNode_HasActualLocation(pNode))
    {
        PathLoc* pLoc = pNode->FUN_00717e50();
        if (!pLoc->FUN_006dd6f0(0))
        {
            return 2;
        }
        if (pLoc->FUN_006dd6a0())
        {
            aArray->FUN_006cf1b0(*pLoc);
        }
        else
        {
            switch (CollectNearbyEdges(pLoc, 10, aDoors))
            {
            case 1:
                aArray->FUN_006cf1b0(*pLoc);
                return 1;
            case 2:
                for (unsigned int i = 0; i < aDoors->FUN_0044ddc0(); i++)
                {
                    PathPoint3 kDiff = pLoc->FUN_005c3420() - aDoors->BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(i)->kPos;
                    if (kDiff.Length() < pRequest->GetCenterRadius() * pRequest->GetCenterRadius() && kDiff.z > -64.0 &&
                        kDiff.z < 180.0)
                    {
                        PathLoc kDoorLoc(aDoors->BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(i)->kPos, aDoors->BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(i)->pInfo,
                                         aDoors->BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(i)->m_usTriangleID);
                        aArray->FUN_006cf1b0(kDoorLoc);
                        return 1;
                    }
                }
                return PathBuilder_BuildPathToValidNavMeshTriangle(pLoc, aArray, 0, aDoors);
            }
            return 2;
        }
    }
    else
    {
        return 2;
    }
    return 1;
}

struct FUN_006cb3a0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    FUN_006cb3a0_Sub();
    ~FUN_006cb3a0_Sub();
};

struct FUN_006cb3a0_Tail
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void Call0();
};

struct FUN_006cb3a0_cls
{
    int unk00;
    int unk04;
    FUN_006cb3a0_Sub m_08;
    FUN_006cb3a0_Sub m_30;
    FUN_006cb3a0_Tail m_58;

    FUN_006cb3a0_cls();
};

// @fnv 0x006cb3a0
FUN_006cb3a0_cls::FUN_006cb3a0_cls()
{
    m_58.Call0();
}

// Thiscall dtor, 104 bytes /MT /Od /GS /EHsc: member sub-object at +0x58 released (state 1),
// member sub-object at +0x30 released (state 0), then base sub-object at +8 released (state -1).
// The +0x30 member and the +8 base share one type, so they call the same dtor.
class FUN_006cb410_pad
{
  public:
    unsigned int unk00;
    unsigned int unk04;
};

class FUN_006cb410_sub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    ~FUN_006cb410_sub();
};

class FUN_006cb410_tail
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~FUN_006cb410_tail();
};

class FUN_006cb410_cls : public FUN_006cb410_pad, public FUN_006cb410_sub
{
  public:
    FUN_006cb410_sub m_30;
    FUN_006cb410_tail m_58;
    ~FUN_006cb410_cls();
};

// Destructor for the class; the compiler-generated body destroys the base subobject and the m_30 and m_58 members.
// @fnv 0x006cb410
FUN_006cb410_cls::~FUN_006cb410_cls()
{}

struct S_006cb900_Vec
{
    int x;
    int y;
    int z;
    void FUN_006815c0();
};

struct S_006cb900
{
    int unk00;
    int unk04;
    int unk08;
    S_006cb900_Vec m_0c;
    void FastNavMeshEdgeHandle_FastNavMeshEdgeHandle(const S_006cb900* p);
    S_006cb900& NavMeshEdgeLocation_NavMeshEdgeLocation(const S_006cb900* other);
};

// @fnv 0x006cb900
// src: COMMUNITY 0x006cb900
S_006cb900& S_006cb900::NavMeshEdgeLocation_NavMeshEdgeLocation(const S_006cb900* other)
{
    FastNavMeshEdgeHandle_FastNavMeshEdgeHandle(other);
    m_0c.FUN_006815c0();
    m_0c = other->m_0c;
    return *this;
}

struct PLocShell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    PLocShell(const NiPoint3& pt, const NavMeshInfo* info, unsigned short w);
    ~PLocShell();
};
struct PtCtor
{
    float x;
    float y;
    float z;
    PtCtor();
    NiPoint3 operator+(const PtCtor& other) const;
};
struct Inner2
{
    bool FUN_0069ad00(NavMeshPtr* p);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    NiPoint3 m_10;
};
struct Inner
{
    void FUN_006de250();
    Inner2* FUN_006dd540();
    NiPoint3 FUN_005c3420();
};
struct ArgObj
{
    Inner* FUN_00717e50();
};
struct PLocInner
{
    NiPoint3 FUN_005c3420();
};
struct ReqObj
{
    float GetFloatAtOffset68();
    PLocInner* NiAVObject_GetRotate_006a9540();
};
struct TriArr
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    TriArr(int a, int b, int c);
    ~TriArr();
    unsigned int FUN_0044ddc0();
    int* FUN_00877a30(unsigned int i);
};
struct TESshell
{
    float GetCellHeightAtPosition(NiPoint3* pt, void* cell);
};
extern TESshell* DAT_011dea10;
extern float DAT_0101e2bc;
extern float DAT_0104e2b8;
extern double DAT_0104f2f0;
extern double DAT_0106c948;
extern float DAT_01016970;
bool __fastcall VirtualPathingNode_HasActualLocation(const int* pThis);

struct ThisCls
{
    ReqObj* m_00;
    int m_04;
    int m_08;
    bool ComputePathingLocation(ArgObj* a0, ArgObj* a1, PathingLocation* a2);
};

// @fnv 0x006ce2d0
bool ThisCls::ComputePathingLocation(ArgObj* a0, ArgObj* a1, PathingLocation* apOutLocation)
{
    a0->FUN_00717e50()->FUN_006de250();
    NavMeshPtr navPtr;
    if (!a0->FUN_00717e50()->FUN_006dd540()->FUN_0069ad00(&navPtr))
        return false;
    if (VirtualPathingNode_HasActualLocation((const int*)a0))
    {
        unsigned short wIdxW;
        int iIdxT;
        float zlen;
        zlen = (a1->FUN_00717e50()->FUN_005c3420() - a0->FUN_00717e50()->FUN_006dd540()->m_10).Length();
        wIdxW = 0xffff;
        iIdxT = -1;
        if (navPtr.Modelloader_GetReferencedThis()->FindClosestOpenEdgeForLocation(a1->FUN_00717e50()->FUN_005c3420(), zlen * 2.0, &wIdxW, &iIdxT, 0))
        {
            PtCtor upt4c;
            PtCtor pt34G;
            navPtr.Modelloader_GetReferencedThis()->GetEdgeVertices_0068f0c0(wIdxW, iIdxT, (NiPoint3&)upt4c, (NiPoint3&)pt34G);
            PointStorage wpt28;
            navPtr.Modelloader_GetReferencedThis()->FUN_00558220(&reinterpret_cast<NiPoint3&>(wpt28), wIdxW);
            NiPoint3 xtmp40 = (upt4c + pt34G) * DAT_0104e2b8 + reinterpret_cast<NiPoint3&>(wpt28) * DAT_0101e2bc;
            float vf50;
            vf50 = DAT_011dea10->GetCellHeightAtPosition(&xtmp40, navPtr.Modelloader_GetReferencedThis()->GetParentCell());
            if (vf50 + DAT_0104f2f0 > xtmp40.z)
                xtmp40.z = vf50;
            *apOutLocation = *(PathingLocation*)&PLocShell(xtmp40, navPtr.Modelloader_GetReferencedThis()->GetNavMeshInfo_0068efb0(), wIdxW);
            return true;
        }
    }
    else
    {
        float ubest;
        TriArr zarr(0, 0, m_08);
        int bestIdxz;
        int ui;
        float tlen2;
        NavMeshTriangle* ttri;
        PointStorage pt84S;
        PointStorage pt90N;
        float rf94;
        navPtr.Modelloader_GetReferencedThis()->CollectTrianglesForDoor((unsigned int)a1->FUN_00717e50()->FUN_006dd540(), (BSSimpleArray<unsigned int, 1024>*)&zarr);
        bestIdxz = 0xffff;
        ubest = DAT_01016970;
        ui = 0;
        for (; ui < zarr.FUN_0044ddc0(); ui++)
        {
            ttri = navPtr.Modelloader_GetReferencedThis()->FUN_005582f0(*(unsigned short*)zarr.FUN_00877a30(ui));
            if (m_00->GetFloatAtOffset68() > DAT_0106c948 && ttri->IsNoLargeCreature())
                continue;
            navPtr.Modelloader_GetReferencedThis()->FUN_00558220(&reinterpret_cast<NiPoint3&>(pt84S), *(unsigned short*)zarr.FUN_00877a30(ui));
            tlen2 = (reinterpret_cast<NiPoint3&>(pt84S) - m_00->NiAVObject_GetRotate_006a9540()->FUN_005c3420()).Length();
            if (tlen2 < ubest)
            {
                tlen2 = ubest;
                bestIdxz = *zarr.FUN_00877a30(ui);
            }
        }
        if (bestIdxz != 0xffff)
        {
            navPtr.Modelloader_GetReferencedThis()->FUN_00558220(&reinterpret_cast<NiPoint3&>(pt90N), (unsigned short)bestIdxz);
            rf94 = DAT_011dea10->GetCellHeightAtPosition(&reinterpret_cast<NiPoint3&>(pt90N), navPtr.Modelloader_GetReferencedThis()->GetParentCell());
            if (rf94 + DAT_0104f2f0 > pt90N.z)
                pt90N.z = rf94;
            *apOutLocation = *(PathingLocation*)&PLocShell(
                reinterpret_cast<NiPoint3&>(pt90N), (const NavMeshInfo*)a0->FUN_00717e50()->FUN_006dd540(), (unsigned short)bestIdxz);
            return true;
        }
    }
    return false;
}

struct MeshTri
{
    unsigned short GetVertexIndex(int aEdge);
    unsigned short GetNeighbor(int aEdge);
};

struct MeshVert
{
    float x;
    float y;
    float z;
};

struct SegmentDelta : public NiPoint3
{
    float SqrLength();
};

struct MeshObj
{
    unsigned int GetTriangleCount();
    MeshTri* GetTriangle(unsigned short aIndex);
    MeshVert* GetVertex(unsigned short aIndex);
    NiPoint3 GetTriangleCenter(unsigned short aIndex);
};

struct MeshPtr
{
    MeshObj* m_pObject;
    MeshPtr(MeshObj* apObject);
    ~MeshPtr();
    MeshObj* operator->();
};

struct MeshList
{
    void* m_pVtbl;
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiCap;
    MeshList();
    ~MeshList();
    unsigned int GetSize();
    MeshObj* GetAt(unsigned int aIndex);
};

struct EdgeCandidate
{
    MeshObj* pMesh;
    unsigned short m_usTriangleID;
    unsigned short usPad;
    int m_iEdgeNumber;
    NiPoint3 kPoint;
    float fDist;
    float fZ;
    EdgeCandidate();
};

struct EdgeCandidateList
{
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiCap;
    unsigned int m_uiGrow;
    EdgeCandidateList();
    ~EdgeCandidateList();
    unsigned int GetSize();
    bool IsEmpty();
    EdgeCandidate* GetAt(unsigned int aIndex);
    void Add(const EdgeCandidate& arItem);
};

struct MeshEdgeRecord
{
    MeshObj* pMesh;
    unsigned short m_usTriangleID;
    unsigned short usPad;
    int m_iEdgeNumber;
    NiPoint3 kPoint;
    MeshEdgeRecord(const EdgeCandidate& arItem);
};

struct EdgeHandleList
{
    void Add(const MeshEdgeRecord& arItem);
};

struct PathActor
{
    void Prepare(int aiFlag);
    bool IsDone();
    NiPoint3 GetPosition();
};

extern SettingT<INISettingCollection> gSearchRadius;
extern float fCenterBias;

void __cdecl CollectMeshes(PathActor* apActor, float afRadius, MeshList* apList);
void __cdecl ClosestPointOnSegment(NiPoint3* apOut, const NiPoint3& arPoint, MeshVert* apA, MeshVert* apB);
int __cdecl CompareEdgeCandidates(const void* apA, const void* apB);
extern "C" void __cdecl qsort(void* base, unsigned int num, unsigned int width,
                              int(__cdecl* compare)(const void*, const void*));
unsigned int __cdecl MinCount(unsigned int a, unsigned int b);

// @fnv 0x006d4120
int __cdecl CollectNearbyEdges(PathActor* apActor, unsigned int auiMax, EdgeHandleList* apOut)
{
    apActor->Prepare(0);
    if (apActor->IsDone())
    {
        return 1;
    }
    float fRadius = *gSearchRadius.Float();
    float fRadiusSq2 = fRadius * fRadius;
    MeshList kMeshes5;
    CollectMeshes(apActor, fRadius, &kMeshes5);
    EdgeCandidateList kEdges;
    for (unsigned int aI = 0; aI < kMeshes5.GetSize(); aI++)
    {
        MeshPtr spMesh_(kMeshes5.GetAt(aI));
        for (unsigned int t3 = 0; t3 < spMesh_->GetTriangleCount(); t3++)
        {
            MeshTri* pTri_ = spMesh_->GetTriangle((unsigned short)t3);
            for (int e9 = 0; e9 < 3; e9++)
            {
                if (pTri_->GetNeighbor(e9) == 0xFFFF)
                {
                    MeshVert* _pV0 = spMesh_->GetVertex(pTri_->GetVertexIndex(e9));
                    int iNext2 = e9 + 1;
                    if (iNext2 == 3)
                    {
                        iNext2 = 0;
                    }
                    MeshVert* pV2 = spMesh_->GetVertex(pTri_->GetVertexIndex(iNext2));
                    PointStorage kClosest5;
                    ClosestPointOnSegment(&reinterpret_cast<NiPoint3&>(kClosest5), apActor->GetPosition(), _pV0, pV2);
                    NiPoint3 kDiff_ = apActor->GetPosition() - reinterpret_cast<NiPoint3&>(kClosest5);
                    float fDistA = static_cast<SegmentDelta&>(kDiff_).SqrLength();
                    if (fDistA < fRadiusSq2)
                    {
                        EdgeCandidate kItem6;
                        kItem6.pMesh = spMesh_.operator->();
                        kItem6.m_usTriangleID = (unsigned short)t3;
                        kItem6.m_iEdgeNumber = e9;
                        kItem6.kPoint =
                            reinterpret_cast<NiPoint3&>(kClosest5) + (spMesh_->GetTriangleCenter((unsigned short)t3) - reinterpret_cast<NiPoint3&>(kClosest5)) * fCenterBias;
                        kItem6.fZ = kDiff_.z;
                        kItem6.fDist = fDistA;
                        kEdges.Add(kItem6);
                    }
                }
            }
        }
    }
    if (kEdges.IsEmpty())
    {
        return 0;
    }
    qsort(kEdges.GetAt(0), kEdges.GetSize(), 0x20, CompareEdgeCandidates);
    unsigned int uiCount5 = MinCount(auiMax, kEdges.GetSize());
    for (unsigned int j = 0; j < uiCount5; j++)
    {
        apOut->Add(MeshEdgeRecord(*kEdges.GetAt(j)));
    }
    if (uiCount5 > 0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

struct PathingVirtualNode;

// Retained only for TrimNodes (0x006c9380), which include/PathingSolution.h does not declare.
struct PathingSolutionData : public PathingSolution
{
    void TrimNodes(int count);
};

struct PathingVirtualNode
{
    PathingLocation* GetLocation();
    void SetLocation(PathingLocation* loc);
};

struct PathingNodeLocation
{
    void** m_ppVirtualMethodTable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    unsigned char ucPad27;
    PathingNodeLocation(const NiPoint3* point, PathingLocation* base);
    ~PathingNodeLocation();
};

struct PathBuilderUpdate : public PathBuilder
{
    bool FindUpdateRange(unsigned int index, int* start, int* end);
    bool RebuildDetailedPath(bool flag);
    bool RebuildFromIndex(bool flag, unsigned int index);
    int UpdatePathFromIndex(unsigned int index, const NiPoint3* point);
};

void __fastcall PathingSolution_ClearCurrentDetailedPath(Dummy_006c93a0* pThis);

// @fnv 0x006c9170
int PathBuilderUpdate::UpdatePathFromIndex(unsigned int index, const NiPoint3* point)
{
    int iStart = -1;
    int iEnd = -1;
    if (!FindUpdateRange(index, &iStart, &iEnd))
    {
        if (m_pOutputSolution->GetObjectFlags() == 0)
        {
            return 0;
        }
        else
        {
            PathingSolution_ClearCurrentDetailedPath((Dummy_006c93a0*)m_pOutputSolution);
            return 1;
        }
    }
    if (m_pOutputSolution->GetObjectFlags() > 0)
    {
        if ((int)m_pOutputSolution->FUN_00441110() >= iEnd)
        {
            return 0;
        }
        m_pOutputSolution->unk18 = index;
        PathingNodeLocation kTargetPoint(
            point, ((PathingVirtualNode*)m_pOutputSolution->GetVirtualNode(index))->GetLocation());
        ((PathingVirtualNode*)m_pOutputSolution->GetVirtualNode(index))->SetLocation((PathingLocation*)&kTargetPoint);
        int iCount = m_pOutputSolution->GetObjectFlags() - 1;
        m_pOutputSolution->RemoveLastNode();
        m_pOutputSolution->unk1c = iEnd;
        m_bPathFound = true;
        if (!RebuildDetailedPath(false))
        {
            return -1;
        }
        else if (m_pOutputSolution->IsIncomplete())
        {
            return -1;
        }
        else
        {
            ((PathingSolutionData*)m_pOutputSolution)->TrimNodes(iCount);
        }
    }
    else
    {
        if (!RebuildFromIndex(false, index))
        {
            return -1;
        }
    }
    return 2;
}

struct PathQuery : FUN_006cb3a0
{
    unsigned int capacity;
    PathQuery();
    ~PathQuery();
};
struct DirectLocation : PathLoc
{
    DirectLocation();
    DirectLocation(const DirectLocation&);
    ~DirectLocation();
};
struct DoorListCopy
{
    void ProcessItems(void*);
};
struct PathManagerDirect : PathManager
{
    int PathManager_GetRayCastPathToNavmesh(PathRequest*, DoorEntryList*, PathLoc*, PathLocArray*, bool);
};
struct PathBuilderDirect : PathBuilderCore
{
    bool FindNearestMeshLocation(DirectLocation, DirectLocation*, bool);
};
// @fnv 0x006cb050
// src: COMMUNITY 0x006cb050
int PathBuilderCore::PathBuilder_BuildPathToValidNavMeshTriangle(PathLoc* start, PathLocArray* output, int allowPartial, DoorEntryList* doors)
{
    if (*g_011d7404.Bool())
    {
        switch (CollectNearbyEdges(start, 10, doors))
        {
        case 0:
            return 2;
        case 1:
            output->FUN_006cf1b0(*start);
            return 1;
        case 2:
            if (GetTaskletManager().IsTaskletThread(gm_GetCurrentThreadId()))
            {
                return static_cast<PathManagerDirect*>(PathManager::GetRandomGenerator())
                    ->PathManager_GetRayCastPathToNavmesh(pRequest, doors, start, output, *reinterpret_cast<bool*>(&allowPartial));
            }
            else
            {
                int status;
                {
                    PathQuery query;
                    {
                        reinterpret_cast<PathingLocation&>(query.kGoal) = *reinterpret_cast<PathingLocation*>(start);
                        query.eType = !*reinterpret_cast<bool*>(&allowPartial);
                        query.pRequest = pRequest;
                        reinterpret_cast<DoorListCopy*>(doors)->ProcessItems(&query.x1);
                        FUN_006cb480 result;
                        PathingSearchRayCast search;
                        status = search.ProcessRayCast((RayCastParam*)&query, (PathingSolutionExt*)&result);
                        while (status == 0)
                        {
                            status = search.ProcessRayCast((RayCastParam*)&query, (PathingSolutionExt*)&result);
                        }
                        if (status == 1)
                        {
                            result.kPath.BSSimpleArray_CopyTo_0(output);
                            return 1;
                        }
                        else
                        {
                            return 2;
                        }
                    }
                }
            }
        }
        return 2;
    }
    else
    {
        DirectLocation goal;
        if (static_cast<PathBuilderDirect*>(this)->FindNearestMeshLocation(
                *reinterpret_cast<DirectLocation*>(start), &goal, *reinterpret_cast<bool*>(&allowPartial)))
        {
            output->FUN_006cf1b0(*start);
            output->FUN_006cf1b0(*reinterpret_cast<PathLoc*>(&goal));
            return 1;
        }
        else
        {
            return 2;
        }
    }
}

struct Info501
{
    bool FUN_0069ad00(NavMeshPtr*);
};
struct Edge501
{
    Info501* info;
    unsigned short triangle;
    unsigned short flags;
    int edge;
    PointStorage position;
    Edge501& NavMeshEdgeLocation_NavMeshEdgeLocation(const Edge501*);
};
struct EdgeInput501
{
    Edge501* GetFirstEntry();
};
struct Loc501
{
    NiPoint3 FUN_005c3420() const;
};
struct Node501
{
    Loc501* FUN_00717e50();
};
struct Solution501
{
    Node501* GetVirtualNode_006e78b0(unsigned int);
};
struct Builder501
{
    PathRequest* request;
    Solution501* solution;
    bool TryAddClosestPoint(unsigned int, EdgeInput501*, BSSimpleArray<PathingLocation, 1024>*);
};
void __cdecl GetClosestPointOnSegment(NiPoint3*, const NiPoint3&, const NiPoint3&, const NiPoint3&);
// @fnv 0x006cb6a0
bool Builder501::TryAddClosestPoint(unsigned int index, EdgeInput501* input, BSSimpleArray<PathingLocation, 1024>* output)
{
    Edge501 edge;
    edge.NavMeshEdgeLocation_NavMeshEdgeLocation(input->GetFirstEntry());
    PointStorage mesh;
    ((NiPoint3&)mesh).FUN_006815c0();
    PointStorage start;
    ((NiPoint3&)start).FUN_006815c0();
    NavMeshPtr end;
    if (edge.info->FUN_0069ad00(&end))
    {
        end.Modelloader_GetReferencedThis()->GetEdgeVertices_0068f0c0(edge.triangle, edge.edge, (NiPoint3&)mesh, (NiPoint3&)start);
        NiPoint3 position = solution->GetVirtualNode_006e78b0(index)->FUN_00717e50()->FUN_005c3420();
        PointStorage closest;
        GetClosestPointOnSegment((NiPoint3*)&closest, position, (NiPoint3&)mesh, (NiPoint3&)start);
        if (((NiPoint3&)closest - position).GetSquaredXYLength() < request->GetCenterRadius() * request->GetCenterRadius() &&
            ((NiPoint3&)closest - position).z > -64.0 && ((NiPoint3&)closest - position).z < 180.0)
        {
            PointStorage center;
            end.Modelloader_GetReferencedThis()->FUN_00558220((NiPoint3*)&center, edge.triangle);
            ((NiPoint3&)closest).ComputeValue_0063c8a0(((NiPoint3&)center - (NiPoint3&)closest) * DAT_0101e2bc);
            output->Clear(false);
            PathLoc location((const PathPoint3&)closest, (const NavMeshInfo*)edge.info, edge.triangle);
            output->AppendElement((const PathingLocation&)location);
            return true;
        }
    }
    return false;
}

// Detailed path construction between two solution nodes.
struct LenS
{
    float NiPoint3_XYLength();
};
struct DoorHandle
{
    const NavMeshInfo* mesh;
    unsigned short triangle;
    unsigned short flags;
    int edge;
    NiPoint3 position;
};
struct DoorAccess
{
    DoorHandle* BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(int index);
};
struct LocAcc
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    DoorHandle* GetFirstEntry();
};
struct FUN_006cf180
{
    void** vt;
    void* buf;
    unsigned int sz;
    unsigned int res;
    FUN_006cf180();
    ~FUN_006cf180();
    unsigned int FUN_0044ddc0();
    void* FUN_00691750(int idx);
    int BSSimpleArray_PathingLocation_1024_GetTail(int a, int b);
    int BSSimpleArray_PathingLocation_1024_GetTail(int a);
};
struct FUN_006cf200
{
    void** vt;
    void* buf;
    unsigned int sz;
    unsigned int res;
    FUN_006cf200();
    ~FUN_006cf200();
};
struct NodeS
{
    void* FUN_00717e50();
    bool FUN_006ca0c0();
    void* FUN_0055b980();
};
struct PosS
{
    NiPoint3 FUN_005c3420();
};
struct MinS
{
    unsigned int FUN_00441110();
};
struct SolS
{
    void* GetVirtualNode_006e78b0(unsigned int idx);
    void* PathingSolution_GetLastNode();
    bool IsIncomplete();
    void PathingSolution_AddPathingNode(void* elem, const NiPoint3& z);
};
struct PBX
{
    int FUN_006caa40(unsigned int a, void* arr, void* loc);
    int ProcessPathNode(unsigned int a, void* arr, void* loc);
    bool TryAddClosestPoint(unsigned int a, void* arr, void* loc);
    int PathBuilder_AddNodesFromNavMesh(int a);
};
struct ReqX
{
    float GetFloatAtOffset68() const;
};
extern SettingT<GameSettingCollection> DAT_011d6ef0;
struct _Mem_2064
{
    void** vtable;
    NiPoint3 position;
    const NavMeshInfo* mesh;
    const void* meshes;
    void* cell;
    void* world;
    unsigned int cellKey;
    unsigned short triangle;
    unsigned char flags;
    unsigned char padding;
    _Mem_2064(const NiPoint3& p, const void* nm, unsigned short tri);
    ~_Mem_2064();
};
struct PLArr
{
    unsigned int FUN_006cf1b0(const PathingLocation& loc);
};
bool __cdecl Pathing_CheckLineOfSight(PathingLocation& a, PathingLocation& b, PathingLocation* c, void* d);

// Checks whether entries a and b can be connected, then updates m_pOutputSolution using path results and intermediate entries.
// @fnv 0x006cb950
bool PathBuilder::TryConnectPathNodes(unsigned int a, unsigned int b)
{
    struct FUN_006cf200 distA;  // Start door handles.
    struct FUN_006cf180 arrB;   // Start path.
    // Start path result.
    int distB;
    int distC = ((PBX*)this)->FUN_006caa40(a, &arrB, &distA);
    struct FUN_006cf200 flag;  // Goal door handles.
    struct FUN_006cf180 locA;  // Goal path.
    // Goal path result.
    distB = ((PBX*)this)->ProcessPathNode(b, &locA, &flag);
    if (distC == 0 || distB == 0)
    {
        return false;
    }
    // Distance from the start to its door.
    float locB = 0.0f;
    if (!((LocAcc*)&distA)->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        NiPoint3 ptA = ((DoorAccess*)&distA)->BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(0)->position;
        locB =
            ((LenS*)&(ptA -
                      ((PosS*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(a))->FUN_00717e50())->FUN_005c3420()))
                ->NiPoint3_XYLength();
    }
    // Distance from the goal to its door.
    float res2 = 0.0f;
    if (!((LocAcc*)&flag)->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        NiPoint3 ptB = ((DoorAccess*)&flag)->BSSimpleArray_NavMeshEdgeLocation_1024_GetAt(0)->position;
        res2 =
            ((LenS*)&(ptB -
                      ((PosS*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b))->FUN_00717e50())->FUN_005c3420()))
                ->NiPoint3_XYLength();
    }
    // Direct endpoint distance.
    float r2 =
        ((LenS*)&(((PosS*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(a))->FUN_00717e50())->FUN_005c3420() -
                  ((PosS*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b))->FUN_00717e50())->FUN_005c3420()))
            ->NiPoint3_XYLength();
    // Try a direct detailed path.
    bool r1 = false;
    if (2.0 * (locB + res2) > r2)
        r1 = true;
    if (distC == 2 || distB == 2)
    {
        if (r2 < 512.0)
            r1 = true;
    }
    if (r1)
    {
        struct FUN_006cf180 arrC;
        int res =
            ((PathBuilder*)this)
                ->BuildStraightPathUsingRayCasts(*(PathingLocation*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(a))->FUN_00717e50(),
                               *(PathingLocation*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b))->FUN_00717e50(),
                               &arrC);
        switch (res)
        {
        case 1: {
            unsigned int nodeB;  // Detailed-path index.
            for (nodeB = 0; nodeB < arrC.FUN_0044ddc0(); nodeB++)
                ((SolS*)m_pOutputSolution)->PathingSolution_AddPathingNode(arrC.FUN_00691750(nodeB), NiPoint3::ZERO);
            // Goal solution node.
            void* i = ((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b);
            if (((NodeS*)i)->FUN_006ca0c0())
            {
                ((Mid*)((SolS*)m_pOutputSolution)->PathingSolution_GetLastNode())->PathingNode_SetActionAtNode((int)((NodeS*)i)->FUN_0055b980());
            }
            else if (((MinS*)((NodeS*)i)->FUN_00717e50())->FUN_00441110() != 0)
            {
                if ((unsigned int)m_pOutputSolution->PathingSolution_GetVirtualNodeCount() > b + 1)
                {
                    if (((MinS*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b + 1))->FUN_00717e50())
                            ->FUN_00441110() == ((MinS*)((NodeS*)i)->FUN_00717e50())->FUN_00441110())
                    {
                        ((SolS*)m_pOutputSolution)
                            ->PathingSolution_AddPathingNode(((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b + 1))->FUN_00717e50(),
                                           NiPoint3::ZERO);
                        ((FUN_006cc5a0_shell*)((SolS*)m_pOutputSolution)->PathingSolution_GetLastNode())->SetFlag4(true);
                    }
                }
            }
            return true;
            break;
        }
        case 0:
            return false;
        }
    }
    if (distC == 2)
    {
        return false;
    }
    if (distB == 2)
    {
        if (((LocAcc*)&flag)->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        {
            return false;
        }
        if (!((PBX*)this)->TryAddClosestPoint(b, &flag, &locA))
            m_pOutputSolution->SetByteAtOffset40(1);
        {
            _Mem_2064 tmpPL(((LocAcc*)&flag)->GetFirstEntry()->position, ((LocAcc*)&flag)->GetFirstEntry()->mesh,
                            ((LocAcc*)&flag)->GetFirstEntry()->triangle);
            ((PLArr*)&locA)->FUN_006cf1b0(*(PathingLocation*)&tmpPL);
        }
    }
    {
        unsigned int i;
        for (i = 0; i < arrB.FUN_0044ddc0() - 1; i++)
            ((SolS*)m_pOutputSolution)->PathingSolution_AddPathingNode(arrB.FUN_00691750(i), NiPoint3::ZERO);
    }
    // Combined path result.
    int arrA = ((PBX*)this)->PathBuilder_AddNodesFromNavMesh(arrB.BSSimpleArray_PathingLocation_1024_GetTail(locA.BSSimpleArray_PathingLocation_1024_GetTail(a, b)));
    switch (arrA)
    {
    case 2: {
        if (r2 < 512.0 && (double)((ReqX*)pRequest)->GetFloatAtOffset68() < (double)*DAT_011d6ef0.Float())
        {
            if (Pathing_CheckLineOfSight(*(PathingLocation*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(a))->FUN_00717e50(),
                             *(PathingLocation*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b))->FUN_00717e50(),
                             0, 0))
            {
                return false;
            }
            struct FUN_006cf180 res3;  // Retry path.
            // Retry path result.
            int arrD = ((PathBuilder*)this)
                           ->BuildStraightPathUsingRayCasts(
                               *(PathingLocation*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(a))->FUN_00717e50(),
                               *(PathingLocation*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b))->FUN_00717e50(),
                               &res3);
            if (arrD != 1)
            {
                return false;
            }
            else
            {
                m_pOutputSolution->SetByteAtOffset40(0);
                unsigned int i;
                for (i = 0; i < res3.FUN_0044ddc0(); i++)
                    ((SolS*)m_pOutputSolution)->PathingSolution_AddPathingNode(res3.FUN_00691750(i), NiPoint3::ZERO);
                return !((SolS*)m_pOutputSolution)->IsIncomplete();
            }
        }
        else
        {
            return false;
        }
        break;
    }
    case 0: {
        if (!((LocAcc*)&locA)->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        {
            int i;
            for (i = (int)locA.FUN_0044ddc0() - 1; i >= 0; i--)
                ((SolS*)m_pOutputSolution)->PathingSolution_AddPathingNode(locA.FUN_00691750(i), NiPoint3::ZERO);
        }
        void* nodeB = ((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b);
        if (((NodeS*)nodeB)->FUN_006ca0c0())
        {
            ((Mid*)((SolS*)m_pOutputSolution)->PathingSolution_GetLastNode())->PathingNode_SetActionAtNode((int)((NodeS*)nodeB)->FUN_0055b980());
        }
        else if (((MinS*)((NodeS*)nodeB)->FUN_00717e50())->FUN_00441110() != 0)
        {
            if ((unsigned int)m_pOutputSolution->PathingSolution_GetVirtualNodeCount() > b + 1)
            {
                if (((MinS*)((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b + 1))->FUN_00717e50())
                        ->FUN_00441110() == ((MinS*)((NodeS*)nodeB)->FUN_00717e50())->FUN_00441110())
                {
                    ((SolS*)m_pOutputSolution)
                        ->PathingSolution_AddPathingNode(((NodeS*)((SolS*)m_pOutputSolution)->GetVirtualNode_006e78b0(b + 1))->FUN_00717e50(),
                                       NiPoint3::ZERO);
                    ((FUN_006cc5a0_shell*)((SolS*)m_pOutputSolution)->PathingSolution_GetLastNode())->SetFlag4(true);
                }
            }
        }
        return !((SolS*)m_pOutputSolution)->IsIncomplete();
        break;
    }
    case 1: {
        m_pOutputSolution->SetByteAtOffset40(1);
        return false;
    }
    }
    return false;
}

struct MeshRefLocal
{
    void* object;
    MeshRefLocal();
    ~MeshRefLocal();
    operator void*() const;
};
struct LocationLocal
{
    bool Resolve(MeshRefLocal&, unsigned short&);
};
struct SearchPointLocal
{
    void* mesh;
    unsigned short triangle;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
};
struct SearchLocal
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    int unk0df4;
    int unk0df8;
    int unk0dfc;
    int unk0e00;
    int unk0e04;
    int unk0e08;
    int unk0e0c;
    int unk0e10;
    int unk0e14;
    int unk0e18;
    int unk0e1c;
    int unk0e20;
    int unk0e24;
    int unk0e28;
    int unk0e2c;
    int unk0e30;
    int unk0e34;
    int unk0e38;
    int unk0e3c;
    int unk0e40;
    int unk0e44;
    int unk0e48;
    int unk0e4c;
    int unk0e50;
    int unk0e54;
    int unk0e58;
    int unk0e5c;
    int unk0e60;
    int unk0e64;
    int unk0e68;
    int unk0e6c;
    int unk0e70;
    int unk0e74;
    int unk0e78;
    int unk0e7c;
    int unk0e80;
    int unk0e84;
    int unk0e88;
    int unk0e8c;
    int unk0e90;
    int unk0e94;
    int unk0e98;
    int unk0e9c;
    int unk0ea0;
    int unk0ea4;
    int unk0ea8;
    int unk0eac;
    int unk0eb0;
    int unk0eb4;
    int unk0eb8;
    int unk0ebc;
    int unk0ec0;
    int unk0ec4;
    int unk0ec8;
    int unk0ecc;
    int unk0ed0;
    int unk0ed4;
    int unk0ed8;
    int unk0edc;
    int unk0ee0;
    int unk0ee4;
    int unk0ee8;
    int unk0eec;
    int unk0ef0;
    int unk0ef4;
    int unk0ef8;
    int unk0efc;
    int unk0f00;
    int unk0f04;
    int unk0f08;
    int unk0f0c;
    int unk0f10;
    int unk0f14;
    int unk0f18;
    int unk0f1c;
    int unk0f20;
    int unk0f24;
    int unk0f28;
    int unk0f2c;
    int unk0f30;
    int unk0f34;
    int unk0f38;
    int unk0f3c;
    int unk0f40;
    int unk0f44;
    int unk0f48;
    int unk0f4c;
    int unk0f50;
    int unk0f54;
    int unk0f58;
    int unk0f5c;
    int unk0f60;
    int unk0f64;
    int unk0f68;
    int unk0f6c;
    int unk0f70;
    int unk0f74;
    int unk0f78;
    int unk0f7c;
    int unk0f80;
    int unk0f84;
    int unk0f88;
    int unk0f8c;
    int unk0f90;
    int unk0f94;
    int unk0f98;
    int unk0f9c;
    int unk0fa0;
    int unk0fa4;
    int unk0fa8;
    int unk0fac;
    int unk0fb0;
    int unk0fb4;
    int unk0fb8;
    int unk0fbc;
    int unk0fc0;
    int unk0fc4;
    int unk0fc8;
    int unk0fcc;
    int unk0fd0;
    int unk0fd4;
    int unk0fd8;
    int unk0fdc;
    int unk0fe0;
    int unk0fe4;
    int unk0fe8;
    int unk0fec;
    int unk0ff0;
    int unk0ff4;
    int unk0ff8;
    int unk0ffc;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100c;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101c;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102c;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103c;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104c;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105c;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106c;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107c;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108c;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109c;
    int unk10a0;
    int unk10a4;
    int unk10a8;
    int unk10ac;
    int unk10b0;
    int unk10b4;
    int unk10b8;
    int unk10bc;
    int unk10c0;
    int unk10c4;
    int unk10c8;
    int unk10cc;
    int unk10d0;
    int unk10d4;
    int unk10d8;
    int unk10dc;
    int unk10e0;
    int unk10e4;
    int unk10e8;
    int unk10ec;
    int unk10f0;
    int unk10f4;
    int unk10f8;
    int unk10fc;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110c;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111c;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112c;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113c;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114c;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115c;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116c;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117c;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118c;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119c;
    int unk11a0;
    int unk11a4;
    int unk11a8;
    int unk11ac;
    int unk11b0;
    int unk11b4;
    int unk11b8;
    int unk11bc;
    int unk11c0;
    int unk11c4;
    int unk11c8;
    int unk11cc;
    int unk11d0;
    int unk11d4;
    int unk11d8;
    int unk11dc;
    int unk11e0;
    int unk11e4;
    int unk11e8;
    int unk11ec;
    int unk11f0;
    int unk11f4;
    int unk11f8;
    int unk11fc;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120c;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121c;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122c;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123c;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124c;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125c;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126c;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127c;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128c;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129c;
    int unk12a0;
    int unk12a4;
    int unk12a8;
    int unk12ac;
    int unk12b0;
    int unk12b4;
    int unk12b8;
    int unk12bc;
    int unk12c0;
    int unk12c4;
    int unk12c8;
    int unk12cc;
    int unk12d0;
    int unk12d4;
    int unk12d8;
    int unk12dc;
    int unk12e0;
    int unk12e4;
    int unk12e8;
    int unk12ec;
    int unk12f0;
    int unk12f4;
    int unk12f8;
    int unk12fc;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130c;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131c;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132c;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133c;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134c;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135c;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136c;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137c;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138c;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139c;
    int unk13a0;
    int unk13a4;
    int unk13a8;
    int unk13ac;
    int unk13b0;
    int unk13b4;
    int unk13b8;
    int unk13bc;
    int unk13c0;
    int unk13c4;
    int unk13c8;
    int unk13cc;
    int unk13d0;
    int unk13d4;
    int unk13d8;
    int unk13dc;
    int unk13e0;
    int unk13e4;
    int unk13e8;
    int unk13ec;
    int unk13f0;
    int unk13f4;
    int unk13f8;
    int unk13fc;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140c;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141c;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142c;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143c;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144c;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145c;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146c;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147c;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148c;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149c;
    int unk14a0;
    int unk14a4;
    int unk14a8;
    int unk14ac;
    int unk14b0;
    int unk14b4;
    int unk14b8;
    int unk14bc;
    int unk14c0;
    int unk14c4;
    int unk14c8;
    int unk14cc;
    int unk14d0;
    int unk14d4;
    int unk14d8;
    int unk14dc;
    int unk14e0;
    int unk14e4;
    int unk14e8;
    int unk14ec;
    int unk14f0;
    int unk14f4;
    int unk14f8;
    int unk14fc;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150c;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151c;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152c;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153c;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154c;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155c;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156c;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157c;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158c;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159c;
    int unk15a0;
    int unk15a4;
    int unk15a8;
    int unk15ac;
    int unk15b0;
    int unk15b4;
    int unk15b8;
    int unk15bc;
    int unk15c0;
    int unk15c4;
    int unk15c8;
    int unk15cc;
    int unk15d0;
    int unk15d4;
    int unk15d8;
    int unk15dc;
    int unk15e0;
    int unk15e4;
    int unk15e8;
    int unk15ec;
    int unk15f0;
    int unk15f4;
    int unk15f8;
    int unk15fc;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160c;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161c;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162c;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163c;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164c;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165c;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166c;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167c;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168c;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169c;
    int unk16a0;
    int unk16a4;
    int unk16a8;
    int unk16ac;
    int unk16b0;
    int unk16b4;
    int unk16b8;
    int unk16bc;
    int unk16c0;
    int unk16c4;
    int unk16c8;
    int unk16cc;
    int unk16d0;
    int unk16d4;
    int unk16d8;
    int unk16dc;
    int unk16e0;
    int unk16e4;
    int unk16e8;
    int unk16ec;
    int unk16f0;
    int unk16f4;
    int unk16f8;
    int unk16fc;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170c;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171c;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172c;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173c;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174c;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175c;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176c;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177c;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178c;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179c;
    int unk17a0;
    int unk17a4;
    int unk17a8;
    int unk17ac;
    int unk17b0;
    int unk17b4;
    int unk17b8;
    int unk17bc;
    int unk17c0;
    int unk17c4;
    int unk17c8;
    int unk17cc;
    int unk17d0;
    int unk17d4;
    int unk17d8;
    int unk17dc;
    int unk17e0;
    int unk17e4;
    int unk17e8;
    int unk17ec;
    int unk17f0;
    int unk17f4;
    int unk17f8;
    int unk17fc;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180c;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181c;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182c;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183c;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184c;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185c;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186c;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187c;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188c;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189c;
    int unk18a0;
    int unk18a4;
    int unk18a8;
    int unk18ac;
    int unk18b0;
    int unk18b4;
    int unk18b8;
    int unk18bc;
    int unk18c0;
    int unk18c4;
    int unk18c8;
    int unk18cc;
    int unk18d0;
    int unk18d4;
    int unk18d8;
    int unk18dc;
    int unk18e0;
    int unk18e4;
    int unk18e8;
    int unk18ec;
    int unk18f0;
    int unk18f4;
    int unk18f8;
    int unk18fc;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190c;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191c;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192c;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193c;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194c;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195c;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196c;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197c;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198c;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199c;
    int unk19a0;
    int unk19a4;
    int unk19a8;
    int unk19ac;
    int unk19b0;
    int unk19b4;
    int unk19b8;
    int unk19bc;
    int unk19c0;
    int unk19c4;
    int unk19c8;
    int unk19cc;
    int unk19d0;
    int unk19d4;
    int unk19d8;
    int unk19dc;
    int unk19e0;
    int unk19e4;
    int unk19e8;
    int unk19ec;
    int unk19f0;
    int unk19f4;
    int unk19f8;
    int unk19fc;
    int unk1a00;
    int unk1a04;
    int unk1a08;
    int unk1a0c;
    int unk1a10;
    int unk1a14;
    int unk1a18;
    int unk1a1c;
    int unk1a20;
    int unk1a24;
    int unk1a28;
    int unk1a2c;
    int unk1a30;
    int unk1a34;
    int unk1a38;
    int unk1a3c;
    int unk1a40;
    int unk1a44;
    int unk1a48;
    int unk1a4c;
    int unk1a50;
    int unk1a54;
    int unk1a58;
    int unk1a5c;
    int unk1a60;
    int unk1a64;
    int unk1a68;
    int unk1a6c;
    int unk1a70;
    int unk1a74;
    int unk1a78;
    int unk1a7c;
    int unk1a80;
    int unk1a84;
    int unk1a88;
    int unk1a8c;
    int unk1a90;
    int unk1a94;
    int unk1a98;
    int unk1a9c;
    int unk1aa0;
    int unk1aa4;
    int unk1aa8;
    int unk1aac;
    int unk1ab0;
    int unk1ab4;
    int unk1ab8;
    int unk1abc;
    int unk1ac0;
    int unk1ac4;
    int unk1ac8;
    int unk1acc;
    int unk1ad0;
    int unk1ad4;
    int unk1ad8;
    int unk1adc;
    int unk1ae0;
    int unk1ae4;
    int unk1ae8;
    int unk1aec;
    int unk1af0;
    int unk1af4;
    int unk1af8;
    int unk1afc;
    int unk1b00;
    int unk1b04;
    int unk1b08;
    int unk1b0c;
    int unk1b10;
    int unk1b14;
    int unk1b18;
    int unk1b1c;
    int unk1b20;
    int unk1b24;
    int unk1b28;
    int unk1b2c;
    int unk1b30;
    int unk1b34;
    int unk1b38;
    int unk1b3c;
    int unk1b40;
    int unk1b44;
    int unk1b48;
    int unk1b4c;
    int unk1b50;
    int unk1b54;
    int unk1b58;
    int unk1b5c;
    int unk1b60;
    int unk1b64;
    int unk1b68;
    int unk1b6c;
    int unk1b70;
    int unk1b74;
    int unk1b78;
    int unk1b7c;
    int unk1b80;
    int unk1b84;
    int unk1b88;
    int unk1b8c;
    int unk1b90;
    int unk1b94;
    int unk1b98;
    int unk1b9c;
    int unk1ba0;
    int unk1ba4;
    int unk1ba8;
    int unk1bac;
    int unk1bb0;
    int unk1bb4;
    int unk1bb8;
    int unk1bbc;
    int unk1bc0;
    int unk1bc4;
    int unk1bc8;
    int unk1bcc;
    int unk1bd0;
    int unk1bd4;
    int unk1bd8;
    int unk1bdc;
    int unk1be0;
    int unk1be4;
    int unk1be8;
    int unk1bec;
    int unk1bf0;
    int unk1bf4;
    int unk1bf8;
    int unk1bfc;
    int unk1c00;
    int unk1c04;
    int unk1c08;
    int unk1c0c;
    int unk1c10;
    int unk1c14;
    int unk1c18;
    int unk1c1c;
    int unk1c20;
    int unk1c24;
    int unk1c28;
    int unk1c2c;
    int unk1c30;
    int unk1c34;
    int unk1c38;
    int unk1c3c;
    int unk1c40;
    int unk1c44;
    int unk1c48;
    int unk1c4c;
    int unk1c50;
    int unk1c54;
    int unk1c58;
    int unk1c5c;
    int unk1c60;
    int unk1c64;
    int unk1c68;
    int unk1c6c;
    int unk1c70;
    int unk1c74;
    int unk1c78;
    int unk1c7c;
    int unk1c80;
    int unk1c84;
    int unk1c88;
    int unk1c8c;
    int unk1c90;
    int unk1c94;
    int unk1c98;
    int unk1c9c;
    int unk1ca0;
    int unk1ca4;
    int unk1ca8;
    int unk1cac;
    int unk1cb0;
    int unk1cb4;
    int unk1cb8;
    int unk1cbc;
    int unk1cc0;
    int unk1cc4;
    int unk1cc8;
    int unk1ccc;
    int unk1cd0;
    int unk1cd4;
    int unk1cd8;
    int unk1cdc;
    int unk1ce0;
    int unk1ce4;
    int unk1ce8;
    int unk1cec;
    int unk1cf0;
    int unk1cf4;
    int unk1cf8;
    int unk1cfc;
    int unk1d00;
    int unk1d04;
    int unk1d08;
    int unk1d0c;
    int unk1d10;
    int unk1d14;
    int unk1d18;
    int unk1d1c;
    int unk1d20;
    int unk1d24;
    int unk1d28;
    int unk1d2c;
    int unk1d30;
    int unk1d34;
    int unk1d38;
    int unk1d3c;
    int unk1d40;
    int unk1d44;
    int unk1d48;
    int unk1d4c;
    int unk1d50;
    int unk1d54;
    int unk1d58;
    int unk1d5c;
    int unk1d60;
    int unk1d64;
    int unk1d68;
    int unk1d6c;
    int unk1d70;
    int unk1d74;
    int unk1d78;
    int unk1d7c;
    int unk1d80;
    int unk1d84;
    int unk1d88;
    int unk1d8c;
    int unk1d90;
    int unk1d94;
    int unk1d98;
    int unk1d9c;
    int unk1da0;
    int unk1da4;
    int unk1da8;
    int unk1dac;
    int unk1db0;
    int unk1db4;
    int unk1db8;
    int unk1dbc;
    int unk1dc0;
    int unk1dc4;
    int unk1dc8;
    int unk1dcc;
    int unk1dd0;
    int unk1dd4;
    int unk1dd8;
    int unk1ddc;
    int unk1de0;
    int unk1de4;
    int unk1de8;
    int unk1dec;
    int unk1df0;
    int unk1df4;
    int unk1df8;
    int unk1dfc;
    int unk1e00;
    int unk1e04;
    int unk1e08;
    int unk1e0c;
    int unk1e10;
    int unk1e14;
    int unk1e18;
    int unk1e1c;
    int unk1e20;
    int unk1e24;
    int unk1e28;
    int unk1e2c;
    int unk1e30;
    int unk1e34;
    int unk1e38;
    int unk1e3c;
    int unk1e40;
    int unk1e44;
    int unk1e48;
    int unk1e4c;
    int unk1e50;
    int unk1e54;
    int unk1e58;
    int unk1e5c;
    int unk1e60;
    int unk1e64;
    int unk1e68;
    int unk1e6c;
    int unk1e70;
    int unk1e74;
    int unk1e78;
    int unk1e7c;
    int unk1e80;
    int unk1e84;
    int unk1e88;
    int unk1e8c;
    int unk1e90;
    int unk1e94;
    int unk1e98;
    int unk1e9c;
    int unk1ea0;
    int unk1ea4;
    int unk1ea8;
    int unk1eac;
    int unk1eb0;
    int unk1eb4;
    int unk1eb8;
    int unk1ebc;
    int unk1ec0;
    int unk1ec4;
    int unk1ec8;
    int unk1ecc;
    int unk1ed0;
    int unk1ed4;
    int unk1ed8;
    int unk1edc;
    int unk1ee0;
    int unk1ee4;
    int unk1ee8;
    int unk1eec;
    int unk1ef0;
    int unk1ef4;
    int unk1ef8;
    int unk1efc;
    int unk1f00;
    int unk1f04;
    int unk1f08;
    int unk1f0c;
    int unk1f10;
    int unk1f14;
    int unk1f18;
    int unk1f1c;
    int unk1f20;
    int unk1f24;
    int unk1f28;
    int unk1f2c;
    int unk1f30;
    int unk1f34;
    int unk1f38;
    int unk1f3c;
    int unk1f40;
    int unk1f44;
    int unk1f48;
    int unk1f4c;
    int unk1f50;
    int unk1f54;
    int unk1f58;
    int unk1f5c;
    int unk1f60;
    int unk1f64;
    int unk1f68;
    int unk1f6c;
    int unk1f70;
    int unk1f74;
    int unk1f78;
    int unk1f7c;
    int unk1f80;
    int unk1f84;
    int unk1f88;
    int unk1f8c;
    int unk1f90;
    int unk1f94;
    int unk1f98;
    int unk1f9c;
    int unk1fa0;
    int unk1fa4;
    int unk1fa8;
    int unk1fac;
    int unk1fb0;
    int unk1fb4;
    int unk1fb8;
    int unk1fbc;
    int unk1fc0;
    int unk1fc4;
    int unk1fc8;
    int unk1fcc;
    int unk1fd0;
    int unk1fd4;
    int unk1fd8;
    int unk1fdc;
    int unk1fe0;
    int unk1fe4;
    int unk1fe8;
    int unk1fec;
    int unk1ff0;
    int unk1ff4;
    int unk1ff8;
    int unk1ffc;
    int unk2000;
    int unk2004;
    int unk2008;
    int unk200c;
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201c;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202c;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203c;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204c;
    int unk2050;
    int unk2054;
    int unk2058;
    int unk205c;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206c;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207c;
    int unk2080;
    int unk2084;
    int unk2088;
    int unk208c;
    int unk2090;
    int unk2094;
    int unk2098;
    int unk209c;
    int unk20a0;
    int unk20a4;
    SearchLocal();
    ~SearchLocal();
    void SetMode(int);
    bool Search(void*, SearchPointLocal*, SearchPointLocal*, int, int, void*);
};
struct BuilderLocal
{
    void* request;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int infos;
    bool FindPath(LocationLocal*, LocationLocal*, int, int, int, int, int);
};
// Resolves start and goal locations to mesh/triangle points, runs a search in the given mode, and returns whether a path was found.
// @fnv 0x006cd670
bool BuilderLocal::FindPath(LocationLocal* start, LocationLocal* goal, int mode, int a, int b, int c, int d)
{
    MeshRefLocal startMesh2;
    unsigned short startTriangle;
    if (!start->Resolve(startMesh2, startTriangle))
        return false;
    SearchPointLocal startPoint7;
    startPoint7.mesh = startMesh2;
    startPoint7.triangle = startTriangle;
    MeshRefLocal goalMesh;
    unsigned short goalTriangle;
    if (!goal->Resolve(goalMesh, goalTriangle))
        return false;
    SearchPointLocal goalPoint3;
    goalPoint3.mesh = goalMesh;
    goalPoint3.triangle = goalTriangle;
    SearchLocal search;
    search.SetMode(mode);
    bool result3 = search.Search(request, &startPoint7, &goalPoint3, a, b, &infos);
    if (!result3)
        return false;
    return true;
}

struct SearchMesh;
struct SearchMeshPtr
{
    SearchMesh* object;
    SearchMeshPtr();
    ~SearchMeshPtr();
    operator SearchMesh*() const;
};
struct SearchPoint
{
    float x, y, z;
    SearchPoint operator-(const SearchPoint&) const;
    SearchPoint operator*(float) const;
    SearchPoint& operator+=(const SearchPoint&);
    float FUN_004a7290() const;
    static const SearchPoint ZERO;
};
struct SearchLocation
{
    void** vtable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const BSSimpleArray<NavMeshInfo_const*, 1024>* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;

    SearchLocation(const SearchPoint&, const NavMeshInfo*, unsigned short);
    ~SearchLocation();
    SearchLocation& operator=(const SearchLocation&);
    SearchPoint FUN_005c3420() const;
    void FUN_006dd5c0(BSSimpleArray<const NavMeshInfo*, 1024>&);
};
struct MeshInfoSearch
{
    bool FUN_0069ad00(SearchMeshPtr&);
};
struct SearchEdge
{
    SearchEdge();
    const SearchPoint* low;
    const SearchPoint* high;
};
struct SearchMesh : NavMesh
{
    bool FindClosestOpenEdgeForLocation(const SearchPoint&, float, unsigned short&, unsigned int&, bool);
    SearchEdge NavMesh_GetEdgeVertices_0(unsigned short, unsigned int);
    SearchPoint FUN_00558220(unsigned short);
};

bool NavMeshMath_Find2DIntersection_2(const SearchPoint&, const SearchPoint&, const SearchPoint&, const SearchPoint&, SearchPoint&);
struct PathBuilderSearch : PathBuilder
{
    bool FindNearestMeshLocation(SearchLocation location, SearchLocation& result, bool option);
};
// Searches the path infos for a mesh whose point is closest to the location, then stores the best match into result and returns whether one was found.
// @fnv 0x006cdb40
bool PathBuilderSearch::FindNearestMeshLocation(SearchLocation searchLocation, SearchLocation& resultLocation,
                                                bool option)
{
    float a = 3.402823466e38F;
    unsigned int p = -1;
    unsigned short h = 0xffff;
    SearchPoint f = SearchPoint::ZERO;
    BSSimpleArray<const NavMeshInfo*, 1024> s;
    searchLocation.FUN_006dd5c0(s);
    unsigned int i = s.GetSize();
    for (unsigned int j = 0; j < i; ++j)
    {
        SearchMeshPtr mesh;
        if (((MeshInfoSearch*)s.GetAt(j))->FUN_0069ad00(mesh))
        {
            unsigned short q;
            unsigned int b;
            if (((SearchMesh*)mesh)
                    ->FindClosestOpenEdgeForLocation(searchLocation.FUN_005c3420(), ((PathRequest*)pRequest)->GetCenterRadius(), q, b,
                                   option))
            {
                SearchEdge l = ((SearchMesh*)mesh)->NavMesh_GetEdgeVertices_0(q, b);
                SearchPoint k = ((SearchMesh*)mesh)->FUN_00558220(q);
                SearchPoint c = k;
                if (NavMeshMath_Find2DIntersection_2(searchLocation.FUN_005c3420(), ((SearchMesh*)mesh)->FUN_00558220(q), *l.low, *l.high,
                                 c))
                    c += (k - c) * 0.1F;
                float e = (c - searchLocation.FUN_005c3420()).FUN_004a7290();
                if (e < a)
                {
                    a = e;
                    p = j;
                    h = q;
                    f = c;
                }
            }
        }
    }
    if (p == -1)
        return false;
    resultLocation = SearchLocation(f, (const NavMeshInfo*)s.GetAt(p), h);
    return true;
}

struct Loc152 : PLocShell
{
    Loc152(const NiPoint3&, const NavMeshInfo*, unsigned short);
    ~Loc152();
};
struct Out152
{
    void FUN_006dcce0(const Loc152&);
};
struct Req152 : ReqObj
{
    PLocInner* GetOffsetC();
};
struct This152
{
    Req152* request;
    int field04;
    int field08;
    bool FindNavMeshLocation(ArgObj* from, ArgObj* to, Out152* output);
};
// @fnv 0x006cde50
bool This152::FindNavMeshLocation(ArgObj* from, ArgObj* to, Out152* output)
{
    to->FUN_00717e50()->FUN_006de250();
    NavMeshPtr mesh;
    if (!to->FUN_00717e50()->FUN_006dd540()->FUN_0069ad00(&mesh))
        return false;
    if (VirtualPathingNode_HasActualLocation((const int*)to))
    {
        float edge = (from->FUN_00717e50()->FUN_005c3420() - to->FUN_00717e50()->FUN_006dd540()->m_10).Length();
        unsigned short triangle = 0xffff;
        int distance = -1;
        if (mesh.Modelloader_GetReferencedThis()
                ->FindClosestOpenEdgeForLocation(from->FUN_00717e50()->FUN_005c3420(), edge * 2.0f, &triangle, &distance, 1))
        {
            PtCtor b;
            PtCtor a;
            mesh.Modelloader_GetReferencedThis()->GetEdgeVertices_0068f0c0(triangle, distance, (NiPoint3&)b, (NiPoint3&)a);
            NiPoint3 center = mesh.Modelloader_GetReferencedThis()->FUN_00558220(triangle);
            output->FUN_006dcce0(Loc152((((NiPoint3&)b + (NiPoint3&)a) * DAT_0104e2b8) + center * DAT_0101e2bc,
                                        mesh.Modelloader_GetReferencedThis()->GetNavMeshInfo_0068efb0(), triangle));
            return true;
        }
    }
    else
    {
        TriArr triangles(0, 0, field08);
        mesh.Modelloader_GetReferencedThis()->CollectTrianglesForDoor((unsigned int)from->FUN_00717e50()->FUN_006dd540(), (BSSimpleArray<unsigned int, 1024>*)&triangles);
        unsigned int minDistance = 0xffff;
        float best = DAT_01016970;
        for (unsigned int i = 0; i < triangles.FUN_0044ddc0(); ++i)
        {
            float center;
            NavMeshTriangle* d =
                mesh.Modelloader_GetReferencedThis()->FUN_005582f0((unsigned short)*triangles.FUN_00877a30(i));
            if (request->GetFloatAtOffset68() > DAT_0106c948 && d->IsNoLargeCreature())
                continue;
            {
                NiPoint3 tri =
                    mesh.Modelloader_GetReferencedThis()->FUN_00558220((unsigned short)*triangles.FUN_00877a30(i));
                center = (tri - request->GetOffsetC()->FUN_005c3420()).Length();
                if (center < best)
                {
                    center = best;
                    minDistance = *triangles.FUN_00877a30(i);
                }
            }
        }
        if (minDistance != 0xffff)
        {
            output->FUN_006dcce0(Loc152(mesh.Modelloader_GetReferencedThis()->FUN_00558220((unsigned short)minDistance),
                                        (NavMeshInfo*)to->FUN_00717e50()->FUN_006dd540(), (unsigned short)minDistance));
            return true;
        }
    }
    return false;
}

struct FUN_006c93f0_Stage
{
    void FUN_006ddbe0();
};
struct FUN_006c93f0_Node
{
    FUN_006c93f0_Stage* FUN_00717e50();
    void UpdateProxyFlag();
};
struct FUN_006c93f0_Collection
{
    unsigned int PathingSolution_GetVirtualNodeCount();
    FUN_006c93f0_Node* GetVirtualNode_006e78b0(unsigned int index);
};
struct FUN_006c93f0_Object
{
    int unk00;
    FUN_006c93f0_Collection* collection;
    bool FindPathSegmentEnd(int index, int* firstIndex, int* lastIndex);
    bool PathBuilder_BuildDetailedPath(int flag, int index);
    int ProcessIndexRange(int index);
};
// @fnv 0x006c93f0
int FUN_006c93f0_Object::ProcessIndexRange(int index)
{
    int firstIndex = -1;
    int lastIndex = -1;
    if (!FindPathSegmentEnd(index, &firstIndex, &lastIndex))
        return 0;
    for (unsigned int i = 0; i < collection->PathingSolution_GetVirtualNodeCount(); ++i)
        collection->GetVirtualNode_006e78b0(i)->FUN_00717e50()->FUN_006ddbe0();
    for (int j = firstIndex; j <= lastIndex; ++j)
        collection->GetVirtualNode_006e78b0(j)->UpdateProxyFlag();
    if (!PathBuilder_BuildDetailedPath(0, index))
        return -1;
    return 2;
}

class NavMeshInfo_;

class PathingGraphNode;
class ScrapHeapBuffer;

struct FNVHashMap
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    unsigned int Find(NavMeshInfo_* const& key, unsigned int start,
                      bool(__cdecl* fn)(NavMeshInfo_* const&, NavMeshInfo_* const&));
};

class NavMeshInfo_
{
  public:
    char pad0[0x24];
    FNVHashMap map24;
    FNVHashMap map34;
};

struct ParentSpaceNode
{
    int iStart;
    int iEnd;
    bool bNew;
};

struct OutNodes
{
    void* m_ppVirtualMethodTable;
    void* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int uiFlags;
    void Clear(bool freeMemory);
    unsigned int Add(const ParentSpaceNode& item);
};

struct VisitedArray
{
    void* m_ppVirtualMethodTable;
    unsigned char* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int uiFlags;
    VisitedArray(unsigned int size, unsigned int growBy, ScrapHeapBuffer* heap);
    ~VisitedArray();
    unsigned int Add(const unsigned char& item);
    int Find(const unsigned char& item, unsigned int start,
             bool(__cdecl* fn)(const unsigned char*, const unsigned char*));
    unsigned int FUN_0044ddc0();
};

bool __cdecl AreBytesEqual(const unsigned char*, const unsigned char*);
bool __fastcall VirtualPathingNode_HasNavMesh(const unsigned int*);
bool __cdecl Actor_AreReferencedValuesEqual(NavMeshInfo_* const&, NavMeshInfo_* const&);

// @fnv 0x006ca500
bool PathBuilder::BuildPathSpans(OutNodes& aOutNodes)
{
    aOutNodes.Clear(false);

    int iFirstA = this->m_pOutputSolution->unk18;
    int iLastA = this->m_pOutputSolution->unk1c;

    VisitedArray visited5(iLastA - iFirstA + 1, 0, this->m_pAllocator);

    {
        for (int i = iFirstA; i <= iLastA; i++)
        {
            PathingGraphNode* pNodeX = (PathingGraphNode*)this->m_pOutputSolution->GetVirtualNode(i);
            visited5.Add(VirtualPathingNode_HasNavMesh((const unsigned int*)pNodeX));
        }
    }

    {
        int i = iFirstA;
        while (i <= iLastA)
        {
            int iOpen_2 = visited5.Find((unsigned char)1, i - iFirstA, AreBytesEqual);
            if (iOpen_2 != -1)
            {
                int iClose3 = visited5.Find((unsigned char)0, iOpen_2, AreBytesEqual) - 1;
                if (iClose3 == -2)
                    iClose3 = visited5.FUN_0044ddc0() - 1;

                iOpen_2 += iFirstA;
                iClose3 += iFirstA;

                if (iOpen_2 > i)
                {
                    ParentSpaceNode gap;
                    gap.iStart = i;
                    gap.iEnd = iOpen_2 - 1;
                    gap.bNew = false;
                    aOutNodes.Add(gap);
                }

                int iSpanStartB = iOpen_2;
                int m2 = iOpen_2;
                while (m2 + 1 <= iClose3)
                {
                    PathingGraphNode* kPNode2;
                    PathingGraphNode* kPNode1;
                    kPNode1 = (PathingGraphNode*)this->m_pOutputSolution->GetVirtualNode(m2);
                    kPNode2 = (PathingGraphNode*)this->m_pOutputSolution->GetVirtualNode(m2 + 1);

                    kPNode1->FUN_00717e50().FUN_006de250();
                    kPNode2->FUN_00717e50().FUN_006de250();
                    NavMeshInfo_* pInfo8 = (NavMeshInfo_*)kPNode1->FUN_00717e50().GetAssociatedNavMesh();
                    NavMeshInfo_* pInfoX = (NavMeshInfo_*)kPNode2->FUN_00717e50().GetAssociatedNavMesh();

                    if (pInfo8 == 0 || pInfoX == 0)
                        return false;

                    if (pInfo8 != pInfoX && pInfo8->map24.Find(pInfoX, 0, Actor_AreReferencedValuesEqual) == (unsigned int)-1 &&
                        pInfo8->map34.Find(pInfoX, 0, Actor_AreReferencedValuesEqual) == (unsigned int)-1)
                    {
                        ParentSpaceNode span7;
                        span7.iStart = iSpanStartB;
                        span7.iEnd = m2;
                        span7.bNew = true;
                        aOutNodes.Add(span7);
                        iSpanStartB = m2 + 1;
                    }
                    m2++;
                }

                ParentSpaceNode tail;
                tail.iStart = iSpanStartB;
                tail.iEnd = iClose3;
                tail.bNew = true;
                aOutNodes.Add(tail);
                i = iClose3 + 1;
            }
            else
            {
                ParentSpaceNode node;
                node.iStart = i;
                node.iEnd = iLastA;
                node.bNew = false;
                aOutNodes.Add(node);
                i = iLastA + 1;
            }
        }
    }
    return true;
}

namespace fnv_006cd1f0 {
class VectorMethods : public NiPoint3
{
  public:
    NiPoint3 FUN_0053d1a0(const NiPoint3&) const;
};

class FUN_006dd0d0
{
  public:
    void** m_ppVirtualMethodTable;
    float posX, posY, posZ;
    const void* m_pLocationNavMesh;
    const void* pNavMeshInfoArray;
    void* pCell;
    void* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags, tailFlag;
    FUN_006dd0d0(const NiPoint3&, const PathingLocation*);
    ~FUN_006dd0d0();
};

class FUN_006cd5a0
{
  public:
    void* m_ppVirtualMethodTable;
    bool m_bCheckWater;
    FUN_006cd5a0();
};

class TESWorld
{
  public:
    double GetCellHeightAtPosition(const NiPoint3&, void*);
};
extern SettingT<GameSettingCollection> DAT_011d6ef0;
extern NiPoint3 DAT_011a9484;
extern unsigned int DAT_011f426c;
extern TESWorld* g_TES;
bool __cdecl Pathing_CheckLineOfSight(const PathingLocation*, const PathingLocation*, int, void*);

class PathBuilderMethods : public PathBuilder
{
  public:
    bool PathBuilder_TryBuildStraightPath(PathingLocation*, PathingLocation*);
};

// @fnv 0x006cd1f0
// src: COMMUNITY 0x006cd1f0
bool PathBuilderMethods::PathBuilder_TryBuildStraightPath(PathingLocation* pStart, PathingLocation* pEndLocation)
{
    FUN_006cd5a0 filter;
    filter.m_bCheckWater = ((PathingRequest*)pRequest)->GetFloatAtOffset68() > *DAT_011d6ef0.Setting_Float_00403e20();
    if (!Pathing_CheckLineOfSight(pStart, pEndLocation, 0, &filter))
        return false;

    if (g_TES->GetCellHeightAtPosition(((PathingLocation*)pStart)->FUN_005c3420(),
                                       ((PathingLocation*)pStart)->FUN_006dd4f0()) +
                25.0 >
            ((PathingLocation*)pStart)->FUN_005c3420().z ||
        g_TES->GetCellHeightAtPosition(((PathingLocation*)pEndLocation)->FUN_005c3420(),
                                       ((PathingLocation*)pEndLocation)->FUN_006dd4f0()) +
                25.0 >
            ((PathingLocation*)pEndLocation)->FUN_005c3420().z)
    {
        m_pOutputSolution->ReserveIndex(*pStart, *(const NiPoint3*)&DAT_011f426c);
        return true;
    }

    NiPoint3 kDelta =
        ((PathingLocation*)pEndLocation)->FUN_005c3420() - ((PathingLocation*)pStart)->FUN_005c3420();
    NiPoint3 sideOffset = ((VectorMethods*)&kDelta)->FUN_0053d1a0(DAT_011a9484) *
                          (float)((PathingRequest*)pRequest)->GetFloatAtOffset68();

    FUN_006dd0d0 kEndPlus(((PathingLocation*)pStart)->FUN_005c3420() - sideOffset, pStart);
    FUN_006dd0d0 kStartMinus(((PathingLocation*)pEndLocation)->FUN_005c3420() - sideOffset, pEndLocation);
    if (!Pathing_CheckLineOfSight((const PathingLocation*)&kEndPlus, (const PathingLocation*)&kStartMinus, 0, 0))
        return false;

    FUN_006dd0d0 kStartPlus(((PathingLocation*)pStart)->FUN_005c3420() + sideOffset, pStart);
    FUN_006dd0d0 kEndMinus(((PathingLocation*)pEndLocation)->FUN_005c3420() + sideOffset, pEndLocation);
    if (!Pathing_CheckLineOfSight((const PathingLocation*)&kStartPlus, (const PathingLocation*)&kEndMinus, 0, 0))
        return false;

    m_pOutputSolution->ReserveIndex(*pStart, *(const NiPoint3*)&DAT_011f426c);
    return true;
}
}  // namespace fnv_006cd1f0

namespace std {
float abs(float x);
}

float BSMAX_00404010(float a, float b);
float BSMIN(float a, float b);

struct NiPoint3Ext : NiPoint3
{
    NiPoint3Ext(float x, float y, float z);
};

struct RayCastItem
{
    const NavMeshInfo* m_pNavigationMesh;
    unsigned short triangleIndex;
    unsigned short unk06;
    unsigned int unk08;
    NiPoint3 location;

    RayCastItem(const RayCastItem& other);
};



struct NavMeshExt : NavMesh
{
    void FUN_00558220(NiPoint3& outPt, unsigned short tri);
};

struct TESObjectCELLExt : TESObjectCELL
{
    float UpdateTESState();
};

struct PathingLocationSub
{
    void** m_ppVirtualMethodTable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    void* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    unsigned char layoutPadding27;

    PathingLocationSub(const NiPoint3& pt, const NavMeshInfo* info, unsigned short tri);
    ~PathingLocationSub();
    NiPoint3 GetLocation() const;
    TESObjectCELL* FUN_006dd4f0() const;
    void FUN_006dd6f0();
};

class PathingLocationArray
{
  public:
    unsigned int FUN_006cf1b0(const PathingLocation& loc);
    unsigned int FUN_006cf1b0(const PathingLocationSub& loc);
    PathingLocationSub* BSSimpleArray_PathingLocation_1024_GetTail(int index);
};

template <class T, unsigned int Growth> class BSSimpleArrayExt : public BSSimpleArray<T, Growth>
{
  public:
    T& Front();
    void BSSimpleArray_NavMeshEdgeLocation_1024_Remove(unsigned int a, unsigned int b);
    bool IsEmpty() const;
};

struct RayCastParam
{
    unsigned int type;
    PathingRequest* pRequest;
    PathingLocation startLoc;
    PathingLocation endLoc;
    BSSimpleArrayExt<RayCastItem, 1024> pathArray;
};

struct PathingRequestExt : PathingRequest
{
    float GetRadius();
};

struct PathingSolutionExt
{
    unsigned int unk00;
    unsigned int status;
    PathingLocationArray locations;
};

// Sets up the ray cast from the request, then either handles the direct start/end case or walks the path array to build pathing locations and a status.
// @fnv 0x006e6320
unsigned int PathingSearchRayCast::ProcessRayCast(RayCastParam* pRayCastParam, PathingSolutionExt* param2)
{
    this->unk58 = pRayCastParam->type;
    this->pRequest = pRayCastParam->pRequest;
    param2->unk00 = this->unk58;
    this->f74 = BSMAX_00404010(((PathingRequestExt*)this->pRequest)->GetRadius(), 32.0f);
    this->unk88 = 0;

    switch (pRayCastParam->type)
    {
    case 1:
        this->loc2C = pRayCastParam->endLoc;
        this->ComputeBounds(pRayCastParam->pathArray);
        break;
    case 0:
        this->loc2C = pRayCastParam->endLoc;
        this->ComputeBounds(pRayCastParam->pathArray);
        break;
    case 2: {
        this->loc2C = pRayCastParam->endLoc;
        this->loc04 = pRayCastParam->startLoc;

        NiPoint3 kDiff =
            ((PathingLocationSub*)&this->loc2C)->GetLocation() - ((PathingLocationSub*)&this->loc04)->GetLocation();
        float fExtent2 = BSMAX_00404010(std::abs(kDiff.x), std::abs(kDiff.y));
        float minZ2 = BSMIN(((PathingLocationSub*)&this->loc04)->GetLocation().z,
                                   ((PathingLocationSub*)&this->loc2C)->GetLocation().z);
        float maxZ7 = BSMAX_00404010(((PathingLocationSub*)&this->loc04)->GetLocation().z,
                                   ((PathingLocationSub*)&this->loc2C)->GetLocation().z);
        NiPoint3 ptCenter2 =
            (((PathingLocationSub*)&this->loc2C)->GetLocation() + ((PathingLocationSub*)&this->loc04)->GetLocation()) *
            0.5f;

        this->pt5C = ptCenter2 - NiPoint3Ext(fExtent2 * 0.5, fExtent2 * 0.5, 0.0f);
        this->pt68 = ptCenter2 + NiPoint3Ext(fExtent2 * 0.5, fExtent2 * 0.5, 0.0f);
        this->pt5C.z = minZ2;
        this->pt68.z = maxZ7;

        if (!this->SetupFromCellWorld())
        {
            param2->status = 2;
            return 2;
        }

        if (((PathingLocationSub*)&this->loc04)->FUN_006dd4f0() &&
            ((PathingLocationSub*)&this->loc2C)->FUN_006dd4f0() &&
            ((PathingLocationSub*)&this->loc04)->GetLocation().z <
                ((TESObjectCELLExt*)((PathingLocationSub*)&this->loc04)->FUN_006dd4f0())->UpdateTESState() &&
            ((PathingLocationSub*)&this->loc2C)->GetLocation().z <
                ((TESObjectCELLExt*)((PathingLocationSub*)&this->loc2C)->FUN_006dd4f0())->UpdateTESState())
        {
            if (this->UpdateAndCheck(((PathingLocationSub*)&this->loc04)->GetLocation(),
                                     ((PathingLocationSub*)&this->loc2C)->GetLocation()))
            {
                param2->locations.FUN_006cf1b0(pRayCastParam->startLoc);
                param2->locations.FUN_006cf1b0(pRayCastParam->endLoc);
                param2->status = 1;
            }
            else
            {
                param2->status = 2;
            }
        }
        else
        {
            if (this->CheckPathClear(((PathingLocationSub*)&pRayCastParam->startLoc)->GetLocation(),
                                     ((PathingLocationSub*)&pRayCastParam->endLoc)->GetLocation()))
            {
                param2->locations.FUN_006cf1b0(pRayCastParam->startLoc);
                param2->locations.FUN_006cf1b0(pRayCastParam->endLoc);
                param2->status = 1;
            }
            else
            {
                param2->status = 2;
            }
        }
        this->PathingSearchRayCast_CleanUpRayCasts();
        return param2->status;
    }
    }

    if (!this->SetupFromCellWorld())
    {
        return 2;
    }

    for (this->unk88 = 0; this->unk88 < 10 && !pRayCastParam->pathArray.IsEmpty();)
    {
        bool bFlag8 = false;
        if (this->unk58 == 0)
        {
            bFlag8 = this->CheckPathClear(((PathingLocationSub*)&this->loc2C)->GetLocation(),
                                          pRayCastParam->pathArray.Front().location);
        }
        else
        {
            bFlag8 = this->CheckPathClear(pRayCastParam->pathArray.Front().location,
                                          ((PathingLocationSub*)&this->loc2C)->GetLocation());
        }

        if (bFlag8)
        {
            RayCastItem item_ = pRayCastParam->pathArray.Front();
            NavMeshPtr spMesh8;
            if (item_.m_pNavigationMesh->ResolveNavMesh(spMesh8))
            {
                NiPoint3 ptPos4 = item_.location;
                PointStorage kKNormal;
                ((NavMeshExt*)(NavMesh*)spMesh8)->FUN_00558220(reinterpret_cast<NiPoint3&>(kKNormal), item_.triangleIndex);
                ptPos4 += (reinterpret_cast<NiPoint3&>(kKNormal) - ptPos4) * 0.1f;
                PathingLocationSub loc(ptPos4, item_.m_pNavigationMesh, item_.triangleIndex);
                param2->locations.FUN_006cf1b0(this->loc2C);
                param2->locations.FUN_006cf1b0(loc);
                param2->locations.BSSimpleArray_PathingLocation_1024_GetTail(0)->FUN_006dd6f0();
                param2->status = 1;
                break;
            }
            else
            {
                pRayCastParam->pathArray.Clear(true);
                param2->status = 2;
                break;
            }
        }
        else
        {
            pRayCastParam->pathArray.BSSimpleArray_NavMeshEdgeLocation_1024_Remove(0, 1);
            if (pRayCastParam->pathArray.IsEmpty())
            {
                param2->status = 2;
                break;
            }
            else
            {
                param2->status = 0;
            }
        }
    }

    this->PathingSearchRayCast_CleanUpRayCasts();
    return param2->status;
}

struct FormX
{
    unsigned int FUN_00441110();
    int FUN_006dd540();
    int FUN_006dd4f0();
};

struct ListX
{
    void FreeArray(int i);
};
struct GroupX
{
    void FUN_006c90d0(FormX* pkForm);
    char pad[8];
    ListX kList;
};
struct GlobX
{
    void FUN_00408d60();
};
struct DialX
{
    PathingRequest* m_pkActor;
    GroupX* m_pkActorGroup;
    bool BuildRoute(void* pkA, void* pkB);
    bool PathBuilder_BuildTeleportDoorPath();
    bool PathBuilder_BuildHighLevelPath(void* pkA, void* pkB);
};
// For equal non-null arguments, adds two actor offsets; otherwise may call BuildRoute, then clear a list and call FUN_006c9b20.
// @fnv 0x006c8f50
// src: COMMUNITY 0x006c8f50
bool DialX::PathBuilder_BuildHighLevelPath(void* pkA, void* pkB)
{
    bool bResult = false;
    if (pkA && pkB)
    {
        if (pkA == pkB)
        {
            m_pkActorGroup->FUN_006c90d0((FormX*)&m_pkActor->GetOffsetC());
            m_pkActorGroup->FUN_006c90d0((FormX*)m_pkActor->NiAVObject_GetRotate_006a9540());
            bResult = true;
        }
        else if (BuildRoute(pkA, pkB))
        {
            bResult = true;
        }
    }
    else
    {
        DAT_011d7450.Bool();
    }
    if (0)
    {
    }
    if (0)
    {
    }
    if (!bResult)
    {
        if (m_pkActor->GetOffsetC().FUN_00441110())
        {
            if (m_pkActor->GetOffsetC().FUN_00441110() == m_pkActor->NiAVObject_GetRotate_006a9540()->FUN_00441110() &&
                m_pkActor->GetOffsetC().GetAssociatedNavMesh() && m_pkActor->NiAVObject_GetRotate_006a9540()->GetAssociatedNavMesh())
                return false;
        }
        else
        {
            if (m_pkActor->GetOffsetC().FUN_006dd4f0() == m_pkActor->NiAVObject_GetRotate_006a9540()->FUN_006dd4f0() &&
                m_pkActor->GetOffsetC().GetAssociatedNavMesh() && m_pkActor->NiAVObject_GetRotate_006a9540()->GetAssociatedNavMesh())
                return false;
        }
        m_pkActorGroup->kList.FreeArray(0);
        if (!PathBuilder_BuildTeleportDoorPath())
            return false;
    }
    return true;
}

struct RoutePoint
{
    float x, y, z;
};
struct RouteInfo
{
    RoutePoint FUN_005c3420();
};
struct RouteLock;
struct RouteRequest
{
    bool FUN_0073cb80();
    RouteLock* GetActorLockData();
    bool GetIgnoreLocks_006a79a0();
    RouteInfo& NiAVObject_GetRotate_006a9540();
    RouteInfo& GetOffsetC();
};
struct RouteCell
{
    RoutePoint& FUN_00717e50();
};
struct RoutePortal
{
    RoutePoint& TESObjectREFR_GetLinkedDoorTeleportPosition();
    RouteCell* FUN_00568e50();
};
struct RouteInfos
{
    unsigned unk00, unk04, unk08, unk0c, unk10;
    RouteInfos(int, int, void*);
    ~RouteInfos();
    unsigned FUN_0044ddc0();
    RouteInfo*& FUN_00877a30(unsigned);
};
struct RoutePortals
{
    unsigned unk00, unk04, unk08, unk0c, unk10;
    RoutePortals(int, int, void*);
    ~RoutePortals();
    RoutePortal*& FUN_00877a30(unsigned);
};
struct RouteSearch
{
    unsigned unk0000;
    unsigned unk0004;
    unsigned unk0008;
    unsigned unk000c;
    unsigned unk0010;
    unsigned unk0014;
    unsigned unk0018;
    unsigned unk001c;
    unsigned unk0020;
    unsigned unk0024;
    unsigned unk0028;
    unsigned unk002c;
    unsigned unk0030;
    unsigned unk0034;
    unsigned unk0038;
    unsigned unk003c;
    unsigned unk0040;
    unsigned unk0044;
    unsigned unk0048;
    unsigned unk004c;
    unsigned unk0050;
    unsigned unk0054;
    unsigned unk0058;
    unsigned unk005c;
    unsigned unk0060;
    unsigned unk0064;
    unsigned unk0068;
    unsigned unk006c;
    unsigned unk0070;
    unsigned unk0074;
    unsigned unk0078;
    unsigned unk007c;
    unsigned unk0080;
    unsigned unk0084;
    unsigned unk0088;
    unsigned unk008c;
    unsigned unk0090;
    unsigned unk0094;
    unsigned unk0098;
    unsigned unk009c;
    unsigned unk00a0;
    unsigned unk00a4;
    unsigned unk00a8;
    unsigned unk00ac;
    unsigned unk00b0;
    unsigned unk00b4;
    unsigned unk00b8;
    unsigned unk00bc;
    unsigned unk00c0;
    unsigned unk00c4;
    unsigned unk00c8;
    unsigned unk00cc;
    unsigned unk00d0;
    unsigned unk00d4;
    unsigned unk00d8;
    unsigned unk00dc;
    unsigned unk00e0;
    unsigned unk00e4;
    unsigned unk00e8;
    unsigned unk00ec;
    unsigned unk00f0;
    unsigned unk00f4;
    unsigned unk00f8;
    unsigned unk00fc;
    unsigned unk0100;
    unsigned unk0104;
    unsigned unk0108;
    unsigned unk010c;
    unsigned unk0110;
    unsigned unk0114;
    unsigned unk0118;
    unsigned unk011c;
    unsigned unk0120;
    unsigned unk0124;
    unsigned unk0128;
    unsigned unk012c;
    unsigned unk0130;
    unsigned unk0134;
    unsigned unk0138;
    unsigned unk013c;
    unsigned unk0140;
    unsigned unk0144;
    unsigned unk0148;
    unsigned unk014c;
    unsigned unk0150;
    unsigned unk0154;
    unsigned unk0158;
    unsigned unk015c;
    unsigned unk0160;
    unsigned unk0164;
    unsigned unk0168;
    unsigned unk016c;
    unsigned unk0170;
    unsigned unk0174;
    unsigned unk0178;
    unsigned unk017c;
    unsigned unk0180;
    unsigned unk0184;
    unsigned unk0188;
    unsigned unk018c;
    unsigned unk0190;
    unsigned unk0194;
    unsigned unk0198;
    unsigned unk019c;
    unsigned unk01a0;
    unsigned unk01a4;
    unsigned unk01a8;
    unsigned unk01ac;
    unsigned unk01b0;
    unsigned unk01b4;
    unsigned unk01b8;
    unsigned unk01bc;
    unsigned unk01c0;
    unsigned unk01c4;
    unsigned unk01c8;
    unsigned unk01cc;
    unsigned unk01d0;
    unsigned unk01d4;
    unsigned unk01d8;
    unsigned unk01dc;
    unsigned unk01e0;
    unsigned unk01e4;
    unsigned unk01e8;
    unsigned unk01ec;
    unsigned unk01f0;
    unsigned unk01f4;
    unsigned unk01f8;
    unsigned unk01fc;
    unsigned unk0200;
    unsigned unk0204;
    unsigned unk0208;
    unsigned unk020c;
    unsigned unk0210;
    unsigned unk0214;
    unsigned unk0218;
    unsigned unk021c;
    unsigned unk0220;
    unsigned unk0224;
    unsigned unk0228;
    unsigned unk022c;
    unsigned unk0230;
    unsigned unk0234;
    unsigned unk0238;
    unsigned unk023c;
    unsigned unk0240;
    unsigned unk0244;
    unsigned unk0248;
    unsigned unk024c;
    unsigned unk0250;
    unsigned unk0254;
    unsigned unk0258;
    unsigned unk025c;
    unsigned unk0260;
    unsigned unk0264;
    unsigned unk0268;
    unsigned unk026c;
    unsigned unk0270;
    unsigned unk0274;
    unsigned unk0278;
    unsigned unk027c;
    unsigned unk0280;
    unsigned unk0284;
    unsigned unk0288;
    unsigned unk028c;
    unsigned unk0290;
    unsigned unk0294;
    unsigned unk0298;
    unsigned unk029c;
    unsigned unk02a0;
    unsigned unk02a4;
    unsigned unk02a8;
    unsigned unk02ac;
    unsigned unk02b0;
    unsigned unk02b4;
    unsigned unk02b8;
    unsigned unk02bc;
    unsigned unk02c0;
    unsigned unk02c4;
    unsigned unk02c8;
    unsigned unk02cc;
    unsigned unk02d0;
    unsigned unk02d4;
    unsigned unk02d8;
    unsigned unk02dc;
    unsigned unk02e0;
    unsigned unk02e4;
    unsigned unk02e8;
    unsigned unk02ec;
    unsigned unk02f0;
    unsigned unk02f4;
    unsigned unk02f8;
    unsigned unk02fc;
    unsigned unk0300;
    unsigned unk0304;
    unsigned unk0308;
    unsigned unk030c;
    unsigned unk0310;
    unsigned unk0314;
    unsigned unk0318;
    unsigned unk031c;
    unsigned unk0320;
    unsigned unk0324;
    unsigned unk0328;
    unsigned unk032c;
    unsigned unk0330;
    unsigned unk0334;
    unsigned unk0338;
    unsigned unk033c;
    unsigned unk0340;
    unsigned unk0344;
    unsigned unk0348;
    unsigned unk034c;
    unsigned unk0350;
    unsigned unk0354;
    unsigned unk0358;
    unsigned unk035c;
    unsigned unk0360;
    unsigned unk0364;
    unsigned unk0368;
    unsigned unk036c;
    unsigned unk0370;
    unsigned unk0374;
    unsigned unk0378;
    unsigned unk037c;
    unsigned unk0380;
    unsigned unk0384;
    unsigned unk0388;
    unsigned unk038c;
    unsigned unk0390;
    unsigned unk0394;
    unsigned unk0398;
    unsigned unk039c;
    unsigned unk03a0;
    unsigned unk03a4;
    unsigned unk03a8;
    unsigned unk03ac;
    unsigned unk03b0;
    unsigned unk03b4;
    unsigned unk03b8;
    unsigned unk03bc;
    unsigned unk03c0;
    unsigned unk03c4;
    unsigned unk03c8;
    unsigned unk03cc;
    unsigned unk03d0;
    unsigned unk03d4;
    unsigned unk03d8;
    unsigned unk03dc;
    unsigned unk03e0;
    unsigned unk03e4;
    unsigned unk03e8;
    unsigned unk03ec;
    unsigned unk03f0;
    unsigned unk03f4;
    unsigned unk03f8;
    unsigned unk03fc;
    unsigned unk0400;
    unsigned unk0404;
    unsigned unk0408;
    unsigned unk040c;
    unsigned unk0410;
    unsigned unk0414;
    unsigned unk0418;
    unsigned unk041c;
    unsigned unk0420;
    unsigned unk0424;
    unsigned unk0428;
    unsigned unk042c;
    unsigned unk0430;
    unsigned unk0434;
    unsigned unk0438;
    unsigned unk043c;
    unsigned unk0440;
    unsigned unk0444;
    unsigned unk0448;
    unsigned unk044c;
    unsigned unk0450;
    unsigned unk0454;
    unsigned unk0458;
    unsigned unk045c;
    unsigned unk0460;
    unsigned unk0464;
    unsigned unk0468;
    unsigned unk046c;
    unsigned unk0470;
    unsigned unk0474;
    unsigned unk0478;
    unsigned unk047c;
    unsigned unk0480;
    unsigned unk0484;
    unsigned unk0488;
    unsigned unk048c;
    unsigned unk0490;
    unsigned unk0494;
    unsigned unk0498;
    unsigned unk049c;
    unsigned unk04a0;
    unsigned unk04a4;
    unsigned unk04a8;
    unsigned unk04ac;
    unsigned unk04b0;
    unsigned unk04b4;
    unsigned unk04b8;
    unsigned unk04bc;
    unsigned unk04c0;
    unsigned unk04c4;
    unsigned unk04c8;
    unsigned unk04cc;
    unsigned unk04d0;
    unsigned unk04d4;
    unsigned unk04d8;
    unsigned unk04dc;
    unsigned unk04e0;
    unsigned unk04e4;
    unsigned unk04e8;
    unsigned unk04ec;
    unsigned unk04f0;
    unsigned unk04f4;
    unsigned unk04f8;
    unsigned unk04fc;
    unsigned unk0500;
    unsigned unk0504;
    unsigned unk0508;
    unsigned unk050c;
    unsigned unk0510;
    unsigned unk0514;
    unsigned unk0518;
    unsigned unk051c;
    unsigned unk0520;
    unsigned unk0524;
    unsigned unk0528;
    unsigned unk052c;
    unsigned unk0530;
    unsigned unk0534;
    unsigned unk0538;
    unsigned unk053c;
    unsigned unk0540;
    unsigned unk0544;
    unsigned unk0548;
    unsigned unk054c;
    unsigned unk0550;
    unsigned unk0554;
    unsigned unk0558;
    unsigned unk055c;
    unsigned unk0560;
    unsigned unk0564;
    unsigned unk0568;
    unsigned unk056c;
    unsigned unk0570;
    unsigned unk0574;
    unsigned unk0578;
    unsigned unk057c;
    unsigned unk0580;
    unsigned unk0584;
    unsigned unk0588;
    unsigned unk058c;
    unsigned unk0590;
    unsigned unk0594;
    unsigned unk0598;
    unsigned unk059c;
    unsigned unk05a0;
    unsigned unk05a4;
    unsigned unk05a8;
    unsigned unk05ac;
    unsigned unk05b0;
    unsigned unk05b4;
    unsigned unk05b8;
    unsigned unk05bc;
    unsigned unk05c0;
    unsigned unk05c4;
    unsigned unk05c8;
    unsigned unk05cc;
    unsigned unk05d0;
    unsigned unk05d4;
    unsigned unk05d8;
    unsigned unk05dc;
    unsigned unk05e0;
    unsigned unk05e4;
    unsigned unk05e8;
    unsigned unk05ec;
    unsigned unk05f0;
    unsigned unk05f4;
    unsigned unk05f8;
    unsigned unk05fc;
    unsigned unk0600;
    unsigned unk0604;
    unsigned unk0608;
    unsigned unk060c;
    unsigned unk0610;
    unsigned unk0614;
    unsigned unk0618;
    unsigned unk061c;
    unsigned unk0620;
    unsigned unk0624;
    unsigned unk0628;
    unsigned unk062c;
    unsigned unk0630;
    unsigned unk0634;
    unsigned unk0638;
    unsigned unk063c;
    unsigned unk0640;
    unsigned unk0644;
    unsigned unk0648;
    unsigned unk064c;
    unsigned unk0650;
    unsigned unk0654;
    unsigned unk0658;
    unsigned unk065c;
    unsigned unk0660;
    unsigned unk0664;
    unsigned unk0668;
    unsigned unk066c;
    unsigned unk0670;
    unsigned unk0674;
    unsigned unk0678;
    unsigned unk067c;
    unsigned unk0680;
    unsigned unk0684;
    unsigned unk0688;
    unsigned unk068c;
    unsigned unk0690;
    unsigned unk0694;
    unsigned unk0698;
    unsigned unk069c;
    unsigned unk06a0;
    unsigned unk06a4;
    unsigned unk06a8;
    unsigned unk06ac;
    unsigned unk06b0;
    unsigned unk06b4;
    unsigned unk06b8;
    unsigned unk06bc;
    unsigned unk06c0;
    unsigned unk06c4;
    unsigned unk06c8;
    unsigned unk06cc;
    unsigned unk06d0;
    unsigned unk06d4;
    unsigned unk06d8;
    unsigned unk06dc;
    unsigned unk06e0;
    unsigned unk06e4;
    unsigned unk06e8;
    unsigned unk06ec;
    unsigned unk06f0;
    unsigned unk06f4;
    unsigned unk06f8;
    unsigned unk06fc;
    unsigned unk0700;
    unsigned unk0704;
    unsigned unk0708;
    unsigned unk070c;
    unsigned unk0710;
    unsigned unk0714;
    unsigned unk0718;
    unsigned unk071c;
    unsigned unk0720;
    unsigned unk0724;
    unsigned unk0728;
    unsigned unk072c;
    unsigned unk0730;
    unsigned unk0734;
    unsigned unk0738;
    unsigned unk073c;
    unsigned unk0740;
    unsigned unk0744;
    unsigned unk0748;
    unsigned unk074c;
    unsigned unk0750;
    unsigned unk0754;
    unsigned unk0758;
    unsigned unk075c;
    unsigned unk0760;
    unsigned unk0764;
    unsigned unk0768;
    unsigned unk076c;
    unsigned unk0770;
    unsigned unk0774;
    unsigned unk0778;
    unsigned unk077c;
    unsigned unk0780;
    unsigned unk0784;
    unsigned unk0788;
    unsigned unk078c;
    unsigned unk0790;
    unsigned unk0794;
    unsigned unk0798;
    unsigned unk079c;
    unsigned unk07a0;
    unsigned unk07a4;
    unsigned unk07a8;
    unsigned unk07ac;
    unsigned unk07b0;
    unsigned unk07b4;
    unsigned unk07b8;
    unsigned unk07bc;
    unsigned unk07c0;
    unsigned unk07c4;
    unsigned unk07c8;
    unsigned unk07cc;
    unsigned unk07d0;
    unsigned unk07d4;
    unsigned unk07d8;
    unsigned unk07dc;
    unsigned unk07e0;
    unsigned unk07e4;
    unsigned unk07e8;
    unsigned unk07ec;
    unsigned unk07f0;
    unsigned unk07f4;
    unsigned unk07f8;
    unsigned unk07fc;
    unsigned unk0800;
    unsigned unk0804;
    unsigned unk0808;
    unsigned unk080c;
    unsigned unk0810;
    unsigned unk0814;
    unsigned unk0818;
    unsigned unk081c;
    unsigned unk0820;
    unsigned unk0824;
    unsigned unk0828;
    unsigned unk082c;
    unsigned unk0830;
    unsigned unk0834;
    unsigned unk0838;
    unsigned unk083c;
    unsigned unk0840;
    unsigned unk0844;
    unsigned unk0848;
    unsigned unk084c;
    unsigned unk0850;
    unsigned unk0854;
    unsigned unk0858;
    unsigned unk085c;
    unsigned unk0860;
    unsigned unk0864;
    unsigned unk0868;
    unsigned unk086c;
    unsigned unk0870;
    unsigned unk0874;
    unsigned unk0878;
    unsigned unk087c;
    unsigned unk0880;
    unsigned unk0884;
    unsigned unk0888;
    unsigned unk088c;
    unsigned unk0890;
    unsigned unk0894;
    unsigned unk0898;
    unsigned unk089c;
    unsigned unk08a0;
    unsigned unk08a4;
    unsigned unk08a8;
    unsigned unk08ac;
    unsigned unk08b0;
    unsigned unk08b4;
    unsigned unk08b8;
    unsigned unk08bc;
    unsigned unk08c0;
    unsigned unk08c4;
    unsigned unk08c8;
    unsigned unk08cc;
    unsigned unk08d0;
    unsigned unk08d4;
    unsigned unk08d8;
    unsigned unk08dc;
    unsigned unk08e0;
    unsigned unk08e4;
    unsigned unk08e8;
    unsigned unk08ec;
    unsigned unk08f0;
    unsigned unk08f4;
    unsigned unk08f8;
    unsigned unk08fc;
    unsigned unk0900;
    unsigned unk0904;
    unsigned unk0908;
    unsigned unk090c;
    unsigned unk0910;
    unsigned unk0914;
    unsigned unk0918;
    unsigned unk091c;
    unsigned unk0920;
    unsigned unk0924;
    unsigned unk0928;
    unsigned unk092c;
    unsigned unk0930;
    unsigned unk0934;
    unsigned unk0938;
    unsigned unk093c;
    unsigned unk0940;
    unsigned unk0944;
    unsigned unk0948;
    unsigned unk094c;
    unsigned unk0950;
    unsigned unk0954;
    unsigned unk0958;
    unsigned unk095c;
    unsigned unk0960;
    unsigned unk0964;
    unsigned unk0968;
    unsigned unk096c;
    unsigned unk0970;
    unsigned unk0974;
    unsigned unk0978;
    unsigned unk097c;
    unsigned unk0980;
    unsigned unk0984;
    unsigned unk0988;
    unsigned unk098c;
    unsigned unk0990;
    unsigned unk0994;
    unsigned unk0998;
    unsigned unk099c;
    unsigned unk09a0;
    unsigned unk09a4;
    unsigned unk09a8;
    unsigned unk09ac;
    unsigned unk09b0;
    unsigned unk09b4;
    unsigned unk09b8;
    unsigned unk09bc;
    unsigned unk09c0;
    unsigned unk09c4;
    unsigned unk09c8;
    unsigned unk09cc;
    unsigned unk09d0;
    unsigned unk09d4;
    unsigned unk09d8;
    unsigned unk09dc;
    unsigned unk09e0;
    unsigned unk09e4;
    unsigned unk09e8;
    unsigned unk09ec;
    unsigned unk09f0;
    unsigned unk09f4;
    unsigned unk09f8;
    unsigned unk09fc;
    unsigned unk0a00;
    unsigned unk0a04;
    unsigned unk0a08;
    unsigned unk0a0c;
    unsigned unk0a10;
    unsigned unk0a14;
    unsigned unk0a18;
    unsigned unk0a1c;
    unsigned unk0a20;
    unsigned unk0a24;
    unsigned unk0a28;
    unsigned unk0a2c;
    unsigned unk0a30;
    unsigned unk0a34;
    unsigned unk0a38;
    unsigned unk0a3c;
    unsigned unk0a40;
    unsigned unk0a44;
    unsigned unk0a48;
    unsigned unk0a4c;
    unsigned unk0a50;
    unsigned unk0a54;
    unsigned unk0a58;
    unsigned unk0a5c;
    unsigned unk0a60;
    unsigned unk0a64;
    unsigned unk0a68;
    unsigned unk0a6c;
    unsigned unk0a70;
    unsigned unk0a74;
    unsigned unk0a78;
    unsigned unk0a7c;
    unsigned unk0a80;
    unsigned unk0a84;
    unsigned unk0a88;
    unsigned unk0a8c;
    unsigned unk0a90;
    unsigned unk0a94;
    unsigned unk0a98;
    unsigned unk0a9c;
    unsigned unk0aa0;
    unsigned unk0aa4;
    unsigned unk0aa8;
    unsigned unk0aac;
    unsigned unk0ab0;
    unsigned unk0ab4;
    unsigned unk0ab8;
    unsigned unk0abc;
    unsigned unk0ac0;
    unsigned unk0ac4;
    unsigned unk0ac8;
    unsigned unk0acc;
    unsigned unk0ad0;
    unsigned unk0ad4;
    unsigned unk0ad8;
    unsigned unk0adc;
    unsigned unk0ae0;
    unsigned unk0ae4;
    unsigned unk0ae8;
    unsigned unk0aec;
    unsigned unk0af0;
    unsigned unk0af4;
    unsigned unk0af8;
    unsigned unk0afc;
    unsigned unk0b00;
    unsigned unk0b04;
    unsigned unk0b08;
    unsigned unk0b0c;
    unsigned unk0b10;
    unsigned unk0b14;
    unsigned unk0b18;
    unsigned unk0b1c;
    unsigned unk0b20;
    unsigned unk0b24;
    unsigned unk0b28;
    unsigned unk0b2c;
    unsigned unk0b30;
    unsigned unk0b34;
    unsigned unk0b38;
    unsigned unk0b3c;
    unsigned unk0b40;
    unsigned unk0b44;
    unsigned unk0b48;
    unsigned unk0b4c;
    unsigned unk0b50;
    unsigned unk0b54;
    unsigned unk0b58;
    unsigned unk0b5c;
    unsigned unk0b60;
    unsigned unk0b64;
    unsigned unk0b68;
    unsigned unk0b6c;
    unsigned unk0b70;
    unsigned unk0b74;
    unsigned unk0b78;
    unsigned unk0b7c;
    unsigned unk0b80;
    unsigned unk0b84;
    unsigned unk0b88;
    unsigned unk0b8c;
    unsigned unk0b90;
    unsigned unk0b94;
    unsigned unk0b98;
    unsigned unk0b9c;
    unsigned unk0ba0;
    unsigned unk0ba4;
    unsigned unk0ba8;
    unsigned unk0bac;
    unsigned unk0bb0;
    unsigned unk0bb4;
    unsigned unk0bb8;
    unsigned unk0bbc;
    unsigned unk0bc0;
    unsigned unk0bc4;
    unsigned unk0bc8;
    unsigned unk0bcc;
    unsigned unk0bd0;
    unsigned unk0bd4;
    unsigned unk0bd8;
    unsigned unk0bdc;
    unsigned unk0be0;
    unsigned unk0be4;
    unsigned unk0be8;
    unsigned unk0bec;
    unsigned unk0bf0;
    unsigned unk0bf4;
    unsigned unk0bf8;
    unsigned unk0bfc;
    unsigned unk0c00;
    unsigned unk0c04;
    unsigned unk0c08;
    unsigned unk0c0c;
    unsigned unk0c10;
    unsigned unk0c14;
    unsigned unk0c18;
    unsigned unk0c1c;
    unsigned unk0c20;
    unsigned unk0c24;
    unsigned unk0c28;
    unsigned unk0c2c;
    unsigned unk0c30;
    unsigned unk0c34;
    unsigned unk0c38;
    unsigned unk0c3c;
    unsigned unk0c40;
    unsigned unk0c44;
    unsigned unk0c48;
    unsigned unk0c4c;
    unsigned unk0c50;
    unsigned unk0c54;
    unsigned unk0c58;
    unsigned unk0c5c;
    unsigned unk0c60;
    unsigned unk0c64;
    unsigned unk0c68;
    unsigned unk0c6c;
    unsigned unk0c70;
    unsigned unk0c74;
    unsigned unk0c78;
    unsigned unk0c7c;
    unsigned unk0c80;
    unsigned unk0c84;
    unsigned unk0c88;
    unsigned unk0c8c;
    unsigned unk0c90;
    unsigned unk0c94;
    unsigned unk0c98;
    unsigned unk0c9c;
    unsigned unk0ca0;
    unsigned unk0ca4;
    unsigned unk0ca8;
    unsigned unk0cac;
    unsigned unk0cb0;
    unsigned unk0cb4;
    unsigned unk0cb8;
    unsigned unk0cbc;
    unsigned unk0cc0;
    unsigned unk0cc4;
    unsigned unk0cc8;
    unsigned unk0ccc;
    unsigned unk0cd0;
    unsigned unk0cd4;
    unsigned unk0cd8;
    unsigned unk0cdc;
    unsigned unk0ce0;
    unsigned unk0ce4;
    unsigned unk0ce8;
    unsigned unk0cec;
    unsigned unk0cf0;
    unsigned unk0cf4;
    unsigned unk0cf8;
    unsigned unk0cfc;
    unsigned unk0d00;
    unsigned unk0d04;
    unsigned unk0d08;
    unsigned unk0d0c;
    unsigned unk0d10;
    unsigned unk0d14;
    unsigned unk0d18;
    unsigned unk0d1c;
    unsigned unk0d20;
    unsigned unk0d24;
    unsigned unk0d28;
    unsigned unk0d2c;
    unsigned unk0d30;
    unsigned unk0d34;
    unsigned unk0d38;
    unsigned unk0d3c;
    unsigned unk0d40;
    unsigned unk0d44;
    unsigned unk0d48;
    unsigned unk0d4c;
    unsigned unk0d50;
    unsigned unk0d54;
    unsigned unk0d58;
    unsigned unk0d5c;
    unsigned unk0d60;
    unsigned unk0d64;
    unsigned unk0d68;
    unsigned unk0d6c;
    unsigned unk0d70;
    unsigned unk0d74;
    unsigned unk0d78;
    unsigned unk0d7c;
    unsigned unk0d80;
    unsigned unk0d84;
    unsigned unk0d88;
    unsigned unk0d8c;
    unsigned unk0d90;
    unsigned unk0d94;
    unsigned unk0d98;
    unsigned unk0d9c;
    unsigned unk0da0;
    unsigned unk0da4;
    unsigned unk0da8;
    unsigned unk0dac;
    unsigned unk0db0;
    unsigned unk0db4;
    unsigned unk0db8;
    unsigned unk0dbc;
    unsigned unk0dc0;
    unsigned unk0dc4;
    unsigned unk0dc8;
    unsigned unk0dcc;
    unsigned unk0dd0;
    unsigned unk0dd4;
    unsigned unk0dd8;
    unsigned unk0ddc;
    unsigned unk0de0;
    unsigned unk0de4;
    unsigned unk0de8;
    unsigned unk0dec;
    unsigned unk0df0;
    unsigned unk0df4;
    unsigned unk0df8;
    unsigned unk0dfc;
    unsigned unk0e00;
    unsigned unk0e04;
    unsigned unk0e08;
    unsigned unk0e0c;
    unsigned unk0e10;
    unsigned unk0e14;
    unsigned unk0e18;
    unsigned unk0e1c;
    unsigned unk0e20;
    unsigned unk0e24;
    unsigned unk0e28;
    unsigned unk0e2c;
    unsigned unk0e30;
    unsigned unk0e34;
    unsigned unk0e38;
    unsigned unk0e3c;
    unsigned unk0e40;
    unsigned unk0e44;
    unsigned unk0e48;
    unsigned unk0e4c;
    unsigned unk0e50;
    unsigned unk0e54;
    unsigned unk0e58;
    unsigned unk0e5c;
    unsigned unk0e60;
    unsigned unk0e64;
    unsigned unk0e68;
    unsigned unk0e6c;
    unsigned unk0e70;
    unsigned unk0e74;
    unsigned unk0e78;
    unsigned unk0e7c;
    unsigned unk0e80;
    unsigned unk0e84;
    unsigned unk0e88;
    unsigned unk0e8c;
    unsigned unk0e90;
    unsigned unk0e94;
    unsigned unk0e98;
    unsigned unk0e9c;
    unsigned unk0ea0;
    unsigned unk0ea4;
    unsigned unk0ea8;
    unsigned unk0eac;
    unsigned unk0eb0;
    unsigned unk0eb4;
    unsigned unk0eb8;
    unsigned unk0ebc;
    unsigned unk0ec0;
    unsigned unk0ec4;
    unsigned unk0ec8;
    unsigned unk0ecc;
    unsigned unk0ed0;
    unsigned unk0ed4;
    unsigned unk0ed8;
    unsigned unk0edc;
    unsigned unk0ee0;
    unsigned unk0ee4;
    unsigned unk0ee8;
    unsigned unk0eec;
    unsigned unk0ef0;
    unsigned unk0ef4;
    unsigned unk0ef8;
    unsigned unk0efc;
    unsigned unk0f00;
    unsigned unk0f04;
    unsigned unk0f08;
    unsigned unk0f0c;
    unsigned unk0f10;
    unsigned unk0f14;
    unsigned unk0f18;
    unsigned unk0f1c;
    unsigned unk0f20;
    unsigned unk0f24;
    unsigned unk0f28;
    unsigned unk0f2c;
    unsigned unk0f30;
    unsigned unk0f34;
    unsigned unk0f38;
    unsigned unk0f3c;
    unsigned unk0f40;
    unsigned unk0f44;
    unsigned unk0f48;
    unsigned unk0f4c;
    unsigned unk0f50;
    unsigned unk0f54;
    unsigned unk0f58;
    unsigned unk0f5c;
    unsigned unk0f60;
    unsigned unk0f64;
    unsigned unk0f68;
    unsigned unk0f6c;
    unsigned unk0f70;
    unsigned unk0f74;
    unsigned unk0f78;
    unsigned unk0f7c;
    unsigned unk0f80;
    unsigned unk0f84;
    unsigned unk0f88;
    unsigned unk0f8c;
    unsigned unk0f90;
    unsigned unk0f94;
    unsigned unk0f98;
    unsigned unk0f9c;
    unsigned unk0fa0;
    unsigned unk0fa4;
    unsigned unk0fa8;
    unsigned unk0fac;
    unsigned unk0fb0;
    unsigned unk0fb4;
    unsigned unk0fb8;
    unsigned unk0fbc;
    unsigned unk0fc0;
    unsigned unk0fc4;
    unsigned unk0fc8;
    unsigned unk0fcc;
    unsigned unk0fd0;
    unsigned unk0fd4;
    unsigned unk0fd8;
    unsigned unk0fdc;
    unsigned unk0fe0;
    unsigned unk0fe4;
    unsigned unk0fe8;
    unsigned unk0fec;
    unsigned unk0ff0;
    unsigned unk0ff4;
    unsigned unk0ff8;
    unsigned unk0ffc;
    unsigned unk1000;
    unsigned unk1004;
    unsigned unk1008;
    unsigned unk100c;
    unsigned unk1010;
    unsigned unk1014;
    unsigned unk1018;
    unsigned unk101c;
    unsigned unk1020;
    unsigned unk1024;
    unsigned unk1028;
    unsigned unk102c;
    unsigned unk1030;
    unsigned unk1034;
    unsigned unk1038;
    unsigned unk103c;
    unsigned unk1040;
    unsigned unk1044;
    unsigned unk1048;
    unsigned unk104c;
    unsigned unk1050;
    unsigned unk1054;
    unsigned unk1058;
    unsigned unk105c;
    unsigned unk1060;
    unsigned unk1064;
    unsigned unk1068;
    unsigned unk106c;
    unsigned unk1070;
    unsigned unk1074;
    unsigned unk1078;
    unsigned unk107c;
    unsigned unk1080;
    unsigned unk1084;
    unsigned unk1088;
    unsigned unk108c;
    unsigned unk1090;
    unsigned unk1094;
    unsigned unk1098;
    unsigned unk109c;
    unsigned unk10a0;
    unsigned unk10a4;
    unsigned unk10a8;
    unsigned unk10ac;
    unsigned unk10b0;
    unsigned unk10b4;
    unsigned unk10b8;
    unsigned unk10bc;
    unsigned unk10c0;
    unsigned unk10c4;
    unsigned unk10c8;
    unsigned unk10cc;
    unsigned unk10d0;
    unsigned unk10d4;
    unsigned unk10d8;
    unsigned unk10dc;
    unsigned unk10e0;
    unsigned unk10e4;
    unsigned unk10e8;
    unsigned unk10ec;
    unsigned unk10f0;
    unsigned unk10f4;
    unsigned unk10f8;
    unsigned unk10fc;
    unsigned unk1100;
    unsigned unk1104;
    unsigned unk1108;
    unsigned unk110c;
    unsigned unk1110;
    unsigned unk1114;
    unsigned unk1118;
    unsigned unk111c;
    unsigned unk1120;
    unsigned unk1124;
    unsigned unk1128;
    unsigned unk112c;
    unsigned unk1130;
    unsigned unk1134;
    unsigned unk1138;
    unsigned unk113c;
    unsigned unk1140;
    unsigned unk1144;
    unsigned unk1148;
    unsigned unk114c;
    unsigned unk1150;
    unsigned unk1154;
    unsigned unk1158;
    unsigned unk115c;
    unsigned unk1160;
    unsigned unk1164;
    unsigned unk1168;
    unsigned unk116c;
    unsigned unk1170;
    unsigned unk1174;
    unsigned unk1178;
    unsigned unk117c;
    unsigned unk1180;
    unsigned unk1184;
    unsigned unk1188;
    unsigned unk118c;
    unsigned unk1190;
    unsigned unk1194;
    unsigned unk1198;
    unsigned unk119c;
    unsigned unk11a0;
    unsigned unk11a4;
    unsigned unk11a8;
    unsigned unk11ac;
    unsigned unk11b0;
    unsigned unk11b4;
    unsigned unk11b8;
    unsigned unk11bc;
    unsigned unk11c0;
    unsigned unk11c4;
    unsigned unk11c8;
    unsigned unk11cc;
    unsigned unk11d0;
    unsigned unk11d4;
    unsigned unk11d8;
    unsigned unk11dc;
    unsigned unk11e0;
    unsigned unk11e4;
    unsigned unk11e8;
    unsigned unk11ec;
    unsigned unk11f0;
    unsigned unk11f4;
    unsigned unk11f8;
    unsigned unk11fc;
    unsigned unk1200;
    unsigned unk1204;
    unsigned unk1208;
    unsigned unk120c;
    unsigned unk1210;
    unsigned unk1214;
    unsigned unk1218;
    unsigned unk121c;
    unsigned unk1220;
    unsigned unk1224;
    unsigned unk1228;
    unsigned unk122c;
    unsigned unk1230;
    unsigned unk1234;
    unsigned unk1238;
    unsigned unk123c;
    unsigned unk1240;
    unsigned unk1244;
    unsigned unk1248;
    unsigned unk124c;
    unsigned unk1250;
    unsigned unk1254;
    unsigned unk1258;
    unsigned unk125c;
    unsigned unk1260;
    unsigned unk1264;
    unsigned unk1268;
    unsigned unk126c;
    unsigned unk1270;
    unsigned unk1274;
    unsigned unk1278;
    unsigned unk127c;
    unsigned unk1280;
    unsigned unk1284;
    unsigned unk1288;
    unsigned unk128c;
    unsigned unk1290;
    unsigned unk1294;
    unsigned unk1298;
    unsigned unk129c;
    unsigned unk12a0;
    unsigned unk12a4;
    unsigned unk12a8;
    unsigned unk12ac;
    unsigned unk12b0;
    unsigned unk12b4;
    unsigned unk12b8;
    unsigned unk12bc;
    unsigned unk12c0;
    unsigned unk12c4;
    unsigned unk12c8;
    unsigned unk12cc;
    unsigned unk12d0;
    unsigned unk12d4;
    unsigned unk12d8;
    unsigned unk12dc;
    unsigned unk12e0;
    unsigned unk12e4;
    unsigned unk12e8;
    unsigned unk12ec;
    unsigned unk12f0;
    unsigned unk12f4;
    unsigned unk12f8;
    unsigned unk12fc;
    unsigned unk1300;
    unsigned unk1304;
    unsigned unk1308;
    unsigned unk130c;
    unsigned unk1310;
    unsigned unk1314;
    unsigned unk1318;
    unsigned unk131c;
    unsigned unk1320;
    unsigned unk1324;
    unsigned unk1328;
    unsigned unk132c;
    unsigned unk1330;
    unsigned unk1334;
    unsigned unk1338;
    unsigned unk133c;
    unsigned unk1340;
    unsigned unk1344;
    unsigned unk1348;
    unsigned unk134c;
    unsigned unk1350;
    unsigned unk1354;
    unsigned unk1358;
    unsigned unk135c;
    unsigned unk1360;
    unsigned unk1364;
    unsigned unk1368;
    unsigned unk136c;
    unsigned unk1370;
    unsigned unk1374;
    unsigned unk1378;
    unsigned unk137c;
    unsigned unk1380;
    unsigned unk1384;
    unsigned unk1388;
    unsigned unk138c;
    unsigned unk1390;
    unsigned unk1394;
    unsigned unk1398;
    unsigned unk139c;
    unsigned unk13a0;
    unsigned unk13a4;
    unsigned unk13a8;
    unsigned unk13ac;
    unsigned unk13b0;
    unsigned unk13b4;
    unsigned unk13b8;
    unsigned unk13bc;
    unsigned unk13c0;
    unsigned unk13c4;
    unsigned unk13c8;
    unsigned unk13cc;
    unsigned unk13d0;
    unsigned unk13d4;
    unsigned unk13d8;
    unsigned unk13dc;
    unsigned unk13e0;
    unsigned unk13e4;
    unsigned unk13e8;
    unsigned unk13ec;
    unsigned unk13f0;
    unsigned unk13f4;
    unsigned unk13f8;
    unsigned unk13fc;
    unsigned unk1400;
    unsigned unk1404;
    unsigned unk1408;
    unsigned unk140c;
    unsigned unk1410;
    unsigned unk1414;
    unsigned unk1418;
    unsigned unk141c;
    unsigned unk1420;
    unsigned unk1424;
    unsigned unk1428;
    unsigned unk142c;
    unsigned unk1430;
    unsigned unk1434;
    unsigned unk1438;
    unsigned unk143c;
    unsigned unk1440;
    unsigned unk1444;
    unsigned unk1448;
    unsigned unk144c;
    unsigned unk1450;
    unsigned unk1454;
    unsigned unk1458;
    unsigned unk145c;
    unsigned unk1460;
    unsigned unk1464;
    unsigned unk1468;
    unsigned unk146c;
    unsigned unk1470;
    unsigned unk1474;
    unsigned unk1478;
    unsigned unk147c;
    unsigned unk1480;
    unsigned unk1484;
    unsigned unk1488;
    unsigned unk148c;
    unsigned unk1490;
    unsigned unk1494;
    unsigned unk1498;
    unsigned unk149c;
    unsigned unk14a0;
    unsigned unk14a4;
    unsigned unk14a8;
    unsigned unk14ac;
    unsigned unk14b0;
    unsigned unk14b4;
    unsigned unk14b8;
    unsigned unk14bc;
    unsigned unk14c0;
    unsigned unk14c4;
    unsigned unk14c8;
    unsigned unk14cc;
    unsigned unk14d0;
    unsigned unk14d4;
    unsigned unk14d8;
    unsigned unk14dc;
    unsigned unk14e0;
    unsigned unk14e4;
    unsigned unk14e8;
    unsigned unk14ec;
    unsigned unk14f0;
    unsigned unk14f4;
    unsigned unk14f8;
    unsigned unk14fc;
    unsigned unk1500;
    unsigned unk1504;
    unsigned unk1508;
    unsigned unk150c;
    unsigned unk1510;
    unsigned unk1514;
    unsigned unk1518;
    unsigned unk151c;
    unsigned unk1520;
    unsigned unk1524;
    unsigned unk1528;
    unsigned unk152c;
    unsigned unk1530;
    unsigned unk1534;
    unsigned unk1538;
    unsigned unk153c;
    unsigned unk1540;
    unsigned unk1544;
    unsigned unk1548;
    unsigned unk154c;
    unsigned unk1550;
    unsigned unk1554;
    unsigned unk1558;
    unsigned unk155c;
    unsigned unk1560;
    unsigned unk1564;
    unsigned unk1568;
    unsigned unk156c;
    unsigned unk1570;
    unsigned unk1574;
    unsigned unk1578;
    unsigned unk157c;
    unsigned unk1580;
    unsigned unk1584;
    unsigned unk1588;
    unsigned unk158c;
    unsigned unk1590;
    unsigned unk1594;
    unsigned unk1598;
    unsigned unk159c;
    unsigned unk15a0;
    unsigned unk15a4;
    unsigned unk15a8;
    unsigned unk15ac;
    unsigned unk15b0;
    unsigned unk15b4;
    unsigned unk15b8;
    unsigned unk15bc;
    unsigned unk15c0;
    unsigned unk15c4;
    unsigned unk15c8;
    unsigned unk15cc;
    unsigned unk15d0;
    unsigned unk15d4;
    unsigned unk15d8;
    unsigned unk15dc;
    unsigned unk15e0;
    unsigned unk15e4;
    unsigned unk15e8;
    unsigned unk15ec;
    unsigned unk15f0;
    unsigned unk15f4;
    unsigned unk15f8;
    unsigned unk15fc;
    unsigned unk1600;
    unsigned unk1604;
    unsigned unk1608;
    unsigned unk160c;
    unsigned unk1610;
    unsigned unk1614;
    unsigned unk1618;
    unsigned unk161c;
    unsigned unk1620;
    unsigned unk1624;
    unsigned unk1628;
    unsigned unk162c;
    unsigned unk1630;
    unsigned unk1634;
    unsigned unk1638;
    unsigned unk163c;
    unsigned unk1640;
    unsigned unk1644;
    unsigned unk1648;
    unsigned unk164c;
    unsigned unk1650;
    unsigned unk1654;
    unsigned unk1658;
    unsigned unk165c;
    unsigned unk1660;
    unsigned unk1664;
    unsigned unk1668;
    unsigned unk166c;
    unsigned unk1670;
    unsigned unk1674;
    unsigned unk1678;
    unsigned unk167c;
    unsigned unk1680;
    unsigned unk1684;
    unsigned unk1688;
    unsigned unk168c;
    unsigned unk1690;
    unsigned unk1694;
    unsigned unk1698;
    unsigned unk169c;
    unsigned unk16a0;
    unsigned unk16a4;
    unsigned unk16a8;
    unsigned unk16ac;
    unsigned unk16b0;
    unsigned unk16b4;
    unsigned unk16b8;
    unsigned unk16bc;
    unsigned unk16c0;
    unsigned unk16c4;
    unsigned unk16c8;
    unsigned unk16cc;
    unsigned unk16d0;
    unsigned unk16d4;
    unsigned unk16d8;
    unsigned unk16dc;
    unsigned unk16e0;
    unsigned unk16e4;
    unsigned unk16e8;
    unsigned unk16ec;
    unsigned unk16f0;
    unsigned unk16f4;
    unsigned unk16f8;
    unsigned unk16fc;
    unsigned unk1700;
    unsigned unk1704;
    unsigned unk1708;
    unsigned unk170c;
    unsigned unk1710;
    unsigned unk1714;
    unsigned unk1718;
    unsigned unk171c;
    unsigned unk1720;
    unsigned unk1724;
    unsigned unk1728;
    unsigned unk172c;
    unsigned unk1730;
    unsigned unk1734;
    unsigned unk1738;
    unsigned unk173c;
    unsigned unk1740;
    unsigned unk1744;
    unsigned unk1748;
    unsigned unk174c;
    unsigned unk1750;
    unsigned unk1754;
    unsigned unk1758;
    unsigned unk175c;
    unsigned unk1760;
    unsigned unk1764;
    unsigned unk1768;
    unsigned unk176c;
    unsigned unk1770;
    unsigned unk1774;
    unsigned unk1778;
    unsigned unk177c;
    unsigned unk1780;
    unsigned unk1784;
    unsigned unk1788;
    unsigned unk178c;
    unsigned unk1790;
    unsigned unk1794;
    unsigned unk1798;
    unsigned unk179c;
    unsigned unk17a0;
    unsigned unk17a4;
    unsigned unk17a8;
    unsigned unk17ac;
    unsigned unk17b0;
    unsigned unk17b4;
    unsigned unk17b8;
    unsigned unk17bc;
    unsigned unk17c0;
    unsigned unk17c4;
    unsigned unk17c8;
    unsigned unk17cc;
    unsigned unk17d0;
    unsigned unk17d4;
    unsigned unk17d8;
    unsigned unk17dc;
    unsigned unk17e0;
    unsigned unk17e4;
    unsigned unk17e8;
    unsigned unk17ec;
    unsigned unk17f0;
    unsigned unk17f4;
    unsigned unk17f8;
    unsigned unk17fc;
    unsigned unk1800;
    unsigned unk1804;
    unsigned unk1808;
    unsigned unk180c;
    unsigned unk1810;
    unsigned unk1814;
    unsigned unk1818;
    unsigned unk181c;
    unsigned unk1820;
    unsigned unk1824;
    unsigned unk1828;
    unsigned unk182c;
    unsigned unk1830;
    unsigned unk1834;
    unsigned unk1838;
    unsigned unk183c;
    unsigned unk1840;
    unsigned unk1844;
    unsigned unk1848;
    unsigned unk184c;
    unsigned unk1850;
    unsigned unk1854;
    unsigned unk1858;
    unsigned unk185c;
    unsigned unk1860;
    unsigned unk1864;
    unsigned unk1868;
    unsigned unk186c;
    unsigned unk1870;
    unsigned unk1874;
    unsigned unk1878;
    unsigned unk187c;
    unsigned unk1880;
    unsigned unk1884;
    unsigned unk1888;
    unsigned unk188c;
    unsigned unk1890;
    unsigned unk1894;
    unsigned unk1898;
    unsigned unk189c;
    unsigned unk18a0;
    unsigned unk18a4;
    unsigned unk18a8;
    unsigned unk18ac;
    unsigned unk18b0;
    unsigned unk18b4;
    unsigned unk18b8;
    unsigned unk18bc;
    unsigned unk18c0;
    unsigned unk18c4;
    unsigned unk18c8;
    unsigned unk18cc;
    unsigned unk18d0;
    unsigned unk18d4;
    unsigned unk18d8;
    unsigned unk18dc;
    unsigned unk18e0;
    unsigned unk18e4;
    unsigned unk18e8;
    unsigned unk18ec;
    unsigned unk18f0;
    unsigned unk18f4;
    unsigned unk18f8;
    unsigned unk18fc;
    unsigned unk1900;
    unsigned unk1904;
    unsigned unk1908;
    unsigned unk190c;
    unsigned unk1910;
    unsigned unk1914;
    unsigned unk1918;
    unsigned unk191c;
    unsigned unk1920;
    unsigned unk1924;
    unsigned unk1928;
    unsigned unk192c;
    unsigned unk1930;
    unsigned unk1934;
    unsigned unk1938;
    unsigned unk193c;
    unsigned unk1940;
    unsigned unk1944;
    unsigned unk1948;
    unsigned unk194c;
    unsigned unk1950;
    unsigned unk1954;
    unsigned unk1958;
    unsigned unk195c;
    unsigned unk1960;
    unsigned unk1964;
    unsigned unk1968;
    unsigned unk196c;
    unsigned unk1970;
    unsigned unk1974;
    unsigned unk1978;
    unsigned unk197c;
    unsigned unk1980;
    unsigned unk1984;
    unsigned unk1988;
    unsigned unk198c;
    unsigned unk1990;
    unsigned unk1994;
    unsigned unk1998;
    unsigned unk199c;
    unsigned unk19a0;
    unsigned unk19a4;
    unsigned unk19a8;
    unsigned unk19ac;
    unsigned unk19b0;
    unsigned unk19b4;
    unsigned unk19b8;
    unsigned unk19bc;
    unsigned unk19c0;
    unsigned unk19c4;
    unsigned unk19c8;
    unsigned unk19cc;
    unsigned unk19d0;
    unsigned unk19d4;
    unsigned unk19d8;
    unsigned unk19dc;
    unsigned unk19e0;
    unsigned unk19e4;
    unsigned unk19e8;
    unsigned unk19ec;
    unsigned unk19f0;
    unsigned unk19f4;
    unsigned unk19f8;
    unsigned unk19fc;
    unsigned unk1a00;
    unsigned unk1a04;
    unsigned unk1a08;
    unsigned unk1a0c;
    unsigned unk1a10;
    unsigned unk1a14;
    unsigned unk1a18;
    unsigned unk1a1c;
    unsigned unk1a20;
    unsigned unk1a24;
    unsigned unk1a28;
    unsigned unk1a2c;
    unsigned unk1a30;
    unsigned unk1a34;
    unsigned unk1a38;
    unsigned unk1a3c;
    unsigned unk1a40;
    unsigned unk1a44;
    unsigned unk1a48;
    unsigned unk1a4c;
    unsigned unk1a50;
    unsigned unk1a54;
    unsigned unk1a58;
    unsigned unk1a5c;
    unsigned unk1a60;
    unsigned unk1a64;
    unsigned unk1a68;
    unsigned unk1a6c;
    unsigned unk1a70;
    unsigned unk1a74;
    unsigned unk1a78;
    unsigned unk1a7c;
    unsigned unk1a80;
    unsigned unk1a84;
    unsigned unk1a88;
    unsigned unk1a8c;
    unsigned unk1a90;
    unsigned unk1a94;
    unsigned unk1a98;
    unsigned unk1a9c;
    unsigned unk1aa0;
    unsigned unk1aa4;
    unsigned unk1aa8;
    unsigned unk1aac;
    unsigned unk1ab0;
    unsigned unk1ab4;
    unsigned unk1ab8;
    unsigned unk1abc;
    unsigned unk1ac0;
    unsigned unk1ac4;
    unsigned unk1ac8;
    unsigned unk1acc;
    unsigned unk1ad0;
    unsigned unk1ad4;
    unsigned unk1ad8;
    unsigned unk1adc;
    unsigned unk1ae0;
    unsigned unk1ae4;
    unsigned unk1ae8;
    unsigned unk1aec;
    unsigned unk1af0;
    unsigned unk1af4;
    unsigned unk1af8;
    unsigned unk1afc;
    unsigned unk1b00;
    unsigned unk1b04;
    unsigned unk1b08;
    unsigned unk1b0c;
    unsigned unk1b10;
    unsigned unk1b14;
    unsigned unk1b18;
    unsigned unk1b1c;
    unsigned unk1b20;
    unsigned unk1b24;
    unsigned unk1b28;
    unsigned unk1b2c;
    unsigned unk1b30;
    unsigned unk1b34;
    unsigned unk1b38;
    unsigned unk1b3c;
    unsigned unk1b40;
    unsigned unk1b44;
    unsigned unk1b48;
    unsigned unk1b4c;
    unsigned unk1b50;
    unsigned unk1b54;
    unsigned unk1b58;
    unsigned unk1b5c;
    unsigned unk1b60;
    unsigned unk1b64;
    unsigned unk1b68;
    unsigned unk1b6c;
    unsigned unk1b70;
    unsigned unk1b74;
    unsigned unk1b78;
    unsigned unk1b7c;
    unsigned unk1b80;
    unsigned unk1b84;
    unsigned unk1b88;
    unsigned unk1b8c;
    unsigned unk1b90;
    unsigned unk1b94;
    unsigned unk1b98;
    unsigned unk1b9c;
    unsigned unk1ba0;
    unsigned unk1ba4;
    unsigned unk1ba8;
    unsigned unk1bac;
    unsigned unk1bb0;
    unsigned unk1bb4;
    unsigned unk1bb8;
    unsigned unk1bbc;
    unsigned unk1bc0;
    unsigned unk1bc4;
    unsigned unk1bc8;
    unsigned unk1bcc;
    unsigned unk1bd0;
    unsigned unk1bd4;
    unsigned unk1bd8;
    unsigned unk1bdc;
    unsigned unk1be0;
    unsigned unk1be4;
    unsigned unk1be8;
    unsigned unk1bec;
    unsigned unk1bf0;
    unsigned unk1bf4;
    unsigned unk1bf8;
    unsigned unk1bfc;
    unsigned unk1c00;
    unsigned unk1c04;
    unsigned unk1c08;
    unsigned unk1c0c;
    unsigned unk1c10;
    unsigned unk1c14;
    unsigned unk1c18;
    unsigned unk1c1c;
    unsigned unk1c20;
    unsigned unk1c24;
    unsigned unk1c28;
    unsigned unk1c2c;
    unsigned unk1c30;
    unsigned unk1c34;
    unsigned unk1c38;
    unsigned unk1c3c;
    unsigned unk1c40;
    unsigned unk1c44;
    unsigned unk1c48;
    unsigned unk1c4c;
    unsigned unk1c50;
    unsigned unk1c54;
    unsigned unk1c58;
    unsigned unk1c5c;
    unsigned unk1c60;
    unsigned unk1c64;
    unsigned unk1c68;
    unsigned unk1c6c;
    unsigned unk1c70;
    unsigned unk1c74;
    unsigned unk1c78;
    unsigned unk1c7c;
    unsigned unk1c80;
    unsigned unk1c84;
    unsigned unk1c88;
    unsigned unk1c8c;
    unsigned unk1c90;
    unsigned unk1c94;
    unsigned unk1c98;
    unsigned unk1c9c;
    unsigned unk1ca0;
    unsigned unk1ca4;
    unsigned unk1ca8;
    unsigned unk1cac;
    unsigned unk1cb0;
    unsigned unk1cb4;
    unsigned unk1cb8;
    unsigned unk1cbc;
    unsigned unk1cc0;
    unsigned unk1cc4;
    unsigned unk1cc8;
    unsigned unk1ccc;
    unsigned unk1cd0;
    unsigned unk1cd4;
    unsigned unk1cd8;
    unsigned unk1cdc;
    unsigned unk1ce0;
    unsigned unk1ce4;
    unsigned unk1ce8;
    unsigned unk1cec;
    unsigned unk1cf0;
    unsigned unk1cf4;
    unsigned unk1cf8;
    unsigned unk1cfc;
    unsigned unk1d00;
    unsigned unk1d04;
    unsigned unk1d08;
    unsigned unk1d0c;
    unsigned unk1d10;
    unsigned unk1d14;
    unsigned unk1d18;
    unsigned unk1d1c;
    unsigned unk1d20;
    unsigned unk1d24;
    unsigned unk1d28;
    unsigned unk1d2c;
    unsigned unk1d30;
    unsigned unk1d34;
    unsigned unk1d38;
    unsigned unk1d3c;
    unsigned unk1d40;
    unsigned unk1d44;
    unsigned unk1d48;
    unsigned unk1d4c;
    unsigned unk1d50;
    unsigned unk1d54;
    unsigned unk1d58;
    unsigned unk1d5c;
    unsigned unk1d60;
    unsigned unk1d64;
    unsigned unk1d68;
    unsigned unk1d6c;
    unsigned unk1d70;
    unsigned unk1d74;
    unsigned unk1d78;
    unsigned unk1d7c;
    unsigned unk1d80;
    unsigned unk1d84;
    unsigned unk1d88;
    unsigned unk1d8c;
    unsigned unk1d90;
    unsigned unk1d94;
    unsigned unk1d98;
    unsigned unk1d9c;
    unsigned unk1da0;
    unsigned unk1da4;
    unsigned unk1da8;
    unsigned unk1dac;
    unsigned unk1db0;
    unsigned unk1db4;
    unsigned unk1db8;
    unsigned unk1dbc;
    unsigned unk1dc0;
    unsigned unk1dc4;
    unsigned unk1dc8;
    unsigned unk1dcc;
    unsigned unk1dd0;
    unsigned unk1dd4;
    unsigned unk1dd8;
    unsigned unk1ddc;
    unsigned unk1de0;
    unsigned unk1de4;
    unsigned unk1de8;
    unsigned unk1dec;
    unsigned unk1df0;
    unsigned unk1df4;
    unsigned unk1df8;
    unsigned unk1dfc;
    unsigned unk1e00;
    unsigned unk1e04;
    unsigned unk1e08;
    unsigned unk1e0c;
    unsigned unk1e10;
    unsigned unk1e14;
    unsigned unk1e18;
    unsigned unk1e1c;
    unsigned unk1e20;
    unsigned unk1e24;
    unsigned unk1e28;
    unsigned unk1e2c;
    unsigned unk1e30;
    unsigned unk1e34;
    unsigned unk1e38;
    unsigned unk1e3c;
    unsigned unk1e40;
    unsigned unk1e44;
    unsigned unk1e48;
    unsigned unk1e4c;
    unsigned unk1e50;
    unsigned unk1e54;
    unsigned unk1e58;
    unsigned unk1e5c;
    unsigned unk1e60;
    unsigned unk1e64;
    unsigned unk1e68;
    unsigned unk1e6c;
    unsigned unk1e70;
    unsigned unk1e74;
    unsigned unk1e78;
    unsigned unk1e7c;
    unsigned unk1e80;
    unsigned unk1e84;
    unsigned unk1e88;
    unsigned unk1e8c;
    unsigned unk1e90;
    unsigned unk1e94;
    unsigned unk1e98;
    unsigned unk1e9c;
    unsigned unk1ea0;
    unsigned unk1ea4;
    unsigned unk1ea8;
    unsigned unk1eac;
    unsigned unk1eb0;
    unsigned unk1eb4;
    unsigned unk1eb8;
    unsigned unk1ebc;
    unsigned unk1ec0;
    unsigned unk1ec4;
    unsigned unk1ec8;
    unsigned unk1ecc;
    unsigned unk1ed0;
    unsigned unk1ed4;
    unsigned unk1ed8;
    unsigned unk1edc;
    unsigned unk1ee0;
    unsigned unk1ee4;
    unsigned unk1ee8;
    unsigned unk1eec;
    unsigned unk1ef0;
    unsigned unk1ef4;
    unsigned unk1ef8;
    unsigned unk1efc;
    unsigned unk1f00;
    unsigned unk1f04;
    unsigned unk1f08;
    unsigned unk1f0c;
    unsigned unk1f10;
    unsigned unk1f14;
    unsigned unk1f18;
    unsigned unk1f1c;
    unsigned unk1f20;
    unsigned unk1f24;
    unsigned unk1f28;
    unsigned unk1f2c;
    unsigned unk1f30;
    unsigned unk1f34;
    unsigned unk1f38;
    unsigned unk1f3c;
    unsigned unk1f40;
    unsigned unk1f44;
    unsigned unk1f48;
    unsigned unk1f4c;
    unsigned unk1f50;
    unsigned unk1f54;
    unsigned unk1f58;
    unsigned unk1f5c;
    unsigned unk1f60;
    unsigned unk1f64;
    unsigned unk1f68;
    unsigned unk1f6c;
    unsigned unk1f70;
    unsigned unk1f74;
    unsigned unk1f78;
    unsigned unk1f7c;
    unsigned unk1f80;
    unsigned unk1f84;
    unsigned unk1f88;
    unsigned unk1f8c;
    unsigned unk1f90;
    unsigned unk1f94;
    unsigned unk1f98;
    unsigned unk1f9c;
    unsigned unk1fa0;
    unsigned unk1fa4;
    unsigned unk1fa8;
    unsigned unk1fac;
    unsigned unk1fb0;
    unsigned unk1fb4;
    unsigned unk1fb8;
    unsigned unk1fbc;
    unsigned unk1fc0;
    unsigned unk1fc4;
    unsigned unk1fc8;
    unsigned unk1fcc;
    unsigned unk1fd0;
    unsigned unk1fd4;
    unsigned unk1fd8;
    unsigned unk1fdc;
    unsigned unk1fe0;
    unsigned unk1fe4;
    unsigned unk1fe8;
    unsigned unk1fec;
    unsigned unk1ff0;
    unsigned unk1ff4;
    unsigned unk1ff8;
    unsigned unk1ffc;
    unsigned unk2000;
    unsigned unk2004;
    unsigned unk2008;
    unsigned unk200c;
    unsigned unk2010;
    unsigned unk2014;
    unsigned unk2018;
    unsigned unk201c;
    unsigned unk2020;
    unsigned unk2024;
    unsigned unk2028;
    unsigned unk202c;
    unsigned unk2030;
    unsigned unk2034;
    unsigned unk2038;
    unsigned unk203c;
    unsigned unk2040;
    unsigned unk2044;
    unsigned unk2048;
    unsigned unk204c;
    unsigned unk2050;
    unsigned unk2054;
    unsigned unk2058;
    unsigned unk205c;
    unsigned unk2060;
    unsigned unk2064;
    unsigned unk2068;
    unsigned unk206c;
    unsigned unk2070;
    unsigned unk2074;
    unsigned unk2078;
    unsigned unk207c;
    unsigned unk2080;
    unsigned unk2084;
    unsigned unk2088;
    unsigned unk208c;
    unsigned unk2090;
    unsigned unk2094;
    unsigned unk2098;
    unsigned unk209c;
    RouteSearch();
    ~RouteSearch();
    bool SetupNavMeshSearch(RouteLock*, const RoutePoint&, void*, const RoutePoint&, void*, RouteInfos&, RoutePortals&,
                            int);
};
struct RouteSolution
{
    void FUN_006c90d0(const RouteInfo&);
    void CreateEntry(RouteInfo*, const RoutePoint&, RoutePortal*);
    void AddPathingItem(const RoutePoint&, RouteInfo*);
    void ConstructThing(RouteInfo*);
};
struct RouteBuilder
{
    RouteRequest* request;
    RouteSolution* solution;
    void* heap;
    bool BuildRoute(void*, void*);
};
// Runs a nav-mesh search between two points and builds the route solution from the resulting infos and portals.
// @fnv 0x006c94c0
bool RouteBuilder::BuildRoute(void* from, void* to)
{
    RouteSearch search7;
    RouteInfos infos(20, 0, heap);
    RoutePortals portals(20, 0, heap);
    RouteLock* actor_ = 0;
    if (!request->FUN_0073cb80())
        actor_ = request->GetActorLockData();
    int mode;
    if (request->GetIgnoreLocks_006a79a0())
        mode = 1;
    else
        mode = 0;
    bool result = search7.SetupNavMeshSearch(actor_, request->GetOffsetC().FUN_005c3420(), from,
                                             request->NiAVObject_GetRotate_006a9540().FUN_005c3420(), to, infos, portals, mode);
    if (infos.FUN_0044ddc0() <= 1)
    {
        if (0)
        {
        }
        solution->FUN_006c90d0(request->GetOffsetC());
        solution->FUN_006c90d0(request->NiAVObject_GetRotate_006a9540());
    }
    else
    {
        solution->FUN_006c90d0(request->GetOffsetC());
        if (portals.FUN_00877a30(0))
        {
            RoutePortal* portalRes = portals.FUN_00877a30(0);
            RoutePoint exit = portalRes->TESObjectREFR_GetLinkedDoorTeleportPosition();
            solution->CreateEntry(infos.FUN_00877a30(0), exit, portalRes);
            RoutePoint entry = portalRes->FUN_00568e50()->FUN_00717e50();
            solution->AddPathingItem(entry, infos.FUN_00877a30(1));
        }
        for (unsigned i2 = 1; i2 < infos.FUN_0044ddc0() - 1; ++i2)
        {
            if (portals.FUN_00877a30(i2))
            {
                RoutePortal* portalRes = portals.FUN_00877a30(i2);
                if (portalRes)
                {
                    RoutePoint exit = portalRes->TESObjectREFR_GetLinkedDoorTeleportPosition();
                    solution->CreateEntry(infos.FUN_00877a30(i2), exit, portalRes);
                    RoutePoint entry = portalRes->FUN_00568e50()->FUN_00717e50();
                    solution->AddPathingItem(entry, infos.FUN_00877a30(i2 + 1));
                }
            }
            else
                solution->ConstructThing(infos.FUN_00877a30(i2));
        }
        solution->FUN_006c90d0(request->NiAVObject_GetRotate_006a9540());
    }
    return result;
}

namespace fnv_006cd8a0 {
struct PosX
{
    float x, y, z;
};
struct NodeX
{
    void* pkNode;
    unsigned short usIdx;
};
struct ListX
{
    unsigned FUN_0044ddc0();
    NodeX* GetIndexedValue_006b3160(unsigned i);
};
struct LocX
{
    PosX FUN_005c3420();
};
struct EdgeX
{
    int pad[8 / 4];
    EdgeX(void* p, unsigned short us);
};
struct ArrX
{
    int pad[0x14 / 4];
    ArrX(unsigned n, int a, int b);
    ~ArrX();
    void BSSimpleArray_NavMeshTriHandle_1024_Add(const EdgeX& r);
};
struct SearchA
{
    int pad[0x20f4 / 4];
    SearchA();
    ~SearchA();
    bool NavMeshPOVSearch_BuildPath(LocX* a, LocX* b, ArrX* c, void* d, int e);
};
struct SearchB
{
    int pad[0xb8 / 4];
    SearchB();
    ~SearchB();
    bool PathSmoother_SmoothPath(void* a, ListX* b, int c, PosX* d, PosX* e, int f, int g, int h);
};
struct SearchC
{
    int pad[0x2110 / 4];
    SearchC();
    ~SearchC();
    bool FUN_006ad770(void* a, ListX* b, int c, PosX* d, PosX* e, int f, int g, void* h);
};
struct BoolSet
{
    bool* FUN_00408d60();
};
extern BoolSet DAT_011d7444, DAT_011d7434;

struct PathX
{
    PathingRequest* m0;
    int m4;
    int m8;
    char padc[8];
    char m14[4];
    bool PathBuilder_RunPathSmoother(LocX* pkStart, LocX* pkEnd, int iC, ListX* pkList, int iE);
};
// Selects among three search calls using global booleans and, in one branch, a float threshold; passes endpoints and a node list.
// @fnv 0x006cd8a0
// src: COMMUNITY 0x006cd8a0
bool PathX::PathBuilder_RunPathSmoother(LocX* pkStart, LocX* pkEnd, int iC, ListX* pkList, int iE)
{
    if (*DAT_011d7444.FUN_00408d60() && m0->GetFloatAtOffset68() > 150.0)
    {
        ArrX kArr_ilg(pkList->FUN_0044ddc0(), 0, m8);
        for (unsigned i = 0; i < pkList->FUN_0044ddc0(); i++)
        {
            kArr_ilg.BSSimpleArray_NavMeshTriHandle_1024_Add(EdgeX(pkList->GetIndexedValue_006b3160(i)->pkNode, pkList->GetIndexedValue_006b3160(i)->usIdx));
        }
        SearchA kSearchA_xmkn;
        return kSearchA_xmkn.NavMeshPOVSearch_BuildPath(pkStart, pkEnd, &kArr_ilg, m0, m4);
    }
    else if (*DAT_011d7434.FUN_00408d60())
    {
        SearchB kSearchB;
        return kSearchB.PathSmoother_SmoothPath(m0, pkList, iE, &pkStart->FUN_005c3420(), &pkEnd->FUN_005c3420(), m4, iC, 1);
    }
    else
    {
        SearchC kSearchC;
        return kSearchC.FUN_006ad770(m0, pkList, iE, &pkStart->FUN_005c3420(), &pkEnd->FUN_005c3420(), m4, iC, m14);
    }
}
}  // namespace fnv_006cd8a0

namespace seg6b9 {
struct S6Point
{
    float x;
    float y;
    float z;
    S6Point();
    S6Point SubtractIntoVector(const S6Point& other) const;
    S6Point FUN_00439e90(const S6Point& other) const;
    float DotProduct(const S6Point& other) const;
};
S6Point FUN_004a3760(float scale, const S6Point& point);

// Returns the closest point on the segment from start to end to the given point, clamping the projection parameter to the [0,1] range.
// @fnv 0x006b9c20
S6Point GetClosestPointOnSegment(const S6Point& point, const S6Point& start, const S6Point& end)
{
    S6Point kDir7 = end.SubtractIntoVector(start);
    S6Point kRel = point.SubtractIntoVector(start);
    double dDot5 = kRel.DotProduct(kDir7);
    if (dDot5 <= 0.0)
    {
        return start;
    }
    double _dLenSq = kDir7.DotProduct(kDir7);
    if (_dLenSq <= dDot5)
    {
        return end;
    }
    double dT = dDot5 / _dLenSq;
    return start.FUN_00439e90(FUN_004a3760((float)dT, kDir7));
}
}

namespace fnv_006ca0e0 {

class NiPoint3Ext : public NiPoint3
{
  public:
    float FUN_004a7290() const;
};

class PathingRequestExt : public PathingRequest
{
  public:
    bool PathingRequest_GetInitialPathHeading();
    float GetFloatAtOffset68();
    float GetField90Float();
    bool TESCombatStyle_GetPowerAttackF();
    float BGSProjectile_GetMuzzleFlashDuration();
};

class PathNodeExt
{
  public:
    PathingLocation& FUN_00717e50();
    void FORenderedMenu_SetScreenLightColor(NiColor*);
};

// Retained for reset (0x006c93a0) and current-node access (0x009611e0), absent from the shared header.
class PathingSolutionExt : public PathingSolution
{
  public:
    void PathingSolution_ClearCurrentDetailedPath();
    int NiAVObject_GetParent();
};

void __cdecl Pathing_ComputeInitialTangentForActor(NiColor*, float, PathingLocation&, PathingLocation&, float);
void __cdecl Pathing_ComputeFinalTangentForActor(NiColor*, float, PathingLocation&, float);

class PathBuilder_Child : public PathBuilder
{
  public:
    bool FindPathSegmentEnd(unsigned int, unsigned int&, unsigned int&);
    bool FUN_006ca850(Actor*);
    bool PathBuilder_BuildDetailedPath(Actor* a1, unsigned int a2);
};

// Calls FindPathSegmentEnd, stores its indices, invokes FUN_006ca850, and may update endpoint node colors when adjacent nodes are over 4096 units apart.
// @fnv 0x006ca0e0
// src: COMMUNITY 0x006ca0e0
bool PathBuilder_Child::PathBuilder_BuildDetailedPath(Actor* apActor, unsigned int aiSegmentIndex)
{
    ((PathingSolutionExt*)this->m_pOutputSolution)->PathingSolution_ClearCurrentDetailedPath();

    unsigned int iStart = 0xffffffff;
    {
        unsigned int iEnd = 0xffffffff;
        if (!this->FindPathSegmentEnd(aiSegmentIndex, iStart, iEnd))
        {
            return true;
        }

        this->m_pOutputSolution->unk18 = iStart;
        this->m_pOutputSolution->unk1c = iEnd;
    }
    {

        bool bResult = this->FUN_006ca850(apActor);
        if (!bResult && this->m_pOutputSolution->GetObjectFlags() == 0)
        {
            return false;
        }

        if (((PathingRequestExt*)this->pRequest)->PathingRequest_GetInitialPathHeading() &&
            ((PathingSolutionExt*)this->m_pOutputSolution)->NiAVObject_GetParent() == 0 &&
            this->m_pOutputSolution->GetObjectFlags() >= 2)
        {
            PathNodeExt* node0 = (PathNodeExt*)this->m_pOutputSolution->GetNode_006e7970(0);
            PathNodeExt* node1 = (PathNodeExt*)this->m_pOutputSolution->GetNode_006e7970(1);
            if (node0 && node1)
            {
                PathingLocation kStart(node0->FUN_00717e50());
                PathingLocation kNext(node1->FUN_00717e50());
                if (((NiPoint3Ext&)(kNext.FUN_005c3420() - kStart.FUN_005c3420())).FUN_004a7290() > 4096.0)
                {
                    // The callee fills this color; do not invoke the NiColor constructor.
                    float col[sizeof(NiColor) / sizeof(float)];
                    Pathing_ComputeInitialTangentForActor((NiColor*)col, ((PathingRequestExt*)this->pRequest)->GetField90Float(), kStart, kNext,
                                 ((PathingRequestExt*)this->pRequest)->GetFloatAtOffset68());
                    node0->FORenderedMenu_SetScreenLightColor((NiColor*)col);
                }
            }
        }

        if (bResult && ((PathingRequestExt*)this->pRequest)->TESCombatStyle_GetPowerAttackF() &&
            this->m_pOutputSolution->FUN_00441110() ==
                this->m_pOutputSolution->PathingSolution_GetVirtualNodeCount() - 1)
        {
            PathNodeExt* nodeLast =
                (PathNodeExt*)this->m_pOutputSolution
                    ->GetNode_006e7970(this->m_pOutputSolution->GetObjectFlags() - 1);
            PathNodeExt* nodePrev =
                (PathNodeExt*)this->m_pOutputSolution
                    ->GetNode_006e7970(this->m_pOutputSolution->GetObjectFlags() - 2);
            if (nodeLast && nodePrev)
            {
                PathingLocation locLast(nodeLast->FUN_00717e50());
                PathingLocation locPrev(nodePrev->FUN_00717e50());
                if (((NiPoint3Ext&)(locLast.FUN_005c3420() - locPrev.FUN_005c3420())).FUN_004a7290() > 4096.0)
                {
                    float kEndColor[sizeof(NiColor) / sizeof(float)];
                    {
                        PathingLocation kAdjustedLocation(nodeLast->FUN_00717e50());
                        Pathing_ComputeFinalTangentForActor((NiColor*)kEndColor, ((PathingRequestExt*)this->pRequest)->BGSProjectile_GetMuzzleFlashDuration(),
                                     kAdjustedLocation, ((PathingRequestExt*)this->pRequest)->GetFloatAtOffset68());
                        nodeLast->FORenderedMenu_SetScreenLightColor((NiColor*)kEndColor);
                    }
                }
            }
        }

        return bResult;
    }
}
}  // namespace fnv_006ca0e0

extern SettingT<GameSettingCollection> DAT_011cff94;
extern float DAT_0101e340;
// Constructor that zeroes four integer fields and initializes two float fields from DAT_011cff94 and DAT_0101e340.
// @fnv 0x006e61a0
PathingSearchRayCast::PathingSearchRayCast()
{
    // pt5C and pt68 are built by the out-of-line NiPoint3 constructor before this body.
    unk7C = 0;
    unk84 = 0;
    unk80 = 0;
    unk88 = 0;
    f8C = *DAT_011cff94.Setting_Float_00403e20();
    f90 = DAT_0101e340;
}
