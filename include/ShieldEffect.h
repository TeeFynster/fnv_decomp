#pragma once

#include "ValueModifierEffect.h"

class ShieldEffect : public ValueModifierEffect
{
public:
    virtual ActiveEffect* Copy() override;
    virtual void Update(float delta) override;
    virtual unsigned short GetSaveSize(Actor* actor) override;
    virtual void SaveGame(Actor* actor) override;
    virtual void LoadGame(Actor* actor) override;
    virtual void CopyData(ActiveEffect* other) override;
    virtual void Start() override;
    virtual void Finish() override;

    unsigned int m_uiUnknownValue;

    ShieldEffect(void*, void*, void*);
    void ApplyActorValueModifier(Actor* actor, float magnitude);
};
