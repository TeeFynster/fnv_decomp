// src/gamebryo2.2/corelibs/nimain/nimateriallibrary.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nimateriallibrary.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl _delete(void* p, unsigned int flags);

struct FUN_00a8fdb0_shell
{
    void __thiscall ProcessEntries_00a8fdb0();
};

struct FUN_00a8ff10_shell : FUN_00a8fdb0_shell
{
    void* __thiscall FUN_00a8ff10(unsigned int flags);
};

// Calls the base cleanup, then frees this object with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a8ff10
void* __thiscall FUN_00a8ff10_shell::FUN_00a8ff10(unsigned int flags)
{
    ProcessEntries_00a8fdb0();
    if (flags & 1)
        _delete(this, 0xc);
    return this;
}
