// fallout_shared/pathfinding/navmeshedgeextrainfo.cpp: EdgeExtraInfo, EdgeHolder (2 functions)

#include "navmeshedgeextrainfo_decls.h"
#include "../../../include/TES.h"

// @fnv 0x00694de0
EdgeExtraInfo* EdgeExtraInfo::DeserializeFromFile()
{
    vtable = &DAT_0106b0dc;
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(this)->BSSimpleArray_float_1024_InitialSetup(0, false);
    return this;
}

extern TES* g_TES;
struct PortalHolder
{
    void LoadFormRef(void* p);
};
struct EdgeHolder
{
    void EdgeExtraInfo_LoadV5(void* a, void* b);
};
// @fnv 0x0069d240
// src: COMMUNITY 0x0069d240
void EdgeHolder::EdgeExtraInfo_LoadV5(void* apArg1, void* apArg2)
{
    *(int*)this = 0;
    ((PortalHolder*)((char*)this + 4))->LoadFormRef(g_TES->GetActiveCell(apArg1, apArg2));
}
