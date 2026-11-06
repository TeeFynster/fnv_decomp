
// src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkpVehicleDefaultAerodynamics.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkpRigidBody.h"
#include "../../../../../../include/hkpVehicleData.h"
#include "../../../../../../include/hkpVehicleInstance.h"

__forceinline hkSimdReal::hkSimdReal(float f)
{
    m_vValue = _mm_load_ss(&f);
}

__forceinline const __m128& hkVector4::getQuad() const
{
    return m_vComponents;
}

__forceinline __m128& hkVector4::getQuad()
{
    return m_vComponents;
}

__forceinline void hkVector4::setZero4()
{
    getQuad() = _mm_setzero_ps();
}

__forceinline void hkVector4::setMul4(float r, const hkVector4& v)
{
    getQuad() = _mm_mul_ps(_mm_load1_ps(&r), v.getQuad());
}

__forceinline void hkVector4::addMul4(const hkSimdReal& r, const hkVector4& v)
{
    __m128 rr = r.m_vValue;
    rr = _mm_shuffle_ps(rr, rr, 0);
    getQuad() = _mm_add_ps(getQuad(), _mm_mul_ps(rr, v.getQuad()));
}

__forceinline float hkVector4::dot3scalar(const hkVector4& v) const
{
    __m128 p = _mm_mul_ps(getQuad(), v.getQuad());
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, _MM_SHUFFLE(2, 2, 2, 2)),
                          _mm_add_ss(_mm_shuffle_ps(p, p, _MM_SHUFFLE(1, 1, 1, 1)), p));
    float f;
    _mm_store_ss(&f, s);
    return f;
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    const __m128 q = b.getQuad();
    __m128 xb = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(0, 0, 0, 0)), r.m_kColumn0.getQuad());
    __m128 yb = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(1, 1, 1, 1)), r.m_kColumn1.getQuad());
    __m128 zb = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(2, 2, 2, 2)), r.m_kColumn2.getQuad());
    getQuad() = _mm_add_ps(_mm_add_ps(xb, yb), zb);
}

__forceinline const hkVector4& hkpRigidBody::getLinearVelocity() const
{
    return m_pMotionState.m_kTranslationalVelocity;
}

__forceinline hkpRigidBody* hkpVehicleInstance::getChassis() const
{
    return static_cast<hkpRigidBody*>(m_pEntity);
}

struct AerodynamicsDragOutputE443
{
    hkVector4 m_kForce;
    hkVector4 m_kTorque;
};

// @fnv 0x00e44370
void hkpVehicleDefaultAerodynamics::vf03(const float fMoveElapsedTime,
                                        const hkpVehicleInstanceE443* pkVehicle,
                                        AerodynamicsDragOutputE443& kDragInfoOut) throw()
{
    // The approved method declaration retains an opaque name for the vehicle parameter.
    const hkpVehicleInstance* vehicle = reinterpret_cast<const hkpVehicleInstance*>(pkVehicle);
    hkpRigidBody* pkChassis = vehicle->getChassis();
    const hkRotation& kRotationBasis = pkChassis->m_pMotionState.m_kMotionState.m_kMotionTransform.m_rotation;

    // The old data proxy began its basis at +0x20; the actual orientation begins at +0x30.
    hkVector4 kForward;
    kForward._setRotatedDir(kRotationBasis, vehicle->m_data->m_kChassisOrientation.m_kColumn1);
    hkVector4 kUp;
    kUp._setRotatedDir(kRotationBasis, vehicle->m_data->m_kChassisOrientation.m_kColumn0);

    const float m_fGain = pkChassis->getLinearVelocity().dot3scalar(kForward);
    const float fDragForce = calcDragForce(m_fGain);
    const float fLiftForce = calcLiftForce(m_fGain);

    kDragInfoOut.m_kForce.setMul4(fDragForce, kForward);
    kDragInfoOut.m_kForce.addMul4(hkSimdReal(fLiftForce), kUp);

    const float fMass = pkChassis->m_pMotionState.GetMassValue();
    kDragInfoOut.m_kForce.addMul4(hkSimdReal(fMass), m_vExtraGravityWorldSpace);
    kDragInfoOut.m_kTorque.setZero4();
}
