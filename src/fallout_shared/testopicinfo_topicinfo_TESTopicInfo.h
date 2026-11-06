// Source layout: TESTopicInfo. PC corrections are in generate_headers.py.
#ifndef FNV_TESTOPICINFO_H
#define FNV_TESTOPICINFO_H

#include "testopicinfo_topicinfo_layout_support.h"
#include "testopicinfo_topicinfo_TESCondition.h"
#include "../../include/TESForm.h"
#include "TopicInfoData.h"
class TESTopicInfo : public TESForm
{
  public:
    PerkEntryConditionSet m_kInfoConditions;  // +0x18
    unsigned short m_uiInfoIndex;    // +0x20
    bool m_bGoodbye;                 // +0x22
    TopicInfoData m_Data;          // +0x23
    unsigned char layoutPadding27[1];
    BSStringT<char> m_kPrompt;                  // +0x28
    BSSimpleList<TESTopic*> m_kAddTopicList;    // +0x30
    TESTopicInfoData* m_pResponseData;       // +0x38
    TESActorBase* m_pDialogueSpeaker;           // +0x3C
    TESForm* m_pPerkSkillStat;                  // +0x40
    SPEECH_CHALLENGE_LEVEL m_eDifficultyLevel;  // +0x44
    TESQuest* m_pOwnerQuest;                    // +0x48
    unsigned long m_ulTopicFlags;               // +0x4C
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    void AddTopicList();
    TESResponseList* DuplicateResponseList(TESResponseList* list);
    virtual void InitItem();
    TESActorBase* GetSpeaker();
    void FormatDebugInfo(BSStringT<char>& text, bool firstOnly);
    bool IsSayOnceADay();
    bool IsRandomEnd();
    bool IsRandom();
    bool IsInfoValidForDialogue(bool& deferred, TESQuest* quest, TESObjectREFR* speaker, TESObjectREFR* listener);
    TESTopicInfoData* GetConversationData();
    Script* GetResultScript(unsigned int onEnd);
    bool HasResultScript();
    TESTopicInfo(DIALOGUE_TYPE type);
    void SetRandom(bool random);
    void SetTopicInfoData(TESTopicInfoData* data);
    virtual void InitializeComponent();
    virtual void ClearData();
    unsigned short GetInfoIndex();
    PerkEntryConditionSet* GetInfoConditions();
    void SetOwnerTopic(TESTopic* owner);
    void ResetResponseList();
    void ClearResponses();
    BSSimpleList<TESTopic*>* GetAddTopicList();
    void SetPrompt(const char* prompt);
    void SetSpeaker(TESActorBase* speaker);
    void SetActorValue(ActorValueInfo* value);
    void SetPerk(BGSPerk* perk);
    void SetDifficultyLevel(SPEECH_CHALLENGE_LEVEL difficulty);
    virtual bool LoadForm(TESFile* file);
};
FNV_STATIC_ASSERT(sizeof(TESTopicInfo) == 0x50);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_kInfoConditions) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_uiInfoIndex) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_bGoodbye) == 0x22);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_Data) == 0x23);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_kPrompt) == 0x28);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_kAddTopicList) == 0x30);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_pResponseData) == 0x38);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_pDialogueSpeaker) == 0x3C);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_pPerkSkillStat) == 0x40);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_eDifficultyLevel) == 0x44);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_pOwnerQuest) == 0x48);
FNV_STATIC_ASSERT(offsetof(TESTopicInfo, m_ulTopicFlags) == 0x4C);
#endif
