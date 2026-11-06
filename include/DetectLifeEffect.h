#pragma once

#include "ValueModifierEffect.h"

class DetectLifeEffect : public ValueModifierEffect
{
public:
    virtual ~DetectLifeEffect();
    virtual ActiveEffect* Copy();
    virtual void Start();
    virtual void Finish();

    DetectLifeEffect(MagicCaster*, MagicItem*, EffectItem*);
    void FUN_0080ce60();
    void FUN_0080d0e0();
};
