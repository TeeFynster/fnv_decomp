// src/havok/physics/vehicle/hkpvehicleinstanceclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstanceclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/hkMemoryAllocator.h"
#include "../../../../include/hkMemoryRouter.h"
#include "../../../../include/hkpVehicleInstance.h"

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl DestroyVehicleInstance();

// Destroys the vehicle, optionally frees its allocation, and returns its address.
// @fnv 0x00dfbe50
hkpVehicleInstance* __fastcall DeleteVehicleInstance(hkpVehicleInstance* pInstance, void*, unsigned char acFlags)
{
    typedef void (__thiscall* DestroyFunction)(hkpVehicleInstance*);
    reinterpret_cast<DestroyFunction>(&DestroyVehicleInstance)(pInstance);
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        reinterpret_cast<FreeFunction>((*reinterpret_cast<void***>(pAllocator))[2])(pAllocator, pInstance, pInstance->m_usMemSizeAndFlags);
    }
    return pInstance;
}
