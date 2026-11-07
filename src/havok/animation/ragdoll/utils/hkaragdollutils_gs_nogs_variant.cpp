
// src/havok/animation/ragdoll/utils/hkaragdollutils_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/animation/ragdoll/utils/hkaragdollutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>

#include "../../../../../include/hkErrStream.h"
#include "../../../../../include/hkError.h"

extern "C"
{
    int __cdecl hkaRagdollUtils_reorderForRagdoll(void*, void*);
    int __cdecl HkaragdollutilsFpfast_ProcessEntries_00ce9db0(void*, void*);
    int __cdecl alignConstraintSpacesToChildren(void*);
}

// @fnv 0x00cea7c0
// src: HAVOK_LIB 0x00cea7c0
int __cdecl hkaRagdollUtils_reorderAndAlignForRagdoll(void* p1, void* p2, void* p3)
{
    if (hkaRagdollUtils_reorderForRagdoll(p1, p2))
        return 1;
    if (HkaragdollutilsFpfast_ProcessEntries_00ce9db0(p2, p3))
        return 1;
    if (alignConstraintSpacesToChildren(p2))
        return 1;
    return 0;
}

struct Item
{
    int unk00[11];
    int unk2c;
};
struct Container
{
    int unk00[2];
    Item** items;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct Counter
{
    int unk00[12];
    int unk30;
};
extern "C" void __cdecl AssignNodeFlags(int, int, int);
void __cdecl hkaRagdollUtils_setCollisionLayer(Container* c, int value, Counter* counter);
struct Inner
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getSomething();
};
struct Obj
{
    char pad0[0xc];
    Inner* inner;
};
static bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw();
void caller(Obj* obj);
struct SpawnedAllocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct SpawnedGlobal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};
SpawnedGlobal* __cdecl hkMemoryRouter_getInstance() throw();
struct SpawnedObject
{
    int unk00;
    unsigned short m_size04;
    int Init(void* a, void* b, int c, void* d);
};
struct SourceRecord
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
    int m_i2c;
};
int __cdecl SpawnObjectFromRecord(SourceRecord* src);

struct Constraint390
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned int GetType();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
};
struct Owner390
{
    unsigned int unk00, unk04, unk08;
    Constraint390* data;
};
// @fnv 0x00ce9cf0
// src: HAVOK_LIB 0x00ce9cf0
static __declspec(noinline) void* _accessConstraintPivotB(Owner390* owner)
{
    Constraint390* data = owner->data;
    switch (data->GetType())
    {
    case 0:
        return &data->unk30;
    case 1:
        return &data->unk90;
    case 2:
        return &data->unk90;
    case 6:
        return &data->unk90;
    case 7:
        return &data->unk90;
    case 8:
        return &data->unk20;
    case 3:
    case 4:
    case 5:
    default: {
        char message[512];
        // Preserve the explicit stream lifetime without adding exception cleanup.
        union
        {
            void* alignment;
            char bytes[sizeof(hkErrStream)];
        } streamStorage;
        ::new (streamStorage.bytes) hkErrStream(message, sizeof(message));
        hkErrStream& stream = *reinterpret_cast<hkErrStream*>(streamStorage.bytes);
        stream << "Unsupported type of constraint in rag doll.";
        hkError::s_instance->message(1, 0xabbabf3b, message, ".\\Utils\\hkaRagdollUtils.cpp", 230);
        stream.hkErrStream::~hkErrStream();
        return 0;
    }
    }
}
void* ConstraintData390(Owner390* owner)
{
    return _accessConstraintPivotB(owner);
}

#include <xmmintrin.h>
// local form of Vec4: 0x00ce9e90 needs aligned integer POD copies; the shared hkVector4 SIMD copy yields 230 instead of 258 bytes.
__declspec(align(16)) struct RagdollVectorWords
{
    int x;
    int y;
    int z;
    int w;
};

struct Target
{
    void hkVector4_setTransformedInversePos(void* where, RagdollVectorWords* v);
};

struct Body : public Obj
{
    int unk10;
    char* shape;
    char* owner;
};

struct List
{
    Body** items;
    int count;
};

static __declspec(noinline) bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return true;
    if (reportError)
    {
        hkError::s_instance->message(1, 0, 0, 0, 0);
    }
    return false;
}

// src: HAVOK_LIB 0x00ce9c40
static __declspec(noinline) RagdollVectorWords* _accessConstraintPivotA(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return (RagdollVectorWords*)((char*)inner + 0x20);
    return 0;
}

// src: HAVOK_LIB 0x00ce9cf0
static __declspec(noinline) Target* _accessConstraintPivotB(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return (Target*)((char*)inner + 0x30);
    return 0;
}

// @fnv 0x00ce9e90
// src: XBOX_PDB 0x00ce9e90
extern "C" int __cdecl alignConstraintSpacesToChildren(void* p)
{
    List* list = (List*)p;
    int count = list->count;
    for (int i = 0; i < count; i++)
    {
        Body* b = list->items[i];
        if (IsSupportedRagdollConstraint(b, true))
        {
            char* shape = b->shape;
            char* owner = b->owner;
            RagdollVectorWords v = *(RagdollVectorWords*)(shape + 0x120);
            RagdollVectorWords* vel = _accessConstraintPivotA(b);
            *(__m128*)vel = _mm_setzero_ps();
            Target* target = _accessConstraintPivotB(b);
            target->hkVector4_setTransformedInversePos(owner + 0xf0, &v);
        }
        if (b->inner->getSomething() == 8)
        {
            int buf[0x80];
            hkErrStream stream(buf, 0x200);
            stream << "Unusual : Aligning constraint spaces of a stiff spring.";
            hkError::s_instance->message(1, 0xabba876d, (const char*)buf, ".\\Utils\\hkaRagdollUtils.cpp", 0x134);
        }
    }
    return 0;
}
