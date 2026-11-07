// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/NiGeometryGroupManager.h"

extern int DAT_0109df2c;
extern int DAT_011f4ab4;
void __cdecl _delete(void*, unsigned int);
// Sets the vtable pointer, clears DAT_011f4ab4, and if bit 0 of a1 is set deletes this with size 4, then returns this.
// @fnv 0x00a7f840
void* NiGeometryGroupManager::vf00(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_0109df2c;
    DAT_011f4ab4 = 0;
    if (auiFlags & 1)
        _delete(this, 4);
    return this;
}

// @fnv 0x00aa00c0
// src: GUESS 0x00aa00c0 (confidence: high)
bool __stdcall Object_ReturnFalse(int a, int b)
{
    return false;
}
