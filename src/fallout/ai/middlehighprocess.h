// Reconstructed source: fallout/ai/middlehighprocess.h
// MiddleHighProcess inline accessors (Doc Speech30 aid segment).
#ifndef FNV_MIDDLEHIGHPROCESS_H
#define FNV_MIDDLEHIGHPROCESS_H

#include "../../../include/FurnitureMark.h"
#include "../../../include/MiddleHighProcess.h"

enum RESET_3D_FLAGS
{
    RESET_3D_FLAGS_RESET_MODEL = 1,
    RESET_3D_FLAGS_RESET_SKIN = 2,
    RESET_3D_FLAGS_RESET_HEAD = 4,
    RESET_3D_FLAGS_RESET_FACE = 8,
    RESET_3D_FLAGS_RESET_SCALE = 16
};

// @fnv 0x008d8120
MagicItem* MiddleHighProcess::GetSelectedMagicItem() const
{
    return m_pFirstMagicItem;
}

// @fnv 0x008d8140
void MiddleHighProcess::SetSelectedMagicItem(MagicItem* apSpell)
{
    m_pFirstMagicItem = apSpell;
}

// @fnv 0x008d8180
void MiddleHighProcess::SetMagicTarget(MagicTarget* apTarget)
{
    m_pMagicTarget = apTarget;
}

// @fnv 0x008d81a0
bool MiddleHighProcess::UpdateIdleAnimation() const
{
    return m_bWeaponOut;
}

// @fnv 0x008d8220
bool MiddleHighProcess::ResetAlertState() const
{
    return m_bFirstWeaponFlag;
}

// @fnv 0x008d8270
bool MiddleHighProcess::GetProcessState()
{
    return m_bFourthWeaponFlag;
}

// @fnv 0x008d8290
bool MiddleHighProcess::SetProcessStateFlag()
{
    return m_bFifthWeaponFlag;
}

// @fnv 0x008d82d0
bool MiddleHighProcess::SetActorAlertState()
{
    return m_bSeventhWeaponFlag;
}

// @fnv 0x008d82f0
void MiddleHighProcess::Assign3DObject(NiAVObject* apNode)
{
    m_pActorObject = apNode;
}

// @fnv 0x008d8420
int MiddleHighProcess::GetCurrentProcedure() const
{
    return const_cast<ActorPackageContext&>(PackageReference).GetProcedureIndex();
}

// @fnv 0x008d8440
void MiddleHighProcess::SetCurrentProcedure(int aiIndex)
{
    PackageReference.AddToProcedureIndex(aiIndex);
}

// @fnv 0x008d8480
bhkCharacterController* MiddleHighProcess::GetPhysicsCharacterController() const
{
    return m_pCharacterController;
}

// @fnv 0x008d84a0
void MiddleHighProcess::AssignCharacterController(NiPointer<bhkCharacterController> apController)
{
    m_pCharacterController = apController;
}

// @fnv 0x008d8500
void MiddleHighProcess::AddDeferredHideLimb(ObjectToAcquire* apObject)
{
    m_pDetectionData60 = (TargetDoorController*)apObject;
}

// @fnv 0x00407800
void MiddleHighProcess::SetFaceAnimationData(ObjectToAcquire* apObject)
{
    m_pDetectionData64 = (TargetDoorController*)apObject;
}

// @fnv 0x008d8540
KNOCK_STATE_ENUM MiddleHighProcess::StopIdleAnimation()
{
    return (KNOCK_STATE_ENUM)m_cCharacterControllerState;
}

// @fnv 0x008d8600
bool MiddleHighProcess::IsProcessStateInitialized() const
{
    return m_bFirstFaceGenFlag;
}

// @fnv 0x008d8680
void MiddleHighProcess::InitializeProcessState()
{
    m_pFaceGenAnimationData = 0;
}

// @fnv 0x008d8740
void MiddleHighProcess::ResetActorModel(RESET_3D_FLAGS aeFlags)
{
    m_ucProcessState |= aeFlags;
}

// @fnv 0x008d87a0
void MiddleHighProcess::ClearDetectionFlag()
{
    m_ucProcessState = 0;
}

// @fnv 0x008d8800
BSSimpleList<ArrowProjectile*>* MiddleHighProcess::GetArrowProjectiles() const
{
    return m_pArrowProjectileList;
}

// @fnv 0x008d8840
bool MiddleHighProcess::IsAlert() const
{
    return m_kFieldAfterWeaponFlags;
}

// @fnv 0x008d8860
bool MiddleHighProcess::IsHoldingWeapon()
{
    return m_bFirstAnimationFlag;
}

// @fnv 0x008d8880
void MiddleHighProcess::SetSustainedState(bool abSustained)
{
    m_bFirstAnimationFlag = abSustained;
}

// @fnv 0x008d88a0
void MiddleHighProcess::SetIdleAnimationPlayed(bool abPlayed)
{
    m_kThirdUnshownMember = abPlayed;
}

// @fnv 0x008d88e0
void MiddleHighProcess::SetPlayedState(bool abPlayed)
{
    m_kFourthUnshownMember = abPlayed;
}

// @fnv 0x008d8900
bool MiddleHighProcess::WasIdleAnimationPlayed() const
{
    return m_kFourthUnshownMember;
}

// @fnv 0x008d8920
LipSyncAnimation* MiddleHighProcess::GetLipSyncAnimationData() const
{
    return m_pLipSyncAnimation;
}

// @fnv 0x008d89c0
float MiddleHighProcess::GetAnimationElapsedTime() const
{
    return m_fFirstFaceGenValue;
}

// @fnv 0x008d89e0
void MiddleHighProcess::AdvanceMovementTimer(float afDelta)
{
    m_fSecondFaceGenValue = afDelta;
}

// @fnv 0x008d8a00
float MiddleHighProcess::GetAnimationRemainingTime() const
{
    return m_fSecondFaceGenValue;
}

// @fnv 0x008d8a80
void MiddleHighProcess::SetKnockdownStage(int aiStage)
{
    m_iFaceGenNodeIndex = aiStage;
}

// @fnv 0x008d8aa0
void MiddleHighProcess::AttachFaceGenerationNode(BSFaceGenNiNode* apNode)
{
    m_pFirstFaceGenNode = apNode;
}

// @fnv 0x008d8ac0
BSFaceGenNiNode* MiddleHighProcess::GetFaceGenHeadNode() const
{
    return m_pSecondFaceGenNode;
}

// @fnv 0x008d8ae0
void MiddleHighProcess::SetFaceGenHeadNode(BSFaceGenNiNode* apNode)
{
    m_pSecondFaceGenNode = apNode;
}

// @fnv 0x008d8b00
NiAVObject* MiddleHighProcess::GetAnimationObject() const
{
    return m_pFaceGenObject;
}

// @fnv 0x008d8c20
NiNode* MiddleHighProcess::GetActorSceneObject() const
{
    return (NiNode*)m_pSecondAttachedObject;
}

// @fnv 0x00502430
NiNode* MiddleHighProcess::GetSceneRoot() const
{
    return (NiNode*)m_pActorObject;
}

// @fnv 0x00505e50
void MiddleHighProcess::SetCurrentIdle(TESIdleForm* apIdle)
{
    m_pPackageIdleForm = apIdle;
}

// @fnv 0x00521630
BooleanFloatQuery* MiddleHighProcess::RefreshActorRuntimeData() const
{
    return m_pData;
}

// @fnv 0x00521710
void MiddleHighProcess::SetAnimationNode(NiAVObject* apAnims)
{
    m_pFaceGenObject = apAnims;
}

// @fnv 0x005224a0
BSFaceGenNiNode* MiddleHighProcess::GetFacialAnimationNode() const
{
    return m_pFirstFaceGenNode;
}

// @fnv 0x00566950
bool MiddleHighProcess::IsActorInCombat() const
{
    return m_bEquipStateFlag;
}

// @fnv 0x005c8a30
void MiddleHighProcess::SetBoundingBox(BSBound* apBound)
{
    m_pBound = apBound;
}

// @fnv 0x005ce8f0
bool MiddleHighProcess::IsAnimationPlaying() const
{
    return m_bSecondWeaponFlag;
}

// @fnv 0x00602150
Animation* MiddleHighProcess::GetAnimation() const
{
    return pCurrentAnimation;
}

// @fnv 0x007ac9d0
void MiddleHighProcess::AssignEffectShader(TESEffectShader* apShader)
{
    m_pEffectShader = apShader;
}

// @fnv 0x0087d7d0
void MiddleHighProcess::UpdateEffectShader(unsigned int auiTime)
{
    m_uiLipSyncState = auiTime;
}

// @fnv 0x008f7710
float MiddleHighProcess::GetLightIntensity() const
{
    return m_fFirstEffectShaderValue;
}

// @fnv 0x009ee020
BSBound* MiddleHighProcess::GetObjectBounds()
{
    return m_pBound;
}

// @fnv 0x008d8310
bool MiddleHighProcess::ClearProcessStateFlags() const
{
    return GetRunOncePackage();
}

// @fnv 0x008d8b20
SIT_SLEEP_STATE MiddleHighProcess::GetSitSleepState() const
{
    if ((GetPostAnimationAction() & 8) &&
        (m_ucFurnitureInteractionState == 4 || m_ucFurnitureInteractionState == 9))
        return (SIT_SLEEP_STATE)(m_ucFurnitureInteractionState + 1);
    else
        return (SIT_SLEEP_STATE)m_ucFurnitureInteractionState;
}

#endif
