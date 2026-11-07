#pragma once

#include "Menu.h"
#include "BSSoundHandle.h"
#include "HotkeyWheelDisplay.h"
#include "GameTimerRecord.h"
#include "ShadowSceneLight.h"

class Actor;
class Tile;
class TESObjectREFR;
class NiControllerSequence;
class RegionObjectEntry;
class HUDMainMenu__MessageData;
class HUDMainMenu__SubtitleData;
class HUDMainMenu__QuestObjective;
class HUDMainMenu__XPUpdate;
class HUDMainMenu__RadiationUpdate;


class HUDMainMenu : public Menu
{
public:
    enum HUD_MENU_MODE
    {
        HMM_NONE = 0,
        HMM_CHANGED = 1,
        HMM_RUN_AND_GUN = 2,
        HMM_PIPBOY = 3,
        HMM_START = 4,
        HMM_LOAD = 5,
        HMM_DIALOGUE = 6,
        HMM_VATS = 7,
        HMM_VATS_PLAYBACK = 8,
        HMM_CONTAINER = 9,
        HMM_SIT_SLEEP_ANIM = 10,
        HMM_SIT_SLEEP = 11,
        HMM_MOVEMENT_DISABLED = 12,
        HMM_PIPBOY_DISABLED = 13,
        HMM_CHARGEN_MENU = 14,
        HMM_HACKING = 15,
        HMM_TERMINAL = 16,
        HMM_MESSAGE_MENU = 17,
        HMM_SPECIAL_BOOK = 18,
        HMM_LOVE_TESTER = 19,
        HMM_VANITY = 20,
        HMM_AUTO_VANITY = 21,
        HMM_IRON_SIGHTS = 22,
        HMM_SNIPER_RIFLE = 23,
        HMM_MOVIE = 24,
        HMM_CASINO_GAME = 25,
    };

    HUDMainMenu();
    virtual ~HUDMainMenu();
    virtual void AssignTileByID(int aTileID, Tile* apTile);
    virtual int GetClass();

    Tile* m_pTiles[87];
    Tile* m_pAdditionalHudTile;
    float m_fMessageDisplayTimer;
    BSSimpleList<HUDMainMenu__MessageData*> m_kMessageList;
    unsigned int m_uiMessageCount;
    BSSimpleArray<HUDMainMenu__SubtitleData*, 1024> m_kSubtitleArray;
    HUDMainMenu__SubtitleData* m_pCurrentSubtitle;
    BSSoundHandle m_kTargetDisplayData;
    TESObjectREFR* m_pCrosshairReference;
    int m_iHudValueFirstBeforeMode;
    int m_iHudValueSecondBeforeMode;
    HUD_MENU_MODE m_eHudMenuMode;
    HotkeyWheelDisplay m_kMenuData;
    bool m_bHudModeActive;
    unsigned char layoutPadding1FD[3];
    NiControllerSequence* m_pHudAnimationSequence;
    bool m_bSequenceActive;
    bool m_bHudAnimationActive;
    unsigned char layoutPadding206[2];
    unsigned int m_uiHudAnimationCounter;
    BSSimpleList<RegionObjectEntry*>* m_pRegionObjectListObj;
    int m_iHudValueFirstAfterUpdateList;
    int m_iHudValueSecondAfterUpdateList;
    int m_iHudValueThirdAfterUpdateList;
    Actor* m_pTargetActor;
    bool m_bTargetActorVisible;
    unsigned char layoutPadding221[3];
    GameTimerRecord m_cBuffer;
    unsigned int m_uiHudValueFirstAfterActor;
    unsigned int m_uiHudValueSecondAfterActor;
    int m_iHudValueFirstAfterUnsignedValues;
    int m_iHudValueSecondAfterUnsignedValues;
    bool m_bQuestObjectiveUpdatesEnabled;
    unsigned char layoutPadding255[3];
    BSSimpleList<HUDMainMenu__QuestObjective*> m_kQuestObjectives;
    bool m_bQuestObjectiveUpdatePending;
    bool m_bXPUpdatePending;
    unsigned char layoutPadding262[2];
    BSSimpleList<HUDMainMenu__XPUpdate*> m_kXPUpdates;
    BSSimpleList<HUDMainMenu__RadiationUpdate*> m_kRadiationUpdates;
    float m_fRadiationUpdateTimer;

    void HUDMainMenu_KillQuestUpdates();

    static HUDMainMenu* g_pHudMainMenuInstance;
    static void SetCrosshairTarget(TESObjectREFR*, bool);
    static void SetHUDVisible(bool);
    static bool UpdateTargetReference(TESObjectREFR*, bool, bool);
    bool RefreshTargetDisplay();
    static void UpdateTargetActor(Actor* actor);
    static void UpdateVisibilityState(int state);
};
