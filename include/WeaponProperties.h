#pragma once

class BGSProjectile;

enum WEAPONHITBEHAVIOR;
enum WEAPON_RUMBLE_PATTERN;
enum WEAPON_MOD_EFFECT;

namespace ActorValue
{
    enum Index;
}

typedef ActorValue::Index ActorValue__Index;

class WeaponProperties
{
public:
    char eType;
    unsigned char layoutPadding1[3];
    float fSpeed;
    float ActorTypeValueEntry;
    unsigned char cFlags;
    unsigned char m_ucGripAnimation;
    unsigned char m_ucAmmoUse;
    unsigned char m_ucReloadAnimation;
    float m_fMinimumSpread;
    float fBodyPartChance;
    float m_fUnknownFloat;
    float AmmunitionData;
    unsigned char m_ucSubtype;
    unsigned char layoutPadding21[3];
    BGSProjectile* pProjectile;
    unsigned char m_ucBaseVATSChance;
    unsigned char m_ucAttackAnimation;
    unsigned char m_ucProjectileCount;
    unsigned char m_ucFourthByte;
    float m_fMinimumRange;
    float m_fMaximumRange;
    WEAPONHITBEHAVIOR m_eHitBehavior;
    unsigned int WeaponAttackData;
    float m_fAnimationAttackMultiplier;
    float fWeaponDamageMultiplier;
    float m_fOverrideActionPoints;
    float m_fLeftRumbleMotorStrength;
    float m_fRightRumbleMotorStrength;
    float m_fRumbleDuration;
    float m_fOverrideDamageToWeaponMultiplier;
    float m_fAttackShotsPerSecond;
    float WeaponCombatData;
    float WeaponHandlingData;
    float WeaponFiringData;
    ActorValue__Index m_eWeaponSkill;
    WEAPON_RUMBLE_PATTERN m_eRumblePattern;
    float WeaponFiringParameters;
    float m_fLimbDamageMultiplier;
    ActorValue__Index m_eResistanceType;
    float m_fSightUsage;
    float m_fMinimumSemiAutomaticFireDelay;
    float m_fMaximumSemiAutomaticFireDelay;
    float m_fFourthModifierValue;
    WEAPON_MOD_EFFECT m_eFirstWeaponModEffect;
    WEAPON_MOD_EFFECT m_eSecondWeaponModEffect;
    WEAPON_MOD_EFFECT m_eThirdWeaponModEffect;
    float m_fModValueA1;
    float m_fModValueA2;
    float m_fModValueA3;
    unsigned char m_ucPowerAttackAnimationOverride;
    unsigned char layoutPaddingA5[3];
    unsigned int m_uiStrengthRequirement;
    char m_cUnknownByte;
    char m_cReloadAnimationMod;
    unsigned char layoutPaddingAE[2];
    float FlaggedFloatData;
    float m_fKillImpulse;
    float m_fModValueB1;
    float m_fModValueB2;
    float m_fModValueB3;
    float FourFloatsAndUnsignedInteger;
    unsigned int m_uiSkillRequirement;

    void Endian();
};
