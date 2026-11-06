// fallout_shared/tesscript_decls.h: declares TESForm, Script, SpellItem, MagicItem, EffectSetting and more
#ifndef FNV_TESSCRIPT_DECLS_H
#define FNV_TESSCRIPT_DECLS_H

#include <stdarg.h>
#include <new>
#include <malloc.h>
#include "../../include/RecursiveSpinLock.h"
#include "../../include/ScriptExecutor.h"
class FormFlagRecord;
class ScriptVariableInfo;
class ScriptReferencedObject;
class ScriptLocalVariable;
class ScriptParameter;
class ScriptDefinition;
#include <string.h>
#include "tesscript_layout.h"
// tesscript_layout.h already supplies this template for the unit.
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../include/TESForm.h"
#include "../../include/AutoMemContext.h"
#include "../../include/EffectSetting.h"
#include "../../include/ExtraDataList.h"
#include "../../include/InventoryStackRecord.h"
#include "../../include/MagicItem.h"
#include "../../include/NiNode.h"
#include "../../include/BSFadeNode.h"
#include "../../include/Script.h"
#include "../../include/ScriptFunctionInfo.h"
#include "../../include/ScriptLocals.h"
#include "../../include/SpellItem.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESContainer.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESObjectBOOK.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
#include "../../include/TESSaveLoadGame.h"

#include "layout_support.h"
#include "../../include/ScriptReferencedObject.h"

#include "layout_support.h"
#include "../../include/ScriptLocalVariable.h"

#include "ScriptVariableInfo.h"
#include "tesscript_types_SCRIPT_PARAMETER.h"

class EnchantmentItem;

struct ScriptParameterKind
{
    const char* name;
    unsigned char valueKind;
    bool isReference;
    unsigned short reserved;
};
extern ScriptParameterKind DAT_0118cdd0[];
int Warning(const char*, ...);

bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                 ScriptLocals*, ...);

class TESGlobalValueReader
{
  public:
    float GetValue();
};
ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output);

#include "../../include/MEM_CONTEXT.h"

#include "../../include/SETTING_VALUE.h"
#include "../../include/SettingT_GameSettingCollection_.h"
extern SettingT_GameSettingCollection_ DAT_011cac68;
extern float DAT_011cad20[8];
extern int DAT_011cad40;
char* AllocateZeroed(unsigned int count, unsigned int size);
class FormRecordMetadata
{
  public:
    unsigned int iFormID;
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

extern RecursiveSpinLock DAT_011cacf8;
extern BSSimpleList<TESObjectREFR*> DAT_011caca8;
extern BSSimpleList<TESObjectREFR*> DAT_011cac98;
extern BSSimpleList<TESObjectREFR*> DAT_011cace8;
extern BSSimpleList<TESObjectREFR*> DAT_011cacb8;
class TimeGlobal
{
  public:
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
extern int DAT_011cae50;
class FormFlagRecord
{
  public:
    TESForm* pForm;
    unsigned int iFlags;
};
extern bool DAT_0118c685;
#endif

class ScriptActionView
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual TESBoundObject* vfn_94();
};
