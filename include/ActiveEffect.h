#pragma once

#include "BSSoundHandle.h"

class Actor;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class EffectItem;
class EffectSetting;
class MagicCaster;
class MagicHitEffect;
class MagicItem;
class MagicTarget;
class TESBoundObject;
template <class T> class BSSimpleList;

enum MagicSystem__SpellType
{
    MagicSystem__SpellType_SPELL = 0,
    MagicSystem__SpellType_DISEASE = 1,
    MagicSystem__SpellType_POWER = 2,
    MagicSystem__SpellType_LESSER_POWER = 3,
    MagicSystem__SpellType_ABILITY = 4,
    MagicSystem__SpellType_POISON = 5,
    MagicSystem__SpellType_ENCHANTMENT = 6,
    MagicSystem__SpellType_POTION = 7,
    MagicSystem__SpellType_WORTCRAFT = 8,
    MagicSystem__SpellType_LEVELED_SPELL = 9,
    MagicSystem__SpellType_ADDICTION = 10,
    MagicSystem__SpellType_SPELL_TYPE_COUNT = 11
};

class ActiveEffect
{
public:
    virtual ~ActiveEffect();                                   // 00
    virtual ActiveEffect* Copy();                              // 04
    virtual void Finalize();                                   // 08
    virtual void Update(float afElapsedSeconds);               // 0C
    virtual unsigned short GetSaveSize(Actor* apActor);         // 10
    // MSVC places each virtual overload group in reverse declaration order.
    virtual void SaveGame(Actor* apActor);                      // 18
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);          // 14
    virtual void LoadGame(Actor* apActor);                      // 20
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);          // 1C
    virtual void InitLoadGame(Actor* apActor);                  // 28
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);      // 24
    virtual void FinishLoadGameTES(Actor* apActor);             // 2C
    virtual void Revert(Actor* apActor);                        // 34
    virtual void Revert(BGSLoadFormBuffer* apBuffer);            // 30
    virtual bool CanApply(MagicCaster* apCaster);               // 38
    virtual bool CanFinish();                                  // 3C
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);   // 40
    virtual void CopyData(ActiveEffect* apOther);               // 44
    virtual bool CanCast(MagicCaster* apCaster);                // 48
    virtual bool IsEffectValid(MagicTarget* apTarget);          // 4C
    virtual void Start();                                      // 50
    virtual void Continue();                                   // 54
    virtual void Finish();                                     // 58

    float m_fEffectMagnitude;
    MagicItem* pSpell;
    EffectItem* pEffect;
    bool bActive;
    bool bEffectFlag;
    bool bWasPlaying;
    bool bPickResultFound;
    bool m_bEffectState;
    unsigned char layoutPadding15[3];
    int iFlags;
    float m_fElapsedTime;
    float fDuration;
    MagicTarget* pTarget;
    MagicCaster* m_pEffectInstance;
    MagicSystem__SpellType m_eSpellType;
    BSSoundHandle m_kSoundHandle;
    TESBoundObject* pSource;
    BSSimpleList<MagicHitEffect*>* pHitEffectList;
    MagicItem* pMagicItem;

    ActiveEffect(MagicCaster*, MagicItem*, EffectItem*);
    void AddFlags(unsigned int);
    bool IsFlagged();
    bool HasFlag(unsigned int);
    void AdvanceEffect(float, bool);
    bool IsTerminated();
    float GetAge();
    void SetEffectiveness(float);
    float GetFloatAtOffset1C();
    EffectSetting* GetEffectSetting();
    EffectSetting* GetEffectSetting() const;
    void ResetEffectState();
    bool IsDone();
    bool IsDone() const;
    float GetDuration() const;
    MagicTarget* GetTarget();
    void Dispel(bool bForce);
    void ApplyLockEffect();
    bool GetByteAtOffset17();
    void SetFlag(bool);
    bool IsFlag200Set();
    void UpdateEffect(float);
    void InitFromSource(TESBoundObject*);
    void LoadGame(void*);

    bool HasConditions();
    bool ActiveEffect_IsActive();
    float FUN_007df1f0();
    void BaseProcess_SetLastTimeProcessed(float);
    void ActiveEffect_SetMagnitude(float);
    MagicTarget* FUN_0059bb30();
    void* FUN_006733e0();
    MagicItem* FUN_0044ddc0();
    EffectItem* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    EffectSetting* FUN_007df1d0();
    void FUN_00808680();
    void FUN_00804bc0(float);
    bool FUN_00705cf0();

    static void LoadActiveEffectList(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect*>*);
    static ActiveEffect* ReadActiveEffect(BGSLoadFormBuffer*);
    static void __cdecl WriteActiveEffectList(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect*>*);
};
