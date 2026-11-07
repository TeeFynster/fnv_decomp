#pragma once

#include "hkpConvexShape.h"
// Define when a complete hkVector4 is supplied before this header.
#ifndef FNV64_HKPBOXSHAPE_EXTERNAL_HKVECTOR4
#include "hkVector4.h"
#endif

struct BRRayCastInput;
struct BRRayCastOutput;

class hkpBoxShape : public hkpConvexShape
{
public:
    static const ClassMemberDescriptor Members[];

    virtual ~hkpBoxShape() throw();

    virtual int GetNumCollisionSpheres() const;
    virtual const hkSphere* GetCollisionSpheres(hkSphere* sphereBuffer) const;
    virtual void GetFirstVertex(hkVector4& vertex) const;
    virtual void GetSupportVertex(const hkVector4& direction, Vector4WithInt24W& supportingVertexOut) const;
    virtual void GetVerticesFromIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const;
    virtual int WeldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                                 hkVector4& contactPointWs, const hkTransform* thisObjTransform,
                                 const hkpConvexShape* collidingShape, const hkTransform* collidingTransform,
                                 hkVector4& separatingNormalInOut) const;
    virtual void GetCentre(hkVector4& centreOut) const;

    inline const hkVector4& getHalfExtents() const { return m_vHalfExtents; }
    void SetHalfExtents(const hkVector4& halfExtents);
    void GetHalfExtents(hkVector4& result) const;
    void GetAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const;
    void getSupportingVertexImpl(const float* src, float* dst);
    void* getCollisionSpheresImpl(__m128* sphereBuffer) const;
    hkBool castRayImpl(const BRRayCastInput& input, BRRayCastOutput& results) const;
    hkpBoxShape* SetExtentsAndRadius(const hkVector4& halfExtents, float radius);

    char pad14[0xC];
    hkVector4 m_vHalfExtents;
};
