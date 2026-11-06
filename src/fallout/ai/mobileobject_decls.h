// Source layout: MobileObject. PC corrections are in generate_headers.py.
#ifndef FNV_MOBILEOBJECT_POSITION_DECLS_H
#define FNV_MOBILEOBJECT_POSITION_DECLS_H

#include "layout_support.h"
#include "TESObjectREFR.h"
// the shared MobileObject
#include "../../../include/MobileObject.h"
// a call view (0x004518e0 is TESObjectCELL::HasWater)
class MobileObjectCellAccess
{
  public:
    bool FUN_004518e0() const;
};

struct MobileObjectWaterPositionHeight
{
    float waterHeight;
    float heightOffset;
};

extern "C" double DAT_010241b0;
extern const double DAT_01020998;
extern const double DAT_0101de30;
extern int DAT_011df880;
extern NiPoint3 DAT_011df7a0[5];
#endif
