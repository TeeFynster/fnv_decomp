// src/havok/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Baseline from an unnamed contributor, 2026-10-28, packet score 58 (unverified).
// The inherited volatile-global caller is replaced by an ordinary argument-forwarding caller.
// No unverified non-aliasing qualifier is imposed on the result pointer.
// Exe 0x00e62740 FUN_00e62740: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ps(const float*);
    int _mm_movemask_ps(LocalM128);
    float _mm_cvtss_f32(LocalM128);
}
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern const LocalM128 DAT_010c44d0;
struct Matrix;
struct Scalar
{
    LocalM128 v;
    Scalar(LocalM128 x) : v(x)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, v);
        return value;
    }
};
// hkVector4 stand-in with the unit's own inline setNeg4/_setRotatedInverseDir/_setTransformedPos/setSub4/dot3/getSimdAt bodies over a local __m128 (Matrix = hkTransform).
struct CvxDistVector4
{
    union
    {
        LocalM128 v;
        struct
        {
            float x, y, z, w;
        };
    };
    CvxDistVector4()
    {}
    CvxDistVector4(const CvxDistVector4& a) : v(a.v)
    {}
    void operator=(const CvxDistVector4& a)
    {
        v = a.v;
    }
    void negative(const CvxDistVector4& n)
    {
        v = _mm_xor_ps(n.v, DAT_010c44d0);
    }
    void inv(const Matrix& m, const CvxDistVector4& n);
    void point(const Matrix& m, const CvxDistVector4& b);
    void difference(const CvxDistVector4& a, const CvxDistVector4& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    Scalar dot(const CvxDistVector4& n) const
    {
        LocalM128 p = _mm_mul_ps(v, n.v);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return Scalar(_mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy));
    }
    Scalar at(int i) const
    {
        if (i == 0)
            return Scalar(v);
        if (i == 1)
            return Scalar(_mm_shuffle_ps(v, v, 0x55));
        if (i == 2)
            return Scalar(_mm_shuffle_ps(v, v, 0xaa));
        return Scalar(_mm_shuffle_ps(v, v, 0xff));
    }
    void set(float a, float b, float c, float d)
    {
        v = _mm_setr_ps(a, b, c, d);
    }
};
struct Matrix
{
    CvxDistVector4 row0, row1, row2, row3;
};
__forceinline void CvxDistVector4::inv(const Matrix& m, const CvxDistVector4& n)
{
    LocalM128 a = m.row0.v, b = m.row1.v, c = m.row2.v;
    LocalM128 low = _mm_unpacklo_ps(a, b);
    LocalM128 high = _mm_shuffle_ps(_mm_unpackhi_ps(a, b), c, 0xe4);
    a = _mm_movelh_ps(low, c);
    b = _mm_shuffle_ps(_mm_movehl_ps(a, low), c, 0xd4);
    c = high;
    LocalM128 x = _mm_shuffle_ps(n.v, n.v, 0);
    LocalM128 px = _mm_mul_ps(a, x);
    LocalM128 y = _mm_shuffle_ps(n.v, n.v, 0x55);
    LocalM128 py = _mm_mul_ps(b, y);
    LocalM128 z = _mm_shuffle_ps(n.v, n.v, 0xaa);
    LocalM128 pz = _mm_mul_ps(c, z);
    v = _mm_add_ps(_mm_add_ps(px, py), pz);
}
__forceinline void CvxDistVector4::point(const Matrix& m, const CvxDistVector4& b)
{
    LocalM128 x = _mm_shuffle_ps(b.v, b.v, 0);
    LocalM128 px = _mm_mul_ps(m.row0.v, x);
    LocalM128 y = _mm_shuffle_ps(b.v, b.v, 0x55);
    LocalM128 py = _mm_mul_ps(m.row1.v, y);
    LocalM128 z = _mm_shuffle_ps(b.v, b.v, 0xaa);
    LocalM128 pz = _mm_mul_ps(m.row2.v, z);
    v = _mm_add_ps(_mm_add_ps(px, py), _mm_add_ps(pz, m.row3.v));
}
struct Shape
{
    virtual void reserved() = 0;
    virtual void transform(const CvxDistVector4*, CvxDistVector4*) = 0;
};
struct Result
{
    CvxDistVector4 pointA, pointB, localB, plane;
};
static void Object_UpdateFields_00e625c0(const Matrix* matrix, Shape* shape, Shape* other, const CvxDistVector4* normal, Result* result);
void ProjectShapes(const Matrix* matrix, Shape* shape, Shape* other, const CvxDistVector4* normal, Result* result);

#include <string.h>

#include <math.h>

extern const float DAT_01017d00 = 0.001f;

extern "C" ::LocalM128(_mm_setzero_ps)();

extern "C" ::LocalM128(_mm_set_ss)(float);

extern "C" ::LocalM128(_mm_rsqrt_ss)(::LocalM128);

extern "C" ::LocalM128(_mm_cmpeq_ss)(::LocalM128, ::LocalM128);

extern "C" ::LocalM128(_mm_andnot_ps)(::LocalM128, ::LocalM128);

extern "C" ::LocalM128(_mm_mul_ss)(::LocalM128, ::LocalM128);

extern ::CvxDistVector4 DAT_01268370;

struct SamplingOutPair_e62740
{
    ::CvxDistVector4 first, second;
};

static __forceinline ::LocalM128 SamplingRecipSqrt_e62740(::LocalM128 r, const ::CvxDistVector4& three, const ::CvxDistVector4& half,
                                                       const ::CvxDistVector4& zero)

{

    ::LocalM128 e = (_mm_rsqrt_ss)(r);

    ::LocalM128 cmp = (_mm_cmpeq_ss)(r, zero.v);

    ::LocalM128 t = (_mm_mul_ss)((_mm_mul_ss)(r, e), e);

    ::LocalM128 q = (_mm_mul_ss)((_mm_mul_ss)(half.v, e), (_mm_sub_ss)(three.v, t));

    return (_mm_andnot_ps)(cmp, q);
}

static __forceinline void SamplingSetMul_e62740(::CvxDistVector4& o, ::LocalM128 s, const ::CvxDistVector4& a)

{

    o.v = (_mm_mul_ps)(s, a.v);
}

struct SamplingShuffles_e62740
{
    ::CvxDistVector4 d, c;
};

static __forceinline void SamplingPrepare_e62740(SamplingShuffles_e62740& sh, ::LocalM128 q)
{
    sh.d.v = (_mm_shuffle_ps)(q, q, 0xd2);
    sh.c.v = (_mm_shuffle_ps)(q, q, 0xc9);
}

static __forceinline void SamplingCross_e62740(::CvxDistVector4& o, const ::CvxDistVector4& a, const SamplingShuffles_e62740& sh)

{

    ::LocalM128 m1 = (_mm_mul_ps)((_mm_shuffle_ps)(a.v, a.v, 0xd2), sh.c.v);

    ::LocalM128 m2 = (_mm_mul_ps)((_mm_shuffle_ps)(a.v, a.v, 0xc9), sh.d.v);

    o.v = (_mm_sub_ps)(m2, m1);
}

static __forceinline void SamplingSetMulS_e62740(::CvxDistVector4& o, ::LocalM128 s, const ::CvxDistVector4& a)

{

    o.v = (_mm_mul_ps)((_mm_shuffle_ps)(s, s, 0), a.v);
}

// src: GUESS 0x00e625c0 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00e625c0(const Matrix* matrix, Shape* shape, Shape* other, CvxDistVector4* normal,
                                              Result* result)
{
    Result* output = result;
    CvxDistVector4 opposite, local, a, b;
    opposite.negative(*normal);
    local.inv(*matrix, *normal);
    shape->transform(&opposite, &a);
    other->transform(&local, &b);
    CvxDistVector4 mapped, delta;
    mapped.point(*matrix, b);
    delta.difference(a, mapped);
    CvxDistVector4 n = *normal;
    Scalar distance = delta.dot(n);
    if (_mm_movemask_ps(_mm_sub_ss(output->plane.at(3).v, distance.v)) & 1)
    {

        output->plane.set(n.at(0), n.at(1), n.at(2), distance);
        output->pointA = a;
        output->localB = b;
        output->pointB = mapped;
    }
}

// @fnv 0x00e62740
// src: GUESS 0x00e62740 (confidence: low)
__declspec(noinline) void Object_CopyData_00e62740(Shape* shape, Shape* other, const Matrix* matrix, ::CvxDistVector4* outA, ::CvxDistVector4* outB,
                                       SamplingOutPair_e62740* outPair)

{

    Result result;

    result.plane.w = -3.402820018375656e+38f;

    const ::CvxDistVector4* axisPtr = &DAT_01268370;

    int count = 3;

    do
    {

        ::CvxDistVector4 axis;

        memcpy(&axis, axisPtr, sizeof(::CvxDistVector4));

        axisPtr += 1;

        axis.v = (_mm_xor_ps)(DAT_010c44d0, axis.v);

        Object_UpdateFields_00e625c0(matrix, shape, other, &axis, &result);

        Object_UpdateFields_00e625c0(matrix, shape, other, &axis, &result);

    } while (--count != 0);

    ::CvxDistVector4 zeroA;

    zeroA.v = (_mm_setzero_ps)();

    ::CvxDistVector4 zeroB;

    zeroB.v = (_mm_set_ss)(0.0f);

    ::CvxDistVector4 cThree;

    cThree.v = (_mm_set_ss)(3.0f);

    ::CvxDistVector4 cHalf;

    cHalf.v = (_mm_set_ss)(0.5f);

    float limit = 1.0f;

    do
    {

        limit = (float)(limit * 0.9900000095367431640625);

        float absX = fabs(result.plane.x);

        float absY = fabs(result.plane.y);

        float absZ = fabs(result.plane.z);

        int iMin = 0;

        int i1 = iMin + 1;

        int i2 = iMin + 2;

        if (absY < absX)
        {
            absX = absY;
            i1 = 0;
            iMin = 1;
        }

        if (absZ < absX)
            i2 = iMin;

        ::CvxDistVector4 perp;

        perp = zeroA;

        float* planeC = &result.plane.x;

        float* perpC = &perp.x;

        perpC[i1] = planeC[i2];

        perpC[i2] = -planeC[i1];

        ::CvxDistVector4 perpN;

        SamplingSetMulS_e62740(perpN, SamplingRecipSqrt_e62740(perp.dot(perp).v, cThree, cHalf, zeroB), perp);

        ::LocalM128 ls1 = (_mm_load_ss)(&limit);

        ::LocalM128 ls2 = (_mm_load_ss)(&limit);

        SamplingShuffles_e62740 sh;
        SamplingPrepare_e62740(sh, perpN.v);

        ::CvxDistVector4 scaledPerp;

        SamplingSetMulS_e62740(scaledPerp, ls1, perpN);

        ::CvxDistVector4 cross;

        SamplingCross_e62740(cross, result.plane, sh);

        ::CvxDistVector4 crossScaled;

        SamplingSetMulS_e62740(crossScaled, ls2, cross);

        ::CvxDistVector4 sum;

        sum.v = (_mm_add_ps)(result.plane.v, scaledPerp.v);

        ::LocalM128 is2 = SamplingRecipSqrt_e62740(sum.dot(sum).v, cThree, cHalf, zeroB);

        ::LocalM128 splat2 = (_mm_shuffle_ps)(is2, is2, 0);

        ::CvxDistVector4 n1;

        SamplingSetMul_e62740(n1, splat2, sum);

        ::CvxDistVector4 n2;

        n2.v = (_mm_mul_ps)((_mm_sub_ps)(result.plane.v, scaledPerp.v), splat2);

        ::LocalM128 add3 = (_mm_add_ps)(crossScaled.v, result.plane.v);

        ::LocalM128 sub4 = (_mm_sub_ps)(result.plane.v, crossScaled.v);

        ::CvxDistVector4 n3;

        n3.v = (_mm_mul_ps)(add3, splat2);

        ::CvxDistVector4 n4;

        n4.v = (_mm_mul_ps)(sub4, splat2);

        Object_UpdateFields_00e625c0(matrix, shape, other, &n1, &result);

        Object_UpdateFields_00e625c0(matrix, shape, other, &n2, &result);

        Object_UpdateFields_00e625c0(matrix, shape, other, &n3, &result);

        Object_UpdateFields_00e625c0(matrix, shape, other, &n4, &result);

        limit = (float)(limit * 0.5);

    } while (limit > DAT_01017d00);

    *outA = result.pointA;

    *outB = result.localB;

    outPair->first = result.plane;

    outPair->second = result.pointA;
}
