// src/staging/blk_00ce0000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00ce0000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/staging/blk_00ce0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/MemoryManager.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiStream.h"
#include "../../include/hkArray.h" // also declares hkArrayUtil
#include "../../include/hkBool.h"
#include "../../include/hkBaseObject.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMultiThreadCheck.h"
#include "../../include/hkVector4.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkpBroadPhaseListener.h"
extern int DAT_010cc164;
void __cdecl FUN_00d86220();
struct FUN_00cf45d0_class
{
    int vtable;
    FUN_00cf45d0_class();
};
struct FUN_00cf4ca0_class
{
    int m_auiShapeKeys[6];
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    void hkpBinaryAction__referenceBodies();
};
struct FUN_00d06d50_cls
{
    int __thiscall FindClass(int);
};
extern "C" void __cdecl hkStatisticsCollectorUtil_addClassContentsAll(int, int, int);
void __cdecl hkStatisticsCollectorUtil_addClassContentsAll_00cf6950(int a, int apObject);
struct FUN_00cf86f0_class
{
    int IsFieldEqual();
};
unsigned short hkMath_min2_unsigned_short(unsigned short a, unsigned short b);
extern int DAT_010cb864;
struct FUN_00ce4ae0_cls
{
    int __thiscall AssignFields_00ce4ae0(int);
    void __thiscall hkaSkeletonMapperData_hkaSkeletonMapperData();
};
struct FUN_00ce4a20_cls
{
    int m_kPointA;
    short m_kPointB;
    short m_iThirdValue;
    int m_iFourthElementInteger;
    int __thiscall ProcessAndReturnValue_00ce4a20(int a);
};
extern int DAT_0102e378;
void __cdecl Object_UpdateFields_00cf69a0(int* a);
struct FUN_00cf69c0_class
{
    int m_kPointA;
    int m_auiShapeKeys;
    int m_kPointB;
    int __thiscall hkSingletonInitNode_findByName(int a);
};
int __cdecl hkString_strCmp(int a, int b);
struct FUN_00cf86e0_class
{
    void hkpSimulation_setFrameTimeMarker(float f);
};
extern int DAT_010cc2e0;
struct FUN_00cf4820_class
{
    int* vtbl;
    int m1;
    int m2;
    int m3;
    int m4;
    FUN_00cf4820_class();
};
extern int DAT_0102e388;
struct FUN_00cf86d0_cls
{
    void SetVtableAndProcessState_00cf86d0();
};
// FUN_00ce29e0: member function that (re)initialises the object.
//   - installs the base vtable pointer at [this],
//   - calls the constructor of the sub-object living at this+0x10,
//   - then installs the vtable pointer of the derived class at [this].
extern int DAT_010cb864;
extern int DAT_0102e388;
// Sub-object at +0x10; FUN_00ce5370 is the game's constructor for it.
struct FUN_00ce5370_cls
{
    void UpdateState_00ce5370();
};
struct FUN_00ce29e0_cls
{
    int* m_pVTable;          // +0x00
    int unk04;               // +0x04
    int unk08;               // +0x08
    int unk0C;               // +0x0C
    FUN_00ce5370_cls m_sub;  // +0x10
    void UpdateFields_00ce29e0();
};
struct FnvSpawnedObject;
struct FnvProbe
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned char* Match(FnvSpawnedObject** ref);
    unsigned char* Check(FnvSpawnedObject** ref);
};
struct FnvSpawnedObject
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FnvProbe m_10;
    FnvProbe m_20;
    unsigned char* Check(FnvSpawnedObject** ref);
};
bool __cdecl hkaSkeletonMapper_checkTransform(int unused, FnvSpawnedObject* obj);
void __cdecl Object_UpdateFields_00ce2ca0(int a1, int a2, int* a3, int a4);
void __cdecl hkaSkeletonMapper_mapExtractedMotion(int pObject, int param_2, int param_3);
void __cdecl hkaSkeletonMapper_mapPoseLocalSpace(int a1, int a2, int a3, int a4, int a5, int a6);
void __cdecl hkaSkeletonMapper_mapPoseLocalSpace_00ce4330(int a1, int a2, int a3, int a4);
struct FnvKeyRec
{
    unsigned short m_iOwnerObjectOffset;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};
struct FUN_00ce5480_cls
{
    int unk00;
    int unk04;
    FnvKeyRec* m_pRecords;
    int m_uiItemCount;
};
void* __cdecl FindKeyRecord(unsigned short aKey, FUN_00ce5480_cls* pKeyBox);
void __cdecl bhkLimitedForceConstraintMotor_SaveBinary(void* stream, void* self);
struct FUN_00cf4490_cls
{
    char unk00[0x14];
    unsigned int m_14;
    unsigned int m_18;
    unsigned char m_1c;
    void bhkVelocityConstraintMotor_SaveBinary(void* stream);
};
struct CpuOpaque;
extern CpuOpaque DAT_01268740;
CpuOpaque* __cdecl bhkSpringDamperConstraintMotor_GetRTTI();
struct SerializedObject
{
    int base00, base04, base08, base0C, base10, word14, word18;
    void __thiscall SerializeToStream(int source);
};
extern "C" void __cdecl bhkLimitedForceConstraintMotor_SaveBinary(int, SerializedObject*);
// Save a Havok-wrapped object: write its type id, then let a type-specific saver write the rest.
extern __declspec(thread) int g_iCF4BC0AllocTag;
struct CF4BC0AllocTagScope
{
    int m_iSaved;

    CF4BC0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCF4BC0AllocTag;
        g_iCF4BC0AllocTag = aiAllocationTag;
    }
    ~CF4BC0AllocTagScope()
    {
        g_iCF4BC0AllocTag = m_iSaved;
    }
};
inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes,
                                                unsigned int count)
{
    unsigned int written = m_pfnWrite(this, p, n, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}
template <class T>
inline void CF4BC0BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void CF4BC0SaveBinary(NiStream& kStream, const T& value)
{
    CF4BC0BinaryStreamSave(*kStream.m_pkOstr, &value);
}
class CF4BC0Object
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual unsigned int GetSaveType();
};
class CF4BC0Saver
{
  public:
    virtual void DeleteThis(bool bFree);
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void SaveBinary(NiStream& kStream);

    void SetObject(CF4BC0Object* pkObject);
};
CF4BC0Saver* __cdecl CF4BC0CreateSaver(unsigned int uiType);
void __cdecl bhkConstraintManager_SaveBinary(NiStream& kStream, CF4BC0Object* pkObject);
extern int DAT_010cc2fc;
extern int DAT_0102e388;
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct SubObject_b3813
{
    int unk00;
    void Release();
};
struct FUN_00cf4eb0_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    SubObject_b3813 m_sub;

    FUN_00cf4eb0_cls* Destroy(unsigned char acFlags);
};
struct S_00cf4f00
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    short unk24;
    unsigned short m_uiItemCount;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned int m_bits[1];
    void __thiscall ClearBit(unsigned int idx);
};
struct FUN_00cf4f30_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    short unk24;
    unsigned short counter;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    unsigned int bits[8];
    void SetBit(unsigned int index);
};
struct FUN_00cf4f70_src
{
    int* m_00;
    int m_04;
};
int __cdecl CountBitsInWords(int* data, int count);
class FUN_00cf4f70_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
    int unk20;
    unsigned short unk24;
    unsigned short m_26;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int m_50;

    void InitFromSource(FUN_00cf4f70_src* src);
};
struct FUN_00cf6980_class
{
    virtual void Object_ForwardCall_00cf6980(int);
};
void __cdecl Object_ForwardCall_00cf6980(FUN_00cf6980_class* object);
extern int DAT_01268748;
int* __cdecl Runtime_GetDAT01268748Address();
extern int DAT_0102e378;
int* __cdecl Runtime_GetDAT0102e378Address();
extern int DAT_01268794;
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(int value);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(int value);
struct S_00cf6b50_Foo
{
    int m_iWordAt00;
    short m_iWordAt04;
    unsigned short m_6;

    void __thiscall UpdateState(int a);
};
struct FUN_00cf6d50_cls
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    void UpdateState_00cf6d50();
};
struct FUN_00cf6f80_cls
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
    unsigned __int64 ComputeValue_00cf6f80();
};
// FUN_00cf8710 : thiscall member returning a bool.
//
// Original shape (24 bytes):
//   fld  dword ptr [ecx+0x18]
//   fld  dword ptr [ecx+0x14]
//   fucompp
//   fnstsw ax
//   test ah,0x44
//   jp   <not equal>
//   mov  eax,1
//   ret
//   <not equal>: xor eax,eax ; ret
//
// i.e. a plain float equality test between the two float members at +0x14 and
// +0x18 of the object, with the +0x18 member loaded first.
struct FUN_00cf8710_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float m_14;
    float m_18;

    bool hkpSimulation_isSimulationAtPsi();
};
extern MemoryManager _g_memoryManager;
class CF4840Saver
{
  public:
    void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    virtual void DeleteThis(bool bFree);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct Saver00 : CF4840Saver
{
    Saver00() throw();
};
struct Saver01 : CF4840Saver
{
    Saver01() throw();
};
struct Saver02 : CF4840Saver
{
    Saver02() throw();
};
struct Saver03 : CF4840Saver
{
    Saver03() throw();
};
struct Saver06 : CF4840Saver
{
    Saver06() throw();
};
struct Saver07 : CF4840Saver
{
    Saver07() throw();
};
struct Saver08 : CF4840Saver
{
    Saver08() throw();
};
struct Saver09 : CF4840Saver
{
    Saver09() throw();
};
struct Saver10 : CF4840Saver
{
    Saver10() throw();
};
struct Saver12 : CF4840Saver
{
    Saver12() throw();
};
struct Saver13 : CF4840Saver
{
    Saver13() throw();
};
CF4840Saver* __cdecl CreateSaver(unsigned int uiType);
// Build the Havok object for a serialized node: find its creator, run it, keep the result and delete the creator.
extern __declspec(thread) int g_iF4A30AllocTag;
struct F4A30AllocTagScope
{
    int m_iSaved;

    F4A30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iF4A30AllocTag;
        g_iF4A30AllocTag = aiAllocationTag;
    }
    ~F4A30AllocTagScope()
    {
        g_iF4A30AllocTag = m_iSaved;
    }
};
class F4A30Result
{
  public:
    void RetainReference();
};
class F4A30Node
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual int GetTypeID();
};
class F4A30Creator
{
  public:
    virtual ~F4A30Creator();
    virtual void Create(int iFlags, void* pvContext);

    void Init(F4A30Node* pkNode);

    F4A30Result* m_pkResult;
};
F4A30Creator* __cdecl F4A30FindCreator(int iTypeID);
F4A30Result* CreateF4A30Result(F4A30Node* pkNode, void* pvContext);
void __cdecl BuildMatrixFromRotationScaleAndPosition();
void __cdecl Object_ForwardCall_00ce5300();
class FUN_00ce5360_This
{
  public:
// @fnv 0x00ce5360
    virtual ~FUN_00ce5360_This()
    {}
    unsigned int ComputeValue_00ce5360(unsigned int arg);
};
// src: GUESS 0x00ce5360 (confidence: low)
unsigned int FUN_00ce5360_This::ComputeValue_00ce5360(unsigned int arg)
{
    return reinterpret_cast<unsigned int>(this);
}
class FUN_00ce9800_obj
{
  public:
    virtual ~FUN_00ce9800_obj();
};
void __cdecl DeleteObjectIfNotNull(FUN_00ce9800_obj* pkObject);
struct FUN_00ce9820_vt
{
    virtual void FUN_00ce9820_v0(int a);
    virtual void FUN_00ce9820_v1(int a);
};
void __cdecl CallVirtualMethodWithOne(FUN_00ce9820_vt* pObject);
struct Record
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};
void bhkPoseArray_bhkPose_SaveBinary(NiStream* owner, Record* rec);
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct ArrayData
{
    unsigned int* m_data;
    int m_iElementCount;
};
// @fnv 0x00cf0e90
extern "C" unsigned int __cdecl SaveUIntArray(NiStream& kStream, const ArrayData& kArray)
{
    unsigned int count = kArray.m_iElementCount;
    CF4BC0SaveBinary(kStream, count);

    unsigned int totalSize = count * sizeof(unsigned int);
    int i = 0;
    if ((int)count > 0)
    {
        do
        {
            unsigned int val = kArray.m_data[i];
            if ((unsigned char)kStream.m_bSaveLittleEndian != 1)
            {
                val = _byteswap_ulong(val);
            }
            CF4BC0SaveBinary(kStream, val);
            ++i;
        } while (i < (int)count);
    }

    return totalSize;
}
extern int DAT_010cc064;
struct FUN_00cdf560
{
    int m0;
    int m4;
    int m8;
    FUN_00cdf560(float);
};
struct FUN_00cf4190 : FUN_00cdf560
{
    FUN_00cf4190();
};
extern int DAT_01268730;
int* bhkPositionConstraintMotor_GetRTTI();
extern "C" void __cdecl bhkLimitedForceConstraintMotor_LoadBinary(void* view, void* object);
struct SerializedRecord
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int m_14, m_18, m_1c, m_20;
    void bhkPositionConstraintMotor_LoadBinary(NiStream* view);
};
struct CpuOpaque;
extern CpuOpaque DAT_01268738;
CpuOpaque* __cdecl bhkVelocityConstraintMotor_GetRTTI();
void __cdecl bhkLimitedForceConstraintMotor_LoadBinary(NiStream* ar, void* obj);
class hkObjCF46
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_kPointA;
    int m_kPointB;

    void SaveToArchive(NiStream* ar);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
unsigned int __cdecl Object_ForwardCall_00d87a40() throw();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
unsigned int __cdecl Object_ForwardCall_00d87a40() throw();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();
struct CC9F10Shape
{
    void FUN_00c90510();
};
struct FUN_00cf7490_class
{
    void j_hkReferencedObject_addReference();
};
void __cdecl FUN_00c905b0(void);
void __cdecl j_hkReferencedObject_removeReference(void);
struct hkOwnerCF74;
// 0x00cf74b0 orders these records by owner at +0, owner key at +0xD4, and subindex at +8.
struct OwnerSubindexEntry
{
    hkOwnerCF74* m_pOwnerObject;
    int unk04;
    unsigned int m_08;
};
struct hkOwnerCF74
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98;
    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0;
    unsigned int m_d4;
};
int __cdecl hkpWorldBodyOperationQueueSortCmp(const OwnerSubindexEntry& aEntryA, const OwnerSubindexEntry& aEntryB);
struct hkQualityCF74
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_priority;
};
struct hkEntityCF74
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    hkQualityCF74* m_quality;
};
struct hkPairCF74
{
    int unk00;
    hkEntityCF74* m_kPointA;
    hkEntityCF74* m_kPointB;
};
hkBool __cdecl LessThanPairPriority(const hkPairCF74& aPairA, const hkPairCF74& aPairB);
void* __cdecl Runtime_UpdateState_00cfb050(void* pvUnused, bool* pbOut, void* pvResult);
void nullsub_7();
int __cdecl Runtime_GetC(int a, int b, int c);
void __stdcall nullsub_59(int, int, int, int, int);
extern int DAT_0102e388;
struct FUN_00cfc590_class
{
    int* vtable;

    void __thiscall SetVtable();
};
extern int DAT_010cc86c;
struct S_00cfc5a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short unkA8;
    unsigned short unkAA;
};
struct FUN_00cfc5a0
{
    int* vtbl;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    S_00cfc5a0* unk10;
    S_00cfc5a0* unk14;
    unsigned short unk18;

    FUN_00cfc5a0(int a1, S_00cfc5a0* a2, S_00cfc5a0* a3);
};
void Object_DoNothing_00cfdb40();
// Per-thread profiler ring: TlsGetValue(index) -> buffer with head@+4 / end@+0xc,
// 0xc-byte events {tag, timestamp, pad}.
struct CE0020Event
{
    const char* m_pTag;
    unsigned int m_uiEventId;
    int m_unk08;
};
struct CE0020Buffer
{
    int m_unk00;
    CE0020Event* m_pHead;
    int m_unk08;
    CE0020Event* m_pRecordEnd;
};
extern unsigned int DAT_0126835c;
extern char DAT_010cb81c[];
extern char DAT_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
__forceinline void CE0020TimerMark(const char* pTag)
{
    CE0020Buffer* pBuffer = (CE0020Buffer*)TlsGetValue(DAT_0126835c);
    CE0020Event* pEvent = pBuffer->m_pHead;
    if (pEvent < pBuffer->m_pRecordEnd)
    {
        pEvent->m_pTag = pTag;
        _ReadWriteBarrier();
        volatile unsigned int uiStamp = (unsigned int)__rdtsc();
        pEvent->m_uiEventId = uiStamp;
        pBuffer->m_pHead = pEvent + 1;
    }
}
// 4-byte flags struct passed by value (bool first member).
class CE0020Flag
{
  public:
    bool m_bEnableState;
    unsigned char m_unk01;
    unsigned char m_unk02;
    unsigned char m_unk03;
};
class CE0020ZeroInfo
{
  public:
    int m_unk00;
    int m_iArrayLength;
};
class CE0020Holder
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Fill(CE0020Flag kFlags, CE0020ZeroInfo* pInfo);
};
class CE0020Arrays
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    float* m_pFloats;
};
class CE0020Target
{
  public:
    int unk00, unk04, unk08;
    CE0020Holder* m_pHolder;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    CE0020Arrays* m_pArrayData;
};
class CE0020Subject
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void EnableConstraints();
};
void __cdecl hkpWorldConstraintUtil_removeAndDeleteModifier(CE0020Target* pTarget, CE0020Subject* pSubject, int iType);
void __cdecl EnableConstraintsAndZeroArrays(CE0020Target* pTarget, CE0020Subject* pSubject);
void __cdecl Runtime_ProcessEntries_00ce2d10();
void __cdecl Runtime_ForwardCall_00ce2f30();
class SerializableCF42;
void __cdecl bhkLimitedForceConstraintMotor_SaveBinary(NiStream& kStream, SerializableCF42* pkObject);
class SerializableCF42
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned int m_uiValue1C;
    unsigned int m_uiValue20;

    void bhkPositionConstraintMotor_SaveBinary(NiStream& kStream);
};
// bhkVelocityConstraintMotor ctor (hkpVelocityConstraintMotor chain):
// vptr(0), memSizeAndFlags(4), referenceCount(6), motor type(8), min/max force, tau, damping, velocity-clamp bool.
const void* DAT_010cc0ec[];
extern "C" void _ReadWriteBarrier();
class FUN_00cf43b0
{
  public:
    const void** m_vftable;              // 0x00
    unsigned short m_usMemSizeAndFlags;  // 0x04
    unsigned short m_sReferenceCount;    // 0x06
    unsigned char m_motorType;           // 0x08
    char unk09;
    char unk0A;
    char unk0B;
    float m_fMinForce;        // 0x0c
    float m_fMaxForce;        // 0x10
    float m_fTau;             // 0x14
    float m_fMotorDamping;    // 0x18
    char m_useVelocityClamp;  // 0x1c

    FUN_00cf43b0();
};
class SerializableCF44;
void __cdecl bhkLimitedForceConstraintMotor_LoadBinary(NiStream& kStream, SerializableCF44* pkObject);
class SerializableCF44
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned char m_ucValue1C;

    void bhkVelocityConstraintMotor_LoadBinary(NiStream& kStream);
};
class CF4BC0SaverLoader
{
  public:
    virtual void DeleteThis(bool bFree);
    virtual void Unk_01();
    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    hkReferencedObject* m_pPointer;
};
struct TagState
{
    int oldTag;
    int newTag;
};
__forceinline TagState GetTag(int tag)
{
    TagState state = {g_iCF4BC0AllocTag, tag};
    return state;
}
struct AllocScope
{
    int saved;
    AllocScope(TagState t) : saved(t.oldTag)
    {
        g_iCF4BC0AllocTag = t.newTag;
    }
    ~AllocScope()
    {
        g_iCF4BC0AllocTag = saved;
    }
};
hkReferencedObject* __cdecl bhkConstraintManager_LoadBinary(NiStream& kStream);
void Runtime_DoNothing_00cf6d10();
class hkRefObjCF70 : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class ListenerCF70 : public hkRefObjCF70, public hkpBroadPhaseListener
{
  public:
    virtual void AddCollisionPair(void* pair);
    virtual void RemoveCollisionPair(void* pair);
};
class FUN_00cf7060
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC;
    ListenerCF70 m_kListener;

    ~FUN_00cf7060();
};
#include <xmmintrin.h>
extern const __m128 g_vectorConstantQuaternionIdentity;
struct __declspec(align(16)) CE5430Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void SetAllComponents(float f)
    {
        m_vComponents = _mm_set_ps1(f);
    }
};
struct __declspec(align(16)) CE5430Quaternion
{
    __m128 m_vec;

    void setIdentity()
    {
        m_vec = g_vectorConstantQuaternionIdentity;
    }
};

#include "../../include/hkQsTransform.h"

struct __declspec(align(16)) CE5430Pose
{
    short m_sIndex0;
    short m_sIndex1;
    short m_sIndex2;
    short m_sIndex3;
    int unk08;
    int unk0C;
    hkQsTransform m_kTransform0;
    hkQsTransform m_kTransform1;

    void SetIdentity();
};
struct __declspec(align(16)) hkVector4CE98
{
    __m128 m_vComponents;

    void operator=(const hkVector4CE98& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
struct hkElementCE98
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    hkVector4CE98 m_vector;
};
void __cdecl CopyVectors(hkElementCE98* pkDst, const hkElementCE98* pkSrc, int iCount);
struct FUN_00cf0820
{
    float field00;
    float field04;
    unsigned int unk08;
    unsigned int unk0c;
    __m128 field10;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    FUN_00cf0820(const FUN_00cf0820& input);
};
extern __declspec(align(16)) float DAT_01017d10[4];
extern float DAT_01017d00;
struct FUN_00cf08c0_VectorArray
{
    float* values;
    int count;
};
bool __cdecl bhkStream_IsEqual(const FUN_00cf08c0_VectorArray* left, const FUN_00cf08c0_VectorArray* right);
struct hkMatrixCF0
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
void __cdecl NiStream_ReadTransformColumns(NiStream* pkView, hkMatrixCF0* pkDest);
struct S00cf0cf0_Arr
{
    __m128* data;
    unsigned int count;
};
static unsigned int S00cf0cf0_SaveRaw(NiBinaryStream* s, const void* p, unsigned int n, unsigned int elemSize)
{
    unsigned int uiSize = elemSize;
    return s->m_pfnWrite(s, p, n * elemSize, &uiSize, 1);
}
int __cdecl bhkStream_SaveBinary(NiStream* self, S00cf0cf0_Arr* arr);
struct TargetType
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __m128 unk10;
    void* unk20;
    unsigned int unk24;
};
unsigned int NiStream_WriteObjectBuffer(NiStream& stream, TargetType* obj);
const char* __cdecl GetConstraintTypeName(int eType);
void __stdcall Object_DoNothing_00cf6d00(int);
extern void* DAT_010c63bc;
extern void* DAT_010cc4e0;
extern void* DAT_010cc4d0;
struct NodeBaseA
{
    void* m_vtbl;
    unsigned short m_04;
    unsigned short m_06;
    NodeBaseA()
    {
        m_06 = 1;
    }
};
struct NodeBaseB
{
    void* m_vtbl;
    NodeBaseB()
    {
        m_vtbl = &DAT_010c63bc;
    }
};
struct NodeObj : NodeBaseA, NodeBaseB
{
    NodeObj()
    {
        NodeBaseA::m_vtbl = &DAT_010cc4e0;
        NodeBaseB::m_vtbl = &DAT_010cc4d0;
    }
};
struct FUN_00cf6f90
{
    NodeBaseB* m_apSlots[8][8];
    NodeObj m_kDefault;
    FUN_00cf6f90();
};
void __stdcall Runtime_DoNothing_00cf8810(int a);
extern char DAT_010cc688[];
struct VecCFAD
{
    union
    {
        __m128 v;
        float f[4];
    };
};
struct InputCFAD
{
    VecCFAD vec;
    int unk10, unk14, unk18, unk1C;
    unsigned char enabled;
};
struct DescCFAD
{
    VecCFAD vec;
    void* data;
    void* extra;
    unsigned int size;
    unsigned int flags;
};
struct ContextCFAD
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
};
struct TargetCFAD;
struct SelfCFAD;
struct TargetCFAD
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C(DescCFAD*, SelfCFAD*, int);
};
struct SelfCFAD
{
    void* unk00;
    InputCFAD* input;
    void* extra;
    unsigned int flags;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* context;
    void UpdateFields_00cfad60(TargetCFAD*, InputCFAD*, void*, ContextCFAD*, unsigned int, unsigned int);
};
struct Cfd50Range
{
    int m_00;
    int* m_04;
    int m_08;
};
static int hkAgentNnMachine_getLastEntry(Cfd50Range* a);
extern "C" Cfd50Range* Cfd50Get(void);
extern "C" int Cfd50Sink(int);
void Cfd50Caller(void);
struct CE1700World
{
    void hkpWorld_removeConstraint(char* result, void* object);
    void RemoveEntities(void* owner, int flags);
};
struct CE1700Node
{
    int unk00;
    int unk04;
    CE1700World* world;
};
struct CE1700Owner
{
    int unk00;
    int unk04;
    CE1700Node** owner;
    int flags;
    int unk10;
    void** objects;
    int count;
    int ProcessEntries_00ce1700();
};
struct Slot_cfdb70
{
    void* m_p;
    int m_04;
};
struct Node_cfdb70
{
    char pad[0x50];
    Slot_cfdb70* m_slots;
};
struct Edge_cfdb70
{
    void* m_vtbl;
    unsigned short m_idxA;
    unsigned short m_idxB;
    int m_08;
    int m_0c;
    Node_cfdb70* m_kPointA;
    Node_cfdb70* m_kPointB;
};
static void LinkEdge(Edge_cfdb70* e);
void zz_probe_cfdb70(Edge_cfdb70* e);
struct BlockArr_cfd
{
    unsigned* m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    unsigned operator[](int i) const
    {
        return m_data[i];
    }
    const unsigned& at(int i) const
    {
        return m_data[i];
    }
};
struct BlockList_cfd
{
    unsigned m_lastSize;
    BlockArr_cfd m_kBlocks;
};
bool __cdecl IsAddressInBlock(const BlockList_cfd* list, unsigned addr);
inline hkMemoryAllocator& heap_cfde()
{
    return *reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_heap);
}
extern "C" void __cdecl hkArrayUtil__reduce(hkMemoryAllocator* alloc, void* array, int elemSize, void* storage, int capacity);
struct BlockArr_cfde
{
    char*& back()
    {
        return m_data[m_iElementCount - 1];
    }
    void popBack()
    {
        m_iElementCount--;
    }
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char* m_kStorage[1];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void OptimizeCapacity(int numFreeElemsLeft)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            unsigned c = m_iElementCount + numFreeElemsLeft - 1;
            c |= c >> 16;
            c |= c >> 8;
            c |= c >> 4;
            c |= c >> 2;
            c |= c >> 1;
            int newCap = c + 1;
            if (newCap < 1)
            {
                hkMemoryRouter* h = hkMemoryRouter_getInstance();
                hkArrayUtil__reduce(reinterpret_cast<hkMemoryAllocator*>(h->m_heap), this, sizeof(char*), m_kStorage, 1);
            }
            else if (newCap < getCapacity())
            {
                hkMemoryAllocator& a = heap_cfde();
                hkArrayUtil__reduce(&a, this, sizeof(char*), 0, newCap);
            }
        }
    }
};
struct BlockStack_cfde
{
    int m_uiBufferCapacity;
    BlockArr_cfde m_kBlocks;
};
static void hkMemoryRouter_UpdateState_00cfdeb0(BlockStack_cfde* s);
void zz_probe_cfdeb0(BlockStack_cfde* s);
// Havok: build index maps for a selection and propagate it through records and links (hkArray<hkInt16> maps).
typedef short hkInt16;
typedef unsigned short hkUint16;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
struct IndexSource
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int m_iStridedVertexCount;
};
struct SelRecord
{
    hkInt16 m_vFrom;
    hkUint16 m_vTo;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct SelLink
{
    hkUint16 m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};
hkBool __cdecl WalkChainUntilLimit(const IndexSource* src, int a, int b, hkArray<hkInt16>& out) throw();
struct Selection
{
    int unk00, unk04, unk08, unk0c;
    hkArray<hkInt16> m_ppIndices;
};
struct SelectionMapper
{
    int unk00, unk04, unk08, unk0c;
    IndexSource* m_pObservedSource;
    IndexSource* m_target;
    SelRecord* m_records;
    int m_numRecords;
    int unk20;
    SelLink* m_ppLinks;
    int m_numLinks;
    void MapSelection(const Selection& sel, hkArray<hkInt16>& sourceMap, hkArray<hkInt16>& targetMap,
                      hkArray<hkInt16>& output);
};
#include <xmmintrin.h>
#include <xmmintrin.h>
extern "C" bool __cdecl hkaSkeletonMapper_checkTransform(int mappingType, const FnvSpawnedObject* transform);
struct FUN_00cb1600
{
    void* vtable;
    void* writer;
    int flags;
    FUN_00cb1600(char*, int) throw();
    void __thiscall FUN_00cc00e0() throw();
    FUN_00cb1600& __thiscall ProcessAndReturnValue_00cc01c0(const char*) throw();
    FUN_00cb1600& __thiscall WriteName(const void*) throw();
};
struct CEError
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void report(int, unsigned int, const char*, const char*, int) throw();
};
extern int DAT_01268360;
extern const char DAT_010cba14, DAT_010cb9f8, DAT_010cb9d8, DAT_010cb9c4;
extern const char DAT_010cb9b0, DAT_010cb98c, DAT_010cb964, DAT_010cb8d0;
struct CEBoneName
{
    void* name;
    int flags;
};
struct CESkeleton
{
    int unk00;
    int unk04;
    int unk08;
    short* parents;
    int unk10;
    int unk14;
    CEBoneName* names;
    int count;
};
struct CESingle
{
    short source, target;
    int unk04, unk08, unk0c;
    FnvSpawnedObject transform;
};
struct CERange
{
    short startA, endA, startB, endB;
    int unk08, unk0c;
    FnvSpawnedObject transformA;
    FnvSpawnedObject transformB;
};
struct CEMap
{
    CESkeleton* a;
    CESkeleton* b;
    CESingle* singles;
    int singleCount;
    int unk10;
    CERange* ranges;
    int rangeCount;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int checker;
};
struct CEAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void free(void*, int) throw();
};
struct CECountArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int* m_pStackAllocation;
};
void __cdecl hkaSkeletonMapper_checkMappingLocalSpace(CEMap* map);
extern __m128 DAT_010c71b0;
extern float DAT_01012068;
struct MapperInitialization
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    unsigned char unk60;
    void __thiscall hkaSkeletonMapperData_hkaSkeletonMapperData();
};

#include <xmmintrin.h>

struct ElemA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_v;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};
struct ElemB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_v0;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    __m128 m_v1;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct ScaleObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ElemA* m_pA;
    int m_nCallbackId;
    int unk20;
    ElemB* m_pB;
    int m_nB;
};

// @fnv 0x00ce54c0
// src: GUESS 0x00ce54c0 (confidence: low)
void __cdecl Object_ProcessEntries_00ce54c0(ScaleObj* obj, float scale)
{
    for (int i = 0; i < obj->m_nCallbackId; i++)
    {
        __m128 s = _mm_load_ss(&scale);
        obj->m_pA[i].m_v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), obj->m_pA[i].m_v);
    }
    for (int i = 0; i < obj->m_nB; i++)
    {
        __m128 s = _mm_load_ss(&scale);
        obj->m_pB[i].m_v0 = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), obj->m_pB[i].m_v0);
        __m128 t = _mm_load_ss(&scale);
        obj->m_pB[i].m_v1 = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), obj->m_pB[i].m_v1);
    }
}

extern "C" void _ReadWriteBarrier();

struct ScalarValue
{
    __m128 v;
    ScalarValue(__m128 x) : v(x)
    {}
    __m128 splat() const
    {
        return _mm_shuffle_ps(v, v, 0);
    }
};
struct __declspec(align(16)) VectorValue
{
    __m128 v;
    void apply(const ScalarValue& s)
    {
        v = _mm_mul_ps(s.splat(), v);
    }
};
struct QsTransform
{
    VectorValue m_vTranslation;
    __m128 m_rotation;
    VectorValue m_vScale;
};

extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;

extern const __m128 DAT_010c71c0;
extern const __m128 DAT_010c71d0;

static __forceinline float LengthSquared4(__m128 v, float& out)
{
    v = _mm_mul_ps(v, v);
    __m128 s0 = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4E), v);
    __m128 s1 = _mm_add_ps(_mm_shuffle_ps(s0, s0, 0xB1), s0);
    _mm_store_ss(&out, s1);
    return out;
}

static __forceinline __m128 LengthSquared4v(__m128 v)
{
    v = _mm_mul_ps(v, v);
    __m128 s0 = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4E), v);
    return _mm_add_ps(_mm_shuffle_ps(s0, s0, 0xB1), s0);
}

static __forceinline void Normalize4(QsTransform* p)
{
    float dots[4];
    __declspec(align(16)) float len2[4];
    len2[0] = LengthSquared4(p[0].m_rotation, dots[0]);
    len2[1] = LengthSquared4(p[1].m_rotation, dots[1]);
    len2[2] = LengthSquared4(p[2].m_rotation, dots[2]);
    len2[3] = LengthSquared4(p[3].m_rotation, dots[3]);
    _ReadWriteBarrier();
    __m128 x = _mm_load_ps(len2);
    __m128 y0 = _mm_rsqrt_ps(x);
    __m128 ree = _mm_mul_ps(_mm_mul_ps(y0, x), y0);
    __m128 t = _mm_sub_ps(DAT_010c71c0, ree);
    y0 = _mm_mul_ps(y0, DAT_010c71d0);
    __m128 inv = _mm_mul_ps(t, y0);
    __m128 s0 = _mm_shuffle_ps(inv, inv, 0);
    p[0].m_rotation = _mm_mul_ps(s0, p[0].m_rotation);
    __m128 s1 = _mm_shuffle_ps(inv, inv, 0x55);
    s1 = _mm_shuffle_ps(s1, s1, 0);
    p[1].m_rotation = _mm_mul_ps(s1, p[1].m_rotation);
    __m128 s2 = _mm_shuffle_ps(inv, inv, 0xAA);
    s2 = _mm_shuffle_ps(s2, s2, 0);
    __m128 s3 = _mm_shuffle_ps(inv, inv, 0xFF);
    p[2].m_rotation = _mm_mul_ps(s2, p[2].m_rotation);
    _ReadWriteBarrier();
    s3 = _mm_shuffle_ps(s3, s3, 0);
    p[3].m_rotation = _mm_mul_ps(s3, p[3].m_rotation);
}

// @fnv 0x00ce4e20
// src: GUESS 0x00ce4e20 (confidence: low)
void __cdecl Object_ProcessEntries_00ce4e20(QsTransform* xforms, const float* volatile weights, unsigned int count)
{
    unsigned int i = 0;
    if (count > 0)
    {
        const float* input = weights;
        __m128 one = _mm_load_ss(&DAT_01012068);
        QsTransform* scaled = xforms;
        do
        {
            ScalarValue inv(_mm_div_ss(_mm_load_ss(&one.m128_f32[0]), _mm_load_ss(input + i)));
            scaled->m_vTranslation.apply(inv);
            scaled->m_vScale.apply(inv);
            ++i;
            ++scaled;
        } while (i < count);
    }

    unsigned int n4 = count >> 2;
    QsTransform* batch = xforms;
    if (n4 > 0)
    {
        do
        {
            Normalize4(batch);
            batch += 4;
        } while (--n4);
    }

    unsigned int rem = count & 3;
    if (rem > 0)
    {
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 half = _mm_set_ss(DAT_01016248);
        unsigned int n = rem;
        do
        {
            __m128 v = batch->m_rotation;
            __m128 len2 = LengthSquared4v(v);
            __m128 y0 = _mm_rsqrt_ss(len2);
            __m128 ree = _mm_mul_ss(_mm_mul_ss(len2, y0), y0);
            __m128 refined = _mm_mul_ss(_mm_mul_ss(half, y0), _mm_sub_ss(three, ree));
            __m128 factor = _mm_andnot_ps(_mm_cmpeq_ss(len2, zero), refined);
            factor = _mm_shuffle_ps(factor, factor, 0);
            batch->m_rotation = _mm_mul_ps(factor, v);
            ++batch;
        } while (--n);
    }
}
