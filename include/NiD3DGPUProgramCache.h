#pragma once

#include "NiGPUProgramCache.h"

class NiD3DGPUProgramCache : public NiGPUProgramCache
{
public:
    virtual ~NiD3DGPUProgramCache();
    virtual void vf38();

    static const char* GetVertexShaderProfile();
    static const char* GetPixelShaderProfile(bool usePixelLevel);
};
