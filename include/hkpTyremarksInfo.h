#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkpTyremarksWheel;

class hkpTyremarksInfo : public hkReferencedObject
{
public:
    virtual ~hkpTyremarksInfo() throw();
    virtual void vf03();
    virtual void vf04();

    void updateTyremarksInfo(float deltaTime, void* vehicle); // exe: 0x00e39fd0

    hkReal m_fMinTyremarkPointDistance;
    hkReal m_fMaxTyremarkPointDistance;
    hkArray<hkpTyremarksWheel*> m_kTyremarksWheels;
};
