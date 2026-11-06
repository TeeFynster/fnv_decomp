// fallout_shared/region system/tesregion_load.h: TESRegionLoadHandler, TESRegionLoadList
#ifndef TESREGION_LOAD_H
#define TESREGION_LOAD_H

#include <malloc.h>
#include "../../../include/TESFile.h"
#include "../../../include/TESRegionDataManager.h"
class TESRegionLoadHandler
{
  public:
    TESRegionDataManager* GetRegionDataManager();
};
extern TESDataHandler* g_dataHandler;
class TESRegionLoadList
{
  public:
    void Remove(RegionPointList* const&);
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
#endif
