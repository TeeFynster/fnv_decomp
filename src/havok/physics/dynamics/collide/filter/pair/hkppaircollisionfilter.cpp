#define FNV64_HKENUM_INLINE_BODIES
// Keep this unit's original intrinsic lane representation for matching code generation.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00def570 FUN_00def570: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
extern "C"
{
    extern LocalM128 _mm_add_ss(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_add_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_sub_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_mul_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_shuffle_ps(LocalM128 _A, LocalM128 _B, unsigned int _Imm8);
    extern void _mm_store_ss(float* _V, LocalM128 _A);
};
#endif

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkHalf.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

inline hkMemoryAllocator& GetStreamAllocator(hkMemoryRouter& stream)
{
    return *stream.m_heap;
}

// src/havok/physics/dynamics/collide/filter/pair/hkppaircollisionfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/filter/pair/hkppaircollisionfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern hkMemoryRouter* hkMemoryRouter_getInstance();

struct HashCls
{
    __int64 hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(unsigned __int64 key, int a2, int a3);
    void InsertKeyValue(hkMemoryAllocator& f0, __int64 m, __int64 n);

    int InsertPair(int p1, int p2);
};

// Orders the two ints into a 64-bit key, inserts it into the hash at this+0x30 with a counter value, and returns that counter.
// @fnv 0x00def2b0
int HashCls::InsertPair(int aiFirst, int aiSecond)
{
    __int64 m;
    if ((unsigned __int64)(__int64)aiFirst < (unsigned __int64)(__int64)aiSecond)
        m = (__int64)aiFirst * 4294967296LL + (__int64)aiSecond;
    else
        m = (__int64)aiSecond * 4294967296LL + (__int64)aiFirst;

    HashCls* pHash = (HashCls*)((char*)this + 0x30);
    __int64 n = pHash->hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(m, 0, 0) + 1;
    hkMemoryAllocator& f0 = *hkMemoryRouter_getInstance()->m_heap;
    pHash->InsertKeyValue(f0, m, n);
    return (int)n;
}

namespace fnv_00def350 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct DEF350PointerMap
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    DEF350PointerMap() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {
        reserve(GetStreamAllocator(hkMemoryRouter_getInstance()), 0);
    }

    void reserve(hkMemoryAllocator& alloc, int numElements);
};

struct DEF350Base
{
    DEF350Base();

    virtual void vfunc00();
    virtual void vfunc04();

    int unk04;
};

struct __declspec(novtable) DEF350ListenerA
{
    virtual void vfunc00();
    virtual void vfunc04();
};

struct __declspec(novtable) DEF350ListenerB
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
};

struct __declspec(novtable) DEF350ListenerC
{
    virtual void vfunc00();
    virtual void vfunc04();
};

struct __declspec(novtable) DEF350ListenerD
{
    virtual void vfunc00();
    virtual void vfunc04();
};

struct FUN_00def350 : DEF350Base, DEF350ListenerA, DEF350ListenerB, DEF350ListenerC, DEF350ListenerD
{
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    DEF350PointerMap m_map;
    hkReferencedObject* m_object;

    FUN_00def350(hkReferencedObject* object);
};

// @fnv 0x00def350
FUN_00def350::FUN_00def350(hkReferencedObject* object) : m_object(object)
{
    unk20 = 5;
    if (object)
        object->addReference();
}
}  // namespace fnv_00def350

struct Owner;

struct Inner
{
    unsigned char unk00[8];
    int threshold;
    int hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(unsigned __int64 value);
};

struct Owner
{
    unsigned char unk00[0x30];
    Inner inner;
    volatile unsigned char* CheckPairAgainstThreshold(volatile unsigned char* result, int first, int second);
};

// Writes 1 to result if either argument is zero or the combined value exceeds inner.threshold, otherwise writes 0.
// @fnv 0x00def3d0
volatile unsigned char* Owner::CheckPairAgainstThreshold(volatile unsigned char* result, int first, int second)
{
    if (first == 0 || second == 0)
    {
        *result = 1;
        return result;
    }

    unsigned __int64 ullFirst = (unsigned __int64)(__int64)first;
    unsigned __int64 ullSecond = (unsigned __int64)(__int64)second;
    unsigned __int64 value;
    if (ullFirst < ullSecond)
        value = ullFirst * 0x100000000LL + ullSecond;
    else
        value = ullSecond * 0x100000000LL + ullFirst;

    Inner* pInner = &inner;
    int actual = pInner->hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(value);
    if (actual > pInner->threshold)
    {
        *result = 1;
        return result;
    }
    *result = 0;
    return result;
}

struct Converted;

struct Operand
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_cByteAtOffset10;
    char pad11;
    char pad12;
    char pad13;
    char pad14;
    char pad15;
    char pad16;
    char pad17;
    char m_cType;
};

struct CheckResult
{
    char m_cStatus;
};

struct CheckSubObject
{
    virtual void v00();
    virtual CheckResult* Check(void* apScratch, Operand* apFirst, Operand* apSecond);
};

struct CheckHolder
{
    int unk00;
    int unk04;
    CheckSubObject m_kSub;
};

struct ResultWriter
{
    void CheckPairAgainstThreshold(char* apResult, Converted* apFirst, Converted* apSecond);
};

struct FUN_00def450_cls
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
    CheckHolder* m_pHolder;

    char* CheckAndWriteResult(char* apResult, Operand* apFirst, Operand* apSecond);
};

// @fnv 0x00def450
char* FUN_00def450_cls::CheckAndWriteResult(char* apResult, Operand* apFirst, Operand* apSecond)
{
    if (m_pHolder != 0)
    {
        int iScratch;
        CheckResult* pCheck = m_pHolder->m_kSub.Check(&iScratch, apFirst, apSecond);
        if (pCheck->m_cStatus == 0)
        {
            *apResult = 0;
            return apResult;
        }
    }

    Converted* pFirst = (apFirst->m_cType == 1) ? (Converted*)((char*)apFirst + apFirst->m_cByteAtOffset10) : 0;
    Converted* pSecond = (apSecond->m_cType == 1) ? (Converted*)((char*)apSecond + apSecond->m_cByteAtOffset10) : 0;

    ResultWriter* pWriter = (ResultWriter*)((char*)this - 8);
    pWriter->CheckPairAgainstThreshold(apResult, pFirst, pSecond);
    return apResult;
}

struct HolderCheckResult
{
    char m_cValue;
    HolderCheckResult(bool abValue) : m_cValue(abValue)
    {}
};
struct HolderCheckSub
{
    virtual HolderCheckResult Check(int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};
struct CheckHolder070
{
    int unk00;
    int unk04;
    int unk08;
    HolderCheckSub m_kSub;
};
struct FUN_00def070_cls
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
    CheckHolder070* m_pHolder;

    HolderCheckResult hkpPairCollisionFilter_isCollisionEnabled_00def070(int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

// Returns true if m_pHolder is null or its sub-object's Check returns a nonzero value.
// @fnv 0x00def070
// src: HAVOK_LIB 0x00def070
HolderCheckResult FUN_00def070_cls::hkpPairCollisionFilter_isCollisionEnabled_00def070(int aiArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6, int aiArg7,
                                                 int aiArg8)
{
    return HolderCheckResult(!m_pHolder ||
                             m_pHolder->m_kSub.Check(aiArg2, aiArg3, aiArg4, aiArg5, aiArg6, aiArg7, aiArg8).m_cValue);
}

struct DfResult
{
    char m_cStatus;
};

struct DfSubObject
{
    virtual DfResult* Check(DfResult* apScratch, int a2, int a3, int a4, int a5);
};

struct DfHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DfSubObject m_kSub;
};

class DfCls
{
  public:
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
    DfHolder* m_2c;

    unsigned char* CheckSubStatus(unsigned char* apOut, int a2, int a3, int a4, int a5);
};

// Writes to apOut whether m_2c is null or its sub-object's Check returns a non-zero status.
// @fnv 0x00def0d0
unsigned char* DfCls::CheckSubStatus(unsigned char* apOut, int a2, int a3, int a4, int a5)
{
    DfResult res;
    *apOut = (m_2c == 0 || m_2c->m_kSub.Check(&res, a2, a3, a4, a5)->m_cStatus != 0);
    return apOut;
}

// Collision filter forwarder: enabled unless the owner's filter says otherwise.

struct DEF120Bool
{
    char m_cBooleanValue;
    DEF120Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class DEF120Filter
{
  public:
    virtual void Unk_00();
    virtual DEF120Bool IsCollisionEnabled(const void* pvA, const void* pvB) const;
};

struct DEF120Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    DEF120Filter m_kFilter;
};

class DEF120Wrapper
{
  public:
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
    DEF120Owner* m_pkOwnerManager;

    DEF120Bool hkpPairCollisionFilter_isCollisionEnabled_00def120(const void* pvA, const void* pvB) const;
};

// @fnv 0x00def120
// src: HAVOK_LIB 0x00def120
DEF120Bool DEF120Wrapper::hkpPairCollisionFilter_isCollisionEnabled_00def120(const void* pvA, const void* pvB) const
{
    return !m_pkOwnerManager || m_pkOwnerManager->m_kFilter.IsCollisionEnabled(pvA, pvB);
}

namespace fnvc_adapt {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
}

typedef unsigned __int64 DEF1E0Uint64;

struct DEF1E0PairMap
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    DEF1E0Uint64 FindValueForKey(DEF1E0Uint64 key, DEF1E0Uint64 def) const;
    int insert(hkMemoryAllocator& alloc, DEF1E0Uint64 key, DEF1E0Uint64 val);
    void remove(DEF1E0Uint64 key);
};

struct DEF1E0PairCounter
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
    DEF1E0PairMap m_pairCounts;

    int DecrementPairCount(int idA, int idB);
};

// Looks up the count for the ordered pair of idA and idB, decrements it, updates or removes the map entry, and returns the new count.
// @fnv 0x00def1e0
int DEF1E0PairCounter::DecrementPairCount(int idA, int idB)
{
    DEF1E0Uint64 a = idA;
    DEF1E0Uint64 b = idB;
    DEF1E0Uint64 key = (a < b) ? a * 0x100000000ULL + b : b * 0x100000000ULL + a;
    DEF1E0PairMap& map = m_pairCounts;
    DEF1E0Uint64 count = map.FindValueForKey(key, 0);
    if (count == 0)
        return 0;
    count--;
    if (count > 0)
        map.insert(GetStreamAllocator(fnvc_adapt::hkMemoryRouter_getInstance()), key, count);
    else
        map.remove(key);
    return (int)count;
}


class hkBase0DEF0
{
  public:
    virtual ~hkBase0DEF0();
    int unk04[2];
};

class hkFilterDEF0
{
  public:
    virtual ~hkFilterDEF0();
    virtual hkBool IsCollisionEnabled(const void* a, const void* b, const void* c, const void* d,
                                          const void* e) const;
};

class hkFilterImplDEF0 : public hkBase0DEF0, public hkFilterDEF0
{
};

class hkListDEF0
{
  public:
    int unk00[12];
    hkFilterImplDEF0* m_iFilter;

    hkBool hkpPairCollisionFilter_isCollisionEnabled(const void* a, const void* b, const void* c, const void* d, const void* e) const;
};

// Returns true if m_iFilter is null or if m_iFilter->IsCollisionEnabled returns true for the given arguments.
// @fnv 0x00def020
// src: HAVOK_LIB 0x00def020
hkBool hkListDEF0::hkpPairCollisionFilter_isCollisionEnabled(const void* a, const void* b, const void* c, const void* d, const void* e) const
{
    return !m_iFilter || m_iFilter->IsCollisionEnabled(a, b, c, d, e);
}

// sub ecx,8; jmp target == MSVC adjustor thunk for a virtual that Derived overrides
// through its second base. PrimaryBase is vptr + one int (8 bytes).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00def4c0();
    int unk04;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00def4c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00def4c0
// src: GUESS 0x00def4c0 (confidence: low)
    virtual void AdjustThisAndForward_00def4c0();
};

Derived::Derived()
{}

struct DEF4D0Primary
{
    virtual void vfunc00();
    virtual void FUN_00def4d0();

    int unk04;
    int unk08;
};

struct DEF4D0Secondary
{
    virtual void FUN_00def4d0();
};

struct DEF4D0Object : DEF4D0Primary, DEF4D0Secondary
{
    DEF4D0Object();

// @fnv 0x00def4d0
    virtual void FUN_00def4d0();
};

DEF4D0Object::DEF4D0Object()
{}

struct DEF4E0Primary
{
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00def4e0();

    int unk04;
    int unk08;
    int unk0C;
};

struct DEF4E0Secondary
{
    virtual void AdjustThisAndForward_00def4e0();
};

struct DEF4E0Object : DEF4E0Primary, DEF4E0Secondary
{
    DEF4E0Object();

// @fnv 0x00def4e0
// src: GUESS 0x00def4e0 (confidence: low)
    virtual void AdjustThisAndForward_00def4e0();
};

DEF4E0Object::DEF4E0Object()
{}

struct DEF4F0Primary
{
    virtual void unk00();
    virtual void FUN_00def4f0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct DEF4F0Secondary
{
    virtual void FUN_00def4f0();
};

struct DEF4F0Object : DEF4F0Primary, DEF4F0Secondary
{
    DEF4F0Object();

    virtual void unk00();
// @fnv 0x00def4f0
    virtual void FUN_00def4f0();
};

DEF4F0Object::DEF4F0Object()
{}

namespace fnv_00def160 {
extern int DAT_010da0c8;
extern int DAT_010da0bc;
extern int DAT_010da0a8;
extern int DAT_010da09c;
extern int DAT_010da090;
extern int DAT_010c3b8c;
extern int DAT_010c3bac;
extern int DAT_010c3b98;
extern int DAT_010c3b80;
extern int DAT_0102e388;


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00def160_Sub
{
    int unk00;
    int unk04;
    int unk08;

    void hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_clearAndDeallocate(void* pAllocator);
    void Object_DoNothing();
};

class FUN_00def160_cls
{
  public:
    void* m_vp00;
    int unk04;
    void* m_vp08;
    void* m_vp0C;
    void* m_vp10;
    void* m_vp14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    FUN_00def160_Sub m_sub;
    hkReferencedObject* m_pReference;

    void UpdateFields_00def160();
};

// @fnv 0x00def160
// src: GUESS 0x00def160 (confidence: low)
void FUN_00def160_cls::UpdateFields_00def160()
{
    hkMemoryRouter* pHolder;
    FUN_00def160_Sub* pSub;

    m_vp00 = (void*)&DAT_010da0c8;
    m_vp08 = (void*)&DAT_010da0bc;
    m_vp0C = (void*)&DAT_010da0a8;
    m_vp10 = (void*)&DAT_010da09c;
    m_vp14 = (void*)&DAT_010da090;

    if (m_pReference != 0)
    {
        m_pReference->removeReference();
    }

    pSub = &m_sub;
    pHolder = hkMemoryRouter_getInstance();
    pSub->hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_clearAndDeallocate(pHolder->m_heap);
    pSub->Object_DoNothing();

    m_vp14 = (void*)&DAT_010c3b8c;
    m_vp10 = (void*)&DAT_010c3bac;
    m_vp0C = (void*)&DAT_010c3b98;
    m_vp08 = (void*)&DAT_010c3b80;
    m_vp00 = (void*)&DAT_0102e388;
}
}  // namespace fnv_00def160

namespace fnv_00def500 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void UpdateFields_00def160();
    CpuObject* hkpPairCollisionFilter_Destroy(unsigned int flags);
};
// Calls FUN_00def160, and if the low bit of flags is set, releases this through the memory router allocator, then returns this.
// @fnv 0x00def500
// src: COMMUNITY 0x00def500
CpuObject* CpuObject::hkpPairCollisionFilter_Destroy(unsigned int flags)
{
    UpdateFields_00def160();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        holder->m_heap->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00def500

typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef signed long __w64 hkLong;
typedef unsigned __w64 hk_size_t;
template <typename TYPE> __forceinline TYPE* __cdecl hkAddByteOffset(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}
template <typename TYPE> __forceinline const TYPE* __cdecl hkAddByteOffsetConst(const TYPE* base, hkLong offset)
{
    return reinterpret_cast<const TYPE*>(reinterpret_cast<const char*>(base) + offset);
}

#include "../../../../../../../include/hkEnum.h"
using ::hkEnum;
typedef LocalM128 hkQuadReal;
typedef const hkVector4& hkVector4Parameter;

inline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x)
{}

inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
extern "C"
{
    double __cdecl fabs([SA_Pre(Null = SA_No)][SA_Pre(Deref = 1, Valid = SA_Yes, Access = SA_Read)] double _X);
    inline float fabsf([SA_Pre(Null = SA_No)][SA_Pre(Deref = 1, Valid = SA_Yes, Access = SA_Read)] float _X)
    {
        return ((float)fabs((double)_X));
    }
}
namespace MathUtilities {
inline hkReal __cdecl fabs(hkReal r)
{
    return ::fabsf(r);
}
template <typename T> inline T __cdecl max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> inline T __cdecl min2(T x, T y)
{
    return x < y ? x : y;
}
}

__forceinline hkMatrix3::hkMatrix3()
{}

__forceinline hkRotation::hkRotation()
{}

// The approved hkVector4 header does not yet declare the matrix rotation helper.
class MatrixRotatedVector : public hkVector4
{
  public:
    void SetRotatedVector(const hkMatrix3& matrix, const hkVector4& vector);
};

__forceinline hkSimdReal hkVector4::horizontalAdd3() const
{
    hkQuadReal xySum = _mm_add_ss(
        _mm_shuffle_ps(m_vComponents, m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), m_vComponents);
    return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))),
                      xySum);
}
__forceinline hkReal& hkVector4::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
__forceinline const hkReal& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
class QuantizedBoundsData
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = GetStreamAllocator(hkMemoryRouter::getInstance()).blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    enum RigidBodyType
    {
        HK_RIGID_BODY,
        HK_KEYFRAMED_RIGID_BODY,
        HK_NO_GRAVITY_RIGID_BODY,
        HK_END
    };
    hkEnum<RigidBodyType, hkUint8> m_type;
    hkReal m_fGravityFactor;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4& getCenterOfMassInWorld()
    {
        return getScratch0();
    }
    hkRotation& getCoreFromWorldMatrix()
    {
        return m_kCoreFromWorldMatrix;
    }
    hkVector4& getSumLinearVel()
    {
        return getScratch0();
    }
    const hkVector4& getSumLinearVel() const
    {
        return getScratch0();
    }
    const hkVector4& getSumAngularVel() const
    {
        return getScratch1();
    }
    hkVector4& getScratch0()
    {
        return m_vCenterOfMass;
    }
    hkVector4& getScratch1()
    {
        return m_kCoreFromWorldMatrix.m_kColumn0;
    }
    const hkVector4& getScratch0() const
    {
        return m_vCenterOfMass;
    }
    const hkVector4& getScratch1() const
    {
        return m_kCoreFromWorldMatrix.m_kColumn0;
    }

  public:
    hkVector4 m_vCenterOfMass;
    hkRotation m_kCoreFromWorldMatrix;

  public:
    __forceinline void setFixed()
    {
        m_type = QuantizedBoundsData::HK_KEYFRAMED_RIGID_BODY;
        m_fGravityFactor = 0.0f;
        this->m_vInverseInertiaAndMass.setZero4();
        this->m_vLinearVelocity.setZero4();
        this->m_vAngularVelocity.setZero4();
        this->getCenterOfMassInWorld().setZero4();
        reinterpret_cast<hkMatrix3&>(this->getCoreFromWorldMatrix()).setZero();
    }
};
struct ConstraintSolverInfo
{
    enum DeactivationClass
    {
        DEACTIVATION_CLASS_INVALID,
        DEACTIVATION_CLASS_OFF,
        DEACTIVATION_CLASS_LOW,
        DEACTIVATION_CLASS_MEDIUM,
        DEACTIVATION_CLASS_HIGH,
        DEACTIVATION_CLASS_AGGRESSIVE,
        DEACTIVATION_CLASSES_END
    };
    struct FloatAndHalfRecord
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = GetStreamAllocator(hkMemoryRouter::getInstance()).blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                GetStreamAllocator(hkMemoryRouter::getInstance()).blockFree(
                    p, sizeof(ConstraintSolverInfo::FloatAndHalfRecord));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        float m_fFirstFloat;
        float m_fSecondFloat;
        float m_fThirdValue;
        float m_fFourthFloat;
        float m_afFloatPair[2];
        hkHalf m_ahHalfPair[2];
    };
    __declspec(align(16)) float m_iCachedVertexCount;
    hkVector4 m_kGravity;
    hkVector4 m_kSecondSolverVector;
    hkVector4 m_kTimeStep;
    hkVector4 GetTimeStepFactor;
    float m_fFirstTrailingParameter;
    float m_fSecondTrailingParameter;
    float m_fThirdTrailingParameter;
    float m_fFourthTrailingParameter;
    float m_fContactRestingVelocity;
    FloatAndHalfRecord m_kDeactivationClassInfo[DEACTIVATION_CLASSES_END];
    float m_fTimeStep;
    float m_fInverseDeltaTime;
    int m_iToiEventCount;
};
struct VelocityConstraintMotor
{
    hkReal m_fMinimumForce;
    hkReal m_fMaximumForce;
    hkReal m_fVelocity;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
};
struct AngularMotorState
{
    typedef hkUint8 Status;
    enum Mask
    {
        ANGULAR_1ST = 0x03,
        ANGULAR_2ND = 0x0c,
        ANGULAR_3RD = 0x30,
    };
    Status m_ucReferenceTimeSteps;
    inline int GetReferenceTimeStep(int idx) const
    {
        ;
        return (m_ucReferenceTimeSteps >> (2 * idx)) & ANGULAR_1ST;
    }
    VelocityConstraintMotor m_kAngularMotors[3];
};
struct ConstraintInstanceBuffer
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = GetStreamAllocator(hkMemoryRouter::getInstance()).blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    enum
    {
        CAPACITY = 128
    };
    void reset()
    {
        m_uiConstraintCount = 0;
    }

  public:
    hkUint32 m_uiConstraintCount;
    class hkpConstraintInstance* m_ppConstraints[CAPACITY];
};
class ContactImpulseInfo
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = GetStreamAllocator(hkMemoryRouter::getInstance()).blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkReal m_fAccumulatedImpulse;
    hkReal m_fImpulseLimit;
};
class hkSpuDmaSparseWriter;
struct FloatRecord
{
    union
    {
        hkReal m_fAccumulatedImpulse;
        hkReal m_fSecondUnionFloat;
        hkReal m_fAccumulatedMotorRhs;
    };
};
struct ConstraintChainBreachInfo
{
    hkUint16 m_type;
    hkUint16 m_usSecondaryField;
    hkpConstraintInstance* m_pConstraintChainInstance;
    ContactImpulseInfo* m_solverResult;
};
struct ConstraintBreachInfoBlock
{
    int m_iBreachCount;
    ConstraintBreachInfoBlock* m_next;
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    inline ConstraintChainBreachInfo& getElem(int index)
    {
        return *reinterpret_cast<ConstraintChainBreachInfo*>(hkAddByteOffset(this, 16 + index * 16));
    }
};
class ConstraintJacobian
{
  public:
    hkVector4 m_kLinearJacobian;
    hkVector4 m_kAngularVelocity[2];
    inline void setRHS(hkReal v)
    {
        m_kLinearJacobian(3) = v;
    }
    inline const hkReal& getRHS() const
    {
        return m_kLinearJacobian(3);
    }
    inline hkReal getUserValue() const
    {
        return m_kAngularVelocity[1](3);
    }
};
class AngularJacobianElement
{
  public:
    hkVector4 m_kAngularVelocity[2];
    inline hkReal getInvJacDiag() const
    {
        return m_kAngularVelocity[0](3);
    }
    inline void setAngularRhs(hkReal v)
    {
        m_kAngularVelocity[1](3) = v;
    }
    inline hkReal getAngularRhs() const
    {
        return m_kAngularVelocity[1](3);
    }
};
class JacobianElement
{
  public:
    hkVector4 m_kTranslationalVelocity[2];
    hkVector4 m_kAngularVelocity[2];
    inline hkReal getRHS() const
    {
        return m_kTranslationalVelocity[0](3);
    }
};
class SolverRecordPair
{
  public:
    ConstraintJacobian m_kFirstFrictionJacobian;
    ConstraintJacobian m_kSecondFrictionJacobian;
};
class FrictionJacobianTriple
{
  public:
    ConstraintJacobian m_kFirstFrictionJacobian;
    ConstraintJacobian m_kSecondFrictionJacobian;
    AngularJacobianElement m_kAngularJacobian;
};
struct QuantizedBoundsDataOffset
{
    hkUint32 m_offset;
    inline const QuantizedBoundsData& getAccumulator(const QuantizedBoundsData* accumulatorsBase) const
    {
        return *hkAddByteOffsetConst(accumulatorsBase, m_offset);
    }
};
class SolverSchemaHeader
{
  public:
    enum SolverSchemaType
    {
        SCHEMA_TYPE_END,
        SCHEMA_TYPE_HEADER,
        SCHEMA_TYPE_GOTO,
        SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER,
        SCHEMA_TYPE_SIMPLE_BEGIN,
        SCHEMA_TYPE_1D_BILATERAL,
        SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT,
        SCHEMA_TYPE_1D_BILATERAL_USER_TAU,
        SCHEMA_TYPE_1D_LINEAR_LIMITS,
        SCHEMA_TYPE_1D_FRICTION,
        SCHEMA_TYPE_1D_LINEAR_MOTOR,
        SCHEMA_TYPE_1D_PULLEY,
        SCHEMA_TYPE_1D_ANGULAR,
        SCHEMA_TYPE_1D_ANGULAR_LIMITS,
        SCHEMA_TYPE_1D_ANGULAR_FRICTION,
        SCHEMA_TYPE_1D_ANGULAR_MOTOR,
        SCHEMA_TYPE_SINGLE_CONTACT,
        SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK,
        SCHEMA_TYPE_SINGLE_LIMIT_CONTACT,
        SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK,
        SCHEMA_TYPE_PAIR_CONTACT,
        SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK,
        SCHEMA_TYPE_2D_FRICTION,
        SCHEMA_TYPE_3D_FRICTION,
        SCHEMA_TYPE_2D_ROLLING_FRICTION,
        SCHEMA_TYPE_SET_MASS,
        SCHEMA_TYPE_ADD_VELOCITY,
        SCHEMA_TYPE_SET_CENTER_OF_MASS,
        SCHEMA_TYPE_SIMPLE_END,
        SCHEMA_TYPE_STIFF_SPRING_CHAIN,
        SCHEMA_TYPE_BALL_SOCKET_CHAIN,
        SCHEMA_TYPE_POWERED_CHAIN,
        SCHEMA_TYPE_MAX
    };
    static inline hkEnum<SolverSchemaType, hkInt8> getType(const SolverSchemaHeader* schema)
    {
        return *reinterpret_cast<const hkEnum<SolverSchemaType, hkInt8>*>(hkAddByteOffsetConst(schema, 0));
    }
    static inline int GetLogicalSize(const SolverSchemaHeader* schema)
    {
        const hkEnum<SolverSchemaType, hkInt8> type = getType(schema);
        const int size = ms_aucLogicalSchemaSizes[type];
        return size;
    }
    static inline int getNumSolverElemTemps(const SolverSchemaHeader* schema)
    {
        const hkEnum<SolverSchemaType, hkInt8> type = getType(schema);
        const int numSolverElemTemps = ms_aiSolverResultTempCounts[type];
        return numSolverElemTemps;
    }
    static hkUint8 ms_aucLogicalSchemaSizes[];
    static hkUint8 ms_aiSolverResultTempCounts[];
};
class ConstraintHeaderSchema : public SolverSchemaHeader
{
  public:
    hkUint8 m_ucHeaderByte;
    hkUint8 m_ucSecondHeaderByte;
    hkUint16 m_usHeaderWord;
    hkUint16 m_usBodyAAccumulatorIndex;
    hkUint16 m_usBodyBAccumulatorIndex;
    ContactImpulseInfo* m_solverResultInMainMemory;
    hkpConstraintInstance* m_pConstraintChainInstance;
    inline const QuantizedBoundsData* getBodyA(const QuantizedBoundsData* accumulatorBuffer) const
    {
        return accumulatorBuffer + m_usBodyAAccumulatorIndex;
    }
    inline const QuantizedBoundsData* getBodyB(const QuantizedBoundsData* accumulatorBuffer) const
    {
        return accumulatorBuffer + m_usBodyBAccumulatorIndex;
    }
};
class SchemaJump : public SolverSchemaHeader
{
  public:
    hkUint32 m_ucHeaderByte;
    hkUint32 m_offset;
    hkUint32 m_padding1a;
    hkUint32 m_padding1b;
};
class ShiftSolverResultsPointerSchema : public SolverSchemaHeader
{
  public:
    hkUint32 m_uiSolverResultPointerOffset;
    hkUint8 m_ucSolverResultCount;
    hkUint32 m_padding2a;
    hkUint32 m_padding2b;
    inline int getNumSolverResults() const
    {
        return m_ucSolverResultCount;
    }
};
class JacobianPair : public SolverSchemaHeader
{
  public:
    SolverRecordPair m_pJacobian;
    hkReal m_fOffDiagonal;
    hkReal m_paddinga;
    hkReal m_paddingb;
    hkReal m_paddingc;
};
class JacobianPointerSchema : public SolverSchemaHeader
{
  public:
    ConstraintJacobian m_pJacobian;
};
class JacobianDataHolder : public SolverSchemaHeader
{
  public:
    ConstraintJacobian m_pJacobian;
};
class LinearSoftConstraintAtom : public SolverSchemaHeader
{
  public:
    ConstraintJacobian m_pJacobian;
    hkReal m_fTau;
    hkReal m_paddinga;
    hkReal m_paddingb;
    hkReal m_paddingc;
};
class LinearDistanceLimitAtom : public SolverSchemaHeader
{
  public:
    ConstraintJacobian m_pJacobian;
    hkReal m_paddinga;
    hkReal m_paddingb;
    hkReal m_paddingc;
    hkReal m_paddingd;
};
class MotorSolverSchema : public SolverSchemaHeader
{
  public:
    ConstraintJacobian m_pJacobian;
    VelocityConstraintMotor m_kMotorInfo;
    hkReal m_paddinga;
    hkReal m_paddingb;
    hkReal m_paddingc;
};
class FrictionImpulseLimitAtom : public SolverSchemaHeader
{
  public:
    ConstraintJacobian m_pJacobian;
    hkReal m_usFlags;
    hkReal m_paddinga;
    hkReal m_paddingb;
    hkReal m_paddingc;
};
class JacobianHolder : public SolverSchemaHeader
{
  public:
    AngularJacobianElement m_pJacobian;
};
class AngularLimitJacobian : public SolverSchemaHeader
{
  public:
    AngularJacobianElement m_pJacobian;
    hkReal m_paddinga;
    hkReal m_paddingb;
    hkReal m_paddingc;
    hkReal m_paddingd;
};
class MotorInfoRecord : public SolverSchemaHeader
{
  public:
    AngularJacobianElement m_pJacobian;
    VelocityConstraintMotor m_kMotorInfo;
    hkReal m_paddinga;
    hkReal m_paddingb;
    hkReal m_paddingc;
};
class FrictionImpulseLimitedJacobian : public SolverSchemaHeader
{
  public:
    AngularJacobianElement m_pJacobian;
    hkReal m_usFlags;
    hkReal m_paddinga;
    hkReal m_paddingb;
    hkReal m_paddingc;
};
class SingleJacobianSchema : public SolverSchemaHeader
{
  public:
    JacobianElement m_pJacobian;
};
class TwoAxisFrictionInfo : public SolverSchemaHeader
{
  public:
    SolverRecordPair m_pJacobian;
    hkReal m_fOffDiagonal;
    hkReal m_usFlags;
    ContactImpulseInfo* m_pSolverResults;
    inline void unpackSolverResultsPtr(ContactImpulseInfo*& solverResults) const
    {
        solverResults = m_pSolverResults;
    }
};
class Friction3DSchema : public SolverSchemaHeader
{
  public:
    FrictionJacobianTriple m_pJacobian;
    hkReal m_fOffDiagonal;
    hkReal m_usFlags;
    hkReal m_fAngularImpulseFactor;
    ContactImpulseInfo* m_pSolverResults;
    inline void unpackSolverResultsPtr(ContactImpulseInfo*& solverResults) const
    {
        solverResults = m_pSolverResults;
    }
};
class Friction2DSchema : public SolverSchemaHeader
{
  public:
    AngularJacobianElement m_kFirstFrictionJacobian;
    AngularJacobianElement m_kSecondFrictionJacobian;
    hkReal m_usFlags;
    ContactImpulseInfo* m_pSolverResults;
    inline void unpackSolverResultsPtr(ContactImpulseInfo*& solverResults) const
    {
        solverResults = m_pSolverResults;
    }
};
class AddVelocitySchema : public SolverSchemaHeader
{
  public:
    hkVector4 m_vVelocityChange;
    int m_iBodyIndex;
    int m_pada;
    int m_padb;
    int m_padc;
};
class CenterOfMassShiftSchema : public SolverSchemaHeader
{
  public:
    hkMatrix3 m_kAngularToLinearVelocityMatrixA;
    hkMatrix3 m_kAngularToLinearVelocityMatrixB;
};
class SetInverseMassSchema : public SolverSchemaHeader
{
  public:
    hkVector4 m_vInverseMassA;
    hkVector4 m_vInverseMassB;
};
struct FloatTriple
{
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
};
struct Matrix3LowerDiagonalUpperFactors
{
    hkMatrix3 m_kPointA;
    hkMatrix3 m_kPointB;
    hkMatrix3 m_iThirdValue;
};
struct Vector4RowStorage
{
    hkVector4 m_rows[60];
};
struct NibbleVectorPair
{
    hkVector4 m_ucLowNibble;
    hkVector4 m_ucHighNibble;
};
class ConstraintSolverBuffer : public SolverSchemaHeader
{
  public:
    hkUint16 m_ucUnknownByte;
    hkUint16 m_iConstraintCount;
    hkUint32 m_iElementCount;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
    static inline ConstraintJacobian* getJacobians(SolverSchemaHeader* schema)
    {
        return reinterpret_cast<ConstraintJacobian*>(reinterpret_cast<ConstraintSolverBuffer*>(schema) + 1);
    }
    inline FloatTriple* getMatrixBuffer()
    {
        return reinterpret_cast<FloatTriple*>(getJacobians(this) + m_iConstraintCount);
    }
    inline hkReal* getTempBuffer()
    {
        return reinterpret_cast<hkReal*>(getMatrixBuffer() + m_iConstraintCount);
    }
    inline QuantizedBoundsDataOffset* getAccumulatorOffsetsBase()
    {
        return reinterpret_cast<QuantizedBoundsDataOffset*>(getTempBuffer() + m_iConstraintCount + 1);
    }
};
class BallSocketChainSchema : public SolverSchemaHeader
{
  public:
    hkUint16 m_ucUnknownByte;
    hkUint16 m_iConstraintCount;
    hkUint32 m_iElementCount;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
    static inline ConstraintJacobian* getJacobians(SolverSchemaHeader* schema)
    {
        return reinterpret_cast<ConstraintJacobian*>(reinterpret_cast<BallSocketChainSchema*>(schema) + 1);
    }
    inline Matrix3LowerDiagonalUpperFactors* getMatrixBuffer()
    {
        return reinterpret_cast<Matrix3LowerDiagonalUpperFactors*>(
            hkAddByteOffset(getJacobians(this), m_iConstraintCount * 3 * 0x30));
    }
    inline hkVector4* getTempBuffer()
    {
        return reinterpret_cast<hkVector4*>(hkAddByteOffset(getMatrixBuffer(), m_iConstraintCount * 0x90));
    }
    inline QuantizedBoundsDataOffset* getAccumulatorOffsetsBase()
    {
        return reinterpret_cast<QuantizedBoundsDataOffset*>(
            hkAddByteOffset(getTempBuffer(), (m_iConstraintCount + 1) << 4));
    }
};
class PoweredChainSolverSchema : public SolverSchemaHeader
{
  public:
    hkUint32 m_uiChainHeaderValue;
    hkUint16 m_iConstraintCount;
    hkUint8* m_pConstraintData;
    hkUint32 m_usHeaderWord;
    hkUint32 m_iElementCount;
    hkReal m_fPoweredChainParameter;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
    static inline ConstraintJacobian* getLinearJacobians(SolverSchemaHeader* schema)
    {
        return reinterpret_cast<ConstraintJacobian*>(reinterpret_cast<PoweredChainSolverSchema*>(schema) + 1);
    }
    static inline AngularJacobianElement* getAngularJacobians(SolverSchemaHeader* schema, int numConstraints)
    {
        return reinterpret_cast<AngularJacobianElement*>(getLinearJacobians(schema) + numConstraints * 3);
    }
    inline Vector4RowStorage* getMatrixBuffer()
    {
        return reinterpret_cast<Vector4RowStorage*>(
            hkAddByteOffset(getAngularJacobians(reinterpret_cast<SolverSchemaHeader*>(this), m_iConstraintCount),
                            m_iConstraintCount * 3 * 32));
    }
    inline NibbleVectorPair* getTempBuffer()
    {
        return reinterpret_cast<NibbleVectorPair*>(hkAddByteOffset(getMatrixBuffer(), m_iConstraintCount * 0x3c0));
    }
    inline NibbleVectorPair* getVelocityBuffer()
    {
        return getTempBuffer() + m_iConstraintCount + 1;
    }
    inline QuantizedBoundsDataOffset* getAccumulatorOffsetsBase()
    {
        return reinterpret_cast<QuantizedBoundsDataOffset*>(getVelocityBuffer() + m_iConstraintCount);
    }
    inline AngularMotorState* getChildConstraintStatusBase()
    {
        return reinterpret_cast<AngularMotorState*>(getAccumulatorOffsetsBase() + m_iConstraintCount + 1);
    }
};
namespace hkSolverExport {
__forceinline static hkReal integrateRhs(const QuantizedBoundsData& ma, const QuantizedBoundsData& mb,
                                         const ConstraintJacobian* jac, hkReal oldRhsFactor, hkReal sumVelocitiesFactor)
{
    const hkVector4* lva = &ma.getSumLinearVel();
    const hkVector4* lvb = &mb.getSumLinearVel();
    const hkVector4* ava = &ma.getSumAngularVel();
    const hkVector4* avb = &mb.getSumAngularVel();
    hkVector4 a;
    a.setMul4(*ava, jac->m_kAngularVelocity[0]);
    hkVector4 d;
    d.setSub4(*lva, *lvb);
    hkVector4 b;
    b.setMul4(*avb, jac->m_kAngularVelocity[1]);
    d.mul4(jac->m_kLinearJacobian);
    a.add4(b);
    a.add4(d);
    hkReal vel = a.horizontalAdd3();
    hkReal oldRhs = jac->m_kLinearJacobian(3) * oldRhsFactor;
    hkReal changeRhs = vel * sumVelocitiesFactor;
    return oldRhs - changeRhs;
}
__forceinline static void integrateRhsPair(const QuantizedBoundsData& ma, const QuantizedBoundsData& mb,
                                           const ConstraintJacobian* jac, hkReal oldRhsFactor,
                                           hkReal sumVelocitiesFactor, hkReal& rhsOut0, hkReal& rhsOut1)
{
    rhsOut0 = integrateRhs(ma, mb, jac, oldRhsFactor, sumVelocitiesFactor);
    rhsOut1 = integrateRhs(ma, mb, jac + 1, oldRhsFactor, sumVelocitiesFactor);
}
__forceinline static hkReal integrateRhs2Lin2Ang(const QuantizedBoundsData& ma, const QuantizedBoundsData& mb,
                                                 const JacobianElement* jac, hkReal oldRhsFactor,
                                                 hkReal sumVelocitiesFactor)
{
    const hkVector4* lva = &ma.getSumLinearVel();
    const hkVector4* lvb = &mb.getSumLinearVel();
    const hkVector4* ava = &ma.getSumAngularVel();
    const hkVector4* avb = &mb.getSumAngularVel();
    hkVector4 a;
    a.setMul4(*ava, jac->m_kAngularVelocity[0]);
    hkVector4 b;
    b.setMul4(*avb, jac->m_kAngularVelocity[1]);
    hkVector4 c;
    c.setMul4(*lva, jac->m_kTranslationalVelocity[0]);
    hkVector4 d;
    d.setMul4(*lvb, jac->m_kTranslationalVelocity[1]);
    a.add4(b);
    c.sub4(d);
    a.add4(c);
    hkReal vel = a.horizontalAdd3();
    hkReal oldRhs = jac->getRHS() * oldRhsFactor;
    hkReal changeRhs = vel * sumVelocitiesFactor;
    return oldRhs - changeRhs;
}
__forceinline static hkReal integrateAngularRhs(const QuantizedBoundsData& ma, const QuantizedBoundsData& mb,
                                                const AngularJacobianElement* jac, hkReal oldRhsFactor,
                                                hkReal sumVelocitiesFactor)
{
    const hkVector4* ava = &ma.getSumAngularVel();
    const hkVector4* avb = &mb.getSumAngularVel();
    hkVector4 a;
    a.setMul4(*ava, jac->m_kAngularVelocity[0]);
    hkVector4 b;
    b.setMul4(*avb, jac->m_kAngularVelocity[1]);
    a.add4(b);
    hkReal vel = a.horizontalAdd3();
    return jac->getAngularRhs() * oldRhsFactor - vel * sumVelocitiesFactor;
}
}
__forceinline static void hkSolverExportWriteRhs(hkReal rhs, ContactImpulseInfo* solverResultInMainMemory)
{
    solverResultInMainMemory->m_fImpulseLimit = rhs;
}
__forceinline static void hkSolverExportWriteResult64(hkReal impulseApplied, hkReal rhs,
                                                      ContactImpulseInfo* solverResultInMainMemory,
                                                      hkSpuDmaSparseWriter* writer)
{
    solverResultInMainMemory->m_fAccumulatedImpulse = impulseApplied;
    solverResultInMainMemory->m_fImpulseLimit = rhs;
}
__forceinline static void hkSolverExportWriteResult128(hkReal impulseApplied0, hkReal rhs0, hkReal impulseApplied1,
                                                       hkReal rhs1, ContactImpulseInfo* solverResultInMainMemory,
                                                       hkSpuDmaSparseWriter* writer)
{
    solverResultInMainMemory[0].m_fAccumulatedImpulse = impulseApplied0;
    solverResultInMainMemory[0].m_fImpulseLimit = rhs0;
    solverResultInMainMemory[1].m_fAccumulatedImpulse = impulseApplied1;
    solverResultInMainMemory[1].m_fImpulseLimit = rhs1;
}
// Iterates solver schemas to integrate constraint right-hand sides and write impulse results to solver output buffers.
// @fnv 0x00def570
// src: GUESS 0x00def570 (confidence: medium)
void hkReal_IntegrateConstraintSchemas(const ConstraintSolverInfo& info, const FloatRecord* solverInputs, const SolverSchemaHeader* schemas,
                  const QuantizedBoundsData* accums)
{
    const FloatRecord* solverIn = solverInputs;
    const SolverSchemaHeader* com = schemas;
    ContactImpulseInfo* solverOut = 0;
    int solverResultStriding = 0;
    ;
    QuantizedBoundsData nonConstAccumA;
    QuantizedBoundsData nonConstAccumB;
    const hkReal rhsFactorInfo = info.m_fTimeStep * info.m_fFirstTrailingParameter;
    const hkReal frictionRhsFactor = info.m_fTimeStep * info.m_fThirdTrailingParameter;
    const hkReal frameDeltaTime = info.m_iToiEventCount * info.m_fTimeStep;
    const hkReal rhsFactorUserTau = info.m_fTimeStep;
    FrictionJacobianTriple tripleJac;
    SolverRecordPair* doubleJac = reinterpret_cast<SolverRecordPair*>(&tripleJac);
    ConstraintJacobian* j1Lin2Ang = reinterpret_cast<ConstraintJacobian*>(&tripleJac);
    AngularJacobianElement* j2Ang = &tripleJac.m_kAngularJacobian;
    const FrictionJacobianTriple* tripleJacExtPtr = &tripleJac;
    const SolverRecordPair* doubleJacExtPtr = doubleJac;
    const ConstraintJacobian* j1Lin2AngExtPtr = j1Lin2Ang;
    const AngularJacobianElement* j2AngExtPtr = j2Ang;
    JacobianElement j2Lin2Ang;
    const JacobianElement* j2Lin2AngExtPtr = &j2Lin2Ang;
    const FloatRecord* nextSolverIn = 0;
    int numImpulseLimitsBreached = 0;
    hkpConstraintInstance* constraintInstance = 0;
    hkSpuDmaSparseWriter* srWriter = 0;
    const QuantizedBoundsData* mA = 0;
    const QuantizedBoundsData* mB = 0;
    int constraintBroken = 0;
    int dumA0 = constraintBroken;
    hkReal usedImpulseFactor;
    while (1)
    {
        switch (SolverSchemaHeader::getType(com))
        {
        case SolverSchemaHeader::SCHEMA_TYPE_HEADER: {
            const ConstraintHeaderSchema* headerSchema = static_cast<const ConstraintHeaderSchema*>(com);
            solverOut = headerSchema->m_solverResultInMainMemory;
            solverResultStriding = headerSchema->m_ucSecondHeaderByte;
            mA = headerSchema->getBodyA(accums);
            mB = headerSchema->getBodyB(accums);
            constraintInstance = headerSchema->m_pConstraintChainInstance;
            com = hkAddByteOffsetConst(headerSchema, sizeof(ConstraintHeaderSchema));
            if (solverOut == 0)
            {
                while (SolverSchemaHeader::getType(com) > SolverSchemaHeader::SCHEMA_TYPE_SIMPLE_BEGIN &&
                       SolverSchemaHeader::getType(com) < SolverSchemaHeader::SCHEMA_TYPE_SIMPLE_END)
                {
                    solverIn += SolverSchemaHeader::getNumSolverElemTemps(com);
                    com = hkAddByteOffsetConst(com, SolverSchemaHeader::GetLogicalSize(com));
                }
            }
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_GOTO: {
            const SchemaJump* sc = static_cast<const SchemaJump*>(com);
            com = hkAddByteOffsetConst(com, sc->m_offset);
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER: {
            const ShiftSolverResultsPointerSchema* schema = static_cast<const ShiftSolverResultsPointerSchema*>(com);
            solverOut =
                hkAddByteOffset(solverOut, hkInt16(solverResultStriding) * hkInt16(schema->getNumSolverResults()));
            com = hkAddByteOffsetConst(schema, 16);
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_PAIR_CONTACT:
        case SolverSchemaHeader::SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK: {
            const JacobianPair* schema = static_cast<const JacobianPair*>(com);
            doubleJacExtPtr = &schema->m_pJacobian;
            com = schema + 1;
            hkReal rhsOut1;
            hkReal rhsOut0;
            hkSolverExport::integrateRhsPair(*mA, *mB, &doubleJacExtPtr->m_kFirstFrictionJacobian, rhsFactorInfo,
                                             frameDeltaTime, rhsOut0, rhsOut1);
            hkSolverExportWriteResult64(solverIn[0].m_fAccumulatedImpulse, rhsOut0, solverOut, srWriter);
            solverOut = hkAddByteOffset(solverOut, solverResultStriding);
            hkSolverExportWriteResult64(solverIn[1].m_fAccumulatedImpulse, rhsOut1, solverOut, srWriter);
            solverOut = hkAddByteOffset(solverOut, solverResultStriding);
            solverIn += 2;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_SINGLE_CONTACT:
        case SolverSchemaHeader::SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK: {
            const JacobianPointerSchema* schema = static_cast<const JacobianPointerSchema*>(com);
            j1Lin2AngExtPtr = &schema->m_pJacobian;
            com = schema + 1;
            goto commonCodeForHk1Lin2AngJacobians;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
        case SolverSchemaHeader::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK: {
            const JacobianPointerSchema* schema = static_cast<const JacobianPointerSchema*>(com);
            j1Lin2AngExtPtr = &schema->m_pJacobian;
            com = schema + 1;
            if (solverIn->m_fAccumulatedImpulse > j1Lin2AngExtPtr->getUserValue() * 0.99f)
            {
                ConstraintBreachInfoBlock* h =
                    reinterpret_cast<ConstraintBreachInfoBlock*>(const_cast<SolverSchemaHeader*>(schemas));
                ConstraintChainBreachInfo* e = &h->getElem(numImpulseLimitsBreached++);
                e->m_type = 0;
                e->m_usSecondaryField = 1;
                e->m_pConstraintChainInstance = constraintInstance;
                e->m_solverResult = solverOut;
            }
            goto commonCodeForHk1Lin2AngJacobians;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_BILATERAL_USER_TAU: {
            const LinearSoftConstraintAtom* schema = static_cast<const LinearSoftConstraintAtom*>(com);
            j1Lin2AngExtPtr = &schema->m_pJacobian;
            com = schema + 1;
            goto commonCodeForHk1Lin2AngJacobians;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_LINEAR_LIMITS: {
            const LinearDistanceLimitAtom* schema = static_cast<const LinearDistanceLimitAtom*>(com);
            j1Lin2AngExtPtr = &schema->m_pJacobian;
            com = schema + 1;
            goto commonCodeForHk1Lin2AngJacobians;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT: {
            const JacobianDataHolder* schema = static_cast<const JacobianDataHolder*>(com);
            j1Lin2AngExtPtr = &schema->m_pJacobian;
            com = schema + 1;
            if (MathUtilities::fabs(solverIn->m_fAccumulatedImpulse) > j1Lin2AngExtPtr->getUserValue() * 0.99f)
            {
                constraintBroken = 1;
            }
            if (SolverSchemaHeader::getType(com) != SolverSchemaHeader::SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT &&
                constraintBroken)
            {
                ConstraintBreachInfoBlock* h =
                    reinterpret_cast<ConstraintBreachInfoBlock*>(const_cast<SolverSchemaHeader*>(schemas));
                ConstraintChainBreachInfo* e = &h->getElem(numImpulseLimitsBreached++);
                e->m_type = 0;
                e->m_usSecondaryField = 0;
                e->m_pConstraintChainInstance = constraintInstance;
                e->m_solverResult = 0;
                constraintBroken = 0;
            }
            goto commonCodeForHk1Lin2AngJacobians;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_BILATERAL: {
            hkReal rhs0;
            {
                const JacobianDataHolder* schema = static_cast<const JacobianDataHolder*>(com);
                j1Lin2AngExtPtr = &schema->m_pJacobian;
                com = schema + 1;
            }
        commonCodeForHk1Lin2AngJacobians:
            rhs0 = hkSolverExport::integrateRhs(*mA, *mB, j1Lin2AngExtPtr, rhsFactorInfo, frameDeltaTime);
            hkSolverExportWriteResult64(solverIn->m_fAccumulatedImpulse, rhs0, solverOut, srWriter);
            solverOut = hkAddByteOffset(solverOut, solverResultStriding);
            solverIn++;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_LINEAR_MOTOR: {
            const MotorSolverSchema* schema = static_cast<const MotorSolverSchema*>(com);
            j1Lin2AngExtPtr = &schema->m_pJacobian;
            usedImpulseFactor = solverIn[1].m_fSecondUnionFloat;
            hkReal deltaRhs = solverIn[2].m_fAccumulatedMotorRhs;
            hkReal rhs = j1Lin2AngExtPtr->getRHS();
            const_cast<ConstraintJacobian*>(j1Lin2AngExtPtr)->setRHS(rhs + deltaRhs);
            nextSolverIn = solverIn + SolverSchemaHeader::getNumSolverElemTemps(com);
            com = schema + 1;
            goto commonCodeFor1dLinarMotorAndFriction;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_FRICTION: {
            hkReal rhs0;
            {
                const FrictionImpulseLimitAtom* schema = static_cast<const FrictionImpulseLimitAtom*>(com);
                j1Lin2AngExtPtr = &schema->m_pJacobian;
                usedImpulseFactor = solverIn[1].m_fSecondUnionFloat;
                nextSolverIn = solverIn + SolverSchemaHeader::getNumSolverElemTemps(com);
                com = schema + 1;
            }
        commonCodeFor1dLinarMotorAndFriction:
            rhs0 = hkSolverExport::integrateRhs(*mA, *mB, j1Lin2AngExtPtr, rhsFactorInfo, frameDeltaTime) *
                   usedImpulseFactor;
            hkSolverExportWriteResult64(solverIn->m_fAccumulatedImpulse, rhs0, solverOut, srWriter);
            solverOut = hkAddByteOffset(solverOut, solverResultStriding);
            solverIn = nextSolverIn;
            nextSolverIn = 0;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_ANGULAR: {
            const JacobianHolder* schema = static_cast<const JacobianHolder*>(com);
            j2AngExtPtr = &schema->m_pJacobian;
            com = schema + 1;
            goto commonCodeForHk2AngJacobians;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_ANGULAR_LIMITS: {
            hkReal rhsa;
            {
                const AngularLimitJacobian* schema = static_cast<const AngularLimitJacobian*>(com);
                j2AngExtPtr = &schema->m_pJacobian;
                com = schema + 1;
            }
        commonCodeForHk2AngJacobians:
            rhsa = hkSolverExport::integrateAngularRhs(*mA, *mB, j2AngExtPtr, rhsFactorUserTau, frameDeltaTime);
            hkSolverExportWriteResult64(solverIn->m_fAccumulatedImpulse, rhsa, solverOut, srWriter);
            solverOut = hkAddByteOffset(solverOut, solverResultStriding);
            solverIn++;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_ANGULAR_MOTOR: {
            const MotorInfoRecord* schema = static_cast<const MotorInfoRecord*>(com);
            j2AngExtPtr = &schema->m_pJacobian;
            usedImpulseFactor = solverIn[1].m_fSecondUnionFloat;
            hkReal deltaRhs = solverIn[2].m_fAccumulatedMotorRhs;
            hkReal rhs = j2AngExtPtr->getAngularRhs();
            const_cast<AngularJacobianElement*>(j2AngExtPtr)->setAngularRhs(rhs + deltaRhs);
            nextSolverIn = solverIn + SolverSchemaHeader::getNumSolverElemTemps(com);
            com = schema + 1;
            goto commonCodeFor1dAngularMotorAndFriction;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_ANGULAR_FRICTION: {
            hkReal rhsa;
            {
                const FrictionImpulseLimitedJacobian* schema = static_cast<const FrictionImpulseLimitedJacobian*>(com);
                j2AngExtPtr = &schema->m_pJacobian;
                usedImpulseFactor = solverIn[1].m_fSecondUnionFloat;
                nextSolverIn = solverIn + SolverSchemaHeader::getNumSolverElemTemps(com);
                com = schema + 1;
            }
        commonCodeFor1dAngularMotorAndFriction:
            rhsa = hkSolverExport::integrateAngularRhs(*mA, *mB, j2AngExtPtr, rhsFactorUserTau, frameDeltaTime) *
                   usedImpulseFactor;
            hkSolverExportWriteResult64(solverIn->m_fAccumulatedImpulse, rhsa, solverOut, srWriter);
            solverOut = hkAddByteOffset(solverOut, solverResultStriding);
            solverIn = nextSolverIn;
            nextSolverIn = 0;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_1D_PULLEY: {
            const SingleJacobianSchema* schema = static_cast<const SingleJacobianSchema*>(com);
            j2Lin2AngExtPtr = &schema->m_pJacobian;
            com = schema + 1;
            hkReal rhs0 =
                hkSolverExport::integrateRhs2Lin2Ang(*mA, *mB, j2Lin2AngExtPtr, rhsFactorInfo, frameDeltaTime);
            hkSolverExportWriteResult64(solverIn->m_fAccumulatedImpulse, rhs0, solverOut, srWriter);
            solverOut = hkAddByteOffset(solverOut, solverResultStriding);
            solverIn++;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_2D_FRICTION: {
            const TwoAxisFrictionInfo* schema = static_cast<const TwoAxisFrictionInfo*>(com);
            doubleJacExtPtr = &schema->m_pJacobian;
            ContactImpulseInfo* dsr;
            schema->unpackSolverResultsPtr(dsr);
            usedImpulseFactor = solverIn[2].m_fSecondUnionFloat;
            com = schema + 1;
            hkReal rhsOut1;
            hkReal rhsOut0;
            hkSolverExport::integrateRhsPair(*mA, *mB, &doubleJacExtPtr->m_kFirstFrictionJacobian, frictionRhsFactor,
                                             frameDeltaTime, rhsOut0, rhsOut1);
            hkSolverExportWriteResult128(solverIn[0].m_fAccumulatedImpulse, rhsOut0 * usedImpulseFactor,
                                         solverIn[1].m_fAccumulatedImpulse, rhsOut1 * usedImpulseFactor, dsr, srWriter);
            solverIn += 3;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_3D_FRICTION: {
            const Friction3DSchema* schema = static_cast<const Friction3DSchema*>(com);
            tripleJacExtPtr = &schema->m_pJacobian;
            ContactImpulseInfo* dsr;
            schema->unpackSolverResultsPtr(dsr);
            usedImpulseFactor = solverIn[3].m_fSecondUnionFloat;
            com = schema + 1;
            hkReal rhsOut1;
            hkReal rhsOut0;
            hkSolverExport::integrateRhsPair(*mA, *mB, &tripleJacExtPtr->m_kFirstFrictionJacobian, frictionRhsFactor,
                                             frameDeltaTime, rhsOut0, rhsOut1);
            hkReal rhsa = hkSolverExport::integrateAngularRhs(*mA, *mB, &tripleJacExtPtr->m_kAngularJacobian,
                                                              frictionRhsFactor, frameDeltaTime) *
                          usedImpulseFactor;
            hkSolverExportWriteResult128(solverIn[0].m_fAccumulatedImpulse, rhsOut0 * usedImpulseFactor,
                                         solverIn[1].m_fAccumulatedImpulse, rhsOut1 * usedImpulseFactor, dsr, srWriter);
            hkSolverExportWriteResult64(solverIn[2].m_fAccumulatedImpulse, rhsa, dsr + 2, srWriter);
            solverIn += 4;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_2D_ROLLING_FRICTION: {
            const Friction2DSchema* schema = static_cast<const Friction2DSchema*>(com);
            j2AngExtPtr = &schema->m_kFirstFrictionJacobian;
            ContactImpulseInfo* dsr;
            schema->unpackSolverResultsPtr(dsr);
            usedImpulseFactor = solverIn[2].m_fSecondUnionFloat;
            nextSolverIn = solverIn + SolverSchemaHeader::getNumSolverElemTemps(com);
            com = schema + 1;
            hkReal rhsa = hkSolverExport::integrateAngularRhs(*mA, *mB, j2AngExtPtr, rhsFactorUserTau, frameDeltaTime) *
                          usedImpulseFactor;
            hkReal rhsa1 =
                hkSolverExport::integrateAngularRhs(*mA, *mB, j2AngExtPtr + 1, rhsFactorUserTau, frameDeltaTime) *
                usedImpulseFactor;
            hkSolverExportWriteResult128(solverIn[0].m_fAccumulatedImpulse, rhsa, solverIn[1].m_fAccumulatedImpulse,
                                         rhsa1, dsr, srWriter);
            solverIn = nextSolverIn;
            nextSolverIn = 0;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_ADD_VELOCITY: {
            const AddVelocitySchema* schema = static_cast<const AddVelocitySchema*>(com);
            com = schema + 1;
            QuantizedBoundsData* nonConstAccum;
            if (schema->m_iBodyIndex == 0)
            {
                nonConstAccumA = *mA;
                mA = &nonConstAccumA;
                nonConstAccum = &nonConstAccumA;
            }
            else
            {
                nonConstAccumB = *mB;
                mB = &nonConstAccumB;
                nonConstAccum = &nonConstAccumB;
            }
            nonConstAccum->m_vLinearVelocity.add4(schema->m_vVelocityChange);
            nonConstAccum->getSumLinearVel().add4(schema->m_vVelocityChange);
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_SET_CENTER_OF_MASS: {
            const CenterOfMassShiftSchema* schema = static_cast<const CenterOfMassShiftSchema*>(com);
            com = schema + 1;
            nonConstAccumA = *mA;
            mA = &nonConstAccumA;
            nonConstAccumB = *mB;
            mB = &nonConstAccumB;
            MatrixRotatedVector deltaVelA;
            deltaVelA.SetRotatedVector(schema->m_kAngularToLinearVelocityMatrixA, mA->m_vAngularVelocity);
            MatrixRotatedVector deltaSumVelA;
            deltaSumVelA.SetRotatedVector(schema->m_kAngularToLinearVelocityMatrixA, mA->getSumAngularVel());
            MatrixRotatedVector deltaVelB;
            deltaVelB.SetRotatedVector(schema->m_kAngularToLinearVelocityMatrixB, mB->m_vAngularVelocity);
            MatrixRotatedVector deltaSumVelB;
            deltaSumVelB.SetRotatedVector(schema->m_kAngularToLinearVelocityMatrixB, mB->getSumAngularVel());
            nonConstAccumA.m_vLinearVelocity.add4(deltaVelA);
            nonConstAccumA.getSumLinearVel().add4(deltaSumVelA);
            nonConstAccumB.m_vLinearVelocity.add4(deltaVelB);
            nonConstAccumB.getSumLinearVel().add4(deltaSumVelB);
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_SET_MASS: {
            const SetInverseMassSchema* schema = static_cast<const SetInverseMassSchema*>(com);
            com = schema + 1;
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_STIFF_SPRING_CHAIN: {
            ConstraintSolverBuffer* chain =
                reinterpret_cast<ConstraintSolverBuffer*>(const_cast<SolverSchemaHeader*>(com));
            ConstraintJacobian* j1Lin2AngInChain =
                ConstraintSolverBuffer::getJacobians(const_cast<SolverSchemaHeader*>(com));
            if (solverOut)
            {
                QuantizedBoundsDataOffset* va = chain->getAccumulatorOffsetsBase();
                for (int c = 0; c < chain->m_iConstraintCount; c++)
                {
                    const QuantizedBoundsData* raA = &va[c].getAccumulator(accums);
                    const QuantizedBoundsData* raB = &va[c + 1].getAccumulator(accums);
                    hkReal rhs0 =
                        hkSolverExport::integrateRhs(*raA, *raB, j1Lin2AngInChain, rhsFactorUserTau, frameDeltaTime);
                    hkSolverExportWriteResult64(solverIn->m_fAccumulatedImpulse, rhs0, solverOut, srWriter);
                    solverOut = hkAddByteOffset(solverOut, solverResultStriding);
                    solverIn++;
                    j1Lin2AngInChain++;
                }
            }
            else
            {
                solverIn += chain->m_iConstraintCount;
            }
            com = hkAddByteOffsetConst(com, chain->m_iElementCount);
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_BALL_SOCKET_CHAIN: {
            BallSocketChainSchema* chain =
                reinterpret_cast<BallSocketChainSchema*>(const_cast<SolverSchemaHeader*>(com));
            ConstraintJacobian* j1Lin2AngInChain =
                BallSocketChainSchema::getJacobians(const_cast<SolverSchemaHeader*>(com));
            if (solverOut)
            {
                QuantizedBoundsDataOffset* va = chain->getAccumulatorOffsetsBase();
                for (int c = 0; c < chain->m_iConstraintCount; c++)
                {
                    const QuantizedBoundsData* raA = &va[c].getAccumulator(accums);
                    const QuantizedBoundsData* raB = &va[c + 1].getAccumulator(accums);
                    int d = 0;
                    do
                    {
                        hkReal rhs0 = hkSolverExport::integrateRhs(*raA, *raB, j1Lin2AngInChain, rhsFactorUserTau,
                                                                   frameDeltaTime);
                        hkSolverExportWriteResult64(solverIn->m_fAccumulatedImpulse, rhs0, solverOut, srWriter);
                        solverOut = hkAddByteOffset(solverOut, solverResultStriding);
                        solverIn++;
                        j1Lin2AngInChain++;
                    } while (++d < 3);
                }
            }
            else
            {
                solverIn += chain->m_iConstraintCount * 3;
            }
            com = hkAddByteOffsetConst(com, chain->m_iElementCount);
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_POWERED_CHAIN: {
            PoweredChainSolverSchema* chain =
                reinterpret_cast<PoweredChainSolverSchema*>(const_cast<SolverSchemaHeader*>(com));
            {
                for (int c = 0; c < chain->m_iConstraintCount; c++)
                {
                    chain->m_pConstraintData[c] = chain->getChildConstraintStatusBase()[c].m_ucReferenceTimeSteps;
                }
            }
            ConstraintJacobian* j1Lin2AngInChain =
                PoweredChainSolverSchema::getLinearJacobians(const_cast<SolverSchemaHeader*>(com));
            AngularJacobianElement* j2AngInChain = PoweredChainSolverSchema::getAngularJacobians(
                const_cast<SolverSchemaHeader*>(com), chain->m_iConstraintCount);
            if (solverOut)
            {
                QuantizedBoundsDataOffset* va = chain->getAccumulatorOffsetsBase();
                for (int c = 0; c < chain->m_iConstraintCount; c++)
                {
                    const QuantizedBoundsData* raA = &va[c].getAccumulator(accums);
                    const QuantizedBoundsData* raB = &va[c + 1].getAccumulator(accums);
                    const QuantizedBoundsData& rB = *raB;
                    int i = 0;
                    do
                    {
                        hkReal rhsa;
                        hkReal rhs0 = hkSolverExport::integrateRhs(*raA, rB, j1Lin2AngInChain + i, rhsFactorUserTau,
                                                                   frameDeltaTime);
                        hkSolverExportWriteResult64(solverIn[i].m_fAccumulatedImpulse, rhs0, solverOut, srWriter);
                        rhsa = hkSolverExport::integrateAngularRhs(*raA, *raB, j2AngInChain + i, rhsFactorUserTau,
                                                                   frameDeltaTime);
                        hkSolverExportWriteResult64(solverIn[i + 3].m_fAccumulatedImpulse, rhsa, solverOut + 3 + i,
                                                    srWriter);
                        {
                            AngularMotorState* motorState = chain->getChildConstraintStatusBase() + c;
                            // Unsigned indices preserve the original x86 base/index encoding.
                            if (motorState->GetReferenceTimeStep(i) == 3)
                            {
                                const hkReal virtMass = (j2AngInChain + i)->getInvJacDiag();
                                const hkReal minDeltaVel = motorState->m_kAngularMotors[static_cast<size_t>(i)].m_fMaximumForce / virtMass;
                                const hkReal factor = 1.5f;
                                const hkReal minRhs =
                                    minDeltaVel * info.m_fTimeStep / motorState->m_kAngularMotors[static_cast<size_t>(i)].m_fTau * factor;
                                rhsa = MathUtilities::max2(rhsa, minRhs);
                                hkSolverExportWriteRhs(rhsa, solverOut + 3 + i);
                            }
                            if (motorState->GetReferenceTimeStep(i) == 1)
                            {
                                const hkReal virtMass = (j2AngInChain + i)->getInvJacDiag();
                                const hkReal maxDeltaVel = motorState->m_kAngularMotors[static_cast<size_t>(i)].m_fMinimumForce / virtMass;
                                const hkReal factor = 1.5f;
                                const hkReal maxRhs =
                                    maxDeltaVel * info.m_fTimeStep / motorState->m_kAngularMotors[static_cast<size_t>(i)].m_fTau * factor;
                                rhsa = MathUtilities::min2(rhsa, maxRhs);
                                hkSolverExportWriteRhs(rhsa, solverOut + 3 + i);
                            }
                        }
                    } while (++i < 3);
                    solverOut = hkAddByteOffset(solverOut, solverResultStriding * 6);
                    solverIn += 6;
                    j1Lin2AngInChain += 3;
                    j2AngInChain += 3;
                }
            }
            else
            {
                solverIn += chain->m_iConstraintCount * 6;
            }
            com = hkAddByteOffsetConst(com, chain->m_iElementCount);
            break;
        }
        case SolverSchemaHeader::SCHEMA_TYPE_END: {
            ConstraintBreachInfoBlock* h =
                reinterpret_cast<ConstraintBreachInfoBlock*>(const_cast<SolverSchemaHeader*>(schemas));
            h->m_iBreachCount = numImpulseLimitsBreached;
            return;
        }
        default:;
        }
    }
}
