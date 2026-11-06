// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_ACTIVEEFFECT_H
#define FNV_ACTIVEEFFECT_H

#include "statsmenu_layout_support.h"
#include "statsmenu_BSSoundHandle.h"
#include "statsmenu_MagicCaster.h"
#include "statsmenu_MagicTarget.h"
#include "statsmenu_layout_support.h"
class EffectItem;
class MagicHitEffect;
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
    void** m_ppVirtualMethodTable;           // +0x0, 4 bytes
    float m_fEffectMagnitude;  // +0x4, 4 bytes
    MagicItem* pSpell;         // +0x8, 4 bytes
    EffectItem* pEffect;       // +0xC, 4 bytes
    bool bActive;              // +0x10, 1 bytes
    bool bEffectFlag;          // +0x11, 1 bytes
    bool bWasPlaying;          // +0x12, 1 bytes
    bool bPickResultFound;                // +0x13, 1 bytes
    bool m_bEffectState;       // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    int iFlags;                                     // +0x18, 4 bytes
    float m_fElapsedTime;                           // +0x1C, 4 bytes
    float fDuration;                                // +0x20, 4 bytes
    MagicTarget* pTarget;                           // +0x24, 4 bytes
    MagicCaster* m_pEffectInstance;                           // +0x28, 4 bytes
    MagicSystem__SpellType m_eSpellType;            // +0x2C, 4 bytes
    BSSoundHandle m_kSoundHandle;                   // +0x30, 12 bytes
    TESBoundObject* pSource;                        // +0x3C, 4 bytes
    BSSimpleList<MagicHitEffect*>* pHitEffectList;  // +0x40, 4 bytes
    MagicItem* pMagicItem;                          // +0x44, 4 bytes
    float GetDuration() const;
    EffectSetting* GetEffectSetting() const;
    // ActiveEffect
    // void __cdecl ActiveEffect::*(float)
    // void __cdecl ActiveEffect::*(MagicTarget*)
    // MagicTarget* __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(MagicCaster*)
    // MagicCaster* __cdecl ActiveEffect::*()
    // MagicItem* __cdecl ActiveEffect::*()
    // MagicSystem::SpellType __cdecl ActiveEffect::*()
    // EffectItem* __cdecl ActiveEffect::*()
    // EffectSetting* __cdecl ActiveEffect::*()
    // float __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(float)
    // float __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(float)
    // void __cdecl ActiveEffect::*(float)
    // float __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(TESBoundObject*)
    // TESBoundObject* __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(MagicItem*)
    // MagicItem* __cdecl ActiveEffect::*()
    // bool __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(bool)
    // bool __cdecl ActiveEffect::*()
    // bool __cdecl ActiveEffect::*()
    // bool __cdecl ActiveEffect::*()
    // bool __cdecl ActiveEffect::*()
    // bool __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(float, bool)
    // BSSimpleList<MagicHitEffect *>* __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(MagicHitEffect*)
    // void __cdecl ActiveEffect::*(BSSimpleList<MagicHitEffect *>*)
    // void __cdecl ActiveEffect::*()
    // bool __cdecl ActiveEffect::*(ActiveEffect::ActiveEffectFlags)
    // void __cdecl ActiveEffect::*(ActiveEffect::ActiveEffectFlags)
    // void __cdecl ActiveEffect::*(ActiveEffect::ActiveEffectFlags)
    // void __cdecl ActiveEffect::*(bool)
    // bool __cdecl ActiveEffect::*()
    // SaveGame
    // LoadGame
    // InitLoadGame
    // Revert
    // unsigned short __cdecl ActiveEffect::*(ActiveEffect*, Actor*)
    // unsigned short __cdecl ActiveEffect::*(BSSimpleList<ActiveEffect *>*, Actor*)
    // SaveActiveEffectList
    // LoadActiveEffectList
    // void __cdecl ActiveEffect::*(BSSimpleList<ActiveEffect *>*, Actor*)
    // void __cdecl ActiveEffect::*(BSSimpleList<ActiveEffect *>*, Actor*)
    // RevertActiveEffectList
    // void __cdecl ActiveEffect::*(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect *>*)
    // void __cdecl ActiveEffect::*(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect *>*)
    // bool __cdecl ActiveEffect::*()
    // void __cdecl ActiveEffect::*(float)
    // void __cdecl ActiveEffect::*()
    // ActiveEffect& __cdecl ActiveEffect::*(const ActiveEffect&)
};
FNV_STATIC_ASSERT(sizeof(ActiveEffect) == 72);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_fEffectMagnitude) == 4);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pSpell) == 8);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pEffect) == 12);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bActive) == 16);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bEffectFlag) == 17);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bWasPlaying) == 18);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bPickResultFound) == 19);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_bEffectState) == 20);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, iFlags) == 24);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_fElapsedTime) == 28);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, fDuration) == 32);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pTarget) == 36);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_pEffectInstance) == 40);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_eSpellType) == 44);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_kSoundHandle) == 48);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pSource) == 60);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pHitEffectList) == 64);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pMagicItem) == 68);
#endif
