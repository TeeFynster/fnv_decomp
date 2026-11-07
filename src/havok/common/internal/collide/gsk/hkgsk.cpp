#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/common/internal/collide/gsk/hkgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/gsk/hkgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void _ReadWriteBarrier(void);

// Keep the original intrinsic union: the CRT byte arrays change VC9 /GS instrumentation.
#define _INCLUDED_MM2
// Exe 0x00e4bbe0 FUN_00e4bbe0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#include "../../../../../../include/hkVector4.h"

extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_div_ss(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    void _mm_store_ss(float*, LocalM128);
}

typedef float hkReal;


__forceinline hkVector4::hkVector4(const hkVector4& v)
{
    unsigned* out = reinterpret_cast<unsigned*>(&m_vComponents);
    const unsigned* in = reinterpret_cast<const unsigned*>(&v.m_vComponents);
    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
    out[3] = in[3];
}


__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::add4(const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline int hkVector4::lessZeroXYZ() const
{
    return _mm_movemask_ps(_mm_cmplt_ps(m_vComponents, _mm_setzero_ps())) & 7;
}

__forceinline int hkVector4::lessZero3() const
{
    return _mm_movemask_ps(_mm_cmplt_ps(m_vComponents, _mm_setzero_ps())) & 7;
}

extern LocalM128 DAT_010c44d0;

__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}

static __forceinline int hkDot3LessZero(const hkVector4& a, const hkVector4& b)
{
    LocalM128 p = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    LocalM128 xyz = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
    return _mm_movemask_ps(xyz) & 1;
}

static __forceinline void hkTranspose3(hkVector4& c0, hkVector4& c1, hkVector4& c2)
{
    LocalM128 tmp = _mm_unpacklo_ps(c0.m_vComponents, c1.m_vComponents);
    LocalM128 ctmp = _mm_unpackhi_ps(c0.m_vComponents, c1.m_vComponents);
    c0.m_vComponents = _mm_movelh_ps(tmp, c2.m_vComponents);
    c1.m_vComponents = _mm_shuffle_ps(_mm_movehl_ps(c0.m_vComponents, tmp), c2.m_vComponents, 0xd4);
    c2.m_vComponents = _mm_shuffle_ps(ctmp, c2.m_vComponents, 0xe4);
}

static __forceinline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                                    const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
    hkVector4 c0;
    c0.setMul4(a0, b0);
    hkVector4 c1;
    c1.setMul4(a1, b1);
    hkVector4 c2;
    c2.setMul4(a2, b2);
    hkTranspose3(c0, c1, c2);
    dotsOut.setAdd4(c0, c1);
    dotsOut.add4(c2);
}

template <class T> static __forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

struct TriangleVerts
{
    hkVector4 m_kVertices[3];
    hkVector4 m_extra30;
    hkVector4 m_extra40;
    hkVector4 m_extra50;
};

struct TriangleSolver
{
    hkVector4 m_barycentric;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_flipped;
    hkVector4 m_kPoint;
    hkVector4 m_unk30;
    hkVector4 m_unk40;
    hkVector4 m_unk50;
    hkVector4 m_unk60;
    hkVector4 m_unk70;
    hkVector4 m_unk80;
    hkVector4 m_unk90;
    hkVector4 m_kSmartReference;

    int ComputeTriangleBarycentricTerms(const hkVector4& p, TriangleVerts& tri, hkVector4& normalOut);
};

// Computes three dot products into m_barycentric, stores the normal, and may flip the winding and swap values when mask is 7.
// @fnv 0x00e4da90
// src: GUESS 0x00e4da90 (confidence: medium)
int TriangleSolver::ComputeTriangleBarycentricTerms(const hkVector4& p, TriangleVerts& tri, hkVector4& normalOut)
{
    hkVector4 e0;
    e0.setSub4(tri.m_kVertices[2], tri.m_kVertices[1]);
    hkVector4 e1;
    e1.setSub4(tri.m_kVertices[0], tri.m_kVertices[2]);
    hkVector4 e2;
    e2.setSub4(tri.m_kVertices[1], tri.m_kVertices[0]);

    hkVector4 normal;
    normal.setCross(e0, e1);

    hkVector4 d1;
    d1.setSub4(p, tri.m_kVertices[1]);
    hkVector4 d2;
    d2.setSub4(p, tri.m_kVertices[2]);
    hkVector4 d0;
    d0.setSub4(p, tri.m_kVertices[0]);

    hkVector4 c0;
    c0.setCross(d1, e0);
    hkVector4 c1;
    c1.setCross(d2, e1);
    hkVector4 c2;
    c2.setCross(d0, e2);

    dot3_3vs3(c0, normal, c1, normal, c2, normal, m_barycentric);

    int mask = m_barycentric.lessZeroXYZ();
    normalOut = normal;
    if (mask == 7)
    {
        hkVector4 diff;
        diff.setSub4(m_kPoint, m_kSmartReference);
        if (hkDot3LessZero(diff, normal))
        {
            normal.setNeg4(normal);
            hkSwap(tri.m_kVertices[0], tri.m_kVertices[1]);
            _ReadWriteBarrier();
            normalOut = normal;
            hkSwap(m_barycentric.m_vComponents.m128_f32[0], m_barycentric.m_vComponents.m128_f32[1]);
            hkVector4* __restrict pExtra = &tri.m_extra40;
            hkSwap(pExtra[0], pExtra[1]);
            m_flipped = 1;
        }
    }
    return mask;
}

static inline void dot3_3vs3Direct(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                             const hkVector4& a2, const hkVector4& b2, hkVector4& out)
{
    LocalM128 d0 = _mm_mul_ps(a0.m_vComponents, b0.m_vComponents);
    LocalM128 d1 = _mm_mul_ps(a1.m_vComponents, b1.m_vComponents);
    LocalM128 d2 = _mm_mul_ps(a2.m_vComponents, b2.m_vComponents);
    {
        LocalM128 low, high;
        low = _mm_unpacklo_ps(d0, d1);
        high = _mm_shuffle_ps(_mm_unpackhi_ps(d0, d1), d2, 0xe4);
        d0 = _mm_movelh_ps(low, d2);
        d1 = _mm_shuffle_ps(_mm_movehl_ps(d0, low), d2, 0xd4);
        d2 = high;
    }
    out.m_vComponents = _mm_add_ps(_mm_add_ps(d0, d1), d2);
}

// Computes three dot products of cross products with the normal, stores them, and returns a bitmask of negative first three components.
// @fnv 0x00e4dc70
// src: GUESS 0x00e4dc70 (confidence: medium)
int hkVector4::GetTriangleEdgeSignMask(const hkVector4& point, const hkVector4* apTriangle, void*)
{
    const hkVector4& v0 = apTriangle[0];
    const hkVector4& v1 = apTriangle[1];
    const hkVector4& v2 = apTriangle[2];
    hkVector4 e0;
    e0.setSub4(v2, v1);
    hkVector4 e1;
    e1.setSub4(v0, v2);
    hkVector4 e2;
    e2.setSub4(v1, v0);
    hkVector4 n;
    n.setCross(e0, e1);
    hkVector4 p1;
    p1.setSub4(point, v1);
    hkVector4 p2;
    p2.setSub4(point, v2);
    hkVector4 p0;
    p0.setSub4(point, v0);
    hkVector4 c0;
    c0.setCross(p1, e0);
    hkVector4 c1;
    c1.setCross(p2, e1);
    hkVector4 c2;
    c2.setCross(p0, e2);
    dot3_3vs3Direct(c0, n, c1, n, c2, n, *this);
    return lessZero3();
}


struct Out
{
    int* p;
    Out(int* a) : p(a)
    {}
};
static const LocalM128 one4 = {1, 1, 1, 1};

struct Scalar
{
    LocalM128 q;
    Scalar()
    {}
    Scalar(const LocalM128& a) : q(a)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, q);
        return value;
    }
    LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
inline Scalar operator*(const Scalar& a, const Scalar& b)
{
    return _mm_mul_ss(a.q, b.q);
}
inline Scalar operator-(const Scalar& a, const Scalar& b)
{
    return _mm_sub_ss(a.q, b.q);
}
inline Scalar operator/(const Scalar& a, const Scalar& b)
{
    return _mm_div_ss(a.q, b.q);
}
static __forceinline Scalar vectorDot3(const hkVector4& a, const hkVector4& b)
{
    LocalM128 p = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    LocalM128 t = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), t);
}

static __forceinline void vectorInterpolate(hkVector4& out, const hkVector4& a, const hkVector4& b, const Scalar& f)
{
    LocalM128 t = f.broadcast();
    LocalM128 s = _mm_sub_ps(one4, t);
    out.m_vComponents = _mm_add_ps(_mm_mul_ps(s, a.m_vComponents), _mm_mul_ps(t, b.m_vComponents));
}

static __forceinline Scalar vectorComponent(const hkVector4& vector, int i)
{
    switch (i)
    {
    case 0:
        return vector.m_vComponents;
    case 1:
        return _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0x55);
    case 2:
        return _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0xaa);
    default:
        return _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0xff);
    }
}

static __forceinline void Swap(hkVector4& a, hkVector4& b)
{
    hkVector4 saved = a;
    a = b;
    b = saved;
}
static __forceinline bool ComparePlane(const hkVector4& oldValue, const hkVector4& newValue, int i, int j)
{
    Scalar oldI = vectorComponent(oldValue, i);
    Scalar oldJ = vectorComponent(oldValue, j);
    Scalar deltaI = vectorComponent(newValue, i) - oldI;
    Scalar deltaJ = vectorComponent(newValue, j) - oldJ;
    return float(oldJ * deltaI) > float(oldI * deltaJ);
}

struct Shape
{
    hkVector4 points[4];
    hkVector4 anchors[3];
};
struct Clip
{
    hkVector4 point;
    hkVector4 separation;
    float distance;
};
struct Both
{
    Clip first;
    Clip second;
};
extern "C" int hkLineSegmentUtil_closestLineSegLineSeg(Shape*, const hkVector4*, const hkVector4*, const hkVector4*, Clip*);

static __forceinline void ThreeDots(const hkVector4& first, const hkVector4& firstWeight, const hkVector4& second, const hkVector4& secondWeight,
                                    const hkVector4& third, const hkVector4& thirdWeight, hkVector4& out)
{
    register LocalM128 products0 = _mm_mul_ps(first.m_vComponents, firstWeight.m_vComponents);
    register LocalM128 products1 = _mm_mul_ps(second.m_vComponents, secondWeight.m_vComponents);
    register LocalM128 products2 = _mm_mul_ps(third.m_vComponents, thirdWeight.m_vComponents);
    LocalM128 lower = _mm_unpacklo_ps(products0, products1);
    LocalM128 upper = _mm_shuffle_ps(_mm_unpackhi_ps(products0, products1), products2, 0xe4);
    products0 = _mm_movelh_ps(lower, products2);
    products1 = _mm_shuffle_ps(_mm_movehl_ps(products0, lower), products2, 0xd4);
    products2 = upper;
    out.m_vComponents = _mm_add_ps(_mm_add_ps(products0, products1), products2);
}

static __forceinline int mask(const hkVector4& p, const Shape* b)
{
    hkVector4 e0, e1, e2, n, d0, d1, d2, c0, c1, c2;
    e0.setSub4(b->points[2], b->points[1]);
    e1.setSub4(b->points[0], b->points[2]);
    e2.setSub4(b->points[1], b->points[0]);
    n.setCross(e0, e1);
    d0.setSub4(p, b->points[1]);
    d1.setSub4(p, b->points[2]);
    d2.setSub4(p, b->points[0]);
    c0.setCross(d0, e0);
    c1.setCross(d1, e1);
    c2.setCross(d2, e2);
    hkVector4 sum;
    ThreeDots(c0, n, c1, n, c2, n, sum);
    return _mm_movemask_ps(_mm_cmplt_ps(sum.m_vComponents, _mm_setzero_ps())) & 7;
}
static __forceinline void ReplaceSelected(hkVector4& point, hkVector4& anchor, const hkVector4& newPoint, const hkVector4& newAnchor, int* count)
{
    point = newPoint;
    anchor = newAnchor;
    *count = 2;
}

static __forceinline void CollapseFirst(Shape* shape, const hkVector4& point, int* count)
{
    *count = 1;
    shape->points[0] = point;
    shape->anchors[0] = shape->anchors[1];
}

struct State
{
    hkVector4 origin;
    int m10, m14, m18, m1c;
    hkVector4 m20, m30, m40, m50, m60, m70, m80, m90, ma0, mb0, mc0, md0, me0, mf0, m100, m110;
    hkVector4 direction;
    int ComputeTriangleBarycentricTerms(Shape*, Shape*, hkVector4*);
    int GetTriangleEdgeSignMask(hkVector4*, Shape*, hkVector4*);
    int ProcessAndReturnValue_00e4bbe0(Shape*, Shape*, int*, int*, unsigned char, int);
};
// Branches on flag, updates shape points and anchors, writes through out1 or out2 on selected paths, and returns status values.
// @fnv 0x00e4bbe0
// src: GUESS 0x00e4bbe0 (confidence: low)
int State::ProcessAndReturnValue_00e4bbe0(Shape* apShapeA, Shape* apShapeB, int* __restrict apOutCount1, int* __restrict apOutCount2,
                        unsigned char flag, int val)
{
    if (flag)
    {
        hkVector4 edge0, edge1, normal;
        edge0.setSub4(apShapeB->points[1], apShapeB->points[2]);
        edge1.setSub4(apShapeB->points[0], apShapeB->points[2]);
        normal.setCross(edge0, edge1);
        hkVector4 d0;
        d0.setSub4(apShapeA->points[0], apShapeB->points[0]);
        Scalar s0 = vectorDot3(d0, normal);
        d0.setSub4(apShapeA->points[1], apShapeB->points[0]);
        Scalar s1 = vectorDot3(d0, normal);
        if (_mm_movemask_ps((s0 * s1).q) & 1)
        {
            Scalar t = s0 / (s0 - s1);
            hkVector4 p;
            vectorInterpolate(p, apShapeA->points[0], apShapeA->points[1], t);
            if (mask(p, apShapeB) == 7)
                return 1;
        }
        else
        {
            if (float(s0 * s0) > float(s1 * s1))
            {
                Swap(apShapeA->points[0], apShapeA->points[1]);
                Swap(apShapeA->anchors[0], apShapeA->anchors[1]);
            }
            if (ComputeTriangleBarycentricTerms(apShapeA, apShapeB, &direction) == 7)
            {
                *apOutCount1 = 1;
                return 0;
            }
        }
        hkVector4 diff;
        diff.setSub4(apShapeA->points[1], apShapeA->points[0]);
        Clip clip0, clip1;
        Clip* later = &clip1;
        hkLineSegmentUtil_closestLineSegLineSeg(apShapeA, &diff, &apShapeB->points[2], &edge0, &clip0);
        hkLineSegmentUtil_closestLineSegLineSeg(apShapeA, &diff, &apShapeB->points[2], &edge1, later);
        int index = clip0.distance > clip1.distance ? 1 : 0;
        ReplaceSelected(apShapeB->points[index], apShapeB->anchors[index], apShapeB->points[2], apShapeB->anchors[2],
                        apOutCount2);
        return 2;
    }
    else
    {
        hkVector4 saved = origin;
        hkVector4* end = &apShapeA->points[0];
        hkVector4 d0;
        d0.setSub4(*end, apShapeB->points[0]);
        Scalar s0 = vectorDot3(d0, direction);
        ++end;
        d0.setSub4(*end, apShapeB->points[0]);
        Scalar s1 = vectorDot3(d0, direction);
        if (_mm_movemask_ps((s0 * s1).q) & 1)
        {
            hkVector4 p;
            vectorInterpolate(p, apShapeA->points[0], *end, s0 / (s0 - s1));
            if (mask(p, apShapeB) == 7)
                return 1;
        }
        int r = GetTriangleEdgeSignMask(end, apShapeB, &direction);
        if (r == 7)
        {
            CollapseFirst(apShapeA, *end, apOutCount1);
            m14 = val;
            return 0;
        }
        *apOutCount2 = 2;
        if (r == 6)
            goto replace0;
        if (r == 5)
            goto replace1;
        if (r == 3)
            goto done;
        if (r == 1)
        {
            if (ComparePlane(saved, origin, 1, 2))
                goto done;
            goto replace1;
        }
        if (r == 2)
        {
            if (ComparePlane(saved, origin, 2, 0))
                goto replace0;
            goto done;
        }
        else if (r == 4)
        {
            if (ComparePlane(saved, origin, 0, 1))
                goto replace1;
        }
    replace0:
        apShapeB->points[0] = apShapeB->points[2];
        apShapeB->anchors[0] = apShapeB->anchors[2];
    done:
        return 2;
    replace1:
        apShapeB->points[1] = apShapeB->points[2];
        apShapeB->anchors[1] = apShapeB->anchors[2];
        return 2;
    }
}
