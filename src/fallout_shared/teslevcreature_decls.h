// fallout_shared/teslevcreature_decls.h: local leveled-entry declarations
#pragma once

#include <malloc.h>
#include <string.h>
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESLeveledList.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

class ContainerItemExtra
{
  public:
    char data[12];
    ContainerItemExtra();
    bool Load(TESFile*);
};
class LeveledObject
{
  public:
    unsigned short level, pad;
    TESForm* form;
    unsigned short count, pad2;
    void SwapEndian();
};
struct LeveledEntry
{
    unsigned int a, b;
    ContainerItemExtra* extra;
};
extern LeveledEntry* DAT_011c8eec;
