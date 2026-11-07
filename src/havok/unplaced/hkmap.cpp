
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cb18f0_t
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_iPairCount;
    int FindSlot(int);
    int RemoveEntry(int);
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(int key);
};

// @fnv 0x00cb1fb0
// src: XBOX_PDB 0x00cb1fb0
int __thiscall FUN_00cb18f0_t::hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(int key)
{
    int found = FindSlot(key);
    if (found <= m_iPairCount)
    {
        RemoveEntry(found);
        return 0;
    }
    return 1;
}

// @fnv 0x00cb1810
// src: XBOX_PDB 0x00cb1810
int __cdecl hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_getSizeInBytesFor(int key)
{
    int iDoubled = key * 2;
    int size = 8;
    if (iDoubled > 8)
    {
        while (size < iDoubled)
            size += size;
    }
    return size << 4;
}

struct FUN_00cb1930_t
{
    int* m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_iPairCount;
    int LookupHashEntry(int key, int defaultValue);
};

// @fnv 0x00cb1930
int FUN_00cb1930_t::LookupHashEntry(int key, int defaultValue)
{
    if (m_iPairCount > 0)
    {
        unsigned int uiIndex = ((unsigned int)key >> 4) * 0x9e3779b1u;
        uiIndex &= m_iPairCount;
        int iCurrentKey = m_uiStandInValue[uiIndex * 2];
        while (iCurrentKey != -1)
        {
            if (iCurrentKey == key)
                return m_uiStandInValue[uiIndex * 2 + 1];
            uiIndex = (uiIndex + 1) & m_iPairCount;
            iCurrentKey = m_uiStandInValue[uiIndex * 2];
        }
    }
    return defaultValue;
}

// @fnv 0x00cb17f0
// src: GUESS 0x00cb17f0 (confidence: low)
int Hkmap_ProcessEntries_00cb17f0(int value)
{
    int required = value * 2;
    int size = 8;

    if (size < required)
    {
        do
        {
            size *= 2;
        } while (size < required);
    }

    return size * 8;
}

struct DepthLimit
{
    int FindSlot(int);
    int* m_buckets;
};
// Hashes key, and if the hash is within the limit, writes the bucket's paired value to out and returns 0; otherwise returns 1.
// @fnv 0x00cb1980
int __fastcall LookupBucketValue(DepthLimit* self, int edx, int key, int* paiOut)
{
    int iHash = self->FindSlot(key);
    if (iHash <= *(int*)((char*)self + 8))
    {
        *paiOut = self->m_buckets[iHash * 2 + 1];
        return 0;
    }
    return 1;
}

struct FUN_00cb1a60_t
{
    int* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    void ResetEntries();
};

// @fnv 0x00cb1a60
void FUN_00cb1a60_t::ResetEntries()
{
    int i;
    int n = m_iPairCount + 1;
    for (i = 0; i < n; ++i)
        m_kPrimitiveElement[i * 2] = -1;
    m_iCapacityFlags &= 0x80000000;
}

namespace fnv_00cb1ac0 {
struct TypeNode
{
    int m_key;
    int m_uiFilterValue;
};

struct Allocator
{
    virtual void Unused() = 0;
    virtual void* Allocate(int size);
    virtual void Free(void* data, int size);
};

struct DepthLimit
{
    TypeNode* m_data;
    int m_flags;
    int m_uiItemCount;

    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* allocator, void* key, int value);
    void ResizeAndRehash(Allocator* allocator, int count);
};

// @fnv 0x00cb1ac0
void DepthLimit::ResizeAndRehash(Allocator* allocator, int count)
{
    int iNewCapacity = count;
    if (iNewCapacity <= 8)
        iNewCapacity = 8;

    unsigned int flags = m_flags & 0x80000000u;
    TypeNode* pOldEntries = m_data;
    int iOldCapacity = m_uiItemCount + 1;

    m_data = static_cast<TypeNode*>(allocator->Allocate(iNewCapacity * 8));

    for (int i = 0; i < iNewCapacity; ++i)
        m_data[i].m_key = -1;

    m_uiItemCount = iNewCapacity - 1;
    m_flags = 0;

    for (int i = 0; i < iOldCapacity; ++i)
    {
        if (pOldEntries[i].m_key != -1)
            this->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(allocator, reinterpret_cast<void*>(pOldEntries[i].m_key),
                               pOldEntries[i].m_uiFilterValue);
    }

    if (flags == 0)
        allocator->Free(pOldEntries, iOldCapacity * 8);
}
}  // namespace fnv_00cb1ac0

struct FUN_00cb1e40_arg_t
{
    // Empty virtual function body that does nothing.
// @fnv 0x00cb1e40
    virtual void FUN_00cb1e40_dummy()
    {}

    virtual void FUN_00cb1e40_dummy2()
    {}

    virtual void FUN_00cb1e40_op(int data, int size)
    {}
};

struct FUN_00cb1e40_t
{
    int m_data;
    int m_flags;
    int m_uiItemCount;

    void ProcessEntries_00cb1e00();
    void hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_clearAndDeallocate(FUN_00cb1e40_arg_t* arg);
};

// src: XBOX_PDB 0x00cb1e40
void FUN_00cb1e40_t::hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_clearAndDeallocate(FUN_00cb1e40_arg_t* arg)
{
    ProcessEntries_00cb1e00();

    if (!(m_flags & 0x80000000))
    {
        arg->FUN_00cb1e40_op(m_data, (m_uiItemCount + 1) << 4);
    }
}

struct CB1BC0Allocator
{
};

struct CB1BC0Map
{
    void ResizeStorage(CB1BC0Allocator&, int);
    void ResizeToFit(CB1BC0Allocator&, int);
};

// @fnv 0x00cb2030
void CB1BC0Map::ResizeToFit(CB1BC0Allocator& allocator, int size)
{
    int doubledSize = size + size;
    int newSize = 8;

    if (doubledSize > 8)
    {
        do
        {
            newSize += newSize;
        } while (newSize < doubledSize);
    }

    ResizeStorage(allocator, newSize);
}

struct HashEntryTable
{
    unsigned long FindValueForKey(unsigned long key, unsigned long defaultValue);
};
// @fnv 0x00dc8e30
unsigned long __fastcall LookupWithDefault(HashEntryTable* self, int edx, unsigned long key)
{
    return ((HashEntryTable*)((char*)self + 0xc))->FindValueForKey(key, -1);
}

struct FUN_00cb17e0_cls
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_iPairCount;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_getMemSize();
};

// @fnv 0x00cb17e0
// src: XBOX_PDB 0x00cb17e0
int FUN_00cb17e0_cls::hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_getMemSize()
{
    return m_iPairCount * 8 + 8;
}

struct hkMapOperatorsCB19
{
    static unsigned hash(unsigned long key, unsigned long mod)
    {
        return unsigned((key >> 4) * 2654435761U) & mod;
    }
    static void invalidate(unsigned long& key)
    {
        key = unsigned long(-1);
    }
    static bool isValid(unsigned long key)
    {
        return key != unsigned long(-1);
    }
};

class hkMapBaseCB19
{
  public:
    // hkMapBase<KEY,VAL>::Pair (Havok hkMap.h: key, val); renamed so it does not take include/Pair.h's name
    struct KeyValue
    {
        unsigned long key;
        unsigned long val;
    };

    KeyValue* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void RemoveEntry(void* it) throw();
};

// Removes the map entry at the given slot, invalidates its key, and shifts later entries back to fill the gap.
// @fnv 0x00cb19b0
void hkMapBaseCB19::RemoveEntry(void* it) throw()
{
    typedef hkMapOperatorsCB19 OPS;
    unsigned i = unsigned(unsigned long(it));

    --m_iCapacityFlags;
    OPS::invalidate(m_kPrimitiveElement[i].key);

    unsigned lo = (i + m_iPairCount) & m_iPairCount;
    while (OPS::isValid(m_kPrimitiveElement[lo].key))
    {
        lo = (lo + m_iPairCount) & m_iPairCount;
    }
    lo = (lo + 1) & m_iPairCount;

    unsigned empty = i;

    for (i = (i + 1) & m_iPairCount; OPS::isValid(m_kPrimitiveElement[i].key); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = OPS::hash(m_kPrimitiveElement[i].key, m_iPairCount);

        if ((i >= lo) && (hash > empty))
        {
            continue;
        }
        else if ((i < empty) && (hash > empty || hash <= i))
        {
            continue;
        }
        else if (hash > empty && hash < lo)
        {
            continue;
        }
        m_kPrimitiveElement[empty].key = m_kPrimitiveElement[i].key;
        m_kPrimitiveElement[empty].val = m_kPrimitiveElement[i].val;
        OPS::invalidate(m_kPrimitiveElement[i].key);
        empty = i;
    }
}

struct CB1A90Argument
{
    virtual void Dummy0();
    virtual void Dummy1();
    virtual void Process(int data, int size);
};
struct CB1A90Owner
{
    int data;
    int flags;
    int count;
    void ResetEntries();
    void ProcessArgument(CB1A90Argument* argument);
};
// Calls ResetEntries, then if the high flag bit is clear, passes data and (count + 1) << 3 to argument->Process.
// @fnv 0x00cb1a90
void CB1A90Owner::ProcessArgument(CB1A90Argument* argument)
{
    ResetEntries();
    if (!(flags & 0x80000000))
    {
        argument->Process(data, (count + 1) << 3);
    }
}

struct hkMapPairCB1E
{
    __int64 m_key;
    int m_val;
    int m_val2;
};

class hkMapCB1E
{
  public:
    hkMapPairCB1E* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ProcessEntries_00cb1e00();
};

// @fnv 0x00cb1e00
// src: GUESS 0x00cb1e00 (confidence: low)
void hkMapCB1E::ProcessEntries_00cb1e00()
{
    int n = m_iPairCount + 1;
    for (int i = 0; i < n; i++)
    {
        m_kPrimitiveElement[i].m_key = -1;
    }
    m_iCapacityFlags &= 0x80000000;
}

struct FUN_00cb1ac0_Obj
{
    void ResizeAndRehash(int a1, int a2);
};

struct FUN_00cb1fe0_t
{
    void EnsureCapacity(int a1, int n);
};

// @fnv 0x00cb1fe0
void FUN_00cb1fe0_t::EnsureCapacity(int a1, int n)
{
    int iWantedSize = n * 2;
    int size = 8;
    while (size < iWantedSize)
    {
        size += size;
    }
    ((FUN_00cb1ac0_Obj*)this)->ResizeAndRehash(a1, size);
}

class FUN_00cb2000_cls
{
  public:
    int m_00;
    int m_04;
    int m_pFreeList;

    int hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(int iArg0, int iArg1);
    void hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_remove(int iCount);
    int ProcessAndReturnValue_00cb2000(int iArg0, int iArg1);
};

// @fnv 0x00cb2000
// src: GUESS 0x00cb2000 (confidence: low)
int FUN_00cb2000_cls::ProcessAndReturnValue_00cb2000(int iArg0, int iArg1)
{
    int iCount = hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(iArg0, iArg1);
    if (iCount <= m_pFreeList)
    {
        hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_remove(iCount);
        return 0;
    }
    return 1;
}

struct hkMapPairCB18
{
    unsigned int key;
    unsigned int val;
};

class FUN_00cb1830
{
  public:
    hkMapPairCB18* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    FUN_00cb1830(void* ptr, unsigned int sizeInBytes);
};

// @fnv 0x00cb1830
FUN_00cb1830::FUN_00cb1830(void* apElements, unsigned int sizeInBytes)
{
    int maxKeys = sizeInBytes / sizeof(hkMapPairCB18);
    m_kPrimitiveElement = static_cast<hkMapPairCB18*>(apElements);
    m_iCapacityFlags = 0x80000000;
    m_iPairCount = maxKeys - 1;
    for (int i = 0; i < maxKeys; i++)
    {
        m_kPrimitiveElement[i].key = 0xffffffff;
    }
}

namespace fnv_00cb1870 {
class hkMemoryAllocatorCB18;

struct hkMapPairCB18
{
    unsigned int key;
    unsigned int val;
};

class hkMapBaseCB18
{
  public:
    hkMapPairCB18* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ResizeAndRehash(hkMemoryAllocatorCB18& alloc, int newHashMod);
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocatorCB18& alloc, unsigned int key, unsigned int val);
};

// Inserts or updates a key/val pair in the hash map, resizing if needed, and returns 1 if the key was new.
// @fnv 0x00cb1870
// src: XBOX_PDB 0x00cb1870
int hkMapBaseCB18::hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocatorCB18& alloc, unsigned int key, unsigned int val)
{
    if ((m_iCapacityFlags & 0x7fffffff) * 2 > m_iPairCount)
        ResizeAndRehash(alloc, m_iPairCount + m_iPairCount + 2);
    unsigned int i;
    int isNewKey = 1;
    for (i = ((key >> 4) * 2654435761U) & m_iPairCount; m_kPrimitiveElement[i].key != (unsigned int)-1;
         i = (i + 1) & m_iPairCount)
    {
        if (m_kPrimitiveElement[i].key == key)
        {
            isNewKey = 0;
            break;
        }
    }
    m_iCapacityFlags += isNewKey;
    m_kPrimitiveElement[i].key = key;
    m_kPrimitiveElement[i].val = val;
    return isNewKey;
}
}  // namespace fnv_00cb1870

struct Allocator;
struct EdgeEntry
{
    int key;
    int value;
};
struct EdgeMap
{
    EdgeEntry* unk00;
    int unk04;
    int unk08;
    void EnsureCapacity(Allocator& allocator, int count);
    int FindSlot(int key);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator& allocator, int key, int value);
    void ProcessArgument(Allocator& allocator);
    void Object_DoNothing();
    int first() const
    {
        int i;
        for (i = 0; i <= unk08; ++i)
        {
            if (unk00[i].key != -1)
                break;
        }
        return i;
    }
    int next(int i) const
    {
        for (++i; i <= unk08; ++i)
        {
            if (unk00[i].key != -1)
                break;
        }
        return i;
    }
};
struct Manager
{
    int unk00, unk04, unk08, unk0c;
    Allocator* unk10;
    Allocator& heap()
    {
        return *unk10;
    }
};
Manager* __cdecl hkMemoryRouter_getInstance();
struct Target
{
    int unk00, unk04;
    unsigned short* unk08;
    int unk0c, unk10;
    unsigned char* unk14;
    int unk18;
    bool* hkpConvexVerticesConnectivity_isClosed(bool* out);
};
// Checks that every edge in the vertex list appears exactly twice with opposite orientation, returning true only when all edge keys have value 3.
// @fnv 0x00e48e80
// src: HAVOK_LIB 0x00e48e80
bool* Target::hkpConvexVerticesConnectivity_isClosed(bool* apResult)
{
    EdgeMap edgeMap = {0, 0, -1};
    Allocator& allocator = hkMemoryRouter_getInstance()->heap();
    edgeMap.EnsureCapacity(allocator, 0);
    int count = unk18;
    int iVertexOffset = 0;
    for (int i = 0; i < count; ++i)
    {
        int n = unk14[i];
        unsigned short* vertices = &unk08[iVertexOffset];
        int iPrevVertex = vertices[n - 1];
        for (int j = 0; j < n; ++j)
        {
            int iCurrVertex = vertices[j];
            unsigned int key;
            if (iPrevVertex < iCurrVertex)
                key = (static_cast<unsigned int>(iPrevVertex) << 16) | iCurrVertex;
            else
                key = (static_cast<unsigned int>(iCurrVertex) << 16) | iPrevVertex;
            int iOrientation = 1 + (iPrevVertex < iCurrVertex);
            int keyPlus = key + 1;
            int index = edgeMap.FindSlot(keyPlus);
            if (index <= edgeMap.unk08)
            {
                int value = edgeMap.unk00[index].value;
                if (value & iOrientation)
                {
                    *apResult = false;
                    edgeMap.ProcessArgument(hkMemoryRouter_getInstance()->heap());
                    edgeMap.Object_DoNothing();
                    return apResult;
                }
                edgeMap.unk00[index].value = value | iOrientation;
            }
            else
            {
                Allocator& allocator = hkMemoryRouter_getInstance()->heap();
                edgeMap.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(allocator, keyPlus, iOrientation);
            }
            iPrevVertex = iCurrVertex;
        }
        iVertexOffset += n;
    }
    for (int index = edgeMap.first(); index <= edgeMap.unk08; index = edgeMap.next(index))
    {
        if (edgeMap.unk00[index].value != 3)
        {
            *apResult = false;
            edgeMap.ProcessArgument(hkMemoryRouter_getInstance()->heap());
            edgeMap.Object_DoNothing();
            return apResult;
        }
    }
    *apResult = true;
    edgeMap.ProcessArgument(hkMemoryRouter_getInstance()->heap());
    edgeMap.Object_DoNothing();
    return apResult;
}

typedef unsigned __int64 hkUint64CB1C;

struct MapOpsCB1C
{
    static inline unsigned hash(hkUint64CB1C key, unsigned mod)
    {
        return (unsigned)(((unsigned)key >> 4) * 0x9e3779b1u) & mod;
    }
    static inline bool isValid(hkUint64CB1C key)
    {
        return key != hkUint64CB1C(-1);
    }
    static inline bool equal(hkUint64CB1C key0, hkUint64CB1C key1)
    {
        return key0 == key1;
    }
};

struct MapCB1C
{
    struct KeyValue
    {
        hkUint64CB1C key;
        hkUint64CB1C val;
    };
    KeyValue* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    hkUint64CB1C hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(hkUint64CB1C key, hkUint64CB1C def) const;
};

// Looks up a key in the primitive element array and returns its value, or def when the key is not present.
// @fnv 0x00cb1cb0
// src: HAVOK_LIB 0x00cb1cb0
hkUint64CB1C MapCB1C::hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(hkUint64CB1C key, hkUint64CB1C def) const
{
    typedef MapOpsCB1C OPS;
    if (m_iPairCount > 0)
    {
        for (unsigned i = OPS::hash(key, m_iPairCount); OPS::isValid(m_kPrimitiveElement[i].key);
             i = (i + 1) & m_iPairCount)
        {
            if (OPS::equal(m_kPrimitiveElement[i].key, key))
            {
                return m_kPrimitiveElement[i].val;
            }
        }
    }
    return def;
}

struct hkMapOperatorsU64
{
    static unsigned hash(unsigned __int64 key, unsigned mod)
    {
        return unsigned((unsigned(key) >> 4) * 2654435761U) & mod;
    }
    static void invalidate(unsigned __int64& key)
    {
        key = (unsigned __int64)(-1);
    }
    static bool isValid(unsigned __int64 key)
    {
        return key != (unsigned __int64)(-1);
    }
};

class hkMapBaseU64
{
  public:
    struct KeyValue
    {
        unsigned __int64 key;
        unsigned __int64 val;
    };

    KeyValue* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_remove(unsigned it);
};

// Invalidates the entry at index it and rehashes subsequent entries to close the gap in the open-addressed map.
// @fnv 0x00cb1d20
// src: XBOX_PDB 0x00cb1d20
void hkMapBaseU64::hkMapBase_unsigned_int64_unsigned_int64_hkMapOperations_unsigned_int64_remove(unsigned aiIndex)
{
    unsigned i = aiIndex;
    --m_iCapacityFlags;
    hkMapOperatorsU64::invalidate(m_kPrimitiveElement[i].key);

    unsigned lo = (i + m_iPairCount) & m_iPairCount;
    while (hkMapOperatorsU64::isValid(m_kPrimitiveElement[lo].key))
    {
        lo = (lo + m_iPairCount) & m_iPairCount;
    }
    lo = (lo + 1) & m_iPairCount;

    unsigned empty = i;

    for (i = (i + 1) & m_iPairCount; hkMapOperatorsU64::isValid(m_kPrimitiveElement[i].key); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = hkMapOperatorsU64::hash(m_kPrimitiveElement[i].key, m_iPairCount);

        if ((i >= lo) && (hash > empty))
        {
            continue;
        }
        else if ((i < empty) && (hash > empty || hash <= i))
        {
            continue;
        }
        else if (hash > empty && hash < lo)
        {
            continue;
        }

        m_kPrimitiveElement[empty].key = m_kPrimitiveElement[i].key;
        m_kPrimitiveElement[empty].val = m_kPrimitiveElement[i].val;
        hkMapOperatorsU64::invalidate(m_kPrimitiveElement[i].key);
        empty = i;
    }
}

struct Allocator_cb1e
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct MapPair_cb1e
{
    unsigned __int64 key;
    unsigned __int64 val;
};

class MapBase_cb1e
{
  public:
    MapPair_cb1e* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void InsertKeyValue(Allocator_cb1e& alloc, unsigned __int64 key, unsigned __int64 val);
    void hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_resizeTable(Allocator_cb1e& alloc, int newcap);
};

// Reallocates the pair array to newcap (min 8), reinserts old pairs, and frees the old block unless the high bit of m_iCapacityFlags was set.
// @fnv 0x00cb1e70
// src: HAVOK_LIB 0x00cb1e70
void MapBase_cb1e::hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_resizeTable(Allocator_cb1e& alloc, int aiNewCapacity)
{
    if (aiNewCapacity <= 8)
        aiNewCapacity = 8;
    int iOldCapacity = m_iPairCount + 1;
    int dontDeallocate = m_iCapacityFlags & 0x80000000;
    MapPair_cb1e* oldelem = m_kPrimitiveElement;
    m_kPrimitiveElement = (MapPair_cb1e*)alloc.AllocateMemoryBlock(sizeof(MapPair_cb1e) * aiNewCapacity);
    for (int i = 0; i < aiNewCapacity; ++i)
        m_kPrimitiveElement[i].key = (unsigned __int64)-1;
    m_iCapacityFlags = 0;
    m_iPairCount = aiNewCapacity - 1;
    for (int i = 0; i < iOldCapacity; ++i)
    {
        if (oldelem[i].key != (unsigned __int64)-1)
            InsertKeyValue(alloc, oldelem[i].key, oldelem[i].val);
    }
    if (dontDeallocate == 0)
        alloc.ReleaseBlock(oldelem, sizeof(MapPair_cb1e) * iOldCapacity);
}

struct hkMemoryAllocatorCB1F;

struct hkMapOperationsCB1F
{
    static unsigned hash(unsigned int key, unsigned mod)
    {
        return (unsigned(key) >> 4) * 2654435761U & mod;
    }
    static bool equal(unsigned int keyCur, unsigned int keyValue)
    {
        return keyCur == keyValue;
    }
    static bool isValid(unsigned int key)
    {
        return key != unsigned(-1);
    }
};

struct hkMapPairCB1F
{
    unsigned int key;
    unsigned int val;
};

class hkMapBaseCB1F
{
  public:
    void ResizeAndRehash(hkMemoryAllocatorCB1F& alloc, int newcap);
    int InsertKeyIfAbsent(hkMemoryAllocatorCB1F& alloc, unsigned int key, unsigned int val);

    hkMapPairCB1F* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};

// Grows the table if over half full, adds key/val if key is absent, and returns the key's slot index.
// @fnv 0x00cb1f40
// src: GUESS 0x00cb1f40 (confidence: medium)
int hkMapBaseCB1F::InsertKeyIfAbsent(hkMemoryAllocatorCB1F& alloc, unsigned int key, unsigned int uiValue)
{
    {
        int numElems = m_iCapacityFlags & static_cast<int>(0x7fffffff);
        if ((numElems + numElems) > m_iPairCount)
        {
            ResizeAndRehash(alloc, m_iPairCount + m_iPairCount + 2);
        }
    }

    unsigned i;
    for (i = hkMapOperationsCB1F::hash(key, m_iPairCount); !hkMapOperationsCB1F::equal(m_kPrimitiveElement[i].key, key);
         i = (i + 1) & m_iPairCount)
    {
        if (!hkMapOperationsCB1F::isValid(m_kPrimitiveElement[i].key))
        {
            m_kPrimitiveElement[i].key = key;
            m_kPrimitiveElement[i].val = uiValue;
            m_iCapacityFlags++;
            return i;
        }
    }
    return i;
}

// Hashes key into the open-addressing table and linearly probes for a matching entry, returning its slot index or a not-found value.
// @fnv 0x00cb18f0
int FUN_00cb18f0_t::FindSlot(int key)
{
    int mod = m_iPairCount;
    if (mod > 0)
    {
        int* table = (int*)m_uiStandInValue;
        unsigned int index = ((unsigned int)key >> 4) * 0x9e3779b1u & (unsigned int)mod;
        int value = table[index * 2];
        if (value != -1)
        {
            do
            {
                if (value == key)
                    return (int)index;
                index = (index + 1) & (unsigned int)mod;
                value = table[index * 2];
            } while (value != -1);
        }
    }
    return mod + 1;
}
