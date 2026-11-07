#include "../../../../include/MemoryManager.h"
// src/gamebryo2.2/corelibs/nisystem/bsniallocator_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* _memmove(void* dst, const void* src, unsigned int n);
void* _realloc(void* ptr, unsigned int size);

struct FUN_00aa4200_Helper
{
    void* _MemoryManager_Reallocate(void* old, unsigned int size, unsigned int a, unsigned int b, unsigned int c);
};

// @fnv 0x00aa4200
// src: COMMUNITY 0x00aa4200
void* FUN_00aa4200_Helper::_MemoryManager_Reallocate(void* old, unsigned int size, unsigned int a, unsigned int b, unsigned int c)
{
    void* result2 = 0;
    unsigned int oldSize;
    oldSize = ((MemoryManager*)this)->Size(old);
    if (oldSize)
    {
        result2 = ((MemoryManager*)this)->Allocate(size);
        if (oldSize > size)
            oldSize = size;
        _memmove(result2, old, oldSize);
        ((MemoryManager*)this)->Deallocate(old);
    }
    else
    {
        void* tmp = old;
        tmp = _realloc(tmp, size);
        result2 = tmp;
    }
    return result2;
}
