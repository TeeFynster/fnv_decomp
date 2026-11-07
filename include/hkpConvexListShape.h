#pragma once

#include "hkpConvexShape.h"
#include "hkpShapeContainer.h"
#include "hkVector4.h"
#include "hkBool.h"
#include "hkArray.h"
#include "hkaAnimation.h"

class hkpConvexListShape : public hkpConvexShape, public hkpShapeContainer
{
public:
    hkpConvexListShape(hkpConvexShape** children, int numChildren) throw();
    virtual ~hkpConvexListShape() throw();

    virtual void vf17();

    void SetChildren(hkpConvexShape** children, int numChildren) throw();
    void UpdateCachedAabb(bool useCachedAabb) throw();
    void hkReferencedObject_calcContentStatistics(hkStatisticsCollector* collector, int* cls);
    void calcContentStatistics_00d5e480(hkStatisticsCollector* collector, int cls);

    union
    {
        hkReal m_fMaximumRadius;
        float m_minDistanceToUseConvexHull;
    };
    char pad1C[0x4];
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    hkBool m_bUseCachedAabb;
    char pad41[0x3];
    hkArray<hkpConvexShape*> m_kChildShapes;
};
