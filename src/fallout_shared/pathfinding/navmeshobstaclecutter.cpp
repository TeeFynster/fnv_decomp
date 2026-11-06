
// src/fallout_shared/pathfinding/navmeshobstaclecutter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshobstaclecutter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/ObstacleUndoData.h"

extern "C" void __cdecl _delete(void*, unsigned int);

// Runs the destructor and, when flags has bit 0 set, frees this with _delete using size 0x70; returns this.
// @fnv 0x006bc300
void* ObstacleUndoData::Destroy(unsigned int flags)
{
    ObstacleUndoData::~ObstacleUndoData();
    if (flags & 1)
        _delete(this, 0x70);
    return this;
}
