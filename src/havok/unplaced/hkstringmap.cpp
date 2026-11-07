#include "../../../include/hkMemoryRouter.h"
#include "../../../include/hkArray.h"
#include "../../../include/hkBool.h"
#include "../../../include/hkMemoryAllocator.h"



// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d87430_class
{
    int* m_p;
    int m_kPointB;
    int m_iThirdValue;
    int GetEntry(int idx);
};

// @fnv 0x00d87430
int FUN_00d87430_class::GetEntry(int idx)
{
    return m_p[m_iThirdValue + idx + 1];
}

struct FUN_00d87440_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int __thiscall hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int a);
};
// @fnv 0x00d87440
// src: XBOX_PDB 0x00d87440
int __thiscall FUN_00d87440_Class::hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int aiIndex)
{
    return *(int*)((char*)m_iWordAt00 + aiIndex * 4 + m_8 * 8 + 8);
}

struct SlotBitmap
{
    unsigned long* m_kPrimitiveElement;
    int m_auiShapeKeys;
    int m_iPairCount;
    int FindNextUsedSlot(int i);
};

// @fnv 0x00d87480
int SlotBitmap::FindNextUsedSlot(int aiStartIndex)
{
    ++aiStartIndex;
    if (aiStartIndex <= m_iPairCount)
    {
        unsigned long* p = m_kPrimitiveElement + aiStartIndex;
        do
        {
            if (*p != 0xffffffff)
                break;
            ++aiStartIndex;
            p += 1;
        } while (aiStartIndex <= m_iPairCount);
    }
    return aiStartIndex;
}

struct FUN_00d874b0_class
{
    int m_iWordAt00;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;
    char* SetBoolFromThreshold(char* p, int value);
};

// @fnv 0x00d874b0
char* FUN_00d874b0_class::SetBoolFromThreshold(char* pbOut, int value)
{
    *pbOut = value <= m_cByteAtOffset2;
    return pbOut;
}

struct FUN_00d87460_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void __thiscall SetElement(int idx, int val);
};

// @fnv 0x00d87460
void __thiscall FUN_00d87460_class::SetElement(int aiIndex, int aiValue)
{
    *(int*)((int*)m_iWordAt00 + m_8 * 2 + 2 + aiIndex) = aiValue;
}

struct FUN_00d87760_class
{
    void** m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    void ClearEntries();
};

// @fnv 0x00d87760
void FUN_00d87760_class::ClearEntries()
{
    int i;
    for (i = 0; i < m_iPairCount + 1; i++)
        ((unsigned long*)m_kPrimitiveElement)[i] = 0xffffffff;
    m_iCapacityFlags = 0;
}

hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00d877d0_class
{
    unsigned long* m_kPrimitiveElement;
    int m_auiShapeKeys;
    int m_iPairCount;
    void FreeBuffer();
};

// @fnv 0x00d877d0
void FUN_00d877d0_class::FreeBuffer()
{
    hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
    reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(m_kPrimitiveElement, 12 * (m_iPairCount + 1));
}

struct FUN_00d87820_Class
{
    char* SetBoolFromThreshold(char* p, int value);
    int FindStringKey(int);
    void ProcessEntries_00d876a0(int);
    int ProcessAndReturnValue_00d87820(int a);
};

// @fnv 0x00d87820
// src: GUESS 0x00d87820 (confidence: low)
int FUN_00d87820_Class::ProcessAndReturnValue_00d87820(int a)
{
    int v = FindStringKey(a);
    char r;
    if (*SetBoolFromThreshold(&r, v))
    {
        ProcessEntries_00d876a0(v);
        return 0;
    }
    return 1;
}

namespace fnv_00dc8080 {
struct FUN_00dc7750_class
{
    void ClearWorldContainers();
};

extern int DAT_010d7510;
extern int _DAT_0102e388;

hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00dc8080_class
{
    void* m_vptr;
    int m_iWordAt04;
    FUN_00dc7750_class* m_8;

    void ReleaseStorage_00dc8080();
};

// src: GUESS 0x00dc8080 (confidence: medium)
void FUN_00dc8080_class::ReleaseStorage_00dc8080()
{
    FUN_00dc7750_class* object = m_8;
    m_vptr = &DAT_010d7510;

    if (object)
    {
        object->ClearWorldContainers();

        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        hkMemoryAllocator* allocator =
            reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
        allocator->blockFree(object, 0x88);
    }

    m_vptr = &_DAT_0102e388;
}
}  // namespace fnv_00dc8080

int __cdecl hkString_strCmp(const char*, const char*);

static __forceinline int stringHash(const char* str)
{
    int hash = 0;
    if (*str)
    {
        const char* p = str;
        do
        {
            hash = 31 * hash + *p;
            ++p;
        } while (*p);
    }
    return hash & 0x7fffffff;
}

// @fnv 0x00d87580
int FUN_00d87820_Class::FindStringKey(int key)
{
    const char* str = (const char*)key;
    SlotBitmap* table = (SlotBitmap*)this;
    int hash = stringHash(str);
    unsigned int slot = hash & table->m_iPairCount;
    while (table->m_kPrimitiveElement[slot] != 0xffffffffu)
    {
        if (table->m_kPrimitiveElement[slot] == (unsigned int)hash &&
            hkString_strCmp(str, (const char*)table->m_kPrimitiveElement[table->m_iPairCount + slot + 1]) == 0)
            return slot;
        slot = (slot + 1) & table->m_iPairCount;
    }
    return table->m_iPairCount + 1;
}

hkMemoryRouter* hkMemoryRouter_getInstance();
extern "C" void* hkString_memSet(void*, int, unsigned int);

struct FUN_00d87790
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    FUN_00d87790(int a);
};

// @fnv 0x00d87790
FUN_00d87790::FUN_00d87790(int a)
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    void* p = reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockAlloc(0xc0);
    m_kPrimitiveElement = p;
    hkString_memSet(p, 0xff, 0x40);
    m_iCapacityFlags = 0;
    m_iPairCount = 0xf;
}

class hkObjectD878
{
  public:
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_get(int a, int* piValue);
    int GetValue(int a, int b);
};

// @fnv 0x00d87800
int hkObjectD878::GetValue(int a, int aiDefault)
{
    int iValue = aiDefault;
    hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_get(a, &iValue);
    return iValue;
}

class hkStringMapD876
{
  public:
    int unk00;
    int unk04;
    int unk08;

    int FindStringKey(const char* key);
    hkBool SetBoolFromThreshold(int it);
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int it);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* key, int val);
    int GetOrSetInt(const char* key, int def);
};

// Looks up key; if found returns its value, otherwise stores def under key and returns def.
// @fnv 0x00d87600
int hkStringMapD876::GetOrSetInt(const char* key, int iDefault)
{
    int it = FindStringKey(key);
    if (SetBoolFromThreshold(it))
        return hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(it);
    hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(key, iDefault);
    return iDefault;
}

class hkStringMapD8765
{
  public:
    int unk00;
    int unk04;
    int unk08;

    int FindStringKey(const char* key);
    hkBool SetBoolFromThreshold(int it);
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int it);
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_get(const char* key, int* out);
};

// Looks up key; if found writes its value to out and returns 0, otherwise returns 1.
// @fnv 0x00d87650
// src: XBOX_PDB 0x00d87650
int hkStringMapD8765::hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_get(const char* key, int* piOut)
{
    int it = FindStringKey(key);
    if (SetBoolFromThreshold(it))
    {
        *piOut = hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(it);
        return 0;
    }
    return 1;
}

namespace fnvc_adapt {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

class FUN_00d874d0_s
{
  public:
    unsigned int* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* pcKey, int iValue);
    void hkCachedHashMap_struct_hkStringMapOperations_struct_hkContainerHeapAllocator_resizeTable(int iNewCap);
};

// Grows the primitive element array to iNewCap, re-inserts existing pairs via FUN_00d874d0, and releases the old block.
// @fnv 0x00d87860
// src: HAVOK_LIB 0x00d87860
void FUN_00d874d0_s::hkCachedHashMap_struct_hkStringMapOperations_struct_hkContainerHeapAllocator_resizeTable(int iNewCap)
{
    int iOldCap = m_iPairCount + 1;
    unsigned int* puiOldElements = m_kPrimitiveElement;
    hkMemoryAllocator& kAlloc = reinterpret_cast<hkMemoryAllocator&>(fnvc_adapt::hkMemoryRouter_getInstance().heap());
    m_kPrimitiveElement = (unsigned int*)kAlloc.blockAlloc(iNewCap * 3 * sizeof(unsigned int));
    hkString_memSet(m_kPrimitiveElement, 0xff, iNewCap * sizeof(unsigned int));
    m_iCapacityFlags = 0;
    m_iPairCount = iNewCap - 1;

    for (int i = 0; i < iOldCap; i++)
    {
        if (puiOldElements[i] != 0xffffffff)
            hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert((const char*)puiOldElements[iOldCap + i], puiOldElements[i + 2 * iOldCap]);
    }

    kAlloc.blockFree(puiOldElements, iOldCap * 3 * sizeof(unsigned int));
}

struct S00d876a0_Map
{
    unsigned long* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ProcessEntries_00d876a0(int it);
};

// Removes the element at index it from the open-addressing hash table, compacting remaining entries to fill the gap.
// @fnv 0x00d876a0
// src: GUESS 0x00d876a0 (confidence: low)
void S00d876a0_Map::ProcessEntries_00d876a0(int aiIndex)
{
    unsigned i = aiIndex;

    // remove it
    --m_iCapacityFlags;
    m_kPrimitiveElement[i] = unsigned(-1);

    // find lowest element of this unbroken run
    unsigned lo = (i + m_iPairCount) & m_iPairCount;
    while (m_kPrimitiveElement[lo] != unsigned(-1))
    {
        lo = (lo + m_iPairCount) & m_iPairCount;
    }
    lo = (lo + 1) & m_iPairCount;

    // the slot which has become empty
    unsigned empty = i;

    // shift up, closing any gaps we find
    for (i = (i + 1) & m_iPairCount; m_kPrimitiveElement[i] != unsigned(-1); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = m_kPrimitiveElement[i] & m_iPairCount;

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
        m_kPrimitiveElement[empty] = m_kPrimitiveElement[i];
        m_kPrimitiveElement[m_iPairCount + 1 + empty] = m_kPrimitiveElement[m_iPairCount + 1 + i];
        m_kPrimitiveElement[2 * (m_iPairCount + 1) + empty] = m_kPrimitiveElement[2 * (m_iPairCount + 1) + i];
        m_kPrimitiveElement[i] = unsigned(-1);
        empty = i;
    }
}

int __cdecl hkString_strCmp(const char* pcA, const char* pcB) throw();

class hkStringMapD874
{
  public:
    unsigned long* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    static __forceinline int hash(const char* pcKey)
    {
        int h = 0;
        for (int i = 0; pcKey[i]; i++)
            h = 31 * h + pcKey[i];
        return h & 0x7fffffff;
    }

    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* pcKey, int iValue);
    void hkCachedHashMap_struct_hkStringMapOperations_struct_hkContainerHeapAllocator_resizeTable(int iNewCap);
};

// Inserts a key-value pair into the hash map, growing the table if the load factor exceeds half capacity.
// @fnv 0x00d874d0
// src: XBOX_PDB 0x00d874d0
void hkStringMapD874::hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* pcKey, int iValue)
{
    int uiHash = hash(pcKey);
    if (m_iCapacityFlags * 2 > m_iPairCount)
        hkCachedHashMap_struct_hkStringMapOperations_struct_hkContainerHeapAllocator_resizeTable(m_iPairCount + m_iPairCount + 2);

    int i = uiHash & m_iPairCount;
    while (m_kPrimitiveElement[i] != 0xffffffffu)
    {
        if (m_kPrimitiveElement[i] == uiHash)
        {
            const char* pcStored = (const char*)m_kPrimitiveElement[m_iPairCount + i + 1];
            if (hkString_strCmp(pcKey, pcStored) == 0)
                goto KEY_FOUND;
        }
        i = (i + 1) & m_iPairCount;
    }

    m_iCapacityFlags += 1;

KEY_FOUND:
    m_kPrimitiveElement[i] = uiHash;
    m_kPrimitiveElement[m_iPairCount + i + 1] = (unsigned long)pcKey;
    m_kPrimitiveElement[2 * m_iPairCount + 2 + i] = iValue;
}

namespace fnv_00e02800 {
namespace hkRouterE028 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

char* __cdecl hkString_strDup(const char* pcString, hkMemoryAllocator& kAlloc);

class FUN_00d87790
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int unk0C;

    FUN_00d87790(hkBool bOwnsKeys) throw();

    static void* operator new(unsigned int uiSize)
    {
        return reinterpret_cast<hkMemoryAllocator&>(hkRouterE028::hkMemoryRouter_getInstance().heap()).blockAlloc(uiSize);
    }
    static void operator delete(void* p);

    int FindStringKey(const char* pcKey);
    char* SetBoolFromThreshold(char* pcOut, int iIt);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* pcKey, int iValue);
    int GetEntry(int iIt);
    void SetElement(int iIt, int iValue);

    bool isValid(int iIt)
    {
        char cValid;
        SetBoolFromThreshold(&cValid, iIt);
        return cValid != 0;
    }
};

class StringMapE028 : public FUN_00d87790
{
  public:
    StringMapE028() throw() : FUN_00d87790(hkBool(false))
    {}
};

struct EntryE028
{
    void* m_pPointer;
    const char* m_pcName;
};

class NamedObjectsE028
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    hkArray<EntryE028> m_kEntries;
    StringMapE028* m_pkPool;

    void AddNamedPooledObject(void* pkObject, const char* pcName);
};

// Pools pcName via m_pkPool, stores a new EntryE028 with pkObject and the pooled name into m_kEntries.
// @fnv 0x00e02800
// src: GUESS 0x00e02800 (confidence: medium)
void NamedObjectsE028::AddNamedPooledObject(void* pkObject, const char* pcName)
{
    if (!m_pkPool)
        m_pkPool = new StringMapE028();
    StringMapE028* pkPool = m_pkPool;
    int iIt = pkPool->FindStringKey(pcName);
    const char* pcPooled;
    if (!pkPool->isValid(iIt))
    {
        pcPooled = hkString_strDup(pcName, reinterpret_cast<hkMemoryAllocator&>(hkRouterE028::hkMemoryRouter_getInstance().heap()));
        pkPool->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(pcPooled, 0);
    }
    else
    {
        pcPooled = (const char*)pkPool->GetEntry(iIt);
        pkPool->SetElement(iIt, 0);
    }
    EntryE028 kEntry;
    kEntry.m_pPointer = pkObject;
    kEntry.m_pcName = pcPooled;
    m_kEntries.pushBack(kEntry);
}
}  // namespace fnv_00e02800
// hkArrayUtil::_reserveMore is the 0x00c90940 growth helper used by this unit.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(fnvc_adapt::hkMemoryRouter_getInstance().heap());
}

template <typename T>
static __forceinline void constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    constructWithCopy(m_data + m_iElementCount, 1, t);
    m_iElementCount++;
}
