#pragma once

#include "NiRefObject.h"
#include "NiFixedString.h"

enum NiGPUProgram__ProgramType
{
    NiGPUProgram__ProgramType_PROGRAM_VERTEX = 0,
    NiGPUProgram__ProgramType_PROGRAM_VERTEX_CLIPPING_PLANES = 1,
    NiGPUProgram__ProgramType_PROGRAM_PIXEL = 2,
    NiGPUProgram__ProgramType_PROGRAM_MAX = 3
};

class NiShaderConstantMap : public NiRefObject
{
public:
    class ShaderConstantMapEntry
    {
    public:
        unsigned int m_uiConstantID;
        NiFixedString m_kConstantName;

        ShaderConstantMapEntry();
        ShaderConstantMapEntry(unsigned int id, const NiFixedString& name);
        ~ShaderConstantMapEntry();
        ShaderConstantMapEntry& operator=(const ShaderConstantMapEntry& other);
        static void* operator new[](unsigned int size) throw();
    };

    virtual ~NiShaderConstantMap();
    virtual unsigned int SetConstant(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                                     const char*, unsigned int, unsigned int, const void*, bool);
    virtual unsigned int vf03(const char*, unsigned int, unsigned int, const char*);
    virtual unsigned int vf04(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                              const char*, unsigned int, unsigned int, const void*, bool);
    virtual unsigned int vf05(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                              const char*, unsigned int, unsigned int, const void*, bool);
    virtual unsigned int vf06(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                              const char*, unsigned int, unsigned int, const void*, bool);
    virtual unsigned int vf07(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*);
    virtual unsigned int vf08(const char*, unsigned int, const char*, unsigned int, int);
    virtual void vf09();

    static void InitializePoint3();
    static bool ParseConstantName(const char*, char*, unsigned int, unsigned int&);
    static bool FindConstantMapping(const char*, unsigned int&, unsigned int&);
    static ShaderConstantMapEntry* ms_pkShaderConstantMap;
    static unsigned int ms_uiShaderConstantMapEntryCount;
    static ShaderConstantMapEntry* ms_pkConstantMap;
    static unsigned int ms_uiConstantMapEntryCount;

    NiGPUProgram__ProgramType m_iProgramType;
};
