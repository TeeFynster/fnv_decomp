// fallout_shared/teslevitem_decls.h: declares SettingT_GameSettingCollection_, ContainerItemExtra, LeveledObject
#ifndef TESLEVITEM_DECLS_H
#define TESLEVITEM_DECLS_H

#include "../../include/SETTING_VALUE.h"
#include "../../include/SettingT_GameSettingCollection_.h"
class GlobalObject2_0040c150 : public SettingT_GameSettingCollection_
{
};
extern GlobalObject2_0040c150 g_011c8f00;
#include "layout_support.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESLeveledList.h"
class ContainerItemExtra
{
  public:
    unsigned int data[3];
    static void* operator new(unsigned int);
    static void operator delete(void*);
    ContainerItemExtra();
    bool Load(TESFile*);
};
class LeveledObject
{
  public:
    unsigned short level;
    unsigned short pad;
    TESForm* form;
    unsigned short count;
    unsigned short pad2;
    void SwapEndian();
};
extern LeveledObject* DAT_011c8f1c;
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);
#endif
