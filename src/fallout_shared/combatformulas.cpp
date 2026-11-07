// fallout_shared/combatformulas.cpp: CombatDamageCalculator, NiCamera (52 functions)

#include "../../include/BSStringT.h"
#include "../../include/Setting.h"
#include "../../include/Actor.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/BGSAmmoForm.h"
#include "../../include/BGSBipedModelList.h"
#include "../../include/BGSClipRoundsForm.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSEquipType.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/BGSPreloadable.h"
#include "../../include/BGSRepairItemList.h"
#include "../../include/EffectSetting.h"
#include "../../include/FileEntryList.h"
#include "../../include/InventoryStackRecord.h"
#include "../../include/MiddleHighProcess.h"
#include "../../include/PathingRequest.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESAmmoEffect.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESForm.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObject.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"
#include "../../include/WeaponCriticalData.h"
#include "../../include/WeaponProperties.h"
#include "../../include/WeaponVATSData.h"
#include "../../include/NiFile.h"
#include "../../include/BGSProjectile.h"
#include "../../include/TESAnimGroup.h"
#include "../../include/TESCreature.h"
#include "../../include/NiCamera.h"
#include "../../include/PlayerCharacter.h"
#include "combatformulas_dependencies.h"

// Combat formula queries not yet declared by the shared weapon header.
// No layout is duplicated here; all data comes from TESObjectWEAP.
class CombatFormulaWeapon : public TESObjectWEAP
{
public:
    BGSProjectile* GetProjectileForOwner(ActorValueOwner* owner);
    void SetFlag2(bool set);
    bool IsDamageDisabled();
    float GetField124Float();
    bool IsFlag20Set() const;
    unsigned char GetBaseVATSChance(unsigned char modded);
    unsigned int GetAttackAnimation();
    int GetField1BC();
    float GetSpread(bool modded);
    float GetAnimationMultiplier();
};

// @fnv 0x004be0b0
float InventoryStackRecord::GetArmorDamageThreshold(Actor* actor)
{
    float fArmorProtectionValue = -1.0f;
    TESObjectARMO* pArmorForm;
    struct ArmorCondition
    {
        float baseHealth;
        float fraction;
    } condition;
    if (reinterpret_cast<TESForm*>(m_pItemObject)->GetFormType() == 24)
    {
        pArmorForm = reinterpret_cast<TESObjectARMO*>(m_pItemObject);
        condition.baseHealth = TESHealthForm::GetBaseHealth(pArmorForm);
        condition.fraction = condition.baseHealth == 0.0 ? 0.0 : GetConditionPercent(false) / condition.baseHealth;
        fArmorProtectionValue = CombatDamageCalculator::CalculateArmorDamageThreshold(
            (unsigned short)pArmorForm->GetDamageThreshold(), condition.fraction);
    }
    return InventoryStackRecord::GetConditionPercent(fArmorProtectionValue);
}

// @fnv 0x006447f0
float NiCamera::GetMaxFarNearRatio() const
{
    return m_fMaxFarNearRatio;
}

// @fnv 0x00645380
float CombatDamageCalculator::CalculateWeaponDamage(ActorValueOwner* owner, TESObjectWEAP* weapon, float health,
                                                    bool abApplyPerks, InventoryStackRecord* item, bool includeReload,
                                                    bool noJams, int skill, float critChance, float critMult,
                                                    bool sneakAttack, bool specialAttack, TESAmmo* ammoOverride)
{
    if (health <= 0.0)
        return 0.0f;
    // Nested scopes preserve the original MSVC9 stack-local allocation order.
    {
        bool bIsCreature;
        {
            Actor* pActor;
            {
                float fWeaponDamageMultiplier;
                {
                    float fConditionDamageMult;
                    {
                        bool bHasExtendedClip;
                        {
                            int iCondition;
                            {
                                int iClipRounds;
                                {
                                    float m_fClusterOffsetX;
                                    {
                                        bool bHasFireRateMod;
                                        {
                                            float fModBonusDamage;
                                            {
                                                float m_fNextProcedureCheckHour;
                                                {
                                                    float afDamageAmount;
                                                    {
                                                        float fClipDamage;
                                                        {
                                                            float fCritChance;
                                                            {
                                                                bool bHasSplitBeam;
                                                                {
                                                                    float fCritDamage;
                                                                    {
                                                                        float fWeaponDamage;
                                                                        m_fClusterOffsetX = 0.0f;
                                                                        iClipRounds = 1;
                                                                        afDamageAmount = 0.0f;
                                                                        fCritChance = 0.0f;
                                                                        m_fNextProcedureCheckHour = 3.402823466e38f;
                                                                        bIsCreature = false;
                                                                        fWeaponDamage = health;
                                                                        bHasExtendedClip = false;
                                                                        bHasFireRateMod = false;
                                                                        fWeaponDamageMultiplier =
                                                                            weapon ? weapon->GetField14C() : 1.0f;
                                                                        bHasSplitBeam = false;
                                                                        iCondition =
                                                                            (int)InventoryStackRecord::RoundToNearestStep(
                                                                                (float)(fWeaponDamage * 10.0), 1.0f);
                                                                        fModBonusDamage = 0.0f;
                                                                        if (reinterpret_cast<void*>(ammoOverride) ==
                                                                            weapon)
                                                                            ammoOverride = 0;
                                                                        pActor = static_cast<Actor*>(owner);
                                                                        bIsCreature = pActor->IsCreature();
                                                                        if (item)
                                                                        {
                                                                            item->SetEquipmentState(1, fModBonusDamage);
                                                                            bHasExtendedClip =
                                                                                item->SetEquipmentState(2);
                                                                            bHasFireRateMod =
                                                                                item->SetEquipmentState(8);
                                                                            fWeaponDamageMultiplier =
                                                                                CalculateWeaponDamageForActor(
                                                                                    pActor, weapon, false, item);
                                                                            bHasSplitBeam = item->SetEquipmentState(12);
                                                                        }
                                                                        if (weapon)
                                                                        {
                                                                            afDamageAmount = *DAT_011ce2c0.Float() *
                                                                                             weapon->GetAttackDamage();
                                                                            afDamageAmount += fModBonusDamage;
                                                                            if (bHasSplitBeam)
                                                                                afDamageAmount *= 1.3;
                                                                            TESAmmo* pAmmo =
                                                                                ammoOverride
                                                                                    ? ammoOverride
                                                                                    : weapon->GetCurrentAmmo(0);
                                                                            BSSimpleList<TESAmmoEffect*>* pAmmoEffects =
                                                                                pAmmo
                                                                                    ? reinterpret_cast<BSSimpleList<
                                                                                          TESAmmoEffect*>*>(
                                                                                          reinterpret_cast<
                                                                                              TESAmmoInitCalls*>(pAmmo)
                                                                                              ->TESAmmo_GetAmmoEffectList())
                                                                                    : 0;
                                                                            {
                                                                                bool bIsNPC;
                                                                                {
                                                                                    float fCritChanceOverride;
                                                                                    afDamageAmount =
                                                                                        TESAmmoEffect::ApplyAmmoEffects(
                                                                                            AMMO_EFFECT_TYPE_AMMO_EFFECT_DAM,
                                                                                            pAmmoEffects,
                                                                                            afDamageAmount);
                                                                                    if (weapon->GetProjectileData(0) &&
                                                                                        reinterpret_cast<
                                                                                            EffectSetting*>(
                                                                                            weapon->GetProjectileData(
                                                                                                0))
                                                                                            ->GetBoltSound())
                                                                                        afDamageAmount +=
                                                                                            reinterpret_cast<
                                                                                                PathingRequest*>(
                                                                                                reinterpret_cast<
                                                                                                    EffectSetting*>(
                                                                                                    weapon
                                                                                                        ->GetProjectileData(
                                                                                                            0))
                                                                                                    ->GetBoltSound())
                                                                                                ->GetTargetRadius() *
                                                                                            weapon->GetDamageForActor(
                                                                                                bHasSplitBeam, false,
                                                                                                pActor);
                                                                                    switch (weapon->FUN_00446390())
                                                                                    {
                                                                                    case 1:
                                                                                    case 2:
                                                                                    case 13:
                                                                                        break;
                                                                                    case 10:
                                                                                    case 11:
                                                                                        if (weapon->GetProjectileData(
                                                                                                0) &&
                                                                                            reinterpret_cast<
                                                                                                EffectSetting*>(
                                                                                                weapon
                                                                                                    ->GetProjectileData(
                                                                                                        0))
                                                                                                ->GetBoltSound())
                                                                                            afDamageAmount =
                                                                                                *DAT_011ce2c0.Float() *
                                                                                                reinterpret_cast<
                                                                                                    PathingRequest*>(
                                                                                                    reinterpret_cast<
                                                                                                        EffectSetting*>(
                                                                                                        weapon
                                                                                                            ->GetProjectileData(
                                                                                                                0))
                                                                                                        ->GetBoltSound())
                                                                                                    ->GetTargetRadius();
                                                                                        fWeaponDamage = 1.0f;
                                                                                        iCondition = 10;
                                                                                        break;
                                                                                    case -1:
                                                                                    case 0:
                                                                                        break;
                                                                                    default:
                                                                                        iClipRounds =
                                                                                            weapon->GetClipRounds(
                                                                                                bHasExtendedClip);
                                                                                        break;
                                                                                    }
                                                                                    if (skill == -1)
                                                                                        afDamageAmount *=
                                                                                            *DAT_011cece8.Float() +
                                                                                            *DAT_011cf350.Float() *
                                                                                                (owner
                                                                                                     ? owner->GetActorValueFloatByIndex(
                                                                                                           reinterpret_cast<
                                                                                                               MiddleHighProcess*>(
                                                                                                               weapon)
                                                                                                               ->MiddleHighProcess::GetWeaponForm()) /
                                                                                                           100.0f
                                                                                                     : 1.0f);
                                                                                    else
                                                                                    {
                                                                                        float fSkill = skill / 100.0;
                                                                                        afDamageAmount *=
                                                                                            *DAT_011cece8.Float() +
                                                                                            *DAT_011cf350.Float() *
                                                                                                fSkill;
                                                                                    }
                                                                                    if (abApplyPerks)
                                                                                        ApplyPerkModifiers(
                                                                                            0, pActor,
                                                                                            (weapon
                                                                                                 ? static_cast<
                                                                                                       TESForm*>(weapon)
                                                                                                 : 0),
                                                                                            pActor, &afDamageAmount);
                                                                                    m_fNextProcedureCheckHour =
                                                                                        fWeaponDamageMultiplier;
                                                                                    if (weapon->FUN_00446390() != 10 &&
                                                                                        weapon->FUN_00446390() != 11 &&
                                                                                        weapon->FUN_00446390() != 13)
                                                                                    {
                                                                                        if (noJams)
                                                                                            m_fNextProcedureCheckHour +=
                                                                                                iClipRounds *
                                                                                                GetWeaponConditionDamageMultiplier(
                                                                                                    0) *
                                                                                                weapon->GetField154();
                                                                                        else
                                                                                            m_fNextProcedureCheckHour +=
                                                                                                iClipRounds *
                                                                                                GetWeaponConditionDamageMultiplier(
                                                                                                    iCondition) *
                                                                                                weapon->GetField154();
                                                                                    }
                                                                                    m_fNextProcedureCheckHour =
                                                                                        iClipRounds /
                                                                                        m_fNextProcedureCheckHour;
                                                                                    if ((iClipRounds <=
                                                                                             *DAT_011cf888.Int() ||
                                                                                         includeReload) &&
                                                                                        weapon->FUN_00446390() != 1 &&
                                                                                        weapon->FUN_00446390() != 2 &&
                                                                                        weapon->FUN_00446390() != 0 &&
                                                                                        weapon->FUN_00446390() != 10 &&
                                                                                        weapon->FUN_00446390() != 13 &&
                                                                                        weapon->FUN_00446390() != 11)
                                                                                        m_fNextProcedureCheckHour +=
                                                                                            weapon->GetField150Float();
                                                                                    bIsNPC = false;
                                                                                    if (pActor !=
                                                                                        reinterpret_cast<Actor*>(
                                                                                            g_thePlayer))
                                                                                        bIsNPC = true;
                                                                                    if (bIsNPC &&
                                                                                        weapon->IsRangedWeapon())
                                                                                    {
                                                                                        if (!weapon
                                                                                                 ->GetIsAutomaticWeapon())
                                                                                        {
                                                                                            float fAttackDelay =
                                                                                                (weapon
                                                                                                     ->GetProjectileData() +
                                                                                                 reinterpret_cast<
                                                                                                     MiddleHighProcess*>(
                                                                                                     weapon)
                                                                                                     ->MiddleHighProcess::GetThirdProcessFloat()) /
                                                                                                runtimeInitializationDouble2;
                                                                                            float fShotDelay =
                                                                                                1.0f /
                                                                                                fWeaponDamageMultiplier;
                                                                                            if (fAttackDelay >
                                                                                                fShotDelay)
                                                                                            {
                                                                                                float fExtraDelay =
                                                                                                    fAttackDelay -
                                                                                                    fShotDelay;
                                                                                                m_fNextProcedureCheckHour +=
                                                                                                    iClipRounds *
                                                                                                    fExtraDelay;
                                                                                            }
                                                                                        }
                                                                                        bool bIsBurst =
                                                                                            weapon
                                                                                                ->GetIsAutomaticWeapon() ||
                                                                                            weapon->GetBurstShot();
                                                                                        if (bIsBurst)
                                                                                            m_fNextProcedureCheckHour *=
                                                                                                (*DAT_011ceef0.Float() +
                                                                                                 *DAT_011cf21c.Float()) /
                                                                                                *DAT_011cf21c.Float();
                                                                                    }
                                                                                    fCritChanceOverride = 0.0f;
                                                                                    if (critChance != 0.0)
                                                                                        fCritChanceOverride =
                                                                                            critChance * 100.0;
                                                                                    fCritChance =
                                                                                        (owner
                                                                                             ? owner
                                                                                                   ->GetCurrentActorValue(
                                                                                                       (ActorValue::
                                                                                                            Index)14)
                                                                                             : fCritChanceOverride) *
                                                                                        1.0 *
                                                                                        reinterpret_cast<Actor*>(weapon)
                                                                                            ->ProcessActorAction();
                                                                                    BSClamp_float(fCritChance, 0.0f,
                                                                                                 100.0f);
                                                                                    fCritChance *= (double)0.01f;
                                                                                    if (weapon &&
                                                                                        weapon
                                                                                            ->GetIsAutomaticWeapon() &&
                                                                                        fWeaponDamageMultiplier != 0.0)
                                                                                        fCritChance /=
                                                                                            fWeaponDamageMultiplier;
                                                                                }
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            if (bIsCreature)
                                                                                afDamageAmount =
                                                                                    ((int(__thiscall*)(Actor*))(*(void***)pActor)[0x111])(pActor);
                                                                            else
                                                                            {
                                                                                afDamageAmount =
                                                                                    *DAT_011cf810.Float() *
                                                                                    (owner
                                                                                         ? owner->GetCurrentActorValue(
                                                                                               (ActorValue::Index)56)
                                                                                         : 0.0f);
                                                                                afDamageAmount +=
                                                                                    (owner
                                                                                         ? owner->GetActorValueFloatByIndex(
                                                                                               (ActorValue::Index)45) /
                                                                                               100.0
                                                                                         : 0.0) *
                                                                                    *DAT_011cf350.Float();
                                                                            }
                                                                            m_fNextProcedureCheckHour =
                                                                                bIsCreature ? *DAT_011cf6c0.Float()
                                                                                            : *DAT_011cfbf0.Float();
                                                                        }
                                                                        fConditionDamageMult =
                                                                            GetWeaponHealthConditionMultiplier(health);
                                                                        afDamageAmount *= fConditionDamageMult;
                                                                        fCritDamage =
                                                                            weapon
                                                                                ? (float)weapon->GetShortAtOffset1C0()
                                                                                : 0.0f;
                                                                        if (critMult != 0.0 && fCritDamage != 0.0)
                                                                            fCritDamage *= critMult;
                                                                        fClipDamage =
                                                                            iClipRounds *
                                                                            ((afDamageAmount +
                                                                              fCritChance * fCritDamage) *
                                                                             ((sneakAttack ? 2.0f : 1.0f) *
                                                                              (specialAttack ? 1.25f : 1.0f)));
                                                                        if (m_fNextProcedureCheckHour != 0.0)
                                                                            m_fClusterOffsetX =
                                                                                fClipDamage / m_fNextProcedureCheckHour;
                                                                        return m_fClusterOffsetX;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// @fnv 0x00646800
float CombatDamageCalculator::GetActorValueMultiplier(ActorValueOwner* owner, ActorValue::Index part, bool percentage)
{
    float fWeaponDamage = 1.0f;
    switch (part)
    {
    case (ActorValue::Index)25:
    case (ActorValue::Index)26:
    case (ActorValue::Index)27:
    case (ActorValue::Index)28:
    case (ActorValue::Index)29:
    case (ActorValue::Index)30:
    case (ActorValue::Index)31:
        fWeaponDamage = BSMIN(100.0f, owner->GetCurrentActorValue(part));
        if (!percentage)
            fWeaponDamage = fWeaponDamage > 0.0 ? 1.0f : 0.0f;
    }
    return fWeaponDamage;
}

// Computes the min and max of two floats and returns a random float in that range, or the shared value if they are equal.
// @fnv 0x006465f0
float CombatDamageCalculator::GetDamageMultiplier(float afValueA, float afValueB)
{
    // Local min/max pair (maximum stored first, at +0x00); not the shared AABB Bounds.
    struct DamageRange
    {
        float maximum;
        float minimum;
    } bounds;
    bounds.minimum = BSMIN(afValueA, afValueB);
    bounds.maximum = BSMAX_00404010(afValueA, afValueB);
    if (bounds.minimum != bounds.maximum)
    {
        return RandomFloat(bounds.minimum, bounds.maximum);
    }
    else
    {
        return bounds.minimum;
    }
}

// Multiplies rating by the condition multiplier from GetArmorConditionFactor and returns the result.
// @fnv 0x00646360
float CombatDamageCalculator::CalculateArmorDamageThreshold(unsigned short rating, float condition)
{
    float fRating = 0.0f;
    float fConditionMult = GetArmorConditionFactor(condition);
    fRating = rating * fConditionMult;
    return fRating;
}

// @fnv 0x005dc980
// src: XBOX_PDB 0x005dc980
char __fastcall BGSBodyPart_GetToHitChance(const char* pThis)
{
    return pThis[0x64];
}

// Maps a weapon health percentage to a damage multiplier: returns 1.0 above 0.75, otherwise scales down by 0.67 per unit below 0.75.
// @fnv 0x00646d00
float __cdecl GetWeaponHealthConditionMultiplier(float fWeapHealthPercent)
{
    if (fWeapHealthPercent > 0.75)
    {
        return 1.0f;
    }
    else
    {
        return 1.0 - (0.75 - fWeapHealthPercent) * 0.6700000166893005;
    }
}

extern double DAT_01011588;

// Returns 1.0 when fArmorHealthPercent exceeds DAT_01011588, otherwise returns 1.0 minus the shortfall from DAT_01011588.
// @fnv 0x00646d40
float GetArmorConditionFactor(float fArmorHealthPercent)
{
    if (fArmorHealthPercent > DAT_01011588)
        return 1.0f;
    else
        return 1.0 - (DAT_01011588 - fArmorHealthPercent) * 1.0;
}

// Clamps the int pointed to by aVal to the range [aMin, aMax], writing the bound back when it is out of range.
// @fnv 0x00647ba0
void __cdecl ClampInt(int* aVal, int aMin, int aMax)
{
    if (*aVal > aMax)
    {
        *aVal = aMax;
    }
    else if (*aVal < aMin)
    {
        *aVal = aMin;
    }
}

struct FUN_00644930_shell
{
    char m_auiShapeKeys[0x94];
    float m_f;
    float __thiscall Explosion_GetRadius();
};

// @fnv 0x00644930
// src: XBOX_PDB 0x00644930
float __thiscall FUN_00644930_shell::Explosion_GetRadius()
{
    return m_f;
}

// @fnv 0x00644970
// src: COMMUNITY 0x00644970
float __fastcall TESWaterForm_GetDepthY(void* p)
{
    return *(float*)((char*)p + 0x104);
}

struct FUN_00644a30_shell
{
    unsigned char __thiscall TESCombatStyle_GetDodgeChance();
};

// @fnv 0x00644a30
// src: COMMUNITY 0x00644a30
unsigned char __thiscall FUN_00644a30_shell::TESCombatStyle_GetDodgeChance()
{
    return *(unsigned char*)((char*)this + 0x58);
}

struct FUN_00644a50_shell
{
    char pad[0xc4];
    float fValue;
    float TESCombatStyle_GetDodgeDuringAttackMult();
};

// @fnv 0x00644a50
// src: COMMUNITY 0x00644a50
float FUN_00644a50_shell::TESCombatStyle_GetDodgeDuringAttackMult()
{
    return fValue;
}

// @fnv 0x00646250
// src: COMMUNITY 0x00646250
float CombatFormulas_CalcCreatureDamage(int a, int b)
{
    return (float)b;
}

float NiSqrt_004579e0(float a);
extern double _gModifierZero;

// Returns 0 when 1-b is negative, otherwise returns FUN_004579e0(1-b) multiplied by a.
// @fnv 0x00647960
// src: XBOX_PDB 0x00647960
float CombatFormulas_CalcExplosionPowerDistance(float a, float b)
{
    float t = 1.0f - b;
    if (t < 0.0f)
        return 0.0f;
    return NiSqrt_004579e0(t) * a;
}

struct FUN_00644950_shell
{
    virtual float Sky_GetFlash();
};

// @fnv 0x00644950
// src: COMMUNITY 0x00644950
float FUN_00644950_shell::Sky_GetFlash()
{
    return *(float*)((char*)this + 0x100);
}

struct FUN_00644cc0_shell
{
    unsigned char GetByteAt59();
};

// @fnv 0x00644cc0
unsigned char FUN_00644cc0_shell::GetByteAt59()
{
    return *(unsigned char*)((char*)this + 0x59);
}

// @fnv 0x00645320
void CombatFormulaWeapon::SetFlag2(bool abSet)
{
    abSet ? data.cFlags |= 2 : data.cFlags &= ~2;
}

// @fnv 0x00646230
bool CombatFormulaWeapon::IsDamageDisabled()
{
    return (data.WeaponAttackData & 0x40) ? true : false;
}

// @fnv 0x00646f50
float CombatFormulaWeapon::GetField124Float()
{
    return data.m_fMaximumRange;
}

// @fnv 0x00647790
bool CombatFormulaWeapon::IsFlag20Set() const
{
    return (data.WeaponAttackData & 0x20) ? true : false;
}

extern Setting* DAT_0119b26c[10];

// Returns the float value of the game setting at index aiCondition if it is in [0,10), otherwise 0.0f.
// @fnv 0x006477b0
// src: XBOX_PDB 0x006477b0
float CombatFormulas_GetWeaponConditionJamMult(int aiCondition)
{
    float fresult = 0.0f;
    if (aiCondition >= 0 && aiCondition < 10)
    {
        fresult = *DAT_0119b26c[aiCondition]->Float();
    }
    return fresult;
}

extern "C"
{
    extern Setting* DAT_0119b2bc[10];
}

// Returns the float value of the game setting at index a if a is in [0,10), otherwise 0.0f.
// @fnv 0x006477e0
// src: COMMUNITY 0x006477e0
float __cdecl CombatFormulas_GetWeaponConditionReloadJamMult(int aiIndex)
{
    float v = 0.0f;
    if (aiIndex >= 0 && aiIndex < 10)
        v = *DAT_0119b2bc[aiIndex]->Float();
    return v;
}

// Returns 1 minus the square of b/a when a is at least b, otherwise 0.
// @fnv 0x00647920
float ComputeSquaredRatioComplement(float a, float b)
{
    float result = 0.0f;
    if (a >= b)
    {
        result = b / a;
        result = result * result;
        result = 1.0f - result;
    }
    return result;
}

float __cdecl CombatFormulas_CalcExplosionPowerDistance(float, float);

// Computes the damage ratio afActualDamage/afBaseExplosionDamage, returns 0 if it exceeds 1, otherwise passes the radius and ratio to FUN_00647960.
// @fnv 0x006479a0
float __cdecl ComputeExplosionDamageFalloff(float afExplosionRadius, float afBaseExplosionDamage, float afActualDamage)
{
    float fDamageRatio = afActualDamage / afBaseExplosionDamage;
    if (fDamageRatio > 1.0f)
        return 0.0f;
    return CombatFormulas_CalcExplosionPowerDistance(afExplosionRadius, fDamageRatio);
}

// @fnv 0x00525ae0
BGSProjectile* CombatFormulaWeapon::GetProjectileForOwner(ActorValueOwner* pActorOffset)
{
    Actor* actor = pActorOffset ? (Actor*)((char*)pActorOffset - 0xA4) : 0;
    return GetProjectileData(actor);
}

// @fnv 0x00646020
// src: XBOX_PDB 0x00646020
float TESObjectWEAP::GetAttackSpeed(bool bModValue)
{
    if (bModValue)
        return GetModdedWeaponValue((WEAPON_MOD_EFFECT)8, 0) + data.m_fAnimationAttackMultiplier;
    else
        return data.m_fAnimationAttackMultiplier;
}

extern Setting originalRuntimeFloatSetting508;
// Multiplies a by b, then multiplies the result by the float value of originalRuntimeFloatSetting508.
// @fnv 0x006462e0
// src: XBOX_PDB 0x006462e0
float CombatFormulas_CalcDamageToArmor(float afValueA, float afValueB)
{
    return (double)(afValueA * afValueB) * *originalRuntimeFloatSetting508.Float();
}

extern double DAT_01011588;
float __cdecl CombatFormulas_CalcWeaponDamage(void*, int, float, float, int, int, int, int);
// Stores the result of FUN_00644ce0 into *c and, when b is false, sets *d to *c multiplied by DAT_01011588.
// @fnv 0x00646310
// src: XBOX_PDB 0x00646310
void CombatFormulas_CalcHandToHandDamage(void* a, bool b, float* pfValue, float* pfScaledValue)
{
    *pfValue = CombatFormulas_CalcWeaponDamage(a, 0, 1.0f, 1.0f, 0, 0, 0, 0);
    if (!b)
        *pfScaledValue = *pfValue * DAT_01011588;
}

void __cdecl ClampInt(int*, int, int);
extern Setting originalRuntimeFloatSetting583;
// @fnv 0x00647810
// src: XBOX_PDB 0x00647810
float __cdecl CombatFormulas_GetWeaponStrengthRequirementModifier(unsigned int uiMinuend, unsigned int uiSubtrahend, unsigned int a3)
{
    int v = 0;
    if (uiSubtrahend <= uiMinuend)
    {
        v = uiMinuend - uiSubtrahend - a3;
    }
    else
    {
        v = 0;
    }
    ClampInt(&v, 0, 10);
    return (double)v * *originalRuntimeFloatSetting583.Float();
}

// @fnv 0x00647730
unsigned char CombatFormulaWeapon::GetBaseVATSChance(unsigned char type)
{
    if (type)
    {
        return (unsigned char)GetModdedWeaponValue((WEAPON_MOD_EFFECT)13, 0) + data.m_ucBaseVATSChance;
    }
    else
    {
        return data.m_ucBaseVATSChance;
    }
}

bool __fastcall TESObjectWEAP_IsMeleeWeapon(TESObjectWEAP*);
// @fnv 0x00645d00
// src: COMMUNITY 0x00645d00
float __cdecl ActorValueOwner_GetWeaponAnimMult(ActorValueOwner* pActorValueOwner, TESObjectWEAP* weapon, InventoryStackRecord* item)
{
    float frateOfFire = 1.0f;
    Actor* pactor = 0;
    pactor = pActorValueOwner ? (Actor*)((char*)pActorValueOwner - 0xa4) : 0;
    if (TESObjectWEAP_IsMeleeWeapon(weapon))
        frateOfFire = ((CombatFormulaWeapon*)weapon)->GetAnimationMultiplier();
    else
        frateOfFire = CombatDamageCalculator::CalculateWeaponDamageForActor(
            dynamic_cast<TESObjectREFR*>(pActorValueOwner), weapon, true, item);
    bool bUseSplit = false;
    if (item)
        bUseSplit = item->SetEquipmentState(0xc);
    frateOfFire = weapon->GetDamageForActor(bUseSplit, false, pactor) * frateOfFire;
    return frateOfFire;
}

namespace fnv_00645dc0 {
struct Animation
{
    unsigned short ResolveAnimGroup(unsigned short, bool);
};
struct HackAnim
{
    TESAnimGroup* Animation_LookupGroup(unsigned short);
};
// The shared group does not declare the event-time query yet.
struct AnimGroupTiming : TESAnimGroup
{
    float GetActionTime(int);
};
extern PlayerCharacter* g_thePlayer;
extern int DAT_0118a838[];
extern double gModifierZero;
int __cdecl GetType(unsigned short);
bool __fastcall TESObjectWEAP_IsThrownWeapon(TESObjectWEAP*);

// Computes a weapon's shots-per-second from its animation group timings, reload time and speed modifiers, folding in reload when requested.
// @fnv 0x00645dc0
// src: COMMUNITY 0x00645dc0
float Actor_GetAttackSpeedMult(TESObjectREFR* apActorRef, TESObjectWEAP* apWeapon, bool abUseReload, InventoryStackRecord* apItem)
{
    float fweapSPS = 0;
    float fweapReloadTime = 0;
    bool bClipSize = false;
    bool bSpeedMod = false;
    Animation* panim = reinterpret_cast<Animation*>(g_thePlayer->GetAnimation(false));
    if (apItem)
    {
        bClipSize = apItem->SetEquipmentState(2);
        bSpeedMod = apItem->SetEquipmentState(8);
    }
    if (panim && abUseReload)
    {
        int iReloadAnim = apWeapon->GetReloadAnim(bClipSize);
        if (iReloadAnim == 0xff)
            iReloadAnim = 0xb1;
        unsigned short sanimGroup =
            TESAnimGroup::AnimGroup(0, DAT_0118a838[apWeapon->FUN_00446390()], iReloadAnim, false);
        sanimGroup = panim->ResolveAnimGroup(sanimGroup, false);
        if (GetType(sanimGroup) == iReloadAnim)
        {
            TESAnimGroup* panimGroup = ((HackAnim*)panim)->Animation_LookupGroup(sanimGroup);
            if (panimGroup)
                fweapReloadTime = static_cast<AnimGroupTiming*>(panimGroup)->GetActionTime(1) *
                                  ((CombatFormulaWeapon*)apWeapon)->GetAnimationMultiplier();
        }
    }
    if (apWeapon->GetIsAutomaticWeapon() || !panim)
    {
        fweapSPS = ((TESCreature*)apWeapon)->TESObjectWEAP_GetShotsPerSecond() * apWeapon->GetAttackSpeed(bSpeedMod);
    }
    else if (panim)
    {
        int eattackAnim = ((CombatFormulaWeapon*)apWeapon)->GetAttackAnimation();
        if (eattackAnim == 0xff)
            eattackAnim = 0x20;
        unsigned short sanimGroup =
            TESAnimGroup::AnimGroup(0, DAT_0118a838[apWeapon->FUN_00446390()], eattackAnim, false);
        sanimGroup = panim->ResolveAnimGroup(sanimGroup, false);
        if (GetType(sanimGroup) == eattackAnim)
        {
            TESAnimGroup* panimGroup = ((HackAnim*)panim)->Animation_LookupGroup(sanimGroup);
            fweapSPS = 1.0f / static_cast<AnimGroupTiming*>(panimGroup)->GetActionTime(3);
        }
    }
    if (abUseReload && fweapReloadTime > gModifierZero && fweapSPS > gModifierZero)
    {
        int inumRounds = TESObjectWEAP_IsThrownWeapon(apWeapon) ? 1 : apWeapon->GetClipRounds(bClipSize);
        float freloadRounds = fweapReloadTime / inumRounds;
        freloadRounds = 1.0f / fweapSPS + freloadRounds;
        fweapSPS = 1.0f / freloadRounds;
    }
    return ((CombatFormulaWeapon*)apWeapon)->GetAnimationMultiplier() * fweapSPS *
           apWeapon->GetAttackSpeed(bSpeedMod);
}
}  // namespace fnv_00645dc0

// Returns the average of actor values 27 and 28 for weapon types 0,2,5-9, otherwise actor value 28 alone.
// @fnv 0x00646880
// src: XBOX_PDB 0x00646880
float CombatFormulas_GetArmCondition(ActorValueOwner* actor, int weaponType)
{
    float result = 1.0f;
    switch (weaponType)
    {
    case 0:
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        result = (CombatDamageCalculator::GetActorValueMultiplier(actor, ActorValue::Index(27), false) +
                  CombatDamageCalculator::GetActorValueMultiplier(actor, ActorValue::Index(28), false)) /
                 2.0;
        break;
    default:
        result = CombatDamageCalculator::GetActorValueMultiplier(actor, ActorValue::Index(28), false);
        break;
    }
    return result;
}

extern Setting g_011ce660;
extern Setting originalRuntimeFloatSetting611;
extern Setting originalRuntimeFloatSetting612;
extern Setting originalRuntimeFloatSetting613;

// Computes a damage multiplier from the owner's agility (actor value 10) and the damage value using four game settings, and returns their product.
// @fnv 0x00646580
// src: XBOX_PDB 0x00646580
float CombatFormulas_GetKnockbackSpeed(ActorValueOwner* owner, int damage)
{
    float fmodAgility;
    float fDamageFactor;
    {
        float fagility = owner->GetActorValueFloatByIndex((ActorValue::Index)10) * 10.0;
        fDamageFactor = *g_011ce660.Float() + *originalRuntimeFloatSetting611.Float() * fagility;
    }
    {
        fmodAgility = *originalRuntimeFloatSetting612.Float() + *originalRuntimeFloatSetting613.Float() * damage;
    }
    return fDamageFactor * fmodAgility;
}

extern Setting originalRuntimeFloatSetting760;

struct FUN_00646260Process
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual InventoryStackRecord* GetTarget();
};

// @fnv 0x00646260
// src: COMMUNITY 0x00646260
float CombatFormulas_CalcDamageToWeapon(Actor* apActor)
{
    TESObjectWEAP* pWeap;
    float m_fCriticalHitMultiplier;

    m_fCriticalHitMultiplier = *reinterpret_cast<float*>(originalRuntimeFloatSetting760.Float());
    pWeap = reinterpret_cast<FUN_00646260Process*>(apActor->GetCurrentAIProcess())->GetTarget()->GetFlags();

    if (pWeap && pWeap->GetCurrentAmmo(apActor))
    {
        m_fCriticalHitMultiplier = TESAmmoEffect::ApplyAmmoEffects(
            AMMO_EFFECT_TYPE(4),
            reinterpret_cast<BSSimpleList<TESAmmoEffect*>*>(
                reinterpret_cast<TESAmmoInitCalls*>(pWeap->GetCurrentAmmo(apActor))->TESAmmo_GetAmmoEffectList()),
            m_fCriticalHitMultiplier);
    }

    return m_fCriticalHitMultiplier;
}

// Returns true when the weapon's data.eType is 0, 1 or 2, otherwise false.
// @fnv 0x006450c0
// src: XBOX_PDB 0x006450c0
bool __fastcall TESObjectWEAP_IsMeleeWeapon(TESObjectWEAP* pWeap)
{
    switch (pWeap->data.eType)
    {
    case 0:
    case 1:
    case 2:
        return true;
    }
    return false;
}

struct DamageAmmo
{
    signed char GetCategory();
};
struct CombatActorForm
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual DamageAmmo* GetAmmo();
    int GetFormType();
};
struct NPCCombatPrefix
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
};
struct CreatureCombatPrefix
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
};
struct NPCCombatForm : CombatActorForm, NPCCombatPrefix
{
    ActorValueOwner actorValues;
};
struct CreatureCombatForm : CombatActorForm, CreatureCombatPrefix
{
    ActorValueOwner actorValues;
    DamageAmmo* GetCreatureAmmo();
};
extern const double DAT_01020758;
extern const double DAT_0102f078;
// Computes weapon damage via FUN_00645380 for NPC or creature forms, then scales it by weapon type and ammo category.
// @fnv 0x00646060
float __cdecl ComputeWeaponDamage(CombatActorForm* form, TESObjectWEAP* weapon, float condition, DamageAmmo* ammo,
                                  void* changes, void* extra)
{
    if (weapon && static_cast<CombatFormulaWeapon*>(weapon)->IsDamageDisabled())
        return 0.0f;
    float damage3 = 0.0f;
    if (form->GetFormType() == 43 || form->GetFormType() == 42)
    {
        NPCCombatForm* npc = static_cast<NPCCombatForm*>(form);
        damage3 = CombatDamageCalculator::CalculateWeaponDamage(
            (npc ? &npc->actorValues : 0), weapon, condition, false,
            reinterpret_cast<InventoryStackRecord*>(changes), false, false, -1, 0.0f, 0.0f, false, false,
            reinterpret_cast<TESAmmo*>(extra));
        if (!ammo)
            ammo = npc->GetAmmo();
    }
    else
    {
        CreatureCombatForm* pCreature = static_cast<CreatureCombatForm*>(form);
        damage3 = CombatDamageCalculator::CalculateWeaponDamage(
            (pCreature ? &pCreature->actorValues : 0), weapon, condition, false,
            reinterpret_cast<InventoryStackRecord*>(changes), false, false, -1, 0.0f, 0.0f, false, false,
            reinterpret_cast<TESAmmo*>(extra));
        if (!ammo)
            ammo = pCreature->GetCreatureAmmo();
    }
    int weaponType = weapon ? weapon->TESObjectWEAP_GetCombatWeaponType() : 6;
    if (weaponType == 3)
        damage3 /= DAT_01020758;
    else if (weaponType == 4)
        damage3 = 0.0f;
    if (ammo)
    {
        signed char cAmmoCategory = ammo->GetCategory();
        if (cAmmoCategory == 1 && weapon && weapon->IsRangedWeapon())
            damage3 /= DAT_0102f078;
        else if (cAmmoCategory == 2 && (!weapon || !weapon->IsRangedWeapon()))
            damage3 /= DAT_0102f078;
    }
    return damage3;
}

extern Setting DAT_011cfd58;
extern Setting DAT_011cf618;
extern Setting DAT_011cf624;
extern Setting DAT_011cfe74;
extern Setting DAT_011cfd04;
extern Setting DAT_011cf724;
extern Setting DAT_011cf950;
extern Setting DAT_011cfb9c;
float __cdecl FUN_00408840(float);

// @fnv 0x006466e0
float __cdecl RemapValueBySettings(float aValue, bool bAlternative)
{
    float fMinimumInputValue = bAlternative ? *DAT_011cfd58.Float() : *DAT_011cf618.Float();
    float lowOutput = bAlternative ? *DAT_011cf624.Float() : *DAT_011cfe74.Float();
    float value = bAlternative ? *DAT_011cfd04.Float() : *DAT_011cf724.Float();
    float fTargetUpperBound = bAlternative ? *DAT_011cf950.Float() : *DAT_011cfb9c.Float();
    float highOutput = FUN_00408840(aValue);
    highOutput = (highOutput - fMinimumInputValue) / (lowOutput - fMinimumInputValue);
    highOutput = BSMIN(1.0f, BSMAX_00404010(highOutput, 0.0f));
    return (fTargetUpperBound - value) * highOutput + value;
}

extern Setting DAT_011ce2fc;
extern Setting DAT_011cf2ec;
extern const double DAT_01016408;
unsigned int __cdecl FUN_00487f50();
struct ChanceModifier
{
    int __thiscall Actor_GetCurrentCombatTarget();
};
// Rolls a random 0-99 value and sets success/critical flags against computed chances, then applies a modifier that can override the outcome.
// @fnv 0x00646e50
void __cdecl RollChanceOutcome(void* unused, ChanceModifier* modifier, int baseChance, int effectChance,
                               int extraChance, bool fixedChance, unsigned char* success, unsigned char* critical)
{
    *success = 0;
    *critical = 0;
    unsigned int normalChance = FUN_00487f50() % 100;
    int intermediateChance;
    if (fixedChance)
    {
        intermediateChance = baseChance + extraChance;
    }
    else
    {
        int criticalBase = extraChance + *DAT_011ce2fc.Int();
        intermediateChance = (int)((double)criticalBase * ((double)baseChance * DAT_01016408));
    }
    int criticalChance = intermediateChance;
    int roll = effectChance + *DAT_011cf2ec.Int();
    if ((int)normalChance < criticalChance)
    {
        *critical = 1;
    }
    else if ((int)normalChance < roll)
    {
        *success = 1;
    }
    if (modifier && (*critical || *success))
    {
        switch (modifier->Actor_GetCurrentCombatTarget())
        {
        case 1:
            *critical = 0;
            *success = 1;
            break;
        case 2:
            *critical = 1;
            *success = 0;
            break;
        case 3:
            *critical = 0;
            *success = 0;
            break;
        }
    }
}

extern const double g_d644810Zero;

unsigned int __cdecl C644810Random();

class C644810Actor
{
  public:
    char GetBaseChance();
    float GetLuckBonus();
    float GetSkillBonus();
    float GetBaseModifier();
    float GetScaledModifier();
};

// Computes a success chance from the actor's base chance plus optional luck and skill bonuses and a difficulty modifier, then compares it against a random roll.
// @fnv 0x00644810
bool __cdecl CheckChanceSuccess(C644810Actor* pkActor, float fDifficulty, bool bUseLuck, bool bUseSkill, bool bAutoFail)
{
    if (bAutoFail)
        return false;

    float fChancePercent = pkActor->GetBaseChance();
    if (fChancePercent == g_d644810Zero)
        return false;
    else if (fChancePercent >= 100.0)
        return true;

    float fA = bUseLuck ? pkActor->GetLuckBonus() : 0.0f;
    float fSkillValueBonus = bUseSkill ? pkActor->GetSkillBonus() : 0.0f;
    float fC = pkActor->GetBaseModifier() + (1.0 - fDifficulty) * pkActor->GetScaledModifier();
    fChancePercent = fA + fSkillValueBonus + fC + fChancePercent;

    float fRandom = (float)(C644810Random() % 100);
    return fRandom <= fChancePercent;
}

struct OCActor
{
    float GetFieldCC();
    float FUN_00453700();
    float GetFirstLightParameter();
    float FUN_00885bd0();
    char GetByteAt59();
};

unsigned int __cdecl OCDialogueRandom();

extern Setting g_kOCSettingSkillMult;
extern Setting g_kOCSettingBonus;

// Rolls three skill/bonus-weighted random scores and returns an outcome code (0,1,2,4,8) based on comparisons and actor checks.
// @fnv 0x00644a70
// src: XBOX_PDB 0x00644a70
unsigned short __cdecl CombatFormulas_SelectDodgeDirection(OCActor* apActor, bool abUseSkillB, bool abUseSkillA, float afValueA,
                                    float afValueB, bool abBonus, bool abNoFirst, unsigned short ausFlags)
{
    unsigned short usResult6 = 0;
    usResult6 = 0;

    float fFirst = *g_kOCSettingSkillMult.Float() * (abUseSkillA ? apActor->GetFieldCC() : apActor->FUN_00453700()) *
                   (OCDialogueRandom() % 5 + 1);
    float fSecond = *g_kOCSettingSkillMult.Float() *
                    (abUseSkillB ? apActor->GetFirstLightParameter() : apActor->FUN_00885bd0()) *
                    (OCDialogueRandom() % 5 + 1);
    if ((ausFlags & 2) || abNoFirst)
        fFirst = 0.0f;
    if (ausFlags & 1)
        fSecond = 0.0f;
    float fThird2 =
        *g_kOCSettingSkillMult.Float() * (abBonus ? *g_kOCSettingBonus.Float() : 1.0f) * (OCDialogueRandom() % 5 + 1);

    if ((fFirst >= fSecond && fFirst > fThird2) || afValueA < afValueB * 0.5)
    {
        usResult6 = 2;
    }
    else if (fSecond > fFirst && fSecond > fThird2 && afValueA > afValueB * 1.5)
    {
        usResult6 = 1;
    }
    else
    {
        float fRoll = OCDialogueRandom() % 100;
        if (apActor->GetByteAt59() >= fRoll)
        {
            fRoll = OCDialogueRandom() % 100;
            if (fRoll <= 49.0)
            {
                if (!(ausFlags & 4))
                    usResult6 = 4;
            }
            else
            {
                if (!(ausFlags & 8))
                    usResult6 = 8;
            }
        }
    }
    return usResult6;
}

float CombatFormulas_CalcWeaponDamage(void*, int, float, float, int, int, int, bool);
// Computes weapon damage from condition and ammo, applies ammo effects and perk modifiers, and returns the result.
// @fnv 0x006450f0
float GetWeaponDamage(TESObjectWEAP* weapon, float condition, InventoryStackRecord* extra, TESAmmo* specifiedAmmo)
{
    float damage = 0.0f;
    damage = CombatDamageCalculator::CalculateWeaponDamage(
        static_cast<ActorValueOwner*>(g_thePlayer), weapon, condition, true, extra, false, false, -1,
        0.0f, 0.0f, false, false, specifiedAmmo);
    if (weapon && weapon->GetIsAutomaticWeapon() && TESObjectWEAP_IsMeleeWeapon(weapon))
    {
        ((CombatFormulaWeapon*)weapon)->SetFlag2(false);
        damage = CombatFormulas_CalcWeaponDamage(static_cast<ActorValueOwner*>(g_thePlayer), (int)weapon, condition, 1.0f, 0, 0,
                              (int)extra, specifiedAmmo != 0);
        ((CombatFormulaWeapon*)weapon)->SetFlag2(true);
    }
    else
    {
        damage = CombatFormulas_CalcWeaponDamage(static_cast<ActorValueOwner*>(g_thePlayer), (int)weapon, condition, 1.0f, 0, 0,
                              (int)extra, specifiedAmmo != 0);
    }
    TESAmmo* ammo = 0;
    if (weapon)
        ammo = specifiedAmmo ? specifiedAmmo : weapon->GetCurrentAmmo(g_thePlayer);
    if (!ammo)
        ammo = weapon->GetCurrentAmmo(0);
    if (ammo && weapon && (void*)ammo != (void*)weapon)
    {
        BSSimpleList<TESAmmoEffect*>* effects =
            ammo ? (BSSimpleList<TESAmmoEffect*>*)((TESAmmoInitCalls*)ammo)->TESAmmo_GetAmmoEffectList() : 0;
        damage = TESAmmoEffect::ApplyAmmoEffects(AMMO_EFFECT_TYPE_AMMO_EFFECT_DAM, effects, damage);
    }
    if (extra && extra->SetEquipmentState(12))
        damage = damage * 1.3;
    ApplyPerkModifiers(0, g_thePlayer, weapon, g_thePlayer, &damage);
    return damage;
}

// @fnv 0x00646d80
float __cdecl GetWeaponDPS(ActorValueOwner* pkOwner, TESObjectWEAP* pkWeapon)
{
    int iType = pkWeapon ? pkWeapon->GetWeaponType() : -1;
    float fShotRate = 1.0f;
    bool bAuto = false;

    if (pkWeapon && pkWeapon->GetIsAutomaticWeapon())
        fShotRate = reinterpret_cast<TESCreature*>(pkWeapon)->TESObjectWEAP_GetShotsPerSecond();
    if (fShotRate == 0.0)
        fShotRate = 1.0f;

    float fValue = pkOwner ? pkOwner->GetCurrentActorValue((ActorValue::Index)0xe) : 0.0f;
    float fDPS = fValue / fShotRate;
    if (pkWeapon && reinterpret_cast<Actor*>(pkWeapon)->ProcessActorAction() >= 0.0)
        fDPS *= reinterpret_cast<Actor*>(pkWeapon)->ProcessActorAction();
    return fDPS;
}

extern Setting DAT_011cf648;
extern Setting DAT_011cf654;
extern Setting DAT_011ce830;
extern Setting DAT_011cedd0;
extern Setting DAT_011cef38;
extern Setting DAT_011ce60c;
extern Setting DAT_011cf008;
extern Setting DAT_011cf068;
extern Setting DAT_011cf7f8;
extern Setting DAT_011ceb8c;
extern const double DAT_01012070;

float __cdecl FUN_00646800(ActorValueOwner* owner, int attribute, int unused);
float __cdecl CombatFormulas_GetWeaponStrengthRequirementModifier(unsigned int weaponType, unsigned int baseValue, unsigned int perkLevel);
float __cdecl ComputeScaledCount(int weaponCategory, int ownerValue, int mode);

// Computes a weapon damage modifier from actor perks, game settings, weapon type and category values, clamps it to a minimum and returns it.
// @fnv 0x00646910
float __cdecl ComputeWeaponDamageModifier(Actor* actor, TESObjectWEAP* weapon, void* unused, bool bypassDamage,
                                          bool bypassCritical, bool useEnergy, bool useUnarmed)
{
    float damageFactor_2 = 1.0f;
    float modifier4 = 0.0f;
    if (actor == reinterpret_cast<Actor*>(g_thePlayer))
    {
        ApplyPerkModifiers(0x36, reinterpret_cast<Actor*>(g_thePlayer), weapon, &damageFactor_2);
        if (damageFactor_2 < DAT_01012070)
        {
            damageFactor_2 = 1.0f;
        }
    }
    if (!bypassCritical)
        modifier4 += *DAT_011cf648.Float();
    if (useEnergy)
        modifier4 += *DAT_011cf654.Float() / damageFactor_2;
    else if (useUnarmed)
        modifier4 += *DAT_011ce830.Float() / damageFactor_2;
    if (!bypassDamage)
        modifier4 += *DAT_011cedd0.Float();

    float firstB = FUN_00646800(static_cast<ActorValueOwner*>(actor), 0x1b, 0);
    float second7 = FUN_00646800(static_cast<ActorValueOwner*>(actor), 0x1c, 0);
    float third3 = FUN_00646800(static_cast<ActorValueOwner*>(actor), 0x19, 0);
    if (actor->GetActorValue(static_cast<ActorValue::Index>(0x48)) == 0)
    {
        if (firstB == 0.0 && second7 == 0.0)
        {
            if (weapon->IsTwoHandedWeapon())
                modifier4 += *DAT_011cef38.Float();
            else
                modifier4 += *DAT_011ce60c.Float();
        }
        else if (firstB == 0.0 || second7 == 0.0)
        {
            if (weapon->IsTwoHandedWeapon())
                modifier4 += *DAT_011cf008.Float();
            else if (second7 == 0.0)
                modifier4 += *DAT_011cf068.Float();
        }
    }

    int baseValue_ = (unsigned int)(reinterpret_cast<ActorValueOwner*>((char*)actor + 0xa4)->GetActorValueFloatByIndex(5));
    float perkValue3 = 0.0f;
    Actor* perkActor = actor;
    ApplyPerkModifiers(0x35, perkActor, weapon, &perkValue3);
    int perkLevelB = (unsigned int)perkValue3;
    int weaponType7 = weapon->GetField19C();
    float weaponModifier4 = CombatFormulas_GetWeaponStrengthRequirementModifier(weaponType7, baseValue_, perkLevelB);
    modifier4 += weaponModifier4;

    int weaponCategoryX = weapon ? weapon->GetUnk15C() : 0x2d;
    float categoryValueB = reinterpret_cast<ActorValueOwner*>((char*)actor + 0xa4)->GetActorValueAsInteger(weaponCategoryX);
    int categoryLevel = (unsigned int)categoryValueB;
    int weaponClass2 = reinterpret_cast<CombatFormulaWeapon*>(weapon)->GetField1BC();
    float categoryModifier4 = ComputeScaledCount(weaponClass2, categoryLevel, 0);
    modifier4 += categoryModifier4;

    float multiplier7 = static_cast<float>(1.0 - categoryValueB * *DAT_011cf7f8.Float() * (double)0.01f);
    modifier4 *= multiplier7;
    if (modifier4 < *DAT_011ceb8c.Float())
        modifier4 = *DAT_011ceb8c.Float();
    return modifier4;
}

namespace fnv_00647870 {
float FUN_00476b20(float value);
void ClampUInt(unsigned* value, unsigned low, unsigned high);
extern Setting originalRuntimeFloatSetting583;
// @fnv 0x00647870
float ComputeScaledCount(unsigned first, unsigned second, unsigned third)
{
    unsigned count = 0;
    float amount_2 = 0.0f;
    if (second <= first)
    {
        amount_2 = static_cast<float>(first - second - third);
        amount_2 = FUN_00476b20(static_cast<float>(amount_2 / 10.0));
        count = static_cast<unsigned>(amount_2);
        ClampUInt(&count, 0, 10);
    }
    return static_cast<float>(static_cast<double>(count) * *originalRuntimeFloatSetting583.Setting_Float_00403e20());
}
}  // namespace fnv_00647870

namespace fnv_00644990 {
struct FUN_00644a30_shell
{
    unsigned char TESCombatStyle_GetDodgeChance();
};
struct FUN_00644a50_shell
{
    float TESCombatStyle_GetDodgeDuringAttackMult();
};
struct FUN_009a1260_Class
{
    float GetFloatAt0xC8();
};

// Computes a float from iLevel, fRatio, bFlag, and values returned by calls on pkActor.
// @fnv 0x00644990
// src: XBOX_PDB 0x00644990
float __cdecl CombatFormulas_ChooseDodge(void* pkActor, int iLevel, float fRatio, bool bFlag)
{
    float fBonus =
        iLevel * ((Actor*)pkActor)->PathingRequestCoveredMove_GetAttackerHealth() + ((Actor*)pkActor)->BSSceneGraph_GetCameraFOV();
    float fBase =
        (1.0f - fRatio) * ((Actor*)pkActor)->GetFieldB4Float() + ((TESForm*)pkActor)->GetFieldB8Float();
    float fResult = (char)((FUN_00644a30_shell*)pkActor)->TESCombatStyle_GetDodgeChance() + fBonus + fBase;
    fResult *=
        bFlag ? ((FUN_00644a50_shell*)pkActor)->TESCombatStyle_GetDodgeDuringAttackMult() : ((FUN_009a1260_Class*)pkActor)->GetFloatAt0xC8();
    return fResult;
}
}  // namespace fnv_00644990

extern Setting DAT_011cf044;
extern Setting DAT_011cec88;
extern Setting DAT_011cfdf0;
extern const double DAT_01012060;

// Combines setting values using a1 and a2, then sets the result to zero if it is below a global threshold.
// @fnv 0x00646660
// src: XBOX_PDB 0x00646660
float CombatFormulas_GetArrowGravity(float afLerp, float afScale)
{
    float fScale = afScale;
    float fAdjusted;
    float fResult;

    fAdjusted = *DAT_011cf044.Float() - fScale * *DAT_011cec88.Float();
    fResult = afLerp * fAdjusted + (1.0f - afLerp) * *DAT_011cfdf0.Float();
    if (fResult < DAT_01012060)
    {
        fResult = 0.0f;
    }
    return fResult;
}

// Returns true if m_cType is 2, 5, 6, 8, or 9, otherwise false.
// @fnv 0x00646cb0
// src: XBOX_PDB 0x00646cb0
bool TESObjectWEAP::IsTwoHandedWeapon()
{
    switch (data.eType)
    {
    case 2:
    case 5:
    case 6:
    case 8:
    case 9:
        return true;
    }
    return false;
}

struct FUN_00452370_shell
{
    bool TESForm_GetDestructible() const;
};

char __fastcall BGSBodyPart_GetToHitChance(const char*);
bool __fastcall TESObjectWEAP_IsMeleeWeapon(TESObjectWEAP*);
bool __fastcall TESObjectWEAP_IsThrownWeapon(TESObjectWEAP*);
bool __fastcall TESObjectWEAP_IsGunWeapon(TESObjectWEAP*);
float __cdecl tan_0057dd70(float);
float __cdecl CombatFormulas_GetArmCondition(ActorValueOwner*, int);

struct CombatDebugLog
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Log(int, int, const char*, ...);
};
typedef bool(__thiscall* RefBoolFn)(TESObjectREFR*);

extern Setting DAT_011cfab0;
extern Setting DAT_011cef80;
extern Setting DAT_011ced00;
extern Setting DAT_011cfba8;
extern Setting DAT_011cf068;
extern Setting DAT_011cf528;
extern Setting DAT_011ce99c;
extern Setting DAT_011cf8bc;
extern Setting DAT_011cfe08;
extern Setting DAT_011ceb20;
extern Setting DAT_011ce6fc;
extern Setting DAT_011cfe50;
extern Setting DAT_011cf504;
extern Setting DAT_011cf678;
extern Setting DAT_011cee54;
extern Setting DAT_011ce10c;
extern double DAT_01017a40;
extern const double DAT_01023128;
extern const float DAT_01016410;

// Computes the hit chance for a weapon attack on a target, applying range, spread, ammo, and stealth modifiers, and returns the final probability.
// @fnv 0x00646f70
float __cdecl GetHitChance(ActorValueOwner* m_pkAttacker, TESObjectREFR* pTarget, TESObjectWEAP* pWeapon,
                           void* unused14, void* unused18, float fSpreadBonus, const char* pAmmoName,
                           CombatFormulaWeapon* pWeaponMod, float fWeaponDamage, float afDistance, float fWeaponSpread,
                           CombatDebugLog* pLog)
{
    float fFinalVal = 0.0f;
    float fOutOdds = 0.0f;
    bool bDestTarget = pTarget ? (((FUN_00452370_shell*)pTarget)->TESForm_GetDestructible() && !pTarget->IsActor()) : false;
    bool bThrown = ((RefBoolFn)(*(void***)pTarget)[0x89])(pTarget);
    ActorValueOwner* pTargetAV = (pTarget && pTarget->IsActor()) ? (ActorValueOwner*)(Actor*)pTarget : 0;
    float fOutAmmoChance = 0.0f;
    if (pAmmoName)
    {
        fOutAmmoChance = (float)(unsigned char)BGSBodyPart_GetToHitChance(pAmmoName);
    }
    else if (pWeaponMod)
    {
        fOutAmmoChance = (float)pWeaponMod->GetBaseVATSChance(0);
    }
    else
    {
        fOutAmmoChance = 1.0f;
    }
    if (bThrown)
        fOutAmmoChance = 1.0f;
    if (pLog && (bDestTarget || bThrown))
    {
        pLog->Log(1, 3, "%s%s", bDestTarget ? "Destructible Target " : "", bThrown ? "Grenade Target" : "");
    }
    float fCurWeight = BSMIN(*DAT_011cfab0.Float(), 1.0f);
    float fConditionMultVal = fCurWeight * fWeaponDamage + (1.0f - fCurWeight);
    if (pWeapon && !TESObjectWEAP_IsMeleeWeapon(pWeapon))
    {
        if (((CombatFormulaWeapon*)pWeapon)->GetProjectileForOwner(m_pkAttacker) &&
            ((CombatFormulaWeapon*)pWeapon)->GetProjectileForOwner(m_pkAttacker)->GetExplosionProximity() != DAT_01012060)
        {
            if (pLog)
                pLog->Log(1, 3, "Target out of explosion range");
            return 0.0f;
        }
        if (TESObjectWEAP_IsThrownWeapon(pWeapon))
        {
            float fCurMaxRange = ((CombatFormulaWeapon*)pWeapon)->GetField124Float();
            if (fCurMaxRange * *DAT_011cef80.Float() < afDistance)
            {
                if (pLog)
                    pLog->Log(1, 3, "Target out of thrown weapon range");
                return 0.0f;
            }
            float fModRangeVal = fCurMaxRange * *DAT_011ced00.Float();
            float fGap = fModRangeVal - *DAT_011cfba8.Float();
            float fFalloff = 1.0f - BSMAX_00404010(afDistance - *DAT_011cfba8.Float(), 0.0f) / fGap;
            float fOutArmMult = CombatFormulas_GetArmCondition(m_pkAttacker, pWeapon ? pWeapon->FUN_00446390() : 0);
            if (fOutArmMult <= DAT_01012060)
            {
                fOutArmMult = 1.0f - *DAT_011cf068.Float();
            }
            else
            {
                fOutArmMult = 1.0f;
            }
            float fOutSkill =
                (m_pkAttacker->GetActorValueFloatByIndex(pWeapon->GetUnk15C()) *
                     *DAT_011cf528.Float() / DAT_01017a40 +
                 (1.0f - *DAT_011ce99c.Float())) *
                fOutArmMult;
            fOutOdds = *DAT_011cf8bc.Float() * (fFalloff + fOutSkill) * DAT_01017a40;
            if (pLog)
            {
                pLog->Log(1, 3, "mod max range: %.2f, range gap: %.2f, range odds: %.2f", (double)fModRangeVal,
                          (double)fGap, (double)fFalloff);
                pLog->Log(1, 3, "arm condition: %.2f, skill calc %.2f, final chance %.2f", (double)fOutArmMult,
                          (double)fOutSkill, (double)fOutOdds);
            }
        }
        else
        {
            if (TESObjectWEAP_IsGunWeapon(pWeapon) && ((CombatFormulaWeapon*)pWeapon)->IsFlag20Set() &&
                ((CombatFormulaWeapon*)pWeapon)->GetField124Float() < afDistance)
            {
                return 0.0f;
            }
            float fOutSpreadMult = 1.0f;
            if (TESObjectWEAP_IsGunWeapon(pWeapon))
            {
                fOutSpreadMult = ((CombatFormulaWeapon*)pWeapon)->GetSpread(false) + fSpreadBonus;
            }
            float fOutConeRadius = tan_0057dd70(fOutSpreadMult * *DAT_011cfe08.Float() * DAT_01023128) * afDistance;
            float fAreaVal = fOutConeRadius * fOutConeRadius * 3.1415927410125732;
            float fCurTargetArea = fWeaponSpread / 3.0 * fWeaponSpread;
            if (bThrown)
            {
                fCurTargetArea = *DAT_011ceb20.Float();
            }
            else
            {
                if (fOutConeRadius * 2.0f < fWeaponSpread)
                {
                    fCurTargetArea = (fOutConeRadius * 2.0f) / fWeaponSpread * fCurTargetArea;
                }
                if (bDestTarget)
                {
                    fCurTargetArea = fCurTargetArea * *DAT_011ce6fc.Float();
                }
            }
            float fAreaRatio = 0.0f;
            if (fAreaVal > DAT_01012060)
            {
                fAreaRatio = BSMIN(fCurTargetArea / fAreaVal, *DAT_011cfe50.Float());
            }
            fOutOdds = *DAT_011cf504.Float() * fConditionMultVal * fAreaRatio * fOutAmmoChance;
            if (pLog)
            {
                pLog->Log(1, 3, "bound size: %.2f, base chance: %.2f", (double)fWeaponSpread, (double)fOutAmmoChance);
                pLog->Log(1, 3, "spread factor: %.2f, radius %.2f, area %.2f", (double)fOutSpreadMult,
                          (double)fOutConeRadius, (double)fAreaVal);
                pLog->Log(1, 3, "target area: %.2f, range spread: %.2f, final chance: %.2f", (double)fCurTargetArea,
                          (double)fAreaRatio, (double)fOutOdds);
            }
        }
        if (bDestTarget || bThrown)
        {
            fOutOdds = fOutOdds * DAT_01017a40;
            if (fOutOdds > DAT_01012060 && fOutOdds < 1.0)
            {
                fOutOdds = 1.0f;
            }
            if (pLog)
                pLog->Log(1, 3, "destructible/grenade target chance: %.2f", (double)fOutOdds);
        }
    }
    else
    {
        if (afDistance <= *DAT_011cf678.Float())
        {
            if (pLog)
                pLog->Log(1, 3, "Melee weapon or unarmed assume 100%");
            fOutOdds = DAT_01016410;
        }
        else
        {
            if (pLog)
                pLog->Log(1, 3, "Melee weapon or unarmed -- out of range");
        }
    }
    if (pTargetAV && (pTargetAV->GetActorValue((ActorValue::Index)0x31) > 0 ||
                      m_pkAttacker->GetActorValue((ActorValue::Index)0x30) > 0))
    {
        if (pLog)
            pLog->Log(1, 3, "Stealth bonus: %f becomes %f", (double)fOutOdds,
                      (double)(fOutOdds * *DAT_011cee54.Float()));
        float fStealthBonus = 0.0f;
        ApplyPerkModifiers(0x45, (Actor*)g_thePlayer, &fStealthBonus);
        if (fStealthBonus <= DAT_01012060)
        {
            fOutOdds = fOutOdds * *DAT_011cee54.Float();
        }
    }
    fFinalVal = BSMIN(fOutOdds, *DAT_011ce10c.Float());
    return fFinalVal / DAT_01017a40;
}

struct DmgAmmo
{
    void* GetEffect();
};

struct DmgVATS
{
    bool IsActive();
};

struct DmgTimeGlobal
{
    float GetTimeMult();
};

float __cdecl DmgAmmoEffectMult(void* apEffect);

extern Setting g_kDmgBaseMult;
extern Setting g_kDmgSkillMultA;
extern Setting g_kDmgSkillMultB;
extern Setting g_kDmgConditionBase;
extern Setting g_kDmgConditionMult;
extern Actor* g_pDmgPlayer;
extern DmgVATS g_kDmgVATS;
extern DmgTimeGlobal g_kDmgTimeGlobal;
extern const float g_fDmgDefaultSkill;

// Computes total weapon damage from base, skill, ammo, condition, time and teammate multipliers, returning the final value.
// @fnv 0x00644ce0
// src: XBOX_PDB 0x00644ce0
float __cdecl CombatFormulas_CalcWeaponDamage(ActorValueOwner* apOwner, TESObjectWEAP* apWeapon, float afCondition, float afMult, int aiUnused,
                           bool abNoAmmo, InventoryStackRecord* apItem, bool abUseActor)
{
    int iSkillB = apWeapon ? apWeapon->GetUnk15C() : 0x2d;
    float fBaseDamage4 = *g_kDmgBaseMult.Float() * (apWeapon ? (float)apWeapon->GetAttackDamage() : 1.0f);
    float fBonus6 = 0.0f;
    if (apItem)
        apItem->SetEquipmentState(1, fBonus6);

    if (apWeapon)
    {
        switch (apWeapon->FUN_00446390())
        {
        case 1:
        case 2:
        case 13:
            if (apOwner)
                fBonus6 += apOwner->GetCurrentActorValue((ActorValue::Index)0x11);
            break;
        case -1:
        case 0:
            if (apOwner)
                fBonus6 += apOwner->GetCurrentActorValue((ActorValue::Index)0x38);
            break;
        }
    }
    else if (apOwner)
    {
        fBonus6 += apOwner->GetCurrentActorValue((ActorValue::Index)0x38);
    }

    float fSkillMultA = 1.0f;
    if (apOwner && (!apWeapon || TESObjectWEAP_IsMeleeWeapon(apWeapon)))
        fSkillMultA = CombatFormulas_GetArmCondition(apOwner, apWeapon ? apWeapon->FUN_00446390() : 0) * *g_kDmgSkillMultA.Float() +
                      *g_kDmgSkillMultB.Float();

    float _fSkill = apOwner ? apOwner->GetActorValueFloatByIndex((ActorValue::Index)iSkillB) : g_fDmgDefaultSkill;
    float fSkillDamage5 = fSkillMultA;
    if (apWeapon && apWeapon->FUN_00446390())
        fSkillDamage5 = *g_kDmgConditionBase.Float() + *g_kDmgConditionMult.Float() * (0.01f * _fSkill) * fSkillMultA;
    float kFDamage = fSkillDamage5 * afMult;

    float fAmmoBonus6 = 0.0f;
    if (!abNoAmmo && apWeapon && reinterpret_cast<DmgAmmo*>(
            static_cast<CombatFormulaWeapon*>(apWeapon)->GetProjectileForOwner(abUseActor ? apOwner : 0)) &&
        reinterpret_cast<DmgAmmo*>(
            static_cast<CombatFormulaWeapon*>(apWeapon)->GetProjectileForOwner(abUseActor ? apOwner : 0))->GetEffect())
    {
        fAmmoBonus6 = DmgAmmoEffectMult(reinterpret_cast<DmgAmmo*>(
            static_cast<CombatFormulaWeapon*>(apWeapon)->GetProjectileForOwner(abUseActor ? apOwner : 0))->GetEffect()) *
                      apWeapon->GetDamageForActor(apItem ? apItem->SetEquipmentState(0xc) : false, false,
                                                  abUseActor ? dynamic_cast<Actor*>(apOwner) : 0);
    }

    float fTimeMult3 = 1.0f;
    float fHealthMult3 = 1.0f;
    fHealthMult3 = GetWeaponHealthConditionMultiplier(afCondition);
    float fTeammateMult = 1.0f;
    Actor* pActor4 = dynamic_cast<Actor*>(apOwner);
    if (pActor4 && pActor4->IsPlayerTeammate())
    {
        float fPlayerLevel_ = g_pDmgPlayer->GetActorValueFloatByIndex((ActorValue::Index)8);
        fTeammateMult = 1.0 + fPlayerLevel_ * (double)0.05f;
    }
    if (apWeapon && apWeapon->GetIsAutomaticWeapon() && TESObjectWEAP_IsMeleeWeapon(apWeapon))
    {
        if (!g_kDmgVATS.IsActive() || pActor4 != g_pDmgPlayer)
            fTimeMult3 = g_kDmgTimeGlobal.GetTimeMult();
    }
    return ((fBaseDamage4 + fAmmoBonus6) * kFDamage + fBonus6) * fHealthMult3 * fTimeMult3 * fTeammateMult;
}
