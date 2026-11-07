
// src/gamebryo2.2/corelibs/nisystem/nifile_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nisystem/nifile.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nifile_packet.h"
// The dispatch helper retains the original unoptimized request construction.
#pragma optimize("", off)

class FUN_00afe9f0
{
  public:
    FUN_00afe9f0(int aiFlags);
    ~FUN_00afe9f0();
    int unk00;
};

struct Dummy_0086bce0;
extern Dummy_0086bce0* _g_fileFinder;
extern bool DAT_011f81e0;

void FileFinder_GetFile_(const char* apPath, int aiArg, unsigned int auiArg);
void FileFinder_AccessFile();
void __cdecl NiFile_SetFileCreateFunc(void (*apfnCallback)(const char*, int, unsigned int));
void __cdecl NiFile_SetFileAccessFunc(void (*apfnCallback)());

class FUN_00afdc60 : public FUN_00afe9f0
{
  public:
    FUN_00afdc60(int aiArg1, int aiArg2, bool abFlag);
};

// @fnv 0x00afdc60
FUN_00afdc60::FUN_00afdc60(int aiArg1, int aiArg2, bool abFlag) : FUN_00afe9f0(0)
{
    int aiUnused[3];
    (void)aiUnused;
    if (!_g_fileFinder)
        _g_fileFinder = (Dummy_0086bce0*)this;
    NiFile_SetFileCreateFunc(FileFinder_GetFile_);
    NiFile_SetFileAccessFunc(FileFinder_AccessFile);
    DAT_011f81e0 = abFlag;
}
