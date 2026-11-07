#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/Pair.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"

// src/havok/common/serialize/version/hkversionpatchmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionpatchmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* __cdecl hkString_strDup_00cb1410(unsigned int);
struct FUN_00d479e0_class
{
    void* GetValue(const void* a, const void* b);
};
struct FUN_00d874d0_s
{
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* a, int b);
};
struct FUN_00db7d00_class
{
    void* __thiscall hkVersionPatchManager_UidFromClassVersion_cache(unsigned int a);
};
// @fnv 0x00db7d00
// src: XBOX_PDB 0x00db7d00
void* __thiscall FUN_00db7d00_class::hkVersionPatchManager_UidFromClassVersion_cache(unsigned int a)
{
    if (a)
    {
        void* p = ((FUN_00d479e0_class*)((char*)this + 0x1c))->GetValue((const void*)a, 0);
        if (!p)
        {
            p = hkString_strDup_00cb1410(a);
            ((FUN_00d874d0_s*)((char*)this + 0x1c))->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert((const char*)p, (int)p);
        }
        return p;
    }
    return 0;
}

struct DB7DD0Inner
{
    void ComputeValue_00db7d60();
};

struct DB7DD0Outer
{
    int unk00;
    int unk04;
    DB7DD0Inner* m_inner;

    void hkVersionPatchManager_getUid();
};

// @fnv 0x00db7dd0
// src: XBOX_PDB 0x00db7dd0
void DB7DD0Outer::hkVersionPatchManager_getUid()
{
    m_inner->ComputeValue_00db7d60();
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct GraphEntry
{
    void* m_pKey;
    int m_iNext;
};

struct GraphTable
{
    GraphEntry* m_pEntries;

    int LookupWithDefault(void* apKey);
};

struct DepthLimit
{
    int unk00;
    int unk04;
    int m_iLimit;

    int FindSlot(void* apItem);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* apAllocator, void* apItem, int aiFlag);
};

// @fnv 0x00db7e70
// src: GUESS 0x00db7e70 (confidence: low)
int __cdecl hkMemoryRouter_ProcessEntries_00db7e70(void* apTarget, void* apItem, GraphTable* apTable, DepthLimit* apDepth)
{
    if (apDepth->FindSlot(apItem) > apDepth->m_iLimit)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        void* pAllocator = pHolder->m_heap;
        apDepth->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(pAllocator, apItem, 0);

        int iIndex = apTable->LookupWithDefault(apItem);
        while (iIndex != -1)
        {
            void* pKey = apTable->m_pEntries[iIndex].m_pKey;
            if (apTarget == pKey)
                return 1;
            if (hkMemoryRouter_ProcessEntries_00db7e70(apTarget, pKey, apTable, apDepth) != 0)
                return 1;
            iIndex = apTable->m_pEntries[iIndex].m_iNext;
        }
    }
    return 0;
}

namespace fnv_00db8540 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct ByteTag
{
    char m_cValue;

    ByteTag() : m_cValue(0)
    {}

    ~ByteTag()
    {}
};

struct ArrayHeader
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ArrayHeader() : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};

struct TaggedList
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;

    void FUN_00d87790(ByteTag akTag);
};

struct CreatedObject
{
    TaggedList m_kFirst;
    ArrayHeader m_kArray;
    TaggedList m_kSecond;
};

struct PoolHolder
{
    void* m_p00;
    int m_i04;
    int m_i08;

    PoolHolder() : m_p00(0), m_i04(0), m_i08(-1)
    {}

    void ResizeToFit(hkMemoryAllocator* apAllocator, int aiFlag);
};

struct FUN_00db8540
{
    virtual void v00();

    short m_s04;
    unsigned short m_u06;
    CreatedObject* m_pCreated;
    ArrayHeader m_kArray;
    PoolHolder m_kEntryPool;

    FUN_00db8540();
};

// @fnv 0x00db8540
FUN_00db8540::FUN_00db8540() : m_u06(1)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    m_kEntryPool.ResizeToFit(pAllocator, 0);

    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    CreatedObject* pNew = (CreatedObject*)reinterpret_cast<hkMemoryAllocator*>(pAllocator2)->blockAlloc(sizeof(CreatedObject));
    if (pNew)
    {
        {
            ByteTag kTag;
            pNew->m_kFirst.FUN_00d87790(kTag);
        }
        pNew->m_kArray.m_pData = 0;
        pNew->m_kArray.m_iArrayLength = 0;
        pNew->m_kArray.m_uCapacity = 0x80000000;
        {
            ByteTag kTag;
            pNew->m_kSecond.FUN_00d87790(kTag);
        }
        m_pCreated = pNew;
    }
    else
    {
        m_pCreated = 0;
    }
}
}  // namespace fnv_00db8540

struct DBA230Entry
{
    unsigned __int64 m_key;
    int unk08;
    int unk0C;
};

struct DBA230Array
{
    DBA230Entry* m_data;
    int m_iElementCount;

    bool ContainsKey(const unsigned __int64& key);
};

// Scans the array's entries and returns true if any entry's m_key equals key, otherwise false.
// @fnv 0x00dba230
bool DBA230Array::ContainsKey(const unsigned __int64& aullKey)
{
    for (int i = 0; i < m_iElementCount; i++)
    {
        if (aullKey == m_data[i].m_key)
            return true;
    }
    return false;
}

namespace fnv_00dbe710 {
hkMemoryRouter* hkMemoryRouter_getInstance();
void ResizeAudioStream(hkMemoryAllocator* alloc, void* arr, int elemSize);

struct S_00dbe710_Elem
{
    int m_uiFilterValue;
    int m_next;
};

struct S_00dbe710
{
    S_00dbe710_Elem* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int unkC;
    int unk10;
    int unk14;
    int m_firstFree;
    int AllocateSlot();
};
// Returns a free slot index from the free list, or grows the array via the router's heap and returns the next index.
// @fnv 0x00dbe710
int S_00dbe710::AllocateSlot()
{
    int idx = m_firstFree;
    if (idx != -1)
    {
        m_firstFree = m_data[idx].m_next;
        return idx;
    }
    int n = m_iElementCount;
    hkMemoryRouter* r = hkMemoryRouter_getInstance();
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(r->m_heap), this, 8);
    m_iElementCount++;
    return n;
}
}  // namespace fnv_00dbe710

// @fnv 0x00db7cb0
// src: GUESS 0x00db7cb0 (confidence: low)
int __cdecl Hkversionpatchmanager_EvaluateValue_00db7cb0(int* values)
{
    if (values[2] == -1)
    {
        if ((values[0] != 0 || values[3] == -1) || values[1] == 0)
        {
            return 0;
        }
    }
    else if (values[3] == -1)
    {
        if (values[0] == 0)
        {
            return 0;
        }
        if (values[1] != 0)
        {
            return 0;
        }
    }
    else if (values[0] == 0)
    {
        return 0;
    }

    return 1;
}

// FindEntry (0x00db7de0, 134 bytes)
//
// Walks a spatial index: it asks the index object (embedded at this+0x18) for
// the next candidate, looks the entry up in the table at this+0x0c, optionally
// validates it and then hands it to the owner object at this+0x08, which
// returns the key that is used to ask the index for the next candidate.
//
// NOTE: FUN_00db7d60 is only DECLARED in the original translation unit, but
// the original code keeps the "key" value in EDX across the call to it (the
// original callee happens to leave the key in EDX).  To make MSVC 2008 pick
// the same register the helper is given a stand-in body that does not touch
// EDX and is marked __declspec(noinline) so that the call is not inlined.

struct Entry_t
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct Index_t
{
    unsigned int unk00;
    int __thiscall hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(int a, int b, int c, int d);
};

struct Owner_t
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int __thiscall ComputeValue_00db7d60(unsigned int a, unsigned int b);
};

// src: GUESS 0x00db7d60 (confidence: low)
__declspec(noinline) int __thiscall Owner_t::ComputeValue_00db7d60(unsigned int a, unsigned int b)
{
    return (int)a;
}

extern "C" int __cdecl hkString_strCmp(unsigned int a, unsigned int b);

struct Cls_t
{
    unsigned int unk00;
    unsigned int unk04;
    Owner_t* m08;
    Entry_t** m0C;
    unsigned int unk10;
    unsigned int unk14;
    Index_t m18;

    int FindEntry(int a, int b, int c);
};

// Searches m18 for an index whose entry has unk0C == -1 or, when c is 0, a nonzero unk04 passing FUN_00cb0fa0; returns the index or -1.
// @fnv 0x00db7de0
int Cls_t::FindEntry(int a, int b, int aiFlag)
{
    Index_t* pIndex = &m18;
    int idx = pIndex->hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(a, b, -1, -1);
    while (idx != -1)
    {
        Entry_t* e = m0C[idx];
        if (e->unk0C == 0xffffffff)
        {
            return idx;
        }
        if (aiFlag == 0 && e->unk04 != 0)
        {
            if (hkString_strCmp(e->unk00, e->unk04) != 0)
            {
                return idx;
            }
        }
        unsigned int key = e->unk04;
        unsigned int r = (unsigned int)m08->ComputeValue_00db7d60(key, e->unk0C);
        idx = pIndex->hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault((int)r, (int)key, -1, -1);
    }
    return -1;
}

struct HelperClass
{
    int hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(int a, int b, int c, int d);
};
struct OwnerClass
{
    int unk00, unk04, unk08;
    HelperClass helper;
    int CallHelperWithDefaults(int first, int second);
};
// @fnv 0x00dba210
int OwnerClass::CallHelperWithDefaults(int first, int second)
{
    return helper.hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(first, second, -1, -1);
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int iReqCapacity, int iElementSize);
void __cdecl hkMemUtil_memMove(void* pvDst, const void* pvSrc, int iNumBytes);

inline void* __cdecl operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}

struct BDBA270Element
{
    int m_iA;
    int m_iB;
    int m_iC;
    int m_iD;
};

typedef hkArrayBase<BDBA270Element> BDBA270Array;

// @fnv 0x00dba270
void BDBA270Array::_spliceInto(hkMemoryAllocator& kAlloc, int iIndex, int iNumToDel, const BDBA270Element* pkItems,
                          int iNumToInsert)
{
    int iNewSize = m_iElementCount - iNumToDel + iNumToInsert;
    int iNumToMove = m_iElementCount - iIndex - iNumToDel;
    if (getCapacity() < iNewSize)
    {
        int iNewCapacity = 2 * getCapacity();
        hkArrayUtil__reserve(kAlloc, this, iNewSize < iNewCapacity ? iNewCapacity : iNewSize, sizeof(BDBA270Element));
    }
    hkMemUtil_memMove(m_data + iIndex + iNumToInsert, m_data + iIndex + iNumToDel, iNumToMove * sizeof(BDBA270Element));
    BDBA270Element* pkDst = m_data + iIndex;
    for (int i = 0; i < iNumToInsert; i++)
        new (pkDst + i) BDBA270Element(pkItems[i]);
    m_iElementCount = iNewSize;
}

struct FUN_00dc7fd0_sub
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void FUN_00d87790(unsigned int a);
    void InitializeFields_00dc9e70();
};

struct FUN_00dc7fd0_subw
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    void FUN_00d87790(unsigned int a);
    void InitializeFields_00dc9e70();
};

struct FUN_00dc7fd0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    FUN_00dc7fd0_subw m_10;
    int m_2c;
    FUN_00dc7fd0_subw m_30;
    FUN_00dc7fd0_sub m_4c;
    FUN_00dc7fd0_sub m_5c;
    FUN_00dc7fd0_sub m_6c;

    FUN_00dc7fd0_cls* Initialize();
    void FUN_00d87790(unsigned int a);
};

// @fnv 0x00dc7fd0
FUN_00dc7fd0_cls* FUN_00dc7fd0_cls::Initialize()
{
    unsigned char flag = 0;
    this->FUN_00d87790(*(unsigned int*)&flag);
    m_10.InitializeFields_00dc9e70();
    m_2c = 0;
    m_30.InitializeFields_00dc9e70();
    flag = 0;
    m_4c.FUN_00d87790(*(unsigned int*)&flag);
    flag = 0;
    m_5c.FUN_00d87790(*(unsigned int*)&flag);
    m_6c.InitializeFields_00dc9e70();
    return this;
}

namespace fnvc_adapt {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkMemoryRouter_easyFree(hkMemoryAllocator* pkAllocator, void* pvMem) throw();

template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        hkMemoryAllocator& alloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}

class DB7F50Map
{
  public:
    ~DB7F50Map() throw();

    int GetFirstIterator() throw();
    void* getValue(int it) throw();
    int getNext(int it) throw();
    void isValid(bool* pbValid, int it) throw();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00db7f50 : public DB7F50Map
{
  public:
    ~FUN_00db7f50() throw();

    hkArray<void*> m_kEntries;
    DB7F50Map m_kValues;
};

// @fnv 0x00db7f50
FUN_00db7f50::~FUN_00db7f50() throw()
{
    DB7F50Map* pkValues = &m_kValues;
    bool bValid;
    int it = pkValues->GetFirstIterator();
    pkValues->isValid(&bValid, it);
    if (bValid)
    {
        do
        {
            void* pvValue = pkValues->getValue(it);
            hkMemoryRouter_easyFree(&fnvc_adapt::hkMemoryRouter_getInstance().heap(), pvValue);
            it = pkValues->getNext(it);
            pkValues->isValid(&bValid, it);
        } while (bValid);
    }
}

class BSAudio;
namespace fnv_00db83c0 {


namespace fnvc_adapt {
__declspec(nothrow) BSAudio* __cdecl hkMemoryRouter_getInstance();
}
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)fnvc_adapt::hkMemoryRouter_getInstance();
}

__declspec(nothrow) void __cdecl ResizeAudioStream(void*, void*, int);

inline void constructWithCopy(int* p, int n, const int& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}
typedef hkArray<int> hkIntArray;
}
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
using namespace fnv_00db83c0;
return reinterpret_cast<hkMemoryAllocator&>(audio()->heap());
}
template<> __forceinline void hkArrayBase<int>::_pushBack(hkMemoryAllocator& sharedAlloc, int const& e)
{
using namespace fnv_00db83c0;
hkMemoryAllocator& alloc = reinterpret_cast<hkMemoryAllocator&>(sharedAlloc);

        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(int));
        constructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    
}
namespace fnv_00db83c0 {


struct LocalBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[32];
    __declspec(nothrow) void InitBuffer();
};

struct GraphEdge
{
    int target;
    int next;
};

struct Graph
{
    GraphEdge* m_kEdges;
    int m_numEdges;
    int m_iCapacityState;
    __declspec(nothrow) int LookupWithDefault(int node);
};

// @fnv 0x00db83c0
// src: GUESS 0x00db83c0 (confidence: low)
int __cdecl hkIntArray_ProcessEntries_00db83c0(int node, hkIntArray* state, Graph* graph, int counter, hkIntArray* stack, int arg)
{
    if (state->m_data[node] == -1)
    {
        state->m_data[node] = -2;
        stack->pushBack(node);
        for (int e = graph->LookupWithDefault(node); e != -1; e = graph->m_kEdges[e].next)
        {
            int other = graph->m_kEdges[e].target;
            switch (state->m_data[other])
            {
            case -1:
                counter = hkIntArray_ProcessEntries_00db83c0(other, state, graph, counter, stack, arg);
                break;
            case -2: {
                stack->pushBack(other);
                LocalBuf buf;
                buf.InitBuffer();
                stack->m_iElementCount--;
                hkMemoryAllocator& alloc = audio()->temp();
                buf.m_iElementCount = 0;
                if ((buf.m_iCapacityState & 0x80000000) == 0)
                    alloc.bufFree(buf.m_data, buf.m_iCapacityState & 0x3fffffff);
                break;
            }
            }
        }
        stack->m_iElementCount--;
        state->m_data[node] = counter;
        return counter + 1;
    }
    return counter;
}
}  // namespace fnv_00db83c0

namespace fnv_00db85e0 {
namespace fnvc_adapt {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
}

struct DB85E0Impl
{
    ~DB85E0Impl();

    static void operator delete(void* p, unsigned int nbytes)
    {
        fnvc_adapt::hkMemoryRouter_getInstance().heap().blockFree(p, nbytes);
    }

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
};

struct DB85E0MapBase
{
    ~DB85E0MapBase();

    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};

struct DB85E0Map : DB85E0MapBase
{
    void ClearAndRelease(hkMemoryAllocator& alloc);
    __forceinline ~DB85E0Map()
    {
        ClearAndRelease(fnvc_adapt::hkMemoryRouter_getInstance().heap());
    }
};

typedef hkArray<int> DB85E0IntArray;

class DB85E0ReferencedObject
{
  public:
    virtual ~DB85E0ReferencedObject() throw()
    {}

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00db85e0 : public DB85E0ReferencedObject
{
  public:
    virtual ~FUN_00db85e0() throw();

    DB85E0Impl* m_pClassImpl;
    DB85E0IntArray m_ppIndices;
    DB85E0Map m_map;
};

// @fnv 0x00db85e0
FUN_00db85e0::~FUN_00db85e0() throw()
{
    if (m_pClassImpl)
        delete m_pClassImpl;
}
}  // namespace fnv_00db85e0

namespace fnv_00dba1e0 {
namespace fnvc_adapt {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
}

class DBA1E0ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        DBA1E0ReferencedObject* b =
            static_cast<DBA1E0ReferencedObject*>(fnvc_adapt::hkMemoryRouter_getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~DBA1E0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DBA1E0Object : public DBA1E0ReferencedObject
{
  public:
    __declspec(nothrow) DBA1E0Object();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

// Allocates and constructs a DBA1E0Object via its custom operator new and returns the pointer.
// @fnv 0x00dba1e0
DBA1E0Object* __cdecl CreateDBA1E0Object()
{
    return new DBA1E0Object();
}
}  // namespace fnv_00dba1e0

namespace fnv_00db95c0 {
// Reordered source-vector loop and allocator acquisition; official check pending.
extern "C" void* __cdecl hkString_strDup_00cb1410(unsigned int);
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* a, void* arr, int sz, int elem) throw();
void __cdecl ResizeAudioStream(hkMemoryAllocator* a, void* arr, int elem) throw();
struct VecP
{
    void** m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(hkMemoryAllocator& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.bufFree(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~VecP() throw()
    {
        hkMemoryAllocator& alloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.bufFree(m_pData, (m_iCapacity & 0x3fffffff) * 4);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
struct VecPair
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(hkMemoryAllocator& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.bufFree(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~VecPair() throw()
    {
        hkMemoryAllocator& alloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.bufFree(m_pData, (m_iCapacity & 0x3fffffff) * 8);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
template <class T> __forceinline void constructArray(T* p, int n, const T& t) throw()
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct WorkRecord
{
    unsigned __int64 key;
    int index;
    int dependency;
};
struct Vec16
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(hkMemoryAllocator& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.bufFree(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~Vec16() throw()
    {
        hkMemoryAllocator& alloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.bufFree(m_pData, (m_iCapacity & 0x3fffffff) * 16);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
struct ClassMember
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
typedef hkArray<ClassMember> IndexedMemberArray;
struct ClassCinfo
{
    int name;
    int version;
    int parent;
    IndexedMemberArray members;
};
struct ObjCB
{
    void* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void ResizeToFit(hkMemoryAllocator* a, int b) throw();
    int hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(unsigned __int64 key) throw();
    void InsertKeyValue(hkMemoryAllocator* a, unsigned __int64 key, __int64 value) throw();
    void hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_clearAndDeallocate(hkMemoryAllocator* a) throw();
    void Object_DoNothing() throw();
};
struct StrX
{
    int m_00;
    void SetField00(void* a) throw();
    int TestValue() throw();
    void Object_DoNothing_00dba660() throw();
};
struct HelperX
{
    int m_00;
    int m_04;
    int m_08;
    void hkDataWorldDict_hkDataWorldDict() throw();
    void ReleaseStorage_00dc8080() throw();
    void* hkDataWorldDict_findClass(int a) throw();
    void wrapClass(void* a) throw();
    void* CreateItem(void* a) throw();
    void hkDataWorldDict_findAllClasses(void* a) throw();
    void RenameClassMember(StrX* a, int b, int c) throw();
    void FUN_00dc7d20(StrX* a, int b, int c, int d, int e) throw();
    void ProcessEntries_00dc7600(StrX* a, int b) throw();
    void AssignRefCountedSlot(StrX* a, StrX* b) throw();
    void ReleaseRef(StrX* a) throw();
    void hkDataWorldDict_renameClass(StrX* a, int b) throw();
    void hkDataWorldDict_setClassVersion(StrX* a, int b) throw();
};
struct MgrA
{
    int m_00;
    int m_04;
    int m_08;
    MgrA* ProcessAndReturnValue_00cc01c0(void* a) throw();
    MgrA* WriteInt(int a) throw();
    void FUN_00cb1600(void* a, int b) throw();
    void FUN_00cc00e0() throw();
    void FUN_00d87790(int a) throw();
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(int a, void* b) throw();
    void* GetValue(int a, int b) throw();
    void ProcessAndReturnValue_00d87820(int a) throw();
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator() throw();
    void SetBoolFromThreshold(void* valid, int iterator) throw();
    void* hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int a) throw();
    int FindNextUsedSlot(int a) throw();
    void FreeBuffer() throw();
};
struct MapTag
{
    char m_00;
};
struct MgrB
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void FUN_00d87790(MapTag a) throw();
    void ProcessAndReturnValue_00d87820(int a) throw();
    void FreeBuffer() throw();
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(int a, void* b) throw();
    void* GetValue(int a, int b) throw();
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator() throw();
    void SetBoolFromThreshold(void* valid, int iterator) throw();
    void* hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int a) throw();
    int FindNextUsedSlot(int a) throw();
};
struct ErrorBuffer
{
    int words[128];
};
struct LogSink
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void FUN_v3(int a, int b, void* c, const char* d, int e) throw();
};
extern LogSink* DAT_01268360;
struct VerObj
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual int FUN_v2() throw();
    int FUN_00d47120() throw();
    int FUN_00d46d40() throw();
};
struct Pair5
{
    int m_00;
    int* m_04;
};
struct Elem
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Pair5* m_10;
    int m_14;
};
struct VObj
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual int FUN_v2() throw();
    virtual int FUN_v3() throw();
};
struct ArgA
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual VerObj* FUN_v4(int a) throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void FUN_v8(void* a) throw();
    void copyClassFromWorld(int name, HelperX* world) throw();
};
// src: GUESS 0x00db7cb0 (confidence: low)
__declspec(noinline) int __cdecl Hkversionpatchmanager_EvaluateValue_00db7cb0(int* v)
{
    if (v[2] == -1)
    {
        if (v[0] != 0 || v[3] == -1 || v[1] == 0)
            return 0;
    }
    else if (v[3] == -1)
    {
        if (v[0] == 0 || v[1] != 0)
            return 0;
    }
    else if (v[0] == 0)
        return 0;
    return 1;
}
int __cdecl setAllDependeciesToDo(Vec16* out, int lo, int hi, void* a, void* b, ObjCB* c, ObjCB* d) throw();
struct Owner8
{
    unsigned __int64 ComputeValue_00db7d60(int a, int b) throw();
};
struct This
{
    int m_00;
    int m_04;
    Owner8* m_08;
    Elem** m_0c;
    int m_10;
    int HkVersionPatchManager_UidFromClassVersion_getName_Thunk(int a, int b) throw();
    int ForwardToInner(int a, int b) throw();
    int ProcessVersionPatches(ArgA* a, ArgA* b, VecP* c) throw();
};
struct ClassWorld : HelperX
{
    ClassWorld() throw()
    {
        hkDataWorldDict_hkDataWorldDict();
    }
    ~ClassWorld() throw()
    {
        ReleaseStorage_00dc8080();
    }
};
struct PointerMap : ObjCB
{
    PointerMap() throw()
    {
        m_pData = 0;
        m_iArrayLength = 0;
        m_iCapacity = -1;
        hkMemoryRouter* holder = (hkMemoryRouter*)&fnvc_adapt::hkMemoryRouter_getInstance();
        ResizeToFit((hkMemoryAllocator*)holder->m_heap, 0);
    }
    ~PointerMap() throw()
    {
        hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_clearAndDeallocate((hkMemoryAllocator*)fnvc_adapt::hkMemoryRouter_getInstance().m_heap);
        Object_DoNothing();
    }
};
// Validates version patches, resolves class dependencies, and registers updated class definitions into the world.
// @fnv 0x00db95c0
int This::ProcessVersionPatches(ArgA* apSource, ArgA* argB, VecP* apOutput)
{
    VecP pSource;
    pSource.m_pData = 0;
    pSource.m_iArrayLength = 0;
    pSource.m_iCapacity = (int)0x80000000;
    apSource->FUN_v8(&pSource);
    VecPair pairs;
    pairs.m_pData = 0;
    pairs.m_iArrayLength = 0;
    pairs.m_iCapacity = (int)0x80000000;
    int initialCount = pSource.m_iArrayLength;
    hkMemoryRouter* initialHolder = ((hkMemoryRouter*)&fnvc_adapt::hkMemoryRouter_getInstance());
    if ((pairs.m_iCapacity & 0x3fffffff) < initialCount)
        hkArrayUtil__reserve(((hkMemoryAllocator*)initialHolder->m_heap), &pairs, initialCount, 8);
    int i;
    for (i = 0; i < pSource.m_iArrayLength; i++)
    {
        VObj* e = (VObj*)pSource.m_pData[i];
        int lo = ((VObj*)pSource.m_pData[i])->FUN_v2();
        int hi = ((VObj*)pSource.m_pData[i])->FUN_v3();
        int* dest = pairs.m_pData + pairs.m_iArrayLength * 2;
        if (dest)
        {
            dest[0] = lo;
            dest[1] = hi;
        }
        pairs.m_iArrayLength++;
    }
    ClassWorld world;
    PointerMap oDone;
    PointerMap oPending;
    ErrorBuffer oErr;
    int p;
    for (p = 0; p < m_10; p++)
    {
        Elem* elem = m_0c[p];
        int ok = Hkversionpatchmanager_EvaluateValue_00db7cb0((int*)elem);
        if (!ok)
            return 1;
        if (elem->m_08 != -1)
            continue;
        unsigned __int64 id = m_08->ComputeValue_00db7d60(elem->m_04, elem->m_0c);
        int idx = oPending.hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(id);
        if (idx <= oPending.m_iCapacity)
            return 1;
        hkMemoryRouter* mapHolder = ((hkMemoryRouter*)&fnvc_adapt::hkMemoryRouter_getInstance());
        oPending.InsertKeyValue((hkMemoryAllocator*)mapHolder->m_heap, id, (__int64)p);
    }
    apOutput->m_iArrayLength = 0;
    {
        Vec16 work;
        work.m_pData = 0;
        work.m_iArrayLength = 0;
        work.m_iCapacity = (int)0x80000000;
        {
            int s;
            for (s = 0; s < pairs.m_iArrayLength; s++)
            {
                setAllDependeciesToDo(&work, pairs.m_pData[s * 2], pairs.m_pData[s * 2 + 1], apSource, this, &oPending, &oDone);
            }
        }
        while (work.m_iArrayLength != 0)
        {
            WorkRecord item = *(WorkRecord*)work.m_pData;
            unsigned __int64 uiKey = item.key;
            int iKeyLo = (int)uiKey;
            int iKeyHi = (int)(uiKey >> 32);
            int iIndex = item.index;
            work.m_iArrayLength--;
            {
                int remaining = work.m_iArrayLength * 16;
                unsigned __int64* from = (unsigned __int64*)(work.m_pData + 4);
                unsigned __int64* dst = (unsigned __int64*)work.m_pData;
                while (remaining > 0)
                {
                    *dst = *from;
                    ++from;
                    ++dst;
                    remaining -= 8;
                }
            }
            if (iIndex != -1 && m_0c[iIndex]->m_08 == -1)
            {
                hkMemoryRouter* holder = ((hkMemoryRouter*)&fnvc_adapt::hkMemoryRouter_getInstance());
                oDone.InsertKeyValue((hkMemoryAllocator*)holder->m_heap, uiKey, 1);
            }
            else
            {
                hkMemoryRouter* holder = ((hkMemoryRouter*)&fnvc_adapt::hkMemoryRouter_getInstance());
                oDone.InsertKeyValue((hkMemoryAllocator*)holder->m_heap, uiKey, 2);
            }
            if (iIndex >= 0)
            {
                Elem* pElem = m_0c[iIndex];
                hkMemoryAllocator& oAppendAlloc = fnvc_adapt::hkMemoryRouter_getInstance().heap();
                if (apOutput->m_iArrayLength == (apOutput->m_iCapacity & 0x3fffffff))
                    ResizeAudioStream((hkMemoryAllocator*)&oAppendAlloc, apOutput, 4);
                constructArray(apOutput->m_pData + apOutput->m_iArrayLength, 1, (void*)pElem);
                apOutput->m_iArrayLength++;
                {
                    Elem* pe = m_0c[iIndex];
                    setAllDependeciesToDo(&work, pe->m_04 ? pe->m_04 : pe->m_00, pe->m_0c, apSource, this, &oPending, &oDone);
                }
            }
            else
            {
                int q1 = HkVersionPatchManager_UidFromClassVersion_getName_Thunk(iKeyLo, iKeyHi);
                int q2 = ForwardToInner(iKeyLo, iKeyHi);
                if (q2 != -1)
                {
                    VerObj* pVerObj = argB->FUN_v4(q1);
                    if (!pVerObj)
                        return 1;
                    if (pVerObj->FUN_00d47120() != q2)
                    {
                        MgrA oErrorStream;
                        oErrorStream.FUN_00cb1600(&oErr, 0x200);
                        oErrorStream.ProcessAndReturnValue_00cc01c0((void*)"Found class ")
                            ->ProcessAndReturnValue_00cc01c0((void*)q1)
                            ->ProcessAndReturnValue_00cc01c0((void*)" of version ")
                            ->WriteInt(pVerObj->FUN_00d47120())
                            ->ProcessAndReturnValue_00cc01c0((void*)", but expected version ")
                            ->WriteInt(q2)
                            ->ProcessAndReturnValue_00cc01c0((void*)".\nMake sure required patches are registered to update the class ")
                            ->ProcessAndReturnValue_00cc01c0((void*)q1)
                            ->ProcessAndReturnValue_00cc01c0((void*)" from version ")
                            ->WriteInt(q2)
                            ->ProcessAndReturnValue_00cc01c0((void*)" to ")
                            ->WriteInt(pVerObj->FUN_00d47120())
                            ->ProcessAndReturnValue_00cc01c0((void*)",\nor update the class definition with the //+version(")
                            ->WriteInt(q2)
                            ->ProcessAndReturnValue_00cc01c0((void*)") annotation.");
                        DAT_01268360->FUN_v3(1, 0x3f79ddb1, &oErr, ".\\Version\\hkVersionPatchManager.cpp", 0x2fe);
                        oErrorStream.FUN_00cc00e0();
                        return 1;
                    }
                    int hv = pVerObj->FUN_00d46d40();
                    if (!world.hkDataWorldDict_findClass(hv))
                        world.wrapClass(pVerObj);
                }
            }
        }
    }

    {
        {
            int ii;
            for (ii = apOutput->m_iArrayLength - 1; ii >= 0; ii--)
            {
                Elem* ce = (Elem*)apOutput->m_pData[ii];
                int saved = ce->m_00;
                int key = ce->m_04 ? ce->m_04 : saved;
                StrX oStr;
                oStr.SetField00(world.hkDataWorldDict_findClass(key));
                if (oStr.TestValue())
                {
                    ClassCinfo oCinfo;
                    oCinfo.name = key;
                    oCinfo.version = ce->m_08;
                    oCinfo.parent = 0;
                    {
                        StrX oTmpStr;
                        oTmpStr.SetField00(world.CreateItem(&oCinfo));
                        oStr.m_00 = oTmpStr.m_00;
                        oTmpStr.Object_DoNothing_00dba660();
                    }
                }
                {
                    int pi;
                    for (pi = ce->m_14 - 1; pi >= 0; pi--)
                    {
                        Pair5* pr = &ce->m_10[pi];
                        switch (pr->m_00 - 1)
                        {
                        case 2:
                            world.RenameClassMember(&oStr, pr->m_04[1], pr->m_04[0]);
                            break;
                        case 1:
                            world.FUN_00dc7d20(&oStr, pr->m_04[0], pr->m_04[1], pr->m_04[2], pr->m_04[3]);
                            break;
                        case 0:
                            world.ProcessEntries_00dc7600(&oStr, pr->m_04[0]);
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5: {
                            int* data5 = pr->m_04;
                            StrX removed;
                            removed.SetField00(world.hkDataWorldDict_findClass(data5[0]));
                            removed.Object_DoNothing_00dba660();
                            break;
                        }
                        case 6: {
                            int* data6 = pr->m_04;
                            if (data6[0])
                            {
                                StrX oTmpStr;
                                oTmpStr.SetField00(world.hkDataWorldDict_findClass(data6[0]));
                                world.AssignRefCountedSlot(&oStr, &oTmpStr);
                                oTmpStr.Object_DoNothing_00dba660();
                            }
                            else
                            {
                                StrX oTmpStr;
                                oTmpStr.SetField00((void*)0);
                                world.AssignRefCountedSlot(&oStr, &oTmpStr);
                                oTmpStr.Object_DoNothing_00dba660();
                            }
                        }
                        break;
                        default:
                            break;
                        }
                    }
                }
                if (ce->m_08 == -1)
                {
                    world.ReleaseRef(&oStr);
                }
                else
                {
                    if (key != saved)
                        world.hkDataWorldDict_renameClass(&oStr, saved);
                    world.hkDataWorldDict_setClassVersion(&oStr, ce->m_08);
                }
                oStr.Object_DoNothing_00dba660();
            }
        }
    }
    {
        VecP drain;
        drain.m_pData = 0;
        drain.m_iArrayLength = 0;
        drain.m_iCapacity = (int)0x80000000;
        world.hkDataWorldDict_findAllClasses(&drain);
        MgrB mga;
        MgrB mgb;
        mga.FUN_00d87790(MapTag());
        mgb.FUN_00d87790(MapTag());
        int i5;
        for (i5 = 0; i5 < drain.m_iArrayLength; i5++)
        {
            VObj* e = (VObj*)drain.m_pData[i5];
            int r = e->FUN_v2();
            mga.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(r, e);
        }
        int j5;
        for (j5 = 0; j5 < pSource.m_iArrayLength; j5++)
        {
            VObj* e = (VObj*)pSource.m_pData[j5];
            int r = e->FUN_v2();
            if (mga.GetValue(r, 0))
            {
                int r2 = ((VObj*)pSource.m_pData[j5])->FUN_v2();
                mga.ProcessAndReturnValue_00d87820(r2);
            }
        }
        int si = mga.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
        char bFlag;
        mga.SetBoolFromThreshold(&bFlag, si);
        while (bFlag)
        {
            VObj* cls = (VObj*)mga.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(si);
            apSource->copyClassFromWorld(cls->FUN_v2(), &world);
            si = mga.FindNextUsedSlot(si);
            mga.SetBoolFromThreshold(&bFlag, si);
        }
        mgb.FreeBuffer();
        mga.FreeBuffer();
    }
    return 0;
}
}  // namespace fnv_00db95c0

extern "C" void* __cdecl hkString_strDup_00cb1410(unsigned int);

struct PatchFactory
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};

extern PatchFactory* DAT_01268b08;

struct FUN_00c90510_Object
{
    void FUN_00c90510();
};

struct FUN_00c905b0_Object
{
    void FUN_00c905b0();
};

struct PatchArray
{
    int unk00;
    int unk04;
    int unk08;
};

extern "C" int __cdecl applyPatchOperations(int patch, int object);
struct PatchWorld
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
    virtual int GetClassFromName(int name);
};
// src: XBOX_PDB 0x00db8000
static __declspec(noinline) int applyPatchesFinally(PatchArray* patches, PatchWorld* world)
{
    if (!world)
        return 1;
    int object = world->GetClassFromName(0);
    return applyPatchOperations(patches->unk00, world->GetClassFromName(object));
}

struct PatchManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    int hkVersionPatchManager_recomputePatchDependencies();
    int ProcessVersionPatches(int a, int b, PatchArray* c);
    int hkVersionPatchManager_applyPatches(int param2, int param3);
};

// Applies a patch to a world object, resolving the allocator, running patch operations, and releasing the allocated patch data.
// @fnv 0x00dba0d0
// src: XBOX_PDB 0x00dba0d0
int __thiscall PatchManager::hkVersionPatchManager_applyPatches(int apWorld, int param3)
{
    if (param3 == 0)
    {
        param3 = DAT_01268b08->vf10();
    }

    reinterpret_cast<FUN_00c90510_Object*>(param3)->FUN_00c90510();

    if ((unk1C & 0x7FFFFFFF) == 0 && unk10 != 0)
    {
        if (hkVersionPatchManager_recomputePatchDependencies() == 1)
        {
            return 1;
        }
    }

    PatchArray patchResult;
    patchResult.unk00 = 0;
    patchResult.unk04 = 0;
    patchResult.unk08 = 0x80000000;

    int found = ProcessVersionPatches(apWorld, param3, &patchResult);
    if (found == 0)
    {
        found = applyPatchesFinally(&patchResult, reinterpret_cast<PatchWorld*>(apWorld));
    }

    reinterpret_cast<FUN_00c905b0_Object*>(param3)->FUN_00c905b0();

    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* audio = reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);

    patchResult.unk04 = 0;
    if ((patchResult.unk08 & 0x80000000) == 0)
    {
        audio->bufFree(reinterpret_cast<void*>(patchResult.unk00), (patchResult.unk08 & 0x3FFFFFFF) * 4);
    }

    return found;
}

struct DBA1A0Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
    int unk14;
    int unk18;
    int unk1C;

    int hkVersionPatchManager_recomputePatchDependencies();
    int __thiscall ProcessAndReturnValue_00dba1a0(int a1);
};

extern "C" int fnv_unknown_clobber(int a) throw();

// src: XBOX_PDB 0x00db8000
static __declspec(noinline) int applyPatchesFinally(int* pArr, int iKey)
{
    if (iKey == -1)
        return -1;
    int t = fnv_unknown_clobber(0);
    return pArr[iKey] + t;
}

// Returns 1 when the field checks pass; otherwise calls FUN_00db8000 with this+0xC and a1.
// @fnv 0x00dba1a0
// src: GUESS 0x00dba1a0 (confidence: low)
int __thiscall DBA1A0Class::ProcessAndReturnValue_00dba1a0(int aiKey)
{
    if ((unk1C & 0x7FFFFFFF) == 0 && unk10 != 0 && hkVersionPatchManager_recomputePatchDependencies() == 1)
        return 1;
    return applyPatchesFinally((int*)((char*)this + 0xC), aiKey);
}

// @fnv 0x00db7d40
struct C
{
    void __thiscall hkVersionPatchManager_UidFromClassVersion_getName(int, int);
};
struct W
{
    int x, y;
    C* inner;
    void __thiscall HkVersionPatchManager_UidFromClassVersion_getName_Thunk(Pair);
};
// src: GUESS 0x00db7d40 (confidence: medium)
void W::HkVersionPatchManager_UidFromClassVersion_getName_Thunk(Pair pair)
{
    inner->hkVersionPatchManager_UidFromClassVersion_getName(pair.a, pair.b);
}

namespace fnv_00dba4d0 {

struct SortedEntry
{
    int m_kPointA;
    int m_kPointB;
    int m_key;
    int m_iFourthElementInteger;
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* allocator, void* list, unsigned int elemSize);

struct FUN_00dba4d0_cls
{
    SortedEntry* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void ForwardCall_00dba340(void* allocator, int index, const SortedEntry* value);
    void HeapArray_UidItem_insert(const SortedEntry* apValue);
};

// @fnv 0x00dba4d0
// src: XBOX_PDB 0x00dba4d0
void FUN_00dba4d0_cls::HeapArray_UidItem_insert(const SortedEntry* apValue)
{
    for (int i = 0; i < m_iArrayLength; ++i)
    {
        SortedEntry cur = m_pData[i];
        if (apValue->m_key < cur.m_key)
        {
            hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
            ForwardCall_00dba340(pHolder->m_heap, i, apValue);
            return;
        }
    }

    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    if (m_iArrayLength == (int)(m_uCapBits & 0x3fffffffu))
    {
        ResizeAudioStream(pHolder->m_heap, this, sizeof(SortedEntry));
    }

    SortedEntry* pDst = m_pData + m_iArrayLength;
    if (pDst != 0)
    {
        pDst->m_kPointA = apValue->m_kPointA;
        pDst->m_kPointB = apValue->m_kPointB;
        pDst->m_key = apValue->m_key;
        pDst->m_iFourthElementInteger = apValue->m_iFourthElementInteger;
    }
    m_iArrayLength++;
}
}  // namespace fnv_00dba4d0

namespace fnv_00dba580 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00db85e0();
    CpuObject* FUN_00dba580(unsigned int flags);
};
// Calls FUN_00db85e0, then if flags has bit 0 set, releases this object through the allocator with its size, and returns this.
// @fnv 0x00dba580
CpuObject* CpuObject::FUN_00dba580(unsigned int flags)
{
    FUN_00db85e0();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00dba580

extern "C" void _ReadWriteBarrier(void);
void __cdecl ResizeAudioStream(hkMemoryAllocator* apAllocator, void* apContainer, unsigned int auiElemSize);
int __cdecl Hkversionpatchmanager_EvaluateValue_00db7cb0(unsigned int auiValue);

struct FUN_00db7ef0_sub
{
    int unk00;
    int unk04;
    void ProcessEntries_00cb1e00();
};

struct FUN_00db7ef0_list
{
    unsigned int* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};

struct FUN_00db7ef0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00db7ef0_list m_kNode;
    FUN_00db7ef0_sub m_sub;

    void UpdateState_00db7ef0(unsigned int auiValue);
};

// @fnv 0x00db7ef0
// src: GUESS 0x00db7ef0 (confidence: low)
void FUN_00db7ef0_cls::UpdateState_00db7ef0(unsigned int auiValue)
{
    if (Hkversionpatchmanager_EvaluateValue_00db7cb0(auiValue) == 0)
    {
        return;
    }

    FUN_00db7ef0_list* pList = &m_kNode;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    unsigned int uCap = pList->m_capFlags & 0x3fffffffu;
    if (pList->m_uiItemCount == (int)uCap)
    {
        ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap), pList, 4);
    }

    unsigned int* pSlot = pList->m_data + pList->m_uiItemCount;
    _ReadWriteBarrier();
    *pSlot = auiValue;
    pList->m_uiItemCount++;

    m_sub.ProcessEntries_00cb1e00();
}

struct S00db94b0_Ref_s
{
    int unk00;
    int unk04;
};

struct S00db94b0_Entry_s
{
    int type;
    S00db94b0_Ref_s* ref;
};

struct S00db94b0_Item_s
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S00db94b0_Entry_s* entries;
    int count;
};

struct S00db94b0_Node_s
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual S00db94b0_Node_s* v9(int a);
};

struct S00db94b0_Sub_s
{
    int hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(unsigned __int64 key, __int64 val);
};

struct S00db94b0_Owner_s
{
    int unk00;
    int unk04;
    int unk08;
    S00db94b0_Item_s** items;
    int unk10;
    int unk14;
    S00db94b0_Sub_s sub;

    unsigned __int64 hkVersionPatchManager_getUid(int a, int b);
};

struct S00db94b0_Array_s : DBA230Array
{
    bool ContainsKey(const unsigned __int64& key);
    void HeapArray_UidItem_insert(const unsigned __int64& key);
};

// Builds a key, calls two array methods when t is not 2, and recurses for entries whose type is 6.
// @fnv 0x00db94b0
// src: XBOX_PDB 0x00db94b0
extern "C" void __cdecl setAllDependeciesToDo(S00db94b0_Array_s* apArray, int a2, int a3, S00db94b0_Node_s* apNode,
                                     S00db94b0_Owner_s* apOwner, S00db94b0_Sub_s* apSubA, S00db94b0_Sub_s* apSubB)
{
    unsigned __int64 key = apOwner->hkVersionPatchManager_getUid(a2, a3);

    S00db94b0_Node_s* node = apNode->v9(a2);
    int idx = -1;
    if (node == 0 || node->v3() != a3)
    {
        idx = apSubA->hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(key, -1LL);
    }

    int t = apSubB->hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(key, 0LL);
    if (idx == -1 || t == 1)
    {
        idx = apOwner->sub.hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(key, -1LL);
    }

    DBA230Entry s;
    s.m_key = key;
    s.unk08 = idx;
    if (t != 2)
    {
        if (!apArray->ContainsKey(s.m_key))
        {
            apArray->HeapArray_UidItem_insert(s.m_key);
        }
    }

    if (idx < 0)
    {
        return;
    }

    S00db94b0_Item_s* item = apOwner->items[idx];
    for (int i = item->count - 1; i >= 0; i--)
    {
        S00db94b0_Entry_s* e = &item->entries[i];
        if (e->type == 6)
        {
            S00db94b0_Ref_s* ref = e->ref;
            setAllDependeciesToDo(apArray, ref->unk00, ref->unk04, apNode, apOwner, apSubA, apSubB);
        }
    }
}

struct DB7D00_Shell
{
    void* __thiscall hkVersionPatchManager_UidFromClassVersion_cache(unsigned int a);
};

struct VersionUidCache
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    struct ItemVec
    {
        unsigned int* m_data;
        unsigned int m_uiItemCount;
        unsigned int m_cap;
    } m_vec;

    unsigned int __thiscall GetOrSetInt(unsigned int a, unsigned int b);
    unsigned __int64 ComputeValue_00db7d60(unsigned int a1, int a2);
};

extern "C" void _ReadWriteBarrier(void);
extern "C" void __cdecl ResizeAudioStream(void* alloc, void* vec, unsigned int n);
// Finds item in m_vec via GetOrSetInt; if not found, grows capacity if needed, appends item, and returns index with a2 in high 32 bits.
// @fnv 0x00db7d60
// src: GUESS 0x00db7d60 (confidence: low)
unsigned __int64 VersionUidCache::ComputeValue_00db7d60(unsigned int a1, int a2)
{
    unsigned int item = reinterpret_cast<unsigned int>(reinterpret_cast<DB7D00_Shell*>(this)->hkVersionPatchManager_UidFromClassVersion_cache(a1));
    unsigned int uiSize = m_vec.m_uiItemCount;
    unsigned int r = GetOrSetInt(item, uiSize);
    if (r == m_vec.m_uiItemCount)
    {
        ItemVec* v = &m_vec;
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        if (v->m_uiItemCount == (v->m_cap & 0x3fffffffu))
        {
            ResizeAudioStream(holder->m_heap, v, 4);
        }
        unsigned int* slot = v->m_data + v->m_uiItemCount;
        _ReadWriteBarrier();
        *slot = item;
        v->m_uiItemCount++;
    }
    return (unsigned __int64)r | ((unsigned __int64)(__int64)a2 << 32);
}
