#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/staging/blk_00540000_o2_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /GS /EHsc /Gy /Od (unit src/staging/blk_00540000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00540000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include "../../include/hkVector4.h"
typedef unsigned int U32;
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();

    float* FUN_00560d30(int);
};
struct FUN_00404eb0
{
    U32 flags;
    FUN_00404eb0(int context, int enabled, const char* filename, int line);
    ~FUN_00404eb0()
    {
        FUN_00404ee0();
    }
    void FUN_00404ee0();
};
struct __declspec(align(16)) FUN_00c681c0
{
    U32 header0, header1, header2, header3;
    hkVector4 orientation;
    U32 unk20;
    U32 unk24;
    U32 unk28;
    U32 unk2c;
    U32 unk30;
    U32 unk34;
    U32 unk38;
    U32 unk3c;
    U32 unk40;
    U32 unk44;
    U32 unk48;
    U32 unk4c;
    U32 unk50;
    float alpha;
    U32 unk58;
    U32 unk5c;
    U32 unk60;
    U32 unk64;
    U32 unk68;
    U32 unk6c;
    U32 unk70;
    U32 unk74;
    U32 unk78;
    U32 unk7c;
    U32 unk80;
    U32 unk84;
    U32 unk88;
    U32 unk8c;
    U32 unk90;
    U32 unk94;
    U32 unk98;
    U32 unk9c;
    U32 unka0;
    U32 unka4;
    U32 unka8;
    U32 unkac;
    U32 unkb0;
    U32 unkb4;
    U32 unkb8;
    U32 unkbc;
    U32 unkc0;
    U32 unkc4;
    U32 unkc8;
    U32 unkcc;
    U32 unkd0;
    U32 unkd4;
    U32 unkd8;
    U32 unkdc;
    U32 unke0;
    U32 unke4;
    U32 unke8;
    U32 unkec;
    FUN_00c681c0();
    ~FUN_00c681c0()
    {
        Object_ForwardCall_00553520();
    }
    void Object_ForwardCall_00553520();
    void hkpWorldCinfo_setBroadPhaseWorldSize(float);
};
struct Component
{
    void FUN_00483710();
};
void* __cdecl Object_OurMemalign_Thunk(unsigned int);
struct CurveBase
{
    U32 field08, field0c, field10, field14, field18, field1c, field20;
};
struct CurveOwner
{
    U32 field00, field04;
};
struct ParticleSystem
{
    virtual void VFunction0();
    virtual void VFunction1();
    virtual void VFunction2();
    virtual void VFunction3();
    virtual void VFunction4();
    virtual void VFunction5();
    virtual void VFunction6();
    virtual void VFunction7();
    virtual void VFunction8();
    virtual void VFunction9();
    virtual void VFunction10();
    virtual void VFunction11();
    virtual void VFunction12();
    virtual void VFunction13();
    virtual void VFunction14();
    virtual void VFunction15();
    virtual void VFunction16();
    virtual void VFunction17();
    virtual void VFunction18();
    virtual void VFunction19();
    virtual void VFunction20();
    virtual void VFunction21();
    virtual void VFunction22();
    virtual void VFunction23();
    virtual void VFunction24();
    virtual void VFunction25();
    virtual void VFunction26();
    virtual void VFunction27();
    virtual void VFunction28();
    virtual void VFunction29();
    virtual void VFunction30();
    virtual void VFunction31();
    virtual void VFunction32();
    virtual void VFunction33();
    virtual void VFunction34();
    virtual void VFunction35();
    virtual void VFunction36();
    virtual void VFunction37();
    virtual void VFunction38();
    virtual void VFunction39();
    virtual void VFunction40();
    virtual void VFunction41();
    virtual void VFunction42();
    virtual void VFunction43();
    virtual void VFunction44();
    virtual void VFunction45();
    virtual void VFunction46();
    virtual void VFunction47();
    virtual void VFunction48();
    virtual void Update();
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned int fieldac;
    unsigned int fieldb0;
    unsigned int fieldb4;
    unsigned int fieldb8;
    unsigned int fieldbc;
    unsigned int fieldc0;
    unsigned int fieldc4;
    unsigned int fieldc8;
    static void* operator new(unsigned int n)
    {
        return Object_OurMemalign_Thunk(n);
    }
    Component* FUN_00541c80();
    void bhkWorld_AddEntityListener(void*);
    void bhkWorld_AddTrapListener(CurveBase*);
    void SetField(void*);
    void bhkWorld_AppendAcousticSpaceListener(void*);
    void bhkWorld_AddContactListener(void*);
    void bhkWorld_SetOrigin(FUN_006815c0*);
    void bhkWorld_SetEnabled(bool);
    void SetProcessEnabled(int);
};
struct FUN_00c99ff0 : ParticleSystem
{
    static void operator delete(void*);
    FUN_00c99ff0(FUN_00c681c0*, FUN_006815c0*, FUN_006815c0*);
};
struct FUN_00554590
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    FUN_00554590();
};
struct FUN_0062d5c0 : CurveOwner, CurveBase
{
    FUN_0062d5c0();
};
struct FUN_0061f460
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    FUN_0061f460();
};
struct FUN_0062a460
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    FUN_0062a460();
};
struct FUN_00624150
{
    U32 header, body;
    FUN_00624150();
    void NotifyActivation(Component*);
};
extern "C"
{
    extern float DAT_011ca158, DAT_0102f104, DAT_0102f100, DAT_0102f0fc;
    extern const char str_0102ed68[];
    extern FUN_00624150* DAT_011ca088;
}
extern float __cdecl NI2HK_004a3e90(float);
extern void* __cdecl TESWaterListener_GetExteriorListener();
extern void* __cdecl FOCollisionListener_GetSingleton();
extern bool __cdecl TES_QCollisionDisableFlag();
// @fnv 0x00554010
// src: XBOX_PDB 0x00554010
ParticleSystem* __cdecl TESObjectCELL_CreateWorld(const FUN_006815c0* origin)
{
    FUN_00404eb0 context(16, 1, str_0102ed68, 0x3c1b);
    FUN_00c681c0 source;
    __declspec(align(16)) unsigned char rotation[sizeof(hkVector4)];
    source.orientation.SetValue(reinterpret_cast<hkVector4*>(rotation)->hkVector4_hkVector4(0.0f, 0.0f, DAT_011ca158, 0.0f));
    source.hkpWorldCinfo_setBroadPhaseWorldSize(NI2HK_004a3e90(DAT_0102f104));
    FUN_006815c0 direction;
    direction = *origin;
    direction.z = 0.0f;
    source.alpha = 1.0f;
    __declspec(align(16)) FUN_006815c0 velocity;
    *velocity.FUN_00560d30(0) = NI2HK_004a3e90(DAT_0102f100);
    *velocity.FUN_00560d30(1) = NI2HK_004a3e90(DAT_0102f100);
    *velocity.FUN_00560d30(2) = NI2HK_004a3e90(DAT_0102f100);
    __declspec(align(16)) FUN_006815c0 acceleration;
    *acceleration.FUN_00560d30(0) = NI2HK_004a3e90(DAT_0102f0fc);
    *acceleration.FUN_00560d30(1) = NI2HK_004a3e90(DAT_0102f0fc);
    *acceleration.FUN_00560d30(2) = NI2HK_004a3e90(DAT_0102f0fc);
    ParticleSystem* system = new FUN_00c99ff0(&source, &velocity, &acceleration);
    system->FUN_00541c80()->FUN_00483710();
    system->bhkWorld_AddEntityListener(new FUN_00554590());
    system->bhkWorld_AddTrapListener(new FUN_0062d5c0());
    system->SetField(TESWaterListener_GetExteriorListener());
    system->bhkWorld_AppendAcousticSpaceListener(new FUN_0061f460());
    system->bhkWorld_AddContactListener(FOCollisionListener_GetSingleton());
    system->bhkWorld_AddEntityListener(new FUN_0062a460());
    if (!DAT_011ca088)
        DAT_011ca088 = new FUN_00624150();
    DAT_011ca088->NotifyActivation(system->FUN_00541c80());
    system->bhkWorld_SetOrigin(&direction);
    system->FUN_00541c80()->FUN_00483710();
    system->Update();
    system->bhkWorld_SetEnabled(!TES_QCollisionDisableFlag());
    system->SetProcessEnabled(0);
    return system;
}
