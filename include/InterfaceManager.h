#pragma once

// InterfaceManager: the UI singleton, no vtable. 0x580 bytes: InterfaceManager::Instance 0x00709fd0 news 0x580,
// runs the constructor 0x0070a130 and stores the result at 0x011d8a80. The constructor builds the NiPointers at
// +0x04/+0x08/+0x8c/+0x90/+0xac (0x00633c90), the NiPoint3s at +0x2c/+0x38/+0x104, the BSSimpleLists at +0x70/+0x4c4,
// FOHUDEffectManager at +0x178 (0x007f7610), FOVATSEffectManager at +0x1dc (0x007ffec0) and TutorialManager at
// +0x4d4 (0x0070a8e0), news the ViewCaster (0xc) into +0x13c and the Timer (0x14, 0x0070a8a0) into +0x164, clears
// the 10-entry menu stack at +0x114 and stores 1.0 at +0x4d0.

#include "BSSimpleList.h"
#include "FOHUDEffectManager.h"
#include "FOVATSEffectManager.h"
#include "NiPoint3.h"
#include "NiPointer.h"

class Actor;
class BSCullingProcess;
class BSRenderedTexture;
class BSShaderAccumulator;
class FOPipboyManager;
class FORenderedMenu;
class InventoryStackRecord;
class ListBoxBase;
class Menu;
class NiAVObject;
class NiAlphaProperty;
class NiNode;
class SceneGraph;
class ShadowSceneNode;
class TESImageSpaceModifier;
class TESObjectREFR;
class Tile;
class TileImage;
class ViewCaster;

class InterfaceManager
{
public:
    // 0x14-byte timer list head (ctor 0x0070a8a0; the InterfaceManager ctor links its +0x0c to itself).
    class Timer;

    // Help flags: Reset 0x00706b90 clears bits 0/1 of each of the 41 flags and stores 41 at +0xa4, 0 at +0xa8.
    class Help
    {
    public:
        unsigned int auiFlags[41];        // 0x00
        unsigned int uiCount;             // 0xa4
        unsigned int uiCurrent;           // 0xa8

        void Reset();                     // 0x00706b90
        void SetMenuShown(unsigned int);  // 0x007d09c0
    };

    // 0xac bytes at +0x4d4 (to the end of the object); its constructor 0x0070a8e0 only calls Help::Reset on itself.
    class TutorialManager : public Help
    {
    public:
        TutorialManager();                              // 0x0070a8e0
        ~TutorialManager();
        bool ShowMessage(int, int, unsigned int);       // 0x00718630
        bool HasBeenShown(int);                         // 0x00718840
        void FlagAsShown(int);                          // 0x007185e0
        unsigned int GetSaveLoadSize();                 // 0x00706810
        void Update();                                  // 0x007182e0
    };

    bool bStateFlag0;                                   // 0x000
    bool bStateFlag1;                                   // 0x001
    NiPointer<SceneGraph> spSceneGraph004;              // 0x004
    NiPointer<SceneGraph> spSceneGraph008;              // 0x008
    unsigned int uiCurrentMode;                         // 0x00c ctor: 1
    unsigned char byte010;                              // 0x010
    unsigned char byte011;                              // 0x011
    unsigned char byte012;                              // 0x012 ctor: 0xff
    unsigned char byte013;                              // 0x013 ctor: 0xff
    unsigned char byte014;                              // 0x014 ctor: 0xff
    unsigned char byte015;                              // 0x015 ctor: 0xff
    unsigned int uiPickLength;                          // 0x018 ctor: 0x50
    unsigned int unk01C;                                // 0x01c
    bool byte020;                                       // 0x020 Instance: 0
    bool byte021;                                       // 0x021 Instance: 0
    unsigned int unk024;                                // 0x024
    TileImage* pCursor;                                 // 0x028
    NiPoint3 kCursorPos02C;                             // 0x02c
    NiPoint3 kCursorPos038;                             // 0x038
    float fMouseWheel;                                  // 0x044
    float flt048;                                       // 0x048
    Tile* pDraggedTile;                                 // 0x04c
    int unk050;                                         // 0x050
    float flt054;                                       // 0x054
    float flt058;                                       // 0x058
    int unk05C;                                         // 0x05c
    int unk060;                                         // 0x060
    int unk064;                                         // 0x064
    unsigned int unk068[2];                             // 0x068
    BSSimpleList<TESObjectREFR*> kSelectableRefs;       // 0x070
    unsigned int uiSelectedRefIndex;                    // 0x078
    bool bDebugText;                                    // 0x07c
    unsigned char byte07D;                              // 0x07d
    NiNode* pUIRootNode;                                // 0x080
    NiNode* pCursorRootNode;                            // 0x084
    unsigned int unk088;                                // 0x088
    NiPointer<BSShaderAccumulator> spShaderAccum08C;    // 0x08c
    NiPointer<BSShaderAccumulator> spShaderAccum090;    // 0x090
    ShadowSceneNode* pShadowScene094;                   // 0x094
    ShadowSceneNode* pShadowScene098;                   // 0x098
    Tile* pMenuRoot;                                    // 0x09c
    Tile* pGlobalsTile;                                 // 0x0a0
    union
    {
        NiNode* pDebugTextRoot;                         // 0x0a4
        unsigned int uiCount;                          // 0x0a4
    };
    union
    {
        float fScreenScale;                            // 0x0a8
        unsigned int uiCurrent;                        // 0x0a8
    };
    NiPointer<NiNode> sp0AC;                            // 0x0ac
    unsigned short us0B0;                               // 0x0b0
    unsigned short usPickDistance;                      // 0x0b2
    Tile* pTile0B4;                                     // 0x0b4
    Tile* pTile0B8;                                     // 0x0b8
    Tile* pActiveTileAlt;                               // 0x0bc
    unsigned int unk0C0;                                // 0x0c0 ctor: 0x64
    unsigned int unk0C4;                                // 0x0c4
    bool byte0C8;                                       // 0x0c8 ctor: 1
    bool byte0C9;                                       // 0x0c9
    Tile* pActiveTile;                                  // 0x0cc
    Menu* pActiveMenu;                                  // 0x0d0
    Tile* pTile0D4;                                     // 0x0d4
    Menu* pMenu0D8;                                     // 0x0d8
    unsigned char byte0DC;                              // 0x0dc
    unsigned char byte0DD;                              // 0x0dd
    unsigned int unk0E0;                                // 0x0e0
    unsigned char ucMsgBoxButton;                       // 0x0e4 ctor: 0xff
    unsigned int unk0E8;                                // 0x0e8
    unsigned char byte0EC;                              // 0x0ec
    bool bHasMouseMoved;                                // 0x0ed ctor: 1
    TESObjectREFR* pDebugSelection;                     // 0x0f0
    TESObjectREFR* pRef0F4;                             // 0x0f4
    TESObjectREFR* pRef0F8;                             // 0x0f8
    TESObjectREFR* pCrosshairRef;                       // 0x0fc
    TESObjectREFR* pRef100;                             // 0x100
    NiPoint3 kPoint104;                                 // 0x104
    unsigned char byte110;                              // 0x110
    unsigned int auiMenuStack[10];                      // 0x114
    ViewCaster* pViewCaster;                            // 0x13c
    unsigned int unk140;                                // 0x140
    unsigned int unk144;                                // 0x144
    unsigned char byte148;                              // 0x148
    bool bIsShift;                                      // 0x149
    unsigned int uiKeyModifiers;                        // 0x14c
    unsigned int uiCurrentKey;                          // 0x150
    unsigned int uiKeyRepeatStartTime;                  // 0x154
    unsigned int uiLastKeyRepeatTime;                   // 0x158
    unsigned int unk15C;                                // 0x15c
    unsigned int unk160;                                // 0x160
    Timer* pTimerList;                                  // 0x164
    bool byte168;                                       // 0x168
    FORenderedMenu* pRenderedMenu;                      // 0x16c
    bool byte170;                                       // 0x170
    FOPipboyManager* pPipboyManager;                    // 0x174
    FOHUDEffectManager kHUDEffects;                     // 0x178
    FOVATSEffectManager kVATSEffects;                   // 0x1dc
    float fScale4AC;                                    // 0x4ac
    float flt4B0;                                       // 0x4b0
    unsigned char byte4B4;                              // 0x4b4
    unsigned char byte4B5;                              // 0x4b5
    unsigned char byte4B6;                              // 0x4b6
    unsigned char byte4B7;                              // 0x4b7
    unsigned int uiQueuedPipboyTab;                     // 0x4b8
    unsigned int uiPipboyMode;                          // 0x4bc
    void* pPipboyModeCallback;                          // 0x4c0
    BSSimpleList<void*> kList4C4;                       // 0x4c4 element type not established
    bool byte4CC;                                       // 0x4cc
    bool byte4CD;                                       // 0x4cd
    float fScreenAspectRatio;                           // 0x4d0 ctor: 1.0
    TutorialManager kTutorialManager;                   // 0x4d4

    InterfaceManager();                                 // 0x0070a130
    ~InterfaceManager();                                // 0x0070a920
#if !defined(_MSC_VER) || defined(__vecDelDtor)
    void* __vecDelDtor(unsigned int);
#endif
    // MSVC supplies __vecDelDtor(unsigned int) from the destructor.
    FOHUDEffectManager* GetHUDEffects();                // 0x00460fb0
    FOVATSEffectManager* GetVATSEffect();               // 0x00602170

    // Declarations the units bind (union of their copies); FUN_ names are placeholders.
    void Accumulate();
    int AddMenuStackEntry(int, bool);
    void AddTileIfAbsent(Tile*);
    void CalculateConsolePickRefs();
    void ClearActivatePickResults();
    void ClearCurrentFocusTarget();
    void ClearInterfaceState(Tile*, int, bool);
    void ClearMenuInput();
    void ClearPickedREFR();
    void ClearPipboyPickResults();
    void ClearTargetREFR();
    static void ClearTimer(void*);
    void ClosePipboy(int*);
    void Click(BSRenderedTexture*, BSRenderedTexture*);
    static int ConvertGamepadButton(int);
    void CullInterfaceMenus();
    void CullPipboyMenus();
    void Disable360Controller(bool);
    void DumpMenuPackingInfo();
    static bool InterfaceManager_Has360Controller();
    NiNode* FUN_004fb070();
    Tile* GetAVEffect();
    void BGSTerminal_SetPassword(Tile*);
    Tile* CombatController_GetCombatState();
    bool IsInMenuMode();
    TESObjectREFR* GetCurrentWeapon();
    bool GetIsEmergencyTextureRelease();
    void FUN_00714d70(int);
    void InterfaceManager_SetCurrentFocusTarget(Tile*, int, int);
    bool InterfaceManager_TutorialManager_HasBeenShown(int);
    TESImageSpaceModifier* InterfaceManager_GetCurrentImagespaceMod();  // 0x00718ab0 (defined in interfacemanager.cpp; called on the singleton by 0x00871dc0)
    bool InterfaceManager_GetLockpickControlsDisable();
    int InterfaceManager_GetCursorY();
    int GetCursorX();
    float InterfaceManager_GetPipboyMouseX();
    float QueuedModel_GetOverriddenVisualDistance();
    Actor* Projectile_GetShooter();
    bool TESTextureList_GetTextureCount();
    void FUN_00984f60(unsigned int);
    float TESCombatStyle_GetWeaponMinRangeMult();
    static void Free();
    void FreeTimerList();
    static bool Get360ControllerDisabled();
    SceneGraph* Get3DSceneGraph();
    BSShaderAccumulator* Get3dAccumulator();
    BSShaderAccumulator* GetAccumulator();
    int GetActivatePickResult(int);
    NiPoint3 GetActivatePickLocation(); // 0x007033d0 returns three position components.
    TESObjectREFR* GetActivateREFR();
    FORenderedMenu* GetActiveRenderedMenu();
    NiAlphaProperty* GetAlphaProp();
    int GetChar(int, int);
    bool GetClickMultithreaded();
    static bool GetContainerMenuQueued();
    Tile* GetCurrentFocusTarget();
    int GetCurrentMainMenu();
    TESObjectREFR* GetCurrentPickedREFR();
    Tile* GetCursor();
    int GetCursorOffsetX();
    int GetCursorOffsetY();
    NiNode* GetCursorRoot();
    int GetCursorY();
    NiNode* GetDebugTextRoot();
    bool GetDebugTextVisible();
    void GetDefaultFocus();
    int GetDragDroppingState();
    static float GetFirstInterfaceFloat();
    static float GetFourthInterfaceFloat();
    int GetGamepadInput(bool, bool, bool*);
    TESImageSpaceModifier* GetImageSpaceModifier();
    static int GetInputButtonCode(int, bool);
    NiNode* GetInterfaceNode();
    char GetInventoryPageNumber();
    unsigned short GetKeyModifiers();
    static unsigned int GetLastXDefault(int);
    char GetMagicPageNumber();
    static bool GetMainDiskError();
    char GetMapPageNumber();
    static float GetMenuHeight();
    char GetMenuMode();
    int GetMenuStackEntry(int);
    TileImage* GetMouseCursorImage();
    float GetMouseHeldTime();
    bool GetMouseVisible();
    int GetMouseWheel();
    float GetOneToOneDistance();
    SceneGraph* GetOrCreateSceneGraph(SceneGraph*, char*, bool);
    Tile* GetParent();
    int GetPickCursorX();
    int GetPickDistance();
    Tile* GetPickTarget(bool);
    TESObjectREFR* GetPickedREFR();
    FOPipboyManager* GetPipboyManagerInstance();
    void GetPipboyMouseCoords(float*, float*);
    float GetPipboyMouseX();
    float GetPipboyMouseY();
    NiNode* GetPlayerRoot();
    Tile* GetPrimaryInterfaceTile();
    float GetRawCursorX();
    float GetRawCursorY();
    int GetRealCursorX();
    int GetRealCursorY();
    static float GetRealScreenBottom();
    static float GetRealScreenLeft();
    static float GetRealScreenRight();
    static float GetRealScreenTop();
    int GetRepeatingKey(float);
    float GetScaledValue();
    SceneGraph* GetSceneGraph();
    static float GetScreenAspect();
    static float GetScreenBottom();
    static float GetScreenLeft();
    static float GetScreenRight();
    static float GetScreenSafeX();
    static float GetScreenSafeY();
    static float GetScreenTop();
    Tile* GetSecondaryInterfaceTile();
    ShadowSceneNode* GetShadowNode();
    char GetStatsPageNumber();
    Tile* GetTarget();
    int GetTargetID();
    TESObjectREFR* GetTargetREFR();
    static float GetThirdInterfaceFloat();
    static float GetTimerPercent(void*);
    int GetTopEnterStackEntry();
    bool HandleMenuInput(Menu*, int, float);
    void HandleMenuMouseEvent(Menu*, int, Tile*);
    void HandleMenuSelection(Menu*, int, Tile*);
    void HandleMenuTileEvent(Menu*, int, Tile*);
    static bool Has360Controller();
    void Idle();
    void Init(bool);
    static void Initialize(unsigned int, bool);
    static InterfaceManager* Instance();
    void InternalSetMenuMode(int);
    bool IsActivatePickFuzzy();
    bool IsAltDown();
    bool IsAnyMenuOpen();
    bool IsControlDown();
    static bool IsCurrentRenderedMenuTopmost();
    bool IsDoneFirstInit();
    bool IsDoneSecondInit();
    static bool IsInterfaceMenuActive();
    bool IsMenuInStack(unsigned int);
    static bool IsPipboyMenuActive();
    bool IsPipboyMenuOpen();
    bool IsSaveLoadActive();
    bool IsShiftDown();
    static void LocalMessgeResults();
    void NeedToUpdate(bool);
    static void NewTimer(void*, float);
    static void PlayUISound(int);
    void PreIdleStuff();
    void ProcessGamepadInput(int);
    void ProcessMenuCulling(BSCullingProcess*, bool);
    bool QLockpickControlsDisable();
    void QueueCloseSupportMenus();
    void RecursiveFade(NiAVObject*, float, float);
    void RefreshGamepadState();
    void RefreshInputState();
    void RefreshInterface();
    void RefreshInterfaceState();
    void RefreshTargetReference();
    static void RegisterListBox(ListBoxBase*);
    void ReleaseMenuTextures();
    void RemoveTileFromUpdateList(Tile*);
    void RestoreMenuVisibility();
    void RenderBlur(BSRenderedTexture*);
    Tile* ScanForMaxFocus(int*, Tile*);
    static void SendGamepadButton(int);
    void SetActivatePickReference(TESObjectREFR*);
    void SetClickMultithreaded(bool);
    static void SetContainerMenuQueued(bool);
    void SetCurrentMainMenu(int);
    void SetCurrentRenderedMenu(FORenderedMenu*);
    static void SetCursorAlpha(int);
    void SetCursorOffsetX(int);
    void SetCursorOffsetY(int);
    void SetCursorPos(float, float);
    void SetDebugTextVisible(bool);
    static void SetDiskError(bool);
    void SetDragDroppingState(int);
    void SetFirstChanceTextureRelease(bool);
    void SetInventoryPageNumber(char);
    void SetLockpickControlsDisable(bool);
    void SetMapPageNumber(char);
    void SetMenuFocusEnabled(bool);
    void SetMouseHeldTime(float);
    void SetNamedMenuOption(char*, bool);
    void SetNamedMenuOption(int);
    void SetPickDistance(int);
    void SetPickedREFR(TESObjectREFR*);
    void SetPipboyPickResults(bool, float, float, int);
    void SetRawCursorX(float);
    void SetRawCursorY(float);
    void SetRepeatingKey(int);
    void SetStatsPageNumber(char);
    void SetStringRoot(Tile*);
    void SetTarget(Tile*);
    void SetTargetID(int);
    void SetTargetREFR(TESObjectREFR*);
    void SetTelekinesisDistance(int);
    void ShowPipboy(int*, int);
    void SwitchControllerModes(bool);
    void Test();
    bool TileIsAcceptingEvents(Tile*);
    void ToggleMouseVisible();
    void ToggleReticle(int);
    void ToggleSafeZone(int);
    void UncullPipboyMenus();
    static void UnregisterListBox(ListBoxBase*);
    void UpdateAllTimers();
    static void UpdateContainerMenu(Tile*, Tile*, Tile*, InventoryStackRecord*, bool);
    static float UpdateInterfaceState();
    void UpdateInventoryPageNumber(char);
    void UpdateMagicPageNumber(char);
    void UpdateMapPageNumber(char);
    void UpdateMenuCulling();
    void UpdatePipboyState();
    void UpdateQueuedMenuClosings();
    void UpdateScreenShape(int, int);
    void UpdateStatsPageNumber(char);
    // Folded helpers used on the singleton: load +0x9c/+0xa0/+0x80, store +0xa0/+0x18.
};
