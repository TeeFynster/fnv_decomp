#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkBool.h"
#include "hkContactPoint.h"

class hkpRigidBody;
class hkpVehicleInstance;

class hkpVehicleWheelCollide : public hkReferencedObject
{
public:
    struct WheelCollideResult
    {
    public:
        enum { MAX_NUM_SHAPE_KEYS = 8 };

        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        class CommandArgument;

        hkContactPoint m_vContactPoint;
        float m_fSuspensionLength;
        hkpRigidBody* m_pUserData;
        unsigned int m_contactShapeKey0;
        unsigned int m_contactShapeKey1;
        unsigned int m_contactShapeKey2;
        unsigned int m_contactShapeKey3;
        unsigned int m_contactShapeKey4;
        unsigned int m_contactShapeKey5;
        unsigned int m_contactShapeKey6;
        unsigned int m_contactShapeKey7;
        float m_fContactFriction;
        float m_fValueAtOffset4C;
        float m_fValueAtOffset50;
    };

    enum WheelCollideType
    {
        INVALID_WHEEL_COLLIDE = 0,
        RAY_CAST_WHEEL_COLLIDE = 1,
        LINEAR_CAST_WHEEL_COLLIDE = 2,
        USER_WHEEL_COLLIDE1 = 3,
        USER_WHEEL_COLLIDE2 = 4,
        USER_WHEEL_COLLIDE3 = 5,
        USER_WHEEL_COLLIDE4 = 6,
        USER_WHEEL_COLLIDE5 = 7
    };

    static void* __cdecl operator new(std::size_t nbytes);

    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void InitializeWheelCollisionOutput(const hkpVehicleInstance*, unsigned char,
                                                WheelCollideResult&);

    hkBool m_bWheelCollisionEnabled;
    unsigned char m_type;
    char padA[2];

};
