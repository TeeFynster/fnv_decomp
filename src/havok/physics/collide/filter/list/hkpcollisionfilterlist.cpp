
// src/havok/physics/collide/filter/list/hkpcollisionfilterlist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/list/hkpcollisionfilterlist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkpCollisionFilter.h"

// No shared hkpCollisionFilterList header exists yet; retain its reflected layout.
class hkpCollisionFilterList : public hkpCollisionFilter
{
  public:
    int m_postTypePadding[3]; // Reflected filter array starts at +0x30.
    hkArray<hkpCollisionFilter*> m_kFilters;
};

struct hkBoolRet
{
    char b;
    hkBoolRet(bool val) : b(val)
    {}
};

// Exe 0x00e49cf0: unit-local Interface view; declarations and layout are preserved.
struct HkpcollisionfilterlistInterfaceView
{
    virtual hkBoolRet IsCollisionEnabled(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7) = 0;
};

struct BaseWithVptr
{
    virtual ~BaseWithVptr()
    {}
    int unk04;
    int unk08;
};

struct SubFilter : public BaseWithVptr, public HkpcollisionfilterlistInterfaceView
{
};

class FilterList
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    hkArray<SubFilter*> m_kFilters;

    hkBoolRet hkpCollisionFilterList_isCollisionEnabled_00e49cf0(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
};

// @fnv 0x00e49cf0
// src: HAVOK_LIB 0x00e49cf0
hkBoolRet FilterList::hkpCollisionFilterList_isCollisionEnabled_00e49cf0(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7)
{
    for (int i = m_kFilters.m_iElementCount - 1; i >= 0; --i)
    {
        if (!m_kFilters.m_data[i]->IsCollisionEnabled(a1, a2, a3, a4, a5, a6, a7).b)
        {
            return false;
        }
    }
    return true;
}

struct CheckResult
{
    unsigned char enabled;
    explicit CheckResult(bool value) : enabled(value)
    {}
};

struct FilterPredicate
{
    virtual void unknownMethod();
    virtual CheckResult evaluate(int first, int second);
};

struct FilterEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FilterPredicate predicate;
};

struct FilterChain
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FilterEntry** filters;
    int filterCount;

    CheckResult EvaluateAllFilters(int first, int second);
};

// Evaluates each filter predicate from last to first and returns false as soon as one is disabled, otherwise true.
// @fnv 0x00e49d60
CheckResult FilterChain::EvaluateAllFilters(int first, int second)
{
    for (int index = filterCount - 1; index >= 0; --index)
    {
        if (!filters[index]->predicate.evaluate(first, second).enabled)
        {
            return CheckResult(false);
        }
    }
    return CheckResult(true);
}


struct CollidableA9BC0;
struct CollidableB9BC0;

class CollidableFilter9BC0
{
  public:
    virtual ~CollidableFilter9BC0();
    virtual hkBool IsCollisionEnabled(const CollidableA9BC0& a, const CollidableB9BC0& b) const;
};

class ReferencedObject9BC0
{
  public:
    virtual ~ReferencedObject9BC0();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class CollisionFilter9BC0 : public ReferencedObject9BC0, public CollidableFilter9BC0
{
};


class CollisionFilterList9BC0
{
  public:
    hkBool hkpCollisionFilterList_isCollisionEnabled(const CollidableA9BC0& a, const CollidableB9BC0& b) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    hkArray<CollisionFilter9BC0*> m_kFilters;
};

// Returns true if every filter in m_kFilters reports that collision between a and b is enabled, otherwise false.
// @fnv 0x00e49bc0
// src: HAVOK_LIB 0x00e49bc0
hkBool CollisionFilterList9BC0::hkpCollisionFilterList_isCollisionEnabled(const CollidableA9BC0& a, const CollidableB9BC0& b) const
{
    for (int i = m_kFilters.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (!m_kFilters[i]->IsCollisionEnabled(a, b))
            return false;
    }
    return true;
}

class Iface9C20
{
  public:
    virtual void vpad0();
    virtual hkBool IsCollisionEnabled(const void* p0, const void* p1, const void* p2, const void* p3,
                                          const void* p4) const;
};
class ReferencedObject9C20
{
  public:
    virtual ~ReferencedObject9C20();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class IfacePad9C20_0
{
  public:
    virtual void v();
};
class Filter9C20 : public ReferencedObject9C20, public IfacePad9C20_0, public Iface9C20
{
};
class FilterList9C20
{
  public:
    hkBool hkpCollisionFilterList_isCollisionEnabled_00e49c20(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4) const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    hkArray<Filter9C20*> m_kFilters;
};
// Returns true only if every filter in m_kFilters reports IsCollisionEnabled true for the given arguments.
// @fnv 0x00e49c20
// src: HAVOK_LIB 0x00e49c20
hkBool FilterList9C20::hkpCollisionFilterList_isCollisionEnabled_00e49c20(const void* p0, const void* p1, const void* p2, const void* p3,
                                        const void* p4) const
{
    for (int i = m_kFilters.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (!m_kFilters[i]->IsCollisionEnabled(p0, p1, p2, p3, p4))
            return false;
    }
    return true;
}

class Iface9C90
{
  public:
    virtual hkBool IsCollisionEnabled(const void* p0, const void* p1, const void* p2, const void* p3) const;
};
class ReferencedObject9C90
{
  public:
    virtual ~ReferencedObject9C90();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class IfacePad9C90_0
{
  public:
    virtual void v();
};
class IfacePad9C90_1
{
  public:
    virtual void v();
};
class Filter9C90 : public ReferencedObject9C90, public IfacePad9C90_0, public IfacePad9C90_1, public Iface9C90
{
};
class FilterList9C90
{
  public:
    hkBool hkpCollisionFilterList_isCollisionEnabled_00e49c90(const void* p0, const void* p1, const void* p2, const void* p3) const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkArray<Filter9C90*> m_kFilters;
};
// Returns true only if every filter in m_kFilters reports IsCollisionEnabled true for the given arguments.
// @fnv 0x00e49c90
// src: HAVOK_LIB 0x00e49c90
hkBool FilterList9C90::hkpCollisionFilterList_isCollisionEnabled_00e49c90(const void* p0, const void* p1, const void* p2, const void* p3) const
{
    for (int i = m_kFilters.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (!m_kFilters[i]->IsCollisionEnabled(p0, p1, p2, p3))
            return false;
    }
    return true;
}

struct FUN_00e49dc0_FilterObject
{
    void FUN_00c905b0();
};

struct FUN_00e49dc0_List : public hkpCollisionFilterList
{
    void hkpCollisionFilterList_removeCollisionFilter(hkpCollisionFilter* filter);
};

// Removes the given hkpCollisionFilter from m_kFilters by swapping it with the last element and calling FUN_00c905b0 on it.
// @fnv 0x00e49dc0
// src: HAVOK_LIB 0x00e49dc0
void FUN_00e49dc0_List::hkpCollisionFilterList_removeCollisionFilter(hkpCollisionFilter* filter)
{
    int count = m_kFilters.m_iElementCount;
    int index = 0;

    if (count > 0)
    {
        hkpCollisionFilter** p = m_kFilters.m_data;
        do
        {
            if (*p == filter)
            {
                goto found;
            }
            ++p;
            ++index;
        } while (index < count);
    }
    index = -1;

found:
    volatile int& sz = m_kFilters.m_iElementCount;
    --sz;
    int size = sz;

    if (size != index)
    {
        hkpCollisionFilter** data = m_kFilters.m_data;
        data[index] = data[size];
    }

    ((FUN_00e49dc0_FilterObject*)filter)->FUN_00c905b0();
}

struct AllocatorE49
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* Allocate(int& bytes) throw();
    virtual void Free(void*, int) throw();
};
struct RefE49
{
    virtual ~RefE49() throw();
    unsigned short sizeFlags;
    short references;
    void AddReference() throw();
};
struct CollidableE49
{
    virtual ~CollidableE49() throw();
    virtual void Test();
};
struct CollectionE49
{
    virtual ~CollectionE49() throw();
    virtual void Test();
};
struct RayCollectionE49
{
    virtual ~RayCollectionE49() throw();
    virtual void Test();
};
struct RayCollidableE49
{
    virtual ~RayCollidableE49() throw();
    virtual void Test();
};
struct FilterE49 : RefE49, CollidableE49, CollectionE49, RayCollectionE49, RayCollidableE49
{
    int unk18, unk1c;
    unsigned int type;
    int unk24, unk28, unk2c;
    FilterE49() throw();
};
struct FilterArrayE49
{
    FilterE49** data;
    int size;
    int capacity;
    FilterArrayE49() : data(0), size(0), capacity(0x80000000)
    {}
    static __forceinline void CopyItems(FilterE49** dest, FilterE49* const* src, int count)
    {
        for (int i = 0; i < count; ++i)
            dest[i] = src[i];
    }
    __forceinline void Copy(const FilterArrayE49& source)
    {
        AllocatorE49* heap = reinterpret_cast<AllocatorE49*>(hkMemoryRouter::getInstance().m_heap);
        if ((capacity & 0x3fffffff) < source.size)
        {
            if ((capacity & 0x80000000) == 0)
                heap->Free(data, (capacity & 0x3fffffff) * 4);
            int bytes = source.size * 4;
            data = (FilterE49**)heap->Allocate(bytes);
            capacity = bytes / 4;
        }
        size = source.size;
        CopyItems(data, source.data, size);
    }
};
struct FUN_00e49e50 : FilterE49
{
    FilterArrayE49 filters;
    FUN_00e49e50(const FilterArrayE49& source) throw();
    virtual ~FUN_00e49e50() throw();
};
// Initializes type to 3, copies the source filter array into filters, and adds a reference to each filter element.
// @fnv 0x00e49e50
FUN_00e49e50::FUN_00e49e50(const FilterArrayE49& source) throw()
{
    type = 3;
    filters.Copy(source);
    for (int i = 0; i < filters.size; ++i)
        filters.data[i]->AddReference();
}

struct FilterAllocatorE4
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void DeallocateMemory(void*, int) throw();
};
struct FilterRouterE4
{
    int unk00, unk04, unk08, unk0c;
    FilterAllocatorE4* m_pStreamAllocator;
    FilterAllocatorE4& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
FilterRouterE4* GetFilterRouterE4() throw();
struct FilterRefE4
{
    virtual ~FilterRefE4() throw()
    {}
    unsigned short sizeFlags;
    short references;
    void RemoveReference() throw();
};
struct CollectionFilterE4
{
    virtual ~CollectionFilterE4() throw()
    {}
    virtual void Filter();
};
struct RayCollectionFilterE4
{
    virtual ~RayCollectionFilterE4() throw()
    {}
    virtual void Filter();
};
struct RayCollidableFilterE4
{
    virtual ~RayCollidableFilterE4() throw()
    {}
    virtual void Filter();
};
struct BorderFilterE4
{
    virtual ~BorderFilterE4() throw()
    {}
    virtual void Filter();
};
struct CollisionFilterE4 : FilterRefE4, CollectionFilterE4, RayCollectionFilterE4, RayCollidableFilterE4, BorderFilterE4
{
    int unk18, unk1c;
    unsigned int type;
    int unk24, unk28, unk2c;
};
struct FilterArrayE4
{
    CollisionFilterE4** data;
    int size;
    int capacityAndFlags;
    ~FilterArrayE4() throw()
    {
        FilterAllocatorE4& a = GetFilterRouterE4()->heap();
        size = 0;
        if ((capacityAndFlags & 0x80000000) == 0)
            a.DeallocateMemory(data, (capacityAndFlags & 0x3fffffff) * 4);
        data = 0;
        capacityAndFlags = 0x80000000;
    }
};
struct FUN_00e49f40 : CollisionFilterE4
{
    FilterArrayE4 filters;
    virtual ~FUN_00e49f40() throw();
};
// Releases references to all collision filters held in the filters array.
// @fnv 0x00e49f40
FUN_00e49f40::~FUN_00e49f40() throw()
{
    for (int i = 0; i < filters.size; ++i)
        filters.data[i]->RemoveReference();
}

extern int DAT_0102e388;

class FilterListAE90
{
  public:
    int vftable;
    int unk04;
    FilterRefE4** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void ProcessEntries_00e4ae90();
};

// Releases each FilterRefE4 reference, deallocates m_data, empties the list and sets the vftable pointer to DAT_0102e388.
// @fnv 0x00e4ae90
// src: GUESS 0x00e4ae90 (confidence: low)
void FilterListAE90::ProcessEntries_00e4ae90()
{
    FilterRouterE4* router = GetFilterRouterE4();
    FilterRefE4** data = m_data;
    FilterAllocatorE4* heap = router->m_pStreamAllocator;
    int n = m_iElementCount;
    for (int i = 0; i < n; i++)
    {
        if (data[i])
            data[i]->RemoveReference();
        data[i] = 0;
    }
    int cap = m_iCapacityState;
    m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
    {
        heap->DeallocateMemory(m_data, (cap & 0x3fffffff) * 4);
    }
    m_data = 0;
    m_iCapacityState = (int)0x80000000;
    vftable = (int)&DAT_0102e388;
}
