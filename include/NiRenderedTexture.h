#pragma once

#include <windows.h>
#include <d3d9.h>
#include "NiTexture.h"
#include "Ni2DBuffer.h"
#include "NiAVObject.h"

class NiRenderer;

class NiRenderedTexture : public NiTexture
{
  public:
    NiRenderedTexture() throw();
    virtual ~NiRenderedTexture();
    virtual int vf41();

    void vfn_0();
    void vfn_4();
    NiRTTI* GetType();
    bool IsExactKindOf(const NiRTTI* type);

    static NiRenderedTexture* Create(const NiFixedString&, unsigned int, unsigned int, NiRenderer*,
                                     NiTexture::TextureFormatPreferences&, Ni2DBuffer::MultiSamplePreference,
                                     NiRenderedTexture*, unsigned int);

    NiPointer<Ni2DBuffer> m_spRenderTargetBuffer;
    unsigned int m_uiAliasOffset;
    NiRenderedTexture* m_pReuseTexture;
    Ni2DBuffer::MultiSamplePreference m_eMultiSamplePreference;
    bool m_bUseMipMaps;
    bool m_bUseDepthBuffer;
    _D3DFORMAT m_ePixelFormat;

    static bool ms_bUseMipMaps;
    static bool ms_bUseDepthBuffer;
    static _D3DFORMAT ms_eDepthStencilFormat;
};
