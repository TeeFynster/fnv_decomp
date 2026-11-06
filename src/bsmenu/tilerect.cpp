// bsmenu/tilerect.cpp: TileRect (2 functions)

#include "layout_support.h"
#include "../../include/NiExtraData.h"
#include "../../include/Tile.h"
#include "../../include/TileRect.h"

// Initializes the TileRect by calling Tile::Init, then sets a value of 0x0fa3 to 1.0f and calls a method with 3.
// @fnv 0x00a1f370
void TileRect::Init(Tile* parent, const char* name, Tile* replacedChild)
{
    Tile::Init(parent, name, replacedChild);
    Set(0x0fa3, 1.0f, true);
    SetTileType(3);
}

// @fnv 0x00709960
int TileRect::GetType()
{
    return eRect;
}
