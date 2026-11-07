// fallout_shared/aiformulas.cpp: AIFormulas (22 functions)

#include "../../include/Actor.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/ExtraFollower.h"
#include "../../include/NiPoint3.h"
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/TESClass.h"
#include "../../include/TESForm.h"
#include "../../include/TESNPC.h"
#include "../../include/TESPackage.h"

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting326;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting314;
float __cdecl floorf(float);
float __cdecl ceilf(float);
class AIFormulas
{
  public:
    static float __cdecl CalculateSkillValue(float, float, float);
};
#include "../../include/ActorValue.h"
namespace ActorValue
{
    float __cdecl ClampValue(Index, float);
}

// Returns base plus the attribute and luck contributions, each scaled by a runtime float setting and passed through a helper.
// @fnv 0x00643c20
float __cdecl AIFormulas::CalculateSkillValue(float base, float attribute, float luck)
{
    float result = base;
    result += floorf(attribute * originalRuntimeFloatSetting326.Float()->f);
    result += ceilf(luck * originalRuntimeFloatSetting314.Float()->f);
    return result;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting293;

// Returns 1 if afHeightOrLength is not above the runtime float setting, otherwise the integer quotient of afHeightOrLength divided by that setting.
// @fnv 0x00642e80
// src: XBOX_PDB 0x00642e80
int __cdecl AiFormulas_GetActorDetectionSize(float afHeightOrLength)
{
    int iresult = 1;
    if (afHeightOrLength > originalRuntimeFloatSetting293.Float()->f)
    {
        iresult = static_cast<int>(afHeightOrLength / originalRuntimeFloatSetting293.Float()->f);
    }
    return iresult;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting277;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting272;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting268;
extern SettingT_GameSettingCollection_* DAT_0119b194[];
extern SettingT_GameSettingCollection_* DAT_0119b1ac[];
float __cdecl RandomFloat(float, float);
// Computes a base duration from settings scaled by energy level and proc index, then returns a random duration within a jittered min/max range.
// @fnv 0x006435c0
// src: COMMUNITY 0x006435c0
float AiFormulas_ComputeRandomSandboxSubProcessDuration(int aiEngergyLevel, int aiProcIndex)
{
    float fenergyMult;
    float fdurationMax;
    float fdurationMin;
    float fbaseDuration;
    float fenergy;
    float fduration;
    fenergy = (float)aiEngergyLevel;
    fbaseDuration = originalRuntimeFloatSetting268.Float()->f * DAT_0119b194[aiProcIndex]->Float()->f;
    fenergyMult = originalRuntimeFloatSetting272.Float()->f * DAT_0119b1ac[aiProcIndex]->Float()->f;
    fbaseDuration = (1 + fenergy * fenergyMult) * fbaseDuration;
    fdurationMin = (1 - originalRuntimeFloatSetting277.Float()->f) * fbaseDuration;
    fdurationMax = (1 + originalRuntimeFloatSetting277.Float()->f) * fbaseDuration;
    fduration = RandomFloat(fdurationMin, fdurationMax);
    return fduration;
}

extern int DAT_0119b144[];
extern SettingT_GameSettingCollection_* DAT_0119b17c[];

// Looks up the primary attribute and base value for a skill index from DAT_0119b144 and the setting table DAT_0119b17c, writing them to the output pointers.
// @fnv 0x00643bf0
void __cdecl GetSkillAttributeAndBase(int aiSkill, int* aiPrimaryAttribute, float* afBase)
{
    *aiPrimaryAttribute = DAT_0119b144[aiSkill];
    *afBase = DAT_0119b17c[aiSkill]->Float()->f;
}

void __cdecl FUN_00ec6f20(int a, int b, int c, int d);
struct FUN_006c8980_stand
{
    int pad;
    int a;
    int b;
    void BSSimpleArray_Sort_0(int fn);
};
// Calls FUN_00ec6f20 with the object's a and b fields, 0x10 and fn.
// @fnv 0x006c8980
// src: COMMUNITY 0x006c8980
void FUN_006c8980_stand::BSSimpleArray_Sort_0(int fn)
{
    FUN_00ec6f20(a, b, 0x10, fn);
}

void __cdecl AiFormulas_CalculateDerivedFatigue(int*, float);

// @fnv 0x00643820
// src: COMMUNITY 0x00643820
void __cdecl AiFormulas_AVDeriveFatigue(int* pObj)
{
    float result = reinterpret_cast<ActorValueOwner*>(pObj)->GetPermanentActorValueAdjustment((ActorValue::Index)7);
    result = ActorValue::ClampValue((ActorValue::Index)7, result);
    AiFormulas_CalculateDerivedFatigue(pObj, result);
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting310;

// @fnv 0x00643a50
// src: COMMUNITY 0x00643a50
float AiFormulas_AVDeriveBodyPartCondition()
{
    return originalRuntimeFloatSetting310.Float()->f;
}

float __cdecl GetSkillValue(ActorValueOwner*, int, bool);

// Calls GetSkillValue with arg2, arg3 and false, returning the resulting float.
// @fnv 0x00643bd0
// src: COMMUNITY 0x00643bd0
float __cdecl callback4C(void* arg2, int arg3)
{
    float result = GetSkillValue(static_cast<ActorValueOwner*>(arg2), arg3, 0);
    return result;
}

extern SettingT_GameSettingCollection_ g_011cd48c;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting154;
extern SettingT_GameSettingCollection_ g_011cd8e4;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting157;
extern SettingT_GameSettingCollection_ g_011cda88;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting153;
extern SettingT_GameSettingCollection_ g_011cdef8;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting156;

// Computes a weighted sum of three inputs using float settings, truncates it to int, and clamps it between two setting bounds.
// @fnv 0x00643400
int __cdecl ComputeClampedSettingSum(int aiFirst, int aiSecond, float afThird)
{
    int iresult = 0;
    float fTerm1 = g_011cdef8.Float()->f + g_011cd8e4.Float()->f * aiFirst;
    float fTerm2 = g_011cd48c.Float()->f + originalRuntimeFloatSetting153.Float()->f * aiSecond;
    float fTerm3 = g_011cda88.Float()->f + originalRuntimeFloatSetting154.Float()->f * afThird;
    iresult = (int)(fTerm1 + fTerm2 + fTerm3);
    if (iresult < originalRuntimeFloatSetting156.Float()->f)
        iresult = (int)originalRuntimeFloatSetting156.Float()->f;
    else if (iresult > originalRuntimeFloatSetting157.Float()->f)
        iresult = (int)originalRuntimeFloatSetting157.Float()->f;
    return iresult;
}

namespace fnv_00643a70 {
extern SettingT_GameSettingCollection_ g_011cd4d8;
extern SettingT_GameSettingCollection_ g_011cd360;
extern SettingT_GameSettingCollection_ g_011cda10;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting311;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting312;

// Reads actor value index 7 and returns the float from one of five settings based on the value (6-10), otherwise 0.
// @fnv 0x00643a70
// src: COMMUNITY 0x00643a70
float __cdecl AiFormulas_AVDeriveHealingRate(ActorValueOwner* apActor)
{
    float fresult = 0.0f;
    switch (apActor->GetActorValueAsInteger(7))
    {
    case 6:
        fresult = g_011cd4d8.Float()->f;
        break;
    case 7:
        fresult = g_011cd360.Float()->f;
        break;
    case 8:
        fresult = g_011cda10.Float()->f;
        break;
    case 9:
        fresult = originalRuntimeFloatSetting311.Float()->f;
        break;
    case 10:
        fresult = originalRuntimeFloatSetting312.Float()->f;
        break;
    }
    return fresult;
}
}  // namespace fnv_00643a70

extern SettingT_GameSettingCollection_ g_011cd550;
extern SettingT_GameSettingCollection_ g_011cd7f0;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting155;
// Computes a value from two float settings scaled by a, subtracts it from another setting, and halves the result.
// @fnv 0x006434f0
// src: COMMUNITY 0x006434f0
float AiFormulas_ComputeTimeTillNextWander(int aiValue)
{
    float fResult = g_011cd550.Float()->f + g_011cd7f0.Float()->f * aiValue;
    fResult = (originalRuntimeFloatSetting155.Float()->f - fResult) / 2.0;
    return fResult;
}

namespace fnv_00643670 {
void __cdecl ComputeActorLevel(ActorValueOwner*, float);
// @fnv 0x00643670
// src: COMMUNITY 0x00643670
void __cdecl AiFormulas_AVDeriveHealth(ActorValueOwner* p)
{
    float f = p->GetPermanentActorValueAdjustment((ActorValue::Index)7);
    f = ActorValue::ClampValue((ActorValue::Index)7, f);
    ComputeActorLevel(p, f);
}
}  // namespace fnv_00643670

namespace fnv_006439d0 {
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting306;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting307;
// @fnv 0x006439d0
// src: COMMUNITY 0x006439d0
float AiFormulas_AVDeriveActionPoints(ActorValueOwner* apActorValueOwner)
{
    return (float)((double)apActorValueOwner->GetActorValueFloatByIndex((ActorValue::Index)10) *
                       originalRuntimeFloatSetting306.Float()->f +
                   originalRuntimeFloatSetting307.Float()->f);
}
}  // namespace fnv_006439d0

namespace fnv_00643a10 {
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting308;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting309;
// @fnv 0x00643a10
// src: COMMUNITY 0x00643a10
float AiFormulas_AVDeriveCarryWeight(ActorValueOwner* pActorValueOwner)
{
    return (double)pActorValueOwner->GetActorValueFloatByIndex((ActorValue::Index)5) *
               originalRuntimeFloatSetting308.Float()->f +
           originalRuntimeFloatSetting309.Float()->f;
}
}  // namespace fnv_00643a10

namespace fnv_00643b50 {
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting313;
extern SettingT_GameSettingCollection_ g_011cd12c;
extern double _DAT_01012060;

// @fnv 0x00643b50
// src: COMMUNITY 0x00643b50
float AiFormulas_AVDeriveFromPrimary(ActorValueOwner* owner, int value)
{
    float fResult = 0.0f;

    switch (value)
    {
    case 17: {
        float fClampedValue = floorf(static_cast<float>(
            ((static_cast<double>(owner->GetActorValueFloatByIndex(5)) + originalRuntimeFloatSetting313.Float()->f) *
             g_011cd12c.Float()->f)));

        if (fClampedValue > _DAT_01012060)
            fResult += fClampedValue;
        break;
    }
    }

    return fResult;
}
}  // namespace fnv_00643b50

namespace fnv_00643540 {
struct SettingSlot16
{
    SettingT_GameSettingCollection_* m_00;
    SettingT_GameSettingCollection_* m_04;
    SettingT_GameSettingCollection_* m_08;
    SettingT_GameSettingCollection_* m_0c;
};

extern SettingSlot16 DAT_011cd680[];

float __cdecl AiFormulas_RandomHour(float a, float b);
float __cdecl FUN_00476b70(float a, float b);

// Reads four floats from the setting slot at aiIndex, combines the first two into afOutA and the last two into afOutB.
// @fnv 0x00643540
void __cdecl GetSettingPairValues(int aiIndex, float* afOutA, float* afOutB)
{
    SettingSlot16* slot = &DAT_011cd680[aiIndex];
    *afOutA = AiFormulas_RandomHour(slot->m_00->Float()->f, slot->m_04->Float()->f);
    *afOutB = FUN_00476b70(slot->m_08->Float()->f, slot->m_0c->Float()->f);
}
}  // namespace fnv_00643540

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting295;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting294;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting298;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting297;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting296;
// The shared Actor header does not declare the no-argument method at 0x0087f4e0.
// Its sole this pointer uses ECX under both thiscall and one-argument fastcall.
bool __fastcall ActorIsStub(Actor* actor);

// 0x00603fc0 and 0x006040d0 are NPC stat queries in tesnpc.cpp, absent from shared TESNPC.
class NPCFormulaQueries : public TESNPC
{
public:
    unsigned int ComputeAttributeValue(int);
    unsigned int ComputeDerivedValue(int);
};
// Computes a level value from afLevel and runtime float settings, branching on v218/v360 and adjusting for stub actors or positive GetLevel.
// @fnv 0x006436c0
float __cdecl ComputeActorLevel(ActorValueOwner* apObj, float afLevel)
{
    float fResult = 0.0f;
    Actor* pActor2 = static_cast<Actor*>(apObj);
    bool b4 = pActor2->IsCharacter();
    bool b3 = pActor2->IsPlayerRef();
    if (b3)
    {
        fResult = (afLevel + originalRuntimeFloatSetting295.Float()->f) * originalRuntimeFloatSetting294.Float()->f;
    }
    else if (b4)
    {
        fResult = (afLevel + originalRuntimeFloatSetting298.Float()->f) * originalRuntimeFloatSetting297.Float()->f;
    }
    if (ActorIsStub(pActor2) && b4 && !b3)
    {
        NPCFormulaQueries* pBase2 = static_cast<NPCFormulaQueries*>(pActor2->GetActorBase());
        fResult = (float)pBase2->ComputeAttributeValue(0);
    }
    else if (b3 && pActor2->GetActorValueOwnerType() > 0)
    {
        fResult += (pActor2->GetActorValueOwnerType() - 1) * originalRuntimeFloatSetting296.Float()->f;
    }
    return fResult;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting86;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting151;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting152;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting99;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting100;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting98;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting97;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting150;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting101;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting87;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting102;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting90;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting88;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting91;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting93;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting95;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting96;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting92;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting89;
extern SettingT_GameSettingCollection_ g_011cdc80;
extern SettingT_GameSettingCollection_ g_011cd080;
extern SettingT_GameSettingCollection_ g_011cdb84;
extern SettingT_GameSettingCollection_ g_011cdeec;
extern SettingT_GameSettingCollection_ g_011cd310;
extern SettingT_GameSettingCollection_ g_011cd8c0, g_011cd13c, g_011cd4c0;
int BSMAX_00647b70(int, int);
float BSMAX_00404010(float, float);
double FUN_00ec9ac0(double, double);
// @fnv 0x00642ed0
int __cdecl ComputeDamageResult(int aiLevel, int aiBaseDamage, int a10, int aiDamage, float afCurrentHealth, int a1c,
                                int aiPercent, bool a24, int a28, bool abApplyAttackBonus, bool abApplyDeduction,
                                bool abApplyMultiplier, bool abFlag38, bool abFlag3c, int aiCount, int aiRepeats,
                                bool abMaxHealth, bool abFlag4c, int aiBonusType, float* apFirstDamage,
                                float* apSecondaryDamage, float* apThirdDamage, int a60, int a64, int aiPenalty)
{
    float fScaleTmp;
    float adjusted;
    float multiplier9;
    int flag3;
    float factors4;
    int count101;
    int base14;
    int flag6;
    int flag4c_2;
    float fTotal4;
    float bonusA;
    int extra6;
    float attackVal;
    int result7;
    int damage;
    int flag2cB;
    float ratio2;
    float secondary8;
    float first3;
    float repeats4;
    float weighted9;
    int flagA;
    float third_2;
    int flagVal5;
    float maximum3;
    float percentTmp;
    float deduction2;
    int flagVal9;
    float level5;

    result7 = 0;
    fTotal4 = originalRuntimeFloatSetting86.Float()->f;
    base14 = aiBaseDamage;
    extra6 = *g_011cd8c0.Setting_Int();
    base14 += *g_011cd13c.Setting_Int() * (a64 - a60);
    extra6 -= a64 * *g_011cd4c0.Setting_Int();
    base14 += BSMAX_00647b70(extra6, 0);
    base14 -= aiPenalty;
    flag6 = 0;
    flagVal5 = 0;
    flag4c_2 = 0;
    if (abFlag3c)
        flag6 = 1;
    if (abFlag38)
        flagVal5 = 1;
    if (abFlag4c)
        flag4c_2 = 1;
    bonusA = 0.0f;
    if (aiBonusType == 1)
        bonusA = originalRuntimeFloatSetting151.Float()->f;
    else if (aiBonusType == 2.0)
        bonusA = originalRuntimeFloatSetting152.Float()->f;
    fScaleTmp =
        originalRuntimeFloatSetting99.Float()->f +
        (originalRuntimeFloatSetting100.Float()->f - originalRuntimeFloatSetting99.Float()->f) * (aiLevel / 10.0f);
    fScaleTmp *= 1.0 + flag6 * originalRuntimeFloatSetting98.Float()->f +
                 flagVal5 * originalRuntimeFloatSetting97.Float()->f +
                 flag4c_2 * originalRuntimeFloatSetting150.Float()->f + bonusA;
    damage = aiDamage;
    if (a24)
        damage = 0;
    flagA = 0;
    if (a10 > 0)
        flagA = 1;
    flagVal9 = 0;
    if (abApplyDeduction)
        flagVal9 = 1;
    flag3 = 0;
    if (abApplyMultiplier)
        flag3 = 1;
    flag2cB = 0;
    if (abApplyAttackBonus)
        flag2cB = 1;
    maximum3 = abMaxHealth ? originalRuntimeFloatSetting101.Float()->f * originalRuntimeFloatSetting87.Float()->f
                           : originalRuntimeFloatSetting87.Float()->f;
    ratio2 = BSMAX_00404010((maximum3 - afCurrentHealth) / maximum3, 0.0f);
    ratio2 = FUN_00ec9ac0(ratio2, originalRuntimeFloatSetting102.Float()->f);
    adjusted = ratio2;
    if (!flagA && aiBonusType != 1)
        adjusted = ratio2 * originalRuntimeFloatSetting90.Float()->f;
    attackVal = flag2cB * (originalRuntimeFloatSetting88.Float()->f + g_011cdc80.Float()->f * a28);
    multiplier9 = 1.0f;
    if (flag3)
        multiplier9 = originalRuntimeFloatSetting91.Float()->f;
    attackVal *= multiplier9;
    count101 = (int)g_011cd080.Float()->f * aiCount;
    first3 = BSMAX_00404010(adjusted * originalRuntimeFloatSetting93.Float()->f * (count101 + attackVal), 0.0f);
    *apFirstDamage = first3;
    factors4 =
        1.0 + flag2cB * originalRuntimeFloatSetting95.Float()->f + flag3 * originalRuntimeFloatSetting96.Float()->f;
    level5 = (g_011cdb84.Float()->f + a1c) * originalRuntimeFloatSetting92.Float()->f;
    percentTmp = (100 - aiPercent) / 100;
    repeats4 = aiRepeats <= 1 ? 1.0 : 1.0 + (aiRepeats - 1.0) * g_011cdeec.Float()->f;
    secondary8 = BSMAX_00404010(damage * ratio2 * factors4 * level5 * percentTmp * repeats4, 0.0f);
    if (a24)
        secondary8 *= g_011cd310.Float()->f;
    *apSecondaryDamage = secondary8;
    deduction2 = base14 * flagVal9;
    weighted9 = fScaleTmp * ratio2;
    third_2 = originalRuntimeFloatSetting89.Float()->f * (weighted9 - deduction2);
    *apThirdDamage = third_2;
    fTotal4 = fTotal4 + first3 + secondary8 + third_2;
    if (fTotal4 < 1.0 && fTotal4 > 0.0)
        result7 = 1;
    else
        result7 = (int)fTotal4;
    return result7;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting327;
bool __cdecl ActorValue_IsSkill(int);
void __cdecl GetSkillAttributeAndBase(int aiSkill, int* aiPrimaryAttribute, float* afBase);
float __cdecl CalcSkillBase(float, float, float);
// @fnv 0x00643c90
float __cdecl GetSkillValue(ActorValueOwner* apActor, int aiSkill, bool abCurrent)
{
    float fResult = 0.0f;
    if (ActorValue_IsSkill(aiSkill))
    {
        int iAttribute = -1;
        GetSkillAttributeAndBase(aiSkill, &iAttribute, &fResult);
        bool bUnused = false;
        if (iAttribute != -1)
        {
            if (!abCurrent)
            {
                fResult = CalcSkillBase(fResult, apActor->GetActorValueFloatByIndex(iAttribute),
                                        apActor->GetActorValueFloatByIndex(11));
            }
            else
            {
                fResult = CalcSkillBase(
                    fResult,
                    ActorValue::ClampValue((ActorValue::Index)iAttribute,
                                           apActor->GetBaseActorValueFloat((ActorValue::Index)iAttribute) +
                                               apActor->GetDamageActorValue((ActorValue::Index)iAttribute)),
                    ActorValue::ClampValue((ActorValue::Index)11,
                                           apActor->GetBaseActorValueFloat((ActorValue::Index)11) +
                                               apActor->GetDamageActorValue((ActorValue::Index)11)));
            }
        }
        TESForm* pBase = apActor->GetActorValueOwnerForm();
        if (pBase && pBase->GetIsReference())
        {
            TESForm* pForm = pBase;
            if (pForm->IsActor())
            {
                TESNPC* pNPC = (TESNPC*)pForm;
                if (pNPC->GetClass() && pNPC->GetClass()->IsTagSkill((ActorValue::Index)aiSkill))
                {
                    fResult += originalRuntimeFloatSetting327.Float()->f;
                }
            }
        }
    }
    return fResult;
}

namespace fnv_00643ff0 {
struct ExtraData
{
    ExtraFollower* ExtraDataList_GetFollowerExtra();
};
struct FollowerEntry
{
    Actor* actor;
    float distance;
    float spacing;
    float radius;
};
int __cdecl CompareObjects(const void*, const void*);
struct FollowerArray
{
    void* operations;
    FollowerEntry* entries;
    unsigned int count;
    unsigned int capacity;
    FollowerArray(unsigned int);
    ~FollowerArray();
    FollowerEntry& GetElementAddress16(unsigned int);
    void BSSimpleArray_Sort_0(int(__cdecl*)(const void*, const void*));
    unsigned int FUN_0044ddc0();
};
extern SettingT_GameSettingCollection_ g_011cde98;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting291;
float __cdecl BSMAX_00404010(float, float);

// Builds a sorted list of the leader's followers whose current package is type 1 and returns the accumulated spacing offset up to the given actor.
// @fnv 0x00643ff0
float __cdecl GetFollowerOffset(Actor* actor, Actor* leader)
{
    float offset = 0.0f;
    ExtraFollower* pExtraFollower = leader ? reinterpret_cast<ExtraData*>(leader->BSFile_GetDevice())->ExtraDataList_GetFollowerExtra() : 0;
    if (pExtraFollower)
    {
        unsigned int count = 0;
        if (!pExtraFollower->list->IsEmpty())
        {
            BSSimpleList<Actor*>* node = pExtraFollower->list;
            while (node)
            {
                Actor* follower = node->GetItem();
                TESPackage* package = follower->MobileObject::GetCurrentPackage();
                if (package && package->GetPackType() == 1)
                    ++count;
                node = node->GetNext();
            }
        }
        if (count > 0)
        {
            FollowerArray followerList(count);
            unsigned int index = 0;
            BSSimpleList<Actor*>* followers = pExtraFollower->list;
            while (followers)
            {
                Actor* follower = followers->GetItem();
                TESPackage* package = follower->MobileObject::GetCurrentPackage();
                if (package && package->GetPackType() == 1)
                {
                    FollowerEntry& entry = followerList.GetElementAddress16(index);
                    entry.actor = follower;
                    entry.distance = (*static_cast<const Actor*>(leader)->GetPos() -
                                      *static_cast<const Actor*>(follower)->GetPos()).FUN_004a7290();
                    entry.spacing = (float)*g_011cde98.Setting_Int();
                    entry.radius = follower->FUN_008be1b0();
                    entry.spacing = package->GetPackageResult(actor, false);
                    ++index;
                }
                followers = followers->GetNext();
            }
            followerList.BSSimpleArray_Sort_0(CompareObjects);
            float distance = 0.0f;
            for (index = 0; index < followerList.FUN_0044ddc0(); ++index)
            {
                FollowerEntry& entry = followerList.GetElementAddress16(index);
                if (index > 0)
                    distance += followerList.GetElementAddress16(index - 1).radius + entry.radius +
                                originalRuntimeFloatSetting291.Float()->f;
                distance = BSMAX_00404010(distance, entry.spacing);
                if (followerList.GetElementAddress16(index).actor == actor)
                {
                    offset = distance - followerList.GetElementAddress16(index).spacing;
                    break;
                }
            }
        }
    }
    return offset;
}
}  // namespace fnv_00643ff0

extern "C" SettingT_GameSettingCollection_ g_011cdee0;
extern "C" SettingT_GameSettingCollection_ g_011cdb48;
// Returns the sum of a base setting value and the owner's actor value 11 multiplied by another setting value.
// @fnv 0x00643b10
// src: COMMUNITY 0x00643b10
float __cdecl AiFormulas_AVDeriveCriticalChance(ActorValueOwner* apActorValueOwner)
{
    float result = g_011cdee0.Float()->f + apActorValueOwner->GetActorValueFloatByIndex(11) * g_011cdb48.Float()->f;
    return result;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting300;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting301;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting302;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting303;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting304;

// Computes a float result from afValue and runtime settings based on actor traits, level, and a shell check.
// @fnv 0x00643870
// src: COMMUNITY 0x00643870
float __cdecl AiFormulas_CalculateDerivedFatigue(ActorValueOwner* apObj, float afValue)
{
    float fResult = 0.0f;
    Actor* pActor2 = static_cast<Actor*>(apObj);
    bool bHasTrait4 = pActor2->IsCharacter();
    bool bHasSpecial3 = pActor2->IsPlayerRef();

    if (bHasSpecial3)
    {
        fResult = originalRuntimeFloatSetting300.Float()->f + afValue * originalRuntimeFloatSetting301.Float()->f;
    }
    else if (bHasTrait4)
    {
        fResult = originalRuntimeFloatSetting303.Float()->f + afValue * originalRuntimeFloatSetting304.Float()->f;
    }

    if (ActorIsStub(pActor2) && bHasTrait4 && !bHasSpecial3)
    {
        NPCFormulaQueries* base2 = static_cast<NPCFormulaQueries*>(pActor2->GetActorBase());
        fResult = (float)base2->ComputeDerivedValue(1);
    }
    else if (bHasSpecial3)
    {
        if (pActor2->GetActorValueOwnerType() > 0)
        {
            fResult = (double)(pActor2->GetActorValueOwnerType() - 1) * originalRuntimeFloatSetting302.Float()->f + fResult;
        }
    }

    return fResult;
}
