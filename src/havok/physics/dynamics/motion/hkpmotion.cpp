// src/havok/physics/dynamics/motion/hkpmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/hkpmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the unit's intrinsic type and declarations used by its original SSE code.
#define _INCLUDED_MM2
// Exe 0x00c864f0 SetCollisionShape: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" void _mm_store_ss(float*, LocalM128);

#include "../../../../../include/hkpMotion.h"
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkMotionState.h"

// Havok's empty value constructors and reference-count initialization are inline in this unit.
inline hkTransform::hkTransform() {}
inline hkQuaternion::hkQuaternion() {}
inline QuantizedFloat8::QuantizedFloat8() {}
inline hkMotionState::hkMotionState() {}
template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum() {}

inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
inline const float& hkVector4::operator()(int i) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[i];
}
// Preserve the packed-half assignment, including its reference return.
inline short& StoreHalf(short& storage, const float& value)
{
    int bits = reinterpret_cast<const int*>(&value)[0];
    storage = static_cast<short>(bits >> 16);
    return storage;
}

// The shared hkMotionState currently has no declarations for these two operations.
// Use their native thiscall ABI directly, without defining a substitute motion-state class.
extern "C" void InitializeMotionState();
extern "C" void CopyMotionState();
typedef void (__thiscall *InitializeMotionStateFn)(hkMotionState*, const hkVector4&, const hkQuaternion&);
typedef void (__thiscall *CopyMotionStateFn)(hkMotionState*, const hkMotionState*);

extern "C" void __cdecl SetMotionState(const hkTransform*, hkMotionState*);

// @fnv 0x00c86400
void hkpMotion::SetGeometryTransform(const hkTransform& transform)
{
    SetMotionState(&transform, &m_kMotionState);
}

// The shared hkpMotion has no setDeactivationClass declaration; retain only this operation locally.
// @fnv 0x00c86420
void __fastcall SetMotionDeactivationClass(hkpMotion* motion, void*, char value)
{
    motion->m_kMotionState.m_uiDeactivationClass = value;
}

// @fnv 0x00c86480
void hkpMotion::SetMassInv(float value)
{
    m_kInertiaAndMassInv.w = value;
}

// Computes the inverse of mass (0 if mass is 0) and passes it to SetMassInv.
// @fnv 0x00c86330
void hkpMotion::SetBodyMass(float mass)
{
    float invMass;
    if (mass == 0.0f)
    {
        invMass = 0.0f;
    }
    else
    {
        invMass = 1.0f / mass;
    }
    SetMassInv(invMass);
}

extern "C" void __cdecl hkSweptTransformUtil_warpToPosition(const hkVector4*, hkMotionState*);
// @fnv 0x00c863a0
void hkpMotion::SetWorldPosition(const hkVector4& position)
{
    hkSweptTransformUtil_warpToPosition(&position, &m_kMotionState);
}

extern "C" void __cdecl hkSweptTransformUtil_warpToRotation(const hkQuaternion*, hkMotionState*);

// @fnv 0x00c863c0
void hkpMotion::SetBodyOrientation(const hkQuaternion& rotation)
{
    hkSweptTransformUtil_warpToRotation(&rotation, &m_kMotionState);
}

extern void __cdecl hkSweptTransformUtil_warpTo(const hkVector4*, const hkQuaternion*, hkMotionState*);

// @fnv 0x00c863e0
void hkpMotion::SetPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation)
{
    hkSweptTransformUtil_warpTo(&position, &rotation, &m_kMotionState);
}

// The shared hkpMotion has no swept-transform evaluation declaration.
// @fnv 0x00c86490
void __fastcall ApproximateMotionTransform(hkpMotion* motion, void*, float value, hkTransform* result)
{
    motion->m_kMotionState.m_kSweptTransform._approxTransformAt(value, *result);
}

int __cdecl ApplyDelta(int, int);
// @fnv 0x00c86380
void hkpMotion::SetCenterOfMassInLocal(const hkVector4& centerOfMass)
{
    ApplyDelta((int)&centerOfMass, (int)&m_kMotionState);
}

// Adds impulse scaled by inverse mass to the translational velocity.
// @fnv 0x00c864f0
void hkpMotion::SetCollisionShape(const hkVector4& impulse)
{
    hkVector4 delta;
    LocalM128 inverseMass = _mm_shuffle_ps(m_kInertiaAndMassInv.m_vComponents, m_kInertiaAndMassInv.m_vComponents, 0xff);
    delta.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inverseMass, inverseMass, 0), impulse.m_vComponents);
    m_kTranslationalVelocity.add4(delta);
}

// Constructor: zeroes velocities, damping and deactivation data, initializes the motion state,
// and sets the packed gravity factor to 1.0.
// @fnv 0x00c86530
hkpMotion::hkpMotion(const hkVector4& position, const hkQuaternion& rotation, bool wantDeactivation) throw()
{
    hkVector4 zero;
    zero.setZero4();
    m_kTranslationalVelocity = zero;
    m_kAngularVelocity = zero;
    reinterpret_cast<InitializeMotionStateFn>(&InitializeMotionState)(&m_kMotionState, position, rotation);
    m_kMotionState.m_fAngularDamping = m_kMotionState.m_fLinearDamping = 0.0f;
    *reinterpret_cast<unsigned char*>(&m_type) = MOTION_INVALID;
    if (wantDeactivation)
    {
        m_ucDeactivationIntegrateCounter = static_cast<unsigned char>(0xf & static_cast<int>(position(0)));
    }
    else
    {
        m_ucDeactivationIntegrateCounter = 0xff;
    }
    m_ausDeactivationNumInactiveFrames[0] = 0;
    m_ausDeactivationNumInactiveFrames[1] = 0;
    m_akDeactivationReferencePositions[0] = zero;
    m_akDeactivationReferencePositions[1] = zero;
    m_auiDeactivationReferenceOrientations[0] = 0;
    m_auiDeactivationReferenceOrientations[1] = 0;
    // hkpMotion.h declares hkHalf as the packed short storage type.
    StoreHalf(m_fGravityFactor.m_value, 1.0f);
}

// Copies the motion state, velocities and deactivation integrate counter to the destination.
// @fnv 0x00c86610
// src: HAVOK_SRC 0x00c86610
void hkpMotion::getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* destination)
{
    reinterpret_cast<CopyMotionStateFn>(&CopyMotionState)(&destination->m_kMotionState, &m_kMotionState);
    destination->m_kTranslationalVelocity = m_kTranslationalVelocity;
    destination->m_kAngularVelocity = m_kAngularVelocity;
    destination->m_ucDeactivationIntegrateCounter = m_ucDeactivationIntegrateCounter;
}

// @fnv 0x00c864b0
void hkpMotion::SetTranslationalVelocity(const hkVector4& velocity)
{
    m_kTranslationalVelocity = velocity;
}

// @fnv 0x00c864d0
void hkpMotion::SetRotationalVelocity(const hkVector4& velocity)
{
    m_kAngularVelocity = velocity;
}

// Reads inverse mass, returning zero for zero inverse mass and the reciprocal otherwise.
// @fnv 0x00c86430
float hkpMotion::GetMassValue()
{
    LocalM128 v = m_kInertiaAndMassInv.m_vComponents;
    float invMass;
    _mm_store_ss(&invMass, _mm_shuffle_ps(v, v, 0xFF));
    if (invMass == 0.0f)
        return 0.0f;
    float mass = 1.0f / invMass;
    return mass;
}
