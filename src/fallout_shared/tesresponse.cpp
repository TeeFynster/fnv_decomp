#include "../../include/BSStringT.h"
#include "../../include/Stack.h"
// fallout_shared/tesresponse.cpp: TESResponse, DialogueResponseData (11 functions)

#include "tesresponse_support.h"
#include "../../include/NiPointer.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/MapEntryCount.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESIdleForm.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESQuest.h"
#include "../../include/TESResponse.h"
#include "../../include/TESResponseList.h"
#include "../../include/TESSound.h"
#include "../../include/TESTopic.h"
#include "../../include/TESTopicInfo.h"
#include "tesresponse_decls.h"
#include <stdio.h>
#include <string.h>

// Resolves the response's topic, sound and idle form IDs against the owner's file, clearing invalid ones and warning on failure, then applies the emotion value.
// @fnv 0x00617580
void TESResponse::InitItem(TESForm* owner)
{
    if (Data.m_pTopic)
    {
        struct FormResolution
        {
            unsigned int formID;
            TESForm* form;
        } resolved;
        resolved.formID = reinterpret_cast<unsigned int>(Data.m_pTopic);
        TESForm::RemapFormIDForFile(resolved.formID, owner->GetFile(-1));
        resolved.form = TESForm::GetFormByID(resolved.formID);
        if (resolved.form && static_cast<const TESForm*>(resolved.form)->GetFormType() == 69)
            Data.m_pTopic = static_cast<TESTopic*>(resolved.form);
        else
            Data.m_pTopic = 0;
        if (!Data.m_pTopic)
        {
            TESTopicInfo* info = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* topic = TESTopic::GetTopicFromInfo(info);
            TESQuest* quest = 0;
            if (topic)
                quest = topic->GetParentQuest(info);
            {
                BSStringT<char> text;
                info->FormatDebugInfo(text, true);
                char description[260];
                sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)", info->GetFormID(),
                        text.String(), quest ? quest->GetEditorName() : "", quest ? quest->GetFormID() : 0,
                        topic ? topic->GetName() : "", topic ? topic->GetFormID() : 0);
                Warning("MASTERFILE: Unable to find TESTopic (%08X) in TESResponse init for %s.", resolved.formID,
                        description);
            }
        }
    }
    if (Data.m_pResponseSound)
    {
        struct FormResolution
        {
            unsigned int formID;
            TESForm* form;
        } resolved;
        resolved.formID = reinterpret_cast<unsigned int>(Data.m_pResponseSound);
        TESForm::RemapFormIDForFile(resolved.formID, owner->GetFile(-1));
        resolved.form = TESForm::GetFormByID(resolved.formID);
        if (resolved.form && static_cast<const TESForm*>(resolved.form)->GetFormType() == 13)
            Data.m_pResponseSound = static_cast<TESSound*>(resolved.form);
        else
            Data.m_pResponseSound = 0;
        if (!Data.m_pResponseSound)
        {
            TESTopicInfo* info = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* topic = TESTopic::GetTopicFromInfo(info);
            TESQuest* quest = 0;
            if (topic)
                quest = topic->GetParentQuest(info);
            {
                BSStringT<char> text;
                info->FormatDebugInfo(text, true);
                char description[260];
                sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)", info->GetFormID(),
                        text.String(), quest ? quest->GetEditorName() : "", quest ? quest->GetFormID() : 0,
                        topic ? topic->GetName() : "", topic ? topic->GetFormID() : 0);
                Warning("MASTERFILE: Unable to find TESSound (%08X) in TESResponse init for %s.", resolved.formID,
                        description);
            }
        }
    }
    if (m_pFirstIdleForm)
    {
        struct FormResolution
        {
            unsigned int formID;
            TESForm* form;
        } resolved;
        resolved.formID = reinterpret_cast<unsigned int>(m_pFirstIdleForm);
        TESForm::RemapFormIDForFile(resolved.formID, owner->GetFile(-1));
        resolved.form = TESForm::GetFormByID(resolved.formID);
        if (resolved.form && static_cast<const TESForm*>(resolved.form)->GetFormType() == 72)
            m_pFirstIdleForm = static_cast<TESIdleForm*>(resolved.form);
        else
            m_pFirstIdleForm = 0;
        if (!m_pFirstIdleForm)
        {
            TESTopicInfo* info = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* topic = TESTopic::GetTopicFromInfo(info);
            TESQuest* quest = 0;
            if (topic)
                quest = topic->GetParentQuest(info);
            {
                BSStringT<char> text;
                info->FormatDebugInfo(text, true);
                char description[260];
                sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)", info->GetFormID(),
                        text.String(), quest ? quest->GetEditorName() : "", quest ? quest->GetFormID() : 0,
                        topic ? topic->GetName() : "", topic ? topic->GetFormID() : 0);
                Warning("MASTERFILE: Could not find speaker idle (%08X) in TESResponse init for %s.", resolved.formID,
                        description);
            }
        }
    }
    if (m_pSecondIdleForm)
    {
        struct FormResolution
        {
            unsigned int formID;
            TESForm* form;
        } resolved;
        resolved.formID = reinterpret_cast<unsigned int>(m_pSecondIdleForm);
        TESForm::RemapFormIDForFile(resolved.formID, owner->GetFile(-1));
        resolved.form = TESForm::GetFormByID(resolved.formID);
        if (resolved.form && static_cast<const TESForm*>(resolved.form)->GetFormType() == 72)
            m_pSecondIdleForm = static_cast<TESIdleForm*>(resolved.form);
        else
            m_pSecondIdleForm = 0;
        if (!m_pSecondIdleForm)
        {
            TESTopicInfo* info = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* topic = TESTopic::GetTopicFromInfo(info);
            TESQuest* quest = 0;
            if (topic)
                quest = topic->GetParentQuest(info);
            {
                BSStringT<char> text;
                info->FormatDebugInfo(text, true);
                // The original listener failure path does not initialize this buffer.
                char description[260];
                Warning("MASTERFILE: Could not find listener idle (%08X) in TESResponse init for %s.", resolved.formID,
                        description);
            }
        }
    }
    if (GetEmotion())
        SetEmotionValue(g_responseEmotionValue.Int()->i);
}

// Builds a filename from quest, topic and info when the response ID is nonzero, otherwise sets it to "New Response".
// @fnv 0x00617400
void TESResponse::BuildResponseFileName(TESQuest* quest, TESTopic* topic, TESTopicInfo* info, BSStringT<char>& filename)
{
    if (!quest || !topic || !info)
        return;
    unsigned int responseID = GetResponseID();
    if (responseID > 0)
    {
        char combined[260];
        BuildQuestTopicName(quest, topic, combined, sizeof(combined));
        unsigned int formID = info->GetFormID() & 0x00FFFFFF;
        filename.PrintfString("%s_%08X_%u", combined, formID, responseID);
    }
    else
        filename.Set("New Response", 0);
}

// @fnv 0x00616ce0
TESResponse::TESResponse()
{
    m_kResponseText.Set(0, 0);
    m_pFirstIdleForm = 0;
    m_pSecondIdleForm = 0;
    pNext = 0;
}

// @fnv 0x006172c0
void TESResponse::BuildQuestTopicName(TESQuest* quest, TESTopic* topic, char* output, unsigned int capacity)
{
    if (!output || !capacity)
        return;
    *output = 0;
    if (!quest || !topic)
        return;
    // Separate scopes preserve the original buffer lifetimes and stack ordering.
    unsigned int questLength;
    {
        char topicName[260];
        {
            char questName[260];
            {
                __insecure_strcpy(questName, quest->GetEditorName());
                __insecure_strcpy(topicName, topic->GetName());
                questLength = strlen(questName);
                unsigned int topicLength = strlen(topicName);
                if (questLength + topicLength > 25)
                {
                    struct NameLimits
                    {
                        unsigned int quest;
                        unsigned int topic;
                    } limits;
                    limits.quest = 10;
                    limits.topic = 15;
                    if (questLength > limits.quest)
                        questName[limits.quest] = 0;
                    else
                        limits.topic += limits.quest - questLength;
                    topicName[limits.topic] = 0;
                }
                sprintf_s(output, capacity, "%s_%s", questName, topicName);
            }
        }
    }
}

// Deletes every TESResponse in the linked list starting at pHead, then sets pHead to null.
// @fnv 0x0061cad0
void TESResponseList::ClearResponses()
{
    TESResponse* response = pHead;
    while (response)
    {
        TESResponse* next = response->GetNext();
        delete response;
        response = next;
    }
    pHead = 0;
}

// Reads the response data chunk from the TESFile if the chunk ID matches, converting endianness when required.
// @fnv 0x00617530
void TESResponse::Load(TESFile* file)
{
    if (file && file->GetChunkID() == 0x54445254)
    {
        file->GetChunkData(&Data, sizeof(Data));
        if (file->IsEndianConversionRequired())
            Data.Endian();
    }
}

// @fnv 0x00616de0
const char* TESResponse::GetDialogueText()
{
    return m_kResponseText.String() ? m_kResponseText.String() : "";
}

// @fnv 0x00616d70
DialogueResponseData::DialogueResponseData()
{
    eEmotion = static_cast<DIALOGUE_EMOTION>(0);
    ActorProjectileState = 50;
    m_pTopic = 0;
    m_ucResponseFlags = 0;
    m_pResponseSound = 0;
    m_bTenthFlag = true;
}

// @fnv 0x00616dc0
TESResponse::~TESResponse()
{}

// @fnv 0x006174b0
unsigned int TESResponse::GetResponseID()
{
    return Data.m_ucResponseFlags;
}

void* __cdecl __memcpy(void*, const void*, unsigned int);

// Copies the response data, text, and speaker/listener idle forms.
// @fnv 0x006174d0
void TESResponse::CopyResponse(TESResponse* apCopy)
{
    __memcpy(this, apCopy->GetData(), 24);
    m_kResponseText.Set(apCopy->GetDialogueText(), 0);
    SetSpeakerIdle(apCopy->GetSpeakerIdle());
    SetListenerIdle(apCopy->GetListenerIdle());
}
