#pragma once

#include "hkpVehicleWheelCollide.h"
#include "hkpRejectChassisListener.h"
#include "hkArray.h"

class hkpAabbPhantom;
class hkpCollisionFilter;
class hkpVehicleInstance;
class hkpVehicleInstanceWheelInfo;
class hkpWorldObject;
union hkAabbQ;
struct hkpWorldRayCastOutput;
struct CollidableRayCastCommand;

typedef unsigned int hkUint32;
typedef int hkInt32;

class hkpVehicleRayCastWheelCollide : public hkpVehicleWheelCollide
{
public:
    __declspec(noinline) hkpVehicleRayCastWheelCollide();
    virtual ~hkpVehicleRayCastWheelCollide() throw();

    virtual void vf12();
    virtual void GetWheelAabb(const hkpVehicleInstance*, hkAabbQ*);
    virtual void CastWheelRay(const hkpVehicleInstanceWheelInfo&, hkpWorldRayCastOutput&);
    virtual void ProcessWheelRayCastResult(const hkpVehicleInstance*, unsigned char,
                                         const hkpWorldRayCastOutput&, WheelCollideResult&);
    virtual void FinalizeWheelCollisionOutput(const hkpVehicleInstance*, unsigned char,
                                            WheelCollideResult&);

    static void* operator new(unsigned int nbytes);
    static void operator delete(void* p);
    void SetUserInfo(int value);
    void UpdatePhantom(const hkpVehicleInstance* vehicle);
    void* AddToWorld(void* world);
    void RemoveFromWorld();
    void CreateWheelPhantom(const hkpVehicleInstance* vehicle);
    void Destroy();
    void AppendPhantom(hkArray<hkpAabbPhantom*>& phantoms);
    void CollideWheels(float deltaTime, const hkpVehicleInstance* vehicle,
                       WheelCollideResult* output);
    int BuildRayCastCommands(const hkpVehicleInstance* vehicle, const hkpCollisionFilter* filter,
                             hkInt32 filterSize, CollidableRayCastCommand* commands,
                             hkpWorldRayCastOutput* results) const;
    hkpVehicleRayCastWheelCollide* Clone(hkpWorldObject* chassis,
                                       const hkArray<hkpAabbPhantom*>& phantoms);

    hkUint32 m_uiWheelCount;
    hkpAabbPhantom* m_pPhantom;
    hkpRejectChassisListener m_kChassisRejectionListener;
};
