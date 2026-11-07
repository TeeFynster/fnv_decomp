// fallout/magic/concussioneffect.cpp: ConcussionEffect (7 functions)

#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/ActorMover.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/ConcussionEffect.h"
#include "../../../include/ImageSpaceModifierInstanceForm.h"
#include "../../../include/MagicProjectile.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/TESImageSpaceModifier.h"
#include "concussioneffect_decls.h"
#include "../../../include/TESForm.h"

const char kConcussionFXCrippleHead[] = "FXCrippleHead";

// @fnv 0x0080bd60
bool ConcussionEffect::IsEffectValid(MagicTarget* target)
{
    Actor* actor = target ? target->GetOwnerActor() : 0;
    if (actor)
    {
        if (!actor->HasHealth(false) && !actor->GetIsDying())
            return true;
    }
    return false;
}

// @fnv 0x0080bdd0
void ConcussionEffect::Update(float deltaTime)
{
    ((MagicProjectile*)this)->Process(deltaTime);
    m_fPackageValue += deltaTime;
    Actor* actor = GetTarget() ? GetTarget()->GetOwnerActor() : 0;
    if (actor)
        ApplyConcussion(actor);
}

// @fnv 0x0080bcb0
ActiveEffect* ConcussionEffect::Copy()
{
    ConcussionEffect* copy = new ConcussionEffect(m_pEffectInstance, pSpell, pEffect);
    copy->m_fPackageValue = m_fPackageValue;
    CopyData(copy);
    return copy;
}

// @fnv 0x0080be40
void ConcussionEffect::ApplyConcussion(Actor* actor)
{
    if (m_fPackageValue > DAT_011d1ba4.Float()->f)
    {
        m_fPackageValue = 0.0f;
        if (actor->Actor_GetPerceptionCondition() == 0.0)
        {
            if (!actor->GetActorValue(static_cast<ActorValue::Index>(0x48)))
            {
                DAT_011dbe50 = true;
                if (actor->IsPlayerRef() && !g_thePlayer->IsSleepingOrResting())
                {
                    ImageSpaceModifierInstanceForm::Trigger(TESImageSpaceModifier::GetConcussionModifier(),
                                                            DAT_011cf834.Float()->f, 0);
                    BSAudio::GetSingleton()->GetSoundHandleByEditorID(kConcussionFXCrippleHead, 0x101).Play(false);
                }
                actor->GetProcess()->StartIdleAnimation(actor, 0, static_cast<ANIM_IDLE_PLAY_TYPE>(2), true, false, true);
                DAT_011dbe50 = false;
            }
        }
    }
}

// @fnv 0x0080bc70
ConcussionEffect::ConcussionEffect(MagicCaster* apCaster, MagicItem* apMagicItem, EffectItem* apEffectItem)
    : ActiveEffect(apCaster, apMagicItem, apEffectItem)
{
    m_fPackageValue = 0.0f;
}

TESForm* __cdecl GetFormByID(unsigned int);
extern unsigned char DAT_0118abb1;
extern TESImageSpaceModifier* DAT_011c9704;

// @fnv 0x0080bfa0
TESImageSpaceModifier* TESImageSpaceModifier::GetConcussionModifier()
{
    if (!DAT_0118abb1)
        return 0;
    if (!DAT_011c9704)
        DAT_011c9704 = dynamic_cast<TESImageSpaceModifier*>(GetFormByID(0x164));
    return DAT_011c9704;
}

struct FUN_0052d240_shell
{
    void FUN_00483710();
    void BGSStaticCollection_ClearData();
};
// @fnv 0x0052d240
// src: COMMUNITY 0x0052d240
void FUN_0052d240_shell::BGSStaticCollection_ClearData()
{
    FUN_00483710();
}
