#pragma once

#include <windows.h>
#include "Menu.h"
#include "NiAVObject.h"
#include "NiTPointerList_Tile___.h"
#include "TESFullName.h"
#include "NiColorA.h"
#include "BSSoundHandle.h"

class BGSLoadGameBuffer;
class BGSPerkEntry;
class NiNode;
struct LoadingTileSettings;
struct LoadingTileSettingsX;
struct LoadingStatsSettings;
struct Options;
struct ScreenArray;
struct ScreenEntry;
class TESForm;
class TESLoadScreen;
class TileShaderProperty;
class NiTexture;
template <class T, unsigned int Growth> class BSSimpleArray;

enum MiscStatManager__MiscStatID;
enum FONTS;

class TileLayout
{
public:
    int m_iXPosition;
    int m_iYPosition;
    int nHeight;
    int nWidth;
    FONTS m_eFont;
    unsigned char m_ucFontStyle;
    unsigned char layoutPadding15[3];
};

class LoadingMenu : public Menu
{
public:
    class TileList : public NiTPointerList_Tile___
    {
    public:
        ~TileList();
    };

    class LoadingScreenTip : public BSStringT<char>
    {
    public:
        ~LoadingScreenTip();
    };

    enum TileIndex  // values: Xbox PDB LoadingMenu::TileIndex
    {
        eBackground = 0,
        ePlateNumber = 1,
        ePlateText = 2,
        eCurrentObjective = 3,
        eRandomStat1Label = 4,
        eRandomStat1Val = 5,
        eRandomStat2Label = 6,
        eRandomStat2Val = 7,
        eRandomStat3Label = 8,
        eRandomStat3Val = 9,
        eLevelProgress = 10,
        ePinwheel = 11,
        eWorldImage = 12,
        ePlateLabel = 13,
        eCurrentObjectiveLabel = 14,
        eLevelProgressLabel = 15,
        eLevelProgressParentRect = 16,
        eRandomStatLabelRect = 17,
        eRandomStatValRect = 18,
        eRandomStat4Label = 19,
        eRandomStat4Val = 20,
        eRandomStat5Label = 21,
        eRandomStat5Val = 22,
        eRandomStat6Label = 23,
        eRandomStat6Val = 24,
        eRandomStat7Label = 25,
        eRandomStat7Val = 26,
        eCurrentObjectiveRect = 27,
        eLevelProgressCurrentLevel = 28,
        eLevelProgressNextLevel = 29,
        eLevelProgressCharMarker = 30,
        eRandomStatRect = 31,
        eTileSlide01 = 32,
        eTileSlide02 = 33,
        eTipText01 = 34,
        eTipText02 = 35,
        eTipMatte_Slide01 = 36,
        eTipMatte_Slide02 = 37,
        NUM_TILES = 38
    };

    LoadingMenu();
    virtual ~LoadingMenu();
    virtual void AssignTileByID(int uiIndex, Tile* pTile);
    virtual int GetClass();

    Tile* m_pTiles[38];
    tagRECT m_kTileRectangle;
    TileList m_kFirstTileList;
    TileList m_kSecondTileList;
    TileList m_kThirdTileList;
    TileList m_kFourthTileList;
    TileList m_kFifthTileList;
    MiscStatManager__MiscStatID m_aeMiscStatIdentifiers[43];
    LoadingScreenTip m_kLoadingScreenTip;
    NiColorA m_kLoadingScreenColor;
    BSSimpleList<TESLoadScreen*> m_kLoadScreenItems;
    BSSimpleList<TESLoadScreen*>* m_pkLoadScreenList;
    TESLoadScreen* m_pCurrentLoadScreen;
    unsigned int m_uiLoadScreenIndex;
    unsigned int LoadScreenData;
    TESForm* pLocation;
    TileShaderProperty* TileShaderState;
    TileShaderProperty* m_pAlternateTileShaderState;
    BSSoundHandle m_kFirstDate;
    BSSoundHandle m_kSecondDate;
    NiPointer<NiTexture> m_kLoadScreenTextures[4];
    unsigned int m_uiLoadingScreenNumber;
    unsigned short m_usAdditionalFlags;
    unsigned short usFlags;
    TileLayout m_kTileLayouts[38];
    unsigned int m_uiFirstStateValue;
    unsigned int m_uiSecondStateValue;
    int m_iStateFlags;

    void InitLoadingMenu(TESForm*);
    void SetTileVisible(TileIndex, bool);
    void SetTileVisible(int, bool);
    void SetTileAlpha(Tile*, float);
    void SetTileAlpha(void*, float);
    void SetAlphaRecursive(NiNode*, float);
    void ToggleFlagBit(int);
    void UpdateLoadingScreenText(bool);
    void UpdateLoadingScreenText(int);
    void UpdateLoadingScreens();
    bool UpdateLoadingScreen();
    void ApplyLoadingScreenTexture(bool);
    void ApplyLoadingScreenTexture(int);
    void ApplyLoadingScreenTexture(void*);
    void ApplyLoadingScreenTexture(TileShaderProperty*);
    void CopyTileLayout();
    void ApplySettings(int);
    void ApplySettings(LoadingStatsSettings*);
    void ApplySettingsToTiles(int);
    void ApplySettingsToTiles(LoadingTileSettings*);
    void ApplyXPBarSettings(int);
    void ApplyXPBarSettings(LoadingTileSettingsX*);
    void UpdateMenuTiles(int);
    void UpdateMenuTiles(Options*);
    void UpdateLoadingScreenTip();
    bool IsLoadScreenValid(TESLoadScreen*);
    void RefreshLoadingScreen();
    bool GetFloat(int);
    void SelectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>&);
    void CollectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>&);
    void Update();
    void UpdateLoadScreen(TESLoadScreen*, float, int);
    void UpdateStatsTilesAlphas(float, int);
    void UpdateTiles(float, int);
    void FadeSlideTiles(float, int);
    void UpdateLoadingTiles(float, int);
    void SetFloatFlag(int, bool);

    bool FUN_00458110(int);
    void FUN_00458080(int, bool);
    void FUN_00458080(int, int);
    void FUN_00458080(TileIndex, bool);
    void Reset_00788ab0(int);
    void Reset_00788ab0(TESForm*);
    void InitStatsTilesList();
    void LoadingMenu_InitObjectiveTilesList();
    void InitXPProgressTilesList();
    void InitTipTilesList();
    void Update_00789820();
    void ResetLoadingPinwheelAnimation();
    void LoadingMenu_FlushLoadScreenList();
    void LoadingMenu_AdvanceScreen();
    void FUN_0078abd0();
    void FUN_0078aec0();
    void ShowPlayerTiles(bool);
    void UpdatePlayerTileVisibilities(TESLoadScreen*, bool);
    void UpdateStatsTilesVisibilities(bool);
    void UpdateObjectiveTilesVisibilities(bool);
    void UpdateTipTilesVisibilities(bool);
    void UpdateXPProgressTilesVisibilities(bool);
    void CalcLoadScreenTypeTextWindowVerts(void*);
    void CalcLoadScreenTypeTextWindowVerts(int);
    void InitPlayerTileSettings();
    void UpdatePlayerTileSettings(int);
    void UpdatePlayerTileSettings(BGSPerkEntry*);
    void FadeIn();

    void Clear();
    void SetFlag(int, bool);
    void Gather(ScreenArray&);
    void Build(ScreenArray&);
    void Refresh();
    void Reset();
    void Select(ScreenEntry*, bool);

    static void HideTile();
    static void __cdecl UpdateLoadingScreenThread();
    static void SetLoadingScreenVisible(int);
    static void UpdateLoadingMenuState();
    static void LoadGame(BGSLoadGameBuffer*);
    static Tile* Create(TESForm*, bool, bool);
};
