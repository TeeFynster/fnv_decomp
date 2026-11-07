
// src/fallout/magic/magicfogprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/magicfogprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/magicfogprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magicfogprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/magicfogprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicfogprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(float, float, float, float);
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    bool FUN_00ad8ce0();
    void FUN_00ad8d10();
    bool FUN_00ad89e0(float);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xFltSetting
{
    float* Setting_Float_00403e20();
};
extern xFltSetting xg_11d16f8;
extern xFltSetting xg_11d1c28;
extern const float xg_107ad40;
extern xFltSetting xg_11d1b74;
extern xFltSetting xg_11d15c8;
extern xFltSetting xg_11d15f8;
float xFUN_00404010(float, float);
struct xItem
{
    int FUN_004044d0();
    int FUN_00404420();
};
void xFUN_0080fae0(float);
struct xRadius
{
    float FUN_009b0bd0();
};
struct xSndForm
{
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct xEffect
{
    xSndForm* BGSProjectile_GetExplosion();
};
struct xCtl
{
    void bhkCharacterProxy_SetLinearVelocity(xVec4*);
};
struct xCell
{
    void FUN_00548230(void*, bool);
};
struct xOwner
{
    void MagicLight_Transfer(void*);
    void MagicLight_Fade(bool, float);
};
struct xA
{
    virtual void a0();
    virtual void FUN_00484b60(unsigned int);
    int m_iWordAt04, m_8, m_iThirdValue, m_10, m_14;
};
struct xB
{
    virtual void b0();
};
struct xBase : xA, xB
{
    xBase(int, int, int, int, xP3, xP3);
    ~xBase();
};
struct xActorV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void* FUN_2c();
};

extern void* xg_player_11dea3c;
struct xProj : xBase
{
    int m_pad1c[27];
    float m_88;
    int m_pad8c[7];
    float m_a8;
    float m_ac;
    float m_b0;
    int m_b4;
    float m_b8;
    xSound m_bc;
    int m_c8;
    xOwner* m_cc;
    xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner);
    xEffect* GetAVEffect();
    xItem* CombatController_GetCombatState();
    void TESObjectREFR_Set3DSimple(void*);
    void MagicProjectile_Load3D(int);
    void InitProjectileEffect();
    void MagicFogProjectile_InitHavok();
    xCtl* FUN_009306d0();
    xCell* FUN_008d6f30();
    xSound PlaySoundByFormID(void*, int, unsigned int, int);
    void MagicProjectile_CheckShotBehindWall();
    xActorV* FUN_009185e0();
};
// @fnv 0x00819360
xProj::xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner) : xBase(a, b, c, d, kP1, kP2)
{
    m_ac = xFUN_00404010((float)CombatController_GetCombatState()->FUN_004044d0(), *xg_11d1b74.Setting_Float_00403e20());
    m_b0 = xFUN_00404010((float)CombatController_GetCombatState()->FUN_00404420(), *xg_11d15c8.Setting_Float_00403e20());
    m_88 = ((xRadius*)GetAVEffect())->FUN_009b0bd0() * *xg_11d16f8.Setting_Float_00403e20();
    m_b4 = 0;
    m_a8 = 0.0f;
    m_b8 = 1.0f;
    m_cc = 0;
    m_c8 = 0;
    if (apE)
        TESObjectREFR_Set3DSimple(apE);
    else
        MagicProjectile_Load3D(0);
    InitProjectileEffect();
    MagicFogProjectile_InitHavok();
    xVec4 V(-xg_107ad40, 0.0f, 0.0f, 0.0f);
    FUN_009306d0()->bhkCharacterProxy_SetLinearVelocity(&V);
    FUN_008d6f30()->FUN_00548230(this, false);
    if (GetAVEffect()->BGSProjectile_GetExplosion())
    {
        void* NAME = GetAVEffect()->BGSProjectile_GetExplosion()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        if (m_bc.FUN_00ad8ce0())
            m_bc.FUN_00ad8d10();
        m_bc = PlaySoundByFormID(NAME, 1, 0x40000102, 1);
        m_bc.FUN_00ad89e0(1.0f);
    }
    if (apOwner)
    {
        apOwner->MagicLight_Transfer(this);
        m_cc = apOwner;
        m_cc->MagicLight_Fade(false, m_ac);
    }
    MagicProjectile_CheckShotBehindWall();
    void* SHOOTER = FUN_009185e0() ? FUN_009185e0()->FUN_2c() : 0;
    if (SHOOTER != xg_player_11dea3c)
        xFUN_0080fae0(*xg_11d15f8.Setting_Float_00403e20());
}
