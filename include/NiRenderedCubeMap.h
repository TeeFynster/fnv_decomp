#pragma once

#include "NiRenderedTexture.h"

class NiRenderedCubeMap : public NiRenderedTexture
{
  public:
    NiRenderedCubeMap() throw();
    virtual ~NiRenderedCubeMap();

    void __thiscall ReleaseReference_00ee82b0();

    static NiRenderedCubeMap* Create_00ee8330(unsigned int uiFaceSize, NiRenderer* pkRenderer,
                                         NiTexture::TextureFormatPreferences& kPrefs);

    int unk48;
    void* m_ppCubeMapFaces[6];
};
