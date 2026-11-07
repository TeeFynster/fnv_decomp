#pragma once

#include "ValueModifierEffect.h"

class LimbConditionEffect : public ValueModifierEffect
{
public:
    virtual ~LimbConditionEffect();
    virtual ActiveEffect* Copy();
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(Actor* apActor);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void CopyData(ActiveEffect* apOther);
    virtual void ApplyActorValueModifier(Actor* apActor, float afModifier, ActorValue::Index aeOverrideActorValue);

    LimbConditionEffect(void*, void*, void*);
    LimbConditionEffect* __thiscall LimbConditionEffect_0080f060(void*, void*, void*);
    unsigned short __thiscall FUN_0080f2b0(Actor* apActor);

    static ActiveEffect* Instantiate(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    void SetLimbIndex(int aiLimbIndex);

    int m_eModifiedActorValue;
};
