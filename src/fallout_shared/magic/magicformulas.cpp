// fallout_shared/magic/magicformulas.cpp: FlaggedData (10 functions)

#include "magicformulas_packet.h"
#include "../../../include/Setting.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
// @fnv 0x0040e210
int FlaggedData::ContainsAnyFlag(unsigned int mask)
{
    return (flags & mask) != 0;
}
// Returns the result of FUN_00874480 on the object from FUN_004b7210 when it exists and its GetIndex is nonzero, otherwise 0.
// @fnv 0x00703350
int FlaggedData::GetPlayerValue()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<QuestStage*>(InterfaceManager_GetSingleton())->GetIndex())
        return reinterpret_cast<int>(InterfaceManager_GetSingleton()->Projectile_GetShooter());
    return 0;
}

float __cdecl BSMAX_00404010(float, float);
float __cdecl pow_004dd130(float, float);
extern Setting originalRuntimeFloatSetting1116;
extern Setting originalRuntimeFloatSetting1114;
extern Setting originalRuntimeFloatSetting1209;
extern Setting originalRuntimeFloatSetting1115;

// Computes an effect cost from base cost, area, duration and magnitude, applying area, duration and magnitude modifiers and a range-target multiplier.
// @fnv 0x006490b0
float __cdecl CalcEffectCost(float afBaseEffectCost, int aiArea, int aiDuration, int aiMagnitude, bool abIsRangeTarget)
{
    float fdurationModifier;
    float fmagnitudeModifier;
    float fareaModifier;
    float fbaseCost;
    fareaModifier = BSMAX_00404010(*originalRuntimeFloatSetting1114.Float() * (float)aiArea, 1.0f);
    fdurationModifier =
        afBaseEffectCost * *originalRuntimeFloatSetting1115.Float() * (aiDuration == 0 ? 1.0f : (float)aiDuration);
    fmagnitudeModifier =
        aiMagnitude == 0 ? 1.0f : pow_004dd130((float)aiMagnitude, *originalRuntimeFloatSetting1209.Float());
    fbaseCost = fareaModifier * fdurationModifier * fmagnitudeModifier;
    return (abIsRangeTarget ? *originalRuntimeFloatSetting1116.Float() : 1.0f) * fbaseCost;
}

// @fnv 0x006494b0
// src: XBOX_PDB 0x006494b0
float NiPow_006494b0(float afA, float afB)
{
    return pow_004dd130(afA, afB);
}

extern double g_d100;
// Returns 0 if either input is at least g_d100, otherwise computes 1 - ((1 - a/g_d100) * (b/g_d100) + a/g_d100).
// @fnv 0x006492a0
// src: COMMUNITY 0x006492a0
float MagicFormulas_GetMagicTargetResistance(float a, float b)
{
    if (a >= g_d100 || b >= g_d100)
        return 0.0f;
    float fResult;
    {
        float fNormA = a / g_d100;
        float fNormB = b / g_d100;
        fResult = 1.0f - ((1.0f - fNormA) * fNormB + fNormA);
    }
    return fResult;
}

extern Setting originalRuntimeFloatSetting1183;
extern Setting g_011d1a14;
// Scales afMagnitude by a runtime float setting and returns true if the result reaches the global int threshold or is at least aiTargetLevel.
// @fnv 0x006494d0
// src: XBOX_PDB 0x006494d0
bool MagicFormulas_CheckTargetLevelMagnitude(int aiTargetLevel, float afMagnitude)
{
    float fScaledMagnitude;
    fScaledMagnitude = afMagnitude * *originalRuntimeFloatSetting1183.Float();
    if (*g_011d1a14.Int() <= fScaledMagnitude)
        return true;
    else
        return aiTargetLevel <= fScaledMagnitude;
}

extern Setting g_011d1cd0;
extern Setting originalRuntimeFloatSetting1132;
extern Setting originalRuntimeFloatSetting1133;

// @fnv 0x00649300
float ComputeBlastPower(int aiCost, int aiAgility, float afDistance, int aiLuck, int aiArea, float afFatiguePercentage)
{
    float fblastPower = 0.0f;
    float fdistanceRatio = 0.0f;
    if (aiAgility > 0)
    {
        fdistanceRatio = afDistance / (float)aiAgility;
        fdistanceRatio = fdistanceRatio * fdistanceRatio;
        fdistanceRatio = 1.0f - fdistanceRatio;
    }
    else
    {
        fdistanceRatio = 1.0f;
    }
    fblastPower =
        *originalRuntimeFloatSetting1133.Float() * fdistanceRatio * aiCost + *originalRuntimeFloatSetting1132.Float();
    float fLuck = (float)aiLuck;
    fblastPower = fblastPower - fLuck * *g_011d1cd0.Float();
    return fblastPower;
}

extern Setting g_011d1938;
extern Setting originalRuntimeFloatSetting1161;
extern Setting originalRuntimeFloatSetting1160;
extern Setting originalRuntimeFloatSetting1159;
float NiPow_006494b0(float f, float g);

// Returns 0 outside [afStart, afEnd]; otherwise scales afBase by a curve from afTime, afSkill and settings, with flag-dependent multipliers.
// @fnv 0x00649390
// src: XBOX_PDB 0x00649390
float __cdecl MagicFormulas_CalcSunDamage(float afBase, float afTime, float afStart, float afEnd, bool abFlag1, float afSkill,
                           bool abFlag2)
{
    if (afTime < afStart || afTime > afEnd)
        return 0.0f;
    float fRatio9;
    float fFlag2Mult_;
    const float fMid = 12.0f;
    float fFlag1Mult4;
    {
        float fResult;
        float fSkillMult;
        if (afTime > fMid)
            fRatio9 = (fMid - afTime) / (fMid - afEnd);
        else
            fRatio9 = (fMid - afTime) / (fMid - afStart);
        fRatio9 = 1.0f - NiPow_006494b0(fRatio9, 4.0f);
        fSkillMult = (1.0f - *g_011d1938.Float()) * afSkill + *g_011d1938.Float();
        fFlag1Mult4 = !abFlag1 ? *originalRuntimeFloatSetting1161.Float() : 1.0f;
        fFlag2Mult_ = abFlag2 ? *originalRuntimeFloatSetting1160.Float() : 1.0f;
        fResult = *originalRuntimeFloatSetting1159.Float() * afBase * fRatio9 * fSkillMult * fFlag2Mult_ * fFlag1Mult4;
        return fResult;
    }
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1117;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1118;

// Multiplies param_1 by the sum of two runtime float settings, the second weighted by one minus param_2 divided by g_d100.
// @fnv 0x00649180
float __cdecl ScaleBySettingBlend(float afValue, int aiPercent)
{
    float quotient = (float)(aiPercent / g_d100);
    float result = *originalRuntimeFloatSetting1117.Float() +
                   (1.0f - quotient) * *originalRuntimeFloatSetting1118.Float();
    return afValue * result;
}

extern Setting g_011d158c;
extern Setting g_011d1b98;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1119;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1120;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1121;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1122;
// Computes a band index from a linear combination of two global floats and argument, returning 0 to 4 based on which setting threshold it falls below.
// @fnv 0x006491d0
int GetBandIndex(float afValue)
{
    float f = *g_011d158c.Float() + *g_011d1b98.Float() * afValue;
    int r;
    if (f < *originalRuntimeFloatSetting1119.Float())
    {
        r = 0;
    }
    else
    {
        int b;
        if (f < *originalRuntimeFloatSetting1120.Float())
        {
            b = 1;
        }
        else
        {
            int c;
            if (f < *originalRuntimeFloatSetting1121.Float())
            {
                c = 2;
            }
            else
            {
                int d;
                if (f < *originalRuntimeFloatSetting1122.Float())
                    d = 3;
                else
                    d = 4;
                c = d;
            }
            b = c;
        }
        r = b;
    }
    return r;
}
