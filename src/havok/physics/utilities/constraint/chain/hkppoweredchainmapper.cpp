
// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpPoweredChainMapper.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"



// The router accessor is 0x00c85750, also bound to hkMemoryRouter::GetMonitorStream.
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();


template <class T> __forceinline void constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

// The shared array declares allocator-dependent bodies for each unit to supply.
template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& e)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&alloc, this, sizeof(T));
    constructWithCopy<T>(m_data + m_iElementCount, 1, e);
    m_iElementCount++;
}

struct hkRowE3A5
{
    int m_slots[20];
};

struct hkTableE3A5
{
    int unk00[16];
    hkRowE3A5 m_rows[1];
};

struct hkOwnerE3A5
{
    int unk00[6];
    hkTableE3A5* m_table;
};

struct hkpPoweredChainMapperLinkInfo
{
    int m_iChainIndex;
    int m_iLinkIndex;
    hkReferencedObject* m_pConstraintInstance;
    hkpPoweredChainMapperLinkInfo() : m_iChainIndex(-1), m_iLinkIndex(0), m_pConstraintInstance(0)
    {}
};

struct hkpPoweredChainMapperTarget
{
    struct ChainInstance* m_pChainInstance;
    int m_targetIndex;
};

// Iterates the targets of a link and appends each non-zero motor pointer.
// @fnv 0x00e3a520
void hkpPoweredChainMapper::CollectSlotValues(int range, int slot, hkArray<int>& out)
{
    const hkpPoweredChainMapperLinkInfo& r = m_ppLinks.m_data[range];
    for (int i = 0; i < r.m_iLinkIndex; i++)
    {
        const hkpPoweredChainMapperTarget& ref = m_kTargets.m_data[r.m_iChainIndex + i];
        int v = ((hkOwnerE3A5*)ref.m_pChainInstance)->m_table->m_rows[ref.m_targetIndex].m_slots[slot];
        if (v)
            out.pushBack(v);
    }
}

struct FnPlacement
{
};
inline void* operator new(unsigned int, FnPlacement* p)
{
    return p;
}
extern "C" void __cdecl hkArrayUtil__reserve(hkMemoryAllocator*, void*, int, int);
extern "C" void __cdecl ResizeAudioStream(hkMemoryAllocator*, void*, int);
extern "C" void* __cdecl hkString_memSet(void*, int, unsigned int);
extern "C" int DAT_010e0654;

template <class T> struct FnArray
{
    T* data;
    int size;
    int capacity;
    FnArray() throw() : data(0), size(0), capacity(0x80000000)
    {}
    void initialize() throw()
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
    }
    ~FnArray() throw()
    {
        clear();
    }
    void clear()
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        size = 0;
        if (!(capacity & 0x80000000))
            heap.bufFree(data, sizeof(T) * (capacity & 0x3fffffff));
        data = 0;
        capacity = 0x80000000;
    }
    void reserve(hkMemoryAllocator& heap, int n)
    {
        int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            cap *= 2;
            if (n >= cap)
                cap = n;
            hkArrayUtil__reserve(&heap, this, cap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(hkMemoryAllocator& allocator, int count)
    {
        reserve(allocator, count);
        int n = count - size;
        T* p = data + size;
        if (n > 0)
            do
            {
                new ((FnPlacement*)p) T;
                ++p;
            } while (--n);
        size = count;
    }
    void push(const T& value)
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&heap, this, sizeof(T));
        T* destination = data + size;
        const T* source = &value;
        for (int i = 0; i < 1; ++i)
            *destination++ = *source++;
        ++size;
    }
    T& expand()
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&heap, this, sizeof(T));
        return data[size++];
    }
};
struct FnMap
{
    struct Entry
    {
        int key;
        int value;
    };
    Entry* data;
    int size;
    int capacity;
    FnMap() throw() : data(0), size(0), capacity(-1)
    {
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        EnsureCapacity(&heap, 0);
    }
    ~FnMap() throw()
    {
        ProcessArgument(hkMemoryRouter_getInstance()->m_heap);
        Object_DoNothing();
    }
    void __thiscall EnsureCapacity(hkMemoryAllocator*, int) throw();
    void __thiscall hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocator*, int, int) throw();
    int __thiscall FindSlot(int) throw();
    void __thiscall ProcessArgument(hkMemoryAllocator*) throw();
    void __thiscall Object_DoNothing() throw();
};
struct FnNodePair
{
    int first;
    int second;
};
struct FnVisit
{
    void* constraint;
    int localIndex;
    int linkIndex;
};
struct FnConstraint
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void reserved0C();
    virtual void VirtualFunction10();
    virtual void reserved14();
    virtual void reserved18();
    virtual void reserved1C();
    virtual int getType() throw();
};
struct FnObject
{
    int reserved00;
    int reserved04;
    int reserved08;
    FnConstraint* constraint;
    void __thiscall FUN_00c905b0() throw();
};
// Keep allocation and layout-only array initialization local to this unit.
__forceinline hkpPoweredChainMapper* allocatePoweredChainMapper()
{
    hkMemoryAllocator& allocator = hkMemoryRouter_getInstance()->heap();
    hkpPoweredChainMapper* p = (hkpPoweredChainMapper*)allocator.blockAlloc(sizeof(hkpPoweredChainMapper));
    p->m_usMemSizeAndFlags = (unsigned short)sizeof(hkpPoweredChainMapper);
    return p;
}
__forceinline void initializePoweredChainMapper(hkpPoweredChainMapper* p)
{
    *(void**)p = &DAT_010e0654;
    p->m_sReferenceCount = 1;
    ((FnArray<hkpPoweredChainMapperLinkInfo>&)p->m_ppLinks).initialize();
    ((FnArray<hkpPoweredChainMapperTarget>&)p->m_kTargets).initialize();
    ((FnArray<FnObject*>&)p->m_kChainInstances).initialize();
}
extern "C" int __cdecl hkpConstraintChainUtil_findConstraintLinkBetweenEntities(hkArray<int>*, int, int, FnArray<int>*, FnArray<int>*);
extern "C" FnObject* __cdecl hkpConstraintChainUtil_buildPoweredChain(FnArray<int>*, unsigned char);
extern "C" int __cdecl CloneInstanceFromSource(int);
struct FnDiagnostic
{
    int stream;
    int cursor;
    int capacity;
    void __thiscall FUN_00cb1600(char*, int) throw();
    void __thiscall ProcessAndReturnValue_00cc01c0(const char*) throw();
    void __thiscall FUN_00cc00e0() throw();
};
struct FnLogger
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void report(int, unsigned int, char*, const char*, int) throw();
};
extern "C" FnLogger* DAT_01268360;
inline void reportError(const char* message, unsigned int id, int line)
{
    unsigned int buffer[128];
    FnDiagnostic diagnostic;
    diagnostic.FUN_00cb1600((char*)buffer, 512);
    diagnostic.ProcessAndReturnValue_00cc01c0(message);
    DAT_01268360->report(1, id, (char*)buffer, ".\\Constraint\\Chain\\hkpPoweredChainMapper.cpp", line);
    diagnostic.FUN_00cc00e0();
}
__forceinline int buildOffsets(hkpPoweredChainMapper* mapper, FnArray<int>& linkCounts)
{
    int total = 0;
    for (unsigned int i = 0; (int)i < mapper->m_ppLinks.m_iElementCount; ++i)
    {
        mapper->m_ppLinks.m_data[i].m_iChainIndex = total;
        total += linkCounts.data[i];
        mapper->m_ppLinks.m_data[i].m_iLinkIndex = 0;
    }
    return total;
}
struct FnFlags
{
    unsigned char copyFallbacks;
    unsigned char includeChains;
};
// Builds a powered chain mapper by resolving constraint chains for node pairs, populating link offsets, targets, and optionally collecting unlinked ids.
// @fnv 0x00e3a5b0
hkpPoweredChainMapper* __cdecl BuildPoweredChainMapper(FnFlags flags, hkArray<int>* linkIds, hkArray<FnNodePair>* pairs,
                                                    hkArray<int>* unlinked) throw()
{
    hkpPoweredChainMapper* mapper = allocatePoweredChainMapper();
    initializePoweredChainMapper(mapper);

    FnArray<FnVisit> visits;
    FnArray<int> linkCounts;
    int count = linkIds->m_iElementCount;
    linkCounts.reserve(hkMemoryRouter_getInstance()->heap(), count);
    linkCounts.size = count;
    hkString_memSet(linkCounts.data, 0, 4 * count);
    FnMap table;
    for (int k = 0; k < linkIds->m_iElementCount; ++k)
    {
        int key = linkIds->m_data[k];
        hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
        table.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(&heap, key, k);
    }
    count = linkIds->m_iElementCount;
    ((FnArray<hkpPoweredChainMapperLinkInfo>&)mapper->m_ppLinks).SetSizeAndGrow(hkMemoryRouter_getInstance()->heap(), count);
    hkString_memSet(mapper->m_ppLinks.m_data, 0, 12 * mapper->m_ppLinks.m_iElementCount);
    for (int pairIndex = 0; pairIndex < pairs->m_iElementCount; ++pairIndex)
    {
        FnArray<int> scratch;
        FnArray<int> chainLinks;
        FnNodePair& pair = pairs->m_data[pairIndex];
        if (hkpConstraintChainUtil_findConstraintLinkBetweenEntities(linkIds, pair.first, pair.second, &scratch, &chainLinks) == 1)
        {
            reportError("Cannot find a chain of constraints linking one of the entity pairs.", 0xabbaaa88, 68);
            mapper->removeReference();
            return 0;
        }
        FnObject* obj = hkpConstraintChainUtil_buildPoweredChain(&chainLinks, flags.includeChains);
        if (!obj)
        {
            reportError("Failed to build a chain.", 0xabbaddaa, 78);
            mapper->removeReference();
            return 0;
        }
        ((FnArray<FnObject*>&)mapper->m_kChainInstances).push(obj);
        for (int j = 0; j < chainLinks.size; ++j)
        {
            int entity = chainLinks.data[j];
            int index = table.FindSlot(entity);
            if (index > table.capacity)
            {
                reportError("Internal error.", 0xabba99dd, 93);
                obj->FUN_00c905b0();
                mapper->removeReference();
                return 0;
            }
            int linkIndex = table.data[index].value;
            hkpPoweredChainMapperLinkInfo* link = &mapper->m_ppLinks.m_data[linkIndex];
            FnVisit& v = visits.expand();
            v.linkIndex = linkIndex;
            ++linkCounts.data[linkIndex];
            if (obj->constraint->getType() != 0x66)
            {
                reportError("Internal error; invalid chain type.", 0xabba9d6d, 108);
                obj->FUN_00c905b0();
                mapper->removeReference();
                return 0;
            }
            v.constraint = obj->constraint;
            v.localIndex = j;
            if (flags.copyFallbacks && !link->m_pConstraintInstance)
                link->m_pConstraintInstance = (hkReferencedObject*)CloneInstanceFromSource(chainLinks.data[j]);
        }
    }
    int total = buildOffsets(mapper, linkCounts);
    ((FnArray<hkpPoweredChainMapperTarget>&)mapper->m_kTargets).SetSizeAndGrow(hkMemoryRouter_getInstance()->heap(), total);
    for (int i = 0; i < visits.size; ++i)
    {
        FnVisit& visit = visits.data[i];
        hkpPoweredChainMapperLinkInfo& link = mapper->m_ppLinks.m_data[visit.linkIndex];
        hkpPoweredChainMapperTarget& target = mapper->m_kTargets.m_data[link.m_iChainIndex + link.m_iLinkIndex];
        target = *(hkpPoweredChainMapperTarget*)&visit;
        ++link.m_iLinkIndex;
    }
    if (unlinked)
    {
        for (int i = 0; i < mapper->m_ppLinks.m_iElementCount; ++i)
        {
            if (!mapper->m_ppLinks.m_data[i].m_iLinkIndex)
            {
                int& key = linkIds->m_data[i];
                ((FnArray<int>*)unlinked)->push(key);
            }
        }
    }
    return mapper;
}

#include <xmmintrin.h>
struct TargetRuntime
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __m128 m_vVectorData;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};

struct ChainInstance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    TargetRuntime* m_pRuntime;
};

// Writes vec into the runtime vector slot of every target belonging to the link at chainIndex.
// @fnv 0x00e3a4d0
void hkpPoweredChainMapper::SetLinkVector(int chainIndex, const __m128& vec)
{
    hkpPoweredChainMapperLinkInfo& linkInfo = m_ppLinks.m_data[chainIndex];
    for (int i = 0; i < linkInfo.m_iLinkIndex; ++i)
    {
        hkpPoweredChainMapperTarget& target = m_kTargets.m_data[linkInfo.m_iChainIndex + i];
        target.m_pChainInstance->m_pRuntime[target.m_targetIndex].m_vVectorData = vec;
    }
}

struct hkpConstraintEntryE3A3
{
    hkReferencedObject* m_pHavokConstraint;
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
};

namespace FUN_00e3a3d0 {
class hkpConstraintChainMapperE3A3 : public hkReferencedObject
{
  public:
    hkArray<hkpConstraintEntryE3A3> m_entries;

    virtual ~hkpConstraintChainMapperE3A3() throw();
};

// Iterates over m_entries and calls removeReference on each m_pHavokConstraint.
// @fnv 0x00e3a3d0
hkpConstraintChainMapperE3A3::~hkpConstraintChainMapperE3A3() throw()
{
    const int iEntryIndex = m_entries.m_iElementCount;
    for (int i = 0; i < iEntryIndex; i++)
        m_entries[i].m_pHavokConstraint->removeReference();
}
}

// Havok buffer deallocation uses allocator vtable slot 4 (ReturnMemory).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance()->heap();
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    for (int i = 0; i < m_iElementCount; i++)
        m_data[i].~T();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}

// @fnv 0x00e3ad80
hkpPoweredChainMapper::~hkpPoweredChainMapper() throw()
{
    for (int i = 0; i < m_ppLinks.m_iElementCount; i++)
    {
        if (m_ppLinks[i].m_pConstraintInstance)
            m_ppLinks[i].m_pConstraintInstance->removeReference();
    }
    for (int i = 0; i < m_kChainInstances.m_iElementCount; i++)
        ((hkReferencedObject*)m_kChainInstances.m_data[i])->removeReference();
}

