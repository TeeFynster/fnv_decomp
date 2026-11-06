#pragma once

#include "ValueModifierEffect.h"

class NightEyeEffect : public ValueModifierEffect
{
public:
    NightEyeEffect(void*, void*, void*);

    virtual ActiveEffect* Copy();
    virtual void Update(float delta);
    virtual void InitLoadGame(Actor* apActor);
    virtual void Revert(Actor* apActor);
    virtual void Start();
    virtual void Finish();

    void FUN_00825810();
    void FUN_00825860();
    void FUN_00825920(Actor* apActor);
};
