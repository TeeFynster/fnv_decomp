// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct D3DXMACRO;
struct ID3DXInclude;
struct ID3DXBuffer;
struct ID3DXConstantTable;

extern "C" __declspec(dllimport) long __stdcall D3DXCompileShader(const char* pSrcData, unsigned int SrcDataLen,
                                                                  const D3DXMACRO* pDefines, ID3DXInclude* pInclude,
                                                                  const char* pFunctionName, const char* pProfile,
                                                                  unsigned long Flags, ID3DXBuffer** ppShader,
                                                                  ID3DXBuffer** ppErrorMsgs,
                                                                  ID3DXConstantTable** ppConstantTable);

// @fnv 0x00ee6e0a
// src: COMMUNITY 0x00ee6e0a
long __stdcall D3DXCompileShader_00ee6e0a(const char* pSrcData, unsigned int SrcDataLen, const D3DXMACRO* pDefines,
                            ID3DXInclude* pInclude, const char* pFunctionName, const char* pProfile,
                            unsigned long Flags, ID3DXBuffer** ppShader, ID3DXBuffer** ppErrorMsgs,
                            ID3DXConstantTable** ppConstantTable)
{
    return D3DXCompileShader(pSrcData, SrcDataLen, pDefines, pInclude, pFunctionName, pProfile, Flags, ppShader,
                             ppErrorMsgs, ppConstantTable);
}

extern "C" __declspec(dllimport) void __stdcall D3DXCreateVolumeTextureFromFileInMemory();
// @fnv 0x00ee6e10
// src: COMMUNITY 0x00ee6e10
void __cdecl D3DXCreateVolumeTextureFromFileInMemory_00ee6e10()
{
    D3DXCreateVolumeTextureFromFileInMemory();
}

__declspec(dllimport) long __stdcall D3DXCreateCubeTextureFromFileInMemory(void*, const void*, unsigned int, void**);
// @fnv 0x00ee6e16
// src: COMMUNITY 0x00ee6e16
long __stdcall D3DXCreateCubeTextureFromFileInMemory_00ee6e16(void* device, const void* data, unsigned int size, void** texture)
{
    return D3DXCreateCubeTextureFromFileInMemory(device, data, size, texture);
}

struct D3DXIMAGE_INFO;
extern "C" __declspec(dllimport) long __stdcall D3DXGetImageInfoFromFileInMemory(const void* source, unsigned int size,
                                                                                 D3DXIMAGE_INFO* info);
// @fnv 0x00ee6e22
// src: COMMUNITY 0x00ee6e22
long __stdcall D3DXGetImageInfoFromFileInMemory_00ee6e22(const void* source, unsigned int size, D3DXIMAGE_INFO* info)
{
    return D3DXGetImageInfoFromFileInMemory(source, size, info);
}

struct EE6E40ConstantTable;

extern "C" __declspec(dllimport) long __stdcall D3DXGetShaderConstantTable(const unsigned long* pFunction,
                                                                           EE6E40ConstantTable** ppConstantTable);

// @fnv 0x00ee6e40
// src: COMMUNITY 0x00ee6e40
long __stdcall D3DXGetShaderConstantTable_00ee6e40(const unsigned long* pFunction, EE6E40ConstantTable** ppConstantTable)
{
    return D3DXGetShaderConstantTable(pFunction, ppConstantTable);
}

struct D3DXMACRO;
struct ID3DXInclude;
struct ID3DXBuffer;
struct ID3DXConstantTable;

extern "C" __declspec(dllimport) long __stdcall D3DXCompileShaderFromFileA(
    const char* pSrcFile, const D3DXMACRO* pDefines, ID3DXInclude* pInclude, const char* pFunctionName,
    const char* pProfile, unsigned long Flags, ID3DXBuffer** ppShader, ID3DXBuffer** ppErrorMsgs,
    ID3DXConstantTable** ppConstantTable);

// @fnv 0x00ee6e46
// src: COMMUNITY 0x00ee6e46
long __stdcall D3DXCompileShaderFromFileA_00ee6e46(const char* pSrcFile, const D3DXMACRO* pDefines, ID3DXInclude* pInclude,
                            const char* pFunctionName, const char* pProfile, unsigned long Flags,
                            ID3DXBuffer** ppShader, ID3DXBuffer** ppErrorMsgs, ID3DXConstantTable** ppConstantTable)
{
    return D3DXCompileShaderFromFileA(pSrcFile, pDefines, pInclude, pFunctionName, pProfile, Flags, ppShader,
                                      ppErrorMsgs, ppConstantTable);
}

// FUN_00ee6e1c: probe of the stdcall tail-jump form (args forwarded in place).
extern "C" __declspec(dllimport) int __stdcall D3DXCreateTextureFromFileInMemory(void* pDevice, const void* pSrcData,
                                                                                 unsigned int SrcDataSize,
                                                                                 void** ppTexture);

// @fnv 0x00ee6e1c
// src: COMMUNITY 0x00ee6e1c
int __stdcall D3DXCreateTextureFromFileInMemory_00ee6e1c(void* pDevice, const void* pSrcData, unsigned int SrcDataSize, void** ppTexture)
{
    return D3DXCreateTextureFromFileInMemory(pDevice, pSrcData, SrcDataSize, ppTexture);
}

// FUN_00ee6e28: 6-byte 'jmp [IAT]' forwarder to d3dx9_38 D3DXGetPixelShaderProfile
// (stdcall, 2 args: LPDIRECT3DDEVICE9, D3DX_SHADER_TYPE) returning HRESULT.
extern "C" __declspec(dllimport) long __stdcall D3DXGetPixelShaderProfile(void* pDevice, int ShaderType);

// @fnv 0x00ee6e28
// src: COMMUNITY 0x00ee6e28
long __stdcall D3DXGetPixelShaderProfile_00ee6e28(void* pDevice, int ShaderType)
{
    return D3DXGetPixelShaderProfile(pDevice, ShaderType);
}

// FUN_00ee6e4c: 6-byte 'jmp [IAT]' forwarder to d3dx9_38 D3DXAssembleShaderFromFileA (stdcall, 6 args).
extern "C" __declspec(dllimport) long __stdcall D3DXAssembleShaderFromFileA(const char* pSrcFile, const void* pDefines,
                                                                            void* pInclude, unsigned int Flags,
                                                                            void** ppShader, void** ppErrorMsgs);

// @fnv 0x00ee6e4c
// src: COMMUNITY 0x00ee6e4c
long __stdcall D3DXAssembleShaderFromFileA_0(const char* pSrcFile, const void* pDefines, void* pInclude, unsigned int Flags,
                            void** ppShader, void** ppErrorMsgs)
{
    return D3DXAssembleShaderFromFileA(pSrcFile, pDefines, pInclude, Flags, ppShader, ppErrorMsgs);
}

extern "C" __declspec(dllimport) void __cdecl D3DXAssembleShader();

// @fnv 0x00ee6e52
// src: COMMUNITY 0x00ee6e52
void __cdecl D3DXAssembleShader_00ee6e52()
{
    D3DXAssembleShader();
}
