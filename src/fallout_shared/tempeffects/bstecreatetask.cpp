#include "../../../include/NiTask.h"

// src/fallout_shared/tempeffects/bstecreatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tempeffects/bstecreatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char const* const g_011d6a18_arg1;

struct FUN_00682480_shell
{
    char const* const* GetArg1Ptr();
};

// @fnv 0x00682480
char const* const* FUN_00682480_shell::GetArg1Ptr()
{
    return &g_011d6a18_arg1;
}

extern "C" void __cdecl _delete(void* p, unsigned int size);
struct FUN_00682490_shell
{
    void __thiscall FUN_006824c0();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_006824c0, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00682490
void* __thiscall FUN_00682490_shell::DestroyIfFlagged(unsigned int flags)
{
    this->FUN_006824c0();
    if (flags & 1)
        _delete(this, 0xc);
    return this;
}


// Returns true if the status field at offset 8 is 4 or 3, otherwise false.
// @fnv 0x006824e0
// src: XBOX_PDB 0x006824e0
bool NiTask::Clear_006824e0()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) == 4 ||
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) == 3)
        return true;
    return false;
}

class C0NiObject
{
  public:
    virtual ~C0NiObject();

    int m_uiRefCount;
};

class FUN_006824c0 : public C0NiObject
{
  public:
    virtual ~FUN_006824c0();
};

// @fnv 0x006824c0
FUN_006824c0::~FUN_006824c0()
{}
