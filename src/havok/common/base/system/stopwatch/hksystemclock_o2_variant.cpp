// havok/common/base/system/stopwatch/hksystemclock_o2_variant.cpp: free functions (1 function)
#include "fnv_asm_helpers.h"
// src/havok/common/base/system/stopwatch/hksystemclock_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/havok/common/base/system/stopwatch/hksystemclock.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/havok/common/base/system/stopwatch/hksystemclock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/stopwatch/hksystemclock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dd8e00
// src: HAVOK_LIB 0x00dd8e00
unsigned __int64 __cdecl hkWindowsSystemClock_getTickCounter() {
    unsigned __int64 ticks;
    fnv_ReadTicks64(ticks);
    return ticks;
}
