#ifndef _INCLUDED_MM2
// Exe 0x00d5bb10 FUN_00d5bb10: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#endif
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../include/Vec4.h"

__forceinline void Vec4::operator=(const Vec4& q)
{
    m_vComponents = q.m_vComponents;
}

// src/havok/common/internal/convexhull/hkgeometryutility_rtmfull_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkgeometryutility.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


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

// Initializes two context objects, looks up a1 in the first, and if found calls SetB with 0 and a2, then finishes.
// @fnv 0x00d5a5e0
void __cdecl InitAndSetB(void* a1, int a2)
{
    FUN_00d5a5e0_ctxB b;
    FUN_00d5a5e0_ctxA a;

    a.InitA();
    b.InitB();
    b.m_00 = 1;
    if (a.FindB(a1, &b) != -1)
    {
        a.SetB(0, a2);
    }
    a.FinishA();
}

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

// Initialises two context objects, sets a flag, looks up a1 in the first context and, if found, applies a2 and a3 and a float constant before finishing.
// @fnv 0x00d5a630
// src: HAVOK_LIB 0x00d5a630
void __cdecl hkGeometryUtility_createConvexGeometry(void* a1, int a2, int a3)
{
    FUN_00d5a630_ctxB b;
    FUN_00d5a630_ctxA a;

    a.InitA();
    b.InitB();
    b.m_00 = 1;
    if (a.FindB(a1, &b) != -1)
    {
        a.SetB(0, a2);
        a.SetF(DAT_0106ea1c, 0);
        a.SetC(a3);
    }
    a.FinishA();
}

struct S_00d5a6b0_Array
{
    Vec4* m_data;
    int m_iElementCount;
};

// Subtracts val from the w component of every element in the array.
// @fnv 0x00d5a6b0
void SubtractFromW(S_00d5a6b0_Array* pArray, float val)
{
    for (int i = 0; i < pArray->m_iElementCount; ++i)
        pArray->m_data[i].w -= val;
}

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

// @fnv 0x00d5c110
void __cdecl BuildGeometryFromShape(const void* shape, D5C110Geometry& aGeometry)
{
    D5C110VertexArray vertices;
    ProcessArg(shape, vertices);
    if (vertices.m_iElementCount > 0)
    {
        D5C110StridedVertices stridedVertices;
        stridedVertices.m_iStridedVertexCount = vertices.m_iElementCount;
        stridedVertices.m_kVertices = &vertices.m_data->x;
        stridedVertices.m_iVertexStride = sizeof(Vec4);
        InitAndSetB(stridedVertices, aGeometry);
    }
    else
    {
        aGeometry.m_iTriangleCount = 0;
        aGeometry.m_iStridedVertexCount = 0;
    }
    vertices.ClearAndRelease();
}

struct D5C110VertexArray;
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);

// @fnv 0x00d5a6a0
// src: XBOX_PDB 0x00d5a6a0
void __cdecl hkGeometryUtility_createVerticesFromPlaneEquations(const void* shape, D5C110VertexArray& vertices)
{
    ProcessArg(shape, vertices);
}

#include <math.h>
struct S00d5ad60_cls
{
    float m_f00;
    unsigned char S00d5ad60_call(float* other, float threshold);
};

// @fnv 0x00d5ad60
// src: HAVOK_LIB 0x00d5ad60
static __declspec(noinline) unsigned char approxEquals(S00d5ad60_cls* self, float* other, float threshold)
{
    float d = *other - self->m_f00;
    d = fabs(d);
    return d < threshold;
}

unsigned char S00d5ad60_cls::S00d5ad60_call(float* other, float threshold)
{
    return approxEquals(this, other, threshold);
}


#ifndef _INCLUDED_MM2
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
#endif
extern float DAT_01011d78;

// @fnv 0x00d5ad90
// src: GUESS 0x00d5ad90 (confidence: high)
static __declspec(noinline) int Hkgeometryutility_IsMaximumAbsoluteComponentNearOne(const float* pVec, float fTol)
{
    float a2 = fabs(pVec[2]);
    float a1 = fabs(pVec[1]);
    float a0 = fabs(pVec[0]);
    LocalM128 v = _mm_setr_ps(a0, a1, a2, DAT_01011d78);
    float fScaledValue = (v.m128_f32[0] > v.m128_f32[1]) ? v.m128_f32[0] : v.m128_f32[1];
    if (v.m128_f32[2] > fScaledValue)
        fScaledValue = v.m128_f32[2];
    float fDist = fabs((float)(fScaledValue - 1.0));
    if (fDist < fTol)
        return 1;
    return 0;
}

int __cdecl S00d5ad90_Wrap(const float* pVec, float fTol)
{
    return Hkgeometryutility_IsMaximumAbsoluteComponentNearOne(pVec, fTol);
}

struct S00d5c060_Src
{
    char* m_pData;
    int m_uiItemCount;
    int m_iElementIndex;
};

char* __cdecl AllocateWithHeader(D5C110Allocator* alloc, int size);
char* __cdecl hkMemoryRouter_easyFree(D5C110Allocator* owner, char* data);
void __cdecl Hkgeometryutility_ProcessEntries_00d5beb0(Vec4* self, char* data, int count, int flags, float scale);

// @fnv 0x00d5c060
// src: HAVOK_LIB 0x00d5c060
Vec4 hkGeometryUtility_createMinBoundingSphere(const S00d5c060_Src* src, float scale)
{
    Vec4 result;
    int count = src->m_uiItemCount;
    char* data = AllocateWithHeader(&hkMemoryRouter_getInstance().heap(), count * 16);
    int quad = src->m_iElementIndex / 4;
    Vec4* d = (Vec4*)data;
    for (int i = 0; i < src->m_uiItemCount; ++i)
    {
        d[i].x = ((const float*)src->m_pData)[i * quad];
        d[i].y = ((const float*)src->m_pData)[i * quad + 1];
        d[i].z = ((const float*)src->m_pData)[i * quad + 2];
    }
    Hkgeometryutility_ProcessEntries_00d5beb0(&result, data, src->m_uiItemCount, 0, scale);
    hkMemoryRouter_easyFree(&hkMemoryRouter_getInstance().heap(), data);
    return result;
}

namespace fnv_00d5d270 {

#ifndef _INCLUDED_MM2
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
#endif

extern float DAT_01013ea4;
extern float DAT_01011d78;
extern float DAT_01012068;
extern "C" int ae60_mix(int);
extern "C" void _ReadWriteBarrier(void);

struct S4
{
    int v;
    S4(int x) : v(x)
    {}
};

struct ObbVec
{
    LocalM128 q;
    float x() const
    {
        return q.m128_f32[0];
    }
    float y() const
    {
        return q.m128_f32[1];
    }
    float z() const
    {
        return q.m128_f32[2];
    }
};

struct ObbRot
{
    ObbVec c0;
    ObbVec c1;
    ObbVec c2;
};

struct ObbXf
{
    ObbVec c0;
    ObbVec c1;
    ObbVec c2;
    ObbVec c3;
};

struct ObbFrame
{
    ObbVec ext1;
    ObbVec ext0;
    ObbVec ctr1;
    ObbVec ctr0;
    ObbRot rot0;
    ObbRot rot1;
    ObbRot cov;
};

struct ObbTri
{
    int i0;
    int i1;
    int i2;
    int i3;
};

struct ObbGeom
{
    ObbVec* verts;
    int numVerts;
    int vcap;
    ObbTri* tris;
    int numTris;
    int tcap;

    ObbGeom() : verts(0), numVerts(0), vcap(0x80000000), tris(0), numTris(0), tcap(0x80000000)
    {}
    void FUN_00cce530();
};

struct ObbArr
{
    ObbVec* m_data;
    int m_iElementCount;
    int m_cap;
    char* m_pTrailingData;

    ObbArr() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
};

struct ObbFlag
{
    char c;
};

void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
bool __cdecl getIsBoxGeometry(void* geom, void* halfExtents, void* transform, float tolerance);
void __cdecl getMeanAndCovariance(void*, int, int, void*, void*, ObbFlag);
void __cdecl HkgeometryutilityGsEhscNogsNoehsc_ComputeValues_00d5ac50(void*, void*, void*, void*, void*);

// src: GUESS 0x00d5ae60 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5ae60(const char* verts, const char* mat, int count, int stride, S4 extents,
                                              S4 center)
{
    int n = count / 3;
    const char* p = verts;
    const char* end = p + n * 16;
    float acc = 0;
    while (p != end)
    {
        acc += *(const float*)p + *(const float*)mat;
        p += 16;
    }
    n = ae60_mix(n) + n;
    *(float*)extents.v = acc + *(const float*)(mat + 16) + (float)n;
    *(int*)center.v = stride;
}

// src: GUESS 0x00d5b990 (confidence: low)
static __declspec(noinline) float Hkgeometryutility_UpdateState_00d5b990(S4 verts, S4 count, S4 src, int steps, int stride, char* dest)
{
    *(int*)dest = stride + steps;
    int acc = verts.v + count.v + src.v + steps + stride + (int)dest;
    return (float)(acc + ae60_mix(acc));
}

// @fnv 0x00d5d270
// src: XBOX_PDB 0x00d5d270
void hkGeometryUtility_calcObb(const void* shape, ObbVec* outExt, ObbXf* outXf, int mode)
{
    ObbGeom geom;
    InitAndSetB(*(const D5C110StridedVertices*)shape, *(D5C110Geometry*)&geom);

    int nStack = geom.numTris * 3;
    ObbArr arr;
    D5C110MemoryRouter& router = hkMemoryRouter_getInstance();
    char* start = (char*)router.unk00;
    router.unk00 = (int)(start + ((nStack * 16 + 0x7f) & ~0x7f));
    arr.m_cap = nStack | 0x80000000;
    arr.m_data = (ObbVec*)start;
    arr.m_pTrailingData = start;

    int total = geom.numTris * 3;
    D5C110Allocator& heap = hkMemoryRouter_getInstance().heap();
    if ((arr.m_cap & 0x3fffffff) < total)
    {
        int cap = (arr.m_cap & 0x3fffffff) * 2;
        if (total >= cap)
            cap = total;
        hkArrayUtil__reserve(&heap, &arr.m_data, cap, 16);
    }
    arr.m_iElementCount = total;

    for (int i = 0; i < geom.numTris; i++)
    {
        arr.m_data[i * 3 + 0].q = geom.verts[geom.tris[i].i0].q;
        arr.m_data[i * 3 + 1].q = geom.verts[geom.tris[i].i1].q;
        arr.m_data[i * 3 + 2].q = geom.verts[geom.tris[i].i2].q;
    }

    if (getIsBoxGeometry(&geom, outExt, outXf, DAT_01013ea4))
    {
        char* saved = arr.m_pTrailingData;
        if (saved == (char*)arr.m_data)
            arr.m_iElementCount = 0;
        hkMemoryRouter_getInstance().unk00 = (int)saved;
        D5C110Allocator& alloc = hkMemoryRouter_getInstance().heap();
        arr.m_iElementCount = 0;
        if ((arr.m_cap & 0x80000000) == 0)
            alloc.ReturnMemory(arr.m_data, (arr.m_cap & 0x3fffffff) * 16);
        arr.m_cap = 0x80000000;
        arr.m_data = 0;
        geom.FUN_00cce530();
        return;
    }

    const char* data = (const char*)arr.m_data;
    int count = arr.m_iElementCount;

    ObbFrame f;
    f.rot0.c0.q = _mm_setr_ps(DAT_01012068, DAT_01011d78, DAT_01011d78, DAT_01011d78);
    f.rot0.c1.q = _mm_setr_ps(DAT_01011d78, DAT_01012068, DAT_01011d78, DAT_01011d78);
    f.rot0.c2.q = _mm_setr_ps(DAT_01011d78, DAT_01011d78, DAT_01012068, DAT_01011d78);

    Object_ProcessEntries_00d5ae60(data, (const char*)&f.rot0, count, 16, S4((int)&f.ext0), S4((int)&f.ctr0));
    float vol0 = f.ext0.y() * f.ext0.x() * f.ext0.z();
    ObbFlag flag;
    flag.c = 0;
    getMeanAndCovariance((void*)data, count, 16, &f.cov, &f.ctr1, flag);
    char ok;
    HkgeometryutilityGsEhscNogsNoehsc_ComputeValues_00d5ac50(&ok, &f.cov, &f.rot1.c0, &f.rot1.c1, &f.rot1.c2);
    Object_ProcessEntries_00d5ae60(data, (const char*)&f.rot1, count, 16, S4((int)&f.ext1), S4((int)&f.ctr1));
    float vol1 = f.ext1.y() * f.ext1.x() * f.ext1.z();

    if (mode == 2)
    {
        vol0 = Hkgeometryutility_UpdateState_00d5b990(S4((int)data), S4(count), S4((int)&f.rot0), 20, 16, (char*)&f.rot0);
        Object_ProcessEntries_00d5ae60(data, (const char*)&f.rot0, count, 16, S4((int)&f.ext0), S4((int)&f.ctr0));
        vol1 = Hkgeometryutility_UpdateState_00d5b990(S4((int)data), S4(count), S4((int)&f.rot1), 20, 16, (char*)&f.rot1);
        Object_ProcessEntries_00d5ae60(data, (const char*)&f.rot1, count, 16, S4((int)&f.ext1), S4((int)&f.ctr1));
    }

    LocalM128 pickedCtr;
    ObbRot* pickedRot;
    if (vol0 < vol1)
    {
        pickedCtr = f.ctr0.q;
        pickedRot = &f.rot0;
        outExt->q = f.ext0.q;
    }
    else
    {
        pickedCtr = f.ctr1.q;
        pickedRot = &f.rot1;
        outExt->q = f.ext1.q;
    }
    LocalM128 col0 = pickedRot->c0.q;
    LocalM128 col1 = pickedRot->c1.q;
    LocalM128 col2 = pickedRot->c2.q;
    _ReadWriteBarrier();
    outXf->c0.q = col0;
    outXf->c1.q = col1;
    outXf->c2.q = col2;
    outXf->c3.q = pickedCtr;

    char* saved = arr.m_pTrailingData;
    if (saved == (char*)arr.m_data)
        arr.m_iElementCount = 0;
    hkMemoryRouter_getInstance().unk00 = (int)saved;
    D5C110Allocator& alloc2 = hkMemoryRouter_getInstance().heap();
    arr.m_iElementCount = 0;
    if ((arr.m_cap & 0x80000000) == 0)
        alloc2.ReturnMemory(arr.m_data, (arr.m_cap & 0x3fffffff) * 16);
    arr.m_cap = 0x80000000;
    arr.m_data = 0;
    geom.FUN_00cce530();
}
}  // namespace fnv_00d5d270

extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" float _mm_cvtss_f32(LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);

extern const float DAT_01012054;

static __declspec(noinline) Vec4* Hkgeometryutilityfull_UpdateState_00d5bb10(Vec4* res, Vec4* p0, Vec4* p1, float t);

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

// @fnv 0x00d5beb0
// src: GUESS 0x00d5beb0 (confidence: low)
LocalM128* __cdecl Hkgeometryutility_ProcessEntries_00d5beb0(LocalM128* out, Vec4* pts, int count, int depth, float t)
{
    Vec4 rA;
    Vec4 rB;
    Vec4 rC;

    switch (depth)
    {
    case 0:
        *(LocalM128*)&rA = _mm_setzero_ps();
        ((float*)&rA)[3] = DAT_01012054;
        *out = *(LocalM128*)&rA;
        break;
    case 1:
        *(LocalM128*)&rA = pts[-1].v;
        ((float*)&rA)[3] = t;
        *out = *(LocalM128*)&rA;
        break;
    case 2:
        *out = *(LocalM128*)Hkgeometryutilityfull_UpdateState_00d5bb10(&rA, (Vec4*)&pts[-1], (Vec4*)&pts[-2], t);
        break;
    case 3:
        *out = *(LocalM128*)Object_ProcessAndReturnValue_00d5bb80(&rB, (Vec4*)&pts[-1], (Vec4*)&pts[-2], (Vec4*)&pts[-3], t);
        break;
    default:
        *out = *(LocalM128*)Object_ComputeValue_00d5bce0(&rC, (Vec4*)&pts[-1], (Vec4*)&pts[-2], (Vec4*)&pts[-3], (Vec4*)&pts[-4], t);
        return out;
    }

    for (int i = 0; i < count; ++i)
    {
        LocalM128 diff = _mm_sub_ps(pts[i].v, *out);
        LocalM128 sq = _mm_mul_ps(diff, diff);
        LocalM128 s1 = _mm_shuffle_ps(sq, sq, 0x55);
        LocalM128 s2 = _mm_shuffle_ps(sq, sq, 0xaa);
        LocalM128 sum = _mm_add_ss(s1, sq);
        sum = _mm_add_ss(s2, sum);
        float dist;
        _mm_store_ss(&dist, _mm_sqrt_ss(sum));

        if (dist > ((const float*)out)[3])
        {
            for (int k = i; k > 0; --k)
            {
                rA = *(Vec4*)&pts[k];
                pts[k].v = pts[k - 1].v;
                pts[k - 1].v = *(LocalM128*)&rA;
            }

            *out = *Hkgeometryutility_ProcessEntries_00d5beb0((LocalM128*)&rB, pts + 1, i, depth + 1, t);
        }
    }

    return out;
}

extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
class ObbScalar
{
    LocalM128 val;

  public:
    __forceinline ObbScalar(LocalM128 x) : val(x)
    {}
    __forceinline ObbScalar(float x) : val(_mm_load_ss(&x))
    {}
    __forceinline LocalM128 splat() const
    {
        return _mm_shuffle_ps(val, val, 0);
    }
    __forceinline LocalM128 quad() const
    {
        return val;
    }
    __forceinline operator float() const
    {
        float x;
        _mm_store_ss(&x, val);
        return x;
    }
};
class ObbAxis
{
    LocalM128 val;

  public:
    __forceinline ObbAxis()
    {}
    __forceinline ObbAxis(const ObbAxis& a) : val(a.val)
    {}
    __forceinline void operator=(const ObbAxis& a)
    {
        val = a.val;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&val)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&val)[i];
    }
    __forceinline void addScaled(const ObbScalar& s, const ObbAxis& a)
    {
        val = _mm_add_ps(val, _mm_mul_ps(s.splat(), a.val));
    }
    __forceinline void subtractScaled(const ObbScalar& s, const ObbAxis& a)
    {
        val = _mm_sub_ps(val, _mm_mul_ps(s.splat(), a.val));
    }
    __forceinline ObbScalar dot(const ObbAxis& a) const
    {
        LocalM128 p = _mm_mul_ps(val, a.val);
        LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    }
    __forceinline void cross(const ObbAxis& a, const ObbAxis& b)
    {
        LocalM128 u = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xc9), _mm_shuffle_ps(b.val, b.val, 0xd2));
        LocalM128 v = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xd2), _mm_shuffle_ps(b.val, b.val, 0xc9));
        val = _mm_sub_ps(u, v);
    }
    __forceinline void normalize()
    {
        LocalM128 half = _mm_load_ss(&kHalf), three = _mm_load_ss(&kThree), zero = _mm_load_ss(&kZero);
        LocalM128 d = dot(*this).quad();
        LocalM128 mask = _mm_cmpeq_ss(d, zero);
        LocalM128 r = _mm_rsqrt_ss(d);
        LocalM128 q = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(d, r), r)));
        LocalM128 inv = _mm_andnot_ps(mask, q);
        val = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), val);
    }
    static const float kHalf, kThree, kZero;
};
const float ObbAxis::kHalf = 0.5f, ObbAxis::kThree = 3.0f, ObbAxis::kZero = 0.0f;
struct ObbWord
{
    int v;
    ObbWord(int x) : v(x)
    {}
    operator int() const
    {
        return v;
    }
};

extern "C" int obbMix(int);
// src: GUESS 0x00d5ae60 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5ae60(const float* verts, int count, int stride, ObbWord ext,
                                              const ObbAxis* axes, ObbWord pos)
{
    int triangles = count / 3;
    const float* p = verts;
    const float* end = p + triangles * 4;
    float sum = 0.0f;
    while (p != end)
    {
        sum += p[0] + axes[0](0);
        p += 4;
    }
    int total = obbMix(triangles) + triangles;
    ((ObbAxis*)ext.v)->operator()(0) = sum + axes[1](0) + (float)total;
    ((ObbAxis*)pos.v)->operator()(0) = (float)stride;
}

// src: GUESS 0x00d5b0c0 (confidence: low)
static __declspec(noinline) float Object_ProcessAndReturnValue_00d5b0c0(const float* verts, int count, int stride, const ObbAxis* axes)
{
    ObbAxis tmp[3];
    tmp[0] = axes[0];
    tmp[1] = axes[1];
    tmp[0].normalize();
    float projection = axes[0].dot(axes[1]);
    tmp[1].subtractScaled(projection, axes[0]);
    tmp[1].normalize();
    tmp[2].cross(axes[0], axes[1]);
    tmp[2].normalize();
    ObbAxis position, extents;
    Object_ProcessEntries_00d5ae60(verts, count, stride, ObbWord((int)&extents), tmp, ObbWord((int)&position));
    return extents(1) * extents(0) * extents(2);
}
// src: GUESS 0x00d5b440 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5b440(const ObbAxis* axes, ObbAxis* direction, float step, ObbAxis* out)
{
    for (int i = 0; i < 2; ++i)
    {
        out[i] = axes[i];
        out[i].addScaled(step, direction[i]);
    }
    out[0].normalize();
    float projection = out[0].dot(out[1]);
    out[1].subtractScaled(projection, out[0]);
    out[1].normalize();
    out[2].cross(out[0], out[1]);
    out[2].normalize();
}
inline float obbRoot(float f)
{
    return (float)sqrt((double)f);
}
// @fnv 0x00d5b640
// src: GUESS 0x00d5b640 (confidence: low)
static __declspec(noinline) float Object_ProcessEntries_00d5b640(const float* vertexArray, int numVertices, int striding,
                                               const ObbAxis* axes, float stepIn, ObbAxis* direction, int maxIter)
{
    float fb = 0;
    float fc = 0;
    float a = 0;
    float fa = Object_ProcessAndReturnValue_00d5b0c0(vertexArray, numVertices, striding, axes);
    ObbAxis tempAxes[3];
    Object_ProcessEntries_00d5b440(axes, direction, stepIn, tempAxes);
    float fTemp = Object_ProcessAndReturnValue_00d5b0c0(vertexArray, numVertices, striding, tempAxes);
    float b, c;
    if (fTemp < fa)
    {
        b = stepIn;
        fb = fTemp;
        c = b;
        for (int i = 0; i < maxIter; i++)
        {
            c *= double(1.2f);
            Object_ProcessEntries_00d5b440(axes, direction, c, tempAxes);
            fc = Object_ProcessAndReturnValue_00d5b0c0(vertexArray, numVertices, striding, tempAxes);
            if (fb < fc)
                break;
            else
            {
                b = c;
                fb = fc;
            }
            if (i == maxIter - 1)
                return c;
        }
    }
    else
    {
        c = stepIn;
        fc = fTemp;
        b = c;
        for (int i = 0; i < maxIter; i++)
        {
            b = (a + b) * 0.5;
            Object_ProcessEntries_00d5b440(axes, direction, b, tempAxes);
            fb = Object_ProcessAndReturnValue_00d5b0c0(vertexArray, numVertices, striding, tempAxes);
            if (fb < fa && fb < fc)
                break;
            if (i == maxIter - 1)
                return -1.0f;
        }
    }
    if (a > b || b > c || fa < fb || fc < fb)
        return -1.0f;
    const float GoldenRatio = (3.0 - obbRoot(5.0f)) * 0.5;
    float lengthAb, lengthBc, x, fx;
    for (int i = 0; i < maxIter; i++)
    {
        lengthAb = b - a;
        lengthBc = c - b;
        if (lengthAb > lengthBc)
        {
            x = b - GoldenRatio * lengthAb;
            Object_ProcessEntries_00d5b440(axes, direction, x, tempAxes);
            fx = Object_ProcessAndReturnValue_00d5b0c0(vertexArray, numVertices, striding, tempAxes);
            if (fx < fb)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + GoldenRatio * lengthBc;
            Object_ProcessEntries_00d5b440(axes, direction, x, tempAxes);
            fx = Object_ProcessAndReturnValue_00d5b0c0(vertexArray, numVertices, striding, tempAxes);
            if (fx < fb)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}
const float* volatile obbVerts;
const ObbAxis* volatile obbAxes;
ObbAxis* volatile obbDir;
volatile int obbCount, obbStride, obbIter;
volatile float obbStep, obbAnswer;
void obbCaller()
{
    obbAnswer = Object_ProcessEntries_00d5b640(obbVerts, obbCount, obbStride, obbAxes, obbStep, obbDir, obbIter);
}

extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_set_ss(float);
extern const float DAT_010d1018 = 0.0000011920928955078125f;

struct S4
{
    int v;
    S4(int x) : v(x)
    {}
};

class AxisScalar
{
    LocalM128 value;

  public:
    AxisScalar(LocalM128 q) : value(q)
    {}
    AxisScalar(float f) : value(_mm_load_ss(&f))
    {}
    __forceinline LocalM128 quad() const
    {
        return value;
    }
    __forceinline LocalM128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
};

class Axis
{
    LocalM128 value;

  public:
    void operator=(const Axis& other)
    {
        value = other.value;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&value)[i];
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        value = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(float f)
    {
        AxisScalar s(f);
        value = s.splat();
    }
    __forceinline void mul4(const AxisScalar& s)
    {
        value = _mm_mul_ps(value, s.splat());
    }
    __forceinline void setMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_mul_ps(s.splat(), v.value);
    }
    __forceinline void addMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_add_ps(value, _mm_mul_ps(s.splat(), v.value));
    }
    __forceinline void subMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(s.splat(), v.value));
    }
    __forceinline void setAdd4(const Axis& a, const Axis& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void setSub4(const Axis& a, const Axis& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setCross(const Axis& a, const Axis& b)
    {
        LocalM128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        LocalM128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline AxisScalar dot3(const Axis& v) const
    {
        LocalM128 product = _mm_mul_ps(value, v.value);
        LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    }
    __forceinline AxisScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline AxisScalar lengthInverse3() const
    {
        const LocalM128 h = _mm_set_ss(0.5f);
        const LocalM128 t = _mm_set_ss(3.0f);
        const LocalM128 z = _mm_set_ss(0.0f);
        LocalM128 square = dot3(*this).quad();
        LocalM128 mask = _mm_cmpeq_ss(square, z);
        LocalM128 inv = _mm_rsqrt_ss(square);
        LocalM128 correction = _mm_mul_ss(_mm_mul_ss(h, inv), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(square, inv), inv)));
        return _mm_andnot_ps(mask, correction);
    }
    __forceinline void normalize3()
    {
        LocalM128 scale = lengthInverse3().splat();
        value = _mm_mul_ps(scale, value);
    }
};

__forceinline float axisSqrt(float f)
{
    AxisScalar s(f);
    return AxisScalar(_mm_sqrt_ss(s.quad()));
}
__forceinline float axisInvSqrt(float f)
{
    return 1.0f / axisSqrt(f);
}

// src: GUESS 0x00d5ae60 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5ae60(const float* data, int count, int stride, Axis& size, const Axis* axes,
                                              Axis& center)
{
    Axis lower;
    lower.SetAllComponents(3.40282e38f);
    Axis upper;
    upper.SetAllComponents(-3.40282e38f);
    const float* vertex = data;
    for (int tri = 0; tri < count / 3; ++tri)
    {
        Axis point;
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
    }
    Axis midpoint;
    midpoint.setAdd4(upper, lower);
    midpoint.mul4(0.5f);
    size.setSub4(upper, lower);
    size.mul4(0.5f);
    center.setMul4(midpoint(0), axes[0]);
    center.addMul4(midpoint(1), axes[1]);
    center.addMul4(midpoint(2), axes[2]);
}

// src: GUESS 0x00d5b0c0 (confidence: low)
static __declspec(noinline) float Object_ProcessAndReturnValue_00d5b0c0(const float* data, int count, int stride, const Axis* axes)
{
    Axis adjusted[3];
    adjusted[0] = axes[0];
    adjusted[1] = axes[1];
    adjusted[0].normalize3();
    float projection = axes[0].dot3(axes[1]);
    adjusted[1].subMul4(projection, axes[0]);
    adjusted[1].normalize3();
    adjusted[2].setCross(axes[0], axes[1]);
    adjusted[2].normalize3();
    Axis center;
    Axis size;
    Object_ProcessEntries_00d5ae60(data, count, stride, size, adjusted, center);
    return size(0) * size(1) * size(2);
}

// src: GUESS 0x00d5b2a0 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5b2a0(const float* data, int count, int stride, const Axis* axes, float delta,
                                              Axis* direction)
{
    Axis changed[3];
    changed[0] = axes[0];
    changed[1] = axes[1];
    float base = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, axes);
    float invDelta = 1 / delta;
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            changed[row](col) += delta;
            float volume = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            direction[row](col) = (volume - base) * invDelta;
            changed[row](col) = axes[row](col);
        }
        direction[row].mul4(-1.0f);
    }
    float normSquared = direction[0].lengthSquared3() + direction[1].lengthSquared3();
    if (normSquared > 1.0)
    {
        float invNorm = axisInvSqrt(normSquared);
        direction[0].mul4(invNorm);
        direction[1].mul4(invNorm);
    }
}

// src: GUESS 0x00d5b440 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5b440(const Axis* input, Axis* direction, float step, Axis* output)
{
    for (int axis = 0; axis < 2; ++axis)
    {
        output[axis] = input[axis];
        output[axis].addMul4(step, direction[axis]);
    }
    output[0].normalize3();
    float projection = output[0].dot3(output[1]);
    output[1].subMul4(projection, output[0]);
    output[1].normalize3();
    output[2].setCross(output[0], output[1]);
    output[2].normalize3();
}

// src: GUESS 0x00d5b640 (confidence: low)
static __declspec(noinline) float Object_ProcessEntries_00d5b640(const float* data, int count, int stride, const Axis* axes, float start,
                                               Axis* direction, int limit)
{
    float fb = 0, fc = 0;
    float a = 0;
    float fa = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, axes);
    Axis changed[3];
    Object_ProcessEntries_00d5b440(axes, direction, start, changed);
    float trial = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
    float b, c;
    if (fa > trial)
    {
        b = start;
        fb = trial;
        c = b;
        for (int iter = 0; iter < limit; ++iter)
        {
            c *= 1.2f;
            Object_ProcessEntries_00d5b440(axes, direction, c, changed);
            fc = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            if (fc > fb)
                break;
            else
            {
                b = c;
                fb = fc;
            }
            if (iter == limit - 1)
                return c;
        }
    }
    else
    {
        c = start;
        fc = trial;
        b = c;
        for (int iter = 0; iter < limit; ++iter)
        {
            b = (a + b) * 0.5;
            Object_ProcessEntries_00d5b440(axes, direction, b, changed);
            fb = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            if (fa > fb && fc > fb)
                break;
            if (iter == limit - 1)
                return -1.0f;
        }
    }
    if (!(a <= b && b <= c && fb <= fa && fb <= fc))
        return -1.0f;
    const float golden = (3.0 - axisSqrt(5.0f)) * 0.5;
    for (int iter = 0; iter < limit; ++iter)
    {
        float ab = b - a;
        float bc = c - b;
        float x, fx;
        if (bc < ab)
        {
            x = b - golden * ab;
            Object_ProcessEntries_00d5b440(axes, direction, x, changed);
            fx = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            if (fb > fx)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + golden * bc;
            Object_ProcessEntries_00d5b440(axes, direction, x, changed);
            fx = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            if (fb > fx)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}

// @fnv 0x00d5b990
// src: GUESS 0x00d5b990 (confidence: low)
static __declspec(noinline) float Hkgeometryutility_UpdateState_00d5b990(const float* data, int count, int stride, const Axis* initial,
                                               Axis* result, int limit)
{
    float delta = 0.0001f;
    float step = 0.001f;
    float volume = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, initial);
    result[0] = initial[0];
    result[1] = initial[1];
    result[2] = initial[2];
    Axis previous[3];
    Axis direction[2];
    for (int iter = 0; iter < limit; ++iter)
    {
        previous[0] = result[0];
        previous[1] = result[1];
        previous[2] = result[2];
        Object_ProcessEntries_00d5b2a0(data, count, stride, result, delta, direction);
        step = Object_ProcessEntries_00d5b640(data, count, stride, result, step, direction, limit);
        if (step < 0.0)
            break;
        Object_ProcessEntries_00d5b440(result, direction, step, result);
        float lastVolume = volume;
        volume = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, result);
        if (lastVolume < volume)
        {
            volume = lastVolume;
            result[0] = previous[0];
            result[1] = previous[1];
            result[2] = previous[2];
            break;
        }
        if (step < DAT_010d1018)
            break;
    }
    return volume;
}

const float* volatile probeData;
int volatile probeCount, probeStride, probeLimit;
Axis* volatile probeAxes;
Axis* volatile probeOutput;
volatile float probeSink;
void runProbe()
{
    probeSink = Hkgeometryutility_UpdateState_00d5b990(probeData, probeCount, probeStride, probeAxes, probeOutput, probeLimit);
}
#pragma optimize("", on)

extern float DAT_01016248;

namespace sphere_pair_build {

struct Scalar
{
    LocalM128 q;
    Scalar()
    {}
    Scalar(LocalM128 v) : q(v)
    {}
    explicit Scalar(const float& v) : q(_mm_load_ss(&v))
    {}
    LocalM128 spread() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
    float get() const
    {
        float r;
        _mm_store_ss(&r, q);
        return r;
    }
    Scalar root() const
    {
        return Scalar(_mm_sqrt_ss(q));
    }
};

inline void multiply(Vec4& vector, const Scalar& v)
{
    vector.v = _mm_mul_ps(v.spread(), vector.v);
}
inline Scalar dot(const Vec4& vector, const Vec4& v)
{
    LocalM128 sq = _mm_mul_ps(vector.v, v.v);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    return Scalar(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), xy));
}
inline float length(const Vec4& vector)
{
    return dot(vector, vector).root().get();
}
inline void setSub(Vec4& vector, const Vec4& a, const Vec4& b)
{
    vector.v = _mm_sub_ps(a.v, b.v);
}
inline void setAdd(Vec4& vector, const Vec4& a, const Vec4& b)
{
    vector.v = _mm_add_ps(a.v, b.v);
}

}

// @fnv 0x00d5bb10
// src: GUESS 0x00d5bb10 (confidence: low)
__declspec(noinline) Vec4* Hkgeometryutilityfull_UpdateState_00d5bb10(Vec4* result, Vec4* first, Vec4* second, float radius)
{
    using namespace sphere_pair_build;
    const Vec4* a = reinterpret_cast<const Vec4*>(first);
    Vec4* __restrict out = reinterpret_cast<Vec4*>(result);
    const Vec4* b = reinterpret_cast<const Vec4*>(second);
    const Vec4& base = *a;
    Vec4 delta;
    setSub(delta, *b, base);
    Scalar half(DAT_01016248);
    multiply(delta, half);
    float distance = length(delta);
    setAdd(*out, base, delta);
    out->w = distance + radius;
    return result;
}
