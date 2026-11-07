#include <stddef.h>

#include "../../include/TESFile.h"
#include "../../include/TESLevSpell.h"
#include "../../include/SpellItem.h"
#include "../../include/TESForm.h"
#include "../../include/TESLeveledList.h"

// src/fallout_shared/teslevspell.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/teslevspell.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Use the shared layout for adapters to component methods missing from the headers.
// A C++ base-pointer cast adds a null check with this unit's original compiler.
static const unsigned int kLeveledListOffset =
    offsetof(TESLevSpell, leveledList) - offsetof(TESLeveledList, leveledList);

// These nonvirtual TESForm helpers are not declared in the shared header yet.
struct FormHelpers
{
    void TESForm_CopyAllComponents(TESForm*);
    bool TESForm_CompareAllComponents(TESForm*);
    void Cleanup();
};
// Casts apCopy to TESLevSpell and, if the cast succeeds, calls FUN_004851b0 on apCopy.
// @fnv 0x0050bcd0
// src: XBOX_PDB 0x0050bcd0
void TESLevSpell::Copy_0050bcd0(TESForm* apCopy)
{
    TESLevSpell* pllcopy = dynamic_cast<TESLevSpell*>(apCopy);
    if (!pllcopy)
        return;
    ((FormHelpers*)this)->TESForm_CopyAllComponents(apCopy);
}

extern "C" void* __cdecl _alloca(unsigned int);
void* memset(void*, int, unsigned int);
class ContainerItemExtra
{
  public:
    static void* operator new(unsigned int);
    ContainerItemExtra();
    bool Load(TESFile*);
    void* data[3];
};
class LeveledObject
{
  public:
    void* pad[2];
    ContainerItemExtra* pExtra;
};
struct LeveledFormEntry
{
    unsigned short sLevel;
    TESForm* pForm;
    unsigned short m_sCount;
};
struct TmpEndian
{
    void SwapEndian();
};
extern LeveledObject* DAT_011c8f98;
// @fnv 0x0050ba30
bool TESLevSpell::LoadForm(TESFile* apFile)
{
    unsigned char formid = apFile->GetTESForm();
    if (formid != 0x4c)
        return false;
    FUN_00485110(apFile);
    do
    {
        switch ((int)apFile->GetChunkID())
        {
        case 'DIDE': {
            char* pEditorID = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pEditorID, 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(apFile);
            break;
        case 'OLVL':
        case 'DEOC':
            switch ((int)apFile->GetChunkID())
            {
            case 'OLVL': {
                LeveledFormEntry levObj;
                memset(&levObj, 0, 0xc);
                apFile->GetChunkData(&levObj, 0xc);
                if (apFile->GetChunkData())
                    ((TmpEndian*)&levObj)->SwapEndian();
                DAT_011c8f98 = TESLeveledList::CreateLeveledObject(levObj.sLevel, levObj.m_sCount, levObj.pForm, 0);
                break;
            }
            case 'DEOC':
                if (DAT_011c8f98)
                {
                    ContainerItemExtra* pextra = new ContainerItemExtra;
                    pextra->Load(apFile);
                    DAT_011c8f98->pExtra = pextra;
                    DAT_011c8f98 = 0;
                }
                break;
            }
            break;
        case 'DLVL': {
            unsigned char cdata = 0;
            apFile->GetChunkData(&cdata, 0);
            TESLeveledList::ExtraWeaponModFlags_SetWeaponModFlags(cdata);
            break;
        }
        case 'FLVL':
            apFile->GetChunkData(&m_ucChanceNone, 0);
            break;
        case 'GLVL': {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            m_pLevelGlobal = (TESGlobal*)itempint;
            break;
        }
        }
    } while (apFile->NextChunk());
    // 0x00484ab0 is TESForm::SetInitializationState, as defined in tesform.cpp.
    SetInitializationState(false);
    return true;
}

// @fnv 0x0050b9b0
TESLevSpell::~TESLevSpell()
{
    ((FormHelpers*)this)->Cleanup();
}

extern int DAT_01183060;
extern int DAT_01183028;
unsigned int __cdecl FUN_00ec43fb(unsigned int, int, void*, void*, int);

// @fnv 0x0050bf90
// src: COMMUNITY 0x0050bf90
SpellItem* TESLevSpell::GetLeveledSpell(void* a1, unsigned short a2)
{
    unsigned int aa = 0;
    unsigned int zz = 0;
    unsigned short word = 0;
    this->SelectLeveledSpell(a1, a2, &zz, &word, 1);
    if (zz != 0)
    {
        aa = FUN_00ec43fb(zz, 0, &DAT_01183028, &DAT_01183060, 0);
    }
    return (SpellItem*)aa;
}

struct SpellEntry
{
    TESForm* form;
};
struct SpellEntryNode
{
    SpellEntry** FUN_006815c0();
    SpellEntryNode* FUN_00726070();
};
struct SpellChoices
{
    SpellEntryNode* FUN_00717e50();
};
struct FUN_0096a2d0
{
    void* unk00;
    void* unk04;
    FUN_0096a2d0();
    void FUN_005ae3d0(SpellItem*&);
};
void* operator new(unsigned int);
// Adapter for the list-building member missing from TESLevSpell.h.
struct SpellListBuilder
{
    FUN_0096a2d0* TESLevSpell_GetLeveledSpells(void*, unsigned short);
};
// Builds a spell list from the selector's choices, resolving nested level spells via FUN_0050bf90, or falls back to a single spell; returns the new list or null.
// @fnv 0x0050c000
// src: COMMUNITY 0x0050c000
FUN_0096a2d0* SpellListBuilder::TESLevSpell_GetLeveledSpells(void* actor, unsigned short level)
{
    FUN_0096a2d0* result = 0;
    if (((TESLevSpell*)this)->TESLeveledList::FUN_004878a0())
    {
        SpellEntryNode* node = ((SpellChoices*)((char*)this + kLeveledListOffset))->FUN_00717e50();
        while (node)
        {
            SpellEntry* entry = *node->FUN_006815c0();
            if (entry)
            {
                if (!result)
                    result = new FUN_0096a2d0;
                SpellItem* spell = dynamic_cast<SpellItem*>(entry->form);
                if (spell)
                {
                    result->FUN_005ae3d0(spell);
                }
                else
                {
                    TESLevSpell* nested = dynamic_cast<TESLevSpell*>(entry->form);
                    if (nested)
                    {
                        spell = nested->GetLeveledSpell(actor, level);
                        if (spell)
                            result->FUN_005ae3d0(spell);
                    }
                }
            }
            node = node->FUN_00726070();
        }
    }
    else
    {
        SpellItem* spell = ((TESLevSpell*)this)->GetLeveledSpell(actor, level);
        if (spell)
        {
            result = new FUN_0096a2d0;
            result->FUN_005ae3d0(spell);
        }
    }
    return result;
}

class BGSHeadPart;
namespace fnv_0050c1d0 {
struct List_009e03e0
{
    BGSHeadPart* m_item;
    List_009e03e0* m_pkNext;
    ~List_009e03e0();
    BGSHeadPart*& FUN_006815c0();
    List_009e03e0* FUN_00726070();
    void RemoveAll();
};
struct FUN_0096a2d0
{
    BGSHeadPart* m_item;
    FUN_0096a2d0* m_pkNext;
    FUN_0096a2d0();
    bool BSSimpleList_TESLevSpell_IsInList(BGSHeadPart*& pkItem);
    void FUN_005ae3d0(BGSHeadPart*& pkItem);
};
int GetMinusOne(int iIndex);
struct SpellSource
{
    virtual void v0();
    virtual void v1();
    virtual void* GetEntry(int iType);
};
struct SpellOwner
{
    char pad[0xa4];
    SpellSource m_kSource;
};
struct SpellCollectionBuilder
{
    List_009e03e0* TESLevSpell_GetLeveledSpells(int iIndex, void* pkEntry);
    FUN_0096a2d0* CollectHeadParts(SpellOwner* pkOwner);
};
// Iterates six source entries, gathers non-null BGSHeadPart items into a deduplicated FUN_0096a2d0 list, frees each temporary list, and returns the result.
// @fnv 0x0050c1d0
FUN_0096a2d0* SpellCollectionBuilder::CollectHeadParts(SpellOwner* pkOwner)
{
    FUN_0096a2d0* pkResult = 0;
    for (int i = 0; i < 6; i++)
    {
        List_009e03e0* pkIter = TESLevSpell_GetLeveledSpells(i, pkOwner->m_kSource.GetEntry(GetMinusOne(i)));
        List_009e03e0* pkListCur = pkIter;
        while (pkIter)
        {
            BGSHeadPart* pkItem = pkIter->FUN_006815c0();
            if (pkItem)
            {
                bool bAppend = true;
                if (!pkResult)
                    pkResult = new FUN_0096a2d0;
                else
                    bAppend = !pkResult->BSSimpleList_TESLevSpell_IsInList(pkItem);
                if (bAppend)
                    pkResult->FUN_005ae3d0(pkItem);
            }
            pkIter = pkIter->FUN_00726070();
        }
        if (pkListCur)
            pkListCur->RemoveAll();
        delete pkListCur;
    }
    return pkResult;
}
}  // namespace fnv_0050c1d0

extern int DAT_01183028;
extern int DAT_01183140;
extern int DAT_01187818;
unsigned int __cdecl FUN_00487f50();
unsigned int __cdecl FUN_00ec43fb(unsigned int, int, void*, void*, int);
void* __cdecl GetSix(unsigned int);

struct Entry
{
    unsigned int form;
    unsigned short count;
    unsigned short level;
};
// Exe 0x0050bd60: unit-local ListNode view; declarations and layout are preserved.
struct TeslevspellListNodeView
{
    Entry** FUN_006815c0();
    TeslevspellListNodeView* FUN_00726070();
};
struct ListData
{
    TeslevspellListNodeView* FUN_00717e50();
};
struct FormHandle
{
    unsigned int EffectItemList_GetAssociatedSkill();
};
// @fnv 0x0050bd60
void TESLevSpell::SelectLeveledSpell(void* desiredForm, unsigned short level, unsigned int* outForm,
                                    unsigned short* outCount, unsigned char recurse)
{
    *outForm = 0;
    *outCount = 0;
    unsigned int candidateCount;
    int maxLevel;
    TeslevspellListNodeView* best;
    TeslevspellListNodeView* node;
    unsigned char chanceNone = vfn_10();
    if (chanceNone > 0)
    {
        int chanceRoll = (int)(FUN_00487f50() % 100);
        if (chanceRoll < chanceNone)
            return;
    }

    candidateCount = 1;
    maxLevel = 0;
    best = 0;
    node = ((ListData*)((char*)this + kLeveledListOffset))->FUN_00717e50();
    while (node != 0 && *node->FUN_006815c0() != 0)
    {
        Entry* entryLevel = *node->FUN_006815c0();
        TESForm* mapped =
            (TESForm*)FUN_00ec43fb(entryLevel->form, 0, &DAT_01183028, &DAT_01183140, 0);
        int entry = entryLevel->level;
        if (entry > level || (mapped != 0 && GetSix(((FormHandle*)&mapped->iFormID)->EffectItemList_GetAssociatedSkill()) != desiredForm))
            break;
        if (entry > maxLevel && (maxLevel == 0 || !TESLeveledList::FUN_004877e0()))
        {
            candidateCount = 1;
            best = node;
            maxLevel = entry;
        }
        else
        {
            ++candidateCount;
        }
        node = node->FUN_00726070();
    }
    if (best != 0)
    {
        unsigned int skip = FUN_00487f50() % candidateCount;
        node = best;
        while (skip != 0)
        {
            node = node->FUN_00726070();
            --skip;
            if (node == 0)
                return;
        }
        unsigned short nestedRecord;
        Entry* chosen = *node->FUN_006815c0();
        unsigned int foundForm = chosen->form;
        nestedRecord = chosen->count;
        TESLevSpell* selectedEntry =
            (TESLevSpell*)FUN_00ec43fb(chosen->form, 0, &DAT_01183028, &DAT_01187818, 0);
        if (selectedEntry != 0 && recurse != 0)
        {
            unsigned short recursiveCount;
            unsigned int recursiveForm = 0;
            recursiveCount = 0;
            selectedEntry->SelectLeveledSpell(desiredForm, level, &recursiveForm, &recursiveCount, recurse);
            foundForm = recursiveForm;
            nestedRecord *= recursiveCount;
        }
        *outForm = foundForm;
        *outCount = nestedRecord;
    }
}

// Returns true if apCompare is not a TESLevSpell or if FUN_00485270(pcomp) is true, otherwise false.
// @fnv 0x0050bd10
// src: XBOX_PDB 0x0050bd10
bool TESLevSpell::Compare_0050bd10(TESForm* apCompare)
{
    TESLevSpell* pLevSpell = dynamic_cast<TESLevSpell*>(apCompare);
    if (!pLevSpell)
        return true;
    if (((FormHelpers*)this)->TESForm_CompareAllComponents(pLevSpell))
        return true;
    return false;
}
