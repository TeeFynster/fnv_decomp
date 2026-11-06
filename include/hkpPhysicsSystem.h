#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkaAnimation.h"
#include "hkBool.h"
#include "hkStringPtr.h"

class hkpRigidBody;
class hkpConstraintInstance;
class hkpAction;
class hkpPhantom;
struct BoolResult;

typedef unsigned long hkUlong;

class hkpPhysicsSystem : public hkReferencedObject
{
public:
    hkArray<hkpRigidBody*> m_ppRigidBodies;
    hkArray<hkpConstraintInstance*> m_ppConstraints;
    hkArray<hkpAction*> m_ppActions;
    hkArray<hkpPhantom*> m_kPhantoms;
    hkStringPtr m_name;
    hkUlong m_ulUserData;
    hkBool m_bSlotEnabled;
    char pad41[3];

    hkpPhysicsSystem();
    hkpPhysicsSystem(FinishingFlag f);
    virtual ~hkpPhysicsSystem() throw();
    virtual void vfunc3() throw();
    virtual BoolResult vfunc4() throw();

    void vfunc1() throw();
    void vfunc2() throw();
    static void* __cdecl operator new(std::size_t nbytes);
    const hkArray<hkpRigidBody*>& getRigidBodies() const;
    void __thiscall AddShape(hkpRigidBody* body);
    void __thiscall AddAction(hkpAction* action);
    void __thiscall FUN_00d064f0(void* phantom);
    void __thiscall FUN_00d06540(hkpConstraintInstance* constraint);
    void __thiscall FUN_00d06590(hkpAction* action);
    void __thiscall FUN_00d06130(int index);
    void __thiscall FUN_00d061b0(int index);
    void __thiscall FUN_00d061f0(int index);
};
