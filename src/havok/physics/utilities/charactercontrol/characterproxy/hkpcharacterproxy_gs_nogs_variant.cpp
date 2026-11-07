#include "../../../../../../include/ContactArray289.h"
#include "../../../../../../include/hkpAllCdPointCollector.h"
#include "../../../../../../include/hkpCdPointCollector.h"


// src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00cad480_Class
{
    void __thiscall hkpCharacterProxy_fireContactAdded(void* arg);
};
struct S_00cad440;
struct S_00cad440_Listener
{
    virtual void unk0();
    virtual void Notify(S_00cad440* src, void* a, void* b);
};
struct S_00cad440
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
    S_00cad440_Listener** unk80;
    int unk84;
    void hkpCharacterProxy_fireConstraintsProcessed(void* a, void* b);
};
struct CAD4C0Owner;
struct CAD4C0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void notify(CAD4C0Owner* owner, void* data);
};
struct CAD4C0Owner
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
    CAD4C0Listener** m_kListeners;
    int m_numListeners;

    void hkpCharacterProxy_fireContactRemoved(void* data);
};
struct FUN_00cad6f0_class
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
    void** items;
    volatile int itemCount;
    void __thiscall RemoveItem(void* item);
};
struct FUN_00cade20_Class
{
    void __thiscall hkpCharacterProxy_integrateImplementation(int, int, int, int, int, int);
};
struct FUN_00cafbd0_Class
{
    void __thiscall hkpCharacterProxy_integrateWithCollectors(int first, int second, int third, int fourth);
};
struct FNVAllocator
{
    virtual void Release();
    virtual void* Allocate(unsigned int bytes);
};
struct FNVMemoryManager
{
    FNVAllocator* GetAllocator()
    {
        return *reinterpret_cast<FNVAllocator**>(reinterpret_cast<char*>(this) + 0x10);
    }
};
FNVMemoryManager* __cdecl hkMemoryRouter_getInstance();
struct FNVArray
{
    int* values;
    unsigned short size;
    unsigned short flags;
    FNVArray() : values(0), size(0), flags(0x8000)
    {}
};
struct FNVBuffers
{
    FNVArray spare;
    FNVArray elements;
    static void* operator new(unsigned int bytes)
    {
        return hkMemoryRouter_getInstance()->GetAllocator()->Allocate(bytes);
    }
};
void __cdecl hkSmallArrayUtil__reserveMore(FNVArray*, unsigned int);
struct FNVOwner
{
    FNVBuffers*& Buffers()
    {
        return *reinterpret_cast<FNVBuffers**>(reinterpret_cast<char*>(this) + 0x214);
    }
    void hkpEntity_addEntityListener(int value);
};
extern __declspec(thread) int g_tlsMemContext;
struct S_00cac150_Scope
{
    int m_oldContext;
    S_00cac150_Scope(int ctx)
    {
        m_oldContext = g_tlsMemContext;
        g_tlsMemContext = ctx;
    }
    ~S_00cac150_Scope()
    {
        g_tlsMemContext = m_oldContext;
    }
};
struct S_00cac150_Item1
{
    void removeEntityListener_00c9c670(void* arg);
};
struct S_00cac150_Item2
{
    void RemoveListener(void* arg);
};
struct S_00cac150
{
    int unk00;
    int unk04;
    int m_arg1;
    int m_arg2;
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
    S_00cac150_Item1** m_items1;
    int m_count1;
    int unk94;
    S_00cac150_Item2** m_items2;
    int m_count2;

    void ClearItems();
};
struct CpuScalar
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int value;
};
struct CpuObject
{
    unsigned int unk00;
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
    CpuScalar* value;
    unsigned int hkpCharacterProxy_getPosition();
};
extern float DAT_0101e2bc;
struct FUN_00cacf10_cls
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
    int m_74;
    int m_78;

    float hkpCharacterProxy_surfaceDistance(void* a, void* b);
    int hkpCharacterProxy_findSurface(void* arg);
};
struct ArgminState
{
    volatile float best;
    volatile int idx;
};
// Stand-in model for the object whose method RemoveTarget is being rebuilt.
// Layout is taken from the original disassembly, not from the pack's unit file.
struct BhkShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    unsigned char unk18;
};
// 0x70 bytes; the pointer to the shape sits at +0x48.
struct BhkElem
{
    __int64 q00;
    __int64 q08;
    __int64 q10;
    __int64 q18;
    __int64 q20;
    __int64 q28;
    __int64 q30;
    __int64 q38;
    __int64 q40;
    BhkShape* p;
    __int64 q50;
    __int64 q58;
    __int64 q60;
    __int64 q68;
};
struct BhkTarget
{
    void removeEntityListener_00c9c670(void* v);
};
struct BhkProxy
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
    volatile BhkElem* m_elements;
    int m_uiItemCount;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    BhkTarget** m_ids;
    volatile int m_idcount;

    void RemoveTarget(BhkTarget* arg1);
};
struct FUN_00cad900_arg
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int code, const char* name, int a, int b, int c);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned char flag10;
};
extern "C" int __cdecl hkStatisticsCollector_getAllocatedSize(int ptr, int size);
extern "C" char str_010c8444[];
extern "C" char str_010c8450[];
extern "C" char str_010c8460[];
struct FUN_00cad900_cls
{
    unsigned int unk00;
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
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;

    void hkpCharacterProxy_calcContentStatistics(FUN_00cad900_arg* a1, int a2);
};
extern char str_0102f13c[];
extern char DAT_0104e3d0[];
extern char DAT_010c84a4[];
extern char DAT_010c8488[];
extern char DAT_010c8470[];
struct FUN_00cad500_Class
{
    void __thiscall hkpCharacterProxy_updateFromCinfo(void* arg);
};
struct FUN_00cada70_cls
{
    void* m_vtbl;
    unsigned char unk04[2];
    unsigned short m_06;
    void* m_08;
    void* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_30;
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
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7c;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8c;
    unsigned int m_90;
    unsigned int m_94;
    unsigned int m_98;
    unsigned int m_9c;
    unsigned int m_a0;

    FUN_00cada70_cls* Construct(void* a1);
};
struct Query289
{
    __declspec(nothrow) void hkpCharacterProxy_integrateImplementation(void*, void*, hkpCdPointCollector*, hkpCdPointCollector*, unsigned,
                                          unsigned) throw();
    void CollectAllContactPoints(void*, void*);
};

#include <xmmintrin.h>
#include <new>
extern float DAT_0104da48;
struct Allocator197
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    __declspec(nothrow) virtual void Free(void* memory, int bytes);
};
__declspec(nothrow) inline hkpCdPointCollector::hkpCdPointCollector() : m_fEarlyOutDistance(DAT_0104da48)
{}

__declspec(nothrow) __forceinline hkpCdPointCollector::~hkpCdPointCollector()
{}

__declspec(nothrow) inline ContactArray289::ContactArray289()
{
    data = local;
    capacity = 0x80000008;
    count = 0;
}

__declspec(nothrow) __forceinline ContactArray289::~ContactArray289()
{
    FNVMemoryManager* manager = hkMemoryRouter_getInstance();
    unsigned int flags = capacity;
    Allocator197* heap = reinterpret_cast<Allocator197*>(manager->GetAllocator());
    count = 0;
    if (!(flags & 0x80000000u))
        heap->Free(data, (flags & 0x3fffffff) * sizeof(RootContact289));
    data = 0;
    capacity = 0x80000000;
}

__declspec(nothrow) inline hkpAllCdPointCollector::hkpAllCdPointCollector()
{}

__declspec(nothrow) __forceinline hkpAllCdPointCollector::~hkpAllCdPointCollector()
{}

struct Bool197
{
    bool value;
    Bool197(bool v) : value(v)
    {}
};
struct Context197
{
    virtual void v00();
    virtual void v04();
    virtual void Begin();
};
struct Scalar197
{
    float value;
};
struct Query197
{
    Scalar197 x, y, z, otherX, otherY, otherZ;
    __m128 axisX, axisY, axisZ;
    Query197(const Query197& q)
        : x(q.x), y(q.y), z(q.z), otherX(q.otherX), otherY(q.otherY), otherZ(q.otherZ), axisX(q.axisX), axisY(q.axisY),
          axisZ(q.axisZ)
    {}
};
struct QueryOwner197
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
    Query197* query;
};
struct Provider197
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void Process(Context197*, Query197*);
    int unk04;
    QueryOwner197* owner;
};
struct Controller197
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    __declspec(nothrow) virtual void Collect(Context197*, hkpAllCdPointCollector*, Bool197);
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
    Provider197* provider;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    float margin58, margin5c;
    void AllocateStorage_00cae7f0(Context197* context);
};
// @fnv 0x00cae7f0
// src: GUESS 0x00cae7f0 (confidence: low)
void Controller197::AllocateStorage_00cae7f0(Context197* context)
{
    context->Begin();
    Query197 query = *provider->owner->query;
    query.z.value = (margin5c + margin58) + query.z.value;
    provider->Process(context, &query);
    // Preserve the original explicit lifetime without adding an exception cleanup scope.
    __declspec(align(16)) unsigned char storage[sizeof(hkpAllCdPointCollector)];
    hkpAllCdPointCollector* collector = ::new (storage) hkpAllCdPointCollector;
    Collect(context, collector, false);
    collector->hkpAllCdPointCollector::~hkpAllCdPointCollector();
}
