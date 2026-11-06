#pragma once

#include "ActiveEffect.h"

class ConcussionEffect : public ActiveEffect
{
public:
    virtual ActiveEffect* Copy();
    virtual void Update(float deltaTime);
    virtual bool IsEffectValid(MagicTarget* target);

    float m_fPackageValue;

    ConcussionEffect(MagicCaster*, MagicItem*, EffectItem*);
    void ApplyConcussion(Actor* target);
};
