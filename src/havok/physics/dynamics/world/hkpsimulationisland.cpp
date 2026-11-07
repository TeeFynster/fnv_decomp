
// src/havok/physics/dynamics/world/hkpsimulationisland.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpsimulationisland.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkpConstraintOwner.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkpConstraintInfo.h"
#include "../../../../../include/hkpAgentNnTrack.h"

// Preserve the allocator's indirect calls while the shared methods are non-virtual.
static __forceinline void FreeAudioArray(hkMemoryAllocator* allocator, void* memory, unsigned int size) throw()
{
    typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
    ((FreeFunction)(*(void***)allocator)[4])(allocator, memory, size);
}

static __forceinline void FreeAudioMemory(hkMemoryAllocator* allocator, void* memory, unsigned int size) throw()
{
    typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
    ((FreeFunction)(*(void***)allocator)[2])(allocator, memory, size);
}

struct S_00d070c0_Inner
{
    int unk00;
    int unk04;
    void* unk08;
};

struct S_00d070c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00d070c0_Inner* unk14;
};

void __cdecl hkpWorldOperationUtil_addConstraintToCriticalLockedIsland(void* a, S_00d070c0* obj);

// @fnv 0x00d070c0
// src: HAVOK_SRC 0x00d070c0
void __stdcall hkpSimulationIsland_addConstraintToCriticalLockedIsland(S_00d070c0* obj)
{
    hkpWorldOperationUtil_addConstraintToCriticalLockedIsland(obj->unk14->unk08, obj);
}

struct Holder
{
    int unk00;
    int unk04;
    void* m_pFlagTarget;
};

struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Holder* m_pHolder;
};

void __cdecl Object_NotifyAndDetachRecord(void* apTarget, Owner* apOwner);

// @fnv 0x00d070e0
// src: HAVOK_SRC 0x00d070e0
void __stdcall hkpSimulationIsland_removeConstraintFromCriticalLockedIsland(Owner* apOwner)
{
    Object_NotifyAndDetachRecord(apOwner->m_pHolder->m_pFlagTarget, apOwner);
}

struct FUN_00d07130Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct SaveBuffer
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
    unsigned char unk24;
    unsigned char flags;
    unsigned short unk26;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    FUN_00d07130Arg** entries;
    int count;
    void RemoveEntry(FUN_00d07130Arg* value);
};
// Clears the matching entry pointer in entries, zeroes the value's unk0c, and updates flags.
// @fnv 0x00d07130
void SaveBuffer::RemoveEntry(FUN_00d07130Arg* apEntry)
{
    int length = count;
    int index = 0;
    if (length > 0)
    {
        FUN_00d07130Arg** current = entries;
        do
        {
            if (*current == apEntry)
                goto found;
            ++index;
            ++current;
        } while (index < length);
    }
    index = -1;
found:
    entries[index] = 0;
    apEntry->unk0c = 0;
    flags = (flags & 0xdd) | 0x11;
}

struct FUN_00d07180_s
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int MergeFrom(FUN_00d07180_s* other);
};
// Merges another instance into this one: takes the larger unk08, adds unk0c and unk10, adds unk14 and returns the other's unk14.
// @fnv 0x00d07180
int FUN_00d07180_s::MergeFrom(FUN_00d07180_s* other)
{
    int incoming = other->unk08;
    int current = unk08;
    if (current > incoming)
        incoming = current;
    unk08 = incoming;
    unk0c += other->unk0c;
    unk10 += other->unk10;
    int last = other->unk14;
    unk14 += last;
    return last;
}

struct S_00d071b0_Item
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
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned short m_usIndex;
    unsigned short unkAA;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
};
struct S_00d071b0_Array
{
    S_00d071b0_Item** m_ppItems;
    unsigned int m_uiCount;
    S_00d071b0_Item* GetAt(unsigned int i) const
    {
        return m_ppItems[i];
    }
    void SetAt(unsigned int i, S_00d071b0_Item* p)
    {
        m_ppItems[i] = p;
    }
    unsigned int GetSize() const
    {
        return m_uiCount;
    }
    void Remove(S_00d071b0_Item* pItem)
    {
        m_ppItems[pItem->m_usIndex] = m_ppItems[m_uiCount - 1];
        m_ppItems[pItem->m_usIndex]->m_usIndex = pItem->m_usIndex;
        m_uiCount--;
    }
};
struct S_00d071b0
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
    unsigned char unk24;
    unsigned char m_ucFlags;
    unsigned short unk26;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    S_00d071b0_Array m_kUnsortedGeometryList;
    void RemoveItem(S_00d071b0_Item* pItem);
};
// Removes pItem from the item array, clears its unkCC and sets m_usIndex to 0xffff, then updates m_ucFlags.
// @fnv 0x00d071b0
void S_00d071b0::RemoveItem(S_00d071b0_Item* pItem)
{
    m_kUnsortedGeometryList.Remove(pItem);
    pItem->unkCC = 0;
    pItem->m_usIndex = 0xffff;
    m_ucFlags = (m_ucFlags & ~2) | 1;
}

struct D077D0MemoryRouter
{
    char* m_stackCurrent;

    void* stackAllocInts(int numInts)
    {
        char* p = m_stackCurrent;
        m_stackCurrent = p + ((numInts * 4 + 127) & ~127);
        return p;
    }
    void stackFree(void* p)
    {
        m_stackCurrent = (char*)p;
    }
};

extern "C" D077D0MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct D077D0LocalBuffer
{
    void* m_data;
    int m_iElementCount;
};

struct D077D0BitField
{
    int unk00;
    int unk04;

    D077D0BitField(void* const& buffer, int numBits);
};

struct D077D0Object
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
    int m_iCapacity;

    bool CheckConnectivity(D077D0BitField& bits);
    bool hkpSimulationIsland_isFullyConnected();
};

// @fnv 0x00d077d0
// src: HAVOK_LIB 0x00d077d0
bool D077D0Object::hkpSimulationIsland_isFullyConnected()
{
    D077D0LocalBuffer buffer;
    buffer.m_data = hkMemoryRouter_getInstance().stackAllocInts(m_iCapacity);
    D077D0BitField bits(buffer.m_data, m_iCapacity);
    bool result = CheckConnectivity(bits);
    hkMemoryRouter_getInstance().stackFree(buffer.m_data);
    return result;
}

struct GlobalObjectO2_00d472a0
{
};
extern GlobalObjectO2_00d472a0 g_012687cc;
// @fnv 0x00d078d0
// src: GUESS 0x00d078d0 (confidence: low)
GlobalObjectO2_00d472a0* hkpSimulationIsland_GetField012687ccAddress()
{
    return &g_012687cc;
}

// FUN_00d07100: OR a flag byte into a sub-object's flags field.
// Sub-object pointer lives at +0x30 of the owner; flags byte at +0x12 of it.

// @fnv 0x00d07100
// src: HAVOK_LIB 0x00d07100
void __stdcall hkpSimulationIsland_addCallbackRequest(char* owner, unsigned char bits)
{
    char* sub = *(char**)(owner + 0x30);
    *(unsigned char*)(sub + 0x12) |= bits;
}

struct S_00d074c0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00d074c0_Router
{
    int unk00, unk04, unk08, unk0C;
    S_00d074c0_Heap* unk10;
    static S_00d074c0_Router& GetMonitorStream();
    S_00d074c0_Heap& heap()
    {
        return *unk10;
    }
};

template <class T>
struct S_00d074c0_Array
{ // local form of hkArrayBase: 0x00d074c0 needs the local constructor/destructor split; the shared lifetime form changes extent from 594 to 610 bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    void _clearAndDeallocate(S_00d074c0_Heap& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~S_00d074c0_Array() throw()
    {
        _clearAndDeallocate(S_00d074c0_Router::GetMonitorStream().heap());
    }
};

template <class T, int N> struct S_00d074c0_InplaceArray : S_00d074c0_Array<T>
{
    T m_kStorage[N];
    S_00d074c0_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
    ~S_00d074c0_InplaceArray() throw()
    {}
};

struct S_00d074c0_Entity;
struct S_00d074c0_Collidable
{
    int unk00, unk04, unk08, unk0C;
    signed char m_iOwnerOffset;
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};
struct S_00d074c0_CollisionEntry
{
    void* m_pAgentEntry;
    S_00d074c0_Collidable* m_pCollidable;
};
struct S_00d074c0_ConstraintInternal
{
    int unk00;
    S_00d074c0_Entity* m_kActorEntries[2];
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct S_00d074c0_Entity
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
    S_00d074c0_Array<S_00d074c0_CollisionEntry> m_kCollisionEntries;
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
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned short m_usStorageIndex;
    unsigned short unkAA;
    S_00d074c0_ConstraintInternal* m_constraintsData;
    unsigned short m_constraintsSize;
    unsigned short m_constraintsCap;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char m_bFlag;
    unsigned char unkE9;
    unsigned short unkEA;
    bool isFixed() const
    {
        return m_bFlag == 5;
    }
};
struct S_00d074c0_Action
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void GetEntities(S_00d074c0_Array<S_00d074c0_Entity*>& entitiesOut) throw();
};
struct S_00d074c0_FixedArray
{
    int* m_data;
};
struct S_00d074c0_UnionFind
{
    S_00d074c0_FixedArray* m_pParentArray;
    int m_iNodeCount;
    void Union(int i, int j) throw();
    bool isOneGroup() const
    {
        return m_pParentArray->m_data[0] == -m_iNodeCount;
    }
};

struct S_00d074c0_Island
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
    S_00d074c0_Array<S_00d074c0_Action*> m_ppActions;
    int unk44;
    S_00d074c0_Array<S_00d074c0_Entity*> m_kActorEntries;
    bool CheckConnectivity(S_00d074c0_UnionFind& checkConnectivityOut) throw();
};

// Unions entities linked by collision entries, constraints and actions in checkConnectivityOut and returns whether they form one group.
// @fnv 0x00d074c0
bool S_00d074c0_Island::CheckConnectivity(S_00d074c0_UnionFind& aUnionFind) throw()
{
    {
        for (int e = 0; e < m_kActorEntries.GetLogicalSize(); e++)
        {
            S_00d074c0_Entity* entity = m_kActorEntries[e];
            const S_00d074c0_Array<S_00d074c0_CollisionEntry>& collisionEntries = entity->m_kCollisionEntries;
            for (int i = 0; i < collisionEntries.GetLogicalSize(); i++)
            {
                S_00d074c0_Entity* otherEntity =
                    static_cast<S_00d074c0_Entity*>(collisionEntries[i].m_pCollidable->getOwner());
                if (!otherEntity->isFixed())
                {
                    aUnionFind.Union(e, otherEntity->m_usStorageIndex);
                    if (aUnionFind.isOneGroup())
                    {
                        return true;
                    }
                }
            }
        }
    }
    {
        for (int e = 0; e < m_kActorEntries.GetLogicalSize(); e++)
        {
            S_00d074c0_Entity* entity = m_kActorEntries[e];
            for (int c = 0; c < entity->m_constraintsSize; c++)
            {
                S_00d074c0_ConstraintInternal& ci = entity->m_constraintsData[c];
                if (!ci.m_kActorEntries[0]->isFixed() && !ci.m_kActorEntries[1]->isFixed())
                {
                    aUnionFind.Union(ci.m_kActorEntries[0]->m_usStorageIndex, ci.m_kActorEntries[1]->m_usStorageIndex);
                    if (aUnionFind.isOneGroup())
                    {
                        return true;
                    }
                }
            }
        }
    }
    {
        S_00d074c0_InplaceArray<S_00d074c0_Entity*, 10> entities;
        for (int a = 0; a < m_ppActions.GetLogicalSize(); a++)
        {
            if (m_ppActions[a])
            {
                entities.clear();
                m_ppActions[a]->GetEntities(entities);
                int j = 0;
                int firstNonFixed = -1;
                for (; firstNonFixed == -1 && j < entities.GetLogicalSize(); j++)
                {
                    if (!entities[j]->isFixed())
                    {
                        firstNonFixed = j;
                    }
                }
                for (; j < entities.GetLogicalSize(); j++)
                {
                    if (!entities[j]->isFixed())
                    {
                        aUnionFind.Union(entities[firstNonFixed]->m_usStorageIndex, entities[j]->m_usStorageIndex);
                        if (aUnionFind.isOneGroup())
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return aUnionFind.isOneGroup();
}

namespace fnvc_adapt {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
}
void __cdecl ResizeAudioStream(hkMemoryAllocator* apAllocator, void* apContainer, unsigned int auiElemSize);

struct PointerList
{
    void** m_pData;
    unsigned int m_uCount;
    unsigned int m_uCapFlags;
};

struct FUN_00d07470_cls;

struct ListItem
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d07470_cls* m_pSharedOwner;
};

struct FUN_00d07470_cls
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
    PointerList m_kNode;

    void AddItem(ListItem* apItem);
};

// Appends apItem to the pointer list, growing it via the allocator when full, and sets the item's back-pointer to this.
// @fnv 0x00d07470
void FUN_00d07470_cls::AddItem(ListItem* apItem)
{
    PointerList* pItems = &m_kNode;
    hkMemoryRouter* pHolder = fnvc_adapt::hkMemoryRouter_getInstance();
    if (pItems->m_uCount == (pItems->m_uCapFlags & 0x3fffffffu))
    {
        ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap), pItems, 4);
    }

    void** pSlot = (void**)((unsigned int)pItems->m_pData + *(volatile unsigned int*)&pItems->m_uCount * 4);
    *pSlot = apItem;
    pItems->m_uCount++;

    apItem->m_pSharedOwner = this;
}

namespace fnv_00d07720 {
namespace fnvc_adapt {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
}
extern int DAT_010ccf28;
extern int DAT_0102e388;

struct FUN_00d07720_cls
{
    int m_vptr00;
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
    void* m_pData3;
    int m_iCount3;
    unsigned int m_uCapBits3;
    int unk44;
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    int unk54;
    int unk58;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void ResetArrays();
};

// @fnv 0x00d07720
void FUN_00d07720_cls::ResetArrays()
{
    m_vptr00 = (int)&DAT_010ccf28;

    hkMemoryRouter* pHolder = fnvc_adapt::hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapBits1 = m_uCapBits1;
    m_iCount1 = 0;
    if ((uCapBits1 & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator, m_pData1, (uCapBits1 & 0x3fffffffu) * 4);
    }
    m_pData1 = 0;
    m_uCapBits1 = 0x80000000u;

    hkMemoryRouter* pHolder2 = fnvc_adapt::hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((uCapBits2 & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator2, m_pData2, (uCapBits2 & 0x3fffffffu) * 4);
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;

    hkMemoryRouter* pHolder3 = fnvc_adapt::hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator3 = reinterpret_cast<hkMemoryAllocator*>(pHolder3->m_heap);
    unsigned int uCapBits3 = m_uCapBits3;
    m_iCount3 = 0;
    if ((uCapBits3 & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator3, m_pData3, (uCapBits3 & 0x3fffffffu) * 4);
    }
    m_pData3 = 0;
    m_uCapBits3 = 0x80000000u;

    *(volatile int*)&m_vptr00 = (int)&DAT_0102e388;
}
}  // namespace fnv_00d07720

namespace fnv_00d078e0 {
namespace fnvc_adapt {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
}

struct FUN_00d078e0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void ResetArrays();

    FUN_00d078e0_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// @fnv 0x00d078e0
FUN_00d078e0_cls* FUN_00d078e0_cls::Destroy(unsigned char acFlags)
{
    ResetArrays();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = fnvc_adapt::hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        FreeAudioMemory(pAllocator, this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d078e0

// 0x00d07120  bare ret
// @fnv 0x00d07120
// src: COMMUNITY 0x00d07120
void nullsub_10()
{}

// SaveIsland

struct FUN_00d07210_Writer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Begin(const char* name, void* ptr, int flag);
    virtual void v10();
    virtual void Array(int type, const char* name, void* data, int size, int alloc);
    virtual void Block(const char* name);
    virtual void End();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned char m_force;
};

struct FUN_00d07210_ConFlags
{
    int unk00;
    unsigned short m_flags;
    unsigned short unk06;
};

struct FUN_00d07210_ConInstance
{
    int unk00;
    unsigned short m_flags;
    unsigned short unk06;
    int unk08;
    FUN_00d07210_ConFlags* m_pData;
};

struct FUN_00d07210_Constraint
{
    FUN_00d07210_ConInstance* m_pConstraintInstance;
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
};

struct FUN_00d07210_World
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    void* unk78;
};

struct FUN_00d07210_Island
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    FUN_00d07210_World* unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    S_00d074c0_Array<S_00d074c0_Action*> m_ppActions;
    int unk44;
    S_00d074c0_Array<S_00d074c0_Entity*> m_kActorEntries;
    int unk54;
    hkpAgentNnTrack m_pAgents;
    void SaveIsland(FUN_00d07210_Writer* save, int unkArg);
};

int __cdecl hkStatisticsCollector_getAllocatedSize(void* data, int bytes);
void __cdecl CollectSectors(void* agents, FUN_00d07210_Writer* save);
void __cdecl hkpAgentMachineUtil_calcNnStatistics(void* agents, void* world, FUN_00d07210_Writer* save);

// Serializes the island's entity and action pointer arrays, per-entity constraints, agents and collision agents through the writer.
// @fnv 0x00d07210
void FUN_00d07210_Island::SaveIsland(FUN_00d07210_Writer* save, int)
{
    if ((m_kActorEntries.m_iCapacityState & 0x80000000) == 0 || save->m_force)
    {
        int alloc = hkStatisticsCollector_getAllocatedSize(m_kActorEntries.m_data, m_kActorEntries.getCapacity() * 4);
        save->Array(3, "EntityPtrs", m_kActorEntries.m_data, m_kActorEntries.GetLogicalSize() * 4, alloc);
    }

    for (int i = 0; i < m_kActorEntries.GetLogicalSize(); i++)
    {
        S_00d074c0_Entity* entity = m_kActorEntries[i];
        save->Begin("Entity", entity, 0);
        save->Block("Constraints");
        if ((entity->m_constraintsCap & 0x8000) == 0 || save->m_force)
        {
            save->Array(3, "ConMstPtr", entity->m_constraintsData, entity->m_constraintsSize * 48,
                        (entity->m_constraintsCap & 0x3fff) * 48);
        }
        for (int j = 0; j < entity->m_constraintsSize; j++)
        {

            if (((FUN_00d07210_Constraint*)&entity->m_constraintsData[j])->m_pConstraintInstance->m_flags & 0x7fff)
                save->Begin("ConInstance",
                            ((FUN_00d07210_Constraint*)&entity->m_constraintsData[j])->m_pConstraintInstance, 0);
            if (((FUN_00d07210_Constraint*)&entity->m_constraintsData[j])->m_pConstraintInstance->m_pData->m_flags &
                0x7fff)
                save->Begin("ConData",
                            ((FUN_00d07210_Constraint*)&entity->m_constraintsData[j])->m_pConstraintInstance->m_pData,
                            0);
        }
        save->End();
    }

    if ((m_ppActions.m_iCapacityState & 0x80000000) == 0 || save->m_force)
    {
        int alloc;
        {
            int capacity = m_ppActions.getCapacity();
            void* data = m_ppActions.m_data;
            alloc = hkStatisticsCollector_getAllocatedSize(data, capacity * 4);
        }
        save->Array(3, "ActionPtrs", m_ppActions.m_data, m_ppActions.GetLogicalSize() * 4, alloc);
    }

    for (int i = 0; i < m_ppActions.GetLogicalSize(); i++)
    {
        S_00d074c0_Action* action = m_ppActions[i];
        save->Begin("Actions", action, 0);
    }

    CollectSectors(&m_pAgents, save);
    save->Block("CollAgents");
    hkpAgentMachineUtil_calcNnStatistics(&m_pAgents, unk18->unk78, save);
    save->End();
}

extern const void* DAT_010ccf28[];  // hkpSimulationIsland vftable (not in the symbols DB)



// The shared hkpConstraintInfo header is not available yet; this is its four-int layout.

__forceinline hkMultiThreadCheck::hkMultiThreadCheck()
{
    m_uiThreadId = UNMARKED;
    m_usMarkedForWrite = 0x8000;
}

struct hkpWorld;
struct hkpAction;
struct hkpEntity;
// These construction helpers install the game vtable explicitly; suppress helper vtable stores.
struct __declspec(novtable) IslandBaseQ : hkpConstraintOwner
{
    // Complete the constraint-info block after the shared owner's m_iMaxSchemaSize.
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    hkpWorld* m_pOwningWorld;
    int m_iConstraintCount;
    unsigned short m_usStorageIndex;
    unsigned short m_usDirtyListIndex;
    unsigned char m_ucSplitCheckFrameCounter;
    unsigned char m_bSplitCheckRequested : 2;
    unsigned char m_isSparse : 2;
    unsigned char m_bActionListCleanupNeeded : 2;
    unsigned char m_bAllowIslandLocking : 2;
    unsigned char m_ucMultiThreadCheckFlags;
    unsigned char m_bActiveMark;
    IslandBaseQ(hkpWorld* world) : m_pOwningWorld(world), m_usDirtyListIndex(0xffff)
    {
        *(const void**)this = DAT_010ccf28;
        m_ucMultiThreadCheckFlags = 5;
        m_bSplitCheckRequested = 0;
        m_bActionListCleanupNeeded = 0;
    }
};

struct __declspec(novtable) FUN_00d07830 : IslandBaseQ
{
    hkMultiThreadCheck m_kMultiThreadCheck;
    float m_fIslandValueBeforeActions1;
    float m_fIslandValueBeforeActions2;
    hkArray<hkpAction*> m_ppActions;
    float m_fIslandValueBeforeEntities;
    hkInplaceArray<hkpEntity*, 1> m_kActorEntries;
    hkpAgentNnTrack m_kAgentNnTrack;

    FUN_00d07830(hkpWorld* world);
};

// Constructs the object: sets two floats to 0 and one to -10, clears constraint info, the sparse and island-locking flags, and the constraint count.
// @fnv 0x00d07830
FUN_00d07830::FUN_00d07830(hkpWorld* world)
    : IslandBaseQ(world), m_fIslandValueBeforeActions1(0.0f), m_fIslandValueBeforeActions2(0.0f),
      m_fIslandValueBeforeEntities(-10.0f)
{
    m_bAllowIslandLocking = 0;
    reinterpret_cast<hkpConstraintInfo*>(&m_iMaxSchemaSize)->clear();
    m_isSparse = 0;
    m_iConstraintCount = 0;
}

namespace fnv_00d07420 {
// FUN_00d07420: append a pointer to a list owned by this object, growing via the global allocator.

struct ItemList
{
    void** m_data;            // +0x00
    int m_uiItemCount;        // +0x04
    unsigned int m_capFlags;  // +0x08 (low 30 bits = capacity)
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* alloc, void* list, unsigned int n);

struct FUN_00d07420_cls
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
    ItemList m_kNode;  // +0x48
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
    int unkA0;
    int unkA4;
    unsigned short m_a8;  // +0xa8
    unsigned short unkAA;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    FUN_00d07420_cls* m_cc;  // +0xcc

    void hkpSimulationIsland_internalAddEntity(FUN_00d07420_cls* item);
};

// Sets item's parent to this and its index to the current count, then appends item to this object's item list, growing it via FUN_00c90940 when full.
// @fnv 0x00d07420
// src: HAVOK_LIB 0x00d07420
void FUN_00d07420_cls::hkpSimulationIsland_internalAddEntity(FUN_00d07420_cls* item)
{
    item->m_cc = this;
    item->m_a8 = (unsigned short)m_kNode.m_uiItemCount;
    ItemList* list = &m_kNode;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    if (list->m_uiItemCount == (int)(list->m_capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_heap, list, 4);
    }
    void** slot = list->m_data + list->m_uiItemCount;
    *slot = item;
    *slot = item;  // repeated store: keeps the slot address materialised in a register
    list->m_uiItemCount++;
}
}  // namespace fnv_00d07420
