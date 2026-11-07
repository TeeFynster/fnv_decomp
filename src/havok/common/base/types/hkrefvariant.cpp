
// src/havok/common/base/types/hkrefvariant.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/hkrefvariant.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVtableClassRegistry.h"

struct FUN_00d47770
{
    hkReferencedObject* m_pObject;
    void __thiscall SetObject(hkReferencedObject* object, int extra);
};

// @fnv 0x00d47770
void __thiscall FUN_00d47770::SetObject(hkReferencedObject* object, int extra)
{
    if (object)
        object->addReference();
    if (m_pObject)
        m_pObject->removeReference();
    m_pObject = object;
}

extern hkVtableClassRegistry* DAT_01269b10;

struct ReferencedObjectHolder
{
    hkReferencedObject* m_pObject;
    void* __thiscall hkRefVariant_getClass();
};

// @fnv 0x00d477a0
// src: HAVOK_LIB 0x00d477a0
void* ReferencedObjectHolder::hkRefVariant_getClass()
{
    hkReferencedObject* object = m_pObject;
    if (object)
        return const_cast<hkClass*>(DAT_01269b10->GetClassFromVirtualInstance(object));
    return 0;
}

extern int DAT_010cf9c8;

struct SetBlk
{
    void* f00;
    unsigned short f04;
    unsigned short f06;
};

extern int(__thiscall* DAT_010cf9d4)(SetBlk* object, int value, int extra, int result);

extern "C" int stub_a(void);
extern "C" int stub_b(void);
extern "C" int stub_c(void);

// FUN_00d48560 is reached by the game with a private register convention:
// the enable flag arrives in eax, the extra word in edx, the value on the
// stack. The trailing stub_caller exists only so VC9 negotiates that
// convention for the out-of-line body above.
// If enable is set, builds a SetBlk with f06=1 and f00 pointing to DAT_010cf9c8, then calls DAT_010cf9d4; otherwise returns 1.
// @fnv 0x00d48560
// src: GUESS 0x00d48560 (confidence: low)
static __declspec(noinline) int Object_ProcessAndReturnValue_00d48560(int enable, int extra, int value)
{
    SetBlk v;
    if (enable)
    {
        v.f06 = 1;
        v.f00 = (void*)&DAT_010cf9c8;
        return DAT_010cf9d4(&v, value, enable, extra);
    }
    return 1;
}

int stub_caller(void)
{
    return Object_ProcessAndReturnValue_00d48560(stub_a(), stub_b(), stub_c());
}

// @fnv 0x00d48620
// src: GUESS 0x00d48620 (confidence: low)
int __cdecl Object_ForwardCall_00d48620(int iThirdArg, int iFirstArg, int iUnused)
{
    return Object_ProcessAndReturnValue_00d48560(iFirstArg, 0, iThirdArg);
}
