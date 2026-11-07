#pragma once

#include "ActiveEffect.h"

namespace ActorValue
{
    enum Index;
}

class ValueModifierEffect : public ActiveEffect
{
public:
    virtual ~ValueModifierEffect();
    virtual ActiveEffect* Copy();
    virtual void Finalize();
    virtual void Update(float delta);
    virtual void FinishLoadGameTES(Actor* actor);
    virtual bool CanFinish();
    virtual void CopyData(ActiveEffect* other);
    virtual bool IsEffectValid(MagicTarget* target);
    virtual void Start();
    virtual void Continue();
    virtual void Finish();
    virtual void SetActorValue(ActorValue::Index value);
    virtual ActorValue::Index GetActorValue();
    virtual void ApplyActorValueModifier(Actor* actor, float magnitude, ActorValue::Index value);

    ActorValue::Index m_eActorValue;

    ValueModifierEffect(void*, void*, void*);
    float GetModifiedMagnitude(float magnitude);
    void RefreshPlayerActorValue();
    void ApplyEffect();
    MagicTarget* FUN_0059bb30();
    unsigned short __thiscall FUN_00802d90(Actor* apActor);
    void FUN_00802db0(Actor* apActor);
    void FUN_00802dd0(Actor* apActor);
    void LimbConditionEffect_SaveGame(Actor* apActor);
    void __thiscall ValueModifierEffect_FinishInitLoadGame(Actor* apActor);
};
