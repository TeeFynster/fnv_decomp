#pragma once
#include "NiRefObject.h"

class NiD3DShaderConstantManager : public NiRefObject
{
public:
    virtual ~NiD3DShaderConstantManager();
    virtual void vf02();

    void* __thiscall Destroy(unsigned int flags);
};
