// src/fallout/magic/cureeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/cureeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/ActiveEffect.h"
#include "../../../include/BSThread.h"
#include "../../../include/CureEffect.h"
#include "../../../include/MagicTarget.h"

// Keep only the missing removal declarations here; the layout is shared.
class CureEffectTarget : public MagicTarget
{
public:
    void MagicTarget_Dispel(int);
    void RemoveEffectsByArchetype(int, int);
};

// The shared CureEffect header does not yet declare these constructors.
class CureEffectConstruction : public CureEffect
{
public:
    CureEffectConstruction(MagicCaster*, MagicItem*, EffectItem*, MagicSystem__SpellType);
    CureEffectConstruction(MagicCaster*, MagicItem*, EffectItem*, int);
};

// @fnv 0x0080d4b0
bool CureEffect::IsEffectValid(MagicTarget* apTarget)
{
    Actor* pActor = apTarget ? apTarget->GetOwnerActor() : 0;
    return pActor != 0;
}

// @fnv 0x0080c210
void CureEffect::Start()
{
    if (m_iCureType == -1)
        static_cast<CureEffectTarget*>(GetTarget())->MagicTarget_Dispel(m_eSpellType);
    else
        static_cast<CureEffectTarget*>(GetTarget())->RemoveEffectsByArchetype(m_iCureType, 0);
}

void* __cdecl operator new(unsigned int);

// @fnv 0x0080c0f0
ActiveEffect* CureEffect::Copy()
{
    ActiveEffect* pEffect = 0;

    if (m_iCureType == -1)
    {
        pEffect = new CureEffectConstruction(m_pEffectInstance, pSpell, this->pEffect, (MagicSystem__SpellType)m_eSpellType);
    }
    else
    {
        pEffect = new CureEffectConstruction(m_pEffectInstance, pSpell, this->pEffect, m_iCureType);
    }

    this->CopyData(pEffect);
    return pEffect;
}
