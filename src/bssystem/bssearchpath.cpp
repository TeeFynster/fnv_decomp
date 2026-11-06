
// src/bssystem/bssearchpath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystem/bssearchpath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BSSearchPath.h"
#include "../../include/BSWin32FileCache.h"
#include "../../include/MemoryManager.h"

// @fnv 0x00b013e0
bool BSSearchPath::FUN_00b013e0(char* apFile)
{
    return true;
}

extern MemoryManager g_memoryManager;

// Calls FUN_00aa24f0, then deallocates this via g_memoryManager._DeallocateAlias when flags has bit 1 set, and returns this.
// @fnv 0x00b01480
void* BSSearchPath::FUN_00b01480(unsigned int flags)
{
    this->FUN_00aa24f0();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct FUN_00b01c40_shell
{
    void SetByteAt45(unsigned char u8);
};

// @fnv 0x00b01c40
void FUN_00b01c40_shell::SetByteAt45(unsigned char u8)
{
    *reinterpret_cast<unsigned char*>(this + 0x45) = u8;
}

struct FUN_00b01c70_shell
{
    int __thiscall FUN_00b01c70(int a, int b);
};

// @fnv 0x00b01c70
int __thiscall FUN_00b01c70_shell::FUN_00b01c70(int a, int b)
{
    return 0;
}

struct FUN_00b01c80_shell
{
    void FUN_00b01c80(int a1);
};

// @fnv 0x00b01c80
void FUN_00b01c80_shell::FUN_00b01c80(int a1)
{}

// @fnv 0x00b01c90
int BSWin32FileCache::vf05(int arg)
{
    return 0;
}

struct FUN_00b01ca0_shell
{
    void FUN_00b01ca0(int a, int b);
};

// @fnv 0x00b01ca0
void FUN_00b01ca0_shell::FUN_00b01ca0(int a, int b)
{}

struct FUN_00b01cb0_shell
{
    bool FUN_00b01cb0(int arg1);
};

// @fnv 0x00b01cb0
bool FUN_00b01cb0_shell::FUN_00b01cb0(int arg1)
{
    return false;
}

struct FUN_00b01cc0_shell
{
    void __thiscall FUN_00b01cc0(int);
};

// @fnv 0x00b01cc0
void __thiscall FUN_00b01cc0_shell::FUN_00b01cc0(int)
{}

struct FUN_00b01cd0_shell
{
    void FUN_00b01cd0();
};

// @fnv 0x00b01cd0
void FUN_00b01cd0_shell::FUN_00b01cd0()
{}

struct FUN_00b01ce0_shell
{
    void __thiscall FUN_00b01ce0(int);
};

// @fnv 0x00b01ce0
void __thiscall FUN_00b01ce0_shell::FUN_00b01ce0(int)
{}

struct FUN_00b01cf0_shell
{
    void FUN_00b01cf0(float a, float b, float c, float d);
};

// @fnv 0x00b01cf0
void FUN_00b01cf0_shell::FUN_00b01cf0(float a, float b, float c, float d)
{}

struct FUN_00b01d10_shell
{
    bool __thiscall FUN_00b01d10(int a);
};

// @fnv 0x00b01d10
bool __thiscall FUN_00b01d10_shell::FUN_00b01d10(int a)
{
    return 0;
}

struct FUN_00b01c60_shell
{
    void FUN_00b01c60();
};
// @fnv 0x00b01c60
void FUN_00b01c60_shell::FUN_00b01c60()
{}

struct FUN_00b01d00_shell
{
    void __thiscall FUN_00b01d00();
};

// @fnv 0x00b01d00
void __thiscall FUN_00b01d00_shell::FUN_00b01d00()
{}

extern MemoryManager g_00b01d20_MemoryManager;
struct S_00b01d20_FileCache
{
    virtual ~S_00b01d20_FileCache();
    S_00b01d20_FileCache* DestroyFileCache(unsigned int uiFlags);
};
// Destructs the object and, when bit 0 of uiFlags is set, deallocates it through g_00b01d20_MemoryManager, returning this.
// @fnv 0x00b01d20
S_00b01d20_FileCache* S_00b01d20_FileCache::DestroyFileCache(unsigned int uiFlags)
{
    this->S_00b01d20_FileCache::~S_00b01d20_FileCache();
    if (uiFlags & 1)
        g_00b01d20_MemoryManager.Deallocate(this);
    return this;
}

int __cdecl FUN_00ec65a6(char* dst, unsigned int size, const char* src);

// @fnv 0x00b01390
bool BSSearchPath::ResolveSearchPath(char* out, unsigned int unused)
{
    switch (m_uiSearchPathValue)
    {
    case 0:
        FUN_00ec65a6(out, 0x104, m_acFilePathBuffer);
        m_uiSearchPathValue = m_uiSearchPathValue + 1;
        return true;
    }
    return false;
}
