#pragma once

#include "NiGeometryData.h"

class NiGeometryGroup;
class COMUnknownInterface;
class COMBaseInterface;
class NiVBChip;

class NiGeometryBufferData : public NiGeometryData::RendererData
{
public:
    NiGeometryBufferData();
    virtual ~NiGeometryBufferData();
    virtual bool IsKindEnabled(int kind);

    void ReleaseBuffers();

    unsigned int m_uiValue1;
    NiGeometryGroup* m_pkOwnerGroup;
    unsigned int m_uiGroupIndex;
    COMUnknownInterface* m_pkVertexDeclaration;
    bool m_bIsInitialized;
    unsigned int m_uiVertexCount;
    unsigned int m_uiVertexDataSize;
    unsigned int m_uiRegisterStreamCount;
    unsigned int* m_puiVertexStrides;
    NiVBChip** m_ppkVertexBuffers;
    unsigned int m_uiStartIndex;
    unsigned int m_uiPrimitiveCount;
    COMBaseInterface* m_pkIndexBuffer;
    unsigned int m_uiBufferSize;
    unsigned int m_eRequestType;
    unsigned int m_uiIndexArrayCount;
    unsigned int m_uiMinimumIndex;
    unsigned int m_uiMaximumIndex;
    const unsigned short* m_pusIndexData;
    const unsigned short* m_pusIndexArray;
};
