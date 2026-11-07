#include "../../../include/BSSimpleList.h"
// fallout/dialogue/menutopic.cpp: TopicMenuController, MenuTopic, TESTopicInfo, TopicHolder and more (33 functions)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "menutopic_layout.h"
#include "../../../include/Actor.h"
#include "../../../include/ActorValueOwner.h"
#include "../../../include/TESFullName.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESTopicInfoData.h"
#include "../../../include/TESQuest.h"
#include "../../../include/TESResponseList.h"
#include "../../../include/TESResponse.h"
#include "menutopic_decls.h"
#include "menutopic_types_MenuTopic.h"
#include "menutopic_types_MenuTopicManager.h"
#include "../../../include/TESSaveLoadGame.h"

// @fnv 0x0083e170
DialogueResponse* MenuTopic::GetActiveResponse()
{
    if (m_pCurrentResponseList)
    {
        return m_pCurrentResponseList->GetItem();
    }
    else
    {
        return 0;
    }
}

// @fnv 0x0083e4c0
MenuTopic* TopicMenuController::GetSelectedTopic()
{
    if (m_pCurrentTopicList)
    {
        return m_pCurrentTopicList->GetItem();
    }
    else
    {
        return 0;
    }
}

// @fnv 0x0083e4f0
MenuTopic* TopicMenuController::GetFirstTopic()
{
    return MenuTopicManager_GetCurrentTopicList()->GetItem();
}

// Advances the stored iterator to its next entry and returns whether it exists and has an item.
// @fnv 0x0083e3e0
bool TopicMenuController::AdvanceTopic()
{
    if (m_pCurrentTopicList)
        m_pCurrentTopicList = m_pCurrentTopicList->GetNext();
    return m_pCurrentTopicList && m_pCurrentTopicList->GetItem();
}

// Advances the stored iterator when advance is set and it is non-null, then returns whether the iterator exists and has an item.
// @fnv 0x0083e370
bool TopicMenuController::SelectTopic(bool advance)
{
    m_pCurrentTopicList = MenuTopicManager_GetCurrentTopicList();
    if (advance && m_pCurrentTopicList)
        m_pCurrentTopicList = m_pCurrentTopicList->GetNext();
    return m_pCurrentTopicList && m_pCurrentTopicList->GetItem();
}

// @fnv 0x004d5c60
void TopicMenuController::IncrementMiscStat(int aiStatId)
{
    MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)aiStatId, 1);
}

// @fnv 0x0083e620
bool TopicMenuController::Initialize(MobileObject* speaker, TESTopic* requestedTopic)
{
    // Keep the greeting context together in the original stack-frame order.
    struct GreetingLocals
    {
        BSSimpleList<MenuTopic*>* topicList;
        TESQuest* quest;
        unsigned char padding0, padding1, padding2;
        bool dispositionFailure;
        TESTopicInfo* info;
        MenuTopic* menuTopic;
        TESTopic* topic;
    } locals;
    MenuTopicManager_ClearData();
    locals.topicList = new BSSimpleList<MenuTopic*>;
    m_kTopicListStack.AddHead(locals.topicList);
    m_pDialogueSpeaker = (TESObjectREFR*)speaker;
    m_bControllerFlag = false;
    m_iTopicIndex = 0;
    locals.topic = requestedTopic;
    if (!locals.topic)
        locals.topic = TESTopic::GetAudioBackendData((DIALOGUE_TYPE)0, 0);
    locals.menuTopic = 0;
    if (locals.topic)
    {
        locals.info = locals.topic->FindMatchingTopicInfo(locals.dispositionFailure, (MobileObject*)m_pDialogueSpeaker,
                                                          g_thePlayer);
        if (locals.info)
        {
            locals.quest = locals.topic->GetParentQuest(locals.info);
            locals.menuTopic =
                new MenuTopic(locals.quest, locals.topic, locals.info, (MobileObject*)m_pDialogueSpeaker, false);
            locals.menuTopic->FUN_0045cd60(2147483648.0f)->ImageSpaceModifierInstanceDOF_SetMaskConst();
            locals.menuTopic->FillResponseList();
            MenuTopicManager_GetCurrentTopicList()->AddTail(locals.menuTopic);
        }
    }
    if (locals.menuTopic)
    {
        locals.menuTopic->GetTopicInfo()->AddTopicList();
        locals.menuTopic->GetTopicInfo()->RunResultScript(false, (MobileObject*)m_pDialogueSpeaker);
    }
    else
        Warning((const char*)6, "No GREETING topic was found for %s. Selecting stock GREETING.",
                m_pDialogueSpeaker->GetFullName());
    SelectTopic(false);
    return locals.menuTopic && locals.menuTopic->GetTopicInfo() &&
           ((TESTopic*)locals.menuTopic->GetTopicInfo())->IsRemappedRumors();
}

// Initializes a MenuTopic from quest, topic, info and speaker, optionally substituting a refusal info and resolving owner quest/topic.
// @fnv 0x0083db00
MenuTopic::MenuTopic(TESQuest* quest, TESTopic* topic, TESTopicInfo* info, MobileObject* speaker,
                     bool substituteRefusal)
{
    // Selected and owning topic contexts can differ after refusal substitution.
    struct TopicLocals
    {
        TESTopicInfo* refusalInfo;
        TESTopic* refusalTopic;
        TESQuest* ownerQuest;
        TESTopic* ownerTopic;
        TESQuest* selectedQuest;
        TESTopic* selectedTopic;
    } locals;
    m_pCurrentResponseList = 0;
    pQuest = 0;
    pTopic = 0;
    pInfo = 0;
    m_pOriginalTopic = topic;
    if (topic->IsRemappedRumors())
    {
        m_bIsRemappedRumor = true;
        m_bFirstFlag = false;
    }
    else
        m_bIsRemappedRumor = false;
    m_bIsRefusal = false;
    m_bThirdFlag = false;
    locals.selectedQuest = quest;
    locals.selectedTopic = topic;
    if (topic && info)
    {
        m_bInfoHasBeenRead = !info->IsNew();
        pInfo = info;
        if (substituteRefusal && !info->IsRefusal())
        {
            locals.refusalTopic = TESTopic::GetAudioBackendData((DIALOGUE_TYPE)6, 12);
            locals.refusalInfo =
                locals.refusalTopic ? locals.refusalTopic->FindMatchingTopicInfo(speaker, g_thePlayer) : 0;
            if (locals.refusalInfo)
            {
                pInfo = locals.refusalInfo;
                locals.selectedTopic = locals.refusalTopic;
                locals.selectedQuest = locals.selectedTopic->GetParentQuest(locals.refusalInfo);
            }
            m_bIsRefusal = true;
        }
        else
            m_bIsRefusal = info->IsRefusal();
        if (((Actor*)g_thePlayer)->GetActorValue((ActorValue::Index)9) <= *g_011d0dc8.Int() &&
            topic->HasDummyPrompt())
            m_kPrompt.Set(topic->GetDummyPrompt());
        else if (info->HasPrompt())
            m_kPrompt.Set(info->GetPrompt());
        else
            m_kPrompt.Set(topic->GetFullName());
        m_kPrompt.Set(BSStringT_char_RemoveCurlyContent());
        if (!m_bIsRemappedRumor)
            m_bFirstFlag = pInfo->GetConversationData() && !pInfo->GetConversationData()->GetLinkToList()->IsEmpty();
        if (topic->IsPersuasion())
            m_bThirdFlag = true;
        locals.ownerQuest = pInfo->GetParentQuest();
        locals.ownerTopic = TESTopic::GetTopicFromInfo(pInfo);
        if (locals.selectedQuest != locals.ownerQuest || locals.selectedTopic != locals.ownerTopic)
            MenuTopic_FillResponseList_0083df80(locals.ownerQuest, locals.ownerTopic, pInfo, speaker);
        else
            MenuTopic_FillResponseList_0083df80(locals.selectedQuest, locals.selectedTopic, pInfo, speaker);
    }
    pTopic = locals.selectedTopic;
    pQuest = locals.selectedQuest;
}

// Initializes the object's two fields to zero.
// @fnv 0x0083e1a0
TopicMenuController::TopicMenuController()
{
    m_pCurrentTopicList = 0;
    m_pDialogueSpeaker = 0;
}

// @fnv 0x0083e590
TopicMenuController* TopicMenuController::GetInstance()
{
    if (!g_011ddde4)
        g_011ddde4 = new TopicMenuController();
    return g_011ddde4;
}

// @fnv 0x0083ec10
// src: COMMUNITY 0x0083ec10
bool TESTopicInfo::IsRunForRumors()
{
    return m_Data.flags & 0x40;
}

// @fnv 0x0083ebb0
void TopicMenuController::RunTopicResultScript()
{
    // Keep the topic and info locals in the original stack-frame order.
    struct TopicLocals
    {
        MenuTopic* topic;    // [ebp-0x8]
        TESTopicInfo* info;  // [ebp-0x4]
    } locals;
    locals.topic = GetSelectedTopic();
    locals.info = 0;
    if (locals.topic)
    {
        if (!locals.topic->GetTopicInfo()->IsRunForRumors())
            locals.info = locals.topic->GetTopicInfo();
    }
    if (locals.info)
        locals.info->RunResultScript(false, (MobileObject*)m_pDialogueSpeaker);
}

struct FUN_0083de40_shell : public TESTopicInfo
{
    bool TESTopicInfo_HasPrompt();
};

unsigned int __fastcall BSStringT_char_Length(void*);

// @fnv 0x0083de40
// src: XBOX_PDB 0x0083de40
bool FUN_0083de40_shell::TESTopicInfo_HasPrompt()
{
    return BSStringT_char_Length(reinterpret_cast<char*>(this) + 0x28) > 0;
}

struct FUN_0083de60_shell : public TESTopic
{
    bool TESTopic_IsPersuasion();
};

// Returns true when the form ID is 0xFD or 0x118.
// @fnv 0x0083de60
// src: COMMUNITY 0x0083de60
bool FUN_0083de60_shell::TESTopic_IsPersuasion()
{
    return GetFormID() == 0xFD || GetFormID() == 0x118;
}

struct FUN_0083e230_shell : public TopicMenuController
{
    void MenuTopicManager_ClearData();
};

bool __fastcall _ref_008256d0(void* pThis);
BSSimpleList<char const*>** __fastcall _ref_006815c0(void* pThis);
void __fastcall _ref_0063f7b0(void* pThis);

struct FUN_0083e2d0_helper
{
    void MenuTopicManager_ClearTopicList(void* pList, bool bDeleteGreeting);
};

// @fnv 0x0083e230
// src: XBOX_PDB 0x0083e230
void FUN_0083e230_shell::MenuTopicManager_ClearData()
{
    bool bdeletegreeting;
    BSSimpleList<char const*>* pCurrentElementNext;

    *(int*)((char*)this + 0xc) = 0;
    while (!_ref_008256d0((char*)this + 4))
    {
        pCurrentElementNext = *_ref_006815c0((char*)this + 4);
        _ref_0063f7b0((char*)this + 4);
        bdeletegreeting = _ref_008256d0((char*)this + 4);
        ((FUN_0083e2d0_helper*)this)->MenuTopicManager_ClearTopicList(pCurrentElementNext, bdeletegreeting);
        ((BSSimpleList<int>*)pCurrentElementNext)->RemoveAll();
        delete pCurrentElementNext;
    }
}

struct FUN_0083e430_shell : public TopicMenuController
{
    bool DialogMenu_SetClickedMenuItem(int);
};

// @fnv 0x0083e430
// src: COMMUNITY 0x0083e430
bool FUN_0083e430_shell::DialogMenu_SetClickedMenuItem(int aiIndex)
{
    int a = 0;
    BSSimpleList<MenuTopic*>* pMenuTopicEntry = MenuTopicManager_GetCurrentTopicList();
    if (pMenuTopicEntry)
    {
        pMenuTopicEntry = pMenuTopicEntry->GetNext();
    }
    while (pMenuTopicEntry && a < aiIndex)
    {
        pMenuTopicEntry = pMenuTopicEntry->GetNext();
        ++a;
    }
    if (pMenuTopicEntry)
    {
        m_pCurrentTopicList = pMenuTopicEntry;
    }
    return pMenuTopicEntry && m_pCurrentTopicList->GetItem();
}

namespace fnv_0083f260 {
struct FUN_0083f260_shell : public TopicMenuController
{
    void* MenuTopicManager_GetCurrentTopicList();
};

void** __fastcall _ref_006815c0(void* pThis);

// @fnv 0x0083f260
// src: XBOX_PDB 0x0083f260
void* FUN_0083f260_shell::MenuTopicManager_GetCurrentTopicList()
{
    return *_ref_006815c0((char*)this + 4);
}
}  // namespace fnv_0083f260

struct FUN_00965250_shell : public TESTopic
{
    void ImageSpaceModifierInstanceDOF_SetMaskConst(float);
};

// @fnv 0x00965250
// src: COMMUNITY 0x00965250
void FUN_00965250_shell::ImageSpaceModifierInstanceDOF_SetMaskConst(float afValue)
{
    *(float*)((char*)this + 0x28) = afValue;
}

namespace fnv_0083e2d0 {
struct TopicItem
{
    char pad[0x24];
    bool bKeep;
    ~TopicItem();
};
void __fastcall _ref_0063f7b0(void* pThis);
void** __fastcall _ref_006815c0(void* pThis);
bool __fastcall _ref_008256d0(void* pThis);
void* __fastcall _ref_00726070(void* pThis);
struct TopicHolder
{
    void* head;
    void MenuTopicManager_ClearTopicList(void* list, bool flag);
};
// @fnv 0x0083e2d0
// src: XBOX_PDB 0x0083e2d0
void TopicHolder::MenuTopicManager_ClearTopicList(void* list, bool flag)
{
    head = 0;
    void* node = list;
    if (!flag && node)
        node = _ref_00726070(node);
    while (node && !_ref_008256d0(node))
    {
        TopicItem* item = (TopicItem*)*_ref_006815c0(node);
        if (!item->bKeep)
            delete (TopicItem*)*_ref_006815c0(node);
        _ref_0063f7b0(node);
    }
}
}  // namespace fnv_0083e2d0

struct FUN_0083ec30_shell : public TopicMenuController
{
    void UpdateTopicList();
};

struct FUN_00464e30_shell
{
    BSSimpleList<TESTopic*>* GetSelfOffset6A8();
};
struct FUN_0083ec30_topic : MenuTopic
{
    bool IsChoice();
    TESTopic* GetAudioBackendData();
};
struct FUN_0083ec30_mgr : TopicMenuController
{
    void PopTopicList();
    void MenuTopicManager_ClearTopicList(BSSimpleList<MenuTopic*>*, bool);
};

// @fnv 0x0083ec30
void FUN_0083ec30_shell::UpdateTopicList()
{
    FUN_0083ec30_topic* pMenuTopicEntry = (FUN_0083ec30_topic*)GetSelectedTopic();
    if (pMenuTopicEntry && pMenuTopicEntry->GetTopicInfo())
        pMenuTopicEntry->GetTopicInfo()->AddTopicList();
    if (m_bControllerFlag && pMenuTopicEntry && !pMenuTopicEntry->IsChoice())
    {
        ((FUN_0083ec30_mgr*)this)->PopTopicList();
        m_bControllerFlag = false;
    }
    else if (pMenuTopicEntry && !pMenuTopicEntry->m_bIsRemappedRumor)
    {
        bool bIsChoice = pMenuTopicEntry->IsChoice();
        BSSimpleList<TESTopic*>* pList = bIsChoice
                                             ? pMenuTopicEntry->GetTopicInfo()->GetConversationData()->GetLinkToList()
                                             : ((FUN_00464e30_shell*)g_thePlayer)->GetSelfOffset6A8();
        TESTopic* pTopic = pMenuTopicEntry->GetAudioBackendData();
        if (pList)
        {
            ((FUN_0083ec30_mgr*)this)->MenuTopicManager_ClearTopicList(MenuTopicManager_GetCurrentTopicList(), false);
            BuildTopicList(pList, false, bIsChoice, pTopic);
        }
        if (m_bControllerFlag)
            m_bControllerFlag = false;
    }
}

float __fastcall TESTopic_GetPriority_GetUnk28(TESTopic*);
struct FUN_0083f110_topic : MenuTopic
{
    TESTopic* GetAudioBackendData();
};

// Compares two topics by the value returned from FUN_00526ae0, returning -1, 1 or 0 for descending order.
// @fnv 0x0083f110
// src: GUESS 0x0083f110 (confidence: high)
int TESTopic_GetPriority_GetUnk28_CompareTopicPrioritiesDescending(FUN_0083f110_topic* apTopicA, FUN_0083f110_topic* apTopicB)
{
    return TESTopic_GetPriority_GetUnk28(apTopicA->GetAudioBackendData()) > TESTopic_GetPriority_GetUnk28(apTopicB->GetAudioBackendData())
               ? -1
               : (TESTopic_GetPriority_GetUnk28(apTopicA->GetAudioBackendData()) < TESTopic_GetPriority_GetUnk28(apTopicB->GetAudioBackendData()) ? 1
                                                                                                                : 0);
}

struct FUN_0083f1d0_t : TopicMenuController
{
    void MenuTopicManager_ClearTopicList(BSSimpleList<MenuTopic*>*, bool);
    BSSimpleList<MenuTopic*>* PopTopicList();
};

// @fnv 0x0083f1d0
BSSimpleList<MenuTopic*>* FUN_0083f1d0_t::PopTopicList()
{
    if (m_kTopicListStack.GetNext())
    {
        BSSimpleList<MenuTopic*>* pCurrentElementNext = m_kTopicListStack.GetItem();
        if (pCurrentElementNext)
        {
            m_kTopicListStack.RemoveHead();
            MenuTopicManager_ClearTopicList(pCurrentElementNext, false);
            pCurrentElementNext->RemoveAll();
            delete pCurrentElementNext;
        }
    }
    return m_kTopicListStack.GetItem();
}

// The 0x004fd3e0 accessor returns this change record: form ID +0, type +4, flags +5, version +9.
// Retained locally until include/ supplies SaveFormHeader.
struct SaveFormHeader
{
    unsigned int formID;
    unsigned char kind;
    unsigned char flagsLow, flagsByte1, flagsByte2, flagsHigh;
    unsigned char version;
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
// Exe 0x0083f280: unit-local MenutopicInterfaceView view used by this matched implementation.
struct MenutopicInterfaceView
{
    static void PrintDebugMessage(const char*, ...);
};
unsigned int BSStringLength(const char*);
TESForm* GetFormByID(unsigned int);
struct FUN_0083f280_t : MenuTopic
{
    unsigned short MenuTopic_GetSaveSize();
};

// Computes the save size of a MenuTopic by summing field sizes and optionally logs the size and form header details.
// @fnv 0x0083f280
// src: COMMUNITY 0x0083f280
unsigned short FUN_0083f280_t::MenuTopic_GetSaveSize()
{
    unsigned short isize = 0;
    {
        unsigned short itempStartSize = isize;
        if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
        {
            isize += 4;
            isize += 2;
        }
        const char* ptext = (const BSStringT<char>&)m_kPrompt;
        isize += 1;
        isize += BSStringLength(ptext);
        isize += 1;
        isize += 1;
        isize += 1;
        isize += 4;
        isize += 4;
        isize += 4;
        if (*g_011de4e8.Bool())
        {
            SaveFormHeader* pheader = (SaveFormHeader*)g_TESSaveLoadGame->FUN_004fd3e0();
            if (pheader)
            {
                TESForm* pform = GetFormByID(pheader->formID);
                MenutopicInterfaceView::PrintDebugMessage(
                    "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                    isize - itempStartSize, pheader->formID, pform->GetName(), *(unsigned int*)((char*)pheader + 5),
                    729, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp");
            }
            else
            {
                MenutopicInterfaceView::PrintDebugMessage(
                    "GetSaveSize(): %-5i ending at line %i in file %s", isize - itempStartSize, 729,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp");
            }
        }
    }
    return isize;
}

struct ListX
{
    ~ListX();
};
struct FUN_0083e1d0
{
    int _00;
    ListX _04;
    ~FUN_0083e1d0();
};
// @fnv 0x0083e1d0
FUN_0083e1d0::~FUN_0083e1d0()
{
    ((TopicMenuController*)this)->MenuTopicManager_ClearData();
}

// If the global pointer g_011ddde4 is non-null, deletes it and resets it to null.
// @fnv 0x0083e510
// src: XBOX_PDB 0x0083e510
void MenuTopicManager_Destroy()
{
    if (g_011ddde4)
    {
        delete g_011ddde4;
        g_011ddde4 = 0;
    }
}

void _Deallocate(void*);
struct Struct_0083e560
{
    void FUN_0083e1d0();
    void* FUN_0083e560(unsigned int);
};
// Calls FUN_0083e1d0, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x0083e560
void* Struct_0083e560::FUN_0083e560(unsigned int flags)
{
    FUN_0083e1d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0083f0d0_shell
{
    char _pad[0x25];
    char f25;
    int TESTopic_GetDummyNodeState();
};
// Returns 1 if bit 0x10 of f25 is set, otherwise 2 plus 1 when bit 0x20 is set.
// @fnv 0x0083f0d0
// src: COMMUNITY 0x0083f0d0
int FUN_0083f0d0_shell::TESTopic_GetDummyNodeState()
{
    return (f25 & 0x10) ? 1 : (((f25 & 0x20) != 0) + 2);
}

struct G2
{
    void AddHead(int*&);
};
struct Owner83F1A0
{
    int _pad;
    G2 _list;
    void AddHeadIfNotNull(int*);
};
// @fnv 0x0083f1a0
void Owner83F1A0::AddHeadIfNotNull(int* a1)
{
    if (a1)
    {
        _list.AddHead(a1);
    }
}

// Shared Actor does not yet declare this nonvirtual method. Its only argument is in ECX.
bool __fastcall HasNoRumors(Actor* actor);

struct FUN_00619df0_shell
{
    bool TESTopic_IsRemappedRumors();
    TESTopicInfo* FUN_0061a790(bool* apbFlag, TESObjectREFR* apSpeaker, PlayerCharacter* apPlayer, int a4,
                               TESTopic* apTopic, int a6);
    TESQuest* FindQuestForTopicInfo(TESTopicInfo* apInfo);
};

struct FUN_0042df90_shell
{
    MenuTopic* ExtraDataList_GetInfoGeneralTopic(TESObjectREFR* apRef);
    void ExtraDataList_SetInfoGeneralTopic(MenuTopic* apTopic);
};
FUN_0042df90_shell* __fastcall BSFile_GetDevice(TESObjectREFR* apRef);

struct FUN_0083e0c0_shell
{
    bool HasCur();
};

struct FUN_00619b20_shell
{
    bool TESTopicInfo_IsSayOnce();
};

struct FUN_009611e0_shell
{
    FUN_00619b20_shell* NiAVObject_GetParent();
};

struct FUN_005f65d0_list
{
    bool BSSimpleList_TESLevSpell_IsInList(MenuTopic*& arpTopic);
    void SortItems(int (*apCompare)(FUN_0083f110_topic*, FUN_0083f110_topic*));
};

struct FUN_00425ff0
{
    ~FUN_00425ff0();
};

struct FUN_0083ed50_ref
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12(unsigned int auiFlags);
};

struct FUN_0083ed50_shell : public TopicMenuController
{
    void BuildMenuTopics(BSSimpleList<TESTopic*>* apList, bool abFlag, bool abNoSort, TESTopic* apTopic);
};

// Iterates a TESTopic list, filters by flag and type against an actor value, builds MenuTopic entries, adds new ones to the list, and optionally sorts it.
// @fnv 0x0083ed50
void FUN_0083ed50_shell::BuildMenuTopics(BSSimpleList<TESTopic*>* apList, bool abFlag, bool abNoSort, TESTopic* apTopic)
{
    bool bStateChanged = false;
    Actor* pActorCur = dynamic_cast<Actor*>(m_pDialogueSpeaker);
    while (apList && apList->GetItem())
    {
        TESTopic* pTopic = apList->GetItem();
        apList = apList->GetNext();
        if (abFlag && !((FUN_0083de60_shell*)pTopic)->TESTopic_IsPersuasion())
            continue;
        if (!abFlag && ((FUN_0083de60_shell*)pTopic)->TESTopic_IsPersuasion())
            continue;

        int iTypeValue = ((FUN_0083f0d0_shell*)pTopic)->TESTopic_GetDummyNodeState();
        if (((Actor*)g_thePlayer)->GetActorValue((ActorValue::Index)9) <= *g_011d0dc8.Int())
        {
            if (iTypeValue == 3)
                continue;
        }
        else
        {
            if (iTypeValue == 1)
                continue;
        }

        if (((FUN_00619df0_shell*)pTopic)->TESTopic_IsRemappedRumors() && !HasNoRumors(pActorCur))
        {
            MenuTopic* pExisting = 0;
            pExisting = BSFile_GetDevice(m_pDialogueSpeaker)->ExtraDataList_GetInfoGeneralTopic(m_pDialogueSpeaker);
            if (pExisting && !bStateChanged)
            {
                if (((FUN_0083e0c0_shell*)pExisting)->HasCur() && !bStateChanged &&
                    !((FUN_005f65d0_list*)MenuTopicManager_GetCurrentTopicList())->BSSimpleList_TESLevSpell_IsInList(pExisting))
                    MenuTopicManager_GetCurrentTopicList()->AddTail(pExisting);
                bStateChanged = true;
            }
        }

        bool bChoice = false;
        TESTopicInfo* pInfo =
            ((FUN_00619df0_shell*)pTopic)->FUN_0061a790(&bChoice, m_pDialogueSpeaker, g_thePlayer, 0, apTopic, 0);
        if (pInfo)
        {
            TESQuest* pQuest4 = ((FUN_00619df0_shell*)pTopic)->FindQuestForTopicInfo(pInfo);
            bool bSave = false;
            bool bCreate5 = true;
            if (((FUN_00619df0_shell*)pTopic)->TESTopic_IsRemappedRumors())
            {
                if (!bStateChanged && !HasNoRumors(pActorCur))
                    bSave = true;
                else
                    bCreate5 = false;
            }
            MenuTopic* pMenuTopic = 0;
            if (bCreate5)
                pMenuTopic = new MenuTopic(pQuest4, pTopic, pInfo, (MobileObject*)m_pDialogueSpeaker, bChoice);
            if (bCreate5 && ((FUN_0083e0c0_shell*)pMenuTopic)->HasCur() &&
                !((FUN_005f65d0_list*)MenuTopicManager_GetCurrentTopicList())->BSSimpleList_TESLevSpell_IsInList(pMenuTopic))
            {
                MenuTopicManager_GetCurrentTopicList()->AddTail(pMenuTopic);
            }
            else if (pMenuTopic)
            {
                delete (FUN_00425ff0*)pMenuTopic;
                pMenuTopic = 0;
            }
            if (bSave && pMenuTopic && !((FUN_009611e0_shell*)pMenuTopic)->NiAVObject_GetParent()->TESTopicInfo_IsSayOnce())
            {
                BSFile_GetDevice(m_pDialogueSpeaker)->ExtraDataList_SetInfoGeneralTopic(pMenuTopic);
                ((FUN_0083ed50_ref*)m_pDialogueSpeaker)->v12(0x80000000);
            }
        }
    }
    if (!abNoSort)
        ((FUN_005f65d0_list*)MenuTopicManager_GetCurrentTopicList())->SortItems(TESTopic_GetPriority_GetUnk28_CompareTopicPrioritiesDescending);
}

struct TopicLoader
{
    bool IsLoading();
    void Read(void*, unsigned int);
    void ReadID(unsigned int*, unsigned int);
    SaveFormHeader* Header();
    unsigned int Position();
    unsigned char Version();
};

TESForm* GetFormByID(unsigned int);
void FNV_Warning(const char*, ...);
void* memset(void*, int, unsigned int);
struct TopicLoad : MenuTopic
{
    void LoadFromSave(void*);
};
// @fnv 0x0083f680
void TopicLoad::LoadFromSave(void*)
{
    unsigned int uiChunkType, infoID, topicID;
    {
        unsigned short start = 0;
        unsigned int chunkSize = 0;
        if (((TopicLoader*)g_TESSaveLoadGame)->IsLoading())
        {
            unsigned int tag;
            ((TopicLoader*)g_TESSaveLoadGame)->Read(&tag, 4);
            if (tag != 0x424c4f4b)
            {
                SaveFormHeader* header = ((TopicLoader*)g_TESSaveLoadGame)->Header();
                if (header)
                {
                    TESForm* form = GetFormByID(header->formID);
                    FNV_Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x305,
                        header->formID, form->GetName(), header->version, *(unsigned int*)&header->flagsLow);
                }
                else
                    FNV_Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x305,
                        ((TopicLoader*)g_TESSaveLoadGame)->Version());
            }
            chunkSize = ((TopicLoader*)g_TESSaveLoadGame)->Position();
            ((TopicLoader*)g_TESSaveLoadGame)->Read(&start, 2);
        }
        char text[260];
        memset(text, 0, 260);
        unsigned char length;
        ((TopicLoader*)g_TESSaveLoadGame)->Read(&length, 1);
        if (length)
        {
            ((TopicLoader*)g_TESSaveLoadGame)->Read(text, length);
            m_kPrompt.Set(text, 0);
        }
        ((TopicLoader*)g_TESSaveLoadGame)->Read(&m_bFirstFlag, 1);
        ((TopicLoader*)g_TESSaveLoadGame)->Read(&m_bIsRemappedRumor, 1);
        ((TopicLoader*)g_TESSaveLoadGame)->Read(&m_bInfoHasBeenRead, 1);
        ((TopicLoader*)g_TESSaveLoadGame)->ReadID(&uiChunkType, 4);
        pQuest = dynamic_cast<TESQuest*>(GetFormByID(uiChunkType));
        ((TopicLoader*)g_TESSaveLoadGame)->ReadID(&infoID, 4);
        pTopic = dynamic_cast<TESTopic*>(GetFormByID(infoID));
        ((TopicLoader*)g_TESSaveLoadGame)->ReadID(&topicID, 4);
        pInfo = dynamic_cast<TESTopicInfo*>(GetFormByID(topicID));
        if (((TopicLoader*)g_TESSaveLoadGame)->IsLoading())
        {
            unsigned int end = ((TopicLoader*)g_TESSaveLoadGame)->Position();
            SaveFormHeader* current = ((TopicLoader*)g_TESSaveLoadGame)->Header();
            if (current)
            {
                TESForm* form2 = GetFormByID(current->formID);
                if (end > chunkSize + start)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        end - (chunkSize + start),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x329,
                        current->formID, form2->GetName(), current->version, *(unsigned int*)&current->flagsLow);
                else if (end < chunkSize + start)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        chunkSize + start - end,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x329,
                        current->formID, form2->GetName(), current->version, *(unsigned int*)&current->flagsLow);
            }
            else
            {
                if (end > chunkSize + start)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        end - (chunkSize + start),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x329,
                        ((TopicLoader*)g_TESSaveLoadGame)->Version());
                else if (end < chunkSize + start)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        chunkSize + start - end,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x329,
                        ((TopicLoader*)g_TESSaveLoadGame)->Version());
            }
        }
    }
}


extern "C" char DAT_0107dd28;

class SpeakerVt
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual bool v63();
    virtual bool v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual int v209(void* a, int b);
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280(void* a, float b);
    void LoadRecord(void* p);
};

struct InfoShell
{
    bool IsChallengeFlagSet();
    void MarkAsRefusal();
    bool TESTopicInfo_IsSayOnce();
    bool IsSayOnceADay();
    int FUN_0061f2b0();
    int GetType();
};

struct TopicShell
{
    TESTopicInfo* FUN_0061a790(char* a, void* b, void* c, int d, int e, int f);
    TESQuest* FindQuestForTopicInfo(TESTopicInfo* p);
};

struct ProcShell
{
    int GetProcessLevel();
};

// Exe 0x0083e850: unit-local MenuList view; declarations and layout are preserved.


struct ListShell
{
    void RemoveMatchingItem();
};

class FloatSetting
{
  public:
    float* Float();
};
extern FloatSetting g_011d0a24;


int ExperiencePoints_GetExperiencePoints(int a, int b);
unsigned int DialogueRandom();
int Warning_005b5e40(int a, const char* b);
int FUN_004d5c60(int a);
TESTopic* GetTopicSubTypeName(int a, int b);
float GamePlayFormulas_GetSpeechFailPenalty(int a);
int ComputeWeightedValue(float a, float b, int c);

class Mgr
{
  public:
    void* m_pCurrentTopicList;
    void* m_kTopicListStack[2];
    SpeakerVt* m_pDialogueSpeaker;
    bool m_bControllerFlag;
    char pad[3];
    int m_iTopicIndex;
    MenuTopic* FUN_0083e4f0();
    void FUN_0083e370(int a);
    void AddHeadIfNotNull(void* p);
    ListShell* MenuTopicManager_GetCurrentTopicList(MenuTopic** p);
    bool CheckTopicInfoChance(MenuTopic* pTopic);
};

// @fnv 0x0083e850
bool Mgr::CheckTopicInfoChance(MenuTopic* pTopic)
{
    if (pTopic && ((InfoShell*)pTopic->GetTopicInfo())->IsChallengeFlagSet())
    {
        int iChance2 = ComputeWeightedValue(((Actor*)g_thePlayer)->GetActorValueFloatByIndex(0x2b),
                                            m_pDialogueSpeaker->v64() ? (float)m_pDialogueSpeaker->v209(g_thePlayer, 0)
                                                                      : *g_011d0a24.Float(),
                                            ((InfoShell*)pTopic->GetTopicInfo())->FUN_0061f2b0());
        int iRoll5 = DialogueRandom() % 100;
        if (iRoll5 >= iChance2)
        {
            m_bControllerFlag = true;
            FUN_004d5c60(0x1f);
            char _flag;
            TESTopic* pT2 = GetTopicSubTypeName(0, 0xb);
            TESTopicInfo* pInfo = ((TopicShell*)pT2)
                                      ->FUN_0061a790(&_flag, m_pDialogueSpeaker, g_thePlayer, 0,
                                                     ((ProcShell*)pTopic)->GetProcessLevel(), 0);
            if (!pInfo)
            {
                Warning_005b5e40(6, (const char*)&DAT_0107dd28);
            }
            else
            {
                BSSimpleList<MenuTopic*>* pList = new BSSimpleList<MenuTopic*>;
                MenuTopic* pNew = new MenuTopic(((TopicShell*)pT2)->FindQuestForTopicInfo(pInfo), pT2, pInfo,
                                                (MobileObject*)m_pDialogueSpeaker, false);
                pNew->FillResponseList();
                ((InfoShell*)pTopic->GetTopicInfo())->MarkAsRefusal();
                if (((InfoShell*)pTopic->GetTopicInfo())->TESTopicInfo_IsSayOnce() ||
                    ((InfoShell*)pTopic->GetTopicInfo())->IsSayOnceADay())
                {
                    if (((InfoShell*)pTopic->GetTopicInfo())->IsSayOnceADay() && m_pDialogueSpeaker->v63())
                    {
                        SpeakerVt* pSpk7 = m_pDialogueSpeaker;
                        pSpk7->LoadRecord(pTopic->GetTopicInfo());
                    }
                    MenuTopicManager_GetCurrentTopicList(&pTopic)->RemoveMatchingItem();
                }
                ((BSSimpleList<MenuTopic*>*)pList)->AddTail(FUN_0083e4f0());
                ((BSSimpleList<MenuTopic*>*)pList)->AddTail(pNew);
                AddHeadIfNotNull(pList);
                FUN_0083e370(1);
            }
            if (m_pDialogueSpeaker->v64())
                m_pDialogueSpeaker->v280(g_thePlayer, GamePlayFormulas_GetSpeechFailPenalty(iChance2));
        }
        else
        {
            m_iTopicIndex = ExperiencePoints_GetExperiencePoints(4, ((InfoShell*)pTopic->GetTopicInfo())->GetType() - 1);
        }
    }
    return m_bControllerFlag;
}

namespace fnv_0083f3e0 {
template <class T> unsigned int BSStringLength(const T* pString);

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct GlobalObject_0045cf30
{
    bool* FUN_00408d60();
};
extern GlobalObject_0045cf30 g_011de4e8;

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormId);
void __cdecl ProgramFlow(const char* pcFormat, ...);
void __cdecl Warning_005b5e40(const char* pcFormat, ...);

}  // namespace fnv_0083f3e0

// Writes a BLOK record for this topic to the save stream: text length and string, three bytes, quest/topic/info form IDs, and patches the block size.
// @fnv 0x0083f3e0
void MenuTopic::SaveTopic()
{
    using namespace fnv_0083f3e0;
    unsigned short usLen = 0;
    char* pcSizeLoc = 0;
    char* pcStart = (char*)fnv_0083f3e0::g_TESSaveLoadGame->FUN_00825c00();
    if (*fnv_0083f3e0::g_011de4e8.FUN_00408d60())
        pcStart = (char*)fnv_0083f3e0::g_TESSaveLoadGame->FUN_00825c00();
    if (fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiTag = 'BLOK';
        fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&uiTag, 4);
        pcSizeLoc = (char*)fnv_0083f3e0::g_TESSaveLoadGame->FUN_00825c00();
        fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&usLen, 2);
    }
    const char* pcTopic = m_kPrompt.String();
    unsigned char ucTextLen = fnv_0083f3e0::BSStringLength(pcTopic);
    fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&ucTextLen, 1);
    if (ucTextLen)
        fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((void*)pcTopic, ucTextLen);
    fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_bFirstFlag, 1);
    fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_bIsRemappedRumor, 1);
    fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_bInfoHasBeenRead, 1);
    unsigned int uiQuestID = 0;
    if (pQuest)
        uiQuestID = pQuest->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID((void*)&uiQuestID, 4);
    unsigned int uiID2 = 0;
    if (pTopic)
        uiID2 = pTopic->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID((void*)&uiID2, 4);
    unsigned int uiResp = 0;
    if (pInfo)
        uiResp = pInfo->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID((void*)&uiResp, 4);
    if (*fnv_0083f3e0::g_011de4e8.FUN_00408d60())
    {
        char* pcEnd = (char*)fnv_0083f3e0::g_TESSaveLoadGame->FUN_00825c00();
        SaveFormHeader* pkHeader = (SaveFormHeader*)fnv_0083f3e0::g_TESSaveLoadGame->FUN_004fd3e0();
        if (pkHeader)
        {
            TESForm* pkForm = TESForm_GetFormByNumericID(pkHeader->formID);
            ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         pcEnd - pcStart, pkHeader->formID, pkForm->GetName(), *(unsigned int*)&pkHeader->flagsLow,
                         0x2ff, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp");
        }
        else
            ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", pcEnd - pcStart, 0x2ff,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp");
    }
    if (fnv_0083f3e0::g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        char* pcNow = (char*)fnv_0083f3e0::g_TESSaveLoadGame->FUN_00825c00();
        char* pcMark = pcSizeLoc;
        if (pcNow > pcMark + 0xffff)
            Warning_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x2ff);
        *(unsigned short*)pcSizeLoc = pcNow - pcMark;
    }
}


typedef char _sizecheck_ResponseListWrapper[sizeof(TESResponseList) == 4 ? 1 : -1];
struct FUN_0083df80_shell : public MenuTopic
{
    void MenuTopic_FillResponseList_0083df80(TESObjectREFR*);
};

struct FUN_0061e760_shell
{
    TESResponseList* FUN_0061e760(TESResponseList*);
};
struct TESIdleForm;
class DialogueResponse
{
  public:
    DialogueResponse(TESQuest*, TESTopic*, TESTopicInfo*, TESObjectREFR*, TESResponse*);
    BSStringT<char> m_kResponseText;
    unsigned int eEmotion;
    unsigned int m_uiEmotionValue;
    BSStringT<char> m_kResponseNotes;
    TESIdleForm* m_pFirstIdleForm;
    TESIdleForm* m_pSecondIdleForm;
    TESTopic* pTopic;
    TESTopicInfo* pInfo;
    TESQuest* pQuest;
};
struct ResponseFillOwner : MenuTopic
{
    void MenuTopic_FillResponseList_0083df80(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker);
};

// Iterates the response list obtained from pInfo and appends eligible DialogueResponse entries to m_kResponseList.
// @fnv 0x0083df80
// src: XBOX_PDB 0x0083df80
void ResponseFillOwner::MenuTopic_FillResponseList_0083df80(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo,
                                     TESObjectREFR* apSpeaker)
{
    TESResponseList lResponseList;
    int i;
    TESResponse* presponse;

    ((FUN_0061e760_shell*)pInfo)->FUN_0061e760(&lResponseList);
    presponse = (TESResponse*)(unsigned int)lResponseList;
    i = 0;
    while (presponse)
    {
        if (presponse->GetLength() && (!m_bIsRemappedRumor || i == 0))
        {
            ::DialogueResponse* pMenuResponse = reinterpret_cast< ::DialogueResponse*>(
                new DialogueResponse(apQuest, apTopic, apInfo, apSpeaker, presponse));
            m_kResponseList.AddTail(pMenuResponse);
            i++;
        }
        presponse = presponse->GetNext();
    }
}
