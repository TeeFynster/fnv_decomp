// src/fallout/interface/menumanager_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BookMenu). The skeleton of src/fallout/interface/menumanager.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "menumanager_decls_rtti2_menumanager.h"
#include "../../../include/TESObjectBOOK.h"
#include "../../../include/Tile.h"

// 0x00720aa0  838 bytes  /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall (ret 4), one int arg: fetch the cached menu for that class, delete
// it, then build the class's menu through an if/else-if chain over the ids.

Tile* FUN_00a09030(int menuClass);
bool IsStartMenuFlag1Set();
int FUN_00720df0();
int FUN_0070ede0();
Tile* FUN_00704140();
Tile* FUN_00704490();
Tile* FUN_007046c0();
Tile* CreateInventoryMenuIfModifierKey();
Tile* FUN_00704be0();
Tile* FUN_0076bfe0();
Tile* ShowLevelUpMenu();
void FUN_007164c0(Tile* menu, float value);
bool FUN_0070cb7d0(bool flag, bool other);
Tile* CreateLoadingMenuTile(void* form, bool a, bool b);
Tile* FUN_0075b310(void* form, int flag);
Tile* FUN_0073ad50(void* book, char* data);

struct Mgr20
{
    void* FUN_00720aa0(int menuClass);
};

// @fnv 0x00720aa0
void* Mgr20::FUN_00720aa0(int menuClass)
{
    Tile* pMenu = FUN_00a09030(menuClass);
    bool bFlag = IsStartMenuFlag1Set();
    if (pMenu)
    {
        delete pMenu;
    }
    pMenu = 0;

    if (FUN_00720df0() == menuClass)
    {
        pMenu = FUN_00704140();
        FUN_007164c0(((Tile*)pMenu->FUN_00a03c90()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->FUN_00a03c90())->FUN_007037c0(8);
    }
    else if (menuClass == 0x40b)
    {
        pMenu = FUN_00704490();
        FUN_007164c0(((Tile*)pMenu->FUN_00a03c90()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->FUN_00a03c90())->FUN_007037c0(8);
    }
    else if (menuClass == 0x425)
    {
        pMenu = FUN_007046c0();
        FUN_007164c0(((Tile*)pMenu->FUN_00a03c90()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->FUN_00a03c90())->FUN_007037c0(8);
    }
    else if (menuClass == 0x3ea)
    {
        pMenu = CreateInventoryMenuIfModifierKey();
        FUN_007164c0(((Tile*)pMenu->FUN_00a03c90()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->FUN_00a03c90())->FUN_007037c0(8);
    }
    else if (menuClass == 0x3eb)
    {
        pMenu = FUN_00704be0();
        FUN_007164c0(((Tile*)pMenu->FUN_00a03c90()), pMenu->FUN_00a011b0(0xfc1));
        ((Tile*)pMenu->FUN_00a03c90())->FUN_007037c0(8);
    }
    else if (menuClass == 0x3ec)
    {
        pMenu = FUN_0076bfe0();
    }
    else if (FUN_0070ede0() == menuClass && FUN_0070cb7d0(bFlag, false))
    {
        pMenu = FUN_00a09030(menuClass);
    }
    else if (menuClass == 0x3ef)
    {
        pMenu = CreateLoadingMenuTile(0, true, false);
    }
    else if (menuClass == 0x403)
    {
        pMenu = ShowLevelUpMenu();
    }
    else if (menuClass == 0x3f0)
    {
        ContainerMenu* pContainer = dynamic_cast<ContainerMenu*>(FUN_00a09030(0x3f0));
        if (pContainer)
        {
            pMenu = FUN_0075b310(((Tile*)pContainer)->FUN_004fd3a0(), 1);
        }
    }
    else if (menuClass == 0x402)
    {
        BookMenu* pBookMenu = dynamic_cast<BookMenu*>(FUN_00a09030(0x3f0));
        if (pBookMenu)
        {
            char* data = ((Tile*)pBookMenu)->FUN_00671d10();
            TESObjectBOOK* pBookForm = dynamic_cast<TESObjectBOOK*>(((TESBoundObject*)data)->FUN_007af430());
            delete (Tile*)pBookMenu;
            pMenu = FUN_0073ad50(pBookForm, data);
        }
    }

    return pMenu;
}
