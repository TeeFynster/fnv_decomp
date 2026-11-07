
// src/staging/blk_00aa0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/MemoryManager.h"
#include "../../include/IMemoryHeap.h"
#include "../../include/AbstractHeap.h"
#include "../../include/BSThread.h"
#include "../../include/MemoryPool.h"

extern "C" void* __cdecl _malloc(unsigned int);

// Allocates size bytes with _malloc and returns the resulting pointer.
// @fnv 0x00aa4290
void* __thiscall MemoryManager::DoSystemAllocation(unsigned int size, bool aligned)
{
    void* buffer = _malloc(size);
    void* result = buffer;
    return result;
}

extern "C" void __cdecl free(void*);

// @fnv 0x00aa42c0
void __thiscall MemoryManager::DoSystemDeallocation(void* p, bool aligned)
{
    free(p);
}

struct FUN_00aa4790_Class
{
    void __thiscall MemoryManager_GetHeapStats(int, unsigned char, int);
    void __thiscall MemoryManager_GetDefaultHeapStats(int a, int b, int c);
};

// Calls FUN_00aa4710 with a, the low byte of b, and c.
// @fnv 0x00aa4790
// src: COMMUNITY 0x00aa4790
void __thiscall FUN_00aa4790_Class::MemoryManager_GetDefaultHeapStats(int a, int b, int c)
{
    MemoryManager_GetHeapStats(a, (unsigned char)b, c);
}

// @fnv 0x00aa4bf0
void SetByteAtOffset(char* p, char c)
{
    p[0x11f6370] = c;
}

struct FUN_00aa4c10_class
{
    void __thiscall CheckWarningDisabled(int arg);
};

extern "C" void __cdecl BSCoreMessage_IsWarningDisabled(int);

// Passes arg to FUN_00aa4be0 via a local copy.
// @fnv 0x00aa4c10
// src: GUESS 0x00aa4c10 (confidence: medium)
void __thiscall FUN_00aa4c10_class::CheckWarningDisabled(int arg)
{
    int local = arg;
    BSCoreMessage_IsWarningDisabled(local);
}

extern "C" void __cdecl SetByteAtOffset(int, int);

struct FUN_00aa4c40_class
{
    void __thiscall BSCoreMessage_DisableContextMessages(int a);
};

// @fnv 0x00aa4c40
// src: COMMUNITY 0x00aa4c40
void __thiscall FUN_00aa4c40_class::BSCoreMessage_DisableContextMessages(int a)
{
    SetByteAtOffset(a, 1);
}

extern "C" void* DAT_010a2708;

struct FUN_00aa4c60_class
{
    void* m_p;
    void* BSCoreMessage_BSCoreMessage();
};

// @fnv 0x00aa4c60
// src: COMMUNITY 0x00aa4c60
void* FUN_00aa4c60_class::BSCoreMessage_BSCoreMessage()
{
    m_p = &DAT_010a2708;
    return this;
}

namespace fnv_00aa4c80 {
extern int DAT_010a2708;

struct FUN_00aa4c80_class
{
    int* m_p;
    void UpdateFields_00aa4c80();
};

// @fnv 0x00aa4c80
// src: GUESS 0x00aa4c80 (confidence: low)
void FUN_00aa4c80_class::UpdateFields_00aa4c80()
{
    m_p = &DAT_010a2708;
}
}  // namespace fnv_00aa4c80

struct AbstractHeapLogger
{
    void ProcessState_00aa4ce0();
};
extern AbstractHeapLogger* DAT_011f6388;
// @fnv 0x00aa4ce0
// src: GUESS 0x00aa4ce0 (confidence: low)
void AbstractHeapLogger::ProcessState_00aa4ce0()
{
    if (DAT_011f6388)
        DAT_011f6388->ProcessState_00aa4ce0();
}

extern MemoryPool* DAT_011f67b8[];

struct FUN_00aa6950_Class
{
    void __thiscall ClearPoolSlot(unsigned int a);
};

// Clears the entry at index a >> 2 in the DAT_011f67b8 pool array.
// @fnv 0x00aa6950
void __thiscall FUN_00aa6950_Class::ClearPoolSlot(unsigned int uiIndex)
{
    unsigned int idx = uiIndex >> 2;
    DAT_011f67b8[idx] = 0;
}

// @fnv 0x00aa7e50
const char* AbstractHeap::GetName()
{
    return pName;
}

extern int DAT_010a29c0;


struct FUN_00aa8410 : BSThread
{
    FUN_00aa8410();
};

// @fnv 0x00aa8410
FUN_00aa8410::FUN_00aa8410()
{}

extern int DAT_010a29b0;

struct FUN_00aa8a00_cls
{
    int* m;
    void UpdateFields_00aa8a00();
};

// @fnv 0x00aa8a00
// src: GUESS 0x00aa8a00 (confidence: low)
void FUN_00aa8a00_cls::UpdateFields_00aa8a00()
{
    m = &DAT_010a29b0;
}

extern int DAT_010a2980;

struct FUN_00aa8a20_class
{
    void UpdateFields_00aa8a20();
};

// @fnv 0x00aa8a20
// src: GUESS 0x00aa8a20 (confidence: low)
void FUN_00aa8a20_class::UpdateFields_00aa8a20()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010a2980);
}

extern MemoryManager g_memoryManager;

struct FUN_00aa8b00_Class
{
    void* __thiscall BSMap_unsigned_int_ScrapHeap_NewItem();
};

// @fnv 0x00aa8b00
// src: COMMUNITY 0x00aa8b00
void* __thiscall FUN_00aa8b00_Class::BSMap_unsigned_int_ScrapHeap_NewItem()
{
    void* result = g_memoryManager.Allocate(0xc);
    return result;
}

void __cdecl FNV_Warning(const char* fmt, ...);

// @fnv 0x00aafbb0
void __cdecl ReportFr2Error(const char* pcFile, int iLine, const char* pcMessage)
{
    FNV_Warning("DEFAULT: FR2 ERROR in %s line %i : '%s'. Code may crash.", pcFile, iLine, pcMessage);
}

// @fnv 0x00aa41e0
void* __thiscall MemoryManager::AllocatePhysical(unsigned int a, unsigned long b)
{
    return 0;
}

// @fnv 0x00aa41f0
void MemoryManager::DeallocatePhysical(void* a, unsigned long b, unsigned long c)
{}

// @fnv 0x00aa45a0
IMemoryHeap* MemoryManager::GetHeapForPointer(void* arg)
{
    for (unsigned short i = 0; i < iNumHeaps; ++i)
    {
        IMemoryHeap* item = ppHeaps[i];
        if (item->ContainsBlockImpl(arg))
            return item;
    }
    return 0;
}

struct FUN_00aa46a0_holder
{
    void* __thiscall GetEntryAt(unsigned int a);
};
struct FUN_00aa4710_Class
{
    char __thiscall MemoryManager_GetHeapStats(int a, unsigned char b, int c);
};
// @fnv 0x00aa4710
// src: COMMUNITY 0x00aa4710
char __thiscall FUN_00aa4710_Class::MemoryManager_GetHeapStats(int a, unsigned char b, int c)
{
    char flag_ = 0;
    void* p2 = ((FUN_00aa46a0_holder*)this)->GetEntryAt((unsigned int)a);
    if (p2)
    {
        flag_ = 1;
        ((void(__thiscall*)(void*, int, unsigned char))(*(void***)p2)[6])(p2, c, b);
    }
    return flag_;
}

struct FUN_00aa4b20_Class
{
    void __thiscall ClearAndDeallocate(void* p);
};

// Sets the third int of p to zero, then passes p to MemoryManager::Deallocate.
// @fnv 0x00aa4b20
void __thiscall FUN_00aa4b20_Class::ClearAndDeallocate(void* p)
{
    ((int*)p)[2] = 0;
    void* arg = p;
    g_memoryManager.Deallocate(arg);
}

namespace fnv_00aa4b50 {
extern int DAT_010a2618;
extern MemoryManager _g_memoryManager;
struct FUN_00aa4b50_Class
{
    int* vtbl;
    int pad;
    void* p;
    void* __thiscall Destroy(unsigned int flags);
};
// Sets the vtable, deallocates p if set, and frees this when flags has bit 0 set; returns this.
// @fnv 0x00aa4b50
void* __thiscall FUN_00aa4b50_Class::Destroy(unsigned int flags)
{
    vtbl = (int*)&DAT_010a2618;
    if (p)
    {
        void* tmp = p;
        _g_memoryManager.Deallocate(tmp);
    }
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00aa4b50

struct FUN_00aa50f0_Class
{
    void __thiscall BSTimer_Init(unsigned int a);
};
// Zeroes the object's byte, floats and int fields, stores the given value at offset 24, and clears the bytes at offsets 28 and 29.
// @fnv 0x00aa50f0
// src: COMMUNITY 0x00aa50f0
void __thiscall FUN_00aa50f0_Class::BSTimer_Init(unsigned int uiValue)
{
    *(unsigned char*)this = 0;
    *(float*)(this + 4) = 0.0f;
    *(float*)(this + 8) = 0.0f;
    *(float*)(this + 12) = 0.0f;
    *(int*)(this + 20) = 0;
    *(unsigned int*)(this + 24) = uiValue;
    *(unsigned char*)(this + 29) = 0;
    *(unsigned char*)(this + 28) = 0;
}

namespace fnv_00aa8b20 {
extern MemoryManager _g_memoryManager;
struct FUN_00aa8b20_Class
{
    int* p;
    void* __thiscall FUN_00aa8b20(int flag);
};
// @fnv 0x00aa8b20
void* __thiscall FUN_00aa8b20_Class::FUN_00aa8b20(int flag)
{
    p = &DAT_010a29b0;
    if (flag & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00aa8b20

namespace fnv_00aa8b50 {
struct FUN_00aa8b50_Class
{
    int* m;
    void* __thiscall FUN_00aa8b50(int a);
};
// Sets m to &DAT_010a2980 and, when bit 0 of a is set, deallocates this via g_memoryManager; returns this.
// @fnv 0x00aa8b50
void* __thiscall FUN_00aa8b50_Class::FUN_00aa8b50(int aiFlags)
{
    m = &DAT_010a2980;
    if (aiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00aa8b50

struct FUN_00aa8b80_class
{
    void* m0;
    void* m4;
    void* m8;
    int mC;
    void __thiscall AppendBlock(void* block);
};
// Links block into the list after m8, sets its first two words, updates m4/m8 and increments mC.
// @fnv 0x00aa8b80
void __thiscall FUN_00aa8b80_class::AppendBlock(void* block)
{
    *(void**)block = 0;
    ((void**)block)[1] = m8;
    if (m8)
        *(void**)m8 = block;
    else
        m4 = block;
    m8 = block;
    ++mC;
}

struct FUN_00aa8c40_N
{
    FUN_00aa8c40_N* next;
    FUN_00aa8c40_N* prev;
};
struct FUN_00aa8c40_H
{
    int pad0;
    FUN_00aa8c40_N* head;
    FUN_00aa8c40_N* tail;
    unsigned int count;
    void PushFront(FUN_00aa8c40_N* n);
};
// Inserts node n at the head of the doubly linked list, updating prev/next links, tail when empty, and incrementing count.
// @fnv 0x00aa8c40
void FUN_00aa8c40_H::PushFront(FUN_00aa8c40_N* pNode)
{
    pNode->prev = 0;
    pNode->next = head;
    if (head)
        head->prev = pNode;
    else
        tail = pNode;
    head = pNode;
    ++count;
}

struct FUN_00aa9d20_Class
{
    void __thiscall nullsub_317(int arg);
};

// @fnv 0x00aa9d20
// src: COMMUNITY 0x00aa9d20
void FUN_00aa9d20_Class::nullsub_317(int arg)
{}

struct FUN_00aaa6d0_Class
{
    void* __thiscall return_this();
};
// @fnv 0x00aaa6d0
// src: COMMUNITY 0x00aaa6d0
void* __thiscall FUN_00aaa6d0_Class::return_this()
{
    return this;
}

struct FUN_00aaa6e0_Class
{
    int m0;
    int m4;
    void __thiscall SetFlags(unsigned int flags, int unused);
};
// @fnv 0x00aaa6e0
void __thiscall FUN_00aaa6e0_Class::SetFlags(unsigned int flags, int unused)
{
    m4 = 0;
    m4 = (m4 & 0xf0000000) | flags;
    m0 = 0;
    unused = 0;
}

extern int DAT_010a2618;
void* __cdecl _fnv_zlib_memset(void* dst, int val, unsigned int len);
struct FUN_00aa47e0_Class
{
    int m0;
    int m4;
    void* m8;
    int mC;
    FUN_00aa47e0_Class* __thiscall BSMapBase_unsigned_int_ScrapHeap_BSMapBase_unsigned_int_ScrapHeap(unsigned int count);
};
// Initializes the object with a count, allocates count*4 bytes zeroed into m8, and returns this.
// @fnv 0x00aa47e0
// src: COMMUNITY 0x00aa47e0
FUN_00aa47e0_Class* FUN_00aa47e0_Class::BSMapBase_unsigned_int_ScrapHeap_BSMapBase_unsigned_int_ScrapHeap(unsigned int count)
{
    unsigned int bytes;
    void* p5;
    m0 = (int)&DAT_010a2618;
    m4 = count;
    mC = 0;
    if (count)
    {
        bytes = m4 * 4;
        p5 = g_memoryManager.Allocate(bytes);
        m8 = p5;
        _fnv_zlib_memset(m8, 0, m4 * 4);
    }
    return this;
}

struct FUN_00aba370_s
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    void __thiscall EraseRange(unsigned int a, unsigned int b);
    void __thiscall AppendChars(unsigned int a, unsigned char b);
    void __thiscall ResizeStringRange(unsigned int pos, unsigned char b);
};
extern unsigned int DAT_010173f0;
// If pos is within m_14, calls EraseRange with pos and DAT_010173f0; otherwise calls AppendChars with pos - m_14 and b.
// @fnv 0x00aba370
// src: GUESS 0x00aba370 (confidence: medium)
void FUN_00aba370_s::ResizeStringRange(unsigned int pos, unsigned char ucValue)
{
    unsigned int v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, va, vb, vc, vd;
    if (pos <= m_14)
        EraseRange(pos, DAT_010173f0);
    else
        AppendChars(pos - m_14, ucValue);
}

void __cdecl FUN_00ec7c56();

struct FUN_00abbeb0_Class
{
    int m0;
    int m4;
    int m8;
    unsigned int mC;
    unsigned int m10;
    FUN_00abbeb0_Class* SetCheckedRangeSize(unsigned int size, FUN_00abbeb0_Class* p);
};

// Validates that p is non-null and size lies within p->mC..p->m10, otherwise calls FUN_00ec7c56, then copies p->m0 into m0 and stores size in m4.
// @fnv 0x00abbeb0
// src: GUESS 0x00abbeb0 (confidence: medium)
FUN_00abbeb0_Class* FUN_00abbeb0_Class::SetCheckedRangeSize(unsigned int size, FUN_00abbeb0_Class* p)
{
    m0 = 0;
    if (!(p && p->mC <= size && size <= p->m10))
    {
        FUN_00ec7c56();
    }
    m0 = p->m0;
    m4 = size;
    return this;
}

void FUN_00ec7c56();

struct FUN_00abbf00_Class
{
    int m0;
    int m4;
    char Matches(FUN_00abbf00_Class* other);
};

// Calls FUN_00ec7c56 unless m0 is nonzero and equal to other's m0, then returns whether m4 equals other's m4.
// @fnv 0x00abbf00
char FUN_00abbf00_Class::Matches(FUN_00abbf00_Class* other)
{
    if (!static_cast<bool>(static_cast<int>(this->m0 != 0)) ||
        !static_cast<bool>(static_cast<int>(this->m0 == other->m0)))
        FUN_00ec7c56();
    return static_cast<char>(static_cast<int>(this->m4 == other->m4));
}

struct FUN_00aa4760_Class : public FUN_00aa4710_Class
{
    char CallBaseWithOffset(int a, unsigned char b, int c);
};
// Calls the base-class method with the first argument offset by the 16-bit value at this+2, passing b and c through.
// @fnv 0x00aa4760
char FUN_00aa4760_Class::CallBaseWithOffset(int aiValue, unsigned char b, int c)
{
    return MemoryManager_GetHeapStats(aiValue + *(unsigned short*)((char*)this + 2), b, c);
}

// @fnv 0x00aa4be0
// src: COMMUNITY 0x00aa4be0
unsigned char __cdecl BSCoreMessage_IsWarningDisabled(char* p)
{
    return p[0x11f6370];
}

struct FUN_00aa4ca0_class
{
    void __thiscall ProcessState_00aa4ca0(unsigned int a, unsigned int b, float c, unsigned int d, unsigned int e);
};

// @fnv 0x00aa4ca0
// src: GUESS 0x00aa4ca0 (confidence: low)
void __thiscall FUN_00aa4ca0_class::ProcessState_00aa4ca0(unsigned int a, unsigned int b, float c, unsigned int d,
                                                 unsigned int e)
{
    if (DAT_011f6388)
    {
        ((FUN_00aa4ca0_class*)DAT_011f6388)->ProcessState_00aa4ca0(a, b, c, d, e);
    }
}

struct FUN_00aa5fc0_Class
{
    int __thiscall ClearFields();
};
// Sets the two int fields at offsets 0 and 4 of this object to zero and returns this.
// @fnv 0x00aa5fc0
int FUN_00aa5fc0_Class::ClearFields()
{
    *(int*)this = 0;
    *(int*)((char*)this + 4) = 0;
    return (int)this;
}

struct FUN_00aa6920_Class
{
    void __thiscall RegisterInPool(unsigned int index);
};
// Stores this object into the DAT_011f67b8 pool array at slot index >> 2.
// @fnv 0x00aa6920
void __thiscall FUN_00aa6920_Class::RegisterInPool(unsigned int index)
{
    unsigned int i = index >> 2;
    DAT_011f67b8[i] = (MemoryPool*)this;
}

struct FUN_00aa8a40_vt
{
    virtual void v0();
    virtual void* v1();
};
struct FUN_00aa8a40_Node
{
    int pad0;
    int pad4;
    int pad8;
};
struct FUN_00aa8a40_Class
{
    FUN_00aa8c40_H m_kNode;
    void __thiscall BSList_BSSemaphore_AddHead(FUN_00aa8a40_Node* node);
};

// Calls v1 to get an object, stores node->pad0 at offset 8, then passes it to PushFront.
// @fnv 0x00aa8a40
// src: COMMUNITY 0x00aa8a40
void __thiscall FUN_00aa8a40_Class::BSList_BSSemaphore_AddHead(FUN_00aa8a40_Node* node)
{
    FUN_00aa8c40_N* n = (FUN_00aa8c40_N*)((FUN_00aa8a40_vt*)this)->v1();
    *(int*)((char*)n + 8) = node->pad0;
    m_kNode.PushFront(n);
}

// @fnv 0x00aa8ea0
void AbstractHeap::Clear()
{
    for (int i = 0; i < 0x400; ++i)
    {
        HeapFreeList* list = &pSmallFreeList[i];

        while (list->pTail != 0)
        {
            this->RemoveBlockFromFreeList_00aa9e50(list, list->pTail);
        }
    }

    while (LargeFreeList.pTail != 0)
    {
        this->RemoveBlockFromFreeList_00aa9e50(&LargeFreeList, LargeFreeList.pTail);
    }

    FreeHeapMemory(pMemHeap);

    pMemHeap = 0;
    MemHeapSize = 0;
}

struct FUN_00aaaa80_Class
{
    void* __thiscall FUN_00aaaa80();
    void* __thiscall DestroyWithFlags(unsigned int flags);
};

// @fnv 0x00aaab00
void* FUN_00aaaa80_Class::DestroyWithFlags(unsigned int flags)
{
    int a, b, c, d, e, f, g, h, i, j;
    FUN_00aaaa80();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00ab2e70
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    FUN_00ab2e70();
    ~FUN_00ab2e70();
};
struct FUN_00ab2e40
{
    int m0;
    int m4;
    int m8;
    int mC;
    FUN_00ab2e70 m10[3];
    FUN_00ab2e40();
};
// @fnv 0x00ab2e40
FUN_00ab2e40::FUN_00ab2e40()
{}

// Scans the pool array and returns the first pool whose Contains check accepts pvMem, or null if none does.
// @fnv 0x00aa4610
IMemoryHeap* MemoryManager::GetHeapForPhysicalPointer(void* pvMem)
{
    IMemoryHeap* pkFound = 0;
    for (unsigned short i = 0; i < iNumPhysicalHeaps && !pkFound; i++)
    {
        if (ppPhysicalHeaps[i]->ContainsBlockImpl(pvMem))
            pkFound = ppPhysicalHeaps[i];
    }
    return pkFound;
}

extern unsigned int DAT_011f69f8;

// @fnv 0x00aa4960
// src: COMMUNITY 0x00aa4960
void* MemoryPool_GetClosestPoolForSize(unsigned int size)
{
    unsigned int result = 0;

    if (size < 0x12c)
    {
        result = (size <= 0x3fc) ? (unsigned int)DAT_011f67b8[((size + 15) & 0xfffffff0) >> 2] : 0;
    }
    else if (size < 0x200)
    {
        result = (size <= 0x3fc) ? (unsigned int)DAT_011f67b8[((size + 15) & 0xfffffff0) >> 2] : 0;
        if (result == 0)
        {
            result = (size <= 0x3fc) ? (unsigned int)DAT_011f67b8[((size + 0x1f) & 0xffffffe0) >> 2] : 0;
        }
    }
    else if (size < 0x240)
    {
        result = (size <= 0x3fc) ? DAT_011f69f8 : 0;
    }

    if (result != 0 && 1)
    {
        return (void*)result;
    }
    else
    {
        return 0;
    }
}

struct FUN_00aa4ae0_Class
{
    int* unk00;
    int unk04;
    void* unk08;
    void ResetAndFree();
};

extern int DAT_010a2618;
extern MemoryManager DAT_011f6238;

// Points unk00 at DAT_010a2618 and, if unk08 is non-null, deallocates it through DAT_011f6238.
// @fnv 0x00aa4ae0
void __thiscall FUN_00aa4ae0_Class::ResetAndFree()
{
    this->unk00 = &DAT_010a2618;
    if (this->unk08 != 0)
    {
        void* p = this->unk08;
        DAT_011f6238.Deallocate(p);
    }
}

extern MemoryManager DAT_011f6238;

struct FUN_00aa4bb0_Class
{
    void FUN_00aa4a60();
    int __thiscall FUN_00aa4bb0(int arg);
};

struct FUN_00aa4bb0_Local
{
    int unk00;
    int unk04;
    int unk08;
};

// Calls FUN_00aa4a60, then deallocates this via DAT_011f6238 when bit 0 of arg is set, and returns this.
// @fnv 0x00aa4bb0
int __thiscall FUN_00aa4bb0_Class::FUN_00aa4bb0(int aiFlags)
{
    FUN_00aa4bb0_Local local;

    this->FUN_00aa4a60();

    if ((aiFlags & 1) != 0)
    {
        DAT_011f6238.Deallocate(this);
    }

    return reinterpret_cast<int>(this);
}

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* frequency);
extern double DAT_01017b70;
extern float DAT_011ac39c;

// Queries the performance counter frequency and stores it divided by DAT_01017b70 as a float in DAT_011ac39c.
// @fnv 0x00aa4d50
void __cdecl InitPerformanceFrequency(void)
{
    __int64 frequency;
    QueryPerformanceFrequency(&frequency);
    DAT_011ac39c = static_cast<float>(frequency / DAT_01017b70);
}

struct ScrapHeapEntry
{
    void* m_pBuffer;
    unsigned int m_iElementCount;
};

struct ScrapHeapManager
{
    ScrapHeapEntry m_entries[64];
    unsigned int m_uiItemCount;
    unsigned int m_totalSize;
    void RemoveEntry(unsigned int index);
};

// Decrements the entry count, subtracts the removed entry's size from m_totalSize, and moves the last entry into the freed slot if it is not the last one.
// @fnv 0x00aa5f50
void ScrapHeapManager::RemoveEntry(unsigned int index)
{
    m_uiItemCount = m_uiItemCount - 1;
    m_totalSize = m_totalSize - m_entries[index].m_iElementCount;
    if (index < m_uiItemCount)
    {
        m_entries[index] = m_entries[m_uiItemCount];
    }
}

struct FUN_00aa5ff0_Class
{
    unsigned int m_uiItemCount;
    unsigned int m_uiThreadId;

    void __thiscall BSReadWriteLock_LockForRead();
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* destination, long exchange,
                                                                           long comparand);

// @fnv 0x00aa5ff0
// src: XBOX_PDB 0x00aa5ff0
void __thiscall FUN_00aa5ff0_Class::BSReadWriteLock_LockForRead()
{
    unsigned long threadId = GetCurrentThreadId();

    if (m_uiThreadId == threadId)
    {
        m_uiItemCount = m_uiItemCount + 1;
    }
    else
    {
        unsigned int count = m_uiItemCount & 0x0fffffff;

        while (InterlockedCompareExchange(reinterpret_cast<volatile long*>(&m_uiItemCount),
                                          static_cast<long>(count + 1),
                                          static_cast<long>(count)) != static_cast<long>(count))
        {
            Sleep(0);
            count = m_uiItemCount & 0x0fffffff;
        }
    }
}

struct FUN_00aa6330_Class
{
    int unk0;
    unsigned int unk4;
    bool IsCurrentThread();
};

// Returns whether the current thread's id equals the stored thread id in unk4.
// @fnv 0x00aa6330
bool FUN_00aa6330_Class::IsCurrentThread()
{
    unsigned int threadId = GetCurrentThreadId();
    return threadId == unk4;
}

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned int, unsigned int);
struct FUN_00aa6680_class
{
    unsigned int unk00;
    void* allocation;
    void __thiscall FreeAllocation();
};
// @fnv 0x00aa6680
void FUN_00aa6680_class::FreeAllocation()
{
    VirtualFree(allocation, 0, 0x8000);
}

struct LinkedNode
{
    LinkedNode* previous;
    LinkedNode* next;
};
struct NodeSorter
{
    LinkedNode* SortList(LinkedNode* head);
};
// Bottom-up merge sort of a doubly linked list by node address, relinking previous/next pointers and returning the new head.
// @fnv 0x00aa70c0
LinkedNode* NodeSorter::SortList(LinkedNode* head)
{
    LinkedNode *left, *tail, *p, *tailPtr;
    unsigned int insize;
    int i, q, nmerges;
    unsigned int e;
    i = 0;
    if (head == 0)
        return 0;
    insize = 1;
    while (i != 1)
    {
        left = head;
        head = 0;
        tailPtr = 0;
        i = 0;
        while (left != 0)
        {
            ++i;
            tail = left;
            nmerges = 0;
            for (e = 0; e < insize; ++e)
            {
                ++nmerges;
                tail = tail->next;
                if (tail == 0)
                    break;
            }
            q = insize;
            while (nmerges > 0 || (q > 0 && tail != 0))
            {

                if (nmerges == 0)
                {
                    p = tail;
                    tail = tail->next;
                    --q;
                }
                else if (q == 0 || tail == 0)
                {
                    p = left;
                    left = left->next;
                    --nmerges;
                }
                else if (tail >= left)
                {
                    p = left;
                    left = left->next;
                    --nmerges;
                }
                else
                {
                    p = tail;
                    tail = tail->next;
                    --q;
                }
                if (tailPtr != 0)
                    tailPtr->next = p;
                else
                    head = p;
                p->previous = tailPtr;
                tailPtr = p;
            }
            left = tail;
        }
        tailPtr->next = 0;
        insize *= 2;
    }
    return head;
}


extern MemoryPool* DAT_011f67b8[];
extern char DAT_010a2850;

// @fnv 0x00aa7290
// src: COMMUNITY 0x00aa7290
void MemoryPool_SortFreeBlocks(int aiIndex)
{
    int pad0;
    int pad1;
    RecursiveSpinLock* pool;
    if (DAT_011f67b8[aiIndex])
    {
        DAT_011f67b8[aiIndex]->m_kCriticalSection.BSSpinLock_Lock(&DAT_010a2850);
        DAT_011f67b8[aiIndex]->MemoryPool_SortFreeBlockList();
        pool = &DAT_011f67b8[aiIndex]->m_kCriticalSection;
        pool->m_uiRecursionCount = pool->m_uiRecursionCount - 1;
        if (pool->m_uiRecursionCount == 0)
        {
            pool->m_uiOwningThreadID = 0;
        }
    }
}

extern int DAT_011f6bec;
extern int DAT_011f6bd4;

typedef void(__stdcall* FUN_00fdf054_t)(void*);
typedef void(__stdcall* FUN_00fdf05c_t)(void*);
typedef void(__stdcall* FUN_00fdf100_t)(void*);

extern FUN_00fdf054_t DAT_00fdf054;
extern FUN_00fdf05c_t DAT_00fdf05c;
extern FUN_00fdf100_t DAT_00fdf100;

int __cdecl FUN_00ec658f(void(__cdecl*)(void));
void __cdecl FUN_00fdb2b0(void);

struct FUN_00aa7300_Obj
{
    void MemoryPool_CheckFreeBlocks();
};

// @fnv 0x00aa7370
// src: COMMUNITY 0x00aa7370
void MemoryPool_CheckPools(void)
{
    if ((DAT_011f6bec & 1) == 0)
    {
        DAT_011f6bec = DAT_011f6bec | 1;
        DAT_00fdf054(&DAT_011f6bd4);
        FUN_00ec658f(FUN_00fdb2b0);
    }

    DAT_00fdf05c(&DAT_011f6bd4);

    for (int index = 0; index < 0x100; index = index + 1)
    {
        MemoryPool* pool = DAT_011f67b8[index];
        if (pool != 0)
        {
            reinterpret_cast<FUN_00aa7300_Obj*>(pool)->MemoryPool_CheckFreeBlocks();
        }
    }

    DAT_00fdf100(&DAT_011f6bd4);
}

extern "C" void(__stdcall* DAT_00fdf05c)(void*);
extern "C" void(__stdcall* DAT_00fdf100)(void*);
extern "C" void(__stdcall* DAT_00fdf1b4)(void*, int, int);
extern "C" void(__stdcall* DAT_00fdf1c0)(void*);
extern "C" void* DAT_011f6bfc;
extern "C" void* DAT_011f6bf4;

struct BlockSource
{
    virtual void v0();
    virtual void* v1();
};
extern "C" BlockSource* DAT_011f6c00;

struct BlockHolder
{
    void* m0;
    void* m4;
};

struct AllocBlock
{
    void* m0;
    void* m4;
    int m8;
    int mC;
};

struct FUN_00aa8b80_class;

// @fnv 0x00aa86b0
void __cdecl SetBlockValue(int aiValue)
{
    void* lock = DAT_011f6bfc;
    DAT_00fdf05c(lock);
    int a = aiValue;
    BlockSource* src2 = DAT_011f6c00;
    AllocBlock* aBlock = (AllocBlock*)src2->v1();
    aBlock->m8 = a;
    ((FUN_00aa8b80_class*)src2)->AppendBlock(aBlock);
    void* unlock2 = DAT_011f6bfc;
    DAT_00fdf100(unlock2);
    BlockHolder* holder5 = (BlockHolder*)DAT_011f6bf4;
    DAT_00fdf1b4(holder5->m4, 1, 0);
    DAT_00fdf1c0(holder5);
}

struct FUN_00aa8be0_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* item);
    void* m_04;
    void* m_08;
    void* m_0c;
    void __thiscall ClearList();
};

// Walks the linked list from m_04, calling v2 on each node, then resets m_0c, m_04 and m_08 to null.
// @fnv 0x00aa8be0
void __thiscall FUN_00aa8be0_cls::ClearList()
{
    void* node = m_04;
    while (node != 0)
    {
        void* cur = node;
        node = *(void**)node;
        v2(cur);
    }
    m_0c = 0;
    m_04 = 0;
    m_08 = 0;
}

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* cs);

extern "C" char DAT_010a28c8;
extern "C" char DAT_010a2bbc;

// The shared class has no constructor overload for these four arguments. Keep
// its initialization and teardown helpers here, using the shared layout.
struct AbstractHeapLifecycle : AbstractHeap
{
    AbstractHeap* Initialize(int a1, int a2, int a3, int a4);
    void Destroy();
};

// Sets the vtable and initializes fields from the four arguments, zeroes counters, initializes a critical section and returns this.
// @fnv 0x00aa8ca0
AbstractHeap* AbstractHeapLifecycle::Initialize(int a1, int a2, int a3, int a4)
{
    *(void**)this = &DAT_010a28c8;
    *(void**)this = &DAT_010a2bbc;
    pName = (const char*)a3;
    iDefaultAlignment = 4;
    iPageSize = a4;
    MemHeapSize = a1;
    iInitialSize = a2;
    iCurrentSize = a2;
    iWastedMemory = 0;
    iMemAllocated = 0;
    iMemAllocatedHigh = 0;
    iBlockMemAllocated = 0;
    pMemHeap = 0;
    iNumBlocks = 0;
    pBlockHead = 0;
    pBlockTail = 0;
    iNumFreeBlocks = 0;
    void* cs = CriticalSectionO;
    InitializeCriticalSection(cs);
    MinFreeBlockSize = (int)((char*)0 + 8) + 8;
    pDelayedFreeBlocksA = 0;
    iNextDelayedFreeIndex = 0;
    return this;
}

extern "C" void __cdecl FUN_00ec61c0(void* p, int value, unsigned int size);
extern "C" void __stdcall FUN_00eccec5(int code);

// @fnv 0x00aa8dd0
void AbstractHeap::ResetHeap()
{
    pMemHeap = (char*)AllocateHeapMemory(MemHeapSize, iCurrentSize);
    if (pMemHeap == 0)
        FUN_00eccec5(0);
    pLastSmallList = &pSmallFreeList[1023];
    int stride3 = 0x40;
    int i;
    for (i = 0; i < 0x10; i++)
    {
        pSubBuckets[i].iCount = 0;
        pSubBuckets[i].pFirst = (HeapFreeList*)((char*)pSmallFreeList + i * stride3 * 8);
    }
    FUN_00ec61c0(pSmallFreeList, 0, 0x2000);
    FUN_00ec61c0(&LargeFreeList, 0, 8);
}

struct FUN_00aa9d00_cls
{
    int unk00;
    void nullsub_318();
};

// @fnv 0x00aa9d00
// src: COMMUNITY 0x00aa9d00
void FUN_00aa9d00_cls::nullsub_318()
{}

struct FUN_00aaa720_cls
{
    int unk00;
    void nullsub_321();
};

// @fnv 0x00aaa720
// src: COMMUNITY 0x00aaa720
void FUN_00aaa720_cls::nullsub_321()
{}

struct FrameBlock40
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
};

struct FUN_00aaab30_base
{
    virtual ~FUN_00aaab30_base();
};

struct FUN_00aaab30_cls : FUN_00aaab30_base
{
    void unk04();
    virtual ~FUN_00aaab30_cls();
};

// Destructor that calls unk04() on the object.
// @fnv 0x00aaab30
FUN_00aaab30_cls::~FUN_00aaab30_cls()
{
    FrameBlock40 blk;
    this->unk04();
}

struct S_00aadd20_Vector
{
    float x;
    float y;
    float z;
    float w;
};

// @fnv 0x00aadd20
// src: GUESS 0x00aadd20 (confidence: low)
S_00aadd20_Vector* __cdecl Object_ComputeValue_00aadd20(S_00aadd20_Vector* out, S_00aadd20_Vector* in)
{
    float v = in->x * in->w - in->y * in->z;
    S_00aadd20_Vector r7;

    v = 1.0f / v;
    r7.x = in->w * v;
    r7.y = -in->y * v;
    r7.z = -in->z * v;
    r7.w = in->x * v;

    *out = r7;
    return out;
}

struct FUN_00aadda0_Class
{
    void __thiscall BuildScaledValues(int a, float b);
    int __thiscall BuildReciprocalScaledValues(int a, float b);
};

// Calls BuildScaledValues with the reciprocal of b, sets bit 0 of flags, and returns a.
// @fnv 0x00aadda0
// src: GUESS 0x00aadda0 (confidence: medium)
int FUN_00aadda0_Class::BuildReciprocalScaledValues(int a, float b)
{
    int flags = 0;
    BuildScaledValues(a, 1.0f / b);
    flags |= 1;
    return a;
}

// Candidate: FUN_00aafa30
struct FlagBox
{
    unsigned char v;
};
void __cdecl Object_ProcessEntries_00aafa80(int a0, int a1, int a2, int a3, unsigned char f4, unsigned char f5);

// @fnv 0x00aafa30
// src: GUESS 0x00aafa30 (confidence: low)
void __cdecl Runtime_UpdateState_00aafa30(int a0, int a1, int a2, int a3)
{
    FlagBox b0 = {};
    unsigned char qq;
    unsigned char cc = qq;
    int dd = a1;
    int n6 = a0;
    int n8;
    Object_ProcessEntries_00aafa80(n6, dd, a2, a3, cc, b0.v);
}

struct FUN_00aafbd0_cls
{
    int unk00;
    void __thiscall nullsub_320();
};
// @fnv 0x00aafbd0
// src: COMMUNITY 0x00aafbd0
void FUN_00aafbd0_cls::nullsub_320()
{}

struct FUN_00ab2630_cls
{
    int unk00;
    void nullsub_322();
};

// @fnv 0x00ab2630
// src: COMMUNITY 0x00ab2630
void FUN_00ab2630_cls::nullsub_322()
{}

struct FUN_00ab46e0_cls
{
    int unk00;
    void nullsub_323();
};

// @fnv 0x00ab46e0
// src: COMMUNITY 0x00ab46e0
void FUN_00ab46e0_cls::nullsub_323()
{}

// ---------------------------------------------------------------------------
// FUN_00abaf60 - pick one of two range handles out of a container.
//
// The container keeps a base pointer (m_pBase) and the byte offsets of the
// first and of the one-past-the-last element of an array of eight byte
// elements (m_i0c / m_i10).  A range handle is a pair of that base pointer
// and the byte offset of an element inside the array.
//
// The function gets two such handles (a and b) and copies the first one out
// through pOut.  Both handles are checked against the range of the container
// and are compared with each other; only when the two offsets are equal the
// new end of the container is computed and stored back.
//
// The build is unoptimised (/Od), so every value lives in its own frame slot.
// The names of the locals below are chosen so that the frame slots land on
// the offsets of the original (the compiler sorts the locals of an /Od frame
// by a hash of their name).
// ---------------------------------------------------------------------------

// A range handle: the base of the array and the byte offset of an element.
struct FnvAbaf60Iter
{
    void* m_pBase;
    unsigned int m_uiPosition;
    bool __thiscall ProcessAndReturnValue_00ac0460(FnvAbaf60Iter* pOther);
};

// A scratch block of 48 bytes.  Only its first two bytes are touched.
struct FnvAbaf60Block
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

// The container the range handles belong to.
struct FnvAbaf60Owner
{
    void* m_pBase;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    FnvAbaf60Iter* __thiscall ProcessEntries_00abaf60(FnvAbaf60Iter* pOut, FnvAbaf60Iter a, FnvAbaf60Iter b);
};

// The helper that turns two offsets into the offset of the element behind the
// last one of the range.
int __cdecl Runtime_EvaluateValue_00ac12d0(int nFirst, int nLast, int nExtra);

// @fnv 0x00abaf60
// src: GUESS 0x00abaf60 (confidence: low)
FnvAbaf60Iter* FnvAbaf60Owner::ProcessEntries_00abaf60(FnvAbaf60Iter* pOut, FnvAbaf60Iter aBegin, FnvAbaf60Iter aEnd)
{
    FnvAbaf60Iter itA;
    itA.m_pBase = 0;
    if (!this || this->m_i0c > aBegin.m_uiPosition || aBegin.m_uiPosition > this->m_i10)
        FUN_00ec7c56();
    itA.m_pBase = this->m_pBase;
    itA.m_uiPosition = aBegin.m_uiPosition;

    FnvAbaf60Iter itB;
    itB.m_pBase = 0;
    if (!this || this->m_i0c > aEnd.m_uiPosition || aEnd.m_uiPosition > this->m_i10)
        FUN_00ec7c56();
    itB.m_pBase = this->m_pBase;
    itB.m_uiPosition = aEnd.m_uiPosition;

    if (itA.ProcessAndReturnValue_00ac0460(&itB))
    {
        int nNew4 = Runtime_EvaluateValue_00ac12d0(itB.m_uiPosition, this->m_i10, itA.m_uiPosition);
        int nEnd4 = this->m_i10;
        int nLimit6 = nEnd4;
        int nBegin2 = nNew4;
        FnvAbaf60Block blockVal;
        blockVal.unk01 = blockVal.unk00;
        int bPCur = nBegin2;
        for (; bPCur != nLimit6; bPCur += 8)
        {
        }
        this->m_i10 = nNew4;
    }

    *pOut = itA;
    return pOut;
}

namespace fnv_00abc0a0 {
extern MemoryManager DAT_011f6238;

struct FUN_00abc0a0_pair
{
    unsigned int unk00;
    unsigned int unk04;
};

struct FUN_00abc0a0_small
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
};

struct FUN_00abc0a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    void std_vector_char_std_allocator_char_Tidy();
};

// @fnv 0x00abc0a0
// src: COMMUNITY 0x00abc0a0
void FUN_00abc0a0_cls::std_vector_char_std_allocator_char_Tidy()
{
    if (m_0c != 0)
    {
        FUN_00abc0a0_pair a;
        a.unk00 = m_10;
        a.unk04 = m_0c;
        FUN_00abc0a0_pair b_2 = a;
        FUN_00abc0a0_small s3;
        s3.unk03 = s3.unk02;
        unsigned int size = m_14 - m_0c;
        unsigned int p2 = m_0c;
        DAT_011f6238.Deallocate((void*)p2);
    }
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
}
}  // namespace fnv_00abc0a0

unsigned int __cdecl Object_ProcessAndReturnValue_00ac13c0(unsigned int b, unsigned int end, unsigned int a);

struct FUN_00abc180_Pair
{
    void* p;
    unsigned int i;
    bool Compare(FUN_00abc180_Pair* other);
};

struct FUN_00abc180_Tmp
{
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned char fC;
    unsigned char fD;
};

struct FUN_00abc180_Pad
{
    unsigned int g00, g04, g08, g0C, g10, g14, g18, g1C;
};

struct FUN_00abc180_cls
{
    void* m0;
    unsigned int m4;
    unsigned int m8;
    unsigned int mC;
    unsigned int m10;
    FUN_00abc180_Pair ProcessAndReturnValue_00abc180(unsigned int x, unsigned int a, unsigned int y, unsigned int b);
};

// Validates indices a and b against mC/m10, builds two pairs from m0, and if they compare, updates m10 via FUN_00ac13c0 and returns the first pair.
// @fnv 0x00abc180
// src: GUESS 0x00abc180 (confidence: low)
FUN_00abc180_Pair FUN_00abc180_cls::ProcessAndReturnValue_00abc180(unsigned int auiUnused, unsigned int auiIndexA,
                                                 unsigned int auiUnused2, unsigned int auiIndexB)
{
    FUN_00abc180_Pair p9;
    FUN_00abc180_Pair p2;
    unsigned int res4;
    FUN_00abc180_Pad pad;

    p9.p = 0;
    if (this == 0 || mC > auiIndexA || auiIndexA > m10)
    {
        FUN_00ec7c56();
    }
    p9.p = m0;
    p9.i = auiIndexA;
    p2.p = 0;
    if (this == 0 || mC > auiIndexB || auiIndexB > m10)
    {
        FUN_00ec7c56();
    }
    p2.p = m0;
    p2.i = auiIndexB;
    if (p9.Compare(&p2))
    {
        res4 = Object_ProcessAndReturnValue_00ac13c0(p2.i, m10, p9.i);
        FUN_00abc180_Tmp t;
        t.f0 = m10;
        t.f4 = t.f0;
        t.f8 = res4;
        t.fD = t.fC;
        m10 = res4;
    }
    return p9;
}

extern "C" void __cdecl Object_Length_error_Thunk(void);
extern "C" unsigned int* __cdecl Object_AllocateCheckedWords(unsigned int count, unsigned int zero);
struct FUN_00abc260_frame
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
};
struct FUN_00abc260_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int* m_0c;
    unsigned int* m_10;
    unsigned int* m_14;
    bool AllocateZeroedElementStorage(unsigned int count);
};

// Clears the three pointers, then allocates count zeroed elements and sets m_0c/m_10/m_14 to begin/begin/end; returns false when count is 0.
// @fnv 0x00abc260
// src: GUESS 0x00abc260 (confidence: medium)
bool FUN_00abc260_cls::AllocateZeroedElementStorage(unsigned int count)
{
    unsigned int cap;
    FUN_00abc260_frame buf;
    this->m_0c = 0;
    this->m_10 = 0;
    this->m_14 = 0;
    if (count == 0)
    {
        return false;
    }
    else
    {
        cap = 0x3fffffff;
        if ((cap > 0 ? cap : 1) < count)
        {
            Object_Length_error_Thunk();
        }
        else
        {
            this->m_0c = Object_AllocateCheckedWords(count, 0);
            this->m_10 = this->m_0c;
            this->m_14 = this->m_0c + count;
        }
    }
    return true;
}

struct FUN_00aa6650_Class
{
    bool __thiscall FreeMemory(unsigned int size, void* p);
};
// Releases the memory block at p with VirtualFree using MEM_DECOMMIT and returns whether the call succeeded.
// @fnv 0x00aa6650
bool FUN_00aa6650_Class::FreeMemory(unsigned int size, void* pMemory)
{
    return VirtualFree(pMemory, 0x1000, 0x4000) != 0;
}

struct FUN_00aa7300_node
{
    int m_00;
    FUN_00aa7300_node* m_04;
};

struct FUN_00aa7300_pool
{
    int m_00;
    int m_04;
    void BSSpinLock_Lock(const char* name);
};

class FUN_00aa7300_cls
{
  public:
    int m_00;
    int m_04;
    FUN_00aa7300_node* m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    FUN_00aa7300_pool m_20;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    unsigned int m_40;

    void MemoryPool_CheckFreeBlocks();
};

// @fnv 0x00aa7300
// src: COMMUNITY 0x00aa7300
void FUN_00aa7300_cls::MemoryPool_CheckFreeBlocks()
{
    int scratch0;
    int scratch1;
    FUN_00aa7300_node* cur;
    m_20.BSSpinLock_Lock((const char*)"CheckFreeBlocks");
    if (m_40 > 8)
    {
        cur = m_08;
        while (cur != 0)
        {
            cur = cur->m_04;
        }
    }
    {
        FUN_00aa7300_pool* pool = &m_20;
        pool->m_04 = pool->m_04 - 1;
        if (pool->m_04 == 0)
        {
            pool->m_00 = 0;
        }
    }
}

struct CounterA
{
    long count;
    void* event;
};
struct NodeA
{
    NodeA* next;
    NodeA* prev;
    void* value;
};
struct JobA
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    CounterA* completion;
};
struct QueueA
{
    virtual void v0();
    virtual NodeA* Allocate();
    void AppendBlock(NodeA* node);
};
struct PoolA
{
    virtual void v0();
    virtual NodeA* Allocate();
    virtual void FreeNode(NodeA* node);
    CounterA* FUN_00aa8a80();
    void PushFront(NodeA* node);
};
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);
extern "C" void(__stdcall* DAT_00fdf1c8)(void*, int);
extern PoolA* DAT_011f6c04;

// @fnv 0x00aa8740
void __cdecl CompleteJob(JobA* job)
{
    JobA* value;
    {
        void* lock = DAT_011f6bfc;
        DAT_00fdf05c(lock);
        job->completion = DAT_011f6c04->FUN_00aa8a80();
        value = job;
        {
            QueueA* queue = (QueueA*)DAT_011f6c00;
            NodeA* tail = queue->Allocate();
            int p;
            int ptr;
            tail->value = value;
            queue->AppendBlock(tail);
        }
    }
    {
        void* unlock = DAT_011f6bfc;
        DAT_00fdf100(unlock);
    }
    {
        CounterA* semaphore = (CounterA*)DAT_011f6bf4;
        DAT_00fdf1b4(semaphore->event, 1, 0);
        DAT_00fdf1c0(semaphore);
    }
    {
        CounterA* completion = job->completion;
        DAT_00fdf1c8(completion->event, -1);
        DAT_00fdf1c4(completion);
    }
    {
        void* lock2 = DAT_011f6bfc;
        DAT_00fdf05c(lock2);
        {
            PoolA* pool = DAT_011f6c04;
            NodeA* freeNode = pool->Allocate();
            freeNode->value = job->completion;
            pool->PushFront(freeNode);
        }
    }
    {
        void* unlock2 = DAT_011f6bfc;
        DAT_00fdf100(unlock2);
    }
}

struct S_0044a730_Class
{
    void fopen_0044a730(int a, int b);
};

struct S_00aba220_Class
{
    int unk00;
    float unk04;
    float unk08;
    float unk0c;
    S_0044a730_Class unk10;

    S_00aba220_Class* ProcessAndReturnValue_00aba220();
};

// Clears the three floats at unk04 and calls FUN_0044a730(0, 0) on the embedded object at offset 0x10, then returns this.
// @fnv 0x00aba220
// src: GUESS 0x00aba220 (confidence: low)
S_00aba220_Class* S_00aba220_Class::ProcessAndReturnValue_00aba220()
{
    long child;
    unsigned int tmp;
    unsigned int s;
    int v;
    int c;
    int unk14;

    float* p;
    p = &this->unk04;

    p[0] = 0.0f;
    p[1] = 0.0f;
    p[2] = 0.0f;

    S_0044a730_Class* unk0c = reinterpret_cast<S_0044a730_Class*>(reinterpret_cast<char*>(this) + 0x10);

    char i;
    char* unk08;
    unk08 = &i;

    unk0c->fopen_0044a730(0, 0);

    return this;
}

struct FUN_00aa6800_class
{
    void __thiscall FUN_00aa6800();
};

// @fnv 0x00aa68a0
void __cdecl DestroyMemoryPools()
{
    unsigned int i;

    for (i = 0; i < 0x100; i++)
    {
        MemoryPool* _pool;
        MemoryPool* tmp;
        MemoryPool* result;

        tmp = DAT_011f67b8[i];
        _pool = tmp;
        if (_pool != 0)
        {
            reinterpret_cast<FUN_00aa6800_class*>(_pool)->FUN_00aa6800();
            // Inlined bool-policy helper from the original (unit is really /Ob1): the flag survives as an int temp.
            if ((_pool, 1) & 1)
            {
                DAT_011f6238.Deallocate(_pool);
            }
            result = _pool;
        }
        else
        {
            result = 0;
        }
        DAT_011f67b8[i] = 0;
    }
}

extern unsigned int DAT_010173f0;
extern "C" void __cdecl _Xlen(void);

class S_00aadeb0_Class
{
  public:
    unsigned int m_00;
    char* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;

    S_00aadeb0_Class* AppendChars(unsigned int count, unsigned char ch);
};

struct S_00aae180_Class
{
    void __thiscall WriteBufferValue(unsigned int pos, unsigned int count, unsigned char ch);
};

struct S_0044a8d0_Class
{
    bool __thiscall std_basic_string_char_std_char_traits_char_std_allocator_char_Grow(unsigned int newSize, int reserve);
};

struct S_00aadeb0_pad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

// Appends count copies of ch to the string, growing the buffer and null-terminating it, and returns this.
// @fnv 0x00aadeb0
S_00aadeb0_Class* S_00aadeb0_Class::AppendChars(unsigned int count, unsigned char ch)
{
    S_00aadeb0_pad pad;
    unsigned int newsize;
    __declspec(align(4)) unsigned char zero;

    if (DAT_010173f0 - m_14 <= count)
        _Xlen();
    if (count > 0)
    {
        newsize = m_14 + count;
        if (((S_0044a8d0_Class*)this)->std_basic_string_char_std_char_traits_char_std_allocator_char_Grow(newsize, 0))
        {
            ((S_00aae180_Class*)this)->WriteBufferValue(m_14, count, ch);
            zero = 0;
            m_14 = newsize;
            (m_18 >= 16 ? m_04 : (char*)this + 4)[newsize] = zero;
        }
    }
    return this;
}

extern double DAT_01016ff0;

double GenerateGaussianRandom();

struct FaceGenCoordinateValue
{
    float* data;
    void* owner;
};

struct FaceGenCoordinateBasis
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;
    FaceGenCoordinateValue* ForwardCall_0060b370(FaceGenCoordinateValue* out, int index);
    void std_vector_float_std_allocator_float_resize_0060b410(unsigned int count, float value);
};

struct FaceGenBasisOwner
{
    void ProcessEntries_00aad500(float scale, FaceGenCoordinateBasis (*src)[2], FaceGenCoordinateBasis (*dst)[2]);
};

// @fnv 0x00aad500
// src: GUESS 0x00aad500 (confidence: low)
void FaceGenBasisOwner::ProcessEntries_00aad500(float scale, FaceGenCoordinateBasis (*src)[2], FaceGenCoordinateBasis (*dst)[2])
{
    int pad2;
    int i8;
    int jB;
    int k4;
    int m6;
    double deltaDM;
    unsigned int colsK8;
    FaceGenCoordinateValue basisOut;
    FaceGenCoordinateValue dstValueY4;
    unsigned int rowsKG;
    FaceGenCoordinateBasis* nRows6;
    unsigned int basisPtrD;
    unsigned int colCountA;
    int tmpA;
    FaceGenCoordinateValue* basisIn;
    int pad1;
    float* from;
    FaceGenCoordinateValue* dstPtrULen;
    int tmpD;

    for (i8 = 0; i8 < 2; i8++)
    {
        for (jB = 0; jB < 2; jB++)
        {
            colsK8 = ((FaceGenCoordinateBasis*)((char*)src + ((jB << 5) + (i8 << 6))))->m_uiColumnCount;
            rowsKG = ((FaceGenCoordinateBasis*)((char*)src + ((jB << 5) + (i8 << 6))))->m_uiRowCount;
            nRows6 = ((FaceGenCoordinateBasis*)((char*)dst + ((jB << 5) + (i8 << 6))));
            nRows6->m_uiRowCount = rowsKG;
            nRows6->m_uiColumnCount = colsK8;
            nRows6->std_vector_float_std_allocator_float_resize_0060b410(rowsKG * colsK8, 0.0f);
            for (k4 = 0;
                 k4 < (basisPtrD = ((FaceGenCoordinateBasis*)((char*)src + ((jB << 5) + (i8 << 6))))->m_uiRowCount);
                 k4++)
            {
                for (m6 = 0;
                     m6 <
                     (colCountA = ((FaceGenCoordinateBasis*)((char*)src + ((jB << 5) + (i8 << 6))))->m_uiColumnCount);
                     m6++)
                {
                    deltaDM = GenerateGaussianRandom() * scale * DAT_01016ff0;
                    basisIn =
                        ((FaceGenCoordinateBasis*)((char*)src + ((jB << 5) + (i8 << 6))))->ForwardCall_0060b370(&basisOut, k4);
                    from = &basisIn->data[m6];
                    dstPtrULen = ((FaceGenCoordinateBasis*)((char*)dst + ((jB << 5) + (i8 << 6))))
                                     ->ForwardCall_0060b370(&dstValueY4, k4);
                    dstPtrULen->data[m6] = *from + deltaDM;
                }
            }
        }
    }
}

// FUN_00ab23c0: fills a run of 6-byte elements, rolling back on exception
struct FillElem6
{
    unsigned short m_00;
    unsigned short m_02;
    unsigned short m_04;
};

// @fnv 0x00ab23c0
// src: GUESS 0x00ab23c0 (confidence: low)
void __cdecl Object_ProcessEntries_00ab23c0(char* first, unsigned int count, const FillElem6* val)
{
    char* start = first;
    try
    {
        for (; 0 < count; --count, first += 6)
        {
            char* p = first;
            char* q = p;
            char* r;
            if (q != 0)
            {
                *(FillElem6*)q = *val;
                r = q;
            }
            else
            {
                r = 0;
            }
        }
    }
    catch (...)
    {
        for (; start != first; start += 6)
        {
        }
        throw;
    }
}

struct FUN_00aba9a0_pair
{
    unsigned int a;
    unsigned int b;
    bool ProcessAndReturnValue_00ac0460(FUN_00aba9a0_pair* other);
};

struct __declspec(align(4)) FUN_00aba9a0_iter
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned char m_10;
    unsigned char m_11;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
};

struct FUN_00aba9a0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    FUN_00aba9a0_pair* ProcessEntries_00aba9a0(FUN_00aba9a0_pair* out, unsigned int unk0c, unsigned int a, unsigned int unk14,
                                    unsigned int b);
};

extern "C" unsigned int __cdecl Runtime_EvaluateValue_00ac1170(unsigned int, unsigned int, unsigned int);

// @fnv 0x00aba9a0
// src: GUESS 0x00aba9a0 (confidence: low)
FUN_00aba9a0_pair* FUN_00aba9a0_cls::ProcessEntries_00aba9a0(FUN_00aba9a0_pair* out, unsigned int unk0c, unsigned int a,
                                                  unsigned int uiUnused, unsigned int b)
{
    FUN_00aba9a0_pair p9;
    FUN_00aba9a0_pair p2;
    unsigned int r;
    FUN_00aba9a0_iter it9;

    p9.a = 0;
    if (this == 0 || this->m_0c > a || a > this->m_10)
    {
        FUN_00ec7c56();
    }
    p9.a = this->m_00;
    p9.b = a;
    p2.a = 0;
    if (this == 0 || this->m_0c > b || b > this->m_10)
    {
        FUN_00ec7c56();
    }
    p2.a = this->m_00;
    p2.b = b;
    if (p9.ProcessAndReturnValue_00ac0460(&p2))
    {
        r = Runtime_EvaluateValue_00ac1170(p2.b, this->m_10, p9.b);
        it9.m_00 = this->m_10;
        it9.m_04 = it9.m_00;
        it9.m_08 = r;
        it9.m_11 = it9.m_10;
        for (it9.m_0c = it9.m_08; it9.m_0c != it9.m_04; it9.m_0c += 12)
        {
        }
        this->m_10 = r;
    }
    *out = p9;
    return out;
}

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* handle);

extern MemoryManager DAT_011f6238;
void* __stdcall FUN_00ec5fce(void* base, unsigned int size, unsigned int count, void(__cdecl* destructor)(void*));
void __cdecl ForwardCall_0055a2d0(void* element);

struct VectorOwnedItem
{
    void* vtable;
    void* handle;
    void* other;
    void* __thiscall FUN_00aa8850(unsigned int flags);
};

// If flags & 2 runs FUN_00ec5fce over the array elements, else closes handle; with flags & 1 deallocates the block via DAT_011f6238; returns the block pointer.
// @fnv 0x00aa8850
void* VectorOwnedItem::FUN_00aa8850(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 12, ((unsigned int*)this)[-1], ForwardCall_0055a2d0);
        if (flags & 1)
            DAT_011f6238.Deallocate((char*)this - 4);
        return (char*)this - 4;
    }
    CloseHandle(handle);
    if (flags & 1)
        DAT_011f6238.Deallocate(this);
    return this;
}

void __cdecl FUN_00ec61c0(char* dst, int value, int size);

class FUN_00aae180_cls
{
  public:
    int m_00;
    char* m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    unsigned int m_18;

    void WriteBufferValue(int offset, int flag, char value);
};

// Writes value at offset in the buffer (inline below 0x10 else m_04): one byte if flag is 1, otherwise flag bytes via FUN_00ec61c0.
// @fnv 0x00aae180
// src: GUESS 0x00aae180 (confidence: medium)
void FUN_00aae180_cls::WriteBufferValue(int offset, int aiSize, char value)
{
    if (aiSize == 1)
    {
        *((m_18 >= 0x10 ? m_04 : (char*)this + 4) + offset) = value;
    }
    else
    {
        char tmp;
        FUN_00ec61c0((m_18 >= 0x10 ? m_04 : (char*)this + 4) + offset, tmp = value, aiSize);
    }
}

void __cdecl Object_ProcessAndReturnValue_00aaf9a0(int, int, int, FlagBox, FlagBox, FlagBox);

// Zero-initializes f3, copies an uninitialized FlagBox into f2, and calls FUN_00aaf9a0 with a1, a2, a3, a4, f2 and f3.
// @fnv 0x00aaf860
// src: GUESS 0x00aaf860 (confidence: low)
void __cdecl Object_UpdateFields_00aaf860(int a1, int a2, int a3, FlagBox a4)
{
    FlagBox f3 = {};
    FlagBox f2;
    FlagBox f1;
    f2 = f1;
    int CNVal;
    int CN_;
    int Diff2;
    int Diff_;
    int EndLoc_2;
    int EntryLoc;
    int EntryLocA;
    int EntryLocTmp;
    int LeftB;
    int PN4;
    int PNA;
    int StartLoc2;
    int StartLoc7;
    int _AngleYawB;
    int _Dest5;
    int _DestVal;
    int _Dest_;
    int _Diff2;
    int _Dir;
    int _DirZNew;
    int _DirZVal;
    int _DirZ_;
    int _FYaw6;
    int _FYaw9;
    int _FuturePhase6;
    int _FuturePhaseTmp;
    Object_ProcessAndReturnValue_00aaf9a0(a1, a2, a3, a4, f2, f3);
}

extern "C" void __cdecl Object_ProcessAndReturnValue_00ab2580(int a, int b, int c, unsigned char d, bool e, bool f);

struct ZeroTag
{
    bool v;
};

// Zero-initializes tagB, copies an uninitialized bool into tagA, and calls FUN_00ab2580 with a, b, c, d, tagA and tagB.v.
// @fnv 0x00ab2380
// src: GUESS 0x00ab2380 (confidence: low)
void __cdecl Object_UpdateFields_00ab2380(int a, int b, int c, unsigned char d)
{
    ZeroTag tagB = {};
    bool tagA;
    bool src;
    tagA = src;
    unsigned int a0;
    unsigned int a6;
    unsigned int aa2;
    unsigned int act2;
    unsigned int act6;
    unsigned int adj1;
    unsigned int adj5;
    unsigned int adj51;
    unsigned int adj53;
    unsigned int adj64;
    unsigned int adj9;
    unsigned int ae2;
    unsigned int af5;
    unsigned int age2;
    unsigned int age6;
    unsigned int all3;
    unsigned int all7;
    unsigned int an4;
    unsigned int an7;
    unsigned int arr57;
    unsigned int arr84;
    unsigned int aux4;
    unsigned int aux8;
    unsigned int b1;
    unsigned int b141;
    unsigned int b145;
    unsigned int b149;
    unsigned int b49;
    unsigned int bip2;
    unsigned int bip6;
    unsigned int blk5;
    unsigned int blk9;
    unsigned int box4;
    unsigned int box8;
    unsigned int bp1;
    unsigned int bs2;
    unsigned int buf1;
    unsigned int buf16;
    unsigned int buf18;
    unsigned int buf43;
    unsigned int buf45;
    unsigned int buf48;
    unsigned int buf5;
    unsigned int buf9;
    unsigned int cat2;
    unsigned int cat6;
    unsigned int cb2;
    unsigned int cf7;
    unsigned int ch3;
    unsigned int ch8;
    unsigned int cj2;
    unsigned int cnt140;
    unsigned int cnt27;
    unsigned int cnt29;
    unsigned int cnt52;
    unsigned int cs2;
    unsigned int ctx19;
    unsigned int ctx28;
    unsigned int ctx40;
    unsigned int ctx50;
    unsigned int ctx61;
    unsigned int cx7;
    unsigned int cx9;
    unsigned int cy6;
    unsigned int d1;
    unsigned int d7;
    unsigned int dbc10;
    unsigned int dbc17;
    unsigned int dbc46;
    unsigned int dbc48;
    unsigned int dbc57;
    unsigned int dd1;
    unsigned int dev511;
    unsigned int dev538;
    unsigned int dev551;
    unsigned int dev59;
    unsigned int df1;
    unsigned int dh1;
    unsigned int dn9;
    unsigned int dp2;
    unsigned int dq2;
    Object_ProcessAndReturnValue_00ab2580(a, b, c, d, tagA, tagB.v);
}

struct ContainerAux;
struct Aux
{
    const ContainerAux* container;
};
struct ContainerAux
{
    Aux* proxy;
};
template <class T> struct GameAllocator
{
    GameAllocator()
    {}
    template <class U> GameAllocator(const GameAllocator<U>&)
    {}
    void deallocate(T* p, unsigned int);
};
template <class T> struct ProxyBase : ContainerAux
{
    GameAllocator<Aux> auxAllocator;
};
template <class T> struct VectorVal : ProxyBase<T>
{
    GameAllocator<T> allocator;
};
void __cdecl Object_ProcessState_00ac16e0(char* ptr, unsigned int count, const char& val, GameAllocator<char>& al);
struct FUN_00aba0d0 : VectorVal<char>
{
    char* first;
    char* last;
    char* limit;
    bool ProcessAndReturnValue_00ac03a0(unsigned int count);
    void std_vector_char_std_allocator_char_Tidy();
    void InitializeFilledElements(unsigned int count, const char& val);
};
// If FUN_00ac03a0(count) succeeds, fills count copies of val from first and sets last to first + count; on exception calls FUN_00abc0a0 and rethrows.
// @fnv 0x00abbfc0
// src: GUESS 0x00abbfc0 (confidence: medium)
void FUN_00aba0d0::InitializeFilledElements(unsigned int count, const char& val)
{
    if (ProcessAndReturnValue_00ac03a0(count))
    {
        try
        {
            unsigned int a0, a114, a1c5, a1c9, a2, a3, a6;
            unsigned int a148, aa, aabb5, ab4, ab9, above8, action40, action44, action48, action70, action74, action78,
                active8, actor15, actor20, actor22, actor23, actor30, actor41, actor57, actor59, actor66, actor85,
                actor90, adj30, af4, ah6, ai7, aim5, aim9, aimed1, aimed100, aimed104, aimed108, aimed17, aimed28,
                aimed49, aimed59;
            char* filled = first;
            Object_ProcessState_00ac16e0(filled, count, val, allocator);
            last = filled + count;
        }
        catch (...)
        {
            std_vector_char_std_allocator_char_Tidy();
            throw;
        }
    }
}

struct Basis_006581e0
{
    int unk00[8];
    void FUN_006581e0(const Basis_006581e0* other);
};

struct String_0044a580
{
    int unk00[7];
    void AssignSubstring(const String_0044a580* other, unsigned int pos, unsigned int count);
};

struct Element_00aaf6f0
{
    Basis_006581e0 m00;
    String_0044a580 m20;
};

extern unsigned int DAT_010173f0;

// For each element in [first, last), applies FUN_006581e0 with val's m00 and assigns a substring of val's m20 (from 0, DAT_010173f0 chars).
// @fnv 0x00aaf6f0
// src: GUESS 0x00aaf6f0 (confidence: medium)
void Runtime_AssignRangeElementStrings(Element_00aaf6f0* first, Element_00aaf6f0* last, const Element_00aaf6f0* val)
{
    char pad[73];
    int a;
    Element_00aaf6f0* end = last;
    for (Element_00aaf6f0* cur = first; cur != end; ++cur)
    {
        cur->m00.FUN_006581e0(&val->m00);
        cur->m20.AssignSubstring(&val->m20, 0, DAT_010173f0);
    }
}

namespace fnv_00aa6590 {
#include <windows.h>

// Wrapper that hands the caller's exit code to the Win32 ExitThread import.
struct FUN_00aa6590_cls
{
    int unk00;
    void __thiscall ForwardCall_00aa6590(unsigned int exitCode, int unused);
};

// @fnv 0x00aa6590
// src: GUESS 0x00aa6590 (confidence: low)
void __thiscall FUN_00aa6590_cls::ForwardCall_00aa6590(unsigned int exitCode, int unused)
{
    ExitThread(exitCode);
}
}  // namespace fnv_00aa6590

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* cs);
extern "C" char DAT_010a28c8;
extern "C" char DAT_010a2bbc;

// @fnv 0x00aa8da0
void AbstractHeapLifecycle::Destroy()
{
    *(void**)this = &DAT_010a2bbc;
    DeleteCriticalSection(CriticalSectionO);
    *(void**)this = &DAT_010a28c8;
}

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned int, unsigned long, unsigned long);

class VirtualReservationSearch
{
  public:
    unsigned int m_00;
    void* m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3C;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4C;
    unsigned int m_50;
    void MemoryPool_PlatformReserveHeap();
};

// @fnv 0x00aa65b0
// src: COMMUNITY 0x00aa65b0
void VirtualReservationSearch::MemoryPool_PlatformReserveHeap()
{
    unsigned int i = 1;
    while (m_04 == 0)
    {
        m_04 = VirtualAlloc((void*)(i << 24), m_50, 0x2000, 4);
        if (i < 0xff)
        {
            i++;
        }
        else
        {
            break;
        }
    }
}

extern unsigned int DAT_011f6bd0;
extern _RTL_CRITICAL_SECTION DAT_011f6bb8;

void __fastcall MemoryPool_FreeUnusedPagesForAllPools(MemoryPool* pPool);
void __cdecl FUN_00fdb2a0();
int FUN_00ec658f(void(__cdecl* fn)());

// Initializes the lock on first call, then under the lock calls FUN_00aa6f90 on each non-null entry of the 256-entry table DAT_011f67b8.
// @fnv 0x00aa7030
// src: COMMUNITY 0x00aa7030
void MemoryPool_FreeUnusedPagesForAllPools_00aa7030()
{
    if ((DAT_011f6bd0 & 1) == 0)
    {
        DAT_011f6bd0 |= 1;
        InitializeCriticalSection(&DAT_011f6bb8);
        FUN_00ec658f(FUN_00fdb2a0);
    }
    DAT_00fdf05c(&DAT_011f6bb8);
    for (unsigned int i = 0; i < 0x100; i++)
    {
        if (DAT_011f67b8[i] != 0)
        {
            MemoryPool_FreeUnusedPagesForAllPools(DAT_011f67b8[i]);
        }
    }
    DAT_00fdf100(&DAT_011f6bb8);
}

__declspec(dllimport) int __stdcall QueryPerformanceCounter(FNVInt64* counter);

// Reads the high-resolution performance counter via QueryPerformanceCounter and returns the raw tick value.
// @fnv 0x00aa4d80
// src: COMMUNITY 0x00aa4d80
unsigned long long BSPrecisionTimer_GetTimer()
{
    FNVInt64 counter = 0;
    QueryPerformanceCounter(&counter);
    return counter;
}
