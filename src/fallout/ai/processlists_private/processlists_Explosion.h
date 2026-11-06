// Unit-private PC Explosion declaration. Public layout facts and real virtual
// declarations only. ApplyBlastEffects is the supplied pack's actual candidate.
#ifndef FNV_PROCESSLISTS_PRIVATE_EXPLOSION_H
#define FNV_PROCESSLISTS_PRIVATE_EXPLOSION_H

#include "processlists_MobileObject.h"
#include "processlists_BSSoundHandle.h"
#include "processlists_NiPoint3.h"

class ActorCause;
class NiLight;
class NonActorMagicCaster;
class TESObjectWEAP;
class bhkSimpleShapePhantom;

class Explosion : public MobileObject
{
  public:
    struct ExplosionParameters;

    virtual ~Explosion();
    virtual void Initialize();  // +0x304

    float m_fFirstFloatValue;
    float f3DLifetime;
    float fInnerRadius;
    float fOuterRadius;
    float ExplosionRuntimeData;
    float m_fFourthRecordValue;
    NiPointer<bhkSimpleShapePhantom> m_pExplosionPhantom;
    BSSimpleList<ExplosionParameters*> kTargets;
    BSSoundHandle kSoundHandles[2];
    NiPointer<NiLight> m_pMenuLight;
    TESObjectREFR* pOwnerRef;
    TESObjectREFR* ReferenceSoundCauseData;
    NiPointer<ActorCause> m_pActorCause;
    bool ReferenceCauseInfo;
    bool m_bFlagD5;
    bool m_bFlagD6;
    bool m_bFlagD7;
    bool MagicWeaponState;
    bool bUnderwater;
    NonActorMagicCaster* m_pEffectInstance;
    TESObjectWEAP* m_pFiringWeapon;
    int m_iValueE4;
    NiPoint3 kClosestPoint;
    NiPoint3 kClosestPointNormal;
    float m_fClosestPointScalar;

    void ApplyBlastEffects();  // PC 009AE6E0, supplied candidate identity
};

FNV_STATIC_ASSERT(sizeof(Explosion) == 0x104);
FNV_STATIC_ASSERT(offsetof(Explosion, m_fFirstFloatValue) == 0x88);
FNV_STATIC_ASSERT(offsetof(Explosion, f3DLifetime) == 0x8C);
FNV_STATIC_ASSERT(offsetof(Explosion, fInnerRadius) == 0x90);
FNV_STATIC_ASSERT(offsetof(Explosion, fOuterRadius) == 0x94);
FNV_STATIC_ASSERT(offsetof(Explosion, ExplosionRuntimeData) == 0x98);
FNV_STATIC_ASSERT(offsetof(Explosion, m_fFourthRecordValue) == 0x9C);
FNV_STATIC_ASSERT(offsetof(Explosion, m_pExplosionPhantom) == 0xA0);
FNV_STATIC_ASSERT(offsetof(Explosion, kTargets) == 0xA4);
FNV_STATIC_ASSERT(offsetof(Explosion, kSoundHandles) == 0xAC);
FNV_STATIC_ASSERT(offsetof(Explosion, m_pMenuLight) == 0xC4);
FNV_STATIC_ASSERT(offsetof(Explosion, pOwnerRef) == 0xC8);
FNV_STATIC_ASSERT(offsetof(Explosion, ReferenceSoundCauseData) == 0xCC);
FNV_STATIC_ASSERT(offsetof(Explosion, m_pActorCause) == 0xD0);
FNV_STATIC_ASSERT(offsetof(Explosion, ReferenceCauseInfo) == 0xD4);
FNV_STATIC_ASSERT(offsetof(Explosion, m_bFlagD5) == 0xD5);
FNV_STATIC_ASSERT(offsetof(Explosion, m_bFlagD6) == 0xD6);
FNV_STATIC_ASSERT(offsetof(Explosion, m_bFlagD7) == 0xD7);
FNV_STATIC_ASSERT(offsetof(Explosion, MagicWeaponState) == 0xD8);
FNV_STATIC_ASSERT(offsetof(Explosion, bUnderwater) == 0xD9);
FNV_STATIC_ASSERT(offsetof(Explosion, m_pEffectInstance) == 0xDC);
FNV_STATIC_ASSERT(offsetof(Explosion, m_pFiringWeapon) == 0xE0);
FNV_STATIC_ASSERT(offsetof(Explosion, m_iValueE4) == 0xE4);
FNV_STATIC_ASSERT(offsetof(Explosion, kClosestPoint) == 0xE8);
FNV_STATIC_ASSERT(offsetof(Explosion, kClosestPointNormal) == 0xF4);
FNV_STATIC_ASSERT(offsetof(Explosion, m_fClosestPointScalar) == 0x100);
#endif
