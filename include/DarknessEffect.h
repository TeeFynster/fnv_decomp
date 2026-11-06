#pragma once

#include "ValueModifierEffect.h"

class DarknessEffect : public ValueModifierEffect
{
public:
    DarknessEffect(void*, void*, void*);

    virtual ~DarknessEffect();
    virtual ActiveEffect* Copy();
    virtual void FinishLoadGameTES(Actor* actor);
    virtual void Revert(Actor* actor);
    virtual void Start();
    virtual void Finish();
};
