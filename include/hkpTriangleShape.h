#pragma once

#include "hkpConvexShape.h"
#include "hkVector4.h"

class hkVector4_S;

class hkpWeldingUtility
{
public:
    enum WeldingType
    {
        WELDING_TYPE_ANTICLOCKWISE = 0,
        WELDING_TYPE_CLOCKWISE = 4,
        WELDING_TYPE_TWO_SIDED = 5,
        WELDING_TYPE_NONE = 6
    };
};

class hkpTriangleShape : public hkpConvexShape
{
public:
    static const ClassMemberDescriptor Members[];

    hkpTriangleShape(float fRadius, unsigned short uWeldingInfo, int iWeldingType) throw();

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
    virtual void vf17(hkVector4* pOut);

    void setVertex(int i, const hkVector4& kVertexDelta)
    {
        (&m_kVertexA)[i] = kVertexDelta;
    }

    const hkVector4& getVertex(int iIndex) const;
    unsigned short getWeldingInfo() const;
    hkpWeldingUtility::WeldingType getWeldingType() const;
    const hkVector4_S* GetIndexedVertices() const;
    __forceinline float getRadius() const;
    void setType();

    unsigned short m_kWeldingInfo;
    hkEnum<hkpWeldingUtility::WeldingType, hkUint8> m_eWeldingType;
    hkUint8 m_ucWeldingPadding;
    char pad18[0x8];
    union
    {
        struct
        {
            hkVector4 m_kVertexA;
            hkVector4 m_kVertexB;
            hkVector4 m_kVertexC;
        };
        struct
        {
            hkVector4 m_kVertices[3];
        };
    };
    hkVector4 m_kVertexTransform;
};
