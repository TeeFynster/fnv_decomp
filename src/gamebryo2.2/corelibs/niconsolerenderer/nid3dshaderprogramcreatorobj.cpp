
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl _NiMalloc_00aa1070(unsigned int a);
void* __cdecl memmove(void* d, const void* s, unsigned int n);
int __cdecl NiShaderFactory_ReportError(int a, int b, const char* c);

// Allocates a buffer of size b, copies a into it, stores the pointer and size in c and d, and returns false with an error if a or b is zero.
// @fnv 0x00e98370
bool __stdcall CopyShaderBuffer(int apSource, int uiSize, int* pOutBuffer, int* pOutSize, int* e, int* f, int g)
{
    *pOutBuffer = 0;
    *pOutSize = 0;
    *e = 0;
    *f = 0;
    if (apSource != 0 && uiSize != 0)
    {
        void* pBuffer = _NiMalloc_00aa1070((unsigned int)uiSize);
        *pOutBuffer = (int)pBuffer;
        memmove(pBuffer, (const void*)apSource, (unsigned int)uiSize);
        *pOutSize = uiSize;
        return true;
    }
    NiShaderFactory_ReportError(1, g, "Invalid shader buffer\n");
    return false;
}

extern "C" const char str_010f1338[];
extern "C" const char str_010f1628[];
extern "C" const char str_010f12a8[];

extern "C" void* __cdecl FUN_00ec61c0(void* d, int v, unsigned int n);
extern "C" void __cdecl _NiFree_00aa10f0(void* p);
extern "C" bool __cdecl FindShaderProgramFile(const char* in, char* out, unsigned int n);

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char*, unsigned int, unsigned int, void*,
                                                             unsigned int, unsigned int, void*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetFileSize(void*, unsigned int*);
extern "C" __declspec(dllimport) int __stdcall ReadFile(void*, void*, unsigned int, unsigned int*, void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

typedef int(__cdecl* FUN_00aa0020_4args)(int, int, const char*, const char*);

// Resolves a file path, opens it, reads its entire contents into a newly allocated buffer, and returns the buffer and size via out parameters.
// @fnv 0x00e981f0
// src: XBOX_PDB 0x00e981f0
bool __stdcall NiD3DShaderProgramCreatorObj_LoadShaderCodeFromFile(const char* apFilePath, void** apOutBuffer, unsigned int* outSize,
                            unsigned int* apOutExtra1, unsigned int* apOutExtra2, int aiContext)
{
    char szResolvedPath[0x104];
    void* hFile;
    unsigned int uiFileSize;
    unsigned int uiBytesRead;
    void* pBuffer;

    *apOutBuffer = 0;
    *outSize = 0;
    *apOutExtra1 = 0;
    *apOutExtra2 = 0;

    if (apFilePath == 0 || *apFilePath == 0)
    {
        NiShaderFactory_ReportError(1, aiContext, str_010f12a8);
        return false;
    }

    if (!FindShaderProgramFile(apFilePath, szResolvedPath, 0x104))
    {
        ((FUN_00aa0020_4args)NiShaderFactory_ReportError)(1, aiContext, str_010f1338, apFilePath);
        return false;
    }

    hFile = CreateFileA(szResolvedPath, 0x80000000, 1, 0, 3, 0, 0);
    if (hFile == (void*)-1)
    {
        ((FUN_00aa0020_4args)NiShaderFactory_ReportError)(1, aiContext, str_010f1628, szResolvedPath);
        return false;
    }

    uiFileSize = GetFileSize(hFile, 0);
    pBuffer = _NiMalloc_00aa1070(uiFileSize + 4);
    if (pBuffer == 0)
    {
        return false;
    }
    FUN_00ec61c0(pBuffer, 0, uiFileSize + 4);
    ReadFile(hFile, pBuffer, uiFileSize, &uiBytesRead, 0);
    CloseHandle(hFile);
    if (uiBytesRead != uiFileSize)
    {
        _NiFree_00aa10f0(pBuffer);
        return false;
    }
    *outSize = uiFileSize;
    *apOutBuffer = pBuffer;
    return true;
}
