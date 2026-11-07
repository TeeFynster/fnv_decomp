#pragma once

#include "Menu.h"

class BookInput;
class BookTile;

class BookMenu : public Menu
{
public:
    BookMenu();
    virtual ~BookMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual bool HandleKeyboardInput(unsigned int);
    virtual int GetClass();

    union
    {
        unsigned char layoutExtension[0x14];
        struct
        {
            Tile* m_pHighlightedTile;
            Tile* m_pObject;
            int unk30;
            int unk34;
            int unk38;
        };
    };

    int GetID();
    bool HasAllFlagsSet(int*);
    void InitMenu();
    void* CreateSurgery3DCamera();
    void InvokeCallbacksForSlot();
    void HandleKey(unsigned int key, int unused);
    void SetTileByID(int aiID, Tile* apTile);
    void UpdateMenuTile();
    bool HandleKey(int aikey);
    void ReadBook();
    void HandleScrollInput(int a1, int a2);
    void HandleMessage(int msg, int unused);
    void UpdateBookMenu(BookInput* input, int value);
    void LoadBookFile();

    void FUN_00a1dc70(BookTile*, bool);
    void FUN_00a1dc20(bool);
    void* FUN_00726070();
    int GetClass_0073acf0();
    void* FUN_0073ad00(unsigned int flags);
    void SetVtableAndProcessState_0073ad30();
    bool IsWellFormedMenu();
    void DoDownClick(int aiID, Tile* apTarget);
    void DoStillDown(int aiID, Tile* apTarget);
    void FUN_00a1c520();
    int GetCurrentStatesActorValue();
    bool TurnPage(bool);
};
