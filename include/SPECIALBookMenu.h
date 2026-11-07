#pragma once

#include "Menu.h"

class NiAVObject;
class NiNode;
class BkButton;
class BkDisplay;
class BookButton;

class SPECIALBookMenu : public Menu
{
public:
    SPECIALBookMenu();
    virtual ~SPECIALBookMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);

    struct BkButtonList
    {
        BkButton** m_pData;
        int m_iCapacity;
        int m_iArrayLength;
        int m_iGrow;

        unsigned int FUN_0044ddc0();
        BkButton*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int index);
        void FUN_007cb2e0(BkButton* const& item);
    };

    struct BkDisplayList
    {
        BkDisplay** m_pData;
        int m_iCapacity;
        int m_iArrayLength;
        int m_iGrow;

        unsigned int FUN_0044ddc0();
        BkDisplay*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int index);
        void FUN_007cb2e0(BkDisplay* const& item);
    };

    struct BkGroup
    {
        BkButtonList buttons;
        BkDisplayList displays;
    };

    struct BookButtonList
    {
        BookButton** data;
        int capacity;
        int count;
        int grow;

        unsigned int FUN_0044ddc0();
        BookButton*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
    };

    struct BookGroup
    {
        BookButtonList buttons;
        BkDisplayList displays;
    };

    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    union
    {
        int pageIndex;
        int selection;
        int m_48;
        int unk48;
    };
    union
    {
        int selectedStat;
        int m_4c;
        int field4c;
        int unk4C;
    };
    union
    {
        float elapsed;
        float m_fTime;
        int unk50;
    };
    union
    {
        bool finished;
        int unk54;
    };
    union
    {
        int limit;
        int field58;
        int unk58;
    };
    union
    {
        NiAVObject* scene;
        NiAVObject* pRoot;
        NiNode* m_pReferencedNode;
    };
    union
    {
        BkGroup m_groups[9];
        BookGroup groups[9];
    };
    int m180[10];
    int m1a8[5];
    int m1bc;
    int m1c0;
    int m1c4;
    int m1c8;
    int m1cc;
    int m1d0;
    int m1d4;
    int m1d8;
    int m1dc;
    int m1e0;

    bool HandleInput(int aiKey);
    int GetCurrentStatesActorValue();
    int LoveTesterMenu_GetCurrentStatesActorValue();
    int SPECIALBookMenu_GetTotalPointsUsed();
    void DoIdle_007c6200();
    bool HandleSpecialBookKey(unsigned int key, int unused);
    bool TurnPage(bool forward);
    void InitMenu();
    void LoadBBTextures();
    void InvokeCallbacksForSlot();
    void HandleKey(unsigned int key, int unused);
};
