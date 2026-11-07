#include "../../../../include/TraitSelectMenu.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/Tile.h"
#include "../../../../include/Menu.h"

// BSAudio still declares legacy handle returns. Cast its editor-ID entry point
// to the shared handle ABI and retain this unit's original no-argument Play call.
typedef BSSoundHandle (BSAudio::*TraitSoundFactory)(const char*, unsigned int, int);
typedef bool (BSSoundHandle::*TraitSoundPlay)();

// src/fallout/interface/menus/traitselectmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/traitselectmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x007e7ac0
// src: COMMUNITY 0x007e7ac0
int __thiscall TraitSelectMenu::GetMenuID_007e7ac0()
{
    return 0x434;
}

// @fnv 0x007e7d90
// src: COMMUNITY 0x007e7d90
int __cdecl TraitSelectMenu_GetMenuID_0()
{
    return 0x434;
}


// @fnv 0x007e8840
// src: XBOX_PDB 0x007e8840
void __thiscall TraitSelectMenu::ClearCheckBox()
{
    HandleTraitSelection(-1, 0);
}


// @fnv 0x007e7da0
// src: COMMUNITY 0x007e7da0
bool __thiscall TraitSelectMenu::HasTiles_007e7da0()
{
    for (int i = 0; i < 0x12; ++i)
    {
        if (m_pTiles[i] == 0)
            return false;
    }
    return true;
}

// @fnv 0x007e7b00: compiler-generated scalar deleting destructor.

extern int DAT_011db00c;
// @fnv 0x007e7b30
TraitSelectMenu::~TraitSelectMenu()
{
    DAT_011db00c = 0;
}

namespace fnv_007e7de0 {
struct FUN_00975d10_host
{
    void UpdateActor3D();
};
extern Menu* DAT_011db00c;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern FUN_00975d10_host DAT_011e0e80;
// @fnv 0x007e7de0
// src: XBOX_PDB 0x007e7de0
void TraitSelectMenu_Close()
{
    if (DAT_011db00c)
    {
        if (!g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
            DAT_011e0e80.UpdateActor3D();
        DAT_011db00c->GetTile()->Set(0x1772, 1);
        DAT_011db00c->LoadMenuData();
    }
}
}  // namespace fnv_007e7de0

void* __cdecl InterfaceManager_GetSingleton();
struct FUN_0070ec70_This
{
    int __thiscall InterfaceManager_GetMouseWheel();
};
extern float const runtimeFloatSettingDefault275;
// Reads a value from FUN_004b7210 and calls FUN_007e8310 with 0.05f when it is negative or with runtimeFloatSettingDefault275 when it is positive.
// @fnv 0x007e82b0
// src: XBOX_PDB 0x007e82b0
void __thiscall TraitSelectMenu::DoWheelMove_007e82b0(int, int)
{
    if (((FUN_0070ec70_This*)InterfaceManager_GetSingleton())->InterfaceManager_GetMouseWheel() < 0)
        ScrollForm(0.05f);
    if (((FUN_0070ec70_This*)InterfaceManager_GetSingleton())->InterfaceManager_GetMouseWheel() > 0)
        ScrollForm(runtimeFloatSettingDefault275);
}


// @fnv 0x007e8860
// src: XBOX_PDB 0x007e8860
void TraitSelectMenu::ToggleCheckBox(int tile)
{
    if (iCurrentID == tile)
        ClearCheckBox();
    else
        SelectTrait(tile, 0);
}

// @fnv 0x007e7ad0
void __thiscall TraitSelectMenu::SetTileByID(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 0x12)
    {
        m_pTiles[aiID] = apTile;
    }
}

// @fnv 0x007e8280
// src: XBOX_PDB 0x007e8280
void __thiscall TraitSelectMenu::DoEnter_007e8280(int aiID, Tile* apTarget)
{
    if (apTarget == 0 && aiID >= 0 && aiID < 0x12)
        apTarget = m_pTiles[aiID];
}

void __cdecl TraitSelectMenu_Close();
void __cdecl InterfaceManager_PlayMenuSound(int);


// @fnv 0x007e7e30
// src: XBOX_PDB 0x007e7e30
void TraitSelectMenu::DoClick_007e7e30(int aiID, Tile* apTarget)
{
    if (apTarget == 0 && aiID >= 0 && aiID < 0x12)
    {
        apTarget = this->m_pTiles[aiID];
    }

    switch (aiID)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        ToggleCheckBox(aiID);
        break;
    case 14:
        InterfaceManager_PlayMenuSound(1);
        TraitSelectMenu_Close();
        break;
    }
}


// @fnv 0x007e81b0
bool TraitSelectMenu::HandleKeyInput(int iKey, int iUnused)
{
    bool bHandled = false;
    switch (iKey)
    {
    case 9:
        if (m_iSelected >= 0 && m_iSelected <= 0xc)
            ToggleCheckBox(m_iSelected);
        else if (m_iSelected == 0xe)
            HandleSelection(0xe, static_cast<Tile*>(m_pvTile));
        bHandled = true;
        break;
    case 10:
        bHandled = true;
        break;
    case 1:
        ChangePage(true);
        bHandled = true;
        break;
    case 2:
        ChangePage(false);
        bHandled = true;
        break;
    }
    return bHandled;
}


// @fnv 0x007e85c0
void TraitSelectMenu::ChangePage(bool bPrevious)
{
    if (bPrevious)
    {
        switch (m_uiPage)
        {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            SetPage(m_uiPage - 1, false);
            break;
        case 14:
            SetPage(12, false);
            break;
        default:
            SetPage(0, false);
            break;
        }
    }
    else
    {
        switch (m_uiPage)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            SetPage(m_uiPage + 1, false);
            break;
        case 12:
            SetPage(14, false);
            break;
        case 14:
            break;
        default:
            SetPage(0, false);
            break;
        }
    }
}

unsigned int gm_GetTickCount();


static const char kErase[] = "UITraitSelectErase";

// @fnv 0x007e86c0
void TraitSelectMenu::SelectTrait(int aiID, bool abForce)
{
    if (!abForce && iCurrentID == aiID)
        return;
    uiLastTick = gm_GetTickCount();
    if (pCheckTile)
    {
        if (aiID == -1)
        {
            pCheckTile->SetInt(0xfa3, 0);
            ((BSAudio::GetSingleton()->*reinterpret_cast<TraitSoundFactory>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(
                kErase, 0x121, 0).*reinterpret_cast<TraitSoundPlay>(&BSSoundHandle::Play))();
        }
        else if (m_pTiles[aiID])
        {
            pCheckTile->SetInt(0xfa3, 1);
            pCheckTile->SetFloat(0xfa2, m_pTiles[aiID]->GetFloat(0xfa2) - 8.0, true);
            ((BSAudio::GetSingleton()->*reinterpret_cast<TraitSoundFactory>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(
                "UITraitSelectCheckmark", 0x121, 0).*reinterpret_cast<TraitSoundPlay>(&BSSoundHandle::Play))();
        }
    }
    iCurrentID = aiID;
}

struct RootTile
{
    Tile* ReadFile(const char*);
};
struct ManagerOpen
{
    RootTile* GetRoot();
};
struct TileOpen
{
    TraitSelectMenu* GetMenu();
    float GetValue(int);
    void SetValue(int, float, bool);
};
TraitSelectMenu* FindMenu(int);
void Warning(const char*);
float DefaultDepth();
// @fnv 0x007e7b60
// src: COMMUNITY 0x007e7b60
Tile* __cdecl TraitSelectMenu_Create()
{
    ManagerOpen* pManager = (ManagerOpen*)InterfaceManager_GetSingleton();
    TraitSelectMenu* oldMenu = FindMenu(TraitSelectMenu_GetMenuID_0());
    if (oldMenu)
        delete oldMenu;
    Tile* pTile = pManager->GetRoot()->ReadFile("Data\\Menus\\trait_select_menu.xml");
    DAT_011db00c = (int)((TileOpen*)pTile)->GetMenu();
    if (DAT_011db00c && ((TraitSelectMenu*)DAT_011db00c)->GetClass() == TraitSelectMenu_GetMenuID_0())
    {
        ((TraitSelectMenu*)DAT_011db00c)->SetTileMenu(reinterpret_cast<TileMenu*>(pTile), false);
        if (!((TraitSelectMenu*)DAT_011db00c)->Init())
        {
            Warning("MENUS: Companion Wheel Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        ((TraitSelectMenu*)DAT_011db00c)->scrollX = 0.0f;
        ((TraitSelectMenu*)DAT_011db00c)->scrollY = 0.0f;
        ((TraitSelectMenu*)DAT_011db00c)->Select(0, 0);
        ((TraitSelectMenu*)DAT_011db00c)->lastTick = gm_GetTickCount();
        ((BSAudio::GetSingleton()->*reinterpret_cast<TraitSoundFactory>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(
                "UIPopUpMessageGeneral", 0x121, 0).*reinterpret_cast<TraitSoundPlay>(&BSSoundHandle::Play))();
        if (((TileOpen*)pTile)->GetValue(0xfa7) == 6006.0 || ((TileOpen*)pTile)->GetValue(0xfa7) == 102.0)
            ((TileOpen*)pTile)->SetValue(0xfad, DefaultDepth(), true);
        ((TraitSelectMenu*)DAT_011db00c)->SetMenuVisibility(false);
        return pTile;
    }
    else
    {
        if (DAT_011db00c && ((TraitSelectMenu*)DAT_011db00c)->GetTile())
            delete (TraitSelectMenu*)DAT_011db00c;
    }
    return 0;
}

int __cdecl Tile_TextToTrait(const char* name);
bool __cdecl InterfaceManager_Has360Controller();
int __cdecl FUN_00ec7d40(int value);
extern short DAT_011d8a5e;
extern short DAT_011d8a62;
struct FUN_00755680_shell
{
    bool InterfaceManager_GetMouseVisible();
};
struct FUN_00a012d0_t
{
    void Tile_Set(int id, float value, bool propagate);
};
struct TraitScrollTile : FUN_00a012d0_t
{
    float FUN_00a011b0(int id);
};
// @fnv 0x007e7ea0
void TraitSelectMenu::UpdateScrollAnimation()
{
    if (scrollTile)
    {
        int id = Tile_TextToTrait("_current_value");
        if (scrollTile->FUN_00a011b0(id) != currentPosition * 10.0f)
            ScrollForm(scrollTile->FUN_00a011b0(id) * 0.1f - currentPosition);
    }
    bool bVertical = false;
    bool overrideFlag3 = false;
    float horizontal = 0.0f;
    float vertical = 0.0f;
    if ((InterfaceManager_GetSingleton(), InterfaceManager_Has360Controller()) && !static_cast<FUN_00755680_shell*>(InterfaceManager_GetSingleton())->InterfaceManager_GetMouseVisible())
    {
        if ((InterfaceManager_GetSingleton(), InterfaceManager_Has360Controller()) && !static_cast<FUN_00755680_shell*>(InterfaceManager_GetSingleton())->InterfaceManager_GetMouseVisible())
        {
            if (FUN_00ec7d40(DAT_011d8a5e) > 7849)
            {
                overrideFlag3 = true;
                horizontal = DAT_011d8a5e;
            }
            if (FUN_00ec7d40(DAT_011d8a62) > 8689)
            {
                bVertical = true;
                vertical = DAT_011d8a62;
            }
        }
    }
    if (currentID != -1 && selectedTile)
    {
        unsigned int elapsed = gm_GetTickCount() - selectionTick;
        if (elapsed < 50)
        {
            selectedTile->Tile_Set(4032, 0.0f, true);
            selectedTile->Tile_Set(4031, 0.0f, true);
        }
        else if (elapsed < 100)
        {
            selectedTile->Tile_Set(4032, 0.0f, true);
            selectedTile->Tile_Set(4031, 32.0f, true);
        }
        else if (elapsed < 150)
        {
            selectedTile->Tile_Set(4032, 64.0f, true);
            selectedTile->Tile_Set(4031, 0.0f, true);
        }
        else
        {
            selectedTile->Tile_Set(4032, 64.0f, true);
            selectedTile->Tile_Set(4031, 32.0f, true);
        }
    }
    if ((InterfaceManager_GetSingleton(), InterfaceManager_Has360Controller()) && !static_cast<FUN_00755680_shell*>(InterfaceManager_GetSingleton())->InterfaceManager_GetMouseVisible())
    {
        unsigned int elapsed = gm_GetTickCount() - updateTick;
        updateTick = gm_GetTickCount();
        if (targetPosition != currentPosition)
        {
            float difference = elapsed * 0.001f;
            float step = targetPosition - currentPosition;
            if (step > difference)
                step = difference;
            if (step < -difference)
                step = -difference;
            ScrollForm(step);
        }
    }
}

TraitScrollTile* __cdecl Tile_GetMenuByClass(int aiType);
int __cdecl Interface_PlayMenuSound(int);

struct TraitPokeTile
{
    void SetTraitAndReset(int aiID, float afValue);
};

// Clamps currentPosition to [0,1], updates scroll tile position and value display, and sets _SetInCode on the scroll tile.
// @fnv 0x007e8310
// src: XBOX_PDB 0x007e8310
void TraitSelectMenu::ScrollForm(float afDelta)
{
    this->currentPosition += afDelta;
    if (this->currentPosition > 1.0)
        this->currentPosition = 1.0f;
    if (this->currentPosition < 0.0)
        this->currentPosition = 0.0f;
    TraitScrollTile* pMenu9 = Tile_GetMenuByClass(0x434);
    if (pMenu9)
    {
        float fA5 = pMenu9->FUN_00a011b0(0x1004);
        float fB = pMenu9->FUN_00a011b0(0x1005);
        float fC3 = pMenu9->FUN_00a011b0(0x1006);
        float fD = pMenu9->FUN_00a011b0(0x1007);
        float fE2 = pMenu9->FUN_00a011b0(0x1008);
        float fPos2 = 0.0f;
        this->unk64 &&
            (fPos2 = fA5 - this->currentPosition * fE2,
             ((TraitScrollTile*)this->unk64)->Tile_Set(0xfa2, fPos2, true), 1);
        Interface_PlayMenuSound(4);
        if (this->scrollTile)
        {
            int iID2 = Tile_TextToTrait("_current_value");
            float fScaled5 = this->currentPosition * 10.0;
            this->scrollTile->Tile_Set(iID2, fScaled5, false);
            ((TraitPokeTile*)this->scrollTile)->SetTraitAndReset(Tile_TextToTrait("_SetInCode"), 1.0f);
        }
    }
}


extern double const _DAT_01012060;

// Selects a trait tile by clearing the previous selection, marking the new one, and computing m_fRatio from the selected and initial setting values.
// @fnv 0x007e8470
// src: COMMUNITY 0x007e8470
void __thiscall TraitSelectMenu::SetScroll(int aiID, bool abForce)
{
    Tile* settings;
    float selectedValue;
    float settingValue;
    float initialSetting;

    if (!abForce && m_iSelectedTrait == aiID)
        return;

    if (m_iSelectedTrait != -1 && m_pTiles[m_iSelectedTrait] != 0)
    {
        m_pTiles[m_iSelectedTrait]->SetInt(0x1005, 0);
    }

    m_iSelectedTrait = aiID;

    if (m_iSelectedTrait != -1)
    {
        if (m_pTiles[m_iSelectedTrait] != 0)
        {
            m_pTiles[m_iSelectedTrait]->SetInt(0x1005, 1);
        }

        InterfaceManager_GetSingleton();
        if (InterfaceManager_Has360Controller() && !reinterpret_cast<FUN_00755680_shell*>(InterfaceManager_GetSingleton())->InterfaceManager_GetMouseVisible())
        {
            settings = reinterpret_cast<Tile*>(Tile_GetMenuByClass(0x434));
            if (settings != 0 && m_pTiles[15] != 0)
            {
                settingValue = settings->GetFloat(0x1008);
                initialSetting = m_pTiles[15]->GetFloat(0xfb0);
                selectedValue = m_pTiles[m_iSelectedTrait]->GetFloat(0xfa2);
                if (initialSetting != _DAT_01012060)
                {
                    m_fRatio = selectedValue / initialSetting;
                }
                else
                {
                    m_fRatio = 0.0f;
                }
            }
        }
    }
}
