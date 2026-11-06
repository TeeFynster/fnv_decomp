#pragma once

#include "NiDX92DBufferData.h"

// Abstract base of the DX9 depth-stencil renderer data (RTTI: derives from
// NiDX92DBufferData). The original emits no vftable of its own, so its virtuals
// are read off its two subclasses (0x010ef114 implicit, 0x010ef184 additional):
// both replace NiDX92DBufferData's SetDepthTarget (slot 24) with 0x00e7cdb0 (makes
// m_pkSurface the device's depth-stencil target); GetRTTI (slot 3) and Recreate
// (slot 22) differ per subclass. Adds no members: the implicit subclass is
// allocated with 0x20 bytes, the size of NiDX92DBufferData.
class NiDX9DepthStencilBufferData : public NiDX92DBufferData
{
public:
    NiDX9DepthStencilBufferData() throw()
    {
    }
    virtual ~NiDX9DepthStencilBufferData();
    virtual bool SetDepthTarget(IDirect3DDevice9* pkD3DDevice9);
};
