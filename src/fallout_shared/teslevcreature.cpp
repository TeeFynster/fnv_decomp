// fallout_shared/teslevcreature.cpp: Entry, TESLevCreature (7 functions)

#include "../../include/TESLevCreature.h"
#include "teslevcreature_decls.h"
// @fnv 0x0050af60
bool TESLevCreature::Load(TESFile* file)
{
    unsigned char type = file->GetTESForm();
    if (type != 44)
        return false;
    LoadRecordHeader(file);
    do
    {
        switch ((int)file->GetChunkID())
        {
        case 0x44494445: {
            char* uiGlobalId = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(uiGlobalId, 512);
            SetEditorID_AtRuntime(uiGlobalId);
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
                LeveledObject leveledEntry;
                memset(&leveledEntry, 0, 12);
                file->GetChunkData(&leveledEntry, 12);
                if (file->IsEndianConversionRequired())
                    leveledEntry.SwapEndian();
                DAT_011c8eec =
                    (LeveledEntry*)CreateLeveledObject(leveledEntry.level, leveledEntry.count, leveledEntry.form, 0);
                break;
            }
            case 0x44454f43:
                if (DAT_011c8eec)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(file);
                    DAT_011c8eec->extra = extra;
                    DAT_011c8eec = 0;
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
            unsigned int uiGlobalId = 0;
            file->GetChunkData(&uiGlobalId);
            m_pLevelGlobal = (TESGlobal*)uiGlobalId;
            break;
        }
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            struct
            {
                unsigned int size;
                void* data;
            } chunk;
            chunk.size = file->GetChunkSize();
            chunk.data = _alloca(chunk.size);
            file->GetChunkData(chunk.data, chunk.size);
            ParseTextureSwapData(chunk.data, chunk.size, file->GetFormVersion());
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

// @fnv 0x0050adf0
TESLevCreature::TESLevCreature()
{
    SetFormType((ENUM_FORM_ID)0x2c);
    TESForm::ClearData();
    SetInitializationState(true);
}

// @fnv 0x0050aed0
TESLevCreature::~TESLevCreature()
{}

struct LevCreatureDeletion : public TESLevCreature
{
    void* Destroy(unsigned int flags);
};

// @fnv 0x0050aea0
void* LevCreatureDeletion::Destroy(unsigned int flags)
{
    TESLevCreature::~TESLevCreature();
    if (flags & 1)
        operator delete(this);
    return this;
}

// The three-chunk serialization overload is not declared by the shared header.
struct ModelTextureSwapSerialization : public TESModelTextureSwap
{
    void WriteChunks(unsigned int, unsigned int, unsigned int);
};

struct LevCreatureSerialization : public TESLevCreature
{
    void SaveForm();
};

// @fnv 0x0050a8e0
void LevCreatureSerialization::SaveForm()
{
    TESForm::BeginFormRecord();
    TESForm::ClearData();
    TESLeveledList::Save();
    ((ModelTextureSwapSerialization*)((char*)this + 0x4c))->WriteChunks(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    TESForm::FinishFormRecord();
}

namespace LevCreatureCopyImplementation {

struct Entry : public TESLevCreature
{
    void TESLevCreature_Copy(TESForm*);
};

// Casts source to TESLevCreature and, if valid, calls FUN_004851b0 to copy data from it.
// @fnv 0x0050b2e0
// src: XBOX_PDB 0x0050b2e0
void Entry::TESLevCreature_Copy(TESForm* source)
{
    TESLevCreature* creature;
    creature = dynamic_cast<TESLevCreature*>(source);
    if (!creature)
        return;
    TESForm::CopyFrom(source);
}

}

namespace LevCreatureComparisonImplementation {

struct Entry : public TESLevCreature
{
    bool TESLevCreature_Compare(TESForm*);
};

// Returns true if the other form is not a TESLevCreature or if FUN_00485270(creature) is true, otherwise false.
// @fnv 0x0050b320
// src: XBOX_PDB 0x0050b320
bool Entry::TESLevCreature_Compare(TESForm* other)
{
    TESLevCreature* creature;
    creature = dynamic_cast<TESLevCreature*>(other);
    if (!creature)
        return true;
    if (TESForm::Compare(creature))
        return true;
    return false;
}

}
