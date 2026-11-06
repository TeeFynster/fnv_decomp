#pragma once
#include "SANDBOX_PROCEDURE.h"
#include "SANDBOX_ACTIVITY.h"

#include "ActorPackageData.h"
#include "BSSimpleArray.h"

class Actor;
class SandboxProcedureData;
class TESObjectREFR;

class SandBoxActorPackageData : public ActorPackageData
{
public:
    enum SANDBOX_STATE
    {
        SANDBOX_STATE_INIT = 0,
        SANDBOX_STATE_GETTING_UP = 1,
        SANDBOX_STATE_MOVING = 2,
        SANDBOX_STATE_DOINGSTUFF = 3,
        NUM_SANDBOX_STATES = 4
    };



    SandBoxActorPackageData();
    virtual ~SandBoxActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);

    bool IsLocationCheckDue();
    bool IsActivityTime();
    bool HasProcessTarget(Actor* apActor);
    bool HasActivityEnded(bool* apbEndedToday);
    bool IsActivityProcedure();
    float GetHourDifference(float afLastTime, float afNow);
    bool IsActorWithinLocationRadius(Actor* apActor, bool abFlag);

    SANDBOX_STATE eState;
    SANDBOX_PROCEDURE eProcedure;
    float m_fProcedureTime;
    TESObjectREFR* pLocation;
    float m_fLastProcedureCheckHour;
    float m_fNextProcedureCheckHour;
    unsigned int m_uiLastProcedureCheckDay;
    BSSimpleArray<SandboxProcedureData, 1024> m_kProcedureList;
    unsigned int m_uiProcedureIndex;
    bool m_bNeedsSandboxUpdate;
    bool m_bHasFoodMarker;
    bool m_bHasChairMarker;
    bool m_bHasBedMarker;
    int m_iSerializedValue;
    TESObjectREFR* m_pCurrentTarget;
    unsigned char m_ucProcedureIndex;
    unsigned char layoutPadding41[3];
    TESObjectREFR* m_pCurrentFurniture;
    unsigned int m_uiActivityStartDay;
    unsigned int m_uiActivityEndDay;
    float m_fActivityStartHour;
    float m_fActivityEndHour;
    SANDBOX_ACTIVITY m_eSandboxActivity;
    unsigned char m_ucProcedureFlags[NUM_SANDBOX_PROCEDURES];
    unsigned char layoutPadding62[2];
};
