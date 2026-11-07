// fallout/interface/hotkeyswheel_decls.h: hotkey wheel declarations
#ifndef HOTKEYSWHEEL_DECLS_H
#define HOTKEYSWHEEL_DECLS_H

#include "../../../include/BSStringT.h"

#include "../../../include/Tile.h"

#include "../../../include/HotkeyWheelDisplay.h"

// InputManager (no shared definition; OSGlobals.h names it): 0x00a24660 is its control-state query, reading the key
// maps at +0x1b94 (keyboard, 2 devices) and +0x1be8 (controller) and the flags at +0x1b92 -- not a HotkeyWheelDisplay method
class InputManager
{
  public:
    char layoutPadding0[0x1b92];
    unsigned short flags;
    unsigned char keyboard[3][28];
    unsigned char controller[28];
    int Controls_GetUserAction(int key, int state);
    int Controls_GetButtonState(int, int, int);
    int HandleHotkeyInput(int, int);
    int Controls_GetControllerButton(int, int);
};
int __cdecl GetTileValueID(const char*, int);
int __cdecl Warning(const char*, ...);
extern const char DAT_0106eaa0[], DAT_0106ea94[], DAT_0106ea84[], DAT_0106ea74[], g_emptyTopicInfoPrompt[];
__forceinline unsigned short HotkeySuppressedMask()
{
    return 8;
}
extern bool DAT_011f35c8;
#endif
