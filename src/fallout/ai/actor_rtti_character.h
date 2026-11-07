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

#include "layout_support.h"
#include "actor_packet_rtti_character.h"
#include "ActorValueOwner.h"
#include "CachedValuesOwner.h"
#include "MagicCaster.h"
#include "MagicTarget.h"
#include "../../../include/TESObjectREFR.h"
#include "actor_rtti_character_mobileobject.h"
#include "ActorValueModifierList.h"
#include "../../../include/NiPoint3.h"
#pragma pack(push, 4)
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
    unsigned char layoutPaddingBD[3];
    Actor* m_pActorReference;  // +0xC0
    bool m_bActorFlag;         // +0xC4
    unsigned char layoutPaddingC5[3];
    float m_fFirstValueAfterFlag;     // +0xC8
    float m_fSecondScalar;            // +0xCC
    ActorValueModifierList m_kFirstActorData;   // +0xD0
    ActorValueModifierList m_kSecondActorData;  // +0xE0
    bool m_bFlagBeforeTwoBooleans;    // +0xF0
    bool m_bMiddleFlag;               // +0xF1
    bool m_bThirdActorFlag;           // +0xF2
    unsigned char layoutPaddingF3[1];
    BSSimpleList<CombatGroupCollection*> m_kFirstPointerList;         // +0xF4
    BSSimpleList<ActorListEntry*> m_kSecondPointerList;  // +0xFC
    bool m_bActorStateFlag;                                   // +0x104
    unsigned char layoutPadding105[3];
    ACTOR_LIFE_STATE m_eLifeState;          // +0x108
    ACTOR_CRITICAL_STAGE m_eCriticalStage;  // +0x10C
    ANIM_GROUP_ENUM m_eAnimationGroup;      // +0x110
    float ActorConditionAndAnimationState;  // +0x114
    bool m_bHasUpdated;                     // +0x118
    unsigned char layoutPadding119[3];
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
    unsigned char layoutPadding135[3];
    int m_iIntegerAfterActorListValid;                     // +0x138
    unsigned int m_uiFirstValueAfterInteger;  // +0x13C
    unsigned int m_uiActorFlags;              // +0x140
    bool ActorStatusData;                     // +0x144
    bool ActorBaseConfiguration;              // +0x145
    bool m_bFlagBeforeActorBase;              // +0x146
    unsigned char layoutPadding147[1];
    TESActorBase* m_pActorBase;              // +0x148
    bool ActorBaseReference;                 // +0x14C
    bool m_bSecondActorFlag;                 // +0x14D
    bool m_bThirdBooleanFlagAfterActorBase;  // +0x14E
    unsigned char layoutPadding14F[1];
    int m_iIntegerBeforeTwoFloatValues;                  // +0x150
    float BooleanIntegerTwoFloatData;  // +0x154
    float IntegerFloatFlagSettings;    // +0x158
    bool m_bFirstBehaviorFlag;         // +0x15C
    bool m_bSecondOfTwoFlags;          // +0x15D
    unsigned char layoutPadding15E[2];
    NiPoint3 m_kFormPosition;     // +0x160
    float FormPositionData;       // +0x16C
    TESForm* FormReferenceState;  // +0x170
    bool m_bFirstFlagAfterForm;   // +0x174
    bool m_bFormFlag;             // +0x175
    unsigned char layoutPadding176[2];
    float TwoBooleanFourFloatData;       // +0x178
    float BooleanAndFiveFloatSettings;   // +0x17C
    float FiveFloatBooleanData;          // +0x180
    float FloatFlagSettings;             // +0x184
    float m_fFourthFloat;                // +0x188
    bool FloatTripleBooleanFlagRecord;   // +0x18C
    bool m_bMiddleFlagBeforeActorMover;  // +0x18D
    bool m_bMovementFlag;                // +0x18E
    unsigned char layoutPadding18F[1];
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
    unsigned char layoutPadding1B2[2];
    virtual void Unk_C1(void);
    virtual void Unk_C2(void);
    virtual void Unk_C3(void);
    virtual void Unk_C4(void);
    virtual void Unk_C5(void);
    virtual void Unk_C6(void);
    virtual void Unk_C7(void);
    virtual void Unk_C8(void);
    virtual void Unk_C9(void);
    virtual void Unk_CA(void);
    virtual void Unk_CB(void);
    virtual void Unk_CC(void);
    virtual void Unk_CD(void);
    virtual void Unk_CE(void);
    virtual void Unk_CF(void);
    virtual void Unk_D0(void);
    virtual void Unk_D1(void);
    virtual void Unk_D2(void);
    virtual void Unk_D3(void);
    virtual void Unk_D4(void);
    virtual void Unk_D5(void);
    virtual void Unk_D6(void);
    virtual void Unk_D7(void);
    virtual void Unk_D8(void);
    virtual void Unk_D9(void);
    virtual void Unk_DA(void);
    virtual void Unk_DB(void);
    virtual void Unk_DC(void);
    virtual void Unk_DD(void);
    virtual void Unk_DE(void);
    virtual void Unk_DF(void);
    virtual void Unk_E0(void);
    virtual void Unk_E1(void);
    virtual void Unk_E2(void);
    virtual void Unk_E3(void);
    virtual void Unk_E4(void);
    virtual void Unk_E5(void);
    virtual void Unk_E6(void);
    virtual void Unk_E7(void);
    virtual void Unk_E8(void);
    virtual void Unk_E9(void);
    virtual void Unk_EA(void);
    virtual void Unk_EB(void);
    virtual void Unk_EC(void);
    virtual void Unk_ED(void);
    virtual void Unk_EE(void);
    virtual void Unk_EF(void);
    virtual void Unk_F0(void);
    virtual void Unk_F1(void);
    virtual void Unk_F2(void);
    virtual void Unk_F3(void);
    virtual void Unk_F4(void);
    virtual void Unk_F5(void);
    virtual void Unk_F6(void);
    virtual void Unk_F7(void);
    virtual void Unk_F8(void);
    virtual void Unk_F9(void);
    virtual void Unk_FA(void);
    virtual void Unk_FB(void);
    virtual void Unk_FC(void);
    virtual void Unk_FD(void);
    virtual void Unk_FE(void);
    virtual void Unk_FF(void);
    virtual void Unk_100(void);
    virtual void Unk_101(void);
    virtual void Unk_102(void);
    virtual void Unk_103(void);
    virtual void Unk_104(void);
    virtual void Unk_105(void);
    virtual void Unk_106(void);
    virtual void Unk_107(void);
    virtual void Unk_108(void);
    virtual void Unk_109(void);
    virtual bool IsInCombat(void);
    virtual Actor* GetCombatTarget(void);
    virtual void Unk_10C(void);
    virtual void Unk_10D(void);
    virtual void Unk_10E(void);
    virtual void Unk_10F(void);
    virtual void Unk_110(void);
    virtual void Unk_111(void);
    virtual void Unk_112(void);
    virtual void Unk_113(void);
    virtual void Unk_114(void);
    virtual void Unk_115(void);
    virtual void Unk_116(void);
    virtual void Unk_117(void);
    virtual void Unk_118(void);
    virtual void Unk_119(void);
    virtual void Unk_11A(void);
    virtual void Unk_11B(void);
    virtual void Unk_11C(void);
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
    virtual void Unk_12D(void);
    virtual void Unk_12E(void);
    virtual void Unk_12F(void);
    virtual void Unk_130(void);
    virtual void Unk_131(void);
    virtual void Unk_132(void);
    virtual void Unk_133(void);
    virtual void Unk_134(void);
    virtual void Unk_135(void);
    virtual void Unk_136(void);
    TESActorBase* GetActorBase();
    bool IsPlayerTeammate();
    MagicCaster* GetMagicCaster();
    int GetBaseLevel();
    unsigned int GetActorStateFlags();
    bool IsMoving();
    bool IsSneaking();
    void UpdateActorMovement(float delta);
    Animation* GetAnimation();
    BaseProcess* GetProcess();
    void SetAnimationGroupAction(int);
    void RefreshActorData();
    void SetAnimationForAction(int, Animation*);
    void UpdateAnimationMovement(Animation*, float);
    void PickAnimations(float, float);
    NiPoint3 GetMovementPosition();
    NiPoint3* GetMagicCaster(NiPoint3* output);
    void GetMagicCaster(NiPoint3& output);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Actor) == 0x1B4);
FNV_STATIC_ASSERT(offsetof(Actor, m_pRagdollController) == 0xAC);
FNV_STATIC_ASSERT(offsetof(Actor, m_pRagdollPenetrationUtil) == 0xB0);
FNV_STATIC_ASSERT(offsetof(Actor, m_eDialogueEmotion) == 0xB4);
FNV_STATIC_ASSERT(offsetof(Actor, ActorRagdollData) == 0xB8);
FNV_STATIC_ASSERT(offsetof(Actor, m_bFirstActorFlag) == 0xBC);
FNV_STATIC_ASSERT(offsetof(Actor, m_pActorReference) == 0xC0);
FNV_STATIC_ASSERT(offsetof(Actor, m_bActorFlag) == 0xC4);
FNV_STATIC_ASSERT(offsetof(Actor, m_fFirstValueAfterFlag) == 0xC8);
FNV_STATIC_ASSERT(offsetof(Actor, m_fSecondScalar) == 0xCC);
FNV_STATIC_ASSERT(offsetof(Actor, m_kFirstActorData) == 0xD0);
FNV_STATIC_ASSERT(offsetof(Actor, m_kSecondActorData) == 0xE0);
FNV_STATIC_ASSERT(offsetof(Actor, m_bFlagBeforeTwoBooleans) == 0xF0);
FNV_STATIC_ASSERT(offsetof(Actor, m_bMiddleFlag) == 0xF1);
FNV_STATIC_ASSERT(offsetof(Actor, m_bThirdActorFlag) == 0xF2);
FNV_STATIC_ASSERT(offsetof(Actor, m_kFirstPointerList) == 0xF4);
FNV_STATIC_ASSERT(offsetof(Actor, m_kSecondPointerList) == 0xFC);
FNV_STATIC_ASSERT(offsetof(Actor, m_bActorStateFlag) == 0x104);
FNV_STATIC_ASSERT(offsetof(Actor, m_eLifeState) == 0x108);
FNV_STATIC_ASSERT(offsetof(Actor, m_eCriticalStage) == 0x10C);
FNV_STATIC_ASSERT(offsetof(Actor, m_eAnimationGroup) == 0x110);
FNV_STATIC_ASSERT(offsetof(Actor, ActorConditionAndAnimationState) == 0x114);
FNV_STATIC_ASSERT(offsetof(Actor, m_bHasUpdated) == 0x118);
FNV_STATIC_ASSERT(offsetof(Actor, m_iActorStateValue) == 0x11C);
FNV_STATIC_ASSERT(offsetof(Actor, m_uiValueBeforeBooleanFields) == 0x120);
FNV_STATIC_ASSERT(offsetof(Actor, ActorStateFlags) == 0x124);
FNV_STATIC_ASSERT(offsetof(Actor, ActorReferenceData) == 0x125);
FNV_STATIC_ASSERT(offsetof(Actor, ActorReferenceListData) == 0x126);
FNV_STATIC_ASSERT(offsetof(Actor, m_bFlagBeforeCurrentActor) == 0x127);
FNV_STATIC_ASSERT(offsetof(Actor, m_pCurrentActor) == 0x128);
FNV_STATIC_ASSERT(offsetof(Actor, m_pFirstActorArray) == 0x12C);
FNV_STATIC_ASSERT(offsetof(Actor, m_pSecondActorArray) == 0x130);
FNV_STATIC_ASSERT(offsetof(Actor, m_bActorListValid) == 0x134);
FNV_STATIC_ASSERT(offsetof(Actor, m_iIntegerAfterActorListValid) == 0x138);
FNV_STATIC_ASSERT(offsetof(Actor, m_uiFirstValueAfterInteger) == 0x13C);
FNV_STATIC_ASSERT(offsetof(Actor, m_uiActorFlags) == 0x140);
FNV_STATIC_ASSERT(offsetof(Actor, ActorStatusData) == 0x144);
FNV_STATIC_ASSERT(offsetof(Actor, ActorBaseConfiguration) == 0x145);
FNV_STATIC_ASSERT(offsetof(Actor, m_bFlagBeforeActorBase) == 0x146);
FNV_STATIC_ASSERT(offsetof(Actor, m_pActorBase) == 0x148);
FNV_STATIC_ASSERT(offsetof(Actor, ActorBaseReference) == 0x14C);
FNV_STATIC_ASSERT(offsetof(Actor, m_bSecondActorFlag) == 0x14D);
FNV_STATIC_ASSERT(offsetof(Actor, m_bThirdBooleanFlagAfterActorBase) == 0x14E);
FNV_STATIC_ASSERT(offsetof(Actor, m_iIntegerBeforeTwoFloatValues) == 0x150);
FNV_STATIC_ASSERT(offsetof(Actor, BooleanIntegerTwoFloatData) == 0x154);
FNV_STATIC_ASSERT(offsetof(Actor, IntegerFloatFlagSettings) == 0x158);
FNV_STATIC_ASSERT(offsetof(Actor, m_bFirstBehaviorFlag) == 0x15C);
FNV_STATIC_ASSERT(offsetof(Actor, m_bSecondOfTwoFlags) == 0x15D);
FNV_STATIC_ASSERT(offsetof(Actor, m_kFormPosition) == 0x160);
FNV_STATIC_ASSERT(offsetof(Actor, FormPositionData) == 0x16C);
FNV_STATIC_ASSERT(offsetof(Actor, FormReferenceState) == 0x170);
FNV_STATIC_ASSERT(offsetof(Actor, m_bFirstFlagAfterForm) == 0x174);
FNV_STATIC_ASSERT(offsetof(Actor, m_bFormFlag) == 0x175);
FNV_STATIC_ASSERT(offsetof(Actor, TwoBooleanFourFloatData) == 0x178);
FNV_STATIC_ASSERT(offsetof(Actor, BooleanAndFiveFloatSettings) == 0x17C);
FNV_STATIC_ASSERT(offsetof(Actor, FiveFloatBooleanData) == 0x180);
FNV_STATIC_ASSERT(offsetof(Actor, FloatFlagSettings) == 0x184);
FNV_STATIC_ASSERT(offsetof(Actor, m_fFourthFloat) == 0x188);
FNV_STATIC_ASSERT(offsetof(Actor, FloatTripleBooleanFlagRecord) == 0x18C);
FNV_STATIC_ASSERT(offsetof(Actor, m_bMiddleFlagBeforeActorMover) == 0x18D);
FNV_STATIC_ASSERT(offsetof(Actor, m_bMovementFlag) == 0x18E);
FNV_STATIC_ASSERT(offsetof(Actor, m_pActorMover) == 0x190);
FNV_STATIC_ASSERT(offsetof(Actor, m_pData) == 0x194);
FNV_STATIC_ASSERT(offsetof(Actor, m_pPackage) == 0x198);
FNV_STATIC_ASSERT(offsetof(Actor, m_fPackageParameter) == 0x19C);
FNV_STATIC_ASSERT(offsetof(Actor, m_pContinuousBeamProjectile) == 0x1A0);
FNV_STATIC_ASSERT(offsetof(Actor, m_iPackageState) == 0x1A4);
FNV_STATIC_ASSERT(offsetof(Actor, ActorProjectileState) == 0x1A8);
FNV_STATIC_ASSERT(offsetof(Actor, m_eSitSleepState) == 0x1AC);
FNV_STATIC_ASSERT(offsetof(Actor, m_bFlagAfterSitSleepState) == 0x1B0);
FNV_STATIC_ASSERT(offsetof(Actor, ActorSleepState) == 0x1B1);
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
BSSimpleList<ActiveEffect*>* MiddleHighProcess::GetActiveEffectList()
{
    return pActiveEffects;
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
            NiAVObject* node = Get3DSimple();
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
