
// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpWheelConstraintData.h"
#include <xmmintrin.h>
#include <math.h>

static __forceinline __m128 WheelAngleCross(const __m128& b, const __m128& a)
{
    __m128 p = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 q = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(p, q);
}

static __forceinline __m128 WheelAnglePerpendicular(const __m128& a, const __m128& b)
{
    __m128 left = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 right = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(left, right);
}
struct WheelAngleScalar
{
    __m128 v;
    __forceinline WheelAngleScalar(float x)
    {
        v = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(v, v, 0);
    }
};
// @fnv 0x00d4e480
// src: GUESS 0x00d4e480 (confidence: low)
void __fastcall hkpWheelConstraintData_UpdateFields_00d4e480(hkpWheelConstraintData* self, void*, float angle)
{
    // The shared atoms header exposes padding: rotation B columns 0 and 2 are at +0xf0 and +0x110.
    __m128& steeringDirection = *reinterpret_cast<__m128*>(self->m_kBridgeAtoms.pad0 + 0xf0);
    __m128& perpendicularDirection = *reinterpret_cast<__m128*>(self->m_kBridgeAtoms.pad0 + 0x110);
    float s = sinf(angle);
    float c = sqrtf(1.0f - s * s);
    WheelAngleScalar co(c);
    WheelAngleScalar si(s);
    __m128 cr = WheelAngleCross(self->m_kAxleDirectionInBodyB.m_vComponents, self->m_kSteeringDirectionInBodyB.m_vComponents);
    __m128 st = _mm_mul_ps(cr, si.broadcast());
    __m128 ct = _mm_mul_ps(co.broadcast(), self->m_kAxleDirectionInBodyB.m_vComponents);
    __m128 result = _mm_add_ps(st, ct);
    steeringDirection = result;
    perpendicularDirection = WheelAnglePerpendicular(result, self->m_kSteeringDirectionInBodyB.m_vComponents);
}
