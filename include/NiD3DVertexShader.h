#pragma once

#include "NiD3DShaderProgram.h"
#include "NiRTTI.h"

class RenderableGeometry;
class COMUnknownInterface;

class NiD3DVertexShader : public NiD3DShaderProgram
{
public:
    NiD3DVertexShader(GraphicsRenderer* pkRenderer);
    NiD3DVertexShader(void* pkRenderer);
    virtual ~NiD3DVertexShader();

    virtual void vf31();
    virtual void SetShaderUsage(unsigned int uiUsage);
    virtual int IsRecreated();
    virtual void SetD3DPixelShader(void* hShader);
    virtual COMUnknownInterface* GetShaderDeclaration() const;
    virtual void SetVertexDeclaration(void* hDecl);
    virtual void vf37();
    virtual void SetSoftwareVertexProcessing(bool bSoftwareVP);
    virtual void UnloadShader();
    virtual void BuildVertexShader();

    using NiD3DShaderProgram::GetRTTI;
    using NiD3DShaderProgram::SetName;
    using NiD3DShaderProgram::SetCreator;

    virtual const NiRTTI* GetRTTI() const;
    void SetFileName(const char* pcFileName);
    void SetD3DPixelShader(RenderableGeometry* hShader);
    NiD3DVertexShader* Construct(GraphicsRenderer* pkRenderer);
    void SetVertexDeclaration_00be0bd0(COMUnknownInterface* hDecl);
    void SetSoftwareVertexProcessing_00be0bf0(bool bSoftwareVP);
    void IncRefCount();
    void DecRefCount();

    static const NiRTTI ms_kRTTI;

    bool m_bIsInitialized;
    unsigned int m_uiShaderUsage;
    RenderableGeometry* m_pD3DPixelShader;
    COMUnknownInterface* m_pD3DVertexShader;
};
