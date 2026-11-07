// fallout/interface/menus/inventorymenu.cpp: InventoryMenu, Interface, Menu, InventoryCheck and more (30 functions)

#include "../../../../include/InterfaceManager.h"
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/HotkeyWheelDisplay.h"
#include "../../../../include/InventoryMenu__sPageState.h"
#include "../../../../include/ListBoxBase.h"
#include "../../../../include/ListBox_ItemChange___.h"
#include "../../../../include/StatsMenu.h"
#include "../../../../include/OSGlobals.h"
#include "../../../../include/TESObjectARMO.h"
#include "../../../../include/Menu.h"
#include "../../../../include/TESObjectWEAP.h"
#include "../../../../include/Tile.h"
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/GO.h"
#include "../../../../include/Setting.h"
#include "../../../../include/TESBipedModelForm.h"

#include <stddef.h>
#include "../../../../include/FOPipboyManager.h"
#include "../../../../include/InventoryMenu.h"
#define FNV_CTOR_JOIN_(a, b) a##b
#define FNV_CTOR_JOIN(a, b) FNV_CTOR_JOIN_(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_CTOR_JOIN(fnv_layout_check_, __LINE__)[(c) ? 1 : -1]

// The shared class lacks the 0x006e4ba0 entry; its only argument is this in ECX.
int __fastcall GetHotkeySlotCount(HotkeyWheelDisplay*);

FNV_STATIC_ASSERT(sizeof(InventoryMenu) == 0x124);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_iCurrentTab) == 0x84);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kPageStates) == 0x88);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kItemList) == 0xB8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kMenuData) == 0xE8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kHotkeyObjects) == 0x11C);


#include "../../../../include/InventoryStackRecord.h"
class InputManager
{
  public:
    int Controls_GetUserAction(int, int);
    int Controls_GetMouseButton(int, int);
};
extern OSGlobals* g_osGlobals;
extern PlayerCharacter* g_thePlayer;
class InventoryInterface
{
  public:
    enum enumMenus
    {
        kInventory = 1002
    };
    static bool GetSelectedTargetIndex(enumMenus);
    static bool IsSaveLoadActive();
    static FOPipboyManager* GetPipboyManagerInstance();
    static void SetTileFormattedText(Tile*, int, const char*, ...);
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
};
class InventoryMenuSetting
{
  public:
    const char* FUN_00403df0();
};
extern InventoryMenuSetting DAT_011d3810;
extern InventoryMenuSetting DAT_011d1e18;
extern bool DAT_011d9f38;
bool InterfaceManager_Has360Controller();
InterfaceManager* InterfaceManager_GetSingleton();
int Warning(const char*, ...);
extern InventoryMenuSetting DAT_011d3258;
extern InventoryMenuSetting DAT_011d2acc;
extern InventoryMenuSetting DAT_011d40b4;
extern InventoryMenuSetting DAT_011d4d50;
extern InventoryMenuSetting DAT_011d29b8;
extern InventoryMenuSetting DAT_011d29f4;
extern InventoryMenuSetting DAT_011d2c7c;
extern InventoryMenuSetting DAT_011d412c;
extern InventoryMenuSetting DAT_011d330c;
extern InventoryMenuSetting DAT_011d20c4;
extern InventoryMenuSetting DAT_011d396c;

static const int kGetClassValue = 1002;

// @fnv 0x0077fb40
int InventoryMenu::GetClass()
{
    return kGetClassValue;
}

// m_pTiles holds kNumTiles (23) entries, so out-of-range tile ids are ignored.
static const int kNumTiles = 23;

// Stores tile in the tile array at index id when id is within the valid tile range.
// @fnv 0x007cb4e0
void InventoryMenu::AssignTileByID(int aiTileIndex, Tile* tile)
{
    if (aiTileIndex >= 0 && aiTileIndex < kNumTiles)
    {
        m_pTiles[aiTileIndex] = tile;
    }
}

// @fnv 0x0077fa00
InventoryMenu::InventoryMenu()
{
    ms_iValueTileID = Tile::GetTraitID("_Value");
    ms_iItemTypeTileID = Tile::GetTraitID("_ItemType");
    ms_iCurrentTabTileID = Tile::GetTraitID("_CurrentTab");
    ms_iKeyringOpenTileID = Tile::GetTraitID("_KeyringOpen");
    ms_iEquippableItemTileID = Tile::GetTraitID("_EquippableItem");
    for (int i = 0; i < 6; ++i)
    {
        m_kPageStates[i].m_iSelectedItemIndex = -1;
        m_kPageStates[i].m_iScrollOffset = 0;
    }
    m_iCurrentTab = 0;
}

// Handles hotkey selection for the inventory menu: toggles hotkey slots, shows messages for invalid items, and updates the item card display.
// @fnv 0x00781ba0
void InventoryMenu::UpdateDialog()
{
    if (!InventoryInterface::GetSelectedTargetIndex(InventoryInterface::kInventory) ||
        !InventoryInterface::GetPipboyManagerInstance()->IsUnk28Set())
        return;
    int iPage;
    int iHotkey;
    bool bHotkeySelected;
    int iIndex;
    if (InterfaceManager_Has360Controller())
    {
        if (m_kMenuData.GetVisible())
        {
            m_pTiles[20]->Set(0xfa3, 0);
            m_pTiles[22]->Set(0xfa3, 0);
            iHotkey = m_kMenuData.GetSelectedHotkeyIndex(-1);
            if (iHotkey >= 0)
            {
                DAT_011d9f38 = true;
            }
            else if (DAT_011d9f38)
            {
                if (ms_pActionPointSource && ms_pActionPointSource->GetConditionPercent(true) == 0.0)
                {
                    InventoryInterface::ShowMessage(DAT_011d3810.FUN_00403df0(), 0,
                                           "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                                           "UIVATSInsufficientAP", 2.0f, false);
                }
                else if (!FUN_00726070()->ContainsTrait(ms_iEquippableItemTileID) ||
                         (ms_pActionPointSource &&
                          ms_pActionPointSource->FUN_0044ddc0()->GetFormType() == TESForm::kArmor))
                {
                    InventoryInterface::ShowMessage(DAT_011d1e18.FUN_00403df0(), 0,
                                           "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                                           "UIVATSInsufficientAP", 2.0f, false);
                }
                else
                {
                    m_kMenuData.SetHotkeyItem(ms_pActionPointSource);
                    TESBoundObject* object = ms_pActionPointSource->FUN_0044ddc0();
                    m_kHotkeyObjects.AddHead(object);
                    UpdateItemList();
                    m_kMenuData.SetVisible(true);
                    m_pTiles[11]->Set(0xfa3, 0);
                }
                DAT_011d9f38 = false;
            }
        }
        else if (ms_pActionPointSource && ms_pActionPointSource->FUN_0044ddc0()->GetFormType() == TESForm::kWeapon)
        {
            m_pTiles[20]->Set(0xfa3, 1);
            m_pTiles[22]->Set(0xfa3, 1);
            InterfaceManager::UpdateContainerMenu(0, 0, m_pTiles[20], ms_pActionPointSource, true);
            InterfaceManager::UpdateContainerMenu(0, 0, m_pTiles[22], ms_pActionPointSource, true);
        }
    }
    else
    {
        bHotkeySelected = false;
        if (ms_pActionPointSource && ms_pActionPointSource->FUN_0044ddc0()->GetFormType() == TESForm::kWeapon)
        {
            m_pTiles[20]->Set(0xfa3, 1);
            m_pTiles[22]->Set(0xfa3, 1);
        }
        for (iIndex = 0; !bHotkeySelected && !FUN_00726070()->ContainsTrait(ms_iKeyringOpenTileID) &&
                         iIndex < GetHotkeySlotCount(&m_kMenuData);
             ++iIndex)
        {
            if (g_osGlobals->Main_GetControls()->Controls_GetUserAction(iIndex + 17, 1) ||
                (g_osGlobals->Main_GetControls()->Controls_GetUserAction(iIndex + 17, 0) && iIndex != 1))
            {
                if (iIndex == 1)
                    continue;
                if (!m_kMenuData.GetVisible())
                {
                    m_kMenuData.SetVisible(true);
                    m_pTiles[11]->Set(0xfa3, 0);
                }
                else
                {
                    m_pTiles[20]->Set(0xfa3, 0);
                    m_pTiles[22]->Set(0xfa3, 0);
                }
                m_kMenuData.GetSelectedHotkeyIndex(iIndex);
                bHotkeySelected = true;
            }
        }
        if (!bHotkeySelected && m_kMenuData.GetVisible())
        {
            m_kMenuData.SetVisible(false);
            if (reinterpret_cast<ListBoxBase*>(&m_kItemList)->GetHighlightedItem())
                m_pTiles[11]->Set(0xfa3, 1);
        }
    }
    if (InventoryInterface::IsSaveLoadActive() && g_osGlobals->Main_GetControls()->Controls_GetMouseButton(1, 1) && reinterpret_cast<ListBoxBase*>(&m_kItemList)->GetHighlightedItem() &&
        !g_osGlobals->Main_GetControls()->Controls_GetUserAction(14, 1))
        HandleSelection(7, 0);
    iPage = ms_pInventoryMenu->m_iCurrentTab + 24;
    if (iPage == 24)
    {
        InterfaceManager::UpdateContainerMenu(m_pTiles[14], m_pTiles[15], m_pTiles[16], ms_pActionPointSource, false);
    }
    else if (iPage == 25)
    {
        InterfaceManager::UpdateContainerMenu(
            ms_pActionPointSource &&
                    static_cast<TESObjectARMO*>(ms_pActionPointSource->FUN_0044ddc0())->GetArmorRating() != 0.0
                ? m_pTiles[17]
                : 0,
            ms_pActionPointSource &&
                    static_cast<TESObjectARMO*>(ms_pActionPointSource->FUN_0044ddc0())->GetDamageThreshold() != 0.0
                ? m_pTiles[18]
                : 0,
            0, ms_pActionPointSource, false);
    }
    m_pTiles[2]->Set(0xfa9, 0.0f, true);
    InterfaceManager::UpdateContainerMenu(g_thePlayer->GetCurrentActorValue(static_cast<ActorValue::Index>(18)) != 0.0 ? m_pTiles[2] : 0,
                                          m_pTiles[21], 0, ms_pActionPointSource, false);
}

// Loads inventory_menu.xml, stores the InventoryMenu, initializes its list and title tiles, and returns the tile or 0 on failure.
// @fnv 0x0077fc10
Tile* InventoryMenu::Create()
{
    InterfaceManager* pMenuInterfaceManager = InterfaceManager_GetSingleton();
    float m_fProjectionDepth = Tile::GetInterfaceScale();
    Menu* oldMenu = Tile::FindMenuById(GetClassStatic());
    if (oldMenu)
        delete oldMenu;
    Tile* pTile = pMenuInterfaceManager->CombatController_GetCombatState()->ReadFile("Data\\Menus\\Main\\inventory_menu.xml");
    ms_pInventoryMenu = static_cast<InventoryMenu*>(pTile->GetMenu());
    Menu::ReadMenuDefinition("Data\\Menus\\Main\\inventory_menu.xml", ms_pInventoryMenu);
    if (ms_pInventoryMenu && ms_pInventoryMenu->GetClass() == GetClassStatic())
    {
        ms_pInventoryMenu->SetTileMenu(reinterpret_cast<TileMenu*>(pTile), false);
        ms_pInventoryMenu->Menu_SetRenderedMenu();
        if (!ms_pInventoryMenu->IsWellFormedMenu_0077ff90())
        {
            Warning("MENUS: Inventory Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (pTile->GetFloat(0xfa7) == 6006.0 ||
            pTile->GetFloat(0xfa7) == 102.0)
            pTile->Set(0xfad, Tile::GetInterfaceScale(), true);
        InterfaceManager_GetSingleton()->kTutorialManager.ShowMessage(34, GetClassStatic(), 512);
        ms_pInventoryMenu->m_kItemList.Initialize(ms_pInventoryMenu->m_pTiles[4], "IM_InventoryListTemplate");
        ms_pInventoryMenu->m_kItemList.FUN_007a1930(false);
        InventoryInterface::SetTileFormattedText(ms_pInventoryMenu->m_pTiles[13], 24, DAT_011d29b8.FUN_00403df0(),
                                        DAT_011d4d50.FUN_00403df0(), DAT_011d40b4.FUN_00403df0(),
                                        DAT_011d2acc.FUN_00403df0(), DAT_011d3258.FUN_00403df0(), 0);
        ms_pInventoryMenu->m_kMenuData.Initialize(ms_pInventoryMenu->m_pTiles[5]);
        ms_pInventoryMenu->m_pTiles[10]->Set(0xfc4, DAT_011d29f4.FUN_00403df0(), true);
        int titleTrait = Tile::GetTraitID("_Title");
        if (ms_pInventoryMenu->m_pTiles[14])
            ms_pInventoryMenu->m_pTiles[14]->Set(titleTrait, DAT_011d2c7c.FUN_00403df0(), true);
        if (ms_pInventoryMenu->m_pTiles[15])
            ms_pInventoryMenu->m_pTiles[15]->Set(titleTrait, DAT_011d412c.FUN_00403df0(), true);
        if (ms_pInventoryMenu->m_pTiles[16])
            ms_pInventoryMenu->m_pTiles[16]->Set(titleTrait, DAT_011d330c.FUN_00403df0(), true);
        if (ms_pInventoryMenu->m_pTiles[17])
            ms_pInventoryMenu->m_pTiles[17]->Set(titleTrait, DAT_011d20c4.FUN_00403df0(), true);
        if (ms_pInventoryMenu->m_pTiles[18])
            ms_pInventoryMenu->m_pTiles[18]->Set(titleTrait, DAT_011d396c.FUN_00403df0(), true);
        ms_pInventoryMenu->SetMenuVisibility(true);
        return pTile;
    }
    else
    {
        if (ms_pInventoryMenu && ms_pInventoryMenu->FUN_00726070())
            delete ms_pInventoryMenu;
    }
    return 0;
}

// @fnv 0x0077ff80
// src: XBOX_PDB 0x0077ff80
int InventoryMenu::GetClassStatic()
{
    return kGetClassValue;
}

// Returns true only if every one of the kNumTiles tile pointers is non-null; otherwise returns false.
// @fnv 0x0077ff90
// src: XBOX_PDB 0x0077ff90
bool InventoryMenu::IsWellFormedMenu_0077ff90()
{
    for (int i = 0; i < kNumTiles; ++i)
    {
        if (!m_pTiles[i])
            return false;
    }
    return true;
}

// @fnv 0x00704390
// src: XBOX_PDB 0x00704390
void __cdecl StatsMenu_ResetHealingMode()
{
    if (StatsMenu::ms_pInventoryMenu != 0)
    {
        if (StatsMenu::ms_pInventoryMenu->m_bHealingMode != 0)
        {
            StatsMenu::ms_pInventoryMenu->RefreshHealingOptions();
        }
    }
}

// 0x00780be0 stores the inventory page byte at InterfaceManager +0x13.
// @fnv 0x00780be0
void InterfaceManager::SetInventoryPageNumber(char value)
{
    byte013 = value;
}

extern double _gModifierZero;

// Sets tile property 0xFA3 to whether the float from property 0xFAC is greater than or equal to _gModifierZero.
// @fnv 0x00780c00
// src: XBOX_PDB 0x00780c00
void __cdecl InventoryMenu_SetVisibleFunc(Tile* pTile)
{
    pTile->Set(0xFA3, static_cast<const Tile*>(pTile)->GetFloat(0xFAC) >= _gModifierZero);
}

bool __cdecl _FUN_004b71d0();
int __cdecl Interface_GetTopMenuID();

struct FUN_00781620_shell : public InventoryMenu
{
    void __thiscall InventoryMenu_DoLeave(int aiID, Tile* apTarget);
};
// @fnv 0x00781620
// src: XBOX_PDB 0x00781620
void __thiscall FUN_00781620_shell::InventoryMenu_DoLeave(int aiID, Tile* apTarget)
{
    if (aiID == 0x1D || aiID == 0x1E)
    {
        if (!_FUN_004b71d0() || Interface_GetTopMenuID() != 0x3F8)
            ClearActionPointSource();
        this->FUN_00726070()->Set(InventoryMenu::ms_iEquippableItemTileID, 0);
    }
}

// @fnv 0x00782470
// src: XBOX_PDB 0x00782470
void InventoryMenu_SetKnobPosition(bool a1)
{
    if (InventoryMenu::ms_pInventoryMenu)
        InterfaceManager_GetSingleton()->GetPipboyManagerInstance()->SetValue(InventoryMenu::ms_pInventoryMenu->m_iCurrentTab, a1);
}

// @fnv 0x007824b0
// src: COMMUNITY 0x007824b0
unsigned char InventoryMenu_GetCurrentInventoryPage()
{
    int currTab;
    if (InventoryMenu::ms_pInventoryMenu)
        currTab = ((unsigned char*)InventoryMenu::ms_pInventoryMenu)[0x84];
    else
        currTab = 0;
    return currTab;
}

unsigned int __fastcall FUN_0044ddc0(void*);
// Returns 0 when a1 is non-null and its form type is 0x2E, otherwise returns 1.
// @fnv 0x00782810
unsigned char __cdecl IsNotFormType2E(void* a1)
{
    int v;
    if (a1)
        v = ((TESForm*)FUN_0044ddc0(a1))->GetFormType() != 0x2E;
    else
        v = 1;
    return v;
}

// @fnv 0x007800c0
// src: XBOX_PDB 0x007800c0
void __cdecl InventoryMenu_LoadPageState()
{
    int iElementIndex;
    if (InventoryMenu::ms_pInventoryMenu->FUN_00726070()
            ->ContainsTrait(InventoryMenu::ms_iKeyringOpenTileID))
        iElementIndex = 5;
    else
        iElementIndex = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab;
    int iarg = iElementIndex;
    InventoryMenu::ms_pInventoryMenu->m_kItemList.ListBox_ItemChange_SetListState(InventoryMenu::ms_pInventoryMenu->m_kPageStates[iarg].m_iSelectedItemIndex,
                       InventoryMenu::ms_pInventoryMenu->m_kPageStates[iarg].m_iScrollOffset);
}

struct FUN_004bddd0_t
{
    bool __thiscall ItemChange_GetWorn(bool);
};

struct FUN_00781860_shell
{
    bool __thiscall InventoryMenu_IsItemRepairable(InventoryStackRecord*);
};


struct GlobalObject_0040c150 : public InventoryMenuSetting
{
};

extern InventoryMenuSetting* DAT_011d5178;
extern GlobalObject_0040c150 g_011d3cdc;
extern GlobalObject_0040c150 g_011d460c;
extern GlobalObject_0040c150 g_011d478c;

// @fnv 0x00781680
// src: XBOX_PDB 0x00781680
void InventoryMenu::UpdateButtons()
{
    int icurrTabIndex;

    if (InventoryMenu::ms_pActionPointSource)
    {
        if (InventoryMenu::ms_pActionPointSource->FUN_0044ddc0()->GetFormType() == 0x19)
        {
            m_pTiles[6]->Set(0xfc4, DAT_011d5178->FUN_00403df0(), true);
        }
        else if (((FUN_004bddd0_t*)InventoryMenu::ms_pActionPointSource)->ItemChange_GetWorn(false))
        {
            m_pTiles[6]->Set(0xfc4, g_011d460c.FUN_00403df0(), true);
        }

        m_pTiles[6]->Set(
            0xfaf,
            static_cast<const Tile*>(FUN_00726070())->GetFloat(InventoryMenu::ms_iEquippableItemTileID),
            true);
        m_pTiles[7]->Set(0xfaf, 1);

        m_pTiles[9]->Set(0xfaf,
                         (unsigned char)(InventoryMenu::ms_pActionPointSource->FUN_0044ddc0()->GetFormType() != 0x29));
        m_pTiles[19]->Set(0xfaf, 1);

        m_pTiles[8]->Set(0xfaf, ((FUN_00781860_shell*)this)->InventoryMenu_IsItemRepairable(InventoryMenu::ms_pActionPointSource));
    }
    else
    {
        icurrTabIndex = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab + 0x18;

        if (icurrTabIndex == 0x1a)
        {
            m_pTiles[6]->Set(0xfc4, g_011d478c.FUN_00403df0(), true);
        }
        else
        {
            m_pTiles[6]->Set(0xfc4, g_011d3cdc.FUN_00403df0(), true);
        }

        m_pTiles[6]->Set(0xfaf, 0);
        m_pTiles[7]->Set(0xfaf, 0);
        m_pTiles[9]->Set(0xfaf, 0);
        m_pTiles[19]->Set(0xfaf, 0);
        m_pTiles[8]->Set(0xfaf, 0);
    }
}


struct FUN_007823d0_shell : public InventoryMenu
{
    bool __thiscall HandleInventoryButton(int aiButton, float afValue);
};

// Handles inventory menu buttons 16 and 10 when the inventory interface is open, hiding a tile and returning whether the button was handled.
// @fnv 0x007823d0
bool __thiscall FUN_007823d0_shell::HandleInventoryButton(int aiButton, float afValue)
{
    bool bhandled;

    bhandled = false;

    if (InventoryInterface::GetSelectedTargetIndex(InventoryInterface::kInventory))
    {
        switch (aiButton)
        {
        case 16:
            reinterpret_cast<HotkeyWheelDisplay*>(reinterpret_cast<char*>(this) + 0xE8)->SetVisible(false);

            if (reinterpret_cast<ListBoxBase*>(reinterpret_cast<char*>(this) + 0xB8)->GetHighlightedItem())
            {
                (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x54))->Set(0xFA3, 1);
            }

            bhandled = true;
            break;

        case 10:
            HandleSelection(0x0A, 0);
            bhandled = true;
            break;
        }
    }

    return bhandled;
}

namespace fnv_007824e0 {
template <class T> struct ListBoxItem
{
    int m_iValueAt00;
    T m_pInventoryEntryData;
};

struct FUN_004be2d0_shell
{
    unsigned char const* GetTargetFullName();
};

struct FUN_004bddd0_t
{
    bool ItemChange_GetWorn(bool);
};

int __cdecl BSstrcmp(char const*, char const*);

// @fnv 0x007824e0
// src: COMMUNITY 0x007824e0
int __cdecl InventoryMenu_CompareForSorting(ListBoxItem<InventoryStackRecord*>* apItem1, ListBoxItem<InventoryStackRecord*>* apItem2)
{
    int iresult;

    if (apItem1->m_pInventoryEntryData == 0)
    {
        iresult = 1;
    }
    else if (apItem2->m_pInventoryEntryData == 0)
    {
        iresult = -1;
    }
    else if (BSstrcmp(
                 reinterpret_cast<char const*>(
                     reinterpret_cast<FUN_004be2d0_shell*>(apItem1->m_pInventoryEntryData)->GetTargetFullName()),
                 reinterpret_cast<char const*>(
                     reinterpret_cast<FUN_004be2d0_shell*>(apItem2->m_pInventoryEntryData)->GetTargetFullName())) == 0)
    {
        iresult = apItem1->m_pInventoryEntryData->GetConditionPercent(false) >
                          apItem2->m_pInventoryEntryData->GetConditionPercent(false)
                      ? -1
                      : (apItem1->m_pInventoryEntryData->GetConditionPercent(false) <
                                 apItem2->m_pInventoryEntryData->GetConditionPercent(false)
                             ? 1
                             : 0);

        if (iresult == 0)
        {
            if (reinterpret_cast<FUN_004bddd0_t*>(apItem1->m_pInventoryEntryData)->ItemChange_GetWorn(0))
            {
                iresult = -1;
            }
            else if (reinterpret_cast<FUN_004bddd0_t*>(apItem2->m_pInventoryEntryData)->ItemChange_GetWorn(0))
            {
                iresult = 1;
            }
        }
    }
    else
    {
        iresult = BSstrcmp(
            reinterpret_cast<char const*>(
                reinterpret_cast<FUN_004be2d0_shell*>(apItem1->m_pInventoryEntryData)->GetTargetFullName()),
            reinterpret_cast<char const*>(
                reinterpret_cast<FUN_004be2d0_shell*>(apItem2->m_pInventoryEntryData)->GetTargetFullName()));
    }

    return iresult;
}
}  // namespace fnv_007824e0

struct XExtra
{
    short __thiscall ExtraDataList_GetCount();
};

struct Ref006815c0
{
    void* __thiscall _ref_006815c0();
};

struct InventoryDropPoint
{
    int x;
    int y;
    int z;
};


extern PlayerCharacter* _g_thePlayer;
extern int _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;

// @fnv 0x00780c50
void __cdecl DropInventoryItem(int aiAmountChosen)
{
    ExtraDataList* pextra;
    TESBoundObject* pobjectRef;
    InventoryDropPoint dropPoint;

    dropPoint.x = _NiPoint3_ZERO;
    dropPoint.y = _DAT_011f4270;
    dropPoint.z = _DAT_011f4274;

    pobjectRef = InventoryMenu::ms_pActionPointSource->FUN_0044ddc0();

    pextra = reinterpret_cast<GO*>(InventoryMenu::ms_pActionPointSource)->operator unsigned int()
                 ? *reinterpret_cast<ExtraDataList**>(
                       reinterpret_cast<Ref006815c0*>(
                           reinterpret_cast<GO*>(InventoryMenu::ms_pActionPointSource)->operator unsigned int())
                           ->_ref_006815c0())
                 : 0;

    if (aiAmountChosen == 0)
        return;

    if (pextra && pextra->ExtraDataList_GetCount() < aiAmountChosen)
        pextra = 0;

    _g_thePlayer->PlayerCharacter_GetDropPoint(pobjectRef, &dropPoint, 1, 1);
    // The shared virtual slot has no inventory signature yet.
    reinterpret_cast<void (__thiscall*)(PlayerCharacter*, TESBoundObject*, ExtraDataList*, int, InventoryDropPoint*, bool)>(
        (*reinterpret_cast<void***>(_g_thePlayer))[0xF3])(_g_thePlayer, pobjectRef, pextra, aiAmountChosen, &dropPoint, false);

    if (InventoryMenu::ms_pInventoryMenu)
    {
        if (InventoryMenu::ms_pActionPointSource)
        {
            {
                TESBoundObject* p = InventoryMenu::ms_pActionPointSource->FUN_0044ddc0();
                InventoryMenu::ms_pInventoryMenu->m_kHotkeyObjects.AddHead(p);
            }
        }
        InventoryMenu::UpdateItemList();
    }
}



extern int DAT_011d9ea4;

// Clears the global inventory menu pointer when the object is destroyed.
// @fnv 0x0077fb80
InventoryMenu::~InventoryMenu()
{
    DAT_011d9ea4 = 0;
}

extern int DAT_011d9eb8;

// @fnv 0x0077ffd0
void __cdecl UpdateCurrentValue()
{
    int tab;
    int idx;
    int res5;
    if (InventoryMenu::ms_pInventoryMenu->FUN_00726070()->IsTraitNonZero(DAT_011d9eb8))
    {
        tab = 5;
    }
    else
    {
        tab = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab;
    }
    idx = tab;
    if (reinterpret_cast<ListBoxBase*>(&InventoryMenu::ms_pInventoryMenu->m_kItemList)->GetHighlightedItem() != 0)
    {
        res5 = static_cast<int>(reinterpret_cast<ListBoxBase*>(&InventoryMenu::ms_pInventoryMenu->m_kItemList)->GetHighlightedItem()->GetFloat(0xfac));
    }
    else
    {
        res5 = -1;
    }
    InventoryMenu::ms_pInventoryMenu->m_kPageStates[idx].m_iSelectedItemIndex = res5;
    InventoryMenu::ms_pInventoryMenu->m_kPageStates[idx].m_iScrollOffset = static_cast<int>(
        InventoryMenu::ms_pInventoryMenu->m_kItemList.FUN_00825c00()->GetFloat(Tile::GetTraitID("_current_value")));
}

extern char* DAT_011dea3c;
// Checks indices 25 through 30 of the input interface and returns true if any first value is less than its second value.
// @fnv 0x00780f70
// src: XBOX_PDB 0x00780f70
bool __cdecl IsDrBagUsable()
{
    for (int index = 25; index < 31; ++index)
    {
        if (reinterpret_cast<ActorValueOwner*>(DAT_011dea3c + 0xa4)->GetActorValue(static_cast<ActorValue::Index>(index)) <
            reinterpret_cast<ActorValueOwner*>(DAT_011dea3c + 0xa4)->GetPermanentActorValue(static_cast<ActorValue::Index>(index)))
        {
            return true;
        }
    }
    return false;
}

namespace InventorySelection {
struct Item;
struct Form;

struct TileRef
{
    Tile** NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead();
};
struct TileHolder
{
    unsigned int unk0;
    TileRef tile;
};
// 0x007a1910 returns the selected stack; the shared list lacks this accessor.
Item* __fastcall GetSelectedInventoryItem(ListBox_ItemChange___*);
struct Form
{
    int FUN_00401170();
    void* GetUnk15C();
    int GetField1BC();
};
struct Item
{
    Form* FUN_0044ddc0();
    float ItemChange_GetItemHealth(int);
    const char* GetIconFilename(int);
};
struct Camera
{
    void FOPipboyManager_MoveKnob(int, float, float, bool);
};
InterfaceManager* InterfaceManager_GetSingleton();
extern Setting DAT_011db2f0, DAT_011db358, DAT_011d3dcc, DAT_011d1f2c, DAT_011d33f0;
extern Setting* DAT_011d5168;
extern int DAT_011d9f34, DAT_011d9ebc;
extern Item* DAT_011d9ea8;
extern PlayerCharacter* DAT_011dea3c;
extern float DAT_0102f0f8, DAT_0101b268, DAT_01050280, DAT_01072e3c, DAT_01073af0, DAT_0104f754;
extern double DAT_01073ae8, DAT_01073ae0;
extern const char DAT_01020764[], DAT_0106eb24[], DAT_01073aac[];
void Interface_PopulateItemStatsDisplay(Item*, Tile*);
const char* GetWeaponSkillIconPath(void*);
int BSsprintf(char*, unsigned int, const char*, ...);
int BSstrcmp(const char*, const char*);
void FUN_00406d30(char*, unsigned int, const char*);
unsigned int BSstrlen(const char*);
void* FUN_00479430(Form*);
const char* GetMenuIconName(void*);
void FUN_00406d50(char*, unsigned int, const char*);
}  // namespace InventorySelection

// On action 29 refreshes the selected item's label, stats, description, ammo and icon; on action 30 resets the description and button text.
// @fnv 0x00780ff0
void InventoryMenu::UpdateItemDisplay(int action, Tile* changed)
{
    if (action == 29)
    {
        InventorySelection::DAT_011d9ea8 = InventorySelection::GetSelectedInventoryItem(&m_kItemList);
        if (InventorySelection::DAT_011d9ea8)
        {
            // This virtual list accessor takes a trait ID; the shared list has no matching declaration.
            int selectedSlot11 = (int)reinterpret_cast<Tile* (__thiscall*)(ListBox_ItemChange___*, int)>((*reinterpret_cast<void***>(&m_kItemList))[1])(&m_kItemList, 0xfac)->FUN_00a011b0();
            if (InventorySelection::DAT_011d9f34 != selectedSlot11)
            {
                reinterpret_cast<InventorySelection::Camera*>(InventorySelection::InterfaceManager_GetSingleton()->GetPipboyManagerInstance())->FOPipboyManager_MoveKnob(
                    0, InventorySelection::DAT_011d9f34 < selectedSlot11 ? *InventorySelection::DAT_011db2f0.Setting_Float_00403e20() : -*InventorySelection::DAT_011db2f0.Setting_Float_00403e20(),
                    *InventorySelection::DAT_011db358.Setting_Float_00403e20(), 1);
                InventorySelection::DAT_011d9f34 = selectedSlot11;
            }
            float threshold = InventorySelection::DAT_0102f0f8;
            if (InventorySelection::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 24)
                threshold = InventorySelection::DAT_0101b268;
            if (InventorySelection::DAT_011d9ea8->ItemChange_GetItemHealth(1) >= threshold)
                m_pTiles[8]->Tile_Set_00a01350(0xfc4, InventorySelection::DAT_011d3dcc.FUN_00403df0(), 1);
            else
                m_pTiles[8]->Tile_Set_00a01350(0xfc4, InventorySelection::DAT_011d1f2c.FUN_00403df0(), 1);
            InventorySelection::Interface_PopulateItemStatsDisplay(InventorySelection::DAT_011d9ea8, m_pTiles[12]);
            m_pTiles[12]->FUN_00700320(0xfa3, 1);
            FUN_00726070()->FUN_00700320(InventorySelection::DAT_011d9ebc, InventorySelection::DAT_011dea3c->PlayerCharacter_CanEquipOrUseObject(reinterpret_cast<InventoryStackRecord*>(InventorySelection::DAT_011d9ea8)));
            m_pTiles[11]->Tile_Set_00a01350(0xfcc, InventorySelection::DAT_011d9ea8->GetIconFilename(0), 1);
            InventorySelection::Form* ammo = 0;
            if (InventorySelection::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 40)
            {
                ammo = InventorySelection::DAT_011d9ea8->FUN_0044ddc0();
                m_pTiles[20]->Tile_Set_00a01350(0xfcc, InventorySelection::GetWeaponSkillIconPath(ammo->GetUnk15C()), 1);
                char countText[128];
                InventorySelection::BSsprintf(countText, 128, InventorySelection::DAT_01020764, ammo->GetField1BC());
                if (m_pTiles[22])
                    m_pTiles[22]->Tile_Set_00a01350(0xfc4, countText, 1);
            }
            if (!InventorySelection::BSstrcmp(m_pTiles[11]->Tile_GetString(0xfcc), InventorySelection::DAT_011d33f0.FUN_00403df0()))
            {
                m_pTiles[11]->Tile_Set(0xfa1, InventorySelection::DAT_01050280, 1);
                m_pTiles[11]->Tile_Set(0xfb1, InventorySelection::DAT_01072e3c, 1);
                m_pTiles[11]->Tile_Set(0xfb0, InventorySelection::DAT_01072e3c, 1);
            }
            else if (InventorySelection::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 41)
            {
                float heightSlot1 = InventorySelection::DAT_01073af0;
                float width = InventorySelection::DAT_0104f754;
                m_pTiles[11]->Tile_Set(0xfa1, heightSlot1 + InventorySelection::DAT_01073ae8, 1);
                m_pTiles[11]->Tile_Set(0xfb1, width + InventorySelection::DAT_01073ae0, 1);
                m_pTiles[11]->Tile_Set(0xfb0, width + InventorySelection::DAT_01073ae0, 1);
            }
            else
            {
                m_pTiles[11]->Tile_Set(0xfa1, InventorySelection::DAT_01050280, 1);
                m_pTiles[11]->Tile_Set(0xfb1, InventorySelection::DAT_01072e3c, 1);
                m_pTiles[11]->Tile_Set(0xfb0, InventorySelection::DAT_01072e3c, 1);
            }
            m_pTiles[11]->Tile_SetChangeFlag(17);
            char path[260];
            InventorySelection::FUN_00406d30(path, 260, InventorySelection::DAT_0106eb24);
            unsigned int prefixLengthSlot0 = InventorySelection::BSstrlen(path);
            InventorySelection::FUN_00406d50(path, 260, InventorySelection::GetMenuIconName(InventorySelection::FUN_00479430(InventorySelection::DAT_011d9ea8->FUN_0044ddc0())));
            if (InventorySelection::BSstrlen(path) > prefixLengthSlot0)
            {
                (*reinterpret_cast<InventorySelection::TileHolder*>(m_pTiles[5])->tile.NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead())->Tile_Set_00a01350(0xfcc, path, 1);
                (*reinterpret_cast<InventorySelection::TileHolder*>(m_pTiles[5])->tile.NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead())->FUN_00700320(0xfa3, 1);
            }
            else
                (*reinterpret_cast<InventorySelection::TileHolder*>(m_pTiles[5])->tile.NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead())->FUN_00700320(0xfa3, 0);
            if (!m_kMenuData.GetVisible())
                m_pTiles[11]->FUN_00700320(0xfa3, 1);
            UpdateButtons();
        }
    }
    else if (action == 30)
    {
        ClearActionPointSource();
        m_pTiles[11]->Tile_Set_00a01350(0xfcc, InventorySelection::DAT_01073aac, 1);
        if (!m_kMenuData.GetVisible())
            m_pTiles[11]->FUN_00700320(0xfa3, 1);
        m_pTiles[6]->Tile_Set_00a01350(0xfc4, InventorySelection::DAT_011d5168->FUN_00403df0(), 1);
        m_pTiles[6]->FUN_00700320(0xfaf, 1);
    }
}

struct Form
{
    int FUN_00401170();
};
struct Extra
{
    bool ExtraDataList_HasWeaponMods();
};
struct ExtraNode
{
    Extra** FUN_006815c0();
};
struct Entry
{
    ~Entry();
    Form* FUN_0044ddc0();
    float ItemChange_GetItemHealth(bool);
    int FUN_00726070();
    ExtraNode* Modelloader_GetReferencedThis();
    bool ItemChange_GetWorn(bool);
    void* FUN_004459e0(int);
};
struct EntryListNode
{
    Entry* item;
    EntryListNode* next;
    EntryListNode();
    ~EntryListNode();
    Entry** FUN_006815c0();
    EntryListNode* FUN_00726070();
    void FUN_0063f7b0();
};
struct Changes
{
    void FilterInventoryChanges(Form*, EntryListNode*);
};
Changes* __cdecl FUN_004bf220(void*);
extern void* player;
float __cdecl FUN_00476b20(float);
struct InventoryCheck
{
    bool InventoryMenu_IsItemRepairable(Entry* entry);
};
// @fnv 0x00781860
// src: XBOX_PDB 0x00781860
bool InventoryCheck::InventoryMenu_IsItemRepairable(Entry* entry)
{
    bool result5 = false;
    Form* form4 = entry ? entry->FUN_0044ddc0() : 0;
    if (entry && FUN_00476b20(entry->ItemChange_GetItemHealth(true)) == 100.0)
        return result5;
    if (entry && form4 && (form4->FUN_00401170() == 40 || form4->FUN_00401170() == 24) &&
        entry->ItemChange_GetItemHealth(true) < 100.0)
    {
        if (entry->FUN_00726070() > 1)
            result5 = true;
        else
        {
            EntryListNode list6;
            Changes* changes = FUN_004bf220(player);
            Extra* originalExtra = entry->Modelloader_GetReferencedThis() ? *entry->Modelloader_GetReferencedThis()->FUN_006815c0() : 0;
            EntryListNode* cleanup = &list6;
            changes->FilterInventoryChanges(form4, &list6);
            for (EntryListNode* node9 = &list6; node9 && *node9->FUN_006815c0(); node9 = node9->FUN_00726070())
            {
                Form* otherForm2 = (*node9->FUN_006815c0())->FUN_0044ddc0();
                Extra* otherExtra8 = (*node9->FUN_006815c0())->Modelloader_GetReferencedThis()
                                         ? *(*node9->FUN_006815c0())->Modelloader_GetReferencedThis()->FUN_006815c0()
                                         : 0;
                if (!(*node9->FUN_006815c0())->ItemChange_GetWorn(false))
                {
                    if (otherForm2 != form4 ||
                        (FUN_00476b20((*node9->FUN_006815c0())->ItemChange_GetItemHealth(true)) < 100.0 &&
                         otherExtra8 != originalExtra && otherExtra8 && !otherExtra8->ExtraDataList_HasWeaponMods()))
                        result5 = true;
                }
            }
            while (cleanup && *cleanup->FUN_006815c0())
            {
                delete *cleanup->FUN_006815c0();
                cleanup->FUN_0063f7b0();
            }
        }
    }
    return result5;
}

struct ItemLabelSource : InventoryStackRecord
{
    int FUN_00726070();
    unsigned char FUN_004bd820();
    const char* GetTargetFullName();
    bool ItemChange_GetWorn(bool);
};

struct ItemLabelChildren
{
    Tile** FUN_007b5370();
    void* Modelloader_GetReferencedThis();
    Tile** AddEight(void*);
};

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// @fnv 0x00782850
void __cdecl UpdateItemLabel(Tile* tile, ItemLabelSource* item)
{
    char label[128];
    if (item)
    {
        if (item->FUN_00726070() > 1)
        {
            if (item->FUN_004bd820())
                _sprintf_s(label, 128, "%s+ (%d)", item->GetTargetFullName(), item->FUN_00726070());
            else
                _sprintf_s(label, 128, "%s (%d)", item->GetTargetFullName(), item->FUN_00726070());
            tile->Set(0xfc4, label, true);
        }
        tile->Set(0xfaa, 29);
        if (item->FUN_0044ddc0()->GetFormType() == 41 || item->FUN_0044ddc0()->GetFormType() == 24 ||
            item->FUN_0044ddc0()->GetFormType() == 40)
        {
            if (!g_thePlayer->PlayerCharacter_CanEquipOrUseObject(item))
                (*reinterpret_cast<ItemLabelChildren*>(&tile->m_kChildTileList)->FUN_007b5370())->Set(0xfa9, 127);
            else
                (*reinterpret_cast<ItemLabelChildren*>(&tile->m_kChildTileList)->FUN_007b5370())->Set(0xfa9, 255);
        }
        if (item->FUN_0044ddc0()->GetFormType() == 41 &&
            reinterpret_cast<TESObjectWEAP*>(g_thePlayer->Actor_GetCurrentWeapon()))
        {
            (*reinterpret_cast<ItemLabelChildren*>(&tile->m_kChildTileList)->AddEight(reinterpret_cast<ItemLabelChildren*>(&tile->m_kChildTileList)->Modelloader_GetReferencedThis()))
                ->Set(0xfa3,
                      static_cast<bool>(item && item->FUN_0044ddc0() ==
                                                    reinterpret_cast<TESBoundObject*>(
                                                        reinterpret_cast<TESObjectWEAP*>(g_thePlayer->Actor_GetCurrentWeapon())
                                                            ->GetCurrentAmmo(reinterpret_cast<Actor*>(g_thePlayer)))));
        }
        else
        {
            (*reinterpret_cast<ItemLabelChildren*>(&tile->m_kChildTileList)->AddEight(reinterpret_cast<ItemLabelChildren*>(&tile->m_kChildTileList)->Modelloader_GetReferencedThis()))
                ->Set(0xfa3, item && item->ItemChange_GetWorn(false) ? 1 : 0);
        }
    }
}

// 0x00780d60  unit_65921382d98c.cpp  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, no stack args (ret): menu refresh/close path.
extern "C" void* DAT_011d9ea8;
extern "C" int DAT_011d9ebc;

void* __fastcall Modelloader_GetReferencedThis(void* obj);
void __cdecl InventoryMenu_UpdateInventoryMenu();
void __cdecl InventoryMenu_AddToChangedItemsListIfWorn(void* tile, int index);

struct Sh006815c0
{
    void** FUN_006815c0();
};
struct InventoryEntryCountAccess
{
    void* FUN_00726070();
};

struct Sh004bddd0
{
    bool ItemChange_GetWorn(bool arg);
};

unsigned __cdecl FUN_0058db10(int arg);
unsigned __cdecl TESForm_GetFormByNumericID(int arg);

class SettingString
{
  public:
    const char* GetString();
};
extern "C" SettingString DAT_011d2af0;


// 0x00780d60 uses InventoryMenu offsets 0xB8/0x11C and AddHead at 0x005ae3d0; the shared class lacks this method.
// @fnv 0x00780d60
void __fastcall RefreshInventorySelection(InventoryMenu* menu)
{
    void* a = (void*)FUN_0044ddc0(DAT_011d9ea8);
    void* b = Modelloader_GetReferencedThis(DAT_011d9ea8) ? (void*)*((Sh006815c0*)Modelloader_GetReferencedThis(DAT_011d9ea8))->FUN_006815c0() : 0;

    if (static_cast<Menu*>(menu)->FUN_00726070()->IsTraitNonZero(DAT_011d9ebc))
    {
        menu->m_kItemList.ListBox_ItemChange_Traverse(InventoryMenu_AddToChangedItemsListIfWorn, 0, 0x7fffffff);
    }

    void* c = (void*)FUN_0044ddc0(DAT_011d9ea8);
    menu->m_kHotkeyObjects.AddHead(reinterpret_cast<TESBoundObject*&>(c));

    if ((FUN_0044ddc0(DAT_011d9ea8) == FUN_0058db10(0) || FUN_0044ddc0(DAT_011d9ea8) == TESForm_GetFormByNumericID(0xccef2)) &&
        g_thePlayer->GetActorValue(static_cast<ActorValue::Index>(0x10)) == g_thePlayer->GetPermanentActorValue(static_cast<ActorValue::Index>(0x10)))
    {
        InventoryInterface::ShowMessage(DAT_011d2af0.GetString(), 0, 0, 0, 2.0f, false);
    }
    else if (FUN_0044ddc0(DAT_011d9ea8) == FUN_0058db10(0x15) && !IsDrBagUsable())
    {
        InventoryInterface::ShowMessage(DAT_011d2af0.GetString(), 0, 0, 0, 2.0f, false);
    }
    else if (!((Sh004bddd0*)DAT_011d9ea8)->ItemChange_GetWorn(false))
    {
        g_thePlayer
            ->Actor_QueueEquipObject(static_cast<TESForm*>(a), (int)((InventoryEntryCountAccess*)DAT_011d9ea8)->FUN_00726070(), static_cast<ExtraDataList*>(b), false, false, true);
    }
    else
    {
        g_thePlayer
            ->QueueUnEquipObject(reinterpret_cast<int>(a), (int)((InventoryEntryCountAccess*)DAT_011d9ea8)->FUN_00726070(), reinterpret_cast<int>(b), false, false, true);
    }

done:
    InventoryMenu_UpdateInventoryMenu();
}

namespace fnv_00780140 {

class VTForm
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual bool IsDeleted();  // +0x94
    int FUN_00401170();
};

struct VTPoint3
{
    float x, y, z;
};

struct VTItemData
{
    bool ExtraDataList_GetCanNotWear();
    bool ExtraDataList_GetWorn(int iFlag);
};
struct VTItemNode
{
    VTItemData** FUN_006815c0();
};

class VTTarget
{
  public:
    VTForm* FUN_0044ddc0();
    Tile* FUN_00726070();
    VTItemNode* Modelloader_GetReferencedThis();
    float ItemChange_GetItemHealth(int iFlag);
    bool ItemChange_GetWorn(int iFlag);
};

class VTAction
{
  public:
    VTAction(VTForm* pkTargetNum, Tile* pkTile);
    int unk00;
    int unk04;
    int unk08;
};

struct VTActionList
{
    void FUN_006ecd40();
};
struct VTWeaponInfo
{
    bool HasEffect();
};

class VTProcess
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual VTWeaponInfo* GetWeaponInfo(int iHand);  // +0x148
    virtual VTActionList* GetActionList(int iFlag);  // +0x14c
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void PerformAction(VTAction* pkAction);  // +0x168
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void SetQueued(int iA, int iB, int iC);  // +0x580
};

struct VTWeapon
{
    bool GetByteAt384();
};
struct VTAnim;
// Inventory entry points not declared by the shared player hierarchy.
VTWeapon* __fastcall GetInventoryWeapon(PlayerCharacter*);
void PlayInventoryActorSound();
bool __fastcall CanDropInventoryItem(PlayerCharacter*);


struct VTCombat
{
    void AddItemExtraData(VTForm* pkTargetNum, Tile* pkTile, PlayerCharacter* pkPlayer, int iFlag, VTTarget* pkSource);
};

struct VTSetting
{
    float* Setting_Float_00403e20();
    const char* FUN_00403df0();
};
struct VTCounter
{
    int* Setting_Int();
};

struct VTSoundHandle
{
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~VTSoundHandle();
    bool FUN_00ad8830(bool bLoop);
};
class VTAudio
{
  public:
    static VTAudio* BSAudio_QInstance();
    VTSoundHandle BSAudio_GetSoundHandleByEditorName(const char* pcName, int iFlags);
};

extern VTTarget* DAT_011d9ea8;
extern int DAT_011d9eac;
extern int DAT_011d9ebc;
extern VTPoint3 DAT_011f426c;
extern VTSetting DAT_011db37c;
extern VTSetting DAT_011db458;
extern VTSetting DAT_011d47a4;
extern VTSetting DAT_011d22c8;
extern VTSetting DAT_011d43e4;
extern VTSetting DAT_011d31f8;
extern VTSetting DAT_011d3d30;
extern VTCounter DAT_011d2418;

void InventoryMenu_LoadPageState();
void InventoryMenu_SetKnobPosition(int iFlag);
int GetClassStatic();
void InterfaceManager_PlayMenuSound(int iMenu);
void RepairMenu_InitRepairMenu(VTTarget* pkTargetNum);
VTCombat* FUN_004bf220(PlayerCharacter* pkPlayer);
void ItemModMenu_InitItemModMenu(VTTarget* pkTargetNum, int iFlag);
bool InterfaceManager_Has360Controller();
void InventoryMenu_UpdateInventoryMenu();
void DispatchMessageToSink(const char* pcText, int iA, const char* pcIcon, const char* pcSound, float fTime, int iB);
void CreateQuantityMenu(Tile* pkTile, void (*pfnCallback)(int), int iMax);
void InventoryMenu_FilterFunc();
void UpdateItemLabel(Tile* pkTile);
void IsNotFormType2E();

}  // namespace fnv_00780140

// Dispatches mode changes and item actions.
// 0x00780140 uses InventoryMenu's tiles +0x28, tab +0x84, list +0xB8 and hotkeys +0xE8/+0x11C.
// @fnv 0x00780140
void InventoryMenu::Select(int m_uiSoundID, int pkTile)
{
    using namespace fnv_00780140;
    if (!pkTile && m_uiSoundID >= 0 && m_uiSoundID < 0x17)
        pkTile = reinterpret_cast<int>(m_pTiles[m_uiSoundID]);
    switch (m_uiSoundID)
    {
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
        if (m_iCurrentTab != m_uiSoundID - 0x18)
        {
            int iOldMode = m_iCurrentTab;
            if (FUN_00726070()->IsTraitNonZero(DAT_011d9eb8))
                FUN_00726070()->FUN_00700320(DAT_011d9eb8, 0);
            ClearActionPointSource();
            UpdateCurrentValue();
            m_iCurrentTab = m_uiSoundID - 0x18;
            m_pTiles[13]->FUN_00700320(DAT_011d9eac, m_iCurrentTab);
            ::InterfaceManager_GetSingleton()->GetPipboyManagerInstance()->StartBurst(*DAT_011db458.Setting_Float_00403e20(), *DAT_011db37c.Setting_Float_00403e20(), 0.5f);
            ::InterfaceManager_GetSingleton()->SetInventoryPageNumber(m_uiSoundID);
            m_kItemList.ApplyFilter(fnv_00780140::InventoryMenu_FilterFunc);
            m_kItemList.ListBox_ItemChange_Traverse(InventoryMenu_SetVisibleFunc, -1, 0x7fffffff);
            fnv_00780140::InventoryMenu_LoadPageState();
            fnv_00780140::InventoryMenu_SetKnobPosition(1);
        }
        if (m_uiSoundID == 0x18)
            m_pTiles[19]->FUN_00700320(0xfa3, 1);
        else if (m_uiSoundID == 0x1c)
        {
            ::InterfaceManager_GetSingleton()->kTutorialManager.ShowMessage(0x24, GetClassStatic(), 0x1f4);
            ((InventoryMenu*)DAT_011d9ea4)->m_kItemList.ListBox_ItemChange_Traverse(fnv_00780140::UpdateItemLabel, 0, 0x7fffffff);
        }
        else
        {
            if (m_uiSoundID == 0x19)
                ::InterfaceManager_GetSingleton()->kTutorialManager.ShowMessage(0x23, GetClassStatic(), 0x200);
            m_pTiles[19]->FUN_00700320(0xfa3, 0);
            m_pTiles[20]->FUN_00700320(0xfa3, 0);
            m_pTiles[22]->FUN_00700320(0xfa3, 0);
        }
        break;
    case 8:
        if (fnv_00780140::DAT_011d9ea8)
        {
            InterfaceManager_PlayMenuSound(0x24);
            UpdateCurrentValue();
            RepairMenu_InitRepairMenu(fnv_00780140::DAT_011d9ea8);
        }
        break;
    case 19:
        if (fnv_00780140::DAT_011d9ea8 && fnv_00780140::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 0x28)
        {
            InterfaceManager_PlayMenuSound(0x24);
            UpdateCurrentValue();
            if (fnv_00780140::DAT_011d9ea8->Modelloader_GetReferencedThis() && !*fnv_00780140::DAT_011d9ea8->Modelloader_GetReferencedThis()->FUN_006815c0())
            {
                VTCombat* pkCombat = FUN_004bf220((PlayerCharacter*)DAT_011dea3c);
                pkCombat->AddItemExtraData(fnv_00780140::DAT_011d9ea8->FUN_0044ddc0(), fnv_00780140::DAT_011d9ea8->FUN_00726070(),
                                           (PlayerCharacter*)DAT_011dea3c, 0, fnv_00780140::DAT_011d9ea8);
            }
            ItemModMenu_InitItemModMenu(fnv_00780140::DAT_011d9ea8, 1);
        }
        break;
    case 29:
        if (fnv_00780140::DAT_011d9ea8 && !FUN_00726070()->IsTraitNonZero(DAT_011d9eb8) &&
            fnv_00780140::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() != 0x29)
        {
            bool bResume = false;
            if (m_kMenuData.GetVisible())
            {
                if (!fnv_00780140::InterfaceManager_Has360Controller())
                {
                    if (fnv_00780140::DAT_011d9ea8 && fnv_00780140::DAT_011d9ea8->ItemChange_GetItemHealth(1) == 0.0)
                        DispatchMessageToSink(((VTSetting*)&DAT_011d3810)->FUN_00403df0(), 2, 0, "UIVATSInsufficientAP",
                                              2.0f, 0);
                    else if (!FUN_00726070()->IsTraitNonZero(fnv_00780140::DAT_011d9ebc) ||
                             fnv_00780140::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 0x19)
                        DispatchMessageToSink(((VTSetting*)&DAT_011d1e18)->FUN_00403df0(), 2, 0, "UIVATSInsufficientAP",
                                              2.0f, 0);
                    else
                    {
                        m_kMenuData.SetHotkeyItem(reinterpret_cast<InventoryStackRecord*>(fnv_00780140::DAT_011d9ea8));
                        m_kHotkeyObjects.AddHead(reinterpret_cast<TESBoundObject*>(fnv_00780140::DAT_011d9ea8->FUN_0044ddc0()));
                        fnv_00780140::InventoryMenu_UpdateInventoryMenu();
                    }
                }
            }
            else
            {
                RefreshInventorySelection(this);
                bResume = true;
            }
            if (bResume)
            {
                ((PlayerCharacter*)DAT_011dea3c)->PlayerCharacter_UpdatePlayer3d();
                reinterpret_cast<VTProcess*>(((PlayerCharacter*)DAT_011dea3c)->FUN_008d8520())->SetQueued(1, 0, 0);
                ((PlayerCharacter*)DAT_011dea3c)->Update();
            }
        }
        else if (fnv_00780140::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 0x29)
        {
            VTForm* pkTargetNum = fnv_00780140::DAT_011d9ea8->FUN_0044ddc0();
            if (!pkTargetNum || !FUN_00726070()->IsTraitNonZero(fnv_00780140::DAT_011d9ebc))
                break;
            VTAction* pkAction = new VTAction(fnv_00780140::DAT_011d9ea8->FUN_0044ddc0(), fnv_00780140::DAT_011d9ea8->FUN_00726070());
            VTProcess* pkProcess = reinterpret_cast<VTProcess*>(((PlayerCharacter*)DAT_011dea3c)->FUN_008d8520());
            VTWeapon* pkWeaponOut = GetInventoryWeapon((PlayerCharacter*)DAT_011dea3c);
            VTAnim* pkAnimOut = reinterpret_cast<VTAnim*>(((PlayerCharacter*)DAT_011dea3c)->Actor_GetCurrentWeapon());
            pkProcess->PerformAction(pkAction);
            pkProcess->GetActionList(0)->FUN_006ecd40();
            reinterpret_cast<void (__thiscall*)(PlayerCharacter*, VTForm*, int, int)>(&PlayInventoryActorSound)((PlayerCharacter*)DAT_011dea3c, fnv_00780140::DAT_011d9ea8->FUN_0044ddc0(), 1, 0);
            int iType = (pkWeaponOut && !pkWeaponOut->GetByteAt384()) ? 0 : 2;
            bool bLeft = pkProcess->GetWeaponInfo(2)->HasEffect();
            reinterpret_cast<void (__thiscall*)(PlayerCharacter*, VTAnim*, int, bool, int)>((*reinterpret_cast<void***>(DAT_011dea3c))[0xFB])((PlayerCharacter*)DAT_011dea3c, pkAnimOut, iType, bLeft, 0);
            m_kHotkeyObjects.AddHead(reinterpret_cast<TESBoundObject*>(fnv_00780140::DAT_011d9ea8->FUN_0044ddc0()));
            fnv_00780140::InventoryMenu_UpdateInventoryMenu();
        }
        break;
    case 30:
        if (!m_kMenuData.GetVisible())
        {
            UpdateCurrentValue();
            FUN_00726070()->FUN_00700320(DAT_011d9eb8, 1);
            m_kItemList.ApplyFilter(fnv_00780140::IsNotFormType2E);
            m_kItemList.ListBox_ItemChange_Traverse(InventoryMenu_SetVisibleFunc, -1, 0x7fffffff);
            ClearActionPointSource();
            fnv_00780140::InventoryMenu_LoadPageState();
        }
        else
            DispatchMessageToSink(((VTSetting*)&DAT_011d1e18)->FUN_00403df0(), 0,
                                  "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                                  "UIVATSInsufficientAP", 2.0f, 0);
        break;
    case 10:
        UpdateCurrentValue();
        FUN_00726070()->FUN_00700320(DAT_011d9eb8, 0);
        m_kItemList.ApplyFilter(fnv_00780140::InventoryMenu_FilterFunc);
        m_kItemList.ListBox_ItemChange_Traverse(InventoryMenu_SetVisibleFunc, -1, 0x7fffffff);
        fnv_00780140::InventoryMenu_LoadPageState();
        break;
    case 7:
        if (fnv_00780140::DAT_011d9ea8)
        {
            VTPoint3 kPos = DAT_011f426c;
            VTForm* pkRefOut = fnv_00780140::DAT_011d9ea8->FUN_0044ddc0();
            VTItemData* pkItem = fnv_00780140::DAT_011d9ea8->Modelloader_GetReferencedThis() ? *fnv_00780140::DAT_011d9ea8->Modelloader_GetReferencedThis()->FUN_006815c0() : 0;
            if (FUN_00726070()->IsTraitNonZero(DAT_011d9eb8))
                VTAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByEditorName("UIVATSInsufficientAP", 0x121).FUN_00ad8830(false);
            else if (pkRefOut->IsDeleted())
                DispatchMessageToSink(DAT_011d47a4.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else if (((PlayerCharacter*)DAT_011dea3c)->GetAnimAction_008a7570() != -1 && fnv_00780140::DAT_011d9ea8->ItemChange_GetWorn(0))
                DispatchMessageToSink(DAT_011d22c8.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else if (CanDropInventoryItem((PlayerCharacter*)DAT_011dea3c))
                DispatchMessageToSink(DAT_011d43e4.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else if (pkItem && pkItem->ExtraDataList_GetCanNotWear() && pkItem->ExtraDataList_GetWorn(0))
                DispatchMessageToSink(DAT_011d31f8.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else if (!((PlayerCharacter*)DAT_011dea3c)->PlayerCharacter_GetDropPoint(reinterpret_cast<TESBoundObject*>(pkRefOut), reinterpret_cast<InventoryDropPoint*>(&kPos), 1, 1))
                DispatchMessageToSink(DAT_011d3d30.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else
            {
                if ((int)fnv_00780140::DAT_011d9ea8->FUN_00726070() > *DAT_011d2418.Setting_Int())
                    CreateQuantityMenu(fnv_00780140::DAT_011d9ea8->FUN_00726070(), DropInventoryItem, 0x7fffffff);
                else
                    DropInventoryItem(1);
                ((PlayerCharacter*)DAT_011dea3c)->PlayerCharacter_UpdatePlayer3d();
                reinterpret_cast<VTProcess*>(((PlayerCharacter*)DAT_011dea3c)->FUN_008d8520())->SetQueued(1, 0, 0);
                ((PlayerCharacter*)DAT_011dea3c)->Update();
            }
        }
    }
}


struct FilterForm
{
    int FUN_00401170();
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual bool IsQuestItem();
};
bool __cdecl TESContainer_IsGold(FilterForm*);
unsigned char __fastcall GetInventoryFilterFlag(PlayerCharacter*);
struct FilterList
{
    int GetConditionIndex(FilterForm*);
};
extern int DAT_010722f4;
FilterList* __cdecl FUN_00483a00(int*);

// Returns whether a form fails the current tab's checks, including type, item, and condition-index checks.
// @fnv 0x00782620
// src: COMMUNITY 0x00782620
bool __cdecl InventoryMenu_FilterFunc(Entry* entry)
{
    if (DAT_011d9ea4)
    {
        FilterForm* form4 = entry ? (FilterForm*)entry->FUN_0044ddc0() : 0;
        int tab3 = ((InventoryMenu*)DAT_011d9ea4)->m_iCurrentTab + 24;
        if (!form4)
            return tab3 != 27;
        int type = form4->FUN_00401170();
        TESBipedModelForm* biped3 = TESBipedModelForm::GetFormAsBipedModel((TESForm*)form4);
        if ((biped3 && !biped3->TESBipedModelForm_GetPlayable()) || TESContainer_IsGold(form4) ||
            (form4->IsQuestItem() && !GetInventoryFilterFlag(reinterpret_cast<PlayerCharacter*>(DAT_011dea3c))) || type == 46)
            return true;
        switch (tab3)
        {
        case 24:
            return type != 40;
        case 25:
            return type != 24 && type != 26;
        case 26:
            return type != 29 && type != 47 && type != 25;
        case 27:
            return type == 40 || type == 24 || type == 26 || type == 29 || type == 47 || type == 41 || type == 25;
        case 28:
            if (type != 41)
                return true;
            else
            {
                FilterList* list = FUN_00483a00(&DAT_010722f4);
                FilterForm* item = form4;
                if (list && list->GetConditionIndex(item) >= 0)
                    return true;
                return false;
            }
        }
    }
    return true;
}

struct FUN_0073ac90_shell
{
    Tile** __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead();
};

// Clears the static action point source and resets several inventory menu tiles and a related tile to 0.
// @fnv 0x00781b10
void Menu::ClearActionPointSource()
{
    InventoryMenu::ms_pActionPointSource = 0;

    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[12]->Set(0xFA3, 0);
    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[11]->Set(0xFA3, 0.0f, false);
    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[20]->Set(0xFA3, 0.0f, false);
    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[22]->Set(0xFA3, 0);

    (*reinterpret_cast<FUN_0073ac90_shell*>(
          reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x3C)) + 4)
          ->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead())
        ->Set(0xFA3, 0);

    reinterpret_cast<InventoryMenu*>(this)->UpdateButtons();
}
