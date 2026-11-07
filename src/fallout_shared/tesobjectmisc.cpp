// fallout_shared/tesobjectmisc.cpp: TESObjectMISC, TESCaravanMoney, TargetHolder (13 functions)

#include "tesobjectmisc_decls.h"
#include "../../include/TESForm.h"
#include "../../include/TESValueForm.h"
#include <malloc.h>
extern const char DAT_0102b038[];
TESForm* GetFormByID(unsigned int formID);
int Warning(const char* format, ...);

// Legacy TESForm entry points 0x00484c20/0x00484c50/0x00485e00 have no declarations in the shared header; this is an ABI-only record I/O interface.
struct LegacyFormRecordIO
{
    void SaveRecordFlags(unsigned int flags);
    void LoadRecordArguments(unsigned int flags, unsigned int currentFlags);
    void FinishRecord();
};

// @fnv 0x0051a980
void TESObjectMISC::ResetFormData()
{
    pLoopingSound = 0;
}

// Initializes the scriptable, destructible, model, and pickup sound sub-forms, resolves pLoopingSound by form ID, and marks the object initialized.
// @fnv 0x0051a9a0
void TESObjectMISC::InitItem()
{
    if (GetInitialized())
        return;

    ((TESScriptableForm*)((char*)this + 0x68))->InitItem(this);
    ((BGSDestructibleObjectForm*)((char*)this + 0x84))->InitItem(this);
    ((TESModelTextureSwap*)((char*)this + 0x3C))->InitItem(this);
    ((BGSPickupPutdownSounds*)((char*)this + 0x9C))->InitItem(this);

    unsigned int formID = (unsigned int)pLoopingSound;
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        pLoopingSound = dynamic_cast<TESSound*>(GetFormByID(formID));
        if (!pLoopingSound)
            Warning(DAT_0102b038, formID, GetName(), GetFormID());
    }

    SetInitializationState(true);
}

// @fnv 0x0059ae60
TESCaravanMoney::TESCaravanMoney()
{
    SetFormType(ENUM_FORM_ID_CMNY_ID);
    ResetFormData();
}

// @fnv 0x0051aaa0
bool TESObjectMISC::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    while (int chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            char* swaps;
            {
                unsigned int size = file->GetChunkSize();
                swaps = (char*)_alloca(size);
                file->GetChunkData(swaps, size);
                TESModelTextureSwap::ParseTextureSwapData(swaps, size, file->GetFormVersion());
            }
            break;
        }
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            ((CombatProcedure*)((char*)this + 0x68))->Initialize((CombatController*)scriptID);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 0x4d414e59: {
            unsigned int pickupID = 0;
            file->GetChunkData(&pickupID);
            ((CombatProcedure*)((char*)this + 0x9c))->Initialize((CombatController*)pickupID);
            break;
        }
        case 0x4d414e5a: {
            unsigned int putdownID = 0;
            file->GetChunkData(&putdownID);
            ((TESRegionGrassObject*)((char*)this + 0x9c))->AssignLandTexture((TESLandTexture*)putdownID);
            break;
        }
        case 0x41544144:
            ((BGSImpactData*)this)->ReadTypedData(file, 0, 0);
            break;
        case 0x4d414e52: {
            unsigned int loopingID = 0;
            file->GetChunkData(&loopingID);
            FUN_009db930(loopingID);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_0051b070_shell
{
    void TESObjectMISC_SaveGame(unsigned int aiFlags);
};

// Calls FUN_00484c20 with aiFlags, then calls FUN_0048e9e0 with aiFlags on the object at this+0x74.
// @fnv 0x0051b070
// src: XBOX_PDB 0x0051b070
void FUN_0051b070_shell::TESObjectMISC_SaveGame(unsigned int aiFlags)
{
    reinterpret_cast<LegacyFormRecordIO*>(this)->SaveRecordFlags(aiFlags);
    reinterpret_cast<TESValueForm*>(reinterpret_cast<char*>(this) + 0x74)->SaveGame_0048e9e0(aiFlags);
}


struct FUN_0051b020_shell
{
    unsigned short __thiscall TESObjectMISC_GetSaveSize(unsigned int aiFlags);
};

// Returns the sum of GetSaveSize(aiFlags) for this object and the sub-object at offset 0x74.
// @fnv 0x0051b020
// src: XBOX_PDB 0x0051b020
unsigned short __thiscall FUN_0051b020_shell::TESObjectMISC_GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += (unsigned short)((TESForm*)this)->TESForm::GetSaveSize(aiFlags);
    isize += ((TESValueForm*)((char*)this + 0x74))->GetFlaggedDataSize(aiFlags);
    return isize;
}

struct FUN_0051b0a0_shell
{
    void LoadForm(unsigned int aiFlags, BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x0051b0a0
void FUN_0051b0a0_shell::LoadForm(unsigned int aiFlags, BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<LegacyFormRecordIO*>(this)->LoadRecordArguments(
        aiFlags, reinterpret_cast<unsigned int>(apLoadGameBuffer));
    reinterpret_cast<TESValueForm*>(reinterpret_cast<char*>(this) + 0x74)
        ->LoadGame_0048ea10(aiFlags, reinterpret_cast<unsigned int>(apLoadGameBuffer));
}

void _Deallocate(void*);
struct CallHelper
{
    void FUN_0051a840();
};
struct TargetHolder
{
    void* ReleaseIfFlagged(unsigned int);
};
// @fnv 0x0051a810
void* TargetHolder::ReleaseIfFlagged(unsigned int flags)
{
    ((CallHelper*)this)->FUN_0051a840();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S_00477f20
{
    void FUN_00477f20();
};
struct S_00487010
{
    void Save_00487010();
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct S_0048cca0
{
    void Save_0048cca0();
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct FUN_0047b560_holder
{
    void LogFormIDs();
};
struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};
void TESForm_AddChunk_00485910(unsigned int, unsigned int);
struct FUN_0051ae80_shell
{
    void TESObjectMISC_Save();
};
// @fnv 0x0051ae80
// src: XBOX_PDB 0x0051ae80
void FUN_0051ae80_shell::TESObjectMISC_Save()
{
    ((TESForm*)this)->BeginFormRecord();
    ((S_00487010*)((char*)this + 0x30))->Save_00487010();
    ((S_0048a520*)((char*)this + 0x3c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_0048e370_obj*)((char*)this + 0x5c))->TESTexture_Save(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x8c))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x68))->Save_0048cca0();
    ((S_00477f20*)((char*)this + 0x84))->FUN_00477f20();
    ((FUN_0047b560_holder*)((char*)this + 0x9c))->LogFormIDs();
    ((LegacyFormRecordIO*)this)->FinishRecord();
    if (*(unsigned int*)((char*)this + 0xa8))
    {
        unsigned int formID = ((TESForm**)((char*)this + 0xa8))[0]->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e52, formID);
    }
    ((TESForm*)this)->FinishFormRecord();
}

struct FUN_008cdd90_shell
{
    unsigned int __thiscall DialoguePackage_GetCurrentDialogItem();
};
struct FUN_0051af50_shell
{
    void __thiscall TESObjectMISC_Copy(TESForm* apCopy);
};
// @fnv 0x0051af50
// src: XBOX_PDB 0x0051af50
void __thiscall FUN_0051af50_shell::TESObjectMISC_Copy(TESForm* apCopy)
{
    TESObjectMISC* pmisc = dynamic_cast<TESObjectMISC*>(apCopy);
    if (!pmisc)
        return;
    ((TESObjectMISC*)this)->FUN_009db930(((FUN_008cdd90_shell*)pmisc)->DialoguePackage_GetCurrentDialogItem());
    ((TESForm*)this)->TESForm::CopyFrom(apCopy);
}

struct FUN_0051b0d0_holder
{
    void SaveToBuffer(BGSSaveFormBuffer*);
};
// Saves this object to the buffer by calling the save routine at offset 0 and the one at offset 0x74.
// @fnv 0x0051b0d0
void FUN_0051b0d0_holder::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<TESForm*>(this)->TESForm::SaveGame(buffer);
    reinterpret_cast<TESValueForm*>(reinterpret_cast<char*>(this) + 0x74)->SaveGameBGS_0048ea40(buffer);
}

struct FUN_0051b100_owner
{
    void __thiscall TESObjectMISC_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
};
// Loads the form from the buffer, then loads the value form at offset 0x74 from the same buffer.
// @fnv 0x0051b100
// src: XBOX_PDB 0x0051b100
void __thiscall FUN_0051b100_owner::TESObjectMISC_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<TESForm*>(this)->TESForm::LoadGame(apLoadGameBuffer);
    reinterpret_cast<TESValueForm*>((char*)this + 0x74)->LoadGame(apLoadGameBuffer);
}

struct FUN_0051afb0_shell : public FUN_008cdd90_shell
{
    bool TESObjectMISC_Compare(TESForm* apCompare);
};
// @fnv 0x0051afb0
// src: XBOX_PDB 0x0051afb0
bool FUN_0051afb0_shell::TESObjectMISC_Compare(TESForm* apCompare)
{
    TESObjectMISC* pcomp = dynamic_cast<TESObjectMISC*>(apCompare);
    if (!pcomp)
        return true;
    if (DialoguePackage_GetCurrentDialogItem() != ((FUN_008cdd90_shell*)pcomp)->DialoguePackage_GetCurrentDialogItem())
        return true;
    if (((TESForm*)this)->TESForm::Compare((TESForm*)pcomp))
        return true;
    return false;
}
