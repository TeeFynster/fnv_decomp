
// src/staging/blk_00800000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00800000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00800000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
#include "../../include/hkVector4.h"
// Read a vector property from this object into an aligned local and hand it to a setter on
// the target passed in.

void __cdecl FUN_00458620(void* apTarget, const hkVector4& arVector);

struct VectorSourceB00
{
    void SubtractVectors(hkVector4& arOut);
    void bhkCharacterController_GetPosition(void* apTarget);
};

// Preserve the original stack cookie with the shared vector's union layout.
#pragma strict_gs_check(push, on)
// @fnv 0x00812b00
// src: XBOX_PDB 0x00812b00
void VectorSourceB00::bhkCharacterController_GetPosition(void* apTarget)
{
    hkVector4 kVector;
    SubtractVectors(kVector);
    FUN_00458620(apTarget, kVector);
}
#pragma strict_gs_check(pop)

struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator-(const xP3&) const;
    xP3 operator+(const xP3&) const;
    xP3 operator*(float) const;
};
struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};
struct __declspec(align(16)) xHitInfo
{
    xHitInfo(const xHitInfo*);
    int m_iWordAt00[4];
    float m_10;
    int m_14[15];
    void* m_50;
    int m_54[3];
};
struct xHitList
{
    int FUN_00726070();
    xHitInfo* GetEntryAt(int);
};
struct __declspec(align(16)) xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    xHitList* TESDataHandler_GetWorldSpaceList();
    int m_q[0xc7];
};
struct __declspec(align(16)) xPick
{
    xPick();
    void bhkPickData_SetFrom(xP3*);
    void bhkPickData_SetTo(const xP3&);
    void bhkPickData_SetFilter(xFilter);
    void bhkPickData_SetAllCollector(xAllHits*);
    char m_buf[0xb0];
};
struct xWorld
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
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual bool FUN_c8(xPick*);
};

struct xCell;
xWorld* __fastcall xFUN_004543c0(xCell*);
struct xOwner
{
    xFilter bhkCharacterController_GetCollisionFilter();
};
struct xActor;
float __fastcall xFUN_0070c3b0(xActor*);
void* xFUN_004b5820(void*);
void* xFUN_004b59f0(void*);
void* xFUN_004b5a80(void*);
xActor* xFUN_0056f930(void*);
struct xShooterV
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
    virtual xActor* FUN_2c();
};
struct xActor
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
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool FUN_100();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void* FUN_1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
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
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void FUN_304(xP3, void*, xActor*, int);
    xCell* FUN_008d6f30();
    float TESObjectREFR_GetScale_00567400();
    xFilter FUN_00931ed0();
    xOwner* FUN_009306d0();
    xShooterV* FUN_009185e0();
    void MagicProjectile_CheckShotBehindWall();
};

extern xActor* xg_player_11dea3c;
// @fnv 0x0081eba0
// src: XBOX_PDB 0x0081eba0
void xActor::MagicProjectile_CheckShotBehindWall()
{
    void* EFFECT = FUN_1d0();
    if ((FUN_009185e0() && FUN_009185e0()->FUN_2c() != xg_player_11dea3c) || !EFFECT)
        return;
    xPick PICK;
    xP3 PLPOS;
    xP3 MYPOS;
    xP3 DIR;
    MYPOS = *FUN_1f4();
    PLPOS = *xg_player_11dea3c->FUN_1f4();
    PLPOS.z = PLPOS.z + xFUN_0070c3b0(xg_player_11dea3c) * xg_player_11dea3c->TESObjectREFR_GetScale_00567400();
    DIR = MYPOS - PLPOS;
    xOwner* OWNER = FUN_009306d0();
    xFilter FILTER(0);
    if (OWNER)
        FILTER = OWNER->bhkCharacterController_GetCollisionFilter();
    else
        FILTER = xg_player_11dea3c->FUN_00931ed0();
    PICK.bhkPickData_SetFilter(FILTER);
    PICK.bhkPickData_SetFrom(&PLPOS);
    PICK.bhkPickData_SetTo(PLPOS + DIR);
    xAllHits HITS;
    PICK.bhkPickData_SetAllCollector(&HITS);
    bool DONE = false;
    if (xg_player_11dea3c->FUN_008d6f30() && xFUN_004543c0(xg_player_11dea3c->FUN_008d6f30())->FUN_c8(&PICK))
    {
        bool GO = true;
        for (int I = 0; GO && I < HITS.TESDataHandler_GetWorldSpaceList()->FUN_00726070() && !DONE; I++)
        {
            xHitInfo INFO(HITS.TESDataHandler_GetWorldSpaceList()->GetEntryAt(I));
            void* OBJ = xFUN_004b5820(INFO.m_50);
            if (OBJ)
            {
                void* FormRecordHeader = xFUN_004b5a80(xFUN_004b59f0(INFO.m_50));
                xActor* ACTOR = xFUN_0056f930(OBJ);
                if (ACTOR != xg_player_11dea3c && ACTOR != this && !ACTOR->FUN_100() && FormRecordHeader)
                {
                    xP3 HITPOS = PLPOS + DIR * INFO.m_10;
                    FUN_304(HITPOS, FormRecordHeader, ACTOR, 0);
                    GO = false;
                }
            }
        }
    }
}

extern const float DAT_010546cc;
struct ImpactValue
{
    float* __thiscall Setting_Float_00403e20();
};
extern ImpactValue DAT_011ce3e4, DAT_011cecac, DAT_011cf9d4, DAT_011ce798, DAT_011cf114, DAT_011ce224;
struct ImpactState
{
    void __thiscall FUN_00483710();
};
struct ImpactType
{
    int value;
    int __thiscall CFilter_GetLayer();
};
struct __declspec(align(16)) ImpactVector
{
    __m128 coordinates;
    void __thiscall FUN_006815c0();
    void __thiscall FUN_005dbf20(float);
    void __thiscall normalize3_0062aea0();
    void __thiscall hkVector4_mul4(ImpactVector*);
};
extern void __cdecl NI2HK(ImpactVector*, const float*);
struct ImpactResult
{
    void __thiscall ApplyVirtualCall();
};
struct ImpactObject
{
    virtual void unknown_0000();
    virtual void unknown_0004();
    virtual void unknown_0008();
    virtual void unknown_000c();
    virtual void unknown_0010();
    virtual void unknown_0014();
    virtual void unknown_0018();
    virtual void unknown_001c();
    virtual void unknown_0020();
    virtual void unknown_0024();
    virtual void unknown_0028();
    virtual void unknown_002c();
    virtual void unknown_0030();
    virtual void unknown_0034();
    virtual void unknown_0038();
    virtual void unknown_003c();
    virtual void unknown_0040();
    virtual void unknown_0044();
    virtual void unknown_0048();
    virtual void unknown_004c();
    virtual void unknown_0050();
    virtual void unknown_0054();
    virtual void unknown_0058();
    virtual void unknown_005c();
    virtual void unknown_0060();
    virtual void unknown_0064();
    virtual void unknown_0068();
    virtual void unknown_006c();
    virtual void unknown_0070();
    virtual void unknown_0074();
    virtual void unknown_0078();
    virtual void unknown_007c();
    virtual void unknown_0080();
    virtual void unknown_0084();
    virtual void unknown_0088();
    virtual void unknown_008c();
    virtual void unknown_0090();
    virtual void unknown_0094();
    virtual ImpactState* unknown_0098();
    void __thiscall bhkWorldObject_GetCollisionFilter(ImpactType*);
    float __thiscall bhkRigidBody_GetMass();
    ImpactResult* __thiscall Bipedanim_GetReferenceFlagsOrZero(ImpactVector*, ImpactVector*);
};
struct ImpactOwner
{
    void __thiscall MagicProjectile_ApplyCollisionForce(float x, float y, float z, float dx, float dy, float dz, ImpactObject* object);
};
// @fnv 0x0081f000
// src: XBOX_PDB 0x0081f000
void ImpactOwner::MagicProjectile_ApplyCollisionForce(float x, float y, float z, float dx, float dy, float dz, ImpactObject* object)
{
    if (!object)
        return;
    ImpactState* state = object->unknown_0098();
    if (state)
    {
        float scale = DAT_010546cc;
        ImpactType type;
        object->bhkWorldObject_GetCollisionFilter(&type);
        switch (type.CFilter_GetLayer())
        {
        case 14:
            scale *= *DAT_011ce3e4.Setting_Float_00403e20();
            break;
        case 8:
        case 29:
            scale *= *DAT_011cecac.Setting_Float_00403e20();
            break;
        case 2:
        case 10:
            scale *= *DAT_011cf9d4.Setting_Float_00403e20();
            break;
        default:
            scale *= *DAT_011ce798.Setting_Float_00403e20();
            break;
        }
        float weight = object->bhkRigidBody_GetMass();
        if (weight < *DAT_011cf114.Setting_Float_00403e20())
            scale = weight / *DAT_011cf114.Setting_Float_00403e20() * scale;
        scale *= *DAT_011ce224.Setting_Float_00403e20();
        ImpactVector direction;
        direction.FUN_006815c0();
        NI2HK(&direction, &dx);
        ImpactVector position;
        position.FUN_006815c0();
        NI2HK(&position, &x);
        direction.normalize3_0062aea0();
        ImpactVector amount;
        amount.FUN_005dbf20(scale);
        direction.hkVector4_mul4(&amount);
        state->FUN_00483710();
        object->Bipedanim_GetReferenceFlagsOrZero(&direction, &position)->ApplyVirtualCall();
        state->FUN_00483710();
    }
}

namespace fnv_0080f810 {
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
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xFltSetting
{
    float* Setting_Float_00403e20();
};
extern xFltSetting xg_11d16f8;
extern xFltSetting xg_11d1c28;
extern const float xg_107a510;
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
    int m_ac;
    float m_b0;
    xSound m_b4;
    xOwner* m_c0;
    xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner);
    xEffect* GetAVEffect();
    void TESObjectREFR_Set3DSimple(void*);
    void MagicProjectile_Load3D(int);
    void ResetProjectileIdleAnimation();
    void MagicBallProjectile_InitHavok();
    xCtl* FUN_009306d0();
    xCell* FUN_008d6f30();
    xSound PlaySoundByFormID(void*, int, unsigned int, int);
    void MagicProjectile_CheckShotBehindWall();
    xActorV* FUN_009185e0();
};
// @fnv 0x0080f810
xProj::xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner) : xBase(a, b, c, d, kP1, kP2)
{
    m_88 = ((xRadius*)GetAVEffect())->FUN_009b0bd0() * *xg_11d16f8.Setting_Float_00403e20();
    m_ac = 0;
    m_a8 = 0.0f;
    m_b0 = 1.0f;
    m_c0 = 0;
    if (apE)
        TESObjectREFR_Set3DSimple(apE);
    else
        MagicProjectile_Load3D(0);
    ResetProjectileIdleAnimation();
    MagicBallProjectile_InitHavok();
    xVec4 V(-xg_107a510, 0.0f, 0.0f, 0.0f);
    FUN_009306d0()->bhkCharacterProxy_SetLinearVelocity(&V);
    FUN_008d6f30()->FUN_00548230(this, false);
    if (GetAVEffect()->BGSProjectile_GetExplosion())
    {
        void* NAME = GetAVEffect()->BGSProjectile_GetExplosion()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        if (m_b4.FUN_00ad8ce0())
            m_b4.FUN_00ad8d10();
        m_b4 = PlaySoundByFormID(NAME, 1, 0x40000102, 1);
    }
    if (apOwner)
    {
        apOwner->MagicLight_Transfer(this);
        m_c0 = apOwner;
    }
    MagicProjectile_CheckShotBehindWall();
    void* SHOOTER = FUN_009185e0() ? FUN_009185e0()->FUN_2c() : 0;
    if (SHOOTER != xg_player_11dea3c)
        xFUN_0080fae0(*xg_11d1c28.Setting_Float_00403e20());
    FUN_00484b60(0x10000000);
}
}  // namespace fnv_0080f810
