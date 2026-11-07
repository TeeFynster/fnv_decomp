// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl Deallocate(void*);
extern int DAT_010d9fc4;
struct FUN_00dee620
{
    void* m_pVTable;
    __thiscall FUN_00dee620(int testFlag);
};
extern "C" void __cdecl hkVector4_ProcessEntries_00dedf10(void*, void*, void*, void*, int, int);
void __cdecl hkGeometryProcessing_generateRandomDistribution(void* first, void* second, void* third, void* fourth);
struct FUN_00dee6b0_Class
{
    int unk00;
    float unk04;
    float GetUnk04(int testFlag);
};
extern int DAT_010cd664;
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00dee6c0_cls
{
    int m_vptr;

    FUN_00dee6c0_cls* FUN_00dee6c0(unsigned char acFlags);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_sub_ss(__m128 a, __m128 b);
    __m128 _mm_div_ss(__m128 a, __m128 b);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
    __m128 _mm_load_ps1(const float* p);
    void _mm_store_ss(float* p, __m128 a);
}
struct hkSimdReal
{
    __m128 m_vValue;

    hkSimdReal()
    {}
    hkSimdReal(const __m128& r) : m_vValue(r)
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};
__forceinline hkSimdReal operator/(const hkSimdReal& a, const hkSimdReal& b)
{
    return _mm_div_ss(a.m_vValue, b.m_vValue);
}
struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void sub4(const hkVector4& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdReal& r)
    {
        m_vComponents =
            _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents));
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        return _mm_add_ss(z, xySum);
    }
    __forceinline hkSimdReal lengthSquared3() const
    {
        return dot3(*this);
    }
};
extern const hkVector4 DAT_010c7160;
float __cdecl hkVector4_GetPointSegmentSquaredDistance(const hkVector4& a, const hkVector4& b, const hkVector4& c, float* out);
extern __m128 DAT_010c71d0;
struct FUN_00dee640_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_vec10;
    float m_fDist20;
    int unk24;
    int unk28;
    int unk2C;
    void* m_pTag30;
    float UpdateNearestDistance(void* pair);
};
extern __m128 DAT_01267e30;
struct Vertex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    __m128 m_vHitNormal;
};
struct Triangle
{
    unsigned int unk00;
    unsigned int unk04;
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    unsigned int unk20;
};
struct Edge
{
    Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    Edge(Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    Edge(unsigned int uid)
    {
        m_uiEdgeIndex = uid & 3;
        m_pkTriangle = (Triangle*)(uid & ~3u);
    }
    unsigned int uid() const
    {
        return (unsigned int)m_pkTriangle + m_uiEdgeIndex;
    }
    Edge link() const
    {
        return Edge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]);
    }
    void bind(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
    void bindSafe(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        if (other.m_pkTriangle)
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
};
struct PendingBlock
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
    int m_40;
    int m_44;
    unsigned int unk48;
    unsigned int unk4C;
};
struct Sub08_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    Vertex* PushFront(PendingBlock* out);
};
struct Sub20_cls
{
    Triangle* UpdateFields_00e241a0(Triangle* node);
};
struct FUN_00e19200_cls
{
    unsigned int unk00;
    unsigned int unk04;
    Sub08_cls m_08;
    Sub20_cls m_20;
    void SplitTriangleWithNewVertex(Triangle* a, const __m128* b, int c);
};
extern "C"
{
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_setr_ps(float, float, float, float);
}
extern __m128 DAT_01017d10;
extern float DAT_01011d78;
struct CubeVector
{
    __m128 lanes;
    __forceinline void sum(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_add_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void difference(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_sub_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void scale(const __m128& k)
    {
        lanes = _mm_mul_ps(k, lanes);
    }
    __forceinline int longestAxis() const
    {
        CubeVector magnitude;
        magnitude.lanes = _mm_and_ps(lanes, DAT_01017d10);
        const float* p = (const float*)&magnitude.lanes;
        if (p[0] < p[1])
            return p[1] < p[2] ? 2 : 1;
        return p[0] < p[2] ? 2 : 0;
    }
    __forceinline float component(int i) const
    {
        return ((const float*)&lanes)[i];
    }
};
struct CubeBox
{
    CubeVector lower;
    CubeVector upper;
    __forceinline void center(CubeVector& dst) const
    {
        dst.sum(lower, upper);
        dst.scale(DAT_010c71d0);
    }
    __forceinline void extent(CubeVector& dst) const
    {
        dst.difference(upper, lower);
        dst.scale(DAT_010c71d0);
    }
};
void __cdecl Hkgeometryprocessing_GetCubeBoundsFromLargestExtent(CubeBox* box);
#include <math.h>
extern const float DAT_0104da4c = 1.1920928955078125e-7f;
extern float DAT_0104da48;
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_load_ss(const float*);
float __cdecl hkVector4_GetClosestSegmentParameters(const hkVector4& firstStart, const hkVector4& firstEnd, const hkVector4& secondStart,
                           const hkVector4& secondEnd, float* firstParameter, float* secondParameter);
