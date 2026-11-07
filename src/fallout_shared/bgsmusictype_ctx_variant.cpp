
// bgsmusictype_ctx_variant.cpp: context variant of src/fallout_shared/bgsmusictype.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "music_local.h"
#include "../../include/AutoMemHelper.h"
#include <malloc.h>
#include "../../include/TESFile.h"
extern "C" int __cdecl sprintf_s(char* buffer, unsigned int size, const char* format, ...);
unsigned int __cdecl GetRandomNumberInRange(int minimum, int maximum);

#include <windows.h>

int __cdecl FUN_00462d40(const char* path, char* drive, unsigned int driveLen, char* dir, unsigned int dirLen,
                         char* fname, unsigned int fnameLen, char* ext, unsigned int extLen);
int __cdecl BSstricmp(const char* a, const char* b);

class BSDirectoryIterator
{
  public:
    void* m_hFindHandle;
    _WIN32_FIND_DATAA m_findData;
    BGSMusicType::MusicTrack m_path;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    BSDirectoryIterator(const char* path);
    ~BSDirectoryIterator();
    int Next(bool* outDone);
    bool IsDirectory();
    const char* GetFileName();
};

class MusicFileBuilder : public BGSMusicType
{
  public:
    void BGSMusicType_BuildFileList();
};

// @fnv 0x005917b0
// src: COMMUNITY 0x005917b0
void MusicFileBuilder::BGSMusicType_BuildFileList()
{
    AutoMemHelper memContext(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSMusicType.cpp", 352);
    const char* soundFile5 = GetSoundFile();
    char path5[260];
    char fullPathA[260];
    sprintf_s(path5, 0x104, "%s\\%s", "Data\\Music", soundFile5);
    const char* ext_2 = ".mp3";
    bool done4 = false;
    BSDirectoryIterator iter(path5);
    int res3 = iter.Next(&done4);
    while (!done4 && res3 == 0)
    {
        if (!iter.IsDirectory() && iter.GetFileName())
        {
            char fileExt[260];
            FUN_00462d40(iter.GetFileName(), 0, 0, 0, 0, 0, 0, fileExt, 0x104);
            if (BSstricmp(fileExt, ext_2) == 0)
            {
                sprintf_s(fullPathA, 0x104, "%s%s", path5, iter.GetFileName());
                MusicTrack* entry = new MusicTrack(fullPathA);
                m_kMusicFiles.AddHead(entry);
            }
        }
        res3 = iter.Next(&done4);
    }
}
