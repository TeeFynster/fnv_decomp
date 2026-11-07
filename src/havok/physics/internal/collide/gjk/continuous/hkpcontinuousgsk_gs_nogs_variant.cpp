// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <math.h>
// Havok-style bisection: find the sample time t where the support distance along the target plane reaches target.
struct __declspec(align(16)) Sample
{
    unsigned int d[76];
};
struct Out
{
    float t;
    float u[3];
    __m128 pos;
};
void hkTransform_setMulInverseMul_UpdateState_00db4b50(void* a, float t, Sample* out);
extern const double DAT_010290b0;  // 0.5
extern const double DAT_0101ffa0;  // 0.1
extern const float DAT_0101e2bc;   // 0.1f
extern const double DAT_0106b9e8;  // 0.9
extern const float DAT_010177e8;   // 0.9f
// @fnv 0x00db4ca0
// src: GUESS 0x00db4ca0 (confidence: low)
float Object_ProcessEntries_00db4ca0(void* a, const float* target, const __m128* origin, float A, float B, float C, float D, int unused,
                   Out* res)
{
    float t = A;
    float eps = (float)(target[4] * DAT_010290b0);
    for (int i = 0; i < 10; i++)
    {
        if (*target >= C)
            break;
        float d = D - C;
        if (d > -eps)
            break;
        t = (*target - C) / d;
        if (!(i & 1))
        {
            if (!(t > DAT_0101ffa0))
                t = DAT_0101e2bc;
            if (!(t < DAT_0106b9e8))
                t = DAT_010177e8;
        }
        Sample s;
        t = (1.0f - t) * A + B * t;
        hkTransform_setMulInverseMul_UpdateState_00db4b50(a, t, &s);
        __m128 w = *(__m128*)&s.d[48];
        __m128 v = _mm_mul_ps(_mm_sub_ps(*origin, *(__m128*)&s.d[52]), w);
        __m128 p = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), _mm_shuffle_ps(w, w, 0xff));
        __m128 q = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
        float r;
        _mm_store_ss(&r, _mm_add_ps(p, q));
        float e = (float)fabs((float)(r - *target));
        if (e < eps)
            break;
        if (r < *target)
        {
            B = t;
            D = r;
        }
        else
        {
            A = t;
            C = r;
        }
    }
    if (t < res->t)
    {
        res->t = t;
        res->pos = *origin;
    }
    return res->t;
}
