#pragma once

#include "NiObject.h"

class NiSkinPartition : public NiObject
{
public:
    class Partition
    {
    public:
        virtual ~Partition();
        unsigned short* m_pusBonePalette;
        float* m_pfVertexWeights;
        unsigned short* m_pusSourceVertexIndices;
        unsigned char* m_pucBoneIndices;
        unsigned short* m_pusTriList;
        unsigned short* m_pusStripLengths;
        unsigned short m_usVertices;
        unsigned short m_usTriangles;
        unsigned short m_usBoneCount;
        unsigned short m_usStrips;
        unsigned short m_usWeightsPerVertex;
        void* m_pkGeometryRendererData;

        unsigned int GetStripIndexCount();
    };
};
