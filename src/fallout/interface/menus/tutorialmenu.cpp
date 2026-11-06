#include "../../../../include/InterfaceManager.h"

// src/fallout/interface/menus/tutorialmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/tutorialmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BGSListForm.h"
#include "../../../../include/BGSMessage.h"
// InterfaceH_tutorialmenu: local type (was include/InterfaceH.h, which had no evidence of one real class); its methods are 0x00702360 Interface::IsInMenuMode, 0x00702450 Interface::IsTopMenuID, 0x00703860 HUDMainMenu::HandleHealthbarForCrosshairActor_, 0x00705e00 Interface::CreateLoadingMenu
class TESForm;
class TESObjectREFR;

class InterfaceH_tutorialmenu
{
public:
    static bool __cdecl GetSelectedTargetIndex(int);
    static void SetQuestTarget(TESForm*, bool);
    static void SetLookAtReference(TESObjectREFR*);
    static double GetFourthInterfaceFloat();
    static double GetThirdInterfaceFloat();
    static bool IsSaveLoadActive();
};
#include "../../../../include/Menu.h"
#include "../../../../include/Setting.h"
#include "../../../../include/StrMem.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/Tile.h"
#include "../../../../include/TileMenu.h"
#include "../../../../include/TutorialMenu.h"

// @fnv 0x007e8e20
void TutorialMenu::FUN_007e8e20()
{
    ShowPageByIndex(static_cast<int>(uiCurrentPage) + 1);
}

// @fnv 0x007e8e60
bool TutorialMenu::FUN_007e8e60(int aiButton, float afValue)
{
    bool bhandled = false;
    return bhandled;
}

// @fnv 0x007e8e40
void TutorialMenu::DecrementAndDispatch()
{
    ShowPageByIndex(static_cast<int>(uiCurrentPage) - 1);
}


struct FORenderedMenu;
FORenderedMenu* __cdecl FUN_00707ad0();
void __cdecl HandleBackAction();
extern Menu* DAT_011db088;

// @fnv 0x007e8d60
void FUN_007e8d60()
{
    if (DAT_011db088)
    {
        DAT_011db088->FUN_00726070()->Set(0x1772, 1);
        if (FUN_00707ad0())
            DAT_011db088->FUN_00a1d9e0();
        else
            DAT_011db088->LoadMenuData();
        HandleBackAction();
    }
}


void* __cdecl FUN_004b7210();
void __cdecl FUN_007e8d60();
// @fnv 0x007e8e80
bool TutorialMenu::HandleGamepadButton(int aiButton, float afValue)
{
    if (InterfaceH_tutorialmenu::GetSelectedTargetIndex(GetClass()) && aiButton == 10)
    {
        FUN_004b7210();
        InterfaceManager::SendGamepadButton(10);
        FUN_007e8d60();
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x007e9010
void TutorialMenu::FUN_007e9010()
{
    m_pTiles[2]->Set(0xFAF, 0 < uiCurrentPage);
    m_pTiles[1]->Set(0xFAF, uiCurrentPage + 1 < uiPageCount);
}

// Resolves apTarget from the tile array at offset 0x28 when null and aiID is 0-7, then dispatches on aiID to one of three handlers.
// @fnv 0x007e8db0
void TutorialMenu::FUN_007e8db0(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 8)
        apTarget = m_pTiles[aiID];
    switch (aiID)
    {
    case 1:
        FUN_007e8e20();
        break;
    case 2:
        DecrementAndDispatch();
        break;
    case 3:
        FUN_007e8d60();
        break;
    }
}

struct MenuTileField
{
    void __thiscall FUN_00a01350(unsigned int property, const char* text, int forceUpdate);
    void __thiscall FUN_00700320(unsigned int property, int matched);
    void __thiscall FUN_00a012d0(void* value, float fade, int flags);
};
extern char str_010702d8[];
extern "C" void* __cdecl FUN_00a00940(const char* descriptor, int index);
// @fnv 0x007e9060
void TutorialMenu::ApplyRecordToTiles(BGSMessage* record)
{
    const char* description;
    if (!record)
        return;
    if (reinterpret_cast<MenuTileField*>(m_pTiles[4]) != 0)
    {
        reinterpret_cast<MenuTileField*>(m_pTiles[4])->FUN_00a01350(0xFC4, record->GetFullName(), 1);
    }
    if (reinterpret_cast<MenuTileField*>(m_pTiles[0]) != 0)
    {
        // Avoid the null-adjusting base conversion emitted by the original compiler.
        description = reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(record) + sizeof(TESForm) + sizeof(TESFullName))
                          ->GetDescription(0, static_cast<CHUNK_ID>(0x43534544));
        if (description != 0)
        {
            reinterpret_cast<MenuTileField*>(m_pTiles[0])->FUN_00700320(0xFBE, description[0] == '<');
            reinterpret_cast<MenuTileField*>(m_pTiles[0])->FUN_00a01350(0xFC4, description, 1);
        }
    }
    if (reinterpret_cast<MenuTileField*>(m_pTiles[6]) != 0)
    {
        reinterpret_cast<MenuTileField*>(m_pTiles[6])->FUN_00a012d0(FUN_00a00940(str_010702d8, -1), 0.0f, 0);
    }
}

int __cdecl FUN_00406f60(StrMem* apStr, const char* apFmt, ...);
void __cdecl FNV_Warning(unsigned int aeType, const char* apFmt, ...);

struct HelpListNode
{
    TESForm** Item();
    HelpListNode* Next();
};

// Sets the current help page index, updates the page counter tile, walks the page list to the requested page, shows it and refreshes the menu.
// @fnv 0x007e8ed0
void TutorialMenu::ShowPageByIndex(unsigned int auiPage)
{
    if (auiPage < uiPageCount)
    {
        StrMem kText;
        uiCurrentPage = auiPage;
        FUN_00406f60(&kText, "%d/%d", auiPage + 1, uiPageCount);
        m_pTiles[5]->Set(0xfc4, kText, true);
        HelpListNode* pPageNode = pPages;
        while (pPageNode && auiPage--)
        {
            pPageNode = pPageNode->Next();
        }
        if (!pPageNode)
        {
            FNV_Warning(0x12, "End of Help Manual reached while searching for page %d in help manual.", auiPage);
            return;
        }
        ShowPage(dynamic_cast<BGSMessage*>(*pPageNode->Item()));
        Refresh();
    }
}

struct IMF;

class AA
{
  public:
    virtual ~AA();
};
AA* __cdecl FUN_00a09030(int);
int __cdecl FUN_007cc6d0();

extern Setting DAT_011d2340;
extern Setting DAT_011d34b0;
extern Setting DAT_011d4468;
extern Setting DAT_011d22b0;
extern float DAT_01023cd8;
extern char str_01077ba4[];

TESForm* __cdecl FUN_004839c0(unsigned int auID);

struct TForm2
{
    bool IsInCombat();
};

struct IMF
{
    Tile* FUN_00586150();
    Tile* FUN_0045cd60();
};


void* __cdecl FUN_00ec43fb(void* apObject, long alVfDelta, void* apSrcType, void* apDstType, int aiIsRef);
float __cdecl FUN_00a01530();

bool __cdecl FUN_004b71d0();

// @fnv 0x007e8890
bool InitTutorialMenu(TESForm* apMsg, bool aFlag)
{
    AA* p = FUN_00a09030(FUN_007cc6d0());
    if (p)
        delete p;

    Tile* pTile = ((IMF*)FUN_004b7210())->FUN_00586150()->ReadFile(str_01077ba4);
    DAT_011db088 = pTile ? pTile->FUN_00a03c90() : 0;

    if (DAT_011db088 != 0 && ((TutorialMenu*)DAT_011db088)->GetClass() == FUN_007cc6d0())
    {
        ((TutorialMenu*)DAT_011db088)
            ->FUN_00a1dc70(static_cast<TileMenu*>(FUN_00ec43fb(pTile, 0, (void*)&typeid(Tile), (void*)&typeid(TileMenu), 0)), 0);

        if (pTile->FUN_00a011b0(0xfa7) == 6006.0 || pTile->FUN_00a011b0(0xfa7) == 102.0)
            pTile->Set(0xfad, FUN_00a01530(), 1);

        ((TutorialMenu*)DAT_011db088)->m_pTiles[7]->SetString(0xfc4, DAT_011d2340.String(), 1);

        if (aFlag)
        {
            BGSListForm* pForm = FUN_004b71d0() ? dynamic_cast<BGSListForm*>(FUN_004839c0(0x165u))
                                                : dynamic_cast<BGSListForm*>(FUN_004839c0(0x163u));
            if (pForm)
            {
                ((TutorialMenu*)DAT_011db088)->pPages = reinterpret_cast<HelpListNode*>(pForm->GetList());
                if (apMsg == 0)
                    apMsg = dynamic_cast<BGSMessage*>(*((TutorialMenu*)DAT_011db088)->pPages->Item());
            }
            ((TutorialMenu*)DAT_011db088)->m_pTiles[1]->SetString(0xfc4, DAT_011d34b0.String(), 1);
            ((TutorialMenu*)DAT_011db088)->m_pTiles[2]->SetString(0xfc4, DAT_011d4468.String(), 1);
        }
        else
        {
            ((TutorialMenu*)DAT_011db088)->m_pTiles[1]->SetInt(0xfa3, 0);
            ((TutorialMenu*)DAT_011db088)->m_pTiles[2]->SetInt(0xfa3, 0);
        }

        ((TutorialMenu*)DAT_011db088)->m_pTiles[3]->SetString(0xfc4, DAT_011d22b0.String(), 1);

        if (apMsg == 0)
            FNV_Warning(0x12, "Warning:  Unable to find valid starting message for Tutorial Menu.");

        ((TutorialMenu*)DAT_011db088)->uiPageCount = 0;
        ((TutorialMenu*)DAT_011db088)->uiCurrentPage = 0;
        HelpListNode* node5;
        bool found2 = false;
        node5 = ((TutorialMenu*)DAT_011db088)->pPages;
        while (node5 != 0 && *node5->Item() != 0)
        {
            if (!found2 && *node5->Item() == apMsg)
            {
                ((TutorialMenu*)DAT_011db088)->uiCurrentPage = ((TutorialMenu*)DAT_011db088)->uiPageCount;
                found2 = true;
            }
            ((TutorialMenu*)DAT_011db088)->uiPageCount = ((TutorialMenu*)DAT_011db088)->uiPageCount + 1;
            node5 = node5->Next();
        }

        if (found2)
        {
            StrMem str;
            FUN_00406f60(&str, "%d/%d", ((TutorialMenu*)DAT_011db088)->uiCurrentPage + 1, ((TutorialMenu*)DAT_011db088)->uiPageCount);
            ((TutorialMenu*)DAT_011db088)->m_pTiles[5]->SetString(0xfc4, str, 1);
        }
        else
        {
            ((TutorialMenu*)DAT_011db088)->m_pTiles[5]->SetInt(0xfa3, 0);
            ((TutorialMenu*)DAT_011db088)->uiPageCount = 0;
        }

        if (apMsg != 0)
        {
            ((TutorialMenu*)DAT_011db088)->ApplyRecordToTiles(reinterpret_cast<BGSMessage*>(apMsg));
            ((TutorialMenu*)DAT_011db088)->FUN_007e9010();
            ((TForm2*)DAT_011db088)->IsInCombat();
            ((IMF*)FUN_004b7210())->FUN_0045cd60()->Set(0xfa9, DAT_01023cd8, 1);
            ((TutorialMenu*)DAT_011db088)->FUN_00a1dc20(0);
            return true;
        }
        else
        {
            delete (TutorialMenu*)DAT_011db088;
            return false;
        }
    }
    else
    {
        if (DAT_011db088 != 0 && DAT_011db088->FUN_00726070())
            delete (TutorialMenu*)DAT_011db088;
    }
    return false;
}
