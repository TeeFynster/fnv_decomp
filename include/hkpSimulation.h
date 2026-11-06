#pragma once

#include "hkReferencedObject.h"

class hkpWorld;

typedef unsigned int hkUint32;
typedef unsigned char hkUint8;
typedef float hkReal;
typedef hkReal hkTime;

class hkpSimulation : public hkReferencedObject
{
public:
    enum FindContacts
    {
        FIND_CONTACTS_DEFAULT = 0,
        FIND_CONTACTS_EXTRA = 1
    };

    enum ResetCollisionInformation
    {
        RESET_TOI = 1,
        RESET_TIM = 2,
        RESET_AABB = 4,
        RESET_ALL = 7
    };

    enum LastProcessingStep
    {
        INTEGRATE = 0,
        COLLIDE = 1
    };

    virtual void WarpTime(hkReal deltaTime);
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void shiftTime(float shift);

    static const ClassMemberDescriptor Members[];

    void checkDeltaTimeIsOk(hkReal deltaTime);
    void setCurrentTime(hkTime time) { m_fElapsedSimulationTime = time; }

    hkUint32 m_eLastProcessingStep;
    hkpWorld* m_pOwningWorld;
    hkUint8 m_bHasStepped;
    char pad11[3];
    hkReal m_fElapsedSimulationTime;
    hkReal m_fSimulationTime;
    hkReal m_fStepDeltaTime;
    hkReal m_fFrameMarkerTime;
    hkReal m_fFrameMarkerPsiSnap;
    hkUint32 m_uiSimulationType;
};
