
// src/fallout/interface/interface_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x007054f0: the skeleton of src/fallout/interface/interface_rtti_variant.cpp
// with declarations corrected to what the original code does (interface_rebase_packet.h: InterfaceManager += bool FUN_009373f0();). Move the function to its real unit once
// that unit declares it this way.

// src/fallout/interface/interface_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Menu). The skeleton of src/fallout/interface/interface.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "../../../include/BSSystemUtility.h"
#include "../../../include/EffectSetting.h"
#include "interface_rebase_packet_decl_interface_rtti_variant.h"
#include "../../../include/Tile.h"
#include "../../../include/VATSMenu.h"
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
void __cdecl Interface_CreateVATSMenu();

Tile* __cdecl Tile_GetMenuByClass(unsigned int);
bool __cdecl IsSomethingZero();
void __cdecl CreateSleepWaitMenu(bool);
// @fnv 0x007054f0
// src: COMMUNITY 0x007054f0
void __cdecl Interface_CreateSleepMenu(bool sleep)
{
    if (InterfaceManager_GetSingleton() && InterfaceManager_GetSingleton()->TESTextureList_GetTextureCount() && IsSomethingZero())
    {
        Tile* menu = Tile_GetMenuByClass(1012);
        SleepWaitMenu* tile = menu ? dynamic_cast<SleepWaitMenu*>(static_cast<const Tile*>(menu)->GetMenu()) : 0;
        if (tile)
            delete tile;
        CreateSleepWaitMenu(sleep);
    }
}
