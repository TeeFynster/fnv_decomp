
// src/havok/common/base/memory/allocator/checking/hkleakdetectallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/checking/hkleakdetectallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d5f270_class
{
    void __thiscall hkLeakDetectAllocator_checkedFree(int c, void* a, unsigned int b);
    void __thiscall hkLeakDetectAllocator_blockFree(void* a, unsigned int b);
};

// @fnv 0x00d5f270
// src: HAVOK_SRC 0x00d5f270
void __thiscall FUN_00d5f270_class::hkLeakDetectAllocator_blockFree(void* a, unsigned int b)
{
    hkLeakDetectAllocator_checkedFree(0, a, b);
}

struct FUN_00d5f2b0_class
{
    void hkLeakDetectAllocator_checkedFree(int, int, int);
    void hkLeakDetectAllocator_bufFree(int a, int b);
};

// @fnv 0x00d5f2b0
// src: HAVOK_LIB 0x00d5f2b0
void FUN_00d5f2b0_class::hkLeakDetectAllocator_bufFree(int a, int b)
{
    hkLeakDetectAllocator_checkedFree(1, a, b);
}

struct Inner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual int v28(int a);
};

struct Outer
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Inner* unk30;
    int hkLeakDetectAllocator_getMemoryStatistics(int a);
};

// @fnv 0x00d5ee60
// src: HAVOK_LIB 0x00d5ee60
int Outer::hkLeakDetectAllocator_getMemoryStatistics(int a)
{
    return unk30->v28(a);
}

struct S_00d5ee70_Inner
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C(int a0);
};
struct S_00d5ee70
{
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
    S_00d5ee70_Inner* unk30;
    void hkLeakDetectAllocator_getAllocatedSize(int a0);
};

// Forwards a0 to the virtual function vfn2C of the inner object at unk30.
// @fnv 0x00d5ee70
// src: HAVOK_LIB 0x00d5ee70
void S_00d5ee70::hkLeakDetectAllocator_getAllocatedSize(int a0)
{
    unk30->vfn2C(a0);
}

struct FUN_00d5ee80_class
{
    unsigned int unk00;
    void* unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    volatile void* unk40;
    unsigned int unk44;
    void __thiscall InitWithAllocator(void* a, void* b, void* c, void* d);
};
struct Allocator
{
    virtual void* first();
    virtual void* allocate(unsigned int);
};
struct Existing
{
    void __thiscall FUN_00c903a0();
};
struct Old
{
    void __thiscall ReleaseReference();
};
extern void* DAT_01269a84;
extern void* __cdecl hkStackTracer_create();
// @fnv 0x00d5ee80
void __thiscall FUN_00d5ee80_class::InitWithAllocator(void* apArg0, void* apAllocator, void* apArg2, void* apArg3)
{
    unk30 = apArg0;
    unk34 = apAllocator;
    unk38 = apArg2;
    unk3c = apArg3;
    unk44 = 0;
    if (!DAT_01269a84)
    {
        void* x = hkStackTracer_create();
        if (DAT_01269a84)
            ((Old*)DAT_01269a84)->ReleaseReference();
        DAT_01269a84 = x;
    }
    unk04 = DAT_01269a84;
    ((Existing*)unk04)->FUN_00c903a0();
    void* pBlock = ((Allocator*)apAllocator)->allocate(12);
    if (pBlock)
    {
        ((unsigned int*)pBlock)[0] = 0;
        ((unsigned int*)pBlock)[1] = 0;
        ((unsigned int*)pBlock)[2] = 0xffffffff;
    }
    else
    {
        pBlock = 0;
    }
    this->unk14 = apAllocator;
    this->unk40 = pBlock;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct Sub30
{
    virtual void unk0();
    virtual int vfunc_4(void* a);
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual int vfunc_2C(int a, void* b);
};

void* __stdcall hkStackTracer_getStackTrace(void* buf, int size);
struct Helper8
{
    int FindOrAddCallTrace(void* buf, void* val);
};
struct ParamStruct
{
    int p0;
    void* p1;
    int p2;
};
struct Sub40
{
    void hkMapBase_unsigned_long_struct_hkLeakDetectAllocator_AllocInfo_struct_hkMapOperations_unsigned_long_insert(void* u34, int edi, ParamStruct p);
};

struct FUN_00d5f0a0_class
{
    int unk00;
    volatile int unk04;
    Helper8 unk08;
    int unk0c, unk10, unk14;
    char cs[24];
    Sub30* sub30;
    void* unk34;
    int unk38, unk3C;
    Sub40* sub40;
    int unk44;

    int ProcessAndDispatch(int a1, void* a2);
};

// Locks cs, resolves a2 via sub30, accumulates unk44, builds a ParamStruct from a1/a2 and unk04, dispatches through sub40, then unlocks.
// @fnv 0x00d5f0a0
int FUN_00d5f0a0_class::ProcessAndDispatch(int aiFlag, void* apArg)
{
    EnterCriticalSection(&cs);
    int res = sub30->vfunc_4(apArg);
    unk44 += sub30->vfunc_2C(res, apArg);
    ParamStruct p;
    *(char*)&p.p2 = (aiFlag != 0);
    p.p1 = apArg;
    int buffer[32];
    if (unk04)
    {
        p.p0 = unk08.FindOrAddCallTrace(buffer, hkStackTracer_getStackTrace(buffer, 0x20));
    }
    else
    {
        p.p0 = 0;
    }
    sub40->hkMapBase_unsigned_long_struct_hkLeakDetectAllocator_AllocInfo_struct_hkMapOperations_unsigned_long_insert(unk34, res, p);
    LeaveCriticalSection(&cs);
    return res;
}

void __stdcall ProcessAndDispatch(int aiFlag, void* apObject);

// @fnv 0x00d5f260
// src: HAVOK_SRC 0x00d5f260
void __stdcall hkLeakDetectAllocator_blockAlloc(void* apObject)
{
    ProcessAndDispatch(0, apObject);
}

namespace fnv_00d5f480 {
struct ParamStruct
{
    int p0;
    void* p1;
    int p2;
};

struct Entry
{
    int key;
    ParamStruct val;
};

struct FUN_00d5f480_class
{
    Entry* entries;
    int count;
    int mask;

    void Resize(void* u34, int new_cap);
    int hkMapBase_unsigned_long_struct_hkLeakDetectAllocator_AllocInfo_struct_hkMapOperations_unsigned_long_insert(void* u34, int key, ParamStruct val);
};

// Grows the table when load exceeds half the mask, probes for the key, stores the key/value pair, and returns 1 if the key was new.
// @fnv 0x00d5f480
// src: HAVOK_LIB 0x00d5f480
int FUN_00d5f480_class::hkMapBase_unsigned_long_struct_hkLeakDetectAllocator_AllocInfo_struct_hkMapOperations_unsigned_long_insert(void* u34, int key, ParamStruct val)
{
    if ((count & 0x7fffffff) * 2 > mask)
    {
        Resize(u34, mask * 2 + 2);
    }

    int idx = ((unsigned int)key >> 4) * 0x9e3779b1 & mask;
    int isNew = 1;
    while (entries[idx].key != -1)
    {
        if (entries[idx].key == key)
        {
            isNew = 0;
            break;
        }
        idx = (idx + 1) & mask;
    }
    count += isNew;
    entries[idx].key = key;
    entries[idx].val = val;
    return isNew;
}
}  // namespace fnv_00d5f480

struct Deallocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct FUN_00d5f640_cls
{
    void* m_pData;
    unsigned int m_uiObjectFlags;
    int m_iArrayLength;

    void Reset();
    void FreeStorage(Deallocator* apAllocator);
};

// @fnv 0x00d5f640
void FUN_00d5f640_cls::FreeStorage(Deallocator* apAllocator)
{
    Reset();
    if ((m_uiObjectFlags & 0x80000000) == 0)
        apAllocator->Free(m_pData, (m_iArrayLength + 1) << 4);
}

namespace fnv_00da2bc0 {
struct FUN_00da2b90_class
{
    void* vtbl;
    short unk04;
    short unk06;
    void* unk08;
    FUN_00da2b90_class* Initialize();
};

extern FUN_00da2b90_class DAT_01269a90;

// @fnv 0x00da2bc0
// src: XBOX_PDB 0x00da2bc0
void hkStackTracer_create()
{
    DAT_01269a90.Initialize();
}
}  // namespace fnv_00da2bc0

struct FUN_00da2b50_cls
{
    int hkStackTracer_CallTree_getCallStack(int a, int b, int c);
};
struct FUN_00da2990_cls
{
    int hkStackTracer_dumpStackTrace(int a, int b, int c, int d);
};

extern "C" int __cdecl Vsnprintf(char* buf, unsigned int n, const char* fmt, ...);

struct FUN_00d5edc0_cls
{
    int m_00;
    void* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;

    void LogAddressAndSize(int p1, int p2, int* p3);
};

// @fnv 0x00d5edc0
void FUN_00d5edc0_cls::LogAddressAndSize(int p1, int aAddress, int* pInfo)
{
    unsigned int buf[0x40];
    unsigned int buf2[0x20];
    Vsnprintf((char*)buf, 0x100, "\nAddress=0x%p size=%i\n", aAddress, pInfo[1]);
    reinterpret_cast<int(__cdecl*)(...)>(m_38)(p1, m_3c);
    reinterpret_cast<int(__cdecl*)(...)>(m_38)(buf, m_3c);
    int r = reinterpret_cast<FUN_00da2b50_cls*>(&m_08)->hkStackTracer_CallTree_getCallStack(pInfo[0], (int)buf2, 0x20);
    reinterpret_cast<FUN_00da2990_cls*>(m_04)->hkStackTracer_dumpStackTrace((int)buf2, r, m_38, m_3c);
    reinterpret_cast<int(__cdecl*)(...)>(m_38)(
        "-------------------------------------------------------------------\n\n", m_3c);
}

struct FUN_00d5f290_class
{
    void __thiscall ProcessAndDispatch(int, int);
    void __thiscall CallWithFirstArg(int* a);
};

// @fnv 0x00d5f290
void FUN_00d5f290_class::CallWithFirstArg(int* piValue)
{
    ProcessAndDispatch(1, *piValue);
}

struct FUN_00d5f2d0_cls
{
    int ProcessAndDispatch(int a, int b);
    int hkLeakDetectAllocator_bufRealloc(int a1, int a2, int* a3);
};

void __cdecl hkMemUtil_memCpy_00d2caa0(int a, int b, int c);

// @fnv 0x00d5f2d0
// src: HAVOK_LIB 0x00d5f2d0
int FUN_00d5f2d0_cls::hkLeakDetectAllocator_bufRealloc(int a1, int a2, int* piValue)
{
    int r = this->ProcessAndDispatch(1, *piValue);
    int m = *piValue;
    if (!(m < a2))
    {
        m = a2;
    }
    hkMemUtil_memCpy_00d2caa0(r, a1, m);
    reinterpret_cast<FUN_00d5f2b0_class*>(this)->hkLeakDetectAllocator_checkedFree(1, a1, a2);
    return r;
}

// hkLeakDetectAllocator::quit()

struct S_00d5f320_Allocator
{
    virtual ~S_00d5f320_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00d5f320_RefObj
{
    void FUN_00c905b0();  // removeReference
};

struct S_00d5f320_AllocInfo
{
    int unk00;
    int unk04;
    int unk08;
};

struct S_00d5f320_Pair
{
    unsigned long key;
    S_00d5f320_AllocInfo val;
};

class S_00d5f320_Dummy;

struct S_00d5f320_Map
{
    typedef S_00d5f320_Dummy* Iterator;

    S_00d5f320_Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int GetLogicalSize() const
    {
        return m_iCapacityFlags & 0x7fffffff;
    }
    Iterator GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned long)-1)
                break;
        }
        return reinterpret_cast<Iterator>(i);
    }
    Iterator getNext(Iterator it) const
    {
        int i = (int)reinterpret_cast<unsigned long>(it);
        for (i += 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned long)-1)
                break;
        }
        return reinterpret_cast<Iterator>(i);
    }
    bool isValid(Iterator it) const
    {
        return (int)reinterpret_cast<unsigned long>(it) <= m_iPairCount;
    }
    unsigned long GetIteratorKey(Iterator it) const
    {
        return m_kPrimitiveElement[(int)reinterpret_cast<unsigned long>(it)].key;
    }
    S_00d5f320_AllocInfo getValue(Iterator it) const
    {
        return m_kPrimitiveElement[(int)reinterpret_cast<unsigned long>(it)].val;
    }

    void FreeStorage(S_00d5f320_Allocator& alloc);
};

struct S_00d5f320_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct S_00d5f320_CallTree
{
    S_00d5f320_Node* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d5f320_Allocator* m_pThreadAllocator;

    void _clearAndDeallocate(S_00d5f320_Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S_00d5f320_Node));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void quit()
    {
        _clearAndDeallocate(*m_pThreadAllocator);
        m_pThreadAllocator = 0;
    }
};

typedef void(__cdecl* S_00d5f320_OutputFunc)(const char*, void*);

int __cdecl Vsnprintf(char* buf, int n, const char* fmt, ...);

struct S_00d5f320_LeakDetect
{
    int unk00;
    S_00d5f320_RefObj* m_pReferenceObject;
    S_00d5f320_CallTree m_kCallTree;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    S_00d5f320_Allocator* m_pAllocator;
    S_00d5f320_OutputFunc m_pOutputFunction;
    void* m_pOutputUserData;
    S_00d5f320_Map* m_pAllocationMap;

    void LogAddressAndSize(const char* what, unsigned long addr, const S_00d5f320_AllocInfo& info);
    void printBlock(const char* what, unsigned long addr, S_00d5f320_AllocInfo info)
    {
        LogAddressAndSize(what, addr, info);
    }
    void ReportLeaks();
};

// If the leak map is non-empty, prints each leaked block and a leak count via the output callback, then quits the call tree and frees the map.
// @fnv 0x00d5f320
void S_00d5f320_LeakDetect::ReportLeaks()
{
    if (m_pAllocationMap->GetLogicalSize())
    {
        m_pOutputFunction("**************************************************************\n"
                          "* Begin hkLeakDetectorAllocator                              *\n"
                          "**************************************************************\n",
                          m_pOutputUserData);
        for (S_00d5f320_Map::Iterator it = m_pAllocationMap->GetFirstIterator(); m_pAllocationMap->isValid(it);
             it = m_pAllocationMap->getNext(it))
        {
            S_00d5f320_AllocInfo info;
            info = m_pAllocationMap->getValue(it);
            printBlock("Memory Leaked:\n", m_pAllocationMap->GetIteratorKey(it), info);
        }
        unsigned int buf[64];  // char[256] in the original; built without a GS cookie
        Vsnprintf((char*)buf, 256, "\n%i leaks found\n", m_pAllocationMap->GetLogicalSize());
        m_pOutputFunction((char*)buf, m_pOutputUserData);
        m_pOutputFunction("**************************************************************\n"
                          "* End hkLeadDetectorAllocator                                *\n"
                          "**************************************************************\n",
                          m_pOutputUserData);
        __debugbreak();
    }
    m_kCallTree.quit();
    m_pAllocationMap->FreeStorage(*m_pAllocator);
    m_pAllocator->ReleaseBlock(m_pAllocationMap, sizeof(S_00d5f320_Map));
    m_pReferenceObject->FUN_00c905b0();
}

struct FUN_00d5f520_class
{
    int unk00;
    int unk04;
    int unk08;
    int FindSlot(unsigned int a);
};

// @fnv 0x00d5f520
int FUN_00d5f520_class::FindSlot(unsigned int auiKey)
{
    int v = unk08;
    if (v > 0)
    {
        unsigned int idx = ((auiKey >> 4) * 0x9e3779b1) & (unsigned int)v;
        int val = *(int*)(*(int*)this + (idx << 4));
        while (val != -1)
        {
            if (val == (int)auiKey)
                return (int)idx;
            idx = (idx + 1) & (unsigned int)v;
            val = *(int*)(*(int*)this + (idx << 4));
        }
    }
    return v + 1;
}

struct D5F670Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D5F670Value
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
};

struct D5F670Pair
{
    unsigned int key;
    D5F670Value val;
};

struct D5F670Map
{
    D5F670Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int insert(D5F670Allocator& alloc, unsigned int key, D5F670Value val);
    void Resize(D5F670Allocator& alloc, int newcap);
};

// @fnv 0x00d5f670
void D5F670Map::Resize(D5F670Allocator& alloc, int aiNewCapacity)
{
    aiNewCapacity = (aiNewCapacity > 8) ? aiNewCapacity : 8;
    int iNoDeallocate = m_iCapacityFlags & 0x80000000;
    int iOldCapacity = m_iPairCount + 1;
    D5F670Pair* pOldEntries = m_kPrimitiveElement;
    m_kPrimitiveElement = static_cast<D5F670Pair*>(alloc.AllocateMemoryBlock(sizeof(D5F670Pair) * aiNewCapacity));
    for (int i = 0; i < aiNewCapacity; i++)
        m_kPrimitiveElement[i].key = 0xffffffff;
    m_iCapacityFlags = 0;
    m_iPairCount = aiNewCapacity - 1;

    for (int i = 0; i < iOldCapacity; i++)
    {
        if (pOldEntries[i].key != 0xffffffff)
            insert(alloc, pOldEntries[i].key, pOldEntries[i].val);
    }

    if (iNoDeallocate == 0)
        alloc.ReleaseBlock(pOldEntries, sizeof(D5F670Pair) * iOldCapacity);
}

struct Node2b50
{
    unsigned int m_uiFilterValue;
    int m_next;
    int unk08;
    int unk0c;
};
struct List2b50
{
    Node2b50* m_kNodeCollection;
    int hkStackTracer_CallTree_getCallStack(int node, unsigned int* out, int count);
};
// @fnv 0x00da2b50
// src: HAVOK_LIB 0x00da2b50
int List2b50::hkStackTracer_CallTree_getCallStack(int iStartIndex, unsigned int* out, int count)
{
    int iIndex = iStartIndex;
    int i;
    for (i = 0; i < count; i++)
    {
        if (iIndex <= 0)
            break;
        out[i] = m_kNodeCollection[iIndex].m_uiFilterValue;
        iIndex = m_kNodeCollection[iIndex].m_next;
    }
    return i;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct CriticalSectionD5
{
    void* DebugInfo;
    int LockCount;
    int RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

struct AllocatorD5
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct ListenerD5
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void onEntry(int key, int value);
};

struct RouterD5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ListenerD5* m_kListener;
    AllocatorD5* m_pStreamAllocator;

    AllocatorD5& heap()
    {
        return *m_pStreamAllocator;
    }
};
RouterD5* hkMemoryRouter_getInstance();
extern "C" void* __cdecl hkMemUtil_memSet(void* dst, int value, int numBytes);
extern "C" void* __cdecl hkString_memCpy(void* dst, const void* src, int numBytes);

struct PointerInfoD5
{
    int a;
    int b;
    int c;
};

struct MapElemD5
{
    int key;
    PointerInfoD5 val;
};

struct MapD5
{
    MapElemD5* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int GetLogicalSize() const
    {
        return m_iCapacityFlags & 0x7fffffff;
    }
    int GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != -1)
                break;
        }
        return i;
    }
    int getNext(int it) const
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != -1)
                break;
        }
        return i;
    }
    bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
    int GetIteratorKey(int it) const
    {
        return m_kPrimitiveElement[it].key;
    }
    PointerInfoD5 getValue(int it) const
    {
        return m_kPrimitiveElement[it].val;
    }
};

struct SnapshotEntryD5
{
    int m_uiFilterValue;
    unsigned int m_data[16];
    int m_uiItemCount;
};

struct SnapshotD5
{
    int* m_keys;
    SnapshotEntryD5* m_entries;
    int m_num;

    void FreeBuffers();
};

struct SourceD5
{
    int hkStackTracer_CallTree_getCallStack(int key, unsigned int* out, int capacity);
};

struct FUN_00d5ef20_Class
{
    int unk00;
    int unk04;
    SourceD5 m_pObservedSource;
    int unk0c;
    int unk10;
    int unk14;
    CriticalSectionD5 m_kCriticalSection;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    MapD5* m_map;

    int Snapshot(SnapshotD5* out);
};

// Copies the current map entries into out by allocating buffers, reading each source value, and notifying the router listener.
// @fnv 0x00d5ef20
int FUN_00d5ef20_Class::Snapshot(SnapshotD5* out)
{
    void* section = &m_kCriticalSection;
    EnterCriticalSection(section);
    out->FreeBuffers();
    MapD5* map = m_map;
    int n = map->GetLogicalSize();
    if (n == 0)
    {
        LeaveCriticalSection(section);
        return 0;
    }
    out->m_num = n;
    out->m_entries = (SnapshotEntryD5*)hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(n * sizeof(SnapshotEntryD5));
    hkMemUtil_memSet(out->m_entries, 0, n * sizeof(SnapshotEntryD5));
    out->m_keys = (int*)hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(n * sizeof(int));
    SnapshotEntryD5* entry = out->m_entries;
    int* keys = out->m_keys;
    RouterD5* router = hkMemoryRouter_getInstance();
    for (int it = map->GetFirstIterator(); map->isValid(it); it = map->getNext(it))
    {
        PointerInfoD5 info = map->getValue(it);
        *keys = map->GetIteratorKey(it);
        unsigned int data[16];
        int n = m_pObservedSource.hkStackTracer_CallTree_getCallStack(info.a, data, 16);
        entry->m_uiItemCount = n;
        hkString_memCpy(entry->m_data, data, n * sizeof(unsigned int));
        entry->m_uiFilterValue = info.b;
        router->m_kListener->onEntry(*keys, info.b);
        entry++;
        keys++;
    }
    LeaveCriticalSection(section);
    return 0;
}

struct ValD5F5
{
    unsigned int v0;
    unsigned int v1;
    unsigned int v2;
};

struct MapOpsD5F5
{
    static inline void invalidate(unsigned int& key)
    {
        key = (unsigned int)-1;
    }
    static inline bool isValid(unsigned int key)
    {
        return key != (unsigned int)-1;
    }
    static inline unsigned hash(unsigned int key, unsigned mod)
    {
        return (unsigned)((key >> 4) * 0x9e3779b1u) & mod;
    }
};

struct MapD5F5
{
    // hkMapBase<KEY,VAL>::Pair (Havok hkMap.h: key, val); renamed so it does not take include/Pair.h's name
    struct KeyValue
    {
        unsigned int key;
        ValD5F5 val;
    };
    KeyValue* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    void hkMapBase_unsigned_long_struct_hkLeakDetectAllocator_AllocInfo_struct_hkMapOperations_unsigned_long_remove(void* it);
};

// Removes the entry at index it by invalidating its key and compacting the remaining valid pairs in the open-addressing table.
// @fnv 0x00d5f570
// src: HAVOK_LIB 0x00d5f570
void MapD5F5::hkMapBase_unsigned_long_struct_hkLeakDetectAllocator_AllocInfo_struct_hkMapOperations_unsigned_long_remove(void* aiIndex)
{
    typedef MapOpsD5F5 OPS;
    unsigned i = (unsigned)aiIndex;

    --m_iCapacityFlags;
    OPS::invalidate(m_kPrimitiveElement[i].key);

    unsigned iStart = (i + m_iPairCount) & m_iPairCount;
    while (OPS::isValid(m_kPrimitiveElement[iStart].key))
    {
        iStart = (iStart + m_iPairCount) & m_iPairCount;
    }
    iStart = (iStart + 1) & m_iPairCount;

    unsigned empty = i;

    for (i = (i + 1) & m_iPairCount; OPS::isValid(m_kPrimitiveElement[i].key); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = OPS::hash(m_kPrimitiveElement[i].key, m_iPairCount);

        if ((i >= iStart) && (hash > empty))
        {
            continue;
        }
        else if ((i < empty) && (hash > empty || hash <= i))
        {
            continue;
        }
        else if ((hash > empty && hash < iStart))
        {
            continue;
        }

        m_kPrimitiveElement[empty].key = m_kPrimitiveElement[i].key;
        m_kPrimitiveElement[empty].val = m_kPrimitiveElement[i].val;
        OPS::invalidate(m_kPrimitiveElement[i].key);
        empty = i;
    }
}

typedef void(__cdecl* LeakOutputFunc)(const char*, void*);

struct LeakAllocInfo
{
    int unk00;
    int size;
    int unk08;
};

struct LeakPair
{
    unsigned long key;
    LeakAllocInfo val;
};

struct LeakMapBase
{
    LeakPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int FindSlot(unsigned long key);
    void hkMapBase_unsigned_long_struct_hkLeakDetectAllocator_AllocInfo_struct_hkMapOperations_unsigned_long_remove(int it);
    bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
    LeakAllocInfo getValue(int it) const
    {
        return m_kPrimitiveElement[it].val;
    }
};
struct LeakMap
{
    LeakMapBase m_map;
    int findKey(unsigned long k)
    {
        return m_map.FindSlot(k);
    }
    bool isValid(int it) const
    {
        return m_map.isValid(it);
    }
    LeakAllocInfo getValue(int it) const
    {
        return m_map.getValue(it);
    }
    void remove(int it)
    {
        m_map.hkMapBase_unsigned_long_struct_hkLeakDetectAllocator_AllocInfo_struct_hkMapOperations_unsigned_long_remove(it);
    }
};

struct LeakChildAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int GetUsableSize(void* p, int numBytes);
};

struct LeakDetectAllocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    CriticalSectionD5 m_pWorldLock;
    LeakChildAllocator* m_pReferenceObject;
    int unk34;
    LeakOutputFunc m_pOutputFunction;
    void* m_pOutputUserData;
    LeakMap* volatile m_pAllocationMap;
    int m_inUseBytes;

    void LogAddressAndSize(const char* what, unsigned long addr, LeakAllocInfo* info);
    void checkSize(const char* what, unsigned long addr, LeakAllocInfo info, int size)
    {
        if (info.size != size)
        {
            LogAddressAndSize(what, addr, &info);
            __debugbreak();
        }
    }
    void hkLeakDetectAllocator_checkedFree(unsigned int unused, void* p, int numBytes);
};

struct LeakCsLock
{
    void* m_cs;
    LeakCsLock(void* cs) : m_cs(cs)
    {
        EnterCriticalSection(cs);
    }
    ~LeakCsLock()
    {
        LeaveCriticalSection(m_cs);
    }
};
// Validates and removes a freed allocation from the leak map, subtracts its usable size from m_inUseBytes, and releases the block via m_pReferenceObject.
// @fnv 0x00d5f150
// src: HAVOK_LIB 0x00d5f150
void LeakDetectAllocator::hkLeakDetectAllocator_checkedFree(unsigned int unused, void* apBlock, int numBytes)
{
    void* cs = &m_pWorldLock;
    EnterCriticalSection(cs);
    if (apBlock != 0 && numBytes == 0)
    {
        m_pOutputFunction("Given zero bytes to free with an nonnull address\n", m_pOutputUserData);
        __debugbreak();
        LeaveCriticalSection(cs);
        return;
    }
    if (apBlock == 0)
    {
        if (numBytes != 0)
        {
            m_pOutputFunction("Given nonzero bytes to free with an null address\n", m_pOutputUserData);
            __debugbreak();
        }
        LeaveCriticalSection(cs);
        return;
    }
    int it = m_pAllocationMap->m_map.FindSlot((unsigned long)apBlock);
    if (!m_pAllocationMap->isValid(it))
    {
        m_pOutputFunction("Freeing block not from this allocator", m_pOutputUserData);
        __debugbreak();
    }
    checkSize("Freeing block of incorrect size", (unsigned long)apBlock, m_pAllocationMap->getValue(it), numBytes);
    m_pAllocationMap->remove(it);
    m_inUseBytes -= m_pReferenceObject->GetUsableSize(apBlock, numBytes);
    m_pReferenceObject->ReleaseBlock(apBlock, numBytes);
    LeaveCriticalSection(cs);
}
