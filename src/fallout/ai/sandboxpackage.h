// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/sandboxpackage.cpp
//
// Unit-local procedure, calendar and reference helpers. Package and load-buffer
// layouts come from the checked shared headers.
#ifndef FNV_SANDBOXPACKAGE_H
#define FNV_SANDBOXPACKAGE_H


#include "../../../include/Actor.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESGlobal.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/ENUM_FORM_ID.h"

#ifndef FNV_STATIC_ASSERT
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#endif

#include "../../../include/ActorPackageData.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/SandBoxActorPackageData.h"

// Nonvirtual APIs absent from the shared Actor declarations.
class SandboxActorEnergySource : public Actor
{
public:
    void* Actor_GetActorBaseEnergyLevel();
};

class SandboxActorUsedReference : public Actor
{
public:
    TESObjectREFR* GetUsedRef();
};

// Methods not yet declared by the shared class use its checked layout.

class SandboxPackageOperations : public SandBoxActorPackageData
{
public:
    bool IsObjectWithinLocationRadius(MobileObject*, float);
    void ResetReference();
    void BeginGettingUp();
    void ClearTargetReferences(void*, void*);
    void SelectActivity();
    void SelectSandboxActivity(Actor*, TESPackage*);
    void ScanSandboxTargets(Actor*);
    void InitializeLocation(Actor*, TESPackage*);
};

#ifndef NULL
#define NULL 0
#endif

#include "../../../include/SANDBOX_PROCEDURE.h"
#include "../../../include/SANDBOX_ACTIVITY.h"
#pragma pack(push, 4)
class SandboxProcedureData
{
  public:
    TESObjectREFR* pTarget;        // +0x0, 4 bytes
    SANDBOX_PROCEDURE eProcedure;  // +0x4, 4 bytes
    int m_iActivityState;          // +0x8, 4 bytes
    int m_iProcedureData;          // +0xC, 4 bytes
    // Unit-local out-of-line declarations (owned by other units except
    // SandboxProcedureData::LoadGame/InitLoadGame targets as noted).
    TESObjectREFR* GetTarget();
    SANDBOX_PROCEDURE GetProcedure();
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SandboxProcedureData) == 16);
FNV_STATIC_ASSERT(offsetof(SandboxProcedureData, pTarget) == 0);
FNV_STATIC_ASSERT(offsetof(SandboxProcedureData, eProcedure) == 4);
FNV_STATIC_ASSERT(offsetof(SandboxProcedureData, m_iActivityState) == 8);
FNV_STATIC_ASSERT(offsetof(SandboxProcedureData, m_iProcedureData) == 12);

#pragma pack(push, 4)
class Calendar
{
  public:
    TESGlobal* m_pYearGlobal;            // +0x0, 4 bytes
    TESGlobal* m_pMonthGlobal;           // +0x4, 4 bytes
    TESGlobal* m_pDayGlobal;             // +0x8, 4 bytes
    TESGlobal* m_pHourGlobal;            // +0xC, 4 bytes
    TESGlobal* m_pGameDaysPassedGlobal;  // +0x10, 4 bytes
    TESGlobal* pHourGlobal;              // +0x14, 4 bytes
    unsigned int m_uiDaysPassed;         // +0x18, 4 bytes
    // Unit-local out-of-line declarations.
    unsigned int GetDaysPassed();
    float GetGameTime();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Calendar) == 28);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pYearGlobal) == 0);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pMonthGlobal) == 4);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pDayGlobal) == 8);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pHourGlobal) == 12);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pGameDaysPassedGlobal) == 16);
FNV_STATIC_ASSERT(offsetof(Calendar, pHourGlobal) == 20);
FNV_STATIC_ASSERT(offsetof(Calendar, m_uiDaysPassed) == 24);
extern Calendar g_calendar;

// Community-evidenced global timer (JIP LN NVSE GameData.h Timer/TimeGlobal,
// millisecond getter at 0x825C00.
class TimeGlobal
{
  public:
    unsigned char disableCounter;  // +0x0
    unsigned char pad01[3];
    float fpsClamp;           // +0x4
    float fpsClampRemainder;  // +0x8
    float secondsPassed;      // +0xC
    float lastSecondsPassed;  // +0x10
    unsigned int msPassed;    // +0x14
    unsigned int tickCount;   // +0x18
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;


// Minimal region-point declaration (GetX binding ?GetX@RegionPoint@@QAEMXZ).
class RegionPoint
{
  public:
    float GetX();
};

// Other-unit-owned ExtraDataList/TESObjectREFR out-of-line helpers reached
// through subclass casts (no layout change, no bytes).
class ExtraDataListHelper : public ExtraDataList
{
  public:
    TESObjectREFR* GetLinkedRef();
};
class TESObjectREFRHelper : public TESObjectREFR
{
  public:
    void SetTargetingState(bool abTargeted);
    void SetMarkerState(unsigned char abMarker, bool abReserved);
    bool IsMarkerAvailable(unsigned char abMarker, bool abFlag);
};

class SandboxTargetInfo
{
  public:
    bool CheckFoodMarker();
    bool CheckBedMarker();
    bool CheckChairMarker();
};
class ActorTargetSource
{
  public:
    SandboxTargetInfo* GetProcessTarget();
};

// Other-unit-owned free helpers.
TESForm* GetFormByID(unsigned int auFormID);
bool IsValidSandboxProcedure(int aiProcedure);

// Activity -> procedure table at 0x11A5F3C.
extern SANDBOX_PROCEDURE g_procedureForActivity[4];

#endif
