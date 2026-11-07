
// to their real unit once identified.

// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "nifile_console.h"
struct MersenneTwister
{
    int _0;
    int _4;
    char _8[0x9C0];
    int _9C8;
    void BSRandom_Init(unsigned int);
    void Seed(unsigned int);
};

struct ArchiveManager
{
    void* FUN_00afe0d0(const char* name, unsigned int a, unsigned int b, unsigned int c);
};

extern ArchiveManager* DAT_011f81dc;

class FileStream
{
  public:
    virtual ~FileStream();
    virtual operator bool() const;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    char* unk20;
    FILE* unk24;
    int unk28;
    bool unk2C;
    FileStream(const char* name, int mode, unsigned int bufferSize);
};

// @fnv 0x00afde50
// src: COMMUNITY 0x00afde50
bool FileFinder_AccessFile(const char* name, int mode)
{
    if (mode == 0)
    {
        return DAT_011f81dc ? DAT_011f81dc->FUN_00afe0d0(name, 0, 0, 0xffffffff) : 0;
    }
    FileStream kFile(name, mode, 0);
    return kFile;
}
