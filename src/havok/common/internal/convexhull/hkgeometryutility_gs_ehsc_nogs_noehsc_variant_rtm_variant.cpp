// src/havok/common/internal/convexhull/hkgeometryutility_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkgeometryutility_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


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
S_00d5ac50_R HkgeometryutilityGsEhscNogsNoehsc_ComputeValues_00d5ac50(S_00d5ac50_M& m, S_00d5ac50_V* p0, S_00d5ac50_V* p1, S_00d5ac50_V* p2);

struct S00d5bb80_hkSimdReal
{
    __m128 m_vValue;
    S00d5bb80_hkSimdReal(__m128 x) : m_vValue(x)
    {}
    S00d5bb80_hkSimdReal(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

struct S00d5bb80_hkVector4
{
    __m128 m_vComponents;
    void setSub4(const S00d5bb80_hkVector4& a, const S00d5bb80_hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const S00d5bb80_hkVector4& v1, const S00d5bb80_hkVector4& v2)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    S00d5bb80_hkSimdReal lengthSquared3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    }
    S00d5bb80_hkSimdReal length3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2)));
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void addMul4(const S00d5bb80_hkSimdReal& r, const S00d5bb80_hkVector4& a)
    {
        m_vComponents =
            _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents));
    }
    void mul4(const S00d5bb80_hkSimdReal& r)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, _mm_shuffle_ps(r.m_vValue, r.m_vValue, 0));
    }
    void setAdd4(const S00d5bb80_hkVector4& a, const S00d5bb80_hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const S00d5bb80_hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    float& operator()(int i)
    {
        return ((float*)this)[i];
    }
};

struct S00d5bb80_hkSphere
{
    S00d5bb80_hkVector4 m_pos;
};

// @fnv 0x00d5bb80
// src: GUESS 0x00d5bb80 (confidence: low)
static __declspec(noinline) S00d5bb80_hkSphere
    Object_ProcessAndReturnValue_00d5bb80(const S00d5bb80_hkVector4& a, const S00d5bb80_hkVector4& b, const S00d5bb80_hkVector4& c, float radius)
{
    S00d5bb80_hkVector4 ab;
    ab.setSub4(b, a);
    S00d5bb80_hkVector4 ac;
    ac.setSub4(c, a);
    S00d5bb80_hkVector4 center = a;
    S00d5bb80_hkVector4 n;
    n.setCross(ab, ac);
    float inv = 0.5 / float(n.lengthSquared3());
    S00d5bb80_hkVector4 c1;
    c1.setCross(n, ab);
    S00d5bb80_hkVector4 c2;
    c2.setCross(ac, n);
    S00d5bb80_hkVector4 t;
    t.setZero4();
    t.addMul4(ac.lengthSquared3(), c1);
    t.addMul4(ab.lengthSquared3(), c2);
    t.mul4(inv);
    float len = t.length3();
    S00d5bb80_hkSphere s;
    s.m_pos.setAdd4(center, t);
    s.m_pos(3) = len + radius;
    return s;
}

S00d5bb80_hkVector4* volatile g_a;
S00d5bb80_hkVector4* volatile g_b;
S00d5bb80_hkVector4* volatile g_c;
volatile float g_r;
S00d5bb80_hkSphere g_out;
void CallTarget_d5bb80()
{
    g_out = Object_ProcessAndReturnValue_00d5bb80(*g_a, *g_b, *g_c, g_r);
    g_out = Object_ProcessAndReturnValue_00d5bb80(*g_a, *g_b, *g_c, g_r);
}
