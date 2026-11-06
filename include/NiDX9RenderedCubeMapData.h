#pragma once

#include "NiDX9RenderedTextureData.h"

class NiTextureStub;
class NiPixelFormatStub;
class NiRenderedCubeMap;

class NiDX9RenderedCubeMapData : public NiDX9RenderedTextureData
{
public:
    virtual void Unk_26();
    virtual void* GetD3DTexture();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();

    void DeleteThis(int);
    NiPixelFormatStub* CreateSurface(NiRenderedCubeMap*);

    void* m_iWordAt04;
    NiTextureStub* m_pkTexture;
    unsigned int m_uiImageHeight;
    unsigned int m_uiImageWidth;
};
