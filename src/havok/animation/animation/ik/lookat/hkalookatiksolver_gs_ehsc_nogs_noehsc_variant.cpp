// src/havok/animation/animation/ik/lookat/hkalookatiksolver_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/ik/lookat/hkalookatiksolver.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/ik/lookat/hkalookatiksolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/ik/lookat/hkalookatiksolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <math.h>
#include <xmmintrin.h>
extern float DAT_01011d78;

// @fnv 0x00ce0110
// src: GUESS 0x00ce0110 (confidence: low)
void __cdecl HkalookatiksolverGsEhscNogsNoehsc_UpdateState_00ce0110(float* v)
{
    volatile float x = v[0];
    float y = v[1];
    float z = v[2];
    float a = (float)cos((double)z) * x;
    float p = (float)cos((double)y) * a;
    float q = (float)sin((double)y) * a;
    float r = (float)sin((double)z) * x;
    __m128 out = _mm_setr_ps(p, q, r, 0.0f);
    _mm_store_ps(v, out);
}
