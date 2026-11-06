#include "../../../include/BSSimpleArray.h"
// fallout_shared/pathfinding/navmeshedgeextrainfo_decls.h: declares EdgeExtraInfo
#ifndef NAVMESHEDGEEXTRAINFO_DECLS_H
#define NAVMESHEDGEEXTRAINFO_DECLS_H


class NavMeshInfo;
class TESFile;





extern unsigned int DAT_0106b0dc;

class EdgeExtraInfo
{
  public:
    void* vtable;
    EdgeExtraInfo* DeserializeFromFile();
};

#endif
