#pragma once

#include "Menu.h"
#include "ListBox_enum_ActorValue__Index_.h"

class CharGenMenu : public Menu
{
public:
    virtual ~CharGenMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);

    union
    {
        unsigned char layoutExtension[0x30];
        struct
        {
            union
            {
                int m_iSelectedAttributeIndex;
                int eMode;
            };
            Tile* m_pTiles[7];
            int m_iPointsUsed;
            int m_iPointsRemaining;
            float unk50;
            union
            {
                bool m_bValueStringNeedsUpdate;
                bool bLimit;
                bool editing;
                bool onlyAdd;
            };
            union
            {
                bool showTagged;
                bool flag;
            };
            unsigned char unk56[2];
        };
    };
    ListBox_enum_ActorValue__Index_ list;

    CharGenMenu();
    void SetTile(int id, Tile* tile);
    int __thiscall vf13();
    int __thiscall GetMenuID_00753340();
    void UpdateValueString(Tile*);
    void UpdatePointsDisplay();
    bool HasAllSlotsSet();
    void HandleTileClick(int, Tile*);
    void InitMenu();
    void BuildSkillList();
    void HandleSkillMenuCommand(int, Tile*);
    bool __thiscall UpdateState_00754150(int, float);
    bool __thiscall HandleButton(int, float);
};
