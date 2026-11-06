// fallout/interface/menus/vatsmenu_decls.h: declares ListBox_00726660; TileListBoxCalls_vatsmenu_decls and VATSMenu come from include/

// TileListBoxCalls_vatsmenu_decls: local type (was include/TileListBoxCalls.h, which had no evidence of one real class); its methods are 0x00a011b0 Tile::GetFloat
#include "../../../../include/Tile.h"

class TileListBoxCalls_vatsmenu_decls : public Tile
{
  public:
    float GetFloat(int trait);
};
int GetTileValueID(const char*, int);
#include "../../../../include/VATSMenu.h"
// 0x00726660 is a ListBox<T> method, not VATSMenu: it reads the item list at +4 (0x00726c40 counts it) and the
// list tile at +0xC (ListBox_int_ layout: vtable, BSSimpleList, m_pListTile). Real template argument and name unknown.
class ListBox_00726660
{
  public:
    char padding[12];
    TileListBoxCalls_vatsmenu_decls* tile;
    int GetSelectedTargetIndex();
    unsigned int Create();
};
