#pragma once

#include "hkReferencedObject.h"

class hkpVehicleInstance;

class hkpVehicleCastBatchingManager : public hkReferencedObject
{
public:
    hkpVehicleInstance** m_registeredVehicles;
    int m_registeredVehiclesSize;
    int m_registeredVehiclesCapacityAndFlags;
    unsigned short m_uiTotalWheelCount;
    char pad16[0x2];
};
