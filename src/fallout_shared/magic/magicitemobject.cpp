// fallout_shared/magic/magicitemobject.cpp: MagicItemObject (5 functions)

#include "magicitemobject_decls.h"
// @fnv 0x0040c9d0
void MagicItemObject::InitItem()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    LoadEffectsFromForm(this);
    SetInitializationState(true);
}

#include <malloc.h>
// Reads a magic item record's chunks (editor ID, bounds, full name, effects), warns when the effect list is empty, and returns true.
// @fnv 0x0040c650
bool MagicItemObject::Load(TESFile* file)
{
    int chunk;
    LoadRecordHeader(file);
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editor = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editor, 512);
            SetEditorID_AtRuntime(editor);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 0x44494645:
        case 0x41445443:
            EffectItemList::Load(file, GetFullName());
            break;
        }
        LoadMagicItemChunk(file, chunk);
        if (chunk == GetChunkID())
        {
            memset(GetData(), 0, GetDataSize());
            file->GetChunkData(GetData(), GetDataSize());
            if (file->GetChunkData())
                vfn_180();
        }
        if (!file->NextChunk())
            break;
    }
    if (!reinterpret_cast<EffectListEntries*>(reinterpret_cast<char*>(this) + kEffectEntriesOffset)->ItemsInList())
        Warning("GAME EFFECTS: Effect Item (%08X) %s has no effects defined.", GetFormID(), GetFullName());
    return true;
}

// @fnv 0x0040c5f0
void MagicItemObject::ClearData()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    ClearMagicItemData();
    SaveMagicItemData();
    FUN_004056d0(reinterpret_cast<char*>(this) + kEffectListOffset);
    TESForm::FinishFormRecord();
}

// The shared classes do not declare these comparison and copy entry points yet.
// These extensions add declarations only; all object layout comes from include/.
class EffectListOperations : public EffectItemList
{
public:
    bool CompareEffects(EffectItemList* other);
    void CopyItemsFromList(EffectItemList* other);
};

class MagicItemObjectOperations : public MagicItemObject
{
public:
    bool CompareObject(TESForm* other);
    void CopyObject(TESForm* other);
};

// @fnv 0x0040c870
bool MagicItemObjectOperations::CompareObject(TESForm* other)
{
    MagicItemObject* converted = dynamic_cast<MagicItemObject*>(other);
    if (!converted)
        return true;
    if (TESForm::Compare(other))
        return true;
    if (IsMagicItemEqual(static_cast<MagicItem*>(converted)))
        return true;
    if (reinterpret_cast<EffectListOperations*>(reinterpret_cast<char*>(this) + kEffectListOffset)->CompareEffects(converted ? reinterpret_cast<EffectItemList*>(reinterpret_cast<char*>(converted) + kEffectListOffset) : 0))
        return true;
    return false;
}

extern int DAT_01183028;
extern int DAT_011830e8;

MagicItemObject* __cdecl FUN_00ec43fb(TESForm* arg, int a, int* b, int* c, int d);

// @fnv 0x0040c930
void MagicItemObjectOperations::CopyObject(TESForm* pForm)
{
    MagicItemObject* result = FUN_00ec43fb(pForm, 0, &DAT_01183028, &DAT_011830e8, 0);
    if (!result)
        return;

    TESForm::CopyFrom(pForm);

    CopyMagicItemData(result ? reinterpret_cast<MagicItem*>(reinterpret_cast<char*>(result) + kMagicItemOffset) : 0);

    reinterpret_cast<EffectListOperations*>(reinterpret_cast<char*>(this) + kEffectListOffset)->CopyItemsFromList(result ? reinterpret_cast<EffectItemList*>(reinterpret_cast<char*>(result) + kEffectListOffset) : 0);
}
