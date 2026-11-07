#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/ContactArray289.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkpAllCdPointCollector.h"
#include "../../../../../../include/hkpCdPointCollector.h"

// src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00cad480_Class {
    void __thiscall hkpCharacterProxy_fireContactAdded(void* arg);
};
struct S_00cad440;
struct S_00cad440_Listener {
    virtual void unk0();
    virtual void Notify(S_00cad440* src, void* a, void* b);
};
struct S_00cad440 {
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
struct CAD4C0Listener {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void notify(CAD4C0Owner* owner, void* data);
};
struct CAD4C0Owner {
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
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
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
struct FNVAllocator {
    virtual void Release();
    virtual void* Allocate(unsigned int bytes);
};
struct FNVMemoryManager {
    FNVAllocator* GetAllocator() {
        return *reinterpret_cast<FNVAllocator**>(reinterpret_cast<char*>(this) + 0x10);
    }
};
FNVMemoryManager* __cdecl hkMemoryRouter_getInstance();
struct FNVArray {
    int* values;
    unsigned short size;
    unsigned short flags;
    FNVArray() : values(0), size(0), flags(0x8000) {}
};
struct FNVBuffers {
    FNVArray spare;
    FNVArray elements;
    static void* operator new(unsigned int bytes) {
        return hkMemoryRouter_getInstance()->GetAllocator()->Allocate(bytes);
    }
};
void __cdecl hkSmallArrayUtil__reserveMore(FNVArray*, unsigned int);
struct FNVOwner {
    FNVBuffers*& Buffers() {
        return *reinterpret_cast<FNVBuffers**>(reinterpret_cast<char*>(this) + 0x214);
    }
    void hkpEntity_addEntityListener(int value);
};
extern __declspec(thread) int g_tlsMemContext;
struct S_00cac150_Scope {
    int m_oldContext;
    S_00cac150_Scope(int ctx) {
        m_oldContext = g_tlsMemContext;
        g_tlsMemContext = ctx;
    }
    ~S_00cac150_Scope() {
        g_tlsMemContext = m_oldContext;
    }
};
struct S_00cac150_Item1 {
    void removeEntityListener_00c9c670(void* arg);
};
struct S_00cac150_Item2 {
    void RemoveListener(void* arg);
};
struct S_00cac150 {
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
struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int value;
};
struct CpuObject {
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
struct FUN_00cacf10_cls {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70;
    int m_74;
    int m_78;

    float hkpCharacterProxy_surfaceDistance(void* a, void* b);
    int hkpCharacterProxy_findSurface(void* arg);
};
struct ArgminState {
    volatile float best;
    volatile int idx;
};
// Stand-in model for the object whose method RemoveTarget is being rebuilt.
// Layout is taken from the original disassembly, not from the pack's unit file.
struct BhkShape {
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
struct BhkElem {
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
struct BhkTarget {
    void removeEntityListener_00c9c670(void* v);
};
struct BhkProxy {
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
struct FUN_00cad900_arg {
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
struct FUN_00cad900_cls {
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
extern float DAT_0104da48;
struct Query289 {
 __declspec(nothrow) void hkpCharacterProxy_integrateImplementation(void*,void*,hkpCdPointCollector*,hkpCdPointCollector*,unsigned,unsigned) throw();
 void CollectAllContactPoints(void*,void*);
};
// Exe 0x00cade20 FUN_00cade20: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128 a);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
extern float DAT_0104da4c;
struct S00cacaa0_Vec {
    LocalM128 m_vComponents;
};
struct S00cacaa0_Base {
    unsigned int f00, f04, f08, f0c, f10, f14;
    S00cacaa0_Vec v20;
    S00cacaa0_Vec v30;
    S00cacaa0_Vec v40;
};
struct S00cacaa0_Src : S00cacaa0_Base {
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5c; unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6c;
    unsigned int f70;
};
struct S00cacaa0_Input : S00cacaa0_Base {
    S00cacaa0_Vec v50;
    float f60;
    float f64;
    unsigned int f68;
    S00cacaa0_Input() { f04 = 0; f60 = DAT_0104da4c; }
};
struct S00cacaa0_Shape {
    unsigned int unk00, unk04, unk08;
    unsigned int m_type;
};
struct S00cacaa0_Coll {
    S00cacaa0_Shape* m_pCollisionShape;
};
typedef void (__cdecl *S00cacaa0_Fn)(S00cacaa0_Coll* a, S00cacaa0_Coll* b, S00cacaa0_Input* in, void* c, void* d);
struct S00cacaa0_Entry {
    S00cacaa0_Fn m_fn;
    unsigned int unk04, unk08, unk0c, unk10;
};
struct S00cacaa0_Disp {
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4; unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc; unsigned int unk0d0; unsigned int unk0d4; unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec; unsigned int unk0f0; unsigned int unk0f4; unsigned int unk0f8; unsigned int unk0fc; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10c; unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c; unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c; unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15c; unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16c; unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17c; unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18c; unsigned int unk190; unsigned int unk194; unsigned int unk198; unsigned int unk19c;
    unsigned char m_table[64][32];
};
struct S00cacaa0_World {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0c; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c; unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2c; unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3c; unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4c; unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5c; unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6c; unsigned int unk70; unsigned int unk74;
    S00cacaa0_Src* m_src;
    unsigned int unk7c;
    S00cacaa0_Disp* m_disp;
    void hkpWorld_linearCast(S00cacaa0_Coll* a, float* b, void* c, void* d);
};
struct S00cacaa0_Agent {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(S00cacaa0_Coll* a, S00cacaa0_Coll* b, S00cacaa0_Input* in, void* c, void* d);
};
struct S00cacaa0_Pair {
    S00cacaa0_Agent* m_pCollisionAgent;
    S00cacaa0_Coll* m_coll;
};
struct S00cacaa0_Arr {
    void* m_data;
    int m_iElementCount;
};
struct S00cacaa0_Phantom {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int v14();
    unsigned int unk04;
    S00cacaa0_World* m_pOwningWorld;
    unsigned int unk0c;
    S00cacaa0_Coll m_coll;
    unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4; unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc; unsigned int unk0d0; unsigned int unk0d4; unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec; unsigned int unk0f0; unsigned int unk0f4; unsigned int unk0f8; unsigned int unk0fc; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10c; unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c; unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c; unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15c;
    S00cacaa0_Arr m_aiIndexedValues;
};
struct S00cacaa0_cls {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0c; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c;
    S00cacaa0_Vec m_v20;
    S00cacaa0_Phantom* m_pPhantom;
    void hkpCharacterProxy_linearCast(bool flag, float* a2, void* a3, void* a4);
};
struct HkEntity289 {
    void removeEntityListener_00c9c670(void* listener) throw();
};
struct HkPhantom289 {
    void RemoveListener(void* listener) throw();
};
struct HkWorldLock289 {
    int unk00;
    int unk04;
};
struct HkWorld289 {
    void hkpWorldObject_removeProperty(HkWorldLock289* apOut, unsigned int auiFlags) throw();
    void FUN_00c905b0() throw();
};
template <class T> struct HkArray289 {
    T* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;

    void clear() { m_iElementCount = 0; }
    ~HkArray289() throw() {
        hkMemoryAllocator& alloc = hkMemoryRouter::get().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct HkBaseObject289 {
    virtual ~HkBaseObject289() {}
};
struct HkReferencedObject289 : HkBaseObject289 {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct HkEntityListener289 {
    virtual ~HkEntityListener289() {}
};
struct HkPhantomListener289 {
    virtual ~HkPhantomListener289() {}
};
struct FUN_00cadb00 : HkReferencedObject289, HkEntityListener289, HkPhantomListener289 {
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    HkWorld289* m_pOwningWorld;
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
    HkArray289<BhkElem> m_elements;
    HkArray289<int> m_ids;
    HkArray289<HkEntity289*> m_kActorEntries;
    HkArray289<HkPhantom289*> m_kPhantoms;

    virtual ~FUN_00cadb00();
};
extern float DAT_0104da48;
struct S00cafbf0_Obj {
    void hkpCharacterProxy_integrateImplementation(int, int, hkpAllCdPointCollector*, hkpAllCdPointCollector*, int, int) throw();
    void hkpCharacterProxy_integrateMultithreaded(int a, int b, int c, int d) throw();
};
// fires added/removed notifications and keeps entity/phantom listeners attached to the touched objects.
struct S_00caf4d0_Heap {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct S_00caf4d0_Stack {
    char* m_next;
    void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    void deallocateStack(void* p) throw() { m_next = (char*)p; }
};
struct S_00caf4d0_Router {
    S_00caf4d0_Stack m_aiEntries;
    int unk04;
    int unk08;
    int unk0C;
    S_00caf4d0_Heap* m_pStreamAllocator;
    S_00caf4d0_Stack& stack() throw() { return m_aiEntries; }
    S_00caf4d0_Heap& heap() throw() { return *m_pStreamAllocator; }
};
static __forceinline S_00caf4d0_Router* GetRouter37() throw() { return reinterpret_cast<S_00caf4d0_Router*>(hkMemoryRouter_getInstance()); }
void ResizeAudioStream(S_00caf4d0_Heap& alloc, void* array, int elemSize) throw();
inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }
struct __declspec(align(16)) S_00caf4d0_Vector4 {
    float x, y, z, w;
    S_00caf4d0_Vector4() throw() {}
    S_00caf4d0_Vector4(const S_00caf4d0_Vector4& v) throw()
    {
        reinterpret_cast<LocalM128&>(*this) = reinterpret_cast<const LocalM128&>(v);
    }
};
struct S_00caf4d0_Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset; // 0x10
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;               // 0x18
    void* getOwner() const throw() { return (void*)((char*)this + m_iOwnerOffset); }
};
struct S_00caf4d0_Point {
    S_00caf4d0_Vector4 m_vContactPosition;            // 0x00
    S_00caf4d0_Vector4 m_vSeparatingNormal;    // 0x10 (w = distance)
    int m_pCollidableA;                        // 0x20
    int m_uiShapeKeyA;                          // 0x24
    int m_kContactPointB[8];                      // 0x28
    S_00caf4d0_Collidable* m_pCollidableB;     // 0x48
    int m_uiShapeKeyB;                          // 0x4c
    int m_kContactPointC[8];                      // 0x50

    S_00caf4d0_Point& operator=(const S_00caf4d0_Point& other) throw();
    float getDistance() const throw() { return m_vSeparatingNormal.w; }
};
static __forceinline void memCpy8(void* dst, const void* src, int n) throw()
{
    const unsigned __int64* s = (const unsigned __int64*)src;
    unsigned __int64* d = (unsigned __int64*)dst;
    for (int i = 0; i < n; i++)
        d[i] = s[i];
}
template <class T> __forceinline void constructWithCopy(T* p, const T& t) throw()
{
    new (p) T(t);
}
template <class T> __forceinline void constructWithCopy(T** p, T* const& t) throw()
{
    for (int k = 0; k < 1; k++)
        p[k] = t;
}
template <class T> struct S_00caf4d0_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const throw() { return m_iElementCount; }
    T& operator[](int i) throw() { return m_data[i]; }
    const T& operator[](int i) const throw() { return m_data[i]; }
    void clear() throw() { m_iElementCount = 0; }
    int indexOf(const T& t) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void AddBack(const T& t) throw()
    {
        S_00caf4d0_Router* router = GetRouter37();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->heap(), this, sizeof(T));
        constructWithCopy(m_data + m_iElementCount, t);
        m_iElementCount++;
    }
    void removeAt(int index) throw()
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy8(m_data + index, m_data + m_iElementCount, sizeof(T) / 8);
    }
};
template <class T> struct S_00caf4d0_LocalArray : S_00caf4d0_Array<T> {
    T* m_pStackAllocation;
    __forceinline S_00caf4d0_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)GetRouter37()->stack().allocateStack(capacity * sizeof(T));
        this->m_iElementCount = 0;
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~S_00caf4d0_LocalArray() throw()
    {
        GetRouter37()->stack().deallocateStack(m_pStackAllocation);
        S_00caf4d0_Heap& heap = GetRouter37()->heap();
        if ((this->m_iCapacityState & 0x80000000) == 0)
            heap.ReturnMemory(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
};
struct S_00caf4d0_EntityListener { virtual void elUnk00(); };
struct S_00caf4d0_PhantomListener { virtual void plUnk00(); };
struct S_00caf4d0_TrackerBase { virtual void tbUnk00(); int unk04; };
struct S_00caf4d0_Entity {
    void hkpEntity_addEntityListener(S_00caf4d0_EntityListener* l) throw();
    void removeEntityListener_00c9c670(S_00caf4d0_EntityListener* l) throw();
};
struct S_00caf4d0_Phantom {
    void AddItem(S_00caf4d0_PhantomListener* l) throw();
    void RemoveListener(S_00caf4d0_PhantomListener* l) throw();
};
extern float DAT_0104da48;
extern const float g_011dd8bc_arg1;
static inline S_00caf4d0_Entity* getRigidBody_caf(const S_00caf4d0_Collidable* c) throw()
{
    if (c->m_type == 1)
        return (S_00caf4d0_Entity*)c->getOwner();
    return 0;
}
static inline S_00caf4d0_Phantom* getPhantom_caf(const S_00caf4d0_Collidable* c) throw()
{
    if (c->m_type == 2)
        return (S_00caf4d0_Phantom*)c->getOwner();
    return 0;
}
struct S_00caf4d0_Tracker : S_00caf4d0_TrackerBase, S_00caf4d0_EntityListener, S_00caf4d0_PhantomListener {
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
    float unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    S_00caf4d0_Array<S_00caf4d0_Point> m_kPoints;      // 0x74
    S_00caf4d0_Array<void*> m_kListeners;              // 0x80
    S_00caf4d0_Array<S_00caf4d0_Entity*> m_kActorEntries;  // 0x8c
    S_00caf4d0_Array<S_00caf4d0_Phantom*> m_kPhantoms; // 0x98

    float hkpCharacterProxy_surfaceDistance(const S_00caf4d0_Point* a, const S_00caf4d0_Point* b) throw();
    void hkpCharacterProxy_fireContactRemoved(const S_00caf4d0_Point* p) throw();
    void hkpCharacterProxy_fireContactAdded(const S_00caf4d0_Point* p) throw();
    int hkpCharacterProxy_findSurface(const S_00caf4d0_Point* p) throw();

    void hkpCharacterProxy_updateManifold(const hkpAllCdPointCollector* input, const hkpAllCdPointCollector* extra, bool keepListeners) throw();
};
struct ContactQuery {
    void ahkpCharacterProxy_checkSupportWithCollector(void*, unsigned, hkpAllCdPointCollector*) throw();
    void ahkpCharacterProxy_checkSupport(void*, unsigned);
};
struct CadColl {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_type;
    void* getOwner() const throw() { return (void*)((char*)this + m_iOwnerOffset); }
};
static inline S_00caf4d0_Phantom* getPhantom_cad(const CadColl* c) throw()
{
    if (c->m_type == 2)
        return (S_00caf4d0_Phantom*)c->getOwner();
    return 0;
}
struct CadPoint {
    S_00caf4d0_Vector4 m_vContactPosition;
    S_00caf4d0_Vector4 m_vSeparatingNormal;
    int m_pCollidableA;
    int m_uiShapeKeyA;
    int m_kContactPointB[8];
    CadColl* m_pCollidableB;
    int m_uiShapeKeyB;
    int m_kContactPointC[8];
};
struct CadPhantomListener {
    virtual void plUnk00();
    virtual void hkpPhantomListener_phantomRemovedCallback(struct CadPhantom* p) throw();
};
struct CadPhantom {
    void RemoveListener(CadPhantomListener* l) throw();
};

struct Cad820Cls : S_00caf4d0_TrackerBase, S_00caf4d0_EntityListener, CadPhantomListener {
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
    float unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    S_00caf4d0_Array<CadPoint> m_kPoints;
    S_00caf4d0_Array<void*> m_kListeners;
    S_00caf4d0_Array<S_00caf4d0_Entity*> m_kActorEntries;
    hkArrayBase<CadPhantom*> m_kPhantoms;

    void hkpPhantomListener_phantomRemovedCallback(CadPhantom* phantom) throw();
};
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_setzero_ps(void);
struct S00cafd90_Vec {
    LocalM128 m_vComponents;
};
struct S00cafd90_Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char unk18;
};
struct S00cafd90_Body;
struct S00cafd90_Conv {
    __declspec(noalias) void hkpRigidBody_getPointVelocity(S00cafd90_Body* body, LocalM128* out);
};
struct S00cafd90_Body {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00cafd90_Vec unk10;
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
    S00cafd90_Info* unk48;
};
extern double DAT_0101ffa0;
extern double DAT_01020758;
static __forceinline S00cafd90_Conv* S00cafd90_ConvOf(S00cafd90_Body* b)
{
    S00cafd90_Info* info = b->unk48;
    if (info->unk18 != 1)
        return 0;
    return (S00cafd90_Conv*)((char*)info + info->unk10);
}
static __forceinline S00cafd90_Vec S00cafd90_Pos(S00cafd90_Body* b)
{
    S00cafd90_Vec r;
    r.m_vComponents = _mm_setzero_ps();
    if (S00cafd90_Conv* c = S00cafd90_ConvOf(b))
        c->hkpRigidBody_getPointVelocity(b, &r.m_vComponents);
    return r;
}
static __forceinline float S00cafd90_Dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 prod = _mm_mul_ps(a, b);
    LocalM128 s1 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
    LocalM128 s2 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), s1);
    float r;
    _mm_store_ss(&r, s2);
    return r;
}

#include <string.h>
#include <windows.h>
extern "C" {
void _ReadWriteBarrier();
LocalM128 _mm_set_ss(float);
LocalM128 _mm_set_ps1(float);
LocalM128 _mm_setr_ps(float,float,float,float);
unsigned __int64 __rdtsc();
LocalM128 _mm_load_ps(const float*);
LocalM128 _mm_load_ss(const float*);
void _mm_store_ps(float*,LocalM128);
LocalM128 _mm_add_ps(LocalM128,LocalM128);
LocalM128 _mm_mul_ss(LocalM128,LocalM128);
LocalM128 _mm_sub_ss(LocalM128,LocalM128);
LocalM128 _mm_rsqrt_ss(LocalM128);
LocalM128 _mm_cmpeq_ss(LocalM128,LocalM128);
LocalM128 _mm_cmple_ps(LocalM128,LocalM128);
LocalM128 _mm_and_ps(LocalM128,LocalM128);
LocalM128 _mm_andnot_ps(LocalM128,LocalM128);
LocalM128 _mm_unpacklo_ps(LocalM128,LocalM128);
LocalM128 _mm_movelh_ps(LocalM128,LocalM128);
int _mm_movemask_ps(LocalM128);
}
extern unsigned DAT_0126835c;
extern char str_010c8508[],str_010c8500[],str_010c84f0[],str_010c84dc[],str_010c84d0[],str_010c84c4[],str_010c84b8[],str_01076f38[];
extern LocalM128 DAT_01017d10;
__declspec(nothrow) FNVMemoryManager* __cdecl hkMemoryRouter_getInstance();
template<class T> class PStorage {
    T value;
public:
    __forceinline PStorage() throw(){}
    __forceinline PStorage(T v) throw():value(v){}
    __forceinline T val() const throw(){return value;}
    __forceinline operator T() const throw(){return val();}
    __forceinline void operator=(T v) throw(){value=v;}
};
struct PBool {char value;PBool(bool b) throw():value(b){} operator bool() const throw(){return value!=0;}};
class PScalar {
    LocalM128 q;
public:
    PScalar(const LocalM128& x) throw():q(x){}
    __forceinline operator float() const throw(){float f;_mm_store_ss(&f,q);return f;}
    const LocalM128& quad() const throw(){return q;}
    LocalM128 broadcast() const throw(){return _mm_shuffle_ps(q,q,0);}
};
class PVec {
    LocalM128 q;
public:
    __forceinline PVec() throw(){}
    __forceinline PVec(const PVec& v) throw():q(v.q){}
    __forceinline void operator=(const PVec& v) throw(){q=v.q;}
    __forceinline void operator=(const LocalM128& v) throw(){q=v;}
    const LocalM128& quad() const throw(){return q;}
    __forceinline float& component(int i) throw(){return q.m128_f32[i];}
    __forceinline void set(float x,float y,float z,float w=0.0f) throw(){
        q=_mm_setr_ps(x,y,z,w);
    }
    __forceinline void zero() throw(){q=_mm_setzero_ps();}
    __forceinline void all(float f) throw(){q=_mm_set_ps1(f);}
    __forceinline void add(const PVec& v) throw(){q=_mm_add_ps(q,v.q);}
    __forceinline void sum(const PVec& a,const PVec& b) throw(){q=_mm_add_ps(a.q,b.q);}
    __forceinline void mul(float f,const PVec& v) throw(){q=_mm_mul_ps(_mm_set_ps1(f),v.q);}
    __forceinline PScalar dot(const PVec& v) const throw(){LocalM128 p=_mm_mul_ps(q,v.q);LocalM128 a=_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p);return _mm_add_ss(_mm_shuffle_ps(p,p,0xaa),a);}
    __forceinline PScalar square() const throw(){return dot(*this);}
    __forceinline PScalar inverse() const throw(){
        LocalM128 half=_mm_set_ss(0.5f),three=_mm_set_ss(3.0f),zero=_mm_set_ss(0.0f);
        LocalM128 d=dot(*this).quad();LocalM128 mask=_mm_cmpeq_ss(d,zero);LocalM128 r=_mm_rsqrt_ss(d);
        return _mm_andnot_ps(mask,_mm_mul_ss(_mm_mul_ss(half,r),_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(d,r),r))));
    }
    __forceinline void normalize() throw(){q=_mm_mul_ps(inverse().broadcast(),q);}
    __forceinline int equal(const PVec& other,float epsilon) const throw(){
        LocalM128 d=_mm_sub_ps(q,other.q);d=_mm_and_ps(d,DAT_01017d10);LocalM128 e=_mm_set_ps1(epsilon);
        int mask=_mm_movemask_ps(_mm_cmple_ps(d,e));return (mask&7)==7;
    }
};
struct PContact {
PVec point,normal;void* rootA;unsigned keyA,pathA[8];BhkShape* rootB;unsigned keyB,pathB[8];
__forceinline PContact() throw(){}
__forceinline PContact(const PContact& x) throw(){point=x.point;normal=x.normal;rootA=x.rootA;keyA=x.keyA;memcpy(pathA,x.pathA,sizeof(pathA));rootB=x.rootB;keyB=x.keyB;memcpy(pathB,x.pathB,sizeof(pathB));}
};
struct PPlane {PVec normal,velocity;float friction,upFriction,downFriction,dynamic;int priority;};
struct PInteraction {unsigned char touched,stopped;float time,penalty;int status;};
struct PAllocator {virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void freeMemory(void*,int) throw();template<class T> __forceinline void freeBuffer(void* p,int n) throw(){const int stride=sizeof(T);freeMemory(p,n*stride);}};
struct PStack {PStorage<void*> cursor,start,end;int peak;
    inline void* allocate(int n,const char* what) throw(){void* p=cursor.val();cursor=static_cast<char*>(p)+n;return p;}
    __forceinline void deallocate(void* p) throw(){cursor=p;}
};
struct PRouter {PStack stack;PAllocator* allocator;__forceinline PAllocator& heap() throw(){return *allocator;}__forceinline PStack& local() throw(){return stack;}};
__forceinline PRouter* route() throw(){return reinterpret_cast<PRouter*>(hkMemoryRouter_getInstance());}
void ResizeAudioStream(PAllocator&,void*,int) throw();
void hkArrayUtil__reserve(PAllocator&,void*,int,int) throw();
struct PContainerAllocator {__forceinline PAllocator& get(const void*) const throw(){return route()->heap();}};
struct ClassCopy{};struct ScalarCopy{};
template<class T> struct CopyKind{typedef ClassCopy type;};
template<class T> struct CopyKind<T*>{typedef ScalarCopy type;};
template<class T> __forceinline void copyElements(T* dest,int n,const T& x,ClassCopy) throw(){for(int i=0;i<n;++i)new (dest+i) T(x);}
template<class T> __forceinline void copyElements(T* dest,int n,const T& x,ScalarCopy) throw(){for(int i=0;i<n;++i)dest[i]=x;}

__forceinline void copyByteRange(void* dest,const void* src,int n) throw(){for(int i=0,j=0;i<n;i+=8,++j)static_cast<__int64*>(dest)[j]=static_cast<const __int64*>(src)[j];}
template<class T> struct PArrayBase {
    T* data;int size,capacity;
    __forceinline PArrayBase() throw():data(0),size(0),capacity(0x80000000){}
    __forceinline ~PArrayBase() throw(){}
    __forceinline T* begin() throw(){return data;}
    __forceinline int count() const throw(){return size;}
    __forceinline int room() const throw(){return capacity&0x3fffffff;}
    __forceinline T& operator[](int i) throw(){return data[i];}
    __forceinline void clear() throw(){size=0;}
    __forceinline void clearDeallocate(PAllocator& a) throw(){clear();if(!(capacity&0x80000000))a.freeBuffer<T>(data,room());data=0;capacity=0x80000000;}
    __forceinline void resizeUnchecked(int n) throw(){size=n;}
    __forceinline void reserveWith(PAllocator& a,int n) throw(){const int c=room();if(c<n){int twice=2*c;int want=n<twice?twice:n;hkArrayUtil__reserve(a,this,want,sizeof(T));}}
    __forceinline T& expandWith(PAllocator& a) throw(){if(size==room())ResizeAudioStream(a,this,sizeof(T));new (data+size) T;return data[size++];}
    __forceinline void pushWith(PAllocator& a,const T& x) throw(){if(size==room())ResizeAudioStream(a,this,sizeof(T));copyElements(data+size,1,x,typename CopyKind<T>::type());++size;}
    __forceinline int indexOf(const T& x,int first=0,int last=-1) const throw(){if(last<0)last=size;for(int i=first;i<last;++i)if(data[i]==x)return i;return -1;}
    __forceinline void remove(int index) throw(){--size;copyByteRange(data+index,data+index+1,(size-index)*sizeof(T));}
};
template<class T> struct PArray:PArrayBase<T> {
    __forceinline PArray() throw(){}
    __forceinline ~PArray() throw(){PArrayBase<T>::clearDeallocate(PContainerAllocator().get(this));}
    __forceinline void reserve(int n) throw(){PArrayBase<T>::reserveWith(PContainerAllocator().get(this),n);}
    __forceinline T& expand() throw(){return PArrayBase<T>::expandWith(PContainerAllocator().get(this));}
    __forceinline void push(const T& x) throw(){PArrayBase<T>::pushWith(PContainerAllocator().get(this),x);}
};
template<class T> __forceinline T* stackAllocate(const int& n,const char* what=0) throw(){PRouter& r=*route();return static_cast<T*>(r.local().allocate((int(sizeof(T))*n+127)&~127,what));}
template<class T> __forceinline void stackDeallocate(T* p) throw(){route()->local().deallocate(static_cast<void*>(p));}
template<class T> struct PLocal : PArray<T> {
    T* localMemory;
    __forceinline PLocal(const int& n) throw(){this->data=stackAllocate<T>(n);this->capacity=n|0x80000000;localMemory=this->data;}
    __forceinline ~PLocal() throw(){if(localMemory==this->data)this->size=0;stackDeallocate(localMemory);}
};
struct PCast {PVec target;float penetration,tolerance;PCast() throw():penetration(1.1920928955078125e-7f),tolerance(1.1920928955078125e-7f){}};
struct PSolver {PVec position,velocity,maxVelocity,up;float time,minTime;PPlane* planes;int count;__forceinline PSolver() throw(){up.set(0,1,0);maxVelocity.all(1.1920928955078125e-7f);position.zero();}};
struct PResult {PVec position,velocity;float time;PInteraction* interactions;};
struct PPad {float value;__forceinline operator float() const throw(){return value;}};
struct PStep {__declspec(align(16)) PStorage<float> start;PStorage<float> end,delta,inverse;};
struct PPose {PVec axis0,axis1,axis2,position;void SetWorldPosition(const PVec& v) throw(){position=v;}};
struct PPhantom {virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual PPose* pose();virtual void f5();virtual void f6();virtual void f7();virtual void f8();virtual void f9();virtual void fa();virtual void fb();virtual void fc();virtual void fd();virtual void cast(const PVec&,const PCast&,hkpAllCdPointCollector&,hkpAllCdPointCollector*) throw();void hkpShapePhantom_setPosition(const PVec&,float) throw();};
struct PBody {void hkpEntity_addEntityListener(void*) throw();};
struct POther {void AddItem(void*) throw();};
void hkSimplexSolverSolve(const PSolver&,PResult&) throw();
struct PBase {virtual void f0();virtual void f1();virtual void f2();unsigned short memoryFlags;short references;};
struct PEntityListener {virtual void callback();};
struct PPhantomListener {virtual void callback();};
struct POwner:PBase,PEntityListener,PPhantomListener {
    virtual void update(hkpAllCdPointCollector&,hkpAllCdPointCollector&,PBool) throw();virtual void convert(const PContact&,PPlane&,float) const throw();
    PVec velocity,oldDisplacement;PPhantom* phantom;float friction,staticFriction;int m3c;PVec up;float extraUp,extraDown,keepDistance,keepTolerance,angle;int userPlanes;float maxSpeed,strength,mass;PArray<PContact> manifold;PArray<void*> listeners;PArray<PBody*> bodies;PArray<POther*> phantoms;float slope,recovery;int maxIterations;bool refresh;
    const PVec& hkpCharacterProxy_getPosition() const throw();
    void hkpCharacterProxy_linearCast(PBool,const PCast&,hkpAllCdPointCollector&,hkpAllCdPointCollector*) throw();
    void hkpCharacterProxy_convertFractionToDistance(const PContact*,int,const PVec&) const throw();
    void hkpCharacterProxy_fireConstraintsProcessed(const PArray<PContact>&,PSolver&) const throw();
    void ahkpCharacterProxy_ResolveContacts(const PStep&,const PVec&,void*,int) throw();
    int hkpCharacterProxy_findSurface(const PContact&) const throw();
    void hkpCharacterProxy_fireContactAdded(const PContact&) const throw();
    float hkpCharacterProxy_moveToLinearCastHitPosition(const PResult&,const hkpAllCdPointCollector&,const PCast&,PVec&) throw();
    void hkpCharacterProxy_integrateImplementation(const PStep&,const PVec&,hkpAllCdPointCollector&,hkpAllCdPointCollector&,void*,int) throw();
};
struct PTimer {const char* tag;unsigned time,time1;__forceinline void stamp() throw(){
unsigned int ticks;
__asm {
    rdtsc
    mov dword ptr[ticks], eax
}
time=ticks;
}};
struct PTimerList:PTimer {const char* first;};
struct PStream {
    PStorage<char*> start,current,capacity,capacityMinus16;
    __forceinline char* GetStreamEnd() throw(){return current.val();}
    __forceinline char* getLimit() throw(){return capacityMinus16.val();}
    __forceinline PBool available() throw(){return GetStreamEnd()<getLimit();}
    __forceinline void end(char* p) throw(){current=p;}
};
__forceinline void timerPart(const char* tag) throw(){PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimer* p=reinterpret_cast<PTimer*>(s.GetStreamEnd());p->tag=tag;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
__forceinline void timerBegin() throw(){PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimerList* p=reinterpret_cast<PTimerList*>(s.GetStreamEnd());p->tag=str_010c8508;p->first=str_010c8500;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
// src: XBOX_PDB 0x00cadca0
static __declspec(noinline) bool addMaxSlopePlane(int index,PArray<PPlane>& planes,float limit,const PVec& up) throw(){float d=planes[index].normal.dot(up);if(d>0.01f && d<limit){PPlane& out=planes.expand();out=planes[index];PVec correction;correction.mul(-d,up);out.normal.add(correction);out.normal.normalize();return true;}return false;}

__forceinline PBody* getBody(BhkShape* s) throw(){return s->unk18==1?reinterpret_cast<PBody*>(reinterpret_cast<char*>(s)+s->unk10):0;}
__forceinline POther* getOther(BhkShape* s) throw(){return s->unk18==2?reinterpret_cast<POther*>(reinterpret_cast<char*>(s)+s->unk10):0;}
__forceinline PContact* collectorBegin(hkpAllCdPointCollector& c) throw(){return reinterpret_cast<PContact*>(c.contacts.data);}
__forceinline int collectorCount(const hkpAllCdPointCollector& c) throw(){return c.contacts.count;}
__forceinline PContact& collectorContact(hkpAllCdPointCollector& c,int i) throw(){return reinterpret_cast<PContact*>(c.contacts.data)[i];}
__forceinline PBool collectorHit(const hkpAllCdPointCollector& c) throw(){return collectorCount(c)>0;}
__forceinline void removeFirst(hkpAllCdPointCollector& c) throw(){
    --c.contacts.count;
    copyByteRange(c.contacts.data,c.contacts.data+1,c.contacts.count*sizeof(RootContact289));
}
// @fnv 0x00cade20
// src: XBOX_PDB 0x00cade20
void POwner::hkpCharacterProxy_integrateImplementation(const PStep& step,const PVec& gravity,hkpAllCdPointCollector& cast,hkpAllCdPointCollector& start,void* command,int maxInteractions) throw() {
    {PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimerList* p=reinterpret_cast<PTimerList*>(s.GetStreamEnd());p->tag=str_010c8508;p->first=str_010c8500;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
    PBool threaded=command!=0;
    PVec position=hkpCharacterProxy_getPosition();
    float remaining=step.delta;
    PCast query;
    PResult solved;
    query.tolerance=keepTolerance+keepDistance;
    query.penetration=0.01f;
    for(int iter=0;remaining>1.1920928955078125e-7f && iter<maxIterations;++iter) {
        {PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimer* p=reinterpret_cast<PTimer*>(s.GetStreamEnd());p->tag=str_010c84f0;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
        query.target.sum(oldDisplacement,position);
        cast.reset();start.reset();
        if(threaded) {
            phantom->pose()->SetWorldPosition(position);
            hkpCharacterProxy_linearCast(iter!=0,query,cast,&start);
        } else phantom->cast(position,query,cast,&start);
        if(collectorHit(cast)) {
            cast.sortHits();
            hkpCharacterProxy_convertFractionToDistance(collectorBegin(cast),collectorCount(cast),oldDisplacement);
        }
        {PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimer* p=reinterpret_cast<PTimer*>(s.GetStreamEnd());p->tag=str_010c84dc;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
        update(start,cast,threaded);
        PLocal<PPlane> planes(manifold.count()+userPlanes+10);
        planes.resizeUnchecked(manifold.count());
        for(int i=0;i<manifold.count();++i) {
            convert(manifold[i],planes[i],step.delta-remaining);
            addMaxSlopePlane(i,planes,slope,up);
        }
        int used=planes.count();int extra=userPlanes;if(planes.room()-used<extra) planes.reserve(used+extra);
        {PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimer* p=reinterpret_cast<PTimer*>(s.GetStreamEnd());p->tag=str_010c84d0;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
        PSolver input;
        PLocal<PInteraction> interactions(userPlanes+planes.count());
        interactions.resizeUnchecked(userPlanes+planes.count());
        input.planes=planes.begin();
        input.count=planes.count();
        input.velocity=velocity;
        input.time=remaining;
        if(velocity.square()==0.0f) input.minTime=0.0f;
        else input.minTime=float(velocity.inverse())*keepDistance*0.5;
        input.position.zero();
        input.up=up;
        input.maxVelocity.all(maxSpeed);
        hkpCharacterProxy_fireConstraintsProcessed(manifold,input);
        solved.interactions=interactions.begin();
        hkSimplexSolverSolve(input,solved);
        {PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimer* p=reinterpret_cast<PTimer*>(s.GetStreamEnd());p->tag=str_010c84c4;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
        ahkpCharacterProxy_ResolveContacts(step,gravity,command,maxInteractions);
        {PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimer* p=reinterpret_cast<PTimer*>(s.GetStreamEnd());p->tag=str_010c84b8;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
        int ok=oldDisplacement.equal(solved.position,0.001f);
        if(!ok) {
            query.target.sum(position,solved.position);
            cast.reset();
            if(threaded) {
                phantom->pose()->SetWorldPosition(position);
                hkpCharacterProxy_linearCast(true,query,cast,0);
            } else phantom->cast(position,query,cast,0);
            if(collectorHit(cast)) {
                cast.sortHits();
                hkpCharacterProxy_convertFractionToDistance(collectorBegin(cast),collectorCount(cast),solved.position);
                while(hkpCharacterProxy_findSurface(collectorContact(cast,0))!=-1) {
                    removeFirst(cast);
                    if(!collectorHit(cast)) {ok=1;break;}
                }
                if(collectorCount(cast)>0) {
                    const PContact& hit=collectorContact(cast,0);
                    hkpCharacterProxy_fireContactAdded(hit);
                    manifold.push(hit);
                    if(!refresh) {
                        PBody* body=getBody(hit.rootB);
                        if(body && bodies.indexOf(body)==-1) {
                            if(!threaded) body->hkpEntity_addEntityListener(static_cast<PEntityListener*>(this));
                            bodies.push(body);
                        }
                        POther* phantom=getOther(hit.rootB);
                        if(phantom && phantoms.indexOf(phantom)==-1) {
                            if(!threaded) phantom->AddItem(static_cast<PPhantomListener*>(this));
                            phantoms.push(phantom);
                        }
                    }
                }
            } else ok=1;
        }
        if(ok) {
            position.add(solved.position);
            remaining-=solved.time;
        } else remaining-=hkpCharacterProxy_moveToLinearCastHitPosition(solved,cast,query,position);
        oldDisplacement=solved.position;
    }
    velocity=solved.velocity;
    if(threaded) phantom->pose()->SetWorldPosition(position);
    else phantom->hkpShapePhantom_setPosition(position,query.tolerance);
    {PStream& s=*static_cast<PStream*>(TlsGetValue(DAT_0126835c));if(s.available()){PTimer* p=reinterpret_cast<PTimer*>(s.GetStreamEnd());p->tag=str_01076f38;p->stamp();s.end(reinterpret_cast<char*>(p+1));}}
}


template <typename T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        m_data[index] = m_data[m_iElementCount];
}
