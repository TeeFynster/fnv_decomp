// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_EFFECTITEM_H
#define FNV_EFFECTITEM_H

#include "statsmenu_layout_support.h"
#include "../include/PerkEntryConditionSet.h"
class EffectItem;
class MagicEffectEntry;
enum MagicSystem__Range
{
    MagicSystem__Range_SELF = 0,
    MagicSystem__Range_TOUCH = 1,
    MagicSystem__Range_TARGET = 2,
    MagicSystem__Range_RANGE_COUNT = 3
};
class MagicEffectEntry
{
  public:
    int m_iMagnitude;               // +0x0, 4 bytes
    int m_iArea;                    // +0x4, 4 bytes
    int m_iPayloadInteger;                  // +0x8, 4 bytes
    MagicSystem__Range m_eRange;    // +0xC, 4 bytes
    ActorValue__Index m_eAssociatedActorValue;  // +0x10, 4 bytes
    // void __cdecl MagicEffectEntry::*()
    // void __cdecl MagicEffectEntry::*()
};
FNV_STATIC_ASSERT(sizeof(MagicEffectEntry) == 20);
FNV_STATIC_ASSERT(offsetof(MagicEffectEntry, m_iMagnitude) == 0);
FNV_STATIC_ASSERT(offsetof(MagicEffectEntry, m_iArea) == 4);
FNV_STATIC_ASSERT(offsetof(MagicEffectEntry, m_iPayloadInteger) == 8);
FNV_STATIC_ASSERT(offsetof(MagicEffectEntry, m_eRange) == 12);
FNV_STATIC_ASSERT(offsetof(MagicEffectEntry, m_eAssociatedActorValue) == 16);
class EffectItem
{
  public:
    MagicEffectEntry data;            // +0x0, 20 bytes
    EffectSetting* m_pEffectSetting;  // +0x14, 4 bytes
    float m_fCost;                    // +0x18, 4 bytes
    PerkEntryConditionSet Conditions;          // +0x1C, 8 bytes
    EffectSetting* GetEffectSetting() const;
    bool IsScriptBasedEffect();
    bool IsActorValueUsed();
    int GetAffectedActorValue();
    int FUN_00403ea0();
    // EffectItem
    // void __cdecl EffectItem::*()
    // void __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*(TESFile*, const char*)
    // void __cdecl EffectItem::*(EffectItem*)
    // bool __cdecl EffectItem::*(EffectItem*)
    // bool __cdecl EffectItem::*(EffectItem*)
    // void __cdecl EffectItem::*(TESForm*)
    // GetEffectString
    // EffectSetting* __cdecl EffectItem::*()
    // const char* __cdecl EffectItem::*()
    // int __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*(int)
    // int __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*(int)
    // int __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*(int)
    // MagicSystem::Range __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*(MagicSystem::Range)
    // int __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*()
    // bool __cdecl EffectItem::*()
    // void __cdecl EffectItem::*(bool)
    // bool __cdecl EffectItem::*()
    // GetEffectName
    // ActorValue::Index __cdecl EffectItem::*()
    // ActorValue::Index __cdecl EffectItem::*()
    // void __cdecl EffectItem::*(ActorValue::Index)
    // Script* __cdecl EffectItem::*()
    // float __cdecl EffectItem::*(Actor*)
    // float __cdecl EffectItem::*()
    // void __cdecl EffectItem::*(EffectSetting*)
    // void __cdecl EffectItem::*(EffectSetting*)
    // EffectItem& __cdecl EffectItem::*(const EffectItem&)
    // void* __cdecl EffectItem::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(EffectItem) == 36);
FNV_STATIC_ASSERT(offsetof(EffectItem, data) == 0);
FNV_STATIC_ASSERT(offsetof(EffectItem, m_pEffectSetting) == 20);
FNV_STATIC_ASSERT(offsetof(EffectItem, m_fCost) == 24);
FNV_STATIC_ASSERT(offsetof(EffectItem, Conditions) == 28);
#endif
