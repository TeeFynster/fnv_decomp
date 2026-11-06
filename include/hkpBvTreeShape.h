#pragma once

#include "hkpShape.h"

#include "hkArray.h"

typedef unsigned char hkUint8;
typedef unsigned int hkpShapeKey;

class hkpBvTreeShape : public hkpShape
{
public:
    static const ClassMemberDescriptor Members[];

    enum BvTreeType
    {
        BVTREE_MOPP,
        BVTREE_TRISAMPLED_HEIGHTFIELD,
        BVTREE_USER,
        BVTREE_MAX
    };

    virtual void GetObbHits(const hkTransform& obbTransform, const hkVector4& obbExtent,
                            hkReal tolerance, hkArray<hkpShapeKey>& hits) const = 0;
    virtual void GetAabbHits(const hkAabb& aabb, hkArray<hkpShapeKey>& hits) const = 0;
    virtual hkUint32 GetAabbHitsToBuffer(const hkAabb& aabb, hkpShapeKey* hits,
                                        int maxNumKeys) const = 0;

    hkUint32 GetAabbHits(const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys) const;

    hkEnum<BvTreeType, hkUint8> m_uiUserData;
};
