
// src/bsmenu/radialtile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsmenu/radialtile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/TileImage.h"

struct FUN_00a21660 : TileImage
{
    FUN_00a21660();
};
// Constructs a TileImage-derived object; the body only declares unused locals and performs no work.
// @fnv 0x00a21660
FUN_00a21660::FUN_00a21660()
{
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11;
}

struct P03MM
{
    void Deallocate(void*);
};
extern P03MM g_memoryManager;

struct FUN_00a219e0_shell
{
    void* FUN_00a219e0(unsigned int flags);
    void __thiscall DestroyTileImageBase();
};

// Calls DestroyTileImageBase, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a219e0
void* FUN_00a219e0_shell::FUN_00a219e0(unsigned int flags)
{
    DestroyTileImageBase();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

// ---------------------------------------------------------------------------
// 0x00a21690 - FUN_00a219e0_shell::DestroyTileImageBase()
//
// The original is an unoptimised (/Od) build:
//     00a21690  55                 push ebp
//     00a21691  8b ec              mov ebp, esp
//     00a21693  83 ec 1c           sub esp, 0x1c
//     00a21696  89 4d e4           mov dword ptr [ebp - 0x1c], ecx
//     00a21699  8b 45 e4           mov eax, dword ptr [ebp - 0x1c]
//     00a2169c  c7 00 50 57 09 01  mov dword ptr [eax], 0x01095750
//     00a216a2  8b 4d e4           mov ecx, dword ptr [ebp - 0x1c]
//     00a216a5  e8 16 a0 ce ff     call 0x0070b6c0
//     00a216aa  8b e5              mov esp, ebp
//     00a216ac  5d                 pop ebp
//     00a216ad  c3                 ret
//
// The function puts the vtable pointer of the class back at the front of the
// object (0x01095750 is the vftable of FUN_00a21660) and then chains to the
// base class destructor TileImage::~TileImage() at 0x0070b6c0.
//
// The /Od frame is 0x1c bytes wide: six dead words plus the spilled `this`.
// ---------------------------------------------------------------------------

// The vtable of the class, 0x01095750 in the original binary.  It is only
// ever used by address, so a declaration is enough.
extern void* const FUN_00a21660Vftable[];

// Six dead words of stack space.  The original /Od build reserved them
// between the frame pointer and the spilled `this` pointer, and nothing ever
// reads or writes them.
struct DeadStackSpace
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

// @fnv 0x00a21690
void FUN_00a219e0_shell::DestroyTileImageBase()
{
    DeadStackSpace dead;

    *reinterpret_cast<const void**>(this) = FUN_00a21660Vftable;
    reinterpret_cast<TileImage*>(this)->TileImage::~TileImage();
}
