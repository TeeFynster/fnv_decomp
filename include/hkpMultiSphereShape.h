#pragma once

#include "hkpSphereRepShape.h"

#include <xmmintrin.h>

#include "hkVector4.h"

class hkpMultiSphereShape : public hkpSphereRepShape
{
public:
    hkpMultiSphereShape(const hkVector4* pSpheres, int iCount);

    virtual void calcContentStatistics(hkStatisticsCollector* pCollector, const hkClass* pCls) const;
    virtual void CalculateAabb(const hkTransform& kLocalToWorld, hkReal fTolerance, hkAabb& kOut) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& kInput, ShapeRayCastOutput& kOutput) const;
    virtual void CastRayWithCollector(const ShapeRayCastQuery& kInput, const hkpCdBody& kBody,
                                      hkpRayHitCollector& kCollector) const;
    virtual int getNumCollisionSpheres() const;
    virtual hkVector4* CopySpheres(hkVector4* pDst);

    int m_iSphereCount;
    char pad14[0xC];
    hkVector4 m_kSpheres[8];
};
