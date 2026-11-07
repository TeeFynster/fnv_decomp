#pragma once

#include "hkReferencedObject.h"
#include "hkaSkeletonMapperData.h"

class hkaSkeletonMapper : public hkReferencedObject
{
public:
    enum ConstraintSource
    {
        NO_CONSTRAINTS = 0,
        REFERENCE_POSE = 1,
        CURRENT_POSE = 2
    };

    void __cdecl mapPose(const hkQsTransform* poseAModelSpace, const hkQsTransform* originalPoseBLocalSpace, hkQsTransform* poseBModelSpace, int source) const;

    char pad8[0x8];
    hkaSkeletonMapperData m_kMappingData;
};
