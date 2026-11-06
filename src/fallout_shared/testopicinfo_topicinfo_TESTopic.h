// Source layout: TESTopic. PC corrections are in generate_headers.py.
#ifndef FNV_TESTOPIC_H
#define FNV_TESTOPIC_H

#include "testopicinfo_topicinfo_layout_support.h"
#include "DialogueTopicData.h"
#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
class TESTopic : public TESForm
{
  public:
    TESFullName tESFullNameComponent;  // +0x18
    DialogueTopicData m_Data;              // +0x24
    unsigned char layoutPadding26[2];
    float m_fTopicParamB;                        // +0x28
    BSSimpleList<QuestDialogueInfo*> m_kQuestInfoList;  // +0x2C
    BSStringT<char> m_kDummyPrompt;              // +0x34
    int m_iTopicFlags;                           // +0x3C
    TESTopicInfo* FindMatchingTopicInfo(bool& deferred, TESObjectREFR* speaker, TESObjectREFR* listener, bool filter,
                                        TESTopic* previousTopic, BSSimpleList<DialogueItem*>* history);
    static TESTopicInfo* FindMatchingTopicInfo(const TESTopic* topic, bool& deferred, TESObjectREFR* speaker,
                                               TESObjectREFR* listener, bool filter, TESTopic* previousTopic,
                                               BSSimpleList<DialogueItem*>* history);
    bool IsRemappedRumors() const;
    static TESTopic* GetAudioBackendData(DIALOGUE_TYPE type, int subtype);
    BSSimpleList<QuestDialogueInfo*>* GetQuestInfoList() const;
    DIALOGUE_TYPE GetDialogueType();
    static TESTopic* GetTopicFromInfo(TESTopicInfo* info);
    QuestDialogueInfo* GetQuestInfoForInfo(TESTopicInfo* info);
    static void CompactTopicInfos(TopicInfoArray* infoArray);
    TESQuest* GetParentQuest(TESTopicInfo* info);
    bool InsertInfoAfter(TESQuest* quest, TESTopicInfo* info, unsigned int previousInfoID);
};
FNV_STATIC_ASSERT(sizeof(TESTopic) == 0x40);
FNV_STATIC_ASSERT(offsetof(TESTopic, tESFullNameComponent) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_Data) == 0x24);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_fTopicParamB) == 0x28);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_kQuestInfoList) == 0x2C);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_kDummyPrompt) == 0x34);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_iTopicFlags) == 0x3C);
#endif
