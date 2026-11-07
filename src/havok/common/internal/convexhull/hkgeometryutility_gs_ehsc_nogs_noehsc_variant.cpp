
// src/havok/common/internal/convexhull/hkgeometryutility_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/convexhull/hkgeometryutility.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
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
struct S_00d5a6b0_Elem
{
    float x;
    float y;
    float z;
    float w;
};
struct S_00d5a6b0_Array
{
    S_00d5a6b0_Elem* m_data;
    int m_iElementCount;
};
void SubtractFromW(S_00d5a6b0_Array* arr, float val);
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
struct D5C110Vector4
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};
// hkArray<hkVector4> without a destructor (Havok was built without EH): explicit cleanup.
struct D5C110VertexArray
{
    D5C110Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D5C110VertexArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        D5C110Allocator& alloc = hkMemoryRouter_getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(D5C110Vector4));
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
void __cdecl BuildGeometryFromShape(const void* shape, D5C110Geometry& out);
struct D5C110VertexArray;
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);
void __cdecl hkGeometryUtility_createVerticesFromPlaneEquations(const void* shape, D5C110VertexArray& vertices);

#include <xmmintrin.h>
struct S_00d5ac50_R
{
    char v;
    S_00d5ac50_R()
    {}
};

struct __declspec(align(16)) S_00d5ac50_V
{
    float x, y, z, w;
};

struct S_00d5ac50_M
{
    S_00d5ac50_V c0, c1, c2;
};

struct S_00d5ac50_P
{
    S_00d5ac50_V* p;
    S_00d5ac50_V& get() const
    {
        return *p;
    }
};

extern __m128 DAT_010c44d0;

S_00d5ac50_R Object_ProcessEntries_00d5a6e0(S_00d5ac50_M& m, int iters);

static __forceinline __m128& S_q(S_00d5ac50_V& v)
{
    return reinterpret_cast<__m128&>(v);
}

static __forceinline void S_set(S_00d5ac50_V& v, float x, float y, float z, float w)
{
    S_q(v) = _mm_setr_ps(x, y, z, w);
}

static __forceinline float S_dot3(__m128 x)
{
    return _mm_cvtss_f32(_mm_add_ss(_mm_shuffle_ps(x, x, 0xaa), _mm_add_ss(_mm_shuffle_ps(x, x, 0x55), x)));
}

// @fnv 0x00d5ac50
// src: GUESS 0x00d5ac50 (confidence: low)
S_00d5ac50_R HkgeometryutilityGsEhscNogsNoehsc_ComputeValues_00d5ac50(S_00d5ac50_M& m, S_00d5ac50_V* p0, S_00d5ac50_V* p1, S_00d5ac50_V* p2)
{
    S_00d5ac50_R r = Object_ProcessEntries_00d5a6e0(m, 30);
    S_00d5ac50_V& o0 = *p0;
    S_00d5ac50_V& o1 = *p1;
    S_00d5ac50_V& o2 = *p2;
    if (r.v == 0)
    {
        S_set(o0, 1.0f, 0.0f, 0.0f, 0.0f);
        S_set(o1, 0.0f, 1.0f, 0.0f, 0.0f);
        S_set(o2, 0.0f, 0.0f, 1.0f, 0.0f);
        return r;
    }
    S_q(o0) = S_q(m.c0);
    S_q(o1) = S_q(m.c1);
    S_q(o2) = S_q(m.c2);
    __m128 b = S_q(o1);
    __m128 a = S_q(o0);
    __m128 cr = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                           _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    __m128 pr = _mm_mul_ps(cr, S_q(o2));
    float det;
    _mm_store_ss(&det, _mm_add_ss(_mm_shuffle_ps(pr, pr, 0xaa), _mm_add_ss(_mm_shuffle_ps(pr, pr, 0x55), pr)));
    if (det < 0.0f)
    {
        S_q(o2) = _mm_xor_ps(S_q(o2), DAT_010c44d0);
    }
    return r;
}
