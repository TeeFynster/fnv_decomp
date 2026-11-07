#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModel.h"
#include "BGSPreloadable.h"
#include "BGSDestructibleObjectForm.h"
#include "ProjectileProperties.h"
#include "BaseProcess.h"

class SoundObj;
class TESFile;

class BGSProjectile : public TESBoundObject,
                      public TESFullName,
                      public TESModel,
                      public BGSPreloadable,
                      public BGSDestructibleObjectForm
{
public:
    class Properties : public ProjectileProperties
    {
    public:
        Properties();
    };

    Properties Data;
    TESModel m_kProjectileModel;
    SOUND_LEVEL m_eSoundLevel;

    BGSProjectile();
    virtual ~BGSProjectile();

    virtual void ClearData();
    virtual void InitItem();

    void ResetFormData();
    bool Load(TESFile* file);
    bool GetHasExplosion();
    bool GetFlag(unsigned int flag) const;
    bool GetHasExplosionDetonates() const;
    bool GetHasExplosionAltTrigger() const;
    float GetExplosionProximity() const;
    float GetFloatAtOffset68();
    float GetFloatAtOffsetB0();
    bool IsFlag200Set() const;
    SoundObj* FUN_004fd3e0();
    bool FUN_00975300();
    float FUN_0045cd80();
    bool GetHasExplosionDetonates_005de080();
    bool GetCanTurnOff() const;
    bool GetHasRotation();
    bool GetSupersonic();
    bool GetCanPickup();
    bool GetHitScan() const;
    float GetGravity_00966980();
    float FUN_009a7c40();
    BGSProjectile* _FNV_GetObjectReference();
    int _FNV_GetFormType();

};
