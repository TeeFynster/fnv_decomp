// fallout/ai/highprocess.h: definitions for shared HighProcess declarations
#ifndef FNV_LUNA_HIGH_PROCESS_H
#define FNV_LUNA_HIGH_PROCESS_H

#include "../../../include/BaseProcess.h"
#include "../../../include/HighProcess.h"
#include "highprocess_packet_decls.h"

// @fnv 0x008d9090
float HighProcess::GetProcessBlendAmount() const
{
    return fAwarePlayerTimer;
}

// @fnv 0x004727d0
unsigned int HighProcess::GetPostAnimationAction() const
{
    return m_ePendingPostAnimationActions;
}

// @fnv 0x0051f510
MobileObject* HighProcess::GetMobileObject() const
{
    return m_pSavedReference;
}

// @fnv 0x008d94b0
float HighProcess::GetProcessBlendWeight() const
{
    return m_fLipSyncTimer;
}

// @fnv 0x008d9530
bool HighProcess::IsDetectionEnabled() const
{
    return m_bSpellState;
}

// @fnv 0x006214b0
TESIdleForm* HighProcess::GetSelectedIdleForm() const
{
    return iAnimationStateCode;
}

// @fnv 0x008d9610
BaseProcess::FadeState HighProcess::GetCurrentFadeState() const
{
    return (BaseProcess::FadeState)m_iSecondSerializedValue;
}

// @fnv 0x008d96b0
void HighProcess::ClearPostAnimActions()
{
    m_ePendingPostAnimationActions = BaseProcess::POSTANIM_ACTION_NONE;
}

// @fnv 0x008d9300
NiObjectNET* HighProcess::GetMuzzleFlash() const
{
    return (NiObjectNET*)m_pMuzzleFlash;
}

// @fnv 0x008d94f0
float HighProcess::GetLightLevel(void)
{
    return m_fLipSyncValue;
}

// @fnv 0x008d94d0
void HighProcess::SetLightLevel(float value)
{
    m_fLipSyncTimer = value;
}

// @fnv 0x008d9510
void HighProcess::SetFloatProperty(float value)
{
    m_fLipSyncValue = value;
}

// @fnv 0x008d95b0
float HighProcess::GetCurrentAlpha() const
{
    return m_fSecondLipSyncParameter;
}

// @fnv 0x008d9010
float HighProcess::GetRadiationRate() const
{
    return m_fSecondProcessValue;
}

// @fnv 0x008d9030
void HighProcess::SetRadiationRate(float value)
{
    m_fSecondProcessValue = value;
}

// @fnv 0x008d91e0
bool HighProcess::IsProcessStateActive() const
{
    return iLocalState;
}

// @fnv 0x008d97a0
float HighProcess::GetControllerPhase() const
{
    return m_fSecondReferenceValue > m_kTenthUnshownMember ? m_fSecondReferenceValue : m_kTenthUnshownMember;
}

// @fnv 0x008d90e0
void HighProcess::UpdateActorLighting(float value)
{
    m_fAwarenessValue = value;
}

// @fnv 0x008d8da0
bool HighProcess::IsAsleep() const
{
    return m_bSubtitleActive;
}

// @fnv 0x008d93f0
double HighProcess::GetDetectionStrength(void)
{
    return m_fSocialTalkDelay;
}

// @fnv 0x008d9650
bool HighProcess::IsCurrentlyDetected() const
{
    return pTargetObject;
}

// @fnv 0x008d8f10
bool HighProcess::IsDetecting() const
{
    return iProcessIndex;
}

// @fnv 0x008d9050
bool HighProcess::HasAssignedAnimation() const
{
    return m_bSavedReferenceFlag;
}

// @fnv 0x008d9180
bool HighProcess::IsMovementStopped(void)
{
    return bStop;
}

// @fnv 0x008d9740
float HighProcess::GetDetectionProgress() const
{
    return m_fReferencePriority;
}

// @fnv 0x008d9760
void HighProcess::SetDetectionLevel(float value)
{
    m_fReferencePriority = value;
}

// @fnv 0x008d8de0
DIALOGUE_EMOTION HighProcess::GetCurrentDialogueEmotion() const
{
    return m_iProcessState;
}

// @fnv 0x008d9720
bool HighProcess::GetPlantedExplosive() const
{
    return iCount;
}

// @fnv 0x008d9100
float HighProcess::UpdateProcessTiming() const
{
    return m_fAwarenessValue;
}

// @fnv 0x008d9390
DetectionEvent* HighProcess::FindDetectionEventForActor(Actor* index)
{
    return m_pDetectionEvent;
}

// @fnv 0x008d8ff0
void HighProcess::SetEssentialFlag(bool value)
{
    bWeaponAlertDrawn = value;
}

// @fnv 0x008d9070
void HighProcess::SetAnimationEnabled(bool value)
{
    m_bSavedReferenceFlag = value;
}

// @fnv 0x008d9320
float HighProcess::GetFirstProcessFloat() const
{
    return m_fImpactValue;
}

// @fnv 0x008d9690
void HighProcess::SetCurrentDialogueItem(DialogueItem* value)
{
    m_pCurrentDialogueItem = value;
}

// @fnv 0x008d9410
void HighProcess::SetIdleForm(TESIdleForm* value)
{
    iAnimationStateCode = value;
}

// @fnv 0x008d91a0
void HighProcess::ResetMovementState(void)
{
    bStop = BaseProcess::POSTANIM_ACTION_NONE;
}

// @fnv 0x008d9160
void HighProcess::SetSubtitleActive(bool value)
{
    m_bDialogueFlag = value;
}

// @fnv 0x008d9550
void HighProcess::SetActorProcessEnabled(bool value)
{
    m_bSpellState = value;
}

// @fnv 0x008d9240
LipSyncAnimation* HighProcess::GetLipSync() const
{
    return pLipSyncAnimation;
}

// @fnv 0x008d92a0
bool HighProcess::IsActorTalking() const
{
    return m_bLipSyncPlaying;
}

// @fnv 0x008d9220
void HighProcess::SetDialogueState(bool value)
{
    m_bLipSyncEnabled = value;
}

// @fnv 0x008d8e00
void HighProcess::SetDialogueEmotion(DIALOGUE_EMOTION value)
{
    m_iProcessState = value;
}

// @fnv 0x008d9260
void HighProcess::AssignLipSyncAnimation(LipSyncAnimation* value)
{
    pLipSyncAnimation = value;
}

// @fnv 0x008d8f70
void HighProcess::SetLipSyncValue(float value)
{
    m_fReferenceTimer = value;
}

// @fnv 0x008d9280
void HighProcess::SetTalkingState(bool value)
{
    m_bLipSyncPlaying = value;
}

// @fnv 0x008d8fb0
void HighProcess::UpdateActorProcess(float value)
{
    m_fFirstProcessValue = value;
}

// @fnv 0x008d9830
TESObjectREFR* HighProcess::GetRelatedReference() const
{
    return coordinate;
}

// @fnv 0x008d8e20
TESObjectREFR* HighProcess::GetPreviousReference() const
{
    return m_pSocialTalkTarget;
}

// @fnv 0x008d9430
bool HighProcess::HasCombatStarted()
{
    return m_bTrackedReferenceFlag;
}

// @fnv 0x008d9810
bool HighProcess::IsCombatTargetValid() const
{
    return m_bDetectionFlag;
}

// @fnv 0x008d8e40
void HighProcess::SetActorTargetReference(TESObjectREFR* value)
{
    m_pSocialTalkTarget = value;
}

// @fnv 0x008d92c0
bool HighProcess::CanFireWeapon(void)
{
    return m_bAlertState;
}

// @fnv 0x008d9670
DialogueItem* HighProcess::GetCurrentDialogueItem() const
{
    return m_pCurrentDialogueItem;
}

// @fnv 0x008d8dc0
void HighProcess::SetCombatEnabled(bool value)
{
    m_bSubtitleActive = value;
}

// @fnv 0x008d8f30
void HighProcess::SetCombatAlerted(bool value)
{
    iProcessIndex = value;
}

// @fnv 0x008d9570
void HighProcess::StopAllActorSounds()
{
    m_fSecondLipSyncParameter = *originalRuntimeFloatSetting244.Float();
}

// @fnv 0x008d8e60
BSSoundHandle HighProcess::GetActorSoundHandle(unsigned int index)
{
    return AudioPlaybackHandle[index];
}

// @fnv 0x008d8ea0
void HighProcess::SetActorSoundHandle(unsigned int index, BSSoundHandle handle)
{
    AudioPlaybackHandle[index] = handle;
}

#endif
