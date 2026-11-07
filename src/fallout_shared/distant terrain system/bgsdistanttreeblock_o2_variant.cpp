
// src/fallout_shared/distant terrain system/bgsdistanttreeblock_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistanttreeblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../include/BGSDistantTreeBlockLoadTask.h"
#include "../../../include/NP.h"

extern NP DAT_012007c4;
void BSDistantTreeShader_SetTextureAtlas(void* p);
void* __cdecl _Deallocate(void*);

extern int _fnv_particle_shader_renderer_level;
extern unsigned int DAT_012007b8;

// @fnv 0x00bb6030
// src: XBOX_PDB 0x00bb6030
unsigned int __cdecl BSDistantTreeShader_GetMaxInstances()
{
    if (!DAT_012007b8)
        DAT_012007b8 = 40 + ((_fnv_particle_shader_renderer_level < 2) ? 0 : 74);
    return DAT_012007b8;
}
