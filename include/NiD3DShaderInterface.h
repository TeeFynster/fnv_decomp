#pragma once

#include "NiShader.h"

class Direct3DDeviceInterface;
class GraphicsRenderer;
class ShaderPassRenderer;
class NiD3DShaderDeclaration;

class NiD3DShaderInterface : public NiShader
{
  public:
    NiD3DShaderInterface() throw();
    virtual ~NiD3DShaderInterface();
    virtual bool Initialize();

    virtual NiD3DShaderDeclaration* SelectVertexDeclaration();
    virtual void UseShaderDeclaration(NiD3DShaderDeclaration* pkShaderDecl);
    virtual void HandleResetDevice(void* pkShaderDecl);
    virtual void HandleLostDevice();
    virtual void UnloadShader();
    virtual bool BuildVertexShader();
    virtual bool IsShaderAvailable();
    virtual bool CanRenderGeometry();
    virtual bool IsShaderSupported();
    virtual bool IsShaderValid();
    virtual bool IsShaderEnabled();
    virtual void SetIsBest(bool bIsBest);

    bool IsExactKindOf(const NiRTTI* type);
    bool IsDefault();
    void SetShaderObject(GraphicsRenderer* renderer);
    static unsigned int InitializeShaderRenderer(GraphicsRenderer* renderer);

    Direct3DDeviceInterface* m_pkD3DDevice;
    GraphicsRenderer* m_pkD3DRenderer;
    ShaderPassRenderer* m_pkD3DRenderState;
    bool m_bIsBestImplementation;
    unsigned char _pad21[3];
};
