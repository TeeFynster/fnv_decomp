#pragma once

#include "NiD3DVertexShader.h"

class ID3DXConstantTable;

class NiD3DHLSLVertexShader : public NiD3DVertexShader
{
public:
    NiD3DHLSLVertexShader(GraphicsRenderer* pkRenderer);
    NiD3DHLSLVertexShader(void* pkRenderer);
    virtual ~NiD3DHLSLVertexShader();

    virtual const char* GetEntryPoint();
    virtual void vf42(const char* pcEntryPoint);
    virtual int vf43();
    virtual void vf44(const char* pcShaderTarget);
    virtual int vf45();
    virtual void SetShaderTable(ID3DXConstantTable* pkTable);

    using NiD3DVertexShader::SetSoftwareVertexProcessing;

    void SetSoftwareVP(unsigned int bSoftwareVP);
    const char* GetConstantName(unsigned int uiIndex);
    void __thiscall SetEntryPoint_00e95e20(const char* pcEntryPoint);
    void __thiscall SetShaderTarget_00e95e80(const char* pcShaderTarget);
    void __thiscall SetVtableAndProcessState_00e971d0();
    void* __thiscall DestroyVertexShader(unsigned int flags);

    char* m_pcShaderEntryPoint;
    char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};
