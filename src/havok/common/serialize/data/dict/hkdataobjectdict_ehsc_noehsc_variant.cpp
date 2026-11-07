#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkHalf.h"
#include "../../../../../../include/hkClassMember.h"
#include "../../../../../../include/hkClass.h"
#include "../../../../../../include/hkDataArrayImpl.h"
#include "../../../../../../include/hkVariant.h"
#include "../../../../../../include/Pair.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkDataClassDict.h"


// src/havok/common/serialize/data/dict/hkdataobjectdict_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/data/dict/hkdataobjectdict.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/data/dict/hkdataobjectdict.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/dict/hkdataobjectdict.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

struct hkAllocX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& numBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);

    template <typename T> __forceinline T* _bufAlloc(int& numInOut)
    {
        if (numInOut)
        {
            int numBytes = numInOut * sizeof(T);
            void* p = AllocateBufferWithSize(numBytes);
            numInOut = numBytes / (int)sizeof(T);
            return static_cast<T*>(p);
        }
        return 0;
    }
};

struct hkRouterX
{
    void* m_aiEntries;
    void* unk04;
    void* unk08;
    hkAllocX* m_pTemp;
    hkAllocX* m_pStreamAllocator;
    hkAllocX& temp()
    {
        return *m_pTemp;
    }
    hkAllocX& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" void* hkMemoryRouter_getInstance() throw();

static __forceinline hkRouterX& getRouterX()
{
    return *reinterpret_cast<hkRouterX*>(hkMemoryRouter_getInstance());
}

void __cdecl hkArrayUtil__reserve(hkAllocX& alloc, void* array, int numElem, int sizeElem) throw();

template <typename T> struct hkHeapArrXLocalForm
{ // local form of hkArray: 0x00dc85a0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkHeapArrXLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkHeapArrXLocalForm()
    {
        _clearAndDeallocate(getRouterX().heap());
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _clearAndDeallocate(hkAllocX& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(hkAllocX& alloc, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int n)
    {
        GrowArrayCapacity(getRouterX().heap(), n);
    }
};

template <typename T> struct hkTempArrX
{ // local form of hkArrayBase: 0x00dc8270 needs temporary allocator construction and ReturnMemory cleanup; hkArrayBase has no owning constructor/destructor.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkTempArrX(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        hkAllocX& alloc = getRouterX().temp();
        T* p = alloc._bufAlloc<T>(n);
        int cap = n ? n : 0x80000000;
        m_data = p;
        m_iElementCount = n;
        m_iCapacityState = cap;
        for (int i = 0; i < n; i++)
            new (p + i) T();
    }
    __forceinline ~hkTempArrX()
    {
        hkAllocX& alloc = getRouterX().temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkMemAllocDC82
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct hkRouterDC82
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemAllocDC82* m_pStreamAllocator;
    hkMemAllocDC82& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterNsDC82 {
extern "C" hkRouterDC82& __cdecl hkMemoryRouter_getInstance() throw();
}

#include "../../../../../../include/hkDataClassImpl.h"

// hkDataRefCounted's class allocator, inlined here: the router heap allocates and the size is recorded at +4.
inline void* hkDataRefCounted::operator new(unsigned int n)
{
    void* p = hkRouterNsDC82::hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(n);
    static_cast<hkDataRefCounted*>(p)->m_memSize = (unsigned short)n;
    return p;
}

struct hkDataMemberInfoX
{
    const char* m_name;
    hkDataClassImpl* m_pOwnerObject;
    int m_type;
    hkDataClassImpl* m_valueClass;
    int m_iFlags;
    hkDataMemberInfoX() : m_name(0), m_pOwnerObject(0), m_type(0), m_valueClass(0), m_iFlags(0)
    {}
};

struct hkDataMemberCinfoX
{
    const char* m_name;
    int m_type;
    const char* m_valueClass;
    int m_iFlags;
};

struct hkDataClassCinfoX
{
    const char* name;
    int version;
    const char* parent;
    hkHeapArrXLocalForm<hkDataMemberCinfoX> members;
};

// Shared hkDataClass.h is absent; calls bind to the wrapper at 0x00dba650-0x00dbaf10.
class hkDataClass
{
  public:
    hkDataClassImpl* m_pClassImpl;

    hkDataClass(hkDataClassImpl* impl) throw();
    ~hkDataClass() throw();
    int GetObjectKind() const throw();
    const char* getName() const throw();
    int GetNumOwnMembers() const throw();
    hkDataClass getParent() const throw();
    int GetNumAllMembers() const throw();
    void GetAllMemberInfo(hkTempArrX<hkDataMemberInfoX>& out) const throw();
};

struct hkRefObjDC82
{
    void addReference() const;
    void removeReference() const;
};

extern hkRefObjDC82 DAT_011b7c00;

template <class T> class hkRefPtrDC82
{
  public:
    hkRefPtrDC82() : m_pRetainedObject(0)
    {}
    hkRefPtrDC82(T* e)
    {
        if (e)
            e->addReference();
        m_pRetainedObject = e;
    }
    ~hkRefPtrDC82()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    void operator=(const hkRefPtrDC82& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->addReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    void operator=(T* e)
    {
        if (e)
            e->addReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};

struct hkHandleDC82
{
    hkHandleDC82()
    {
        DAT_011b7c00.addReference();
        m_pRetainedObject = &DAT_011b7c00;
    }
    void operator=(const hkRefPtrDC82<hkRefObjDC82>& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->addReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    hkRefObjDC82* m_pRetainedObject;
};

// Keep the byte-valued member getters inline; shared getType is out of line.
static __forceinline int GetDataDictMemberType(const hkClassMember& member)
{
    return member.m_type;
}
static __forceinline int GetDataDictMemberSubtype(const hkClassMember& member)
{
    return member.m_eSubtype;
}

struct hkMemberAccessorDC82
{
    void* m_pTargetObject;
    const void* m_kMemberDescriptor;
    hkMemberAccessorDC82(const hkVariant* v, const char* member);
    const char** GetStringPointerAt(int i);
};

// Preserve the inlined reference ownership when setting the shared class's parent.
inline void hkDataClassDict::setParent(hkDataClassDict* p)
{
    if (p)
        p->addReference();
    if (parent)
        parent->removeReference();
    parent = p;
}

struct hkStringMapDC82
{
    void* GetValue(const char* key, void* def);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* key, const char* val);
};

extern "C" char* hkString_strDup_00cb1410(const char* s);
struct hkTrackerDC82
{
    hkStringMapDC82 m_kLookupMap;
    int unk04;
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
    hkStringMapDC82 m_pStringFunctions;

    const char* InternString(const char* s)
    {
        if (s)
        {
            const char* r = (const char*)m_pStringFunctions.GetValue(s, 0);
            if (r == 0)
            {
                r = hkString_strDup_00cb1410(s);
                m_pStringFunctions.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(r, r);
            }
            return r;
        }
        return 0;
    }
    void RegisterObject(hkDataClassDict* c);
    hkRefPtrDC82<hkRefObjDC82> FindOrCreateTypeEntry(const char* name);
};

extern const char* DAT_011b7bfc;
extern "C" char* hkString_strDup_00cb1410(const char* s);
int GetShapeTypeFlags(int type, int subtype, const hkClass* pClassInfo, int count);

// Shared hkDataWorldDict.h is absent; both dictionary-world functions use this tracker at +0x08.
class hkDataWorldDict
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual hkDataClassImpl* newClass(const hkDataClassCinfoX& cinfo);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual hkDataClassImpl* GetClassFromName(const char* name) const;

    void addClassMemberX(hkDataClass& pClassInfo, const char* name, int type, const char* className,
                         int aiFlags) throw();
    hkDataClassImpl* copyClassFromWorld(const char* name, const hkDataWorldDict& worldFrom);
    int m_referenceCounts;
    hkTrackerDC82* m_pTracker;

    hkDataClassDict* FindTrackedClass(const char* name)
    {
        hkStringMapDC82& classes = m_pTracker->m_kLookupMap;
        return name ? (hkDataClassDict*)classes.GetValue(name, 0) : 0;
    }
    const char* internString(const char* s)
    {
        hkTrackerDC82* tracker = m_pTracker;
        return tracker->InternString(s);
    }
    hkDataClassDict* wrapClass(const hkClass& pClassInfo);
};

// @fnv 0x00dc8270
// src: XBOX_PDB 0x00dc8270
hkDataClassDict* hkDataWorldDict::wrapClass(const hkClass& pClassInfo)
{
    hkDataClassDict* c = new hkDataClassDict(this, pClassInfo.FUN_00d46d40(), pClassInfo.FUN_00d47120());
    if (pClassInfo.FUN_00d46d50())
    {
        const hkClass* parent = pClassInfo.FUN_00d46d50();
        hkDataClassDict* p = FindTrackedClass(parent->FUN_00d46d40());
        if (p == 0)
        {
            p = wrapClass(*pClassInfo.FUN_00d46d50());
        }
        c->setParent(p);
    }
    c->addReference();
    m_pTracker->RegisterObject(c);
    for (int i = 0; i < pClassInfo.FUN_00d46f70(); ++i)
    {
        const hkClassMember& m = pClassInfo.FUN_00d46f80(i);
        int type = 0;
        hkHandleDC82 typeName;
        if ((m.m_flags & 0x400) != 0x400)
        {
            type = GetShapeTypeFlags(GetDataDictMemberType(m), GetDataDictMemberSubtype(m), m.getClass(), m.getCstyleArraySize());
            if (m.getClass())
            {
                if (const hkVariant* attr = m.getAttribute_00d86960(DAT_011b7bfc))
                {
                    hkMemberAccessorDC82 acc(attr, "typeName");
                    typeName = m_pTracker->FindOrCreateTypeEntry(*acc.GetStringPointerAt(0));
                }
                else if (const hkVariant* attr = m.getClass()->FUN_00d47260(DAT_011b7bfc))
                {
                    hkMemberAccessorDC82 acc(attr, "typeName");
                    typeName = m_pTracker->FindOrCreateTypeEntry(*acc.GetStringPointerAt(0));
                }
                else
                {
                    typeName = m_pTracker->FindOrCreateTypeEntry(m.getClass()->FUN_00d46d40());
                }
            }
        }
        const char* name = internString(m.m_name);
        hkRefObjDC82* typeObj = typeName.m_pRetainedObject;
        c->FUN_00dc9f20(name, type, typeName, m.getCstyleArraySize());
        if (typeObj)
            typeObj->removeReference();
    }
    return c;
}

// @fnv 0x00dc85a0
// src: XBOX_PDB 0x00dc85a0
hkDataClassImpl* hkDataWorldDict::copyClassFromWorld(const char* name, const hkDataWorldDict& worldFrom)
{
    if (hkDataClassImpl* c = GetClassFromName(name))
        return c;
    hkDataClass klassFrom(worldFrom.GetClassFromName(name));
    hkDataClassCinfoX cinfo;
    cinfo.name = klassFrom.getName();
    cinfo.version = klassFrom.GetNumOwnMembers();
    hkDataClass parent = klassFrom.getParent();
    if (parent.GetObjectKind())
    {
        cinfo.parent = 0;
    }
    else
    {
        cinfo.parent = parent.getName();
        if (hkDataClassImpl* c = GetClassFromName(cinfo.name))
            return c;
    }
    hkDataClassImpl* clsImpl = newClass(cinfo);
    hkTempArrX<hkDataMemberInfoX> minfos(klassFrom.GetNumAllMembers());
    klassFrom.GetAllMemberInfo(minfos);
    cinfo.members.reserve(minfos.GetLogicalSize());
    hkDataClass pClassInfo(clsImpl);
    for (int i = 0; i < minfos.GetLogicalSize(); i++)
    {
        hkDataMemberInfoX& m = minfos[i];
        const char* className = 0;
        if (m.m_valueClass)
        {
            className = m.m_valueClass->getName();
            copyClassFromWorld(className, worldFrom);
        }
        addClassMemberX(pClassInfo, m.m_name, m.m_type, className, m.m_iFlags);
    }
    return clsImpl;
}


// @fnv 0x00dc7d20
void hkDataWorldDict::addClassMemberX(hkDataClass& klass, const char* pcName, int iType,
                                    const char* pcTypeName, int iCount) throw()
{
    hkDataClassDict* pkClass = static_cast<hkDataClassDict*>(klass.m_pClassImpl);
    const char* pcPooled = m_pTracker->InternString(pcName);
    if (pkClass->getDeclaredMemberIndexByName(pcName) != -1)
        pkClass->FUN_00dc9470(pcPooled);
    pkClass->FUN_00dc9f20(pcPooled, iType, m_pTracker->FindOrCreateTypeEntry(pcTypeName), iCount);
}
