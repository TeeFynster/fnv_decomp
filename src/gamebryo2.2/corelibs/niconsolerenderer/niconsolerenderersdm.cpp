
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiD3DShaderProgramCreatorHLSL.h"

// @fnv 0x00e91ae0
void __thiscall NiD3DShaderProgramCreatorHLSL::SetCompileFlags(unsigned int uiFlags)
{
    m_uiCompileFlags = uiFlags;
}

extern "C" void* __cdecl __Dummy_00b6fef0(void* obj, unsigned int flags);
extern int DAT_010f0a68;

// @fnv 0x00e91c10
void* __thiscall NiD3DShaderProgramCreatorHLSL::Destroy(unsigned int flags)
{
    *(void**)this = (void*)&DAT_010f0a68;
    if (flags & 1)
    {
        __Dummy_00b6fef0(this, 8);
    }
    return this;
}

void __cdecl _delete(void*, unsigned int);
extern int DAT_010f0a68;
// @fnv 0x00e91be0
void* __fastcall DestroyShaderProgramCreator(NiD3DShaderProgramCreator* pThis, void*, unsigned int flags)
{
    *(void**)pThis = (void*)&DAT_010f0a68;
    if (flags & 1)
        _delete(pThis, 4);
    return pThis;
}

void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_010f0a68;
extern int DAT_010f0ac0;
struct Holder00e91c40
{
    int m0;
    int m4;
    void* m8;
    int mC;
    void* DestroyHolder(unsigned int);
};
// @fnv 0x00e91c40
void* Holder00e91c40::DestroyHolder(unsigned int auiFlags)
{
    void* p = m8;
    *(void**)this = (void*)&DAT_010f0ac0;
    _NiFreeAlias(p);
    *(void**)this = (void*)&DAT_010f0a68;
    if (auiFlags & 1)
        _delete(this, 0x10);
    return this;
}
