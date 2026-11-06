
// src/havok/physics/collide/dispatch/broadphase/hkptypedbroadphasedispatcher.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/broadphase/hkptypedbroadphasedispatcher.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/Pair.h"
#include "../../../../../../include/hkBool.h"
struct Body
{
    int m_auiShapeKeys;
    signed char m_type;
};

struct Handler
{
    virtual void V0();
    virtual void V1();
    virtual void Process(Pair* p);
};

struct Dispatcher
{
    Handler* m_table[64];
    void DispatchPairs(Pair* pairs, int n);
};

// For each of n pairs, looks up a handler by the pair's two body types and calls Process on it.
// @fnv 0x00cf70f0
void Dispatcher::DispatchPairs(Pair* pairs, int aiCount)
{
    while (--aiCount >= 0)
    {
        Body* a = reinterpret_cast<Body*>(pairs->a);
        Body* b = reinterpret_cast<Body*>(pairs->b);
        m_table[a->m_type * 8 + b->m_type]->Process(pairs);
        pairs++;
    }
}

struct HandleCF7080
{
    unsigned int m_iOwnerObjectOffset;
    signed char m_type;
    signed char m_iOwnerOffset;
    const void* getOwner() const
    {
        return reinterpret_cast<const char*>(this) + m_iOwnerOffset;
    }
};
struct FilterCF7080
{
    virtual ~FilterCF7080();
    virtual hkBool IsCollisionEnabled(const void* a, const void* b) const;
};
struct HandlerCF7080
{
    virtual ~HandlerCF7080();
    virtual void addPair(Pair& pair);
};
struct DispatcherCF7080
{
    HandlerCF7080* m_handlers[8][8];
    void FUN_00cf7080(Pair* pairs, int numPairs, const FilterCF7080* filter);
};

// Iterates over collision pairs, filters them with filter->IsCollisionEnabled, and forwards accepted pairs to the handler for each type combination.
// @fnv 0x00cf7080
void DispatcherCF7080::FUN_00cf7080(Pair* pairs, int numPairs, const FilterCF7080* filter)
{
    while (--numPairs >= 0)
    {
        const void* a = reinterpret_cast<HandleCF7080*>(pairs->a)->getOwner();
        const void* b = reinterpret_cast<HandleCF7080*>(pairs->b)->getOwner();
        if (filter->IsCollisionEnabled(a, b).m_cBooleanValue)
        {
            int typeA = reinterpret_cast<HandleCF7080*>(pairs->a)->m_type;
            int typeB = reinterpret_cast<HandleCF7080*>(pairs->b)->m_type;
            m_handlers[typeA][typeB]->addPair(*pairs);
        }
        pairs++;
    }
}

struct Edge
{
    unsigned int first;
    unsigned int second;
};
struct EdgeArray
{
    Edge* data;
    int count;
    unsigned int capacityFlags;
};
struct HashEntry
{
    unsigned int first;
    unsigned int second;
    unsigned __int64 value;
};
struct HashTableBase
{
    HashEntry* entries;
    int count;
    int capacity;
    void FUN_00cb1b80(void* handle, int length);
    int FUN_00cb1c60(unsigned int first, unsigned int second);
    void InsertKeyValue(void* allocator, unsigned int first, unsigned int second, __int64 value);
    void FUN_00cb1d20(int index);
    void FUN_00cb1e40(void* allocator);
    void FUN_00a29680();
};
struct ScratchAllocator
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual void* Allocate(int* descriptor);
    virtual void Release(void* handle, int length);
};
struct S00cf7130_Buf
{
    void* data;
    int size;
    int capacityFlags;
};
struct S00cf7130_Map
{
    S00cf7130_Buf buf;
    HashTableBase table;
};
struct GlobalPool
{
    int unk00;
    int unk04;
    int unk08;
    ScratchAllocator* scratch;
    void* allocator;
    ScratchAllocator& Scratch()
    {
        return *scratch;
    }
};
extern "C" void* __cdecl FUN_00c85750();
unsigned int __cdecl FUN_00cb1810(int);
void __cdecl FUN_00c908c0(void* allocator, EdgeArray* array, int length, int elementSize);

template <typename T> static __forceinline void Swap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
template <typename T> static __forceinline T Min2(T x, T y)
{
    return x < y ? x : y;
}

static __forceinline GlobalPool* GetPool()
{
    return (GlobalPool*)FUN_00c85750();
}

static void ShrinkEdges(EdgeArray* array, int size, void* allocator)
{
    int cap = array->capacityFlags & 0x3fffffff;
    if (cap < size)
    {
        int newCap = cap * 2;
        if (size >= newCap)
            newCap = size;
        FUN_00c908c0(allocator, array, newCap, 8);
    }
    array->count = size;
}

static __forceinline void MemCpy4(void* dst, const void* src, int nbytes)
{
    for (int k = 0; k < nbytes; k += 4)
    {
        *(int*)((char*)dst + k) = *(const int*)((const char*)src + k);
    }
}

static __forceinline void RemoveAt(EdgeArray* a, int i)
{
    --a->count;
    MemCpy4(&a->data[i], &a->data[i + 1], (a->count - i) * 8);
}

static __forceinline bool SameEdge(const Edge& h, const Edge& v)
{
    return (h.first == v.first && h.second == v.second) || (h.second == v.first && h.first == v.second);
}

static __forceinline int FindEdge(EdgeArray* a, const Edge& v)
{
    int i = 0;
    for (; i < a->count; ++i)
    {
        if (SameEdge(a->data[i], v))
            break;
    }
    return i;
}

// Removes edges that appear in both arrays from each, treating an edge as equal in either vertex order.
// @fnv 0x00cf7130
void __cdecl FUN_00cf7130(EdgeArray* apEdgesA, EdgeArray* apEdgesB)
{
    int iCountA = apEdgesA->count;
    int nb = apEdgesB->count;
    if (Min2(iCountA, nb) < 32)
    {
        int size = 0;
        for (nb = 0; nb < apEdgesB->count; ++nb)
        {
            int i = 0;
            for (; i < apEdgesA->count; ++i)
            {
                if (SameEdge(apEdgesA->data[i], apEdgesB->data[nb]))
                    break;
            }
            if (i == apEdgesA->count)
            {
                if (size != nb)
                    apEdgesB->data[size] = apEdgesB->data[nb];
                ++size;
            }
            else
            {
                RemoveAt(apEdgesA, i);
            }
        }
        ShrinkEdges(apEdgesB, size, GetPool()->allocator);
        return;
    }
    int val = FUN_00cb1810(apEdgesA->count);
    ScratchAllocator* pScratch = GetPool()->scratch;
    void* pBuffer;
    int descriptor = 0;
    if (val)
    {
        int allocated = val;
        pBuffer = pScratch->Allocate(&allocated);
        descriptor = allocated;
    }
    else
    {
        pBuffer = 0;
    }
    if (!descriptor)
        descriptor = (int)0x80000000;
    HashTableBase table;
    table.FUN_00cb1b80(pBuffer, val);
    for (int i = 0; i < apEdgesA->count; ++i)
    {
        Edge e = apEdgesA->data[i];
        if (e.first > e.second)
            Swap(e.first, e.second);
        int found = table.FUN_00cb1c60(e.first, e.second);
        if (found <= table.capacity)
        {
            ++table.entries[found].value;
            apEdgesA->data[i].first = 0;
        }
        else
        {
            table.InsertKeyValue(GetPool()->allocator, e.first, e.second, (__int64)((i << 8) | 1));
        }
    }
    int size = 0;
    for (int j = 0; j < apEdgesB->count; ++j)
    {
        Edge e = apEdgesB->data[j];
        if (e.first > e.second)
            Swap(e.first, e.second);
        int found = table.FUN_00cb1c60(e.first, e.second);
        if (found <= table.capacity)
        {
            unsigned __int64 countA = table.entries[found].value;
            if (((int)countA & 0xff) > 1)
            {
                table.entries[found].value = countA + -1;
            }
            else
            {
                table.FUN_00cb1d20(found);
                apEdgesA->data[(unsigned int)countA >> 8].first = 0;
            }
        }
        else
        {
            apEdgesB->data[size++] = apEdgesB->data[j];
        }
    }
    ShrinkEdges(apEdgesB, size, GetPool()->allocator);
    size = 0;
    for (int i = 0; i < apEdgesA->count; ++i)
    {
        if (apEdgesA->data[i].first ? true : false)
            apEdgesA->data[size++] = apEdgesA->data[i];
    }
    ShrinkEdges(apEdgesA, size, GetPool()->allocator);
    table.FUN_00cb1e40(GetPool()->allocator);
    table.FUN_00a29680();
    ScratchAllocator& scratchRef = GetPool()->Scratch();
    if ((descriptor & 0x80000000) == 0)
        scratchRef.Release(pBuffer, descriptor & 0x3fffffff);
}
