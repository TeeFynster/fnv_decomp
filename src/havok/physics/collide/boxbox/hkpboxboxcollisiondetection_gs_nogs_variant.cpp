#define FNV_VEC4_SIMD
#include "../../../../../include/Vec4.h"


// src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// RemoveValueAt - drops slot <index> of the eight-slot table held by
// FUN_00db0920: the last slot in use is moved into the hole and the used-slot
// counter goes down by one.
struct FUN_00db0920
{
    int values[8];        // +0x00: eight four-byte slots, low half holds the key
    unsigned char unk20;  // +0x20
    unsigned char count;  // +0x21: number of slots in use
    unsigned char flag;   // +0x22
    void RemoveValueAt(int index);
};

#include <xmmintrin.h>
struct KeyEntry
{
    unsigned char k0;
    unsigned char k1;
    unsigned short unk02;
};

struct Obj
{
    void ProcessEntries_00db1990(void* a1, KeyEntry* key, float scale);
    void UpdateState_00db1d90(void* a1, int idxA, int idxB, int axisA, int axisB, const Vec4& vecA, const Vec4& vecB,
                      float scale);
};

// @fnv 0x00db1d90
// src: GUESS 0x00db1d90 (confidence: low)
void Obj::UpdateState_00db1d90(void* a1, int idxA, int idxB, int axisA, int axisB, const Vec4& vecA, const Vec4& vecB,
                       float scale)
{
    const float one = 1.0f;
    KeyEntry key;
    key.unk02 = 0;
    Vec4 tmpA = vecA;
    Vec4 tmpB = vecB;
    (&tmpA.x)[idxA] = one;
    (&tmpB.x)[idxB] = one;
    __m128 zero = _mm_setzero_ps();
    int maskA = _mm_movemask_ps(_mm_cmplt_ps(*(__m128*)&tmpA, zero));
    int maskB = _mm_movemask_ps(_mm_cmplt_ps(*(__m128*)&tmpB, zero));
    key.k0 = (unsigned char)(((maskA | 0xf8) << 4) | idxA);
    key.k1 = (unsigned char)((((~maskB) & 7) << 4) + idxB);
    ProcessEntries_00db1990(a1, &key, scale);

    int stepA = (axisA == 0) ? 0 : ((axisA != 1) + 1);
    int bitA = 1 << (stepA + 4);
    int stepB = (axisB == 0) ? 0 : ((axisB != 1) + 1);

    key.k0 ^= bitA;
    ProcessEntries_00db1990(a1, &key, scale);

    key.k1 ^= (unsigned char)(1 << (stepB + 4));
    ProcessEntries_00db1990(a1, &key, scale);

    key.k0 ^= bitA;
    ProcessEntries_00db1990(a1, &key, scale);
}
