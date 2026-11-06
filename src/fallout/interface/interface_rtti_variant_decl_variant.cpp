
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
unsigned int FUN_00702440();
bool FUN_00705100();
unsigned int FUN_00706f20();
bool FUN_00707b50();
class InterfaceManagerKey
{
  public:
    bool FUN_009373f0();
};
Tile* __cdecl FUN_00a09030(unsigned int eLine);
void __cdecl FUN_007e9200();
void __cdecl FUN_00705640();

Tile* __cdecl FUN_00a09030(unsigned int);
bool __cdecl IsSomethingZero();
void __cdecl CreateSleepWaitMenu(bool);
// @fnv 0x007054f0
void __cdecl FUN_007054f0(bool sleep)
{
    if (FUN_004b7210() && FUN_004b7210()->FUN_009373f0() && IsSomethingZero())
    {
        Tile* menu = FUN_00a09030(1012);
        SleepWaitMenu* tile = menu ? dynamic_cast<SleepWaitMenu*>(static_cast<const Tile*>(menu)->GetMenu()) : 0;
        if (tile)
            delete tile;
        CreateSleepWaitMenu(sleep);
    }
}
