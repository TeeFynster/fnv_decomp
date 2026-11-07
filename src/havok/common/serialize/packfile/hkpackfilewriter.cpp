
// src/havok/common/serialize/packfile/hkpackfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/hkpackfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkClassEnum.h"
#include "../../../../../include/hkError.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkReferencedObject.h"



__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap());
}

template <class T, class Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& kAlloc = Allocator().get(this);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

extern "C" void __cdecl Vsnprintf(void*, void*, const char*, int, int, int, const char*);

// Calls Vsnprintf with a and b and a formatted Havok version string (7.1.0-r1).
// @fnv 0x00dbda20
// src: XBOX_PDB 0x00dbda20
void __cdecl hkPackfileWriter_getCurrentVersion(void* a, void* b)
{
    Vsnprintf(a, b, "Havok-%i.%i.%i-%s", 7, 1, 0, "r1");
}

struct FUN_00dbdd40_s
{
    int __thiscall GetOrAddString(int a);
};
struct FUN_00d874d0_s
{
    void __thiscall hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char*, int);
};
struct FUN_00dbdf30_s
{
    int m_kPointA;
    int m_kPointB;
    void __thiscall hkPackfileWriter_setSectionForClass(int a, int b);
};
// @fnv 0x00dbdf30
// src: HAVOK_SRC 0x00dbdf30
void __thiscall FUN_00dbdf30_s::hkPackfileWriter_setSectionForClass(int pNameSource, int a)
{
    int idx = ((FUN_00dbdd40_s*)this)->GetOrAddString(a);
    const char* name = ((const hkClass*)(void*)pNameSource)->getName();
    ((FUN_00d874d0_s*)((char*)this + 0xa8))->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(name, idx);
}

struct DepthLimit
{
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void*, void*, int);
};
struct FUN_00dbdae0
{
    char m[0x2c];
    DepthLimit m_dl;
    void UpdateFields_00dbdae0(void* a, int b);
};
// Gets the memory router's stream allocator and forwards it with a and b to m_dl.FUN_00cb1870.
// @fnv 0x00dbdae0
// src: GUESS 0x00dbdae0 (confidence: low)
void FUN_00dbdae0::UpdateFields_00dbdae0(void* a, int b)
{
    void* r = (&hkMemoryRouter::getInstance())->m_heap;
    m_dl.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(r, a, b);
}

namespace fnv_00dbdf00 {
struct DepthLimit
{
    void __thiscall hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void*, void*, int);
};

struct FUN_00dbdf00_s
{
    void __thiscall hkPackfileWriter_setSectionForPointer(void*, int);
};

// Calls GetOrAddString with b, then passes the result and a to FUN_00cb1870 on the DepthLimit at this+0x9c using the memory router's stream allocator.
// @fnv 0x00dbdf00
// src: HAVOK_SRC 0x00dbdf00
void FUN_00dbdf00_s::hkPackfileWriter_setSectionForPointer(void* a, int b)
{
    int result = reinterpret_cast<FUN_00dbdd40_s*>(this)->GetOrAddString(b);
    hkMemoryRouter* router = (&hkMemoryRouter::getInstance());

    reinterpret_cast<DepthLimit*>(reinterpret_cast<char*>(this) + 0x9c)->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(router->m_heap, a, result);
}
}  // namespace fnv_00dbdf00

struct FUN_00dbe760_s;

struct FUN_00dbc6e0_s
{
    virtual void FUN_00dbdf60();
};

struct FUN_00dbe760_s : public FUN_00dbc6e0_s
{
    unsigned short m_uiFilterValue;

    FUN_00dbe760_s* __thiscall FUN_00dbe760(int a);
};

// @fnv 0x00dbe760
FUN_00dbe760_s* __thiscall FUN_00dbe760_s::FUN_00dbe760(int aiFlags)
{
    FUN_00dbc6e0_s::FUN_00dbdf60();

    if (aiFlags & 1)
    {
        hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
        reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(this, m_uiFilterValue);
    }

    return this;
}

struct FUN_00cb1930_s
{
    int LookupHashEntry(const void* key, int defaultValue);
};
struct TrackedElement
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int state;
    unsigned int unk14;
};
struct FUN_00dbda80_s
{
    void* m00;
    void* m04;
    TrackedElement* entries;
    void* m0c;
    void* m10;
    FUN_00cb1930_s entryIndex;
    unsigned int unk18;
    unsigned int unk1c;
    DepthLimit firstDepth;
    void hkPackfileWriter_addImport(void* key, int value);
};
// @fnv 0x00dbda80
// src: HAVOK_SRC 0x00dbda80
void FUN_00dbda80_s::hkPackfileWriter_addImport(void* key, int value)
{
    int index = entryIndex.LookupHashEntry(key, -1);
    if (index >= 0)
        entries[index].state = -2;

    hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
    ((DepthLimit*)&entryIndex)->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(router->m_heap, key, -2);

    hkMemoryRouter* router2 = (&hkMemoryRouter::getInstance());
    firstDepth.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(router2->m_heap, key, value);
}

extern int DAT_0102e388;

struct FUN_00dbdb10_buf
{
    int unk00;
    int unk04;
    volatile int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct FUN_00dc1670_Obj
{
    void hkStructureLayout_hkStructureLayout();
};

struct FUN_00e02bb0_Obj
{
    void hkPlatformObjectWriter_hkPlatformObjectWriter(void* a);
};

struct FUN_00e02ef0_Obj
{
    void FUN_00e02ef0();
};

struct FUN_00e02a80_Obj
{
    void hkPlatformObjectWriter_writeObject(void* a, void* b, void* c, void* d);
};

struct FUN_00e02c70_Obj
{
    void FUN_00e02c70();
};

// @fnv 0x00dbdb10
// src: XBOX_PDB 0x00dbdb10
void __cdecl chasePointers(void* apArg1, void* apArg2, void* apArg3)
{
    FUN_00dbdb10_buf buf;

    reinterpret_cast<FUN_00dc1670_Obj*>(&buf.unk00)->hkStructureLayout_hkStructureLayout();
    reinterpret_cast<FUN_00e02bb0_Obj*>(&buf.unk14)->hkPlatformObjectWriter_hkPlatformObjectWriter(&buf);
    reinterpret_cast<FUN_00e02ef0_Obj*>(&buf.unk04)->FUN_00e02ef0();
    reinterpret_cast<FUN_00e02a80_Obj*>(&buf.unk14)->hkPlatformObjectWriter_writeObject(&buf.unk04, apArg1, apArg2, apArg3);
    buf.unk04 = (int)&DAT_0102e388;
    reinterpret_cast<FUN_00e02c70_Obj*>(&buf.unk14)->FUN_00e02c70();
}

extern "C" void __cdecl GetOrAddString(void);

// @fnv 0x00dbdef0
// src: HAVOK_SRC 0x00dbdef0
void __cdecl hkPackfileWriter_addSection()
{
    GetOrAddString();
}

struct DbFirst
{
    char* __thiscall GetLastNodeFlag(void* out);
};

struct DbSecond
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual unsigned int vf10(unsigned int value);
};

// Calls first->GetLastNodeFlag; if its first character is nonzero, returns second->vf10(arg) or 0; otherwise returns the first pointer.
// @fnv 0x00dbd9f0
// src: XBOX_PDB 0x00dbd9f0
static __declspec(noinline) unsigned int getExactClass(DbFirst* first, DbSecond* second, unsigned int arg)
{
    bool bFlag;
    char* result = first->GetLastNodeFlag(&bFlag);

    if (*result != 0)
    {
        if (second != 0)
            return second->vf10(arg);
        return 0;
    }
    return (unsigned int)first;
}

DbFirst* volatile g_dbd_first;
DbSecond* volatile g_dbd_second;
unsigned int volatile g_dbd_arg;
unsigned int volatile g_dbd_sink;

void dbd9f0_probe_caller(void)
{
    g_dbd_sink = getExactClass((DbFirst*)g_dbd_first, (DbSecond*)g_dbd_second, g_dbd_arg);
}

int __cdecl hkStrCmpDB7(const char* pcA, const char* pcB) throw();
extern hkError* g_pkErrorDB7;
struct hkPointerMapDB7
{
    int FindValueForKey(const void* pvKey, int iDefault) const throw();
    void insert(hkMemoryAllocator& kAlloc, const void* pvKey, int iValue) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkStringMapDB7
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const throw();
    void insert(const char* pcKey, void* pvValue) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
// RegisterObject is the writer method at 0x00dbdb70; retain its layout because include/hkPackfileWriter.h is unavailable.
class hkPackfileWriter
{
  public:
    int RegisterObject(void* pvObject, const hkClass* pkClass) throw();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkPointerMapDB7 m_kObjectIndexMap;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkStringMapDB7 m_kObjectNameMap;
    hkStringMapDB7 m_kClassLookupMap;
    hkPointerMapDB7 m_kClassMap;
};

// For hkClass and hkClassEnum objects, indexes new names and maps duplicates to existing entries; returns 0 for duplicates and 1 otherwise.
// @fnv 0x00dbdb70
int hkPackfileWriter::RegisterObject(void* pvObject, const hkClass* pkClass) throw()
{
    if (hkStrCmpDB7(pkClass->getName(), "hkClass") == 0)
    {
        const hkClass* pkNewClass = (const hkClass*)pvObject;
        const char* pcName = pkNewClass->getName();
        const hkClass* pkOldClass = (const hkClass*)m_kObjectNameMap.FindValueForKey(pcName, 0);
        if (pkOldClass)
        {
            if (pkNewClass->CalculateDatabaseSignature(0) != pkOldClass->CalculateDatabaseSignature(0))
            {
                unsigned int assertBuf[128];
                hkOstream ostr(assertBuf, sizeof(assertBuf));
                ostr
                    << "Conflicting metadata found for class " << pkNewClass->getName()
                    << ". Perhaps you have called setContents on data which has not been updated to the current version.";
                if (g_pkErrorDB7->message(3, 0x2518721c, (const char*)assertBuf, ".\\Packfile\\hkPackfileWriter.cpp",
                                          178))
                    __debugbreak();
            }
            int iIndex = m_kObjectIndexMap.FindValueForKey(pkOldClass, -1);
            m_kObjectIndexMap.insert(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), pkNewClass, iIndex);
            m_kClassMap.insert(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), pkNewClass, (int)pkOldClass);
            return 0;
        }
        const char* pcNewName = pkNewClass->getName();
        m_kObjectNameMap.insert(pcNewName, (void*)pkNewClass);
    }
    else if (hkStrCmpDB7(pkClass->getName(), "hkClassEnum") == 0)
    {
        const hkClassEnum* pkNewEnum = (const hkClassEnum*)pvObject;
        const char* pcName = pkNewEnum->m_name;
        const hkClassEnum* pkOldEnum = (const hkClassEnum*)m_kClassLookupMap.FindValueForKey(pcName, 0);
        if (pkOldEnum)
        {
            int iIndex = m_kObjectIndexMap.FindValueForKey(pkOldEnum, -1);
            m_kObjectIndexMap.insert(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), pkNewEnum, iIndex);
            m_kClassMap.insert(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), pkNewEnum, (int)pkOldEnum);
            return 0;
        }
        m_kClassLookupMap.insert(pkNewEnum->m_name, (void*)pkNewEnum);
    }
    return 1;
}

template <int SIZE> __forceinline void memCpyOneAlignedXdbdd40(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& e)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    memCpyOneAlignedXdbdd40<sizeof(T)>(m_data + m_iElementCount, &e);
    m_iElementCount++;
}

extern "C" char* __cdecl hkString_strDup_00cb1410(const char* str);

class hkStringMapXdbdd40
{
  public:
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_get(const char* key, int* out);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* key, int value);
};

class hkStringPoolXdbdd40
{
  public:
    int unk00[25];
    hkArray<char*> m_pStringFunctions;
    hkStringMapXdbdd40 m_map;

    int GetOrAddString(const char* str);
};

// Looks up str in m_map, returning the existing index; otherwise copies str, stores it in m_pStringFunctions, registers it in m_map, and returns the new index.
// @fnv 0x00dbdd40
int hkStringPoolXdbdd40::GetOrAddString(const char* apString)
{
    int index;
    if (m_map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_get(apString, &index) == 0)
        return index;
    char* copy = hkString_strDup_00cb1410(apString);
    int newIndex = m_pStringFunctions.m_iElementCount;
    m_map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(copy, newIndex);
    m_pStringFunctions.pushBack(copy);
    return newIndex;
}

struct S00dbde40_Base
{
    int __thiscall hkPackfileWriter_findSectionFor(int a, int b, int c);
};

struct S00dbde40_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct S00dbde40_Arr
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};

struct S00dbde40_Obj : public S00dbde40_Base
{
    int unk00;
    int unk04;
    S00dbde40_Arr arr;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;

    void __thiscall hkPackfileWriter_addPendingWrite(int a, int b, int c, int d, int e);
};

void __cdecl ResizeAudioStream(void* a, void* b, int c);
extern char DAT_0126cae8;

// Calls FUN_00dbddc0, builds an S00dbde40_Entry, appends it to arr, and increments unk98 or unk94 depending on b.
// @fnv 0x00dbde40
// src: XBOX_PDB 0x00dbde40
void S00dbde40_Obj::hkPackfileWriter_addPendingWrite(int a, int b, int c, int d, int e)
{
    int result = this->hkPackfileWriter_findSectionFor(c, d, e);
    S00dbde40_Entry tmp;
    tmp.unk00 = a;
    tmp.unk04 = b;
    tmp.unk08 = c;
    tmp.unk0C = d;
    tmp.unk10 = result;
    tmp.unk14 = -1;

    S00dbde40_Arr& arr = this->arr;
    hkMemoryRouter* router = (&hkMemoryRouter::getInstance());

    if (arr.m_iElementCount == (int)(arr.m_capFlags & 0x3fffffff))
    {
        ResizeAudioStream(router->m_heap, &arr, 0x18);
    }

    S00dbde40_Entry* pSlot = (S00dbde40_Entry*)((char*)arr.m_data + arr.m_iElementCount * 24);

    if (pSlot != 0)
    {
        *pSlot = tmp;
    }

    ++arr.m_iElementCount;
    this->unk98 += (b == (int)&DAT_0126cae8);
    this->unk94 += (b != (int)&DAT_0126cae8);
}

void __cdecl hkDeallocateDF6(hkMemoryAllocator& kAlloc, void* pvData) throw();

struct hkMapDF6
{
    ~hkMapDF6() throw();
    void ClearAndRelease(hkMemoryAllocator& kAlloc) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkPointerMapDF6
{
    ~hkPointerMapDF6() throw()
    {
        m_map.ClearAndRelease(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()));
    }
    hkMapDF6 m_map;
};
struct hkStringMapDF6
{
    ~hkStringMapDF6() throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
struct SectionDF6
{
    int m_aiData00;
    int m_aiData04;
    int m_aiData08;
    int m_aiData0C;
    int m_aiData10;
    int m_aiData14;
};
// Packfile exports store two pointers; Pair.h instead describes integer group/index and Ref values.
struct PackfileExportPair
{
    void* m_pvFirst;
    void* m_pvSecond;
};
struct SectionTableDF6
{
    hkArray<PackfileExportPair> m_entries;
    hkPointerMapDF6 m_uiEdgeIndex;
};
// Retained writer layout: include/hkPackfileWriter.h is not available.
class FUN_00dbdf60 : public hkReferencedObject
{
  public:
    virtual ~FUN_00dbdf60() throw();
    hkArray<SectionDF6> m_sections;
    hkPointerMapDF6 m_kObjectNameMap;
    hkPointerMapDF6 m_kObjectIndexMap;
    hkPointerMapDF6 m_kClassMap;
    hkStringMapDF6 m_kClassNameMap;
    hkStringMapDF6 m_classNames;
    hkPointerMapDF6 m_kObjectMap;
    hkArray<void*> m_pendingObjects;
    hkStringMapDF6 m_kImports;
    hkArray<PackfileExportPair> m_kExports;
    int m_iContentsSection;
    int m_iDataSection;
    void* m_pvContents;
    void* m_pvContentsClass;
    hkPointerMapDF6 m_objectsWritten;
    hkStringMapDF6 m_classesWritten;
    SectionTableDF6 m_kSectionTable;
};

// Frees each object pointer stored in m_pendingObjects via the global memory router allocator.
// @fnv 0x00dbdf60
FUN_00dbdf60::~FUN_00dbdf60() throw()
{
    for (int i = 0; i < m_pendingObjects.m_iElementCount; i++)
    {
        void* pvObject = m_pendingObjects.m_data[i];
        hkDeallocateDF6(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), pvObject);
    }
}

struct hkPointerMapE4D
{
    hkPointerMapE4D() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {
        init(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), 0);
    }
    void init(hkMemoryAllocator& kAlloc, int iNumElements);
    void insert(hkMemoryAllocator& kAlloc, const void* pvKey, int iValue);
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkStringMapE4D
{
    hkStringMapE4D(hkContainerHeapAllocator kAlloc);
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
struct hkPackfileSectionTableE4D
{
    hkPackfileSectionTableE4D();
};

extern hkClass g_kClassAE4D;
extern hkClass g_kClassBE4D;
extern hkClass g_kClassCE4D;
// Retained writer layout: include/hkPackfileWriter.h is not available.
class FUN_00dbe4d0 : public hkReferencedObject
{
  public:
    FUN_00dbe4d0() throw();
    virtual ~FUN_00dbe4d0();
    hkArray<void*> m_sections;
    hkPointerMapE4D m_kObjectNameMap;
    hkPointerMapE4D m_kObjectIndexMap;
    hkPointerMapE4D m_kClassMap;
    hkStringMapE4D m_kClassNameMap;
    hkStringMapE4D m_classNames;
    hkPointerMapE4D m_kObjectMap;
    hkArray<void*> m_pendingObjects;
    hkStringMapE4D m_kImports;
    hkArray<void*> m_kExports;
    int m_iContentsSection;
    int m_iDataSection;
    void* m_pvContents;
    void* m_pvContentsClass;
    hkPointerMapE4D m_objectsWritten;
    hkStringMapE4D m_classesWritten;
    hkPackfileSectionTableE4D m_kSectionTable;
};

// Constructs the object, initialising string maps with a container heap allocator and inserting three class pointers into m_kObjectNameMap with value -1.
// @fnv 0x00dbe4d0
FUN_00dbe4d0::FUN_00dbe4d0() throw()
    : m_kClassNameMap(hkContainerHeapAllocator()), m_classNames(hkContainerHeapAllocator()),
      m_kImports(hkContainerHeapAllocator()), m_iContentsSection(-1), m_iDataSection(-1), m_pvContents(0),
      m_pvContentsClass(0), m_classesWritten(hkContainerHeapAllocator())
{
    m_kObjectNameMap.insert(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), &g_kClassAE4D, -1);
    m_kObjectNameMap.insert(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), &g_kClassBE4D, -1);
    m_kObjectNameMap.insert(reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()), &g_kClassCE4D, -1);
}

struct Mgr
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vf5();
};
extern Mgr* DAT_01268b08;
struct Cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vf3(void* a, void* b, void* r, void* c);
    void hkPackfileWriter_setContents(void* a, void* b, void* c);
};
// Invokes vf3 on the object, passing a, b, the result of DAT_01268b08->vf5(), and c.
// @fnv 0x00dbda50
// src: HAVOK_SRC 0x00dbda50
void Cls::hkPackfileWriter_setContents(void* apArg1, void* apArg2, void* apArg3)
{
    vf3(apArg1, apArg2, DAT_01268b08->vf5(), apArg3);
}

struct S00dbddc0_Base
{
    int __thiscall GetOrAddString(int a);
};

struct S00dbddc0_Sub9C
{
    int unk00;
    int unk04;
    int unk08;
    int __thiscall LookupHashEntry(int a, int b);
};

struct S00dbddc0_SubA8
{
    int __thiscall GetValue(int a, int b);
};

struct S00dbddc0_Node
{
    int __thiscall FUN_00d46d40();
    S00dbddc0_Node* __thiscall FUN_00d46d50();
};

struct S00dbddc0_cls : public S00dbddc0_Base
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    S00dbddc0_Sub9C m_sub9c;
    S00dbddc0_SubA8 m_suba8;

    int __thiscall hkPackfileWriter_findSectionFor(int a1, S00dbddc0_Node* a2, int a3);
};

// Looks up a hash entry for a1, then walks the node chain a2 calling GetValue on each key, returning the first hit or calling GetOrAddString(a3).
// @fnv 0x00dbddc0
// src: XBOX_PDB 0x00dbddc0
int S00dbddc0_cls::hkPackfileWriter_findSectionFor(int a1, S00dbddc0_Node* apStartNode, int a3)
{
    int r = m_sub9c.LookupHashEntry(a1, -1);
    if (r != -1)
    {
        return r;
    }
    S00dbddc0_Node* n = apStartNode;
    int iKey = n->FUN_00d46d40();
    r = m_suba8.GetValue(iKey, -1);
    if (r != -1)
    {
        return r;
    }
    do
    {
        n = n->FUN_00d46d50();
        if (n == 0)
        {
            return GetOrAddString(a3);
        }
        iKey = n->FUN_00d46d40();
        r = m_suba8.GetValue(iKey, -1);
    } while (r == -1);
    return r;
}

namespace fnv_00dbe680 {
struct S00dbe680_Tbl
{
    int __thiscall LookupHashEntry(int a, int b);
};

struct S00dbe680_Ret
{
    bool b;
    S00dbe680_Ret();
};

struct S00dbe680_A2
{
    S00dbe680_Ret __thiscall GetLastNodeFlag();
};

struct S00dbe680_A3
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int a1);
};

struct S00dbe680_Glob
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual S00dbe680_A3* v5();
};

extern S00dbe680_Glob* DAT_01268b08;
extern void* DAT_011b7ae8;

struct Class_00dbe680
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S00dbe680_Tbl m_hashTable;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int m_8c;
    int m_90;

    void hkPackfileWriter_addObject(int a1, void* a2, S00dbe680_A3* a3, int a4, void* a5);
    void hkPackfileWriter_setContentsWithRegistry(int a1, S00dbe680_A2* a2, S00dbe680_A3* a3, int a4);
};

// src: XBOX_PDB 0x00dbe150
__declspec(noinline) void Class_00dbe680::hkPackfileWriter_addObject(int a1, void* a2, S00dbe680_A3* a3, int a4, void* a5)
{
    unk00 = a1;
    unk04 = a4;
}

// Resolves a target pointer from a3 or a global, adjusts it via v4 or a2, calls FUN_00dbe150, and stores hash lookups in m_8c and m_90.
// @fnv 0x00dbe680
// src: HAVOK_SRC 0x00dbe680
void Class_00dbe680::hkPackfileWriter_setContentsWithRegistry(int a1, S00dbe680_A2* a2, S00dbe680_A3* a3, int a4)
{
    void* target = a3 ? (void*)a3 : (void*)DAT_01268b08->v5();
    if (a2->GetLastNodeFlag().b)
    {
        target = ((S00dbe680_A3*)target)->v4(a1);
    }
    else
    {
        target = a2;
    }
    hkPackfileWriter_addObject(a1, target, a3, a4, DAT_011b7ae8);
    m_8c = m_hashTable.LookupHashEntry(a1, -1);
    m_90 = m_hashTable.LookupHashEntry((int)target, -1);
}
}  // namespace fnv_00dbe680

struct FUN_00cb18f0_t
{
    int unk00;
    int unk04;
    int unk08;
    int __thiscall FindSlot(int key);
    void __thiscall hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* alloc, int key, int value);
    int __thiscall LookupHashEntry(int key, int def);
    __forceinline void insert(void* key, int value)
    {
        hkMemoryRouter* sg = (&hkMemoryRouter::getInstance());
        hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(sg->m_heap, (int)key, value);
    }
};
struct MapB8E150
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00cb18f0_t indices;
    int __thiscall AllocateSlot();
    __declspec(noinline) void __thiscall hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(void* a, int* b);
};
// Fixup links store a pointer key and pointer-encoded index; they do not use Pair.h's Ref operations.
struct FixupLinkPair
{
    void* key;
    void* value;
};
struct PairListE150
{
    FixupLinkPair* m_data;
    int m_uiItemCount;
    int m_pRayCursor;
};
struct Arg4ObjE150
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void* a, void* b);
};
struct EntryE150
{
    int unk00;
    void* m04;
    void* m08;
    int m0c;
};
struct BufObjE150
{
    int unk00;
    int unk04;
    int unk08;
    EntryE150* m_data;
    int m_uiItemCount;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void __thiscall FUN_00dbd870();
    void __thiscall FUN_00e028e0();
};
extern hkError* DAT_01268360;
extern int DAT_011b7aec;
extern const char DAT_010d6734;
extern const char DAT_010d6760;
extern const char DAT_010d67a8;
extern const char DAT_010d67e0;
extern const char DAT_010d664c;
struct ErrBufE150
{
    int f000;
    int f001;
    int f002;
    int f003;
    int f004;
    int f005;
    int f006;
    int f007;
    int f008;
    int f009;
    int f010;
    int f011;
    int f012;
    int f013;
    int f014;
    int f015;
    int f016;
    int f017;
    int f018;
    int f019;
    int f020;
    int f021;
    int f022;
    int f023;
    int f024;
    int f025;
    int f026;
    int f027;
    int f028;
    int f029;
    int f030;
    int f031;
    int f032;
    int f033;
    int f034;
    int f035;
    int f036;
    int f037;
    int f038;
    int f039;
    int f040;
    int f041;
    int f042;
    int f043;
    int f044;
    int f045;
    int f046;
    int f047;
    int f048;
    int f049;
    int f050;
    int f051;
    int f052;
    int f053;
    int f054;
    int f055;
    int f056;
    int f057;
    int f058;
    int f059;
    int f060;
    int f061;
    int f062;
    int f063;
    int f064;
    int f065;
    int f066;
    int f067;
    int f068;
    int f069;
    int f070;
    int f071;
    int f072;
    int f073;
    int f074;
    int f075;
    int f076;
    int f077;
    int f078;
    int f079;
    int f080;
    int f081;
    int f082;
    int f083;
    int f084;
    int f085;
    int f086;
    int f087;
    int f088;
    int f089;
    int f090;
    int f091;
    int f092;
    int f093;
    int f094;
    int f095;
    int f096;
    int f097;
    int f098;
    int f099;
    int f100;
    int f101;
    int f102;
    int f103;
    int f104;
    int f105;
    int f106;
    int f107;
    int f108;
    int f109;
    int f110;
    int f111;
    int f112;
    int f113;
    int f114;
    int f115;
    int f116;
    int f117;
    int f118;
    int f119;
    int f120;
    int f121;
    int f122;
    int f123;
    int f124;
    int f125;
    int f126;
    int f127;
};

struct OwnerE150
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00cb18f0_t map14;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    FUN_00cb18f0_t map58;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    PairListE150 list80;
    int u8c;
    int u90;
    int u94;
    int u98;
    FUN_00cb18f0_t map9c;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    MapB8E150 mapb8;
    int __thiscall RegisterObject(void* a, void* b);
    void __thiscall hkPackfileWriter_addPendingWrite(void* a, void* b, void* c, void* d, void* e);
    void __thiscall hkPackfileWriter_addObject(void* a1, void* a2, void* a3, void* a4, void* a5);
};

// Processes a1 and a2 using map14, may recurse through buffered entries, and logs a message when FUN_00dbd9f0 returns null.
// @fnv 0x00dbe150
// src: XBOX_PDB 0x00dbe150
void __thiscall OwnerE150::hkPackfileWriter_addObject(void* apKey, void* a2, void* a3, void* a4, void* a5)
{
    FUN_00cb18f0_t* pMap = &map14;
    if (pMap->FindSlot((int)apKey) <= pMap->unk08)
    {
        return;
    }
    void* result = (void*)getExactClass((DbFirst*)a2, (DbSecond*)a3, (unsigned int)apKey);
    if (result)
    {
        void* pResolvedKey = apKey;
        void* pResolvedValue = result;
        if (a4)
        {
            ((Arg4ObjE150*)a4)->v3(&pResolvedKey, &pResolvedValue);
        }
        if (pResolvedKey)
        {
            if (!RegisterObject(pResolvedKey, pResolvedValue))
            {
                return;
            }
            if (apKey != pResolvedKey)
            {
                if (pMap->FindSlot((int)pResolvedKey) <= pMap->unk08)
                {
                    return;
                }
            }
            pMap->insert(apKey, unk0c);
            if (pResolvedKey != apKey)
            {
                pMap->insert(pResolvedKey, unk0c);
                map58.insert(pResolvedKey, (int)apKey);
            }
            hkPackfileWriter_addPendingWrite(pResolvedKey, pResolvedValue, apKey, a2, a5);
            BufObjE150 buf;
            buf.FUN_00dbd870();
            chasePointers(pResolvedKey, pResolvedValue, &buf);
            int idx = 0;
            if (buf.m_uiItemCount > 0)
            {
                int iOffset = 0;
                do
                {
                    EntryE150* e = (EntryE150*)((char*)buf.m_data + iOffset);
                    void* k2 = e->m08;
                    void* k1 = e->m04;
                    if (k2 && k1)
                    {
                        if (e->m0c)
                        {
                            FUN_00cb18f0_t* map9cp = &map9c;
                            if (map9cp->FindSlot((int)k1) > map9cp->unk08)
                            {
                                int code = ((FUN_00dbdd40_s*)this)->GetOrAddString((int)a5);
                                int iValue = map9cp->LookupHashEntry((int)pResolvedKey, code);
                                map9cp->insert(k1, iValue);
                            }
                        }
                        hkPackfileWriter_addObject(k1, k2, a3, a4, a5);
                        if (pResolvedKey != k1)
                        {
                            int tmp = pMap->LookupHashEntry((int)k1, -1);
                            if (tmp != -1)
                            {
                                mapb8.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(pResolvedKey, &tmp);
                            }
                        }
                    }
                    idx++;
                    iOffset += 0x10;
                } while (idx < buf.m_uiItemCount);
            }
            hkPackfileWriter_addObject(pResolvedValue, (void*)&DAT_0126cae8, a3, a4, (void*)DAT_011b7aec);
            buf.FUN_00e028e0();
        }
        else
        {
            pMap->insert(apKey, -1);
        }
    }
    else
    {
        ErrBufE150 errorBuffer;
        unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
        hkOstream& stream = *reinterpret_cast<hkOstream*>(streamStorage);
        stream.FUN_00cb1600((char*)&errorBuffer, 0x200);
        stream.ProcessAndReturnValue_00cc01c0(&DAT_010d6734)
            .ProcessAndReturnValue_00cc01c0(((const hkClass*)a2)->getName())
            .ProcessAndReturnValue_00cc01c0(&DAT_010d6760)
            .ProcessAndReturnValue_00cc01c0(&DAT_010d67a8)
            .ProcessAndReturnValue_00cc01c0(&DAT_010d67e0);
        DAT_01268360->message(1, (int)0xabbaabba, (const char*)&errorBuffer, &DAT_010d664c, 0x121);
        stream.FUN_00cc00e0();
        pMap->insert(apKey, -1);
        PairListE150* exports = &list80;
        hkMemoryRouter* sg2 = (&hkMemoryRouter::getInstance());
        if (exports->m_uiItemCount == (exports->m_pRayCursor & 0x3fffffff))
        {
            ResizeAudioStream(sg2->m_heap, exports, 8);
        }
        FixupLinkPair* p = &exports->m_data[exports->m_uiItemCount];
        p->key = apKey;
        p->value = a2;
        exports->m_uiItemCount++;
    }
}

// src: XBOX_PDB 0x00dc9ec0
__declspec(noinline) void __thiscall MapB8E150::hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(void* a, int* b)
{
    int oldIndex = indices.LookupHashEntry((int)a, -1);
    int index = AllocateSlot();
    FixupLinkPair* entries = (FixupLinkPair*)unk00;
    entries[index].key = (void*)*b;
    entries[index].value = (void*)oldIndex;
    indices.insert(a, index);
}
