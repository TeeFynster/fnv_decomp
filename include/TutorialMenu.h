#pragma once

#include "Menu.h"

class BGSMessage;
class HelpListNode;

class TutorialMenu : public Menu
{
public:
    TutorialMenu();                  // 0x0071f240 (installs vftable 0x0106ff84; 0x54 bytes)
    virtual ~TutorialMenu();
    virtual void AssignTileByID(int aiID, Tile* apTile);
    virtual void HandleSelection(int aiID, Tile* apTile);
    virtual int GetClass();
    virtual bool HandleMenuInput(int aiButton, float afValue);
    virtual bool HandleControllerInput(int aiButton, Tile* apTile);

    Tile* m_pTiles[8];
    unsigned int uiCurrentPage;
    unsigned int uiPageCount;
    HelpListNode* pPages;

    void SetTile(int aiID, Tile* apTile);
    void* DestroyTutorialMenu(unsigned int flags);
    void DestroyMenu();
    bool DoGamepad_007e8e60(int aiButton, float afValue);
    bool HandleGamepadButton(int aiButton, float afValue);
    void DoClick_007e8db0(int aiID, Tile* apTarget);
    void ProcessAndTransformResult_007e8e20();
    void DecrementAndDispatch();
    void ShowPageByIndex(int aiPage);
    void ShowPageByIndex(unsigned int auiPage);
    void ShowPage(BGSMessage* apPage);
    void Refresh();
    void ApplyRecordToTiles(BGSMessage* record);
    void ApplyRecordToTiles(void* apTile);
    void UpdatePrevNext();

    static void Create(unsigned int, unsigned int);
};

