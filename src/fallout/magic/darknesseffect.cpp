#include "../../../include/Actor.h"
#include "../../../include/DarknessEffect.h"
#include "../../../include/InvisibilityEffect.h"
#include "../../../include/MagicTarget.h"

// src/fallout/magic/darknesseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/darknesseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Constructs a ValueModifierEffect subobject and sets its vtable pointer to DAT_01079d2c.
// @fnv 0x0080c460
DarknessEffect::DarknessEffect(void* apArg1, void* apArg2, void* apArg3)
    : ValueModifierEffect(apArg1, apArg2, apArg3)
{
}

void __cdecl BSShaderManager_RecursiveSetForcedDarkness(int, float);
// @fnv 0x0080c850
void DarknessEffect::Revert(Actor* apActor)
{
    reinterpret_cast<TESForm*>(this)->TESForm::Revert(reinterpret_cast<BGSLoadFormBuffer*>(apActor));
    if (apActor->GetReferenceType())
        BSShaderManager_RecursiveSetForcedDarkness(apActor->GetReferenceType(), 1.0F);
}

// Allocates and constructs a new DarknessEffect from the three given arguments and returns it.
// @fnv 0x0080c730
// src: COMMUNITY 0x0080c730
DarknessEffect* __cdecl DarknessEffect_Create(void* a, void* b, void* c)
{
    return new DarknessEffect(a, b, c);
}

// @fnv 0x0080c4c0
ActiveEffect* DarknessEffect::Copy()
{
    ActiveEffect* presult = new DarknessEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(presult);
    return presult;
}

double _DAT_01012060;
double g_d100;

// @fnv 0x0080c570
void DarknessEffect::Start()
{
    Actor* ptargetActor;
    float fnewDarkness;

    ptargetActor = ActiveEffect::FUN_0059bb30() ? ActiveEffect::FUN_0059bb30()->GetOwnerActor() : 0;

    ValueModifierEffect::Start();

    if (ptargetActor && ptargetActor->GetNiNode())
    {
        fnewDarkness = static_cast<float>(
            1.0 - ptargetActor->GetCurrentActorValue(m_eActorValue) / g_d100);

        if (fnewDarkness < _DAT_01012060)
            fnewDarkness = 0.0f;

        if (fnewDarkness > 1.0)
            fnewDarkness = 1.0f;

        BSShaderManager_RecursiveSetForcedDarkness(reinterpret_cast<int>(ptargetActor->GetNiNode()), fnewDarkness);
    }
}

// @fnv 0x0080c650
void DarknessEffect::Finish()
{
    ValueModifierEffect::ApplyEffect();

    Actor* ptargetActor = ActiveEffect::FUN_0059bb30() ? ActiveEffect::FUN_0059bb30()->GetOwnerActor() : 0;
    float fnewDarkness;

    if (ptargetActor && ptargetActor->GetNiNode())
    {
        fnewDarkness = 1.0 - ptargetActor->GetCurrentActorValue(m_eActorValue) / g_d100;

        if (fnewDarkness < _DAT_01012060)
            fnewDarkness = 0.0f;
        if (fnewDarkness > 1.0)
            fnewDarkness = 1.0f;

        BSShaderManager_RecursiveSetForcedDarkness(reinterpret_cast<int>(ptargetActor->GetNiNode()), fnewDarkness);
    }
}

// @fnv 0x0080c7b0
void DarknessEffect::FinishLoadGameTES(Actor* apActor)
{
    reinterpret_cast<InvisibilityEffect*>(this)->ValueModifierEffect_FinishInitLoadGame(apActor);

    float fnewDarkness = 1.0 - apActor->GetCurrentActorValue(m_eActorValue) / g_d100;

    if (fnewDarkness < 0.0)
        fnewDarkness = 0.0f;

    if (fnewDarkness > 1.0)
        fnewDarkness = 1.0f;

    if (apActor->GetReferenceType() != 0)
        BSShaderManager_RecursiveSetForcedDarkness(apActor->GetReferenceType(), fnewDarkness);
}
