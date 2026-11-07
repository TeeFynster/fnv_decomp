// bssystem/filefinder_filefinder_decls.h: declares FileFinder, ArchiveManager
#ifndef FNV_FILEFINDER_FILEFINDER_DECLS_H
#define FNV_FILEFINDER_FILEFINDER_DECLS_H

#include "../../include/BSFile.h"

class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NOTFOUND = 0,
        HARDDRIVE = 1,
        ARCHIVE = 2,
        CACHE = 3,
        PC = 4,
        DVD = 5,
        DVDTOHD = 6
    };
    static NiFile* GetFile(const char*, NiFile::OpenMode, unsigned int, unsigned int);
    static FILE_LOCATION __cdecl Exist(const char*, char*, unsigned int, unsigned int);
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
    unsigned int FileFinder_LookForFile(char*, unsigned int, unsigned int);
};
extern "C" FileFinder* g_fileFinder;
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

extern MemoryManager g_memoryManager;
class ArchiveManager
{
  public:
    static NiFile* GetFile(const char*, unsigned int, unsigned int);
};

#endif
