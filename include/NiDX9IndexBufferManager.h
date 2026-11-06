#pragma once
#include "NiRefObject.h"

class IDirect3DDevice9Like;
class IDirect3DIndexBuffer9Like;

class NiDX9IndexBufferManager : public NiRefObject
{
public:
    virtual ~NiDX9IndexBufferManager();

    IDirect3DIndexBuffer9Like* CreateIndexBuffer(unsigned int uiLength, unsigned int uiUsage,
        int eFormat, int ePool, void* pkDesc);
    IDirect3DIndexBuffer9Like* ResizeTempLineConnectivityIB(unsigned int uiVertexCount,
        const unsigned char* pucConnect, unsigned int* puiIndexCount,
        unsigned int uiUsage, int ePool);
    IDirect3DIndexBuffer9Like* ResizeTemp(unsigned int uiSize, unsigned int uiUsage, int ePool);
    static bool PackBuffer(IDirect3DIndexBuffer9Like* pkIB, unsigned int uiSize,
        unsigned int uiVertexCount, const unsigned char* pucConnect,
        unsigned int* puiIndexCount);

    IDirect3DDevice9Like* m_pDirect3DDevice;
    int m_unk0c;
    int m_unk10;
    IDirect3DIndexBuffer9Like* m_pkTempLineConnectivityIB;
    unsigned int m_uiTempLineConnectivityIBSize;
};
