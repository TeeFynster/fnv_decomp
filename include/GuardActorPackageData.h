#pragma once

#include "ActorPackageData.h"

class Actor;

class GuardActorPackageData : public ActorPackageData
{
public:
    enum GUARD_STATE
    {
        GUARD_STATE_INIT = 0,
        GUARD_STATE_IDLE = 1,
        GUARD_STATE_WAIT_TO_ATTACK = 2
    };

    GuardActorPackageData();
    virtual ~GuardActorPackageData();

    void* DestroyIfFlagged(unsigned int flags);

    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);

    GUARD_STATE eState;
    Actor* pWarningTarget;
    int iWarningCount;
    float m_fWarningTimer;
};
