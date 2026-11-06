#pragma once

#include "ValueModifierEffect.h"

class ValueAndConditionsEffect : public ValueModifierEffect
{
public:
    ValueAndConditionsEffect(void*, void*, void*);

    virtual ActiveEffect* Copy() override;
    virtual void CopyData(ActiveEffect* other) override;
    virtual void ApplyActorValueModifier(Actor* actor, float modifier, ActorValue::Index index) override;

    ActorValue::Index m_eModifiedActorValue;

    void LoadGame(void* buffer);
};
