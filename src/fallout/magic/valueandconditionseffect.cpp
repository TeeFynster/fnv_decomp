// src/fallout/magic/valueandconditionseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/valueandconditionseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/ActorValue.h"
#include "../../../include/Setting.h"
#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/ValueAndConditionsEffect.h"

extern TESSaveLoadGame* g_TESSaveLoadGame;

// @fnv 0x0082b780
void ValueAndConditionsEffect::LoadGame(void* buffer)
{
    ActiveEffect::LoadGame(buffer);
    g_TESSaveLoadGame->ReadTypedData(&m_eActorValue, 1);
}

// @fnv 0x0082b7b0
ValueAndConditionsEffect::ValueAndConditionsEffect(void* a, void* b, void* c) : ValueModifierEffect(a, b, c)
{
    m_eModifiedActorValue = ActorValue::ActorValue__Index_VALUE_NONE;
}

extern Setting originalRuntimeFloatSetting1213;
extern Setting originalRuntimeFloatSetting1214;

// Applies the modifier to the stored actor value (or none) and, scaled by a runtime setting, to ActorValue__Index_VALUE_NONE or actor values 25-31.
// @fnv 0x0082b970
void ValueAndConditionsEffect::ApplyActorValueModifier(Actor* actor, float modifier, ActorValue::Index index)
{
    if (m_eModifiedActorValue != ActorValue::ActorValue__Index_VALUE_NONE)
    {
        float fScaledMagnitude = modifier * originalRuntimeFloatSetting1213.Float()[0];
        ValueModifierEffect::ApplyActorValueModifier(actor, modifier, m_eModifiedActorValue);
        ValueModifierEffect::ApplyActorValueModifier(actor, fScaledMagnitude, ActorValue::ActorValue__Index_VALUE_NONE);
    }
    else
    {
        ValueModifierEffect::ApplyActorValueModifier(actor, modifier, ActorValue::ActorValue__Index_VALUE_NONE);
        float fScaledMagnitude = modifier * originalRuntimeFloatSetting1214.Float()[0];
        for (int i = 25; i < 32; ++i)
            ValueModifierEffect::ApplyActorValueModifier(actor, fScaledMagnitude, (ActorValue::Index)i);
    }
}

extern int DAT_011a13d0;
extern int DAT_011a0d1c;
void* __cdecl CreateSpawnedRecord(void* p, int a2, void* a3, void* a4, int a5);

// @fnv 0x0082b8a0
void ValueAndConditionsEffect::CopyData(ActiveEffect* other)
{
    ValueModifierEffect::CopyData(other);
    ValueAndConditionsEffect* copy = (ValueAndConditionsEffect*)CreateSpawnedRecord(other, 0, &DAT_011a0d1c, &DAT_011a13d0, 0);
    if (copy != 0)
        copy->m_eModifiedActorValue = m_eModifiedActorValue;
}

void* __cdecl operator new(unsigned int size);

// @fnv 0x0082b8f0
ValueAndConditionsEffect* CreateValueModifier(void* a, void* b, void* c)
{
    return new ValueAndConditionsEffect(a, b, c);
}

// @fnv 0x0082b7f0
ActiveEffect* ValueAndConditionsEffect::Copy()
{
    ValueAndConditionsEffect* effect = new ValueAndConditionsEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(effect);
    return effect;
}
