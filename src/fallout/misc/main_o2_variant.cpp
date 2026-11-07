
// src/fallout/misc/main_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/misc/main.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "main.h"

struct BSBatchRenderer__PassList
{
    void ResetPassList();
};
struct FUN_00b65660_StandIn
{
    void BSShaderAccumulator_ClearRenderedGeometryCache();
};
// @fnv 0x00b65660
// src: COMMUNITY 0x00b65660
void FUN_00b65660_StandIn::BSShaderAccumulator_ClearRenderedGeometryCache()
{
    BSBatchRenderer__PassList* p = (BSBatchRenderer__PassList*)((char*)this + 0xa0);
    for (int i = 0; i < 4; ++i, p = (BSBatchRenderer__PassList*)((char*)p + 0x14))
    {
        ((BSBatchRenderer__PassList*)((char*)p - 4))->ResetPassList();
        *(int*)((char*)p + 8) = *(int*)p;
        *(int*)p = 0;
        *(int*)((char*)p + 4) = 0;
        *(int*)((char*)p + 0xc) = 0;
        ((BSBatchRenderer__PassList*)((char*)p + 0x4c))->ResetPassList();
        *(int*)((char*)p + 0x58) = *(int*)((char*)p + 0x50);
        *(int*)((char*)p + 0x50) = 0;
        *(int*)((char*)p + 0x54) = 0;
        *(int*)((char*)p + 0x5c) = 0;
    }
}
