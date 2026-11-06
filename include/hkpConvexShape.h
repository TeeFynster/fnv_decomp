#pragma once

#include "hkpShape.h"

class hkSphere;
class hkTransform_S;
class hkVector4_S;
class hkVector4X;
class Vector4WithInt24W;
struct hkVec4X;

typedef unsigned char hkUint8;
typedef unsigned short hkpVertexId;

class hkpConvexShape : public hkpShape
{
public:
    enum WeldResult
    {
        WELD_RESULT_REJECT_CONTACT_POINT = 0,
        WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED = 1,
        WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED = 2
    };

    static const ClassMemberDescriptor Members[];

    hkpConvexShape(hkpShapeType type, hkReal radius);
    hkpConvexShape(int iType, float fRadius);
    hkpConvexShape(FinishingFlag flag);

    virtual int GetNumCollisionSpheres() const;
    virtual const hkSphere* GetCollisionSpheres(hkSphere* sphereBuffer) const;
    virtual void GetFirstVertex(hkVector4& v) const = 0;
    virtual void GetSupportVertex(const hkVector4& direction, Vector4WithInt24W& supportingVertexOut) const = 0;
    virtual void GetVerticesFromIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* vertices) const = 0;
    virtual int WeldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                                 hkVector4& contactPointWs, const hkTransform* thisObjTransform,
                                 const hkpConvexShape* collidingShape, const hkTransform* collidingTransform,
                                 hkVector4& separatingNormalInOut) const;
    __forceinline int getNumCollisionSpheres() const;
    __forceinline const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer) const;
    __forceinline void GetVerticesForIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* vertices) const;

    __forceinline WeldResult weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                               hkVector4& contactPointWs, const hkTransform* thisObjTransform,
                               const hkpConvexShape* collidingShape, const hkTransform* collidingTransform,
                               hkVector4& separatingNormalInOut) const;
    __forceinline WeldResult weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                               hkVector4X& contactPointWs, const hkTransform* thisObjTransform,
                               const hkpConvexShape* collidingShape, const hkTransform* collidingTransform,
                               hkVector4X& separatingNormalInOut) const;
    __forceinline WeldResult weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                               hkVector4& contactPointWs, const hkTransform_S* thisObjTransform,
                               const hkpConvexShape* collidingShape, const hkTransform_S* collidingTransform,
                               hkVector4& separatingNormalInOut) const;
    __forceinline WeldResult weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                               hkVec4X& contactPointWs, const hkTransform* thisObjTransform,
                               const hkpConvexShape* collidingShape, const hkTransform* collidingTransform,
                               hkVec4X& separatingNormalInOut) const;
    __forceinline WeldResult weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                               hkVector4_S& contactPointWs, const hkTransform* thisObjTransform,
                               const hkpConvexShape* collidingShape, const hkTransform* collidingTransform,
                               hkVector4_S& separatingNormalInOut) const;

    __forceinline hkReal getRadius() const { return m_fSphereRadius; }

    hkReal m_fSphereRadius;
};
