#pragma once

#include "NiMemObject.h"

class ShaderArg;
class NiD3DVertexShader;
class NiD3DPixelShader;

class NiD3DShaderProgramCreator : public NiMemObject
{
public:
    virtual ~NiD3DShaderProgramCreator();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual ShaderArg* CreateShader(const char* p0, const char* p1, const char* p3,
                                    unsigned int p4, unsigned int p5, unsigned int p6,
                                    unsigned int p7, unsigned int p8, unsigned int p9);
    virtual void vf05();
    virtual void vf06();
    virtual bool Recreate(NiD3DPixelShader* pkPixelShader);
    virtual bool Recreate(NiD3DVertexShader* pkVertexShader);

    void* __thiscall FUN_00e91be0(unsigned int);
};
