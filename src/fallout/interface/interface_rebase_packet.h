#include "../../../include/InterfaceManager.h"
// fallout/interface/interface_rebase_packet.h: declares InterfaceManager
#ifndef FNV_INTERFACE_REBASE_CURRENT_PACKET_H
#define FNV_INTERFACE_REBASE_CURRENT_PACKET_H
class Tile;
class NiNode;
class TESSound;

InterfaceManager* InterfaceManager_GetSingleton();
float InterfaceManager_GetScreenHeight();
float InterfaceManager_GetRealScreenHeight();
float InterfaceManager_GetRealScreenWidth();
bool Renderer_GetWidescreen();
unsigned int NiVertexColorProperty_GetType();
bool DialogMenu_IsDialogActive();
unsigned int HudMainMenu_GetMenuID();

extern bool DAT_011d9514;
extern bool DAT_011c70eb;

#endif
