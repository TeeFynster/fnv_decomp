#pragma once

#include "NiDX9DepthStencilBufferData.h"

class DepthDevice;
class Ni2DBuffer;
class NiPixelFormat;

// vftable 0x010ef184 (GetRTTI 0x00e7d9c0, Recreate 0x00e7cf50), allocated with
// 0x28 bytes (0x00e7d9d0). The constructor (0x00e7d940) is out of line: it also
// links the object into a global list under a critical section.
class NiDX9AdditionalDepthStencilBufferData : public NiDX9DepthStencilBufferData
{
public:
    NiDX9AdditionalDepthStencilBufferData() throw();
    virtual ~NiDX9AdditionalDepthStencilBufferData();
    virtual const NiRTTI* GetRTTI() const;
    virtual bool Recreate(IDirect3DDevice9* pkD3DDevice9);

    static NiDX9AdditionalDepthStencilBufferData* __cdecl Create(
        DepthDevice*, Ni2DBuffer**, const NiPixelFormat*, unsigned int);

    unsigned int m_eCreateFormat;  // 0x20, the D3DFORMAT the surface is created with
    // 0x24, the Discard argument of CreateDepthStencilSurface (0x00e7d9d0 copies a
    // global flag into it; Recreate 0x00e7cf50 passes it again).
    unsigned int m_bDiscard;
};
