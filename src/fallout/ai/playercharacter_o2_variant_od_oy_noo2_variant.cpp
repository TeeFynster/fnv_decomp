
// src/fallout/ai/playercharacter_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/playercharacter_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/playercharacter_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/playercharacter.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../../include/Projectile.h"
#include "../../../include/Setting.h"
#include "../../../include/NiPoint3.h"

struct PickTarget
{
    int GetId();
    int GetState();
    float GetRange();
};
struct FUN_00c6fd20_class
{
    void* m_60c;
    int FUN_00c6fd20();
};

#include <xmmintrin.h>
struct GrabVector
{
    __m128 value;
    GrabVector& FUN_006815c0();
    void FUN_00553f70(const GrabVector*);
    void FUN_00961190(void*);
    void FUN_004b4ab0(const GrabVector*);
};
struct GrabPoint
{
    float x, y, z;
    GrabPoint& FUN_006815c0();
    GrabPoint operator*(float) const;
    GrabPoint operator+(const GrabPoint&) const;
    GrabPoint operator-(const GrabPoint&) const;
    float FUN_00457990() const;
};
struct GrabMatrix
{
    GrabPoint FUN_004b4500(const GrabPoint*) const;
};
struct GrabPosition
{
    GrabVector value;
    void SetFromScaledVector3(const GrabPoint&);
    void FUN_004b4db0(const GrabVector*);
    GrabVector* ApplyToAction(GrabVector*);
};
struct GrabBody;
struct GrabConstraintData
{
    int unk00;
    GrabBody* body;
    int unk08, unk0c;
    GrabPosition angular;
    GrabPosition position;
    float f30, f34, f38, f3c;
    void FUN_004b4f40();
};
struct GrabRay
{
    GrabVector from, to;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    float hitFraction;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    void FUN_004a3c20();
    void FUN_004a3f70(int);
    void FUN_004a3da0(const GrabPoint*);
    void FUN_007f68a0(const GrabPoint*);
    GrabBody* FUN_00c66fd0();
};
struct GrabFilter
{
    int bits;
    GrabFilter(int);
    void FUN_004a39f0(int);
    void FUN_0059ce80(unsigned);
    int FUN_004a3a20();
    int FUN_0043b4d0();
};
struct GrabController
{
    float GetSettingFloat();
};
struct GrabCell;
struct GrabRef;
struct GrabShape;
struct GrabItem
{
    GrabShape* FUN_0084e3a0();
};
struct GrabItems
{
    int GetShortAtOffset4();
    GrabItem** FUN_0096a370(int);
};
struct GrabBody
{
    void* FUN_0044ddc0();
    int FUN_00517670();
    GrabItems* FUN_009604f0();
    void* FUN_004b4ec0();
    GrabVector* FUN_004b4f00(const GrabVector*);
};
struct GrabWorld
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual bool Cast(GrabRay*);
    void FUN_005533c0();
};
struct GrabShape
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual int GetType();
};
struct GrabPhysics
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void GetNavMeshData(GrabVector*);
    GrabBody* FUN_004ae750();
    GrabFilter FUN_0043b4f0();
};
struct GrabRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsDead();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual GrabRef* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual bool IsActor();
    virtual void v228();
    virtual bool AllowGrab(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual int GetState();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual bool IsStateValid();

    bool FUN_00444d00(int);
    GrabCell* FUN_008d6f30();
    void* FUN_005d43c0();
    GrabRef* FUN_0044ddc0();
    GrabMatrix* FUN_00461130();
};
struct GrabCell
{
    GrabWorld* FUN_004543c0();
};
struct GrabSave
{
    bool FUN_0042ce10();
};
struct GrabConstraint
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();

    virtual void SetWorld(GrabWorld*);
    int unk04, unk08, unk0c;
    static void* operator new(unsigned);
    GrabConstraint(const GrabConstraintData*);
};
struct GrabPointer
{
    GrabConstraint* ptr;
    GrabPointer& FUN_0066b0d0(GrabConstraint*);
    GrabConstraint* FUN_00559450();
};
struct GrabHost
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
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
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;

    GrabPointer constraint;
    GrabRef* target;
    int mode;
    float mass;
    float distance;
    void GetCameraPosAndDir(GrabPoint*, GrabPoint*, bool);
    GrabFilter* FUN_00931ed0(int*);
    void SetEffectValue(int, float, GrabRef*);
    void FUN_00961280();
    GrabController* FUN_009306d0();
    void FUN_0095f930(GrabRef*, int, float);
};
extern Setting DAT_011e0b1c;
extern Setting DAT_011d18a8, DAT_011d183c, DAT_011d1728, DAT_011d1604;
extern Setting DAT_011d1a08, DAT_011d1c7c, DAT_011d1b44, DAT_011d177c;
extern Setting DAT_011d1260, DAT_011d0048, DAT_011d0220, DAT_011d0e4c;
extern Setting DAT_011d0358, DAT_011cfeec, DAT_011d08c8, DAT_011d0ffc;
extern GrabSave* DAT_011ddf38;
extern const GrabPoint DAT_011a9484;
extern const float DAT_01017868;
extern const double DAT_01020998, DAT_0101ffa0, DAT_01018a90, DAT_01011588;
GrabPhysics* FUN_004b52f0(GrabRef*);
int GetBSXFlags(GrabRef*, int);
bool MarkBaseExtraListScriptEvent(int, void*, unsigned);
void GetScalarAndVector(GrabRef*, GrabVector*, float*);
bool FUN_00703430();
GrabPhysics* FUN_00960510();
GrabRef* FUN_004b5a20(GrabBody*);
GrabRef* FUN_0056f930(GrabRef*);
GrabPhysics* FUN_004b5a80(GrabBody*);
void FUN_007033d0(GrabPoint*);
void FUN_00553fc0(GrabVector*, const GrabPoint*);
void FUN_00458620(GrabPoint*, const GrabVector*);
float FUN_004587d0(float);
float FUN_00404010(float, float);
float FUN_0040ebd0(float, float);
float FUN_0062c300(GrabRef*);
float LinearInterpolate(float, float, float, float, float);

// @fnv 0x0095f930
void GrabHost::FUN_0095f930(GrabRef* ref, int newMode, float range)
{
    if (!*DAT_011e0b1c.FUN_00408d60() && ref->IsDead() && !ref->AllowGrab(0))
        return;
    if (ref && ref->IsActor())
    {
        GrabRef* actor = ref;
        if (actor->GetState() == 3)
        {
            GrabRef* actor2 = actor;
            if (actor2->IsStateValid() && !actor2->FUN_00444d00(0x200))
                return;
        }
    }
    if (ref && ref->FUN_008d6f30())
    {
        GrabRef* root = ref->Get3D();
        GrabPhysics* physics = FUN_004b52f0(root);
        if (physics)
        {
            bool character = GetBSXFlags(root, 8) || ref->IsDead();
            target = ref;
            MarkBaseExtraListScriptEvent(0, target->FUN_005d43c0(), 0x80000);
            mode = newMode;
            distance = range;
            GrabConstraintData data;
            data.FUN_004b4f40();
            float ignored = 0.0f;
            GrabVector center;
            center.FUN_006815c0();
            if (character && ref->IsDead())
                GetScalarAndVector(root, &center, &ignored);
            else
                physics->GetNavMeshData(&center);
            GrabPoint direction;
            direction.FUN_006815c0();
            GrabPoint origin;
            origin.FUN_006815c0();
            GetCameraPosAndDir(&origin, &direction, true);
            bool selected = false;
            GrabWorld* world = ref->FUN_008d6f30()->FUN_004543c0();
            if (mode == 1 && world && !DAT_011ddf38->FUN_0042ce10())
            {
                if (!FUN_00703430() || !FUN_00960510())
                {
                    GrabRay ray;
                    ray.FUN_004a3c20();
                    GrabFilter filter(0);
                    filter.FUN_004a39f0(0x24);
                    int filterTemp;
                    filter.FUN_0059ce80(FUN_00931ed0(&filterTemp)->FUN_004a3a20());
                    ray.FUN_004a3f70(filter.bits);
                    ray.FUN_004a3da0(&origin);
                    ray.FUN_007f68a0(&(direction * distance));
                    if (world->Cast(&ray))
                    {
                        GrabBody* hit = ray.FUN_00c66fd0();
                        GrabRef* hitRef = FUN_004b5a20(hit);
                        GrabRef* hitNode = hitRef ? hitRef->FUN_0044ddc0() : 0;
                        GrabRef* resolved = FUN_0056f930(hitNode);
                        if (hit && resolved == ref)
                        {
                            if (!character)
                            {
                                GrabPhysics* hitPhysics = FUN_004b5a80(hit);
                                hitPhysics->GetNavMeshData(&center);
                            }
                            selected = true;
                            data.body = hit;
                            distance *= ray.hitFraction;
                            GrabPoint destination = origin + direction * distance;
                            data.position.SetFromScaledVector3(destination);
                        }
                    }
                }
                else
                {
                    GrabPoint picked;
                    FUN_007033d0(&picked);
                    if (!DAT_011ddf38->FUN_0042ce10())
                        distance = (picked - origin).FUN_00457990();
                    data.position.SetFromScaledVector3(picked);
                    GrabPhysics* pickedPhysics = FUN_00960510();
                    data.body = pickedPhysics->FUN_004ae750();
                    selected = true;
                }
            }
            if (!selected)
            {
                data.position.FUN_004b4db0(&center);
                GrabVector position;
                position.FUN_006815c0();
                if (character)
                {
                    GrabVector scratch;
                    scratch.FUN_006815c0();
                    GrabVector rotated;
                    rotated.FUN_006815c0();
                    FUN_00553fc0(&rotated, &(root->FUN_00461130()->FUN_004b4500(&DAT_011a9484)));
                    data.position.ApplyToAction(&position);
                    position.FUN_00553f70(&rotated);
                    data.position.FUN_004b4db0(&position);
                }
                if (!DAT_011ddf38->FUN_0042ce10())
                {
                    GrabPoint point;
                    point.FUN_006815c0();
                    FUN_00458620(&point, data.position.ApplyToAction(&position));
                    distance = (point - origin).FUN_00457990();
                }
                data.body = physics->FUN_004ae750();
            }
            if (mode == 1)
                SetEffectValue(5, DAT_01017868, ref);
            GrabBody* body = data.body;
            if (!body->FUN_0044ddc0() || body->FUN_00517670() == 5 || body->FUN_00517670() == 4)
            {
                FUN_00961280();
                return;
            }
            GrabController* controller = FUN_009306d0();
            if (controller)
            {
                float minDistance = FUN_004587d0(controller->GetSettingFloat()) + DAT_01020998;
                if (distance < minDistance)
                    distance = minDistance;
            }
            if (mode == 3)
            {
                if (character)
                {
                    data.f30 = *DAT_011d18a8.FUN_00403e20();
                    data.f34 = *DAT_011d183c.FUN_00403e20();
                    data.f3c = *DAT_011d1728.FUN_00403e20();
                    data.f38 = *DAT_011d1604.FUN_00403e20();
                }
                else
                {
                    data.f30 = *DAT_011d1a08.FUN_00403e20();
                    data.f34 = *DAT_011d1c7c.FUN_00403e20();
                    data.f3c = *DAT_011d1b44.FUN_00403e20();
                    data.f38 = *DAT_011d177c.FUN_00403e20();
                }
            }
            else
            {
                float angularScale = 1.0f;
                float linearScale = 1.0f;
                if (target->IsDead())
                {
                    float upper = *DAT_011d1260.FUN_00403e20();
                    float lower = *DAT_011d0048.FUN_00403e20();
                    float minScale = *DAT_011d0220.FUN_00403e20();
                    float maxScale = *DAT_011d0e4c.FUN_00403e20();
                    float clamped = FUN_0040ebd0(lower, FUN_00404010(upper, FUN_0062c300(root)));
                    angularScale *= LinearInterpolate(maxScale, minScale, lower, upper, clamped);
                    bool allCharacter = true;
                    for (int i = 0; i < body->FUN_009604f0()->GetShortAtOffset4() && allCharacter; ++i)
                    {
                        GrabShape* shape = (*body->FUN_009604f0()->FUN_0096a370(i))->FUN_0084e3a0();
                        allCharacter = shape->GetType() == 0xb;
                    }
                    if (allCharacter)
                    {
                        linearScale *= DAT_0101ffa0;
                        angularScale *= DAT_01018a90;
                    }
                }
                else if (physics->FUN_0043b4f0().FUN_0043b4d0() == 0xe)
                {
                    linearScale *= DAT_0101ffa0;
                    angularScale *= DAT_01011588;
                }
                data.f30 = *DAT_011d0358.FUN_00403e20();
                data.f34 = *DAT_011cfeec.FUN_00403e20() * linearScale;
                data.f3c = *DAT_011d08c8.FUN_00403e20();
                data.f38 = *DAT_011d0ffc.FUN_00403e20() * angularScale;
            }
            GrabVector localPosition;
            localPosition.FUN_006815c0();
            GrabVector localRotation;
            localRotation.FUN_006815c0();
            data.position.ApplyToAction(&localPosition);
            localPosition.FUN_00961190(body->FUN_004b4ec0());
            data.angular.ApplyToAction(&localRotation)
                ->FUN_004b4ab0(&body->FUN_004b4f00(&localPosition)->FUN_006815c0());
            data.angular.FUN_004b4db0(&localRotation);
            target->FUN_008d6f30()->FUN_004543c0()->FUN_005533c0();
            constraint.FUN_0066b0d0(new GrabConstraint(&data));
            GrabConstraint* created = constraint.FUN_00559450();
            created->SetWorld(target->FUN_008d6f30()->FUN_004543c0());
            target->FUN_008d6f30()->FUN_004543c0()->FUN_005533c0();
            mass = FUN_0062c300(ref->Get3D());
        }
        else if (newMode == 2)
        {
            target = ref;
            MarkBaseExtraListScriptEvent(0, target->FUN_005d43c0(), 0x80000);
            mode = 2;
            distance = range;
        }
    }
}

#include <xmmintrin.h>
namespace fnv_00960520 {
#include <xmmintrin.h>
/* UNVERIFIED previous contributor's C++ reconstruction, 2026-10-23; preserved for official recheck. */

struct ObjF0;
struct HkTransform;
class HkVec
{
  public:
    __m128 m_v;
    HkVec();
    HkVec(float s);
    void SetTransformedPos(HkTransform* t, HkVec* p);
    void AddVec(HkVec* p);
    HkVec Delta(void) const;
    float Length3() const;
    void MulVec(HkVec* p);
    float& At(int i);
    void Set(float x, float y, float z, float w);
    void SetRotated(void* p);
};
struct HkTransform
{
    HkVec m_row0, m_row1, m_row2, m_row3;
    HkTransform();
};
class Handle
{
  public:
    unsigned int m_val;
    Handle();
    void Assign(int v);
    bool IsSet();
};
class Handle2
{
  public:
    unsigned int m_val;
    Handle2();
    int Get();
};
struct VObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual VObj* vGet0C();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int vGetType();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual bool vTest(ObjF0* p);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void vGetTransform(HkTransform* t);
    virtual void v3E();
    virtual void v3F();
    virtual bool vIsDead();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
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
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
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
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual VObj* vGet1D0();
    int GetRace();
    VObj* GetBase();
    void GetDir(HkVec* out);
    void GetVel(HkVec* out);
    void SetDest(NiPoint3* p);
    Handle GetHandle();
    Handle2 GetHandle2();
    VObj* GetCombat();
    VObj* GetNode();
    VObj* Get3D();
    NiPoint3* GetPos();
    int GetCount();
    VObj* GetAt(int i);
    VObj* GetOwner();
    VObj* GetParent();
    VObj* GetNext();
    float GetRadius();
    VObj* GetChild(int i);
    VObj* GetFirst();
    void* GetRot();
    void ApplyVel(HkVec* p);
};
struct ItemList
{
    int Count();
    void* At(int i);
};
struct Obj4A0
{
    int unk00, unk04, unk08, unk0C;
    float fValue;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int iRef;
    int unk54, unk58, unk5C;
    Obj4A0(void* p);
};
struct Obj430
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C;
    int unk260, unk264, unk268, unk26C, unk270, unk274, unk278, unk27C;
    int unk280, unk284, unk288, unk28C, unk290, unk294, unk298, unk29C;
    int unk2A0, unk2A4, unk2A8, unk2AC, unk2B0, unk2B4, unk2B8, unk2BC;
    int unk2C0, unk2C4, unk2C8, unk2CC, unk2D0, unk2D4, unk2D8, unk2DC;
    int unk2E0, unk2E4, unk2E8, unk2EC, unk2F0, unk2F4, unk2F8, unk2FC;
    int unk300, unk304, unk308, unk30C, unk310, unk314, unk318;
    Obj430();
    ~Obj430();
    ItemList* GetList();
};
struct ObjF0
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8;
    ObjF0();
    void SetHandle(Handle h);
    void SetOrigin(NiPoint3* p);
    void SetDir(const NiPoint3& v);
    void Run(Obj430* out);
    void SetTarget(NiPoint3* p);
    VObj* GetHit();
};
struct RefHandle
{
    VObj* Get();
};
extern VObj* DAT_011dea3c;
extern Setting DAT_011d0664;
extern Setting DAT_011cffc4;
extern Setting DAT_011d1308;
extern Setting DAT_011d0808;
extern Setting DAT_011d04d8;
extern Setting DAT_011d037c;
extern const double DAT_01012070;
extern const double DAT_01072f98;
extern const double DAT_0101a6b0;
extern const double DAT_01012060;
extern const double DAT_01020998;
VObj* GetPf8(VObj* p);
VObj* LookupForm(int id);
VObj* AsActor(VObj* p);
float MaxF(float a, float b);
float ClampF(float f);
int HasFlag(VObj* p, int flag);
VObj* GetProcess(VObj* p);
float GetScale(VObj* p);
float MinF(float a, float b);
float Lerp(float a, float b, float c, float d, float e);
void ToNiPoint(NiPoint3* out, HkVec* in);
void ApplyImpulse(VObj* p, NiPoint3* v, int flag);
}  // namespace fnv_00960520


// Legacy grab state referenced by this reconstruction lies beyond Projectile.
// Keep its original offsets until the function's owning type is identified.
// @fnv 0x00960520
void Projectile::FUN_00960520(int a)
{
    using namespace fnv_00960520;
    if ((*reinterpret_cast<VObj**>(reinterpret_cast<char*>(this) + 0x638)) == 0 || (*reinterpret_cast<RefHandle*>(reinterpret_cast<char*>(this) + 0x634)).Get() == 0 || (*reinterpret_cast<RefHandle*>(reinterpret_cast<char*>(this) + 0x634)).Get()->GetRace() == 0)
    {
        Explode();
        return;
    }
    PickTarget* pick = GetPick();
    if (pick != 0 && pick->GetId() == (*reinterpret_cast<RefHandle*>(reinterpret_cast<char*>(this) + 0x634)).Get()->GetRace() && pick->GetState() == 1)
    {
        Explode();
        return;
    }
    float base = 0.0f;
    float speed = (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x644)) + base;
    NiPoint3 pos;
    NiPoint3 dir;
    GetLaunch(&pos, &dir, true);
    ObjF0 ray;
    VObj* weapon = (*reinterpret_cast<RefHandle*>(reinterpret_cast<char*>(this) + 0x634)).Get()->GetBase();
    VObj* shooter = GetPf8(weapon);
    Handle owner = shooter->GetHandle();
    owner.Assign(DAT_011dea3c->GetHandle2().Get());
    ray.SetHandle(owner);
    ray.SetOrigin(&pos);
    ray.SetDir(dir.Scale(speed));
    Obj430 hits;
    ray.Run(&hits);
    VObj* world = DAT_011dea3c->GetCombat()->GetNode();
    if (world->vTest(&ray))
    {
        float frac = 1.0f;
        for (int i = 0; frac == DAT_01012070 && i < hits.GetList()->Count(); i++)
        {
            Obj4A0 hit(hits.GetList()->At(i));
            VObj* form = LookupForm(hit.iRef);
            if (form != 0)
            {
                VObj* actor = AsActor(form);
                if (actor != 0 && actor != (*reinterpret_cast<VObj**>(reinterpret_cast<char*>(this) + 0x638)) && actor != DAT_011dea3c)
                {
                    frac = hit.fValue;
                }
            }
        }
        speed = MaxF(0.0f, (double)frac * speed - base);
        if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x63c)) == 3)
        {
            (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x644)) = speed;
        }
    }
    if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x63c)) == 3)
    {
        ObjF0 ray2;
        ray2.SetHandle(shooter->GetHandle());
        ray2.SetOrigin(&pos);
        NiPoint3 tgt = *(*reinterpret_cast<VObj**>(reinterpret_cast<char*>(this) + 0x638))->vGet1D0()->Get3D()->GetPos();
        ray2.SetTarget(&tgt);
        if (DAT_011dea3c->GetCombat() != 0)
        {
            VObj* world2 = DAT_011dea3c->GetCombat()->GetNode();
            if (world2->vTest(&ray2))
            {
                VObj* hitId = ray2.GetHit();
                VObj* hitActor = AsActor(hitId);
                if (hitActor != 0 && (*reinterpret_cast<VObj**>(reinterpret_cast<char*>(this) + 0x638)) != hitActor && !hitActor->vIsDead())
                {
                    Explode();
                    return;
                }
            }
        }
    }
    HkVec delta;
    HkVec vel;
    HkVec dirv;
    HkTransform xf;
    (*reinterpret_cast<RefHandle*>(reinterpret_cast<char*>(this) + 0x634)).Get()->GetDir(&dirv);
    (*reinterpret_cast<RefHandle*>(reinterpret_cast<char*>(this) + 0x634)).Get()->GetVel(&vel);
    shooter->vGetTransform(&xf);
    delta.SetTransformedPos(&xf, &vel);
    delta.AddVec(&dirv);
    float len = ClampF(delta.Delta().Length3());
    if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x63c)) != 3 && len > DAT_01072f98)
    {
        Explode();
        return;
    }
    int count = weapon->GetCount();
    float best = 0.0f;
    for (int j = 0; j < count; j++)
    {
        VObj* item = weapon->GetAt(j);
        if (item != 0)
        {
            VObj* owner2 = item->GetOwner();
            if (owner2->vGetType() == 0xb)
            {
                VObj* src = (item->GetParent() == weapon) ? item->GetNext() : item->GetParent();
                if (src != 0 && best < src->GetRadius())
                {
                    best = src->GetRadius();
                }
            }
        }
    }
    float ratio = best / weapon->GetRadius();
    if (len > *DAT_011d0664.FUN_00403e20() && ratio > *DAT_011cffc4.FUN_00403e20())
    {
        Explode();
        return;
    }
    VObj* target = (*reinterpret_cast<VObj**>(reinterpret_cast<char*>(this) + 0x638))->vGet1D0();
    bool flagA = HasFlag(target, 8) != 0 ? 1 : 0;
    bool flagB = HasFlag(target, 0x80) != 0 ? 1 : 0;
    if ((*reinterpret_cast<VObj**>(reinterpret_cast<char*>(this) + 0x638))->vIsDead() && shooter->GetHandle().IsSet())
    {
        flagA = false;
        VObj* parent = target->vGet0C();
        if (parent != 0 && parent->GetChild(0) != 0)
        {
            target = parent->GetChild(0);
        }
        VObj* proc = GetProcess(weapon);
        VObj* node = proc ? proc->GetFirst() : 0;
        while (node != 0 && node != parent)
        {
            if (node == target)
            {
                flagA = true;
            }
            node = node->GetNext();
        }
    }
    if (target != 0 && flagA && len > *DAT_011d1308.FUN_00403e20())
    {
        float force = *DAT_011d0808.FUN_00403e20() * (len - *DAT_011d1308.FUN_00403e20()) / len;
        float fScaledValue = *DAT_011d04d8.FUN_00403e20();
        float fMin = *DAT_011d037c.FUN_00403e20();
        float scale = MinF(fMin, MaxF(fScaledValue, fnv_00960520::GetScale(target)));
        float t = Lerp(0.0f, 1.0f, fMin, fScaledValue, scale);
        HkVec mul(force * DAT_0101a6b0 * t);
        delta.MulVec(&mul);
        if (flagB || (*reinterpret_cast<VObj**>(reinterpret_cast<char*>(this) + 0x638))->vIsDead())
        {
            NiPoint3 imp;
            ToNiPoint(&imp, &delta);
            ApplyImpulse(target, &imp, 0);
        }
        else
        {
            VObj* body = (*reinterpret_cast<RefHandle*>(reinterpret_cast<char*>(this) + 0x634)).Get()->GetBase();
            if (body != 0)
            {
                VObj* bodyProc = GetPf8(body);
                HkVec v;
                v.Set(delta.At(0), delta.At(1), delta.At(2), 0.0f);
                v.SetRotated(bodyProc->GetRot());
                bodyProc->ApplyVel(&v);
            }
        }
    }
    NiPoint3 dest = pos.Add(dir.Scale(speed));
    if (pick != 0)
    {
        NiPoint3 step = dir.Scale(speed);
        if (dir.z < DAT_01012060)
        {
            step.z = 0.0f;
            float horiz = step.FUN_00457910();
            float range = ClampF(pick->GetRange()) + fnv_00960520::DAT_01020998;
            if (horiz < range)
            {
                float extra = range - horiz;
                dest.AddTo(step.Scale(extra));
            }
        }
    }
    (*reinterpret_cast<RefHandle*>(reinterpret_cast<char*>(this) + 0x634)).Get()->SetDest(&dest);
}
