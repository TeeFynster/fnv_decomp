// src/havok/physics/dynamics/motion/rigid/hkpcharactermotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpcharactermotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the original SIMD storage; the CRT's byte-array aliases change /GS parameter copies.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00d1eec0 ApplyImpulseAtPoint: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps1(const float*);
}
#endif

#define FNV64_HKVECTOR4_OWN_COPY
#include <string.h>
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkpCharacterMotion.h"

// Keep only the overrides local: include/hkpCharacterMotion.h declares none of them.
// The former sphere-named stand-ins implement this character-motion unit's 0x00d1ecc0-0x00d1ef80 methods and use hkpMotion's 0xC0/0xD0/0xE0 fields.

// A block copy keeps the original implicit SIMD-union copy semantics.
__forceinline hkVector4::hkVector4(const hkVector4& vector)
{
    memcpy(this, &vector, sizeof(hkVector4));
}

__forceinline float& hkVector4::operator()(int i)
{
    return reinterpret_cast<float*>(&m_vComponents)[i];
}

__forceinline const float& hkVector4::operator()(int i) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[i];
}

__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline float& hkMatrix3::operator()(int r, int c)
{
    return (&m_kColumn0)[c](r);
}

__forceinline void hkMatrix3::setZero()
{
    m_kColumn0.setZero4();
    m_kColumn1.setZero4();
    m_kColumn2.setZero4();
}

// The shared matrix has no three-scalar setDiagonal overload.
__forceinline void SetCharacterInertiaDiagonal(hkMatrix3& inertia, float value)
{
    inertia.setZero();
    inertia(0, 0) = value;
    inertia(1, 1) = value;
    inertia(2, 2) = value;
}

__forceinline hkSimdReal::hkSimdReal()
{}

__forceinline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline hkSimdReal hkVector4::getSimdAt3() const
{
    hkSimdReal result;
    result.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    return result;
}

__forceinline void hkVector4::addMul4(const hkSimdReal& s, const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), v.m_vComponents));
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

// Computes the reciprocal of the largest diagonal inertia element.
template <class T> inline T MaxScalar(T x, T y)
{
    return x > y ? x : y;
}

// @fnv 0x00d1ed40
void hkpCharacterMotion::SetInertiaLocal(const hkMatrix3& inertia)
{
    float a = MaxScalar(MaxScalar(inertia.m_kColumn0.x, inertia.m_kColumn1.y), inertia.m_kColumn2.z);
    float fInvMaxDiag;
    if (a > 0.0f)
        fInvMaxDiag = 1.0f / a;
    else
        fInvMaxDiag = 0.0f;
    m_kInertiaAndMassInv.x = fInvMaxDiag;
    m_kInertiaAndMassInv.y = fInvMaxDiag;
    m_kInertiaAndMassInv.z = fInvMaxDiag;
}

// @fnv 0x00d1edd0
void hkpCharacterMotion::SetInertiaInvLocal(const hkMatrix3& inertia)
{
    float a = inertia.m_kColumn0.x;
    float b = inertia.m_kColumn1.y;
    float c = a < b ? a : b;
    float fThird = inertia.m_kColumn2.z;
    float fMinAll = c < fThird ? c : fThird;
    m_kInertiaAndMassInv.x = fMinAll;
    m_kInertiaAndMassInv.y = fMinAll;
    m_kInertiaAndMassInv.z = fMinAll;
}

// @fnv 0x00d1ee40
void hkpCharacterMotion::GetInertiaInvLocal(hkMatrix3& inertia) const
{
    float fInv = m_kInertiaAndMassInv(0);
    SetCharacterInertiaDiagonal(inertia, fInv);
}

// @fnv 0x00d1ee80
void hkpCharacterMotion::GetLocalInverseInertia(hkMatrix3& inertia) const
{
    float fInv = m_kInertiaAndMassInv(0);
    SetCharacterInertiaDiagonal(inertia, fInv);
}

// @fnv 0x00d1ef50
void hkpCharacterMotion::ApplyAngularImpulseToBodies(const hkVector4& impulse)
{
    hkVector4 delta;
    delta.setMul4(m_kInertiaAndMassInv, impulse);
    m_kAngularVelocity.add4(delta);
}

// @fnv 0x00d1ecc0
void hkpCharacterMotion::GetInertiaLocal(hkMatrix3& inertia) const
{
    const float value = 1.0f / m_kInertiaAndMassInv.x;
    const LocalM128 zero = _mm_setzero_ps();
    inertia.m_kColumn0.m_vComponents = zero;
    inertia.m_kColumn1.m_vComponents = zero;
    inertia.m_kColumn2.m_vComponents = zero;
    inertia.m_kColumn0.x = value;
    inertia.m_kColumn1.y = value;
    inertia.m_kColumn2.z = value;
}

// @fnv 0x00d1ed00
void hkpCharacterMotion::GetInverseScaleMatrix(hkMatrix3& inertia) const
{
    float inv = 1.0f / m_kInertiaAndMassInv.x;
    LocalM128 z = _mm_setzero_ps();
    inertia.m_kColumn0.m_vComponents = z;
    inertia.m_kColumn1.m_vComponents = z;
    inertia.m_kColumn2.m_vComponents = z;
    inertia.m_kColumn0.x = inv;
    inertia.m_kColumn1.y = inv;
    inertia.m_kColumn2.z = inv;
}

// @fnv 0x00d1eec0
void hkpCharacterMotion::ApplyImpulseAtPoint(const hkVector4& imp, const hkVector4& p)
{
    m_kTranslationalVelocity.addMul4(m_kInertiaAndMassInv.getSimdAt3(), imp);
    hkVector4 relMassCenter;
    relMassCenter.setSub4(p, m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
    hkVector4 crossWs;
    crossWs.setCross(relMassCenter, imp);
    hkVector4 deltaVelWs;
    deltaVelWs.setMul4(crossWs, m_kInertiaAndMassInv);
    m_kAngularVelocity.add4(deltaVelWs);
}

// @fnv 0x00d1ef80
void hkpCharacterMotion::vf5c(float afTimestep, const hkVector4& force)
{
    LocalM128 timestep = _mm_load_ps1(&afTimestep);
    hkVector4 impulse;
    impulse.quad = _mm_mul_ps(timestep, force.quad);
    hkSimdReal w = m_kInertiaAndMassInv.getSimdAt3();
    hkVector4 weighted = impulse;
    weighted.mul4(w);
    m_kTranslationalVelocity.quad = _mm_add_ps(weighted.quad, m_kTranslationalVelocity.quad);
}
