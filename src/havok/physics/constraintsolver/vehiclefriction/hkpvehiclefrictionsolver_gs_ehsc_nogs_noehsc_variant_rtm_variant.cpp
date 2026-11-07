// src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>

struct CurveInput
{
    __m128 points[2];
    __m128 origin, axis, normal, offsetDirection;
    __m128 matrix0, matrix1, matrix2;
    float common, scale0, scale1;
    float radius[2];
    float blend;
};
struct CurveBlock
{
    float samples[16];
    float multiplier, progress, scale, inverseScale, effectiveScale;
    float radius, inverseRadius, weight0, weight1;
};
struct CurveOutput
{
    float separation, common;
    CurveBlock blocks[2];
};

extern "C" double pow(double, double);
extern "C" double fabs(double);
extern "C" const double DAT_010ec9e0;

static __m128 HSum(__m128 m)
{
    __m128 t = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), t);
}

static float Abs(float x)
{
    return (float)fabs(x);
}
static float Power(float x, float y)
{
    return (float)pow(x, y);
}
static float PowerStep(float x)
{
    return (float)pow(x, DAT_010ec9e0);
}

// @fnv 0x00e593f0
// src: XBOX_PDB 0x00e593f0
void hkVehicleFrictionDescriptionInitValues(CurveInput* a, CurveOutput* b)
{
    b->common = a->common;
    b->blocks[0].radius = a->radius[0];
    b->blocks[1].radius = a->radius[1];
    b->blocks[0].inverseRadius = 1.0f / a->radius[0];
    b->blocks[1].inverseRadius = 1.0f / a->radius[1];
    b->blocks[0].scale = a->scale0 * b->blocks[0].inverseRadius;
    b->blocks[1].scale = a->scale1 * b->blocks[1].inverseRadius;
    b->blocks[0].inverseScale = 1.0f / b->blocks[0].scale;
    b->blocks[1].inverseScale = 1.0f / b->blocks[1].scale;

    float d1;
    _mm_store_ss(&d1, HSum(_mm_mul_ps(a->normal, a->points[0])));
    float d2;
    _mm_store_ss(&d2, HSum(_mm_mul_ps(a->points[1], a->normal)));
    float e = Abs(d1 - d2);
    b->separation = e;
    float r = 1.0f / e;
    b->blocks[0].weight0 = 1.0f - a->blend;
    double neg = -d2;
    b->blocks[0].weight1 = Abs(neg * r) * a->blend;
    b->blocks[1].weight0 = 1.0f - a->blend;
    b->blocks[1].weight1 = Abs(d1 * r) * a->blend;

    __m128 a30 = a->axis;
    __m128 a30c9 = _mm_shuffle_ps(a30, a30, 0xc9);
    __m128 a50 = a->offsetDirection;
    __m128 a20 = a->origin;
    __m128 a30d2 = _mm_shuffle_ps(a30, a30, 0xd2);

    float T[2];
    int k;
    for (k = 0; k < 2; ++k)
    {

        float s = -a->radius[k];
        __m128 scalar = _mm_load_ss(&s);
        __m128 u = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), a50), _mm_sub_ps(a->points[k], a20));
        __m128 uc9 = _mm_shuffle_ps(u, u, 0xc9);
        __m128 ud2 = _mm_shuffle_ps(u, u, 0xd2);
        __m128 X = _mm_sub_ps(_mm_mul_ps(uc9, a30d2), _mm_mul_ps(ud2, a30c9));
        float b4 = b->common;
        __m128 Y = _mm_mul_ps(_mm_shuffle_ps(X, X, 0), a->matrix0);
        Y = _mm_add_ps(Y, _mm_mul_ps(_mm_shuffle_ps(X, X, 0x55), a->matrix1));
        Y = _mm_add_ps(Y, _mm_mul_ps(_mm_shuffle_ps(X, X, 0xaa), a->matrix2));
        float D3;
        _mm_store_ss(&D3, HSum(_mm_mul_ps(Y, X)));
        T[k] = b4 + D3;
    }

    int ebx;
    for (ebx = 0; ebx < 2; ++ebx)
    {
        CurveBlock* bp = &b->blocks[ebx];
        float r1 = T[ebx] * bp->scale;
        bp->effectiveScale = r1;
        float r2 = (float)(r1 * 0.0625);
        bp->progress = r2;
        float r3 = 1.0f / r2;
        double stepValue = PowerStep(r3);
        float r4 = (float)stepValue;
        bp->multiplier = r4;
        float inv1 = 1.0f / r1;
        int cnt;
        for (cnt = 0; cnt < 15; ++cnt)
        {
            float t = 1.0f - r2;
            float v = Power(t, inv1);
            b->blocks[ebx].samples[cnt] = 1.0f - v;
            r2 = r4 * r2;
        }
        b->blocks[ebx].samples[cnt] = 1.0f;
    }
}
