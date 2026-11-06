#pragma once

#include "hkaAnimation.h"
#include "FinishingFlag.h"

class hkxVertexDescriptionElementDecl;

class hkxVertexDescription
{
public:
    enum DataType
    {
        HKX_DT_NONE = 0,
        HKX_DT_UINT8 = 1,
        HKX_DT_INT16 = 2,
        HKX_DT_UINT32 = 3,
        HKX_DT_FLOAT = 4,
        HKX_DT_FLOAT2 = 5,
        HKX_DT_FLOAT3 = 6,
        HKX_DT_FLOAT4 = 7
    };

    enum DataUsage
    {
        HKX_DU_NONE = 0,
        HKX_DU_POSITION = 1,
        HKX_DU_COLOR = 2,
        HKX_DU_NORMAL = 4,
        HKX_DU_TANGENT = 8,
        HKX_DU_BINORMAL = 16,
        HKX_DU_TEXCOORD = 32,
        HKX_DU_BLENDWEIGHTS = 64,
        HKX_DU_BLENDINDICES = 128,
        HKX_DU_USERDATA = 256
    };

    hkArray<hkxVertexDescriptionElementDecl> m_kElementDeclarations;

    hkxVertexDescription(FinishingFlag flag) throw();
    bool Equals(const hkxVertexDescription& other) const throw();
    bool operator==(const hkxVertexDescription& other) const;
    const hkxVertexDescriptionElementDecl* getElementDecl(DataUsage usage, int usageIndex) const;
    void clear();
    hkxVertexDescriptionElementDecl& AllocatePair();
};
