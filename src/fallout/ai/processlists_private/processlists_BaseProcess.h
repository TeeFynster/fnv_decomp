// Unit-private PC virtual declarations from public JohnnyGuitar BaseProcess.hpp.
// Declarations/layout facts only; no community implementations or raw vtable substitute.
#ifndef FNV_BASEPROCESS_H
#define FNV_BASEPROCESS_H

#include "processlists_layout_support.h"
#include "processlists_ActorPackage.h"
#include "processlists_NiPoint3.h"
#include "processlists_actor_enums.h"
class ActiveEffect;
class AnimIdle;
class ArrowProjectile;
class Actor;
class BooleanFloatQuery;
class Animation;
class BGSBodyPartData;
class BGSLoadFormBuffer;
class BGSSaveGameBuffer;
class BSAnimGroupSequence;
class BSBound;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class PathingAvoidNodeArray;
class BSSoundHandle;
class BipedAnim;
class ActorCombatGroup;
class Crime;
class DetectionViewData;
class ExtraDataList;
class InventoryStackRecord;
class KFModel;
class MagicCaster;
class MagicItem;
class MagicTarget;
class MobileObject;
class MuzzleFlash;
class NiAVObject;
class NiNode;
class NiRefObject;
class NiTriShape;
class Projectile;
class SpellItem;
class TESActorBase;
class TESAmmo;
class TESEffectShader;
class TESIdleForm;
class TESObject;
class TESObjectCELL;
class TESObjectWEAP;
class TESTopic;
class TESWorldSpace;
class bhkCharacterController;
class NiControllerManager;
class TESPackageData;
class DialogueItem;
class DetectionEvent;
class ObjectToAcquire;
class LipSyncAnimation;
class TESBoundObject;
class TESObjectSTAT;
class WadingWaterData;
struct FurnitureMark;

class BaseProcess
{
  public:
    struct _DetectionListType
    {
        enum Type
        {
            BY_ME = 0,
            BY_OTHERS = 1,
        };
    };
    typedef _DetectionListType::Type DetectionListType;

    struct _PostAnimAction
    {
        enum Action
        {
            NONE = 0,
            FIRE_WEAPON = 1u << 0,
            RELOAD_WEAPON = 1u << 1,
            SIT_SLEEP = 1u << 2,
            GET_UP = 1u << 3,
            PLAY_IDLE = 1u << 4,
            DIE = 1u << 5,
            EQUIP_UNEQUIP_WEAPON = 1u << 6,
            PICK_IDLE_CALL = 1u << 7,
            HAND_GRIP_WEAPON = 1u << 8,
            GET_OUT_OF_FURNITURE = 1u << 9,
            FORCE_IDLE_ANIMATION = 1u << 10,
            FREE_SPECIAL_IDLE = 1u << 11,
            RELOAD_TARGETS = 1u << 12,
            IDLE_LOADED = 1u << 13,
            HAVOK_WEAPON = 1u << 14,
            BLOCK = 1u << 15,
            SET_IRON_SIGHTS = 1u << 16,
            EXPEL_SHELLCASING = 1u << 17,
            RELOAD_SINGLE = 1u << 18,
            START_LOOPING_RELOAD = 1u << 19,
        };
    };
    typedef _PostAnimAction::Action PostAnimAction;

    struct _FadeState
    {
        enum State
        {
            FADE_NORMAL = 0,
            FADE_IN = 1,
            FADE_OUT = 2,
            FADE_TELEPORT_IN = 3,
            FADE_TELEPORT_OUT = 4,
            FADE_OUT_DISABLE = 5,
            FADE_OUT_DELETE = 6,
            FADE_MOVE_TO_MARKER = 7,
            COUNT = 8,
        };
    };
    typedef _FadeState::State FadeState;

    struct _HeadTrackType
    {
        enum Type
        {
            DEFAULT = 0,
            ACTION = 1,
            COMBAT = 2,
            DIALOG = 3,
            SCRIPT = 4,
            PROCEDURE = 5,
            COUNT = 6,
        };
    };
    typedef _HeadTrackType::Type HeadTrackType;

    virtual ~BaseProcess();                                                           // PC vtable +0x000
    virtual void Copy(BaseProcess* apSource);                                         // PC vtable +0x004
    virtual void SetReferenceTarget(Actor* apActor);                                  // PC vtable +0x008
    virtual void UpdateAlt(MobileObject* apObject, float afDelta);                    // PC vtable +0x00C
    virtual void Update(MobileObject* apObject);                                      // PC vtable +0x010
    virtual void SetMobileObjectState(MobileObject* apObject, bool abActionflag);     // PC vtable +0x014
    virtual NiPoint3 GetActorWorldPosition(Actor* apActor);                           // PC vtable +0x018
    virtual NiPoint3 GetActorNodePosition(Actor* apActor, DetectionListType aeType);  // PC vtable +0x01C
    virtual double GetActorValueAtIndex(Actor* apActor, DetectionListType aeType);    // PC vtable +0x020
    virtual bool CheckForNewPackage(Actor* apActor, bool abFlag);                     // PC vtable +0x024
    virtual void ResetPackageState();                                                 // PC vtable +0x028
    virtual bool IsLowProcessStateValid() const;                                      // PC vtable +0x02C
    virtual unsigned int GetPackedStateBits0To8() const;                              // PC vtable +0x030
    virtual unsigned int GetPackedStateBits9To12() const;                             // PC vtable +0x034
    virtual unsigned int GetPackedStateBits13To26() const;                            // PC vtable +0x038
    virtual void SetProcessInteger(int aiVal);                                        // PC vtable +0x03C
    virtual int GetProcessInteger() const;                                            // PC vtable +0x040
    virtual bool StartIdleAnimation(Actor* apActor, TESIdleForm* apIdle, ANIM_IDLE_PLAY_TYPE aeDefaultAction,
                                    bool abCrippled, bool abForce, bool abTestConditions);        // PC vtable +0x044
    virtual void ClearIdleAnimation();                                                            // PC vtable +0x048
    virtual MagicItem* GetCurrentMagicItem() const;                                               // PC vtable +0x04C
    virtual void SetCurrentMagicItem(MagicItem* apSpell);                                         // PC vtable +0x050
    virtual void SetActorMagicItem(Actor* apActor, int aiRounds);                                 // PC vtable +0x054
    virtual void InitializeProcessState();                                                        // PC vtable +0x058
    virtual void UpdateHealthBar(Actor* apActor);                                                 // PC vtable +0x05C
    virtual bool GetIdleDoneOnce() const;                                                         // PC vtable +0x060
    virtual void MarkIdleDoneOnce(bool abVal);                                                    // PC vtable +0x064
    virtual bool ShouldProcessActor(Actor* apActor);                                              // PC vtable +0x068
    virtual void ProcessActorGroupState(Actor* apActor);                                    // PC vtable +0x06C
    virtual bool CanUsePlayerAction(Actor* apActor) const;                                        // PC vtable +0x070
    virtual bool CanPerformActorAction(Actor apActor, float afTimeDelta);                         // PC vtable +0x074
    virtual bool IsAsleep() const;                                                                // PC vtable +0x078
    virtual void ProcessSandman(Actor* apActor);                                                  // PC vtable +0x07C
    virtual void ProcessCannibal(Actor* apActor);                                                 // PC vtable +0x080
    virtual void ProcessFurniture(Actor* apActor);                                                // PC vtable +0x084
    virtual void SetCombatEnabled(bool abVal);                                                    // PC vtable +0x088
    virtual bool FindPackageTarget(Actor* apActor);                                               // PC vtable +0x08C
    virtual bool GetPackageLocationReference(Actor* apActor);                                     // PC vtable +0x090
    virtual TESObjectREFR* GetActorTargetReference(Actor* apActor, bool abInterrupt);             // PC vtable +0x094
    virtual NiPoint3* GetActorTargetPosition(NiPoint3& arPos, Actor* apActor, bool abInterrupt);  // PC vtable +0x098
    virtual TESObjectCELL* GetTargetCell(Actor* apActor);                                         // PC vtable +0x09C
    virtual TESWorldSpace* GetTargetWorldSpace(Actor* apActor);                                   // PC vtable +0x0A0
    virtual float GetTargetDistance(Actor* apActor);                                              // PC vtable +0x0A4
    virtual MobileObject* GetMobileObject() const;                                                // PC vtable +0x0A8
    virtual void AdvanceProcess();                                                                // PC vtable +0x0AC
    virtual bool EvaluateActorPackage(Actor* apActor, TESPackage* apPackage, bool abInCombat);    // PC vtable +0x0B0
    virtual bool FindPackageToEvaluate(Actor* apActor, TESPackage*& apPackage);                   // PC vtable +0x0B4
    virtual float GetFirstProcessFloat() const;                                                   // PC vtable +0x0B8
    virtual void SetCurrentSpeed(float afValue);                                                  // PC vtable +0x0BC
    virtual void EvaluateCurrentPackage(Actor* apActor);                                          // PC vtable +0x0C0
    virtual void SelectPackage(Actor* apActor, bool abInterateIndex);                             // PC vtable +0x0C4
    virtual void SetPackageForActor(Actor* apActor, TESPackage* apPackage, bool abCheck);         // PC vtable +0x0C8
    virtual bool HasInterruptPackage() const;                                                     // PC vtable +0x0CC
    virtual void SetEssentialFlag(bool abVal);                                                    // PC vtable +0x0D0
    virtual void PlayRandomIdle(Actor* apActor);                                                  // PC vtable +0x0D4
    virtual void ProcessActorIdle(Actor* apActor);                                                // PC vtable +0x0D8
    virtual void PlayIdleAnimation();                                                             // PC vtable +0x0DC
    virtual void ClearAnimationState();                                                           // PC vtable +0x0E0
    virtual float GetEssentialDownTimer() const;                                                  // PC vtable +0x0E4
    virtual void SetEssentialDownTimer(float afValue);                                            // PC vtable +0x0E8
    virtual void ResetEssentialDownTimer();                                                       // PC vtable +0x0EC
    virtual DetectionViewData* FindDetectionRecord(Actor* apActor, DETECTION_LEVEL aeDetectionLevel, bool abLineSight,
                                                   int aiLevel, DetectionListType aeType, bool ab360View,
                                                   bool abInCombat);     // PC vtable +0x0F0
    virtual BSSimpleList<DetectionViewData*>* GetDetectingActors();      // PC vtable +0x0F4
    virtual DetectionEvent* FindDetectionEventForActor(Actor* apActor);  // PC vtable +0x0F8
    virtual void AddDetectionEvent(Actor* apActor, NiPoint3 akPosition, SOUND_LEVEL aeSoundLevel,
                                   int aiDetectionEventType, TESObjectREFR* apRef);               // PC vtable +0x0FC
    virtual void RemoveDetectionEvent();                                                          // PC vtable +0x100
    virtual void ClearDetectionEvents();                                                          // PC vtable +0x104
    virtual void GetWeaponScore();                                                                // PC vtable +0x108
    virtual void SetWeaponScore(float afVal);                                                     // PC vtable +0x10C
    virtual bool HasCaughtPlayerPickpocketing() const;                                            // PC vtable +0x110
    virtual void SetIsWeaponReady();                                                              // PC vtable +0x114
    virtual void SetAnimationComplete(bool abVal);                                                // PC vtable +0x118
    virtual bool IsMovementComplete() const;                                                      // PC vtable +0x11C
    virtual void SetCurrentMovementComplete(bool abVal);                                          // PC vtable +0x120
    virtual bool GetCurrentMovementComplete() const;                                              // PC vtable +0x124
    virtual TESObjectREFR* GetTarget() const;                                                     // PC vtable +0x128
    virtual void SetTarget(TESObjectREFR* apTarget);                                              // PC vtable +0x12C
    virtual TESObjectREFR* GetDoor() const;                                                       // PC vtable +0x130
    virtual void SetDoor(TESObjectREFR* apDoor);                                                  // PC vtable +0x134
    virtual void AddDeferredHideLimb(ObjectToAcquire* apObject);                                  // PC vtable +0x138
    virtual ObjectToAcquire* GetObjectToAcquire() const;                                          // PC vtable +0x13C
    virtual void SetFaceAnimationData(ObjectToAcquire* apObject);                                 // PC vtable +0x140
    virtual BSFaceGenAnimationData* GetActorFaceGenData();                                        // PC vtable +0x144
    virtual InventoryStackRecord* GetActiveWeapon() const;                                                  // PC vtable +0x148
    virtual InventoryStackRecord* GetCurrentAmmo() const;                                                   // PC vtable +0x14C
    virtual bool GetLipQueued() const;                                                            // PC vtable +0x150
    virtual void SetLipQueued(bool abVal);                                                        // PC vtable +0x154
    virtual unsigned int GetPackageObjectType() const;                                            // PC vtable +0x158
    virtual void SetPackageObjectType(unsigned int auiCount);                                     // PC vtable +0x15C
    virtual bool SetCurrentArmor(InventoryStackRecord* apWeapon, NiNode* apScene, bool abForce);            // PC vtable +0x160
    virtual void SetCurrentTorch(InventoryStackRecord* apTorch);                                            // PC vtable +0x164
    virtual bool SetCurrentAmmunition(InventoryStackRecord* apAmmo);                                        // PC vtable +0x168
    virtual void SetCurrentShield(InventoryStackRecord* apShield);                                          // PC vtable +0x16C
    virtual void UpdateEquippedItems(Actor* apActor);                                             // PC vtable +0x170
    virtual bool IsItemQueued(TESBoundObject* apItem, ExtraDataList* apExtraList, bool abEquip);  // PC vtable +0x174
    virtual void ProcessEquipmentRequest(Actor* apActor, bool abEquip, TESBoundObject* apItem, int aiNumber,
                                         ExtraDataList* apExtraList, bool abNow, bool abForceEquip, bool abFromMenus,
                                         bool abForceUnequip, bool abEquipCalling,
                                         bool abPlaySound);                                    // PC vtable +0x178
    virtual void SetEquippedItem(TESBoundObject* apObject, ExtraDataList* apExtraList);        // PC vtable +0x17C
    virtual void ClearQueuedEquipItems();                                                      // PC vtable +0x180
    virtual NiNode* GetSceneRoot() const;                                                      // PC vtable +0x184
    virtual void Assign3DObject(NiAVObject* apNode);                                           // PC vtable +0x188
    virtual bool SetAnimationControllerManager(NiControllerManager* apControllerManager, NiNode* apNode);  // PC vtable +0x18C
    virtual NiNode* GetActorRootNode(BipedAnim* apAnim) const;                                 // PC vtable +0x190
    virtual NiNode* GetWeaponAttachNode(BipedAnim* apAnim) const;                              // PC vtable +0x194
    virtual NiNode* GetShieldBone(BipedAnim* apAnim) const;                                    // PC vtable +0x198
    virtual NiNode* GetQuiverBone(BipedAnim* apAnim) const;                                    // PC vtable +0x19C
    virtual NiNode* GetTorchAttachNode(BipedAnim* apAnim) const;                               // PC vtable +0x1A0
    virtual NiNode* GetLeftWeaponBone(BipedAnim* apAnim) const;                                // PC vtable +0x1A4
    virtual bool ResetAlertState() const;                                                      // PC vtable +0x1A8
    virtual bool IsAnimationPlaying() const;                                                   // PC vtable +0x1AC
    virtual bool IsAnimationActive() const;                                                    // PC vtable +0x1B0
    virtual bool IsAnimationSequenceActive() const;                                            // PC vtable +0x1B4
    virtual Animation* GetAnimation() const;                                                   // PC vtable +0x1B8
    virtual bool IsAnimationStateActive() const;                                               // PC vtable +0x1BC
    virtual void SetAnimationStateActive(bool abVal);                                          // PC vtable +0x1C0
    virtual bool IsProcessTaskComplete() const;                                                       // PC vtable +0x1C4
    virtual void SetProcessTaskComplete(bool abVal);                                           // PC vtable +0x1C8
    virtual void PlayAnimation(bool abDrawn, BipedAnim* apBipedAnim, Animation* apAnim,
                               Actor* apActor);                                      // PC vtable +0x1CC
    virtual void SetCurrentBoundObject(TESObject* apItem);                           // PC vtable +0x1D0
    virtual TESObject* GetCurrentBoundObject() const;                                // PC vtable +0x1D4
    virtual void RunActorProcessing(Actor* apActor);                                 // PC vtable +0x1D8
    virtual void RefreshActorMovement(Actor* apActor, bool abFlag);                  // PC vtable +0x1DC
    virtual float GetProcessBlendAmount() const;                                     // PC vtable +0x1E0
    virtual void SetAnimationTimer(float afVal);                                     // PC vtable +0x1E4
    virtual void SetCombatDelayFadeTimer(float afVal);                               // PC vtable +0x1E8
    virtual bool IsProcessConditionMet() const;                                      // PC vtable +0x1EC
    virtual void SelectActorCombatTarget(Actor* apActor);                            // PC vtable +0x1F0
    virtual bool IsCombatTargetForActor(Actor* apActor, Actor* apTarget) const;      // PC vtable +0x1F4
    virtual bool CanAttackTarget(Actor* apActor, Actor* apTarget) const;             // PC vtable +0x1F8
    virtual bool IsActorTargetValid(Actor* apActor, Actor* apTarget) const;          // PC vtable +0x1FC
    virtual bool IsCurrentPackageTarget(Actor* apActor);                             // PC vtable +0x200
    virtual bool IsValidCombatTarget(Actor* apActor, Actor* apTarget);               // PC vtable +0x204
    virtual float GetDistanceBetweenActors(Actor* apActor, Actor* apTarget);         // PC vtable +0x208
    virtual TESPackage* GetRunOncePackage() const;                                   // PC vtable +0x20C
    virtual void AssignRunOncePackage(TESPackage* apPackage, Actor* apActor);        // PC vtable +0x210
    virtual void StopRunOncePackage();                                               // PC vtable +0x214
    virtual void SetRunOncePackageIndex(int aiIndex);                                // PC vtable +0x218
    virtual int GetCurrentProcedure() const;                                         // PC vtable +0x21C
    virtual void SetCurrentProcedure(int aiOffset);                                  // PC vtable +0x220
    virtual void ClearDialogueItems();                                               // PC vtable +0x224
    virtual bool IsPackageRunningForActor(Actor* apActor) const;                     // PC vtable +0x228
    virtual TESPackage* GetCurrentPackage() const;                                   // PC vtable +0x22C
    virtual void SetCurrentPackageAndTarget(TESPackage* apPackage, Actor* apActor);  // PC vtable +0x230
    virtual void StopPackage();                                                      // PC vtable +0x234
    virtual void SetPackageInfoState(int aiIndex);                              // PC vtable +0x238
    virtual int GetPackageState() const;                                             // PC vtable +0x23C
    virtual void SetPackageExecutionState(int aiOffset);                             // PC vtable +0x240
    virtual void ResetCurrentPackage();                                              // PC vtable +0x244
    virtual DialogueItem* GetCurrentDialogueItem() const;                            // PC vtable +0x248
    virtual void SetCurrentDialogueItem(DialogueItem* apSubtitle);                   // PC vtable +0x24C
    virtual void MoveToPosition(Actor* apActor, NiPoint3 akPoint, float afRadius, float afTimeToExpire,
                                float afAvoidanceStrength, TESObjectREFR* apRef,
                                TESObjectSTAT* apMarker);                                     // PC vtable +0x250
    virtual PathingAvoidNodeArray* GetPathingAvoidNodeArray();                                // PC vtable +0x254
    virtual bool IsReferenceAvoided(TESObjectREFR* apRef) const;                              // PC vtable +0x258
    virtual void SetAnimationTime(float afVal);                                               // PC vtable +0x25C
    virtual void SetDetectionTarget(TESObjectREFR* apRef);                                // PC vtable +0x260
    virtual float GetDetectionProgress() const;                                               // PC vtable +0x264
    virtual void SetDetectionLevel(float afVal);                                              // PC vtable +0x268
    virtual void ClearCurrentTarget();                                                        // PC vtable +0x26C
    virtual ActorPackageData* GetRunOncePackageData() const;                                  // PC vtable +0x270
    virtual ActorPackageData* GetCurrentPackageData() const;                                  // PC vtable +0x274
    virtual ActorPackageContext* GetCurrentProcessData() const;                                      // PC vtable +0x278
    virtual TESPackage* GetOneTimePackage() const;                                            // PC vtable +0x27C
    virtual int GetPackageInfoValue() const;                                                  // PC vtable +0x280
    virtual void SetAnimationState(unsigned int aiIndex);                                     // PC vtable +0x284
    virtual void SetProcessTarget(Actor* apActor, int aiOffset);                              // PC vtable +0x288
    virtual bhkCharacterController* GetPhysicsCharacterController() const;                    // PC vtable +0x28C
    virtual void AssignCharacterController(NiPointer<bhkCharacterController>& arController);  // PC vtable +0x290
    virtual void StopActorMovement(Actor* apActor);                                           // PC vtable +0x294
    virtual void UpdateActorPackage(Actor* apActor, bool abFlag, unsigned int aeMoveMode,
                                    bool abPursuit);  // PC vtable +0x298
    virtual void EvaluatePackage(Actor* apActor, bool abNewPackage, bool abInterateIndex,
                                 unsigned int aeMoveMode);  // PC vtable +0x29C
    virtual void ProcessFlee(Actor* apActor);               // PC vtable +0x2A0
    virtual void ProcessDialogueTopic(Actor* apActor, TESTopic* apTopic, bool abForceSub, bool abStop, bool abQueue,
                                      bool abSayCallBack);                                       // PC vtable +0x2A4
    virtual void StartActorInteraction(Actor* apActor);                                          // PC vtable +0x2A8
    virtual void UpdateActorInteraction(Actor* apActor);                                         // PC vtable +0x2AC
    virtual void IsActorProcessable(Actor* apActor);                                             // PC vtable +0x2B0
    virtual bool IsFurnitureType(TESObjectREFR* apFurnitureRef, unsigned int auiFurnitureType);  // PC vtable +0x2B4
    virtual bool CanDetectActor(Actor* apActor);                                                 // PC vtable +0x2B8
    virtual void UpdateActorStateWithOptions(Actor* apActor, bool abNewPackage, bool abIterateIndex, unsigned int aeMoveMode,
                               bool abSecondLoc);                                   // PC vtable +0x2BC
    virtual WadingWaterData* GetWadingWaterData() const;                            // PC vtable +0x2C0
    virtual void SetActorDetectionLevel(Actor* apActor, DetectionListType aeType);  // PC vtable +0x2C4
    virtual void SetDetectionTimer();                                               // PC vtable +0x2C8
    virtual void IsActorVisibleToActor(Actor* apActor, Actor* apTarget, DetectionListType aeType,
                                       bool abFullTest);                                            // PC vtable +0x2CC
    virtual bool IsActorDetected(Actor* apActor, Actor* apTarget, DetectionListType aeType);        // PC vtable +0x2D0
    virtual int GetDetectionCount(Actor* apTarget, DetectionListType aeType) const;                 // PC vtable +0x2D4
    virtual bool IsDetectionEnabled() const;                                                        // PC vtable +0x2D8
    virtual void SetActorProcessEnabled(bool abVal);                                                // PC vtable +0x2DC
    virtual void SetActorProcessTime(Actor* apActor, float afTimeDelta);                            // PC vtable +0x2E0
    virtual int GetActorReferenceState(Actor* apActor, TESObjectREFR* apTarget);                    // PC vtable +0x2E4
    virtual DIALOGUE_EMOTION GetCurrentDialogueEmotion() const;                                     // PC vtable +0x2E8
    virtual void SetDialogueEmotion(DIALOGUE_EMOTION aeEmotion);                                    // PC vtable +0x2EC
    virtual void RunDetection();                                                                    // PC vtable +0x2F0
    virtual double GetDetectionStrength();                                                          // PC vtable +0x2F4
    virtual void ResetDetectionState();                                                             // PC vtable +0x2F8
    virtual void UpdateActorLighting(float afVal);                                                  // PC vtable +0x2FC
    virtual float UpdateProcessTiming() const;                                                      // PC vtable +0x300
    virtual void SetSurfacing(bool abVal);                                                          // PC vtable +0x304
    virtual bool GetSurfacing();                                                                    // PC vtable +0x308
    virtual bool IsDetecting() const;                                                               // PC vtable +0x30C
    virtual void SetCombatAlerted(bool abVal);                                                      // PC vtable +0x310
    virtual float GetSecondProcessFloat() const;                                                    // PC vtable +0x314
    virtual void SetLipSyncValue(float afVal);                                                      // PC vtable +0x318
    virtual bool IsCurrentlyAlerted() const;                                                        // PC vtable +0x31C
    virtual void SetAlert(bool abVal);                                                              // PC vtable +0x320
    virtual bool HasCombatStarted();                                                       // PC vtable +0x324
    virtual void SetIsWeaponDrawn(bool abVal);                                                      // PC vtable +0x328
    virtual InventoryStackRecord* GetPackageObject(Actor* apActor, PACKAGE_OBJECT_TYPE aePackageObjectType);  // PC vtable +0x32C
    virtual void ClearPackageObjectList();                                                          // PC vtable +0x330
    virtual float GetRadiationRate() const;                                                         // PC vtable +0x334
    virtual void SetRadiationRate(float afValue);                                                   // PC vtable +0x338
    virtual bool ShouldAttackTarget(Actor* apActor, Actor* apTarget, bool, bool abIsEvil, ActorCombatGroup* apCombatGroup,
                                    bool, bool, bool abIsAggressor, bool, bool abIgnoreActorLimit, bool, bool,
                                    TESPackage* apPackage);                       // PC vtable +0x33C
    virtual void SetCombatTargetForActor(Actor* apActor, Actor* apCriminal);      // PC vtable +0x340
    virtual void CallForHelp(Actor* apActor, Actor* apCriminal, Crime* apCrime);  // PC vtable +0x344
    virtual void SetCrimeCategory(int aiVal);                                     // PC vtable +0x348
    virtual unsigned int GetAttackChance(Actor* apActor, float afDistanceSq, float afShortDistSq, float afLongDistSq,
                                         bool abAlarmOrCombat, bool abPureTravel) const;  // PC vtable +0x34C
    virtual void SetActorDetectionState(Actor* apActor, unsigned int aeMoveMode,
                                        bool abCheckAlwaysRun);                          // PC vtable +0x350
    virtual void FinishDying(Actor* apActor);                                            // PC vtable +0x354
    virtual bool MoveToTarget(Actor* apActor, float afRadius, unsigned int aeMoveMode);  // PC vtable +0x358
    virtual bool ClearProcessStateFlags() const;                                         // PC vtable +0x35C
    virtual bool IsCurrentProcessComplete() const;
    virtual void SetCurrentProcessComplete(bool abVal);                                                           // PC vtable +0x364
    virtual int GetActorStateCode(Actor* apActor);                                                  // PC vtable +0x368
    virtual bool HasActorAlertState() const;                                                      // PC vtable +0x36C
    virtual void SetDialogueState(bool abVal);                                                      // PC vtable +0x370
    virtual void SetTalkingState(bool abVal);                                                       // PC vtable +0x374
    virtual bool IsActorTalking() const;                                                          // PC vtable +0x378
    virtual LipSyncAnimation* GetLipSync() const;                                                   // PC vtable +0x37C
    virtual void AssignLipSyncAnimation(LipSyncAnimation* apAnim);                                  // PC vtable +0x380
    virtual void SetLipSyncEnabled(bool abVal);                                                     // PC vtable +0x384
    virtual bool GetPlantedExplosive() const;                                                       // PC vtable +0x388
    virtual TESIdleForm* GetActiveIdleForm() const;                                                 // PC vtable +0x38C
    virtual void SetLastPlayedIdle(TESIdleForm* idleForm);                                          // PC vtable +0x390
    virtual void RefreshActorValues(Actor* apActor);                                                // PC vtable +0x394
    virtual int GetActorValueI(TESActorBase* apBase, ActorValue::Index aeIndex, Actor* apActor);    // PC vtable +0x398
    virtual float GetActorValueF(TESActorBase* apBase, ActorValue::Index aeIndex, Actor* apActor);  // PC vtable +0x39C
    virtual void TempModActorValueF(Actor* apActor, ActorValue::Index aeIndex, float afVal);        // PC vtable +0x3A0
    virtual void TempModActorValueI(Actor* apActor, ActorValue::Index aeIndex, int aiVal);          // PC vtable +0x3A4
    virtual void DamageModActorValueF(Actor* apActor, ActorValue::Index aeIndex, float afVal);      // PC vtable +0x3A8
    virtual void DamageModActorValueI(Actor* apActor, ActorValue::Index aeIndex, int aiVal);        // PC vtable +0x3AC
    virtual void InvalidateValue(ActorValue::Index aeIndex);                                        // PC vtable +0x3B0
    virtual void InitializeActiveEffectList();                                                      // PC vtable +0x3B4
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() const;                               // PC vtable +0x3B8
    virtual void DestroyActiveEffectList();                                                         // PC vtable +0x3BC
    virtual void CastSpellOnCaster(MagicCaster* apCaster, SpellItem* apAbility, bool abLoadCast);   // PC vtable +0x3C0
    virtual void CastSpellAtTarget(MagicCaster* apCaster, SpellItem* apDisease, MagicTarget* apTarget,
                                   bool abLoadCast);                   // PC vtable +0x3C4
    virtual MagicItem* GetSelectedMagicItem() const;                   // PC vtable +0x3C8
    virtual void SetSelectedMagicItem(MagicItem* apSpell);             // PC vtable +0x3CC
    virtual MagicTarget* GetCurrentMagicTarget() const;                // PC vtable +0x3D0
    virtual void SetMagicTarget(MagicTarget* apTarget);                // PC vtable +0x3D4
    virtual bool UpdateIdleAnimation() const;                          // PC vtable +0x3D8
    virtual void SetBooleanState(bool abVal);                          // PC vtable +0x3DC
    virtual void Move(MobileObject* apObject, NiPoint3 akSideVector);  // PC vtable +0x3E0
    virtual ANIMATION_ACTION GetAnimAction() const;                    // PC vtable +0x3E4
    virtual BSAnimGroupSequence* GetActorProcessTime() const;          // PC vtable +0x3E8
    virtual void SetAnimAction(ANIMATION_ACTION aeAnimationAction,
                               BSAnimGroupSequence* apSequence);                                   // PC vtable +0x3EC
    virtual bool IsAnimationSequencePlaying() const;                                               // PC vtable +0x3F0
    virtual void SetIsAlerted(bool abVal);                                                         // PC vtable +0x3F4
    virtual bool IsAimingWeapon() const;                                                           // PC vtable +0x3F8
    virtual bool IsAimingAtActor(Actor* apActor);                                                  // PC vtable +0x3FC
    virtual void SetAimingWeapon(bool isAiming);                                                     // PC vtable +0x400
    virtual bool IsAlert() const;                                                                  // PC vtable +0x404
    virtual bool HasAnimationGroup(ANIM_GROUP_TYPE aeAnim);                                        // PC vtable +0x408
    virtual int GetKnockedState();                                                                 // PC vtable +0x40C
    virtual void SetKnockedState(char state);                                                      // PC vtable +0x410
    virtual void KnockDown(Actor* apActor);                                                        // PC vtable +0x414
    virtual void ApplyKnockback(Actor* apActor, NiPoint3 akSource, float afForce);                 // PC vtable +0x418
    virtual void UpdateActorData(Actor* apActor);                                                  // PC vtable +0x41C
    virtual void ProcessActorEvent(Actor* apActor);                                                // PC vtable +0x420
    virtual void SetAnimationSequence(unsigned int aeDirection, BSAnimGroupSequence* apSequence);  // PC vtable +0x424
    virtual void RefreshActorAnimation(Actor* apActor);                                            // PC vtable +0x428
    virtual float GetAimAngle() const;                                                             // PC vtable +0x42C
    virtual void SetAimAngle(float afValue);                                                       // PC vtable +0x430
    virtual void SetStartShooting(bool abStartShooting);                                           // PC vtable +0x434
    virtual unsigned char GetAttackState(Actor* apTarget);                                         // PC vtable +0x438
    virtual void SetBodyPartState(unsigned char aucCount);                                         // PC vtable +0x43C
    virtual unsigned char GetProcessStateByte() const;                                             // PC vtable +0x440
    virtual float GetVisibilityAlpha() const;                                                      // PC vtable +0x444
    virtual void SetAttackCount(int aiNumAttacks);                                                 // PC vtable +0x448
    virtual bool IsFirstActorFlagSet() const;                                                       // PC vtable +0x44C
    virtual void SetIsSwimming(bool abVal);                                                        // PC vtable +0x450
    virtual bool IsAdditionalActorFlagSet() const;                                                           // PC vtable +0x454
    virtual void SetActorMovementState(Actor* apActor, bool abVal);                                // PC vtable +0x458
    virtual void SetWeaponLastPos(NiPoint3 akPos);                                                 // PC vtable +0x45C
    virtual NiPoint3* GetLastKnownPosition() const;                                                // PC vtable +0x460
    virtual void Update3DModel(Actor* apActor);                                                    // PC vtable +0x464
    virtual void ResetActorModel(unsigned char aucFlag);                                           // PC vtable +0x468
    virtual void SetDetectionFlag(unsigned char aucFlag);                                          // PC vtable +0x46C
    virtual void ClearDetectionFlag();                                                             // PC vtable +0x470
    virtual bool IsProcessFlagSet(unsigned char aucFlag) const;                                    // PC vtable +0x474
    virtual unsigned char GetCurrentTargetType() const;                                            // PC vtable +0x478
    virtual void ClearReferenceRecords(TESObjectREFR* apObject);                                   // PC vtable +0x47C
    virtual void ClearObjectFromAcquireListAlt(unsigned int auiFormID);                            // PC vtable +0x480
    virtual TESObjectREFR* GetPreviousReference() const;                                           // PC vtable +0x484
    virtual void SetActorTargetReference(TESObjectREFR* apRef);                                             // PC vtable +0x488
    virtual BSSoundHandle GetActorSoundHandle(unsigned int aeType);                                // PC vtable +0x48C
    virtual void SetActorSoundHandle(unsigned int aeType, BSSoundHandle akHandle);                 // PC vtable +0x490
    virtual void StopActorSound(unsigned int aeType);                                              // PC vtable +0x494
    virtual void UpdateMovementStopped(Actor* apActor);                                            // PC vtable +0x498
    virtual bool GetMovementStopped() const;                                                       // PC vtable +0x49C
    virtual void ClearMovementStopped();                                                           // PC vtable +0x4A0
    virtual void SetDiveBreathLevel(float afVal);                                                  // PC vtable +0x4A4
    virtual void StopAllActorSounds();                                                             // PC vtable +0x4A8
    virtual float GetDiveBreathLevel() const;                                                      // PC vtable +0x4AC
    virtual float GetMovementTimer() const;                                                        // PC vtable +0x4B0
    virtual void UpdateActorProcess(float afVal);                                                  // PC vtable +0x4B4
    virtual bool IsTalking() const;                                                                // PC vtable +0x4B8
    virtual SIT_SLEEP_STATE GetSitSleepState() const;                                              // PC vtable +0x4BC
    virtual void SetFurnitureState(Actor* apActor, SIT_SLEEP_STATE aeState, TESObjectREFR* apFurniture,
                                   unsigned char aucFurnitureIndex);                          // PC vtable +0x4C0
    virtual unsigned int GetFurnitureMarkerID() const;                                        // PC vtable +0x4C4
    virtual TESObjectREFR* GetFurnitureReference() const;                                     // PC vtable +0x4C8
    virtual void RemoveFurniture(TESObjectREFR* apFurnitureRef);                              // PC vtable +0x4CC
    virtual unsigned int GetFurnitureMarkerIndex() const;                                     // PC vtable +0x4D0
    virtual FurnitureMark* GetFurnitureMarkerData() const;                                    // PC vtable +0x4D4
    virtual bool IsFurnitureMarkerValid(Actor* apActor);                                      // PC vtable +0x4D8
    virtual void AssignAnimation(Actor* apActor, Animation* apAnimation);                     // PC vtable +0x4DC
    virtual bool HasAssignedAnimation() const;                                                // PC vtable +0x4E0
    virtual void SetAnimationEnabled(bool abVal);                                             // PC vtable +0x4E4
    virtual bool IsPlayingAnimation() const;                                                  // PC vtable +0x4E8
    virtual void SetProcessConditionMet();                                                    // PC vtable +0x4EC
    virtual bool IsProcessStateEnabled() const;                                               // PC vtable +0x4F0
    virtual void SetWeaponOutState(bool abVal);                                               // PC vtable +0x4F4
    virtual BSShaderPPLightingProperty* GetPixelLightingProperty() const;                     // PC vtable +0x4F8
    virtual void SetPixelLightingProperty(BSShaderPPLightingProperty* apProp);                // PC vtable +0x4FC
    virtual void SetDetectionState(Actor* apActor, bool abIgnoreTorch);                       // PC vtable +0x500
    virtual DetectionViewData* GetDetectionState(Actor* apTarget, DetectionListType aeType);  // PC vtable +0x504
    virtual DetectionViewData* InsertIntoDetectionArray(Actor* apTarget,
                                                        DETECTION_LEVEL aeDetectionLevel);  // PC vtable +0x508
    virtual double GetLightUpdateTimer() const;                                             // PC vtable +0x50C
    virtual void SetLightUpdateTimer(float afVal);                                          // PC vtable +0x510
    virtual TESObjectREFR* GetActiveCombatTarget() const;                                   // PC vtable +0x514
    virtual void SetCurrentCombatTarget(TESObjectREFR* apLocation);                         // PC vtable +0x518
    virtual TESObjectREFR* GetProcessReference() const;                                     // PC vtable +0x51C
    virtual void SetCurrentLocationReference(TESObjectREFR* apLocation);                    // PC vtable +0x520
    virtual void UpdateCurrentPackage();                                                    // PC vtable +0x524
    virtual void SetTalkTarget(Actor* apActor);                                             // PC vtable +0x528
    virtual Actor* GetCurrentTalkTarget() const;                                              // PC vtable +0x52C
    virtual void SetEquippedWeapon(TESObjectWEAP* apWeapon);                                // PC vtable +0x530
    virtual TESObjectWEAP* GetWeaponForm() const;                                           // PC vtable +0x534
    virtual void SetActorAlpha(float afVal);                                                // PC vtable +0x538
    virtual float GetActorAlpha() const;                                                    // PC vtable +0x53C
    virtual void SetFurnitureMarkerData(TESObjectREFR* apFurnitureRef, unsigned char aucMarkerIndex,
                                        FurnitureMark* apMark);                         // PC vtable +0x540
    virtual void ApplyProcessLevelChange(MobileObject* apObject);                       // PC vtable +0x544
    virtual unsigned short GetSaveSize(unsigned int auiFlags, MobileObject* apObject);  // PC vtable +0x548
    virtual void SaveGameBGS(BGSSaveGameBuffer* apBuffer);                              // PC vtable +0x54C
    virtual void SaveGameTES(unsigned int auiFlags, MobileObject* apObject);            // PC vtable +0x550
    virtual void LoadGameBGS(BGSLoadFormBuffer* apBuffer);                              // PC vtable +0x554
    virtual void LoadGameTES(unsigned int auiFlags, unsigned int auiCurrentFlags,
                             MobileObject* apObject);           // PC vtable +0x558
    virtual void InitLoadGameBGS(BGSLoadFormBuffer* apBuffer);  // PC vtable +0x55C
    virtual void InitLoadGameTES(unsigned int auiFlags, unsigned int auiOldFlags,
                                 MobileObject* apObject);  // PC vtable +0x560
    virtual void FinishLoadGameTES(unsigned int auiFlags, unsigned int auiOldFlags,
                                   MobileObject* apObject);                 // PC vtable +0x564
    virtual void RevertBGS(BGSLoadFormBuffer* apBuffer);                    // PC vtable +0x568
    virtual void RevertTES(unsigned int auiFlags, MobileObject* apObject);  // PC vtable +0x56C
    virtual void ApplyLoadBuffer();                                         // PC vtable +0x570
    virtual TESEffectShader GetCurrentEffectShader() const;                 // PC vtable +0x574
    virtual void AssignEffectShader(TESEffectShader* apShader);             // PC vtable +0x578
    virtual bool IsProcessStateInitialized() const;                         // PC vtable +0x57C
    virtual void UpdateActorAppearance(bool abUpdateWeaponEffectShader, bool abInitializeActiveHitEffect,
                                       bool);                                   // PC vtable +0x580
    virtual void RefreshActorProcessState(Actor* apActor);                      // PC vtable +0x584
    virtual void SetIdleAnimationPlayed(bool abVal);                            // PC vtable +0x588
    virtual bool IsPlayedState() const;                                   // PC vtable +0x58C
    virtual void SetPlayedState(bool abVal);                                    // PC vtable +0x590
    virtual bool WasIdleAnimationPlayed() const;                                // PC vtable +0x594
    virtual void OnPackageChanged(Actor* apActor, TESPackage* apPackage);       // PC vtable +0x598
    virtual TESPackage* OnPackageStart(Actor* apActor, TESPackage* apPackage);  // PC vtable +0x59C
    virtual void OnPackageEnd(Actor* apActor, TESPackage* apPackage);           // PC vtable +0x5A0
    virtual bool IsProcessActivityActive() const;                               // PC vtable +0x5A4
    virtual void SetProcessModeEnabled(bool abVal);                             // PC vtable +0x5A8
    virtual float GetLightIntensity() const;                                    // PC vtable +0x5AC
    virtual void SetUnderwaterBreathTime(float afVal);                          // PC vtable +0x5B0
    virtual float GetThirdProcessFloat() const;                                 // PC vtable +0x5B4
    virtual void SetWadingWaterLevel(float afVal);                              // PC vtable +0x5B8
    virtual void UpdateWadingWater(Actor* apActor);                             // PC vtable +0x5BC
    virtual int GetProcessIndex() const;                                        // PC vtable +0x5C0
    virtual void SetProcessIndex(int aiVal);                                    // PC vtable +0x5C4
    virtual bool HasActiveEffectOfType(BSSimpleList<ActiveEffect*>* apEffects,
                                       unsigned int aeFlareType);                                 // PC vtable +0x5C8
    virtual void RefreshMagicEffects();                                                           // PC vtable +0x5CC
    virtual BSSimpleList<SpellItem*>* GetActorSpellList(Actor* apActor, bool abIncludeDiseases);  // PC vtable +0x5D0
    virtual void SetCastingState(int aiHasSpells);                                                // PC vtable +0x5D4
    virtual int GetCurrentAnimAction() const;                                                     // PC vtable +0x5D8
    virtual void SetCurrentMoveMode(int aiHasHealingPotion);                                      // PC vtable +0x5DC
    virtual int GetPendingIdleFlags() const;                                                      // PC vtable +0x5E0
    virtual float GetPermanentActorValueFloat(ActorValue::Index aeActorValue);                    // PC vtable +0x5E4
    virtual float GetDamageActorValue(ActorValue::Index aeActorValue);                            // PC vtable +0x5E8
    virtual float GetTemporaryActorValue(ActorValue::Index aeActorValue);                         // PC vtable +0x5EC
    virtual BSBound* GetBound() const;                                                            // PC vtable +0x5F0
    virtual void SetObjectBound(BSBound* apBound);                                                // PC vtable +0x5F4
    virtual void SetIsSitting(bool abVal);                                                        // PC vtable +0x5F8
    virtual bool IsActorInCombat() const;                                                      // PC vtable +0x5FC
    virtual void SetCombatState(bool abVal);                                                      // PC vtable +0x600
    virtual bool IsCurrentlyDetected() const;                                                       // PC vtable +0x604
    virtual BSSimpleList<Actor*>* GetActorsInAggroRadius() const;                                 // PC vtable +0x608
    virtual void ProcessActorReferences(Actor* apActor, Actor* apTarget, Actor* apAlly);          // PC vtable +0x60C
    virtual FadeState GetCurrentFadeState() const;                                                // PC vtable +0x610
    virtual void AddPostAnimAction(PostAnimAction aeFlag);                                        // PC vtable +0x614
    virtual unsigned int GetPostAnimationAction() const;                                          // PC vtable +0x618
    virtual void ClearPostAnimActions();                                                          // PC vtable +0x61C
    virtual void SetProcessState(PostAnimAction aeFlag);                                          // PC vtable +0x620
    virtual void SetPreviousReference(TESObjectREFR* apTarget);                                   // PC vtable +0x624
    virtual void SetActorProcessState(TESObjectREFR* apTarget);                                   // PC vtable +0x628
    virtual void SetPackageTargetReference(TESObjectREFR* apTarget);                              // PC vtable +0x62C
    virtual void SetCombatTargetReference(TESObjectREFR* apTarget);                               // PC vtable +0x630
    virtual void ClearHighProcessState(TESObjectREFR* apTarget);                                  // PC vtable +0x634
    virtual void SetLastKnownReference(TESObjectREFR* apTarget);                                  // PC vtable +0x638
    virtual void SetTargetReferenceByIndex(HeadTrackType aeType, TESObjectREFR* apTarget);        // PC vtable +0x63C
    virtual void ClearPackageData();                                                              // PC vtable +0x640
    virtual void ClearCachedTargetReferences(bool abHoldDefault);                                 // PC vtable +0x644
    virtual void SetCombatActive(bool abHoldDefault);                                             // PC vtable +0x648
    virtual void ResetCombatState();                                                              // PC vtable +0x64C
    virtual void RestorePreviousReference(bool abHoldDefault);                                    // PC vtable +0x650
    virtual void SetProcessActive(bool abHoldDefault);                                            // PC vtable +0x654
    virtual void UpdatePlayerAwarenessTimer();                                                    // PC vtable +0x658
    virtual float GetCurrentAlpha() const;                                                        // PC vtable +0x65C
    virtual void ResetHeadTrackingTarget();                                                       // PC vtable +0x660
    virtual void SetCurrentTargetReference(TESObjectREFR* apTarget);                                  // PC vtable +0x664
    virtual bool HasNoPendingEntriesAndExpired();                                                 // PC vtable +0x668
    virtual bool HasNoPendingEntries();                                                           // PC vtable +0x66C
    virtual bool CanSetDialogHeadTrackTarget();                                                   // PC vtable +0x670
    virtual TESObjectREFR* GetCurrentHeadTrackTargetByType(HeadTrackType aeType);                 // PC vtable +0x674
    virtual TESObjectREFR* GetPrimaryTargetReference();                                           // PC vtable +0x678
    virtual unsigned int GetCombatTargetCount() const;                                            // PC vtable +0x67C
    virtual const char* GetCurrentPackageName() const;                                            // PC vtable +0x680
    virtual void SetIsTalking(bool abVal);                                                        // PC vtable +0x684
    virtual bool IsCombatTargetValid() const;                                                     // PC vtable +0x688
    virtual TESObjectREFR* GetRelatedReference() const;                                           // PC vtable +0x68C
    virtual bool IsInLastDefaultTargetArray(TESObjectREFR* apRef);                                // PC vtable +0x690
    virtual void SetHasLastDefaultTargetArray(bool abVal);                                        // PC vtable +0x694
    virtual bool BeginIdleAnimation() const;                                                      // PC vtable +0x698
    virtual float GetCurrentDetectionAmount() const;                                              // PC vtable +0x69C
    virtual void SetLightingAmount(float afVal);                                                  // PC vtable +0x6A0
    virtual void AddArrowProjectile(ArrowProjectile* apArrow);                                    // PC vtable +0x6A4
    virtual void UnregisterArrowProjectile(ArrowProjectile* apArrow);                             // PC vtable +0x6A8
    virtual void SetArrowTargetReference(TESObjectREFR* apRef);                                   // PC vtable +0x6AC
    virtual BSSimpleList<ArrowProjectile*>* GetArrowProjectiles() const;                          // PC vtable +0x6B0
    virtual void SetProjectileTarget(Projectile* apProjectile, TESObjectREFR* apShooter);         // PC vtable +0x6B4
    virtual MuzzleFlash* GetMuzzleFlash() const;                                                  // PC vtable +0x6B8
    virtual bool GetEnableMuzzleFlash();                                                          // PC vtable +0x6BC
    virtual void EnableMuzzleFlash();                                                             // PC vtable +0x6C0
    virtual void ClearMuzzleFlash();                                                              // PC vtable +0x6C4
    virtual void ApplyBodyPartData(NiNode* apNode, BGSBodyPartData* apBodyPartData);              // PC vtable +0x6C8
    virtual void SetNodeForType(LIMB_TYPE aeBodyPart, NiNode* apNode);                            // PC vtable +0x6CC
    virtual NiNode* GetNodeByType(LIMB_TYPE aeBodyPart) const;                                    // PC vtable +0x6D0
    virtual NiNode* GetFirstSceneObject() const;                                                  // PC vtable +0x6D4
    virtual NiNode* GetActorSceneObject() const;                                                  // PC vtable +0x6D8
    virtual bool GetSustainedFire() const;                                                        // PC vtable +0x6DC
    virtual void SetSustainedState(bool abVal);                                                   // PC vtable +0x6E0
    virtual void RunActorProcess();                                                               // PC vtable +0x6E4
    virtual void IsWearingHeavyArmor();                                                           // PC vtable +0x6E8
    virtual bool IsWearingPowerArmorTorso();                                                      // PC vtable +0x6EC
    virtual bool IsWearingPowerArmorHelmet();                                                     // PC vtable +0x6F0
    virtual bool IsWearingBackpack();                                                             // PC vtable +0x6F4
    virtual void SetIdleStateFlag(bool abVal);                                                    // PC vtable +0x6F8
    virtual bool IsProcessStateActive() const;                                                 // PC vtable +0x6FC
    virtual void UpdateReferenceTime(Actor* apActor, float afTimeDelta);                          // PC vtable +0x700
    virtual void UpdateActorProcessState(Actor* apActor);                                      // PC vtable +0x704
    virtual void SelectAnimationAction(int aiValue);                                              // PC vtable +0x708
    virtual void UpdateActorReferences(Actor* apActor);                                           // PC vtable +0x70C
    virtual void SetProcessReference(TESObjectREFR* apRef);                                       // PC vtable +0x710
    virtual void SetMobileObjectTarget(TESObjectREFR* apRef);                                     // PC vtable +0x714
    virtual TESIdleForm* GetSelectedIdleForm() const;                                             // PC vtable +0x718
    virtual void SetIdleForm(TESIdleForm* apIdleForm);                                            // PC vtable +0x71C
    virtual void SetIdleAnimation(AnimIdle* apAnimIdle, KFModel* apAnimIdleKF);                   // PC vtable +0x720
    virtual AnimIdle* GetIdleAnimation() const;                                                   // PC vtable +0x724
    virtual KFModel* GetIdleAnimationModel() const;                                               // PC vtable +0x728
    virtual void ApplyDamageToActor(Actor* apSource, float afDamage);                             // PC vtable +0x72C
    virtual float GetLastDamage() const;                                                          // PC vtable +0x730
    virtual float GetProcessBlendWeight() const;                                                  // PC vtable +0x734
    virtual void SetLightLevel(float afLightAmount);                                              // PC vtable +0x738
    virtual void AttachWeaponNode(LIMB_TYPE aeLimbIndex, NiNode* apDismemberedLimbRoot, NiAVObject* apReplacementLimb,
                                  bool abExplosion);                      // PC vtable +0x73C
    virtual void UpdateActorWithTime(Actor* apActor, float afTimeDelta);  // PC vtable +0x740
    virtual void SetLipSyncAnimation(LipSyncAnimation* apAnim);           // PC vtable +0x744
    virtual LipSyncAnimation* GetLipSyncAnimationData() const;            // PC vtable +0x748
    virtual void UpdateEffectShader(unsigned int auiTime);                // PC vtable +0x74C
    virtual unsigned int GetAnimationState() const;                       // PC vtable +0x750
    virtual void SetActorMovementRate(float afVal);                       // PC vtable +0x754
    virtual void SetMovementTimer(float afVal);                           // PC vtable +0x758
    virtual float GetAnimationElapsedTime() const;                        // PC vtable +0x75C
    virtual void AdvanceMovementTimer(float afVal);                       // PC vtable +0x760
    virtual float GetAnimationRemainingTime() const;                      // PC vtable +0x764
    virtual void SetWaterLevel(float afVal);                              // PC vtable +0x768
    virtual float GetControllerPhase() const;                             // PC vtable +0x76C
    virtual BooleanFloatQuery* RefreshActorRuntimeData() const;           // PC vtable +0x770
    virtual void SetProcessObject(BooleanFloatQuery* apHitData);          // PC vtable +0x774
    virtual void ResetHitData();                                          // PC vtable +0x778
    virtual BooleanFloatQuery* GetCurrentObjectData();                    // PC vtable +0x77C
    virtual void SetHitData(BooleanFloatQuery* apHitData);                // PC vtable +0x780
    virtual void ResetTargetHitData();                                    // PC vtable +0x784
    virtual int GetSleepSitState() const;                                 // PC vtable +0x788
    virtual void SetKnockdownStage(int aiStage);                          // PC vtable +0x78C
    virtual BSFaceGenNiNode* GetFacialAnimationNode() const;              // PC vtable +0x790
    virtual void AttachFaceGenerationNode(BSFaceGenNiNode* apNode);       // PC vtable +0x794
    virtual BSFaceGenNiNode* GetFaceGenHeadNode() const;                  // PC vtable +0x798
    virtual void SetFaceGenHeadNode(BSFaceGenNiNode* apNode);             // PC vtable +0x79C
    virtual NiAVObject* GetAnimationObject() const;                       // PC vtable +0x7A0
    virtual void SetAnimationNode(NiAVObject* apObject);                  // PC vtable +0x7A4
    virtual void SetActorTarget(Actor* apActor);                          // PC vtable +0x7A8
    virtual void SetLastTargetReference(TESObjectREFR* apTarget);         // PC vtable +0x7AC
    virtual void ClearTargetReference(TESObjectREFR* apTarget);           // PC vtable +0x7B0

    ActorPackageContext m_kProcessData;    // +0x04
    float m_fValue2;                // +0x1C
    float m_fValue1;                // +0x20
    unsigned int m_uiStateFlags;    // +0x24
    PROCESS_TYPE m_eProcessType;    // +0x28
    CachedValues* m_pCachedValues;  // +0x2C
    // Public PC 0045CD60; PROCESS_LEVEL is an alias of PROCESS_TYPE in that source.
    PROCESS_TYPE GetProcessLevel() const;
};
FNV_STATIC_ASSERT(sizeof(BaseProcess) == 0x30);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_kProcessData) == 0x4);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_fValue2) == 0x1C);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_fValue1) == 0x20);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_uiStateFlags) == 0x24);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_eProcessType) == 0x28);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_pCachedValues) == 0x2C);
#endif
