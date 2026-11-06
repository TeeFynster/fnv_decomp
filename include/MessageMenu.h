#pragma once

#include "Menu.h"
#include "ListBox_int_.h"
#include "GameTimerRecord.h"

class MessageMenu : public Menu
{
public:
    Tile* m_pTiles[6];             // 0x28
    ListBox_int_ m_kChoiceList;    // 0x40
    GameTimerRecord m_kTimerCalls; // 0x70
    unsigned int m_uiMessageCount; // 0x90

    MessageMenu();
    virtual int GetClass();
    static void SetMessageMenuActive(bool);
};
