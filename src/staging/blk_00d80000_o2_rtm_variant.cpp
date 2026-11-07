// Exe 0x00d84c50 SIMD helper: define the native view before FourFloatVector forward declarations.
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
// src/staging/blk_00d80000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d80000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include <stdlib.h>
#define FNV_FOURFLOATVECTOR_NO_SSE
// local form of hkVector4: 0x00d86ec0 needs packed storage before this unit declares its own intrinsic type.


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class ConstraintPacketLocal_00d8
{
public:
#if defined(FNV_FOURFLOATVECTOR_NO_SSE)
    union Components
    {
        float m128_f32[4];
        unsigned __int64 m128_u64[2];
        signed char m128_i8[16];
        short m128_i16[8];
        int m128_i32[4];
        __int64 m128_i64[2];
        unsigned char m128_u8[16];
        unsigned short m128_u16[8];
        unsigned int m128_u32[4];
    };
#else
    typedef __declspec(align(4)) __m128 Components;
#endif

    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        Components m_vComponents;
        Components m;
        float f[4];
        Components values;
        Components q;
        Components value;
        Components quad;
        float elements[4];
        float m_fComponents[4];
    };

    ConstraintPacketLocal_00d8();
    ConstraintPacketLocal_00d8(float x, float y, float z, float w);
    ConstraintPacketLocal_00d8(const __m128& vector);

    ConstraintPacketLocal_00d8* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(ConstraintPacketLocal_00d8* vector);
    void __thiscall SetQuaternionComponentsFromVector(const ConstraintPacketLocal_00d8* vector);
    ConstraintPacketLocal_00d8& ComputeValue_00e531a0(int parameter);
    ConstraintPacketLocal_00d8 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const ConstraintPacketLocal_00d8& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const ConstraintPacketLocal_00d8& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const ConstraintPacketLocal_00d8& vector);
    void Sub(const ConstraintPacketLocal_00d8& vector);
    void Cross(const ConstraintPacketLocal_00d8& a, const ConstraintPacketLocal_00d8& b);

    void setAbs4(const ConstraintPacketLocal_00d8& vector);
    void setMul4(const SimdReal& scalar, const ConstraintPacketLocal_00d8& vector);
    void addMul4(const SimdReal& scalar, const ConstraintPacketLocal_00d8& vector);
    void setAddMul4(const ConstraintPacketLocal_00d8& a, const ConstraintPacketLocal_00d8& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const ConstraintPacketLocal_00d8& vector);
    void setAddMul(const ConstraintPacketLocal_00d8& a, const ConstraintPacketLocal_00d8& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const ConstraintPacketLocal_00d8& vector);
    void transformed(const Transform& transform, const ConstraintPacketLocal_00d8& vector);
    void addScaled(const ConstraintPacketLocal_00d8& base, const ConstraintPacketLocal_00d8& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#undef FNV_FOURFLOATVECTOR_NO_SSE
#define FNV_TRANSFORM_NO_SSE
#include "../../include/Transform.h"
#undef FNV_TRANSFORM_NO_SSE
#include "../../include/hkJobType.h"

// src/staging/blk_00d80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/AutoMemContext.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkpConstraintInstance.h"
#include "../../include/hkpConstraintListener.h"
#include "../../include/hkArray.h"
#include "../../include/hkBool.h"
#include "../../include/hkStatisticsCollector.h"
#include "../../include/hkpCdBody.h"
#include "../../include/hkpCollisionDispatcher.h"
// hkpTaskHeader_blk_00d80000_o2_rtm_variant: local type (was include/hkpTaskHeader.h, which had no evidence of one real class); no method of it is bound to a named game function
class hkpTaskHeader_blk_00d80000_o2_rtm_variant {
public:
    int unk00;
    int m_iJobId;
};
extern int DAT_010cc4f4;
void __cdecl Runtime_UpdateState_00d9f6d0(int* p);
struct FUN_00d85300_Stub {
    void ComputeValue_00d85300(int*);
};
struct FUN_00d85a20_Stub : FUN_00d85300_Stub {
    int* CopyStateFrom(int* p);
};
extern char DAT_01267e30;
class FNVDispatchNode {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual unsigned int v08();

    FNVDispatchNode* Resolve();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FNVDispatchNode* m_18;
};
char* GetDispatchTarget(FNVDispatchNode* pNode);
struct AllocIface {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkString_memCpy(void* dst, const void* src, unsigned int size);
struct FUN_00d85360_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;

    FUN_00d85360_cls* FUN_00d54290();
};
FUN_00d85360_cls* __cdecl hkpConstraintDataUtils_copyAtoms_hkpBallAndSocketConstraintData_(int pSource);
struct S_00d85af0_Base {
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
    void ComputeValue_00d85300(const S_00d85af0_Base* o);
};
struct S_00d85af0_V3 { float x, y, z; };
struct S_00d85af0_Cls : S_00d85af0_Base {
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    S_00d85af0_V3 unkb4;
    S_00d85af0_Cls* AssignFrom(const S_00d85af0_Cls* o);
};
struct CpuOpaque;
extern CpuOpaque DAT_01269514;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00d9f6c0();
extern int DAT_010cc4f4;
unsigned int __cdecl Object_ComputeValue_00d9f6e0();
// Havok object clone: allocate a default instance and copy the payload (everything after the header).
struct D85660Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
extern "C" hkMemoryRouter& __cdecl D85660GetMemoryRouter() throw();
void __cdecl D85660MemCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();
class D85660Object {
public:
    D85660Object() throw();
    virtual ~D85660Object();

    static void* operator new(unsigned int nbytes) throw()
    {
        D85660Object* p = static_cast<D85660Object*>(reinterpret_cast<D85660Allocator*>((&D85660GetMemoryRouter().heap()))->AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int m_iData010;
    int m_iData014;
    int m_iData018;
    int m_iData01C;
    int m_iData020;
    int m_iData024;
    int m_iData028;
    int m_iData02C;
    int m_iData030;
    int m_iData034;
    int m_iData038;
    int m_iData03C;
    int m_iData040;
    int m_iData044;
    int m_iData048;
    int m_iData04C;
    int m_iData050;
    int m_iData054;
    int m_iData058;
    int m_iData05C;
    int m_iData060;
    int m_iData064;
    int m_iData068;
    int m_iData06C;
    int m_iData070;
    int m_iData074;
    int m_iData078;
    int m_iData07C;
    int m_iData080;
    int m_iData084;
    int m_iData088;
    int m_iData08C;
    int m_iData090;
    int m_iData094;
    int m_iData098;
    int m_iData09C;
};
D85660Object* __cdecl copyConstraintAtoms_class_hkpHingeLimitsData(const D85660Object* pkSource);
extern int DAT_010d3838;
struct FUN_00d86260_Class {
    unsigned int m_vptr;
    unsigned short m_word04;
    unsigned short m_word06;
    volatile unsigned char m_byte08;
    volatile float m_float0C;
    float m_float10;
    float m_float14;
    float m_float18;
    FUN_00d86260_Class(float a, float b, float c);
};
struct Struct40 {
    int m_00, m_04, m_08, m_0c;
    int m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c;
};
struct TargetData {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c;
    char unk20;
    char unk21;
    short unk22;
    int unk24, unk28, unk2c;
    Struct40 unk30;
    Struct40 unk70;
};
struct FUN_00d53200_class {
    int unk00;
    void hkConstraintCinfo_LoadBinary(NiStream&) throw();
};
struct Derived_00d53200 : public FUN_00d53200_class {
    TargetData* unk04;
    void ReadFromStream(NiStream& stream);
};
struct BinaryReader {
    void* vtable;
    unsigned int currentPosition;
    unsigned int reserved08;
    unsigned int (__cdecl *Read)(BinaryReader* stream, void* dst, unsigned int bytes, unsigned int* componentBytes, unsigned int components);

    unsigned int BinaryRead(void* destination, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        unsigned int readBytes = Read(this,destination,bytes,&componentSize,1);
        currentPosition += readBytes;
        return readBytes;
    }
};
struct DataStream {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    BinaryReader* input;
};
struct Record {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int header;
    unsigned int flag;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int data30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int words40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int words70;
};
void __stdcall hkConstraintCinfo_SaveBinary(DataStream* stream);
struct DataOwner {
    unsigned int unknown00;
    Record* record;
    void ReadRecord(DataStream* stream);
};
inline int countBitsSetD866(unsigned int n)
{
    n = ((n >> 1) & 0x55555555) + (n & 0x55555555);
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0f0f0f0f) + (n & 0x0f0f0f0f);
    n = ((n >> 8) & 0x000f000f) + (n & 0x000f000f);
    return (n & 0xff) + (n >> 16);
}
int __cdecl CountBitsInWords(const unsigned int* puiWords, int iNumWords);
int __cdecl j_strncmp(const char*, const char*, unsigned int);
const char* __cdecl hkString_strRchr(const char*, int);
const char* __cdecl hkString_strChr(const char*, int);
struct TypeEntry {
    const char* name;
    int unk04;
    int unk08;
};
extern TypeEntry DAT_011b6ab4[];
extern TypeEntry DAT_011b6c4c[];
struct StringBuf {
    char* m_kStringBuffer;
    int m_fRestLength;
    int m_iCapacityState;
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

    void FUN_00d61a50(const char* s);
    void FUN_00d61fc0(int from, int len);
    int Object_ForwardCall_00d616e0(const char* other);
    void UpdateFields_00cbbd40();
};
int __cdecl GetTypeCode(const char* typeName);
struct B { char pad[0x12]; unsigned short w12; };
struct S {
    unsigned int m0;
    B* m4;
    void SetValueAndPtr(unsigned int a, B* b);
};
struct D871A0Buffer {
    void append(const void* p, int a, int b);
};
struct FUN_00d871c0_class {
    FUN_00d871c0_class* Append(FUN_00d871c0_class* a, int b, const void* p);
};
struct TargetClass {
    void* Append(int a, int b, int c);
};
struct MemberClass {
    int FUN_00d86910();
};
struct FUN_00d87380_Class {
    int unk00;
    MemberClass* unk04;

    TargetClass* CallTargetMethod(TargetClass* target, int arg2);
};
struct FUN_00d86910_Obj {
    int __thiscall FUN_00d86910();
};
struct FUN_00d873b0_Obj {
    void __thiscall FUN_00d873b0(int a, int b);
};
struct FUN_00d873f0_Holder {
    int unk00;
    FUN_00d86910_Obj* unk04;
    FUN_00d873b0_Obj* __thiscall hkClassMemberAccessor_object(FUN_00d873b0_Obj* a);
};
class hkSetD874 {
public:
    int* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator() const;
};
struct FUN_00d87910_cls {
    int m_00;

    FUN_00d87910_cls* hkThread_hkThread();
};
extern "C" unsigned int (__stdcall *DAT_00fdf1d0)();
unsigned __int64 __cdecl Object_ForwardCall_00d87a40();
void __cdecl hkThread_stopThread();
void __cdecl hkThread_stopThread_ForwardCall_00d87a70();
struct FUN_00d87a80_Stub {
    void* GetSelf_00d87a80(int);
};
void __cdecl Runtime_DoNothing_00d87a90();
extern int DAT_010d3cc0;
D85660Object* __cdecl CreateD85660Object();
class FUN_00d88050 {
public:
    FUN_00d88050();

    bool m_bModifierActive;
    int m_iValue;
    bool m_bValueAt0C;
};
void __cdecl Object_DoNothing_00d88060();
struct AllocIfaceFree : AllocIface
{
    virtual void Free(void* block, unsigned int size);
};
extern void* DAT_012691fc;
void __cdecl FreeGlobalBlock();
struct FUN_00d880d0 {
    unsigned char m_kPointB;
    int m_i;
    void M_00d880d0();
};
void __cdecl Object_DoNothing_00d880e0();
struct FUN_00d880f0_Class {
    int unk00;
    int unk04;
    unsigned char unk08;

    void SetUnk08(unsigned char val);
};
struct DispatchTarget {
    virtual void Event0();
    virtual void Event1();
    virtual void Event2();
    virtual void Event3();
    virtual void Event4();
    virtual void Event5();
    virtual void Event6();
    virtual void Dispatch(int argument);
};
void __cdecl InvokeDispatch(void* context, DispatchTarget** target, void* reserved, int argument);
class hkTargetD922B {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void process(void* a, void* b, void* c, void* d);
};
void __cdecl hkAgent3Bridge_updateFilter(void* pvContext, hkTargetD922B** ppkTarget, void* a, void* b, void* c, void* pvUnused, void* d);
// 0x00d92230 reads an agent pointer at +0; the agent entry header consists of four byte fields.
struct Agent2PointerPayload {
    void* m_pCollisionAgent;
};
void __cdecl AddChildAgent2ToCollector(void* pvContext, const Agent2PointerPayload* pkEntry, void* pvUnused, hkStatisticsCollector* pkCollector);
class FUN_00d92250_obj {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9(int iValue);
};
struct FUN_00d92250_holder {
    FUN_00d92250_obj* m_object;
};
void __cdecl CallObjectVirtual(void* pvUnused, FUN_00d92250_holder* pkHolder, int iValue);
struct FUN_00d92270_Dispatch
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual int v10(float a, float b, int c) = 0;
};
int DispatchVirtualCall(int aiUnused, FUN_00d92270_Dispatch** a2, float afArg1, float afArg2, int aiArg3);
class hkTargetD92A {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void process(void* pvData);
};
void __cdecl hkAgent3Bridge_removePoint(void* pvContext, hkTargetD92A** ppkTarget, void* pvData);
class hkTargetD922 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void process(void* pvData);
};
void __cdecl hkAgent3Bridge_commitPotential(void* pvContext, hkTargetD922** ppkTarget, void* pvData);
struct FUN_00d922e0_Iface {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void* unk34(int arg);
};
void* __cdecl CallIfaceMethod(int unused, FUN_00d922e0_Iface** p, int arg);
struct FUN_00d92380_obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b, int c, int d);
};
struct FUN_00d92380_vec {
    int a0;
    int a4;
    int a8;
    int ac;
};
struct FUN_00d92380_holder {
    FUN_00d92380_obj* m0;
    int m4;
    int m8;
    int mc;
    int m10;
};
int* __cdecl CallVirtualWithVectorArgs(FUN_00d92380_vec* pVec, int u1, FUN_00d92380_holder* pHolder, int u2, int arg);
struct FUN_00d93310_cls {
    int m_00;
    int m_04;
    int m_08;

    FUN_00d93310_cls* hkpFixedSizePhysicsCommandQueue_256_hkpFixedSizePhysicsCommandQueue_256();
};
extern "C" {
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
    extern unsigned int DAT_0126835c;
    void __cdecl Object_ProcessAndReturnValue_00d89f80(void* p, int a2, int a3, int a4, bool* pb);
}
struct TargetObj {
    int dummy;
};
struct SubObj {
    int unk_000; int unk_004; int unk_008; int unk_00c; int unk_010; int unk_014; int unk_018; int unk_01c;
    int unk_020; int unk_024; int unk_028; int unk_02c; int unk_030; int unk_034; int unk_038; int unk_03c;
    int unk_040; int unk_044; int unk_048; int unk_04c; int unk_050; int unk_054; int unk_058; int unk_05c;
    int unk_060; int unk_064; int unk_068; int unk_06c; int unk_070; int unk_074; int unk_078; int unk_07c;
    int unk_080; int unk_084; int unk_088; int unk_08c; int unk_090; int unk_094; int unk_098; int unk_09c;
    int unk_0a0; int unk_0a4; int unk_0a8; int unk_0ac; int unk_0b0; int unk_0b4; int unk_0b8; int unk_0bc;
    int unk_0c0; int unk_0c4; int unk_0c8; int unk_0cc; int unk_0d0; int unk_0d4; int unk_0d8; int unk_0dc;
    int unk_0e0; int unk_0e4; int unk_0e8; int unk_0ec; int unk_0f0; int unk_0f4; int unk_0f8; int unk_0fc;
    int unk_100; int unk_104; int unk_108; int unk_10c; int unk_110; int unk_114; int unk_118; int unk_11c;
    int unk_120; int unk_124; int unk_128; int unk_12c; int unk_130; int unk_134; int unk_138; int unk_13c;
    int unk_140; int unk_144; int unk_148; int unk_14c; int unk_150; int unk_154; int unk_158; int unk_15c;
    int unk_160; int unk_164; int unk_168; int unk_16c; int unk_170; int unk_174; int unk_178; int unk_17c;
    int unk_180; int unk_184; int unk_188; int unk_18c; int unk_190; int unk_194; int unk_198; int unk_19c;
    int unk_1a0; int unk_1a4; int unk_1a8; int unk_1ac; int unk_1b0; int unk_1b4; int unk_1b8; int unk_1bc;
    int unk_1c0; int unk_1c4; int unk_1c8; int unk_1cc; int unk_1d0; int unk_1d4; int unk_1d8; int unk_1dc;
    TargetObj unk1e0;
};
struct Arg0 {
    SubObj* m_pSub;
};
struct Arg2 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    int unk24;
    int unk28;
    char unk2c;
};
struct Arg1 {
    void ProcessCallback(Arg2* a1, Arg2* a2, int a3);
};
void LogIntegrateVelocity(Arg0* a1, Arg1* a2, Arg2* a3);
extern "C" char str_010d4030[];
void __cdecl hkStringBuf_printf(unsigned int* result, char* text, double d0,
                          int value0, double d1, int value1, double d2);
unsigned int __cdecl hkVector4Util_toString3(float* values, unsigned int* result, signed char value);
void __cdecl hkStringBuf_printf(...);
struct FUN_00d97680_Vec {
    float x;
    float y;
    float z;
    float w;
};
int __cdecl FormatVec4(FUN_00d97680_Vec* v, int* dst, char acSeparator);
struct hkRecordD983 {
    float m_00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;

    hkRecordD983()
    {
        m_00 = 1.0f;
        m_04 = -1;
        m_30 = 0;
        m_10 = -1;
    }
};
struct FUN_00d98390 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkRecordD983 m_records[4];

    FUN_00d98390();
};
void __cdecl Runtime_ProcessEntries_00d98630(void*, void*, void*, void*);
void* __cdecl hkKdTreeUtils_isValidRayBundle(void* a1, void* a2, void* a3, void* a4);
struct FNV_00d99f50_Entry { void* value; void* payload; };
struct FNV_00d99f50_Result {
    unsigned char flag;
    FNV_00d99f50_Result() {}
    ~FNV_00d99f50_Result() {}
};
extern "C" void __cdecl hkKdTreeUtils_castRayIterative(unsigned char* scratch, const FNV_00d99f50_Entry* entry, void* context, void* left, void* right);
FNV_00d99f50_Result __cdecl hkKdTreeUtils_castRayMultiTree(int count, const FNV_00d99f50_Entry* const* entries, void* context, void* left, void* right);
struct FUN_00d9a4a0_Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct FUN_00d9a4a0_Float {
    float unk00;
    float unk04;
};
struct FUN_00d9a4a0_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d9a4a0_Float* unk10;

    void __thiscall InvokeCallback(int a1);
};
float __fastcall Object_ProcessAndReturnValue_00d9a4a0( FUN_00d9a4a0_Obj* self, int unused, FUN_00d9a4a0_Param* param);
struct IdxStand_ {
    char* m_iWordAt00;
    void* ComputeValue_00d9a4c0(int idx);
};
struct FUN_00d9a4d0_Class {
    int unk00;

    int __thiscall GetEntryOffset(unsigned short value);
};
struct FnvCpu_FUN_00d9f6b0_CpuInterface {
    virtual void Invoke(int value);
};
void __cdecl Runtime_ForwardCall_00d9f6b0(FnvCpu_FUN_00d9f6b0_CpuInterface* object);
extern char DAT_0102e388;
struct FUN_00d9fb30_Stub {
    void SetVtableAndProcessState_00d9fb30();
};
void __stdcall Object_UpdateFields_00d9fb40(unsigned char* output, int unused1);
void __stdcall nullsub_68(int);
void __stdcall nullsub_69(int, int, int);
void __stdcall nullsub_70(int);
void __stdcall nullsub_71(int);
void __stdcall nullsub_72(int);
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D85TlsFn)(unsigned long);
extern D85TlsFn DAT_00fdf044;
struct D85Ctn {
    void** entries;
    unsigned short count;
};
struct D85Ev {
    unsigned int tag;
    unsigned int time;
    int unk08;
};
struct D85Prof {
    int unk00;
    D85Ev* head;
    int unk08;
    D85Ev* end;
};
struct D85A0 {
    int unk00;
    unsigned int unk04;
};
struct D85Msg {
    D85A0* p;
};
struct D85Node5 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(D85Msg m);
};
// src: GUESS 0x00d85d40 (confidence: low)
static __declspec(noinline) D85Ctn* Object_ProcessEntries_00d85d40(D85Ctn* c) {
    for (int i = c->count - 1; i >= 0; --i) {
        if (c->entries[i] != 0) continue;
        c->count -= 1;
        unsigned int cnt = c->count;
        if (i < (int)cnt) {
            for (int j = i; j < (int)cnt; ++j)
                c->entries[j] = c->entries[j + 1];
        }
    }
    return c;
}
void __cdecl hkpConstraintCallbackUtil_fireConstraintBroken(D85Msg a);
template <class T>
inline void NiStreamSaveBinaryD861(NiBinaryStream& kStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
// 0x00d86100/0x00d86160 serialize words at +0x0C/+0x10; shared Data is only 0x10 bytes.
struct SerializedWordPairPayload {
    int unk00[3];
    unsigned int m_0c;
    unsigned int m_10;
};
void __cdecl bhkLimitedForceConstraintMotor_LoadBinary(NiStream& kStream, SerializedWordPairPayload* pkData);
template <class T>
inline void NiStreamLoadBinaryD8616(NiBinaryStream& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, sizeof(T), &uiSize, 1);
}
void __cdecl bhkLimitedForceConstraintMotor_SaveBinary(NiStream& kStream, SerializedWordPairPayload* pkData);
extern int DAT_010d3838;
struct FUN_00d86220_Class {
    unsigned int m_vptr;
    unsigned short m_word04;
    unsigned short m_word06;
    volatile unsigned char m_byte08;
    volatile float m_float0C;
    float m_float10;
    float m_float14;
    float m_float18;
    FUN_00d86220_Class();
};
extern __declspec(thread) unsigned int tlsArr[0xb0];
void __cdecl Object_UpdateFields_00c9eae0(void* p);
struct FUN_00dee750 {
    void* m_vptr;
    unsigned short m_usMemorySizeAndFlags;
    short m_sReferenceCount;
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
    int unka8;
    int unkac;

    static void* operator new(unsigned int sz)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        AllocIface* alloc = reinterpret_cast<AllocIface*>(holder->m_heap);
        void* p = alloc->Alloc(sz);
        ((FUN_00dee750*)p)->m_usMemorySizeAndFlags = (unsigned short)sz;
        return p;
    }
    static void operator delete(void* p) { Object_UpdateFields_00c9eae0(p); }

    FUN_00dee750();
};
struct FUN_00d86470_cls {
    int unk00;
    FUN_00dee750* m_04;

    unsigned int hkPointToPathConstraintCinfo_CreateData();
};
struct Cls00d86950 {
    int unk00;
    int unk04;
    int unk08;
    int GetUnk08();
};
struct S_00d87a60 {
    int m_uiFilterValue;
    int GetValue();
};
extern void* DAT_012691fc;
void* __cdecl Object_GetDAT_012691fc_00d880a0();
class FUN_00d88100_Class {
public:
    bool m_bTriggered;
    char unk01;
    char unk02;
    char unk03;
    int m_iArrayLength;
    bool m_bEnableState;
    bool m_abFlags[3];

    bool hkMemoryExceptionTestingUtil_isMemoryAvailableImpl(int iIndex);
};
struct S00d881a0_Leaf {
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
    int m78;
};
struct S00d881a0_Mid {
    int unk00;
    int unk04;
    S00d881a0_Leaf* m08;
};
struct S00d881a0_Obj {
    S00d881a0_Mid* m00;
};
int __cdecl hkRigidMotionUtilApplyAccumulators(void* a0, void* a1, void* a2, void* a3, void* a4, int a5);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(int a0, void* a1, void* a2);
static int hkConstraintSolverSetup_integrate2(void* p, void* ecxv, char* eaxv, S00d881a0_Obj* esi, void* edi);
int S00d881a0_Wrap(void* p);
static unsigned char* S00d96870_outp;
static void spawnBuildJacobiansJobs(unsigned char* self, int* src, unsigned char* out);
void __fastcall S00d96870_Entry(unsigned char* self, int* src);
// Exe 0x00d84c50 SIMD helper: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);
struct D99FC0Quad { int a; int b; int c; int d; };
struct D99FC0Object {
    void* unk00;
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
    D99FC0Quad q30;
    LocalM128 v40;
};
void __cdecl IntersectTree(int a1, int a2, int a3, float* a4, int* a5,
                          int a6, int a7, float a8, float a9, float a10, int a11);
void __cdecl ComputeAndDispatchDelta(D99FC0Object* obj, int a2, int a3, float a4, float a5, float a6, int a7);
struct FUN_00d9a410_Target {
    virtual void v00();
    virtual char* v01(char* buffer, int* a, int* b);
};
struct FUN_00d9a410_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
typedef void (__cdecl *FUN_00d9a410_Callback)(int*, int*, void*, int, int);
struct FUN_00d9a410_Entry {
    FUN_00d9a410_Callback fn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct FUN_00d9a410_Stub {
    int unk00;
    int unk04;
    int unk08;
    FUN_00d9a410_Target* unk0c;
    int unk10;
    int unk14;
    int* unk18;
    int unk1c;
    unsigned char* unk20;

    void __thiscall InvokeCallback(int* param);
};
struct ArgD9A4 {
    int unk00, unk04, unk08, unk0C;
};
struct InnerD9A4 {
    int unk00;
    float m_fValue;
};
class PrimaryD9A4 {
public:
    virtual ~PrimaryD9A4();
};
class SecondaryD9A4 {
public:
    virtual float ProcessAndReturnValue_00d9a480(ArgD9A4* pkArg) = 0;
};
class ObjD9A4 : public PrimaryD9A4, public SecondaryD9A4 {
public:
    int unk08;
    int unk0C;
    InnerD9A4* m_pkInner;

    void InvokeCallback(int iValue);
    virtual float ProcessAndReturnValue_00d9a480(ArgD9A4* pkArg);
};
struct __declspec(align(16)) FUN_00d9a4e0_Obj {
    LocalM128 unk00;
    LocalM128 unk10;
    int unk20;
    unsigned short unk24;
    unsigned short unk26;
    FUN_00d9a4e0_Obj* CopyFrom(const FUN_00d9a4e0_Obj* o);
};
namespace sd84c50 {

class Shape {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned int GetType() const;
};

struct BoolResult {
    bool m_bValue;

    BoolResult(bool bValue) : m_bValue(bValue) {}
};

// @fnv 0x00d84c50
// src: HAVOK_LIB 0x00d84c50
BoolResult hkpConstraintPivotsUtil_constraintSupportsPivotGetSet(const Shape* pkShape)
{
    switch (pkShape->GetType())
    {
    case 0:
    case 1:
    case 2:
    case 6:
    case 7:
    case 8:
    case 9:
    case 12:
    case 13:
    case 14:
    case 15:
        return BoolResult(true);
    default:
        return BoolResult(false);
    }
}

}
extern char DAT_01267e30;
class ShapeD84D {
public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual int getType();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ShapeD84D* m_pkChild;

    ShapeD84D* GetFieldC();
};
void* __cdecl GetShapeData(ShapeD84D* pkShape);
// pivot vector lives first in each 0x40-byte atom
struct PivotAtom {
    LocalM128 m_kPivotVector;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};
// view of the derived-class atom chain at data+0x50
struct AtomChain {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    PivotAtom m_kBridgeAtoms[2];
};
// hkpConstraintData stand-in (base class stays 4-aligned)
struct PivotCData {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int v08();

    PivotCData* hkpMalleableConstraintData_getWrappedConstraintData();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    PivotCData* m_wrapped;
};
void __cdecl SetPivotAtom(PivotCData* data, const LocalM128* pivot, int pivotIndex);
extern unsigned int DAT_0126835c;
typedef void* (__stdcall* D90TlsFn)(unsigned long);
extern D90TlsFn DAT_00fdf044;
struct D90Ctn {
    void** entries;
    unsigned short count;
};
struct D90Owner {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    D90Ctn m_kListeners;
};
struct D90Ev {
    unsigned int tag;
    unsigned int time;
    int unk08;
};
struct D90Prof {
    int unk00;
    D90Ev* head;
    int unk08;
    D90Ev* end;
};
struct D90Node {
    virtual void v00();
    virtual void v01(D90Owner* pOwner);
    virtual void v02();
    virtual void v03(D90Owner* pOwner);
};
// src: GUESS 0x00d85d40 (confidence: low)
static __declspec(noinline) D90Ctn* Object_ProcessEntries_00d85d40(D90Ctn* c) {
    for (int i = c->count - 1; i >= 0; --i) {
        if (c->entries[i] != 0) continue;
        c->count -= 1;
        unsigned int cnt = c->count;
        if (i < (int)cnt) {
            for (int j = i; j < (int)cnt; ++j)
                c->entries[j] = c->entries[j + 1];
        }
    }
    return c;
}
D90Ctn* __cdecl hkpConstraintCallbackUtil_fireConstraintAdded(D90Owner* pOwner);
static __forceinline void hkTimer(const char* name, volatile unsigned int& t)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.val() < s->m_capacityMinus16.val()) {
        hkMonitorStream::TimerCommand* c = (hkMonitorStream::TimerCommand*)s->m_end.val();
        c->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        c->m_time0 = t;
        s->m_end.m_storage = (char*)(c + 1);
    }
}
template <class T>
struct ResizableArray {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++) {
            m_data[i] = m_data[i + 1];
        }
    }
};
struct hkpConstraintInstance;
// src: GUESS 0x00d85d40 (confidence: low)
static void Object_ProcessEntries_00d85d40(ResizableArray<hkpConstraintListener*>& cleanupArray)
{
    for (int i = cleanupArray.GetLogicalSize() - 1; i >= 0; i--) {
        if (cleanupArray[i] == 0) {
            cleanupArray.removeAtAndCopy(i);
        }
    }
}
void __cdecl NotifyConstraintRemoved(hkpConstraintInstance* constraint);
void __cdecl hkArrayUtil__reserve(AllocIface& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
extern const char DAT_010d3aa0[];
extern const char DAT_010d3a90[];
int __cdecl j_strncmp(const char*, const char*, int) throw();
int __cdecl hkString_strLen(const char*) throw();
const char* __cdecl hkString_strChr(const char*, int) throw();
int __cdecl CallWithZeroMiddleArg(const char*, int) throw();
int __cdecl GetTypeCode(const char*) throw();
struct HkTempAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void ReturnMemory(void*, int) throw();
};
struct HkBytes16 {
    int a;
    int b;
    int c;
    int d;
};
struct HkBytes64 {
    HkBytes16 a;
    HkBytes16 b;
    HkBytes16 c;
    HkBytes16 d;
};
struct HkBytes128 {
    HkBytes64 a;
    HkBytes64 b;
};
struct HkInplaceChars {
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    HkBytes128 m_kStorage;
};
struct FUN_00d61b10 {
    HkInplaceChars m_kStringBuffer;

    FUN_00d61b10(const char*, int) throw();
    ~FUN_00d61b10() throw() {
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        int cap = m_kStringBuffer.m_iCapacityState;
        HkTempAllocator* allocator = reinterpret_cast<HkTempAllocator*>(router->m_temp);
        m_kStringBuffer.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            allocator->ReturnMemory(m_kStringBuffer.m_data, cap & 0x3fffffff);
        m_kStringBuffer.m_iCapacityState = int(0x80000000u);
        m_kStringBuffer.m_data = 0;
    }
};
int __cdecl GetTypeCodeFromString(const char* name) throw();
struct FUN_00d87180_cls : S {
    FUN_00d87180_cls* hkClassMemberAccessor_hkClassMemberAccessor(unsigned int a, B* b);
};
class OwnerD87A {
public:
    unsigned __int64 GetCurrentValue() const;
    int unk00;
    int unk04;
    unsigned __int64 m_uiCurrentValue;
};
__declspec(noinline) extern "C" void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int size)
{
    unsigned char* p = (unsigned char*)destination;
    for (unsigned int i = 0; i < size; ++i)
        p[i] = (unsigned char)value;
    return destination;
}
struct MonitorBuffer {
    void* m_ppVirtualMethodTable;
    int m_uiItemCount;
    char m_bSlotEnabled;
    char m_buffer[50];
    void hkMemoryExceptionTestingUtil_startNewDemoImpl();
};
void __cdecl Object_DoNothing_00d892e0();
struct hkpAgent3Input;
struct hkpAgentEntry;
struct hkpAgentDataD923;
hkpAgentDataD923* __cdecl CreateAgent(const hkpAgent3Input& input, hkpAgentEntry* entry, hkpAgentDataD923* freeMemory);
struct CleanupAllocator {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08(void* object, unsigned int size);
    virtual void unk0C();
    virtual void unk10(void* object, unsigned int size);
};
struct CleanupRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CleanupAllocator* m_pThreadAllocator;
    int unk14;
    CleanupAllocator* m_allocator2;
};
struct CleanupObject {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
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
    void* unk50;
    unsigned short unk54;
    unsigned short unk56;
    unsigned short unk58;
    unsigned short unk5A;
    void* unk5C;
    int unk60;
    int unk64;
    void* unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;

};
static void deleteTaskHeaderResources(CleanupObject* self);
CleanupObject* volatile cleanupInput;
void CleanupEntry();
extern "C" void _ReadWriteBarrier(void);
extern "C" {
    unsigned __int64 __rdtsc(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int dwTlsIndex);
}
extern unsigned int DAT_0126835c;
extern "C" char str_010cc5c4[];
extern "C" char str_010d3e98[];
extern "C" char str_01076f38[];
void __cdecl Hkpsolver_ProcessEntries_00d89ed0(void* p, int a, int b);
struct S00d944d0_Ent16 {
    char* m_name;
    unsigned int m_ts;
    int unk08;
    char* m_ucOperationType;
};
struct S00d944d0_Ent12 {
    char* m_name;
    unsigned int m_ts;
    int unk08;
};
struct S00d944d0_Sub {
    int unk00;
};
struct S00d944d0_Obj {
    S00d944d0_Sub* m_sub;
};
struct S00d944d0_Arg2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_20;
    int m_24;
};
struct S00d944d0_Arg1 {
    void ProcessCallback(S00d944d0_Arg2* a1, S00d944d0_Arg2* a2, int a3);
};
void __cdecl hkCpuSolveApplyGravityJob(S00d944d0_Obj* a1, S00d944d0_Arg1* a2, S00d944d0_Arg2* a3);
extern char DAT_010cc5c4[];
extern char DAT_010d3eb8[];
extern char DAT_01076f38[];
struct ProfilerLongRecord {
    char* name;
    unsigned int time;
    unsigned int unk08;
    char* secondaryName;
};
struct ProfilerShortRecord {
    char* name;
    unsigned int time;
    unsigned int unk08;
};
struct SolverTarget {
    int unk00, unk04, unk08, unk0c, unk10;
};
struct SolverObject {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    SolverTarget* target;
};
void __cdecl hkExportImpulsesAndRhs(TargetObj*, int, int, int);
void __cdecl hkCpuSolveExportResultsJob(Arg0* world, Arg1* context, SolverObject* object);
struct StructItem {
    short* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short unk14;
    unsigned short pad16;
    unsigned short unk18;
    unsigned short unk1A;
};
struct StructA {
    StructItem* items;
    int count;
    int unk08;
    int* ptrC;
    int unk10;
    int unk14;
    char unk18;
};
struct StructB {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};
extern double DAT_010c9300;
struct LocalFlag { unsigned char value; };
void __cdecl hkSimpleContactConstraintDataBuildJacobian(short* a1, StructB* a2, LocalFlag a3, int** a4);
void __cdecl hkSolverBuildJacobianFromAtomsNotContact(short* a1, unsigned short a2, StructB* a3, int** a4);
static void WriteItems(StructA* a, StructB* b);
extern "C" StructA* input_a();
extern "C" StructB* input_b();
void invoke_match();
struct d94eb0_cls { unsigned char b; };
extern "C" d94eb0_cls* d94eb0_target(void);
static void Runtime_UpdateState_00d94eb0(d94eb0_cls* dst);
void d94eb0_caller(void);
struct JobDescriptor {
    unsigned char m_ucSubType;
    hkEnum<hkJobType, unsigned char> m_eJobType;
    hkEnum<hkJobSpuType, unsigned char> m_eSpuType;
    unsigned char unk03;
    unsigned short m_iElementCount;
    short m_iAffinity;
    __forceinline JobDescriptor(hkJobType jobType, unsigned int subType, unsigned short size, hkJobSpuType spuType)
        : m_ucSubType((unsigned char)subType), m_eJobType(jobType), m_eSpuType(spuType), m_iElementCount(size), m_iAffinity(-1) {}
};
struct DynamicsJob : public JobDescriptor {
    int unk08;
    int unk0c;
    unsigned short m_usValueAtOffset10;
    int m_taskHeader14;
    int m_mtThreadStructure18;
    int m_unk1c;
    hkpTaskHeader_blk_00d80000_o2_rtm_variant* m_kHeader;
    __forceinline DynamicsJob(unsigned int subType, unsigned short size, const DynamicsJob& src)
        : JobDescriptor(HK_JOB_TYPE_DYNAMICS, subType, size, HK_JOB_SPU_TYPE_DISABLED)
    {
        m_usValueAtOffset10 = src.m_usValueAtOffset10;
        m_taskHeader14 = src.m_taskHeader14;
        m_mtThreadStructure18 = src.m_mtThreadStructure18;
        m_unk1c = src.m_unk1c;
    }
};
struct DynamicsJobSubtype14 : public DynamicsJob {
    __forceinline DynamicsJobSubtype14(const DynamicsJob& job)
        : DynamicsJob(14, 0x30, job)
    {
        m_usValueAtOffset10 = job.m_usValueAtOffset10;
        m_kHeader = job.m_kHeader;
    }
};
inline void* operator new(unsigned int, void* where) throw() { return where; }
struct JobRecord {
    int m_iFirstValue;
    int unk04;
    int unk08;
    int unk0c;
    DynamicsJob m_kJob;
};
int __cdecl TryCreateSubtype14Job(void* queue, void* data, const DynamicsJob& job, JobRecord& newJobCreated);
struct __declspec(align(16)) S00d96970_Local {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned short unk04;
    short unk06;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};
struct S00d96970_Target {
    void __thiscall InsertItemAndNotify(int value, S00d96970_Local* local, int flag);
};
struct S00d96970_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char unk21;
};
static void spawnSplitSimulationIslandJob(S00d96970_Obj* self, const S00d96970_Local* src, S00d96970_Target* target, int value);
void S00d96970_Entry(S00d96970_Obj* self, const S00d96970_Local* src, S00d96970_Target* target, int value);
extern float DAT_01017b78;
extern float DAT_01012068;
extern float DAT_01050cb0;
extern double DAT_01011588;
extern double DAT_01035718;
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
__forceinline unsigned int roundLane(const float& value)
{
    float copy = value;
    return fnv_FloatToInt(copy);
}
float Runtime_ProcessEntries_00d974f0();
extern const LocalM128 DAT_011b6de0;
LocalM128 __cdecl Object_GetDAT_011b6de0_00d98620();
struct ListenerArray {
    void** m_ppItems;
    unsigned short m_wCount;
};
static void Object_ProcessEntries_00d85d40(ListenerArray* pArr);
struct ListenerOwner {
    int unk00;
    ListenerArray m_kNode;
};
void CallCompact(ListenerOwner* o);
#include <stdarg.h>
namespace sd85040 {

class Shape {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType() const;
};

struct ContainerShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    Shape* m_pkChild;
};

struct ListShape : Shape {
    Shape* hkpMalleableConstraintData_getWrappedConstraintData();
};

struct VertexShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk1c;
    ConstraintPacketLocal_00d8 m_akVertices[1];
};

struct TransformShape : Shape {
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk1c;
    Transform m_akTransforms[1];
};

// @fnv 0x00d85040
// src: GUESS 0x00d85040 (confidence: low)
void Object_ProcessEntries_00d85040(Shape* pkShape, const Transform& kTransform, int iIndex)
{
    for (;;)
    {
        switch (pkShape->GetType())
        {
        case 12:
            pkShape = ((ContainerShape*)pkShape)->m_pkChild;
            break;
        case 13:
            pkShape = ((ListShape*)pkShape)->hkpMalleableConstraintData_getWrappedConstraintData();
            break;
        case 1:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 2:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 6:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 7:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 14:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 9:
            ((TransformShape*)pkShape)->m_akTransforms[iIndex].FUN_00c6cd60(kTransform);
            return;
        case 0:
            reinterpret_cast<LocalM128&>(((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents) = kTransform.r[3];
            return;
        case 8:
            reinterpret_cast<LocalM128&>(((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents) = kTransform.r[3];
            return;
        case 15:
            reinterpret_cast<LocalM128&>(((VertexShape*)pkShape)->m_akVertices[iIndex].m_vComponents) = kTransform.r[3];
            return;
        default:
            return;
        }
    }
}

}
struct HasFlag_d86 {
    char pad[0x10];
    unsigned short m_flags;
    hkBool HasFlag() const;
};
struct D94Rec16 {
    const char* name;
    unsigned int start;
    unsigned int unk08;
    const char* name2;
};
struct D94Rec12 {
    const char* name;
    unsigned int start;
    unsigned int unk08;
};
struct D94Tls {
    int unk00;
    D94Rec16* pCur;
    int unk08;
    D94Rec16* pEnd;
};
extern unsigned int DAT_0126835c;
typedef void* (__stdcall *D94TlsGetFn)(unsigned long);
extern D94TlsGetFn DAT_00fdf044;
extern const char str_010d3ef4[];
void __cdecl hkRigidMotionUtilApplyForcesAndBuildAccumulators(char* p, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
struct D94Sub {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int m30;
};
struct D94Body {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    D94Sub* m18;
    int u1c;
    int* p20;
    unsigned short us24;
    unsigned short us26;
};
struct D94Obj {
    int ProcessCallback(D94Body* a, D94Body* b, int c);
};
int __cdecl hkCpuBuildAccumulatorsJob(char* a1, D94Obj* a2, D94Body* a3);
#include <string.h>
struct S00d967a0_Obj {
    void** vptr;
};
struct S00d967a0_Rec {
    unsigned char m00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned short m10;
    unsigned short unk12;
    int m14;
    unsigned int unk18;
    S00d967a0_Obj* m1C;
    unsigned int unk20;
    unsigned short m24;
    unsigned short unk26;
    unsigned short m28;
    unsigned short m2A;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    int m40;
    unsigned short m44;
};
static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do {
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        s += 4; d += 4;
    } while (--numQuads > 0);
}
static __forceinline int split13(S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    unsigned short a = src->m28;
    unsigned short c = src->m2A;
    if (a <= c) return 0;
    src->m24++;
    src->m28 = (unsigned short)(a - c);
    src->m40 += c;
    dst->m44 = 0x200;
    dst->m28 = c;
    return 1;
}
static __forceinline int split15(S00d967a0_Rec* src, S00d967a0_Rec* dst)
{
    unsigned short a = src->m28;
    unsigned short c = src->m2A;
    if (a <= c) return 0;
    src->m28 = (unsigned short)(a - c);
    src->m24++;
    dst->m28 = c;
    return 1;
}
int SplitRecord(int a1, int a2, S00d967a0_Rec* src, S00d967a0_Rec* dst);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmpeq_ps(LocalM128, LocalM128);
extern "C" int _mm_movemask_ps(LocalM128);
struct D986Result {
    char value;
    D986Result(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};
D986Result __cdecl Runtime_ProcessEntries_00d98630(const LocalM128* src, const LocalM128* dst, int mask);
// Real body is 0xd96600..0xd9679f (0x1A0). 0xd967a0 is a second function the claim swallowed.
struct D96600Link {
    D96600Link* next;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char flag1c;
};
struct D96600Table {
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
    int* table;
};
struct D96600Blob {
    unsigned char type;
    unsigned char unk01;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short word10;
    unsigned short unk12;
    int field14;
    D96600Link* unk18;
    D96600Table** ppHolder;
    union {
        int count20;
        unsigned int offset20;
        D96600Link* node20;
    };
    union {
        unsigned int limit24;
        struct {
            unsigned short word24;
            unsigned short word26;
        };
    };
    int unk28;
    D96600Link* node2c;
    int unk30;
    unsigned short word34;
    unsigned short word36;
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

    int hkpBroadPhaseJob_popJobTask(int** slot, D96600Blob* dst);
};
static __forceinline int popPart(D96600Blob* src, D96600Blob* dst)
{
    D96600Table* holder = *src->ppHolder;
    int** slot = &holder->table;
    dst->field14 = holder->table[dst->word10];

    switch (src->type) {
    case 0: {
        int n = src->count20;
        if (n <= 1)
            return 0;
        src->word10++;
        src->count20 = n - 1;
        dst->count20 = 1;
        return 1;
    }
    case 1: {
        unsigned short step = 0x80;
        if (src->word26 <= step)
            return 0;
        src->word26 = (unsigned short)(src->word26 - step);
        src->word24 = (unsigned short)(src->word24 + step);
        dst->word26 = step;
        return step - 0x7f;
    }
    case 4:
    case 10:
        if (src->node20->next == 0)
            return 0;
        src->node20 = src->node20->next;
        return 1;
    case 12:
        return src->hkpBroadPhaseJob_popJobTask(slot, dst);
    case 11: {
        unsigned short step = 0x80;
        if (src->word34 > step) {
            src->word34 = (unsigned short)(src->word34 - step);
            src->word36 = (unsigned short)(src->word36 + step);
            dst->word34 = step;
            return step - 0x7f;
        }
        if (src->count20 == 0)
            return 0;
        src->type = 0x0a;
        return 1;
    }
    case 7:
    case 9: {
        unsigned int next = src->offset20 + 0x4000;
        if (next >= src->limit24)
            return 0;
        src->offset20 = next;
        dst->limit24 = next;
        return 1;
    }
    case 8:
        if (src->node2c->flag1c != 0)
            return 0;
        src->node2c = src->node2c->next;
        return 1;
    case 3:
    case 6:
    case 14:
        *dst = *src;
        return 0;
    case 2:
    case 5:
    case 13:
        return 0;
    default:
        return 0;
    }

}
int __cdecl PopPart(int callbackCtx, int callbackIndex, D96600Blob* src, D96600Blob* dst);
union __declspec(intrin_type) __declspec(align(16)) __m128i { unsigned __int64 q[2]; };
extern "C" {
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_and_ps(LocalM128, LocalM128);
LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
LocalM128 _mm_or_ps(LocalM128, LocalM128);
LocalM128 _mm_cmpeq_ps(LocalM128, LocalM128);
LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
LocalM128 _mm_min_ps(LocalM128, LocalM128);
LocalM128 _mm_max_ps(LocalM128, LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
LocalM128 _mm_rcp_ps(LocalM128);
LocalM128 _mm_setzero_ps();

LocalM128 _mm_load_ss(const float*);
LocalM128 _mm_set_ps1(float);
int _mm_movemask_ps(LocalM128);
__m128i _mm_setzero_si128();
__m128i _mm_unpacklo_epi16(__m128i, __m128i);
__m128i _mm_unpackhi_epi16(__m128i, __m128i);
__m128i _mm_srli_epi32(__m128i, int);
__m128i _mm_slli_epi32(__m128i, int);
LocalM128 _mm_cvtepi32_ps(__m128i);
}
__forceinline LocalM128 TreeSplat(float value) {
    LocalM128 scalar = _mm_load_ss(&value);
    return _mm_shuffle_ps(scalar, scalar, 0);
}
struct __declspec(align(16)) TreeVector {
    float x, y, z, w;
    LocalM128 simdValue() const { return *reinterpret_cast<const LocalM128*>(this); }
    float operator[](unsigned int axis) const { return (&x)[axis]; }
};
struct TreeNode {
    int flags;
    unsigned int bounds;
};
struct __declspec(align(16)) QuantizedBounds {
    unsigned short minX, minY, minZ, idLow;
    unsigned short maxX, maxY, maxZ, idHigh;
};
union TreeLeafId {
    unsigned int value;
    struct { unsigned short low, high; };
};
struct TreeCollector {
    virtual void unused();
    virtual void AddHit(unsigned char* state, unsigned int id);
    virtual void begin(unsigned char* state);
    virtual float earlyOut();
};
extern unsigned int DAT_010c92e0[4];
extern const double DAT_010217d0;
extern const LocalM128 DAT_011b6de0;
extern LocalM128 DAT_010c7170;
extern const float DAT_010cd644 = 1.0000000272564224e16f;
extern const float DAT_0104e148 = -3.402820018375656e38f;
extern const float DAT_0104da48 = 3.402820018375656e38f;
float __cdecl NiMax(float a, float b);
float __cdecl NiMin(float a, float b);
template<class T> struct TreeRef { T* p; TreeRef(T* q):p(q){} operator T*()const{return p;} T* operator->()const{return p;} };
__forceinline const QuantizedBounds* projectAt(const TreeNode& node, const QuantizedBounds* leaves, unsigned int index) { return leaves + (node.flags & 0x7fffffff) + index; }
struct BoundPair { LocalM128 minimum, maximum; void set(float a, float b) { minimum = _mm_set_ps1(a); maximum = _mm_set_ps1(b); } };
void __cdecl IntersectTree(void* tree, const TreeNode* node, const QuantizedBounds* leaves, const TreeVector* scale, const TreeVector* offset, const TreeVector* origin, const TreeVector* direction, float intervalMin, float intervalMax, float fractionScale, TreeCollector* collector);
extern char str_010cc5c4[];
extern char str_010d3ec8[];
extern char DAT_01076f38[];
struct S00d94a80_Ctx {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};
struct __declspec(align(16)) S00d94a80_Local {
    S00d94a80_Ctx head;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    char* unk94;
};
void __cdecl hkSolverBuildJacobianFromAtomsNotContact(char* atom, int count, S00d94a80_Local* ctx, int** cursor);
struct S00d94a80_Bool {
    bool m_cBooleanValue;
    S00d94a80_Bool(bool v) { m_cBooleanValue = v; }
};
void __cdecl hkSimpleContactConstraintDataBuildJacobian(char* atom, S00d94a80_Local* ctx, S00d94a80_Bool bCopy, int** cursor);
inline S00d94a80_Bool S00d94a80_True() { S00d94a80_Bool r(true); return r; }
struct S00d94a80_A0 {
    SubObj* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    S00d94a80_Ctx m_ctx;
};
struct S00d94a80_Rec {
    char* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned short unk14;
    unsigned short unk16;
    unsigned short unk18;
    unsigned short unk1a;
};
struct S00d94a80_Desc {
    int unk00;
    int unk04;
    char* end;
    int* c0;
    char* mon;
    int count;
    S00d94a80_Rec records[1];
};
struct S00d94a80_A2 {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    S00d94a80_Desc* unk20;
    int unk24;
    unsigned char unk28;
};
struct ArgHandle {
    Arg2* p;
    ArgHandle(Arg2* q):p(q) {}
};
struct S00d94a80_TimerCmd {
    const char* m_name;
    unsigned int m_uiStartTicks;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};
static __forceinline void S00d94a80_Process(Arg0* a1, Arg2* p)
{
    S00d94a80_Desc* desc = ((S00d94a80_A2*)p)->unk20;
    S00d94a80_Local base;
    base.head = ((S00d94a80_A0*)a1)->m_ctx;
    S00d94a80_Rec* rec = desc->records;
    char* mon = desc->mon;
    int count = desc->count;
    char* end = desc->end;
    int* c0 = desc->c0;
    base.unk94 = mon;
    bool flag = ((S00d94a80_A2*)p)->unk28 != 0 && desc->unk00 != 0;
    _ReadWriteBarrier();

    
    int* cursor = c0;
    if (count > 0) {
    int remaining = count;
    do {
        S00d94a80_Rec* r = rec++;
        base.head.unk38 = r->unk0c;
        base.head.unk3c = r->unk10;
        base.head.unk30 = (unsigned int)(end + r->unk18 * 128);
        base.head.unk34 = (unsigned int)(end + r->unk1a * 128);
        base.head.unk6c = r->unk18;
        base.head.unk70 = r->unk1a;
        base.head.unk60 = r->unk04;
        base.head.unk64 = r->unk08;
        base.head.unk74 = r->unk08;
        unsigned int w14 = r->unk14;
        char* atom = r->unk00;
        if (*(unsigned short*)atom == 0x16) {
            S00d94a80_Bool b(true);
            hkSimpleContactConstraintDataBuildJacobian(atom, &base, b, &cursor);
        } else {
            hkSolverBuildJacobianFromAtomsNotContact(atom, w14, &base, &cursor);
        }
    } while (--remaining);
    }

    int* c = cursor;
    if (!flag) {
        *c = 0;
    } else {
        int remain = (int)(base.unk94 - (char*)c);
        if (remain > 0) {
            *(float*)c += 1.1920928955078125e-07;
            c[1] = remain;
            *(unsigned char*)c = 2;
        }
    }

}
void __cdecl hkCpuBuildJacobiansJob(Arg0* a1, Arg1* a2, Arg2* a3);
extern const float g_011c5874_arg1;
extern const float runtimeFloatSettingDefault262;
extern double DAT_01035718;
union F128U
{
    LocalM128 v;
    unsigned u[4];
};
static const F128U V4C = { { 196608.0f, 196608.0f, 196608.0f, 196608.0f } };
float Object_ComputeBisectionMidpoint();
extern "C" void _mm_store_ps(float* p, LocalM128 a);
extern int DAT_010d37e4;
struct FUN_00d84bd0
{
    unsigned int m_00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile unsigned int m_08;
    unsigned int unk0c;
    volatile unsigned short m_10;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    volatile float m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    volatile float m_34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    volatile float m_48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    volatile float m_60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    volatile float m_74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    volatile float m_88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    volatile unsigned short m_a0;
    volatile unsigned char m_a2;

    FUN_00d84bd0();
};

struct TypeNameD86 {
    const char* FUN_00d46d40();
};
extern "C" char str_010d3b50[], str_010d3a88[], str_010d3b48[], str_010d3b40[], str_010d3b34[], str_010d3b28[], str_010d3b18[], str_010d3b10[], str_010d3b00[], str_010d3af0[], str_010d3ae0[], str_010d3ad0[], str_010d3abc[], str_010d3a74[];
struct TextD86 : StringBuf {
    void InitBuffer() throw();
    void FUN_00d61c10(const char*) throw();
};
extern "C" void __cdecl hkStringBuf_printf(TextD86*, const char*, ...);
extern "C" void __cdecl CopyIfNonEmpty(char*, const char*, int);
struct FreeD86 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void freeBlock(void*, int);
};
// 0x00d86ec0 reads its release allocator at +0x0C; shared Router::heap is at +0x10.
struct BufferReleaseContext {
    int unk00, unk04, unk08;
    FreeD86* heap;
};
// src: HAVOK_LIB 0x00d868b0
static __declspec(noinline) unsigned char isSimpleType(int t) {
    return (t >= 0 && (t < 20 || t == 28 || t == 30 || t == 29 || t == 32 || t == 33)) ? 1 : 0;
}
// src: HAVOK_LIB 0x00d868e0
static __declspec(noinline) void getSimpleTypeName(int t, TextD86* text, int extent) {
    if (!extent) text->FUN_00d61c10(DAT_011b6ab4[t].name);
    else hkStringBuf_printf(text, str_010d3a74, DAT_011b6ab4[t].name, extent);
}
struct MemberD86 {
    int unk00;
    TypeNameD86* classType;
    const char** enumType;
    unsigned char type;
    unsigned char subType;
    short extent;
    __declspec(noinline) int FUN_00d86b30() { return subType; }
};
// @fnv 0x00d86ec0
// src: GUESS 0x00d86ec0 (confidence: low)
extern "C" int __fastcall Object_ProcessAndReturnValue_00d86ec0(MemberD86* self, void*, char* output, int capacity) {
    TypeNameD86* cls = self->classType;
    int t = self->type;
    const char* className = cls ? cls->FUN_00d46d40() : "unknown";
    const char* enumName = self->enumType ? *self->enumType : "unknown";
    TextD86 text;
    text.InitBuffer();
    if (!((t >= 0 && (t < 20 || t == 28 || t == 30 || t == 29 || t == 32 || t == 33)) || t == 27)) {
    if (t == 20) {
        if (self->classType) hkStringBuf_printf(&text, str_010d3b50, self->classType->FUN_00d46d40());
        else if (self->subType == 2) text.FUN_00d61c10(str_010d3a88);
        else text.FUN_00d61c10(str_010d3b48);
    } else if (t == 22 || t == 26) {
        int st = self->FUN_00d86b30();
        const char* container = t == 22 ? str_010d3b10 : str_010d3b00;
        if (isSimpleType(st)) hkStringBuf_printf(&text, str_010d3af0, container, DAT_011b6ab4[st].name);
        else if (st == 20) {
            if (self->classType) hkStringBuf_printf(&text, str_010d3ae0, container, className);
            else hkStringBuf_printf(&text, str_010d3ad0, container);
        } else if (st == 25) hkStringBuf_printf(&text, str_010d3abc, container, className);
    } else if (t == 24) hkStringBuf_printf(&text, str_010d3b40, enumName);
    else if (t == 31) hkStringBuf_printf(&text, str_010d3b34, enumName);
    else if (t == 25) {
        if (!self->extent) hkStringBuf_printf(&text, str_010d3b28, className);
        else hkStringBuf_printf(&text, str_010d3b18, className, self->extent);
    }
    } else {
    getSimpleTypeName(t, &text, self->extent);
    }
    CopyIfNonEmpty(output, text.m_kStringBuffer, capacity);
    int result = text.m_fRestLength - 1;
    BufferReleaseContext* router = (BufferReleaseContext*)hkMemoryRouter_getInstance();
    FreeD86* heap = router->heap;
    text.m_fRestLength = 0;
    if ((text.m_iCapacityState & 0x80000000) == 0)
        heap->freeBlock(text.m_kStringBuffer, text.m_iCapacityState & 0x3fffffff);
    return result;
}
volatile int d86_type;
TextD86* volatile d86_text;
volatile int d86_extent;
void D86HelperUse() {
    getSimpleTypeName(d86_type, d86_text, d86_extent);
}
