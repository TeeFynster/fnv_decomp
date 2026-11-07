#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#include "../../../../../../include/hkArray.h"

// src/havok/common/serialize/data/util/hkdataobjectutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/util/hkdataobjectutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV_VEC4_SIMD
#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/hkMemoryRouter.h"

struct FUN_00dc35e0_class
{
    int __thiscall ProcessEntries_00dc35e0();
};

// @fnv 0x00dc35e0
// src: GUESS 0x00dc35e0 (confidence: low)
int __thiscall FUN_00dc35e0_class::ProcessEntries_00dc35e0()
{
    int count = *(int*)((char*)this + 8);
    int result = 0;
    if (count >= 0)
    {
        void* node = *(void**)this;
        while (result <= count && *(int*)node == -1)
        {
            ++result;
            node = (char*)node + 0xc;
        }
    }
    return result;
}

struct DC3980Pair
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
};

struct DC3980Map
{
    DC3980Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void Reset();
};

// @fnv 0x00dc3980
void DC3980Map::Reset()
{
    int capacity = m_iPairCount + 1;
    for (int i = 0; i < capacity; i++)
        m_kPrimitiveElement[i].m_key = -1;
    m_iCapacityFlags &= 0x80000000;
}

struct Callback
{
    virtual void unk00();
    virtual void unk04();
    virtual void update(void* entries, int bytes);
};
struct FUN_00dc3b60_class
{
    void** entries;
    unsigned int flags;
    int count;
    void __thiscall ResetEntries();
    void __thiscall NotifyCallback(Callback* callback);
};
// Calls ResetEntries, then if the high flag bit is clear, invokes callback->update with entries and (count + 1) * 12 bytes.
// @fnv 0x00dc3b60
void FUN_00dc3b60_class::NotifyCallback(Callback* callback)
{
    ResetEntries();
    if ((flags & 0x80000000) == 0)
        callback->update(entries, (count + 1) * 12);
}

struct S_00dc3b90_Pair
{
    unsigned __int64 key;
    unsigned __int64 val;
};

struct S_00dc3b90
{
    S_00dc3b90_Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FindEntry(unsigned __int64 key);
    int LookupValue(unsigned __int64 key, unsigned __int64* out);
};

// @fnv 0x00dc3b90
int S_00dc3b90::LookupValue(unsigned __int64 key, unsigned __int64* out)
{
    int i = FindEntry(key);
    if (i <= m_iPairCount)
    {
        *out = m_kPrimitiveElement[i].val;
        return 0;
    }
    return 1;
}

struct DC3CC0Allocator;

struct DC3CC0Map
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ResizeStorage(DC3CC0Allocator& alloc, int capacity);
    void hkMapBase_hkDataObject_Handle_void_Copier_HandleOps_resizeTable(DC3CC0Allocator& alloc, int numElements);
};

// @fnv 0x00dc3cc0
// src: XBOX_PDB 0x00dc3cc0
void DC3CC0Map::hkMapBase_hkDataObject_Handle_void_Copier_HandleOps_resizeTable(DC3CC0Allocator& alloc, int numElements)
{
    int minCap = numElements * 2;
    int cap = 8;
    while (cap < minCap)
        cap *= 2;
    ResizeStorage(alloc, cap);
}

struct S_00dc3ce0_Allocator
{
    int unk0;
};

hkMemoryRouter& __cdecl GetAudioHolder();

inline S_00dc3ce0_Allocator& GetStreamAllocator(hkMemoryRouter& holder)
{
    return *(S_00dc3ce0_Allocator*)holder.m_heap;
}

void ResizeAudioStream(S_00dc3ce0_Allocator& alloc, void* array, int sizeElem);

struct S_00dc3ce0_Entry
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    S_00dc3ce0_Entry(int a, int b, int c) : m_kPointA(a), m_kPointB(b), m_iThirdValue(c)
    {}
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_00dc3ce0_ArrayLocalForm
{ // local form of hkArray: 0x00dc2d60 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    S_00dc3ce0_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void pushBack(S_00dc3ce0_Allocator& alloc, const S_00dc3ce0_Entry& e)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(S_00dc3ce0_Entry));
        }
        new (m_data + m_iElementCount) S_00dc3ce0_Entry(e);
        m_iElementCount++;
    }
    __forceinline void pushBack(const S_00dc3ce0_Entry& e)
    {
        pushBack(GetStreamAllocator(GetAudioHolder()), e);
    }
};

struct S_00dc3ce0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    S_00dc3ce0_ArrayLocalForm m_entries;
    void AddEntry(int a, int b, int c);
};

// Appends a new entry constructed from the three arguments to m_entries.
// @fnv 0x00dc3ce0
void S_00dc3ce0::AddEntry(int aiFirst, int aiSecond, int aiThird)
{
    m_entries.pushBack(S_00dc3ce0_Entry(aiFirst, aiSecond, aiThird));
}

struct Temp
{
    int f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11;
    Temp* __thiscall Construct(void* a2, int one, void* a1, void* a3) throw();
    ~Temp() throw();
    int __thiscall Copier_toObject() throw();
};

// @fnv 0x00dc32c0
// src: XBOX_PDB 0x00dc32c0
int __cdecl hkDataObjectUtil_toObjectWithRegistry(void* a1, void* a2, void* a3)
{
    Temp temp;
    return temp.Construct(a2, 1, a1, a3)->Copier_toObject();
}

struct GlobalObj_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c();
    virtual int v10();
};

extern GlobalObj_cls* DAT_01268b08;

extern "C" int __cdecl hkDataObjectUtil_toObjectWithRegistry(int a1, int a2, int a3);

// Calls v0c on DAT_01268b08, then passes a1, obj->v10() and that result to FUN_00dc32c0 and returns its result.
// @fnv 0x00dc3500
// src: GUESS 0x00dc3500 (confidence: low)
int __cdecl Object_ProcessAndReturnValue_00dc3500(int a1)
{
    GlobalObj_cls* obj = DAT_01268b08;
    int r1 = DAT_01268b08->v0c();
    return hkDataObjectUtil_toObjectWithRegistry(a1, obj->v10(), r1);
}

namespace fnv_00dc3530 {
extern int DAT_01268b08;

int __cdecl hkDataObjectUtil_toResourceWithRegistry(int a1, int a2);

struct SvcHolder_b0466
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual int unk10();
};

// @fnv 0x00dc3530
// src: GUESS 0x00dc3530 (confidence: low)
int __cdecl hkDataObjectUtil_toResourceWithRegistry_UpdateState_00dc3530(int a1)
{
    SvcHolder_b0466* svc = (SvcHolder_b0466*)DAT_01268b08;
    int r = svc->unk10();
    return hkDataObjectUtil_toResourceWithRegistry(a1, r);
}
}  // namespace fnv_00dc3530

struct Handle
{
    void* p;
    void ReleaseStorage_00dba7f0();
};

struct X
{
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int V7(Handle* other);
};

struct Slt
{
    void* m0;
    void* m4;
    int m8;
    void ProcessEntries_00dc3bd0(void*, int);
    void FreeStorage(void*);
};

struct Rec
{
    Handle f1;
    X* f2;
    Slt slt;
    void CloneObject(Handle* h, int v);
};

struct CT
{
    Handle f1;
    Handle f2;
};

void* __cdecl hkMemoryRouter_getInstance();

// @fnv 0x00dc3550
// src: GUESS 0x00dc3550 (confidence: low)
int hkMemoryRouter_getInstance_UpdateState_00dc3550(CT ct)
{
    Rec home;
    home.f1 = ct.f1;
    home.f2 = (X*)ct.f2.p;
    home.slt.m0 = 0;
    home.slt.m4 = 0;
    home.slt.m8 = -1;
    void* mgr = hkMemoryRouter_getInstance();
    home.slt.ProcessEntries_00dc3bd0(((void**)mgr)[4], 0);
    (void)home.f1.p;  // keep
    home.CloneObject(&ct.f1, home.f2->V7(&ct.f2));
    ct.f1.ReleaseStorage_00dba7f0();
    ct.f2.ReleaseStorage_00dba7f0();
    mgr = hkMemoryRouter_getInstance();
    home.slt.FreeStorage(((void**)mgr)[4]);
    return 0;
}

struct DC3600Allocator;

struct DC3600Key
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

struct DC3600MapOperations
{
    static unsigned hash(const DC3600Key& key, unsigned mod)
    {
        return (key.m_ucLowNibble >> 4) * 2654435761U & mod;
    }
    static bool isValid(const DC3600Key& key)
    {
        return key.m_ucLowNibble != 0xffffffff;
    }
    static bool equal(const DC3600Key& key0, const DC3600Key& key1)
    {
        return key0.m_ucLowNibble == key1.m_ucLowNibble && key0.m_ucHighNibble == key1.m_ucHighNibble;
    }
};

struct DC3600Pair
{
    DC3600Key key;
    int val;
};

struct DC3600Map
{
    DC3600Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ResizeStorage(DC3600Allocator& alloc, int capacity);
    int InsertKeyValue(DC3600Allocator& alloc, DC3600Key key, int val);
};

// Grows the table if needed, probes for the key, stores key and value, and returns whether the key was new.
// @fnv 0x00dc3600
int DC3600Map::InsertKeyValue(DC3600Allocator& alloc, DC3600Key key, int val)
{
    {
        int iCount = m_iCapacityFlags & 0x7fffffff;
        if ((iCount + iCount) > m_iPairCount)
            ResizeStorage(alloc, m_iPairCount + m_iPairCount + 2);
    }

    unsigned i;
    int isNewKey = true;
    for (i = DC3600MapOperations::hash(key, m_iPairCount); DC3600MapOperations::isValid(m_kPrimitiveElement[i].key);
         i = (i + 1) & m_iPairCount)
    {
        if (DC3600MapOperations::equal(m_kPrimitiveElement[i].key, key))
        {
            isNewKey = false;
            break;
        }
    }

    m_iCapacityFlags += isNewKey;

    m_kPrimitiveElement[i].key = key;
    m_kPrimitiveElement[i].val = val;
    return isNewKey;
}

struct FUN_00dc36b0_cls
{
    struct HashEntry
    {
        unsigned int key0;
        unsigned int key1;
        unsigned int value;
    };

    HashEntry* m_pEntries;
    unsigned int m_u04;
    unsigned int m_uMask;

    unsigned int Lookup(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault);
};

// Probes the hash table for the entry matching aKey0 and aKey1, returning its value or aDefault when not found.
// @fnv 0x00dc36b0
unsigned int FUN_00dc36b0_cls::Lookup(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault)
{
    unsigned int mask = m_uMask;
    if ((int)mask > 0)
    {
        unsigned int idx = ((aKey0 >> 4) * 0x9e3779b1u) & mask;
        if (m_pEntries[idx].key0 != 0xffffffffu)
        {
            for (;;)
            {
                HashEntry* e = &m_pEntries[idx];
                if (e->key0 == aKey0 && e->key1 == aKey1)
                {
                    return m_pEntries[idx].value;
                }
                idx = (idx + 1) & mask;
                if (m_pEntries[idx].key0 == 0xffffffffu)
                {
                    break;
                }
            }
        }
    }
    return aDefault;
}

struct Wrapper
{
    void __thiscall ProcessEntries_00dc3bd0(int first, int count);
    void __thiscall ProcessEntries_00dc39b0(int, int);
};
// @fnv 0x00dc3bd0
// src: GUESS 0x00dc3bd0 (confidence: low)
void __thiscall Wrapper::ProcessEntries_00dc3bd0(int first, int count)
{
    int needed = count + count;
    int capacity = 8;
    while (capacity < needed)
        capacity += capacity;
    ProcessEntries_00dc39b0(first, capacity);
}

struct DC3BF0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct DC3BF0Key
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

struct DC3BF0Pair
{
    DC3BF0Key key;
    int val;
};

struct DC3BF0Map
{
    DC3BF0Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int insert(DC3BF0Allocator& alloc, DC3BF0Key key, int val);
    void ResizeAndRehashPairs(DC3BF0Allocator& alloc, int newcap);
};

// Reallocates the map's pair array to at least 8 slots, rehashes existing entries via insert, and frees the old array unless the high flag bit is set.
// @fnv 0x00dc3bf0
// src: GUESS 0x00dc3bf0 (confidence: medium)
void DC3BF0Map::ResizeAndRehashPairs(DC3BF0Allocator& alloc, int aiNewCapacity)
{
    aiNewCapacity = (aiNewCapacity > 8) ? aiNewCapacity : 8;
    int iKeepOldBuffer = m_iCapacityFlags & 0x80000000;
    int iOldCapacity = m_iPairCount + 1;
    DC3BF0Pair* pOldPairs = m_kPrimitiveElement;
    m_kPrimitiveElement = static_cast<DC3BF0Pair*>(alloc.AllocateMemoryBlock(sizeof(DC3BF0Pair) * aiNewCapacity));
    for (int i = 0; i < aiNewCapacity; i++)
        m_kPrimitiveElement[i].key.m_ucLowNibble = 0xffffffff;
    m_iCapacityFlags = 0;
    m_iPairCount = aiNewCapacity - 1;

    for (int i = 0; i < iOldCapacity; i++)
    {
        if (pOldPairs[i].key.m_ucLowNibble != 0xffffffff)
            insert(alloc, pOldPairs[i].key, pOldPairs[i].val);
    }

    if (iKeepOldBuffer == 0)
        alloc.ReleaseBlock(pOldPairs, sizeof(DC3BF0Pair) * iOldCapacity);
}

namespace fnv_00dc43a0 {
struct DC43A0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};


inline DC43A0Allocator& GetHeap(hkMemoryRouter& holder)
{
    return *(DC43A0Allocator*)holder.m_heap;
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct DC43A0ReferencedObject
{
    void removeReference() const;
};

template <typename T> struct DC43A0RefPtr
{
    T* m_pRetainedObject;

    ~DC43A0RefPtr()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct DC43A0MapA
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ClearAndRelease(DC43A0Allocator& alloc);
    ~DC43A0MapA()
    {
        ClearAndRelease(GetHeap(hkMemoryRouter_getInstance()));
    }
};

struct DC43A0MapB
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ClearAndRelease(DC43A0Allocator& alloc);
    ~DC43A0MapB()
    {
        ClearAndRelease(GetHeap(hkMemoryRouter_getInstance()));
    }
};

struct DC43A0Pair
{
    int m_kPointA;
    int m_kPointB;
};

typedef hkArray<DC43A0Pair> DC43A0PairArray;
} // namespace fnv_00dc43a0
template<> __forceinline hkArray<fnv_00dc43a0::DC43A0Pair>::~hkArray()
{
    using namespace fnv_00dc43a0;

        DC43A0Allocator& alloc = GetHeap(fnv_00dc43a0::hkMemoryRouter_getInstance());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(DC43A0Pair));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}
namespace fnv_00dc43a0 {


struct FUN_00dc43a0
{
    DC43A0RefPtr<DC43A0ReferencedObject> m_pHeadNode;
    DC43A0RefPtr<DC43A0ReferencedObject> m_iSecondInteger;
    int unk08;
    DC43A0MapB m_mapB;
    DC43A0MapA m_mapA;
    DC43A0PairArray m_pairs;

    ~FUN_00dc43a0() throw();
};

// Destructor that destroys the two reference pointers, both maps and the pair array in reverse declaration order.
// @fnv 0x00dc43a0
FUN_00dc43a0::~FUN_00dc43a0() throw()
{}
}  // namespace fnv_00dc43a0

namespace fnv_00dc4f20 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct ObjectRef
{
    void FUN_00c90510();
};

struct SubRecord
{
    int m_i00;
    int m_i04;
    int m_i08;

    void EnsureCapacity(int aiValue, int aiZero);
    void hkMapBase_hkDataObject_Handle_void_Copier_HandleOps_resizeTable(int aiValue, int aiZero);
};

struct FUN_00dc4f20_cls
{
    ObjectRef* m_pReference;
    int m_i04;
    int m_iSecond;
    SubRecord m_sub0c;
    SubRecord m_sub18;
    int unk24;
    int unk28;
    unsigned int m_uFlags2c;

    FUN_00dc4f20_cls* Construct(ObjectRef* apRef, int aiSecond);
};

// @fnv 0x00dc4f20
FUN_00dc4f20_cls* FUN_00dc4f20_cls::Construct(ObjectRef* apRef, int aiSecond)
{
    if (apRef != 0)
    {
        apRef->FUN_00c90510();
    }

    m_pReference = apRef;
    m_i04 = 0;
    m_iSecond = aiSecond;

    SubRecord* pSub = &m_sub0c;
    pSub->m_i00 = 0;
    pSub->m_i04 = 0;
    pSub->m_i08 = -1;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    pSub->EnsureCapacity((int)pHolder->m_heap, 0);

    SubRecord* pSub2 = &m_sub18;
    pSub2->m_i00 = 0;
    pSub2->m_i04 = 0;
    pSub2->m_i08 = -1;
    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    pSub2->hkMapBase_hkDataObject_Handle_void_Copier_HandleOps_resizeTable((int)pHolder2->m_heap, 0);

    unk24 = 0;
    unk28 = 0;
    m_uFlags2c = 0x80000000;
    return this;
}
}  // namespace fnv_00dc4f20

namespace fnv_00dc58a0 {
struct S_00dc58a0_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};
inline S_00dc58a0_Alloc& GetBufferAllocator(hkMemoryRouter& holder)
{
    return *(S_00dc58a0_Alloc*)holder.m_temp;
}

hkMemoryRouter* hkMemoryRouter_getInstance();

struct S_00dc58a0_Obj
{
    int unk0;
    ~S_00dc58a0_Obj() throw();
};
struct S_00dc58a0_Src
{
    S_00dc58a0_Obj GetObjectValue();
};
struct S_00dc58a0_Item
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};
struct S_00dc58a0_Arr
{ // local form of hkArrayBase: 0x00dc58a0 needs ClearAndRelease(S_00dc58a0_Alloc&) through the unit allocator ABI, absent from the shared base.
    S_00dc58a0_Item* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void ClearAndRelease(S_00dc58a0_Alloc& a)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S_00dc58a0_Item));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct FUN_00dc58a0_cls
{
    void FillMissingMemberClassImplementations(S_00dc58a0_Arr& out, const S_00dc58a0_Obj& a, const S_00dc58a0_Obj& b) throw();
    void Cloner_copyValue(S_00dc58a0_Src* a, S_00dc58a0_Src* b, S_00dc58a0_Item* item) throw();
    void ProcessSourcePair(S_00dc58a0_Src* a, S_00dc58a0_Src* b) throw();
};

// Builds an item array from two sources, applies FUN_00dc4210 to each item, then frees the array via the router's allocator.
// @fnv 0x00dc58a0
void FUN_00dc58a0_cls::ProcessSourcePair(S_00dc58a0_Src* pSourceA, S_00dc58a0_Src* pSourceB) throw()
{
    S_00dc58a0_Obj ha = pSourceA->GetObjectValue();
    S_00dc58a0_Arr arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_iCapacityState = 0x80000000;
    FillMissingMemberClassImplementations(arr, ha, pSourceB->GetObjectValue());
    for (int i = 0; i < arr.m_iElementCount; i++)
        Cloner_copyValue(pSourceA, pSourceB, &arr.m_data[i]);
    arr.ClearAndRelease(GetBufferAllocator(*hkMemoryRouter_getInstance()));
}
}  // namespace fnv_00dc58a0

struct S_00dc5970_Allocator;
struct S_00dc5970_ClassImpl;
struct S_00dc5970_ObjectImpl;

inline S_00dc5970_Allocator& GetCloneAllocator(hkMemoryRouter& holder) throw()
{
    return *(S_00dc5970_Allocator*)holder.m_heap;
}

hkMemoryRouter& __cdecl GetAudioHolderForCloning() throw();

struct S_00dc5970_Handle
{
    void* p0;
    void* p1;
};

struct S_00dc5970_Class
{
    S_00dc5970_ClassImpl* m_pClassImpl;

    S_00dc5970_Class(S_00dc5970_ClassImpl* impl) throw();     // FUN_00dba650
    ~S_00dc5970_Class() throw();                              // FUN_00dba660
    S_00dc5970_ClassImpl* getImplementation() const throw();  // FUN_00dba680
};

struct S_00dc5970_Object
{
    S_00dc5970_ObjectImpl* m_pClassImpl;

    S_00dc5970_Object(S_00dc5970_ObjectImpl* impl) throw();  // FUN_00dba760
    S_00dc5970_Object(const S_00dc5970_Object& o) throw();   // AssignRef
    ~S_00dc5970_Object() throw();                            // FUN_00dba7f0
    int GetObjectKind() const throw();                       // FUN_00dba980
    S_00dc5970_Handle GetObjectHandle() const throw();       // GetSourcePair
    S_00dc5970_Class GetVariantValue() const throw();        // GetObjectValue
};

struct S_00dc5970_World
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual void vf2() throw();
    virtual void vf3() throw();
    virtual S_00dc5970_ObjectImpl* GetObject(const S_00dc5970_Class& pClassInfo) throw();
    virtual void vf5() throw();
    virtual void vf6() throw();
    virtual void vf7() throw();
    virtual void vf8() throw();
    virtual void vf9() throw();
    virtual S_00dc5970_Object GetSelectionItem(const S_00dc5970_Handle& handle) throw();
};

struct S_00dc5970_Map
{
    int LookupValue(S_00dc5970_Handle key, S_00dc5970_Handle* out) throw();                          // get
    void Insert(S_00dc5970_Allocator& alloc, S_00dc5970_Handle key, S_00dc5970_Handle val) throw();  // insert

    int get(S_00dc5970_Handle key, S_00dc5970_Handle* out) throw()
    {
        return LookupValue(key, out);
    }
    void insert(S_00dc5970_Handle key, S_00dc5970_Handle val) throw()
    {
        Insert(GetCloneAllocator(GetAudioHolderForCloning()), key, val);
    }
};

struct ValueQ;
struct Element;
struct Object;

// World cloning context: copyObject (0x00dc5970) and both simple-value specializations share this type.
struct Cloner
{
    S_00dc5970_World& m_kSourceWorld;
    int unk4;
    S_00dc5970_Map m_kHandleMap;

    S_00dc5970_ClassImpl* CloneClassMembersRecursively(S_00dc5970_ClassImpl* srcClass) throw();  // copyClass
    void ProcessSourcePair(S_00dc5970_Object& dstObj, const S_00dc5970_Object& srcObj) throw();
    S_00dc5970_Object CloneObject(const S_00dc5970_Object& srcObj) throw();
    void CopyValue(ValueQ dst, const ValueQ& src) throw();
    Object CloneObject(const Object& srcObj) throw();
    void CopyValueByType(Element dst, const Element& src);
};

// Looks up srcObj's handle in the map; if absent, clones its class, creates a destination object, records the handle mapping, copies the object and returns it.
// @fnv 0x00dc5970
S_00dc5970_Object Cloner::CloneObject(const S_00dc5970_Object& srcObj) throw()
{
    if (!srcObj.GetObjectKind())
    {
        S_00dc5970_Handle dstHandle;
        if (m_kHandleMap.get(srcObj.GetObjectHandle(), &dstHandle) == 0)
            return m_kSourceWorld.GetSelectionItem(dstHandle);

        S_00dc5970_Class dstClass(CloneClassMembersRecursively(srcObj.GetVariantValue().getImplementation()));
        S_00dc5970_Object dstObj(m_kSourceWorld.GetObject(dstClass));
        m_kHandleMap.insert(srcObj.GetObjectHandle(), dstObj.GetObjectHandle());
        ProcessSourcePair(dstObj, srcObj);
        return dstObj;
    }
    return S_00dc5970_Object(0);
}

struct FUN_00dc38f0_cls
{
    struct E
    {
        int k;
        int a;
        int b;
    }* m_00;
    unsigned int m_04;
    int m_08;
    void __thiscall ResetEntries();
};

// Sets the k field of the first m_08 + 1 entries to -1 and clears all but the top bit of m_04.
// @fnv 0x00dc38f0
void FUN_00dc38f0_cls::ResetEntries()
{
    int count = m_08 + 1;
    for (int i = 0; i < count; ++i)
        m_00[i].k = -1;
    m_04 &= 0x80000000u;
}

// FUN_00dc39b0 - rehash a hash table into a freshly allocated one.
//
// The table owns an array of 16-byte entries; the allocator is a polymorphic
// object whose virtual slot 4 allocates and slot 8 frees.  Every entry that
// is still in use is re-inserted through Insert; the old array is only
// released when the table did not grow behind a 0x80000000 flag.
struct Allocator_cls
{
    virtual void unk();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p, unsigned int size);
};

// Eight-byte data-object handle used by the handle-to-handle map, not an array value proxy.
struct DataObjectHandleKey
{
    unsigned int lo;
    unsigned int hi;
};
struct HashEntry
{
    DataObjectHandleKey key;
    DataObjectHandleKey val;
};

struct HashTable_cls
{
    HashEntry* m_00;
    unsigned int m_04;
    unsigned int m_08;

    void Insert(Allocator_cls* alloc, DataObjectHandleKey key, DataObjectHandleKey val);
    void ProcessEntries_00dc39b0(Allocator_cls* alloc, int newSize);
};

// @fnv 0x00dc39b0
// src: GUESS 0x00dc39b0 (confidence: low)
void HashTable_cls::ProcessEntries_00dc39b0(Allocator_cls* alloc, int newSize)
{
    int n = newSize;
    if (n <= 8)
    {
        n = 8;
    }
    unsigned int flag = m_04 & 0x80000000u;
    int remain = (int)(m_08 + 1);
    HashEntry* pOldEntries = m_00;
    m_00 = (HashEntry*)alloc->Alloc((unsigned int)n << 4);
    for (int i = 0; i < n; i++)
    {
        m_00[i].key.lo = -1;
    }
    m_04 = 0;
    m_08 = (unsigned int)(n - 1);
    for (int i = 0; i < remain; i++)
    {
        if (pOldEntries[i].key.lo != -1)
        {
            Insert(alloc, pOldEntries[i].key, pOldEntries[i].val);
        }
    }
    if (flag == 0)
    {
        alloc->Free(pOldEntries, (unsigned int)remain << 4);
    }
}

extern int DAT_010d6b98[];
struct DC1C50Shape
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
};
struct DC1C50Collection
{
    int FUN_00d46f00();
    DC1C50Shape* getMember(int i);
};

// Maps a type/subtype pair to a flag value from DAT_010d6b98, resolving subtype 0x19 against the collection's child types and optionally OR-ing 0x20.
// @fnv 0x00dc1c50
int __cdecl GetShapeTypeFlags(int iType, int iSubType, DC1C50Collection* pkCollection, int abAddFlag)
{
    if (iType == 0x18 || iType == 0x1f)
    {
        iType = iSubType;
        iSubType = 0;
    }
    int iFlags = DAT_010d6b98[iType];
    if (iFlags == 0x10)
    {
        switch (iSubType)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
            iFlags = DAT_010d6b98[iSubType] | 0x10;
            break;
        case 4:
            iFlags = 0x11;
            break;
        case 0x19: {
            int bValid = 1;
            for (int i = 0; i < pkCollection->FUN_00d46f00(); i++)
            {
                int iChildType = pkCollection->getMember(i)->m_type;
                if (iChildType == 0x16 || (iChildType > 0x19 && iChildType <= 0x1b))
                {
                    bValid = 0;
                    break;
                }
            }
            iFlags = bValid ? 0x19 : 0x18;
            break;
        }
        }
    }
    if (abAddFlag)
        iFlags |= 0x20;
    return iFlags;
}

struct ValueQ
{
    void* m_pClassImpl;
    int m_handle;
    int QueryAndWriteResult() const throw();
    int ForwardCall_00dba990() const throw();
    float InvokeVirtualMethod_00dbaa00() const throw();
    const float* DispatchToInterface(int n) const throw();
    S_00dc5970_Object GetWrappedDataObject() const throw();
    const char* hkDataObject_Value_asString() const throw();
    void ForwardCall_00dbaa30(int i) throw();
    void DispatchFloatToVtbl(float r) throw();
    void Apply_Thunk(const float* v, int n) throw();
    void DispatchToObject(const S_00dc5970_Object& o) throw();
    void ForwardCall_00dbab30(const char* s) throw();
};

// Copies src into dst by dispatching on src's type tag and calling the matching setter for int, float, float array, object or string values.
// @fnv 0x00dc5ab0
void Cloner::CopyValue(ValueQ dst, const ValueQ& src) throw()
{
    switch (src.QueryAndWriteResult())
    {
    case 1:
    case 2:
        dst.ForwardCall_00dbaa30(src.ForwardCall_00dba990());
        break;
    case 3:
        dst.DispatchFloatToVtbl(src.InvokeVirtualMethod_00dbaa00());
        break;
    case 4:
    case 5:
    case 6:
    case 7: {
        int n = (src.QueryAndWriteResult() - 3) * 4;
        dst.Apply_Thunk(src.DispatchToInterface(n), n);
        break;
    }
    case 8:
    case 9:
        dst.DispatchToObject(CloneObject(src.GetWrappedDataObject()));
        break;
    case 10:
        dst.ForwardCall_00dbab30(src.hkDataObject_Value_asString());
        break;
    }
}

class hkMemoryAllocatorDC37;

struct hkPairKeyDC37
{
    unsigned int m_k1;
    unsigned int m_k2;
    bool operator==(const hkPairKeyDC37& o) const
    {
        return m_k1 == o.m_k1 && m_k2 == o.m_k2;
    }
};

struct hkPairValueDC37
{
    unsigned int m_v1;
    unsigned int m_v2;
};

struct hkPairMapElemDC37
{
    hkPairKeyDC37 m_key;
    hkPairValueDC37 m_uiFilterValue;
};

class hkPairMapDC37
{
  public:
    hkPairMapElemDC37* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ProcessEntries_00dc39b0(hkMemoryAllocatorDC37& alloc, int iNewCap);
    int Insert(hkMemoryAllocatorDC37& alloc, hkPairKeyDC37 key, hkPairValueDC37 value);
};

// Checks for the key, calls FUN_00dc39b0 under the shown condition, stores the key/value, and returns whether the key was new.
// @fnv 0x00dc3740
int hkPairMapDC37::Insert(hkMemoryAllocatorDC37& alloc, hkPairKeyDC37 key, hkPairValueDC37 value)
{
    if ((m_iCapacityFlags & 0x7fffffff) * 2 > m_iPairCount)
        ProcessEntries_00dc39b0(alloc, m_iPairCount * 2 + 2);

    unsigned int i = ((key.m_k1 >> 4) * 0x9e3779b1) & m_iPairCount;
    int isNewKey = 1;
    while (m_kPrimitiveElement[i].m_key.m_k1 != 0xffffffff)
    {
        if (m_kPrimitiveElement[i].m_key == key)
        {
            isNewKey = 0;
            break;
        }
        i = (i + 1) & m_iPairCount;
    }
    m_iCapacityFlags += isNewKey;
    m_kPrimitiveElement[i].m_key = key;
    m_kPrimitiveElement[i].m_uiFilterValue = value;
    return isNewKey;
}

#include <xmmintrin.h>
class FUN_00c6cd00_cls
{
  public:
    LocalM128 m_v0;
    LocalM128 m_v1;
    LocalM128 m_v2;

    void __thiscall CopyThreeVectors(const FUN_00c6cd00_cls* src);
};

// Copies the three __m128 vector fields from src into the current object.
// @fnv 0x00c6cd00
// src: GUESS 0x00c6cd00 (confidence: medium)
void FUN_00c6cd00_cls::CopyThreeVectors(const FUN_00c6cd00_cls* src)
{
    m_v0 = src->m_v0;
    m_v1 = src->m_v1;
    m_v2 = src->m_v2;
}

struct S48
{
    LocalM128 v[3];
    void __thiscall CopyFromFloatArray(const float* src);
};
// Copies 12 floats from src into the three __m128 members of v using SSE load/store.
// @fnv 0x00c6cd30
void __thiscall S48::CopyFromFloatArray(const float* src)
{
    _mm_store_ps((float*)&v[0], _mm_load_ps(src));
    _mm_store_ps((float*)&v[1], _mm_load_ps(src + 4));
    _mm_store_ps((float*)&v[2], _mm_load_ps(src + 8));
}

typedef LocalM128 M128;

struct Mat3a
{
    Vec4 c0, c1, c2;
    void CopyThreeVectors(const float* p) throw();
};

struct Mat3b
{
    Vec4 c0, c1, c2;
    void CopyFromFloatArray(const float* p) throw();
};

struct Mat4a
{
    Vec4 c0, c1, c2, c3;
    void InitializeFields_00dc3710(const float* p) throw();
};

struct Mat4b
{
    Vec4 c0, c1, c2, c3;
    void FUN_00c6cd60(const float* p) throw();
};

struct DKlass
{
    int FUN_00d470d0() throw();
};

struct DObj
{
    int unk00;
    int hkDataObject_isNull() throw();
    void ReleaseStorage_00dba7f0() throw();
    __forceinline ~DObj() throw()
    {
        ReleaseStorage_00dba7f0();
    }
};

struct DValue
{
    int unk00;
    int unk04;
    int CallVirtualWithArg() throw();
    float ApplyValue() throw();
    const float* DispatchToVTableSlot8(int n) throw();
    template <int Width> __forceinline const float* asVector() throw()
    {
        return DispatchToVTableSlot8(Width);
    }
    DObj CreateValueInto() throw();
};

struct DArray
{
    int InvokeVirtualMethod_00dbac00() throw();
    DValue CreateResultPair(int i) throw();
};

struct DVariant
{
    void* unk00;
    void* unk04;
};

struct DAllocator
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void* AllocateBufferWithSize(int& numBytes) throw();
};


__declspec(restrict) void* __cdecl hkMemoryRouter_getInstance() throw();
extern "C" void __cdecl hkString_memSet(void* p, int v, int n) throw();

struct DOutArray
{
    void* unk00;
    int unk04;
    int unk08;
};

struct DMember
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned short unk0E;
    unsigned short unk10;
};

struct DTracker
{
    void AddEntry(void* p, int size, int flags) throw();
};

template <class T> __forceinline T* AllocElems(int& count)
{
    hkMemoryRouter* mem = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    DAllocator& heap = *(DAllocator*)mem->m_heap;
    T* p;
    {
        int numBytes = count * (int)sizeof(T);
        p = (T*)heap.AllocateBufferWithSize(numBytes);
        count = numBytes / (int)sizeof(T);
    }
    return p;
}

__forceinline void* CopyClassBytes(DAllocator& heap, const int& bytes) throw()
{
    int localBytes = bytes;
    return heap.AllocateBufferWithSize(localBytes);
}

struct DReader
{
    int unk00;
    DTracker* unk04;
    int unk08;

    DKlass* Copier_getMemberClassAndCheck(DMember* member, DObj& obj) throw();
    int ReadObject(void* p, DObj& obj) throw();
    DVariant FindOrCreateObjectMapEntry(DObj& obj, int flag) throw();
    int ReadValue(char** p, int type, DValue& v, int unk, int flag) throw();

    int ReadArray(DOutArray* out, DMember* member, DArray* arr) throw();
};

// Converts DArray elements into a type-selected output buffer, records eligible allocations, and updates out->unk08 for member type 0x16.
// @fnv 0x00dc1d30
int DReader::ReadArray(DOutArray* out, DMember* member, DArray* apArray) throw()
{
    if (apArray->InvokeVirtualMethod_00dbac00() == 0)
    {
        if (member->unk0C == 0x16)
        {
            out->unk08 = 0x80000000;
        }
        return 0;
    }

    int result = 0;
    int flag = ((unsigned short)~member->unk10 >> 9) & 1;
    int elemSize = 0;

    switch (member->unk0D)
    {
    case 0:
        goto checkTrack;
    case 1: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<bool>(out->unk04);
        elemSize = 1;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((bool*)out->unk00)[i] = apArray->CreateResultPair(i).CallVirtualWithArg() != 0;
        }
        break;
    }
    case 2: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<char>(out->unk04);
        elemSize = 1;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((char*)out->unk00)[i] = (char)apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 3: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<unsigned char>(out->unk04);
        elemSize = 1;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((unsigned char*)out->unk00)[i] = (unsigned char)apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 4: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<char>(out->unk04);
        elemSize = 1;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((char*)out->unk00)[i] = (char)apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 5: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<short>(out->unk04);
        elemSize = 2;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((short*)out->unk00)[i] = (short)apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 6: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<unsigned short>(out->unk04);
        elemSize = 2;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((unsigned short*)out->unk00)[i] = (unsigned short)apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 7: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<int>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((int*)out->unk00)[i] = apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 8: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<unsigned int>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((unsigned int*)out->unk00)[i] = apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 9: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<__int64>(out->unk04);
        elemSize = 8;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((__int64*)out->unk00)[i] = apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 10: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<unsigned __int64>(out->unk04);
        elemSize = 8;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((unsigned __int64*)out->unk00)[i] = apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 30: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<unsigned long>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((unsigned long*)out->unk00)[i] = apArray->CreateResultPair(i).CallVirtualWithArg();
        }
        break;
    }
    case 11: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<float>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((float*)out->unk00)[i] = apArray->CreateResultPair(i).ApplyValue();
        }
        break;
    }
    case 32: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<short>(out->unk04);
        elemSize = 2;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            union
            {
                float f;
                int i;
            } u;
            u.f = apArray->CreateResultPair(i).ApplyValue();
            ((short*)out->unk00)[i] = (short)(u.i >> 16);
        }
        break;
    }
    case 12: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<Vec4>(out->unk04);
        elemSize = 16;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            *(M128*)&((Vec4*)out->unk00)[i] = *(const M128*)apArray->CreateResultPair(i).asVector<4>();
        }
        break;
    }
    case 13: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<Vec4>(out->unk04);
        elemSize = 16;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            *(M128*)&((Vec4*)out->unk00)[i] = *(const M128*)apArray->CreateResultPair(i).asVector<4>();
        }
        break;
    }
    case 14: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<Mat3a>(out->unk04);
        elemSize = 48;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((Mat3a*)out->unk00)[i].CopyThreeVectors(apArray->CreateResultPair(i).asVector<12>());
        }
        break;
    }
    case 15: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<Mat3b>(out->unk04);
        elemSize = 48;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((Mat3b*)out->unk00)[i].CopyFromFloatArray(apArray->CreateResultPair(i).asVector<12>());
        }
        break;
    }
    case 16: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<Mat3b>(out->unk04);
        elemSize = 48;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((Mat3b*)out->unk00)[i].CopyFromFloatArray(apArray->CreateResultPair(i).asVector<12>());
        }
        break;
    }
    case 17: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<Mat4a>(out->unk04);
        elemSize = 64;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((Mat4a*)out->unk00)[i].InitializeFields_00dc3710(apArray->CreateResultPair(i).asVector<16>());
        }
        break;
    }
    case 18: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<Mat4b>(out->unk04);
        elemSize = 64;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            ((Mat4b*)out->unk00)[i].FUN_00c6cd60(apArray->CreateResultPair(i).asVector<16>());
        }
        break;
    }
    case 25: {
        DKlass* pClassInfo = Copier_getMemberClassAndCheck(member, apArray->CreateResultPair(0).CreateValueInto());
        if (pClassInfo)
        {
            out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
            int totalBytes = pClassInfo->FUN_00d470d0() * out->unk04;
            hkMemoryRouter* mem = (hkMemoryRouter*)hkMemoryRouter_getInstance();
            {
                int numBytes = totalBytes;
                out->unk00 = CopyClassBytes(*(DAllocator*)mem->m_heap, numBytes);
            }
            elemSize = pClassInfo->FUN_00d470d0();
            hkString_memSet(out->unk00, 0, pClassInfo->FUN_00d470d0() * apArray->InvokeVirtualMethod_00dbac00());
            for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
            {
                if (result != 0)
                {
                    goto checkTrack;
                }
                void* p;
                {
                    int offset = pClassInfo->FUN_00d470d0() * i;
                    p = (char*)out->unk00 + offset;
                }
                result = ReadObject(p, apArray->CreateResultPair(i).CreateValueInto());
            }
        }
        if (!pClassInfo)
            goto finish;
        break;
    }
    case 20: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<void*>(out->unk04);
        elemSize = 4;
        hkString_memSet(out->unk00, 0, out->unk04 * 4);
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            DObj o = apArray->CreateResultPair(i).CreateValueInto();
            if (!o.hkDataObject_isNull())
            {
                DVariant v = FindOrCreateObjectMapEntry(o, flag);
                if (v.unk00 == 0)
                {
                    result = 1;
                }
                else
                {
                    ((void**)out->unk00)[i] = v.unk00;
                }
            }
        }
        break;
    }
    case 28: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<DVariant>(out->unk04);
        elemSize = 8;
        hkString_memSet(out->unk00, 0, out->unk04 * 8);
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            DObj o = apArray->CreateResultPair(i).CreateValueInto();
            if (!o.hkDataObject_isNull())
            {
                DVariant v = FindOrCreateObjectMapEntry(o, flag);
                if (v.unk00 == 0)
                {
                    result = 1;
                }
                else
                {
                    ((DVariant*)out->unk00)[i] = v;
                }
            }
        }
        break;
    }
    case 29: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<char*>(out->unk04);
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            if (result != 0)
            {
                break;
            }
            int subtype = member->unk0D;
            char** destination = &((char**)out->unk00)[i];
            result = ReadValue(destination, subtype, apArray->CreateResultPair(i), 0, flag);
        }
    }
    case 33: {
        out->unk04 = apArray->InvokeVirtualMethod_00dbac00();
        out->unk00 = AllocElems<char*>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->InvokeVirtualMethod_00dbac00(); i++)
        {
            if (result != 0)
            {
                goto checkTrack;
            }
            int subtype = member->unk0D;
            char** destination = &((char**)out->unk00)[i];
            result = ReadValue(destination, subtype, apArray->CreateResultPair(i), 0, flag);
        }
        break;
    }
    default:
        return 1;
    }

checkTrack:
    if (elemSize <= 0)
        goto finish;
track:
    unk04->AddEntry(out->unk00, out->unk04 * elemSize, 0x18);

finish:
    if (member->unk0C == 0x16)
    {
        out->unk08 = out->unk04;
        if (unk08 == 0)
        {
            out->unk08 |= 0x80000000;
        }
    }
    return result;
}

__forceinline void Vec4::operator=(const Vec4& v)
{
    m_vComponents = v.m_vComponents;
}

struct DC3710Transform
{
    Vec4 m_kColumn0;
    Vec4 m_kColumn1;
    Vec4 m_kColumn2;
    Vec4 m_vTranslation;

    void InitializeFields_00dc3710(const DC3710Transform& t);
};

// Copies the four vector fields from the source transform into this transform.
// @fnv 0x00dc3710
// src: GUESS 0x00dc3710 (confidence: low)
void DC3710Transform::InitializeFields_00dc3710(const DC3710Transform& akSource)
{
    m_kColumn0 = akSource.m_kColumn0;
    m_kColumn1 = akSource.m_kColumn1;
    m_kColumn2 = akSource.m_kColumn2;
    m_vTranslation = akSource.m_vTranslation;
}

struct S_00dc4a80_Reader
{
    void* __thiscall DispatchToVTableSlot8(int count) throw();
    const char* __thiscall ForwardCall_00dbac70() throw();
    float __thiscall ApplyValue() throw();
    int __thiscall CallVirtualWithArg() throw();
    S_00dc5970_Object __thiscall CreateValueInto() throw();
};

struct S_00dc4a80_M3
{
    void __thiscall CopyThreeVectors(void*) throw();
};

struct S_00dc4a80_Rot
{
    void __thiscall CopyFromFloatArray(void*) throw();
};

struct S_00dc4a80_QsTr
{
    void __thiscall CopyFromFloatArray(void*) throw();
};

struct S_00dc4a80_M4
{
    void __thiscall InitializeFields_00dc3710(void*) throw();
};

struct S_00dc4a80_Tr
{
    void __thiscall FUN_00c6cd60(void*) throw();
};

__forceinline void constructStrings(char** p, int n, char* const& str) throw()
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = str;
    }
}

typedef hkArray<char*> StringArray;
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
return reinterpret_cast<hkMemoryAllocator&>(*reinterpret_cast<hkMemoryAllocator*>(&GetStreamAllocator(GetAudioHolder())));
}
template<> __forceinline void hkArrayBase<char*>::_pushBack(hkMemoryAllocator& sharedAlloc, char* const& str)
{
S_00dc3ce0_Allocator& alloc = reinterpret_cast<S_00dc3ce0_Allocator&>(sharedAlloc);

        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(alloc, this, 4);
        }
        constructStrings(m_data + m_iElementCount, 1, str);
        m_iElementCount++;
    
}


struct StringHolder
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
    int unk30;
    StringArray m_pStringFunctions;
};

extern "C" char* __cdecl hkString_strDup_00cb1410(const char*) throw();

struct S_00dc4a80
{
    int unk00;
    StringHolder* unk04;
    int unk08;

    void __thiscall FindOrCreateObjectMapEntry(S_00dc5970_Handle* out, const S_00dc5970_Object& obj, int arg4) throw();
    int __thiscall ReadObject(void* out, const S_00dc5970_Object& obj) throw();

    int __thiscall ReadValue(void* out, int type, S_00dc4a80_Reader* reader, int arg3, int arg4) throw();
};

// Reads a value of the given type from reader into out, returning 1 on failure.
// @fnv 0x00dc4a80
int __thiscall S_00dc4a80::ReadValue(void* out, int type, S_00dc4a80_Reader* reader, int aiFlag3, int arg4) throw()
{
    switch (type)
    {
    case 1:
        *(bool*)out = (reader->CallVirtualWithArg() != 0);
        return 0;
    case 2:
        *(unsigned char*)out = (unsigned char)reader->CallVirtualWithArg();
        return 0;
    case 3:
        *(char*)out = (char)reader->CallVirtualWithArg();
        return 0;
    case 4:
        *(unsigned char*)out = (unsigned char)reader->CallVirtualWithArg();
        return 0;
    case 5:
        *(short*)out = (short)reader->CallVirtualWithArg();
        return 0;
    case 6:
        *(unsigned short*)out = (unsigned short)reader->CallVirtualWithArg();
        return 0;
    case 7:
        *(int*)out = reader->CallVirtualWithArg();
        return 0;
    case 8:
        *(unsigned int*)out = (unsigned int)reader->CallVirtualWithArg();
        return 0;
    case 9:
        *(__int64*)out = reader->CallVirtualWithArg();
        return 0;
    case 10:
        *(unsigned __int64*)out = reader->CallVirtualWithArg();
        return 0;
    case 30:
        *(unsigned long*)out = (unsigned long)reader->CallVirtualWithArg();
        return 0;
    case 11:
        *(float*)out = reader->ApplyValue();
        return 0;
    case 32: {
        float f = reader->ApplyValue();
        *(short*)out = (short)(*(int*)&f >> 16);
        return 0;
    }
    case 20:
        if (aiFlag3)
        {
            S_00dc5970_Object obj = reader->CreateValueInto();
            if (!obj.GetObjectKind())
            {
                __declspec(align(8)) S_00dc5970_Handle h;
                FindOrCreateObjectMapEntry(&h, obj, arg4);
                if (!h.p0)
                {
                    return 1;
                }
                *(void**)out = h.p0;
            }
        }
        break;
    case 25:
        if (aiFlag3)
        {
            bool err;
            if (err = (ReadObject(out, reader->CreateValueInto()) == 1))
            {
                return 1;
            }
        }
        break;
    case 12:
        *(LocalM128*)out = *(LocalM128*)reader->DispatchToVTableSlot8(4);
        return 0;
    case 13:
        *(LocalM128*)out = *(LocalM128*)reader->DispatchToVTableSlot8(4);
        return 0;
    case 14:
        ((S_00dc4a80_M3*)out)->CopyThreeVectors(reader->DispatchToVTableSlot8(12));
        return 0;
    case 15:
        ((S_00dc4a80_Rot*)out)->CopyFromFloatArray(reader->DispatchToVTableSlot8(12));
        return 0;
    case 16:
        ((S_00dc4a80_QsTr*)out)->CopyFromFloatArray(reader->DispatchToVTableSlot8(12));
        return 0;
    case 17:
        ((S_00dc4a80_M4*)out)->InitializeFields_00dc3710(reader->DispatchToVTableSlot8(16));
        return 0;
    case 18:
        ((S_00dc4a80_Tr*)out)->FUN_00c6cd60(reader->DispatchToVTableSlot8(16));
        return 0;
    case 29: {
        if (unk08)
        {
            return 1;
        }
        char* copy;
        if (reader->ForwardCall_00dbac70())
        {
            copy = hkString_strDup_00cb1410(reader->ForwardCall_00dbac70());
            unk04->m_pStringFunctions.pushBack(copy);
        }
        else
        {
            copy = 0;
        }
        *(char**)out = copy;
        return 0;
    }
    case 33: {
        int val;
        if (reader->ForwardCall_00dbac70())
        {
            char* copy = hkString_strDup_00cb1410(reader->ForwardCall_00dbac70());
            unk04->m_pStringFunctions.pushBack(copy);
            val = (int)copy;
        }
        else
        {
            val = 0;
        }
        *(int*)out = val;
        if (unk08)
        {
            *(int*)out = val | 1;
            return 0;
        }
        break;
    }
    case 28:
        if (unk08)
        {
            return 1;
        }
        {
            S_00dc5970_Object obj = reader->CreateValueInto();
            if (!obj.GetObjectKind())
            {
                __declspec(align(8)) S_00dc5970_Handle h;
                FindOrCreateObjectMapEntry(&h, obj, arg4);
                if (!h.p0)
                {
                    return 1;
                }
                *(S_00dc5970_Handle*)out = h;
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}

namespace fnv_00dc4fa0 {
typedef ::__m128 LocalM128;

struct S_00dc4fa0_Reader
{
    void* __thiscall DispatchToInterface(int count) throw();
    const char* __thiscall hkDataObject_Value_asString() throw();
    float __thiscall InvokeVirtualMethod_00dbaa00() throw();
    int __thiscall ForwardCall_00dba990() throw();
    S_00dc5970_Object __thiscall GetWrappedDataObject() throw();
};

struct S_00dc4fa0_M3
{
    void __thiscall CopyThreeVectors(void*) throw();
};

struct S_00dc4fa0_Rot
{
    void __thiscall CopyFromFloatArray(void*) throw();
};

struct S_00dc4fa0_QsTr
{
    void __thiscall CopyFromFloatArray(void*) throw();
};

struct S_00dc4fa0_M4
{
    void __thiscall InitializeFields_00dc3710(void*) throw();
};

struct S_00dc4fa0_Tr
{
    void __thiscall FUN_00c6cd60(void*) throw();
};

typedef hkArray<char*> StringArray;

struct StringHolder
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
    int unk30;
    StringArray m_pStringFunctions;
};

extern "C" char* __cdecl hkString_strDup_00cb1410(const char*) throw();

struct S_00dc4fa0
{
    int unk00;
    StringHolder* unk04;
    int unk08;

    void __thiscall FindOrCreateObjectMapEntry(S_00dc5970_Handle* out, const S_00dc5970_Object& obj, int arg4) throw();
    int __thiscall ReadObject(void* out, const S_00dc5970_Object& obj) throw();

    int __thiscall ReadTypedValue(void* out, int type, S_00dc4fa0_Reader* reader, int arg3, int arg4) throw();
};

// Reads a typed value from reader into out based on type, returning 1 on error or unsupported type.
// @fnv 0x00dc4fa0
// src: GUESS 0x00dc4fa0 (confidence: medium)
int __thiscall S_00dc4fa0::ReadTypedValue(void* out, int type, S_00dc4fa0_Reader* reader, int aiFlag, int arg4) throw()
{
    switch (type)
    {
    case 1:
        *(bool*)out = (reader->ForwardCall_00dba990() != 0);
        return 0;
    case 2:
        *(unsigned char*)out = (unsigned char)reader->ForwardCall_00dba990();
        return 0;
    case 3:
        *(char*)out = (char)reader->ForwardCall_00dba990();
        return 0;
    case 4:
        *(unsigned char*)out = (unsigned char)reader->ForwardCall_00dba990();
        return 0;
    case 5:
        *(short*)out = (short)reader->ForwardCall_00dba990();
        return 0;
    case 6:
        *(unsigned short*)out = (unsigned short)reader->ForwardCall_00dba990();
        return 0;
    case 7:
        *(int*)out = reader->ForwardCall_00dba990();
        return 0;
    case 8:
        *(unsigned int*)out = (unsigned int)reader->ForwardCall_00dba990();
        return 0;
    case 30:
        *(int*)out = reader->ForwardCall_00dba990();
        return 0;
    case 9:
        *(__int64*)out = reader->ForwardCall_00dba990();
        return 0;
    case 10:
        *(__int64*)out = reader->ForwardCall_00dba990();
        return 0;
    case 11:
        *(float*)out = reader->InvokeVirtualMethod_00dbaa00();
        return 0;
    case 32: {
        float f = reader->InvokeVirtualMethod_00dbaa00();
        *(short*)out = (short)(*(int*)&f >> 16);
        return 0;
    }
    case 20:
        if (aiFlag)
        {
            S_00dc5970_Object obj = reader->GetWrappedDataObject();
            if (!obj.GetObjectKind())
            {
                __declspec(align(8)) S_00dc5970_Handle h;
                FindOrCreateObjectMapEntry(&h, obj, arg4);
                if (!h.p0)
                {
                    return 1;
                }
                *(void**)out = h.p0;
            }
        }
        break;
    case 25:
        if (aiFlag)
        {
            bool err;
            if (err = (ReadObject(out, reader->GetWrappedDataObject()) == 1))
            {
                return 1;
            }
        }
        break;
    case 12:
        *(LocalM128*)out = *(LocalM128*)reader->DispatchToInterface(4);
        return 0;
    case 13:
        *(LocalM128*)out = *(LocalM128*)reader->DispatchToInterface(4);
        return 0;
    case 14:
        ((S_00dc4fa0_M3*)out)->CopyThreeVectors(reader->DispatchToInterface(12));
        return 0;
    case 15:
        ((S_00dc4fa0_Rot*)out)->CopyFromFloatArray(reader->DispatchToInterface(12));
        return 0;
    case 16:
        ((S_00dc4fa0_QsTr*)out)->CopyFromFloatArray(reader->DispatchToInterface(12));
        return 0;
    case 17:
        ((S_00dc4fa0_M4*)out)->InitializeFields_00dc3710(reader->DispatchToInterface(16));
        return 0;
    case 18:
        ((S_00dc4fa0_Tr*)out)->FUN_00c6cd60(reader->DispatchToInterface(16));
        return 0;
    case 29: {
        if (unk08)
        {
            return 1;
        }
        char* copy;
        if (reader->hkDataObject_Value_asString())
        {
            copy = hkString_strDup_00cb1410(reader->hkDataObject_Value_asString());
            unk04->m_pStringFunctions.pushBack(copy);
        }
        else
        {
            copy = 0;
        }
        *(char**)out = copy;
        return 0;
    }
    case 33: {
        int val;
        if (reader->hkDataObject_Value_asString())
        {
            char* copy = hkString_strDup_00cb1410(reader->hkDataObject_Value_asString());
            unk04->m_pStringFunctions.pushBack(copy);
            val = (int)copy;
        }
        else
        {
            val = 0;
        }
        *(int*)out = val;
        if (unk08)
        {
            *(int*)out = val | 1;
            return 0;
        }
        break;
    }
    case 28:
        if (unk08)
        {
            return 1;
        }
        {
            S_00dc5970_Object obj = reader->GetWrappedDataObject();
            if (!obj.GetObjectKind())
            {
                __declspec(align(8)) S_00dc5970_Handle h;
                FindOrCreateObjectMapEntry(&h, obj, arg4);
                if (!h.p0)
                {
                    return 1;
                }
                *(S_00dc5970_Handle*)out = h;
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}
}  // namespace fnv_00dc4fa0

struct DCNode;
struct DCWorld
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void add(void*);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual DCNode* find(DCNode*);
};
struct DCNode
{
    virtual void f0();
    virtual void f1();
    virtual DCNode* get();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int count();
    virtual void member(int, void*);
};
struct DCIterator
{
    int p;
    DCIterator(DCNode*) throw();
    ~DCIterator() throw();
    DCIterator SetShiftedValue() throw();
    int TestValue() throw();
    DCNode* hkDataClass_getName() throw();
    void FillOutFromInterface(void*) throw();
};
struct DCEntry
{
    int x[3];
    void* data;
    int size;
    int cap;
};
struct DCArray
{
    DCEntry* data;
    int size;
    int cap;
    void reserve(void*, int);
};
void __cdecl hkArrayUtil__reserve(void*, DCArray*, int, int);
void __cdecl ResizeAudioStream(void*, DCArray*, int);
inline void DCArray::reserve(void* heap, int min)
{
    int old = cap & 0x3fffffff;
    if (old < min)
    {
        int n = old * 2;
        if (n <= min)
            n = min;
        hkArrayUtil__reserve(heap, this, n, 24);
    }
}
struct DCAlloc
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Free(void*, int);
};
__forceinline void clearPart(int flags, int* cap, DCAlloc* other)
{
    cap[-1] = 0;
    if (!(flags & 0x80000000))
        other->Free(*(void**)(cap - 2), (flags & 0x3fffffff) * 16);
    *(void**)(cap - 2) = 0;
    cap[0] = 0x80000000;
}
// Looks up srcClass in m_kSourceWorld; on a miss, walks nodes, adds collected entries, visits members recursively, and frees temporary array storage.
// @fnv 0x00dc5440
// src: GUESS 0x00dc5440 (confidence: medium)
S_00dc5970_ClassImpl* Cloner::CloneClassMembersRecursively(S_00dc5970_ClassImpl* srcClass) throw()
{

    DCNode* arg = (DCNode*)srcClass;
    DCNode* result = ((DCWorld*)&m_kSourceWorld)->find(arg);
    if (result)
        return (S_00dc5970_ClassImpl*)result;
    {
        DCArray a = {0, 0, (int)0x80000000};
        hkMemoryRouter* r = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        a.reserve((DCAlloc*)r->m_temp, 10);
        DCNode* node = arg;
        while (node && !((DCWorld*)&m_kSourceWorld)->find(node))
        {
            DCIterator it(((DCWorld*)unk4)->find(node));
            r = (hkMemoryRouter*)hkMemoryRouter_getInstance();
            if (a.size == (a.cap & 0x3fffffff))
                ResizeAudioStream((DCAlloc*)r->m_temp, &a, 24);
            DCEntry* e = a.data + a.size;
            if (e)
            {
                e->data = 0;
                e->size = 0;
                e->cap = 0x80000000;
            }
            DCEntry* out = a.data + a.size;
            a.size++;
            it.FillOutFromInterface(out);
            node = it.SetShiftedValue().TestValue() ? 0 : it.SetShiftedValue().hkDataClass_getName();
        }
        for (int i = a.size - 1; i >= 0; --i)
            ((DCWorld*)&m_kSourceWorld)->add(a.data + i);
        DCNode* pClass = ((DCWorld*)unk4)->find(arg);
        for (int i = 0; i < pClass->count(); ++i)
        {
            struct Member
            {
                int x[5];
            } member = {0, 0, 0, 0, 0};
            pClass->member(i, &member);
            if (member.x[3])
                CloneClassMembersRecursively((S_00dc5970_ClassImpl*)((DCNode*)member.x[3])->get());
        }
        srcClass = (S_00dc5970_ClassImpl*)((DCWorld*)&m_kSourceWorld)->find(arg);
        DCAlloc* heap = (DCAlloc*)((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_temp;
        if (a.size > 0)
        {
            int* cap = &a.data->cap;
            int i = a.size;
            do
            {
                hkMemoryRouter* r = (hkMemoryRouter*)hkMemoryRouter_getInstance();
                clearPart(cap[0], cap, (DCAlloc*)r->m_heap);
                cap += 6;
            } while (--i);
        }
        a.size = 0;
        if (!(a.cap & 0x80000000))
            heap->Free(a.data, (a.cap & 0x3fffffff) * 24);
    }
    return srcClass;
}

struct DWC_Allocator;
inline DWC_Allocator& GetTempAllocator(hkMemoryRouter& holder) throw()
{
    return *(DWC_Allocator*)holder.m_temp;
}

hkMemoryRouter& __cdecl GetTempAudioHolder() throw();
struct DWC_Allocator
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual void vf2() throw();
    virtual void vf3() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
void hkArrayUtil__reserve(DWC_Allocator& alloc, void* array, int numElem, int sizeElem) throw();

struct DWC_ClassImpl;
struct DWC_ClassSource
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual DWC_ClassImpl* getImplementation() throw();
};
struct DWC_MemberInfo
{
    const char* m_name;
    int m_type;
    int m_tuple;
    DWC_ClassSource* m_class;
    const void* m_valuePtr;
    DWC_MemberInfo() throw() : m_name(0), m_type(0), m_tuple(0), m_class(0), m_valuePtr(0)
    {}
};
inline void* operator new(unsigned int, DWC_MemberInfo* p) throw()
{
    return p;
}

__forceinline void DWC_construct(DWC_MemberInfo* t, int n) throw()
{
    for (int i = 0; i < n; ++i)
    {
        ::new (t + i) DWC_MemberInfo();
    }
}

struct DWC_MemberArray
{ // local form of hkArrayBase: 0x00dc56f0 needs throw() temp-allocator growth/cleanup with DWC_construct and DWC_Allocator call signatures.
    DWC_MemberInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    DWC_MemberArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~DWC_MemberArray() throw()
    {
        _clearAndDeallocate(GetTempAllocator(GetTempAudioHolder()));
    }
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    DWC_MemberInfo& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(DWC_Allocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(DWC_MemberInfo));
        }
    }
    __forceinline void GrowArrayCapacity(DWC_Allocator& alloc, int n) throw()
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(DWC_MemberInfo));
        }
    }
    __forceinline void _setSize(DWC_Allocator& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        DWC_construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(GetTempAllocator(GetTempAudioHolder()), n);
    }
};

struct DWC_Class
{
    int ForwardCall_00dba730() const throw();
    void DispatchItems(DWC_MemberArray& infos) const throw();
};

struct DWC_Cloner
{
    DWC_ClassImpl* CloneClassMembersRecursively(DWC_ClassImpl* srcClass) throw();
    void FillMissingMemberClassImplementations(DWC_MemberArray& dstInfos, const DWC_Class& dstClass, const DWC_Class& srcClass) throw();
};

// Dispatches member info for both classes, then fills null destination m_class entries with cloned source implementations.
// @fnv 0x00dc56f0
// src: GUESS 0x00dc56f0 (confidence: medium)
void DWC_Cloner::FillMissingMemberClassImplementations(DWC_MemberArray& dstInfos, const DWC_Class& dstClass, const DWC_Class& srcClass) throw()
{
    DWC_MemberArray srcInfos;
    srcInfos.SetSizeAndGrow(srcClass.ForwardCall_00dba730());
    srcClass.DispatchItems(srcInfos);

    dstInfos.SetSizeAndGrow(dstClass.ForwardCall_00dba730());
    dstClass.DispatchItems(dstInfos);

    for (int i = 0; i < srcClass.ForwardCall_00dba730(); ++i)
    {
        if (srcInfos[i].m_class && !dstInfos[i].m_class)
        {
            dstInfos[i].m_class = (DWC_ClassSource*)CloneClassMembersRecursively(srcInfos[i].m_class->getImplementation());
        }
    }
}

extern "C" void _ReadWriteBarrier(void);
struct S_00dc3920_E
{
    unsigned int key0;
    unsigned int key1;
    unsigned int unk08;
    unsigned int unk0C;
};
struct FUN_00dc3920_cls
{
    S_00dc3920_E* m_pEntries;
    unsigned int unk04;
    int m_iMask;
    unsigned int FindEntry(unsigned int a, unsigned int b);
};
// Linearly probes the hash table m_pEntries for a matching key pair (a, b) and returns the slot index, or mask+1 when not found.
// @fnv 0x00dc3920
unsigned int FUN_00dc3920_cls::FindEntry(unsigned int auiKey0, unsigned int auiKey1)
{
    int mask = m_iMask;
    if (mask > 0)
    {
        S_00dc3920_E* pEntries = m_pEntries;
        unsigned int idx = ((auiKey0 >> 4) * 0x9e3779b1u) & mask;
        S_00dc3920_E* e = &pEntries[idx];
        while (e->key0 != 0xffffffffu)
        {
            _ReadWriteBarrier();
            if (e->key0 == auiKey0 && e->key1 == auiKey1)
                return idx;
            idx = (idx + 1) & mask;
            e = &pEntries[idx];
        }
    }
    return mask + 1;
}

struct Member355
{
    const char* name;
    void* typeInfo;
    void* enumInfo;
    unsigned char type;
    unsigned char subtype;
    unsigned short fixedCount;
    unsigned short flags;
    unsigned short offset;
    __forceinline const char* getName() const throw()
    {
        return name;
    }
    int getCstyleArraySize() throw();
    int FUN_00d86980() throw();
    void* getClass() throw();
};
struct Class355
{
    int FUN_00d46f70() throw();
    Member355* FUN_00d46f80(int index) throw();
    Class355* FUN_00d46d50() throw();
    int FUN_00d470d0() throw();
};
struct ClassHandle355
{
    void* impl;
    void* hkDataClass_getName() throw();
    void Object_DoNothing_00dba660() throw();
};
struct Object355;
struct Value355;
struct Array355
{
    void* impl;
    int InvokeVirtualMethod_00dbac00() throw();
    Value355 UpdateState_00dbab90(int index) throw();
    ~Array355() throw();
};
struct Value355
{
    void* impl;
    int index;
    Array355 GetResult() throw();
    Object355 CreateValueInto() throw();
    Object355 GetWrappedDataObject() throw();
};
struct Object355
{
    void* impl;
    ClassHandle355* GetObjectValue(ClassHandle355* out) throw();
    int ForwardCall_00dba910(const char* name) throw();
    Value355 UpdateState_00dba870(const char* name) throw();
    ~Object355() throw();
};
struct Registry355
{
    virtual void f0() throw();
    virtual void f4() throw();
    virtual void f8() throw();
    virtual void fC() throw();
    virtual Class355* find(void* name) throw();
};
struct Allocator355
{
    virtual void f0() throw();
    virtual void f4() throw();
    virtual void f8() throw();
    virtual void* allocate(int& bytes) throw();
};

struct Sequence355
{
    Class355* elementClass;
    char* data;
    int count;
};
// ReadObject at 0x00dc2d60 fills native members through a class registry and allocation tracker.
struct NativeObjectCopier
{
    Registry355* registry;
    S_00dc3ce0* tracker;
    int restricted;
    int ReadObject(char* destination, Object355* object) throw();
    int ReadTypedValue(char* destination, int type, Value355* value, void* metadata, int owned) throw();
    int ReadValue(char* destination, int type, Value355* value, void* metadata, int owned) throw();
    int ReadArray(char* destination, Member355* member, Array355* array) throw();
    int hkClassMember_UpdateState_00dc1bf0(char* destination, Member355* member, Value355* value, Class355* type) throw();
    Class355* Copier_getMemberClassAndCheck(Member355* member, Object355* object) throw();
};
// Deserializes an Object355 into destination by iterating class members and dispatching on member type, returning 1 on failure.
// @fnv 0x00dc2d60
int NativeObjectCopier::ReadObject(char* destination, Object355* object) throw()
{
    int result = 0;
    ClassHandle355 classHandle;
    void* name = object->GetObjectValue(&classHandle)->hkDataClass_getName();
    classHandle.Object_DoNothing_00dba660();
    Class355* type = registry->find(name);
    if (!type)
        goto finished;
    do
    {
        for (int memberIndex = 0; memberIndex < type->FUN_00d46f70(); ++memberIndex)
        {
            Member355* member = type->FUN_00d46f80(memberIndex);
            char* output = destination + member->offset;
            if (!object->ForwardCall_00dba910(member->getName()))
            {
                if (member->type == 22)
                    ((Sequence355*)output)->count = 0x80000000;
                continue;
            }
            Value355 value = object->UpdateState_00dba870(member->getName());
            int count = member->getCstyleArraySize();
            if (!count)
                count = 1;
            int stride = member->FUN_00d86980() / count;
            unsigned char kind = member->type;
            int owned = ((unsigned short)~member->flags >> 9) & 1;
            switch (kind)
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 25:
            case 28:
            case 29:
            case 30:
            case 32:
            case 33:
                if (count == 1)
                {
                    result = ReadTypedValue(output, kind, &value, member->getClass(), owned);
                }
                else
                {
                    Array355 array = value.GetResult();
                    for (int i = 0; i < array.InvokeVirtualMethod_00dbac00() && !result; ++i, output += stride)
                    {

                        result = ReadValue(output, kind, &array.UpdateState_00dbab90(i), member->getClass(), owned);
                    }
                }
                break;
            case 22:
            case 26: {
                if (restricted && ((unsigned char)kind == 26 || member->subtype == 28 || member->subtype == 29))
                    goto failed;
                result = ReadArray(output, member, &value.GetResult());
                break;
            }
            case 20:
                if (member->subtype == 2)
                {
                    if (count == 1)
                        result = ReadTypedValue(output, 29, &value, 0, owned);
                    else
                    {
                        Array355 array = value.GetResult();
                        for (int i = 0; i < array.InvokeVirtualMethod_00dbac00() && !result; ++i)
                        {

                            result = ReadValue(output, 29, &array.UpdateState_00dbab90(i), 0, owned);
                            output += stride;
                        }
                    }
                }
                else if (member->subtype == 25)
                {
                    if (count == 1)
                    {

                        result = ReadTypedValue(output, kind, &value, Copier_getMemberClassAndCheck(member, &value.GetWrappedDataObject()), owned);
                    }
                    else
                    {
                        Array355 array = value.GetResult();
                        for (int i = 0; i < array.InvokeVirtualMethod_00dbac00() && !result; ++i, output += stride)
                        {

                            result = ReadValue(output, kind, &array.UpdateState_00dbab90(i),
                                               Copier_getMemberClassAndCheck(member, &array.UpdateState_00dbab90(i).CreateValueInto()), owned);
                        }
                    }
                }
                break;
            case 24:
            case 31:
                result = hkClassMember_UpdateState_00dc1bf0(output, member, &value, type);
                break;
            case 27: {
                if (restricted)
                    goto failed;
                Array355 array = value.GetResult();

                Sequence355* sequence = (Sequence355*)output;
                sequence->elementClass = Copier_getMemberClassAndCheck(member, &array.UpdateState_00dbab90(0).CreateValueInto());

                sequence->count = array.InvokeVirtualMethod_00dbac00();
                int elementSize = sequence->elementClass->FUN_00d470d0();
                {
                    int bytes = sequence->count * elementSize;
                    sequence->data = AllocElems<char>(bytes);
                    hkString_memSet(sequence->data, 0, bytes);
                }
                tracker->AddEntry((int)sequence->data, sequence->count * elementSize, 6);
                int i = 0;
                if (i < sequence->count)
                {
                    int offset = 0;
                    for (; i < sequence->count && !result; ++i, offset += elementSize)
                    {
                        char* elementDestination = sequence->data + offset;

                        result = ReadObject(elementDestination, &array.UpdateState_00dbab90(i).CreateValueInto());
                    }
                }
                break;
            }
            default:
                goto failed;
            }
            if (result == 1)
                goto failed;
        }
        type = type->FUN_00d46d50();
    } while (type);
    goto finished;
failed:
    return 1;
finished:
    return result;
}

struct S_Heap
{
    virtual void* v0() throw();
    virtual void* alloc(unsigned int n) throw();
};
inline S_Heap& GetObjectAllocator(hkMemoryRouter& holder)
{
    return *(S_Heap*)holder.m_heap;
}

void* __cdecl hkMemoryRouter_getInstance() throw();
inline S_Heap& S_heap()
{
    return GetObjectAllocator(*(hkMemoryRouter*)hkMemoryRouter_getInstance());
}
struct S_Blk
{
    int unk00;
    unsigned short sz;
};
struct S_Str
{
    const char* FUN_00d46d40();
};
struct S_Key
{
    int a;
    int b;
};
struct S_Ent
{
    S_Key k;
    int v8;
};
struct S_Arr12 : FUN_00dc35e0_class
{
    S_Ent* data;
    int m4;
    int m8;
    int next(int i)
    {
        int j = i + 1;
        while (j <= m8 && data[j].k.a == -1)
            j++;
        return j;
    }
    S_Key GetIteratorKey(int i)
    {
        return data[i].k;
    }
    int getValue(int i)
    {
        return data[i].v8;
    }
};
struct S_Map
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(S_Heap* h, int v, const char* k) throw();
};
struct S_Obj
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int m8;
    int unk0c;
    S_Map m10;
    S_Obj* hkPackfileData_hkPackfileData();
    void SetValue08(int a, const char* b) throw();
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();
};
struct S_PH;
struct S_X
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void v8() throw();
    virtual void v9() throw();
    virtual void v10(S_PH* out, S_Key* k) throw();
};
struct S_PH
{
    S_X* p;
    int hkDataObject_isNull();
    S_PH* GetObjectValue(S_PH* out);
    S_X* hkDataClass_getWorld();
    const char* hkDataClass_getName();
    void Object_DoNothing_00dba660() throw();
    void ReleaseStorage_00dba7f0() throw();
};
struct S_Dom
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual S_Str* v4(const char* y) throw();
};
struct S_T2
{
    int f0;
    S_Str* f4;
};
struct S_Owner
{
    S_Obj* p;
    operator S_Obj*() const
    {
        return p;
    }
    S_Obj* operator->() const
    {
        return p;
    }
    void operator=(S_Obj* n)
    {
        if (p && p != n)
            p->FUN_00c905b0();
        p = n;
    }
};
struct S_Ctx
{
    S_Dom* m0;
    S_Owner m4;
    int m8;
    int unk0c;
    int unk10;
    int unk14;
    S_Arr12 m18;
    int unk24;
    int unk28;
    int unk2c;
    S_Ctx* Construct(S_Dom* d, int x) throw();
    ~S_Ctx() throw()
    {
        FUN_00dc43a0();
    }
    __declspec(noalias) void FindOrCreateObjectMapEntry(S_T2* t, S_PH* h, int f) throw();
    void FUN_00dc43a0() throw();
};

__forceinline S_Obj* S_toResource(S_Ctx* context, S_PH* object) throw()
{
    S_Obj* result = 0;
    if (!object->hkDataObject_isNull())
    {
        S_Obj* resource = (S_Obj*)S_heap().alloc(0x64);
        ((S_Blk*)resource)->sz = 0x64;
        S_Obj* replacement = resource->hkPackfileData_hkPackfileData();
        context->m4 = replacement;
        S_T2 target;
        context->FindOrCreateObjectMapEntry(&target, object, 0);
        if (target.f0 && target.f4)
        {
            S_PH temporary;
            S_X* x = object->GetObjectValue(&temporary)->hkDataClass_getWorld();
            temporary.Object_DoNothing_00dba660();
            int index = context->m18.ProcessEntries_00dc35e0();
            while (index <= context->m18.m8)
            {
                S_Key key = context->m18.GetIteratorKey(index);
                S_PH value;
                x->v10(&value, &key);
                S_PH text;
                const char* name = value.GetObjectValue(&text)->hkDataClass_getName();
                text.Object_DoNothing_00dba660();
                S_Str* string = context->m0->v4(name);
                int number = context->m18.getValue(index);
                S_Obj* owner = context->m4;
                const char* keyName = string->FUN_00d46d40();
                S_Heap& heap = S_heap();
                owner->m10.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(&heap, number, keyName);
                value.ReleaseStorage_00dba7f0();
                index = context->m18.next(index);
            }
            S_Obj* owner = context->m4;
            const char* name = target.f4->FUN_00d46d40();
            owner->SetValue08(target.f0, name);
            result = context->m4;
            result->FUN_00c90510();
            context->m4 = 0;
            return result;
        }
        context->m4 = 0;
    }
    return result;
}

// Constructs a context from domain and delegates to S_toResource to build an S_Obj from object.
// @fnv 0x00dc3300
// src: XBOX_PDB 0x00dc3300
S_Obj* __cdecl hkDataObjectUtil_toResourceWithRegistry(S_PH* object, S_Dom* domain) throw()
{
    S_Ctx context;
    S_Ctx* ctx = context.Construct(domain, 0);
    return S_toResource(ctx, object);
}

struct Object
{
    void* impl;
    Object() throw() : impl(0)
    {}
    ~Object() throw()
    {
        ReleaseStorage_00dba7f0();
    }
    void ReleaseStorage_00dba7f0() throw();
};
struct Element
{
    void* array;
    int index;
    int InvokeVirtualMethod_00dbac40() const throw();
    int CallVirtualWithArg() const throw();
    float ApplyValue() const throw();
    const float* DispatchToVTableSlot8(int) const throw();
    const char* ForwardCall_00dbac70() const throw();
    Object CreateValueInto() const throw();
    void InvokeOnInterface(int) throw();
    void Apply_Thunk(float) throw();
    void InvokeVirtualMethod_00dbad60(const float*, int) throw();
    void InvokeVirtualMethod_00dbad00(const Object&) throw();
    void InvokeVirtualMethod_00dbadc0(const char*) throw();
};
// Dispatches on the value returned by src.FUN_00dbac40() and invokes the corresponding destination method for handled cases.
// @fnv 0x00dc37f0
// src: GUESS 0x00dc37f0 (confidence: medium)
void Cloner::CopyValueByType(Element dst, const Element& src)
{

    switch (src.InvokeVirtualMethod_00dbac40())
    {
    case 1:
    case 2:
        dst.InvokeOnInterface(src.CallVirtualWithArg());
        break;
    case 3:
        dst.Apply_Thunk(src.ApplyValue());
        break;
    case 4:
    case 5:
    case 6:
    case 7: {
        int n = 4 * (src.InvokeVirtualMethod_00dbac40() - 3);
        dst.InvokeVirtualMethod_00dbad60(src.DispatchToVTableSlot8(n), n);
        break;
    }
    case 8:
    case 9: {
        dst.InvokeVirtualMethod_00dbad00(CloneObject(&dst ? src.CreateValueInto() : Object()));
        break;
    }
    case 10:
        dst.InvokeVirtualMethod_00dbadc0(src.ForwardCall_00dbac70());
        break;
    }
}

struct S_00dc4710_Alloc
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int n);
};

inline S_00dc4710_Alloc& GetReferenceAllocator(hkMemoryRouter& holder)
{
    return *(S_00dc4710_Alloc*)holder.m_heap;
}

struct S_00dc4710_Ref
{
    virtual void v0();
    short m_iElementCount;
    short m_iObjectReferenceCount;
    void removeReference() throw();  // FUN_00c905b0
    static void* operator new(unsigned int n)
    {
        void* p = GetReferenceAllocator(*(hkMemoryRouter*)hkMemoryRouter_getInstance()).AllocateMemoryBlock(n);
        ((S_00dc4710_Ref*)p)->m_iElementCount = (short)n;
        return p;
    }
    static void operator delete(void*)
    {}
};
struct S_00dc4710_Thing : S_00dc4710_Ref
{
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    S_00dc4710_Thing() throw();  // FUN_00e05700
};
struct S_00dc4710_Key
{
    int a;
    int b;
};
struct S_00dc4710_Ret
{
    int p;
    int q;
};
struct S_00dc4710_Bool
{
    char b;
    S_00dc4710_Bool()
    {}
};

template <typename K, typename V> struct hkMap_dc4710
{
    // hkMapBase<KEY,VAL>::Pair (Havok hkMap.h: key, val); renamed so it does not take include/Pair.h's name
    struct KeyValue
    {
        K key;
        V val;
    };
    KeyValue* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    typedef int Iterator;

    inline Iterator GetFirstIterator() const
    {
        int i = 0;
        int last = m_iPairCount;
        if (last >= 0)
        {
            KeyValue* p = m_kPrimitiveElement;
            do
            {
                if (p->key.a != -1)
                    break;
                i++;
                p++;
            } while (i <= last);
        }
        return i;
    }
    inline Iterator getNext(Iterator i) const
    {
        int last = m_iPairCount;
        i++;
        if (i <= last)
        {
            KeyValue* p = m_kPrimitiveElement + i;
            do
            {
                if (p->key.a != -1)
                    break;
                i++;
                p++;
            } while (i <= last);
        }
        return i;
    }
    inline bool isValid(Iterator i) const
    {
        return i <= m_iPairCount;
    }
    inline KeyValue& getPair(Iterator i) const
    {
        const Iterator& index = i;
        KeyValue* const& data = m_kPrimitiveElement;
        return data[index];
    }
    inline K GetIteratorKey(Iterator i) const
    {
        return getPair(i).key;
    }
    inline V getValue(Iterator i) const
    {
        __assume(m_kPrimitiveElement != 0);
        return getPair(i).val;
    }
};
struct S_00dc4710_ClassC
{
    int FUN_00d470d0() throw();
    const char* FUN_00d46d40() throw();
    S_00dc4710_Bool GetLastNodeFlag() throw();
};
struct S_00dc4710_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual S_00dc4710_ClassC* vf10(void* impl) throw();
};
struct S_00dc4710_ClassImpl;
struct S_00dc4710_Obj;
struct S_00dc4710_Class
{
    S_00dc4710_ClassImpl* m_pClassImpl;
    ~S_00dc4710_Class() throw();                        // FUN_00dba660
    S_00dc4710_ClassImpl* getImplementation() throw();  // FUN_00dba680
    struct S_00dc4710_World* hkDataClass_getWorld() throw();
};
struct S_00dc4710_ObjImpl;
struct S_00dc4710_Obj
{
    S_00dc4710_ObjImpl* m_pClassImpl;
    ~S_00dc4710_Obj() throw();  // FUN_00dba7f0
    S_00dc4710_Class GetObjectValue() throw();
};
struct S_00dc4710_World
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual S_00dc4710_Obj vf28(const S_00dc4710_Key& k) throw();
};
struct S_00dc4710_Entry
{
    S_00dc4710_Key key;
    unsigned short* item;
};
struct S_00dc4710_Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* vf10(void* item, const char* name) throw();
};
struct S_00dc4710_Err
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vc(int a, int id, const char* msg, const char* file, int line) throw();
};
extern S_00dc4710_Err* DAT_01268360;
struct S_00dc4710_Stream
{
    int unk0;
    int unk4;
    int unk8;
    S_00dc4710_Stream(char* b, int n) throw();  // FUN_00cb1600
    ~S_00dc4710_Stream() throw();               // FUN_00cc00e0
    S_00dc4710_Stream& ProcessAndReturnValue_00cc01c0(const char* s) throw();
};
struct S_00dc4710_Result : S_00dc4710_Ref
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_00dc4710_Result(const S_00dc4710_Ret& r) throw();  // Initialize
    void hkObjectResource_setClassNameRegistry(S_00dc4710_Owner* o) throw();
    void hkObjectResource_setTypeInfoRegistry(S_00dc4710_Sink* s) throw();
};
struct S_00dc4710_Map
{
    int unk0;
    int unk4;
    int unk8;
    unsigned short LookupHashEntry(unsigned short* item, int z) throw();
};
struct S_00dc4710_Cls
{
    S_00dc4710_Owner* m_pOwnerObject;
    S_00dc4710_Thing* m_thing;
    int unk08;
    S_00dc4710_Map m_map;
    hkMap_dc4710<S_00dc4710_Key, unsigned short*> m_entries;
    S_00dc4710_Ret FindOrCreateObjectMapEntry(S_00dc4710_Obj* a1, int one) throw();
    S_00dc4710_Result* Copier_toObject(S_00dc4710_Obj* a1, S_00dc4710_Sink* a2) throw();
};

// Creates a Result from a1, updates m_entries via m_map and m_pOwnerObject, and reports unregistered classes through DAT_01268360.
// @fnv 0x00dc4710
// src: XBOX_PDB 0x00dc4710
S_00dc4710_Result* S_00dc4710_Cls::Copier_toObject(S_00dc4710_Obj* apObj, S_00dc4710_Sink* apSink) throw()
{
    S_00dc4710_Thing* t = new S_00dc4710_Thing;
    if (m_thing && m_thing != t)
        m_thing->removeReference();
    m_thing = t;
    S_00dc4710_Ret ret = FindOrCreateObjectMapEntry(apObj, 1);
    S_00dc4710_World* world = apObj->GetObjectValue().hkDataClass_getWorld();
    if (ret.p == 0)
    {
        m_thing->unk30 = 0;
        if (m_thing)
            m_thing->removeReference();
        m_thing = 0;
        return 0;
    }
    for (int i = m_entries.GetFirstIterator(); m_entries.isValid(i); i = m_entries.getNext(i))
    {
        S_00dc4710_Obj obj = world->vf28(m_entries.GetIteratorKey(i));
        S_00dc4710_ClassImpl* impl = obj.GetObjectValue().getImplementation();
        S_00dc4710_ClassC* c = m_pOwnerObject->vf10(impl);
        unsigned short* item = m_entries.getValue(i);
        unsigned short n = m_map.LookupHashEntry(item, 0);
        if ((short)n > 0)
        {
            item[2] = (unsigned short)c->FUN_00d470d0();
            item[3] = n;
        }
    }
    for (int i = m_entries.GetFirstIterator(); m_entries.isValid(i); i = m_entries.getNext(i))
    {
        S_00dc4710_Obj obj = world->vf28(m_entries.GetIteratorKey(i));
        S_00dc4710_ClassImpl* impl = obj.GetObjectValue().getImplementation();
        S_00dc4710_ClassC* c = m_pOwnerObject->vf10(impl);
        unsigned short* item = m_entries.getValue(i);
        void* r = apSink->vf10(item, c->FUN_00d46d40());
        if (c->GetLastNodeFlag().b != 0 && r == 0)
        {
            unsigned int buf[128];
            S_00dc4710_Stream s((char*)buf, 512);
            s.ProcessAndReturnValue_00cc01c0("Cannot finish virtual object of class ")
                .ProcessAndReturnValue_00cc01c0(c->FUN_00d46d40())
                .ProcessAndReturnValue_00cc01c0(". Please make sure the class is registered.");
            DAT_01268360->vc(1, 0x7c303834, (const char*)buf, ".\\Data\\Util\\hkDataObjectUtil.cpp", 0x133);
        }
    }
    S_00dc4710_Result* pResult = new S_00dc4710_Result(ret);
    pResult->hkObjectResource_setClassNameRegistry(m_pOwnerObject);
    pResult->hkObjectResource_setTypeInfoRegistry(apSink);
    S_00dc4710_Thing* pThing = m_thing;
    pThing->unk30 = 0;
    pThing->unk38 = 0;
    pThing->unk44 = 0;
    if (m_thing)
        m_thing->removeReference();
    m_thing = 0;
    return pResult;
}

namespace fnv_00dc3d40 {
struct DObj
{
    int unk00;
    void ReleaseStorage_00dba7f0() throw();
    __forceinline ~DObj() throw()
    {
        ReleaseStorage_00dba7f0();
    }
};
struct DArray;
struct DValue
{
    union
    {
        __int64 handle;
        struct
        {
            int unk00;
            int unk04;
        };
    };
    int CallVirtualWithArg() throw();
    float ApplyValue() throw();
    const float* DispatchToVTableSlot8(int n) throw();
    const char* ForwardCall_00dbac70() throw();
    DObj CreateValueInto() throw();
    DArray GetMemberArrayValue() throw();
    void InvokeOnInterface(int v) throw();
    void Apply_Thunk(float v) throw();
    void InvokeVirtualMethod_00dbad60(const float* v, int n) throw();
    void InvokeVirtualMethod_00dbad00(const DObj& v) throw();
    void InvokeVirtualMethod_00dbadc0(const char* v) throw();
};
struct DMember
{
    const char* name;
    int unk04;
    unsigned int type;
    int unk0c;
    int tupleSize;
    __forceinline DMember() throw() : name(0), unk04(0), type(0), unk0c(0), tupleSize(0)
    {}
};
struct DAllocator
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void* AllocateBufferWithSize(int& numBytes) throw();
    virtual void ReturnMemory(void*, int) throw();
};
inline DAllocator& GetTemporaryHeap(hkMemoryRouter& holder) throw()
{
    return *(DAllocator*)holder.m_temp;
}

__declspec(restrict) void* __cdecl hkMemoryRouter_getInstance();
// hkMemoryAllocator::_bufAlloc<T>: the allocator may round the request up, the element count is updated
template <class T> __forceinline T* AllocateBufferWithSize(DAllocator& a, int& reqNumInOut) throw()
{
    int n = reqNumInOut * (int)sizeof(T);
    T* p = (T*)a.AllocateBufferWithSize(n);
    reqNumInOut = n / (int)sizeof(T);
    return p;
}
template <class T> __forceinline void construct(T* p, int n) throw()
{
    for (int i = 0; i < n; ++i)
        new (p + i) T();
}

// hkArray<MemberInfo>::Temp: hkArray(int n) constructs every allocated element (n is updated by _bufAlloc)
struct DMembers
{
    DMember* data;
    int size;
    int capacity;
    __forceinline DMembers(int n) throw() : data(0), size(0), capacity(0x80000000)
    {
        DAllocator& alloc = GetTemporaryHeap(*(hkMemoryRouter*)hkMemoryRouter_getInstance());
        DMember* p = n ? AllocateBufferWithSize<DMember>(alloc, n) : 0;
        int cap = n ? n : 0x80000000;
        data = p;
        size = n;
        capacity = cap;
        construct(data, size);
    }
    __forceinline void setSizeUnchecked(int n) throw()
    {
        construct(data + size, n - size);
        size = n;
    }
    __forceinline ~DMembers() throw()
    {
        DAllocator& a = GetTemporaryHeap(*(hkMemoryRouter*)hkMemoryRouter_getInstance());
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.ReturnMemory(data, (capacity & 0x3fffffff) * sizeof(DMember));
        data = 0;
        capacity = 0x80000000;
    }
};
struct DClass
{
    int impl;
    int ForwardCall_00dba730() throw();
    void DispatchItems(DMembers& out) throw();
    void Object_DoNothing_00dba660() throw();
    __forceinline ~DClass() throw()
    {
        Object_DoNothing_00dba660();
    }
};
struct DArray
{
    int impl;
    int ForwardCall_00dbac10() throw();
    int InvokeVirtualMethod_00dbac00() throw();
    DValue CreateResultPair(int i) throw();
    DValue UpdateState_00dbab90(int i) throw();
    void Get_Thunk(int n) throw();
    DClass ProcessAndReturnValue_00dbac20() throw();
    DArray InvokeCallbackInto(const char* name) throw();
    void ReleaseStorage_00dbab70() throw();
    __forceinline ~DArray() throw()
    {
        ReleaseStorage_00dbab70();
    }
};
struct DCloner
{
    DObj CloneObject(const DObj& o) throw();
    void CopyValueByType(DValue dst, const DValue& src) throw();
    void Cloner_copyArray(DArray& destination, const DArray& src, int n) throw();
};
// Copies n elements from source array to destination array, dispatching on element type to clone scalars, vectors, objects, classes, or strings.
// @fnv 0x00dc3d40
// src: XBOX_PDB 0x00dc3d40
void DCloner::Cloner_copyArray(DArray& destination, const DArray& source, int aiCount) throw()
{
    DArray& src = const_cast<DArray&>(source);
    switch (src.ForwardCall_00dbac10())
    {
    case 1:
    case 2:
        for (int i = 0; i < aiCount; ++i)
            destination.UpdateState_00dbab90(i).InvokeOnInterface(src.CreateResultPair(i).CallVirtualWithArg());
        break;
    case 3:
        for (int i = 0; i < aiCount; ++i)
            destination.UpdateState_00dbab90(i).Apply_Thunk(src.CreateResultPair(i).ApplyValue());
        break;
    case 4:
    case 5:
    case 6:
    case 7: {
        int iVectorSize = (src.ForwardCall_00dbac10() - 3) * 4;
        for (int i = 0; i < aiCount; ++i)
            destination.UpdateState_00dbab90(i).InvokeVirtualMethod_00dbad60(src.CreateResultPair(i).DispatchToVTableSlot8(iVectorSize), iVectorSize);
        break;
    }
    case 8:
        destination.Get_Thunk(aiCount);
        for (int i = 0; i < aiCount; ++i)
            destination.UpdateState_00dbab90(i).InvokeVirtualMethod_00dbad00(CloneObject(src.CreateResultPair(i).CreateValueInto()));
        break;
    case 9: {
        destination.Get_Thunk(aiCount);
        DClass pClassInfo = src.ProcessAndReturnValue_00dbac20();
        int numMembers = pClassInfo.ForwardCall_00dba730();
        DMembers members(numMembers);
        members.setSizeUnchecked(numMembers);
        pClassInfo.DispatchItems(members);
        for (int iMemberIndex = 0; iMemberIndex < numMembers; ++iMemberIndex)
        {
            DMember& member = members.data[iMemberIndex];
            if (member.type & 15)
            {
                DArray dstMember = destination.InvokeCallbackInto(member.name);
                DArray srcMember = src.InvokeCallbackInto(member.name);
                if (member.type & 0x30)
                {
                    for (int i = 0; i < aiCount; ++i)
                    {
                        int iLength = (member.type & 0x10) ? dstMember.UpdateState_00dbab90(i).GetMemberArrayValue().InvokeVirtualMethod_00dbac00()
                                                           : member.tupleSize;
                        DArray dstNested = dstMember.UpdateState_00dbab90(i).GetMemberArrayValue();
                        Cloner_copyArray(dstNested, srcMember.UpdateState_00dbab90(i).GetMemberArrayValue(), iLength);
                    }
                }
                else
                {
                    for (int i = 0; i < aiCount; ++i)
                    {
                        CopyValueByType(dstMember.UpdateState_00dbab90(i), srcMember.UpdateState_00dbab90(i));
                    }
                }
            }
        }
        break;
    }
    case 10:
        for (int i = 0; i < aiCount; ++i)
            destination.UpdateState_00dbab90(i).InvokeVirtualMethod_00dbadc0(src.CreateResultPair(i).ForwardCall_00dbac70());
        break;
    }
}
}  // namespace fnv_00dc3d40

struct ArrayImpl;
struct MemberInfo
{
    const char* m_name;
    const char* m_pClassName;
    int m_type;
    void* m_valuePtr;
    int m_uiItemCount;
};

struct FUN_00dbab70
{
    ArrayImpl* m_pClassImpl;
    FUN_00dbab70() throw()
    {}
    ~FUN_00dbab70() throw();
    void FUN_00dbab50(ArrayImpl* impl) throw();
    void Get_Thunk(int size) throw();
    int InvokeVirtualMethod_00dbac00() const throw();
};

struct DataObject;
struct DataWorld
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual void vf2() throw();
    virtual void vf3() throw();
    virtual void vf4() throw();
    virtual ArrayImpl* m_ppNewArray(DataObject& obj, const MemberInfo& minfo) throw();
};

struct FUN_00dba660
{
    void* m_pClassImpl;
    ~FUN_00dba660() throw();
    DataWorld* hkDataClass_getWorld() const throw();
};

struct DataValue
{
    void* m_pClassImpl;
    void* m_handle;
    FUN_00dbab70 GetResult() const throw();
};

struct DataObject
{
    void* m_pClassImpl;
    FUN_00dba660 GetObjectValue() const throw();
    DataValue* UpdateState_00dba870(DataValue* out, const char* name) throw();
    DataValue* Get_Thunk(DataValue* out, const char* name) const throw();
    DataValue Get_Thunk(const char* name) const throw();
};

struct ValueCloner
{
    void Cloner_copyArray(FUN_00dbab70& dst, const FUN_00dbab70& src, int n) throw();
    void CopyValue(DataValue dst, const DataValue& src) throw();
    void Cloner_copyValue(DataObject& dstObj, const DataObject& srcObj, const MemberInfo& minfo) throw();
};

template <class T> struct CheckedReference
{
    T* value;
    CheckedReference(T& object) throw() : value(&object)
    {}
    ~CheckedReference() throw()
    {}
    operator T&() const throw()
    {
        return *value;
    }
};
// Clones a data member from srcObj to dstObj based on minfo.m_type, handling arrays and plain values.
// @fnv 0x00dc4210
// src: XBOX_PDB 0x00dc4210
void ValueCloner::Cloner_copyValue(DataObject& dstObj, const DataObject& srcObj, const MemberInfo& minfo) throw()
{
    DataValue v;

    if (minfo.m_type & 0x20)
    {
        FUN_00dbab70 srcArray =
            ((const DataObject&)((minfo.m_type & 0x20) ? CheckedReference<const DataObject>(srcObj)
                                                       : CheckedReference<const DataObject>(srcObj)))
                .Get_Thunk(&v, minfo.m_name)
                ->GetResult();
        FUN_00dbab70 dstArray;
        dstArray.FUN_00dbab50(dstObj.GetObjectValue().hkDataClass_getWorld()->m_ppNewArray(dstObj, minfo));
        dstArray.Get_Thunk(minfo.m_uiItemCount);
        Cloner_copyArray(dstArray, srcArray, minfo.m_uiItemCount);
    }
    else if (minfo.m_type & 0x10)
    {
        FUN_00dbab70 srcArray = srcObj.Get_Thunk(&v, minfo.m_name)->GetResult();
        FUN_00dbab70 dstArray;
        dstArray.FUN_00dbab50(dstObj.GetObjectValue().hkDataClass_getWorld()->m_ppNewArray(dstObj, minfo));
        dstArray.Get_Thunk(srcArray.InvokeVirtualMethod_00dbac00());
        Cloner_copyArray(dstArray, srcArray, srcArray.InvokeVirtualMethod_00dbac00());
    }
    else
    {
        dstObj.UpdateState_00dba870(&v, minfo.m_name);
        CopyValue(v, srcObj.Get_Thunk(minfo.m_name));
    }
}

extern "C" void _ReadWriteBarrier();
struct AllocatorVtbl;
__declspec(restrict) void* __cdecl hkMemoryRouter_getInstance() throw();
__forceinline S_00dc3ce0_Allocator& GetMapAllocator(hkMemoryRouter& holder) throw()
{
    return *(S_00dc3ce0_Allocator*)holder.m_heap;
}

struct FlagBool
{
    char value;
    FlagBool()
    {}
    ~FlagBool() throw()
    {}
    FlagBool(bool b) : value(b)
    {}
    __forceinline operator bool() const throw()
    {
        return value != 0;
    }
};
void ResizeAudioStream(S_00dc3ce0_Allocator& alloc, void* array, int sizeElem) throw();

struct Key64
{
    union
    {
        unsigned __int64 val;
        struct
        {
            unsigned int low, high;
        };
    };
    __forceinline bool operator==(const Key64& o) const throw()
    {
        return low == o.low && high == o.high;
    }
};

struct DObjWrap
{
    void* m_ptr;
    ~DObjWrap() throw();
    int TestValue() throw();
    int hkDataClass_getName() throw();
    int ForwardCall_00dba690() throw();
};

struct ObjB
{
    int FUN_00d47120() throw();
    int FUN_00d470d0() throw();
    FlagBool GetLastNodeFlag() throw();
};

struct ObjA
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual ObjB* v10(int arg) throw();
};

struct Arg1
{
    int hkDataObject_isNull() throw();
    DObjWrap GetObjectValue() throw();
    Key64* GetSourcePair(Key64* out) throw();
};

struct KeyArrayLocalForm
{ // local form of hkArray: 0x00dc4430 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    Key64* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline int indexOf(const Key64& key) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    __forceinline void pushBack(S_00dc3ce0_Allocator& alloc, const Key64& e) throw()
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(Key64));
        }
        new (m_data + m_iElementCount) Key64(e);
        m_iElementCount++;
    }

    __forceinline void pushBack(const Key64& e) throw()
    {
        pushBack(GetMapAllocator(*(hkMemoryRouter*)hkMemoryRouter_getInstance()), e);
    }

    __forceinline void popBack() throw()
    {
        m_iElementCount--;
    }
};

struct Map18
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void* Lookup(unsigned __int64 key, void* defVal) throw();
    void InsertKeyValue(S_00dc3ce0_Allocator& alloc, unsigned __int64 key, void* val) throw();
};

struct Pair0C
{
    void* key;
    int val;
};

struct Map0C
{
    Pair0C* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int InsertKeyIfAbsent(S_00dc3ce0_Allocator& alloc, void* key, int defVal) throw();
};

class GlobalObjectO2_00d472a0
{
  public:
    FlagBool hkClass_isSuperClass(ObjB* obj) throw();
};
extern GlobalObjectO2_00d472a0 g_01268748;

extern "C" void* __cdecl _FUN_00cb1280(void*, int, unsigned int) throw();

struct AllocatorVtbl
{
    virtual void v00() throw();
    virtual void* allocate(int size) throw();
};

struct RetDC4430
{
    void* first;
    ObjB* second;
};

struct DC4430_Class
{
    ObjA* m_obj00;
    S_00dc3ce0* m_obj04;
    int m_unk08;
    Map0C m_map0c;
    Map18 m_map18;
    KeyArrayLocalForm m_ppData;

    int ReadObject(void* mem, Arg1* arg1) throw();
    RetDC4430 FindOrCreateObjectMapEntry(Arg1* arg1, int arg2) throw();
};

// Looks up or allocates a Map18 entry for arg1's key, optionally tracking it in m_ppData and m_map0c, returning the entry pointer and class info.
// @fnv 0x00dc4430
// src: GUESS 0x00dc4430 (confidence: medium)
RetDC4430 DC4430_Class::FindOrCreateObjectMapEntry(Arg1* apArg, int aiFlag) throw()
{
    RetDC4430 result;
    result.first = 0;

    long ret;
    if (m_unk08)
    {
        ret = 1;
        if (!aiFlag)
        {
            ret = 0;
        }
    }

    else
    {
        ret = 0;
    }

    _ReadWriteBarrier();
    result.second = 0;
    if (!apArg->hkDataObject_isNull())
    {

        if (apArg->GetObjectValue().TestValue() || !apArg->GetObjectValue().hkDataClass_getName())
        {
            result.second = 0;
            return result;
        }

        Key64 key;
        if (ret)
        {
            if (m_ppData.indexOf(*apArg->GetSourcePair(&key)) != -1)
            {
                RetDC4430 size;
                size.first = 0;
                size.second = 0;
                return size;
            }
            m_ppData.pushBack(*apArg->GetSourcePair(&key));
        }

        ObjA* world = m_obj00;
        ObjB* pClassInfo = world->v10(apArg->GetObjectValue().hkDataClass_getName());

        result.first = m_map18.Lookup(apArg->GetSourcePair(&key)->val, 0);
        if (result.first == 0)
        {
            (apArg->GetObjectValue().ForwardCall_00dba690(), pClassInfo->FUN_00d47120());
            int mem = pClassInfo->FUN_00d470d0();
            hkMemoryRouter* memory = (hkMemoryRouter*)hkMemoryRouter_getInstance();
            AllocatorVtbl* heap = (AllocatorVtbl*)memory->m_heap;
            result.first = heap->allocate(mem);
            m_obj04->AddEntry((int)result.first, mem, 6);
            _FUN_00cb1280(result.first, 0, pClassInfo->FUN_00d470d0());

            Key64 temp;
            Key64* __restrict pReturnedKey = apArg->GetSourcePair(&temp);
            Key64* __restrict destination = &key;
            *destination = *pReturnedKey;
            m_map18.InsertKeyValue(GetMapAllocator(*(hkMemoryRouter*)hkMemoryRouter_getInstance()), key.val, result.first);

            if (ReadObject(result.first, apArg) == 1)
            {
                result.first = 0;
                pClassInfo = 0;
            }
        }

        if (0 != result.first)
        {
            if (ret)
            {

                if (pClassInfo->GetLastNodeFlag() && g_01268748.hkClass_isSuperClass(pClassInfo))
                {
                    int b = m_map0c.InsertKeyIfAbsent(GetMapAllocator(*(hkMemoryRouter*)hkMemoryRouter_getInstance()), result.first, 0);
                    m_map0c.m_kPrimitiveElement[b].val++;
                }
            }
        }

        if (ret)
        {
            m_ppData.popBack();
        }

        result.second = pClassInfo;
    }
    return result;
}

struct DBool_dc3a80
{
    char m_cBooleanValue;
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};
struct DKlass_dc3a80
{
    const char* FUN_00d46d40() throw();
    DBool_dc3a80 hkClass_isSuperClass(const DKlass_dc3a80* other) throw();
};
struct DClass_dc3a80
{
    void* m_pClassImpl;
    const char* hkDataClass_getName() const throw();
    void Object_DoNothing_00dba660() throw();
    __forceinline ~DClass_dc3a80() throw()
    {
        Object_DoNothing_00dba660();
    }
};
struct DObj_dc3a80
{
    int unk00;
    int hkDataObject_isNull() const throw();
    DClass_dc3a80 GetObjectValue() const throw();
};
struct DAttribute_dc3a80
{
    void** unk00;
};
struct DMember_dc3a80
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned short unk0E;
    unsigned short unk10;
    DKlass_dc3a80* getClass() const throw();
    DAttribute_dc3a80* getAttribute_00d86960(const char* name) const throw();
};
struct DWorld_dc3a80
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual DKlass_dc3a80* GetClassFromName(const char* name) throw();
};
extern "C" int __cdecl hkString_strCmp(const char* a, const char* b) throw();
struct DReader_dc3a80
{
    DWorld_dc3a80* unk00;
    void* unk04;
    int unk08;
    DKlass_dc3a80* Copier_getMemberClassAndCheck(const DMember_dc3a80* member, const DObj_dc3a80& obj) throw();
};
// Resolves the DKlass for a DMember by comparing the object's class name against the expected class and the hk.DataObjectType attribute.
// @fnv 0x00dc3a80
// src: XBOX_PDB 0x00dc3a80
DKlass_dc3a80* DReader_dc3a80::Copier_getMemberClassAndCheck(const DMember_dc3a80* member, const DObj_dc3a80& obj) throw()
{
    if (obj.hkDataObject_isNull())
        return 0;
    DKlass_dc3a80* pExpectedClass = member->getClass();
    const char* name = obj.GetObjectValue().hkDataClass_getName();
    DKlass_dc3a80* pActualClass = name ? unk00->GetClassFromName(name) : 0;
    if (!pExpectedClass)
        return pActualClass;
    if (!pActualClass)
        return 0;
    if (!hkString_strCmp(pExpectedClass->FUN_00d46d40(), name))
        return pExpectedClass;
    if (pExpectedClass->hkClass_isSuperClass(pActualClass))
        return pActualClass;
    DAttribute_dc3a80* pAttribute = member->getAttribute_00d86960("hk.DataObjectType");
    if (pAttribute)
    {
        const char* pcTypeName = (const char*)*pAttribute->unk00;
        pExpectedClass = unk00->GetClassFromName(pcTypeName);
        if (pExpectedClass->hkClass_isSuperClass(pActualClass))
            return pActualClass;
    }
    return pExpectedClass;
}
