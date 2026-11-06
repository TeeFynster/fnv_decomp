
// src/havok/physics/dynamics/motion/rigid/hkpcharactermotion_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/motion/rigid/hkpcharactermotion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/motion/rigid/hkpcharactermotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpcharactermotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpCharacterMotion.h"
#include "../../../../../../include/hkpSphereMotion.h"

// The shared character class lacks this override; keep its body here with the original ECX/stack ABI.
// @fnv 0x00d1f050
void __fastcall GetCharacterProjectedPointVelocity(const hkpCharacterMotion* motion, void*,
                                                   const hkVector4* pos, const hkVector4* normal,
                                                   float* out_vel, float* out_inv_mass)
{
    __m128 com = _mm_load_ps((const float*)&motion->m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
    __m128 arm = _mm_sub_ps(_mm_load_ps((const float*)pos), com);
    __m128 n = _mm_load_ps((const float*)normal);
    __m128 lin = _mm_mul_ps(_mm_load_ps((const float*)&motion->m_kTranslationalVelocity), n);
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(n, n, 0xc9), _mm_shuffle_ps(arm, arm, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(n, n, 0xd2), _mm_shuffle_ps(arm, arm, 0xc9)));
    __m128 ang = _mm_mul_ps(_mm_load_ps((const float*)&motion->m_kAngularVelocity), cross);
    __m128 a1 = _mm_add_ss(_mm_shuffle_ps(ang, ang, 0x55), ang);
    __m128 a2 = _mm_add_ss(_mm_shuffle_ps(ang, ang, 0xaa), a1);
    __m128 l1 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0x55), lin);
    __m128 l2 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0xaa), l1);
    __m128 sum = _mm_add_ss(a2, l2);
    float fv = _mm_cvtss_f32(sum);
    *out_vel = fv;
    *out_inv_mass = motion->m_kInertiaAndMassInv.w;
}
