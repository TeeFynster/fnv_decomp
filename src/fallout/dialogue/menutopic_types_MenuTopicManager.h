// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MENUTOPICMANAGER_H
#define FNV_MENUTOPICMANAGER_H

#include "menutopic_layout.h"
#include "../../../include/TESObjectREFR.h"
class MenuTopic;
#pragma pack(push, 4)
class TopicMenuController
{
  public:
    BSSimpleList<MenuTopic*>* m_pCurrentTopicList;              // +0x0, 4 bytes
    BSSimpleList<BSSimpleList<MenuTopic*>*> m_kTopicListStack;  // +0x4, 8 bytes
    TESObjectREFR* m_pDialogueSpeaker;                          // +0xC, 4 bytes
    bool m_bControllerFlag;                                     // +0x10, 1 bytes
    unsigned char layoutPadding11[3];
    int m_iTopicIndex;  // +0x14, 4 bytes
    // void __cdecl TopicMenuController::*()
    // bool __cdecl TopicMenuController::*(bool)
    // bool __cdecl TopicMenuController::*()
    // bool __cdecl TopicMenuController::*(int)
    // MenuTopic* __cdecl TopicMenuController::*()
    // void __cdecl TopicMenuController::*()
    // MenuTopic* __cdecl TopicMenuController::*()
    // BSSimpleList<MenuTopic *>* __cdecl TopicMenuController::*()
    // TopicMenuController
    // void __cdecl TopicMenuController::*()
    // void __cdecl TopicMenuController::*(BSSimpleList<MenuTopic *>*, bool)
    // void __cdecl TopicMenuController::*(BSSimpleList<TESTopic *>*, bool, bool, TESTopic*)
    // void __cdecl TopicMenuController::*(BSSimpleList<MenuTopic *>*)
    // BSSimpleList<MenuTopic *>* __cdecl TopicMenuController::*()
    // void __cdecl TopicMenuController::*(BSSimpleList<MenuTopic *>*)
    // int __cdecl TopicMenuController::*(MenuTopic*, MenuTopic*)
    // TopicMenuController* __cdecl TopicMenuController::*()
    // void __cdecl TopicMenuController::*()
    // bool __cdecl TopicMenuController::*(TESObjectREFR*, TESTopic*)
    // void __cdecl TopicMenuController::*()
    // bool __cdecl TopicMenuController::*(MenuTopic*)
    // void __cdecl TopicMenuController::*()
    // int __cdecl TopicMenuController::*()
    // bool __cdecl TopicMenuController::*()
    // TESObjectREFR* __cdecl TopicMenuController::*()
    // TopicMenuController& __cdecl TopicMenuController::*(const TopicMenuController&)
    // void* __cdecl TopicMenuController::*(unsigned int)
    BSSimpleList<MenuTopic*>* MenuTopicManager_GetCurrentTopicList();
    bool SelectTopic(bool advance);
    bool AdvanceTopic();
    MenuTopic* GetSelectedTopic();
    MenuTopic* GetFirstTopic();
    static void IncrementMiscStat(int id);
    void MenuTopicManager_ClearData();
    bool Initialize(MobileObject*, TESTopic*);
    void BuildTopicList(BSSimpleList<TESTopic*>*, bool, bool, TESTopic*);
    TopicMenuController();
    static TopicMenuController* GetInstance();
    void RunTopicResultScript();
};
#pragma pack(pop)
extern TopicMenuController* g_011ddde4;
FNV_STATIC_ASSERT(sizeof(TopicMenuController) == 24);
FNV_STATIC_ASSERT(offsetof(TopicMenuController, m_pCurrentTopicList) == 0);
FNV_STATIC_ASSERT(offsetof(TopicMenuController, m_kTopicListStack) == 4);
FNV_STATIC_ASSERT(offsetof(TopicMenuController, m_pDialogueSpeaker) == 12);
FNV_STATIC_ASSERT(offsetof(TopicMenuController, m_bControllerFlag) == 16);
FNV_STATIC_ASSERT(offsetof(TopicMenuController, m_iTopicIndex) == 20);
#endif
