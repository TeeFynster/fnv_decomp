
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ID3DXBuffer
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void* __stdcall GetBufferPointer() = 0;
    virtual unsigned long __stdcall GetBufferSize() = 0;
};

extern "C" long __stdcall D3DXAssembleShaderFromFileA(const char* pSrcFile, const void* pDefines, void* pInclude,
                                                      unsigned long Flags, ID3DXBuffer** ppShader,
                                                      ID3DXBuffer** ppErrorMsgs);

bool ResolveShaderPath(const char* pcName, char* pcPath, unsigned int uiSize);
int ShaderLog(int iLevel, int aiMemoryContext, const char* pcFormat, ...);
void* NiMalloc(unsigned int uiSize);
void NiFree(void* pvMem);
int strcpy_s(char* dst, unsigned int size, char* src);
void* memcpy(void* dst, const void* src, unsigned int size);

extern unsigned int g_uiShaderAssembleFlags;
inline void NiMemcpy(void* d, const void* s, unsigned int n)
{
    memcpy(d, s, n);
}

struct ShaderLoader
{
    void* m_vtbl;
    unsigned int m_uiValue1;

    bool AssembleShaderFile(const char* pcFile, void** ppvData, unsigned int* puiSize, int* piUnk0, int* piUnk1,
                            int pcContext);
};

// Resolves the shader path, assembles it with D3DXAssembleShaderFromFileA, copies the bytecode into a NiMalloc buffer, and logs errors on failure.
// @fnv 0x00e97ea0
bool ShaderLoader::AssembleShaderFile(const char* pcFile, void** ppvBytecode, unsigned int* puiBytecodeSize,
                                      int* piUnk0, int* piUnk1, int pcLogContext)
{
    *ppvBytecode = 0;
    *puiBytecodeSize = 0;
    *piUnk0 = 0;
    *piUnk1 = 0;

    if (pcFile && *pcFile)
    {
        ID3DXBuffer* pkErrors;
        ID3DXBuffer* pkShader;
        char acPath[260];
        if (!ResolveShaderPath(pcFile, acPath, 260))
        {
            ShaderLog(1, pcLogContext, "Failed to find shader program file %s\n", pcFile);
            return false;
        }

        unsigned int uiAssembleFlags = (m_uiValue1 | g_uiShaderAssembleFlags) & 3;
        if (D3DXAssembleShaderFromFileA(acPath, 0, 0, uiAssembleFlags, &pkShader, &pkErrors) < 0)
        {
            char* pcErrorText = 0;
            if (pkErrors)
            {
                char* pcErrorMsg = (char*)pkErrors->GetBufferPointer();
                if (pcErrorMsg)
                {
                    unsigned int uiErrorLen = pkErrors->GetBufferSize();
                    pcErrorText = (char*)NiMalloc(uiErrorLen);
                    strcpy_s(pcErrorText, uiErrorLen, pcErrorMsg);
                    ShaderLog(1, pcLogContext, "Failed to assemble shader %s\nError: %s\n", pcFile, pcErrorText);
                }
                pkErrors->Release();
            }
            else
            {
                ShaderLog(1, pcLogContext, "Failed to assemble shader %s\nError: NONE REPORTED\n", pcFile);
            }
            NiFree(pcErrorText);
            if (pkShader)
                pkShader->Release();
            return false;
        }

        *puiBytecodeSize = pkShader->GetBufferSize();
        *ppvBytecode = NiMalloc(*puiBytecodeSize);
        NiMemcpy(*ppvBytecode, pkShader->GetBufferPointer(), *puiBytecodeSize);
        pkShader->Release();
        if (pkErrors)
            pkErrors->Release();
        return true;
    }

    ShaderLog(1, 0, "Invalid shader file name\n");
    return false;
}

extern "C" long __stdcall D3DXAssembleShader_00ee6e52(const char*, unsigned int, const void*, void*, unsigned int, ID3DXBuffer**,
                                       ID3DXBuffer**);
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);

inline void Move266(void* d, const void* s, unsigned int n)
{
    memmove(d, s, n);
}

struct FUN_00e98080_shell
{
    void* vtable;
    unsigned int flags;

    bool NiD3DShaderProgramCreatorAsm_LoadShaderCodeFromBuffer(const char*, unsigned int, void**, unsigned int*, void**, unsigned int*, int);
};

// Assembles source, logs failures, and copies successful output into a newly allocated buffer returned through data.
// @fnv 0x00e98080
// src: COMMUNITY 0x00e98080
bool FUN_00e98080_shell::NiD3DShaderProgramCreatorAsm_LoadShaderCodeFromBuffer(const char* source, unsigned int length, void** ppBytecode,
                                      unsigned int* puiBytecodeSize, void** reserved, unsigned int* reservedSize,
                                      int context)
{
    void** const volatile& originalData = ppBytecode;
    void** dataOut = originalData;
    unsigned int* sizeOut = puiBytecodeSize;
    *dataOut = 0;
    *sizeOut = 0;
    *reserved = 0;
    *reservedSize = 0;

    if (!source || !length)
        goto invalid;

    {
        unsigned int options = (flags | g_uiShaderAssembleFlags) & 3;
        long status =
            D3DXAssembleShader_00ee6e52(source, length, 0, 0, options, (ID3DXBuffer**)&ppBytecode, (ID3DXBuffer**)&puiBytecodeSize);
        if (status < 0)
        {
            char* pszError = 0;
            ID3DXBuffer* error = (ID3DXBuffer*)puiBytecodeSize;
            if (error)
            {
                char* text = (char*)error->GetBufferPointer();
                if (text)
                {
                    unsigned int n = ((ID3DXBuffer*)puiBytecodeSize)->GetBufferSize();
                    pszError = (char*)NiMalloc(n);
                    strcpy_s(pszError, n, text);
                    ShaderLog(1, context, "Failed to assemble shader from memory\nError: %s\n", pszError);
                }
                ((ID3DXBuffer*)puiBytecodeSize)->Release();
            }
            else
            {
                ShaderLog(1, context, "Failed to assemble shader from memory\nError: NONE REPORTED\n");
            }
            NiFree(pszError);
            if (ppBytecode)
                ((ID3DXBuffer*)ppBytecode)->Release();
            return false;
        }

        *sizeOut = ((ID3DXBuffer*)ppBytecode)->GetBufferSize();
        *dataOut = NiMalloc(*sizeOut);
        Move266(*dataOut, ((ID3DXBuffer*)ppBytecode)->GetBufferPointer(), *sizeOut);
        ((ID3DXBuffer*)ppBytecode)->Release();
        if (puiBytecodeSize)
            ((ID3DXBuffer*)puiBytecodeSize)->Release();
        return true;
    }

invalid:
    ShaderLog(1, context, "Invalid shader buffer\n");
    return false;
}
