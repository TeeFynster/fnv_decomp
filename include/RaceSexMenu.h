#pragma once

#include "Menu.h"

class RaceSexMenu : public Menu
{
public:
    RaceSexMenu();

    void SetTile(int aiID, Tile* apTile);
    void OnRaceSelected(void*);
    int __thiscall FUN_007ac4f0();
    void FUN_007fe910(void* apList);
    void FUN_007fe910(int aiIndex);

    union
    {
        unsigned char layoutExtension[0x17c];
        struct
        {
            unsigned char unk28[0x50];
            Tile* m_pTiles[24];
            unsigned char unkD8[0xcc];
        };
    };
};
