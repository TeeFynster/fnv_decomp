#pragma once

#include "Projectile.h"
#include "NiPoint3.h"

class BGSSaveFormBuffer;
class Collider890;

enum SEX;

class MissileProjectile : public Projectile
{
public:
    MissileProjectile(unsigned char a);
    MissileProjectile(int a, int b, int c, NiPoint3 position,
                      float magnitude, float duration);

    virtual ~MissileProjectile();
    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void Unk_21(BGSLoadFormBuffer* arg);
    virtual unsigned int GetProjectileType();
    virtual void Do3DLoaded();
    virtual void HandleTracer();
    virtual void UpdateProjectile(float timeDelta);
    virtual bool OnActorHit(Actor* actor, bool silent);
    virtual bool OnCollision(Actor* actor, const NiPoint3& contactPoint,
                             const NiPoint3& contactNormal, hkpCollidable* collidable,
                             unsigned int collisionShapeKey, unsigned int hitMaterial);

    void LoadProjectile(BGSLoadFormBuffer* buffer);
    void SaveProjectile(BGSSaveFormBuffer* buffer);
    SEX GetCharacterSex();

    void UpdateBeamFlags();
    void UpdateProjectileNodeVisibility();
    bool HandleContactResponse();
    void HandleMissileImpact();

    void* FUN_009b7a20(unsigned int flags);
    void FUN_009b7bc0();
    void UpdateProjectile_009b8030(float deltaTime);
    void AdvanceStateAtOffset150_009b8a20();
    bool AddImpact_009b8900(int arg1, int arg2, int arg3, Collider890* collider,
                      int arg5, int arg6);
    void ProcessImpale();
    void SaveGame_009baaa0(BGSLoadFormBuffer* buffer);
    void LoadGame_009baad0(BGSLoadFormBuffer* buffer);
    void RevertBGS_009bab70(BGSLoadFormBuffer* buffer);
    void Initialize3D();
    // called on a missile by 0x009b90b0; owner class and real names not yet known
    float Projectile_GetDistanceMoved();
    void Projectile_SetFlag(int a, int b);
    void FUN_008126e0(int a);
    void* Projectile_GetShooter();
    int MiddleHighProcess_GetCurrentFurniture();
    float Projectile_GetSpeed(NiPoint3* out, float f);
    NiPoint3* Projectile_GetMovementDirection(NiPoint3* out);
    void Projectile_Kill();
    void FUN_009bf470(int a, int b);

    // own state (0x160 per its allocations; cleared by both constructors, 0x150 saved and loaded)
    unsigned int uiImpactResult;   // 0x150: 3 and 4 are checked in impact handling
    bool bWaitingToInitialize3D;   // 0x154: checked together with the 3D
    float fUnk158;                 // 0x158
    float fUnk15C;                 // 0x15c
};
