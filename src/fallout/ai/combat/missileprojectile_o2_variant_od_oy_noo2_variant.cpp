#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSProjectile.h"
#include "../../../../include/MissileProjectile.h"
#include "../../../../include/bhkConstraint.h"
#include "../../../../include/bhkHingeConstraint.h"
#include "../../../../include/NiPoint3.h"

// src/fallout/ai/combat/missileprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/missileprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/missileprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/missileprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/missileprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/missileprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_011c6278;
int __cdecl FixedStrings_QPinnedLimb();
extern char const* const g_01268310_arg1;
extern "C" void __cdecl FUN_00c89640(void*);
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
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

namespace fnv_009b90b0 {
struct Obj;
struct Big;
struct V9;

struct V
{
    float x;
    float y;
    float z;
    V* FUN_006815c0();
    V* ApplyScaled(V* out, float f);
    V* SubtractIntoVector(V* out, const V* a);
    void Unitize_004a0c10();
    void FUN_0043d410(float x, int y, int z);
    V* FUN_00439e90(V* out, V* a);
    void normalize3_0062aea0();
};

struct V5
{
    float a;
    float b;
    float c;
    float d;
    float e;
    V5* FUN_006815c0();
    void normalize3_0062aea0();
};

struct V6
{
    V5 q;
    float f;
    V6* FUN_006815c0();
};

struct V9
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    V9* FUN_006815c0();
    void FUN_004a0c90(float f);
    void FUN_00524ac0(float f);
    V9* FUN_0043f8d0(V9* out, V9* b);
    void NiMatrix3_GetCol(int a, V* out);
};

struct Xform
{
    V9 rot;
    V pos;
    float scale;
    void NiTransform_NiTransform();
    void InvertTransform(Xform* out);
    Xform* FUN_0062c250(Xform* out, Xform* b);
    V* ComputeValue_00524c40(V* out, V* b);
};


struct Str
{
    int p;
    Str(int s);
    ~Str();
};

struct Ctrl
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void SetScale(float f);
    Ctrl(float f);
    ~Ctrl();
};

struct Item
{
    unsigned char unk00;
    unsigned char unk01;
};

struct Arr
{
    unsigned int FUN_0044ddc0();
    Item** FUN_00877a30(unsigned int i);
};

struct Rec
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
    void hkpWorldRayCastOutput_hkpWorldRayCastOutput_00696c30(Rec* r);
};

struct List
{
    int FUN_00726070();
    Rec* GetEntryAt(int i);
};

struct ListH
{
    List* TESDataHandler_GetWorldSpaceList();
};

struct Big
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    void FUN_004a3c20();
    void bhkPickData_SetFrom(const V* v);
    void bhkPickData_SetLength(V* v);
    void bhkPickData_SetAllCollector(struct Res* r);
    ListH* DialoguePackage_GetCurrentDialogItem();
    void bhkPickData_SetFilter(int a);
};

struct __declspec(align(16)) Res
{
    int unk00[200];
    Res();
    ~Res();
};

void* Object_DispatchCommandFour(unsigned int n);

struct Path
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void EnsureChild();
    void hkConstraintCinfo_SetEntities(Obj* a, Obj* b);
    void hkHingeConstraintCinfo_SetInWorldSpace(struct Name* a, struct Name* b, V5* c, V5* d);
    Path();
    ~Path();
};

struct PathRef
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    PathRef(Path* p);
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
};

void* Object_DispatchCommandFour(unsigned int n);

struct Name
{
    char buf[64];
    Name(int a);
    Obj* FUN_006815c0();
};

struct Color
{
    float r;
    float g;
    float b;
    float a;
    void FUN_00414430(float r, float g, float b, float a);
};

struct Handle
{
    int val;
    void FUN_008c71b0(int a);
    void CFilter_SetLayer(int a);
    void CFilter_SetGroup(int a);
};

struct HandleSrc
{
    int val;
    int CFilter_GetGroup();
};

struct Sub
{
    int unk00;
    bool FUN_008256d0();
    Obj** FUN_006815c0();
    Obj* FUN_00726070();
};

struct Obj
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual Obj* vfc();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual Obj* vf9c(const Str& s);
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void vfb8(V* v);
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void vfc8(Big* b);
    virtual void v051();
    virtual void vfd0(Obj* a, int b, int c, int d, int e);
    virtual void v053();
    virtual void v054();
    virtual void vfdc(Obj* a, int b);
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool vf100();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual Obj* vf1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual V* vf1f4();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void vf2a4();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float vf2bc(int a);
    Obj** FUN_006815c0();
    Obj* FUN_0042e8c0();
    float NiAVObject_GetWorldScale();
    Obj* FUN_00a5d2c0(Ctrl* c);
    void RemoveLimb(int a);
    void FUN_00450f90(int a);
    void NiAVObject_SetScale(float f);
    unsigned int FUN_0043b480();
    Obj* FUN_0043b4a0(unsigned int i);
    void NiAVObject_Update(NiPoint3* v);
    Obj* TESObjectCELL_GetbhkWorld();
    void NiAVObject_SetTranslate(void* a);
    void SetRotate_0043fa80(void* a);
    int NiNode_GetAtChecked(int a);
    Xform* NiAVObject_GetWorldRotate();
    void AssignFixedString(int a);
    Obj* bhkNiCollisionObject_GetWorldObject();
    Obj* Bipedanim_GetReferenceFlagsOrZero();
    int hkpRigidBody_getTransform();
    void hkRotation_renormalize();
    void bhkRigidBody_AddActCon(PathRef* p);
    void UpdateMatchingNodes(Obj* a);
    HandleSrc* bhkCharacterController_GetCollisionFilter(int* out);
    HandleSrc* FUN_00931ed0(int* out);
    int CFilter_GetLayer();
    Obj* bhkWorldObject_GetCollisionFilter(int* out);
    int bhkRigidBody_GetMotionType();
    void bhkCharacterController_SetPosition(V5* v);
};

struct Owner
{
    Obj* unk00;
    V unk04;
    int pad10;
    int pad14;
    int pad18;
    int pad1C;
    int pad20;
    int unk24;
    unsigned char unk28;
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Arr unk20;
};

struct Glob
{
    float* Setting_Float_00403e20();
    bool BGSSaveLoadGame_GetSaveGameLoading();
    void FUN_00458e20(int a, float f);
    V* GetNegatedVector(V* out);
    Obj* BGSSaveFormBuffer_GetForm();
    void SetValue(int a);
};

extern Glob DAT_011ce1e8;
extern Glob* DAT_011ddf38;
extern int DAT_01196d6c[];
extern int DAT_011f426c;
extern int DAT_011a9448;
extern Glob DAT_011a9478;
extern Glob DAT_011f210c;
extern Glob* DAT_011dea10;
extern Glob DAT_011f2250;

bool Animation_FindSkinnedNode(Obj* a);
void BipedAnim_AttachToSkeleton(Obj* a, Obj* b, Obj* c, int d);
int FixedStrings_QPinnedLimb();
void bhkWorld_UpdatePosition(Obj* a, int b, int c);
void bhkWorld_SetMotion(Obj* a, int b, int c, int d, int e);
void bhkWorld_SetGroup(Obj* a, int b, int c, int d);
void bhkWorld_EnableCollision(Obj* a, int b, int c, int d);
bool Projectile_PickSceneGraph(Big* a, Obj* b, int c, int d);
int GetAVObjectForCollidable(int a);
Obj* FindFirstCollisionObject(Obj* a);
void FUN_00553fc0(V5* a, V* b);
void NI2HK(void* a, V* b);
int bhkCollisionFilter_GetNewSystemGroup();
int MakeLine(V* a, Color* b, V* c, Color* d, int e);
int hkpGetRigidBody(int a);
Obj* bhkEntity_Getbhk(int a);
Obj* TESObjectREFR_FindReferenceFor3D(int a);
void TESHavokUtilities_AddVelocity(Obj* a, V* b, int c);


struct VRes
{
    void ProcessAndReturnValue_0053d280();
};

}  // namespace fnv_009b90b0

// @fnv 0x009b90b0
// src: XBOX_PDB 0x009b90b0
void MissileProjectile::ProcessImpale()
{
    using namespace fnv_009b90b0;
    using fnv_009b90b0::Obj;
    using fnv_009b90b0::V;
    using fnv_009b90b0::Path;
    static float s_offset = *DAT_011ce1e8.Setting_Float_00403e20();
    bool noMove = DAT_011ddf38->BGSSaveLoadGame_GetSaveGameLoading();
    if (!kImpacts.IsEmpty())
    {
        Obj* p24 = ((Obj*)GetNiNode());
        Obj* p28 = p24->vfc();
        Owner* owner = (Owner*)kImpacts.GetItem();
        fUnk158 = 10.0f;
        if (uiImpactResult == 4)
        {
            owner = (Owner*)(kImpacts.GetNext() ? kImpacts.GetNext()->GetItem() : 0);
        }
        if (owner && owner->unk00 && owner->unk00->vf100())
        {
            if (owner->unk28)
                return;
            Obj* p34 = owner->unk00;
            if (reinterpret_cast<Actor*>(p34)->FUN_00573090(owner->unk24))
            {
                Holder* p38 = (Holder*)reinterpret_cast<Obj*>(reinterpret_cast<Actor*>(p34)->BSFile_GetDevice())->FUN_0042e8c0();
                bool found = false;
                for (unsigned int i = 0; i < p38->unk20.FUN_0044ddc0(); i++)
                {
                    if ((*p38->unk20.FUN_00877a30(i))->unk00 == (char)owner->unk24 &&
                        (*p38->unk20.FUN_00877a30(i))->unk01)
                        found = true;
                }
                Obj* p48 = owner->unk00 ? owner->unk00->vf1d0() : 0;
                if (p48 && !found)
                {
                    int p4c = DAT_01196d6c[owner->unk24];
                    Obj* p60 = p48 ? p48->vf9c(Str(p4c)) : 0;
                    float f64 = p60->NiAVObject_GetWorldScale();
                    if (p60 == 0)
                    {
                        byte90 = 0;
                        return;
                    }
                    {
                        Ctrl ctrl(1.0f);
                        ctrl.SetScale(1.0f);
                        Obj* p84 = p60->FUN_00a5d2c0(&ctrl);
                        p34->RemoveLimb(owner->unk24);
                        p60 = p84;
                        p60->FUN_00450f90(0);
                        p60->NiAVObject_SetScale(f64);
                        Obj* p88 = p60->vfc();
                        if (p88)
                        {
                            for (unsigned int j = 0; j < p88->FUN_0043b480(); j++)
                            {
                                Obj* p90 = p88->FUN_0043b4a0(j);
                                if (p90 && Animation_FindSkinnedNode(p90))
                                    BipedAnim_AttachToSkeleton(p88, p90, p88, 0);
                            }
                        }
                        V v9c;
                        v9c.FUN_0043d410(0.0f, 0, 0);
                        p60->NiAVObject_Update((NiPoint3*)&v9c);
                        Obj* pa0 = ((Obj*)GetParentCell())->TESObjectCELL_GetbhkWorld();
                        if (pa0)
                            pa0->vfd0(p60, 1, 0, 0, 1);
                        p60->NiAVObject_SetTranslate(&DAT_011f426c);
                        p60->SetRotate_0043fa80(&DAT_011a9448);
                        if (p88 && p88->NiNode_GetAtChecked(0))
                        {
                            Xform xd4 = *p88->FUN_0043b4a0(0)->NiAVObject_GetWorldRotate();
                            if (!noMove)
                                SetLocationOnReference(*(NiPoint3*)&owner->unk04);
                            FUN_009bf470(0, 0);
                            V ve0;
                            ve0.FUN_0043d410(0.0f, 0, 0);
                            p28->vfb8((V*)&ve0);
                            Xform x114 = *p28->NiAVObject_GetWorldRotate();
                            Xform x148;
                            x148.NiTransform_NiTransform();
                            x114.InvertTransform(&x148);
                            Xform x17c;
                            xd4 = *x148.FUN_0062c250(&x17c, &xd4);
                            xd4.pos.y -= s_offset;
                            p88->FUN_0043b4a0(0)->NiAVObject_SetTranslate(&xd4.pos);
                            p88->FUN_0043b4a0(0)->SetRotate_0043fa80(&xd4);
                            p88->FUN_0043b4a0(0)->NiAVObject_SetScale(xd4.scale);
                        }
                        p28->vfdc(p60, 1);
                        p60->AssignFixedString(fnv_009b90b0::FixedStrings_QPinnedLimb());
                        bhkWorld_UpdatePosition(p60, 1, 1);
                        bhkWorld_SetMotion(p60, 4, 1, 1, 1);
                        V v188;
                        v188.FUN_0043d410(0.0f, 0, 0);
                        p28->NiAVObject_Update((NiPoint3*)&v188);
                        bool blocked = false;
                        if (p60)
                        {
                            int p190 = 0;
                            Obj* p194 = ((Obj*)GetParentCell())->TESObjectCELL_GetbhkWorld();
                            Big big;
                            big.FUN_004a3c20();
                            V v25c;
                            v25c.FUN_006815c0();
                            V v268;
                            v268.FUN_006815c0();
                            v25c = *((V*)static_cast<const MobileObject*>(this)->GetPos());
                            V9 m28c;
                            m28c.FUN_006815c0();
                            m28c.FUN_004a0c90(GetCurrentTargetDistance(false));
                            V9 m2b0;
                            m2b0.FUN_006815c0();
                            m2b0.FUN_00524ac0(GetLooking());
                            V9 m2d4;
                            m28c = *m28c.FUN_0043f8d0(&m2d4, &m2b0);
                            m28c.NiMatrix3_GetCol(1, &v268);
                            v268.Unitize_004a0c10();
                            V t2e0;
                            V t2ec;
                            big.bhkPickData_SetFrom(v25c.SubtractIntoVector(&t2ec, v268.ApplyScaled(&t2e0, 512.0f)));
                            V t2f8;
                            big.bhkPickData_SetLength(v268.ApplyScaled(&t2f8, 1024.0f));
                            {
                                Res res;
                                big.bhkPickData_SetAllCollector(&res);
                                bool ok = Projectile_PickSceneGraph(&big, p60, 0, 1);
                                if (ok && big.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->FUN_00726070() > 0)
                                    p190 = GetAVObjectForCollidable(big.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(0)->unk50);
                            }
                            if (p190)
                            {
                                Obj* p628 = FindFirstCollisionObject(((Obj*)GetNiNode()));
                                Obj* p630 = p628 ? p628->bhkNiCollisionObject_GetWorldObject() : 0;
                                Obj* p634 = FindFirstCollisionObject((Obj*)p190);
                                Obj* p63c = p634 ? p634->bhkNiCollisionObject_GetWorldObject() : 0;
                                if (p63c && p63c != p630)
                                {
                                    Path path;
                                    path.EnsureChild();
                                    path.hkConstraintCinfo_SetEntities(p63c, p630);
                                    Name n690(p63c->Bipedanim_GetReferenceFlagsOrZero()->hkpRigidBody_getTransform());
                                    Name n6d0(p630->Bipedanim_GetReferenceFlagsOrZero()->hkpRigidBody_getTransform());
                                    n690.FUN_006815c0()->hkRotation_renormalize();
                                    n6d0.FUN_006815c0()->hkRotation_renormalize();
                                    V v6dc;
                                    v6dc.FUN_006815c0();
                                    ((Obj*)GetNiNode())->NiAVObject_GetWorldRotate()->rot.NiMatrix3_GetCol(1, &v6dc);
                                    V5 v6f0;
                                    v6f0.FUN_006815c0();
                                    FUN_00553fc0(&v6f0, &v6dc);
                                    v6f0.normalize3_0062aea0();
                                    Xform x724 = *((Obj*)GetNiNode())->NiAVObject_GetWorldRotate();
                                    V v730;
                                    V v73c;
                                    V v748;
                                    DAT_011a9478.GetNegatedVector(&v73c)->ApplyScaled(&v730, s_offset);
                                    x724.ComputeValue_00524c40(&v748, &v730);
                                    V6 v760;
                                    v760.FUN_006815c0();
                                    NI2HK(&v760, &v748);
                                    path.hkHingeConstraintCinfo_SetInWorldSpace(&n690, &n6d0, &v760.q, &v6f0);
                                    PathRef* ref = new PathRef(&path);
                                    p63c->bhkRigidBody_AddActCon(ref);
                                    p63c->UpdateMatchingNodes(((Obj*)GetParentCell())->TESObjectCELL_GetbhkWorld());
                                    Obj* p774 = ((Obj*)GetParentCell())->TESObjectCELL_GetbhkWorld();
                                    Big big2;
                                    big2.FUN_004a3c20();
                                    V v83c;
                                    v83c.FUN_006815c0();
                                    V v848;
                                    v848.FUN_006815c0();
                                    v83c = *((V*)static_cast<const MobileObject*>(this)->GetPos());
                                    V9 m86c;
                                    m86c.FUN_006815c0();
                                    m86c.FUN_004a0c90(GetCurrentTargetDistance(false));
                                    V9 m890;
                                    m890.FUN_006815c0();
                                    m890.FUN_00524ac0(GetLooking());
                                    V9 m8b4;
                                    m86c = *m86c.FUN_0043f8d0(&m8b4, &m890);
                                    m86c.NiMatrix3_GetCol(1, &v848);
                                    v848.Unitize_004a0c10();
                                    Handle h;
                                    h.FUN_008c71b0(0);
                                    int t8bc;
                                    if (((Obj*)GetPhysicsCharacterController()))
                                    {
                                        h.val = ((Obj*)GetPhysicsCharacterController())->bhkCharacterController_GetCollisionFilter(&t8bc)->val;
                                    }
                                    else
                                    {
                                        h.CFilter_SetLayer(6);
                                        Obj* p8c0;
                                        int t8c4;
                                        if (((Obj*)Projectile_GetShooter()) && (p8c0 = ((Obj*)Projectile_GetShooter()), p8c0->vf100()))
                                            h.CFilter_SetGroup(((Obj*)Projectile_GetShooter())->FUN_00931ed0(&t8c4)->CFilter_GetGroup());
                                        else
                                            h.CFilter_SetGroup(bhkCollisionFilter_GetNewSystemGroup());
                                    }
                                    V v8e0;
                                    v848.ApplyScaled(&v8e0, (float)(GetFirstLightParameter() - Projectile_GetDistanceMoved()));
                                    big2.bhkPickData_SetFilter(h.val);
                                    big2.bhkPickData_SetFrom(&v83c);
                                    big2.bhkPickData_SetLength(&v8e0);
                                    Res res2;
                                    big2.bhkPickData_SetAllCollector(&res2);
                                    Obj* pc04 = ((Obj*)GetParentCell())->TESObjectCELL_GetbhkWorld();
                                    pc04->vfc8(&big2);
                                    if (0)
                                    {
                                        Color c;
                                        c.FUN_00414430(1.0f, 0.5f, 0.5f, 1.0f);
                                        V tc20;
                                        int c24 = MakeLine(&v83c, &c, v83c.FUN_00439e90(&tc20, &v8e0), &c, 1);
                                        DAT_011dea10->FUN_00458e20(c24, *DAT_011f210c.Setting_Float_00403e20());
                                    }
                                    for (int k = 0; !blocked && k < big2.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->FUN_00726070();
                                         k++)
                                    {
                                        Rec rec;
                                        rec.hkpWorldRayCastOutput_hkpWorldRayCastOutput_00696c30(big2.DialoguePackage_GetCurrentDialogItem()->TESDataHandler_GetWorldSpaceList()->GetEntryAt(k));
                                        int pc94 = GetAVObjectForCollidable(rec.unk50);
                                        Obj* pc98 = bhkEntity_Getbhk(hkpGetRigidBody(rec.unk50));
                                        Obj* pc9c = TESObjectREFR_FindReferenceFor3D(pc94);
                                        int tca0;
                                        int type = pc98 ? pc98->bhkWorldObject_GetCollisionFilter(&tca0)->CFilter_GetLayer() : 0;
                                        if (pc98 &&
                                            (type == 1 || type == 2 || type == 9 || type == 0x11 || type == 0xd ||
                                             type == 0x14) &&
                                            (pc98->bhkRigidBody_GetMotionType() == 5 || pc98->bhkRigidBody_GetMotionType() == 4))
                                        {
                                            blocked = true;
                                        }
                                        else if (pc98 && pc9c != (Obj*)this && pc9c && pc9c != owner->unk00)
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        owner->unk28 = 1;
                        if (blocked)
                        {
                            if (MiddleHighProcess_GetCurrentFurniture())
                                FUN_008126e0(0);
                            bhkWorld_UpdatePosition(p60, 1, 1);
                            bhkWorld_SetMotion(p60, 4, 1, 1, 1);
                            if (((Obj*)GetPhysicsCharacterController()))
                            {
                                int tcac;
                                bhkWorld_SetGroup(p60, ((Obj*)GetPhysicsCharacterController())->bhkCharacterController_GetCollisionFilter(&tcac)->CFilter_GetGroup(), 1, 1);
                                if (!noMove)
                                {
                                    SetLocationOnReference(*(NiPoint3*)&owner->unk04);
                                    V5 vcc0;
                                    vcc0.FUN_006815c0();
                                    NI2HK(&vcc0, &owner->unk04);
                                    ((Obj*)GetPhysicsCharacterController())->bhkCharacterController_SetPosition(&vcc0);
                                }
                                FUN_009bf470(0, 0);
                            }
                            if (!noMove)
                                byte90 = 0;
                        }
                        else
                        {
                            if (!noMove)
                                SetLocationOnReference(*(NiPoint3*)&owner->unk04);
                            FUN_009bf470(0, 0);
                            Projectile_SetFlag(4, 1);
                            Unk_A9();
                            bhkWorld_UpdatePosition(p60, 1, 1);
                            int tcc4;
                            bhkWorld_SetGroup(p28, p34->FUN_00931ed0(&tcc4)->CFilter_GetGroup(), 1, 1);
                            bhkWorld_SetMotion(p28, 1, 1, 1, 1);
                            bhkWorld_EnableCollision(p28, 1, 1, 0);
                            V vcd0;
                            {
                                V vcdc;
                                V vce8;
                                ((VRes*)((V*)Projectile_GetMovementDirection((NiPoint3*)&vce8))->ApplyScaled(&vcdc, Projectile_GetSpeed((NiPoint3*)&vcd0, 2.0f)))
                                    ->ProcessAndReturnValue_0053d280();
                            }
                            TESHavokUtilities_AddVelocity(p28, &vcd0, 1);
                            if (DAT_011f2250.BGSSaveFormBuffer_GetForm() == (Obj*)this)
                                DAT_011f2250.SetValue(0);
                        }
                    }
                    return;
                }
            }
            Projectile_Kill();
            return;
        }
    }
    uiImpactResult = 4;
    HandleMissileImpact();
}

