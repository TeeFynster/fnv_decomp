// src/gamebryo2.2/corelibs/nisystem/nimemobject_o2_variant_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nisystem/nimemobject_o2_variant.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/gamebryo2.2/corelibs/nisystem/nimemobject_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nisystem/nimemobject.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "nimemobject_decls.h"
#include "../../../../include/NiAllocator.h"

struct FUN_00a5c200 : ::NiObjectWords
{
    ::FixedStringHandle name;
    void* controller;
    void* extraData;
    unsigned short extraDataSize, extraDataCapacity;
    FUN_00a5c200();
};
// @fnv 0x00a5c200
FUN_00a5c200::FUN_00a5c200()
{
    words[0] = (unsigned int)::DAT_0109b244;
    name = ::EmptyFS;
    controller = 0;
    extraData = 0;
    extraDataSize = 0;
    extraDataCapacity = 0;
}

#include "../../../../include/NiMemObject.h"

// NiMemManager stand-in: DAT_011f6080 holds the allocator, whose vftable has Allocate at +4 and Deallocate at +8.
namespace NiMemDetail {
enum NiMemEventType
{
    NI_OPER_NEW_ARRAY = 2,
    NI_OPER_DELETE = 3
};

class NiMemManager
{
  public:
    ::NiAllocator* m_pkAllocator;
    static NiMemManager& Get()
    {
        return *static_cast<NiMemManager*>(::DAT_011f6080);
    }
};
}

// @fnv 0x00aa1420
void* NiMemObject::operator new[](size_t stSizeInBytes)
{
    // The exe keeps the size (zero becomes 1) in a local and reuses the parameter's slot for the alignment (4); the
    // volatile stores pin the order in which it writes them around the argument pushes.
    size_t stSize;
    NiAllocator* pkAllocator;
    return pkAllocator->vfn_04((*(volatile size_t*)&stSizeInBytes = 4, stSize), stSizeInBytes, NiMemDetail::NI_OPER_NEW_ARRAY,
                                 false,
                                 (*(volatile size_t*)&stSize = stSizeInBytes ? stSizeInBytes : 1,
                                  pkAllocator = NiMemDetail::NiMemManager::Get().m_pkAllocator, (const char*)0),
                                 -1, 0);
}

// @fnv 0x00aa1460
void NiMemObject::operator delete(void* pvMem, size_t stElementSize)
{
    if (pvMem)
    {
        NiAllocator* pkAllocator = NiMemDetail::NiMemManager::Get().m_pkAllocator;
        // The shared header leaves the +8 virtual slot untyped (vf02).
        typedef void (__thiscall* DeallocateFunction)(NiAllocator*, void*, int, size_t);
        reinterpret_cast<DeallocateFunction>((*reinterpret_cast<void***>(pkAllocator))[2])(
            pkAllocator, pvMem, NiMemDetail::NI_OPER_DELETE, stElementSize);
    }
}
