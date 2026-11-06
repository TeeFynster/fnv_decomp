// Unit-private PC Projectile declaration. Public JohnnyGuitarNVSE supplies
// names and virtual order; JIP independently annotates the PC slots/layout.
// This declares real virtual destruction and contains no method bodies.
#ifndef FNV_PROCESSLISTS_PRIVATE_PROJECTILE_H
#define FNV_PROCESSLISTS_PRIVATE_PROJECTILE_H

#include "processlists_MobileObject.h"
#include "processlists_BSSoundHandle.h"
#include "processlists_impacts_math.h"

class Actor;
class ActorCause;
class InventoryStackRecord;
class NiLight;
class NiRefObject;
class ProjectileSupportData;
class TESObjectWEAP;
class hkpCollidable;

class Projectile : public MobileObject
{
  public:
    enum Type
    {
        UNKNOWN,
        BEAM,
        FLAME,
        GRENADE,
        MISSILE,
        CONTINUOUS_BEAM
    };
    struct ImpactData;

    virtual ~Projectile();
    virtual Type GetProjectileType() const;              // +0x304
    virtual void Initialize();                           // +0x308
    virtual void ResetProjectile();                      // +0x30C
    virtual void UpdateProjectile(float timeDelta);      // +0x310
    virtual bool ProcessProjectile();                    // +0x314; JIP calls this ProcessImpact
    virtual bool IsProjectileActive() const;             // +0x318
    virtual void UpdateProjectileState();                // +0x31C
    virtual bool OnActorHit(Actor* actor, bool silent);  // +0x320
    virtual bool GetCharacterSex() const;                // +0x324
    virtual bool IsProximityDetonationTriggered();       // +0x328
    virtual bool OnCollision(Actor* actor, const NiPoint3& contactPoint, const NiPoint3& contactNormal,
                             hkpCollidable* collidable, unsigned int collisionShapeKey,
                             unsigned int hitMaterial);  // +0x32C

    BSSimpleList<ImpactData*> kImpacts;
    bool m_bHasImpactData;
    NiTransform m_kImpactTransform;
    unsigned int iFlags;
    float m_fAlpha;
    float TransformFlagFloatData;
    float fImpulseRadiusSquared;
    float m_fFirstFloatValue;
    float afDamageAmount;
    float fAlpha;
    float AlphaFloatParameters;
    float AlphaParameterSet;
    float WeaponAlphaParameters;
    float WeaponReferenceParameterData;
    float m_fFourthRecordValue;
    TESObjectWEAP* pSourceWeapon;
    TESObjectREFR* WeaponHitData;
    TESObjectREFR* m_pMagicTarget;
    NiPoint3 kMovementDirection;
    float fDistanceMoveds;
    NiPointer<NiLight> m_pMenuLight;
    bool m_bFlagAfterLight;
    NiPointer<NiRefObject> m_pExplosionEffect;
    NiPointer<ActorCause> m_pActorCause;
    float m_fLifetime;
    BSSoundHandle kSound;
    BSSoundHandle kCountdownSound;
    ProjectileSupportData* pProjectileTarget;
    InventoryStackRecord* pRockItLauncherEntry;
    bool m_bHasTarget;
    float fSoundDistance;
};

FNV_STATIC_ASSERT(sizeof(Projectile::Type) == 4);
FNV_STATIC_ASSERT(sizeof(Projectile) == 0x150);
FNV_STATIC_ASSERT(offsetof(Projectile, kImpacts) == 0x88);
FNV_STATIC_ASSERT(offsetof(Projectile, m_bHasImpactData) == 0x90);
FNV_STATIC_ASSERT(offsetof(Projectile, m_kImpactTransform) == 0x94);
FNV_STATIC_ASSERT(offsetof(Projectile, iFlags) == 0xC8);
FNV_STATIC_ASSERT(offsetof(Projectile, m_fAlpha) == 0xCC);
FNV_STATIC_ASSERT(offsetof(Projectile, TransformFlagFloatData) == 0xD0);
FNV_STATIC_ASSERT(offsetof(Projectile, fImpulseRadiusSquared) == 0xD4);
FNV_STATIC_ASSERT(offsetof(Projectile, m_fFirstFloatValue) == 0xD8);
FNV_STATIC_ASSERT(offsetof(Projectile, afDamageAmount) == 0xDC);
FNV_STATIC_ASSERT(offsetof(Projectile, fAlpha) == 0xE0);
FNV_STATIC_ASSERT(offsetof(Projectile, AlphaFloatParameters) == 0xE4);
FNV_STATIC_ASSERT(offsetof(Projectile, AlphaParameterSet) == 0xE8);
FNV_STATIC_ASSERT(offsetof(Projectile, WeaponAlphaParameters) == 0xEC);
FNV_STATIC_ASSERT(offsetof(Projectile, WeaponReferenceParameterData) == 0xF0);
FNV_STATIC_ASSERT(offsetof(Projectile, m_fFourthRecordValue) == 0xF4);
FNV_STATIC_ASSERT(offsetof(Projectile, pSourceWeapon) == 0xF8);
FNV_STATIC_ASSERT(offsetof(Projectile, WeaponHitData) == 0xFC);
FNV_STATIC_ASSERT(offsetof(Projectile, m_pMagicTarget) == 0x100);
FNV_STATIC_ASSERT(offsetof(Projectile, kMovementDirection) == 0x104);
FNV_STATIC_ASSERT(offsetof(Projectile, fDistanceMoveds) == 0x110);
FNV_STATIC_ASSERT(offsetof(Projectile, m_pMenuLight) == 0x114);
FNV_STATIC_ASSERT(offsetof(Projectile, m_bFlagAfterLight) == 0x118);
FNV_STATIC_ASSERT(offsetof(Projectile, m_pExplosionEffect) == 0x11C);
FNV_STATIC_ASSERT(offsetof(Projectile, m_pActorCause) == 0x120);
FNV_STATIC_ASSERT(offsetof(Projectile, m_fLifetime) == 0x124);
FNV_STATIC_ASSERT(offsetof(Projectile, kSound) == 0x128);
FNV_STATIC_ASSERT(offsetof(Projectile, kCountdownSound) == 0x134);
FNV_STATIC_ASSERT(offsetof(Projectile, pProjectileTarget) == 0x140);
FNV_STATIC_ASSERT(offsetof(Projectile, pRockItLauncherEntry) == 0x144);
FNV_STATIC_ASSERT(offsetof(Projectile, m_bHasTarget) == 0x148);
FNV_STATIC_ASSERT(offsetof(Projectile, fSoundDistance) == 0x14C);
#endif
