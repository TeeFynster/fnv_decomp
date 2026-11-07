
// src/havok/common/serialize/resourcedatabase/hkresourcehandle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/resourcedatabase/hkresourcehandle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/MemoryManager.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkStringBuf.h"
#include "../../../../../include/hkResourceHandle.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkMemoryAllocator.h"

__declspec(nothrow) __forceinline hkStringPtr::hkStringPtr()
{
    Init();
}

// The shared string declaration is potentially throwing.  This unit's inline
// destructor delegates to the original string release routine without unwinding.
__declspec(nothrow) inline hkStringPtr::~hkStringPtr()
{
    release();
}



inline void* operator new(unsigned int, void* p)
{
    return p;
}

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();
// This unit's reserve helper is nonthrowing; hkArrayUtil::_reserve is not.
void __cdecl ReserveResourceArray(hkMemoryAllocator&, void*, int, int) throw();

inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return *reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_heap);
}
inline hkMemoryAllocator& hkContainerTempAllocator::get(void*)
{
    return *reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_temp);
}

template <typename T> __forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& item, hkTypeIsPod)
{
    for (int i = 0; i < n; ++i)
        p[i] = item;
}

template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int doubled = 2 * capacity;
        int newSize = (n < doubled) ? doubled : n;
        ReserveResourceArray(alloc, this, newSize, sizeof(T));
    }
}

template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}

template <typename T> __forceinline void hkArrayUtil::destruct(T* p, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}

template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkMemoryAllocator& alloc = A().get(this);
    hkArrayUtil::destruct(this->m_data, this->m_iElementCount, hkTypeIsClass());
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}

struct FUN_00e2df60_class
{
    int __thiscall hkMemoryResourceContainer_getName(int);
};

// @fnv 0x00e2df60
// src: HAVOK_SRC 0x00e2df60
int __thiscall FUN_00e2df60_class::hkMemoryResourceContainer_getName(int)
{
    return *(int*)((char*)this + 8) & 0xfffffffe;
}

extern int DAT_010eb19c;
void __cdecl Deallocate(void*);
struct FUN_00e2def0_class
{
    void* m_p;
    int __thiscall InitAndMaybeFree(int flags);
};
// @fnv 0x00e2def0
int __thiscall FUN_00e2def0_class::InitAndMaybeFree(int flags)
{
    m_p = &DAT_010eb19c;
    if (flags & 1)
        Deallocate(this);
    return (int)this;
}

struct FUN_00e2df40_class
{
    const char* __thiscall hkMemoryResourceHandle_getName(int);
};

// @fnv 0x00e2df40
// src: HAVOK_SRC 0x00e2df40
const char* __thiscall FUN_00e2df40_class::hkMemoryResourceHandle_getName(int)
{
    int v = *(const int*)(this + 0xc) & 0xfffffffe;
    return v ? reinterpret_cast<const char*>(v) : "null";
}

struct D481D0RefVariant
{
    const void* GetVariantValue() const;
};
// @fnv 0x00e2df20
// src: HAVOK_SRC 0x00e2df20
const void* __fastcall hkMemoryResourceHandle_getClass(char* self, int)
{
    return reinterpret_cast<D481D0RefVariant*>(self + 8)->GetVariantValue();
}

namespace fnv_00e2df30 {
struct D481D0Class;
struct D481D0RefVariant
{
    void set(hkReferencedObject*, D481D0Class const*);
};

struct FUN_00e2df30_class
{
    void hkMemoryResourceHandle_setObject(hkReferencedObject* obj, D481D0Class const* cls);
};

// @fnv 0x00e2df30
// src: HAVOK_SRC 0x00e2df30
void FUN_00e2df30_class::hkMemoryResourceHandle_setObject(hkReferencedObject* obj, D481D0Class const* cls)
{
    ((D481D0RefVariant*)((char*)this + 8))->set(obj, cls);
}
}  // namespace fnv_00e2df30

struct FUN_00d479e0_class
{
    void* GetValue(void const*, int);
};

struct FUN_00e2df80_obj
{
    virtual int FUN_00e2df80_v00();
    virtual int FUN_00e2df80_v04();
    virtual int FUN_00e2df80_v08();
    virtual int FUN_00e2df80_v0c();
    virtual int FUN_00e2df80_v10();
    virtual int FUN_00e2df80_v14();
    virtual int FUN_00e2df80_v18();
    virtual int FUN_00e2df80_v1c();
};

struct FUN_00e2df80_class
{
    int __thiscall hkContainerResourceMap_findObjectByName(void* a, int* out);
};

// Clears *out, looks up an object via the helper at this+4, and if found stores its v1c() result in *out and returns its v18() result.
// @fnv 0x00e2df80
// src: XBOX_PDB 0x00e2df80
int __thiscall FUN_00e2df80_class::hkContainerResourceMap_findObjectByName(void* apKey, int* piOut)
{
    if (piOut)
        *piOut = 0;
    FUN_00e2df80_obj* obj = (FUN_00e2df80_obj*)((FUN_00d479e0_class*)((char*)this + 4))->GetValue(apKey, 0);
    if (!obj)
        return 0;
    if (piOut)
        *piOut = obj->FUN_00e2df80_v1c();
    return obj->FUN_00e2df80_v18();
}

extern int DAT_010eb288;
struct FUN_00e2ea20_class
{
    int m_p;
    int m_kPointA;
    int m_kPointB;
    hkStringPtr m_h;
    FUN_00e2ea20_class* hkaMeshBinding_hkaMeshBinding(int a);
};
// @fnv 0x00e2ea20
// src: HAVOK_LIB 0x00e2ea20
FUN_00e2ea20_class* FUN_00e2ea20_class::hkaMeshBinding_hkaMeshBinding(int aiValue)
{
    m_p = (int)&DAT_010eb288;
    m_h.hkStringPtr::hkStringPtr(FinishingFlag(aiValue));
    return this;
}

struct S_00e028e0_Base
{
    ~S_00e028e0_Base();
};

struct FUN_00e2f1e0_class
{
    void* m_p;
    S_00e028e0_Base m_base;
    void* __thiscall Destroy(int flags);
};

// @fnv 0x00e2f1e0
void* __thiscall FUN_00e2f1e0_class::Destroy(int flags)
{
    m_base.~S_00e028e0_Base();
    m_p = &DAT_010eb19c;
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00e2ea40_class
{
    virtual void FUN_00e2ea40();
};

struct FUN_00e2f210_manager
{
    virtual void unused();
    virtual void unused2();
    virtual void __thiscall release(void* resource, unsigned short handle);
};

hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00e2f210_class : public FUN_00e2ea40_class
{
    unsigned short m_handle;
    void* __thiscall FUN_00e2f210(unsigned int flags);
};

// Runs the base constructor, and if flags has bit 0 set, releases m_handle through the memory router's manager, then returns this.
// @fnv 0x00e2f210
void* FUN_00e2f210_class::FUN_00e2f210(unsigned int flags)
{
    FUN_00e2ea40_class::FUN_00e2ea40();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        reinterpret_cast<FUN_00e2f210_manager*>(router->m_heap)->release(this, m_handle);
    }

    return this;
}

namespace fnv_00e2f240 {
struct FUN_00e2ec00_class
{
    void ClearItems();
};

struct FUN_00e2f240_manager_class
{
    virtual void FUN_00e2f240_virtual_0();
    virtual void FUN_00e2f240_virtual_1();
    virtual void __thiscall FUN_00e2f240_free(void*, unsigned short);
};

hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00e2f240_class : public FUN_00e2ec00_class
{
    unsigned char m_auiShapeKeys[4];
    unsigned short m_iElementCount;

    void* __thiscall FUN_00e2f240(int flags);
};

// @fnv 0x00e2f240
void* FUN_00e2f240_class::FUN_00e2f240(int flags)
{
    this->ClearItems();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        reinterpret_cast<FUN_00e2f240_manager_class*>(router->m_heap)->FUN_00e2f240_free(this, m_iElementCount);
    }

    return this;
}
}  // namespace fnv_00e2f240

struct FUN_00e2df50_Obj
{
    int unk00;
    int unk04;
    int unk08;

    int GetUnk08();
};

// @fnv 0x00e2df50
// src: GUESS 0x00e2df50 (confidence: low)
int FUN_00e2df50_Obj::GetUnk08()
{
    return unk08;
}

struct FnvCpu_FUN_00e2df70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    int value;
    int GetValue();
};
// @fnv 0x00e2df70
// src: GUESS 0x00e2df70 (confidence: low)
int FnvCpu_FUN_00e2df70_CpuObject::GetValue()
{
    return value;
}

struct FNVEntry
{
    int unk00;
    int unk04;
    unsigned int taggedType;
};
int __cdecl hkString_strCmp(const void* filter, const void* tagged);
struct FNVEntryCollection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FNVEntry** items;
    int count;

    FNVEntry* __thiscall hkMemoryResourceContainer_findContainerByName(const void* filter, FNVEntry* previous);
};
// @fnv 0x00e2dfd0
// src: HAVOK_SRC 0x00e2dfd0
FNVEntry* __thiscall FNVEntryCollection::hkMemoryResourceContainer_findContainerByName(const void* filter, FNVEntry* previous)
{
    int index = 0;
    FNVEntry** ppSlot = 0;
    while (previous && index < count && (ppSlot = &items[index++], *ppSlot != previous))
    {
    }

    for (int next = index; next < count; ++next)
    {
        FNVEntry* item = items[next];
        if (!filter || !hkString_strCmp(filter, reinterpret_cast<const void*>(item->taggedType & ~1u)))
        {
            return item;
        }
    }
    return 0;
}

struct Entry
{
    virtual void m00();
    virtual void m04();
    virtual void m08();
    virtual void m0c();
    virtual void m10();
    virtual void m14();
    virtual void m18();
    virtual void m1c();
    virtual void m20();
    virtual void m24();
    virtual void m28();
    virtual void m2c();
    virtual void m30();
    virtual void process(int);
};
void __stdcall hkResourceContainer_findAllResourceRecursively(hkArrayBase<Entry*>*);
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
// @fnv 0x00e2e960
// src: HAVOK_SRC 0x00e2e960
void __stdcall hkMemoryResourceContainer_tryToResolveLinks(int aiValue)
{
    hkArrayBase<Entry*> a;
    a.m_data = 0;
    a.m_iElementCount = 0;
    a.m_iCapacityState = 0x80000000;
    hkResourceContainer_findAllResourceRecursively(&a);
    for (int i = 0; i < a.m_iElementCount; ++i)
        a.m_data[i]->process(aiValue);
    hkMemoryRouter* pRouter = hkMemoryRouter_getInstance();
    int cap = a.m_iCapacityState;
    {
        MemoryManager* m = reinterpret_cast<MemoryManager*>(pRouter->m_heap);
        a.m_iElementCount = 0;
        if (!(cap & 0x80000000))
        {
            // This router allocator dispatches through slot 0x10; the shared
            // MemoryManager::freeBlock declaration is nonvirtual.
            typedef void (__thiscall* FreeBlock)(MemoryManager*, void*, int);
            (*reinterpret_cast<FreeBlock**>(m))[4](m, a.m_data, (cap & 0x3fffffff) * 4);
        }
    }
}

namespace fnv_00e2ec00 {
extern "C" int DAT_010eb2c4;
extern "C" int DAT_0102e388;
struct MemoryAllocator
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Free(void* address, unsigned int bytes);
};
void* hkMemoryRouter_getInstance() throw();
struct AnimationResource
{
    int* m_ppVirtualMethodTable;
    int m_04;
    hkStringPtr m_handle;
    int m_0c;
    hkReferencedObject** m_firstItems;
    int m_firstCount;
    int m_firstCapacity;
    hkReferencedObject** m_secondItems;
    int m_secondCount;
    int m_secondCapacity;
    void ClearItems();
};
// @fnv 0x00e2ec00
void AnimationResource::ClearItems()
{
    m_ppVirtualMethodTable = &DAT_010eb2c4;
    hkMemoryRouter* router = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    int count = m_secondCount;
    MemoryAllocator* allocator = reinterpret_cast<MemoryAllocator*>(router->m_heap);
    hkReferencedObject** items = m_secondItems;
    int i = 0;
    while (i < count)
    {
        hkReferencedObject* pItem = items[i];
        if (pItem)
            pItem->removeReference();
        items[i] = 0;
        ++i;
    }
    m_secondCount = 0;
    int capacity = m_secondCapacity;
    if ((capacity & 0x80000000) == 0)
        allocator->Free(m_secondItems, (capacity & 0x3fffffff) * sizeof(hkReferencedObject*));
    m_secondItems = 0;
    m_secondCapacity = 0x80000000;
    router = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    int iFirstCount = m_firstCount;
    allocator = reinterpret_cast<MemoryAllocator*>(router->m_heap);
    hkReferencedObject** pFirstItems = m_firstItems;
    i = 0;
    while (i < iFirstCount)
    {
        hkReferencedObject* pItem = pFirstItems[i];
        if (pItem)
            pItem->removeReference();
        pFirstItems[i] = 0;
        ++i;
    }
    m_firstCount = 0;
    int iFirstCapacity = m_firstCapacity;
    if ((iFirstCapacity & 0x80000000) == 0)
        allocator->Free(m_firstItems, (iFirstCapacity & 0x3fffffff) * sizeof(hkReferencedObject*));
    m_firstItems = 0;
    m_firstCapacity = 0x80000000;
    m_handle.~hkStringPtr();
    m_ppVirtualMethodTable = &DAT_0102e388;
}
}  // namespace fnv_00e2ec00

inline hkMemoryAllocator& ResourceTempAllocator(hkMemoryRouter* router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router->m_temp);
}

__forceinline hkStringBuf::hkStringBuf() throw()
    : m_string(reinterpret_cast<char*>(m_storage), 0, 128)
{
    m_string._setSize(ResourceTempAllocator(hkMemoryRouter_getInstance()), 1);
    m_string[0] = 0;
}

__forceinline hkStringBuf::~hkStringBuf() throw()
{}

namespace fnv_00e2f090 {
inline hkMemoryAllocator& HeapAllocator(hkMemoryRouter* router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
}

class hkNamedTypeE2F0
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual const char* getName(hkStringBuf& kBuf) const throw();
};

}  // namespace fnv_00e2f090

template <> __forceinline hkArray<fnv_00e2f090::hkNamedTypeE2F0*>::~hkArray()
{
    hkMemoryAllocator& alloc = fnv_00e2f090::HeapAllocator(hkMemoryRouter_getInstance());
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(m_data[0]));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

namespace fnv_00e2f090 {

class hkTypeSourceE2F0
{
  public:
    void hkResourceContainer_findAllResourceRecursively(hkArray<hkNamedTypeE2F0*>& kTypesOut) const throw();
};

class FUN_00d87790
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;

    FUN_00d87790(hkBool bIsValid) throw();
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* pcKey, const void* pvValue) throw();
};

template <typename V> class hkStringMapE2F0
{
  public:
    FUN_00d87790 m_map;

    hkStringMapE2F0(hkBool bIsValid = false) : m_map(bIsValid)
    {}
    void insert(const char* pcKey, V val)
    {
        m_map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(pcKey, val);
    }
};

class FUN_00e2f090
{
  public:
    hkStringMapE2F0<hkNamedTypeE2F0*> m_typeFromName;

    FUN_00e2f090(const hkTypeSourceE2F0* pkSource) throw();
    virtual void V0() throw();
};

// Collects the named types from pkSource and inserts each type into m_typeFromName keyed by its name.
// @fnv 0x00e2f090
FUN_00e2f090::FUN_00e2f090(const hkTypeSourceE2F0* pkSource) throw()
{
    hkArray<hkNamedTypeE2F0*> kTypes;
    pkSource->hkResourceContainer_findAllResourceRecursively(kTypes);
    for (int i = 0; i < kTypes.GetLogicalSize(); i++)
    {
        hkNamedTypeE2F0* pkType = kTypes[i];
        // Word-aligned backing preserves this function's original /GS treatment
        // while constructing the actual string buffer and shared inplace array.
        unsigned int storage[sizeof(hkStringBuf) / sizeof(unsigned int)];
        hkStringBuf& kBuf = *new (storage) hkStringBuf;
        kBuf.setEmpty();
        m_typeFromName.insert(pkType->getName(kBuf), pkType);
        kBuf.~hkStringBuf();
    }
}
}  // namespace fnv_00e2f090

// Keep the router lookup before the capacity check and the allocator load inside
// it, as in the original pointer-array append; hkArray::pushBack loads it early.
template <class T> __forceinline void AppendResourceNode(hkArray<T>& out, const T& item)
{
    hkMemoryRouter& router = *hkMemoryRouter_getInstance();
    if (out.m_iElementCount == (out.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router.m_heap, &out, sizeof(T));
    hkArrayUtil::constructWithCopy(out.m_data + out.m_iElementCount, 1, item, hkTypeIsPod());
    out.m_iElementCount++;
}

template <class T> __forceinline void AppendResourceReference(hkArray<T>& out, const T& item) throw()
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    if (out.m_iElementCount == (out.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router->m_heap, &out, sizeof(T));
    new (&out.m_data[out.m_iElementCount]) T(item);
    out.m_iElementCount++;
}

class hkNodeE2E2
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual hkNodeE2E2* vfn_20(int a, int b, hkNodeE2E2* prev);
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual hkNodeE2E2* vfn_34(int a, hkNodeE2E2* prev);

    void hkResourceContainer_findAllResourceRecursively(hkArray<hkNodeE2E2*>& out);
};

// Recursively visits nodes returned by vfn_34 and appends nodes returned by vfn_20 to out.
// @fnv 0x00e2e2e0
// src: XBOX_PDB 0x00e2e2e0
void hkNodeE2E2::hkResourceContainer_findAllResourceRecursively(hkArray<hkNodeE2E2*>& apOutNodes)
{
    for (hkNodeE2E2* child = vfn_34(0, 0); child; child = vfn_34(0, child))
        child->hkResourceContainer_findAllResourceRecursively(apOutNodes);
    for (hkNodeE2E2* item = vfn_20(0, 0, 0); item; item = vfn_20(0, 0, item))
        AppendResourceNode(apOutNodes, item);
}

class hkNodeE2E3
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual hkNodeE2E3* vfn_20(int a, int b, hkNodeE2E3* prev);
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual hkNodeE2E3* vfn_34(int a, hkNodeE2E3* prev);

    void hkResourceContainer_findAllContainersRecursively(hkArray<hkNodeE2E3*>& out);
};

// Appends this node to out, then recursively appends all descendant child nodes via vfn_34.
// @fnv 0x00e2e380
// src: XBOX_PDB 0x00e2e380
void hkNodeE2E3::hkResourceContainer_findAllContainersRecursively(hkArray<hkNodeE2E3*>& out)
{
    AppendResourceNode(out, this);
    for (hkNodeE2E3* child = vfn_34(0, 0); child; child = vfn_34(0, child))
        child->hkResourceContainer_findAllContainersRecursively(out);
}

struct S00e2e3f0_Pair
{
    hkStringPtr m_kPointA;
    hkStringPtr m_kPointB;
};

struct S00e2e3f0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00e2e3f0_Pair* m_aiIndexedValues;
    int m_uiItemCount;
    void hkMemoryResourceHandle_clearExternalLinks();
};

// @fnv 0x00e2e3f0
// src: HAVOK_SRC 0x00e2e3f0
void S00e2e3f0_Obj::hkMemoryResourceHandle_clearExternalLinks()
{
    S00e2e3f0_Pair* p = m_aiIndexedValues;
    int n = m_uiItemCount;
    for (int i = 0; i < n; i++)
    {
        p[i].m_kPointB.~hkStringPtr();
        p[i].m_kPointA.~hkStringPtr();
    }
    m_uiItemCount = 0;
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" int __cdecl hkString_strCmp(const char*, const char*);
inline const char* hkStringPtr::cString() const
{
    return reinterpret_cast<const char*>(reinterpret_cast<unsigned int>(m_pcText) & ~1u);
}

// Two hkStringPtr fields released at 0x00e2e430; shared Pair instead contains two integers.
struct ResourceStringPair
{
    hkStringPtr name, value;
};
__forceinline void CopyWords839(void* destination, const void* source, int words)
{
    const unsigned char* in = static_cast<const unsigned char*>(source);
    unsigned char* out = static_cast<unsigned char*>(destination);
    int i = 0;
    do
    {
        memcpy(out + i * 4, in + i * 4, 4);
        ++i;
    } while (i < words);
}
struct Container839
{
    int unk00, unk04, unk08, unk0C;
    ResourceStringPair* pairs;
    int size, capacity;
    void hkMemoryResourceHandle_removeExternalLink(const char*);
};
// Finds the pair whose name matches name, destroys its strings, decrements size, and copies the last pair into its slot when needed.
// @fnv 0x00e2e430
// src: HAVOK_SRC 0x00e2e430
void Container839::hkMemoryResourceHandle_removeExternalLink(const char* name)
{
    for (int i = 0; i < size; ++i)
    {
        if (hkString_strCmp(pairs[i].name.cString(), name) == 0)
        {
            ResourceStringPair* found = &pairs[i];
            found->value.~hkStringPtr();
            found->name.~hkStringPtr();
            --size;
            if (size != i)
                CopyWords839(&pairs[i], &pairs[size], sizeof(ResourceStringPair) / 4);
            return;
        }
    }
}

struct C
{
    int a, b, c, d;
    void** items;
    int count;
    void RemoveItem(void* item);
};
// Calls FUN_00c90510 on item and searches items; then calls FUN_00c905b0 on item, and if found releases the slot, decrements count, and copies later entries down.
// @fnv 0x00e2e670
void C::RemoveItem(void* item)
{
    if (item)
        reinterpret_cast<hkReferencedObject*>(item)->addReference();
    int index;
    int i = 0;
    if (count > 0)
    {
        void** p = items;
        do
        {
            if (*p == item)
            {
                index = i;
                goto found;
            }
            ++i;
            ++p;
        } while (i < count);
    }
    index = -1;
found:
    if (item)
        reinterpret_cast<hkReferencedObject*>(item)->removeReference();
    if (index > -1)
    {
        void** target = items + index;
        if (*target)
            reinterpret_cast<hkReferencedObject*>(*target)->removeReference();
        *target = 0;
        --count;
        int bytes = (count - index) * 4;
        char* dst = reinterpret_cast<char*>(items + index);
        char* src = reinterpret_cast<char*>(items + index + 1);
        for (int k = 0; k < bytes; k += 4)
            *reinterpret_cast<void**>(dst + k) = *reinterpret_cast<void**>(src + k);
    }
}

template <class T> struct RefPtrE2E710
{
    RefPtrE2E710(T* e) throw() : m_pRetainedObject(e)
    {
        if (e)
            e->addReference();
    }
    ~RefPtrE2E710() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};
template <class T> __forceinline bool operator==(const RefPtrE2E710<T>& a, const RefPtrE2E710<T>& b)
{
    return a.m_pRetainedObject == b.m_pRetainedObject;
}

template <class T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_data[index].~T();
    m_iElementCount--;
    if (m_iElementCount != index)
        *reinterpret_cast<int*>(m_data + index) = *reinterpret_cast<int*>(m_data + m_iElementCount);
}

struct WorldE2E710
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    hkArray<RefPtrE2E710<hkReferencedObject> > m_kThirdFollowingStreamField;
    void RemoveObject(hkReferencedObject* pkObject);
};

// Finds pkObject in m_kThirdFollowingStreamField and removes it from the array if found.
// @fnv 0x00e2e710
void WorldE2E710::RemoveObject(hkReferencedObject* pkObject)
{
    int iIndex = m_kThirdFollowingStreamField.indexOf(pkObject);
    if (iIndex > -1)
        m_kThirdFollowingStreamField.removeAt(iIndex);
}

struct FUN_00e2e9e0_class
{
    void* m_class;
    unsigned short unk04;
    volatile unsigned short m_handle;
    volatile int m_iObjectReferenceCount;
    hkStringPtr m_target;
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_flags;

    void* __thiscall Ctor();
};

extern int DAT_010eb288;

// Initializes the object handle, class pointer, reference count, target, and flags, then returns this.
// @fnv 0x00e2e9e0
void* __thiscall FUN_00e2e9e0_class::Ctor()
{
    m_handle = 1;
    m_class = &DAT_010eb288;
    m_iObjectReferenceCount = 0;
    m_target.Init();
    m_uiStandInValue = 0;
    m_iValueAfterStandIn = 0;
    m_flags = 0x80000000;
    return this;
}

extern int DAT_010eb2c4;
// The shared string header has no const-char constructor; retain its call here.
void __cdecl ConstructResourceName(hkStringPtr*, const char*);

struct ResourceArrays
{
    int m_iValue;
    hkArray<int> m_kFirst;
    hkArray<int> m_kSecond;
    ResourceArrays() : m_iValue(0)
    {}
};

struct FUN_00e2eb70 : public hkReferencedObject
{
    FUN_00e2eb70* Init(const char* pcName) throw();
    virtual ~FUN_00e2eb70() throw();
    hkStringPtr m_kName;
    ResourceArrays m_arrays;
};

// Constructs the object, storing pcName in m_kName and initialising m_iValue to 0.
// @fnv 0x00e2eb70
FUN_00e2eb70* FUN_00e2eb70::Init(const char* pcName) throw()
{
    m_sReferenceCount = 1;
    *reinterpret_cast<void**>(this) = &DAT_010eb2c4;
    reinterpret_cast<void (__thiscall*)(hkStringPtr*, const char*)>(ConstructResourceName)(&m_kName, pcName);
    // MSVC supports explicit construction of this member without a placement-new null check.
    m_arrays.ResourceArrays::ResourceArrays();
    return this;
}

extern int DAT_010eb2c4;

struct Item_e2ebc0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct F_e2ebc0
{
    int v;
};

struct FUN_00e2ebc0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Item_e2ebc0** items;
    int itemCount;
    FUN_00e2ebc0_class* Init(F_e2ebc0 flags);
};

// Initializes the object by setting unk00 to DAT_010eb2c4, calling FUN_00cb0a70 with flags.v, and back-linking items when flags.v is set.
// @fnv 0x00e2ebc0
FUN_00e2ebc0_class* FUN_00e2ebc0_class::Init(F_e2ebc0 flags)
{
    unk00 = (int)&DAT_010eb2c4;
    reinterpret_cast<hkStringPtr*>((char*)this + 8)->hkStringPtr::hkStringPtr(FinishingFlag(flags.v));
    if (flags.v)
    {
        for (int i = 0; i < itemCount; ++i)
            items[i]->unk0c = (int)this;
    }
    return this;
}


struct Heap_e2ef
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int nbytes) throw();
};
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement) throw();

inline Heap_e2ef& ResourceHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<Heap_e2ef*>(router.m_heap);
}

struct Container_e2ef;

struct Resource_e2ef
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08;
    Container_e2ef* m_parent;
    static void* operator new(unsigned int nbytes) throw()
    {
        Resource_e2ef* p = (Resource_e2ef*)ResourceHeap(*hkMemoryRouter_getInstance()).AllocateMemoryBlock(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    Resource_e2ef* FUN_00e2eb70(const char* name) throw();
    int unk10, unk14, unk18, unk1C, unk20, unk24;
};

template <class T> struct hkRefPtr_e2ef
{
    T* m_pRetainedObject;
    hkRefPtr_e2ef(T* p) throw() : m_pRetainedObject(p)
    {
        if (m_pRetainedObject)
            reinterpret_cast<hkReferencedObject*>(m_pRetainedObject)->addReference();
    }
    hkRefPtr_e2ef(const hkRefPtr_e2ef& o) throw()
    {
        if (o.m_pRetainedObject)
            reinterpret_cast<hkReferencedObject*>(o.m_pRetainedObject)->addReference();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    ~hkRefPtr_e2ef() throw()
    {
        if (m_pRetainedObject)
            reinterpret_cast<hkReferencedObject*>(m_pRetainedObject)->removeReference();
    }
};

struct Container_e2ef
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual Resource_e2ef* findResource(const char* name, int flags);
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    hkArray<hkRefPtr_e2ef<Resource_e2ef> > m_kResources;
    Resource_e2ef* hkMemoryResourceContainer_createContainer(const char* name);
};

// Looks up a resource by name, and if missing, allocates one via FUN_00e2eb70, adds it to m_kResources, sets m_parent, and returns it.
// @fnv 0x00e2efe0
// src: HAVOK_SRC 0x00e2efe0
Resource_e2ef* Container_e2ef::hkMemoryResourceContainer_createContainer(const char* name)
{
    Resource_e2ef* found = findResource(name, 0);
    if (found)
        return found;
    Resource_e2ef* resource = ((Resource_e2ef*)Resource_e2ef::operator new(sizeof(Resource_e2ef)))->FUN_00e2eb70(name);
    AppendResourceReference(m_kResources, hkRefPtr_e2ef<Resource_e2ef>(resource));
    resource->m_parent = this;
    reinterpret_cast<hkReferencedObject*>(resource)->removeReference();
    return resource;
}

namespace fnv_00e2ea40 {
namespace hkE2EA {

template <class T> class ReferenceCountedPointer
{
  public:
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
            reinterpret_cast<hkReferencedObject*>(m_pRetainedObject)->removeReference();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};

struct ExternalLink
{
    ::hkStringPtr m_kLinkName;
    ::hkStringPtr m_kClassName;
};
}

namespace FUN_00e2ea40 {
class hkMemoryResourceHandle : public ::hkReferencedObject
{
  public:
    virtual ~hkMemoryResourceHandle() throw();

    hkE2EA::ReferenceCountedPointer<::hkReferencedObject> m_pReferencedResource;
    ::hkStringPtr m_name;
    ::hkArray<hkE2EA::ExternalLink> m_kExternalLinks;
};

// Destructor for hkMemoryResourceHandle; body is empty so members are destroyed by their own destructors.
// @fnv 0x00e2ea40
hkMemoryResourceHandle::~hkMemoryResourceHandle() throw()
{}
}
}  // namespace fnv_00e2ea40

namespace fnv_00e2eae0 {
struct FUN_00e2eae0_Result
{
    void __thiscall UpdateFields_00e2eae0(int* param);
};

struct FUN_00e2eae0_class
{
    virtual void* vf00();
    virtual void* vf04();
    virtual void* vf08();
    virtual void* vf0c();
    virtual void* vf10(void* arg);
    virtual void* vf14();
    virtual void* vf18();
    virtual void* vf1c();
    virtual void* vf20();
    virtual FUN_00e2eae0_Result* vf24();
    void __thiscall UpdateFields_00e2eae0(int* param);
};

struct FUN_00d61df0_Obj
{
    void __thiscall FUN_00d61df0(void* value);
};

struct FUN_00c85750_Object
{
    virtual void* vf00();
    virtual void* vf04();
    virtual void* vf08();
    virtual void* vf0c();
    virtual void vf10(void* arg1, int arg2);
};

extern int DAT_01063cbc;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

// Calls vf24 and vf10, sends two values to the object at param, then conditionally calls allocator->vf10.
// @fnv 0x00e2eae0
// src: GUESS 0x00e2eae0 (confidence: low)
void __thiscall FUN_00e2eae0_class::UpdateFields_00e2eae0(int* apTarget)
{
    FUN_00e2eae0_Result* result = vf24();
    if (result != 0)
    {
        result->UpdateFields_00e2eae0(apTarget);
    }

    // The original uses the out-of-line initializer and explicit cleanup here.
    unsigned int storage[sizeof(hkStringBuf) / sizeof(unsigned int)];
    hkStringBuf& local = *reinterpret_cast<hkStringBuf*>(storage);
    local.InitBuffer();

    void* value = vf10(&local);

    FUN_00d61df0_Obj* target = (FUN_00d61df0_Obj*)apTarget;
    target->FUN_00d61df0(&DAT_01063cbc);
    target->FUN_00d61df0(value);

    FUN_00c85750_Object* allocator = reinterpret_cast<FUN_00c85750_Object*>(hkMemoryRouter_getInstance()->m_temp);
    int handle = local.m_string.m_iCapacityState;
    local.m_string.m_iElementCount = 0;
    if ((handle & 0x80000000u) == 0)
    {
        allocator->vf10(local.m_string.m_data, handle & 0x3fffffff);
    }
}
}  // namespace fnv_00e2eae0

struct ExternalLinkPair
{
    hkStringPtr memberName;
    hkStringPtr externalId;
};

extern void __cdecl ResizeAudioStream(MemoryManager*, void*, int);

struct ExternalLinkHandle : hkResourceHandle
{
    void* object;
    hkStringPtr name;
    hkArray<ExternalLinkPair> references;
    void hkMemoryResourceHandle_addExternalLink(const char* memberName, const char* externalId);
};

// Appends a new ExternalLinkPair with the given memberName and externalId to the references array, growing capacity if needed.
// @fnv 0x00e2e040
// src: HAVOK_SRC 0x00e2e040
void ExternalLinkHandle::hkMemoryResourceHandle_addExternalLink(const char* memberName, const char* externalId)
{
    hkArray<ExternalLinkPair>* links = &references;
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    if (links->m_iElementCount == (links->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(reinterpret_cast<MemoryManager*>(router->m_heap), links, sizeof(ExternalLinkPair));
    ExternalLinkPair* link = &links->m_data[links->m_iElementCount];
    if (link)
        new (link) ExternalLinkPair();
    link = &links->m_data[links->m_iElementCount];
    links->m_iElementCount++;
    link->memberName = memberName;
    link->externalId = externalId;
}

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();
struct ObjQ_e2e9e0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void FUN_00e2e9e0_v14(void* a);
    virtual void v18();
    virtual void v1c();
    virtual void FUN_00e2e9e0_v20(void* a, void* b);
    unsigned short m_usMemSizeAndFlags;
    void* Ctor();
};
struct FUN_00e2ed00_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkArray<ObjQ_e2e9e0*> unk10;
    ObjQ_e2e9e0* hkMemoryResourceContainer_createResource(void* p0, void* p1, void* p2);
};
// Allocates an ObjQ_e2e9e0, initializes it with p0, p1, p2, and appends it to the hkArray<ObjQ_e2e9e0*> array at unk10.
// @fnv 0x00e2ed00
// src: HAVOK_SRC 0x00e2ed00
ObjQ_e2e9e0* FUN_00e2ed00_class::hkMemoryResourceContainer_createResource(void* p0, void* apArg1, void* apArg2)
{
    ObjQ_e2e9e0* obj = (ObjQ_e2e9e0*)ResourceHeap(*hkMemoryRouter_getInstance()).AllocateMemoryBlock(0x1c);
    obj->m_usMemSizeAndFlags = 0x1c;
    obj = (ObjQ_e2e9e0*)obj->Ctor();
    obj->FUN_00e2e9e0_v14(p0);
    obj->FUN_00e2e9e0_v20(apArg1, apArg2);
    ((hkReferencedObject*)obj)->addReference();
    hkArray<ObjQ_e2e9e0*>* arr = &this->unk10;
    hkMemoryRouter& audio2 = *hkMemoryRouter_getInstance();
    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(audio2.m_heap, arr, 4);
    ObjQ_e2e9e0** slot = arr->m_data + arr->m_iElementCount;
    if (slot != 0)
    {
        ((hkReferencedObject*)obj)->addReference();
        *slot = obj;
    }
    arr->m_iElementCount++;
    ((hkReferencedObject*)obj)->removeReference();
    ((hkReferencedObject*)obj)->removeReference();
    return obj;
}
