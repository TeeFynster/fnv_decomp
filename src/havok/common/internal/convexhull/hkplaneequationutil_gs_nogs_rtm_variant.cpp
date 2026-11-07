#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/havok/common/internal/convexhull/hkplaneequationutil_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkplaneequationutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/common/internal/convexhull/hkplaneequationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkplaneequationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Arg
{
    void* data;
    int count;
};
struct B
{
    int f0;
    int f1;
    int f2;
    int f3;

    void* hkgpConvexHull_BuildConfig_BuildConfig();
};
struct A
{
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;

    void FUN_00d76ca0();
    int ProcessEntries_00d774a0(void*, int, void*);
    void ProcessState_00d76120(int, int);
    void ReleaseStorage_00d76940();
};
int __cdecl ProcessArg(Arg* a, int second);

typedef ::__m128 LocalM128;
extern "C"
{
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_set_ps(float, float, float, float);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_set_ss(float);
    void _mm_store_ss(float*, LocalM128);
    double fabs(double);
}
extern const float DAT_0104da4c;
extern const float DAT_010c4990;
extern const float DAT_01011d78;
typedef LocalM128 hkQuadReal;
struct S00dd6380_hkSimdReal
{
    hkQuadReal m_vValue;
    __forceinline S00dd6380_hkSimdReal(const hkQuadReal& r) : m_vValue(r)
    {}
    __forceinline S00dd6380_hkSimdReal(const float& f) : m_vValue(_mm_load_ss(&f))
    {}
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};
struct S00dd6380_hkVector4
{
    hkQuadReal m_vComponents;
    __forceinline void operator=(const S00dd6380_hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setCross(const S00dd6380_hkVector4& v1, const S00dd6380_hkVector4& v2)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9)));
    }
    __forceinline S00dd6380_hkSimdReal dot3(const S00dd6380_hkVector4& a) const
    {
        const hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const hkQuadReal sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void set(const S00dd6380_hkSimdReal& a, const S00dd6380_hkSimdReal& b, const S00dd6380_hkSimdReal& c,
                           const S00dd6380_hkSimdReal& d)
    {
        hkQuadReal ac = _mm_unpacklo_ps(a.m_vValue, c.m_vValue);
        hkQuadReal bd = _mm_unpacklo_ps(b.m_vValue, d.m_vValue);
        m_vComponents = _mm_unpacklo_ps(ac, bd);
    }
    template <int I> __forceinline S00dd6380_hkSimdReal getSimdAt() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, I * 0x55);
    }
    __forceinline void setMul4(const S00dd6380_hkSimdReal& r, const S00dd6380_hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(r.m_vValue, v.m_vComponents);
    }
    __forceinline void addMul4(const S00dd6380_hkSimdReal& r, const S00dd6380_hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.m_vValue, v.m_vComponents));
    }
    __forceinline void mul4(float r)
    {
        hkQuadReal s = _mm_load_ss(&r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), m_vComponents);
    }
    __forceinline float operator()(int i) const
    {
        return m_vComponents.m128_f32[i];
    }
};
__forceinline void SetCrossPtr(S00dd6380_hkVector4* dst, const S00dd6380_hkVector4* v1, const S00dd6380_hkVector4* v2)
{
    dst->setCross(*v1, *v2);
}
// local form of hkMatrix3: 0x00dd6380 needs implicit construction and original vector aliases; shared form gives 422 bytes vs exe 397.
struct S00dd6380_hkMatrix3
{
    S00dd6380_hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};
template <typename T> __forceinline void hkSwap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
struct S00dd6380_PointResult
{
    S00dd6380_hkVector4 m_kPoint;
    int m_kPointA, m_kPointB, m_iThirdValue;
};
struct S00dd6380_PlaneSet
{
    S00dd6380_hkVector4* m_kPlaneArray;
    int m_iValue;
};

// Keep SP1 scalar negations separate from its packed-mask lowering.
__forceinline LocalM128 Dd6380NegativeDistances(const float& x, const float& y, const float& z)
{
    if (_MSC_FULL_VER >= 150030729)
    {
        const float nx = -x;
        const float ny = -y;
        const float nz = -z;
        return _mm_setr_ps(nx, ny, nz, 0.0f);
    }
    else
    {
        return _mm_setr_ps(-x, -y, -z, 0.0f);
    }
}
// @fnv 0x00dd6380
// src: GUESS 0x00dd6380 (confidence: low)
int Object_ProcessAndReturnValue_00dd6380(S00dd6380_PlaneSet* set, int a, int b, int c, S00dd6380_PointResult* out)
{
    const S00dd6380_hkVector4* planes = set->m_kPlaneArray;
    S00dd6380_hkMatrix3 m;
    m.m_kColumn0.setCross(planes[b], planes[c]);
    m.m_kColumn1.setCross(planes[c], planes[a]);
    SetCrossPtr(&m.m_kColumn2, &planes[a], &planes[b]);
    const float det = planes[a].dot3(m.m_kColumn0);
    if ((float)fabs(det) < 1.1920928955078125e-07f)
        return 1;
    const float invDet = 1.0f / det;
    S00dd6380_hkVector4 d;
    d.m_vComponents = Dd6380NegativeDistances(planes[a].m_vComponents.m128_f32[3], planes[b].m_vComponents.m128_f32[3],
                                              planes[c].m_vComponents.m128_f32[3]);
    S00dd6380_hkVector4 p;
    p.setMul4(d.getSimdAt<1>(), m.m_kColumn1);
    p.addMul4(d.getSimdAt<0>(), m.m_kColumn0);
    p.addMul4(d.getSimdAt<2>(), m.m_kColumn2);
    out->m_kPoint = p;
    out->m_kPoint.mul4(invDet);
    out->m_kPointA = a;
    out->m_kPointB = b;
    out->m_iThirdValue = c;
    if (a > b)
        hkSwap(out->m_kPointA, out->m_kPointB);
    return 0;
}
