#include "../../../../include/InterfaceManager.h"
// External helpers used by repairmenu.cpp.
#ifndef REPAIRMENU_PACKET_H
#define REPAIRMENU_PACKET_H

#include "../../../../include/RepairMenu.h"

class BGSPerkEntry;

InterfaceManager* InterfaceManager_GetSingleton();
int RepairMenu_GetClassStatic();
int Warning(const char*, ...);
float RandomFloatTwoPi();
void NiSinCos_004169a0(float, float&, float&);
extern bool DAT_011d9e91;
extern RepairMenu* DAT_011da75c;
extern int DAT_011da754;
#endif
