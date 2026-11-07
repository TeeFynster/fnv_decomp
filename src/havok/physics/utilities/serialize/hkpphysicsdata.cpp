
// src/havok/physics/utilities/serialize/hkpphysicsdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkpphysicsdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkpPhysicsData.h"
#include "../../../../../include/hkpPhysicsSystem.h"
#include "../../../../../include/hkThreadMemory.h"
#include "../../../../../include/hkpWorld.h"

int __cdecl CompareStringsCaseInsensitive(int, int);

struct FUN_00d4c000
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
    int m_10;
    int Method(int a);
};

// @fnv 0x00d4c000
int FUN_00d4c000::Method(int a)
{
    for (int i = 0; i < m_10; i++)
    {
        int v = *reinterpret_cast<int*>(*(reinterpret_cast<char**>(m_0c) + i) + 0x38) & 0xfffffffe;
        if (v && !CompareStringsCaseInsensitive(v, a))
            return m_0c[i];
    }
    return 0;
}

extern int DAT_010cf9a4;

struct FUN_00d4c220_s
{
    int* m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00d4c220_s();
};

// @fnv 0x00d4c220
FUN_00d4c220_s::FUN_00d4c220_s()
{
    m_06 = 1;
    m_00 = &DAT_010cf9a4;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0x80000000;
    m_08 = 0;
}

int __cdecl CompareStringsCaseInsensitive(int, int);

struct FUN_00d4c050_obj
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
    int m_10;
    int FindMatchingEntry(int a);
};

// Scans m_10 entries, checks each entry's sub-items via CompareStringsCaseInsensitive on the masked field at offset 0x74, and returns the first matching item or 0.
// @fnv 0x00d4c050
int FUN_00d4c050_obj::FindMatchingEntry(int a)
{
    for (int i = 0; i < m_10; ++i)
    {
        int* p = (int*)m_0c[i];
        for (int jItem = 0; jItem < p[3]; ++jItem)
        {
            int v = ((int*)p[2])[jItem];
            int m = *(int*)((char*)v + 0x74);
            if ((m & ~1) && !CompareStringsCaseInsensitive(m & ~1, a))
                return v;
        }
    }
    return 0;
}

extern int DAT_0102f0ec;


void* hkMemoryRouter_getInstance() throw();
void __cdecl InitializeWorld(void*) throw();
void __cdecl RunWithLocalContext(void*, void*, void*) throw();

template <typename T> struct ReferenceCountedPointer
{
    T* m_pRetainedObject;
    __forceinline ReferenceCountedPointer() throw()
    {}
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
        {
            ((hkReferencedObject*)m_pRetainedObject)->removeReference();
        }
        m_pRetainedObject = 0;
    }
};

struct BoolResult
{
    char val;
    __forceinline BoolResult() throw()
    {}
};

class __declspec(align(16)) FUN_00553540
{
  public:
    void* vtable;
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
    int unk4c;
    int unk50;
    int unk54;
    ReferenceCountedPointer<void> m_pCollisionFilter;  // 0x58
    ReferenceCountedPointer<void> m_pConvexListCollisionFilter;  // 0x5c
    int unk60;
    int unk64;
    int unk68;
    ReferenceCountedPointer<void> m_pMemoryWatchDog;  // 0x6c
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;

    void FUN_00c90b80() throw();
    __forceinline FUN_00553540() throw()
    {
        FUN_00c90b80();
    }
    __forceinline ~FUN_00553540() throw()
    {
        vtable = &DAT_0102f0ec;
    }
};

__forceinline void* hkThreadMemory::allocateChunk(int size) throw()
{
    return reinterpret_cast<hkMemoryAllocator*>(m_pMemoryAllocator)->blockAlloc(size);
}

__forceinline hkMemoryAllocator& hkThreadMemory::heap()
{
    return *reinterpret_cast<hkMemoryAllocator*>(m_pMemoryAllocator);
}

__forceinline void* hkpWorld::operator new(size_t size) throw()
{
    void* p = ((hkThreadMemory*)hkMemoryRouter_getInstance())->allocateChunk(size);
    ((unsigned short*)p)[2] = (unsigned short)size;
    return p;
}

struct ContactOptions
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    int m_04;
    char m_08;
    char m_09;
    char m_0a;
    char m_0b;
};

struct PhysicsDataExt : public hkpPhysicsData
{
    hkpWorld* CreateWorld(char bRegisterWithMemoryManager) throw();
};

// @fnv 0x00d4c0c0
hkpWorld* PhysicsDataExt::CreateWorld(char bRegisterWithMemoryManager) throw()
{
    FUN_00553540 defaultCinfo;
    hkpWorld* world;
    if (this->m_pWorldCinfo == 0)
    {
        world = ((hkpWorld*)hkpWorld::operator new(0x350))->hkpWorld_hkpWorld(reinterpret_cast<const hkpWorldCinfo*>(&defaultCinfo));
    }
    else
    {
        world = ((hkpWorld*)hkpWorld::operator new(0x350))->hkpWorld_hkpWorld(this->m_pWorldCinfo);
    }

    if (bRegisterWithMemoryManager)
    {
        InitializeWorld(world->m_pDispatcher);
    }

    for (int i = 0; i < this->m_kPhysicsSystems.m_iElementCount; ++i)
    {
        world->hkpWorld_addPhysicsSystem(this->m_kPhysicsSystems.m_data[i]);
        if (this->m_kPhysicsSystems.m_data[i]->vfunc4().val)
        {
            ContactOptions opts;
            opts.m_00 = 0;
            opts.m_01 = 0;
            opts.m_04 = 0;
            opts.m_08 = 1;
            opts.m_09 = 1;
            opts.m_0a = 0;
            RunWithLocalContext(&opts, this->m_kPhysicsSystems.m_data[i], world);
        }
    }

    if (this->m_pWorldCinfo && ((FUN_00553540*)this->m_pWorldCinfo)->m_pCollisionFilter.m_pRetainedObject)
    {
        world->hkpWorld_updateCollisionFilterOnWorld(0, 1);
    }

    return world;
}

namespace fnv_00d4c8e0 {
class FUN_00dcecc0
{
  public:
    virtual ~FUN_00dcecc0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        ((hkThreadMemory*)hkMemoryRouter_getInstance())->heap().blockFree(p, static_cast<FUN_00dcecc0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00dcecc0* Destroy(unsigned int uiFlags) throw();
};

// Runs the destructor and, when bit 0 of uiFlags is set, frees the object through the heap allocator, then returns this.
// @fnv 0x00d4c8e0
FUN_00dcecc0* FUN_00dcecc0::Destroy(unsigned int uiFlags) throw()
{
    this->FUN_00dcecc0::~FUN_00dcecc0();
    if (uiFlags & 1)
        FUN_00dcecc0::operator delete(this);
    return this;
}
}  // namespace fnv_00d4c8e0

extern void* __cdecl hkMemoryRouter_getInstance(void);
extern int DAT_010d07f4;
extern void __cdecl ProcessCollisionRecords(void*, void*, void*);
extern void __cdecl ResizeAudioStream(void*, void*, int);

struct D4C2Place
{
};
inline void* operator new(unsigned int, void* p, D4C2Place)
{
    __assume(p != 0);
    return p;
}
inline void operator delete(void*, void*, D4C2Place)
{}

struct BigType
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    void* FUN_00c90b80(void);
};

struct SmallType
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    unsigned char m_40;
    unsigned char m_41;
    unsigned char m_42;
    unsigned char m_43;
    hkArray<void*> m_ppData;
    void FUN_00d065e0(void);
};

struct ClientType
{
    void hkpWorld_getCinfo(void*);
    void AddPhysicsSystem(void*);
};
struct HostType
{
    int m_00;
    int m_04;
    void* m_08;
    hkArray<SmallType*> m_0c;
    void hkpPhysicsData_populateFromWorld(ClientType*, unsigned char);
};

// Ensures m_08 is allocated, registers client and m_0c, and when value is set allocates a SmallType, calls ProcessCollisionRecords, and appends it to m_0c.
// @fnv 0x00d4c2d0
// src: HAVOK_LIB 0x00d4c2d0
void HostType::hkpPhysicsData_populateFromWorld(ClientType* client, unsigned char ubFlag)
{
    if (m_08 == 0)
    {
        hkThreadMemory* holder = (hkThreadMemory*)hkMemoryRouter_getInstance();
        BigType* big = (BigType*)holder->allocateChunk(0xF0);
        big->m_04 = 0xF0;
        m_08 = big->FUN_00c90b80();
    }

    client->hkpWorld_getCinfo(m_08);
    hkArray<SmallType*>* array = &m_0c;
    client->AddPhysicsSystem(array);

    if (ubFlag != 0)
    {
        struct Local
        {
            unsigned char m_flag;
            int m_uiFilterValue;
        } local;

        local.m_flag = 0;
        local.m_uiFilterValue = 0;

        hkThreadMemory* holder = (hkThreadMemory*)hkMemoryRouter_getInstance();
        SmallType* small = (SmallType*)holder->allocateChunk(0x50);
        small->m_04 = 0x50;
        small->FUN_00d065e0();

        small->m_00 = (int)&DAT_010d07f4;
        new (&small->m_ppData, D4C2Place()) hkArray<void*>();

        ProcessCollisionRecords(&local, client, small);

        small->m_40 = 0;

        holder = (hkThreadMemory*)hkMemoryRouter_getInstance();
        if (array->m_iElementCount == (array->m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(holder->m_pMemoryAllocator, array, 4);
        }

        new (array->m_data + array->m_iElementCount, D4C2Place()) SmallType*(small);
        array->m_iElementCount++;
    }
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

struct Value
{
    BoolResult isActive_00c9bff0();
};
struct Owner
{
    int unk00;
    int unk04;
    int** m_08;
    int m_0c;
    void hkpPhysicsSystem_removeRigidBody(int index);
};
struct Entity
{
    int unk00;
    int unk04;
    int** m_08;
    int m_0c;
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
    unsigned char m_40;
    void AddShape(int value);
};
struct OwnerArg
{
    Owner* p;
};
struct ValueArg
{
    Value* p;
};
template <class T> __forceinline int findValue(T* self, Value* value)
{
    int count = ((volatile T*)self)->m_0c;
    for (int i = 0; i < count; ++i)
    {
        if (self->m_08[i] == (int*)value)
            return i;
    }
    return -1;
}
typedef int Owner::*MemberPtr;
// If value is in owner's list but not entity's, sets entity->m_40, calls entity->AddShape(value) and owner->FUN_00d06130 with the owner index.
// @fnv 0x00d4bf70
// src: HAVOK_LIB 0x00d4bf70
static __declspec(noinline) void tryMoveEntity(Owner* owner, Entity* volatile apEntity, MemberPtr valueArg)
{
    Entity* entity = apEntity;
    Value* pValue;
    memcpy(&pValue, &valueArg, 4);
    Value* value = pValue;
    int ownerIndex = findValue(owner, value);
    int entityIndex = findValue(entity, value);
    if (entityIndex == -1 && ownerIndex != -1)
    {
        entity->m_40 = entity->m_40 || value->isActive_00c9bff0().val;
        entity->AddShape((int)value);
        owner->hkpPhysicsSystem_removeRigidBody(ownerIndex);
    }
}
Owner* volatile probeOwner;
Value* volatile probeValue;
Entity* volatile probeEntity;
void probeCaller()
{
    OwnerArg o = {probeOwner};
    ValueArg v = {probeValue};
    tryMoveEntity(o.p, probeEntity, *(MemberPtr*)&v.p);
}



template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray() throw()
{
    hkMemoryAllocator& alloc = ((hkThreadMemory*)hkMemoryRouter_getInstance())->heap();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

namespace fnv_00d4c250 {
class FUN_00d4c250 : public hkReferencedObject
{
  public:
    hkReferencedObject* m_pCollisionShape;
    hkArray<hkReferencedObject*> m_children;

    virtual ~FUN_00d4c250();
};

// Destructor: calls FUN_00c905b0 on m_pCollisionShape if set and on each element of m_children.
// @fnv 0x00d4c250
FUN_00d4c250::~FUN_00d4c250()
{
    if (m_pCollisionShape)
        m_pCollisionShape->removeReference();
    for (int i = 0; i < m_children.m_iElementCount; i++)
        m_children.m_data[i]->removeReference();
}
}  // namespace fnv_00d4c250
