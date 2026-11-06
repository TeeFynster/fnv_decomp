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
    float FUN_00644930();
    Proj* FUN_004181e0();
    NiPoint3* FUN_00430830();
    Cell* FUN_008d6f30();
    float FUN_00507e10();
    void FUN_00810550(float a);

    void ApplyBlastEffects();
    void* Destroy(unsigned int flags);

    void WriteToSaveBuffer(BGSSaveFormBuffer* buffer);
    void FUN_009b22c0(BGSLoadFormBuffer* apLoadGameBuffer);
    void FUN_009b25b0(void* apBuffer);
    void FUN_009b2770(BGSLoadFormBuffer* apLoadGameBuffer);
    void FUN_009b2790(BGSLoadFormBuffer* apBuffer);

    void FUN_009ae580(float afDelta);
    void Update3D(int iUnused);
    void UpdateExplosion();
    void UpdateCastSound();
    void FUN_009b2940();
    void FUN_009ad670();
    void FUN_009acd00();
    void FUN_009b13a0();
    unsigned int FUN_009ad610();
    void FUN_009b1090();
    unsigned char GetByteAtOffsetD9();
    void FUN_009ac170(ActorCause* apActorCause);
};
