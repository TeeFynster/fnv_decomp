#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModel.h"
#include "TESEnchantableForm.h"
#include "BGSPreloadable.h"
#include "TESImageSpaceModifiableForm.h"
#include "ExplosionEffectSettings.h"

class BGSImpactDataSet;
class TESFile;
class TESSound;

class BGSExplosion : public TESBoundObject,
                     public TESFullName,
                     public TESModel,
                     public TESEnchantableForm,
                     public BGSPreloadable,
                     public TESImageSpaceModifiableForm
{
public:
    BGSExplosion();
    virtual ~BGSExplosion();

    virtual void InitItem();

    void ResetFormData();
    bool Load(TESFile* file);
    // TESForm vtable slot 8 (vftable 0x1024a94 slot 8 = 0x4fb0d0)
    bool LoadForm(TESFile* file);
    float __thiscall GetScaledValue();
    ExplosionEffectSettings* GetData_004fadc0();
    BGSImpactDataSet* BGSExplosion_GetImpactDataSet();
    void SetImpactDataSet_004fb0b0(BGSImpactDataSet* value);
    void FUN_004febf0(TESSound* value);
    ExplosionEffectSettings* GetExplosionData();
    BGSImpactDataSet* GetImpactDataSet();
    void SetImpactDataSet(BGSImpactDataSet* value);
    void SetSecondaryImpactSound(TESSound* value);

    TESBoundObject* m_pExplosionBoundObject;
    ExplosionEffectSettings Data;
};
