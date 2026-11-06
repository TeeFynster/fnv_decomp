
// src/fallout/ai/combat/projectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/projectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/projectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/projectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../../../include/NiPoint3.h"
#include "../../../../include/hkVector4.h"

#include <xmmintrin.h>
class NiPoint3PB
{
  public:
    NiPoint3PB operator-(const NiPoint3PB& kPt) const;
    float Length() const;
    float x;
    float y;
    float z;
};

class NiColorAPB
{
  public:
    NiColorAPB(float fR, float fG, float fB, float fA);
    float r;
    float g;
    float b;
    float a;
};

class hkSimdRealPB
{
  public:
    hkSimdRealPB(float fValue);
    __m128 m_vValue;
};

class NodePB
{
  public:
    const NiPoint3PB& GetWorldTranslate();
};

class TimerPB
{
  public:
    float GetMovementDelta();
};
extern TimerPB g_kTimerPB;

class VATSPB
{
  public:
    int GetMode();
    float GetPlayerMult();
    float GetTargetMult();
};
extern VATSPB g_kVATSPB;

class SettingPB
{
  public:
    float& GetValue();
};
extern SettingPB g_kDebugTimePB;
extern bool g_bShowDebugPB;

class AVOwnerPB
{
  public:
    virtual void v0();
    virtual void v1();
    virtual int GetActorValueInt(int iAV);
};

class BaseFormPB
{
  public:
    float GetAnimationSpeed();
};

class CollisionPB
{
  public:
    void* GetWorldObject();
};

class EntityPB
{
  public:
    void* GetRigidBody();
};

class BodyPB
{
  public:
    BodyPB* GetMotion();
    void ApplyImpulse(float fTimeSinceScaleStart, const hkVector4& kImpulse);
};

class HavokWorldPB
{
  public:
    const void* GetGravity();
};

class CellPB
{
  public:
    HavokWorldPB* GetWorld();
};

class WorldObjectPB
{
  public:
    EntityPB* GetEntity();
};

class TrackerPB
{
  public:
    void Add(void* pvShooter, void* pvProjectile);
};
extern TrackerPB g_kTrackerPB;

class TimerObjPB
{
  public:
    void Start(int iValue);
};

class SpherePB
{
  public:
    void Init();
    void GetTransformScale(const NiPoint3PB& kPos);
};

class DebugListPB
{
  public:
    void Add(SpherePB* pkSphere, float fTime);
};
extern DebugListPB* g_pkDebugListPB;

class RefPB
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual NodePB* Get3D();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual void r07d();
    virtual void r07e();
    virtual void r07f();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r08a();
    virtual void r08b();
    virtual void r08c();
    virtual void r08d();
    virtual void r08e();
    virtual void r08f();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r09a();
    virtual void r09b();
    virtual void r09c();
    virtual void r09d();
    virtual void r09e();
    virtual void r09f();
    virtual void r0a0();
    virtual void r0a1();
    virtual void r0a2();
    virtual void r0a3();
    virtual void r0a4();
    virtual void r0a5();
    virtual void r0a6();
    virtual void r0a7();
    virtual void r0a8();
    virtual void r0a9();
    virtual void r0aa();
    virtual void r0ab();
    virtual void r0ac();
    virtual void r0ad();
    virtual void r0ae();
    virtual void r0af();
    virtual void r0b0();
    virtual void r0b1();
    virtual void r0b2();
    virtual void r0b3();
    virtual void r0b4();
    virtual void r0b5();
    virtual void r0b6();
    virtual void r0b7();
    virtual void r0b8();
    virtual void r0b9();
    virtual void r0ba();
    virtual void r0bb();
    virtual void r0bc();
    virtual void r0bd();
    virtual void r0be();
    virtual void r0bf();
    virtual void r0c0();
    virtual int GetState();
    virtual void r0c2();
    virtual void r0c3();
    virtual void UpdateMotion(float fTimeSinceScaleStart);
    bool HasFlag(unsigned int uiFlag);
    RefPB* GetShooter();
    BaseFormPB* GetBaseForm();
    CellPB* GetParentCell();
    void UpdateTimers();
    char m_acPad[0xa4 - 4];
    AVOwnerPB m_kAVOwner;
};
extern RefPB* g_pkPlayerPB;
extern RefPB* g_pkPlayerTeammatePB;

CollisionPB* __cdecl FUN_004a8b00(NodePB* pkNode);
BodyPB* __cdecl FUN_004b5a80(void* pvEntity);
void __cdecl FUN_00b6bb30(NodePB* pkNode, float fAlpha);
float __cdecl FUN_00408840(float fValue);
SpherePB* __cdecl CreateOctahedron(float fRadius, const NiColorAPB& kColor, int iFlags);

class ProjPB : public RefPB
{
  public:
    void FUN_009becc0(float fUnused);
    char m_acPad2[0xd8 - 0xa8];
    float m_fXValue;
    float m_fPadDC;
    float m_fAlpha;
    char m_acPad3[0x118 - 0xe4];
    bool m_bTracked;
    char m_acPad4[0x128 - 0x119];
    TimerObjPB m_kTimer;
    char m_acPad5[0x148 - 0x129];
    bool m_bNearPlayer;
    float m_fNearDistance;
};

// @fnv 0x009becc0
void ProjPB::FUN_009becc0(float fUnused)
{
    float fTimeSinceScaleStart = g_kTimerPB.GetMovementDelta();
    if (g_kVATSPB.GetMode() == 4 && !HasFlag(4))
    {
        if (GetShooter() == g_pkPlayerPB)
            fTimeSinceScaleStart *= g_kVATSPB.GetPlayerMult();
        else if (GetShooter() == g_pkPlayerTeammatePB)
            fTimeSinceScaleStart *= g_kVATSPB.GetTargetMult();
    }
    if (HasFlag(0x20))
    {
        float fSpeed = GetBaseForm()->GetAnimationSpeed();
        m_fAlpha -= fTimeSinceScaleStart / fSpeed;
        if (m_fAlpha <= 0.0)
            m_fAlpha = 0.0f;
        if (Get3D())
            FUN_00b6bb30(Get3D(), m_fAlpha);
    }
    if (GetShooter() && GetShooter()->IsActor() && HasFlag(4))
    {
        RefPB* pkShooter = GetShooter();
        if (pkShooter->m_kAVOwner.GetActorValueInt(0x33) > 0 && Get3D())
        {
            NodePB* pkNode = Get3D();
            CollisionPB* pkCollision = FUN_004a8b00(pkNode);
            BodyPB* pkBody = 0;
            BodyPB* pkMotion = 0;
            pkBody = pkCollision ? FUN_004b5a80(((WorldObjectPB*)pkCollision->GetWorldObject())->GetEntity()) : 0;
            if (pkBody)
            {
                pkMotion = pkBody->GetMotion();
                HavokWorldPB* pkWorld = GetParentCell()->GetWorld();
                hkVector4 kImpulse(0.0f, 0.0f, -30.0f, 0.0f);
                kImpulse = *(const hkVector4*)pkWorld->GetGravity();
                hkSimdRealPB kScale(2.0f);
                kImpulse.FUN_00627920((const hkSimdReal&)kScale);
                pkMotion->ApplyImpulse(fTimeSinceScaleStart, kImpulse);
            }
        }
    }
    if (GetState() != 5)
        UpdateMotion(fTimeSinceScaleStart);
    m_fXValue += fTimeSinceScaleStart;
    UpdateTimers();
    if (!m_bTracked)
    {
        RefPB* pkShooter = 0;
        if (GetShooter() && GetShooter()->IsActor())
            pkShooter = GetShooter();
        g_kTrackerPB.Add(pkShooter, this);
        m_bTracked = true;
    }
    if (!m_bNearPlayer && !HasFlag(1) && Get3D() && g_pkPlayerPB)
    {
        NiPoint3PB kDiff = g_pkPlayerPB->Get3D()->GetWorldTranslate() - Get3D()->GetWorldTranslate();
        if (FUN_00408840(kDiff.Length()) <= m_fNearDistance)
        {
            m_kTimer.Start(1);
            m_bNearPlayer = true;
            if (g_bShowDebugPB)
            {
                NiColorAPB kColor(0.0f, 0.0f, 1.0f, 0.6f);
                SpherePB* pkSphere = CreateOctahedron(5.0f, kColor, 1);
                pkSphere->Init();
                pkSphere->GetTransformScale(Get3D()->GetWorldTranslate());
                g_pkDebugListPB->Add(pkSphere, g_kDebugTimePB.GetValue());
            }
        }
    }
}

namespace fnv_009c0090 {
struct S9c_Pt : NiPoint3
{
};
struct S9c_Room
{
    int FUN_0048cee0();
};
struct S9c_Base
{
    bool HasFlag8();
    S9c_Room* FUN_006ab360();
};
struct S9c_Geom;
struct S9c_Obj
{
    S9c_Geom* FUN_006286d0();
};
struct S9c_Target
{
    S9c_Obj* FUN_00541c80();
};
struct S9c_Ref
{
    S9c_Target* FUN_004543c0();
};
struct S9c_Pos
{
    NiPoint3 FUN_00439ef0(const NiPoint3& rhs) const;
    NiPoint3 FUN_00439e90(const NiPoint3& rhs) const;
};
struct S9c_Vec
{
    __m128 m_vComponents;
};
struct S9c_Ray
{
    S9c_Vec from;
    S9c_Vec to;
    S9c_Ray();
};
struct S9c_Rec
{
    int hdr;
    struct S9c_Coll* obj;
};
struct S9c_Coll
{
    void* FUN_009b2c90();
};
struct __declspec(align(16)) S9c_Hits
{
    S9c_Vec v0;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    S9c_Hits(bool b);
    ~S9c_Hits();
    int FUN_00726070();
    S9c_Rec* FUN_00626660(int);
};
struct S9c_Geom
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void Query(S9c_Ray*, S9c_Hits*);
};
struct S9c_Layer
{
    void* p;
    int FUN_0043b4d0();
};
struct S9c_World
{
    S9c_Layer FUN_0043b4f0();
};
struct S9c_Form
{
    void* FUN_005d43c0();
};
void* __cdecl FUN_004b5820(void*);
S9c_Form* __cdecl FUN_0056f930(void*);
void* __cdecl FUN_004b5950(void*);
S9c_World* __cdecl FUN_004b5a80(void*);
void __cdecl MarkBaseExtraListScriptEvent(void*, void*, unsigned int);
extern NiPoint3 DAT_011a9490;
extern void* DAT_011ca288;
S9c_Pt __cdecl FUN_004a3760(float, const NiPoint3*);
void __cdecl FUN_004a3e00(S9c_Vec*, const NiPoint3*);

struct S9c_Actor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
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
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual S9c_Pos* GetVirtualPosition();
    S9c_Base* FUN_004181e0();
    S9c_Ref* FUN_008d6f30();
    bool FUN_009c0090();
};
// @fnv 0x009c0090
bool S9c_Actor::FUN_009c0090()
{
    bool found = false;
    if (FUN_004181e0()->HasFlag8() && FUN_004181e0()->FUN_006ab360()->FUN_0048cee0())
    {
        S9c_Target* target = FUN_008d6f30() ? FUN_008d6f30()->FUN_004543c0() : 0;
        if (!target)
            return found;
        S9c_Obj* obj = target->FUN_00541c80();
        S9c_Geom* geom = obj ? obj->FUN_006286d0() : 0;
        NiPoint3 from = GetVirtualPosition()->FUN_00439ef0(FUN_004a3760(1.0f, &DAT_011a9490));
        NiPoint3 to = GetVirtualPosition()->FUN_00439e90(FUN_004a3760(1.0f, &DAT_011a9490));
        S9c_Ray ray;
        FUN_004a3e00(&ray.from, &from);
        FUN_004a3e00(&ray.to, &to);
        S9c_Hits hits(false);
        geom->Query(&ray, &hits);
        for (int i = 0; !found && i < hits.FUN_00726070(); i++)
        {
            S9c_Rec* rec = hits.FUN_00626660(i);
            S9c_Coll* coll = rec->obj;
            void* item = coll->FUN_009b2c90();
            void* a = FUN_004b5820(item);
            S9c_Form* form = FUN_0056f930(a);
            void* c = FUN_004b5950(item);
            S9c_World* world = c ? FUN_004b5a80(c) : 0;
            if (world && form)
            {
                if (world->FUN_0043b4f0().FUN_0043b4d0() == 23 || world->FUN_0043b4f0().FUN_0043b4d0() == 24)
                {
                    found = true;
                    MarkBaseExtraListScriptEvent(this, form->FUN_005d43c0(), 0x80);
                    MarkBaseExtraListScriptEvent(DAT_011ca288, form->FUN_005d43c0(), 0x100);
                }
            }
        }
    }
    return found;
}
}  // namespace fnv_009c0090

class NiPoint3P9
{
  public:
    NiPoint3P9();
    NiPoint3P9 operator+(const NiPoint3P9& kPt) const;
    NiPoint3P9 operator-(const NiPoint3P9& kPt) const;
    NiPoint3P9 operator*(float fScale) const;
    NiPoint3P9& operator*=(float fScale);
    NiPoint3P9& operator/=(float fScale);
    void Unitize();
    float x;
    float y;
    float z;
};

class NiMatrix3P9
{
  public:
    NiMatrix3P9();
    void SetZRotation(float fAngleDifference);
    void SetXRotation(float fAngleDifference);
    NiMatrix3P9 operator*(const NiMatrix3P9& kOther) const;
    void GetCol(unsigned int uiCol, NiPoint3P9& kCol) const;
    float m_afEntries[3][3];
};

class NiColorAP9
{
  public:
    NiColorAP9(float fR, float fG, float fB, float fA);
    float r;
    float g;
    float b;
    float a;
};

class HitResultsP9
{
  public:
    HitResultsP9();
    ~HitResultsP9();
    __m128 m_akData[50];
};

class PickFlagsP9
{
  public:
    PickFlagsP9(int iValue);
    void SetType(int iType);
    void SetTarget(void* pvTarget);
    int m_iValue;
};

class PickQueryP9
{
  public:
    PickQueryP9();
    void SetFilter(void* pvFilter);
    void SetFlags(PickFlagsP9 kFlags);
    void SetOrigin(const NiPoint3P9& akStart);
    void SetDirection(const NiPoint3P9& kWorldPosition);
    void SetResults(HitResultsP9* pkResults);
    bool HasHit();
    __m128 m_akData[11];
};

class HandleP9
{
  public:
    void* Get();
    unsigned int m_uiHandle;
};

class ProjP9
{
  public:
    PickFlagsP9 GetFlags();
};

class ShooterP9
{
  public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s00a();
    virtual void s00b();
    virtual void s00c();
    virtual void s00d();
    virtual void s00e();
    virtual void s00f();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s01a();
    virtual void s01b();
    virtual void s01c();
    virtual void s01d();
    virtual void s01e();
    virtual void s01f();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s02a();
    virtual void s02b();
    virtual void s02c();
    virtual void s02d();
    virtual void s02e();
    virtual void s02f();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037();
    virtual void s038();
    virtual void s039();
    virtual void s03a();
    virtual void s03b();
    virtual void s03c();
    virtual void s03d();
    virtual void s03e();
    virtual void s03f();
    virtual bool IsActor();
    HandleP9 GetHandle();
};

class CollHolderP9
{
  public:
    void* GetFilter();
};

class CollSrcP9
{
  public:
    CollHolderP9* GetHolder();
};

struct BroadphaseP9
{
    char m_acPad[0x310];
    __m128 m_kMin;
    __m128 m_kMax;
};

class WorldP9
{
  public:
    virtual void w000();
    virtual void w001();
    virtual void w002();
    virtual void w003();
    virtual void w004();
    virtual void w005();
    virtual void w006();
    virtual void w007();
    virtual void w008();
    virtual void w009();
    virtual void w00a();
    virtual void w00b();
    virtual void w00c();
    virtual void w00d();
    virtual void w00e();
    virtual void w00f();
    virtual void w010();
    virtual void w011();
    virtual void w012();
    virtual void w013();
    virtual void w014();
    virtual void w015();
    virtual void w016();
    virtual void w017();
    virtual void w018();
    virtual void w019();
    virtual void w01a();
    virtual void w01b();
    virtual void w01c();
    virtual void w01d();
    virtual void w01e();
    virtual void w01f();
    virtual void w020();
    virtual void w021();
    virtual void w022();
    virtual void w023();
    virtual void w024();
    virtual void w025();
    virtual void w026();
    virtual void w027();
    virtual void w028();
    virtual void w029();
    virtual void w02a();
    virtual void w02b();
    virtual void w02c();
    virtual void w02d();
    virtual void w02e();
    virtual void w02f();
    virtual void w030();
    virtual void w031();
    virtual bool Pick(PickQueryP9& kQuery);
    void GetNavMeshData(NiPoint3P9& kTargetCenter);
    BroadphaseP9* GetBroadphase();
};

class CellP9
{
  public:
    WorldP9* GetWorld();
};

class NameP9
{
  public:
    const char* c_str();
};

class BaseFormP9
{
  public:
    virtual void b000();
    virtual void b001();
    virtual void b002();
    virtual void b003();
    virtual void b004();
    virtual void b005();
    virtual void b006();
    virtual void b007();
    virtual void b008();
    virtual void b009();
    virtual void b00a();
    virtual void b00b();
    virtual void b00c();
    virtual void b00d();
    virtual void b00e();
    virtual void b00f();
    virtual void b010();
    virtual void b011();
    virtual void b012();
    virtual void b013();
    virtual void b014();
    virtual void b015();
    virtual void b016();
    virtual void b017();
    virtual void b018();
    virtual void b019();
    virtual void b01a();
    virtual void b01b();
    virtual void b01c();
    virtual void b01d();
    virtual void b01e();
    virtual void b01f();
    virtual void b020();
    virtual void b021();
    virtual void b022();
    virtual void b023();
    virtual void b024();
    virtual void b025();
    virtual void b026();
    virtual void b027();
    virtual void b028();
    virtual void b029();
    virtual void b02a();
    virtual void b02b();
    virtual void b02c();
    virtual void b02d();
    virtual void b02e();
    virtual void b02f();
    virtual void b030();
    virtual void b031();
    virtual void b032();
    virtual void b033();
    virtual void b034();
    virtual void b035();
    virtual void b036();
    virtual void b037();
    virtual void b038();
    virtual void b039();
    virtual void b03a();
    virtual void b03b();
    virtual void b03c();
    virtual void b03d();
    virtual void b03e();
    virtual void b03f();
    virtual void b040();
    virtual void b041();
    virtual void b042();
    virtual void b043();
    virtual void b044();
    virtual void b045();
    virtual void b046();
    virtual void b047();
    virtual void b048();
    virtual void b049();
    virtual void b04a();
    virtual void b04b();
    virtual const char* GetFullName();
    int HasFullName();
    char m_acPad[0x30 - 4];
    NameP9 m_kName;
};

class SettingP9
{
  public:
    float& GetValue();
    bool& GetBool();
};
extern SettingP9 g_kShowRaysP9;
extern SettingP9 g_kRayTimeP9;

class DebugP9
{
  public:
    void AddLine(void* pvLine, float fTime);
};
extern DebugP9* g_pkDebugP9;

void __cdecl FUN_00458620(NiPoint3P9& kOut, const __m128& kIn);
float __cdecl FUN_00408840(float fValue);
float __cdecl FUN_00404010(float fA, float fB);
void __cdecl FUN_005b5e40(const char* pcFormat, ...);
bool __cdecl FUN_00888960();
void __cdecl FUN_00c66230(bool bValue);
void* __cdecl FUN_005dbe10();
void* __cdecl FUN_004b3890(const NiPoint3P9& kStart, const NiColorAP9& kStartColor, const NiPoint3P9& kEnd,
                           const NiColorAP9& kEndColor, int iFlags);

class PlayerP9
{
  public:
    CellP9* GetParentCell();
};
extern PlayerP9* g_pkPlayerP9;

class RefP9
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual void r040();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual const NiPoint3P9* GetPos();
    virtual void r07e();
    virtual void r07f();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r08a();
    virtual void r08b();
    virtual void r08c();
    virtual void r08d();
    virtual void r08e();
    virtual void r08f();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r09a();
    virtual void r09b();
    virtual void r09c();
    virtual void r09d();
    virtual void r09e();
    virtual void r09f();
    virtual void r0a0();
    virtual void r0a1();
    virtual void r0a2();
    virtual void r0a3();
    virtual void r0a4();
    virtual void r0a5();
    virtual void r0a6();
    virtual void r0a7();
    virtual void r0a8();
    virtual void r0a9();
    virtual void r0aa();
    virtual void r0ab();
    virtual void r0ac();
    virtual void r0ad();
    virtual void r0ae();
    virtual float GetAngle(int iAxis);
    CellP9* GetParentCell();
    ProjP9* GetProjectileData();
    ShooterP9* GetShooter();
    float GetAnimationSpeed();
    float GetGravity();
    float GetRange();
    BaseFormP9* GetBaseForm();
    bool CheckHits(PickQueryP9& kQuery, float& fDistance);
    void OnHit();
    bool FUN_009c03f0();
    char m_acPad[0x11c - 4];
    CollSrcP9 m_kCollSrc;
};
int __cdecl FUN_009c0d80(PickQueryP9& kQuery, RefP9* pkRef, BaseFormP9* pkBase, int iA, int iB, float fDistance);

// @fnv 0x009c03f0
bool RefP9::FUN_009c03f0()
{
    if (!GetParentCell() || !GetParentCell()->GetWorld())
        return false;
    WorldP9* pkWorld = GetParentCell()->GetWorld();
    PickQueryP9 kQuery;
    NiPoint3P9 kPos;
    NiPoint3P9 kWorldPosition;
    kPos = *GetPos();
    NiMatrix3P9 kRotate;
    kRotate.SetZRotation(GetAngle(0));
    NiMatrix3P9 kTilt;
    kTilt.SetXRotation(GetAnimationSpeed());
    kRotate = kRotate * kTilt;
    kRotate.GetCol(1, kWorldPosition);
    kWorldPosition.Unitize();
    PickFlagsP9 kFlags(0);
    if (GetProjectileData())
    {
        kFlags = GetProjectileData()->GetFlags();
    }
    else
    {
        kFlags.SetType(6);
        if (GetShooter() && GetShooter()->IsActor())
            kFlags.SetTarget(GetShooter()->GetHandle().Get());
        else
            kFlags.SetTarget(FUN_005dbe10());
    }
    if (m_kCollSrc.GetHolder() && m_kCollSrc.GetHolder()->GetFilter())
        kQuery.SetFilter(m_kCollSrc.GetHolder()->GetFilter());
    NiPoint3P9 kRay = kWorldPosition * (GetRange() - GetGravity());
    NiPoint3P9 kTargetCenter;
    pkWorld->GetNavMeshData(kTargetCenter);
    BroadphaseP9* pkBroadphase = pkWorld->GetBroadphase();
    NiPoint3P9 kMaxPoint;
    FUN_00458620(kMaxPoint, pkBroadphase->m_kMax);
    NiPoint3P9 kMinBoundsCur;
    FUN_00458620(kMinBoundsCur, pkBroadphase->m_kMin);
    NiPoint3P9 kExtent = kMaxPoint - kMinBoundsCur;
    kExtent /= 2.0f;
    NiPoint3P9 kRel = kPos - kTargetCenter;
    float fRatio = FUN_00404010(FUN_00408840(kRel.x / kExtent.x),
                                FUN_00404010(FUN_00408840(kRel.y / kExtent.y), FUN_00408840(kRel.z / kExtent.z)));
    if (fRatio > 1.0)
    {
        FUN_005b5e40("COMBAT: Projectile %s is spawning outside of the broadphase.",
                     GetBaseForm()->HasFullName() ? GetBaseForm()->GetFullName() : GetBaseForm()->m_kName.c_str());
    }
    else
    {
        NiPoint3P9 kEnd = kPos + kRay;
        NiPoint3P9 kEndRel = kEnd - kTargetCenter;
        float fEndRatio =
            FUN_00404010(FUN_00408840(kEndRel.x / kExtent.x),
                         FUN_00404010(FUN_00408840(kEndRel.y / kExtent.y), FUN_00408840(kEndRel.z / kExtent.z)));
        if (fEndRatio > 1.0)
        {
            if (kPos.x + kRay.x > kMaxPoint.x)
                kRay *= (kMaxPoint.x - kPos.x) / kRay.x;
            if (kPos.y + kRay.y > kMaxPoint.y)
                kRay *= (kMaxPoint.y - kPos.y) / kRay.y;
            if (kPos.z + kRay.z > kMaxPoint.z)
                kRay *= (kMaxPoint.z - kPos.z) / kRay.z;
            if (kPos.x + kRay.x < kMinBoundsCur.x)
                kRay *= (kMinBoundsCur.x - kPos.x) / kRay.x;
            if (kPos.y + kRay.y < kMinBoundsCur.y)
                kRay *= (kMinBoundsCur.y - kPos.y) / kRay.y;
            if (kPos.z + kRay.z < kMinBoundsCur.z)
                kRay *= (kMinBoundsCur.z - kPos.z) / kRay.z;
        }
    }
    kQuery.SetFlags(kFlags);
    kQuery.SetOrigin(kPos);
    kQuery.SetDirection(kRay);
    HitResultsP9 kResults;
    kQuery.SetResults(&kResults);
    bool bOld = FUN_00888960();
    FUN_00c66230(true);
    bool bHitDetected = g_pkPlayerP9->GetParentCell()->GetWorld()->Pick(kQuery);
    FUN_00c66230(bOld);
    float fDistance = 3.402823466e+38F;
    bHitDetected = bHitDetected | CheckHits(kQuery, fDistance);
    if (bHitDetected)
        bHitDetected = FUN_009c0d80(kQuery, this, GetBaseForm(), 0, 1, fDistance) != 0;
    if (g_kShowRaysP9.GetBool())
    {
        NiColorAP9 kColor = kQuery.HasHit() ? NiColorAP9(1.0f, 0.0f, 0.0f, 1.0f) : NiColorAP9(1.0f, 1.0f, 0.0f, 1.0f);
        void* pvLine = FUN_004b3890(kPos, kColor, kPos + kRay, kColor, 1);
        g_pkDebugP9->AddLine(pvLine, g_kRayTimeP9.GetValue());
    }
    if (kQuery.HasHit())
        OnHit();
    return bHitDetected;
}

class FUN_005dbf20
{
  public:
    FUN_005dbf20(float fValue);
    __m128 m_vValue;
};

hkVector4& FUN_004a3e00(hkVector4& kOut, const NiPoint3& kIn);

class ImpulseBody
{
  public:
    void ApplyVirtualCall(const hkVector4& kImpulse, const hkVector4& kPoint);
};

class ImpulseLock
{
  public:
    void FUN_00483710();
};

class ImpulseRigidBody
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v37();
    virtual ImpulseLock* GetLock();  // +0x98

    int FUN_00517630();  // motion type
    ImpulseBody* FUN_004ae750();
};

void* FUN_004b59f0(const void* pvObject);
void* FUN_004b5a80(const void* pvObject);

class ImpulseActorBase
{
  public:
    float FUN_00644930();
};

float FUN_0062b520(float fBase, ImpulseRigidBody* pkBody, int iMode);

class ImpulseSource
{
  public:
    ImpulseActorBase* FUN_004181e0();
    void FUN_009c2e80(NiPoint3 kPoint, NiPoint3 kDirection, void* pvTarget);
};

// @fnv 0x009c2e80
void ImpulseSource::FUN_009c2e80(NiPoint3 kPoint, NiPoint3 kDirection, void* pvTarget)
{
    if (!pvTarget)
        return;
    ImpulseRigidBody* pkBody = (ImpulseRigidBody*)FUN_004b5a80(FUN_004b59f0(pvTarget));
    ImpulseLock* pkLock = pkBody ? pkBody->GetLock() : 0;
    if (pkLock)
    {
        if (pkBody->FUN_00517630() < 4)
        {
            float fForce = FUN_004181e0()->FUN_00644930();
            fForce = FUN_0062b520(fForce, pkBody, 1);
            if (fForce != 0.0)
            {
                hkVector4 kImpulse;
                FUN_004a3e00(kImpulse, kDirection);
                hkVector4 kPosition;
                FUN_004a3e00(kPosition, kPoint);
                if (kImpulse.FUN_00630b40().FUN_004586d0() > 0.0)
                    kImpulse.FUN_0062aea0();
                FUN_005dbf20 kScale(fForce);
                kImpulse.FUN_00627920((const hkSimdReal&)kScale);
                pkLock->FUN_00483710();
                pkBody->FUN_004ae750()->ApplyVirtualCall(kImpulse, kPosition);
                pkLock->FUN_00483710();
            }
        }
    }
}

class hkTransform9C
{
  public:
    hkTransform9C();
    hkTransform9C(const hkTransform9C& kOther);
    void Set(const void* pvRotation, const void* pvTranslation);
    void SetMul(const hkTransform9C& kA, const hkTransform9C& kB);
    __m128 m_akCols[4];
};

class hkAabb9C
{
  public:
    hkAabb9C();
    hkVector4 m_kMin;
    hkVector4 m_kMax;
    __m128 m_kExtra;
};

class ResultFlag9C
{
  public:
    ResultFlag9C();
    bool IsSet();
    char m_cValue;
};

class hkAabbOut9C
{
  public:
    hkAabbOut9C();
    ResultFlag9C GetResult();
    __m128 m_akData[5];
};

class Flags9C
{
  public:
    Flags9C();
    bool IsActive();
    int GetMotionType();
    int m_iValue;
};

class Motion9C
{
  public:
    ResultFlag9C CalcAabb(const hkAabb9C& kAabb, hkAabbOut9C& kOut);
    void* GetEntry(hkAabbOut9C& kOut);
};

class RigidBody9C
{
  public:
    Motion9C* GetMotion();
};

class WorldObject9C
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void GetTransform(hkTransform9C& kXform);
    RigidBody9C* GetRigidBody();
    Flags9C GetFlags();
    bool IsFixed();
    Motion9C* GetMotion();
};

class Phantom9C
{
  public:
    const void* GetRotation();
    const void* GetTranslation();
};

class Listener9C
{
  public:
    virtual void Add(void* pvEntry);
    void Update();
};

class World9C
{
  public:
    const void* GetMin();
    const void* GetMax();
    Listener9C* GetListener();
};

class CollisionObject9C
{
  public:
    WorldObject9C* GetWorldObject();
};

class BlendCollisionObject9C : public CollisionObject9C
{
  public:
    float GetBlend();
};

class NiRTTI9C
{
  public:
    const char* m_pcName;
};
extern NiRTTI9C g_kBlendCollisionRTTI9C;
extern NiRTTI9C g_kPhantomRTTI9C;

class NiNode9C;
class NiAVObject9C
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode9C* IsSceneNode();
    const void* GetWorldTransform();
};

class NiNode9C
{
  public:
    unsigned int GetArrayCount();
    NiAVObject9C* GetAt(unsigned int uiIndex);
};

CollisionObject9C* __cdecl FUN_0043b610(NiAVObject9C* pkObject);
bool __cdecl FUN_0043b300(NiRTTI9C* pkRTTI, void* pvObject);
void __cdecl FUN_0056df80(hkTransform9C& kOut, const void* pvTransform);

// @fnv 0x009c5ba0
bool __cdecl FUN_009c5ba0(World9C* pkWorld, NiAVObject9C* pkObject, bool bCheckMotion, bool bUpdate)
{
    bool bStateChanged = false;
    if (pkObject)
    {
        CollisionObject9C* pkCollision = FUN_0043b610(pkObject);
        if (pkCollision)
        {
            WorldObject9C* pkWorldObject = pkCollision->GetWorldObject();
            RigidBody9C* pkBody = pkWorldObject ? pkWorldObject->GetRigidBody() : 0;
            if (pkBody && pkWorldObject->GetFlags().IsActive() &&
                (!bCheckMotion || pkWorldObject->GetFlags().GetMotionType() != 1))
            {
                hkTransform9C kXform;
                if (FUN_0043b300(&g_kBlendCollisionRTTI9C, pkCollision))
                {
                    BlendCollisionObject9C* pkBlend = (BlendCollisionObject9C*)pkCollision;
                    if (!pkWorldObject->IsFixed() || pkBlend->GetBlend() == 1.0)
                    {
                        FUN_0056df80(kXform, pkObject->GetWorldTransform());
                        if (FUN_0043b300(&g_kPhantomRTTI9C, pkWorldObject))
                        {
                            Phantom9C* pkPhantom = (Phantom9C*)pkWorldObject;
                            hkTransform9C kLocal;
                            hkTransform9C kWorld(kXform);
                            kLocal.Set(pkPhantom->GetTranslation(), pkPhantom->GetRotation());
                            kXform.SetMul(kWorld, kLocal);
                        }
                    }
                    else
                    {
                        pkWorldObject->GetTransform(kXform);
                    }
                }
                else
                {
                    pkWorldObject->GetTransform(kXform);
                }
                hkAabb9C kAabb;
                hkAabbOut9C kOut;
                kAabb.m_kMin.SetTransformedPosition((const hkTransform&)kXform, *(const hkVector4*)pkWorld->GetMin());
                kAabb.m_kMax.SetTransformedPosition((const hkTransform&)kXform, *(const hkVector4*)pkWorld->GetMax());
                pkBody->GetMotion()->CalcAabb(kAabb, kOut);
                if (kOut.GetResult().IsSet())
                {
                    Listener9C* pkListener = pkWorld->GetListener();
                    pkListener->Add(pkWorldObject->GetMotion()->GetEntry(kOut));
                    bStateChanged = true;
                }
            }
        }
        NiNode9C* pkNode = pkObject->IsSceneNode();
        if (pkNode)
        {
            for (unsigned int i = 0; i < pkNode->GetArrayCount(); i++)
            {
                NiAVObject9C* pkChild = pkNode->GetAt(i);
                bStateChanged = bStateChanged | FUN_009c5ba0(pkWorld, pkChild, bCheckMotion, false);
            }
        }
    }
    if (bUpdate)
        pkWorld->GetListener()->Update();
    return bStateChanged;
}
