#pragma once

#include "hkpConvexShape.h"

class hkpSphereShape : public hkpConvexShape
{
public:
    static const ClassMemberDescriptor Members[];

    hkpSphereShape(FinishingFlag kFlag);

    virtual void CalculateAabb(const hkTransform& kLocalToWorld, hkReal fTolerance, hkAabb& kOut) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& kInput, ShapeRayCastOutput& kOutput) const;
    virtual void CastRayWithCollector(const ShapeRayCastQuery& kInput, const hkpCdBody& kBody,
                                      hkpRayHitCollector& kCollector) const;

    virtual int GetNumCollisionSpheres() const;
    virtual const hkSphere* GetCollisionSpheres(hkSphere* pSphereBuffer) const;
    virtual void GetFirstVertex(hkVector4& kVec) const;
    virtual void GetSupportVertex(const hkVector4& kDirection, Vector4WithInt24W& kSupportingVertexOut) const;
    virtual void GetVerticesFromIds(const hkpVertexId* pIds, int iNumIds, Vector4WithInt24W* pVertices) const;
    virtual int WeldContactPoint(hkpVertexId* pFeaturePoints, hkUint8& kNumFeaturePoints,
                                 hkVector4& kContactPointWs, const hkTransform* pThisObjTransform,
                                 const hkpConvexShape* pCollidingShape, const hkTransform* pCollidingTransform,
                                 hkVector4& kSeparatingNormalInOut) const;
    virtual void GetCentre(hkVector4& kCentreOut) const;
};
