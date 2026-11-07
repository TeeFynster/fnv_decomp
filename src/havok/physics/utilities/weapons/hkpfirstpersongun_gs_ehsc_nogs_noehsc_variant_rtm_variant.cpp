
// src/havok/physics/utilities/weapons/hkpfirstpersongun_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpfirstpersongun_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/weapons/hkpfirstpersongun_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/weapons/hkpfirstpersongun.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/weapons/hkpfirstpersongun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpfirstpersongun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkVector4.h"

#include <xmmintrin.h>

extern float DAT_0104da4c;
extern double DAT_01011598;

static __inline __m128 splat(const float* p)
{
    __m128 s = _mm_load_ss(p);
    return _mm_shuffle_ps(s, s, 0);
}

// @fnv 0x00e463d0
// src: XBOX_PDB 0x00e463d0
void __cdecl hkpFirstPersonGun_calcVelocityToTarget(const hkVector4& from, const hkVector4& to, const hkVector4& dir, float t, hkVector4& out)
{
    float eps = DAT_0104da4c;
    float temp;

    __m128 a = *(const __m128*)&from;
    __m128 b = *(const __m128*)&to;
    __m128 diff = _mm_sub_ps(b, a);

    __m128 sq = _mm_mul_ps(diff, diff);
    __m128 y = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 z = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 sum = _mm_add_ss(y, sq);
    sum = _mm_add_ss(z, sum);
    __m128 len = _mm_sqrt_ss(sum);

    float dist;
    _mm_store_ss(&dist, len);

    if (eps < dist)
    {
        float invRatio = dist / t;
        float factor = (float)(invRatio * DAT_01011598);
        const __m128 c = *(const __m128*)&dir;

        temp = factor;
        __m128 vec_a = _mm_mul_ps(splat(&temp), c);

        __m128 sq_a = _mm_mul_ps(vec_a, vec_a);
        __m128 y_a = _mm_shuffle_ps(sq_a, sq_a, 0x55);
        __m128 z_a = _mm_shuffle_ps(sq_a, sq_a, 0xaa);
        __m128 sum_a = _mm_add_ss(y_a, sq_a);
        sum_a = _mm_add_ss(z_a, sum_a);
        __m128 len_a_vec = _mm_sqrt_ss(sum_a);

        _mm_store_ss(&temp, len_a_vec);

        float len_a = temp;

        if (len_a > t)
        {
            float s = t / len_a;
            temp = s;
            vec_a = _mm_mul_ps(splat(&temp), vec_a);
        }
        float ratio = t / dist;
        temp = ratio;
        *(__m128*)&out = _mm_add_ps(_mm_mul_ps(splat(&temp), diff), vec_a);
    }
    else
    {
        *(__m128*)&out = diff;
    }
}
