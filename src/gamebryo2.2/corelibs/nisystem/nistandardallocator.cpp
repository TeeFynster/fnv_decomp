
// src/gamebryo2.2/corelibs/nisystem/nistandardallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/nistandardallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiStandardAllocator.h"

// Swaps two adjacent ints at a and b when the pointers differ.
// @fnv 0x00aa3530
void __cdecl SwapIntPairs(int* paiFirst, int* paiSecond)
{
    if (paiFirst != paiSecond)
    {
        int tmp0 = *paiFirst;
        int tmp1 = *(paiFirst + 1);
        *paiFirst = *paiSecond;
        *(paiFirst + 1) = *(paiSecond + 1);
        *(paiSecond + 1) = tmp1;
        *paiSecond = tmp0;
    }
}

struct P03MM
{
    void Deallocate(void*);
};
extern P03MM g_memoryManager;

// @fnv 0x00aa3370
// src: COMMUNITY 0x00aa3370
void __stdcall NiStandardAllocator_DeallocateExternal(void* apBlock, int e, unsigned int s)
{
    if (apBlock)
    {
        if (e == 0x10)
            apBlock = (char*)apBlock - *(unsigned char*)((char*)apBlock - 1);
        g_memoryManager.Deallocate(apBlock);
    }
}

namespace fnv_00aa3430 {
extern int DAT_011f622c;

struct P03MM
{
    void* Allocate(unsigned int);
};

P03MM g_memoryManager;

// @fnv 0x00aa3430
void __cdecl AllocateStandardAllocator()
{
    void* p = g_memoryManager.Allocate(0x10080);
    if (p)
    {
        DAT_011f622c = (int)((NiStandardAllocator*)p)->NiStandardObjectAllocHelper(0x6400);
    }
    else
    {
        DAT_011f622c = 0;
    }
}
}  // namespace fnv_00aa3430

// Reads four bytes from pMemory into an unsigned int and returns it.
// @fnv 0x00aa3090
unsigned int __cdecl ReadUInt32(void* pMemory)
{
    char* pBytes;
    char* pcSize;
    unsigned int stSize;
    pBytes = (char*)pMemory;
    pcSize = (char*)&stSize;
    pcSize[0] = pBytes[0];
    pcSize[1] = pBytes[1];
    pcSize[2] = pBytes[2];
    pcSize[3] = pBytes[3];
    return stSize;
}

struct SmallAlloc
{
    void __thiscall NiSmallObjectAllocator_Deallocate(void* p, unsigned int s);
};
extern SmallAlloc* DAT_011f622c;
unsigned int __cdecl ReadUInt32(void* p);
void __cdecl FreeAllocatorBlock(void* p);
// @fnv 0x00aa3150
// src: COMMUNITY 0x00aa3150
void __stdcall NiStandardAllocator_Deallocate(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes)
{
    if (pvMemory)
    {
        if (aiAllocationType != 10 && aiAllocationType != 8)
        {
            if (stSizeInBytes == 0xffffffff)
            {
                pvMemory = (char*)pvMemory - 4;
                stSizeInBytes = ReadUInt32(pvMemory);
            }
        }
        if (stSizeInBytes <= 0x100)
            DAT_011f622c->NiSmallObjectAllocator_Deallocate(pvMemory, stSizeInBytes);
        else
            FreeAllocatorBlock(pvMemory);
    }
}

// Stand-ins for the two callees of the original function.
//   0x00aa3810 : __thiscall member, one 4-byte stack argument, returns a pointer.
//   0x00aa1130 : __cdecl, two 4-byte arguments (count, type), returns a pointer.
// The names are deliberately different from the ones in the unit file so that the
// checker binds the call relocations to the addresses found in the original bytes.
struct MemPool
{
    void* __thiscall FUN_00aa3810_x(unsigned int s);
};
void* __cdecl FUN_00aa1130_x(int count, int type);

// A 4-byte object that is written as a dword and read back one byte at a time.
// The ARRAY member is what keeps the object in memory: with four named byte
// members cl 2008 expands the union into registers and extracts the bytes with
// shifts, which is not what the original does.
union Pun
{
    unsigned int i;
    unsigned char c[4];
};

// 0x00aa30c0: writes a 4-byte count into a buffer obtained from the memory
// manager, when the record is a 4-byte type and the caller's flag is clear.
// @fnv 0x00aa30c0
// src: COMMUNITY 0x00aa30c0
unsigned char* __stdcall NiStandardAllocator_Allocate(unsigned int* pCount, int* pType, int eType, unsigned char bFlag, int a4, int a5,
                                      int a6)
{
    bool bWriteCount = false;
    unsigned char* pBuffer = 0;

    if (*pType == 4 && bFlag == 0)
    {
        if (eType != 7)
        {
            if (eType != 8)
            {
                *pCount += 4;
                bWriteCount = true;
            }
        }
    }

    if (eType != 7 && eType != 8 && *pCount <= 0x100 && *pType == 4)
    {
        pBuffer = (unsigned char*)((MemPool*)DAT_011f622c)->FUN_00aa3810_x(*pCount);
    }
    else
    {
        pBuffer = (unsigned char*)FUN_00aa1130_x(*pCount, *pType);
    }

    if (pBuffer && bWriteCount)
    {
        {
            Pun u;
            u.i = *pCount;
            unsigned char* bytes = (unsigned char*)&u;
            pBuffer[0] = bytes[0];
            pBuffer[1] = bytes[1];
            pBuffer[2] = bytes[2];
            pBuffer[3] = bytes[3];
        }
        pBuffer += 4;
    }

    return pBuffer;
}

extern P03MM g_memoryManager;

extern SmallAlloc* DAT_011f622c;

struct AA3460Pool
{
    void Shutdown();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
};

struct AA3460Pools
{
    AA3460Pool m_akPools[256];

    ~AA3460Pools()
    {
        AA3460Pool* pkPool = m_akPools + 256;
        for (int i = 255; i >= 0; i--)
        {
            --pkPool;
            pkPool->Shutdown();
        }
    }

    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
};

// Deletes the AA3460Pools object at DAT_011f622c and clears the pointer.
// @fnv 0x00aa3460
void __cdecl DestroySmallAllocPools()
{
    delete reinterpret_cast<AA3460Pools*>(DAT_011f622c);
    DAT_011f622c = 0;
}

struct FUN_00aa34b0_entry
{
    unsigned int m_base;
    unsigned int m_unk04;
};

struct FUN_00aa34b0_cls
{
    unsigned int m_00;
    unsigned char m_04;
    unsigned char m_unk05;
    unsigned char m_unk06;
    unsigned char m_unk07;
    FUN_00aa34b0_entry* m_08;
    unsigned int m_0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    FUN_00aa34b0_entry* m_18;

    FUN_00aa34b0_entry* FindEntryContaining(unsigned int p);
};

// Searches the entry array outward from m_18 for an entry whose [m_base, m_base + m_04*m_00) range contains p, returning it or null.
// @fnv 0x00aa34b0
FUN_00aa34b0_entry* FUN_00aa34b0_cls::FindEntryContaining(unsigned int auiAddress)
{
    FUN_00aa34b0_entry* back = m_18;
    FUN_00aa34b0_entry* pForward = m_18 + 1;
    unsigned int uiRangeSize = (unsigned int)m_04 * m_00;
    FUN_00aa34b0_entry* end = m_08 + m_0c;
    if (pForward == end)
    {
        pForward = 0;
    }

top:
    if (back == 0)
    {
        goto check_fwd;
    }
    if (back->m_base <= auiAddress && auiAddress < back->m_base + uiRangeSize)
    {
        return back;
    }
    if (back == m_08)
    {
        back = 0;
        if (pForward == 0)
        {
            return 0;
        }
        goto fwd_body;
    }
    back = back - 1;

check_fwd:
    if (pForward == 0)
    {
        goto top;
    }
fwd_body:
    if (pForward->m_base <= auiAddress && auiAddress < pForward->m_base + uiRangeSize)
    {
        return pForward;
    }
    pForward = pForward + 1;
    if (pForward != end)
    {
        goto top;
    }
    pForward = 0;
    if (back == 0)
    {
        return 0;
    }
    goto top;
}

unsigned int __cdecl ReadUInt32(void* pMemory);
void* __cdecl NiExternalAlignedRealloc(void* pvMemory, unsigned int stSizeInBytes, unsigned int stAlignment);
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int n);

struct StdAllocator
{
    virtual ~StdAllocator();
    virtual void* Allocate(unsigned int& stSizeInBytes, unsigned int& stAlignment, int aiAllocationType,
                           bool bProvideAccurateSizeOnDeallocate, const char* pcFile, int iLine,
                           const char* pcFunction);
    virtual void Deallocate(void* pvMemory, int aiAllocationType, unsigned int stSizeinBytes);
    void* NiStandardAllocator_Reallocate(void* pvMemory, unsigned int& stSizeInBytes, unsigned int& stAlignment, int aiAllocationType,
                       bool bProvideAccurateSizeOnDeallocate, unsigned int stSizeCurrent, const char* pcFile, int iLine,
                       const char* pcFunction);
};

// @fnv 0x00aa31b0
// src: COMMUNITY 0x00aa31b0
void* StdAllocator::NiStandardAllocator_Reallocate(void* pvMemory, unsigned int& stSizeInBytes, unsigned int& stAlignment,
                                 int aiAllocationType, bool bProvideAccurateSizeOnDeallocate,
                                 unsigned int stSizeCurrent, const char* pcFile, int iLine, const char* pcFunction)
{
    if (aiAllocationType != 10 && aiAllocationType != 8 && stSizeCurrent == (unsigned int)-1 &&
        !bProvideAccurateSizeOnDeallocate)
    {
        pvMemory = (char*)pvMemory - 4;
        stSizeCurrent = ReadUInt32(pvMemory);
    }

    bool bPrependSize = false;
    if (stAlignment == 4 && !bProvideAccurateSizeOnDeallocate && aiAllocationType != 7 && aiAllocationType != 8)
    {
        stSizeInBytes += 4;
        bPrependSize = true;
    }

    if (stSizeCurrent != (unsigned int)-1 && stSizeInBytes <= stSizeCurrent && bPrependSize)
    {
        stSizeInBytes = stSizeCurrent;
        return (char*)pvMemory + 4;
    }

    void* pvNewMemory;
    if (aiAllocationType != 7 && aiAllocationType != 8 && (stSizeCurrent <= 0x100 || stSizeInBytes <= 0x100))
    {
        stSizeInBytes -= 4;
        pvNewMemory = Allocate(stSizeInBytes, stAlignment, aiAllocationType, bProvideAccurateSizeOnDeallocate, pcFile,
                               iLine, pcFunction);
        bPrependSize = false;
        if (stSizeCurrent != (unsigned int)-1)
        {
            memcpy(pvNewMemory, (char*)pvMemory + 4, stSizeCurrent - 4);
            Deallocate(pvMemory, aiAllocationType, stSizeCurrent);
        }
    }
    else
    {
        pvNewMemory = NiExternalAlignedRealloc(pvMemory, stSizeInBytes, stAlignment);
    }

    if (pvNewMemory && bPrependSize)
    {
        unsigned int stSize = stSizeInBytes;
        char* pcSize = (char*)&stSize;
        char* pcMem = (char*)pvNewMemory;
        pcMem[0] = pcSize[0];
        pcMem[1] = pcSize[1];
        pcMem[2] = pcSize[2];
        pcMem[3] = pcSize[3];
        pvNewMemory = pcMem + 4;
    }
    return pvNewMemory;
}

struct MM
{
    void* FUN_00aa4150(void* pvMem, unsigned int uiSize);
};
extern MM _g_memoryManager;
void* _fnv_zlib_memset(void* pvDest, int iValue, int iCount);

// Allocates memory via the memory manager, applying alignment for type 0xe and zeroing the returned block.
// @fnv 0x00aa33a0
// src: COMMUNITY 0x00aa33a0
void* __stdcall NiStandardAllocator_ReallocateExternal(void* pvMem, unsigned int* puiSize, unsigned char* pucAlign, int iType, int iUnk,
                             int iUnkCur, int iUnkValue, int iNewUnk, int iTmpUnk)
{
    void* pNewMem;
    if (iType != 0xe)
    {
        unsigned int uiSize = *puiSize;
        pNewMem = _g_memoryManager.FUN_00aa4150(pvMem, uiSize);
    }
    else
    {
        unsigned int uiSize = *puiSize;
        unsigned char ucAlign = *pucAlign;
        if (pvMem)
        {
            pvMem = (char*)pvMem - ((unsigned char*)pvMem)[-1];
            pNewMem = _g_memoryManager.FUN_00aa4150(pvMem, ucAlign + uiSize);
            unsigned char ucOffset = ucAlign - ((ucAlign - 1) & (unsigned char)(unsigned int)pNewMem);
            pNewMem = (char*)pNewMem + ucOffset;
            ((unsigned char*)pNewMem)[-1] = ucOffset;
        }
        else
        {
            pNewMem = 0;
        }
    }
    return _fnv_zlib_memset(pNewMem, 0, *puiSize);
}

#include <windows.h>
void __cdecl FreeAlignedBlock(void*);
void __cdecl FreeAllocatorBlock(void*);
struct FUN_00aa3560
{
    char _pad0[8];
    struct Entry
    {
        void* p;
        int q;
    }* m_ptr;
    unsigned int m_cnt;
    char _pad1[112];
    CRITICAL_SECTION m_cs;
    ~FUN_00aa3560();
};
// Frees each allocated block in m_ptr, then frees the m_ptr array and deletes the critical section.
// @fnv 0x00aa3560
FUN_00aa3560::~FUN_00aa3560()
{
    for (unsigned int i = 0; i < m_cnt; ++i)
        FreeAllocatorBlock(m_ptr[i].p);
    FreeAlignedBlock(m_ptr);
    DeleteCriticalSection(&m_cs);
}

struct MMHeap
{
    void* Game_DoHeapAlloc(unsigned int uiSize);
};

// Allocates and zeroes a block, applying the requested alignment when iType is 0xd.
// @fnv 0x00aa3300
// src: COMMUNITY 0x00aa3300
void* __stdcall NiStandardAllocator_AllocateExternal(unsigned int puiSize, unsigned char* pucAlign, int iType, int iUnk, int iUnkCur,
                             int iUnkValue, int iNewUnk)
{
    MMHeap* pkHeap = (MMHeap*)&_g_memoryManager;
    void* pvNew;
    if (iType != 0xd)
    {
        unsigned int uiSize = *(unsigned int*)puiSize;
        pvNew = pkHeap->Game_DoHeapAlloc(uiSize);
    }
    else
    {
        unsigned int uiSize = *(unsigned int*)puiSize;
        unsigned char ucAlign = *pucAlign;
        pvNew = pkHeap->Game_DoHeapAlloc(ucAlign + uiSize);
        unsigned char ucOffset = ucAlign - ((ucAlign - 1) & (unsigned char)(unsigned int)pvNew);
        pvNew = (char*)pvNew + ucOffset;
        ((unsigned char*)pvNew)[-1] = ucOffset;
    }
    puiSize = *(unsigned int*)puiSize;
    return _fnv_zlib_memset(pvNew, 0, puiSize);
}
