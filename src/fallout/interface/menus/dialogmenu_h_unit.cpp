#include "../../../../include/DialogMenu.h"

// @fnv 0x007618f0
int DialogMenu::GetClass()
{
    return 0x3F1;
}

// @fnv 0x00761900
void DialogMenu::AssignTileByID(int id, Tile* tile)
{
    if (id >= 0 && id < 4)
        m_pTiles[id] = tile;
}
