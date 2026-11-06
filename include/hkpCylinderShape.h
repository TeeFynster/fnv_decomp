#pragma once

#include "hkpConvexShape.h"
#include "hkVector4.h"

struct ShapeCallbackDispatchTable;

class hkpCylinderShape : public hkpConvexShape
{
public:
    enum VertexIdEncoding
    {
        VERTEX_ID_ENCODING_IS_BASE_A_SHIFT = 7,
        VERTEX_ID_ENCODING_SIN_SIGN_SHIFT = 6,
        VERTEX_ID_ENCODING_COS_SIGN_SHIFT = 5,
        VERTEX_ID_ENCODING_IS_SIN_LESSER_SHIFT = 4,
        VERTEX_ID_ENCODING_VALUE_MASK = 15
    };

    struct DefaultStruct;
    static const ClassMemberDescriptor Members[];
    static const hkClass& __cdecl staticClass();

    hkpCylinderShape(const hkVector4& vertexA, const hkVector4& vertexB,
                     hkReal cylinderRadius, hkReal paddingRadius);
    hkpCylinderShape(FinishingFlag flag);

    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& results) const;
    virtual int GetNumCollisionSpheres() const;
    virtual const hkSphere* GetCollisionSpheres(hkSphere* sphereBuffer) const;
    virtual void GetFirstVertex(hkVector4& v) const;
    virtual void GetSupportVertex(const hkVector4& direction, Vector4WithInt24W& supportingVertexOut) const;
    virtual void GetVerticesFromIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const;
    virtual void GetCentre(hkVector4& centreOut) const;

    const hkVector4* GetIndexedVertices() const { return &m_kVertexA; }
    const hkVector4& getVertex(int i) const;
    void setVertex(int i, const hkVector4& position);
    hkReal GetCylinderRadius() const;
    hkReal getCylinderRadius() const;  // 0x00d571a0 (Havok 7.1 hkpCylinderShape.h)
    void setCylinderRadius(hkReal radius);
    hkReal getCylinderBaseRadiusFactorForHeightfieldCollisions(hkReal radiusFactor);
    void setCylinderBaseRadiusFactorForHeightfieldCollisions(hkReal radiusFactor);
    void presetPerpendicularVector();
    void decodeVertexId(hkpVertexId code, hkVector4& result) const;
    hkReal FUN_00d571a0();
    hkBool FUN_00d57d50(const ShapeRayCastQuery& input, ShapeRayCastOutput& results) const;

    static void __cdecl registerSimulationFunctions(ShapeCallbackDispatchTable& sf);
    static void __cdecl registerCollideQueryFunctions(ShapeCallbackDispatchTable& sf);
    static void __cdecl registerRayCastFunctions(ShapeCallbackDispatchTable& sf);
    static void __cdecl registerGetAabbFunction(ShapeCallbackDispatchTable& sf);
    static void __cdecl setNumberOfVirtualSideSegements(int numSegments);
    static void __cdecl initRoundUpThreshold();

    static hkReal ms_fVirtualSideSegments;
    static hkReal ms_fRoundUpThreshold;
    static hkReal ms_fRoundUpThresholdInverse;

    hkReal m_fCylinderRadius;
    hkReal m_fCylinderRadiusSquared;
    char pad1C[0x4];
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
    hkVector4 m_kPerpendicular1;
    hkVector4 m_kPerpendicular2;
};
