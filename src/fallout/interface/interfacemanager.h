#ifndef FNV_INTERFACEMANAGER_H
#define FNV_INTERFACEMANAGER_H

#include "interfacemanager_decls.h"
// @fnv 0x00719320
unsigned int SystemColorManager::SoftSystemColor::GetColor()
{
    return setting->Int()->u;
}
// @fnv 0x00707af0
FORenderedMenu* InterfaceManager::GetActiveRenderedMenu()
{
    return IsPipboyMenuActive() ? reinterpret_cast<FORenderedMenu*>(pPipboyManager) : pRenderedMenu;
}
#endif
