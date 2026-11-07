#include "../../../include/BSSimpleArray.h"
// fallout/interface/menumanager.cpp: MenuSystem, TutorialMenu, QuantityMenu, StatsMenu and more (50 functions)

#include "../../../include/Menu.h"
#include "../../../include/InventoryMenu.h"
#include "../../../include/VATSMenu.h"
#include "../../../include/BlackJackMenu.h"
#include "../../../include/BookMenu.h"
#include "../../../include/SleepWaitMenu.h"
#include "../../../include/StatsMenu.h"
#include "../../../include/TutorialMenu.h"
#include "../../../include/CharGenMenu.h"
#include "../../../include/Tile.h"
#include "../../../include/RepairServicesMenu.h"
#include "../../../include/SlotMachineMenu.h"
#include "../../../include/RepairMenu.h"
#include "../../../include/RecipeMenu.h"
#include "../../../include/QuantityMenu.h"
#include "../../../include/ComputersMenu.h"
#include "../../../include/LockPickMenu.h"
#include "../../../include/TraitMenu.h"
#include "../../../include/TraitSelectMenu.h"
#include "../../../include/TextEditMenu.h"
#include "../../../include/SurgeryMenu.h"

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
int __cdecl Warning(const char*, ...);
class MenuSystem
{
  public:
    MenuSystem();
    static MenuSystem* Instance(bool create);
    Menu* GetMenuById(int menuClass);
    void ResizeMenuByClassArray();
};
extern MenuSystem* DAT_011d8d54;
class ActorCombatGroup;
template <class T> class NiTMallocInterface;
#include "../../../include/NiTArray.h"
class MenuClassArray : public NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> >
{
};
extern MenuClassArray g_menuByClassArray;
// GetMenuById (0x0071e420): each case's class is the one whose vftable its ctor installs (RTTI), at the size it allocates.
#include "../../../include/ActorValueOwner.h"
#include "../../../include/BSThread.h"
#include "../../../include/BaseFormComponent.h"
#include "../../../include/CachedValuesOwner.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/TESChildCell.h"
#include "../../../include/BarterMenu.h"
#include "../../../include/CaravanMenu.h"
#include "../../../include/CompanionWheelMenu.h"
#include "../../../include/MessageMenu.h"
#include "../../../include/HackingMenu.h"
#include "../../../include/ItemModMenu.h"
#include "../../../include/LevelUpMenu.h"
#include "../../../include/LoveTesterMenu.h"
#include "../../../include/RouletteMenu.h"
#include "../../../include/CreditsMenu.h"
#include "../../../include/HUDMainMenu.h"
#include "../../../include/LoadingMenu.h"
#include "../../../include/ContainerMenu.h"
#include "../../../include/DialogMenu.h"
#include "../../../include/StartMenu.h"
#include "../../../include/SPECIALBookMenu.h"
#include "../../../include/RaceSexMenu.h"
#include "../../../include/MapMenu.h"
#include "../../../include/CombatManager.h"

// Creates and returns a new menu instance matching the given menu class, warning and returning 0 for unknown classes.
// @fnv 0x0071e420
Menu* MenuSystem::GetMenuById(int menuClass)
{
    switch (menuClass)
    {
    case 1047:
        return new CreditsMenu;
    case 1001:
        return new MessageMenu;
    case 1059:
        return new TutorialMenu;
    case 1023:
        return new MapMenu;
    case 1002:
        return new InventoryMenu;
    case 1003:
        return new StatsMenu;
    case 1004:
        return new HUDMainMenu;
    case 1007:
        return new LoadingMenu;
    case 1008:
        return new ContainerMenu;
    case 1053:
        return new BarterMenu;
    case 1009:
        return new DialogMenu;
    case 1012:
        return new SleepWaitMenu;
    case 1013:
        return new StartMenu;
    case 1014:
        return new LockPickMenu;
    case 1016:
        return new QuantityMenu;
    case 1026:
        return new BookMenu;
    case 1027:
        return new LevelUpMenu;
    case 1036:
        return new RaceSexMenu;
    case 1035:
        return new RepairMenu;
    case 1061:
        return new ItemModMenu;
    case 1058:
        return new RepairServicesMenu;
    case 1055:
        return new HackingMenu;
    case 1057:
        return new ComputersMenu;
    case 1054:
        return new SurgeryMenu;
    case 1056:
        return new VATSMenu;
    case 1048:
        return new CharGenMenu;
    case 1060:
        return new SPECIALBookMenu;
    case 1075:
        return new CompanionWheelMenu;
    case 1074:
        return new LoveTesterMenu;
    case 1076:
        return new TraitSelectMenu;
    case 1080:
        return new SlotMachineMenu;
    case 1081:
        return new BlackJackMenu;
    case 1084:
        return new TraitMenu;
    case 1082:
        return new RouletteMenu;
    case 1083:
        return new CaravanMenu;
    case 1077:
        return new RecipeMenu;
    case 1051:
        return new TextEditMenu;
    default:
        Warning("MENUS: Unknown menu class!");
        return 0;
    }
}

// Returns the singleton instance, creating it and calling ResizeMenuByClassArray on first request when create is true.
// @fnv 0x0071e290
MenuSystem* MenuSystem::Instance(bool create)
{
    if (create && !DAT_011d8d54)
    {
        DAT_011d8d54 = new MenuSystem;
        DAT_011d8d54->ResizeMenuByClassArray();
        return DAT_011d8d54;
    }
    else
        return DAT_011d8d54;
}

// @fnv 0x0071e400
void MenuSystem::ResizeMenuByClassArray()
{
    g_menuByClassArray.SetSize(84);
}

// @fnv 0x0071e340
MenuSystem::MenuSystem()
{
    ResizeMenuByClassArray();
}

struct FUN_006317a0_struct
{
    int AddEight(int param_1);
};

// @fnv 0x006317a0
int FUN_006317a0_struct::AddEight(int aiValue)
{
    return aiValue + 8;
}

struct FUN_0071e3e0_shell
{
    void ForwardCall_0071e3e0();
};

void Menumanager_ClearDAT011d8d54();

// @fnv 0x0071e3e0
// src: GUESS 0x0071e3e0 (confidence: low)
void FUN_0071e3e0_shell::ForwardCall_0071e3e0()
{
    Menumanager_ClearDAT011d8d54();
}

// @fnv 0x0071e3f0
// src: GUESS 0x0071e3f0 (confidence: low)
void Menumanager_ClearDAT011d8d54()
{
    DAT_011d8d54 = 0;
}


// Calls FUN_0071f700, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x0071f6d0
void* StatsMenu::FUN_0071f6d0(unsigned int flags)
{
    FUN_0071f700();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0071feb0_shell
{
    int __thiscall SurgeryMenu_GetClass();
};

// @fnv 0x0071feb0
// src: COMMUNITY 0x0071feb0
int __thiscall FUN_0071feb0_shell::SurgeryMenu_GetClass()
{
    return 0x41e;
}

struct FUN_00720100_shell
{
    int __thiscall VATSMenu_GetClass();
};

// @fnv 0x00720100
// src: COMMUNITY 0x00720100
int __thiscall FUN_00720100_shell::VATSMenu_GetClass()
{
    return 0x420;
}

struct FUN_00720320_shell
{
    int GetClass();
};

// @fnv 0x00720320
int FUN_00720320_shell::GetClass()
{
    return 0x424;
}

struct FUN_00720760_shell
{
    int LoveTesterMenu_GetMenuID();
};

// @fnv 0x00720760
// src: COMMUNITY 0x00720760
int FUN_00720760_shell::LoveTesterMenu_GetMenuID()
{
    return 0x432;
}

// @fnv 0x00720df0
// src: XBOX_PDB 0x00720df0
int __cdecl MapMenu_GetClassStatic()
{
    return 0x3ff;
}

int GetTileValueID(const char*, int);
int __fastcall GetRaceCount(char*);
// 0x00726710 counts a list at +0x04 and reads its tile at +0x0c; this is a list-box helper.
struct FilteredListCounter
{
    char pad[0xc];
    Tile* tile;
    unsigned int GetUnfilteredRaceCount();
};
// Returns the result of GetRaceCount on this minus tile's float value at the _num_filtered setting.
// @fnv 0x00726710
// src: GUESS 0x00726710 (confidence: medium)
unsigned int FilteredListCounter::GetUnfilteredRaceCount()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);
    return GetRaceCount((char*)this) - (unsigned int)tile->GetFloat(numFiltered);
}

struct NiNode;
extern NiPointer<NiNode> g_011dadb4;
extern NiPointer<NiNode> g_011dade8;
extern NiPointer<NiNode> g_011dae5c;
struct FUN_0071fef0 : public Menu
{
    Tile* tile028;
    Tile* tile02C;
    Tile* tile030;
    Tile* tile034;
    Tile* tile038;
    Tile* tile03C;
    Tile* tile040;
    Tile* tile044;
    Tile* tile048;
    Tile* tile04C;
    Tile* tile050;
    Tile* tile054;
    Tile* tile058;
    Tile* tile05C;
    Tile* tile060;
    Tile* tile064;
    Tile* tile068;
    Tile* tile06C;
    Tile* tile070;
    Tile* tile074;
    Tile* tile078;
    Tile* tile07C;
    Tile* tile080;
    Tile* tile084;
    Tile* tile088;
    Tile* tile08C;
    Tile* tile090;
    BSSoundHandle kSound094;
    BSSoundHandle kSound0A0;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    NiPointer<NiNode> spNodes[6];
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    NiPointer<NiNode> spNode0F0;
    NiPointer<NiNode> spNode0F4;
    virtual ~FUN_0071fef0();
};
// Clears the global NiNode pointers and the menu's spNode0F0 pointer by assigning null to them.
// @fnv 0x0071fef0
FUN_0071fef0::~FUN_0071fef0()
{
    g_011dadb4 = 0;
    g_011dade8 = 0;
    g_011dae5c = 0;
    spNode0F0 = 0;
}

class NiNode;
namespace fnv_00720170 {
void* memset(void*, int, unsigned int);
struct FUN_007203c0
{
    FUN_007203c0();
    ~FUN_007203c0();
    Tile* pTile;
    Tile* pLabel;
    Tile* pValue;
    unsigned int uiIndex;
    float fValue;
    float fMin;
    float fScaledValue;
    unsigned int uiFlags;
};
struct FUN_00720170_t : public Menu
{
    Tile* m_pTiles[8];
    int iSelected;
    int iCount;
    float fScroll;
    bool m_bDecalsEnabled;
    void* pTarget;
    void* pCurrent;
    FUN_007203c0 kEntries[9];
    NiPointer<NiNode> spNodes180[11];
    NiPointer<NiNode> spNodes1AC[4];
    NiPointer<NiNode> spNodes1BC[2];
    NiPointer<NiNode> spNodes1C4[2];
    NiPointer<NiNode> spNodes1CC[2];
    NiPointer<NiNode> spNodes1D4[2];
    NiPointer<NiNode> spNodes1DC[2];
    FUN_00720170_t();
    virtual ~FUN_00720170_t();
};
// Zeroes the tile array and initializes the menu's selection, count, scroll, and target pointers.
// @fnv 0x00720170
FUN_00720170_t::FUN_00720170_t()
{
    fnv_00720170::memset(m_pTiles, 0, sizeof(m_pTiles));
    pCurrent = 0;
    iSelected = 0;
    iCount = 1;
    fScroll = 0.0f;
    m_bDecalsEnabled = true;
    pTarget = 0;
}
}  // namespace fnv_00720170

class NiNode;
namespace fnv_00720420 {
struct FUN_007203c0
{
    ~FUN_007203c0();
    Tile* pTile;
    Tile* pLabel;
    Tile* pValue;
    unsigned int uiIndex;
    float fValue;
    float fMin;
    float fScaledValue;
    unsigned int uiFlags;
};
struct FUN_00720420 : public Menu
{
    Tile* tile028;
    Tile* tile02C;
    Tile* tile030;
    Tile* tile034;
    Tile* tile038;
    Tile* tile03C;
    Tile* tile040;
    Tile* tile044;
    Tile* tile048;
    Tile* tile04C;
    Tile* tile050;
    Tile* tile054;
    Tile* tile058;
    Tile* tile05C;
    FUN_007203c0 kEntries[9];
    NiPointer<NiNode> spNodes180[11];
    NiPointer<NiNode> spNodes1AC[4];
    NiPointer<NiNode> spNodes1BC[2];
    NiPointer<NiNode> spNodes1C4[2];
    NiPointer<NiNode> spNodes1CC[2];
    NiPointer<NiNode> spNodes1D4[2];
    NiPointer<NiNode> spNodes1DC[2];
    virtual ~FUN_00720420();
};
// Empty destructor for the menu class; the compiler-generated member destructors run implicitly.
// @fnv 0x00720420
FUN_00720420::~FUN_00720420()
{}
}  // namespace fnv_00720420

class NiNode;
namespace fnv_00720860 {
struct FUN_00723fd0
{
    ~FUN_00723fd0();
    void* pHead;
    void* pNext;
    unsigned int ItemUpdateArray;
    unsigned int uiFlags;
};
struct FUN_00724020
{
    ~FUN_00724020();
    void* pHead;
    void* pNext;
    unsigned int ItemUpdateArray;
    unsigned int uiFlags;
};
struct FUN_00720800
{
    ~FUN_00720800();
    Tile* pTile;
    Tile* pLabel;
    Tile* pValue;
    unsigned int uiIndex;
    float fValue;
    float fMin;
    float fScaledValue;
    unsigned int uiFlags;
};
struct FUN_00720860 : public Menu
{
    Tile* tile028;
    Tile* tile02C;
    Tile* tile030;
    Tile* tile034;
    Tile* tile038;
    Tile* tile03C;
    Tile* tile040;
    Tile* tile044;
    Tile* tile048;
    Tile* tile04C;
    Tile* tile050;
    Tile* tile054;
    Tile* tile058;
    Tile* tile05C;
    Tile* tile060;
    FUN_00723fd0 kList064;
    FUN_00724020 kList074;
    FUN_00720800 kEntries[9];
    FUN_00720800 kEntry1A4;
    NiPointer<NiNode> spNodes1C4[11];
    NiPointer<NiNode> spNodes1F0[4];
    NiPointer<NiNode> spNodes200[2];
    NiPointer<NiNode> spNodes208[2];
    NiPointer<NiNode> spNodes210[2];
    NiPointer<NiNode> spNodes218[2];
    NiPointer<NiNode> spNodes220[2];
    NiPointer<NiNode> spNodes228[2];
    virtual ~FUN_00720860();
};
// Destructor for the menu class; the body is empty and member destructors run implicitly.
// @fnv 0x00720860
FUN_00720860::~FUN_00720860()
{}
}  // namespace fnv_00720860

class RecursiveLock;
class NiAVObject;
class NiNode;
class TileShaderProperty;
class TESObjectREFR;
namespace fnv_00720e60 {
struct MenuValueDescriptor;
struct FUN_00720e60_shell : public MenuSystem
{
    Menu* FindTopMenu();
};

struct FUN_006317a0_struct
{
    int AddEight(int);
};
struct IMH;
IMH* __cdecl InterfaceManager_GetSingleton(void);
struct IMH
{
    Tile* CombatController_GetCombatState();
};
struct Flt
{
    operator unsigned int() const;
};
// Unit-local view of NiTPointerList for 0x00720e60 (namespace fnv_00720e60): built on the shared NiTPointerList, that code does not compile or does not match.
template <class T> struct NiTPointerList_00720e60
{
    void* DereferenceIfNotNull(void*) const;
};

// @fnv 0x00720e60
Menu* FUN_00720e60_shell::FindTopMenu()
{
    Menu* ptop = 0;
    float fMaxDepth = -100000000.0f;
    void* pListElem = (void*)(unsigned int)*(Flt*)((char*)InterfaceManager_GetSingleton()->CombatController_GetCombatState() + 4);
    while (pListElem)
    {
        Tile* pmenutile =
            *(Tile**)((FUN_006317a0_struct*)((char*)InterfaceManager_GetSingleton()->CombatController_GetCombatState() + 4))->AddEight((int)pListElem);
        Menu* pmenu = 0;
        if (pmenutile)
            pmenu = pmenutile->GetMenu();
        if (pmenu && pmenu->FUN_00726070())
        {
            if (pmenu->FUN_00726070()->GetFloat(0xfad) > fMaxDepth &&
                pmenu->FUN_00726070()->GetFloat(0xfa7) != 6008.0 &&
                pmenu->GetVisibilityState() != 2 && pmenu->GetVisibilityState() != 4)
            {
                fMaxDepth = pmenu->FUN_00726070()->GetFloat(0xfad);
                ptop = pmenu;
            }
        }
        pListElem = ((NiTPointerList_00720e60<TESObjectREFR*>*)((char*)InterfaceManager_GetSingleton()->CombatController_GetCombatState() + 4))
                        ->DereferenceIfNotNull(pListElem);
    }
    return ptop;
}
}  // namespace fnv_00720e60

struct ListBoxItem_t
{
    Tile* pTile;
    void* pObject;
    bool m_bFiltered;
};
struct FUN_004ee7d0_node
{
    ListBoxItem_t* pItem;
    FUN_004ee7d0_node* pNext;
    ListBoxItem_t** FUN_006815c0();
    FUN_004ee7d0_node* FUN_00726070();
};
struct ListBoxBase_t
{
    virtual ~ListBoxBase_t();
};
struct FUN_007254d0_t : public ListBoxBase_t, public FUN_004ee7d0_node
{
    Tile* pParentTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float fTotalHeight;
    void ListBox_StatsMenu_StatusEffect_Synchronize();
    void UpdateState_00725970();
    void UpdateSpeechChallengeTrait();
    void AccumulateTileHeight(Tile*);
};

// @fnv 0x007254d0
// src: COMMUNITY 0x007254d0
void FUN_007254d0_t::ListBox_StatsMenu_StatusEffect_Synchronize()
{
    usItemCount = 0;
    fTotalHeight = 0.0f;
    FUN_004ee7d0_node* pnode;
    for (pnode = this; pnode && *pnode->FUN_006815c0(); pnode = pnode->FUN_00726070())
    {
        if (!(*pnode->FUN_006815c0())->m_bFiltered)
        {
            (*pnode->FUN_006815c0())->pTile->Set(0xfac, usItemCount++);
            AccumulateTileHeight((*pnode->FUN_006815c0())->pTile);
        }
    }
    UpdateState_00725970();
    UpdateSpeechChallengeTrait();
}

namespace fnv_00726530 {
float __cdecl FUN_004e4430(float);
int __cdecl BSMAX_00647b70(int, int);
struct ListBoxBase_t
{
    virtual ~ListBoxBase_t();
};
struct BSSimpleList_t
{
    void* pItem;
    BSSimpleList_t* pNext;
};
struct FUN_00726530_t : public ListBoxBase_t, public BSSimpleList_t
{
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    void ListBox_unsigned_int_SetTotalListHeight();
    unsigned int GetFilteredCount();
};

// @fnv 0x00726530
// src: XBOX_PDB 0x00726530
void FUN_00726530_t::ListBox_unsigned_int_SetTotalListHeight()
{
    if (m_pListTile)
    {
        float flistHeight = m_pListTile->GetFloat(0xfb0);
        int inumPages = 1;
        if (m_fFirstListValue > 0.0 && flistHeight > 0.0)
        {
            if (m_fFirstListValue > flistHeight)
                inumPages = BSMAX_00647b70(
                    (int)FUN_004e4430(GetFilteredCount() * (m_fFirstListValue - flistHeight) / m_fFirstListValue) + 1,
                    2);
            if (inumPages > 1)
                m_pListTile->Set(Tile::GetTraitID("_scroll_delta"), (m_fFirstListValue - flistHeight) / (inumPages - 1),
                                 true);
        }
        if (m_pHighlightedTile)
            m_pHighlightedTile->Set(Tile::GetTraitID("_number_of_items"), inumPages);
    }
}
}  // namespace fnv_00726530

class NiNode;
namespace fnv_007b8d30 {
// Unit-local view of NiPointer for 0x007b8d30 (namespace fnv_007b8d30): built on the shared NiPointer, that code does not compile or does not match.
template <class T> class NiPointer_007b8d30
{
  public:
    NiPointer_007b8d30(T* pObject = 0);
    ~NiPointer_007b8d30();
    T* m_pObject;
};
struct FUN_007b9000
{
    FUN_007b9000();
    ~FUN_007b9000();
    Tile* m_pTiles[25];
};
struct PC7d
{
    void* GetField630();
};
extern PC7d* g_thePlayer;
int GetTileValueID(const char*, int);
extern int DAT_011da86c;
extern int DAT_011da870;
struct FUN_007b8d30_t : public Menu
{
    int iMode;
    Tile* m_pTiles[11];
    int m_iEntryCount;
    FUN_007b9000 kEntries[159];
    BSSimpleList<void*>* pList;
    Tile* pEntryTiles[61];
    int iSelected;
    Tile* pTile3F74;
    Tile* pTile3F78;
    NiPointer_007b8d30<NiNode> m_pController;
    Tile* pTiles3F80[4];
    float fScrollX;
    float fScrollY;
    Tile* pTiles3F98[15];
    float fPosX;
    float fPosY;
    float fPosZ;
    int iValue3FE0;
    int iValue3FE4;
    int iValue3FE8;
    int iValue3FEC;
    int iValue3FF0;
    int iValue3FF4;
    int iValue3FF8;
    int iValue3FFC;
    int iValue4000;
    int iValue4004;
    int iValue4008;
    bool bFlag400C;
    bool bFlag400D;
    void* pPlayerData;
    FUN_007b8d30_t();
    virtual ~FUN_007b8d30_t();
};
// @fnv 0x007b8d30
FUN_007b8d30_t::FUN_007b8d30_t()
{
    DAT_011da870 = GetTileValueID("_Value", -1);
    DAT_011da86c = GetTileValueID("_X", -1);
    pList = new BSSimpleList<void*>;
    iMode = 4;
    iSelected = 0;
    bFlag400D = false;
    m_iEntryCount = 0;
    fPosX = 0.0f;
    fPosY = 0.0f;
    fPosZ = 0.0f;
    iValue3FE0 = 0;
    iValue3FE4 = 0;
    iValue3FE8 = 0;
    iValue3FFC = 0;
    iValue3FEC = 0;
    iValue3FF0 = 0;
    iValue3FF4 = 0;
    iValue3FF8 = 0;
    fScrollX = 0.0f;
    fScrollY = 0.0f;
    pPlayerData = g_thePlayer->GetField630();
}
}  // namespace fnv_007b8d30

namespace fnv_0071e3b0 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_0071e3e0_shell
{
    void ForwardCall_0071e3e0();
};

struct FUN_0071e3b0_shell : FUN_0071e3e0_shell
{
    void* FUN_0071e3b0(unsigned int flags);
};

// Calls FUN_0071e3e0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x0071e3b0
void* FUN_0071e3b0_shell::FUN_0071e3b0(unsigned int flags)
{
    ForwardCall_0071e3e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0071e3b0

struct FUN_0071f2d0_shell
{
    int TutorialMenu_GetMenuID();
};

// @fnv 0x0071f2d0
// src: COMMUNITY 0x0071f2d0
int __thiscall FUN_0071f2d0_shell::TutorialMenu_GetMenuID()
{
    return 0x423;
}

struct FUN_00720330_shell
{
    void* FUN_00720330(unsigned int flags);
    void FUN_00720420();
};

void __cdecl _Deallocate(void* p);

// @fnv 0x00720330
void* FUN_00720330_shell::FUN_00720330(unsigned int flags)
{
    FUN_00720420();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00720770_shell
{
    void* FUN_00720770(unsigned int flags);
    void* FUN_00720860();
};

void __cdecl _Deallocate(void*);

// Calls FUN_00720860, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00720770
void* FUN_00720770_shell::FUN_00720770(unsigned int flags)
{
    FUN_00720860();
    if (flags & 1)
        _Deallocate(this);
    return this;
}


// @fnv 0x007209e0
void TutorialMenu::SetTile(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 8)
        m_pTiles[aiID] = apTile;
}

// @fnv 0x00720a30
// src: COMMUNITY 0x00720a30
int QuantityMenu::GetMenuID_00720a30()
{
    return 0x3f8;
}

struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct BGSExplosion;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct CombatCoverMap;
struct ActorCombatGroup;
struct CombatTargetMap;
struct CombatThreatMap;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
class NiMatrix3;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
typedef char _sizecheck_CombatManager[sizeof(CombatManager) == 60 ? 1 : -1];
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
struct FUN_008d0300_shell : public CombatManager
{
    bool Actor_CheckAttackDisarm(Actor*, Actor*);
};

// @fnv 0x008d0300
// src: XBOX_PDB 0x008d0300
bool FUN_008d0300_shell::Actor_CheckAttackDisarm(Actor* apAttacker, Actor* apTarget)
{
    return false;
}

struct S0071e3b0
{
    void* FUN_0071e3b0(int);
};
// If DAT_011d8d54 is set, calls its FUN_0071e3b0(1) method and then clears DAT_011d8d54.
// @fnv 0x0071e360
// src: COMMUNITY 0x0071e360
void MenuManager_Free()
{
    if (DAT_011d8d54)
    {
        S0071e3b0* p1 = (S0071e3b0*)DAT_011d8d54;
        S0071e3b0* p2 = p1;
        void* r;
        if (p2)
            r = p2->FUN_0071e3b0(1);
        else
            r = 0;
        DAT_011d8d54 = 0;
    }
}

void __cdecl _Deallocate(void*);
// Calls DestroyMenu, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0071f2e0
void* TutorialMenu::DestroyTutorialMenu(unsigned int flags)
{
    DestroyMenu();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void _Deallocate(void*);
struct S0071f670
{
    void FUN_0071f570();
    void* FUN_0071f670(unsigned int);
};
// Calls FUN_0071f570, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0071f670
void* S0071f670::FUN_0071f670(unsigned int flags)
{
    FUN_0071f570();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct StatusEffectList
{
    void FUN_0071f600();
    void* FUN_0071f6a0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_0071f600, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0071f6a0
void* StatusEffectList::FUN_0071f6a0(unsigned int flags)
{
    FUN_0071f600();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0071fec0 {
struct FUN_0071fef0
{
    virtual ~FUN_0071fef0();
    void* FUN_0071fec0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0071fec0
void* FUN_0071fef0::FUN_0071fec0(unsigned int flags)
{
    this->FUN_0071fef0::~FUN_0071fef0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0071fec0

struct FUN_00720010_shell
{
    int SurgeryMenu_GetIndex(int a);
};
// Returns a-1 when a is in 1..0x12, otherwise returns 0x12.
// @fnv 0x00720010
// src: XBOX_PDB 0x00720010
int FUN_00720010_shell::SurgeryMenu_GetIndex(int aiValue)
{
    return (aiValue > 0 && aiValue <= 0x12) ? aiValue - 1 : 0x12;
}

struct Cls_720110
{
    void FUN_007e9130();
    void* FUN_00720110(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_007e9130, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00720110
void* Cls_720110::FUN_00720110(unsigned int flags)
{
    FUN_007e9130();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int _data_011c16bc;
struct FUN_00723f30_shell
{
    void SetVtableAndProcessState_00723f30();
};
struct FUN_00723f80
{
    ~FUN_00723f80();
};
struct FUN_007203c0 : FUN_00723f80
{
    char _pad[16];
    FUN_00723f30_shell fld10;
    ~FUN_007203c0();
};
// Destructor that calls FUN_00723f30 on the fld10 member.
// @fnv 0x007203c0
FUN_007203c0::~FUN_007203c0()
{
    fld10.SetVtableAndProcessState_00723f30();
}

extern int _data_011c16bc;
struct FUN_00724040
{
    char _d[16];
    FUN_00724040();
    ~FUN_00724040();
};
struct FUN_00723fa0
{
    FUN_00723fa0();
};
struct FUN_007207a0 : FUN_00724040
{
    FUN_00723fa0 m;
    FUN_007207a0();
};
// Empty constructor for a class that inherits FUN_00724040 and contains a FUN_00723fa0 member.
// @fnv 0x007207a0
FUN_007207a0::FUN_007207a0()
{}

struct FUN_00724070
{
    char _pad[16];
    ~FUN_00724070();
};
struct Helper_00723fd0
{
    void UpdateState_00723fd0();
};
struct FUN_00720800 : public FUN_00724070
{
    Helper_00723fd0 m;
    ~FUN_00720800();
};
// @fnv 0x00720800
FUN_00720800::~FUN_00720800()
{
    m.UpdateState_00723fd0();
}

// @fnv 0x00720a40
void* QuantityMenu::FUN_00720a40(unsigned int flags)
{
    ClearGlobalAndDestroyMenu();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00720a70 {
extern int DAT_011da618;
}  // namespace fnv_00720a70
// Sets the object's first field to the string "@\nr", clears DAT_011da618, then calls the Menu destructor on this.
// @fnv 0x00720a70
// src: GUESS 0x00720a70 (confidence: medium)
void QuantityMenu::ClearGlobalAndDestroyMenu()
{
    *(const char**)this = "@\nr";
    fnv_00720a70::DAT_011da618 = 0;
    ((Menu*)this)->Menu::~Menu();
}

namespace fnv_00720e00 {
Tile* __cdecl FindMenuById(int);
struct FakeMgr
{
    bool DestroyMenuByClass(int aiMenuClass);
};
// Looks up a Tile for the given menu class, deletes it if found, and returns whether it existed.
// @fnv 0x00720e00
bool FakeMgr::DestroyMenuByClass(int aiMenuClass)
{
    Tile* pmenu = FindMenuById(aiMenuClass);
    if (pmenu)
    {
        delete pmenu;
        return true;
    }
    return false;
}
}  // namespace fnv_00720e00

struct S0071
{
    unsigned char _pad[0x2c];
    Tile* m_pTiles[18];
    int __thiscall SurgeryMenu_GetIndex(int);
    void __thiscall SurgeryMenu_AttachTileByID(int, Tile*);
};
// Stores apTile in the slot returned by FUN_00720010(aiID) when aiID is in 1..0x12.
// @fnv 0x0071ffe0
// src: XBOX_PDB 0x0071ffe0
void __thiscall S0071::SurgeryMenu_AttachTileByID(int aiID, Tile* apTile)
{
    if (aiID > 0 && aiID <= 0x12)
    {
        m_pTiles[SurgeryMenu_GetIndex(aiID)] = apTile;
    }
}

// Stores apTile into the menu tile slot indexed by aiID when aiID is between 1 and 0x1F.
// @fnv 0x00720140
// src: XBOX_PDB 0x00720140
void VATSMenu::AttachTileByID(int aiID, Tile* apTile)
{
    if (aiID > 0 && aiID <= 0x1F)
    {
        m_pTiles[aiID] = apTile;
    }
}

struct FUN_00723f50
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    FUN_00723f50();
    ~FUN_00723f50();
};

struct FUN_00723f00
{
    int unk00;

    FUN_00723f00();
    ~FUN_00723f00();
};

struct FUN_00720360 : public FUN_00723f50
{
    FUN_00723f00 unk10;

    FUN_00720360();
    ~FUN_00720360();
};

// Initializes a FUN_00720360 object, constructing its FUN_00723f50 base and FUN_00723f00 member.
// @fnv 0x00720360
FUN_00720360::FUN_00720360()
{}



// @fnv 0x00720a10
QuantityMenu::QuantityMenu()
{
}

struct FUN_007df140_Sub
{
    int unk00;
    int unk04;
    int unk08;

    FUN_007df140_Sub();
    ~FUN_007df140_Sub();
};

struct FUN_007df140_Tail
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    FUN_007df140_Tail();
};

struct FUN_007df140_cls
{
    int m_00;
    FUN_007df140_Sub m_04;
    FUN_007df140_Tail m_10;

    FUN_007df140_cls(int aValue);
};

// Initializes the object's first field with the given value.
// @fnv 0x007df140
FUN_007df140_cls::FUN_007df140_cls(int aValue)
{
    m_00 = aValue;
}




void ourMemset(void* apDest, int aiValue, unsigned int auiSize);


// @fnv 0x00720040
VATSMenu::VATSMenu()
{
    ourMemset(m_pTiles, 0, sizeof(m_pTiles));
    m_bFirstFlag = false;
    m_bStateFlag4 = false;
    m_pSelectedChance = 0;
}

namespace fnv_00720550 {
void* __cdecl ourMemset(void*, int, unsigned int);
namespace Reconstructed {
// Exe 0x00720550: unit-local MenuList view; declarations and layout are preserved.

struct MenuSelection
{
    unsigned int head, tail, count, selected;
    MenuSelection();
    ~MenuSelection();
};
struct MenuEntry
{
    unsigned int tile, object, flags, value, minimum, maximum, step, selected;
    MenuEntry();
    ~MenuEntry();
};
struct SceneNode;
struct FUN_00720550 : Menu
{
    unsigned int tiles[8];
    unsigned int selectedTile;
    unsigned int mode;
    float elapsed;
    bool active;
    unsigned int currentIndex;
    unsigned int currentObject;
    unsigned int currentTile;
    BSSimpleArray<LoveTesterMenu::LoveTesterTextItem*,1024> list;
    MenuSelection selection;
    MenuEntry entries[9];
    MenuEntry currentEntry;
    NiPointer<SceneNode> nodes[11];
    NiPointer<SceneNode> effects[4];
    NiPointer<SceneNode> pair200[2];
    NiPointer<SceneNode> pair208[2];
    NiPointer<SceneNode> pair210[2];
    NiPointer<SceneNode> pair218[2];
    NiPointer<SceneNode> pair220[2];
    NiPointer<SceneNode> pair228[2];
    FUN_00720550();
    virtual ~FUN_00720550();
};
// Initializes the menu: clears the tiles array, zeroes the current object/tile/index and selected tile, sets mode to 1, elapsed to 0.0 and active to true.
// @fnv 0x00720550
FUN_00720550::FUN_00720550()
{
    ourMemset(tiles, 0, sizeof(tiles));
    currentObject = 0;
    currentTile = 0;
    selectedTile = 0;
    mode = 1;
    elapsed = 0.0f;
    active = true;
    currentIndex = 0;
}
}
}  // namespace fnv_00720550

struct FUN_00720f90_shell
{
    bool MenuManager_IsMenuOpen(int param_1);
};

struct NiPtrStub
{
    void* pObject;
    void* GetPtr();
};

struct ListStandIn
{
    int* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(int** cursor);
};





struct InterfaceManager_helper
{
    void* CombatController_GetCombatState();
};

void* __cdecl InterfaceManager_GetSingleton(void);

// @fnv 0x00720f90
// src: COMMUNITY 0x00720f90
bool FUN_00720f90_shell::MenuManager_IsMenuOpen(int param_1)
{
    int* cursor = (int*)((NiPtrStub*)((char*)((InterfaceManager_helper*)InterfaceManager_GetSingleton())->CombatController_GetCombatState() + 4))->GetPtr();
    while (cursor)
    {
        int item = *((ListStandIn*)((char*)((InterfaceManager_helper*)InterfaceManager_GetSingleton())->CombatController_GetCombatState() + 4))
                        ->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&cursor);
        Menu* menu = 0;
        if (item)
            menu = ((Tile*)item)->GetMenu();
        if (menu)
        {
            if (menu->FUN_00726070())
            {
                if (menu->GetClass() == param_1)
                {
                    if (menu->FUN_00726070()->IsTraitNonZero(0xfa3) &&
                        menu->GetVisibilityState() != 2)
                        return true;
                    else
                        return false;
                }
            }
        }
    }
    return false;
}
