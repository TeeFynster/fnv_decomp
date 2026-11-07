
// src/havok/physics/dynamics/world/hkpworld_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/dynamics/world/hkpworld.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/world/hkpworld.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpworld.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../include/hkReferencedObject.h"

// Only the callback dispatcher below belongs to this variant. Unused copied
// declarations from the parent unit, including its class stand-ins, were removed.
struct FUN_00c98820_ArrayObject
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24(void* first, void* second, void* third, void* fourth, void* fifth);
};

struct FUN_00c98820_Class
{
    int m_00;
    int m_04;
    FUN_00c98820_ArrayObject** m_08;
    int m_0c;

    void __thiscall ProcessEntries_00c98820(void* first, void* second, void* third, void* fourth, void* fifth);
};

// @fnv 0x00c98820
// src: GUESS 0x00c98820 (confidence: low)
void __thiscall FUN_00c98820_Class::ProcessEntries_00c98820(void* first, void* second, void* third, void* fourth, void* fifth)
{
    __m128 sum = _mm_add_ps(*(__m128*)second, *(__m128*)first);

    for (int index = 0; index < m_0c; ++index)
    {
        FUN_00c98820_ArrayObject* object = m_08[index];
        object->vf24(first, &sum, third, fourth, fifth);
    }
}
