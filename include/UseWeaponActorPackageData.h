#pragma once

#include "ActorPackageData.h"

class TESObjectREFR;

class UseWeaponActorPackageData : public ActorPackageData
{
public:
    UseWeaponActorPackageData();
    virtual ~UseWeaponActorPackageData();
    void SetReferenceTarget(TESObjectREFR* reference) override;
    void LoadGame(BGSLoadFormBuffer* apBuffer) override;
    void InitLoadGame(BGSLoadFormBuffer* apBuffer) override;

    TESObjectREFR* m_pUseTarget;
};
