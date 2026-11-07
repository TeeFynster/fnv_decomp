#pragma once

#include "hkDisplayGeometry.h"
#include "hkVector4.h"

typedef float hkReal;

class hkDisplaySemiCircle : public hkDisplayGeometry
{
public:
    hkDisplaySemiCircle(const hkVector4& center, const hkVector4& normal, const hkVector4& startPerp,
                        hkReal thetaMin, hkReal thetaMax, hkReal radius, int numSegments);

    void UpdateState_00de4950(hkReal radius, hkReal thetaMin, hkReal thetaMax, int numSegments,
                      const hkVector4& center, const hkVector4& normal, const hkVector4& startPerp);

    hkVector4 m_vHitNormal;
    hkVector4 m_kCenterPosition;
    hkVector4 m_kStartPerpendicular;
    hkReal m_fThetaMin;
    hkReal m_fThetaMax;
    hkReal m_fSphereRadius;
    int m_iNumSegments;
    int unk90;
};
