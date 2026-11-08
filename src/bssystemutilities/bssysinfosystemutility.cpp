// bssystemutilities/bssysinfosystemutility.cpp: BSSysInfoSystemUtility (3 functions)

#include "layout_support.h"
#include "../../include/BSSysInfoSystemUtility.h"
#include "../../include/MemoryManagerGlobals.h"

// @fnv 0x00af3b70
void BSSysInfoSystemUtility::Initialize()
{}

// @fnv 0x00af3b80
void BSSysInfoSystemUtility::Destroy()
{
    m_eLanguage = BSSysInfoSystemUtility::LANGUAGE_UNKNOWN;
}



// The shared header does not declare the non-virtual destructor.
void DestroyBSSysInfoSystemUtility();

// @fnv 0x00af3ba0
void* BSSysInfoSystemUtility::vf00(unsigned int flags)
{
    reinterpret_cast<void (__thiscall*)(BSSysInfoSystemUtility*)>(&DestroyBSSysInfoSystemUtility)(this);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
