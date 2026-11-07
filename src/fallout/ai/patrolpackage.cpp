#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/BGSSaveLoadGame.h"
#include "../../../include/EscortActorPackageData.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PatrolActorPackageData.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESPackage.h"
// fallout/ai/patrolpackage.cpp: patrol package data (13 functions)

class LocationDescriptor
{
  public:
    void SetLocRef(TESObjectREFR*);
    TESObjectREFR* GetLocationReference();
};


class ArchiveManager
{
  public:
    void CopyArchiveName(char*, unsigned int);
};


struct PatrolPackage
{
    bool TESRegionData_GetOverride();
};

// @fnv 0x004f1540
// src: XBOX_PDB 0x004f1540
bool PatrolPackage::TESRegionData_GetOverride()
{
    return *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 4);
}

extern int DAT_010933c8;


// Calls FUN_0067d920, installs the vtable at DAT_010933c8, and zeroes fields at offsets 0x4 through 0x10 before returning thisPtr.
// @fnv 0x009f27a0
void* __fastcall InitEscortPackageData(void* thisPtr)
{
    reinterpret_cast<EscortActorPackageData*>(thisPtr)->FUN_0067d920();
    *reinterpret_cast<void**>(thisPtr) = &DAT_010933c8;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(thisPtr) + 0x8) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(thisPtr) + 0xc) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(thisPtr) + 0x10) = 0.0f;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(thisPtr) + 0x4) = 0;
    return thisPtr;
}


// @fnv 0x009f2a30
PTYPE PatrolActorPackageData::GetPackageType()
{
    return static_cast<PTYPE>(0xd);
}

// Stores the actor and package, resets counters, and if the package is valid and has patrol data, initializes the patrol from the actor's position.
// @fnv 0x009f2ba0
bool PatrolActorPackageData::Init(Actor* apActor, TESPackage* apPackage)
{
    pActor = apActor;
    pPackage = apPackage;
    m_pEscortPackageData = apPackage->GetPackagePatrolData();
    m_uiSecondValueAfterReferenceFlag = 0;
    m_bPatrolFlag = true;
    m_uiValueAfterReferenceFlag = 0;
    bool bvalid = (((ArchiveManager*)this)->*(bool(ArchiveManager::*)()) & ArchiveManager::CopyArchiveName)();
    if (bvalid)
    {
        if (((PatrolPackage*)m_pEscortPackageData)->TESRegionData_GetOverride())
        {
            SetPatrolPosition((*(const NiPoint3&(__thiscall**)(Actor*))(*(int*)apActor + 0x1f4))(apActor));
        }
    }
    return bvalid;
}

class BGSMessageInitAccess
{
  public:
    unsigned int GetIconFormID();
};

// Returns the reference from the pack's icon form if it resolves to one, otherwise falls back to the actor's linked reference.
// @fnv 0x009f2d40
TESObjectREFR* __cdecl PatrolActorPackageData::GetPatrolReference(Actor* apActor, TESPackage* apPack)
{
    LocationDescriptor* ploc;
    TESObjectREFR* pinitialReference = 0;

    ploc = reinterpret_cast<LocationDescriptor*>(((BGSMessageInitAccess*)apPack)->GetIconFormID());
    if (ploc)
    {
        TESObjectREFR* plocRef = ploc->GetLocationReference();
        if (plocRef)
        {
            pinitialReference = plocRef;
        }
    }

    if (!pinitialReference)
    {
        TESObjectREFR* plinkedRef = ((TESObjectREFR*)apActor)->GetLinkedRef();
        if (plinkedRef)
        {
            pinitialReference = plinkedRef;
        }
    }

    return pinitialReference;
}

namespace fnv_009f30d0 {
struct RefExtraHelper
{
    const ExtraDataList* GetExtra() const;
};
struct ExtraHelper
{
    bool ExtraDataList_GetPatrolRefCanBeUsedBy(void*);
    void ExtraDataList_SetPatrolRefInUse(void*);
};
struct PatrolHelper
{
    void PatrolActorPackageData_ClearReservedPatrolRef();
};
void __cdecl ClampInt(unsigned int*, int, int);

}  // namespace fnv_009f30d0
using fnv_009f30d0::RefExtraHelper;
using fnv_009f30d0::ExtraHelper;
using fnv_009f30d0::PatrolHelper;
using fnv_009f30d0::ClampInt;

// @fnv 0x009f30d0
bool PatrolActorPackageData::SetPatrolRefIndex(unsigned int aiRefIndex)
{
    if (References.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() ||
        !m_bReferenceFlag)
    {
        m_uiSecondValueAfterReferenceFlag = aiRefIndex;
        return true;
    }
    unsigned int aiclampedRefIndex = aiRefIndex;
    int isize = References.GetSize() - 1;
    ClampInt(&aiclampedRefIndex, 0, isize);
    bool bsuccess = true;
    TESObjectREFR* pnewRef =
        (TESObjectREFR*)References.GetAt(aiclampedRefIndex);
    ExtraDataList* pnewExtra = pnewRef ? (ExtraDataList*)((RefExtraHelper*)pnewRef)->GetExtra() : 0;
    if (pnewExtra)
    {
        if (((ExtraHelper*)pnewExtra)->ExtraDataList_GetPatrolRefCanBeUsedBy(pActor))
        {
            ((PatrolHelper*)this)->PatrolActorPackageData_ClearReservedPatrolRef();
            ((ExtraHelper*)pnewExtra)->ExtraDataList_SetPatrolRefInUse(pActor);
            m_uiSecondValueAfterReferenceFlag = aiclampedRefIndex;
        }
        else
        {
            bsuccess = false;
        }
    }
    return bsuccess;
}


// @fnv 0x009f3390
TESObjectREFR* PatrolActorPackageData::GetCurrentPatrolReference()
{
    if (!References.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        return References.GetAt(m_uiSecondValueAfterReferenceFlag);
    }
    else
    {
        return 0;
    }
}

struct DH
{
    bool TESDataHandler_GetClearingData();
};
extern DH* g_dataHandler;
struct PatrolCleanupAccess
{
    void PatrolActorPackageData_ClearReservedPatrolRef();
};
// @fnv 0x009f2a70
PatrolActorPackageData::~PatrolActorPackageData()
{
    if (!g_dataHandler->TESDataHandler_GetClearingData())
        ((PatrolCleanupAccess*)this)->PatrolActorPackageData_ClearReservedPatrolRef();
    References.SetSize(0, true);
    eState = PATROL_STATE_DEBUG_DESTRUCTED;
    pActor = 0;
    pPackage = 0;
    m_pEscortPackageData = 0;
}


// @fnv 0x009f33d0
void PatrolActorPackageData::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData(&eState, 4, 0);
    apSaveGameBuffer->SaveData(&m_fElapsedWaitTime, 4, 0);
    apSaveGameBuffer->SaveData(&m_uiSecondValueAfterReferenceFlag, 4, 0);
    apSaveGameBuffer->SaveData(&m_bPatrolFlag, 1, 0);
    apSaveGameBuffer->SaveData(&m_bReferenceFlag, 1, 0);
    apSaveGameBuffer->SaveData(&m_uiValueAfterReferenceFlag, 4, 0);
    apSaveGameBuffer->SerializeFormData(pPackage, 0);
    unsigned int isaveGameCount = (reinterpret_cast<BSSimpleArray<TESObjectREFR*, 1024>*>(reinterpret_cast<char*>(this) + offsetof(PatrolActorPackageData, References))) ? References.GetSize() : 0;
    apSaveGameBuffer->SaveVariableSizedValue(isaveGameCount);
    for (unsigned int i = 0; i < isaveGameCount; ++i)
    {
        TESObjectREFR** ppRefr = (TESObjectREFR**)&reinterpret_cast<BSSimpleArray<unsigned int, 1024>&>(References).GetAt((int)i);
        apSaveGameBuffer->SerializeFormData(*ppRefr, 0);
    }
}

struct PatrolTarget
{
    bool ExtraDataList_GetPatrolRefCanBeUsedBy(void* p);
};
struct PatrolRef
{
    PatrolTarget* BSFile_GetDevice();
};


// Computes the next patrol index from m_uiSecondValueAfterReferenceFlag and m_bPatrolFlag, wrapping or reversing at the ends, and applies it via SetPatrolRefIndex when abApply is set.
// @fnv 0x009f2ea0
bool PatrolActorPackageData::AdvanceToNextReference(bool abApply)
{
    int idx = m_uiSecondValueAfterReferenceFlag;
    bool bResult = true;
    bool bLoop = m_pEscortPackageData ? ((PatrolPackage*)m_pEscortPackageData)->TESRegionData_GetOverride() : false;
    if (m_bPatrolFlag)
    {
        idx++;
        if (idx == References.GetSize())
        {
            if (bLoop)
            {
                if (m_bReferenceFlag)
                {
                    idx = m_uiValueAfterReferenceFlag;
                }
                else
                {
                    if (References.GetSize() == 1)
                        idx = 0;
                    else
                        idx -= 2;
                    m_bPatrolFlag = !m_bPatrolFlag;
                }
            }
            else
            {
                idx = 0;
                bResult = false;
            }
        }
    }
    else
    {
        idx--;
        if (idx == -1)
        {
            if (bLoop)
            {
                if (m_bReferenceFlag)
                {
                    idx = 0;
                    bResult = false;
                }
                else
                {
                    if (References.GetSize() == 1)
                        idx = 0;
                    else
                        idx = 1;
                    m_bPatrolFlag = !m_bPatrolFlag;
                }
            }
            else
            {
                idx = 0;
                bResult = false;
            }
        }
    }
    if (abApply)
    {
        if (idx != m_uiSecondValueAfterReferenceFlag)
        {
            bool bOk = SetPatrolRefIndex(idx);
            if (!bOk)
            {
                unsigned int numRefs = References.GetSize();
                unsigned int uiValid = numRefs - 1;
                for (unsigned int i = 0; i < numRefs; i++)
                {
                    PatrolRef* pRef = (PatrolRef*)References.GetAt(i);
                    PatrolTarget* pTarget = pRef ? pRef->BSFile_GetDevice() : 0;
                    if (i == m_uiSecondValueAfterReferenceFlag)
                        continue;
                    if (!pTarget || !pTarget->ExtraDataList_GetPatrolRefCanBeUsedBy(pActor))
                        uiValid--;
                }
                if (uiValid <= 0)
                    return AdvanceToNextReference(false);
            }
        }
    }
    else
    {
        m_uiSecondValueAfterReferenceFlag = idx;
    }
    return bResult;
}

namespace fnv_009f31c0 {
struct PatrolRefStub
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
    PatrolTarget* GetTarget();
};
extern float DAT_01016970;

}  // namespace fnv_009f31c0
using fnv_009f31c0::PatrolRefStub;
using fnv_009f31c0::DAT_01016970;

// @fnv 0x009f31c0
void PatrolActorPackageData::SelectClosestPatrolPoint(const NiPoint3& arPoint)
{
    if (!pActor)
        return;
    int BackgroundTask = References.GetSize();
    SetPatrolRefIndex(0);
    m_bPatrolFlag = true;
    PatrolRefStub* pOld = 0;
    NiPoint3* pOrigPos = 0;
    int iPrevIdx = 0;
    bool bOldForward = true;
    PatrolRefStub* pR = (PatrolRefStub*)GetCurrentPatrolReference();
    if (!pR)
        return;
    NiPoint3* pPt = pR->GetPos();
    float afThirdFloatArgument = DAT_01016970;
    int iWinner = 0;
    bool bBest = true;
    bool bSuccess = false;
    for (int i = 0; i < BackgroundTask; i++)
    {
        iPrevIdx = m_uiSecondValueAfterReferenceFlag;
        bOldForward = m_bPatrolFlag;
        pOld = pR;
        pOrigPos = pPt;
        AdvanceToNextReference(false);
        PatrolRefStub* pNext = (PatrolRefStub*)GetCurrentPatrolReference();
        PatrolTarget* pData = pNext ? pNext->GetTarget() : 0;
        if (!pData || pData->ExtraDataList_GetPatrolRefCanBeUsedBy(pActor))
        {
            pR = (PatrolRefStub*)GetCurrentPatrolReference();
            if (!pR)
                break;
            pPt = pR->GetPos();
            NiPoint3 kDelta = *pOrigPos - arPoint;
            NiPoint3 kLine = *pPt - *pOrigPos;
            float fDistance = kDelta.GetSquaredXYLength();
            if (fDistance < afThirdFloatArgument)
            {
                afThirdFloatArgument = fDistance;
                iWinner = iPrevIdx;
                bBest = bOldForward;
                bSuccess = true;
            }
        }
    }
    if (bSuccess)
    {
        SetPatrolRefIndex(iWinner);
        m_bPatrolFlag = bBest;
    }
    m_bPatrolFlag = true;
}

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct PatrolReference
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual const NiPoint3& GetPos();
};
// The shared array does not yet declare this erase operation.
struct PatrolReferenceArrayAccess : BSSimpleArray<unsigned int, 1024>
{
    void RemoveAt(unsigned int, bool);
};
// Removes a patrol reference: if it is the active one, resets state; otherwise erases it from the array and adjusts the active index.
// @fnv 0x009f2c30
void PatrolActorPackageData::SetReferenceTarget(TESObjectREFR* reference)
{
    if (reference == (TESObjectREFR*)pActor)
    {
        ((PatrolCleanupAccess*)this)->PatrolActorPackageData_ClearReservedPatrolRef();
        eState = PATROL_STATE_DEBUG_ACTOR_DELETED;
        pActor = 0;
        pPackage = 0;
        m_pEscortPackageData = 0;
    }
    else
    {
        unsigned int index;
        for (index = 0; index < References.GetSize(); index++)
        {
            if (References.GetAt(index) == reference)
            {
                reinterpret_cast<PatrolReferenceArrayAccess&>(References).RemoveAt(index, true);
                if (m_uiSecondValueAfterReferenceFlag >= index)
                    m_uiSecondValueAfterReferenceFlag--;
                index--;
            }
        }
        if (pActor && !g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        {
            if (!SetPatrolRefIndex(m_uiSecondValueAfterReferenceFlag))
            {
                SelectClosestPatrolPoint(((PatrolReference*)pActor)->GetPos());
            }
        }
    }
}
