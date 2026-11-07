// src/gamebryo2.2/corelibs/nisystem/nifile_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nisystem/nifile.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


#include "nifile_packet.h"
// The dispatch helper retains the original unoptimized request construction.

void __cdecl ReadFileData();
void __cdecl NiFile_WriteNoSwap();
void __cdecl NiFile_ReadAndSwap();
void __cdecl NiFile_WriteAndSwap();

struct FileTransferCallbacks
{
    unsigned int vtable;
    unsigned int bytesProcessed;
    void(__cdecl* readFunction)();
    void(__cdecl* writeFunction)();
    void NiFile_SetEndianSwap(bool enableSwap);
};

// @fnv 0x00aa1b30
// src: XBOX_PDB 0x00aa1b30
void FileTransferCallbacks::NiFile_SetEndianSwap(bool enableSwap)
{
    if (enableSwap)
    {
        readFunction = NiFile_ReadAndSwap;
        writeFunction = NiFile_WriteAndSwap;
    }
    else
    {
        readFunction = ReadFileData;
        writeFunction = NiFile_WriteNoSwap;
    }
}

struct FileAllocator
{
    void* Game_DoHeapAlloc(unsigned int);
};
extern "C" FileAllocator DAT_011f6238;

struct FileConstructor
{
    NiFile* FUN_00aa14d0(const char*, NiFile::OpenMode, unsigned int);
};

// @fnv 0x00aa1b60
// src: COMMUNITY 0x00aa1b60
extern "C" NiFile* __cdecl NiFile_DefaultFileCreateFunc(const char* filename, NiFile::OpenMode mode, unsigned int bufferSize)
{
    void* storage = DAT_011f6238.Game_DoHeapAlloc(0x30);
    if (storage)
        return static_cast<FileConstructor*>(storage)->FUN_00aa14d0(filename, mode, bufferSize);
    return 0;
}

::NiFile* __cdecl NiFile_DefaultFileCreateFunc(const char*, ::NiFile::OpenMode, unsigned int);

// @fnv 0x00aa1b90
// src: COMMUNITY 0x00aa1b90
void __cdecl NiFile_SetFileCreateFunc(::NiFile*(__cdecl* replacement)(const char*, ::NiFile::OpenMode, unsigned int))
{
    ::DAT_011ac224 = &NiFile_DefaultFileCreateFunc;
    if (replacement)
        ::DAT_011ac224 = replacement;
}

extern int EmptyFS;
bool __cdecl NiFile_DirectoryExists(const char*);
bool __cdecl NiFile_CreateDirectoryRecursive(const char*);

struct ProgramCacheDirectoryState
{
    void* vtable;
    unsigned int references;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    const char* filename;
    const char* workingDirectory;
};

// @fnv 0x00ee8d20
// src: XBOX_PDB 0x00ee8d20
extern "C" bool __fastcall NiGPUProgramCache_ValidateDirectory(ProgramCacheDirectoryState* cache, int)
{
    if (cache->workingDirectory != reinterpret_cast<const char*>(EmptyFS))
    {
        if (NiFile_DirectoryExists(cache->workingDirectory))
            return true;
        const char* directory = cache->workingDirectory;
        bool created = NiFile_CreateDirectoryRecursive(directory);
        return created;
    }
    return false;
}

// FUN_00aa1a40 reads its good flag at +0x30: this unit lays the opened file out on its own (it derived from an
// empty NiFile stand-in before), so it stays a self-contained view rather than the shared NiFile.
struct FileAccessObject
{
    FileAccessObject(const char*, NiFile::OpenMode, unsigned int);
    virtual ~FileAccessObject();
    unsigned int absolutePosition;
    void* readFunction;
    void* writeFunction;
    unsigned int bufferCapacity;
    unsigned int bufferedBytes;
    unsigned int bufferPosition;
    unsigned int diskPosition;
    char* buffer;
    void* fileHandle;
    NiFile::OpenMode mode;
    bool good;
};
// @fnv 0x00aa1a40
// src: COMMUNITY 0x00aa1a40
extern "C" bool __cdecl NiFile_DefaultFileAccessFunc(const char* name, NiFile::OpenMode mode)
{
    FileAccessObject file(name, mode, 0);
    return file.good;
}

extern bool(__cdecl* DAT_011ac228)(const char*, ::NiFile::OpenMode);
bool __cdecl NiFile_DefaultFileAccessFunc(const char*, ::NiFile::OpenMode);

// @fnv 0x00aa1a70
// src: COMMUNITY 0x00aa1a70
extern "C" void __cdecl NiFile_SetFileAccessFunc(bool(__cdecl* handler)(const char*, ::NiFile::OpenMode))
{
    DAT_011ac228 = NiFile_DefaultFileAccessFunc;
    if (handler != 0)
    {
        DAT_011ac228 = handler;
    }
}

extern int DAT_010a2484;

namespace RelativeFileSeekDetail {
class RelativeSeekFile : public NiFile
{
  public:
    void NiFile_Seek_00aa1a90(int distance);
};

// @fnv 0x00aa1a90
// src: GAMEBRYO_LIB 0x00aa1a90
void RelativeSeekFile::NiFile_Seek_00aa1a90(int distance)
{
    Seek(distance, DAT_010a2484);  // NiFile::Seek(int, int), vtable slot 5 (+0x14)
}
}

extern "C" unsigned int __cdecl strlen(const char* str);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);

extern bool(__cdecl* DAT_011ac230)(const char*);
extern bool(__cdecl* DAT_011ac22c)(const char*);
void __cdecl fnv_StandardizeFilePath(char*);

// @fnv 0x00aa1bb0
// src: COMMUNITY 0x00aa1bb0
bool __cdecl NiFile_CreateDirectoryRecursive(const char* pcPath)
{
    if (DAT_011ac230(pcPath))
        return true;

    if (strlen(pcPath) > 0x104)
        return false;

    char acPath[0x104];
    strcpy_s(acPath, 0x104, pcPath);
    fnv_StandardizeFilePath(acPath);

    unsigned int n = 0;
    if (acPath[1] == ':')
        n = 2;

    while (n < 0x104 && (acPath[n] == '\\' || acPath[n] == '/'))
        ++n;

    for (unsigned int i = n; i < 0x104; i++)
    {
        char c = acPath[i];
        if (c == '/' || c == '\\')
        {
            acPath[i] = '\0';
            if (!DAT_011ac230(acPath))
            {
                if (!DAT_011ac22c(acPath))
                    return false;
            }
            acPath[i] = c;
        }
    }

    if (DAT_011ac230(acPath) || DAT_011ac22c(acPath))
        return true;
    return false;
}

namespace fnv_00aa1a30 {
extern void(__cdecl* DAT_011ac228)(const char*, NiFile::OpenMode);
// @fnv 0x00aa1a30
// src: XBOX_PDB 0x00aa1a30
void __cdecl NiFile_Access(const char* name, NiFile::OpenMode mode)
{
    DAT_011ac228(name, mode);
}
}  // namespace fnv_00aa1a30
