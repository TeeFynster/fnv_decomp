
// src/fallout_shared/bgsdecalmanager_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF /Oy- (unit src/fallout_shared/bgsdecalmanager_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/bgsdecalmanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsdecalmanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "bgsdecalmanager_decls.h"
#include "bgsdecalmanager_types_BGSDecalManager.h"
#include "bgsdecalmanager_types_BSTempEffectSimpleDecal.h"

#include <xmmintrin.h>
struct AlignedVector
{
    __m128 value;
    void __thiscall SetValue(const AlignedVector& source);
};
// @fnv 0x004a3f10
// src: GUESS 0x004a3f10 (confidence: low)
void AlignedVector::SetValue(const AlignedVector& source)
{
    value = source.value;
}
