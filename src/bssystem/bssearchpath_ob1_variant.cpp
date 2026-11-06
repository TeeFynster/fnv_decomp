
// src/bssystem/bssearchpath_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bssystem/bssearchpath.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bssystem/bssearchpath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystem/bssearchpath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/BSWin32FileCache.h"
#include "../../include/BSSearchPath.h"
#include "../../include/NiSearchPath.h"

struct FUN_00b01c40_shell
{
    void SetByteAt45(unsigned char u8);
};
struct FUN_00b01c70_shell
{
    int __thiscall FUN_00b01c70(int a, int b);
};
struct FUN_00b01c80_shell
{
    void FUN_00b01c80(int a1);
};
struct FUN_00b01ca0_shell
{
    void FUN_00b01ca0(int a, int b);
};
struct FUN_00b01cb0_shell
{
    bool FUN_00b01cb0(int arg1);
};
struct FUN_00b01cc0_shell
{
    void __thiscall FUN_00b01cc0(int);
};
struct FUN_00b01cd0_shell
{
    void FUN_00b01cd0();
};
struct FUN_00b01ce0_shell
{
    void __thiscall FUN_00b01ce0(int);
};
struct FUN_00b01cf0_shell
{
    void FUN_00b01cf0(float a, float b, float c, float d);
};
struct FUN_00b01d10_shell
{
    bool __thiscall FUN_00b01d10(int a);
};
struct FUN_00b01c60_shell
{
    void FUN_00b01c60();
};
struct FUN_00b01d00_shell
{
    void __thiscall FUN_00b01d00();
};
struct S_00b01d20_MemoryManager
{
    void Deallocate(void* p);
};
extern S_00b01d20_MemoryManager g_00b01d20_MemoryManager;
int __cdecl FUN_00ec65a6(char* dst, unsigned int size, const char* src);

struct MemMgrSP
{
    void* __thiscall Allocate(unsigned int uiSize);
};
extern MemMgrSP g_memMgrSP;

inline void* BSSearchPath::operator new(unsigned int uiSize)
{
    return g_memMgrSP.Allocate(uiSize);
}

// @fnv 0x00b013f0
void* FUN_00b013f0()
{
    return new BSSearchPath;
}
