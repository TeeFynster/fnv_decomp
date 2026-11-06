// fallout_shared/distant terrain system/bgsterrainmanager_decls.h: declares FileFinder
#ifndef FNV_BGSTERRAINMANAGER_DECLS_H
#define FNV_BGSTERRAINMANAGER_DECLS_H


#include "../../../include/BSFile.h"
#include "../../../include/BGSTerrainManager.h"

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
    static BSFile* GetFile(const char*, NiFile::OpenMode, unsigned int, unsigned int);
    static FILE_LOCATION __cdecl Exist(const char*, char*, unsigned int, unsigned int);
};


BGSTerrainManager* ReadAnimationFromStream(BSFile*);

#endif
