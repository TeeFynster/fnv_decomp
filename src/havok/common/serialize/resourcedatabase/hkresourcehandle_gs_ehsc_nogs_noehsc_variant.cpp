
// src/havok/common/serialize/resourcedatabase/hkresourcehandle_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/resourcedatabase/hkresourcehandle.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/resourcedatabase/hkresourcehandle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/resourcedatabase/hkresourcehandle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkResourceHandle.h"
#include "../../../../../include/MemoryManager.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkBoolResult.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkErrStream.h"
#include "../../../../../include/hkStringPtr.h"
struct FUN_00e2df60_class
{
    int __thiscall FUN_00e2df60(int);
};
extern int DAT_010eb19c;
void __cdecl Deallocate(void*);
struct FUN_00e2def0_class
{
    void* m_p;
    int __thiscall InitAndMaybeFree(int flags);
};
struct FUN_00e2df40_class
{
    const char* __thiscall FUN_00e2df40(int);
};
struct D481D0RefVariant
{
    const void* GetVariantValue() const;
};
const void* __fastcall FUN_00e2df20(char* self, int);
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
    int __thiscall FUN_00e2df80(void* a, int* out);
};
extern int DAT_010eb288;
struct FUN_00cb0a70
{
    void m(int);
};
struct FUN_00e2ea20_class
{
    int m_p;
    int m_kPointA;
    int m_kPointB;
    FUN_00cb0a70 m_h;
    FUN_00e2ea20_class* FUN_00e2ea20(int a);
};
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
struct FUN_00e2ea40_class
{
    virtual void FUN_00e2ea40();
};
struct FUN_00e2f210_class : public FUN_00e2ea40_class
{
    unsigned short m_handle;
    void* __thiscall FUN_00e2f210(unsigned int flags);
};
struct FUN_00e2df50_Obj
{
    int unk00;
    int unk04;
    int unk08;

    int FUN_00e2df50();
};
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
    int FUN_00e2df70();
};
struct FNVEntry
{
    int unk00;
    int unk04;
    unsigned int taggedType;
};
int __cdecl FUN_00cb0fa0(const void* filter, const void* tagged);
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

    FNVEntry* __thiscall FUN_00e2dfd0(const void* filter, FNVEntry* previous);
};
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
struct EntryArray
{
    Entry** data;
    int size;
    int capacityAndFlags;
};
void __stdcall FUN_00e2e2e0(EntryArray*);
void __stdcall FUN_00e2e960(int x);

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

    void FUN_00e2e2e0(hkArray<hkNodeE2E2*>& out);
};

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

    void FUN_00e2e380(hkArray<hkNodeE2E3*>& out);
};
struct S00e2e3f0_Pair
{
    int m_kPointA;
    int m_kPointB;
};
struct S00e2e3f0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00e2e3f0_Pair* m_aiIndexedValues;
    int m_uiItemCount;
    void FUN_00e2e3f0();
};
extern "C" __declspec(noinline) void __fastcall FUN_00cb0c00(void* self)
{
    Deallocate(self);
}

// @fnv 0x00e2e3f0
void S00e2e3f0_Obj::FUN_00e2e3f0()
{
    S00e2e3f0_Pair* p = m_aiIndexedValues;
    int n = m_uiItemCount;
    for (int i = 0; i < n; i++)
    {
        FUN_00cb0c00(&p[i].m_kPointB);
        FUN_00cb0c00(&p[i].m_kPointA);
    }
    m_uiItemCount = 0;
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" int __cdecl FUN_00cb0fa0(const char*, const char*);

// Two tagged strings (release at 0x00cb0c00), unlike include/Pair.h's integer/reference pair.
struct ResourceLinkStringPair
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
    ResourceLinkStringPair* pairs;
    int size, capacity;
    void FUN_00e2e430(const char*);
};
struct FUN_00c90510_Class
{
    void FUN_00c90510();
};
struct FUN_00c905b0_Class
{
    void FUN_00c905b0();
};
struct C
{
    int a, b, c, d;
    void** items;
    int count;
    void RemoveItem(void* item);
};
struct ReferencedE2E710
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
template <class T> struct RefPtrE2E710
{
    RefPtrE2E710(T* e) throw() : m_pRetainedObject(e)
    {
        if (e)
            e->FUN_00c90510();
    }
    ~RefPtrE2E710() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};
template <class T> struct ArrayE2E710
{
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i].m_pRetainedObject == t.m_pRetainedObject)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_data[index].~T();
        m_iElementCount--;
        if (m_iElementCount != index)
            *reinterpret_cast<int*>(m_data + index) = *reinterpret_cast<int*>(m_data + m_iElementCount);
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct WorldE2E710
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ArrayE2E710<RefPtrE2E710<ReferencedE2E710> > m_kThirdFollowingStreamField;
    void RemoveObject(ReferencedE2E710* pkObject);
};
struct FUN_00cb0a60_target
{
    void __thiscall FUN_00cb0a60();
};
struct FUN_00e2e9e0_class
{
    void* m_class;
    unsigned short unk04;
    volatile unsigned short m_handle;
    volatile int m_iObjectReferenceCount;
    FUN_00cb0a60_target m_target;
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_flags;

    void* __thiscall Ctor();
};
extern int DAT_010eb288;
struct ReferencedE2EB70
{
    ReferencedE2EB70() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~ReferencedE2EB70() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct NameE2EB70
{
    NameE2EB70(const char* pcName) throw();
    const char* m_pcName;
};
template <class T> struct ArrayE2EB70
{
    ArrayE2EB70() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct FUN_00e2eb70 : public ReferencedE2EB70
{
    FUN_00e2eb70(const char* pcName) throw();
    virtual ~FUN_00e2eb70() throw();
    NameE2EB70 m_kName;
    int m_iValue;
    ArrayE2EB70<int> m_kFirst;
    ArrayE2EB70<int> m_kSecond;
};
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
struct FUN_00cb0a70_Class
{
    void FUN_00cb0a70(int);
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

struct S00e2e0b0_Member;
struct S00e2e0b0_Class
{
    S00e2e0b0_Member* FUN_00d46fe0(const char*);
};
struct S00e2e0b0_Member
{
    const char* unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned short unk0e;
    unsigned short unk10;
    unsigned short unk12;
    S00e2e0b0_Class* FUN_00d86920();
};
struct S00e2e0b0_Ref
{
    void* unk00;
    void* unk04;
    S00e2e0b0_Class* FUN_00d477a0();
};
struct S00e2e0b0_Access
{
    void* unk00;
    void* unk04;
    S00e2e0b0_Access* FUN_00d87180(void*, S00e2e0b0_Member*);
};
struct S00e2e0b0_Output
{
    const char* unk00;
    const char* unk04;
    S00e2e0b0_Access unk08;
};
struct S00e2e0b0_Array
{
    S00e2e0b0_Output* unk00;
    int unk04;
    int unk08;
    void reserve(hkMemoryAllocator& allocator, int count);
    S00e2e0b0_Output* expandByUnchecked(int n)
    {
        int oldSize = unk04;
        unk04 = oldSize + n;
        return unk00 + oldSize;
    }
    void popBack()
    {
        --unk04;
    }
};
struct S00e2e0b0_Entry
{
    unsigned int unk00;
    unsigned int unk04;
};
void FUN_00c908c0(void*, S00e2e0b0_Array*, int, int);
const char* FUN_00cb1140(const char*, int);
void FUN_00cb1260(char*, const char*, int);

struct S00e2e0b0_Error
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void report(int, unsigned int, const char*, const char*, int);
};
extern S00e2e0b0_Error* DAT_01268360;
static __forceinline hkMemoryAllocator& S00e2e0b0_heap(hkMemoryRouter* router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
}
inline void S00e2e0b0_Array::reserve(hkMemoryAllocator& allocator, int count)
{
    int capacity = unk08 & 0x3fffffff;
    if (capacity < count)
    {
        int n = capacity * 2;
        if (count >= n)
            n = count;
        FUN_00c908c0(&allocator, this, n, 16);
    }
}
struct S00e2e0b0_Viewer
{
    int unk00;
    int unk04;
    S00e2e0b0_Ref unk08;
    S00e2e0b0_Entry* unk10;
    int unk14;
    int unk18;
    void FUN_00e2e0b0(S00e2e0b0_Array*);
};
static __forceinline S00e2e0b0_Member* S00e2e0b0_lookup(char*& object, const char*& name, S00e2e0b0_Class* pClassInfo)
{
    char memberName[512];
    const char* dot = FUN_00cb1140(name, '.');
    while (dot)
    {
        int length = dot - name;
        FUN_00cb1260(memberName, name, length);
        memberName[length] = 0;
        name += length + 1;
        S00e2e0b0_Member* member = pClassInfo->FUN_00d46fe0(memberName);
        if (!member)
            return 0;
        if (member->unk0c != 25)
        {
            char message[512];
            hkOstream stream(message, 512);
            stream << "Member is not of type struct : " << memberName;
            DAT_01268360->report(1, 0xf032edfe, message, ".\\ResourceDatabase\\hkResourceHandle.cpp", 128);
            return 0;
        }
        pClassInfo = member->FUN_00d86920();
        object += member->unk12;
        dot = FUN_00cb1140(name, '.');
    }
    return pClassInfo->FUN_00d46fe0(name);
}
// @fnv 0x00e2e0b0
void S00e2e0b0_Viewer::FUN_00e2e0b0(S00e2e0b0_Array* array)
{
    array->unk04 = 0;
    int count = unk14;
    array->reserve(S00e2e0b0_heap((&hkMemoryRouter::getInstance())), count);
    for (int i = 0; i < unk14; ++i)
    {
        const char* name;
        S00e2e0b0_Output* out = array->expandByUnchecked(1);
        name = (const char*)(unk10[i].unk00 & ~1u);
        char* object = (char*)unk08.unk00;
        S00e2e0b0_Member* member = S00e2e0b0_lookup(object, name, unk08.FUN_00d477a0());
        if (member)
        {
            out->unk00 = name;
            S00e2e0b0_Access access;
            out->unk08 = *access.FUN_00d87180(object, member);
            out->unk04 = (const char*)(unk10[i].unk04 & ~1u);
        }
        else
        {
            array->popBack();
            char message[512];
            hkOstream stream(message, 512);
            stream << "Cannot find member : " << name;
            DAT_01268360->report(1, 0xf032edf1, message, ".\\ResourceDatabase\\hkResourceHandle.cpp", 146);
        }
    }
}

namespace fnv_00e2e4c0 {
extern const char str_010eb234[];
extern const char str_010eb20c[];
extern const char str_010eb1c4[];

struct hkClassR
{
    const char* FUN_00d46d40() const;
    hkBoolResult FUN_00d46d80(const hkClassR& other) const;
};

struct hkClassMemberR
{
    const char* m_name;
    const char* getName() const
    {
        return m_name;
    }
    const hkClassR* FUN_00d86920() const;
};

struct hkClassMemberAccessorR
{
    void* m_pTargetObject;
    const hkClassMemberR* m_kMemberDescriptor;
    const hkClassMemberR& FUN_00d87370() const;
    void*& FUN_00d87210(int index);
};

struct LinkR
{
    const char* m_kLinkName;
    const char* m_kClassName;
    hkClassMemberAccessorR m_kMemberAccessor;
};

inline hkMemoryAllocator& heapOf(hkMemoryRouter* r)
{
    return *reinterpret_cast<hkMemoryAllocator*>(r->m_heap);
}

struct LinkArrayLocalForm
{ // local form of hkArray: 0x00e2e4c0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    LinkR* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    LinkArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~LinkArrayLocalForm()
    {
        _clearAndDeallocate(heapOf((&hkMemoryRouter::getInstance())));
    }
    void _clearAndDeallocate(hkMemoryAllocator& a)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(LinkR));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    LinkR& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkErrorR
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* description, const char* file, int line);
};
extern hkErrorR* DAT_01268360;

struct hkResourceContainerR
{
    virtual void* GetContentsPointer(const char* name, const hkClassR** klassOut);
};

struct hkResourceHandleR
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void* GetUnderlyingObject();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void RemoveLink(const char* memberName);
    virtual void GetLinks(LinkArrayLocalForm& linksOut);
    void FUN_00e2e4c0(hkResourceContainerR* container);
};

// @fnv 0x00e2e4c0
void hkResourceHandleR::FUN_00e2e4c0(hkResourceContainerR* container)
{
    LinkArrayLocalForm links;
    GetLinks(links);
    for (int i = links.GetLogicalSize() - 1; i >= 0; i--)
    {
        LinkR& link = links[i];
        const hkClassR* pClassInfo;
        void* object = container->GetContentsPointer(link.m_kClassName, &pClassInfo);
        if (object)
        {
            const hkClassMemberR& member = link.m_kMemberAccessor.FUN_00d87370();
            const hkClassR* expected = member.FUN_00d86920();
            if (!expected->FUN_00d46d80(*pClassInfo) && pClassInfo != expected)
            {
                char assertBuf[512];
                hkOstream ostr(static_cast<void*>(assertBuf), sizeof(assertBuf));
                ostr << str_010eb20c << pClassInfo->FUN_00d46d40() << str_010eb234 << expected->FUN_00d46d40();
                DAT_01268360->message(1, 0xf034ed21, assertBuf, str_010eb1c4, 0xb2);
                continue;
            }
            if (object == GetUnderlyingObject())
                return;
            link.m_kMemberAccessor.FUN_00d87210(0) = object;
            RemoveLink(member.getName());
        }
    }
}
}  // namespace fnv_00e2e4c0

namespace fnv_00e2edb0 {
int __cdecl FUN_00cb0fa0(const char* a, const char* b);

struct hkClassE2
{
    const char* FUN_00d46d40() const;
    hkBoolResult FUN_00d46d80(const hkClassE2* k) const;
};

void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* array, int numElements, int sizeElem);

inline hkMemoryAllocator& heapE2(hkMemoryRouter* router)
{
    // This string buffer uses the allocator slot at 0x0c rather than the stream allocator.
    return *reinterpret_cast<hkMemoryAllocator*>(router->m_temp);
}

struct hkStringBufE2
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_kStorage[128];

    hkStringBufE2()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = (int)0x80000080;
        hkMemoryAllocator& heap = heapE2((&hkMemoryRouter::getInstance()));
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < 1)
        {
            int newCap = cap + cap;
            if (newCap <= 1)
            {
                newCap = 1;
            }
            FUN_00c908c0(&heap, this, newCap, 1);
        }
        m_iElementCount = 1;
        m_data[0] = 0;
        m_data[0] = 0;
    }

    ~hkStringBufE2()
    {
        hkMemoryAllocator& heap = heapE2((&hkMemoryRouter::getInstance()));
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            heap.bufFree(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
};

struct hkResourceHandleE2
{
    virtual void m00();
    virtual void m04();
    virtual void m08();
    virtual void m0c();
    virtual const char* getName(hkStringBufE2& buffer) const;
    virtual void m14();
    virtual void m18();
    virtual const hkClassE2* GetVariantValue() const;
};

struct hkErrorE2
{
    virtual void m00();
    virtual void m04();
    virtual void m08();
    virtual int message(int type, int id, const char* description, const char* file, int line);
};

extern hkErrorE2* DAT_01268360;

typedef hkArrayBase<hkResourceHandleE2*> hkHandleArrayE2;

struct hkMemoryResourceContainerE2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkHandleArrayE2 m_kHandles;

    hkResourceHandleE2* FUN_00e2edb0(const char* objectName, const hkClassE2* pClassInfo,
                                     const hkResourceHandleE2* prevObject);
};

// @fnv 0x00e2edb0
hkResourceHandleE2* hkMemoryResourceContainerE2::FUN_00e2edb0(const char* objectName, const hkClassE2* pClassInfo,
                                                              const hkResourceHandleE2* prevObject)
{
    int start = 0;
    hkResourceHandleE2* const* h;
    while (prevObject && start < m_kHandles.GetLogicalSize() && (h = &m_kHandles.m_data[start++], *h != prevObject))
    {
    }

    for (int i = start; i < m_kHandles.GetLogicalSize(); i++)
    {
        hkResourceHandleE2* handle = m_kHandles[i];
        if (objectName)
        {
            hkStringBufE2 buffer;
            if (FUN_00cb0fa0(objectName, handle->getName(buffer)) != 0)
            {
                continue;
            }
        }
        if (pClassInfo)
        {
            const hkClassE2* handleClass = handle->GetVariantValue();
            if (pClassInfo != handleClass && !pClassInfo->FUN_00d46d80(handleClass).m_cBooleanValue)
            {
                if (objectName)
                {
                    char assertBuf[512];
                    hkOstream ostr(assertBuf, sizeof(assertBuf));
                    ostr.FUN_00cc01c0("Class mismatch, cannot resolve link: ")
                        .FUN_00cc01c0(pClassInfo->FUN_00d46d40())
                        .FUN_00cc01c0(" != ")
                        .FUN_00cc01c0(handleClass->FUN_00d46d40());
                    DAT_01268360->message(1, 0xf034ed22, assertBuf, ".\\ResourceDatabase\\hkResourceHandle.cpp", 0x138);
                    return 0;
                }
                continue;
            }
        }
        return handle;
    }
    return 0;
}
}  // namespace fnv_00e2edb0

void __cdecl hkArrayUtil_reserveMore(hkMemoryAllocator* alloc, void* array, int elemSize) throw();

template <class T> struct hkRefPtrE2E
{
    T* m_pRetainedObject;
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
    __forceinline hkRefPtrE2E(T* e)
    {
        if (e)
            e->RetainReference();
        m_pRetainedObject = e;
    }
    __forceinline ~hkRefPtrE2E()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    __forceinline bool operator==(const hkRefPtrE2E& o) const throw()
    {
        return m_pRetainedObject == o.m_pRetainedObject;
    }
};

template <class T> __forceinline void hkArrayUtil_destruct(T* p, int n) throw()
{
    for (int i = 0; i < n; ++i)
    {
        p[i].~T();
    }
}

__forceinline void hkMemUtil_memCpy(void* dst, const void* src, int nbytes) throw()
{
    for (int i = 0; i < nbytes; i += 4)
    {
        *(int*)((char*)dst + i) = *(const int*)((const char*)src + i);
    }
}

template <class T> struct hkRefArrayE2ELocalForm
{ // local form of hkArray: 0x00e2e790 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkRefPtrE2E<T>* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int indexOf(const hkRefPtrE2E<T>& t) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
            {
                return i;
            }
        }
        return -1;
    }
    __forceinline void removeAtAndCopy(int index) throw()
    {
        hkArrayUtil_destruct(m_data + index, 1);
        m_iElementCount--;
        hkMemUtil_memCpy(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(hkRefPtrE2E<T>));
    }
    __forceinline void AddBack(const hkRefPtrE2E<T>& t) throw()
    {
        hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            hkArrayUtil_reserveMore(reinterpret_cast<hkMemoryAllocator*>(router->m_heap), this, sizeof(hkRefPtrE2E<T>));
        }
        new (m_data + m_iElementCount) hkRefPtrE2E<T>(t.m_pRetainedObject);
        m_iElementCount++;
    }
};

class hkMemoryResourceContainer : public hkResourceBase
{
  public:
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual hkMemoryResourceContainer* getParent() throw();

    __declspec(nothrow) void RetainReference() const throw();
    __declspec(nothrow) void removeReference() const throw();

    int FUN_00e2e790(hkMemoryResourceContainer* newParent);

    hkStringPtr m_name;
    hkMemoryResourceContainer* m_parent;
    hkArray<void*> m_kHandles;
    hkRefArrayE2ELocalForm<hkMemoryResourceContainer> m_children;
};

// @fnv 0x00e2e790
int hkMemoryResourceContainer::FUN_00e2e790(hkMemoryResourceContainer* newParent)
{
    for (hkMemoryResourceContainer* c = newParent; c; c = c->getParent())
    {
        if (c == this)
        {
            char buf[0x200];
            hkErrStream os(buf, sizeof(buf));
            static_cast<hkOstream&>(os) << "Cannot parent '" << m_name << "' to '" << newParent->m_name
               << "' as this would create a circular dependency ";
            DAT_01268360->report(1, 0xabba4554, buf, ".\\ResourceDatabase\\hkResourceHandle.cpp", 0x198);
            return 1;
        }
    }

    RetainReference();
    int index = m_parent->m_children.indexOf(this);
    m_parent->m_children.removeAtAndCopy(index);
    newParent->m_children.AddBack(this);
    m_parent = newParent;
    removeReference();
    return 0;
}
