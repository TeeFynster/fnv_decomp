#pragma once

#include "NiDX9DepthStencilBufferData.h"

class NiDepthStencilBuffer;

// vftable 0x010ef114 (GetRTTI 0x00e7d680, Recreate 0x00e7ce30), allocated with
// 0x20 bytes (0x00e7d850): wraps the device's own depth-stencil surface
// (GetDepthStencilSurface). Adds no members; its scalar deleting destructor is
// the one NiDX92DBufferData's vftable uses (0x00e7d620).
class NiDX9ImplicitDepthStencilBufferData : public NiDX9DepthStencilBufferData
{
public:
    NiDX9ImplicitDepthStencilBufferData() throw()
    {
    }
    virtual ~NiDX9ImplicitDepthStencilBufferData();
    virtual const NiRTTI* GetRTTI() const;
    virtual bool Recreate(IDirect3DDevice9* pkD3DDevice9);

    // 0x00e7d850
    static NiDX9ImplicitDepthStencilBufferData* __cdecl Create(IDirect3DDevice9* pkD3DDevice9,
                                                               NiDepthStencilBuffer*& pkBuffer);
};
