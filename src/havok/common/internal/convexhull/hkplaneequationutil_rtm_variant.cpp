#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
// src/havok/common/internal/convexhull/hkplaneequationutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkplaneequationutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/internal/convexhull/hkplaneequationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkplaneequationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Keep the original intrinsic layout: the CRT's extra byte arrays change VC9 /GS stack allocation.
#define _INCLUDED_MM2
// Exe 0x00dd6510 FUN_00dd6510: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_set_ss(float);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ps(const float*);
}
#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/hkMatrix3.h"
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

#include <math.h>
typedef LocalM128 hkQuadReal;
extern const hkQuadReal DAT_010c44d0;
inline hkSimdReal::hkSimdReal()
{}
inline hkSimdReal::hkSimdReal(float f)
{
    m_vValue = _mm_load_ss(&f);
}
inline hkSimdReal::hkSimdReal(const hkQuadReal& r) : m_vValue(r)
{}
inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
inline hkQuadReal hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdReal& r)
{
    m_vComponents = _mm_add_ps(_mm_mul_ps(r.broadcast(), b.m_vComponents), a.m_vComponents);
}
inline void hkVector4::setCross(const hkVector4& av, const hkVector4& bv)
{
    hkQuadReal a = _mm_load_ps(av.m_vComponents.m128_f32);
    hkQuadReal b = _mm_load_ps(bv.m_vComponents.m128_f32);
    hkQuadReal c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    hkQuadReal c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    m_vComponents = _mm_sub_ps(c0, c1);
}
inline void hkVector4::set(float x, float y, float z, float w)
{
    hkQuadReal xz = _mm_unpacklo_ps(_mm_set_ss(x), _mm_set_ss(z));
    hkQuadReal yw = _mm_unpacklo_ps(_mm_set_ss(y), _mm_set_ss(w));
    m_vComponents = _mm_unpacklo_ps(xz, yw);
}
inline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& a)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), a.m_vComponents);
}
inline void hkVector4::mul4(const hkSimdReal& r)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), m_vComponents);
}
inline void hkVector4::add4(const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}
inline float hkVector4::getW() const
{
    return m_vComponents.m128_f32[3];
}
inline hkSimdReal hkVector4::getComponent(int i) const
{
    return i == 0   ? hkSimdReal(_mm_shuffle_ps(m_vComponents, m_vComponents, 0))
           : i == 1 ? hkSimdReal(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55))
                    : hkSimdReal(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa));
}
inline void hkVector4::setNeg4(const hkVector4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
}
inline hkMatrix3::hkMatrix3()
{}
struct PointResult
{
    hkVector4 m_kPoint;
    int m_kPointA, m_kPointB, m_iThirdValue;
};
struct PlaneSet
{
    hkVector4* m_kPlaneArray;
    int m_iValue;
};
// src: GUESS 0x00dd6380 (confidence: low)
__declspec(noinline) int Object_ProcessAndReturnValue_00dd6380(PlaneSet* set, int a, int b, int c, PointResult* out)
{
    const hkVector4& pa = set->m_kPlaneArray[a];
    const hkVector4& pb = set->m_kPlaneArray[b];
    const hkVector4& pc = set->m_kPlaneArray[c];
    hkMatrix3 m;
    m.m_kColumn0.setCross(pb, pc);
    m.m_kColumn1.setCross(pc, pa);
    m.m_kColumn2.setCross(pa, pb);
    float det = pa.dot3(m.m_kColumn0);
    if (fabs(det) < 1.1920928955078125e-7f)
        return 1;
    float invDet = 1.0f / det;
    hkQuadReal negZero = _mm_set_ss(-0.0f);
    hkQuadReal dx = _mm_sub_ss(negZero, _mm_load_ss(&pa.m_vComponents.m128_f32[3]));
    hkQuadReal dy = _mm_sub_ss(negZero, _mm_load_ss(&pb.m_vComponents.m128_f32[3]));
    hkQuadReal dz = _mm_sub_ss(negZero, _mm_load_ss(&pc.m_vComponents.m128_f32[3]));
    hkQuadReal d = _mm_unpacklo_ps(_mm_unpacklo_ps(dx, dz), _mm_unpacklo_ps(dy, _mm_set_ss(0.0f)));
    hkQuadReal p = _mm_mul_ps(_mm_shuffle_ps(d, d, 0x55), m.m_kColumn1.m_vComponents);
    p = _mm_add_ps(p, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), m.m_kColumn0.m_vComponents));
    p = _mm_add_ps(p, _mm_mul_ps(_mm_shuffle_ps(d, d, 0xaa), m.m_kColumn2.m_vComponents));
    out->m_kPoint.m_vComponents = p;
    out->m_kPoint.m_vComponents = _mm_mul_ps(hkSimdReal(invDet).broadcast(), out->m_kPoint.m_vComponents);
    out->m_kPointA = a;
    out->m_kPointB = b;
    out->m_iThirdValue = c;
    if (a > b)
    {
        out->m_kPointA = b;
        out->m_kPointB = a;
    }
    return 0;
}
// @fnv 0x00dd6510
// src: GUESS 0x00dd6510 (confidence: low)
int hkVector4_ProcessEntries_00dd6510(const hkVector4* direction, PlaneSet* set, int first, int second, PointResult* neg, PointResult* pos)
{
    neg->m_kPointA = -1;
    neg->m_kPointB = -1;
    neg->m_iThirdValue = -1;
    pos->m_kPointA = -1;
    pos->m_kPointB = -1;
    pos->m_iThirdValue = -1;
    bool initialized = false;
    for (int i = 0; i < set->m_iValue; i++)
    {
        if (i == first || i == second)
            continue;
        PointResult p;
        if (Object_ProcessAndReturnValue_00dd6380(set, first, second, i, &p) != 0)
            continue;
        if (!initialized)
        {
            pos->m_kPoint.setAddMul4(p.m_kPoint, *direction, hkSimdReal(-100000.0f));
            neg->m_kPoint.setNeg4(pos->m_kPoint);
            initialized = true;
        }
        hkVector4 d;
        d.setSub4(pos->m_kPoint, p.m_kPoint);
        if (d.dot3(set->m_kPlaneArray[i]) > -1.1920928955078125e-7f)
        {
            pos->m_kPoint = p.m_kPoint;
            pos->m_kPointA = p.m_kPointA;
            pos->m_kPointB = p.m_kPointB;
            pos->m_iThirdValue = p.m_iThirdValue;
        }
        hkVector4 e;
        e.setSub4(neg->m_kPoint, p.m_kPoint);
        if (e.dot3(set->m_kPlaneArray[i]) > -1.1920928955078125e-7f)
        {
            neg->m_kPoint = p.m_kPoint;
            neg->m_kPointA = p.m_kPointA;
            neg->m_kPointB = p.m_kPointB;
            neg->m_iThirdValue = p.m_iThirdValue;
        }
    }
    if (neg->m_kPointA == -1)
    {
        if (pos->m_kPointA != -1)
        {
            neg->m_kPointA = pos->m_kPointA;
            neg->m_kPointB = pos->m_kPointB;
            neg->m_iThirdValue = pos->m_iThirdValue;
        }
        else
            return 1;
    }
    if (pos->m_kPointA == -1)
    {
        if (neg->m_kPointA == -1)
            return 1;
        pos->m_kPointA = neg->m_kPointA;
        pos->m_kPointB = neg->m_kPointB;
        pos->m_iThirdValue = neg->m_iThirdValue;
    }
    return 0;
}
