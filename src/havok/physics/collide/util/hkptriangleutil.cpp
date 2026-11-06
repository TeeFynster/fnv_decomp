#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#include "../../../../../include/hkBool.h"

// src/havok/physics/collide/util/hkptriangleutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/hkptriangleutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Retain the original SIMD intrinsic type: the extra byte lanes in the CRT
// definition change VC9 alias analysis and register allocation in this unit.
#define _INCLUDED_MM2
// Exe 0x00ceb8d0 IsDegenerateTriangle: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;

extern "C" LocalM128 _mm_mul_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_sub_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_add_ss(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 _A, LocalM128 _B, unsigned int _Imm8);
extern "C" void _mm_store_ss(float* _V, LocalM128 _A);

#include "../../../../../include/hkVector4.h"

typedef float hkReal;

inline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x)
{}

inline hkSimdReal::operator float() const
{
    hkReal s;
    _mm_store_ss(&s, m_vValue);
    return s;
}


inline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
    return s;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& v) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
    return s;
}

// @fnv 0x00ceb8d0
hkBool __cdecl IsDegenerateTriangle(const hkVector4& aVertexA, const hkVector4& aVertexB, const hkVector4& aVertexC,
                                    hkReal tolerance)
{
    hkVector4 vAB;
    vAB.setSub4(aVertexA, aVertexB);
    hkVector4 vAC;
    vAC.setSub4(aVertexA, aVertexC);
    hkVector4 vNormal1;
    vNormal1.setCross(vAB, vAC);
    hkVector4 vBA;
    vBA.setSub4(aVertexB, aVertexA);
    hkVector4 vBC;
    vBC.setSub4(aVertexB, aVertexC);
    hkVector4 vNormal2;
    vNormal2.setCross(vBA, vBC);
    if (vNormal1.lengthSquared3() < tolerance || vNormal2.lengthSquared3() < tolerance)
        return true;
    hkVector4 vCB;
    vCB.setSub4(aVertexC, aVertexB);
    hkReal lab = vAB.dot3(vAB);
    hkReal lcb = vCB.lengthSquared3();
    hkReal fDot = vCB.dot3(vAB);
    hkReal fProduct = lab * lcb;
    hkReal fDotSq = fDot * fDot;
    hkReal fRemainder = fProduct - fDotSq;
    if (fRemainder == 0.0f)
        return true;
    return false;
}
