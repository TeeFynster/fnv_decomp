#pragma once

#include "Menu.h"
#include "TextEditState.h"

class Tile;

class TextEditMenu : public Menu
{
public:
    Tile* input;
    Tile* accept;
    Tile* title;
    TextEditState editor;
    void (__cdecl* callback)(const char*);

    TextEditMenu();                  // 0x0071fa80 (installs vftable 0x01070034; 0x5c bytes)
    void ProcessState_007e6700();
};
