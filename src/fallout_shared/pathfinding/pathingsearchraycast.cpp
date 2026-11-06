
// src/fallout_shared/pathfinding/pathingsearchraycast.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingsearchraycast.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/PathingSearchRayCast.h"

// Calls FUN_006e62b0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x006e6280
void* __thiscall PathingSearchRayCast::Destroy(unsigned int flags)
{
    FUN_006e62b0();
    if (flags & 1)
        operator delete(this);
    return this;
}
