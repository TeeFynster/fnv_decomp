
// Fallout: New Vegas - original source reconstruction.
// Source unit: fallout/ai/movement/playermover.cpp
//
// PlayerMover extends the ActorMover base with player-specific movement
// state: a side-step vector, the current move mode, the pending turn
// direction bits and the minimum turn timer.
//
#include "../../../../include/bhkCharacterController.h"
#include "../../../../include/Actor.h"
#include "../../../../include/LowProcess.h"
#include "../../../../include/MapEntryCount.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TESActorBaseData.h"
#include "../../../../include/TESAnimGroup.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESObjectLAND.h"
#include "../../../../include/TESTopicInfo.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/ActorMover.h"
#include "../../../../include/PlayerMover.h"
#include "playermover_decls.h"

// @fnv 0x009ea6a0
void PlayerMover::Revert(BGSLoadFormBuffer* apBuffer)
{
    ActorMover::Revert(apBuffer);
    m_kSideVec = NiPoint3::ZERO;
    ByteAndFlagState = 0;
    m_fValue = -1.0f;
    m_uiMode = 0;
}

// @fnv 0x009ea610
void PlayerMover::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    ActorMover::LoadGame(apBuffer);
    apBuffer->ReadDataBlock(&m_kSideVec, sizeof(m_kSideVec));
    apBuffer->ReadDataBlock(&ByteAndFlagState, sizeof(ByteAndFlagState));
    apBuffer->ReadDataBlock(&m_uiMode, sizeof(m_uiMode));
    apBuffer->ReadDataBlock(&m_fValue, sizeof(m_fValue));
}

// @fnv 0x009ea680
void PlayerMover::InitLoadGame(BGSLoadFormBuffer* apBuffer)
{
    ActorMover::InitLoadGame(apBuffer);
}

// @fnv 0x009ea2f0
void PlayerMover::SetMovementValue(float afDelta)
{
    if (m_fValue > 0.0)
    {
        m_fValue -= afDelta;
        if (!pActor->GetSitSleepState())
            ByteAndFlagState |= m_uiMode;
    }
}

// @fnv 0x009e9e50
void PlayerMover::Update(float fTimeSinceScaleStart)
{
    NiPoint3 delta = NiPoint3::ZERO;
    Animation* animation = g_thePlayer->GetAnimation(false);
    if (!g_thePlayer->PlayerCharacter_Is3rdPerson())
    {
        Animation* firstPerson = g_thePlayer->GetAnimation(true);
        if (!animation || firstPerson->Animation_GetGroup(1) == animation->Animation_GetGroup(1))
            animation = firstPerson;
    }
    if (!g_thePlayer->PlaceAtPosition(delta))
    {
        if (animation)
        {
            if (g_thePlayer->FUN_0050d4a0())
                animation->GetMovementDelta(&delta, g_thePlayer, true, false);
            else
                animation->GetMovementDelta(&delta, g_thePlayer, false, true);
        }
        struct ControllerState
        {
            bhkCharacterController* controller;
            bhkCharacterController::ControllerState* state;
        } character;
        character.controller = g_thePlayer->GetPhysicsCharacterController();
        character.state = character.controller ? &character.controller->state : 0;
        if (character.state && character.state->bhkCharacterListener_StuckToSomeone())
            delta = NiPoint3::ZERO;
        if ((ByteAndFlagState & 0xF) && !g_thePlayer->GetIsDying() && !g_thePlayer->FUN_0050d4a0())
        {
            switch (g_thePlayer->GetAnimAction())
            {
            default:
                break;
            }
            struct MovementLengths
            {
                float sideLength;
                float deltaLength;
            } lengths;
            lengths.sideLength = static_cast<const NiPoint3&>(m_kSideVec).Length();
            lengths.deltaLength = static_cast<const NiPoint3&>(delta).Length();
            if (lengths.sideLength > 0.0 && lengths.deltaLength > 0.0 && !(ByteAndFlagState & 0x40))
            {
                float sideX = m_kSideVec.x / lengths.sideLength;
                float sideY = m_kSideVec.y / lengths.sideLength;
                delta.x = sideX * lengths.deltaLength;
                delta.y = sideY * lengths.deltaLength;
            }
        }
        if ((ByteAndFlagState & 3) && (ByteAndFlagState & 0xC) && !g_thePlayer->GetIsDying())
        {
            switch (g_thePlayer->GetLogDate()->GetAnimAction())
            {
            default:
                if (delta.y != 0.0)
                {
                    float displacement = m_kSideVec.x * fTimeSinceScaleStart * g_thePlayer->GetScale();
                    float angle = displacement / delta.y * 0.7853981852531433;
                    if (ByteAndFlagState & 4)
                        delta.x += -std::abs(cos(1.5707963705062866 - angle) * delta.y);
                    else if (ByteAndFlagState & 8)
                        delta.x += std::abs(cos(1.5707963705062866 - angle) * delta.y);
                    delta.y = cos(angle) * delta.y;
                }
            case 13:
            case 14:
                break;
            }
        }
    }
    if (g_thePlayer->FUN_0050d4a0())
    {
        NiPoint3 position =
            *reinterpret_cast<NiPoint3*>(reinterpret_cast<TESTopicInfo*>(g_thePlayer)->GetAddTopicList()) + delta;
        g_thePlayer->SetPos(&position);
    }
    else
    {
        g_thePlayer->Move(fTimeSinceScaleStart, &delta, g_thePlayer->GetActorStateFlags());
        struct GroundHeight
        {
            float height;
            TESObjectCELL* cell;
        } ground;
        ground.cell = reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(g_thePlayer)->LowProcess::GetTarget());
        if (ground.cell && !ground.cell->IsCellInterior())
        {
            ground.height = 0.0f;
            NiPoint3 position = *static_cast<const MobileObject*>(g_thePlayer)->GetPos();
            if (ground.cell->GetLandscape()->GetLandHeightAtPosition(position, ground.height))
            {
                if (ground.height - position.z > 32.0)
                {
                    position.z = ground.height + 32.0;
                    g_thePlayer->SetPos(&position);
                }
            }
        }
    }
}

// @fnv 0x009ea3e0
void PlayerMover::SetMoverMode(unsigned int auMode)
{
    bool changed = (ByteAndFlagState & 0x400) != (auMode & 0x400);
    if (auMode & 0x30)
    {
        m_fValue = DAT_011cdf28.Float()->f;
        m_uiMode = auMode & 0x30;
    }
    ByteAndFlagState = auMode;
    if (changed && TESAnimGroup::IsAimAnimation(g_thePlayer->GetAnimation(false)->Animation_GetGroup(4)))
    {
        struct AimAnimationState
        {
            ANIM_GROUP_ENUM group;
            unsigned short groupID;
            Animation* animation;
            NiControllerSequence* sequence;
        } aimState;
        aimState.group = g_thePlayer->IsAlert() ? (ANIM_GROUP_ENUM)20 : (ANIM_GROUP_ENUM)17;
        aimState.animation = g_thePlayer->GetAnimation(false);
        aimState.sequence = aimState.animation->GetControllerSequence(4);
        aimState.groupID = g_thePlayer->GetAnimGroup(aimState.group, 0, false, aimState.animation);
        if (!aimState.sequence ||
            aimState.groupID != aimState.sequence->GetAnimGroup()->GetAnimGroupType_0047d3b0())
            aimState.animation->BlendOut(4, false);
        aimState.animation = g_thePlayer->GetAnimation(true);
        aimState.sequence = aimState.animation->GetControllerSequence(4);
        aimState.groupID = g_thePlayer->GetAnimGroup(aimState.group, 0, false, aimState.animation);
        if (!aimState.sequence ||
            aimState.groupID != aimState.sequence->GetAnimGroup()->GetAnimGroupType_0047d3b0())
            aimState.animation->BlendOut(4, false);
    }
}

// @fnv 0x009ea360
void PlayerMover::UpdatePlayerStatus(unsigned int auMode, bool abSet)
{
    if (abSet)
        ByteAndFlagState |= auMode;
    else
        ByteAndFlagState &= ~auMode;
}

// Stores the given side vector into the player mover's side vector member.
// @fnv 0x009ea570
void PlayerMover::SetSideVec(const NiPoint3& arSideVec)
{
    m_kSideVec = arSideVec;
}

// @fnv 0x009ea3b0
void PlayerMover::ClearMode(unsigned int auMode)
{
    ByteAndFlagState &= ~auMode;
}

// @fnv 0x009e9de0
// src: XBOX_PDB 0x009e9de0
void PlayerMover::ClearMoveModePreference(unsigned int auMode)
{
    ClearMode(auMode);
}

// @fnv 0x009e9dc0
// src: XBOX_PDB 0x009e9dc0
void PlayerMover::SetMoveModePreference(unsigned int auMode)
{
    UpdatePlayerStatus(auMode, true);
}

// @fnv 0x009e9e30
// src: GUESS 0x009e9e30 (confidence: medium)
void PlayerMover::ResetVtableAndDestroyActorMover()
{
    *reinterpret_cast<int*>(this) = 0x0109297c;
    ActorMover::~ActorMover();
}

void __cdecl _Deallocate(void*);
// Calls FUN_009e9e30, then deallocates this object if auFlags has bit 0 set, and returns this.
// @fnv 0x009e9e00
void* PlayerMover::FUN_009e9e00(unsigned int auFlags)
{
    ResetVtableAndDestroyActorMover();
    if (auFlags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x009ea5a0
// src: XBOX_PDB 0x009ea5a0
void PlayerMover::SaveGame_009ea5a0(BGSSaveFormBuffer* apBuffer)
{
    ActorMover::SaveGame_009df100(apBuffer);
    apBuffer->SaveData(&m_kSideVec, 0xC, 0);
    apBuffer->SaveData(&ByteAndFlagState, 4, 0);
    apBuffer->SaveData(&m_uiMode, 4, 0);
    apBuffer->SaveData(&m_fValue, 4, 0);
}
