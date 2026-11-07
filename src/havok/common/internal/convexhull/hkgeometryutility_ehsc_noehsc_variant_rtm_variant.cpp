#ifndef _INCLUDED_MM2
// Exe 0x00d5c1a0 _FUN_00d5c1a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#endif
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../include/Vec4.h"

// src/havok/common/internal/convexhull/hkgeometryutility_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkgeometryutility_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/internal/convexhull/hkgeometryutility_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/internal/convexhull/hkgeometryutility.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/convexhull/hkgeometryutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkgeometryutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d5a5e0_ctxA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;

    void InitA();
    int FindB(void* a1, void* b);
    void SetB(int zero, int a2);
    void FinishA();
};
struct FUN_00d5a5e0_ctxB
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

    void InitB();
};
void __cdecl InitAndSetB(void* a1, int a2);
struct FUN_00d5a630_ctxA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;

    void InitA();
    int FindB(void* a1, void* b);
    void SetB(int zero, int a2);
    void SetF(float f, int zero);
    void SetC(int a3);
    void FinishA();
};
struct FUN_00d5a630_ctxB
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

    void InitB();
};
extern float DAT_0106ea1c;
void __cdecl hkGeometryUtility_createConvexGeometry(void* a1, int a2, int a3);
struct S_00d5a6b0_Array
{
    Vec4* m_data;
    int m_iElementCount;
};
void SubtractFromW(S_00d5a6b0_Array* pArray, float val);
struct D5C110Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct D5C110MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D5C110Allocator* m_pStreamAllocator;

    D5C110Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" D5C110MemoryRouter& __cdecl hkMemoryRouter_getInstance();
// hkArray<hkVector4> without a destructor (Havok was built without EH): explicit cleanup.
struct D5C110VertexArray
{
    Vec4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D5C110VertexArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        D5C110Allocator& alloc = hkMemoryRouter_getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(Vec4));
    }
};
struct D5C110StridedVertices
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};
struct D5C110Geometry
{
    int unk00;
    int m_iStridedVertexCount;
    int unk08;
    int unk0C;
    int m_iTriangleCount;
};
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);
void __cdecl InitAndSetB(const D5C110StridedVertices& vertices, D5C110Geometry& out);
void __cdecl BuildGeometryFromShape(const void* shape, D5C110Geometry& aGeometry);
struct D5C110VertexArray;
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);
void __cdecl hkGeometryUtility_createVerticesFromPlaneEquations(const void* shape, D5C110VertexArray& vertices);
#include <math.h>
struct S00d5ad60_cls
{
    float m_f00;
    unsigned char S00d5ad60_call(float* other, float threshold);
};
static unsigned char approxEquals(S00d5ad60_cls* self, float* other, float threshold);
#ifndef _INCLUDED_MM2
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
#endif
extern float DAT_01011d78;
static int Hkgeometryutility_IsMaximumAbsoluteComponentNearOne(const float* pVec, float fTol);
int __cdecl S00d5ad90_Wrap(const float* pVec, float fTol);
struct S00d5c060_Src
{
    char* m_pData;
    int m_uiItemCount;
    int m_iElementIndex;
};
char* __cdecl AllocateWithHeader(D5C110Allocator* alloc, int size);
char* __cdecl hkMemoryRouter_easyFree(D5C110Allocator* owner, char* data);
void __cdecl Hkgeometryutility_ProcessEntries_00d5beb0(Vec4* self, char* data, int count, int flags, float scale);
Vec4 hkGeometryUtility_createMinBoundingSphere(const S00d5c060_Src* src, float scale);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" float _mm_cvtss_f32(LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern const float DAT_01012054;
// src: GUESS 0x00d5bb10 (confidence: low)
static __declspec(noinline) Vec4* Hkgeometryutilityfull_UpdateState_00d5bb10(Vec4* res, Vec4* p0, Vec4* p1, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(int)p1;
    res->w = a.y;
    return res;
}
// src: GUESS 0x00d5bb80 (confidence: low)
static __declspec(noinline) Vec4* Object_ProcessAndReturnValue_00d5bb80(Vec4* res, Vec4* p0, Vec4* p1, Vec4* p2, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(int)p1 + (float)(int)p2;
    res->w = a.y;
    return res;
}
// src: GUESS 0x00d5bce0 (confidence: low)
static __declspec(noinline) Vec4* Object_ComputeValue_00d5bce0(Vec4* res, Vec4* p0, Vec4* p1, Vec4* p2, Vec4* p3, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(int)p1 + (float)(int)p2 + (float)(int)p3;
    res->w = a.y;
    return res;
}
LocalM128* __cdecl Hkgeometryutility_ProcessEntries_00d5beb0(LocalM128* out, Vec4* pts, int count, int depth, float t);

namespace MeanCovIntrinsics {
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_load_ss(const float*);
}
}
inline LocalM128& Vec4::getQuad()
{
    return *(LocalM128*)this;
}
inline float& Vec4::operator()(int i)
{
    return ((float*)this)[i];
}
static inline float MeanCovGet(const LocalM128& value, int i)
{
    return ((const float*)&value)[i];
}
static __forceinline void MeanCovLoad(LocalM128& out, const float* p)
{
    out = _mm_setr_ps(p[0], p[1], p[2], 0.0f);
}
static inline float& MeanCovAt(LocalM128& value, int i)
{
    return ((float*)&value)[i];
}
struct MeanCovObbRot
{
    Vec4 c0, c1, c2;
    float& at(int row, int col)
    {
        return ((float*)this)[col * 4 + row];
    }
};
struct MeanCovObbFlag
{
    char c;
};
struct MeanCovObbStride
{
    int v;
};
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
struct MeanCovTrivialElements
{
};
struct MeanCovArrayLifecycle
{
    template <class T> static __forceinline void construct(T*, int, MeanCovTrivialElements)
    {}
    template <class T> static __forceinline void destruct(T*, int, MeanCovTrivialElements)
    {}
};
struct MeanCovArrayHeap
{
    __forceinline D5C110Allocator& get(const void*)
    {
        return hkMemoryRouter_getInstance().heap();
    }
};
template <class T> class MeanCovArrayBase
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline MeanCovArrayBase() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    __forceinline ~MeanCovArrayBase()
    {}
    __forceinline int capacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void reserve(D5C110Allocator& heap, int count)
    {
        int oldCapacity = capacity();
        if (oldCapacity < count)
        {
            int doubled = oldCapacity * 2;
            int chosen = count < doubled ? doubled : count;
            hkArrayUtil__reserve(&heap, this, chosen, sizeof(T));
        }
    }
    __forceinline T* expand(D5C110Allocator& heap, int count)
    {
        int previous = m_iElementCount;
        reserve(heap, m_iElementCount + count);
        MeanCovArrayLifecycle::construct(m_data + m_iElementCount, count, MeanCovTrivialElements());
        m_iElementCount += count;
        return m_data + previous;
    }
    __forceinline void clear()
    {
        MeanCovArrayLifecycle::destruct(m_data, m_iElementCount, MeanCovTrivialElements());
        m_iElementCount = 0;
    }
    __forceinline void release(D5C110Allocator& heap)
    {
        clear();
        if (!(m_cap & 0x80000000))
            heap.ReturnMemory(m_data, capacity() * sizeof(T));
        m_data = 0;
        m_cap = 0x80000000;
    }
};
template <class T, class Heap = MeanCovArrayHeap> class MeanCovTypedArray : public MeanCovArrayBase<T>
{
  public:
    __forceinline MeanCovTypedArray() : MeanCovArrayBase<T>()
    {}
    __forceinline ~MeanCovTypedArray()
    {
        ClearAndRelease();
    }
    __forceinline T* expandBy(int count)
    {
        return MeanCovArrayBase<T>::expand(Heap().get(this), count);
    }
    __forceinline void ClearAndRelease()
    {
        MeanCovArrayBase<T>::release(Heap().get(this));
    }
};
typedef MeanCovTypedArray<Vec4> MeanCovObbArr;
struct MeanCovObbRandom
{
    int seed0, seed1;
    void NextFloat4(Vec4& out);
};
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
static __forceinline LocalM128 MeanCovsplat(float x)
{
    LocalM128 r = MeanCovIntrinsics::_mm_load_ss(&x);
    return _mm_shuffle_ps(r, r, 0);
}
static __forceinline float MeanCovarea(LocalM128 e0, LocalM128 e1)
{
    LocalM128 t0 = _mm_shuffle_ps(e0, e0, 0xd2);
    LocalM128 t1 = _mm_shuffle_ps(e1, e1, 0xc9);
    LocalM128 p1 = _mm_mul_ps(t1, t0);
    LocalM128 u0 = _mm_shuffle_ps(e0, e0, 0xc9);
    LocalM128 u1 = _mm_shuffle_ps(e1, e1, 0xd2);
    LocalM128 cross = _mm_sub_ps(_mm_mul_ps(u1, u0), p1);
    LocalM128 sq = _mm_mul_ps(cross, cross);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    LocalM128 root = _mm_sqrt_ss(sum);
    float len;
    _mm_store_ss(&len, root);
    return len * 0.5;
}
// @fnv 0x00d5c1a0
// src: XBOX_PDB 0x00d5c1a0
extern "C" __declspec(noinline) void __cdecl getMeanAndCovariance(const void* vertices, int count, MeanCovObbStride stride,
                                                          MeanCovObbRot* covariance, Vec4* center,
                                                          MeanCovObbFlag perturb)
{
    int j, k;
    int n = count / 3;
    float totalArea = 0;
    LocalM128 zero;
    zero = _mm_setzero_ps();
    LocalM128 weighted;
    weighted = _mm_setzero_ps();
    MeanCovObbArr centroids;
    Vec4* all = centroids.expandBy(n);
    covariance->c0.getQuad() = zero;
    covariance->c1.getQuad() = zero;
    covariance->c2.getQuad() = zero;
    const char* p = (const char*)vertices;
    for (int t = 0; t < n; t++)
    {
        Vec4* centroid = &all[t];
        LocalM128 a, b, c;
        MeanCovLoad(a, (const float*)p);
        p += stride.v;
        MeanCovLoad(b, (const float*)p);
        p += stride.v;
        MeanCovLoad(c, (const float*)p);
        p += stride.v;
        LocalM128 av = a;
        LocalM128 bv = b;
        float triangleArea;
        if (perturb.c)
        {
            MeanCovObbRandom random;
            random.seed0 = count;
            random.seed1 = count;
            LocalM128 delta;
            random.NextFloat4((Vec4&)delta);
            LocalM128 moved;
            moved = _mm_sub_ps(MeanCovIntrinsics::_mm_add_ps(_mm_mul_ps(MeanCovsplat(0.01f), delta), av), bv);
            LocalM128 edge;
            edge = _mm_sub_ps(av, c);
            triangleArea = MeanCovarea(moved, edge);
        }
        else
        {
            LocalM128 moved;
            moved = _mm_sub_ps(av, bv);
            LocalM128 edge;
            edge = _mm_sub_ps(av, c);
            triangleArea = MeanCovarea(moved, edge);
        }
        if (triangleArea > 0)
        {
            totalArea += triangleArea;
            centroid->getQuad() = _mm_mul_ps(MeanCovIntrinsics::_mm_add_ps(MeanCovIntrinsics::_mm_add_ps(bv, av), c),
                                     MeanCovsplat(1.0f / 3.0f));
            {
                LocalM128 sa = MeanCovsplat(triangleArea);
                weighted = MeanCovIntrinsics::_mm_add_ps(_mm_mul_ps(sa, centroid->getQuad()), weighted);
            }
            const float* cj = (const float*)centroid;
            for (int j = 0; j < 3; j++, cj++)
            {
                for (int k = 0; k < 3; k++)
                {
                    covariance->at(j, k) +=
                        (9.0 * all[t](j) * all[t](k) + MeanCovAt(a, j) * MeanCovAt(a, k) + MeanCovGet(b, k) * MeanCovAt(b, j) + MeanCovGet(c, k) * MeanCovAt(c, j)) * triangleArea;
                }
            }
        }
        else
        {
            centroid->getQuad() = MeanCovIntrinsics::_mm_add_ps(bv, av);
            MeanCovIntrinsics::_mm_store_ps((float*)&all[t], MeanCovIntrinsics::_mm_add_ps(c, all[t].getQuad()));
            {
                LocalM128 s3 = MeanCovsplat(1.0f / 3.0f);
                MeanCovIntrinsics::_mm_store_ps((float*)centroid,
                                                _mm_mul_ps(s3, MeanCovIntrinsics::_mm_load_ps((const float*)centroid)));
            }
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    covariance->at(j, k) += MeanCovGet(b, k) * MeanCovAt(b, j) + MeanCovAt(a, j) * MeanCovAt(a, k) + MeanCovAt(c, k) * MeanCovAt(c, j);
                }
            }
        }
    }
    if (totalArea <= 0)
    {
        center->getQuad() = zero;
        covariance->c0.getQuad() = zero;
        covariance->c1.getQuad() = zero;
        covariance->c2.getQuad() = zero;
        covariance->c0(0) = 1;
        covariance->c1(1) = 1;
        covariance->c2(2) = 1;
    }
    else
    {
        float inv = 1.0f / totalArea;
        weighted = _mm_mul_ps(MeanCovsplat(inv), weighted);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                covariance->at(j, k) = covariance->at(j, k) / 12.0 - (MeanCovAt(weighted, j) * MeanCovAt(weighted, k)) * totalArea;
            }
        }
        center->getQuad() = weighted;
    }
}
