
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiTPointerMap.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerListBase.h"

void __cdecl operator delete(void*);

struct FUN_004edb30_t
{
    void SetVtableAndProcessState_004edb30();
    void* __thiscall FUN_004edd50(unsigned int flags);
};

// Calls FUN_004edb30, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x004edd50
void* __thiscall FUN_004edb30_t::FUN_004edd50(unsigned int flags)
{
    SetVtableAndProcessState_004edb30();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_010232b4;


struct NiPointerListBase
{
    void* p;
    void* q;
    void __thiscall ReleaseStorage_004edc60();
};

// @fnv 0x004edc60
// src: GUESS 0x004edc60 (confidence: medium)
void __thiscall NiPointerListBase::ReleaseStorage_004edc60()
{
    p = &DAT_010232b4;
    NiTMallocInterface<void*>::Deallocate((void**)q);
}

void __cdecl operator delete(void*);
extern int DAT_010232bc;
struct FUN_004edf70_t
{
    void __thiscall FUN_004edf70(int a, int b);
};
struct FUN_004edc90_t
{
    void* __thiscall NiTPrimitiveArray_enum_BSTextureManager_eTextureType_NiTPrimitiveArray(int a, int b);
};
// Calls FUN_004edf70 with the two arguments, then stores the address of DAT_010232bc as the object's first field and returns this.
// @fnv 0x004edc90
// src: EXE 0x004edc90
void* __thiscall FUN_004edc90_t::NiTPrimitiveArray_enum_BSTextureManager_eTextureType_NiTPrimitiveArray(int a, int b)
{
    reinterpret_cast<FUN_004edf70_t*>(this)->FUN_004edf70(a, b);
    *reinterpret_cast<int**>(this) = &DAT_010232bc;
    return this;
}

class ActorCombatGroup;
namespace fnv_004edcc0 {
void __cdecl operator delete(void*);
extern int DAT_010232c4;
struct FUN_004edcc0_t
{
    void* m;
    void __thiscall InitAndDeallocate();
};
// Sets m to the address of DAT_010232c4, then deallocates the pointer stored just past this via NiTMallocInterface::Deallocate.
// @fnv 0x004edcc0
void __thiscall FUN_004edcc0_t::InitAndDeallocate()
{
    m = &DAT_010232c4;
    NiTMallocInterface<ActorCombatGroup*>::Deallocate(*(ActorCombatGroup***)(this + 1));
}
}  // namespace fnv_004edcc0

extern int DAT_010232cc;
struct FUN_004edcf0_t
{
    int* __thiscall InitWithGlobal(int, int);
    void __thiscall FUN_004edfe0(int, int);
};
// Calls FUN_004edfe0 with the two arguments, stores the address of DAT_010232cc at the start of this object, and returns this.
// @fnv 0x004edcf0
int* __thiscall FUN_004edcf0_t::InitWithGlobal(int a, int b)
{
    FUN_004edfe0(a, b);
    *reinterpret_cast<int**>(this) = &DAT_010232cc;
    return reinterpret_cast<int*>(this);
}

void __cdecl NiFreeAlias(void*);

// @fnv 0x004ede70
// src: XBOX_PDB 0x004ede70
void __cdecl NiTMallocInterface_unsigned_int_Deallocate(void* apMemory)
{
    NiFreeAlias(apMemory);
}

extern int DAT_01023254;
void __cdecl NiFreeAlias(void*);
struct MyMap
{
    void RemoveAll();
};
struct FUN_004eda30_t
{
    void __thiscall SetVtableAndProcessState_004eda30();
};
// @fnv 0x004eda30
// src: GUESS 0x004eda30 (confidence: low)
void __thiscall FUN_004eda30_t::SetVtableAndProcessState_004eda30()
{
    *(int**)(void*)this = (int*)&DAT_01023254;
    ((MyMap*)(void*)this)->RemoveAll();
    NiFreeAlias(*(void**)((char*)this + 8));
}

namespace fnv_004edc30 {
extern int DAT_01023294;
struct MyMap
{
    void* vtbl;
    void* a;
    void* b;
    void __thiscall RemoveAll();
};
void __cdecl NiFreeAlias(void*);
struct FUN_004edc30_t
{
    void __thiscall ClearAndFreeMap();
};
// @fnv 0x004edc30
void __thiscall FUN_004edc30_t::ClearAndFreeMap()
{
    *(int**)this = (int*)&DAT_01023294;
    ((MyMap*)this)->RemoveAll();
    NiFreeAlias(((MyMap*)this)->b);
}
}  // namespace fnv_004edc30

class Script;
// Walks the list from m_pkHead, deleting each item via DeleteItem, then resets the count, head and tail.
// @fnv 0x004ed900
template <>
void NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*>::RemoveAll() // src: GAMEBRYO_SRC
{
    NiTListItem<Script*>* pkCurr = m_pkHead;
    while (pkCurr)
    {
        NiTListItem<Script*>* pkDel = pkCurr;
        pkCurr = pkCurr->m_pkNext; // src: GAMEBRYO_SRC
        DeleteItem(pkDel);
    }
    m_kItemCount.m_uiCount = 0; // src: GAMEBRYO_SRC
    m_pkHead = 0;
    m_pkTail = 0;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

struct FUN_004ed960
{
    void* vtbl;
    unsigned int size;
    void* data;
    unsigned int count;
    void* __thiscall Init(unsigned int size);
};

// Sets the vtable, stores sz in size, allocates size*4 bytes for data, zeroes them, and returns this.
// @fnv 0x004ed960
void* __thiscall FUN_004ed960::Init(unsigned int uiSize)
{
    vtbl = (void*)&DAT_01023254;
    size = uiSize;
    count = 0;
    unsigned int n = size << 2;
    data = NiMalloc(n);
    memset(data, 0, size << 2);
    return this;
}

extern int DAT_01023274;
void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dst, int c, unsigned int n);
struct FUN_004eda60_t
{
    void* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_TESWaterForm_bool_NiTMapBase_NiTPointerAllocator_unsigned_int_TESWaterForm_bool(unsigned int count);
};
// Sets the vtable, stores count, allocates count*4 bytes, zeroes the buffer, and returns this.
// @fnv 0x004eda60
// src: COMMUNITY 0x004eda60
void* __thiscall FUN_004eda60_t::NiTMapBase_NiTPointerAllocator_unsigned_int_TESWaterForm_bool_NiTMapBase_NiTPointerAllocator_unsigned_int_TESWaterForm_bool(unsigned int count)
{
    unsigned int size;
    *(int*)this = (int)&DAT_01023274;
    *(unsigned int*)((char*)this + 4) = count;
    *(int*)((char*)this + 12) = 0;
    size = *(unsigned int*)((char*)this + 4) * 4;
    *(void**)((char*)this + 8) = NiMalloc(size);
    memset(*(void**)((char*)this + 8), 0, *(unsigned int*)((char*)this + 4) * 4);
    return this;
}

extern int DAT_01023294;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_004edb60_t
{
    int* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData_NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData(int size);
};
// Sets the vtable, stores size, allocates size*4 bytes, zeroes the buffer and returns this.
// @fnv 0x004edb60
// src: COMMUNITY 0x004edb60
int* __thiscall FUN_004edb60_t::NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData_NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData(int size)
{
    int tmp;
    *(int*)this = (int)&DAT_01023294;
    *(int*)((char*)this + 4) = size;
    *(int*)((char*)this + 0xc) = 0;
    tmp = *(int*)((char*)this + 4) << 2;
    *(int*)((char*)this + 8) = (int)_NiMalloc((unsigned int)tmp);
    memset(*(void**)((char*)this + 8), 0, (unsigned int)(*(int*)((char*)this + 4) << 2));
    return (int*)this;
}

extern int DAT_01023234;
struct FUN_004edc30_t
{
    virtual ~FUN_004edc30_t();
};
struct FUN_004edbd0 : FUN_004edc30_t
{
    void RemoveAll();
    virtual ~FUN_004edbd0();
};
// @fnv 0x004edbd0
FUN_004edbd0::~FUN_004edbd0()
{
    RemoveAll();
}

namespace fnv_004edd80 {
void __cdecl operator delete(void*);
struct FUN_004edc30_t
{
    void __thiscall ClearAndFreeMap();
    void* __thiscall FUN_004edd80(unsigned int flags);
};
// @fnv 0x004edd80
void* __thiscall FUN_004edc30_t::FUN_004edd80(unsigned int flags)
{
    ClearAndFreeMap();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_004edd80

struct FUN_004eddb0_t
{
    void* __thiscall FUN_004eddb0(unsigned int flags);
};
// @fnv 0x004eddb0
void* FUN_004eddb0_t::FUN_004eddb0(unsigned int flags)
{
    ((NiPointerListBase*)this)->ReleaseStorage_004edc60();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_004ebb30_shell
{
    void ForwardCall_004ebb30();
    void* __thiscall FUN_004edde0(unsigned int flags);
};
// Calls FUN_004ebb30, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x004edde0
void* FUN_004ebb30_shell::FUN_004edde0(unsigned int flags)
{
    ForwardCall_004ebb30();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_004ebb50_shell
{
    void __thiscall InitAndDeallocate();
    void* __thiscall FUN_004ede10(unsigned int flags);
};
// @fnv 0x004ede10
void* __thiscall FUN_004ebb50_shell::FUN_004ede10(unsigned int flags)
{
    InitAndDeallocate();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_004ede40 {
void __cdecl operator delete(void*);
struct FUN_004ebb50_shell
{
    void __thiscall InitAndDeallocate_Thunk();
    void* __thiscall FUN_004ede40(unsigned int flags);
};
// Calls FUN_004ebb50, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x004ede40
void* __thiscall FUN_004ebb50_shell::FUN_004ede40(unsigned int flags)
{
    InitAndDeallocate_Thunk();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_004ede40

struct NodePoolView
{
    NiTMapItem<unsigned int, void*>* AddHead();
};
struct FUN_00ae8bf0_t
{
    void AddItem(const void* element);
    void NewItem(NiTMapItem<unsigned int, void*>* node); // links the node in; not a NiTPointerMap member
};
// Allocates a map node from the pool at offset 8, stores the element's first pointer in it, and inserts the node into the map.
// @fnv 0x00ae8bf0
void FUN_00ae8bf0_t::AddItem(const void* element)
{
    NiTMapItem<unsigned int, void*>* node;
    {
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
        int g;
        node = ((NodePoolView*)((char*)this + 8))->AddHead();
    }
    ((void**)node)[2] = *(void**)element;
    NewItem(node);
}

struct FUN_004edd20_shell
{
    void* __thiscall FUN_004edd20(unsigned int flags);
};
// @fnv 0x004edd20
void* FUN_004edd20_shell::FUN_004edd20(unsigned int flags)
{
    ((FUN_004eda30_t*)this)->SetVtableAndProcessState_004eda30();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00438af0_t
{
    void __thiscall FUN_00438af0();
};
struct FUN_004eda30
{
    virtual ~FUN_004eda30();
};
struct FUN_004ed9d0 : FUN_004eda30
{
    virtual ~FUN_004ed9d0();
};
// Destructor that forwards to FUN_00438af0 on this object.
// @fnv 0x004ed9d0
FUN_004ed9d0::~FUN_004ed9d0()
{
    ((FUN_00438af0_t*)this)->FUN_00438af0();
}

namespace fnv_004edad0 {
struct FUN_00438af0_t
{
    void FUN_00438af0();
};

struct FUN_004edb30
{
    virtual ~FUN_004edb30();
};

struct FUN_004edad0 : FUN_004edb30
{
    virtual ~FUN_004edad0();
};

// Destructor that forwards to FUN_00438af0 on this object.
// @fnv 0x004edad0
FUN_004edad0::~FUN_004edad0()
{
    reinterpret_cast<FUN_00438af0_t*>(this)->FUN_00438af0();
}
}  // namespace fnv_004edad0

// @fnv 0x00ae8370
template <>
void NiTPointerListBase<NiTPointerAllocator<unsigned int>, void*>::RemoveAll() // src: GAMEBRYO_SRC
{
    NiTListItem<void*>* pos = m_pkHead;
    while (pos)
    {
        NiTListItem<void*>* cur = pos;
        unsigned int pad[3];
        pos = pos->m_pkNext; // src: GAMEBRYO_SRC
        cur->m_element = 0; // src: GAMEBRYO_SRC
        m_kItemCount.Deallocate(cur); // src: GAMEBRYO_SRC
    }
    m_kItemCount.m_uiCount = 0; // src: GAMEBRYO_SRC
    m_pkHead = 0;
    m_pkTail = 0;
}

extern int DAT_01023274;

// Sets the first word to DAT_01023274, calls RemoveAll, then frees the pointer at offset 8 with NiFreeAlias.
// @fnv 0x004edb30
// src: GUESS 0x004edb30 (confidence: low)
void FUN_004edb30_t::SetVtableAndProcessState_004edb30()
{
    *(int**)this = &DAT_01023274;
    ((MyMap*)this)->RemoveAll();
    NiFreeAlias(*(void**)((char*)this + 8));
}
