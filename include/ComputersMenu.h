#pragma once

#include "Menu.h"
#include "ListBox_int_.h"
#include "StrMem.h"
#include "BSSoundHandle.h"

class BGSTerminal;
class BGSNote;
class TextSource;
class TextAnimator;
class TESObjectREFR;

class ComputersMenu : public Menu
{
public:
    class ComputerEntryList : public ListBox_int_
    {
    public:
        bool ContainsKey(Tile*);
        BGSTerminal* FindItemData(Tile*);
        Tile* Insert(BGSTerminal*, int, int, int);
        void Traverse(void (*)(Tile*, TESObjectREFR*), int, int);
        void ListBox_ItemChange_Traverse(void (__cdecl*)(Tile*, void*), int, int);
    };

    ComputersMenu();
    virtual ~ComputersMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleControllerInput(int, Tile*);

    union
    {
        unsigned char layoutExtension[0x40];
        Tile* m_pTiles[16];
        struct
        {
            Tile* tile28;
            Tile* tile2c;
            Tile* tile30;
            Tile* tile34;
            Tile* tile38;
            Tile* tile3c;
            Tile* tile40;
            Tile* tile44;
            Tile* tile48;
            Tile* tile4c;
            Tile* tile50;
            Tile* tile54;
            Tile* tile58;
            Tile* tile5c;
            Tile* tile60;
            Tile* tile64;
        };
    };
    ComputerEntryList entries;
    BSSimpleList<BGSTerminal*> notes;
    unsigned int unka0;
    void* unka4;
    BGSTerminal* terminal;
    TESObjectREFR* reference;
    int unkb0;
    StrMem text;
    union
    {
        const char* m_pText;
        const char* unkbc;
    };
    bool unkc0;
    bool bRefreshed;
    unsigned char unkC2[2];
    BSSoundHandle sounds[3];
    TextAnimator* manager;
    void (*callbackec)();
    void (*callbackf0)();
    void (*callbackf4)();
    int unkf8;

    void CompanionWheelMenu_AttachTileByID(int aiID, Tile* apTile);
    int __thiscall GetMenuId();
    bool __thiscall HasAllTiles(int*);
    bool HandleButtonInput(int, float);
    void UpdateBlink();
    void RefreshDisplay();
    void BuildAnimation();
    void SetTextSource(TextSource*);
    void SetTextSource(int);
    void PlayNoteSound(BGSNote*);
    void DoClick(int, Tile*);
    void DoIdle_00758470();
    void DisplayTerminal(int);
    void DisplayTerminal(bool);
    void DisplayPreviousTerminal();
};
