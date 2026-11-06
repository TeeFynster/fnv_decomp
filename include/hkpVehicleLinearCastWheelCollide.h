#pragma once

#include "hkpVehicleWheelCollide.h"
#include "hkaAnimation.h"
#include "hkArray.h"
#include "hkAabb.h"
#include "hkpRejectChassisListener.h"

class hkpVehicleLinearCastWheelCollideWheelState;
class hkpAabbPhantom;
class hkpCollisionFilter;
class hkpCollidable;
class hkpPairLinearCastCommand;
class hkpPhantom;
class hkpRootCdPoint;
class hkpShape;
class hkpWorld;
struct LCHit;
struct LCWheelCastOut;

class hkpCollidable;

typedef unsigned int hkUint32;

class hkpVehicleLinearCastWheelCollide : public hkpVehicleWheelCollide
{
public:
    hkpVehicleLinearCastWheelCollide() throw();
    virtual ~hkpVehicleLinearCastWheelCollide() throw();

    virtual int GetTotalHits() const;
    virtual int getNumHits(unsigned char ucWheel) const;
    virtual int FUN_00e363d0(const hkpVehicleInstance* vehicle, const hkpCollisionFilter* filter,
                            hkpCollidable* collidables, hkpPairLinearCastCommand* commands,
                            hkpRootCdPoint* results) const throw();
    virtual hkContactPoint* FUN_00e36250(int iWheel, LCHit* pHits);
    virtual char* castQuery(char* found, hkpVehicleInstance* vehicle, unsigned char iWheel,
                            LCWheelCastOut* out);
    virtual void applyHit(hkpVehicleInstance* vehicle, unsigned char iWheel,
                           LCWheelCastOut* out, WheelCollideResult* results);
    virtual void noHit(hkpVehicleInstance* vehicle, unsigned char iWheel, WheelCollideResult* results);

    static void* operator new(unsigned int uiSize) throw();
    static void operator delete(void* p) throw();

    void InitializeWheelCollisions(const hkpVehicleInstance* vehicle) throw();
    void UpdateAllWheels(int unused, hkpVehicleInstance* vehicle, WheelCollideResult* results);
    void FUN_00e36ab0(hkArray<hkpPhantom*>* output);
    void UpdateWheelAabb(unsigned char wheelIndex);
    hkpVehicleLinearCastWheelCollide* CloneWithChassis(const hkpRigidBody& chassis,
                                                      const hkArray<hkpPhantom*>& phantoms) const throw();
    void FUN_00e36870(hkpWorld* world);
    void FUN_00e368a0();
    void SetTargetArg(void* arg);
    void FUN_00e36900(int unused, unsigned char wheelIndex, hkVector4* result);
    int getNumHits(int iWheel);
    unsigned int FUN_00e363a0(unsigned char wheelIndex);
    void CastWheel(int hitOut, hkUint32 unused, unsigned char wheelIndex, int context);
    void SetWheelPhantoms(const hkpVehicleInstance* vehicle,
                          const hkArray<hkReferencedObject*>& phantoms);
    hkpShape* FUN_00e36120(hkReal height, hkReal radius) throw();
    void FUN_00e36700(const hkpVehicleInstance* vehicle, unsigned char wheelIndex,
                      hkAabb& aabb) throw();
    void FUN_00e367d0(const hkpVehicleInstance* vehicle, unsigned char wheelIndex) throw();
    void FUN_00e36700(unsigned char wheelIndex, unsigned char stateIndex, hkAabb* aabb);
    void FUN_00e367d0(unsigned char wheelIndex, unsigned char stateIndex);

    hkUint32 m_uiWheelCount;
    hkArray<hkpVehicleLinearCastWheelCollideWheelState> m_kWheelStates;
    hkpRejectChassisListener m_kRejectChassisListener;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fMaxExtraPenetrationAgainstFixed;
};

