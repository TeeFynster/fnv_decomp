// Names of nested/template specializations use the canonical generator identifier mapping.
#include "../../../include/TESPackage.h"
#ifndef FNV_TESPACKAGE_H
#define FNV_TESPACKAGE_H

#include "layout_support.h"
#include "Script.h"
#include "PerkEntryConditionSet.h"
#include "TESForm.h"
#include "TESTopic.h"
class Actor;
class TESObjectREFR;
class BGSIdleCollection;
class PackageRuntimeData;
class PackedByteIntRecord;
class PackageEventActionData;
class LocationDescriptor;
class DurationData;
class PackageTargetRecord;
class TESCombatStyle;
class TESIdleForm;
class TESPackageData;
#include "../../../include/PACKAGE_PROCEDURE_TYPE.h"
#include "../../../include/PACK_EVENT_ACTION_TYPE.h"
#pragma pack(push, 4)
class PackageRuntimeData
{
  public:
    unsigned int m_uiPackEventActionType;  // +0x0, 4 bytes
    char m_cEventActionValue;              // +0x4, 1 bytes
    unsigned char layoutPadding5[1];
    unsigned short IntegerByteAndShortPairRecord;  // +0x6, 2 bytes
    unsigned short m_usPairedShortValue;           // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    // void __cdecl PackageRuntimeData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackageRuntimeData) == 12);
FNV_STATIC_ASSERT(offsetof(PackageRuntimeData, m_uiPackEventActionType) == 0);
FNV_STATIC_ASSERT(offsetof(PackageRuntimeData, m_cEventActionValue) == 4);
FNV_STATIC_ASSERT(offsetof(PackageRuntimeData, IntegerByteAndShortPairRecord) == 6);
FNV_STATIC_ASSERT(offsetof(PackageRuntimeData, m_usPairedShortValue) == 8);
#pragma pack(push, 4)
class PackedByteIntRecord
{
  public:
    char m_cByte0;  // +0x0, 1 bytes
    char m_cByte1;  // +0x1, 1 bytes
    char m_cByte2;  // +0x2, 1 bytes
    char m_cLastByteBeforePayloadItem;     // +0x3, 1 bytes
    int m_iPayloadInteger;  // +0x4, 4 bytes
    // void __cdecl PackedByteIntRecord::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackedByteIntRecord) == 8);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte0) == 0);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte1) == 1);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte2) == 2);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cLastByteBeforePayloadItem) == 3);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_iPayloadInteger) == 4);
#pragma pack(push, 4)
class DurationData
{
  public:
    PackedByteIntRecord m_kScheduleData;  // +0x0, 8 bytes
    // DurationData
    // void __cdecl DurationData::*()
    // PSMONTH __cdecl DurationData::*()
    // void __cdecl DurationData::*(PSMONTH)
    // PSDAYOFWEEK __cdecl DurationData::*()
    // void __cdecl DurationData::*(PSDAYOFWEEK)
    // char __cdecl DurationData::*()
    // void __cdecl DurationData::*(char)
    // char __cdecl DurationData::*()
    // void __cdecl DurationData::*(char)
    // int __cdecl DurationData::*()
    // void __cdecl DurationData::*(int)
    // void __cdecl DurationData::*(DurationData*)
    // bool __cdecl DurationData::*(DurationData*)
    // void __cdecl DurationData::*()
    // const char* __cdecl DurationData::*()
    // const char* __cdecl DurationData::*()
    // void* __cdecl DurationData::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DurationData) == 8);
FNV_STATIC_ASSERT(offsetof(DurationData, m_kScheduleData) == 0);
#pragma pack(push, 4)
class PackageEventActionData
{
  public:
    TESIdleForm* m_pIdleForm;      // +0x0, 4 bytes
    Script* m_pScript;             // +0x4, 4 bytes
    TESTopic* pTopic;              // +0x8, 4 bytes
    PACK_EVENT_ACTION_TYPE eType;  // +0xC, 4 bytes
    // void __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // TESIdleForm* __cdecl PackageEventActionData::*()
    // Script* __cdecl PackageEventActionData::*()
    // TESTopic* __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*(TESIdleForm*)
    // void __cdecl PackageEventActionData::*(const char*)
    // void __cdecl PackageEventActionData::*(TESTopic*)
    // void __cdecl PackageEventActionData::*(PACK_EVENT_ACTION_TYPE)
    // PACK_EVENT_ACTION_TYPE __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*(PackageEventActionData*)
    // bool __cdecl PackageEventActionData::*(PackageEventActionData*)
    // void __cdecl PackageEventActionData::*(TESFile*)
    // void __cdecl PackageEventActionData::*(CHUNK_ID)
    // void __cdecl PackageEventActionData::*(TESForm*)
    // unsigned short __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // const char* __cdecl PackageEventActionData::*()
    // void* __cdecl PackageEventActionData::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackageEventActionData) == 16);
FNV_STATIC_ASSERT(offsetof(PackageEventActionData, m_pIdleForm) == 0);
FNV_STATIC_ASSERT(offsetof(PackageEventActionData, m_pScript) == 4);
FNV_STATIC_ASSERT(offsetof(PackageEventActionData, pTopic) == 8);
FNV_STATIC_ASSERT(offsetof(PackageEventActionData, eType) == 12);
#pragma pack(push, 4)
#pragma pack(pop)
#endif
