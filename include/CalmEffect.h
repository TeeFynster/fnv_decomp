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

    CalmEffect* FUN_0080a930();
    bool FUN_0080a9e0(MagicCaster* caster);
    void FUN_0080aa90();
    void FUN_0080ab10(float value);
    void FUN_0080abf0();
    bool __thiscall FUN_0080ba50(MagicCaster*);
    bool __thiscall ClearCasterIfMatch(MagicCaster*);
};
