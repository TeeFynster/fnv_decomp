
// src/havok/common/base/math/quaternion/hkquaternion_gs_nogs_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/base/math/quaternion/hkquaternion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/math/quaternion/hkquaternion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/quaternion/hkquaternion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <math.h>
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQuaternion.h"


inline float& hkVector4::operator()(int i)
{
    return m_f[i];
}

inline const float& hkVector4::operator()(int i) const
{
    return m_f[i];
}

extern const hkVector4 DAT_010c71e0;
extern const hkVector4 DAT_010c71b0;
extern const double DAT_010c8760;
extern const double DAT_01016978;
extern const float DAT_0102b3c8;
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;

float __cdecl ClampedAcos(float val);

namespace MathUtilities {
inline float fabs(float f)
{
    return fabsf(f);
}
}

// @fnv 0x00cb2a50
// src: COMMUNITY 0x00cb2a50
void hkQuaternion::removeAxisComponent(const hkVector4& v)
{
    __m128 q_w = _mm_shuffle_ps((*reinterpret_cast<__m128*>(&unk00)), (*reinterpret_cast<__m128*>(&unk00)), 0xff);

    __m128 prod0 = _mm_mul_ps(v.m_vComponents, (*reinterpret_cast<__m128*>(&unk00)));
    __m128 sum0 = _mm_add_ss(_mm_shuffle_ps(prod0, prod0, 0x55), prod0);
    __m128 dot0 = _mm_add_ss(_mm_shuffle_ps(prod0, prod0, 0xaa), sum0);

    __m128 q_c9 = _mm_shuffle_ps((*reinterpret_cast<__m128*>(&unk00)), (*reinterpret_cast<__m128*>(&unk00)), 0xc9);
    __m128 q_d2 = _mm_shuffle_ps((*reinterpret_cast<__m128*>(&unk00)), (*reinterpret_cast<__m128*>(&unk00)), 0xd2);

    __m128 v_c9 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xc9);
    __m128 qd2_vc9 = _mm_mul_ps(q_d2, v_c9);
    __m128 v_d2 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xd2);
    __m128 qc9_vd2 = _mm_mul_ps(q_c9, v_d2);
    __m128 cross = _mm_sub_ps(qc9_vd2, qd2_vc9);

    __m128 term1 = _mm_mul_ps(cross, q_w);
    __m128 w2 = _mm_mul_ps(q_w, q_w);
    __m128 w2_sub_half = _mm_add_ps(w2, DAT_010c71e0.m_vComponents);

    __m128 dot0_shuf = _mm_shuffle_ps(dot0, dot0, 0);
    __m128 term2 = _mm_mul_ps(dot0_shuf, (*reinterpret_cast<__m128*>(&unk00)));
    __m128 term3 = _mm_mul_ps(w2_sub_half, v.m_vComponents);

    __m128 add1 = _mm_add_ps(term3, term2);
    __m128 add2 = _mm_add_ps(term1, add1);
    __m128 v_rot = _mm_add_ps(add2, add2);

    // dot3(v, v_rot)
    __m128 prod1 = _mm_mul_ps(v.m_vComponents, v_rot);
    __m128 sum1 = _mm_add_ss(_mm_shuffle_ps(prod1, prod1, 0x55), prod1);
    __m128 dot1 = _mm_add_ss(_mm_shuffle_ps(prod1, prod1, 0xaa), sum1);

    float dot;
    _mm_store_ss(&dot, dot1);

    if (dot - 1.0f > DAT_010c8760)
    {
        (*reinterpret_cast<__m128*>(&unk00)) = DAT_010c71b0.m_vComponents;
        return;
    }

    hkVector4 axis;

    if (dot + 1.0f < DAT_01016978)
    {
        int i0 = 0;
        int i1 = 1;
        int i2 = 2;

        float f0 = MathUtilities::fabs(v(0));
        float f1 = MathUtilities::fabs(v(1));
        float f2 = MathUtilities::fabs(v(2));

        if (f1 < f0)
        {
            f0 = f1;
            i1 = 0;
            i0 = 1;
        }
        if (f2 < f0)
        {
            i2 = i0;
        }

        axis.m_vComponents = _mm_setzero_ps();
        axis(i1) = v(i2);
        axis(i2) = -v(i1);

        hkQuaternion_setAxisAngle(axis, DAT_0102b3c8);
        return;
    }

    __m128 vrot_c9 = _mm_shuffle_ps(v_rot, v_rot, 0xc9);
    __m128 vrot_d2 = _mm_shuffle_ps(v_rot, v_rot, 0xd2);

    __m128 t1 = _mm_mul_ps(vrot_c9, v_d2);
    __m128 t2 = _mm_mul_ps(vrot_d2, v_c9);
    __m128 cross2 = _mm_sub_ps(t2, t1);
    __m128 cp_sq = _mm_mul_ps(cross2, cross2);
    __m128 cp_sum1 = _mm_add_ss(_mm_shuffle_ps(cp_sq, cp_sq, 0x55), cp_sq);
    __m128 len_sq = _mm_add_ss(_mm_shuffle_ps(cp_sq, cp_sq, 0xaa), cp_sum1);

    __m128 rsqrt = _mm_rsqrt_ss(len_sq);

    __m128 step1 = _mm_mul_ss(_mm_mul_ss(len_sq, rsqrt), rsqrt);
    __m128 is_zero = _mm_cmpeq_ss(len_sq, _mm_set_ss(0.0f));
    __m128 sub_step = _mm_sub_ss(_mm_set_ss(3.0f), step1);
    __m128 mul1 = _mm_mul_ss(_mm_set_ss(0.5f), rsqrt);
    __m128 mul2 = _mm_mul_ss(mul1, sub_step);
    __m128 inv_len = _mm_andnot_ps(is_zero, mul2);
    __m128 inv_len_bcast = _mm_shuffle_ps(inv_len, inv_len, 0);

    axis.m_vComponents = _mm_mul_ps(inv_len_bcast, cross2);

    hkQuaternion_setAxisAngle(axis, ClampedAcos(dot));
}
