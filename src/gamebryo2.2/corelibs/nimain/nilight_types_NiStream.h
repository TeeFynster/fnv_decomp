// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NISTREAM_TYPES_H
#define FNV_NISTREAM_TYPES_H
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTNewInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiTLargeObjectArray.h"

#include "layout_support.h"
#include "../../../../include/BSStreamHeader.h"
#include "NiFixedString.h"
class NiObjectGroup;
class ProcessorAffinityInfo;
class NiSearchPath;
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
#pragma pack(push, 4)
// Retained because shared NiStream.h redeclares BSStreamHeader instead of including its shared header.
class NiStream
{
  public:
    void** m_ppVirtualMethodTable;                                     // +0x0, 4 bytes
    BSStreamHeader m_kHeader;                            // +0x4, 196 bytes
    NiTPrimitiveArray_NiObjectGroup___ m_kObjectGroups;  // +0xC8, 16 bytes
    unsigned int m_uiNifVersion;                         // +0xD8, 4 bytes
    unsigned int StreamFileInfo;                         // +0xDC, 4 bytes
    char m_acInputFilePath[260];                         // +0xE0, 260 bytes
    bool m_bFirstStreamFlag;                             // +0x1E4, 1 bytes
    bool m_bSecondStreamFlag;                            // +0x1E5, 1 bytes
    unsigned char layoutPadding1E6[2];
    NiSearchPath* m_pSearchPath;                                             // +0x1E8, 4 bytes
    NiTLargeObjectArray_NiPointer_NiObject___ m_kThirdFollowingStreamField;  // +0x1EC, 24 bytes
    NiTLargePrimitiveArray<unsigned int> ObjectSerializationStream;          // +0x204, 24 bytes
    NiTLargeObjectArray_NiPointer_NiObject___ m_kTopLevelObjects;            // +0x21C, 24 bytes
    NiTLargeObjectArray_NiFixedString_ m_kStringTable;                       // +0x234, 24 bytes
    NiBinaryStream* m_pUnderlyingStream;                                     // +0x24C, 4 bytes
    NiBinaryStream* m_pBackingStream;                                        // +0x250, 4 bytes
    NiTPrimitiveSet_unsigned_int_ m_kSecondFollowingStreamField;             // +0x254, 12 bytes
    unsigned int StreamObjectIndex;                                          // +0x260, 4 bytes
    NiTPrimitiveSet_unsigned_int_ m_kSecondUnsignedIntSet;                   // +0x264, 12 bytes
    unsigned int m_uiObjectIndexCount;                                       // +0x270, 4 bytes
    NiTPointerMap<const NiObject*, unsigned int> m_kObjectToIndexMap;        // +0x274, 16 bytes
    unsigned short m_usAVObjectFlags;                                        // +0x284, 2 bytes
    unsigned short m_usTimeControllerFlags;                                  // +0x286, 2 bytes
    unsigned short m_usPropertyFlags;                                        // +0x288, 2 bytes
    unsigned char layoutPadding28A[2];
    NiStream__ThreadStatus m_eStreamThreadStatus;  // +0x28C, 4 bytes
    bool m_bThreadActive;                          // +0x290, 1 bytes
    unsigned char layoutPadding291[3];
    unsigned int StreamThreadContext;                       // +0x294, 4 bytes
    unsigned int m_uiBackgroundLoadState;                   // +0x298, 4 bytes
    unsigned int BackgroundLoadThreadInfo;                  // +0x29C, 4 bytes
    NiThread* m_pBackgroundLoadThread;                      // +0x2A0, 4 bytes
    NiStream__BackgroundLoadProcedure* BackgroundLoadTask;  // +0x2A4, 4 bytes
    NiThread__Priority m_eThreadPriority;                   // +0x2A8, 4 bytes
    ProcessorAffinityInfo m_kBackgroundLoadSemaphore;       // +0x2AC, 8 bytes
    char m_acLoadPath[260];                                 // +0x2B4, 260 bytes
    unsigned int m_uiNativeThreadId;                        // +0x3B8, 4 bytes
    char m_acSecondPathBuffer[260];                         // +0x3BC, 260 bytes
    char m_acFilePathBuffer[260];                           // +0x4C0, 260 bytes
    // NiStream
    // void __cdecl NiStream::*(NiObject*)
    // void __cdecl NiStream::*(NiObject*)
    // void __cdecl NiStream::*()
    // unsigned int __cdecl NiStream::*()
    // NiObject* __cdecl NiStream::*(unsigned int)
    // Load
    // Save
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*(bool)
    // bool __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // BackgroundLoadBegin
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // const ProcessorAffinityInfo& __cdecl NiStream::*()
    // void __cdecl NiStream::*(const ProcessorAffinityInfo&)
    // const NiThread::Priority __cdecl NiStream::*()
    // void __cdecl NiStream::*(const NiThread::Priority)
    // unsigned int __cdecl NiStream::*(const char*)
    // unsigned int __cdecl NiStream::*(unsigned int, unsigned int, unsigned int, unsigned int)
    // unsigned int __cdecl NiStream::*()
    // unsigned int __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned int)
    // unsigned int __cdecl NiStream::*()
    // const char* __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*(char*&)
    // void __cdecl NiStream::*(const char*)
    // void __cdecl NiStream::*(NiFixedString&)
    // void __cdecl NiStream::*(const NiFixedString&)
    // void __cdecl NiStream::*(NiFixedString&)
    // void __cdecl NiStream::*()
    // unsigned int __cdecl NiStream::*()
    // NiObject* __cdecl NiStream::*()
    // NiObject* __cdecl NiStream::*()
    // unsigned int __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned int)
    // NiObjectGroup* __cdecl NiStream::*(unsigned int)
    // unsigned int __cdecl NiStream::*(NiObjectGroup*)
    // NiBinaryStream& __cdecl NiStream::*()
    // NiBinaryStream& __cdecl NiStream::*()
    // void __cdecl NiStream::*(NiTexture*)
    // void __cdecl NiStream::*(const char*, NiPointer<NiTexture>&)
    // NiSearchPath* __cdecl NiStream::*()
    // void __cdecl NiStream::*(NiSearchPath*)
    // const char* __cdecl NiStream::*()
    // unsigned short __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned short)
    // unsigned short __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned short)
    // unsigned short __cdecl NiStream::*()
    // void __cdecl NiStream::*(unsigned short)
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // int __cdecl NiStream::*(const char*, NiObject* __cdecl ()*)
    // void __cdecl NiStream::*(const char*)
    // void __cdecl NiStream::*(void __cdecl (NiStream&, NiObject*)*)
    // void __cdecl NiStream::*(void __cdecl (NiStream&, NiObject*)*)
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // NiObject* __cdecl NiStream::*(const char*)
    // const char* __cdecl NiStream::*()
    // void __cdecl NiStream::*(const char*)
    // void __cdecl NiStream::*()
    // bool __cdecl NiStream::*(char*, unsigned int)
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*(NiAVObject*)
    // void __cdecl NiStream::*(char*)
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*(const char*)
    // unsigned int __cdecl NiStream::*(const NiFixedString&)
    // void __cdecl NiStream::*()
    // bool __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // void __cdecl NiStream::*()
    // NiStream& __cdecl NiStream::*(const NiStream&)
    // void __cdecl NiStream::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiStream) == 1476);
FNV_STATIC_ASSERT(offsetof(NiStream, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kHeader) == 4);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kObjectGroups) == 200);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiNifVersion) == 216);
FNV_STATIC_ASSERT(offsetof(NiStream, StreamFileInfo) == 220);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acInputFilePath) == 224);
FNV_STATIC_ASSERT(offsetof(NiStream, m_bFirstStreamFlag) == 484);
FNV_STATIC_ASSERT(offsetof(NiStream, m_bSecondStreamFlag) == 485);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pSearchPath) == 488);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kThirdFollowingStreamField) == 492);
FNV_STATIC_ASSERT(offsetof(NiStream, ObjectSerializationStream) == 516);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kTopLevelObjects) == 540);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kStringTable) == 564);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pUnderlyingStream) == 588);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pBackingStream) == 592);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kSecondFollowingStreamField) == 596);
FNV_STATIC_ASSERT(offsetof(NiStream, StreamObjectIndex) == 608);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kSecondUnsignedIntSet) == 612);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiObjectIndexCount) == 624);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kObjectToIndexMap) == 628);
FNV_STATIC_ASSERT(offsetof(NiStream, m_usAVObjectFlags) == 644);
FNV_STATIC_ASSERT(offsetof(NiStream, m_usTimeControllerFlags) == 646);
FNV_STATIC_ASSERT(offsetof(NiStream, m_usPropertyFlags) == 648);
FNV_STATIC_ASSERT(offsetof(NiStream, m_eStreamThreadStatus) == 652);
FNV_STATIC_ASSERT(offsetof(NiStream, m_bThreadActive) == 656);
FNV_STATIC_ASSERT(offsetof(NiStream, StreamThreadContext) == 660);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiBackgroundLoadState) == 664);
FNV_STATIC_ASSERT(offsetof(NiStream, BackgroundLoadThreadInfo) == 668);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pBackgroundLoadThread) == 672);
FNV_STATIC_ASSERT(offsetof(NiStream, BackgroundLoadTask) == 676);
FNV_STATIC_ASSERT(offsetof(NiStream, m_eThreadPriority) == 680);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kBackgroundLoadSemaphore) == 684);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acLoadPath) == 692);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiNativeThreadId) == 952);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acSecondPathBuffer) == 956);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acFilePathBuffer) == 1216);
#endif
