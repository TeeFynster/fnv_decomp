#pragma once

#include "NiPlane.h"

class NiFrustumPlanes
{
public:
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;

    NiFrustumPlanes() : m_uiActivePlaneMask(63) {}

    void Set(void*, void*);
    void Set(void*);
    void* GetPlane(unsigned int);
    void SetWaterColorParameter(unsigned int, void*);
    bool IsPlaneActive(unsigned int);
    bool IsAnyPlaneActive();
    bool AreAllPlanesActive();
    void EnablePlane(unsigned int);
    void DisablePlane(unsigned int);
    void EnableAllPlanes();
    void DisableAllPlanes();
    unsigned int GetActivePlaneState();
    void SetActivePlaneState(unsigned int);
};
