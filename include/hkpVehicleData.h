#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkaAnimation.h"
#include "hkVector4.h"
#include "hkRotation.h"
#include "hkBool.h"
#include "hkpVehicleFrictionDescription.h"

typedef signed char hkInt8;

class hkpVehicleData : public hkReferencedObject
{
public:
    struct WheelComponentParams
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        class CommandArgument;
        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;

        hkReal m_fSphereRadius;
        hkReal m_fViscosityFriction;
        hkReal m_fMaxFriction;
        hkReal m_fSlipAngle;
        hkReal m_fSlipVelocity;
        hkReal m_fMaxContactBodyAcceleration;
        hkReal m_fForceFeedbackMultiplier;
        hkReal m_fMaxFrictionForce;
        hkReal m_fFrictionEqualizer;
        hkInt8 m_iAxle;
    };

    static void* __cdecl operator new(std::size_t nbytes);
    hkpVehicleData(FinishingFlag f);

    virtual void vf03();

    char pad8[0x8];
    hkVector4 m_kGravity;
    hkInt8 m_iWheelCount;
    char pad21[0xF];
    hkRotation m_kChassisOrientation;
    hkReal m_fChassisMass;
    hkReal m_fTorqueMax;
    hkReal m_fTorqueMin;
    hkReal m_fTorqueFactor;
    hkReal m_fTorquePitchFactor;
    hkReal m_fTorqueRollFactor;
    hkReal m_fTorqueYawFactor;
    hkReal m_fExtraTorqueFactor;
    hkReal m_fChassisUnitInertiaRoll;
    hkReal m_fChassisUnitInertiaPitch;
    hkReal m_fChassisUnitInertiaYaw;
    hkArray<WheelComponentParams> m_kWheelParams;
    hkArray<hkInt8> m_kNumWheelsPerAxle;
    hkpVehicleFrictionDescription m_kFrictionDescription;
    char pad174[0xC];
    hkVector4 m_vChassisUnitInertiaAndMassInv;
    hkBool m_bWheelsUseChassisForGround;
    char pad191[0xF];
};
