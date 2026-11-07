// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/geometryprocessing/hkgeometryprocessing_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/Vec4.h"

extern "C" void __cdecl Deallocate(void*);
extern int DAT_010d9fc4;
struct FUN_00dee620
{
    void* m_pVTable;
    __thiscall FUN_00dee620(int testFlag);
};
extern "C" void __cdecl hkVector4_ProcessEntries_00dedf10(void*, void*, void*, void*, int, int);
void __cdecl hkGeometryProcessing_generateRandomDistribution(void* first, void* second, void* third, void* fourth);
struct FUN_00dee6b0_Class
{
    int unk00;
    float unk04;
    float GetUnk04(int testFlag);
};
extern int DAT_010cd664;
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00dee6c0_cls
{
    int m_vptr;

    FUN_00dee6c0_cls* FUN_00dee6c0(unsigned char acFlags);
};
#include <xmmintrin.h>
#include <math.h>
struct SphereInput276
{
    float a, b;
};
struct __declspec(align(16)) SphereOutput276
{
    __m128 value;
};
// @fnv 0x00de9650
// src: GUESS 0x00de9650 (confidence: medium)
extern "C" void Geometry_MapCoordinatesToSphere(SphereInput276* in, SphereOutput276* out)
{
    float u = 2.0 * in->a - 1.0;
    float v = 2.0 * in->b - 1.0;
    float sum = u + v;
    float difference = v - u;
    float radius, sign, angle;
    if (v >= 0.0f)
    {
        if (u >= 0.0f)
        {
            if (sum <= 1.0f)
            {
                radius = sum;
                sign = 1.0f;
                angle = v / radius;
            }
            else
            {
                radius = 2.0 - sum;
                sign = -1.0f;
                angle = (1.0f - u) / radius;
            }
        }
        else
        {
            if (difference <= 1.0f)
            {
                radius = difference;
                sign = 1.0f;
                angle = 1.0f - u / radius;
            }
            else
            {
                radius = 2.0 - difference;
                sign = -1.0f;
                angle = 1.0f + (1.0f - v) / radius;
            }
        }
    }
    else
    {
        if (u < 0.0f)
        {
            if (sum >= -1.0f)
            {
                radius = -sum;
                sign = 1.0f;
                angle = 2.0 - v / radius;
            }
            else
            {
                radius = sum + 2.0;
                sign = -1.0f;
                angle = 2.0 + (1.0f + u) / radius;
            }
        }
        else
        {
            if (difference >= -1.0f)
            {
                radius = -difference;
                sign = 1.0f;
                angle = 3.0 + u / radius;
            }
            else
            {
                radius = difference + 2.0;
                sign = -1.0f;
                angle = 3.0 + (1.0f + v) / radius;
            }
        }
    }
    if (radius == 0.0f)
        angle = 0.0f;
    else
        angle *= 1.5707963705062866;
    float squared = radius * radius;
    float radialSquared = 2.0 - squared;
    float radialRoot = (float)sqrt(radialSquared);
    radius = radialRoot * radius;
    float cosine = (float)cos(angle);
    float x = cosine * radius;
    float sine = (float)sin(angle);
    float z = sine * radius;
    float y = (1.0f - squared) * sign;
    out->value = _mm_setr_ps(x, z, y, 0.0f);
}
extern "C" void _ReadBarrier();
__declspec(align(16)) struct Vec4Pair
{
    Vec4 a;
    Vec4 b;
};
struct Vec4Array
{
    Vec4* m_00;
    int m_04;
    unsigned int m_08;
};
struct Owner
{
    void ProcessEntries_00e11530(Vec4Pair* out);
    float ProcessAndReturnValue_00e13660(Vec4* p, Vec4* q, unsigned char* ok);
};
struct Obj
{
    void NextFloat4(Vec4* p);
};
void __cdecl ResizeAudioStream(void* allocator, Vec4Array* arr, int elemSize);
extern Vec4 DAT_01267e30;
bool __cdecl hkGeometryProcessingInternals_generateRandomDistribution(Owner* self, int count, Vec4Array* out, Obj* obj);

#include <xmmintrin.h>

extern __declspec(align(16)) float DAT_010c7160[4];
extern float DAT_01012054;

// @fnv 0x00de9e10
// src: XBOX_PDB 0x00de9e10
float __cdecl hkGeometryProcessing_squaredDistanceFromPointToLine(float* arg1, float* arg2, float* arg3, float* result, float* optionalResult)
{
    __m128 b = _mm_load_ps(arg2);
    __m128 a = _mm_load_ps(arg1);
    __m128 d1 = _mm_sub_ps(b, a);
    __m128 c = _mm_load_ps(arg3);
    __m128 d2 = _mm_sub_ps(c, b);
    __m128 n2 = _mm_mul_ps(d2, d2);
    __m128 m = _mm_mul_ps(d2, d1);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), xy);
    __m128 num = _mm_sub_ss(_mm_load_ps(DAT_010c7160), sum);
    __m128 nxy = _mm_add_ss(_mm_shuffle_ps(n2, n2, 0x55), n2);
    __m128 nsum = _mm_add_ss(_mm_shuffle_ps(n2, n2, 0xaa), nxy);
    float t;
    _mm_store_ss(&t, _mm_div_ss(num, nsum));
    float k = t < 0.0f ? 0.0f : t > 1.0f ? 1.0f : t;
    __m128 factor = _mm_load_ss(&k);
    __m128 v = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), d2), d1);
    __m128 neg = _mm_load_ss(&DAT_01012054);
    _mm_store_ps(result, _mm_mul_ps(_mm_shuffle_ps(neg, neg, 0), v));
    if (optionalResult)
        *optionalResult = k;
    __m128 sq = _mm_mul_ps(v, v);
    __m128 sqxy = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 sqsum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), sqxy);
    _mm_store_ss(&k, sqsum);
    return k;
}
