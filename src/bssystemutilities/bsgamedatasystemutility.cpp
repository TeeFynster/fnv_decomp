// bssystemutilities/bsgamedatasystemutility.cpp: BSGameDataSystemUtility (3 functions)

#include "BSGameDataSystemUtility.h"
#include "../../include/MemoryManager.h"

// @fnv 0x00af3a00
void BSGameDataSystemUtility::Destroy()
{}

struct FUN_00af39e0_shell : public BSGameDataSystemUtility
{
    void CallVirtualMethod2();
};

namespace {
struct VTable
{
    void* f0;
    void* f1;
    void(__thiscall* f2)(void*);
};
struct Obj
{
    VTable* vt;
};
}

// @fnv 0x00af39e0
void FUN_00af39e0_shell::CallVirtualMethod2()
{
    reinterpret_cast<Obj*>(this)->vt->f2(this);
}

extern MemoryManager g_memoryManager;
struct FUN_00af3a10_Class
{
    void SetVirtualTable_00af39c0();
    void* FUN_00af3a10(unsigned int);
};
// @fnv 0x00af3a10
void* FUN_00af3a10_Class::FUN_00af3a10(unsigned int flags)
{
    SetVirtualTable_00af39c0();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
