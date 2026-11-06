#pragma once

#include "Menu.h"

class PlayerNameEntryMenu : public Menu
{
public:
    virtual ~PlayerNameEntryMenu();
    void UpdateDialog() override;
    void Finish(const char* name);
};
