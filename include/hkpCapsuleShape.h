#pragma once

#include "hkpConvexShape.h"
#include "hkVector4.h"

struct ShapeCallbackDispatchTable;

typedef const hkVector4& hkVector4Parameter;

class hkpCapsuleShape : public hkpConvexShape
{
public:
    enum RayHitType
    {
        HIT_CAP0 = 0,
        HIT_CAP1 = 1,
        HIT_BODY = 2
    };

    struct DefaultStruct;
    static const ClassMemberDescriptor Members[];
    static const hkClass& __cdecl staticClass();

    hkpCapsuleShape(const hkVector4& vertexA, const hkVector4& vertexB, hkReal radius);
    hkpCapsuleShape(FinishingFlag flag);

    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& results) const;

    virtual int GetNumCollisionSpheres() const;
    virtual const hkSphere* GetCollisionSpheres(hkSphere* sphereBuffer) const;
    virtual void GetFirstVertex(hkVector4& v) const;
    virtual void GetSupportVertex(hkVector4Parameter direction, Vector4WithInt24W& supportingVertexOut) const;
    virtual void GetVerticesFromIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const;
    virtual int WeldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                                 hkVector4& contactPointWs, const hkTransform* thisObjTransform,
                                 const hkpConvexShape* collidingShape, const hkTransform* collidingTransform,
                                 hkVector4& separatingNormalInOut) const;
    virtual void GetCentre(hkVector4& centreOut) const;

    const hkVector4* GetIndexedVertices() const;
    const hkVector4& getVertex(int i) const;
    void setVertex(int i, const hkVector4& position);

    static void __cdecl registerSimulationFunctions(ShapeCallbackDispatchTable& sf);
    static void __cdecl registerCollideQueryFunctions(ShapeCallbackDispatchTable& sf);
    static void __cdecl registerRayCastFunctions(ShapeCallbackDispatchTable& sf);
    static void __cdecl registerGetAabbFunction(ShapeCallbackDispatchTable& sf);
    static void __cdecl GetClosestPointOnLineSegment(const hkVector4& A, const hkVector4& B,
                                                     const hkVector4& B2, hkVector4& pt);
    static void __cdecl GetClosestPointsBetweenInfiniteLines(const hkVector4& A, const hkVector4& dA,
                                                              const hkVector4& B, const hkVector4& dB,
                                                              hkReal& distSquared, hkReal& t, hkReal& u,
                                                              hkVector4& p, hkVector4& q);

    char pad14[0xC];
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
};
