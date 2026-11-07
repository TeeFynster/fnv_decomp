#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/Vec4.h"


// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
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

// @fnv 0x00dedbb0
// src: XBOX_PDB 0x00dedbb0
bool __cdecl hkGeometryProcessingInternals_generateRandomDistribution(Owner* self, int count, Vec4Array* out, Obj* obj)
{
    // Preserve the original uninitialized SIMD storage without invoking Vec4 constructors.
    __m128 pairStorage[2];
    Vec4Pair& pair = *(Vec4Pair*)pairStorage;
    __m128 scratchStorage;
    Vec4& scratch = *(Vec4*)&scratchStorage;
    __m128 deltaStorage;
    Vec4& delta = *(Vec4*)&deltaStorage;
    __m128 baseStorage;
    Vec4& base = *(Vec4*)&baseStorage;
    __m128 curStorage;
    Vec4& cur = *(Vec4*)&curStorage;
    int limit;
    unsigned char flag;
    int tries;

    self->ProcessEntries_00e11530(&pair);
    base = pair.a;
    _mm_store_ps((float*)(void*)&delta,
                 _mm_sub_ps(pairStorage[1], pairStorage[0]));
    tries = 0;
    limit = count * 8;
    while (count != 0)
    {
        cur = DAT_01267e30;
        flag = 1;
        obj->NextFloat4(&cur);
        _mm_store_ps((float*)(void*)&cur, _mm_add_ps(_mm_mul_ps(*(__m128*)&cur, *(__m128*)&delta), *(__m128*)&base));
        self->ProcessAndReturnValue_00e13660(&cur, &scratch, &flag);
        if (flag != 0)
        {
            cur.w = 1.0f;
            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            if (out->m_04 == (int)(out->m_08 & 0x3fffffff))
            {
                ResizeAudioStream(holder->m_heap, out, 0x10);
            }
            Vec4* __restrict dst = out->m_00 + out->m_04;
            _mm_store_ps((float*)dst, _mm_load_ps((const float*)&cur));
            count--;
            _ReadBarrier();
            out->m_04++;
            tries = 0;
        }
        else
        {
            tries++;
            if (tries > limit)
            {
                break;
            }
        }
    }
    return count == 0;
}
