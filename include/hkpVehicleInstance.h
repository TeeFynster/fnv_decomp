#pragma once

#include <cstddef>
#include "hkpUnaryAction.h"
#include "hkaAnimation.h"
#include "hkBool.h"
#include "hkContactPoint.h"
#include "hkQuaternion.h"
#include "hkpVehicleFrictionStatus.h"
#include "hkpVehicleWheelCollide.h"

class hkpRigidBody;
class hkpVehicleData;
class hkpVehicleDriverInput;
class hkpVehicleSteering;
class hkpVehicleEngine;
class hkpVehicleTransmission;
class hkpVehicleBrake;
class hkpVehicleSuspension;
class hkpVehicleAerodynamics;
class hkpTyremarksInfo;
class hkpVehicleVelocityDamper;
class hkpVehicleDriverInputStatus;
class hkpVehicleInstanceWheelInfo;
struct WGround;

class hkpVehicleInstance : public hkpUnaryAction
{
public:
    static void* __cdecl operator new(std::size_t nbytes);

    struct WheelInfo
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
        enum { MAX_NUM_SHAPE_KEYS = 8 };

        hkContactPoint m_vContactPoint;
        hkReal m_fSuspensionLength;
        hkpRigidBody* m_pUserData;
        unsigned int m_contactShapeKey0;
        unsigned int m_contactShapeKey1;
        unsigned int m_contactShapeKey2;
        unsigned int m_contactShapeKey3;
        unsigned int m_contactShapeKey4;
        unsigned int m_contactShapeKey5;
        unsigned int m_contactShapeKey6;
        unsigned int m_contactShapeKey7;
        hkVector4 m_vContactPointVelocity;
        hkVector4 m_vContactNormal;
        hkReal m_fContactFriction;
        hkVector4 m_vHardPointWs;
        hkVector4 m_vRayEndPointWs;
        hkVector4 m_vSuspensionDirectionWs;
        hkQuaternion m_qSteeringOrientation;
        hkReal m_fValueAtOffsetC0;
        hkReal m_fSpinAngle;
        hkReal m_fSkidEnergyDensity;
        hkReal m_fSideForce;
        hkReal m_fSuspensionForce;
        hkReal m_fForwardForce;

        void init();
    };

    static const unsigned char s_maxNumLocalWheels = 16;

    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();

    void UpdateVehicle(hkReal deltaTime, const hkpVehicleWheelCollide::WheelCollideResult* cdInfo);
    hkpRigidBody* getChassis() const;
    void ProcessEntries_00e38310(float deltaTime, const int* groundBody, const WGround* ground);

    hkpVehicleData* m_data;
    hkpVehicleDriverInput* m_pDriverInput;
    hkpVehicleSteering* m_pSteering;
    hkpVehicleEngine* m_pVehicleEngine;
    hkpVehicleTransmission* m_pTransmission;
    hkpVehicleBrake* m_pBrake;
    hkpVehicleSuspension* m_pSuspension;
    hkpVehicleAerodynamics* m_pAerodynamics;
    hkpVehicleWheelCollide* m_pWheelCollide;
    hkpTyremarksInfo* m_pTyremarksInfo;
    hkpVehicleVelocityDamper* m_pVelocityDamper;
    hkArray<hkpVehicleInstanceWheelInfo> m_kWheelInfoArray;
    hkpVehicleFrictionStatus m_kFrictionStatus;
    hkpVehicleDriverInputStatus* m_pDriverInputStatus;
    hkArray<hkBool> m_kSecondRealArray;
    hkReal m_fBrakeState;
    hkBool m_bIsReversing;
    char padB1[3];
    hkReal m_fFirstValueBeforeSteeringAngle;
    hkReal m_fSecondValueBeforeSteeringAngle;
    hkReal m_fMainSteeringAngle;
    hkArray<hkReal> m_kWheelSteeringAngles;
    hkBool m_iGearCount;
    signed char m_iGearCapacity;
    hkBool m_bGearShiftActive;
    char padCF[1];
    hkReal m_fGearShiftTime;
};
