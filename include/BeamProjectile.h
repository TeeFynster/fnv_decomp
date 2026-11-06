#pragma once

#include "Projectile.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NiGeometry;

class BeamProjectile : public Projectile
{
public:
    virtual ~BeamProjectile();
    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void Unk_21(BGSLoadFormBuffer* arg);
    virtual unsigned int GetProjectileType();
    virtual void Do3DLoaded();
    virtual void HandleTracer();
    virtual void UpdateProjectile(float timeDelta);
    virtual bool OnCollision(Actor* actor, const NiPoint3& contactPoint,
                             const NiPoint3& contactNormal, hkpCollidable* collidable,
                             unsigned int collisionShapeKey, unsigned int hitMaterial);

    void LoadProjectile(BGSLoadFormBuffer* apLoadGameBuffer);
    void SaveProjectile(BGSSaveFormBuffer* apSaveGameBuffer);
    void FUN_009b4cf0(BGSLoadFormBuffer* apLoadGameBuffer);
    void FUN_009abf10(BGSLoadFormBuffer* apLoadGameBuffer);
    void FUN_009bab00(BGSLoadFormBuffer* apLoadGameBuffer);
    void FUN_00979bb0(BGSSaveFormBuffer* apSaveGameBuffer);
    void FUN_009abef0(BGSLoadFormBuffer* apLoadGameBuffer);

    void FUN_00979140();
    void __thiscall FUN_00979280();
    unsigned char FUN_00979510(void* a1, void* a2, void* a3,
                              void* a4, void* a5, void* a6);
    void FUN_009795c0(float value);
    void FUN_009795e0(NiAVObject* apObject, float scale);
    float FUN_00979840(NiGeometry* arg);
    float FUN_00979840(NiAVObject* obj);
    void ScaleNode(NiAVObject* node, float fScale, float fDivisor);
};
