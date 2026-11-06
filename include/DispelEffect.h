#pragma once

#include "ActiveEffect.h"

class DispelEffect : public ActiveEffect
{
public:
    DispelEffect(MagicCaster*, MagicItem*, EffectItem*);

    virtual ActiveEffect* Copy() override;
    virtual void CopyData(ActiveEffect* apDestination) override;
    virtual bool IsEffectValid(MagicTarget* apTarget) override;
    virtual void Start() override;
};
