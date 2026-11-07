#pragma once

#include "hkMoppBvTreeShapeBase.h"
#include "hkpSingleShapeContainer.h"

class hkpShapeCollection;

class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
{
public:
    static const ClassMemberDescriptor Members[];

    virtual ~hkpMoppBvTreeShape() throw();
    virtual void calcContentStatistics(hkStatisticsCollector* pCollector, const hkClass* pCls) const throw();
    virtual const hkpShapeContainer* GetShapeContainer() const;
    virtual int CalcSizeForSpu(const PhysicsShape& kInput, int iSpuBufferSizeLeft) const;
    virtual void CalculateAabb(const hkTransform& kLocalToWorld, hkReal fTolerance, hkAabb& kOut) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& kInput, ShapeRayCastOutput& kOutput) const;
    virtual void CastRayWithCollector(const ShapeRayCastQuery& kInput, const hkpCdBody& kBody,
                                      hkpRayHitCollector& kCollector) const;
    virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput& kInput, ShapeRayCastOutputArray& kOutput,
                                            hkVector4ComparisonParameter kMask) const;
    virtual void GetObbHits(const hkTransform& kObbTransform, const hkVector4& kObbExtent,
                            hkReal fTolerance, hkArray<hkpShapeKey>& kHits) const;
    virtual void GetAabbHits(const hkAabb& kAabb, hkArray<hkpShapeKey>& kHits) const;
    virtual hkUint32 GetAabbHitsToBuffer(const hkAabb& kAabb, hkpShapeKey* pHits, int iMaxNumKeys) const;

    using hkMoppBvTreeShapeBase::GetAabbHits;

    const hkpShapeCollection* getShapeCollection() const;
    void hkMoppBvTreeShapeBase_queryAabb(const hkAabb& kAabbIn, hkArray<unsigned int>& kHits) const;
    Vector4Comparison castRayBundleImpl(const ShapeRayBundleCastInput& kInput, ShapeRayCastOutputArray& kOutput,
                                  hkVector4ComparisonParameter kMask) const throw();

    hkpSingleShapeContainer m_pChildAtom;
    mutable int m_iChildSize;
    int unk3C;
};
