// src/fallout/interface/interface_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Menu). The skeleton of src/fallout/interface/interface.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "interface_rebase_packet.h"
#include "../../../include/BSSystemUtility.h"
#include "../../../include/StatsMenu.h"
#include "../../../include/Tile.h"

const char kMeshesFolder[] = "Meshes";
unsigned int NiVertexColorProperty_GetType();
bool DialogMenu_IsDialogActive();
unsigned int HudMainMenu_GetMenuID();
bool Renderer_GetWidescreen();

struct MenuLookup704
{
    ::Menu* Tile_GetMenu();
};

struct InterfaceGate704
{
  public:
    bool TESTextureList_GetTextureCount();
};
bool __cdecl Interface_IsMenuIDVisible(int, int);

// @fnv 0x00704e10
// src: XBOX_PDB 0x00704e10
void __cdecl Interface_UpdateActorValue(int id)
{
    if (InterfaceManager_GetSingleton() && ((InterfaceGate704*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        bool b = Interface_IsMenuIDVisible(0x3eb, 0xb);
        if (b)
        {
            ::Menu* menu = Tile::FindMenuById(0x3ebu);
            ::StatsMenu* result = menu ? dynamic_cast< ::StatsMenu*>(((MenuLookup704*)menu)->Tile_GetMenu()) : 0;
            if (result)
            {
                if (id == 0x4d)
                {
                    result->UpdateActorValueTiles();
                }
                else
                {
                    result->RefreshActorValueTile(static_cast<ActorValue::Index>(id));
                }
            }
        }
    }
}
