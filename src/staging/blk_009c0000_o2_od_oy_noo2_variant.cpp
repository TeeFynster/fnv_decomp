
// src/staging/blk_009c0000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_009c0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_009c0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator-(const xP3&) const;
};
struct xFilter
{
    xFilter(int);
    void CFilter_SetLayer(int);
    unsigned int m_uiFilterValue;
};
struct xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    int m_q[0xc7];
};
struct __declspec(align(16)) xPick
{
    xPick();
    void bhkPickData_SetFrom(xP3*);
    void bhkPickData_SetLength(xP3*);
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
int xFUN_009c0d80(xPick*, xActor*, void*, int, int, float);
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
    virtual void v64();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    char m_pad04[0xf8];
    xActor* m_fc;
    xCell* FUN_008d6f30();
    float TESObjectREFR_GetScale_00567400();
    xFilter FUN_00931ed0();
    xOwner* FUN_009306d0();
    void* FUN_004181e0();
    bool GetWaterPlaneIntersection(xPick*, float*);
    void Projectile_SetRange(float);
    bool Projectile_CheckShotBehindWall();
};

extern xActor* xg_player_11dea3c;
// @fnv 0x009c40c0
// src: XBOX_PDB 0x009c40c0
bool xActor::Projectile_CheckShotBehindWall()
{
    if (m_fc != xg_player_11dea3c)
        return false;
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
    FILTER.CFilter_SetLayer(6);
    PICK.bhkPickData_SetFilter(FILTER);
    PICK.bhkPickData_SetFrom(&PLPOS);
    PICK.bhkPickData_SetLength(&DIR);
    xAllHits HITS;
    PICK.bhkPickData_SetAllCollector(&HITS);
    xWorld* WORLD = xFUN_004543c0(xg_player_11dea3c->FUN_008d6f30());
    bool RES = WORLD->FUN_c8(&PICK);
    float DIST = 3.402823466e+38F;
    RES = RES | GetWaterPlaneIntersection(&PICK, &DIST);
    if (RES)
        RES = xFUN_009c0d80(&PICK, this, FUN_004181e0(), 0, 1, DIST) != 0;
    if (RES)
        Projectile_SetRange(0.0f);
    return RES;
}
