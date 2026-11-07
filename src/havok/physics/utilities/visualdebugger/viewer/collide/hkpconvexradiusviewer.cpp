
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkThreadMemory.h"
#include "../../../../../../../include/hkArray.h"

struct hkMemory
{
    virtual void unk0();
    virtual void* allocateChunk(int size);
};

inline hkMemoryAllocator& hkThreadMemory::heap()
{
    return *(hkMemoryAllocator*)m_pMemoryAllocator;
}

inline void* hkThreadMemory::allocateChunk(int size) throw()
{
    return m_pMemoryAllocator->allocateChunk(size);
}

void* __cdecl hkpConvexRadiusViewer_create();
struct FUN_00dd9380_class
{
    void* __thiscall hkProcessFactory_registerProcess(const char* name, void* func);
};
void* DAT_01269cd0;
void* DAT_01269010;

// @fnv 0x00d68e40
void* __cdecl RegisterConvexRadius()
{
    DAT_01269010 = ((FUN_00dd9380_class*)DAT_01269cd0)->hkProcessFactory_registerProcess("Convex Radius", hkpConvexRadiusViewer_create);
    return DAT_01269010;
}

struct FUN_00d68a70_class
{
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
    int unk28;
    int unk2c;
    int** entries;
    int count;
    int FindKeyIndex(int key);
};
// Scans the entries array for the first entry whose first int equals key and returns its index, or -1 if none match.
// @fnv 0x00d68a70
int FUN_00d68a70_class::FindKeyIndex(int key)
{
    int limit = count;
    int index = 0;
    if (limit > 0)
    {
        int** ppEntry = entries;
        do
        {
            if (**ppEntry == key)
                return index;
            ++index;
            ++ppEntry;
        } while (index < limit);
    }
    return -1;
}

struct D68FC0World
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
    void** m_kActorEntries;
    int m_iActorEntryCount;
};

struct D68FC0Primary
{
    virtual void vfunc00();

    int unk04;
};

struct D68FC0Listener
{
    virtual void ProcessEntries_00d68fc0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    D68FC0World* m_pOwningWorld;
};

struct D68FC0Object : D68FC0Primary, D68FC0Listener
{
    void RegisterEntity(void* entity);

    virtual void ProcessEntries_00d68fc0();
};

// @fnv 0x00d68fc0
// src: GUESS 0x00d68fc0 (confidence: low)
void D68FC0Object::ProcessEntries_00d68fc0()
{
    if (m_pOwningWorld)
    {
        for (int i = 0; i < m_pOwningWorld->m_iActorEntryCount; i++)
            RegisterEntity(m_pOwningWorld->m_kActorEntries[i]);
    }
}

struct Target
{
    void hkpConvexRadiusViewer_addWorld();
};
struct Outer
{
    void HkpConvexRadiusViewer_addWorld_Thunk();
};
// @fnv 0x00d69000
// src: GUESS 0x00d69000 (confidence: medium)
void Outer::HkpConvexRadiusViewer_addWorld_Thunk()
{
    ((Target*)((char*)this - 0x20))->hkpConvexRadiusViewer_addWorld();
}

struct Base
{
    int FindKeyIndex(int);
    void hkpConvexRadiusViewer_removeWorld(int);
};
struct Sub
{
    void UpdateFields_00d69160(int);
};
// Calls FindKeyIndex on the Base at this-0x20 with value, and if the result is non-negative passes it to FUN_00d69010.
// @fnv 0x00d69160
// src: GUESS 0x00d69160 (confidence: low)
void Sub::UpdateFields_00d69160(int value)
{
    Base* base = reinterpret_cast<Base*>(reinterpret_cast<char*>(this) - 0x20);
    int result = base->FindKeyIndex(value);
    if (result >= 0)
        base->hkpConvexRadiusViewer_removeWorld(result);
}

// @fnv 0x00d69180
// src: GUESS 0x00d69180 (confidence: low)
void* __cdecl Object_GetDAT_01269010_00d69180()
{
    return DAT_01269010;
}

struct Heap
{
    virtual void a();
    virtual void b();
    virtual void free(void*, unsigned short);
};

struct Destructor
{
    void FUN_00d690d0();
};
struct FUN_00d691d0_Class
{
    int unk00;
    unsigned short allocationSize;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00d691d0_Class* Destroy(unsigned int flags);
};
extern hkThreadMemory* hkMemoryRouter_getInstance();
// Runs the destructor, and if flags has bit 0 set, frees this object through the holder's allocator using allocationSize.
// @fnv 0x00d691d0
FUN_00d691d0_Class* FUN_00d691d0_Class::Destroy(unsigned int flags)
{
    ((Destructor*)this)->FUN_00d690d0();
    if (flags & 1)
    {
        hkThreadMemory* holder = hkMemoryRouter_getInstance();
        ((Heap*)holder->m_pMemoryAllocator)->free(this, allocationSize);
    }
    return this;
}

extern void* DAT_01269010;

struct FUN_00d68940_target
{
    virtual void vSlot0();
    virtual void vSlot1();
    virtual void vSlot2();
    virtual void vSlot3();
    virtual void vSlot4(void* a, void* b, void* c);
};

struct FUN_00d68940_cls
{
    void DispatchToTarget(char* a1);
};

// Calls vSlot4 on the target object stored 0x14 bytes before this, passing a1+0xf0, a1+0x13 and DAT_01269010.
// @fnv 0x00d68940
void FUN_00d68940_cls::DispatchToTarget(char* pData)
{
    FUN_00d68940_target* target = *(FUN_00d68940_target**)((char*)this - 0x14);
    target->vSlot4(pData + 0xf0, pData + 0x13, DAT_01269010);
}

struct FUN_00d68aa0_req
{
    int unk00;
    int unk04;
    void* m_08;
    int unk0C;
    void* m_10;
};

struct FUN_00d68aa0_item_list
{
    void* unk00;
    void** m_04;
    int m_08;
};

struct FUN_00d68aa0_mgr
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(void* a, void* b, int c);
};

struct FUN_00d68aa0_owner
{
    int FindKeyIndex(void* key);
};

extern void* DAT_01269010;

struct FUN_00d68aa0_cls
{
    void* unk00;
    void* unk04;
    FUN_00d68aa0_item_list** m_08;

    void RemoveItem(FUN_00d68aa0_req* a1);
};

// @fnv 0x00d68aa0
void FUN_00d68aa0_cls::RemoveItem(FUN_00d68aa0_req* pRequest)
{
    if (pRequest->m_10 == 0)
    {
        return;
    }
    int idx = ((FUN_00d68aa0_owner*)((char*)this - 0x28))->FindKeyIndex(pRequest->m_08);
    if (idx < 0)
    {
        return;
    }
    FUN_00d68aa0_item_list* list = m_08[idx];
    FUN_00d68aa0_mgr* mgr = *(FUN_00d68aa0_mgr**)((char*)this - 0x10);
    pRequest = (FUN_00d68aa0_req*)((char*)pRequest + 0x13);
    mgr->v05(pRequest, DAT_01269010, 0);

    int i = 0;
    int n = list->m_08;
    if (n > 0)
    {
        void** p = list->m_04;
        do
        {
            if (*p == (void*)pRequest)
            {
                goto found;
            }
            ++i;
            ++p;
        } while (i < n);
    }
    return;
found:
    if (i < 0)
    {
        return;
    }
    volatile int* pCount = &list->m_08;
    *pCount = *pCount - 1;
    int last = list->m_08;
    if (last != i)
    {
        void** arr = list->m_04;
        arr[i] = arr[last];
    }
}



struct S_B0
{
    virtual void b0v0();
    int unk04;
    void hkpConvexRadiusViewer_removeWorld(int i) throw();
};
struct S_B8
{
    virtual void b8v0();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct S_B20
{
    virtual void b20v0();
};
struct FUN_00ddcc60 : S_B0, S_B8, S_B20
{
    int m24;
    virtual ~FUN_00ddcc60() throw();
};
struct S_D28
{
    virtual ~S_D28() throw()
    {}
};
struct S_D2c
{
    virtual ~S_D2c() throw()
    {}
};

struct S_Arr
{
    void** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.bufFree(m_data, (cap & 0x3fffffff) * (int)sizeof(void*));
        m_data = 0;
        m_cap = 0x80000000;
    }
};
struct FUN_00d690d0 : FUN_00ddcc60, S_D28, S_D2c
{
    S_Arr m30;
    virtual ~FUN_00d690d0() throw();
};
// Destroys the object: calls FUN_00d69010 for each element of m30 in reverse order, then clears and deallocates m30 using the heap from FUN_00c85750.
// @fnv 0x00d690d0
FUN_00d690d0::~FUN_00d690d0() throw()
{
    for (int i = m30.m_iElementCount - 1; i >= 0; i--)
        hkpConvexRadiusViewer_removeWorld(i);
    m30._clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
}

struct SubObj
{
    virtual void v0();
    virtual void v1(void* p);
};

struct Allocator
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
};

struct PairList
{
    void** m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

struct ListHolder
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
    PairList m_48;
};

struct Record
{
    void* m_pOwnerObject;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_flags0C;
};

void ResizeAudioStream(Allocator* allocator, PairList* list, unsigned int elemSize);

struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ListHolder* m_20;
    int unk24;
    ListHolder** m_28;
    int m_2C;
    void hkpWorld_addEntityListener(SubObj* p);
    void hkpWorld_addWorldPostSimulationListener(SubObj* p);
    int unk30;
    ListHolder** m_34;
    int m_38;
};

struct FUN_00d68e60_cls
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
    SubObj m_28;
    SubObj m_2C;
    PairList m_30;

    void hkpConvexRadiusViewer_addWorld(Owner* owner);
};

// @fnv 0x00d68e60
// src: XBOX_PDB 0x00d68e60
void FUN_00d68e60_cls::hkpConvexRadiusViewer_addWorld(Owner* owner)
{
    owner->hkpWorld_addEntityListener(this != 0 ? &m_28 : 0);
    owner->hkpWorld_addWorldPostSimulationListener(this != 0 ? &m_2C : 0);

    hkThreadMemory* pAllocHolder = hkMemoryRouter_getInstance();
    Record* pRecord = 0;
    Record* pNewRecord = (Record*)((Allocator*)pAllocHolder->m_pMemoryAllocator)->Alloc(16);
    if (pNewRecord != 0)
    {
        pNewRecord->unk04 = 0;
        pNewRecord->unk08 = 0;
        pNewRecord->m_flags0C = 0x80000000u;
        pRecord = pNewRecord;
    }
    pRecord->m_pOwnerObject = owner;

    PairList* pList = &m_30;
    hkThreadMemory* holder = hkMemoryRouter_getInstance();
    if (pList->m_uiItemCount == (int)(pList->m_capBits & 0x3fffffffu))
    {
        ResizeAudioStream((Allocator*)holder->m_pMemoryAllocator, pList, 4);
    }
    unsigned int idx = *(volatile unsigned int*)&pList->m_uiItemCount;
    void** ppData = pList->m_data;
    void** ppSlot = &ppData[idx];
    *ppSlot = pRecord;
    *ppSlot = pRecord;
    pList->m_uiItemCount++;

    for (int i = 0; i < owner->m_2C; i++)
    {
        PairList* pPairList = &owner->m_28[i]->m_48;
        for (int j = 0; j < pPairList->m_uiItemCount; j++)
        {
            m_28.v1(pPairList->m_data[j]);
        }
    }

    for (int i = 0; i < owner->m_38; i++)
    {
        PairList* pPairList = &owner->m_34[i]->m_48;
        for (int j = 0; j < pPairList->m_uiItemCount; j++)
        {
            m_28.v1(pPairList->m_data[j]);
        }
    }

    ListHolder* pExtraHolder = owner->m_20;
    if (pExtraHolder != 0)
    {
        for (int j = 0; j < pExtraHolder->m_48.m_uiItemCount; j++)
        {
            m_28.v1(pExtraHolder->m_48.m_data[j]);
        }
    }
}

static void* DAT_01269018;
static void* DAT_01269014;

struct T68B0
{
    virtual void b0v0();
    int unk04;
};
struct T68B8
{
    virtual void b8v0();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct T68B20
{
    virtual void b20v0();
};

struct T68Base : T68B0, T68B8, T68B20
{
    int m24;
    T68Base(int arg);
};

struct T68D28
{
    virtual void d28v0();
    T68D28()
    {}
};
struct T68D2c
{
    virtual void d2cv0();
    T68D2c()
    {}
};

struct T68Arr
{
    void** m_data;
    int m_iElementCount;
    unsigned int m_cap;
    T68Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000u)
    {}
};

struct FUN_00d68b90 : T68Base, T68D28, T68D2c
{
    T68Arr m30;
    void* m3c;
    void* m40;
    FUN_00d68b90(int arg);
    virtual void b0v0();
    virtual void b8v0();
    virtual void b20v0();
    virtual void d28v0();
    virtual void d2cv0();
};

// @fnv 0x00d68b90
FUN_00d68b90::FUN_00d68b90(int arg) : T68Base(arg), m3c(DAT_01269018), m40(DAT_01269014)
{}






inline hkMemoryAllocator& getMemory_d65f()
{
    return hkMemoryRouter_getInstance()->heap();
}

inline void memCpy4_d65f(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T, class Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& mem = hkMemoryRouter_getInstance()->heap();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        mem.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <class T>
__forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        memCpy4_d65f(m_data + index, m_data + m_iElementCount, sizeof(T));
}

struct Listener_d65f;
struct Watch2_d65f
{
    virtual void w00();
};

struct Agent_d65f
{
    void hkpWorld_removeEntityListener(Listener_d65f* listener);
    void ClearValue(Watch2_d65f* watch);
};

struct Node_d65f
{
    Agent_d65f* m_pCollisionAgent;
    hkArray<int> m_items;
    static void operator delete(void* p) throw()
    {
        (hkMemoryRouter_getInstance()->heap()).blockFree(p, sizeof(Node_d65f));
    }
};

struct Base_d65f
{
    virtual void v00();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
};

struct Listener_d65f
{
    virtual void l00();
};

struct Watch_d65f
{
    int unk00;
};

struct Phantom_d65f : Base_d65f, Listener_d65f, Watch2_d65f
{
    hkArray<Node_d65f*> m_kNodeCollection;
    void ClearItemArray(int index);
    void hkpConvexRadiusViewer_removeWorld(int index);
};

// Calls FUN_00c917a0 and ClearValue on the node's collision agent, calls FUN_00d68b20, then deletes the node at index and removes it from m_kNodeCollection.
// @fnv 0x00d69010
// src: XBOX_PDB 0x00d69010
void Phantom_d65f::hkpConvexRadiusViewer_removeWorld(int index)
{
    m_kNodeCollection[index]->m_pCollisionAgent->hkpWorld_removeEntityListener(this);
    m_kNodeCollection[index]->m_pCollisionAgent->ClearValue(this);
    ClearItemArray(index);
    delete m_kNodeCollection[index];
    m_kNodeCollection.removeAt(index);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern DWORD DAT_0126835c;
extern void* DAT_01269010;
extern char DAT_010d2080[];
extern char DAT_010c41f8[];

struct D68970_ProfileRecord
{
    const char* name;
    DWORD tick;
    DWORD unk08;
};

struct D68970_ProfileBuffer
{
    DWORD unk00;
    D68970_ProfileRecord* current;
    DWORD unk08;
    D68970_ProfileRecord* end;
};

struct D68970_Vector
{
    float x, y, z, w;
};
struct __declspec(align(16)) D68970_Output
{
    D68970_Vector rotation0, rotation1, rotation2, translation;
};

struct D68970_TransformObject
{
    void SweepTransform(float time, void* output);
};

struct D68970_Body
{
    DWORD unk00, unk04, unk08, unk0C;
    char unk10, unk11, unk12, displayId;
    DWORD unk14;
    DWORD unk18;
    DWORD unk1C;
    DWORD unk20;
    DWORD unk24;
    DWORD unk28;
    DWORD unk2C;
    DWORD unk30;
    DWORD unk34;
    DWORD unk38;
    DWORD unk3C;
    DWORD unk40;
    DWORD unk44;
    DWORD unk48;
    DWORD unk4C;
    DWORD unk50;
    DWORD unk54;
    DWORD unk58;
    DWORD unk5C;
    DWORD unk60;
    DWORD unk64;
    DWORD unk68;
    DWORD unk6C;
    DWORD unk70;
    DWORD unk74;
    DWORD unk78;
    DWORD unk7C;
    DWORD unk80;
    DWORD unk84;
    DWORD unk88;
    DWORD unk8C;
    DWORD unk90;
    DWORD unk94;
    DWORD unk98;
    DWORD unk9C;
    DWORD unkA0;
    DWORD unkA4;
    DWORD unkA8;
    DWORD unkAC;
    DWORD unkB0;
    DWORD unkB4;
    DWORD unkB8;
    DWORD unkBC;
    DWORD unkC0;
    DWORD unkC4;
    DWORD unkC8;
    DWORD unkCC;
    DWORD unkD0;
    DWORD unkD4;
    DWORD unkD8;
    DWORD unkDC;
    D68970_TransformObject transformObject;
};

struct D68970_BodyIsland
{
    D68970_Body** bodies;
    int bodyCount;
};

struct D68970_Entity
{
    DWORD unk00;
    DWORD unk04;
    DWORD unk08;
    DWORD unk0C;
    DWORD unk10;
    DWORD unk14;
    DWORD unk18;
    DWORD unk1C;
    DWORD unk20;
    DWORD unk24;
    DWORD unk28;
    DWORD unk2C;
    DWORD unk30;
    DWORD unk34;
    DWORD unk38;
    DWORD unk3C;
    DWORD unk40;
    DWORD unk44;
    D68970_BodyIsland islands;
};

struct D68970_Owner
{
    DWORD unk00;
    DWORD unk04;
    DWORD unk08;
    DWORD unk0C;
    DWORD unk10;
    DWORD unk14;
    DWORD unk18;
    DWORD unk1C;
    DWORD unk20;
    DWORD unk24;
    D68970_Entity** entities;
    int entityCount;

    float hkpWorld_getCurrentTime();
};

struct D68970_DisplayBase
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(void* transform, void* id, void* context);
};

struct D68970_Primary
{
    D68970_DisplayBase* display;
    int unk04, unk08, unk0C, unk10;
};
struct D68970_Listener
{
    int unk00;
    void hkpConvexRadiusViewer_postSimulationCallback(D68970_Owner* owner);
};
struct D68970_Viewer : D68970_Primary, D68970_Listener
{
};

// Sweeps each body's transform and pushes the result to the display, bracketing the work with two profile records.
// @fnv 0x00d68970
// src: HAVOK_LIB 0x00d68970
void D68970_Listener::hkpConvexRadiusViewer_postSimulationCallback(D68970_Owner* owner)
{
    __assume(this != 0);
    volatile DWORD tick;
    D68970_ProfileBuffer* profile = static_cast<D68970_ProfileBuffer*>(TlsGetValue(DAT_0126835c));

    D68970_ProfileRecord* record = profile->current;
    if (record < profile->end)
    {
        record->name = DAT_010d2080;
        _ReadWriteBarrier();
        tick = __rdtsc();
        record->tick = tick;
        profile->current = record + 1;
    }

    for (int entityIndex = 0; entityIndex < owner->entityCount; ++entityIndex)
    {
        D68970_Entity* entity = owner->entities[entityIndex];
        D68970_BodyIsland* island = &entity->islands;

        for (int bodyIndex = 0; bodyIndex < island->bodyCount; ++bodyIndex)
        {
            D68970_Body* body = island->bodies[bodyIndex];
            float time = owner->hkpWorld_getCurrentTime();

            D68970_TransformObject* transformObject = &body->transformObject;
            D68970_Output output;
            transformObject->SweepTransform(time, &output);

            static_cast<D68970_Viewer&>(*this).display->vf10(&output, &body->displayId, DAT_01269010);
        }
    }

    profile = static_cast<D68970_ProfileBuffer*>(TlsGetValue(DAT_0126835c));
    record = profile->current;
    if (record < profile->end)
    {
        record->name = DAT_010c41f8;
        _ReadWriteBarrier();
        tick = __rdtsc();
        record->tick = tick;
        profile->current = record + 1;
    }
}

struct D69190Primary
{
    virtual void vfunc00();
    virtual void FUN_00d69190();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct D69190Secondary
{
    virtual void FUN_00d69190();
};

struct D69190Object : D69190Primary, D69190Secondary
{
    D69190Object();

// @fnv 0x00d69190
    virtual void FUN_00d69190();
};

D69190Object::D69190Object()
{}

// FUN_00d691a0 : MSVC this-adjusting thunk.
//
// The original is 8 bytes:  sub ecx, 0x08 ; jmp 0x00d691d0
// That is the adjustor thunk MSVC emits for a virtual function that a
// derived class overrides for a SECONDARY base: calling through the
// secondary base's vftable passes the base subobject's 	his, so the
// thunk walks it back to the derived object and tail-jumps to the shared
// override.
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them -> one adjustor per secondary base.  The first
// base is padded to 8 bytes so the second base lands at +0x08.
// The override is DECLARED ONLY, so the thunk is the single defined
// function symbol carrying the name FUN_00d691a0, and a defined key function in the
// derived class makes the vftable that references the thunk be emitted here.
struct AdjBase1
{
    AdjBase1();
    virtual void AdjustThisAndForward_00d691a0();
    char pad[0x04];
};

struct AdjBase2
{
    AdjBase2();
// @fnv 0x00d691a0
// src: GUESS 0x00d691a0 (confidence: low)
    virtual void AdjustThisAndForward_00d691a0();
};

struct AdjOwner : AdjBase1, AdjBase2
{
    AdjOwner();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void AdjustThisAndForward_00d691a0();    // the shared override - declared only
};

AdjOwner::AdjOwner()
{}
void AdjOwner::key_fn()
{}

AdjOwner* make_adj_owner()
{
    static AdjOwner o;
    return &o;
}

// sub ecx,0x28; jmp target: MSVC adjustor thunk. PrimaryBase is 0x28 bytes (vptr + 9 ints),
// so the second base sits at +0x28 and the thunk subtracts 0x28 from this.
struct PrimaryBase
{
    virtual void FUN_00d691b0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct SecondaryBase
{
    virtual void FUN_00d691b0();
};

struct SpawnedObject : PrimaryBase, SecondaryBase
{
    SpawnedObject();
// @fnv 0x00d691b0
    virtual void FUN_00d691b0();
};

SpawnedObject::SpawnedObject()
{}

struct D691C0Primary
{
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00d691c0();

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
};

struct D691C0Secondary
{
    virtual void AdjustThisAndForward_00d691c0();
};

struct D691C0Object : D691C0Primary, D691C0Secondary
{
    D691C0Object();

// @fnv 0x00d691c0
// src: GUESS 0x00d691c0 (confidence: low)
    virtual void AdjustThisAndForward_00d691c0();
};

D691C0Object::D691C0Object()
{}

namespace fnv_00d68c00 {
struct S_00d68c00_Arg
{
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
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
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
    unsigned char unke8;
    unsigned char unke9;
    unsigned char unkea;
    unsigned char unkeb;
    int unkec;
    int unkf0;
};

struct S_00d68c00_Elem
{
    virtual void* v0(unsigned int flags) throw();
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
};

struct S_00d68c00_Arr
{
    S_00d68c00_Elem** data;
    int size;
    int cap;
};

struct S_00d68c00_List
{
    char** data;
    int size;
    int cap;
};

struct S_00d68c00_Item
{
    int unk00;
    S_00d68c00_List list;
};





hkThreadMemory* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl ResizeAudioStream(hkMemoryAllocator* heap, void* arr, int elemSize) throw();

struct S_00d68c00_Obj
{
    virtual void v0() throw();
    virtual void v1(S_00d68c00_Arr* arr, void* p, char* name, void* dat, int zero) throw();
    virtual void v2() throw();
    virtual void v3(int a, char* name, void* dat) throw();
};

struct S_00d68c00_Log
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3(int a, int b, char* msg, const char* file, int line) throw();
};
extern S_00d68c00_Log* DAT_01268360;

struct S_00d68c00_Real
{
    float v;
    void FUN_00de3050() throw();
};

struct S_00d68c00_Query
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00de3060(S_00d68c00_Real* r) throw();
    void UpdateFields_00de4420(int a, S_00d68c00_Arr* arr) throw();
};

struct S_00d68c00_Str
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size) throw();
    void ProcessAndReturnValue_00cc01c0(const char* s) throw();
    void FUN_00cc00e0() throw();
};

struct S_00d68c00_Main
{
    virtual void m0() throw();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_00d68c00_Obj* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int FindKeyIndex(int key) throw();
};

struct S_00d68c00_Listener
{
    virtual void hkpConvexRadiusViewer_entityAddedCallback(S_00d68c00_Arg* a2) throw();
    int unk04;
    S_00d68c00_Item** unk08;
    int unk0c;
    int unk10;
    void* unk14;
    void* unk18;
};

struct S_00d68c00_Sub : S_00d68c00_Main, S_00d68c00_Listener
{
    virtual void hkpConvexRadiusViewer_entityAddedCallback(S_00d68c00_Arg* a2) throw();
};

// Collects elements via FUN_00de4420, logs and drops those with unk50 == 6 and unk08 == 0, hands the rest to unk18's v1 and v3, then calls v0(1) on each.
// @fnv 0x00d68c00
// src: HAVOK_LIB 0x00d68c00
void S_00d68c00_Sub::hkpConvexRadiusViewer_entityAddedCallback(S_00d68c00_Arg* a2) throw()
{
    if (a2->unk10 == 0)
        return;
    int idx = FindKeyIndex(a2->unk08);
    if (idx < 0)
        return;
    S_00d68c00_Item* item = S_00d68c00_Listener::unk08[idx];
    S_00d68c00_Arr arr;
    arr.data = 0;
    arr.size = 0;
    arr.cap = 0x80000000;
    S_00d68c00_Real radius;
    radius.FUN_00de3050();
    S_00d68c00_Query query;
    query.FUN_00de3060(&radius);
    query.UpdateFields_00de4420(a2->unk10, &arr);
    for (int i = arr.size - 1; i >= 0; i--)
    {
        S_00d68c00_Elem* e = arr.data[i];
        if (e->unk50 == 6 && e->unk08 == 0)
        {
            unsigned int buf[128];
            S_00d68c00_Str msg;
            msg.FUN_00cb1600((char*)buf, 0x200);
            msg.ProcessAndReturnValue_00cc01c0("Unable to build display geometry from hkpShape geometry data");
            DAT_01268360->v3(0, -1, (char*)buf, ".\\VisualDebugger\\Viewer\\Collide\\hkpConvexRadiusViewer.cpp", 0xa7);
            msg.FUN_00cc00e0();
            arr.size--;
            if (arr.size != i)
                arr.data[i] = arr.data[arr.size];
        }
    }
    if (arr.size > 0)
    {
        char* name = (char*)a2 + 0x13;
        S_00d68c00_List* list = &item->list;
        hkThreadMemory* r = hkMemoryRouter_getInstance();
        if (list->size == (list->cap & 0x3fffffff))
            ResizeAudioStream(&r->heap(), list, 4);
        char** p = list->data + list->size;
        for (int k = 0; k < 1; k++)
            p[k] = name;
        list->size++;
        S_00d68c00_Main::unk18->v1(&arr, &a2->unkf0, name, DAT_01269010, 0);
        if (a2->unke8 == 5)
            S_00d68c00_Main::unk18->v3((int)S_00d68c00_Listener::unk14, name, DAT_01269010);
        else
            S_00d68c00_Main::unk18->v3((int)S_00d68c00_Listener::unk18, name, DAT_01269010);
    }
    for (int j = 0; j < arr.size; j++)
    {
        S_00d68c00_Elem* e = arr.data[j];
        if (e)
            e->v0(1);
    }
    hkMemoryAllocator& heap = (hkMemoryRouter_getInstance()->heap());
    arr.size = 0;
    if ((arr.cap & 0x80000000) == 0)
        heap.bufFree(arr.data, (arr.cap & 0x3fffffff) * 4);
}
}  // namespace fnv_00d68c00

namespace fnv_00d68e00 {
extern "C" hkThreadMemory* __cdecl hkMemoryRouter_getInstance();

struct TargetAgent
{
    char pad[4];
    short m_usMemSizeAndFlags;
    TargetAgent* FUN_00d68b90(void* arg1);
};

// Allocates a 0x44-byte TargetAgent chunk, sets its size field, calls FUN_00d68b90, and returns the result offset by 8 bytes or null.
// @fnv 0x00d68e00
// src: XBOX_PDB 0x00d68e00
void* __cdecl hkpConvexRadiusViewer_create(void* arg1)
{
    TargetAgent* agent = (TargetAgent*)hkMemoryRouter_getInstance()->allocateChunk(0x44);
    agent->m_usMemSizeAndFlags = 0x44;
    TargetAgent* res = agent->FUN_00d68b90(arg1);
    return res ? (char*)res + 8 : 0;
}
}  // namespace fnv_00d68e00

struct VObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(void* a, void* b, int c);
};

struct HkArr
{
    void** data;
    int size;
    unsigned int m_iCapacity;
};

struct SpawnItem
{
    int unk00;
    HkArr arr;
};



void __cdecl hkArrayUtil__reserve(void* alloc, void* arr, int n, int elemSize);

struct FUN_00d68b20_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    VObj* m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SpawnItem** m_30;

    void ClearItemArray(int idx);
};

// Calls v05 on each element of the item at idx, then conditionally calls FUN_00c908c0 on its array and sets the array size to 0.
// @fnv 0x00d68b20
// src: GUESS 0x00d68b20 (confidence: medium)
void FUN_00d68b20_cls::ClearItemArray(int idx)
{
    SpawnItem* item = m_30[idx];
    for (int i = 0; i < item->arr.size; ++i)
    {
        m_18->v05(item->arr.data[i], DAT_01269010, 0);
    }
    HkArr* a = &item->arr;
    hkThreadMemory* h = hkMemoryRouter_getInstance();
    void* alloc = *(void* volatile*)&h->m_pMemoryAllocator;
    int cap = (int)(a->m_iCapacity & 0x3fffffff);
    if (cap < 0)
    {
        hkArrayUtil__reserve(alloc, a, (cap + cap > 0) ? cap + cap : 0, 4);
    }
    a->size = 0;
}
