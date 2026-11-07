#pragma once

#include "NiDX9TextureData.h"

class NiPixelFormatStandIn;
class NiDX9RendererStandIn;
class TextureSurface;
class DynamicTextureStandIn;

class NiDX9DynamicTextureData : public NiDX9TextureData
{
public:
    virtual ~NiDX9DynamicTextureData();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual int GetTexture_00e902d0();
    virtual char IsTextureLocked();
    virtual void SetTextureLocked(bool v);

    const NiPixelFormatStandIn* CreateSurf_00e90340(DynamicTextureStandIn* pkTexture, bool bDynamic);

    NiDX9RendererStandIn* m_pOwnerShader;
    TextureSurface* m_pkCubeMapTexture;
    unsigned int m_uiTextureFormat;
    TextureSurface* m_pkSysMemTexture;
    bool unk70;
    unsigned char unk71[3];
};
