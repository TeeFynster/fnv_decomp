
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/RecursiveSpinLock.h"

struct FUN_008691b0
{
    void Lock();
};

// @fnv 0x008691b0
void FUN_008691b0::Lock()
{
    ((RecursiveSpinLock*)((char*)this + 0x20))->TryLock();
}

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long ms);
// @fnv 0x0040fca0
// src: XBOX_PDB 0x0040fca0
void BSSleep(unsigned long ms)
{
    Sleep(ms);
}
