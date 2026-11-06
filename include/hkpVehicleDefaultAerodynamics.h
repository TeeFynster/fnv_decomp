#pragma once

#include "hkpVehicleAerodynamics.h"
#include "hkVector4.h"

class hkpVehicleInstanceE443;
struct AerodynamicsDragOutputE443;

typedef float hkReal;

class hkpVehicleDefaultAerodynamics : public hkpVehicleAerodynamics
{
public:
    hkpVehicleDefaultAerodynamics() throw();

    virtual void vf03(const float fMoveElapsedTime,
                      const hkpVehicleInstanceE443* pkVehicle,
                      AerodynamicsDragOutputE443& kDragInfoOut) throw();
    virtual float calcDragForce(float m_fGain) throw();
    virtual float calcLiftForce(float m_fGain) throw();

    hkReal m_fAirDensity;
    hkReal m_fFrontalArea;
    hkReal m_fDragCoefficient;
    hkReal m_fLiftCoefficient;
    char pad18[0x8];
    hkVector4 m_vExtraGravityWorldSpace;
};
