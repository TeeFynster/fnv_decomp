#include "../../../include/ShieldEffect.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/EffectItem.h"
#include "../../../include/Actor.h"
#include "../../../include/TESSaveLoadGame.h"

// src/fallout/magic/shieldeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/shieldeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00828050
void ShieldEffect::CopyData(ActiveEffect* apDestination)
{
    ValueModifierEffect::CopyData(apDestination);
    ShieldEffect* pvme = dynamic_cast<ShieldEffect*>(apDestination);
    if (pvme)
        pvme->m_uiUnknownValue = m_uiUnknownValue;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

// Adds four bytes to the base save size for save versions of at least 0x6E.
// @fnv 0x008283a0
unsigned short ShieldEffect::GetSaveSize(Actor* apActor)
{
    unsigned short isize = 0;
    isize += ValueModifierEffect::FUN_00802d90(apActor);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6E)
        isize += 4;
    return isize;
}

// @fnv 0x008283f0
void ShieldEffect::SaveGame(Actor* actor)
{
    ValueModifierEffect::FUN_00802db0(actor);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6e)
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_uiUnknownValue, 4);
}

// @fnv 0x00828430
void ShieldEffect::LoadGame(Actor* pEffect)
{
    ValueModifierEffect::FUN_00802dd0(pEffect);
    if ((unsigned char)g_TESSaveLoadGame->FUN_008df040() >= 0x6e)
        g_TESSaveLoadGame->ReadTypedData(&m_uiUnknownValue, 4);
}

extern double gModifierZero;
// @fnv 0x008281b0
void ShieldEffect::Update(float dt)
{
    ValueModifierEffect::Update(dt);
    if (!pEffect->GetEffectSetting()->IsFlagSet(2))
    {
        Actor* actor =
            ActiveEffect::FUN_0059bb30() ? ActiveEffect::FUN_0059bb30()->GetOwnerActor() : 0;
        if (fDuration > gModifierZero || m_eSpellType == 4)
            ApplyActorValueModifier(actor, m_fElapsedTime * dt);
    }
}

void* __cdecl operator new(unsigned int);

// Allocates and constructs a ShieldEffect with the three given arguments, returning it as a ShieldEffect pointer.
// @fnv 0x008280a0
ShieldEffect* CreateShieldEffect(unsigned int auiArg1, unsigned int auiArg2, unsigned int auiArg3)
{
    return new ShieldEffect((void*)auiArg1, (void*)auiArg2, (void*)auiArg3);
}

extern unsigned int _data_011c16bc;

// @fnv 0x00827fa0
ActiveEffect* ShieldEffect::Copy()
{
    ShieldEffect* pNewEffect = new ShieldEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(pNewEffect);
    return pNewEffect;
}

// @fnv 0x00827f20
ShieldEffect::ShieldEffect(void* a, void* b, void* apItem) : ValueModifierEffect(a, b, apItem)
{
    ValueModifierEffect::SetActorValue((ActorValue::Index)((EffectItem*)apItem)->GetAffectedActorValue());
}

// Starts the modifier and applies its initial magnitude when required.
// @fnv 0x00828120
void ShieldEffect::Start()
{
    Actor* actor;
    ValueModifierEffect::Start();
    if (this->pEffect->GetEffectSetting()->IsFlagSet(2) || this->fDuration == gModifierZero)
    {
        actor = (ActiveEffect::FUN_0059bb30() != 0)
                    ? ActiveEffect::FUN_0059bb30()->FUN_00822b40()
                    : 0;
        ApplyActorValueModifier(actor, this->m_fElapsedTime);
    }
}

// @fnv 0x008282e0
void ShieldEffect::ApplyActorValueModifier(Actor* pkTarget, float m_fElapsedTime)
{
    if (!pkTarget || ValueModifierEffect::GetActorValue() == 0x4d)
        return;

    if (m_eSpellType == 4)
        // Actor.h exposes slot 0x3B4 as Unk_ED() without its actor-value arguments.
        ((void (__thiscall *)(Actor*, ActorValue::Index, float))(*(void***)pkTarget)[0x3B4 / 4])(
            pkTarget, ValueModifierEffect::GetActorValue(), m_fElapsedTime);
    else if (pEffect->GetEffectSetting()->IsFlagSet(2))
        pkTarget->ModActorValue(ValueModifierEffect::GetActorValue(), m_fElapsedTime, 0);
    else
        pkTarget->DamageActorValue(ValueModifierEffect::GetActorValue(), m_fElapsedTime, 0);
}

// @fnv 0x00828260
void ShieldEffect::Finish()
{
    ValueModifierEffect::ApplyEffect();
    if (pEffect->GetEffectSetting()->IsFlagSet(2))
    {
        Actor* actor = ActiveEffect::FUN_0059bb30() ? ActiveEffect::FUN_0059bb30()->FUN_00822b40() : 0;
        ApplyActorValueModifier(actor, -m_fElapsedTime);
    }
}
