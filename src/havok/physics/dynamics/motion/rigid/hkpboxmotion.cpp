
// src/havok/physics/dynamics/motion/rigid/hkpboxmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpboxmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original SIMD storage: the CRT's byte-array aliases trigger /GS
// parameter copies in this compiler and change the generated instructions.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00d1e690 InitializeBoxMotion: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_load_ps1(const float*);
    void _mm_store_ss(float*, LocalM128);
    void _mm_store_ps(float*, LocalM128);
}
#endif


#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkpBoxMotion.h"

template <typename ENUM, typename STORAGE>
__forceinline hkEnum<ENUM, STORAGE>::hkEnum(ENUM value) : m_kStorage(static_cast<STORAGE>(value))
{}

// Former hkpSphereMotionD1E6F/D1E8 are box motion: 0x00d1e810 stores independent diagonals; sphere 0x00d1e320 stores their common minimum.
// Keep the box declaration local: include/hkpBoxMotion.h lacks these overrides.

__forceinline float& hkVector4::operator()(int i)
{
    return reinterpret_cast<float*>(&m_vComponents)[i];
}

__forceinline const float& hkVector4::operator()(int i) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[i];
}

__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}

__forceinline float& hkMatrix3::operator()(int r, int c)
{
    return (&m_kColumn0)[c](r);
}

__forceinline const float& hkMatrix3::operator()(int r, int c) const
{
    return (&m_kColumn0)[c](r);
}

__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline void hkMatrix3::setZero()
{
    m_kColumn0.setZero4();
    m_kColumn1.setZero4();
    m_kColumn2.setZero4();
}

// The shared matrix declares no three-scalar setDiagonal overload.
__forceinline void SetBoxInertiaDiagonal(hkMatrix3& out, float a, float b, float c)
{
    out.setZero();
    out(0, 0) = a;
    out(1, 1) = b;
    out(2, 2) = c;
}

__forceinline hkSimdReal::hkSimdReal()
{}

__forceinline hkSimdReal::hkSimdReal(const LocalM128& v) : m_vValue(v)
{}

template <typename T>
__forceinline hkSimdReal hkSimdReal::operator+(const T& r) const
{
    return hkSimdReal(_mm_add_ss(m_vValue, r.m_vValue));
}

__forceinline hkSimdReal::operator float() const
{
    float f;
    _mm_store_ss(&f, m_vValue);
    return f;
}

__forceinline hkSimdReal hkVector4::getSimdAt(int) const
{
    return hkSimdReal(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
}

__forceinline void hkVector4::addMul4(const hkSimdReal& r, const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents));
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    const LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    const LocalM128 z = _mm_shuffle_ps(x2, x2, 0xaa);
    return hkSimdReal(_mm_add_ss(z, xySum));
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    LocalM128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    LocalM128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    LocalM128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    LocalM128 c0 = r.m_kColumn0.m_vComponents;
    LocalM128 c1 = r.m_kColumn1.m_vComponents;
    LocalM128 c2 = r.m_kColumn2.m_vComponents;
    LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
    LocalM128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = ctmp;

    LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    LocalM128 r0 = _mm_mul_ps(c0, b0);
    LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    LocalM128 r1 = _mm_mul_ps(c1, b1);
    LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    LocalM128 r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}


__forceinline void RotateContactArmInverse(hkVector4& out, const hkRotation& rotIn, const hkVector4& b)
{
    const hkVector4* r = reinterpret_cast<const hkVector4*>(&rotIn);
    LocalM128 c0 = r[0].m_vComponents;
    LocalM128 c1 = r[1].m_vComponents;
    LocalM128 c2 = r[2].m_vComponents;
    {
        LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
        LocalM128 ctmp = _mm_unpackhi_ps(c0, c1);
        c0 = _mm_movelh_ps(tmp, c2);
        tmp = _mm_movehl_ps(c0, tmp);
        c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
        c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    }
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(b1, c1);
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const LocalM128 r0 = _mm_mul_ps(b0, c0);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(c2, b2);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}

// @fnv 0x00d1e670
void hkpBoxMotion::SetBodyMass(float value)
{
    SetMassInv(1.0f / value);
}

// @fnv 0x00d1e7b0
void hkpBoxMotion::WriteInverseInertiaDiagonal(float* pOut)
{
    float fDiag0 = m_kInertiaAndMassInv.x;
    float fDiag1 = m_kInertiaAndMassInv.y;
    float fDiag2 = m_kInertiaAndMassInv.z;
    LocalM128 z = _mm_setzero_ps();
    ((LocalM128*)pOut)[0] = z;
    ((LocalM128*)pOut)[1] = z;
    ((LocalM128*)pOut)[2] = z;
    pOut[0] = fDiag0;
    pOut[5] = fDiag1;
    pOut[10] = fDiag2;
}


// @fnv 0x00d1e810
void hkpBoxMotion::SetInertiaInvLocal(const hkMatrix3& kInertiaInv)
{
    m_kInertiaAndMassInv.set(kInertiaInv(0, 0), kInertiaInv(1, 1), kInertiaInv(2, 2), m_kInertiaAndMassInv(3));
}

// @fnv 0x00d1eba0
void hkpBoxMotion::GetProjectedPointVelocity(const hkVector4& p, const hkVector4& normal, float& velOut,
                                            float& invVirtMassOut) const
{
    hkVector4 arm;
    {
        hkVector4 relPos;
        relPos.setSub4(p, m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
        arm.setCross(relPos, normal);
    }
    velOut = m_kAngularVelocity.dot3(arm) + m_kTranslationalVelocity.dot3(normal);

    hkVector4 armLocal;
    RotateContactArmInverse(armLocal, m_kMotionState.m_kMotionTransform.m_rotation, arm);
    hkVector4 r;
    r.setMul4(m_kInertiaAndMassInv, armLocal);
    invVirtMassOut = m_kInertiaAndMassInv.w + r.dot3(armLocal);
}

extern LocalM128 DAT_010c7200;
// @fnv 0x00d1e8c0
void hkpBoxMotion::GetInertiaWorld(hkMatrix3& out)
{
    hkVector4 inv;
    inv.m_vComponents = _mm_max_ps(m_kInertiaAndMassInv.m_vComponents, DAT_010c7200);
    SetBoxInertiaDiagonal(out, 1.0f / inv(0), 1.0f / inv(1), 1.0f / inv(2));
    out.SetFromRotation(m_kMotionState.m_kMotionTransform.m_rotation);
}

// @fnv 0x00d1e9f0
void hkpBoxMotion::ApplyImpulseAtPoint(const hkVector4& imp, const hkVector4& p)
{
    m_kTranslationalVelocity.addMul4(m_kInertiaAndMassInv.getSimdAt(3), imp);

    hkVector4 relPos;
    relPos.setSub4(p, m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
    hkVector4 crossWs;
    crossWs.setCross(relPos, imp);
    hkVector4 crossLs;
    crossLs._setRotatedInverseDir(m_kMotionState.m_kMotionTransform.m_rotation, crossWs);
    hkVector4 deltaVelLs;
    deltaVelLs.setMul4(m_kInertiaAndMassInv, crossLs);
    hkVector4 deltaVelWs;
    deltaVelWs._setRotatedDir(m_kMotionState.m_kMotionTransform.m_rotation, deltaVelLs);
    m_kAngularVelocity.add4(deltaVelWs);
}


// @fnv 0x00d1eaf0
// Preserve the original aliasing of the reloads; typed member loads change SIMD scheduling.
void hkpBoxMotion::ApplyAngularImpulseToBodies(const hkVector4& impulse)
{
    const hkRotation& r = m_kMotionState.m_kMotionTransform.m_rotation;
    LocalM128 a = r.m_kColumn0.m_vComponents, b = r.m_kColumn1.m_vComponents, c = r.m_kColumn2.m_vComponents;
    LocalM128 tmp = _mm_unpacklo_ps(a, b);
    LocalM128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(a, b), c, 0xe4);
    a = _mm_movelh_ps(tmp, c);
    tmp = _mm_movehl_ps(a, tmp);
    b = _mm_shuffle_ps(tmp, c, 0xd4);
    c = ctmp;
    LocalM128 vResult;
    vResult = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const LocalM128&>(impulse), reinterpret_cast<const LocalM128&>(impulse), 0x00), a),
                                    _mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const LocalM128&>(impulse), reinterpret_cast<const LocalM128&>(impulse), 0x55), b)),
                         _mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const LocalM128&>(impulse), reinterpret_cast<const LocalM128&>(impulse), 0xaa), c));
    vResult = _mm_mul_ps(vResult, *reinterpret_cast<const LocalM128*>((char*)this + 0xc0));
    vResult = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(vResult, vResult, 0x00), _mm_load_ps((const float*)((char*)this + 0x10))),
                   _mm_mul_ps(_mm_shuffle_ps(vResult, vResult, 0x55), _mm_load_ps((const float*)((char*)this + 0x20)))),
        _mm_mul_ps(_mm_shuffle_ps(vResult, vResult, 0xaa), _mm_load_ps((const float*)((char*)this + 0x30))));
    LocalM128& acc = *reinterpret_cast<LocalM128*>((char*)this + 0xe0);
    acc = _mm_add_ps(acc, vResult);
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}
extern const char DAT_010c6dc4[];
extern const float DAT_01012068;
// @fnv 0x00d1e690
hkpBoxMotion* hkpBoxMotion::InitializeBoxMotion(int a1, int a2)
{
    __assume(this != 0);
    ::new (this) hkpMotion(*reinterpret_cast<const hkVector4*>(a1), *reinterpret_cast<const hkQuaternion*>(a2), false);
    *(LocalM128*)&m_kInertiaAndMassInv = _mm_setr_ps(DAT_01012068, DAT_01012068, DAT_01012068, DAT_01012068);
    *(const char**)this = DAT_010c6dc4;
    m_type = MOTION_BOX_INERTIA;
    return this;
}

// @fnv 0x00d1e750
const hkMatrix3& hkpBoxMotion::StoreInertiaLocal(const hkMatrix3& inertia)
{
    float f[3];
    f[0] = 1.0f / inertia.m_kColumn0.x;
    f[1] = 1.0f / inertia.m_kColumn1.y;
    f[2] = 1.0f / inertia.m_kColumn2.z;
    *(LocalM128*)&m_kInertiaAndMassInv = _mm_setr_ps(f[0], f[1], f[2], m_kInertiaAndMassInv.w);
    return inertia;
}


extern "C" void _ReadWriteBarrier(void);
extern const float DAT_0104da4c;
// @fnv 0x00d1e6f0
void hkpBoxMotion::GetInertiaLocal(hkMatrix3& kInertiaInv) const
{
    __declspec(align(16)) float afInertia[4];
    LocalM128 m = m_kInertiaAndMassInv.m_vComponents;
    _ReadWriteBarrier();
    _mm_store_ps(afInertia, _mm_max_ps(_mm_load_ps1(&DAT_0104da4c), m));
    SetBoxInertiaDiagonal(kInertiaInv, 1.0f / afInertia[0], 1.0f / afInertia[1], 1.0f / afInertia[2]);
}
