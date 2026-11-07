// Source layout: Actor. PC corrections are in generate_headers.py.
#ifndef FNV_ACTOR_H
#define FNV_ACTOR_H

#include "processlists_layout_support.h"
#include "processlists_ActorValueOwner.h"
#include "processlists_CachedValuesOwner.h"
#include "processlists_MagicCaster.h"
#include "processlists_MagicTarget.h"
#include "processlists_MobileObject.h"
#include "processlists_ModifierList.h"
#include "processlists_NiPoint3.h"
class Actor : public MobileObject,
              public MagicCaster,
              public MagicTarget,
              public ActorValueOwner,
              public CachedValuesOwner
{
  public:
    TESObjectREFR* GetCombatOpponent();    // genuine pack PC00881650 and original names list
    void SetCombatOpponent(Actor* actor);  // genuine pack PC008BC790 and original names list

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
    float GetFatiguePercentage();
    bool IsPlayerTeammate();
    bool QUpdateLighting();
};
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
#endif
