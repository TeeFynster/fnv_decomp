// bssystemutilities/bssavedatasystemutility.cpp: BSSaveDataSystemUtility (4 functions)

#include "../../include/BSSaveDataSystemUtility.h"
#include "../../include/MemoryManager.h"

// @fnv 0x00af2f60
void BSSaveDataSystemUtility::Destroy()
{
    m_pOperationContext = 0;
}

// @fnv 0x00af2f40
void BSSaveDataSystemUtility::vf04()
{
    Destroy();
}

extern MemoryManager g_memoryManager;
// The shared header does not declare the non-virtual destructor.
void DestroyBSSaveDataSystemUtility();

// @fnv 0x00af2fc0
void* BSSaveDataSystemUtility::vf00(unsigned int flags)
{
    reinterpret_cast<void (__thiscall*)(BSSaveDataSystemUtility*)>(&DestroyBSSaveDataSystemUtility)(this);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

// @fnv 0x00af2ff0
bool BSSaveDataSystemUtility::vf10(const char* a, void* b)
{
    return false;
}
