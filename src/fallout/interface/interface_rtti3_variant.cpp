// RTTI variant: close the active VATS menu.

#include "../../../include/BSFaceGenNiNode.h"
#include "../../../include/ContainerMenu.h"
#include "../../../include/FORenderedTerminal.h"
#include "../../../include/InventoryMenu.h"
#include "../../../include/Setting.h"
#include "../../../include/TESGlobal.h"
#include "../../../include/TESNPC.h"
#include "../../../include/TESObjectARMO.h"
#include "../../../include/TileMenu.h"
#include "../../../include/TileRect.h"
#include "../../../include/VATSMenu.h"
#include "../../../include/MapMenu.h"

#include "interface_rebase_packet.h"

enum { eVATSMenu = 1056 };

struct FUN_009373f0_shell : public InterfaceManager
{
    bool FUN_009373f0();
};

Tile* FUN_00a09030(int);
void ShutdownVats();

// @fnv 0x00705780
void __cdecl FUN_00705780()
{
    if (FUN_004b7210() && reinterpret_cast<FUN_009373f0_shell*>(FUN_004b7210())->FUN_009373f0())
    {
        Tile* pTile = (Tile*)FUN_00a09030(eVATSMenu);
        VATSMenu* pVATSMenuInstance = pTile ? dynamic_cast<VATSMenu*>(static_cast<const Tile*>(pTile)->GetMenu()) : 0;
        if (pVATSMenuInstance)
            ShutdownVats();
    }
}
