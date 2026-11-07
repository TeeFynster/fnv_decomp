// fallout_shared/bgsnote.cpp: BGSNote and note serialization operations (25 functions)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

#include "../../include/BGSNote.h"
#include "../../include/BSSimpleList.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESModel.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/MagicTarget.h"
#include "../../include/TESDescription.h"
#include "../../include/TESTexture.h"
#include "../../include/TESQuest.h"
#include "../../include/TESSound.h"
#include "../../include/TESTopic.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESFile.h"
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/FormChangeMask.h"
#include "../../include/BGSPickupPutdownSounds.h"

// 0x00472660 is compared as a full ENUM_FORM_ID here; TESFile's shared declaration returns a byte.
class RecordFormTypeReader
{
  public:
    ENUM_FORM_ID GetTESForm();
};

int Warning(const char*, ...);
template <class T> struct BGSNoteReference
{
    unsigned int id;
    T* form;
};
bool __cdecl IsChunkTypeIcon(int);
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

// @fnv 0x005e8240
void BGSNote::ResetFormData()
{
    cType = 0;
    m_pText = 0;
    m_pDialogueSpeaker = 0;
    m_bIsRead = false;
}

// Returns the note's TESDescription when GetNoteType reports 1, otherwise returns null.
// @fnv 0x005e91d0
TESDescription* BGSNote::GetNoteDescription()
{
    if (GetNoteType() == 1)
        return (TESDescription*)m_pText;
    return 0;
}

// @fnv 0x005e8060
BGSNote::BGSNote()
{
    SetFormType(ENUM_FORM_ID_NOTE_ID);
    ResetFormData();
}

// If type differs from cType, deletes the current TESDescription or TESTexture, stores the new type, and allocates the matching object.
// @fnv 0x005e8f90
void BGSNote::ChangeNoteType(NOTE_TYPE type)
{
    if (type != cType)
    {
        switch (cType)
        {
        case 1:
            delete (TESDescription*)m_pText;
            m_pText = 0;
            break;
        case 2:
            delete (TESTexture*)m_pText;
            m_pText = 0;
            break;
        }
        cType = (signed char)type;
        switch (cType)
        {
        case 1:
            m_pText = new TESDescription;
            break;
        case 2:
            m_pText = new TESTexture;
            break;
        }
    }
}

// @fnv 0x005e8900
void BGSNote::InitItem()
{
    if (GetInitialized())
        return;
    BSSimpleList<TESQuest*>* current = &ownerQuests;
    BSSimpleList<TESQuest*>* previous = 0;
    while (current && !current->IsEmpty())
    {
        BGSNoteReference<TESQuest> noteRef;
        noteRef.id = (unsigned int)current->GetItem();
        RemapFormIDForFile(noteRef.id, GetFile(-1));
        noteRef.form = dynamic_cast<TESQuest*>(GetFormByID(noteRef.id));
        if (noteRef.form)
        {
            current->SetItem(noteRef.form);
            previous = current;
            current = current->GetNext();
        }
        else
        {
            Warning("MASTERFILE: Unable to find owner quest (%08X) for Note '%s' (%08X).", noteRef.id, GetName(),
                    GetFormID());
            if (previous)
            {
                previous->Remove(current->GetItem());
                current = previous->GetNext();
            }
            else
                current->RemoveHead();
        }
    }
    if (GetNoteSound())
    {
        BGSNoteReference<TESSound> noteRef;
        noteRef.id = (unsigned int)GetNoteSound();
        RemapFormIDForFile(noteRef.id, GetFile(-1));
        noteRef.form = dynamic_cast<TESSound*>(GetFormByID(noteRef.id));
        SetNoteSound(noteRef.form);
        if (!noteRef.form)
            Warning("MASTERFILE: Unable to find sound (%08X) for Note '%s' (%08X).", noteRef.id, GetName(),
                    GetFormID());
    }
    if (GetNoteTopic())
    {
        BGSNoteReference<TESTopic> noteRef;
        noteRef.id = (unsigned int)GetNoteTopic();
        RemapFormIDForFile(noteRef.id, GetFile(-1));
        noteRef.form = dynamic_cast<TESTopic*>(GetFormByID(noteRef.id));
        SetNoteTopic(noteRef.form);
        if (!noteRef.form)
            Warning("MASTERFILE: Unable to find topic (%08X) for Note '%s' (%08X).", noteRef.id, GetName(),
                    GetFormID());
    }
    if (GetNoteSpeaker())
    {
        BGSNoteReference<TESActorBase> noteRef;
        noteRef.id = (unsigned int)GetNoteSpeaker();
        RemapFormIDForFile(noteRef.id, GetFile(-1));
        noteRef.form = dynamic_cast<TESActorBase*>(GetFormByID(noteRef.id));
        SetNoteSpeaker(noteRef.form);
        if (!noteRef.form)
            Warning("MASTERFILE: Unable to find actor base (%08X) for Note '%s' (%08X).", noteRef.id, GetName(),
                    GetFormID());
    }
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Reads a NOTE record's chunks from the file, dispatching editor ID, bounds, full name, model, texture, sounds, type, owner quests and type-specific chunks.
// @fnv 0x005e84e0
bool BGSNote::Load(TESFile* file)
{
    if (reinterpret_cast<RecordFormTypeReader*>(file)->GetTESForm() != ENUM_FORM_ID_NOTE_ID)
        return false;
    LoadRecordHeader(file);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
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
            TESModel::LoadModelData(this, file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4d414e59: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            SetPickupSound((TESSound*)id);
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            SetPutdownSound((TESSound*)id);
            break;
        }
        case 0x41544144: {
            unsigned char type = 0;
            file->GetChunkData(&type, 1);
            ChangeNoteType((NOTE_TYPE)type);
            break;
        }
        case 0x4d414e4f: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            ownerQuests.AddHead((TESQuest*)id);
            break;
        }
        case 0x4d414e58: {
            unsigned int size = file->GetChunkSize();
            if (size)
            {
                char* name = (char*)_alloca(size);
                file->GetChunkData(name, size);
                if (GetNoteTexture())
                    GetNoteTexture()->AssignTextureName(name);
            }
            break;
        }
        default:
            switch (cType)
            {
            case 0:
                if (chunk == 0x4d414e53)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    SetNoteSound((TESSound*)id);
                }
                break;
            case 1:
                if (chunk == 0x4d414e54)
                {
                    TESDescription* description = GetNoteDescription();
                    if (description)
                        TESDescription::ReadDescriptionFromFile(description, file);
                }
                break;
            case 2:
                if (IsChunkTypeIcon(chunk))
                {
                    TESTexture* texture = GetNoteTexture();
                    if (texture)
                        TESTexture::ReadTextureData(texture, file);
                }
                break;
            case 3:
                if (chunk == 0x4d414e53)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    SetNoteSpeaker((TESActorBase*)id);
                }
                else if (chunk == 0x4d414e54)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    SetNoteTopic((TESTopic*)id);
                }
                break;
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}


// @fnv 0x005e8d40
int BGSNote::GetNoteType()
{
    return cType;
}

// Returns the note's sound if its type is NT_SOUND, otherwise returns null.
// @fnv 0x005e9100
// src: XBOX_PDB 0x005e9100
TESSound* BGSNote::GetNoteSound()
{
    if (GetNoteType() == NT_SOUND)
        return (TESSound*)m_pText;
    return 0;
}

// Returns the note texture if the note type is NT_IMAGE, otherwise returns null.
// @fnv 0x005e9160
TESTexture* BGSNote::GetNoteTexture()
{
    if (GetNoteType() == NT_IMAGE)
        return (TESTexture*)m_pText;
    return 0;
}

// Returns the stored topic when GetNoteType() equals 3, otherwise returns null.
// @fnv 0x005e9240
// src: XBOX_PDB 0x005e9240
TESTopic* BGSNote::GetNoteTopic()
{
    if (GetNoteType() == 3)
        return (TESTopic*)m_pText;
    return 0;
}


// @fnv 0x005e9270
void BGSNote::SetNoteTopic(TESTopic* apTopic)
{
    if (GetNoteType() == 3)
        m_pText = apTopic;
}

// Returns the stored TESActorBase pointer when GetNoteType() equals 3, otherwise returns null.
// @fnv 0x005e92a0
// src: XBOX_PDB 0x005e92a0
TESActorBase* BGSNote::GetNoteSpeaker()
{
    if (GetNoteType() == 3)
        return (TESActorBase*)m_pDialogueSpeaker;
    return 0;
}


// If GetNoteType() returns 3, stores apSpeaker into a field.
// @fnv 0x005e92d0
void BGSNote::SetNoteSpeaker(TESActorBase* apSpeaker)
{
    if (GetNoteType() == 3)
        m_pDialogueSpeaker = apSpeaker;
}


// Stores the sound when the note type is NT_SOUND.
// @fnv 0x005e9130
void BGSNote::SetNoteSound(TESSound* sound)
{
    if (GetNoteType() == 0)
        m_pText = sound;
}

void _Deallocate(void*);
// Runs the note destructor, frees this when flags has bit 1 set, and returns this.
// @fnv 0x005e8140
void* BGSNote::Release(unsigned int flags)
{
    this->BGSNote::~BGSNote();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x005e9190
void BGSNote::SetNoteTexture(TESTexture* texture)
{
    if (GetNoteType() == 2)
        ((TESTexture*)m_pText)->CopyFromBase((BaseFormComponent*)texture);
}

// @fnv 0x005e9200
void BGSNote::SetNoteText(TESDescription* text)
{
    if (GetNoteType() == 1)
        ((TESDescription*)m_pText)->CopyFromBase((BaseFormComponent*)text);
}

// @fnv 0x005e9480
void BGSNote::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::LoadGame(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags(0x80000000).operator bool())
        m_bIsRead = true;
}

// @fnv 0x005e94d0
void BGSNote::Revert(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert(apLoadGameBuffer);
    if (apLoadGameBuffer->GetOldChangeFlags(0x80000000).operator bool())
        m_bIsRead = false;
}

// @fnv 0x005e9300
void BGSNote::SetSoundNotePlayed(bool abRead)
{
    if (m_bIsRead == abRead)
        return;
    m_bIsRead = abRead;
    if (m_bIsRead)
        MarkAsModified(0x80000000);
    else
        MarkAsUnmodified(0x80000000);
}

// @fnv 0x005e8170
BGSNote::~BGSNote()
{
    ClearNoteData();
}

// @fnv 0x005e8270
void BGSNote::ClearNoteData()
{
    ownerQuests.RemoveAll();
    switch ((unsigned char)cType)
    {
    case 1:
        delete (TESDescription*)m_pText;
        m_pText = 0;
        break;
    case 2:
        delete (TESTexture*)m_pText;
        m_pText = 0;
        break;
    }
}

void SaveByteChunk(unsigned int, unsigned char);
void SaveIntChunk(unsigned int, unsigned int);
void SaveDataChunk(unsigned int, const void*, unsigned int);
void SaveDescriptionChunk(void*, unsigned int);

// @fnv 0x005e8300
void BGSNote::SaveNote()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    TESModel::WriteToBuffer(0x4c444f4d, 0x54444f4d);
    TESTexture::Save(0x4e4f4349);
    BGSPickupPutdownSounds::SavePickupChunk();
    SaveByteChunk(0x41544144, cType);
    BSSimpleList<TESQuest*>* pNode = GetOwnerQuests();
    while (pNode && !pNode->IsEmpty())
    {
        TESQuest* pOwner = pNode->GetItem();
        unsigned int uiOwnerQuestID = pOwner->GetFormID();
        SaveIntChunk(0x4d414e4f, uiOwnerQuestID);
        pNode = pNode->GetNext();
    }
    switch (cType)
    {
    case 0: {
        TESSound* SoundAssetTmp = GetNoteSound();
        if (SoundAssetTmp)
        {
            unsigned int uiSoundID = SoundAssetTmp->GetFormID();
            SaveIntChunk(0x4d414e53, uiSoundID);
        }
        break;
    }
    case 1: {
        void* pText = GetNoteDescription();
        if (pText)
            SaveDescriptionChunk(pText, 0x4d414e54);
        break;
    }
    case 2: {
        TESTexture* pNoteTexture = GetNoteTexture();
        if (pNoteTexture)
            SaveDataChunk(0x4d414e58, pNoteTexture->GetTextureResourceName(), pNoteTexture->GetTextureNameLength() + 1);
        break;
    }
    case 3: {
        TESTopic* pTopic = GetNoteTopic();
        if (pTopic)
        {
            unsigned int uiTopicFormID = pTopic->GetFormID();
            SaveIntChunk(0x4d414e54, uiTopicFormID);
        }
        TESActorBase* m_pDialogueSpeaker = GetNoteSpeaker();
        if (m_pDialogueSpeaker)
        {
            unsigned int uiSpeakerFormID = m_pDialogueSpeaker->GetFormID();
            SaveIntChunk(0x4d414e53, uiSpeakerFormID);
        }
        break;
    }
    }
    TESForm::FinishFormRecord();
}

// Copies generic components, flags, speaker, type-specific data and owner quests from another BGSNote into this one.
// @fnv 0x005e8c00
void BGSNote::CopyFrom(const TESForm* apForm)
{
    BGSNote* pSource = dynamic_cast<BGSNote*>(const_cast<TESForm*>(apForm));
    if (!pSource)
        return;

    TESForm::CopyFrom(apForm);
    BSSimpleList<TESQuest*>* pIter = 0;
    ChangeNoteType((NOTE_TYPE)pSource->GetNoteType());
    SetNoteSpeaker(pSource->GetNoteSpeaker());
    switch (cType)
    {
    case 0:
        SetNoteSound(pSource->GetNoteSound());
        break;
    case 1:
        SetNoteText(pSource->GetNoteDescription());
        break;
    case 2:
        SetNoteTexture(pSource->GetNoteTexture());
        break;
    case 3:
        SetNoteTopic(pSource->GetNoteTopic());
        break;
    }

    ownerQuests.RemoveAll();
    pIter = pSource->GetOwnerQuests();
    while (pIter && !pIter->IsEmpty())
    {
        ownerQuests.AddHead(pIter->GetItem());
        pIter = pIter->GetNext();
    }
    m_bIsRead = pSource->m_bIsRead;
}

// Compares this note against apForm by base data, type-specific data and owner quest lists, returning true when they differ.
// @fnv 0x005e8d60
bool BGSNote::Compare(TESForm* apForm)
{
    BGSNote* pNote = dynamic_cast<BGSNote*>(apForm);
    if (!pNote)
        return true;
    if (TESForm::Compare(pNote))
        return true;
    if (pNote->cType != cType)
        return true;

    switch (cType)
    {
    case 0:
        if (GetNoteSound() != pNote->GetNoteSound())
            return true;
        break;
    case 1: {
        TESDescription* pMine = GetNoteDescription();
        TESDescription* pTheirs = pNote->GetNoteDescription();
        if (pMine && pTheirs)
        {
            if (pMine->CompareWithBase((BaseFormComponent*)pTheirs))
                return true;
        }
        else if (pMine || pTheirs)
            return true;
        break;
    }
    case 2: {
        TESTexture* pMine = GetNoteTexture();
        TESTexture* pTheirs = pNote->GetNoteTexture();
        if (pMine && pTheirs)
        {
            if (pMine->CompareWithBase((BaseFormComponent*)pTheirs))
                return true;
        }
        else if (pMine || pTheirs)
            return true;
        break;
    }
    case 3:
        if (GetNoteTopic() != pNote->GetNoteTopic())
            return true;
        if (GetNoteSpeaker() != pNote->GetNoteSpeaker())
            return true;
        break;
    }

    if (GetOwnerQuests()->ItemsInList() != pNote->GetOwnerQuests()->ItemsInList())
        return true;

    BSSimpleList<TESQuest*>* pNode = GetOwnerQuests();
    while (pNode && !pNode->IsEmpty())
    {
        TESQuest* pQuest = pNode->GetItem();
        if (!pNote->GetOwnerQuests()->IsInList(pQuest))
            return true;
        pNode = pNode->GetNext();
    }
    return false;
}
