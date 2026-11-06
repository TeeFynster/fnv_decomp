#pragma once

#include "NiRefObject.h"
#include "NiTPointerList.h"

class NiD3DShaderProgramCreator;
struct ShaderBufferRecord;
template <class TVAL> class NiTStringPointerMap;

class NiD3DShaderProgramFactory : public NiRefObject
{
public:
    NiTPointerList<char*> m_kDirectoryList;
    NiTStringPointerMap<ShaderBufferRecord*>* m_pVertexShaderMap;
    union
    {
        NiTStringPointerMap<ShaderBufferRecord*>* m_pPixelShaderMap;
        NiTStringPointerMap<ShaderBufferRecord*>* m_pShaderBufferMap;
    };

    char* GetFirstName(void**);
    const char* GetNextName(void*&);
    void AddDirectory(const char* pacDirectory);
    void LoadProgramByName(const char*);
    void RemoveDirectoryEntry(const char* pcDirectory);
    ShaderBufferRecord* __thiscall FindVertexShader(const char* pcShaderName);
    ShaderBufferRecord* __thiscall FindPixelShader(const char* pcShaderName);

    static bool __cdecl RegisterCreator(const char*, NiD3DShaderProgramCreator*);
    static void CreateFactoryInstance();
};
