#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSProjectile.h"
#include "../../../../include/BeamProjectile.h"
#include "../../../../include/MissileProjectile.h"
#include "../../../../include/bhkConstraint.h"
#include "../../../../include/bhkHingeConstraint.h"

// src/fallout/ai/combat/missileprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/missileprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/ai/combat/missileprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/missileprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_011c6278;
int __cdecl FixedStrings_QPinnedLimb();
extern char const* const g_01268310_arg1;
struct FUN_009ba4d0_shell
{
    char const* const* GetArg1Ptr();
};
extern "C" void __cdecl FUN_00c89640(void*);
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
struct FUN_009b7c90_shell : BGSProjectile
{
    bool BGSProjectile_GetPinsLimbs();
};
extern "C" void __cdecl _delete(void*, unsigned int);

struct TlsBlock_t
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
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

extern __declspec(thread) TlsBlock_t g_tlsBlock;
extern int g_ctrA;
extern int g_ctrD;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock();
void* __cdecl Object_DispatchCommandFour(unsigned int size);

class OwnerBase_t
{
  public:
    OwnerBase_t();
    virtual void unkB0();
    virtual ~OwnerBase_t();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

class ChainA_t : public OwnerBase_t
{
  public:
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_t()
    {
        m_0c = 0;
        g_ctrA += 1;
    }
};

class SpawnedObject_t : public ChainA_t
{
  public:
    virtual void unkD2();
    SpawnedObject_t()
    {
        g_ctrD += 1;
    }
};

struct FUN_00cbdd60_cls
{
    int unk00;
    int unk04;
    void bhkConstraint_CopyMembers(SpawnedObject_t* obj, unsigned int arg);
    SpawnedObject_t* bhkHingeConstraint_CreateClone(unsigned int arg);
};

// @fnv 0x00cbdd60
// src: XBOX_PDB 0x00cbdd60
SpawnedObject_t* FUN_00cbdd60_cls::bhkHingeConstraint_CreateClone(unsigned int arg)
{
    TlsGuard_t guard;
    SpawnedObject_t* result = 0;
    bhkSerializable_CloneCritLock();
    result = new SpawnedObject_t();
    bhkConstraint_CopyMembers(result, arg);
    bhkSerializable_CloneCritUnlock();
    return result;
}

struct S_cbde40_Tls
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
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};
__declspec(thread) S_cbde40_Tls g_tls_cbde40;
struct S_cbde40_Guard
{
    int saved;
    S_cbde40_Guard()
    {
        saved = g_tls_cbde40.unk2B4;
        g_tls_cbde40.unk2B4 = 0x10;
    }
    ~S_cbde40_Guard()
    {
        g_tls_cbde40.unk2B4 = saved;
    }
};
struct S_cbde40_Pool
{
    void* Game_DoHeapAlloc(unsigned int n);
};
extern S_cbde40_Pool DAT_011f6238;
extern int DAT_0108ff98;
struct S_cbde40_Base
{
    int unk00;
};
struct S_cbde40_Obj
{
    int* unk00;
    S_cbde40_Base base;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
struct S_cbde40
{
    int unk00;
    int unk04;
    int unk08;
    S_cbde40_Base* unk0c;
    void CopyFromSource(S_cbde40_Obj* c);
    S_cbde40_Base* bhkHingeConstraint_CreateCinfo(bool* created);
};
// @fnv 0x00cbde40
// src: XBOX_PDB 0x00cbde40
S_cbde40_Base* S_cbde40::bhkHingeConstraint_CreateCinfo(bool* created)
{
    S_cbde40_Guard guard;
    bool b = (unk0c == 0);
    *created = b;
    if (b)
    {
        S_cbde40_Obj* c = new S_cbde40_Obj;
        S_cbde40_Base* r;
        if (c)
        {
            S_cbde40_Base* bp = &c->base;
            c->unk08 = 1;
            c->unk0c = 0;
            c->unk10 = 0;
            c->unk00 = &DAT_0108ff98;
            bp->unk00 = 0;
            r = bp;
        }
        else
        {
            r = 0;
        }
        unk0c = r;
        if (unk08)
            CopyFromSource(unk0c ? (S_cbde40_Obj*)((char*)unk0c - 4) : 0);
    }
    return unk0c;
}

class NiAVObject;
class NiCollisionObject;

struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    unsigned int uiValue;
    int unk10;
    int unk14;
    int unk18;
};

typedef void (*CollisionObjectCountCallback)(NiCollisionObject*, CollisionObjectCountContext*);
void bhkWorld_DoObjectRec(NiAVObject* pkObject, CollisionObjectCountContext* pkContext,
                  CollisionObjectCountCallback pfnCallback);
extern CollisionObjectCountCallback DAT_011afec0;

struct C6A0B0Properties
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiValue1;
};
extern "C" C6A0B0Properties* GetExtraDataChecked(NiAVObject* pkObject);
static inline unsigned int C6A0B0IsEnabled(NiAVObject* pkObject)
{
    C6A0B0Properties* pkProps = GetExtraDataChecked(pkObject);
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}

// @fnv 0x00c6a0b0
// src: XBOX_PDB 0x00c6a0b0
bool bhkWorld_EnableCollision(NiAVObject* pkObject, bool bValue, bool bRecurse, bool bForce)
{
    bool bResult = false;
    if (pkObject && (bForce || C6A0B0IsEnabled(pkObject)))
    {
        CollisionObjectCountContext kContext;
        bResult = true;
        kContext.pCurrentObject = 0;
        kContext.bRecurse = bRecurse;
        kContext.uiTraversalFlags = 0xe;
        kContext.uiValue = bValue;
        if (DAT_011afec0)
            bhkWorld_DoObjectRec(pkObject, &kContext, DAT_011afec0);
    }
    return bResult;
}
