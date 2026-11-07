
// src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/motor/hkpmotoraction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkpMotorAction.h"
#include "../../../../../../include/hkpRigidBody.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkSimdReal.h"

#include <xmmintrin.h>

inline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}

inline hkSimdReal::hkSimdReal(float f)
{
    m_vValue = _mm_load_ss(&f);
}

inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}


inline hkMatrix3::hkMatrix3()
{}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 res = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xAA), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    return res;
}

inline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& a)
{
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents);
}

struct TimeInterval
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
};

struct Motion
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void GetInertiaLocal(hkMatrix3& m) const;
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void StepMotion(float dt, const hkVector4& t);
    int unk04;
    int unk08;
    int unk0C;
};

// The shared hkpMotion has untyped vf14/vf60 slots; retain Motion above
// until it declares GetInertiaLocal and StepMotion with their arguments.
inline void StepMotion(hkpRigidBody* rb, float dt, const hkVector4& t)
{
    rb->activate_00c9c1d0();
    reinterpret_cast<Motion*>(&rb->m_pMotionState)->StepMotion(dt, t);
}

// The shared hkpMotorAction does not yet declare this entry point.
struct MotorAction : hkpMotorAction
{
    void hkpMotorAction_applyAction(const TimeInterval& stepInfo);
};

// @fnv 0x00d4d860
// src: HAVOK_SRC 0x00d4d860
void MotorAction::hkpMotorAction_applyAction(const TimeInterval& stepInfo)
{
    if (!m_bSlotEnabled)
        return;
    hkpRigidBody* rb = static_cast<hkpRigidBody*>(m_pEntity);

    hkVector4 currentAngVel;
    const hkRotation& rotation = reinterpret_cast<const hkRotation&>(
        rb->m_pMotionState.m_kMotionState.m_kMotionTransform);
    currentAngVel.hkVector4_setRotatedInverseDir(rotation, rb->m_pMotionState.m_kAngularVelocity);

    const hkVector4& axis = m_kAxisEndPoints;
    float currentRate = currentAngVel.dot3(axis);
    float deltaRate = m_fSpinRate - currentRate;
    hkVector4 angularDelta;
    angularDelta.setMul4(hkSimdReal(deltaRate * m_fGain), axis);

    __declspec(align(16)) hkMatrix3 worldInertia;
    reinterpret_cast<const Motion*>(&rb->m_pMotionState)->GetInertiaLocal(worldInertia);

    angularDelta.hkVector4_setMul3(worldInertia, angularDelta);
    angularDelta.hkVector4_setRotatedDir(rotation, angularDelta);

    StepMotion(rb, stepInfo.m_fTimeStep, angularDelta);
}
