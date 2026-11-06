// src/fallout/interface/interface_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Menu). The skeleton of src/fallout/interface/interface.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "interface_rebase_packet.h"
#include "../../../include/BSSystemUtility.h"
#include "../../../include/StatsMenu.h"
#include "../../../include/Tile.h"

const char kMeshesFolder[] = "Meshes";
unsigned int FUN_00702440();
bool FUN_00705100();
unsigned int FUN_00706f20();
bool FUN_00707b50();

struct MenuLookup704
{
    ::Menu* FUN_00a03c90();
};

struct InterfaceGate704
{
  public:
    bool FUN_009373f0();
};
bool __cdecl FUN_00702680(int, int);

// @fnv 0x00704e10
void __cdecl FUN_00704e10(int id)
{
    if (FUN_004b7210() && ((InterfaceGate704*)FUN_004b7210())->FUN_009373f0())
    {
        bool b = FUN_00702680(0x3eb, 0xb);
        if (b)
        {
            ::Menu* menu = Tile::FindMenuById(0x3ebu);
            ::StatsMenu* result = menu ? dynamic_cast< ::StatsMenu*>(((MenuLookup704*)menu)->FUN_00a03c90()) : 0;
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
