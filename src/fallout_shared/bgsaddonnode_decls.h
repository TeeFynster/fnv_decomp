// fallout_shared/bgsaddonnode_decls.h: declares TESFormInitFlag, TESSound, TESFileFormVersion, TESFileAccessor
#ifndef FNV_BGSADDONNODE_DECLS_H
#define FNV_BGSADDONNODE_DECLS_H


#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/TESSound.h"

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};

class TESFileAccessor
{
  public:
    bool GetChunkData();
};

extern unsigned int DAT_011c8054;

TESForm* GetFormByID(unsigned int formID);
int __cdecl Warning(const char* format, ...);

#endif
