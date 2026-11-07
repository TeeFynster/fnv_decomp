
// src/fallout/interface/interface_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Menu). The skeleton of src/fallout/interface/interface.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "interface_rebase_packet.h"
#include "../../../include/BSSystemUtility.h"
#include "../../../include/VATSMenu.h"
#include "../../../include/Tile.h"
#include "../../../include/SleepWaitMenu.h"

const char kMeshesFolder[] = "Meshes";
unsigned int NiVertexColorProperty_GetType();
bool DialogMenu_IsDialogActive();
unsigned int HudMainMenu_GetMenuID();
bool Renderer_GetWidescreen();

class InterfaceManagerKey
{
  public:
    bool TESTextureList_GetTextureCount();
};
Tile* __cdecl Tile_GetMenuByClass(unsigned int eLine);
void __cdecl VATSMenu_Create();

// @fnv 0x00705640
// src: COMMUNITY 0x00705640
void __cdecl Interface_CreateVATSMenu()
{
    if (InterfaceManager_GetSingleton() && ((InterfaceManagerKey*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        const Tile* pkTileMenu = Tile_GetMenuByClass(1056u);
        VATSMenu* pkMenu = pkTileMenu ? dynamic_cast<VATSMenu*>(pkTileMenu->GetMenu()) : 0;
        if (pkMenu)
            delete pkMenu;
        VATSMenu_Create();
    }
}

Tile* Tile_GetMenuByClass(int);
class Iface2
{
  public:
    bool TESTextureList_GetTextureCount();
};
void SleepWaitMenu_Close();
// @fnv 0x007055c0
// src: GUESS 0x007055c0 (confidence: low)
void Object_UpdateFields_007055c0()
{
    if (InterfaceManager_GetSingleton() && ((Iface2*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        const Tile* a = Tile_GetMenuByClass(0x3f4);
        SleepWaitMenu* b = a ? dynamic_cast<SleepWaitMenu*>(a->GetMenu()) : 0;
        if (b)
            SleepWaitMenu_Close();
    }
}
