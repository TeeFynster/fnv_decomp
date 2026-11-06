// tesregiondatasound_decls.h: declares RegionDataEntry, RegionSoundEntry and more
#ifndef TESREGIONDATASOUND_DECLS_H
#define TESREGIONDATASOUND_DECLS_H

#include "../include/BSSimpleList.h"
#include "../include/TESFile.h"
#include "../include/TESForm.h"
#include "../include/BGSMusicType.h"
#include "../include/TESDataHandler.h"
#include "../include/TESRegionDataSound.h"


void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
class RegionDataEntry
{
  public:
    unsigned int data;
    void Endian();
};
class RegionSoundEntry
{
  public:
    unsigned int sound, flags, chance;
    RegionSoundEntry();
    void Endian();
};
class ScriptVariableInfo;
class ContainerItemExtraFileData
{
  public:
    void Endian();
};
extern TESDataHandler* g_dataHandler;
int __cdecl Warning(const char*, ...);
#endif
