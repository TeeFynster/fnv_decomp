#pragma once

#include "hkaSkeleton.h"
#include "hkBool.h"
#include "hkQsTransform.h"

class hkaSkeletonMapperDataSimpleMapping;
class hkaSkeletonMapperDataChainMapping;

typedef short hkInt16;

#pragma pack(push, 1)
class hkaSkeletonMapperData
{
public:
    enum MappingType
    {
        HK_RAGDOLL_MAPPING = 0,
        HK_RETARGETING_MAPPING = 1
    };

    hkaSkeleton* m_pSkeletonA;
    hkaSkeleton* m_pSkeletonB;
    hkArray<hkaSkeletonMapperDataSimpleMapping> m_kSimpleMappings;
    hkArray<hkaSkeletonMapperDataChainMapping> m_kChainMappings;
    hkArray<hkInt16> m_kUnmappedBones;
    char pad2C[0x4];
    hkQsTransform m_kExtractedMotionMapping;
    hkBool m_bKeepUnmappedLocal;
    char pad61[0x3];
    hkInt32 m_eMappingType;
    char pad68[0x8];
};
#pragma pack(pop)
