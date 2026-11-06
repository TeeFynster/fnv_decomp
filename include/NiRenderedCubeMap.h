#pragma once

#include "NiRenderedTexture.h"

class NiRenderedCubeMap : public NiRenderedTexture
{
  public:
    NiRenderedCubeMap() throw();
    virtual ~NiRenderedCubeMap();

    void __thiscall FUN_00ee82b0();

    static NiRenderedCubeMap* FUN_00ee8330(unsigned int uiFaceSize, NiRenderer* pkRenderer,
                                         NiTexture::TextureFormatPreferences& kPrefs);

    int unk48;
    void* m_ppCubeMapFaces[6];
};
