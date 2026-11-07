#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/staging/blk_00ce0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00ce0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00ce0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"
// Keep the original intrinsic lane definition: the CRT byte-array lanes make
// this compiler insert /GS checks into otherwise unchanged vector operations.
// Exe 0x00ce2d10 FUN_00ce2d10: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
#include "../../include/hkVector4.h"
#include "../../include/hkArray.h"
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);

struct __declspec(align(16)) SortElem16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

typedef bool(__cdecl* SortElemLess)(const SortElem16& a, const SortElem16& b);

// @fnv 0x00cf83c0
// src: HAVOK_LIB 0x00cf83c0
void __cdecl hkAlgorithm_quickSortRecursive_struct_hkpBodyOperationEntry_bool(SortElem16* pArr, int d, int h, SortElemLess cmpLess)
{
    int i, j;
    SortElem16 str;
begin:
    i = d;
    j = h;
    str = pArr[(d + h) >> 1];
    do
    {
        while (cmpLess(pArr[i], str))
            i++;
        while (cmpLess(str, pArr[j]))
            j--;
        if (j >= i)
        {
            if (j != i)
            {
                SortElem16* pj = &pArr[j];
                SortElem16* pi = &pArr[i];
                SortElem16 tmp = *pj;
                *pj = *pi;
                *pi = tmp;
            }
            j--;
            i++;
        }
    } while (i <= j);
    if (d < j)
    {
        hkAlgorithm_quickSortRecursive_struct_hkpBodyOperationEntry_bool(pArr, d, j, cmpLess);
    }
    if (i < h)
    {
        d = i;
        goto begin;
    }
}

extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);

struct QuaternionVector
{
    LocalM128 value;
// src: COMMUNITY 0x00c66320
    __declspec(noinline) void setMul(const QuaternionVector* left, const QuaternionVector* right)
    {
        LocalM128 a = left->value;
        LocalM128 b = right->value;
        LocalM128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        LocalM128 imag = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xff), a),
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xff), b), cross));
        LocalM128 prod = _mm_mul_ps(b, a);
        LocalM128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        LocalM128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        value = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};
// hkQsTransform layout (translation, quaternion, scale) over this unit's __m128/QuaternionVector stand-ins.
struct PoseQsTransform
{
    LocalM128 translation;
    QuaternionVector rotation;
    LocalM128 scale;
};
extern const LocalM128 DAT_010c71e0;
struct Par_00ce2d10
{
    LocalM128 translation;
    QuaternionVector rotation;
};

template <class T> struct PointerParam
{
    T* p;
    PointerParam(T* q) : p(q)
    {}
    operator T*() const
    {
        return p;
    }
    PointerParam& operator++()
    {
        ++p;
        return *this;
    }
    T* operator->() const
    {
        return p;
    }
};
// @fnv 0x00ce2d10
// src: GUESS 0x00ce2d10 (confidence: low)
void __cdecl Runtime_ProcessEntries_00ce2d10(const PoseQsTransform* parents, PointerParam<const PoseQsTransform> local, const short* indices,
                          int count, PoseQsTransform* output)
{
    if (!indices)
    {
        for (int i = 0; i < count; ++i)
        {
            const PoseQsTransform& l = local[i];
            const PoseQsTransform& p = parents[i];
            LocalM128 v = l.translation;
            LocalM128 q = p.rotation.value;
            LocalM128 t1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
            LocalM128 t2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
            LocalM128 cross = _mm_sub_ps(t1, t2);
            LocalM128 w = _mm_shuffle_ps(q, q, 0xff);
            LocalM128 product = _mm_mul_ps(v, q);
            LocalM128 s55 = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
            LocalM128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), s55);
            LocalM128 rotated =
                _mm_add_ps(_mm_mul_ps(cross, w), _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
                                                            _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q)));
            output[i].translation = _mm_add_ps(_mm_add_ps(rotated, rotated), p.translation);
            output[i].rotation.setMul(&p.rotation, &l.rotation);
            output[i].scale = _mm_mul_ps(l.scale, p.scale);
        }
    }
    else
    {
        int i = 0;
        if (i >= count)
            return;
        const PoseQsTransform* source = local.p;
        do
        {
            short index = indices[i];
            if (index >= 0)
            {
                PoseQsTransform parent;
                parent.rotation.value = parents[index].rotation.value;
                parent.scale = parents[index].scale;
                parent.translation = parents[index].translation;
                LocalM128 v = source->translation;
                LocalM128 q = parent.rotation.value;
                LocalM128 t1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
                LocalM128 t2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
                LocalM128 cross = _mm_sub_ps(t1, t2);
                LocalM128 w = _mm_shuffle_ps(q, q, 0xff);
                LocalM128 product = _mm_mul_ps(v, q);
                LocalM128 s55 = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
                LocalM128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), s55);
                LocalM128 rotated = _mm_add_ps(_mm_mul_ps(cross, w),
                                            _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
                                                       _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q)));
                output[index].translation = _mm_add_ps(_mm_add_ps(rotated, rotated), parent.translation);
                output[index].rotation.setMul(&parent.rotation, &source->rotation);
                output[index].scale = _mm_mul_ps(source->scale, parent.scale);
                ++source;
            }
            else
            {
                ++source;
            }
            ++i;
        } while (i < count);
    }
}

struct Cls
{
    unsigned short m0, m2, m4, m6;
    LocalM128 v10, v20, v30, v40, v50, v60;
    Cls* InitializeFields_00ce4a50(Cls* src);
};

// @fnv 0x00ce4a50
// src: GUESS 0x00ce4a50 (confidence: low)
Cls* Cls::InitializeFields_00ce4a50(Cls* src)
{
    m0 = src->m0;
    m2 = src->m2;
    m4 = src->m4;
    m6 = src->m6;
    v10 = src->v10;
    v20 = src->v20;
    v30 = src->v30;
    v40 = src->v40;
    v50 = src->v50;
    v60 = src->v60;
    return this;
}

struct SortRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

typedef char*(__cdecl* SortCmp)(void* tag, const SortRec* lhs, const SortRec* rhs);

void __cdecl FUN_00ce245a(SortRec* a, int low, int high, SortCmp cmp);

// @fnv 0x00cf8510
// src: COMMUNITY 0x00cf8510
void __cdecl hkAlgorithm_quickSortRecursive(SortRec* a, int low, int high, SortCmp cmp)
{
    char tagLo;
    char tagHi;

    for (;;)
    {
        int j = high;
        int i = low;
        __declspec(align(16)) SortRec pivot = a[(i + j) >> 1];
        do
        {
            while (*cmp(&tagLo, &a[i], &pivot))
                ++i;
            while (*cmp(&tagHi, &pivot, &a[j]))
                --j;
            if (j < i)
                break;
            if (j != i)
            {
                SortRec& x = a[j];
                SortRec& y = a[i];
                __declspec(align(16)) SortRec t = x;
                x = y;
                y = t;
            }
            --j;
            ++i;
        } while (i <= j);
        if (low < j)
            FUN_00ce245a(a, low, j, cmp);
        if (i >= high)
            return;
        low = i;
    }
}




inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}

inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}

namespace fnv_00cfac20 {
extern "C" LocalM128 _mm_min_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_max_ps(LocalM128 a, LocalM128 b);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned int DAT_0126835c;
extern char DAT_010cc678[];
extern char DAT_010c41f8[];
void* __cdecl hkMemoryRouter_getInstance(void);
struct S00cfac20_Ray
{
    hkVector4 from;
    hkVector4 to;
    hkVector4 extra;
};
struct S00cfac20_Aabb
{
    hkVector4 mn;
    hkVector4 mx;
    void includePoint(const hkVector4& p)
    {
        mn.setMin4(mn, p);
        mx.setMax4(mx, p);
    }
};
struct S00cfac20_Builder
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual int GetLogicalSize();
    virtual void v64();
    virtual void init(S00cfac20_Aabb* bounds, void* mem);
};
struct S00cfac20_Mon
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
static inline char* S00cfac20_alloc(hkMemoryRouter* stack, int size)
{
    char* r = reinterpret_cast<char*>(stack->m_stack.m_next.m_storage);
    stack->m_stack.m_next.m_storage = (void*)(reinterpret_cast<int>(r + ((size + 0x7f) & ~0x7f)));
    return r;
}
static inline void S00cfac20_release(hkMemoryRouter* stack, char* p)
{
    stack->m_stack.m_next.m_storage = (void*)(reinterpret_cast<int>(p));
}
struct S00cfac20_Grp
{
    void RecordAndDispatch(S00cfac20_Builder* b, S00cfac20_Ray* ray, void* ctx, void* mem, char* out);
    void ProcessEntries_00cfac20(S00cfac20_Builder* b, S00cfac20_Ray* rays, int count, void* ctx, char* out);
};
static inline void S00cfac20_timer(const char* name)
{
    S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue(DAT_0126835c);
    char* p = mon->cur;
    if (p < mon->end)
    {
        *(const char**)p = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(p + 4) = t;
        p += 0xc;
        mon->cur = p;
    }
}
static __forceinline void S00cfac20_calcAabb(const S00cfac20_Ray* rays, int count, S00cfac20_Aabb& aabb)
{
    hkVector4 mn;
    mn.setMin4(rays->from, rays->to);
    aabb.mn.m_vComponents = mn.m_vComponents;
    aabb.mx.setMax4(rays->from, rays->to);
    const S00cfac20_Ray* p = rays + 1;
    int i = count - 2;
    if (i >= 0)
    {
        do
        {
            mn.setMin4(mn, p->to);
            aabb.mx.setMax4(aabb.mx, p->to);
            mn.setMin4(mn, p->from);
            aabb.mx.setMax4(aabb.mx, p->from);
            ++p;
        } while (--i >= 0);
        aabb.mn.m_vComponents = mn.m_vComponents;
    }
}
// @fnv 0x00cfac20
// src: GUESS 0x00cfac20 (confidence: low)
void S00cfac20_Grp::ProcessEntries_00cfac20(S00cfac20_Builder* b, S00cfac20_Ray* rays, int count, void* ctx, char* out)
{
    char* dst;
    int j;
    {
        S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue(DAT_0126835c);
        char* p = mon->cur;
        if (p < mon->end)
        {
            *(const char**)p = DAT_010cc678;
            _ReadWriteBarrier();
            *(volatile unsigned*)&dst = (unsigned)__rdtsc();
            *(unsigned int*)(p + 4) = *(volatile unsigned*)&dst;
            p += 0xc;
            mon->cur = p;
        }
    }
    S00cfac20_Aabb aabb;
    S00cfac20_calcAabb(rays, count, aabb);
    char* mem = S00cfac20_alloc(static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance()), b->GetLogicalSize());
    b->init(&aabb, mem);
    S00cfac20_Ray* r = rays;
    dst = out;
    for (j = count - 1; j >= 0; --j)
    {
        RecordAndDispatch(b, r++, ctx, mem, dst);
        dst += 0x60;
    }
    S00cfac20_release(static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance()), mem);
    {
        S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue(DAT_0126835c);
        char* p = mon->cur;
        if (p < mon->end)
        {
            *(const char**)p = DAT_010c41f8;
            _ReadWriteBarrier();
            *(volatile unsigned*)&j = (unsigned)__rdtsc();
            *(unsigned int*)(p + 4) = *(volatile unsigned*)&j;
            p += 0xc;
            mon->cur = p;
        }
    }
}
}  // namespace fnv_00cfac20

typedef unsigned short hkUint16;

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}

template <class T> struct ReferenceCountedPointer
{
    T* m_pRetainedObject;

    __forceinline void operator=(const ReferenceCountedPointer& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->addReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
};

template <typename T> __forceinline T* hkMemoryAllocator::_bufAlloc(int& reqNumInOut)
{
    int n = reqNumInOut * sizeof(T);
    void* p = bufAlloc(n);
    reqNumInOut = n / int(sizeof(T));
    return static_cast<T*>(p);
}

template <typename T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
    bufFree(p, numElem * sizeof(T));
}

void* __cdecl hkMemoryRouter_getInstance();


__forceinline hkMemoryAllocator& containerHeap()
{
    return static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap();
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* array, int reqCapacity, int sizeElem);

template <typename T> __forceinline void hkConstructWithArray(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) T(tcopy[i]);
    }
}

template <typename T> __forceinline void hkCopy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
    {
        dst[i] = src[i];
    }
}

template <typename T> __forceinline void hkConstructWithArray2(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; ++i)
    {
        new (t) T(*tcopy);
        ++t;
        ++tcopy;
    }
}

template <typename T> __forceinline void hkCopy2(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
    {
        *dst = *src;
        ++dst;
        ++src;
    }
}

// hkArray<T>::operator= (hkArray.inl): copyFromArray(AllocatorType().get(this), a, hkIsPodType<T>::type()).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return containerHeap();
}
// Specialization of the shared IsPodType trait for the unsigned-short array element; no separate local trait.
template <> struct IsPodType<hkUint16> : public hkTypeIsPod   // hkTypeTraits.h HK_DEFINE_AS_POD_TYPE(hkUint16)
{
};
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
    }
}
template <typename T>
__forceinline hkArrayBase<T>& hkArrayBase<T>::copyFromArray(hkMemoryAllocator& kHeap, const hkArrayBase<T>& kSrc, hkTypeIsClass)
{
    int iWas = m_iElementCount;
    int iNow = kSrc.getSize();
    int iShared = iNow > iWas ? iWas : iNow;

    GrowArrayCapacity(kHeap, iNow);
    hkCopy(m_data, kSrc.m_data, iShared);
    hkConstructWithArray(m_data + iShared, iNow - iShared, kSrc.m_data + iShared);
    m_iElementCount = iNow;
    return *this;
}
template <typename T>
__forceinline hkArrayBase<T>& hkArrayBase<T>::copyFromArray(hkMemoryAllocator& kHeap, const hkArrayBase<T>& kSrc, hkTypeIsPod)
{
    if (getCapacity() < kSrc.getSize())
    {
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            kHeap._bufFree<T>(m_data, getCapacity());
        }
        int iCount = kSrc.getSize();
        m_data = kHeap._bufAlloc<T>(iCount);
        m_iCapacityState = iCount;
    }
    m_iElementCount = kSrc.getSize();
    hkCopy(m_data, kSrc.m_data, m_iElementCount);
    return *this;
}
template <typename T, typename A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray<T, A>& a)
{
    this->copyFromArray(AllocatorType().get(this), a, typename IsPodType<T>::type());
    return *this;
}

struct VectorTriple
{
    hkVector4 a, b, c;
};

struct VertexInfo
{
    hkUint16 m_index0;
    hkUint16 m_index1;
    VectorTriple m_v;
};

struct FaceInfo
{
    hkUint16 m_index0;
    hkUint16 m_index1;
    hkUint16 m_index2;
    hkUint16 m_index3;
    VectorTriple m_kPointA;
    VectorTriple m_kPointB;
};

struct ShapeData
{
    ReferenceCountedPointer<hkReferencedObject> m_kFirstReferencedObject;
    ReferenceCountedPointer<hkReferencedObject> m_kSecondReferencedObject;
    hkArray<VertexInfo> m_kVertices;
    hkArray<FaceInfo> m_faces;
    hkArray<hkUint16> m_ppIndices;
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    hkVector4 m_kCenterPosition;
    bool m_flag;
    int m_uiItemCount;

    ShapeData& AssignFields_00ce4ae0(const ShapeData& other);
};

// @fnv 0x00ce4ae0
// src: GUESS 0x00ce4ae0 (confidence: low)
ShapeData& ShapeData::AssignFields_00ce4ae0(const ShapeData& other)
{
    m_kFirstReferencedObject = other.m_kFirstReferencedObject;
    m_kSecondReferencedObject = other.m_kSecondReferencedObject;
    m_kVertices = other.m_kVertices;
    m_faces = other.m_faces;
    m_ppIndices = other.m_ppIndices;
    m_kMinimumCorner = other.m_kMinimumCorner;
    m_kMaximumCorner = other.m_kMaximumCorner;
    m_kCenterPosition = other.m_kCenterPosition;
    m_flag = other.m_flag;
    m_uiItemCount = other.m_uiItemCount;
    return *this;
}
