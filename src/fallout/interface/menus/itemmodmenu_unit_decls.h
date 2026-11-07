#include "../../../../include/InterfaceManager.h"
// fallout/interface/menus/itemmodmenu_unit_decls.h: declares Menu, ListBox_ItemChange___, Tile, InterfaceManager, InventoryMenu and more
#ifndef ITEMMODMENU_UNIT_DECLS_H
#define ITEMMODMENU_UNIT_DECLS_H


#include "../../../../include/InventoryMenu.h"
#include "../../../../include/ListBox_ItemChange___.h"
#include "../../../../include/Menu.h"
#include "../../../../include/RepairMenu.h"
#include "../../../../include/Tile.h"
#include "../../../../include/MapMenu.h"
// TileListBoxCalls_itemmodmenu_unit_decls: local type (was include/TileListBoxCalls.h, which had no evidence of one real class); its methods are 0x00a011b0 Tile::GetFloat
#include "../../../../include/Tile.h"

class TileListBoxCalls_itemmodmenu_unit_decls : public Tile
{
  public:
    float GetFloat(int trait);
};
#include "../../../../include/TileWorkList.h"

#pragma pack(push, 4)




class BGSPerkEntry;

#pragma pack(pop)

extern "C"
{
    extern void* DAT_01073b7c;
    extern void* DAT_01075c5c;

    extern const char DAT_0106ed18[];
    extern const char DAT_0106ed20[];
    extern const char DAT_01070244[];
    extern const char DAT_01073b64[];
    extern const char DAT_01075c44[];
    extern const char DAT_01073bc4[];
    extern const char DAT_01073be0[];
    extern const char DAT_01073c34[];

    extern double DAT_010704e8;
    extern double DAT_010704f0;

    extern int DAT_011d9f3c;
    extern unsigned char DAT_011d9f40;
    extern int DAT_011d9f44;
    extern int DAT_011d9f48;
    extern int DAT_011d9f4c;

    extern int DAT_011da748;
    extern int DAT_011da74c;
    extern int DAT_011da750;
    extern int DAT_011da754;
    extern Menu* DAT_011d9f54;
}

InterfaceManager* __cdecl InterfaceManager_GetSingleton();
int __cdecl ItemModMenu_GetClassStatic();
int __cdecl Warning(const char* message, ...);

#endif
