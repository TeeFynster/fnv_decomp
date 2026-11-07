#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/havok/common/internal/collide/gsk/hkgsk_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/collide/gsk/hkgsk_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/internal/collide/gsk/hkgsk_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/internal/collide/gsk/hkgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/internal/collide/gsk/hkgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/gsk/hkgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/Transform.h"
struct __declspec(align(16)) Scalar4
{
    float x, y, z, w;
};
struct Differences
{
    Scalar4 d0, d1, d2, d3;
};
struct SimplexContext
{
    SimplexContext()
    {}
    Transform transform;
    Scalar4 tolerance;
    float epsilon;
    const void* shapeA;
    const void* shapeB;
    int status;
    hkVector4* pointsA;
    hkVector4* pointsB;
    Scalar4* differences;
    int count;
    int ProcessEntries_00e63770(hkVector4*);
};
void __cdecl Object_CopyData_00e62740(const void*, const void*, const Transform*, hkVector4*, hkVector4*,
                          hkVector4*);
template <class T> struct Ref
{
    T* p;
    T* operator->() const
    {
        return p;
    }
    operator T*() const
    {
        return p;
    }
};
struct Simplex
{
    __m128 unk00, unk10;
    hkVector4 pointsA[4];
    __m128 unk60, unk70, unk80, unk90;
    hkVector4 transformedB[4];
    hkVector4 pointsB[4];
    hkVector4 result;
    void ProcessEntries_00e4c230(const void*, const void*, const Transform*, int*, int*, hkVector4*);
};
// @fnv 0x00e4c230
// src: GUESS 0x00e4c230 (confidence: low)
void Simplex::ProcessEntries_00e4c230(const void* shapeA, const void* shapeB, const Transform* transform, int* countA, int* countB,
                           hkVector4* output)
{
    int simplexCount = 4;
    if (*countB >= 3)
    {
        if (*countB > 3)
        {
            pointsA[3].quad = pointsA[0].quad;
        }
        else if (*countA > 1)
        {
            pointsA[3].quad = pointsA[1].quad;
            pointsB[3].quad = pointsB[0].quad;
            transformedB[3].quad = transformedB[0].quad;
        }
        else
            simplexCount = 3;
        pointsA[1].quad = pointsA[0].quad;
        pointsA[2].quad = pointsA[0].quad;
    }
    else if (*countA >= 3)
    {
        if (*countA > 3)
        {
            pointsB[3].quad = pointsB[0].quad;
            transformedB[3].quad = transformedB[0].quad;
        }
        else if (*countB > 1)
        {
            pointsA[3].quad = pointsA[0].quad;
            pointsB[3].quad = pointsB[1].quad;
            transformedB[3].quad = transformedB[1].quad;
        }
        else
            simplexCount = 3;
        pointsB[1].quad = pointsB[0].quad;
        transformedB[1].quad = transformedB[0].quad;
        pointsB[2].quad = pointsB[0].quad;
        transformedB[2].quad = transformedB[0].quad;
    }
    else
    {
        Scalar4 t = *reinterpret_cast<const Scalar4*>(&pointsA[0]);
        __m128 a = _mm_load_ps(&t.x);
        pointsA[*countA].quad = a;
        pointsA[*countA + 1].quad = a;
        t = *reinterpret_cast<const Scalar4*>(&pointsB[0]);
        __m128 b = _mm_load_ps(&t.x);
        pointsB[*countB].quad = b;
        pointsB[*countB + 1].quad = b;
        t = *reinterpret_cast<const Scalar4*>(&transformedB[0]);
        __m128 tb = _mm_load_ps(&t.x);
        transformedB[*countB].quad = tb;
        transformedB[*countB + 1].quad = tb;
        simplexCount = 1;
    }
    Differences differences;
    SimplexContext context;
    float tolerance = 0.0001f;
    context.epsilon = 0.0001f * 0.0001f;
    _mm_store_ps(&differences.d0.x, _mm_sub_ps(pointsA[0].quad, transformedB[0].quad));
    _mm_store_ps(&differences.d1.x, _mm_sub_ps(pointsA[1].quad, transformedB[1].quad));
    _mm_store_ps(&differences.d2.x, _mm_sub_ps(pointsA[2].quad, transformedB[2].quad));
    _mm_store_ps(&differences.d3.x, _mm_sub_ps(pointsA[3].quad, transformedB[3].quad));
    context.transform.r[0] = transform->r[0];
    context.transform.r[1] = transform->r[1];
    context.transform.r[2] = transform->r[2];
    context.transform.r[3] = transform->r[3];
    _mm_store_ps(&context.tolerance.x, _mm_shuffle_ps(_mm_load_ss(&tolerance), _mm_load_ss(&tolerance), 0));
    context.shapeA = shapeA;
    context.shapeB = shapeB;
    context.status = 0;
    context.pointsA = pointsA;
    context.pointsB = pointsB;
    context.differences = &differences.d0;
    context.count = simplexCount;
    if (context.ProcessEntries_00e63770(output) == 5)
    {
        Object_CopyData_00e62740(shapeA, shapeB, transform, pointsA, pointsB, output);
        *countA = 1;
        *countB = 1;
    }
    else
    {
        *countA = 3;
        *countB = 3;
        if ((pointsA[1].quad.m128_u32[3] & 0xc0ffffff) == (pointsA[2].quad.m128_u32[3] & 0xc0ffffff) ||
            (pointsA[0].quad.m128_u32[3] & 0xc0ffffff) == (pointsA[2].quad.m128_u32[3] & 0xc0ffffff))
            --*countA;
        if (*countA >= 2 && ((pointsA[0].quad.m128_u32[3] ^ pointsA[1].quad.m128_u32[3]) & 0xc0ffffff) == 0)
        {
            --*countA;
            pointsA[0].quad = pointsA[*countA].quad;
        }
        if ((pointsB[1].quad.m128_u32[3] & 0xc0ffffff) == (pointsB[2].quad.m128_u32[3] & 0xc0ffffff) ||
            (pointsB[0].quad.m128_u32[3] & 0xc0ffffff) == (pointsB[2].quad.m128_u32[3] & 0xc0ffffff))
            --*countB;
        if (*countB >= 2 && ((pointsB[0].quad.m128_u32[3] ^ pointsB[1].quad.m128_u32[3]) & 0xc0ffffff) == 0)
        {
            --*countB;
            pointsB[0].quad = pointsB[*countB].quad;
        }
        Scalar4 c0 = *reinterpret_cast<const Scalar4*>(&transform->r[0]);
        Scalar4 c1 = *reinterpret_cast<const Scalar4*>(&transform->r[1]);
        Scalar4 c2 = *reinterpret_cast<const Scalar4*>(&transform->r[2]);
        Scalar4 c3 = *reinterpret_cast<const Scalar4*>(&transform->r[3]);
        __m128 x = _mm_load_ps(&c0.x);
        __m128 y = _mm_load_ps(&c1.x);
        __m128 z = _mm_load_ps(&c2.x);
        __m128 t = _mm_load_ps(&c3.x);
        int i = *countB - 1;
        hkVector4* src = &pointsB[i];
        do
        {
            __m128 p = src->quad;
            src[-4].quad = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0x55), y), _mm_mul_ps(_mm_shuffle_ps(p, p, 0), x)),
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0xaa), z), t));
            --i;
            --src;
        } while (i >= 0);
        if (*countA + *countB > 4)
        {
            if (*countA > *countB)
            {
                *countA = 3;
                *countB = 1;
            }
            else
            {
                *countB = 3;
                *countA = 1;
            }
        }
    }
    result.quad = output->quad;
}
