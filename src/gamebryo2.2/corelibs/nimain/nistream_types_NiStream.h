// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NISTREAM_TYPES_H
#define FNV_NISTREAM_TYPES_H
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTNewInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiTLargeObjectArray.h"
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
#include "layout_support.h"
class NiBinaryStream;
class NiObjectGroup;
class ProcessorAffinityInfo;
class NiSearchPath;
class NiStream;
class NiStream__BackgroundLoadProcedure;
class NiTPrimitiveSet_unsigned_int_;
class NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___;
class NiThread;
enum NiStream__ThreadStatus
{
    NiStream__ThreadStatus_IDLE = 0,
    NiStream__ThreadStatus_LOADING = 1,
    NiStream__ThreadStatus_CANCELLING = 2,
    NiStream__ThreadStatus_PAUSING = 3,
    NiStream__ThreadStatus_PAUSED = 4
};
enum NiThread__Priority
{
    NiThread__Priority_IDLE = 0,
    NiThread__Priority_LOWEST = 1,
    NiThread__Priority_BELOW_NORMAL = 2,
    NiThread__Priority_NORMAL = 3,
    NiThread__Priority_ABOVE_NORMAL = 4,
    NiThread__Priority_HIGHEST = 5,
    NiThread__Priority_TIME_CRITICAL = 6,
    NiThread__Priority_NUM_PRIORITIES = 7
};
enum NiProcessorAffinity__Processor
{
    NiProcessorAffinity__Processor_PROCESSOR_0 = 1,
    NiProcessorAffinity__Processor_PROCESSOR_1 = 2,
    NiProcessorAffinity__Processor_PROCESSOR_2 = 4,
    NiProcessorAffinity__Processor_PROCESSOR_3 = 8,
    NiProcessorAffinity__Processor_PROCESSOR_4 = 16,
    NiProcessorAffinity__Processor_PROCESSOR_5 = 32,
    NiProcessorAffinity__Processor_PROCESSOR_6 = 64,
    NiProcessorAffinity__Processor_PROCESSOR_7 = 128,
    NiProcessorAffinity__Processor_PROCESSOR_8 = 256,
    NiProcessorAffinity__Processor_PROCESSOR_9 = 512,
    NiProcessorAffinity__Processor_PROCESSOR_10 = 1024,
    NiProcessorAffinity__Processor_PROCESSOR_11 = 2048,
    NiProcessorAffinity__Processor_PROCESSOR_12 = 4096,
    NiProcessorAffinity__Processor_PROCESSOR_13 = 8192,
    NiProcessorAffinity__Processor_PROCESSOR_14 = 16384,
    NiProcessorAffinity__Processor_PROCESSOR_15 = 32768,
    NiProcessorAffinity__Processor_PROCESSOR_16 = 65536,
    NiProcessorAffinity__Processor_PROCESSOR_17 = 131072,
    NiProcessorAffinity__Processor_PROCESSOR_18 = 262144,
    NiProcessorAffinity__Processor_PROCESSOR_19 = 524288,
    NiProcessorAffinity__Processor_PROCESSOR_20 = 1048576,
    NiProcessorAffinity__Processor_PROCESSOR_21 = 2097152,
    NiProcessorAffinity__Processor_PROCESSOR_22 = 4194304,
    NiProcessorAffinity__Processor_PROCESSOR_23 = 8388608,
    NiProcessorAffinity__Processor_PROCESSOR_24 = 16777216,
    NiProcessorAffinity__Processor_PROCESSOR_25 = 33554432,
    NiProcessorAffinity__Processor_PROCESSOR_26 = 67108864,
    NiProcessorAffinity__Processor_PROCESSOR_27 = 134217728,
    NiProcessorAffinity__Processor_PROCESSOR_28 = 268435456,
    NiProcessorAffinity__Processor_PROCESSOR_29 = 536870912,
    NiProcessorAffinity__Processor_PROCESSOR_30 = 1073741824,
    NiProcessorAffinity__Processor_PROCESSOR_31 = -2147483648,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_0_THREAD_0 = 1,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_0_THREAD_1 = 2,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_1_THREAD_0 = 4,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_1_THREAD_1 = 8,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_2_THREAD_0 = 16,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_2_THREAD_1 = 32,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_0 = 3,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_1 = 12,
    NiProcessorAffinity__Processor_PROCESSOR_CONSOLE_CORE_2 = 48,
    NiProcessorAffinity__Processor_PROCESSOR_DONT_CARE = -1
};
#pragma pack(push, 4)
// the exe's NiTPrimitiveArray<NiObjectGroup*> (the name spells the instantiation)
typedef NiTPrimitiveArray<NiObjectGroup*> NiTPrimitiveArray_NiObjectGroup___;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_NiObjectGroup___) == 16);
#pragma pack(push, 4)
// the exe's NiTLargeObjectArray<NiPointer<NiObject> > (the name spells the instantiation)
typedef NiTLargeObjectArray<NiPointer<NiObject> > NiTLargeObjectArray_NiPointer_NiObject___;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTLargeObjectArray_NiPointer_NiObject___) == 24);
#pragma pack(push, 4)
// the exe's NiTLargeObjectArray<NiFixedString> (the name spells the instantiation)
typedef NiTLargeObjectArray<NiFixedString> NiTLargeObjectArray_NiFixedString_;
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTLargeObjectArray_NiFixedString_) == 24);
#pragma pack(push, 4)
class NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___
{
  public:
    unsigned int* m_pBase;               // +0x0, 4 bytes
    unsigned int m_uiElementCount;       // +0x4, 4 bytes
    unsigned int m_uiAllocatedCapacity;  // +0x8, 4 bytes
    // NiTSet<unsigned int,NiTMallocInterface<unsigned int> >
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // unsigned int __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // unsigned int* __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // GetAt
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
    // bool __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // bool __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int, const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // Realloc
    // int __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // NiTSet<unsigned int,NiTMallocInterface<unsigned int> >& __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const NiTSet<unsigned int,NiTMallocInterface<unsigned int> >&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // void* __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_pBase) == 0);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_uiElementCount) == 4);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_uiAllocatedCapacity) == 8);
#pragma pack(push, 4)
class NiTPrimitiveSet_unsigned_int_ : public NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___
{
  public:
    // base NiTSet<unsigned int,NiTMallocInterface<unsigned int> > at +0x0, size 12
    // NiTPrimitiveSet<unsigned int>
    // void __cdecl NiTPrimitiveSet<unsigned int>::*()
    // NiTPrimitiveSet<unsigned int>& __cdecl NiTPrimitiveSet<unsigned int>::*(const NiTPrimitiveSet<unsigned int>&)
    // void __cdecl NiTPrimitiveSet<unsigned int>::*()
    // void* __cdecl NiTPrimitiveSet<unsigned int>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveSet_unsigned_int_) == 12);
#pragma pack(push, 4)
class ProcessorAffinityInfo
{
  public:
    NiProcessorAffinity__Processor m_eProcessorAffinity;  // +0x0, 4 bytes
    unsigned int m_uiProcessorAffinityMask;               // +0x4, 4 bytes
    // ProcessorAffinityInfo
    // unsigned int __cdecl ProcessorAffinityInfo::*()
    // void __cdecl ProcessorAffinityInfo::*(unsigned int)
    // ProcessorAffinityInfo::Processor __cdecl ProcessorAffinityInfo::*()
    // void __cdecl ProcessorAffinityInfo::*(ProcessorAffinityInfo::Processor)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ProcessorAffinityInfo) == 8);
FNV_STATIC_ASSERT(offsetof(ProcessorAffinityInfo, m_eProcessorAffinity) == 0);
FNV_STATIC_ASSERT(offsetof(ProcessorAffinityInfo, m_uiProcessorAffinityMask) == 4);
// NiStream itself and BSStreamHeader are the shared include/NiStream.h definitions.
#endif
