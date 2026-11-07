#pragma once

#include "Menu.h"
#include "NiPoint2.h"
#include "NiPoint3.h"
#include "BSSoundHandle.h"

class BGSNote;
class BGSQuestObjective;
class MapPoint3;
class PathingPath;
class RegionObjectEntry;
class TESChallenge;
class TESForm;
class TESObjectCELL;
class TESObjectREFR;
class TESQuest;
class TESWorldSpace;
class Tile;
class TileMenu;

template <class T> class BSStringT;

template <class T, unsigned int N = 1024>
class MapArray
{
public:
    MapArray();
    ~MapArray();
    T* data;
    unsigned int size;
    unsigned int capacity;
    unsigned int grow;
    void Clear(bool);
    void Add(const T&);
};

#include "ListBox.h"

class MapSoundList : public BSSimpleList<BSSoundHandle>
{
public:
    MapSoundList();
    ~MapSoundList();
};

class MapMenu : public Menu
{
public:
    virtual ~MapMenu();
    virtual void AssignTileByID(int index, Tile* tile);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void PostDragTileChange(unsigned int, Tile*, Tile*);
    virtual void PreDragTileChange(unsigned int, Tile*, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void OnClickHeld(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);
    virtual void OnUpdateUserTrait(int);
    virtual void HandleControllerConnectOrDisconnect(bool);

    Tile* m_pTiles[22];
    int m_iMapDisplayMode;
    Tile* m_pMapTile;
    float m_fMapRotation;
    bool m_bMapMenuActive;
    char pad8d[3];
    BGSNote* m_pSelectedNote;
    unsigned int m_uiMapState;
    MapSoundList m_kSoundList;
    MapArray<BSStringT<char> > SubtitlesToShow;
    BSSimpleList<BSSoundHandle>* m_pkActiveSoundList;
    bool m_bMapListUpdatePending;
    char padbd[3];
    float m_fMapZoom;
    int m_iMapSelectionIndex;
    float m_fSavedMusicVolume;
    TESQuest* m_pSelectedQuest;
    RegionObjectEntry* m_pSelectedMapMarkerInfo;
    Tile* m_pSelectedMarkerTile;
    BSSimpleList<TESObjectREFR*> m_kMapMarkerList, LocalMapMarkerList;
    NiPoint2 m_kMapMinimumPoint, m_kMapMaximumPoint;
    TESForm* m_pCurrentMapSpace;
    NiPoint3 m_kPlayerWorldPosition;
    TESForm* m_pCurrentMapForm;
    TESWorldSpace* m_pCurrentWorldspace;
    bool m_bLocalMapMode;
    char pad111[3];
    TESObjectREFR* m_pFirstMapReference;
    TESObjectREFR* m_pSecondMapReference;
    TESObjectCELL* pAdjustNorthRotationCell;
    NiPoint2 m_kMapOffset;
    unsigned int m_uiMapMarkerCount;
    bool m_bNeedsMapUpdate;
    char pad12d[3];
    ListBox<TESQuest*> m_kQuestListBox;
    ListBox<BGSNote*> m_kNoteListBox;
    ListBox<TESObjectREFR*> m_kMapMarkerListBox;
    ListBox<BGSQuestObjective*> m_kObjectiveListBox;
    ListBox<TESChallenge*> m_kChallengeListBox;
    MapArray<Tile*> m_kMapMarkerTiles;

    void UpdateLocalMap();
    void RefreshMap();
    void UpdateQuestObjectiveList();
    void RefreshNotesList();
    void RefreshChallengeList();
    void SetNote(BGSNote* note);
    void RefreshRadioList();
    void SetCurrentPage(unsigned char);
    void SetCurrentPage(int);
    void FUN_007069f0(unsigned char);
    void UpdateCurrentPage();
    void ToggleNotesChallengeMode(bool);
    void ResetWaveform();
    static void MapMenu_SetKnobPosition(bool);
    TESWorldSpace* CalculatePlayerMarkerSpace(NiPoint3);
    TESWorldSpace* CalculatePlayerMarkerSpace(MapPoint3);
    void Menu_SetRenderedMenu();
    void RefreshMapMenu(bool selected);
    MapMenu();
    static Tile* Create();
    static void MenuDepthController();
    static void StopMapMenuSounds();
    static void SetMapPositionToPlayer();
    static void UpdateMapPosition();
    static void OpenMap();
    void UpdateSelectedQuestMarkers();
    void SelectNote(BGSNote*);
    void RefreshMapData();
    void SetMapDisplayMode(bool);
    NiPoint3 WorldToMapPosition(NiPoint3, TESWorldSpace*);
    NiPoint3 MapToWorldPosition(NiPoint3, TESWorldSpace*);
    MapPoint3 WorldToMapPosition(MapPoint3, TESWorldSpace*);
    MapPoint3 MapToWorldPosition(MapPoint3, TESWorldSpace*);
    TESObjectREFR* GetTeleportDestination(TESObjectREFR*, PathingPath*);
    void RefreshMapMarkers();
    void UpdateMapObjectives();
    void UpdateMapHighlight();
    void UpdatePlayerMapMarker();
    void SetFlag8000();
    bool HasNoZeroEntries();
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
};
