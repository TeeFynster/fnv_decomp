
// effectitemlist_ctxr_variant.cpp: rename variant for 0x00405760 (integration 2026-10-30): the unit's skeleton with Str renamed, whose names are bound elsewhere.
#include "effectitemlist.h"

#include "../../../include/BSStringT.h"

#include "../../../include/EffectSetting.h"
ActorPathHandler::PATH_HANDLER_RESULT CallNoPathUpdate(ActorPathHandler* pHandler, float fSeconds)
{
    return pHandler->CompleteNoPathUpdate(fSeconds);
}

extern "C" char DAT_011837c4, DAT_01183028, DAT_010120d8, DAT_010125c0, DAT_01012578, DAT_01012520, DAT_011c33d4;
struct File
{
    int TESFile_GetTESChunk();
    void ReadChunkInt(unsigned*);
    void FUN_004726f0();
};
struct Item
{
    char data[36];
    Item(EffectSetting*);
    ~Item();
    bool FUN_00404120(File*, const char*);
    bool FUN_00404710();
};
void* __cdecl operator new(unsigned);
void __cdecl operator delete(void*);
void __cdecl ResolveFormID(unsigned*, File*);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
void __cdecl Warning_005b5e40(const char*, ...);
struct List
{
    int pad[3];
    int count;
    void FUN_00405d20(Item*);
    void EffectItemList_Load(File*, const char*);
};
// @fnv 0x00405760
// src: XBOX_PDB 0x00405760
void List::EffectItemList_Load(File* file, const char* name)
{
    unsigned id;
    EffectSetting* effect;
    Item* actorValue;
    int item;
    switch (file->TESFile_GetTESChunk())
    {
    case 0x44494645:
        file->ReadChunkInt(&id);
        ResolveFormID(&id, file);
        effect = dynamic_cast<EffectSetting*>(TESForm_GetFormByNumericID(id));
        if (effect)
        {
            actorValue = new Item(effect);
            file->FUN_004726f0();
            if (effect->HasFlag2() && effect->GetAssociatedActorValue() == 0x36)
                item = 0;
            if (actorValue->FUN_00404120(file, name))
                FUN_00405d20(actorValue);
            else
            {
                Warning_005b5e40(&DAT_010125c0, static_cast<const char*>(effect->GetEffectName()), name == 0 ? &DAT_010120d8 : name);
                delete actorValue;
                actorValue = 0;
            }
            *(Item**)&DAT_011c33d4 = actorValue;
        }
        else
            Warning_005b5e40(&DAT_01012578, id, name == 0 ? &DAT_010120d8 : name);
        break;
    case 0x41445443:
        if (*(Item**)&DAT_011c33d4)
        {
            (*(Item**)&DAT_011c33d4)->FUN_00404120(file, name);
            if ((*(Item**)&DAT_011c33d4)->FUN_00404710())
                count++;
        }
        else
            Warning_005b5e40(&DAT_01012520, name == 0 ? &DAT_010120d8 : name);
        break;
    }
}
