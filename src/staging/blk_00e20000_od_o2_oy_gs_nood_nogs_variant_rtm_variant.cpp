#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/staging/blk_00e20000_od_o2_oy_gs_nood_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e20000_od_o2_oy_gs_nood_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/staging/blk_00e20000_od_o2_oy_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /Oy /GS- /EHsc /Gy (unit src/staging/blk_00e20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00e20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_set_ss;
using ::_mm_load_ss;
using ::_mm_add_ss;
using ::_mm_mul_ss;
using ::_mm_div_ss;
using ::_mm_shuffle_ps;
using ::_mm_add_ps;
using ::_mm_mul_ps;
}
extern float DAT_01012068;
extern float DAT_01011d78;

static __forceinline LocalM128 inverseSpan(LocalM128 a, LocalM128 b)
{
    return _mm_div_ss(_mm_load_ss(&DAT_01012068), _mm_add_ss(a, b));
}
// @fnv 0x00e33760
// src: GUESS 0x00e33760 (confidence: low)
void Object_UpdateFields_00e33760(float t, int unused, const float* knots, const LocalM128* ctrl, LocalM128* out)
{
    float f;
    LocalM128 left[4], right[4];

    f = t - knots[2];
    left[1] = _mm_load_ss(&f);
    f = knots[3] - t;
    right[1] = _mm_load_ss(&f);
    LocalM128 inv = inverseSpan(right[1], left[1]);
    LocalM128 n12 = _mm_mul_ss(right[1], inv);
    f = t - knots[1];
    left[2] = _mm_load_ss(&f);
    f = knots[4] - t;
    right[2] = _mm_load_ss(&f);
    LocalM128 zero = _mm_load_ss(&DAT_01011d78);
    LocalM128 n03 = _mm_div_ss(_mm_add_ss(zero, n12), _mm_add_ss(right[1], left[2]));
    LocalM128 n22 = _mm_div_ss(_mm_mul_ss(left[1], inv), _mm_add_ss(right[2], left[1]));
    f = t - knots[0];
    left[3] = _mm_load_ss(&f);
    f = knots[5] - t;
    right[3] = _mm_load_ss(&f);
    LocalM128 b0t = _mm_div_ss(_mm_add_ss(zero, _mm_mul_ss(right[1], n03)), _mm_add_ss(right[1], left[3]));
    LocalM128 b0 = _mm_add_ss(zero, _mm_mul_ss(right[1], b0t));
    LocalM128 n13 =
        _mm_div_ss(_mm_add_ss(_mm_mul_ss(left[2], n03), _mm_mul_ss(right[2], n22)), _mm_add_ss(right[2], left[2]));
    LocalM128 rightTerm = _mm_mul_ss(right[2], n13);
    LocalM128 b1 = _mm_add_ss(_mm_mul_ss(left[3], b0t), rightTerm);
    LocalM128 n23 = _mm_div_ss(_mm_mul_ss(left[1], n22), _mm_add_ss(right[3], left[1]));
    LocalM128 b2left = _mm_mul_ss(left[2], n13);
    LocalM128 b2right = _mm_mul_ss(right[3], n23);
    LocalM128 b3 = _mm_mul_ss(left[1], n23);
    LocalM128 b2 = _mm_add_ss(b2left, b2right);
    LocalM128 sum = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b1, b1, 0), ctrl[1]),
                                                  _mm_mul_ps(_mm_shuffle_ps(b0, b0, 0), ctrl[0])),
                                       _mm_mul_ps(_mm_shuffle_ps(b2, b2, 0), ctrl[2])),
                            _mm_mul_ps(_mm_shuffle_ps(b3, b3, 0), ctrl[3]));
    *out = sum;
}
