#include "../../include/BSSimpleArray.h"
// fallout_shared/bgsidlecollection_decls.h: unit-local declarations
#ifndef FALLOUT_SHARED_BGSIDLECOLLECTION_DECLS_H
#define FALLOUT_SHARED_BGSIDLECOLLECTION_DECLS_H

#include "../../include/TESFile.h"
#include "../../include/TESForm.h"


class TESFormInitFlag
{
  public:
    static TESForm* GetFormByID(unsigned int formID);
};

extern "C" const char kBGSIdleCollectionMissingIdle[];
extern "C" const char kBGSIdleCollectionMissingAnim[];
int Warning(const char* format, ...);

bool FUN_00479e20(unsigned int);
template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
void* operator new[](unsigned int);
void operator delete[](void*);
extern "C" void* memset(void*, int, unsigned int);
#endif
