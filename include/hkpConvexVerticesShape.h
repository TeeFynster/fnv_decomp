#pragma once

#include "hkpConvexShape.h"
#include "hkaAnimation.h"
#include "hkVector4.h"
#include "hkpConvexVerticesConnectivity.h"

class hkpConvexVerticesShapeFourVectors;
class hkVector4q;
struct hkSphereQ;
struct MatchVector;
struct FloatArrayDescriptor;
struct InputValues;
struct RefObj;
struct RayInput;
struct RayOutput;
struct hkBoolRet;
template <class T> struct hkArrayq;

class hkpConvexVerticesShape : public hkpConvexShape
{
public:
    hkpConvexVerticesShape(const FloatArrayDescriptor& vertices,
                          const hkArray<hkVector4>& planes, float radius);
    hkpConvexVerticesShape(InputValues* vertices,
                          const hkArray<hkVector4>& planes, float radius);
    virtual ~hkpConvexVerticesShape() throw();

    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
    virtual int GetNumCollisionSpheres() const;
    virtual const hkSphere* GetCollisionSpheres(hkSphere* sphereBuffer) const;
    virtual void GetFirstVertex(hkVector4& vertex) const;
    virtual void GetSupportVertex(const hkVector4& direction, Vector4WithInt24W& supportingVertexOut) const;
    virtual void GetVerticesFromIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const;
    virtual void GetCentre(__m128* out);

    hkSphereQ* FillSphereBuffer(hkSphereQ* sphereBuffer) const;
    void GetOriginalVertices(hkArray<hkVector4>& vertices) const;
    const hkArray<hkVector4>& GetPlaneEquations() const;
    hkpConvexVerticesShape* Initialize(const FloatArrayDescriptor& vertices,
                                     const hkArray<hkVector4>& planes, float radius);
    void Transform(const hkTransform& transform);
    void SetVertices(const hkArray<hkVector4>& vertices);
    void AssignReference(hkpConvexVerticesConnectivity* connectivity, bool update);
    void AssignReference(RefObj* connectivity, bool update);

    void hkpConvexVerticesShape_getSupportingVertexImpl(const MatchVector& direction, MatchVector& supportingVertexOut) const;
    hkBoolRet hkpConvexVerticesShape_castRayImpl(const RayInput& input, RayOutput& output);
    void FUN_00d59200(hkArray<hkVector4>& vertices) const;
    void FUN_00d59200(hkArrayq<hkVector4q>& vertices) const throw();
    void FUN_00d59870();
    void hkpConvexVerticesShape_copyVertexData(const float* vertices, int byteStriding, int numVertices);
    void hkpConvexVerticesShape_copyVertexData(int vertices, int byteStriding, int numVertices);
    void ProcessEntries_00d59f40();
    hkpConvexVerticesShape* FUN_00d5a4e0(unsigned char deleting);

    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    hkArray<hkpConvexVerticesShapeFourVectors> m_kRotatedVertices;
    int m_iStridedVertexCount;
    int unk50;
    hkArray<hkVector4> m_kVertexPositions;
    hkpConvexVerticesConnectivity* m_pConnectivity;
};
