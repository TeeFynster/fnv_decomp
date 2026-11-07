#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/staging/blk_00d20000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00d20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
#include "../../include/hkVector4.h"
struct Transform4
{
    hkVector4 x, y, z, translation;
};
struct ShapeGeometry
{
    void* vtable;
    int userData;
    int type;
    int flags;
    float radius;
    float welding;
    int material;
    int extra;
    __m128 vertices[3];
};
struct CollisionBody
{
    ShapeGeometry* shape;
    int key;
    Transform4* transform;
};
struct BodyPair
{
    CollisionBody* a;
    CollisionBody* b;
};
struct QueryInput
{
    int flags;
    int mode;
    // The query stores its direction at byte 8, without SIMD alignment.
    unsigned char directionStorage[sizeof(hkVector4)];
};
struct ContactResult
{
    __m128 normal;
    hkVector4 first;
    __m128 firstAux;
    hkVector4 second;
    __m128 secondAux;
    __m128 extra;
};
extern float DAT_0104da48;
void __cdecl hkCollideCapsuleUtilCapsVsTri(const __m128*, float, const __m128*, float, const hkVector4*, float, int,
                          ContactResult*, void*);

// @fnv 0x00d39150
// src: GUESS 0x00d39150 (confidence: low)
void __cdecl hkCollideCapsuleUtilCapsVsTri_ProcessEntries_00d39150(BodyPair* bodies, void* unused, QueryInput* input, __m128* output)
{
    ShapeGeometry* shapeA = bodies->a->shape;
    CollisionBody* bodyB = bodies->b;
    ShapeGeometry* shapeB = bodyB->shape;
    __m128 pointsA[2];
    __m128 pointsB[3];
    // The callee fills the result; preserve the original uninitialized storage.
    __m128 resultStorage[sizeof(ContactResult) / sizeof(__m128)];
    ContactResult& result = *reinterpret_cast<ContactResult*>(resultStorage);
    {
        Transform4* transform = bodies->a->transform;
        // Keep the original four scalar word copies into aligned SIMD storage.
        __m128 axisX;
        reinterpret_cast<unsigned int*>(&axisX)[0] = reinterpret_cast<const unsigned int*>(&transform->x)[0];
        reinterpret_cast<unsigned int*>(&axisX)[1] = reinterpret_cast<const unsigned int*>(&transform->x)[1];
        reinterpret_cast<unsigned int*>(&axisX)[2] = reinterpret_cast<const unsigned int*>(&transform->x)[2];
        reinterpret_cast<unsigned int*>(&axisX)[3] = reinterpret_cast<const unsigned int*>(&transform->x)[3];
        __m128 axisY;
        reinterpret_cast<unsigned int*>(&axisY)[0] = reinterpret_cast<const unsigned int*>(&transform->y)[0];
        reinterpret_cast<unsigned int*>(&axisY)[1] = reinterpret_cast<const unsigned int*>(&transform->y)[1];
        reinterpret_cast<unsigned int*>(&axisY)[2] = reinterpret_cast<const unsigned int*>(&transform->y)[2];
        reinterpret_cast<unsigned int*>(&axisY)[3] = reinterpret_cast<const unsigned int*>(&transform->y)[3];
        __m128 axisZ;
        reinterpret_cast<unsigned int*>(&axisZ)[0] = reinterpret_cast<const unsigned int*>(&transform->z)[0];
        reinterpret_cast<unsigned int*>(&axisZ)[1] = reinterpret_cast<const unsigned int*>(&transform->z)[1];
        reinterpret_cast<unsigned int*>(&axisZ)[2] = reinterpret_cast<const unsigned int*>(&transform->z)[2];
        reinterpret_cast<unsigned int*>(&axisZ)[3] = reinterpret_cast<const unsigned int*>(&transform->z)[3];
        __m128 translation;
        reinterpret_cast<unsigned int*>(&translation)[0] = reinterpret_cast<const unsigned int*>(&transform->translation)[0];
        reinterpret_cast<unsigned int*>(&translation)[1] = reinterpret_cast<const unsigned int*>(&transform->translation)[1];
        reinterpret_cast<unsigned int*>(&translation)[2] = reinterpret_cast<const unsigned int*>(&transform->translation)[2];
        reinterpret_cast<unsigned int*>(&translation)[3] = reinterpret_cast<const unsigned int*>(&transform->translation)[3];
        int i = 1;
        do
        {
            __m128 p = shapeA->vertices[i];
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 x = _mm_shuffle_ps(p, p, 0);
            x = _mm_mul_ps(x, axisX);
            y = _mm_mul_ps(y, axisY);
            y = _mm_add_ps(y, x);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            z = _mm_mul_ps(z, axisZ);
            z = _mm_add_ps(z, translation);
            pointsA[i] = _mm_add_ps(y, z);
        } while (--i >= 0);
    }
    {
        Transform4* transform = bodyB->transform;
        // Keep the original four scalar word copies into aligned SIMD storage.
        __m128 axisX;
        reinterpret_cast<unsigned int*>(&axisX)[0] = reinterpret_cast<const unsigned int*>(&transform->x)[0];
        reinterpret_cast<unsigned int*>(&axisX)[1] = reinterpret_cast<const unsigned int*>(&transform->x)[1];
        reinterpret_cast<unsigned int*>(&axisX)[2] = reinterpret_cast<const unsigned int*>(&transform->x)[2];
        reinterpret_cast<unsigned int*>(&axisX)[3] = reinterpret_cast<const unsigned int*>(&transform->x)[3];
        __m128 axisY;
        reinterpret_cast<unsigned int*>(&axisY)[0] = reinterpret_cast<const unsigned int*>(&transform->y)[0];
        reinterpret_cast<unsigned int*>(&axisY)[1] = reinterpret_cast<const unsigned int*>(&transform->y)[1];
        reinterpret_cast<unsigned int*>(&axisY)[2] = reinterpret_cast<const unsigned int*>(&transform->y)[2];
        reinterpret_cast<unsigned int*>(&axisY)[3] = reinterpret_cast<const unsigned int*>(&transform->y)[3];
        __m128 axisZ;
        reinterpret_cast<unsigned int*>(&axisZ)[0] = reinterpret_cast<const unsigned int*>(&transform->z)[0];
        reinterpret_cast<unsigned int*>(&axisZ)[1] = reinterpret_cast<const unsigned int*>(&transform->z)[1];
        reinterpret_cast<unsigned int*>(&axisZ)[2] = reinterpret_cast<const unsigned int*>(&transform->z)[2];
        reinterpret_cast<unsigned int*>(&axisZ)[3] = reinterpret_cast<const unsigned int*>(&transform->z)[3];
        __m128 translation;
        reinterpret_cast<unsigned int*>(&translation)[0] = reinterpret_cast<const unsigned int*>(&transform->translation)[0];
        reinterpret_cast<unsigned int*>(&translation)[1] = reinterpret_cast<const unsigned int*>(&transform->translation)[1];
        reinterpret_cast<unsigned int*>(&translation)[2] = reinterpret_cast<const unsigned int*>(&transform->translation)[2];
        reinterpret_cast<unsigned int*>(&translation)[3] = reinterpret_cast<const unsigned int*>(&transform->translation)[3];
        int i = 2;
        do
        {
            __m128 p = shapeB->vertices[i];
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 x = _mm_shuffle_ps(p, p, 0);
            x = _mm_mul_ps(x, axisX);
            y = _mm_mul_ps(y, axisY);
            y = _mm_add_ps(y, x);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            z = _mm_mul_ps(z, axisZ);
            z = _mm_add_ps(z, translation);
            pointsB[i] = _mm_add_ps(y, z);
        } while (--i >= 0);
    }
    hkCollideCapsuleUtilCapsVsTri(pointsA, shapeA->radius, pointsB, shapeB->radius, reinterpret_cast<const hkVector4*>(input->directionStorage), DAT_0104da48, 0, &result, 0);
    if (result.first.w < result.second.w)
        *output = *reinterpret_cast<__m128*>(&result.first);
    else
        *output = *reinterpret_cast<__m128*>(&result.second);
}
