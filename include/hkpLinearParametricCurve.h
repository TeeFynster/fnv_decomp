#pragma once

#include "hkpParametricCurve.h"
#include "hkBool.h"
#include "hkVector4.h"
#include "hkArray.h"
#include "hkaAnimation.h"

class hkpLinearParametricCurve : public hkpParametricCurve
{
public:
    __declspec(noinline) hkpLinearParametricCurve() throw();
    virtual ~hkpLinearParametricCurve() throw();

    virtual void vf11();
    virtual void vf12();
    virtual void vf13();

    hkReal m_fSmoothingValue;
    hkBool m_bClosedLoop;
    char padD[0x3];
    hkVector4 m_kVector4;
    hkArray<hkVector4> m_kPoints;
    hkArray<hkReal> m_fClosestPointDistanceSquared;
    char pad38[0x8];
};
