#pragma once

#include "hkReferencedObject.h"
#include "hkArray.h"

class hkpVehicleSuspensionSuspensionWheelParameters;

class hkpVehicleSuspension : public hkReferencedObject
{
public:
    hkArray<hkpVehicleSuspensionSuspensionWheelParameters> m_kWheelParams;
};
