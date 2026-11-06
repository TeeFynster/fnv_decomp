#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "DialogueTopicData.h"

class Actor;
class DialogueItem;
class FormRecordHeader;
class MobileObject;
class PlayerCharacter;
class QuestDialogueInfo;
class TESObjectREFR;
class TESQuest;
class TESTopicInfo;
class TopicInfoArray;
enum DIALOGUE_TYPE;

class TESTopic : public TESForm, public TESFullName
{
public:
    // Allocation size 0x48 (object_sizes.csv); members to 0x40 as in the original include/TESTopic.h layout.
    DialogueTopicData m_Data;                           // +0x24
    float m_fTopicParamB;                               // +0x28
    BSSimpleList<QuestDialogueInfo*> m_kQuestInfoList;  // +0x2C
    BSStringT<char> m_kDummyPrompt;                     // +0x34
    int m_iTopicFlags;                                  // +0x3C
    unsigned int unk40;                                 // +0x40
    unsigned int unk44;                                 // +0x44

    TESTopic(int);
    virtual ~TESTopic();
    void __vslot_10();
    bool Save(TESFile*);
    void Save();
    bool ReadTopicData(TESFile*);
    bool Load(TESFile*);
    virtual void InitItem();
    void ResetFormData();
    bool CopyTopicData(FormRecordHeader*);
    bool CopyTopicData(TESForm*);
    bool IsParentForm();
    bool IsFormType(unsigned char);
    void v0();

    static void BadQuestInfo(QuestDialogueInfo*);
    DialogueTopicData* GetData();
    DIALOGUE_TYPE GetDialogueType();
    float GetPriority();
    void SetPriority(float);
    bool IsRemappedRumors();
    bool IsRemappedRumors() const;
    void SetRemappedRumors(bool);
    bool IsTopLevel();
    void SetTopLevel(bool);
    int GetDummyNodeState();
    void SetDummyNodeState(int);
    bool IsPersuasion();
    bool IsNonMenuTopic();
    bool IsNew();
    void* GetQuestInfoList();
    BSSimpleList<QuestDialogueInfo*>* GetQuestInfoList() const;
    TopicInfoArray* GetInfoArray(TESQuest*);
    TESTopicInfo* GetInfoByID(TESQuest*, unsigned int, bool);
    TESTopicInfo* GetInfoByID(unsigned int, bool);
    static TESTopicInfo* GetInfoByIndex(QuestDialogueInfo*, unsigned int);
    TESTopicInfo* GetInfoByIndex(TESQuest*, unsigned int);
    TESQuest* GetParentQuest(TESTopicInfo*);
    QuestDialogueInfo* GetQuestInfoForInfo(TESTopicInfo*);
    const BSStringT<char>& GetDummyPrompt();
    void SetDummyPrompt(char*);
    bool HasDummyPrompt();
    void RemoveQuestInfo(TESQuest*);
    static void RemoveQuestFromAllTopics(TESQuest*);
    bool HasQuest(void*, bool);
    bool HasQuest(TESQuest*, bool);
    static void CompactTopicInfos(TopicInfoArray*);
    void CompactTopicInfos(TESQuest*);
    bool InsertInfoAfter(TESQuest*, TESTopicInfo*, unsigned int);
    QuestDialogueInfo* GetQuestInfoForQuest(TESQuest*, bool);
    bool AddInfoToEnd(TESQuest*, TESTopicInfo*);
    TESTopicInfo* CreateInfoAtIndex(TESQuest*, int);
    static void AddDefaultTopics();
    static void RemoveDefaultTopics();
    static TESTopic* GetAudioBackendData(int, int);
    static TESTopic* GetAudioBackendData(DIALOGUE_TYPE, int);
    static TESTopic* GetTopicFromInfo(TESTopicInfo*);
    static void AlterOwner(TESTopicInfo*);
    static void UpdateTopic(TESTopic*, void*, bool);
    static bool CompareTopics(TESTopic*, TESTopic*, bool);
    static void ReorderTopics(bool, void*);
    static void ReorderTopics(bool, BSSimpleList<TESTopic*>*);
    bool SortQuests();
    static bool IsQuestValidForTopics(TESQuest*);
    static bool IsFormTypeDialogueChild(unsigned char);
    static unsigned int GetDialogueTopicFlags(TESObjectREFR*, TESObjectREFR*, void*, TESTopic*);
    DialogueItem* CreateDialogueItem(TESObjectREFR*, TESObjectREFR*, TESTopic*, void*, bool);
    DialogueItem* CreateDialogueItem(Actor*, Actor*, TESTopic*, BSSimpleList<Actor*>*, bool);
    static TESTopicInfo* FindMatchingTopicInfo(void*, bool*, TESObjectREFR*, TESObjectREFR*, bool, TESTopic*, void*);
    static TESTopicInfo* FindMatchingTopicInfo(const TESTopic*, bool&, TESObjectREFR*, TESObjectREFR*, bool, TESTopic*, BSSimpleList<DialogueItem*>*);
    TESTopicInfo* FindMatchingTopicInfo(bool*, TESObjectREFR*, TESObjectREFR*, bool, TESTopic*, void*);
    TESTopicInfo* FindMatchingTopicInfo(bool&, TESObjectREFR*, TESObjectREFR*, bool, TESTopic*, BSSimpleList<DialogueItem*>*);
    TESTopicInfo* FindMatchingTopicInfo(bool*, TESObjectREFR*, TESObjectREFR*);
    TESTopicInfo* FindMatchingTopicInfo(TESObjectREFR*, TESObjectREFR*);
    TESTopicInfo* FindMatchingTopicInfo(MobileObject*, PlayerCharacter*);
    TESTopicInfo* FindMatchingTopicInfo(bool&, MobileObject*, PlayerCharacter*);
    static TESTopicInfo* FindFollowupTopicInfo(TESTopicInfo*, bool*, TESObjectREFR*, TESObjectREFR*, bool, void*);
    static void ResetAllTopics();
    void ResetTopics();
    int GetJournalIndex();
    void SetJournalIndex(int);
    bool AddJournalEntry(int, Actor*);
    static void SetShowConversationStats(bool);
    static bool GetShowConversationStats();
};
