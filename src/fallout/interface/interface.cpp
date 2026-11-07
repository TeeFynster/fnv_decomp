#include "../../../include/Stack.h"
#include "../../../include/SettingT.h"
#include "../../../include/BSStringT.h"
#include "../../../include/NiTListItem.h"
// fallout/interface/interface.cpp: Interface, ConsoleManager, FileFinder, TESCreature and more (216 functions)

#include "../../../include/InterfaceManager.h"
#include "../../../include/TESResponse.h"
#include "../../../include/TESSaveLoadGame.h"

InterfaceManager* InterfaceManager_GetSingleton();
float InterfaceManager_GetScreenHeight();
float InterfaceManager_GetRealScreenHeight();
float InterfaceManager_GetRealScreenWidth();
bool Renderer_GetWidescreen();
unsigned int NiVertexColorProperty_GetType();
bool DialogMenu_IsDialogActive();
unsigned int HudMainMenu_GetMenuID();

extern bool DAT_011d9514;
extern bool DAT_011c70eb;

class FOPipboyManager;
class Menu;
class TESForm;
class TESObjectREFR;
class NiControllerSequence;
class TESWorldSpace;

// The shared Menu header only declares Interface::IsSaveLoadActive; this facade still needs its local API.
// Exe 0x00707860: unit-local Interface view; declarations and layout are preserved.
class InterfaceInterfaceView
{
  public:
    FOPipboyManager* GetPipboyManager();
    static const char* GetInterfaceName();
    static float GetFirstInterfaceFloat();
    static float UpdateInterfaceState();
    static float GetThirdInterfaceFloat();
    static float GetFourthInterfaceFloat();
    static bool IsInterfaceOpen();
    static float GetInterfaceFloat();
    static void* GetPrimaryInterfaceTile();
    static void* GetSecondaryInterfaceTile();
    static NiNode* GetInterfaceNode();
    static bool IsAnyMenuOpen();

    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
    static bool IsInterfaceActive();

    enum enumMenus
    {
        eNoMenu = 0,
        eMainFour = 1,
        eOtherRoot = 2,
        eConsoleMenu = 3,
        eFirstMenu = 1001,
        eMessageMenu = 1001,
        eInventoryMenu = 1002,
        eStatsMenu = 1003,
        eHUDMainMenu = 1004,
        eLoadingMenu = 1007,
        eContainerMenu = 1008,
        eDialogMenu = 1009,
        eSleepWaitMenu = 1012,
        eStartMenu = 1013,
        eLockPickMenu = 1014,
        eQuantityMenu = 1016,
        eAudioMenu = 1017,
        eVideoMenu = 1018,
        eGameplayMenu = 1020,
        eMapMenu = 1023,
        eBookMenu = 1026,
        eLevelUpMenu = 1027,
        eBirthSignMenu = 1029,
        eRepairMenu = 1035,
        eRaceSexMenu = 1036,
        eCreditsMenu = 1047,
        eCharGenMenu = 1048,
        eTextEditMenu = 1051,
        eBarterMenu = 1053,
        eSurgeryMenu = 1054,
        eHackingMenu = 1055,
        eVATSMenu = 1056,
        eComputersMenu = 1057,
        eRepairServicesMenu = 1058,
        eTutorialMenu = 1059,
        eSPECIALBookMenu = 1060,
        eItemModMenu = 1061,
        eLoveTesterMenu = 1074,
        eCompanionWheelMenu = 1075,
        eTraitSelectMenu = 1076,
        eRecipeMenu = 1077,
        eSlotMachineMenu = 1080,
        eBlackJackMenu = 1081,
        eRouletteMenu = 1082,
        eCaravanMenu = 1083,
        eTraitMenu = 1084,
        eLastMenu = 1084
    };
    static void Init(bool);
    static void RefreshInterfaceState();
    static void SetQuestTarget(TESForm*, bool);
    static bool IsPipBoyOpen();
    static bool GetStatsMenuVisible();
    static bool IsGamePaused();
    static bool ContainerIsRecipe();
    static bool ContainerIsBarter();
    static void SetLookAtReference(TESObjectREFR*);
    static bool PlayNifSounds(NiControllerSequence*);
    static Menu* GetMenuById(int);
    static void SetHUDVisible(bool);
    static void SetTileFormattedText(void*, int, const char*, ...);
};

bool __cdecl Interface_IsMenuIDVisible(InterfaceInterfaceView::enumMenus, unsigned int);

// Keep this unit's template APIs alongside the shared game classes.
#include "interface_rebase_layout_support.h"
// Tile's dependencies already have checked declarations in this packet.
#pragma include_alias("ShadowSceneLight.h", "../interface/interface_rebase_layout_support.h")
#define FNV64_NIFIXEDSTRING_OWN_BODIES
#include "../../../include/NiFixedString.h"
#include "../../../include/Tile.h"
typedef NiTListItem<Tile* > InterfaceTileListItem;
#include "../../../include/Menu.h"
// The shared scene-graph classes; their header's smart-pointer and list templates are kept apart
// from the packet's own (interface_rebase_layout_support.h), which the rest of this unit uses.
#include "../../../include/NiAVObject.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/ActorBaseAttributes.h"
#include "../../../include/ActorValueModifierList.h"
#include "../../../include/ActorValueOwner.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BGSDestructibleObjectForm.h"
#include "../../../include/BGSTouchSpellForm.h"
#include "../../../include/BSAnimGroupSequence.h"
#include "../../../include/BSFadeNode.h"
#include "../../../include/BaseExtraList.h"
#include "../../../include/BaseFormComponent.h"
#include "../../../include/CachedValuesOwner.h"
#include "../../../include/Character.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/FOPipboyManager.h"
#include "../../../include/FORenderedMenu.h"
#include "../../../include/FileEntryList.h"
#include "../../../include/FileEntryListCollection.h"
#include "../../../include/GameTimerRecord.h"
#include "../../../include/HUDMainMenu.h"
#include "../../../include/HotkeyWheelDisplay.h"
#include "../../../include/LoadingMenu.h"
#include "../../../include/MagicCaster.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/MapEntryCount.h"
#include "../../../include/MessageMenu.h"
#include "../../../include/MobileObject.h"
#include "../../../include/NiColor.h"
#include "../../../include/NiControllerSequence.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiObject.h"
#include "../../../include/NiRefObject.h"
#include "../../../include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile___.h"
#include "../../../include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator.h"
#include "../../../include/NiTPointerAllocator_unsigned_int_.h"
#include "../../../include/NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___.h"
#include "../../../include/NiTPointerList_Tile___.h"
#include "../../../include/PackageList.h"
#include "../../../include/PerkEntryConditionSet.h"
#include "../../../include/PlacedObjectInfo.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/NiColorA.h"
#include "../../../include/SETTING_VALUE.h"
#include "../../../include/ShortPoint3.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/TESAIForm.h"
#include "../../../include/TESActorBase.h"
#include "../../../include/TESActorBaseData.h"
#include "../../../include/TESAnimation.h"
#include "../../../include/TESAttackDamageForm.h"
#include "../../../include/TESAttributes.h"
#include "../../../include/TESBoundAnimObject.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/TESBoundObject__BOUND_DATA.h"
#include "../../../include/TESChildCell.h"
#include "../../../include/TESContainer.h"
#include "../../../include/TESCreature.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESFullName.h"
#include "../../../include/TESHealthForm.h"
#include "../../../include/TESModel.h"
#include "../../../include/TESModelList.h"
#include "../../../include/TESObject.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESRecipe.h"
#include "../../../include/TESScriptableForm.h"
#include "../../../include/TESSpellList.h"
#include "../../../include/TypedData.h"
#include "interface_rebase_types_MenuManager.h"

extern PlayerCharacter* g_thePlayer;
#include "../../../include/BSSystemUtility.h"
#include "../../../include/BSThread.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/BGSMoviePlayer.h"
#include "../../../include/BSStream.h"
#include "../../../include/GO.h"
#include "../../../include/GameSettingCollection.h"
#include "../../../include/NiStream.h"
#include "../../../include/OSGlobals.h"
#include "../../../include/Setting.h"

#include "../../../include/BSFaceGenNiNode.h"
#include "../../../include/InventoryMenu.h"
#include "../../../include/DialogMenu.h"
// MapMenu's private array template is independent of the packet's array template.
#include "../../../include/MapMenu.h"
#include "../../../include/StartMenu.h"
#include "../../../include/StatsMenu.h"
#include "../../../include/ContainerMenu.h"
#include "../../../include/INISettingCollection.h"
#pragma include_alias("BSSimpleArray.h", "../interface/interface_rebase_layout_support.h")
class BGSLoadFormBuffer;
enum SEX;
#include "../../../include/TESNPC.h"
#include "../../../include/TESObjectARMO.h"
#include "../../../include/SurgeryMenu.h"
#include "../../../include/SleepWaitMenu.h"
#include "../../../include/TESGlobal.h"
#include "../../../include/TileRect.h"
#include "../../../include/TileMenu.h"
#include "../../../include/FORenderedTerminal.h"

// These approved headers lack the getters; each uses only the this pointer in ECX.
bool __fastcall IsSleepWaitMenuActive(SleepWaitMenu*);
char __fastcall GetGlobalValueType(TESGlobal*);

const char kMeshesFolder[] = "Meshes";

// @fnv 0x00707860
const char* InterfaceInterfaceView::GetInterfaceName()
{
    return kMeshesFolder;
}

// @fnv 0x007043c0
bool InterfaceInterfaceView::IsWorldSpaceEnabled(TESWorldSpace* apSpace)
{
    (void)apSpace;
    return false;
}

// @fnv 0x00705ea0
bool InterfaceInterfaceView::IsInterfaceActive()
{
    return BSSystemUtility::s_iUpdateEnabled != 0;
}

// @fnv 0x00706df0
float InterfaceInterfaceView::GetFirstInterfaceFloat()
{
    return InterfaceManager_GetScreenHeight();
}

// @fnv 0x00706e00
float InterfaceInterfaceView::UpdateInterfaceState()
{
    return InterfaceManager::UpdateInterfaceState();
}

// @fnv 0x00706e10
float InterfaceInterfaceView::GetThirdInterfaceFloat()
{
    return InterfaceManager_GetRealScreenHeight();
}

// @fnv 0x00706e40
float InterfaceInterfaceView::GetFourthInterfaceFloat()
{
    return InterfaceManager_GetRealScreenWidth();
}

// @fnv 0x00707b40
bool InterfaceInterfaceView::IsInterfaceOpen()
{
    return Renderer_GetWidescreen();
}

// @fnv 0x00706e70
float InterfaceInterfaceView::GetInterfaceFloat()
{
    return InterfaceManager_GetSingleton()->fScreenAspectRatio;
}

// @fnv 0x00706cd0
void* InterfaceInterfaceView::GetPrimaryInterfaceTile()
{
    return InterfaceManager_GetSingleton()->CombatController_GetCombatState();
}

// @fnv 0x00706cf0
void* InterfaceInterfaceView::GetSecondaryInterfaceTile()
{
    return InterfaceManager_GetSingleton()->GetAVEffect();
}

// @fnv 0x00706d30
NiNode* InterfaceInterfaceView::GetInterfaceNode()
{
    return InterfaceManager_GetSingleton()->FUN_004fb070();
}

// @fnv 0x00706d70
bool InterfaceInterfaceView::IsAnyMenuOpen()
{
    return InterfaceManager_GetSingleton()->GetIsEmergencyTextureRelease();
}

// @fnv 0x00702440
// src: COMMUNITY 0x00702440
unsigned int NiVertexColorProperty_GetType()
{
    return 10;
}

// @fnv 0x00705100
// src: XBOX_PDB 0x00705100
bool DialogMenu_IsDialogActive()
{
    return DAT_011d9514;
}

// @fnv 0x00706f20
// src: COMMUNITY 0x00706f20
unsigned int HudMainMenu_GetMenuID()
{
    return 1004;
}

// @fnv 0x00707b50
// src: XBOX_PDB 0x00707b50
bool Renderer_GetWidescreen()
{
    return DAT_011c70eb;
}

// Fresh-claim additions verified against the supplied PC spans.

// Creates an AutoMemContext for the interface and calls InterfaceManager::Initialize with 1 and initializeRender.
// @fnv 0x00702250
void InterfaceInterfaceView::Init(bool initializeRender)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_INTERFACE, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Interface.cpp", 176u);
    InterfaceManager::Initialize(1u, initializeRender);
}

// Creates an AutoMemContext for the interface and calls InterfaceManager::Initialize with 2 and true.
// @fnv 0x007022c0
void InterfaceInterfaceView::RefreshInterfaceState()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_INTERFACE, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Interface.cpp", 189u);
    InterfaceManager::Initialize(2u, true);
}

// @fnv 0x00705e00
void InterfaceInterfaceView::SetQuestTarget(TESForm* location, bool flag)
{
    MessageMenu::SetMessageMenuActive(true);
    LoadingMenu::Create(location, true, flag);
}

// @fnv 0x00704ad0
bool InterfaceInterfaceView::IsPipBoyOpen()
{
    return Menu::IsMenuVisible(static_cast<Interface::enumMenus>(eInventoryMenu));
}

// @fnv 0x00704df0
bool InterfaceInterfaceView::GetStatsMenuVisible()
{
    return Menu::IsMenuVisible(static_cast<Interface::enumMenus>(eStatsMenu));
}

// @fnv 0x00705e80
bool InterfaceInterfaceView::IsGamePaused()
{
    return Menu::IsMenuVisible(static_cast<Interface::enumMenus>(eLoadingMenu));
}

// @fnv 0x00705000
bool InterfaceInterfaceView::ContainerIsRecipe()
{
    return Tile::FindMenuById(eRecipeMenu) != 0;
}

// @fnv 0x00705020
bool InterfaceInterfaceView::ContainerIsBarter()
{
    return Tile::FindMenuById(eBarterMenu) != 0;
}

// If the player and its NiNode exist, forwards the target reference to HUDMainMenu with a false flag.
// @fnv 0x00703860
void InterfaceInterfaceView::SetLookAtReference(TESObjectREFR* target)
{
    if (g_thePlayer && g_thePlayer->GetNiNode())
        HUDMainMenu::SetCrosshairTarget(target, false);
}

// @fnv 0x0059f3a0
signed char TESCreature::GetCreatureType() const
{
    return Data.eType;
}

// @fnv 0x007037c0
void TESRecipe::SetRequiredSkill(ActorValue::Index skill)
{
    kData.eReqSkill = skill;
}

// @fnv 0x00705cf0
bool ActiveEffect::IsDone() const
{
    return bPickResultFound;
}

// @fnv 0x007058c0
LOD_MULT_TYPE BSFadeNode::GetLODMultType() const
{
    return static_cast<LOD_MULT_TYPE>(eMultType);
}

// If initialized, culls the first three button objects and un-culls the object at index button - 1 when button is greater than zero.
// @fnv 0x007fa010
void FOPipboyManager::ActivateButton(const unsigned int button)
{
    if (!GetInitialized())
        return;

    if (m_pButtonGlowObjects[0])
        static_cast<NiAVObject*>(m_pButtonGlowObjects[0])->SetAppCulled(true);
    if (m_pButtonGlowObjects[1])
        static_cast<NiAVObject*>(m_pButtonGlowObjects[1])->SetAppCulled(true);
    if (m_pButtonGlowObjects[2])
        static_cast<NiAVObject*>(m_pButtonGlowObjects[2])->SetAppCulled(true);

    if (button > 0 && m_pButtonGlowObjects[button - 1])
        static_cast<NiAVObject*>(m_pButtonGlowObjects[button - 1])->SetAppCulled(false);
}

// Returns p1stPersonAnimation when firstPerson is set, otherwise delegates to Actor::GetAnimation().
// @fnv 0x00950a60
Animation* PlayerCharacter::GetAnimation(bool firstPerson) const
{
    if (firstPerson)
        return p1stPersonAnimation;
    return Actor::GetAnimation();
}

// Creates a TabButtonTemplate tile per label from the varargs list, sets its string/name/indices, then positions each tab by accumulated width.
// @fnv 0x00707be0
void InterfaceInterfaceView::SetTileFormattedText(void* parent, int firstID, const char* firstLabel, ...)
{
    BSStringT<char> buttonLabel;
    int count = 0;
    int iTotalWidth = 0;
    va_list labels;
    va_start(labels, firstLabel);
    buttonLabel.Set(firstLabel, 0);

    for (count = 0; buttonLabel.Length() > 0; ++count)
    {
        Tile* pTab = static_cast<Tile*>(parent)->GetMenu()->CreateTileFromTemplate(
            static_cast<Tile*>(parent), "TabButtonTemplate", 0);
        pTab->SetString(0xfc4, buttonLabel.String(), true);
        pTab->SetName(buttonLabel.String());
        pTab->SetInt(0xfac, count);
        pTab->SetInt(0xfaa, firstID + count);
        Tile::UpdateAll(false);
        iTotalWidth += static_cast<int>(pTab->GetFloat(0xfb1));
        buttonLabel = va_arg(labels, const char*);
    }
    va_end(labels);

    // Initial button position also supplies the uniform inter-button gap.
    int iPosition = static_cast<int>((static_cast<Tile*>(parent)->GetFloat(0xfb1) - iTotalWidth) / (count + 1));
    // Accumulated left spacing is the current button coordinate.
    int iSpacing = iPosition;
    static_cast<Tile*>(parent)->SetInt(Tile::GetTraitID("_LeftLineLength"), iPosition);
    static_cast<Tile*>(parent)->SetInt(Tile::GetTraitID("_ButtonCount"), count);

    va_start(labels, firstLabel);
    buttonLabel.Set(firstLabel, 0);
    while (buttonLabel.Length() > 0)
    {
        Tile* pTab = static_cast<Tile*>(parent)->GetNamedChild(buttonLabel.String());
        pTab->SetInt(Tile::GetTraitID("_x"), iSpacing);
        iSpacing = static_cast<int>(pTab->GetFloat(0xfb1)) + iPosition + iSpacing;
        buttonLabel = va_arg(labels, const char*);
    }
    va_end(labels);
}

// @fnv 0x00707e10
void Tile::SetName(const char* name)
{
    StringProvider = name;
}

// @fnv 0x00707970
bool InterfaceInterfaceView::PlayNifSounds(NiControllerSequence* sequence)
{
    return BSAnimGroupSequence::PlayAnimSounds(sequence, 0);
}

// @fnv 0x00707990
Menu* InterfaceInterfaceView::GetMenuById(int menuClass)
{
    return MenuSystem::Instance(true)->GetMenuById(menuClass);
}

// @fnv 0x00709c40
void InterfaceInterfaceView::SetHUDVisible(bool visible)
{
    HUDMainMenu::SetHUDVisible(visible);
}

struct FUN_00424940_shell : public InterfaceManager
{
    char InterfaceManager_GetMenuMode();
};

// @fnv 0x00424940
// src: XBOX_PDB 0x00424940
char FUN_00424940_shell::InterfaceManager_GetMenuMode()
{
    return *((char*)this + 0xc);
}

extern bool DAT_011c70ed;
extern bool DAT_011c70ee;

// Returns true only when both DAT_011c70ed and DAT_011c70ee are set.
// @fnv 0x004de080
// src: COMMUNITY 0x004de080
bool __cdecl IsEyefinity()
{
    return DAT_011c70ed && DAT_011c70ee;
}

struct ListStandIn
{
    int* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(int** pos);
};
// @fnv 0x0057cbe0
// src: XBOX_PDB 0x0057cbe0
int* ListStandIn::NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(int** pos)
{
    int* element = reinterpret_cast<int*>(*pos) + 2;
    *pos = reinterpret_cast<int*>(**pos);
    return element;
}

struct FUN_00644640_shell : public InterfaceManager
{
    bool InterfaceManager_IsDebugTextVisible();
};

// @fnv 0x00644640
// src: XBOX_PDB 0x00644640
bool FUN_00644640_shell::InterfaceManager_IsDebugTextVisible()
{
    return *((bool*)((char*)this + 0x7c));
}

class Modifier
{
  public:
    char GetKey(void);
};

bool __fastcall InterfaceManager_IsDebugTextVisible(void*);

// Returns true when FUN_004b7210 yields a Modifier whose GetKey is nonzero and FUN_00644640 accepts that same object; otherwise false.
// @fnv 0x00702360
// src: XBOX_PDB 0x00702360
bool Interface_IsInMenuMode()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        return InterfaceManager_IsDebugTextVisible(InterfaceManager_GetSingleton());
    return false;
}


// @fnv 0x007023a0
// src: XBOX_PDB 0x007023a0
bool InterfaceManager::IsInMenuMode()
{
    return uiCurrentMode != 1;
}

namespace fnv_007023c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};


// @fnv 0x007023c0
// src: XBOX_PDB 0x007023c0
int Interface_GetTopMenuID()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return reinterpret_cast<InterfaceManager*>(InterfaceManager_GetSingleton())->GetTopEnterStackEntry();
    return 0;
}
}  // namespace fnv_007023c0

namespace fnv_00702400 {
struct Modifier
{
    bool GetKey();
    int GetMenuStackEntry(int);
};
// @fnv 0x00702400
// src: COMMUNITY 0x00702400
int Interface_GetMenuID(int a)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetMenuStackEntry(a);
    return 0;
}
}  // namespace fnv_00702400

namespace fnv_00702450 {
class Modifier
{
  public:
    char GetKey();
};


// @fnv 0x00702450
// src: XBOX_PDB 0x00702450
bool __cdecl Interface_IsTopMenuID(InterfaceInterfaceView::enumMenus aeMenuID)
{
    if (InterfaceManager_GetSingleton() && (unsigned char)((Modifier*)InterfaceManager_GetSingleton())->GetKey())
    {
        int topid = ((InterfaceManager*)InterfaceManager_GetSingleton())->GetTopEnterStackEntry();
        if (topid == InterfaceInterfaceView::eMainFour &&
            (aeMenuID == InterfaceInterfaceView::eStatsMenu || aeMenuID == InterfaceInterfaceView::eInventoryMenu ||
             aeMenuID == InterfaceInterfaceView::eRepairMenu || aeMenuID == InterfaceInterfaceView::eMapMenu ||
             aeMenuID == InterfaceInterfaceView::eItemModMenu))
        {
            return ::Interface_IsMenuIDVisible(aeMenuID, 0);
        }
        else
        {
            return topid == aeMenuID;
        }
    }
    return false;
}
}  // namespace fnv_00702450

namespace fnv_00702640 {
class Modifier
{
  public:
    unsigned char GetKey();
};


// @fnv 0x00702640
// src: XBOX_PDB 0x00702640
int Interface_GetMenuModeType()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return static_cast<InterfaceManager*>(InterfaceManager_GetSingleton())->GetMenuStackEntry(0);
    return 0;
}
}  // namespace fnv_00702640

extern bool DAT_011f308f[];

// @fnv 0x007027b0
// src: XBOX_PDB 0x007027b0
bool __cdecl Menu_IsMenuVisible(int aiMenuID)
{
    if (aiMenuID >= InterfaceInterfaceView::eFirstMenu && aiMenuID <= InterfaceInterfaceView::eLastMenu)
    {
        return DAT_011f308f[aiMenuID];
    }
    else
    {
        return false;
    }
}

namespace fnv_007027e0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

void __fastcall UpdateStartMenuState(InterfaceManager*);

// If FUN_004b7210 returns a Modifier with a nonzero key, calls UpdateStartMenuState with that manager.
// @fnv 0x007027e0
// src: COMMUNITY 0x007027e0
void Interface_PreIdleStuff()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        UpdateStartMenuState(InterfaceManager_GetSingleton());
}
}  // namespace fnv_007027e0

namespace fnv_00702810 {
class Modifier
{
  public:
    char GetKey();
};

void __fastcall UpdateInterface(InterfaceManager*);

// If FUN_004b7210() returns a non-null object whose GetKey() is nonzero, calls UpdateInterface with that object.
// @fnv 0x00702810
// src: COMMUNITY 0x00702810
void Interface_Idle()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        UpdateInterface(InterfaceManager_GetSingleton());
}
}  // namespace fnv_00702810

namespace fnv_00702840 {
class Modifier
{
  public:
    unsigned char GetKey();
};

void __fastcall UpdateMenuSelection(InterfaceManager* pThis);

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls UpdateMenuSelection with that object.
// @fnv 0x00702840
// src: COMMUNITY 0x00702840
void Interface_PostIdleStuff()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        UpdateMenuSelection(InterfaceManager_GetSingleton());
}
}  // namespace fnv_00702840

namespace fnv_00702870 {
class Modifier
{
  public:
    unsigned char GetKey();
};

extern BGSMoviePlayer* DAT_0126fac4;
void __fastcall InterfaceManager_Accumulate(InterfaceManager*);

// @fnv 0x00702870
// src: COMMUNITY 0x00702870
void Interface_Accumulate()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey() && !DAT_0126fac4->IsPlaying())
        InterfaceManager_Accumulate(InterfaceManager_GetSingleton());
}
}  // namespace fnv_00702870

namespace fnv_007028b0 {
class Modifier
{
  public:
    bool GetKey();
};

class TaskThreadManager
{
  public:
    static TaskThreadManager* __cdecl GetSingleton();
    void MTRenderingSystem_SetThreadStage(int, int);
    void MTRenderingSystem_WaitOnThreadStage(int, int);
};

struct IM_Stub
{
    void RenderMenu(int, int);
    void SetField148(int);
};

extern BGSMoviePlayer* DAT_0126fac4;

// @fnv 0x007028b0
void __cdecl RenderOrFallback(int aiArg1, int aiArg2)
{
    bool bRendered = false;
    if (InterfaceManager_GetSingleton() && ((Modifier*)InterfaceManager_GetSingleton())->GetKey() && !DAT_0126fac4->IsPlaying())
    {
        ((IM_Stub*)InterfaceManager_GetSingleton())->RenderMenu(aiArg1, aiArg2);
        bRendered = true;
    }
    if (!bRendered)
    {
        TaskThreadManager::GetSingleton()->MTRenderingSystem_SetThreadStage(0, 0x17);
        TaskThreadManager::GetSingleton()->MTRenderingSystem_WaitOnThreadStage(1, 0x17);
    }
    ((IM_Stub*)InterfaceManager_GetSingleton())->SetField148(0);
}
}  // namespace fnv_007028b0

struct FUN_00702940_cls
{
    char pad[0x148];
    char field_148;
    void SetField148(char val);
};

// @fnv 0x00702940
void FUN_00702940_cls::SetField148(char acValue)
{
    field_148 = acValue;
}

struct FUN_00703060_shell : public InterfaceManager
{
    void InterfaceManager_SetDebugTextVisible(bool);
};

// @fnv 0x00703060
// src: XBOX_PDB 0x00703060
void FUN_00703060_shell::InterfaceManager_SetDebugTextVisible(bool abVisible)
{
    reinterpret_cast<unsigned char*>(this)[0x7C] = abVisible;
}

namespace fnv_00703180 {
struct Modifier
{
    bool GetKey();
    TESObjectREFR* GetCurrentWeapon();
};
// Gets the InterfaceManager and, if it exists and its key check passes, returns the reference from the modifier; otherwise returns 0.
// @fnv 0x00703180
// src: XBOX_PDB 0x00703180
TESObjectREFR* Interface_GetTargetREFR()
{
    InterfaceManager* pim = InterfaceManager_GetSingleton();
    if (pim && reinterpret_cast<Modifier*>(pim)->GetKey())
        return reinterpret_cast<Modifier*>(pim)->GetCurrentWeapon();
    return 0;
}
}  // namespace fnv_00703180

namespace fnv_00703d50 {
struct Modifier
{
    bool GetKey();
};
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    bool IsConsoleActive();
};
// @fnv 0x00703d50
// src: XBOX_PDB 0x00703d50
bool Interface_IsConsoleVisible()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey() && ConsoleManager::Instance(false))
        return ConsoleManager::Instance(true)->IsConsoleActive();
    return false;
}
}  // namespace fnv_00703d50

namespace fnv_00703da0 {
struct Modifier
{
    bool GetKey();
    int AddMenuStackEntry(int, bool);
};
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    bool IsConsoleActive();
    void MenuConsole_ToggleVisible();
};
// @fnv 0x00703da0
// src: XBOX_PDB 0x00703da0
void Interface_CloseConsole()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey() && ConsoleManager::Instance(false) &&
        ConsoleManager::Instance(true)->IsConsoleActive())
    {
        ConsoleManager::Instance(true)->MenuConsole_ToggleVisible();
        reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->AddMenuStackEntry(3, false);
    }
}
}  // namespace fnv_00703da0

// Reads the char at offset 0xE4 of the object returned by FUN_004b7210, sets that byte to -1, and returns the original value.
// @fnv 0x00703fa0
char ConsumeByteAtE4()
{
    char cresult = *reinterpret_cast<char*>(reinterpret_cast<char*>(InterfaceManager_GetSingleton()) + 0xE4);
    *reinterpret_cast<char*>(reinterpret_cast<char*>(InterfaceManager_GetSingleton()) + 0xE4) = -1;
    return cresult;
}

namespace fnv_00704140 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl MapMenu_Create();

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, returns FUN_00796b90(); otherwise returns 0.
// @fnv 0x00704140
// src: XBOX_PDB 0x00704140
int Interface_CreateMapMenu()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return MapMenu_Create();
    return 0;
}
}  // namespace fnv_00704140

namespace fnv_00704490 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl MapMenu_Create();

// If FUN_004b7210() returns non-null and its GetKey() is nonzero, returns FUN_00796b90(); otherwise returns 0.
// @fnv 0x00704490
// src: XBOX_PDB 0x00704490
int Interface_CreateRepairMenu()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return MapMenu_Create();
    return 0;
}
}  // namespace fnv_00704490

namespace fnv_007046c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl MapMenu_Create();

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, returns FUN_00796b90(); otherwise returns 0.
// @fnv 0x007046c0
// src: XBOX_PDB 0x007046c0
int Interface_CreateItemModMenu()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return MapMenu_Create();
    return 0;
}
}  // namespace fnv_007046c0

namespace fnv_007048c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

// Returns InventoryMenu::Create() when FUN_004b7210() is non-null and its GetKey() is nonzero, otherwise returns 0.
// @fnv 0x007048c0
void* CreateInventoryMenuIfModifierKey()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return InventoryMenu::Create();
    return 0;
}
}  // namespace fnv_007048c0

namespace fnv_00704be0 {
class Modifier
{
  public:
    char GetKey(void);
};

int __cdecl StatsMenu_Create();

// If FUN_004b7210 returns a non-null Modifier whose GetKey is nonzero, returns FUN_007da2c0(); otherwise returns 0.
// @fnv 0x00704be0
// src: XBOX_PDB 0x00704be0
int Interface_CreateStatsMenu()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        return StatsMenu_Create();
    return 0;
}
}  // namespace fnv_00704be0

namespace fnv_00704f50 {
class Modifier
{
  public:
    char GetKey();
};

// If FUN_004b7210 returns an object whose GetKey() is nonzero, calls ContainerMenu::Close().
// @fnv 0x00704f50
// src: XBOX_PDB 0x00704f50
void Interface_CloseContainer()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        ContainerMenu::Close();
}
}  // namespace fnv_00704f50

namespace fnv_00705070 {
struct Modifier
{
    bool GetKey();
};
struct TimeGlobal
{
    void SetGlobalTimeMultiplier(float, bool);
};
extern TimeGlobal g_timeGlobal;

// @fnv 0x00705070
// src: XBOX_PDB 0x00705070
void* Interface_CreateDialogMenu(void* apArg1, void* apArg2, void* apArg3)
{
    void* r;
    g_timeGlobal.SetGlobalTimeMultiplier(1.0f, true);
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
    {
        r = DialogMenu::Create(apArg1, apArg2, apArg3);
        return r;
    }
    return 0;
}
}  // namespace fnv_00705070

namespace fnv_007050d0 {
class Modifier
{
  public:
    char GetKey(void);
};

// @fnv 0x007050d0
// src: XBOX_PDB 0x007050d0
bool Interface_InDialog()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        return DialogMenu_IsDialogActive();
    return false;
}
}  // namespace fnv_007050d0

namespace fnv_007053f0 {
class Modifier
{
  public:
    char GetKey(void);
};

// If FUN_004b7210() returns a non-null Modifier whose GetKey() is nonzero, calls StartMenu::Create(false, false).
// @fnv 0x007053f0
// src: COMMUNITY 0x007053f0
void Interface_CreateMainMenu()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        StartMenu::Create(false, false);
}
}  // namespace fnv_007053f0

namespace fnv_007058e0 {
class Modifier
{
  public:
    char GetKey(void);
};

void __fastcall InterfaceManager_LastMinuteUpdate(InterfaceManager*);

// If FUN_004b7210() returns a Modifier whose GetKey() is nonzero, calls FUN_00713c70 with the InterfaceManager from FUN_004b7210().
// @fnv 0x007058e0
// src: COMMUNITY 0x007058e0
void Interface_LastMinuteUpdate()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        InterfaceManager_LastMinuteUpdate(InterfaceManager_GetSingleton());
}
}  // namespace fnv_007058e0

namespace fnv_00705910 {
struct Modifier
{
    bool GetKey();
};
// If FUN_004b7210() returns a Modifier whose GetKey() is true, returns the TESNPC result of FUN_00602170(); otherwise returns 0.
// @fnv 0x00705910
// src: XBOX_PDB 0x00705910
int Interface_GetVATSEffect()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
    {
        return reinterpret_cast<int>(reinterpret_cast<TESNPC*>(InterfaceManager_GetSingleton())->InterfaceManager_GetVATSEffect());
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_00705910

namespace fnv_00705990 {
struct Modifier
{
    bool GetKey();
};
// If FUN_004b7210() returns a Modifier whose GetKey() is true, returns its Pipboy manager; otherwise returns 0.
// @fnv 0x00705990
// src: XBOX_PDB 0x00705990
int Interface_GetPipboy()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
    {
        return reinterpret_cast<int>(reinterpret_cast<InterfaceInterfaceView*>(InterfaceManager_GetSingleton())->GetPipboyManager());
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_00705990

namespace fnv_007059d0 {
class Modifier
{
  public:
    char GetKey(void);
};
void __fastcall ResetWidget(InterfaceManager*);

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls ResetWidget with that InterfaceManager.
// @fnv 0x007059d0
// src: COMMUNITY 0x007059d0
void Interface_ReinitialisePipboyManager()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        ResetWidget(InterfaceManager_GetSingleton());
}
}  // namespace fnv_007059d0

namespace fnv_00705a00 {
class Modifier
{
  public:
    char GetKey();
};

bool __cdecl Interface_IsPipboyOpening();
bool __cdecl Interface_IsPipboyOpen();

// @fnv 0x00705a00
// src: XBOX_PDB 0x00705a00
bool __cdecl Interface_IsInPipboyMenu()
{
    if (InterfaceManager_GetSingleton() && (unsigned char)((Modifier*)InterfaceManager_GetSingleton())->GetKey())
    {
        return Interface_IsPipboyOpening() || Interface_IsPipboyOpen();
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00705a00

namespace fnv_00705a90 {
class Modifier
{
  public:
    char GetKey();
};

// Returns the LOD mult type of the fade node from FUN_004b7210 when it exists and its key is nonzero, otherwise 0.
// @fnv 0x00705a90
int GetLODMultTypeIfKeySet()
{
    if (InterfaceManager_GetSingleton() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey()))
        return reinterpret_cast<const BSFadeNode*>(InterfaceManager_GetSingleton())->GetLODMultType();
    else
        return 0;
}
}  // namespace fnv_00705a90

struct FUN_00705b10_Dummy
{
    char pad[0xc4];
    int val;
    void Set(int a);
};

// @fnv 0x00705b10
void FUN_00705b10_Dummy::Set(int aiValue)
{
    val = aiValue;
}

namespace fnv_00705b30 {
struct Modifier
{
    bool GetKey();
};
struct IMStandIn
{
    void InterfaceManager_ClearReferencePointers(int a);
};
// If FUN_004b7210() returns an object whose GetKey() is true, forwards a to its FUN_00716010 method.
// @fnv 0x00705b30
// src: COMMUNITY 0x00705b30
void __cdecl Interface_ClearReferencePointers(int a)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        reinterpret_cast<IMStandIn*>(InterfaceManager_GetSingleton())->InterfaceManager_ClearReferencePointers(a);
}
}  // namespace fnv_00705b30

// Returns the larger of the two integer arguments.
// @fnv 0x00705c40
// src: COMMUNITY 0x00705c40
int _max(int aiValue1, char aiValue2)
{
    return (aiValue1 > aiValue2) ? aiValue1 : aiValue2;
}

struct DummyVtable_00705e30
{
    virtual ~DummyVtable_00705e30();
};

// @fnv 0x00705e30
// src: XBOX_PDB 0x00705e30
void Interface_CloseLoadingMenu()
{
    delete (DummyVtable_00705e30*)BSSystemUtility::s_iUpdateEnabled;
    MessageMenu::SetMessageMenuActive(false);
}

namespace fnv_007069d0 {
extern MapMenu* DAT_011da368;

// @fnv 0x007069d0
// src: COMMUNITY 0x007069d0
void MapMenu_SetCurrentMapPage(unsigned char acPage)
{
    if (DAT_011da368)
        DAT_011da368->SetCurrentPage(acPage);
}

}  // namespace fnv_007069d0

// Calls HandleSelection with the argument offset by 0x20 and zero.
// @fnv 0x007069f0
void MapMenu::SetCurrentPage(int aiValue)
{
    this->HandleSelection(aiValue + 0x20, 0);
}

void __cdecl SetInventoryTab(unsigned char);

// @fnv 0x00706a20
// src: COMMUNITY 0x00706a20
void __cdecl InventoryMenu_SetCurrentInventoryPage(unsigned char acPage)
{
    SetInventoryTab(acPage);
}

int __cdecl MinInt(int, int);


// @fnv 0x00706a40
void __cdecl SetInventoryTab(int aiTab)
{
    if (InventoryMenu::ms_pInventoryMenu)
    {
        aiTab = MinInt(aiTab, 4);
        ((Tile*)InventoryMenu::ms_pInventoryMenu->m_pTiles[13])->Set(InventoryMenu::ms_iCurrentTabTileID, aiTab);
        InventoryMenu::ms_pInventoryMenu->m_iCurrentTab = aiTab;
    }
}

namespace fnv_00706a90 {

void __cdecl StatsMenu_UpdatePerks();
void __cdecl UpdateStatsMenuLevelText();
void __cdecl ClearMapMenuNote();

// @fnv 0x00706a90
// src: COMMUNITY 0x00706a90
void __cdecl InterfaceManager_FinishLoadGame()
{
    StatsMenu_UpdatePerks();
    UpdateStatsMenuLevelText();
    StatsMenu::UpdateStatusEffects();
    MapMenu::SetMapPositionToPlayer();
    ClearMapMenuNote();
    MapMenu::UpdateMapPosition();
    SurgeryMenu::UpdatePerkEntries();
}
}  // namespace fnv_00706a90

struct BGSNote;
struct BGSQuestObjective;
struct TESChallenge;
struct TESQuest;
struct RegionObjectEntry;
struct TESWorldSpace;
struct PathingPath;
struct blob12
{
    char b[12];
};

extern MapMenu* DAT_011da368;

// @fnv 0x00706ac0
void ClearMapMenuNote()
{
    if (DAT_011da368 != 0)
    {
        DAT_011da368->m_pSelectedNote = 0;
    }
}

struct TutorialManagerLayout
{
    struct Entry
    {
        unsigned int b0 : 1;
        unsigned int b1 : 1;
        unsigned int pad : 6;
        unsigned int rest : 24;
    };
    Entry entries[0x29];
    unsigned int unkA4;
    unsigned int unkA8;
};

// @fnv 0x00706b90
void __fastcall ResetEntries(TutorialManagerLayout* pThis)
{
    for (unsigned int i = 0; i < 0x29; ++i)
    {
        pThis->entries[i].b0 = 0;
        pThis->entries[i].b1 = 0;
        pThis->entries[i].rest = 0;
    }
    pThis->unkA8 = 0;
    pThis->unkA4 = 0x29;
}

struct FUN_00706cb0_shell : public InterfaceManager
{
    void ResetFieldBC();
};

// @fnv 0x00706cb0
void FUN_00706cb0_shell::ResetFieldBC()
{
    *(int*)((char*)this + 0xbc) = 0;
}

class NiAVObject_Attach : public NiAVObject
{
  public:
    void AttachProperty(NiObject*);
};

// @fnv 0x00706d50
void AttachFaceGenAnimationData(NiAVObject* apObject)
{
    reinterpret_cast<NiAVObject_Attach*>(apObject)->AttachProperty(
        reinterpret_cast<NiObject*>(reinterpret_cast<BSFaceGenNiNode*>(InterfaceManager_GetSingleton())->BSFaceGenNiNode::GetAnimationData()));
}


// @fnv 0x00706d90
// src: COMMUNITY 0x00706d90
bool InterfaceManager::GetIsEmergencyTextureRelease()
{
    return *reinterpret_cast<bool*>(&byte0EC);
}

// @fnv 0x00706dd0
void __cdecl SetFlagAtOffsetDC(bool abValue)
{
    *((bool*)InterfaceManager_GetSingleton() + 0xdc) = abValue;
}

int __cdecl Renderer_GetScreenHeight();

// @fnv 0x00706e20
// src: XBOX_PDB 0x00706e20
float InterfaceManager_GetRealScreenHeight()
{
    return (float)Renderer_GetScreenHeight();
}

int __cdecl Renderer_GetScreenWidth();

// @fnv 0x00706e50
// src: XBOX_PDB 0x00706e50
float __cdecl InterfaceManager_GetRealScreenWidth()
{
    return (float)Renderer_GetScreenWidth();
}

NiRenderer* __cdecl NiXenonRenderer_GetRenderer();
float __cdecl retn1280_0();

struct DummyRTG_00706e90
{
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
    virtual unsigned int GetWidth(unsigned int);
    virtual unsigned int GetHeight(unsigned int);
};

struct DummyRenderer_00706e90
{
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
    virtual DummyRTG_00706e90* GetDefaultRenderTargetGroup();
};

// Returns FUN_00706e80() multiplied by the default render target group's height divided by its width.
// @fnv 0x00706e90
// src: COMMUNITY 0x00706e90
float __cdecl CalculateScaledHeight()
{
    DummyRenderer_00706e90* apRenderer = (DummyRenderer_00706e90*)NiXenonRenderer_GetRenderer();
    return retn1280_0() * ((double)apRenderer->GetDefaultRenderTargetGroup()->GetHeight(0) /
                             (double)apRenderer->GetDefaultRenderTargetGroup()->GetWidth(0));
}

void __cdecl InterfaceManager_NewTimer(void*, float);

// @fnv 0x00706f50
// src: XBOX_PDB 0x00706f50
void __cdecl Interface_NewTimer(void* apPointer, float afLength)
{
    InterfaceManager_NewTimer(apPointer, afLength);
}

void __fastcall UpdateNodeTimers(InterfaceManager*);

// @fnv 0x00706f70
// src: XBOX_PDB 0x00706f70
void Interface_UpdateAllTimers()
{
    UpdateNodeTimers(InterfaceManager_GetSingleton());
}

struct FUN_00714d90_struct
{
    void PushMenuStackEntry(int);
};

// @fnv 0x00706fb0
// src: COMMUNITY 0x00706fb0
void Interface_AddToEnterStack(int aiID)
{
    ((FUN_00714d90_struct*)InterfaceManager_GetSingleton())->PushMenuStackEntry(aiID);
}


// @fnv 0x00706fd0
// src: XBOX_PDB 0x00706fd0
int __cdecl Interface_PopFromEnterStack(int aiID, bool abForceRemoval)
{
    return reinterpret_cast<InterfaceManager*>(InterfaceManager_GetSingleton())
        ->AddMenuStackEntry(aiID, abForceRemoval);
}

struct IMStandIn
{
    void InterfaceManager_SetCurrentFocusTarget(int a, int b, int c);
};
// @fnv 0x00706ff0
// src: XBOX_PDB 0x00706ff0
void __cdecl Interface_SetCurrentFocusTarget(int a)
{
    reinterpret_cast<IMStandIn*>(InterfaceManager_GetSingleton())->InterfaceManager_SetCurrentFocusTarget(a, 0xfc3, 1);
}

// @fnv 0x00707040
// src: COMMUNITY 0x00707040
void* InterfaceManager_GetOverTileTarget()
{
    return *(Tile**)((char*)InterfaceManager_GetSingleton() + 0xcc);
}

// @fnv 0x00707050
// src: XBOX_PDB 0x00707050
void Interface_SetOverTileTarget(void* apTile)
{
    *(Tile**)((char*)InterfaceManager_GetSingleton() + 0xcc) = static_cast<Tile*>(apTile);
}

// @fnv 0x00707070
int __cdecl GetFieldD0()
{
    return *(int*)((char*)InterfaceManager_GetSingleton() + 0xd0);
}

// @fnv 0x00707080
// src: XBOX_PDB 0x00707080
void Interface_SetOverTileMenu(Menu* apMenu)
{
    *(Menu**)((char*)InterfaceManager_GetSingleton() + 0xd0) = apMenu;
}

// @fnv 0x007070a0
void* GetNextTile()
{
    return (Tile*)((TESResponse*)InterfaceManager_GetSingleton())->GetNext();
}

class ModelLoader
{
  public:
    void ModelLoader_ReleaseFile(const char*);
};
extern ModelLoader* g_modelLoader;

// @fnv 0x00707640
// src: XBOX_PDB 0x00707640
void Interface_ReleaseModelFile(const char* apPath)
{
    if (g_modelLoader)
        g_modelLoader->ModelLoader_ReleaseFile(apPath);
}

struct S_004431f0
{
    void* FUN_004431f0(unsigned int);
};
extern S_004431f0* DAT_011d890c;

// Calls FUN_004431f0(1) on DAT_011d890c if it is non-null, then sets DAT_011d890c to null.
// @fnv 0x00707820
// src: COMMUNITY 0x00707820
void Interface_ClearTempModel()
{
    S_004431f0* p0;
    S_004431f0* p1 = DAT_011d890c;
    p0 = p1;
    p0 ? p0->FUN_004431f0(1) : 0;
    DAT_011d890c = 0;
}

namespace fnv_00707930 {
struct Modifier
{
    void SetNeed(bool);
};
// @fnv 0x00707930
// src: XBOX_PDB 0x00707930
void Interface_SetNeedToUpdate(bool a)
{
    reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->SetNeed(a);
}
}  // namespace fnv_00707930

struct FUN_00707950_shell : public InterfaceManager
{
    void SetNeed(bool);
};

// @fnv 0x00707950
void FUN_00707950_shell::SetNeed(bool abNeed)
{
    *((bool*)((char*)this + 0xb0)) = abNeed;
}

bool __cdecl Interface_IsInPipboyMenu();
FORenderedMenu* __cdecl Interface_GetPipboy();
bool __fastcall InterfaceManager_IsInRenderedMenu(InterfaceManager*);

// Returns false if FUN_00705a00() is true and the rendered menu is not initialized; otherwise returns FUN_007079f0(FUN_004b7210()).
// @fnv 0x007079b0
// src: XBOX_PDB 0x007079b0
bool Interface_IsInRenderedMenu()
{
    if (Interface_IsInPipboyMenu() && !Interface_GetPipboy()->GetInitialized())
        return false;
    return InterfaceManager_IsInRenderedMenu(InterfaceManager_GetSingleton());
}

struct FUN_007079f0_shell : public InterfaceManager
{
    bool InterfaceManager_IsInRenderedMenu();
};

bool __cdecl InterfaceManager_IsInPipboyMenu();

// Returns true if the byte at offset 0x168 of this InterfaceManager is set, otherwise returns the result of FUN_007178a0.
// @fnv 0x007079f0
// src: XBOX_PDB 0x007079f0
bool FUN_007079f0_shell::InterfaceManager_IsInRenderedMenu()
{
    return *((bool*)this + 0x168) || InterfaceManager_IsInPipboyMenu();
}
FORenderedMenu* __fastcall FUN_00707af0(InterfaceManager*);

// @fnv 0x00707ad0
// src: XBOX_PDB 0x00707ad0
FORenderedMenu* Interface_GetCurrentRenderedMenu()
{
    return FUN_00707af0(InterfaceManager_GetSingleton());
}

int __cdecl Renderer_GetScreenHeight();

// @fnv 0x00707b60
// src: COMMUNITY 0x00707b60
float Interface_SizeOfAScreenPixelInCrazyAssMenuCoordinates()
{
    static float s_val = InterfaceInterfaceView::GetFirstInterfaceFloat() / Renderer_GetScreenHeight();
    return s_val;
}

extern int g_011d8950;
extern int DAT_011d8954;
extern int DAT_011d8958;
extern int DAT_011d895c;
extern int DAT_011d8964;
extern int g_011d8998;
extern int DAT_011d899c;
extern int DAT_011d89a0;
extern int DAT_011d89a4;
extern int DAT_011d89ac;

bool __cdecl IsConditionMet();
void __cdecl Interface_HandleQueuedMenuOpen();
void __cdecl Interface_ClearMenuQueue();

// @fnv 0x00709470
// src: XBOX_PDB 0x00709470
void __cdecl Interface_QueueMenuCreate(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    if (param_1 != 7)
    {
        g_011d8950 = param_1;
        DAT_011d8954 = param_2;
        DAT_011d8958 = param_3;
        DAT_011d895c = param_4;
        DAT_011d8964 = param_5;
    }
    else
    {
        g_011d8998 = param_1;
        DAT_011d899c = param_2;
        DAT_011d89a0 = param_3;
        DAT_011d89a4 = param_4;
        DAT_011d89ac = param_5;
    }
    if (!IsConditionMet())
    {
        Interface_HandleQueuedMenuOpen();
        Interface_ClearMenuQueue();
    }
}

// @fnv 0x00709bc0
// src: XBOX_PDB 0x00709bc0
bool Interface_IsPipboyOpening()
{
    return *(int*)((char*)InterfaceManager_GetSingleton() + 0x4bc) == 2;
}

// @fnv 0x00709c00
// src: XBOX_PDB 0x00709c00
bool __cdecl Interface_IsPipboyOpen()
{
    return *(int*)((char*)InterfaceManager_GetSingleton() + 0x4bc) == 3;
}

class TESRace;
#include "../../../include/BSSimpleList.h"

// @fnv 0x00726c40
int __fastcall GetRaceCount(char* pThis)
{
    return ((BSSimpleList<TESRace*>*)(pThis + 4))->ItemsInList();
}

struct StrHelper
{
    operator const char*() const;
};
struct StrOwner
{
    int pad;
    StrHelper s;
    const char* SkyObject_GetNiNode();
};
// @fnv 0x007fa950
// src: COMMUNITY 0x007fa950
const char* StrOwner::SkyObject_GetNiNode()
{
    return s;
}


// @fnv 0x009373f0
// src: XBOX_PDB 0x009373f0
bool InterfaceManager::TESTextureList_GetTextureCount()
{
    return *reinterpret_cast<bool*>(this);
}

namespace fnv_00703e80 {
struct Modifier
{
    unsigned char GetKey();
};
InterfaceManager* InterfaceManager_GetSingleton();
bool QueueMessage(const char*, const char*, const char*, int, void*, int, int, const char*, char**, int, int, int,
                  float, float, float);
// Shows a warning message via QueueMessage when the interface manager's modifier key is held, returning the result; otherwise returns false.
// @fnv 0x00703e80
// src: XBOX_PDB 0x00703e80
bool Interface_CreateMessageMenu(const char* aText, const char* apcIconFilename, const char* apcTitle, void* afpResult,
                  int aiFirstButtonResult, int aiWarningContext, float afBackgroundTextureOpacityOverride,
                  float afMenuWidthOverride, const char* axFirst, ...)
{
    if (InterfaceManager_GetSingleton() && ((Modifier*)InterfaceManager_GetSingleton())->GetKey())
    {
        char* xlist = (char*)&axFirst + 4;
        bool bresult =
            QueueMessage(aText, apcIconFilename, apcTitle, 0, afpResult, aiFirstButtonResult, aiWarningContext, axFirst,
                         &xlist, 1, -1, -1, 0.0f, afBackgroundTextureOpacityOverride, afMenuWidthOverride);
        xlist = 0;
        return bresult;
    }
    return false;
}
}  // namespace fnv_00703e80

namespace fnv_007053b0 {
struct Modifier
{
    unsigned char GetKey();
};
struct HUDHelper
{
    void FUN_00775920();
};
extern HUDMainMenu* g_pHudMainMenuInstance;
InterfaceManager* InterfaceManager_GetSingleton();
// @fnv 0x007053b0
// src: COMMUNITY 0x007053b0
void HUDMainMenu_ResetQueuedMessagesAndSubtitles_()
{
    if (InterfaceManager_GetSingleton() && ((Modifier*)InterfaceManager_GetSingleton())->GetKey() && g_pHudMainMenuInstance)
        ((HUDHelper*)g_pHudMainMenuInstance)->FUN_00775920();
}
}  // namespace fnv_007053b0

namespace fnv_00705b70 {
struct Modifier
{
    unsigned char GetKey();
};
struct FUN_0070b790_shell
{
    void InterfaceManager_SetStatsPageNumbe(char);
};
namespace fnv_0070b810 {
struct FUN_0070b810_shell
{
    void InterfaceManager_SetInventoryPageNumber(char);
};
}
namespace fnv_0070b870 {
struct S0b870
{
    void InterfaceManager_SetMapPageNumber(char);
};
}
struct FUN_0070b8d0_shell
{
    void InterfaceManager_SetCurrentMainMenu(int);
};
InterfaceManager* InterfaceManager_GetSingleton();
int MinInt(int, int);
int _max(int, char);
// If the interface manager exists and a key is pressed, updates the stats, inventory and map tab states and selects the given menu, defaulting to 0x3eb.
// @fnv 0x00705b70
// src: COMMUNITY 0x00705b70
void Interface_SetMainMenuDefaults(char aiStatsTab, char aiInventoryTab, char aiMapTab, int aiWhichMenu)
{
    if (InterfaceManager_GetSingleton() && ((Modifier*)InterfaceManager_GetSingleton())->GetKey())
    {
        ((FUN_0070b790_shell*)InterfaceManager_GetSingleton())->InterfaceManager_SetStatsPageNumbe(MinInt(4, _max(0, aiStatsTab)));
        ((fnv_0070b810::FUN_0070b810_shell*)InterfaceManager_GetSingleton())->InterfaceManager_SetInventoryPageNumber(MinInt(4, _max(0, aiInventoryTab)));
        ((fnv_0070b870::S0b870*)InterfaceManager_GetSingleton())->InterfaceManager_SetMapPageNumber(MinInt(4, _max(0, aiMapTab)));
        if (aiWhichMenu != 0x3eb && aiWhichMenu != 0x3ea && aiWhichMenu != 0x3ff)
            aiWhichMenu = 0x3eb;
        ((FUN_0070b8d0_shell*)InterfaceManager_GetSingleton())->InterfaceManager_SetCurrentMainMenu(aiWhichMenu);
    }
}
}  // namespace fnv_00705b70

struct DialogH
{
    static bool IsInDialog();
};
struct fnv_007aa480
{
    static void ClearAllElements();
};
struct FocusH
{
    void FocusOnActor(MobileObject*, float, bool);
};
struct Im7181
{
    void SetRenderedMenu(int);
};
extern PlayerCharacter* g_thePlayer;
extern unsigned char DAT_011d8a85;
InterfaceManager* InterfaceManager_GetSingleton();
MobileObject* GetDialogCastSound();
void HUDMainMenu_ResetQueuedMessagesAndSubtitles_();
void VATSCameraData_Accept();
void Interface_CloseAllSupportMenus(int);
void ClearMapMenuNote();
void __fastcall ResetEntries(void*);
void Interface_PopFromEnterStack(int, int);
void VATSMenu_ClearTargetList();
void MenuTopicManager_Destroy();
void ResetHUDMainMenu();
MobileObject* GetDialogCastSound();
// @fnv 0x00706ae0
void ResetInterfaceState()
{
    DAT_011d8a85 = 1;
    HUDMainMenu_ResetQueuedMessagesAndSubtitles_();
    ResetHUDMainMenu();
    if (DialogH::IsInDialog())
    {
        ((FocusH*)g_thePlayer)->FocusOnActor(GetDialogCastSound(), 0.0f, true);
        MenuTopicManager_Destroy();
    }
    VATSCameraData_Accept();
    VATSMenu_ClearTargetList();
    Interface_CloseAllSupportMenus(0);
    fnv_007aa480::ClearAllElements();
    StatsMenu::ClearPerks();
    ClearMapMenuNote();
    MapMenu::StopMapMenuSounds();
    Interface_PopFromEnterStack(1, 1);
    ((Im7181*)InterfaceManager_GetSingleton())->SetRenderedMenu(0);
    *(int*)((char*)InterfaceManager_GetSingleton() + 0x4bc) = 0;
    ResetEntries((char*)InterfaceManager_GetSingleton() + 0x4d4);
}

struct NavMesh;
struct S3de0
{
    void InterfaceManager_RemoveTileFromUpdateList(NavMesh*);
};
struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};
struct FUN_00706cb0_shell2
{
    void ResetFieldBC();
};
InterfaceManager* InterfaceManager_GetSingleton();
// @fnv 0x00706c20
void ClearInterfaceRefs(unsigned int a)
{
    InterfaceManager* im = InterfaceManager_GetSingleton();
    if (*(unsigned int*)((char*)im + 0xcc) == a)
    {
        *(unsigned int*)((char*)im + 0xcc) = 0;
        *(unsigned int*)((char*)im + 0xd0) = 0;
    }
    if (*(unsigned int*)((char*)im + 0xd4) == a)
    {
        *(unsigned int*)((char*)im + 0xd4) = 0;
        *(unsigned int*)((char*)im + 0xd8) = 0;
    }
    if (((TESAmmoInitCalls*)im)->GetFieldBC() == a)
        ((FUN_00706cb0_shell2*)im)->ResetFieldBC();
    ((S3de0*)im)->InterfaceManager_RemoveTileFromUpdateList((NavMesh*)a);
}

struct QuantityData
{
    Tile* GetItem();
};

// @fnv 0x00707a30
// src: COMMUNITY 0x00707a30
bool Menu_ShouldScaleByResolutionRatio(QuantityData* apComponent)
{
    Tile* pTile = apComponent ? apComponent->GetItem() : 0;
    if (!pTile)
        return false;
    int iFilter = (int)pTile->GetFloat(0xfaa);
    int m_uiSoundID = (int)pTile->GetFloat(0xfa4);
    return iFilter == 0x70 || m_uiSoundID == 0x421 || m_uiSoundID == 0x41f || m_uiSoundID == 0x40c;
}

namespace fnv_00704af0 {
struct Modifier
{
    unsigned char GetKey();
};
bool __cdecl Interface_IsMenuIDVisible(int, unsigned int);
struct MenuHelper
{
    void UpdateOption(int);
};
void __cdecl BarterMenu_ForceBarterUpdate(int);
void __cdecl RecipeMenu_ForceRecipeUpdate(int);
void __cdecl ContainerMenu_ForceContainerUpdate();

// @fnv 0x00704af0
// src: COMMUNITY 0x00704af0
void Interface_UpdateInventory()
{
    if (InterfaceManager_GetSingleton())
    {
        if (reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        {
            if (InterfaceInterfaceView::IsPipBoyOpen())
            {
                InventoryMenu::UpdateItemList();
            }
            else if (InterfaceInterfaceView::GetStatsMenuVisible())
            {
                reinterpret_cast<MenuHelper*>(reinterpret_cast<Tile*>(Tile::FindMenuById(0x3eb))->GetMenu())
                    ->UpdateOption(4);
            }
            else if (Interface_IsMenuIDVisible(0x41d, 0))
            {
                BarterMenu_ForceBarterUpdate(1);
            }
            else if (Interface_IsMenuIDVisible(0x435, 0))
            {
                RecipeMenu_ForceRecipeUpdate(1);
            }
            else if (Interface_IsMenuIDVisible(0x3f0, 0))
            {
                ContainerMenu_ForceContainerUpdate();
            }
        }
    }
}
}  // namespace fnv_00704af0

namespace fnv_00705420 {
struct Modifier
{
    unsigned char GetKey();
};

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
struct AttachMsg
{
    int a;
    char name[260];
    char flag;
};
void __cdecl ShowRegionData(AttachMsg*);

// @fnv 0x00705420
// src: COMMUNITY 0x00705420
void __cdecl Interface_SetRegionText(int a, ::BSStringT<char> name, bool flag)
{
    if (InterfaceManager_GetSingleton())
    {
        if (reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        {
            AttachMsg msg;
            msg.flag = flag;
            msg.a = a;
            if ((const char*)name)
                TaskQueueInterface::CopyStringToBuffer(msg.name, 260, (const char*)name);
            else
                msg.name[0] = 0;
            ShowRegionData(&msg);
        }
    }
}
}  // namespace fnv_00705420

namespace fnv_00702330 {
class Modifier
{
  public:
    unsigned char GetKey(void);
};

extern "C" void __cdecl InterfaceManager_Destroy(void);

// Calls FUN_004b7210, and if it returns non-null and its GetKey result is nonzero, calls FUN_0070a0b0.
// @fnv 0x00702330
// src: COMMUNITY 0x00702330
void Interface_Free()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        InterfaceManager_Destroy();
}
}  // namespace fnv_00702330

Tile* __cdecl FindMenuById(int);
bool __cdecl Interface_IsPipboyOpen();

// @fnv 0x00702680
// src: XBOX_PDB 0x00702680
bool __cdecl Interface_IsMenuIDVisible(InterfaceInterfaceView::enumMenus aeMenuID, unsigned int abFadeStatesThatCountAsVisible)
{
    Tile* ptile;

    if (InterfaceManager_GetSingleton() && ((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        if (aeMenuID == InterfaceInterfaceView::eMainFour)
            return Interface_IsPipboyOpen() && (Interface_IsMenuIDVisible(InterfaceInterfaceView::eStatsMenu, abFadeStatesThatCountAsVisible) ||
                                      Interface_IsMenuIDVisible(InterfaceInterfaceView::eInventoryMenu, abFadeStatesThatCountAsVisible) ||
                                      Interface_IsMenuIDVisible(InterfaceInterfaceView::eRepairMenu, abFadeStatesThatCountAsVisible) ||
                                      Interface_IsMenuIDVisible(InterfaceInterfaceView::eItemModMenu, abFadeStatesThatCountAsVisible) ||
                                      Interface_IsMenuIDVisible(InterfaceInterfaceView::eMapMenu, abFadeStatesThatCountAsVisible));
        if (abFadeStatesThatCountAsVisible)
        {
            ptile = FindMenuById(aeMenuID);
            if (ptile && ptile->GetMenu() &&
                !(ptile->GetMenu()->GetVisibilityState() & abFadeStatesThatCountAsVisible))
                return false;
        }
        return Menu::IsMenuVisible(static_cast<Interface::enumMenus>(aeMenuID));
    }
    return false;
}

namespace fnv_00702960 {
struct Modifier
{
    unsigned char GetKey();
};

extern BGSMoviePlayer* DAT_0126fac4;

// If FUN_004b7210() returns non-null and its GetKey() is nonzero, calls FUN_00ec17c0() on DAT_0126fac4.
// @fnv 0x00702960
// src: GUESS 0x00702960 (confidence: low)
void Object_ProcessState_00702960()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        DAT_0126fac4->IsPlaying();
}
}  // namespace fnv_00702960

namespace fnv_00703000 {
struct Modifier
{
    unsigned char GetKey();
    void InterfaceManager_ToggleDebugTextVisible();
};

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls FUN_00703030 on it.
// @fnv 0x00703000
// src: XBOX_PDB 0x00703000
void Interface_ToggleDebugTextVisible()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->InterfaceManager_ToggleDebugTextVisible();
}
}  // namespace fnv_00703000

namespace fnv_007030c0 {
struct Modifier
{
    unsigned char GetKey();
    void SetTileValues(int, int);
};

// If FUN_004b7210() returns a Modifier whose GetKey() is nonzero, forwards a1 and a2 to its SetTileValues.
// @fnv 0x007030c0
// src: COMMUNITY 0x007030c0
void Interface_UpdateScreenShape(int aiArg1, int aiArg2)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->SetTileValues(aiArg1, aiArg2);
}
}  // namespace fnv_007030c0

namespace fnv_00703390 {
class Modifier
{
  public:
    unsigned char GetKey();
};


struct FUN_009b4440_holder
{
    void* Projectile_GetDesiredTarget();
};

// If FUN_004b7210() returns a Modifier with a nonzero key, returns its FUN_009b4440() result; otherwise returns 0.
// @fnv 0x00703390
// src: XBOX_PDB 0x00703390
void* Interface_GetTelekinesisREFR()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return reinterpret_cast<FUN_009b4440_holder*>(InterfaceManager_GetSingleton())->Projectile_GetDesiredTarget();
    return 0;
}
}  // namespace fnv_00703390

char __cdecl ConsumeByteAtE4();
extern char DAT_0119f349;

// @fnv 0x00704130
// src: GUESS 0x00704130 (confidence: low)
void __cdecl Interface_SetDAT0119f349()
{
    DAT_0119f349 = ConsumeByteAtE4();
}

namespace fnv_007043d0 {
struct Modifier
{
    unsigned char GetKey();
};

bool GetMapMenuFogOfWar();

// @fnv 0x007043d0
// src: XBOX_PDB 0x007043d0
bool Interface_GetFogOfWarEnabled()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return GetMapMenuFogOfWar();
    return 0;
}
}  // namespace fnv_007043d0

namespace fnv_00704420 {
struct Modifier
{
    unsigned char GetKey();
};

bool SetMapMenuFogOfWar(bool);

// If FUN_004b7210 returns a non-null object whose GetKey is nonzero, forwards abSetTo to FUN_00704450.
// @fnv 0x00704420
// src: XBOX_PDB 0x00704420
void Interface_SetFogOfWarEnabled(bool abSetTo)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        SetMapMenuFogOfWar(abSetTo);
}
}  // namespace fnv_00704420

extern MapMenu* DAT_011da368;

// @fnv 0x00704450
// src: COMMUNITY 0x00704450
void SetMapMenuFogOfWar(char bShow)
{
    if (DAT_011da368)
        reinterpret_cast<char&>(DAT_011da368->m_bNeedsMapUpdate) = bShow;
}

extern "C" void __cdecl MapMenu_ResetCurrentNoteIfEqualTo(int);

// @fnv 0x00704470
// src: COMMUNITY 0x00704470
void __cdecl MapMenu_ResetCurrentNoteIfEqualTo_(int arg)
{
    if (arg)
    {
        MapMenu_ResetCurrentNoteIfEqualTo(arg);
    }
}

namespace fnv_00704690 {
class Modifier
{
  public:
    unsigned char GetKey();
};
void CreateRepairServicesMenu(unsigned int);

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, forwards arg to CreateRepairServicesMenu.
// @fnv 0x00704690
// src: COMMUNITY 0x00704690
void RepairServicesMenu_Create_(unsigned int arg)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        CreateRepairServicesMenu(arg);
}
}  // namespace fnv_00704690

extern ContainerMenu* DAT_011d93f8;

// @fnv 0x00704bc0
// src: COMMUNITY 0x00704bc0
void ContainerMenu_ForceContainerUpdate()
{
    if (DAT_011d93f8)
        DAT_011d93f8->ContainerMenu_UpdateLists(0);
}

namespace fnv_00704f80 {
struct Modifier
{
    bool GetKey();
};

extern "C" void __cdecl InitInventoryMenu(unsigned int, unsigned int);

// @fnv 0x00704f80
// src: COMMUNITY 0x00704f80
void ShowBarterMenu_(unsigned int a1, unsigned int a2)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        InitInventoryMenu(a1, a2);
}
}  // namespace fnv_00704f80

namespace fnv_00704fc0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

extern "C" void __cdecl CreateRecipeMenu(int, int);

// @fnv 0x00704fc0
// src: COMMUNITY 0x00704fc0
void Interface_CreateRecipeMenu(int a1, int a2)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        CreateRecipeMenu(a1, a2);
}
}  // namespace fnv_00704fc0

void GetContainerMenuMode();

// @fnv 0x00705040
// src: COMMUNITY 0x00705040
void GetContainerMenuMode_()
{
    GetContainerMenuMode();
}

namespace fnv_00705050 {
extern ContainerMenu* DAT_011d93f8;

// @fnv 0x00705050
// src: COMMUNITY 0x00705050
void* GetContainerMenuMode()
{
    if (DAT_011d93f8)
    {
        return *(void**)((char*)DAT_011d93f8 + 0x80);
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_00705050

// @fnv 0x00705770
// src: COMMUNITY 0x00705770
unsigned int ret_1012()
{
    return 0x3f4;
}

namespace fnv_00705800 {
class Modifier
{
  public:
    unsigned char GetKey();
};

// @fnv 0x00705800
// src: COMMUNITY 0x00705800
void Interface_ForceReload()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        StartMenu::Create(true, true);
}
}  // namespace fnv_00705800

namespace fnv_00705830 {
struct Modifier
{
    unsigned char GetKey();
};

void CreateLockpickMenu(int, int, unsigned char);

// @fnv 0x00705830
// src: XBOX_PDB 0x00705830
void Interface_CreateLockPickMenu(int a1, int a2, unsigned char a3)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        CreateLockpickMenu(a1, a2, a3);
}
}  // namespace fnv_00705830

extern Setting g_011c3ea4;
extern int g_011d8950;
extern int DAT_011d8960;

void DialogMenu_ServiceStart();
void GetOrCreateMenuTile(int);

// @fnv 0x00705870
// src: COMMUNITY 0x00705870
void Interface_CreateRaceSexMenu(int arg)
{
    if (DialogMenu_IsDialogActive())
        DialogMenu_ServiceStart();

    if (*g_011c3ea4.Int() > 1 && g_011d8950 == 0)
    {
        g_011d8950 = 5;
        DAT_011d8960 = arg;
    }
    else
    {
        GetOrCreateMenuTile(arg);
    }
}

namespace fnv_00705a60 {
struct Modifier
{
    unsigned char GetKey();
    void InterfaceManager_DumpMenuPackingInfo();
};

// @fnv 0x00705a60
// src: COMMUNITY 0x00705a60
void Interface_DumpMenuPackingInfo()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->InterfaceManager_DumpMenuPackingInfo();
}
}  // namespace fnv_00705a60

namespace fnv_00705ad0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

struct FUN_00705b10_Dummy
{
    void Set(int);
};

// @fnv 0x00705ad0
// src: COMMUNITY 0x00705ad0
void Interface_SetDragDroppingState(int arg)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        reinterpret_cast<FUN_00705b10_Dummy*>(InterfaceManager_GetSingleton())->Set(arg);
}
}  // namespace fnv_00705ad0

namespace fnv_00705d90 {
struct Modifier
{
    unsigned char GetKey();
    int InterfaceManager_GetLastPipboyTab();
};

// @fnv 0x00705d90
// src: COMMUNITY 0x00705d90
int Interface_GetLastPipboyTab()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->InterfaceManager_GetLastPipboyTab();
    return -1;
}
}  // namespace fnv_00705d90

namespace fnv_00706230 {
struct Modifier
{
    unsigned char GetKey();
};

extern "C" void __cdecl SurgeryMenu_SetCursorPos(int, int);

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, forwards a and b to FUN_007e41f0.
// @fnv 0x00706230
// src: COMMUNITY 0x00706230
void Interface_SetSurgeryCursorPos(int aiArg1, int aiArg2)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        SurgeryMenu_SetCursorPos(aiArg1, aiArg2);
}
}  // namespace fnv_00706230

namespace fnv_00706270 {
class Modifier
{
  public:
    unsigned char GetKey();
};

void LevelUpMenu_Create();

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls FUN_00784c80.
// @fnv 0x00706270
// src: COMMUNITY 0x00706270
void LevelUpMenu_Create_()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        LevelUpMenu_Create();
}
}  // namespace fnv_00706270

extern MapMenu* DAT_011da368;

// Returns the value at offset 0x80 of DAT_011da368 minus 0x20, or 4 when DAT_011da368 is null.
// @fnv 0x00706830
// src: COMMUNITY 0x00706830
char MapMenu_GetCurrentMapPage()
{
    int v;
    if (DAT_011da368)
        v = DAT_011da368->m_iMapDisplayMode - 0x20;
    else
        v = 4;
    return (char)v;
}

// Folded 0x005e3fc0 getter, used here on the UI singleton.
unsigned int __fastcall GetInterfaceAuxiliaryNode(InterfaceManager*);
// @fnv 0x00706d10
// src: COMMUNITY 0x00706d10
unsigned int Interface_GetDebugTextRoot()
{
    return GetInterfaceAuxiliaryNode(InterfaceManager_GetSingleton());
}

void __cdecl InterfaceManager_PlayMenuSound(int aiSoundIndex);

// @fnv 0x00706f30
// src: XBOX_PDB 0x00706f30
void Interface_PlayMenuSound(int aiSoundIndex)
{
    InterfaceManager_PlayMenuSound(aiSoundIndex);
}

void __cdecl RemoveNodeById(int);
// @fnv 0x00706f90
// src: COMMUNITY 0x00706f90
void __cdecl Interface_ClearTimer(int aiValue)
{
    InterfaceManager_GetSingleton();
    RemoveNodeById(aiValue);
}


// @fnv 0x00709920
const char* Tile::GetTypeName()
{
    return "TILE";
}

// @fnv 0x00709970
const char* TileRect::GetTypeName()
{
    return "RECT";
}

// @fnv 0x00709a50
const char* __fastcall GetTileMenuTypeName(TileMenu* menu)
{
    return "MENU";
}

// @fnv 0x00709be0
bool IsSomethingZero()
{
    return *(int*)((char*)InterfaceManager_GetSingleton() + 0x4bc) == 0;
}

void HUDMainMenu_InitGunScope(int a1);

// @fnv 0x00709c20
// src: XBOX_PDB 0x00709c20
void Interface_InitGunScope(int a1)
{
    HUDMainMenu_InitGunScope(a1);
}

extern int DAT_011da204;

// @fnv 0x0078e0d0
// src: XBOX_PDB 0x0078e0d0
void LockPickMenu_Close()
{
    if (DAT_011da204)
        *(int*)((char*)DAT_011da204 + 0x28) = 7;
}

namespace fnv_00703150 {
struct Modifier
{
    unsigned char GetKey();
};
extern "C" unsigned char __cdecl Interface_GetFullHelp();

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, returns the byte at offset 0xdd of that object; otherwise returns 0.
// @fnv 0x00703150
// src: XBOX_PDB 0x00703150
unsigned char Interface_GetFullHelp()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(InterfaceManager_GetSingleton()) + 0xdd);
    return 0;
}
}  // namespace fnv_00703150

namespace fnv_00703e10 {
class ConsoleManager
{
  public:
    static ConsoleManager* __cdecl Instance(bool);
    bool IsConsoleActive(void);
    void MenuConsole_ToggleVisible();
};

class Modifier
{
  public:
    unsigned char GetKey(void);
};

class FUN_00714d90_struct
{
  public:
    void PushMenuStackEntry(int);
};

// @fnv 0x00703e10
// src: COMMUNITY 0x00703e10
void __cdecl Interface_OpenConsole()
{
    if (InterfaceManager_GetSingleton() != 0 && ((Modifier*)InterfaceManager_GetSingleton())->GetKey() != 0 && ConsoleManager::Instance(0) != 0 &&
        !ConsoleManager::Instance(1)->IsConsoleActive())
    {
        ConsoleManager::Instance(1)->MenuConsole_ToggleVisible();
        ((FUN_00714d90_struct*)InterfaceManager_GetSingleton())->PushMenuStackEntry(3);
    }
}
}  // namespace fnv_00703e10

// @fnv 0x00704400
// src: COMMUNITY 0x00704400
char __cdecl GetMapMenuFogOfWar()
{
    if (DAT_011da368 != 0)
    {
        return reinterpret_cast<char&>(DAT_011da368->m_bNeedsMapUpdate);
    }
    else
    {
        return 1;
    }
}

namespace fnv_00705cb0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

// If FUN_004b7210() returns a modifier whose GetKey() is nonzero, returns its IsDone() result; otherwise returns -1.
// @fnv 0x00705cb0
// src: COMMUNITY 0x00705cb0
char Interface_GetInventoryPageNumber()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return reinterpret_cast<ActiveEffect*>(InterfaceManager_GetSingleton())->IsDone();
    return -1;
}
}  // namespace fnv_00705cb0

extern "C" char __cdecl GetInterfaceManagerResult();
extern "C" char __cdecl Interface_GetInventoryPageNumber();
extern "C" char __cdecl Interface_GetMagicPageNumber();
extern "C" char __cdecl Interface_GetMapPageNumber();
extern "C" int __cdecl Interface_GetLastPipboyTab();

extern TESSaveLoadGame* g_TESSaveLoadGame;

// Reads the inventory, stats, map and magic tab values plus the current main menu, clamps each tab to at least 1, and writes them to the save/load game.
// @fnv 0x00706610
void __cdecl SaveMenuTabStates()
{
    char acInventoryTab;
    char acStatsTab4;
    char acMagicTab;
    char acMapTab9;
    int icurrentMainMenu;

    acInventoryTab = GetInterfaceManagerResult();
    acStatsTab4 = Interface_GetInventoryPageNumber();
    acMapTab9 = Interface_GetMagicPageNumber();
    acMagicTab = Interface_GetMapPageNumber();
    icurrentMainMenu = Interface_GetLastPipboyTab();

    if (acInventoryTab < 1)
        acInventoryTab = 1;
    if (acStatsTab4 < 1)
        acStatsTab4 = 1;
    if (acMapTab9 < 1)
        acMapTab9 = 1;
    if (acMagicTab < 1)
        acMagicTab = 1;

    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&acInventoryTab, 1);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&acStatsTab4, 1);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&acMapTab9, 1);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&acMagicTab, 1);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&icurrentMainMenu, 4);
}

struct FUN_00406f90_this
{
    int VSPrintF(char const*, char*);
};
// Calls the object's FUN_00406f90 with apFormat and the address just past it, then returns its result.
// @fnv 0x00406f60
// src: XBOX_PDB 0x00406f60
int __cdecl BSStringT_char_SPrintF(FUN_00406f90_this* p, char const* apFormat, ...)
{
    int ires;
    char* marker;
    marker = (char*)(&apFormat + 1);
    ires = p->VSPrintF(apFormat, marker);
    marker = 0;
    return ires;
}

namespace fnv_00703030 {
struct FUN_00703060_shell
{
    char _pad[0x7c];
    bool b7c;
    void InterfaceManager_SetDebugTextVisible(bool);
    void InterfaceManager_ToggleDebugTextVisible();
};
// Calls FUN_00703060 with 0 when b7c is set, otherwise with 1.
// @fnv 0x00703030
// src: XBOX_PDB 0x00703030
void FUN_00703060_shell::InterfaceManager_ToggleDebugTextVisible()
{
    if (b7c)
        InterfaceManager_SetDebugTextVisible(0);
    else
        InterfaceManager_SetDebugTextVisible(1);
}
}  // namespace fnv_00703030

namespace fnv_00703080 {
struct Modifier
{
    char GetKey();
};
struct Holder
{
    void UpdateTilePosition(float, float);
};
// If FUN_004b7210() returns a non-null object whose GetKey() is nonzero, calls UpdateTilePosition(a1, a2) on it.
// @fnv 0x00703080
// src: COMMUNITY 0x00703080
void Interface_SetCursorPos(float afValue1, float afValue2)
{
    if (InterfaceManager_GetSingleton() && (unsigned char)reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        reinterpret_cast<Holder*>(InterfaceManager_GetSingleton())->UpdateTilePosition(afValue1, afValue2);
}
}  // namespace fnv_00703080

namespace fnv_007037e0 {
class Modifier
{
  public:
    char GetKey();
    void ClearMenuIDs();
};
// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls ClearMenuIDs on it.
// @fnv 0x007037e0
// src: XBOX_PDB 0x007037e0
void Interface_EmergencyCloseAllMenusAndBreakStuff()
{
    if (InterfaceManager_GetSingleton() && (unsigned char)reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->ClearMenuIDs();
}
}  // namespace fnv_007037e0

namespace fnv_00703810 {
struct Modifier
{
    char GetKey();
};
InterfaceManager* InterfaceManager_GetSingleton();

// If the interface manager exists and its modifier key is set, culls or unculls the tile's scene node according to abVisible.
// @fnv 0x00703810
// src: COMMUNITY 0x00703810
void Interface_SetMenuSystemVisible(bool abVisible)
{
    if (InterfaceManager_GetSingleton() && (unsigned char)((Modifier*)InterfaceManager_GetSingleton())->GetKey())
    {
        ((Tile*)InterfaceManager_GetSingleton()->CombatController_GetCombatState())->GetModel_0056c7f0()->SetAppCulled(!abVisible);
    }
}
}  // namespace fnv_00703810

namespace fnv_00705d10 {
struct Modifier
{
    char GetKey();
};
struct IdleAnimationManager
{
    bool InterfaceManager_GetMagicPageNumber();
};
// Returns FUN_00843150's result when FUN_004b7210 is non-null and GetKey is nonzero; otherwise returns -1.
// @fnv 0x00705d10
// src: COMMUNITY 0x00705d10
char Interface_GetMagicPageNumber()
{
    if (InterfaceManager_GetSingleton() && (unsigned char)reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return reinterpret_cast<IdleAnimationManager*>(InterfaceManager_GetSingleton())->InterfaceManager_GetMagicPageNumber();
    return -1;
}
}  // namespace fnv_00705d10

namespace fnv_00705d50 {
struct Modifier
{
    char GetKey();
};
struct Byte15Accessor
{
    char GetByte15();
};
// If FUN_004b7210() returns a non-null object whose GetKey() is nonzero, returns the result of GetByte15() on it; otherwise returns -1.
// @fnv 0x00705d50
// src: COMMUNITY 0x00705d50
char Interface_GetMapPageNumber()
{
    if (InterfaceManager_GetSingleton() && (unsigned char)reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        return reinterpret_cast<Byte15Accessor*>(InterfaceManager_GetSingleton())->GetByte15();
    return -1;
}
}  // namespace fnv_00705d50

struct UnnamedClass_00705dd0
{
    char _pad[0x9c];
    Tile* m_9c;
    int InterfaceManager_GetLastPipboyTab();
};
// @fnv 0x00705dd0
// src: COMMUNITY 0x00705dd0
int UnnamedClass_00705dd0::InterfaceManager_GetLastPipboyTab()
{
    return (int)m_9c->GetFloat(0x1771);
}

// @fnv 0x007060a0
void* FORenderedTerminal::DestroyIfFlagged(unsigned int flags)
{
    FUN_007060d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

int __cdecl MinInt(int, int);

struct FUN_00706810_Class
{
    int __thiscall InterfaceManager_TutorialManager_GetSaveLoadSize();
};

// @fnv 0x00706810
// src: COMMUNITY 0x00706810
int __thiscall FUN_00706810_Class::InterfaceManager_TutorialManager_GetSaveLoadSize()
{
    return MinInt(1, 1) + 5;
}

struct Dummy00712450
{
    int SetNodeAlpha();
};
Dummy00712450* __stdcall _FUN_004b7210(int, float, float);
// Calls _FUN_004b7210 with a, b and c, then returns the result of SetNodeAlpha on the returned object.
// @fnv 0x00707010
// src: COMMUNITY 0x00707010
int Interface_RecursiveFade(int aiArg, float afArg1, float afArg2)
{
    return _FUN_004b7210(aiArg, afArg1, afArg2)->SetNodeAlpha();
}

class NiQuaternion;
class hkVector4;
namespace fnv_00706860 {
struct SaveLoadFile;

typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];

InterfaceManager* InterfaceManager_GetSingleton();


void InventoryMenu_SetCurrentInventoryPage(unsigned char);
void MapMenu_SetCurrentMapPage(unsigned char);
void MapMenu_SetLocalMapMagnification(float);
void MapMenu_SetWorldMapMagnification(float);
struct TutorialState
{
    void LoadTutorialSeenFlags(char*);
};
void* memset(void*, int, unsigned int);
// Reads menu page indices and map magnifications from the load buffer, applies them to the UI, and reads a settings blob when the version is at least 12.
// @fnv 0x00706860
void LoadMenuState(BGSLoadGameBuffer* apLoadGameBuffer)
{
    unsigned char cstatsPage;
    int ifrontMostMenu;
    unsigned char cinventoryPage;
    float fworldMapMagnification;
    unsigned char cmapPage;
    float flocalMapMagnification;
    ifrontMostMenu = 0;
    cstatsPage = 0;
    cinventoryPage = 0;
    cmapPage = 0;
    apLoadGameBuffer->ReadDataBlock(&ifrontMostMenu, 4);
    apLoadGameBuffer->ReadDataBlock(&cstatsPage, 1);
    apLoadGameBuffer->ReadDataBlock(&cinventoryPage, 1);
    apLoadGameBuffer->ReadDataBlock(&cmapPage, 1);
    reinterpret_cast<Tile*>(InterfaceManager_GetSingleton()->CombatController_GetCombatState())->Set(0x1771, ifrontMostMenu);
    StatsMenu::SetStatsPage(cstatsPage);
    InventoryMenu_SetCurrentInventoryPage(cinventoryPage);
    MapMenu_SetCurrentMapPage(cmapPage);
    flocalMapMagnification = 0;
    fworldMapMagnification = 0;
    apLoadGameBuffer->ReadDataBlock(&flocalMapMagnification, 4);
    apLoadGameBuffer->ReadDataBlock(&fworldMapMagnification, 4);
    MapMenu_SetLocalMapMagnification(flocalMapMagnification);
    MapMenu_SetWorldMapMagnification(fworldMapMagnification);
    if (apLoadGameBuffer->GetVersion() >= 12)
    {
        unsigned int isettingsSize;
        char psettings[100];
        memset(psettings, 0, 100);
        isettingsSize = 0;
        apLoadGameBuffer->ReadDataBlock(&isettingsSize, 4);
        apLoadGameBuffer->ReadDataBlock(psettings, isettingsSize);
        reinterpret_cast<TutorialState*>((char*)InterfaceManager_GetSingleton() + 0x4d4)->LoadTutorialSeenFlags(psettings);
    }
    else
    {
        char ptempString[260];
        apLoadGameBuffer->LoadString(ptempString);
    }
}
}  // namespace fnv_00706860

namespace fnv_00703610 {

class MenuPC : public Menu
{
  public:
    void SetFadeState(int);
    Tile* GetTile();
};

struct Im7181
{
    void SetRenderedMenu(int);
};
Tile* __cdecl FindMenuById(int);
void __cdecl Interface_CloseContainer();
void __cdecl CloseStartMenu(bool);

// @fnv 0x00703610
// src: XBOX_PDB 0x00703610
void __cdecl Interface_HideMenus()
{
    Tile* pinv;
    Tile* prepair;
    Tile* pstat;
    InterfaceManager* pim;
    Tile* pmap;
    Tile* pitemmod;

    if (InterfaceManager_GetSingleton() && ((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        pim = InterfaceManager_GetSingleton();
        pstat = (FindMenuById)(InterfaceInterfaceView::eStatsMenu);
        pinv = (FindMenuById)(InterfaceInterfaceView::eInventoryMenu);
        prepair = (FindMenuById)(InterfaceInterfaceView::eRepairMenu);
        pitemmod = (FindMenuById)(InterfaceInterfaceView::eItemModMenu);
        pmap = (FindMenuById)(InterfaceInterfaceView::eMapMenu);
        if (pstat)
        {
            ((MenuPC*)pstat->GetMenu())->SetFadeState(4);
            ((Tile*)((MenuPC*)pstat->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        if (pinv)
        {
            ((MenuPC*)pinv->GetMenu())->SetFadeState(4);
            ((Tile*)((MenuPC*)pinv->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        if (prepair)
        {
            ((MenuPC*)prepair->GetMenu())->SetFadeState(4);
            ((Tile*)((MenuPC*)prepair->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        if (pitemmod)
        {
            ((MenuPC*)pitemmod->GetMenu())->SetFadeState(4);
            ((Tile*)((MenuPC*)pitemmod->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        if (pmap)
        {
            ((MenuPC*)pmap->GetMenu())->SetFadeState(4);
            ((Tile*)((MenuPC*)pmap->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        Interface_CloseContainer();
        if (PlayerCharacter::UpdatePlayerStatus())
            CloseStartMenu(true);
        ((Im7181*)pim)->SetRenderedMenu(0);
    }
}
}  // namespace fnv_00703610

namespace fnv_007024e0 {
class Modifier
{
  public:
    unsigned char GetKey();
};


void* __cdecl _FUN_004b7210();
Menu* __cdecl FindMenuById(int);

// Checks the current modifier and interface menu, resolves a tile for the active menu, and returns whether its menu's thread ID equals 1.
// @fnv 0x007024e0
// src: COMMUNITY 0x007024e0
bool Interface_IsTopMenuFadedIn()
{
    Tile* ptile;
    int topid;

    if (_FUN_004b7210())
    {
        if (reinterpret_cast<Modifier*>(_FUN_004b7210())->GetKey())
        {
            ptile = 0;
            topid = reinterpret_cast<InterfaceManager*>(_FUN_004b7210())->GetTopEnterStackEntry();

            if (topid == 1)
            {
                if (::Interface_IsMenuIDVisible(static_cast<InterfaceInterfaceView::enumMenus>(0x3eb), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x3eb));
                else if (::Interface_IsMenuIDVisible(static_cast<InterfaceInterfaceView::enumMenus>(0x3ea), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x3ea));
                else if (::Interface_IsMenuIDVisible(static_cast<InterfaceInterfaceView::enumMenus>(0x40b), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x40b));
                else if (::Interface_IsMenuIDVisible(static_cast<InterfaceInterfaceView::enumMenus>(0x425), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x425));
                else if (::Interface_IsMenuIDVisible(static_cast<InterfaceInterfaceView::enumMenus>(0x3ff), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x3ff));
            }
            else
            {
                ptile = reinterpret_cast<Tile*>(FindMenuById(topid));
            }

            if (ptile && ptile->GetMenu())
            {
                return reinterpret_cast<BSThread*>(ptile->GetMenu())->GetThreadID() == 1;
            }
        }
    }

    return false;
}
}  // namespace fnv_007024e0

namespace fnv_00704170 {
class Modifier
{
  public:
    unsigned char GetKey();
};


class ProxyMgr
{
  public:
    FOPipboyManager* GetPipboyManager();
};


struct PipboyAccess
{
    void FOPipboyManager_TriggerRandomEffect();
};

struct MenuVirtualAccess
{
    virtual void FUN_00();
    virtual void FUN_01();
    virtual void FUN_02();
    virtual void FUN_03();
    virtual void FUN_04();
    virtual void FUN_05(int, int);
};

Menu* __cdecl FindMenuById(int);
Tile* __cdecl Interface_CreateMapMenu();
void __cdecl StatsMenu_ResetHealingMode();
void __cdecl ResetItemModMenu();
void __cdecl ResetRepairMenu();
void __cdecl MapMenu_SetKnobPosition(bool);

// @fnv 0x00704170
void __cdecl UpdatePipboyMapVisibility(bool abVisibility, bool abAnyVisibleState)
{
    if (InterfaceManager_GetSingleton() != 0 && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey() != 0)
    {
        Tile* pinv;
        Tile* prepair;
        bool bMapVisible;
        Tile* pstat;
        Tile* pmap;
        Tile* pitemmod;

        pstat = reinterpret_cast<Tile*>(FindMenuById(1003));
        pinv = reinterpret_cast<Tile*>(FindMenuById(1002));
        prepair = reinterpret_cast<Tile*>(FindMenuById(1035));
        pitemmod = reinterpret_cast<Tile*>(FindMenuById(1061));
        pmap = reinterpret_cast<Tile*>(FindMenuById(1023));

        bMapVisible =
            ::Interface_IsMenuIDVisible(static_cast<InterfaceInterfaceView::enumMenus>(1023), abAnyVisibleState ? 11 : 0);

        if (abVisibility && !bMapVisible)
        {
            if (pstat != 0)
            {
                reinterpret_cast<Menu*>(pstat->GetMenu())->LoadMenuData();
                StatsMenu_ResetHealingMode();
            }

            if (prepair != 0)
            {
                reinterpret_cast<Menu*>(prepair->GetMenu())->LoadMenuData();
                ResetRepairMenu();
            }

            if (pitemmod != 0)
            {
                reinterpret_cast<Menu*>(pitemmod->GetMenu())->LoadMenuData();
                ResetItemModMenu();
            }

            if (pinv != 0)
                reinterpret_cast<Menu*>(pinv->GetMenu())->LoadMenuData();

            if (pmap == 0)
                pmap = Interface_CreateMapMenu();

            if (pmap != 0)
            {
                reinterpret_cast<Tile*>(InterfaceManager_GetSingleton()->CombatController_GetCombatState())->Set(6001, 1023);
            }

            if (pmap != 0)
                reinterpret_cast<Menu*>(pmap->GetMenu())->UnloadMenuData();

            MapMenu::MenuDepthController();
        }
        else if (!abVisibility && bMapVisible)
        {
            if (pmap != 0)
            {
                reinterpret_cast<Menu*>(pmap->GetMenu())->LoadMenuData();
                reinterpret_cast<MenuVirtualAccess*>(pmap->GetMenu())->FUN_05(0, 0);
            }
        }

        if (abVisibility)
        {
            reinterpret_cast<PipboyAccess*>(reinterpret_cast<ProxyMgr*>(InterfaceManager_GetSingleton())->GetPipboyManager())
                ->FOPipboyManager_TriggerRandomEffect();

            reinterpret_cast<ProxyMgr*>(InterfaceManager_GetSingleton())->GetPipboyManager()->ActivateButton(3);

            if (reinterpret_cast<ProxyMgr*>(InterfaceManager_GetSingleton())->GetPipboyManager()->GetInitialized())
            {
                MapMenu_SetKnobPosition(false);
            }
        }
    }
}
}  // namespace fnv_00704170

namespace fnv_007056f0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

unsigned int __cdecl ret_1012();
Menu* __cdecl FindMenuById(int);
Modifier* __cdecl _FUN_004b7210();

// @fnv 0x007056f0
// src: COMMUNITY 0x007056f0
bool SleepWaitMenu_UpdateSleeping()
{
    SleepWaitMenu* pSleepWaitMenu;
    Tile* ptile;

    ptile = reinterpret_cast<Tile*>(FindMenuById(ret_1012()));
    pSleepWaitMenu = ptile ? static_cast<SleepWaitMenu*>(ptile->GetMenu()) : 0;

    return _FUN_004b7210() && _FUN_004b7210()->GetKey() && pSleepWaitMenu && IsSleepWaitMenuActive(pSleepWaitMenu);
}
}  // namespace fnv_007056f0

class FUN_004b7210_class;

extern FUN_004b7210_class* __cdecl _FUN_004b7210();

class FUN_004b7210_class
{
  public:
    unsigned char GetKey();
    BSSimpleList<BGSPerk*>* GetBGSPerkList();
};

// Returns the perk list from the object obtained via _FUN_004b7210 when its key is nonzero, otherwise returns null.
// @fnv 0x00705950
// src: XBOX_PDB 0x00705950
BSSimpleList<BGSPerk*>* Interface_GetHUDEffects()
{
    if (_FUN_004b7210() && _FUN_004b7210()->GetKey())
    {
        return _FUN_004b7210()->GetBGSPerkList();
    }
    else
    {
        return 0;
    }
}

namespace fnv_007073d0 {

using ::SettingT;

struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};

void ___insecure_strcpy(char*, const char*);
int strcat_s(char*, unsigned int, const char*);
int _BSStringLength(const char*);
int _sprintf(char*, const char*, ...);
void __fastcall _ref_00ec408c(unsigned int);

extern unsigned int __security_cookie;

// Looks up a game or INI setting by name (stripping a leading '&' or '-') and writes its string, int, float or bool value into axStringOut.
// @fnv 0x007073d0
bool ResolveSettingString(const char* apString, char* apValueOut)
{
    Setting* psetting;
    int istartIndex;
    char xstr[260];

    if (!apString || !apString[0])
        return false;

    istartIndex = 0;
    if (apString[istartIndex] == '&')
        ++istartIndex;
    if (apString[istartIndex] == '-')
        ++istartIndex;

    TaskQueueInterface::CopyStringToBuffer(xstr, 0x104, apString + istartIndex);

    if (xstr[_BSStringLength(xstr) - 1] == ';')
        xstr[_BSStringLength(xstr) - 1] = 0;

    psetting = GameSettingCollection::Instance()->SettingCollectionMap_Setting_GetPtr(xstr);
    if (!psetting)
    {
        strcat_s(xstr, 0x104, ":LANGUAGE");
        // GetPtr takes the collection address; the shared empty base would adjust it.
        psetting = reinterpret_cast<SettingCollectionList<Setting>*>(SettingT<INISettingCollection>::GetCollection())->GetPtr(xstr);
    }

    if (psetting)
    {
        if (xstr[0] == 's' || xstr[0] == 'S')
        {
            ___insecure_strcpy(apValueOut, psetting->String());
        }
        else if (xstr[0] == 'i' || xstr[0] == 'I')
        {
            _sprintf(xstr, "%i", *psetting->Int());
            ___insecure_strcpy(apValueOut, xstr);
        }
        else if (xstr[0] == 'f' || xstr[0] == 'F')
        {
            _sprintf(xstr, "%i", *psetting->Float());
            ___insecure_strcpy(apValueOut, xstr);
        }
        else if (xstr[0] == 'b' || xstr[0] == 'B')
        {
            if (*psetting->Bool() == 1)
                ___insecure_strcpy(apValueOut, "&true;");
            else
                ___insecure_strcpy(apValueOut, "&false;");
        }

        return true;
    }

    return false;
}
}  // namespace fnv_007073d0

namespace fnv_00702c80 {
class List_009e03e0
{
  public:
    void RemoveAll();
};

class Modifier
{
  public:
    unsigned char GetKey();
};

class TL
{
  public:
    void* GetNext(void*&);
};



// Folded +0xac getter (0x004fd3c0) on the UI singleton returns its scene-node handle.
NiAVObject* __fastcall GetCursorSceneNode(InterfaceManager*);

void* _FUN_004b7210();
void UpdateVisibility(void*, bool, bool, bool);

// @fnv 0x00702c80
// src: COMMUNITY 0x00702c80
void Interface_IsolateMenuElements(bool abFlag1, bool abFlag2)
{
    if (_FUN_004b7210())
    {
        if (reinterpret_cast<Modifier*>(_FUN_004b7210())->GetKey())
        {
            void* current = _FUN_004b7210();
            if (abFlag1 && !abFlag2)
            {
                reinterpret_cast<List_009e03e0*>(reinterpret_cast<char*>(current) + 0x4c4)->RemoveAll();
            }

            Tile* p2 = reinterpret_cast<InterfaceManager*>(_FUN_004b7210())->CombatController_GetCombatState();
            void* tile = reinterpret_cast<void*>(
                reinterpret_cast<const GO*>(reinterpret_cast<char*>(p2) + 4)->operator unsigned int());

            while (tile)
            {
                void* item =
                    *reinterpret_cast<void**>(reinterpret_cast<TL*>(reinterpret_cast<char*>(p2) + 4)->GetNext(tile));

                UpdateVisibility(item, abFlag1, abFlag2, true);
            }

            if (!abFlag1 && !abFlag2)
            {
                if (GetInterfaceAuxiliaryNode(reinterpret_cast<InterfaceManager*>(_FUN_004b7210())))
                {
                    reinterpret_cast<NiAVObject*>(GetInterfaceAuxiliaryNode(reinterpret_cast<InterfaceManager*>(_FUN_004b7210())))
                        ->SetAppCulled(false);
                }

                if (GetCursorSceneNode(reinterpret_cast<InterfaceManager*>(_FUN_004b7210())))
                {
                    reinterpret_cast<NiAVObject*>(GetCursorSceneNode(reinterpret_cast<InterfaceManager*>(_FUN_004b7210())))
                        ->SetAppCulled(false);
                }
            }
            else
            {
                if (GetInterfaceAuxiliaryNode(reinterpret_cast<InterfaceManager*>(_FUN_004b7210())))
                {
                    reinterpret_cast<NiAVObject*>(GetInterfaceAuxiliaryNode(reinterpret_cast<InterfaceManager*>(_FUN_004b7210())))
                        ->SetAppCulled(true);
                }

                if (GetCursorSceneNode(reinterpret_cast<InterfaceManager*>(_FUN_004b7210())))
                {
                    reinterpret_cast<NiAVObject*>(GetCursorSceneNode(reinterpret_cast<InterfaceManager*>(_FUN_004b7210())))
                        ->SetAppCulled(true);
                }
            }
        }
    }
}
}  // namespace fnv_00702c80

struct StubMenu
{
    void CloseA();
    void CloseB();
};
struct StubTile
{
    StubMenu* GetMenuX();
    void SetX(int trait, int value);
};
struct StubPipboy
{
    void DoA();
    void ActivateBtn(unsigned int button);
    bool IsInit();
};
struct StubIM
{
    bool KeyX();
    StubTile* RootX();
    StubPipboy* PipboyX();
};
StubIM* GetIM();
StubTile* __cdecl MenuByClass(int aiClass);
bool __cdecl MenuVisible(int aiID, unsigned int auFade);
StubTile* __cdecl CreateMenuX();
void __cdecl AfterCloseX();
void __cdecl SetPipboyX(bool ab);

// @fnv 0x007044c0
// src: XBOX_PDB 0x007044c0
void Interface_SetRepairMenuVisible(bool abShow, bool abInstant, bool abActivate)
{
    if (GetIM() && GetIM()->KeyX())
    {
        StubTile* pA = MenuByClass(0x3eb);
        StubTile* pB = MenuByClass(0x3ea);
        StubTile* pCA = MenuByClass(0x40b);
        StubTile* pD = MenuByClass(0x425);
        StubTile* pE2 = MenuByClass(0x3ff);
        bool bVisible = MenuVisible(0x40b, abInstant ? 0xb : 0);
        if (abShow)
        {
            if (!pCA)
                pCA = CreateMenuX();
            if (!bVisible)
            {
                if (pA)
                {
                    pA->GetMenuX()->CloseA();
                    AfterCloseX();
                }
                if (pE2)
                    pE2->GetMenuX()->CloseA();
                if (pD)
                    pD->GetMenuX()->CloseA();
                if (pCA)
                    pCA->GetMenuX()->CloseB();
                if (pB)
                    pB->GetMenuX()->CloseA();
            }
            if (pCA)
                GetIM()->RootX()->SetX(0x1771, 0x40b);
            if (abActivate)
            {
                GetIM()->PipboyX()->DoA();
                GetIM()->PipboyX()->ActivateBtn(2);
            }
            if (GetIM()->PipboyX()->IsInit())
                SetPipboyX(false);
        }
        else if (!abShow && bVisible && pCA)
        {
            pCA->GetMenuX()->CloseA();
        }
    }
}

struct TerminalBase
{
    int unk00;
    ~TerminalBase();
};

struct TerminalMember
{
    ~TerminalMember();
};

struct FUN_007060d0_cls : TerminalBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    TerminalMember m_kMemberDescriptor;
    ~FUN_007060d0_cls();
};

// Destructor for the class; destroys the embedded member and the base, with no other work.
// @fnv 0x007060d0
FUN_007060d0_cls::~FUN_007060d0_cls()
{}

class B706130Node;

class B706130Tile
{
  public:
    B706130Node* GetModel_0056c7f0();
};

class B706130Pick
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    B706130Pick();

    void SetTile(B706130Tile* pkTile);
    void SetTarget_00705fc0(B706130Node* pkNode);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
};

class B706130Manager
{
  public:
    bool GetKey();
    void SetRenderedMenu(B706130Pick* pkPick);
};

B706130Manager* __cdecl B706130GetManager();
B706130Tile* __cdecl CreateComputerMenu(int m_uiSoundID);
void __cdecl B706130UpdateAllTiles(bool bForce);

extern Setting g_kB706130Setting;

// @fnv 0x00706130
// src: COMMUNITY 0x00706130
bool __cdecl Interface_CreateComputerMenu(int m_uiSoundID)
{
    if (B706130GetManager() && B706130GetManager()->GetKey())
    {
        B706130Tile* pkTile = CreateComputerMenu(m_uiSoundID);
        B706130UpdateAllTiles(false);
        if (*g_kB706130Setting.Bool())
        {
            B706130Pick* pkPick = new B706130Pick;
            pkPick->SetTile(pkTile);
            pkPick->SetTarget_00705fc0(pkTile->GetModel_0056c7f0());
            B706130GetManager()->SetRenderedMenu(pkPick);
        }
        return true;
    }
    else
    {
        return false;
    }
}

class FUN_00707870_Temp
{
  public:
    float m_v;
    FUN_00707870_Temp(float f);
    ~FUN_00707870_Temp();
};

struct FUN_00707870_Owner
{
    int TES_CreateDeepCopySameTextures(unsigned int a, FUN_00707870_Temp* b);
};

struct FUN_00707870_Target
{
    int FUN_00a5d2c0(FUN_00707870_Temp* b);
};

extern FUN_00707870_Owner* DAT_011dea10;
bool __cdecl HasMorpherController(unsigned int a);

// Constructs a temporary with value 1.0 and dispatches it to DAT_011dea10 or to the object at a1 depending on FUN_004b5bf0(a1).
// @fnv 0x00707870
// src: COMMUNITY 0x00707870
unsigned int __cdecl Interface_CopyOrDeepCopyNode(unsigned int a1)
{
    unsigned int pad[6];
    FUN_00707870_Temp t(1.0f);
    if (HasMorpherController(a1) != 0)
    {
        return DAT_011dea10->TES_CreateDeepCopySameTextures(a1, &t);
    }
    else
    {
        return reinterpret_cast<FUN_00707870_Target*>(a1)->FUN_00a5d2c0(&t);
    }
}

extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int uExitCode);
extern "C" void __debugbreak();

char ConsumeByteAtE4();
void Interface_MessageMenuYesToAll();
void ProgramFlow(const char* pcMessage);

// Switches on ConsumeByteAtE4: for 1 or 3 warns and exits the process, for 2 calls FUN_00703fd0.
// @fnv 0x0086a530
// src: COMMUNITY 0x0086a530
void MessageMenuCallback()
{
    switch (ConsumeByteAtE4())
    {
        break;
    case 1:
    case 3:
        ProgramFlow("Warning Response was to Exit the Process");
        if (IsDebuggerPresent())
            __debugbreak();
        ExitProcess(0);
    case 2:
        Interface_MessageMenuYesToAll();
        break;
    }
}

struct Player;
struct Helper;
struct ActiveObject
{
    int FUN_0041ca90();
};
struct InterfaceObject
{
    virtual void Unknown000();
    virtual void Unknown001();
    virtual void Unknown002();
    virtual void Unknown003();
    virtual void Unknown004();
    virtual void Unknown005();
    virtual void Unknown006();
    virtual void Unknown007();
    virtual void Unknown008();
    virtual void Unknown009();
    virtual void Release();
    virtual void Unknown011();
    virtual void Unknown012();
    virtual void Unknown013();
    virtual void Unknown014();
    virtual void Unknown015();
    virtual void Unknown016();
    virtual void Unknown017();
    virtual void Unknown018();
    virtual void Unknown019();
    virtual void Unknown020();
    virtual void Unknown021();
    virtual void Unknown022();
    virtual void Unknown023();
    virtual void Unknown024();
    virtual void Unknown025();
    virtual void Unknown026();
    virtual void Unknown027();
    virtual void Unknown028();
    virtual void Unknown029();
    virtual void Unknown030();
    virtual void Unknown031();
    virtual void Unknown032();
    virtual void Unknown033();
    virtual void Unknown034();
    virtual void Unknown035();
    virtual void Unknown036();
    virtual void Unknown037();
    virtual void Unknown038();
    virtual void Unknown039();
    virtual void Unknown040();
    virtual void Unknown041();
    virtual void Unknown042();
    virtual void Unknown043();
    virtual void Unknown044();
    virtual void Unknown045();
    virtual void Unknown046();
    virtual void Unknown047();
    virtual void Unknown048();
    virtual void Unknown049();
    virtual void Unknown050();
    virtual void Unknown051();
    virtual void Unknown052();
    virtual void Unknown053();
    virtual void Unknown054();
    virtual void Unknown055();
    virtual void Unknown056();
    virtual void Unknown057();
    virtual void Unknown058();
    virtual void Unknown059();
    virtual void Unknown060();
    virtual void Unknown061();
    virtual void Unknown062();
    virtual void Unknown063();
    virtual void Unknown064();
    virtual void Unknown065();
    virtual void Unknown066();
    virtual void Unknown067();
    virtual void Unknown068();
    virtual void Unknown069();
    virtual void Unknown070();
    virtual void Unknown071();
    virtual void Unknown072();
    virtual void Unknown073();
    virtual void Unknown074();
    virtual void Unknown075();
    virtual void Unknown076();
    virtual void Unknown077();
    virtual void Unknown078();
    virtual void Unknown079();
    virtual void Unknown080();
    virtual void Unknown081();
    virtual void Unknown082();
    virtual void Unknown083();
    virtual void Unknown084();
    virtual void Unknown085();
    virtual void Unknown086();
    virtual void Unknown087();
    virtual void Unknown088();
    virtual void Unknown089();
    virtual void Unknown090();
    virtual void Unknown091();
    virtual void Unknown092();
    virtual void Unknown093();
    virtual void Unknown094();
    virtual void Unknown095();
    virtual void Unknown096();
    virtual void Unknown097();
    virtual void Unknown098();
    virtual void Unknown099();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual void Unknown125();
    virtual void Unknown126();
    virtual void Unknown127();
    virtual void Unknown128();
    virtual void Unknown129();
    virtual void Unknown130();
    virtual void Unknown131();
    virtual void Unknown132();
    virtual void Unknown133();
    virtual void Unknown134();
    virtual void Unknown135();
    virtual void Unknown136();
    virtual void Unknown137();
    virtual void Unknown138();
    virtual void Unknown139();
    virtual void Unknown140();
    virtual void Unknown141();
    virtual void Unknown142();
    virtual void Unknown143();
    virtual void Unknown144();
    virtual void Unknown145();
    virtual void Unknown146();
    virtual void Unknown147();
    virtual void Unknown148();
    virtual void Unknown149();
    virtual void Unknown150();
    virtual void Unknown151();
    virtual void Unknown152();
    virtual void Unknown153();
    virtual void Unknown154();
    virtual void Unknown155();
    virtual void Unknown156();
    virtual void Unknown157();
    virtual void Unknown158();
    virtual ActiveObject* CurrentObject();
};
struct DialogObject
{
    void BackUpPackage_InitializeBackUpPackage(Player*, int);
};
struct Helper
{
    void SetPackageType(int);
    void FUN_00826b40(int);
    void FUN_00826b90(int);
    void FUN_00984f60(int);
};
extern Helper* __cdecl CreatePackageByType(int);
extern DialogObject* __cdecl FUN_00ec43fb(Helper*, int, void*, void*, int);
extern int DAT_011846a0;
extern int DAT_011a32e0;
extern int DAT_011dea3c;
struct Player
{
    virtual void Unknown000();
    virtual void Unknown001();
    virtual void Unknown002();
    virtual void Unknown003();
    virtual void Unknown004();
    virtual void Unknown005();
    virtual void Unknown006();
    virtual void Unknown007();
    virtual void Unknown008();
    virtual void Unknown009();
    virtual void Unknown010();
    virtual void Unknown011();
    virtual void Unknown012();
    virtual void Unknown013();
    virtual void Unknown014();
    virtual void Unknown015();
    virtual void Unknown016();
    virtual void Unknown017();
    virtual void Unknown018();
    virtual void Unknown019();
    virtual void Unknown020();
    virtual void Unknown021();
    virtual void Unknown022();
    virtual void Unknown023();
    virtual void Unknown024();
    virtual void Unknown025();
    virtual void Unknown026();
    virtual void Unknown027();
    virtual void Unknown028();
    virtual void Unknown029();
    virtual void Unknown030();
    virtual void Unknown031();
    virtual void Unknown032();
    virtual void Unknown033();
    virtual void Unknown034();
    virtual void Unknown035();
    virtual void Unknown036();
    virtual void Unknown037();
    virtual void Unknown038();
    virtual void Unknown039();
    virtual void Unknown040();
    virtual void Unknown041();
    virtual void Unknown042();
    virtual void Unknown043();
    virtual void Unknown044();
    virtual void Unknown045();
    virtual void Unknown046();
    virtual void Unknown047();
    virtual void Unknown048();
    virtual void Unknown049();
    virtual void Unknown050();
    virtual void Unknown051();
    virtual void Unknown052();
    virtual void Unknown053();
    virtual void Unknown054();
    virtual void Unknown055();
    virtual void Unknown056();
    virtual void Unknown057();
    virtual void Unknown058();
    virtual void Unknown059();
    virtual void Unknown060();
    virtual void Unknown061();
    virtual void Unknown062();
    virtual void Unknown063();
    virtual void Unknown064();
    virtual void Unknown065();
    virtual void Unknown066();
    virtual void Unknown067();
    virtual void Unknown068();
    virtual void Unknown069();
    virtual void Unknown070();
    virtual void Unknown071();
    virtual void Unknown072();
    virtual void Unknown073();
    virtual void Unknown074();
    virtual void Unknown075();
    virtual void Unknown076();
    virtual void Unknown077();
    virtual void Unknown078();
    virtual void Unknown079();
    virtual void Unknown080();
    virtual void Unknown081();
    virtual void Unknown082();
    virtual void Unknown083();
    virtual void Unknown084();
    virtual void Unknown085();
    virtual void Unknown086();
    virtual void Unknown087();
    virtual void Unknown088();
    virtual void Unknown089();
    virtual void Unknown090();
    virtual void Unknown091();
    virtual void Unknown092();
    virtual void Unknown093();
    virtual void Unknown094();
    virtual void Unknown095();
    virtual void Unknown096();
    virtual void Unknown097();
    virtual void Unknown098();
    virtual void Unknown099();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual void Unknown125();
    virtual void Unknown126();
    virtual void Unknown127();
    virtual void Unknown128();
    virtual void Unknown129();
    virtual void Unknown130();
    virtual void Unknown131();
    virtual void Unknown132();
    virtual void Unknown133();
    virtual void Unknown134();
    virtual void Unknown135();
    virtual void Unknown136();
    virtual void Unknown137();
    virtual void Unknown138();
    virtual void Unknown139();
    virtual void Unknown140();
    virtual void Unknown141();
    virtual void Unknown142();
    virtual void Unknown143();
    virtual void Unknown144();
    virtual void Unknown145();
    virtual void Unknown146();
    virtual void Unknown147();
    virtual void Unknown148();
    virtual void Unknown149();
    virtual void Unknown150();
    virtual void Unknown151();
    virtual void Unknown152();
    virtual void Unknown153();
    virtual void Unknown154();
    virtual void Unknown155();
    virtual void Unknown156();
    virtual void Unknown157();
    virtual void Unknown158();
    virtual void Unknown159();
    virtual void Unknown160();
    virtual void Unknown161();
    virtual void Unknown162();
    virtual void Unknown163();
    virtual void Unknown164();
    virtual void Unknown165();
    virtual void Unknown166();
    virtual void Unknown167();
    virtual void Unknown168();
    virtual void Unknown169();
    virtual void Unknown170();
    virtual void Unknown171();
    virtual void Unknown172();
    virtual void Unknown173();
    virtual void Unknown174();
    virtual void Unknown175();
    virtual void Unknown176();
    virtual void Unknown177();
    virtual void Unknown178();
    virtual void Unknown179();
    virtual void Unknown180();
    virtual void Unknown181();
    virtual void Unknown182();
    virtual void Unknown183();
    virtual void Unknown184();
    virtual void Unknown185();
    virtual void Unknown186();
    virtual void Unknown187();
    virtual void Unknown188();
    virtual void ActivateInterface(Helper*, int, int);
    InterfaceObject* FUN_008d8520();
    bool Actor_IsRestrained();
    bool Actor_IsUnConscious();
    int FUN_008d6f30(int);
    void OpenDialogMenu();
};
// Returns early if the player is busy or the active object is type 26; otherwise builds a menu context, opens a dialog, and activates the interface.
// @fnv 0x008a7760
void Player::OpenDialogMenu()
{
    ActiveObject* active = FUN_008d8520()->CurrentObject();
    if (Actor_IsRestrained() || Actor_IsUnConscious() || (active && active->FUN_0041ca90() == 26))
    {
        return;
    }
    Helper* menuContext = CreatePackageByType(39);
    menuContext->SetPackageType(39);
    menuContext->FUN_00826b40(0);
    menuContext->FUN_00826b90(1);
    DialogObject* dialog = FUN_00ec43fb(menuContext, 0, &DAT_011846a0, &DAT_011a32e0, 0);
    if (dialog)
    {
        dialog->BackUpPackage_InitializeBackUpPackage(this, FUN_008d6f30(DAT_011dea3c));
    }
    menuContext->FUN_00984f60(48);
    FUN_008d8520()->Release();
    ActivateInterface(menuContext, 1, 1);
}

struct TileListAccess
{
    void* GetHeadPos() const;
    Tile*& GetNext(void*& _n);
};

struct VisibilityManager
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    BSSimpleList<Tile*> visibilityQueue;
};

// @fnv 0x00702990
void UpdateVisibility(Tile* tile, bool show, bool alternate, bool queue)
{
    if (!tile)
        return;
    Tile* _node = InterfaceManager_GetSingleton()->CombatController_GetCombatState();
    InterfaceManager* current = InterfaceManager_GetSingleton();
    bool _unused = false;
    bool _found = false;
    bool _visible = tile->FUN_00a011b0(0xfaa) == 112.0;
    if ((alternate && !_visible) || (!alternate && _visible))
        tile->SetInt(0x1779, 0);
    else
        tile->SetInt(0x1779, 1);

    void* _n = ((TileListAccess*)&tile->m_kChildTileList)->GetHeadPos();
    while (_n)
    {
        Tile* _first = (Tile*)((TileListAccess*)&_node->m_kChildTileList)->GetNext(_n);
        Tile* _child = _first->FUN_00a011b0(0xfaa) == 110.0 ? _first : 0;
        Tile* _second = _first->FUN_00a011b0(0xfaa) == 111.0 ? _first : 0;
        if (_child)
        {
            _unused = true;
            if (show)
            {
                _child->SetInt(0x1779, 1);
                if (queue && !alternate && !_visible)
                    ((VisibilityManager*)current)->visibilityQueue.AddTail(_child);
            }
            else
            {
                _child->SetInt(0x1779, 0);
            }
        }
        if (_second)
        {
            _found = true;
            if (!show)
                _second->SetInt(0x1779, 1);
            else
                _second->SetInt(0x1779, 0);
        }
        if (_child && ((Tile*)_child)->GetModel_0056c7f0())
            ((Tile*)_child)
                ->GetModel_0056c7f0()
                ->SetAppCulled(((Tile*)_child)->FUN_00a011b0(0xfa3) == 0.0 ||
                               ((Tile*)_child)->FUN_00a011b0(0x1779) == 0.0);
        if (_second && ((Tile*)_second)->GetModel_0056c7f0())
            ((Tile*)_second)
                ->GetModel_0056c7f0()
                ->SetAppCulled(show || ((Tile*)_second)->FUN_00a011b0(0xfa3) == 0.0 ||
                               ((Tile*)_second)->FUN_00a011b0(0x1779) == 0.0);
    }
    if (tile->GetModel_0056c7f0())
        tile->GetModel_0056c7f0()->SetAppCulled(tile->FUN_00a011b0(0xfa3) == 0.0 || tile->FUN_00a011b0(0x1779) == 0.0);
}


// TileChildList_interface: local type (was include/TileChildList.h, which had no evidence of one real class); its methods are 0x00559450 NiPointer<PathingSolution>::operator->, 0x0057cbe0 NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::GetNext, 0x00683520 NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::GetPrev
class Tile;
class TileChildNode;
class InterfaceLocalTile;

class TileChildList_interface
{
public:
    TileChildNode* m_pkHead;
    TileChildNode* m_pkTail;
    unsigned int m_uiCount;

    void* GetHeadPos();
    TileChildNode* GetHeadPos() const { return m_pkHead; }
    Tile*& GetNext(void*& rkPos);
    Tile*& GetNext(void*& kPos) const;
    Tile*& GetNext(TileChildNode*& kPos) const;
    InterfaceLocalTile*& GetPrev(void*& pos);
};


// If the menu is open, walks the root tile's children and culls each tile's node when its float at 0xfa3 or 0x1779 is zero.
// @fnv 0x00702dd0
void UpdateMenuTileVisibility()
{
    if (InterfaceManager_GetSingleton() && static_cast<InterfaceManager*>(InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        Tile* pRoot4 = InterfaceManager_GetSingleton()->CombatController_GetCombatState();
        void* pPosVal = reinterpret_cast<TileChildList_interface*>(&pRoot4->m_kChildTileList)->GetHeadPos();
        while (pPosVal)
        {
            Tile* pTile2 =
                static_cast<Tile*>(reinterpret_cast<TileChildList_interface*>(&pRoot4->m_kChildTileList)->GetNext(pPosVal));
            Tile* pChildA2 = static_cast<Tile*>(pTile2->GetChildById(0x6e));
            Tile* pChildB5 = static_cast<Tile*>(pTile2->GetChildById(0x6f));
            pTile2->SetInt(0x1779, 1);
            if (pChildA2)
                pChildA2->SetInt(0x1779, 1);
            if (pChildB5)
                pChildB5->SetInt(0x1779, 1);
            if (pTile2->GetModel_0056c7f0())
                pTile2->GetModel_0056c7f0()->SetAppCulled(pTile2->GetFloat(0xfa3) == 0.0 || pTile2->GetFloat(0x1779) == 0.0);
            if (pChildA2 && pChildA2->GetModel_0056c7f0())
                pChildA2->GetModel_0056c7f0()->SetAppCulled(pChildA2->GetFloat(0xfa3) == 0.0 ||
                                                  pChildA2->GetFloat(0x1779) == 0.0);
            if (pChildB5 && pChildB5->GetModel_0056c7f0())
                pChildB5->GetModel_0056c7f0()->SetAppCulled(pChildB5->GetFloat(0xfa3) == 0.0 ||
                                                  pChildB5->GetFloat(0x1779) == 0.0);
        }
    }
}

// If FUN_004b7210 returns non-null and its FUN_009373f0 check passes, flips the byte at offset 0xdd of its padding field between 0 and 1.
// @fnv 0x00703100
// src: COMMUNITY 0x00703100
void __cdecl ToggleFullHelp()
{
    if (InterfaceManager_GetSingleton() != 0)
    {
        if (((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
        {
            InterfaceManager_GetSingleton()->byte0DD = InterfaceManager_GetSingleton()->byte0DD ? 0 : 1;
        }
    }
}

extern "C" void __fastcall InterfaceManager_PreLoadMenus(InterfaceManager*);
extern "C" void __cdecl UpdatePipboyMapVisibility(int, int);
extern "C" void __cdecl Interface_SetInventoryMenuVisible(int, int, int);
extern "C" void __cdecl ShowStatsMenu(int, int);

// @fnv 0x00703500
void __cdecl HandleMenuKeyInput(void)
{
    if (InterfaceManager_GetSingleton() != 0)
    {
        if (((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
        {
            InterfaceManager* iMenu = InterfaceManager_GetSingleton();
            int pManager = (int)iMenu->CombatController_GetCombatState()->GetFloat(0x1771);
            if (pManager == 0)
            {
                InterfaceManager_PreLoadMenus(InterfaceManager_GetSingleton());
                pManager = 0x3eb;
            }
            switch (pManager)
            {
            case 0x3ff:
                UpdatePipboyMapVisibility(1, 0);
                break;
            case 0x3ea:
            case 0x40b:
            case 0x425:
                Interface_SetInventoryMenuVisible(1, 0, 1);
                break;
            case 0x3eb:
                ShowStatsMenu(1, 0);
                break;
            }
        }
    }
}

bool __cdecl QueueMessage(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a10, va_list* args, int enabled,
                          int left, int right, float zero, float x, float y);

// @fnv 0x00703f10
// src: COMMUNITY 0x00703f10
bool __cdecl Interface_CreateMessageMenuSound(int a1, int a2, int a3, int a4, int a5, int a6, int a7, float x, float y, int a10, ...)
{
    if (InterfaceManager_GetSingleton() && ((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        bool result5;
        va_list args;
        va_start(args, a10);
        result5 = QueueMessage(a1, a2, a3, a4, a5, a6, a7, a10, &args, 1, -1, -1, 0.0f, x, y);
        va_end(args);
        return result5;
    }
    return false;
}

#include <stdarg.h>
typedef MSG WinMessage;

struct InterfaceControl
{
    void FUN_007010e0(bool, bool);
};
extern InterfaceInterfaceView* DAT_011d8804;
bool __cdecl QueueMessage(const char*, int, int, int, void (*)(), int, int, int, va_list*, bool, int, int, float, float,
                          float);
void __cdecl ourMemset(void*, int, unsigned int);
class InputManager
{
  public:
    void Controls_UpdateValues();
};

extern OSGlobals* g_osGlobals;
void Interface_PreIdleStuff();
void Interface_Idle();
void Interface_PostIdleStuff();
void RenderOrFallback(int, int);
void Object_ProcessState_00702960();
// @fnv 0x00704010
// src: COMMUNITY 0x00704010
char __cdecl Interface_CreateModalMessageMenu(const char* text, int aiArg1, int aiArg2, int aiArg3, ...)
{
    DAT_0119f349 = -1;
    bool success = false;
    ((InterfaceControl*)DAT_011d8804)->FUN_007010e0(true, true);
    if (InterfaceManager_GetSingleton() && ((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        va_list args;
        va_start(args, aiArg3);
        success =
            QueueMessage(text, 0, 0, 0, Interface_SetDAT0119f349, aiArg1, aiArg2, aiArg3, &args, true, -1, -1, 0.0f, 0.0f, 0.0f);
        va_end(args);
    }
    if (success)
    {
        while (DAT_0119f349 == -1)
        {
            WinMessage message;
            ourMemset(&message, 0, sizeof(message));
            while (PeekMessageA(&message, 0, 0, 0, 1))
            {
                TranslateMessage(&message);
                DispatchMessageA(&message);
            }
            g_osGlobals->Main_GetControls()->Controls_UpdateValues();
            Interface_PreIdleStuff();
            Interface_Idle();
            Interface_PostIdleStuff();
            RenderOrFallback(0, 0);
            Object_ProcessState_00702960();
        }
        return DAT_0119f349;
    }
    return 0;
}

struct MenuProxy
{
    void FUN_00a1d910();
    void InitializeStatsMenu();
    void FUN_00a1db20();
};
struct TileProxy
{
    MenuProxy* Tile_GetMenu();
};
TileProxy* Tile_GetMenuByClass(int);
TileProxy* Interface_CreateStatsMenu();
void ResetRepairMenu();
void ResetItemModMenu();
void PlayPipboyPageSound(bool);
struct PipProxy
{
    void FOPipboyManager_TriggerRandomEffect();
    void FUN_007fa010(unsigned int);
    bool IsUnk28Set();
};
struct InterfaceProxy
{
    PipProxy* FUN_00704370();
};
// Shows or hides the stats menu and its related tiles, updating the Pip-Boy interface when shown.
// @fnv 0x00704c10
void ShowStatsMenu(bool show, bool fades)
{
    if (InterfaceManager_GetSingleton() && ((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        TileProxy* stats = Tile_GetMenuByClass(1003);
        TileProxy* inv = Tile_GetMenuByClass(1002);
        TileProxy* repair2 = Tile_GetMenuByClass(1035);
        TileProxy* barterX = Tile_GetMenuByClass(1061);
        TileProxy* map3 = Tile_GetMenuByClass(1023);
        bool visible2 = Interface_IsMenuIDVisible(InterfaceInterfaceView::eStatsMenu, fades ? 11 : 0);
        if (show && !visible2)
        {
            if (inv)
                inv->Tile_GetMenu()->FUN_00a1d910();
            if (repair2)
            {
                repair2->Tile_GetMenu()->FUN_00a1d910();
                ResetRepairMenu();
            }
            if (barterX)
            {
                barterX->Tile_GetMenu()->FUN_00a1d910();
                ResetItemModMenu();
            }
            if (map3)
                map3->Tile_GetMenu()->FUN_00a1d910();
            if (!stats)
                stats = Interface_CreateStatsMenu();
            if (stats)
            {
                InterfaceManager_GetSingleton()->CombatController_GetCombatState()->SetInt(6001, 1003);
                stats->Tile_GetMenu()->InitializeStatsMenu();
                stats->Tile_GetMenu()->FUN_00a1db20();
            }
        }
        else if (!show && visible2)
        {
            if (stats)
                stats->Tile_GetMenu()->FUN_00a1d910();
        }
        if (show)
        {
            ((InterfaceProxy*)InterfaceManager_GetSingleton())->FUN_00704370()->FOPipboyManager_TriggerRandomEffect();
            ((InterfaceProxy*)InterfaceManager_GetSingleton())->FUN_00704370()->FUN_007fa010(1);
            if (((InterfaceProxy*)InterfaceManager_GetSingleton())->FUN_00704370()->IsUnk28Set())
                PlayPipboyPageSound(false);
        }
    }
}


struct DecompArg12
{
    int m_00;
    int m_04;
    int m_08;
    DecompArg12(const DecompArg12& src);
    ~DecompArg12();
};

struct DecompVec3
{
    int m_00;
    int m_04;
    int m_08;
};

struct DecompTarget
{
    void HUDMainMenu_ShowSubtitle(int a1, DecompArg12 a2, DecompVec3 a3, int a4, bool a5);
};

extern unsigned int DAT_011d96c0;

// If the interface manager and its shell are available and DAT_011d96c0 is set, forwards the arguments to FUN_00774fd0 on DAT_011d96c0; always returns false.
// @fnv 0x00705210
// src: XBOX_PDB 0x00705210
bool __cdecl Interface_ShowSubtitle(int aiArg1, DecompArg12 aArg12, DecompVec3 aVec3, int aiArg4, bool a5)
{
    AutoMemContext guard(13, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Interface.cpp", 0x8ec);
    if (InterfaceManager_GetSingleton() && ((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount() && DAT_011d96c0)
    {
        ((DecompTarget*)DAT_011d96c0)->HUDMainMenu_ShowSubtitle(aiArg1, aArg12, aVec3, aiArg4, a5);
    }
    return false;
}

struct FUN_0047ee30_shell : public InterfaceManager
{
    char GetAssistance();
};

// If FUN_004b7210 returns a non-null object whose FUN_009373f0 is true, returns its GetAssistance result; otherwise returns -1.
// @fnv 0x00705c70
extern "C" char __cdecl GetInterfaceManagerResult()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<InterfaceManager*>(InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        return reinterpret_cast<FUN_0047ee30_shell*>(InterfaceManager_GetSingleton())->GetAssistance();
    }
    return -1;
}

struct FloatValue
{
    float GetFloat();
};
// InterfaceManager tutorial-seen flags: GetData 0x007187a0 = TutorialState::PackFlags, GetLength 0x00706810 (interfacemanager.cpp)
struct TutorialState
{
    int GetLength();
    void GetData(char*);
};
struct Buffer
{
    void SaveData(void*, unsigned, int);
};
char GetStatsMenuPage();
unsigned char InventoryMenu_GetCurrentInventoryPage();
float GetMapMenuFloatSetting();
float GetTileFloatOrDefault();
void ourMemset(void*, int, unsigned);
// @fnv 0x007066d0
// src: COMMUNITY 0x007066d0
void Interface_SaveGame(Buffer* buffer)
{
    char y[100];
    float text;
    int length = (int)InterfaceManager_GetSingleton()->CombatController_GetCombatState()->GetFloat(0x1771);
    char third = GetStatsMenuPage();
    unsigned char x = InventoryMenu_GetCurrentInventoryPage();
    char value = MapMenu_GetCurrentMapPage();
    buffer->SaveData(&length, 4, 0);
    buffer->SaveData(&third, 1, 0);
    buffer->SaveData(&x, 1, 0);
    buffer->SaveData(&value, 1, 0);
    float first = GetMapMenuFloatSetting();
    text = GetTileFloatOrDefault();
    buffer->SaveData(&first, 4, 0);
    buffer->SaveData(&text, 4, 0);
    ourMemset(y, 0, 100);
    int second = InterfaceManager_GetSingleton()->kTutorialManager.GetSaveLoadSize();
    reinterpret_cast<TutorialState*>(&InterfaceManager_GetSingleton()->kTutorialManager)->GetData(y);
    buffer->SaveData(&second, 4, 0);
    buffer->SaveData(y, second, 0);
}

struct FUN_00703960_Class
{
    void __thiscall SetByteAtOffsetEC(char param);
};

// @fnv 0x00706db0
// src: COMMUNITY 0x00706db0
void Interface_SetIsEmergencyTextureRelease(unsigned char ucValue)
{
    ((FUN_00703960_Class*)InterfaceManager_GetSingleton())->SetByteAtOffsetEC((char)ucValue);
}


extern Setting* DAT_0119b354[];
extern Setting* DAT_0119b35c[];
extern Setting* DAT_0119b364[];

struct Player_StandIn : public PlayerCharacter
{
    const char* GetFullName();
    const char* Actor_GetRaceFullName();
    int GetSex();
};

int __cdecl FindSettingIndex(const char* apName);
void __cdecl GetControlLabel(int a1, char* a2, bool a3);
bool __cdecl ResolveSettingString(const char* a1, char* a2);
TESForm* __cdecl FUN_00483a00(const char* apName);

int __cdecl sprintf_s(char* apBuffer, unsigned int auiBufferSize, const char* apFormat, ...);
int __cdecl CopyInterfaceString(char* apDest, unsigned int auiDestSize, const char* apSrc);
int __cdecl CompareInterfaceStringsIgnoreCase(const char* apStr1, const char* apStr2);

// @fnv 0x007070c0
// src: XBOX_PDB 0x007070c0
bool __cdecl Interface_FindTextReplacementString(const char* apName, char* apBuffer, unsigned int auiBufferSize, bool abArg4)
{
    bool bFound = false;
    if (apName && *apName && apBuffer && auiBufferSize)
    {
        int iSettingIndex = FindSettingIndex(apName);
        if (iSettingIndex < 28)
        {
            GetControlLabel(iSettingIndex, apBuffer, abArg4);
            bFound = true;
        }
        if (!bFound)
        {
            TESForm* pForm = FUN_00483a00(apName);
            if (pForm && ((TESForm*)pForm)->FUN_00401170() == 6)
            {
                TESGlobal* pGlobalForm = (TESGlobal*)pForm;
                if (GetGlobalValueType(pGlobalForm) == 'f')
                {
                    sprintf_s(apBuffer, auiBufferSize, "%.2f", pGlobalForm->GetValue());
                }
                else
                {
                    sprintf_s(apBuffer, auiBufferSize, "%i", (int)pGlobalForm->GetValue());
                }
                bFound = true;
            }
        }
        if (!bFound && CompareInterfaceStringsIgnoreCase(apName, "PCName") == 0)
        {
            CopyInterfaceString(apBuffer, auiBufferSize, ((Player_StandIn*)g_thePlayer)->GetFullName());
            bFound = true;
        }
        if (!bFound && CompareInterfaceStringsIgnoreCase(apName, "PCRace") == 0)
        {
            CopyInterfaceString(apBuffer, auiBufferSize, ((Player_StandIn*)g_thePlayer)->Actor_GetRaceFullName());
            bFound = true;
        }
        if (!bFound && CompareInterfaceStringsIgnoreCase(apName, "PCSex") == 0)
        {
            CopyInterfaceString(apBuffer, auiBufferSize, DAT_0119b354[((Player_StandIn*)g_thePlayer)->GetSex()]->String());
            bFound = true;
        }
        if (!bFound && CompareInterfaceStringsIgnoreCase(apName, "PCSexPronoun") == 0)
        {
            CopyInterfaceString(apBuffer, auiBufferSize, DAT_0119b364[((Player_StandIn*)g_thePlayer)->GetSex()]->String());
            bFound = true;
        }
        if (!bFound && CompareInterfaceStringsIgnoreCase(apName, "PCSexPossessive") == 0)
        {
            CopyInterfaceString(apBuffer, auiBufferSize, DAT_0119b35c[((Player_StandIn*)g_thePlayer)->GetSex()]->String());
            bFound = true;
        }
        if (!bFound)
        {
            bFound = ResolveSettingString(apName, apBuffer);
        }
    }
    return bFound;
}

class Model
{
  public:
    unsigned int unk00, unk04, unk08, unk0C;
    Model(const char*, BSStream*, bool, bool);
    NiNode* GetObject3D();
};
struct Loader_S
{
    NiNode* ModelLoader_LoadFile(const char*, int, bool, bool, bool, bool);
};
extern bool DAT_011d8908;
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NONE
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
// Clears the flag, then loads a model from path via the model loader or a BSStream and returns its NiNode, or null on failure.
// @fnv 0x00707660
// src: COMMUNITY 0x00707660
NiNode* Interface_LoadModelFile(const char* path, bool* flag)
{
    *flag = false;
    if (g_modelLoader && !DAT_011d8908)
    {
        *flag = true;
        return ((Loader_S*)g_modelLoader)->ModelLoader_LoadFile(path, 0, true, false, false, false);
    }
    else if (FileFinder::Exist(path, 0, 0, -1))
    {
        BSStream stream;
        if (stream.BSStream_Load(path, false))
        {
            S_004431f0* previous = DAT_011d890c;
            S_004431f0* old = previous;
            old ? old->FUN_004431f0(1) : 0;
            DAT_011d890c = (S_004431f0*)new Model(path, &stream, true, false);
            return ((Model*)DAT_011d890c)->GetObject3D();
        }
    }
    return 0;
}

// The packet TESFullName declaration lacks the out-of-line name getter.
const char* __fastcall GetNPCFullName(const TESFullName*);


extern PlayerCharacter* g_pkB7AB690Player;
extern Setting g_kB7AB690NamePrompt;

void __cdecl Object_GetGlobalValue_007ab7c0();
void __cdecl B7AB690ShowTextEntry(const char* pcPrompt, const char* pcDefault, void(__cdecl* pfnCallback)(const char*));
void __cdecl B7AB690OnNameEntered(const char* pcName);


class FUN_007ab690_cls : public Menu
{
  public:
    FUN_007ab690_cls();
    virtual ~FUN_007ab690_cls();

    void Finish(const char* pcName);

    TESNPC* m_pkNPC;
};

// Stores the player's TESNPC reference, then shows the name text entry prompt with the NPC's current full name, or calls Finish(0) if there is no NPC.
// @fnv 0x007ab690
FUN_007ab690_cls::FUN_007ab690_cls()
{
    m_pkNPC = g_pkB7AB690Player ? dynamic_cast<TESNPC*>(g_pkB7AB690Player->GetObjectReference()) : 0;
    if (m_pkNPC)
    {
        Object_GetGlobalValue_007ab7c0();
        // Address the inherited name component without a nullable base-pointer conversion.
        B7AB690ShowTextEntry(
            g_kB7AB690NamePrompt.GetString(),
            GetNPCFullName(reinterpret_cast<const TESFullName*>(
                reinterpret_cast<const char*>(&m_pkNPC->m_kName) - offsetof(TESFullName, m_kName))),
            B7AB690OnNameEntered);
    }
    else
    {
        Finish(0);
    }
}

namespace fnv_008d66b0 {
#include <string.h>
#include <stdio.h>

struct WobbleNode : NiNode
{
    NiFixedString& GetName();
    void SetName(const NiFixedString&);
};
struct WobbleLoader : ModelLoader
{
    WobbleNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
struct FileFinder
{
    static int Exist(const char*, char*, unsigned int, unsigned int);
};
extern WobbleNode* DAT_011e0110[];
extern char* DAT_011e00e0[];
extern bool DAT_01185520;
extern const char* DAT_011977a4[];
int FUN_00406d30(char*, unsigned int, const char*);
// Loads up to 12 weapon wobble NIF models from Meshes\Characters\WeaponWobbles, storing each node and a copy of its name, then sets DAT_01185520 to true.
// @fnv 0x008d66b0
void LoadWeaponWobbleModels()
{
    memset(DAT_011e0110, 0, 12);
    memset(DAT_011e00e0, 0, 12);
    DAT_01185520 = false;
    char path[260];
    for (int i = 0; i < 12; i++)
    {
        if (i == 0)
            sprintf_s(path, 260, "%s\\Characters\\WeaponWobbles\\ScopeWobble.nif", "Meshes");
        else
            sprintf_s(path, 260, "%s\\Characters\\WeaponWobbles\\%s.nif", "Meshes", DAT_011977a4[i]);
        if (FileFinder::Exist(path, 0, 6, 1))
        {
            DAT_011e0110[i] = static_cast<WobbleLoader*>(g_modelLoader)->LoadFile(path, 0, true, false, false, false);
            unsigned int length = BSStringLength(DAT_011e0110[i]->GetName()) + 1;
            DAT_011e00e0[i] = new char[length];
            FUN_00406d30(DAT_011e00e0[i], length, DAT_011e0110[i]->GetName());
            DAT_011e0110[i]->SetName(NiFixedString(static_cast<const char*>(path)));
        }
    }
    DAT_01185520 = true;
}
}  // namespace fnv_008d66b0


struct TESObjectREFRMine : TESObjectREFR
{
    TESForm* GetOwner();
    bool CanBeUsed(Actor* apActor, bool abUnk);
};

int ContainerMenu_Create(TESObjectREFR* apRef, int aType);

// If the interface manager key is held, adjusts aType to 2 for owned non-actor refs that cannot be used, then calls FUN_0075b310; otherwise returns 0.
// @fnv 0x00704ed0
// src: XBOX_PDB 0x00704ed0
int Interface_CreateContainerMenu(TESObjectREFR* apRef, int aType)
{
    if (InterfaceManager_GetSingleton() && ((InterfaceManager*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        if (aType == 1)
        {
            if (!((TESObjectREFRMine*)apRef)->IsActor() && ((TESObjectREFRMine*)apRef)->GetOwner() &&
                !((TESObjectREFRMine*)apRef)->CanBeUsed(g_thePlayer, true))
            {
                aType = 2;
            }
        }
        return ContainerMenu_Create(apRef, aType);
    }
    return 0;
}

// @fnv 0x0040fbe0
// src: XBOX_PDB 0x0040fbe0
void __cdecl ProgramFlow()
{}

struct MgrQ
{
    bool TESTextureList_GetTextureCount();
    bool InterfaceManager_IsDebugTextVisible();
};
// Returns the result of MgrQ::FUN_00644640 when FUN_004b7210 is non-null and MgrQ::FUN_009373f0 is true, otherwise false.
// @fnv 0x00702fc0
// src: XBOX_PDB 0x00702fc0
bool Interface_IsDebugTextVisible()
{
    if (InterfaceManager_GetSingleton() && ((MgrQ*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
        return ((MgrQ*)InterfaceManager_GetSingleton())->InterfaceManager_IsDebugTextVisible();
    return false;
}

namespace sleep704 {
struct M70Tile
{
    void FUN_00a1d910();
    void FUN_00a1db20();
};
struct M70Menu
{
    M70Tile* Tile_GetMenu();
};
struct M70Trait
{
    void FUN_00700320(int id, int value);
};
struct M70Hud
{
    void FOPipboyManager_TriggerRandomEffect();
    void FUN_007fa010(int a);
    bool IsUnk28Set();
};
struct M70Player
{
    bool TESTextureList_GetTextureCount();
    M70Trait* CombatController_GetCombatState();
    M70Hud* FUN_00704370();
};
M70Player* InterfaceManager_GetSingleton();
M70Menu* Tile_GetMenuByClass(int id);
bool Interface_IsMenuIDVisible(int id, int a);
M70Menu* CreateInventoryMenuIfModifierKey();
void StatsMenu_ResetHealingMode();
void ResetRepairMenu();
void ResetItemModMenu();
void InventoryMenu_UpdateInventoryMenu();
void InventoryMenu_SetKnobPosition(int a);
void UpdateCurrentValue();

// Shows or hides the inventory menu, closing related menus and resetting HUD state as needed.
// @fnv 0x007048f0
// src: XBOX_PDB 0x007048f0
void Interface_SetInventoryMenuVisible(bool show, bool fade, bool reset)
{
    M70Menu* pMenu3eb;
    M70Menu* pMenu3ea;
    M70Menu* pMenu40bB;
    M70Menu* aPMenu425;
    M70Menu* pMenu3ff8;
    bool bOpen;

    if (InterfaceManager_GetSingleton() && InterfaceManager_GetSingleton()->TESTextureList_GetTextureCount())
    {
        pMenu3eb = Tile_GetMenuByClass(0x3eb);
        pMenu3ea = Tile_GetMenuByClass(0x3ea);
        pMenu40bB = Tile_GetMenuByClass(0x40b);
        aPMenu425 = Tile_GetMenuByClass(0x425);
        pMenu3ff8 = Tile_GetMenuByClass(0x3ff);
        bOpen = Interface_IsMenuIDVisible(0x3ea, fade ? 0xb : 0);
        if (show)
        {
            if (!pMenu3ea)
            {
                pMenu3ea = CreateInventoryMenuIfModifierKey();
            }
            if (!bOpen)
            {
                if (pMenu3eb)
                {
                    pMenu3eb->Tile_GetMenu()->FUN_00a1d910();
                    StatsMenu_ResetHealingMode();
                }
                if (pMenu3ff8)
                {
                    pMenu3ff8->Tile_GetMenu()->FUN_00a1d910();
                }
                if (pMenu40bB)
                {
                    pMenu40bB->Tile_GetMenu()->FUN_00a1d910();
                    ResetRepairMenu();
                }
                if (aPMenu425)
                {
                    aPMenu425->Tile_GetMenu()->FUN_00a1d910();
                    ResetItemModMenu();
                }
                if (pMenu3ea)
                {
                    pMenu3ea->Tile_GetMenu()->FUN_00a1db20();
                }
            }
            if (pMenu3ea)
            {
                InventoryMenu_UpdateInventoryMenu();
                InterfaceManager_GetSingleton()->CombatController_GetCombatState()->FUN_00700320(0x1771, 0x3ea);
            }
            if (reset)
            {
                InterfaceManager_GetSingleton()->FUN_00704370()->FOPipboyManager_TriggerRandomEffect();
                InterfaceManager_GetSingleton()->FUN_00704370()->FUN_007fa010(2);
            }
            if (InterfaceManager_GetSingleton()->FUN_00704370()->IsUnk28Set())
            {
                InventoryMenu_SetKnobPosition(0);
            }
        }
        else if (!show && bOpen && pMenu3ea)
        {
            pMenu3ea->Tile_GetMenu()->FUN_00a1d910();
            UpdateCurrentValue();
        }
    }
}
}

struct BaseMenu
{
    BaseMenu();
    ~BaseMenu();
    virtual void vfunc();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
};

struct RenderedPoint
{
    RenderedPoint();
    float x;
    float y;
    float z;
};

struct NodeHandle
{
    NodeHandle(int);
};

struct FUN_00705fe0 : BaseMenu
{
    RenderedPoint pt;
    NodeHandle node;

    FUN_00705fe0();
};

// Constructs a FUN_00705fe0 object, initializing its node member to 0.
// @fnv 0x00705fe0
FUN_00705fe0::FUN_00705fe0() : node(0)
{}


// Destructor for Tile; performs no additional cleanup beyond the default body.
// @fnv 0x00709930
Tile::~Tile()
{}

// Candidate for FUN_0079ffb0 (claim clm_f5183b6336444303ae13, 0x0079ffb0, 5190 bytes)
// World-map tile mesh build / screenshot dump; param_1 != 0 selects the dump path.
// Builds on the packet's best prior attempt; corrected constructors, calls and local layout.
// Packet flags: /MT /Od /Oy- /GS /EHsc /Gy /GF. Entry ABI: __cdecl, caller pops.


namespace points {
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
    FUN_006815c0(float, float, float);
    void ComputeValue_0063c8a0(const FUN_006815c0*);
};
}
typedef points::FUN_006815c0 NiPt3;
namespace uvs {
struct FUN_006815c0
{
    float u, v;
    FUN_006815c0();
    FUN_006815c0(float, float);
};
}
typedef uvs::FUN_006815c0 NiPt2;
struct FUN_004a7800
{
    float r, g, b, a;
    FUN_004a7800();
    FUN_004a7800(float, float, float, float);
};
typedef FUN_004a7800 NiCol;

// object reached from DAT_011dea3c through virtual slot 0x1f4 (index 125, __thiscall)
struct C125
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual void* v125();
};

// object with virtual name accessor at slot 0x130 (index 76, __thiscall)
struct C76a
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual unsigned int v076();
};
struct C76b
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual unsigned int v076(int, int);
};
struct C76c
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual unsigned int v076(int);
};

// object with virtual slot 0xdc (index 55, __thiscall, callee pops 8)
struct C55
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055(void*, int);
};

// object with virtual slot 0x9c (index 39, __thiscall, callee pops 4)
struct C39
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual unsigned int v039(int);
};

// chain objects reached through DAT_011dea3c members
struct Local12;
struct Mesh34;
struct V3Maker;
struct ChainObj
{
    void NiAVObject_Update(V3Maker*);
    ChainObj* FUN_00586170();
    ChainObj* NiObjectNET_GetControllers();
    bool GetAppCulled_00456610();
    void FUN_00450f90(bool);
    void* FUN_005875a0(int, int);
    void FUN_00555bc0();
    void NiXenonRenderer_LockRenderer();
    void NiXenonRenderer_UnlockRenderer();
    void AdjustCoordForNorthRotation(NiPt3*, NiPt3*, int);
    void TESObjectCELL_GetIntSeenSection(int, int, int);
    void TESObjectCELL_GetExteriorLocalMapTexture(Local12*);
    void GetInteriorLocalMapTexture(int, int, Local12*);
    void CollectCellReferences(unsigned int*);
    unsigned int FUN_0059bb30();
};
struct Mesh34
{
    void NiAVObject_AttachProperty(void*);
    void UpdateProperties();
    void NiAVObject_SetTranslate_004bc1f0(float, float, float);
};
struct ObjD_11dea3c
{
    bool TESObjectREFR_GetInterior();
    void* TESObjectREFR_GetWorldSpace();
    void* FUN_008d6f30();
};

// path-name providers on the object at DAT_011dea10
struct PathSrc
{
    void* FUN_005f36f0();
    void* FUN_004fd3e0();
};

// object at [[DAT_011da368]+0x30]
struct Tile30
{
    unsigned int GetModel_0056c7f0();
    void Tile_ClearNeedsUpdate(int);
    void Tile_SetChangeFlag(int);
    void FUN_00700320(int, int);
    void Tile_Set(int, float, int);
};

// small local-object stand-ins (methods invoked with ecx = local)
struct V3Maker
{
    float x, y, z;
    NiPt3& SetComponents(float x, float y, float z);
    NiPt2& FUN_00452dc0(float u, float v);
    NiCol& FUN_00414430(float a, float b, float c, float d);
    void FUN_0043d410(float a, int b, int c);
    void ComputeValue_0063c8a0(NiPt3* p);
};
struct ColorMaker
{
    float r, g, b, a;
    NiCol& FUN_00414430(float, float, float, float);
};
struct UvMaker
{
    float u, v;
    NiPt2& FUN_00452dc0(float, float);
};
struct Obj16
{
    struct FloatColor
    {
        float r, g, b, a;
    } c;
    Obj16(float, float, float, float);
};
struct Local12
{
    unsigned int value;
    Local12(int);
    ~Local12();
    unsigned int Modelloader_GetReferencedThis();
    void FUN_0066b0d0(int);
};

// mesh/material stand-ins
struct ObjD4
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    ObjD4(unsigned short, void*, void*, void*, void*, int, int, unsigned int, void*, int, int, int, int);
};
struct ObjB0
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    ObjB0(bool);
    void SetTileTexture(unsigned int);
    void EffectSetting_SetAreaSound(int);
    void SetNavMeshInfo(Obj16*);
    void SetFlag(int);
};
struct Obj1C
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Obj1C();
    void NiAlphaProperty_SetSrcBlendMode(int);
    void NiAlphaProperty_SetDestBlendMode(int);
    void NiAlphaProperty_SetAlphaBlending(int);
};

// map-menu state global, fields at their offsets

int __cdecl TESObjectCELL_GetSeenValue(V3Maker*);
// free helpers; conventions read from add esp evidence
extern "C" void* __cdecl FormHeap_Allocate(unsigned int);
extern "C" void __stdcall FUN_00401050(void*, unsigned int, unsigned int, void*);
extern "C" void* __cdecl _NiMalloc_00aa1070(unsigned int);
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern "C" void __cdecl FUN_006815c0();
extern "C" void __cdecl FUN_004a7800();
extern "C" int __cdecl FloatToInt(float);
extern "C" void __cdecl BSsprintf(char*, unsigned int, const char*, ...);
extern "C" void __stdcall NiRenderedTexture_SaveToFile(char*, int, unsigned int);
extern "C" bool __cdecl MapMenu_ShouldRenderLocalMap();
extern "C" void* __cdecl Main_LandLODNode();
extern "C" void* __cdecl NiObject_DynamicCast(unsigned int, unsigned int);
extern "C" void __cdecl FUN_00b57e30(void*, int, int);
extern "C" float __cdecl ScreenWidth();
extern "C" float __cdecl ScreenHeight();
extern "C" void* __cdecl FUN_00ec62c0();
extern "C" float __cdecl SeenData_GetSeenPosSize();
struct ColorSource
{
    void ReadColor(int, Obj16*);
};
extern "C" ColorSource* __cdecl ColorSingleton();
extern "C" void __fastcall FUN_00719060(void*); /* ecx = FUN_00718b60 result */
extern "C" void __fastcall NiAVObject_Update(void*); /* ecx = FUN_0056c7f0 result */
extern Setting DAT_011c63cc; /* object at 0x11c63cc */

// globals read/written here
struct Position
{
    float x, y, z;
};
extern Position DAT_011f426c;
struct RenderColor
{
    unsigned int r, g, b, a;
};
extern RenderColor DAT_011ff3a8;
extern RenderColor DAT_011a9bd0;
extern unsigned char DAT_011ff103;
extern double DBL_01020758;
extern double DBL_01011590;
extern double DBL_0101db80;
extern double DBL_0101e568;
extern float FLT_0101e570;
extern char DAT_01075520[];
extern char DAT_01075508[];
extern char DAT_010754f0[];
extern char DAT_010754d4[];
extern char DAT_010754ac[];
extern char DAT_01075490[];
extern char DAT_01075468[];
extern unsigned int DAT_011f4418;

// Builds and attaches a map mesh; when param_1 is set, it builds a path and passes it with collected references to another function.
// @fnv 0x0079ffb0
// src: XBOX_PDB 0x0079ffb0
void __cdecl MapMenu_RenderLocalMapGrid(char param_1)
{
    RenderColor savedColor1;
    int size27;
    int totalSize40;
    bool bWide9;
    Position base9c33;
    short* pIdx11;
    V3Maker mk8c26;
    int step17;
    int m23;
    int m10;
    bool cFlag7151;
    void* pvT32;
    void* pvC52;
    Position pos15;
    void* pSub10;
    ChainObj* pMenu25;
    bool cMenuOk4;
    ObjB0* pFx44;
    Obj1C* pFx221;
    int gridSize13;
    int cellY10;
    void* pvV17;
    int totalCells21;
    int idx19;
    Mesh34* pMesh14;
    unsigned char svByte10316;
    float fStep27;
    int n25;
    int j17;
    int i17;
    int n2;
    int cellX17;

    if (DAT_011da368 == 0 ||
        reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])->GetModel_0056c7f0() == 0 ||
        !MapMenu_ShouldRenderLocalMap())
        return;

    pos15 = *static_cast<Position*>(reinterpret_cast<C125*>(DAT_011dea3c)->v125());
    pos15.z += DBL_01020758;

    /* world size: 0x800 when flagged, else 0x400 */
    bWide9 = reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetInterior() != 0;
    size27 = bWide9 ? 0x800 : 0x400;

    n2 = 0x10;
    n25 = n2 * n2;
    step17 = size27 / n2;
    m10 = 0x11;
    m23 = m10 * m10;

    gridSize13 = *DAT_011c63cc.Setting_Int();
    totalCells21 = gridSize13 * gridSize13;
    totalSize40 = size27 * gridSize13;
    fStep27 = SeenData_GetSeenPosSize();

    /* save render state, install defaults */
    savedColor1 = DAT_011ff3a8;
    DAT_011ff3a8 = DAT_011a9bd0;
    svByte10316 = DAT_011ff103;
    DAT_011ff103 = 1;

    Obj16 objB83(0.0f, 0.0f, 0.0f, 0.0f);
    ColorSingleton()->ReadColor(4, &objB83);
    cFlag7151 = 1;
    if (reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetWorldSpace() != 0)
    {
        if (static_cast<ChainObj*>(reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetWorldSpace())
                ->FUN_00586170()
                ->NiObjectNET_GetControllers() != 0)
        {
            cFlag7151 = static_cast<ChainObj*>(reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetWorldSpace())
                            ->FUN_00586170()
                            ->NiObjectNET_GetControllers()
                            ->GetAppCulled_00456610();
            static_cast<ChainObj*>(reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetWorldSpace())
                ->FUN_00586170()
                ->NiObjectNET_GetControllers()
                ->FUN_00450f90(1);
        }
    }

    pMenu25 = static_cast<ChainObj*>(Main_LandLODNode());
    cMenuOk4 = pMenu25->GetAppCulled_00456610();
    if (cMenuOk4 == '\0')
        pMenu25->FUN_00450f90(1);

    cellX17 = DAT_011da368->m_uiMapMarkerCount % *DAT_011c63cc.Setting_Int();
    cellY10 = DAT_011da368->m_uiMapMarkerCount / *DAT_011c63cc.Setting_Int();

    Local12 local1415(0);
    pSub10 = 0;
    base9c33 = DAT_011f426c;

    if (reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetInterior())
    {
        pSub10 = reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_008d6f30();
        if (pSub10 != 0)
        {
            int insideTileX1;
            int ex62;
            int ey21;
            Position adj31 = pos15;
            static_cast<ChainObj*>(pSub10)->AdjustCoordForNorthRotation(reinterpret_cast<NiPt3*>(&pos15),
                                                         reinterpret_cast<NiPt3*>(&adj31), 1);
            ex62 = (FloatToInt(adj31.x) - 0x800) >> 0xc;
            ey21 = (FloatToInt(adj31.y) - 0x800) >> 0xc;
            insideTileX1 = ex62 + cellX17 - (gridSize13 >> 1);
            int insideTileY1 = ey21 + cellY10 - (gridSize13 >> 1);
            base9c33 =
                reinterpret_cast<const Position&>(NiPt3(static_cast<float>((insideTileX1 << 0xc) + 0x800),
                                                        static_cast<float>((insideTileY1 << 0xc) + 0x800), 0.0f));
            static_cast<ChainObj*>(pSub10)->TESObjectCELL_GetIntSeenSection(insideTileX1, insideTileY1, 0);
            static_cast<ChainObj*>(static_cast<void*>(NiXenonRenderer_GetRenderer()))->NiXenonRenderer_LockRenderer();
            static_cast<ChainObj*>(pSub10)->GetInteriorLocalMapTexture(insideTileX1, insideTileY1, &local1415);
            static_cast<ChainObj*>(static_cast<void*>(NiXenonRenderer_GetRenderer()))->NiXenonRenderer_UnlockRenderer();
            if (cellX17 == 0 && cellY10 == 0)
                static_cast<ChainObj*>(pSub10)->CollectCellReferences(
                    reinterpret_cast<unsigned int*>(&DAT_011da368->LocalMapMarkerList));
        }
    }
    else
    {
        int wx5;
        int outsideTileY1;
        int outsideTileX2;
        int wy1;
        void* pReg8 = reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetWorldSpace();
        wx5 = FloatToInt(pos15.x) >> 0xc;
        wy1 = FloatToInt(pos15.y) >> 0xc;
        outsideTileX2 = wx5 + cellX17 - (gridSize13 >> 1);
        outsideTileY1 = wy1 + cellY10 - (gridSize13 >> 1);
        base9c33 = reinterpret_cast<const Position&>(
            NiPt3(static_cast<float>(outsideTileX2 << 0xc), static_cast<float>(outsideTileY1 << 0xc), 0.0f));
        if (pReg8 != 0)
            pSub10 = static_cast<ChainObj*>(pReg8)->FUN_005875a0(outsideTileX2, outsideTileY1);
        if (pSub10 != 0)
        {
            static_cast<ChainObj*>(pSub10)->FUN_00555bc0();
            static_cast<ChainObj*>(static_cast<void*>(NiXenonRenderer_GetRenderer()))->NiXenonRenderer_LockRenderer();
            static_cast<ChainObj*>(pSub10)->TESObjectCELL_GetExteriorLocalMapTexture(&local1415);
            static_cast<ChainObj*>(static_cast<void*>(NiXenonRenderer_GetRenderer()))->NiXenonRenderer_UnlockRenderer();
            static_cast<ChainObj*>(pSub10)->CollectCellReferences(
                reinterpret_cast<unsigned int*>(&DAT_011da368->LocalMapMarkerList));
        }
    }

    if (static_cast<unsigned char>(param_1) != 0)
    {
        char pathB41[0x104];
        C39* p3925;
        char pathA25[0x104];
        /* dump current view into per-cell screenshot folders */
        CreateDirectoryA(DAT_01075520, 0);
        CreateDirectoryA(DAT_01075508, 0);
        CreateDirectoryA(DAT_010754f0, 0);
        if (reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_005f36f0() != 0)
        {
            BSsprintf(pathA25, 0x104, DAT_010754d4,
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_005f36f0())->v076());
            CreateDirectoryA(pathA25, 0);
            BSsprintf(pathB41, 0x104, DAT_010754ac,
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_005f36f0())->v076(),
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_005f36f0())->v076(), cellX17,
                         cellY10);
        }
        else
        {
            BSsprintf(pathA25, 0x104, DAT_01075490,
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_004fd3e0())->v076());
            CreateDirectoryA(pathA25, 0);
            BSsprintf(pathB41, 0x104, DAT_01075468,
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_004fd3e0())->v076(),
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_004fd3e0())->v076(),
                         (FloatToInt(pos15.x) >> 0xc) + cellX17, (FloatToInt(pos15.y) >> 0xc) + cellY10);
        }
        p3925 = static_cast<C39*>(NiObject_DynamicCast(reinterpret_cast<unsigned int>(&DAT_011f4418),
                                               reinterpret_cast<ChainObj*>(local1415.Modelloader_GetReferencedThis())->FUN_0059bb30()));
        NiRenderedTexture_SaveToFile(pathB41, 3, p3925->v039(0));
        DAT_011da368->m_uiMapMarkerCount =
            DAT_011da368->m_uiMapMarkerCount + 1;
        return;
    }

    /* build the tile mesh: vertices, normals, uvs, colours, indices */
    pvV17 = new NiPt3[m23];
    void* pvN31 = new NiPt3[m23];
    pvT32 = new NiPt2[m23];
    pvC52 = new NiCol[m23];
    pIdx11 = static_cast<short*>(_NiMalloc_00aa1070((n25 * 2) * 3 * 2));

    idx19 = 0;
    for (i17 = 0; i17 < m10; i17++)
    {
        for (j17 = 0; j17 < m10; j17++)
        {
            static_cast<NiPt3*>(pvV17)[idx19] =
                NiPt3(static_cast<float>(j17 * step17) - static_cast<float>(size27) / DBL_01011590, 0.0f,
                      static_cast<float>(i17 * step17) - static_cast<float>(size27) / DBL_01011590);
            idx19++;
        }
    }
    idx19 = 0;
    for (i17 = 0; i17 < m10; i17++)
    {
        for (j17 = 0; j17 < m10; j17++)
        {
            static_cast<NiPt3*>(pvN31)[idx19] = NiPt3(0.0f, 1.0f, 0.0f);
            static_cast<NiPt2*>(pvT32)[idx19] =
                NiPt2(static_cast<float>(j17) / m10, 1.0f - static_cast<float>(i17) / m10);
            NiPt3 mk324(static_cast<float>(j17) * fStep27, static_cast<float>(i17) * fStep27, 0.0f);
            mk324.ComputeValue_0063c8a0(reinterpret_cast<NiPt3*>(&base9c33));
            float hgt = FLT_0101e570;
            if (DAT_011da368->m_bNeedsMapUpdate != 0)
                hgt = static_cast<float>(TESObjectCELL_GetSeenValue(reinterpret_cast<V3Maker*>(&mk324)));
            static_cast<NiCol*>(pvC52)[idx19] = NiCol(1.0f, 1.0f, 1.0f, hgt / DBL_0101db80);
            idx19++;
        }
    }
    idx19 = 0;
    for (i17 = 0; i17 < n2; i17++)
    {
        for (j17 = 0; j17 < n2; j17++)
        {
            if ((i17 % 2) ^ (j17 % 2))
            {
                short sVertexIndex;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
            }
            else
            {
                short sVertexIndex;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
            }
        }
    }

    /* create mesh + fx objects, submit to renderer */
    pMesh14 = reinterpret_cast<Mesh34*>(new ObjD4(static_cast<unsigned short>(m23), pvV17, pvN31, pvC52, pvT32, 1, 0,
                                                  n25 << 1, pIdx11, 0, 0, (int)ScreenWidth(), (int)ScreenHeight()));
    pFx44 = new ObjB0(false);

    static_cast<ObjB0*>(pFx44)->SetTileTexture(local1415.Modelloader_GetReferencedThis());
    static_cast<ObjB0*>(pFx44)->EffectSetting_SetAreaSound(0);
    static_cast<ObjB0*>(pFx44)->SetNavMeshInfo(&objB83);
    static_cast<ObjB0*>(pFx44)->SetFlag(1);
    local1415.FUN_0066b0d0(0);
    pMesh14->NiAVObject_AttachProperty(pFx44);

    pFx221 = new Obj1C();
    static_cast<Obj1C*>(pFx221)->NiAlphaProperty_SetSrcBlendMode(6);
    static_cast<Obj1C*>(pFx221)->NiAlphaProperty_SetDestBlendMode(0);
    static_cast<Obj1C*>(pFx221)->NiAlphaProperty_SetAlphaBlending(1);
    pMesh14->NiAVObject_AttachProperty(pFx221);
    FUN_00b57e30(pMesh14, 0, 0);
    pMesh14->NiAVObject_SetTranslate_004bc1f0(static_cast<float>(size27 * cellX17) + static_cast<float>(size27) / DBL_01011590, 0.0f,
                          static_cast<float>(size27 * cellY10) + static_cast<float>(size27) / DBL_01011590 -
                              totalSize40);
    pMesh14->UpdateProperties();

    static_cast<C55*>(reinterpret_cast<void*>(
                          reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])->GetModel_0056c7f0()))
        ->v055(pMesh14, 1);
    reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])->Tile_ClearNeedsUpdate(0x20);

    DAT_011ff3a8 = savedColor1;
    DAT_011ff103 = svByte10316;

    if (cFlag7151 == '\0')
    {
        if (reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetWorldSpace() != 0)
            static_cast<ChainObj*>(reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->TESObjectREFR_GetWorldSpace())
                ->FUN_00586170()
                ->NiObjectNET_GetControllers()
                ->FUN_00450f90(cFlag7151);
    }
    if (cMenuOk4 == '\0')
        pMenu25->FUN_00450f90(0);

    reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])->Tile_SetChangeFlag(0x108);
    reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])->FUN_00700320(0xfcd, size27 * gridSize13);
    reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])->FUN_00700320(0xfce, size27 * gridSize13);
    reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])
        ->Tile_Set(0xfb2, objB83.c.r * DBL_0101e568, 1);
    reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])
        ->Tile_Set(0xfb3, objB83.c.g * DBL_0101e568, 1);
    reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])
        ->Tile_Set(0xfb4, objB83.c.b * DBL_0101e568, 1);
    mk8c26.FUN_0043d410(0.0f, 0, 0);
    static_cast<ChainObj*>(
        reinterpret_cast<void*>(
            reinterpret_cast<Tile30*>(DAT_011da368->m_pTiles[2])->GetModel_0056c7f0()))
        ->NiAVObject_Update(&mk8c26);
    DAT_011da368->m_uiMapMarkerCount = DAT_011da368->m_uiMapMarkerCount + 1;
    if (MapMenu_ShouldRenderLocalMap() == 0)
    {
        if (DAT_011da368->m_pMapTile == DAT_011da368->m_pTiles[2])
            DAT_011da368->UpdateLocalMap();
    }
}

namespace fnv_00705ec0 {
class IMHelper
{
  public:
    bool TESTextureList_GetTextureCount();
    void SetRenderedMenu();
};
class ValueHolder
{
  public:
    void* GetModel_0056c7f0();
};
class DatHolder
{
  public:
    unsigned char* FUN_00408d60();
};
extern DatHolder DAT_011db620;
class SpawnedObject
{
  public:
    SpawnedObject();
    SpawnedObject* Init();
    void Attach(ValueHolder* a);
    void Set(void* a);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
};
InterfaceManager* InterfaceManager_GetSingleton();
IMHelper* __stdcall Getter2(SpawnedObject* obj);
ValueHolder* HackingMenu_Create(void* a);
void Tile_UpdateAll(int a);
// @fnv 0x00705ec0
// src: COMMUNITY 0x00705ec0
bool Interface_CreateHackingMenu(void* arg)
{
    if (InterfaceManager_GetSingleton() != 0 && ((IMHelper*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        ValueHolder* v = HackingMenu_Create(arg);
        if (*DAT_011db620.FUN_00408d60())
        {
            Tile_UpdateAll(0);
            SpawnedObject* obj = new SpawnedObject();
            obj->Attach(v);
            obj->Set(v->GetModel_0056c7f0());
            Getter2(obj)->SetRenderedMenu();
        }
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00705ec0

namespace fnv_007046f0 {
struct PipboyQ
{
    void FOPipboyManager_TriggerRandomEffect();
    void FUN_007fa010(int);
    bool IsUnk28Set();
};
struct IMQ : InterfaceManager
{
    bool TESTextureList_GetTextureCount();
    PipboyQ* FUN_00704370();
};
Tile* Tile_GetMenuByClass(int);
bool Interface_IsMenuIDVisible(int, int);
Tile* Interface_CreateItemModMenu();
void StatsMenu_ResetHealingMode();
void InventoryMenu_SetKnobPosition(int);

// Shows or hides a menu tile and, when showing it, hides several other menu tiles.
// @fnv 0x007046f0
// src: XBOX_PDB 0x007046f0
void Interface_SetItemModMenuVisible(bool abShow, bool abInstant, bool abActivate)
{
    if (InterfaceManager_GetSingleton() && ((IMQ*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        Tile* m_pInventoryChangesValue = Tile_GetMenuByClass(0x3eb);
        Tile* pStats = Tile_GetMenuByClass(0x3ea);
        Tile* pMap = Tile_GetMenuByClass(0x40b);
        Tile* pRepair5 = Tile_GetMenuByClass(0x3ff);
        Tile* pMenu2 = Tile_GetMenuByClass(0x425);
        bool bVisible8 = Interface_IsMenuIDVisible(0x425, abInstant ? 0xb : 0);
        if (abShow)
        {
            if (!pMenu2)
                pMenu2 = Interface_CreateItemModMenu();
            if (!bVisible8)
            {
                if (m_pInventoryChangesValue)
                {
                    m_pInventoryChangesValue->Tile_GetMenu()->LoadMenuData();
                    StatsMenu_ResetHealingMode();
                }
                if (pRepair5)
                    pRepair5->Tile_GetMenu()->LoadMenuData();
                if (pMap)
                    pMap->Tile_GetMenu()->LoadMenuData();
                if (pMenu2)
                    pMenu2->Tile_GetMenu()->UnloadMenuData();
                if (pStats)
                    pStats->Tile_GetMenu()->LoadMenuData();
            }
            if (pMenu2)
                ((Tile*)InterfaceManager_GetSingleton()->CombatController_GetCombatState())->FUN_00700320(0x1771, 0x425);
            if (abActivate)
            {
                ((IMQ*)InterfaceManager_GetSingleton())->FUN_00704370()->FOPipboyManager_TriggerRandomEffect();
                ((IMQ*)InterfaceManager_GetSingleton())->FUN_00704370()->FUN_007fa010(2);
            }
            if (((IMQ*)InterfaceManager_GetSingleton())->FUN_00704370()->IsUnk28Set())
                InventoryMenu_SetKnobPosition(0);
        }
        else if (!abShow && bVisible8 && pMenu2)
        {
            pMenu2->Tile_GetMenu()->LoadMenuData();
        }
    }
}
}  // namespace fnv_007046f0

namespace s7094f0 {

struct Lock
{
    void BSSpinLock_Lock(int iArg);
    void BSSpinLock_Unlock();
};


struct NameMenu
{
    NameMenu(int iArg0, int iArg1);

    void Tile_SetParent(Tile* parent, Tile* replacedChild);
    void FUN_00707e10(const char* pcName);
    void FUN_00409480(struct NameTile* pkTile);

    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk3c;
};

struct NameTile
{
    NameTile();

    void FUN_00a1dc70(NameMenu* pkNameMenu, int iArg);

    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk28;
};

extern Lock DAT_011d89c0;
extern int DAT_011d8950;
extern TESObjectREFR* DAT_011d8954;
extern int DAT_011d8958;
extern int DAT_011d895c;
extern int DAT_011d8960;
extern int DAT_011d8964;
extern int DAT_011d8998;
extern int DAT_011d899c;

InterfaceManager* InterfaceManager_GetSingleton();
int Interface_CreateContainerMenu(TESObjectREFR* pkRef, int iArg);
bool Interface_CreateHackingMenu(TESObjectREFR* pkRef);
bool Interface_CreateComputerMenu(TESObjectREFR* pkRef);
int Interface_CreateDialogMenu(TESObjectREFR* pkRef, int iArg0, int iArg1);
int GetOrCreateMenuTile(int iArg);
bool InitStartMenu(int iArg0, int iArg1);
void HUDMainMenu_UpdateVisibilityState(int iArg);
bool MessageMenu_Create();
bool DestroyCompanionWheelMenu(Actor* pkActor);

static const char s_szPlayerNameEntryMenu[] = "Player Name Entry Menu";

// Processes pending action requests stored in DAT_011d8950 and DAT_011d8998, executing the corresponding logic and clearing the flags on success.
// @fnv 0x007094f0
// src: COMMUNITY 0x007094f0
void Interface_HandleQueuedMenuOpen()
{
    DAT_011d89c0.BSSpinLock_Lock(0);
    if (DAT_011d8950 && (!InterfaceManager_GetSingleton()->uiPipboyMode || DAT_011d8950 == 6 || DAT_011d8950 == 7))
    {
        bool bPickResultFound = false;
        switch (DAT_011d8950)
        {
        case 1:
            bPickResultFound = s7094f0::Interface_CreateContainerMenu(DAT_011d8954, DAT_011d8964) ? 1 : 0;
            break;
        case 2:
            bPickResultFound = Interface_CreateHackingMenu(DAT_011d8954);
            break;
        case 3:
            bPickResultFound = Interface_CreateComputerMenu(DAT_011d8954);
            break;
        case 4:
            if (!InterfaceManager_GetSingleton()->IsInMenuMode())
                bPickResultFound = Interface_CreateDialogMenu(DAT_011d8954, DAT_011d8958, DAT_011d895c) ? 1 : 0;
            break;
        case 5:
            bPickResultFound = GetOrCreateMenuTile(DAT_011d8960) ? 1 : 0;
            break;
        case 6:
            bPickResultFound = InitStartMenu(1, 0);
            if (bPickResultFound)
                HUDMainMenu_UpdateVisibilityState(4);
            break;
        case 7:
            bPickResultFound = MessageMenu_Create();
            break;
        case 8:
            bPickResultFound = DestroyCompanionWheelMenu(dynamic_cast<Actor*>(DAT_011d8954));
            break;
        case 9: {
            NameMenu* pkNameMenu = new NameMenu(0, 0);
            NameTile* pkTile = new NameTile;
            pkNameMenu->Tile_SetParent(InterfaceManager_GetSingleton()->CombatController_GetCombatState(), 0);
            pkNameMenu->FUN_00707e10(s_szPlayerNameEntryMenu);
            pkTile->FUN_00a1dc70(pkNameMenu, 1);
            pkNameMenu->FUN_00409480(pkTile);
            bPickResultFound = true;
        }
        }
        if (bPickResultFound)
        {
            DAT_011d8950 = 0;
            DAT_011d8954 = 0;
        }
    }
    if (DAT_011d8998 && (!InterfaceManager_GetSingleton()->uiPipboyMode || DAT_011d8998 == 6 || DAT_011d8998 == 7))
    {
        bool bSuccess2 = false;
        switch (DAT_011d8998)
        {
        case 7:
            bSuccess2 = MessageMenu_Create();
        }
        if (bSuccess2)
        {
            DAT_011d8998 = 0;
            DAT_011d899c = 0;
        }
    }
    DAT_011d89c0.BSSpinLock_Unlock();
}

}

struct DisplayItem;
struct DisplayForm;
struct DisplayPlayer;

struct DisplayList
{
    void* FUN_00726070();
    Tile** FUN_00683520(void**);
    void** FUN_006815c0();
};

struct DisplayName
{
    const char* TESModel_GetModel();
};


struct DisplayEffects
{
    int unk00;
    DisplayList effects;
    void BuildDescription(char*, int);
};

struct DisplayItem
{
    DisplayForm* FUN_0044ddc0();
    DisplayForm* GetExtraForm();
    float FUN_004bd400();
    unsigned char FUN_004bd820();
    bool HasEffect(int);
    float ItemChange_GetItemHealth(bool);
    DisplayList* Modelloader_GetReferencedThis();
    int FUN_00726070();
};

struct DisplayForm
{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int unk1c;

    int unk20;

    int unk24;

    int unk28;

    int unk2c;

    DisplayName name;
    int FUN_00401170();
    void TESAmmo_BuildMenuString(char*, int);
    float FUN_004be380(bool);
    int GetField19C();
    unsigned char FUN_00525b20(bool, int, DisplayPlayer*);
    DisplayForm* TESObjectWEAP_GetCurrentAmmo(DisplayPlayer*);
    const char* GetStringAtOffsetC4();
    int GetFlaggedValue(bool);
    float GetAmmoRegenRate(int);
    float TESObjectARMO_GetArmorRating();
    float TESObjectARMO_GetDamageThreshold();
    DisplayForm* FUN_004bd570(int);
    bool FUN_0040e210(int);
};

struct DisplayProcess
{

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

    virtual void v63();

    virtual void v64();

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

    virtual DisplayItem* Weapon();
    virtual DisplayItem* Ammo();
};

#include "../../../include/ActorValues.h"

struct DisplayPlayerPrefix
{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int unk1c;

    int unk20;

    int unk24;

    int unk28;

    int unk2c;

    int unk30;

    int unk34;

    int unk38;

    int unk3c;

    int unk40;

    int unk44;

    int unk48;

    int unk4c;

    int unk50;

    int unk54;

    int unk58;

    int unk5c;

    int unk60;

    int unk64;

    int unk68;

    int unk6c;

    int unk70;

    int unk74;

    int unk78;

    int unk7c;

    int unk80;

    int unk84;

    int unk88;

    int unk8c;

    int unk90;

    int unk94;

    int unk98;

    int unk9c;

    int unka0;
};

struct DisplayPlayer : DisplayPlayerPrefix, ActorValues
{
    bool PlayerCharacter_IsHardcore();
    DisplayProcess* FUN_008d8520();
};

struct DisplayInventory
{
    int FUN_004c8f30(DisplayForm*);
};

struct DisplayDescription
{

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* Text(int, int);
};

struct DescriptionForm
{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int unk1c;

    int unk20;

    int unk24;

    int unk28;

    int unk2c;

    int unk30;

    int unk34;

    int unk38;

    int unk3c;

    int unk40;

    int unk44;

    int unk48;

    int unk4c;

    int unk50;

    int unk54;

    int unk58;

    int unk5c;

    int unk60;

    int unk64;

    int unk68;

    int unk6c;

    int unk70;

    DisplayDescription description;
};

struct EffectPrefix
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
};

struct EffectForm : EffectPrefix, DisplayEffects
{
};

struct EnchantPrefix
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

struct EnchantForm : EnchantPrefix, DisplayEffects
{
    bool FUN_0040e210(int);
};

extern Setting *DAT_0118a644, *DAT_0118a648, *DAT_0118a640;

extern Setting DAT_011d4024, DAT_011c6478, DAT_011c64a8, DAT_011c3cb4, DAT_011d20c4, DAT_011d412c, DAT_011d2c7c,
    DAT_011d2aa8, DAT_011d26a0, DAT_011d4da4, DAT_011d4edc, DAT_011d330c;

extern char DAT_0106ed20[], DAT_0106ed18[], DAT_0106ed0c[], DAT_0106ecfc[], DAT_01020764[], DAT_0106ecf4[],
    DAT_01019f08[], DAT_0106ece8[], DAT_01047008[], DAT_0106ece0[], DAT_0106ecd8[], DAT_0106ecd0[], DAT_0106ecc8[],
    DAT_01020768[], DAT_01030018[], DAT_01018348[];

int Tile_TextToTrait(const char*);
float FUN_0048ebc0(DisplayForm*, bool);
Tile* Tile_GetTileByName(Tile*, const char*);

unsigned int BSstrlen(const char*);
void FUN_005e58f0(int, DisplayPlayer*, ...);
float FUN_00645380(ActorValues*, DisplayForm*, float, bool, DisplayItem*, int, int, int, float, float, int, int,
                   DisplayForm*);
float GetWeaponDamage(DisplayForm*, float, DisplayItem*, DisplayForm*);

void FUN_00406d30(char*, unsigned int, const char*);
float FUN_004bd510(float, float);
float BSMIN(float, float);
DisplayInventory* FUN_004bf220(DisplayPlayer*);
int MinInt(int, int);
float FUN_00646360(int, float);
float FUN_00476b20(float);
unsigned int FUN_004873d0(DisplayForm*);
EnchantForm* FUN_004be330(DisplayForm*);
int BSstrcmp(const char*, const char*);

// Populates the inventory item detail panel tiles with type-specific stats, effects, and value labels.
// @fnv 0x00707e30
// src: XBOX_PDB 0x00707e30
void Interface_PopulateItemStatsDisplay(DisplayItem* item, Tile* root)
{

    {

        int maskB = 0;

        int label3 = Tile_TextToTrait(DAT_0106ed20);

        int text3 = Tile_TextToTrait(DAT_0106ed18);

        int value = 0x1009;
        float modY4 = 0.0f;
        float aModZ = 0.0f;

        float _worth = item->FUN_004bd400();
        float weight =
            FUN_0048ebc0(item->FUN_0044ddc0(), reinterpret_cast<DisplayPlayer*>(g_thePlayer)->PlayerCharacter_IsHardcore());

        Tile* tiles3[13];
        char worthBufTmp[16];
        char weightBuf[32];

        if (item && root)
        {

            void* pos = reinterpret_cast<NiTPointerListBase<NiTPointerAllocator<unsigned int>, Tile*>*>(&root->m_kChildTileList)->GetHeadPos();
            int indexB = 0;

            while (pos && indexB < 13)
            {
                tiles3[indexB] = reinterpret_cast<NiTPointerListBase<NiTPointerAllocator<unsigned int>, Tile*>*>(&root->m_kChildTileList)->GetNext(pos);
                ++indexB;
            }

            while (indexB < 13)
            {
                tiles3[indexB] = 0;
                ++indexB;
            }

            Tile* position = Tile_GetTileByName(root, DAT_0106ed0c);
            Tile* reference8 = Tile_GetTileByName(root, DAT_0106ecfc);

            position->Tile_Set(0xfb0, reference8->FUN_00a011b0(0xfb0), true);

            position->Tile_Set(0xfa2, reference8->FUN_00a011b0(0xfa2), true);

            bool modified3 = item->FUN_004bd820();

            char _modName[128];
            float perk;
            float width;

            switch (item->FUN_0044ddc0()->FUN_00401170())
            {

            case 0x29: {

                maskB = 12;
                DisplayForm* book = item->FUN_0044ddc0();
                char desc[256];
                book->TESAmmo_BuildMenuString(desc, 256);

                if (BSstrlen(desc) > 0)
                {
                    tiles3[6]->Tile_Set_00a01350(text3, desc, true);
                    maskB |= 64;
                }
                else
                    maskB &= ~64;

                break;
            }

            case 0x28: {

                DisplayForm* weapon = item->FUN_0044ddc0();
                tiles3[4]->FUN_00700320(0x100a, true);

                DisplayForm* ammoForm = 0;
                DisplayPlayer* actor_11 = 0;

                if (reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520() &&
                    reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Weapon() &&
                    weapon == reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Weapon()->FUN_0044ddc0())
                {

                    ammoForm =
                        reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Ammo()
                            ? reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Ammo()->FUN_0044ddc0()
                            : 0;
                    actor_11 = reinterpret_cast<DisplayPlayer*>(g_thePlayer);
                }

                weight = weapon->FUN_004be380(item->HasEffect(4));

                if (weight >= 10.0)
                {
                    float multiplier = 1.0f;
                    FUN_005e58f0(0x49, reinterpret_cast<DisplayPlayer*>(g_thePlayer), &multiplier);
                    weight *= multiplier;
                }

                float conditionB = item->ItemChange_GetItemHealth(true) / 100.0;
                int ap_10 = weapon->GetField19C();
                float damage3 = 0.0f;
                float kDps = 0.0f;

                kDps = FUN_00645380(reinterpret_cast<DisplayPlayer*>(g_thePlayer), weapon, conditionB, true, item, 0, 0,
                                    -1, 0.0f, 0.0f, 0, 0, ammoForm);

                if (conditionB <= 0.0)
                    damage3 = 0.0f;
                else
                    damage3 = GetWeaponDamage(weapon, conditionB, item, ammoForm);

                char weaponBuf4[128];
                BSsprintf(weaponBuf4, 128, DAT_01020764, (int)FUN_004bd510(kDps, 1.0f));
                tiles3[1]->Tile_Set_00a01350(text3, weaponBuf4, true);

                unsigned int projectiles_4 = weapon->FUN_00525b20(item->HasEffect(12), 0, actor_11);

                if (projectiles_4 > 1)
                {
                    float perShot = damage3 / projectiles_4;
                    BSsprintf(weaponBuf4, 128, DAT_0106ecf4, perShot, projectiles_4);
                }

                else
                    BSsprintf(weaponBuf4, 128, DAT_01020764, (int)FUN_004bd510(damage3, 1.0f));

                tiles3[11]->Tile_Set_00a01350(text3, weaponBuf4, true);
                tiles3[4]->Tile_Set(value, BSMIN(conditionB, 1.0f), true);

                float reduction = 0.0f;
                FUN_005e58f0(0x35, reinterpret_cast<DisplayPlayer*>(g_thePlayer), weapon, &reduction);
                unsigned int reduced = (unsigned int)reduction;
                ap_10 -= reduced;
                if (ap_10 < 0)
                    ap_10 = 0;

                BSsprintf(weaponBuf4, 128, DAT_01020764, ap_10);
                if (tiles3[10])
                    tiles3[10]->Tile_Set_00a01350(text3, weaponBuf4, true);

                if (weapon->TESObjectWEAP_GetCurrentAmmo(actor_11))
                {

                    DisplayItem* currentWeapon =
                        reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Weapon();
                    DisplayItem* currentAmmo2 = reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Ammo();

                    const char* name2 = weapon->TESObjectWEAP_GetCurrentAmmo(actor_11)->GetStringAtOffsetC4();
                    int total = FUN_004bf220(reinterpret_cast<DisplayPlayer*>(g_thePlayer))
                                    ->FUN_004c8f30(weapon->TESObjectWEAP_GetCurrentAmmo(actor_11));
                    int loaded = 0;

                    if (!name2 || !*name2)
                        name2 = weapon->TESObjectWEAP_GetCurrentAmmo(actor_11)->name.TESModel_GetModel();

                    if (currentWeapon && currentWeapon->Modelloader_GetReferencedThis() && item->Modelloader_GetReferencedThis() &&
                        *currentWeapon->Modelloader_GetReferencedThis()->FUN_006815c0() == *item->Modelloader_GetReferencedThis()->FUN_006815c0())
                        loaded = currentAmmo2 ? currentAmmo2->FUN_00726070() : 0;

                    else
                        loaded = MinInt(weapon->GetFlaggedValue(item->HasEffect(2)), total);

                    bool unlimited2 = weapon->GetAmmoRegenRate(0) == 0.0 ? false : true;

                    if (unlimited2)
                        BSsprintf(weaponBuf4, 128, DAT_01019f08, name2);
                    else
                        BSsprintf(weaponBuf4, 128, DAT_0106ece8, name2, loaded, total - loaded);
                }
                else
                    FUN_00406d30(weaponBuf4, 128, DAT_01047008);

                tiles3[5]->Tile_Set_00a01350(label3, weaponBuf4, true);
                maskB = 0xc3e;
                break;
            }

            case 0x18:
            case 0x1a: {

                tiles3[4]->FUN_00700320(0x100a, false);
                float conditionArmor = item->ItemChange_GetItemHealth(true) / 100.0;
                maskB = 0x3c;

                char armorBuf_[128];
                FUN_00406d30(armorBuf_, 128, DAT_01047008);

                TESObjectARMO* armor =
                    dynamic_cast<TESObjectARMO*>(reinterpret_cast<TESBoundObject*>(item->FUN_0044ddc0()));

                if (armor)
                {
                    if (armor->GetIsHeavyArmor())
                        FUN_00406d30(armorBuf_, 128, DAT_0118a644->FUN_00403df0());
                    else if (armor->GetIsMediumArmor())
                        FUN_00406d30(armorBuf_, 128, DAT_0118a648->FUN_00403df0());
                    else
                        FUN_00406d30(armorBuf_, 128, DAT_0118a640->FUN_00403df0());
                }

                tiles3[5]->Tile_Set_00a01350(label3, armorBuf_, true);

                float dt3 = FUN_00646360((int)item->FUN_0044ddc0()->TESObjectARMO_GetArmorRating(), conditionArmor);
                float dr2 = FUN_00646360((int)item->FUN_0044ddc0()->TESObjectARMO_GetDamageThreshold(), conditionArmor);

                if (dt3 == 0.0 && dr2 == 0.0)
                {
                    maskB |= 1;
                    FUN_00406d30(armorBuf_, 128, DAT_01047008);
                    tiles3[0]->Tile_Set_00a01350(text3, armorBuf_, true);
                }

                else
                {
                    if (dt3 != 0.0)
                    {
                        BSsprintf(armorBuf_, 128, DAT_01020764, (int)FUN_00476b20(dt3));
                        tiles3[0]->Tile_Set_00a01350(text3, armorBuf_, true);
                        maskB |= 1;
                    }
                    if (dr2 != 0.0)
                    {
                        BSsprintf(armorBuf_, 128, DAT_01020764, (int)FUN_00476b20(dr2));
                        tiles3[12]->Tile_Set_00a01350(text3, armorBuf_, true);
                        maskB |= 0x1000;
                    }
                }

                tiles3[4]->Tile_Set(
                    value,
                    BSMIN(1.0f,
                                 item->ItemChange_GetItemHealth(false) /
                                     (FUN_004873d0(item->FUN_0044ddc0()) ? FUN_004873d0(item->FUN_0044ddc0()) : 1)),
                    true);
                break;
            }

            default:
                maskB = 12;
            }

            DisplayEffects* effects5 = 0;

            if (item->FUN_0044ddc0()->FUN_00401170() == 0x1d)
                effects5 = static_cast<EffectForm*>(reinterpret_cast<EffectForm*>(item->GetExtraForm()));

            else if (item->FUN_0044ddc0()->FUN_00401170() == 0x2f)
                effects5 = static_cast<EffectForm*>(reinterpret_cast<EffectForm*>(item->FUN_0044ddc0()));

            else
            {
                EnchantForm* enchant = FUN_004be330(item->FUN_0044ddc0());
                if (enchant && !enchant->FUN_0040e210(4))
                    effects5 = enchant;
            }

            if (effects5 && *effects5->effects.FUN_006815c0())
            {
                char effectBuf[256];
                effects5->BuildDescription(effectBuf, 256);
                if (BSstrlen(effectBuf) > 0)
                {
                    tiles3[6]->Tile_Set_00a01350(text3, effectBuf, true);
                    maskB |= 64;
                }
                else
                    maskB &= ~64;
            }

            else if (item->FUN_0044ddc0()->FUN_00401170() != 0x29)
                maskB &= ~64;

            if (item->FUN_0044ddc0()->FUN_00401170() == 0x67)
            {
                DescriptionForm* note = reinterpret_cast<DescriptionForm*>(item->FUN_0044ddc0());
                tiles3[6]->Tile_Set_00a01350(text3, note->description.Text(0, 0x43534544), true);
                maskB |= 64;
            }

            if (modified3)
            {

                DisplayForm* modWeapon5 = item->FUN_0044ddc0();
                DisplayForm* mod_16 = 0;
                unsigned char flags = item->FUN_004bd820();
                bool labeled = false;

                if (flags & 1)
                {
                    maskB |= 0x80;
                    tiles3[7]->Tile_Set_00a01350(label3, DAT_011d4024.FUN_00403df0(), true);
                    labeled = true;
                    modY4 += 41.0;
                    aModZ += 41.0;
                    mod_16 = modWeapon5->FUN_004bd570(1);
                    if (mod_16)
                        FUN_00406d30(_modName, 128, mod_16->name.TESModel_GetModel());
                    else
                        FUN_00406d30(_modName, 128, DAT_0106ece0);
                    tiles3[7]->Tile_Set_00a01350(text3, _modName, true);
                }

                if (flags & 2)
                {
                    maskB |= 0x100;
                    mod_16 = modWeapon5->FUN_004bd570(2);
                    if (mod_16)
                        FUN_00406d30(_modName, 128, mod_16->name.TESModel_GetModel());
                    else
                        FUN_00406d30(_modName, 16, DAT_0106ecd8);
                    tiles3[8]->Tile_Set_00a01350(text3, _modName, true);
                    if (!labeled)
                    {
                        tiles3[8]->Tile_Set_00a01350(label3, DAT_011d4024.FUN_00403df0(), true);
                        labeled = true;
                    }
                    aModZ += 41.0;
                }

                if (flags & 4)
                {
                    mod_16 = modWeapon5->FUN_004bd570(4);
                    if (mod_16)
                        FUN_00406d30(_modName, 128, mod_16->name.TESModel_GetModel());
                    else
                        FUN_00406d30(_modName, 16, DAT_0106ecd0);
                    tiles3[9]->Tile_Set_00a01350(text3, _modName, true);
                    maskB |= 0x200;
                    if (!labeled)
                    {
                        tiles3[9]->Tile_Set_00a01350(label3, DAT_011d4024.FUN_00403df0(), true);
                        labeled = true;
                    }
                }

                maskB &= ~64;
            }
            else
                maskB &= ~0x80;

            if (_worth > 0.0)
            {
                if (_worth >= 1.0)
                    BSsprintf(worthBufTmp, 16, DAT_0106ecc8, _worth * item->FUN_00726070());
                else
                    BSsprintf(worthBufTmp, 16, DAT_01020768, _worth * item->FUN_00726070());
            }
            else
                FUN_00406d30(worthBufTmp, 16, DAT_01047008);

            tiles3[3]->Tile_Set_00a01350(text3, worthBufTmp, true);
            perk = 0.0f;
            FUN_005e58f0(0x37, reinterpret_cast<DisplayPlayer*>(g_thePlayer), &perk);

            if (perk > 0.0 && weight <= *DAT_011c6478.Setting_Float_00403e20())
                weight *= *DAT_011c64a8.Setting_Float_00403e20();

            if (weight > 0.0)
                BSsprintf(weightBuf, 32, DAT_01030018, weight * item->FUN_00726070());
            else
                FUN_00406d30(weightBuf, 32, DAT_01047008);

            tiles3[2]->Tile_Set_00a01350(text3, weightBuf, true);

            if (BSstrcmp(DAT_011c3cb4.FUN_00403df0(), DAT_01018348))
            {

                tiles3[0]->Tile_Set_00a01350(label3, DAT_011d20c4.FUN_00403df0(), true);

                tiles3[1]->Tile_Set_00a01350(label3, DAT_011d412c.FUN_00403df0(), true);

                tiles3[11]->Tile_Set_00a01350(label3, DAT_011d2c7c.FUN_00403df0(), true);

                tiles3[2]->Tile_Set_00a01350(label3, DAT_011d2aa8.FUN_00403df0(), true);

                tiles3[3]->Tile_Set_00a01350(label3, DAT_011d26a0.FUN_00403df0(), true);

                tiles3[4]->Tile_Set_00a01350(label3, DAT_011d4da4.FUN_00403df0(), true);

                tiles3[6]->Tile_Set_00a01350(label3, DAT_011d4edc.FUN_00403df0(), true);

                tiles3[7]->Tile_Set_00a01350(label3, DAT_011d4024.FUN_00403df0(), true);

                tiles3[10]->Tile_Set_00a01350(label3, DAT_011d330c.FUN_00403df0(), true);
            }

            tiles3[0]->FUN_00700320(0xfa3, (int)((maskB & 1) != 0));

            tiles3[12]->FUN_00700320(0xfa3, (int)((maskB & 4096) != 0));

            tiles3[1]->FUN_00700320(0xfa3, (int)((maskB & 2) != 0));

            tiles3[11]->FUN_00700320(0xfa3, (int)((maskB & 2048) != 0));

            tiles3[2]->FUN_00700320(0xfa3, (int)((maskB & 4) != 0));

            tiles3[3]->FUN_00700320(0xfa3, (int)((maskB & 8) != 0));

            tiles3[4]->FUN_00700320(0xfa3, (int)((maskB & 16) != 0));

            tiles3[5]->FUN_00700320(0xfa3, (int)((maskB & 32) != 0));

            tiles3[6]->FUN_00700320(0xfa3, (int)((maskB & 64) != 0));

            tiles3[7]->FUN_00700320(0xfa3, (int)((maskB & 128) != 0));

            tiles3[8]->FUN_00700320(0xfa3, (int)((maskB & 256) != 0));

            tiles3[9]->FUN_00700320(0xfa3, (int)((maskB & 512) != 0));

            if (tiles3[10])
            {
                tiles3[10]->FUN_00700320(0xfa3, (int)((maskB & 0x400) != 0));
                tiles3[10]->Tile_Set(0xfa9, 255.0f, true);
            }

            width = root->FUN_00a011b0(0xfb0) / 2.0 - 20.0;
            if ((maskB & 0x10) || (maskB & 0x20))
                width *= 2.0f;

            tiles3[6]->Tile_Set(0xfa2, width, true);
            tiles3[7]->Tile_Set(0xfa2, width, true);
            tiles3[8]->Tile_Set(0xfa2, width + modY4, true);
            tiles3[9]->Tile_Set(0xfa2, width + aModZ, true);
        }
    }
}

