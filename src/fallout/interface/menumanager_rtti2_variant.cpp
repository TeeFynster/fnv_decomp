// src/fallout/interface/menumanager_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BookMenu). The skeleton of src/fallout/interface/menumanager.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "menumanager_decls_rtti2_menumanager.h"
#include "../../../include/TESObjectBOOK.h"
#include "../../../include/Tile.h"

// 0x00720aa0  838 bytes  /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall (ret 4), one int arg: fetch the cached menu for that class, delete
// it, then build the class's menu through an if/else-if chain over the ids.

Tile* Tile_GetMenuByClass(int menuClass);
bool IsStartMenuFlag1Set();
int MapMenu_GetClassStatic();
int StartMenu_GetClassStatic();
Tile* Interface_CreateMapMenu();
Tile* Interface_CreateRepairMenu();
Tile* Interface_CreateItemModMenu();
Tile* CreateInventoryMenuIfModifierKey();
Tile* Interface_CreateStatsMenu();
Tile* HUDMainMenu_Create();
Tile* LevelUpMenu_Create();
void InterfaceManager_NewTimer(Tile* menu, float value);
bool FUN_0070cb7d0(bool flag, bool other);
Tile* CreateLoadingMenuTile(void* form, bool a, bool b);
Tile* ContainerMenu_Create(void* form, int flag);
Tile* BookMenu_Create(void* book, char* data);

struct Mgr20
{
    void* MenuManager_ReloadMenu(int menuClass);
};

// @fnv 0x00720aa0
// src: XBOX_PDB 0x00720aa0
void* Mgr20::MenuManager_ReloadMenu(int menuClass)
{
    Tile* pMenu = Tile_GetMenuByClass(menuClass);
    bool bFlag = IsStartMenuFlag1Set();
    if (pMenu)
    {
        delete pMenu;
    }
    pMenu = 0;

    if (MapMenu_GetClassStatic() == menuClass)
    {
        pMenu = Interface_CreateMapMenu();
        InterfaceManager_NewTimer(((Tile*)pMenu->Tile_GetMenu()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->Tile_GetMenu())->FUN_007037c0(8);
    }
    else if (menuClass == 0x40b)
    {
        pMenu = Interface_CreateRepairMenu();
        InterfaceManager_NewTimer(((Tile*)pMenu->Tile_GetMenu()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->Tile_GetMenu())->FUN_007037c0(8);
    }
    else if (menuClass == 0x425)
    {
        pMenu = Interface_CreateItemModMenu();
        InterfaceManager_NewTimer(((Tile*)pMenu->Tile_GetMenu()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->Tile_GetMenu())->FUN_007037c0(8);
    }
    else if (menuClass == 0x3ea)
    {
        pMenu = CreateInventoryMenuIfModifierKey();
        InterfaceManager_NewTimer(((Tile*)pMenu->Tile_GetMenu()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->Tile_GetMenu())->FUN_007037c0(8);
    }
    else if (menuClass == 0x3eb)
    {
        pMenu = Interface_CreateStatsMenu();
        InterfaceManager_NewTimer(((Tile*)pMenu->Tile_GetMenu()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->Tile_GetMenu())->FUN_007037c0(8);
    }
    else if (menuClass == 0x3ec)
    {
        pMenu = HUDMainMenu_Create();
    }
    else if (StartMenu_GetClassStatic() == menuClass && FUN_0070cb7d0(bFlag, false))
    {
        pMenu = Tile_GetMenuByClass(menuClass);
    }
    else if (menuClass == 0x3ef)
    {
        pMenu = CreateLoadingMenuTile(0, true, false);
    }
    else if (menuClass == 0x403)
    {
        pMenu = LevelUpMenu_Create();
    }
    else if (menuClass == 0x3f0)
    {
        ContainerMenu* pContainer = dynamic_cast<ContainerMenu*>(Tile_GetMenuByClass(0x3f0));
        if (pContainer)
        {
            pMenu = ContainerMenu_Create(((Tile*)pContainer)->TESChallenge_GetFormOne(), 1);
        }
    }
    else if (menuClass == 0x402)
    {
        BookMenu* pBookMenu = dynamic_cast<BookMenu*>(Tile_GetMenuByClass(0x3f0));
        if (pBookMenu)
        {
            char* data = ((Tile*)pBookMenu)->FUN_00671d10();
            TESObjectBOOK* pBookForm = dynamic_cast<TESObjectBOOK*>(((TESBoundObject*)data)->BGSSaveFormBuffer_GetForm());
            delete (Tile*)pBookMenu;
            pMenu = BookMenu_Create(pBookForm, data);
        }
    }

    return pMenu;
}
