#pragma once

#include "ActiveEffect.h"

class TESForm;

class AssociatedItemEffect : public ActiveEffect
{
public:
    AssociatedItemEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    virtual ~AssociatedItemEffect();

    virtual ActiveEffect* Copy();
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual void InitLoadGame(Actor* apActor);
    virtual void CopyData(ActiveEffect* apOther);

    void __thiscall FUN_00806c20(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    void __thiscall FUN_00806de0(Actor* apActor);
    void FUN_00806e30(Actor* apActor);
    void __thiscall FUN_00806e70(Actor* apActor);

    TESForm* m_pAssociatedForm;
};
