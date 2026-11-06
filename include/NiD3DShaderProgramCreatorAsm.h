#pragma once

#include "NiD3DShaderProgramCreator.h"

class GeometryRelatedType;

class NiD3DShaderProgramCreatorAsm : public NiD3DShaderProgramCreator
{
public:
    virtual ~NiD3DShaderProgramCreatorAsm();
    using NiD3DShaderProgramCreator::Recreate;
    virtual bool Recreate(NiD3DPixelShader* pkPixelShader);
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();

    void* CreateHandle(GeometryRelatedType* pkShader);
};
