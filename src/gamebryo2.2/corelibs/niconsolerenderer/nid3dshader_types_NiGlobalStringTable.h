// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIGLOBALSTRINGTABLE_H
#define FNV_NIGLOBALSTRINGTABLE_H
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTNewInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"

#include "layout_support.h"
#include "_RTL_CRITICAL_SECTION.h"
#include "layout_support.h"
class NiCriticalSection;
class NiGlobalStringTable;
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<char*> (the name spells the instantiation)
typedef NiTPrimitiveArray<char*> NiTPrimitiveArray_char___;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_char___) == 16);
#pragma pack(push, 4)
class NiCriticalSection
{
  public:
    _RTL_CRITICAL_SECTION m_kCriticalSection;  // +0x0, 28 bytes
    unsigned long m_ulThreadOwner;             // +0x1C, 4 bytes
    unsigned int m_uiLockCount;                // +0x20, 4 bytes
    unsigned char layoutPadding24[92];
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // unsigned int __cdecl NiCriticalSection::*()
    // unsigned int __cdecl NiCriticalSection::*()
    // void* __cdecl NiCriticalSection::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiCriticalSection) == 128);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_kCriticalSection) == 0);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_ulThreadOwner) == 28);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_uiLockCount) == 32);
#endif
