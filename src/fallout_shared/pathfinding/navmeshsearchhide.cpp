
// src/fallout_shared/pathfinding/navmeshsearchhide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchhide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NiPoint3.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshTriangle.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingAvoidNodeArray.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESObjectDOOR.h"
#include "../../../include/NavMeshSearch.h"
#include "../../../include/NavMeshSearchHide.h"

void* _Deallocate(void*);

// Calls FUN_006a9d60, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x006a9d30
void* NavMeshSearchHide::DestroyIfFlagged(unsigned int flags)
{
    FUN_006a9d60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl FUN_005330e0(float* pfValue, float fMin, float fScaledValue);

struct A9F60Entry
{
    int unk00;
    float m_fScore;
    NavMesh* m_pMesh;
    unsigned short m_usNode;
    unsigned short unk0E;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

// @fnv 0x006a9f60
void NavMeshSearchHide::InitEntry(SearchNode* pkEntry, NavMesh* pkMesh, unsigned short usNode)
{
    reinterpret_cast<A9F60Entry*>(pkEntry)->m_pMesh = pkMesh;
    reinterpret_cast<A9F60Entry*>(pkEntry)->m_usNode = usNode;
    NiPoint3 kPos4 = pkMesh->FUN_00558220(usNode);
    reinterpret_cast<A9F60Entry*>(pkEntry)->m_fVectorY = kPos4.x;
    reinterpret_cast<A9F60Entry*>(pkEntry)->m_fVectorZ = kPos4.y;
    reinterpret_cast<A9F60Entry*>(pkEntry)->m_fScalarPart = kPos4.z;
    NiPoint3 kDiff = kPos4 - m_kStartPoint;
    float fScore6 = m_fFirstLightParameter - kDiff.Length();
    FUN_005330e0(&fScore6, 0.0f, m_fFirstLightParameter);
    reinterpret_cast<A9F60Entry*>(pkEntry)->m_fScore = fScore6;
}

struct NavMeshTriRef
{
    NavMesh* m_pMesh;
    unsigned short m_usTri;
    NiPoint3 FUN_006a6eb0();
};

struct NavSearchNodeInfo
{
    float m_fCost;
    int unk04;
    NavMeshTriRef m_kRef;
    int FUN_0045cd60();
};

struct NavSearchNode
{
    char pad00[0x1c];
    NavMesh* m_pMesh;
    unsigned short m_usTri;
    int m_iSide;
};

struct NavSearchNodeList
{
    void FUN_007cb2e0(NavSearchNode** ppNode);
};

struct FloatSetting
{
    float* FUN_00403e20();
};
extern FloatSetting g_setting_011d6ef0;

extern "C" TESForm* __cdecl FUN_004839c0(unsigned int auiFormId);

struct DoorCheck
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DoorCheck(TESForm* pkForm);
    ~DoorCheck();
    bool FUN_00502450(void* pkSource, TESForm* pkForm, bool* pbResult);
};

float __cdecl FUN_00404010(float fA, float fB);

// @fnv 0x006aa000
bool NavMeshSearchHide::ExpandNeighbors(NavSearchNodeInfo* pkInfo, NavSearchNodeList* pkList)
{
    NiPoint3 kPosX = pkInfo->FUN_0045cd60() ? pkInfo->m_kRef.FUN_006a6eb0() : reinterpret_cast<PathingRequest*>(m_pActor)->GetOffsetC().FUN_005c3420();
    for (int i9 = 0; i9 < 3; i9++)
    {
        NavMesh* pMesh5;
        unsigned short usTriZ;
        int iUnkZ;
        if (pkInfo->m_kRef.m_pMesh->FindAdjacentEdge(pkInfo->m_kRef.m_usTri, i9, &pMesh5, &usTriZ, &iUnkZ))
        {
            int* pEdgeWork = reinterpret_cast<int*>(pkInfo->m_kRef.m_pMesh->FUN_0068f230(pkInfo->m_kRef.m_usTri, i9));
            if (pEdgeWork && *pEdgeWork == 1)
                continue;
            float fMultY = 1.0f;
            if (pMesh5->FUN_005582f0(usTriZ)->FUN_00691140(0x1000))
            {
                if (reinterpret_cast<PathingRequest*>(m_pActor)->FUN_0073cb80())
                    continue;
                else
                {
                    unsigned int uiFormIDOut = *pMesh5->FUN_00699af0(usTriZ);
                    TESForm* pForm2 = FUN_004839c0(uiFormIDOut);
                    if (pForm2)
                    {
                        DoorCheck kCheck_2(pForm2);
                        void* pSource_2 = reinterpret_cast<PathingRequest*>(unk2058)->FUN_006c9900();
                        bool bResultZ;
                        if (!kCheck_2.FUN_00502450(pSource_2, pForm2, &bResultZ))
                            continue;
                        if (static_cast<TESObjectDOOR*>(static_cast<TESObjectREFR*>(pForm2)->GetObjectReference())->IsTeleportDoor())
                            fMultY = 100.0f;
                    }
                }
            }
            if (reinterpret_cast<PathingRequest*>(m_pActor)->GetFloatAtOffset68() > *g_setting_011d6ef0.FUN_00403e20() &&
                pMesh5->FUN_005582f0(usTriZ)->FUN_00691140(0x10))
                continue;
            NiPoint3 kCenterTmp = pMesh5->FUN_00558220(usTriZ);
            NiPoint3 kDeltaW = kCenterTmp.FUN_00439ef0(kPosX);
            float fCost_ = kDeltaW.FUN_00589850() * fMultY + pkInfo->m_fCost;
            float fExtraZ = 0.0f;
            if (reinterpret_cast<const PathingRequest*>(m_pActor)->GetString())
                fExtraZ = reinterpret_cast<const PathingRequest*>(m_pActor)->GetString()->GetAvoidanceAtPoint(kCenterTmp);
            float fDist6 = kCenterTmp.FUN_00439ef0(m_kTargetPos).FUN_00589850();
            float fNearOut = 1.0f - fDist6 / 512.0;
            fExtraZ += FUN_00404010(fNearOut, 0.0f);
            NiPoint3 kToTargetWork = m_kTargetPos.FUN_00439ef0(kPosX);
            float fDot_2 = kToTargetWork.DotProduct(kDeltaW);
            float fLenA_2 = kToTargetWork.FUN_00457990();
            float fLenBY = kDeltaW.FUN_00457990();
            if (fLenA_2 == 0.0 || fLenBY == 0.0)
                fDot_2 = 0.0f;
            else
                fDot_2 = fDot_2 / (fLenA_2 * fLenBY);
            fExtraZ += FUN_00404010(fDot_2, 0.0f);
            fCost_ = (1.0f + fExtraZ) * fCost_;
            NavSearchNode* pNode;
            switch (FUN_006a7e00(FUN_006a94f0(reinterpret_cast<NavMeshStandIn*>(pMesh5), usTriZ, fCost_, &pNode)))
            {
            case 0:
                InitEntry(reinterpret_cast<SearchNode*>(pNode), pMesh5, usTriZ);
            case 1:
                pNode->m_pMesh = pkInfo->m_kRef.m_pMesh;
                pNode->m_usTri = pkInfo->m_kRef.m_usTri;
                pNode->m_iSide = i9;
                pkList->FUN_007cb2e0(&pNode);
                break;
            }
        }
    }
    return true;
}

// PathingRequestHide accessors missing from its shared header: 0x00984230 returns this+0xB0; 0x00885BD0 reads +0xD8.
struct HideRequestTargetAccess
{
    PathingLocation* FUN_00984230();
    float FUN_00885bd0();
};

struct InfoF
{
    NavMesh* m_pMesh;
    unsigned short m_usTri;
    unsigned short unk06;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;

    NiPoint3* FUN_006a6eb0(NiPoint3* pOut);
};

struct ParamX
{
    bool FUN_0076b610();
};

extern NiPoint3 DAT_011f426c;

// @fnv 0x006a9d80
int NavMeshSearchHide::SetupActorTarget(ActorX* pkActor, TriRef20* pkInfo, ParamX* pkObj, int iArg)
{
    unk2058 = reinterpret_cast<int>(pkActor);
    m_pActor = pkActor;
    m_kInfo = *pkInfo;

    NiPoint3 kActorPos5 = reinterpret_cast<PathingRequest*>(pkActor)->GetOffsetC().FUN_005c3420();
    m_kStartPoint = DAT_011f426c;
    m_fFirstLightParameter = 0.0f;
    if (reinterpret_cast<const PathingRequest*>(m_pActor)->GetString())
    {
        m_fFirstLightParameter = reinterpret_cast<const PathingRequest*>(m_pActor)->GetString()->GetAvoidCost(kActorPos5, m_kStartPoint);
    }

    InfoF kInfo3;
    kInfo3.m_pMesh = reinterpret_cast<NavMesh*>(pkInfo->m_pMesh);
    kInfo3.m_usTri = pkInfo->m_usTri;
    NiPoint3 kTmp_2 = kInfo3.m_pMesh->FUN_00558220(kInfo3.m_usTri);
    kInfo3.m_fVectorY = kTmp_2.x;
    kInfo3.m_fVectorZ = kTmp_2.y;
    kInfo3.m_fScalarPart = kTmp_2.z;

    // This output buffer is populated by FUN_006a6eb0 without default construction.
    float kTriPt2[3];
    NiPoint3 kDiff = kInfo3.FUN_006a6eb0(reinterpret_cast<NiPoint3*>(kTriPt2))->FUN_00439ef0(m_kStartPoint);
    float fVal6 = m_fFirstLightParameter - kDiff.FUN_00457990();
    FUN_005330e0(&fVal6, 0.0f, m_fFirstLightParameter);

    FUN_006a7c90(FUN_006a94f0(reinterpret_cast<MeshX*>(kInfo3.m_pMesh), kInfo3.m_usTri), &kInfo3, fVal6);

    m_kTargetPos = reinterpret_cast<HideRequestTargetAccess*>(m_pActor)->FUN_00984230()->FUN_005c3420();

    FUN_006a7d60(pkObj, iArg, 1);
    return !pkObj->FUN_0076b610();
}

extern const double DAT_01012060;

bool __cdecl FUN_006b9790(const NiPoint3& kA, const NiPoint3& kB, const NiPoint3& kC, const NiPoint3& kPoint,
                          NiPoint3* pkOut);

struct NavInfo6aa4
{
    bool HasFlags();
    void GetTripleShorts(unsigned short* pusA, unsigned short* pusB, unsigned short* pusC);
    unsigned short FUN_00698030(unsigned short usSide);
};

struct NavList6aa4
{
    NavMesh* m_pkMesh;
    NavInfo6aa4* FUN_006a78d0();
};

struct NavData6aa4
{
    float m_fCost;
    int unk04;
    NavMeshTriRef m_kRef;
    NavList6aa4* FUN_00413f40();
};

// @fnv 0x006aa470
bool NavMeshSearchHide::FUN_006aa470(NavData6aa4* pkData)
{
    NavList6aa4* pkList = pkData->FUN_00413f40();
    NavInfo6aa4* pkInfo7 = pkList->FUN_006a78d0();
    if (!pkInfo7->HasFlags())
        return false;

    NiPoint3 kPos = pkData->m_kRef.FUN_006a6eb0();
    float aFLength = m_kTargetPos.FUN_00439ef0(kPos).FUN_00589850();
    if (aFLength < reinterpret_cast<HideRequestTargetAccess*>(m_pkActor)->FUN_00885bd0())
        return false;

    NavMesh* pkMesh6 = pkList->m_pkMesh;
    unsigned short usA5, usB, usC;
    pkInfo7->GetTripleShorts(&usA5, &usB, &usC);
    // FUN_006815c0 initializes this point storage.
    float kOut3[3];
    reinterpret_cast<NiPoint3*>(kOut3)->FUN_006815c0();
    bool bFound8 = false;
    FUN_006b9790(pkMesh6->FUN_0068f0a0(usA5), pkMesh6->FUN_0068f0a0(usB), pkMesh6->FUN_0068f0a0(usC), m_kTargetPos,
                 reinterpret_cast<NiPoint3*>(kOut3));
    if (kOut3[0] < DAT_01012060 && pkInfo7->FUN_00698030(1) > 0)
        bFound8 = true;
    else if (kOut3[2] < DAT_01012060 && pkInfo7->FUN_00698030(0) > 0)
        bFound8 = true;
    if (!bFound8)
        return false;

    float fDist_2 = 0.0f;
    if (reinterpret_cast<const PathingRequest*>(m_pkActor)->GetString())
        fDist_2 = reinterpret_cast<const PathingRequest*>(m_pkActor)->GetString()->GetAvoidanceAtPoint(kPos);
    return fDist_2 <= DAT_01012060;
}

extern int DAT_0106b7dc;

// @fnv 0x006a9d60
void NavMeshSearchHide::FUN_006a9d60()
{
    *reinterpret_cast<void**>(this) = &DAT_0106b7dc;
    NavMeshSearch::FUN_006a6b00();
}
