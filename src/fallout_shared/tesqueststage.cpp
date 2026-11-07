// fallout_shared/tesqueststage.cpp: PlayerQuestData, TESQuest, StageHolder (15 functions)

#include "../../include/MemoryManager.h"
#include "../../include/PerkEntryConditionSet.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/Script.h"
#include "../../include/ScriptHeaderData.h"
#include "../../include/ScriptReferencedObject.h"
#include "../../include/ScriptVariableInfo.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"

#include "tesqueststage_decls.h"
#include <malloc.h>

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern "C" const char DAT_0104af30[];
int __cdecl Warning(const char* format, ...);
bool __cdecl FUN_005ac740();

// @fnv 0x0060f6a0
bool PlayerQuestData::Load(TESFile* file)
{
    if (!file)
        return false;

    switch (static_cast<int>(file->GetChunkID()))
    {
    case 0x44534c53:
    case 0x52564353:
        if (file->GetChunkID() == 0x44534c53)
        {
            DAT_011cb8ec = new ScriptVariableInfo();
            DAT_011cb8ec->Load(file);
            m_pScript.GetVariableList()->AddTail(DAT_011cb8ec);
        }
        else if (DAT_011cb8ec)
        {
            char* data = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(data, 0x200);
            DAT_011cb8ec->name.Set(data, 0);
        }
        break;
    case 0x52484353: {
        file->GetChunkData(m_pScript.GetHeader(), 0);
        if (file->IsEndianConversionRequired())
            m_pScript.GetHeader()->Endian();
        break;
    }
    case 0x41444353: {
        unsigned int size = file->GetChunkSize();
        char* data = static_cast<char*>(_alloca(size));
        memset(data, 0, size);
        file->GetChunkData(data, 0);
        m_pScript.SetScriptData(size, data);
        break;
    }
    case 0x4f524353: {
        ScriptReferencedObject* object = new ScriptReferencedObject();
        unsigned int value;
        file->GetChunkData(&value);
        object->pForm = reinterpret_cast<TESForm*>(value);
        m_pScript.GetReferencedObjectList()->AddTail(object);
        break;
    }
    case 0x56524353: {
        ScriptReferencedObject* object = new ScriptReferencedObject();
        unsigned int value;
        file->GetChunkData(&value);
        object->m_uiFormID = value;
        m_pScript.GetReferencedObjectList()->AddTail(object);
        break;
    }
    case 0x54445351:
        m_formID = file->GetOffset();
        file->GetChunkData(this, 1);
        break;
    }

    if (!file->NextChunk())
        return false;
    if (file->GetChunkID() == 0x304d414e)
    {
        unsigned int nameIndex;
        file->GetChunkData(&nameIndex);
        m_nameIndex = nameIndex;
        if (!file->NextChunk())
            return false;
    }
    return true;
}

// Empty destructor for the object; performs no work.
// @fnv 0x0060c840
QuestStage::~QuestStage()
{}

void TriggerTESQuestStageDelete(QuestStage* stage)
{
    delete stage;
}

// Reads a QSTA chunk from the file, applies endian conversion if needed, and stores its two fields into the object.
// @fnv 0x00610120
void RegionObjectEntry::Load(TESFile* file)
{
    if (file)
    {
        if (file->GetChunkID() == 0x41545351)
        {
            RegionDataEntry data;
            memset(&data, 0, 8);
            file->GetChunkData(&data, 0);
            if (file->IsEndianConversionRequired())
                data.Endian();
            m_uiEdgeIndex = data.m_ucClipIdentifier;
            m_done = data.m_bCompleted;
        }
    }
}

// @fnv 0x0060fb60
void QuestStage::MarkDone(bool done)
{
    if (m_pCompletionDate && m_pSharedOwner && !m_pSharedOwner->GetAllowRepeatStages())
    {
        Warning(DAT_0104af30);
        return;
    }
    if (done || reinterpret_cast<PlayerQuestData*>(this)->GetConditions()->ContainsTrait(g_thePlayer, 0))
    {
        m_pCompletionDate = new Date(g_calendar.GetGameHour(), g_calendar.GetCurrentMonth(), g_calendar.Calendar_GetYear());

        if (TESQuestStageItem_GetEndQuest())
        {
            if (m_pSharedOwner)
            {
                m_pSharedOwner->MarkCompleted(true);
                if (m_pSharedOwner == g_thePlayer->PlayerCharacter_GetActiveQuest())
                    g_thePlayer->SetActiveQuest(0);
            }
        }
        if (IsFlag2Set())
        {
            if (m_pSharedOwner)
            {
                m_pSharedOwner->SetQuestCompleted(true);
                if (m_pSharedOwner == g_thePlayer->PlayerCharacter_GetActiveQuest())
                    g_thePlayer->SetActiveQuest(0);
            }
        }
        if (m_bCompleteObjective)
            g_thePlayer->CompleteQuestObjective(reinterpret_cast<PlayerQuestData*>(this));

        Script* script = GetOffsetC();
        if (FUN_005ac740() && script && script->GetHeader()->dataSize)
        {
            script->GetHeader()->m_bQuest = false;
            script->Run(g_thePlayer, g_thePlayer->BSFile_GetDevice(false, true)->ExtraDataList_GetScriptLocals());
        }
    }
}

// Walks the quest's stage list and returns the entry whose index matches the given index, or null if none matches.
// @fnv 0x0060db40
QuestStage* TESQuest::GetStage(unsigned char index)
{
    BSSimpleList<TESFile*>* stage = reinterpret_cast<BSSimpleList<TESFile*>*>(GetStageList());
    while (stage)
    {
        QuestStage* item = reinterpret_cast<QuestStage*>(stage->GetItem());
        if (item && item->GetIndex() == index)
            return item;
        stage = stage->GetNext();
    }
    return 0;
}

// @fnv 0x0060fa10
void PlayerQuestData::InitItem(TESForm* form, QuestStage* stage)
{
    int iErrorCount;
    unsigned int auiFormId;
    unsigned int iOldCount;
    if (GetConditions())
        GetConditions()->InitItem(form);
    iOldCount = Warning();
    SetWarningState(true);
    BGSMessageWarningAuxiliary(0);
    GetOffsetC()->InitItem(form);
    SetWarningState(false);
    iErrorCount = Warning();
    BGSMessageWarningAuxiliary(iOldCount);
    if (iErrorCount)
        Warning(DAT_0104ae98, stage->GetIndex(), static_cast<const TESForm*>(form)->GetName(), form->GetDescription());
    m_pSharedOwner = dynamic_cast<TESQuest*>(form);
    auiFormId = m_nameIndex;
    if (auiFormId)
    {
        TESForm::RemapFormIDForFile(auiFormId, form->GetFile(-1));
        TESQuest* next = dynamic_cast<TESQuest*>(TESForm::GetFormByID(auiFormId));
        if (!next)
            Warning(DAT_0104ae54, auiFormId);
        SetNextQuest(next);
    }
}

void __fastcall ResetFlags(void* pThis);

// The 8-byte item list at quest stage +4 (a BSSimpleList: ctor 0x0096a2d0, dtor 0x0046ffb0 via FUN_0060f260).
class QuestStageItemList
{
  public:
    QuestStageItemList();
};

// @fnv 0x0060f210
// src: COMMUNITY 0x0060f210
void* __fastcall TESQuestStage_TESQuestStage(char* pThis)
{
    ResetFlags(pThis);
    ((QuestStageItemList*)(pThis + 4))->QuestStageItemList::QuestStageItemList();
    return pThis;
}

struct IntList
{
    ~IntList();
};
struct FUN_0060f260
{
    char pad[4];
    IntList list;
    void ProcessEntries_0060f3a0();
    ~FUN_0060f260();
};
// @fnv 0x0060f260
FUN_0060f260::~FUN_0060f260()
{
    ProcessEntries_0060f3a0();
}

struct FUN_0060f320_shell : public QuestStage
{
    void TESQuestStage_InitItem(TESForm*);
};

struct StageItemNode;
StageItemNode* __fastcall FUN_00717e50(void* p);
PlayerQuestData** __fastcall _ref_006815c0(StageItemNode* node);
StageItemNode* __fastcall _ref_00726070(StageItemNode* node);

// Walks the stage item list, calls InitItem on each non-null item, clears a header byte, and counts the items.
// @fnv 0x0060f320
// src: COMMUNITY 0x0060f320
void FUN_0060f320_shell::TESQuestStage_InitItem(TESForm* apOwner)
{
    StageItemNode* pNode = FUN_00717e50(this);
    int iCount = 0;
    while (pNode)
    {
        PlayerQuestData* pitem = *_ref_006815c0(pNode);
        if (pitem)
        {
            pitem->InitItem(apOwner, this);
            reinterpret_cast<unsigned char*>(pitem->GetOffsetC()->GetHeader())[0x10] = 0;
            iCount = iCount + 1;
        }
        pNode = _ref_00726070(pNode);
    }
}

struct StageHolder
{
    bool GetDone();
    BSSimpleList<QuestStage*>* GetConditions();
    void TESQuestStage_SetDone(TESQuest* quest, bool done);
};
// @fnv 0x0060f4a0
// src: XBOX_PDB 0x0060f4a0
void StageHolder::TESQuestStage_SetDone(TESQuest* quest, bool done)
{
    QuestStage* stage;
    BSSimpleList<QuestStage*>* list;
    if (!GetDone() || (quest && quest->GetAllowRepeatStages()))
    {
        ((char*)this)[1] = 1;
        list = GetConditions();
        while (list)
        {
            stage = list->GetItem();
            list = list->GetNext();
            if (stage)
                stage->MarkDone(done);
        }
    }
}

struct FUN_0060f520
{
    char b0[4];
    PerkEntryConditionSet cond;
    Script script;
    int v60;
    char v64;
    char v65;
    char pad[2];
    int v68;
    int v6c;
    int v70;
    FUN_0060f520();
};
// @fnv 0x0060f520
FUN_0060f520::FUN_0060f520()
{
    memset(this, 0, 1);
    v70 = 0;
    script.SetInitializationState(false);
    script.NotifySaveLoadGameOfFormChange();
    script.GetHeader()->m_bQuest = true;
    v60 = 0;
    v68 = 0;
    v6c = 0;
    v64 = 0;
    v65 = 0;
}

struct FUN_0060fd70_shell : public PlayerQuestData
{
    bool TESQuestStageItem_GetEndQuest();
};

// @fnv 0x0060fd70
// src: XBOX_PDB 0x0060fd70
bool FUN_0060fd70_shell::TESQuestStageItem_GetEndQuest()
{
    return (*(unsigned char*)this & 1) != 0;
}

namespace fnv_0060f2c0 {
struct StageItemNode;
StageItemNode* __fastcall FUN_00717e50(void*);
const char** __fastcall _ref_006815c0(void*);
StageItemNode* __fastcall _ref_00726070(void*);
char __fastcall BGSBodyPart_GetToHitChance(char const*);
struct FUN_0060f2c0_shell
{
    const char* FindItemByDoneFlag(unsigned char);
};
// Walks the linked StageItemNode list, returning the first item whose FUN_005dc980 result equals done, or null.
// @fnv 0x0060f2c0
const char* FUN_0060f2c0_shell::FindItemByDoneFlag(unsigned char done)
{
    StageItemNode* pNode = FUN_00717e50(this);
    while (pNode)
    {
        const char* item = *_ref_006815c0(pNode);
        if (item && (unsigned char)BGSBodyPart_GetToHitChance(item) == done)
            return item;
        pNode = _ref_00726070(pNode);
    }
    return 0;
}
}  // namespace fnv_0060f2c0

// Stage reset helper: clears the two flag bytes of the stage object and
// hands the object back to the caller.
class FUN_0060f240_cls
{
  public:
    unsigned char m_bDone;
    unsigned char m_bHasSomething;
    FUN_0060f240_cls* ResetFlags();
};

// @fnv 0x0060f240
FUN_0060f240_cls* FUN_0060f240_cls::ResetFlags()
{
    m_bDone = 0;
    m_bHasSomething = 0;
    return this;
}

// Destructor: clear the shared current-entry globals and free the owned decal data; the member lists go after.

class F5F0String
{
  public:
    bool Set(const char* pcText, unsigned int uiLength);
};

extern int g_iF5F0CurrentEntry;
extern F5F0String g_kF5F0CurrentName;

class F5F0DecalData
{
  public:
    ~F5F0DecalData();
    int unk00;
};

class FUN_0060f5f0
{
  public:
    ~FUN_0060f5f0();

    int m_iArrayLength;
    PerkEntryConditionSet m_kConditions;
    Script m_kScript;
    int unk60;
    int unk64;
    F5F0DecalData* m_pkDecalData;
};

// Resets the current entry index and name, then deletes m_pkDecalData if set.
// @fnv 0x0060f5f0
FUN_0060f5f0::~FUN_0060f5f0()
{
    g_iF5F0CurrentEntry = 0;
    g_kF5F0CurrentName.Set(0, 0);
    if (m_pkDecalData)
        delete m_pkDecalData;
}
