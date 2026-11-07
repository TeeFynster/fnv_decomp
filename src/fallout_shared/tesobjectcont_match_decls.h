#ifndef FNV_TESOBJECTCONT_MATCH_DECLS_H
#define FNV_TESOBJECTCONT_MATCH_DECLS_H

class TESObjectCONT_TESScriptableInitCall
{
  public:
    void InitItem(TESForm*);
};

#include "../../include/TESSound.h"
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};

class ContainerItemExtra
{
  public:
    unsigned int opaque0;
    unsigned int opaque4;
    unsigned int opaque8;
    ContainerItemExtra();
    bool Load(TESFile*);
};

struct ContainerItemExtraOwner
{
    unsigned int opaque0;
    unsigned int opaque4;
    ContainerItemExtra* item;
};

class CombatController;
#include "../../include/CombatProcedure.h"
#include "../../include/EffectSetting.h"
class BGSVoiceType;
#include "../../include/BGSTalkingActivator.h"
struct CNTOChunkData
{
    unsigned int formID;
    unsigned int count;
    void TwoValues_Endian();
};

extern "C" ContainerItemExtraOwner* DAT_011c9348;

int __cdecl Warning(const char*, ...);

#endif
