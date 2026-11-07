// Reconstructed source: fallout/ai/actor.h
// Actor inline accessors (Doc Speech30 aid segment).
//
// Layout note: the Actor data members below are copied verbatim from the
// canonical Actor.h generated header, including its layout asserts. The
// method declarations after GetActorBase are the original header's inline
// accessors matched here; GetActorStateFlags is declared here and defined in its
// own engine translation unit (only calls are emitted here).
#ifndef FNV_SRC_FALLOUT_AI_ACTOR_H
#define FNV_SRC_FALLOUT_AI_ACTOR_H

#include "mobileobject_topicinfo.h"  // first: its shared headers include <windows.h> before layout_support.h
#include "layout_support.h"
#include "actor_packet.h"
#include "ActorValueOwner.h"
#include "CachedValuesOwner.h"
#include "MagicCaster.h"
#include "MagicTarget.h"
#include "actor_refr.h"
#include "MobileObject.h"
#include "ActorValueModifierList.h"
#include "NiPoint3.h"
// the shared Actor (include/Actor.h); this header keeps the original's inline accessors
#include "../../../include/Actor.h"
#ifdef _MSC_VER
__forceinline
#else
inline __attribute__((always_inline))
#endif
    Actor*
    ActorValueOwner::GetActorOwner()
{
    return static_cast<Actor*>(this);
}

// @fnv 0x0087d6f0
MagicCaster* Actor::GetMagicCaster()
{
    return this;
}

// @fnv 0x0087d7f0
int Actor::GetBaseLevel()
{
    return ActorProjectileState;
}

// @fnv 0x008a3b30
bool Actor::IsMoving()
{
    return GetActorStateFlags() & 0x30;
}
// @fnv 0x008d8100
BSSimpleList<ActiveEffect*>* MiddleHighProcess::GetActiveEffectList() const
{
    return m_pActiveEffectList;
}
// @fnv 0x004997b0
bool Actor::IsSneaking()
{
    return (GetActorStateFlags() & 0x400) && !(GetActorStateFlags() & 0x800) ? true : false;
}
// @fnv 0x008a8290
NiPoint3 Actor::GetMovementPosition()
{
    NiPoint3 result(0.0f, 0.0f, FormPositionData);
    return result;
}
// @fnv 0x00952ff0
NiPoint3* Actor::GetMagicCaster(NiPoint3* output)
{
    if (!*(unsigned char*)((char*)this + 0x64a) && DAT_011e07d0)
    {
        NiPoint3 result = DAT_011e07d0->NiAVObject_GetWorldTranslate();
        *output = result;
        return output;
    }
    GetMagicCaster(*output);
    return output;
}
// @fnv 0x00888070
void Actor::UpdateActorMovement(float delta)
{
    Animation* pCurrentAnimation;
    g_011df69c.IsInCombat();
    if (((ActorPacketView*)this)->GetNiNode() && ((ActorPacketView*)this)->GetNiNode()->GetParent())
    {
        GetAnimation();
        ((ActorProcessView*)m_pBaseProcess)->UpdateActor(this);
        float speed;
        pCurrentAnimation = ((ActorPacketView*)this)->GetAnimData();
        if (((ActorPacketView*)this)->IsDead() && pCurrentAnimation && pCurrentAnimation->IsGroupQueued(0xe1) &&
            GetProcess() && ((ActorProcessView*)GetProcess())->GetBuffer())
        {
            unsigned int steps = 0;
            if ((unsigned int)(pCurrentAnimation->FUN_00453700() * 1000.0) >
                ((ActorProcessView*)GetProcess())->GetTime())
                steps = ((unsigned int)(pCurrentAnimation->FUN_00453700() * 1000.0) -
                         ((ActorProcessView*)GetProcess())->GetTime()) /
                        33;
            pCurrentAnimation->SetAnimationAmount(((ActorProcessView*)GetProcess())->GetBuffer()->LipSynchAnim_GetPuppetValue(steps));
            if (((ActorProcessView*)GetProcess())->GetBuffer() &&
                steps >
                    (unsigned int)((NiPointer<NiNode>*)((ActorProcessView*)GetProcess())->GetBuffer())->operator->())
            {
                ((ActorProcessView*)GetProcess())->Clear(0);
                ((ActorProcessView*)GetProcess())->SetTime(0);
            }
        }
        if (m_bHasUpdated && GetProcess())
        {
            NiAVObject* node = TESObjectREFR::Get3DSimple();  // include/Actor.h also declares a void* twin (0x0043fcd0)
            if (node)
            {
                bool ragdoll = true;
                Actor* actor = 0;
                if (GetObjectReference()->GetFormType() == 0x2b)
                    actor = this;
                if (actor && !((ActorPacketView*)actor)->HasRagdoll())
                    ragdoll = false;
                if (!ragdoll && pCurrentAnimation && pCurrentAnimation->IsGroupQueued(0xe0))
                {
                    SetAnimationGroupAction(1);
                    ((ActorPacketView*)this)->Reset();
                    pCurrentAnimation->Animation_ForceSection(20, 0xe0, -1, 0.0f, -1);
                    NiControllerSequence* sequence = pCurrentAnimation->GetControllerSequence(1);
                    if (sequence)
                    {
                        sequence->PathingLOSGridMap_SetSightRadius(sequence->GetEndKeyTime_00508100());
                        pCurrentAnimation->Update(this, 0.0f, sequence->GetEndKeyTime_00508100());
                        pCurrentAnimation->UpdateMovement(this);
                    }
                    RefreshActorData();
                    m_bHasUpdated = false;
                }
            }
        }
        if (m_pBaseProcess)
        {
            if (((BSSimpleArray<ParentSpaceNode, 1024>*)&DAT_011f2250)->GetSize() == 4 && this == DAT_011f21cc)
                ((ActorProcessView*)m_pBaseProcess)
                    ->Update(this, g_timeGlobal.FUN_0084d030() * DAT_011f2250.GetUpdateTimeScale());
            else
                ((ActorProcessView*)m_pBaseProcess)->Update(this, g_timeGlobal.FUN_0084d030());
        }
        if (!((ActorPacketView*)this)->IsMoving(false) && ((ActorProcessView*)GetProcess())->IsInIdleState() &&
            pCurrentAnimation && !pCurrentAnimation->GetControllerSequence(4))
            SetAnimationForAction(17, pCurrentAnimation);
        UpdateAnimationMovement(pCurrentAnimation, delta);
        if (!((ActorPacketView*)this)->IsDead())
            speed = ((PlayerCharacter*)this)->HasCombatState()
                        ? *(float*)((SettingT_GameSettingCollection_*)&g_011f2ac4)->Float()
                        : *(float*)((SettingT_GameSettingCollection_*)&g_011f2ad8)->Float();
        else
            speed = ((PlayerCharacter*)this)->HasCombatState()
                        ? *(float*)((SettingT_GameSettingCollection_*)&g_011f2b10)->Float()
                        : *(float*)((SettingT_GameSettingCollection_*)&g_011f2c10)->Float();
        PickAnimations(1.0f, speed);
    }
    g_011df69c.IsInCombat();
}
#endif
