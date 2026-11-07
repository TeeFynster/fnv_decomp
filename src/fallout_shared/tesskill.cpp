
// src/fallout_shared/tesskill.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesskill.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/TESDescription.h"
#include "../../include/TESForm.h"
#include "../../include/TESFile.h"
#include "../../include/TESSkill.h"
#include "../../include/TESRegion.h"
#include "../../include/TESTexture.h"

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<3>);

struct SkillData
{
    int m0;
    int m4;
    int m8;
    int m12;
    int m16;
    void __thiscall SwapEndian();
};

// Byte-swaps the five int fields m0, m4, m8 and the two ints at m12 via BSEndian.
// @fnv 0x006180a0
void __thiscall SkillData::SwapEndian()
{
    BSEndian(&m0, EndianSizeTag<3>());
    BSEndian(&m4, EndianSizeTag<3>());
    BSEndian(&m8, EndianSizeTag<3>());
    for (int i = 0; i < 2; ++i)
    {
        BSEndian(&m12 + i, EndianSizeTag<3>());
    }
}

bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
// @fnv 0x00485910
// src: XBOX_PDB 0x00485910
void __cdecl TESForm_AddChunk_00485910(unsigned int a, int aiValue)
{
    if (TESForm_QEndianSwapOnSave())
        BSEndian(&aiValue, EndianSizeTag<3>());
    AppendChunk(a, &aiValue, 4);
}

void __cdecl Deallocate(void*);

// Calls FUN_00617f40, then if flags has bit 1 set deallocates this and returns this.
// @fnv 0x00617e50
void* __thiscall TESSkill::DeleteThis(unsigned int flags)
{
    TESSkill::~TESSkill();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// @fnv 0x00617ea0
void __thiscall TESSkill::InitializeComponent()
{
    *(int*)((char*)this + 0x2c) = -1;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x30) = 5;
    int iIndex = 0;
    for (; iIndex < 2; ++iIndex)
        *(float*)((char*)this + 0x38 + iIndex * 4) = 1.0f;
    int iSlot = 0;
    for (; iSlot < 4; ++iSlot)
        ((void(__thiscall*)(void*))(*(int**)((char*)this + 0x40 + iSlot * 8))[0])((char*)this + 0x40 + iSlot * 8);
    ((void(__thiscall*)(void*, int))(*(int**)((char*)this + 0x00))[0x32])((char*)this, 0);
    ClearSourceFiles();
}

namespace fnv_00617fc0 {
void __cdecl TESForm_AddChunk_00485910(int, int);
void __cdecl WriteDescChunk(void*, int);
int __cdecl TESForm_QEndianSwapOnSave();
}  // namespace fnv_00617fc0

// @fnv 0x00617fc0
void __thiscall TESSkill::SaveForm()
{
    ((TESForm*)this)->BeginFormRecord();
    fnv_00617fc0::TESForm_AddChunk_00485910(0x58444e49, *(int*)((char*)this + 0x2c));
    ((TESDescription*)((char*)this + 0x18))->Save();
    ((TESTexture*)((char*)this + 0x20))->Save(0x4e4f4349);
    if ((unsigned char)fnv_00617fc0::TESForm_QEndianSwapOnSave())
        ((SkillData*)((char*)this + 0x2c))->SwapEndian();
    ((TESForm*)this)->TESForm___SaveData((char*)this + 0x2c, 0x14);
    if ((unsigned char)fnv_00617fc0::TESForm_QEndianSwapOnSave())
        ((SkillData*)((char*)this + 0x2c))->SwapEndian();
    fnv_00617fc0::WriteDescChunk((char*)this + 0x40, 0x4d414e41);
    fnv_00617fc0::WriteDescChunk((char*)this + 0x48, 0x4d414e4a);
    fnv_00617fc0::WriteDescChunk((char*)this + 0x50, 0x4d414e45);
    fnv_00617fc0::WriteDescChunk((char*)this + 0x58, 0x4d414e4d);
    ((TESForm*)this)->FinishFormRecord();
}

extern "C" void* __cdecl _alloca(unsigned int);

// Reads a skill record from apFile: checks the record type, loads the base form, then dispatches each chunk to its handler until the file ends.
// @fnv 0x00618130
bool TESSkill::LoadForm(TESFile* apFile)
{
    int chunkID;

    // This caller compares the full EAX result, as in the original game.
    if ((apFile->*reinterpret_cast<int (__thiscall TESFile::*)()>(&TESFile::GetTESForm))() != 0x0F)
        return false;

    this->FUN_00485110(apFile);

    while ((chunkID = apFile->TESFile_GetTESChunk()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* pMessage = static_cast<char*>(_alloca(apFile->GetChunkSize()));
            apFile->FUN_00472890(pMessage, 0x200);
            this->SetEditorID_AtRuntime(pMessage);
            break;
        }

        case 0x444E424F:
            this->readOBNDSubRecord(apFile);
            break;

        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(
                this ? reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x18) : 0, apFile);
            break;

        case 0x4E4F4349:
            TESTexture::ReadTextureData(this ? reinterpret_cast<TESTexture*>(reinterpret_cast<char*>(this) + 0x20) : 0,
                                        apFile);
            break;

        case 0x41544144:
            this->ReadTypedData(apFile, reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x2C), 0x14);
            break;

        case 0x4D414E41:
            TESDescription::ReadDescriptionFromFile(
                reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x40), apFile);
            break;

        case 0x4D414E4A:
            TESDescription::ReadDescriptionFromFile(
                reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x48), apFile);
            break;

        case 0x4D414E45:
            TESDescription::ReadDescriptionFromFile(
                reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x50), apFile);
            break;

        case 0x4D414E4D:
            TESDescription::ReadDescriptionFromFile(
                reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(this) + 0x58), apFile);
            break;

        default:
            break;
        }

        if (chunkID == 0x41544144 && apFile->GetChunkData())
        {
            reinterpret_cast<SkillData*>(reinterpret_cast<char*>(this) + 0x2C)->SwapEndian();
        }

        if (!apFile->FUN_004726f0())
            break;
    }

    return true;
}

extern char DAT_01186518, DAT_01183028;
void* FUN_00ec43fb(void*, int, void*, void*, int);
void FUN_00401460(void*, const void*, unsigned int);
// Copies skill data and descriptions after resolving pOther.
// @fnv 0x00618390
void TESSkill::CopyFrom(const TESForm* pOther)
{
    TESSkill* pSource = (TESSkill*)FUN_00ec43fb((void*)pOther, 0, &DAT_01183028, &DAT_01186518, 0);
    if (!pSource)
        return;
    TESForm::CopyFrom(pOther);
    FUN_00401460(formData, pSource->formData, 0x14);
    for (int i = 0; i < 4; i++)
        reinterpret_cast<TESDescription*>(formData + 0x14)[i].CopyFromBase(
            static_cast<BaseFormComponent*>(&reinterpret_cast<TESDescription*>(pSource->formData + 0x14)[i]));
}

int __cdecl _memcmp(const void*, const void*, unsigned int);

// @fnv 0x00618430
bool TESSkill::Compare(TESForm* apCompare)
{
    TESSkill* pOther = dynamic_cast<TESSkill*>(apCompare);
    if (!pOther)
    {
        return true;
    }

    if (TESForm::Compare(reinterpret_cast<TESForm*>(pOther)))
    {
        return true;
    }

    if (_memcmp(formData, reinterpret_cast<TESRegion*>(pOther)->GetDiffuseColor(), 0x14) != 0)
    {
        return true;
    }

    {
        int i;
        for (i = 0; i < 4; ++i)
        {
            if (reinterpret_cast<TESDescription*>(formData + 0x14)[i].CompareWithBase(
                    static_cast<BaseFormComponent*>(&reinterpret_cast<TESDescription*>(pOther->formData + 0x14)[i])))
            {
                return true;
            }
        }
    }

    return false;
}
