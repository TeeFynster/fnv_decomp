#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// Preserve the original intrinsic storage view. The CRT's byte-array views
// change VC9 /GS instrumentation and parameter copies in this function.
#define _INCLUDED_MM2
// Exe 0x00dde4c0 FUN_00dde4c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

#include "../../../../../../include/hkVector4.h"

#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/Transform.h"
#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/hkVector4q.h"

// src/havok/physics/collide/util/welding/hkpmeshweldingutility_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/welding/hkpmeshweldingutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Record
{
    float x, y, key;
};
struct ComparisonResult
{
    bool value;
    ComparisonResult(bool result) : value(result)
    {}
    operator bool() const
    {
        return value;
    }
};
// src: GUESS 0x00ddcda0 (confidence: low)
__declspec(noinline) ComparisonResult Object_CompareField08_00ddcda0(const Record& left, const Record& right)
{
    return ComparisonResult(left.key > right.key);
}
inline void SwapRecords(Record& first, Record& second)
{
    __declspec(align(16)) Record temp = second;
    second = first;
    first = temp;
}
void hkAlgorithm_quickSortRecursive_struct_hkEntry_class_hkAlgorithm_less_struct_hkEntry(Record* records, int left, int right, int comparator);
// Exe 0x00dde4c0: unit-local DynamicArray view; declarations and layout are preserved.
struct HkpmeshweldingutilityDynamicArrayView
{
    void SpliceElements_Thunk(int a, int b, int c, int d);
};
struct S_00ddecf0_Key
{
    float t;
    float a;
    float b;
};
struct S_00ddecf0_Heap;
struct S_00ddecf0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddecf0_Heap* m_pStreamAllocator;
    S_00ddecf0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddecf0_Router* hkMemoryRouter_getInstance();
struct S_00ddecf0_Array
{
    S_00ddecf0_Key* m_data;
    int m_iElementCount;
    void ForwardCall_00ddecd0(S_00ddecf0_Heap& heap, int index, const S_00ddecf0_Key& key);
};
struct S_00ddecf0
{
    int unk0;
    S_00ddecf0_Array m_keys;
    void InsertKey(float t, float a, float b);
};
extern double DAT_010cd5a8;
extern double DAT_0101ff40;
float Object_ComputeDihedralSinCos(int a1, int* pOut, float* pF);
int GetIndexForValue(int aiArg);
struct Iface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual Iface* GetSub();
    virtual void* Query(void* key, void* out);
};
struct FlagTag
{
    bool m_bValue;
    FlagTag(bool value) : m_bValue(value)
    {}
    FlagTag(const FlagTag& other) : m_bValue(other.m_bValue)
    {}
};
struct Mgr
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Write(unsigned int hash, FlagTag value);
    virtual void Read(bool* out, unsigned int hash);
};
extern Mgr* DAT_01268360;
__declspec(align(16)) struct QueryBuffer
{
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
};
int hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(Iface* self, void* a, void* b, int idx, int zero, int* out);
bool* CheckSubQueries(bool* result, void* key, Iface* self);
void* hkArrayUtil__reserve(void* alloc, void* arr, int numElems, int elemSize);
void hkMemUtil_memMove(void* dst, const void* src, int numBytes);
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct S_00ddeab0_Elem
{
    int a, b, c;
    S_00ddeab0_Elem()
    {}
};
static __forceinline void S_00ddeab0_GrowArrayCapacity(hkArrayBase<S_00ddeab0_Elem>& self, void* alloc, int numElems);

static __forceinline void S_00ddeab0_GrowArrayCapacity(hkArrayBase<S_00ddeab0_Elem>& self, void* alloc, int numElems)
{
        int cap = self.m_iCapacityState & 0x3fffffff;
        if (cap < numElems)
        {
            int cap2 = cap + cap;
            int newcap = (numElems < cap2) ? cap2 : numElems;
            hkArrayUtil__reserve(alloc, (&self), newcap, 12);
        }
    }
struct S_00ddecd0
{
    void SpliceElements_Thunk(int a, int b, int c, int flag);
    void ForwardCall_00ddecd0(int a, int b, int c);
};
struct ObjInner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Transform* GetTransform(void* p1, void* buffer);
};
struct ObjOuter
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ObjInner* GetInner();
};
struct LocalBuffer
{
    __declspec(align(16)) int data[125];
};
char* IsDegenerateTriangle(char* out, const hkVector4* v0, const hkVector4* v1, const hkVector4* v2,
                           float eps);
int hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(ObjOuter* p2, Transform* trans, void* p1, int i, void* p3, int* outLocal);
int __cdecl CheckTransformAndProcess(void* p1, ObjOuter* pOuter, void* p3, short* outWord);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_and_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_cmple_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_load_ps1(const float* p);
extern "C" int _mm_movemask_ps(LocalM128 a);
extern const float DAT_01017d00;
extern const LocalM128 DAT_01017d10;
struct hkUtilDDCE
{
    static hkBool ForwardCall_00ddced0(const Transform& kA, const Transform& kB);
};
struct FUN_00ddea00_src
{
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
};
__declspec(align(16)) struct FUN_00ddea00_tmp
{
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
};
__declspec(align(16)) struct FUN_00ddea00_cls
{
    LocalM128 m_v00;
    LocalM128 m_v10;
    LocalM128 m_v20;
    LocalM128 m_v30;
    unsigned int m_i40;

    FUN_00ddea00_cls* CopyFromSource(const FUN_00ddea00_src* src);
};
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
int __cdecl Hkpmeshweldingutility_MergeTriangleVectors(const LocalM128* a, const LocalM128* b, int index, LocalM128* out, int* result);
extern "C"
{

    LocalM128 _mm_set_ss(float);

    LocalM128 _mm_sub_ps(LocalM128, LocalM128);

    LocalM128 _mm_mul_ps(LocalM128, LocalM128);

    LocalM128 _mm_mul_ss(LocalM128, LocalM128);

    LocalM128 _mm_add_ss(LocalM128, LocalM128);

    LocalM128 _mm_sub_ss(LocalM128, LocalM128);


    LocalM128 _mm_rsqrt_ss(LocalM128);

    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);

    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
}
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
struct ScalarNormal
{
    LocalM128 q;
    ScalarNormal(LocalM128 value) : q(value)
    {}
    LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
struct NormalVector
{
    LocalM128 q;
    __forceinline void difference(const NormalVector& a, const NormalVector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const NormalVector& a, const NormalVector& b)
    {
        LocalM128 pos = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 201), _mm_shuffle_ps(b.q, b.q, 210));
        LocalM128 neg = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 210), _mm_shuffle_ps(b.q, b.q, 201));
        q = _mm_sub_ps(pos, neg);
    }
    __forceinline ScalarNormal dot(const NormalVector& v) const
    {
        LocalM128 square = _mm_mul_ps(q, v.q);
        LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(square, square, 85), square);
        return ScalarNormal(_mm_add_ss(_mm_shuffle_ps(square, square, 170), sum));
    }
    __forceinline ScalarNormal inverseLength() const
    {
        LocalM128 half = _mm_set_ss(DAT_01016248);
        LocalM128 three = _mm_set_ss(DAT_01017718);
        LocalM128 zero = _mm_set_ss(DAT_01011d78);
        LocalM128 len = dot(*this).q;
        LocalM128 mask = _mm_cmpeq_ss(len, zero);
        LocalM128 approx = _mm_rsqrt_ss(len);
        LocalM128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, approx), approx));
        return ScalarNormal(_mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, approx), correction)));
    }
    __forceinline void normalize()
    {
        q = _mm_mul_ps(inverseLength().broadcast(), q);
    }
};
void hkpMeshWeldingUtility_calcAntiClockwiseTriangleNormal(const NormalVector* a, const NormalVector* b, const NormalVector* c, NormalVector* out);
struct S_00ddecf0_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * (int)sizeof(T));
    }
};
extern const double DAT_010290b8;
__declspec(nothrow) S_00ddecf0_Router* hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize) throw();
struct KeyLess
{
};
void __cdecl hkAlgorithm_quickSortRecursive_struct_hkEntry_class_hkAlgorithm_less_struct_hkEntry(S_00ddecf0_Key* keys, int left, int right, KeyLess cmp) throw();
template <typename T, typename L> inline void quickSort(T* pArr, int size, L cmpLess)
{
    if (size > 1)
        hkAlgorithm_quickSortRecursive_struct_hkEntry_class_hkAlgorithm_less_struct_hkEntry(pArr, 0, size - 1, cmpLess);
}
extern "C" double __cdecl fabs(double);
__declspec(noinline) ComparisonResult __cdecl AreZDiffering(const S_00ddecf0_Key& a, const S_00ddecf0_Key& b) throw()
{
    float delta = a.b - b.b;
    float distance = (float)fabs(delta);
    bool same = distance < DAT_01017d00;
    return ComparisonResult(!same);
}
// hkArray bodies (allocator = the memory router's heap).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap());
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if (!(m_iCapacityState & 0x80000000))
        alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& value)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    T* dest = m_data + m_iElementCount;
    new (dest) T(value);
    ++m_iElementCount;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}
static inline float clamp(float x, float lo, float hi)
{
    if (x < lo)
        return lo;
    if (x > hi)
        return hi;
    return x;
}
struct Track : public S_00ddecf0
{
    float hkHistogram_evaluate();
};
// FUN_00ddcf60 - "point A is close to one of the three points of the shape
// AND point B is close to one of them as well" test.
//
// The shape object holds three 4-float points at +0x20 / +0x30 / +0x40.
// A point counts as a hit when the x/y/z components of the difference are not
// (movmskps + "and 7" + "cmp 7").
//
// The result byte is written through the first argument; the argument pointer
// is handed back to the caller.
struct Shape
{
    float unk00, unk04, unk08, unk0c;
    float unk10, unk14, unk18, unk1c;
    Vec4 p0, p1, p2;
};
volatile unsigned char* __cdecl Object_TestTriangleVertexProximity(volatile unsigned char* out, const Vec4* a, const Vec4* b, const Shape* s);
extern "C"
{
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
    void _mm_store_ss(float*, LocalM128);
    float __cdecl Atan2(float y, float x);
}
static __forceinline float hkAtan2(float y, float x)
{
    return Atan2(y, x);
}
void __cdecl FUN_00ddd620_triNormal(const hkVector4q& a, const hkVector4q& b, const hkVector4q& c,
                                    hkVector4q& normalOut);
float Object_ComputeDihedralSinCos(const hkVector4q* v, float* sinOut, float* cosOut);
extern "C" LocalM128 _mm_load_ps(float const* _A);
extern "C" void _mm_store_ps(float* _V, LocalM128 _A);
struct __declspec(align(16)) Row
{
    float x, y, z, w;
};
struct __declspec(align(16)) Matrix44
{
    Row row0, row1, row2, row3;
};
struct __declspec(align(16)) Item
{
    Matrix44 transform;
    int payload;
};
struct S00dde760_PoolState
{
    char* cursor;
    int unk04;
    int unk08;
    int unk0c;
    S_00ddecf0_Heap* allocator;
};
struct S00dde760_ScratchVector
{
    Item* elements;
    unsigned int size;
    unsigned int encodedCapacity;
    char* originalCursor;
};
extern "C" Matrix44 DAT_01268370;
extern "C" void __cdecl hkpMeshWeldingUtility_computeWeldingInfoMultiShape(const Matrix44*, int, int, S00dde760_ScratchVector*, int);
void __cdecl hkpMeshWeldingUtility_computeWeldingInfo(int a, int b, int c, int d);

extern "C" ::LocalM128(_mm_setr_ps)(float, float, float, float);
extern "C" ::LocalM128(_mm_add_ps)(::LocalM128, ::LocalM128);

extern float DAT_010141cc;
extern const char str_010d7fc8[];
extern const char str_010d8004[];
extern const char str_010d8014[];
extern const char str_010d7f50[];

static __forceinline LocalM128& vectorQuad(Vec4& vector)
{
    return *reinterpret_cast<LocalM128*>(&vector);
}
static __forceinline void setAll3(Vec4& vector, float value)
{
    vectorQuad(vector) = (_mm_setr_ps)(value, value, value, ::DAT_01011d78);
}
struct __declspec(align(16)) S00dde4c0_Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 v[3];
};
struct __declspec(align(16)) S00dde4c0_Aabb
{
    Vec4 mn;
    Vec4 mx;
};

struct S00dde4c0_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int type;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int data;
};
struct S00dde4c0_Src
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual S00dde4c0_Shape* getShape(int index, void* buffer);
};
struct S00dde4c0_Mesh
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual S00dde4c0_Src* getSource();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void query(S00dde4c0_Aabb* aabb, void* outArray);
};
struct S00dde4c0_Out
{
    ::LocalM128 a;
    ::LocalM128 b;
    ::LocalM128 c;
    ::LocalM128 d;
    ::LocalM128 e;
    ::LocalM128 f;
};

struct S00dde4c0_Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[128];
    __forceinline S00dde4c0_Array()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000080;
    }
    __forceinline void finish()
    {
        release(::hkMemoryRouter_getInstance()->heap());
    }
    __forceinline void release(::S_00ddecf0_Heap& a)
    {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            a._bufFree<int>(m_data, m_iCapacityState & 0x3fffffff);
    }
};
struct S00dde4c0_Buf
{
    int b[128];
};

struct S00dde4c0_Str
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00cb1600(void* buf, int n);
    S00dde4c0_Str& ProcessAndReturnValue_00cc01c0(const char* s);
    S00dde4c0_Str& EvaluateValue_00cc02d0(int v);
    void FUN_00cc00e0();
};
struct S00dde4c0_Err
{
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void report(int a, unsigned int id, const char* msg, const char* file, int line);
};

int __cdecl Hkpmeshweldingutility_MergeTriangleVectors(const Vec4* tri, const void* shape, int idx, S00dde4c0_Out* out, int* winding);
unsigned int __cdecl hkpMeshWeldingUtility_modifyCombinedEdgesBitcode(unsigned int f, unsigned int idx, unsigned int v);

// @fnv 0x00dde4c0
// src: XBOX_PDB 0x00dde4c0
int __cdecl hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(S00dde4c0_Mesh* mesh, S00dde4c0_Tri* tri, int skip, int idx, int checkWinding,
                         unsigned short* flags)
{
    const Vec4* verts = tri->v;
    S00dde4c0_Array hits;
    {
        S00dde4c0_Aabb aabb;
        struct __declspec(align(16)) BoundsWork
        {
            Vec4 center;
            Vec4 lo;
        } work;
        work.center = verts[idx % 3];
        float eps = DAT_010141cc;
        setAll3(work.lo, -eps);
        ::LocalM128 low = vectorQuad(work.lo);
        __declspec(align(16)) Vec4 hi;
        setAll3(hi, eps);
        vectorQuad(aabb.mn) = (_mm_add_ps)(low, vectorQuad(work.center));
        vectorQuad(aabb.mx) = (_mm_add_ps)(vectorQuad(hi), vectorQuad(work.center));
        mesh->query(&aabb, &hits);
    }
    bool first = true;
    for (int i = hits.m_iElementCount - 1; i >= 0; i--)
    {
        int other = hits.m_data[i];
        if (other == skip)
            continue;
        S00dde4c0_Buf buffer;
        S00dde4c0_Shape* shape = mesh->getSource()->getShape(other, &buffer);
        if (shape->type != 3)
            continue;
        int winding[2];
        S00dde4c0_Out out;
        if (Hkpmeshweldingutility_MergeTriangleVectors(verts, &shape->data, idx, &out, winding) != 4)
            continue;
        if (checkWinding && winding[0] != (winding[1] + 1) % 3)
        {
            if (first)
            {
                S00dde4c0_Str sb;
                sb.FUN_00cb1600(&buffer, 0x200);
                sb.ProcessAndReturnValue_00cc01c0(str_010d7fc8)
                    .EvaluateValue_00cc02d0(skip)
                    .ProcessAndReturnValue_00cc01c0(str_010d8004)
                    .EvaluateValue_00cc02d0(other)
                    .ProcessAndReturnValue_00cc01c0(str_010d8014);
                ((S00dde4c0_Err*)::DAT_01268360)->report(1, 0xabba751e, (const char*)&buffer, str_010d7f50, 0x2c9);
                sb.FUN_00cc00e0();
            }
            first = false;
        }
        *flags = (unsigned short)hkpMeshWeldingUtility_modifyCombinedEdgesBitcode(*flags, idx, ::GetIndexForValue((int)&out));
    }
    int result = !first;
    hits.finish();
    return result;
}
