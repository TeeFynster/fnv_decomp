#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/common/base/algorithm/collide/linesegment/hklinesegmentutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/algorithm/collide/linesegment/hklinesegmentutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00d22e40 FUN_00d22e40: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_load_ps1(const float* p);
extern "C" LocalM128 _mm_load_ss(const float* p);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

// Keep the original SSE intrinsic type used by this unit's MSVC code generation.
#define _INCLUDED_MM2
#include "../../../../../../../include/hkVector4.h"

typedef float hkReal;

inline hkSimdReal::hkSimdReal()
{}

inline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x)
{}

inline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}

inline hkSimdReal::operator float() const
{
    hkReal r;
    _mm_store_ss(&r, m_vValue);
    return r;
}

inline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}


inline hkVector4::hkVector4(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}

inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}

inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, float t)
{
    const LocalM128 s = _mm_load_ss(&t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents), a.m_vComponents);
}

// @fnv 0x00d230e0
// src: COMMUNITY 0x00d230e0
int __cdecl hkLineSegmentUtil_closestPointLineSeg(const hkVector4& akPoint, const hkVector4& kA, const hkVector4& kB,
                         hkVector4& kClosestOut)
{
    hkVector4 kAP;
    kAP.setSub4(akPoint, kA);
    hkVector4 kAB;
    kAB.setSub4(kB, kA);
    const float fProj = kAP.dot3(kAB);
    const float fLen2 = kAB.dot3(kAB);
    if (fProj <= 0.0f)
    {
        kClosestOut = kA;
        return 8;
    }
    if (fLen2 <= fProj)
    {
        kClosestOut = kB;
        return 4;
    }
    kClosestOut.setAddMul4(kA, kAB, fProj / fLen2);
    return 0;
}

#include <math.h>


inline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdReal& r)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
}

inline void hkVector4::setAddMul4b(const hkVector4& a, const hkVector4& b, hkReal r)
{
    LocalM128 rr = _mm_load_ss(&r);
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(rr, rr, 0), b.m_vComponents));
}

inline void hkVector4::setAddMul4a(const hkVector4& a, const hkVector4& b, hkReal r)
{
    m_vComponents = _mm_add_ps(a.m_vComponents,
                               _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&r), _mm_load_ss(&r), 0), b.m_vComponents));
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    LocalM128 m = _mm_mul_ps(m_vComponents, a.m_vComponents);
    LocalM128 y = _mm_shuffle_ps(m, m, 0x55);
    LocalM128 xy = _mm_add_ss(y, m);
    LocalM128 z = _mm_shuffle_ps(m, m, 0xaa);
    LocalM128 xyz = _mm_add_ss(z, xy);
    return hkSimdReal(xyz);
}

inline hkReal hkVector4::dot3scalar(const hkVector4& a) const
{
    return dot3(a);
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
    return dot3(*this);
}

static inline hkReal hkFabs(hkReal r)
{
    return (hkReal)::fabs(r);
}

struct VectorPairResult
{
    hkVector4 m_kFirstVector;
    hkVector4 m_kClosestPointOnSecond;
    hkReal m_fValue;
};

// Computes the closest points on two line segments defined by A/dA and B/dB, storing them and the squared distance in result.
// @fnv 0x00d22e40
// src: XBOX_PDB 0x00d22e40
int hkLineSegmentUtil_closestLineSegLineSeg(const hkVector4& A, const hkVector4& dA, const hkVector4& B, const hkVector4& dB,
                 VectorPairResult& result)
{
    hkVector4 kDelta;
    kDelta.setSub4(B, A);
    hkReal fDotDir = dA.dot3(dB);
    hkReal fDotADelta = dA.dot3(kDelta);
    hkReal fDotBDelta = dB.dot3(kDelta);
    hkReal fLenSqA = dA.dot3scalar(dA);
    hkReal fLenSqB;
    _mm_store_ss(&fLenSqB, (dB.dot3(dB)).m_vValue);

    hkReal denom = hkFabs(fLenSqA * fLenSqB - fDotDir * fDotDir);
    hkReal s = fDotADelta * fLenSqB - fDotBDelta * fDotDir;

    int code;
    if (denom * s >= denom * denom)
    {
        code = 1;
        s = 1.0f;
    }
    else if (s <= 0.0f)
    {
        code = 2;
        s = 0.0f;
    }
    else
    {
        hkReal fEpsilon = (fLenSqA * fLenSqB + fDotDir * fDotDir) * (1.0 / 1048576.0);
        if (fEpsilon < denom)
        {
            code = 0;
            s = s / denom;
        }
        else
        {
            code = 1;
            s = 1.0f;
        }
    }

    hkReal t = fDotDir * s - fDotBDelta;
    if (t >= fLenSqB)
    {
        code = 4;
        t = 1.0f;
    }
    else if (t <= 0.0f)
    {
        code = 8;
        t = 0.0f;
    }
    else
    {
        t = t / fLenSqB;
        goto done;
    }

    s = fDotDir * t + fDotADelta;
    if (s <= 0.0f)
    {
        code |= 2;
        s = 0.0f;
    }
    else if (s >= fLenSqA)
    {
        code |= 1;
        s = 1.0f;
    }
    else
    {
        s = s / fLenSqA;
    }

done:
    result.m_kFirstVector.setAddMul4a(A, dA, s);
    hkVector4 closestB;
    closestB.setAddMul4b(B, dB, t);
    result.m_kClosestPointOnSecond.setSub4(result.m_kFirstVector, closestB);
    result.m_fValue = result.m_kClosestPointOnSecond.lengthSquared3();
    return code;
}
