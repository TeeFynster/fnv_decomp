#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/staging/blk_00ce0000_o2_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00ce0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00ce0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiStream.h"
#include "../../include/hkBool.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkVector4.h"
#include "../../include/MemoryManager.h"
#include "../../include/hkBaseObject.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkpBroadPhaseListener.h"
#include "../../include/hkMultiThreadCheck.h"
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
void __cdecl hkStatisticsCollectorUtil_addClassContentsAll_00cf6950(int a, int b);
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
void __cdecl hkaSkeletonMapper_mapExtractedMotion(int param_1, int param_2, int param_3);
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
void* __cdecl FindKeyRecord(unsigned short aKey, FUN_00ce5480_cls* pBox);
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
void __cdecl CallVirtualMethodWithOne(FUN_00ce9820_vt* p);
struct Stream;
typedef int (*StreamIOFunc)(Stream* stream, void* data, int size, int* count, int flag);
struct Stream
{
    int unk00;
    int pos;
    int unk08;
    StreamIOFunc io;
};
struct StreamOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    Stream* stream;
};
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
static inline void WriteData(Stream* s, void* data, int size)
{
    int count = size;
    s->pos += s->io(s, data, size, &count, 1);
}
void bhkPoseArray_bhkPose_SaveBinary(StreamOwner* owner, Record* rec);
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
template <class T> inline void NiStreamSaveBinaryCF46(NiBinaryStream& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}
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
unsigned int __cdecl Object_ForwardCall_00d87a40() throw();
unsigned int __cdecl Object_ForwardCall_00d87a40() throw();
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
hkBool __cdecl LessThanPairPriority(const hkPairCF74& x, const hkPairCF74& y);
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
template <class T> inline void NiStreamLoadBinaryCF42(NiBinaryStream& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}
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
template <class T> inline void NiStreamLoadBinaryCF44(NiBinaryStream& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}
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
extern const __m128 DAT_010c71c0;
extern const __m128 DAT_010c71d0;

struct SimdReal
{
    __m128 m_vValue;
    __forceinline SimdReal(__m128 r) : m_vValue(r)
    {}
    __forceinline operator __m128() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
};

__forceinline hkVector4::hkVector4()
{}

__forceinline SimdReal hkVector4::lengthSquared3SimdCall() const
{
    __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    return SimdReal(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s));
}

__forceinline void hkVector4::setXYZ_W(__m128 xyz, __m128 w)
{
    m_vComponents = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, w), 0xc4);
}

__forceinline void hkVector4::setSqrtInverse4(const hkVector4& v)
{
    __m128 e = _mm_rsqrt_ps(v.m_vComponents);
    __m128 he = _mm_mul_ps(DAT_010c71d0, e);
    __m128 ree = _mm_mul_ps(_mm_mul_ps(e, v.m_vComponents), e);
    m_vComponents = _mm_mul_ps(_mm_sub_ps(DAT_010c71c0, ree), he);
}

// @fnv 0x00ce2a50
// src: GUESS 0x00ce2a50 (confidence: low)
static __declspec(noinline) void hkVector4_ComputeValues_00ce2a50(hkVector4* a, hkVector4* b)
{
    hkVector4 len2;
    SimdReal la = a->lengthSquared3SimdCall();
    SimdReal lb = b->lengthSquared3SimdCall();
    len2.setXYZ_W(la, lb);
    hkVector4 inv;
    inv.setSqrtInverse4(len2);
    __m128 x = _mm_shuffle_ps(inv.m_vComponents, inv.m_vComponents, 0x00);
    a->m_vComponents = _mm_mul_ps(x, a->m_vComponents);
    __m128 w = _mm_shuffle_ps(inv.m_vComponents, inv.m_vComponents, 0xff);
    b->m_vComponents = _mm_mul_ps(_mm_shuffle_ps(w, w, 0), b->m_vComponents);
}

void CallerX(hkVector4* a, hkVector4* b)
{
    hkVector4_ComputeValues_00ce2a50(a, b);
}

struct SubMatrix
{
    __m128 m_row[4];
    void hkRotation_set(const float* pQuat);
};

struct TransformOwner
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
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    SubMatrix m_matrix;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    __m128 m_vec140;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    __m128 m_quat170;
};

extern "C" TransformOwner* cf8b60_self(void);
extern "C" __m128* cf8b60_quat(void);

// @fnv 0x00cf8b60
// src: GUESS 0x00cf8b60 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00cf8b60(TransformOwner* self, __m128* pQuat)
{
    SubMatrix* m = &self->m_matrix;
    m->hkRotation_set((const float*)pQuat);
    __m128 q = self->m_quat170;
    __m128 v = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(1, 1, 1, 1)), m->m_row[1]);
    v = _mm_add_ps(v, _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(0, 0, 0, 0)), m->m_row[0]));
    v = _mm_add_ps(v, _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(2, 2, 2, 2)), m->m_row[2]));
    m->m_row[3] = _mm_sub_ps(self->m_vec140, v);
}

void cf8b60_caller(void)
{
    Object_UpdateFields_00cf8b60(cf8b60_self(), cf8b60_quat());
}

struct ResultByte
{
    char value;
    __forceinline ResultByte(bool b) : value(b)
    {}
};
struct ScalarValue
{
    __m128 packed;
    __forceinline ScalarValue(__m128 x) : packed(x)
    {}
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, packed);
        return f;
    }
};
struct VectorValue
{
    __m128 packed;
    __forceinline void subtract(const VectorValue& a, const VectorValue& b)
    {
        packed = _mm_sub_ps(a.packed, b.packed);
    }
    __forceinline void cross(const VectorValue& a, const VectorValue& b)
    {
        packed =
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.packed, a.packed, 201), _mm_shuffle_ps(b.packed, b.packed, 210)),
                       _mm_mul_ps(_mm_shuffle_ps(a.packed, a.packed, 210), _mm_shuffle_ps(b.packed, b.packed, 201)));
    }
    __forceinline ScalarValue dot(const VectorValue& b) const
    {
        __m128 products = _mm_mul_ps(packed, b.packed);
        __m128 first = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
        return ScalarValue(_mm_add_ss(_mm_shuffle_ps(products, products, 170), first));
    }
};
extern double DAT_01032980;
// @fnv 0x00ceb6f0
// src: GUESS 0x00ceb6f0 (confidence: low)
ResultByte Runtime_UpdateState_00ceb6f0(float& outT, float& outU, float& outV, const VectorValue& position,
                        const VectorValue& direction, const VectorValue& a, const VectorValue& b, const VectorValue& c,
                        bool cull)
{
    VectorValue e1, e2, p;
    e1.subtract(b, a);
    e2.subtract(c, a);
    p.cross(direction, e2);
    float determinant = p.dot(e1);
    if (cull)
    {
        if (determinant < DAT_01032980)
            return false;
    }
    else
    {
        if (determinant > (double)-0.0001f && determinant < DAT_01032980)
            return false;
    }
    float inverse = 1.0f / determinant;
    VectorValue offset;
    offset.subtract(position, a);
    outU = offset.dot(p);
    if (outU < 0.0f || outU > determinant)
        return false;
    VectorValue q;
    q.cross(offset, e1);
    outV = direction.dot(q);
    if (outV < 0.0f || outU + outV > determinant)
        return false;
    outT = q.dot(e2);
    outT *= inverse;
    outU *= inverse;
    outV *= inverse;
    return true;
}
