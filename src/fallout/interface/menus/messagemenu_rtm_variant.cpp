// src/fallout/interface/menus/messagemenu_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/interface/menus/messagemenu.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "MessageMenu.h"
#include "../../../../include/MessageHandler.h"
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/TESFullName.h"
#include "../../../../include/Script.h"
#include "../../../../include/TESObjectREFR.h"
static const int kGetClassValue = 1001;

// Exe 0x007aa5c0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct MessagemenuOffset08View
{
    unsigned int GetFlags();
};
struct MessageQueueEntryView
{
    BSStringT<char> m_kMessageText;
    char* m_kTitle;
    BSStringT<char> m_kPrimaryButtonText;
    BSStringT<char> m_kTertiaryButtonText;
    char m_cButtonCount;
    BSStringT<char> m_kSecondaryButtonText;
    void(__cdecl* aCallback)();
    unsigned int m_uiMessageFlags;
};
struct MessageQueueComparisonArray
{
    MessageQueueEntryView** FUN_00877a30(int);
};
struct GlobalObject_00869f00
{
    void Remove(unsigned int, bool);
};
struct GlobalObject_007ab590;
extern GlobalObject_007ab590 g_011da53c;
extern unsigned int DAT_011da4f4;
struct FUN_007aa500
{
    ~FUN_007aa500();
};
unsigned int __cdecl FUN_007a92a0();
void __cdecl MessageHandler_SetYesToAll(bool);

// @fnv 0x007aa5c0
// src: COMMUNITY 0x007aa5c0
void MessageMenu_ProcessYesToAll()
{
    if (FUN_007a92a0())
    {
        unsigned int uiID = ((MessageQueueEntryView*)FUN_007a92a0())->m_uiMessageFlags;
        MessageHandler::pHandler->BSCoreMessage_DisableContextMessages(uiID);
        MessageHandler_SetYesToAll(true);
        for (unsigned int i = DAT_011da4f4; i < ((MessagemenuOffset08View*)&g_011da53c)->GetFlags(); i++)
        {
            if ((*((MessageQueueComparisonArray*)&g_011da53c)->FUN_00877a30(i))->m_uiMessageFlags == uiID)
            {
                FUN_007aa500* pEntry = (FUN_007aa500*)((BSSimpleArray<unsigned int, 1024>*)&g_011da53c)->GetAt(static_cast<int>(i));
                delete pEntry;
                ((GlobalObject_00869f00*)&g_011da53c)->Remove(i--, true);
            }
        }
    }
}

namespace fnv_007aae70 {
// Exe 0x007aae70: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct MessagemenuOffset08View
{
    unsigned int GetFlags();
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct GlobalObject_007ab610;
struct PC7d;
extern GlobalObject_007ab610 g_011da524;
extern PC7d* g_thePlayer;
char __cdecl FUN_00703fa0();
int __fastcall FUN_00778930(const TESObjectREFR*);

struct PerkActivationEntry
{
    unsigned int uiButton;
    Script* pScript;
    TESObjectREFR* pRef;
};

// @fnv 0x007aae70
// src: GUESS 0x007aae70 (confidence: low)
void BSSimpleArray_UpdateState_007aae70()
{
    unsigned int ibuttonClicked;
    int icount;
    ibuttonClicked = FUN_00703fa0();
    if (ibuttonClicked != ((MessagemenuOffset08View*)&g_011da524)->GetFlags() - 1)
    {
        ((PerkActivationEntry*)((BSSimpleArray<unsigned int, 1024>*)&g_011da524)->GetAt(static_cast<int>(ibuttonClicked)))
            ->pScript->Run(
                ((PerkActivationEntry*)((BSSimpleArray<unsigned int, 1024>*)&g_011da524)->GetAt(static_cast<int>(ibuttonClicked)))->pRef,
                (ScriptLocals*)0, (TESObjectREFR*)0, false);
    }
    else
    {
        icount = FUN_00778930(
            ((PerkActivationEntry*)((BSSimpleArray<unsigned int, 1024>*)&g_011da524)->GetAt(static_cast<int>(ibuttonClicked)))->pRef);
        ((PerkActivationEntry*)((BSSimpleArray<unsigned int, 1024>*)&g_011da524)
                                  ->GetAt(static_cast<int>(ibuttonClicked)))
            ->pRef->Activate((TESObjectREFR*)g_thePlayer, false, (TESBoundObject*)0, icount);
    }
    ((GlobalObject_00869f00*)&g_011da524)->Clear(true);
}
}  // namespace fnv_007aae70
