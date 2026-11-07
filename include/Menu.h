#pragma once

#include "MagicTarget.h"

class Tile;
class TileMenu;
class Tile__TileTemplate;
class NiPoint3;
class Target;
class Arg;
class Screen;


#include "Interface.h"

class Menu
{
public:
    virtual ~Menu();
    virtual void AssignTileByID(int, Tile*);
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

    TileMenu* pMenu;
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;
    Tile* m_pMenuTile;
    int m_iModalMenuId;
    int m_iSecondaryValue;
    bool m_bIsSpecial;
    bool m_bVisible;
    unsigned char layoutPadding1E[2];
    int m_iMenuId;
    Interface::FADE_STATE m_eFadeState;

    Menu();
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
    void LoadMenuData();
    void UnloadMenuData();
    void ParseMenuXML(const char*);
    void SetModal(int id) { m_iModalMenuId = id; }
    Tile* CreateTileFromTemplate(Tile*, const char*, Tile*);
    Tile* GetTile();
    unsigned int GetVisibilityState();
    void SetCurrentPageFromChar(unsigned char);
    void UpdateCardSlots(int, int);
    void UpdateControls();
    void InitMenu();
    void ClearActionPointSource();
    void UpdateItemDisplay(int, Tile*);
    bool IsUnk28Set();
    bool UpdateScreenEffect();
    NiPoint3 GetMarkerPosition(NiPoint3, void*);
    void UpdateMapMarkers();
    void UpdateQuestMarker();
    bool UpdateProgress(float, int);
    void HandleOptionSelection();
    void HandlePendingTileAction();
    void UpdateZoomAndScroll();
    void UpdateClockText();
    void AccumulateTileHeight(Target*);

    Tile* FUN_00726070();
    bool ItemModMenu_IsWellFormedMenu();
    void UpdateButtons();
    void MapMenu_AddQuestMarkers();
    void MapMenu_DeletePlayerMarker();
    void FUN_0079dbb0();
    void DoEffect(Arg*, void*, int);
    Screen* Tile_GetMenu();
    void FUN_00700320(int, int);
    bool FORenderedMenuRaceSex_OnIdle();
    void Menu_SetRenderedMenu();
    void RefreshPage();
    void RaceSexMenu_SetFlag(int, bool);
    bool RaceSexMenu_IsFlagged(int);
    bool RaceSexMenu_RotatePlayer(float, int);
    void UpdateScrollTraits_007a7700();
    void UpdateHighlightTraits_007a73e0();
    void ProcessEntries_007a7260();
    void FUN_00a1dc70(TileMenu*, bool);
    void FUN_00a1dc20(bool);
    void InstantFadeOut();

    static const char* GetMenuPath(const char*);
    static float GetMenuScale();
    static void SetMenuRootTile(int, Tile*);
    static void SetVisible(int, bool);
    static bool IsMenuVisible(Interface::enumMenus);
    static bool ReadMenuDefinition(const char*, Menu*);
};
