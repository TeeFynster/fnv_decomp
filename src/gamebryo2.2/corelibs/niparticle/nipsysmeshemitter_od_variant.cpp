#include "../../../../include/NiPSysVolumeEmitter.h"
// src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int g_01202500;
int* __cdecl NiPSysMeshEmitter_GetRTTI();
struct NiAVObject;
extern void* g_01202508;
void* __cdecl NiPSysCylinderEmitter_GetRTTI();

extern "C" int __cdecl Runtime_GetRandomNumber_Thunk();
extern double DAT_01029790;

// @fnv 0x00639780
// src: GUESS 0x00639780 (confidence: low)
float __cdecl Object_ProcessAndReturnValue_00639780()
{
    int v;
    float result;
    v = Runtime_GetRandomNumber_Thunk();
    result = (float)v / DAT_01029790;
    return result;
}
