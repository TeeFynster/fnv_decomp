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
    bool TESTextureList_GetTextureCount();
};

Tile* Tile_GetMenuByClass(int);
void ShutdownVats();

// @fnv 0x00705780
// src: COMMUNITY 0x00705780
void __cdecl VATSCameraData_Accept()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<FUN_009373f0_shell*>(InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        Tile* pTile = (Tile*)Tile_GetMenuByClass(eVATSMenu);
        VATSMenu* pVATSMenuInstance = pTile ? dynamic_cast<VATSMenu*>(static_cast<const Tile*>(pTile)->GetMenu()) : 0;
        if (pVATSMenuInstance)
            ShutdownVats();
    }
}
