#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVtableClassRegistry.h"
#include "../../../../../include/MemoryManager.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkDefaultBuiltinTypeRegistry.h"

// src/havok/common/serialize/util/hkbuiltintyperegistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkbuiltintyperegistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010cf78c;
// @fnv 0x00d478c0
hkDefaultBuiltinTypeRegistry* hkDefaultBuiltinTypeRegistry::Initialize()
{
    *(unsigned short*)((char*)this + 6) = 1;
    *(void**)this = &DAT_010cf78c;
    RegisterBuiltinTypes();
    return this;
}

struct FUN_00d479e0_class
{
    void* __thiscall GetValue(const void* key, const void* def);
    void* __thiscall hkTypeInfoRegistry_getTypeInfo(const void* key);
};

// @fnv 0x00d479e0
// src: HAVOK_SRC 0x00d479e0
void* __thiscall FUN_00d479e0_class::hkTypeInfoRegistry_getTypeInfo(const void* key)
{
    return ((FUN_00d479e0_class*)((char*)this + 8))->GetValue(key, 0);
}

struct FUN_00d47a80_class
{
    void* GetValue(void* a, int b);
    void* ForwardToOffsetMember(void* a);
};

// @fnv 0x00d47a80
void* FUN_00d47a80_class::ForwardToOffsetMember(void* apArg)
{
    return ((FUN_00d47a80_class*)((char*)this + 0xc))->GetValue(apArg, 0);
}

struct HashEntryTable
{
    unsigned long FindValueForKey(unsigned long a, unsigned long b);
};
// @fnv 0x00d47c40
unsigned long hkVtableClassRegistry::LookupClassByVtable(const unsigned long* pVtable)
{
    unsigned long v = *pVtable;
    return ((HashEntryTable*)((char*)this + 8))->FindValueForKey(v, 0);
}

struct D481D0Class
{
    const char* getName() const;
};
struct FUN_00d874d0_s
{
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char*, int);
};
struct FUN_00d47aa0_s
{
    int a;
    int b;
    int c;
    void hkDynamicClassNameRegistry_registerClass(int a, const char* name);
};
// Calls FUN_00d874d0 on the object at this+0xc with the given name (or the name from a) and a.
// @fnv 0x00d47aa0
// src: HAVOK_LIB 0x00d47aa0
void FUN_00d47aa0_s::hkDynamicClassNameRegistry_registerClass(int a, const char* name)
{
    ((FUN_00d874d0_s*)((char*)this + 0xc))->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(name ? name : ((D481D0Class*)a)->getName(), a);
}

struct FUN_00d87440_Class
{
    int __thiscall hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int);
};
struct SlotBitmap
{
    int __thiscall FindNextUsedSlot(int);
};
struct FUN_00d874b0_class
{
    char* __thiscall SetBoolFromThreshold(char*, int);
};
struct FUN_00d87410_Class
{
    int __thiscall hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
};

struct FUN_00d47ad0_class
{
    void ProcessRegistryEntries(FUN_00d874b0_class* reg);
};

// @fnv 0x00d47ad0
void FUN_00d47ad0_class::ProcessRegistryEntries(FUN_00d874b0_class* reg)
{
    int key = ((FUN_00d87410_Class*)reg)->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    char flag;
    reg->SetBoolFromThreshold(&flag, key);
    while (flag)
    {
        int val = ((FUN_00d87440_Class*)reg)->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(key);
        (*(void(__thiscall**)(void*, int, int))(*(int*)this + 0x1c))(this, val, 0);
        key = ((SlotBitmap*)reg)->FindNextUsedSlot(key);
        reg->SetBoolFromThreshold(&flag, key);
    }
}

extern "C" hkMemoryRouter* __cdecl D1A0E0GetMemoryRouter();
struct DepthLimit
{
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void*, void*, int);
};
struct FUN_00d47c60_class
{
    int x, y;
    DepthLimit z;
    void hkVtableClassRegistry_registerVtable(void* key, int def);
};
// Gets the memory router, takes its manager's first field as a pointer, and passes it with key and def to FUN_00cb1870.
// @fnv 0x00d47c60
// src: HAVOK_LIB 0x00d47c60
void FUN_00d47c60_class::hkVtableClassRegistry_registerVtable(void* key, int aiDefault)
{
    hkMemoryRouter* r = D1A0E0GetMemoryRouter();
    void* p = r->m_heap;
    z.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(p, key, aiDefault);
}

extern int DAT_01269b18;

// @fnv 0x00d47a00
// src: GUESS 0x00d47a00 (confidence: low)
int __cdecl Object_GetDAT_01269b18_00d47a00()
{
    return DAT_01269b18;
}

extern int DAT_01269b14;

// @fnv 0x00d47a10
// src: GUESS 0x00d47a10 (confidence: low)
int __cdecl hkBuiltinTypeRegistry_GetDAT01269b14()
{
    return DAT_01269b14;
}

extern int DAT_01269b10;

// @fnv 0x00d47a20
// src: GUESS 0x00d47a20 (confidence: low)
int Object_GetDAT_01269b10_00d47a20()
{
    return DAT_01269b10;
}

struct D477C0Input
{
    int unk00, unk04, unk08;
    void* value0c;
};
struct D477C0Source
{
    int FUN_00d46d40();
    int SumLinkedValues();
};
struct D477C0RegistryA
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void registerObject(D477C0Source*, int);
};
struct D477C0RegistryB
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void registerInput(D477C0Input*);
};
struct D477C0RegistryC
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void registerLink(void*, D477C0Source*);
};
// @fnv 0x00d477c0
void __stdcall RegisterInputSource(D477C0Input* input, D477C0Source* source)
{
    D477C0RegistryA* registryA = *(D477C0RegistryA**)&DAT_01269b14;
    registryA->registerObject(source, source->FUN_00d46d40());
    D477C0RegistryB* registryB = *(D477C0RegistryB**)&DAT_01269b18;
    registryB->registerInput(input);
    if (source->SumLinkedValues() > 0)
    {
        D477C0RegistryC* registryC = *(D477C0RegistryC**)&DAT_01269b10;
        registryC->registerLink(input->value0c, source);
    }
}

// hkTypeInfo name prefix: Xbox PDB m_typeName is at +0; this is not hkClass metadata.
struct TypeInfoNameView
{
    const char* m_name;

    const char* getName() const
    {
        return m_name;
    }
};

// hkTypeInfoRegistry view: m_map is at +8; Xbox PDB hkClassNameRegistry has no map.
class BuiltinTypeRegistrationView
{
  public:
    int m_00;
    int m_04;
    FUN_00d874d0_s m_map;

    void RegisterClass(const TypeInfoNameView* pkClass);
};

// @fnv 0x00d478e0
void BuiltinTypeRegistrationView::RegisterClass(const TypeInfoNameView* pkClass)
{
    m_map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(pkClass->getName(), (int)pkClass);
}

// hkTypeInfo finish-callback prefix (+4); Xbox PDB hkEntry instead contains three floats.
struct FinishLoadedTypeInfoView
{
    int m_00;
    void(__cdecl* m_func)(void* a, int b);
};

struct hkObjD479
{
    int m_00;
    int m_04;
    FUN_00d47a80_class m_map;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    FinishLoadedTypeInfoView* FindEntryAndCall(void* a, void* key);
};

// Looks up key in m_map; if found, calls the entry's m_func with a and m_18, then returns the entry, else returns 0.
// @fnv 0x00d47900
FinishLoadedTypeInfoView* hkObjD479::FindEntryAndCall(void* apArg, void* key)
{
    FinishLoadedTypeInfoView* p = (FinishLoadedTypeInfoView*)m_map.GetValue(key, 0);
    if (p)
    {
        if (p->m_func)
            p->m_func(apArg, m_18);
        return p;
    }
    return 0;
}

struct FUN_00d47940_Result
{
    int unk00;
    int unk04;
    void(__cdecl* unk08)(int);
};

struct FUN_00d47940_Registry
{
    void* __thiscall GetValue(const void* key, const void* def);
};

struct FUN_00d47940_Obj
{
    int unk00;
    int unk04;
    FUN_00d47940_Registry unk08;
    void* __thiscall hkTypeInfoRegistry_cleanupLoadedObject(int param1, int param2);
};

// Looks up a result by key in the registry, and if found and it has a callback, invokes that callback with param1; returns the result.
// @fnv 0x00d47940
// src: HAVOK_LIB 0x00d47940
void* __thiscall FUN_00d47940_Obj::hkTypeInfoRegistry_cleanupLoadedObject(int param1, int aKey)
{
    FUN_00d47940_Result* result = (FUN_00d47940_Result*)this->unk08.GetValue((const void*)aKey, 0);

    if (result != 0 && result->unk08 != 0)
    {
        result->unk08(param1);
    }

    return result;
}

struct FUN_00d87430_Class
{
    int __thiscall GetEntry(int index);
};
struct FUN_00d47970_Class
{
    int unk00;
    int unk04;
    FUN_00d874d0_s m_map08;

    void hkTypeInfoRegistry_merge(void* iterator);
};

// @fnv 0x00d47970
// src: HAVOK_LIB 0x00d47970
void FUN_00d47970_Class::hkTypeInfoRegistry_merge(void* iterator)
{
    FUN_00d87410_Class* registry = (FUN_00d87410_Class*)((char*)iterator + 8);
    int index = registry->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    ((FUN_00d874b0_class*)registry)->SetBoolFromThreshold((char*)&iterator, index);
    if (*(char*)&iterator != 0)
    {
        FUN_00d874d0_s* destination = &m_map08;
        do
        {
            int key = ((FUN_00d87440_Class*)registry)->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(index);
            int value = ((FUN_00d87430_Class*)registry)->GetEntry(index);
            destination->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert((const char*)value, key);
            index = ((SlotBitmap*)registry)->FindNextUsedSlot(index);
            ((FUN_00d874b0_class*)registry)->SetBoolFromThreshold((char*)&iterator, index);
        } while (*(char*)&iterator != 0);
    }
}

class hkObjD47A
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void add(const char* pcName, int iFlags);

    void AddNames(const char* const* ppcNames);
};

// Calls add on each name in the null-terminated array ppcNames with flags 0.
// @fnv 0x00d47a50
void hkObjD47A::AddNames(const char* const* ppcNames)
{
    for (; *ppcNames; ++ppcNames)
        add(*ppcNames, 0);
}

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

template <class T> T& RouterHeap(hkMemoryRouter* router)
{
    return *(T*)router->m_heap;
}



inline void hkReferencedObject::operator delete(void* p)
{
    RouterHeap<hkMemoryAllocator>(hkMemoryRouter_getInstance()).blockFree(
        p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

struct EmbeddedRegistry
{
    void FreeBuffer();
    ~EmbeddedRegistry()
    {
        FreeBuffer();
    }
};
struct RegistryImpl : hkReferencedObject
{
    int unk08;
    EmbeddedRegistry embedded;
    RegistryImpl* DestroyRegistry(unsigned int flags);
};
// Destroys the embedded registry and base, then if flags bit 0 is set releases this object through the Havok heap using allocatedSize.
// @fnv 0x00d47b30
RegistryImpl* RegistryImpl::DestroyRegistry(unsigned int flags)
{
    embedded.~EmbeddedRegistry();
    hkReferencedObject::~hkReferencedObject();
    if (flags & 1)
    {
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        ((hkMemoryAllocator*)router->m_heap)->blockFree(this, m_usMemSizeAndFlags);
    }
    return this;
}

namespace fnv_00d47bb0 {
void __cdecl ResizeAudioStream(void* allocator, hkArray<int>* array, int elementSize);

struct D47Map
{
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    void SetBoolFromThreshold(unsigned char* hasNext, int iterator);
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int iterator);
    int FindNextUsedSlot(int iterator);
};
struct D47Owner
{
    int field00;
    int field04;
    int field08;
    D47Map entries;
    void AppendEntryValues(hkArray<int>* values);
};
// Iterates the entries map and appends each entry's value to the values array, growing it via the router's heap when full.
// @fnv 0x00d47bb0
void D47Owner::AppendEntryValues(hkArray<int>* values)
{
    unsigned char hasItem;
    int iterator = entries.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    entries.SetBoolFromThreshold(&hasItem, iterator);
    while (hasItem)
    {
        int value = entries.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(iterator);
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        if (values->m_iElementCount == (values->m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(router->m_heap, values, 4);
        }
        int* insertion = values->m_data + values->m_iElementCount;
        ++values->m_iElementCount;
        *insertion = value;
        iterator = entries.FindNextUsedSlot(iterator);
        entries.SetBoolFromThreshold(&hasItem, iterator);
    }
}
}  // namespace fnv_00d47bb0

namespace fnv_00d47c90 {
extern int DAT_0102e388;
struct Sub
{
    int q;
    void ProcessArgument(hkMemoryAllocator* a);
    void Object_DoNothing();
};
struct FUN_00d47c90_cls
{
    void* vptr;
    unsigned short size;
    unsigned short pad;
    Sub sub;
    FUN_00d47c90_cls* Destroy(unsigned char flags);
};
// @fnv 0x00d47c90
FUN_00d47c90_cls* FUN_00d47c90_cls::Destroy(unsigned char flags)
{
    sub.ProcessArgument((hkMemoryAllocator*)hkMemoryRouter_getInstance()->m_heap);
    sub.Object_DoNothing();
    vptr = &DAT_0102e388;
    hkMemoryRouter* h;
    if (flags & 1)
    {
        h = hkMemoryRouter_getInstance();
        hkMemoryAllocator* a = (hkMemoryAllocator*)h->m_heap;
        a->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d47c90

// Unit-local bodies for operations declared by the shared Havok headers.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return RouterHeap<hkMemoryAllocator>(hkMemoryRouter_getInstance());
}

template <class T> __forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& t, hkTypeIsPod)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
    m_iElementCount++;
}

template <class T> void hkMemoryAllocator::_bufFree(void* p, int count)
{
    bufFree(p, count * sizeof(T));
}

template <class T> __forceinline void hkArrayBase<T>::clear()
{
    for (int i = 0; i < m_iElementCount; i++)
        m_data[i].~T();
    m_iElementCount = 0;
}

template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <class T, class Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    this->_clearAndDeallocate(Allocator().get(this));
}

namespace fnv_00d47ce0 {
struct hkMapPairD47C
{
    int key;
    int val;
};

class hkMapIterD47C;
typedef hkMapIterD47C* hkMapIteratorD47C;

class hkPointerMapD47C
{
  public:
    hkMapPairD47C* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkMapIteratorD47C GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != -1)
                break;
        }
        return reinterpret_cast<hkMapIteratorD47C>(i);
    }
    hkMapIteratorD47C getNext(hkMapIteratorD47C it) const
    {
        int i = reinterpret_cast<int>(it);
        for (i += 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != -1)
                break;
        }
        return reinterpret_cast<hkMapIteratorD47C>(i);
    }
    bool isValid(hkMapIteratorD47C it) const
    {
        return reinterpret_cast<int>(it) <= m_iPairCount;
    }
    int getValue(hkMapIteratorD47C it) const
    {
        return m_kPrimitiveElement[reinterpret_cast<int>(it)].val;
    }
};

class FUN_00d47ce0_class
{
  public:
    int unk00;
    int unk04;
    hkPointerMapD47C m_map;

    void CollectMapValues(hkArray<int>& kValuesOut) const;
};

// Iterates the pointer map and appends each valid entry's value to kValuesOut.
// @fnv 0x00d47ce0
void FUN_00d47ce0_class::CollectMapValues(hkArray<int>& kValuesOut) const
{
    for (hkMapIteratorD47C it = m_map.GetFirstIterator(); m_map.isValid(it); it = m_map.getNext(it))
        kValuesOut.pushBack(m_map.getValue(it));
}
}  // namespace fnv_00d47ce0

namespace fnv_00d47d70 {
extern int DAT_010cf7d4;
extern int DAT_010cf804;
extern int DAT_010cf7b0;
extern int DAT_010cf844;
extern const char str_010cf830[];

__forceinline void* AllocateRegistryMemory(hkMemoryRouter* router, int size)
{
    return ((hkMemoryAllocator*)router->m_heap)->blockAlloc(size);
}

extern "C" void __fastcall ReleaseReference(void* ecx);

struct MapHelper
{
    int m00, m04, m08, m0c;
    void FUN_00d87790(int dummy);
};

struct DepthHelper
{
    int d0, d1, d2;
    void EnsureCapacity(hkMemoryAllocator* mem, int zero);
};

struct Obj1
{
    void* vtable;
    short GetAllocationSize;
    short refCount;
    const char* name;
    MapHelper map;
    int unk1c;
};

struct Obj2
{
    void* vtable;
    short GetAllocationSize;
    short refCount;
    MapHelper map;
    int flag;
};

struct Obj3
{
    void* vtable;
    short GetAllocationSize;
    short refCount;
    DepthHelper depth;
};

}  // namespace fnv_00d47d70

// @fnv 0x00d47d70
void hkDefaultBuiltinTypeRegistry::InitGlobalObjects()
{
    using namespace fnv_00d47d70;
    union
    {
        unsigned int i;
        signed char c;
    } u;

    Obj1* p;
    p = (Obj1*)AllocateRegistryMemory(hkMemoryRouter_getInstance(), 0x20);
    p->GetAllocationSize = 0x20;
    p->refCount = 1;
    p->vtable = &DAT_010cf7d4;
    p->name = str_010cf830;
    u.c = 0;
    p->map.FUN_00d87790(u.i);
    p->vtable = &DAT_010cf804;

    if (DAT_01269b14)
    {
        ReleaseReference((void*)DAT_01269b14);
    }
    DAT_01269b14 = (int)p;

    Obj2* n;
    n = (Obj2*)AllocateRegistryMemory(hkMemoryRouter_getInstance(), 0x1c);
    n->GetAllocationSize = 0x1c;
    n->refCount = 1;
    u.c = 0;
    n->vtable = &DAT_010cf7b0;
    n->map.FUN_00d87790(u.i);
    n->flag = 1;

    if (DAT_01269b18)
    {
        ReleaseReference((void*)DAT_01269b18);
    }
    DAT_01269b18 = (int)n;

    Obj3* kIter;
    kIter = (Obj3*)AllocateRegistryMemory(hkMemoryRouter_getInstance(), 0x14);
    kIter->GetAllocationSize = 0x14;
    kIter->refCount = 1;
    kIter->vtable = &DAT_010cf844;
    DepthHelper* pDepth;
    pDepth = &kIter->depth;
    pDepth->d0 = 0;
    pDepth->d1 = 0;
    pDepth->d2 = -1;
    hkMemoryRouter* r = hkMemoryRouter_getInstance();
    pDepth->EnsureCapacity((hkMemoryAllocator*)r->m_heap, 0);

    if (DAT_01269b10)
    {
        ReleaseReference((void*)DAT_01269b10);
    }
    DAT_01269b10 = (int)kIter;

    RegisterBuiltinTypes();
}

namespace fnv_00d47eb0 {
class hkpEntityD47E;

class hkpEntitySourceD47E
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void GetEntities(hkArray<hkpEntityD47E*>& kEntitiesOut) throw();
};

class hkpEntityContainerD47E
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void RegisterEntity(hkpEntityD47E* pkEntity, int iFlags) throw();

    void AddEntitiesFromSource(hkpEntitySourceD47E* pkSource) throw();
};

// Collects entities from pkSource into a local array and adds each one to this container with flags 0.
// @fnv 0x00d47eb0
void hkpEntityContainerD47E::AddEntitiesFromSource(hkpEntitySourceD47E* pkSource) throw()
{
    hkArray<hkpEntityD47E*> kEntities;
    pkSource->GetEntities(kEntities);
    for (int i = 0; i < kEntities.m_iElementCount; i++)
        RegisterEntity(kEntities.m_data[i], 0);
}
}  // namespace fnv_00d47eb0

class hkMemberD47B
{
  public:
    int unk00;
    void FreeBuffer() throw();
};

class hkObjectD47B : public hkReferencedObject
{
  public:
    hkMemberD47B m_kMemberDescriptor;

    hkObjectD47B* FUN_00d47b70(unsigned int uiFlags) throw();
};

// Frees the member buffer, runs the base destructor, and optionally deallocates the object when uiFlags has bit 0 set.
// @fnv 0x00d47b70
hkObjectD47B* hkObjectD47B::FUN_00d47b70(unsigned int uiFlags) throw()
{
    m_kMemberDescriptor.FreeBuffer();
    this->hkReferencedObject::~hkReferencedObject();
    if (uiFlags & 1)
        hkReferencedObject::operator delete(this);
    return this;
}

// @fnv 0x00d47860
struct DefaultNameRegistry
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
    virtual void registerName(const void* name);
};
struct RuntimeTypeInfoRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void registerType(void* typeInfo);
};
struct NameRegistryTable
{
    void hkVtableClassRegistry_registerList(void** entries, void* info);
};
extern int DAT_01268b0c;
extern void* DAT_010d5430[];
extern int DAT_010d59b8;
void hkDefaultBuiltinTypeRegistry::RegisterBuiltinTypes()
{
    DefaultNameRegistry* reg = (DefaultNameRegistry*)DAT_01269b14;
    reg->registerName(&DAT_01268b0c);
    RuntimeTypeInfoRegistry* types = (RuntimeTypeInfoRegistry*)DAT_01269b18;
    void** curr = DAT_010d5430;
    while (*curr)
    {
        types->registerType(*curr);
        ++curr;
    }
    ((NameRegistryTable*)DAT_01269b10)->hkVtableClassRegistry_registerList(DAT_010d5430, &DAT_010d59b8);
}
