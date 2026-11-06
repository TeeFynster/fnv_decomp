#pragma once
#include "hkReferencedObject.h"

class hkpVehicleInstance;
struct hkpFilteredDriverInputOutputE38D;
struct hkpVehicleSteeringAnglesOutputE38D;

typedef float hkReal;

class __declspec(align(4)) hkpVehicleSteering : public hkReferencedObject
{
public:
    void V0() throw();
    void V1() throw();
    void V2() throw();
    void CalcSteering(const hkReal fMoveElapsedTime, const hkpVehicleInstance* pkVehicle,
                      const hkpFilteredDriverInputOutputE38D& kFilteredInfo,
                      hkpVehicleSteeringAnglesOutputE38D& kSteeringOutput) throw();
};
