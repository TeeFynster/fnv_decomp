#pragma once

// TESQuestStageItem: one log entry of a quest stage, no vtable (units call it PlayerQuestData). 0x74 bytes: the quest
// stage loader (0x0060d346) news 0x74 before calling the constructor 0x0060f520, which clears the byte at +0x00,
// constructs the condition list at +0x04 (0x00680890) and the Script at +0x0c (Script::Script 0x005aa0f0), and zeroes
// +0x60, +0x64, +0x65, +0x68, +0x6c and +0x70. SetIndex 0x0060d4b0 writes +0x64, SetHasLogEntry 0x0060d490 writes +0x65.

#include "PerkEntryConditionSet.h"
#include "Script.h"

class Date;
class QuestStage;
class TESFile;
class TESForm;
class TESQuest;

class TESQuestStageItem
{
public:
    unsigned char ucFlags;                        // 0x00
    PerkEntryConditionSet kConditions;            // 0x04
    Script kResultScript;                         // 0x0c
    unsigned int uiFileOffset;                    // 0x60
    unsigned char ucIndex;                        // 0x64 SetIndex
    bool bHasLogEntry;                            // 0x65 SetHasLogEntry
    Date* pLogDate;                               // 0x68
    TESQuest* pOwner;                             // 0x6c
    TESQuest* pNextQuest;                         // 0x70

    TESQuestStageItem();                          // 0x0060f520
    bool Load(TESFile* file);                     // 0x0060f6a0
    void InitItem(TESForm* form, QuestStage* stage);  // 0x0060fa10
    void Resolve();                               // 0x0060fb60
    TESQuest* GetEndQuest();                      // 0x0060fd70
    TESQuest* GetFailQuest();                     // 0x0060fd90
    void SetIndex(unsigned char index);           // 0x0060d4b0
    void SetHasLogEntry(bool value);              // 0x0060d490

    // folded accessors the units bind
    PerkEntryConditionSet* GetConditions();       // 0x00717e50
    Date* GetLogDate();                           // 0x008d8520
    void SetLogDate(Date* date);                  // 0x00407800
    void SetNextQuest(TESQuest* quest);           // 0x0057bd60
    Script* GetOffsetC();
};
