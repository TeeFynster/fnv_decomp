#ifndef FNV_BSMENU_TILE_H
#define FNV_BSMENU_TILE_H

#pragma optimize("", off)
#include "tile_h_decls.h"
#include "Tile__FloatAction.h"
#include "tile_types_Tile__RefValueAction.h"
#pragma function(memcmp)

// @fnv 0x00a0c000
float Tile__FloatAction::GetStoredFloatValue()
{
    return fValue;
}

// @fnv 0x00a0d180
bool Tile__MenuStringMap::IsKeysEqual(const char* left, const char* right)
{
    return _stricmp(left, right) == 0;
}

// @fnv 0x00a0bb00
bool Tile::IsSpecialTileName(const char* name)
{
    int result;
    if (name && *name && (name[0] == 0x5f || memcmp(name, DAT_01093f80, 2) == 0))
        result = true;
    else
        result = false;
    return *reinterpret_cast<bool*>(&result);
}

#pragma optimize("", on)

#endif
