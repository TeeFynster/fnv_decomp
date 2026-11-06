// Exe 0x006ca850 uses a 20-byte allocator-backed scratch array, ctor 0x006cf780: BSScrapArray, not BSSimpleArray.
#include "../../../include/BSScrapArray.h"
// fallout_shared/pathfinding/pathbuilder_decls.h: settings and allocator-array helpers

#include "../../../include/SettingT.h"

class INISettingCollection;
extern SettingT<INISettingCollection> DAT_011d7450;

class GlobalObject_00869f00
{
  public:
    unsigned int GetSize();
};
