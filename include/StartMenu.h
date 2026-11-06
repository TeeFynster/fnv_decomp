#pragma once

#include "Menu.h"
#include "GO.h"
#include "ListBoxBase.h"
#include "ListBox.h"
#include "NiPoint2.h"
#include "NiPoint3.h"
#include "BSSoundHandle.h"
template <class T, unsigned int N> class BSSimpleArray;
typedef BSSimpleArray<void*, 1024> StartMenuArraySupport;
__if_not_exists(StartMenuArraySupport::m_data)
{
    __if_not_exists(StartMenuArraySupport::pBuffer)
    {
        __if_not_exists(StartMenuArraySupport::data)
        {
#include "BSSimpleArray.h"
        }
    }
}

template <class T, unsigned int Growth> class ShadowLightSimpleArray;
template <class T, unsigned int Growth> class ShadowLightArray;

class BGSSaveLoadFileEntry;
class Tile;
class TileMenu;

template <class T> class ListBoxItem;

class StartMenu : public Menu
{
public:
    

    class Option
    {
    public:
        virtual ~Option();
        bool IsForModes(unsigned int auiModes);

        const char* GetValueText;
        void (__cdecl* m_pActionCallback)();
        unsigned int m_uiModes;
    };

    class UserOption : public Option
    {
    public:
        const char* pTemplate;
        int iVal;
        int iDefaultValue;
        int eType;
        unsigned int m_uiValueCount;
        unsigned int m_uiModeFlags;
        const char** m_ppOptionValues;
        void (__cdecl* m_pChangeCallback)(UserOption*);
    };

    class OptionManager
    {
    public:
        unsigned int m_uiFirstValue;
        unsigned int m_uiSecondValue;

        OptionManager();
        static OptionManager* Instance();
    };

    class OptionListBox : public ListBox<Option*>
    {
    public:
        virtual Tile* GetTileForButton(int aeButton);
    };

    enum Flag
    {
        kFlag1 = 0,
        FLAG_1 = 0x1,
        FLAG_INGAME = 0x1,
        FLAG_OPTIONS_DIRTY = 0x2,
        FLAG_FORCE_RELOAD = 0x4,
        FLAG_SAVE_MODE = 0x8,
        FLAG_FADE_IN = 0x10,
        FLAG_SAVE_OPTIONS = 0x20,
        FLAG_RESET_HUD_OPACITY = 0x40,
        FLAG_DLC_NEEDS_UPDATE = 0x80,
        FLAG_NEW_DLC_INSTALLED = 0x100,
        FLAG_SEARCHING_DLC = 0x200,
        FLAG_DLC_WAIT_MESSAGE = 0x400,
        FLAG_SYSUTILSAVECOMPLETE = 0x800,
        FLAG_ACTION_MAPPING = 0x1000,
        FLAG_DELETE_MODE = 0x2000,
        FLAG_SAVE_WAIT_MESSAGE = 0x4000,
        FLAG_SAVE_WAIT_SAVING = 0x8000,
        FLAG_SHOWING_CREDITS = 0x10000,
        FLAG_DONT_FORCE_BACK = 0x20000,
        FLAG_SAVELOAD_BACKOUT = 0x40000,
        FLAG_IIS_PREFADE = 0x80000,
        FLAG_LOADING_SAVEGAMES = 0x100000,
        FLAG_LIVE_MENU = 0x200000,
        FLAG_RESTART_REQUIRED = 0x400000,
        FLAG_MOUNT_DLC = 0x800000,
        FLAG_DLC_CORRUPT_MESSAGE = 0x1000000,
        FLAG_USER_PRESSED_START = 0x2000000,
        FLAG_USER_IS_ACTION_MAPPING = 0x4000000,
        FLAG_MEM_CARD_REMOVED = 0x8000000,
        FLAG_SAVE_SAVING = 0x10000000,
        FLAG_MISSING_CONTENT = 0x20000000
    };

    virtual ~StartMenu();
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

    Tile* m_pTiles[23];
    OptionListBox m_kFirstOptionListBox;
    OptionListBox m_kSecondOptionListBox;
    OptionListBox m_kThirdOptionListBox;
    OptionListBox m_kDownloadOptions;
    ListBox<int> m_kOptionIndexList;
    ListBox<BGSSaveLoadFileEntry*> m_kOptionHelper;
    UserOption* m_pUserOption;
    unsigned int uiFlags;
    float m_fMenuTimer;
    int unk1b0;
    int unk1b4;
    GO unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    void* unk1d0;

    StartMenu();
    TileMenu* GetMenuTitle();
    const char* GetMenuTitle() const;
    void HandleSliderTileInput(int aiID, void* apTile);
    void UpdateMouseover(int aiID, void* apTarget);
    bool IsStartMenuActive();
    bool IsFlagSet(Flag aFlag);
    bool IsFlagSet(int f);

    static bool IsInGame();
    static bool __cdecl Create(bool, bool);
    static void UpdateMedia();
};
