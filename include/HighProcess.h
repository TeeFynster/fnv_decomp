#pragma once

#include "MiddleHighProcess.h"
#include "BaseProcess.h"
#include "AnimIdle.h"
#include "BSSoundHandle.h"
#include "NiPoint3.h"

class Actor;
struct TopicX;
class ActorCombatGroup;
class ActorPathingMessageQueue;
class ActorValueStore;
class Animation;
class BGSLoadFormBuffer;
class BSAnimGroupSequence;
class DetectionEvent;
class DetectionEventData;
class DetectionParameters;
class DetectionViewData;
class DialogueItem;
class KFModel;
class LipSyncAnimation;
class MobileObject;
class MuzzleFlash;
class NiBSBoneLODController;
class NiNode;
class NiTexture;
class PathingAvoidNodeArray;
class SpellItem;
class TESActorBase;
class TESIdleForm;
class TESObjectREFR;
class TESObjectWEAP;
class TESPackage;
class TESTopic;
class TESTopicInfo;

enum ACTOR_AGGRESSION;
enum ACTOR_SOUND_HANDLE;

#pragma pack(push, 4)
class HighProcess : public MiddleHighProcess
{
public:
    BSSimpleList<TESTopicInfo*>* pDetectionEventList;        // +0x25c
    BSSimpleList<TESTopicInfo*>* m_pDetectionEventList;      // +0x260
    BSSimpleList<TESTopicInfo*>* m_pAuxiliaryList;           // +0x264
    BSSimpleList<TESTopicInfo*>* m_pDetectionList;           // +0x268
    BSSimpleList<TESTopicInfo*>* m_pSecondaryDetectionList;  // +0x26c
    bool m_bHasActorGroupState;                              // +0x270
    unsigned char layoutGap_271[3];
    BSSimpleList<TESTopicInfo*> m_kPrimaryDetectionList;    // +0x274
    BSSimpleList<TESTopicInfo*> m_kActorGroupStateList;     // +0x27c
    BSSimpleList<TESTopicInfo*> m_kSecondaryDetectionList;  // +0x284
    BSSimpleList<TESTopicInfo*> m_kActorGroupEntries;       // +0x28c
    float m_fFirstDialogueValue;                            // +0x294
    float m_fSecondDialogueValue;                           // +0x298
    bool m_bDialogueStateEnabled;                           // +0x29c
    bool m_bHasSavedTarget;                                 // +0x29d
    unsigned char layoutGap_29e[2];
    float m_fSavedTargetDistance;             // +0x2a0
    TESObjectREFR* m_pSavedTargetReference;   // +0x2a4
    float m_fFirstReferenceTimer;             // +0x2a8
    TESObjectREFR* m_pTrackedReference;       // +0x2ac
    float m_fAnimationScale;                  // +0x2b0
    float m_fAnimationBlendValue;             // +0x2b4
    float m_fSecondAnimationValue;            // +0x2b8
    float m_fFirstAnimationValue;             // +0x2bc
    short m_sFirstIndex;                      // +0x2c0
    short m_sSecondIndex;                     // +0x2c2
    short m_sThirdIndex;                      // +0x2c4
    bool m_bImpactState;                      // +0x2c6
    bool m_kFirstAdditionalHighProcessField;  // +0x2c7
    float m_fImpactValue;                     // +0x2c8
    NiNode* pNode;                            // +0x2cc
    float m_fImpactForceScale;                // +0x2d0
    float m_fImpactForce;                     // +0x2d4
    float fElapsedAnimationTime;              // +0x2d8
    char m_cDialogueState;                    // +0x2dc
    unsigned char layoutGap_2dd[3];
    float m_fAnimationTimer;                      // +0x2e0
    NiBSBoneLODController* m_pBoneLODController;  // +0x2e4
    int m_iAnimationGroup;                        // +0x2e8
    short m_sAnimationSequenceGroup;              // +0x2ec
    unsigned char layoutGap_2ee[2];
    BSAnimGroupSequence* m_pAnimationSequence;  // +0x2f0
    bool m_bAnimationActive;                    // +0x2f4
    unsigned char layoutGap_2f5[3];
    float m_fSocialTalkDelay;  // +0x2f8
    short m_sAnimationState;   // +0x2fc
    unsigned char layoutGap_2fe[2];
    NiPoint3 m_kSocialTalkPosition;      // +0x300
    TESObjectREFR* m_pSocialTalkTarget;  // +0x30c
    float m_fReferenceTimer;             // +0x310
    BSSoundHandle AudioPlaybackHandle[2];        // +0x314
    bool iProcessIndex;                  // +0x32c
    unsigned char layoutGap_32d[3];
    float m_fFirstProcessValue;   // +0x330
    float m_fSecondProcessValue;  // +0x334
    float m_fAwarenessDelay;      // +0x338
    float m_fAwarenessValue;      // +0x33c
    bool bCanDetectAlert;         // +0x340
    unsigned char layoutGap_341[3];
    float m_fFirstSerializedValue;  // +0x344
    bool m_bAlertState;             // +0x348
    bool bWeaponAlertDrawn;         // +0x349
    unsigned char layoutGap_34a[2];
    float fAwarePlayerTimer;                  // +0x34c
    TESIdleForm* iAnimationStateCode;         // +0x350
    NiPointer<NiTexture> iLocalValue[2];      // +0x354
    NiPointer<KFModel> m_kKeyframeModels[2];  // +0x35c
    bool m_bSpellState;                       // +0x364
    unsigned char layoutGap_365[3];
    DialogueItem* pOwnedObject;        // +0x368
    DIALOGUE_EMOTION m_iProcessState;  // +0x36c
    MobileObject* m_pSavedReference;   // +0x370
    bool m_bSavedReferenceFlag;        // +0x374
    bool m_bDialogueFlag;              // +0x375
    unsigned char layoutGap_376[2];
    float m_fDialogueDelay;                                   // +0x378
    float m_fFirstDialogueParameter;                          // +0x37c
    NiPointer<NiTexture> m_kSixthAdditionalHighProcessField;  // +0x380
    float fCurrentValue;                                      // +0x384
    float m_fSecondDialogueParameter;                         // +0x388
    BSSimpleList<TESTopicInfo*> m_kPrimaryTopicList;          // +0x38c
    BSSimpleList<TESTopicInfo*> m_kSecondaryTopicList;        // +0x394
    int m_iDialogueTopicCount;                                // +0x39c
    bool bStop;                                               // +0x3a0
    unsigned char layoutGap_3a1[3];
    float m_fThirdDialogueParameter;  // +0x3a4
    bool fScale;                      // +0x3a8
    unsigned char layoutGap_3a9[3];
    int m_iFirstSpellIndex;                   // +0x3ac
    int m_iSecondSpellIndex;                  // +0x3b0
    BSSimpleList<SpellItem*>* m_pkSpellList;  // +0x3b4
    char iValue;                              // +0x3b8
    bool iLocalState;                         // +0x3b9
    unsigned char layoutGap_3ba[2];
    float m_fFirstLipSyncParameter;       // +0x3bc
    float m_fSecondLipSyncParameter;      // +0x3c0
    float m_fLipSyncTimer;                // +0x3c4
    float m_fLipSyncValue;                // +0x3c8
    LipSyncAnimation* pLipSyncAnimation;  // +0x3cc
    bool m_bLipSyncEnabled;               // +0x3d0
    bool m_bLipSyncPlaying;               // +0x3d1
    unsigned char layoutGap_3d2[2];
    MuzzleFlash* m_pMuzzleFlash;        // +0x3d4
    unsigned int m_uiMuzzleFlashIndex;  // +0x3d8
    DetectionEvent* m_pDetectionEvent;  // +0x3dc
    bool m_bTrackedReferenceFlag;       // +0x3e0
    unsigned char layoutGap_3e1[3];
    DialogueItem* m_pQueuedDialogueItem;               // +0x3e4
    BaseProcess::FADE_STATE m_iSecondSerializedValue;  // +0x3e8
    float fFadeAlpha;                                  // +0x3ec
    TESObjectREFR* m_pFadeReference;                   // +0x3f0
    DetectionEventData* pDetectionEventData;           // +0x3f4
    TESObjectREFR* m_pRecentReferences[6];             // +0x3f8
    bool m_bReferenceFlags[6];                         // +0x410
    unsigned char layoutGap_416[2];
    float m_fReferencePriority;  // +0x418
    TESObjectREFR* coordinate;   // +0x41c
    bool m_bDetectionFlag;       // +0x420
    unsigned char layoutGap_421[3];
    BaseProcess::POSTANIM_ACTION m_ePendingPostAnimationActions;  // +0x424
    ActorValueStore* m_pRevertibleObject;                         // +0x428
    float m_kSecondAdditionalHighProcessField;                    // +0x42c
    int m_iDialogueState;                                         // +0x430
    NiPointer<NiTexture> m_kNinthAdditionalHighProcessField;      // +0x434
    float m_kThirdAdditionalHighProcessField;                     // +0x438
    float m_fFirstReferenceValue;                                 // +0x43c
    float m_fSecondReferenceValue;                                // +0x440
    bool iCount;                                                  // +0x444
    bool pTargetObject;                                           // +0x445
    unsigned char layoutGap_446[2];
    float m_fDialogueTimer;                          // +0x448
    BSSimpleList<TESTopicInfo*>* m_pkTopicInfoList;  // +0x44c
    float m_fDialogueConditionValue;                           // +0x450
    DialogueItem* m_pCurrentDialogueItem;            // +0x454
    bool bHasSubtitle;                               // +0x458
    bool m_bSubtitleActive;                          // +0x459
    unsigned char layoutGap_45a[2];
    NiPointer<NiTexture> m_kEighthAdditionalHighProcessField;                  // +0x45c
    NiPointer<NiTexture> m_kFifthAdditionalHighProcessField;                   // +0x460
    NiPointer<ActorPathingMessageQueue> m_kSeventhAdditionalHighProcessField;  // +0x464
    NiPointer<ActorPathingMessageQueue> m_kFourthAdditionalHighProcessField;   // +0x468

    void Revert(BGSLoadFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void ClearAndDeleteList();
    bool ClearProcessState(Actor*);
    void ProcessActorWithFlag(Actor*, bool);
    bool HighProcess_DoesFadeProhibitAction();
    void EvaluateBoneLod(Actor*);
    void HighProcess_FadeAndDisable(Actor*);
    void Projectile_ProcessMovement(float);
    void ProcessMovement(float);
    void HighProcess_FadeOut(Actor*, int, int);
    // called non-virtually by Update (0x008eeec0), addresses from the original's call targets
    void ProcessWarning(Actor*);                  // 0x008db240
    void SelectTarget(Actor*);                  // 0x008db4f0
    void ProcessAlertSearch(Actor*);                  // 0x008dd8e0
    void ProcessSearchforTarget(Actor*);                  // 0x008dd980
    void UpdatePathing(Actor*);                 // 0x008df060
    bool ShouldWaitForEscortTarget(Actor*, Actor*, void*, bool*); // 0x008df1e0
    void ProcessActorMovement(Actor*);          // 0x008e7c70
    bool HighProcess_GetSkippedLastUpdate();                        // 0x008f21a0
    void ProcessTakeBackItem(Actor*);                  // 0x008f21f0
    void HighProcess_SayGoodBye(Actor*);                  // 0x00901740
    bool MiddleHighProcess_DidPathingFail(Actor*);                  // 0x00915ef0
    bool UpdateFurnitureAlignment(Actor*);      // 0x00921350
    void MiddleHighProcess_PickPackageIdles(Actor*, bool);            // 0x00929960
    void MiddleHighProcess_ClearFurnitureMarker();                        // 0x0092c680 (ProcessActivate 0x008e9640)
    // overrides defined in highprocess.cpp (slots from the RTTI vftable)
    virtual bool IsValidCombatTarget(Actor* apActor, Actor* apTarget); // RTTI slot 129                               // 0x00904c80
    virtual bool IsActorDetected(Actor* apActor, Actor* apTarget, DetectionListType aeType); // RTTI slot 180   // 0x008f68f0
    virtual void ProcessNotify(Actor*); // RTTI slot 514                                             // 0x008dd8a0
    virtual void RefreshActorValues(Actor* apActor); // RTTI slot 229                                        // 0x008daef0
    virtual NiPoint3 GetActorNodePosition(Actor* apActor, DetectionListType aeType); // RTTI slot 7  // 0x008f6820
    virtual bool IsActorTargetValid(Actor* apActor, Actor* apTarget) const; // RTTI slot 127                          // 0x008ee370
    virtual const char* GetCurrentPackageName() const; // RTTI slot 416                              // 0x009016a0
    virtual void vfn_868(Actor*, Actor*); // RTTI slot 538                                           // 0x00901c70 (slot 538)
    virtual void ProcessAvoidRadiation(Actor*); // RTTI slot 506                                     // 0x00904540 (slot 506)
    virtual bool CanAttackTarget(Actor* apActor, Actor* apTarget) const; // RTTI slot 126                             // 0x00901990
    virtual bool IsCombatTargetForActor(Actor* apActor, Actor* apTarget) const; // RTTI slot 125                      // 0x00901800
    virtual bool vfn_850(Actor*, Actor*); // RTTI slot 532                                           // 0x00901a20 (slot 532)
    virtual bool vfn_80c(Actor*, int); // RTTI slot 515                                              // 0x008ee220 (slot 515)
    virtual void ProcessAlarm(Actor*); // RTTI slot 497                                              // 0x008ecf20 (slot 497)
    virtual void vfn_84c(Actor*, const NiPoint3*, float); // RTTI slot 531                           // 0x008ed420 (slot 531)
    virtual void ProcessAcquire(Actor*); // RTTI slot 500                                            // 0x008ebc60 (slot 500)
    void LowProcess_ProcessKill(Actor*);                                              // 0x008ebbe0
    virtual int GetDetectionCount(Actor* apTarget, DetectionListType aeType) const; // RTTI slot 181   // 0x008f6990 (slot 181)
    virtual void ClearPackageData(); // RTTI slot 400                                                // 0x009010f0 (slot 400)
    virtual void ProcessActorReferences(Actor* apActor, Actor* apTarget, Actor* apAlly); // RTTI slot 387                    // 0x00904000 (slot 387)
    void CleanUpAfterProcessUseWeapon(Actor*);                                              // 0x008f9180
    void MiddleHighProcess_ClearShootingAction(Actor*);                                              // 0x0092bf20
    bool FUN_008e7c00();                                                    // 0x008e7c00
    virtual void UpdateActorPackage(Actor* apActor, bool abFlag, unsigned int aeMoveMode, bool abPursuit); // RTTI slot 166              // 0x008e0f80 (slot 166)
    virtual bool vfn_840(Actor*); // RTTI slot 528                                                   // 0x008e8600 (slot 528)
    virtual void ProcessAmbushWait(Actor*); // RTTI slot 501                                         // 0x008ee3e0 (slot 501)
    virtual void vfn_7b4(Actor*); // RTTI slot 493                                                   // 0x008dfa10 (slot 493)
    virtual void ProcessAccompany(Actor*); // RTTI slot 499                                          // 0x008e0b00 (slot 499)
    bool CheckTargetAndCombat(Actor*, float, bool);                         // 0x008f31d0
    bool ProcessEscortOneHour(Actor*, float);                                       // 0x008f2610
    virtual void ProcessCannibal(Actor* apActor);                           // slot 32 override, 0x00904da0
    virtual int GetActorReferenceState(Actor* apActor, TESObjectREFR* apTarget);   // slot 185 override, 0x008f6ef0
    void ClearNode();                                                       // 0x008e56b0
    int PlayerCharacter_GetNumberOfFollowers();                                                     // 0x00962620
    virtual void FinishDying(Actor* apActor); // RTTI slot 213                                               // 0x008f7350 (slot 213)
    void SelectMoveTarget(Actor*, void*, bool);                             // 0x009026c0
    void HighProcess_SayGuardWarning(Actor*, void*);                                       // 0x00902bd0
    virtual void ProcessGuard(Actor*); // RTTI slot 509                                              // 0x00902290 (slot 509)
    virtual bool ProcessUseItemAt(Actor*); // RTTI slot 502                                          // 0x008f9320 (slot 502)
    void MiddleHighProcess_FindBedChairs(Actor*, int, int);                                    // 0x00922670
    ActorPackageData* FUN_008d0430();                                       // 0x008d0430
    void HighProcess_ProcessGuardStartTravelToLocation(Actor*, void*);                                       // 0x00902640
    void HighProcess_ProcessGuardWaitToAttack(Actor*, void*);                                       // 0x00902c80
    virtual unsigned int GetAttackChance(Actor* apActor, float afDistanceSq, float afShortDistSq, float afLongDistSq, bool abAlarmOrCombat, bool abPureTravel) const; // RTTI slot 211 // 0x008daa20 (slot 211)
    virtual bool ShouldAttackTarget(Actor*, Actor*, bool, bool, ActorCombatGroup*, bool, bool, bool, bool, bool, bool, bool, TESPackage*); // RTTI slot 207                                   // 0x009001c0 (slot 207)
    void FUN_004534f0(Actor*);                  // 0x004534f0 (shared empty body; a direct base-slot call in the original)
    virtual void Update(MobileObject* apObject); // RTTI slot 4
    virtual bool ProcessActivate(Actor*, bool); // RTTI slot 498
    virtual void UpdateActorStateWithOptions(Actor* apActor, bool abNewPackage, bool abIterateIndex, unsigned int aeMoveMode, bool abSecondLoc); // RTTI slot 175   // 0x008e5e90 (override)
    virtual void ProcessDialogueTopic(Actor* apActor, TESTopic* apTopic, bool abForceSub, bool abStop, bool abQueue, bool abSayCallBack); // RTTI slot 169
    virtual void RunDetection(Actor* apActor, float afTimeDelta); // RTTI slot 188
    bool IsActorFriendlyToActor(Actor*, Actor*);
    bool CanDetectTarget(Actor*, Actor*);
    virtual bool ShouldProcessActor(Actor* apActor); // RTTI slot 26
    virtual void ProcessEat(Actor*, TESForm*); // RTTI slot 495
    void ActorEntity(TESObjectREFR*, Actor*, bool&, DetectionParameters*, ACTOR_AGGRESSION, float, float);
    bool HasGroupEntry(ActorCombatGroup*);
    void ProcessDetectionTarget(Actor*, Actor*);
    HighProcess();
    void RefreshActorState(Actor*);
    virtual bool IsCurrentPackageTarget(Actor* apActor); // RTTI slot 128
    virtual void ProcessActorGroupState(Actor* apActor); // RTTI slot 27
    virtual bool StartIdleAnimation(Actor* apActor, TESIdleForm* apIdle, ANIM_IDLE_PLAY_TYPE aeDefaultAction, bool abCrippled, bool abForce, bool abTestConditions); // RTTI slot 17
    virtual void PlayRandomIdle(Actor* apActor); // RTTI slot 53
    bool CanProcessActor(Actor*, bool);
    virtual void UpdateReferenceTime(Actor* apActor, float afTimeDelta); // RTTI slot 448
    virtual void SetActorDetectionLevel(Actor* apActor, DetectionListType aeType); // RTTI slot 177
    virtual DetectionViewData* FindDetectionRecord(Actor* apActor, DETECTION_LEVEL aeDetectionLevel, bool abLineSight, int aiLevel, DetectionListType aeType, bool ab360View, bool abInCombat); // RTTI slot 60
    virtual void OnPackageChanged(Actor* apActor, TESPackage* apPackage); // RTTI slot 358
    unsigned int UpdateHighProcessState(Actor*);
    virtual void UpdateActorReferences(Actor* apActor); // RTTI slot 451
    float GetCurrentActorValue(TESActorBase*, ActorValue::Index, Actor*);
    virtual PathingAvoidNodeArray* GetPathingAvoidNodeArray(Actor* apActor); // RTTI slot 149
    virtual void StopActorSound(unsigned int aeType); // RTTI slot 293
    void AlterActorValue(Actor*, ActorValue::Index, float);
    virtual void OnPackageStart(Actor*, TESPackage*);
    virtual void OnPackageEnd(Actor* apActor, TESPackage* apPackage); // RTTI slot 360
    void RefreshTargetState();
    virtual bool IsTalking(MobileObject* apTarget) const; // RTTI slot 302   // 0x008f6fc0: override of BaseProcess slot 302
    virtual void ProcessActorIdle(Actor* apActor); // RTTI slot 54
    virtual void ResetCurrentPackage(); // RTTI slot 145
    void ClearTrackedActorEntries();
    virtual void SetActorDetectionState(Actor* apActor, unsigned int aeMoveMode, bool abCheckAlwaysRun); // RTTI slot 212
    virtual DetectionViewData* GetDetectionState(Actor* apTarget, DetectionListType aeType) const; // RTTI slot 321
    virtual void RestorePreviousReference(bool abHoldDefault); // RTTI slot 404
    virtual void ClearCachedTargetReferences(bool abHoldDefault); // RTTI slot 401
    virtual void SetCombatActive(bool abHoldDefault); // RTTI slot 402
    virtual void ClearDetectionEvents(); // RTTI slot 65
    virtual void ClearPackageObjectList(); // RTTI slot 204
    virtual void ClearDialogueItems(); // RTTI slot 137
    virtual bool HasNoPendingEntriesAndExpired(); // RTTI slot 410
    virtual void ClearMuzzleFlash(); // RTTI slot 433
    virtual bool IsActorVisibleToActor(Actor* apActor, Actor* apTarget, DetectionListType aeType, bool abFullTest); // RTTI slot 179 // slot 179 override, 0x008f6930
    void ResetTargetReferences();
    virtual TESObjectREFR* GetPrimaryTargetReference(); // RTTI slot 414
    virtual void ClearHighProcessState(TESObjectREFR* apTarget); // RTTI slot 397
    virtual void SetActorProcessState(TESObjectREFR* apTarget); // RTTI slot 394
    virtual void ClearIdleAnimation(); // RTTI slot 18
    void SetAnimation(Animation*);
    virtual bool HasNoPendingEntries(); // RTTI slot 411
    virtual void SetPreviousReference(TESObjectREFR* apTarget); // RTTI slot 393
    int GetActorValue(TESActorBase*, ActorValue::Index, Actor*);
    virtual bool CanUsePlayerAction(Actor* apActor) const; // RTTI slot 28
    virtual void StopActorMovement(Actor* apActor); // RTTI slot 165
    virtual void SetDiveBreathLevel(float afVal); // RTTI slot 297
    virtual void SetAnimAction(ProcessAnimationAction aeAnimationAction, BSAnimGroupSequence* apSequence); // RTTI slot 251
    virtual void UpdatePlayerAwarenessTimer(); // RTTI slot 406
    virtual void ResetDetectionState(); // RTTI slot 190
    virtual void AddPostAnimAction(PostAnimAction aeFlag); // RTTI slot 389
    virtual TESObjectREFR* GetCurrentHeadTrackTargetByType(HeadTrackType aeType); // RTTI slot 413
    virtual ProcessAnimationAction GetAnimAction() const; // RTTI slot 249
    virtual BSAnimGroupSequence* GetActorProcessTime() const; // RTTI slot 250
    float GetDeadTimer();
    int IsInDialogue();
    int GetSavedState();
    char* GetSavedToken();
    void RestoreSavedState(int, char*);

    virtual void SetProcessTarget(MobileObject* apTarget, int aiOffset); // RTTI slot 162
    int GetProcessLevel();
    virtual void SetActorSoundHandle(unsigned int aeType, BSSoundHandle akHandle); // RTTI slot 292
    virtual BSSoundHandle GetActorSoundHandle(unsigned int aeType); // RTTI slot 291
    virtual void StopAllActorSounds(); // RTTI slot 298
    virtual float GetProcessBlendAmount() const; // RTTI slot 120
    virtual unsigned int GetPostAnimationAction() const; // RTTI slot 390
    virtual MobileObject* GetMobileObject() const; // RTTI slot 42
    virtual float GetProcessBlendWeight() const; // RTTI slot 461
    virtual bool IsDetectionEnabled() const; // RTTI slot 182
    virtual TESIdleForm* GetSelectedIdleForm() const; // RTTI slot 454
    virtual FadeState GetCurrentFadeState() const; // RTTI slot 388
    virtual void ClearPostAnimActions(); // RTTI slot 391
    virtual NiObjectNET* GetMuzzleFlash() const; // RTTI slot 430
    float GetLightLevel();
    virtual void SetLightLevel(float afLightAmount); // RTTI slot 462
    void SetFloatProperty(float value);
    virtual float GetCurrentAlpha() const; // RTTI slot 407
    virtual float GetRadiationRate() const; // RTTI slot 205
    virtual void SetRadiationRate(float afValue); // RTTI slot 206
    virtual bool IsProcessStateActive() const; // RTTI slot 447
    virtual float GetControllerPhase() const; // RTTI slot 475
    virtual void UpdateActorLighting(float afVal); // RTTI slot 191
    virtual bool IsAsleep() const; // RTTI slot 30
    virtual double GetDetectionStrength();
    virtual bool IsCurrentlyDetected() const; // RTTI slot 385
    virtual bool IsDetecting() const; // RTTI slot 195
    virtual bool HasAssignedAnimation() const; // RTTI slot 312
    bool IsMovementStopped();
    virtual float GetDetectionProgress() const; // RTTI slot 153
    virtual void SetDetectionLevel(float afVal); // RTTI slot 154
    virtual DIALOGUE_EMOTION GetCurrentDialogueEmotion() const; // RTTI slot 186
    virtual bool GetPlantedExplosive() const; // RTTI slot 226
    virtual float UpdateProcessTiming() const; // RTTI slot 192
    virtual DetectionEvent* FindDetectionEventForActor(Actor* apActor); // RTTI slot 62
    virtual void SetEssentialFlag(bool abVal); // RTTI slot 52
    virtual void SetAnimationEnabled(bool abVal); // RTTI slot 313
    virtual float GetFirstProcessFloat() const; // RTTI slot 46
    virtual void SetCurrentDialogueItem(DialogueItem* apSubtitle); // RTTI slot 147
    virtual void SetIdleForm(TESIdleForm* apIdleForm); // RTTI slot 455
    void ResetMovementState();
    void SetSubtitleActive(bool value);
    virtual void SetActorProcessEnabled(bool abVal); // RTTI slot 183
    virtual LipSyncAnimation* GetLipSync() const; // RTTI slot 223
    virtual bool IsActorTalking() const; // RTTI slot 222
    virtual void SetDialogueState(bool abVal); // RTTI slot 220
    virtual void SetDialogueEmotion(DIALOGUE_EMOTION aeEmotion); // RTTI slot 187
    virtual void AssignLipSyncAnimation(LipSyncAnimation* apAnim); // RTTI slot 224
    virtual void SetLipSyncValue(float afVal); // RTTI slot 198
    virtual void SetTalkingState(bool abVal); // RTTI slot 221
    virtual void UpdateActorProcess(float afVal); // RTTI slot 301
    virtual TESObjectREFR* GetRelatedReference() const; // RTTI slot 419
    virtual TESObjectREFR* GetPreviousReference() const; // RTTI slot 289
    virtual bool HasCombatStarted(); // RTTI slot 201
    virtual bool IsCombatTargetValid() const; // RTTI slot 418
    virtual void SetActorTargetReference(TESObjectREFR* apRef); // RTTI slot 290
    bool CanFireWeapon();
    virtual DialogueItem* GetCurrentDialogueItem() const; // RTTI slot 146
    virtual void SetCombatEnabled(bool abVal); // RTTI slot 34
    virtual void SetCombatAlerted(bool abVal); // RTTI slot 196
    void RefreshProcessState(Actor*, TESObjectREFR*, float, float, float);
    void SetMaxAlpha(float fAlpha);
    virtual void* vf540();
    unsigned char FindSpecialIdletoPlay(Actor* actor, int param, Actor* target);   // 0x008ff0b0
    virtual void SetActorProcessTime(Actor* apActor, float afTimeDelta);   // slot 184: 0x00900830 (RTTI HighProcess vftable 0x01087864)
    virtual void vfn_800(Actor* apTarget);   // slot 512: 0x00900020 (RTTI HighProcess vftable 0x01087864)
    virtual bool ProcessUseWeapon(Actor* apActor);   // slot 503: 0x008f7730 (RTTI HighProcess vftable 0x01087864)
    bool UpdateCombatTarget(Actor* apActor, TESObjectREFR* apTarget, bool abForce);   // 0x008f74c0
    void UpdateActorBehavior(Actor* apActor);                                         // 0x008f9180
    virtual void ProcessFleeNonCombat(Actor* apActor); // slot 505: 0x008ddac0
    InventoryStackRecord* CreateWeaponAcquireList(Actor*, unsigned int); // 0x008eebf0
    virtual void RefreshActorMovement(Actor*, bool); // slot 119: 0x008f7070
    virtual void ProcessSandman(Actor*); // slot 31: 0x00904f50
    virtual bool CanPerformActorAction(Actor*, float); // slot 29: 0x008f3940
    virtual void vfn_818(Actor*); // slot 518: 0x008e2b00
    void HighProcess_SortObjectsListByType(); // 0x0091b580
    void HighProcess_SortObjectsListByValue(); // 0x0091b640
    void HandleActorInteraction(Actor*); // 0x008ec460
    void UpdateDialogue(Actor*, TopicX*, TESObjectREFR*, bool, bool, bool); // 0x008dbe30
    void UpdatePackageExecution(Actor*); // 0x008dddf0
    void Update_008f4020(Actor*, float); // 0x008f4020
    void HighProcess_ProcessAccombanyOneHour(Actor*, float); // 0x008e0ad0
    void FUN_0090dc60(Actor*, int, int, int); // 0x0090dc60: folded stack arguments
    void FUN_008f3fe0(Actor*, float); // 0x008f3fe0
    void FUN_008eeac0(Actor*); // 0x008eeac0
    void FUN_008f36c0(Actor*, float); // 0x008f36c0
    bool HighProcess_ProcessSleepOneHour(Actor*, float); // 0x008f3550
    bool FUN_008f3600(Actor*, float); // 0x008f3600
    void HighProcess_ProcessPatrolOneHour(Actor*, float); // 0x008f4000
    void ChangeWeapon(Actor* apActor, TESObjectWEAP* apWeapon);                       // 0x009037e0
};
#pragma pack(pop)
