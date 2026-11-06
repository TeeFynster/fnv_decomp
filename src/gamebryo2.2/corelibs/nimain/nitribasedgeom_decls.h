// gamebryo2.2/corelibs/nimain/nitribasedgeom_decls.h: the 0x0051d020 bitfield view; the Gamebryo classes come from include/
#pragma once
#include "../../../../include/NiObject.h"
#include "../../../../include/BSTextureSet.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiGeometry.h"

// 0x0051d020 (and 0x0051d080) update a 16-bit flag word at +0xAC of their object; the owning class is not
// identified (NiTriBasedGeom is 0xC4+ and has NiGeometry::m_PropertyState at +0x9C..0xB8).
class FUN_0051d020_FlagsAtAC
{
  public:
    char padding[0xac];
    unsigned short flags;
    void SetBitfield(unsigned short, unsigned short, unsigned short);
};
