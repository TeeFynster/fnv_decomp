#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPSysGravityFieldModifier.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysgravityfieldmodifier_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysgravityfieldmodifier.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/niparticle/nipsysgravityfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysgravityfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C"
{
    extern const void* g_01202708;
}

// @fnv 0x00c2a9b0
// src: COMMUNITY 0x00c2a9b0
const void* __cdecl NiPSysGravityFieldModifier_GetRTTI()
{
    return &g_01202708;
}

extern double DAT_01017cf8;
struct FUN_004a0c10_s
{
    float x, y, z;
    void Unitize_004a0c10();
};
// @fnv 0x004a0c10
// src: XBOX_PDB 0x004a0c10
void FUN_004a0c10_s::Unitize_004a0c10()
{
    float len = ((NiPoint3*)this)->Length();
    if (len > DAT_01017cf8)
    {
        float inv = 1.0f / len;
        x *= inv;
        y *= inv;
        z *= inv;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
}
