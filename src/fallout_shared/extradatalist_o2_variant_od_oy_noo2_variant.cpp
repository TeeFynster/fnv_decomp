
// src/fallout_shared/extradatalist_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/extradatalist_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/extradatalist_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/extradatalist.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "extradatalist_packet.h"
#include "ExtraDataList.h"
#include "ExtraContainerChanges.h"
#include "InventoryChanges.h"
#include "game_constants.h"

#include <xmmintrin.h>
struct V
{
    __m128 v;
    void hkVector4_add4(const V& o);
};
// @fnv 0x00553f70
// src: XBOX_PDB 0x00553f70
void V::hkVector4_add4(const V& o)
{
    v = _mm_add_ps(v, o.v);
}
