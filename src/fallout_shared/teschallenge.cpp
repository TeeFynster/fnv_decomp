// fallout_shared/teschallenge.cpp: TESChallenge, ChallengeManager (16 functions)

#include "../../include/SettingT.h"
#include "../../include/Stack.h"
#include "teschallenge_support.h"
#include "../../include/NiPointer.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/BGSListForm.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/ChallengeData.h"
#include "../../include/ChallengeProgress.h"
#include "../../include/MapEntryCount.h"
#include "../../include/Script.h"
#include "../../include/TESChallenge.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESDescription.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESScriptableForm.h"
#include "teschallenge_decls.h"
#include "../../include/TESQuest.h"
#include "../../include/BGSSaveFormBuffer.h"

FNV_STATIC_ASSERT(sizeof(BGSMessageIcon) == 16);
FNV_STATIC_ASSERT(offsetof(BGSMessageIcon, Icon) == 4);
FNV_STATIC_ASSERT(sizeof(ChallengeData) == 24);
FNV_STATIC_ASSERT(offsetof(ChallengeData, m_iPrimaryValue) == 0);
FNV_STATIC_ASSERT(offsetof(ChallengeData, m_iAuxiliaryValue) == 4);
FNV_STATIC_ASSERT(offsetof(ChallengeData, nFlags) == 8);
FNV_STATIC_ASSERT(offsetof(ChallengeData, m_iRecordIndex) == 12);
FNV_STATIC_ASSERT(offsetof(ChallengeData, FlaggedRecordValueEntry) == 16);
FNV_STATIC_ASSERT(offsetof(ChallengeData, RecordIndexValueData) == 18);
FNV_STATIC_ASSERT(offsetof(ChallengeData, IndexedRecordValueTriple) == 20);
FNV_STATIC_ASSERT(sizeof(ChallengeProgress) == 8);
FNV_STATIC_ASSERT(offsetof(ChallengeProgress, iProgress) == 0);
FNV_STATIC_ASSERT(offsetof(ChallengeProgress, m_iCompletionCount) == 4);
FNV_STATIC_ASSERT(sizeof(TESChallenge) == 124);
FNV_STATIC_ASSERT(offsetof(TESChallenge, data) == 84);
FNV_STATIC_ASSERT(offsetof(TESChallenge, progress) == 108);
FNV_STATIC_ASSERT(offsetof(TESChallenge, m_pPrimaryForm) == 116);
FNV_STATIC_ASSERT(offsetof(TESChallenge, m_pSecondaryForm) == 120);

// @fnv 0x005F5080
void TESChallenge::InitItem()
{
    if (GetInitialized())
        return;
    TESScriptableForm::InitItem(this);
    unsigned int formID = reinterpret_cast<unsigned int>(m_pPrimaryForm);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pPrimaryForm = GetFormByID(formID);
        if (!m_pPrimaryForm)
            Warning("MASTERFILE: Could not find Form (%08X) on challenge '%s' (%08X).", formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(m_pSecondaryForm);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pSecondaryForm = GetFormByID(formID);
        if (!m_pSecondaryForm)
            Warning("MASTERFILE: Could not find Form (%08X) on challenge '%s' (%08X).", formID, GetName(), GetFormID());
    }
    SetInitializationState(true);
}

// @fnv 0x005F57C0
void TESChallenge::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    buffer->ReadTypedData(&progress.iProgress, sizeof(progress.iProgress));
    buffer->ReadTypedData(&progress.m_iCompletionCount, sizeof(progress.m_iCompletionCount));
}

// @fnv 0x005F5950
bool ChallengeManager::UpdateChallengeProgress(CHALLENGE_TYPE type, int count, TESForm* formOne, TESForm* formTwo,
                                               unsigned short specialOne, unsigned short specialTwo,
                                               unsigned short specialThree)
{
    if (type >= CHALLENGE_TYPE_CHALLENGE_TYPE_COUNT || type < 0)
        return false;
    BSSimpleList<TESChallenge*>* list = &pChallengeList[type];
    bool completed = false;
    TESChallenge* challenge = 0;
    while (list)
    {
        challenge = list->GetItem();
        bool applicable = true;
        if (challenge)
        {
            if (challenge->GetCompleted() && !challenge->GetRecurring())
            {
                list = list->GetNext();
                continue;
            }
            if (challenge->GetStartsLocked() && !challenge->GetUnlocked())
            {
                list = list->GetNext();
                continue;
            }
            if (challenge->GetFormOne())
            {
                if (!formOne)
                    applicable = false;
                else
                {
                    switch (type)
                    {
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE_LIST: {
                        BGSListForm* formList = static_cast<BGSListForm*>(challenge->GetFormOne());
                        if (formList && !formList->GetList()->IsInList(formOne))
                            applicable = false;
                        break;
                    }
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_SPECIFIC:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_SKILL:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DAMAGE:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_CRAFT_WITH_ITEM:
                        if (formOne != challenge->GetFormOne())
                            applicable = false;
                        break;
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DISCOVER:
                        if (formOne != challenge->GetFormOne())
                            applicable = false;
                        break;
                    }
                }
            }
            if (!applicable)
            {
                list = list->GetNext();
                continue;
            }
            if (challenge->GetFormTwo())
            {
                if (!formTwo)
                    applicable = false;
                else
                {
                    switch (type)
                    {
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_SPECIFIC:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_CATEGORY:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DISCOVER:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DAMAGE: {
                        BGSListForm* formList = static_cast<BGSListForm*>(challenge->GetFormTwo());
                        if (formList && !formList->GetList()->IsInList(formTwo))
                            applicable = false;
                        break;
                    }
                    }
                }
            }
            if (!applicable)
            {
                list = list->GetNext();
                continue;
            }
            bool special = false;
            if (challenge->GetSpecialOne())
            {
                if (!specialOne)
                    applicable = false;
                if (specialOne != challenge->GetSpecialOne())
                    applicable = false;
            }
            else if (challenge->GetChallengeType() == CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT)
            {
                if (specialOne != challenge->GetSpecialOne())
                    applicable = false;
            }
            if (challenge->GetSpecialTwo())
            {
                if (!specialTwo)
                    applicable = false;
                if (specialTwo != challenge->GetSpecialTwo())
                    applicable = false;
            }
            else
            {
                switch (challenge->GetChallengeType())
                {
                case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    if (specialTwo && specialTwo != 1)
                        applicable = false;
                    break;
                }
            }
            if (challenge->GetSpecialThree())
            {
                if (!specialThree)
                    applicable = false;
                if (specialThree != challenge->GetSpecialThree())
                    applicable = false;
            }
            if (!applicable)
            {
                list = list->GetNext();
                continue;
            }
            challenge->IncrementProgress(count);
            if (challenge->GetProgressValue() >= challenge->GetThreshold())
            {
                if (challenge->GetScript())
                    challenge->GetScript()->ExecuteScript(reinterpret_cast<TESObjectREFR*>(g_thePlayer), 0);
                if (challenge->GetChallengeType() != CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT ||
                    challenge->GetSpecialOne() != 27)
                    TopicMenuController::IncrementMiscStat(27);
                if (challenge->GetFullName() && challenge->GetDescription(0, (CHUNK_ID)0x43534544) &&
                    *DAT_011cb4d4.Bool())
                {
                    char message[512];
                    sprintf_s(message, sizeof(message), "%s   %d\\%d\n%s", challenge->GetFullName(),
                              challenge->GetThreshold(), challenge->GetThreshold(),
                              challenge->GetDescription(0, (CHUNK_ID)0x43534544));
                    Interface::ShowMessage(message, 0, TESTexture::GetTextureResourceName(challenge, 0), 0,
                                           DAT_010162c0, false);
                    Interface::PlayUISound(21);
                }
                if (challenge->GetRecurring() && !challenge->GetRemovedRecurring())
                {
                    int excess = challenge->GetProgressValue() - challenge->GetThreshold();
                    challenge->ClearProgress();
                    challenge->SetCompletedRecurring(true);
                    challenge->IncrementProgress(excess);
                }
                else
                {
                    challenge->MarkCompleted(true);
                    completed = true;
                }
            }
            else
            {
                struct ProgressInterval
                {
                    int interval;
                    int progress;
                } values;
                values.progress = challenge->GetProgressValue();
                values.interval = challenge->GetInterval() ? challenge->GetInterval() : 100;
                for (int value = values.progress; value >= 0; value -= values.interval)
                {
                    if (value == 0)
                    {
                        if (challenge->GetFullName() && challenge->GetDescription(0, (CHUNK_ID)0x43534544) &&
                            *DAT_011cb4d4.Bool())
                        {
                            char message[512];
                            sprintf_s(message, sizeof(message), "%s   %d\\%d\n%s", challenge->GetFullName(),
                                      challenge->GetProgressValue(), challenge->GetThreshold(),
                                      challenge->GetDescription(0, (CHUNK_ID)0x43534544));
                            Interface::ShowMessage(message, 0, TESTexture::GetTextureResourceName(challenge, 0),
                                                   0, DAT_010162c0, false);
                        }
                    }
                }
            }
        }
        list = list->GetNext();
    }
    if (completed)
        CheckCompletedChallenges();
    return true;
}

// @fnv 0x005F51A0
bool TESChallenge::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    CHUNK_ID chunk;
    while (chunk = (CHUNK_ID)file->GetChunkID())
    {
        switch (chunk)
        {
        case (CHUNK_ID)0x44494445: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case (CHUNK_ID)0x444e424f:
            readOBNDSubRecord(file);
            break;
        case (CHUNK_ID)0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case (CHUNK_ID)0x4e4f4349:
            TESTexture::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case (CHUNK_ID)0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case (CHUNK_ID)0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case (CHUNK_ID)0x43534544:
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case (CHUNK_ID)0x41544144:
            ReadTypedData(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.SwapEndianFields();
            break;
        case (CHUNK_ID)0x4d414e53: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            SetFormOne(reinterpret_cast<TESForm*>(formID));
            break;
        }
        case (CHUNK_ID)0x4d414e58: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            SetFormTwo(reinterpret_cast<TESForm*>(formID));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x005F5880
void ChallengeManager::CheckCompletedChallenges()
{
    Clear();
    BSSimpleList<TESChallenge*>* list = g_dataHandler->FUN_00461150();
    TESChallenge* challenge = 0;
    while (list)
    {
        challenge = list->GetItem();
        if (challenge && !challenge->GetCompleted() && (!challenge->GetStartsLocked() || challenge->GetUnlocked()))
            pChallengeList[challenge->GetChallengeType()].AddHead(challenge);
        else if (challenge)
            ms_kInactiveChallengesByType[challenge->GetChallengeType()].AddHead(challenge);
        list = list->GetNext();
    }
}

// @fnv 0x005F4FD0
void TESChallenge::ResetFormData()
{
    memset(&data, 0, sizeof(data));
    memset(&progress, 0, sizeof(progress));
    m_pPrimaryForm = 0;
    m_pSecondaryForm = 0;
    SetShowZero(true);
}

// Sets or clears bit 2 of data.nFlags according to show.
// @fnv 0x005f5020
void TESChallenge::SetShowZero(bool show)
{
    !show ? data.nFlags &= ~4 : data.nFlags |= 4;
}

// Clears all 14 entries by calling RemoveAll on both parallel arrays.
// @fnv 0x005f5840
void ChallengeManager::Clear()
{
    for (int i = 0; i < 14; ++i)
    {
        pChallengeList[i].RemoveAll();
        ms_kInactiveChallengesByType[i].RemoveAll();
    }
}

// @fnv 0x005f5800
void TESChallenge::MarkForSave()
{
    MarkAsModified(2);
}

// @fnv 0x005f5930
int TESChallenge::GetStartsLocked()
{
    return data.nFlags & 1;
}

// @fnv 0x005f4e00
TESChallenge::TESChallenge()
{
    TESChallenge::ResetFormData();
    SetFormType((ENUM_FORM_ID)0x71);
}

// TESForm's legacy I/O at 0x00484c20/0x00484c50/0x00484d60 has no matching shared signatures; inherit its checked layout.
struct ChallengeLegacyFormIO : TESForm
{
    void SaveChangeFlags(unsigned int flags);
    void LoadChangeFlags(unsigned int flags, unsigned int currentFlags);
    void SaveIfChanged(BGSSaveFormBuffer* buffer);
};

// @fnv 0x005a7770
// src: XBOX_PDB 0x005a7770
unsigned short __thiscall TESChallenge::TESCaravanCard_GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += static_cast<unsigned short>(TESForm::GetSaveSize(aiFlags));
    return isize;
}


// @fnv 0x005f5820
void TESChallenge::ClearProgress()
{
    progress.iProgress = 0;
}

// @fnv 0x0059adb0
// src: XBOX_PDB 0x0059adb0
void __thiscall TESChallenge::TESCaravanCard_SaveGame(unsigned int aiFlags)
{
    reinterpret_cast<ChallengeLegacyFormIO*>(this)->SaveChangeFlags(aiFlags);
}

// @fnv 0x00616640
// src: XBOX_PDB 0x00616640
void __thiscall TESChallenge::TESCaravanCard_LoadGame(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<ChallengeLegacyFormIO*>(this)->LoadChangeFlags(aiFlags, aiCurrentFlags);
}


extern "C" int _memcmp(const void*, const void*, unsigned int);


// Compares this TESChallenge against apCompare: returns true if it is not a TESChallenge or if data, form two, form one or the base comparison differ.
// @fnv 0x005f56b0
bool __thiscall TESChallenge::Compare(TESForm* apCompare)
{
    TESChallenge* pcomp = dynamic_cast<TESChallenge*>(apCompare);
    if (!pcomp)
        return true;
    if (_memcmp(&this->data, ((TESQuest*)pcomp)->GetConditions(), 0x18) != 0)
        return true;
    if (this->GetFormTwo() != pcomp->GetFormTwo())
        return true;
    if (this->GetFormOne() != pcomp->GetFormOne())
        return true;
    if (TESForm::Compare(pcomp))
        return true;
    return false;
}

bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
// @fnv 0x005f5540
void __thiscall TESChallenge::Initialize()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    TESIcon::Save(0x4e4f4349);
    BGSMessageIcon::Save(0x4f43494d);
    TESScriptableForm::Save_0048cca0();
    TESDescription::Save_00482cb0();
    if (TESForm_QEndianSwapOnSave())
        ((ChallengeData*)((char*)this + 0x54))->SwapEndianFields();
    TESForm::TESForm___SaveData(&data, 0x18);
    if (TESForm_QEndianSwapOnSave())
        ((ChallengeData*)((char*)this + 0x54))->SwapEndianFields();
    if (*(unsigned int*)((char*)this + 0x74))
    {
        unsigned int v1 = ((TESForm**)((char*)this + 0x74))[0]->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e53, v1);
    }
    if (*(unsigned int*)((char*)this + 0x78))
    {
        unsigned int v2 = ((TESForm**)((char*)this + 0x78))[0]->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e58, v2);
    }
    TESForm::FinishFormRecord();
}


void* __cdecl memcpy(void* dest, const void* src, unsigned int size);


// Copies the TESChallenge data block and both forms from apCopy into this challenge, then calls FUN_004851b0 with apCopy.
// @fnv 0x005f5630
void __thiscall TESChallenge::CopyFromChallenge(TESForm* apCopy)
{
    TESChallenge* challenge = dynamic_cast<TESChallenge*>(apCopy);
    if (!challenge)
        return;
    memcpy(&this->data, &challenge->data, sizeof(ChallengeData));
    this->SetFormOne(challenge->GetFormOne());
    this->SetFormTwo(challenge->GetFormTwo());
    TESForm::CopyFrom(apCopy);
}

// Calls the base save routine, then writes the 4-byte values at offsets 0x6C and 0x70 into the save buffer.
// @fnv 0x005f5780
// src: XBOX_PDB 0x005f5780
void __thiscall TESChallenge::SaveGame_005f5780(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<ChallengeLegacyFormIO*>(this)->SaveIfChanged(apBuffer);
    apBuffer->SaveData((char*)this + 0x6C, 4, 0);
    apBuffer->SaveData((char*)this + 0x70, 4, 0);
}

struct BSIntToType1
{
    char c;
};
struct BSIntToType10
{
    char c;
};
struct BSIntToType2
{
    char c;
};
struct BSIntToType4
{
    char c;
};
struct BSIntToType8
{
    char c;
};
struct BSIntToType16
{
    char c;
};
struct BSIntToType32
{
    char c;
};
void __cdecl BSEndian(unsigned char*, BSIntToType1);
void __cdecl BSEndian(unsigned char*, BSIntToType10);
void __cdecl BSEndian(unsigned char*, BSIntToType2);
void __cdecl BSEndian(unsigned char*, BSIntToType4);
void __cdecl BSEndian(unsigned char*, BSIntToType8);
void __cdecl BSEndian(unsigned char*, BSIntToType16);
void __cdecl BSEndian(unsigned char*, BSIntToType32);


// Byte-swaps the fields at offsets 0, 4, 8, 12, 16, 18 and 20 of this object to the opposite endianness.
// @fnv 0x005f5480
void __thiscall ChallengeData::SwapEndianFields()
{
    BSEndian((unsigned char*)this, BSIntToType1());
    BSEndian((unsigned char*)this + 4, BSIntToType10());
    BSEndian((unsigned char*)this + 8, BSIntToType2());
    BSEndian((unsigned char*)this + 12, BSIntToType4());
    BSEndian((unsigned char*)this + 16, BSIntToType8());
    BSEndian((unsigned char*)this + 18, BSIntToType16());
    BSEndian((unsigned char*)this + 20, BSIntToType32());
}

// @fnv 0x005f4f10
TESChallenge::~TESChallenge()
{
    TESForm::ClearData();
}
