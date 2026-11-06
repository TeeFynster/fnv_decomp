#pragma once

#include "ActiveEffect.h"

class VampirismEffect : public ActiveEffect
{
public:
    VampirismEffect(MagicCaster*, MagicItem*, EffectItem*);
    virtual ActiveEffect* Copy() override;
    virtual void InitLoadGame(Actor* apActor) override;
};
