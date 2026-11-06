
// tesscriptfunctions_ctx_variant.cpp: context variant of src/fallout_shared/tesscriptfunctions.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "../../include/BSSimpleList.h"

#include "../../include/BSStringT.h"
#include "../../include/Actor.h"
#include "../../include/BGSListForm.h"
#include "../../include/BaseProcess.h"
#include "../../include/Script.h"
#include "../../include/TESFaction.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
class ScriptParameter;
class ScriptHeaderData;

#include "../../include/OBJECT_ACTION.h"

class BGSMusicType;
class FalloutAudioMedia
{
  public:
    static void PlayMedia(BGSMusicType*);
    static void EndMediaUpdate();
    static void Update();
};
class ScriptLocals;

extern bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                        ScriptLocals*, ...);
#include "../../include/ExtraDataList.h"

class ExtraDataList;
class ScriptLocals;
class ScriptParameter;
class StrListT;
#include "../../include/InventoryStackRecord.h"
#include "../../include/InventoryChanges.h"

struct SettingObj
{
    const char* String();
};

// Exe 0x005d0300: unit-local Interface view; declarations and layout are preserved.
struct TesscriptfunctionsInterfaceView
{
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
};

extern char DAT_011d424c;
extern Actor* g_thePlayer;

void FUN_00704af0();

// @fnv 0x005d0300
bool Cmd_UnequipItem_Execute(const ScriptParameter* param, const char* desc, TESObjectREFR* obj, TESObjectREFR* obj2,
                  Script* script, ScriptLocals* locals, double& result, unsigned int& opcode)
{
    TESForm* pForm = 0;
    int iCount = 0;
    int iFlag = 0;

    if (!ExtractArgs(param, desc, &opcode, obj, obj2, script, locals, &pForm, &iCount, &iFlag))
        return false;

    if (obj)
    {
        Actor* pActor = dynamic_cast<Actor*>(obj);
        bool bSet = false;
        if (iCount > 0)
            bSet = true;

        if (pForm)
        {
            if (pActor)
            {
                InventoryChanges* pChanges = InventoryChanges::GetOrAddInventoryChanges(obj);
                if (pChanges)
                {
                    ExtraDataList* pExtra = 0;
                    pExtra = pChanges->FUN_004bfda0(pForm, 0);
                    if (pExtra)
                    {
                        pExtra->FUN_0041ab70(false);
                        pActor->UnequipItem(pForm, 1, 0, 1, bSet, 1);
                        if (pActor == g_thePlayer && iFlag == 0)
                        {
                            BSStringT<char> str;
                            str.PrintfString("%s %s.", TESFullName::GetFullName(pForm),
                                         ((SettingObj*)&DAT_011d424c)->String());
                            TesscriptfunctionsInterfaceView::ShowMessage(str.String(), 0,
                                                   "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                                   0, 2.0f, false);
                            g_thePlayer->FUN_00950030();
                            g_thePlayer->GetProcess()->UpdateActorAppearance(true, false, false);
                            FUN_00704af0();
                        }
                    }
                }
            }
        }
        else
        {
            InventoryChanges* pChanges2 = InventoryChanges::GetOrAddInventoryChanges(obj);
            if (pChanges2)
            {
                InventoryStackRecord* pHolder = pChanges2->FUN_004d0650(pForm, 0);
                if (pHolder)
                {
                    if (pHolder->FUN_00559450())
                    {
                        if (pHolder->FUN_00559450()->GetItem())
                        {
                            pHolder->FUN_00559450()->GetItem()->FUN_0041ab70(bSet);
                        }
                        else
                        {
                            ExtraDataList* pNew = new ExtraDataList();
                            pNew->FUN_0041ab70(bSet);
                            pHolder->FUN_00559450()->AddHead(pNew);
                        }
                    }
                    else
                    {
                        pHolder->m_pExtraDataLists = new BSSimpleList<ExtraDataList*>();
                        ExtraDataList* pNew2 = new ExtraDataList();
                        pNew2->FUN_0041ab70(bSet);
                        pHolder->FUN_00559450()->AddHead(pNew2);
                    }
                    delete pHolder;
                }
            }
        }
    }

    return true;
}
