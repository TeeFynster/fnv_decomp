#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "TESDescription.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "MagicTarget.h"

class TESObjectLIGH;

class TESSound;
class TESEffectShader;

enum EffectArchetypes__ArchetypeID
{
    EffectArchetypes__ArchetypeID_ARCHETYPE_NONE = -1,
    EffectArchetypes__ArchetypeID_ARCHETYPE_START = 0,
    EffectArchetypes__ArchetypeID_VALUE_MODIFIER = 0,
    EffectArchetypes__ArchetypeID_SCRIPT = 1,
    EffectArchetypes__ArchetypeID_DISPEL = 2,
    EffectArchetypes__ArchetypeID_CURE_DISEASE = 3,
    EffectArchetypes__ArchetypeID_ABSORB = 4,
    EffectArchetypes__ArchetypeID_SHIELD = 5,
    EffectArchetypes__ArchetypeID_CALM = 6,
    EffectArchetypes__ArchetypeID_DEMORALIZE = 7,
    EffectArchetypes__ArchetypeID_FRENZY = 8,
    EffectArchetypes__ArchetypeID_COMMAND_CREATURE = 9,
    EffectArchetypes__ArchetypeID_COMMAND_HUMANOID = 10,
    EffectArchetypes__ArchetypeID_INVISIBILITY = 11,
    EffectArchetypes__ArchetypeID_CHAMELEON = 12,
    EffectArchetypes__ArchetypeID_LIGHT = 13,
    EffectArchetypes__ArchetypeID_DARKNESS = 14,
    EffectArchetypes__ArchetypeID_NIGHT_EYE = 15,
    EffectArchetypes__ArchetypeID_LOCK = 16,
    EffectArchetypes__ArchetypeID_OPEN = 17,
    EffectArchetypes__ArchetypeID_BOUND_ITEM = 18,
    EffectArchetypes__ArchetypeID_SUMMON_CREATURE = 19,
    EffectArchetypes__ArchetypeID_DETECT_LIFE = 20,
    EffectArchetypes__ArchetypeID_TELEKINESIS = 21,
    EffectArchetypes__ArchetypeID_DISINTEGRATE_ARMOR = 22,
    EffectArchetypes__ArchetypeID_DISINTEGRATE_WEAPON = 23,
    EffectArchetypes__ArchetypeID_PARALYZE = 24,
    EffectArchetypes__ArchetypeID_REANIMATE = 25,
    EffectArchetypes__ArchetypeID_SOUL_TRAP = 26,
    EffectArchetypes__ArchetypeID_TURN_UNDEAD = 27,
    EffectArchetypes__ArchetypeID_SUN_DAMAGE = 28,
    EffectArchetypes__ArchetypeID_VAMPIRISM = 29,
    EffectArchetypes__ArchetypeID_CURE_PARALYSIS = 30,
    EffectArchetypes__ArchetypeID_CURE_ADDICTION = 31,
    EffectArchetypes__ArchetypeID_CURE_POISON = 32,
    EffectArchetypes__ArchetypeID_CONCUSSION = 33,
    EffectArchetypes__ArchetypeID_VALUE_AND_PARTS = 34,
    EffectArchetypes__ArchetypeID_LIMB_CONDITION = 35,
    EffectArchetypes__ArchetypeID_TURBO = 36,
    EffectArchetypes__ArchetypeID_ARCHETYPE_COUNT = 37
};

class EffectSetting__EffectSettingData
{
  public:
    unsigned int iFlags;
    float m_fBaseCost;
    TESForm* m_pAssociatedForm;
    int m_iAssociatedSkill;
    int m_iResistanceActorValue;
    short m_sCounterEffectCount;
    unsigned char unk16[2];
    TESObjectLIGH* apTargetLight;
    float fSpeed;
    TESEffectShader* m_pEffectShader;
    TESEffectShader* m_pEnchantEffectShader;
    TESSound* m_pCastSound;
    TESSound* m_pBoltSound;
    TESSound* m_pContactSound;
    TESSound* m_pAreaEffectSound;
    float m_fEnchantmentFactor;
    float m_fBarterFactor;
    EffectArchetypes__ArchetypeID m_eEffectTypeItem;
    int m_iAssociatedActorValue;
    void Endian();
};

class EffectSetting : public TESForm, public TESModel, public TESDescription, public TESFullName, public TESIcon
{
public:
    typedef EffectSetting__EffectSettingData EndianSwappableData;

    enum EffectFlag
    {
        PLAYER_KNOWS = 0x200000
    };

    bool (__cdecl* m_pEffectSettingCallback)(EffectSetting*, void*);
    void* m_pPredicateData;
    EffectSetting__EffectSettingData data;
    BSSimpleList<EffectSetting*> counterEffects;
    int m_iActorValue;
    int m_iEffectID;

    EffectSetting();
    virtual ~EffectSetting();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual void InitItem();

    bool Load(TESFile* file);
    void UpdateEffectName(const char* name);
    BSStringT<char> GetEffectName() const;
    bool HasEffectID();
    int GetEffectID();
    void SetEffectID(int value);
    bool IsScriptEffect();
    bool IsDetrimental();
    bool IsAssociatedActorValueUsed();
    bool HasAssociatedActorValue();
    int GetAssociatedActorValue();
    void SetAssociatedActorValue(int value);
    bool IsModelLoaded();
    bool HasFlag2();
    int UpdateCounter();
    void* TESDataHandler_GetRecipes();
    TESEffectShader* GetEffectShader_00407820();
    bool UsesAssociatedActorValue();
    bool HasNoAssociatedActorValue();
    bool IsAssociatedFormUsed();
    bool GetFlag(unsigned int flags) const;
    void SetFlag(EffectFlag flag, bool value);
    int GetArchetype();
    bool IsFlagSet(unsigned int flag);
    bool HasAllFlags(unsigned int flags);
    bool IsDetrimentalToActorValue(int actorValue);
    ::TESObjectLIGH* GetLight();
    void SetLight(::TESObjectLIGH* light);
    TESSound* GetCastSound();
    EffectSetting* GetCastSound() const;
    void SetCastSound(TESSound* sound);
    TESSound* GetBoltSound();
    void SetBoltSound(TESSound* sound);
    TESSound* GetHitSound();
    void SetHitSound(TESSound* sound);
    TESSound* GetAreaSound();
    void SetAreaSound(TESSound* sound);
    TESEffectShader* GetEffectShader();
    void SetEffectShader(TESEffectShader* shader);
    TESEffectShader* GetEnchantEffectShader();
    void SetEnchantEffectShader(TESEffectShader* shader);
    int QueueAssociatedItem();
    int NormalizeEffectLoadedCount();
    void SaveAlt();
    int IncEffectLoadedCount();
    bool FUN_007df1b0();
    bool IsFlagSet_00403e60(unsigned int flags);
    void BSShaderProperty_SetDepthBias(float value);
    int FUN_004087e0();
    int FUN_004089c0();
    TESForm* FUN_005f5f80();
};
