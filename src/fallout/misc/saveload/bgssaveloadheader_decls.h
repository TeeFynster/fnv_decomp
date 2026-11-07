// fallout/misc/saveload/bgssaveloadheader_decls.h: local save header declarations
#ifndef FNV_BGSSAVELOADHEADER_DECLS_H
#define FNV_BGSSAVELOADHEADER_DECLS_H

class SaveLoadFile;
class NiTexture;

class SaveLoadHeader
{
  public:
    void ReadHeaderFromFile(SaveLoadFile* file, bool temporary, unsigned int kind, unsigned int unused);
    NiTexture* LoadTextureFromFile(SaveLoadFile* file, unsigned int offset, unsigned int width, unsigned int height);
    static int ReadHeaderFromFile(SaveLoadFile* file);
};

class SaveLoadFile
{
  public:
    unsigned int Read(void* buffer, unsigned int size);
    void SetFilePosition(int offset);
    void AdvancePosition(unsigned int size);
};

class FUN_004f31d0_holder
{
  public:
    void InitIntArray();
};

int __cdecl FUN_00ecbf05(const char* path, int mode);
void* __cdecl BGSSaveLoadFile_Create(char* path, bool temporary, unsigned int size);
int __cdecl BSstrcmp(const char* path, const char* prefix);
NiTexture* __cdecl NiSourceTexture_Create(void* pixelData, void* renderedTexture);
extern int(__cdecl* DAT_00fdf0d4)(char* path);
extern unsigned int DAT_011aa2e8;
extern char* DAT_011a2224;

extern "C" unsigned int __cdecl strlen(const char* string);
extern "C" void* __cdecl fnv_zlib_memset(void* destination, int value, unsigned int size);
extern "C" unsigned int __security_cookie;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);

#endif
