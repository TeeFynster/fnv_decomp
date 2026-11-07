
// src/havok/common/serialize/packfile/hkpackfiledata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/hkpackfiledata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkClass.h"


struct FUN_00cb1930_Class
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
    void* m_g;
    void* m_h;
    void* m_i;
    void* m_iUnknownValue;
    unsigned long FindValueForKey(void* key, unsigned long def);
};

struct FUN_00e05140_Class
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    unsigned long hkPackfileData_getContentsTypeName();
};
// @fnv 0x00e05140
// src: XBOX_PDB 0x00e05140
unsigned long FUN_00e05140_Class::hkPackfileData_getContentsTypeName()
{
    if (m_iThirdValue)
        return ((FUN_00cb1930_Class*)((char*)this + 0x10))->FindValueForKey(m_iThirdValue, 0);
    return 0;
}

struct hkPackFileData
{
    hkReferencedObject* m_pObject;
    void SetObject(hkReferencedObject* pObject);
};

// @fnv 0x00e05160
void hkPackFileData::SetObject(hkReferencedObject* pObject)
{
    if (pObject)
        pObject->addReference();
    if (*(hkReferencedObject**)((char*)this + 0x2c))
        (*(hkReferencedObject**)((char*)this + 0x2c))->removeReference();
    *(hkReferencedObject**)((char*)this + 0x2c) = pObject;
}

struct FUN_00e05950_class
{
    int* m_p;
    int m_auiShapeKeys;
    int m_uiItemCount;
    int FindFirstNonEmptySlot();
};

// @fnv 0x00e05950
int FUN_00e05950_class::FindFirstNonEmptySlot()
{
    int count = 0;
    if (m_uiItemCount >= 0)
    {
        int* p = m_p;
        while (count <= m_uiItemCount)
        {
            if (p[0] != -1)
                break;
            ++count;
            p = (int*)((char*)p + 8);
        }
    }
    return count;
}

void* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* a, void* b, int c);
struct UnkRet
{
    int a;
    int b;
    int c;
    int d;
    int e;
};
struct UnkHolder
{
    int x;
    int y;
    int z;
    int w;
    int* data;
    int count;
    int pad;
    int pad2;
    UnkRet* hkMemoryRouter_getInstance();
    void hkPackfileData_addImport(UnkRet* r, int v);
};
// Appends a two-int entry (r, v) to the array at this+0x58, growing it via ResizeAudioStream when full, and increments the count.
// @fnv 0x00e055a0
// src: XBOX_PDB 0x00e055a0
void UnkHolder::hkPackfileData_addImport(UnkRet* r, int v)
{
    UnkRet* slot = (UnkRet*)((char*)this + 0x58);
    UnkRet* pTemp = hkMemoryRouter_getInstance();
    if ((unsigned int)slot->b == ((unsigned int)slot->c & 0x3fffffff))
        ResizeAudioStream((void*)pTemp->e, slot, 8);
    UnkRet* p = (UnkRet*)((char*)slot->a + slot->b * 8);
    slot->b++;
    p->a = (int)r;
    p->b = v;
}

struct FUN_00e05550_Class
{
    char pad[0x4c];
    int* m_data;
    int m_uiItemCount;
    int m_pRayCursor;
    void AppendPair(int a, int b);
};

void* __cdecl _D1A0E0GetMemoryRouter();

// Appends the pair (a, b) to the array at this+0x4c, growing it via the memory router when full, and increments the count.
// @fnv 0x00e05550
void FUN_00e05550_Class::AppendPair(int aiFirst, int aiSecond)
{
    int* p = (int*)((char*)this + 0x4c);
    void* router = _D1A0E0GetMemoryRouter();
    unsigned int cap = p[2] & 0x3fffffff;
    if (p[1] == (int)cap)
        ResizeAudioStream(*(void**)((char*)router + 0x10), p, 8);
    int iIndex = p[1];
    int* slot = (int*)(p[0] + iIndex * 8);
    p[1] = iIndex + 1;
    slot[0] = aiFirst;
    slot[1] = aiSecond;
}

struct FUN_00e05250_Archive
{
    void** m_ppVirtualMethodTable;
    char m_auiShapeKeys[0x0c];
    unsigned char m_flag;
};

struct FUN_00e05250_Class
{
    char m_auiShapeKeys[0x34];
    void* m_memoryData;
    int m_memorySize;
    int m_memoryHashSize;
    void* m_chunksData;
    int m_chunksSize;
    int m_chunksHashSize;
    void* m_exportsData;
    int m_exportsSize;
    int m_exportsHashSize;
    void* m_importsData;
    int m_importsSize;
    int m_importsHashSize;

    void WriteSections(FUN_00e05250_Archive* pArchive, int unused);
};

typedef void(__thiscall* FUN_00e05250_Write)(FUN_00e05250_Archive*, int, const char*, void*, int, int);

int __cdecl _FUN_00d06f80(void* data, int size);

// @fnv 0x00e05250
void FUN_00e05250_Class::WriteSections(FUN_00e05250_Archive* pArchive, int)
{
    if ((m_memoryHashSize & 0x80000000) == 0 || pArchive->m_flag != 0)
    {
        void* data = m_memoryData;
        int size = (m_memoryHashSize & 0x3fffffff) * 4;
        int hash = _FUN_00d06f80(data, size);

        FUN_00e05250_Write write = reinterpret_cast<FUN_00e05250_Write>(pArchive->m_ppVirtualMethodTable[5]);

        write(pArchive, 3, "memory", m_memoryData, m_memorySize * 4, hash);
    }

    if ((m_chunksHashSize & 0x80000000) == 0 || pArchive->m_flag != 0)
    {
        void* data = m_chunksData;
        int size = (m_chunksHashSize & 0x3fffffff) * 12;
        int hash = _FUN_00d06f80(data, size);

        FUN_00e05250_Write write = reinterpret_cast<FUN_00e05250_Write>(pArchive->m_ppVirtualMethodTable[5]);

        write(pArchive, 3, "chunks", m_chunksData, m_chunksSize * 12, hash);
    }

    if ((m_exportsHashSize & 0x80000000) == 0 || pArchive->m_flag != 0)
    {
        void* data = m_exportsData;
        int size = (m_exportsHashSize & 0x3fffffff) * 8;
        int hash = _FUN_00d06f80(data, size);

        FUN_00e05250_Write write = reinterpret_cast<FUN_00e05250_Write>(pArchive->m_ppVirtualMethodTable[5]);

        write(pArchive, 3, "exports", m_exportsData, m_exportsSize * 8, hash);
    }

    if ((m_importsHashSize & 0x80000000) == 0 || pArchive->m_flag != 0)
    {
        void* data = m_importsData;
        int size = (m_importsHashSize & 0x3fffffff) * 8;
        int hash = _FUN_00d06f80(data, size);

        FUN_00e05250_Write write = reinterpret_cast<FUN_00e05250_Write>(pArchive->m_ppVirtualMethodTable[5]);

        write(pArchive, 3, "imports", m_importsData, m_importsSize * 8, hash);
    }
}

struct ByteSink
{
    void PutBytePair(char a, char b);
};
struct E06C20Writer
{
    void hkpMoppCodeGenerator_addCommand32(int a, void* b);
};
struct FUN_00e06800_Class
{
    void hkpMoppCodeGenerator_addCommand16(int a, void* b);
};

struct FUN_00e06d70_Class
{
    char pad[0x10];
    void* m_pWriter;
    void WriteSize(unsigned int size);
};

// @fnv 0x00e06d70
void FUN_00e06d70_Class::WriteSize(unsigned int size)
{
    void* p = m_pWriter;
    if (size < 0x100)
        ((ByteSink*)p)->PutBytePair(9, (char)size);
    else if (size < 0x10000)
        ((FUN_00e06800_Class*)p)->hkpMoppCodeGenerator_addCommand16(0xa, (void*)size);
    else
        ((E06C20Writer*)p)->hkpMoppCodeGenerator_addCommand32(0xb, (void*)size);
}

struct FUN_00e05100_cls
{
    int unk00;
    int unk04;
    int m_iValue08;
    void SetValue08(int value, int unused);
};

// @fnv 0x00e05100
// src: GUESS 0x00e05100 (confidence: medium)
void FUN_00e05100_cls::SetValue08(int value, int unused)
{
    m_iValue08 = value;
}

struct FUN_00e05240_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    bool hkPackfileData_finishedObjects();
};

// @fnv 0x00e05240
// src: XBOX_PDB 0x00e05240
bool FUN_00e05240_cls::hkPackfileData_finishedObjects()
{
    return m_20 != 0;
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void __cdecl operator delete(void*, void*) throw()
{}

template <typename T> __forceinline T min2E054(T x, T y)
{
    return x < y ? x : y;
}

template <typename T> __forceinline void copyE054(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <typename T> __forceinline void constructWithArrayE054(T* dst, int n, const T* src)
{
    for (int i = 0; i < n; i++)
        new (dst + i) T(src[i]);
}

template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
{
    const int iCapacity = getCapacity();
    if (iCapacity < n)
    {
        int iCap2 = 2 * iCapacity;
        int iNewSize = (n < iCap2) ? iCap2 : n;
        hkArrayUtil__reserve(kAlloc, this, iNewSize, sizeof(T));
    }
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>& hkArray<T, Allocator>::operator=(const hkArray<T, Allocator>& a)
{
    hkMemoryAllocator& kAlloc = ((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    const int iOldSize = this->m_iElementCount;
    int iNewSize = a.m_iElementCount;
    int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
    this->GrowArrayCapacity(kAlloc, iNewSize);
    copyE054<T>(this->m_data, a.m_data, iCopiedSize);
    constructWithArrayE054<T>(this->m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
    this->m_iElementCount = iNewSize;
    return *this;
}

// hkPackfileData's +0x4c array holds hkResource::Export (name, data), not the unrelated shared Pair.
struct PackfileExport
{
    const char* name;
    void* data;
};

// hkPackfileData's +0x58 array holds hkResource::Import (name, location), not the unrelated shared Pair.
struct PackfileImport
{
    const char* name;
    void** location;
};

class FUN_00e05410_Owner
{
  public:
    char m_pad00[0x4c];
    hkArray<PackfileExport> m_iSecondInteger;
    hkArray<PackfileImport> m_pHeadNode;

    void CopyPairArrays(hkArray<PackfileImport>& kFirstOut, hkArray<PackfileExport>& kSecondOut) const throw();
};

// @fnv 0x00e05410
void FUN_00e05410_Owner::CopyPairArrays(hkArray<PackfileImport>& kFirstOut, hkArray<PackfileExport>& kSecondOut) const
    throw()
{
    kFirstOut = m_pHeadNode;
    kSecondOut = m_iSecondInteger;
}

struct FUN_00dce8d0_class
{
    unsigned long LookupHashEntry(unsigned long uiKey, unsigned long uiDefault);
};

struct FUN_00d874d0_s
{
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* pcKey, int iValue);
};

class hkClassRegistryE055
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual const hkClass* GetClassByName(const char* pcName) const;
};

class hkFinishRegistryE055
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int RegisterLoadedObject(void* pvObject, const char* pcClassName) const;
};

struct hkPointerMapPairE055
{
    unsigned long m_uiKey;
    unsigned long m_uiCurrentValue;
};

struct hkPointerMapE055 : public FUN_00e05950_class
{
    int isValid(int iIt) const
    {
        return iIt <= m_uiItemCount;
    }
    int getNext(int iIt) const
    {
        int i = iIt;
        for (i += 1; i <= m_uiItemCount; ++i)
        {
            if (((hkPointerMapPairE055*)m_p)[i].m_uiKey != (unsigned long)-1)
                break;
        }
        return i;
    }
    unsigned long GetIteratorKey(int iIt) const
    {
        return ((hkPointerMapPairE055*)m_p)[iIt].m_uiKey;
    }
    unsigned long getValue(int iIt) const
    {
        return ((hkPointerMapPairE055*)m_p)[iIt].m_uiCurrentValue;
    }
};

// Retained locally: include/ has no hkPackfileData.h yet.
class hkPackfileData
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    void* m_pvTopLevelObject;
    int m_iUnk0c;
    hkPointerMapE055 m_kTrackedTypes;
    FUN_00d874d0_s m_kFinishedTypes;
    int m_aiUnk20[3];
    hkClassRegistryE055* m_pkClassRegistry;

    int hkPackfileData_finishedObjects();
    void* getContentsPointer(const char* pcExpectedClassName, const hkFinishRegistryE055* pkFinish);
};

// @fnv 0x00e055f0
// src: XBOX_PDB 0x00e055f0
void* hkPackfileData::getContentsPointer(const char* pcExpectedClassName, const hkFinishRegistryE055* pkFinish)
{
    if (m_pvTopLevelObject)
    {
        const char* pcTopClassName =
            (const char*)((FUN_00dce8d0_class*)&m_kTrackedTypes)->LookupHashEntry((unsigned long)m_pvTopLevelObject, 0);
        if (pcExpectedClassName)
        {
            const hkClassRegistryE055* pkRegistry = m_pkClassRegistry;
            const hkClass* pkTopClass = pkRegistry->GetClassByName(pcTopClassName);
            const hkClass* pkExpected = pkRegistry->GetClassByName(pcExpectedClassName);
            if (!pkExpected->hkClass_isSuperClass(*pkTopClass).m_cBooleanValue)
                goto fail;
        }
        if (hkPackfileData_finishedObjects() == 0 && pkFinish)
        {
            bool bFailed = false;
            for (int i = m_kTrackedTypes.FindFirstNonEmptySlot(); m_kTrackedTypes.isValid(i);
                 i = m_kTrackedTypes.getNext(i))
            {
                void* pvObject = (void*)m_kTrackedTypes.GetIteratorKey(i);
                const char* pcClassName = (const char*)m_kTrackedTypes.getValue(i);
                int iInfo = pkFinish->RegisterLoadedObject(pvObject, pcClassName);
                if (iInfo)
                    m_kFinishedTypes.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(pcClassName, iInfo);
                else
                    bFailed = true;
            }
            if (bFailed)
                goto fail;
        }
        return m_pvTopLevelObject;
    }
fail:
    return 0;
}

extern "C" const void* DAT_010ea51c;
extern int DAT_0102e388;

void* hkMemoryRouter_getInstance();
void __cdecl hkMemoryRouter_easyFree(void* heap, void* ptr);

template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    int cap = this->m_iCapacityState;
    this->m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
    {
        alloc.bufFree(this->m_data, (cap & 0x3fffffff) * sizeof(T));
    }
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}

struct Chunk
{
    void* data;
    int size;
    int unk8;
};

struct Map1Type
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    void ProcessArgument(void* heap);
    void Object_DoNothing();

    void ClearAndRelease()
    {
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        this->ProcessArgument(router->m_heap);
        this->Object_DoNothing();
    }
};

struct Map2Type
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void FreeBuffer();
};

struct FUN_00e057c0_Class
{
    const void* vtable;
    int unk04;
    int unk08;
    void* unk0c;
    Map1Type m_map1;
    Map2Type m_map2;
    hkReferencedObject* m_obj;
    int unk30;
    hkArray<void*> m_pMemoryAllocator;
    hkArray<Chunk> m_kChunks;
    hkArray<PackfileExport> m_kExports;
    hkArray<PackfileImport> m_kImports;

    void Clear();
    void ReleaseEntries_00e057c0();
};

// @fnv 0x00e057c0
// src: GUESS 0x00e057c0 (confidence: low)
void FUN_00e057c0_Class::ReleaseEntries_00e057c0()
{
    this->vtable = &DAT_010ea51c;
    this->Clear();

    int i;
    for (i = 0; i < this->m_pMemoryAllocator.m_iElementCount; ++i)
    {
        void* item = this->m_pMemoryAllocator.m_data[i];
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        hkMemoryRouter_easyFree(router->m_heap, item);
    }

    for (i = 0; i < this->m_kChunks.m_iElementCount; ++i)
    {
        int size = this->m_kChunks.m_data[i].size;
        void* data = this->m_kChunks.m_data[i].data;
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        router->m_heap->blockFree(data, size);
    }

    void* unk0c = this->unk0c;
    hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryRouter_easyFree(router->m_heap, unk0c);

    hkMemoryRouter* r1 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    this->m_kImports._clearAndDeallocate(*r1->m_heap);

    hkMemoryRouter* r2 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    this->m_kExports._clearAndDeallocate(*r2->m_heap);

    hkMemoryRouter* r3 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    this->m_kChunks._clearAndDeallocate(*r3->m_heap);

    hkMemoryRouter* r4 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    this->m_pMemoryAllocator._clearAndDeallocate(*r4->m_heap);

    if (this->m_obj)
    {
        this->m_obj->removeReference();
    }
    this->m_obj = 0;

    this->m_map2.FreeBuffer();

    this->m_map1.ClearAndRelease();

    this->vtable = (const void*)&DAT_0102e388;
}

class FUN_00e057c0
{
  public:
    ~FUN_00e057c0() throw();
};

class hkObje05970 : public FUN_00e057c0
{
  public:
    hkObje05970* FUN_00e05970(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())
            ->heap()
            .blockFree(p, static_cast<hkObje05970*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

// Calls the base destructor, then deletes this object via hkObje05970::operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00e05970
hkObje05970* hkObje05970::FUN_00e05970(unsigned int uiFlags) throw()
{
    this->FUN_00e057c0::~FUN_00e057c0();
    if (uiFlags & 1)
        hkObje05970::operator delete(this);
    return this;
}

void* hkMemoryRouter_getInstance();
void __cdecl hkMemoryRouter_easyFree(void* heap, void* ptr);
char* __cdecl hkString_strDup_00cb1410(const char* src);
inline void Crux53_FreeName(char* existing)
{
    hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryRouter_easyFree(router->m_heap, existing);
}
struct Crux53_Named
{
    int unk00, unk04, unk08;
    char* name;
    void SetName(const char* newName);
};
// Frees the current name string and assigns the result of FUN_00cb1410(newName).
// @fnv 0x00e05110
void Crux53_Named::SetName(const char* newName)
{
    Crux53_FreeName(name);
    name = hkString_strDup_00cb1410(newName);
}

template <int SIZE> __forceinline void memCpyOneAlignedE051(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

template <typename T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        memCpyOneAlignedE051<sizeof(T)>(m_data + index, m_data + m_iElementCount);
}

class hkListenerE051
{
  public:
    int unk00[19];
    hkArray<PackfileExport> m_entries;

    void hkPackfileData_removeExport(int key);
};

// Removes exports whose data pointer matches key; these 8-byte entries are not the 12-byte hkEntry type.
// @fnv 0x00e05190
// src: XBOX_PDB 0x00e05190
void hkListenerE051::hkPackfileData_removeExport(int key)
{
    for (int i = m_entries.m_iElementCount - 1; i >= 0; i--)
    {
        if (m_entries.m_data[i].data == (void*)key)
            m_entries.removeAt(i);
    }
}

namespace fnv_00e051e0 {
class FUN_00e051e0_C
{
  public:
    char unk00[0x58];
    hkArray<PackfileImport> m_entries;

    void RemoveEntry(void* pValue);
};

// Finds the import whose location equals pValue and removes it from the array.
// @fnv 0x00e051e0
void FUN_00e051e0_C::RemoveEntry(void* pValue)
{
    for (int i = m_entries.m_iElementCount - 1; i >= 0; i--)
    {
        if (m_entries.m_data[i].location == (void**)pValue)
        {
            m_entries.removeAt(i);
            return;
        }
    }
}
}  // namespace fnv_00e051e0

struct FUN_00e05370_Entry
{
    int id;
    void* key;
};
struct FUN_00e05370_Callback
{
    int unknown0;
    int unknown4;
    void(__cdecl* invoke)(int);
};
struct FUN_00e05370_List
{
    FUN_00e05370_Entry* data;
    int capacity;
    int lastIndex;
    void ResetEntries();
};
struct FUN_00e05370_Map
{
    int unknown0;
    int count;
    int unknown8;
    int unknownC;
    int unknown10;
    void* table;
    FUN_00e05370_Callback* GetValue(void* key, int defaultValue);
    void ClearEntries();
};
struct FUN_00e05370_Class
{
    int unknown0;
    int unknown4;
    int field08;
    int unknownC;
    FUN_00e05370_List list;
    FUN_00e05370_Map map;
    void Clear();
};
// Invokes each registered callback with its entry id, then resets field08 and clears the list and map.
// @fnv 0x00e05370
void FUN_00e05370_Class::Clear()
{
    if (map.table && map.count > 0)
    {
        int limit = list.lastIndex;
        int index = 0;
        while (index <= limit && list.data[index].id == -1)
            ++index;
        if (index <= list.lastIndex)
        {
            do
            {
                void* key = list.data[index].key;
                FUN_00e05370_Callback* pCallback = map.GetValue(key, 0);
                if (pCallback && pCallback->invoke)
                    pCallback->invoke(list.data[index].id);
                int next = index + 1;
                while (next <= list.lastIndex && list.data[next].id == -1)
                    ++next;
                index = next;
            } while (index <= list.lastIndex);
        }
    }
    field08 = 0;
    list.ResetEntries();
    map.ClearEntries();
}

struct FUN_00cb1fe0_Class
{
    int __thiscall EnsureCapacity(void* arg1, int arg2);
};

struct FUN_00d87790_Class
{
    void __thiscall FUN_00d87790(int arg);
};

struct FUN_01268B08_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};

extern "C" const void* DAT_010ea51c;
extern FUN_01268B08_Obj* DAT_01268b08;

struct S00e05700_Arr
{
    void* m_data;
    int m_iElementCount;
    int m_capFlags;

    void reset(int capFlags)
    {
        m_data = 0;
        m_iElementCount = 0;
        m_capFlags = capFlags;
    }
};

struct S00e05700_Class
{
    const void* unk00;
    char unk04;
    char unk05;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    hkReferencedObject* unk2C;
    int unk30;
    S00e05700_Arr arr34;
    S00e05700_Arr arr40;
    S00e05700_Arr arr4C;
    S00e05700_Arr arr58;

    S00e05700_Class* __thiscall hkPackfileData_hkPackfileData();
};

// Initializes fields, resets four arrays, and assigns DAT_01268b08->vf10()'s result to unk2C.
// @fnv 0x00e05700
// src: XBOX_PDB 0x00e05700
S00e05700_Class* __thiscall S00e05700_Class::hkPackfileData_hkPackfileData()
{
    int zero = 0;

    unk06 = 1;
    unk00 = reinterpret_cast<const void*>(&DAT_010ea51c);
    unk08 = zero;
    unk0C = zero;

    int* first = &unk10;
    first[0] = zero;
    first[1] = zero;
    first[2] = -1;

    void* audio = hkMemoryRouter_getInstance();
    void* audioObject = *reinterpret_cast<void**>(reinterpret_cast<char*>(audio) + 0x10);

    reinterpret_cast<FUN_00cb1fe0_Class*>(first)->EnsureCapacity(audioObject, zero);

    unsigned char flag = static_cast<unsigned char>(zero);
    int flagArg = *reinterpret_cast<int*>(&flag);
    reinterpret_cast<FUN_00d87790_Class*>(reinterpret_cast<char*>(this) + 0x1C)->FUN_00d87790(flagArg);

    unk2C = 0;
    unk30 = 1;
    arr34.reset(static_cast<int>(0x80000000u));
    arr40.reset(static_cast<int>(0x80000000u));
    arr4C.reset(static_cast<int>(0x80000000u));
    arr58.reset(static_cast<int>(0x80000000u));

    int result = DAT_01268b08->vf10();

    if (result != 0)
    {
        reinterpret_cast<hkReferencedObject*>(result)->addReference();
    }

    if (unk2C != 0)
    {
        unk2C->removeReference();
    }

    unk2C = reinterpret_cast<hkReferencedObject*>(result);
    return this;
}
