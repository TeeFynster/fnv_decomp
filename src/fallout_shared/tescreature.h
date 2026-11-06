// fallout_shared/tescreature.h: defines MiddleHighProcess::GetCurrentAmmo (class in include/MiddleHighProcess.h)
#ifndef FNV_TESCREATURE_H
#define FNV_TESCREATURE_H

#include "../../include/MiddleHighProcess.h"
// @fnv 0x005f7590
InventoryStackRecord* MiddleHighProcess::GetCurrentAmmo() const
{
    return pAmmo;
}
#endif
