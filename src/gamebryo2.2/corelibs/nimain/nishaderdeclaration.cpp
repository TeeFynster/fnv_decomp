// src/gamebryo2.2/corelibs/nimain/nishaderdeclaration.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nishaderdeclaration.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiShaderDeclaration.h"

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
extern int DAT_011011ec;

// @fnv 0x00ee88e0
NiShaderDeclaration* __fastcall FUN_00ee88e0(NiShaderDeclaration* object, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(object) = &DAT_011011ec;
    object->NiRefObject::~NiRefObject();
    if (flags & 1)
        __Dummy_00b6fef0(object, 8);
    return object;
}

extern int DAT_011010ec;
struct BaseStub
{
    void __thiscall _Call_a5d3a0();
};
struct FUN_00ee8500
{
    char _pad[40];
    FUN_00ee8500();
};
// Calls the base constructor, installs DAT_011010ec as the vtable pointer, and zeroes the byte at offset 8 and the dwords from offset 12 through 36.
// @fnv 0x00ee8500
FUN_00ee8500::FUN_00ee8500()
{
    ((BaseStub*)this)->_Call_a5d3a0();
    *(volatile unsigned char*)((char*)this + 8) = 0;
    *(volatile unsigned int*)this = (unsigned int)&DAT_011010ec;
    *(volatile unsigned int*)((char*)this + 12) = 0;
    *(volatile unsigned int*)((char*)this + 16) = 0;
    *(volatile unsigned int*)((char*)this + 20) = 0;
    *(volatile unsigned int*)((char*)this + 24) = 0;
    *(volatile unsigned int*)((char*)this + 28) = 0;
    *(volatile unsigned int*)((char*)this + 32) = 0;
    *(volatile unsigned int*)((char*)this + 36) = 0;
}
