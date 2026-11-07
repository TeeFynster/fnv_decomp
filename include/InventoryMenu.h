#pragma once

#include "Menu.h"
#include "InventoryMenu__sPageState.h"
#include "ListBox_ItemChange___.h"
#include "HotkeyWheelDisplay.h"

class Tile;
class TESBoundObject;
class InventoryStackRecord;
class MenuForm;
class MenuReference;
class MenuEntry;

class MenuFormList
{
public:
    int unk00;
    int unk04;
    MenuForm** FUN_006815c0();
    MenuFormList* FUN_00726070();
};

class __declspec(novtable) MenuList
{
public:
    virtual void slot0();
    virtual void* GetSelected();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void Clear();
    virtual void Sort(int (*)(Tile**, Tile**));

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

    void FUN_007312e0();
    MenuEntry* ListBox_ItemChange_AddItem(InventoryStackRecord*, const char*, int, int);
    void PopulateInventoryList(MenuReference*, void (*)(), int, int, int, int);
    void ListBox_ItemChange_Traverse(void (*)(), int, int);
    void ApplyFilter(void (*)());
    unsigned int ListBox_ItemChange_NumUnfiltered();
    void UpdateCurrentValueTile(int);
    void* CallVirtualZero(int);
};

class InventoryMenu : public Menu
{
public:
    virtual ~InventoryMenu();
    virtual void AssignTileByID(int id, Tile* tile);
    virtual void UpdateDialog();
    virtual int GetClass();

    union
    {
        struct
        {
            Tile* m_pTiles[23];                           // 0x28
            int m_iCurrentTab;                            // 0x84
            InventoryMenu__sPageState m_kPageStates[6];    // 0x88
            ListBox_ItemChange___ m_kItemList;             // 0xB8
            HotkeyWheelDisplay m_kMenuData;                // 0xE8
            BSSimpleList<TESBoundObject*> m_kHotkeyObjects; // 0x11C
        };
        struct
        {
            unsigned char unk28[0x4C];
            MenuReference* container;                    // 0x74
            MenuFormList forms;                          // 0x78
            int mode;                                    // 0x80
            int unk84;
            int unk88;
            int unk8C;
            int unk90;
            int selection;                               // 0x94
            unsigned char unk98[0x30];
            unsigned char unkC8[0x30];
            MenuList* active;                             // 0xF8
        };
    };

    InventoryMenu();
    Tile* FUN_00726070();
    void UpdateButtons();
    void ClearActionPointSource();
    void UpdateItemDisplay(int, Tile*);
    void Click(int, int);
    void Select(int, int);
    void AttachAndDeliver(MenuForm*, void*, MenuList*);
    void ContainerMenu_UpdateLists(MenuForm*);
    bool DoGamepad(int input, int unused);
    bool IsWellFormedMenu_0077ff90();
    void Menu_SetRenderedMenu();

    static Tile* Create();
    static int GetClassStatic();
    static void UpdateItemList();
    static int ms_iValueTileID;
    static int ms_iItemTypeTileID;
    static int ms_iCurrentTabTileID;
    static int ms_iKeyringOpenTileID;
    static int ms_iEquippableItemTileID;
    static InventoryMenu* ms_pInventoryMenu;
    static InventoryStackRecord* ms_pActionPointSource;
};

// These views share storage without adding constructor or destructor calls.
#define m_kList (*reinterpret_cast<MenuList*>(unk98))
#define otherList (*reinterpret_cast<MenuList*>(unkC8))
