#pragma once

#include "hkpCollisionFilter.h"
#include "hkVector4.h"

class hkpGroupFilter : public hkpCollisionFilter
{
public:
    enum { USE_COLLIDABLE_FILTER_INFO = 0xffffffff };

    static const ClassMemberDescriptor Members[];

    hkpGroupFilter();
    hkpGroupFilter(FinishingFlag kFlag);

    virtual void vf03();

    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput,
                                      const hkpCdBody& kFirst,
                                      const hkpCdBody& kSecond,
                                      const hkpShapeContainer& kContainer,
                                      hkpShapeKey uKey) const;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput,
                                      const hkpCdBody& kCollectionBodyA,
                                      const hkpCdBody& kCollectionBodyB,
                                      const hkpShapeContainer& kContainerShapeA,
                                      const hkpShapeContainer& kContainerShapeB,
                                      hkpShapeKey uKeyA,
                                      hkpShapeKey uKeyB) const;

    hkBool ShouldCollide(unsigned int uInfoA, unsigned int uInfoB);
    hkBool ShouldCollide(unsigned int uInfoA, unsigned int uInfoB) const throw();
    void ClearMaskedBits(unsigned int uMaskA, unsigned int uMaskB);
    void DisableCollisionPair(int iLayerA, int iLayerB);
    void hkpGroupFilter_enableCollisionsUsingBitfield(unsigned int uInfoA, unsigned int uInfoB);

    __declspec(align(16)) int m_iNextFreeSystemGroup;
    unsigned int m_uiCollisionGroupMasks[32];
    char padB4[0xC];
    hkVector4 m_kCollisionGroupMaskVectors[4];
};
