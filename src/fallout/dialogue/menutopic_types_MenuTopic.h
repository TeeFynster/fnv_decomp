// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MENUTOPIC_H
#define FNV_MENUTOPIC_H

#include "menutopic_layout.h"
#include "../../../include/TESQuest.h"
#include "../../../include/TESTopic.h"
#include "../../../include/TESTopicInfo.h"
#pragma pack(push, 4)
class MenuTopic
{
  public:
    BSStringT<char> m_kPrompt;  // +0x0, 8 bytes
    bool m_bFirstFlag;          // +0x8, 1 bytes
    bool m_bIsRefusal;          // +0x9, 1 bytes
    bool m_bThirdFlag;          // +0xA, 1 bytes
    unsigned char layoutPaddingB[1];
    BSSimpleList<DialogueResponse*> m_kResponseList;          // +0xC, 8 bytes
    TESQuest* pQuest;                                         // +0x14, 4 bytes
    TESTopicInfo* pInfo;                                      // +0x18, 4 bytes
    TESTopic* m_pOriginalTopic;                               // +0x1C, 4 bytes
    BSSimpleList<DialogueResponse*>* m_pCurrentResponseList;  // +0x20, 4 bytes
    bool m_bIsRemappedRumor;                                  // +0x24, 1 bytes
    bool m_bInfoHasBeenRead;                                  // +0x25, 1 bytes
    unsigned char layoutPadding26[2];
    TESTopic* pTopic;  // +0x28, 4 bytes
    // MenuTopic
    // void __cdecl MenuTopic::*()
    // FillResponseList
    // bool __cdecl MenuTopic::*()
    // const BSStringT<char>& __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // TESTopicInfo* __cdecl MenuTopic::*()
    // TESTopic* __cdecl MenuTopic::*()
    // TESQuest* __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // TESTopic* __cdecl MenuTopic::*()
    // void __cdecl MenuTopic::*(TESTopic*)
    // bool __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // DialogueResponse* __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // void __cdecl MenuTopic::*(bool)
    // bool __cdecl MenuTopic::*()
    // void __cdecl MenuTopic::*(bool)
    // unsigned short __cdecl MenuTopic::*()
    // SaveGame
    // LoadGame
    // MenuTopic& __cdecl MenuTopic::*(const MenuTopic&)
    // void* __cdecl MenuTopic::*(unsigned int)
    MenuTopic(TESQuest*, TESTopic*, TESTopicInfo*, MobileObject*, bool);
    DialogueResponse* GetActiveResponse();
    MenuTopicText* FUN_0045cd60(float);
    BSStringT<char> BSStringT_char_RemoveCurlyContent();
    void MenuTopic_FillResponseList_0083df80(TESQuest*, TESTopic*, TESTopicInfo*, MobileObject*);
    void FillResponseList();
    void SaveTopic();
    TESTopicInfo* GetTopicInfo();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MenuTopic) == 44);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_kPrompt) == 0);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_bFirstFlag) == 8);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_bIsRefusal) == 9);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_bThirdFlag) == 10);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_kResponseList) == 12);
FNV_STATIC_ASSERT(offsetof(MenuTopic, pQuest) == 20);
FNV_STATIC_ASSERT(offsetof(MenuTopic, pInfo) == 24);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_pOriginalTopic) == 28);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_pCurrentResponseList) == 32);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_bIsRemappedRumor) == 36);
FNV_STATIC_ASSERT(offsetof(MenuTopic, m_bInfoHasBeenRead) == 37);
FNV_STATIC_ASSERT(offsetof(MenuTopic, pTopic) == 40);
#endif
