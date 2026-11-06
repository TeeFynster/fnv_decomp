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
    bool FUN_009ab9c0(void* arg1, NiPoint3* arg2, void* arg3,
                      void* arg4, void* arg5, void* arg6);
    bool ProcessHit(void* arg1, NiPoint3* arg2, void* arg3,
                    void* arg4, void* arg5, void* arg6);
    void MarkGeometryDataMutable(NiAVObject* object);
    void ScaleObject(NiAVObject* object, float scale);
    void FUN_009abd00(NiAVObject* object, float scale, float previousScale);
    float FUN_00979840(NiAVObject* object);
    void* GetActorBase();
    bool FUN_00444d00(int flags);
    void FUN_009795c0(float distance);
    void FUN_005de0a0(int flag, int value);
    void FUN_009bda10();
    Actor* FUN_00874480();
    void FUN_009bc8f0();
    int GetArchetype();
    EffectItem* FUN_00586150();
    void FUN_00575830(const NiPoint3*);
    void FUN_0081f000(NiPoint3, NiPoint3, unsigned int);
    ProjectileNodeStandin* FUN_009306d0();
    void* FUN_008d6f30();
    ProjectileEvent* FUN_009185e0();
    EffectSetting* FUN_004fd400();
    void ApplyAreaEffect(NiPoint3 point, unsigned int variant,
                         TESObjectREFR* target, bool silent);

    NiPointer<AnimIdle> m_spUnk150;
};
