#pragma once

#include "NiDX92DBufferData.h"

// The D3D9 SDK's presentation parameters (d3d9types.h), 0x38 bytes.
struct _D3DPRESENT_PARAMETERS_
{
    unsigned int BackBufferWidth;
    unsigned int BackBufferHeight;
    int BackBufferFormat;
    unsigned int BackBufferCount;
    int MultiSampleType;
    unsigned long MultiSampleQuality;
    int SwapEffect;
    void* hDeviceWindow;
    int Windowed;
    int EnableAutoDepthStencil;
    int AutoDepthStencilFormat;
    unsigned long Flags;
    unsigned int FullScreen_RefreshRateInHz;
    unsigned int PresentationInterval;
};
typedef _D3DPRESENT_PARAMETERS_ D3DPRESENT_PARAMETERS;

// Abstract base of the DX9 on-screen renderer data (RTTI: derives from
// NiDX92DBufferData; no vftable of its own is emitted). Adds the presentation
// parameters at 0x20: NiDX9ImplicitBufferData (0x5c bytes) keeps its device at 0x58.
class NiDX9OnscreenBufferData : public NiDX92DBufferData
{
public:
    NiDX9OnscreenBufferData() throw()
    {
    }
    virtual bool Recreate(IDirect3DDevice9* pkD3DDevice9) = 0;

    D3DPRESENT_PARAMETERS m_kD3DPresentParams;  // 0x20
};
