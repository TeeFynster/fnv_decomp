#pragma once

#include "hkpPhantom.h"
#include "hkMotionState.h"

class hkTransform;
class hkpRigidBody;

class hkpShapePhantom : public hkpPhantom
{
public:
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();

    void hkpShapePhantom_setTransform(const hkTransform& t);
    void __thiscall SetWorldPosition(void* body, float pos);
    void __thiscall SetWorldPosition(hkpRigidBody* body, float pos);

    char padA4[0xC];
    hkMotionState m_kMotionState;
};
