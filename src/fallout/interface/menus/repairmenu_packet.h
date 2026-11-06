#include "../../../../include/InterfaceManager.h"
// External helpers used by repairmenu.cpp.
#ifndef REPAIRMENU_PACKET_H
#define REPAIRMENU_PACKET_H

#include "../../../../include/RepairMenu.h"

class BGSPerkEntry;

InterfaceManager* FUN_004b7210();
int FUN_007b5720();
int Warning(const char*, ...);
float FUN_004a4240();
void FUN_004169a0(float, float&, float&);
extern bool DAT_011d9e91;
extern RepairMenu* DAT_011da75c;
extern int DAT_011da754;
#endif
