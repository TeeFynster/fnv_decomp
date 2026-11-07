#pragma once

#include "MagicTarget.h"

class BGSLoadFormBuffer;
class DialogueResponse;
class DialoguePolicy;
class TESTopicInfo;
class TESTopic;
class TESQuest;
class TESObjectREFR;

class DialogueItem
{
public:
    BSSimpleList<DialogueResponse*> m_kResponseList;
    BSSimpleList<DialogueResponse*>* m_pCurrentResponseList;
    TESTopicInfo* pInfo;
    TESTopic* pTopic;
    TESQuest* pQuest;
    TESObjectREFR* m_pDialogueSpeaker;

    DialogueItem();
    DialogueItem(TESQuest* quest, TESTopic* topic, TESTopicInfo* info, TESObjectREFR* speaker);
    ~DialogueItem();
    static void operator delete(void*);
    void LoadDialogueItem(BGSLoadFormBuffer*);
    void RefreshObjectRef(BGSLoadFormBuffer*);
    bool SelectDefaultResponseList();
    bool NextResponse();
    DialogueResponse* GetActiveResponse();
    DialogueResponse* GetCurrentItem();
    DialogueResponse* GetResponseByIndex(short index);
    short GetResponseIndex(DialogueResponse*);
    TESTopicInfo* GetInfo();
    TESQuest* GetQuest();
    TESTopic* GetAudioBackendData();
    TESTopic* Deallocate();
    DialoguePolicy* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    bool FUN_0083c7b0();
    bool NextResponse_0083c7e0();
    void FUN_0083c850(int);
};
