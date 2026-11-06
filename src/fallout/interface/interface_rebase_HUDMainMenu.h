// Source layout: HUDMainMenu. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_HUDMAINMENU_H
#define FNV_INTERFACE_REBASE_FNV_HUDMAINMENU_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_BSSoundHandle.h"
#include "interface_rebase_BSTimer.h"
#include "interface_rebase_HotKeysWheel.h"
#include "interface_rebase_Menu.h"
class HUDMainMenu : public Menu
{
  public:
    static void SetCrosshairTarget(TESObjectREFR*, bool);
    static void SetHUDVisible(bool);
    Tile* m_pTiles[87];                                                // +0x28
    Tile* m_pAdditionalHudTile;                                        // +0x184
    float m_fMessageDisplayTimer;                                      // +0x188
    BSSimpleList<HUDMainMenu__MessageData*> m_kMessageList;            // +0x18C
    unsigned int m_uiMessageCount;                                     // +0x194
    BSSimpleArray<HUDMainMenu__SubtitleData*, 1024> m_kSubtitleArray;  // +0x198
    HUDMainMenu__SubtitleData* m_pCurrentSubtitle;                     // +0x1A8
    BSSoundHandle m_kTargetDisplayData;                                // +0x1AC
    TESObjectREFR* m_pCrosshairReference;                              // +0x1B8
    int m_iHudValueFirstBeforeMode;                                    // +0x1BC
    int m_iHudValueSecondBeforeMode;                                   // +0x1C0
    HUDMainMenu__HUD_MENU_MODE m_eHudMenuMode;                         // +0x1C4
    HotkeyWheelDisplay m_kMenuData;                                          // +0x1C8
    bool m_bHudModeActive;                                             // +0x1FC
    unsigned char layoutPadding1FD[3];
    NiControllerSequence* m_pHudAnimationSequence;  // +0x200
    bool m_bSequenceActive;                         // +0x204
    bool m_bHudAnimationActive;                     // +0x205
    unsigned char layoutPadding206[2];
    unsigned int m_uiHudAnimationCounter;       // +0x208
    BSSimpleList<RegionObjectEntry*>* m_pRegionObjectListObj;  // +0x20C
    int m_iHudValueFirstAfterUpdateList;        // +0x210
    int m_iHudValueSecondAfterUpdateList;       // +0x214
    int m_iHudValueThirdAfterUpdateList;        // +0x218
    Actor* m_pTargetActor;                      // +0x21C
    bool m_bTargetActorVisible;                 // +0x220
    unsigned char layoutPadding221[3];
    GameTimerRecord m_cBuffer;                          // +0x224
    unsigned int m_uiHudValueFirstAfterActor;   // +0x244
    unsigned int m_uiHudValueSecondAfterActor;  // +0x248
    int m_iHudValueFirstAfterUnsignedValues;    // +0x24C
    int m_iHudValueSecondAfterUnsignedValues;   // +0x250
    bool m_bQuestObjectiveUpdatesEnabled;       // +0x254
    unsigned char layoutPadding255[3];
    BSSimpleList<HUDMainMenu__QuestObjective*> m_kQuestObjectives;  // +0x258
    bool m_bQuestObjectiveUpdatePending;                            // +0x260
    bool m_bXPUpdatePending;                                        // +0x261
    unsigned char layoutPadding262[2];
    BSSimpleList<HUDMainMenu__XPUpdate*> m_kXPUpdates;                // +0x264
    BSSimpleList<HUDMainMenu__RadiationUpdate*> m_kRadiationUpdates;  // +0x26C
    float m_fRadiationUpdateTimer;                                    // +0x274
    int GetClass();
};
FNV_STATIC_ASSERT(sizeof(HUDMainMenu) == 0x278);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_pAdditionalHudTile) == 0x184);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_fMessageDisplayTimer) == 0x188);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_kMessageList) == 0x18C);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_uiMessageCount) == 0x194);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_kSubtitleArray) == 0x198);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_pCurrentSubtitle) == 0x1A8);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_kTargetDisplayData) == 0x1AC);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_pCrosshairReference) == 0x1B8);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_iHudValueFirstBeforeMode) == 0x1BC);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_iHudValueSecondBeforeMode) == 0x1C0);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_eHudMenuMode) == 0x1C4);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_kMenuData) == 0x1C8);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_bHudModeActive) == 0x1FC);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_pHudAnimationSequence) == 0x200);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_bSequenceActive) == 0x204);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_bHudAnimationActive) == 0x205);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_uiHudAnimationCounter) == 0x208);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_pRegionObjectListObj) == 0x20C);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_iHudValueFirstAfterUpdateList) == 0x210);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_iHudValueSecondAfterUpdateList) == 0x214);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_iHudValueThirdAfterUpdateList) == 0x218);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_pTargetActor) == 0x21C);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_bTargetActorVisible) == 0x220);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_cBuffer) == 0x224);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_uiHudValueFirstAfterActor) == 0x244);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_uiHudValueSecondAfterActor) == 0x248);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_iHudValueFirstAfterUnsignedValues) == 0x24C);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_iHudValueSecondAfterUnsignedValues) == 0x250);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_bQuestObjectiveUpdatesEnabled) == 0x254);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_kQuestObjectives) == 0x258);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_bQuestObjectiveUpdatePending) == 0x260);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_bXPUpdatePending) == 0x261);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_kXPUpdates) == 0x264);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_kRadiationUpdates) == 0x26C);
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_fRadiationUpdateTimer) == 0x274);
#endif
