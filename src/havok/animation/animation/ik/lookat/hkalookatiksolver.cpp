
// src/havok/animation/animation/ik/lookat/hkalookatiksolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/ik/lookat/hkalookatiksolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
float __cdecl ClampAsin(float value);
float __cdecl Hkaskeletonutils_ForwardCall_00ce00f0(float a, float b);

extern "C" const double DAT_01032980;  // 1.0e-4, the length epsilon
static const float kZero = 0.0f;       // the game's DAT_01011d78

// Computes the three-component length; if it is not below the threshold, stores that length, a function of x and y, and a clamped asin of z over the length.
// @fnv 0x00ce01c0
// src: GUESS 0x00ce01c0 (confidence: low)
void __cdecl Object_ProcessAndReturnValue_00ce01c0(__m128* vec)
{
    const float* pFloats = (const float*)vec;

    __m128 vInput = *vec;
    __m128 vSquared = _mm_mul_ps(vInput, vInput);
    __m128 vSumXY = _mm_add_ss(_mm_shuffle_ps(vSquared, vSquared, 0x55), vSquared);
    __m128 vSumXYZ = _mm_add_ss(_mm_shuffle_ps(vSquared, vSquared, 0xaa), vSumXY);

    // the sqrt result has to travel through memory to reach the x87 stack
    float lenTmp;
    _mm_store_ss(&lenTmp, _mm_sqrt_ss(vSumXYZ));
    struct PlanarConversion
    {
        float x, y, radius;
    };
    PlanarConversion point;
    point.radius = lenTmp;

    if (point.radius < DAT_01032980)
    {
        *vec = _mm_setzero_ps();
        return;
    }

    point.x = pFloats[0];
    point.y = pFloats[1];
    float phi = ClampAsin(pFloats[2] / point.radius);
    // The saved Cartesian y is no longer needed after computing the heading.
    point.y = Hkaskeletonutils_ForwardCall_00ce00f0(point.y, point.x);

    *vec = _mm_setr_ps(point.radius, point.y, phi, kZero);
}
