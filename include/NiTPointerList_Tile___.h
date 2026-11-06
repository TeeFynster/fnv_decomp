#pragma once

#include "NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___.h"

// NiTPointerList<Tile *> (Tile's child list at Tile+0x04). Gamebryo's NiTPointerList declares its own
// constructor and destructor; src: GAMEBRYO_SRC (NiTPointerList.h). Tile::Tile 0x00709860 calls the /Od
// constructor 0x0048f200 (which calls the base constructor 0x00718d90) and its unwind state -1 calls the
// destructor 0x004a1a30.
class NiTPointerList_Tile___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___
{
public:
    NiTPointerList_Tile___();
    ~NiTPointerList_Tile___();
};
