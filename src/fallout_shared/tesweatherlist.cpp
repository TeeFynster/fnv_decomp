// fallout_shared/tesweatherlist.cpp: TESWeatherList, WeatherEntry (10 functions)

#include "tesweatherlist_decls.h"

// Deletes each WeatherEntry in the list, then calls RemoveAll to clear the list.
// @fnv 0x00582780
void TESWeatherList::ClearWeatherSounds()
{
    BSSimpleList<WeatherEntry*>* current = this;
    while (current)
    {
        WeatherEntry* item = current->GetItem();
        operator delete(item);
        current = current->GetNext();
    }
    RemoveAll();
}

// @fnv 0x00824340
WeatherEntry::WeatherEntry()
{
    m_weather = 0;
    m_uiFilterValue = 0;
    m_otherWeather = 0;
}

// Reads weather entries from the file chunk, resolves each weather and global form, adds them to the list, sorts it, and warns on failures.
// @fnv 0x00582940
void TESWeatherList::LoadWeatherEntries(TESWeatherList* list, TESFile* file, TESForm* form)
{
    if (!file || !list || !form)
        return;
    unsigned int count = file->GetChunkSize() / 12;
    if (count > 0)
    {
        list->ClearWeatherSounds();
        FUN_00582570* pEntries = new FUN_00582570[count];
        if (!file->GetChunkData(pEntries, count * 12))
            Warning(DAT_010318b4, form->GetFormID());
        for (unsigned int i = 0; i < count; i++)
        {
            if (file->IsEndianConversionRequired())
                ((ContainerItemExtraFileData*)&pEntries[i])->Endian();
            TESForm::RemapFormIDForFile(pEntries[i].m_unk00, file);
            list->AddHead(new WeatherEntry);
            if (!(list->GetItem()->m_weather =
                      (TESWeather*)__RTDynamicCast(TESForm::GetFormByID(pEntries[i].m_unk00), 0,
                                                   (void*)DAT_01183028, (void*)DAT_0118629c, 0)))
                Warning(DAT_01031858, pEntries[i].m_unk00);
            list->GetItem()->m_uiFilterValue = pEntries[i].m_unk04;
            TESForm::RemapFormIDForFile(pEntries[i].m_unk08, file);
            list->GetItem()->m_otherWeather =
                dynamic_cast<TESGlobal*>(TESForm::GetFormByID(pEntries[i].m_unk08));
        }
        list->Sort(CompareSecondElement);
        delete[] pEntries;
    }
}

struct ListX
{
    void* m_item;
    ListX* m_next;
    ~ListX();
};
struct FUN_00582320 : ListX
{
    ~FUN_00582320();
};
// @fnv 0x00582320
FUN_00582320::~FUN_00582320()
{
    ((TESWeatherList*)this)->ClearWeatherSounds();
}

struct FUN_00582570_Data
{
    int unk0;
    int unk1;
    int unk2;
    FUN_00582570_Data* ClearFields_00582570();
};
// Sets the three integer fields to zero and returns this.
// @fnv 0x00582570
// src: GUESS 0x00582570 (confidence: low)
FUN_00582570_Data* FUN_00582570_Data::ClearFields_00582570()
{
    unk2 = 0;
    unk1 = 0;
    unk0 = 0;
    return this;
}

unsigned int __cdecl DialogueRandom();
struct FUN_005827d0_list : public BSSimpleList<WeatherEntry*>
{
    TESWeather* TESWeatherList_GetRandomWeather();
};
struct FUN_005827d0_node
{
    WeatherEntry*& _ref_006815c0();
};

// @fnv 0x005827d0
// src: XBOX_PDB 0x005827d0
TESWeather* FUN_005827d0_list::TESWeatherList_GetRandomWeather()
{
    BSSimpleList<WeatherEntry*>* pCurrent7;
    {
        unsigned int uiTotalChance5 = 0;
        pCurrent7 = this;
        while (pCurrent7)
        {
            if (((FUN_005827d0_node*)pCurrent7)->_ref_006815c0())
            {
                if (((FUN_005827d0_node*)pCurrent7)->_ref_006815c0()->m_otherWeather)
                    uiTotalChance5 += (unsigned int)((FUN_005827d0_node*)pCurrent7)
                                          ->_ref_006815c0()->m_otherWeather->GetValue();
                else
                    uiTotalChance5 += ((FUN_005827d0_node*)pCurrent7)->_ref_006815c0()->m_uiFilterValue;
            }
            pCurrent7 = pCurrent7->GetNext();
        }
        if (uiTotalChance5)
        {
            unsigned int uiLower;
            unsigned int uiUpper;
            WeatherEntry* pEntry;
            BSSimpleList<WeatherEntry*>* pIter4;
            unsigned int uiRollB;
            uiRollB = DialogueRandom() % uiTotalChance5;
            uiLower = 0;
            uiUpper = 0xFFFFFFFF;
            pEntry = 0;
            pIter4 = this;
            while (pIter4)
            {
                pEntry = ((FUN_005827d0_node*)pIter4)->_ref_006815c0();
                if (pEntry)
                {
                    unsigned int m_uiWeatherChance =
                        pEntry->m_otherWeather
                            ? (unsigned int)pEntry->m_otherWeather->GetValue()
                            : pEntry->m_uiFilterValue;
                    if (m_uiWeatherChance)
                    {
                        uiUpper += m_uiWeatherChance;
                        if (uiLower <= uiRollB && uiRollB <= uiUpper)
                            break;
                        uiLower += m_uiWeatherChance;
                    }
                }
                pIter4 = pIter4->GetNext();
            }
            if (pEntry)
                return pEntry->m_weather;
        }
    }
    return 0;
}

void* __cdecl __memcpy(void* dest, const void* src, unsigned int size);
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_005827d0_shell
{
    bool TESWeatherList_GetRandomWeather();
};
struct FUN_005825a0_shell : public TESWeatherList
{
    void CopyWeatherList(const TESWeatherList* apCopyWL, bool abAppend);
};
// @fnv 0x005825a0
void FUN_005825a0_shell::CopyWeatherList(const TESWeatherList* apCopyWL, bool abAppend)
{
    if (!apCopyWL)
        return;
    if (!abAppend)
        ClearWeatherSounds();
    if (!((FUN_005827d0_shell*)apCopyWL)->TESWeatherList_GetRandomWeather())
    {
        BSSimpleList<WeatherEntry*>* pSourceNode = (BSSimpleList<WeatherEntry*>*)apCopyWL;
        while (pSourceNode)
        {
            WeatherEntry* pNewEntry = new WeatherEntry;
            __memcpy((char*)pNewEntry, (char*)pSourceNode->GetItem(), sizeof(WeatherEntry));
            ((SoundListView*)this)->AddTail((char* const&)pNewEntry);
            pSourceNode = pSourceNode->GetNext();
        }
    }
}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};

bool __fastcall _ref_008256d0(void* pObject);
int __cdecl _memcmp(const void* pDest, const void* pSrc, unsigned int uiSize);

struct FUN_00582690_shell : public TESWeatherList
{
    bool IsDifferentFrom(TESWeatherList* apCompareWL);
};

// Compares this weather list against another: returns true if the other is null, sizes differ, or any entry has no matching 12-byte-equal entry.
// @fnv 0x00582690
bool FUN_00582690_shell::IsDifferentFrom(TESWeatherList* apCompareWL)
{
    BSSimpleList<WeatherEntry*>* pThisNode;
    bool bFound;
    BSSimpleList<WeatherEntry*>* pCompNode;

    if (apCompareWL == 0)
    {
        return true;
        goto L_end;
    }

    if (_ref_008256d0(this) && _ref_008256d0(apCompareWL))
    {
        return false;
        goto L_end;
    }

    if (reinterpret_cast<BSSimpleListTESRaceSize*>(this)->GetSize() !=
        reinterpret_cast<BSSimpleListTESRaceSize*>(apCompareWL)->GetSize())
    {
        return true;
        goto L_end;
    }

    for (pThisNode = this; pThisNode != 0; pThisNode = pThisNode->GetNext())
    {
        bFound = false;

        for (pCompNode = apCompareWL; !bFound && pCompNode != 0; pCompNode = pCompNode->GetNext())
        {
            bFound = (_memcmp(pThisNode->GetItem(), pCompNode->GetItem(), 0xc) == 0);
        }

        if (!bFound)
            return true;
    }

    return false;

L_end:;
}

class SrcListBase_b6402
{
  public:
    virtual ~SrcListBase_b6402();
    unsigned int m_04;
    SrcListBase_b6402(class SrcRecord_b6402* aSrc);
};

class SrcListItem_b6402
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    SrcListItem_b6402();
    ~SrcListItem_b6402();
    void CopyFrom(const SrcListItem_b6402* aSrc, bool abAppend);
};

class SrcRecord_b6402
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    unsigned int m_04;
    SrcListItem_b6402 m_08;
};

class FUN_004f5140 : public SrcListBase_b6402
{
  public:
    virtual ~FUN_004f5140();
    SrcListItem_b6402 m_08;

    FUN_004f5140(SrcRecord_b6402* aSrc);
};

// Constructs a list copy from a source record, copying its item list without appending.
// @fnv 0x004f5140
FUN_004f5140::FUN_004f5140(SrcRecord_b6402* aSrc) : SrcListBase_b6402(aSrc)
{
    m_08.CopyFrom(&aSrc->m_08, false);
}

struct WeatherSaveEntry
{
    unsigned int m_weatherID;
    unsigned int m_uiFilterValue;
    unsigned int m_globalID;
    WeatherSaveEntry();
    void Endian();
};

bool __cdecl IsEndianSwapNeeded();
void __cdecl WriteWeatherData(void* apDest, void* apData, unsigned int auiSize);

struct FUN_00582380_shell : public TESWeatherList
{
    int GetSize();
    void WriteWeatherList(void* apDest);
};

// Builds a WeatherSaveEntry array from the list's weather entries, endian-swaps if needed, writes it to apDest, then swaps back and frees it.
// @fnv 0x00582380
void FUN_00582380_shell::WriteWeatherList(void* apDest)
{
    unsigned int ItemUpdateArray = GetSize();
    if (ItemUpdateArray > 0)
    {
        WeatherSaveEntry* pEntries = new WeatherSaveEntry[ItemUpdateArray];
        ItemUpdateArray = 0;
        BSSimpleList<WeatherEntry*>* pNode = this;
        while (pNode)
        {
            pEntries[ItemUpdateArray].m_weatherID = ((TESForm*)pNode->GetItem()->m_weather)->GetFormID();
            pEntries[ItemUpdateArray].m_uiFilterValue = pNode->GetItem()->m_uiFilterValue;
            pEntries[ItemUpdateArray].m_globalID =
                pNode->GetItem()->m_otherWeather ? pNode->GetItem()->m_otherWeather->GetFormID() : 0;
            ItemUpdateArray++;
            pNode = pNode->GetNext();
        }
        if (IsEndianSwapNeeded())
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                pEntries[i].Endian();
        }
        WriteWeatherData(apDest, pEntries, ItemUpdateArray * sizeof(WeatherSaveEntry));
        if (IsEndianSwapNeeded())
        {
            for (unsigned int j = 0; j < ItemUpdateArray; j++)
                pEntries[j].Endian();
        }
        delete[] pEntries;
    }
}
