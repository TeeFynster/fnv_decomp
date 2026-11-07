#include "../../../../include/MemoryManager.h"

// src/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern MemoryManager g_memoryManager;
struct BSNiAllocator
{
    void Deallocate_00aa22b0(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes);
};
// @fnv 0x00aa22b0
// src: XBOX_PDB 0x00aa22b0
void BSNiAllocator::Deallocate_00aa22b0(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes)
{
    if (aiAllocationType == 10)
    {
        if (pvMemory)
        {
            pvMemory = (char*)pvMemory - *((unsigned char*)pvMemory - 1);
            g_memoryManager._DeallocateAlias(pvMemory);
            return;
        }
    }
    else
    {
        g_memoryManager._DeallocateAlias(pvMemory);
    }
}

namespace fnv_00aa23e0 {
extern MemoryManager g_memoryManager;
// @fnv 0x00aa23e0
// src: XBOX_PDB 0x00aa23e0
void __stdcall BSNiAllocator_DeallocateExternal(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes)
{
    if (aiAllocationType == 0x10)
    {
        if (!pvMemory)
            return;
        pvMemory = (char*)pvMemory - *((unsigned char*)pvMemory - 1);
        g_memoryManager.Deallocate(pvMemory);
        return;
    }
    g_memoryManager.Deallocate(pvMemory);
}
}  // namespace fnv_00aa23e0

namespace fnv_00aa24a0 {
extern MemoryManager g_memoryManager;
extern int DAT_010a24d0;
struct BSNiAllocator
{
    void* Destroy(unsigned int);
};
// Sets the vtable pointer to DAT_010a24d0 and, when bit 0 of flags is set, deallocates this via g_memoryManager, then returns this.
// @fnv 0x00aa24a0
void* BSNiAllocator::Destroy(unsigned int flags)
{
    *(void**)this = (void*)&DAT_010a24d0;
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00aa24a0

// For eType 8, reallocates pBlock with extra *pAdjust bytes and fixes the header offset; otherwise uses tracked reallocation.
// @fnv 0x00aa22f0
char* __stdcall ResizeHeapBlock(char* pBlock, int* pSize, unsigned char* pAdjust, int eType, int a5, int a6, int a7,
                                int a8, int a9)
{
    if (eType == 8)
    {
        int sz = *pSize;
        unsigned char ucAdjust = *pAdjust;
        if (pBlock != 0)
        {
            unsigned char ucHeader = (unsigned char)pBlock[-1];
            char* base = pBlock - ucHeader;
            char* r = (char*)g_memoryManager.Reallocate(base, ucAdjust + sz);
            unsigned char adj = ucAdjust - (unsigned char)((ucAdjust - 1) & (unsigned char)(unsigned long)r);
            r += adj;
            r[-1] = (char)adj;
            return r;
        }
        return 0;
    }
    return (char*)g_memoryManager.Reallocate(pBlock, *pSize, (char*)a7, a8, (char*)a9);
}

void FUN_00ec61c0(unsigned int p, int zero, unsigned int v);

// @fnv 0x00aa2370
unsigned int __stdcall AllocateAlignedBuffer(unsigned int* puiSize, unsigned char* pucAlignByte, int aiAlignMode,
                                             int aiUnused, int a5, int a6, int a7)
{
    unsigned int r;
    if (aiAlignMode == 0xd)
    {
        unsigned int uiSize = *puiSize;
        unsigned char ucAlignByte = *pucAlignByte;
        unsigned int base = (unsigned int)g_memoryManager.Allocate(uiSize + ucAlignByte);
        unsigned char adj = (unsigned char)(ucAlignByte - ((ucAlignByte - 1) & (unsigned char)base));
        *(unsigned char*)(base + adj - 1) = adj;
        r = base + adj;
    }
    else
    {
        r = (unsigned int)g_memoryManager.Allocate(*puiSize, (const char*)a5, a6, (const char*)a7);
    }
    FUN_00ec61c0(r, 0, *puiSize);
    return r;
}

extern "C" void* __cdecl MemSetAA2(void* pvDest, int iValue, unsigned int uiSize);

enum NiMemEventTypeAA2
{
    NI_UNKNOWN,
    NI_OPER_NEW,
    NI_OPER_NEW_ARRAY,
    NI_OPER_DELETE,
    NI_OPER_DELETE_ARRAY,
    NI_MALLOC,
    NI_REALLOC,
    NI_ALIGNEDMALLOC
};

// Allocates memory (aligned or plain) via g_memoryManager, zeroes stSizeInBytes bytes, and returns the pointer.
// @fnv 0x00aa2240
void* __stdcall AllocateZeroedMemory(unsigned int& stSizeInBytes, unsigned int& stAlignment,
                                     NiMemEventTypeAA2 eMemEventType, bool bProvideAccurateSizeOnDeallocate,
                                     const char* pcFile, int iLine, const char* pcFunction)
{
    void* pvMem;
    if (eMemEventType == NI_ALIGNEDMALLOC)
    {
        unsigned int stSize = stSizeInBytes;
        unsigned char ucAlignment = (unsigned char)stAlignment;
        char* pcMem = (char*)g_memoryManager.Allocate(stSize + ucAlignment);
        unsigned char ucOffset = ucAlignment - ((ucAlignment - 1) & (unsigned char)(unsigned int)pcMem);
        pcMem += ucOffset;
        pcMem[-1] = ucOffset;
        pvMem = pcMem;
    }
    else
    {
        pvMem = g_memoryManager.Allocate(stSizeInBytes, pcFile, iLine, pcFunction);
    }
    MemSetAA2(pvMem, 0, stSizeInBytes);
    return pvMem;
}

// @fnv 0x00aa2420
// src: XBOX_PDB 0x00aa2420
void* __stdcall BSNiAllocator_ReallocateExternal(void* pvMem, unsigned int& uiSize, unsigned char& ucAlignment, int aiAllocationType,
                             bool bProvideSize, unsigned int uiCurrentSize, const char* pcFile, int iLine,
                             const char* pcFunction)
{
    if (aiAllocationType == 14)
    {
        unsigned int uiNewSize = uiSize;
        unsigned char ucAlign = ucAlignment;
        if (pvMem)
        {
            char* pcBase = (char*)pvMem - ((unsigned char*)pvMem)[-1];
            char* pcNew = (char*)g_memoryManager.Reallocate(pcBase, ucAlign + uiNewSize);
            unsigned char ucOffset = ucAlign - ((ucAlign - 1) & (unsigned char)(unsigned int)pcNew);
            pcNew += ucOffset;
            pcNew[-1] = ucOffset;
            return pcNew;
        }
        return 0;
    }
    return g_memoryManager.Reallocate(pvMem, uiSize, const_cast<char*>(pcFile), iLine, const_cast<char*>(pcFunction));
}
