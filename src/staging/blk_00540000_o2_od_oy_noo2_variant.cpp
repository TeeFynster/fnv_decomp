
// src/staging/blk_00540000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00540000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00540000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkVector4.h"

class NiPoint3;

hkVector4& NI2HK(hkVector4& out, const NiPoint3& pt);

class Obj554720
{
  public:
    void bhkWorldM_CheckForMove(const hkVector4& v);
    void bhkWorldM_NiCheckForMove(const NiPoint3& pt);
};

// Preserve the original stack cookie with the shared vector's constructor.
#pragma strict_gs_check(push, on)
// @fnv 0x00554720
// src: COMMUNITY 0x00554720
void Obj554720::bhkWorldM_NiCheckForMove(const NiPoint3& pt)
{
    hkVector4 v;
    bhkWorldM_CheckForMove(NI2HK(v, pt));
}
#pragma strict_gs_check(pop)
