
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpspheremotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkpSphereMotion.h"

extern "C" __m128 _mm_setzero_ps();
extern "C" void _mm_store_ps(float* p, __m128 v);
extern const double DAT_010c9300;
extern float DAT_0104da4c;
// hkpSphereMotion lacks this accessor declaration; this member-only adapter uses its shared layout.
struct SphereWorldInertiaAccess : public hkpSphereMotion
{
    void hkpSphereMotion_getInertiaWorld(float* out);
};
// @fnv 0x00d1e230
// src: HAVOK_SRC 0x00d1e230
void SphereWorldInertiaAccess::hkpSphereMotion_getInertiaWorld(float* out)
{
    float t = m_kInertiaAndMassInv.x;
    float s;
    if (DAT_010c9300 > t)
        s = DAT_0104da4c;
    else
        s = t;
    float inv = 1.0f / s;
    __m128 zero = _mm_setzero_ps();
    _mm_store_ps(out, zero);
    _mm_store_ps(out + 4, zero);
    _mm_store_ps(out + 8, zero);
    out[0] = inv;
    out[5] = inv;
    out[10] = inv;
}
