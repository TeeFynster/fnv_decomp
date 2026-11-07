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
// src: GUESS 0x007e8e20 (confidence: low)
void TutorialMenu::ProcessAndTransformResult_007e8e20()
{
    ShowPageByIndex(static_cast<int>(uiCurrentPage) + 1);
}

// @fnv 0x007e8e60
// src: XBOX_PDB 0x007e8e60
bool TutorialMenu::DoGamepad_007e8e60(int aiButton, float afValue)
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
FORenderedMenu* __cdecl Interface_GetCurrentRenderedMenu();
void __cdecl HandleBackAction();
extern Menu* DAT_011db088;

// @fnv 0x007e8d60
// src: XBOX_PDB 0x007e8d60
void TutorialMenu_Close()
{
    if (DAT_011db088)
    {
        DAT_011db088->FUN_00726070()->Set(0x1772, 1);
        if (Interface_GetCurrentRenderedMenu())
            DAT_011db088->InstantFadeOut();
        else
            DAT_011db088->LoadMenuData();
        HandleBackAction();
    }
}


void* __cdecl InterfaceManager_GetSingleton();
void __cdecl TutorialMenu_Close();
// @fnv 0x007e8e80
bool TutorialMenu::HandleGamepadButton(int aiButton, float afValue)
{
    if (InterfaceH_tutorialmenu::GetSelectedTargetIndex(GetClass()) && aiButton == 10)
    {
        InterfaceManager_GetSingleton();
        InterfaceManager::SendGamepadButton(10);
        TutorialMenu_Close();
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x007e9010
// src: XBOX_PDB 0x007e9010
void TutorialMenu::UpdatePrevNext()
{
    m_pTiles[2]->Set(0xFAF, 0 < uiCurrentPage);
    m_pTiles[1]->Set(0xFAF, uiCurrentPage + 1 < uiPageCount);
}

// Resolves apTarget from the tile array at offset 0x28 when null and aiID is 0-7, then dispatches on aiID to one of three handlers.
// @fnv 0x007e8db0
// src: XBOX_PDB 0x007e8db0
void TutorialMenu::DoClick_007e8db0(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 8)
        apTarget = m_pTiles[aiID];
    switch (aiID)
    {
    case 1:
        ProcessAndTransformResult_007e8e20();
        break;
    case 2:
        DecrementAndDispatch();
        break;
    case 3:
        TutorialMenu_Close();
        break;
    }
}

struct MenuTileField
{
    void __thiscall Tile_Set_00a01350(unsigned int property, const char* text, int forceUpdate);
    void __thiscall FUN_00700320(unsigned int property, int matched);
    void __thiscall Tile_Set(void* value, float fade, int flags);
};
extern char str_010702d8[];
extern "C" void* __cdecl Tile_AddUserTrait(const char* descriptor, int index);
// @fnv 0x007e9060
void TutorialMenu::ApplyRecordToTiles(BGSMessage* record)
{
    const char* description;
    if (!record)
        return;
    if (reinterpret_cast<MenuTileField*>(m_pTiles[4]) != 0)
    {
        reinterpret_cast<MenuTileField*>(m_pTiles[4])->Tile_Set_00a01350(0xFC4, record->GetFullName(), 1);
    }
    if (reinterpret_cast<MenuTileField*>(m_pTiles[0]) != 0)
    {
        // Avoid the null-adjusting base conversion emitted by the original compiler.
        description = reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(record) + sizeof(TESForm) + sizeof(TESFullName))
                          ->GetDescription(0, static_cast<CHUNK_ID>(0x43534544));
        if (description != 0)
        {
            reinterpret_cast<MenuTileField*>(m_pTiles[0])->FUN_00700320(0xFBE, description[0] == '<');
            reinterpret_cast<MenuTileField*>(m_pTiles[0])->Tile_Set_00a01350(0xFC4, description, 1);
        }
    }
    if (reinterpret_cast<MenuTileField*>(m_pTiles[6]) != 0)
    {
        reinterpret_cast<MenuTileField*>(m_pTiles[6])->Tile_Set(Tile_AddUserTrait(str_010702d8, -1), 0.0f, 0);
    }
}

int __cdecl BSStringT_char_SPrintF(StrMem* apStr, const char* apFmt, ...);
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
        BSStringT_char_SPrintF(&kText, "%d/%d", auiPage + 1, uiPageCount);
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
AA* __cdecl Tile_GetMenuByClass(int);
int __cdecl TutorialMenu_GetClassStatic();

extern Setting DAT_011d2340;
extern Setting DAT_011d34b0;
extern Setting DAT_011d4468;
extern Setting DAT_011d22b0;
extern float DAT_01023cd8;
extern char str_01077ba4[];

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int auID);

struct TForm2
{
    bool IsInCombat();
};

struct IMF
{
    Tile* CombatController_GetCombatState();
    Tile* FUN_0045cd60();
};


void* __cdecl FUN_00ec43fb(void* apObject, long alVfDelta, void* apSrcType, void* apDstType, int aiIsRef);
float __cdecl FUN_00a01530();

bool __cdecl InterfaceManager_Has360Controller();

// @fnv 0x007e8890
bool InitTutorialMenu(TESForm* apMsg, bool aFlag)
{
    AA* p = Tile_GetMenuByClass(TutorialMenu_GetClassStatic());
    if (p)
        delete p;

    Tile* pTile = ((IMF*)InterfaceManager_GetSingleton())->CombatController_GetCombatState()->ReadFile(str_01077ba4);
    DAT_011db088 = pTile ? pTile->Tile_GetMenu() : 0;

    if (DAT_011db088 != 0 && ((TutorialMenu*)DAT_011db088)->GetClass() == TutorialMenu_GetClassStatic())
    {
        ((TutorialMenu*)DAT_011db088)
            ->FUN_00a1dc70(static_cast<TileMenu*>(FUN_00ec43fb(pTile, 0, (void*)&typeid(Tile), (void*)&typeid(TileMenu), 0)), 0);

        if (pTile->FUN_00a011b0(0xfa7) == 6006.0 || pTile->FUN_00a011b0(0xfa7) == 102.0)
            pTile->Set(0xfad, FUN_00a01530(), 1);

        ((TutorialMenu*)DAT_011db088)->m_pTiles[7]->SetString(0xfc4, DAT_011d2340.String(), 1);

        if (aFlag)
        {
            BGSListForm* pForm = InterfaceManager_Has360Controller() ? dynamic_cast<BGSListForm*>(TESForm_GetFormByNumericID(0x165u))
                                                : dynamic_cast<BGSListForm*>(TESForm_GetFormByNumericID(0x163u));
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
            BSStringT_char_SPrintF(&str, "%d/%d", ((TutorialMenu*)DAT_011db088)->uiCurrentPage + 1, ((TutorialMenu*)DAT_011db088)->uiPageCount);
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
            ((TutorialMenu*)DAT_011db088)->UpdatePrevNext();
            ((TForm2*)DAT_011db088)->IsInCombat();
            ((IMF*)InterfaceManager_GetSingleton())->FUN_0045cd60()->Set(0xfa9, DAT_01023cd8, 1);
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
