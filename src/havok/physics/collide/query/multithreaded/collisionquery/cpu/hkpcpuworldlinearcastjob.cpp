
// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00df71c0_Value
{
    int unk00;
    float value;
};
struct FUN_00df71c0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00df71c0_Value* unk10;
    float GetValue_00df71c0();
};
// @fnv 0x00df71c0
// src: GUESS 0x00df71c0 (confidence: medium)
float FUN_00df71c0_Class::GetValue_00df71c0()
{
    return unk10->value;
}

// record whose +0x20 pointer FUN_00df72c0 loads and forwards to CastAgainstCollidable on this-8; identity unknown
struct CastRecord20
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    volatile CastRecord20* value;
};
struct TargetBase
{
    void CastAgainstCollidable(volatile CastRecord20* value);
};
struct FUN_00df72c0_class
{
    int unk00;
    int unk04;
    void ForwardToBase(volatile CastRecord20* value);
};
// @fnv 0x00df72c0
void FUN_00df72c0_class::ForwardToBase(volatile CastRecord20* value)
{
    value = value->value;
    char* p = (char*)this;
    p -= 8;
    ((TargetBase*)p)->CastAgainstCollidable(value);
}

struct Param
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Param* next0c;
};
struct This
{
    int CastAgainstCollidable(Param*);
    int hkCpuWorldLinearCastCollector_addLeaf(Param*);
};
// @fnv 0x00df72e0
// src: HAVOK_LIB 0x00df72e0
int This::hkCpuWorldLinearCastCollector_addLeaf(Param* pParam)
{
    Param* pNext = pParam;
    pNext = pNext->next0c;
    return ((This*)((char*)this - 0xc))->CastAgainstCollidable(pNext);
}

namespace fnv_00df7300 {
struct Param;
struct This
{
    float CastAgainstCollidable(Param*);
    bool* SetResultTrue(bool*, Param*);
};
// @fnv 0x00df7300
bool* This::SetResultTrue(bool* pbResult, Param* pParam)
{
    ((This*)((char*)this - 4))->CastAgainstCollidable(pParam);
    *pbResult = true;
    return pbResult;
}
}  // namespace fnv_00df7300

struct DF7230Bool
{
    char m_cBooleanValue;

    DF7230Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DF7230Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};

struct DF7230Collidable
{
    const DF7230Shape* m_pCollisionShape;
};

struct DF7230CdPointCollector
{
    int unk00;
    float m_fEarlyOutDistance;
};

struct DF7230LinearCastInput;

typedef void(__cdecl* DF7230LinearCastFunc)(const DF7230Collidable& bodyA, const DF7230Collidable& bodyB,
                                            const DF7230LinearCastInput& input, DF7230CdPointCollector& collector,
                                            DF7230CdPointCollector* startCollector);

struct DF7230AgentFuncs
{
    void* unk00;
    DF7230LinearCastFunc m_pLinearCastFunc;
    void* unk08;
    void* unk0C;
    void* unk10;
};

struct DF7230Dispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agent2TypeMap[64][32];
    int unk9A0;
    int unk9A4;
    DF7230AgentFuncs m_agent2Funcs[1];

    DF7230LinearCastFunc getLinearCastFunc(int typeA, int typeB) const
    {
        return m_agent2Funcs[m_agent2TypeMap[typeA][typeB]].m_pLinearCastFunc;
    }
};

struct DF7230LinearCastInput
{
    const DF7230Dispatcher* m_pCollisionDispatcher;
};

struct DF7230CollidableCollidableFilter
{
    virtual void unk00();
    virtual DF7230Bool IsCollisionEnabled(const DF7230Collidable& a, const DF7230Collidable& b) const;
};

struct DF7230Filter
{
    int unk00;
    int unk04;
    DF7230CollidableCollidableFilter m_collidableFilter;
};

struct DF7230CastCollector
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const DF7230Filter* m_iFilter;
    DF7230CdPointCollector* m_pPointCollector;
    const DF7230Collidable* m_pCollidableA;
    int m_shapeTypeA;
    DF7230LinearCastInput m_pRayCastInput;

    float CastAgainstCollidable(const DF7230Collidable* collidableB);
};

// @fnv 0x00df7230
float DF7230CastCollector::CastAgainstCollidable(const DF7230Collidable* collidableB)
{
    const DF7230Shape* shapeB = collidableB->m_pCollisionShape;
    if (shapeB && (m_pCollidableA != collidableB))
    {
        if (m_iFilter->m_collidableFilter.IsCollisionEnabled(*m_pCollidableA, *collidableB))
        {
            int typeB = shapeB->m_type;
            DF7230LinearCastFunc pLinearCastFunc =
                m_pRayCastInput.m_pCollisionDispatcher->getLinearCastFunc(m_shapeTypeA, typeB);
            pLinearCastFunc(*m_pCollidableA, *collidableB, m_pRayCastInput, *m_pPointCollector, 0);
        }
    }
    return m_pPointCollector->m_fEarlyOutDistance;
}

// FUN_00df7320 - 0x00df7320, 19 bytes
//
//   mov edx, dword ptr [esp + 4]      ; the first stack argument
//   movsx eax, byte ptr [edx + 5]     ; signed byte at +5 of that object
//   add eax, edx                      ; object + offset
//   push eax
//   call 0xdf7230                     ; same class, this (ECX) forwarded
//   ret 8
//
// CastAgainstCollidable is a __thiscall member of the same class with one 4-byte
// stack argument; it ends with `ret 4`, so it pops the pushed pointer
// itself and our own epilogue only has to drop the two incoming arguments.
//
// The function is a virtual of hkCpuWorldLinearCastCollector (its vftable
// entry sits at 0x010db9e8); `this` is never touched here, it is simply
// passed on to CastAgainstCollidable.

// The object the collector is asked about.  The signed byte at +0x05 is the
// offset of the sub-object that has to be evaluated.
struct FUN_00df7320_Shape
{
    int unk00;          // +0x00
    signed char unk04;  // +0x04
    signed char unk05;  // +0x05
};

struct FUN_00df7320_Collector
{
    float CastAgainstCollidable(FUN_00df7320_Shape* value);
    float ProcessAndReturnValue_00df7320(FUN_00df7320_Shape* shape, FUN_00df7320_Shape* other);
};

// @fnv 0x00df7320
// src: GUESS 0x00df7320 (confidence: low)
float FUN_00df7320_Collector::ProcessAndReturnValue_00df7320(FUN_00df7320_Shape* shape, FUN_00df7320_Shape* other)
{
    FUN_00df7320_Shape* target = (FUN_00df7320_Shape*)((char*)shape + shape->unk05);
    return CastAgainstCollidable(target);
}

struct Base1
{
    virtual void FUN_00df7190();
};
struct Base2
{
    virtual void FUN_00df7190();
};
struct Derived : Base1, Base2
{
    Derived();
    virtual void FUN_00df7190();
};
// @fnv 0x00df7190
Derived::Derived()
{}

namespace fnv_00df71a0 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00df71a0();
    int unk04;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00df71a0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00df71a0
// src: GUESS 0x00df71a0 (confidence: low)
    virtual void AdjustThisAndForward_00df71a0();
};

Derived::Derived()
{}
}  // namespace fnv_00df71a0

struct DF71B0Primary
{
    virtual void vfunc00();
    virtual void FUN_00df71b0();

    int unk04;
    int unk08;
};

struct DF71B0Secondary
{
    virtual void FUN_00df71b0();
};

struct DF71B0Object : DF71B0Primary, DF71B0Secondary
{
    DF71B0Object();

// @fnv 0x00df71b0
    virtual void FUN_00df71b0();
};

DF71B0Object::DF71B0Object()
{}

struct S_00df71d0_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, unsigned int n);
};

struct S_00df71d0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00df71d0_Heap* unk10;
    S_00df71d0_Heap& heap()
    {
        return *unk10;
    }
};

S_00df71d0_Router* hkMemoryRouter_getInstance();

struct S_00df71d0_B0
{
    virtual ~S_00df71d0_B0()
    {}
};
struct S_00df71d0_B1
{
    virtual void f1()
    {}
    ~S_00df71d0_B1()
    {}
};
struct S_00df71d0_B2
{
    virtual void f2()
    {}
    ~S_00df71d0_B2()
    {}
};
struct S_00df71d0_B3
{
    virtual void f3()
    {}
    ~S_00df71d0_B3()
    {}
};

struct FUN_00df71d0 : S_00df71d0_B0, S_00df71d0_B1, S_00df71d0_B2, S_00df71d0_B3
{
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
    FUN_00df71d0();
// @fnv 0x00df71d0
    virtual ~FUN_00df71d0()
    {}
    static void operator delete(void* p, unsigned int n)
    {
        hkMemoryRouter_getInstance()->heap().ReleaseBlock(p, n);
    }
};

FUN_00df71d0::FUN_00df71d0()
{}
