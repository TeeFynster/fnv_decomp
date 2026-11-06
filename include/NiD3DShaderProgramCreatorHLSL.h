#pragma once

#include "NiD3DShaderProgramCreator.h"

class ID3DXConstantTable;

class NiD3DShaderProgramCreatorHLSL : public NiD3DShaderProgramCreator
{
public:
    virtual ~NiD3DShaderProgramCreatorHLSL();
    virtual void vf09();
    virtual void vf10();

    void* Destroy(unsigned int flags);
    void SetCompileFlags(unsigned int uiFlags);
    bool CompileShaderFromMemory(const void* pvBuffer, unsigned int uiBufferSize,
                                 const char* pcEntryPoint, const char* pcShaderTarget,
                                 void*& pvCode, unsigned int& uiCodeSize,
                                 ID3DXConstantTable*& pkConstantTable, bool bRecoverable);

    unsigned int m_uiCompileFlags;
};
