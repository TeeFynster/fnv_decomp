// bssystemutilities/bscachedrivesystemutility.cpp: BSCacheDriveSystemUtility (3 functions)

#include "BSCacheDriveSystemUtility.h"
#include "../../include/MemoryManager.h"

// @fnv 0x00af3940
void BSCacheDriveSystemUtility::Destroy()
{}

struct FUN_00af3920_shell : public BSCacheDriveSystemUtility
{
    void BSCacheDriveSystemUtility_DoInitialize();
};

struct VTableHelper_00af3920
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

// @fnv 0x00af3920
// src: COMMUNITY 0x00af3920
void FUN_00af3920_shell::BSCacheDriveSystemUtility_DoInitialize()
{
    reinterpret_cast<VTableHelper_00af3920*>(this)->v2();
}

extern MemoryManager g_memoryManager;
struct Host03950
{
    void SetVirtualTable_00af3900();
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_00af3900, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00af3950
void* Host03950::ReleaseIfFlagged(unsigned int flags)
{
    SetVirtualTable_00af3900();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
