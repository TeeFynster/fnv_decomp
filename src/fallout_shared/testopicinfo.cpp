#include "../../include/BSStringT.h"
// fallout_shared/testopicinfo.cpp: topic-info loading, responses and dialogue helpers.

// Shared file and actor headers need the Windows types before the unit layout helpers.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "testopicinfo_topicinfo_layout_support.h"
#include "../../include/Actor.h"
#include "../../include/ActorValueInfo.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSPerk.h"
#include "../../include/MapEntryCount.h"
#include "../../include/PerkEntryConditionSet.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESIdleForm.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESQuest.h"
#include "../../include/TESResponse.h"
#include "../../include/TESResponseList.h"
#include "../../include/TESTopic.h"
#include "../../include/TESTopicInfo.h"
#include "../../include/TESTopicInfoData.h"
#include "../../include/TopicInfoArray.h"
#include "testopicinfo_topicinfo_helpers.h"
#include "TESFile.h"
#include "../../include/Script.h"
#include "../../include/TESForm.h"
#include "ScriptVariableInfo.h"
#include "ScriptReferencedObject.h"
#include "ScriptHeaderData.h"
#include "game_constants.h"
#include "original_script.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>

extern TESTopicInfo* g_cachedResultScriptInfo;
extern Script g_resultScripts[2];
extern ScriptVariableInfo* g_loadedScriptVariable;
extern const char g_emptyTopicInfoPrompt[];
extern TESResponseList g_topicInfoResponses;
extern TESTopicInfo* g_cachedResponseInfo;
extern TESTopic* g_loadingTopic;
extern const char g_topicInfoLoadWarning[];

// @fnv 0x0061dbd0
bool TESTopicInfo::LoadForm(TESFile* file)
{
    unsigned int previousInfoID;
    int responseCount;
    {
        unsigned char m_ucFormType = file->GetTESForm();
        if (m_ucFormType != kTopicInfoFormType)
            return false;
        if (!file->GetCached())
            m_ulTopicFlags = file->GetOffset();
        previousInfoID = kNoPreviousTopicInfo;
        struct TopicRecord
        {
            int chunk;
            unsigned int uiChunkType;
        } record;
        record.uiChunkType = 0;
        LoadRecordHeader(file);
        responseCount = 0;
        while (record.chunk = file->GetChunkID())
        {
            switch (record.chunk)
            {
            case kConditionDataChunk:
                GetInfoConditions()->Load(file);
                break;
            case kPreviousTopicInfoChunk:
                file->GetChunkData(&previousInfoID);
                if (previousInfoID)
                    RemapFormIDForFile(previousInfoID, file);
                break;
            case kTopicInfoDataChunk:
                file->GetChunkData(&m_Data, sizeof(m_Data));
                if (m_Data.type >= DIALOGUE_TYPE_DIALOGUE_TYPE_COUNT)
                    MarkForDeletion(true);
                if (m_Data.type == DIALOGUE_TYPE_DT_CONVERSATION)
                    SetTopicInfoData(0);
                break;
            case kAdditionalTopicChunk: {
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                GetAddTopicList()->AddTail(reinterpret_cast<TESTopic*>(topicID));
                break;
            }
            case kTopicInfoQuestChunk:
                file->GetChunkData(&record.uiChunkType);
                RemapFormIDForFile(record.uiChunkType, file);
                break;
            case kConversationLinkToChunk: {
                if (!GetConversationData())
                    SetTopicInfoData(0);
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                GetConversationData()->GetLinkToList()->AddTail(reinterpret_cast<TESTopic*>(topicID));
                break;
            }
            case kConversationLinkFromChunk: {
                if (!GetConversationData())
                    SetTopicInfoData(0);
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                GetConversationData()->GetLinkFromList()->AddTail(reinterpret_cast<TESTopic*>(topicID));
                break;
            }
            case kConversationFollowUpChunk: {
                if (!GetConversationData())
                    SetTopicInfoData(0);
                unsigned int infoID = 0;
                file->GetChunkData(&infoID);
                GetConversationData()->GetFollowUpInfoList()->AddTail(reinterpret_cast<TESTopicInfo*>(infoID));
                break;
            }
            case kTopicInfoPromptChunk: {
                char prompt[kTopicInfoPromptReadSize];
                file->GetChunkData(prompt, sizeof(prompt));
                SetPrompt(prompt);
                break;
            }
            case kTopicInfoPerkSkillChunk: {
                unsigned int formID = 0;
                file->GetChunkData(&formID);
                m_pPerkSkillStat = reinterpret_cast<TESForm*>(formID);
                break;
            }
            case kTopicInfoSpeakerChunk: {
                unsigned int speakerID = 0;
                file->GetChunkData(&speakerID);
                m_pDialogueSpeaker = reinterpret_cast<TESActorBase*>(speakerID);
                break;
            }
            case kTopicInfoDifficultyChunk: {
                unsigned int difficulty;
                file->GetChunkData(&difficulty);
                if (difficulty < SPEECH_CHALLENGE_LEVEL_SCL_COUNT)
                    SetDifficultyLevel(static_cast<SPEECH_CHALLENGE_LEVEL>(difficulty));
                if (m_eDifficultyLevel == SPEECH_CHALLENGE_LEVEL_SCL_NONE)
                    m_eDifficultyLevel = SPEECH_CHALLENGE_LEVEL_SCL_VERYEASY;
                break;
            }
            }
            if (!file->NextChunk())
                break;
        }
        if (m_Data.type == DIALOGUE_TYPE_DT_PERSUASION)
            m_Data.type = DIALOGUE_TYPE_DT_TOPIC;
        if (!IsDeleted())
        {
            if (!g_loadingTopic->InsertInfoAfter(reinterpret_cast<TESQuest*>(record.uiChunkType), this, previousInfoID))
                Warning(g_topicInfoLoadWarning, GetFormID(), g_loadingTopic->GetName(), g_loadingTopic->GetFormID(),
                        record.uiChunkType);
        }
        return true;
    }
}

// @fnv 0x0061ccd0
TESTopicInfo::TESTopicInfo(DIALOGUE_TYPE type)
{
    InitializeComponent();
    m_Data.type = static_cast<char>(type);
    if (type == DIALOGUE_TYPE_DT_CONVERSATION)
    {
        m_pResponseData = new TESTopicInfoData;
        SetRandom(true);
    }
}

// @fnv 0x0061e180
void TESTopicInfo::SetTopicInfoData(TESTopicInfoData* data)
{
    if (data)
    {
        if (!m_pResponseData)
            m_pResponseData = new TESTopicInfoData;
        m_pResponseData->Copy(this, data);
    }
    else
    {
        if (m_pResponseData)
        {
            delete m_pResponseData;
            m_pResponseData = 0;
        }
        m_pResponseData = new TESTopicInfoData;
    }
}

// Clears m_Data and the topic-info fields, sets the form type, prompt, speaker, actor value, perk and difficulty level to defaults.
// @fnv 0x0061cf40
void TESTopicInfo::InitializeComponent()
{
    memset(&m_Data, 0, sizeof(m_Data));
    m_ulTopicFlags = 0;
    m_bGoodbye = false;
    m_uiInfoIndex = kInvalidTopicInfoIndex;
    SetFormType(static_cast<ENUM_FORM_ID>(kTopicInfoFormType));
    m_pResponseData = 0;
    m_pOwnerQuest = 0;
    SetPrompt(g_emptyTopicInfoPrompt);
    SetSpeaker(static_cast<TESActorBase*>(0));
    SetActorValue(0);
    SetPerk(0);
    SetDifficultyLevel(SPEECH_CHALLENGE_LEVEL_SCL_VERYEASY);
}

// Removes every entry from the add-topic list returned by GetAddTopicList until the list is empty.
// @fnv 0x0061d250
void TESTopicInfo::ResetResponseList()
{
    BSSimpleList<TESTopic*>* topics = GetAddTopicList();
    while (topics && !topics->IsEmpty())
        topics->RemoveHead();
}

// @fnv 0x0061d230
void TESTopicInfo::ClearResponses()
{
    g_topicInfoResponses.ClearResponses();
}

// @fnv 0x0061cff0
void TESTopicInfo::ClearData()
{
    if (!IsTemporary())
    {
        if (GetInfoIndex() != kInvalidTopicInfoIndex)
        {
            TESTopic* owner = TESTopic::GetTopicFromInfo(this);
            if (owner)
                SetOwnerTopic(owner);
        }
        GetInfoConditions()->InitializeConditionItems();
        ClearResponses();
        ResetResponseList();
        Script emptyScript;
        g_resultScripts[0].CopyScriptContents(&emptyScript);
        g_resultScripts[1].CopyScriptContents(&emptyScript);
    }
    g_cachedResponseInfo = 0;
    g_cachedResultScriptInfo = 0;
    if (m_pResponseData)
        delete m_pResponseData;
}

// @fnv 0x0061d140
void TESTopicInfo::SetOwnerTopic(TESTopic* owner)
{
    if (owner && GetInfoIndex() != kInvalidTopicInfoIndex)
    {
        QuestDialogueInfo* questInfo = owner->GetQuestInfoForInfo(this);
        if (questInfo)
        {
            TopicInfoArray* infoArray = questInfo->GetInfoArray();
            int iCount;
            if (infoArray->GetAt(GetInfoIndex()) == this)
                infoArray->RemoveAt(GetInfoIndex());
            else
            {
                bool bFound = false;
                iCount = infoArray->GetSize();
                for (int index = 0; index < iCount; index++)
                {
                    if (infoArray->GetAt(index) == this)
                    {
                        infoArray->RemoveAt(index);
                        bFound = true;
                        break;
                    }
                }
            }
            infoArray->Compact();
            TESTopic::CompactTopicInfos(infoArray);
        }
    }
}

// @fnv 0x0061db30
void TESTopicInfo::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (buffer->GetChangeFlags().ContainsAnyFlags(0x80000000))
        m_bGoodbye = true;
}

// @fnv 0x0061db80
void TESTopicInfo::Revert(BGSLoadFormBuffer* buffer)
{
    TESForm::Revert(buffer);
    if (buffer->GetOldChangeFlags().ContainsAnyFlags(0x80000000))
        m_bGoodbye = false;
}

// @fnv 0x0061f150
void TESTopicInfo::AddTopicList()
{
    pPlayer->AddTopics(GetAddTopicList());
}

// Loads TESResponse records from the file's response chunk into list or g_topicInfoResponses, caching this as g_cachedResponseInfo when list is null.
// @fnv 0x0061e780
TESResponseList* TESTopicInfo::DuplicateResponseList(TESResponseList* pResponseList)
{
    unsigned char form;
    {
        struct ResponseRead
        {
            TESResponse* response;
            int chunk;
            TESFile* file;
        } responseReader;
        if (this == g_cachedResponseInfo)
        {
            if (pResponseList)
            {
                pResponseList->SetResponseList(g_topicInfoResponses.QResponseList());
                return pResponseList;
            }
            else
                return &g_topicInfoResponses;
        }
        if (!pResponseList)
        {
            g_cachedResponseInfo = this;
            ClearResponses();
        }
        responseReader.file = GetFile(-1);
        if (!responseReader.file || !m_ulTopicFlags)
            return pResponseList ? pResponseList : &g_topicInfoResponses;
        responseReader.file = responseReader.file->GetParentTESFile();
        if (!responseReader.file->SetOffset(m_ulTopicFlags))
            return pResponseList ? pResponseList : &g_topicInfoResponses;
        form = responseReader.file->GetTESForm();
        if (form != kTopicInfoFormType)
            return pResponseList ? pResponseList : &g_topicInfoResponses;
        responseReader.response = 0;
        while (responseReader.chunk = responseReader.file->GetChunkID())
        {
            switch (responseReader.chunk)
            {
            case 0x54445254:  // TRDT reader.response data
                responseReader.response = new TESResponse;
                responseReader.response->Load(responseReader.file);
                responseReader.response->InitItem(this);
                if (pResponseList)
                    pResponseList->AddTail(responseReader.response);
                else
                    g_topicInfoResponses.AddTail(responseReader.response);
                break;
            case 0x314d414e:  // NAM1 reader.response text
                if (responseReader.response)
                {
                    unsigned int size = responseReader.file->GetChunkSize();
                    char* text = static_cast<char*>(_alloca(size));
                    responseReader.file->GetChunkData(text, size);
                    responseReader.response->SetResponseText(text);
                }
                break;
            case 0x4d414e53:  // SNAM speaker idle
                if (responseReader.response)
                {
                    struct IdleReference
                    {
                        unsigned int formID;
                        TESForm* form;
                    } reference;
                    reference.formID = 0;
                    responseReader.file->GetChunkData(&reference.formID);
                    RemapFormIDForFile(reference.formID, responseReader.file);
                    TESIdleForm* idle = 0;
                    reference.form = GetFormByID(reference.formID);
                    if (reference.form && reference.form->GetFormType() == 72)
                        idle = static_cast<TESIdleForm*>(reference.form);
                    if (reference.formID && !idle)
                        Warning("DEFAULT: Unable to find idle (%08X) for info (%08X).", reference.formID, GetFormID());
                    responseReader.response->SetSpeakerIdle(idle);
                }
                break;
            case 0x4d414e4c:  // LNAM listener idle
                if (responseReader.response)
                {
                    struct IdleReference
                    {
                        unsigned int formID;
                        TESForm* form;
                    } reference;
                    reference.formID = 0;
                    responseReader.file->GetChunkData(&reference.formID);
                    RemapFormIDForFile(reference.formID, responseReader.file);
                    TESIdleForm* idle = 0;
                    reference.form = GetFormByID(reference.formID);
                    if (reference.form && reference.form->GetFormType() == 72)
                        idle = static_cast<TESIdleForm*>(reference.form);
                    if (reference.formID && !idle)
                        Warning("DEFAULT: Unable to find idle (%08X) for info (%08X).", reference.formID, GetFormID());
                    responseReader.response->GetListenerIdle(idle);
                }
                break;
            }
            if (!responseReader.file->NextChunk())
                break;
        }
        return pResponseList ? pResponseList : &g_topicInfoResponses;
    }
}

// @fnv 0x0061d290
void TESTopicInfo::InitItem()
{
    if (IsFormInitialized())
        return;
    TESFile* pFile = GetFile(-1);
    {
        BSSimpleList<TESTopic*>* previous = 0;
        TESResponse* pResponse;
        {
            BSSimpleList<TESTopic*>* pTopics = GetAddTopicList();
            while (pTopics && pTopics->GetItem())
            {
                unsigned int formID = reinterpret_cast<unsigned int>(pTopics->GetItem());
                RemapFormIDForFile(formID, pFile);
                TESTopic* topic = dynamic_cast<TESTopic*>(GetFormByID(formID));
                if (!topic)
                {
                    if (pTopics->GetNext() || !previous)
                        pTopics->RemoveHead();
                    else
                    {
                        previous->Remove(reinterpret_cast<TESTopic*>(formID));
                        pTopics = previous->GetNext();
                    }
                    TESTopic* ownerTopic = TESTopic::GetTopicFromInfo(this);
                    TESQuest* ownerQuest = 0;
                    if (ownerTopic)
                        ownerQuest = ownerTopic->GetParentQuest(this);
                    {
                        BSStringT<char> text;
                        FormatDebugInfo(text, true);
                        char description[260];
                        if (ownerTopic && ownerQuest)
                            sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                    GetFormID(), text.String(), ownerQuest->GetEditorName(), ownerQuest->GetFormID(),
                                    ownerTopic->GetName(), ownerTopic->GetFormID());
                        else
                            sprintf(description, "TopicInfo %08X \"%s\"", GetFormID(), text.String());
                        Warning("MASTERFILE: Unable to find topic (%08X) for %s", formID, description);
                    }
                }
                else
                {
                    pTopics->SetItem(topic);
                    previous = pTopics;
                    pTopics = pTopics->GetNext();
                }
            }
            unsigned int speakerID = reinterpret_cast<unsigned int>(GetSpeaker());
            if (speakerID)
            {
                RemapFormIDForFile(speakerID, GetFile(-1));
                SetSpeaker(dynamic_cast<TESActorBase*>(GetFormByID(speakerID)));
            }
            if (GetInfoConditions())
                GetInfoConditions()->InitItem(this);
            if (GetConversationData())
                GetConversationData()->InitItem(this);
            pResponse = g_topicInfoResponses.QResponseList();
            while (pResponse)
            {
                pResponse->InitItem(this);
                pResponse = pResponse->GetNext();
            }
            if (m_pPerkSkillStat)
            {
                struct PerkSkillResolution
                {
                    unsigned int formID;
                    TESForm* form;
                    ActorValueInfo* actorValue;
                } resolved;
                resolved.formID = reinterpret_cast<unsigned int>(m_pPerkSkillStat);
                RemapFormIDForFile(resolved.formID, GetFile(-1));
                resolved.form = GetFormByID(resolved.formID);
                resolved.actorValue = dynamic_cast<ActorValueInfo*>(resolved.form);
                if (resolved.actorValue)
                    m_pPerkSkillStat = resolved.actorValue;
                else
                {
                    BGSPerk* perk = dynamic_cast<BGSPerk*>(resolved.form);
                    m_pPerkSkillStat = perk;
                }
            }
            SetInitializationState(true);
        }
    }
}

// @fnv 0x0061c360
void TESTopicInfoData::InitItem(TESForm* owner)
{
    BSSimpleList<TESTopic*>* pPreviousTopic = 0;
    BSSimpleList<TESTopic*>* pTopicList = GetLinkToList();
    TESFile* pFile = owner ? owner->GetFile(-1) : 0;
    {
        struct InfoCursor
        {
            BSSimpleList<TESTopicInfo*>* current;
            BSSimpleList<TESTopicInfo*>* previous;
        } infoCursor;

        while (pTopicList && pTopicList->GetItem())
        {
            struct TopicResolution
            {
                TESTopic* topic;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(pTopicList->GetItem());
            TESForm::RemapFormIDForFile(resolved.formID, pFile);
            resolved.topic = 0;
            resolved.form = TESForm::GetFormByID(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_DIAL_ID)
                resolved.topic = static_cast<TESTopic*>(resolved.form);

            if (!resolved.topic)
            {
                if (pTopicList->GetNext() || !pPreviousTopic)
                    pTopicList->RemoveHead();
                else
                {
                    pPreviousTopic->Remove(reinterpret_cast<TESTopic*>(resolved.formID));
                    pTopicList = pPreviousTopic->GetNext();
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = TESTopic::GetTopicFromInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = context.topic->GetParentQuest(context.info);
                {
                    BSStringT<char> text;
                    context.info->FormatDebugInfo(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                context.info->GetFormID(), text.String(), context.quest->GetEditorName(),
                                context.quest->GetFormID(), context.topic->GetName(), context.topic->GetFormID());
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", context.info->GetFormID(), text.String());
                    Warning("MASTERFILE: Unable to find topic (%08X) for conversation data 'Link To' on %s",
                            resolved.formID, description);
                }
            }
            else
            {
                pTopicList->SetItem(resolved.topic);
                pPreviousTopic = pTopicList;
                pTopicList = pTopicList->GetNext();
            }
        }

        pPreviousTopic = 0;
        pTopicList = GetLinkFromList();
        while (pTopicList && pTopicList->GetItem())
        {
            struct TopicResolution
            {
                TESTopic* topic;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(pTopicList->GetItem());
            TESForm::RemapFormIDForFile(resolved.formID, pFile);
            resolved.topic = 0;
            resolved.form = TESForm::GetFormByID(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_DIAL_ID)
                resolved.topic = static_cast<TESTopic*>(resolved.form);

            if (!resolved.topic)
            {
                if (pTopicList->GetNext() || !pPreviousTopic)
                    pTopicList->RemoveHead();
                else
                {
                    pPreviousTopic->Remove(reinterpret_cast<TESTopic*>(resolved.formID));
                    pTopicList = pPreviousTopic->GetNext();
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = TESTopic::GetTopicFromInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = context.topic->GetParentQuest(context.info);
                {
                    BSStringT<char> text;
                    context.info->FormatDebugInfo(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                context.info->GetFormID(), text.String(), context.quest->GetEditorName(),
                                context.quest->GetFormID(), context.topic->GetName(), context.topic->GetFormID());
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", context.info->GetFormID(), text.String());
                    Warning("MASTERFILE: Unable to find topic (%08X) for conversation data 'Link From' on %s",
                            resolved.formID, description);
                }
            }
            else
            {
                pTopicList->SetItem(resolved.topic);
                pPreviousTopic = pTopicList;
                pTopicList = pTopicList->GetNext();
            }
        }

        infoCursor.current = GetFollowUpInfoList();
        infoCursor.previous = 0;
        while (infoCursor.current && infoCursor.current->GetItem())
        {
            struct InfoResolution
            {
                TESTopicInfo* followUp;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(infoCursor.current->GetItem());
            TESForm::RemapFormIDForFile(resolved.formID, pFile);
            resolved.followUp = 0;
            resolved.form = TESForm::GetFormByID(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_INFO_ID)
                resolved.followUp = static_cast<TESTopicInfo*>(resolved.form);

            if (!resolved.followUp)
            {
                if (infoCursor.current->GetNext() || !infoCursor.previous)
                    infoCursor.current->RemoveHead();
                else
                {
                    infoCursor.previous->Remove(reinterpret_cast<TESTopicInfo*>(resolved.formID));
                    infoCursor.current = infoCursor.previous->GetNext();
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = TESTopic::GetTopicFromInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = context.topic->GetParentQuest(context.info);
                {
                    BSStringT<char> text;
                    context.info->FormatDebugInfo(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                context.info->GetFormID(), text.String(), context.quest->GetEditorName(),
                                context.quest->GetFormID(), context.topic->GetName(), context.topic->GetFormID());
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", context.info->GetFormID(), text.String());
                    Warning("MASTERFILE: Unable to find topic (%08X) for conversation data 'Follow Up' on %s",
                            resolved.formID, description);
                }
            }
            else
            {
                infoCursor.current->SetItem(resolved.followUp);
                infoCursor.previous = infoCursor.current;
                infoCursor.current = infoCursor.current->GetNext();
            }
        }
    }
}

// @fnv 0x00409480
void TESTopicInfo::SetSpeaker(TESActorBase* apActor)
{
    m_pDialogueSpeaker = apActor;
}

// @fnv 0x00508d70
bool TESTopicInfo::HasResultScript()
{
    return (iFormFlags & 0x2000) ? true : false;
}

void __fastcall RemoveAllLists(void*);

// Clears the three conversation-link lists before destroying their list members.
// @fnv 0x0061c190
TESTopicInfoData::~TESTopicInfoData()
{
    RemoveAllLists(this);
}

// If head is null, stores a as the head node; otherwise forwards a to head->AppendResponse.
// @fnv 0x0061cc60
void TESResponseList::AddTail(TESResponse* pNode)
{
    if (pHead == 0)
    {
        pHead = pNode;
    }
    else
    {
        pHead->AppendResponse(pNode);
    }
}

// Constructs the three lists (link-from, link-to, follow-up infos; BSSimpleList ctor 0x0096a2d0 each).
// @fnv 0x0061ce40
TESTopicInfoData::TESTopicInfoData()
{}

// @fnv 0x0061cfd0
void TESTopicInfo::SetPrompt(char* apPrompt)
{
    m_kPrompt.Set(apPrompt, 0);
}

// Reads the flags byte at offset 0x26 and returns 1 if bit 0x10 is set, 3 if bit 0x20 is set, otherwise 2.
// @fnv 0x0061e720
// src: XBOX_PDB 0x0061e720
int __fastcall TESTopicInfo_GetDummyNodeState(const char* pThis)
{
    return (pThis[0x26] & 0x10) ? 1 : ((pThis[0x26] & 0x20) ? 3 : 2);
}

// @fnv 0x0061e760
void TESTopicInfo::CloneResponseList(TESResponseList* list)
{
    DuplicateResponseList(list);
}

// @fnv 0x0061eb40
void TESResponse::SetResponseText(const char* apResponseText)
{
    m_kResponseText.Set(apResponseText, 0);
}

// @fnv 0x0061f260
bool TESTopicInfo::IsSpeechChallenge()
{
    return (bool)(m_Data.flags & 0x10);
}

// @fnv 0x0061f340
void TESTopicInfo::SetInfoIndex(unsigned short usIndex)
{
    m_uiInfoIndex = usIndex;
}

void __cdecl Deallocate(void*);
// ABI adapter for the scalar deleting destructor, which has no source-level TESResponse declaration.
struct ResponseDeletion : TESResponse
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0061cb30
void* ResponseDeletion::DestroyAndFree(unsigned int flags)
{
    TESResponse::~TESResponse();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// Calls RemoveAll on the list at offset 8, on this object's own list, and on the list at offset 0x10.
// @fnv 0x0061c330
void __fastcall RemoveAllLists(void* data)
{
    static_cast<TESTopicInfoData*>(data)->m_kLinkToList.RemoveAll();
    static_cast<TESTopicInfoData*>(data)->m_kLinkFromList.RemoveAll();
    static_cast<TESTopicInfoData*>(data)->m_kFollowUpInfoList.RemoveAll();
}

// @fnv 0x0061cc40
void TESResponse::SetNext(TESResponse* next)
{
    pNext = next;
}

// Walks the response chain to its last node and links the given response onto the end of it.
// @fnv 0x0061cc90
void TESResponse::AppendResponse(TESResponse* apResponse)
{
    TESResponse* next = this;
    while (next->GetNext() != 0)
    {
        next = next->GetNext();
    }
    next->pNext = apResponse;
}

// @fnv 0x0061e5e0
TopicInfoData* TESTopicInfo::GetData()
{
    return &m_Data;
}

// @fnv 0x0061dad0
void TESTopicInfo::LoadGameLegacy(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    TESForm::LoadGameLegacy(aiFlags, aiCurrentFlags);
    if (aiFlags & 0x80000000)
        m_bGoodbye = true;
}

// Calls TESForm::Revert with the given buffer and, if the high bit of aiFlags is set, clears byte at offset 0x22.
// @fnv 0x0061db00
void TESTopicInfo::RevertLegacy(unsigned int aiFlags)
{
    TESForm::RevertLegacy(aiFlags);
    if (aiFlags & 0x80000000)
        m_bGoodbye = false;
}

// @fnv 0x0061cb60
void TESResponseList::SetResponseList(TESResponse* head)
{
    ClearResponses();
    TESResponse* previous = 0;
    while (head)
    {
        TESResponse* response = new TESResponse;
        response->CopyResponse(head);
        if (previous)
            previous->SetNext(response);
        else
            AddTail(response);
        previous = response;
        head = head->GetNext();
    }
}

// @fnv 0x0061d6a0
void TESTopicInfo::SetAltered(bool set)
{
    if (!IsTemporary() && set && IsFormInitialized())
    {
        TESTopic* owner = TESTopic::GetTopicFromInfo(this);
        if (owner)
            owner->SetAltered(true);
    }
    TESForm::SetAltered(set);
}

extern "C" void* _data_011c16bc;


// @fnv 0x0061e0f0
void TESTopicInfo::SetConditionList(PerkEntryConditionSet* apCond)
{
    if (apCond)
        m_kInfoConditions.CopyConditions(apCond, (PerkEntryConditionSet*)this);
    else
    {
        PerkEntryConditionSet temp;
        m_kInfoConditions.CopyConditions(&temp, (PerkEntryConditionSet*)this);
    }
}




// @fnv 0x0061e2b0
void TESTopicInfo::FormatDebugInfo(BSStringT<char>& text, bool firstOnly)
{
    ((::BSStringT<char>*)&text)->Set(0, 0);
    TESResponse* response = DuplicateResponseList(0)->QResponseList();
    while (response)
    {
        ((::BSStringT<char>*)&text)->operator+=(response->GetDialogueText());
        if (response->GetNext())
            ((::BSStringT<char>*)&text)->operator+=(" | ");
        if (firstOnly)
            break;
        response = response->GetNext();
    }
}

// @fnv 0x0061cdc0
void TESTopicInfo::SetRandom(bool abSet)
{
    abSet ? m_Data.flags |= 2 : m_Data.flags &= ~2;
}


// @fnv 0x0061f280
void TESTopicInfo::ResetSaidOnceFlags()
{
    m_bGoodbye = false;
    MarkAsUnmodified(0x80000000);
}

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011d0dc8;
int __fastcall TESTopicInfo_GetDummyNodeState(const char*);




// @fnv 0x0061e600
bool TESTopicInfo::IsInfoValidForDialogue(bool& rbDeferred, TESQuest* apQuest, TESObjectREFR* apSpeaker,
                                  TESObjectREFR* apListener)
{
    bool bResult;
    Actor* pActor;
    if (IsDeleted())
        return false;
    if (IsSayOnce() && IsNew())
        return false;
    {
        int iType = TESTopicInfo_GetDummyNodeState((const char*)this);
        pActor = 0;
        if (apListener && ((TESForm*)apListener)->IsActor())
            pActor = (Actor*)apListener;
        if (pActor && pActor->GetActorValue(static_cast<ActorValue::Index>(9)) <= *g_011d0dc8.Int())
        {
            if (iType == 3)
                return false;
        }
        else if (iType == 1)
            return false;
        bResult = false;
        {
            bool bQuestOK = true;
            if (apQuest)
                bQuestOK =
                    apQuest->GetConditions()->ContainsTrait(apSpeaker, apListener, rbDeferred, false);
            if (bQuestOK)
                bResult =
                    GetInfoConditions()->ContainsTrait(apSpeaker, apListener, rbDeferred, false);
        }
    }
    return bResult;
}

// @fnv 0x0061ceb0
TESTopicInfo::~TESTopicInfo()
{
    TESTopicInfo::ClearData();
}

extern unsigned int kGroupFormType;

struct TopicGroupIdentity
{
    bool HasFormID(unsigned int);
};

struct GROUP_PARENT_CHECK
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual bool CheckFormGRUP(FormRecordHeader*, bool, bool) = 0;
};

struct TopicInfoGroupCheck
{
    bool CheckGroupForm(FormRecordHeader*, bool, bool);
};

// @fnv 0x0061d820
bool TopicInfoGroupCheck::CheckGroupForm(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly)
{
    bool bretval;
    TESTopic* pparenttopic;

    bretval = false;
    if (apGroupFORM)
    {
        if (reinterpret_cast<unsigned int*>(apGroupFORM)[0] == kGroupFormType)
        {
            pparenttopic = TESTopic::GetTopicFromInfo(reinterpret_cast<TESTopicInfo*>(this));

            if (pparenttopic)
            {
                if (abAllowParentGroups)
                {
                    bretval = reinterpret_cast<GROUP_PARENT_CHECK*>(pparenttopic)
                                  ->CheckFormGRUP(apGroupFORM, abAllowParentGroups, abCurrentOnly);
                }

                if (!bretval && reinterpret_cast<unsigned int*>(apGroupFORM)[3] == 7 &&
                    reinterpret_cast<TopicGroupIdentity*>(pparenttopic)
                        ->HasFormID(reinterpret_cast<unsigned int*>(apGroupFORM)[2]))
                {
                    bretval = true;
                }
            }
        }
    }

    return bretval;
}

// Copies link-to, link-from and follow-up entries after clearing the destination lists.
// @fnv 0x0061c210
void TESTopicInfoData::Copy(TESTopicInfo* unused, TESTopicInfoData* source)
{
    if (!source)
        return;
    RemoveAllLists(this);
    TESTopic* item9;
    {
        BSSimpleList<TESTopic*>* iter = 0;
        item9 = 0;
        for (iter = source->GetLinkToList(); iter && iter->GetItem();)
        {
            item9 = iter->GetItem();
            iter = iter->GetNext();
            GetLinkToList()->AddTail(item9);
        }
        iter = source->GetLinkFromList();
        item9 = 0;
        for (; iter && iter->GetItem();)
        {
            item9 = iter->GetItem();
            iter = iter->GetNext();
            GetLinkFromList()->AddTail(item9);
        }
    }
    BSSimpleList<TESTopicInfo*>* follow2 = source->GetFollowUpInfoList();
    TESTopicInfo* followItem4;
    while (follow2 && (followItem4 = follow2->GetItem()) != 0)
    {
        follow2 = follow2->GetNext();
        GetFollowUpInfoList()->AddTail(followItem4);
    }
}

struct DialogueFormType : TESForm
{
    int FUN_00401170();
};
struct DialogueTopicCompare
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual bool Compare(TESTopic*);
};
TESTopic* FindTopicByInfo(TESForm*);
struct TopicInfoCompare : TESTopicInfo
{
    bool IsLessThan(TESForm*);
    bool CompareTopicForm(TESForm*);
};
// @fnv 0x0061d710
bool TopicInfoCompare::CompareTopicForm(TESForm* form)
{
    bool bResult = false;
    switch (static_cast<DialogueFormType*>(form)->FUN_00401170())
    {
    case 0x46: {
        TESTopicInfo* pOtherInfo = dynamic_cast<TESTopicInfo*>(form);
        if (pOtherInfo)
        {
            TESTopic* pSourceTopic = FindTopicByInfo(this);
            TESTopic* otherOwner = FindTopicByInfo(pOtherInfo);
            if (otherOwner && pSourceTopic && otherOwner != pSourceTopic)
            {
                bResult = reinterpret_cast<DialogueTopicCompare*>(pSourceTopic)->Compare(otherOwner);
            }
        }
        break;
    }
    case 0x45: {
        TESTopic* topic = dynamic_cast<TESTopic*>(form);
        if (topic)
        {
            TESTopic* owner = FindTopicByInfo(this);
            if (owner && owner != topic)
                bResult = reinterpret_cast<DialogueTopicCompare*>(owner)->Compare(topic);
        }
        break;
    }
    default:
        bResult = IsLessThan(form);
    }
    return bResult;
}

struct TopicInfoGroupInput
{
    unsigned int unk00;
    unsigned int unk04;
    TESTopicInfo* unk08;
    unsigned int unk0C;
};

struct TopicInfoGroupOutput
{
    TESResponse* pResponse;
    unsigned int unk04;
    unsigned int formID;
    unsigned int unk0C;
    unsigned int unk10;
};

extern TESTopicInfo* DAT_01187344;
extern TESResponse* DAT_01187020;
int __cdecl FindTopicByInfo(void* object);

struct TopicInfoGroupData
{
    void GetResponseForTopicInfo(TopicInfoGroupOutput* output, TopicInfoGroupInput* input);
};

// @fnv 0x0061d8c0
void TopicInfoGroupData::GetResponseForTopicInfo(TopicInfoGroupOutput* output, TopicInfoGroupInput* input)
{
    int iVar1;

    if (output != 0)
    {
        output->pResponse = 0;
        if (input != 0)
        {
            switch (input->unk0C)
            {
            case 0:
                if (input->unk08 == DAT_01187344)
                {
                    iVar1 = FindTopicByInfo(this);
                    if (iVar1 != 0)
                    {
                        output->pResponse = DAT_01187020;
                        output->unk0C = 7;
                        output->formID = ((TESForm*)iVar1)->GetFormID();
                        output->unk04 = 0;
                        output->unk10 = 0;
                    }
                }
                break;
            }
        }
    }
}

struct DebugTextOut;
int __cdecl DebugTextPrintf(DebugTextOut* out, const char* fmt, ...);



struct TopicInfoDebug : TESTopicInfo
{
    const char* GetFormTypeName();
    const char* GetEditorIDText();
    void PrintDebugInfo(DebugTextOut* out);
};

// Builds topic, quest and response text fragments and prints the form type, editor ID, form ID and those fragments via DebugTextPrintf.
// @fnv 0x0061d950
void TopicInfoDebug::PrintDebugInfo(DebugTextOut* out)
{
    char topicText3[260];
    topicText3[0] = 0;
    TESTopic* topicA = TESTopic::GetTopicFromInfo(this);
    if (topicA)
    {
        sprintf(topicText3, ", Topic '%s' (%08X)", topicA->GetName(), topicA->GetFormID());
    }
    char questText2[260];
    questText2[0] = 0;
    if (topicA && IsFormInitialized())
    {
        TESQuest* quest = topicA->GetParentQuest(this);
        if (quest)
        {
            sprintf(questText2, "Quest '%s' (%08X)", quest->GetEditorName(), quest->GetFormID());
        }
    }
    char responseText9[260];
    responseText9[0] = 0;
    TESResponse* response = DuplicateResponseList(0)->QResponseList();
    if (response)
    {
        sprintf(responseText9, ", Text: \"%s\"", response->GetDialogueText());
    }
    DebugTextPrintf(out, "%s Form '%s' (%08X): %s%s%s", GetFormTypeName(), GetEditorIDText(), GetFormID(), questText2,
                    topicText3, responseText9);
}

// The shared API returns the speech threshold from GetDifficultyLevel; this
// unit also needs the original getter for the stored difficulty enum.
struct TopicInfoDifficulty : TESTopicInfo
{
    SPEECH_CHALLENGE_LEVEL GetSpeechChallengeLevel();
};
// Copies topic info data from another TESTopicInfo: add-topic list, responses, prompt, perk/actor value, difficulty, speaker, result scripts and quest.
// @fnv 0x0061e330
void TESTopicInfo::Copy(TESForm* form)
{
    TESTopicInfo* topic = dynamic_cast<TESTopicInfo*>(form);
    if (!topic)
        return;
    BSSimpleList<TESTopic*>* source = 0;
    TESTopic* node = 0;
    TESForm::CopyFrom(form);
    m_Data = *topic->GetData();
    ResetResponseList();
    source = topic->GetAddTopicList();
    while (source && source->GetItem())
    {
        node = source->GetItem();
        source = source->GetNext();
        GetAddTopicList()->AddTail(node);
    }
    ClearResponses();
    TESResponse* response = topic->DuplicateResponseList(0)->QResponseList();
    while (response)
    {
        TESResponse* copy = new TESResponse;
        copy->CopyResponse(response);
        DuplicateResponseList(0)->AddTail(copy);
        response = response->GetNext();
    }
    SetPrompt(topic->GetPrompt().String());
    if (topic->m_pPerkSkillStat)
    {
        switch (topic->m_pPerkSkillStat->GetFormType())
        {
        case ENUM_FORM_ID_PERK_ID:
            SetPerk(reinterpret_cast<BGSPerk*>(topic->m_pPerkSkillStat));
            break;
        case ENUM_FORM_ID_AVIF_ID:
            SetActorValue(reinterpret_cast<ActorValueInfo*>(topic->m_pPerkSkillStat));
            break;
        default:
            m_pPerkSkillStat = topic->m_pPerkSkillStat;
        }
    }
    else
    {
        SetPerk(0);
    }
    SetDifficultyLevel(static_cast<TopicInfoDifficulty*>(topic)->GetSpeechChallengeLevel());
    SetSpeaker(topic->GetSpeaker());
    GetResultScript(0)->CopyScriptContents(topic->GetResultScript(0));
    GetResultScript(1)->CopyScriptContents(topic->GetResultScript(1));
    SetInfoIndex(topic->GetInfoIndex());
    SetConditionList(topic->GetInfoConditions());
    if (topic->GetConversationData())
        SetTopicInfoData(topic->GetConversationData());
    SetOwnerQuest(topic->GetParentQuest());
    SetInitializationState(topic->IsFormInitialized());
}

extern "C" void* __cdecl _alloca(unsigned int);
void ourMemset(void*, int, unsigned int);
struct FileOps : TESFile
{
    bool GetChunkData();
};

// Returns one of two cached result Script objects for this topic info, resetting and reloading them from the file's SC* chunks when the cache misses.
// @fnv 0x0061eb60
Script* TESTopicInfo::GetResultScript(unsigned int auiIndex)
{
    unsigned int h = auiIndex;
    if (this == g_cachedResultScriptInfo)
        return &g_resultScripts[h];
    g_cachedResultScriptInfo = this;
    Script i;
    g_resultScripts[0].CopyScriptContents(&i);
    g_resultScripts[0].NotifySaveLoadGameOfFormChange();
    g_resultScripts[0].GetHeader()->m_bQuest = false;
    g_resultScripts[1].CopyScriptContents(&i);
    g_resultScripts[1].NotifySaveLoadGameOfFormChange();
    g_resultScripts[1].GetHeader()->m_bQuest = false;
    if (!HasResultScript())
        return &g_resultScripts[h];
    g_resultScripts[0].SetInitializationState(false);
    g_resultScripts[1].SetInitializationState(false);
    TESFile* a = GetFile(-1);
    if (!a || !m_ulTopicFlags)
        return &g_resultScripts[h];
    a = a->GetParentTESFile();
    if (!a->SetOffset(m_ulTopicFlags))
        return &g_resultScripts[h];
    unsigned char p = a->GetTESForm();
    if (p != 0x46)
        return &g_resultScripts[h];
    int s = 0;
    int f;
    while (f = a->GetChunkID())
    {
        switch (f)
        {
        case 0x5458454e:
            s += 1;
            break;
        case 0x44534c53:
        case 0x52564353:
            if (a->GetChunkID() == 0x44534c53)
            {
                g_loadedScriptVariable = new ScriptVariableInfo;
                g_loadedScriptVariable->Load(a);
                g_resultScripts[s].GetVariableList()->AddTail(g_loadedScriptVariable);
            }
            else if (g_loadedScriptVariable)
            {
                char* name = (char*)_alloca(a->GetChunkSize());
                a->GetChunkData(name, 0x200);
                g_loadedScriptVariable->name.Set(name, 0);
            }
            break;
        case 0x52484353:
            a->GetChunkData(g_resultScripts[s].GetHeader(), 0);
            if (((FileOps*)a)->GetChunkData())
                g_resultScripts[s].GetHeader()->Endian();
            break;
        case 0x41444353: {
            unsigned int size = a->GetChunkSize();
            char* data = (char*)_alloca(size);
            ourMemset(data, 0, size);
            a->GetChunkData(data, 0);
            g_resultScripts[s].SetScriptData(size, data);
            break;
        }
        case 0x4f524353: {
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            unsigned int id;
            a->GetChunkData(&id);
            reference->pForm = (TESForm*)id;
            g_resultScripts[s].GetReferencedObjectList()->AddTail(reference);
            break;
        }
        case 0x56524353: {
            ScriptReferencedObject* variable = new ScriptReferencedObject;
            unsigned int id;
            a->GetChunkData(&id);
            variable->m_uiFormID = id;
            g_resultScripts[s].GetReferencedObjectList()->AddTail(variable);
            break;
        }
        }
        if (!a->NextChunk())
            break;
    }
    g_resultScripts[0].InitItem(this);
    g_resultScripts[1].InitItem(this);
    return &g_resultScripts[h];
}

extern GlobalObject2_0040c150 g_011cc06c;
extern GlobalObject2_0040c150 g_011cc03c;
extern GlobalObject2_0040c150 g_011cc058;
extern GlobalObject2_0040c150 g_011cc024;
extern GlobalObject2_0040c150 g_011cbf54;

// @fnv 0x0061f2b0
int TESTopicInfo::GetDifficultyLevel()
{
    switch (m_eDifficultyLevel)
    {
    case 1:
        return *g_011cc06c.Int();
    case 2:
        return *g_011cc03c.Int();
    case 3:
        return *g_011cc058.Int();
    case 4:
        return *g_011cc024.Int();
    case 5:
        return *g_011cbf54.Int();
    }
    return -1;
}

extern unsigned int kGroupFormType;
TESForm* TESForm_GetFormByNumericID(unsigned int id);
struct TopicGroupRecord
{
    unsigned int unk00;
    int unk04;
    unsigned int unk08;
    int unk0C;
};
// CheckFormGRUP is not yet declared with this unit's group-record signature.
struct TopicGroupCheck : TESTopic
{
    bool IsFormInGroup(TopicGroupRecord* arg);
};
// @fnv 0x00619510
bool TopicGroupCheck::IsFormInGroup(TopicGroupRecord* pGroupObj)
{
    bool result = false;
    if (pGroupObj != 0 && pGroupObj->unk00 == kGroupFormType)
    {
        switch (pGroupObj->unk0C)
        {
        case 0:
            result = TESForm::CheckFormGRUP(pGroupObj);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            result = false;
            break;
        case 7: {
            TESTopic* t = dynamic_cast<TESTopic*>(TESForm_GetFormByNumericID(pGroupObj->unk08));
            if (t)
                result = Sort(t);
            break;
        }
        }
    }
    return result;
}

