#pragma once

#include "MobileObject.h"
#include "MagicTarget.h"
#include "NiAVObject.h"
#include "NiPoint3.h"
#include "BSSoundHandle.h"

class ActorCause;
class Cell;
class Proj;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NiLight;
class NonActorMagicCaster;
class TESObjectWEAP;
class bhkSimpleShapePhantom;

class Explosion : public MobileObject
{
public:
    struct ExplosionParameters;

    Explosion();
    virtual ~Explosion();
    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void Unk_21(BGSLoadFormBuffer* arg);
    virtual void Update(float delta);
    virtual void Initialize();

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

    float GetEffectiveValue();
    int* FindEntryResultByCategory(int category);

    bool IsNotCulled();
    float Explosion_GetRadius();
    Proj* FUN_004181e0();
    NiPoint3* FUN_00430830();
    Cell* FUN_008d6f30();
    float BGSProjectile_GetMuzzleFlashDuration();
    void bhkCharacterControllerCinfo_SetAcrobatics(float a);

    void ApplyBlastEffects();
    void* Destroy(unsigned int flags);

    void WriteToSaveBuffer(BGSSaveFormBuffer* buffer);
    void LoadGame_009b22c0(BGSLoadFormBuffer* apLoadGameBuffer);
    void InitLoadGame_009b25b0(void* apBuffer);
    void FinishLoadGame_009b2770(BGSLoadFormBuffer* apLoadGameBuffer);
    void RevertBGS_009b2790(BGSLoadFormBuffer* apBuffer);

    void ProcessMovement(float afDelta);
    void Update3D(int iUnused);
    void UpdateExplosion();
    void UpdateCastSound();
    void Explosion_TestExplosionUnderWater();
    void Init3D();
    void Explosion_AttachDistant();
    void Explosion_UpdateRadiation();
    unsigned int QUserData();
    void StartSounds();
    unsigned char GetByteAtOffsetD9();
    void SetActorCause_009ac170(ActorCause* apActorCause);
};
