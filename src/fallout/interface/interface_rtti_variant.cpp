
// src/fallout/interface/interface_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Menu). The skeleton of src/fallout/interface/interface.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "interface_rebase_packet.h"
#include "../../../include/BSSystemUtility.h"
#include "../../../include/VATSMenu.h"
#include "../../../include/Tile.h"
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

// @fnv 0x00705640
void __cdecl FUN_00705640()
{
    if (FUN_004b7210() && ((InterfaceManagerKey*)FUN_004b7210())->FUN_009373f0())
    {
        const Tile* pkTileMenu = FUN_00a09030(1056u);
        VATSMenu* pkMenu = pkTileMenu ? dynamic_cast<VATSMenu*>(pkTileMenu->GetMenu()) : 0;
        if (pkMenu)
            delete pkMenu;
        FUN_007e9200();
    }
}

Tile* FUN_00a09030(int);
class Iface2
{
  public:
    bool FUN_009373f0();
};
void FUN_007c01b0();
// @fnv 0x007055c0
void FUN_007055c0()
{
    if (FUN_004b7210() && ((Iface2*)FUN_004b7210())->FUN_009373f0())
    {
        const Tile* a = FUN_00a09030(0x3f4);
        SleepWaitMenu* b = a ? dynamic_cast<SleepWaitMenu*>(a->GetMenu()) : 0;
        if (b)
            FUN_007c01b0();
    }
}
