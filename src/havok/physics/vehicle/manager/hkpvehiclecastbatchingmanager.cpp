
// src/havok/physics/vehicle/manager/hkpvehiclecastbatchingmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/manager/hkpvehiclecastbatchingmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleCastBatchingManager.h"

struct FUN_00e37940_Item
{
    void hkpVehicleInstance_updateBeforeCollisionDetection();
};
struct FUN_00e42910_List
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00e37940_Item** items;
    int count;
    void hkpVehicleCastBatchingManager_updateBeforeCollisionDetection();
};
// Iterates over the list's items up to a snapshot of count and calls FUN_00e37940 on each item.
// @fnv 0x00e42910
// src: HAVOK_LIB 0x00e42910
void FUN_00e42910_List::hkpVehicleCastBatchingManager_updateBeforeCollisionDetection()
{
    int countSnapshot = count;
    for (int index = 0; index < countSnapshot; ++index)
        items[index]->hkpVehicleInstance_updateBeforeCollisionDetection();
}
