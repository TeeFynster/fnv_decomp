#pragma once

#include "NiDX9OnscreenBufferData.h"

// vftable 0x010ef06c, allocated with 0x5c bytes (0x00e7d6b0): the device's own
// back buffer. Overrides GetRTTI (0x00e7d550), CanDisplayFrame (0x00b606e0, true),
// DisplayFrame (0x00e7ccd0, Presents through m_pkD3DDevice9), Recreate (0x00e7d0a0)
// and ReleaseReferences (0x00e7d560); scalar deleting destructor 0x00e7d690.
class NiDX9ImplicitBufferData : public NiDX9OnscreenBufferData
{
public:
    NiDX9ImplicitBufferData() throw() : m_pkD3DDevice9(0)
    {
    }
    virtual ~NiDX9ImplicitBufferData();
    virtual const NiRTTI* GetRTTI() const;
    virtual bool CanDisplayFrame();
    virtual bool DisplayFrame();
    virtual bool Recreate(IDirect3DDevice9* pkD3DDevice9);
    virtual void ReleaseReferences();

    // 0x00e7d6b0
    static NiDX9ImplicitBufferData* __cdecl Create(IDirect3DDevice9* pkD3DDevice9,
                                                   const D3DPRESENT_PARAMETERS& kD3DPresentParams,
                                                   Ni2DBuffer*& pkBuffer);

    IDirect3DDevice9* m_pkD3DDevice9;  // 0x58
};
