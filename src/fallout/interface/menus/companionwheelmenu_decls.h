#include "../../../../include/InterfaceManager.h"
// fallout/interface/menus/companionwheelmenu_decls.h: declares InterfaceManager and the MessageMenu ctor's class
#ifndef COMPANIONWHEELMENU_DECLS_H
#define COMPANIONWHEELMENU_DECLS_H
#include "../../../../include/Menu.h"
#include "../../../../include/CompanionWheelMenu.h"
// ListBox<int> at MessageMenu +0x40: ctor 0x007642f0, destroyed on unwind.
class FUN_007642f0
{
  public:
    FUN_007642f0();
    ~FUN_007642f0();
    char storage[48];
};
// GameTimerRecord at MessageMenu +0x70: ctor 0x0076bda0 (GetTime, Init), no dtor.
class FUN_0076bda0
{
  public:
    FUN_0076bda0();
    char storage[32];
};

InterfaceManager* InterfaceManager_GetSingleton();
// MessageMenu (menu class 1001): ctor 0x007a8a10 installs vftable 0x0107566c; GetMenuById allocates 0x94. Named apart from
// include/MessageMenu.h, whose ListBox_int_ and GameTimerRecord declare none of the ctors/dtor this ctor calls.
class MessageMenu_007a8a10 : public Menu
{
  public:
    MessageMenu_007a8a10();
    virtual ~MessageMenu_007a8a10();
    Tile* tiles[6];             // +0x28
    FUN_007642f0 choiceList;    // +0x40
    FUN_0076bda0 timer;         // +0x70
    unsigned int messageCount;  // +0x90
};
#endif
