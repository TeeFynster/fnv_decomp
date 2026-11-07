
// src/fallout/interface/inventorylist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/inventorylist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/InventoryStackRecord.h"
int __cdecl _mbscmp(const unsigned char*, const unsigned char*);
// @fnv 0x00719c80
// src: COMMUNITY 0x00719c80
int __cdecl InventoryList_SortByName(InventoryStackRecord* pFirst, InventoryStackRecord* pSecond)
{
    return _mbscmp(pFirst->GetFullName(), pSecond->GetFullName());
}
