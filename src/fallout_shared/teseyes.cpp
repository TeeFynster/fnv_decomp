// fallout_shared/teseyes.cpp: TESEyes (13 functions)

#include <malloc.h>
#include "../../include/TESEyes.h"
#include "../../include/TESForm.h"
#include "../../include/TESFile.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFullName.h"
#include "../../include/TESNPC.h"
#include "../../include/TESTexture.h"


// @fnv 0x005fc050
TESEyes::TESEyes()
{
    SetFormType((ENUM_FORM_ID)0xb);
    ResetFormData();
}

// @fnv 0x005fc4d0
bool TESEyes::IsFlagSet()
{
    return (cFlags & 1) ? true : false;
}

// Sets or clears bit 0 of the byte at offset 0x30 of this object according to aFlag.
// @fnv 0x005fc4f0
void TESEyes::SetFlag(bool aFlag)
{
    if (aFlag)
        cFlags |= 1;
    else
        cFlags &= 0xfffffffe;
}

// @fnv 0x005fc530
bool TESEyes::IsNotFlag2Set()
{
    if (cFlags & 2)
        return false;
    return true;
}

// @fnv 0x005fc590
bool TESEyes::IsFlag4Clear()
{
    if (cFlags & 4)
        return false;
    return true;
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm* apForm);
};

// @fnv 0x005fc420
bool TESEyes::IsNotEqual(TESForm* apCompare)
{
    TESEyes* pcomp = dynamic_cast<TESEyes*>(apCompare);
    if (pcomp == 0)
        return true;
    if (reinterpret_cast<FUN_005e79a0_t*>(this)->TESForm_CompareAllComponents(pcomp))
        return true;
    if (pcomp->IsFlagSet() !=
        this->IsFlagSet())
        return true;
    if (pcomp->IsNotFlag2Set() !=
        this->IsNotFlag2Set())
        return true;
    if (pcomp->IsFlag4Clear() !=
        this->IsFlag4Clear())
        return true;
    return false;
}

void _Deallocate(void*);
// Calls Destroy, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x005fc0f0
void* TESEyes::ReleaseIfFlagged(unsigned int flags)
{
    Destroy();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
// @fnv 0x005fc1d0
void TESEyes::SaveEyes()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    TESTexture::Save(0x4E4F4349);
    TESForm_AddChunk_3(0x41544144, cFlags);
    TESForm::FinishFormRecord();
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm* apForm);
};
// @fnv 0x005fc3a0
void TESEyes::CopyFromEyes(TESForm* apCopy)
{
    TESEyes* eyes = dynamic_cast<TESEyes*>(apCopy);
    if (!eyes)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(apCopy);
    this->SetFlag(eyes->IsFlagSet());
    this->SetMale(eyes->IsNotFlag2Set());
    this->SetFemale(eyes->IsFlag4Clear());
}

struct LH
{
    bool IsInList(TESNPC*&);
};
// @fnv 0x005fc5f0
bool TESEyes::CanBeNPC(TESNPC* npc)
{
    bool result = false;
    if (npc && npc->TESNPC_GetRace())
    {
        TESNPC* race = (TESNPC*)this;
        if (((LH*)((TESDataHandler*)npc->TESNPC_GetRace())->GetBGSRecipeCategoryList())->IsInList(race))
        {
            switch (npc->TESActorBase::GetSex())
            {
            case 0:
                if (this->IsNotFlag2Set())
                    result = true;
                break;
            case 1:
                if (this->IsFlag4Clear())
                    result = true;
                break;
            }
        }
    }
    return result;
}

// Sets or clears bit 2 of cFlags depending on aFlag: clears it when aFlag is true, sets it otherwise.
// @fnv 0x005fc550
void TESEyes::SetMale(bool aFlag)
{
    if (aFlag)
        cFlags &= ~2;
    else
        cFlags |= 2;
}

// Clears bit 4 of cFlags when aFlag is true, otherwise sets bit 4.
// @fnv 0x005fc5b0
void TESEyes::SetFemale(bool aFlag)
{
    if (aFlag)
        cFlags &= ~4;
    else
        cFlags |= 4;
}

// Loads a TESEyes record from the file, handling EDID, OBND, FULL, ICON and DATA chunks, and returns false if the record type is not 0xb.
// @fnv 0x005fc220
bool TESEyes::Load(TESFile* apFile)
{
    // GetTESForm (0x00472660): this caller compares the full EAX result; preserve its int return view.
    if ((apFile->*reinterpret_cast<int (TESFile::*)()>(&TESFile::GetTESForm))() != 0xb)
        return false;
    LoadRecordHeader(apFile);
    int chunkid;
    while ((chunkid = apFile->GetChunkID()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pEditorId, 0x200);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, apFile);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, apFile);
            break;
        case 0x41544144:
            apFile->GetChunkData(&cFlags, 1);
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}
