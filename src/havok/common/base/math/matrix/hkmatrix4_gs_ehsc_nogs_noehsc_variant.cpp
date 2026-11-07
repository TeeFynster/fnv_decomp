#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form

// src/havok/common/base/math/matrix/hkmatrix4_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/matrix/hkmatrix4.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkMatrix4.h"

__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}

__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}




__forceinline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& v)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents);
}

__forceinline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::addMul4(const hkVector4& x, const hkVector4& y)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}

__forceinline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
    if (i == 0)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    }
    else if (i == 1)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    }
    else if (i == 2)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    }
    else if (i == 3)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
}

__forceinline float& hkVector4::operator()(int i)
{
    return ((float*)&m_vComponents)[i];
}

__forceinline float& hkMatrix4::operator()(int r, int c)
{
    return getColumn(c)(r);
}

__forceinline void hkMatrix4::transformPosition(const hkVector4& kPoint, hkVector4& kPointOut) const
{
    hkVector4 kBx;
    kBx.setBroadcast(kPoint, 0);
    hkVector4 kBy;
    kBy.setBroadcast(kPoint, 1);
    hkVector4 kBz;
    kBz.setBroadcast(kPoint, 2);

    hkVector4 kSum;
    kSum.setMul4(kBx, m_kColumn0);
    kSum.addMul4(kBy, m_kColumn1);
    kSum.addMul4(kBz, m_kColumn2);
    kSum.add4(m_kColumn3);

    kPointOut = kSum;
}

__forceinline void hkMatrix4::transformDirection(const hkVector4& kDir, hkVector4& kDirOut) const
{
    hkVector4 kBx;
    kBx.setBroadcast(kDir, 0);
    hkVector4 kBy;
    kBy.setBroadcast(kDir, 1);
    hkVector4 kBz;
    kBz.setBroadcast(kDir, 2);

    hkVector4 kSum;
    kSum.setMul4(kBx, m_kColumn0);
    kSum.addMul4(kBy, m_kColumn1);
    kSum.addMul4(kBz, m_kColumn2);

    kDirOut = kSum;
}

__forceinline void hkMatrix4::setMulAffine(const hkMatrix4& a, const hkMatrix4& b)
{
    hkVector4 col0;
    a.transformDirection(b.m_kColumn0, col0);
    hkVector4 col1;
    a.transformDirection(b.m_kColumn1, col1);
    hkVector4 col2;
    a.transformDirection(b.m_kColumn2, col2);
    hkVector4 col3;
    a.transformPosition(b.m_kColumn3, col3);

    m_kColumn0 = col0;
    m_kColumn1 = col1;
    m_kColumn2 = col2;
    m_kColumn3 = col3;
}

// src: GUESS 0x00de88a0 (confidence: low)
__declspec(noinline) void hkMatrix4::ProcessAndReturnValue_00de88a0(const hkSimdReal& s, const hkMatrix4& m)
{
    m_kColumn0.setMul4(s, m.m_kColumn0);
    m_kColumn1.setMul4(s, m.m_kColumn1);
    m_kColumn2.setMul4(s, m.m_kColumn2);
    m_kColumn3.setMul4(s, m.m_kColumn3);
}

// src: GUESS 0x00de8910 (confidence: low)
int hkMatrix4::UpdateState_00de8910(float epsilon)
{
    hkMatrix4& m = *this;

    float a0 = m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0);
    float a1 = m(0, 0) * m(1, 2) - m(0, 2) * m(1, 0);
    float a2 = m(0, 0) * m(1, 3) - m(0, 3) * m(1, 0);
    float a3 = m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1);
    float a4 = m(0, 1) * m(1, 3) - m(0, 3) * m(1, 1);
    float a5 = m(0, 2) * m(1, 3) - m(0, 3) * m(1, 2);
    float b0 = m(2, 0) * m(3, 1) - m(2, 1) * m(3, 0);
    float b1 = m(2, 0) * m(3, 2) - m(2, 2) * m(3, 0);
    float b2 = m(2, 0) * m(3, 3) - m(2, 3) * m(3, 0);
    float b3 = m(2, 1) * m(3, 2) - m(2, 2) * m(3, 1);
    float b4 = m(2, 1) * m(3, 3) - m(2, 3) * m(3, 1);
    float b5 = m(2, 2) * m(3, 3) - m(2, 3) * m(3, 2);

    float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
    float absDet = det < 0.0f ? -det : det;
    if (absDet <= epsilon)
    {
        return 1;
    }

    hkMatrix4 inv;
    inv(0, 0) = m(1, 1) * b5 - m(1, 2) * b4 + m(1, 3) * b3;
    inv(1, 0) = -m(1, 0) * b5 + m(1, 2) * b2 - m(1, 3) * b1;
    inv(2, 0) = m(1, 0) * b4 - m(1, 1) * b2 + m(1, 3) * b0;
    inv(3, 0) = -m(1, 0) * b3 + m(1, 1) * b1 - m(1, 2) * b0;
    inv(0, 1) = -m(0, 1) * b5 + m(0, 2) * b4 - m(0, 3) * b3;
    inv(1, 1) = m(0, 0) * b5 - m(0, 2) * b2 + m(0, 3) * b1;
    inv(2, 1) = -m(0, 0) * b4 + m(0, 1) * b2 - m(0, 3) * b0;
    inv(3, 1) = m(0, 0) * b3 - m(0, 1) * b1 + m(0, 2) * b0;
    inv(0, 2) = m(3, 1) * a5 - m(3, 2) * a4 + m(3, 3) * a3;
    inv(1, 2) = -m(3, 0) * a5 + m(3, 2) * a2 - m(3, 3) * a1;
    inv(2, 2) = m(3, 0) * a4 - m(3, 1) * a2 + m(3, 3) * a0;
    inv(3, 2) = -m(3, 0) * a3 + m(3, 1) * a1 - m(3, 2) * a0;
    inv(0, 3) = -m(2, 1) * a5 + m(2, 2) * a4 - m(2, 3) * a3;
    inv(1, 3) = m(2, 0) * a5 - m(2, 2) * a2 + m(2, 3) * a1;
    inv(2, 3) = -m(2, 0) * a4 + m(2, 1) * a2 - m(2, 3) * a0;
    inv(3, 3) = m(2, 0) * a3 - m(2, 1) * a1 + m(2, 2) * a0;

    hkSimdReal invDet(1.0f / det);
    ProcessAndReturnValue_00de88a0(invDet, inv);
    return 0;
}

// @fnv 0x00de9140
// src: GUESS 0x00de9140 (confidence: low)
void hkMatrix4::UpdateFields_00de9140(const hkMatrix4& a, const hkMatrix4& b)
{
    hkMatrix4 bInv = b;
    bInv.UpdateState_00de8910(1.192092896e-07f);
    setMulAffine(a, bInv);
}
