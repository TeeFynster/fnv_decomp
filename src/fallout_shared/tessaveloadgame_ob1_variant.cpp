
// src/fallout_shared/tessaveloadgame_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/tessaveloadgame.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../include/MemoryManager.h"
#include "../../include/RecursiveSpinLock.h"

// Constructor: base list (10 slots, grow 1, entry size 0x78), counters cleared, a helper object
// allocated through the class operator new, and the first entry's payload cached.
extern MemoryManager g_memoryManagerL;

struct EntryL
{
    unsigned int m_00;
    unsigned int m_04;
    void* m_pData;
};
struct BaseListL
{
    void* m_vtbl;
    unsigned int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c, m_40, m_44,
        m_48, m_4c;
    EntryL** m_ppEntries;
    unsigned int m_54, m_58, m_5c;
    BaseListL(int, int, int);
    ~BaseListL();
    EntryL* GetAt(unsigned int i)
    {
        return m_ppEntries[i];
    }
    void* GetDataAt(unsigned int i)
    {
        return m_ppEntries[i]->m_pData;
    }
};
struct HelperL
{
    unsigned int m_00, m_04, m_08, m_0c;
    HelperL(int, int, int);
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManagerL.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);
};
extern int DAT_010c1604;
struct FUN_00c3da50 : BaseListL
{
    void* m_pFirstData;
    HelperL* m_pHelper;
    unsigned int m_68, m_6c, m_70, m_74, m_78, m_7c, m_80;
    FUN_00c3da50();
};
// @fnv 0x00c3da50
FUN_00c3da50::FUN_00c3da50() : BaseListL(10, 1, 120)
{
    m_vtbl = &DAT_010c1604;
    m_70 = 0;
    m_78 = 0;
    m_6c = 0;
    m_7c = 0;
    m_80 = 0;
    m_68 = 6;
    m_pHelper = new HelperL(6, 7, 8);
    m_pFirstData = GetDataAt(0);
}

extern "C" void BSTask_int64_DecRefCount(void* p);
extern "C" long __stdcall InterlockedCompareExchange(long volatile* dest, long exchange, long comparand);

struct Node006c6fe0
{
    Node006c6fe0* next;
    void* value;
};

struct Ops006c6fe0
{
    Node006c6fe0* node;
    Ops006c6fe0* next;
    Ops006c6fe0* tail;
    void notify(void* owner);
};

struct C006c6fe0
{
    Ops006c6fe0* ops;
    Ops006c6fe0** published;
    Node006c6fe0** pending;
    bool TryDequeue()
    {
        Ops006c6fe0* cur;
        Ops006c6fe0* tail;
        Node006c6fe0* node;
        Node006c6fe0* old;
        long expected;
        long result;
        long current;
        long compare;
        long outcome;
        bool ok;
        for (;;)
        {
            cur = ops->next;
            *published = cur;
            if (cur != ops->next)
                continue;
            tail = ops->tail;
            node = cur->node;
            *pending = node;
            if (cur->next != cur)
                continue;
            if (node == 0)
            {
                *published = 0;
                old = *pending;
                if (old != 0)
                {
                    BSTask_int64_DecRefCount(old->value);
                    *pending = 0;
                }
                return false;
            }
            if (cur == tail)
            {
                expected = 0;
                result = InterlockedCompareExchange((long volatile*)&ops->tail, (long)node, expected);
                if (result != 0)
                    continue;
                continue;
            }
            current = (long)cur;
            compare = (long)tail;
            outcome = InterlockedCompareExchange((long volatile*)&cur->next, current, compare);
            ok = outcome == current;
            if (!ok)
                continue;
            ops->notify(this);
            return true;
        }
    }
};

struct C00449f80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
    C006c6fe0* LockFreeMap_GetInterface_0(unsigned int a);
};

struct S_00c3e490 : C00449f80
{
    int unk18;
    int unk1c;
    RecursiveSpinLock m_lock;
    bool LockFreeQueue_NiPointer_IOTask_Pop_00c3e490(unsigned int a);
};

// @fnv 0x00c3e490
// src: COMMUNITY 0x00c3e490
bool S_00c3e490::LockFreeQueue_NiPointer_IOTask_Pop_00c3e490(unsigned int a)
{
    m_lock.Lock(0);
    bool r = LockFreeMap_GetInterface_0(a)->TryDequeue();
    m_lock.Unlock();
    return r;
}

extern MemoryManager g_memoryManager;

extern __declspec(thread) unsigned int DAT_000002b4;
inline unsigned int GetCurrentContext()
{
    return DAT_000002b4;
}
inline void SetCurrentContext(unsigned int context)
{
    DAT_000002b4 = context;
}
struct HeapContextGuard
{
    unsigned int previous;
    HeapContextGuard(unsigned int context)
    {
        previous = GetCurrentContext();
        SetCurrentContext(context);
    }
    ~HeapContextGuard()
    {
        SetCurrentContext(previous);
    }
};

inline void* operator new[](unsigned int n, MemoryManager*)
{
    return g_memoryManager.Allocate(n);
}
inline void* operator new(unsigned int n, MemoryManager*)
{
    return g_memoryManager.Allocate(n);
}
void operator delete(void*, MemoryManager*);

struct ArchiveFileManager
{
    virtual ~ArchiveFileManager()
    {}
};
struct Pair20
{
    int a;
    int b;
    Pair20()
    {
        a = 0;
        b = 0;
    }
};
struct FUN_00c42180
{
    int a, b, c, d;
    FUN_00c42180(unsigned int);
};
struct PointerEntry
{
    void* value;
    void Clear()
    {
        PointerEntry* self = this;
        self->value = 0;
    }
};
__forceinline void InitializeLoop(PointerEntry* cursor, int remaining)
{
    while (--remaining >= 0)
    {
        cursor->Clear();
        ++cursor;
    }
}
__forceinline PointerEntry* InitializeEntries(PointerEntry* allocation, const unsigned int& count)
{
    return allocation ? (InitializeLoop(allocation, count), allocation) : 0;
}

struct FUN_00c3ec80 : ArchiveFileManager
{
    void** unk04;
    unsigned int unk08;
    void** unk0c;
    unsigned int unk10;
    FUN_00c42180* unk14;
    int unk18;
    int unk1c;
    Pair20 unk20;
    FUN_00c3ec80(unsigned int a, unsigned int b, unsigned int c);
    virtual ~FUN_00c3ec80();
};

// @fnv 0x00c3ec80
FUN_00c3ec80::FUN_00c3ec80(unsigned int a, unsigned int b, unsigned int c)
{
    HeapContextGuard context4_2(6);
    unk18 = 0;
    unk08 = b;
    unsigned int count2 = unk08;
    PointerEntry* entries3 = InitializeEntries((PointerEntry*)new (&g_memoryManager) void*[count2], count2);
    unk0c = (void**)entries3;
    unk04 = new (&g_memoryManager) void*[a * 3];
    unk10 = c;
    unk14 = new (&g_memoryManager) FUN_00c42180(a);
}

extern "C" void* __cdecl memset(void* pvDest, int iValue, unsigned int uiSize);

extern MemoryManager g_kMemoryManagerC4;

inline void* operator new[](unsigned int uiSize)
{
    return g_kMemoryManagerC4.Allocate(uiSize);
}

template <class T> inline void ZeroArrayC4(T* pkArray, unsigned int ItemUpdateArray)
{
    memset(pkArray, 0, ItemUpdateArray * sizeof(T));
}

class BaseQueueC4
{
  public:
    BaseQueueC4(unsigned int uiTotal, unsigned int ItemUpdateArray, unsigned int uiStride);
    virtual ~BaseQueueC4();
    char m_acPad[0x40 - 4];
};

class FUN_00c3e4f0;
class WorkerC4
{
  public:
    inline static void* operator new(unsigned int uiSize)
    {
        return g_kMemoryManagerC4.Allocate(uiSize);
    }
    inline static void operator delete(void* pv)
    {}
    WorkerC4(FUN_00c3e4f0* pkOwner, unsigned int uiID);
    void Start();
    char m_acData[0x34];
};

class FUN_00c3e4f0 : public BaseQueueC4
{
  public:
    FUN_00c3e4f0(unsigned int uiReserved, unsigned int uiWorkers, unsigned int uiSlots);
    virtual ~FUN_00c3e4f0();
    bool m_bStopped;
    unsigned int m_uiCount44;
    unsigned int m_uiCount48;
    unsigned int m_uiWorkers;
    WorkerC4** m_ppkWorkers;
    void** m_ppvSlots;
    unsigned int m_uiCount58;
};

// @fnv 0x00c3e4f0
FUN_00c3e4f0::FUN_00c3e4f0(unsigned int uiReserved, unsigned int uiWorkers, unsigned int uiSlots)
    : BaseQueueC4(uiReserved + uiWorkers, uiSlots, 0xc)
{
    m_bStopped = false;
    m_uiCount44 = 0;
    m_uiCount48 = 0;
    m_uiWorkers = uiWorkers;
    m_ppvSlots = new void*[uiSlots];
    ZeroArrayC4(m_ppvSlots, uiSlots);
    m_uiCount58 = 0;
    m_ppkWorkers = new WorkerC4*[m_uiWorkers];
    for (unsigned int i = 0; i < m_uiWorkers; i++)
    {
        m_ppkWorkers[i] = new WorkerC4(this, i + 2);
        m_ppkWorkers[i]->Start();
    }
}

namespace fnv_00c3e8b0 {
struct ThreadDataC3
{
    char m_acPad[0x2b4];
    int m_iMemContext;
};
extern __declspec(thread) ThreadDataC3 g_kThreadDataC3;

inline int GetMemContextC3()
{
    return g_kThreadDataC3.m_iMemContext;
}

inline void SetMemContextC3(int aiMemoryContext)
{
    g_kThreadDataC3.m_iMemContext = aiMemoryContext;
}

class MemContextScopeC3
{
  public:
    inline MemContextScopeC3(int aiMemoryContext)
    {
        m_iOld = GetMemContextC3();
        SetMemContextC3(aiMemoryContext);
    }
    inline ~MemContextScopeC3()
    {
        SetMemContextC3(m_iOld);
    }
    int m_iOld;
};

extern MemoryManager g_kMemoryManagerC3;

inline void* operator new[](unsigned int uiSize)
{
    return g_kMemoryManagerC3.Allocate(uiSize);
}

class IOQueueC3
{
  public:
    inline static void* operator new(unsigned int uiSize)
    {
        return g_kMemoryManagerC3.Allocate(uiSize);
    }
    inline static void operator delete(void* pv)
    {}
    IOQueueC3(void* pvA, void* pvB);
    char m_acData[0x40];
};

class FUN_00c3e8b0
{
  public:
    FUN_00c3e8b0(unsigned int uiSize, void* pvA, void* pvB);
    virtual ~FUN_00c3e8b0();
    IOQueueC3** m_ppkQueues;
    unsigned int m_uiSize;
    unsigned int m_uiCount;
};

extern const void* const g_apvLockFreePriorityQueueVtblC3[];

// @fnv 0x00c3e8b0
FUN_00c3e8b0::FUN_00c3e8b0(unsigned int uiSize, void* pvA, void* pvB)
{
    MemContextScopeC3 kScope(6);
    m_uiCount = 0;
    m_uiSize = uiSize;
    m_ppkQueues = new IOQueueC3*[m_uiSize];
    for (unsigned int i = 0; i < m_uiSize; i++)
        m_ppkQueues[i] = new IOQueueC3(pvA, pvB);
}
}  // namespace fnv_00c3e8b0
