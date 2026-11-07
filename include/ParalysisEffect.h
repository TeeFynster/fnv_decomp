#pragma once

#include "ValueModifierEffect.h"

class TESObjectREFR;

class ParalysisEffect : public ValueModifierEffect
{
public:
    ParalysisEffect(void* caster, void* item, void* effect);

    virtual ActiveEffect* Copy();
    virtual void Update(float delta);
    virtual void FinishLoadGameTES(Actor* apActor);
    virtual void Revert(Actor* apActor);
    virtual void Start();
    virtual void Finish();

    void ApplyEffect();
    void UpdateParalysisEffect(float afElapsed);
    void Start_008263c0();
    void Finish_008264b0();
    void FinishInitLoadGame_00826550(Actor* apActor);
    void Revert_00826570(TESObjectREFR* actor);
};
