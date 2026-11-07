#pragma once

#include <stddef.h>
#include "ActorPackageContext.h"
#include "NiPoint3.h"

class ActiveEffect;
class AnimIdle;
class ArrowProjectile;
class Actor;
enum RESET_3D_FLAGS;
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
class NiObjectNET;
class NiRefObject;
class NiTriShape;
class Projectile;
class BSSoundHandle;
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
class CachedValues;
class PlayerCharacter;

template <class T> class BSSimpleList;
template <class T> class NiPointer;

namespace ActorValue
{
    enum Index;
}

struct _AnimationAction
{
    enum Action
    {
        NONE = -1,
        EQUIP_WEAPON,
        UNEQUIP_WEAPON,
        ATTACK,
        ATTACK_EJECT,
        ATTACK_FOLLOW_THROUGH,
        ATTACK_THROW,
        ATTACK_THROW_ATTACH,
        BLOCK,
        RECOIL,
        RELOAD,
        STAGGER,
        DODGE,
        LOWER_BODY_ANIM,
        SPECIAL_IDLE,
        SCRIPT_ANIMATION,
        RELOAD_LOOP_START,
        RELOAD_LOOP_END,
        RELOAD_LOOP,
        COUNT,
    };
};
// Distinct nested enum: HighProcess::SetAnimAction at 0x008da270 uses _AnimationAction::Action.
typedef _AnimationAction::Action ProcessAnimationAction;

struct _AnimGroup
{
    enum Group
    {
        NONE = -1,

        IDLE = 0,
        DYNAMIC_IDLE,
        SPECIAL_IDLE,

        MOVE_FORWARD,
        MOVE_BACK,
        MOVE_LEFT,
        MOVE_RIGHT,
        FAST_FORWARD,
        FAST_BACK,
        FAST_LEFT,
        FAST_RIGHT,
        DODGE_FORWARD,
        DODGE_BACK,
        DODGE_LEFT,
        DODGE_RIGHT,
        TURN_LEFT,
        TURN_RIGHT,

        _MOVEMENT_START = MOVE_FORWARD,
        _MOVEMENT_END = TURN_RIGHT,

        AIM,
        AIM_UP,
        AIM_DOWN,
        AIM_IS,
        AIM_IS_UP,
        AIM_IS_DOWN,

        _AIM_START = AIM,
        _AIM_END = AIM_IS_DOWN,

        HOLSTER,
        EQUIP,
        UNEQUIP,
        ATTACK_LEFT,
        ATTACK_LEFT_UP,
        ATTACK_LEFT_DOWN,
        ATTACK_LEFT_IS,
        ATTACK_LEFT_IS_UP,
        ATTACK_LEFT_IS_DOWN,
        ATTACK_RIGHT,
        ATTACK_RIGHT_UP,
        ATTACK_RIGHT_DOWN,
        ATTACK_RIGHT_IS,
        ATTACK_RIGHT_IS_UP,
        ATTACK_RIGHT_IS_DOWN,
        ATTACK_3,
        ATTACK_3_UP,
        ATTACK_3_DOWN,
        ATTACK_3_IS,
        ATTACK_3_IS_UP,
        ATTACK_3_IS_DOWN,
        ATTACK_4,
        ATTACK_4_UP,
        ATTACK_4_DOWN,
        ATTACK_4_IS,
        ATTACK_4_IS_UP,
        ATTACK_4_IS_DOWN,
        ATTACK_5,
        ATTACK_5_UP,
        ATTACK_5_DOWN,
        ATTACK_5_IS,
        ATTACK_5_IS_UP,
        ATTACK_5_IS_DOWN,
        ATTACK_6,
        ATTACK_6_UP,
        ATTACK_6_DOWN,
        ATTACK_6_IS,
        ATTACK_6_IS_UP,
        ATTACK_6_IS_DOWN,
        ATTACK_7,
        ATTACK_7_UP,
        ATTACK_7_DOWN,
        ATTACK_7_IS,
        ATTACK_7_IS_UP,
        ATTACK_7_IS_DOWN,
        ATTACK_8,
        ATTACK_8_UP,
        ATTACK_8_DOWN,
        ATTACK_8_IS,
        ATTACK_8_IS_UP,
        ATTACK_8_IS_DOWN,
        ATTACK_LOOP,
        ATTACK_LOOP_UP,
        ATTACK_LOOP_DOWN,
        ATTACK_LOOP_IS,
        ATTACK_LOOP_IS_UP,
        ATTACK_LOOP_IS_DOWN,
        ATTACK_SPIN,
        ATTACK_SPIN_UP,
        ATTACK_SPIN_DOWN,
        ATTACK_SPIN_IS,
        ATTACK_SPIN_IS_UP,
        ATTACK_SPIN_IS_DOWN,
        ATTACK_SPIN_2,
        ATTACK_SPIN_2_UP,
        ATTACK_SPIN_2_DOWN,
        ATTACK_SPIN_2_IS,
        ATTACK_SPIN_2_IS_UP,
        ATTACK_SPIN_2_IS_DOWN,
        ATTACK_POWER,
        ATTACK_FORWARD_POWER,
        ATTACK_BACK_POWER,
        ATTACK_LEFT_POWER,
        ATTACK_RIGHT_POWER,
        ATTACK_CUSTOM_1_POWER,
        ATTACK_CUSTOM_2_POWER,
        ATTACK_CUSTOM_3_POWER,
        ATTACK_CUSTOM_4_POWER,
        ATTACK_CUSTOM_5_POWER,
        PLACE_MINE,
        PLACE_MINE_UP,
        PLACE_MINE_DOWN,
        PLACE_MINE_IS,
        PLACE_MINE_IS_UP,
        PLACE_MINE_IS_DOWN,
        PLACE_MINE_2,
        PLACE_MINE_2_UP,
        PLACE_MINE_2_DOWN,
        PLACE_MINE_2_IS,
        PLACE_MINE_2_IS_UP,
        PLACE_MINE_2_IS_DOWN,
        ATTACK_THROW,
        ATTACK_THROW_UP,
        ATTACK_THROW_DOWN,
        ATTACK_THROW_IS,
        ATTACK_THROW_IS_UP,
        ATTACK_THROW_IS_DOWN,
        ATTACK_THROW_2,
        ATTACK_THROW_2_UP,
        ATTACK_THROW_2_DOWN,
        ATTACK_THROW_2_IS,
        ATTACK_THROW_2_IS_UP,
        ATTACK_THROW_2_IS_DOWN,
        ATTACK_THROW_3,
        ATTACK_THROW_3_UP,
        ATTACK_THROW_3_DOWN,
        ATTACK_THROW_3_IS,
        ATTACK_THROW_3_IS_UP,
        ATTACK_THROW_3_IS_DOWN,
        ATTACK_THROW_4,
        ATTACK_THROW_4_UP,
        ATTACK_THROW_4_DOWN,
        ATTACK_THROW_4_IS,
        ATTACK_THROW_4_IS_UP,
        ATTACK_THROW_4_IS_DOWN,
        ATTACK_THROW_5,
        ATTACK_THROW_5_UP,
        ATTACK_THROW_5_DOWN,
        ATTACK_THROW_5_IS,
        ATTACK_THROW_5_IS_UP,
        ATTACK_THROW_5_IS_DOWN,
        ATTACK_9,
        ATTACK_9_UP,
        ATTACK_9_DOWN,
        ATTACK_9_IS,
        ATTACK_9_IS_UP,
        ATTACK_9_IS_DOWN,
        ATTACK_THROW_6,
        ATTACK_THROW_6_UP,
        ATTACK_THROW_6_DOWN,
        ATTACK_THROW_6_IS,
        ATTACK_THROW_6_IS_UP,
        ATTACK_THROW_6_IS_DOWN,
        ATTACK_THROW_7,
        ATTACK_THROW_7_UP,
        ATTACK_THROW_7_DOWN,
        ATTACK_THROW_7_IS,
        ATTACK_THROW_7_IS_UP,
        ATTACK_THROW_7_IS_DOWN,
        ATTACK_THROW_8,
        ATTACK_THROW_8_UP,
        ATTACK_THROW_8_DOWN,
        ATTACK_THROW_8_IS,
        ATTACK_THROW_8_IS_UP,
        ATTACK_THROW_8_IS_DOWN,
        COUNTER_ATTACK,

        _WEAPONS_START = EQUIP,
        _WEAPONS_END = COUNTER_ATTACK,

        STOMP,
        BLOCK_IDLE,
        BLOCK_HIT,
        RECOIL,

        RELOAD_W_START,
        RELOAD_X_START,
        RELOAD_Y_START,
        RELOAD_Z_START,
        RELOAD_A,
        RELOAD_B,
        RELOAD_C,
        RELOAD_D,
        RELOAD_E,
        RELOAD_F,
        RELOAD_G,
        RELOAD_H,
        RELOAD_I,
        RELOAD_J,
        RELOAD_K,
        RELOAD_L,
        RELOAD_M,
        RELOAD_N,
        RELOAD_O,
        RELOAD_P,
        RELOAD_Q,
        RELOAD_R,
        RELOAD_S,
        RELOAD_W,
        RELOAD_X,
        RELOAD_Y,
        RELOAD_Z,

        _RELOAD_START = RELOAD_A,
        _LOOPING_RELOAD_START = RELOAD_W,
        _RELOAD_END = RELOAD_Z,

        JAM_A,
        JAM_B,
        JAM_C,
        JAM_D,
        JAM_E,
        JAM_F,
        JAM_G,
        JAM_H,
        JAM_I,
        JAM_J,
        JAM_K,
        JAM_L,
        JAM_M,
        JAM_N,
        JAM_O,
        JAM_P,
        JAM_Q,
        JAM_R,
        JAM_S,
        JAM_W,
        JAM_X,
        JAM_Y,
        JAM_Z,

        _WEAPON_JAM_START = JAM_A,
        _WEAPON_JAM_END = JAM_Z,

        STAGGER,
        DEATH,
        TALKING,
        PIPBOY,

        JUMP_START,
        JUMP_LOOP,
        JUMP_LAND,

        HAND_GRIP_1,
        HAND_GRIP_2,
        HAND_GRIP_3,
        HAND_GRIP_4,
        HAND_GRIP_5,
        HAND_GRIP_6,

        JUMP_LOOP_FORWARD,
        JUMP_LOOP_BACKWARD,
        JUMP_LOOP_LEFT,
        JUMP_LOOP_RIGHT,

        PIPBOY_CHILD,

        JUMP_LAND_FORWARD,
        JUMP_LAND_BACKWARD,
        JUMP_LAND_LEFT,
        JUMP_LAND_RIGHT,

        COUNT,
    };
};
typedef _AnimGroup::Group ANIM_GROUP_TYPE;

struct _AnimationIdlePlayType
{
    enum Type
    {
        REPLACE = 0,
        QUEUE = 1,
        AUTO = 2,
        AUTO_EXCLUSIVE = 3,
    };
};
typedef _AnimationIdlePlayType::Type ANIM_IDLE_PLAY_TYPE;

struct _BodyPartType
{
    enum Type
    {
        NONE = -1,
        TORSO,
        HEAD_1,
        HEAD_2,
        LEFT_ARM_1,
        LEFT_ARM_2,
        RIGHT_ARM_1,
        RIGHT_ARM_2,
        LEFT_LEG_1,
        LEFT_LEG_2,
        LEFT_LEG_3,
        RIGHT_LEG_1,
        RIGHT_LEG_2,
        RIGHT_LEG_3,
        BRAIN,
        WEAPON,
        COUNT,
    };
};
typedef _BodyPartType::Type LIMB_TYPE;

struct _DetectionLevel
{
    enum Level
    {
        LOST = 0,
        UNSEEN = 1,
        NOTICED = 2,
        SEEN = 3,
        COUNT = 4,
    };
};
typedef _DetectionLevel::Level DETECTION_LEVEL;

struct _SoundLevel
{
    enum Level
    {
        LOUD,
        NORMAL,
        SILENT,
        COUNT,
    };
};
typedef _SoundLevel::Level SOUND_LEVEL;

#include "DIALOGUE_EMOTION.h"
#include "PACKAGE_OBJECT_TYPE.h"
#include "SIT_SLEEP_STATE.h"
#include "PROCESS_TYPE.h"

typedef PROCESS_TYPE PROCESS_LEVEL;

class BaseProcess
{
  public:
    enum POSTANIM_ACTION  // values: Xbox PDB BaseProcess::POSTANIM_ACTION
    {
        POSTANIM_ACTION_NONE = 0,
        POSTANIM_ACTION_FIRE_WEAPON = 1,
        POSTANIM_ACTION_RELOAD_WEAPON = 2,
        POSTANIM_ACTION_SIT_SLEEP = 4,
        POSTANIM_ACTION_GET_UP = 8,
        POSTANIM_ACTION_PLAY_IDLE = 16,
        POSTANIM_ACTION_DIE = 32,
        POSTANIM_ACTION_EQUIP_UNEQUIP_WEAPON = 64,
        POSTANIM_ACTION_PICK_IDLE_CALL = 128,
        POSTANIM_ACTION_HAND_GRIP_WEAPON = 256,
        POSTANIM_ACTION_GETOUT_OF_FURNITURE = 512,
        POSTANIM_FORCEIDLE_ANIMATION = 1024,
        POSTANIM_FREEUP_SPECIAL_IDLE = 2048,
        POSTANIM_RELOAD_TARGETS = 4096,
        POSTANIM_ACTION_IDLE_LOADED = 8192,
        POSTANIM_ACTION_HAVOKWEAPON = 16384,
        POSTANIM_ACTION_BLOCK = 32768,
        POSTANIM_ACTION_SET_IRON_SIGHTS = 65536,
        POSTANIM_ACTION_EXPEL_SHELLCASING = 131072,
        POSTANIM_ACTION_RELOAD_SINGLE = 262144,
        POSTANIM_ACTION_START_LOOPING_RELOAD = 524288
    };
    enum HEAD_TRACK_TYPE  // values: Xbox PDB BaseProcess::HEAD_TRACK_TYPE
    {
        HEAD_TRACK_TYPE_DEFAULT = 0,
        HEAD_TRACK_TYPE_ACTION = 1,
        HEAD_TRACK_TYPE_SCRIPT = 2,
        HEAD_TRACK_TYPE_COMBAT = 3,
        HEAD_TRACK_TYPE_DIALOG = 4,
        HEAD_TRACK_TYPE_USE_WEAPON = 5,
        HEAD_TRACK_TYPE_COUNT = 6
    };
    enum FADE_STATE  // values: Xbox PDB BaseProcess::FADE_STATE
    {
        FADE_NORMAL = 0,
        FADE_IN = 1,
        FADE_OUT = 2,
        FADE_TELEPORT_IN = 3,
        FADE_TELEPORT_OUT = 4,
        FADE_OUT_DISABLE = 5,
        FADE_OUT_DELETE = 6,
        FADE_OUT_MOVE = 7
    };

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

    virtual ~BaseProcess();
    virtual void Copy(BaseProcess* apSource);
    virtual void SetReferenceTarget(Actor* apActor);
    virtual void UpdateAlt(MobileObject* apObject, float afDelta);
    virtual void Update(MobileObject* apObject);
    virtual void SetMobileObjectState(MobileObject* apObject, bool abActionflag);
    virtual NiPoint3 GetActorWorldPosition(Actor* apActor);
    virtual NiPoint3 GetActorNodePosition(Actor* apActor, DetectionListType aeType);
    virtual double GetActorValueAtIndex(Actor* apActor, DetectionListType aeType);
    virtual bool CheckForNewPackage(Actor* apActor, bool abFlag);
    virtual void ResetPackageState();
    virtual bool IsLowProcessStateValid() const;
    virtual unsigned int GetPackedStateBits0To8() const;
    virtual unsigned int GetPackedStateBits9To12() const;
    virtual unsigned int GetPackedStateBits13To26() const;
    virtual void SetProcessInteger(int aiVal);
    virtual int GetProcessInteger() const;
    virtual bool StartIdleAnimation(Actor* apActor, TESIdleForm* apIdle, ANIM_IDLE_PLAY_TYPE aeDefaultAction,
                                    bool abCrippled, bool abForce, bool abTestConditions);
    virtual void ClearIdleAnimation();
    virtual MagicItem* GetCurrentMagicItem() const;
    virtual void SetCurrentMagicItem(MagicItem* apSpell);
    virtual void SetActorMagicItem(Actor* apActor, int aiRounds);
    virtual void InitializeProcessState();
    virtual void UpdateHealthBar(Actor* apActor);
    virtual bool GetIdleDoneOnce() const;
    virtual void MarkIdleDoneOnce(bool abVal);
    virtual bool ShouldProcessActor(Actor* apActor);
    virtual void ProcessActorGroupState(Actor* apActor);
    virtual bool CanUsePlayerAction(Actor* apActor) const;
    virtual bool CanPerformActorAction(Actor* apActor, float afTimeDelta);
    virtual bool IsAsleep() const;
    virtual void ProcessSandman(Actor* apActor);
    virtual void ProcessCannibal(Actor* apActor);
    virtual void ProcessFurniture(Actor* apActor);
    virtual void SetCombatEnabled(bool abVal);
    virtual bool FindPackageTarget(Actor* apActor);
    virtual TESObjectREFR* GetPackageLocationReference(Actor* apActor, bool abSecond);  // LowProcess 0x00908c50: ret 8, returns the reference
    virtual TESObjectREFR* GetActorTargetReference(Actor* apActor, bool abInterrupt);
    virtual NiPoint3 GetActorTargetPosition(Actor* apActor, bool abInterrupt);  // returned through the hidden pointer
    virtual TESObjectCELL* GetTargetCell(Actor* apActor);
    virtual TESWorldSpace* GetTargetWorldSpace(Actor* apActor);
    virtual float GetTargetDistance(Actor* apActor);
    virtual MobileObject* GetMobileObject() const;
    virtual void AdvanceProcess();
    virtual bool EvaluateActorPackage(Actor* apActor, TESPackage* apPackage, bool abInCombat);
    virtual bool FindPackageToEvaluate(Actor* apActor, TESPackage*& apPackage);
    virtual float GetFirstProcessFloat() const;
    virtual void SetCurrentSpeed(float afValue);
    virtual void EvaluateCurrentPackage(Actor* apActor);
    virtual void SelectPackage(Actor* apActor, bool abInterateIndex);
    virtual void SetPackageForActor(Actor* apActor, TESPackage* apPackage, bool abCheck);
    virtual bool HasInterruptPackage() const;
    virtual void SetEssentialFlag(bool abVal);
    virtual void PlayRandomIdle(Actor* apActor);
    virtual void ProcessActorIdle(Actor* apActor);
    virtual void PlayIdleAnimation();
    virtual void ClearAnimationState();
    virtual float GetEssentialDownTimer() const;
    virtual void SetEssentialDownTimer(float afValue);
    virtual void ResetEssentialDownTimer();
    virtual DetectionViewData* FindDetectionRecord(Actor* apActor, DETECTION_LEVEL aeDetectionLevel, bool abLineSight,
                                                   int aiLevel, DetectionListType aeType, bool ab360View,
                                                   bool abInCombat);
    virtual BSSimpleList<DetectionViewData*>* GetDetectingActors();
    virtual DetectionEvent* FindDetectionEventForActor(Actor* apActor);
    virtual void AddDetectionEvent(Actor* apActor, NiPoint3 akPosition, SOUND_LEVEL aeSoundLevel,
                                   int aiDetectionEventType, TESObjectREFR* apRef);
    virtual void RemoveDetectionEvent();
    virtual void ClearDetectionEvents();
    virtual void GetWeaponScore();
    virtual void SetWeaponScore(float afVal);
    virtual bool HasCaughtPlayerPickpocketing() const;
    virtual void SetIsWeaponReady(bool abVal);
    virtual void SetAnimationComplete(bool abVal);
    virtual bool IsMovementComplete() const;
    virtual void SetCurrentMovementComplete(bool abVal);
    virtual bool GetCurrentMovementComplete() const;
    virtual TESObjectREFR* GetTarget() const;
    virtual void SetTarget(TESObjectREFR* apTarget);
    virtual TESObjectREFR* GetDoor() const;
    virtual void SetDoor(TESObjectREFR* apDoor);
    virtual void AddDeferredHideLimb(ObjectToAcquire* apObject);
    virtual ObjectToAcquire* GetObjectToAcquire() const;
    virtual void SetFaceAnimationData(ObjectToAcquire* apObject);
    virtual BSFaceGenAnimationData* GetActorFaceGenData(Actor* apActor);
    virtual InventoryStackRecord* GetActiveWeapon() const;
    virtual InventoryStackRecord* GetCurrentAmmo() const;
    virtual bool GetLipQueued() const;
    virtual void SetLipQueued(bool abVal);
    virtual unsigned int GetPackageObjectType() const;
    virtual void SetPackageObjectType(unsigned int auiCount);
    virtual bool SetCurrentArmor(InventoryStackRecord* apWeapon, NiNode* apScene, bool abForce);
    virtual void SetCurrentTorch(InventoryStackRecord* apTorch);
    virtual bool SetCurrentAmmunition(InventoryStackRecord* apAmmo);
    virtual void SetCurrentShield(InventoryStackRecord* apShield);
    virtual void UpdateEquippedItems(Actor* apActor);
    virtual bool IsItemQueued(TESBoundObject* apItem, ExtraDataList* apExtraList, bool abEquip);
    virtual void ProcessEquipmentRequest(Actor* apActor, bool abEquip, TESBoundObject* apItem, int aiNumber,
                                         ExtraDataList* apExtraList, bool abNow, bool abForceEquip, bool abFromMenus,
                                         bool abForceUnequip, bool abEquipCalling,
                                         bool abPlaySound);
    virtual void SetEquippedItem(TESBoundObject* apObject, ExtraDataList* apExtraList);
    virtual void ClearQueuedEquipItems();
    virtual NiNode* GetSceneRoot() const;
    virtual void Assign3DObject(NiAVObject* apNode);
    virtual bool SetAnimationControllerManager(NiControllerManager* apControllerManager, NiNode* apNode);
    virtual NiNode* GetActorRootNode(BipedAnim* apAnim) const;
    virtual NiNode* GetWeaponAttachNode(BipedAnim* apAnim) const;
    virtual NiNode* GetShieldBone(BipedAnim* apAnim) const;
    virtual NiNode* GetQuiverBone(BipedAnim* apAnim) const;
    virtual NiNode* GetTorchAttachNode(BipedAnim* apAnim) const;
    virtual NiNode* GetLeftWeaponBone(BipedAnim* apAnim) const;
    virtual bool ResetAlertState() const;
    virtual bool IsAnimationPlaying() const;
    virtual bool IsAnimationActive() const;
    virtual bool IsAnimationSequenceActive() const;
    virtual Animation* GetAnimation() const;
    virtual bool IsAnimationStateActive() const;
    virtual void SetAnimationStateActive(bool abVal);
    virtual bool IsProcessTaskComplete() const;
    virtual void SetProcessTaskComplete(bool abVal);
    virtual void PlayAnimation(bool abDrawn, BipedAnim* apBipedAnim, Animation* apAnim,
                               Actor* apActor);
    virtual void SetCurrentBoundObject(TESObject* apItem);
    virtual TESObject* GetCurrentBoundObject() const;
    virtual void RunActorProcessing(Actor* apActor);
    virtual void RefreshActorMovement(Actor* apActor, bool abFlag);
    virtual float GetProcessBlendAmount() const;
    virtual void SetAnimationTimer(float afVal);
    virtual void SetCombatDelayFadeTimer(float afVal);
    virtual bool IsProcessConditionMet() const;
    virtual void SelectActorCombatTarget(Actor* apActor);
    virtual bool IsCombatTargetForActor(Actor* apActor, Actor* apTarget) const;
    virtual bool CanAttackTarget(Actor* apActor, Actor* apTarget) const;
    virtual bool IsActorTargetValid(Actor* apActor, Actor* apTarget) const;
    virtual bool IsCurrentPackageTarget(Actor* apActor);
    virtual bool IsValidCombatTarget(Actor* apActor, Actor* apTarget);
    virtual float GetDistanceBetweenActors(Actor* apActor, Actor* apTarget);
    virtual TESPackage* GetRunOncePackage() const;
    virtual void AssignRunOncePackage(TESPackage* apPackage, Actor* apActor);
    virtual void StopRunOncePackage();
    virtual void SetRunOncePackageIndex(int aiIndex);
    virtual int GetCurrentProcedure() const;
    virtual void SetCurrentProcedure(int aiOffset);
    virtual void ClearDialogueItems();
    virtual bool IsPackageRunningForActor(Actor* apActor) const;
    virtual TESPackage* GetCurrentPackage() const;
    virtual void SetCurrentPackageAndTarget(TESPackage* apPackage, Actor* apActor);
    virtual void StopPackage();
    virtual void SetPackageInfoState(int aiIndex);
    virtual int GetPackageState() const;
    virtual void SetPackageExecutionState(int aiOffset);
    virtual void ResetCurrentPackage();
    virtual DialogueItem* GetCurrentDialogueItem() const;
    virtual void SetCurrentDialogueItem(DialogueItem* apSubtitle);
    virtual void MoveToPosition(Actor* apActor, NiPoint3 akPoint, float afRadius, float afTimeToExpire,
                                float afAvoidanceStrength, TESObjectREFR* apRef,
                                TESObjectSTAT* apMarker);
    virtual PathingAvoidNodeArray* GetPathingAvoidNodeArray(Actor* apActor); // slot 149: HighProcess 0x00904450 (ret 4)
    virtual bool IsReferenceAvoided(TESObjectREFR* apRef) const;
    virtual void SetAnimationTime(float afVal);
    virtual void SetDetectionTarget(TESObjectREFR* apRef);
    virtual float GetDetectionProgress() const;
    virtual void SetDetectionLevel(float afVal);
    virtual void ClearCurrentTarget();
    virtual ActorPackageData* GetRunOncePackageData() const;
    virtual ActorPackageData* GetCurrentPackageData() const;
    virtual ActorPackageContext* GetCurrentProcessData() const;
    virtual TESPackage* GetOneTimePackage() const;
    virtual int GetPackageInfoValue() const;
    virtual void SetAnimationState(unsigned int aiIndex);
    virtual void SetProcessTarget(MobileObject* apTarget, int aiOffset);
    virtual bhkCharacterController* GetPhysicsCharacterController() const;
    virtual void AssignCharacterController(NiPointer<bhkCharacterController> arController); // slot 164: 0x008d84a0 destroys its by-value argument
    virtual void StopActorMovement(Actor* apActor);
    virtual void UpdateActorPackage(Actor* apActor, bool abFlag, unsigned int aeMoveMode,
                                    bool abPursuit);
    virtual void EvaluatePackage(Actor* apActor, bool abNewPackage, bool abInterateIndex,
                                 unsigned int aeMoveMode);
    virtual void ProcessFlee(Actor* apActor);
    virtual void ProcessDialogueTopic(Actor* apActor, TESTopic* apTopic, bool abForceSub, bool abStop, bool abQueue,
                                      bool abSayCallBack);
    virtual void StartActorInteraction(Actor* apActor);
    virtual void UpdateActorInteraction(Actor* apActor);
    virtual bool IsActorProcessable(Actor* apActor);
    virtual bool IsFurnitureType(TESObjectREFR* apFurnitureRef, unsigned int auiFurnitureType);
    virtual bool CanDetectActor(Actor* apActor);
    virtual void UpdateActorStateWithOptions(Actor* apActor, bool abNewPackage, bool abIterateIndex, unsigned int aeMoveMode,
                               bool abSecondLoc);
    virtual WadingWaterData* GetWadingWaterData() const;
    virtual void SetActorDetectionLevel(Actor* apActor, DetectionListType aeType);
    virtual void SetDetectionTimer();
    virtual bool IsActorVisibleToActor(Actor* apActor, Actor* apTarget, DetectionListType aeType,
                                       bool abFullTest);
    virtual bool IsActorDetected(Actor* apActor, Actor* apTarget, DetectionListType aeType);
    virtual int GetDetectionCount(Actor* apTarget, DetectionListType aeType) const;
    virtual bool IsDetectionEnabled() const;
    virtual void SetActorProcessEnabled(bool abVal);
    virtual void SetActorProcessTime(Actor* apActor, float afTimeDelta);
    virtual int GetActorReferenceState(Actor* apActor, TESObjectREFR* apTarget);
    virtual DIALOGUE_EMOTION GetCurrentDialogueEmotion() const;
    virtual void SetDialogueEmotion(DIALOGUE_EMOTION aeEmotion);
    virtual void RunDetection(Actor* apActor, float afTimeDelta); // slot 188: HighProcess 0x008e40d0 (ret 8)
    virtual double GetDetectionStrength();
    virtual void ResetDetectionState();
    virtual void UpdateActorLighting(float afVal);
    virtual float UpdateProcessTiming() const;
    virtual void SetSurfacing(bool abVal);
    virtual bool GetSurfacing();
    virtual bool IsDetecting() const;
    virtual void SetCombatAlerted(bool abVal);
    virtual float GetSecondProcessFloat() const;
    virtual void SetLipSyncValue(float afVal);
    virtual bool IsCurrentlyAlerted() const;
    virtual void SetAlert(bool abVal);
    virtual bool HasCombatStarted();
    virtual void SetIsWeaponDrawn(bool abVal);
    virtual InventoryStackRecord* GetPackageObject(Actor* apActor, PACKAGE_OBJECT_TYPE aePackageObjectType);
    virtual void ClearPackageObjectList();
    virtual float GetRadiationRate() const;
    virtual void SetRadiationRate(float afValue);
    virtual bool ShouldAttackTarget(Actor* apActor, Actor* apTarget, bool, bool abIsEvil, ActorCombatGroup* apCombatGroup,
                                    bool, bool, bool abIsAggressor, bool, bool abIgnoreActorLimit, bool, bool,
                                    TESPackage* apPackage);
    virtual void SetCombatTargetForActor(Actor* apActor, Actor* apCriminal);
    virtual void CallForHelp(Actor* apActor, Actor* apCriminal, Crime* apCrime);
    virtual void SetCrimeCategory(int aiVal);
    virtual unsigned int GetAttackChance(Actor* apActor, float afDistanceSq, float afShortDistSq, float afLongDistSq,
                                         bool abAlarmOrCombat, bool abPureTravel) const;
    virtual void SetActorDetectionState(Actor* apActor, unsigned int aeMoveMode,
                                        bool abCheckAlwaysRun);
    virtual void FinishDying(Actor* apActor);
    virtual bool MoveToTarget(Actor* apActor, float afRadius, unsigned int aeMoveMode);
    virtual bool ClearProcessStateFlags() const;
    virtual bool IsCurrentProcessComplete() const;
    virtual void SetCurrentProcessComplete(bool abVal);
    virtual int GetActorStateCode(Actor* apActor);
    virtual bool HasActorAlertState() const;
    virtual void SetDialogueState(bool abVal);
    virtual void SetTalkingState(bool abVal);
    virtual bool IsActorTalking() const;
    virtual LipSyncAnimation* GetLipSync() const;
    virtual void AssignLipSyncAnimation(LipSyncAnimation* apAnim);
    virtual void Virtual384(int);
    virtual bool GetPlantedExplosive() const;
    virtual TESIdleForm* GetActiveIdleForm() const;
    virtual void SetLastPlayedIdle(TESIdleForm* idleForm);
    virtual void RefreshActorValues(Actor* apActor);
    virtual int GetActorValueI(TESActorBase* apBase, ActorValue::Index aeIndex, Actor* apActor);
    virtual float GetActorValueF(TESActorBase* apBase, ActorValue::Index aeIndex, Actor* apActor);
    virtual void TempModActorValueF(Actor* apActor, ActorValue::Index aeIndex, float afVal);
    virtual void TempModActorValueI(Actor* apActor, ActorValue::Index aeIndex, int aiVal);
    virtual void DamageModActorValueF(Actor* apActor, ActorValue::Index aeIndex, float afVal);
    virtual void DamageModActorValueI(Actor* apActor, ActorValue::Index aeIndex, int aiVal);
    virtual void InvalidateValue(ActorValue::Index aeIndex);
    virtual void InitializeActiveEffectList();
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() const;
    virtual void DestroyActiveEffectList();
    virtual void CastSpellOnCaster(MagicCaster* apCaster, SpellItem* apAbility, bool abLoadCast);
    virtual void CastSpellAtTarget(MagicCaster* apCaster, SpellItem* apDisease, MagicTarget* apTarget,
                                   bool abLoadCast);
    virtual MagicItem* GetSelectedMagicItem() const;
    virtual void SetSelectedMagicItem(MagicItem* apSpell);
    virtual MagicTarget* GetCurrentMagicTarget() const;
    virtual void SetMagicTarget(MagicTarget* apTarget);
    virtual bool UpdateIdleAnimation() const;
    virtual void SetBooleanState(bool abVal);
    virtual void Move(MobileObject* apObject, NiPoint3 akSideVector);
    virtual ProcessAnimationAction GetAnimAction() const;
    virtual BSAnimGroupSequence* GetActorProcessTime() const;
    virtual void SetAnimAction(ProcessAnimationAction aeAnimationAction,
                               BSAnimGroupSequence* apSequence);
    virtual bool IsAnimationSequencePlaying() const;
    virtual void SetIsAlerted(bool abVal);
    virtual bool IsAimingWeapon() const;
    virtual bool IsAimingAtActor(Actor* apActor);
    virtual void SetAimingWeapon(bool isAiming);
    virtual bool IsAlert() const;
    virtual bool HasAnimationGroup(ANIM_GROUP_TYPE aeAnim);
    virtual int GetKnockedState();
    virtual void SetKnockedState(char state);
    virtual void KnockDown(Actor* apActor);
    virtual void PushActorAway(Actor* apActor, NiPoint3 akSource, float afForce);
    virtual void UpdateActorData(Actor* apActor);
    virtual void ProcessActorEvent(Actor* apActor);
    virtual void SetAnimationSequence(int aeDirection, BSAnimGroupSequence* apSequence);
    virtual void RefreshActorAnimation(Actor* apActor);
    virtual float GetAimAngle() const;
    virtual void SetAimAngle(float afValue);
    virtual void SetStartShooting(bool abStartShooting);
    virtual unsigned char GetAttackState(Actor* apTarget);
    virtual void SetBodyPartState(unsigned char aucCount);
    virtual unsigned char GetProcessStateByte() const;
    virtual float GetVisibilityAlpha() const;
    virtual void SetAttackCount(int aiNumAttacks);
    virtual bool IsFirstActorFlagSet() const;
    virtual void SetIsSwimming(bool abVal);
    virtual bool IsAdditionalActorFlagSet() const;
    virtual void SetActorMovementState(Actor* apActor, bool abVal);
    virtual void SetWeaponLastPos(NiPoint3 akPos);
    virtual NiPoint3* GetLastKnownPosition() const;
    virtual void Update3DModel(Actor* apActor);
    virtual void ResetActorModel(RESET_3D_FLAGS aucFlag); // slot 282: 0x008d8740 reads a 32-bit enum
    virtual void SetDetectionFlag(unsigned char aucFlag);
    virtual void ClearDetectionFlag();
    virtual bool IsProcessFlagSet(unsigned char aucFlag) const;
    virtual unsigned char GetCurrentTargetType() const;
    virtual void ClearReferenceRecords(TESObjectREFR* apObject);
    virtual void ClearObjectFromAcquireListAlt(unsigned int auiFormID);
    virtual TESObjectREFR* GetPreviousReference() const;
    virtual void SetActorTargetReference(TESObjectREFR* apRef);
    virtual BSSoundHandle GetActorSoundHandle(unsigned int aeType);
    virtual void SetActorSoundHandle(unsigned int aeType, BSSoundHandle akHandle);
    virtual void StopActorSound(unsigned int aeType);
    virtual void UpdateMovementStopped(Actor* apActor);
    virtual bool GetMovementStopped() const;
    virtual void ClearMovementStopped();
    virtual void SetDiveBreathLevel(float afVal);
    virtual void StopAllActorSounds();
    virtual float GetDiveBreathLevel() const;
    virtual float GetMovementTimer() const;
    virtual void UpdateActorProcess(float afVal);
    // Slot 302 (+0x4b8): BaseProcess 0x008d0370 and HighProcess 0x008f6fc0 both ret 4 (one argument, a MobileObject*).
    virtual bool IsTalking(MobileObject* apTarget) const;  // const: HighProcess.h's non-virtual IsTalking stays as it is until highprocess.cpp moves
    virtual SIT_SLEEP_STATE GetSitSleepState() const;
    virtual void SetFurnitureState(Actor* apActor, SIT_SLEEP_STATE aeState, TESObjectREFR* apFurniture,
                                   unsigned char aucFurnitureIndex);
    virtual unsigned int GetFurnitureMarkerID() const;
    virtual TESObjectREFR* GetFurnitureReference() const;
    virtual void RemoveFurniture(TESObjectREFR* apFurnitureRef);
    virtual unsigned int GetFurnitureMarkerIndex() const;
    virtual FurnitureMark* GetFurnitureMarkerData() const;
    virtual bool IsFurnitureMarkerValid(Actor* apActor);
    virtual void AssignAnimation(Actor* apActor, Animation* apAnimation);
    virtual bool HasAssignedAnimation() const;
    virtual void SetAnimationEnabled(bool abVal);
    virtual bool IsPlayingAnimation() const;
    virtual void SetProcessConditionMet(bool abVal);  // LowProcess override 0x008d7fe0 reads its bool argument (ret 4)
    virtual bool IsProcessStateEnabled() const;
    virtual void SetWeaponOutState(bool abVal);
    virtual BSShaderPPLightingProperty* GetPixelLightingProperty() const;
    virtual void SetPixelLightingProperty(BSShaderPPLightingProperty* apProp);
    virtual void SetDetectionState(Actor* apActor, bool abIgnoreTorch);
    virtual DetectionViewData* GetDetectionState(Actor* apTarget, DetectionListType aeType) const;
    virtual DetectionViewData* InsertIntoDetectionArray(Actor* apTarget,
                                                        DETECTION_LEVEL aeDetectionLevel);
    virtual double GetLightUpdateTimer() const;
    virtual void SetLightUpdateTimer(float afVal);
    virtual TESObjectREFR* GetActiveCombatTarget() const;
    virtual void SetCurrentCombatTarget(TESObjectREFR* apLocation);
    virtual TESObjectREFR* GetProcessReference() const;
    virtual void SetCurrentLocationReference(TESObjectREFR* apLocation);
    virtual void UpdateCurrentPackage(Actor* apActor);  // LowProcess 0x00910b30: ret 4
    virtual void SetTalkTarget(Actor* apActor);
    virtual Actor* GetCurrentTalkTarget() const;
    virtual void SetEquippedWeapon(TESObjectWEAP* apWeapon);
    virtual ActorValue::Index GetWeaponForm() const; // slot 333: 0x008d85e0, actor-value index in combat callers
    virtual void SetActorAlpha(float afVal);
    virtual float GetActorAlpha() const;
    virtual void SetFurnitureMarkerData(TESObjectREFR* apFurnitureRef, unsigned char aucMarkerIndex,
                                        FurnitureMark* apMark);
    virtual void ApplyProcessLevelChange(MobileObject* apObject);
    virtual unsigned short GetSaveSize(unsigned int auiFlags, MobileObject* apObject);
    virtual void SaveGameBGS(BGSSaveGameBuffer* apBuffer);
    virtual void SaveGameTES(unsigned int auiFlags, MobileObject* apObject);
    virtual void LoadGameBGS(BGSLoadFormBuffer* apBuffer);
    virtual void LoadGameTES(unsigned int auiFlags, unsigned int auiCurrentFlags,
                             MobileObject* apObject);
    virtual void InitLoadGameBGS(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGameTES(unsigned int auiFlags, unsigned int auiOldFlags,
                                 MobileObject* apObject);
    virtual void FinishLoadGameTES(unsigned int auiFlags, unsigned int auiOldFlags,
                                   MobileObject* apObject);
    virtual void RevertBGS(BGSLoadFormBuffer* apBuffer);
    virtual void RevertTES(unsigned int auiFlags, MobileObject* apObject);
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer*); // slot 348: BaseProcess 0x008d1050 consumes the load buffer
    virtual TESEffectShader* GetCurrentEffectShader() const;
    virtual void AssignEffectShader(TESEffectShader* apShader);
    virtual bool IsProcessStateInitialized() const;
    virtual void UpdateActorAppearance(bool abUpdateWeaponEffectShader, bool abInitializeActiveHitEffect,
                                       bool);
    virtual void RefreshActorProcessState(Actor* apActor);
    virtual void SetIdleAnimationPlayed(bool abVal);
    virtual bool IsPlayedState() const;
    virtual void SetPlayedState(bool abVal);
    virtual bool WasIdleAnimationPlayed() const;
    virtual void OnPackageChanged(Actor* apActor, TESPackage* apPackage);
    virtual void OnPackageStart(Actor* apActor, TESPackage* apPackage);  // 0x009135a0 (LowProcess), 0x00903bf0 (HighProcess): no return value
    virtual void OnPackageEnd(Actor* apActor, TESPackage* apPackage);
    virtual bool IsProcessActivityActive() const;
    virtual void SetProcessModeEnabled(bool abVal);
    virtual float GetLightIntensity() const;
    virtual void SetUnderwaterBreathTime(float afVal);
    virtual float GetThirdProcessFloat() const;
    virtual void SetWadingWaterLevel(float afVal);
    virtual void UpdateWadingWater(Actor* apActor);
    virtual int GetProcessIndex() const;
    virtual void SetProcessIndex(int aiVal);
    virtual bool HasActiveEffectOfType(BSSimpleList<ActiveEffect*>* apEffects,
                                       unsigned int aeFlareType);
    virtual void RefreshMagicEffects();
    virtual BSSimpleList<SpellItem*>* GetActorSpellList(Actor* apActor, bool abIncludeDiseases);
    virtual void SetCastingState(int aiHasSpells);
    virtual int GetCurrentAnimAction() const;
    virtual void SetCurrentMoveMode(int aiHasHealingPotion);
    virtual int GetPendingIdleFlags() const;
    virtual float GetPermanentActorValueFloat(ActorValue::Index aeActorValue);
    virtual float GetDamageActorValue(ActorValue::Index aeActorValue);
    virtual float GetTemporaryActorValue(ActorValue::Index aeActorValue);
    virtual BSBound* GetBound() const;
    virtual void SetObjectBound(BSBound* apBound);
    virtual void SetIsSitting(bool abVal);
    virtual bool IsActorInCombat() const;
    virtual void SetCombatState(bool abVal);
    virtual bool IsCurrentlyDetected() const;
    virtual BSSimpleList<Actor*>* GetActorsInAggroRadius() const;
    virtual void ProcessActorReferences(Actor* apActor, Actor* apTarget, Actor* apAlly);
    virtual FadeState GetCurrentFadeState() const;
    virtual void AddPostAnimAction(PostAnimAction aeFlag);
    virtual unsigned int GetPostAnimationAction() const;
    virtual void ClearPostAnimActions();
    virtual void SetProcessState(PostAnimAction aeFlag);
    virtual void SetPreviousReference(TESObjectREFR* apTarget);
    virtual void SetActorProcessState(TESObjectREFR* apTarget);
    virtual void SetPackageTargetReference(TESObjectREFR* apTarget);
    virtual void SetCombatTargetReference(TESObjectREFR* apTarget);
    virtual void ClearHighProcessState(TESObjectREFR* apTarget);
    virtual void SetLastKnownReference(TESObjectREFR* apTarget);
    virtual void SetTargetReferenceByIndex(HeadTrackType aeType, TESObjectREFR* apTarget);
    virtual void ClearPackageData();
    virtual void ClearCachedTargetReferences(bool abHoldDefault);
    virtual void SetCombatActive(bool abHoldDefault);
    virtual void ResetCombatState();
    virtual void RestorePreviousReference(bool abHoldDefault);
    virtual void SetProcessActive(bool abHoldDefault);
    virtual void UpdatePlayerAwarenessTimer();
    virtual float GetCurrentAlpha() const;
    virtual void ResetHeadTrackingTarget();
    virtual void SetCurrentTargetReference(TESObjectREFR* apTarget);
    virtual bool HasNoPendingEntriesAndExpired();
    virtual bool HasNoPendingEntries();
    virtual bool CanSetDialogHeadTrackTarget();
    virtual TESObjectREFR* GetCurrentHeadTrackTargetByType(HeadTrackType aeType);
    virtual TESObjectREFR* GetPrimaryTargetReference();
    virtual unsigned int GetCombatTargetCount() const;
    virtual const char* GetCurrentPackageName() const;
    virtual void SetIsTalking(bool abVal);
    virtual bool IsCombatTargetValid() const;
    virtual TESObjectREFR* GetRelatedReference() const;
    virtual bool IsInLastDefaultTargetArray(TESObjectREFR* apRef);
    virtual void SetHasLastDefaultTargetArray(bool abVal);
    virtual bool BeginIdleAnimation() const;
    virtual float GetCurrentDetectionAmount() const;
    virtual void SetLightingAmount(float afVal);
    virtual void AddArrowProjectile(ArrowProjectile* apArrow);
    virtual void UnregisterArrowProjectile(ArrowProjectile* apArrow);
    virtual void SetArrowTargetReference(TESObjectREFR* apRef);
    virtual BSSimpleList<ArrowProjectile*>* GetArrowProjectiles() const;
    virtual void SetProjectileTarget(Projectile* apProjectile, TESObjectREFR* apShooter);
    virtual NiObjectNET* GetMuzzleFlash() const;
    virtual bool GetEnableMuzzleFlash();
    virtual void EnableMuzzleFlash();
    virtual void ClearMuzzleFlash();
    virtual void ApplyBodyPartData(NiNode* apNode, BGSBodyPartData* apBodyPartData);
    virtual void SetNodeForType(LIMB_TYPE aeBodyPart, NiNode* apNode);
    virtual NiNode* GetNodeByType(LIMB_TYPE aeBodyPart) const;
    virtual NiNode* GetFirstSceneObject() const;
    virtual NiNode* GetActorSceneObject() const;
    virtual bool GetSustainedFire() const;
    virtual void SetSustainedState(bool abVal);
    virtual void RunActorProcess();
    virtual void IsWearingHeavyArmor();
    virtual bool IsWearingPowerArmorTorso();
    virtual bool IsWearingPowerArmorHelmet();
    virtual bool IsWearingBackpack();
    virtual void SetIdleStateFlag(bool abVal);
    virtual bool IsProcessStateActive() const;
    virtual void UpdateReferenceTime(Actor* apActor, float afTimeDelta);
    virtual void UpdateActorProcessState(Actor* apActor);
    virtual void SelectAnimationAction(int aiValue);
    virtual void UpdateActorReferences(Actor* apActor);
    virtual void SetProcessReference(TESObjectREFR* apRef);
    virtual void SetMobileObjectTarget(TESObjectREFR* apRef);
    virtual TESIdleForm* GetSelectedIdleForm() const;
    virtual void SetIdleForm(TESIdleForm* apIdleForm);
    virtual void SetIdleAnimation(AnimIdle* apAnimIdle, KFModel* apAnimIdleKF);
    virtual AnimIdle* GetIdleAnimation() const;
    virtual KFModel* GetIdleAnimationModel() const;
    virtual void ApplyDamageToActor(Actor* apSource, float afDamage);
    virtual float GetLastDamage() const;
    virtual float GetProcessBlendWeight() const;
    virtual void SetLightLevel(float afLightAmount);
    virtual void AttachWeaponNode(LIMB_TYPE aeLimbIndex, NiNode* apDismemberedLimbRoot, NiAVObject* apReplacementLimb,
                                  bool abExplosion);
    virtual void UpdateActorWithTime(Actor* apActor, float afTimeDelta);
    virtual void SetLipSyncAnimation(LipSyncAnimation* apAnim);
    virtual LipSyncAnimation* GetLipSyncAnimationData() const;
    virtual void UpdateEffectShader(unsigned int auiTime);
    virtual unsigned int GetAnimationState() const;
    virtual void SetActorMovementRate(float afVal);
    virtual void SetMovementTimer(float afVal);
    virtual float GetAnimationElapsedTime() const;
    virtual void AdvanceMovementTimer(float afVal);
    virtual float GetAnimationRemainingTime() const;
    virtual void SetWaterLevel(float afVal);
    virtual float GetControllerPhase() const;
    virtual BooleanFloatQuery* RefreshActorRuntimeData() const;
    virtual void SetProcessObject(BooleanFloatQuery* apHitData);
    virtual void ResetHitData();
    virtual BooleanFloatQuery* GetCurrentObjectData();
    virtual void SetHitData(BooleanFloatQuery* apHitData);
    virtual void ResetTargetHitData();
    virtual int GetSleepSitState();
    virtual void SetKnockdownStage(int aiStage);
    virtual BSFaceGenNiNode* GetFacialAnimationNode() const;
    virtual void AttachFaceGenerationNode(BSFaceGenNiNode* apNode);
    virtual BSFaceGenNiNode* GetFaceGenHeadNode() const;
    virtual void SetFaceGenHeadNode(BSFaceGenNiNode* apNode);
    virtual NiAVObject* GetAnimationObject() const;
    virtual void SetAnimationNode(NiAVObject* apObject);
    virtual void SetActorTarget(Actor* apActor);
    virtual void SetLastTargetReference(TESObjectREFR* apTarget);
    virtual void ClearTargetReference(TESObjectREFR* apTarget);

    ActorPackageContext m_kProcessData;
    float m_fValue2;
    float m_fValue1;
    unsigned int m_uiStateFlags;
    PROCESS_TYPE m_eProcessType;
    CachedValues* m_pCachedValues;

    void ApplyKnockback(Actor* apActor, NiPoint3 akSource, float afForce);

    PROCESS_TYPE GetProcessLevel() const;
    PROCESS_TYPE GetProcessLevel();
    int FUN_0045cd60();
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void ProcessNode(PlayerCharacter*);
    void SetPlaybackTime(Actor*, unsigned int, unsigned int);
    void SetPlaybackTime(Actor*, TESObjectREFR*, bool);
    void FUN_007037c0(unsigned int);
    float FUN_007df1f0();
    void BaseProcess_SetLastTimeProcessed(float);
    unsigned int FUN_0059bb30();
    double GetField43C();
    float GetField440();
    void HighProcess_SetRadiationLevel(float);
    void AddAvoidArea(Actor*, NiPoint3, float, float, float, TESObjectREFR*, bool);
    void HighProcess_SetSkippedLastUpdate(bool active);

    void SetLipSyncEnabled(bool abVal);
};

typedef char BaseProcess_size_check[(sizeof(BaseProcess) == 0x30) ? 1 : -1];
typedef char BaseProcess_process_data_offset_check[(offsetof(BaseProcess, m_kProcessData) == 0x04) ? 1 : -1];
typedef char BaseProcess_value2_offset_check[(offsetof(BaseProcess, m_fValue2) == 0x1C) ? 1 : -1];
typedef char BaseProcess_value1_offset_check[(offsetof(BaseProcess, m_fValue1) == 0x20) ? 1 : -1];
typedef char BaseProcess_state_flags_offset_check[(offsetof(BaseProcess, m_uiStateFlags) == 0x24) ? 1 : -1];
typedef char BaseProcess_process_type_offset_check[(offsetof(BaseProcess, m_eProcessType) == 0x28) ? 1 : -1];
typedef char BaseProcess_cached_values_offset_check[(offsetof(BaseProcess, m_pCachedValues) == 0x2C) ? 1 : -1];
