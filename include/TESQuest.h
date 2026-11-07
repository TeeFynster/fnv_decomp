#pragma once

#include "TESForm.h"
#include "TESScriptableForm.h"
#include "TESIcon.h"
#include "TESFullName.h"
#include "QuestData.h"
#include "PerkEntryConditionSet.h"
#include "MagicTarget.h"

class QuestStage;
class BGSQuestObjective;
class RegionObjectEntry;
class ScriptLocals;
class QuestObjectiveList;
class BGSSaveFormBuffer;

template <class T> class PlayerList;

class TESQuest : public TESForm, public TESScriptableForm, public TESIcon, public TESFullName
{
public:
    class QuestDataDefaults : public QuestData
    {
    public:
        QuestDataDefaults();
    };

    QuestDataDefaults data;
    BSSimpleList<QuestStage*> m_kStageList;
    BSSimpleList<BGSQuestObjective*> m_kObjectives;
    PerkEntryConditionSet m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    unsigned char layoutPadding61[3];
    BSStringT<char> strEditorID;

    TESQuest();
    virtual ~TESQuest();
    virtual void ClearData();
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void InitItem();
    virtual const char* GetEditorName() const;

    void ResetFormData();
    void RemoveAllStages();
    void ClearObjectives();
    unsigned int GetStageMask();
    void UpdateStageMask();
    bool HasStage(unsigned char index);
    bool IsStageComplete(unsigned char index);
    BGSQuestObjective* GetObjective(unsigned int index);
    void GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets,
                                 BSSimpleList<BGSQuestObjective*>* objectives);
    bool HasTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets,
                                 BSSimpleList<BGSQuestObjective*>* objectives);
    void GetTargetsAndObjectives(PlayerList<RegionObjectEntry*>* targets,
                                 PlayerList<BGSQuestObjective*>* objectives);
    bool HasTargetsAndObjectives(PlayerList<RegionObjectEntry*>* targets,
                                 PlayerList<BGSQuestObjective*>* objectives);
    bool Load(TESFile* file);
    bool GetEnabled();
    void SetEnabled(bool enabled);
    bool GetCompleted();
    bool GetAllowRepeatStages();
    bool GetAllowRepeatedTopics();
    void RunScript();
    void SetStartsEnabled(bool enabled);
    PerkEntryConditionSet* GetConditions();
    ScriptLocals* GetScriptLocalData();
    BSSimpleList<QuestStage*>* GetStageList();
    BSSimpleList<BGSQuestObjective*>* GetObjectiveList();
    QuestStage* GetStage(unsigned char index);
    void AddStageDataAtIndex(QuestStage* stage);
    void AddObjective(BGSQuestObjective* objective);
    void MarkCompleted(bool completed);
    void SetQuestCompleted(bool failed);
    bool HasFlag40();
    bool HasFlag20();
    bool HasFlag0x10();
    void SetFlag20(bool set);
    void WriteToBuffer(BGSSaveFormBuffer* buffer);
    void SaveIfChanged(BGSSaveFormBuffer* buffer);
    void LoadQuestData(unsigned int flags, unsigned int extra);
    void SetAllObjectivesComplete(int value);
    void FUN_0060c9c0(bool set);
    void SetCompleted(bool set);
    void SetFailed(bool set);
    void ProcessEntries_0060d720();
    void Save_0060cd60();
    unsigned short GetSaveSize_0060dba0(unsigned int changedFlags);
    void SaveGame_0060dd50(unsigned int flags);
    void RevertTES_0060e6a0(unsigned int flags);
    void CheckSaveGame(BGSSaveFormBuffer* buffer);
    float QueuedModel_GetOverriddenVisualDistance();
    QuestObjectiveList* FUN_005d43e0();
};
