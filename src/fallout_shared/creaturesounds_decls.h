// fallout_shared/creaturesounds_decls.h: declares SoundListEntry, SoundListView
#ifndef CREATURESOUNDS_DECLS_H
#define CREATURESOUNDS_DECLS_H


#include "creaturesounds_types_CREATURE_SOUND_TYPE.h"
#include "layout_support.h"
#include "../../include/TESForm.h"

class SoundListEntry
{
  public:
    TESSound* SoundAssetTmp;
    unsigned char m_ucSortOrder;
    unsigned char pad[3];
};

class SoundListView
{
  public:
    bool IsEmpty();
    SoundListEntry*& GetItem();
    SoundListView* GetNext();
    void AddHead(SoundListEntry*& item);
    void AddTail(SoundListEntry* const& item);
};

TESForm* __cdecl GetFormByID(unsigned int formID);
int __cdecl Warning(const char* format, ...);
extern const char DAT_010475a0[];

#endif
