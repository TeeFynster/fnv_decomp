#pragma once

#include "ActiveEffect.h"

class CureEffect : public ActiveEffect
{
public:
    virtual ~CureEffect();
    virtual ActiveEffect* Copy();
    virtual bool IsEffectValid(MagicTarget* apTarget);
    virtual void Start();

    int m_eSpellType;
    int m_iCureType;
};
