// Private declarations for the startmenu packet.
#ifndef FNV_STARTMENU_PACKET_H
#define FNV_STARTMENU_PACKET_H

#include "../../../../include/StartMenu.h"

#pragma pack(push, 4)

template <class T> class ListBoxItem
{
  public:
    Tile* pTile;       // +0x0
    T data;            // +0x4
    bool m_bFiltered;  // +0x8
};

class GlobalObject_0044f440
{
  public:
    float FUN_00450410();
};
// 0x007d1b30 calls the routine at 0x00450410 through the receiver's own class and
// discards the result with no fstp, so at this call site it is the void variant
// (canonical binds the float variant ?FUN_00450410@GlobalObject_0044f440@@QAEMXZ
// to the same folded address).
class GlobalObject_004de370
{
  public:
    void FUN_00450410();
};
class GlobalObject_00709f00
{
  public:
    void GetBoolValue();
};

#pragma pack(pop)

#endif

// ---- identities used by this packet (mapped in manifest.json) ----
extern bool DAT_011a0294;                 // ?DAT_011a0294@@3_NA
extern GlobalObject_004de370 g_011c71ac;  // ?g_011c71ac@@3VGlobalObject_004de370@@A
extern float DAT_011ad7b8[];              // ?DAT_011ad7b8@@3PAMA
extern GlobalObject_00709f00 g_011d8c4c;  // ?g_011d8c4c@@3VGlobalObject_00709f00@@A
