#pragma once

#include "hkReferencedObject.h"
#include "hkpCollidableCollidableFilter.h"
#include "hkpShapeCollectionFilter.h"
#include "hkpRayShapeCollectionFilter.h"
#include "hkpRayCollidableFilter.h"

class __declspec(align(16)) hkpCollisionFilter : public hkReferencedObject,
                           public hkpCollidableCollidableFilter,
                           public hkpShapeCollectionFilter,
                           public hkpRayShapeCollectionFilter,
                           public hkpRayCollidableFilter
{
public:
    static const ClassMemberDescriptor Members[];

    enum hkpFilterType
    {
        HK_FILTER_UNKNOWN = 0,
        HK_FILTER_NULL = 1,
        HK_FILTER_GROUP = 2,
        HK_FILTER_LIST = 3,
        HK_FILTER_CUSTOM = 4,
        HK_FILTER_PAIR = 5,
        HK_FILTER_CONSTRAINT = 6
    };

    hkpCollisionFilter();
    hkpCollisionFilter(FinishingFlag kFlag);

    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput,
                                      const hkpCdBody& kFirst,
                                      const hkpCdBody& kSecond,
                                      const hkpShapeContainer& kContainer,
                                      hkpShapeKey uKey) const = 0;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput,
                                      const hkpCdBody& kCollectionBodyA,
                                      const hkpCdBody& kCollectionBodyB,
                                      const hkpShapeContainer& kContainerShapeA,
                                      const hkpShapeContainer& kContainerShapeB,
                                      hkpShapeKey uKeyA,
                                      hkpShapeKey uKeyB) const = 0;

    unsigned int m_prepad0;
    unsigned int m_prepad1;
    unsigned int m_type;


};
