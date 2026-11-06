// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESRESPONSE_H
#define FNV_TESRESPONSE_H

#include "testopicinfo_topicinfo_layout_support.h"
#include "../../include/TESIdleForm.h"
#include "../../include/TESTopic.h"
class DialogueResponseData;

class DialogueResponseData
{
  public:
    DIALOGUE_EMOTION eEmotion;          // +0x0, 4 bytes
    unsigned int ActorProjectileState;  // +0x4, 4 bytes
    TESTopic* m_pTopic;                 // +0x8, 4 bytes
    unsigned char m_ucResponseFlags;    // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    TESSound* m_pResponseSound;  // +0x10, 4 bytes
    bool m_bTenthFlag;           // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // void __cdecl DialogueResponseData::*()
    // void __cdecl DialogueResponseData::*()
};
FNV_STATIC_ASSERT(sizeof(DialogueResponseData) == 24);
FNV_STATIC_ASSERT(offsetof(DialogueResponseData, eEmotion) == 0);
FNV_STATIC_ASSERT(offsetof(DialogueResponseData, ActorProjectileState) == 4);
FNV_STATIC_ASSERT(offsetof(DialogueResponseData, m_pTopic) == 8);
FNV_STATIC_ASSERT(offsetof(DialogueResponseData, m_ucResponseFlags) == 12);
FNV_STATIC_ASSERT(offsetof(DialogueResponseData, m_pResponseSound) == 16);
FNV_STATIC_ASSERT(offsetof(DialogueResponseData, m_bTenthFlag) == 20);
class TESResponse
{
  public:
    DialogueResponseData Data;        // +0x0, 24 bytes
    BSStringT<char> m_kResponseText;  // +0x18, 8 bytes
    TESIdleForm* m_pFirstIdleForm;    // +0x20, 4 bytes
    TESIdleForm* m_pSecondIdleForm;   // +0x24, 4 bytes
    TESResponse* pNext;               // +0x28, 4 bytes
    TESResponse();
    ~TESResponse();
    void Load(TESFile* file);
    void InitItem(TESForm* owner);
    void SetResponseText(const char* text);
    void SetSpeakerIdle(TESIdleForm* idle);
    void GetListenerIdle(TESIdleForm* idle);
    TESResponse* GetNext();
    void AppendResponse(TESResponse* response);
    void SetNext(TESResponse* apNext);  // 0x0061cc40 (folded +0x28 setter)
    // TESResponse
    // void __cdecl TESResponse::*()
    // void __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(TESFile*)
    // void __cdecl TESResponse::*(TESForm*)
    // void __cdecl TESResponse::*(TESResponse*)
    // const char* __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(const char*)
    // unsigned int __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(TESQuest*, TESTopic*, char*, unsigned int)
    // void __cdecl TESResponse::*(TESQuest*, TESTopic*, TESTopicInfo*, BSStringT<char>&)
    // void __cdecl TESResponse::*(TESTopicInfo*, BSStringT<char>&)
    // GetAudioFullPath
    // bool __cdecl TESResponse::*(BGSVoiceType*, TESQuest*, TESTopic*, TESTopicInfo*, BSStringT<char>&, bool, bool)
    // unsigned int __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(unsigned char)
    // DIALOGUE_EMOTION __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(DIALOGUE_EMOTION)
    // unsigned int __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(unsigned int)
    // TESTopic* __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(TESTopic*)
    // TESIdleForm* __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(TESIdleForm*)
    // TESIdleForm* __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(TESIdleForm*)
    // TESSound* __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(TESSound*)
    // bool __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(bool)
    // unsigned int __cdecl TESResponse::*()
    // TESResponse* __cdecl TESResponse::*()
    // void __cdecl TESResponse::*(TESResponse*)
    // TESResponse* __cdecl TESResponse::*(TESResponse*)
    // void __cdecl TESResponse::*(TESResponse*)
    // DialogueResponseData* __cdecl TESResponse::*()
    // bool __cdecl TESResponse::*(BSStringT<char>&, const char*, const char*, const char*, const char*, const char*)
    // TESResponse& __cdecl TESResponse::*(const TESResponse&)
    // void* __cdecl TESResponse::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(TESResponse) == 44);
FNV_STATIC_ASSERT(offsetof(TESResponse, Data) == 0);
FNV_STATIC_ASSERT(offsetof(TESResponse, m_kResponseText) == 24);
FNV_STATIC_ASSERT(offsetof(TESResponse, m_pFirstIdleForm) == 32);
FNV_STATIC_ASSERT(offsetof(TESResponse, m_pSecondIdleForm) == 36);
FNV_STATIC_ASSERT(offsetof(TESResponse, pNext) == 40);
#endif
