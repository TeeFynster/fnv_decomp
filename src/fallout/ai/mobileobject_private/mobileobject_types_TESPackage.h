// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESPACKAGE_H
#define FNV_TESPACKAGE_H

#include "../../../../include/layout_support.h"
#include "../../../../include/Script.h"
#include "../../../../include/PerkEntryConditionSet.h"
#include "../../../../include/TESForm.h"
#include "mobileobject_package_enum.h"
#include "../../../../include/TESTopic.h"
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
#include "../../../../include/PACKAGE_PROCEDURE_TYPE.h"
#include "../../../../include/PACK_EVENT_ACTION_TYPE.h"

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
FNV_STATIC_ASSERT(sizeof(PackedByteIntRecord) == 8);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte0) == 0);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte1) == 1);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte2) == 2);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cLastByteBeforePayloadItem) == 3);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_iPayloadInteger) == 4);
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
FNV_STATIC_ASSERT(sizeof(DurationData) == 8);
FNV_STATIC_ASSERT(offsetof(DurationData, m_kScheduleData) == 0);


#define _ULARGE_INTEGER FNV64_ULARGE_INTEGER_Unused
#define PACKAGE_TYPE FNV64_PACKAGE_TYPE_Shared
#include "../../../../include/TESPackage.h"
#undef PACKAGE_TYPE
#undef _ULARGE_INTEGER
#endif
