// bssystemutilities/bsdiscbootsystemutility.cpp: BSDiscBootSystemUtility (3 functions)

#include "../../include/BSDiscBootSystemUtility.h"
#include "../../include/MemoryManager.h"

extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

// @fnv 0x00af3ae0
void BSDiscBootSystemUtility::Destroy()
{}

// @fnv 0x00af3aa0
void BSDiscBootSystemUtility::Initialize(const char* titleID, unsigned int parentalLevel)
{
    Destroy();
    if (titleID)
    {
        strcpy_s(m_acTitleID, 0x40, titleID);
    }
    m_uiParentalLevel = parentalLevel;
}

extern MemoryManager g_memoryManager;
// The original destructor resets the vtable and expects this in ECX.
extern "C" void BSDiscBootSystemUtility_ResetVtable();
// @fnv 0x00af3af0
void* BSDiscBootSystemUtility::vf00(unsigned int flags)
{
    __asm
    {
        mov ecx, this
        call BSDiscBootSystemUtility_ResetVtable
    }
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
