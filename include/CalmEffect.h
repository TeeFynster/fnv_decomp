#pragma once

#include "ValueModifierEffect.h"

class CalmEffect : public ValueModifierEffect
{
public:
    CalmEffect(void*, void*, void*);

    virtual ActiveEffect* Copy();
    virtual void Update(float delta);
    virtual bool IsEffectValid(MagicTarget* target);
    virtual void Start();
    virtual void Finish();

    CalmEffect* Copy_0080a930();
    bool CheckTarget_0080a9e0(MagicCaster* caster);
    void Start_0080aa90();
    void Update_0080ab10(float value);
    void Finish_0080abf0();
    bool __thiscall AbsorbEffect_CheckDeletedCaster(MagicCaster*);
    bool __thiscall ClearCasterIfMatch(MagicCaster*);
};
