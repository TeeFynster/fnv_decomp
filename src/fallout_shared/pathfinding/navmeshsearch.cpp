#include "../../../include/NavMeshTriangle.h"
#include "../../../include/NavMeshInfo.h"
#include "../../../include/BSSimpleArray.h"
// fallout_shared/pathfinding/navmeshsearch.cpp: NavMeshSearch, NavMeshSearchEdges (25 functions)

#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshTriangleEdgeReference.h"
#include "../../../include/NavMeshTriangleReference.h"
#include "../../../include/AStarSearch.h"
#include "../../../include/NavMeshStaticAvoidNode.h"
#include "../../../include/NavMeshClosedDoorInfo.h"

class NavMeshSearchNode;
class NavMeshSearchLink;

#include "../../../include/NavMeshSearch.h"
#include "../../../include/SETTING_VALUE.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/DoorAccessData.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESObjectDOOR.h"
#include "../../../include/PathingAvoidNodeArray.h"

class NavMeshInfo;
class NavMeshStaticAvoidNode;


class EdgeExtraInfo
{
  public:
    int type;
};
class NavMeshEdgeExtra
{
  public:
    unsigned int unknown;
    NavMeshInfo* info;
};
template <class N, class L> class AStarNode
{
  public:
    unsigned int key;
    float cost;
    N Node;
    L Link;
    N& GetNode() const;
    void FUN_004f5d90(float);
    float GetCost() const;
};
class AStarMapNav
{
  public:
    char storage[0x1fe0];
    void AStarMap_AStarNode_NavMeshSearchNode_NavMeshSearchLink_Clear();
};
class AStarQueueNav
{
  public:
    char storage[0x54];
    void AStarQueue_NavMeshSearchNode_NavMeshSearchLink_Clear();
};


extern SettingT_GameSettingCollection_ DAT_011d6ef0;
extern float DAT_0119cdf8;
namespace std {
float abs(float);
}
float GetDirectionAngle(const NiPoint3&);
void WrapValueToRange(float&, float, float);
void BSClamp_float(float&, float, float);
bool Actor_AreReferencedValuesEqual(NavMeshInfo*&, NavMeshInfo*&);

// Clears the node and link arrays, sets up start and goal points, runs the search, and optionally collects meshes from the solution.
// @fnv 0x006a6b70
bool NavMeshSearch::ComputePath(const PathingRequest* request, const NavMeshTriangleReference& start,
                                const NavMeshTriangleReference& goal, BSSimpleArray<NavMeshTriangleReference>* nodes,
                                BSSimpleArray<NavMeshTriangleEdgeReference>* links,
                                BSSimpleArray<NavMeshInfo*>* solution)
{
    m_pPathingRequest = request;
    nodes->Clear(false);
    links->Clear(false);
    ClearSearch();
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_pLocationNavMesh = start.m_pLocationNavMesh;
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_usTriangleIdentifier = start.m_usTriangleIdentifier;
    NiPoint3 center =
        (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_pLocationNavMesh->GetNavMeshData((*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_usTriangleIdentifier);
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_fCenterX = center.x;
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_fCenterY = center.y;
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_fCenterZ = center.z;
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_pLocationNavMesh = goal.m_pLocationNavMesh;
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_usTriangleIdentifier = goal.m_usTriangleIdentifier;
    center = (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_pLocationNavMesh->GetNavMeshData((*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_usTriangleIdentifier);
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_fCenterX = center.x;
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_fCenterY = center.y;
    (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_fCenterZ = center.z;
    AStarSearch_NavMeshSearchNode_NavMeshSearchLink_SetMaxFitness(((*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).FastNavMeshTriLocation_GetLocation() - (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).FastNavMeshTriLocation_GetLocation()).FUN_00457990() * 2.0f);
    FindOrCreateSearchNode(
        GetKeyForNode_006a94f0((*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_pLocationNavMesh, (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).m_usTriangleIdentifier),
        (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)), ((*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).FastNavMeshTriLocation_GetLocation() - (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).FastNavMeshTriLocation_GetLocation()).FUN_00457990());
    m_pNavMeshInfos = solution;
    if (m_pNavMeshInfos)
    {
        BSSimpleArray<NavMeshPtr> meshes(m_pNavMeshInfos->GetSize());
        for (unsigned int i = 0; i < m_pNavMeshInfos->GetSize(); i++)
        {
            NavMeshPtr mesh;
            if (m_pNavMeshInfos->GetAt((int)i)->ResolveNavMesh(mesh))
                meshes[i] = mesh;
        }
    }
    if (!Search(nodes, links, true))
        return false;
    return true;
}

// @fnv 0x006a79c0
bool NavMeshSearch::HasReachedGoal(const SearchNode* node)
{
    if (m_pPathingRequest && m_pPathingRequest->GetFloatAtOffset68() > 100.0)
    {
        NiPoint3 kDelta = (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).FastNavMeshTriLocation_GetLocation() - node->GetNode().FastNavMeshTriLocation_GetLocation();
        float fDistanceSquared = kDelta.GetSquaredXYLength();
        float fHeightSquared = kDelta.z * kDelta.z;
        if (m_pPathingRequest->FUN_009b0bd0() * 0.25 * m_pPathingRequest->FUN_009b0bd0() > fDistanceSquared &&
            fHeightSquared < fDistanceSquared)
            return true;
    }
    return node->GetNode().m_pLocationNavMesh == (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_pLocationNavMesh &&
           node->GetNode().m_usTriangleIdentifier == (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).m_usTriangleIdentifier;
}

// @fnv 0x006a6ef0
void NavMeshSearch::SetSearchNodeTriangle(SearchNode* node, NavMesh* mesh, unsigned short triangle)
{
    NavMeshTriangleReference& data = node->GetNode();
    data.m_pLocationNavMesh = mesh;
    data.m_usTriangleIdentifier = triangle;
    NiPoint3 center = mesh->GetNavMeshData(triangle);
    data.m_fCenterX = center.x;
    data.m_fCenterY = center.y;
    data.m_fCenterZ = center.z;
    float distance = (data.FastNavMeshTriLocation_GetLocation() - (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).FastNavMeshTriLocation_GetLocation()).FUN_00457990();
    node->FUN_004f5d90(distance * double(0.01f));
}

// Calls FUN_00996800 and FUN_006a84e0, then zeroes three members.
// @fnv 0x006a7c40
void NavMeshSearch::ClearSearch()
{
    (*reinterpret_cast<AStarMapNav*>(&unk014)).AStarMap_AStarNode_NavMeshSearchNode_NavMeshSearchLink_Clear();
    (*reinterpret_cast<AStarQueueNav*>(&unk1ff4)).AStarQueue_NavMeshSearchNode_NavMeshSearchLink_Clear();
    m_pFirstNode = 0;
    m_pCurrentNode = 0;
    m_pLastCreatedNode = 0;
}

// @fnv 0x006a7940
// src: COMMUNITY 0x006a7940
bool PathingRequest::GetCanSwim() const
{
    return bCanSwim;
}

// @fnv 0x006a7980
// src: COMMUNITY 0x006a7980
bool PathingRequest::GetTryToUseCurvedPath() const
{
    return m_bCanUseDoors;
}

// @fnv 0x006a79a0
// src: XBOX_PDB 0x006a79a0
bool PathingRequest::GetIgnoreLocks_006a79a0() const
{
    return bIgnoreLocks;
}

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool BSSimpleArray_NiAVObject_1024_GetAt(unsigned int f);
};
// @fnv 0x006a7ad0
// src: XBOX_PDB 0x006a7ad0
bool S3e60::BSSimpleArray_NiAVObject_1024_GetAt(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}

namespace fnv_006a7af0 {
struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool BSSimpleArray_NiPoint3_1024_GetAt(unsigned int f);
};
// @fnv 0x006a7af0
// src: XBOX_PDB 0x006a7af0
bool S3e60::BSSimpleArray_NiPoint3_1024_GetAt(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}
}  // namespace fnv_006a7af0

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

struct FUN_006a7bc0_Class
{
    virtual ~FUN_006a7bc0_Class();
    FUN_00982610_Type m_sub0;
    Date m_date1;
    char m_auiShapeKeys[0x1ff4 - 0x14 - sizeof(Date)];
    Date m_date2;
};

// Destructor for FUN_006a7bc0_Class; the body is empty, so member destructors run implicitly.
// @fnv 0x006a7bc0
FUN_006a7bc0_Class::~FUN_006a7bc0_Class()
{}

struct PNode;
struct HX
{
    bool AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(PNode*, BSSimpleArray<NavMeshTriangleReference, 1024>*, BSSimpleArray<EdgeExtraInfo, 1024>*);
};
struct H1
{
    void AllocateStorage_006a8750(unsigned int, int);
};
struct H2
{
    void UpdateState_006a8890(int, int);
};
struct H3
{
    NavMeshTriangleEdgeReference* Object_GetIndexedValue_006a1440(unsigned short);
};
struct H4
{
    NavMeshTriangleReference* GetIndexedValue_006b3160(unsigned int);
};
struct PNode
{
    char pad[8];
    NavMeshTriangleReference f;
    NavMeshTriangleEdgeReference e;
    PNode* next;
};
// @fnv 0x006a8290
// src: XBOX_PDB 0x006a8290
bool HX::AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(PNode* apFinalNode, BSSimpleArray<NavMeshTriangleReference, 1024>* arr,
                      BSSimpleArray<EdgeExtraInfo, 1024>* arrEdges)
{
    PNode* pNode;
    int iElementIndex;
    int icount;
    if (!apFinalNode)
        return false;
    icount = 0;
    pNode = apFinalNode;
    while (pNode)
    {
        icount = icount + 1;
        pNode = pNode->next;
    }
    ((H1*)arr)->AllocateStorage_006a8750(icount, 1);
    ((H2*)arrEdges)->UpdateState_006a8890(icount - 1, 1);
    pNode = apFinalNode;
    iElementIndex = icount - 1;
    while (pNode)
    {
        *((H4*)arr)->GetIndexedValue_006b3160(iElementIndex) = pNode->f;
        if (iElementIndex > 0)
            *((H3*)arrEdges)->Object_GetIndexedValue_006a1440(iElementIndex - 1) = pNode->e;
        pNode = pNode->next;
        iElementIndex = iElementIndex - 1;
    }
    return true;
}

void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x006a84e0
// src: XBOX_PDB 0x006a84e0
void __fastcall AStarQueue_NavMeshSearchNode_NavMeshSearchLink_Clear(char* this_ptr)
{
    memset(this_ptr + 4, 0, 0x50);
}

unsigned int __fastcall _ref_0084e3a0(NavMesh*);

// @fnv 0x006a94f0
// src: XBOX_PDB 0x006a94f0
unsigned int NavMeshSearch::GetKeyForNode_006a94f0(NavMesh* apNavMesh, unsigned short aiTri)
{
    return ((_ref_0084e3a0(apNavMesh) & 0xFFFF) << 16) | aiTri;
}


// Copies the triangle center into the returned point.
// @fnv 0x006a6eb0
// src: COMMUNITY 0x006a6eb0
NiPoint3 NavMeshTriangleReference::FastNavMeshTriLocation_GetLocation() const
{
    return NiPoint3(m_fCenterX, m_fCenterY, m_fCenterZ);
}

// The shared header does not yet declare the default initializer at 0x00501cd0.
void __fastcall InitializeDoorAccessData(DoorAccessData*);

// @fnv 0x006a6a40
NavMeshSearch::NavMeshSearch()
{
    InitializeDoorAccessData(reinterpret_cast<DoorAccessData*>(&unk208c));
    m_pPathingRequest = 0;
    m_pNavMeshTriangleEdges = 0;
    m_pNavMeshInfos = 0;
}

// @fnv 0x006a6b00
NavMeshSearch::~NavMeshSearch()
{
    reinterpret_cast<DoorAccessData*>(&unk208c)->DoorAccessData::~DoorAccessData();
}

class NavMeshInfo;
namespace fnv_006a7b10 {
struct FUN_006a8380
{
    FUN_006a8380();
    ~FUN_006a8380();
    char pad[0x10];
};
struct FUN_006b3de0
{
    FUN_006b3de0();
    ~FUN_006b3de0();
    char pad[0x1fe0];
};
template <class A, class B> struct AStarOpenList
{
    AStarOpenList();
    char pad[0x54];
};
namespace FUN_006a7b10 {
struct FUN_006a7bc0_Class
{
    virtual void Unused0();
    FUN_006a7bc0_Class();
    FUN_006a8380 m04;
    FUN_006b3de0 m14;
    AStarOpenList<const NavMeshInfo*, TESObjectREFR*> m1ff4;
    int m2048;
    int m204c;
    int m2050;
    bool m2054;
};
}

// Initializes the three integer fields at offsets 0x2048, 0x204c and 0x2050 to zero and the bool at 0x2054 to false.
// @fnv 0x006a7b10
FUN_006a7b10::FUN_006a7bc0_Class::FUN_006a7bc0_Class()
{
    m2048 = 0;
    m204c = 0;
    m2050 = 0;
    m2054 = false;
}
}  // namespace fnv_006a7b10

// @fnv 0x006a7960
bool PathingRequest::GetByteAtOffset9E() const
{
    return bCanFly;
}

struct FUN_00aa5410_Helper
{
    int InitWithAlignedSize(unsigned int);
    FUN_00aa5410_Helper* ProcessAndReturnValue_006a8380();
};

// @fnv 0x006a8380
// src: GUESS 0x006a8380 (confidence: low)
FUN_00aa5410_Helper* FUN_00aa5410_Helper::ProcessAndReturnValue_006a8380()
{
    InitWithAlignedSize(0x7800);
    return this;
}

struct FUN_006a8490_node
{
    char pad[0x2c];
    FUN_006a8490_node* pPrev;  // +0x2c
    FUN_006a8490_node* pNext;  // +0x30
};

struct FUN_006a8490_class
{
    void UnlinkNode(FUN_006a8490_node* pNode);
};

// Unlinks pNode from its doubly linked list by patching its neighbours' pointers, then clears pNode's own pPrev and pNext.
// @fnv 0x006a8490
void FUN_006a8490_class::UnlinkNode(FUN_006a8490_node* pNode)
{
    if (pNode->pPrev != 0)
    {
        *reinterpret_cast<FUN_006a8490_node**>(pNode->pPrev) = pNode->pNext;
    }
    if (pNode->pNext != 0)
    {
        pNode->pNext->pPrev = pNode->pPrev;
    }
    pNode->pPrev = 0;
    pNode->pNext = 0;
}

struct A83A0ScrapHeap;

void* operator new(unsigned int uiSize, A83A0ScrapHeap* pkHeap);

struct A83A0Node
{
    A83A0Node();

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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

struct A83A0ScrapHeap
{
    A83A0Node* CreateNode();
};

// Allocates an A83A0Node from this scrap heap and returns it.
// @fnv 0x006a83a0
A83A0Node* A83A0ScrapHeap::CreateNode()
{
    A83A0Node* pkNode = new (this) A83A0Node;
    return pkNode;
}

struct SortNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    SortNode** m_ppPrevious;
    SortNode* m_pNext;
    float GetKey();
};

class FUN_006a83f0_cls
{
  public:
    unsigned int m_uiItemCount;
    SortNode* m_buckets[1];
    unsigned int GetScaledValue(SortNode* node);
    void InsertSortedNode(SortNode* node);
};

// Computes a bucket index for node, walks the bucket's list while keys are smaller, then links node into the list at that position.
// @fnv 0x006a83f0
void FUN_006a83f0_cls::InsertSortedNode(SortNode* node)
{
    unsigned int idx = GetScaledValue(node);
    SortNode** pp = &m_buckets[idx];
    SortNode** slot = pp;
    while (*slot != 0 && (double)(*slot)->GetKey() < node->GetKey())
    {
        slot = &(*slot)->m_pNext;
    }
    if (*slot != 0)
    {
        (*slot)->m_ppPrevious = &node->m_pNext;
    }
    node->m_pNext = *slot;
    node->m_ppPrevious = slot;
    *slot = node;
}

extern double DAT_01012060, DAT_01016408, DAT_01011588, DAT_0101ff40;
extern float DAT_01016410, DAT_0101712c, DAT_0101e570, DAT_010231a0;
extern float DAT_0106b648, DAT_0102b3c8;

struct NavMeshSearchEdges : NavMeshSearch
{
    bool FindEdgeConnections(const SearchNode* current, BSSimpleArray<SearchNode*>* connections);
};

// @fnv 0x006a6fa0
bool NavMeshSearchEdges::FindEdgeConnections(const SearchNode* current, BSSimpleArray<SearchNode*>* connections)
{
    const NavMeshTriangleReference& currentNode = current->GetNode();
    for (int edgeIndex = 0; edgeIndex < 3; ++edgeIndex)
    {
        NavMesh* neighborMesh;
        unsigned short neighborTriangle;
        int outEdge;
        {
            NavMeshTriangle* triangle;
            NavMeshInfo* info;
            if (m_pNavMeshInfos != 0)
            {
                triangle = currentNode.m_pLocationNavMesh->FUN_005582f0(currentNode.m_usTriangleIdentifier);
                if (triangle->IsEdgeFlagSet(edgeIndex))
                {
                    info = currentNode.m_pLocationNavMesh->GetEdge(triangle->GetEdgeExtraInfo_0068f2c0(edgeIndex))->info;
                    if (m_pNavMeshInfos->Find(info, 0, Actor_AreReferencedValuesEqual) == (unsigned int)-1)
                        continue;
                }
            }
            {
                EdgeExtraInfo* edgeInfoA;
                float usePenalty6;
                float stancePenalty4;
                bool nextCrouchX;
                bool currentCrouch3;
                float revisitPenalty4;
                float baseDistance7;
                SearchNode* resultNodeA;
                if (currentNode.m_pLocationNavMesh->FindAdjacentTriangle(currentNode.m_usTriangleIdentifier, edgeIndex,
                                                                         neighborMesh, neighborTriangle, outEdge))
                {
                    edgeInfoA =
                        currentNode.m_pLocationNavMesh->GetEdgeInfo(currentNode.m_usTriangleIdentifier, edgeIndex);
                    if (edgeInfoA != 0 && edgeInfoA->type == 1)
                        continue;
                    if (currentNode.m_pLocationNavMesh == neighborMesh &&
                        currentNode.m_usTriangleIdentifier == neighborTriangle)
                        continue;
                    if (m_pPathingRequest->FUN_006a78f0() > 0.0)
                    {
                        NiPoint3 centerA = neighborMesh->GetNavMeshData(neighborTriangle);
                        NiPoint3 toDestination = centerA - m_pPathingRequest->GetTargetPoint();
                        if (toDestination.FUN_004a7290() >
                            m_pPathingRequest->FUN_006a78f0() * m_pPathingRequest->FUN_006a78f0())
                            continue;
                    }
                    usePenalty6 = 1.0f;
                    if (neighborMesh->FUN_005582f0(neighborTriangle)->FUN_00691140(0x1000))
                    {
                        if (m_pPathingRequest->FUN_0073cb80())
                            continue;
                        else
                        {
                            bool canUnlock3;
                            const PathingActorData* lockData7;
                            unsigned int doorID = neighborMesh->GetClosedDoorInfo(neighborTriangle)->m_uiDoorFormID;
                            TESObjectREFR* doorRef = (TESObjectREFR*)TESForm::GetFormByID(doorID);
                            if (doorRef != 0)
                            {
                                if (!m_pPathingRequest->GetIgnoreLocks_006a79a0())
                                {
                                    if (doorRef->TESObjectREFR_GetInaccessible())
                                        continue;
                                    (*reinterpret_cast<DoorAccessData*>(&unk208c)).SetDoorReference(doorRef);
                                    lockData7 = m_pPathingRequest->GetActorLockData();
                                    if (!(*reinterpret_cast<DoorAccessData*>(&unk208c)).CanUnlockDoor(lockData7, doorRef, canUnlock3))
                                        continue;
                                }
                                if (((TESObjectDOOR*)doorRef->GetObjectReference())->IsTeleportDoor())
                                    usePenalty6 = DAT_01016410;
                            }
                        }
                    }
                    if (m_pPathingRequest->GetFloatAtOffset68() > DAT_011d6ef0.Float()->f &&
                        neighborMesh->FUN_005582f0(neighborTriangle)->FUN_00691140(0x10))
                        continue;
                    stancePenalty4 = 1.0f;
                    nextCrouchX = neighborMesh->FUN_005582f0(neighborTriangle)->NavMeshTriangle_IsWater();
                    currentCrouch3 = currentNode.NavMeshSearchNode_GetTriangle()->NavMeshTriangle_IsWater();
                    if (!m_pPathingRequest->GetCanSwim() && !m_pPathingRequest->GetByteAtOffset9E())
                    {
                        if (nextCrouchX)
                            continue;
                    }
                    else if (nextCrouchX != currentCrouch3)
                        stancePenalty4 = DAT_0101712c;
                    else if (nextCrouchX)
                        stancePenalty4 = DAT_0101e570;
                    revisitPenalty4 = 1.0f;
                    if (m_pNavMeshTriangleEdges != 0)
                    {
                        for (unsigned int i = 0; i < m_pNavMeshTriangleEdges->GetSize(); ++i)
                        {
                            if (m_pNavMeshTriangleEdges->GetAt((int)i).m_usTriangleIdentifier ==
                                    current->Node.m_usTriangleIdentifier &&
                                m_pNavMeshTriangleEdges->GetAt((int)i).m_pLocationNavMesh ==
                                    current->Node.m_pLocationNavMesh &&
                                m_pNavMeshTriangleEdges->GetAt((int)i).m_iEdgeIndex == edgeIndex)
                            {
                                revisitPenalty4 = DAT_01016410;
                                break;
                            }
                        }
                    }
                    {
                        NiPoint3 nextCenter = neighborMesh->GetNavMeshData(neighborTriangle);
                        NiPoint3 currentCenter5 = current->GetNode().FastNavMeshTriLocation_GetLocation();
                        baseDistance7 = (nextCenter - currentCenter5).NiPoint3_XYLength();
                        if (neighborMesh->FUN_005582f0(neighborTriangle)->HasFlag40())
                            baseDistance7 *= DAT_01016408;
                        if (m_pPathingRequest != 0 && m_pPathingRequest->GetString() != 0)
                        {
                            float avoidance = m_pPathingRequest->GetString()->GetAvoidanceAtPoint(nextCenter);
                            if (avoidance > 0.0)
                                baseDistance7 *= 1.0f + avoidance;
                        }
                        if (neighborMesh->FUN_005582f0(neighborTriangle)->FUN_00691140(0x80000000))
                        {
                            BSSimpleArray<NavMeshStaticAvoidNode*> staticAvoids;
                            if (neighborMesh->GetStaticAvoidNodesForTriangle(neighborTriangle, staticAvoids))
                            {
                                float staticPenalty = 0.0f;
                                for (unsigned int i = 0; i < staticAvoids.GetSize(); ++i)
                                    staticPenalty += staticAvoids.GetAt((int)i)->GetFloatAtOffset1C();
                                baseDistance7 *= staticPenalty;
                            }
                        }
                        NiPoint3 edgeStart, edgeEnd5;
                        neighborMesh->GetEdgeVertices_0068f0c0(neighborTriangle, outEdge, edgeStart, edgeEnd5);
                        float edgeLength = (edgeStart - edgeEnd5).NiPoint3_XYLength();
                        float maxEdgeLength6 = DAT_010231a0;
                        float narrowPenalty2 = 1.0f - edgeLength / maxEdgeLength6;
                        BSClamp_float(narrowPenalty2, 0.0f, 1.0f);
                        baseDistance7 *= narrowPenalty2 * DAT_01011588 + DAT_01011588;
                        baseDistance7 *= stancePenalty4;
                        baseDistance7 *= revisitPenalty4;
                        baseDistance7 *= usePenalty6;
                        if (m_pPathingRequest->GetTryToUseCurvedPath())
                        {
                            NiPoint3 goalVector = (*reinterpret_cast<NavMeshTriangleReference*>(&unk205c)).FastNavMeshTriLocation_GetLocation() - (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).FastNavMeshTriLocation_GetLocation();
                            NiPoint3 nodeVector = nextCenter - (*reinterpret_cast<NavMeshTriangleReference*>(&unk2070)).FastNavMeshTriLocation_GetLocation();
                            float goalDistance8 = GetDirectionAngle(goalVector);
                            float nodeDistance3 = GetDirectionAngle(nodeVector);
                            float difference7 = nodeDistance3 - goalDistance8;
                            WrapValueToRange(difference7, DAT_0106b648, DAT_0102b3c8);
                            difference7 = std::abs(difference7);
                            float goalLength7 = goalVector.FUN_00457990();
                            float adjustedTmp = (DAT_0101ff40 - difference7) * goalLength7 / DAT_0101ff40;
                            float nodeLength_ = nodeVector.FUN_00457990();
                            baseDistance7 *= std::abs(nodeLength_ - adjustedTmp) * DAT_0119cdf8;
                        }
                        baseDistance7 += current->GetCost();
                        switch (CreateOrUpdateNode(GetKeyForNode_006a94f0(neighborMesh, neighborTriangle), baseDistance7,
                                                   resultNodeA))
                        {
                        case 0:
                            SetSearchNodeTriangle(resultNodeA, neighborMesh, neighborTriangle);
                        case 1:
                            resultNodeA->Link.m_pLocationNavMesh = current->Node.m_pLocationNavMesh;
                            resultNodeA->Link.m_usTriangleIdentifier = current->Node.m_usTriangleIdentifier;
                            resultNodeA->Link.m_iEdgeIndex = edgeIndex;
                            connections->Add(resultNodeA);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }
    return true;
}

// @fnv 0x006a7910
// src: COMMUNITY 0x006a7910
NiPoint3 PathingRequest::GetTargetPoint() const
{
    return Center;
}





