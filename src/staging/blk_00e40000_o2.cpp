#include "../../include/hkArray.h"
// staging/blk_00e40000_o2.cpp: KnotVector, ThunkDerived, FourComponentVector, Quat4 and more (195 functions)

#include "fnv_asm_helpers.h"
#define FNV_VEC4_SIMD
#include "../../include/Vec4.h"
#include "../../include/hkpConstraintInstance.h"
#include "../../include/hkpConstraintData.h"

// These curve routines use four-byte-aligned scalar vector storage.
#define FNV_V4_UNALIGNED
#define FNV_FOURFLOATVECTOR_NO_SSE
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
// local form of hkVector4: 0x00e55080 needs packed scalar call/copy behavior (shared extent 156 vs 188).


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
union __m128;
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class ConstraintFourLaneCallLocal_00e55080
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

    ConstraintFourLaneCallLocal_00e55080();
    ConstraintFourLaneCallLocal_00e55080(float x, float y, float z, float w);
    ConstraintFourLaneCallLocal_00e55080(const __m128& vector);

    ConstraintFourLaneCallLocal_00e55080* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(ConstraintFourLaneCallLocal_00e55080* vector);
    void __thiscall SetQuaternionComponentsFromVector(const ConstraintFourLaneCallLocal_00e55080* vector);
    ConstraintFourLaneCallLocal_00e55080& ComputeValue_00e531a0(int parameter);
    ConstraintFourLaneCallLocal_00e55080 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const ConstraintFourLaneCallLocal_00e55080& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const ConstraintFourLaneCallLocal_00e55080& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const ConstraintFourLaneCallLocal_00e55080& vector);
    void Sub(const ConstraintFourLaneCallLocal_00e55080& vector);
    void Cross(const ConstraintFourLaneCallLocal_00e55080& a, const ConstraintFourLaneCallLocal_00e55080& b);

    void setAbs4(const ConstraintFourLaneCallLocal_00e55080& vector);
    void setMul4(const SimdReal& scalar, const ConstraintFourLaneCallLocal_00e55080& vector);
    void addMul4(const SimdReal& scalar, const ConstraintFourLaneCallLocal_00e55080& vector);
    void setAddMul4(const ConstraintFourLaneCallLocal_00e55080& a, const ConstraintFourLaneCallLocal_00e55080& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const ConstraintFourLaneCallLocal_00e55080& vector);
    void setAddMul(const ConstraintFourLaneCallLocal_00e55080& a, const ConstraintFourLaneCallLocal_00e55080& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const ConstraintFourLaneCallLocal_00e55080& vector);
    void transformed(const Transform& transform, const ConstraintFourLaneCallLocal_00e55080& vector);
    void addScaled(const ConstraintFourLaneCallLocal_00e55080& base, const ConstraintFourLaneCallLocal_00e55080& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/V4.h"
#include "../../include/hkBool.h"
#include "../../include/hkpEntityExtendedListeners.h"
#include "../../include/hkpEntityListener.h"
#include "../../include/hkpRemoveTerminalsMoppModifier2.h"

// Keep the original empty vector constructors and inline allocator accessors.
inline ConstraintFourLaneCallLocal_00e55080::ConstraintFourLaneCallLocal_00e55080() {}
inline V4::V4() {}

// src/staging/blk_00e40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00e428f0_class {
    void Remove(void*);
    void hkpVehicleCastBatchingManager_removeVehicle(void* p);
};

// @fnv 0x00e428f0
// src: HAVOK_LIB 0x00e428f0
void FUN_00e428f0_class::hkpVehicleCastBatchingManager_removeVehicle(void* p)
{
    Remove(p);
    *(unsigned short*)((char*)this + 0x14) -= *(unsigned char*)((char*)*(unsigned int*)((char*)p + 0x1c) + 0x20);
}

// @fnv 0x00e42940
// src: HAVOK_LIB 0x00e42940
int __cdecl hkpVehicleCastBatchingManager_getStandardFilterSize(int pObject)
{
    int v = *(int*)(pObject + 0x7c);
    return *(int*)(v + 0x20) != 2 ? 0 : 256;
}

extern "C" void __cdecl FUN_00cb0a60();

struct FUN_00e4e400_class {
    FUN_00e4e400_class* __thiscall hkaAnnotationTrack_hkaAnnotationTrack();
};

// @fnv 0x00e4e400
// src: HAVOK_LIB 0x00e4e400
FUN_00e4e400_class* __thiscall FUN_00e4e400_class::hkaAnnotationTrack_hkaAnnotationTrack()
{
    FUN_00cb0a60();
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 12) = 0x80000000;
    return this;
}

// @fnv 0x00e52860
// src: GUESS 0x00e52860 (confidence: low)
void Object_UpdateFields_00e52860(const float* src, float* dst)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

// @fnv 0x00e52ef0
// src: GUESS 0x00e52ef0 (confidence: low)
void Runtime_UpdateState_00e52ef0(const float* src, float* dst)
{
    *dst = *src;
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

struct FUN_00e58780_Class {
    int* GetElementPtr(int a, int b);
};

// @fnv 0x00e58780
int* FUN_00e58780_Class::GetElementPtr(int a, int b)
{
    return *(int**)(this + 0) + a * *(int*)((char*)this + 0x10) + b;
}

struct FUN_00e587c0_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    float GetFloatAt(int idx, int base);
};

// @fnv 0x00e587c0
float FUN_00e587c0_Class::GetFloatAt(int iIndex, int base) {
    return *(float*)((char*)*(void**)((char*)this + 0) + (iIndex * m_10 + base) * 4);
}

struct GlobalObjectO2_00d472a0 { int x; };
GlobalObjectO2_00d472a0 g_0126e600;
void __stdcall FindResourceWithExpectedName(int, GlobalObjectO2_00d472a0*);
// @fnv 0x00e5c5b0
// src: GUESS 0x00e5c5b0 (confidence: low)
void __stdcall Runtime_ForwardCall_00e5c5b0(int a)
{
    FindResourceWithExpectedName(a, &g_0126e600);
}

extern "C" void __stdcall FindResourceWithExpectedName(int, int);

struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c5f0;

// Calls FUN_00e5c540 with the argument a and the address of g_0126c5f0.
// @fnv 0x00e5c5f0
// src: GUESS 0x00e5c5f0 (confidence: low)
void __stdcall Runtime_ForwardCall_00e5c5f0(int aiValue)
{
    FindResourceWithExpectedName(aiValue, (int)&g_0126c5f0);
}

namespace fnv_00e5c610 {
struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126e570;
extern "C" void __stdcall FindResourceWithExpectedName(int, GlobalObjectO2_00d472a0*);
// @fnv 0x00e5c610
// src: GUESS 0x00e5c610 (confidence: low)
void __stdcall Runtime_ForwardCall_00e5c610(int aiValue)
{
    FindResourceWithExpectedName(aiValue, &g_0126e570);
}
}  // namespace fnv_00e5c610

namespace fnv_00e5c650 {
struct GlobalObjectO2_00d472a0 {};
extern GlobalObjectO2_00d472a0 g_0126ea38;
void __stdcall FindResourceWithExpectedName(int, GlobalObjectO2_00d472a0*);
// @fnv 0x00e5c650
// src: GUESS 0x00e5c650 (confidence: low)
void __stdcall Runtime_ForwardCall_00e5c650(int aiValue)
{
    FindResourceWithExpectedName(aiValue, &g_0126ea38);
}
}  // namespace fnv_00e5c650

namespace fnv_00e5c670 {
struct GlobalObjectO2_00d472a0;
extern "C" void* __stdcall FindResourceWithExpectedName(void*, void*);
extern GlobalObjectO2_00d472a0 g_0126ea80;

// @fnv 0x00e5c670
// src: GUESS 0x00e5c670 (confidence: low)
void* __stdcall Runtime_ForwardCall_00e5c670(void* apArg)
{
    return FindResourceWithExpectedName(apArg, &g_0126ea80);
}
}  // namespace fnv_00e5c670

struct FUN_00e459c0_class {
    void SetBitMaskFlags(int a, int b);
};

// If both masks are zero sets byte 0x30 to 1; otherwise ORs each set bit's mask into the corresponding int at offset 0x34.
// @fnv 0x00e459c0
void FUN_00e459c0_class::SetBitMaskFlags(int a, int b)
{
    if (!a && !b)
    {
        ((char*)this)[0x30] = 1;
        return;
    }
    for (int i = 0; i < 32; i++)
    {
        if (a & (1 << i))
            ((int*)((char*)this + 0x34))[i] |= b;
        if (b & (1 << i))
            ((int*)((char*)this + 0x34))[i] |= a;
    }
}

struct FUN_00e45a10_class {
    void __thiscall ClearFlags(int a, int b);
};
// If both masks are zero, clears the byte at offset 0x30; otherwise for each of 32 bits, clears the other mask's bits in the corresponding dword at 0x34 + i*4.
// @fnv 0x00e45a10
void __thiscall FUN_00e45a10_class::ClearFlags(int a, int b)
{
    if (!a && !b)
    {
        *(unsigned char*)((char*)this + 0x30) = 0;
        return;
    }
    for (int i = 0; i < 32; ++i)
    {
        if (a & (1 << i))
            *(unsigned int*)((char*)this + 0x34 + i * 4) &= ~b;
        if (b & (1 << i))
            *(unsigned int*)((char*)this + 0x34 + i * 4) &= ~a;
    }
}

struct FUN_00e587b0_Class {
    int* __thiscall GetElementAddress_00e587b0(int idx);
};

// @fnv 0x00e587b0
// src: GUESS 0x00e587b0 (confidence: low)
int* __thiscall FUN_00e587b0_Class::GetElementAddress_00e587b0(int idx)
{
    return *reinterpret_cast<int**>(this) + idx;
}

struct FUN_00e58880_Class {
    float GetIndexedValue_00e58880(int offset);
};

// @fnv 0x00e58880
// src: GUESS 0x00e58880 (confidence: low)
float __thiscall FUN_00e58880_Class::GetIndexedValue_00e58880(int offset)
{
    const float* base = *(const float**)this;
    return base[offset];
}

namespace fnv_00e589e0 {
struct FUN_00e587b0_Class {
    float* GetElementAddress_00e587b0(int);
    int EvaluateValue_00e58890();
};
// Calls FUN_00e58890 for a count, then for each index gets a float pointer via FUN_00e587b0 and negates its first element.
// @fnv 0x00e589e0
void __cdecl NegateElements(FUN_00e587b0_Class* p)
{
    int count = p->EvaluateValue_00e58890();
    for (int i = 0; i < count; ++i)
    {
        float* a = p->GetElementAddress_00e587b0(i);
        float* b = p->GetElementAddress_00e587b0(i);
        *b = -a[0];
    }
}
}  // namespace fnv_00e589e0

// Returns the factorial of count, using a lookup table for 0-10 and multiplying up from 11 for larger values.
// @fnv 0x00e53090
int __cdecl Factorial(int count)
{
    int values[11] = { 1, 1, 2, 6, 0x18, 0x78, 0x2d0, 0x13b0, 0x9d80, 0x58980, 0x375f00 };
    if (count <= 0)
        return 1;
    if (count <= 10)
        return values[count];
    for (int i = 11; i <= count; ++i)
        values[10] *= i;
    return values[10];
}

extern const float runtimeFloatSettingDefault132;
extern const float runtimeFloatSettingDefault255;
extern const float g_011c7344_arg1;
extern int DAT_010e62a4;

struct FUN_00e44280_struct {
    int* m_00;
    unsigned short m_06;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00e44280_struct* InitializeDefaults();
};

// @fnv 0x00e44280
FUN_00e44280_struct* __thiscall FUN_00e44280_struct::InitializeDefaults()
{
    m_08 = 1000.0f;
    m_0c = runtimeFloatSettingDefault132;
    *(unsigned short*)((char*)this + 6) = 1;
    m_00 = &DAT_010e62a4;
    m_10 = runtimeFloatSettingDefault255;
    m_14 = g_011c7344_arg1;
    m_1c = m_18 = 1.0f;
    m_28 = m_24 = m_20 = 0.0f;
    m_2c = 2000.0f;
    return this;
}

struct FUN_00e407d0_class {
    void SetSlotValue(int idx, char b);
};
// Writes 0.0f into the array at this+0x80 when b is set, otherwise writes 1.0f into the array at this+0x74, both indexed by idx.
// @fnv 0x00e407d0
void FUN_00e407d0_class::SetSlotValue(int aiIndex, char b)
{
    if (b)
        *(float*)(*(int*)((char*)this + 0x80) + aiIndex * 4) = 0.0f;
    else
        *(float*)(*(int*)((char*)this + 0x74) + aiIndex * 4) = 1.0f;
}

struct FUN_00e426f0_class {
    unsigned short m_00;
    unsigned short m_02;
    unsigned short m_04;
    unsigned short m_06;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
    unsigned short m_10;
    unsigned short m_12;
    unsigned short m_14;
    void AddObject(void* p);
    void AddByteFromObject(void* p);
};

// @fnv 0x00e428d0
void FUN_00e426f0_class::AddByteFromObject(void* p)
{
    AddObject(p);
    m_14 += ((unsigned char*)*(void**)((char*)p + 0x1c))[0x20];
}

struct FUN_00e61480_class {
    void hkxMeshSection_collectVertexPositions(int);
};
struct FUN_00e4ab50_class {
    int m_00;
    int m_04;
    int* m_08;
    int m_0c;
    void __thiscall ApplyToAll(int a);
};
// Calls FUN_00e61480 with a on each of the m_0c objects pointed to by m_08.
// @fnv 0x00e4ab50
void __thiscall FUN_00e4ab50_class::ApplyToAll(int aiValue)
{
    for (int i = 0; i < m_0c; i++)
        ((FUN_00e61480_class*)m_08[i])->hkxMeshSection_collectVertexPositions(aiValue);
}

extern int DAT_010ec1fc;
struct FUN_00cb0a70 {
    void m(int);
};
struct FUN_00e4af80 {
    int vtbl;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e4af80* Set(int arg);
};
// @fnv 0x00e4af80
FUN_00e4af80* FUN_00e4af80::Set(int aiValue)
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010ec1fc);
    reinterpret_cast<FUN_00cb0a70*>(reinterpret_cast<char*>(this) + 0x14)->m(aiValue);
    return this;
}

struct FUN_00e58b10_class {
    void FillWithValue(float* out);
    void hkaSparseLSQMatrix_float_MultiplyAdd(int a, int b, int c);
    void hkaSparseLSQMatrix_float_Multiply(int a, int b, int c);
};
// @fnv 0x00e58b10
// src: HAVOK_LIB 0x00e58b10
void FUN_00e58b10_class::hkaSparseLSQMatrix_float_Multiply(int a, int aiArg2, int aiArg3)
{
    float v = 0.0f;
    ((FUN_00e58b10_class*)a)->FillWithValue(&v);
    this->hkaSparseLSQMatrix_float_MultiplyAdd(a, aiArg2, aiArg3);
}

extern const char* const g_0126c5f0_arg1;
void __stdcall FindResourceWithExpectedName(int, int);
// @fnv 0x00e5c5d0
// src: GUESS 0x00e5c5d0 (confidence: low)
void __stdcall Runtime_ForwardCall_00e5c5d0(int aiValue)
{
    FindResourceWithExpectedName(aiValue, (int)&g_0126c5f0_arg1);
}

struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126eb10;
void __stdcall FindResourceWithExpectedName(int a, GlobalObjectO2_00d472a0* b);
// @fnv 0x00e5c630
// src: GUESS 0x00e5c630 (confidence: low)
void __stdcall Runtime_ForwardCall_00e5c630(int aiValue)
{
    FindResourceWithExpectedName(aiValue, &g_0126eb10);
}

struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126eac8;
void __stdcall FindResourceWithExpectedName(int, GlobalObjectO2_00d472a0*);
// @fnv 0x00e5c690
void __stdcall CallWithGlobalObject(int aiValue)
{
    FindResourceWithExpectedName(aiValue, &g_0126eac8);
}

struct FUN_00e406d0_cls
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
    float* m_44;
    int unk48;
    int unk4C;
    float* m_50;
    void ClampBoundsAt(int index, float value);
};
// Clamps the low bound at index to at most value and the high bound at index to at least value.
// @fnv 0x00e406d0
void FUN_00e406d0_cls::ClampBoundsAt(int index, float value)
{
    float a = m_44[index];
    float lo = (a < value) ? a : value;
    m_44[index] = lo;
    float b = m_50[index];
    m_50[index] = (b > value) ? b : value;
}

struct HolderStub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

HolderStub* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize);

struct ValueArray {
    unsigned int* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct FUN_00e41db0_cls {
    int unk00;
    int unk04;
    ValueArray m_08;
    void AppendValue(unsigned int value);
};

// Appends value to the m_08 array, growing it via ResizeAudioStream when the count reaches capacity, then increments the count.
// @fnv 0x00e41db0
void FUN_00e41db0_cls::AppendValue(unsigned int value)
{
    ValueArray* arr = &m_08;
    HolderStub* holder = hkMemoryRouter_getInstance();
    if (arr->m_iArrayLength == (int)(arr->m_uCapFlags & 0x3fffffffu)) {
        ResizeAudioStream(holder->m_pAllocator, arr, 4);
    }
    unsigned int* slot = arr->m_pData + *(volatile int*)&arr->m_iArrayLength;
    *slot = value;
    arr->m_iArrayLength++;
}

class BE41DF0ReferencedObject {
public:
    BE41DF0ReferencedObject() throw() : m_sReferenceCount(1) {}
    virtual ~BE41DF0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};



class FUN_00e41df0_cls : public BE41DF0ReferencedObject {
public:
    FUN_00e41df0_cls() throw();
    virtual ~FUN_00e41df0_cls();

    hkArrayBase<void*> m_kEntries;
};

// Default constructor that initializes the reference count to 1 and leaves the entry array empty.
// @fnv 0x00e41df0
FUN_00e41df0_cls::FUN_00e41df0_cls() throw()
{
}

// FUN_00e42650: iterate an array of listener objects and notify each one.
struct EventListener {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a);
};

struct FUN_00e42650_cls {
    int m_00;
    int m_04;
    EventListener** m_08;
    int m_0c;

    void hkpVehicleManager_addToWorld(int a);
};

// Calls v09(a) on each of the m_0c event listeners stored in m_08.
// @fnv 0x00e42650
// src: HAVOK_LIB 0x00e42650
void FUN_00e42650_cls::hkpVehicleManager_addToWorld(int a) {
    int count = m_0c;
    for (int i = 0; i < count; i++) {
        m_08[i]->v09(a);
    }
}

struct FUN_00e42680_Item {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
};

struct FUN_00e42680_cls {
    int m_00;
    int m_04;
    FUN_00e42680_Item** m_08;
    int m_0c;

    void CallItemsVirtual();
};

// Iterates m_08 up to m_0c times and calls the virtual v10() on each item.
// @fnv 0x00e42680
void FUN_00e42680_cls::CallItemsVirtual() {
    int count = m_0c;
    for (int i = 0; i < count; i++) {
        m_08[i]->v10();
    }
}

extern "C" int DAT_010e5e9c;

struct FUN_00e43ac0_cls {
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    float m_08;
    float m_0c;
    float m_10;
    FUN_00e43ac0_cls();
};

// @fnv 0x00e43ac0
FUN_00e43ac0_cls::FUN_00e43ac0_cls() {
    m_08 = 0.0f;
    m_0c = 0.0f;
    m_06 = 1;
    m_00 = (void*)&DAT_010e5e9c;
    m_10 = 1.0f;
}

extern double DAT_010ebf20;
extern double DAT_010ebf18;
extern double DAT_01012638;
extern double DAT_0101ff48;

// Divides param_3 by param_4 and by a denominator built from param_1, param_2 and the four constants, returning the result.
// @fnv 0x00e43bb0
float __cdecl ComputeScaledRatio(float param_1, float afDivisor, float afValue, float afScale)
{
    float denominator = param_1 * DAT_010ebf20 / DAT_010ebf18;
    denominator /= afDivisor;
    denominator = denominator * DAT_01012638 / DAT_0101ff48;
    return afValue / denominator / afScale;
}

extern "C" int DAT_010e5ff4;

struct FUN_00e43f30_cls {
    void* volatile m_00;
    unsigned short m_04;
    volatile unsigned short m_06;
    volatile float m_08;
    volatile float m_0c;
    volatile float m_10;
    volatile float m_14;
    volatile float m_18;
    volatile int m_1c;
    volatile int m_20;
    volatile unsigned int m_24;
    volatile int m_28;
    volatile int m_2c;
    volatile unsigned int m_30;
    FUN_00e43f30_cls();
};

// @fnv 0x00e43f30
FUN_00e43f30_cls::FUN_00e43f30_cls() {
    m_06 = 1;
    m_00 = (void*)&DAT_010e5ff4;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0x80000000;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0x80000000;
    m_08 = 0.0f;
    m_0c = 0.0f;
    m_10 = 0.0f;
    m_14 = 0.0f;
    m_18 = 0.0f;
}

class BE468B0Base {
public:
    virtual ~BE468B0Base();

    int m_iRefCount;
};

class BE468B0InterfaceA {
public:
    virtual void OnA();
};

class BE468B0InterfaceB {
public:
    virtual void OnB();
};

class BE468B0InterfaceC {
public:
    virtual void OnC();
};

class BE468B0InterfaceD {
public:
    virtual void OnD();
};

class BE468B0Shape : public BE468B0Base, public BE468B0InterfaceA, public BE468B0InterfaceB,
    public BE468B0InterfaceC, public BE468B0InterfaceD {
public:
    BE468B0Shape();
    virtual ~BE468B0Shape();

    int m_iFirst;
    int m_iSecond;
    int m_iEnabled;
    int unk24;
    int unk28;
    int unk2C;
};

class BE468B0Listener {
public:
    virtual void OnEvent();
};



class FUN_00e468b0_cls : public BE468B0Shape, public BE468B0Listener {
public:
    FUN_00e468b0_cls();
    virtual ~FUN_00e468b0_cls();
    virtual void OnA();
    virtual void OnB();
    virtual void OnC();
    virtual void OnD();
    virtual void OnEvent();

    hkArrayBase<int> m_kEntries;
};

// @fnv 0x00e468b0
FUN_00e468b0_cls::FUN_00e468b0_cls()
{
}

struct S_e49fe0_B0 { virtual void d0(); int unk4; };
struct S_e49fe0_B8 { virtual void d8(); };
struct S_e49fe0_Bc { virtual void dc(); };
struct S_e49fe0_B10 { virtual void d10(); };
struct S_e49fe0_B14 { virtual void d14(); };
struct FUN_00cbfba0 : S_e49fe0_B0, S_e49fe0_B8, S_e49fe0_Bc, S_e49fe0_B10, S_e49fe0_B14 {
    FUN_00cbfba0();
};
struct S_e49fe0_Arr {
    int m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_e49fe0_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000) {}
};
struct FUN_00e49fe0 : FUN_00cbfba0 {
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_e49fe0_Arr arr;
    FUN_00e49fe0();
    virtual void d0();
    virtual void d8();
    virtual void dc();
    virtual void d10();
    virtual void d14();
};
// Initializes the FUN_00e49fe0 object, including its embedded S_e49fe0_Arr member.
// @fnv 0x00e49fe0
FUN_00e49fe0::FUN_00e49fe0() {}

struct E4AAA0Allocator;

void __cdecl hkArrayUtil__reserve(E4AAA0Allocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl hkMemUtil_memMove(void* dst, const void* src, unsigned int nbytes);

struct E4AAA0Element {
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};

static __forceinline void E4AAA0Array_reserve(hkArrayBase<E4AAA0Element>& self, E4AAA0Allocator& alloc, int n);

static __forceinline void E4AAA0Array_reserve(hkArrayBase<E4AAA0Element>& self, E4AAA0Allocator& alloc, int n)
{
        const int cap = self.getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, (&self), newSize, sizeof(E4AAA0Element));
        }
    }

// @fnv 0x00e4aaa0


class E4AE50ReferencedObject {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    E4AE50ReferencedObject() { m_sReferenceCount = 1; }
    virtual ~E4AE50ReferencedObject() {}
};



class FUN_00e4ae50 : public E4AE50ReferencedObject {
public:
    hkArrayBase<void*> m_entries;

    FUN_00e4ae50();
    virtual ~FUN_00e4ae50();
};

// @fnv 0x00e4ae50
FUN_00e4ae50::FUN_00e4ae50() {
}

// FUN_00e4ae80 (11 bytes)
//
//   00e4ae80  8b c1                    mov eax, ecx
//   00e4ae82  c7 00 ec c1 0e 01        mov dword ptr [eax], 0x010ec1ec
//   00e4ae88  c2 04 00                 ret 4
//
// This is a CONSTRUCTOR of the class whose vftable lives at 0x010ec1ec
// (hkxMaterialShaderSet - see tools/pe.py rtti 0x010ec1ec).  A constructor
// returns `this` in EAX, so `this` is live-out in EAX and MSVC emits the vptr
// store through EAX (a hand written `this->m_vtbl = ...` would instead give
// `mov eax,OFFSET sym / mov [ecx],eax`).  The single 4-byte stack argument is
// unused, which is why the epilogue is `ret 4`.
//
// The class is stand-in only: it needs one virtual so that the compiler emits
// a vftable, and the vftable slot points at the (undefined) virtual, so the
// only defined function symbol in this translation unit is the constructor.

struct FUN_00e4ae80_class {
    FUN_00e4ae80_class(int flags);
    virtual void vfunc_00();
};

// @fnv 0x00e4ae80
FUN_00e4ae80_class::FUN_00e4ae80_class(int flags)
{
}

// add ecx,0x14; jmp FUN_00cb0c10 : the derived override forwards to the secondary base's
// virtual, so `this` is moved forward by the size of the primary base (vptr + 4 ints = 0x14)
// before the tail jump to the secondary base's implementation.
struct ThunkPrimary
{
    virtual void ForwardCall_00e4af50();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct ThunkSecondary
{
    virtual void UpdateState_00cb0c10();
};

struct ThunkDerived : ThunkPrimary, ThunkSecondary
{
    ThunkDerived();
    virtual void ForwardCall_00e4af50();
};

ThunkDerived::ThunkDerived()
{
}

// @fnv 0x00e4af50
// src: GUESS 0x00e4af50 (confidence: low)
void ThunkDerived::ForwardCall_00e4af50()
{
    this->ThunkSecondary::UpdateState_00cb0c10();
}

struct S_00e4af60_helper {
    void FUN_00cb0a60();
};

struct S_00e4af60_class {
    void* unk00;
    short unk04;
    short unk06;
    void* unk08;
    int unk0c;
    int unk10;
    S_00e4af60_helper unk14;

    S_00e4af60_class* InitializeFields_00e4af60();
};

extern int DAT_010ec1fc;

// @fnv 0x00e4af60
// src: GUESS 0x00e4af60 (confidence: low)
S_00e4af60_class* S_00e4af60_class::InitializeFields_00e4af60()
{
    this->unk06 = 1;
    this->unk00 = &DAT_010ec1fc;
    this->unk14.FUN_00cb0a60();
    return this;
}

namespace fnv_00e50ca0 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00e50ca0_cls {
    int unk00;
    int unk04;
    int unk08;
    void* m_pData5;
    int m_iCount5;
    unsigned int m_uCap5;
    void* m_pData4;
    int m_iCount4;
    unsigned int m_uCap4;
    void* m_pData3;
    int m_iCount3;
    unsigned int m_uCap3;
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCap2;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCap1;

    void ReleaseFiveArrays();
};

// Frees the five allocated arrays through the audio allocator, resetting each pointer, count and capacity to empty.
// @fnv 0x00e50ca0
// src: GUESS 0x00e50ca0 (confidence: medium)
void FUN_00e50ca0_cls::ReleaseFiveArrays()
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCap1 = m_uCap1;
    m_iCount1 = 0;
    if ((uCap1 & 0x80000000u) == 0) {
        pAllocator->bufFree(m_pData1, (uCap1 & 0x3fffffffu) * 1);
    }
    m_pData1 = 0;
    m_uCap1 = 0x80000000u;

    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    unsigned int uCap2 = m_uCap2;
    m_iCount2 = 0;
    if ((uCap2 & 0x80000000u) == 0) {
        pAllocator2->bufFree(m_pData2, (uCap2 & 0x3fffffffu) * 4);
    }
    m_pData2 = 0;
    m_uCap2 = 0x80000000u;

    hkMemoryRouter* pHolder3 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator3 = reinterpret_cast<hkMemoryAllocator*>(pHolder3->m_heap);
    unsigned int uCap3 = m_uCap3;
    m_iCount3 = 0;
    if ((uCap3 & 0x80000000u) == 0) {
        pAllocator3->bufFree(m_pData3, (uCap3 & 0x3fffffffu) * 4);
    }
    m_pData3 = 0;
    m_uCap3 = 0x80000000u;

    hkMemoryRouter* pHolder4 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator4 = reinterpret_cast<hkMemoryAllocator*>(pHolder4->m_heap);
    unsigned int uCap4 = m_uCap4;
    m_iCount4 = 0;
    if ((uCap4 & 0x80000000u) == 0) {
        pAllocator4->bufFree(m_pData4, (uCap4 & 0x3fffffffu) * 4);
    }
    m_pData4 = 0;
    m_uCap4 = 0x80000000u;

    hkMemoryRouter* pHolder5 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator5 = reinterpret_cast<hkMemoryAllocator*>(pHolder5->m_heap);
    unsigned int uCap5 = m_uCap5;
    m_iCount5 = 0;
    if ((uCap5 & 0x80000000u) == 0) {
        pAllocator5->bufFree(m_pData5, (uCap5 & 0x3fffffffu) * 4);
    }
    m_pData5 = 0;
    m_uCap5 = 0x80000000u;
}
}  // namespace fnv_00e50ca0

// Adds k times the sum of adjacent src samples into dst, with the last dst sample getting k times twice the last src sample.
// @fnv 0x00e50d90
void __cdecl AccumulateNeighborSum(float k, const float* src, float* dst, int n)
{
    for (int i = 0; i < n - 1; i++) {
        dst[i] += k * (src[i] + src[i + 1]);
    }
    dst[n - 1] += k * 2.0f * src[n - 1];
}

extern float DAT_0102295c;
extern float DAT_0101622c;

void __cdecl DeinterleaveFloats(float* a, float* b, unsigned int n);
void __cdecl AccumulateNeighborSum(float c, float* a, float* b, unsigned int n);
void __cdecl hkUpdateReflect(float c, float* a, float* b, unsigned int n);

// @fnv 0x00e51330
// src: HAVOK_LIB 0x00e51330
void __cdecl _hkWaveletTransform(float* afValues, unsigned int n)
{
    if (n <= 1) {
        return;
    }
    do {
        DeinterleaveFloats(afValues, afValues, n);
        n = n >> 1;
        AccumulateNeighborSum(DAT_0102295c, afValues, afValues + n, n);
        hkUpdateReflect(DAT_0101622c, afValues, afValues + n, n);
    } while (n > 1);
}

struct PackedFormat {
    unsigned char bits;
    unsigned char rawCount;
    unsigned short unk02;
    float range;
    float minimum;
};

// Writes raw float bytes for the first rawCount values, then quantizes the rest into packed bit fields and flushes the accumulator to dst.
// @fnv 0x00e51f60
// src: HAVOK_LIB 0x00e51f60
void _hkQuantizeReal(const float* afSource, unsigned int count, const PackedFormat* format, unsigned char* pucDest)
{
    for (int i = 0; i < format->rawCount; ++i) {
        union FloatBits { float f; unsigned int u; } value;
        value.f = afSource[i];
        *pucDest++ = (unsigned char)value.u;
        *pucDest++ = (unsigned char)(value.u >> 8);
        *pucDest++ = (unsigned char)(value.u >> 16);
        *pucDest++ = (unsigned char)(value.u >> 24);
    }
    unsigned int levels = 1 << format->bits;
    unsigned int i = format->rawCount;
    int bitCount = 0;
    unsigned int accumulator = 0;
    for (; i < count; ++i) {
        float normalized;
        if (format->range < 1.1920928955078125e-7f)
            normalized = 0.0f;
        else
            normalized = (afSource[i] - format->minimum) / format->range;
        unsigned int quantized = (unsigned int)(levels * normalized);
        if (quantized > levels - 1)
            quantized = levels - 1;
        accumulator |= quantized << bitCount;
        bitCount += format->bits;
        if (bitCount > 15) {
            *pucDest++ = (unsigned char)accumulator;
            *pucDest++ = (unsigned char)(accumulator >> 8);
            accumulator >>= 16;
            bitCount -= 16;
        }
    }
    if (bitCount > 0) {
        *pucDest = (unsigned char)accumulator;
        if (bitCount > 8)
            pucDest[1] = (unsigned char)(accumulator >> 8);
    }
}

// @fnv 0x00e520b0
void __cdecl PackFourFloatsToNibbles(const float* afValues, unsigned char* aucPacked)
{
    unsigned char aucChannels[4];
    unsigned int i = 0;
    aucChannels[0] = (unsigned char)(7 - (unsigned char)(int)(afValues[i++] * -7.0));
    aucChannels[1] = (unsigned char)(7 - (unsigned char)(int)(afValues[i++] * -7.0));
    aucChannels[2] = (unsigned char)(7 - (unsigned char)(int)(afValues[i++] * -7.0));
    aucChannels[3] = (unsigned char)(7 - (unsigned char)(int)(afValues[i] * -7.0));
    aucPacked[0] = (unsigned char)(aucChannels[0] | (aucChannels[1] << 4));
    aucPacked[1] = (unsigned char)(aucChannels[2] | (aucChannels[3] << 4));
}

extern const float g_x;

// @fnv 0x00e52f40
// src: GUESS 0x00e52f40 (confidence: low)
float __cdecl Object_GetGlobalValue_00e52f40()
{
    return g_x;
}

extern const float g_010ec960;

// @fnv 0x00e52f50
// src: GUESS 0x00e52f50 (confidence: low)
float __cdecl Runtime_GetField010ec960()
{
    return g_010ec960;
}

extern const float g_010af2f0;

// @fnv 0x00e52f60
// src: GUESS 0x00e52f60 (confidence: low)
float __cdecl Object_GetGlobalValue_00e52f60()
{
    return g_010af2f0;
}

extern const float g_010ec964;

// @fnv 0x00e52f70
// src: GUESS 0x00e52f70 (confidence: low)
float __cdecl Runtime_GetField010ec964()
{
    return g_010ec964;
}

extern const float DAT_010ec968;

// @fnv 0x00e52f80
// src: GUESS 0x00e52f80 (confidence: low)
float __cdecl Object_GetDAT_010ec968_00e52f80()
{
    return DAT_010ec968;
}

extern float DAT_0104da4c;

// @fnv 0x00e52f90
// src: GUESS 0x00e52f90 (confidence: low)
float __cdecl Runtime_GetDAT0104da4c(void)
{
    return DAT_0104da4c;
}

// @fnv 0x00e52fe0
void __cdecl SwapBytes(void* pData)
{
    unsigned char* p = static_cast<unsigned char*>(pData);
    unsigned char* q = p + 1;
    unsigned char t = p[3];
    unsigned char u = p[0];
    p[0] = t;
    p[3] = u;
    t = q[1];
    u = q[0];
    q[0] = t;
    q[1] = u;
}

inline void SwapByte(unsigned char& left, unsigned char& right)
{
    unsigned char temporary = left;
    left = right;
    right = temporary;
}
// Swaps the bytes in each of the three byte pairs at offsets 0-1, 2-3 and 4-5 of the given buffer.
// @fnv 0x00e53000
// src: HAVOK_LIB 0x00e53000
void __cdecl _handleEndianSignedQuaternion48(unsigned char* bytes)
{
    SwapByte(bytes[0], bytes[1]);
    SwapByte(bytes[2], bytes[3]);
    SwapByte(bytes[4], bytes[5]);
}

extern "C" void _ReadWriteBarrier(void);

// @fnv 0x00e53030
// src: HAVOK_LIB 0x00e53030
void __cdecl _handleEndianSignedQuaternion128(unsigned char* pucBuffer)
{
    unsigned char a;
    unsigned char b;

    a = pucBuffer[3];
    b = pucBuffer[0];
    pucBuffer[0] = a;
    pucBuffer[3] = b;
    _ReadWriteBarrier();

    a = pucBuffer[2];
    b = pucBuffer[1];
    pucBuffer[1] = a;
    pucBuffer[2] = b;
    _ReadWriteBarrier();

    a = pucBuffer[7];
    b = pucBuffer[4];
    pucBuffer[4] = a;
    pucBuffer[7] = b;
    _ReadWriteBarrier();

    a = pucBuffer[6];
    b = pucBuffer[5];
    pucBuffer[5] = a;
    pucBuffer[6] = b;
    _ReadWriteBarrier();

    a = pucBuffer[11];
    b = pucBuffer[8];
    pucBuffer[8] = a;
    pucBuffer[11] = b;
    _ReadWriteBarrier();

    a = pucBuffer[10];
    b = pucBuffer[9];
    pucBuffer[9] = a;
    pucBuffer[10] = b;
}

class FUN_00e53160 {
public:
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;

    FUN_00e53160(float fX, float fY, float fZ, float fW);
};

// @fnv 0x00e53160
FUN_00e53160::FUN_00e53160(float fX, float fY, float fZ, float fW) : m_fVectorY(fX), m_fVectorZ(fY), m_fScalarPart(fZ), m_fVectorX(fW) {
}

struct FUN_00e53180_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e53180_cls(const float* pSrc);
};

// @fnv 0x00e53180
FUN_00e53180_cls::FUN_00e53180_cls(const float* afValues)
{
    m_00 = afValues[0];
    m_04 = afValues[1];
    m_08 = afValues[2];
    m_0c = afValues[3];
}

struct FUN_00e531a0_struct {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;

    FUN_00e531a0_struct* ComputeValue_00e531a0(const FUN_00e531a0_struct* other);
};

// Adds the four float components of other into this object's components and returns this.
// @fnv 0x00e531a0
// src: GUESS 0x00e531a0 (confidence: low)
FUN_00e531a0_struct* FUN_00e531a0_struct::ComputeValue_00e531a0(const FUN_00e531a0_struct* other)
{
    m_00 += other->m_00;
    m_04 += other->m_04;
    m_08 += other->m_08;
    m_0c += other->m_0c;
    return this;
}

// FUN_00e531d0: thiscall member of a 4-float vector; subtracts a vector
// (given by pointer/reference) from itself, in place, and returns itself.
struct FUN_00e531d0_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e531d0_cls* SubtractFourComponents(const float* pOther);
};

// Subtracts the four floats pointed to by pOther from m_00..m_0c and returns this.
// @fnv 0x00e531d0
// src: GUESS 0x00e531d0 (confidence: high)
FUN_00e531d0_cls* FUN_00e531d0_cls::SubtractFourComponents(const float* pOther)
{
    m_00 -= pOther[0];
    m_04 -= pOther[1];
    m_08 -= pOther[2];
    m_0c -= pOther[3];
    return this;
}

struct FUN_00e53200_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e53200_cls(float s);
};

// Multiplies the four float members m_00, m_04, m_08 and m_0c by s.
// @fnv 0x00e53200
FUN_00e53200_cls::FUN_00e53200_cls(float afScale)
{
    m_00 = m_00 * afScale;
    m_04 = m_04 * afScale;
    m_08 = m_08 * afScale;
    m_0c = m_0c * afScale;
}

struct E53230Color {
    float r;
    float g;
    float b;
    float a;

    E53230Color& DivideByScalar(float fScalar);
};

// operator/=
// Divides the r, g, b and a components by fScalar in place and returns *this.
// @fnv 0x00e53230
E53230Color& E53230Color::DivideByScalar(float fScalar)
{
    r /= fScalar;
    g /= fScalar;
    b /= fScalar;
    a /= fScalar;
    return *this;
}

// @fnv 0x00e53260
// src: GUESS 0x00e53260 (confidence: low)
ConstraintFourLaneCallLocal_00e55080 ConstraintFourLaneCallLocal_00e55080::ProcessAndReturnValue_00e53260(int parameter) {
    ConstraintFourLaneCallLocal_00e55080 local = *this;
    return local.ComputeValue_00e531a0(parameter);
}

struct S_e53300_Vec;
struct S_e53300_Vec {
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    S_e53300_Vec& FUN_00e53200(float f);
    S_e53300_Vec ScaleCopy(float f);
};
// Copies this vector into a temporary and returns the result of scaling that copy by f.
// @fnv 0x00e53300
S_e53300_Vec S_e53300_Vec::ScaleCopy(float afScale) {
    S_e53300_Vec t = *this;
    return t.FUN_00e53200(afScale);
}

struct Quad4 {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    Quad4* Eval(float t);
};

class FUN_00e53350_cls : public Quad4 {
public:
    Quad4 EvalCopy(float t);
};

// Copies this Quad4, evaluates it at t via Eval, and returns the resulting Quad4.
// @fnv 0x00e53350
Quad4 FUN_00e53350_cls::EvalCopy(float t) {
    Quad4 tmp = *this;
    Quad4* r = tmp.Eval(t);
    return *r;
}

struct SpawnedObject {
    void Method(float* pOut, float f);
};

// @fnv 0x00e533a0
// src: GUESS 0x00e533a0 (confidence: medium)
float* __cdecl Object_ScaleCopy_Thunk(float* pOut, float fValue, SpawnedObject* pObj)
{
    pObj->Method(pOut, fValue);
    return pOut;
}

// Thin cdecl wrapper: forwards its first argument and a float to a
// thiscall method of the object given as the third argument, then hands
// the first argument back to the caller.
struct FUN_00e533c0_cls {
    void SetValue(float* pOut, float fValue);
};

// @fnv 0x00e533c0
float* __cdecl SetValueAndReturn(float* pOut, float fValue, FUN_00e533c0_cls* pObj)
{
    pObj->SetValue(pOut, fValue);
    return pOut;
}

double __cdecl FUN_00ec6940(double value);

struct FourComponentVector {
    float x, y, z, w;
    __declspec(noinline) FourComponentVector(float a, float b, float c, float d);
    FourComponentVector hkaNURBS_Point_floor() const;
};
FourComponentVector::FourComponentVector(float a, float b, float c, float d)
    : x(a), y(b), z(c), w(d) {}

// Returns a FourComponentVector whose components are each passed through FUN_00ec6940.
// @fnv 0x00e53440
// src: HAVOK_LIB 0x00e53440
FourComponentVector FourComponentVector::hkaNURBS_Point_floor() const
{
    return FourComponentVector(
        static_cast<float>(FUN_00ec6940(x)),
        static_cast<float>(FUN_00ec6940(y)),
        static_cast<float>(FUN_00ec6940(z)),
        static_cast<float>(FUN_00ec6940(w)));
}

struct FUN_00e53580_cls {
    float GetIndexedValue_00e53580(int idx);
};

// @fnv 0x00e53580
// src: GUESS 0x00e53580 (confidence: low)
float FUN_00e53580_cls::GetIndexedValue_00e53580(int idx) {
    return ((float*)this)[idx];
}

struct S_00e53590_Foo {
    int* __thiscall GetElementAddress_00e53590(int index);
};

// @fnv 0x00e53590
// src: GUESS 0x00e53590 (confidence: low)
int* __thiscall S_00e53590_Foo::GetElementAddress_00e53590(int index) {
    return reinterpret_cast<int*>(this) + index;
}

struct Vec4f {
    float x;
    float y;
    float z;
    float w;
    Vec4f(float a, float b, float c, float d);
    float operator[](int i) const;
    float& operator[](int i);
};

__declspec(noinline) Vec4f::Vec4f(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__declspec(noinline) float Vec4f::operator[](int i) const
{
    return (&x)[i];
}

__declspec(noinline) float& Vec4f::operator[](int i)
{
    return (&x)[i];
}

// Returns a Vec4f whose components are the component-wise minimum of a and b.
// @fnv 0x00e53720
// src: HAVOK_LIB 0x00e53720
Vec4f hkaNURBS_Point_Min(const Vec4f& a, const Vec4f& b)
{
    Vec4f result(0.0f, 0.0f, 0.0f, 0.0f);
    result[0] = a[0] < b[0] ? a[0] : b[0];
    result[1] = a[1] < b[1] ? a[1] : b[1];
    result[2] = a[2] < b[2] ? a[2] : b[2];
    result[3] = a[3] < b[3] ? a[3] : b[3];
    return result;
}

// Binary-searches the float array p between indices a and b for the interval where p[mid] <= value < p[mid+1], returning mid.
// @fnv 0x00e53830
int __cdecl FindFloatInterval(int aiLeft, int aiRight, float value, float** pp)
{
    float* p = *pp;

    if (value == p[aiLeft + 1])
        return aiLeft;

    int right = aiRight;
    int left = aiLeft + 1;
    int mid = (left + right) / 2;

    for (;;)
    {
        if (!(p[mid] > value) && !(p[mid + 1] <= value))
            return mid;

        if (p[mid] > value)
            left = mid;
        else
            right = mid;

        mid = (left + right) / 2;
    }
}

// Evaluates the degree+1 nonzero B-spline basis functions at u for the given span using the knot vector, storing them in basis.
// @fnv 0x00e538a0
void __cdecl ComputeBasisFunctions(int span, float u, int degree, float** knots, float* basis)
{
    float left[4], right[4];
    basis[0] = 1.0f;
    for (int j = 1; j <= degree; ++j) {
        left[j] = u - (*knots)[span + 1 - j];
        right[j] = (*knots)[span + j] - u;
        float saved = 0.0f;
        for (int r = 0; r < j; ++r) {
            float temp = basis[r] / (right[r + 1] + left[j - r]);
            basis[r] = saved + right[r + 1] * temp;
            saved = left[j - r] * temp;
        }
        basis[j] = saved;
    }
}

// Binary-searches the sorted array data for value and returns the index where it should be inserted, clamped to 0..count+1.
// @fnv 0x00e54750
int __cdecl FindInsertIndex(float value, float **table, int count)
{
    int lower = 0;
    int high = count;
    int middle = count / 2;
    float *data = *table;

    if (data[count] < value)
        return count + 1;

    if (data[0] >= value)
        return 0;

    if (middle != 0)
    {
        do
        {
            if (data[middle] >= value)
                high = middle;
            else
                lower = middle;

            middle = (high + lower) / 2;
        } while (lower != middle);
        count = high;
    }

    return count;
}

// Counts the positions where consecutive elements of the float array differ and returns that count plus one.
// @fnv 0x00e54840
int __cdecl CountRuns(float** apValues, int aiCount)
{
    int result = 0;

    for (int i = 0; i < aiCount; ++i)
    {
        if ((*apValues)[i] != (*apValues)[i + 1])
        {
            ++result;
        }
    }

    return result + 1;
}

// Compares adjacent samples at index and index+1 and stores true in result unless index is endIndex or the two samples are equal.
// @fnv 0x00e548f0
bool* __cdecl IsSampleBoundary(bool* result, int index, float** samples, int endIndex) {
    bool value;
    if (index != endIndex && (*samples)[index] == (*samples)[index + 1]) {
        value = false;
    } else {
        value = true;
    }
    *result = value;
    return result;
}

// Scans the first count floats of the array and returns the index of the smallest value, or -1 when count is not positive.
// @fnv 0x00e54930
// src: HAVOK_LIB 0x00e54930
int __cdecl hkaNURBS_MinIndex(float **apValues, int count)
{
    if (count <= 0)
        return -1;

    const float *values = *apValues;
    float minimum = values[0];
    int minimumIndex = 0;
    int index = 1;

    if (count - 1 >= 4) {
        const int limit = count - 3;
        const float *p = values + 3;
        do {
            if (p[-2] < minimum) {
                minimum = p[-2];
                minimumIndex = index;
            }
            if (p[-1] < minimum) {
                minimum = p[-1];
                minimumIndex = index + 1;
            }
            if (p[0] < minimum) {
                minimum = p[0];
                minimumIndex = index + 2;
            }
            if (p[1] < minimum) {
                minimum = p[1];
                minimumIndex = index + 3;
            }
            index += 4;
            p += 4;
        } while (index < limit);
    }

    if (index < count) {
        const float *p = values + index;
        do {
            if (*p < minimum) {
                minimum = *p;
                minimumIndex = index;
            }
            ++index;
            ++p;
        } while (index < count);
    }

    return minimumIndex;
}

void __cdecl hkaNURBS_Point_Dot(int a, int b);

struct FUN_00e54ad0_cls
{
    int unk00;
    void EvaluateSelfDotProduct();
};

// @fnv 0x00e54ad0
// src: GUESS 0x00e54ad0 (confidence: medium)
void FUN_00e54ad0_cls::EvaluateSelfDotProduct()
{
    hkaNURBS_Point_Dot((int)this, (int)this);
}

// The two callees below are unnamed in the binary's symbol table; they bind by position.
extern void __cdecl helper_before();
extern double __cdecl helper_value();

// @fnv 0x00e54ae0
float __cdecl GetHelperValueAsFloat()
{
    helper_before();
    return (float)helper_value();
}

class FUN_00e54b00_cls
{
public:
    float GetHelperValueAsFloat();
    void EvalCopy(int a, float b);
    int hkaNURBS_Point_normalize(int p);
};

// Calls EvalCopy with p and the value from GetHelperValueAsFloat, then returns p.
// @fnv 0x00e54b00
// src: HAVOK_LIB 0x00e54b00
int FUN_00e54b00_cls::hkaNURBS_Point_normalize(int p)
{
    this->EvalCopy(p, this->GetHelperValueAsFloat());
    return p;
}

struct FUN_00e54b20_out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct FUN_00e54b20_src
{
    void* Lookup(FUN_00e54b20_out* out, unsigned int key);
};

struct FUN_00e54b20_sink
{
    void Consume();
};

// Looks up an entry for key via src->Lookup into a local out struct, then calls Consume on the returned sink.
// @fnv 0x00e54b20
void __cdecl LookupAndConsume(FUN_00e54b20_src* src, unsigned int key)
{
    FUN_00e54b20_out out;
    FUN_00e54b20_sink* sink = (FUN_00e54b20_sink*)src->Lookup(&out, key);
    sink->Consume();
}

class E54B50Vector4 {
public:
    double Length() const;

    float x;
    float y;
    float z;
    float w;
};

double E54B50Dot(const E54B50Vector4& kA, const E54B50Vector4& kB);

// Returns the dot product of kA and kB divided by the product of their lengths.
// @fnv 0x00e54b50
float Vector4NormalizedDot(const E54B50Vector4& kA, const E54B50Vector4& kB)
{
    return (float)(E54B50Dot(kA, kB) / (kA.Length() * kB.Length()));
}

struct FUN_00e54ae0_class
{
    void __thiscall GetHelperValueAsFloat();
};

struct FUN_00e532b0_class
{
    FUN_00e54ae0_class* __thiscall UpdateState_00e532b0(void* buffer, void* value);
};

// @fnv 0x00e54ba0
// src: HAVOK_LIB 0x00e54ba0
void __cdecl hkaNURBS_Distance3D(void* value, FUN_00e532b0_class* object)
{
    void* buffer[4];
    object->UpdateState_00e532b0(buffer, value)->GetHelperValueAsFloat();
}

char* __cdecl IsSampleBoundary(int* base, int idx, int b, int c);

// Scans indices starting at a upward, calling IsSampleBoundary, until the returned byte is non-zero, and returns that index.
// @fnv 0x00e54bd0
int __cdecl FindFirstNonZero(int aiStartIndex, int b, int c)
{
    int i = aiStartIndex;
    if (*IsSampleBoundary(&aiStartIndex, i, b, c) == 0) {
        do {
            i++;
        } while (*IsSampleBoundary(&aiStartIndex, i, b, c) == 0);
    }
    return i;
}



inline void E54C50MemCpy4(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *reinterpret_cast<int*>(static_cast<char*>(dst) + i) = *reinterpret_cast<const int*>(static_cast<const char*>(src) + i);
}

// Decrements the array's count, shifts elements after index left by one, then decrements elements from index to end.
// @fnv 0x00e54c50
void RemoveAndDecrement(int index, hkArrayBase<int>& array, int end)
{
    array.m_iElementCount--;
    E54C50MemCpy4(&array.m_data[index], &array.m_data[index + 1], (array.m_iElementCount - index) * sizeof(int));
    for (int i = index; i < end; i++)
        array.m_data[i]--;
}

namespace fnv_00e55080 {

extern const double DAT_010290f8;
void __cdecl hkaNURBS_CurvePoint(ConstraintFourLaneCallLocal_00e55080* result, int a, int b, int c, int d, float value);
float __cdecl LookupAndConsume(const ConstraintFourLaneCallLocal_00e55080* a, const ConstraintFourLaneCallLocal_00e55080* b);

// @fnv 0x00e55080
unsigned char* __cdecl CheckPointsWithinThreshold(
    unsigned char* result, int a, int b, int c, int d,
    int count, const ConstraintFourLaneCallLocal_00e55080** points, const float** weights, float threshold)
{
    *result = 1;
    if (count >= 0) {
        double limit = threshold * DAT_010290f8;
        const float* weight = *weights;
        const ConstraintFourLaneCallLocal_00e55080* point = *points;
        int remaining = count + 1;
        do {
            ConstraintFourLaneCallLocal_00e55080 v = *point;
            ConstraintFourLaneCallLocal_00e55080 transformedPoint;
            hkaNURBS_CurvePoint(&transformedPoint, a, b, d, c, *weight);
            if (LookupAndConsume(&v, &transformedPoint) > limit) {
                *result = 0;
            }
            ++point;
            ++weight;
        } while (--remaining);
    }
    return result;
}
}  // namespace fnv_00e55080

struct Float4 { float x, y, z, w; };
extern const double DAT_01016978;
void __cdecl hkaNURBS_CurvePoint(Float4* out, int a, int b, int c, int d, float input);
float __cdecl LookupAndConsume(const Float4* left, const Float4* right);

// @fnv 0x00e55140
unsigned char* __cdecl CheckVerticesAboveThresholds(unsigned char* result, int a, int b, int c, int d, int last,
                          Float4** verticesPtr, float** valuesPtr, float** thresholdsPtr)
{
    int index = 0;
    if (last >= 0) {
        float* thresholds = *thresholdsPtr;
        Float4* vertices = *verticesPtr;
        int delta = (char*)*valuesPtr - (char*)thresholds;
        do {
            Float4 lhsVertex = *vertices;
            Float4 rhs;
            hkaNURBS_CurvePoint(&rhs, a, b, d, c, *(float*)((char*)thresholds + delta));
            if (LookupAndConsume(&lhsVertex, &rhs) > (float)(*thresholds + DAT_01016978)) {
                *result = 0;
                return result;
            }
            ++index;
            ++vertices;
            ++thresholds;
        } while (index <= last);
    }
    *result = 1;
    return result;
}

extern void __cdecl hkaNURBS_ApproximateCurve(int, int, int, int, float, int, int, int, int);

// Passes all nine arguments through unchanged to FUN_00e58440.
// @fnv 0x00e58740
// src: HAVOK_LIB 0x00e58740
void __cdecl _ApproximateNURBSCurve(int i1, int i2, int i3, int i4, float f5, int i6, int i7, int i8, int i9)
{
    hkaNURBS_ApproximateCurve(i1, i2, i3, i4, f5, i6, i7, i8, i9);
}

struct FUN_00e58820_cls {
    float* m_data;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    void FillWithValue(const float* value);
};

// Fills the first m_10 * m_0c elements of m_data with the float pointed to by value.
// @fnv 0x00e58820
void FUN_00e58820_cls::FillWithValue(const float* value) {
    int n = m_10 * m_0c;
    for (int i = 0; i < n; i++) {
        m_data[i] = *value;
    }
}

struct FUN_00e58890_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int EvaluateValue_00e58890();
};

// @fnv 0x00e58890
// src: GUESS 0x00e58890 (confidence: low)
int FUN_00e58890_Class::EvaluateValue_00e58890() {
    return m_10 * m_0c;
}

struct SpawnArray
{
    void* unk00;
    int unk04;
    unsigned int unk08;
    void Reset()
    {
        unk00 = 0;
        unk04 = 0;
        unk08 = 0x80000000;
    }
};

struct FUN_00e58b50_cls
{
    SpawnArray m_kPointA;
    SpawnArray m_kPointB;
    SpawnArray m_iThirdValue;
    int unk24;
    int unk28;
    FUN_00e58b50_cls* ResetSpawnArrays(int a1, int a2);
};

// Resets the three SpawnArray members and stores the two arguments into unk24 and unk28, returning this.
// @fnv 0x00e58b50
FUN_00e58b50_cls* FUN_00e58b50_cls::ResetSpawnArrays(int a1, int a2)
{
    m_kPointA.Reset();
    m_kPointB.Reset();
    m_iThirdValue.Reset();
    unk24 = a1;
    unk28 = a2;
    return this;
}

namespace fnv_00e58b90 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00e58b90_cls {
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void FreeThreeDynamicArrays();
};

// Frees the three allocated arrays through the audio allocator and resets each pointer, count and capacity to empty.
// @fnv 0x00e58b90
// src: GUESS 0x00e58b90 (confidence: medium)
void FUN_00e58b90_cls::FreeThreeDynamicArrays()
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapA = m_uCapA;
    m_iCountA = 0;
    if ((uCapA & 0x80000000u) == 0) {
        pAllocator->bufFree(m_pDataA, (uCapA & 0x3fffffffu) * 4);
    }
    m_pDataA = 0;
    m_uCapA = 0x80000000u;

    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    unsigned int uCapB = m_uCapB;
    m_iCountB = 0;
    if ((uCapB & 0x80000000u) == 0) {
        pAllocator2->bufFree(m_pDataB, (uCapB & 0x3fffffffu) * 4);
    }
    m_pDataB = 0;
    m_uCapB = 0x80000000u;

    hkMemoryRouter* pHolder3 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator3 = reinterpret_cast<hkMemoryAllocator*>(pHolder3->m_heap);
    unsigned int uCapC = m_uCapC;
    m_iCountC = 0;
    if ((uCapC & 0x80000000u) == 0) {
        pAllocator3->bufFree(m_pDataC, (uCapC & 0x3fffffffu) * 4);
    }
    m_pDataC = 0;
    m_uCapC = 0x80000000u;
}
}  // namespace fnv_00e58b90

namespace fnv_00e58c30 {
extern "C" void _ReadWriteBarrier(void);

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize) throw();

struct ValueArray {
    int* data;
    int count;
    unsigned int capFlags;
};

struct FUN_00e58c30_cls {
    ValueArray m_arr00;
    ValueArray m_arr0c;
    ValueArray m_arr18;

    float* AppendTriple(int a1, int a2, float a3);
};

// If a3 is non-zero, appends a1 and a2 to m_arr0c and m_arr18 and a3 to m_arr00, growing each array as needed, and returns a pointer to the stored float.
// @fnv 0x00e58c30
float* FUN_00e58c30_cls::AppendTriple(int aiFirst, int aiSecond, float afValue)
{
    if (afValue != 0.0f) {
        ValueArray* arr = &m_arr0c;
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        if (arr->count == (int)(arr->capFlags & 0x3fffffffu)) {
            fnv_00e58c30::ResizeAudioStream(holder->m_heap, arr, 4);
        }
        int* slot0 = (int*)((unsigned int)arr->data + *(volatile int*)&arr->count * 4);
        *slot0 = aiFirst;
        arr->count++;

        arr = &m_arr18;
        holder = hkMemoryRouter_getInstance();
        if (arr->count == (int)(arr->capFlags & 0x3fffffffu)) {
            fnv_00e58c30::ResizeAudioStream(holder->m_heap, arr, 4);
        }
        int* slot1 = (int*)((unsigned int)arr->data + *(volatile int*)&arr->count * 4);
        *slot1 = aiSecond;
        arr->count++;

        arr = &m_arr00;
        holder = hkMemoryRouter_getInstance();
        if (arr->count == (int)(arr->capFlags & 0x3fffffffu)) {
            fnv_00e58c30::ResizeAudioStream(holder->m_heap, arr, 4);
        }
        unsigned int idx = (unsigned int)arr->count;
        float* base = (float*)arr->data;
        base[idx] = afValue;
        arr->count++;
        return base + idx;
    }
}
}  // namespace fnv_00e58c30

namespace fnv_00e58cf0 {
struct AllocatorIface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* hkMemoryAllocator(int* pSize);
    virtual void Free(void* pBuffer, unsigned int size);
};

hkMemoryRouter* hkMemoryRouter_getInstance();
void hkArrayUtil__reserve(AllocatorIface* alloc, void* arr, unsigned int newCap, int elemSize);

class FUN_00e58cf0_cls
{
public:
    float* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    FUN_00e58cf0_cls* InitFloatArray(int count, int stride, float fill);
};

// Initializes the object with count, stride and fill, allocates storage for count*stride floats via the allocator and fills every element with fill.
// @fnv 0x00e58cf0
FUN_00e58cf0_cls* FUN_00e58cf0_cls::InitFloatArray(int count, int stride, float fill)
{
    m_0c = (unsigned int)count;
    int total = count * stride;
    m_00 = 0;
    m_04 = 0;
    m_08 = 0x80000000u;
    m_10 = (unsigned int)stride;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    AllocatorIface* alloc = reinterpret_cast<AllocatorIface*>(holder->m_heap);
    unsigned int cap = m_08 & 0x3fffffffu;
    if ((int)cap < total)
    {
        int newCap = (int)cap * 2;
        if (total >= newCap)
        {
            newCap = total;
        }
        hkArrayUtil__reserve(alloc, this, (unsigned int)newCap, 4);
    }
    m_04 = (unsigned int)total;
    for (int i = 0; i < total; i++)
    {
        m_00[i] = fill;
    }
    return this;
}
}  // namespace fnv_00e58cf0

namespace fnv_00e58df0 {
struct HkHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct FUN_00e58df0_cls;
void* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void* allocator, FUN_00e58df0_cls* arr, int newCap, int elemSize);

struct FUN_00e58df0_cls {
    float* m_00;
    int m_04;
    unsigned int m_08;
    int m_0C;
    int m_10;
    int EvaluateValue_00e58890();
    FUN_00e58df0_cls* CopyFrom(FUN_00e58df0_cls* src);
};

// @fnv 0x00e58df0
FUN_00e58df0_cls* FUN_00e58df0_cls::CopyFrom(FUN_00e58df0_cls* src) {
    m_00 = 0;
    m_04 = 0;
    m_08 = 0x80000000u;
    m_0C = src->m_0C;
    m_10 = src->m_10;
    int count = EvaluateValue_00e58890();
    HkHolder* holder = reinterpret_cast<HkHolder*>(hkMemoryRouter_getInstance());
    void* alloc = holder->m_pAllocator;
    int cap = (int)(m_08 & 0x3fffffffu);
    if (cap < count) {
        int newCap = cap + cap;
        if (count >= newCap) {
            newCap = count;
        }
        hkArrayUtil__reserve(alloc, this, newCap, 4);
    }
    int total = m_0C * m_10;
    m_04 = count;
    int i = 0;
    if (total > 0) {
        do {
            m_00[i] = src->m_00[i];
            ++i;
        } while (i < m_0C * m_10);
    }
    return this;
}
}  // namespace fnv_00e58df0

// Converts samples in place to first differences, walking backwards in groups of four and then one by one.
// @fnv 0x00e59230
void __cdecl DifferenceInPlace(float* samples, unsigned int count)
{
    float* current = &samples[count - 1];
    unsigned int processed = 1;
    if (static_cast<int>(count - 1) >= 4) {
        unsigned int groups = ((count - 5) >> 2) + 1;
        processed = groups * 4 + 1;
        do {
            current[0] -= current[-1];
            current[-1] -= current[-2];
            current[-2] -= current[-3];
            current[-3] -= current[-4];
            current -= 4;
        } while (--groups != 0);
    }
    if (processed < count) {
        unsigned int remaining = count - processed;
        do {
            current[0] -= current[-1];
            --current;
        } while (--remaining != 0);
    }
}

struct FUN_00e5c490_entry
{
    unsigned int m_ptr;
    unsigned int m_unk04;
};

int CompareStringsCaseInsensitive(unsigned int item, unsigned int ctx);

class FUN_00e5c490_cls
{
public:
    unsigned int m_unk00;
    FUN_00e5c490_entry* m_pEntries;
    int m_uiItemCount;

    int FindEntryIndex(unsigned int a1);
};

// Scans m_pEntries for the first entry whose masked m_ptr matches a1 via CompareStringsCaseInsensitive and returns its index, or -1 if none match.
// @fnv 0x00e5c490
int FUN_00e5c490_cls::FindEntryIndex(unsigned int a1)
{
    for (int i = 0; i < m_uiItemCount; i++)
    {
        unsigned int item = m_pEntries[i].m_ptr & 0xfffffffe;
        if (CompareStringsCaseInsensitive(item, a1) == 0)
        {
            return i;
        }
    }
    return -1;
}

class AttrEntry_b5103 {
public:
    int m_unk00;
    int m_unk04;
    int* m_pIntegerData;
};

class AttrLog_b5103 {
public:
    virtual void Dummy0() throw();
    virtual void Dummy1() throw();
    virtual void Dummy2() throw();
    virtual void Assert(int level, unsigned int magic, const char* msg, const char* file, int line) throw();
};

class AttrTmp_b5103 {
public:
    void Commit() throw();
    int m_unk00;
    int m_unk04;
};

class AttrWriter_b5103 {
public:
    AttrWriter_b5103(unsigned int* buf, unsigned int size) throw();
    int m_unk00;
    int m_unk04;
    int m_unk08;
    AttrWriter_b5103& Write5(const char* a, const char* name, const char* b, const void* self, const char* c) throw();
    AttrWriter_b5103& Step1() throw();
    AttrWriter_b5103& Step2() throw();
    AttrWriter_b5103& Step3() throw();
    AttrWriter_b5103& Step4() throw();
    AttrWriter_b5103& Step5();
    void Release() throw();
    unsigned int* GetBuf() throw();
};

class AttrStream_b5103 {
public:
    AttrStream_b5103(unsigned int* buf, unsigned int size) throw();
    AttrWriter_b5103 m_w;
};

extern AttrLog_b5103* DAT_01268360_b5103;

class FUN_00e5c6b0_cls {
public:
    AttrEntry_b5103* FindPrimary(const char* name) throw();
    AttrEntry_b5103* FindSecondary(const char* name) throw();
    int GetBoolAttribute(const char* name, bool required, unsigned char* out);
};

// Looks up a bool attribute by name in the primary then secondary table, writes it to out, and asserts if a required attribute is missing.
// @fnv 0x00e5c6b0
int FUN_00e5c6b0_cls::GetBoolAttribute(const char* name, bool required, unsigned char* pucOut)
{
    AttrEntry_b5103* e = FindPrimary(name);
    if (e != 0) {
        *pucOut = *(unsigned char*)e->m_pIntegerData;
        return 0;
    }
    e = FindSecondary(name);
    if (e != 0) {
        *pucOut = (*e->m_pIntegerData != 0);
        return 0;
    }
    if (!required) {
        return 1;
    }
    unsigned int buf[0x80];
    AttrWriter_b5103 s(buf, 0x200);
    s.Write5("Bool attribute ", name, " not found in ", this, " attribute group").Step1().Step2().Step4().Step5();
    AttrLog_b5103* log = DAT_01268360_b5103;
    log->Assert(1, 0xabbaab81, (const char*)&s + 0xc, ".\\Attributes\\hkxAttributeGroup.cpp", 0x32);
    s.Release();
    return 1;
}

struct ConfigValue { unsigned type, identifier; const void* data; };
struct CharBuffer {
    char* destination;
    unsigned capacity, length;
    void FUN_00cb1600(char*, unsigned);
    CharBuffer* ProcessAndReturnValue_00cc01c0(const char*);
    CharBuffer* WriteName(const void*);
    void FUN_00cc00e0();
};
struct DiagnosticLogger {
    virtual void open(); virtual void close(); virtual void flush();
    virtual void report(int, unsigned, const char*, const char*, int);
};
extern DiagnosticLogger* DAT_01268360;
extern const char str_010ecd20[],str_010eccfc[],str_010ecd0c[],str_010eccc8[];
struct ConfigTable {
    ConfigValue* Runtime_ForwardCall_00e5c5d0(const char*);
    ConfigValue* Runtime_ForwardCall_00e5c5b0(const char*);
    ConfigValue* Runtime_ForwardCall_00e5c5f0(const char*);
    int GetUnsignedValue(const char*, bool, unsigned*);
};
// @fnv 0x00e5c7a0
int ConfigTable::GetUnsignedValue(const char* name, bool reportMissing, unsigned* puiValue) {
    ConfigValue* entry = Runtime_ForwardCall_00e5c5d0(name);
    if (entry) {
        *puiValue = *static_cast<const unsigned*>(entry->data);
        return 0;
    }
    entry = Runtime_ForwardCall_00e5c5b0(name);
    if (entry) {
        *puiValue = *static_cast<const unsigned char*>(entry->data) != 0;
        return 0;
    }
    entry = Runtime_ForwardCall_00e5c5f0(name);
    if (entry) {
        *puiValue = *static_cast<const unsigned*>(entry->data);
        return 0;
    }
    if (reportMissing) {
        CharBuffer buffer;
        unsigned text[128];
        buffer.FUN_00cb1600(reinterpret_cast<char*>(text), 512);
        buffer.ProcessAndReturnValue_00cc01c0(str_010ecd20)->ProcessAndReturnValue_00cc01c0(name)->ProcessAndReturnValue_00cc01c0(str_010eccfc)->WriteName(this)->ProcessAndReturnValue_00cc01c0(str_010ecd0c);
        DAT_01268360->report(1, 0xabbaab81u, reinterpret_cast<char*>(text), str_010eccc8, 90);
        buffer.FUN_00cc00e0();
    }
    return 1;
}

struct FUN_00e5c8b0_Node
{
    unsigned int m_00;
};

struct FUN_00e5c8b0_Target
{
    void FindValue(unsigned int a, unsigned int* b);
};

struct FUN_00e5c8b0_Rec
{
    int unk00;
    int unk04;
    FUN_00e5c8b0_Node* m_08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00e5c8b0_Target* m_20;
};

struct FUN_00e5c8b0_Str
{
    int m_00;
    int m_04;
    int m_08;
    void Set(char* buf, unsigned int len);
    FUN_00e5c8b0_Str* Chain5(const char* s0, int a1, const char* s2, int a3, const char* s4);
    FUN_00e5c8b0_Str* Chain0();
    FUN_00e5c8b0_Str* ChainB();
    FUN_00e5c8b0_Str* ChainC();
    void Release();
};

struct FUN_00e5c8b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00e5c8b0_Rec* Runtime_ForwardCall_00e5c610(int a);
    FUN_00e5c8b0_Rec* Runtime_ForwardCall_00e5c5f0(int a);
    int GetAttributeValue(int a, bool flag, unsigned int* out);
};

struct FUN_00e5c8b0_Logger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int level, unsigned int code, const char* msg, const char* file, int line);
};
extern FUN_00e5c8b0_Logger* g_01268360;

// @fnv 0x00e5c8b0
int FUN_00e5c8b0_cls::GetAttributeValue(int a, bool bLogMissing, unsigned int* puiValue)
{
    FUN_00e5c8b0_Rec* pRecord = Runtime_ForwardCall_00e5c610(a);
    if (pRecord != 0)
    {
        *puiValue = pRecord->m_08->m_00 & 0xfffffffe;
        return 0;
    }
    pRecord = Runtime_ForwardCall_00e5c5f0(a);
    if (pRecord != 0)
    {
        pRecord->m_20->FindValue(pRecord->m_08->m_00, puiValue);
        return 0;
    }
    if (bLogMissing)
    {
        FUN_00e5c8b0_Str msg;
        unsigned int buf[0x80];
        msg.Set((char*)buf, 0x200);
        FUN_00e5c8b0_Str* p = msg.Chain5("String attribute ", a, " not found in ", (int)this, " attribute group");
        p = p->Chain0();
        p = p->ChainB();
        p = p->ChainC();
        p->Chain0();
        g_01268360->Report(1, 0xabbaab81, (const char*)buf, ".\\Attributes\\hkxAttributeGroup.cpp", 0x80);
        msg.Release();
    }
    return 1;
}

struct AttrLogBuf {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7c;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8c;
    unsigned int m_90;
    unsigned int m_94;
    unsigned int m_98;
    unsigned int m_9c;
    unsigned int m_a0;
    unsigned int m_a4;
    unsigned int m_a8;
    unsigned int m_ac;
    unsigned int m_b0;
    unsigned int m_b4;
    unsigned int m_b8;
    unsigned int m_bc;
    unsigned int m_c0;
    unsigned int m_c4;
    unsigned int m_c8;
    unsigned int m_cc;
    unsigned int m_d0;
    unsigned int m_d4;
    unsigned int m_d8;
    unsigned int m_dc;
    unsigned int m_e0;
    unsigned int m_e4;
    unsigned int m_e8;
    unsigned int m_ec;
    unsigned int m_f0;
    unsigned int m_f4;
    unsigned int m_f8;
    unsigned int m_fc;
    unsigned int m_100;
    unsigned int m_104;
    unsigned int m_108;
    unsigned int m_10c;
    unsigned int m_110;
    unsigned int m_114;
    unsigned int m_118;
    unsigned int m_11c;
    unsigned int m_120;
    unsigned int m_124;
    unsigned int m_128;
    unsigned int m_12c;
    unsigned int m_130;
    unsigned int m_134;
    unsigned int m_138;
    unsigned int m_13c;
    unsigned int m_140;
    unsigned int m_144;
    unsigned int m_148;
    unsigned int m_14c;
    unsigned int m_150;
    unsigned int m_154;
    unsigned int m_158;
    unsigned int m_15c;
    unsigned int m_160;
    unsigned int m_164;
    unsigned int m_168;
    unsigned int m_16c;
    unsigned int m_170;
    unsigned int m_174;
    unsigned int m_178;
    unsigned int m_17c;
    unsigned int m_180;
    unsigned int m_184;
    unsigned int m_188;
    unsigned int m_18c;
    unsigned int m_190;
    unsigned int m_194;
    unsigned int m_198;
    unsigned int m_19c;
    unsigned int m_1a0;
    unsigned int m_1a4;
    unsigned int m_1a8;
    unsigned int m_1ac;
    unsigned int m_1b0;
    unsigned int m_1b4;
    unsigned int m_1b8;
    unsigned int m_1bc;
    unsigned int m_1c0;
    unsigned int m_1c4;
    unsigned int m_1c8;
    unsigned int m_1cc;
    unsigned int m_1d0;
    unsigned int m_1d4;
    unsigned int m_1d8;
    unsigned int m_1dc;
    unsigned int m_1e0;
    unsigned int m_1e4;
    unsigned int m_1e8;
    unsigned int m_1ec;
    unsigned int m_1f0;
    unsigned int m_1f4;
    unsigned int m_1f8;
    unsigned int m_1fc;
};

struct AttrEntry {
    int m_00;
    int m_04;
    float* m_08;
};

class AttrLogBuilder {
public:
    char* m_pString;
    unsigned short m_sLen;
    unsigned short m_sMaxLen;
    unsigned int m_08;
    void Init(AttrLogBuf* buf, unsigned int size);
    AttrLogBuilder* Build(const char* a, const char* name, const char* b, void* self, const char* c);
    AttrLogBuilder* Chain();
    AttrLogBuilder* Other();
    void Free();
};

class LogSink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Log(int level, unsigned int tag, const char* msg, const char* file, int line);
};

extern LogSink* g_pAttrLogger;

class FUN_00e5c9b0_cls {
public:
    AttrEntry* FindAttr(const char* name);
    int GetFloatAttribute(const char* name, bool log, float* out);
};

// Looks up a float attribute by name; on success writes its value to out and returns 0, otherwise optionally logs an error and returns 1.
// @fnv 0x00e5c9b0
int FUN_00e5c9b0_cls::GetFloatAttribute(const char* name, bool log, float* out)
{
    AttrEntry* entry = FindAttr(name);
    if (entry != 0) {
        *out = *entry->m_08;
        return 0;
    }
    if (log) {
        AttrLogBuf buf;
        AttrLogBuilder msg;
        msg.Init(&buf, 0x200);
        msg.Build("Float attribute ", name, " not found in ", this, " attribute group")
            ->Chain()->Chain()->Other()->Chain();
        g_pAttrLogger->Log(1, 0xabbaab81, (const char*)&buf, ".\\Attributes\\hkxAttributeGroup.cpp", 0x91);
        msg.Free();
    }
    return 1;
}

// FUN_00e5cec0 - forwards this + four stack arguments to SpliceArray,
// with a literal zero inserted as the third argument.

struct FUN_00e5cdb0_class {
    void __thiscall SpliceArray(int a, int b, int c, int d, int e);
    void __thiscall SpliceArray_Thunk(int a, int b, int c, int d);
};

// @fnv 0x00e5cec0
// src: GUESS 0x00e5cec0 (confidence: medium)
void FUN_00e5cdb0_class::SpliceArray_Thunk(int a, int b, int c, int d)
{
    SpliceArray(a, b, 0, c, d);
}

struct S_00e5cfb0_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

struct S_00e65ee0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void __thiscall queryOnTree(int* buffer, int value);
};

// Stores value in a local struct and calls FUN_00e65ee0 with a zeroed buffer and object->unk20.
// @fnv 0x00e5cfb0
// src: HAVOK_LIB 0x00e5cfb0
void __cdecl _hkMoppFindAllVirtualMachine_getAllKeys(S_00e5cfb0_Object* object, int value)
{
    S_00e65ee0_Class local;
    int buffer[2];

    local.unk00 = value;
    buffer[0] = 0;
    buffer[1] = 0;

    local.queryOnTree(buffer, object->unk20);
}

extern float DAT_0104e148;

struct FloatArray_e404b0 {
    float* data;
    int count;
};

template <class T> inline T MaxOf(T a, T b) { return a > b ? a : b; }

// Returns the largest value in the array, starting from DAT_0104e148 and comparing each element with MaxOf.
// @fnv 0x00e404b0
// src: HAVOK_LIB 0x00e404b0
float __cdecl hkaFootstepAnalysisInfo_getMax(FloatArray_e404b0* arr)
{
    float best = DAT_0104e148;
    for (int i = 0; i < arr->count; i++)
        best = MaxOf(best, arr->data[i]);
    return best;
}

extern float _DAT_0104da48;

// Scans the float array referenced by param_1 (count in param_1[1], data at param_1[0]) and returns the smallest value, starting from _DAT_0104da48.
// @fnv 0x00e405c0
float __cdecl FindMinFloat(int *param_1)
{
    float *pfVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    float fStack_4;
    float fTemp;

    fStack_4 = _DAT_0104da48;
    iVar3 = param_1[1];
    iVar4 = 0;
    if (iVar3 >= 4) {
        pfVar1 = (float *)(param_1[0] + 8);
        iVar2 = (iVar3 - 4U >> 2) + 1;
        iVar4 = iVar2 * 4;
        do {
            fTemp = pfVar1[-2];
            if (fStack_4 < fTemp) { } else { fStack_4 = fTemp; }
            fTemp = pfVar1[-1];
            if (fStack_4 < fTemp) { } else { fStack_4 = fTemp; }
            fTemp = *pfVar1;
            if (fStack_4 < fTemp) { } else { fStack_4 = fTemp; }
            fTemp = pfVar1[1];
            if (fStack_4 < fTemp) { } else { fStack_4 = fTemp; }
            pfVar1 = pfVar1 + 4;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    if (iVar4 < iVar3) {
        pfVar1 = (float *)(param_1[0] + iVar4 * 4);
        iVar3 = iVar3 - iVar4;
        do {
            fTemp = *pfVar1;
            if (fStack_4 < fTemp) { } else { fStack_4 = fTemp; }
            pfVar1 = pfVar1 + 1;
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
    }
    return fStack_4;
}

namespace fnv_00e42960 {
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
struct MonEntry { const char* name; unsigned int ticks; int pad; };
struct MonStream { int unk0; MonEntry* m_kRayEnd; int unk8; MonEntry* m_pRayCursor; };
inline void TimerMark(const char* name)
{
    MonStream* ms = (MonStream*)TlsGetValue(DAT_0126835c);
    MonEntry* p = ms->m_kRayEnd;
    if (p < ms->m_pRayCursor) {
        p->name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        p->ticks = t;
        ms->m_kRayEnd = p + 1;
    }
}
struct E42940Inner { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int m_type; };
// src: HAVOK_LIB 0x00e42940
__declspec(noinline) int __cdecl hkpVehicleCastBatchingManager_getStandardFilterSize(int p)
{
    E42940Inner* inner = *(E42940Inner**)((char*)p + 0x7c);
    return inner->m_type == 2 ? 0x100 : 0;
}
struct VStepJob {
    int Create(int a, int b);
    void ForwardCall_00d04370();
    void hkSemaphore_acquire();
};
void* __cdecl hkMemoryRouter_alignedAlloc(void* alloc, int a, int b);
void __cdecl hkMemoryRouter_alignedFree(void* alloc, void* p);
struct VWorld {
    void Object_DoNothing_00c911a0();
    void hkpWorld_unlockReadOnly();
};
struct VCollector {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void vfn_0c(void* a, int b);
    virtual void vfn_10();
};
struct VInfo { void hkJobQueue_processAllJobs(); };
struct VSim {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void vfn_1c();
    virtual int vfn_20(int n);
    virtual void vfn_24(VWorld* w, int k, int n, VInfo* info, VStepJob* job, int mark);
    virtual void vfn_28(void* p, int n, int mark);
    void RunVehicleSync(VWorld* world, VCollector* coll, VInfo* info, int n);
};
// Marks a timer, allocates a step job, runs the vehicle sync step via vfn_24, updates the collector, info and world, then frees the job and restores the mark.
// @fnv 0x00e42960
void VSim::RunVehicleSync(VWorld* world, VCollector* coll, VInfo* info, int aiCount)
{
    TimerMark("TtDoVehiclesSynchronously");
    vfn_1c();
    int size = vfn_20(aiCount);
    HolderStub* h = hkMemoryRouter_getInstance();
    int mark = h->unk00;
    h->unk00 = mark + ((size + 0x7f) & ~0x7f);
    void* alloc = hkMemoryRouter_getInstance()->m_pAllocator;
    VStepJob* job = (VStepJob*)hkMemoryRouter_alignedAlloc(alloc, 4, 0x80);
    if (job)
        job->Create(0, 1000);
    vfn_24(world, hkpVehicleCastBatchingManager_getStandardFilterSize((int)world), aiCount, info, job, mark);
    world->Object_DoNothing_00c911a0();
    coll->vfn_0c(info, 0xb);
    info->hkJobQueue_processAllJobs();
    coll->vfn_10();
    job->hkSemaphore_acquire();
    world->hkpWorld_unlockReadOnly();
    job->ForwardCall_00d04370();
    HolderStub* h2 = hkMemoryRouter_getInstance();
    hkMemoryRouter_alignedFree(h2->m_pAllocator, job);
    vfn_28((char*)world + 0x1d0, aiCount, mark);
    hkMemoryRouter_getInstance()->unk00 = mark;
    TimerMark("Et");
}
}  // namespace fnv_00e42960

extern int DAT_010e60c4;

struct FUN_00e44070 {
    int* volatile m_00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile float m_08;
    volatile float m_0c;
    void* volatile m_10;
    volatile int m_14;
    volatile unsigned int m_18;

    FUN_00e44070();
};

// @fnv 0x00e44070
FUN_00e44070::FUN_00e44070()
{
    m_06 = 1;
    m_00 = &DAT_010e60c4;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0x80000000u;
    m_08 = 0.0f;
    m_0c = 0.0f;
}

class PrimaryE45 {
public:
    virtual ~PrimaryE45();

    int unk04;
};

class ListenerAE45 {
public:
    virtual void OnAdded();
};

class ListenerBE45 {
public:
    virtual void OnRemoved();
};

class ListenerCE45 {
public:
    virtual void OnActivated();
};

class ListenerDE45 {
public:
    virtual void OnDeactivated();
};

class BaseE45 : public PrimaryE45, public ListenerAE45, public ListenerBE45, public ListenerCE45, public ListenerDE45 {
public:
    BaseE45();
    virtual ~BaseE45();

    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

class EnabledFlagE45 {
public:
    __forceinline EnabledFlagE45() : m_bEnableState(true) {}

    bool m_bEnableState;
};

class SlotTableE45 {
public:
    __forceinline SlotTableE45()
        : m_pv00(0),
          m_pv04(0),
          m_pv08(0),
          m_pv0C(0),
          m_pv10(0),
          m_pv14(0),
          m_pv18(0),
          m_pv1C(0),
          m_pv20(0),
          m_pv24(0),
          m_pv28(0),
          m_pv2C(0),
          m_pv30(0),
          m_pv34(0),
          m_pv38(0),
          m_pv3C(0),
          m_pv40(0),
          m_pv44(0),
          m_pv48(0),
          m_pv4C(0),
          m_pv50(0),
          m_pv54(0),
          m_pv58(0),
          m_pv5C(0),
          m_pv60(0),
          m_pv64(0),
          m_pv68(0),
          m_pv6C(0),
          m_pv70(0),
          m_pv74(0),
          m_pv78(0),
          m_pv7C(0)
    {
    }

    void* m_pv00;
    void* m_pv04;
    void* m_pv08;
    void* m_pv0C;
    void* m_pv10;
    void* m_pv14;
    void* m_pv18;
    void* m_pv1C;
    void* m_pv20;
    void* m_pv24;
    void* m_pv28;
    void* m_pv2C;
    void* m_pv30;
    void* m_pv34;
    void* m_pv38;
    void* m_pv3C;
    void* m_pv40;
    void* m_pv44;
    void* m_pv48;
    void* m_pv4C;
    void* m_pv50;
    void* m_pv54;
    void* m_pv58;
    void* m_pv5C;
    void* m_pv60;
    void* m_pv64;
    void* m_pv68;
    void* m_pv6C;
    void* m_pv70;
    void* m_pv74;
    void* m_pv78;
    void* m_pv7C;
};

class FUN_00e45530_Manager : public BaseE45 {
public:
    FUN_00e45530_Manager();
    virtual ~FUN_00e45530_Manager();

    EnabledFlagE45 m_kEnabled;
    SlotTableE45 m_kSlots;
};

// Initializes the manager by constructing its base and default-constructing the enabled flag and slot table members.
// @fnv 0x00e45530
FUN_00e45530_Manager::FUN_00e45530_Manager()
{
}

struct AllocationHeap {
    virtual void Unused0();
    virtual void* Allocate(unsigned int bytes);
    virtual void Unused8();
    virtual void UnusedC();
    virtual void Deallocate(void* pointer, unsigned int bytes);
};

template <class T>
static __forceinline void HkArray_ClearAndRelease(hkArrayBase<T>& self);

template <class T>
static __forceinline void HkArray_ClearAndRelease(hkArrayBase<T>& self)
{
        HolderStub* mgr = hkMemoryRouter_getInstance();
        AllocationHeap* heap = (AllocationHeap*)mgr->m_pAllocator;
        int cap = self.m_iCapacityState;
        self.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            heap->Deallocate(self.m_data, (cap & 0x3fffffff) * 4);
        }
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct CBase0 {
    virtual ~CBase0() throw() {}
    int m_ref;
};
struct CBase8 {
    virtual ~CBase8() throw() {}
};
struct CBaseC {
    virtual ~CBaseC() throw() {}
};
struct CBase10 {
    virtual ~CBase10() throw() {}
};
struct CBase14 {
    virtual ~CBase14() throw() {}
};
struct CShape : CBase0, CBase8, CBaseC, CBase10, CBase14 {
    virtual ~CShape() throw() {}
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct FUN_00e46900 : CShape, hkpEntityListener {
    hkArrayBase<hkpEntity*> m_kActorEntries;

    virtual ~FUN_00e46900() throw();
};

// @fnv 0x00e46900
FUN_00e46900::~FUN_00e46900() throw() {
    for (int i = 0; i < m_kActorEntries.m_iElementCount; ++i) {
        if (m_kActorEntries.m_data[i]->getEntityListeners().indexOf(this) >= 0) {
            m_kActorEntries.m_data[i]->removeEntityListener(this);
        }
    }
    HkArray_ClearAndRelease(m_kActorEntries);
}

struct Ref { void FUN_00c90510(); };
int hkMeshPrimitiveUtil_calculateNumIndices(unsigned char,int);
struct Entry { Ref* name; Ref* pClassInfo; unsigned char type; unsigned char flags; unsigned short reserved; int count; unsigned char storage; unsigned char ReplaceImpactData; unsigned short reserved12; void* data; int unk18; int unk1c; int length() const { int t=type; return hkMeshPrimitiveUtil_calculateNumIndices(t,count); } };

hkMemoryRouter* getRouter();
int hkMeshPrimitiveUtil_calculateNumIndices(unsigned char type,int count);
extern "C" void hkArrayUtil__reserve(hkMemoryAllocator*,void*,int,int);
void hkString_memCpy(void*,const void*,int);
struct String { void* value; void init() throw(); void assign(const char*) throw(); };
struct ArrayBase {
 void* data; int size; int capacity;
 ArrayBase():data(0),size(0),capacity(0x80000000){}
 int getCapacity() const {return capacity & 0x3fffffff;}
 static void grow(hkMemoryAllocator& heap,ArrayBase* a,int n,int stride) { int cap=a->getCapacity(); if(cap<n) hkArrayUtil__reserve(&heap,a,n<2*cap?2*cap:n,stride); }
 void reserve(hkMemoryAllocator& heap,int n,int stride){grow(heap,this,n,stride);}
};
template<class T> struct Arr : ArrayBase {
 void reserve(hkMemoryAllocator& heap,int n){ArrayBase::reserve(heap,n,sizeof(T));}
 void SetSizeAndGrow(hkMemoryAllocator& heap,int n){reserve(heap,n);size=n;}
 T* expand(hkMemoryAllocator& heap,int n) {int old=size; reserve(heap,old+n); size+=n; return (T*)data+old;}
};
struct Base { virtual void dummy(); unsigned short flags; short refs; Base(){refs=1;} };
struct FUN_00e4a1d0:Base {
 Arr<Entry> entries; Arr<unsigned short> shorts; Arr<unsigned int> ints; String label;
 FUN_00e4a1d0(const Entry* source,int count);
 virtual void dummy();
};
// Initializes label, reserves shorts/ints/entries from the router heap, copies each source Entry and its data into the matching storage array.
// @fnv 0x00e4a1d0
FUN_00e4a1d0::FUN_00e4a1d0(const Entry* source,int count) {
 label.init(); label.assign(0);
 int iShortCount=0; int iIntCount=0;
 for(int i=0;i<count;++i) { int n=source[i].length(); switch(source[i].storage){case 1:iShortCount+=n;break;case 2:iIntCount+=n;break;} }
 shorts.reserve(getRouter()->heap(),iShortCount); ints.reserve(getRouter()->heap(),iIntCount); entries.SetSizeAndGrow(getRouter()->heap(),count);
 for(int i=0;i<count;++i){ Entry& dest=((Entry*)entries.data)[i]; dest=source[i]; dest.name->FUN_00c90510(); if(dest.pClassInfo)dest.pClassInfo->FUN_00c90510();
 switch(source[i].storage){case 2:{int n=source[i].length(); unsigned int* data=ints.expand(getRouter()->heap(),n); hkString_memCpy(data,source[i].data,n*4); dest.data=data; break;}
 case 1:{int n=source[i].length(); unsigned short* data=shorts.expand(getRouter()->heap(),n); hkString_memCpy(data,source[i].data,n*2); dest.data=data; break;}}
 }
}

struct E51F00Format
{
    unsigned char bits;
    unsigned char rawCount;
    unsigned short unk02;
    float range;
    float minimum;
};

static void __declspec(noinline) E51F00Helper(float* data, int count, float* minOut, float* maxOut)
{
    if (count <= 0)
    {
        *maxOut = 0.0f;
        *minOut = 0.0f;
        return;
    }
    *minOut = data[0];
    *maxOut = data[0];
    int i = 0;
    if (count >= 4)
    {
        for (; i <= count - 4; i += 4)
        {
            if (data[i] < *minOut) *minOut = data[i];
            else if (data[i] > *maxOut) *maxOut = data[i];
            if (data[i + 1] < *minOut) *minOut = data[i + 1];
            else if (data[i + 1] > *maxOut) *maxOut = data[i + 1];
            if (data[i + 2] < *minOut) *minOut = data[i + 2];
            else if (data[i + 2] > *maxOut) *maxOut = data[i + 2];
            if (data[i + 3] < *minOut) *minOut = data[i + 3];
            else if (data[i + 3] > *maxOut) *maxOut = data[i + 3];
        }
    }
    for (; i < count; ++i)
    {
        if (data[i] < *minOut) *minOut = data[i];
        else if (data[i] > *maxOut) *maxOut = data[i];
    }
}

// @fnv 0x00e51f00
void __cdecl InitFormatFromData(float* data, unsigned int count, E51F00Format* format, unsigned int numBits, unsigned int rawStart)
{
    float min;
    float max;

    format->rawCount = (unsigned char)rawStart;
    E51F00Helper(data + rawStart, count - rawStart, &min, &max);
    format->minimum = min;
    format->range = max - min;
    if ((numBits - 1) <= 0xF)
        format->bits = (unsigned char)numBits;
    else
        format->bits = 8;
}

// Component-wise maximum of two 4-vectors.
// Returns a Vec4f whose components are the component-wise maximum of a and b.
// @fnv 0x00e53610
Vec4f VectorMax(const Vec4f& a, const Vec4f& b)
{
    Vec4f result(0.0f, 0.0f, 0.0f, 0.0f);
    result[0] = a[0] > b[0] ? a[0] : b[0];
    result[1] = a[1] > b[1] ? a[1] : b[1];
    result[2] = a[2] > b[2] ? a[2] : b[2];
    result[3] = a[3] > b[3] ? a[3] : b[3];
    return result;
}

struct L { int* m_00; int m_04; };
// Decrements the list count and shifts the remaining int elements left by one slot starting at idx.
// @fnv 0x00e54c10
// src: HAVOK_LIB 0x00e54c10
void __cdecl hkaNURBS_Remove(int aiIndex, L* list)
{
    list->m_04--;
    int bytes = (list->m_04 - aiIndex) * 4;
    char* d = (char*)&list->m_00[aiIndex];
    char* s = d + 4;
    for (int i = 0; i < bytes; i += 4) *(int*)(d + i) = *(int*)(s + i);
}

struct HolderView { int unk00; int unk04; int unk08; int unk0c; void* volatile m_pAllocator; };
struct FloatArrayRef {
    float* data;
    int size;
    unsigned int capacity;
};

// @fnv 0x00e57210
// src: HAVOK_LIB 0x00e57210
int __cdecl hkaNURBS_DegreeElevateKnotVector(FloatArrayRef* array, int count) {
    int added = CountRuns(reinterpret_cast<float**>(array), count);
    int destination = added + count;
    int newSize = destination + 1;
    HolderStub* holder = hkMemoryRouter_getInstance();
    E4AAA0Allocator* alloc = reinterpret_cast<E4AAA0Allocator*>(reinterpret_cast<HolderView*>(holder)->m_pAllocator);
    unsigned int capacity = array->capacity & 0x3fffffff;
    if ((int)capacity < newSize) {
        int newCapacity = (int)(capacity * 2);
        if (newSize >= newCapacity) {
            newCapacity = newSize;
        }
        hkArrayUtil__reserve(alloc, array, newCapacity, 4);
    }
    array->size = newSize;
    int dest = destination;

    for (int n = count; n > 0; --n) {
        if (array->data[n] != array->data[n-1]) array->data[dest--] = array->data[n];
        array->data[dest--] = array->data[n];
    }
    return added - 2;
}


void hkArrayUtil__reserve(hkMemoryAllocator* alloc, hkArrayBase<float>* arr, int newCap, int elemSize);
static __forceinline void FloatArray_reserve(hkArrayBase<float>& self, hkMemoryAllocator& alloc, int n);

static __forceinline void FloatArray_reserve(hkArrayBase<float>& self, hkMemoryAllocator& alloc, int n)
{
        int cap = self.getCapacity();
        if (cap < n) {
            int c = 2 * cap;
            hkArrayUtil__reserve(&alloc, (&self), n < c ? c : n, 4);
        }
    }

hkMemoryRouter* GetMemoryRouter();

// @fnv 0x00e57370
int RemoveAdjacentDuplicates(hkArrayBase<float>* arr, int last)
{
    int out = 0;
    for (int i = 0; i < last; i++) {
        if (arr->m_data[i] == arr->m_data[i + 1]) {
            arr->m_data[out++] = arr->m_data[i];
        }
    }
    arr->m_data[out] = arr->m_data[last];
    int newSize = out + 1;
    FloatArray_reserve((*(arr)), GetMemoryRouter()->heap(), newSize);
    arr->m_iElementCount = newSize;
    return last - out - 1;
}

// Element-wise subtract another matrix of the same shape from this one.

class E87E0Matrix {
public:
    float* m_pfData;
    int unk04;
    int unk08;
    int m_iRows;
    int m_iColumns;

    float& Element(int i) { return m_pfData[i]; }
    E87E0Matrix& SubtractMatrixElements(const E87E0Matrix& kOther);
};

// Subtracts each element of kOther from this matrix's data in place and returns *this.
// @fnv 0x00e587e0
// src: GUESS 0x00e587e0 (confidence: medium)
E87E0Matrix& E87E0Matrix::SubtractMatrixElements(const E87E0Matrix& kOther)
{
    for (int i = 0; i < m_iRows * m_iColumns; i++)
        Element(i) = Element(i) - kOther.m_pfData[i];
    return *this;
}

class CE588A0Vector {
public:
    double Get(int iIndex);
    int GetSize();
};

// Computes the dot product of two vectors by summing the products of their corresponding elements.
// @fnv 0x00e588a0
float __cdecl DotProduct(CE588A0Vector* pkA, CE588A0Vector* pkB)
{
    int iSize = pkA->GetSize();
    float fSum = 0.0f;
    for (int i = 0; i < iSize; i++)
        fSum += pkA->Get(i) * pkB->Get(i);
    return fSum;
}

struct Stand_e58d90 {
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
    int m_iArrayCapacity;
    int m_iElemSize;
    Stand_e58d90* InitArray(int a1, int a2);
};

// @fnv 0x00e58d90
Stand_e58d90* Stand_e58d90::InitArray(int aiCount, int a2)
{
    m_iArrayCapacity = aiCount;
    int n;
    m_pData = 0;
    m_iArrayLength = 0;
    m_uCapFlags = 0x80000000;
    m_iElemSize = a2;
    n = aiCount * a2;
    HolderStub* holder = hkMemoryRouter_getInstance();
    E4AAA0Allocator* alloc = (E4AAA0Allocator*)holder->m_pAllocator;
    int cap = m_uCapFlags & 0x3fffffff;
    if (cap < n) {
        int cap2 = 2 * cap;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(alloc, this, newSize, 4);
    }
    m_iArrayLength = n;
    return this;
}

extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);

static inline float QSqrt(float v) { return (float)sqrt(v); }

// @fnv 0x00e52a70
void UnpackQuaternion(const unsigned int* packed, float* quat)
{
    int a = (*packed >> 18) & 0x3ff;
    int b = *packed & 0x3ffff;
    double t = a / 1023.0;
    float w = 1.0 - t * t;
    int r = (int)QSqrt((float)b);
    float rf = (float)r;
    float theta = rf / 511.0 * 0.5 * 3.1415927f;
    float twoR = rf * 2;
    float phi = (twoR == 0.0f) ? 0.0f : (b - r * r) / twoR * 0.5 * 3.1415927f;
    volatile float sv = QSqrt(1.0f - w * w);
    float s = sv;
    float fSinTheta = (float)sin(theta);
    float x = (float)cos(phi);
    x = x * fSinTheta;
    x = x * s;
    quat[0] = x;
    float y = (float)sin(phi);
    y = y * fSinTheta;
    y = y * s;
    quat[1] = y;
    float z = (float)cos(theta);
    z = z * s;
    quat[2] = z;
    quat[3] = w;
    if (*packed & 0x10000000)
        quat[0] = -x;
    if (*packed & 0x20000000)
        quat[1] = -y;
    if (*packed & 0x40000000)
        quat[2] = -z;
    if (*packed & 0x80000000)
        quat[3] = -w;
}

extern int DAT_010e7874;
extern int DAT_010e7868;
extern int DAT_010e7854;
extern int DAT_010e7848;
extern int DAT_010e783c;
extern int DAT_010e781c;
extern int DAT_010cb1e4;

struct FUN_00cbfba0_Base {
    void FUN_00cbfba0();
};
struct FUN_00c90510_Reference {
    void FUN_00c90510();
};
struct FUN_00e46b30_Layout {
    void* primaryVtable;
    int referenceCount;
    void* secondaryVtable;
    void* thirdVtable;
    void* fourthVtable;
    void* fifthVtable;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    void* volatile listenerVtable;
    FUN_00c90510_Reference* reference;
};
struct FUN_00e46b30_Class : FUN_00e46b30_Layout {
    FUN_00e46b30_Class* InitializeWithReference(FUN_00c90510_Reference* value);
};
// Calls the base initializer, installs the vtable pointers, stores value in reference and, if non-null, calls FUN_00c90510 on it; returns this.
// @fnv 0x00e46b30
FUN_00e46b30_Class* FUN_00e46b30_Class::InitializeWithReference(FUN_00c90510_Reference* value)
{
    reinterpret_cast<FUN_00cbfba0_Base*>(this)->FUN_00cbfba0();
    listenerVtable = &DAT_010cb1e4;
    primaryVtable = &DAT_010e7874;
    secondaryVtable = &DAT_010e7868;
    thirdVtable = &DAT_010e7854;
    fourthVtable = &DAT_010e7848;
    fifthVtable = &DAT_010e783c;
    listenerVtable = &DAT_010e781c;
    reference = value;
    if (value) {
        value->FUN_00c90510();
    }
    return this;
}

struct FUN_00c905b0_class {
    void __thiscall FUN_00c905b0();
};

extern int DAT_010e7874;
extern int DAT_010e7868;
extern int DAT_010e7854;
extern int DAT_010e7848;
extern int DAT_010e783c;
extern int DAT_010e781c;
extern int DAT_010cb1e4;
extern int DAT_010c3b8c;
extern int DAT_010c3bac;
extern int DAT_010c3b98;
extern int DAT_010c3b80;
extern int DAT_0102e388;

struct FUN_00e46b80_class {
    int* unk00;
    int* unk04;
    int* unk08;
    int* unk0C;
    int* unk10;
    int* unk14;
    int* unk18;
    int* unk1C;
    int* unk20;
    int* unk24;
    int* unk28;
    int* unk2C;
    int* unk30;
    FUN_00c905b0_class* unk34;

    void __thiscall UpdateFields_00e46b80();
};

// Assigns global addresses to the object's pointer fields, calls FUN_00c905b0 on unk34 if set, then reassigns the fields to other globals.
// @fnv 0x00e46b80
// src: GUESS 0x00e46b80 (confidence: low)
void __thiscall FUN_00e46b80_class::UpdateFields_00e46b80()
{
    unk00 = &DAT_010e7874;
    unk08 = &DAT_010e7868;
    unk0C = &DAT_010e7854;
    unk10 = &DAT_010e7848;
    unk14 = &DAT_010e783c;
    unk30 = &DAT_010e781c;

    if (unk34)
        unk34->FUN_00c905b0();

    unk30 = &DAT_010cb1e4;
    unk14 = &DAT_010c3b8c;
    unk10 = &DAT_010c3bac;
    unk0C = &DAT_010c3b98;
    unk08 = &DAT_010c3b80;
    unk00 = &DAT_0102e388;
}

struct FUN_00e46e80 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e46e80();
};

// @fnv 0x00e46e80
FUN_00e46e80::FUN_00e46e80()
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_10 = 0;
}

struct E473C0Owner;

struct E473C0Target {
    virtual void vf00();
    virtual void vf01();
    virtual void __thiscall vf02(E473C0Owner* a1, int a2);
};

struct E473C0Owner {
    int unk00;
    unsigned short unk04;

    void __thiscall FUN_00e47020();
    E473C0Owner* __thiscall FUN_00e473c0(unsigned char flags);
};

// Calls FUN_00e47020, then if bit 0 of flags is set, invokes vf02 on the allocator target with unk04, and returns this.
// @fnv 0x00e473c0
E473C0Owner* __thiscall E473C0Owner::FUN_00e473c0(unsigned char flags) {
    FUN_00e47020();

    if ((flags & 1) != 0) {
        HolderStub* holder = hkMemoryRouter_getInstance();
        E473C0Target* target = static_cast<E473C0Target*>(holder->m_pAllocator);
        target->vf02(this, static_cast<int>(unk04));
    }

    return this;
}

struct FnvCpu_FUN_00e473f0_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    void SetValue(unsigned char arg0);
};
// @fnv 0x00e473f0
// src: GUESS 0x00e473f0 (confidence: low)
void FnvCpu_FUN_00e473f0_CpuObject::SetValue(unsigned char arg0)
{
    value = arg0;
}

extern int DAT_010e81a4;

struct FUN_00e48240 {
    void* m_vTable;
    short m_flags;
    short m_sState;
    int m_uiFilterValue;
    FUN_00e48240(int value);
};

// @fnv 0x00e48240
FUN_00e48240::FUN_00e48240(int value)
{
    m_sState = 1;
    m_vTable = &DAT_010e81a4;
    m_uiFilterValue = value;
}

extern int DAT_010cb76c;
extern int DAT_010cb780;
extern int DAT_010e83b4;

struct SourceData {
    void* m_ppVirtualMethodTable;
    unsigned short m_unknown04,m_flags;
    unsigned char m_uiContentCount,m_unknown09,m_unknown0a,m_unknown0b;
    float m_pHeadNode,m_iSecondInteger;
    int m_third,m_fourth,m_fifth,m_sixth,m_seventh;
};
struct FUN_00e48400 {
    int* m_ppVirtualMethodTable;
    unsigned short m_unknown04,m_flags;
    unsigned char m_uiContentCount,m_unknown09,m_unknown0a,m_unknown0b;
    float m_pHeadNode,m_iSecondInteger;
    int m_third,m_fourth,m_fifth,m_sixth,m_seventh;
    FUN_00e48400(const SourceData* source);
};
// @fnv 0x00e48400
FUN_00e48400::FUN_00e48400(const SourceData* source) {
    m_ppVirtualMethodTable = &DAT_010cb76c;
    m_flags = 1;

    unsigned char state = source->m_uiContentCount;
    *reinterpret_cast<int* volatile*>(&m_ppVirtualMethodTable) = &DAT_010cb780;
    m_uiContentCount = state;

    m_pHeadNode = source->m_pHeadNode;
    m_iSecondInteger = source->m_iSecondInteger;
    m_ppVirtualMethodTable = &DAT_010e83b4;

    m_third = source->m_third;
    m_fourth = source->m_fourth;
    m_fifth = source->m_fifth;
    m_sixth = source->m_sixth;
    m_seventh = source->m_seventh;
}

struct FUN_00e484a0_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char* m_base20;
};
struct FUN_00e484a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int* m_items0C;
    int m_count10;
    void ClearReferencedBytes(FUN_00e484a0_Arg* arg);
};
// For each of m_count10 items, reads the byte at arg->m_base20 + (item >> 8), stores it in the item's low byte, and zeroes that byte.
// @fnv 0x00e484a0
void FUN_00e484a0_Class::ClearReferencedBytes(FUN_00e484a0_Arg* arg)
{
    for (int i = 0; i < m_count10; ++i)
    {
        unsigned int* entry = &m_items0C[i];
        unsigned char* target = arg->m_base20 + (*entry >> 8);
        unsigned char value = *target;
        *(unsigned char*)entry = 0;
        *entry |= value;
        *target = 0;
    }
}

struct FUN_00e484e0_dst {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char* m_20;
};
struct FUN_00e484e0_class {
    int unk00;
    int unk04;
    int unk08;
    unsigned int* m_0c;
    int m_10;
    void ScatterBytes(FUN_00e484e0_dst* dst);
};
// For each of m_10 entries in m_0c, writes the low byte of the entry into dst->m_20 at index entry >> 8.
// @fnv 0x00e484e0
void FUN_00e484e0_class::ScatterBytes(FUN_00e484e0_dst* dst) {
    for (int i = 0; i < m_10; ++i) {
        unsigned int v = m_0c[i];
        unsigned char b = *(unsigned char*)&m_0c[i];
        dst->m_20[v >> 8] = b;
    }
}

extern "C" int DAT_010e8ab0;
extern "C" int DAT_010e8a90;
struct FUN_00e48db0_holder {
    void FUN_00dcd310(float f, void* p);
};
struct FUN_00e48db0_class {
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e48db0_class* __thiscall InitFromFloatAndPointer(float f, void* p);
};
// Calls FUN_00dcd310 with f and p, then stores pointers to DAT_010e8ab0 and DAT_010e8a90 in m_00 and m_10, returning this.
// @fnv 0x00e48db0
FUN_00e48db0_class* FUN_00e48db0_class::InitFromFloatAndPointer(float f, void* p)
{
    ((FUN_00e48db0_holder*)this)->FUN_00dcd310(f, p);
    m_00 = &DAT_010e8ab0;
    m_10 = (int)&DAT_010e8a90;
    return this;
}

int CompareStringsCaseInsensitive(const char* a, const char* b);

struct Node4a5
{
    char pad[0x14];
    unsigned int m_uiName;

    const char* GetName() const { return (const char*)(m_uiName & ~1); }

    Node4a5* FindChildByName(const char* pcName);
};

struct Owner4a5
{
    char pad[0x14];
    Node4a5* m_pkTreeNode;

    Node4a5* EvaluateValue_00e4a550(const char* pcName);
};

// @fnv 0x00e4a550
// src: GUESS 0x00e4a550 (confidence: low)
Node4a5* Owner4a5::EvaluateValue_00e4a550(const char* pcName)
{
    if (!pcName || !m_pkTreeNode)
        return 0;
    if (m_pkTreeNode->GetName() && !CompareStringsCaseInsensitive(m_pkTreeNode->GetName(), pcName))
        return m_pkTreeNode;
    return m_pkTreeNode->FindChildByName(pcName);
}

struct GtrStand_ {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* GetUnk14Address_00e4af40();
};
// @fnv 0x00e4af40
// src: GUESS 0x00e4af40 (confidence: low)
void* GtrStand_::GetUnk14Address_00e4af40()
{
    return &unk14;
}

struct HolderStub;
HolderStub* __cdecl hkMemoryRouter_getInstance();
// @fnv 0x00e4e3f0
// src: XBOX_PDB 0x00e4e3f0
HolderStub* __cdecl hkStackMemory_getInstance()
{
    return hkMemoryRouter_getInstance();
}

// @fnv 0x00e52f10
// src: COMMUNITY 0x00e52f10
void nullsub_293()
{
}

// @fnv 0x00e52f20
// src: COMMUNITY 0x00e52f20
void __cdecl nullsub_294()
{
}

// @fnv 0x00e52f30
// src: COMMUNITY 0x00e52f30
void nullsub_292()
{
}

namespace fnv_00e53130 {
int __cdecl Factorial(int count)
{
    int aiFactorial[11] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };
    if (count <= 0)
        return 1;
    if (count <= 10)
        return aiFactorial[count];
    int iResult = aiFactorial[10];
    for (int i = 11; i <= count; i++)
        iResult *= i;
    return iResult;
}

// Returns the binomial coefficient C(n, k) as n! / ((n - k)! * k!) using the factorial helper.
// @fnv 0x00e53130
int __cdecl BinomialCoefficient(int n, int k)
{
    return Factorial(n) / (Factorial(n - k) * Factorial(k));
}
}  // namespace fnv_00e53130

struct FUN_00e53180_Obj {
    float x;
    float y;
    float z;
    float w;
    void FUN_00e53180(const Float4* source);
};
// @fnv 0x00e546e0
// src: HAVOK_LIB 0x00e546e0
void __cdecl hkaNURBS_CurvePoint_00e546e0(int a, int b, int c, int d, int count,
                            float** inputs, FUN_00e53180_Obj** outputs)
{
    for (int i = 0; i <= count; ++i) {
        Float4 temporary;
        Float4* converted = reinterpret_cast<Float4* (__cdecl*)(Float4*, int, int, int, int, float)>(&hkaNURBS_CurvePoint)(&temporary, a, b, c, d, (*inputs)[i]);
        (*outputs)[i].FUN_00e53180(converted);
    }
}

struct E58E80Object {
    void CopyFrom(int setting);
};
// @fnv 0x00e58e80
// src: GUESS 0x00e58e80 (confidence: low)
E87E0Matrix* __fastcall Object_ProcessAndReturnValue_00e58e80(int setting, int unused, E58E80Object* object, const E87E0Matrix& right) {
    object->CopyFrom(setting);
    E87E0Matrix* matrix = reinterpret_cast<E87E0Matrix*>(object);
    matrix->SubtractMatrixElements(right);
    return matrix;
}

// Computes the inclusive prefix sum of an array of n floats in place, unrolling four elements per iteration and handling the remainder.
// @fnv 0x00e592a0
void __cdecl PrefixSum(float* afValues, unsigned int n)
{
    float sum = *afValues;
    float* q = afValues + 1;
    unsigned int i = 1;

    if ((int)(n - 1) >= 4)
    {
        unsigned int blocks = ((n - 5) >> 2) + 1;
        i = blocks * 4 + 1;
        do
        {
            float fSum0 = *q + sum;
            q += 4;
            q[-4] = fSum0;
            float fSum1 = q[-3] + fSum0;
            q[-3] = fSum1;
            float fSum2 = q[-2] + fSum1;
            q[-2] = fSum2;
            float fSum3 = q[-1] + fSum2;
            q[-1] = fSum3;
            sum = fSum3;
        } while (--blocks != 0);
    }

    if (i < n)
    {
        unsigned int uiRemaining = n - i;
        do
        {
            float t = *q + sum;
            *q = t;
            sum = t;
            ++q;
        } while (--uiRemaining != 0);
    }
}

// Inverts a 2x2 matrix if its determinant is not near zero (within fEps), writing the result to out and returning whether it succeeded.
// @fnv 0x00e59340
hkBool __cdecl InvertMatrix2x2(const float* afMatrix, float* afInverse, float fEps)
{
    float fDet = afMatrix[0] * afMatrix[3] - afMatrix[2] * afMatrix[1];
    if (fDet * fDet < fEps * fEps)
        return false;
    float fInv = 1.0f / fDet;
    float t0 = afMatrix[3] * fInv;
    float t1 = -afMatrix[1] * fInv;
    float t2 = -afMatrix[2] * fInv;
    float t3 = afMatrix[0] * fInv;
    afInverse[0] = t0; afInverse[2] = t1; afInverse[1] = t2; afInverse[3] = t3;
    return true;
}

struct E5B110Ref { void FUN_00c90510(); };
struct E5B110Obj {
    void CopyStateFrom(void* p);
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    E5B110Ref* unka0;
};

// static: VC9 /O2 gives it a register convention (obj in esi, p in eax)
// @fnv 0x00e5b110
// src: HAVOK_LIB 0x00e5b110
static void __declspec(noinline) _copyAtoms(E5B110Obj* obj, void* p)
{
    obj->CopyStateFrom(p);
    if (obj->unka0)
        obj->unka0->FUN_00c90510();
}

// same-file caller (CreatePoweredConstraint passes obj = this + 0x10, p = &arg)
void E5B110Caller(char* q, int a, int b, int c)
{
    _copyAtoms((E5B110Obj*)(q + 0x10), &c);
}

int GetUnsignedValue(const char*, bool, unsigned*);

// @fnv 0x00e5c8a0
// src: GUESS 0x00e5c8a0 (confidence: medium)
int Object_GetUnsignedValue_Thunk(const char* p, bool b, unsigned* u)
{
    return GetUnsignedValue(p, b, u);
}

struct UnkRet;

struct FUN_00e47390_obj {
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p, unsigned int bytes);
};

struct UnkRet {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00e47390_obj* m_10;
};

struct UnkHolder {
    void* m_00;
    unsigned int m_04;
    UnkRet* hkMemoryRouter_getInstance();
    void UpdateState_00e47390();
};

// When m_04 is nonzero, calls virtual v08(m_00, m_04 * 4) on the m_10 object of the FUN_00c85750 result.
// @fnv 0x00e47390
// src: GUESS 0x00e47390 (confidence: low)
void UnkHolder::UpdateState_00e47390() {
    unsigned int count = m_04;
    if (count) {
        void* data = m_00;
        UnkRet* mgr = hkMemoryRouter_getInstance();
        mgr->m_10->v08(data, count * 4);
    }
}

extern float DAT_0108cb00;

class RefObjectE483 {
public:
    RefObjectE483() { m_sReferenceCount = 1; }
    virtual ~RefObjectE483();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

class TypedObjectE483 : public RefObjectE483 {
public:
    TypedObjectE483() { m_type = 0; }
    unsigned char m_type;
};

class FUN_00e48390 : public TypedObjectE483 {
public:
    FUN_00e48390(int a, int b);
    virtual ~FUN_00e48390();
    volatile float m_fCoefficientA;
    float m_fB;
    int m_iB;
    int m_iA;
};
// Constructor: stores a and b in m_iA and m_iB, sets m_fCoefficientA to -1e6, m_fB from DAT_0108cb00 and m_type to 4.
// @fnv 0x00e48390
FUN_00e48390::FUN_00e48390(int a, int b)
{
    m_iA = a;
    m_fCoefficientA = -1e6f;
    m_fB = DAT_0108cb00;
    m_type = 4;
    m_iB = b;
}

// @fnv 0x00e48460
// src: GUESS 0x00e48460 (confidence: high)
unsigned char __cdecl Object_ReturnArgument_00e48460(unsigned char value)
{
    return value;
}

// @fnv 0x00e48470
// src: GUESS 0x00e48470 (confidence: low)
__declspec(noinline) static unsigned int Runtime_EvaluateValue_00e48470(unsigned int uiValue) {
    return uiValue >> 8;
}

unsigned int E48470Shift(unsigned int uiValue) {
    return Runtime_EvaluateValue_00e48470(uiValue);
}

struct e48480_cls { unsigned char b; };
extern "C" e48480_cls* e48480_target(void);
extern "C" unsigned char e48480_val(void);
// @fnv 0x00e48480
// src: GUESS 0x00e48480 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00e48480(e48480_cls* dst, unsigned char val)
{
    *(unsigned char*)dst = 0;
    *(unsigned int*)dst |= (unsigned int)val;
}
void e48480_caller(void) { Object_UpdateFields_00e48480(e48480_target(), e48480_val()); }

// FUN_00e48490: ORs the low byte at [this] with an incoming value shifted
// left by 8, stores the dword back, and returns the shifted value in eax.
// The value arrives in eax via VC9's private calling convention for a
// single-call-site static function, driven by a dummy caller that passes
// two extern-call returns.
union E48490Cell {
    unsigned char m_b0;
    int m_cell;
};

E48490Cell* E48490PtrSrc();
int E48490ValSrc();

// @fnv 0x00e48490
// src: GUESS 0x00e48490 (confidence: low)
static __declspec(noinline) int Runtime_UpdateState_00e48490(E48490Cell* cell, int value)
{
    unsigned int shifted = value << 8;
    cell->m_cell = cell->m_b0 | shifted;
    return shifted;
}

void E48490Driver()
{
    Runtime_UpdateState_00e48490(E48490PtrSrc(), E48490ValSrc());
}

// Writes 0.0f to outMin and outMax when count is non-positive, otherwise scans values and stores the smallest and largest into outMin and outMax.
// @fnv 0x00e51dd0
// src: HAVOK_LIB 0x00e51dd0
static __declspec(noinline) void hkGetSignalRange(float* outMin, float* outMax, const float* values, int count)
{
    if (count <= 0) {
        *outMin = *outMax = 0.0f;
        return;
    }
    *outMin = values[0];
    *outMax = values[0];
    for (int i = 0; i < count; i++) {
        if (values[i] < *outMin)
            *outMin = values[i];
        else if (values[i] > *outMax)
            *outMax = values[i];
    }
}

extern "C" float* mm_min(void);
extern "C" float* mm_max(void);
extern "C" const float* mm_vals(void);
extern "C" int mm_count(void);

void mm_caller(void)
{
    hkGetSignalRange(mm_min(), mm_max(), mm_vals(), mm_count());
}

struct SampleField {
    int NiD3DShaderProgram_GetShaderProgramName();
    float* GetElementPtr(int index, int component);
    void FillWithValue(float* value);
    float GetFloatAt(int index, int component);
};
struct FUN_00e58a20_cls {
    float* m_00;
    int m_04;
    int unk08;
    int* m_0c;
    int unk10;
    int unk14;
    int* m_18;
    void hkaSparseLSQMatrix_float_MultiplyAdd(SampleField* volatile input, SampleField* weights, SampleField* output);
};
// Zero-fills output, adds weights times m_00 into output via the m_0c/m_18 index lists, then adds output times m_00 into input.
// @fnv 0x00e58a20
// src: HAVOK_LIB 0x00e58a20
void FUN_00e58a20_cls::hkaSparseLSQMatrix_float_MultiplyAdd(SampleField* volatile input,
                                      SampleField* weights,
                                      SampleField* output) {
    float initial = 0.0f;
    output->FillWithValue(&initial);
    int component = 0;
    if (input->NiD3DShaderProgram_GetShaderProgramName() > 0) {
        int elementCount = m_04;
        do {
            int index = 0;
            if (elementCount > 0) {
                do {
                    float* destination = output->GetElementPtr(m_0c[index], component);
                    *destination = weights->GetFloatAt(m_18[index], component) * m_00[index] + *destination;
                    ++index;
                    elementCount = m_04;
                } while (index < elementCount);
            }
            ++component;
        } while (component < input->NiD3DShaderProgram_GetShaderProgramName());
    }
    component = 0;
    if (input->NiD3DShaderProgram_GetShaderProgramName() > 0) {
        int elementCount = m_04;
        do {
            int index = 0;
            if (elementCount > 0) {
                do {
                    float* destination = input->GetElementPtr(m_18[index], component);
                    float* src = output->GetElementPtr(m_0c[index], component);
                    *destination = m_00[index] * *src + *destination;
                    ++index;
                    elementCount = m_04;
                } while (index < elementCount);
            }
            ++component;
        } while (component < input->NiD3DShaderProgram_GetShaderProgramName());
    }
}

// Source struct: only its float members at 0x80..0x94 take part; the rest are
// stand-in fields holding the earlier offsets.
struct Src
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7c;
    float m_80;
    float m_84;
    unsigned int m_88;
    unsigned int m_8c;
    float m_90;
    float m_94;
};

// Destination object: receives the two scaled components at 0x1c / 0x20.
struct Dst
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    float m_1c;
    float m_20;
};

// this (destination) arrives in ECX, the source pointer rides in EAX.
// @fnv 0x00e593d0
// src: HAVOK_LIB 0x00e593d0
static __declspec(noinline) void hkVehicleFrictionSolverCalcRelativeForces_00e593d0(Dst* dst, Src* src)
{
    dst->m_1c = src->m_94 * src->m_84;
    dst->m_20 = src->m_90 * src->m_80;
}

// in-TU caller so c2 keeps the body and negotiates the register convention.
static Dst* volatile g_dst;
static Src* volatile g_src;

void e593d0_apply_pair()
{
    hkVehicleFrictionSolverCalcRelativeForces_00e593d0(g_dst, g_src);
}

#include <math.h>
class FUN_00e40740_cls {
public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    float* m_pMinArray;
    int unk60;
    int unk64;
    float* m_pMaxArray;
    void UpdateMinMax(int index, float value);
};
// Stores min(existing, |value|) in m_pMinArray[index] and max(existing, |value|) in m_pMaxArray[index].
// @fnv 0x00e40740
void FUN_00e40740_cls::UpdateMinMax(int index, float value)
{
    float a = (float)fabs(value);
    float lo = m_pMinArray[index];
    m_pMinArray[index] = (lo < a) ? lo : a;
    float b = (float)fabs(value);
    float hi = m_pMaxArray[index];
    m_pMaxArray[index] = (hi > b) ? hi : b;
}

#include <xmmintrin.h>
extern int DAT_010e6834;
struct MotorObject {
    int* vtable;
    unsigned short flags;
    unsigned short references;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
    int unk1c;
    __m128 vector20;
    __m128 vector30;
    float value40;
    float value44;
    void FUN_00d2b260(void*, int);
    MotorObject* hkpReorientAction_hkpReorientAction();
};
// Zeroes value40, value44, vector20 and vector30, sets vtable to DAT_010e6834, calls FUN_00d2b260(0, 0) and returns this.
// @fnv 0x00e444c0
// src: EXE 0x00e444c0
MotorObject* MotorObject::hkpReorientAction_hkpReorientAction()
{
    FUN_00d2b260(0, 0);
    value40 = 0.0f;
    value44 = 0.0f;
    vtable = &DAT_010e6834;
    vector20 = _mm_setzero_ps();
    vector30 = _mm_setzero_ps();
    return this;
}

struct LoadedFlag { int finishing; };
extern "C" int DAT_010ec004;
struct LoadedObject {
    void* vtable;
    int unk04;
    unsigned char type;
    void FUN_00e46f20(LoadedFlag flag);
    LoadedObject* Initialize(LoadedFlag flag);
};
// Calls FUN_00e46f20, sets vtable to DAT_010ec004, sets type to 4 when flag.finishing is true, and returns this.
// @fnv 0x00e45120
LoadedObject* LoadedObject::Initialize(LoadedFlag flag)
{
    FUN_00e46f20(flag);
    vtable = &DAT_010ec004;
    if (flag.finishing) type = 4;
    return this;
}

void* operator new(size_t, void* p) { return p; }

template<class T> struct EntityArray : hkArrayBase<T> {
    __forceinline int indexOf(const T& element) const {
        for (int i = 0; i < this->m_iElementCount; ++i) {
            if (this->m_data[i] == element) return i;
        }
        return -1;
    }
    __forceinline void AddBack(const T& element) {
        HolderStub* holder = hkMemoryRouter_getInstance();
        if (this->m_iElementCount == (this->m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(holder->m_pAllocator, this, sizeof(T));
        }
        T* destination = this->m_data + this->m_iElementCount;
        for (int k = 0; k < 1; ++k) destination[k] = element;
        ++this->m_iElementCount;
    }
};

struct SmallBool { unsigned char value; SmallBool(bool v) : value(v) {} };

struct EntityShape {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    hkpEntityListener m_kListener;
    EntityArray<hkpEntity*> m_kActorEntries;
    SmallBool AddActor(hkpEntity* item);
};

// Returns false if the entity is null or already in m_kActorEntries; otherwise adds it, registers m_kListener with hkpEntity::addEntityListener if not yet listed, and returns true.
// @fnv 0x00e46a30
SmallBool EntityShape::AddActor(hkpEntity* apActor) {
    if (!apActor) {
        return false;
    }
    for (int i = 0; i < m_kActorEntries.m_iElementCount; ++i) {
        if (m_kActorEntries.m_data[i] == apActor) {
            return false;
        }
    }
    m_kActorEntries.AddBack(apActor);
    {
        hkpEntityListener* member = &m_kListener;
        if (apActor->getEntityListeners().indexOf(member) < 0) {
            apActor->addEntityListener(member);
        }
    }
    return true;
}

struct BitLinks {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    unsigned int m_ppLinks[64];

    void SetLink(int a, int b);
};

// Sets the bit for b in m_ppLinks[a] and the bit for a in m_ppLinks[b], recording a symmetric link between the two indices.
// @fnv 0x00e48910
void BitLinks::SetLink(int aiIndexA, int aiIndexB)
{
    m_ppLinks[aiIndexA] |= 1u << aiIndexB;
    m_ppLinks[aiIndexB] |= 1u << aiIndexA;
}

namespace se49080 {

extern "C" const char DAT_010e8e94[];
extern "C" const char DAT_010e8e74[];

void __fastcall FUN_00c90510(void* pvObject);

struct Shape;

struct ShapeBase {
    const char* m_pVtbl;
    int unk004;
    int unk008;
    int unk00c;
    const char* m_pVtbl2;

    void FUN_00d21410(int iType, int iFlags);
};

struct KeyedPointerEntry : ShapeBase {
    int unk14;
    Shape* m_pkShapeB;
    Shape* m_pkShapeA;
    float m_fBoundRadius;

    KeyedPointerEntry* InitializeFields_00e49080(Shape* pkShapeA, Shape* pkShapeB, float fRadius);
};

// Initializes the object by calling FUN_00d21410, setting m_fBoundRadius, vtable pointers, and shape pointers, then calls FUN_00c90510 on both shapes.
// @fnv 0x00e49080
// src: GUESS 0x00e49080 (confidence: low)
KeyedPointerEntry* KeyedPointerEntry::InitializeFields_00e49080(Shape* pkShapeA, Shape* pkShapeB, float afBoundRadius)
{
    FUN_00d21410(7, 3);
    m_fBoundRadius = afBoundRadius;
    m_pVtbl = DAT_010e8e94;
    m_pVtbl2 = DAT_010e8e74;
    m_pkShapeB = pkShapeB;
    m_pkShapeA = pkShapeA;
    FUN_00c90510(pkShapeA);
    FUN_00c90510(m_pkShapeB);
    return this;
}

}

namespace se493a0 {

struct Stats {
    int m_iTotal;
    int m_iArrayLength;
    float m_fAverage;
    int m_iMaxControlPoint;
};

struct Layout {
    int unk000;
    int unk004;
    int* m_piSizes;
    int unk00c;
    int unk010;
    int* m_piIndices;
    int m_iNumIndices;
    int unk01c;
    int unk020;
    int m_iBase;
};

struct Owner {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    Layout* m_pkLayout;

    void AccumulateControlPointStatistics(Stats* pkStats);
};

// Accumulates m_iBase and per-index sizes into pkStats, tracking the max control point size and computing the average.
// @fnv 0x00e493a0
// src: GUESS 0x00e493a0 (confidence: medium)
void Owner::AccumulateControlPointStatistics(Stats* pkStats)
{
    pkStats->m_iTotal += m_pkLayout->m_iBase;
    pkStats->m_iArrayLength += m_pkLayout->m_iBase;
    for (int i = 0; i < m_pkLayout->m_iNumIndices; i++)
    {
        int iSize = m_pkLayout->m_piSizes[m_pkLayout->m_piIndices[i]];
        pkStats->m_iTotal += iSize;
        pkStats->m_iMaxControlPoint = pkStats->m_iMaxControlPoint > iSize ? pkStats->m_iMaxControlPoint : iSize;
    }
    pkStats->m_iArrayLength += m_pkLayout->m_iNumIndices;
    pkStats->m_fAverage = (float)pkStats->m_iTotal / pkStats->m_iArrayLength;
}

}

struct SrcArray
{
    unsigned short* m_pBase;
    int m_uiLogicalSize;
};

class AllocatorIface
{
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* hkMemoryAllocator(int* pSize);
    virtual void Free(void* pBuffer, unsigned int size);
};

class SpawnedBase
{
public:
    virtual void unkBase();
    SpawnedBase(unsigned int flags, int one);
};

class FUN_00e49900 : public SpawnedBase
{
public:
    virtual void unkBase();
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
    unsigned short* m_pData;
    int m_iArrayLength;
    unsigned int m_uiCapacity;
    unsigned char m_bFlag;
    float m_fTimeA;
    float m_fTimeB;

    FUN_00e49900(unsigned int flags, SrcArray* src, float a, float b);
};

// @fnv 0x00e49900
FUN_00e49900::FUN_00e49900(unsigned int flags, SrcArray* src, float afTimeA, float afTimeB)
    : SpawnedBase(flags, 1)
{
    m_pData = 0;
    m_iArrayLength = 0;
    m_uiCapacity = 0x80000000;
    m_bFlag = 0;
    AllocatorIface* alloc = static_cast<AllocatorIface*>(hkMemoryRouter_getInstance()->m_pAllocator);
    if ((int)(m_uiCapacity & 0x3fffffff) < src->m_uiLogicalSize)
    {
        if ((m_uiCapacity & 0x80000000u) == 0)
        {
            alloc->Free(m_pData, (m_uiCapacity & 0x3fffffff) * 2);
        }
        int bytes = src->m_uiLogicalSize * 2;
        m_pData = (unsigned short*)alloc->hkMemoryAllocator(&bytes);
        m_uiCapacity = bytes / 2;
    }
    int n = src->m_uiLogicalSize;
    m_iArrayLength = n;
    unsigned short* dst = m_pData;
    const unsigned short* s = src->m_pBase;
    for (int i = 0; i < n; i++)
        dst[i] = s[i];
    m_fTimeB = afTimeB;
    m_fTimeA = afTimeA;
}

// @fnv 0x00e4b560
// src: GUESS 0x00e4b560 (confidence: high)
void __cdecl Object_DoNothing_00e4b560()
{
}

namespace fnv_00e4e420 {
struct IntegerHolder {
    int m_00;
    IntegerHolder() {}
    IntegerHolder(const IntegerHolder& other) { FUN_00cb0bd0(&other); }
    void FUN_00cb0bd0(const IntegerHolder*);
    void Object_UpdateFields_00cb0c00();
    void UpdateState_00cb0c30(const IntegerHolder*);
};
struct CopyEntry {
    float m_00;
    IntegerHolder m_04;
    CopyEntry(const CopyEntry& other) { m_00 = other.m_00; m_04.FUN_00cb0bd0(&other.m_04); }
    CopyEntry& operator=(const CopyEntry& other) { m_00 = other.m_00; m_04.UpdateState_00cb0c30(&other.m_04); return *this; }
    ~CopyEntry() { m_04.Object_UpdateFields_00cb0c00(); }
};
inline void* operator new(unsigned int, void* p) { return p; }
struct CopyAllocator { int m_00, m_04, m_08, m_0c; void* m_10; };
CopyAllocator* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
static __forceinline void destroyEntries(CopyEntry* p, int count) {
    for (int i = 0; i < count; ++i) p[i].~CopyEntry();
}
static __forceinline void assignEntries(CopyEntry* dst, const CopyEntry* src, int count) {
    for (int i = 0; i < count; ++i) dst[i] = src[i];
}
static __forceinline void constructEntries(CopyEntry* dst, const CopyEntry* src, int count) {
    for (int i = 0; i < count; ++i) new(dst + i) CopyEntry(src[i]);
}
struct CopyArray {
    CopyEntry* m_00;
    int m_04;
    int m_08;
    __forceinline CopyArray(const CopyArray& src) : m_00(0), m_04(0), m_08(0x80000000) {
        CopyAllocator* manager = hkMemoryRouter_getInstance();
        int oldSize = m_04;
        int newSize = src.m_04;
        void* allocator = manager->m_10;
        int common = newSize > oldSize ? oldSize : newSize;
        int capacity = m_08 & 0x3fffffff;
        if (capacity < newSize) {
            int grown = capacity * 2;
            if (newSize >= grown) grown = newSize;
            hkArrayUtil__reserve(allocator, this, grown, 8);
        }
        destroyEntries(m_00 + newSize, oldSize - newSize);
        assignEntries(m_00, src.m_00, common);
        constructEntries(m_00 + common, src.m_00 + common, newSize - common);
        m_04 = newSize;
    }
};
struct FUN_00e4e420 {
    IntegerHolder m_00;
    CopyArray m_04;
    FUN_00e4e420(const FUN_00e4e420&);
};
// @fnv 0x00e4e420
FUN_00e4e420::FUN_00e4e420(const FUN_00e4e420& src) : m_00(src.m_00), m_04(src.m_04) {}
}  // namespace fnv_00e4e420

struct Count { int n; };

extern "C" void __movsd(unsigned long* destination,
                        const unsigned long* source,
                        unsigned int count);

// Copies count floats from src to a scratch buffer, then deinterleaves them into dst's first and second halves.
// @fnv 0x00e50fa0
void __cdecl DeinterleaveFloats(const float* src, float* dst, Count aCount)
{
    int count = aCount.n;
    HolderStub* holder = hkMemoryRouter_getInstance();
    unsigned int* scratch = (unsigned int*)holder->unk00;

    holder->unk00 = (int)scratch + ((count * 4 + 0x7f) & ~0x7f);

    {
        const unsigned int* __restrict s32 = (const unsigned int*)src;
        unsigned int* __restrict d32 = scratch;
        for (int i = 0; i < count; i++)
            *(d32++) = *(s32++);
    }

    int half = count >> 1;
    float* values = (float*)scratch;

    for (int i = 0; i < half; ++i) {
        dst[i] = values[2 * i];
        dst[half + i] = values[2 * i + 1];
    }

    hkMemoryRouter_getInstance()->unk00 = (int)scratch;
}

namespace fnv_00e51070 {
struct Count { int n; };

// Copies count floats into scratch memory, then interleaves the first and second halves of that copy into dst.
// @fnv 0x00e51070
// src: HAVOK_LIB 0x00e51070
void __cdecl hkMergeOddEven(const float* src, float* dst, Count value)
{
    int count = value.n;
    HolderStub* holder = hkMemoryRouter_getInstance();
    unsigned int* scratch = (unsigned int*)holder->unk00;
    holder->unk00 = (int)scratch + ((count * 4 + 0x7f) & ~0x7f);

    {
        const unsigned int* __restrict s32 = (const unsigned int*)src;
        unsigned int* __restrict d32 = scratch;
        for (int i = 0; i < count; i++)
            *(d32++) = *(s32++);
    }

    int half = count >> 1;
    float* values = (float*)scratch;
    for (int i = 0; i < half; ++i)
    {
        dst[2 * i] = values[i];
        dst[2 * i + 1] = values[half + i];
    }

    hkMemoryRouter_getInstance()->unk00 = (int)scratch;
}
}  // namespace fnv_00e51070

struct ThresholdAllocator {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void ReleaseBlock(void*, int);
};
struct ThresholdCompare { bool descending; };
void __cdecl hkAlgorithm_quickSortRecursive_float_class_hkAlgorithm_less_float(float*, int, int, ThresholdCompare);
struct ThresholdArray {
    float* data;
    int size;
    int capacity;
    float* original;
    void SetSizeAndGrow(int count) {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        E4AAA0Allocator* heap = (E4AAA0Allocator*)mgr->m_pAllocator;
        int current = capacity & 0x3fffffff;
        if (current < count) {
            int grown = 2 * current;
            hkArrayUtil__reserve(heap, this, count < grown ? grown : count, 4);
        }
        size = count;
    }
    void release() {
        float* saved = original;
        if (saved == data) size = 0;
        hkMemoryRouter_getInstance()->unk00 = (int)saved;
        ClearAndRelease();
    }
    void ClearAndRelease() {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        ThresholdAllocator* heap = (ThresholdAllocator*)mgr->m_pAllocator;
        int cap = capacity;
        size = 0;
        if ((cap & 0x80000000) == 0) heap->ReleaseBlock(data, (cap & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};
inline float ThresholdFloat(unsigned int value) { return (float)value; }
inline float ThresholdAbs(float value) { return (float)fabs(value); }
// Zeroes small-magnitude entries of values: a sorted-cutoff pass if relative.descending is set, otherwise a running-threshold pass.
// @fnv 0x00e51390
void __cdecl ThresholdValues(float* values, unsigned int count, float threshold, ThresholdCompare relative)
{
    float length;
    if (relative.descending) {
        length = ThresholdFloat(count);
        if (threshold < 1.0f / length) return;
        ThresholdArray magnitudes;
        magnitudes.data = 0;
        magnitudes.size = 0;
        magnitudes.capacity = 0x80000000;
        HolderStub* holder = hkMemoryRouter_getInstance();
        float* storage = (float*)holder->unk00;
        holder->unk00 += (count * 4 + 127) & ~127;
        magnitudes.data = storage;
        magnitudes.capacity = count | 0x80000000;
        magnitudes.original = storage;
        magnitudes.SetSizeAndGrow(count);
        for (unsigned int i = 0; i < count; ++i) magnitudes.data[i] = ThresholdAbs(values[i]);
        int index = (int)(length * threshold - 1.1920928955078125e-7) - 1;
        if (index >= (int)count) index = count - 1;
        index = index < 0 ? 0 : index;
        ThresholdCompare comparison; comparison.descending = false;
        if ((int)count > 1) hkAlgorithm_quickSortRecursive_float_class_hkAlgorithm_less_float(magnitudes.data, 0, count - 1, comparison);
        float cutoff = magnitudes.data[index];
        for (unsigned int i = 0; i < count; ++i) {
            if (ThresholdAbs(values[i]) <= cutoff) values[i] = 0.0f;
        }
        magnitudes.release();
    } else {
        unsigned int remaining = count;
        unsigned int midpoint = remaining >> 1;
        length = threshold;
        float maximum = 0.0f;
        while (remaining) {
            float magnitude = ThresholdAbs(values[--remaining]);
            if (magnitude < length) {
                values[remaining] = 0.0f;
                if (maximum < magnitude) maximum = magnitude;
            }
            if (remaining == midpoint) {
                length -= maximum;
                midpoint >>= 1;
                maximum = 0.0f;
            }
        }
    }
}

struct Q { __m128 m_vComponents; void normalize_005611c0(); };
struct QRef { Q* p; Q* operator->() const { return p; } };
// Unpacks four 4-bit values from two bytes, maps each to (v-7)/7, stores them in out->m_vComponents, then calls FUN_005611c0 on it.
// @fnv 0x00e52880
// src: GUESS 0x00e52880 (confidence: medium)
void Object_UnpackFourSignedNibbles(const unsigned char* src, QRef out)
{
    short v[4];
    v[0] = src[0] & 0xf; v[1] = src[0] >> 4; v[2] = src[1] & 0xf; v[3] = src[1] >> 4;
    float* f = (float*)&out->m_vComponents;
    *(__m128*)f = _mm_setzero_ps();
    f[0] = (v[0] - 7) * (1.0f / 7.0f);
    f[1] = (v[1] - 7) * (1.0f / 7.0f);
    f[2] = (v[2] - 7) * (1.0f / 7.0f);
    f[3] = (v[3] - 7) * (1.0f / 7.0f);
    ((Q*)f)->normalize_005611c0();
}

class Quat4
{
public:
	float m_fVectorY;
	float m_fVectorZ;
	float m_fScalarPart;
	float m_fVectorX;

	Quat4(float fX, float fY, float fZ, float fW);
	Quat4 GetAbsolute() const;
};

__declspec(noinline) Quat4::Quat4(float fX, float fY, float fZ, float fW)
{
	m_fVectorY = fX;
	m_fVectorZ = fY;
	m_fScalarPart = fZ;
	m_fVectorX = fW;
}

// Returns a new Quat4 whose components are the absolute values of this quaternion's components.
// @fnv 0x00e533e0
Quat4 Quat4::GetAbsolute() const
{
	return Quat4((float)fabs(m_fVectorY), (float)fabs(m_fVectorZ), (float)fabs(m_fScalarPart), (float)fabs(m_fVectorX));
}

// Evaluates the degree-iDegree B-spline basis function for index i at fT over the knot array, using an in-place table iteration.
// @fnv 0x00e54110
float __cdecl EvaluateBasisFunction(int iDegree, int iNumKnots, const float* const* ppKnots, int iIndex, float fT)
{
    if ((iIndex == 0 && fT == (*ppKnots)[0]) ||
        (iIndex == iNumKnots - iDegree - 1 && fT == (*ppKnots)[iNumKnots]))
    {
        return 1.0f;
    }

    const float* pKnotI = &(*ppKnots)[iIndex];

    if (fT < *pKnotI || fT >= (*ppKnots)[iIndex + iDegree + 1])
        return 0.0f;

    float table[4];
    for (int j = 0; j <= iDegree; ++j)
    {
        if ((*ppKnots)[iIndex + j] <= fT && fT < (*ppKnots)[iIndex + j + 1])
            table[j] = 1.0f;
        else
            table[j] = 0.0f;
    }

    for (int d = 1; d <= iDegree; ++d)
    {
        float term;
        if (table[0] == 0.0f)
        {
            term = 0.0f;
        }
        else
        {
            term = ((fT - *pKnotI) * table[0]) / ((*ppKnots)[iIndex + d] - *pKnotI);
        }

        for (int j = 0; j < iDegree - d + 1; ++j)
        {
            float knot1 = (*ppKnots)[iIndex + j + 1];
            float knot2 = (*ppKnots)[iIndex + j + d + 1];

            if (table[j + 1] == 0.0f)
            {
                table[j] = term;
                term = 0.0f;
            }
            else
            {
                float invDenom = table[j + 1] / (knot2 - knot1);
                table[j] = term + (knot2 - fT) * invDenom;
                term = (fT - knot1) * invDenom;
            }
        }
    }

    return table[0];
}

// Returns the total count of consecutive equal elements around index lo in arr, counting the run extending left and right.
// @fnv 0x00e547d0
int __cdecl GetRunLength(int lo, int hi, float** arr)
{
    int up = 0;
    if (lo <= hi) {
        float* pivot = (*arr) + lo;
        int i = lo;
        float* p = pivot;
        do {
            if (*pivot != *p) {
                break;
            }
            i++;
            up++;
            p++;
        } while (i <= hi);
    }
    int down = 1;
    while (lo-down >= 0) {
        if ((*arr)[lo] != (*arr)[lo-down]) break;
        ++down;
    }
    return down + up - 1;
}

template<class T> struct CurveArg { T value; };

float __cdecl hkaNURBS_ClosestPoint(int a3, int a4, int a5, int a6, float* p, int a9, int a10, float a11, float a12);
void __cdecl hkaNURBS_CurvePoint(V4* out, int a3, int a4, int a5, int a6, float v);
struct CurvePointOps {
    float* UpdateState_00e532b0(V4* p1, V4* p2);
};
struct CurveLengthOps {
    float GetHelperValueAsFloat();
};
// For each index up to n, gets a float v (via FUN_00e54cb0 if a13 else read from a8), stores it in a8, and writes a derived float into a7.
// @fnv 0x00e54fa0
// src: HAVOK_LIB 0x00e54fa0
void __cdecl hkaNURBS_UpdateFit(int n, CurveArg<float**> apPoints, CurveArg<int> a3, CurveArg<int> a4,
                          CurveArg<int> a5, CurveArg<int> a6, CurveArg<float**> a7, CurveArg<float**> apValues,
                          CurveArg<int> a9, CurveArg<int> a10, float a11, float a12, bool a13)
{
    int i = 0;
    if (i <= n) {
        int cached5 = a5.value;
        int cached6 = a6.value;
        do {
        float v;
        if (a13) {
            float* point = (*apPoints.value) + i * 4;
            v = hkaNURBS_ClosestPoint(a3.value, a4.value, cached5, cached6, point, a9.value, a10.value, a11, a12);
        }
        else
            v = (*apValues.value)[i];
        V4 A;
        V4 B;
        hkaNURBS_CurvePoint(&A, a3.value, a4.value, cached5, cached6, v);
        (*apValues.value)[i] = v;
        float* r = reinterpret_cast<CurvePointOps*>((*apPoints.value) + i * 4)->UpdateState_00e532b0(&B, &A);
        (*a7.value)[i] = reinterpret_cast<CurveLengthOps*>(r)->GetHelperValueAsFloat();
        } while (++i <= n);
    }
}

extern const float runtimeFloatSettingDefault726;
__declspec(noalias) float __cdecl LookupAndConsume(const Float4* left, const Float4* right);
extern "C" float __cdecl hkaNURBS_ClosestPoint(int a, int b, int c, int d, Float4* p, int e, int f, float g, float h);

// For each sample up to last, computes a value via FUN_00e54cb0 and FUN_00e54630; writes 0 to result if any compare exceeds threshold, else 1, and returns result.
// @fnv 0x00e55200
unsigned char* __cdecl CheckAllSamplesBelowThreshold(unsigned char* pbAllBelowThreshold, int a, int b, int c, int d, int aiLastIndex, Float4** samples, float threshold)
{
    for (int i = 0; i <= aiLastIndex; i++) {
        Float4 sample = (*samples)[i];
        float r = hkaNURBS_ClosestPoint(a, b, d, c, &(*samples)[i], 100, 10, runtimeFloatSettingDefault726, runtimeFloatSettingDefault726);
        Float4 value;
        hkaNURBS_CurvePoint(&value, a, b, d, c, r);
        if (LookupAndConsume(&sample, &value) > threshold) {
            *pbAllBelowThreshold = 0;
            return pbAllBelowThreshold;
        }
    }
    *pbAllBelowThreshold = 1;
    return pbAllBelowThreshold;
}

// CollectConnectedNodesAndEdges  (__cdecl, 4 args) -- walk a link array, collect incident entries
// The array append keeps the slot address materialised in a register (the original's
// `lea eax,[ecx+eax*4] ; mov [eax],edx`), which a single indexed store does not:
// the slot is reached through a local pointer that is written twice.
struct ChainElem {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_link14;
    void* m_link18;
};

template <class T>
struct ChainArray {
    T* m_data;
    int m_iElementCount;
    int m_capFlags;

    void Add(T const& value) {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_capFlags & 0x3fffffff))
            ResizeAudioStream(mgr->m_pAllocator, this, (int)sizeof(T));
        T* pSlot = &m_data[m_iElementCount];
        pSlot[0] = value;
        pSlot[0] = value;
        ++m_iElementCount;
    }
};

void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, int auiNewSize);

// @fnv 0x00e5b830
void __cdecl CollectConnectedNodesAndEdges(ChainArray<void*>* src, void* node, ChainArray<void*>* outNodes, ChainArray<void*>* outEdges) {
    for (int i = 0; i < src->m_iElementCount; ++i) {
        ChainElem* elem = (ChainElem*)src->m_data[i];
        void* a = elem->m_link14;
        if (a == node || elem->m_link18 == node) {
            void* other = (void*)((unsigned int)elem->m_link18 ^ (unsigned int)a ^ (unsigned int)node);
            outNodes->Add(other);
            outEdges->Add((void*)elem);
        }
    }
}

namespace ns_e5c5 { int __cdecl CompareStringsCaseInsensitive(const char* a, const char* b) throw(); }
struct Resource_e5c5 {
    const char* FUN_00d46d40() throw();
    void FUN_00c905b0() throw();
};

template <class T> struct hkRefPtr_e5c5 {
    T* m_pRetainedObject;
    ~hkRefPtr_e5c5() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
    T* hkRefVariant_getClass() throw();
    T* val() const { return m_pRetainedObject; }
};

struct Registry_e5c5 {
    hkRefPtr_e5c5<Resource_e5c5> FindOrCreateEntryReference(const char* name) throw();
    Resource_e5c5* FindResourceWithExpectedName(const char* name, Resource_e5c5* expected);
};

// Looks up a resource by name and returns it if expected is null or its name matches case-insensitively, otherwise returns null.
// @fnv 0x00e5c540
// src: GUESS 0x00e5c540 (confidence: medium)
Resource_e5c5* Registry_e5c5::FindResourceWithExpectedName(const char* name, Resource_e5c5* expected)
{
    hkRefPtr_e5c5<Resource_e5c5> found = FindOrCreateEntryReference(name);
    if (found.m_pRetainedObject) {
        if (!expected || ns_e5c5::CompareStringsCaseInsensitive(expected->FUN_00d46d40(), found.hkRefVariant_getClass()->FUN_00d46d40()) == 0)
            return found.m_pRetainedObject;
    }
    return 0;
}

extern float DAT_010ea628;
extern float DAT_010ec1b0;

struct __declspec(align(16)) Aabb {
    float minX, minY, minZ, minW;
    float maxX, maxY, maxZ, maxW;
};

// 0x00e5d040; the MOPP code travels as an integer (see hkpRemoveTerminalsMoppModifier2.h).
void __cdecl hkMoppModifyVirtualMachine_queryAabb(hkUlong moppCode, const Aabb* aabb, hkpMoppModifier* modifier);


__forceinline hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier() throw()
    : m_pTerminalIdsToRemove(0)
{
}

// Queries the whole MOPP (+-1e10 box) through the modifier while m_enabledKeys points at enabledKeys.
// @fnv 0x00e487a0
hkpRemoveTerminalsMoppModifier2::hkpRemoveTerminalsMoppModifier2(hkUlong moppCode, const hkBitField& enabledKeys) throw()
    : m_enabledKeys(&enabledKeys)
{
    Aabb aabb;
    *(__m128*)&aabb.maxX = _mm_set1_ps(1e10f);
    *(__m128*)&aabb.minX = _mm_set1_ps(-1e10f);
    hkMoppModifyVirtualMachine_queryAabb(moppCode, &aabb, this);
    m_enabledKeys = 0;
}

struct FnvCpu_FUN_00e49bb0_CpuObject { char* EvaluateValue_00e49bb0(); };
// @fnv 0x00e49bb0
// src: GUESS 0x00e49bb0 (confidence: low)
char* FnvCpu_FUN_00e49bb0_CpuObject::EvaluateValue_00e49bb0()
{
    return reinterpret_cast<char*>(this) + 48;
}

extern double __cdecl FUN_00ec9e10(double x);

namespace Components {
struct FUN_00e53160 {
    float x, y, z, w;
    __declspec(noinline) FUN_00e53160(float a, float b, float c, float d);
};
__declspec(noinline) FUN_00e53160::FUN_00e53160(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
}
struct ComponentVector {
    float x, y, z, w;
    Components::FUN_00e53160 hkaNURBS_Point_ceil() const;
};
inline float ConvertComponent(float x) { return (float)FUN_00ec9e10(x); }
inline float ConvertEarly(float x, volatile float& temp) {
    temp = x;
    temp = (float)FUN_00ec9e10(temp);
    return temp;
}
// Converts the x, y, z, w fields of a ComponentVector to Components::FUN_00e53160 via ConvertComponent and ConvertEarly.
// @fnv 0x00e534c0
// src: HAVOK_LIB 0x00e534c0
Components::FUN_00e53160 ComponentVector::hkaNURBS_Point_ceil() const {
    volatile float temp;
    return Components::FUN_00e53160(ConvertComponent(x), ConvertEarly(y, temp), ConvertEarly(z, temp), ConvertEarly(w, temp));
}

struct KnotVector {
    float x,y,z,w;
    KnotVector(float a=0,float b=0,float c=0,float d=0);
    KnotVector& FUN_00e53180(const KnotVector&);
    KnotVector& operator=(const KnotVector& v) { return FUN_00e53180(v); }
    KnotVector& ComputeValue_00e531a0(const KnotVector&);
    KnotVector& SubtractFourComponents(const KnotVector&);
    KnotVector& FUN_00e53200(float);
    KnotVector& DivideByScalar(float);
    KnotVector ScaleCopy(float) const;
    KnotVector UpdateState_00e532b0(const KnotVector&) const;
    KnotVector ProcessAndReturnValue_00e53260(const KnotVector&) const;
    KnotVector EvalCopy(float) const;
};
__declspec(noinline) KnotVector::KnotVector(float a,float b,float c,float d) : x(a),y(b),z(c),w(d) {}
__declspec(noinline) KnotVector& KnotVector::FUN_00e53180(const KnotVector& v) { x=v.x;y=v.y;z=v.z;w=v.w;return *this; }
// src: GUESS 0x00e531a0 (confidence: low)
__declspec(noinline) KnotVector& KnotVector::ComputeValue_00e531a0(const KnotVector& v) {x+=v.x;y+=v.y;z+=v.z;w+=v.w;return *this;}
// src: GUESS 0x00e531d0 (confidence: high)
__declspec(noinline) KnotVector& KnotVector::SubtractFourComponents(const KnotVector& v) {x-=v.x;y-=v.y;z-=v.z;w-=v.w;return *this;}
__declspec(noinline) KnotVector& KnotVector::FUN_00e53200(float f) {x*=f;y*=f;z*=f;w*=f;return *this;}
__declspec(noinline) KnotVector& KnotVector::DivideByScalar(float f) {x/=f;y/=f;z/=f;w/=f;return *this;}
// src: GUESS 0x00e53260 (confidence: low)
__declspec(noinline) KnotVector KnotVector::ProcessAndReturnValue_00e53260(const KnotVector& v) const {KnotVector a=*this;return a.ComputeValue_00e531a0(v);}
// src: GUESS 0x00e532b0 (confidence: low)
__declspec(noinline) KnotVector KnotVector::UpdateState_00e532b0(const KnotVector& v) const {KnotVector a=*this;return a.SubtractFourComponents(v);}
__declspec(noinline) KnotVector KnotVector::ScaleCopy(float f) const {KnotVector a=*this;return a.FUN_00e53200(f);}
__declspec(noinline) KnotVector KnotVector::EvalCopy(float f) const {KnotVector a=*this;return a.DivideByScalar(f);}
// src: GUESS 0x00e533a0 (confidence: medium)
__declspec(noinline) KnotVector Object_ScaleCopy_Thunk(float f,const KnotVector& v) {return v.ScaleCopy(f);}

float __cdecl hkaNURBS_Distance3D(const KnotVector&,const KnotVector&);

struct CurveArray { float* data; int size; int capacity; };
struct PointArray { KnotVector* data; int size; int capacity; };
// Blends Pw points with knot-ratio alphas from U at parameter u into a temp array, then returns FUN_00e54ba0 applied to the blended values.
// @fnv 0x00e552f0
// src: HAVOK_LIB 0x00e552f0
float __cdecl hkaNURBS_GetRemovalBoundCurve(int n,int p,CurveArray& apKnots,PointArray& apPoints,float afParam,int r,int s)
{
    KnotVector temp[7];
    int ord=p+1;
    int last=r-s;
    int first=r-p;
    int off=first-1;
    temp[0]=apPoints.data[off];
    temp[last+1-off]=apPoints.data[last+1];
    int i, j, iLeftIdx, iRightIdx;
    i=first;
    j=last;
    iLeftIdx=1;
    iRightIdx=last-off;
    while(j-i>0) {
        float fAlphaLeft=(afParam-apKnots.data[i])/(apKnots.data[i+ord]-apKnots.data[i]);
        float fAlphaRight=(afParam-apKnots.data[j])/(apKnots.data[j+ord]-apKnots.data[j]);
        temp[iLeftIdx]=apPoints.data[i].UpdateState_00e532b0(Object_ScaleCopy_Thunk(1.0f-fAlphaLeft,temp[iLeftIdx-1])).EvalCopy(fAlphaLeft);
        temp[iRightIdx]=apPoints.data[j].UpdateState_00e532b0(Object_ScaleCopy_Thunk(fAlphaRight,temp[iRightIdx+1])).EvalCopy(1.0f-fAlphaRight);
        ++i; ++iLeftIdx; --j; --iRightIdx;
    }
    if(j-i<0) return hkaNURBS_Distance3D(temp[iLeftIdx-1],temp[iRightIdx+1]);
    float fAlphaLeft=(afParam-apKnots.data[i])/(apKnots.data[i+ord]-apKnots.data[i]);
    return hkaNURBS_Distance3D(apPoints.data[i],Object_ScaleCopy_Thunk(fAlphaLeft,temp[iLeftIdx+1]).ProcessAndReturnValue_00e53260(Object_ScaleCopy_Thunk(1.0f-fAlphaLeft,temp[iLeftIdx-1])));
}

void* _fnv_zlib_memset(void*,int,int);
struct MarkHeap {
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual void* Allocate(int&);
 virtual void Free(void*,int);
 template<class T> __forceinline T* reserve(int& count) {
  int bytes=count*sizeof(T);
  T* p=(T*)Allocate(bytes);
  count=bytes/sizeof(T);
  return p;
 }
 template<class T> __forceinline void freeBuffer(T* p,int count) {Free(p,count*sizeof(T));}
};
struct MarkPolicy {
 __forceinline MarkHeap& get(void* owner) {HolderStub* h=hkMemoryRouter_getInstance();return *(MarkHeap*)h->m_pAllocator;}
};
template<class T> struct MarkStorage {
 T* data; int size; int capacity;
 __forceinline MarkStorage():data(0),size(0),capacity(0x80000000){}
 __forceinline void own(T* p,int n,int c) {data=p;size=n;capacity=c;}
 __forceinline T& operator[](int i) {return data[i];}
};
template<class T> struct MarkArray:MarkStorage<T> {
 __forceinline MarkArray(int count,const T& initial) {
  MarkHeap& heap=MarkPolicy().get(this);
  T* p=count ? heap.reserve<T>(count) : 0;
  int flags=count ? count : (int)0x80000000;
  own(p,count,flags);
  if(size>0) _fnv_zlib_memset(data,initial,size);
 }
 __forceinline void release() {
  MarkHeap* heap=(MarkHeap*)hkMemoryRouter_getInstance()->m_pAllocator;
  int cap=capacity;
  size=0;
  if((cap&0x80000000)==0) heap->Free(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;
 }
};
struct MarkBounds { float* data; };
int FindFloatInterval(int,int,float,MarkBounds*);
bool* IsSampleBoundary(bool*,int,MarkBounds*,int);
void* _fnv_zlib_memset(void*,int,int);
// Marks the bounds intervals containing each point (shrunk by epsilon); writes 0 to output if any IsSampleBoundary sample is unmarked, else 1.
// @fnv 0x00e57490
// src: HAVOK_LIB 0x00e57490
bool* hkaNURBS_IsWellPosed(bool* output,int n,int start,MarkBounds* bounds,int m,MarkBounds* points,float epsilon) {
 int total = start+n+1;
 MarkArray<char> marked(n+1,0);
 for(int i=0;i<=m;++i) {
  float& point = points->data[i];
  int index = FindFloatInterval(n,start,point,bounds);
  float value = bounds->data[index]+epsilon;
  int next = index==total ? total : index+1;
  if(point >= value) {
   float remaining = bounds->data[next]-epsilon;
   if(point <= remaining)
    marked[index-start] = 1;
  }
 }
 for(int j=0;j<=n;++j) {
  bool result;
  if(*IsSampleBoundary(&result,start+j,bounds,total) && !marked[j]) { *output=0; marked.release();return output; }
 }
 *output = 1;
res:
 marked.release();
 return output;
}

namespace fnv_00e57620 {
struct KnotVector {
 float x,y,z,w;
 KnotVector(float a=0,float b=0,float c=0,float d=0);
 __declspec(noinline) KnotVector& FUN_00e53180(const KnotVector&);
 __declspec(noinline) KnotVector& ComputeValue_00e531a0(const KnotVector&);
 __declspec(noinline) KnotVector UpdateState_00e532b0(const KnotVector&) const;
 __declspec(noinline) KnotVector& SubtractFourComponents(const KnotVector&);
 __declspec(noinline) KnotVector& FUN_00e53200(float);
 __declspec(noinline) KnotVector ScaleCopy(float) const;
 __declspec(noinline) float& GetElementAddress_00e53590(int);
 __declspec(noinline) const float& GetElementAddress_00e53590(int) const;
 __declspec(noinline) float GetIndexedValue_00e53580(int) const;
};
__declspec(noinline) KnotVector::KnotVector(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
__declspec(noinline) KnotVector& KnotVector::FUN_00e53180(const KnotVector& b) {x=b.x;y=b.y;z=b.z;w=b.w;return *this;}
// src: GUESS 0x00e531a0 (confidence: low)
__declspec(noinline) KnotVector& KnotVector::ComputeValue_00e531a0(const KnotVector& b) {x=b.x+x;y=b.y+y;z=b.z+z;w=b.w+w;return *this;}
// src: GUESS 0x00e53590 (confidence: low)
__declspec(noinline) float& KnotVector::GetElementAddress_00e53590(int i) {return (&x)[i];}
__declspec(noinline) KnotVector __cdecl Object_ScaleCopy_Thunk(float s,const KnotVector& b);
// src: GUESS 0x00e531d0 (confidence: high)
__declspec(noinline) KnotVector& KnotVector::SubtractFourComponents(const KnotVector& b) {x-=b.x;y-=b.y;z-=b.z;w-=b.w;return *this;}
__declspec(noinline) KnotVector& KnotVector::FUN_00e53200(float f) {x*=f;y*=f;z*=f;w*=f;return *this;}
__declspec(noinline) KnotVector KnotVector::ScaleCopy(float f) const {KnotVector t=*this;return t.FUN_00e53200(f);}
// src: GUESS 0x00e532b0 (confidence: low)
__declspec(noinline) KnotVector KnotVector::UpdateState_00e532b0(const KnotVector& b) const {KnotVector t=*this;return t.SubtractFourComponents(b);}
// src: GUESS 0x00e533a0 (confidence: medium)
__declspec(noinline) KnotVector __cdecl Object_ScaleCopy_Thunk(float s,const KnotVector& b) {return b.ScaleCopy(s);}
// src: GUESS 0x00e53580 (confidence: low)
__declspec(noinline) float KnotVector::GetIndexedValue_00e53580(int i) const {return (&x)[i];}
struct ElevationAllocator {
 virtual void ReportDiagnostic(); virtual void unused1(); virtual void unused2();
 virtual void* allocate(int* bytes); virtual void release(void* data,int bytes);
};
void __cdecl hkArrayUtil__reserve(void* alloc, void* array,int count,int elementSize);
template<class T> struct ElevationArray {
 T* data; int count; int capacity;
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline void allocate(int requested) {
  ElevationAllocator* allocator=(ElevationAllocator*)hkMemoryRouter_getInstance()->m_pAllocator;
  T* ptr;
  if(requested) {int bytes=requested*sizeof(T);ptr=(T*)allocator->allocate(&bytes);requested=bytes/(int)sizeof(T);} else ptr=0;
  int flags=requested?requested:0x80000000;
  data=ptr;count=requested;capacity=flags;
 }
 __forceinline void reserve(int requested) {
  HolderStub* h=hkMemoryRouter_getInstance();
  void* allocator=h->m_pAllocator;
  int cap=capacity&0x3fffffff;
  if(cap<requested) {int doubled=cap*2;hkArrayUtil__reserve(allocator,this,requested<doubled?doubled:requested,sizeof(T));}
 }
 __forceinline void resize(int requested) {
  reserve(requested);
  int added=requested-count;
  T* start=data+count;
  for(int k=0;k<added;++k) new(start+k) T;
  count=requested;
 }
 __forceinline void free() {
  HolderStub* h=hkMemoryRouter_getInstance();
  ElevationAllocator* allocator=(ElevationAllocator*)h->m_pAllocator;
  int cap=capacity;
  count=0;
  if((cap & 0x80000000)==0) allocator->release(data,(cap&0x3fffffff)*sizeof(T));
  data=0;capacity=0x80000000;
 }
 void SwapThreeInts(ElevationArray<T>* other);
};
struct FitMatrix {
 ElevationArray<float> values; int rows,cols;
 void InitFloatArray(int a,int b,float f);
 void InitArray(int a,int b);
 float& GetElementPtr(int a,int b);
 __declspec(noinline) int NiD3DShaderProgram_GetShaderProgramName();
 __declspec(noinline) int NiD3DShaderProgram_GetName();
 void UpdateState_00c7b0f0();
 __forceinline void set(int a,int b,float value) {GetElementPtr(a,b)=value;}
};
struct RhsWork {float component;FitMatrix matrix;};
struct SparseGrid {
 ElevationArray<float> values;
 ElevationArray<int> rows,cols;
 int numRows,numCols;
 void ResetSpawnArrays(int,int);
 void AppendTriple(int,int,float);
 void FreeThreeDynamicArrays();
};
float EvaluateBasisFunction(int degree,int numKnots,ElevationArray<float>* knots,int i,float t);
__declspec(noinline) float EvaluateBasisFunction(int p,int last,ElevationArray<float>* knots,int index,float u) {
 const float* U=knots->data;
 if((index==0 && u==U[0]) || (index==last-p-1 && u==U[last])) return 1.0f;
 const float* b=U+index;
 if(u<b[0] || u>=U[index+p+1]) return 0.0f;
 float values[4];
 for(int j=0;j<=p;++j) values[j]=(u>=U[index+j] && u<U[index+j+1])?1.0f:0.0f;
 for(int k=1;k<=p;++k) {
  float saved=values[0]==0.0f ? 0.0f : ((u-*b)*values[0])/(U[index+k]-*b);
  for(int j=0;j<p-k+1;++j) {
   float a=U[index+j+1], z=U[index+j+k+1];
   if(values[j+1]==0.0f) {values[j]=saved;saved=0.0f;}
   else {float factor=values[j+1]/(z-a);values[j]=saved+(z-u)*factor;saved=(u-a)*factor;}
  }
 }
 return values[0];
}
char* hkaNURBS_IsWellPosed(char*,int,int,ElevationArray<float>*,int,ElevationArray<float>*,float);
char* SolveMatrixColumns(char*,SparseGrid*,FitMatrix*,FitMatrix*,int,float);
char* CheckPointsWithinThreshold(char*,int,int,ElevationArray<KnotVector>*,ElevationArray<float>*,int,ElevationArray<KnotVector>*,ElevationArray<float>*,float);
// Builds a basis matrix from knots and params, solves for control points, stores them in output if the threshold check passes, and writes 1 or 0 to *result.
// @fnv 0x00e57620
char* FitSpline(char* result,int n,int degree,ElevationArray<KnotVector>* output,ElevationArray<float>* knots,int m,ElevationArray<KnotVector>* points,ElevationArray<float>* params,float tolerance,float tolerance2) {
 if(n>m) {*result=0;return result;}
 SparseGrid grid;
 grid.ResetSpawnArrays(m-1,n-1);
 for(int i=1;i<m;++i) {
  for(int j=1;j<n;++j)
   grid.AppendTriple(i-1,j-1,EvaluateBasisFunction(degree,n+degree+1,knots,j,params->data[i]));
 }
 RhsWork rhs;
 rhs.matrix.InitFloatArray(n-1,4,0.0f);
 ElevationArray<KnotVector> temporary;
 temporary.allocate(m+1);
 for(int i=0;i<temporary.count;++i) new(temporary.data+i) KnotVector;
 int mOff=m*(int)sizeof(KnotVector);
 temporary[0].FUN_00e53180(((KnotVector*)((char*)temporary.data+mOff))->FUN_00e53180(KnotVector()));
 for(int i=1;i<m;++i) {
  temporary[i].FUN_00e53180(points->data[i].UpdateState_00e532b0(Object_ScaleCopy_Thunk(EvaluateBasisFunction(degree,n+degree+1,knots,0,params->data[i]),points->data[0])).UpdateState_00e532b0(Object_ScaleCopy_Thunk(EvaluateBasisFunction(degree,n+degree+1,knots,n,params->data[i]),*(KnotVector*)((char*)points->data+mOff))));
 }
 for(int j=1;j<n;++j) {
  KnotVector sum;
  for(int i=1;i<m;++i) sum.ComputeValue_00e531a0(Object_ScaleCopy_Thunk(EvaluateBasisFunction(degree,n+degree+1,knots,j,params->data[i]),temporary[i]));
  for(int k=0;k<4;++k) {const float* value=&((const KnotVector&)sum).GetElementAddress_00e53590(k);float* dest=&rhs.matrix.GetElementPtr(j-1,k);*dest=*value;}
 }
 char ok;
 int lastParam=params->count-1;
 if(!*hkaNURBS_IsWellPosed(&ok,n,degree,knots,lastParam,params,tolerance)) {
  *result=0;temporary.free();rhs.matrix.UpdateState_00c7b0f0();grid.FreeThreeDynamicArrays();return result;
 }
 FitMatrix interior;
 interior.InitArray(rhs.matrix.NiD3DShaderProgram_GetName(),rhs.matrix.NiD3DShaderProgram_GetShaderProgramName());
 int rowIndex=0;
 if(interior.NiD3DShaderProgram_GetName()>0) {
  int width=interior.NiD3DShaderProgram_GetShaderProgramName();
  do {
   int j=0;
   if(width>0) {
    const KnotVector* row=&points->data[rowIndex+1];
    do {
     rhs.component=row->GetIndexedValue_00e53580(j);interior.GetElementPtr(rowIndex,j)=rhs.component;
     ++j;
     width=interior.NiD3DShaderProgram_GetShaderProgramName();
    } while(j<width);
   }
   ++rowIndex;
  } while(rowIndex<interior.NiD3DShaderProgram_GetName());
 }
 SolveMatrixColumns(&ok,&grid,&interior,&rhs.matrix,50,tolerance);
 if(!ok) {
  *result=0;interior.UpdateState_00c7b0f0();temporary.free();rhs.matrix.UpdateState_00c7b0f0();grid.FreeThreeDynamicArrays();return result;
 }
 ElevationArray<KnotVector> fitted;
 fitted.data=0;fitted.count=0;fitted.capacity=0x80000000;
 fitted.resize(n+1);
 fitted.data[0].FUN_00e53180(points->data[0]);
 fitted.data[n].FUN_00e53180(points->data[m]);
 for(int i=1;i<n;++i) {
  for(int j=0;j<4;++j) {float* src=&interior.GetElementPtr(i-1,j);KnotVector* base=fitted.data;_ReadWriteBarrier();float* dst=&base[i].GetElementAddress_00e53590(j);*dst=*src;}
 }
 if(*CheckPointsWithinThreshold(&ok,n,degree,&fitted,knots,m,points,params,tolerance2)) {
  output->SwapThreeInts(&fitted);*result=1;
 } else *result=0;
 fitted.free();interior.UpdateState_00c7b0f0();temporary.free();rhs.matrix.UpdateState_00c7b0f0();grid.FreeThreeDynamicArrays();return result;
}
}  // namespace fnv_00e57620

struct MemoryAllocator;
// Adapted from an unverified 2026-10-23 saved reconstruction (credited as 'you').
struct Vertex4 {

    float x, y, z, w;

    Vertex4(float a=0, float b=0, float c=0, float d=0);

    Vertex4* FUN_00e53180(const Vertex4* source);

};
__declspec(noinline) Vertex4::Vertex4(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
__declspec(noinline) Vertex4* Vertex4::FUN_00e53180(const Vertex4* source) { x=source->x; y=source->y; z=source->z; w=source->w; return this; }
struct FloatVector {
    void reserve(MemoryAllocator& alloc, int wanted);

    float* data;

    int count;

    unsigned int capacity;

};
struct VertexVector {
    void SetSizeAndGrow(int wanted);
    void reserve(MemoryAllocator& alloc, int wanted);

    Vertex4* data;

    int count;

    unsigned int capacity;

};
struct InputFloats { const float* data; };
struct InputVertices { const Vertex4* data; };
struct ScratchIndices {

    unsigned int* data;

    int count;

    int capacity;

};
struct MemoryAllocator {

    virtual void ReportDiagnostic();

    virtual void unused1();

    virtual void unused2();

    virtual void* Allocate(int* requestedBytes);

    virtual void Free(void* pointer, int requestedBytes);

};
struct AllocationEnvironment {

    unsigned int unk00, unk04, unk08, unk0c;

    MemoryAllocator* allocator;

};
extern int __cdecl hkaNURBS_DegreeElevateKnotVector(FloatVector*, int);
extern int __cdecl RemoveAdjacentDuplicates(FloatVector*, int);
extern int __cdecl hkaNURBS_RemoveKnotsBoundCurve(int*, int, FloatVector*, VertexVector*, int,

    const InputFloats*, ScratchIndices*, float, const InputVertices*);
struct EvaluationResult {

    bool active;

};
extern void __cdecl FitSpline(EvaluationResult*, int, int, VertexVector*, FloatVector*,

    int, const InputVertices*, const InputFloats*, float, float);
extern void __cdecl hkaNURBS_DegreeElevateCurve(int*, int, FloatVector*, VertexVector*, int);
extern void __cdecl hkaNURBS_UpdateFit(int, const InputVertices*, int, int, FloatVector*, VertexVector*,

    ScratchIndices*, const InputFloats*, int, int, float, float, void*);
extern const float DAT_010718c0, DAT_010959f4;
__forceinline void FloatVector::reserve(MemoryAllocator& heap, int wanted) {
    MemoryAllocator* alloc = &heap;
    FloatVector* vec = this;

    int cap = (int)(vec->capacity & 0x3fffffff);

    if (cap < wanted) {

        const int doubled = cap + cap;

        const int newCapacity = wanted < doubled ? doubled : wanted;

        hkArrayUtil__reserve((E4AAA0Allocator*)alloc, vec, newCapacity, 4);

    }

}
__forceinline void VertexVector::reserve(MemoryAllocator& heap, int wanted) {
    MemoryAllocator* alloc = &heap;
    VertexVector* vec = this;

    int cap = (int)(vec->capacity & 0x3fffffff);

    if (cap < wanted) {

        const int doubled = cap + cap;

        const int newCapacity = wanted < doubled ? doubled : wanted;

        hkArrayUtil__reserve((E4AAA0Allocator*)alloc, vec, newCapacity, 16);

    }

}
__forceinline void VertexVector::SetSizeAndGrow(int wanted) {
    HolderStub* mgr = hkMemoryRouter_getInstance();
    MemoryAllocator* heap = (MemoryAllocator*)mgr->m_pAllocator;
    reserve(*heap, wanted);
    int remaining=wanted-count;
    Vertex4* current=data+count;
    for(int index=0; index<remaining; ++index) new(current+index) Vertex4;
    count = wanted;
}
static __forceinline void FreeScratch(unsigned int* data, int capacity) {

    MemoryAllocator* alloc = ((AllocationEnvironment*)hkMemoryRouter_getInstance())->allocator;

    if ((capacity & 0x80000000) == 0)

        alloc->Free(data, (capacity & 0x3fffffff)*4);

}
static __forceinline void FreeScratchEarly(unsigned int* data, int capacity) {
    HolderStub* mgr = hkMemoryRouter_getInstance();
    MemoryAllocator* heap = (MemoryAllocator*)mgr->m_pAllocator;
    int cap=capacity;
    if ((cap & 0x80000000) == 0) heap->Free(data,(cap & 0x3fffffff)*4);
}
// Loops over passes calling helper routines on the position and vertex vectors and a scratch array, then runs a final step and frees the scratch array.
// @fnv 0x00e57d60
void __cdecl ProcessGeometryPasses(int initialCount,

    const InputVertices* inputVertices, const InputFloats* inputFloats,

    void* geometry, int passes, float factor, int& countOutput,

    FloatVector& positionOutput, VertexVector& vertexOutput)

{
    int* currentCount=&countOutput;
    FloatVector* positions=&positionOutput;
    VertexVector* vertices=&vertexOutput;

    *currentCount = initialCount;

    const int floatsWanted = initialCount + 3;

    HolderStub* mgr = hkMemoryRouter_getInstance();
    MemoryAllocator* heap = (MemoryAllocator*)mgr->m_pAllocator;
    positions->reserve(*heap, floatsWanted);

    positions->count = floatsWanted;

    const int verticesWanted = *currentCount + 1;

    vertices->SetSizeAndGrow(verticesWanted);

    positions->data[0] = inputFloats->data[0];

    positions->data[initialCount + 2] = inputFloats->data[initialCount];

    for (int i=0; i<=initialCount; ++i) {

        positions->data[i+1] = inputFloats->data[i];

        vertices->data[i].FUN_00e53180(&inputVertices->data[i]);

    }

    union FitWork { int bytes; EvaluationResult result; };
    unsigned int* ownedData;
    int allocatedCount = initialCount + 1;
    int ownedCapacity;
    HolderStub* scratchRouter = hkMemoryRouter_getInstance();
    MemoryAllocator* scratchHeap = (MemoryAllocator*)scratchRouter->m_pAllocator;
    {
    FitWork work;
    if(allocatedCount) {
        work.bytes = allocatedCount * 4;
        unsigned int* storage = (unsigned int*)scratchHeap->Allocate(&work.bytes);
        allocatedCount = work.bytes / 4;
        ownedData = storage;
    } else ownedData = 0;
    ownedCapacity = allocatedCount ? allocatedCount : (int)0x80000000;
    ScratchIndices scratch;
    scratch.data = ownedData;
    scratch.count = allocatedCount;
    scratch.capacity = ownedCapacity;
    for(int i=0; i<allocatedCount; ++i) ownedData[i]=0;

    int status=0;

    for(int pass=1; pass<=passes; ++pass) {

        status = hkaNURBS_RemoveKnotsBoundCurve(currentCount,pass,positions,vertices,initialCount,inputFloats,&scratch,factor,inputVertices);

        if (pass == passes) break;
        {

            const int appended = hkaNURBS_DegreeElevateKnotVector(positions,*currentCount+pass+1);

            *currentCount += appended+1;

            vertices->SetSizeAndGrow(*currentCount+1);

            FitSpline(&work.result,*currentCount,pass+1,vertices,positions,

                initialCount,inputVertices,inputFloats,DAT_010718c0,factor);

            if (!work.result.active) {

                const int removed = RemoveAdjacentDuplicates(positions,*currentCount+pass+1);

                *currentCount -= removed+1;

                vertices->SetSizeAndGrow(*currentCount+1);

                hkaNURBS_DegreeElevateCurve(currentCount,pass,positions,vertices,1);

            }

            hkaNURBS_UpdateFit(initialCount,inputVertices,*currentCount,pass+1,positions,vertices,

                &scratch,inputFloats,100,10,DAT_010959f4,DAT_010959f4,geometry);

        }

    }

    if (!status) {
        FreeScratchEarly(ownedData, ownedCapacity);
        return;
    }
    {
        EvaluationResult result;
        FitSpline(&result,*currentCount,passes,vertices,positions,

            initialCount,inputVertices,inputFloats,DAT_010718c0,factor);

        hkaNURBS_UpdateFit(initialCount,inputVertices,*currentCount,passes,positions,vertices,

            &scratch,inputFloats,100,10,DAT_010959f4,DAT_010959f4,geometry);

        hkaNURBS_RemoveKnotsBoundCurve(currentCount,passes,positions,vertices,initialCount,inputFloats,&scratch,factor,inputVertices);

    }

    FreeScratch(ownedData, ownedCapacity);

}
}

struct SpawnedAllocator {
    virtual void unkV0();
    virtual void unkV1();
    virtual void unkV2();
    virtual void* hkMemoryAllocator(int* size);
    virtual void Free(void* block, unsigned int size);
};

struct SpawnedHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};

struct SpawnedBlockRef {
    void* data;
    int count;
    unsigned int flags;
};

void __cdecl hkaNURBS_ChordLengthParameterization(int a1, int a2, void* s);
void __cdecl ProcessGeometryPasses(int a1, int a2, SpawnedBlockRef* block, hkBool enabled, int b1, float b2, int b3, int b4, int b5);

// @fnv 0x00e58210
// src: HAVOK_LIB 0x00e58210
void __cdecl hkaNURBS_GlobalCurveApproxErrBnd(int a1, int a2, int a3, float a4, int a5, int a6, int a7)
{
    int n = a1 + 1;
    SpawnedBlockRef blk;
    blk.data = 0;
    blk.count = 0;
    blk.flags = 0x80000000u;

    SpawnedHolder* h = reinterpret_cast<SpawnedHolder*>(hkMemoryRouter_getInstance());
    SpawnedAllocator* pAllocator = h->m_pAllocator;
    void* data;
    if (n != 0) {
        int size = n * 4;
        void* p = pAllocator->hkMemoryAllocator(&size);
        n = size / 4;
        data = p;
    } else {
        data = 0;
    }
    unsigned int flags = n != 0 ? (unsigned int)n : 0x80000000u;
    blk.flags = flags;
    blk.count = n;
    blk.data = data;
    hkaNURBS_ChordLengthParameterization(a1, a2, &blk);
    ProcessGeometryPasses(a1, a2, &blk, true, a3, a4, a5, a6, a7);

    h = reinterpret_cast<SpawnedHolder*>(hkMemoryRouter_getInstance());
    pAllocator = h->m_pAllocator;
    unsigned int f = blk.flags;
    blk.count = 0;
    if ((f & 0x80000000u) == 0) {
        pAllocator->Free(blk.data, (f & 0x3fffffffu) * 4);
    }
}

struct SolverState {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    float m_3c;
    float m_40;
    float m_44;
    float m_48;
    float m_4c;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;
    float m_60;
    float m_64;
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    float m_78;
    float m_7c;
    float m_80;
    float m_84;
    float m_88;
    float m_8c;
    float m_90;
    float m_94;
    float m_98;
};

struct SolverOutput {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
};

struct BoundaryTable {
    float samples[16];
    float scale;
    float initialScale;
};

extern double _gModifierZero;
extern float DAT_0104da4c;
extern const float runtimeFloatSettingDefault1085 = 1.1f;

inline void ApplyBound(float& out, float value) {
    out = value;
    if (out < -1.1f) out = -1.1f;
    else if (out > runtimeFloatSettingDefault1085) out = runtimeFloatSettingDefault1085;
}
// Updates state from scaled values and a table-driven search, clamping blends to -1.1..1.1, and writes output m_1c, m_20 and m_08.
// @fnv 0x00e59700
// src: HAVOK_LIB 0x00e59700
static void hkVehicleFrictionSolverClipImpulse(SolverState* __restrict state, const BoundaryTable* table, SolverOutput* output)
{
    float a;
    a = state->m_94 * state->m_84;
    float b = state->m_90 * state->m_80;
    output->m_1c = a;
    output->m_20 = b;
    if (a * a + b * b < 1.0) {
        state->m_98 = 0.0f;
        return;
    }

    float kIter = a * table->initialScale;
    float ptr = 0.0f;
    float fPrevY = 0.0f;
    float cnt = 0.0f;
    float r = b * table->samples[0];
    long iIter;
    iIter = 0;
    float squaredLength = kIter * kIter + r * r;
    while (!(squaredLength > 1.0f)) {
        if (++iIter >= 16)
            break;
        ptr = kIter;
        fPrevY = r;
        cnt = squaredLength;
        kIter = kIter * table->scale;
        r = b * table->samples[iIter];
        squaredLength = kIter * kIter + r * r;
    }

    squaredLength = (float)sqrt(squaredLength);
    squaredLength = (float)(squaredLength - 1.0);
    cnt = (float)sqrt(cnt);
    cnt = cnt - 1.0f;
    float index = squaredLength - cnt;
    float idx;
    idx = (float)(index - _gModifierZero);
    idx = (float)fabs(idx);
    if (idx < DAT_0104da4c)
        index = DAT_0104da4c;
    float invDifference = 1.0f / index;

    float i;
    i = -cnt * invDifference;
    float fWeightX = squaredLength * invDifference;
    float blendX = fWeightX * ptr + i * kIter;

    float fClampedX;
    if(blendX < -1.1f) fClampedX = -1.1f;
    else if(blendX > runtimeFloatSettingDefault1085) fClampedX = runtimeFloatSettingDefault1085;
    else fClampedX = blendX;

    float blendY = i * r + fWeightX * fPrevY;

    float z;
    if (blendY < -1.1f)
        z = -1.1f;
    else if (blendY > runtimeFloatSettingDefault1085)
        z = runtimeFloatSettingDefault1085;
    else
        z = blendY;

    float fNewX = state->m_8c * fClampedX;
    float updatedY = state->m_88 * z;
    float deltaX = state->m_84 - fNewX;
    state->m_84 = fNewX;
    state->m_98 = state->m_80 - updatedY;
    state->m_80 = updatedY;

    float fTailNormSq = state->m_60 * state->m_60 + state->m_68 * state->m_68;
    idx = (float)(fTailNormSq - _gModifierZero);
    idx = (float)fabs(idx);
    if (idx < DAT_0104da4c)
        fTailNormSq = DAT_0104da4c;

    float forceY = state->m_7c * state->m_98 * state->m_88;
    float val = state->m_74 * deltaX * state->m_8c;
    val = forceY * forceY + val * val;
    float j = 1.0f / fTailNormSq;
    j = j * val;
    output->m_08 = (float)sqrt(j);
}

void caller(SolverState* s, const BoundaryTable* t, SolverOutput* o) {
    hkVehicleFrictionSolverClipImpulse(s, t, o);
}

struct Se5b160_Heap {
    virtual ~Se5b160_Heap();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct Se5b160_Router {
    int unk00; int unk04; int unk08; int unk0c;
    Se5b160_Heap* m_pStreamAllocator;
    Se5b160_Heap& heap() { return *m_pStreamAllocator; }
    static Se5b160_Router& GetMonitorStream() { return *reinterpret_cast<Se5b160_Router*>(hkMemoryRouter_getInstance()); }
};
struct Se5b160_Motor { void FUN_00c90510(); };
struct Se5b160_RefObj {
    virtual ~Se5b160_RefObj();
    static Se5b160_Heap& heap() { return reinterpret_cast<Se5b160_Router*>(hkMemoryRouter_getInstance())->heap(); }
    unsigned short m_usAllocationSize;
    unsigned short m_iObjectReferenceCount;
    static void* operator new(unsigned int nbytes) {
        Se5b160_RefObj* b = static_cast<Se5b160_RefObj*>(Se5b160_Router::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usAllocationSize = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void*) {}
    void FUN_00c905b0();
};
struct Se5b160_HingeAtoms {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    Se5b160_Motor* motor0;
    void CopyStateFrom(const Se5b160_HingeAtoms* source);
};
struct Se5b160_RagdollAtoms {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    Se5b160_Motor* motor0;
    Se5b160_Motor* motor1;
    Se5b160_Motor* motor2;
    void ProcessAndReturnValue_00d85ba0(const Se5b160_RagdollAtoms* source);
};
// src: HAVOK_LIB 0x00e5b110
static __declspec(noinline) void _copyAtoms(const Se5b160_HingeAtoms* source, Se5b160_HingeAtoms* destination) {
    destination->CopyStateFrom(source);
    Se5b160_Motor* m = destination->motor0;
    if (m) m->FUN_00c90510();
}
// src: HAVOK_LIB 0x00e5b130
static __declspec(noinline) void _copyAtoms_00e5b130(const Se5b160_RagdollAtoms* source, Se5b160_RagdollAtoms* destination) {
    destination->ProcessAndReturnValue_00d85ba0(source);
    Se5b160_Motor** motor = &destination->motor0;
    for (int i = 0; i < 3; ++i, ++motor) {
        if (*motor) (*motor)->FUN_00c90510();
    }
}
struct Se5b160_Data : Se5b160_RefObj {
    virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual hkpConstraintData::ConstraintType getType() const;
    int unk08; int unk0c;
};
struct FUN_00cb9090 : Se5b160_Data {
    Se5b160_HingeAtoms m_kBridgeAtoms;
    int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; 
    FUN_00cb9090() throw();
    void SetReferencedObject(Se5b160_Motor* motor);
    void hkpLimitedHingeConstraintData_setMotorActive(void* info, bool enabled);
};
struct FUN_00cdf2f0 : Se5b160_Data {
    Se5b160_RagdollAtoms m_kBridgeAtoms;
    int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; 
    FUN_00cdf2f0() throw();
    void hkpRagdollConstraintData_setTwistMotor(Se5b160_Motor* motor);
    void hkpRagdollConstraintData_setPlaneMotor(Se5b160_Motor* motor);
    void hkpRagdollConstraintData_setConeMotor(Se5b160_Motor* motor);
    void SetFlagAndClearFloats(void* info, bool enabled);
};
struct Se5b160_StrPtr {
    const char* m_pcText;
    const char* cString() const { return reinterpret_cast<const char*>(reinterpret_cast<unsigned int>(m_pcText) & ~1u); }
    void UpdateState_00cb0c10(const char* s);
};
struct Se5b160_Entity;
struct Se5b160_PrioEnum {
    unsigned char m_kStorage;
    operator hkpConstraintInstance::ConstraintPriority() const { return static_cast<hkpConstraintInstance::ConstraintPriority>(m_kStorage); }
};
struct FUN_00cf3ea0 : Se5b160_RefObj {
    int unk08;
    Se5b160_Data* m_data;
    int unk10;
    Se5b160_Entity* m_pEntityA;
    Se5b160_Entity* m_pEntityB;
    Se5b160_PrioEnum m_priority;
    unsigned char unk1d;
    unsigned short unk1e;
    int unk20;
    int unk24;
    Se5b160_StrPtr m_name;
    int unk2c; int unk30; int unk34;
    FUN_00cf3ea0(Se5b160_Entity* a, Se5b160_Entity* b, Se5b160_Data* data, hkpConstraintInstance::ConstraintPriority priority) throw();
    hkpConstraintInstance::ConstraintPriority getPriority() const { return m_priority; }
    Se5b160_Entity* getEntityA() const { return m_pEntityA; }
    Se5b160_Entity* getEntityB() const { return m_pEntityB; }
};
typedef FUN_00cf3ea0 Se5b160_Instance;

// @fnv 0x00e5b160
Se5b160_Instance* __cdecl CreatePoweredConstraint(const Se5b160_Instance* __restrict original, Se5b160_Motor* motor, bool enableMotors) {
    Se5b160_Instance* newConstraint = 0;
    Se5b160_Data* constraintData = original->m_data;
    Se5b160_Entity* entityA = original->getEntityA();
    Se5b160_Entity* entityB = original->getEntityB();
    switch (constraintData->getType()) {
    case hkpConstraintData::CONSTRAINT_TYPE_LIMITEDHINGE: {
        FUN_00cb9090* newData = new FUN_00cb9090();
        FUN_00cb9090* oldData = static_cast<FUN_00cb9090*>(constraintData);
        _copyAtoms(&oldData->m_kBridgeAtoms, &newData->m_kBridgeAtoms);
        newData->SetReferencedObject(motor);
        newData->hkpLimitedHingeConstraintData_setMotorActive(0, enableMotors);
        newConstraint = new Se5b160_Instance(entityA, entityB, newData, original->getPriority());
        newData->FUN_00c905b0();
        newConstraint->m_name.UpdateState_00cb0c10(original->m_name.cString());
        break;
    }
    case hkpConstraintData::CONSTRAINT_TYPE_RAGDOLL: {
        FUN_00cdf2f0* oldData = static_cast<FUN_00cdf2f0*>(constraintData);
        FUN_00cdf2f0* newData = new FUN_00cdf2f0();
        _copyAtoms_00e5b130(&oldData->m_kBridgeAtoms, &newData->m_kBridgeAtoms);
        newData->hkpRagdollConstraintData_setTwistMotor(motor);
        newData->hkpRagdollConstraintData_setPlaneMotor(motor);
        newData->hkpRagdollConstraintData_setConeMotor(motor);
        newData->SetFlagAndClearFloats(0, enableMotors);
        newConstraint = new Se5b160_Instance(entityA, entityB, newData, original->getPriority());
        newData->FUN_00c905b0();
        newConstraint->m_name.UpdateState_00cb0c10(original->m_name.cString());
        break;
    }
    default:
        {
            int buf[128];
            CharBuffer ostr;
            ostr.FUN_00cb1600(reinterpret_cast<char*>(buf), sizeof(buf));
            ostr.ProcessAndReturnValue_00cc01c0("Cannot convert constraint \"")->ProcessAndReturnValue_00cc01c0(original->m_name.cString())->ProcessAndReturnValue_00cc01c0("\" to a powered constraint.");
            DAT_01268360->report(1, 0xabba1b34, reinterpret_cast<char*>(buf), ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 111);
            ostr.FUN_00cc00e0();
        }
        {
            int buf[128];
            CharBuffer ostr;
            ostr.FUN_00cb1600(reinterpret_cast<char*>(buf), sizeof(buf));
            ostr.ProcessAndReturnValue_00cc01c0("Only limited hinges and ragdoll constraints can be powered.");
            DAT_01268360->report(1, 0xabba1b34, reinterpret_cast<char*>(buf), ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 112);
            ostr.FUN_00cc00e0();
        }
        return 0;
    }
    return newConstraint;
}

struct S00e51a60_BlockDesc {
    unsigned int m_uiFirstQuantizationParameter;
    unsigned int m_uiBlockOffset;
    unsigned int m_ucSecondQuantizationParameter;
};

// @fnv 0x00e51a60
unsigned int __cdecl DecodeBlock(const unsigned char* encodedData, S00e51a60_BlockDesc& desc, unsigned char* rawData, unsigned int rawDataSizeBytes)
{
    unsigned int nBits = (rawDataSizeBytes - desc.m_ucSecondQuantizationParameter * 4) * 8;
    unsigned int nValues = nBits / desc.m_uiFirstQuantizationParameter;

    float* rawOut = (float*)rawData;
    const float* rawIn = (const float*)encodedData;
    for (unsigned int i = 0; i < desc.m_ucSecondQuantizationParameter; i++)
    {
        *rawOut++ = *rawIn++;
    }
    rawData = (unsigned char*)((float*)rawData + desc.m_ucSecondQuantizationParameter);
    encodedData = (const unsigned char*)((const float*)encodedData + desc.m_ucSecondQuantizationParameter);

    unsigned int buffer = 0;
    unsigned int outBuffer = 0;
    unsigned char bitsInBuffer = 0;
    unsigned char outBits = 0;
    unsigned short value = 0;
    unsigned int tmp = 0;
    unsigned short word = 0;
    unsigned short mask = (unsigned short)((1 << desc.m_uiFirstQuantizationParameter) - 1);
    const unsigned char* flagPtr = encodedData;
    unsigned char flagBit = 1;
    encodedData += (nValues + 7) >> 3;

    bitsInBuffer = 0;
    word = *encodedData;
    encodedData++;
    word |= *encodedData << 8;
    encodedData++;
    tmp = word;
    tmp >>= bitsInBuffer;
    buffer |= tmp;
    bitsInBuffer = 16 - bitsInBuffer;

    unsigned char flag = 0;
    unsigned int count = 0;

    switch (desc.m_uiFirstQuantizationParameter)
    {
    case 8:
        for (unsigned int i = 0; i < nValues; i++)
        {
            flag = *flagPtr & flagBit;
            if (flag)
            {
                *rawData++ = (unsigned char)desc.m_uiBlockOffset;
            }
            else
            {
                if (bitsInBuffer < 8)
                {
                    word = *encodedData;
                    encodedData++;
                    word |= *encodedData << 8;
                    encodedData++;
                    tmp = word;
                    tmp <<= bitsInBuffer;
                    buffer |= tmp;
                    bitsInBuffer += 16;
                }
                value = (unsigned short)(buffer & 0xffff);
                value &= mask;
                *rawData++ = (unsigned char)(value & 0xff);
                buffer >>= 8;
                bitsInBuffer -= 8;
                count++;
            }
            flagBit <<= 1;
            if (!flagBit)
            {
                flagBit = 1;
                flagPtr++;
            }
        }
        break;
    case 16:
    {
        unsigned char lo = (unsigned char)(desc.m_uiBlockOffset & 0xff);
        unsigned char hi = (unsigned char)((desc.m_uiBlockOffset & 0xff00) >> 8);
        for (unsigned int i = 0; i < nValues; i++)
        {
            flag = *flagPtr & flagBit;
            if (flag)
            {
                *rawData++ = lo;
                *rawData++ = hi;
            }
            else
            {
                if (bitsInBuffer < 16)
                {
                    word = *encodedData;
                    encodedData++;
                    word |= *encodedData << 8;
                    encodedData++;
                    tmp = word;
                    tmp <<= bitsInBuffer;
                    buffer |= tmp;
                    bitsInBuffer += 16;
                }
                value = (unsigned short)(buffer & 0xffff);
                *rawData++ = (unsigned char)(value & 0xff);
                *rawData++ = (unsigned char)((value & 0xff00) >> 8);
                buffer >>= 16;
                bitsInBuffer -= 16;
                count++;
            }
            flagBit <<= 1;
            if (!flagBit)
            {
                flagBit = 1;
                flagPtr++;
            }
        }
        break;
    }
    default:
        for (unsigned int i = 0; i < nValues; i++)
        {
            flag = *flagPtr & flagBit;
            if (flag)
            {
                tmp = desc.m_uiBlockOffset;
                tmp <<= outBits;
                outBits = outBits + (unsigned char)desc.m_uiFirstQuantizationParameter;
                outBuffer |= tmp;
                if (outBits > 15)
                {
                    *rawData++ = (unsigned char)(outBuffer & 0xff);
                    *rawData++ = (unsigned char)(outBuffer >> 8) & 0xff;
                    outBuffer >>= 16;
                    outBits -= 16;
                }
            }
            else
            {
                if (bitsInBuffer >= desc.m_uiFirstQuantizationParameter)
                {
processData:
                    value = (unsigned short)(buffer & 0xffff);
                    value &= mask;
                    tmp = value;
                    tmp <<= outBits;
                    outBits = outBits + (unsigned char)desc.m_uiFirstQuantizationParameter;
                    outBuffer |= tmp;
                    if (outBits > 15)
                    {
                        *rawData++ = (unsigned char)(outBuffer & 0xff);
                        *rawData++ = (unsigned char)(outBuffer >> 8) & 0xff;
                        outBuffer >>= 16;
                        outBits -= 16;
                    }
                    buffer >>= desc.m_uiFirstQuantizationParameter;
                    bitsInBuffer = bitsInBuffer - (unsigned char)desc.m_uiFirstQuantizationParameter;
                    count++;
                }
                else
                {
                    word = *encodedData;
                    encodedData++;
                    word |= *encodedData << 8;
                    encodedData++;
                    tmp = word;
                    tmp <<= bitsInBuffer;
                    buffer |= tmp;
                    bitsInBuffer += 16;
                    goto processData;
                }
            }
            flagBit <<= 1;
            if (!flagBit)
            {
                flagBit = 1;
                flagPtr++;
            }
        }
        if (outBits > 0)
        {
            *rawData++ = (unsigned char)(outBuffer & 0xff);
            if (outBits > 7)
            {
                *rawData++ = (unsigned char)(outBuffer >> 8) & 0xff;
            }
        }
        break;
    }

    count = (count * desc.m_uiFirstQuantizationParameter + nValues + desc.m_ucSecondQuantizationParameter * 4 * 8 + 7) >> 3;
    return count;
}

struct E5B130Object {
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
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    Ref* items[3];
    void ProcessAndReturnValue_00d85ba0(int finishFlags);
};

// Calls FUN_00d85ba0 with finishFlags, then iterates the three item pointers and calls FUN_00c90510 on each non-null item.
// @fnv 0x00e5b130
// src: HAVOK_LIB 0x00e5b130
static __declspec(noinline) void _copyAtoms_00e5b130(E5B130Object* object, int finishFlags)
{
    object->ProcessAndReturnValue_00d85ba0(finishFlags);
    Ref** item = object->items;
    int remaining = 3;
    do {
        if (*item)
            (*item)->FUN_00c90510();
        ++item;
    } while (--remaining);
}

E5B130Object* volatile g_finishObject;
volatile int g_finishFlags;
void CallFinishObject() { _copyAtoms_00e5b130(g_finishObject, g_finishFlags); }

#include <xmmintrin.h>
namespace fnv_00e4b6e0 {
// Keep this routine's float-only intrinsic view of the shared vector storage.
// Exe 0x00e4b6e0 FUN_00e4b6e0: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {float f[4];} __m128, LocalM128;
extern "C" {LocalM128 _mm_mul_ps(LocalM128,LocalM128);LocalM128 _mm_sub_ps(LocalM128,LocalM128);LocalM128 _mm_add_ss(LocalM128,LocalM128);LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int);int _mm_movemask_ps(LocalM128);LocalM128 _mm_rsqrt_ss(LocalM128);}
static inline LocalM128 GetVector(const Vec4& value) { return *reinterpret_cast<const LocalM128*>(&value.m_vComponents); }
static inline void SetVector(Vec4& target, LocalM128 value) { *reinterpret_cast<LocalM128*>(&target.m_vComponents) = value; }
static inline Vec4& CopyVector(Vec4& target, const Vec4& value) { SetVector(target, GetVector(value)); return target; }
static inline void SubVector(Vec4& target, const Vec4& x, const Vec4& y) { SetVector(target, _mm_sub_ps(GetVector(x), GetVector(y))); }
static inline __m128 DotVector3(const Vec4& x, const Vec4& y)
{
    __m128 v = _mm_mul_ps(GetVector(x), GetVector(y));
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), xy);
}
static inline void NormalizeVector(Vec4& target)
{
    __m128 squared = DotVector3(target, target);
    __m128 inv = _mm_rsqrt_ss(squared);
    SetVector(target, _mm_mul_ps(GetVector(target), _mm_shuffle_ps(inv, inv, 0)));
}
static inline void CrossVector(Vec4& target, const Vec4& x, const Vec4& y)
{
    __m128 xv = GetVector(x), yv = GetVector(y);
    __m128 pos = _mm_mul_ps(_mm_shuffle_ps(xv, xv, 0xc9), _mm_shuffle_ps(yv, yv, 0xd2));
    __m128 neg = _mm_mul_ps(_mm_shuffle_ps(xv, xv, 0xd2), _mm_shuffle_ps(yv, yv, 0xc9));
    SetVector(target, _mm_sub_ps(pos, neg));
}
}  // namespace fnv_00e4b6e0

inline void Vec4::setSub4(const Vec4& x, const Vec4& y) { fnv_00e4b6e0::SubVector(*this, x, y); }
inline void Vec4::normalize3() { fnv_00e4b6e0::NormalizeVector(*this); }
inline void Vec4::setCross(const Vec4& x, const Vec4& y) { fnv_00e4b6e0::CrossVector(*this, x, y); }

namespace fnv_00e4b6e0 {
struct PointArg {const Vec4* p; PointArg(const Vec4* v):p(v){}};
struct Segment {Vec4 first,second,unk20,unk30,firstMeta,secondMeta;};
// Tests a point against segment endpoints; between them writes a cross product and returns count, otherwise writes a difference vector and returns 1.
// @fnv 0x00e4b6e0
// src: GUESS 0x00e4b6e0 (confidence: medium)
static __declspec(noinline) int Object_ComputePointSegmentVector(PointArg input, Segment* segment, int count, Vec4* output, int kind){
Vec4 point; CopyVector(point,*input.p);
Vec4 direction; direction.setSub4(segment->second,segment->first);
Vec4 b; b.setSub4(segment->second,point);
Vec4 a; a.setSub4(segment->first,point);
__m128 bdot=DotVector3(b, direction);
__m128 adot=DotVector3(a, direction);
int negativeB=_mm_movemask_ps(bdot)&1;
int negativeA=_mm_movemask_ps(adot)&1;
if(negativeB!=negativeA){
 direction.normalize3();
 Vec4 c; c.setCross(b,a);
 if(kind==1) {output->setCross(direction,c); return count;} output->setCross(c,direction); return count;
}else{
 if(negativeB){CopyVector(segment->first,segment->second);CopyVector(segment->firstMeta,segment->secondMeta);}
 if(kind==1){output->setSub4(point,segment->first); return 1;} output->setSub4(segment->first,point); return 1;
}
}
Vec4* volatile pointInput;Segment* volatile segmentInput;Vec4* volatile resultInput;volatile int kindInput;
extern "C" int ReadCountInput();
int invoke_target(){return Object_ComputePointSegmentVector(PointArg(pointInput),segmentInput,ReadCountInput(),resultInput,kindInput);}
}  // namespace fnv_00e4b6e0

struct S00e58310_Allocator {
    virtual ~S00e58310_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T>
    inline T* _bufAlloc(int& reqNumInOut)
    {
        const int SIZE_ELEM = sizeof(T);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<T*>(p);
    }
    template <typename T>
    inline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};

struct S00e58310_Router {
    int m_aiEntries;
    int m_pTemp;
    int m_pSolver;
    int m_pDebugAllocator;
    S00e58310_Allocator* m_pStreamAllocator;
    S00e58310_Allocator& heap() { return *m_pStreamAllocator; }
    static __forceinline S00e58310_Router& GetMonitorStream();
};

__forceinline S00e58310_Router& S00e58310_Router::GetMonitorStream()
{
    return *(S00e58310_Router*)hkMemoryRouter_getInstance();
}

struct S00e58310_HeapAllocator {
    S00e58310_Allocator& get(const void*) { return S00e58310_Router::GetMonitorStream().heap(); }
};

struct S00e58310_TypeIsPod {};

struct S00e58310_Util {
    template <typename T>
    static __forceinline void destruct(T*, int, S00e58310_TypeIsPod) {}
};

template <typename T>
// local form of hkArrayBase: 0x00e58310 needs the local initialization/copy helper split; the shared form changes extent from 292 to 296 bytes.
struct S00e58310_ArrayBase {
    enum { CAPACITY_MASK = 0x3FFFFFFF, DONT_DEALLOCATE_FLAG = 0x80000000 };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & CAPACITY_MASK; }
    static __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i) {
            dst[i] = src[i];
        }
    }
    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void clear()
    {
        S00e58310_Util::destruct(m_data, m_iElementCount, S00e58310_TypeIsPod());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(S00e58310_Allocator& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline S00e58310_ArrayBase<T>& copyFromArray(S00e58310_Allocator& alloc, const S00e58310_ArrayBase<T>& a, S00e58310_TypeIsPod)
    {
        if (getCapacity() < a.GetLogicalSize()) {
            if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
                alloc._bufFree<T>(m_data, getCapacity());
            }
            int n = a.GetLogicalSize();
            m_data = alloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copy(m_data, a.m_data, m_iElementCount);
        return *this;
    }
};

template <typename T>
struct S00e58310_Array : S00e58310_ArrayBase<T> {
    __forceinline S00e58310_Array<T>& operator=(const S00e58310_Array<T>& a)
    {
        copyFromArray(S00e58310_HeapAllocator().get(this), a, S00e58310_TypeIsPod());
        return *this;
    }
    __forceinline void destroy()
    {
        _clearAndDeallocate(S00e58310_HeapAllocator().get(this));
    }
};

struct S00e58310_Point {
    float x;
    float y;
    float z;
    float w;
};

__declspec(noinline) void __cdecl ProcessGeometryPasses(int n, const S00e58310_Array<S00e58310_Point>& Q, S00e58310_Array<float>& Ub, hkBool useCurvature, int degree, float E, int& nh, S00e58310_Array<float>& U, S00e58310_Array<S00e58310_Point>& P)
{
    nh = n;
    U.m_data[0] = Ub.m_data[0];
    U.m_data[n + 2] = Ub.m_data[n];
    for (int i = 0; i <= n; ++i) {
        U.m_data[i + 1] = Ub.m_data[i];
        P.m_data[i] = Q.m_data[i];
    }
}

// Copies Ub into a temporary array, calls ProcessGeometryPasses with it and the other arguments, then frees the temporary.
// @fnv 0x00e58310
// src: HAVOK_LIB 0x00e58310
void __cdecl hkaNURBS_GlobalCurveApproxErrBnd_00e58310(int n, const S00e58310_Array<S00e58310_Point>& Q, const S00e58310_Array<float>& Ub, int degree, float E, int& nh, S00e58310_Array<float>& U, S00e58310_Array<S00e58310_Point>& P)
{
    S00e58310_Array<float> uCopy;
    uCopy.init();
    uCopy = Ub;
    ProcessGeometryPasses(n, Q, uCopy, false, degree, E, nh, U, P);
    uCopy.destroy();
}

struct CurvePoint { float x,y,z,w; CurvePoint(float a=0,float b=0,float c=0,float d=0) throw(); float& GetElementAddress_00e53590(int); };
__declspec(noinline) CurvePoint::CurvePoint(float a,float b,float c,float d) throw():x(a),y(b),z(c),w(d){}
// src: GUESS 0x00e53590 (confidence: low)
__declspec(noinline) float& CurvePoint::GetElementAddress_00e53590(int i) {return (&x)[i];}
struct CurveHeap {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void* allocate(int& bytes) throw();
 virtual void release(void* ptr,int bytes) throw();
 template<class T> __forceinline T* allocateItems(int& n) {
  int request=n*(int)sizeof(T);
  T* ptr=static_cast<T*>(allocate(request));
  n=request/(int)sizeof(T);
  return ptr;
 }
 template<class T> __forceinline void freeItems(T* ptr,int n) {release(ptr,n*(int)sizeof(T));}
};
struct CurvePolicy {
 __forceinline CurveHeap& get(void*) {return *static_cast<CurveHeap*>(hkMemoryRouter_getInstance()->m_pAllocator);}
};
__forceinline void initializeItems(float*,int) {}
__forceinline void initializeItems(CurvePoint* ptr,int n) {for(int i=0;i<n;++i) new(ptr+i) CurvePoint;}
template<class T> struct FitOwnedArrayBase {
 T* data;int size;int capacity;
 __forceinline FitOwnedArrayBase():data(0),size(0),capacity(0x80000000){}
 __forceinline void set(T* p,int n,int cap) {data=p;size=n;capacity=cap;}
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline const T& operator[](int i) const {return data[i];}
 __forceinline void clear(CurveHeap& heap) {
  size=0;
  int cap=capacity;
  if(!(cap&0x80000000)) heap.freeItems<T>(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;
 }
};
template<class T> struct FitOwnedArray:FitOwnedArrayBase<T> {
 __forceinline FitOwnedArray() throw() {}
 __forceinline FitOwnedArray(int n) throw() {
  HolderStub* holder=hkMemoryRouter_getInstance(); CurveHeap* heap=static_cast<CurveHeap*>(holder->m_pAllocator);
  T* p=n?heap->allocateItems<T>(n):0;
  int cap=n?n:0x80000000;
  set(p,n,cap);
  initializeItems(data,n);
 }
 __forceinline ~FitOwnedArray() throw() {HolderStub* holder=hkMemoryRouter_getInstance(); CurveHeap* heap=static_cast<CurveHeap*>(holder->m_pAllocator);
  int cap=capacity; size=0;
  if(!(cap&0x80000000)) heap->freeItems<T>(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;}
};
struct CurveWirePoints {CurvePoint* data;int size;int capacity;};
void __cdecl ProcessGeometryPasses(int,const CurveWirePoints*,FitOwnedArray<float>*,hkBool,int,float,int*,FitOwnedArray<float>*,FitOwnedArray<CurvePoint>*) throw();
// src: HAVOK_LIB 0x00e58310
__declspec(noinline) void __cdecl hkaNURBS_GlobalCurveApproxErrBnd_00e58310(int count,const FitOwnedArray<CurvePoint>* points,const FitOwnedArray<float>* values,int degree,float tolerance,int* last,FitOwnedArray<float>* outValues,FitOwnedArray<CurvePoint>* outPoints) throw() {
 FitOwnedArray<float> writable(values->size);
 for(int i=0;i<values->size;++i) writable[i]=values->data[i];
 CurveWirePoints input={points->data,points->size,points->capacity};
 ProcessGeometryPasses(count,&input,&writable,hkBool(false),degree,tolerance,last,outValues,outPoints);
}
// Copies values and points into owned arrays, calls FUN_00e58310, then writes the resulting points and values to resultPoints and knots and sets both counts.
// @fnv 0x00e58440
// src: HAVOK_LIB 0x00e58440
void __cdecl hkaNURBS_ApproximateCurve(int aiPointCount,const float* values,const Float4* points,int degree,float tolerance,int* knotCount,float* knots,int* pointCount,Float4* resultPoints) {
 FitOwnedArray<CurvePoint> inPoints(aiPointCount);
 FitOwnedArray<float> inValues(aiPointCount);
 for(int i=0;i<aiPointCount;++i) {
  inValues[i]=values[i];
  inPoints[i].GetElementAddress_00e53590(0)=points[i].x;
  inPoints[i].GetElementAddress_00e53590(1)=points[i].y;
  inPoints[i].GetElementAddress_00e53590(2)=points[i].z;
  inPoints[i].GetElementAddress_00e53590(3)=points[i].w;
 }
 FitOwnedArray<CurvePoint> outPoints;
 FitOwnedArray<float> outValues;
 { int last;
 hkaNURBS_GlobalCurveApproxErrBnd_00e58310(aiPointCount-1,&inPoints,&inValues,degree,tolerance,&last,&outValues,&outPoints);
 *pointCount=last+1;
 *knotCount=last+degree+2;
 for(int i=0;i<*pointCount;++i) {
  resultPoints[i].x=outPoints[i].GetElementAddress_00e53590(0);
  resultPoints[i].y=outPoints[i].GetElementAddress_00e53590(1);
  resultPoints[i].z=outPoints[i].GetElementAddress_00e53590(2);
  resultPoints[i].w=outPoints[i].GetElementAddress_00e53590(3);
 }
 for(int i=0;i<*knotCount;++i) knots[i]=outValues[i];
 }
}

struct E589Destination { float* data; int unknown04; int unknown08; int rows; int columns;
    float* GetElementAddress_00e587b0(int index);
};
struct E589Values { float* data; int unknown04; int unknown08; int rows; int columns;
// src: GUESS 0x00e58880 (confidence: low)
    __declspec(noinline) float GetIndexedValue_00e58880(int index) { return data[index]; }
    int EvaluateValue_00e58890();
};
struct E589ScaledValues { float* data; int unknown04; int unknown08; int rows; int columns;
// src: GUESS 0x00e58880 (confidence: low)
    __declspec(noinline) float GetIndexedValue_00e58880(int index) { return data[index]; }
};
// Adds the product of scale and scaleValues to each value in values, storing the result in destination.
// @fnv 0x00e58900
// src: HAVOK_LIB 0x00e58900
void __cdecl hkaCGSolver_float_ScaleAdd(E589Destination* destination,E589Values* values,const float* scale,E589ScaledValues* scaleValues)
{
    int count=values->EvaluateValue_00e58890();
    for(int index=0;index<count;++index) {
        float* output=destination->GetElementAddress_00e587b0(index);
        *output=values->GetIndexedValue_00e58880(index)+*scale*scaleValues->GetIndexedValue_00e58880(index);
    }
}

extern "C" void _ReadWriteBarrier();
extern __m128 DAT_01017d10;
extern const double DAT_01091c00;
struct __declspec(align(16)) PlaneVector {

    float f[4];

    __forceinline const __m128& quad() const { return *reinterpret_cast<const __m128*>(this); }

    __forceinline void assign(__m128 q) { *reinterpret_cast<__m128*>(this)=q; }

    __forceinline void setAnd(const PlaneVector& a, const __m128& b) { assign(_mm_and_ps(a.quad(), b)); }

    __forceinline void setZero4() { assign(_mm_setzero_ps()); }

    __forceinline void setAdd4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_add_ps(a.quad(), b.quad())); }

    __forceinline void setMul4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_mul_ps(a.quad(), b.quad())); }

    __forceinline void addMul4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_add_ps(quad(), _mm_mul_ps(a.quad(), b.quad()))); }

    __forceinline void setBroadcast(const PlaneVector& v, int i) { assign(_mm_shuffle_ps(v.quad(), v.quad(), 0)); }

    __forceinline void setAbs4(const PlaneVector& a) { assign(_mm_and_ps(a.quad(),DAT_01017d10)); }
    __forceinline void add4(const PlaneVector& a) { assign(_mm_add_ps(quad(),a.quad())); }
    __forceinline void setAll3(float f) { assign(_mm_set_ps1(f)); }

    float& operator()(int i) { return f[i]; }

    const float& operator()(int i) const { return f[i]; }

};

struct PlaneGroup {

    PlaneVector x, y, z, w;

    __forceinline void set(const PlaneVector& a, const PlaneVector& b, const PlaneVector& c, const PlaneVector& d) {

        x.assign(_mm_setr_ps(a(0),b(0),c(0),d(0)));

        y.assign(_mm_setr_ps(a(1),b(1),c(1),d(1)));

        z.assign(_mm_setr_ps(a(2),b(2),c(2),d(2)));

        w.assign(_mm_setr_ps(a(3),b(3),c(3),d(3)));

    }

};

struct QueryCode {
    void* table;
    unsigned short memoryFlags, references;
    PlaneVector origin;
    const unsigned char* program;
};
struct PlaneView { int count; const PlaneVector* data; };
struct QueryState { int x,y,z,primitive,property,shift; };
struct QueryBounds { PlaneVector minimum, scale; };
struct QueryMachine {
    int partial;
    __declspec(align(16)) float inverseScale;
    __declspec(align(16)) int complete;
    __declspec(align(16)) int count;
    PlaneGroup groups[8], magnitudes[8];
    void __thiscall ProcessEntries_00e5e430(QueryState*,const unsigned char*,QueryBounds*);
    __forceinline void prepare(const PlaneView& view, unsigned codeBits) {
        const QueryCode* code=reinterpret_cast<const QueryCode*>(codeBits);
        __assume(view.count>=0 && view.count<=32); int end=view.count & ~3;
        PlaneGroup* dest=groups;
        const PlaneVector* cursor=view.data;
        count=0;
        int n=0;
        for(;n<end;n+=4) {
            dest->set(cursor[0],cursor[1],cursor[2],cursor[3]);
            ++dest; ++count; cursor+=4;
        }
        const PlaneVector* a=cursor;
        const PlaneVector* b=cursor+1;
        const PlaneVector* c=cursor+2;
        const PlaneVector* d=cursor+3;
        switch(view.count-n) {
        case 1:b=a;
        case 2:c=a;
        case 3:d=a;
            dest->set(*a,*b,*c,*d);
            ++dest; ++count;
        }
        PlaneGroup* absolute=magnitudes+count;
        --absolute; --dest;
        for(;dest>=groups;--dest,--absolute) {
            PlaneGroup* g=dest; PlaneVector PlaneGroup::* yfield=&PlaneGroup::y; PlaneVector PlaneGroup::* zfield=&PlaneGroup::z;
            _ReadWriteBarrier(); absolute->x.setAbs4(g->x); _ReadWriteBarrier();
            absolute->y.setAbs4((g->*yfield)); _ReadWriteBarrier();
            absolute->z.assign(_mm_and_ps(DAT_01017d10,(g->*zfield).quad())); _ReadWriteBarrier();
            absolute->w.setZero4(); _ReadWriteBarrier();

        const PlaneVector& offset = code->origin;

        g->w.assign(_mm_add_ps(_mm_add_ps(_mm_add_ps(

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0x00), g->x.quad()),

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0x55), (g->*yfield).quad())),

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0xaa), (g->*zfield).quad())), g->w.quad()));

        _ReadWriteBarrier();

        const __m128& w = g->w.quad();

        _ReadWriteBarrier();

        g->w.assign(_mm_add_ps(g->w.quad(), w));

        }
    }
    __forceinline void query(unsigned codeBits,const PlaneView& view,int output,int properties) {
        const QueryCode* code=reinterpret_cast<const QueryCode*>(codeBits);
        const unsigned char* pc=code->program;
        partial=output;
        QueryState state;
        QueryBounds bounds;
        inverseScale=1.0f/code->origin(3);
        state.z=0; state.primitive=0; state.property=0; state.shift=16;
        state.x=0; state.y=0;
        bounds.minimum.setZero4();
        bounds.scale.setAll3(float(inverseScale*DAT_01091c00));
        prepare(view,codeBits);
        complete=properties;
        ProcessEntries_00e5e430(&state,pc,&bounds);
    }
};
// Creates a QueryMachine and calls its query method with codeBits, the plane view, output and properties.
// @fnv 0x00e5d360
// src: GUESS 0x00e5d360 (confidence: low)
void __cdecl Object_ProcessState_00e5d360(unsigned codeBits,const PlaneView& input,int output,int properties) {
    QueryMachine machine;
    machine.query(codeBits,input,output,properties);
}

#include <xmmintrin.h>

#include <xmmintrin.h>
namespace fnv_00e5d710 {
// Exe 0x00e4b6e0 FUN_00e4b6e0: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" double DAT_01091c00;
extern "C" __m128 _mm_load_ss(const float*);
union __declspec(align(16)) QueryVector {
    __m128 quad;
    struct { float x, y, z, w; } components;
};
struct QueryCode {
    int unk00, unk04, unk08, unk0c;
    QueryVector offset;
    unsigned char* data;
};
struct QueryState {
    int primitiveOffset, properties, x, y, z, shift;
    QueryState() { x=0; y=0; z=0; primitiveOffset=0; properties=0; }
};
struct QueryBounds { QueryVector low, high; };
struct SphereQuery {
    void* hits;
    int unk04, unk08, unk0c;
    float inverseScale;
    int unk14, unk18, unk1c;
    void* volatile collector;
    int unk24, unk28, unk2c;
    QueryVector sphere;
    void ProcessEntries_00e5fb50(QueryState*, unsigned char*, QueryBounds*);
};
// Builds a SphereQuery from code and sphere, then calls FUN_00e5fb50 on it with a query state, code->data and bounds.
// @fnv 0x00e5d710
// src: GUESS 0x00e5d710 (confidence: medium)
void __cdecl Runtime_QueryMoppSphere(const QueryCode* __restrict code, const QueryVector* sphere, void* hits, void* collector)
{
    SphereQuery query;
    QueryBounds bounds;
    query.inverseScale = 1.0f / code->offset.components.w;
    query.hits = hits;
    unsigned char* __restrict data = code->data;
    __m128 offset = code->offset.quad;
    bounds.low.quad = _mm_setzero_ps();
    QueryState state;
    float scaled = (float)(query.inverseScale * DAT_01091c00);
    bounds.high.quad = _mm_set_ps1(scaled);
    __m128 delta = _mm_sub_ps(sphere->quad, offset);
    delta = _mm_add_ps(delta, delta);
    query.sphere.quad = _mm_shuffle_ps(delta, _mm_unpackhi_ps(delta, query.sphere.quad), 0xc4);
    query.sphere.components.w = sphere->components.w + sphere->components.w;
    query.collector = collector;
    state.shift = 16;
    query.ProcessEntries_00e5fb50(&state, data, &bounds);
}
}  // namespace fnv_00e5d710

struct V4Init_00e53160 {
    float x;
    float y;
    float z;
    float w;

    V4Init_00e53160* FUN_00e53160(float a, float b, float c, float d);
};

__declspec(noinline) V4Init_00e53160*
V4Init_00e53160::FUN_00e53160(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
    return this;
}

void __cdecl hkaNURBS_DersBasisFuns(
    int span, float u, int degree, int limit, float** knots, float* basis);

// Zeroes rows a2+1 through a6, then sets rows[0..limit] to sums of points weighted by basis values computed for u.
// @fnv 0x00e544c0
// src: HAVOK_LIB 0x00e544c0
void __cdecl hkaNURBS_CurveDerivs(
    int a1, int a2, float** knots, KnotVector** points, float u,
    int aiRowLimit, KnotVector* rows, int a8, float a9)
{
    float basis[4][4];

    int limit = aiRowLimit < a2 ? aiRowLimit : a2;

    for (int i = a2 + 1; i <= aiRowLimit; ++i) {
        V4Init_00e53160 zero;
        rows[i].FUN_00e53180(
            *(const KnotVector*)zero.FUN_00e53160(0.0f, 0.0f, 0.0f, 0.0f));
    }

    int span = FindFloatInterval(a1, a2, u, knots);
    hkaNURBS_DersBasisFuns(span, u, a2, limit, knots, (float*)basis);

    for (int i = 0; i <= limit; ++i) {
        V4Init_00e53160 zero;
        rows[i].FUN_00e53180(
            *(const KnotVector*)zero.FUN_00e53160(0.0f, 0.0f, 0.0f, 0.0f));

        if (a2 >= 0) {
            for (int j = 0; j <= a2; ++j) {
                rows[i].ComputeValue_00e531a0(
                    Object_ScaleCopy_Thunk(basis[i][j], (*points)[span - a2 + j]));
            }
        }
    }
}

struct S00e49e00_Slot {};
inline void* operator new(size_t, void* p, S00e49e00_Slot) { __assume(p != 0); return p; }
inline void operator delete(void*, void*, S00e49e00_Slot) {}

class hkMemoryAllocator;
namespace se49e00 {


struct AllocatorHolder {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    hkMemoryAllocator* m_pHeapAllocator;
};

AllocatorHolder* hkMemoryRouter_getInstance();
void ResizeAudioStream(hkMemoryAllocator* pkAllocator, void* apvArray, unsigned int uiStride);
void __fastcall FUN_00c90510(void* pvObject);

template <class T> struct ObjectArray {
    T* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;

    void PushBack(const T& kElement)
    {
        AllocatorHolder* pkHolder = hkMemoryRouter_getInstance();
        if (m_uiLogicalSize == (m_iCapacityAndFlags & 0x3fffffff))
            ResizeAudioStream(pkHolder->m_pHeapAllocator, this, sizeof(T));
        new (&m_pData[m_uiLogicalSize], S00e49e00_Slot()) T(kElement);
        m_uiLogicalSize++;
    }
};

struct Child;

struct Container {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    ObjectArray<Child*> m_kChildList;

    void hkpCollisionFilterList_addCollisionFilter(Child* pkChild);
};

// Calls FUN_00c90510 on pkChild, then appends pkChild to m_kChildList.
// @fnv 0x00e49e00
// src: XBOX_PDB 0x00e49e00
void Container::hkpCollisionFilterList_addCollisionFilter(Child* pkChild)
{
    FUN_00c90510(pkChild);
    m_kChildList.PushBack(pkChild);
}

}

// Computes the dot product of two Vec4f vectors by summing the products of their corresponding components.
// @fnv 0x00e535a0
// src: HAVOK_LIB 0x00e535a0
float hkaNURBS_Point_Dot(const Vec4f* left, const Vec4f* right)
{
    return (*left)[1] * (*right)[1]
         + (*left)[0] * (*right)[0]
         + (*left)[2] * (*right)[2]
         + (*left)[3] * (*right)[3];
}

namespace e54 {
int __cdecl FindFloatInterval(int a, int degree, float u, float** knots);
void __cdecl ComputeBasisFunctions(int span, float u, int degree, float** knots, float* basis);
// Finds the span for u, computes the basis functions, and accumulates the weighted control points into a KnotVector result.
// @fnv 0x00e54630
// src: HAVOK_LIB 0x00e54630
KnotVector hkaNURBS_CurvePoint(int a, int degree, float** knots, KnotVector** points, float u)
{
    int span = FindFloatInterval(a, degree, u, knots);
    float basis[4];
    ComputeBasisFunctions(span, u, degree, knots, basis);
    KnotVector result = ::Object_ScaleCopy_Thunk(basis[0], (*points)[span - degree]);
    for (int i = 1; i <= degree; i++)
    {
        result.ComputeValue_00e531a0(::Object_ScaleCopy_Thunk(basis[i], (*points)[span - degree + i]));
    }
    return result;
}
}


template <>
void hkArrayBase<E4AAA0Element>::_spliceInto(hkMemoryAllocator& kSharedAlloc, int index, int aiNumDelete, const E4AAA0Element* apElements, int aiNumInsert)
{
    E4AAA0Allocator& alloc = reinterpret_cast<E4AAA0Allocator&>(kSharedAlloc);
    int iNewCount = aiNumInsert + m_iElementCount - aiNumDelete;
    int numtomove = m_iElementCount - index - aiNumDelete;
    E4AAA0Array_reserve(*this, alloc, iNewCount);
    hkMemUtil_memMove(m_data + index + aiNumInsert, m_data + index + aiNumDelete, numtomove * sizeof(E4AAA0Element));
    E4AAA0Element* dst = m_data + index;
    for (int i = 0; i < aiNumInsert; ++i)
        dst[i] = apElements[i];
    m_iElementCount = iNewCount;
}