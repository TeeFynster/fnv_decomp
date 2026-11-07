#pragma once

#include "TESForm.h"
#include "EffectShaderData.h"
#include "TESTexture.h"
#include "BSShaderPPLightingProperty.h"

class BGSDebris;
class TESTexture;
class NiAVObject;
class NiSourceTexture;
class ParticleShaderProperty;

class TESEffectShader : public TESForm
{
public:
    EffectShaderData Data;
    TESTexture m_kFillTexture;
    TESTexture m_kParticleShaderTexture;
    TESTexture m_kHolesTexture;

    TESEffectShader();
    virtual ~TESEffectShader();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual void InitItem(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    EffectShaderData* GetData();
    BGSDebris* GetAddonModels();
    void SetAddonModels(BGSDebris* models);

    bool IsFlagSet_00507040(unsigned int);
    float NiAVObject_GetWorldScale();
    float Explosion_GetRadius();
    float TESEffectShader_GetAddOnScaleStart();

    TESTexture* GetFieldAt14C();
    TESTexture* GetFieldAt158();
    TESTexture* GetFieldAt164();
    void CopySettingsTo(ParticleShaderProperty*, NiSourceTexture*);
    ParticleShaderProperty* CreateParticleShaderProperty(
        NiAVObject*, NiAVObject*, NiSourceTexture*, float);
    void StopParticleShader(NiAVObject*, ParticleShaderProperty*);
    BSShaderPPLightingProperty::TextureEffectData* CreateEffectData(
        NiAVObject*, NiSourceTexture*, NiSourceTexture*);
    void ApplyShaderToTree(NiAVObject*, BSShaderPPLightingProperty::TextureEffectData*);
};
