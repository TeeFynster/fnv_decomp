// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollideclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollideclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00dfeb10
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00dfeb10();
    virtual ~FUN_00dfeb10();
    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        unsigned int uiSize = ((FUN_00dfeb10*)apMemory)->m_u04;
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        (*reinterpret_cast<FreeFunction**>(pAllocator))[2](pAllocator, apMemory, uiSize);
    }
};

// Initialises m_u04 and m_u06 to zero for a FUN_00dfeb10 instance.
// @fnv 0x00dfeb10
FUN_00dfeb10::FUN_00dfeb10()
{
    m_u04 = 0;
    m_u06 = 0;
}
