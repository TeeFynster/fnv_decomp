#pragma once

#include "hkReferencedObject.h"

typedef float hkReal;
struct VectorQ;
class hkBoolC;

class hkpParametricCurve : public hkReferencedObject
{
public:
    virtual ~hkpParametricCurve() throw();
    virtual void vf0c();
    virtual hkReal FindNearestPoint(hkReal t, const VectorQ& point, VectorQ& nearestPointOut);
    virtual void GetTangentAt(hkReal t, VectorQ& tangentOut);
    virtual hkReal GetStreamStart();
    virtual hkReal GetStreamEnd();
    virtual hkReal GetCurvature(hkReal t);
    virtual void GetBinormal(hkReal t, VectorQ& binormalOut);
    virtual hkBoolC IsClosedCurve();
};
