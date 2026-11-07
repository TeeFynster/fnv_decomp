// bsmenu/tilemenu.cpp: TileMenu, TileRect (6 functions)

#include "layout_support.h"
#include "../../include/Menu.h"
#include "../../include/NiExtraData.h"
#include "../../include/Tile.h"
// TileListBoxCalls_tilemenu: local type (was include/TileListBoxCalls.h, which had no evidence of one real class); its methods are 0x00a011b0 Tile::GetFloat
#include "../../include/Tile.h"

class TileListBoxCalls_tilemenu : public Tile
{
  public:
    float GetFloat(int trait);
};
#include "../../include/TileMenu.h"
#include "../../include/TileRect.h"

extern bool DAT_011f308f[];
Menu* GetMenuById(int);
void DebugLog(const char*, ...);
void __fastcall Tile_ForceTextureRelease(TileMenu* tile);

__forceinline void Menu::SetVisible(int id, bool visible)
{
    if (id >= 1001 && id <= 1084)
        DAT_011f308f[id] = visible;
}

__forceinline bool Tile::IsSpecial()
{
    return (uiFlags & 0x2000) != 0;
}

__forceinline float TileMenu::GetTraitFloat(int id)
{
    return ((TileListBoxCalls_tilemenu*)this)->GetFloat(id);
}

// @fnv 0x00709a40
int TileMenu::GetType()
{
    return 0x389;
}

// @fnv 0x00a1ef30
void TileMenu::Init(Tile* parent, const char* name, Tile* replacedChild)
{
    Tile::Init(parent, name, replacedChild);
    Set(0xFA1, 0.0f, true);
    Set(0xFA2, 0.0f, true);
    Set(0xFA8, 1.0f, true);
    Set(0xFC1, 0.25f, true);
    Set(0xFF4, 1.0f, true);
    Set(0xFA3, 0.0f, true);
    SetTileType(3);
    pMenu = 0;
}

// @fnv 0x00a1f140
NiNode* TileMenu::CalculateNode()
{
    NiNode* node = TileRect::CalculateNode();
    return node;
}

__forceinline TileRect::~TileRect()
{
    if (!IsSpecial())
        Release();
}
// @fnv 0x00a1eff0
TileMenu::~TileMenu()
{
    if (pMenu)
    {
        Menu::SetVisible(pMenu->GetClass(), false);
        Menu::SetMenuRootTile(pMenu->GetClass(), 0);
        pMenu->SetTileMenu(0, false);
        delete pMenu;
    }
    if (!IsSpecial())
        Release();
}

// @fnv 0x00a1f160
Tile* TileMenu::SetTraitValue(int valueID, float floatValue, const char* strValue)
{
    if (valueID == 0xFA4)
    {
        if (!pMenu)
        {
            Menu* menu = GetMenuById((int)floatValue);
            pMenu = menu;
        }
        if (!pMenu)
        {
            DebugLog("ERROR: Cant find menu class!");
        }
        else
        {
            pMenu->SetTileMenu(this, false);
            pMenu->m_iMenuId = pMenu->GetClass();
            if (GetTraitFloat(0xFA7) == 102.0 || GetTraitFloat(0xFA7) == 103.0)
            {
                pMenu->SetModal(pMenu->GetClass());
                Set(0xFAD, Menu::GetMenuScale(), true);
            }
            Menu::SetMenuRootTile((int)floatValue, this);
            return this;
        }
    }
    else if (pMenu && valueID >= 10000)
    {
        pMenu->OnUpdateUserTrait(valueID);
    }
    if (pMenu && valueID == 0xFA3)
    {
        Menu::SetVisible(pMenu->GetClass(), floatValue != 0.0);
    }
    return 0;
}

// Returns early if the menu's ID is 0x3ec or 0x3ef, otherwise calls FUN_00a0b020.
// @fnv 0x00a1f310
// src: XBOX_PDB 0x00a1f310
void __fastcall TileMenu_ForceTextureRelease(TileMenu* tile)
{
    if (tile->pMenu && (tile->pMenu->GetClass() == 0x3ec || tile->pMenu->GetClass() == 0x3ef))
        return;
    else
        Tile_ForceTextureRelease(tile);
}
