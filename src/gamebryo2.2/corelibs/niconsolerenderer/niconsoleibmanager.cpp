// gamebryo2.2/corelibs/niconsolerenderer/niconsoleibmanager.cpp: IndexBufferManager (1 function)

#include "../../../../include/NiD3DDefaultShader.h"
#include "niconsoleibmanager_decls.h"

// Reuses or creates a D3D index buffer matching the requested format/usage/pool/size, copies the indices into it, and returns the buffer.
// @fnv 0x00e8f200
COMBaseInterface* IndexBufferManager::PackBuffer(const unsigned short* pusIndices, unsigned int uiIndexCount,
                                                 unsigned int uiMaxIndexCount, COMBaseInterface* pkIB,
                                                 unsigned int& uiBufferSize, unsigned long ulPool, unsigned int uiUsage)
{
    if (!m_pDirect3DDevice)
        return 0;
    if (!pusIndices)
        return 0;

    unsigned int uiMaxBufferSize = uiMaxIndexCount * sizeof(unsigned short);
    unsigned int uiSize = uiIndexCount * sizeof(unsigned short);
    bool bCreateBuffer = true;
    if (pkIB)
    {
        _D3DINDEXBUFFER_DESC kDesc;
        memset(&kDesc, 0, sizeof(kDesc));
        if (pkIB->GetDesc(&kDesc) >= 0 && kDesc.Format == 101 && kDesc.Type == 7 && kDesc.Usage == uiUsage &&
            kDesc.Pool == ulPool && kDesc.Size >= uiMaxBufferSize)
            bCreateBuffer = false;
    }
    if (bCreateBuffer)
    {
        COMBaseInterface* pkNewIB = 0;
        if (m_pDirect3DDevice->CreateIndexBuffer(uiMaxBufferSize, uiUsage, 101, ulPool, &pkNewIB, 0) < 0)
        {
            NiD3DDefaultShader::SetShaderName("NiDX9IndexBufferManager::CreateIndexBuffer FAILED");
            pkNewIB = 0;
        }
        pkIB = pkNewIB;
        if (!pkIB)
        {
            NiD3DDefaultShader::SetShaderName("NiDX9IndexBufferManager::PackBuffer> Failed to create index buffer\n");
            return 0;
        }
        uiBufferSize = uiMaxBufferSize;
    }
    if (uiSize > 0)
    {
        void* pvLockedData = 0;
        if (pkIB->Lock(0, uiSize, &pvLockedData, 0) >= 0)
        {
            fnv_zlib_memcpy(pvLockedData, pusIndices, uiSize);
            pkIB->Unlock();
        }
        else
        {
            NiD3DDefaultShader::SetShaderName("NiDX9IndexBufferManager::PackBuffer> Failed to lock index buffer\n");
            pkIB->Unlock();
            pkIB->Release();
        }
    }
    return pkIB;
}
