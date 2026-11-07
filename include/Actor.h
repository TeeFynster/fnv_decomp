#pragma once

#include "MobileObject.h"
#include "MagicCaster.h"
#include "MagicTarget.h"
#include "ActorValueOwner.h"
#include "CachedValuesOwner.h"
#include "NiPoint3.h"
#include "ActorValueModifierList.h"

class bhkRagdollController;
class bhkRagdollPenetrationUtil;
class CombatGroupCollection;
class ActorListEntry;
class ActorMover;
class ContinuousBeamProjectile;
template <class T, unsigned int Growth> class BSSimpleArray;

class AlchemyItem;
struct CombatPoint3;
class ActorBase;
class BCaster_S;
class BooleanFloatQuery;
class Box;
class FurnitureMark;
class CListener;
class Context;
class Effect;
class Entry;
class Form;
class FourFloatVector;
class History;
class Idle;
class NiPoint3;
class Obj;
class Path;
class PathingAvoidNodeArray;
class NiPoint3;
class Ref;
class Refr;
class RetObj;
class Scene;
class TESFaction;
class TESIdleForm;
class V;
class NiPoint3;
class Vec4;
class Weapon;

class ActorCombatGroup;
class Animation;
class BGSPerk;
class BGSPerkEntry;
class BSFaceGenAnimationData;
class CombatController;
class PlayerCharacter;
class TESActorBase;
class TESObjectWEAP;
class TESPackage;
class FleePackage;
class TrespassPackage;
class TESRace;
class ActorPackageAccess;
class BaseForm;
class InventoryStackRecord;
class LookTarget;
class Package;
class PathMover;
class Position;
class Target;
struct HandleRef;

namespace ScriptAnimation {
class Idle;
struct ResultList;
}

enum DIALOGUE_EMOTION;
enum SIT_SLEEP_STATE;
enum ACTOR_LIFE_STATE;
enum ACTOR_CRITICAL_STAGE;
enum ANIM_GROUP_ENUM;
enum SEX;

class Actor : public MobileObject,
              public MagicCaster,
              public MagicTarget,
              public ActorValueOwner,
              public CachedValuesOwner
{
public:
    bhkRagdollController* m_pRagdollController;            // +0xAC
    bhkRagdollPenetrationUtil* m_pRagdollPenetrationUtil;  // +0xB0
    DIALOGUE_EMOTION m_eDialogueEmotion;                   // +0xB4
    float ActorRagdollData;                                // +0xB8
    bool m_bFirstActorFlag;                                // +0xBC
    unsigned char layoutPaddingBD;
    unsigned short layoutPaddingBE;
    Actor* m_pActorReference;  // +0xC0
    bool m_bActorFlag;         // +0xC4
    unsigned char layoutPaddingC5;
    unsigned short layoutPaddingC6;
    float m_fFirstValueAfterFlag;     // +0xC8
    float m_fSecondScalar;            // +0xCC
    ActorValueModifierList m_kFirstActorData;   // +0xD0
    ActorValueModifierList m_kSecondActorData;  // +0xE0
    bool m_bFlagBeforeTwoBooleans;    // +0xF0
    bool m_bMiddleFlag;               // +0xF1
    bool m_bThirdActorFlag;           // +0xF2
    unsigned char layoutPaddingF3;
    BSSimpleList<CombatGroupCollection*> m_kFirstPointerList;         // +0xF4
    BSSimpleList<ActorListEntry*> m_kSecondPointerList;  // +0xFC
    bool m_bActorStateFlag;                                   // +0x104
    unsigned char layoutPadding105;
    unsigned short layoutPadding106;
    ACTOR_LIFE_STATE m_eLifeState;          // +0x108
    ACTOR_CRITICAL_STAGE m_eCriticalStage;  // +0x10C
    ANIM_GROUP_ENUM m_eAnimationGroup;      // +0x110
    float ActorConditionAndAnimationState;  // +0x114
    bool m_bHasUpdated;                     // +0x118
    unsigned char layoutPadding119;
    unsigned short layoutPadding11A;
    int m_iActorStateValue;                            // +0x11C
    unsigned int m_uiValueBeforeBooleanFields;         // +0x120
    bool ActorStateFlags;                              // +0x124
    bool ActorReferenceData;                           // +0x125
    bool ActorReferenceListData;                       // +0x126
    bool m_bFlagBeforeCurrentActor;                           // +0x127
    Actor* m_pCurrentActor;                            // +0x128
    BSSimpleArray<Actor*, 1024>* m_pFirstActorArray;   // +0x12C
    BSSimpleArray<Actor*, 1024>* m_pSecondActorArray;  // +0x130
    bool m_bActorListValid;                            // +0x134
    unsigned char layoutPadding135;
    unsigned short layoutPadding136;
    int m_iIntegerAfterActorListValid;                     // +0x138
    unsigned int m_uiFirstValueAfterInteger;  // +0x13C
    unsigned int m_uiActorFlags;              // +0x140
    bool ActorStatusData;                     // +0x144
    bool ActorBaseConfiguration;              // +0x145
    bool m_bFlagBeforeActorBase;              // +0x146
    unsigned char layoutPadding147;
    TESActorBase* m_pActorBase;              // +0x148
    bool ActorBaseReference;                 // +0x14C
    bool m_bSecondActorFlag;                 // +0x14D
    bool m_bThirdBooleanFlagAfterActorBase;  // +0x14E
    unsigned char layoutPadding14F;
    int m_iIntegerBeforeTwoFloatValues;                  // +0x150
    float BooleanIntegerTwoFloatData;  // +0x154
    float IntegerFloatFlagSettings;    // +0x158
    bool m_bFirstBehaviorFlag;         // +0x15C
    bool m_bSecondOfTwoFlags;          // +0x15D
    unsigned short layoutPadding15E;
    NiPoint3 m_kFormPosition;     // +0x160
    float FormPositionData;       // +0x16C
    TESForm* FormReferenceState;  // +0x170
    bool m_bFirstFlagAfterForm;   // +0x174
    bool m_bFormFlag;             // +0x175
    unsigned short layoutPadding176;
    float TwoBooleanFourFloatData;       // +0x178
    float BooleanAndFiveFloatSettings;   // +0x17C
    float FiveFloatBooleanData;          // +0x180
    float FloatFlagSettings;             // +0x184
    float m_fFourthFloat;                // +0x188
    bool FloatTripleBooleanFlagRecord;   // +0x18C
    bool m_bMiddleFlagBeforeActorMover;  // +0x18D
    bool m_bMovementFlag;                // +0x18E
    unsigned char layoutPadding18F;
    ActorMover* m_pActorMover;                              // +0x190
    void* m_pData;                                          // +0x194
    TESPackage* m_pPackage;                                 // +0x198
    float m_fPackageParameter;                         // +0x19C
    ContinuousBeamProjectile* m_pContinuousBeamProjectile;  // +0x1A0
    int m_iPackageState;                                           // +0x1A4
    int ActorProjectileState;                               // +0x1A8
    SIT_SLEEP_STATE m_eSitSleepState;                       // +0x1AC
    bool m_bFlagAfterSitSleepState;                         // +0x1B0
    bool ActorSleepState;                                   // +0x1B1
    unsigned short layoutPadding1B2;

    // Exe/RTTI slot 23: 0x008ab3a0, called directly by Creature.
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual bool Unk_C1();
    virtual void Unk_C2(void);
    virtual void Unk_C3(void);
    virtual void Unk_C4(void);
    virtual void Unk_C5(void);
    virtual void Unk_C6(void);
    virtual void Unk_C7(void);
    virtual bool IsDead(void);
    virtual void Resurrect(bool resetInventory, bool attach3D, bool unk);
    virtual void Unk_CA(void);
    virtual void Unk_CB(void);
    virtual void Unk_CC(void);
    virtual void Unk_CD(void);
    virtual void DamageHealthAndFatigue(float health, float fatigue, Actor* attacker);
    virtual void Unk_CF(void);
    virtual void Unk_D0(void);
    virtual int Unk_D1(TESObjectREFR*, void*);   // 0x344: Actor 0x0087fd90 (ret 8)
    virtual void Virtual_348(float delta, int unused);
    virtual void Unk_D3(void);
    virtual void Unk_D4(void);   // 0x008885a0: no arguments (plain ret); calls slot 0x79 and passes this to its result
    virtual float GetMaxRotationSpeed();
    virtual bool Unk_D6(void); // slot 214: 0x0047c850 returns AL=0; callers 0x008ddac0/0x008dddf0 test AL
    virtual void Unk_D7(void);
    virtual bool IsPlayerRef();
    virtual void Unk_D9(void);
    virtual void Unk_DA(void);
    virtual void Unk_DB(void);
    virtual void Unk_DC(void);
    virtual void Unk_DD(void);
    virtual void Unk_DE(void);
    virtual TESRace* GetRace();
    virtual float GetUnarmedReach();
    virtual void Unk_E1(bool, float);
    virtual void Unk_E2(void);
    virtual bool FUN_vt38c();
    virtual int Unk_E4(void);   // 0x390 (UpdateActorPackage 0x008e0f80 tests the result)
    virtual void Unk_E5(void);
    virtual void Unk_E6(void);
    virtual void ModActorValue(ActorValue::Index actorValue, float value, Actor* source);
    virtual void Unk_E8(void);
    virtual void ForceActorValue(ActorValue::Index actorValue, float value, unsigned int flags);
    virtual void ModActorValueInt(ActorValue::Index actorValue, int value, Actor* source);   // 0x3a8: 0x00880c70
    virtual void DamageActorValue(ActorValue::Index actorValue, float value, Actor* source);
    virtual void Unk_EC(void);
    virtual void Unk_ED(void);
    virtual void Unk_EE(void);
    virtual InventoryStackRecord* GetBestWeapon(int aiWeaponType); // 0x3bc: Actor 0x00891c80 (actor.cpp ActorBestWeapon_d), Update 0x008eeec0 passes 6
    virtual void Unk_F0(void);
    virtual void Update();
    virtual void Unk_F2(void);
    virtual int Unk_F3(TESForm*, void*, int, int, int);   // 0x3cc: Actor 0x008929a0 (ret 0x14; vfn_7b4 0x008dfa10 passes the item first)
    virtual void Unk_F4(TESObjectREFR*, int, int); // 0x3d0: Actor 0x00891e00 (ProcessEat 0x008e3140 passes the item, 1, 0)
    virtual void Unk_F5(void);
    virtual void Unk_F6(void);
    virtual void Unk_F7(float);
    virtual void Unk_F8(void);
    virtual void Unk_F9(void);
    virtual void Unk_FA(void);
    virtual void Unk_FB(void);
    virtual void Unk_FC(void);
    virtual void Unk_FD(void);
    virtual ActorCombatGroup* GetCombatGroup();
    virtual void Unk_FF(void);
    // slot 256 (0x400): Actor 0x008d0370 / Character 0x008d2800; HighProcess::ShouldProcessActor passes the
    // ExtraTresPassPackage package, which Character's body hands to TESPackage code (0x00810fd0)
    virtual bool vfn_400(TrespassPackage*);
    virtual TESForm* Unk_101(float arg0);
    virtual ScriptAnimation::ResultList PlayActor(ScriptAnimation::Idle*, Actor*, bool, bool, int, int);
    virtual void Unk_103(void);
    virtual void Unk_104(Actor* target, int type, bool first, bool second, int flags, int state, float firstValue, float secondValue);
    virtual void Unk_105(void);
    virtual void Unk_106(void);
    virtual void SetAlpha(float fAlpha);
    virtual void Unk_108(void);
    virtual void Alert(PlayerCharacter* target, int a, int b, int c, int d, int e, int f, int g);
    virtual CombatController* GetCombatController();
    virtual Actor* GetCombatTarget(void);
    virtual void Unk_10C(void);
    virtual void Unk_10D(Actor* target);
    virtual void Unk_10E(void);
    virtual void Unk_10F(void);
    virtual void Unk_110(void);
    virtual void Unk_111(void);
    virtual bool IsDisabled(void);
    virtual void Unk_113(void);
    virtual void Unk_114(void);
    virtual void Unk_115(void);
    virtual float CalculateRunSpeed();
    virtual float Unk_117(void);
    virtual void Unk_118(void);
    virtual void Unk_119(void);
    virtual void Unk_11A(void);
    virtual void Unk_11B(void);
    virtual bool Unk_11C(void);   // returns the process's slot 0x13C result; FUN_0059ec30 reads al (movzx ecx, al at 0x0059ec76)
    virtual void Unk_11D(void);
    virtual void Unk_11E(void);
    virtual void Unk_11F(void);
    virtual void Unk_120(void);
    virtual void Unk_121(void);
    virtual void GrantExperience(int experience);
    virtual void Unk_123(void);
    virtual void Unk_124(void);
    virtual void Unk_125(void);
    virtual void SetPerkRank(BGSPerk* perk, unsigned char rank, bool alt);
    virtual void Unk_127(void);
    virtual unsigned char GetPerkRank(BGSPerk* perk, bool alt);
    virtual void Unk_129(void);
    virtual void Unk_12A(void);
    virtual BSSimpleList<BGSPerkEntry*>* GetPerkEntriesForEntryPoint(unsigned char entryPoint, bool teammate);
    virtual void Unk_12C(void);
    virtual bool FUN_vt4b4();
    virtual void Unk_12E(void);
    virtual void Unk_12F(void);
    virtual void Unk_130(void);
    virtual void Unk_131(void);
    virtual void Unk_132(void);
    virtual void Unk_133(void);
    virtual void ResetState();
    virtual void Unk_135(void);
    virtual void Unk_136(void);

    virtual ScriptAnimation::ResultList PlayIdle(ScriptAnimation::Idle* idle, Actor* target, int, int, int, int, bool) override;

    virtual ~Actor();
    virtual bool IsActor();

    TESActorBase* GetActorBase();
    bool IsPlayerTeammate();
    bool IsActorEssential();
    void SetActorEssentialState(int value);
    bool IsVisible(int flags);
    TESObjectREFR* GetCombatOpponent();
    void SetCombatOpponent(Actor* actor);
    void SetCurrentSitSleepState(SIT_SLEEP_STATE state);
    float GetFatiguePercentage();
    BaseProcess* GetProcess();
    TESObjectWEAP* GetActiveWeapon();
    bool IsEssentialActor();
    bool IsInDeadState();
    bool GetGhost();
    bool HasEssentialStatus();
    bool IsWithinRadius(int radius);
    bool IsHostileToActor(Actor* target, int arg1, int* arg2, bool arg3);
    MagicCaster* GetMagicCaster();
    int GetBaseLevel();
    unsigned int GetActorStateFlags();
    bool IsMoving();
    bool IsSneaking();
    void UpdateActorMovement(float delta);
    Animation* GetAnimation();
    void SetAnimationGroupAction(int);
    void RefreshActorData();
    void SetAnimationForAction(int, Animation*);
    void UpdateAnimationMovement(Animation*, float);
    void PickAnimations(float, float);
    NiPoint3 GetMovementPosition();
    NiPoint3* GetMagicCaster(NiPoint3* output);
    void GetMagicCaster(NiPoint3& output);
    void SetAlphaAndFade(float fAlpha);
    void UpdateActorEffectState();
    void UpdateDeathState(float);
    void RestoreHealth(float);
    void UpdateLifeState(float);
    float GetFatigue();
    bool CanEnterLifeState();
    void StopMoving();
    BSFaceGenAnimationData* GetActorFaceGenData();
    void OnLifeStateChanged();
    void UpdateActorPresentation();
    void ConfigureActorState(bool bFirst, bool bSecond);
    void AddDefaultSpells();
    void SetActorLifeState(ACTOR_LIFE_STATE m_eLifeState);
    void UpdateFlag800State();
    bool PlaceAtPosition(NiPoint3* apPos);
    void UpdateControllerFlag();
    void TryMakeTargetThing();
    void SetTravelPackage(void*, bool, bool, bool, void*, void*, float, float);
    bool GetByteAt7C4();
    bool CanStartCombat(bool);
    void SetSpeakingState(bool);
    ActorPackageAccess* GetCurrentPackage();
    BaseProcess* GetCurrentProcess();
    float ComputeFromNode(const char*);
    SEX GetSex();
    unsigned short GetLevel();

    void Actor_EndInterruptPackage(bool a);
    void PickpocketAlarm(TESObjectREFR* victimRef, int amount, int crimeValue);
    bool TESObjectREFR_IsAnOwner(Actor* target, bool a);
    void Actor_IncrementMinorCrimes();
    void Actor_AddFactionMinorCrime(bool a, bool b);
    void Actor_InitiatePickPocketWarning(Actor* actor);
    bool Actor_IsUnConscious();
    bool Actor_IsRestrained();
    bool Actor_IsReanimated();
    bool TESForm_IsStillLoading();
    bool GetShouldCheckMagicNode();
    bool IsRefractive();
    int FUN_00931850();
    bool Actor_CouldBeFollowing(TESObjectREFR*);   // 0x008bc860
    void* FUN_00568e50(); // 0x00568e50
    void Actor_SetPathingDoorReference(Actor*); // 0x008b3cb0
    void* BSFile_GetDevice(int); // 0x005d43c0, explicit folded argument
    template <class Point> void Actor_RequestRotate(Point, int); // 0x008bb520, preserve aggregate call ABI
    BSSoundHandle FUN_00933150(unsigned int, bool, unsigned int, bool); // 0x00933150
    template <class Topic> void TESObjectREFR_SetSayToTopic(Topic*); // 0x0057ad20
    void TESObjectREFR_SetSayToResponseID(int); // 0x0057ad60
    bool Actor_ShouldRotateToTrack(TESObjectREFR*); // 0x008a40e0
    int FUN_008dd860(); // 0x008dd860
    TESObjectREFR* GetHeadingTarget(); // 0x008a2ed0
    void FUN_008dd880(); // 0x008dd880
    void PlayerCharacter_ResetPlayerGreetFlag(); // 0x00953ce0
    bool Actor_IsPathValid(); // 0x008b3960
    bool Actor_CanMove(); // 0x008843a0
    void TESObjectREFR_Activate(Actor*, int, int, int); // 0x00573170
    template <class Point> bool Actor_SetPathfindingGoal(const Point&, TESObjectCELL*, void*, float, int); // 0x008b3690
    bool TESObjectREFR_GetRefPersists_005653d0(); // 0x005653d0
    template <class Point> bool Actor_SetPathfindingGoal(const Point&, void*, void*, float, int, int); // 0x008b3690
    int FUN_00905230(); // 0x00905230
    void Actor_SetPathfindingGoal(NiPoint3*, void*); // 0x008b3690: folded stack arguments
    float FUN_00885560(float, int); // 0x00885560
    bool PlayAttackGroup(int aiAttackGroup);   // 0x008935f0
    PathMover* Actor_GetAnimation();
    LookTarget* FUN_008d6f30();
    bool FUN_0094df60();
    NiPoint3* FUN_00430830();
    void TESObjectREFR_SetLocationOnReference(const NiPoint3& arPos);
    bool Actor_IsInCombat();
    bool PlayerCharacter_Is3rdPerson();
    float Actor_GetEyeLevel();
    NiPoint3* FUN_00436aa0();
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    BaseProcess* FUN_008d8520();
    NiNode* TESObjectREFR_Get3D();
    BaseForm* BGSSaveFormBuffer_GetForm();
    HandleRef FUN_00931ed0();
    void FUN_008a1800(int aiValue);
    bool GetTurretBehavior();
    void UpdateMovement_00886cb0(float afDelta, int aiUnused);
    void TESObjectREFR_GetSayToTopicInfo();
    void MobileObject_PutCreatedPackage(int a1, int a2, int a3);
    Package* FUN_009344a0();
    void TESObjectREFR_GetWorldLocation(Position*);
    int __thiscall TESObjectREFR_GetWorldLocation(void* output);
    int __thiscall TESObjectREFR_GetWorldLocation(FourFloatVector* output);
    int __thiscall TESObjectREFR_GetWorldLocation(void* output, Actor* reference, float radius);
    void* TESObjectREFR_GetSpace();
    void* BSFile_GetDevice();
    float TESObjectREFR_GetDistanceFromReference(Actor* a, int b, int c);
    int GetBootWeight(Target* pkTarget);
    void Actor_UnEquipObject(int iArg0, int iArg1, int iArg2, bool bArg3, bool bArg4, bool bArg5);
    void QueueUnEquipObject(int iArg0, int iArg1, int iArg2, bool bArg3, bool bArg4, bool bArg5);
    void PlayerCharacter_RemoveActorFromPlayercombatList(Actor*);
    void PlayerCharacter_ChangePerceivedActorHostileStatus(Actor*, int);
    void SetWalkRunFlagDirty();
    void Actor_ClearInCombat(bool);
    void TESObjectREFR_ResetInventory(bool);
    InventoryStackRecord* Actor_GetArmorBeingWorn(int);
    bool __thiscall Actor_CanAttackActor(Actor*);
    void TESObjectREFR_RemoveFromAllWater(int);
    void FUN_008c8bb0(int);

    bool DidPathingFail();
    bool IsWaitingOnPath();
    int GetAnimAction_008a7570();
    float GetFatigueRatio();
    float GetWalkSpeed();
    bool IsSwimming_005a2030();
    unsigned short Actor_GetAnimGroup(int, int, int, int);
    float Actor_GetAnimGroupDuration(int);
    void DispatchToTarget(int);
    const char* TESObjectREFR_GetFullName();
    static float GetActorScale();
    void* TESObjectREFR_GetWorldSpace(float);
    void PathToLocation(void*, void*, void*, void*, bool);
    bool SetPathingRequestAvoidNodes(void*);
    Vec4 TESObjectREFR_GetWorldLocation();
    // Explicit aggregate result types retain their own return and copy conventions.
    template <class Result>
    Result TESObjectREFR_GetWorldLocation();
    void FadeIn_008bcd20();
    void Actor_SetWantWeaponDrawn(bool);
    void MobileObject_UpdateTopicInfoSayOnce();                        // 0x00935ae0
    void DoDeathStuff();                        // 0x008b01c0
    bool Actor_IsPointDeepUnderWater(const NiPoint3*, TESObjectCELL*, float); // 0x00885520
    void TryMove(bool);                         // 0x00881860
    bool Actor_IsContinuingPackageforPC();                        // 0x008a69d0
    void Actor_StartGreetingPlayer(int);                     // 0x008bc3d0
    bool IsNodeKindSupported();                 // 0x008ba530
    bool FUN_008d8220();                        // 0x008d8220
    bool FUN_005ce8f0();                        // 0x005ce8f0
    bool Actor_IsTryingToEnterFurniture();                        // 0x008c13d0
    void Actor_SetPathfindingGoalAndAngle(Actor*, float, int);      // 0x008b37c0
    bool Actor_CanSpeak();                        // 0x00884480
    bool Actor_ShouldTalkTo(Actor*);                  // 0x00893190
    bool FUN_005a03f0(int);                     // 0x005a03f0
    void* Actor_GetClass();                       // 0x00884350
    void* Actor_GetActorBaseEnergyLevel();                       // 0x0087f990
    unsigned int FUN_008846e0();                // 0x008846e0
    bool Actor_IsAllowedToSwim();                        // 0x00884b50
    bool IsFlying();                            // 0x0087f350 (not FUN_: actor.cpp and actormover.cpp have a free __fastcall FUN_0087f350)
    bool IsFalling();                           // 0x0087f570 (named so it does not hide actor.cpp's free __fastcall FUN_0087f570)
    bool Actor_LineOfSight(int, Actor*, int, int, int); // 0x0088b880
    void Actor_GetCurrentPathfindingGoal(NiPoint3*);               // 0x008b3840
    bool Actor_CanSneak();                        // 0x008eea60
    void* GetObjectBeingEscorted();                       // 0x008a2d40
    TESForm* TESObjectREFR_GetOwner();                    // 0x00567790
    void Actor_AttackAlarm(Actor*, int, bool);       // 0x008c0460
    void SetDismemberedLimbsFlag(bool);         // 0x008a80c0
    void Actor_MurderAlarm(Actor*);                  // 0x008c09e0
    void Actor_SetPlayerTeammate(int);                     // 0x008bca90
    bool TESObjectREFR_HasObjectId(void*);                   // 0x00575450
    bool Actor_PutItemInReference(TESForm*, int, TESObjectREFR*, unsigned int, int); // 0x00892e90 (ret 0x14)
    void Actor_EvaluatePackage(int, int);                // 0x008a6ce0
    unsigned char FUN_005a3740();               // 0x005a3740
    void TESObjectREFR_GetDeltaForAngle(NiPoint3&, float);        // 0x00572500
    unsigned int FUN_008858c0(unsigned int, float, float); // 0x008858c0
    void Actor_AdjustSpeedForFollowing(float&, float, float);    // 0x008855f0
    void Actor_SetRunSpeed(float);                   // 0x00884ff0
    void Actor_SetWalkSpeed(float);                   // 0x00884fc0
    void Actor_EndMovement();                        // 0x0087faa0
    void ClearPath();                           // 0x008b3ad0 (not FUN_: free __fastcall FUN_008b3ad0 exists in tesobjectrefr.cpp)
    void BuildRequest(PathingRequest*, const NiPoint3&, void*, float, int); // 0x008b38d0
    bool CallPathMgr(FurnitureMark*, TESObjectCELL*, TESWorldSpace*, float, float, int); // 0x008b3750
    int FUN_00575610(TESForm*);
    void Actor_QueueEquipObject(TESForm*, int, ExtraDataList*, bool, bool, bool);
    void QueueUnEquipObject(TESForm*, ExtraDataList*, bool, bool, bool, bool);
    float __thiscall GetCombatRating(float);
    float __thiscall Actor_GetWeaponDamagePerSecond();
    bool Actor_CanUseWeapon(Weapon*, int);
    bool Actor_IsReloading();
    void Actor_QueueReload();
    float FUN_008be1b0();
    Weapon* Actor_GetCurrentWeapon();
    float GetHealthFraction();
    ActorBase* FUN_004181e0();
    RetObj* _FNV_GetObjectReference();
    bool TESObjectREFR_BaseIsQuestItem();
    ActorBase* Base();
    void ProcessImpale();
    void TESObjectREFR_SetLocationOnReference(V* v);
    void UpdateNodeTransform(int a, int b);
    float FUN_00931d70();
    Obj* FUN_009306d0();
    Obj* Projectile_GetShooter();
    float GetFirstLightParameter();
    float Projectile_GetDistanceMoved();
    int MiddleHighProcess_GetCurrentFurniture();
    void SetWhich(int a);
    void Projectile_SetFlag(int a, int b);
    float Projectile_GetSpeed(V* out, float f);
    V* Projectile_GetMovementDirection(V* out);
    void Projectile_Kill();
    void HandleMissileImpact();
    bool IsCombatTargetHostile(Actor*);
    void SpawnProjectile(Actor*, bool, void*, int);
    bool DoesFly_0087f390();
    bool GetGhost_008ace90();
    using MobileObject::GetCurrentAIProcess;
    Animation* GetAnimation() const;
    void Actor_UpdateActorMover(float);
    unsigned short GetAnimGroup(ANIM_GROUP_ENUM, InventoryStackRecord*, bool, Animation*);
    // 0x00572380 is TESObjectREFR::GetLightLevelAtPoint(const NiPoint3&).
    bool FUN_008b3bb0();
    bool IsPathing();
    bool Actor_SetPathfindingGoal(const NiPoint3&, void*, int);
    void PathToLocation(PathingRequest*, const NiPoint3&, void*, void*, float, int);
    bool SetPathingRequestAvoidNodes(PathingRequest&);
    void Actor_RequestRotate_008bb5c0(float, bool);
    void StopMoving_008b3ab0();
    Ref* TESObjectREFR_GetLinkedRef();
    void Actor_QueueEquipObject(Form*, int, int, int, int, int);
    bool Actor_IsProcessingTresPassAlarm();
    bool IsCurrentlyAlerted();
    bool Actor_IsSleeping();
    bool Actor_CalculateLOS(const NiPoint3&, int, int);
    bool IsWithinDistanceOfPoint(const NiPoint3&, float);
    int CalculateDetectionLevel(int, Actor*, bool*, bool, int, bool, bool*);
    bool HasFaction(TESForm*);
    bool CanBeDetected();
    void SetLightingNode(NiAVObject*);
    bool UpdateActorPackageState(int);
    bool TESForm_GetDisabledOrDeleted();
    int GetReactionToActor(Actor*, bool*);
    bool ProcessActorAppearance();
    void UpdatePlayerStatus(int);
    bool UpdateActorInventory();
    Script* GetAttachedScript();
    bool IsCombatEngaged();
    bool HasIdleInFormArray(TESIdleForm*);
    int GetAnimAction();
    bool IsInKillMove();
    TESPackage* GetCurrentAIPackage();
    void* SetTaskFlag(bool);
    void Actor_EndInterruptPackage(int);
    bool Actor_SetPathfindingFlee(PathingRequest*);
    bool GetBlocked();
    void Actor_SetBlock(int);
    void Actor_SetMoveMode(int);
    void HighProcess_ProcessObserveCombat(Actor*);
    TESPackage* GetPackage();
    void ClearLookAtTarget();
    TESObjectREFR* EffectSetting_GetLight();
    void EffectSetting_SetLight(TESObjectREFR*);
    void EffectSetting_SetLight(Actor*);
    void SetDialogueTopic(TESTopic*);
    void TESObjectREFR_SetSayToTopicInfo(void*);
    void TESObjectREFR_SetSayToTopic(ScriptAnimation::Idle*);
    void TESObjectREFR_SetSayToTopicInfo(unsigned int);
    void TESObjectREFR_SetSayToTopic(Idle*);
    Actor* FUN_005e3fa0();
    void InitPathingRequest(PathingRequest*, NiPoint3*, int);
    void InitializePathingRequestFromPosition(PathingRequest*, const NiPoint3&, TESObjectCELL*, TESWorldSpace*, float,
                                              PathingAvoidNodeArray*);
    void SetPathingRequestAvoidNodes(PathingRequest*);
    float GetCurrentMovementSpeed();
    void Actor_MoveActorAndFollowers_008ad910(TESObjectREFR*, bool, bool);
    bool DispatchWithObj(TESObjectREFR*, float, void*);
    void GetApplicablePackages(BSSimpleList<TESPackage*>*, float);
    bool HasCombatState();
    bool HasBoundObject();
    bool RefreshCurrentPackage();
    bool IsAtPosition(const NiPoint3&, TESObjectCELL*, TESWorldSpace*, float, void*);
    void RefreshPackageState();
    int TESObjectREFR_GetWorldSpace();
    void Actor_MoveActorAndFollowers(const NiPoint3&, float, int, int, int, int);
    bool FUN_008b0190(int);
    unsigned int ID();
    float GetRunSpeed();
    const NiPoint3& GetCachedMoveDelta();
    bool IsMoving_004938e0();
    float ProcessCoverLOSResult();
    bool QUpdateLighting();
    bool FUN_004997b0();
    bool GetEssential();
    void StealAlarm(TESObjectREFR*, int, int, int, TESForm*);
    bool IsFirstActorFlagSet();
    void SetIsSwimming(bool);
    bool ShouldShowSubtitles();
    static void SetActorDialogueState(unsigned int, bool);
    float Actor_GetRadiationResistanceMult();
    bool BSSoundHandle_BSSoundHandle_008c1bc0();
    bool Actor_IsInFaction(void*);
    float Actor_GetPerceptionCondition();
    bool Actor_IsFleeing(int);
    void Actor_RemoveFleeTarget(Actor*);
    bool FUN_00477ba0();
    bool TESObjectREFR_IsDead(int iUnused);
    Scene* FUN_009185e0();
    void MagicFogProjectile_InitHavok();
    float GetAlphaMult();
    void SetProcessValue(float);
    void FUN_008c4640();
    void GetLightIntensity(float);
    void __thiscall Actor_SetGhost(bool);
    void __thiscall Kill(Actor*, float);
    void FUN_00865e50(bool* pValue, int a, int b);
    void FUN_005a9db0(Actor* apActor);
    unsigned short GetLevel_0087f9f0();
    float AdjustEffectElapsedTime(float, Actor*);
    void UpdateActorEquipmentState(TESObjectREFR*, float);
    void UpdateActorMovementState(bool);
    void ProcessActorDamage(float, BooleanFloatQuery*);
    void Actor_CreateBloodOnWeapon(float, BooleanFloatQuery*, Actor*);
    void HandleDismembermentTask(int, int, Actor*);
    void ProcessQueuedHit(bool, bool);
    void ProcessHitData(BooleanFloatQuery*, char);
    void DismemberLimb(unsigned int, unsigned int, bool, bool, bool, bool);
    void Actor_SetHavokWeapon(bool);
    void RefreshActorInteraction(bool, bool);
    void ProcessQueuedActorUpdate();
    static void UpdateActorConditionValue(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
    static void UpdateMobilityConditionValue(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
    static void HandleActorValueUpdate(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
    static void HandleRadiationValueChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
    bool IsAlert();
    bool PlayerCharacter_GetTempPerson();
    void SetForceSneak(bool);
    void ForwardToVtSlot(unsigned int);
    void Actor_SetLookAtTarget(NiPoint3);
    void SetAimingWeapon(bool, bool, bool);
    void SetReloadState(bool);
    bool IsInIdleState();
    float ProcessActorAction();
    bool HasFaction(TESFaction* apFaction);
    unsigned int GetActorStateFlags() const;
    BooleanFloatQuery* RefreshActorRuntimeData();
    const char* Actor_GetPickUpSoundName(TESForm*, int, int);
    bool FUN_00573090(int);
    void TESObjectREFR_SetDismembered(int, void*, void*, int, bool);
    void Actor_DismemberLimb(int, int, bool, bool, bool, bool);
    void ApplyEffectToBodyParts(Effect*, int, int, void*, void*, int, int, bool);
    void FUN_0046a010(bool);
    void PlayerCharacter_CheckPoisonWeapon(int action);
    bool TESObjectREFR_CanHaveSound();
    bool TESObjectREFR_ShouldPlaySound();
    void TESObjectREFR_AttachSound(bool bValue);
    void TESObjectREFR_AddLight(int iArg);
    void TESObjectREFR_RemoveLight(int iArg);
    bool FUN_00440da0();
    bool FUN_00440d80();
    void Actor_Kill(Actor*, float);
    bool HasObjects(TESBoundObject*, int, int, unsigned int, int&);
    void Actor_SetForceUpdateQuest(int);
    void* Get3DSimple();
    const char* GetFullName();
    bool IsWeaponDrawn();
    void Actor_ReloadTargets(int a);
    void Actor_InitLightingPropertyPtr(void* p);
    void Actor_UpdateWeaponConditionEffects(int a);
    void* FUN_005715d0(int a, int b, int c);
    BipedAnim* GetBipedAnim(bool b);
    void TESObjectREFR_AttachWeapon(TESObjectWEAP* wpn);
    void TESObjectREFR_SetScale(float fScale);
    Box TESObjectREFR_GetOrientation();
    void TESObjectREFR_InitHavokForCollisionObject();
    int TESObjectREFR_GetCauseofDeath();
    BaseProcess* GetCurrentProcess() const;
    float GetHeight() const;
    unsigned int GetZero(void*);
    bool Actor_CheckShouldSaveHavokData(unsigned int);
    void SetAlert_008a5e40(bool);
    void MobileObject_StopCurrentDialogue();
    void PlayerCharacter_UpdatePlayer3d();
    void QueueUnEquipObject(TESForm*, int, int, int, bool, int);
    bool UnEquipObject(class TESBoundObject*, int, class ExtraDataList*, bool, bool, bool);
    void __thiscall RemoveEntry(Entry*);
    void SetEffectValue(int, float, int);
    bool FUN_008a3b30();
    void FUN_008c3c40(int a, int b);
    Refr* Actor_GetCurrentPackageLocation();
    Refr* Actor_GetCurrentPackageTarget();
    void* Actor_GetBestFoodItem();
    bool IsEating();
    bool Actor_PutActorInChairBedQuick(Refr* r, int a, int b, bool c);
    void TESObjectREFR_Update3DPosition();
    bool __thiscall Actor_HasObjects(TESBoundObject* object, int a, int b, int c, int& count);
    float CombatTimer_GetTargetTime();
    void Actor_CheckDeletedCaster(BCaster_S* caster);
    void Actor_InitPackageLocations(int);
    void TESObjectREFR_SetLocationOnReference(NiPoint3*);
    void TESObjectREFR_SetAngleOnReference(NiPoint3);
    void TESForm_SetDisabled(int);
    void FUN_00483710();
    void FUN_0046a010(int);
    void Actor_ClearInCombat(int);
    void ResetCachedGunSkill();
    void ResetCachedWeaponCondition();
    void ResetRadiationResistanceMult();
    void ConstructorInitialize(bool);
    void ClearMoveModeAll();
    bool TESForm_GetTemporary();
    using TESObjectREFR::GetParentCell;
    bool GetDeleted() const;
    using TESForm::GetDisabled;
    bool Actor_IsFollowing();
    Actor* GetOffsetC();
    Actor* NiAVObject_GetRotate_006a9540();
    Path* GetString();
    Context* GetNavMeshInfo_0068efb0();
    NiPoint3 FUN_005c3420();
    int FUN_007058c0();
    bool GetByteAtE0();
    NiPoint3* TESAmmo_GetAmmoEffectList();
    float GetFieldB8Float();
    float BSSceneGraph_GetCameraFOV();
    History* PathingRequestCoveredMove_GetUnreachableCoverLocations();
    History* GetOffsetF4();
    float GetFloatAtOffset68();
    float GetFloatAtOffsetB0();
    float GetFieldB4Float();
    float PathingRequestCoveredMove_GetAttackerHealth();
    void PathingRequestCoveredMove_SetCoverLocation(const NiPoint3&);
    void hkpEntity_addEntityListener(CListener* listener);

    bool IsValidTarget64();
    void* GetSlot116();
    bool IsSlot139(bool abArg);
    bool IsSlot216();
    AlchemyItem* GetSlot266();
    int GetHeadBone();
    NiAVObject* GetHead();
    TESObjectWEAP* GetEquippedWeapon();
    float GetAdjustedAngle();
    using MobileObject::GetActorHeight;
    float GetActorHeight();
    bool IsSwimming_005a2030() const;
    float Actor_GetSneakHeight(int p);
    float TESObjectREFR_GetScale_00567400();
    float GetGravity_00966980();
    bool GetHitScan() const;
    TESObjectWEAP* BGSProjectile_GetExplosion();
    TESObjectWEAP* GetCurrentCombatStyle();
    int GetFieldBC();
    float FUN_00931d70() const;
    bool vfn_0100();
    CombatPoint3* vfn_01d8(CombatPoint3* p);
    CombatPoint3* vfn_01dc(CombatPoint3* p);
    bool vfn_022c(int p);
    bool vfn_0230();
};
