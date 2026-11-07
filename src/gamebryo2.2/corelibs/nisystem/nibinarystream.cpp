#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/MemoryManager.h"

// src/gamebryo2.2/corelibs/nisystem/nibinarystream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/nibinarystream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern unsigned char DAT_011f607c;

// @fnv 0x00aa1d40
// src: COMMUNITY 0x00aa1d40
unsigned char __cdecl NiBinaryStream_GetEndianMatchHint()
{
    return DAT_011f607c;
}


extern void* __cdecl _DeallocateAlias(void*);
extern MemoryManager g_memoryManager;
extern int DAT_010a24b8;

// Sets the vtable pointer to DAT_010a24b8 and, if fFree has bit 0 set, deallocates this via g_memoryManager, returning this.
// @fnv 0x00aa1db0
void* __thiscall NiBinaryStream::Destroy(unsigned int fFree)
{
    *reinterpret_cast<void**>(this) = &DAT_010a24b8;
    if (fFree & 1)
    {
        g_memoryManager.Deallocate(this);
    }
    return this;
}

static void SwapPair(unsigned char* a, unsigned char* b)
{
    unsigned char hi = *b;
    unsigned char lo = *a;
    *a = hi;
    *b = lo;
}
// Reverses the byte order of each 8-byte block in buf, repeating for count blocks.
// @fnv 0x00aa1d60
void __cdecl ReverseBytesInBlocks(void* pBuffer, unsigned int count)
{
    if (count <= 0)
    {
        return;
    }
    do
    {
        unsigned char* pBlock = (unsigned char*)pBuffer;
        SwapPair(pBlock + 0, pBlock + 7);
        SwapPair(pBlock + 1, pBlock + 6);
        SwapPair(pBlock + 2, pBlock + 5);
        SwapPair(pBlock + 3, pBlock + 4);
        pBuffer = (unsigned char*)pBuffer + 8;
    } while (--count != 0);
}

// 0x00aa1d50  mov eax,[ecx+4]; ret
struct C00aa1d50
{
    char pad00[0x4];
    int m4;
    int NiBinaryStream_GetPosition();
};

// @fnv 0x00aa1d50
// src: COMMUNITY 0x00aa1d50
int C00aa1d50::NiBinaryStream_GetPosition()
{
    return m4;
}
