#pragma once

#include "ActorPackageData.h"
#include "BSSimpleArray.h"

class Actor;
class TESPackage;
class NiPoint3;
class TESPatrolPackageData;

class PatrolActorPackageData : public ActorPackageData
{
public:
    enum PATROL_STATE
    {
        PATROL_STATE_INIT = 0,
        PATROL_STATE_TRAVELING_TO_NEXT_REF = 1,
        PATROL_STATE_AT_REF = 2,
        PATROL_STATE_DEBUG_ACTOR_DELETED = 3,
        PATROL_STATE_DEBUG_DESTRUCTED = 4
    };

    PatrolActorPackageData();
    virtual ~PatrolActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);

    bool Init(Actor* apActor, TESPackage* apPackage);
    bool AdvanceToNextReference(bool abApply);
    TESObjectREFR* GetCurrentPatrolReference();
    static TESObjectREFR* __cdecl GetPatrolReference(Actor* apActor, TESPackage* apPackage);
    bool IsPatrolling();
    void SetPatrolPosition(const NiPoint3& arPosition);
    bool SetPatrolRefIndex(unsigned int aiRefIndex);
    void SelectClosestPatrolPoint(const NiPoint3& arPoint);
    void SelectClosestPatrolPoint(void* apPoint);
    void PatrolActorPackageData_ClearReservedPatrolRef();

    PATROL_STATE eState; // 0x04
    float m_fElapsedWaitTime; // 0x08
    bool m_bPatrolFlag; // 0x0C
    unsigned char unk0D[3];
    Actor* pActor; // 0x10
    TESPackage* pPackage; // 0x14
    const TESPatrolPackageData* m_pEscortPackageData; // 0x18
    BSSimpleArray<TESObjectREFR*, 1024> References; // 0x1C
    bool m_bReferenceFlag; // 0x2C
    unsigned char unk2D[3];
    unsigned int m_uiValueAfterReferenceFlag; // 0x30
    unsigned int m_uiSecondValueAfterReferenceFlag; // 0x34
};
