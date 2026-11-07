#pragma once

#include "TESForm.h"
#include "PerkEntryConditionSet.h"
#include "TopicInfoData.h"
#include "TESFile.h"

class ActorValueInfo;
class BGSPerk;
class Character;
class MagicItem;
class MobileObject;
class Script;
class TESActorBase;
class TESObjectREFR;
class TESQuest;
class TESResponseList;
class TESTopic;
class TESTopicInfoData;
class XActor;

enum DIALOGUE_TYPE;
enum SPEECH_CHALLENGE_LEVEL;

class TESTopicInfo : public TESForm
{
public:
    PerkEntryConditionSet m_kInfoConditions;
    unsigned short m_uiInfoIndex;
    bool m_bGoodbye;
    TopicInfoData m_Data;
    unsigned char layoutPadding27;
    BSStringT<char> m_kPrompt;
    BSSimpleList<TESTopic*> m_kAddTopicList;
    TESTopicInfoData* m_pResponseData;
    TESActorBase* m_pDialogueSpeaker;
    TESForm* m_pPerkSkillStat;
    SPEECH_CHALLENGE_LEVEL m_eDifficultyLevel;
    TESQuest* m_pOwnerQuest;
    unsigned long m_ulTopicFlags;

    TESTopicInfo(DIALOGUE_TYPE type);
    TESTopicInfo(int type);
    virtual ~TESTopicInfo();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();
    virtual void SetAltered(bool altered);
    virtual void Revert(BGSLoadFormBuffer* buffer);

    void __vslot_10();
    void Save();
    bool Load(TESFile* file);
    void Copy(TESForm* form);
    void ResetFormData();
    bool CopyTopicData(FormRecordHeader* header);
    bool CopyTopicData(TESForm* form);
    bool LoadTopicInfoData(FormRecordHeader* header, bool arg1, bool arg2);
    void CreateGroupData(FormRecordHeader* header, TESFileGroup* group);
    void SerializeTopicInfoData(void* data);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void LoadGameLegacy(unsigned int arg0, unsigned int arg1);
    virtual void RevertLegacy(unsigned int flags);

    void SetOwnerTopic(TESTopic* owner);
    int GetTopicType();
    int GetNextSpeaker();
    void SetNextSpeaker(int speaker);
    unsigned short GetInfoIndex();
    bool IsRunForRumors();
    void SetInfoIndex(unsigned short index);
    PerkEntryConditionSet* GetInfoConditions();
    void SetConditionList(PerkEntryConditionSet* conditions);
    BSSimpleList<TESTopic*>* GetAddTopicList();
    bool InAddTopicList(TESTopic* topic);
    void FormatDebugInfo(void* text, bool firstOnly);
    void FormatDebugInfo(BSStringT<char>& text, bool firstOnly);
    TESQuest* GetParentQuest();
    void SetOwnerQuest(TESQuest* quest);
    bool IsGoodbye();
    void SetGoodbye(bool goodbye);
    bool IsRandom();
    void SetRandom(bool random);
    bool IsRandomEnd();
    void SetRandomEnd(bool randomEnd);
    bool IsSayOnce();
    void SetSayOnce(bool sayOnce);
    bool IsInfoRefusal();
    void SetInfoRefusal(bool refusal);
    bool IsRunImmediately();
    void SetRunImmediately(bool immediately);
    bool IsRunRumorResults();
    void SetRunRumorResults(bool runResults);
    bool IsSpeechChallenge();
    void SetSpeechChallenge(bool challenge);
    bool IsSayOnceADay();
    void SetSayOnceADay(bool onceADay);
    bool IsAlwaysDarkened();
    void SetAlwaysDarkened(bool darkened);
    int GetDummyNodeState();
    void SetDummyNodeState(int state);
    TESTopicInfoData* GetConversationData();
    void SetTopicInfoData(TESTopicInfoData* data);
    const BSStringT<char>& GetPrompt();
    void SetPrompt(char* prompt);
    void SetPrompt(const char* prompt);
    bool HasPrompt();
    void SetActorValue(ActorValueInfo* value);
    void SetPerk(BGSPerk* perk);
    ActorValueInfo* GetActorValue();
    BGSPerk* GetPerk();
    TESForm* GetPerkSkillStat();
    int GetDifficultyLevel();
    void SetDifficultyLevel(int difficulty);
    void SetDifficultyLevel(SPEECH_CHALLENGE_LEVEL difficulty);
    int GetNextSpeakerType();
    TESActorBase* GetSpeaker();
    void SetSpeaker(TESActorBase* speaker);
    void SetSpeaker(MagicItem* speaker);
    void CloneResponseList(TESResponseList* list);
    Script* GetResultScript(int onEnd);
    Script* GetResultScript(unsigned int onEnd);
    bool HasResultScript();
    unsigned int GetTempDataOffset();
    void SetTempDataOffset(unsigned int offset);
    bool IsInfoValidForDialogue(bool* deferred, TESQuest* quest, TESObjectREFR* speaker, TESObjectREFR* listener);
    bool IsInfoValidForDialogue(bool& deferred, TESQuest* quest, TESObjectREFR* speaker, TESObjectREFR* listener);
    bool IsInfoValidForDialogue(TESQuest* quest, TESObjectREFR* speaker, TESObjectREFR* listener);
    void HyperLinkCompile(char* text);
    void RemoveHyperLinks();
    void AppendTopicInfo(int arg, TESObjectREFR* reference);
    void AddTopicList();
    bool SaidOnce();
    void SetSaidOnce();
    void ResetSaidOnceFlags();
    bool IsValidSaveID(bool arg);
    TESResponseList* DuplicateResponseList(TESResponseList* list);
    void ClearResponses();
    void ResetResponseList();
    TopicInfoData* GetData();
    void RunResultScript(bool onEnd, MobileObject* speaker);
    void RunResultScript(int onEnd, Character* speaker);
    void RunResultScript(int onEnd, XActor* speaker);
    bool IsNew();
    bool IsRefusal();
    void MarkAsRefusal();
    bool IsChallengeFlagSet();
    bool IsFlagSet();

    static void AddTopicInfoToSortedList(TESTopicInfo* info, void* list);
    static bool CompareTopicInfos(TESTopicInfo* left, TESTopicInfo* right);
};
