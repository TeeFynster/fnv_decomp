
// src/havok/physics/dynamics/world/util/hkpworldagentutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldagentutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/BSAudio.h"

struct S_00cc10b0_World
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
    int m_80;
};

struct S_00cc10b0_Island
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_00cc10b0_World* m_pOwningWorld;
    int unk1c;
    int unk20;
    unsigned char unk24;
    unsigned char m_flags25;
    unsigned char unk26;
    unsigned char unk27;
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
    int m_58;

    void markForCheck()
    {
        m_flags25 = (m_flags25 & ~2) | 1;
    }
};

struct S_00cc10b0_Entity
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
    S_00cc10b0_Island* m_pCurrentSimulationIsland;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char m_bFlag;
    unsigned char unke9;
    unsigned short unkea;
};

struct S_00cc10b0_Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;

    S_00cc10b0_Entity* getOwner()
    {
        return (S_00cc10b0_Entity*)((char*)this + m_iOwnerOffset);
    }
};

struct S_00cc10b0_Listener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
};

struct S_00cc10b0_Agent
{
    int unk00;
    int unk04;
    S_00cc10b0_Listener* m_kListener;
    int unk0c;
    S_00cc10b0_Collidable* m_pCollidableA;
    S_00cc10b0_Collidable* m_pCollidableB;
};

S_00cc10b0_Island* __cdecl PickIslandByValue(S_00cc10b0_Agent* agent, S_00cc10b0_Island* a, S_00cc10b0_Island* b);
void __cdecl hkAgentNnMachine_DestroyAgent(int* p, S_00cc10b0_Agent* agent, int w, S_00cc10b0_Island* island);

// @fnv 0x00cc10b0
// src: HAVOK_LIB 0x00cc10b0
void __cdecl hkpWorldAgentUtil_removeAgent(S_00cc10b0_Agent* agent)
{
    S_00cc10b0_Entity* entityA = agent->m_pCollidableA->getOwner();
    S_00cc10b0_Island* islandA = entityA->m_pCurrentSimulationIsland;
    S_00cc10b0_Entity* entityB = agent->m_pCollidableB->getOwner();
    S_00cc10b0_Island* islandB = entityB->m_pCurrentSimulationIsland;
    S_00cc10b0_Island* island;
    if (islandA == islandB)
    {
        island = islandA;
        island->markForCheck();
    }
    else if (entityA->m_bFlag == 5)
    {
        island = islandB;
    }
    else if (entityB->m_bFlag == 5)
    {
        island = islandA;
    }
    else
    {
        island = PickIslandByValue(agent, islandA, islandB);
        islandA->markForCheck();
        entityB->m_pCurrentSimulationIsland->markForCheck();
    }
    S_00cc10b0_Listener* listener = agent->m_kListener;
    hkAgentNnMachine_DestroyAgent(&island->m_58, agent, island->m_pOwningWorld->m_80, island);
    listener->v24();
}

// Exe 0x00cc1160: unit-local Interface view; declarations and layout are preserved.
struct HkpworldagentutilInterfaceView
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void Invoke(void* value);
};
struct Holder
{
    int unk00;
    int unk04;
    HkpworldagentutilInterfaceView* interfaceObject;
};
struct Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Holder* holder;
};
struct Root
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char displacement;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
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
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Root* root;
};
void __cdecl hkpWorldAgentUtil_removeAgent(Owner* owner);
// Calls Invoke on the interface object reached through root's displacement-indexed entry, then calls FUN_00cc10b0.
// @fnv 0x00cc1160
// src: HAVOK_LIB 0x00cc1160
void __cdecl hkpWorldAgentUtil_removeAgentAndItsToiEvents(Owner* owner)
{
    Owner* pOwner = owner;
    char* pRootBase = (char*)pOwner->root;
    int iDisplacement = ((signed char*)pRootBase)[0x10];
    Entry* entry = *(Entry**)(pRootBase + iDisplacement + 0xcc);
    Holder* holder = entry->holder;
    HkpworldagentutilInterfaceView* pInterface = holder->interfaceObject;
    pInterface->Invoke(pOwner);
    hkpWorldAgentUtil_removeAgent(pOwner);
}

struct EventRecord
{
    unsigned char type;
    unsigned char dispatchId;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    void* value08;
    void* unk0c;
    void* source10;
    void* target14;
    int unk18;
    int unk1c;
    void* data20;
    int unk24;
    int unk28;
    int unk2c;
    void* data30;
};
struct EventArrayEntry
{
    EventRecord* record;
    unsigned int unk04;
};
struct EventArray
{
    EventArrayEntry* data;
    int count;
    int capacity;
};
struct SourceObject
{
    void __thiscall CopyAndSortGeometryList(EventArray* events);
};
struct EventSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SourceObject events;
};
struct DispatchContext
{
    void* table;
};
typedef void(__cdecl* EventHandler)(void*, void*, void*, void*, void*, void*, void*);
struct MemoryAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void Free(void* pointer, unsigned int bytes);
};
extern BSAudio* __cdecl hkMemoryRouter_getInstance();
// @fnv 0x00cc1190
void __cdecl DispatchEvents(EventSource* source, DispatchContext* context)
{
    EventArray events;
    events.data = 0;
    events.count = 0;
    events.capacity = (int)0x80000000;
    source->events.CopyAndSortGeometryList(&events);
    int index = 0;
    if (events.count > 0)
    {
        do
        {
            EventRecord* event = events.data[index].record;
            unsigned char handlerIndex = event->dispatchId;
            EventHandler handler = *(EventHandler*)((char*)context->table + 0x16c8 + handlerIndex * 0x50);
            if (handler)
            {
                void* sourceObject = event->source10;
                void* target = event->target14;
                char sourceOffset = *((char*)sourceObject + 0x10);
                void* sourceField = (char*)sourceObject + sourceOffset;
                void* argument = *((char*)sourceField + 0xe8) == 5
                                     ? *(void**)((char*)target + *((char*)target + 0x10) + 0xcc)
                                     : *(void**)((char*)sourceField + 0xcc);
                void* eventData = event->type == 4 ? (char*)event + 0x30 : (char*)event + 0x20;
                handler(event, eventData, sourceObject, target, context, event->value08, argument);
            }
            ++index;
        } while (index < events.count);
    }
    BSAudio* audio = hkMemoryRouter_getInstance();
    MemoryAllocator* allocator = reinterpret_cast<MemoryAllocator* volatile&>(audio->pListener);
    events.count = 0;
    if (!(events.capacity & (int)0x80000000))
        allocator->Free(events.data, (events.capacity & 0x3fffffff) * 8);
}

struct ItemEntry
{
    void* m_pInventoryEntryData;
    unsigned int unk04;
};

struct ItemOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    ItemEntry* m_pEntries;
    int m_iArrayLength;
};

void __cdecl hkAgentNnMachine_InvalidateTimInAgent(void* pItem, void* pContext);

// @fnv 0x00cc0ea0
// src: HAVOK_LIB 0x00cc0ea0
void __cdecl hkpWorldAgentUtil_invalidateTim(ItemOwner* pOwner, void* pContext)
{
    for (int i = 0; i < pOwner->m_iArrayLength; ++i)
    {
        hkAgentNnMachine_InvalidateTimInAgent(pOwner->m_pEntries[i].m_pInventoryEntryData, pContext);
    }
}

struct S_00cc0ed0_Rec
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char size;
};
struct S_00cc0ed0_Blocks
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
    int m58;
    S_00cc0ed0_Rec** volatile m5c;
    int m60;
};

void __cdecl DispatchSlotCallback(S_00cc0ed0_Rec* r, float a, float b, int c);

// Iterates over the block pointers in m5c, calling DispatchSlotCallback on each record up to the block end (m58 for the last block, 0x200 otherwise).
// @fnv 0x00cc0ed0
void __cdecl ProcessBlocks(S_00cc0ed0_Blocks* s, float a2, float a3, int a4)
{
    int i = 0;
    if (s->m60 > 0)
    {
        do
        {
            S_00cc0ed0_Rec* p = s->m5c[i];
            i++;
            char* end;
            if (i == s->m60)
            {
                end = (char*)p + s->m58;
            }
            else
            {
                end = (char*)p + 0x200;
            }
            while ((char*)p < end)
            {
                DispatchSlotCallback(p, a2, a3, a4);
                p = (S_00cc0ed0_Rec*)((char*)p + p->size);
            }
        } while (i < s->m60);
    }
}

struct S_00cc0f40_Prop
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short w20;
};
struct S_00cc0f40_Body
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
    signed char b8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    S_00cc0f40_Prop* prop;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    char kind;
};
struct S_00cc0f40_Flag
{
    char v;
};
struct S_00cc0f40_Type
{
    int unk00;
    int unk04;
    int unk08;
    int kind;
};
struct S_00cc0f40_Coll
{
    S_00cc0f40_Type* type;
    int unk04;
    int unk08;
    int unk0c;
    signed char off;
};
struct S_00cc0f40_Fn
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(S_00cc0f40_Coll* a, S_00cc0f40_Coll* b, struct S_00cc0f40_In* in);
};
struct S_00cc0f40_Tbl
{
    int unk00;
    int unk04;
    int unk08;
    S_00cc0f40_Fn* fn[64];
};
struct S_00cc0f40_In
{
    S_00cc0f40_Tbl* table;
};
void __cdecl hkpWorldOperationUtil_mergeIslands(int a, S_00cc0f40_Body* b, S_00cc0f40_Body* c);
S_00cc0f40_Coll* __cdecl hkAgentMachine_processTransformedShapes(S_00cc0f40_Coll* c, void* o1, void* o2, int n, char* flag);
void __cdecl GetNodePairValue(S_00cc0f40_Coll* a, S_00cc0f40_Coll* b, S_00cc0f40_In* in, int* o1, int* o2);
void __cdecl hkAgentNnMachine_CreateAgent(S_00cc0f40_Body* z, S_00cc0f40_Coll* a, S_00cc0f40_Coll* b, S_00cc0f40_Coll* c,
                          S_00cc0f40_Coll* d, S_00cc0f40_Flag flag, int v, S_00cc0f40_In* in, int r);
// Resolves the bodies behind two collision objects, swaps them if needed, calls the table's v3 handler and passes the result to FUN_00cfe8a0.
// @fnv 0x00cc0f40
// src: HAVOK_LIB 0x00cc0f40
void __cdecl hkpWorldAgentUtil_addAgent(S_00cc0f40_Coll* pCollA, S_00cc0f40_Coll* pCollB, S_00cc0f40_In* in)
{
    S_00cc0f40_Body* a = (S_00cc0f40_Body*)((char*)pCollA + pCollA->off);
    S_00cc0f40_Body* b = (S_00cc0f40_Body*)((char*)pCollB + pCollB->off);
    if (a->kind != 5 && b->kind != 5 && a->prop != b->prop)
        hkpWorldOperationUtil_mergeIslands((int)a->unk08, a, b);
    S_00cc0f40_Prop* pPropA = a->prop;
    S_00cc0f40_Prop* pPropB = b->prop;
    S_00cc0f40_Prop* z = pPropA->w20 == 0xffff ? (pPropB->w20 == 0xffff ? pPropA : pPropB) : pPropA;
    S_00cc0f40_Flag flag;
    flag.v = 0;
    S_00cc0f40_Coll* s1 = pCollA;
    S_00cc0f40_Coll* s2 = pCollB;
    __declspec(align(16)) unsigned int bufA[0x2b4 / 4];
    __declspec(align(16)) unsigned int bufB[0x2b4 / 4];
    unsigned int outA[16];
    unsigned int outB[16];
    if (pCollA->type->kind == 0xf)
        s1 = hkAgentMachine_processTransformedShapes(pCollA, outA, bufA, 4, &flag.v);
    if (pCollB->type->kind == 0xf)
        s2 = hkAgentMachine_processTransformedShapes(pCollB, outB, bufB, 4, &flag.v);
    int swap, o;
    GetNodePairValue(s1, s2, in, &o, &swap);
    if (swap)
    {
        S_00cc0f40_Coll* pTemp = pCollA;
        pCollA = pCollB;
        pCollB = pTemp;
        pTemp = s1;
        s1 = s2;
        s2 = pTemp;
    }
    int r = in->table->fn[a->b8c * 8 + b->b8c]->v3(pCollA, pCollB, in);
    hkAgentNnMachine_CreateAgent((S_00cc0f40_Body*)((char*)z + 0x58), pCollA, s1, pCollB, s2, flag, o, in, r);
}

struct Island
{
    char pad[0x5c];
    int* arr;
    int count;
};

// Returns the island with the smaller count if val falls within 0x200 of an entry in its array, otherwise the island with the larger count.
// @fnv 0x00cc0e20
Island* __cdecl PickIslandByValue(unsigned int val, Island* apIslandA, Island* apIslandB)
{
    bool less = apIslandA->count <= apIslandB->count;
    Island* p = less ? apIslandA : apIslandB;
    int n = p->count;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int v = p->arr[i];
        if (v <= val && val < v + 0x200)
        {
            found = true;
            break;
        }
    }
    return ((found ? true : false) ^ (less ? true : false)) ? apIslandB : apIslandA;
}

struct SelectorTarget
{
    unsigned char m_00;
};

// @fnv 0x00cc0e90
// src: HAVOK_LIB 0x00cc0e90
static unsigned int getAgentData(SelectorTarget* p)
{
    if (p->m_00 == 4)
    {
        return (unsigned int)p + 0x30;
    }
    return (unsigned int)p + 0x20;
}

unsigned int probe_caller(SelectorTarget* p)
{
    return getAgentData(p);
}

unsigned int probe_sink;

int main()
{
    SelectorTarget a;
    a.m_00 = 4;
    probe_sink = probe_caller(&a);
    return 0;
}
