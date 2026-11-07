#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BeamProjectile.h"
#include "../../../../include/FlameProjectile.h"
#include "../../../../include/NiPoint3.h"

// src/fallout/ai/combat/flameprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/ai/combat/flameprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/flameprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/flameprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/flameprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/flameprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Flt
{
    operator unsigned int() const;
};

#include <xmmintrin.h>
struct FilterKey
{
    unsigned int m_uiCurrentValue;
    FilterKey();
};
struct NiMatrix33
{
    float rows[9];
    void FUN_006815c0();
    void FUN_004a0c90(float angle);
    void FUN_00524ac0(float angle);
    NiMatrix33* FUN_0043f8d0(NiMatrix33* result, NiMatrix33* rhs);
    void NiMatrix3_GetCol(int enabled, NiPoint3* output);
};
struct __declspec(align(16)) VisualState
{
    __m128 m_quad000;
    unsigned unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    unsigned unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c;
    unsigned unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    unsigned unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    unsigned unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac;
    void FUN_004a3c20();
    void BGSTerminal_SetPassword(void* state);
    void bhkPickData_SetFilter(unsigned int state);
    void bhkPickData_SetFrom(NiPoint3* point);
    void bhkPickData_SetLength(const NiPoint3& point);
    void bhkPickData_SetAllCollector(void* result);
    bool bhkPickData_GetPickFailed();
};
struct Handle
{
    unsigned int id;
    void FUN_008c71b0(int initial);
    void CFilter_SetLayer(int kind);
    void CFilter_SetGroup(const FilterKey& kKey);
};
struct Controller
{
    void* FUN_0044ddc0();
};
struct Source
{
    Controller* FUN_009b3cb0();
};
struct AttachedObject
{
    unsigned int* bhkCharacterController_GetCollisionFilter(unsigned int* out);
};
struct BoundForm;
struct FireObject
{
    virtual void fo000();
    virtual void fo004();
    virtual void fo008();
    virtual void fo00c();
    virtual void fo010();
    virtual void fo014();
    virtual void fo018();
    virtual void fo01c();
    virtual void fo020();
    virtual void fo024();
    virtual void fo028();
    virtual void fo02c();
    virtual void fo030();
    virtual void fo034();
    virtual void fo038();
    virtual void fo03c();
    virtual void fo040();
    virtual void fo044();
    virtual void fo048();
    virtual void fo04c();
    virtual void fo050();
    virtual void fo054();
    virtual void fo058();
    virtual void fo05c();
    virtual void fo060();
    virtual void fo064();
    virtual void fo068();
    virtual void fo06c();
    virtual void fo070();
    virtual void fo074();
    virtual void fo078();
    virtual void fo07c();
    virtual void fo080();
    virtual void fo084();
    virtual void fo088();
    virtual void fo08c();
    virtual void fo090();
    virtual void fo094();
    virtual void fo098();
    virtual void fo09c();
    virtual void fo0a0();
    virtual void fo0a4();
    virtual void fo0a8();
    virtual void fo0ac();
    virtual void fo0b0();
    virtual void fo0b4();
    virtual void fo0b8();
    virtual void fo0bc();
    virtual void fo0c0();
    virtual void fo0c4();
    virtual void fo0c8();
    virtual void fo0cc();
    virtual void fo0d0();
    virtual void fo0d4();
    virtual void fo0d8();
    virtual void fo0dc();
    virtual void fo0e0();
    virtual void fo0e4();
    virtual void fo0e8();
    virtual void fo0ec();
    virtual void fo0f0();
    virtual void fo0f4();
    virtual void fo0f8();
    virtual void fo0fc();
    virtual bool IsEnabled();
    BoundForm* FUN_00931ed0();
};
struct BoundForm
{
    FilterKey CFilter_GetGroup();
};
struct ActorRef
{
    BoundForm* TESObjectCELL_GetbhkWorld();
};
struct Tester
{
    virtual void t000();
    virtual void t004();
    virtual void t008();
    virtual void t00c();
    virtual void t010();
    virtual void t014();
    virtual void t018();
    virtual void t01c();
    virtual void t020();
    virtual void t024();
    virtual void t028();
    virtual void t02c();
    virtual void t030();
    virtual void t034();
    virtual void t038();
    virtual void t03c();
    virtual void t040();
    virtual void t044();
    virtual void t048();
    virtual void t04c();
    virtual void t050();
    virtual void t054();
    virtual void t058();
    virtual void t05c();
    virtual void t060();
    virtual void t064();
    virtual void t068();
    virtual void t06c();
    virtual void t070();
    virtual void t074();
    virtual void t078();
    virtual void t07c();
    virtual void t080();
    virtual void t084();
    virtual void t088();
    virtual void t08c();
    virtual void t090();
    virtual void t094();
    virtual void t098();
    virtual void t09c();
    virtual void t0a0();
    virtual void t0a4();
    virtual void t0a8();
    virtual void t0ac();
    virtual void t0b0();
    virtual void t0b4();
    virtual void t0b8();
    virtual void t0bc();
    virtual void t0c0();
    virtual void t0c4();
    virtual bool Query(VisualState* state);
};
struct GameObject
{
    ActorRef* FUN_008d6f30();
};
struct FlagSetting
{
    unsigned char* FUN_00408d60();
};
struct FloatSetting
{
    float* Setting_Float_00403e20();
};
struct ImpactManager
{
    void FUN_00458e20(void* impact, float value);
};
struct ImpactData
{
    unsigned unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    unsigned unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    unsigned unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    unsigned unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    unsigned unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    unsigned unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    void FUN_004a3a70();
    void FUN_004a3bc0();
    ImpactData()
    {
        FUN_004a3a70();
    }
    ~ImpactData()
    {
        FUN_004a3bc0();
    }
};
struct Color4
{
    float r, g, b, a;
    Color4* FUN_00414430(float r, float g, float b, float a);
};
extern GameObject* DAT_011dea3c;
extern FlagSetting DAT_011f20ec;
extern FloatSetting DAT_011f210c;
extern ImpactManager* DAT_011dea10;
extern float RandomFloatTwoPi();
extern const FilterKey& bhkCollisionFilter_GetNewSystemGroup();
extern int Projectile_ProcessTargetPick(VisualState*, void*, int, int, int, float);
extern float DAT_01016970;
extern void GenerateSpherePoints(NiPoint3*, int, NiPoint3, float, float, float, float, float);
extern void* MakeLine(NiPoint3*, Color4*, NiPoint3*, Color4*, int);
struct ProjectileEffect
{
    virtual ~ProjectileEffect();
    virtual void pe004();
    virtual void pe008();
    virtual void pe00c();
    virtual void pe010();
    virtual void pe014();
    virtual void pe018();
    virtual void pe01c();
    virtual void pe020();
    virtual void pe024();
    virtual void pe028();
    virtual void pe02c();
    virtual void pe030();
    virtual void pe034();
    virtual void pe038();
    virtual void pe03c();
    virtual void pe040();
    virtual void pe044();
    virtual void pe048();
    virtual void pe04c();
    virtual void pe050();
    virtual void pe054();
    virtual void pe058();
    virtual void pe05c();
    virtual void pe060();
    virtual void pe064();
    virtual void pe068();
    virtual void pe06c();
    virtual void pe070();
    virtual void pe074();
    virtual void pe078();
    virtual void pe07c();
    virtual void pe080();
    virtual void pe084();
    virtual void pe088();
    virtual void pe08c();
    virtual void pe090();
    virtual void pe094();
    virtual void pe098();
    virtual void pe09c();
    virtual void pe0a0();
    virtual void pe0a4();
    virtual void pe0a8();
    virtual void pe0ac();
    virtual void pe0b0();
    virtual void pe0b4();
    virtual void pe0b8();
    virtual void pe0bc();
    virtual void pe0c0();
    virtual void pe0c4();
    virtual void pe0c8();
    virtual void pe0cc();
    virtual void pe0d0();
    virtual void pe0d4();
    virtual void pe0d8();
    virtual void pe0dc();
    virtual void pe0e0();
    virtual void pe0e4();
    virtual void pe0e8();
    virtual void pe0ec();
    virtual void pe0f0();
    virtual void pe0f4();
    virtual void pe0f8();
    virtual void pe0fc();
    virtual void pe100();
    virtual void pe104();
    virtual void pe108();
    virtual void pe10c();
    virtual void pe110();
    virtual void pe114();
    virtual void pe118();
    virtual void pe11c();
    virtual void pe120();
    virtual void pe124();
    virtual void pe128();
    virtual void pe12c();
    virtual void pe130();
    virtual void pe134();
    virtual void pe138();
    virtual void pe13c();
    virtual void pe140();
    virtual void pe144();
    virtual void pe148();
    virtual void pe14c();
    virtual void pe150();
    virtual void pe154();
    virtual void pe158();
    virtual void pe15c();
    virtual void pe160();
    virtual void pe164();
    virtual void pe168();
    virtual void pe16c();
    virtual void pe170();
    virtual void pe174();
    virtual void pe178();
    virtual void pe17c();
    virtual void pe180();
    virtual void pe184();
    virtual void pe188();
    virtual void pe18c();
    virtual void pe190();
    virtual void pe194();
    virtual void pe198();
    virtual void pe19c();
    virtual void pe1a0();
    virtual void pe1a4();
    virtual void pe1a8();
    virtual void pe1ac();
    virtual void pe1b0();
    virtual void pe1b4();
    virtual void pe1b8();
    virtual void pe1bc();
    virtual void pe1c0();
    virtual void pe1c4();
    virtual void pe1c8();
    virtual void pe1cc();
    virtual void pe1d0();
    virtual void pe1d4();
    virtual void pe1d8();
    virtual void pe1dc();
    virtual void pe1e0();
    virtual void pe1e4();
    virtual void pe1e8();
    virtual void pe1ec();
    virtual void pe1f0();
    virtual NiPoint3* GetFiringPosition();
    virtual void pe1f8();
    virtual void pe1fc();
    virtual void pe200();
    virtual void pe204();
    virtual void pe208();
    virtual void pe20c();
    virtual void pe210();
    virtual void pe214();
    virtual void pe218();
    virtual void pe21c();
    virtual void pe220();
    virtual void pe224();
    virtual void pe228();
    virtual void pe22c();
    virtual void pe230();
    virtual void pe234();
    virtual void pe238();
    virtual void pe23c();
    virtual void pe240();
    virtual void pe244();
    virtual void pe248();
    virtual void pe24c();
    virtual void pe250();
    virtual void pe254();
    virtual void pe258();
    virtual void pe25c();
    virtual void pe260();
    virtual void pe264();
    virtual void pe268();
    virtual void pe26c();
    virtual void pe270();
    virtual void pe274();
    virtual void pe278();
    virtual void pe27c();
    virtual void pe280();
    virtual void pe284();
    virtual void pe288();
    virtual void pe28c();
    virtual void pe290();
    virtual void pe294();
    virtual void pe298();
    virtual void pe29c();
    virtual void pe2a0();
    virtual void pe2a4();
    virtual void pe2a8();
    virtual void pe2ac();
    virtual void pe2b0();
    virtual void pe2b4();
    virtual void pe2b8();
    virtual float GetProjectileSpread(int iMode);
    ActorRef* FUN_008d6f30();
    AttachedObject* FUN_009306d0();
    FireObject* Projectile_GetShooter();
    Controller* FUN_009b3cb0();
    float FUN_00931d70();
    float GetField154();
    GameObject* FUN_004181e0();
    double GetFirstLightParameter();
    double Projectile_GetDistanceMoved();
    bool FlameProjectile_RunTargetPick();
};
struct EmitterProperties
{
    float FUN_009a7c40();
};
// @fnv 0x009b36f0
// src: XBOX_PDB 0x009b36f0
bool ProjectileEffect::FlameProjectile_RunTargetPick()
{
    if (!FUN_008d6f30() || !FUN_008d6f30()->TESObjectCELL_GetbhkWorld())
        return false;
    bool emitted = false;
    void* pWorld = FUN_008d6f30()->TESObjectCELL_GetbhkWorld();
    VisualState visual;
    visual.FUN_004a3c20();
    NiPoint3 position;
    NiPoint3 direction;
    position = *GetFiringPosition();
    NiMatrix33 rotation;
    rotation.FUN_006815c0();
    rotation.FUN_004a0c90(GetProjectileSpread(0));
    NiMatrix33 spin;
    spin.FUN_006815c0();
    spin.FUN_00524ac0(FUN_00931d70());
    NiMatrix33 result;
    rotation = *rotation.FUN_0043f8d0(&result, &spin);
    rotation.NiMatrix3_GetCol(1, &direction);
    direction.Unitize_004a0c10();
    Handle objectHandle;
    objectHandle.FUN_008c71b0(0);
    if (FUN_009306d0())
    {
        unsigned int handleId;
        objectHandle.id = *FUN_009306d0()->bhkCharacterController_GetCollisionFilter(&handleId);
    }
    else
    {
        objectHandle.CFilter_SetLayer(6);
        if (Projectile_GetShooter() && Projectile_GetShooter()->IsEnabled())
        {
            objectHandle.CFilter_SetGroup(Projectile_GetShooter()->FUN_00931ed0()->CFilter_GetGroup());
        }
        else
        {
            objectHandle.CFilter_SetGroup(bhkCollisionFilter_GetNewSystemGroup());
        }
    }
    if (FUN_009b3cb0() && FUN_009b3cb0()->FUN_0044ddc0())
        visual.BGSTerminal_SetPassword(FUN_009b3cb0()->FUN_0044ddc0());
    int iNumPoints = 4;
    NiPoint3 points[4];
    GenerateSpherePoints(points, 3, position, GetProjectileSpread(0), FUN_00931d70(), GetField154(),
                         ((EmitterProperties*)FUN_004181e0())->FUN_009a7c40(), RandomFloatTwoPi());
    points[3] = position + direction * (float)(GetFirstLightParameter() - Projectile_GetDistanceMoved());
    visual.bhkPickData_SetFilter(objectHandle.id);
    visual.bhkPickData_SetFrom(&position);
    for (int i = 0; i < 4; ++i)
    {
        visual.bhkPickData_SetLength(points[i] - position);
        ImpactData impact;
        visual.bhkPickData_SetAllCollector(&impact);
        Tester* tester = (Tester*)DAT_011dea3c->FUN_008d6f30()->TESObjectCELL_GetbhkWorld();
        bool accepted = tester->Query(&visual);
        if (accepted)
            accepted = Projectile_ProcessTargetPick(&visual, this, 0, 0, 0, DAT_01016970) != 0;
        if (accepted)
            emitted = true;
        if (*DAT_011f20ec.FUN_00408d60())
        {
            Color4 greenColor;
            Color4 yellowColor;
            Color4* pColor = visual.bhkPickData_GetPickFailed() ? greenColor.FUN_00414430(1.0f, 0.0f, 0.0f, 1.0f)
                                                   : yellowColor.FUN_00414430(1.0f, 1.0f, 0.0f, 1.0f);
            __declspec(align(16)) Color4 color = *pColor;
            void* marker = MakeLine(&position, &color, &points[i], &color, 1);
            DAT_011dea10->FUN_00458e20(marker, *DAT_011f210c.Setting_Float_00403e20());
        }
    }
    return emitted;
}
