#pragma once

class TESObjectLIGH;
class BGSExplosion;
class TESSound;
class TESObjectWEAP;

class ProjectileProperties
{
public:
    unsigned int iFlags;
    float afGravity;
    float fSpeed;
    float fImpulseRadiusSquared;
    TESObjectLIGH* apTargetLight;
    TESObjectLIGH* m_pSecondLight;
    float ExplosionLightingData;
    float LightExplosionSoundData;
    float AlphaFloatParameters;
    BGSExplosion* ExplosionFadeData;
    TESSound* m_pExplosionSound;
    float ExplosionEffectRecord;
    float fFadeOutTime;
    float fForce;
    TESSound* m_pFirstSound;
    TESSound* m_pSecondSound;
    TESObjectWEAP* m_pProjectileWeapon;
    float ProjectileWeaponDataWithTwoSounds;
    float ProjectileWeaponDataWithOneSound;
    float ProjectileWeaponData;
    float m_fFourthProjectileValue;

    void Endian();
    void InitializeDefaults();
};
