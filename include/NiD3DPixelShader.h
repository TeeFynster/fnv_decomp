#pragma once

#include "NiD3DShaderProgram.h"

class GeometryRelatedType;
class NiD3DRenderer;

class NiD3DPixelShader : public NiD3DShaderProgram
{
public:

    NiD3DPixelShader(NiD3DRenderer* pkRenderer);
    NiD3DPixelShader(GraphicsRenderer* renderer);

    virtual ~NiD3DPixelShader();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
    virtual bool SetShaderConstant(NiShaderConstantMapEntry*, void*, unsigned int);
    virtual bool SetShaderConstantArray(NiShaderConstantMapEntry*, void*, unsigned int,
                                        unsigned int, unsigned short*);

    virtual GeometryRelatedType* GetD3DPixelShader();
    virtual void SetD3DPixelShader(GeometryRelatedType* pixelShader);
    virtual void UnloadShader();
    virtual void BuildVertexShader();

    void IncRefCount();
    void DecRefCount();
    void* __thiscall DestroyPixelShader(unsigned int flags);
    int CanRecreate();

    GeometryRelatedType* m_pD3DPixelShader;
};
