#pragma once

#include <stddef.h>
#include "MagicHitEffect.h"
#include "BSSimpleArray.h"
#include "NiAVObject.h"
template <class T> class NiTPrimitiveArray;

#include "BSShaderPPLightingProperty.h"

class TESBoundObject;
class TESEffectShader;
class ParticleShaderProperty;
class ShaderHitTarget;
class BGSSaveFormBuffer;

class MagicShaderHitEffect : public MagicHitEffect
{
  public:
    MagicShaderHitEffect(TESObjectREFR* apTarget, ActiveEffect* apEffect);
    MagicShaderHitEffect(TESObjectREFR* apTarget, TESEffectShader* apShader, float afDuration);
    ~MagicShaderHitEffect();

    bool Update(float afTime);
    int GetType();
    bool IsSaveable();
    void SaveGame();
    void SaveGame(BGSSaveGameBuffer* apBuffer);
    bool LoadGame();
    void LoadGame(BGSLoadGameBuffer* apBuffer);
    void InitLoadGame(BGSLoadGameBuffer* apBuffer);
    void ApplyLoadBuffer(BGSLoadGameBuffer* apBuffer);
    bool Init();
    void AttachToTarget();
    unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    void SaveGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    void LoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    void InitLoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    void FinishLoadGameTES(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData);

    void ApplyAndCleanup();
    unsigned short GetEffectSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    unsigned short FUN_00822060();
    bool FUN_00822010();
    void FUN_008220c0();
    bool FUN_00822130();
    void FUN_00821e40(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    void FUN_00821ed0(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    void FUN_00822250(BGSSaveFormBuffer* apBuffer);
    void FUN_008222f0(BGSLoadGameBuffer* apBuffer);
    void FUN_008223d0(unsigned int a1);

    ActiveEffect* GetEffect();
    void GetSceneGraphData(bool&, bool&, float&, NiAVObject*&, NiAVObject*&);
    void FUN_008d05e0(ActiveEffect*, TESObjectREFR*, void*);
    void InitHitEffect(ActiveEffect*, TESObjectREFR*, void*);
    ShaderHitTarget* GetHitTarget();
    float GetTimeLeft();
    void Finish();

    bool m_bUseActorParticleEffects;
    unsigned char unk29[3];
    TESBoundObject* m_pAffectedArmorObject;
    TESEffectShader* m_pEffectShader;
    float m_fEffectShaderScale;
    BSSimpleArray<NiPointer<ParticleShaderProperty> > m_kParticleShaderProperties;
    NiPointer<NiNode> m_pParticleShaderNode;
    bool b3rdPerson;
    unsigned char unk4D[3];
    BSSimpleArray<NiPointer<NiAVObject> > m_kAddonModelObjects;
    float m_fAddonModelTimer;
    float m_fAddonModelScale;
    NiPointer<BSShaderPPLightingProperty::TextureEffectData> spTexEffectData;
};

typedef char MagicShaderHitEffect_actor_particles_offset[
    offsetof(MagicShaderHitEffect, m_bUseActorParticleEffects) == 0x28 ? 1 : -1];
typedef char MagicShaderHitEffect_armor_offset[
    offsetof(MagicShaderHitEffect, m_pAffectedArmorObject) == 0x2C ? 1 : -1];
typedef char MagicShaderHitEffect_shader_offset[
    offsetof(MagicShaderHitEffect, m_pEffectShader) == 0x30 ? 1 : -1];
typedef char MagicShaderHitEffect_shader_scale_offset[
    offsetof(MagicShaderHitEffect, m_fEffectShaderScale) == 0x34 ? 1 : -1];
typedef char MagicShaderHitEffect_particle_properties_offset[
    offsetof(MagicShaderHitEffect, m_kParticleShaderProperties) == 0x38 ? 1 : -1];
typedef char MagicShaderHitEffect_particle_node_offset[
    offsetof(MagicShaderHitEffect, m_pParticleShaderNode) == 0x48 ? 1 : -1];
typedef char MagicShaderHitEffect_third_person_offset[
    offsetof(MagicShaderHitEffect, b3rdPerson) == 0x4C ? 1 : -1];
typedef char MagicShaderHitEffect_addon_objects_offset[
    offsetof(MagicShaderHitEffect, m_kAddonModelObjects) == 0x50 ? 1 : -1];
typedef char MagicShaderHitEffect_addon_timer_offset[
    offsetof(MagicShaderHitEffect, m_fAddonModelTimer) == 0x60 ? 1 : -1];
typedef char MagicShaderHitEffect_addon_scale_offset[
    offsetof(MagicShaderHitEffect, m_fAddonModelScale) == 0x64 ? 1 : -1];
typedef char MagicShaderHitEffect_texture_effect_offset[
    offsetof(MagicShaderHitEffect, spTexEffectData) == 0x68 ? 1 : -1];
