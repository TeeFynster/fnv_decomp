
// src/staging/blk_00ca0000_od_o2_ob1_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00ca0000_od_o2_ob1_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/staging/blk_00ca0000_od_o2_ob1_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00ca0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00ca0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/bhkSphereShape.h"

#include <xmmintrin.h>

struct ArgB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float f10;
    float f14;
    float f18;
    float f1c;
};



// @fnv 0x00ca5460
// src: XBOX_PDB 0x00ca5460
void bhkSphereShape::bhkPackedNiTriStripsShape_CopyMembers(void* a1, ArgB* a2)
{
    unsigned char c;
    char* r = reinterpret_cast<char*>(this->slotB4((char*)&c));
    float v = a2->f10;
    __m128 t = _mm_load_ss(&v);
    *(__m128*)(r + 0x10) = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), *(__m128*)(r + 0x10));
    this->bhkSphereShape::bhkShape_CopyMembers(a1, a2);
}
