// fallout_shared/magic/effectsettingcollection.cpp: EffectSettingCollection (3 functions)

#include "../../../include/EffectSetting.h"
#include "../../../include/LowProcess.h"
#include "../../../include/MiddleHighProcess.h"
#include "../../../include/TESSaveLoadGame.h"

class Date;

class PlayerQuestData
{
  public:
    void SetLogDate(Date* value);
};

TESForm* GetFormByID(unsigned int formID);
void RegisterEffectSetting(EffectSetting* effect);

typedef int ActorValueIndex;

class EffectSettingCollection
{
  public:
    unsigned char layoutPadding0[0x3E8];
    unsigned int uiFlags;

    void InitializeCollection(bool initialize);
    static void InitializeEffectSettings();
    static EffectSetting* CreateEffectSetting(unsigned int formID, char* editorID, char* fullName, ActorValueIndex item,
                                              float cost, ActorValueIndex skill, unsigned int count,
                                              ActorValueIndex resist, int flags);
};

extern "C" EffectSetting* DAT_011c33f4;

// @fnv 0x00471D00
void EffectSettingCollection::InitializeCollection(bool initialize)
{
    if (initialize)
        uiFlags |= 4;
    else
    {
        uiFlags &= ~4;
        uiFlags &= ~8;
    }
}

// @fnv 0x00408E40
EffectSetting* EffectSettingCollection::CreateEffectSetting(unsigned int formID, char* editorID, char* fullName,
                                                            ActorValueIndex item, float cost, ActorValueIndex skill,
                                                            unsigned int count, ActorValueIndex resist, int flags)
{
    if (GetFormByID(formID))
        return 0;

    EffectSetting* effect = new EffectSetting();
    effect->SetRefID(formID, true);
    effect->SetEditorID_AtRuntime(editorID);
    ((LowProcess*)effect)->LowProcess::SetPackageObjectType(count);
    effect->UpdateEffectName(fullName);
    effect->BSShaderProperty_SetDepthBias(cost);
    effect->SetAssociatedActorValue(skill);
    ((MiddleHighProcess*)effect)->MiddleHighProcess::AddDeferredHideLimb((ObjectToAcquire*)item);
    ((PlayerQuestData*)effect)->SetLogDate((Date*)resist);
    effect->SetEffectID(flags);
    RegisterEffectSetting(effect);
    return effect;
}

// @fnv 0x00408F60
void EffectSettingCollection::InitializeEffectSettings()
{
    CreateEffectSetting(0x14A, "ScriptEffect", "Script Effect", -1, 0.0f, -1, 0x170, -1, 1);
    CreateEffectSetting(0x14B, "FireDamage", "Fire Damage", -1, 0.0f, 0x10, 0x20000475, 0x34, 0);
    CreateEffectSetting(0x14C, "FrostDamage", "Frost Damage", -1, 0.0f, 0x10, 0x20000475, -1, 0);
    CreateEffectSetting(0x14D, "ShockDamage", "Shock Damage", -1, 0.0f, 0x10, 0x20000475, -1, 0);
    CreateEffectSetting(0x14E, "RestoreHealth", "Restore Health", -1, 0.0f, 0x10, 0x70, -1, 0);
    DAT_011c33f4 = CreateEffectSetting(0x14F, "UMON", "Usage Monitor Effect", -1, 0.0f, -1, 0x12, -1, 1);
}

struct G2
{
    void AddHead(int**);
};
struct GlobalObject_00680890 : public G2
{
};
extern GlobalObject_00680890 g_011c3400;
// @fnv 0x00409060
void RegisterEffectSetting(int* pEffect)
{
    if (pEffect)
        g_011c3400.AddHead(&pEffect);
}

struct FUN_00408b60
{
    void DestroyAllItems(void);
};

// @fnv 0x00408de0
// src: COMMUNITY 0x00408de0
void __cdecl EffectSettingCollection_Destroy()
{
    ((FUN_00408b60*)&g_011c3400)->DestroyAllItems();
}

// Save-game header of the form being sized: formID, change type byte, then (packed) change flags.
struct ChangedForm
{
    unsigned int formID;
    unsigned char changeType;
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

TESForm* TESForm_GetFormByNumericID(unsigned int formID);
void ProgramFlow(const char* format, ...);

// Computes the save size of the effect setting collection, adding 4/2 bytes for save-load state and 4 bytes per flagged EffectSetting, then logs the result.
// @fnv 0x00408c30
// src: COMMUNITY 0x00408c30
unsigned int EffectSettingCollection_GetKnownEffectsSaveSize()
{
    unsigned int size = 0;
    EffectSetting* mgef;
    unsigned short uiStart = (unsigned short)size;
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        size += 4;
        size += 2;
    }
    size += 4;
    for (BSSimpleList<EffectSetting*>* node = (BSSimpleList<EffectSetting*>*)&g_011c3400;
         node && (mgef = node->GetItem()) != 0; node = node->GetNext())
    {
        if (mgef->IsFlagSet(0x200000))
            size += 4;
    }
    if (*g_011de4e8.Bool())
    {
        ChangedForm* changed = (ChangedForm*)g_TESSaveLoadGame->FUN_004fd3e0();
        if (changed)
        {
            TESForm* form = TESForm_GetFormByNumericID(changed->formID);
            ProgramFlow("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         size - uiStart, changed->formID, form->GetName(), *(unsigned int*)(&changed->changeType + 1),
                         0x77,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Magic\\EffectSettingCollection.cpp");
        }
        else
        {
            ProgramFlow("GetSaveSize(): %-5i ending at line %i in file %s", size - uiStart, 0x77,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Magic\\EffectSettingCollection.cpp");
        }
    }
    return size;
}
