#include "../../include/SettingT.h"
// fallout_shared/tesquest.cpp: TESQuest and quest stage/save support

#include <stddef.h>
#define FNV_ASSERT(name, expression) typedef char name[(expression) ? 1 : -1]
class TESForm;
class TESObjectREFR;
class TESActorBase;
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/BSSimpleList.h"
#include "../../include/BSStringT.h"
#include "../../include/SETTING_VALUE.h"

#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/BGSQuestObjective.h"
#include "../../include/PerkEntryConditionSet.h"
#include "../../include/QuestData.h"
#include "../../include/Script.h"
#include "../../include/ScriptLocals.h"
#include "../../include/TESFile.h"
#include "../../include/TESRecipe.h"
#include "../../include/TESQuest.h"

FNV_ASSERT(FormSize, sizeof(TESForm) == 0x18);
FNV_ASSERT(FormIDOffset, offsetof(TESForm, iFormID) == 0x0c);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* memory);
void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* memory);

class PlayerQuestData;
class RegionObjectEntry;
class AnimationClipStatus
{
  public:
    unsigned char m_ucClipIdentifier;
    bool m_bCompleted;
};
class QuestStage
{
  public:
    AnimationClipStatus m_Data;
    unsigned char layoutPadding2[2];
    BSSimpleList<PlayerQuestData*> m_kStageItems;
    QuestStage();
    ~QuestStage();
    bool GetDone();
    unsigned char GetIndex();
    void SetIndex(unsigned char index);
    void MarkDone(TESQuest* quest, bool allItems);
    void MarkDone(bool done);
    PlayerQuestData* GetStageItemByIndex(unsigned char index);
    BSSimpleList<PlayerQuestData*>* GetStageItemList();
    void InitItem(TESForm* owner);
    void Load(TESFile* file);
    void AddStageItem(PlayerQuestData* item);
};
class RegionObjectEntry
{
  public:
    unsigned char cFlags;
    unsigned char layoutPadding1[3];
    PerkEntryConditionSet m_kInfoConditions;
    TESObjectREFR* m_pReference;
    unsigned int m_auiData[14];
    RegionObjectEntry();
    void Load(TESFile* file);
    TESObjectREFR* GetReference(bool resolve);
    PerkEntryConditionSet* GetConditions();
};
class Date
{
  public:
    unsigned short usDate, usYear;
    Date();
    Date(const Date& date);
    ~Date();
};
class PlayerQuestData
{
  public:
    unsigned char m_ucEntryType;
    unsigned char layoutPadding1[3];
    PerkEntryConditionSet m_kInfoConditions;
    Script ScriptData;
    unsigned int uiFileOffset;
    unsigned char m_ucClipIdentifier;
    bool bHasLogEntry;
    unsigned char layoutPadding66[2];
    Date* pLogDate;
    TESQuest* pOwner;
    TESQuest* pNextQuest;
    PlayerQuestData();
    bool Load(TESFile* file);
    void SetIndex(unsigned char index);
    void SetHasLogEntry(bool value);
    PerkEntryConditionSet* GetConditions();
    Date* GetLogDate();
    void SetLogDate(Date* date);
};
// These save/load-buffer entry points return a trivial mask in the original ABI.
// Keep that ABI independent of pending FormChangeMask destructor changes.
class QuestChangeMask
{
  public:
    unsigned int flags;
    operator bool() const { return flags != 0; }
};

class QuestLoadChangeFlags : public BGSLoadFormBuffer
{
  public:
    QuestChangeMask GetChangeFlags(unsigned int mask);
    QuestChangeMask GetOldChangeFlags(unsigned int mask);
};

class QuestSaveChangeFlags : public BGSSaveFormBuffer
{
  public:
    QuestChangeMask GetChangeFlags(unsigned int mask);
};

void __cdecl LogWarning(const char* message, ...);
extern "C" void* __cdecl _alloca(unsigned int size);
class INISettingCollection;
using ::SettingT;
extern SettingT<INISettingCollection> bActivateAllQuestScripts;
FNV_ASSERT(QuestSize, sizeof(TESQuest) == 0x6c);
FNV_ASSERT(QuestStageListOffset, offsetof(TESQuest, m_kStageList) == 0x44);
FNV_ASSERT(QuestLocalsOffset, offsetof(TESQuest, m_pScriptLocals) == 0x5c);
FNV_ASSERT(QuestCurrentStageOffset, offsetof(TESQuest, m_ucEnabled) == 0x60);
FNV_ASSERT(QuestStageSize, sizeof(QuestStage) == 0x0c);
FNV_ASSERT(QuestObjectiveSize, sizeof(BGSQuestObjective) == 0x24);
FNV_ASSERT(QuestStageItemSize, sizeof(PlayerQuestData) == 0x74);
FNV_ASSERT(QuestTargetSize, sizeof(RegionObjectEntry) == 0x48);
FNV_ASSERT(DateSize, sizeof(Date) == 4);
FNV_ASSERT(ScriptLocalsSize, sizeof(ScriptLocals) == 0x14);

// @fnv 0x0060d700
unsigned int TESQuest::GetStageMask()
{
    return m_ucEnabled;
}

// @fnv 0x0060c740
void TESQuest::ResetFormData()
{
    SetEnabled(true);
    m_ucEnabled = 0;
}

// Deletes every stage object in the quest's stage list and removes each entry until the list is empty.
// @fnv 0x0060c7d0
void TESQuest::RemoveAllStages()
{
    BSSimpleList<QuestStage*>* stages = GetStageList();
    while (stages && !stages->IsEmpty())
    {
        delete stages->GetItem();
        stages->RemoveHead();
    }
}

// Walks the quest's stage list and returns whether the stage with the given index is marked done, or false if not found.
// @fnv 0x0060d600
bool TESQuest::HasStage(unsigned char ucStageIndex)
{
    BSSimpleList<QuestStage*>* stages = GetStageList();
    while (stages && !stages->IsEmpty())
    {
        if (stages->GetItem()->GetIndex() == ucStageIndex)
            return stages->GetItem()->GetDone();
        stages = stages->GetNext();
    }
    return false;
}

// @fnv 0x0060c760
void TESQuest::ClearData()
{
    GetConditions()->InitializeConditionItems();
    RemoveAllStages();
    ClearObjectives();
    if (m_pScriptLocals)
    {
        delete m_pScriptLocals;
        m_pScriptLocals = 0;
    }
}

// Deletes every BGSQuestObjective in the objective list and removes each entry until the list is empty.
// @fnv 0x0060c870
void TESQuest::ClearObjectives()
{
    BSSimpleList<BGSQuestObjective*>* objectives = GetObjectiveList();
    while (objectives && !objectives->IsEmpty())
    {
        delete objectives->GetItem();
        objectives->RemoveHead();
    }
}

// @fnv 0x0060f110
void TESQuest::GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets,
                                       BSSimpleList<BGSQuestObjective*>* objectives)
{
    if (!targets)
        return;
    targets->RemoveAll();
    if (GetCompleted())
        return;
    BSSimpleList<BGSQuestObjective*>* pObjectiveNode = GetObjectiveList();
    while (pObjectiveNode && pObjectiveNode->GetItem())
    {
        if (objectives->IsInList(pObjectiveNode->GetItem()))
            pObjectiveNode->GetItem()->GetTargetsAndObjectives(targets);
        pObjectiveNode = pObjectiveNode->GetNext();
    }
}

// Scans the stage list for the highest done stage index and stores it into the quest's highest completed stage field if greater.
// @fnv 0x0060d670
void TESQuest::UpdateStageMask()
{
    BSSimpleList<QuestStage*>* stages = GetStageList();
    unsigned char currentStage = 0;
    while (stages && !stages->IsEmpty())
    {
        QuestStage* stage = stages->GetItem();
        if (stage->GetDone() && stage->GetIndex() > currentStage)
            currentStage = stage->GetIndex();
        stages = stages->GetNext();
    }
    if (currentStage > m_ucEnabled)
        m_ucEnabled = currentStage;
}

// @fnv 0x0060d510
bool TESQuest::IsStageComplete(unsigned char ucStageIndex)
{
    BSSimpleList<QuestStage*>* stages = GetStageList();
    while (stages && !stages->IsEmpty())
    {
        if (stages->GetItem()->GetIndex() == ucStageIndex)
        {
            if (!GetCompleted() || GetAllowRepeatStages())
                SetEnabled(true);
            if (ucStageIndex > m_ucEnabled)
                m_ucEnabled = ucStageIndex;
            stages->GetItem()->MarkDone(this, false);
            MarkAsModified(0x80000000U);
            return true;
        }
        stages = stages->GetNext();
    }
    return false;
}

// @fnv 0x0060EFD0
bool TESQuest::HasTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets,
                                       BSSimpleList<BGSQuestObjective*>* objectives)
{
    BSSimpleList<RegionObjectEntry*>* currentTarget = targets;
    BSSimpleList<BGSQuestObjective*>* currentObjective = GetObjectiveList();
    if (currentTarget && currentObjective)
    {
        while (currentObjective)
        {
            if (currentObjective->GetItem() && currentObjective->GetItem()->GetState() == QOS_DISPLAYED &&
                objectives->IsInList(currentObjective->GetItem()))
            {
                BSSimpleList<RegionObjectEntry*>* objectiveTarget = currentObjective->GetItem()->GetTargetList();
                while (objectiveTarget)
                {
                    RegionObjectEntry* target = objectiveTarget->GetItem();
                    if (target && target->GetConditions()->ContainsTrait(target->GetReference(false), 0))
                    {
                        if (!currentTarget || !currentTarget->GetItem() || currentTarget->GetItem() != target)
                            return false;
                        if (currentTarget)
                            currentTarget = currentTarget->GetNext();
                    }
                    objectiveTarget = objectiveTarget->GetNext();
                }
            }
            currentObjective = currentObjective->GetNext();
        }
    }
    if (currentTarget && !currentTarget->IsEmpty())
        return false;
    return true;
}

// @fnv 0x0060CBA0
void TESQuest::InitItem()
{
    if (IsFormInitialized())
        return;
    TESScriptableForm::InitItem(this);
    if (TESScriptableForm::GetScript())
    {
        m_pScriptLocals = TESScriptableForm::GetScript()->GetOrCreateScriptLocals();
        TESScriptableForm::GetScript()->SetOwnerQuest(this);
        if (m_pScriptLocals)
            SetFormFlags(0x40000000);
        if (bActivateAllQuestScripts.Bool()[0])
            SetEnabled(true);
    }
    if (GetConditions())
        GetConditions()->InitItem(this);
    BSSimpleList<QuestStage*>* stage = GetStageList();
    while (stage && !stage->IsEmpty())
    {
        stage->GetItem()->InitItem(this);
        stage = stage->GetNext();
    }
    BSSimpleList<BGSQuestObjective*>* objective = GetObjectiveList();
    while (objective && !objective->IsEmpty())
    {
        objective->GetItem()->InitItem(this);
        objective = objective->GetNext();
    }
    SetStartsEnabled(GetEnabled());
    SetInitializationState(true);
}

// @fnv 0x0060EE40
void TESQuest::Revert(BGSLoadFormBuffer* buffer)
{
    TESForm::Revert(buffer);
    if (static_cast<QuestLoadChangeFlags*>(buffer)->GetOldChangeFlags(0x80000000U).operator bool())
    {
        BSSimpleList<QuestStage*>* stages = &m_kStageList;
        while (stages)
        {
            QuestStage* stage = stages->GetItem();
            if (stage)
            {
                stage->MarkDone(false);
                BSSimpleList<PlayerQuestData*>* items = stage->GetStageItemList();
                while (items)
                {
                    PlayerQuestData* item = items->GetItem();
                    if (item && item->GetLogDate())
                    {
                        delete item->GetLogDate();
                        item->SetLogDate(0);
                    }
                    items = items->GetNext();
                }
            }
            stages = stages->GetNext();
        }
        m_ucEnabled = 0;
    }
    if (static_cast<QuestLoadChangeFlags*>(buffer)->GetOldChangeFlags(0x40000000U).operator bool() && m_pScriptLocals)
        m_pScriptLocals->Revert(buffer);
    if (static_cast<QuestLoadChangeFlags*>(buffer)->GetOldChangeFlags(0x20000000U).operator bool())
    {
        BSSimpleList<BGSQuestObjective*>* objectives = &m_kObjectives;
        while (objectives)
        {
            BGSQuestObjective* objective = objectives->GetItem();
            if (objective)
                objective->SetState(QOS_DORMANT);
            objectives = objectives->GetNext();
        }
    }
}

enum QUEST_CHUNK_ID
{
    CHUNK_EDID = 0x44494445,
    CHUNK_OBND = 0x444e424f,
    CHUNK_SCRI = 0x49524353,
    CHUNK_FULL = 0x4c4c5546,
    CHUNK_ICON = 0x4e4f4349,
    CHUNK_DATA = 0x41544144,
    CHUNK_QOBJ = 0x4a424f51,
    CHUNK_QSTA = 0x41545351,
    CHUNK_INDX = 0x58444e49,
    CHUNK_QSDT = 0x54445351,
    CHUNK_SCDA = 0x41444353,
    CHUNK_SLSD = 0x44534c53,
    CHUNK_SCVR = 0x52564353,
    CHUNK_SCRO = 0x4f524353,
    CHUNK_SCHR = 0x52484353,
    CHUNK_SCRV = 0x56524353,
    CHUNK_CNAM = 0x4d414e43,
    CHUNK_CTDA = 0x41445443
};

// @fnv 0x0060C8E0
BGSQuestObjective* TESQuest::GetObjective(unsigned int index)
{
    struct ObjectiveSearch
    {
        BSSimpleList<BGSQuestObjective*>* objectives;
        unsigned int objectiveIndex;
    } search;
    search.objectives = GetObjectiveList();
    search.objectiveIndex = 0;
    while (search.objectives && !search.objectives->IsEmpty())
    {
        BGSQuestObjective* objective = search.objectives->GetItem();
        if (objective && objective->GetIndex() == index)
            return objective;
        search.objectives = search.objectives->GetNext();
    }
    return 0;
}

// @fnv 0x0060EAF0
void TESQuest::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (static_cast<QuestLoadChangeFlags*>(buffer)->GetChangeFlags(2U).operator bool())
        static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&data.m_ucEntryType), 1U);
    if (static_cast<QuestLoadChangeFlags*>(buffer)->GetChangeFlags(4U).operator bool())
        static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&data.fQuestDelayTime), 4U);
    if (static_cast<QuestLoadChangeFlags*>(buffer)->GetChangeFlags(0x80000000U).operator bool())
    {
        unsigned int stageCount = static_cast<BGSLoadFormBuffer*>(buffer)->ReadElementCount();
        for (unsigned int i = 0; i < stageCount; ++i)
        {
            unsigned char stageIndex = 0;
            bool done = false;
            static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&stageIndex), 1U);
            static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&done), 1U);
            {
                QuestStage* stage = GetStage(stageIndex);
                if (stage)
                    stage->MarkDone(done);
                else
                    LogWarning("SAVELOAD: Could not find stage %i in quest %s during load.", stageIndex,
                               GetEditorName());
                unsigned int itemCount = static_cast<BGSLoadFormBuffer*>(buffer)->ReadElementCount();
                for (unsigned int j = 0; j < itemCount; ++j)
                {
                    unsigned char itemIndex = 0;
                    bool hasDate = false;
                    Date logDate;
                    static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&itemIndex), 1U);
                    static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&hasDate), 1U);
                    if (hasDate)
                        static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&logDate), 4U);
                    if (hasDate && stage)
                    {
                        PlayerQuestData* item = stage->GetStageItemByIndex(itemIndex);
                        if (item)
                            item->SetLogDate(new Date(logDate));
                    }
                }
            }
        }
        m_ucEnabled = 0;
        UpdateStageMask();
    }
    if (static_cast<QuestLoadChangeFlags*>(buffer)->GetChangeFlags(0x40000000U).operator bool())
    {
        if (m_pScriptLocals)
            m_pScriptLocals->LoadGame(static_cast<BGSLoadFormBuffer*>(buffer));
        else
        {
            ScriptLocals locals;
            locals.LoadGame(static_cast<BGSLoadFormBuffer*>(buffer));
        }
    }
    if (static_cast<QuestLoadChangeFlags*>(buffer)->GetChangeFlags(0x20000000U).operator bool())
    {
        unsigned int objectiveCount = static_cast<BGSLoadFormBuffer*>(buffer)->ReadElementCount();
        for (unsigned int k = 0; k < objectiveCount; ++k)
        {
            struct SavedObjectiveState
            {
                unsigned int index;
                QUEST_OBJECTIVE_STATE state;
            } savedObjective;
            savedObjective.index = 0;
            savedObjective.state = QOS_DORMANT;
            static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&savedObjective.index), 4U);
            static_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(static_cast<void*>(&savedObjective.state), 4U);
            BGSQuestObjective* objective = GetObjective(savedObjective.index);
            if (objective)
                objective->SetState(savedObjective.state);
        }
    }
}

// @fnv 0x0060CEB0
bool TESQuest::Load(TESFile* file)
{
    QuestStage* stage;
    {
        unsigned char formType = file->GetTESForm();
        if (formType != ENUM_FORM_ID_QUST_ID)
            return false;
        stage = 0;
        PlayerQuestData* item = 0;
        RegionObjectEntry* target = 0;
        BGSQuestObjective* objective = 0;
        LoadRecordHeader(file);
        SetInitializationState(false);
        unsigned char itemIndex = 0;
        int chunk;
        while ((chunk = file->GetChunkID()) != 0)
        {
            switch (chunk)
            {
            case CHUNK_EDID: {
                char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
                file->GetChunkData(editorID, 0x200);
                SetEditorID_AtRuntime(editorID);
                break;
            }
            case CHUNK_OBND:
                readOBNDSubRecord(file);
                break;
            case CHUNK_SCRI: {
                unsigned int script = 0;
                file->GetChunkData(&script);
                TESScriptableForm::SetScript(reinterpret_cast<Script*>(script));
                TESScriptableForm::InitItem(this);
                break;
            }
            case CHUNK_FULL:
                TESFullName::LoadFullNameChunk(this ? reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(this) + 0x30) : 0, file);
                break;
            case CHUNK_ICON:
                TESTexture::ReadTextureData(this ? reinterpret_cast<TESIcon*>(reinterpret_cast<char*>(this) + 0x24) : 0, file);
                break;
            case CHUNK_DATA:
                ReadTypedData(file, &data, sizeof(data));
                break;
            case CHUNK_QOBJ:
                objective = new BGSQuestObjective;
                objective->Load(file);
                GetObjectiveList()->AddTail(objective);
                objective->SetOwnerQuest(this);
                break;
            case CHUNK_QSTA:
                stage = 0;
                item = 0;
                target = new RegionObjectEntry;
                target->Load(file);
                if (!objective)
                {
                    objective = new BGSQuestObjective;
                    GetObjectiveList()->AddTail(objective);
                    objective->SetOwnerQuest(this);
                }
                objective->GetTargetList()->AddTail(target);
                break;
            case CHUNK_INDX:
                stage = new QuestStage;
                stage->Load(file);
                GetStageList()->AddTail(stage);
                break;
            case CHUNK_QSDT:
                if (stage)
                {
                    item = new PlayerQuestData;
                    item->Load(file);
                    item->SetIndex(itemIndex);
                    ++itemIndex;
                    stage->GetStageItemList()->AddTail(item);
                }
                continue;
                break;
            case CHUNK_SCDA:
            case CHUNK_SLSD:
            case CHUNK_SCVR:
            case CHUNK_SCRO:
            case CHUNK_SCHR:
            case CHUNK_SCRV:
                if (item)
                {
                    item->Load(file);
                    continue;
                }
                break;
            case CHUNK_CNAM:
                if (item)
                    item->SetHasLogEntry(true);
                break;
            case CHUNK_CTDA:
                if (item)
                    item->GetConditions()->Load(file);
                else if (target)
                    target->GetConditions()->Load(file);
                else
                    GetConditions()->Load(file);
                break;
            }
            if (!file->NextChunk())
                break;
        }
        if (file->IsEndianConversionRequired())
            data.Endian();
        return true;
    }
}

// @fnv 0x0060c9c0
void TESQuest::SetEnabled(bool enabled)
{
    enabled
        ? reinterpret_cast<QuestData*>(reinterpret_cast<TESRecipe*>(this)->GetIngredientList())->m_ucEntryType |= 1
        : reinterpret_cast<QuestData*>(reinterpret_cast<TESRecipe*>(this)->GetIngredientList())->m_ucEntryType &= ~1;
    MarkAsModified(2);
}

// @fnv 0x0060cd00
void TESQuest::SetStartsEnabled(bool enabled)
{
    enabled
        ? reinterpret_cast<QuestData*>(reinterpret_cast<TESRecipe*>(this)->GetIngredientList())->m_ucEntryType |= 16
        : reinterpret_cast<QuestData*>(reinterpret_cast<TESRecipe*>(this)->GetIngredientList())->m_ucEntryType &= ~16;
}

// @fnv 0x0060d4d0
void TESQuest::RunScript()
{
    if (TESScriptableForm::GetScript())
        TESScriptableForm::GetScript()->Run(static_cast<TESObjectREFR*>(0), m_pScriptLocals, static_cast<TESObjectREFR*>(0), false);
}

// @fnv 0x0060d490
void PlayerQuestData::SetHasLogEntry(bool abHasLogEntry)
{
    bHasLogEntry = abHasLogEntry;
}

// @fnv 0x0060d4b0
void PlayerQuestData::SetIndex(unsigned char index)
{
    m_ucClipIdentifier = index;
}

struct FUN_004b1000_shell
{
    short a[2];
    short* CopyShortPair(const short* b);
};

// Copies the first two shorts from b into the object's a array and returns a pointer to it.
// @fnv 0x004b1000
short* FUN_004b1000_shell::CopyShortPair(const short* pSource)
{
    a[0] = pSource[0];
    a[1] = pSource[1];
    return a;
}

#include "../../include/MiscStatManager.h"

// @fnv 0x0060cad0
// src: XBOX_PDB 0x0060cad0
void MiscStatManager_Decrement(int aeStatId)
{
    MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)aeStatId, -1);
}

struct FUN_0060d5e0_shell : TESRecipe
{
    bool HasFlag8();
};

// @fnv 0x0060d5e0
bool FUN_0060d5e0_shell::HasFlag8()
{
    return (reinterpret_cast<unsigned char*>(this->GetIngredientList())[0] & 8) != 0;
}

struct FUN_0060da90_shell
{
    void* GetOffsetPointer();
};

// @fnv 0x0060da90
void* FUN_0060da90_shell::GetOffsetPointer()
{
    return reinterpret_cast<char*>(this) + 0x6B0;
}

struct FUN_00737e30_shell
{
    unsigned int m_210;
    unsigned int GetFieldAt210();
};

// @fnv 0x00737e30
unsigned int FUN_00737e30_shell::GetFieldAt210()
{
    return ((unsigned int*)this)[0x210 / 4];
}

struct FUN_004b0fa0_shell
{
    short m_iWordAt00;
    short m_cByteAtOffset2;
    FUN_004b0fa0_shell();
};

// @fnv 0x004b0fa0
FUN_004b0fa0_shell::FUN_004b0fa0_shell()
{
    m_iWordAt00 = 0;
    m_cByteAtOffset2 = 0;
}

struct FUN_0060d8d0_shell : TESRecipe
{
    bool HasFlag0x10();
};

// @fnv 0x0060d8d0
bool FUN_0060d8d0_shell::HasFlag0x10()
{
    return (*reinterpret_cast<unsigned char*>(this->GetIngredientList()) & 0x10) != 0;
}

struct FUN_0060e680_shell
{
    void SetFlags(unsigned int arg);
};

// @fnv 0x0060e680
void FUN_0060e680_shell::SetFlags(unsigned int auiFlags)
{
    *(unsigned int*)((char*)this + 0x54) = *(unsigned int*)((char*)this + 0x54) | auiFlags;
}

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void __cdecl _security_check_cookie(unsigned int);
extern "C" unsigned int DAT_011c16bc;
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
// TESQuest has no declaration for its editor-ID setter override yet.
// Keep only that missing entry point here, without a duplicate quest layout.
struct QuestEditorIDSetter
{
    bool SetEditorID(const char* arg);
};
// @fnv 0x0060dab0
bool QuestEditorIDSetter::SetEditorID(const char* pcString)
{
    unsigned int size = BSStringLength(pcString) + 1;
    char* buffer = static_cast<char*>(_alloca(size));
    TaskQueueInterface::CopyStringToBuffer(buffer, size, pcString);
    if (!reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x64)->StrCmp(buffer, true))
        return false;
    reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x64)->Set(buffer, 0);
    return true;
}

// Returns the editor ID string, or an empty string when the ID is unset.
// @fnv 0x0060c5f0
const char* TESQuest::GetEditorName() const
{
    return strEditorID.String() ? strEditorID.String() : "";
}

// @fnv 0x0060e7c0
// src: COMMUNITY 0x0060e7c0
void TESQuest::CheckSaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    if (static_cast<QuestSaveChangeFlags*>(apSaveGameBuffer)->GetChangeFlags(0x40000000).operator bool() && m_pScriptLocals == 0)
        apSaveGameBuffer->BGSSaveFormBuffer_RemoveChange(0x40000000U);
}

// @fnv 0x0060c4b0
TESQuest::TESQuest()
{
    SetFormType(ENUM_FORM_ID_QUST_ID);
    m_pScriptLocals = 0;
    ResetFormData();
}

void __cdecl HUDMainMenu_ShowQuestName(void* apQuest);

// Sets or clears the completed flag bit 0x40 on the quest, calls vtable slot 18 with 2, and notifies via FUN_0077a480 when newly completed.
// @fnv 0x0060caf0
// src: XBOX_PDB 0x0060caf0
void TESQuest::SetFailed(bool abCompleted)
{
    if (abCompleted && GetCompleted())
        return;
    if (abCompleted && !(data.m_ucEntryType & 0x40))
    {
        data.m_ucEntryType |= 0x40;
        data.m_ucEntryType |= 2;
        ((void(__thiscall*)(void*, unsigned int))(*(void***)this)[18])(this, 2);
        HUDMainMenu_ShowQuestName(this);
    }
    else if (!abCompleted && (data.m_ucEntryType & 0x40))
    {
        data.m_ucEntryType &= ~0x40;
        ((void(__thiscall*)(void*, unsigned int))(*(void***)this)[18])(this, 2);
    }
}

struct TopicMenuController
{
    static void __cdecl IncrementMiscStat(int id);
};

// @fnv 0x0060ca30
// src: XBOX_PDB 0x0060ca30
void TESQuest::SetCompleted(bool abCompleted)
{
    if (abCompleted && !(data.m_ucEntryType & 2))
    {
        data.m_ucEntryType |= 2;
        MarkAsModified(2);
        TopicMenuController::IncrementMiscStat(0);
        HUDMainMenu_ShowQuestName(this);
    }
    else if (!abCompleted && (data.m_ucEntryType & 2))
    {
        data.m_ucEntryType &= ~2;
        MarkAsModified(2);
        MiscStatManager_Decrement(0);
    }
}

// Clears quest data before destroying the shared members and base components.
// @fnv 0x0060c660
TESQuest::~TESQuest()
{
    TESQuest::ClearData();
}

// The notifying state transition is distinct from shared SetState's raw setter.
struct QuestObjectiveTransitions : BGSQuestObjective
{
    void ApplyState(QUEST_OBJECTIVE_STATE state);
};

// @fnv 0x0060c950
// src: COMMUNITY 0x0060c950
void TESQuest::SetAllObjectivesComplete(int a1)
{
    BSSimpleList<QuestObjectiveTransitions*>* node = reinterpret_cast<BSSimpleList<QuestObjectiveTransitions*>*>(GetObjectiveList());
    while (node && node->GetItem())
    {
        (node->GetItem())->ApplyState((node->GetItem())->GetDisplayed() ? QOS_COMPLETED_DISPLAYED : QOS_COMPLETED);
        node = node->GetNext();
    }
}

struct FNV_InitNode;
struct FNV_SubObject
{
    void FUN_00483710();
    void FUN_005ec280();
};
struct FNV_NodeValue
{
    FNV_SubObject* object;
};
struct FNV_InitNode
{
    bool FUN_008256d0();
    FNV_NodeValue* FUN_006815c0();
    FNV_InitNode* FUN_00726070();
};
struct FNV_InitPart
{
    void PACK_SCHED_DATA_Endian();
};

struct FNV_EventObject
{
    void ProcessItems();
};
extern "C" bool __cdecl TESForm_QEndianSwapOnSave();

// @fnv 0x0060cd60
// src: XBOX_PDB 0x0060cd60
void TESQuest::Save_0060cd60()
{
    BeginFormRecord();
    TESScriptableForm::Save_0048cca0();
    TESFullName::Save_00487010();
    TESIcon::Save(0x4e4f4349);
    if (TESForm_QEndianSwapOnSave())
    {
        reinterpret_cast<FNV_InitPart*>(&data)->PACK_SCHED_DATA_Endian();
    }
    TESForm___SaveData(&data, 8);
    if (TESForm_QEndianSwapOnSave())
    {
        reinterpret_cast<FNV_InitPart*>(&data)->PACK_SCHED_DATA_Endian();
    }
    if (GetConditions() != 0)
    {
        reinterpret_cast<FNV_EventObject*>(GetConditions())->ProcessItems();
    }
    FNV_InitNode* node = reinterpret_cast<FNV_InitNode*>(GetStageList());
    while (node != 0 && !node->FUN_008256d0())
    {
        node->FUN_006815c0()->object->FUN_00483710();
        node = node->FUN_00726070();
    }
    FNV_InitNode* pOtherNode = reinterpret_cast<FNV_InitNode*>(GetObjectiveList());
    while (pOtherNode != 0 && !pOtherNode->FUN_008256d0())
    {
        pOtherNode->FUN_006815c0()->object->FUN_005ec280();
        pOtherNode = pOtherNode->FUN_00726070();
    }
    FinishFormRecord();
}

struct QuestEntryStandIn
{
    TESQuest* GetQuest();
    void* GetOwnerProcess();
    void* CheckQuest(TESQuest* apQuest);
};

struct PlayerQuestListStandIn
{
    BSSimpleList<QuestEntryStandIn*>* GetQuestEntryList();
};

extern PlayerQuestListStandIn* g_thePlayer;

// Clears apList, then walks the player's quest entry list and appends or prepends entries whose quest matches apQuest or passes the completed/any filter.
// @fnv 0x0060d8f0
// src: XBOX_PDB 0x0060d8f0
void __cdecl TESQuest_GetQuestLog(BSSimpleList<QuestEntryStandIn*>* apList, TESQuest* apQuest, bool abCompleted, bool abAddTail,
                          bool abAny)
{
    if (!apList)
        return;
    apList->RemoveAll();
    BSSimpleList<TESQuest*> kSeen;
    BSSimpleList<QuestEntryStandIn*>* pNode = g_thePlayer->GetQuestEntryList();
    while (pNode && pNode->GetItem())
    {
        TESQuest* pQuest;
        QuestEntryStandIn* pEntry2 = pNode->GetItem();
        pQuest = pEntry2->GetQuest();
        pNode = pNode->GetNext();
        if (pQuest)
        {
            bool bOk3 = !apQuest || (apQuest && pQuest == apQuest);
            if (bOk3 && !apQuest)
            {
                bOk3 = (abCompleted == pQuest->GetCompleted() || abAny) && !kSeen.IsInList(pQuest);
                if (bOk3)
                    kSeen.AddHead(pQuest);
            }
            if (bOk3 && pEntry2->GetOwnerProcess() && pEntry2->CheckQuest(pQuest))
            {
                if (abAddTail)
                    apList->AddTail(pEntry2);
                else
                    apList->AddHead(pEntry2);
            }
        }
    }
    kSeen.RemoveAll();
}

struct SaveFormInfo
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char flagsStart;
};

struct SaveLoadGameStub
{
    bool TESSaveLoadGame_UseSaveGameBlocks();
    SaveFormInfo* GetCurrentForm();
};
extern SaveLoadGameStub* g_TESSaveLoadGame;

struct FormSaveSizeStub
{
    unsigned short GetSaveSize(unsigned int changedFlags);
};

struct StageItemListStub
{
    int GetSize();
};

struct QuestStageStub
{
    StageItemListStub* GetStageItemList();
};

struct StageNodeStub
{
    QuestStageStub*& GetItem();
    StageNodeStub* GetNext();
};

extern SettingT<INISettingCollection> bDebugSaveGameSize;
TESForm* __cdecl LookupFormByID(unsigned int formID);
void __cdecl SaveGameSizeWarning(const char* message, ...);

// @fnv 0x0060dba0
// src: XBOX_PDB 0x0060dba0
unsigned short TESQuest::GetSaveSize_0060dba0(unsigned int changedFlags)
{
    unsigned short size7 = 0;
    size7 += ((FormSaveSizeStub*)this)->GetSaveSize(changedFlags);
    unsigned short baseSize2 = size7;
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        size7 += 4;
        size7 += 2;
    }
    if (changedFlags & 2)
    {
        size7 += 1;
    }
    if (changedFlags & 0x80000000)
    {
        StageNodeStub* node9 = reinterpret_cast<StageNodeStub*>(GetStageList());
        size7 += 1;
        while (node9)
        {
            QuestStageStub* stage = node9->GetItem();
            if (stage)
            {
                size7 += 2;
                StageItemListStub* items2 = stage->GetStageItemList();
                size7 += items2->GetSize() * 5 + 1;
            }
            node9 = node9->GetNext();
        }
    }
    if (changedFlags & 0x40000000)
    {
        size7 += m_pScriptLocals->GetSaveSize();
    }
    if (bDebugSaveGameSize.Bool()[0])
    {
        SaveFormInfo* info = g_TESSaveLoadGame->GetCurrentForm();
        if (info)
        {
            TESForm* form = LookupFormByID(info->formID);
            SaveGameSizeWarning("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                                size7 - baseSize2, info->formID, form->GetName(), *(unsigned int*)&info->flagsStart,
                                3920, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp");
        }
        else
        {
            SaveGameSizeWarning("GetSaveSize(): %-5i ending at line %i in file %s", size7 - baseSize2, 3920,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp");
        }
    }
    return size7;
}

struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int auiFlags);
};

// Legacy reset entry point is absent from the shared ScriptLocals interface.
struct QuestScriptLocals : ScriptLocals
{
    void ResetLocals();
    void WriteScriptLocals();
    void ReadScriptLocals();
};

// @fnv 0x0060e6a0
// src: COMMUNITY 0x0060e6a0
void TESQuest::RevertTES_0060e6a0(unsigned int auiFlags)
{
    ((FUN_004534f0_shell*)this)->FUN_004534f0(auiFlags);
    if (auiFlags & 0x80000000)
    {
        BSSimpleList<QuestStage*>* pStageIter = GetStageList();
        while (pStageIter)
        {
            QuestStage* pStage = pStageIter->GetItem();
            if (pStage)
            {
                pStage->MarkDone(false);
                BSSimpleList<PlayerQuestData*>* pItemIter = pStage->GetStageItemList();
                while (pItemIter)
                {
                    PlayerQuestData* pItem3 = pItemIter->GetItem();
                    Date* pDate3 = pItem3 ? pItem3->GetLogDate() : 0;
                    if (pDate3)
                    {
                        pItem3->SetLogDate(0);
                        delete pDate3;
                    }
                    pItemIter = pItemIter->GetNext();
                }
            }
            pStageIter = pStageIter->GetNext();
        }
        m_ucEnabled = 0;
    }
    if ((auiFlags & 0x40000000) && m_pScriptLocals)
    {
        ((QuestScriptLocals*)m_pScriptLocals)->ResetLocals();
    }
}

// Legacy stream entry points not exposed by the shared form interface.
struct QuestRecordIO
{
    void TESForm_SaveGame(unsigned int);
    unsigned char* ComputeValue_005a8080();
    void TESForm_SaveGameDataOLD(void*, unsigned int);
};

struct QuestSaveManager
{
    unsigned char* FUN_00825c00();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(void*, unsigned int);
    SaveFormInfo* FUN_004fd3e0();
};
struct QuestSaveItem
{
    unsigned char BGSBodyPart_GetToHitChance();
    Date* FUN_008d8520();
};
struct QuestSaveItemNode
{
    QuestSaveItem*& FUN_006815c0();
    QuestSaveItemNode* FUN_00726070();
};
struct QuestSaveStage
{
    unsigned char TESTextureList_GetTextureCount();
    bool FUN_005dc960();
    QuestSaveItemNode* FUN_00717e50();
};
struct QuestSaveStageNode
{
    QuestSaveStage*& FUN_006815c0();
    QuestSaveStageNode* FUN_00726070();
};

void __cdecl ProgramFlow(const char*, ...);
void __cdecl Warning_005b5e40(const char*, ...);

// Writes the quest's save data: flags, stage and item lists, optional locals, debug size logging, and a block-size header when block saving is active.
// @fnv 0x0060dd50
// src: XBOX_PDB 0x0060dd50
void TESQuest::SaveGame_0060dd50(unsigned int flags)
{
    reinterpret_cast<QuestRecordIO*>(this)->TESForm_SaveGame(flags);
    unsigned short h = 0;  // Reserved block size.
    unsigned char* p = 0;  // Address of the reserved block-size field.
    unsigned char* a = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
    if (bDebugSaveGameSize.Bool()[0])
        a = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
    if (((QuestSaveManager*)g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int marker = 0x424c4f4b;
        ((QuestSaveManager*)g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&marker, 4);
        p = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
        ((QuestSaveManager*)g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&h, 2);
    }
    if (flags & 2)
    {
        unsigned char questFlags = *reinterpret_cast<QuestRecordIO*>(this)->ComputeValue_005a8080();
        reinterpret_cast<QuestRecordIO*>(this)->TESForm_SaveGameDataOLD(&questFlags, 1);
    }
    if (flags & 0x80000000)
    {
        unsigned char p = 0;  // Number of saved stages.
        unsigned char* j = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
        reinterpret_cast<QuestRecordIO*>(this)->TESForm_SaveGameDataOLD(&p, 1);
        QuestSaveStageNode* h = reinterpret_cast<QuestSaveStageNode*>(GetStageList());  // Stage iterator.
        while (h)
        {
            QuestSaveStage* stage = h->FUN_006815c0();
            if (stage)
            {
                unsigned char eb = stage->TESTextureList_GetTextureCount();  // Stage index.
                bool f = stage->FUN_005dc960();            // Stage completion flag.
                reinterpret_cast<QuestRecordIO*>(this)->TESForm_SaveGameDataOLD(&eb, 1);
                reinterpret_cast<QuestRecordIO*>(this)->TESForm_SaveGameDataOLD(&f, 1);
                unsigned char q = 0;  // Number of saved stage items.
                unsigned char* cf = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
                reinterpret_cast<QuestRecordIO*>(this)->TESForm_SaveGameDataOLD(&q, 1);
                QuestSaveItemNode* s = stage->FUN_00717e50();  // Stage-item iterator.
                while (s)
                {
                    QuestSaveItem* item = s->FUN_006815c0();
                    if (item)
                    {
                        unsigned char j = item->BGSBodyPart_GetToHitChance();  // Stage-item index.
                        Date* p = item->FUN_008d8520();          // Log date, if present.
                        reinterpret_cast<QuestRecordIO*>(this)->TESForm_SaveGameDataOLD(&j, 1);
                        if (p)
                        {
                            ((QuestSaveManager*)g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(p, 4);
                        }
                        else
                        {
                            Date emptyDate;
                            ((QuestSaveManager*)g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&emptyDate, 4);
                        }
                        ++q;
                    }
                    s = s->FUN_00726070();
                }
                *cf = q;
                ++p;
            }
            h = h->FUN_00726070();
        }
        *j = p;
    }
    if (flags & 0x40000000)
        static_cast<QuestScriptLocals*>(m_pScriptLocals)->WriteScriptLocals();
    if (bDebugSaveGameSize.Bool()[0])
    {
        unsigned char* end = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
        SaveFormInfo* formInfo = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_004fd3e0();
        if (formInfo)
        {
            TESForm* form = LookupFormByID(formInfo->formID);
            ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", end - a,
                         formInfo->formID, form->GetName(), *(unsigned int*)&formInfo->flagsStart, 4003,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp");
        }
        else
        {
            ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", end - a, 4003,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp");
        }
    }
    if (((QuestSaveManager*)g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned char* h = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
        unsigned char* j = p;  // Beginning of the saved block.
        if (h > j + 65535)
            Warning_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp", 4003);
        *(unsigned short*)p = (unsigned short)(h - j);
    }
}

extern "C" void* DAT_011de45c;
extern "C" char UNK_0104ad80[];
extern "C" char UNK_0104adc0[];
extern "C" char UNK_010156a8[];
extern "C" char UNK_01015718[];
extern "C" char UNK_01015588[];
extern "C" char UNK_01015500[];
extern "C" char UNK_010154a0[];
extern "C" char UNK_01015440[];
void __cdecl Warning_005b5e40(const char*, ...);
void* __cdecl TESForm_GetFormByNumericID(void*);
struct StreamReader
{
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_LoadGameDataOLD(void*, unsigned int);
    unsigned int FUN_00825c00();
    void* BGSProjectile_GetExplosion();
    unsigned char FUN_008df040();
    void SetFlags(unsigned int);
};
struct QuestInput
{
    void TESForm_LoadGame(unsigned int, unsigned int);
    void TESForm_LoadGameDataOLD(void*, unsigned int);
    unsigned char* ComputeValue_005a8080();
};
struct StageSave
{
    void PackageSchedule_SetStartDayOfWeek(unsigned char);
    void* FindItemByDoneFlag(unsigned char);
};
struct StageEntry
{
    void* FUN_008d8520();
    void FUN_00407800(void*);
};
struct SavedDate
{
    unsigned int value;
    void CopyShortPair(const Date*);
    void FUN_007b3fa0(unsigned int);
};
struct LogValue
{
    short low, high;
    LogValue();
    ~LogValue();
    unsigned short Date_GetDate();
    unsigned short Date_GetYear();
};
void FUN_00483710(LogValue*);
typedef unsigned int(__thiscall* TagMethod)(void*);

// Reads quest data from the stream: enabled flag, stages with dates, script locals, and logs size mismatches.
// @fnv 0x0060e0d0
void TESQuest::LoadQuestData(unsigned int flags, unsigned int extra)
{
    ((QuestInput*)this)->TESForm_LoadGame(flags, extra);
    unsigned short sizeRead = 0;
    unsigned int start = 0;
    if (((StreamReader*)DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int tag;
        ((StreamReader*)DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&tag, 4);
        if (tag != 0x424c4f4b)
        {
            void* entry = ((StreamReader*)DAT_011de45c)->BGSProjectile_GetExplosion();
            if (entry)
            {
                void* view = TESForm_GetFormByNumericID(*(void**)entry);
                Warning_005b5e40(UNK_01015718, UNK_0104ad80, 0xfaf, *(void**)entry, ((TagMethod*)*(void**)view)[76](view),
                             *(unsigned char*)((char*)entry + 9), *(unsigned int*)((char*)entry + 5));
            }
            else
            {
                Warning_005b5e40(UNK_010156a8, UNK_0104ad80, 0xfaf, ((StreamReader*)DAT_011de45c)->FUN_008df040());
            }
        }
        start = ((StreamReader*)DAT_011de45c)->FUN_00825c00();
        ((StreamReader*)DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&sizeRead, 2);
    }
    if (flags & 2)
    {
        unsigned char enabled;
        ((QuestInput*)this)->TESForm_LoadGameDataOLD(&enabled, 1);
        *((QuestInput*)this)->ComputeValue_005a8080() = enabled;
    }
    if (flags & 0x80000000)
    {
        unsigned char stageCount;
        ((QuestInput*)this)->TESForm_LoadGameDataOLD(&stageCount, 1);
        for (int i = 0; i < stageCount; ++i)
        {
            unsigned char stageId;
            unsigned char isComplete;
            ((QuestInput*)this)->TESForm_LoadGameDataOLD(&stageId, 1);
            ((QuestInput*)this)->TESForm_LoadGameDataOLD(&isComplete, 1);
            StageSave* questStage = (StageSave*)GetStage(stageId);
            if (questStage)
            {
                questStage->PackageSchedule_SetStartDayOfWeek(isComplete);
            }
            else
            {
                Warning_005b5e40(UNK_0104adc0, stageId, this->GetEditorName());
            }
            {
                unsigned char itemCount;
                ((QuestInput*)this)->TESForm_LoadGameDataOLD(&itemCount, 1);
                for (int j = 0; j < itemCount; ++j)
                {
                    Date dateValue;
                    {
                        unsigned char itemId;
                        ((QuestInput*)this)->TESForm_LoadGameDataOLD(&itemId, 1);
                        ((StreamReader*)DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&dateValue, 4);
                        if (questStage)
                        {
                            StageEntry* item = (StageEntry*)questStage->FindItemByDoneFlag(itemId);
                            if (item)
                            {

                                if (((LogValue*)&dateValue)->Date_GetDate() == 0 &&
                                    ((LogValue*)&dateValue)->Date_GetYear() == 0)
                                {
                                    SavedDate* pOldDate = (SavedDate*)item->FUN_008d8520();
                                    if (pOldDate)
                                    {
                                        delete (Date*)pOldDate;
                                        item->FUN_00407800(0);
                                    }
                                }
                                else
                                {
                                    SavedDate* pOldDate = (SavedDate*)item->FUN_008d8520();
                                    if (pOldDate)
                                    {
                                        pOldDate->CopyShortPair(&dateValue);
                                    }
                                    else
                                    {
                                        pOldDate = (SavedDate*)new Date(dateValue);
                                        item->FUN_00407800(pOldDate);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        this->m_ucEnabled = 0;
        UpdateStageMask();
    }
    if (flags & 0x40000000)
    {
        if (!this->m_pScriptLocals)
        {
            ScriptLocals* replacement = new ScriptLocals;
            {
                static_cast<QuestScriptLocals*>(replacement)->ReadScriptLocals();
                delete replacement;
                ((StreamReader*)DAT_011de45c)->SetFlags(0x40000000);
            }
        }
        else
        {
            static_cast<QuestScriptLocals*>(this->m_pScriptLocals)->ReadScriptLocals();
        }
    }
    if (((StreamReader*)DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        void* entry;
        {
            unsigned int actual = ((StreamReader*)DAT_011de45c)->FUN_00825c00();
            entry = ((StreamReader*)DAT_011de45c)->BGSProjectile_GetExplosion();
            if (entry)
            {
                void* view = TESForm_GetFormByNumericID(*(void**)entry);
                if (actual > start + sizeRead)
                    Warning_005b5e40(UNK_01015588, actual - (start + sizeRead), UNK_0104ad80, 0x1010, *(void**)entry,
                                 ((TagMethod*)*(void**)view)[76](view), *(unsigned char*)((char*)entry + 9),
                                 *(unsigned int*)((char*)entry + 5));
                else if (actual < start + sizeRead)
                    Warning_005b5e40(UNK_01015500, (start + sizeRead) - actual, UNK_0104ad80, 0x1010, *(void**)entry,
                                 ((TagMethod*)*(void**)view)[76](view), *(unsigned char*)((char*)entry + 9),
                                 *(unsigned int*)((char*)entry + 5));
            }
            else
            {
                if (actual > start + sizeRead)
                    Warning_005b5e40(UNK_010154a0, actual - (start + sizeRead), UNK_0104ad80, 0x1010,
                                 ((StreamReader*)DAT_011de45c)->FUN_008df040());
                else if (actual < start + sizeRead)
                    Warning_005b5e40(UNK_01015440, (start + sizeRead) - actual, UNK_0104ad80, 0x1010,
                                 ((StreamReader*)DAT_011de45c)->FUN_008df040());
            }
        }
    }
}

// WriteToBuffer - data round worker13 v06
struct F810Buf;
struct F810Flags
{
    bool FUN_004280f0();
};
struct F810Item1;
struct F810Item2;
struct F810Node2
{
    F810Item2* pItem;
    F810Node2* pNext;
    F810Item2** FUN_006815c0();
    F810Node2* FUN_00726070();
};
struct F810Node3
{
    BGSQuestObjective* pItem;
    F810Node3* pNext;
    BGSQuestObjective** FUN_006815c0();
    F810Node3* FUN_00726070();
};
struct F810Item1
{
    unsigned char TESTextureList_GetTextureCount();
    bool FUN_005dc960();
    F810Node2* FUN_00717e50();
};
struct F810Item2
{
    bool BGSBodyPart_GetToHitChance();
    void* FUN_008d8520();
};
struct F810Node1
{
    F810Item1* pItem;
    F810Node1* pNext;
    F810Item1** FUN_006815c0();
    F810Node1* FUN_00726070();
};
struct F810Buf
{
    F810Flags* FUN_00428110(void* out, unsigned int tag);
};

// Serializes changed quest flags, delay, stages, objectives, and script locals.
// @fnv 0x0060e810
void TESQuest::WriteToBuffer(BGSSaveFormBuffer* buf)
{
    unsigned int flagsE;
    unsigned int tagD;
    unsigned int flags2;
    unsigned int flag2;
    unsigned int flag;
    F810Node3* next0;
    void* valY;
    BGSQuestObjective* entry;
    int iterY;
    F810Node3* head1;
    unsigned int cntY;
    unsigned char gotB;
    unsigned char opts;
    void* val1;
    F810Item2* item2;
    F810Node2* listD;
    unsigned int cntA;
    int idxD;
    unsigned char rawD;
    unsigned char flg;
    F810Item1* itemD;
    F810Node1* nodeC;
    unsigned int cnt1;
    int idx0;
    SaveIfChanged(buf);
    if (reinterpret_cast<F810Buf*>(buf)->FUN_00428110(&flag, 2)->FUN_004280f0())
    {
        buf->FUN_00865e50(&data.m_ucEntryType, 1, 0);
    }
    if (reinterpret_cast<F810Buf*>(buf)->FUN_00428110(&flag2, 4)->FUN_004280f0())
    {
        buf->FUN_00865e50(&data.fQuestDelayTime, 4, 0);
    }
    if (reinterpret_cast<F810Buf*>(buf)->FUN_00428110(&flags2, 0x80000000)->FUN_004280f0())
    {
        idx0 = 0;
        cnt1 = buf->StartVariableSizedValue();
        nodeC = reinterpret_cast<F810Node1*>(&m_kStageList);
        while (nodeC != 0)
        {
            itemD = *nodeC->FUN_006815c0();
            if (itemD != 0)
            {
                rawD = itemD->TESTextureList_GetTextureCount();
                flg = itemD->FUN_005dc960();
                buf->FUN_00865e50(&rawD, 1, 0);
                buf->FUN_00865e50(&flg, 1, 0);
                idxD = 0;
                cntA = buf->StartVariableSizedValue();
                listD = itemD->FUN_00717e50();
                while (listD != 0)
                {
                    item2 = *listD->FUN_006815c0();
                    if (item2 != 0)
                    {
                        opts = item2->BGSBodyPart_GetToHitChance();
                        val1 = item2->FUN_008d8520();
                        gotB = (val1 != 0);
                        buf->FUN_00865e50(&opts, 1, 0);
                        buf->FUN_00865e50(&gotB, 1, 0);
                        if (gotB)
                        {
                            buf->FUN_00865e50(val1, 4, 0);
                        }
                        idxD++;
                    }
                    listD = listD->FUN_00726070();
                }
                buf->SaveVariableSizedValue_00865ff0(idxD, cntA);
                idx0++;
            }
            nodeC = nodeC->FUN_00726070();
        }
        buf->SaveVariableSizedValue_00865ff0(idx0, cnt1);
    }
    if (reinterpret_cast<F810Buf*>(buf)->FUN_00428110(&tagD, 0x40000000)->FUN_004280f0())
    {
        m_pScriptLocals->SaveGame(buf);
    }
    if (reinterpret_cast<F810Buf*>(buf)->FUN_00428110(&flagsE, 0x20000000)->FUN_004280f0())
    {
        iterY = 0;
        cntY = buf->StartVariableSizedValue();
        head1 = reinterpret_cast<F810Node3*>(&m_kObjectives);
        while (head1 != 0)
        {
            entry = *head1->FUN_006815c0();
            if (entry != 0)
            {
                valY = reinterpret_cast<void*>(entry->GetState());
                if (valY != 0)
                {
                    next0 = reinterpret_cast<F810Node3*>(entry->GetIndex());
                    buf->FUN_00865e50(&next0, 4, 0);
                    buf->FUN_00865e50(&valY, 4, 0);
                    iterY++;
                }
            }
            head1 = head1->FUN_00726070();
        }
        buf->SaveVariableSizedValue_00865ff0(iterY, cntY);
    }
}

struct StageItem
{
    Date* FUN_008d8520();
    void FUN_00407800(Date*);
};
struct SItemNode
{
    StageItem** FUN_006815c0();
    SItemNode* FUN_00726070();
};
struct Stage
{
    void PackageSchedule_SetStartDayOfWeek(bool);
    SItemNode* FUN_00717e50();
};
struct StageNode
{
    Stage** FUN_006815c0();
    StageNode* FUN_00726070();
};
struct ObjNode
{
    QuestObjectiveTransitions** FUN_006815c0();
    ObjNode* FUN_00726070();
};

void __cdecl TESTopic_ClearAllSaidOnceInfosForQuest(TESQuest*);

// @fnv 0x0060d720
// src: GUESS 0x0060d720 (confidence: low)
void TESQuest::ProcessEntries_0060d720()
{
    StageNode* aStageNode;
    ObjNode* objNode;
    Stage* stage;
    {
        SItemNode* itemNode;
        Date* logDate3;
        StageItem* stageItemA;

        aStageNode = reinterpret_cast<StageNode*>(GetStageList());
        while (aStageNode)
        {
            stage = *aStageNode->FUN_006815c0();
            if (stage)
            {
                stage->PackageSchedule_SetStartDayOfWeek(false);
                itemNode = stage->FUN_00717e50();
                while (itemNode)
                {
                    stageItemA = *itemNode->FUN_006815c0();
                    logDate3 = stageItemA ? stageItemA->FUN_008d8520() : 0;
                    if (logDate3)
                    {
                        stageItemA->FUN_00407800(0);
                        delete logDate3;
                    }
                    itemNode = itemNode->FUN_00726070();
                }
            }
            aStageNode = aStageNode->FUN_00726070();
        }
    }

    m_ucEnabled = 0;

    objNode = reinterpret_cast<ObjNode*>(GetObjectiveList());
    while (objNode && *objNode->FUN_006815c0())
    {
        (*objNode->FUN_006815c0())->ApplyState(QOS_DORMANT);
        objNode = objNode->FUN_00726070();
    }

    if (m_pScriptLocals)
    {
        delete m_pScriptLocals;
        m_pScriptLocals = TESScriptableForm::GetScript()->GetOrCreateScriptLocals();
    }

    TESTopic_ClearAllSaidOnceInfosForQuest(this);
    FUN_0060c9c0(HasFlag0x10());
    SetCompleted(false);
    SetFailed(false);
    SetFlag20(false);
}
