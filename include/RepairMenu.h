#pragma once

#include "Menu.h"
#include "ListBox_ItemChange___.h"

class RepairTile;

class RepairMenu : public Menu
{
public:
    Tile* m_pTiles[13];
    ListBox_ItemChange___ m_kItemList;

    __declspec(property(get=GetRepairList)) ListBox_ItemChange___& m_kRepairList;
    ListBox_ItemChange___& GetRepairList() { return m_kItemList; }

    RepairMenu();
    virtual ~RepairMenu();
    virtual void AssignTileByID(int tileID, Tile* tile);
    virtual int GetClass();

    void UpdateRepairList();
    bool IsWellFormedMenu_007b5730();
    void ApplyRepair(void*);
    void RefreshRepairMenu();
    void HandleRepairAction(int id, RepairTile* tile);
    void SetRepairMenuText(const char* text);

    static Tile* Create();
};

