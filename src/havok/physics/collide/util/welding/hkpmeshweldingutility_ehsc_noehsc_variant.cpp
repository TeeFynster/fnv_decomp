#include "../../../../../../include/hkArray.h"
// src/havok/physics/collide/util/welding/hkpmeshweldingutility_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/welding/hkpmeshweldingutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Keep the original intrinsic storage view: CRT byte-array views change VC9 /GS code.
#define _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#include "../../../../../../include/hkBool.h"
#define FNV64_HKVECTOR4_OWN_COPY
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkVector4.h"

#include "../../../../../../include/Transform.h"
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps1(const float*);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
}
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
// Exe 0x00dddcd0: unit-local DynamicArray view; declarations and layout are preserved.
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
extern const float DAT_01017d00;
extern const LocalM128 DAT_01017d10;
struct hkTransformHolderDDCE
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
struct hkUtilDDCE
{
    static hkBool ForwardCall_00ddced0(const hkTransformHolderDDCE& kA, const hkTransformHolderDDCE& kB);
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
int __cdecl Hkpmeshweldingutility_MergeTriangleVectors(const LocalM128* a, const LocalM128* b, int index, LocalM128* out, int* result);
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

extern "C"
{
    double __cdecl fabs(double);
}

extern char DAT_010d7f80;
extern char DAT_010d7f50;
extern const double DAT_0103c7c8;



template <typename ENUM, typename STORAGE> class hkEnumW
{
  public:
    operator ENUM() const
    {
        return static_cast<ENUM>(m_kStorage);
    }
    hkBool operator==(ENUM e) const
    {
        return m_kStorage == static_cast<STORAGE>(e);
    }
    hkBool operator!=(ENUM e) const
    {
        return m_kStorage != static_cast<STORAGE>(e);
    }

  private:
    STORAGE m_kStorage;
};

enum hkpShapeTypeW
{
    HK_SHAPE_TRIANGLE_W = 3
};
enum hkCollectionTypeW
{
    COLLECTION_LIST_W = 1,
    COLLECTION_EXTENDED_MESH_W = 2,
    COLLECTION_TRISAMPLED_HEIGHTFIELD_W = 4,
    COLLECTION_USER_W = 5,
    COLLECTION_SIMPLE_MESH_W = 6
};


// hkVector4 (hkSseVector4.inl): inline bodies used by this welding unit.
// Preserve the original implicit SIMD-union copy used by the triangle vertex temporaries.
inline hkVector4::hkVector4(const hkVector4& other)
{
    unsigned char* dst = reinterpret_cast<unsigned char*>(&m_vComponents);
    const unsigned char* src = reinterpret_cast<const unsigned char*>(&other.m_vComponents);
    for (unsigned int i = 0; i < sizeof(m_vComponents); ++i)
        dst[i] = src[i];
}
inline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x)
{}
inline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
inline const LocalM128& hkSimdReal::getQuad() const
{
    return m_vValue;
}
inline void hkVector4::SetAllComponents(float a)
{
    m_vComponents = _mm_set_ps1(a);
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 cross0;
    cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1;
    cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
inline hkSimdReal WeldingLengthInverse3(const hkVector4& kV)
{
    const LocalM128 kHalf = _mm_set_ss(0.5f);
    const LocalM128 kThree = _mm_set_ss(3.0f);
    const LocalM128 kZero = _mm_set_ss(0.0f);
    const LocalM128 kLenSq = kV.dot3(kV).getQuad();
    const LocalM128 kLenIsZero = _mm_cmpeq_ss(kLenSq, kZero);
    const LocalM128 kEstimate = _mm_rsqrt_ss(kLenSq);
    const LocalM128 kNewtonStep =
        _mm_mul_ss(_mm_mul_ss(kHalf, kEstimate), _mm_sub_ss(kThree, _mm_mul_ss(_mm_mul_ss(kLenSq, kEstimate), kEstimate)));
    return _mm_andnot_ps(kLenIsZero, kNewtonStep);
}
inline void hkVector4::normalize3()
{
    LocalM128 lenInv = WeldingLengthInverse3(*this).broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
}
inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}
inline const hkVector4& hkRotation::getColumn(int i) const
{
    return (&m_kColumn0)[i];
}
inline void hkVector4::_setMul3(const hkRotation& a, const hkVector4& b)
{
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const LocalM128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const LocalM128* r = reinterpret_cast<const LocalM128*>(&t);
    LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    LocalM128 r0 = _mm_mul_ps(r[0], b0);
    LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    LocalM128 r1 = _mm_mul_ps(r[1], b1);
    LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    LocalM128 r2 = _mm_mul_ps(r[2], b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, r[3]));
}

struct hkAabbW
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    hkAabbW()
    {}
    inline hkAabbW(const hkVector4& p0, const hkVector4& p1)
    {
        setEmpty();
        includePoint(p0);
        includePoint(p1);
    }
    inline void setEmpty()
    {
        m_kMinimumCorner.SetAllComponents(3.40282e+38f);
        m_kMaximumCorner.SetAllComponents(-3.40282e+38f);
    }
    inline void includePoint(const hkVector4& point)
    {
        m_kMinimumCorner.setMin4(m_kMinimumCorner, point);
        m_kMaximumCorner.setMax4(m_kMaximumCorner, point);
    }
};

struct hkpTriangleShapeW
{
    int vtbl;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    hkEnumW<hkpShapeTypeW, unsigned int> m_type;
    int unk10, unk14, unk18, unk1c;
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
    hkVector4 m_kVertexC;
    hkpShapeTypeW getType() const
    {
        return m_type;
    }
    const hkVector4& getVertex(int i) const
    {
        return (&m_kVertexA)[i];
    }
};

struct hkInplaceArrayW
{
    unsigned int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[128];
    inline hkInplaceArrayW(int size)
    {
        m_data = m_kStorage;
        m_iElementCount = size;
        m_iCapacityState = 128 | 0x80000000;
    }
    inline ~hkInplaceArrayW()
    {
        S_00ddecf0_Heap& alloc = hkMemoryRouter_getInstance()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(unsigned int));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    unsigned int& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkEntryW
{
    float a, b, c;
};

struct hkHistogramW
{
    float m_fScalar;
    hkEntryW* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    inline hkHistogramW(bool zeroTolerance)
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
        m_fScalar = zeroTolerance ? 0.0f : 3.14159265f;
    }
    inline ~hkHistogramW()
    {
        S_00ddecf0_Heap& alloc = hkMemoryRouter_getInstance()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(hkEntryW));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    float hkHistogram_evaluate();
    void InsertKey(float t0, float t1, float angle);
};

struct hkpShapeContainerW
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const hkpTriangleShapeW* GetShapeForKey(unsigned int key, QueryBuffer& buffer) const;
};

struct hkpBvTreeShapeW
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual const hkpShapeContainerW* GetShapeContainer() const;
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void GetAabbHits(const hkAabbW& aabb, hkInplaceArrayW& hits) const;
};

struct hkShapeInfoW
{
    __declspec(align(16)) Transform m_kMotionTransform;
    const hkpBvTreeShapeW* m_pCollisionShape;
};

struct hkShapeInfoArrayW
{
    hkShapeInfoW* m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    hkShapeInfoW& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkpShapeCollectionContainerW
{
    virtual void v0();
    virtual void v1();
    virtual int GetFirstKey() const;
    virtual int GetNextShapeKey(int) const;
    virtual void v4();
    virtual const hkpTriangleShapeW* GetShapeForKey(int, QueryBuffer&) const;
};

struct hkpShapeCollectionW
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void SetWeldingMode(int weldingType);
    virtual void SetWeldingInfo(int key, unsigned int weldingInfo);
    int unk04;
    int unk08;
    int unk0c;
    hkpShapeCollectionContainerW m_container;
    hkBool m_bDisableWelding;
    hkEnumW<hkCollectionTypeW, unsigned char> m_eCollectionType;
};

struct TextFormat
{
    char* data;
    int size;
    int capacityFlags;
    void FUN_00cb1600(char*, int);
    TextFormat* ProcessAndReturnValue_00cc01c0(const char*);
    void FUN_00cc00e0();
};

struct ErrorManager
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int Report(int, unsigned, char*, const char*, int);
};

// hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal
// src: COMMUNITY 0x00ddd620
__declspec(noinline) void __cdecl hkpMeshWeldingUtility_calcAntiClockwiseTriangleNormal(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2,
                                               hkVector4& normal)
{
    hkVector4 e0;
    e0.setSub4(v1, v0);
    hkVector4 e1;
    e1.setSub4(v2, v1);
    normal.setCross(e0, e1);
    normal.normalize3();
}
hkBool __cdecl Object_TestTriangleVertexProximity(const hkVector4& v0, const hkVector4& v1, const hkpTriangleShapeW* triangle);
float __cdecl hkpMeshWeldingUtility_calcAngleForEdge(const hkVector4& normal, const hkVector4& perp, const hkVector4& otherNormal);
void __cdecl GenerateTrianglePlanes(hkVector4* planes, const hkpTriangleShapeW* triangle, float tolerance);
hkBool __cdecl hkClipEdgeAgainstPlanes(const hkVector4& a, const hkVector4& b, int numPlanes, const hkVector4* planes,
                             float& tmin, float& tmax);
int __cdecl FindAngleIndex(float angle);
unsigned int __cdecl hkpMeshWeldingUtility_modifyCombinedEdgesBitcode(unsigned int combined, int edgeIndex, unsigned int code);

// hkIsEdgeInTrianglePlane
__declspec(noinline) hkBool __cdecl IsDotProductBelowThreshold(const hkVector4& edge, const hkVector4& normal)
{
    LocalM128 product = _mm_mul_ps(edge.m_vComponents, normal.m_vComponents);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 170), sum);
    float scalar;
    _mm_store_ss(&scalar, sum);
    float magnitude = (float)fabs((double)scalar);
    return hkBool(magnitude < DAT_0103c7c8);
}

// @fnv 0x00dddcd0
// src: XBOX_PDB 0x00dddcd0
void __cdecl hkpMeshWeldingUtility_computeWeldingInfoMultiShape(const Transform& transform, hkpShapeCollectionW* collection, int weldingType,
                          hkShapeInfoArrayW& allShapes, bool weldOpenEdges)
{
    if (collection->m_eCollectionType != COLLECTION_LIST_W &&
        collection->m_eCollectionType != COLLECTION_EXTENDED_MESH_W &&
        collection->m_eCollectionType != COLLECTION_SIMPLE_MESH_W &&
        collection->m_eCollectionType != COLLECTION_TRISAMPLED_HEIGHTFIELD_W &&
        collection->m_eCollectionType != COLLECTION_USER_W)
    {
        QueryBuffer messageStorage;
        char* message = reinterpret_cast<char*>(&messageStorage);
        TextFormat formatted;
        formatted.FUN_00cb1600(message, 512);
        formatted.ProcessAndReturnValue_00cc01c0(&DAT_010d7f80);
        ((ErrorManager*)DAT_01268360)->Report(1, 0x3f508c6a, message, &DAT_010d7f50, 271);
        formatted.FUN_00cc00e0();
        return;
    }

    collection->SetWeldingMode(weldingType);
    if (weldingType == 6)
        return;
    collection->m_bDisableWelding = true;
    hkpShapeCollectionContainerW* container = &collection->m_container;
    for (int key = container->GetFirstKey(); key != -1; key = container->GetNextShapeKey(key))
    {
        QueryBuffer buffer;
        const hkpTriangleShapeW* triangle = container->GetShapeForKey(key, buffer);
        if (triangle->getType() != HK_SHAPE_TRIANGLE_W)
            continue;

        unsigned int weldingInfo = 0;
        hkVector4 triangleNormal;
        hkpMeshWeldingUtility_calcAntiClockwiseTriangleNormal(triangle->getVertex(0), triangle->getVertex(1), triangle->getVertex(2), triangleNormal);

        for (int edgeIndex = 0; edgeIndex < 3; edgeIndex++)
        {
            hkHistogramW histogram(weldOpenEdges);
            hkVector4 v0 = triangle->getVertex(edgeIndex);
            hkVector4 v1 = triangle->getVertex((edgeIndex + 1) % 3);
            hkVector4 v2 = triangle->getVertex((edgeIndex + 2) % 3);

            for (int shapeIndex = 0; shapeIndex < allShapes.GetLogicalSize(); shapeIndex++)
            {
                const hkShapeInfoW& info = allShapes[shapeIndex];
                const hkpBvTreeShapeW* bvTree = allShapes[shapeIndex].m_pCollisionShape;
                __declspec(align(16)) Transform t;
                t.hkTransform_setMulInverseMul(info.m_kMotionTransform, transform);

                hkVector4 normal;
                normal._setRotatedDir(*reinterpret_cast<const hkRotation*>(t.r), triangleNormal);
                hkVector4 a;
                a._setTransformedPos(*reinterpret_cast<const hkTransform*>(&t), v0);
                hkVector4 b;
                b._setTransformedPos(*reinterpret_cast<const hkTransform*>(&t), v1);
                hkVector4 c;
                c._setTransformedPos(*reinterpret_cast<const hkTransform*>(&t), v2);
                hkVector4 edge;
                edge.m_vComponents = _mm_sub_ps(b.m_vComponents, a.m_vComponents);
                edge.normalize3();

                hkInplaceArrayW hits(0);
                bvTree->GetAabbHits(hkAabbW(a, b), hits);

                for (int j = 0; j < hits.GetLogicalSize(); j++)
                {
                    unsigned int hitKey = hits[j];
                    const hkpShapeContainerW* shapeContainer = bvTree->GetShapeContainer();
                    QueryBuffer shapeBuffer;
                    const hkpTriangleShapeW* other = shapeContainer->GetShapeForKey(hitKey, shapeBuffer);
                    if (other->getType() != HK_SHAPE_TRIANGLE_W)
                        continue;

                    if (hkUtilDDCE::ForwardCall_00ddced0(*(const hkTransformHolderDDCE*)triangle,
                                                 *(const hkTransformHolderDDCE*)other)
                            .m_cBooleanValue ||
                        Object_TestTriangleVertexProximity(b, c, other) || Object_TestTriangleVertexProximity(c, a, other))
                        continue;

                    hkVector4 otherNormal;
                    hkpMeshWeldingUtility_calcAntiClockwiseTriangleNormal(other->getVertex(0), other->getVertex(1), other->getVertex(2), otherNormal);
                    if (!IsDotProductBelowThreshold(edge, otherNormal))
                        continue;

                    hkVector4 perp;
                    perp.setCross(edge, normal);
                    perp.normalize3();
                    float angle = hkpMeshWeldingUtility_calcAngleForEdge(normal, perp, otherNormal);

                    hkVector4 planes[5];
                    GenerateTrianglePlanes(planes, other, 0.05f);
                    float tmin, tmax;
                    if (hkClipEdgeAgainstPlanes(a, b, 5, planes, tmin, tmax))
                        histogram.InsertKey(tmin, tmax, angle);
                }
            }
            weldingInfo = (unsigned short)hkpMeshWeldingUtility_modifyCombinedEdgesBitcode(weldingInfo, edgeIndex, FindAngleIndex(histogram.hkHistogram_evaluate()));
        }
        collection->SetWeldingInfo(key, weldingInfo);
    }
}
