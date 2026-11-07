#pragma once

#include "AssociatedItemEffect.h"
#include "InventoryStackRecord.h"

class BoundItemEffect : public AssociatedItemEffect
{
public:
    BoundItemEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    virtual ~BoundItemEffect();

    virtual ActiveEffect* Copy();
    virtual void Update(float afElapsedSeconds);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual void InitLoadGame(Actor* apActor);
    virtual bool IsEffectValid(MagicTarget* apTarget);
    virtual void Start();
    virtual void Finish();

    bool __thiscall IsTargetCharacter(MagicTarget* apTarget);
    void DoSummon();

    InventoryStackRecord* m_pkWeaponEntry;
    InventoryStackRecord* m_apArmorEntries[20];
    float unka0;
    bool m_bModifierActive;
    bool m_bShowShader;
    bool m_bLoadWeaponModel;
    bool m_bLoadArmorModel;
    bool pending;
};
