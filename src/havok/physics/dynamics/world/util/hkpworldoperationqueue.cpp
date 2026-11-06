#include "../../../../../../include/hkArray.h"

// src/havok/physics/dynamics/world/util/hkpworldoperationqueue.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldoperationqueue.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/BSAudio.h"

void EnterTlsGuard();
void FUN_00c904e0();

struct S_00cf7540_Alloc
{
};

BSAudio* FUN_00c85750();
void ResizeAudioStream(S_00cf7540_Alloc* alloc, void* arr, int elemSize);

struct S_00cf7540_Ref
{
    int unk0;
    short m_sReferenceCount;
    void FUN_00c90510();
};

struct S_00cf7540_Entry
{
    S_00cf7540_Ref* m_kPointA;
    S_00cf7540_Ref* m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};

template <class T>
static __forceinline T& S_00cf7540_Array_AllocatePair(hkArrayBase<T>& self)
{
        BSAudio* router = FUN_00c85750();
        if (self.m_iElementCount == (self.m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<S_00cf7540_Alloc*>(router->pListener), (&self), sizeof(T));
        return self.m_data[self.m_iElementCount++];
    }

struct S_00cf7540_World
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
};

struct S_00cf7540
{
    int unk0;
    int unk4;
    int unk8;
    S_00cf7540_World* unkC;
    int unk10;
    int unk14;
    int unk18;
    hkArrayBase<S_00cf7540_Entry> m_entries;

    void AddEntry(S_00cf7540_Ref* a, S_00cf7540_Ref* b, int c, int d);
};

// Appends an entry holding the two refs and two ints to m_entries, increments unkC->unk90, and calls the refs' FUN_00c90510 between EnterTlsGuard and FUN_00c904e0.
// @fnv 0x00cf7540
void S_00cf7540::AddEntry(S_00cf7540_Ref* pRefA, S_00cf7540_Ref* pRefB, int c, int d)
{
    EnterTlsGuard();
    unkC->unk90++;
    S_00cf7540_Entry& e = S_00cf7540_Array_AllocatePair(m_entries);
    e.m_kPointA = pRefA;
    e.m_kPointB = pRefB;
    e.m_iThirdValue = c;
    e.m_iFourthElementInteger = d;
    pRefA->FUN_00c90510();
    pRefB->FUN_00c90510();
    FUN_00c904e0();
}

struct Node
{
    virtual void v0(int flag);
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
    void* m_48;
    int m_4c;
};

extern void __fastcall FUN_00c90510(void* self);
extern void __fastcall FUN_00c905b0(void* self);

struct FUN_00c93580_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Node* m_20;
    void* m_24;
    Node** m_28;
    int m_2c;
    int unk30;
    Node** m_34;
    int m_38;
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
    int unk_a0;
    int unk_a4;
    int unk_a8;
    int unk_ac;
    int unk_b0;
    int unk_b4;
    int unk_b8;
    int unk_bc;
    int unk_c0;
    int unk_c4;
    unsigned char m_c8;
    int unk_cc;
    int unk_d0;
    int unk_d4;
    int unk_d8;
    int unk_dc;
    int unk_e0;
    int unk_e4;
    int unk_e8;
    int unk_ec;
    int unk_f0;
    int unk_f4;
    int unk_f8;
    int unk_fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    Node* m_110;
    int m_114;

    void FUN_00c93580();
    void __thiscall FUN_00c92c70(int v);
    void __thiscall ProcessTarget(char* buf, int v);
    void __thiscall FUN_00c914d0(void* p, int flag);
};

// @fnv 0x00c93580
void FUN_00c93580_Class::FUN_00c93580()
{
    while (this->m_114 > 0)
        this->FUN_00c92c70(*(int*)this->m_110);

    while (this->m_2c > 0)
    {
        Node* node = this->m_28[0];
        if (node->m_4c == 0)
            break;
        char buf;
        this->ProcessTarget(&buf, *(int*)node->m_48);
    }

    while (this->m_38 > 0)
    {
        char buf;
        this->ProcessTarget(&buf, *(int*)this->m_34[0]->m_48);
    }

    FUN_00c90510(this->m_24);

    {
        char buf;
        this->ProcessTarget(&buf, (int)this->m_24);
    }

    Node* node = this->m_20;
    while (node->m_4c > 0)
    {
        char buf;
        this->ProcessTarget(&buf, *(int*)node->m_48);
        node = this->m_20;
    }

    this->FUN_00c914d0(this->m_24, 1);
    FUN_00c905b0(this->m_24);

    if (this->m_c8 == 0)
    {
        void* e = this->m_28[this->m_2c - 1];
        extern void __cdecl ClearSlotReference(FUN_00c93580_Class * self, void* e);
        ClearSlotReference(this, e);
        void* e2 = this->m_28[this->m_2c - 1];
        if (e2)
            ((Node*)e2)->v0(1);
        this->m_2c--;
    }

    extern void __cdecl NotifyWorldDeleted(FUN_00c93580_Class * self);
    NotifyWorldDeleted(this);
}



struct FUN_00cf75c0
{
    hkArrayBase<int> m_kPointA;
    int unk0c;
    hkArrayBase<int> m_kPointB;
    hkArrayBase<int> m_iThirdValue;
    FUN_00cf75c0(int v);
};

// Constructor that stores the given int into unk0c and default-initialises the three array members.
// @fnv 0x00cf75c0
FUN_00cf75c0::FUN_00cf75c0(int aiValue)
{
    unk0c = aiValue;
}

extern "C" void _ReadWriteBarrier();
typedef unsigned char Byte;
typedef unsigned short UShort;
typedef unsigned int UInt;
// Exe 0x00cf7c10 FUN_00cf7c10: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x;
        float y;
        float z;
        float w;
    } scalar;
} __m128, LocalM128;
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
// The unit keeps its own __m128 (float lanes only); hkVector4.h uses it.
#include "../../../../../../include/hkVector4.h"

struct Heap
{
    virtual void v0();
    virtual void v4();
    virtual void ReleaseBlock(void*, int);
    virtual void vC();
    virtual void ReturnMemory(void*, int);
};
struct World;
struct Body;
struct EntityArray
{
    Body** data;
    int size;
    int capacity;
};
struct Motion
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
    virtual void m34();
    virtual void m38();
    virtual void m3c();
    virtual void m40();
    virtual void m44();
    virtual void m48();
    virtual void impulse(const hkVector4&);
    virtual void pointImpulse(const hkVector4&, const hkVector4&);
    virtual void angularImpulse(const hkVector4&);
    int state4;
    Byte type;
    Byte typePad9;
    UShort typePadA;
};
struct Body
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void callback(Body*);
    virtual void GetEntities(EntityArray&);
    int unk04;
    World* world;
    void* owner;
    int unk10;
    Body* bodyA;
    Body* bodyB;
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
    void* island;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    Motion motion;
    void FUN_00ca8420(int, int, int);
    void FUN_00d07ec0(void*);
    void FUN_00ca8860(const hkVector4&, const hkVector4&);
    void OnTrigger(const hkVector4&);
    void FUN_00561800(const hkVector4&);
    void FUN_00c9c1d0();
    void FUN_00c9c240();
    void FUN_00d87c20(Body*, int);
};
struct WorldDispatcher
{
    virtual void d00();
    virtual void d04();
    virtual void d08();
    virtual void d0c();
    virtual void d10();
    virtual void d14();
    virtual void d18();
    virtual void d1c();
    virtual void d20();
    virtual void d24();
    virtual void d28();
    virtual void d2c();
    virtual void update(Body**, int, World*, int);
};
struct World
{
    int unk00;
    int unk04;
    WorldDispatcher* dispatcher;
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
    int criticalOperations;
    void FUN_00c914d0(Body*, int);
    void ProcessTarget(char*, Body*);
    void FUN_00c94bd0(Body**, int, int);
    void RemoveEntities(Body**, int);
    void FUN_00c97d30(Body*);
    void FUN_00c97e80(char*, Body*);
    void FUN_00c97370(Body*);
    void DispatchOrQueue(Body*);
    void FUN_00c936a0(Body*);
    void FUN_00c92c70(Body*);
    void FUN_00c954e0(Body**, int);
    void FUN_00c95800(Body**, int);
    void FUN_00c946e0(void*, int, int);
    void ProcessPair(Body*, Body*);
    void UpdatePhantom(void*, int);
    void FUN_00c96ff0(int, int);
    void FUN_00c93c30(void*);
};
// queued island merge (priority, entity A, entity B, 2 more dwords): sorted by priority, then FUN_00cb5570(world, a, b) merges
struct IslandMergeRequest
{
    int priority;
    Body* a;
    Body* b;
    int c;
    int d;
};
struct Op
{
    Byte type;
    Byte flag1;
    Byte flag2;
    Byte flag3;
    union
    {
        Body* object;
        Body** objects;
        hkVector4* vector;
    };
    union
    {
        Body* other;
        hkVector4* point;
        int arg;
        float x;
        struct
        {
            UShort count;
            Byte mode;
            Byte unused;
        } batch;
        struct
        {
            Byte a;
            Byte b;
            Byte c;
            Byte d;
        } flags;
    };
    union
    {
        int arg2;
        float y;
        Byte enabled;
    };
    float z;
};
struct OpArray
{
    Op* data;
    int size;
    int capacity;
    void SwapThreeInts(void*);
};
struct Pending
{
    OpArray operations;
    World* world;
    IslandMergeRequest* pairs;
    int pairCount;
    int pairCapacity;
    void EnterTlsGuard();
    void FUN_00cf7c10();
};
extern "C" void __cdecl LessThanPairPriority(IslandMergeRequest*, IslandMergeRequest*);
extern "C" void __cdecl FUN_00cf8510(IslandMergeRequest*, int, int, void(__cdecl*)(IslandMergeRequest*, IslandMergeRequest*));
extern "C" void __cdecl FUN_00cb5570(World*, Body*, Body*);
extern "C" void __cdecl AddCollisionShape(World*, Body*);
extern "C" void __cdecl FUN_00c90740(Body**, int, int);
extern "C" void __cdecl FUN_00ca8700(Body*);

static __forceinline void release(Body* p)
{
    FUN_00c905b0(p);
}
static __forceinline Heap* heap()
{
    BSAudio* router = FUN_00c85750();
    return reinterpret_cast<Heap*>(router->pListener);
}
static __forceinline void freeBlock(void* p, int n)
{
    heap()->ReleaseBlock(p, n);
}
static __forceinline void freeBatch(Body** a, int n)
{
    heap()->ReleaseBlock(a, n * 4);
}
static __forceinline void freeEntities(EntityArray& a)
{
    Heap* h = heap();
    a.size = 0;
    if ((a.capacity & 0x80000000) == 0)
        h->ReturnMemory(a.data, (a.capacity & 0x3fffffff) * 4);
    a.data = 0;
    a.capacity = 0x80000000;
}
// Drains pending physics pairs and queued operations, dispatching each to the world and releasing the associated bodies and memory.
// @fnv 0x00cf7c10
void Pending::FUN_00cf7c10()
{
    EnterTlsGuard();
    OpArray todo;
    todo.data = 0;
    todo.size = 0;
    todo.capacity = 0x80000000;
    todo.SwapThreeInts(this);
    ++world->criticalOperations;
    if (pairCount)
    {
        if (pairCount > 1)
            FUN_00cf8510(pairs, 0, pairCount - 1, LessThanPairPriority);
        while (pairCount)
        {
            IslandMergeRequest p = pairs[pairCount - 1];
            pairCount = static_cast<const volatile int&>(pairCount) - 1;
            if (p.a->world == world && p.b->world == world && p.a->motion.type != 5 && p.b->motion.type != 5 &&
                p.a->island != p.b->island)
            {
                _ReadWriteBarrier();
                FUN_00cb5570(p.a->world, p.a, p.b);
            }
            release(p.a);
            release(p.b);
        }
    }
    int opCount = todo.size;
    Op* data = todo.data;
    for (int i = 0; i < opCount; ++i)
    {
        Op* p = &data[i];
        switch (p->type)
        {
        case 1:
            if (!p->object->world)
                world->FUN_00c914d0(p->object, p->arg);
            release(p->object);
            break;
        case 2: {
            if (p->object->world == world)
            {
                char result;
                world->ProcessTarget(&result, p->object);
            }
            release(p->object);
            break;
        }
        case 4:
            p->object->FUN_00ca8420(p->flags.a, p->flags.b, p->flags.c);
            release(p->object);
            break;
        case 5:
            p->object->callback(p->other);
            release(p->object);
            release(p->other);
            break;
        case 6:
            world->FUN_00c94bd0(p->objects, p->batch.count, p->batch.mode);
            FUN_00c90740(p->objects, p->batch.count, 4);
            freeBatch(p->objects, p->batch.count);
            break;
        case 7:
            world->RemoveEntities(p->objects, p->batch.count);
            FUN_00c90740(p->objects, p->batch.count, 4);
            freeBatch(p->objects, p->batch.count);
            break;
        case 8:
            if (!p->object->world && p->object->bodyA->world == world && p->object->bodyB->world == world)
                world->FUN_00c97d30(p->object);
            release(p->object);
            break;
        case 9: {
            if (p->object->world)
            {
                char result;
                world->FUN_00c97e80(&result, p->object);
            }
            release(p->object);
            break;
        }
        case 10:
            if (!p->object->world)
            {
                EntityArray a;
                a.data = 0;
                a.size = 0;
                a.capacity = 0x80000000;
                p->object->GetEntities(a);
                int i = 0;
                for (; i < a.size; ++i)
                    if (a.data[i]->world != world)
                        goto skipAction;
                world->FUN_00c97370(p->object);
            skipAction:;
                freeEntities(a);
            }
            release(p->object);
            break;
        case 11:
            if (p->object->owner)
                world->DispatchOrQueue(p->object);
            release(p->object);
            break;
        case 13:
            if (!p->object->world)
                world->FUN_00c936a0(p->object);
            release(p->object);
            break;
        case 14:
            if (p->object->world == world)
                world->FUN_00c92c70(p->object);
            release(p->object);
            break;
        case 15:
            world->FUN_00c954e0(p->objects, p->batch.count);
            FUN_00c90740(p->objects, p->batch.count, 4);
            freeBatch(p->objects, p->batch.count);
            break;
        case 16:
            world->FUN_00c95800(p->objects, p->batch.count);
            FUN_00c90740(p->objects, p->batch.count, 4);
            freeBatch(p->objects, p->batch.count);
            break;
        case 3:
            if (p->object->world == world)
                AddCollisionShape(world, p->object);
            release(p->object);
            break;
        case 17:
            if (p->object->world == world)
                p->object->FUN_00d07ec0(p->point);
            release(p->object);
            if (p->point)
                freeBlock(p->point, 32);
            break;
        case 18:
            if (p->object->world == world)
                world->FUN_00c946e0(p->object, p->flags.a, p->flags.b);
            release(p->object);
            break;
        case 19:
            if (p->object->world == world && p->other->world == world)
                world->ProcessPair(p->object, p->other);
            release(p->object);
            release(p->other);
            break;
        case 20:
            if (p->object->world == world)
                world->UpdatePhantom(p->object, p->flags.a);
            release(p->object);
            break;
        case 21:
            world->FUN_00c96ff0(p->flag1, p->flag2);
            break;
        case 22:
            FUN_00ca8700(p->object);
            release(p->object);
            break;
        case 24:
            p->object->FUN_00ca8860(p->point[0], p->point[1]);
            freeBlock(p->point, 32);
            release(p->object);
            break;
        case 25: {
            hkVector4 v;
            v.quad = _mm_setr_ps(p->x, p->y, p->z, 0.0f);
            p->object->OnTrigger(v);
            release(p->object);
            break;
        }
        case 26: {
            hkVector4 v;
            v.quad = _mm_setr_ps(p->x, p->y, p->z, 0.0f);
            p->object->FUN_00561800(v);
            release(p->object);
            break;
        }
        case 27: {
            hkVector4 v;
            v.quad = _mm_setr_ps(p->x, p->y, p->z, 0.0f);
            Body* b = p->object;
            b->FUN_00c9c1d0();
            b->motion.impulse(v);
            release(p->object);
            break;
        }
        case 28: {
            const hkVector4& a = p->point[1];
            const hkVector4& b = p->point[0];
            Body* body = p->object;
            body->FUN_00c9c1d0();
            body->motion.pointImpulse(a, b);
            freeBlock(p->point, 32);
            release(p->object);
            break;
        }
        case 29: {
            hkVector4 v;
            v.quad = _mm_setr_ps(p->x, p->y, p->z, 0.0f);
            Body* b = p->object;
            b->FUN_00c9c1d0();
            b->motion.angularImpulse(v);
            release(p->object);
            break;
        }
        case 32:
            world->FUN_00c93c30(p->vector);
            freeBlock(p->vector, 32);
            break;
        case 33:
            p->object->FUN_00c9c1d0();
            release(p->object);
            break;
        case 34:
            if (p->object->world == world)
                p->object->FUN_00c9c240();
            release(p->object);
            break;
        case 35:
            p->object->FUN_00d87c20(p->other, p->enabled);
            release(p->object);
            release(p->other);
            break;
        case 23: {
            Body** end = p->objects + p->batch.count - 1;
            int count = p->batch.count;
            for (Body** scan = end; scan >= p->objects; --scan)
            {
                Body* b = *scan;
                if (b->world != world)
                {
                    *scan = *end;
                    *end = b;
                    --end;
                    --count;
                }
            }
            if (count)
                world->dispatcher->update(p->objects, count, world, p->batch.mode);
            Body** batchEnd = p->objects + p->batch.count;
            for (Body** scan = p->objects; scan < batchEnd;)
            {
                Body* b = *scan++;
                release(b);
            }
            freeBatch(p->objects, p->batch.count);
            break;
        }
        case 36:
            p->object->callback(p->other);
            release(p->object);
            break;
        }
        if (operations.size)
            FUN_00cf7c10();
    }
    todo.SwapThreeInts(this);
    operations.size = 0;
    --world->criticalOperations;
    ::FUN_00c904e0();
    Heap* h = heap();
    if ((todo.capacity & 0x80000000) == 0)
        h->ReturnMemory(todo.data, (todo.capacity & 0x3fffffff) * sizeof(Op));
}

namespace fnv_00cf75f0 {
struct Allocator
{
    virtual void vtable_00() = 0;
    virtual void vtable_04() = 0;
    virtual void vtable_08() = 0;
    virtual void vtable_0c() = 0;
    virtual void Release(void* data, unsigned int size) = 0;
};

BSAudio* __cdecl FUN_00c85750();

struct Elem20
{
    unsigned long w0;
    unsigned long w1;
    unsigned long w2;
    unsigned long w3;
    unsigned long w4;
};

struct Elem16
{
    unsigned long w0;
    unsigned long w1;
    unsigned long w2;
    unsigned long w3;
};

template <typename T> struct Buffer
{
    T* data;
    unsigned int size;
    unsigned int flags;

    void clear();
};

template <typename T> void Buffer<T>::clear()
{
    const unsigned int stride = sizeof(T);

    BSAudio* audio = FUN_00c85750();
    Allocator* alloc = reinterpret_cast<Allocator*>(audio->pListener);

    const unsigned int f = flags;
    size = 0;

    if (!(f & 0x80000000u))
    {
        alloc->Release(data, (f & 0x3fffffffu) * stride);
    }

    data = 0;
    flags = 0x80000000u;
}

struct Owner
{
    Buffer<Elem20> first;
    unsigned long gap_0c;
    Buffer<Elem20> second;
    Buffer<Elem16> third;

    void FUN_00cf75f0();
};

// Clears the third, second, and first buffer members of the Owner object in that order.
// @fnv 0x00cf75f0
void Owner::FUN_00cf75f0()
{
    third.clear();
    second.clear();
    first.clear();
}
}  // namespace fnv_00cf75f0

namespace fnv_00cf7690 {
struct Alloc
{
    virtual void V00();
    virtual void* V04(int sz);
};
struct Obj
{
    void FUN_00c90510();
};
struct FUN_00d1df70
{
    void removeReference();
};
void EnterTlsGuard();
void FUN_00c904e0();
BSAudio* FUN_00c85750();
void ResizeAudioStream(void* alloc, void* vec, int elemsz);
void FUN_00cb1260(void* dst, void* src, int n);

struct Elem
{
    union
    {
        unsigned char tag;
        int tagd;
        unsigned char b[4];
    };
    int* f04;
    int f08;
    int f0c;
    int f10;
};
struct Obj32
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
};
struct VecBase
{
    Elem* data;
    int cnt;
    int cap;
};
// Havok 7.1 hkpWorldOperationQueue: m_pending (hkArray of 0x14-byte BiggestOperation), m_world, m_islandMerges; 0x00cf7690 = queueOperation.
struct hkpWorldOperationQueue
{
    Elem* data;
    int cnt;
    int cap;
    char* owner;
    VecBase sub;
    void queueOperation(Elem* arg);
};

// Appends a copy of arg to the vector and, by tag, calls FUN_00c90510 on referenced objects, copying pointer arrays or a 32-byte block for some tags.
// @fnv 0x00cf7690
void hkpWorldOperationQueue::queueOperation(Elem* arg)
{
    EnterTlsGuard();
    BSAudio* bsa = FUN_00c85750();
    if (cnt == (cap & 0x3fffffff))
    {
        ResizeAudioStream(reinterpret_cast<Alloc*>(bsa->pListener), this, 0x14);
    }
    Elem* pNew = data + cnt;
    if (pNew)
    {
        pNew->tag = 0;
    }
    Elem* dst = data + cnt;
    cnt++;
    *(int*)(owner + 0x8c) += 1;
    dst->tagd = arg->tagd;
    dst->f04 = arg->f04;
    dst->f08 = arg->f08;
    dst->f0c = arg->f0c;
    dst->f10 = arg->f10;
    switch (dst->tag)
    {
    case 1:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 2:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 3:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 4:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 5:
        ((Obj*)dst->f04)->FUN_00c90510();
        ((Obj*)dst->f08)->FUN_00c90510();
        FUN_00c904e0();
        return;
    case 6: {
        int f08v = dst->f08;
        int count = (unsigned short)f08v;
        BSAudio* b = FUN_00c85750();
        void* mem = reinterpret_cast<Alloc*>(b->pListener)->V04(count * 4);
        dst->f04 = (int*)mem;
        FUN_00cb1260(mem, arg->f04, (unsigned short)arg->f08 * 4);
        int* p = dst->f04;
        int* end = p + (unsigned short)dst->f08;
        while (p < end)
        {
            ((Obj*)*p++)->FUN_00c90510();
        }
    }
        FUN_00c904e0();
        return;
    case 7: {
        int f08v = dst->f08;
        int count = (unsigned short)f08v;
        BSAudio* b = FUN_00c85750();
        void* mem = reinterpret_cast<Alloc*>(b->pListener)->V04(count * 4);
        dst->f04 = (int*)mem;
        FUN_00cb1260(mem, arg->f04, (unsigned short)arg->f08 * 4);
        int* p = dst->f04;
        int* end = p + (unsigned short)dst->f08;
        while (p < end)
        {
            ((Obj*)*p++)->FUN_00c90510();
        }
    }
        FUN_00c904e0();
        return;
    case 8:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 9:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 10:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 11:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 12:
        ((Obj*)dst->f04)->FUN_00c90510();
        ((Obj*)dst->f08)->FUN_00c90510();
        {
            VecBase* s = &sub;
            BSAudio* b = FUN_00c85750();
            if (s->cnt == (s->cap & 0x3fffffff))
            {
                ResizeAudioStream(reinterpret_cast<Alloc*>(b->pListener), s, 0x14);
            }
            Elem* d2 = s->data + s->cnt;
            if (d2)
            {
                *d2 = *dst;
            }
            s->cnt++;
            cnt--;
        }
        FUN_00c904e0();
        return;
    case 13:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 14:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 15: {
        int f08v = dst->f08;
        int count = (unsigned short)f08v;
        BSAudio* b = FUN_00c85750();
        void* mem = reinterpret_cast<Alloc*>(b->pListener)->V04(count * 4);
        dst->f04 = (int*)mem;
        FUN_00cb1260(mem, arg->f04, (unsigned short)arg->f08 * 4);
        int* p = dst->f04;
        int* end = p + (unsigned short)dst->f08;
        while (p < end)
        {
            ((Obj*)*p++)->FUN_00c90510();
        }
    }
        FUN_00c904e0();
        return;
    case 16: {
        int f08v = dst->f08;
        int count = (unsigned short)f08v;
        BSAudio* b = FUN_00c85750();
        void* mem = reinterpret_cast<Alloc*>(b->pListener)->V04(count * 4);
        dst->f04 = (int*)mem;
        FUN_00cb1260(mem, arg->f04, (unsigned short)arg->f08 * 4);
        int* p = dst->f04;
        int* end = p + (unsigned short)dst->f08;
        while (p < end)
        {
            ((Obj*)*p++)->FUN_00c90510();
        }
    }
        FUN_00c904e0();
        return;
    case 17: {
        ((Obj*)dst->f04)->FUN_00c90510();
        BSAudio* b = FUN_00c85750();
        void* mem = reinterpret_cast<Alloc*>(b->pListener)->V04(0x20);
        int nf08;
        if (mem)
        {
            Obj32* pObjCopy = (Obj32*)mem;
            Obj32* pObjSrc = (Obj32*)arg->f08;
            pObjCopy->d0 = pObjSrc->d0;
            pObjCopy->d1 = pObjSrc->d1;
            pObjCopy->d2 = pObjSrc->d2;
            pObjCopy->d3 = pObjSrc->d3;
            pObjCopy->d4 = pObjSrc->d4;
            pObjCopy->d5 = pObjSrc->d5;
            pObjCopy->d6 = pObjSrc->d6;
            pObjCopy->d7 = pObjSrc->d7;
            nf08 = (int)mem;
        }
        else
        {
            nf08 = 0;
        }
        dst->f08 = nf08;
        FUN_00c904e0();
        return;
    }
    case 18:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 19:
        ((Obj*)dst->f04)->FUN_00c90510();
        ((Obj*)dst->f08)->FUN_00c90510();
        FUN_00c904e0();
        return;
    case 20:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 22:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 23: {
        int f08v = dst->f08;
        int count = (unsigned short)f08v;
        BSAudio* b = FUN_00c85750();
        void* mem = reinterpret_cast<Alloc*>(b->pListener)->V04(count * 4);
        dst->f04 = (int*)mem;
        FUN_00cb1260(mem, arg->f04, (unsigned short)arg->f08 * 4);
        int* p = dst->f04;
        int* end = p + (unsigned short)dst->f08;
        while (p < end)
        {
            ((Obj*)*p++)->FUN_00c90510();
        }
    }
        FUN_00c904e0();
        return;
    case 24:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 25:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 26:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 27:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 28:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 29:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 30:
        ((Obj*)dst->f04)->FUN_00c90510();
        cnt--;
        *(int*)(owner + 0x8c) -= 1;
        FUN_00c904e0();
        return;
    case 31:
        ((FUN_00d1df70*)dst->f04)->removeReference();
        cnt--;
        *(int*)(owner + 0x8c) -= 1;
        FUN_00c904e0();
        return;
    case 33:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 34:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    case 35:
        ((Obj*)dst->f04)->FUN_00c90510();
        ((Obj*)dst->f08)->FUN_00c90510();
        FUN_00c904e0();
        return;
    case 36:
        ((Obj*)dst->f04)->FUN_00c90510();
        break;
    }
    FUN_00c904e0();
}
}  // namespace fnv_00cf7690

namespace fnv_00cf7ae0 {
struct S_00cf7ae0_Heap
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void ReleaseBlock(void* p, int n);
};
BSAudio* __cdecl FUN_00c85750();
inline BSAudio& GetMonitorStream()
{
    return *FUN_00c85750();
}
inline S_00cf7ae0_Heap& __fastcall GetStreamHeap(BSAudio& audio)
{
    return *reinterpret_cast<S_00cf7ae0_Heap*>(audio.pListener);
}
void __cdecl FUN_00c908c0(S_00cf7ae0_Heap*, void* arr, int n, int elemSize);
void __cdecl EnterTlsGuard();
void __cdecl FUN_00c904e0();

struct S_00cf7ae0_Obj
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vfnc(void* data, bool* flag);
    void ReleaseReference();
};
struct S_00cf7ae0_Entry
{
    S_00cf7ae0_Obj* data;
    S_00cf7ae0_Obj* listener;
    int unk8;
    int unkc;
};
bool __cdecl FUN_00cf74b0(const S_00cf7ae0_Entry&, const S_00cf7ae0_Entry&);
void __cdecl FUN_00cf83c0(S_00cf7ae0_Entry* data, int lo, int hi,
                          bool(__cdecl* cmp)(const S_00cf7ae0_Entry&, const S_00cf7ae0_Entry&));

struct S_00cf7ae0_Array
{
    S_00cf7ae0_Entry* m_data;
    int m_iElementCount;
    int m_cap;
    void SwapThreeInts(S_00cf7ae0_Array* other);
    __forceinline void reserve(S_00cf7ae0_Heap& a, int n)
    {
        int cap = m_cap & 0x3fffffff;
        if (cap < n)
        {
            int c2 = cap * 2;
            FUN_00c908c0(&a, this, (n < c2) ? c2 : n, 16);
        }
    }
    __forceinline void ClearAndRelease(S_00cf7ae0_Heap& a)
    {
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            a.ReleaseBlock(m_data, (m_cap & 0x3fffffff) * 16);
        m_data = 0;
        m_cap = 0x80000000;
    }
};
struct S_00cf7ae0_Owner
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
};
struct S_00cf7ae0
{
    int unk0, unk4, unk8;
    S_00cf7ae0_Owner* owner;
    int unk10, unk14, unk18;
    S_00cf7ae0_Array pending;
    void FUN_00cf7ae0();
};

// Drains pending by moving it to a local array, sorting, calling each listener's vfnc on its data, then FUN_00c903b0 on both objects and clearing the local copy.
// @fnv 0x00cf7ae0
void S_00cf7ae0::FUN_00cf7ae0()
{
    while (pending.m_iElementCount != 0)
    {
        S_00cf7ae0_Array localArray;
        localArray.m_data = 0;
        localArray.m_iElementCount = 0;
        localArray.m_cap = 0x80000000;
        localArray.SwapThreeInts(&pending);
        owner->unk90 = 0;
        pending.reserve(GetStreamHeap(GetMonitorStream()), 16);
        int n = localArray.m_iElementCount;
        if (n > 1)
        {
            int last = n - 1;
            FUN_00cf83c0(localArray.m_data, 0, last, FUN_00cf74b0);
        }
        if (n > 0)
        {
            S_00cf7ae0_Entry* p = localArray.m_data;
            int i = n;
            bool flag;
            do
            {
                flag = false;
                S_00cf7ae0_Obj* d = p->data;
                S_00cf7ae0_Obj* l = p->listener;
                l->vfnc(d, &flag);
                p++;
            } while (--i != 0);
        }
        EnterTlsGuard();
        if (n > 0)
        {
            S_00cf7ae0_Entry* p = localArray.m_data;
            do
            {
                S_00cf7ae0_Obj* a = p->data;
                S_00cf7ae0_Obj* b = p->listener;
                a->ReleaseReference();
                b->ReleaseReference();
                p++;
            } while (--n != 0);
        }
        FUN_00c904e0();
        localArray.ClearAndRelease(GetStreamHeap(GetMonitorStream()));
    }
}
}  // namespace fnv_00cf7ae0

#include <string.h>
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
extern "C" int _mm_movemask_ps(LocalM128);
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);

extern __declspec(thread) int g_threadMode;
extern unsigned char DAT_01267b44;
extern float DAT_01017d00;
extern LocalM128 DAT_01267e30;
extern LocalM128 DAT_01017d10;

struct S_Motion
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
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    LocalM128 m_1b0;
    LocalM128 m_1c0;
    void FUN_00c9c1d0();
};
struct S_Body
{
    int unk00;
    int unk04;
    S_Motion* m_8;
    int unk0c;
    unsigned int m_10;
};
struct S_Owned
{
    int unk00;
    int unk04;
    int unk08;
    S_Body* m_iThirdValue;
};
struct S_Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    char unk11;
    short unk12;
    int unk14;
    unsigned char m_type;
    S_Owned* getOwner()
    {
        return (S_Owned*)((char*)this + m_iOwnerOffset);
    }
};
struct S_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short m_20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int m_48;
    int m_4c;
};
struct S_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_Collidable m_kCollidable;
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
    S_Shape* m_cc;
};
struct S_Mgr : FUN_00c93580_Class
{
    void FUN_00c94bd0(S_Item** items, unsigned int count, int flag);
    void FUN_00c92a80(int a, int b);
};
void __cdecl PropagateStateToChildren(S_Mgr* mgr, S_Shape* shape);

struct S_ModeGuard
{
    int m_saved;
    S_ModeGuard()
    {
        m_saved = g_threadMode;
        g_threadMode = 0x10;
    }
    ~S_ModeGuard()
    {
        g_threadMode = m_saved;
    }
};

static inline S_Body* GetBody(S_Collidable* col)
{
    if (col->m_type == 1)
    {
        S_Owned* owner = col->getOwner();
        if (owner)
            return owner->m_iThirdValue;
    }
    return 0;
}

static inline const LocalM128& GetLinVel(S_Body* b)
{
    if (b && b->m_8)
        return b->m_8->m_1b0;
    return DAT_01267e30;
}

static inline const LocalM128& GetAngVel(S_Body* b)
{
    if (b && b->m_8)
        return b->m_8->m_1c0;
    return DAT_01267e30;
}

static inline bool AllNear3(const LocalM128& a, const LocalM128& b, const LocalM128& eps)
{
    LocalM128 d = _mm_and_ps(_mm_sub_ps(a, b), DAT_01017d10);
    return (_mm_movemask_ps(_mm_cmple_ps(d, eps)) & 7) == 7;
}

struct S_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual S_Mgr* GetMgr();
    void FUN_00c674d0(S_Item** items, unsigned int count);
};
// For each item clears flag 0x10 on its body (or calls ProcessTarget), updates the first valid shape once, calls FUN_00c905b0, then zeroes the items array.
// @fnv 0x00c674d0
void S_Owner::FUN_00c674d0(S_Item** items, unsigned int count)
{
    S_ModeGuard guard;
    S_Mgr* mgr = GetMgr();
    if (mgr)
    {
        mgr->FUN_00c94bd0(items, count, 0);
        bool bShapeUpdated = false;
        for (unsigned int i = 0; i < count; i++)
        {
            union
            {
                LocalM128 v;
                char bytes[16];
            } eps;
            eps.v = _mm_set_ps1(0.001f);
            S_Item* it = items[i];
            S_Body* body = GetBody(&it->m_kCollidable);
            if (body)
                body->m_10 &= ~0x10;
            else
            {
                char tmp;
                mgr->ProcessTarget(&tmp, (int)it);
            }
            if (!bShapeUpdated)
            {
                S_Shape* s = items[i]->m_cc;
                if (s && s->m_20 != 0xffff)
                {
                    if (DAT_01267b44)
                        mgr->FUN_00c92a80(s->m_48, s->m_4c);
                    PropagateStateToChildren(mgr, s);
                    bShapeUpdated = true;
                }
            }
            if (!AllNear3(GetLinVel(body), DAT_01267e30, eps.v) || !AllNear3(GetAngVel(body), DAT_01267e30, eps.v))
            {
                if (body && body->m_8)
                    body->m_8->FUN_00c9c1d0();
            }
            FUN_00c905b0(items[i]);
        }
        memset(items, 0, count * sizeof(S_Item*));
    }
}
