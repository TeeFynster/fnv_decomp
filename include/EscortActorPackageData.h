#pragma once

#include "ActorPackageData.h"
#include "MagicTarget.h"

class Actor;
class TESPackage;
class TESEscortPackageData;

class EscortActorPackageData : public ActorPackageData
{
public:
    EscortActorPackageData();
    virtual ~EscortActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);

    void FUN_0067d920();
    void RegisterActor(Actor* apActor);
    void RemoveActorFromList(Actor* actor);
    int GetNumEscortedActorsOfType(Actor* apEscorter, void* apType);

    Actor* pActor;
    TESPackage* pPackage;
    const TESEscortPackageData* m_pEscortPackageData;
    BSSimpleList<Actor*> m_kActorList;
};
