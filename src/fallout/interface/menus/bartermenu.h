#ifndef FNV_BARTERMENU_H
#define FNV_BARTERMENU_H


// @fnv 0x0072d040
void MapMenu::AssignTileByID(int index, Tile* tile)
{
    if (index >= 0 && index < 22)
        m_pTiles[index] = tile;
}
#endif
