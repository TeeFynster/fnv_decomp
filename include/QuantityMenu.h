#pragma once

#include "Menu.h"

class QuantityMenu : public Menu
{
public:
    virtual ~QuantityMenu();

    unsigned char unk28[0x1c];

    QuantityMenu();
    bool HandleButton(int aiButton, float afValue);
    int GetMenuID_00720a30();
    void* FUN_00720a40(unsigned int flags);
    void ClearGlobalAndDestroyMenu();
};
