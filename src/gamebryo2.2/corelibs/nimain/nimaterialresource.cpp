
// src/gamebryo2.2/corelibs/nimain/nimaterialresource.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nimaterialresource.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char const* const g_0126fa40_arg1;

// @fnv 0x00be0ae0
// src: COMMUNITY 0x00be0ae0
char const* const* __cdecl NiD3DPixelShader_GetRTTI()
{
    return &g_0126fa40_arg1;
}

void __cdecl operator delete(void* p, unsigned int flags);
void* __cdecl operator new(unsigned int size, unsigned int flags);
void* __cdecl operator new(unsigned int size);
void* __cdecl ReleaseStrings();

struct FUN_00eea750_shell
{
    virtual ~FUN_00eea750_shell();
    void* Destroy(unsigned int flags);
};

// Calls ReleaseStrings, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00eea750
void* FUN_00eea750_shell::Destroy(unsigned int flags)
{
    ReleaseStrings();
    if (flags & 1)
        operator delete(this, 0x2c);
    return this;
}

// 0x00be0ad0  mov eax,[ecx+0x1c]; ret
struct C00be0ad0
{
    char pad00[0x1c];
    int m1c;
    int NiRenderTargetGroup_GetBufferCount();
};

// @fnv 0x00be0ad0
// src: COMMUNITY 0x00be0ad0
int C00be0ad0::NiRenderTargetGroup_GetBufferCount()
{
    return m1c;
}

// @fnv 0x00eea510
// src: XBOX_PDB 0x00eea510
void* __fastcall NiMaterialResource_GetVariable(void* thisptr)
{
    return (char*)thisptr + 0x14;
}
