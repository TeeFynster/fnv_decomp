#pragma once

#include "hkpVehicleTransmission.h"
#include "hkaAnimation.h"

struct Vehicle;

class hkpVehicleDefaultTransmission : public hkpVehicleTransmission
{
public:
    float calcTransmissionRPM(const Vehicle* vehicle, const void* input);
    virtual void vf03();
    virtual void vf04();
    virtual float vf05(const Vehicle* vehicle, const void* input);
    virtual void vf06();
    virtual void vf07();
    virtual hkReal getTransmissionRatio(const Vehicle* vehicle, const void* input) const;

    hkReal m_fDownshiftRPM;
    hkReal m_fUpshiftRPM;
    hkReal m_fPrimaryTransmissionRatio;
    hkReal m_fClutchDelayTime;
    hkReal m_fReverseGearRatio;
    hkArray<hkReal> m_kGearRatios;
    hkArray<hkReal> m_kWheelTorqueRatios;
};
