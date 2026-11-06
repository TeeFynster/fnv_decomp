#pragma once

#include "NiRefObject.h"

class NiGPUProgram : public NiRefObject
{
  public:
    enum ProgramType  // values: Xbox PDB NiGPUProgram::ProgramType
    {
        PROGRAM_VERTEX = 0,
        PROGRAM_VERTEX_CLIPPING_PLANES = 1,
        PROGRAM_PIXEL = 2,
        PROGRAM_MAX = 3
    };

    bool IsExactKindOf(void*);
    static bool IsExactKindOf(void*, void*);
    bool IsKindOfType(void*);
    static bool IsKindOfType(void*, void*);
    NiGPUProgram* DynamicCast(void*);
    static NiGPUProgram* DynamicCast(void*, void*);
    ProgramType GetProgramType();
    void SetString(void*) throw();
    void IncRefCount() throw();
    void DecRefCount() throw();

    ProgramType m_iProgramType;
};
