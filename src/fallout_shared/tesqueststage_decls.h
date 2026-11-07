// Private quest-stage declarations.
#ifndef FNV_TESQUESTSTAGE_PRIVATE_DECLS_H
#define FNV_TESQUESTSTAGE_PRIVATE_DECLS_H

class QuestStage;
class PlayerQuestData;
class Date;
class ScriptContext;

class QuestStage
{
  public:
    ~QuestStage();
    unsigned char GetIndex();
    void MarkDone(bool done);
    bool TESQuestStageItem_GetEndQuest();
    bool IsFlag2Set();
    Script* GetOffsetC();
    unsigned char m_done;
    unsigned char layoutPadding1[11];
    unsigned int m_uiEdgeIndex;
    unsigned char layoutPadding10[0x65 - 0x10];
    unsigned char m_bCompleteObjective;
    unsigned char layoutPadding66[2];
    Date* m_pCompletionDate;
    TESQuest* m_pSharedOwner;
};

class RegionDataEntry
{
  public:
    unsigned int m_ucClipIdentifier;
    unsigned int m_bCompleted;
    void Endian();
};

class RegionObjectEntry
{
  public:
    void Load(TESFile* file);
    unsigned char m_done;
    unsigned char layoutPadding1[11];
    unsigned int m_uiEdgeIndex;
};

class ScriptContext
{
  public:
    void* ExtraDataList_GetScriptLocals();
};

class PlayerQuestData
{
  public:
    PerkEntryConditionSet* GetConditions();
    bool Load(TESFile* file);
    void InitItem(TESForm* form, QuestStage* stage);
    Script* GetOffsetC();
    void SetNextQuest(TESQuest* quest);
    unsigned char m_type;
    unsigned char layoutPadding1[11];
    Script m_pScript;
    unsigned int m_formID;
    unsigned char layoutPadding64[8];
    TESQuest* m_pSharedOwner;
    unsigned int m_nameIndex;
};

#include "../../include/CALENDAR_MONTH.h"

class Calendar
{
  public:
    unsigned int Calendar_GetYear();
    CALENDAR_MONTH GetCurrentMonth();
    signed char GetGameHour();
};

class Date
{
  public:
    Date(short day, CALENDAR_MONTH month, unsigned int year);
    unsigned int value;
};

extern Calendar g_calendar;
extern PlayerCharacter* g_thePlayer;
extern "C" ScriptVariableInfo* DAT_011cb8ec;

int __cdecl Warning();
unsigned int __cdecl SetWarningState(bool enabled);
void __cdecl BGSMessageWarningAuxiliary(int value);
extern "C" const char DAT_0104ae98[];
extern "C" const char DAT_0104ae54[];
#endif
