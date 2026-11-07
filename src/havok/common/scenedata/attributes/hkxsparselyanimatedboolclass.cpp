
// src/havok/common/scenedata/attributes/hkxsparselyanimatedboolclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxsparselyanimatedboolclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"

hkMemoryRouter* hkMemoryRouter_getInstance();


inline void hkReferencedObject::operator delete(void* p)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(p);
    hkMemoryRouter_getInstance()->heap().blockFree(p, b->m_usMemSizeAndFlags);
}

struct FUN_00e01ac0 : hkReferencedObject
{
    FUN_00e01ac0();
    virtual ~FUN_00e01ac0();
};

// Default constructor for the FUN_00e01ac0 class, which inherits from hkReferencedObject.
// @fnv 0x00e01ac0
FUN_00e01ac0::FUN_00e01ac0()
{}
