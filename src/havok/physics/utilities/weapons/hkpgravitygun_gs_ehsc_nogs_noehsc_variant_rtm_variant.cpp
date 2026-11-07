// src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/weapons/hkpgravitygun.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkpFirstPersonGun.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/FinishingFlag.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/hkpMotion.h"
#include "../../../../../include/hkpRigidBody.h"
#include <xmmintrin.h>
#include "../../../../../include/hkpGravityGun.h"

// The approved hkpGravityGun header lacks the four methods below; retain the real
// class locally until it declares them. Both former gun stand-ins used this layout.

extern double DAT_01011588;
extern const __m128 DAT_010ec7f0;
extern const __m128 DAT_01017d10;

static inline __m128 bcastE45(const float& f)
{
    __m128 s = _mm_load_ss(&f);
    return _mm_shuffle_ps(s, s, 0);
}

inline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
inline hkSimdReal::hkSimdReal(const __m128& v) : m_vValue(v) {}
inline hkSimdReal::operator float() const
{
    float value;
    _mm_store_ss(&value, m_vValue);
    return value;
}
inline hkSimdReal::hkSimdReal(float f)
{
    m_vValue = _mm_load_ss(&f);
}

// src: XBOX_PDB 0x00c7f640
inline __declspec(noinline) void hkVector4::setTransformedPos_00c7f640(const hkTransform& t, const hkVector4& in)
{
    __m128 v = *(__m128*)&in;
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), t.m_row1);
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), t.m_row0);
    __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), t.m_row2);
    *(__m128*)this = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, t.m_row3));
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdReal& s)
{
    __m128 sv = s.broadcast();
    *(__m128*)this = _mm_add_ps(*(__m128*)&a, _mm_mul_ps(sv, *(__m128*)&b));
}
inline void hkVector4::setInterpolate4(const hkVector4& a, const hkVector4& b, const hkSimdReal& t)
{
    __m128 tv = t.broadcast();
    __m128 one_minus_t = _mm_sub_ps(DAT_010ec7f0, tv);
    *(__m128*)this = _mm_add_ps(_mm_mul_ps(one_minus_t, *(__m128*)&a), _mm_mul_ps(tv, *(__m128*)&b));
}
inline int hkVector4::equals4(const hkVector4& a, float eps) const
{
    __m128 diff = _mm_sub_ps(*(__m128*)this, *(__m128*)&a);
    __m128 absDiff = _mm_and_ps(diff, DAT_01017d10);
    __m128 eps_v = _mm_set1_ps(eps);
    return (_mm_movemask_ps(_mm_cmple_ps(absDiff, eps_v)) & 0xf) == 0xf;
}
inline hkSimdReal hkVector4::lengthSquared3() const
{
    __m128 v = *(__m128*)this;
    __m128 mul = _mm_mul_ps(v, v);
    __m128 shuf1 = _mm_shuffle_ps(mul, mul, 0x55);
    __m128 add1 = _mm_add_ss(shuf1, mul);
    __m128 shuf2 = _mm_shuffle_ps(mul, mul, 0xaa);
    __m128 add2 = _mm_add_ss(shuf2, add1);
    return hkSimdReal(add2);
}


// @fnv 0x00e45ee0
// src: XBOX_PDB 0x00e45ee0
void hkpGravityGun::gravityGunPush(int dirSlot, int viewSlot, int p3Slot)
{
    union
    {
        __m128 q;
        float f[4];
    } v;
    if (m_kPickedBodies.m_iElementCount != 0)
    {
        hkpRigidBody* body = hkpGravityGun_dropObject(0);
        v.q = _mm_mul_ps(bcastE45(m_fHoldDistance), *(const __m128*)dirSlot);
        v.f[1] = (float)(v.f[1] + DAT_01011588);
        v.q = _mm_add_ps(((const hkpRigidBody*)viewSlot)->m_pMotionState.m_kTranslationalVelocity, v.q);
        body->OnTrigger(*(const hkVector4*)&v);
        body->m_kCollidable.m_kBroadPhaseHandle.m_ucObjectQualityType = 6;
    }
    else
    {
        hkpRigidBody* body = FindVisibleRigidBodyToGrab(dirSlot, viewSlot, p3Slot);
        if (body)
        {
            __m128 dir = *(const __m128*)dirSlot;
            v.q = dir;
            v.q = _mm_mul_ps(bcastE45(m_fPickAngle), v.q);
            body->activate_00c9c1d0();
            body->m_pMotionState.SetCollisionShape(*(const hkVector4*)&v);
        }
    }
}

// @fnv 0x00e45c90
// src: XBOX_PDB 0x00e45c90
__declspec(noinline) void hkpGravityGun::gravityGunStep(float dTime, const hkTransform& transform,
                                                   hkpRigidBody* otherRb)
{
    for (int i = 0; i < m_kPickedBodies.m_iElementCount; ++i)
    {
        const double gain = 0.4f;
        float invDTime = (float)(gain / dTime);
        hkVector4 localPos;
        localPos.setAddMul4(m_kGrabPosition, m_kTargetPosition, hkSimdReal((float)i));
        hkVector4 targetPos;
        targetPos.setTransformedPos_00c7f640(transform, localPos);
        hkpRigidBody* rb = (hkpRigidBody*)m_kPickedBodies.m_data[i];
        hkVector4 newLinearVelocity = (const hkVector4&)rb->m_pMotionState.m_kTranslationalVelocity;
        newLinearVelocity.setInterpolate4(rb->m_pMotionState.m_kTranslationalVelocity,
                                          otherRb->m_pMotionState.m_kTranslationalVelocity, hkSimdReal(0.8f));
        __m128 deltaPos = _mm_sub_ps(*(__m128*)&targetPos, *(__m128*)&rb->m_pMotionState.m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
        __m128 invDTimeVec = hkSimdReal(invDTime).broadcast();
        *(__m128*)&newLinearVelocity = _mm_add_ps(_mm_mul_ps(deltaPos, invDTimeVec), *(__m128*)&newLinearVelocity);
        if (!newLinearVelocity.equals4(rb->m_pMotionState.m_kTranslationalVelocity, 0.001f))
        {
            rb->activate_00c9c1d0();
            rb->m_pMotionState.SetTranslationalVelocity(newLinearVelocity);
        }
        const float minSq = 1.0f;
        hkVector4 newAngularVelocity;
        *(__m128*)&newAngularVelocity =
            _mm_mul_ps(hkSimdReal(0.8f).broadcast(), *(__m128*)&rb->m_pMotionState.m_kAngularVelocity);
        if (float(newAngularVelocity.lengthSquared3()) > minSq)
        {
            if (!newAngularVelocity.equals4(rb->m_pMotionState.m_kAngularVelocity, 0.001f))
            {
                rb->activate_00c9c1d0();
                rb->m_pMotionState.SetRotationalVelocity(newAngularVelocity);
            }
        }
    }
}
