
// src/havok/common/visualize/shape/hkdisplaycapsule_gs_fpfast_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy /fp:fast (unit src/havok/common/visualize/shape/hkdisplaycapsule.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/visualize/shape/hkdisplaycapsule.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycapsule.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkDisplayCapsule.h"

struct StaticHelper
{
    static void HandleObjectEvent(void* a, void* b, float c, void* d, void* e, void* f, void* g);
};
void __stdcall nullsub_74(int, int);

#include <xmmintrin.h>
extern float DAT_0104ffb8;

struct Plane
{
    __m128 m_vHitNormal;
    __m128 m_kPoint;
};

// @fnv 0x00d23480
// src: GUESS 0x00d23480 (confidence: low)
static __declspec(noinline) hkBool* hkBool_ProcessAndReturnValue_00d23480(hkBool* out, const __m128* p, const Plane* pl)
{
    __m128 m = _mm_mul_ps(_mm_sub_ps(*p, pl->m_kPoint), pl->m_vHitNormal);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
    float d;
    _mm_store_ss(&d, s);
    if (d >= DAT_0104ffb8)
        out->m_cBooleanValue = 0;
    else
        out->m_cBooleanValue = 1;
    return out;
}

hkBool* caller_d23480(hkBool* o, const __m128* v, const Plane* q)
{
    return hkBool_ProcessAndReturnValue_00d23480(o, v, q);
}
