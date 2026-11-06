// fallout_shared/teslevcharacter_unit.h: declares TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject, TESBoundAnimObject and more
#ifndef FNV_TESLEVCHARACTER_UNIT_H
#define FNV_TESLEVCHARACTER_UNIT_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "TESGlobal.h"
#include "layout_support.h"
class TESActorBase;
class BGSLoadFormBuffer;
class BSFileEntry;
class LeveledObject;
class ContainerItemExtra;
class ShortPoint3;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESLevCharacter;
class TESLeveledList;
class TESModel;
class TESModelTextureSwap;
class TESFormList;
class FileEntryList;
class DistantTreeTextureInfo;
#include "../../include/TESObject.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESLeveledList.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESLevCharacter.h"
#include "../../include/TESLevCreature.h"
#include "../../include/TESLevItem.h"
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class ContainerItemExtra
{
  public:
    ContainerItemExtra();
    bool Load(TESFile*);
    unsigned char data[12];
};
class LeveledObject
{
  public:
    unsigned short level;
    unsigned short pad;
    TESForm* form;
    ContainerItemExtra* extra;
    void SwapEndian();
};
extern LeveledObject* DAT_011c8e64;
extern "C" void* memset(void*, int, unsigned int);
void* operator new(unsigned int);
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)
#endif
