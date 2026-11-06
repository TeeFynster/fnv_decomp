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
    bool FUN_004fd360();
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
    bool FUN_005de080();
    bool FUN_004fdf20() const;
    bool FUN_009b88e0();
    bool FUN_009bc870();
    bool FUN_004fdf40();
    bool FUN_009a7f80() const;
    float FUN_00966980();
    float FUN_009a7c40();
    BGSProjectile* _FNV_GetObjectReference();
    int _FNV_GetFormType();

};
