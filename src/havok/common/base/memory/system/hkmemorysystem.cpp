
// src/havok/common/base/memory/system/hkmemorysystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/system/hkmemorysystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkThreadMemory.h"

// @fnv 0x00cbc440
int __stdcall FUN_00cbc440(int a, int b)
{
    return 1;
}

extern int DAT_01268418;

// @fnv 0x00cbbfc0
int FUN_00cbbfc0()
{
    return DAT_01268418;
}

extern int g_CBBFD0Value;

// @fnv 0x00cbbfd0
int __cdecl FUN_00cbbfd0()
{
    return g_CBBFD0Value;
}

extern int DAT_010c8efc;

struct FUN_00cbbfe0_This
{
    int unk00;
    void __thiscall FUN_00cbbfe0();
};

// @fnv 0x00cbbfe0
void FUN_00cbbfe0_This::FUN_00cbbfe0()
{
    this->unk00 = reinterpret_cast<int>(&DAT_010c8efc);
}

// FUN_00cbc450 - 10 bytes
//   call 0xcbbfe0
//   mov eax, ecx
//   ret 4
//
// The callee FUN_00cbbfe0 is DEFINED here (stand-in) because MSVC must be able
// to see that it leaves ECX untouched: the original returns `this` in EAX right
// after the call, so `this` has to stay live in ECX across it.  Declaring the
// helper only would make MSVC spill `this` to a callee-saved register.
//
// The stand-in body is behaviourally equivalent to the original callee
// (0x00cbbfe0 = "mov dword ptr [ecx], 0x010c8efc ; ret"): it stores the class
// vtable pointer into the object and returns, never touching ECX.

struct VTable
{
    void* entries[4];
};

extern void FUN_00cbbfe0_dummy();

static const VTable g_vtbl = {
    {(void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy}};

struct MyCls
{
    const VTable* m_vtbl;
    __declspec(noinline) void FUN_00cbbfe0();
    MyCls* FUN_00cbc450(int arg);
};

void MyCls::FUN_00cbbfe0()
{
    m_vtbl = &g_vtbl;
}

// @fnv 0x00cbc450
MyCls* MyCls::FUN_00cbc450(int arg)
{
    FUN_00cbbfe0();
    return this;
}

// @fnv 0x00cbbff0
void __cdecl FUN_00cbbff0()
{}

void __cdecl FUN_00cc0410(int handle, const char* fmt, ...);
extern const char str_010c9078[];
extern const char str_010c9058[];
extern const char str_010c902c[];
extern const char str_010c900c[];
extern const char str_010c8fe0[];
extern const char str_010c8fc0[];
extern const char str_010c8f94[];
extern const char str_010c8f68[];
extern const char str_010c8f3c[];

template <class T> inline T S00cbc000_max(T a, T b)
{
    return a > b ? a : b;
}
struct S00cbc000_Stats
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

// Formats values derived from S00cbc000_Stats and limit through FUN_00cc0410.
// @fnv 0x00cbc000
static __declspec(noinline) void FUN_00cbc000(S00cbc000_Stats* apStats, unsigned int limit, int handle,
                                              const char* name)
{
    unsigned int total = S00cbc000_max(apStats->unk00, apStats->unk04);
    int diff = total - apStats->unk04 - apStats->unk0c;
    float fDiff = (float)diff;
    unsigned int sum = apStats->unk04 + apStats->unk0c;
    float fRatio = fDiff / (float)sum;
    if (limit == 0 || limit == 0x7fffffff)
        limit = total;
    float fLimit = (float)limit;
    unsigned int comp = (unsigned int)((1.0f - fRatio) * fLimit);
    unsigned int reserved = total - limit;
    unsigned int soft = limit < comp ? limit : comp;
    float invPct = (float)(100.0 / (float)soft);
    FUN_00cc0410(handle, str_010c9078, name);
    FUN_00cc0410(handle, str_010c9058, total);
    if (limit < total)
    {
        FUN_00cc0410(handle, str_010c902c, reserved, (double)(((float)reserved * 100.0) / (float)comp));
        FUN_00cc0410(handle, str_010c900c, limit);
    }
    FUN_00cc0410(handle, str_010c8fe0, diff, (double)((fDiff * 100.0) / fLimit));
    FUN_00cc0410(handle, str_010c8fc0, comp);
    FUN_00cc0410(handle, str_010c8f94, apStats->unk04, (double)((float)apStats->unk04 * invPct));
    FUN_00cc0410(handle, str_010c8f68, apStats->unk0c, (double)((float)apStats->unk0c * invPct));
    FUN_00cc0410(handle, str_010c8f3c, apStats->unk08, (double)((float)apStats->unk08 * invPct));
}

void S00cbc000_Caller(S00cbc000_Stats* s, int handle, unsigned int limit, const char* name)
{
    FUN_00cbc000(s, limit, handle, name);
}

struct hkOstream;
int __cdecl FUN_00cc0410(hkOstream* ostr, const char* fmt, ...);

struct SixUnsignedValueRecord
{
    unsigned int m_uiFirstValue;
    unsigned int m_pAllocationMap;
    unsigned int m_uiThirdValue;
    unsigned int m_uiFourthUnsignedValue;
    unsigned int GetFifthValue;
    unsigned int GetSixthValue;
    SixUnsignedValueRecord()
        : m_uiFirstValue(0), m_pAllocationMap(0), m_uiThirdValue(0), m_uiFourthUnsignedValue(0), GetFifthValue(0),
          GetSixthValue(0)
    {}
};

#include "../../../../../../include/hkStackMemory.h"

#include "../../../../../../include/hkArray.h"

struct MemSystemInfo
{
    hkMemoryAllocator* m_pStreamAllocator;
    hkArray<hkThreadMemory*> m_threadMemory;
    hkArray<hkStackMemory*> m_kAllocatorList;
    int m_stackTotal;
    int m_heapSoftLimit;
};

struct AllocatorHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkMemoryAllocator* m_pAllocator;
    hkMemoryAllocator* m_pSolverAllocator;
    hkMemoryAllocator& debugAllocator()
    {
        return *m_pAllocator;
    }
    hkMemoryAllocator& solverAllocator()
    {
        return *m_pSolverAllocator;
    }
};
AllocatorHolder* __cdecl FUN_00c85750();

namespace MathUtilities {
template <typename T> inline T max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> inline T min2(T x, T y)
{
    return x < y ? x : y;
}
}

static __declspec(noinline) void FUN_00cbc000(hkOstream* ostr, const char* name, const SixUnsignedValueRecord& s,
                                              unsigned int softLimit)
{
    unsigned int total = MathUtilities::max2(s.m_uiFirstValue, s.m_pAllocationMap);
    int overhead = total - s.m_pAllocationMap - s.m_uiFourthUnsignedValue;
    float fOverhead = (float)overhead;
    float overheadRatio = fOverhead / (float)(s.m_pAllocationMap + s.m_uiFourthUnsignedValue);
    if (softLimit == 0 || softLimit == 0x7fffffff)
        softLimit = total;
    float fLimit = (float)softLimit;
    unsigned int available = (unsigned int)((1.0f - overheadRatio) * fLimit);
    unsigned int reserved = total - softLimit;
    unsigned int avail = MathUtilities::min2(softLimit, available);
    float scale = (float)(100.0 / avail);
    FUN_00cc0410(ostr, "\t%s:\n", name);
    FUN_00cc0410(ostr, "            totalSize:   %10i\n", total);
    if (softLimit < total)
    {
        FUN_00cc0410(ostr, "\n            - reserved:  %10i (%4.1f%%)\n", reserved, reserved * 100.0 / available);
        FUN_00cc0410(ostr, "            = softlimit: %10i\n", softLimit);
    }
    FUN_00cc0410(ostr, "            - overhead:  %10i (%4.1f%%)\n", overhead, fOverhead * 100.0 / fLimit);
    FUN_00cc0410(ostr, "            = available: %10i\n", available);
    FUN_00cc0410(ostr, "              used:      %10i (%4.1f%%)\n", s.m_pAllocationMap, s.m_pAllocationMap * scale);
    FUN_00cc0410(ostr, "              free:      %10i (%4.1f%%)\n", s.m_uiFourthUnsignedValue,
                 s.m_uiFourthUnsignedValue * scale);
    FUN_00cc0410(ostr, "              peak:      %10i (%4.1f%%)\n\n", s.m_uiThirdValue, s.m_uiThirdValue * scale);
}

// Writes heap, thread, stack, solver, and debug memory statistics to ostr using info and FUN_00cbc000.
// @fnv 0x00cbc220
void __stdcall FUN_00cbc220(hkOstream* ostr, MemSystemInfo* info)
{
    SixUnsignedValueRecord stats;
    info->m_pStreamAllocator->getMemoryStatistics(reinterpret_cast<hkMemoryAllocator::MemoryStatistics&>(stats));
    unsigned int heapInUse = stats.m_pAllocationMap;
    FUN_00cbc000(ostr, "Heap", stats, info->m_heapSoftLimit);

    FUN_00cc0410(ostr, "\tThreadMemory (=CachedHeapMemory)\n");
    int total = 0;
    for (int i = 0; i < info->m_threadMemory.GetLogicalSize(); i++)
    {
        unsigned int iStackSize = info->m_threadMemory[i]->ComputeWeightedSum();
        if (iStackSize > 0)
        {
            FUN_00cc0410(ostr, "            Thread %i  size %10i\n", i, iStackSize);
            total += iStackSize;
        }
    }
    FUN_00cc0410(ostr, "            = total %i\n\n", total);

    FUN_00cc0410(ostr, "\tStackMemory\n");
    int stackTotal = 0;
    for (int iStackIndex = 0; iStackIndex < info->m_kAllocatorList.GetLogicalSize(); iStackIndex++)
    {
        hkStackMemory* pStackTriple = info->m_kAllocatorList[iStackIndex];
        int used;
        int iStackSize = (char*)pStackTriple->m_end.val() - (char*)pStackTriple->m_start.val();
        stackTotal += iStackSize;
        used = iStackSize - (int)((char*)pStackTriple->m_end.val() - (char*)pStackTriple->m_next.val());
        FUN_00cc0410(ostr, "            Thread %i  size %10i      used:    %6i (%4.1f%%)\n", iStackIndex, iStackSize,
                     used, used * 100.0 / iStackSize);
    }
    if (info->m_kAllocatorList.GetLogicalSize() == 0)
    {
        stackTotal = info->m_stackTotal;
    }
    FUN_00cc0410(ostr, "            = total %i\n\n", stackTotal);

    FUN_00c85750()->solverAllocator().getMemoryStatistics(reinterpret_cast<hkMemoryAllocator::MemoryStatistics&>(stats));
    FUN_00cc0410(ostr, "\t%s:\n", "Solver");
    FUN_00cc0410(ostr, "            totalSize:   %10i\n", stats.m_uiFirstValue);
    FUN_00cc0410(ostr, "              peak:      %10i (%4.1f%%)\n\n", stats.m_uiThirdValue,
                 (float)stats.m_uiThirdValue * 100.0 / (float)stats.m_uiFirstValue);

    FUN_00c85750()->debugAllocator().getMemoryStatistics(reinterpret_cast<hkMemoryAllocator::MemoryStatistics&>(stats));
    if (heapInUse == stats.m_pAllocationMap)
    {
        FUN_00cc0410(ostr, "\tDebugMem: Not used.\n\n");
    }
    else
    {
        FUN_00cbc000(ostr, "DebugMem", stats, 0x7fffffff);
    }
}
