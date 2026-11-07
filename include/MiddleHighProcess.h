#pragma once

#include "MiddleLowProcess.h"
#include "ActorPackageContext.h"
#include "NiPoint3.h"
#include "MagicTarget.h"
#include "NiAVObject.h"
#include "FurnitureMark.h"

class ActiveEffect;
class Actor;
class ActorSupportClass;
class Animation;
class ArrowProjectile;
class BGSLoadFormBuffer;
class BipedAnim;
class BooleanFloatQuery;
class BSAnimGroupSequence;
class BSBound;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class DetectionViewData;
class InventoryStackRecord;
class LipSyncAnimation;
class MagicCaster;
class MagicItem;
class MagicTarget;
class MiddleHighProcess__DeferredHideLimb;
class NiNode;
class PaddedFloatRecord;
class QueuedFile;
class SpellItem;
class TargetDoorController;
class TESEffectShader;
class TESIdleForm;
class TESObjectREFR;
class TESObjectWEAP;
class TESPackage;
class ActorCombatGroup;
class bhkCharacterController;

enum KNOCK_STATE_ENUM;
enum RESET_3D_FLAGS;

#pragma pack(push, 4)
class MiddleHighProcess : public MiddleLowProcess
{
public:
    virtual void vfn_820(); // slot 520
    virtual void vfn_824(); // slot 521
    virtual void vfn_828(); // slot 522
    virtual void vfn_82c(); // slot 523
    virtual void vfn_830(Actor*); // slot 524 (ProcessAcquire 0x008ebc60 passes the actor)
    virtual void vfn_834(Actor*); // slot 525 (ProcessAcquire 0x008ebc60 passes the actor)
    virtual void vfn_838(Actor*); // slot 526 (ProcessAcquire 0x008ebc60 passes the actor)
    virtual void vfn_83c(Actor*); // slot 527 (parameters: HighProcess::Update 0x008eeec0 calls)
    virtual bool vfn_840(Actor*); // slot 528 (HighProcess 0x008e8600)
    virtual void vfn_844(); // slot 529
    virtual void vfn_848(Actor*, int, int); // slot 530
    virtual void vfn_84c(Actor*, const NiPoint3*, float); // slot 531 (HighProcess 0x008ed420)
    virtual bool vfn_850(Actor*, Actor*); // slot 532 (HighProcess 0x00901a20)
    virtual void vfn_854(); // slot 533
    virtual void vfn_858(); // slot 534
    virtual void vfn_85c(); // slot 535
    virtual void vfn_860(); // slot 536
    virtual void vfn_864(); // slot 537
    virtual void vfn_868(Actor*, Actor*); // slot 538
    virtual void vfn_86c(); // slot 539
    virtual void ProcessAvoidRadiation(Actor*); // slot 506 override, 0x00908f40 (HighProcess::Update calls it directly)
    virtual bool ShouldAttackTarget(Actor*, Actor*, bool, bool, ActorCombatGroup*, bool, bool, bool, bool, bool, bool,
                                    bool, TESPackage*); // slot 207 override, 0x00916880 (HighProcess 0x009001c0 calls it directly)

    BSSimpleList<TESObjectREFR*> m_kReferenceList; // 0x0C8
    BSSimpleList<TESObjectREFR*> m_kSecondaryReferenceList; // 0x0D0
    float m_kNinthUnshownMember; // 0x0D8
    float m_kEighthUnshownMember; // 0x0DC
    bool m_bPackageStateFlag2; // 0x0E0
    bool m_bPackageStateFlag; // 0x0E1
    bool m_bPackageStateFlag3; // 0x0E2
    bool m_bPackageStateFlag4; // 0x0E3
    ActorPackageContext PackageReference; // 0x0E4
    NiPoint3 m_kPackageTargetPosition; // 0x0FC
    PACKAGE_OBJECT_TYPE m_ePackageObjectType; // 0x108
    TESIdleForm* m_pPackageIdleForm; // 0x10C
    bool m_kSecondUnshownMember; // 0x110
    unsigned char layoutPadding111[3]; // 0x111
    InventoryStackRecord* pWeapon; // 0x114
    InventoryStackRecord* pAmmo; // 0x118
    NiPointer<QueuedFile> m_pQueuedWeaponFile; // 0x11C
    NiPointer<ActorSupportClass> m_pWeaponData; // 0x120
    bool m_bFirstWeaponFlag; // 0x124
    bool m_bSecondWeaponFlag; // 0x125
    bool m_bThirdWeaponFlag; // 0x126
    bool m_bFourthWeaponFlag; // 0x127
    bool m_bFifthWeaponFlag; // 0x128
    bool m_bSixthWeaponFlag; // 0x129
    bool m_bSeventhWeaponFlag; // 0x12A
    unsigned char layoutPadding12B[1]; // 0x12B
    NiNode* m_pActorNode; // 0x12C
    NiAVObject* m_pActorObject; // 0x130
    bool m_bFirstActorFlag; // 0x134
    bool m_bAdditionalActorFlag; // 0x135
    unsigned char layoutPadding136[2]; // 0x136
    NiPointer<bhkCharacterController> m_pCharacterController; // 0x138
    char m_cCharacterControllerState; // 0x13C
    unsigned char m_ucFurnitureInteractionState; // 0x13D
    unsigned char layoutPadding13E[2]; // 0x13E
    TESObjectREFR* m_pFurnitureReference; // 0x140
    unsigned char m_ucFurnitureMarkerIndex; // 0x144
    unsigned char layoutPadding145[3]; // 0x145
    FurnitureMark FurnitureMarker; // 0x148
    Actor* m_pCombatTarget; // 0x158
    TESObjectWEAP* m_pEquippedWeapon; // 0x15C
    MagicItem* m_pFirstMagicItem; // 0x160
    MagicItem* m_pSecondMagicItem; // 0x164
    bool m_bWeaponOut; // 0x168
    unsigned char layoutPadding169[3]; // 0x169
    TESEffectShader* m_pEffectShader; // 0x16C
    float m_fFirstEffectShaderValue; // 0x170
    float m_fSecondEffectShaderValue; // 0x174
    BSFaceGenAnimationData* m_pFaceGenAnimationData; // 0x178
    bool m_bFirstFaceGenFlag; // 0x17C
    bool m_kSixthUnshownMember; // 0x17D
    bool m_bThirdFaceGenFlag; // 0x17E
    bool m_kSeventhUnshownMember; // 0x17F
    bool m_kFifthUnshownMember; // 0x180
    unsigned char layoutPadding181[3]; // 0x181
    unsigned int m_uiAnimationStateFlags; // 0x184
    bool m_bAiming; // 0x188
    bool m_bAimStateFlag; // 0x189
    bool m_bCombatStateFlag; // 0x18A
    bool m_bFourthStateFlag; // 0x18B
    unsigned char m_ucProcessState; // 0x18C
    bool m_bEquipStateFlag; // 0x18D
    unsigned char layoutPadding18E[2]; // 0x18E
    int m_iIdleState; // 0x190
    TESIdleForm* m_pCurrentIdleForm; // 0x194
    float m_fIdleAnimationTime; // 0x198
    bool m_kThirdUnshownMember; // 0x19C
    bool m_kFourthUnshownMember; // 0x19D
    unsigned char layoutPadding19E[2]; // 0x19E
    LipSyncAnimation* m_pLipSyncAnimation; // 0x1A0
    unsigned int m_uiLipSyncState; // 0x1A4
    int m_iProjectileCount; // 0x1A8
    BSSimpleList<ArrowProjectile*>* m_pArrowProjectileList; // 0x1AC
    BSSimpleList<MiddleHighProcess__DeferredHideLimb*> m_kDeferredHideLimbList; // 0x1B0
    BSSimpleList<ActiveEffect*>* m_pActiveEffectList; // 0x1B8
    MagicTarget* m_pMagicTarget; // 0x1BC
    Animation* pCurrentAnimation; // 0x1C0
    BSAnimGroupSequence* m_apAnimGroupSequences[3]; // 0x1C4
    float m_fAnimationTime; // 0x1D0
    float m_fAnimationSpeed; // 0x1D4
    unsigned char m_ucAnimationState; // 0x1D8
    bool m_bFirstAnimationFlag; // 0x1D9
    bool m_bAnimationStateFlag; // 0x1DA
    unsigned char layoutPadding1DB[1]; // 0x1DB
    NiNode* m_apBodyPartNodes[15]; // 0x1DC
    NiAVObject* m_pFirstAttachedObject; // 0x218
    NiAVObject* m_pSecondAttachedObject; // 0x21C
    NiPointer<BSShaderPPLightingProperty> m_pLightingProperty; // 0x220
    BSBound* m_pBound; // 0x224
    bool m_kFieldAfterWeaponFlags; // 0x228
    unsigned char layoutPadding229[1]; // 0x229
    short m_sBoundDataValue; // 0x22A
    unsigned int m_kEleventhUnshownMember; // 0x22C
    BSSimpleList<PaddedFloatRecord*>* m_pkPaddedFloatRecordList; // 0x230
    float m_kTenthUnshownMember; // 0x234
    float m_fFirstFaceGenValue; // 0x238
    float m_fSecondFaceGenValue; // 0x23C
    BooleanFloatQuery* m_pData; // 0x240
    int m_iFaceGenNodeIndex; // 0x244
    BSFaceGenNiNode* m_pFirstFaceGenNode; // 0x248
    BSFaceGenNiNode* m_pSecondFaceGenNode; // 0x24C
    NiAVObject* m_pFaceGenObject; // 0x250
    BooleanFloatQuery* m_pAdditionalFaceGenData; // 0x254
    unsigned int m_uiFaceGenDataFlags; // 0x258

    MiddleHighProcess();
    virtual ~MiddleHighProcess();
    virtual void ResetCurrentPackage(); // RTTI slot 145
    void SetAnimation(Animation*);
    void RefreshActorPackage(Actor*);
    void ProcessCombat_0091db40(Actor*);
    void BGSTerrainManager_SetNeedsImmediateUpdate(unsigned char);
    bool BSCriticalSection_TryLock();
    void Revert(BGSLoadFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    virtual FurnitureMark* GetFurnitureMarkerData() const; // RTTI slot 309

    virtual bool IsFirstActorFlagSet() const; // RTTI slot 275

    virtual bool IsAdditionalActorFlagSet() const; // RTTI slot 277

    virtual void CastSpellOnCaster(MagicCaster* apCaster, SpellItem* apAbility, bool abLoadCast); // RTTI slot 240
    virtual void CastSpellAtTarget(MagicCaster* apCaster, SpellItem* apDisease, MagicTarget* apTarget, bool abLoadCast); // RTTI slot 241
    virtual void SetPixelLightingProperty(BSShaderPPLightingProperty* apProp); // RTTI slot 319
    virtual NiNode* GetActorRootNode(BipedAnim* apAnim) const; // RTTI slot 100

    virtual void UpdateActorAppearance(bool abUpdateWeaponEffectShader, bool abInitializeActiveHitEffect, bool); // RTTI slot 352
    virtual bool ClearProcessStateFlags() const; // RTTI slot 215
    virtual SIT_SLEEP_STATE GetSitSleepState() const; // RTTI slot 303
    virtual MagicItem* GetSelectedMagicItem() const; // RTTI slot 242
    virtual void SetSelectedMagicItem(MagicItem* apSpell); // RTTI slot 243
    virtual void SetMagicTarget(MagicTarget* apTarget); // RTTI slot 245
    virtual bool UpdateIdleAnimation() const; // RTTI slot 246
    virtual bool ResetAlertState() const; // RTTI slot 106
    bool GetProcessState();
    bool SetProcessStateFlag();
    bool SetActorAlertState();
    virtual void Assign3DObject(NiAVObject* apNode); // RTTI slot 98
    virtual int GetCurrentProcedure() const; // RTTI slot 135
    virtual void SetCurrentProcedure(int aiOffset); // RTTI slot 136
    virtual bhkCharacterController* GetPhysicsCharacterController() const; // RTTI slot 163
    virtual void AssignCharacterController(NiPointer<bhkCharacterController> arController); // RTTI slot 164
    virtual void AddDeferredHideLimb(ObjectToAcquire* apObject); // RTTI slot 78
    virtual void SetFaceAnimationData(ObjectToAcquire* apObject); // RTTI slot 80
    KNOCK_STATE_ENUM StopIdleAnimation();
    virtual bool IsProcessStateInitialized() const; // RTTI slot 351
    virtual void InitializeProcessState(); // RTTI slot 22
    virtual void ResetActorModel(RESET_3D_FLAGS aucFlag); // RTTI slot 282
    virtual void ClearDetectionFlag(); // RTTI slot 284
    virtual BSSimpleList<ArrowProjectile*>* GetArrowProjectiles() const; // RTTI slot 428
    virtual bool IsAlert() const; // RTTI slot 257
    bool IsHoldingWeapon();
    virtual void SetSustainedState(bool abVal); // RTTI slot 440
    virtual void SetIdleAnimationPlayed(bool abVal); // RTTI slot 354
    virtual void SetPlayedState(bool abVal); // RTTI slot 356
    virtual bool WasIdleAnimationPlayed() const; // RTTI slot 357
    virtual LipSyncAnimation* GetLipSyncAnimationData() const; // RTTI slot 466
    virtual float GetAnimationElapsedTime() const; // RTTI slot 471
    virtual void AdvanceMovementTimer(float afVal); // RTTI slot 472
    virtual float GetAnimationRemainingTime() const; // RTTI slot 473
    virtual void SetKnockdownStage(int aiStage); // RTTI slot 483
    virtual void AttachFaceGenerationNode(BSFaceGenNiNode* apNode); // RTTI slot 485
    virtual BSFaceGenNiNode* GetFaceGenHeadNode() const; // RTTI slot 486
    virtual void SetFaceGenHeadNode(BSFaceGenNiNode* apNode); // RTTI slot 487
    virtual NiAVObject* GetAnimationObject() const; // RTTI slot 488
    virtual NiNode* GetActorSceneObject() const; // RTTI slot 438
    virtual NiNode* GetSceneRoot() const; // RTTI slot 97
    void SetCurrentIdle(TESIdleForm*);
    virtual BooleanFloatQuery* RefreshActorRuntimeData() const; // RTTI slot 476
    virtual void SetAnimationNode(NiAVObject* apObject); // RTTI slot 489
    virtual BSFaceGenNiNode* GetFacialAnimationNode() const; // RTTI slot 484
    virtual bool IsActorInCombat() const; // RTTI slot 383
    void SetBoundingBox(BSBound*);
    virtual bool IsAnimationPlaying() const; // RTTI slot 107
    virtual Animation* GetAnimation() const;
 // RTTI slot 110
    virtual void AssignEffectShader(TESEffectShader* apShader); // RTTI slot 350
    virtual void UpdateEffectShader(unsigned int auiTime); // RTTI slot 467
    virtual float GetLightIntensity() const; // RTTI slot 363
    BSBound* GetObjectBounds();
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() const; // RTTI slot 238
    virtual float GetVisibilityAlpha() const; // RTTI slot 273
    virtual ActorValue::Index GetWeaponForm() const; // RTTI slot 333
    virtual void SetRunOncePackageIndex(int aiIndex); // RTTI slot 134
    virtual ObjectToAcquire* GetObjectToAcquire() const; // RTTI slot 79
    void ReadAnimationState(BGSLoadFormBuffer*);
    virtual float GetThirdProcessFloat() const; // RTTI slot 365
    virtual bool BeginIdleAnimation() const; // RTTI slot 422
    virtual InventoryStackRecord* GetActiveWeapon() const; // RTTI slot 82
    virtual InventoryStackRecord* GetCurrentAmmo() const; // RTTI slot 83
    TESPackage* GetInterruptPackage();
    TESPackage* GetStablePackage();
    virtual DetectionViewData* GetDetectionState(Actor* apTarget, DetectionListType aeType) const; // RTTI slot 321
    bool HasMatchingQueuedItem(TESBoundObject*, ExtraDataList*, bool);
    void UpdateShotsPerSecond(bool);
    void SetLastHitData(BooleanFloatQuery*);
    void* GetRightWeaponBone(void*);
};
#pragma pack(pop)
