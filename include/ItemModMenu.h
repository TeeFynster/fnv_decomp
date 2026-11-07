#pragma once

#include "Menu.h"
#include "ListBox_ItemChange___.h"

class Tile;
class EqEntry;

class ItemModMenu : public Menu
{
public:
    Tile* m_pTiles[14];
    ListBox_ItemChange___ m_kItemList;

    ItemModMenu();
    Tile* __cdecl Create();
    virtual ~ItemModMenu();
    virtual void HandleSelection(int, Tile*) override;
    virtual int GetClass() override;
    virtual bool HandleMenuInput(int, float) override;

    void* DestroyIfFlagged(unsigned int);
    void UpdateItemModTile(int, Tile*);
    bool ItemModItem(EqEntry*);
    void DoEnter(int, int);
};
