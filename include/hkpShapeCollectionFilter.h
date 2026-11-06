#pragma once

#include "hkBool.h"
#include "hkpShapeContainer.h"

class CollisionAgentContext;
class hkAabb;
class hkpBvTreeShape;
class hkpCdBody;
struct ClassMemberDescriptor;

class hkpShapeCollectionFilter
{
public:
    static const ClassMemberDescriptor Members[];

    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput,
                                      const hkpCdBody& kBodyA,
                                      const hkpCdBody& kCollectionBodyB,
                                      const hkpShapeContainer& kContainerShapeB,
                                      hkpShapeKey uKeyB) const = 0;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput,
                                      const hkpCdBody& kCollectionBodyA,
                                      const hkpCdBody& kCollectionBodyB,
                                      const hkpShapeContainer& kContainerShapeA,
                                      const hkpShapeContainer& kContainerShapeB,
                                      hkpShapeKey uKeyA, hkpShapeKey uKeyB) const = 0;
    virtual int FilterAabb(const CollisionAgentContext& kInput,
                           const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                           const hkpBvTreeShape* pTreeShapeB, hkAabb& kAabb,
                           hkpShapeKey* pShapeKeysInOut, int iShapeKeysCapacity) const = 0;
    virtual ~hkpShapeCollectionFilter();
};
