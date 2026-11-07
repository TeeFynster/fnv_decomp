#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkDefaultBuiltinTypeRegistry.h"
#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"
// src/havok/common/serialize/util/hkbuiltintyperegistry_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/serialize/util/hkbuiltintyperegistry.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/serialize/util/hkbuiltintyperegistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkbuiltintyperegistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// This RTM unit only uses the declarations below; the unused class skeletons from
// hkbuiltintyperegistry.cpp are supplied by shared headers where needed.
extern int DAT_01269b18;
extern int DAT_01269b14;
extern int DAT_01269b10;
// @fnv 0x00d47860
struct DefaultNameRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void registerName(const void* name);
};
struct RuntimeTypeInfoRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void registerType(void* typeInfo);
};
struct NameRegistryTable
{
    void hkVtableClassRegistry_registerList(void** entries, void* info);
};
extern int DAT_01268b0c;
extern void* DAT_010d5430[];
extern int DAT_010d59b8;
void __cdecl FUN_00d47860()
{
    DefaultNameRegistry* reg = (DefaultNameRegistry*)DAT_01269b14;
    reg->registerName(&DAT_01268b0c);
    RuntimeTypeInfoRegistry* types = (RuntimeTypeInfoRegistry*)DAT_01269b18;
    void** curr = DAT_010d5430;
    while (*curr)
    {
        types->registerType(*curr);
        ++curr;
    }
    ((NameRegistryTable*)DAT_01269b10)->hkVtableClassRegistry_registerList(DAT_010d5430, &DAT_010d59b8);
}

extern hkMemoryRouter* _D1A0E0GetMemoryRouter();

// @fnv 0x00d47820
// src: GUESS 0x00d47820 (confidence: medium)
hkDefaultBuiltinTypeRegistry* hkDefaultBuiltinTypeRegistry_AllocateStorage()
{
    if (DAT_01269b10 != 0 && DAT_01269b14 != 0 && DAT_01269b18 != 0)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        void* memory = reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockAlloc(8);
        hkDefaultBuiltinTypeRegistry* registry = static_cast<hkDefaultBuiltinTypeRegistry*>(memory);
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(registry) + 4) = 8;
        return registry->Initialize();
    }
    return 0;
}
