#include "../../../../../include/hkErrStream.h"
#include "../../../../../include/hkError.h"

// src/havok/animation/ragdoll/utils/hkaragdollutils_gs_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /Gy (unit src/havok/animation/ragdoll/utils/hkaragdollutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C"
{
    int __cdecl FUN_00cea030(void*, void*);
    int __cdecl FUN_00ce9db0(void*, void*);
    int __cdecl FUN_00ce9e90(void*);
}

// @fnv 0x00cea7c0
int __cdecl FUN_00cea7c0(void* p1, void* p2, void* p3)
{
    if (FUN_00cea030(p1, p2))
        return 1;
    if (FUN_00ce9db0(p2, p3))
        return 1;
    if (FUN_00ce9e90(p2))
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
void __cdecl FUN_00ce9fa0(Container* c, int value, Counter* counter);
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
SpawnedGlobal* __cdecl FUN_00c85750() throw();
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

struct InnerShape
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getType();
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
struct ShapeOwner
{
    int unk00;
    int unk04;
    int unk08;
    InnerShape* inner;
};
extern char str_010cbd34[];
extern char str_010cbd50[];

// @fnv 0x00ce9c40
static __declspec(noinline) void* FUN_00ce9c40(ShapeOwner* owner)
{
    InnerShape* shape = owner->inner;
    switch (shape->getType())
    {
    case 0:
        return &shape->unk20;
    case 1:
        return &shape->unk50;
    case 2:
        return &shape->unk50;
    case 6:
        return &shape->unk50;
    case 7:
        return &shape->unk50;
    case 8:
        return &shape->unk20;
    default: {
        char buf[0x200];
        hkErrStream os(buf, sizeof(buf));
        os << str_010cbd50;
        hkError::s_instance->message(1, 0xabbabf3b, buf, str_010cbd34, 0xb4);
    }
        return 0;
    }
}
volatile int g_in9c40;
volatile int g_out9c40;
void CallTarget_ce9c40()
{
    g_out9c40 = (int)FUN_00ce9c40((ShapeOwner*)g_in9c40);
}
