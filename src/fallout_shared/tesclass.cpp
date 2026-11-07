// fallout_shared/tesclass.cpp: TESClass and class-data operations (15 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "layout_support.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSImpactData.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESClass.h"
#include "../../include/TESClassData.h"
#include "../../include/TESDescription.h"
#include "../../include/TESFullName.h"
#include "../../include/TESTexture.h"
#include "TESFile.h"
#include "../../include/TESFile.h"
#include "../../include/ActorValue.h"
namespace ActorValue {
bool IsSkill(Index);
}
class LegacyActorBaseData
{
  public:
    ActorValue::Index skills[3];
    char flags;
    int services;
    unsigned char trainingSkill, trainingLevel;
    void SwapEndianData();
};
extern "C" void* __cdecl memset(void*, int, unsigned int);

extern "C" void* __cdecl _alloca(unsigned int);
int __cdecl Warning(const char*, ...);
// TESFileFormInt_tesclass: local type (was include/TESFileFormInt.h, which had no evidence of one real class); its methods are 0x00472660 TESFile::GetTESForm
class TESFileFormInt_tesclass
{
public:
    int GetTESForm();
};
// Stores skill into data.m_aeTaggedSkills[index] and marks the class modified when skill is a skill or ActorValue__Index_VALUE_NONE.
// @fnv 0x005f6e80
void TESClass::SetClassSkillAtIndex(int index, ActorValue::Index skill)
{
    if (ActorValue::IsSkill(skill) || skill == ActorValue::ActorValue__Index_VALUE_NONE)
    {
        data.m_aeTaggedSkills[index] = skill;
        MarkAsModified(2);
    }
}
// Clears the 28-byte data block and sets all four actor value slots to ActorValue::ActorValue__Index_VALUE_NONE.
// @fnv 0x005f67c0
void TESClass::ResetFormData()
{
    memset(&data, 0, 28);
    for (int i = 0; i < 4; ++i)
        SetClassSkillAtIndex(i, ActorValue::ActorValue__Index_VALUE_NONE);
}
// Loads the base form data, then reads four skill values from the buffer when change flag 2 is set.
// @fnv 0x005f71c0
void TESClass::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (buffer->GetChangeFlags(2u).operator bool())
    {
        for (unsigned int i = 0; i < 4; ++i)
            buffer->ReadTypedData(static_cast<void*>(&data.m_aeTaggedSkills[i]), 4u);
    }
}
// Reads a TESClass record from the file, handling EDID, OBND, FULL, DESC, ICON, DATA and ATTR chunks, then warns if the class data is invalid.
// @fnv 0x005f6930
bool TESClass::Load(TESFile* file)
{
    if (((TESFileFormInt_tesclass*)file)->GetTESForm() != 7)
        return false;
    LoadRecordHeader(file);
    int chunk;
    while (chunk = file->GetChunkID())
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
        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x41544144:
            if (file->GetChunkSize() == GetDataSizeAdjustment() + 28)
            {
                ((BGSImpactData*)this)->ReadTypedData(file, &data, 28);
                if (file->IsEndianConversionRequired())
                    data.SwapEndian();
            }
            else if (file->GetChunkSize() == 24 || file->GetChunkSize() == GetDataSizeAdjustment() + 24)
            {
                LegacyActorBaseData oldData;
                if (file->GetChunkSize() == GetDataSizeAdjustment() + 24)
                    ((BGSImpactData*)this)->ReadTypedData(file, &oldData, 24);
                else
                    file->GetChunkData(&oldData, 24);
                if (file->IsEndianConversionRequired())
                    oldData.SwapEndianData();
                data.m_ucClassFlags = oldData.flags;
                data.m_uiField08 = oldData.services;
                data.m_ucField0D = oldData.trainingLevel;
                data.m_ucField0C = oldData.trainingSkill;
                for (int i = 0; i < 3; ++i)
                    data.m_aeTaggedSkills[i] = oldData.skills[i];
            }
            else
            {
                file->GetChunkData(&data, 28);
                if (file->IsEndianConversionRequired())
                    data.SwapEndian();
            }
            break;
        case 0x52545441: {
            unsigned char attributes[7];
            file->GetChunkData(attributes, 7);
            TESAttributes::Load(attributes);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    if (!ValidateSkillActorValue())
        Warning("MASTERFILE: Class %s contains invalid data. Make sure all attributes and skills are unique",
                GetName());
    return true;
}

// @fnv 0x005f6e20
bool TESClass::ValidateSkillActorValue()
{
    bool bIsSkill = true;
    if (!ActorValue::IsSkill(static_cast<ActorValue::Index>(GetTrainingSkill())))
    {
        SetTrainingSkill(static_cast<ActorValue::Index>(0x20));
        bIsSkill = false;
    }
    return bIsSkill;
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<4>);
void __cdecl BSEndian(int*, EndianSizeTag<3>);
void __cdecl BSEndian(float*, EndianSizeTag<3>);

// Byte-swaps the four 3-byte values at the start of this object and the 4-byte value at offset 0x14.
// @fnv 0x005f68d0
void TESClassData::SwapEndian()
{
    BSEndian(&m_uiField08, EndianSizeTag<4>());
    for (int i = 0; i < 4; ++i)
        BSEndian(reinterpret_cast<int*>(&m_aeTaggedSkills[i]), EndianSizeTag<3>());
}

namespace fnv_005f6c90 {
template <int N> class EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<3>);

struct FUN_005f6c90_shell
{
    int m_data[4];
    void SwapEndianData();
};

// @fnv 0x005f6c90
void FUN_005f6c90_shell::SwapEndianData()
{
    BSEndian(&m_data[4], EndianSizeTag<3>());
    for (int i = 0; i < 3; ++i)
    {
        BSEndian(&m_data[i], EndianSizeTag<3>());
    }
}
}  // namespace fnv_005f6c90

// @fnv 0x005f6dd0
int TESClass::GetTrainingSkill()
{
    int result = data.m_ucField0C + 0x20;
    return result;
}

// If index is a skill, stores index minus 0x20 into the byte at offset 0x5c of this object.
// @fnv 0x005f6df0
void TESClass::SetTrainingSkill(ActorValue::Index aeSkillIndex)
{
    if (ActorValue::IsSkill(aeSkillIndex))
    {
        data.m_ucField0C = (unsigned char)(aeSkillIndex - 0x20);
    }
}

// @fnv 0x005f7150
void __thiscall TESClass::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int i;
    TESForm::SaveGame(apSaveGameBuffer);
    if (((BGSLoadFormBuffer*)apSaveGameBuffer)->GetChangeFlags(2u).operator bool())
    {
        for (i = 0; i < 4; ++i)
        {
            apSaveGameBuffer->SaveData(&data.m_aeTaggedSkills[i], 4, 0);
        }
    }
}

extern "C"
{
    unsigned char __cdecl _FUN_00401500();
}

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
void __cdecl _FUN_00485990(unsigned int, void*, unsigned int);

// @fnv 0x005f6810
void __thiscall TESClass::SaveForm(void)
{
    char cAttribData[7];
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    TESDescription::Save_00482cb0();
    TESTexture::Save(0x4e4f4349);
    if (_FUN_00401500())
    {
        data.SwapEndian();
    }
    _FUN_00485990(0x41544144, &data, 0x1c);
    if (_FUN_00401500())
    {
        data.SwapEndian();
    }
    TESAttributes::Save(cAttribData);
    TESForm_AddChunkArray(0x52545441, cAttribData, 7);
    TESForm::FinishFormRecord();
}

void __cdecl _Deallocate(void*);
// Destroys the class, frees it when flags has bit 1 set, and returns its address.
// @fnv 0x005f66e0
void* TESClass::DestroyIfFlagged(unsigned int flags)
{
    this->TESClass::~TESClass();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void* __memcpy(void*, const void*, unsigned int);
// @fnv 0x005f6d70
void TESClass::CopyFromTESClass(TESForm* apCopy)
{
    TESClass* cl = dynamic_cast<TESClass*>(apCopy);
    if (!cl)
        return;
    TESForm_CopyAllComponents(apCopy);
    __memcpy(&data, cl->GetClassData(), 0x1c);
}

// Tears down the class component bases.
// @fnv 0x005f6710
TESClass::~TESClass()
{}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);

// Returns true if the cast fails, FUN_00485270 returns true, or the two TESClassData byte ranges differ.
// @fnv 0x005f6cf0
bool TESClass::CompareClass(TESForm* other)
{
    TESClass* pClass = dynamic_cast<TESClass*>(other);
    if (!pClass)
        return true;
    if (TESForm_CompareAllComponents(pClass))
        return true;
    if (_memcmp(&data, pClass->GetClassData(), sizeof(TESClassData)))
        return true;
    return false;
}
