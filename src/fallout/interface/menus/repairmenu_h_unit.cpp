#include "../../../../include/RepairMenu.h"

static const int kGetClassValue = 1035;

// @fnv 0x007b54b0
int RepairMenu::GetClass()
{
    return kGetClassValue;
}

// @fnv 0x007b54c0
void RepairMenu::AssignTileByID(int tileID, Tile* tile)
{
    if (tileID >= 0 && tileID < 13)
        m_pTiles[tileID] = tile;
}
