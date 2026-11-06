#pragma once

#include "NiShader.h"

class NiFragmentShaderInstanceDescriptor : public NiShader::NiShaderInstanceDescriptor
{
public:
    virtual void* vf00();
    virtual void* __thiscall vf16(unsigned int flags);

    void* __thiscall FUN_00e8d540(unsigned int flags);

    void* m_pDescriptorData;
};
