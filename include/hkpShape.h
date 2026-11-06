#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "FinishingFlag.h"
#include "hkBool.h"

class hkAabb;
class hkTransform;
class hkVector4;
class hkpCdBody;
class hkpRayHitCollector;
class hkpShapeContainer;
class Vector4Comparison;
struct ClassMemberDescriptor;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;

typedef float hkReal;
typedef unsigned long hkUlong;
typedef unsigned int hkUint32;
typedef const Vector4Comparison& hkVector4ComparisonParameter;

// Shape type ids as the exe's agent/dispatch tables index them (values are what the code compares against).
enum hkpShapeType  // src: HAVOK_SRC (names)
{
    HK_SHAPE_ALL = -1,
    HK_SHAPE_INVALID = 0,
    HK_SHAPE_SPHERE = 1,
    HK_SHAPE_CYLINDER = 2,
    HK_SHAPE_TRIANGLE = 3,
    HK_SHAPE_BOX = 4,
    HK_SHAPE_CAPSULE = 5,
    HK_SHAPE_CONVEX_VERTICES = 6,
    HK_SHAPE_COLLECTION = 7,
    HK_SHAPE_BV_TREE = 8,
    HK_SHAPE_LIST = 9,
    HK_SHAPE_MOPP = 10,
    HK_SHAPE_CONVEX_TRANSLATE = 11,
    HK_SHAPE_CONVEX_TRANSFORM = 12,
    HK_SHAPE_SAMPLED_HEIGHT_FIELD = 13,
    HK_SHAPE_EXTENDED_MESH = 14,
    HK_SHAPE_TRANSFORM = 15,
    HK_SHAPE_COMPRESSED_MESH = 16,
    HK_SHAPE_MAX_ID_SPU = 17,
    HK_SHAPE_CONVEX = 18,
    HK_SHAPE_PACKED_CONVEX_VERTICES = 19,
    HK_SHAPE_MOPP_EMBEDDED = 20,
    HK_SHAPE_CONVEX_PIECE = 21,
    HK_SHAPE_MULTI_SPHERE = 22,
    HK_SHAPE_CONVEX_LIST = 23,
    HK_SHAPE_TRIANGLE_COLLECTION = 24,
    HK_SHAPE_MULTI_RAY = 25,
    HK_SHAPE_HEIGHT_FIELD = 26,
    HK_SHAPE_SPHERE_REP = 27,
    HK_SHAPE_BV = 28,
    HK_SHAPE_PLANE = 29,
    HK_SHAPE_PHANTOM_CALLBACK = 30,
    HK_SHAPE_USER0 = 31,
    HK_SHAPE_USER1 = 32,
    HK_SHAPE_USER2 = 33,
    HK_SHAPE_MAX_ID = 34,
    HK_FIRST_SHAPE_TYPE = HK_SHAPE_SPHERE
};

#include "hkEnum.h"

class hkpShape : public hkReferencedObject
{
public:
    static const ClassMemberDescriptor Members[];

    struct PhysicsShape
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t nbytes, void* p);
        static void* __cdecl operator new[](std::size_t nbytes, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);

        class CommandArgument;
        bool m_bIsConvex;
        bool m_bIsConvexPiece;
        bool m_bIsComposite;
    };

    hkpShape();
    hkpShape(hkpShapeType type);
    hkpShape(FinishingFlag flag);

    virtual hkReal getMaximumProjection(const hkVector4& direction) const;
    virtual const hkpShapeContainer* GetShapeContainer() const;
    virtual bool isConvex() const;
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const = 0;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const = 0;
    virtual void CastRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const = 0;
    virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput& input, ShapeRayCastOutputArray& output,
                                            hkVector4ComparisonParameter mask) const;

    hkpShapeType getType() const;
    void getAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
    hkBool RayCast(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
    void castRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                              hkpRayHitCollector& collector) const;
    static void __cdecl resetShapeFunctions();

    hkUlong m_ulUserData;
    hkEnum<hkpShapeType, hkUint32> m_type;
};
