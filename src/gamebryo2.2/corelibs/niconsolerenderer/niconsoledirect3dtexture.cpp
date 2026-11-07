
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiTexture.h"
#include "../../../../include/NiPersistentSrcTextureRendererData.h"
#include "../../../../include/NiColorA.h"

extern "C" const char* const g_011f444c_arg1;

// @fnv 0x00a5fc00
// src: COMMUNITY 0x00a5fc00
const char* const* __cdecl NiTexture_GetRTTI()
{
    return &g_011f444c_arg1;
}

struct Helper
{
    char _0[4];
    NiColorA _4;
};
bool __cdecl AreFloatsEqual(Helper const*, Helper const*);
// Returns false if AreFloatsEqual(a, b) is false, otherwise returns the result of a->_4.operator==(b->_4).
// @fnv 0x00a299c0
bool __cdecl CompareHelpers(Helper const* apLeft, Helper const* apRight)
{
    if (!AreFloatsEqual(apLeft, apRight))
        return false;
    return apLeft->_4.operator==(apRight->_4);
}

void __fastcall NiTexture_RemoveTextureFromList(void*);
void __fastcall DestroyFogProperty(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_0109b944;
// @fnv 0x00a60120
void* NiTexture::Destroy(unsigned int flags)
{
    *(void**)this = (void*)&DAT_0109b944;
    delete m_pkRendererData;
    NiTexture_RemoveTextureFromList(this);
    DestroyFogProperty(this);
    if (flags & 1)
        _delete(this, 0x30);
    return this;
}
