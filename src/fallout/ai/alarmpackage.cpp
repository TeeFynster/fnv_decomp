// fallout/ai/alarmpackage.cpp: Crime, TESSpellList, Candidate, Cls and more (27 functions)

#include "../../../include/BSSimpleList.h"
#include "../../../include/Actor.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/ChangesMap.h"
#include "../../../include/DialoguePackage.h"
#include "../../../include/SL.h"
#include "../../../include/TESActorBaseData.h"
#include "../../../include/TESFaction.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESPackage.h"
#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/NiTPointerMap.h"
#include "../../../include/SpellItem.h"
#include "../../../include/TESLevSpell.h"
#include "../../../include/TESSpellList.h"
#include "../../../include/TESBoundObject.h"

#include "../../../include/AlarmPackage.h"
#include "../../../include/ProcessLists.h"

TESForm* __cdecl GetFormByID(unsigned int formID);

// Unit operations absent from the shared API; all storage and virtuals come from AlarmPackage.
class AlarmPackageUnitOperations : public AlarmPackage
{
public:
    bool IsSpellInList(SpellItem* spell);
    void AddHeadAtOffset(int* item);
    void RemoveCrime(unsigned int item, Actor* actor);
    void SaveGameLegacy();
};

// If the buffer's change flags include 0x10, clears both spell lists and re-adds each SpellItem and TESLevSpell read from the buffer.
// @fnv 0x0048e140
void TESSpellList::LoadGame(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetChangeFlags(0x10u).operator bool())
    {
        spellList.RemoveAll();
        leveledSpellList.RemoveAll();

        {
            unsigned int spellCount = buffer->ReadElementCount();
            for (unsigned int i = 0; i < spellCount; ++i)
            {
                SpellItem* pLevSpell = 0;
                pLevSpell = dynamic_cast<SpellItem*>(GetFormByID(buffer->ReadFormIdentifier()));
                if (pLevSpell)
                    spellList.AddHead(pLevSpell);
            }
        }

        {
            unsigned int leveledSpellCount = buffer->ReadElementCount();
            for (unsigned int i = 0; i < leveledSpellCount; ++i)
            {
                TESLevSpell* pLevSpell = 0;
                pLevSpell = dynamic_cast<TESLevSpell*>(GetFormByID(buffer->ReadFormIdentifier()));
                if (pLevSpell)
                    leveledSpellList.AddHead(pLevSpell);
            }
        }
    }
}

TESForm* __cdecl GetFormByID(unsigned int);
// Unit operation absent from the shared API; storage and DeleteForm come from TESSaveLoadGame.
class TESSaveLoadGameUnitOperations : public TESSaveLoadGame
{
public:
    void DeleteFormById(unsigned int id);
};
// @fnv 0x0085a290
void TESSaveLoadGameUnitOperations::DeleteFormById(unsigned int uiFormId)
{
    TESForm* pForm = GetFormByID(uiFormId);
    if (pForm)
        DeleteForm(pForm);
    else
        m_pChangesMap->RemoveChanges(uiFormId, true);
}

struct LH
{
    bool IsInList(Actor*&);
};
struct Crime
{
    unsigned char _pad[0x1c];
    LH _list;
    bool IsActorInList(Actor* apActor);
};
// @fnv 0x009eb9a0
bool Crime::IsActorInList(Actor* apActor)
{
    return _list.IsInList(apActor);
}

struct FUN_009eba00_t
{
    int m_uiItemCount;
    void RemoveActorAndDecrementCount(Actor* a);
};
// @fnv 0x009eba00
// src: GUESS 0x009eba00 (confidence: medium)
void FUN_009eba00_t::RemoveActorAndDecrementCount(Actor* apActor)
{
    reinterpret_cast<BSSimpleList<Actor*>*>(reinterpret_cast<char*>(this) + 0x1c)->Remove(apActor);
    m_uiItemCount = m_uiItemCount - 1;
}

struct BSSimpleListTESRaceSize
{
    bool _ref_008256d0();
    int GetSize();
};
struct FUN_009ebab0_host
{
    char _pad[0x1C];
    BSSimpleListTESRaceSize _list;
    int GetRaceListSize();
};
// Returns 0 if the race list reference check succeeds, otherwise returns the list size.
// @fnv 0x009ebab0
int FUN_009ebab0_host::GetRaceListSize()
{
    if (_list._ref_008256d0())
        return 0;
    else
        return _list.GetSize();
}

void __cdecl Deallocate(void*);
// @fnv 0x009ec640
AlarmPackage* AlarmPackage::Destroy(unsigned int flags)
{
    AlarmPackage::~AlarmPackage();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_009ec810 {
struct LH
{
    bool IsInList(SpellItem* const& a) const;
};
}  // namespace fnv_009ec810
// @fnv 0x009ec810
bool AlarmPackageUnitOperations::IsSpellInList(SpellItem* pSpell)
{
    return reinterpret_cast<fnv_009ec810::LH*>(&list)->IsInList(pSpell);
}

struct G2
{
    void AddHead(int* const& a);
};
// @fnv 0x009ec830
void AlarmPackageUnitOperations::AddHeadAtOffset(int* a)
{
    reinterpret_cast<G2*>(&list)->AddHead(a);
}

namespace fnv_009ec850 {
struct MyList
{
    void _ref_00905330(const unsigned int&);
    bool _ref_008256d0();
};
}  // namespace fnv_009ec850
// @fnv 0x009ec850
void AlarmPackageUnitOperations::RemoveCrime(unsigned int a, Actor* pActor)
{
    reinterpret_cast<fnv_009ec850::MyList*>(&list)->_ref_00905330(a);
    if (reinterpret_cast<fnv_009ec850::MyList*>(&list)->_ref_008256d0())
        pActor->SetSpeakingState(0);
}

// 0x00616c20 updates the TESFaction reputation record at +0x38 (also bound by tesfaction.cpp).
struct ReputationChangeNotifier
{
    void TESReputation_CommitCrime(int);
};
// 0x005fda50 is a faction call in actor.cpp; +0x38/+0x44 match TESFaction, not the nonvirtual Crime layout.
struct FactionReputationOperations : TESFaction
{
    void ModifyReputation(int, bool);
};
// @fnv 0x005fda50
void FactionReputationOperations::ModifyReputation(int aiAmount, bool b)
{
    m_iFirstFactionValue += aiAmount;
    if (pReputationData && b)
        reinterpret_cast<ReputationChangeNotifier*>(pReputationData)->TESReputation_CommitCrime(1);
    MarkAsModified(0x80000000);
}

namespace fnv_009eb9c0 {
struct FUN_009eb9c0_list
{
    bool IsInList(Actor* const& a);
    void AddHead(Actor* const& a);
};
struct Crime
{
    int BackgroundTask;
    char pad[0x18];
    FUN_009eb9c0_list actors;
    void AddActor(Actor* apActor);
};
// @fnv 0x009eb9c0
void Crime::AddActor(Actor* apActor)
{
    if (!actors.IsInList(apActor))
    {
        actors.AddHead(apActor);
        BackgroundTask = BackgroundTask + 1;
    }
}
}  // namespace fnv_009eb9c0

struct FUN_009eba30_t;
struct FUN_009eba30_xl
{
    void Remove(FUN_009eba30_t* const& c);
};
struct FUN_0041cf00_shell
{
    FUN_009eba30_xl* ExtraDataList_GetPlayerCrimeList();
};
struct FUN_009eba30_node
{
    Actor** FUN_006815c0();
    FUN_009eba30_node* FUN_00726070();
};
struct FUN_009eba30_t
{
    int BackgroundTask;
    char pad[0x18];
    FUN_009eba30_node list;
    void Crime_ClearActorKnowList();
};
// @fnv 0x009eba30
// src: COMMUNITY 0x009eba30
void FUN_009eba30_t::Crime_ClearActorKnowList()
{
    FUN_009eba30_node* pnode = &list;
    while (pnode && *pnode->FUN_006815c0())
    {
        Actor* pActor = *pnode->FUN_006815c0();
        FUN_009eba30_xl* pList = reinterpret_cast<FUN_0041cf00_shell*>(const_cast<ExtraDataList*>(pActor->GetExtra()))->ExtraDataList_GetPlayerCrimeList();
        if (pList)
            pList->Remove(this);
        pnode = pnode->FUN_00726070();
    }
    BackgroundTask = 0;
}

// Constructs the object: initializes the base subobject and the embedded list member.
// @fnv 0x009ec5d0
AlarmPackage::AlarmPackage()
{}

// Constructs the object and, if apActor is non-null, adds it to the head of the list.
// @fnv 0x009ec670
AlarmPackage::AlarmPackage(Actor* apActor)
{
    if (apActor)
        list.AddHead(apActor);
}

// Destructor that removes all entries from the list member before the base package destructor runs.
// @fnv 0x009ec700
AlarmPackage::~AlarmPackage()
{
    list.RemoveAll();
}

void* __cdecl operator new(unsigned int);

struct FUN_009ebae0_shell
{
    void AddActorToList(Actor* a);
};

// Creates the BSSimpleList at offset 0x38 if null, then adds the given Actor to its head.
// @fnv 0x009ebae0
void FUN_009ebae0_shell::AddActorToList(Actor* apActor)
{
    if (!*(BSSimpleList<Actor*>**)((char*)this + 0x38))
    {
        *(BSSimpleList<Actor*>**)((char*)this + 0x38) = new BSSimpleList<Actor*>;
    }
    (*(BSSimpleList<Actor*>**)((char*)this + 0x38))->AddHead(apActor);
}


struct List_009e03e0
{
    void RemoveAll();
};

struct CrimeList
{
    int** _ref_006815c0();
    CrimeList* FUN_00726070();
};



// @fnv 0x009ec780
void AlarmPackage::CopyFromPackage(TESForm* apCopy)
{
    AlarmPackage* pAlarmSource;
    CrimeNode* pCurrentElementNext;

    ((DialoguePackage*)this)->CopyFromPackage(apCopy);
    ((List_009e03e0*)((char*)this + 0x80))->RemoveAll();
    pAlarmSource = dynamic_cast<AlarmPackage*>(apCopy);
    if (pAlarmSource)
    {
        pCurrentElementNext = pAlarmSource->GetCrimeList();
        while (pCurrentElementNext && *pCurrentElementNext->_ref_006815c0())
        {
            ((G2*)((char*)this + 0x80))->AddHead(*pCurrentElementNext->_ref_006815c0());
            pCurrentElementNext = pCurrentElementNext->FUN_00726070();
        }
    }
}

struct Saver
{
    unsigned short TESPackage_GetSaveSize();
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

TESForm* __cdecl _GetFormByNumericID(unsigned int);

// Exe 0x009ec890: unit-local AlarmpackageInterfaceView view used by this matched implementation.
struct AlarmpackageInterfaceView
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};

struct FormWithID
{
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetEditorID();
};


// @fnv 0x009ec890
unsigned short AlarmPackage::GetSaveSize()
{
    unsigned short isaveGameCount = 0;
    isaveGameCount += reinterpret_cast<Saver*>(this)->TESPackage_GetSaveSize();
    unsigned short isaveGameBufferPos = isaveGameCount;
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        isaveGameCount += 4;
        isaveGameCount += 2;
    }
    if (*g_011de4e8.Bool())
    {
        char* header = (char*)g_TESSaveLoadGame->GetHitSound();
        if (header)
        {
            TESForm* form = _GetFormByNumericID(*(unsigned int*)header);
            AlarmpackageInterfaceView::PrintDebugMessage(
                "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                isaveGameCount - isaveGameBufferPos, *(unsigned int*)header,
                reinterpret_cast<FormWithID*>(form)->GetEditorID(), *(unsigned int*)(header + 5), 491,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\AlarmPackage.cpp");
        }
        else
        {
            AlarmpackageInterfaceView::PrintDebugMessage("GetSaveSize(): %-5i ending at line %i in file %s",
                                         isaveGameCount - isaveGameBufferPos, 491,
                                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\AlarmPackage.cpp");
        }
    }
    return isaveGameCount;
}

extern ProcessLists DAT_011e0e80;

namespace fnv_009ecec0 {
struct CrimeNode : public BSSimpleList<Crime*>
{
    Crime** _ref_006815c0();
};


}  // namespace fnv_009ecec0

// Iterates the crime list, saving each crime's type byte and index, then writes the count and buffer position.
// @fnv 0x009ecec0
void AlarmPackage::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int isaveGameCount = 0;
    unsigned int isaveGameBufferPos = static_cast<BGSSaveFormBuffer*>(apSaveGameBuffer)->StartVariableSizedValue();
    fnv_009ecec0::CrimeNode* pCurrentElementNext = reinterpret_cast<fnv_009ecec0::CrimeNode*>((char*)this + 0x80);
    while (pCurrentElementNext)
    {
        Crime* pcrime = *pCurrentElementNext->_ref_006815c0();
        if (pcrime)
        {
            char ccrimeType = (char)((BSSimpleList<Crime*>*)pcrime)->GetNext();
            unsigned short icrimeIndex = DAT_011e0e80.Crime_CreateIndex(ccrimeType, pcrime);
            static_cast<BGSSaveFormBuffer*>(apSaveGameBuffer)->SaveData(&ccrimeType, 1, 0);
            static_cast<BGSSaveFormBuffer*>(apSaveGameBuffer)->SaveData(&icrimeIndex, 2, 0);
            isaveGameCount++;
        }
        pCurrentElementNext = static_cast<fnv_009ecec0::CrimeNode*>(pCurrentElementNext->GetNext());
    }
    static_cast<BGSSaveFormBuffer*>(apSaveGameBuffer)->SaveVariableSizedValue_00865ff0(isaveGameCount, isaveGameBufferPos);
}




// Loads the base package, then reads a count and for each entry reads a crime type and index, resolving each crime and adding it to the list at offset 0x80.
// @fnv 0x009ecf70
void AlarmPackage::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESPackage::LoadGame(static_cast<BGSLoadFormBuffer*>(apLoadGameBuffer));
    unsigned int isaveGameCount = static_cast<BGSLoadFormBuffer*>(apLoadGameBuffer)->ReadElementCount();
    for (unsigned int iIndex = 0; iIndex < isaveGameCount; ++iIndex)
    {
        char ccrimeType = 0;
        unsigned short icrimeIndex = 0;
        static_cast<BGSLoadFormBuffer*>(apLoadGameBuffer)->ReadTypedData(static_cast<void*>(&ccrimeType), 1u);
        static_cast<BGSLoadFormBuffer*>(apLoadGameBuffer)->ReadTypedData(static_cast<void*>(&icrimeIndex), 2u);
        Crime* pcrime = DAT_011e0e80.ProcessLists_GetCrimeByIndex(ccrimeType, icrimeIndex);
        if (pcrime)
        {
            reinterpret_cast<G2*>((char*)this + 0x80)->AddHead((int*&)pcrime);
        }
    }
}

extern TESSaveLoadGame* DAT_011de45c;
extern const char $SG7034[];
extern const char $SG7035[];
extern const char $SG7038[];

struct FUN_009ebb80_hit_sound
{
    unsigned int formID;
};

struct FUN_009ebb80_form
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual void v64()
    {}
    virtual void v65()
    {}
    virtual void v66()
    {}
    virtual void v67()
    {}
    virtual void v68()
    {}
    virtual void v69()
    {}
    virtual void v70()
    {}
    virtual void v71()
    {}
    virtual void v72()
    {}
    virtual const char* GetEditorID()
    {
        return 0;
    }
    virtual void v73()
    {}
    virtual void v74()
    {}
    virtual const char* v75()
    {
        return 0;
    }
};

struct FUN_009ebb80_shell
{
    char pad[0x1c];
    BSSimpleListTESRaceSize list;

    unsigned short Crime_GetSaveSize();
};

// @fnv 0x009ebb80
// src: COMMUNITY 0x009ebb80
unsigned short FUN_009ebb80_shell::Crime_GetSaveSize()
{
    unsigned short usTotalSize = 0;
    {
        unsigned short usStartSize = usTotalSize;
        FUN_009ebb80_hit_sound* SoundAssetTmp;

        if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
        {
            usTotalSize += 4;
            usTotalSize += 2;
        }

        usTotalSize += 0x10;
        usTotalSize += 0x10;
        usTotalSize += list.GetSize() * 4 + 2;

        if (*g_011de4e8.Bool())
        {
            SoundAssetTmp = reinterpret_cast<FUN_009ebb80_hit_sound*>(DAT_011de45c->GetHitSound());

            if (SoundAssetTmp)
            {
                FUN_009ebb80_form* pForm = reinterpret_cast<FUN_009ebb80_form*>(_GetFormByNumericID(SoundAssetTmp->formID));

                AlarmpackageInterfaceView::PrintDebugMessage(
                    $SG7035, usTotalSize - usStartSize, SoundAssetTmp->formID, pForm->v75(),
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(SoundAssetTmp) + 5), 0xf5, $SG7034);
            }
            else
            {
                AlarmpackageInterfaceView::PrintDebugMessage($SG7038, usTotalSize - usStartSize, 0xf5, $SG7034);
            }
        }

        return usTotalSize;
    }
}

struct SaveLocal
{
    void FUN_00865e50(void*, unsigned int, int);
    void FUN_00865df0(void*, int);
    unsigned int StartVariableSizedValue();
    void SaveVariableSizedValue_00865ff0(int, unsigned int);
};
struct AuxLocal
{
    unsigned int value;
    void SaveTimeStamp(SaveLocal*);
};
struct NodeLocal
{
    TESForm* item;
    NodeLocal* next;
    TESForm** FUN_006815c0();
    NodeLocal* FUN_00726070();
};
struct Candidate
{
    unsigned int unk00, unk04;
    TESForm* form08;
    TESForm* form0c;
    unsigned char flag10;
    TESForm* form14;
    unsigned int unk18;
    NodeLocal list1c;
    TESForm* form24;
    unsigned int unk28;
    unsigned char flag2c;
    unsigned int unk30;
    AuxLocal aux34;
    NodeLocal* list38;
    void SaveToStream(SaveLocal* buffer);
};
// Writes the candidate's scalar fields, aux34, four forms and both linked lists of forms to the save buffer, patching each list's count.
// @fnv 0x009ebfe0
void Candidate::SaveToStream(SaveLocal* buffer)
{
    buffer->FUN_00865e50(&unk00, 4, 0);
    buffer->FUN_00865e50(&unk04, 4, 0);
    buffer->FUN_00865e50(&flag10, 1, 0);
    buffer->FUN_00865e50(&unk18, 4, 0);
    buffer->FUN_00865e50(&unk28, 4, 0);
    buffer->FUN_00865e50(&flag2c, 1, 0);
    buffer->FUN_00865e50(&unk30, 4, 0);
    aux34.SaveTimeStamp(buffer);
    buffer->FUN_00865df0(form08, 0);
    buffer->FUN_00865df0(form0c, 0);
    buffer->FUN_00865df0(form14, 0);
    buffer->FUN_00865df0(form24, 0);
    int count6 = 0;
    unsigned int pos1 = buffer->StartVariableSizedValue();
    NodeLocal* node9 = &list1c;
    while (node9)
    {
        TESForm* item1 = *node9->FUN_006815c0();
        if (item1)
        {
            buffer->FUN_00865df0(item1, 0);
            ++count6;
        }
        node9 = node9->FUN_00726070();
    }
    buffer->SaveVariableSizedValue_00865ff0(count6, pos1);
    {
        int count7 = 0;
        unsigned int pos3 = buffer->StartVariableSizedValue();
        NodeLocal* nodeTmp = list38;
        while (nodeTmp)
        {
            TESForm* item6 = *nodeTmp->FUN_006815c0();
            if (item6)
            {
                buffer->FUN_00865df0(item6, 0);
                ++count7;
            }
            nodeTmp = nodeTmp->FUN_00726070();
        }
        buffer->SaveVariableSizedValue_00865ff0(count7, pos3);
    }
}

namespace fnv_00970b30 {
// 0x00970b30  /MT /Od /Oy- /GS /EHsc /Gy


struct ProcVt
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p180();
    virtual int v181(Actor* a, int b);
};

struct Arr
{
    unsigned int GetCount(unsigned char a);
    Actor* GetItem(unsigned int i);
};

extern "C" float DAT_01022958;
extern "C" Actor* g_thePlayer;

struct Cls
{
    char pad00[4];
    Actor* ProcessLists_GetActorRefInHigh_00970b30(TESFaction* fac, bool a2, bool a3);
};

// Scans the actor array for a faction member passing the rank and process checks, optionally picking the one with the lowest value from FUN_005723b0.
// @fnv 0x00970b30
// src: XBOX_PDB 0x00970b30
Actor* Cls::ProcessLists_GetActorRefInHigh_00970b30(TESFaction* pFaction, bool bRequireProcess, bool bPickBest)
{
    Actor* pB = 0;
    Actor* g4 = 0;
    float pE = DAT_01022958;
    Actor* e8 = 0;
    Actor* d4 = 0;
    Actor* c4 = 0;
    for (unsigned int i = 0; !(pB && bPickBest) && i < ((Arr*)((char*)this + 4))->GetCount(0); i++)
    {
        Actor* v20 = 0;
        float f24 = 0.0f;
        g4 = ((Arr*)((char*)this + 4))->GetItem(i);
        if (g4 && g4->IsActor())
            v20 = g4;
        if (v20 && !v20->HasHealth(0) && !v20->Actor_IsUnConscious() &&
            ((TESActorBaseData*)((char*)v20->GetActorBase() + 0x30))->GetFactionRank(pFaction, v20 == g_thePlayer) >
                -1 &&
            (!bRequireProcess || ((ProcVt*)v20->GetProcess())->v181(g_thePlayer, 0) > 0))
        {
            pB = v20;
            if (bPickBest)
            {
                f24 = v20->TESObjectREFR_GetDistanceFromReference(g_thePlayer, 0, 0);
                if (f24 < pE)
                {
                    e8 = v20;
                    if (e8->IsCreature())
                    {
                        c4 = e8;
                        e8 = 0;
                    }
                    pE = f24;
                }
            }
            if (v20->IsCreature())
            {
                d4 = pB;
                pB = 0;
            }
        }
    }
    if (!pB && d4)
    {
        pB = d4;
        if (bPickBest)
        {
            e8 = c4;
            pB = e8;
        }
    }
    else
    {
        if (bPickBest && e8)
            pB = e8;
    }
    return pB;
}
}  // namespace fnv_00970b30

// WriteToSave - Candidate::SaveGame (BLOK block writer)

struct MyNode;

struct FormRec
{
    unsigned int formID;
    unsigned char unk04;
    unsigned int flags;
};

struct MyNode
{
    TESForm* item;
    MyNode* next;
    bool FUN_008256d0();
    TESForm** FUN_006815c0();
    MyNode* FUN_00726070();
};

extern TESSaveLoadGame* g_save;

extern const char DAT_010153a0[];
extern const char DAT_0101536c[];
extern const char DAT_01015318[];
extern const char DAT_01092b94[];

void __cdecl DebugPrint(const char* fmt, ...);
void __cdecl Warn3(const char* a, const char* b, int line);

struct MyCand
{
    int unk00;
    int unk04;
    TESForm* form08;
    TESForm* form0c;
    unsigned char flag10;
    char pad10[3];
    TESForm* form14;
    unsigned int unk18;
    MyNode list1c;
    TESForm* form24;
    unsigned int unk28;
    unsigned char flag2c;
    char pad2c[3];
    unsigned int unk30;
    unsigned int aux34;
    MyNode* list38;
    void WriteToSave();
};

// Serializes the candidate's flags, form IDs and linked-list form IDs to the save stream, with optional block header and size patching.
// @fnv 0x009ebca0
void MyCand::WriteToSave()
{
    unsigned short a7 = 0;
    char* aa = 0;
    char* a9 = g_save->GetCurrentPosition();

    if (*g_011de4e8.Bool())
        a9 = g_save->GetCurrentPosition();

    if (g_save->TESSaveLoadGame_UseSaveGameBlocks())
    {
        int a5 = 0x424c4f4b;
        g_save->TESSaveLoadGame_SaveGameDataOLD(&a5, 4);
        aa = g_save->GetCurrentPosition();
        g_save->TESSaveLoadGame_SaveGameDataOLD(&a7, 2);
    }

    g_save->TESSaveLoadGame_SaveGameDataOLD(&flag10, 1);
    g_save->TESSaveLoadGame_SaveGameDataOLD(&flag2c, 1);
    g_save->TESSaveLoadGame_SaveGameDataOLD(&unk04, 4);
    g_save->TESSaveLoadGame_SaveGameDataOLD(&unk18, 4);
    g_save->TESSaveLoadGame_SaveGameDataOLD(&unk28, 4);

    int a1 = 0;
    if (form08)
        a1 = form08->GetFormID();
    g_save->TESSaveLoadGame_SaveNumericID(&a1, 4);

    int a1c = 0;
    if (form0c)
        a1c = form0c->GetFormID();
    g_save->TESSaveLoadGame_SaveNumericID(&a1c, 4);

    int actor2 = 0;
    if (form14)
        actor2 = form14->GetFormID();
    g_save->TESSaveLoadGame_SaveNumericID(&actor2, 4);

    int ang4 = 0;
    if (form24)
        ang4 = form24->GetFormID();
    g_save->TESSaveLoadGame_SaveNumericID(&ang4, 4);

    unsigned short a38 = 0;
    unsigned short* a8 = (unsigned short*)g_save->GetCurrentPosition();
    g_save->TESSaveLoadGame_SaveGameDataOLD(&a38, 2);

    MyNode* action9 = &list1c;
    while (action9 && !action9->FUN_008256d0())
    {
        TESForm* active = *action9->FUN_006815c0();
        int ac = active->GetFormID();
        g_save->TESSaveLoadGame_SaveNumericID(&ac, 4);
        a38++;
        action9 = action9->FUN_00726070();
    }
    *(unsigned short*)a8 = a38;

    if (*g_011de4e8.Bool())
    {
        char* a4 = g_save->GetCurrentPosition();
        FormRec* ang8 = static_cast<FormRec*>(g_save->FUN_004fd3e0());
        if (ang8)
        {
            TESForm* pLookup = GetFormByID(ang8->formID);
            DebugPrint(DAT_010153a0, a4 - a9, ang8->formID, ((FormWithID*)pLookup)->GetEditorID(),
                       *(unsigned int*)((char*)ang8 + 5), 301, DAT_01092b94);
        }
        else
        {
            DebugPrint(DAT_0101536c, a4 - a9, 301, DAT_01092b94);
        }
    }

    if (g_save->TESSaveLoadGame_UseSaveGameBlocks())
    {
        char* agg = g_save->GetCurrentPosition();
        char* agg4 = aa;
        if (agg > agg4 + 0xffff)
            Warn3(DAT_01015318, DAT_01092b94, 301);
        *(unsigned short*)aa = (unsigned short)(agg - agg4);
    }
}

extern "C" char DAT_01183108;
extern "C" char DAT_01183028;
extern "C" char DAT_01184704;
TESForm* __cdecl TESForm_GetFormByNumericID(void*);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct List009
{
    char data[8];
    List009();
    ~List009();
    void FUN_005ae3d0(void**);
    void** FUN_006815c0();
};
struct Field009
{
    void FUN_009a5ff0(BGSLoadFormBuffer*);
};
struct Host009
{
    unsigned a, b, c, d;
    char e;
    char pad11[3];
    void* f;
    unsigned g;
    List009 list;
    unsigned h, j;
    char k;
    char pad2d[3];
    unsigned l;
    Field009 field;
    char pad35[3];
    List009* strings;
    void ReadFromStream(BGSLoadFormBuffer* r);
};
// Reads fields, a nested field, form references and two lists from the stream, then discards the faction list if it is empty.
// @fnv 0x009ec1a0
void Host009::ReadFromStream(BGSLoadFormBuffer* apReader)
{
    apReader->LoadData(&a, 4);
    apReader->LoadData(&b, 4);
    apReader->LoadData(&e, 1);
    apReader->LoadData(&g, 4);
    apReader->LoadData(&j, 4);
    apReader->LoadData(&k, 1);
    apReader->LoadData(&l, 4);
    field.FUN_009a5ff0(apReader);
    apReader->FUN_008648e0(&c);
    apReader->FUN_008648e0(&d);
    f = dynamic_cast<TESBoundObject*>(TESForm_GetFormByNumericID(reinterpret_cast<void*>(apReader->FUN_008648a0())));
    apReader->FUN_008648e0(&h);
    {
        unsigned count = apReader->FUN_00864a60();
        for (unsigned i = 0; i < count; i++)
        {
            void* item = 0;
            apReader->FUN_008648e0(&item);
            list.FUN_005ae3d0(&item);
        }
    }
    strings = new List009;
    {
        unsigned uiFactionCount = apReader->FUN_00864a60();
        for (unsigned uiFactionIndex = 0; uiFactionIndex < uiFactionCount; uiFactionIndex++)
        {
            void* pFaction = 0;
            pFaction = dynamic_cast<TESFaction*>(TESForm_GetFormByNumericID(reinterpret_cast<void*>(apReader->FUN_008648a0())));
            if (pFaction)
                strings->FUN_005ae3d0(&pFaction);
        }
    }
    if (!*strings->FUN_006815c0())
    {
        delete strings;
        strings = 0;
    }
}

struct S00679120
{
    void SavePackage();
};
extern "C" void* _ref_004839c0(unsigned int formID);
extern "C" void Log9EC990(const char* fmt, ...);
extern "C" void Warn9EC990(const char* fmt, ...);


// @fnv 0x009ec990
void AlarmPackageUnitOperations::SaveGameLegacy()
{
    ((S00679120*)this)->SavePackage();

    unsigned short usVersion7 = 0;
    unsigned short* pSizeTmp = 0;
    unsigned int uiStart3 = g_TESSaveLoadGame->GetTimeStamp();
    if (*g_011de4e8.Bool())
        uiStart3 = g_TESSaveLoadGame->GetTimeStamp();

    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiMagic_2 = 0x424c4f4b;
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&uiMagic_2, 4);
        pSizeTmp = (unsigned short*)g_TESSaveLoadGame->GetTimeStamp();
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&usVersion7, 2);
    }

    unsigned short m_usPassCountLocal = 0;
    unsigned short* aPCount = (unsigned short*)g_TESSaveLoadGame->GetTimeStamp();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_usPassCountLocal, 2);

    BSSimpleList<void*>* pNodeX = 0;
    while (pNodeX != 0 && !pNodeX->IsEmpty())
    {
        void* pv = pNodeX->GetItem();
        char cIndex2 = (char)((CrimeList*)pv)->FUN_00726070();
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&cIndex2, 1);
        unsigned short usResult6 = DAT_011e0e80.Crime_CreateIndex((int)cIndex2, static_cast<Crime*>(pv));
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&usResult6, 2);
        m_usPassCountLocal++;
        pNodeX = pNodeX->GetNext();
    }
    *aPCount = m_usPassCountLocal;

    if (*g_011de4e8.Bool())
    {
        unsigned int uiEnd = g_TESSaveLoadGame->GetTimeStamp();
        unsigned char* pRec9 = (unsigned char*)g_TESSaveLoadGame->GetHitSound();
        if (pRec9 != 0)
        {
            FormWithID* pForm3 = (FormWithID*)_ref_004839c0(*(unsigned int*)pRec9);
            Log9EC990("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                      uiEnd - uiStart3, *(unsigned int*)pRec9, pForm3->GetEditorID(), *(unsigned int*)(pRec9 + 5), 526,
                      "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\AlarmPackage.cpp");
        }
        else
        {
            Log9EC990("SaveGame(): %-5i ending at line %i in file %s", uiEnd - uiStart3, 526,
                      "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\AlarmPackage.cpp");
        }
    }

    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiEnd9 = g_TESSaveLoadGame->GetTimeStamp();
        unsigned int uiStart2 = (unsigned int)pSizeTmp;
        if (uiEnd9 > uiStart2 + 0xffff)
            Warn9EC990("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\AlarmPackage.cpp", 526);
        *(unsigned short*)pSizeTmp = (unsigned short)(uiEnd9 - uiStart2);
    }
}



struct AlarmActorList
{
    Actor* data;
    AlarmActorList* next;
    bool FUN_008256d0();
    Actor** FUN_006815c0();
    AlarmActorList* FUN_00726070();
    void FUN_00726c60(Actor* const& actor);
    void RemoveMatchingItem(Actor** data);
    void FUN_0063f7b0();
};
struct AlarmPackageData
{
    int unk00;
    int unk04;
    TESObjectREFR* ref;
    Actor* actor;
    int unk10;
    int unk14;
    int unk18;
    AlarmActorList actors;
    TESForm* other;
    void Crime_InitLoadGame(void* unused);
};

// @fnv 0x009ec400
// src: XBOX_PDB 0x009ec400
void AlarmPackageData::Crime_InitLoadGame(void* unused)
{
    ref = ref ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)ref)) : 0;
    actor = actor ? dynamic_cast<Actor*>(GetFormByID((unsigned int)actor)) : 0;
    other = other ? GetFormByID((unsigned int)other) : 0;
    AlarmActorList* current = &actors;
    AlarmActorList* previous = 0;
    while (current && !current->FUN_008256d0())
    {
        Actor* entry = *current->FUN_006815c0();
        bool erase = false;
        if (entry)
        {
            entry = entry ? dynamic_cast<Actor*>(GetFormByID((unsigned int)entry)) : 0;
            if (entry)
            {
                current->FUN_00726c60(entry);
            }
            else
            {
                erase = true;
            }
        }
        else
        {
            erase = true;
        }
        if (erase)
        {
            if (previous)
            {
                previous->RemoveMatchingItem(current->FUN_006815c0());
                current = previous->FUN_00726070();
            }
            else
            {
                current->FUN_0063f7b0();
            }
        }
        else
        {
            previous = current;
            current = current->FUN_00726070();
        }
    }
    if (ref)
    {
        ref->TESObjectREFR_SetTargeted(1);
    }
}
