#pragma once

#include "Menu.h"

class SleepWaitMenu : public Menu
{
public:
    enum TILE_INDEX
    {
        TI_HOW_MANY_TEXT,
        TI_SCROLLBAR,
        TI_HOURS_TEXT,
        TI_TIME_TEXT,
        TI_WAIT_BUTTON,
        TI_CANCEL_BUTTON,
        NUM_TILES
    };

    virtual ~SleepWaitMenu();
    virtual void AssignTileByID(int index, Tile* tile);
    virtual void HandleSelection(int index, Tile* tile);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int input, float value);

    union
    {
        unsigned char layoutExtension[0x24];
        struct
        {
            Tile* m_pTiles[NUM_TILES];
            float m_fCameraTransitionTime;
            bool m_bState1;
            union
            {
                bool m_bState2;
                unsigned char m_bSleep;
            };
            bool m_bState3;
            unsigned char unk47;
            float m_fWaitTime;
        };
    };

    SleepWaitMenu();

    int GetClass_007bfbc0();
    void* __thiscall FUN_007bfbd0(unsigned int flags);
    void* __thiscall FUN_007bfc00();
    void DoClick_007c0220(int slot, int value);
    bool DoGamepad_007c04d0(int input, int unused);
    void UpdateGaugeDisplay();
    bool UpdateSleep();
    bool QuantityMenu_IsWellFormedMenu();
    void FUN_00a1d910();
    int GetID();

    static SleepWaitMenu* ms_pInventoryMenu;
    static int ms_iState;
};
