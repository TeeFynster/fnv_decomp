
// fallout_shared/gameplayformulas.cpp
// ActorValueUtility_gameplayformulas::ConvertActorValue (0x00648b50).

#include "../../include/ActorValueOwner.h"
// ActorValueUtility_gameplayformulas: local type (was include/ActorValueUtility.h, which had no evidence of one real class); its methods are 0x00648b50 GamePlayFormulas::GetRequiredExperiencePoints
class ActorValueUtility_gameplayformulas
{
public:
    static int __cdecl ConvertActorValue(int);
};
#include "../../include/GameSettingCollection.h"
#include "../../include/InventoryStackRecord.h"
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESObjectWEAP.h"

extern SettingT_GameSettingCollection_ iXPBase;
extern SettingT_GameSettingCollection_ iXPBumpBase;

// Returns 0 for levels <= 1, otherwise sums iXPBase plus repeated iXPBump increments across levels up to aiLevel - 1.
// @fnv 0x00648b50
int ActorValueUtility_gameplayformulas::ConvertActorValue(int aiLevel)
{
    if (aiLevel <= 1)
        return 0;
    int iTotal = *reinterpret_cast<int*>(iXPBase.Int());
    int iBase = iTotal;
    int iBump = *reinterpret_cast<int*>(iXPBumpBase.Int());
    for (int i = 1; i < aiLevel - 1; ++i)
    {
        iBase += iBump;
        iTotal += iBase;
    }
    return iTotal;
}

// @fnv 0x005be4d0
// src: XBOX_PDB 0x005be4d0
int __fastcall PlayerCharacter_GetDifficultyLevel(char* pThis)
{
    return *(int*)(pThis + 0x7b8);
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting868;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting869;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting870;

double __cdecl fabsf_00408860(float);
float __cdecl pow_004dd130(float, float);

// @fnv 0x00647c00
float __cdecl ComputeItemValue(float afItemValue, float afItemHealthPercent)
{
    float fvalue = afItemValue;
    float fcondition = afItemHealthPercent / 10.0;
    if (fcondition < 0.0)
    {
        fcondition = 10.0f;
    }
    if (fvalue > 0.0)
    {
        fvalue = (1.0 - originalRuntimeFloatSetting870.Float()->f) * fvalue *
                     originalRuntimeFloatSetting868.Float()->f *
                     pow_004dd130(fcondition,
                                  originalRuntimeFloatSetting869.Float()->f) +
                 fvalue * originalRuntimeFloatSetting870.Float()->f;
    }
    return fabsf_00408860(fvalue) >= 1.0 ? InventoryStackRecord::RoundToNearestStep(fvalue, 1.0f) : fvalue;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting830;
float __cdecl GamePlayFormulas_GetActorWalkSpeed(void*, void*, void*, bool, bool, bool, bool);

// @fnv 0x00647f00
// src: XBOX_PDB 0x00647f00
float __cdecl GamePlayFormulas_GetActorRunSpeed(void* apActor, void* apWeapon, void* pArmor, bool abNoWeapon, bool abIsNpc,
                           bool abIsSneaking, bool abOverEncumbered)
{
    float runSpeed = 0.0f;
    runSpeed += GamePlayFormulas_GetActorWalkSpeed(apActor, apWeapon, pArmor, abIsSneaking, abNoWeapon, abIsNpc, abOverEncumbered);
    runSpeed *= originalRuntimeFloatSetting830.Float()->f;
    return runSpeed;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting861;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting862;

// Returns the sum of the base float setting and aiEndurance multiplied by the per-point float setting.
// @fnv 0x00648a10
// src: COMMUNITY 0x00648a10
float __cdecl GamePlayFormulas_SwimBreathTime(int aiEndurance)
{
    return originalRuntimeFloatSetting861.Float()->f +
           (float)aiEndurance *
               originalRuntimeFloatSetting862.Float()->f;
}

extern double DAT_01011588;
double __cdecl _floor(float);

// Computes a floored value from aiIntelligence and DAT_01011588 plus 10, adding 1 when aiLevel is even and aiIntelligence is odd.
// @fnv 0x00648c10
int __cdecl ComputeIntelligenceResult(int aiIntelligence, int aiLevel)
{
    float fresult = (double)aiIntelligence * DAT_01011588 + 10.0;
    int iresult = _floor(fresult);
    if (aiLevel % 2 == 0 && aiIntelligence % 2 == 1)
    {
        iresult += 1;
    }
    return iresult;
}

float __cdecl GamePlayFormulas_GetActorWalkSpeed(void*, void*, void*, bool, bool, bool, bool);

// @fnv 0x00647f50
// src: XBOX_PDB 0x00647f50
float __cdecl GamePlayFormulas_GetActorSwimWalkSpeed(void* apActor, void* apWeapon, void* pArmor, bool abIsNpc, bool abIsSneaking,
                           bool abOverEncumbered)
{
    float runSpeed = GamePlayFormulas_GetActorWalkSpeed(apActor, apWeapon, pArmor, false, abIsNpc, abIsSneaking, abOverEncumbered);
    return runSpeed;
}

extern double g_d100;
extern double DAT_0104ee98;

// @fnv 0x00648d70
void __cdecl ComputeInjuryEffectScalars(float* afResistanceTime, float* afMagnitude, float* afMouseScalar,
                                        float afInjuryPercent, float afPainPercent, int aiMedicineSkill)
{
    *afResistanceTime =
        (float)(aiMedicineSkill / g_d100 * DAT_0104ee98 + (1.0 - afInjuryPercent) * 0.20000000298023224 +
                (1.0 - afPainPercent) * 0.10000000149011612);
    *afMagnitude = (float)((g_d100 - aiMedicineSkill) / g_d100 * DAT_0104ee98 + afInjuryPercent * 0.20000000298023224 +
                           afPainPercent * 0.10000000149011612);
    *afMouseScalar = (float)(aiMedicineSkill / g_d100 * DAT_0104ee98 + (1.0 - afInjuryPercent) * 0.20000000298023224 +
                             (1.0 - afPainPercent) * 0.10000000149011612);
}

extern double DAT_01012638;

// @fnv 0x00648e10
float ScaleByConstant(float afValue)
{
    return static_cast<float>(afValue * DAT_01012638);
}

extern double DAT_01011588;

// @fnv 0x00648e30
float ScaleLimbWoundPercent(float afLimbWoundPercent)
{
    return static_cast<float>(afLimbWoundPercent * DAT_01011588);
}

#include "../../include/ActorValue.h"

struct CombatDamageCalculator
{
    static float __cdecl GetActorValueMultiplier(ActorValueOwner*, ActorValue::Index, bool);
};
extern double _gModifierZero;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting832;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting826;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1088;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting833;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting828;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting829;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting831;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting827;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1087;

// @fnv 0x00647d10
// src: XBOX_PDB 0x00647d10
float GamePlayFormulas_GetActorWalkSpeed(ActorValueOwner* pActor, TESObjectWEAP* pWeapon, TESObjectARMO* pArmor, bool bSneaking,
                   bool bIsPlayer, bool bScoped, bool bIgnoreSkill)
{
    float fMult = 0.0f;
    if (pArmor)
    {
        unsigned char ucWeight = pArmor->GetArmorType();
        if (ucWeight == 1)
            fMult += originalRuntimeFloatSetting827.Float()->f;
        else if (ucWeight == 2)
            fMult += originalRuntimeFloatSetting826.Float()->f;
    }
    if (pWeapon && !bIsPlayer && pWeapon->IsTwoHandedWeapon())
    {
        if (static_cast<const TESObjectWEAP*>(pWeapon)->GetWeaponType() == 8 ||
            static_cast<const TESObjectWEAP*>(pWeapon)->GetWeaponType() == 9)
            fMult += originalRuntimeFloatSetting829.Float()->f;
        else if (static_cast<const TESObjectWEAP*>(pWeapon)->GetWeaponType() != 2)
            fMult += originalRuntimeFloatSetting828.Float()->f;
    }
    float fPenalty = (1.0f - CombatDamageCalculator::GetActorValueMultiplier(pActor, (ActorValue::Index)0x1d, false)) +
                     (1.0f - CombatDamageCalculator::GetActorValueMultiplier(pActor, (ActorValue::Index)0x1e, false));
    float fBase = 1.0f;
    if (fPenalty == 1.0)
        fBase = originalRuntimeFloatSetting1087.Float()->f;
    else if (fPenalty == 2.0)
        fBase = originalRuntimeFloatSetting1088.Float()->f;
    if (!bIgnoreSkill && pActor->GetActorValue((ActorValue::Index)0x48))
        fBase = 1.0f;
    float fResult = pActor->GetCurrentActorValue((ActorValue::Index)0x15) * 1.1;
    float fCrippled = fResult * originalRuntimeFloatSetting833.Float()->f * fBase;
    float fSkill = fCrippled;
    if (bScoped && bIsPlayer)
        fSkill *= originalRuntimeFloatSetting831.Float()->f;
    fSkill = (1.0f - fMult) * fSkill;
    if (bSneaking)
        fSkill *= originalRuntimeFloatSetting832.Float()->f;
    if (fSkill < _gModifierZero)
        return 0.0f;
    return fSkill;
}

namespace fnv_00648090 {
extern double g_d100;

float __cdecl BSMAX_00404010(float, float);
float __cdecl BSMIN(float, float);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting941;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting944;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting942;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting940;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting943;

// @fnv 0x00648090
float ComputeSkillValue(int aiSkill, float afA, float afB, int* apResult)
{
    float fMaxBonus;
    float fTotal = 0.0f;
    afA = afA / 10.0;
    afB = afB / 10.0;
    fMaxBonus = (originalRuntimeFloatSetting941.Float()->f - originalRuntimeFloatSetting940.Float()->f) * aiSkill / g_d100;
    float fSkillValue = originalRuntimeFloatSetting942.Float()->f * BSMIN(afA, afB);
    float fMin = originalRuntimeFloatSetting943.Float()->f +
                 (originalRuntimeFloatSetting944.Float()->f - originalRuntimeFloatSetting943.Float()->f) * aiSkill / 100.0f;
    float fSkillBonus = BSMAX_00404010(afA, afB);
    fTotal = fSkillBonus + originalRuntimeFloatSetting940.Float()->f + fMaxBonus + fSkillValue;
    if (apResult)
    {
        if ((int)InventoryStackRecord::RoundToNearestStep(fTotal * g_d100, 1.0f) <=
            (int)InventoryStackRecord::RoundToNearestStep(fSkillBonus * g_d100, 1.0f))
            *apResult = (int)((fSkillBonus + (double)0.1f - originalRuntimeFloatSetting943.Float()->f) * g_d100 /
                              (originalRuntimeFloatSetting944.Float()->f - originalRuntimeFloatSetting943.Float()->f));
    }
    return fTotal * 10.0;
}
}  // namespace fnv_00648090

extern double g_d100;
extern double DAT_01011588;
struct MersenneTwister
{
    static MersenneTwister* __cdecl GetRandomGenerator();
    float Float(float afMin, float afMax);
};

// @fnv 0x00648fa0
void ComputeMedicineHealing(float& afLimbHealPercent, float& afHealthDamagePercent, int aiMedicineSkill,
                            bool abMorphineUsed, float afWoundPercent)
{
    afLimbHealPercent = MersenneTwister::GetRandomGenerator()->Float(0.0f, aiMedicineSkill * g_d100 / g_d100 *
                                                                      (1.0 + abMorphineUsed * DAT_01011588));
    afHealthDamagePercent = MersenneTwister::GetRandomGenerator()->Float(
        0.0f, (aiMedicineSkill - g_d100) / g_d100 * ((afWoundPercent - g_d100) / g_d100) * g_d100 *
                  (1.0 - abMorphineUsed * DAT_01011588));
}

float __cdecl GamePlayFormulas_GetActorRunSpeed(void*, void*, void*, bool, bool, bool, bool);
// Calls FUN_00647f00 with the given actor, weapon, armor and flags, passing false for the sixth argument, and returns the resulting swim speed.
// @fnv 0x00647f90
float __cdecl GetSwimSpeed(void* apActor, void* apWeapon, void* pArmor, bool abNoWeapon, bool abIsNpc,
                           bool abOverEncumbered)
{
    float swimSpeed;
    swimSpeed = GamePlayFormulas_GetActorRunSpeed(apActor, apWeapon, pArmor, abNoWeapon, abIsNpc, false, abOverEncumbered);
    return swimSpeed;
}

namespace fnv_00648a50 {
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting863;
// @fnv 0x00648a50
float GetScaledLevelValue(int aiLevel)
{
    return (double)aiLevel * originalRuntimeFloatSetting863.Float()->f;
}
}  // namespace fnv_00648a50

namespace fnv_00648b00 {
extern double _DAT_01012640;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1092;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1093;
// @fnv 0x00648b00
float __cdecl ScaleFloatSetting(float afValue, bool abApplySettings)
{
    float result = afValue / _DAT_01012640;
    if (abApplySettings)
    {
        result = originalRuntimeFloatSetting1092.Float()->f / _DAT_01012640 +
                 result * originalRuntimeFloatSetting1093.Float()->f;
    }
    return result;
}
}  // namespace fnv_00648b00

int __cdecl MinInt(int, int);
int __cdecl ComputeIntelligenceResult(int, int);

// Computes the intelligence result from the capped permanent actor value and owner type.
// @fnv 0x00648bc0
// src: COMMUNITY 0x00648bc0
int __cdecl GamePlayFormulas_GetLevelUpSkillPoints_0(ActorValueOwner* apActorValueOwner)
{
    int v;
    v = ComputeIntelligenceResult(MinInt(apActorValueOwner->GetPermanentActorValue((ActorValue::Index)9), 10),
                                  apActorValueOwner->GetActorValueOwnerType());
    return v;
}

namespace fnv_00648d30 {
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1069;
int __cdecl MinInt(int, int);
int __cdecl BSMAX_00647b70(int, int);
// @fnv 0x00648d30
// src: XBOX_PDB 0x00648d30
int GamePlayFormulas_GetForceLockChance(int aiPlayerSkill, int aiLockLevelMax)
{
    return BSMAX_00647b70(MinInt(aiPlayerSkill - aiLockLevelMax + (int)originalRuntimeFloatSetting1069.Float()->f, 100), 0);
}
}  // namespace fnv_00648d30

// @fnv 0x00647cf0
float ConvertUIntToFloat(unsigned int auiValue)
{
    return (float)auiValue;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting839;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting840;

// @fnv 0x00647fd0
// src: XBOX_PDB 0x00647fd0
float __cdecl GamePlayFormulas_GetActorFlySpeed(ActorValueOwner* actor)
{
    float result;        // Actor-value coefficient.
    float scale = 0.0f;  // Running interpolated output.
    result = (float)(actor->GetCurrentActorValue((ActorValue::Index)21) * 0.01);
    scale = originalRuntimeFloatSetting839.Float()->f;
    scale += (originalRuntimeFloatSetting840.Float()->f - originalRuntimeFloatSetting839.Float()->f) * result;
    if (scale < _gModifierZero)
        return 0.0f;
    return scale;
}

extern SettingT_GameSettingCollection_ DAT_011d198c;
extern SettingT_GameSettingCollection_ DAT_011d00e4;
extern SettingT_GameSettingCollection_ DAT_011d1998;
extern SettingT_GameSettingCollection_ DAT_011d06b8;
extern SettingT_GameSettingCollection_ DAT_011d0568;
extern SettingT_GameSettingCollection_ DAT_011d02b0;
extern SettingT_GameSettingCollection_ DAT_011d009c;
extern SettingT_GameSettingCollection_ DAT_011d022c;

// Computes two values from afBase, afDivisor and game settings, then applies type-dependent multipliers and flags to both.
// @fnv 0x006482f0
void __cdecl ComputeDerivedValues(float* afValue1, float* afValue2, float afDivisor, float afBase, int aiType,
                                  bool abFlag1, float afMult1, float afMult2, float afMult3, bool abFlag2)
{
    *afValue1 = pow_004dd130(afBase * DAT_011d00e4.Float()->f / afDivisor, 1.0 / (DAT_011d198c.Float()->f + 1.0));
    *afValue2 = *afValue1 / DAT_011d00e4.Float()->f / DAT_011d1998.Float()->f;

    switch (aiType)
    {
    case 1:
        if (!abFlag1 && !abFlag2)
        {
            *afValue1 += afMult1 * DAT_011d06b8.Float()->f * *afValue1;
            *afValue2 += afMult1 * DAT_011d0568.Float()->f * *afValue2;
        }
    case 2:
        if (abFlag1 && !abFlag2)
        {
            *afValue1 += afMult2 * DAT_011d02b0.Float()->f * *afValue1;
            *afValue2 += afMult2 * DAT_011d009c.Float()->f * *afValue2;
        }
        break;
    case 5:
        if (abFlag1 && !abFlag2)
        {
            *afValue1 += afMult2 * DAT_011d02b0.Float()->f * *afValue1 + afMult3 * DAT_011d022c.Float()->f * *afValue1;
            *afValue2 += afMult2 * DAT_011d009c.Float()->f * *afValue2 + afMult3 * DAT_011d022c.Float()->f * *afValue2;
        }
        else
        {
            *afValue1 += afMult3 * DAT_011d022c.Float()->f * *afValue1;
            *afValue2 += afMult3 * DAT_011d022c.Float()->f * *afValue2;
        }
    case 3:
        *afValue1 += afMult3 * DAT_011d022c.Float()->f * *afValue1;
        *afValue2 += afMult3 * DAT_011d022c.Float()->f * *afValue2;
        break;
    case 4:
        if (!abFlag1 && !abFlag2)
        {
            *afValue1 += *afValue1 * afMult1 * DAT_011d06b8.Float()->f + *afValue2 * afMult3 * DAT_011d022c.Float()->f;
            *afValue2 += *afValue2 * afMult1 * DAT_011d0568.Float()->f + *afValue2 * afMult3 * DAT_011d022c.Float()->f;
        }
        else
        {
            *afValue1 += afMult3 * DAT_011d022c.Float()->f * *afValue1;
            *afValue2 += afMult3 * DAT_011d022c.Float()->f * *afValue2;
        }
        break;
    }
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1115;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting954;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting955;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting956;

// Divides afValue by afDivisor and a runtime setting into pfResult, then adds scaled adjustments selected by aiType and the two flags.
// @fnv 0x00648620
void __cdecl ComputeScaledResult(float* pfResult, float afDivisor, float afValue, int aiType, bool abFlagA,
                                 float afScaleA, float afScaleB, float afScaleC, bool abFlagB)
{
    *pfResult = afValue / afDivisor / originalRuntimeFloatSetting1115.Float()->f;
    switch (aiType)
    {
    case 1:
        if (!abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleA * originalRuntimeFloatSetting954.Float()->f;
        }
    case 2:
        if (abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleB * originalRuntimeFloatSetting956.Float()->f;
        }
        break;
    case 3:
        *pfResult += *pfResult * afScaleC * originalRuntimeFloatSetting955.Float()->f;
        break;
    case 5:
        if (abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleB * originalRuntimeFloatSetting956.Float()->f +
                         *pfResult * afScaleC * originalRuntimeFloatSetting955.Float()->f;
        }
        else
        {
            *pfResult += *pfResult * afScaleC * originalRuntimeFloatSetting955.Float()->f;
        }
        break;
    case 4:
        if (!abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleA * originalRuntimeFloatSetting954.Float()->f +
                         *pfResult * afScaleC * originalRuntimeFloatSetting955.Float()->f;
        }
        else
        {
            *pfResult += *pfResult * afScaleC * originalRuntimeFloatSetting955.Float()->f;
        }
        break;
    }
}

namespace fnv_00648810 {
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting957;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting958;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting959;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1115;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1209;

// Computes a value from a and b via FUN_004dd130 and applies per-kind setting-based multipliers to it, writing the result to out.
// @fnv 0x00648810
void __cdecl ComputeSettingAdjustedValue(float* pfResult, float afDivisor, float afDividend, int kind, bool flag,
                                         float x, float y, float z, bool other)
{
    *pfResult = pow_004dd130((afDividend / afDivisor) / originalRuntimeFloatSetting1115.Float()->f,
                             1.0f / originalRuntimeFloatSetting1209.Float()->f);

    switch (kind)
    {
    case 1:
        if (!flag && !other)
            *pfResult = *pfResult + (*pfResult * x) * originalRuntimeFloatSetting957.Float()->f;
    case 2:
        if (flag && !other)
            *pfResult = *pfResult + (*pfResult * y) * originalRuntimeFloatSetting959.Float()->f;
        break;
    case 3:
        *pfResult = *pfResult + (*pfResult * z) * originalRuntimeFloatSetting958.Float()->f;
        break;
    case 5:
        if (flag && !other)
            *pfResult = *pfResult + (((*pfResult * y) * originalRuntimeFloatSetting959.Float()->f) * z) *
                                        originalRuntimeFloatSetting958.Float()->f;
        else
            *pfResult = *pfResult + (*pfResult * z) * originalRuntimeFloatSetting958.Float()->f;
        break;
    case 4:
        if (!flag && !other)
            *pfResult = *pfResult + (((*pfResult * x) * originalRuntimeFloatSetting957.Float()->f) * z) *
                                        originalRuntimeFloatSetting958.Float()->f;
        else
            *pfResult = *pfResult + (*pfResult * z) * originalRuntimeFloatSetting958.Float()->f;
        break;
    }
}
}  // namespace fnv_00648810

namespace fnv_00648a80 {
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1089;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1090;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1091;
// @fnv 0x00648a80
float ComputeSettingLerp(float fValue)
{
    if (fValue > originalRuntimeFloatSetting1089.Float()->f)
        return 0.0f;
    float fRatio = 1.0f - fValue / originalRuntimeFloatSetting1089.Float()->f;
    float fLerp = originalRuntimeFloatSetting1090.Float()->f +
                  (originalRuntimeFloatSetting1091.Float()->f -
                   originalRuntimeFloatSetting1090.Float()->f) *
                      fRatio;
    return fLerp;
}
}  // namespace fnv_00648a80

extern SettingT_GameSettingCollection_ DAT_011d05ec;
extern SettingT_GameSettingCollection_ DAT_011d0fd8;

// Returns the sum of two setting values, with the second multiplied by fValue times 10.0f.
// @fnv 0x00648050
// src: COMMUNITY 0x00648050
float __cdecl GamePlayFormulas_CalcFatigueReturn(float fValue)
{
    return DAT_011d05ec.Float()->f + DAT_011d0fd8.Float()->f * (fValue * 10.0f);
}

extern SettingT_GameSettingCollection_ g_kSettingBaseD8230;
extern SettingT_GameSettingCollection_ g_kSettingMaxD8230;
extern SettingT_GameSettingCollection_ g_kSettingMultD8230;

float __cdecl FUN_004bd510(float fValue, float fMin);
int __cdecl BSMAX_00647b70(int iValue, int iMin);

// Computes a level-scaled multiplier from base/max settings and difficulty, clamps it to a minimum of 1.0, and returns the integer result.
// @fnv 0x00648230
int __cdecl GetLevelAdjustedMult(int iLevel, float fDiff, float fMult)
{
    int iResult = 0;
    float fValue = 0.0f;
    float fLevelValue =
        g_kSettingBaseD8230.Float()->f + (g_kSettingMaxD8230.Float()->f - g_kSettingBaseD8230.Float()->f) * iLevel / 100.0f;
    fDiff = fDiff / 10.0;
    fValue = g_kSettingMultD8230.Float()->f * fMult * ((fLevelValue - fDiff) / 10.0);
    if (fValue > 0.5)
        iResult = BSMAX_00647b70((int)FUN_004bd510(fValue, 1.0f), 1);
    return iResult;
}

namespace fnv_00649050 {
extern SettingT_GameSettingCollection_ DAT_011d03c4;
extern SettingT_GameSettingCollection_ DAT_011d040c;
extern SettingT_GameSettingCollection_ DAT_011d0760;
extern SettingT_GameSettingCollection_ DAT_011d0370;
// Computes buy and sell price multipliers from skill-based float settings and writes them to the output pointers.
// @fnv 0x00649050
// src: GUESS 0x00649050 (confidence: high)
void Gameplayformulas_GetSkillPriceMultipliers(int iSkill, float* pfBuyMult, float* pfSellMult)
{
    *pfBuyMult = DAT_011d03c4.Float()->f + DAT_011d040c.Float()->f * iSkill / 100.0f;
    *pfSellMult = DAT_011d0760.Float()->f + DAT_011d0370.Float()->f * iSkill / 100.0f;
}
}  // namespace fnv_00649050

