#pragma once

#include "hkpShape.h"
#include "hkpSingleShapeContainer.h"
#include "hkQuaternion.h"
#include "hkTransform.h"

class hkpTransformShape : public hkpShape
{
public:
    hkpTransformShape(const hkpShape* childShape, const hkTransform& transform);

    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const throw();
    virtual hkReal getMaximumProjection(const hkVector4& direction) const;
    virtual const hkpShapeContainer* GetShapeContainer() const;
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
    virtual void CastRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const;

    int Initialize(hkpShape* child, const hkTransform& transform);
    void SetTransform(const hkTransform& transform);
    hkpTransformShape* DestroyAndMaybeFree(unsigned int flags) throw();

    const hkpShape* GetShapeForKey() const;
    const hkTransform& getTransform() const;

    hkpSingleShapeContainer m_pContainedShape;
    int m_iChildShapeSize;
    char pad1C[4];
    hkQuaternion m_rotation;
    hkTransform m_kMotionTransform;
};
