#pragma once

#include "Menu.h"

class TraitSelectMenu : public Menu
{
public:
    TraitSelectMenu();
    virtual ~TraitSelectMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);

    void __thiscall HandleTraitSelection(int, int);
    void __thiscall ClearTraitSelection();
    int __thiscall FUN_007e7ac0();
    void __thiscall FUN_007e7b30();
    bool __thiscall FUN_007e7da0();
    void __thiscall SetTileByID(int, Tile*);
    void __thiscall FUN_007e7e30(int, Tile*);
    void __thiscall FUN_007e8280(int, Tile*);
    void __thiscall FUN_007e82b0(int, int);
    void __thiscall FUN_007e8310(float);
    void __thiscall FUN_007e8470(int, bool);
    void __thiscall FUN_007e8840();
    void __thiscall FUN_007e8860(int);
    void SelectTrait(int, int);
    void SelectTrait(int, bool);
    bool HandleKeyInput(int, int);
    void ChangePage(bool);
    void SetPage(unsigned int, bool);
    bool Init();
    void Select(int, int);
    void UpdateScrollAnimation();

    union
    {
        unsigned char layoutExtension[0x60];
        struct
        {
            union
            {
                Tile* m_pTiles[18];
                struct
                {
                    Tile* unk28[13];
                    Tile* scrollTile;
                    void* m_pvTile;
                    int unk64;
                    int unk68;
                    union
                    {
                        Tile* pCheckTile;
                        Tile* selectedTile;
                    };
                };
            };
            union
            {
                float currentPosition;
                float scrollX;
                int unk70;
            };
            union
            {
                float targetPosition;
                float scrollY;
                float m_fRatio;
                int unk74;
            };
            union
            {
                int m_iSelectedTrait;
                int m_iSelected;
                unsigned int m_uiPage;
                int unk78;
            };
            union
            {
                int iCurrentID;
                int currentID;
                int unk7C;
            };
            union
            {
                unsigned int uiLastTick;
                unsigned int selectionTick;
                int unk80;
            };
            union
            {
                unsigned int lastTick;
                unsigned int updateTick;
            };
        };
    };
};
