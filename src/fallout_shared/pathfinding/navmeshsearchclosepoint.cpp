#include "../../../include/NavMeshSearchClosePoint.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingAvoidNodeArray.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshTriangle.h"
#include "../../../include/NavMeshSearch.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/SettingT_GameSettingCollection_.h"

// src/fallout_shared/pathfinding/navmeshsearchclosepoint.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchclosepoint.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


extern int DAT_0106b6fc;

struct FUN_006a8b40_shell : NavMeshSearch
{
    void DestroyFields_006a8b40();
};

// @fnv 0x006a8b40
// src: GUESS 0x006a8b40 (confidence: medium)
void FUN_006a8b40_shell::DestroyFields_006a8b40()
{
    reinterpret_cast<int**>(this)[0] = &DAT_0106b6fc;
    NavMeshSearch::~NavMeshSearch();
}

void __cdecl Deallocate(void*);

struct FUN_006a8b10_shell : FUN_006a8b40_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_006a8b40, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006a8b10
void* FUN_006a8b10_shell::DestroyIfFlagged(unsigned int flags)
{
    DestroyFields_006a8b40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// NavMeshAStarNode: unit-local stand-in for the A* search node (AStarNode<NavMeshSearchNode,NavMeshSearchLink>, 60 bytes; src: XBOX_PDB), not a NavMeshTriangleReference: 0x006a8d20 SetNodeFromTriangle writes cost at +4, mesh +8, triangle +0xc, centre +0x10
struct NavMeshAStarNode
{
    void* m_pLocationNavMesh;
    float m_fPathingCostCur;
    void* pMesh;
    unsigned short m_usTriangleIdentifier;
    float GetCenterX, m_fCenterY, m_fCenterZ;
};
void BSClamp_float(float& a, float b, float c);
// @fnv 0x006a8d20
void NavMeshSearchClosePoint::SetNodeFromTriangle(NavMeshTriangleReference* node, NavMesh* mesh,
                                                  unsigned short triangle)
{
    reinterpret_cast<NavMeshAStarNode*>(node)->pMesh = mesh;
    reinterpret_cast<NavMeshAStarNode*>(node)->m_usTriangleIdentifier = triangle;
    NiPoint3 center = mesh->GetNavMeshData(triangle);
    reinterpret_cast<NavMeshAStarNode*>(node)->GetCenterX = center.x;
    reinterpret_cast<NavMeshAStarNode*>(node)->m_fCenterY = center.y;
    reinterpret_cast<NavMeshAStarNode*>(node)->m_fCenterZ = center.z;
    NiPoint3 avoidVector = center - ((NiPoint3*)((char*)this + 0x208c))[0];
    float fcost = ((float*)((char*)this + 0x2098))[0] - static_cast<const NiPoint3&>(avoidVector).Length();
    BSClamp_float(fcost, 0.0f, ((float*)((char*)this + 0x2098))[0]);
    reinterpret_cast<NavMeshAStarNode*>(node)->m_fPathingCostCur = fcost;
}

extern NiPoint3 NiPoint3_ZERO;
struct NavMeshNodeInfo
{
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    struct { float x, y, z; } kPos;
    NiPoint3 GetPos();
};
float __cdecl RandomFloat(float, float);
void BSClamp_float(float& a, float b, float c);
// @fnv 0x006a8b60
bool NavMeshSearch::Search(PathingRequest* request, NavMeshNodeInfo* start, PathingSolution* sol, void* arg)
{
    (*reinterpret_cast<PathingRequest**>(&unk2058)) = request;
    (*reinterpret_cast<NavMeshNodeInfo*>(&unk205c)) = *start;
    (*reinterpret_cast<float*>(&unk2070)) = RandomFloat(request->GetMinRadius(), request->GetMaxRadius());
    NiPoint3 kStartPos = static_cast<const PathingLocation*>(request->GetStartLoc())->GetLocation();
    (*reinterpret_cast<NiPoint3*>(&unk208c)) = NiPoint3_ZERO;
    (*reinterpret_cast<float*>(&unk2098)) = 0.0f;
    if ((*reinterpret_cast<PathingRequest**>(&unk2058))->GetAvoidNodes())
    {
        (*reinterpret_cast<float*>(&unk2098)) = (*reinterpret_cast<PathingRequest**>(&unk2058))->GetAvoidNodes()->GetAvoidCost(kStartPos, (*reinterpret_cast<NiPoint3*>(&unk208c)));
    }
    NavMeshNodeInfo kNode7;
    kNode7.m_pLocationNavMesh = start->m_pLocationNavMesh;
    kNode7.m_usTriangleIdentifier = start->m_usTriangleIdentifier;
    NiPoint3 kCenter4 = kNode7.m_pLocationNavMesh->GetNavMeshData(kNode7.m_usTriangleIdentifier);
    kNode7.kPos.x = kCenter4.x;
    kNode7.kPos.y = kCenter4.y;
    kNode7.kPos.z = kCenter4.z;
    NiPoint3 kDiff3 = kNode7.GetPos() - (*reinterpret_cast<NiPoint3*>(&unk208c));
    float fCost9 = reinterpret_cast<float&>(unk2098) - static_cast<const NiPoint3&>(kDiff3).Length();
    BSClamp_float(fCost9, 0.0f, reinterpret_cast<float&>(unk2098));
    PushOpen(AddNode(kNode7.m_pLocationNavMesh, kNode7.m_usTriangleIdentifier, &kNode7, fCost9));
    Run(sol, arg, true);
    return !sol->IsEmpty();
}


struct GetCenterX_006a6eb0
{
    NiPoint3* FastNavMeshTriLocation_GetLocation(NiPoint3* apOut);
};

struct EdgeExtraInfo
{
    int iType;
};

struct NMForm;


struct NMNode
{
    int unk00;
    int unk04;
    NavMesh* pMesh;
    unsigned short m_usTriangleIdentifier;
};

struct NMSearchNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    NavMesh* pMesh;
    unsigned short m_usTriangleIdentifier;
    int m_iEdgeNumber;
};

struct NMNodeArray
{
    unsigned int Add(NMSearchNode*& arpNode);
};

struct NMSpace
{
    bool FUN_00518000();
};

struct NMForm
{
    NMSpace* BGSSaveFormBuffer_GetForm();
};


struct NMLock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NMLock(NMForm* apForm);
    ~NMLock();
    bool FUN_00502450(void* apActor, NMForm* apForm, bool* apLocked);
};

extern SettingT_GameSettingCollection_ DAT_011d6ef0;

unsigned int __cdecl DialogueRandom();
NMForm* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormID);

struct FUN_006a8dc0_shell
{
    virtual void v00();
    virtual bool AddAdjacentNodes(NMNode* apNode, NMNodeArray* apNodes);
    unsigned int GetKeyForNode_006a94f0(NavMesh* apMesh, unsigned short ausTriangle);
    int FUN_006a7e00(unsigned int auiID, float afCost, NMSearchNode** appNode);
    void SetNodeFromTriangle(NMSearchNode* apNode, NavMesh* apMesh, unsigned short ausTriangle);
};

// @fnv 0x006a8dc0
bool FUN_006a8dc0_shell::AddAdjacentNodes(NMNode* apNode, NMNodeArray* apNodes)
{
    struct { float x, y, z; } kTargetCenter;
    ((GetCenterX_006a6eb0*)&apNode->pMesh)->FastNavMeshTriLocation_GetLocation((NiPoint3*)&kTargetCenter);
    int iPick = DialogueRandom() % 6;
    int iBegin = iPick / 2;
    int iNext = (iPick & 1) + 1;
    int iCnt;
    int e;
    for (iCnt = 0, e = iBegin; iCnt < 3; iCnt++, e = (e + iNext) % 3)
    {
        NavMesh* pMesh;
        unsigned short m_usTriangleIdentifier;
        int iLink;
        if (apNode->pMesh->FindAdjacentEdge(apNode->m_usTriangleIdentifier, e, &pMesh, &m_usTriangleIdentifier, &iLink))
        {
            EdgeExtraInfo* pInfo = apNode->pMesh->GetEdgeExtraInfo(apNode->m_usTriangleIdentifier, e);
            if (pInfo && pInfo->iType == 1)
            {
                continue;
            }
            float fMult = 1.0f;
            if (pMesh->FUN_005582f0(m_usTriangleIdentifier)->FUN_00691140(0x1000))
            {
                if ((*(PathingRequest**)((char*)this + 0x2058))->FUN_0073cb80())
                {
                    continue;
                }
                else
                {
                    unsigned int auiFormId = *pMesh->FUN_00699af0(m_usTriangleIdentifier);
                    NMForm* pPathNodeDoor = TESForm_GetFormByNumericID(auiFormId);
                    if (pPathNodeDoor)
                    {
                        NMLock kLock(pPathNodeDoor);
                        void* actor = (*(PathingRequest**)((char*)this + 0x2058))->GetActorLockData();
                        bool locked;
                        if (!kLock.FUN_00502450(actor, pPathNodeDoor, &locked))
                        {
                            continue;
                        }
                        if (pPathNodeDoor->BGSSaveFormBuffer_GetForm()->FUN_00518000())
                        {
                            fMult = 100.0f;
                        }
                    }
                }
            }
            if ((*(PathingRequest**)((char*)this + 0x2058))->GetFloatAtOffset68() > DAT_011d6ef0.Float()->f &&
                pMesh->FUN_005582f0(m_usTriangleIdentifier)->FUN_00691140(0x10))
            {
                continue;
            }
            float m_fPathingCostCur = 0.0f;
            if (fMult != 1.0)
            {
                m_fPathingCostCur = fMult;
            }
            NMSearchNode* pNext;
            switch (FUN_006a7e00(GetKeyForNode_006a94f0(pMesh, m_usTriangleIdentifier), m_fPathingCostCur, &pNext))
            {
            case 0:
                SetNodeFromTriangle(pNext, pMesh, m_usTriangleIdentifier);
            case 1:
                pNext->pMesh = apNode->pMesh;
                pNext->m_usTriangleIdentifier = apNode->m_usTriangleIdentifier;
                pNext->m_iEdgeNumber = e;
                apNodes->Add(pNext);
                break;
            }
        }
    }
    return true;
}


struct PathingAvoidNodeArray_Sub : PathingAvoidNodeArray
{
    float SumNodeValues(const NiPoint3& pt);
};

bool __cdecl IsPathingLocationClear(PathingLocation* loc, float f);

extern double DAT_01012060;

struct NiPoint3_Sub : NiPoint3
{
    float GetLen() const;
};

struct FUN_006a90a0_Class : NavMeshSearch
{
    bool IsNodeWithinSearchCriteria(NavMeshAStarNode* apNode);
};

// Computes the node center's distance to the request start, checks it against a threshold, validates the location, and compares avoid-node cost to DAT_01012060.
// @fnv 0x006a90a0
bool FUN_006a90a0_Class::IsNodeWithinSearchCriteria(NavMeshAStarNode* apNode)
{
    struct { float x, y, z; } pt;
    ((GetCenterX_006a6eb0*)&apNode->pMesh)->FastNavMeshTriLocation_GetLocation((NiPoint3*)&pt);

    float fDist = ((NiPoint3_Sub*)&(static_cast<const PathingLocation*>((*reinterpret_cast<PathingRequest**>(&this->unk2058))->GetStartLoc())->GetLocation() - *reinterpret_cast<const NiPoint3*>(&pt)))->GetLen();
    if (fDist < reinterpret_cast<float&>(this->unk2070))
        return false;

    PathingLocation nodeLocation(*reinterpret_cast<const NiPoint3*>(&pt), ((NavMesh*)apNode->pMesh)->GetNavMeshInfo_0068efb0());
    if (!IsPathingLocationClear(&nodeLocation, (*reinterpret_cast<PathingRequest**>(&this->unk2058))->GetFloatAtOffset68()))
        return false;

    float fAvoidCost = 0.0f;
    if ((*reinterpret_cast<PathingRequest**>(&this->unk2058))->GetAvoidNodes())
    {
        fAvoidCost = ((PathingAvoidNodeArray_Sub*)(*reinterpret_cast<PathingRequest**>(&this->unk2058))->GetAvoidNodes())->SumNodeValues(*reinterpret_cast<const NiPoint3*>(&pt));
    }
    return fAvoidCost <= DAT_01012060;
}
