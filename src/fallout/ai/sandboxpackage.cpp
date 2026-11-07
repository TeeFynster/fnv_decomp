
// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/sandboxpackage.cpp
#include "../../../include/TESPackage.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/BSAnimGroupSequence.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiPoint3.h"
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include <string.h>
#pragma intrinsic(memcpy)

#include "sandboxpackage_idle.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSSaveGameBuffer.h"

// If the location has a valid timestamp that has passed, follows its linked reference and stores it as the new location, resetting the timestamp.
// @fnv 0x009f3c10
bool SandBoxActorPackageData::IsLocationCheckDue()
{
    if (pLocation != NULL && m_uiLastProcedureCheckDay != 0xFFFFFFFF)
    {
        unsigned int uiNow = g_timeGlobal.GetTimeStamp();
        if (uiNow > m_uiLastProcedureCheckDay)
        {
            TESObjectREFR* pNext = ((ExtraDataListHelper*)pLocation->GetExtraData())->GetLinkedRef();
            if (pNext != NULL && pNext != pLocation)
            {
                pLocation = pNext;
                m_uiLastProcedureCheckDay = 0xFFFFFFFF;
                return true;
            }
        }
    }
    return false;
}

// Checks whether the sandbox activity is currently active by comparing the current day and hour against the activity's start day/hour and computed end day/hour.
// @fnv 0x009f3d50
bool SandBoxActorPackageData::IsActivityTime()
{
    float fEndHour;
    {
        unsigned int uiDay = g_calendar.GetDaysPassed();
        {
            float fHour = g_calendar.GetGameTime();
            {
                bool bLastDay = false;
                if (m_eSandboxActivity == SANDBOX_ACTIVITY_NONE)
                    return true;
                {
                    unsigned int uiEndDay;
                    uiEndDay = m_uiActivityEndDay;
                    fEndHour = m_fActivityStartHour + m_fActivityEndHour;
                    while (fEndHour >= 24.0)
                    {
                        fEndHour -= 24.0;
                        uiEndDay++;
                    }
                    if (uiDay < m_uiActivityEndDay || uiDay > uiEndDay)
                        return false;
                    if (uiDay == m_uiActivityEndDay && fHour < m_fActivityStartHour)
                        return false;
                    if (uiDay == uiEndDay && fHour >= fEndHour)
                        return false;
                }
                return true;
            }
        }
    }
}

// @fnv 0x009f40c0
void SandBoxActorPackageData::SetReferenceTarget(TESObjectREFR* apDeletedRef)
{
    if (apDeletedRef == NULL)
        return;
    {
        int iCount;
        {
            int iIndex;
            {
                bool bReset = false;
                if (pLocation == apDeletedRef)
                    pLocation = NULL;
                if (m_pCurrentFurniture == apDeletedRef)
                    m_pCurrentFurniture = NULL;
                if (m_pCurrentTarget == apDeletedRef)
                    bReset = true;
                iCount = m_kProcedureList.GetSize();
                iIndex = 0;
                while (iIndex < iCount)
                {
                    if (m_kProcedureList.GetAt(iIndex).GetTarget() == apDeletedRef)
                    {
                        bReset = true;
                        m_kProcedureList.RemoveAt(static_cast<unsigned int>(iIndex), 1u);
                        iCount--;
                    }
                    else
                    {
                        iIndex++;
                    }
                }
                if (bReset)
                {
                    eProcedure = SANDBOX_PROCEDURE_NONE;
                    m_fProcedureTime = 0.0F;
                    m_pCurrentTarget = NULL;
                    m_pCurrentFurniture = NULL;
                    m_ucProcedureIndex = 0x7F;
                    m_bNeedsSandboxUpdate = true;
                    m_uiProcedureIndex = 0;
                }
            }
        }
    }
}

// Checks the current sandbox target and markers, clears stale flags, and returns whether a new target should be picked based on timers, state and hour difference.
// @fnv 0x009f43c0
bool SandBoxActorPackageData::HasProcessTarget(Actor* apActor)
{
    {
        SandboxTargetInfo* pTargetInfo = ((ActorTargetSource*)apActor)->GetProcessTarget();
        {
            float fValue;
            {
                bool bPickNew;
                if (pTargetInfo != NULL)
                {
                    {
                        bool bChanged = false;
                        if (m_bHasBedMarker && !pTargetInfo->CheckBedMarker())
                        {
                            m_bHasBedMarker = false;
                            bChanged = true;
                        }
                        if (m_bHasFoodMarker && !pTargetInfo->CheckFoodMarker())
                        {
                            m_bHasFoodMarker = false;
                            bChanged = true;
                        }
                        if (m_bHasChairMarker && !pTargetInfo->CheckChairMarker())
                        {
                            m_bHasChairMarker = false;
                            bChanged = true;
                        }
                        if (bChanged)
                        {
                            m_uiProcedureIndex = g_timeGlobal.GetTimeStamp();
                            return true;
                        }
                    }
                }
                if (pLocation != NULL && eProcedure != SANDBOX_PROCEDURE_USE_IDLE_MARKER &&
                    m_uiLastProcedureCheckDay != 0xFFFFFFFF)
                {
                    if (g_timeGlobal.GetTimeStamp() > m_uiLastProcedureCheckDay)
                        return true;
                }
                if (!IsActorWithinLocationRadius(apActor, true))
                    return false;
                if (m_bNeedsSandboxUpdate)
                    return true;
                if (eProcedure == SANDBOX_PROCEDURE_NONE || m_fProcedureTime <= 0.0)
                    return true;
                if (m_fNextProcedureCheckHour == 0.0)
                    return true;
                if (eState != SANDBOX_STATE_DOINGSTUFF &&
                    m_pCurrentTarget != NULL)
                {
                    if (((TESObjectREFRHelper*)m_pCurrentTarget)->IsMarkerAvailable(m_ucProcedureIndex, true))
                        return true;
                }
                if (HasActivityEnded(NULL))
                    return true;
                if (IsActivityTime() && IsActivityProcedure())
                    return eProcedure != g_procedureForActivity[m_eSandboxActivity];
                bPickNew = false;
                fValue = GetHourDifference(m_fLastProcedureCheckHour, g_calendar.GetGameTime());
                if (fValue > m_fProcedureTime)
                    bPickNew = true;
                return bPickNew;
            }
        }
    }
}

// Reads the sandbox actor package data fields from the load buffer, adjusts the timestamp against g_timeGlobal, and loads the choice array entries.
// @fnv 0x009f5ca0
void SandBoxActorPackageData::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    int iSavedTimeStamp;
    unsigned int ItemUpdateArray;
    apBuffer->ReadTypedData(static_cast<void*>(&eState), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&eProcedure), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_fProcedureTime), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_fLastProcedureCheckHour), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_fNextProcedureCheckHour), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_uiLastProcedureCheckDay), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_fProcedureTime), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_uiProcedureIndex), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_bNeedsSandboxUpdate), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_bHasFoodMarker), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_bHasChairMarker), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_bHasBedMarker), 1u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_iSerializedValue), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_ucProcedureIndex), 1u);
    iSavedTimeStamp = 0;
    apBuffer->ReadTypedData(static_cast<void*>(&iSavedTimeStamp), 4u);
    m_uiActivityStartDay = g_timeGlobal.GetTimeStamp() - iSavedTimeStamp;
    apBuffer->ReadTypedData(static_cast<void*>(&m_uiActivityEndDay), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_fActivityStartHour), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_fActivityEndHour), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(&m_eSandboxActivity), 4u);
    apBuffer->ReadTypedData(static_cast<void*>(m_ucProcedureFlags), 6u);
    apBuffer->ReadFormIdentifier(&pLocation);
    apBuffer->ReadFormIdentifier(&m_pCurrentTarget);
    apBuffer->ReadFormIdentifier(&m_pCurrentFurniture);
    ItemUpdateArray = apBuffer->ReadElementCount();
    m_kProcedureList.SetSize(ItemUpdateArray, true);
    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        SandboxProcedureData* pItem = &m_kProcedureList.GetAt(uiIndex);
        pItem->LoadGame(apBuffer);
    }
}

// @fnv 0x009f5ea0
void SandBoxActorPackageData::InitLoadGame(BGSLoadFormBuffer* apBuffer)
{
    pLocation = pLocation ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)pLocation)) : NULL;
    m_pCurrentTarget =
        m_pCurrentTarget ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)m_pCurrentTarget)) : NULL;
    if (m_pCurrentTarget != NULL)
        ((TESObjectREFRHelper*)m_pCurrentTarget)->SetTargetingState(true);
    m_pCurrentFurniture = m_pCurrentFurniture
                              ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)m_pCurrentFurniture))
                              : NULL;
    if (m_pCurrentFurniture != NULL)
        ((TESObjectREFRHelper*)m_pCurrentFurniture)->SetTargetingState(true);
    {
        int iCount;
        {
            int iIndex;
            {
                bool bResetState;
                {
                    unsigned int uiNumTargets;
                    {
                        unsigned int uiTargetIndex;
                        uiNumTargets = m_kProcedureList.GetSize();
                        for (uiTargetIndex = 0; uiTargetIndex < uiNumTargets; uiTargetIndex++)
                        {
                            {
                                SandboxProcedureData* pItem = &m_kProcedureList.GetAt(uiTargetIndex);
                                pItem->InitLoadGame(apBuffer);
                            }
                        }
                        iCount = m_kProcedureList.GetSize();
                        iIndex = 0;
                        bResetState = false;
                        while (iIndex < iCount)
                        {
                            {
                                SandboxProcedureData* pChoice = &m_kProcedureList.GetAt(iIndex);
                                if (pChoice->GetTarget() == NULL && IsValidSandboxProcedure(pChoice->GetProcedure()))
                                {
                                    m_kProcedureList.RemoveAt(static_cast<unsigned int>(iIndex), 1u);
                                    iCount--;
                                    bResetState = true;
                                }
                                else
                                {
                                    iIndex++;
                                }
                            }
                        }
                        if (m_pCurrentTarget != NULL)
                        {
                            if (((TESObjectREFRHelper*)m_pCurrentTarget)->IsReferenceActive(false))
                                ((TESObjectREFRHelper*)m_pCurrentTarget)->SetMarkerState(m_ucProcedureIndex, true);
                            else
                                bResetState = true;
                        }
                        if (bResetState || m_pCurrentTarget == NULL)
                        {
                            eProcedure = SANDBOX_PROCEDURE_NONE;
                            m_fProcedureTime = 0.0F;
                            m_pCurrentTarget = NULL;
                            m_ucProcedureIndex = 0x7F;
                            m_bNeedsSandboxUpdate = true;
                            m_uiProcedureIndex = 0;
                        }
                        if (pLocation != NULL && m_uiLastProcedureCheckDay == 0)
                        {
                            m_uiLastProcedureCheckDay = 0xFFFFFFFF;
                            if (((ExtraDataListHelper*)pLocation->GetExtraData())->GetLinkedRef() != NULL)
                            {
                                m_uiLastProcedureCheckDay = 0;
                                {
                                    RegionPoint* pPatrolRefData =
                                        pLocation->GetExtraData()->GetStartingPositionData();
                                    if (pPatrolRefData != NULL)
                                    {
                                        m_uiLastProcedureCheckDay = g_timeGlobal.GetTimeStamp() +
                                                                    (unsigned int)(pPatrolRefData->GetX() * 1000.0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// @fnv 0x009f4300
bool SandBoxActorPackageData::IsActorWithinLocationRadius(Actor* actor, bool update)
{
    // Idle animation context: process, sequence, animation and group state.
    struct IdleState
    {
        BaseProcess* process;
        BSAnimGroupSequence* sequence;
        Animation* animation;
        int unused;
    } idle;
    if (eProcedure == 0 || eProcedure == 4)
    {
        {
            switch (((PlayerCharacter*)actor)->GetAnimAction())
            {
            case 12:
            case 13:
                return false;
            }
        }
        idle.animation = reinterpret_cast<Animation*>(actor->GetAnimData());
        idle.unused = -1;
        if (idle.animation)
        {
            if (!idle.animation->IsSequenceActive())
                return false;
            if (update)
            {
                idle.sequence = idle.animation->GetPlayingSequence();
                if (idle.sequence && idle.sequence->GetState() != 3)
                {
                    idle.process = actor->GetProcess();
                    idle.process->RefreshActorValues(actor);
                }
            }
        }
    }
    return true;
}

// @fnv 0x009f56b0
bool SandboxPackageOperations::IsObjectWithinLocationRadius(MobileObject* object, float afRadius)
{
    // Keep the related location query results and radius policy together.
    struct LocationState
    {
        void* helper;
        RegionPoint* patrol;
        float adjustment;
        Actor* locationActor;
        TESPackage* package;
        Actor* actor;
        char pad20, pad21, pad22;
        bool same;
        float radius;
        TESObjectCELL* objectCell;
        TESObjectCELL* locationCell;
        TESWorldSpace* locationWorld;
        NiPoint3* position;
        TESWorldSpace* objectWorld;
        char pad5, pad6, pad7;
        bool special;
    } state;
    if (!object)
        return false;
    state.actor = 0;
    if (object->IsActor())
        state.actor = (Actor*)object;
    if (!pLocation)
    {
        if (state.actor)
        {
            state.package = reinterpret_cast<TESPackage*>(state.actor->GetCurrentPackage());  // the shared Actor's 0x009344a0
            if (state.package)
                return state.package->IsActorWithinPackageRadius(state.actor, false, -1.0f, false);
        }
        return false;
    }
    state.locationWorld = pLocation->GetParentWorldSpace();
    state.locationCell = pLocation->GetParentCell();
    if (state.locationCell && !state.locationCell->IsCellInterior())
        state.locationCell = 0;
    state.objectWorld = object->GetParentWorldSpace();
    state.objectCell = object->GetParentCell();
    if (state.objectCell && !state.objectCell->IsCellInterior())
        state.objectCell = 0;
    state.same = false;
    if (state.objectCell || state.locationCell)
    {
        if (state.objectCell == state.locationCell)
            state.same = true;
    }
    else
    {
        if (state.objectWorld == state.locationWorld)
            state.same = true;
    }
    if (!state.same)
        return false;
    state.radius = afRadius;
    state.special = false;
    state.position = static_cast<const TESObjectREFR*>(pLocation)->GetPos();
    if (state.radius == 0.0)
    {
        if (pLocation->GetObjectReference() == DAT_011ca248 || pLocation->GetObjectReference() == DAT_011ca244)
        {
            state.radius = runtimeFloatSettingDefault94;
        }
        else if (pLocation->IsActor())
        {
            state.locationActor = (Actor*)pLocation;
            if (state.locationActor->GetSitSleepState() == 9)
            {
                state.radius = DAT_010249d8;
                state.special = true;
            }
            else
            {
                state.radius = pLocation->GetBoundingRadius() + 20.0;
            }
        }
        else
        {
            state.adjustment = runtimeFloatSettingDefault94;
            switch (((TESForm*)pLocation->GetObjectReference())->GetFormType())
            {
            case 21:
            case 27:
            case 32:
            case 33:
                state.adjustment = 0.0f;
                break;
            }
            state.radius = pLocation->GetBoundingRadius() + state.adjustment;
            if (state.radius < 0.0)
                state.radius = 0.0f;
        }
    }
    if (state.radius == 0.0)
        state.radius = (float)g_011cde98.Int()->i;
    if (object->IsWithinDistance(state.position, state.radius, !state.special, true))
    {
        if (m_uiLastProcedureCheckDay == 0xffffffff && pLocation->GetExtraData() &&
            ((ExtraDataListHelper*)pLocation->GetExtraData())->GetLinkedRef())
        {
            m_uiLastProcedureCheckDay = 0;
            state.patrol = pLocation->GetExtraData()->GetStartingPositionData();
            if (state.patrol)
                m_uiLastProcedureCheckDay = g_timeGlobal.GetTimeStamp() + (unsigned int)(state.patrol->GetX() * 1000.0);
            if (eProcedure > -1 && eProcedure < 6)
            {
                state.helper = static_cast<SandboxActorEnergySource*>(state.actor)->Actor_GetActorBaseEnergyLevel();
                m_fProcedureTime = AiFormulas_ComputeRandomSandboxSubProcessDuration(state.helper, eProcedure);
            }
        }
        return true;
    }
    return false;
}

// Releases the current target and starts the getting-up state.
// @fnv 0x009f41c0
void __thiscall SandboxPackageOperations::BeginGettingUp()
{
    ResetReference();
    m_bNeedsSandboxUpdate = true;
    eState = SANDBOX_STATE_GETTING_UP;
}

namespace fnv_009f4700 {
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting255;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting256;
extern int g_011cdb3c;
extern int g_011cd0a4;
extern int g_011cdf60;
int& __fastcall Setting_Int(int*);
unsigned int GetRandomNumberInRange(int, int);
int BSMAX_00647b70(int, int);
int GetRandomNumber();

struct DurationData
{
    int FUN_00726070();
};
struct SandBoxChoiceListItem_ext : public SandboxProcedureData
{
    void FUN_0041fd00(int);
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned int FUN_0044ddc0();
};
struct FUN_005682c0_caller
{
    int TESObjectREFR_GetFirstFreeMarkerIndex(bool);
};

}  // namespace fnv_009f4700

// Scores sandbox choice list items by procedure probability and distance, picks one by weighted random, and stores the chosen procedure, target and energy.
// @fnv 0x009f4700
void SandboxPackageOperations::SelectSandboxActivity(Actor* apActor, TESPackage* apOriginalPackage)
{
    using namespace fnv_009f4700;
    int isandboxProceduresProbabilities[6];
    int inumTargets;
    float fsearchDialogueDistSqr;
    TESWorldSpace* ppackageWorldSpace;
    TESObjectCELL* ppackageCell;
    float fsearchDistSqr;
    BaseProcess* process;
    float fsearchDist;
    bool bcanPerformActivity;
    int i;
    // Raw coordinate storage is filled by the checked NiPoint3 values below.
    float packageLoc[3];
    int itotalProb;
    TESPackage* ppack;

    m_bNeedsSandboxUpdate = false;
    SelectActivity();
    if (m_fNextProcedureCheckHour == 0.0)
    {
        if (apOriginalPackage && apOriginalPackage->TESPackage_GetPackageSchedule())
            m_fNextProcedureCheckHour = (float)reinterpret_cast<fnv_009f4700::DurationData*>(apOriginalPackage->TESPackage_GetPackageSchedule())->FUN_00726070();
        if (m_fNextProcedureCheckHour == 0.0)
            m_fNextProcedureCheckHour = 24.0f;
    }
    if (m_pCurrentTarget && m_pCurrentFurniture != m_pCurrentTarget)
    {
        m_uiActivityStartDay = g_timeGlobal.GetTimeStamp() + Setting_Int(&g_011cdb3c) * 1000;
        m_pCurrentFurniture = m_pCurrentTarget;
    }
    if (m_pCurrentFurniture && g_timeGlobal.GetTimeStamp() > m_uiActivityStartDay)
        m_pCurrentFurniture = 0;
    if (m_pCurrentTarget)
        static_cast<TESObjectREFRHelper*>(m_pCurrentTarget)->SetMarkerState(m_ucProcedureIndex, false);
    m_pCurrentTarget = 0;
    m_ucProcedureIndex = 127;
    eProcedure = SANDBOX_PROCEDURE_NONE;
    m_fProcedureTime = 0.0f;
    if (g_timeGlobal.GetTimeStamp() >= m_uiProcedureIndex)
    {
        ResetReference();
        ScanSandboxTargets(apActor);
        m_uiProcedureIndex = g_timeGlobal.GetTimeStamp() +
                             GetRandomNumberInRange(Setting_Int(&g_011cd0a4) * 1000, Setting_Int(&g_011cdf60) * 1000);
    }
    bcanPerformActivity = IsActivityTime() && IsActivityProcedure();
    if (bcanPerformActivity)
    {
        for (i = 0; i < 6; i++)
            isandboxProceduresProbabilities[i] = 0;
        isandboxProceduresProbabilities[g_procedureForActivity[m_eSandboxActivity]] = 10;
    }
    else
    {
        for (i = 0; i < 6; i++)
            isandboxProceduresProbabilities[i] = m_ucProcedureFlags[i];
        isandboxProceduresProbabilities[SANDBOX_PROCEDURE_SLEEP] = 0;
        if (m_bHasFoodMarker)
            isandboxProceduresProbabilities[SANDBOX_PROCEDURE_EAT] += 20;
        if (!m_bHasChairMarker)
            isandboxProceduresProbabilities[SANDBOX_PROCEDURE_EAT] -= 15;
        if (apActor->GetProcess() &&
            apActor->GetProcess()->GetFirstProcessFloat() > 0.0)
            isandboxProceduresProbabilities[SANDBOX_PROCEDURE_DIALOGUE] = 0;
    }
    itotalProb = 0;
    inumTargets = reinterpret_cast<SandBoxChoiceListItem_ext*>(&m_kProcedureList)->FUN_0044ddc0();
    process = apActor->GetProcess();
    fsearchDist = *originalRuntimeFloatSetting255.Float();
    memcpy(packageLoc, static_cast<const TESObjectREFR*>(apActor)->GetPos(), sizeof(packageLoc));
    ppackageCell = apActor->GetParentCell();
    ppack = reinterpret_cast<TESPackage*>(apActor->GetCurrentPackage());
    if (ppack)
    {
        int ipackageLocRadius;
        memcpy(packageLoc, &ppack->GetPackageLocationPosition(apActor), sizeof(packageLoc));
        ppackageCell = ppack->GetPackageLocationCell(apActor);
        ipackageLocRadius = ppack->FUN_00676280(apActor);
        fsearchDist = ipackageLocRadius > 0 ? (float)ipackageLocRadius : fsearchDist;
    }
    if (pLocation)
    {
        memcpy(packageLoc, static_cast<const TESObjectREFR*>(pLocation)->GetPos(), sizeof(packageLoc));
        ppackageCell = pLocation->GetParentCell();
    }
    ppackageWorldSpace = ppackageCell ? ppackageCell->GetParentWorldSpace()
                                      : apActor->GetParentWorldSpace();
    fsearchDialogueDistSqr = fsearchDist + *originalRuntimeFloatSetting256.Float();
    fsearchDistSqr = fsearchDist * fsearchDist;
    fsearchDialogueDistSqr = fsearchDialogueDistSqr * fsearchDialogueDistSqr;
    for (i = 0; i < inumTargets; i++)
    {
        SandBoxChoiceListItem_ext* item;
        TESObjectREFR* ptargObject;
        int score;
        TESPackage* ppack;
        item = static_cast<SandBoxChoiceListItem_ext*>(&m_kProcedureList.GetAt(i));
        score = item->FUN_0044ddc0() * isandboxProceduresProbabilities[item->GetProcedure()];
        score = BSMAX_00647b70(score, 0);
        ppack = reinterpret_cast<TESPackage*>(apActor->GetCurrentPackage());
        ptargObject = item->GetTarget();
        if (ptargObject)
        {
            float fmaxDistSqr;
            TESObjectCELL* ptargetCell;
            bool bisDialogue;
            bool binterior;
            if (ptargObject == m_pCurrentFurniture)
            {
                item->FUN_0041fd00(0);
                continue;
            }
            binterior = false;
            ptargetCell = ptargObject->GetParentCell();
            if (ppackageCell && ptargetCell &&
                (ppackageCell->IsInterior() ||
                 ptargetCell->IsInterior()))
            {
                binterior = true;
                if (ppackageCell != ptargetCell)
                    continue;
            }
            if (!binterior)
            {
                TESWorldSpace* ptargetWorldSpace = ptargetCell
                                                       ? ptargetCell->GetParentWorldSpace()
                                                       : ptargObject->GetParentWorldSpace();
                if (ppackageWorldSpace != ptargetWorldSpace)
                    continue;
            }
            bisDialogue = item->GetProcedure() == SANDBOX_PROCEDURE_DIALOGUE;
            fmaxDistSqr = bisDialogue ? fsearchDialogueDistSqr : fsearchDistSqr;
            if (fmaxDistSqr <
                reinterpret_cast<const NiPoint3&>(reinterpret_cast<NiPoint3*>(static_cast<const TESObjectREFR*>(ptargObject)->GetPos())
                                                         ->operator-(reinterpret_cast<const NiPoint3&>(packageLoc)))
                    .FUN_004a7290())
            {
                item->FUN_0041fd00(0);
                continue;
            }
            if (!ptargObject->IsReferenceActive(false))
            {
                item->FUN_0041fd00(0);
                continue;
            }
            if (bisDialogue)
            {
                Actor* ptargetActor = static_cast<Actor*>(ptargObject);
                int ereaction;
                if (!apActor->GetProcess() ||
                    !apActor->GetProcess()->IsValidCombatTarget(apActor, ptargetActor))
                {
                    item->FUN_0041fd00(0);
                    continue;
                }
                ereaction = 0;
                if (apActor->IsHostileToActor(ptargetActor, 0, &ereaction, false) ||
                    ptargetActor->IsHostileToActor(apActor, 0, &ereaction, false))
                {
                    item->FUN_0041fd00(0);
                    continue;
                }
            }
        }
        item->FUN_0041fd00(score);
        itotalProb += score;
    }
    if (itotalProb > 0)
    {
        int irandom;
        int iIndex;
        SandboxProcedureData ritem;
        int iactorEnergy;
        irandom = GetRandomNumber() % itotalProb;
        for (i = 0; i < inumTargets; i++)
        {
            SandBoxChoiceListItem_ext* item = static_cast<SandBoxChoiceListItem_ext*>(&m_kProcedureList.GetAt(i));
            if ((irandom -= item->GetHavokWorldObjectCountInSceneGraph_0084e3a0()) < 0)
                break;
        }
        ritem = m_kProcedureList.GetAt(i);
        eProcedure = ritem.GetProcedure();
        m_pCurrentTarget = ritem.GetTarget();
        iIndex = m_pCurrentTarget ? reinterpret_cast<FUN_005682c0_caller*>(m_pCurrentTarget)->TESObjectREFR_GetFirstFreeMarkerIndex(false) : -1;
        m_ucProcedureIndex = iIndex < 0 ? 0 : (unsigned char)iIndex;
        iactorEnergy = reinterpret_cast<int>(static_cast<SandboxActorEnergySource*>(apActor)->Actor_GetActorBaseEnergyLevel());
        m_fProcedureTime = AiFormulas_ComputeRandomSandboxSubProcessDuration((void*)iactorEnergy, eProcedure);
        for (i = 0; i < 6; i++)
        {
            unsigned char cweight = m_ucProcedureFlags[i];
            cweight = cweight < 255 ? cweight + 1 : cweight;
            m_ucProcedureFlags[i] = cweight;
        }
        m_ucProcedureFlags[eProcedure] = 1;
        if (m_pCurrentTarget)
            static_cast<TESObjectREFRHelper*>(m_pCurrentTarget)->SetMarkerState(m_ucProcedureIndex, true);
    }
    else
    {
        eProcedure = SANDBOX_PROCEDURE_NONE;
        m_fProcedureTime = 0.0f;
        m_pCurrentTarget = 0;
        m_ucProcedureIndex = 127;
    }
    m_fLastProcedureCheckHour = g_calendar.GetGameTime();
}

struct FUN_009f3800
{
    TESObjectREFRHelper* f0;
    int f1;
    int f2;
    int f3;
    FUN_009f3800(TESObjectREFRHelper* a, int b, int c);
};
// Stores the helper pointer and two ints, zeroes the third field, and if the helper is non-null calls its method with true.
// @fnv 0x009f3800
FUN_009f3800::FUN_009f3800(TESObjectREFRHelper* pHelper, int b, int c)
{
    f0 = pHelper;
    f1 = b;
    f2 = c;
    f3 = 0;
    if (f0 != 0)
        f0->SetTargetingState(true);
}

void __cdecl _Deallocate(void*);

struct DH
{
    bool TESDataHandler_GetClearingData();
};
extern DH* g_dataHandler;
// @fnv 0x009f4060
void SandboxPackageOperations::ResetReference()
{
    if (g_dataHandler == 0 || !g_dataHandler->TESDataHandler_GetClearingData())
    {
        if (m_pCurrentTarget != 0)
        {
            static_cast<TESObjectREFRHelper*>(m_pCurrentTarget)->SetMarkerState(m_ucProcedureIndex, false);
        }
    }
    m_pCurrentTarget = 0;
    m_ucProcedureIndex = 0x7f;
}

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int __thiscall CallGetFlags();
};
extern int DAT_010935dc[];
struct FUN_009f4640_holder
{
    int __thiscall GetFlagsMappedValue();
};
// @fnv 0x009f4640
int __thiscall FUN_009f4640_holder::GetFlagsMappedValue()
{
    return ((TESObjectREFR_GetFlags_Helper*)this)->CallGetFlags() == 0xffffffff
               ? -1
               : DAT_010935dc[((TESObjectREFR_GetFlags_Helper*)this)->CallGetFlags()];
}

struct Arr16
{
    unsigned int BSSimpleArray_TeleportLink_1024_AddUninitialized();
};
struct Elem9f6340
{
    int f0;
    int f4;
    int f8;
    int fC;
};
struct Host9f6340
{
    int f00;
    Elem9f6340* f04;
    void __thiscall BSSimpleArray_SandBoxChoiceListItem_1024_ConstructItems(Elem9f6340* p, int v);
    unsigned int __thiscall AppendElement(Elem9f6340* p);
};
// @fnv 0x009f6340
unsigned int __thiscall Host9f6340::AppendElement(Elem9f6340* apElement)
{
    unsigned int uiIndex = ((Arr16*)this)->BSSimpleArray_TeleportLink_1024_AddUninitialized();
    BSSimpleArray_SandBoxChoiceListItem_1024_ConstructItems(f04 + uiIndex, 1);
    f04[uiIndex] = *apElement;
    return uiIndex;
}

// @fnv 0x009f45e0
bool __fastcall IsSandboxFlag1Clear(TESPackage* package)
{
    return !(*reinterpret_cast<unsigned short*>(&package->specificFlags) & 1) ? true : false;
}

// @fnv 0x009f4620
bool __fastcall IsSandboxFlag10Clear(TESPackage* package)
{
    return !(*reinterpret_cast<unsigned short*>(&package->specificFlags) & 0x10) ? true : false;
}

// @fnv 0x009f4680
void __thiscall SandboxPackageOperations::ClearTargetReferences(void* apArg1, void* apArg2)
{
    if (m_pCurrentTarget)
    {
        int count = reinterpret_cast<TESObjectREFR_GetFlags_Helper*>(&m_kProcedureList)->CallGetFlags();
        for (int i = 0; i < count; ++i)
        {
            SandboxProcedureData* item =
                &m_kProcedureList.GetAt(i);
            if (item->GetTarget() == m_pCurrentTarget)
                item->m_iActivityState = 0;
        }
    }
    SelectSandboxActivity(static_cast<Actor*>(apArg1), static_cast<TESPackage*>(apArg2));
}

// @fnv 0x009f54b0
bool __fastcall IsSandboxFlag8Clear(TESPackage* package)
{
    return (*reinterpret_cast<unsigned short*>(&package->specificFlags) & 8) ? false : true;
}

struct S006949d0
{
    void* __thiscall GetAt(int);
};
struct FUN_009f6190_shell : S006949d0
{
    void* __thiscall BSSimpleArray_SandBoxChoiceListItem_1024_GetAt(int a);
};
// @fnv 0x009f6190
// src: XBOX_PDB 0x009f6190
void* __thiscall FUN_009f6190_shell::BSSimpleArray_SandBoxChoiceListItem_1024_GetAt(int aiIndex)
{
    return GetAt(aiIndex);
}

struct EdgeArr
{
    char* Object_GetIndexedValue_006a1440(unsigned int);
};

struct FUN_00693d30_shell
{
    char pad[0x48];
    EdgeArr m_kEdges;
    char* GetEdge(unsigned short index);
};

// @fnv 0x00693d30
char* FUN_00693d30_shell::GetEdge(unsigned short index)
{
    return m_kEdges.Object_GetIndexedValue_006a1440(index);
}

// @fnv 0x009f3e20
bool __thiscall SandBoxActorPackageData::IsActivityProcedure()
{
    switch (m_eSandboxActivity)
    {
    case -1:
        return false;
    case 1:
    case 2:
    case 3:
        return m_bHasFoodMarker;
    case 0:
        return m_bHasBedMarker;
    default:
        return true;
    }
}

unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
struct FUN_0072ba80_shell
{
    void __thiscall FUN_0072ba80(void*, unsigned int);
};
struct FUN_006c8bd0_Class
{
    void __thiscall BSSimpleArray_NiColorA_1024_CopyItems(const char*, const char*, unsigned int);
};
struct FUN_009f63a0_shell
{
    char* f00;
    char* f04;
    unsigned int f08;
    void __thiscall BSSimpleArray_SandBoxChoiceListItem_1024_RemoveFast(char* apSrcAddr, unsigned int aiCount);
};
// @fnv 0x009f63a0
// src: XBOX_PDB 0x009f63a0
void __thiscall FUN_009f63a0_shell::BSSimpleArray_SandBoxChoiceListItem_1024_RemoveFast(char* apSrcAddr, unsigned int aiCount)
{
    unsigned int i = FUN_0042f5a0(f08 - (unsigned int)apSrcAddr - aiCount, aiCount);
    ((FUN_0072ba80_shell*)this)->FUN_0072ba80(f04 + (unsigned int)apSrcAddr * 16, aiCount);
    ((FUN_006c8bd0_Class*)this)->BSSimpleArray_NiColorA_1024_CopyItems(f04 + (unsigned int)apSrcAddr * 16, f04 + f08 * 16 - i * 16, i);
    f08 -= aiCount;
}

struct FUN_009f3850_shell
{
    void __thiscall SandBoxChoiceListItem_SaveGame(BGSSaveFormBuffer*);
};

// Serializes sandbox state, target references and procedure entries into the save buffer.
// @fnv 0x009f5a60
void __thiscall SandBoxActorPackageData::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int i;
    int iprevTargetDelta3;
    unsigned int isaveGameCount_2;
    SandboxProcedureData* potentialTarget;

    apSaveGameBuffer->SaveData(static_cast<void*>(&eState), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&eProcedure), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_fProcedureTime), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_fLastProcedureCheckHour), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_fNextProcedureCheckHour), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_uiLastProcedureCheckDay), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_fProcedureTime), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_uiProcedureIndex), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_bNeedsSandboxUpdate), 1, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_bHasFoodMarker), 1, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_bHasChairMarker), 1, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_bHasBedMarker), 1, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_iSerializedValue), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_ucProcedureIndex), 1, 0);

    iprevTargetDelta3 =
        g_timeGlobal.GetTimeStamp() - m_uiActivityStartDay;

    apSaveGameBuffer->SaveData(&iprevTargetDelta3, 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_uiActivityEndDay), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_fActivityStartHour), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_fActivityEndHour), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_eSandboxActivity), 4, 0);
    apSaveGameBuffer->SaveData(static_cast<void*>(&m_ucProcedureFlags), 6, 0);

    apSaveGameBuffer->SerializeFormData(pLocation, 0);
    apSaveGameBuffer->SerializeFormData(m_pCurrentTarget, 0);
    apSaveGameBuffer->SerializeFormData(m_pCurrentFurniture, 0);

    isaveGameCount_2 =
        &m_kProcedureList
            ? m_kProcedureList.GetSize()
            : 0;

    static_cast<BGSSaveGameBuffer*>(apSaveGameBuffer)->SaveVariableSizedValue(isaveGameCount_2);

    for (i = 0; i < isaveGameCount_2; ++i)
    {
        potentialTarget = &m_kProcedureList.GetAt(i);
        reinterpret_cast<FUN_009f3850_shell*>(potentialTarget)->SandBoxChoiceListItem_SaveGame(apSaveGameBuffer);
    }
}

struct ActionSource
{
    NiPoint3* __thiscall FUN_00439e90();
};
struct ObjectPart
{
    ActionSource* __thiscall FUN_005c3420(NiPoint3*, NiPoint3*, NiPoint3*);
    void* __thiscall FUN_006dd4f0();
};
struct Object
{
    float __thiscall GetFieldB4Float();
    float __thiscall GetFloatAtOffsetB0();
    ObjectPart* __thiscall GetOffsetC();
};
struct ElevationProvider
{
    bool __thiscall TESObjectCELL_GetLandHeight(NiPoint3*, float*);
};
extern bool __cdecl Pathing_FindClosePointViaNavMesh(Object*, NiPoint3*);
extern float __cdecl RandomFloatTwoPi();
extern float __cdecl FUN_00476b70(float, float);
extern float __cdecl FUN_004e44d0(float);
extern float __cdecl cosf_004e4490(float);
// Computes a position from the object's parts and elevation provider, writing it into result and overriding z with the provider's height.
// @fnv 0x006d33c0
void __cdecl GetObjectPosition(Object* object, NiPoint3* result)
{
    if (Pathing_FindClosePointViaNavMesh(object, result))
        return;
    float a = RandomFloatTwoPi();
    float g;
    float b = FUN_00476b70(object->GetFloatAtOffsetB0(), object->GetFieldB4Float());
    float f[sizeof(NiPoint3) / sizeof(float)];
    reinterpret_cast<NiPoint3*>(f)->SetComponents(cosf_004e4490(a) * b, FUN_004e44d0(a) * b, 0.0f);
    float c[sizeof(NiPoint3) / sizeof(float)];
    float e[sizeof(NiPoint3) / sizeof(float)];
    memcpy(result, object->GetOffsetC()->FUN_005c3420(reinterpret_cast<NiPoint3*>(c), reinterpret_cast<NiPoint3*>(e),
                                                 reinterpret_cast<NiPoint3*>(f))->FUN_00439e90(), sizeof(NiPoint3));
    ElevationProvider* d = static_cast<ElevationProvider*>(object->GetOffsetC()->FUN_006dd4f0());
    if (!d)
        return;
    if (!d->TESObjectCELL_GetLandHeight(result, &g))
        return;
    result->z = g;
}

struct FalloffPair
{
    float first;
    float second;
    void __thiscall FUN_006815c0();
};

struct FalloffController
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    bool active;
    unsigned char state29;
    unsigned short state2a;
    float startTime;
    float firstDuration;
    float secondDuration;
    float firstStrength;
    float secondStrength;
    float firstRate;
    float secondRate;
    float firstOutput;
    float secondOutput;

    void __thiscall UpdateFalloff(float currentTime);
};

float __cdecl FUN_004e44d0(float value);
void __cdecl ImageSpaceShaderMenuUnpack_SetOffset(float first, float second);

// @fnv 0x007f7970
void __thiscall FalloffController::UpdateFalloff(float currentTime)
{
    float elapsed = currentTime - startTime;
    if (elapsed > firstDuration && elapsed > secondDuration)
    {
        active = false;
        ImageSpaceShaderMenuUnpack_SetOffset(0.0f, 0.0f);
    }
    else
    {
        FalloffPair falloffPair;
        falloffPair.FUN_006815c0();
        falloffPair.first = 1.0f - elapsed / firstDuration;
        falloffPair.second = 1.0f - elapsed / secondDuration;
        firstOutput = FUN_004e44d0(elapsed * firstRate) * firstStrength * falloffPair.first;
        secondOutput = FUN_004e44d0(elapsed * secondRate) * secondStrength * falloffPair.second;
    }
}

// CheckTimerState: __thiscall, one out-param (unsigned char*), returns bool
struct SandboxTimerGlobal
{
    int GetCount();
    float GetLimit();
};
extern SandboxTimerGlobal g_sandboxTimerGlobal;

extern const double DAT_010356d8;

// @fnv 0x009f3c90
bool SandBoxActorPackageData::HasActivityEnded(bool* pucOut)
{
    float count;
    unsigned int ratio;
    ratio = (unsigned int)g_sandboxTimerGlobal.GetCount();
    count = g_sandboxTimerGlobal.GetLimit();
    unsigned char rem = 0;
    if (m_eSandboxActivity == -1)
    {
        return true;
    }
    unsigned int k = m_uiActivityEndDay;
    float lim = m_fActivityStartHour + m_fActivityEndHour;
    while (lim >= DAT_010356d8)
    {
        lim -= DAT_010356d8;
        k++;
    }
    if (ratio == k)
    {
        if (count < lim)
        {
            return false;
        }
        rem = 1;
    }
    else if (ratio < k)
    {
        return false;
    }
    if (pucOut != 0)
    {
        *reinterpret_cast<unsigned char*>(pucOut) = rem;
    }
    return true;
}

// @fnv 0x009f4600
bool __fastcall IsSandboxFlag2Clear(TESPackage* package)
{
    return (*reinterpret_cast<unsigned short*>(&package->specificFlags) & 2) ? false : true;
}

// @fnv 0x009f5690
unsigned char __fastcall IsSandboxFlag20Clear(TESPackage* package)
{
    return (unsigned char)((*reinterpret_cast<unsigned short*>(&package->specificFlags) & 0x20) == 0);
}

// Missing nonvirtual package APIs use ECX and have no stack arguments.
int __fastcall GetSandboxActionRefHandle(TESPackage* package);
TESObjectREFR* __fastcall GetSandboxTargetRef(TESPackage* package);

// @fnv 0x009f3af0
void SandboxPackageOperations::InitializeLocation(Actor* apActor, TESPackage* apPackage)
{
    switch (GetSandboxActionRefHandle(apPackage))
    {
    case 0:
        pLocation = GetSandboxTargetRef(apPackage);
        break;
    case 4:
    case 5: {
        BaseProcess* pProcess = apActor->GetProcess();
        if (pProcess)
            pLocation = pProcess->GetActiveCombatTarget();
        break;
    }
    case 6:
        pLocation = apActor->GetLinkedRef();
        break;
    default:
        pLocation = 0;
        break;
    }
    if (pLocation && static_cast<ExtraDataListHelper*>(pLocation->GetExtraData())->GetLinkedRef())
    {
        m_uiLastProcedureCheckDay = 0;
        RegionPoint* pPatrol = pLocation->GetExtraData()->GetStartingPositionData();
        if (pPatrol)
            m_uiLastProcedureCheckDay = g_timeGlobal.GetTimeStamp() + (unsigned int)(pPatrol->GetX() * 1000.0);
    }
}

void __cdecl GetSettingPairValues(int activity, float* start, float* duration);
// Picks the next sandbox activity by comparing each activity's start window against the current day, storing the chosen activity, hour, day and duration.
// @fnv 0x009f3e80
void SandboxPackageOperations::SelectActivity()
{
    bool start = false;
    if (!HasActivityEnded(&start))
        return;
    float endedToday;
    unsigned int bestDuration = g_calendar.GetDaysPassed();
    endedToday = g_calendar.GetGameTime();
    float bestActivity = 3.402823466e+38F;
    float currentHour = 3.402823466e+38F;
    int currentDay;
    float bestDay = 3.402823466e+38F;
    float found = 3.402823466e+38F;
    float bestStart = 3.402823466e+38F;
    currentDay = -2;
    unsigned int duration = 0;
    bool bestDifference = false;
    for (int activity = 0; activity < 4; ++activity)
    {
        GetSettingPairValues(activity, &found, &bestStart);
        bool alreadyStarted;
        bool tomorrow;
        alreadyStarted = endedToday >= found + bestStart;
        if (start && !alreadyStarted && activity == m_eSandboxActivity)
            continue;
        {
            float nextStart = alreadyStarted ? found + 24.0 : found;
            float difference = nextStart - endedToday;
            tomorrow = difference <= 0.0;
            if (tomorrow || difference < bestActivity)
            {
                bestActivity = difference;
                currentDay = activity;
                currentHour = found;
                duration = alreadyStarted ? bestDuration + 1 : bestDuration;
                bestDay = bestStart;
                bestDifference = true;
                if (tomorrow)
                    break;
            }
        }
    }
    if (bestDifference)
    {
        m_eSandboxActivity = (SANDBOX_ACTIVITY)currentDay;
        m_fActivityStartHour = currentHour;
        m_uiActivityEndDay = duration;
        m_fActivityEndHour = bestDay;
    }
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting255;
struct SandboxTarget
{
    TESObjectREFRHelper* pRef;
    int eProcedure;
    int iBase;
    int iScore;
    SandboxTarget(TESObjectREFRHelper* apRef, int aeProc, int aiBase);
};
struct SandboxTargetArray
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiUnk0C;
    void Clear(bool abFree);
    unsigned int Append(const SandboxTarget& arItem);
};
struct SandboxScanContext
{
    Actor* pActor;
    SandboxPackageOperations* pData;
    SandboxScanContext(Actor* apActor, SandboxPackageOperations* apData);
};
typedef bool(__cdecl* SandboxScanFunc)(TESObjectREFR*, void*);
bool __cdecl SandboxScanCallback(TESObjectREFR* apRef, void* apContext);
class SbDataHandler
{
  public:
    void ForEachRefInRange(TESObjectCELL* apCell, NiPoint3* apPos1, float afRadius1, NiPoint3* apPos2, float afRadius2,
                           SandboxScanFunc apFunc, void* apContext);
};

// Clears the target array and flags, then scans refs in range around the package or location position and appends food and bed targets.
// @fnv 0x009f54d0
void SandboxPackageOperations::ScanSandboxTargets(Actor* apActor)
{
    reinterpret_cast<SandboxTargetArray*>(&m_kProcedureList)->Clear(true);
    m_bHasBedMarker = false;
    m_bHasChairMarker = false;
    m_bHasFoodMarker = false;
    float fRadius = *originalRuntimeFloatSetting255.Float();
    TESObjectCELL* pCell = apActor->GetParentCell();
    NiPoint3 kPos7 = *static_cast<const TESObjectREFR*>(apActor)->GetPos();
    TESPackage* pPackage9 = reinterpret_cast<TESPackage*>(apActor->GetCurrentPackage());
    if (pPackage9)
    {
        kPos7 = pPackage9->GetPackageLocationPosition(apActor);
        int iRadius4 = pPackage9->FUN_00676280(apActor);
        fRadius = (iRadius4 > 0) ? (float)iRadius4 : fRadius;
    }
    if (pLocation)
    {
        kPos7 = *static_cast<const TESObjectREFR*>(pLocation)->GetPos();
        pCell = pLocation->GetParentCell();
    }
    SandboxScanContext kContext(apActor, this);
    ((SbDataHandler*)g_dataHandler)
        ->ForEachRefInRange(pCell, &kPos7, fRadius, &kPos7, fRadius, SandboxScanCallback, &kContext);
    if (IsSandboxFlag1Clear(pPackage9))
    {
        TESObjectREFR* pUsed = static_cast<SandboxActorUsedReference*>(apActor)->GetUsedRef();
        if (pUsed && pUsed->GetFlags())
        {
            reinterpret_cast<SandboxTargetArray*>(&m_kProcedureList)->Append(SandboxTarget(0, 2, 1));
            m_bHasFoodMarker = true;
        }
    }
    if (IsSandboxFlag20Clear(pPackage9))
    {
        reinterpret_cast<SandboxTargetArray*>(&m_kProcedureList)->Append(SandboxTarget(0, 3, 1));
    }
}

extern double DAT_01012638;
int __cdecl FUN_00ec7d40(int);

// @fnv 0x009f41f0
float __thiscall SandBoxActorPackageData::GetHourDifference(float f1, float f2)
{
    char cA;
    char c2;
    char cG;
    char cK;
    char cW;
    char c6;
    float fres;

    cA = (char)f1;
    c2 = (char)((f1 - cA) * DAT_01012638);
    cG = (char)(((f1 - cA) * DAT_01012638 - (float)c2) * DAT_01012638);
    cK = (char)f2;
    cW = (char)((f2 - cA) * DAT_01012638);
    c6 = (char)(((f2 - cA) * DAT_01012638 - (float)c2) * DAT_01012638);
    fres = (float)FUN_00ec7d40((int)cK - (int)cA);
    if (cW > c2)
    {
        fres += (int)cW - (int)c2;
    }
    else
    {
        fres -= (int)c2 - (int)cW;
    }
    return fres;
}

struct ChoiceTargetRef;
struct ChoiceBaseForm;
struct ChoiceFurniture;
struct ChoiceTargetRef
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActorSlot();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual bool CanActivateSlot(int);
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void* GetFurnitureSlot();
    bool FUN_00440d80();
    bool TESForm_GetTemporary();
    bool FUN_00440da0();
    bool Actor_CanChildUseObject(ChoiceTargetRef*);
    bool TESObjectREFR_GetIgnoredBySandbox();
    ChoiceBaseForm* BGSSaveFormBuffer_GetForm();
    TESPackage* FUN_009344a0();
    void* TESObjectREFR_GetOwner();
    bool TESObjectREFR_IsAnOwner(ChoiceTargetRef*, int);
};
struct ChoiceMarkerData
{
    unsigned GetByte5();
    unsigned FUN_00479e80();
    bool BGSIdleCollection_HasIdleForActor(ChoiceTargetRef*, ChoiceTargetRef*);
};
struct ChoiceBaseForm
{
    unsigned unknown00;
    unsigned unknown04;
    unsigned unknown08;
    unsigned unknown0c;
    unsigned unknown10;
    unsigned unknown14;
    unsigned unknown18;
    unsigned unknown1c;
    unsigned unknown20;
    unsigned unknown24;
    unsigned unknown28;
    unsigned unknown2c;
    ChoiceMarkerData markers;
    unsigned FUN_00401170();
    bool FUN_00509420();
    bool FUN_005093f0();
};
struct ChoiceFurniture
{
    void* BSFurnitureMarker_QNumMarks();
};
ChoiceFurniture* __cdecl BSFurnitureMarker_Find(void*);
struct ChoiceCollection
{
    unsigned AppendElement(const FUN_009f3800&);
};
struct ChoiceContext
{
    SandboxPackageOperations* FUN_00726070();
    ChoiceTargetRef* Modelloader_GetReferencedThis();
};
extern ChoiceTargetRef* DAT_011dea3c;
// Validates the target and actor, then adds a planner choice based on the target's form type and permission checks; always returns false.
// @fnv 0x009f5070
bool __cdecl AddActivationChoice(ChoiceTargetRef* target, ChoiceContext* pContext)
{
    ChoiceContext* context = pContext;
    SandboxPackageOperations* planner = context->FUN_00726070();
    ChoiceTargetRef* actor = context->Modelloader_GetReferencedThis();
    if (!planner)
        return false;
    if (!actor || !actor->BGSSaveFormBuffer_GetForm())
        return false;
    if (!target || target->FUN_00440d80() || target->TESForm_GetTemporary() || target->FUN_00440da0() ||
        (actor->CanActivateSlot(0) && !actor->Actor_CanChildUseObject(target)))
        return false;
    TESPackage* permissions = actor->FUN_009344a0();
    if (!permissions)
        return false;
    if (target->TESObjectREFR_GetIgnoredBySandbox())
        return false;
    switch (target->BGSSaveFormBuffer_GetForm()->FUN_00401170())
    {
    case 48:
        if (IsSandboxFlag8Clear(permissions) && (!target->TESObjectREFR_GetOwner() || target->TESObjectREFR_IsAnOwner(actor, 1)))
        {
            ChoiceBaseForm* markerBase = target->BGSSaveFormBuffer_GetForm();
            unsigned markerCount2 = markerBase->markers.GetByte5();
            unsigned markerFlags = markerBase->markers.FUN_00479e80();
            bool markerUsed = false;
            if (markerBase->markers.BGSIdleCollection_HasIdleForActor(actor, target))
                reinterpret_cast<ChoiceCollection*>(&planner->m_kProcedureList)->AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 4, 1));
        }
        break;
    case 42:
    case 43:
        if (permissions->IsFlag4Clear() && target->IsActorSlot() && target != DAT_011dea3c && target != actor)
            reinterpret_cast<ChoiceCollection*>(&planner->m_kProcedureList)->AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 5, 1));
        break;
    case 39: {
        void* object8 = target->GetFurnitureSlot();
        if (!object8)
            return false;
        ChoiceFurniture* furniture = BSFurnitureMarker_Find(object8);
        if (!furniture)
            return false;
        void* data = furniture->BSFurnitureMarker_QNumMarks();
        if (!data)
            return false;
        ChoiceBaseForm* furnitureBase2 = target->BGSSaveFormBuffer_GetForm();
        if (IsSandboxFlag2Clear(permissions) && furnitureBase2->FUN_00509420() &&
            (!target->TESObjectREFR_GetOwner() || target->TESObjectREFR_IsAnOwner(actor, 1)))
        {
            reinterpret_cast<ChoiceCollection*>(&planner->m_kProcedureList)->AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 1, 1));
            planner->m_bHasBedMarker = true;
        }
        else if (IsSandboxFlag10Clear(permissions) && furnitureBase2->FUN_005093f0() &&
                 (!target->TESObjectREFR_GetOwner() || target->TESObjectREFR_IsAnOwner(actor, 1)))
        {
            reinterpret_cast<ChoiceCollection*>(&planner->m_kProcedureList)->AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 0, 1));
            planner->m_bHasChairMarker = true;
        }
        else if (IsSandboxFlag10Clear(permissions) && !furnitureBase2->FUN_005093f0() && !furnitureBase2->FUN_00509420() &&
                 (!target->TESObjectREFR_GetOwner() || target->TESObjectREFR_IsAnOwner(actor, 1)))
        {
            reinterpret_cast<ChoiceCollection*>(&planner->m_kProcedureList)->AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 0, 1));
            planner->m_bHasChairMarker = true;
        }
        break;
    }
    case 29:
    case 47:
        if (IsSandboxFlag1Clear(permissions) && (!target->TESObjectREFR_GetOwner() || target->TESObjectREFR_IsAnOwner(actor, 1)))
        {
            reinterpret_cast<ChoiceCollection*>(&planner->m_kProcedureList)->AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 2, 1));
            planner->m_bHasFoodMarker = true;
        }
        break;
    }
    return false;
}

// Releases the current target and clears the procedure list before member destruction.
// @fnv 0x009f3a70
SandBoxActorPackageData::~SandBoxActorPackageData()
{
    static_cast<SandboxPackageOperations*>(this)->ResetReference();
    m_kProcedureList.Clear(true);
}

