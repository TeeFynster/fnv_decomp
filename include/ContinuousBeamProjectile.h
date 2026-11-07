#pragma once

#include "Projectile.h"
#include "AnimIdle.h"
#include "NiPoint3.h"

class EffectItem;
class EffectSetting;
class ProjectileEvent;
class ProjectileNodeStandin;

class ContinuousBeamProjectile : public Projectile
{
public:
    ContinuousBeamProjectile(bool bTempRef);
    virtual ~ContinuousBeamProjectile();
    virtual unsigned int GetProjectileType();
    virtual void Do3DLoaded();
    virtual void HandleTracer();
    virtual void UpdateProjectile(float timeDelta);
    virtual bool OnCollision(Actor* actor, const NiPoint3& contactPoint,
                             const NiPoint3& contactNormal, hkpCollidable* collidable,
                             unsigned int collisionShapeKey, unsigned int hitMaterial);

    NiAVObject* Root();
    NiPoint3* Position();
    void v310();

    int Initialize();
    void InitContinuousBeam();
    void UpdateAlignment();
    bool AddImpact_009ab9c0(void* arg1, NiPoint3* arg2, void* arg3,
                      void* arg4, void* arg5, void* arg6);
    bool ProcessHit(void* arg1, NiPoint3* arg2, void* arg3,
                    void* arg4, void* arg5, void* arg6);
    void MarkGeometryDataMutable(NiAVObject* object);
    void ScaleObject(NiAVObject* object, float scale);
    void fn_9ABD00_Recurse(NiAVObject* object, float scale, float previousScale);
    float FindBeamGeometryLength(NiAVObject* object);
    void* GetActorBase();
    bool Projectile_IsFlagSet(int flags);
    void Projectile_SetRange(float distance);
    void Projectile_SetFlag(int flag, int value);
    void Projectile_Initialize();
    Actor* Projectile_GetShooter();
    void Projectile_Kill();
    int GetArchetype();
    EffectItem* CombatController_GetCombatState();
    void TESObjectREFR_SetLocationOnReference(const NiPoint3*);
    void MagicProjectile_ApplyCollisionForce(NiPoint3, NiPoint3, unsigned int);
    ProjectileNodeStandin* FUN_009306d0();
    void* FUN_008d6f30();
    ProjectileEvent* FUN_009185e0();
    EffectSetting* GetAVEffect();
    void ApplyAreaEffect(NiPoint3 point, unsigned int variant,
                         TESObjectREFR* target, bool silent);

    NiPointer<AnimIdle> m_spUnk150;
};
