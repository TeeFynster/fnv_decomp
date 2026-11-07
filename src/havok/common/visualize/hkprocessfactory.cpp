#include "../../../../include/hkArray.h"

// src/havok/common/visualize/hkprocessfactory.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkprocessfactory.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dd9580_Interface
{
    virtual void unk00();
    virtual void unk04();
    virtual void notify(void*, unsigned short);
};
struct FUN_00dd9580_Service
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00dd9580_Interface* unk10;
};
FUN_00dd9580_Service* __cdecl hkMemoryRouter_getInstance();
struct FUN_00dd9580_Class
{
    void* vtable;
    unsigned short unk04;
    void FUN_00dd94c0();
    FUN_00dd9580_Class* FUN_00dd9580(char flags);
};
// Calls FUN_00dd94c0, then if bit 0 of flags is set notifies the service interface with this and unk04, and returns this.
// @fnv 0x00dd9580
FUN_00dd9580_Class* FUN_00dd9580_Class::FUN_00dd9580(char flags)
{
    FUN_00dd94c0();
    if (flags & 1)
    {
        FUN_00dd9580_Service* service = hkMemoryRouter_getInstance();
        service->unk10->notify(this, unk04);
    }
    return this;
}

extern char DAT_010d7c90[];

struct FUN_00dd9460_Factory
{
    virtual void* unk00();
    virtual void* CreateBuffer(int size);
};

struct FUN_00dd9460_Child
{
    void* Make(int size);
};

class FUN_00dd9460_cls
{
  public:
    void* vtable;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int unk14;
    void* unk18;
    FUN_00dd9460_cls* Initialize();
};

// @fnv 0x00dd9460
FUN_00dd9460_cls* FUN_00dd9460_cls::Initialize()
{
    unk06 = 1;
    vtable = DAT_010d7c90;
    unk08 = 0;
    unk0c = 0;
    unk10 = 0;
    unk14 = 0x80000000u;
    FUN_00dd9580_Service* svc = hkMemoryRouter_getInstance();
    FUN_00dd9460_Factory* f = reinterpret_cast<FUN_00dd9460_Factory*>(svc->unk10);
    void* pBuffer = f->CreateBuffer(0x18);
    if (pBuffer != 0)
    {
        unk18 = reinterpret_cast<FUN_00dd9460_Child*>(pBuffer)->Make(0x7d0);
    }
    else
    {
        unk18 = 0;
    }
    return this;
}

// CreateFactory
// Creates a process object of type 0x1c through the service's interface
// (vtable slot 4), stamps the type into the object's word at +0x04 and
// then runs the object's initialiser (tail call).
struct MyFactory
{
    void* vtable;
    unsigned short unk04;
    MyFactory* init();
};

struct MyInterface
{
    virtual void* v00();
    virtual MyFactory* v04(unsigned int type);
};

// Gets a service, requests a factory of type 0x1c from its interface, sets the factory's unk04 to 0x1c and returns its init() result.
// @fnv 0x00dd9550
MyFactory* CreateFactory()
{
    FUN_00dd9580_Service* service = hkMemoryRouter_getInstance();
    MyInterface* iface = (MyInterface*)service->unk10;
    MyFactory* factory = iface->v04(0x1c);
    factory->unk04 = 0x1c;
    return factory->init();
}

#include <windows.h>
struct S_00dd94c0_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void free(void* p, unsigned short size) throw();
    virtual void unk0c();
    virtual void ReturnMemory(void* p, int bytes) throw();
};
inline S_00dd94c0_Heap& S_00dd94c0_GetHeap()
{
    return *(S_00dd94c0_Heap*)hkMemoryRouter_getInstance()->unk10;
}

struct S_00dd94c0_Entry
{
    int unk00;
    int unk04;
    int unk08;
    void Object_UpdateFields_00cb0c00() throw();
};

typedef hkArrayBase<S_00dd94c0_Entry> S_00dd94c0_Array;
template<> __forceinline void hkArrayBase<S_00dd94c0_Entry>::_clearAndDeallocate(hkMemoryAllocator& sharedAlloc)
{
S_00dd94c0_Heap& h = reinterpret_cast<S_00dd94c0_Heap&>(sharedAlloc);

        
        int n = m_iElementCount;
        S_00dd94c0_Entry* p = m_data;
        for (int i = 0; i < n; i++, p++)
            p->Object_UpdateFields_00cb0c00();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S_00dd94c0_Entry));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}


struct S_00dd94c0_Base
{
    unsigned short m_iElementCount;
    virtual ~S_00dd94c0_Base() throw()
    {}
};

struct FUN_00dd94c0 : S_00dd94c0_Base
{
    int unk08;
    S_00dd94c0_Array m_entries;
    CRITICAL_SECTION* m_lock;
    virtual ~FUN_00dd94c0() throw();
};

// Deletes the critical section, calls notify with the lock and 0x18, then clears m_entries.
// @fnv 0x00dd94c0
FUN_00dd94c0::~FUN_00dd94c0() throw()
{
    CRITICAL_SECTION* lock = m_lock;
    if (lock)
    {
        DeleteCriticalSection(lock);
        FUN_00dd9580_Service* sv = hkMemoryRouter_getInstance();
        sv->unk10->notify(lock, 0x18);
    }
    m_entries._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(S_00dd94c0_GetHeap()));
}

int hkString_strCmp(const char* a, const char* b);

struct S_00dd9380_Allocator;

struct S_00dd9380_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dd9380_Allocator* m_pStreamAllocator;
    S_00dd9380_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00dd9380_StringPtr
{
    unsigned int m_pcText;
    void FUN_00cb0a60();
    void UpdateState_00cb0c10(const char* s);
    const char* cString() const
    {
        return (const char*)(m_pcText & ~1u);
    }
};

inline int S_00dd9380_strCmp(const char* a, const char* b)
{
    if (a)
    {
        if (b)
            return hkString_strCmp(a, b);
        return 1;
    }
    return b ? -1 : 0;
}

struct S_00dd9380_Entry
{
    S_00dd9380_StringPtr m_name;
    int m_uiFilterValue;
    int m_iOwnerObjectOffset;
};

void hkArrayUtil__reserve(S_00dd9380_Allocator& alloc, void* array, int numElem, int sizeElem);

struct S_00dd9380_ArrayLocalForm
{ // local form of hkArray: 0x00dd9380 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    S_00dd9380_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(S_00dd9380_Allocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(S_00dd9380_Entry));
        }
    }
    S_00dd9380_Entry& _expandOne(S_00dd9380_Allocator& alloc)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + 1);
        S_00dd9380_Entry* e = m_data + m_iElementCount;
        if (e)
            e->m_name.FUN_00cb0a60();
        m_iElementCount++;
        return m_data[oldsize];
    }
    S_00dd9380_Entry& AllocatePair()
    {
        return _expandOne(((S_00dd9380_Router*)hkMemoryRouter_getInstance())->heap());
    }
};

struct S_00dd9380
{
    int unk0;
    int unk4;
    int m_nextId;
    S_00dd9380_ArrayLocalForm m_entries;
    CRITICAL_SECTION* m_lock;
    int hkProcessFactory_registerProcess(const char* name, int value);
};

// Finds an entry by name or creates one with the supplied value and next owner offset, then returns its owner offset.
// @fnv 0x00dd9380
// src: HAVOK_LIB 0x00dd9380
int S_00dd9380::hkProcessFactory_registerProcess(const char* name, int value)
{
    EnterCriticalSection(m_lock);
    S_00dd9380_Entry* e = 0;
    for (int i = 0; i < m_entries.m_iElementCount; i++)
    {
        if (S_00dd9380_strCmp(m_entries.m_data[i].m_name.cString(), name) == 0)
        {
            e = &m_entries.m_data[i];
            break;
        }
    }
    if (e == 0)
    {
        e = &m_entries.AllocatePair();
        e->m_name.UpdateState_00cb0c10(name);
        e->m_uiFilterValue = value;
        e->m_iOwnerObjectOffset = m_nextId++;
    }
    LeaveCriticalSection(m_lock);
    return e->m_iOwnerObjectOffset;
}
