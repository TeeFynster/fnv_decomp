// fallout_shared/teslevitem.cpp: TESLevItem, LevItemCopyEntry, LevItemComparison (10 functions)

#include "teslevitem_decls.h"
#include "../../include/TESLevItem.h"
// @fnv 0x0050b8d0
int TESLevItem::GetMaxLevelDifference()
{
    return g_011c8f00.Int()->i;
}

// @fnv 0x0050b560
bool TESLevItem::LoadForm(TESFile* file)
{
    unsigned char ucFormType = file->GetTESForm();
    if (ucFormType != 0x34)
        return false;
    LoadRecordHeader(file);
    do
    {
        switch ((int)file->GetChunkID())
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(pEditorId, 512);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4f4c564c:
        case 0x44454f43:
            switch ((int)file->GetChunkID())
            {
            case 0x4f4c564c: {
                LeveledObject entry;
                memset(&entry, 0, 12);
                file->GetChunkData(&entry, 12);
                if (file->IsEndianConversionRequired())
                    entry.SwapEndian();
                DAT_011c8f1c = CreateLeveledObject(entry.level, entry.count, entry.form, 0);
                break;
            }
            case 0x44454f43:
                if (DAT_011c8f1c)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(file);
                    *(ContainerItemExtra**)((char*)DAT_011c8f1c + 8) = extra;
                    DAT_011c8f1c = 0;
                }
                break;
            }
            break;
        case 0x444c564c: {
            unsigned char chance = 0;
            file->GetChunkData(&chance, 0);
            ExtraWeaponModFlags_SetWeaponModFlags(chance);
            break;
        }
        case 0x464c564c:
            file->GetChunkData(&m_ucChanceNone, 0);
            break;
        case 0x474c564c: {
            unsigned int global = 0;
            file->GetChunkData(&global);
            m_pLevelGlobal = (TESGlobal*)global;
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

// @fnv 0x0050b890
void TESLevItem::InitItem()
{
    if (GetInitialized())
        return;
    TESLeveledList::InitItem(this);
    SetInitializationState(true);
}

// @fnv 0x0050b400
TESLevItem::TESLevItem()
{
    SetFormType((ENUM_FORM_ID)0x34);
    ClearData();
}

// @fnv 0x0050b4c0
TESLevItem::~TESLevItem()
{}

// Saving entry points not yet declared on the shared TESLevItem.
struct LevItemSerialization : public TESLevItem
{
    void Save();
    void SaveGame(BGSSaveFormBuffer* buffer);
    void SaveIfChanged(BGSSaveFormBuffer* buffer);
};

// @fnv 0x0050b530
void LevItemSerialization::Save()
{
    TESForm::BeginFormRecord();
    TESForm::ClearData();
    TESLeveledList::Save();
    TESForm::FinishFormRecord();
}

// @fnv 0x0050adb0
void LevItemSerialization::SaveGame(BGSSaveFormBuffer* buffer)
{
    SaveIfChanged(buffer);
    TESLeveledList::SaveGame(buffer);
}

struct LevItemCopyEntry : public ::TESLevItem
{
    void TESLevItem_Copy(::TESForm* source);
};

// Casts the source TESForm to a TESLevItem and, if valid, calls FUN_004851b0 to copy the source into this entry.
// @fnv 0x0050b800
// src: XBOX_PDB 0x0050b800
void LevItemCopyEntry::TESLevItem_Copy(::TESForm* source)
{
    ::TESLevItem* sourceItem;
    sourceItem = dynamic_cast< ::TESLevItem*>(source);
    if (!sourceItem)
        return;
    TESForm::CopyFrom(source);
}

struct LevItemComparison : public ::TESLevItem
{
    bool TESLevItem_Compare(::TESForm*);
};

// @fnv 0x0050b840
// src: XBOX_PDB 0x0050b840
bool LevItemComparison::TESLevItem_Compare(::TESForm* other)
{
    ::TESLevItem* pLevItem = dynamic_cast< ::TESLevItem*>(other);
    if (!pLevItem)
        return true;
    if (TESForm::Compare(pLevItem))
        return true;
    return false;
}
