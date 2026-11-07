#pragma once

#include "Menu.h"

class TESForm;
class MenuTileList;

class RecipeMenu : public Menu
{
public:
    RecipeMenu();
    virtual ~RecipeMenu();
    virtual void AssignTileByID(int tileID, Tile* tile);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);

    unsigned char layoutExtension[0xDC];

    int GetMenuID_00726f00();
    void* FUN_00726f20(unsigned int flags);
    void FUN_00726f50();
    int GetID();
    void OnAction(int action, Tile* tile);
    void PopulateChallengeList(int unused, int type);
    void RecipeMenu_DoEnter(int id, Tile* tile);
    bool HandleMenuButton(int button, float value);
    void RecipeMenu_DoIdle();
    void RecipeMenu_PopulateItemStatsDisplay(TESForm*, Tile*);
    void RecipeMenu_PopulateItemStatsDisplay(TESForm*, MenuTileList*);
    void FUN_00a1d910();
};
