
// src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_011f5b40;
void* __cdecl BSSegmentedTriShape_GetRTTI();
void __cdecl FinalizeEntries();
void __cdecl FUN_00a745c0();
void __cdecl BSSegmentedTriShape_RenderImmediate();
struct FUN_00a86ff0_shell
{
    void SetEntryActive(unsigned int index);
};

struct PointerSource
{
    int FUN_0059bb30();
    int FUN_0045cd60();
};
extern PointerSource* g_011dea10;

struct ScreenSize
{
    int* Setting_Int();
};
extern ScreenSize g_011c63cc;

struct HitRect
{
    int unk00;
    int extent;
    short left;
    short top;
    bool BGSTerrainNode_CheckIntersectsLoadedRange();
};

// @fnv 0x006fede0
// src: COMMUNITY 0x006fede0
bool HitRect::BGSTerrainNode_CheckIntersectsLoadedRange()
{
    int y;
    int x;
    x = g_011dea10->FUN_0059bb30() - (int)((unsigned int)*g_011c63cc.Setting_Int() >> 1);
    y = g_011dea10->FUN_0045cd60() - (int)((unsigned int)*g_011c63cc.Setting_Int() >> 1);
    if (x + *g_011c63cc.Setting_Int() >= left && x <= left + extent && y + *g_011c63cc.Setting_Int() >= top &&
        y <= top + extent)
    {
        return true;
    }
    return false;
}
