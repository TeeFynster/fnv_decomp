// fallout_shared/creaturesounds.cpp: CreatureSounds (14 functions)

#include "creaturesounds_decls.h"

#include "../../include/TESCreature.h"
#include "../../include/TESSound.h"

#include "../../include/CreatureSounds.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

// @fnv 0x005f0360
CreatureSounds::CreatureSounds()
{
    memset(this, 0, 0x58);
}

// Copies text into the BSStringT<char> at offset 0x1c and returns true.
// @fnv 0x005f0040
bool CreatureSounds::SetSoundName(const char* text)
{
    ((BSStringT<char>*)((char*)this + 0x1c))->Set(text, 0);
    return true;
}

// @fnv 0x005f0380
void CreatureSounds::ClearSounds()
{
    FreeAllCreatureSoundLists();
}

// @fnv 0x005f7bf0
void* CreatureSounds::DeleteThis(unsigned int flags)
{
    ClearSounds();
    if (flags & 1)
        operator delete(this);
    return this;
}

// @fnv 0x005f0900
void CreatureSounds::AddSoundForType(SoundListEntry* sound, CREATURE_SOUND_TYPE type)
{
    if (sound && type >= 0 && type < 22)
    {
        if (m_pSoundListsByType[type] == 0)
        {
            m_pSoundListsByType[type] = new BSSimpleList<SoundListEntry*>;
        }

        SoundListView* current = (SoundListView*)GetSoundListForType(type);
        SoundListView* previous = 0;
        while (current && !current->IsEmpty() && current->GetItem()->m_ucSortOrder <= sound->m_ucSortOrder)
        {
            previous = current;
            current = current->GetNext();
        }

        if (current)
            current->AddHead(sound);
        else if (previous)
            previous->AddTail(sound);
    }
}

// @fnv 0x005f0480
bool CreatureSounds::LoadSoundsFromFile(TESFile* file, CREATURE_SOUND_TYPE type, TESCreature* creature)
{
    bool result = false;
    if (file)
    {
        SoundListEntry* sound = 0;
        if (file->GetChunkID() == 0x49445343)
        {
            unsigned int id = 0;
            file->GetChunkData(&id);
            sound = new SoundListEntry;
            if (id)
            {
                TESForm::RemapFormIDForFile(id, file);
                sound->SoundAssetTmp = dynamic_cast<TESSound*>(GetFormByID(id));
                if (!sound->SoundAssetTmp)
                    Warning(DAT_010475a0, id, creature->GetName(), creature->GetFormID());
            }
            else
            {
                sound->SoundAssetTmp = 0;
            }
            file->NextChunk();
        }
        else if (file->GetChunkID() == 0x46445343)
        {
            char filename[260];
            file->GetChunkData(filename, 260);
            sound = new SoundListEntry;
            sound->SoundAssetTmp = TESSound::FindSoundByFilename(filename);
            file->NextChunk();
        }
        if (sound)
        {
            if (file->GetChunkID() == 0x43445343)
            {
                file->GetChunkData(&sound->m_ucSortOrder, 1);
                AddSoundForType(sound, type);
                result = true;
            }
            else
            {
                delete sound;
            }
        }
    }
    return result;
}

struct FUN_005f0860_helper
{
    void ClearSoundList(int);
};

// Calls ClearSoundList for each index from 0 to 21 on this object.
// @fnv 0x005f0820
// src: COMMUNITY 0x005f0820
void CreatureSounds::FreeAllCreatureSoundLists()
{
    for (char i = 0; i < 22; ++i)
    {
        ((FUN_005f0860_helper*)this)->ClearSoundList(i);
    }
}

struct SoundListView_helper : SoundListView
{
    void _ref_0063f7b0();
};

struct CreatureSounds_shell : CreatureSounds
{
    void ClearSoundList(CREATURE_SOUND_TYPE type);
};

// @fnv 0x005f0860
void CreatureSounds_shell::ClearSoundList(CREATURE_SOUND_TYPE type)
{
    SoundListView* list = (SoundListView*)GetSoundListForType(type);
    while (list && !list->IsEmpty())
    {
        SoundListEntry* item = list->GetItem();
        operator delete(item);
        ((SoundListView_helper*)list)->_ref_0063f7b0();
    }
    delete ((BSSimpleList<const char*>**)this)[type];
    ((BSSimpleList<SoundListEntry*>**)this)[type] = 0;
}

// Returns the list stored in the sound table at index aeType when it is in [0,22), otherwise returns null.
// @fnv 0x005f0ac0
BSSimpleList<SoundListEntry*>* CreatureSounds::GetSoundListForType(CREATURE_SOUND_TYPE aeType)
{
    BSSimpleList<SoundListEntry*>* pretlist = 0;
    if (aeType >= 0 && aeType < 22)
    {
        pretlist = m_pSoundListsByType[aeType];
    }
    return pretlist;
}

// If both dst and src are non-null, copies the pointer at src into dst and the byte at offset 4 of src into offset 4 of dst.
// @fnv 0x005f07f0
void CopyPointerAndByte(void* apDest, void* apSource)
{
    if (apDest && apSource)
    {
        *(void**)apDest = *(void**)apSource;
        *(char*)((char*)apDest + 4) = *(char*)((char*)apSource + 4);
    }
}

void __cdecl CopyPointerAndByte(void*, void*);

struct FUN_005f0640_shell : public CreatureSounds
{
    void CopyCreatureSoundLists(CreatureSounds* apCopy);
};

// @fnv 0x005f0640
void FUN_005f0640_shell::CopyCreatureSoundLists(CreatureSounds* apCopy)
{
    FreeAllCreatureSoundLists();
    if (apCopy)
    {
        for (char i = 0; i < 22; ++i)
        {
            BSSimpleList<SoundListEntry*>* pCurrentElementNext = apCopy->GetSoundListForType((CREATURE_SOUND_TYPE)i);
            while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
            {
                SoundListEntry* pdata = pCurrentElementNext->GetItem();
                SoundListEntry* pnewdata = new SoundListEntry;
                CopyPointerAndByte(pnewdata, pdata);
                AddSoundForType(pnewdata, (CREATURE_SOUND_TYPE)i);
                pCurrentElementNext = pCurrentElementNext->GetNext();
            }
        }
    }
}

unsigned int __cdecl DialogueRandom(void);

struct FUN_005f0a30_shell : CreatureSounds
{
    unsigned int GetRandomCreatureSound(CREATURE_SOUND_TYPE type);
};

// Walks the sound list for a creature sound type and returns the first entry whose chance roll succeeds, or 0 if none.
// @fnv 0x005f0a30
unsigned int FUN_005f0a30_shell::GetRandomCreatureSound(CREATURE_SOUND_TYPE aeSoundType)
{
    unsigned int result2 = 0;
    BSSimpleList<SoundListEntry*>* pSoundList = GetSoundListForType(aeSoundType);
    while (pSoundList && !pSoundList->IsEmpty() && !result2)
    {
        SoundListEntry* sound = pSoundList->GetItem();
        if (sound->SoundAssetTmp && DialogueRandom() % 100 < sound->m_ucSortOrder)
            result2 = (unsigned int)sound->SoundAssetTmp;
        pSoundList = pSoundList->GetNext();
    }
    return result2;
}

void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
void __cdecl _FUN_00485910(unsigned int, unsigned int);

struct FUN_005f03a0_shell : public CreatureSounds
{
    void ProcessEntries_005f03a0();
};

// @fnv 0x005f03a0
// src: GUESS 0x005f03a0 (confidence: low)
void FUN_005f03a0_shell::ProcessEntries_005f03a0()
{
    for (int i = 0; i < 22; ++i)
    {
        BSSimpleList<SoundListEntry*>* pSoundList = GetSoundListForType(static_cast<CREATURE_SOUND_TYPE>(i));

        if (pSoundList && !pSoundList->IsEmpty())
        {
            _FUN_00485910(0x54445343, i);

            while (pSoundList && !pSoundList->IsEmpty())
            {
                SoundListEntry* SoundAssetTmp = pSoundList->GetItem();
                unsigned int formID = 0;

                if (SoundAssetTmp->SoundAssetTmp)
                    formID = SoundAssetTmp->SoundAssetTmp->GetFormID();

                _FUN_00485910(0x49445343, formID);
                TESForm_AddChunk_3(0x43445343, SoundAssetTmp->m_ucSortOrder);

                pSoundList = pSoundList->GetNext();
            }
        }
    }
}

struct FUN_005f06f0_shell : CreatureSounds
{
    bool IsDifferentFrom(CreatureSounds* apCompare);
};

// Compares the 22 creature sound lists of this object and apCompare, returning true if any entry differs or list lengths mismatch.
// @fnv 0x005f06f0
bool FUN_005f06f0_shell::IsDifferentFrom(CreatureSounds* apCompare)
{
    char i;

    if (apCompare == 0)
        return true;

    for (i = 0; i < 22; ++i)
    {
        BSSimpleList<SoundListEntry*>* pCurrentElementNext = this->GetSoundListForType(static_cast<CREATURE_SOUND_TYPE>(i));
        BSSimpleList<SoundListEntry*>* pOtherList = apCompare->GetSoundListForType(static_cast<CREATURE_SOUND_TYPE>(i));

        while (pCurrentElementNext != 0 && !pCurrentElementNext->IsEmpty() && pOtherList != 0 && !pOtherList->IsEmpty())
        {
            SoundListEntry* pdata = pCurrentElementNext->GetItem();
            SoundListEntry* pOtherEntry = pOtherList->GetItem();

            if (pdata->m_ucSortOrder != pOtherEntry->m_ucSortOrder)
                return true;

            if (pdata->SoundAssetTmp != pOtherEntry->SoundAssetTmp)
                return true;

            pCurrentElementNext = pCurrentElementNext->GetNext();
            pOtherList = pOtherList->GetNext();
        }

        if (pCurrentElementNext != 0 || pOtherList != 0)
            return true;
    }

    return false;
}
