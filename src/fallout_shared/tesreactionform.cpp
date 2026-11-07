// fallout_shared/tesreactionform.cpp: TESReactionForm and reaction map storage (21 functions)

#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BaseProcess.h"
#include "../../include/BSSimpleList.h"
#include "../../include/TESForm.h"
#include "../../include/TESReactionForm.h"
#include "tesreactionform_decls.h"

// Reaction entries are 12 bytes: form at 0, reaction at 4, fight reaction at 8; no shared header exists yet.
struct GROUP_REACTION
{
    TESForm* pForm;
    int iReaction;
    int iFightReaction;
    void Endian();
};

void __cdecl operator delete(void* pointer);

static const int kInitializeDataComponentValue1 = 8;

// @fnv 0x0048bad0
void TESReactionForm::InitializeComponent()
{
    m_ucReactionFlags = kInitializeDataComponentValue1;
}

// @fnv 0x0048baf0
void TESReactionForm::ClearComponent()
{
    ClearReactionList();
}

// @fnv 0x0048bb10
void TESReactionForm::ClearReactionList()
{
    while (reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList())
               ->GetItem() != 0)
    {
        GROUP_REACTION* pToFree =
            reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList())
                ->GetItem();
        GROUP_REACTION* pItem = pToFree;
        ::operator delete(pItem);
        reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList())
            ->RemoveHead();
    }
}

// Constructs the map base by forwarding the given size to the TESReactionMapStorage base constructor.
// Constructs a BSMapBase<int, DistantTreeTextureInfo*> with the given size, delegating to TESReactionMapStorage.
// @fnv 0x0048b380
template <> BSMapBase<int, DistantTreeTextureInfo*>::BSMapBase(unsigned int size) : TESReactionMapStorage(size)
{}

// On load, walks the reaction list and drops entries whose formID no longer resolves, unlinking them from the list.
// @fnv 0x0048cb40
void TESReactionForm::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    if (static_cast<const FormChangeMask&>(buffer->GetChangeFlags(4u)))
    {
        BSSimpleList<GROUP_REACTION*>* current = reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(&m_kReactionList);
        BSSimpleList<GROUP_REACTION*>* previous = 0;
        while (current && !current->IsEmpty())
        {
            GROUP_REACTION* reaction = current->GetItem();
            bool remove = false;
            if (reaction)
            {
                reaction->pForm = reaction->pForm
                                       ? TESForm::GetFormByID(reinterpret_cast<unsigned int>(reaction->pForm))
                                       : 0;
                if (!reaction->pForm)
                {
                    delete reaction;
                    remove = true;
                }
            }
            else
            {
                remove = true;
            }
            if (remove)
            {
                if (previous)
                {
                    previous->Remove(current->GetItem());
                    current = previous->GetNext();
                }
                else
                {
                    current->RemoveHead();
                }
            }
            else
            {
                previous = current;
                current = current->GetNext();
            }
        }
    }
}

// Resolves each reaction entry's formID against the given form's file, warns and removes entries whose form cannot be found.
// @fnv 0x0048bc30
void TESReactionForm::InitItem(TESForm* form)
{
    // Local names preserve the original MSVC9 stack allocation.
    TESFile* pPrev;
    BSSimpleList<GROUP_REACTION*>* pList =
        reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList());
    BSSimpleList<GROUP_REACTION*>* pFile = 0;
    pPrev = form ? form->GetFile(-1) : 0;
    while (pList && pList->GetItem())
    {
        GROUP_REACTION* reaction = pList->GetItem();
        unsigned int formID = reinterpret_cast<unsigned int>(reaction->pForm);
        TESForm::RemapFormIDForFile(formID, pPrev);
        reaction->pForm = TESForm::GetFormByID(formID);
        if (reaction->pForm)
        {
            pList = pList->GetNext();
        }
        else
        {
            Warning("MASTERFILE: Form (%08X) not found for reaction of pForm (%08X) '%s'.\r\n", formID,
                    form->GetFormID(), form->GetName());
            if (pList->GetNext() || !pFile)
            {
                pList->RemoveHead();
            }
            else
            {
                pFile->Remove(reaction);
                pList = pFile->GetNext();
            }
            delete reaction;
        }
    }
}

// Searches the reaction list for a matching form and returns its fight reaction, or 0 if not found.
// @fnv 0x0048c1b0
int TESReactionForm::GetFactionCombatRelation(TESForm* apForm)
{
    if (apForm != 0)
    {
        void* pList = GetReactionList();
        while (pList != 0 && static_cast<BSSimpleList<GROUP_REACTION*>*>(pList)->GetItem() != 0)
        {
            GROUP_REACTION* fr = static_cast<BSSimpleList<GROUP_REACTION*>*>(pList)->GetItem();
            if (fr->pForm == apForm)
                return fr->iFightReaction;
            pList = static_cast<BSSimpleList<GROUP_REACTION*>*>(pList)->GetNext();
        }
    }
    return 0;
}

// @fnv 0x0048bfc0
void TESReactionForm::SetReactionValue(TESForm* apForm, int aiReaction)
{
    if (!apForm)
        return;
    bool bFound = false;
    void* pList = GetReactionList();
    while (pList && static_cast<BSSimpleList<GROUP_REACTION*>*>(pList)->GetItem())
    {
        GROUP_REACTION* fr = static_cast<BSSimpleList<GROUP_REACTION*>*>(pList)->GetItem();
        if (fr->pForm == apForm)
        {
            if (aiReaction == 0 && fr->iFightReaction == 0)
            {
                ((BSSimpleList<GROUP_REACTION*>*)((char*)this + 4))->Remove(fr);
                delete fr;
            }
            else
            {
                fr->iReaction = aiReaction;
            }
            bFound = true;
            break;
        }
        pList = static_cast<BSSimpleList<GROUP_REACTION*>*>(pList)->GetNext();
    }
    if (!bFound && aiReaction)
    {
        GROUP_REACTION* fr = new GROUP_REACTION;
        fr->pForm = apForm;
        fr->iReaction = aiReaction;
        ((BSSimpleList<GROUP_REACTION*>*)GetReactionList())->AddTail(fr);
    }
}

// @fnv 0x0048ba00
TESReactionForm::TESReactionForm()
{
    InitializeComponent();
}

// @fnv 0x0048ba70
TESReactionForm::~TESReactionForm()
{
    ClearComponent();
}

void __cdecl operator delete(void*);
void* __cdecl operator new(unsigned int);
// @fnv 0x0048ca90
void TESReactionForm::LoadGame(BGSLoadFormBuffer* buffer)
{
    if (static_cast<const FormChangeMask&>(buffer->GetChangeFlags(4u)))
    {
        ClearReactionList();
        unsigned int count = buffer->ReadElementCount();
        for (unsigned int i = 0; i < count; ++i)
        {
            GROUP_REACTION* entry = new GROUP_REACTION;
            buffer->ReadFormIdentifier(static_cast<void*>(&entry->pForm));
            buffer->ReadTypedData(static_cast<void*>(&entry->iReaction), 4u);
            buffer->ReadTypedData(static_cast<void*>(&entry->iFightReaction), 4u);
            ((BSSimpleList<GROUP_REACTION*>*)((char*)this + 4))->AddHead(entry);
        }
    }
}

bool TESForm_QEndianSwapOnSave();
void AppendChunk(unsigned int, void*, unsigned int);

// @fnv 0x0048bb70
void TESReactionForm::Save()
{
    BSSimpleList<GROUP_REACTION*>* current = (BSSimpleList<GROUP_REACTION*>*)GetReactionList();
    GROUP_REACTION* shot;
    GROUP_REACTION data;

    while (current && current->GetItem())
    {
        shot = current->GetItem();

        if (!(*reinterpret_cast<const TESForm**>(shot))->IsDeleted())
        {
            data.pForm = reinterpret_cast<TESForm*>((*reinterpret_cast<const TESForm**>(shot))->GetFormID());
            data.iReaction = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(shot) + 4);
            data.iFightReaction = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(shot) + 8);

            if (TESForm_QEndianSwapOnSave())
                data.Endian();

            AppendChunk(0x4d414e58, &data, 0xc);

            if (TESForm_QEndianSwapOnSave())
                data.Endian();
        }

        current = (BSSimpleList<GROUP_REACTION*>*)current->GetNext();
    }
}

extern int DAT_01183040;
extern int DAT_01186b30;
void* __cdecl FUN_00ec43fb(TESForm* form, unsigned int a, void* b, void* c, unsigned int d);

// @fnv 0x0048bd50
void TESReactionForm::BaseFormRecord(BaseFormComponent* form)
{
    TESReactionForm* p = (TESReactionForm*)FUN_00ec43fb(reinterpret_cast<TESForm*>(form), 0, &DAT_01183040, &DAT_01186b30, 0);
    if (p == 0)
    {
        return;
    }
    this->ClearReactionList();
    BSSimpleList<GROUP_REACTION*>* cur5;
    BSSimpleList<GROUP_REACTION*>* dst;
    dst = reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList());
    cur5 = reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(p->GetReactionList());
    while (cur5 != 0 && cur5->GetItem() != 0)
    {
        GROUP_REACTION* src2 = cur5->GetItem();
        GROUP_REACTION* item = new GROUP_REACTION;
        item->pForm = src2->pForm;
        item->iReaction = src2->iReaction;
        item->iFightReaction = src2->iFightReaction;
        dst->AddTail(item);
        if (dst->GetNext() != 0)
        {
            dst = dst->GetNext();
        }
        cur5 = cur5->GetNext();
    }
}

// Compares this reaction form's list against another TESReactionForm's list entry by entry, returning true when they differ or the other list is longer.
// @fnv 0x0048be40
bool TESReactionForm::IsEqualToBase(BaseFormComponent* component)
{
    TESReactionForm* right = dynamic_cast<TESReactionForm*>(component);
    if (!right)
        return true;
    BSSimpleList<GROUP_REACTION*>* other = reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList());
    BSSimpleList<GROUP_REACTION*>* left = reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(right->GetReactionList());
    while (other)
    {
        if (!left)
            return true;
        GROUP_REACTION* rhs = other->GetItem();
        GROUP_REACTION* lhs = left->GetItem();
        if (rhs && lhs)
        {
            if (rhs->pForm != lhs->pForm)
                return true;
            if (rhs->iReaction != lhs->iReaction)
                return true;
            if (rhs->iFightReaction != lhs->iFightReaction)
                return true;
        }
        else if (rhs || lhs)
            return true;
        left = left->GetNext();
        other = other->GetNext();
    }
    if (left && !left->IsEmpty())
        return true;
    return false;
}

// Adjust the stored count for a form: add a new entry if missing, remove the entry when its count reaches zero.

// @fnv 0x0048c0b0
void TESReactionForm::ModReaction(TESForm* pkForm, int iDelta)
{
    if (!pkForm || !iDelta)
        return;

    GROUP_REACTION* pkEntry = 0;
    BSSimpleList<GROUP_REACTION*>* pkIter = reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList());
    bool bFound = false;
    while (pkIter && pkIter->GetItem())
    {
        pkEntry = pkIter->GetItem();
        if (pkEntry->pForm == pkForm)
        {
            bFound = true;
            break;
        }
        pkIter = pkIter->GetNext();
    }

    if (!bFound)
    {
        pkEntry = new GROUP_REACTION;
        pkEntry->pForm = pkForm;
        pkEntry->iReaction = iDelta;
        reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList())->AddTail(pkEntry);
    }
    else
    {
        pkEntry->iReaction += iDelta;
        if (!pkEntry->iReaction)
        {
            reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList())->Remove(pkEntry);
            delete pkEntry;
        }
    }
}

// If apForm is non-null, updates the matching list entry's reaction or appends a new entry when aiReaction is non-zero.
// @fnv 0x0048c220
void TESReactionForm::SetFightReaction(TESForm* apForm, int aiReaction)
{
    if (apForm == 0)
    {
        return;
    }
    bool bFound = false;
    void* pNode = GetReactionList();
    while (pNode != 0 && static_cast<BSSimpleList<GROUP_REACTION*>*>(pNode)->GetItem() != 0)
    {
        GROUP_REACTION* pItem = static_cast<BSSimpleList<GROUP_REACTION*>*>(pNode)->GetItem();
        if (pItem->pForm == apForm)
        {
            pItem->iFightReaction = aiReaction;
            bFound = true;
            break;
        }
        pNode = static_cast<BSSimpleList<GROUP_REACTION*>*>(pNode)->GetNext();
    }
    if (!bFound && aiReaction != 0)
    {
        GROUP_REACTION* newItem = new GROUP_REACTION;
        newItem->pForm = apForm;
        newItem->iReaction = 0;
        newItem->iFightReaction = aiReaction;
        static_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList())->AddTail(newItem);
    }
}

namespace fnv_0048c2e0 {
extern "C" char str_01012c78[];
extern "C" char str_0101d4c8[];
extern "C" char str_01012cb0[];
extern void* DAT_011de45c;
extern unsigned char DAT_011de4e8;
struct Global_011de45c
{
    bool TESSaveLoadGame_UseSaveGameBlocks();
    unsigned int* FUN_004fd3e0();
};
struct Global_011de4e8
{
    const unsigned char* FUN_00408d60();
};
// The shared context has no declaration for the entry-count routine at this address.
int __fastcall _ref_005ae380(ActorPackageContext* context);
void __cdecl ProgramFlow(const char*, ...);
}  // namespace fnv_0048c2e0

// Computes the serialized size of the reaction data when flag bit 4 is set.
// @fnv 0x0048c2e0
unsigned short TESReactionForm::GetSaveSize(unsigned int flags)
{
    unsigned short count = 0;
    if ((flags & 4) != 0)
    {
        unsigned short start = count;
        if (((fnv_0048c2e0::Global_011de45c*)fnv_0048c2e0::DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
        {
            count += 4;
            count += 2;
        }
        ActorPackageContext* package = reinterpret_cast<ActorPackageContext*>(GetReactionList());
        count += 2;
        count += fnv_0048c2e0::_ref_005ae380(package) * 8;
        if (*((fnv_0048c2e0::Global_011de4e8*)&fnv_0048c2e0::DAT_011de4e8)->FUN_00408d60() != 0)
        {
            unsigned int* formID = ((fnv_0048c2e0::Global_011de45c*)fnv_0048c2e0::DAT_011de45c)->FUN_004fd3e0();
            if (formID != 0)
            {
                TESForm* form = TESForm::GetFormByID(*formID);
                fnv_0048c2e0::ProgramFlow(fnv_0048c2e0::str_01012cb0, count - start, *formID, form->GetName(),
                             *(unsigned int*)((unsigned char*)formID + 5), 0x557, fnv_0048c2e0::str_0101d4c8);
            }
            else
            {
                fnv_0048c2e0::ProgramFlow(fnv_0048c2e0::str_01012c78, count - start, 0x557, fnv_0048c2e0::str_0101d4c8);
            }
        }
    }
    return count;
}

struct ObjC400
{
    unsigned int formID;
    char flag4;
    int field5;
};
struct SaveC400
{
    unsigned int FUN_00825c00();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(void*, int);
    void TESSaveLoadGame_SaveNumericID(void*, int);
    ObjC400* FUN_004fd3e0();
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern SaveC400* DAT_011de45c;
extern GlobalObject_0045cf30 DAT_011de4e8;
extern const char str_0101d4c8[];
extern const char str_010153a0[];
extern const char str_0101536c[];
extern const char str_01015318[];
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
void __cdecl ProgramFlow(const char*, ...);
int Warning(const char*, ...);

// @fnv 0x0048c400
void TESReactionForm::SaveGame(unsigned int auiFlags)
{
    if (auiFlags & 4)
    {
        unsigned short sizeWord = 0;
        unsigned int posSize4 = 0;
        unsigned int startPos = DAT_011de45c->FUN_00825c00();
        if (*DAT_011de4e8.Bool())
        {
            startPos = DAT_011de45c->FUN_00825c00();
        }
        if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
        {
            int tag = 0x424c4f4b;
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&tag, 4);
            posSize4 = DAT_011de45c->FUN_00825c00();
            DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&sizeWord, 2);
        }
        unsigned short kCount = 0;
        unsigned int posCountC = DAT_011de45c->FUN_00825c00();
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&kCount, 2);
        BSSimpleList<GROUP_REACTION*>* node = reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(GetReactionList());
        while (node)
        {
            GROUP_REACTION* item = node->GetItem();
            if (item)
            {
                unsigned int formID = item->pForm->GetFormID();
                DAT_011de45c->TESSaveLoadGame_SaveNumericID(&formID, 4);
                DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&item->iReaction, 4);
                kCount++;
            }
            node = node->GetNext();
        }
        *(unsigned short*)posCountC = kCount;
        if (*DAT_011de4e8.Bool())
        {
            unsigned int endPos2 = DAT_011de45c->FUN_00825c00();
            ObjC400* kObj = DAT_011de45c->FUN_004fd3e0();
            if (kObj)
            {
                TESForm* form = TESForm_GetFormByNumericID(kObj->formID);
                ProgramFlow(str_010153a0, endPos2 - startPos, kObj->formID, form->GetName(),
                             *(int*)((char*)kObj + 5), 1403, str_0101d4c8);
            }
            else
            {
                ProgramFlow(str_0101536c, endPos2 - startPos, 1403, str_0101d4c8);
            }
        }
        if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int endPos = DAT_011de45c->FUN_00825c00();
            unsigned int blockStart = posSize4;
            if (endPos > blockStart + 0xffff)
            {
                Warning(str_01015318, str_0101d4c8, 1403);
            }
            *(unsigned short*)posSize4 = (unsigned short)(endPos - blockStart);
        }
    }
}

struct SaveLoadFormInfo
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char flagsByte0;
    unsigned char flagsByte1;
    unsigned char flagsByte2;
    unsigned char flagsByte3;
    unsigned char version;
};

struct SaveLoadGameStub
{
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void ReadTypedData(void* apData, unsigned int auiSize);
    void ReadFormIdentifier(unsigned int* apID, int aiSize);
    SaveLoadFormInfo* GetCurrentFormInfo();
    unsigned int GetBufferPosition();
    unsigned char GetVersion();
};
extern SaveLoadGameStub* g_TESSaveLoadGame;

TESForm* LookupFormByID(unsigned int auiFormID);

// @fnv 0x0048c640
void TESReactionForm::LoadGame(unsigned int auiChangeFlags, unsigned int unused)
{
    if (auiChangeFlags & 4)
    {
        unsigned short usLength = 0;
        unsigned int dwStart = 0;
        unsigned short usNum;
        if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int uiMarker;
            g_TESSaveLoadGame->ReadTypedData(&uiMarker, 4);
            if (uiMarker != 0x424C4F4B)
            {
                SaveLoadFormInfo* pInfo = g_TESSaveLoadGame->GetCurrentFormInfo();
                if (pInfo)
                {
                    TESForm* pForm = LookupFormByID(pInfo->formID);
                    Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1415,
                        pInfo->formID, pForm->GetName(), pInfo->version, *(unsigned int*)&pInfo->flagsByte0);
                }
                else
                {
                    Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1415,
                        g_TESSaveLoadGame->GetVersion());
                }
            }
            dwStart = g_TESSaveLoadGame->GetBufferPosition();
            g_TESSaveLoadGame->ReadTypedData(&usLength, 2);
        }
        ClearReactionList();
        g_TESSaveLoadGame->ReadTypedData(&usNum, 2);
        for (unsigned int i = 0; i < usNum; i++)
        {
            unsigned int auiFormId;
            g_TESSaveLoadGame->ReadFormIdentifier(&auiFormId, 4);
            int iFactionReaction;
            g_TESSaveLoadGame->ReadTypedData(&iFactionReaction, 4);
            SetReactionValue(reinterpret_cast<TESForm*>(auiFormId), iFactionReaction);
        }
        if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int endPos = g_TESSaveLoadGame->GetBufferPosition();
            SaveLoadFormInfo* pEndInfo = g_TESSaveLoadGame->GetCurrentFormInfo();
            if (pEndInfo)
            {
                TESForm* pEndForm = LookupFormByID(pEndInfo->formID);
                if (endPos > usLength + dwStart)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        endPos - (usLength + dwStart),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1433,
                        pEndInfo->formID, pEndForm->GetName(), pEndInfo->version,
                        *(unsigned int*)&pEndInfo->flagsByte0);
                }
                else if (endPos < usLength + dwStart)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        (usLength + dwStart) - endPos,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1433,
                        pEndInfo->formID, pEndForm->GetName(), pEndInfo->version,
                        *(unsigned int*)&pEndInfo->flagsByte0);
                }
            }
            else
            {
                if (endPos > usLength + dwStart)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        endPos - (usLength + dwStart),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1433,
                        g_TESSaveLoadGame->GetVersion());
                }
                else if (endPos < usLength + dwStart)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        (usLength + dwStart) - endPos,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESReactionForm.cpp", 1433,
                        g_TESSaveLoadGame->GetVersion());
                }
            }
        }
    }
}

void* __fastcall _ref_00717e50(void* pList);
void __fastcall _ref_0063f7b0(void* pList);
unsigned int __cdecl _ref_004839c0(unsigned int aFormID);

// When flags has bit 4, walks the list, resolves each entry's pForm via _ref_004839c0, and deletes entries whose form resolves to null.
// @fnv 0x0048c930
void TESReactionForm::InitLoadGame(unsigned int flags, unsigned int unused)
{
    if (flags & 4)
    {
        void* iter = _ref_00717e50(this);
        int count = 0;
        while (iter != 0)
        {
            GROUP_REACTION* entry = static_cast<BSSimpleList<GROUP_REACTION*>*>(iter)->GetItem();
            if (entry != 0)
            {
                unsigned int formID = (unsigned int)entry->pForm;
                entry->pForm = (TESForm*)_ref_004839c0(formID);
                if (entry->pForm == 0)
                {
                    _ref_0063f7b0(iter);
                    GROUP_REACTION* dead = entry;
                    operator delete(dead);
                }
                else
                {
                    iter = static_cast<BSSimpleList<GROUP_REACTION*>*>(iter)->GetNext();
                }
            }
            else
            {
                iter = static_cast<BSSimpleList<GROUP_REACTION*>*>(iter)->GetNext();
            }
        }
    }
}

struct FUN_0048c9d0_ChangeFlags
{
    bool FUN_004280f0();
};

struct FUN_0048c9d0_SaveBuffer
{
    FUN_0048c9d0_ChangeFlags* FUN_00428110(int* value, int size);
    unsigned int StartVariableSizedValue();
    void FUN_00865df0(int value, int flag);
    void FUN_00865e50(void* data, unsigned int size, int flag);
    void SaveVariableSizedValue_00865ff0(int count, unsigned int value);
};

// @fnv 0x0048c9d0
void TESReactionForm::SaveGame(BGSSaveFormBuffer* apBuffer)
{
    void* item;
    BSSimpleList<GROUP_REACTION*>* cursor;
    unsigned int value;
    int count;

    {
        int temp;
        if (reinterpret_cast<FUN_0048c9d0_SaveBuffer*>(apBuffer)->FUN_00428110(&temp, 4)->FUN_004280f0())
        {
            count = 0;
            value = reinterpret_cast<FUN_0048c9d0_SaveBuffer*>(apBuffer)->StartVariableSizedValue();
            cursor = reinterpret_cast<BSSimpleList<GROUP_REACTION*>*>(&m_kReactionList);
            while (cursor != 0)
            {
                item = cursor->GetItem();
                if (item != 0)
                {
                    reinterpret_cast<FUN_0048c9d0_SaveBuffer*>(apBuffer)->FUN_00865df0(*(int*)item, 0);
                    reinterpret_cast<FUN_0048c9d0_SaveBuffer*>(apBuffer)->FUN_00865e50((char*)item + 4, 4, 0);
                    reinterpret_cast<FUN_0048c9d0_SaveBuffer*>(apBuffer)->FUN_00865e50((char*)item + 8, 4, 0);
                    count = count + 1;
                }
                cursor = cursor->GetNext();
            }
            reinterpret_cast<FUN_0048c9d0_SaveBuffer*>(apBuffer)->SaveVariableSizedValue_00865ff0(count, value);
        }
    }
}
