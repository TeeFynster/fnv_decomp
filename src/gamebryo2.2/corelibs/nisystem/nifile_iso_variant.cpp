// src/gamebryo2.2/corelibs/nisystem/nifile_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nisystem/nifile.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


#include "nifile_packet.h"
// The dispatch helper retains the original unoptimized request construction.

void __cdecl ReadFileData();
void __cdecl FUN_00aa19c0();
void __cdecl FUN_00aa19e0();
void __cdecl FUN_00aa1ad0();

struct FileTransferCallbacks
{
    unsigned int vtable;
    unsigned int bytesProcessed;
    void(__cdecl* readFunction)();
    void(__cdecl* writeFunction)();
    void FUN_00aa1b30(bool enableSwap);
};

// @fnv 0x00aa1b30
void FileTransferCallbacks::FUN_00aa1b30(bool enableSwap)
{
    if (enableSwap)
    {
        readFunction = FUN_00aa19e0;
        writeFunction = FUN_00aa1ad0;
    }
    else
    {
        readFunction = ReadFileData;
        writeFunction = FUN_00aa19c0;
    }
}

struct FileAllocator
{
    void* FUN_00aa3e40(unsigned int);
};
extern "C" FileAllocator DAT_011f6238;

struct FileConstructor
{
    NiFile* FUN_00aa14d0(const char*, NiFile::OpenMode, unsigned int);
};

// @fnv 0x00aa1b60
extern "C" NiFile* __cdecl FUN_00aa1b60(const char* filename, NiFile::OpenMode mode, unsigned int bufferSize)
{
    void* storage = DAT_011f6238.FUN_00aa3e40(0x30);
    if (storage)
        return static_cast<FileConstructor*>(storage)->FUN_00aa14d0(filename, mode, bufferSize);
    return 0;
}

::NiFile* __cdecl FUN_00aa1b60(const char*, ::NiFile::OpenMode, unsigned int);

// @fnv 0x00aa1b90
void __cdecl FUN_00aa1b90(::NiFile*(__cdecl* replacement)(const char*, ::NiFile::OpenMode, unsigned int))
{
    ::DAT_011ac224 = &FUN_00aa1b60;
    if (replacement)
        ::DAT_011ac224 = replacement;
}

extern int EmptyFS;
bool __cdecl FUN_00aa1ab0(const char*);
bool __cdecl FUN_00aa1bb0(const char*);

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
extern "C" bool __fastcall FUN_00ee8d20(ProgramCacheDirectoryState* cache, int)
{
    if (cache->workingDirectory != reinterpret_cast<const char*>(EmptyFS))
    {
        if (FUN_00aa1ab0(cache->workingDirectory))
            return true;
        const char* directory = cache->workingDirectory;
        bool created = FUN_00aa1bb0(directory);
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
extern "C" bool __cdecl FUN_00aa1a40(const char* name, NiFile::OpenMode mode)
{
    FileAccessObject file(name, mode, 0);
    return file.good;
}

extern bool(__cdecl* DAT_011ac228)(const char*, ::NiFile::OpenMode);
bool __cdecl FUN_00aa1a40(const char*, ::NiFile::OpenMode);

// @fnv 0x00aa1a70
extern "C" void __cdecl FUN_00aa1a70(bool(__cdecl* handler)(const char*, ::NiFile::OpenMode))
{
    DAT_011ac228 = FUN_00aa1a40;
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
    void FUN_00aa1a90(int distance);
};

// @fnv 0x00aa1a90
void RelativeSeekFile::FUN_00aa1a90(int distance)
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
bool __cdecl FUN_00aa1bb0(const char* pcPath)
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
void __cdecl FUN_00aa1a30(const char* name, NiFile::OpenMode mode)
{
    DAT_011ac228(name, mode);
}
}  // namespace fnv_00aa1a30
