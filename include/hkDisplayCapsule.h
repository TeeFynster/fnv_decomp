#pragma once

#include "hkDisplayGeometry.h"
#include "hkVector4.h"

typedef float hkReal;

class hkDisplayCapsule : public hkDisplayGeometry
{
public:
    hkDisplayCapsule(const hkVector4& top, const hkVector4& bottom, hkReal radius, int numSides,
                     int numHeightSegments);

    virtual ~hkDisplayCapsule() throw();
    virtual void vf03();
    virtual void vf04();

    hkVector4 m_fMinimumV;
    hkVector4 m_fMaximumV;
    hkReal m_fSphereRadius;
    int m_iNumSides;
    int m_iNumHeightSegments;
    int unk7C;
    int unk80;

    void buildGeometry();
};
