
// src/fallout/ai/combat/combatutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" float __cdecl FUN_005b9e80(float);

// Returns a divided by the product of FUN_005b9e80(b) and c.
// @fnv 0x009a7dd0
float __cdecl FUN_009a7dd0(float afNumerator, float afInput, float c)
{
    return afNumerator / (FUN_005b9e80(afInput) * c);
}

extern int DAT_011a558c;

// @fnv 0x009a97b0
char FUN_009a97b0(char a1, char a2)
{
    a1 += a2;
    if (a1 < 0)
        a1 += DAT_011a558c;
    if (a1 >= DAT_011a558c)
        a1 -= DAT_011a558c;
    return a1;
}

extern "C" double DAT_0103c348;
extern "C" int DAT_011a558c;

// Converts arg to int, multiplies by DAT_0103c348, divides by DAT_011a558c, and returns the result as float.
// @fnv 0x009a99f0
float ScaleCharToFloat(char acValue)
{
    int v = acValue;
    float result = static_cast<float>(v) * DAT_0103c348 / DAT_011a558c;
    return result;
}

struct FUN_009a9f00_shell
{
    void __thiscall SetFieldE0(float value);
};

// @fnv 0x009a9f00
void __thiscall FUN_009a9f00_shell::SetFieldE0(float value)
{
    *(float*)((char*)this + 0xe0) = value;
}

struct BGSProjectile
{
    bool GetFlag(unsigned int) const;
};

struct FUN_009a7f80_shell : BGSProjectile
{
    bool FUN_009a7f80() const;
};

// @fnv 0x009a7f80
bool FUN_009a7f80_shell::FUN_009a7f80() const
{
    return GetFlag(1);
}

extern "C" double _DAT_0103c348;

// @fnv 0x009a99d0
long __cdecl ScaleByRatio(float afValue)
{
    return (long)(afValue / _DAT_0103c348 * DAT_011a558c);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct TESObjectREFR
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual NiPoint3* v125() = 0;
};
float __cdecl GetScaleOrHeightDelta(TESObjectREFR* a, int b);
// Returns the attacker's position with its z raised by the value from GetScaleOrHeightDelta(apAttacker, 0).
// @fnv 0x009a8250
NiPoint3 FUN_009a8250(TESObjectREFR* apAttacker)
{
    NiPoint3 shooterLocation;
    shooterLocation = *apAttacker->v125();
    shooterLocation.z += GetScaleOrHeightDelta(apAttacker, 0);
    return shooterLocation;
}

namespace fnv_009a8600 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct TopicH
{
    NiPoint3* GetAddTopicList();
};
struct TESObjectREFR : TopicH
{
};
typedef int ACTOR_SEGMENT_INVIEW;
float __cdecl FUN_009a8460(TESObjectREFR*, ACTOR_SEGMENT_INVIEW, int);
// Returns the target's add-topic-list point with its z raised by the value from FUN_009a8460 for the given segment.
// @fnv 0x009a8600
NiPoint3 __cdecl GetTargetLocationWithOffset(TESObjectREFR* apTarget, ACTOR_SEGMENT_INVIEW aeTargetSegmentInView)
{
    NiPoint3 targetLocation;
    targetLocation = *apTarget->GetAddTopicList();
    targetLocation.z += FUN_009a8460(apTarget, aeTargetSegmentInView, 0);
    return targetLocation;
}
}  // namespace fnv_009a8600

namespace fnv_009a9370 {
struct NiPoint3
{
    float x, y, z;
};
struct CombatController
{
    char _00;
};
struct CombatCoverPointData
{
    char _00[0x14];
    NiPoint3 _14;
    char _pad[0x50];
    NiPoint3 _70;
};
void __cdecl FUN_009a93a0(CombatController*, NiPoint3*, NiPoint3*, NiPoint3*, NiPoint3*);
// Calls FUN_009a93a0 with the combat controller and the two NiPoint3 members at offsets 0x14 and 0x70 of the given object, plus the two passed points.
// @fnv 0x009a9370
void __cdecl FUN_009a9370(CombatController* apCombatController, CombatCoverPointData* b, NiPoint3* apPoint1,
                          NiPoint3* apPoint2)
{
    FUN_009a93a0(apCombatController, &b->_14, &b->_70, apPoint1, apPoint2);
}
}  // namespace fnv_009a9370

struct GameSettingCollection;
template <typename T> struct SettingT
{
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting353;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting354;
struct PathingRequest
{
    float GetTargetRadius();
};
struct Standin77900
{
    float FUN_00477900();
};
float __cdecl ComputeExplosionDamageFalloff(float, float, float);
// @fnv 0x009a9720
bool __cdecl IsExplosionRadiusValid(PathingRequest* apExplosion)
{
    if (!apExplosion)
        return false;
    float fdamage = apExplosion->GetTargetRadius();
    if (fdamage < *originalRuntimeFloatSetting353.Float())
        return false;
    float fradius = ((Standin77900*)apExplosion)->FUN_00477900();
    fradius = ComputeExplosionDamageFalloff(fradius, fdamage, *originalRuntimeFloatSetting353.Float());
    if (fradius < *originalRuntimeFloatSetting354.Float())
        return false;
    return true;
}

extern int DAT_011a5590;

// Checks whether bit b of a is set, or whether any bit at offsets -i..i from b (via FUN_009a97b0) is set, for i up to DAT_011a5590.
// @fnv 0x009a9800
char __cdecl IsBitSetOrNeighbor(unsigned int auiMask, char aiBit)
{
    if (auiMask & (1 << aiBit))
        return 1;
    for (int i = 1; i <= DAT_011a5590; ++i)
    {
        char r0 = FUN_009a97b0(aiBit, -i);
        if (auiMask & (1 << r0))
            return 1;
        char r1 = FUN_009a97b0(aiBit, i);
        if (auiMask & (1 << r1))
            return 1;
    }
    return 0;
}

extern int DAT_011a5590;
char FUN_009a97b0(char a1, char a2);

// Sets bit index in flags, then for i from 1 to DAT_011a5590 sets the bits returned by FUN_009a97b0(index, -i) and FUN_009a97b0(index, i), returning flags.
// @fnv 0x009a9940
int ExpandFlagBits(int flags, char index)
{
    flags |= 1 << index;
    for (int i = 1; i <= DAT_011a5590; ++i)
    {
        char r2 = FUN_009a97b0(index, -i);
        flags |= 1 << r2;
        char r1 = FUN_009a97b0(index, i);
        flags |= 1 << r1;
    }
    return flags;
}

struct FUN_00966980_shell
{
    char _pad[0x64];
    float _f64;
    float __thiscall FUN_00966980();
};
// @fnv 0x00966980
float __thiscall FUN_00966980_shell::FUN_00966980()
{
    return ((BGSProjectile*)this)->GetFlag(0x20000) ? 1.0f : this->_f64;
}

struct A69C0Weapon
{
    float GetReachValue();
};

bool __fastcall A69C0IsMeleeWeapon(A69C0Weapon* pkWeapon);
float __cdecl FUN_006463e0(float fValue);

struct A69C0Actor
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual void vfunc22C();
    virtual void vfunc230();
    virtual void vfunc234();
    virtual void vfunc238();
    virtual void vfunc23C();
    virtual void vfunc240();
    virtual void vfunc244();
    virtual void vfunc248();
    virtual void vfunc24C();
    virtual void vfunc250();
    virtual void vfunc254();
    virtual void vfunc258();
    virtual void vfunc25C();
    virtual void vfunc260();
    virtual void vfunc264();
    virtual void vfunc268();
    virtual void vfunc26C();
    virtual void vfunc270();
    virtual void vfunc274();
    virtual void vfunc278();
    virtual void vfunc27C();
    virtual void vfunc280();
    virtual void vfunc284();
    virtual void vfunc288();
    virtual void vfunc28C();
    virtual void vfunc290();
    virtual void vfunc294();
    virtual void vfunc298();
    virtual void vfunc29C();
    virtual void vfunc2A0();
    virtual void vfunc2A4();
    virtual void vfunc2A8();
    virtual void vfunc2AC();
    virtual void vfunc2B0();
    virtual void vfunc2B4();
    virtual void vfunc2B8();
    virtual void vfunc2BC();
    virtual void vfunc2C0();
    virtual void vfunc2C4();
    virtual void vfunc2C8();
    virtual void vfunc2CC();
    virtual void vfunc2D0();
    virtual void vfunc2D4();
    virtual void vfunc2D8();
    virtual void vfunc2DC();
    virtual void vfunc2E0();
    virtual void vfunc2E4();
    virtual void vfunc2E8();
    virtual void vfunc2EC();
    virtual void vfunc2F0();
    virtual void vfunc2F4();
    virtual void vfunc2F8();
    virtual void vfunc2FC();
    virtual void vfunc300();
    virtual void vfunc304();
    virtual void vfunc308();
    virtual void vfunc30C();
    virtual void vfunc310();
    virtual void vfunc314();
    virtual void vfunc318();
    virtual void vfunc31C();
    virtual void vfunc320();
    virtual void vfunc324();
    virtual void vfunc328();
    virtual void vfunc32C();
    virtual void vfunc330();
    virtual void vfunc334();
    virtual void vfunc338();
    virtual void vfunc33C();
    virtual void vfunc340();
    virtual void vfunc344();
    virtual void vfunc348();
    virtual void vfunc34C();
    virtual void vfunc350();
    virtual void vfunc354();
    virtual void vfunc358();
    virtual void vfunc35C();
    virtual void vfunc360();
    virtual void vfunc364();
    virtual void vfunc368();
    virtual void vfunc36C();
    virtual void vfunc370();
    virtual void vfunc374();
    virtual void vfunc378();
    virtual void vfunc37C();
    virtual float GetUnarmedReach();

    float GetScale();
};

// @fnv 0x009a69c0
float __cdecl GetActorReach(A69C0Actor* pkActor, A69C0Weapon* pkWeapon)
{
    float fScale = pkActor->GetScale();
    if (!pkWeapon)
        return pkActor->GetUnarmedReach() * fScale;
    if (!A69C0IsMeleeWeapon(pkWeapon))
        return fScale * 128.0;
    return FUN_006463e0(pkWeapon->GetReachValue()) * fScale;
}

float FUN_004579e0(float);
float FUN_00404010(float, float);
float FUN_0040ebd0(float, float);
float FUN_00755660(float);
extern float runtimeInitializationFloat1935;
// Solves the ballistic trajectory for a launch angle from distance, height, speed and gravity, returning a fallback value when the discriminant is not positive.
// @fnv 0x009a7c60
float ComputeLaunchAngle(float distance, float height, float speed, float gravity, bool lowArc)
{
    float squared = speed * speed;
    float discriminant = squared * squared - (gravity * distance * distance + 2.0 * height * squared) * gravity;
    if (discriminant > 0.0)
    {
        float lower;
        float selected = FUN_004579e0(discriminant);
        float angle = (squared - selected) / (distance * gravity);
        lower = (squared + selected) / (distance * gravity);
        float root;
        if (lowArc)
            root = FUN_00404010(angle, lower);
        else
            root = FUN_0040ebd0(angle, lower);
        float upper = FUN_00755660(root);
        return upper;
    }
    return runtimeInitializationFloat1935 * 0.25;
}

extern "C" double DAT_01012060;
extern "C" float DAT_011f1c00;
struct FUN_009a7f00_obj
{
    float FUN_009a7c40();
    bool FUN_009a7f80() const;
    float FUN_00966980();
    float GetFloatAtOffset68();
};
// Reads a base value; if not flagged, scales arg (or a queried value) squared by a queried value times a constant when above a threshold.
// @fnv 0x009a7f00
float __cdecl FUN_009a7f00(FUN_009a7f00_obj* obj, float arg)
{
    float a = obj->FUN_009a7c40();
    if (obj->FUN_009a7f80())
        return a;
    float value = obj->FUN_00966980();
    if (value <= DAT_01012060)
        return a;
    value *= DAT_011f1c00;
    if (arg == DAT_01012060)
        arg = obj->GetFloatAtOffset68();
    return arg * arg / value;
}

unsigned char FUN_009a97b0(unsigned char a1, unsigned char a2);
bool __cdecl IsBitSetOrNeighbor(unsigned int a, unsigned char b);

// @fnv 0x009a98a0
unsigned char FUN_009a98a0(unsigned int a, unsigned char b)
{
    for (int i = 0; i < DAT_011a558c / 2; i++)
    {
        unsigned char x = FUN_009a97b0(b, i);
        if (!IsBitSetOrNeighbor(a, x))
            return x;
        unsigned char y = FUN_009a97b0(b, -i);
        if (!IsBitSetOrNeighbor(a, y))
            return y;
    }
    return 0xff;
}

struct AlchemyItem
{
    void* FUN_004030b0();
};

struct Actor
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual bool IsValidTarget64();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void* GetSlot116();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual bool IsSlot139(bool abArg);
    virtual void vfunc230();
    virtual void vfunc234();
    virtual void vfunc238();
    virtual void vfunc23C();
    virtual void vfunc240();
    virtual void vfunc244();
    virtual void vfunc248();
    virtual void vfunc24C();
    virtual void vfunc250();
    virtual void vfunc254();
    virtual void vfunc258();
    virtual void vfunc25C();
    virtual void vfunc260();
    virtual void vfunc264();
    virtual void vfunc268();
    virtual void vfunc26C();
    virtual void vfunc270();
    virtual void vfunc274();
    virtual void vfunc278();
    virtual void vfunc27C();
    virtual void vfunc280();
    virtual void vfunc284();
    virtual void vfunc288();
    virtual void vfunc28C();
    virtual void vfunc290();
    virtual void vfunc294();
    virtual void vfunc298();
    virtual void vfunc29C();
    virtual void vfunc2A0();
    virtual void vfunc2A4();
    virtual void vfunc2A8();
    virtual void vfunc2AC();
    virtual void vfunc2B0();
    virtual void vfunc2B4();
    virtual void vfunc2B8();
    virtual void vfunc2BC();
    virtual void vfunc2C0();
    virtual void vfunc2C4();
    virtual void vfunc2C8();
    virtual void vfunc2CC();
    virtual void vfunc2D0();
    virtual void vfunc2D4();
    virtual void vfunc2D8();
    virtual void vfunc2DC();
    virtual void vfunc2E0();
    virtual void vfunc2E4();
    virtual void vfunc2E8();
    virtual void vfunc2EC();
    virtual void vfunc2F0();
    virtual void vfunc2F4();
    virtual void vfunc2F8();
    virtual void vfunc2FC();
    virtual void vfunc300();
    virtual void vfunc304();
    virtual void vfunc308();
    virtual void vfunc30C();
    virtual void vfunc310();
    virtual void vfunc314();
    virtual void vfunc318();
    virtual void vfunc31C();
    virtual void vfunc320();
    virtual void vfunc324();
    virtual void vfunc328();
    virtual void vfunc32C();
    virtual void vfunc330();
    virtual void vfunc334();
    virtual void vfunc338();
    virtual void vfunc33C();
    virtual void vfunc340();
    virtual void vfunc344();
    virtual void vfunc348();
    virtual void vfunc34C();
    virtual void vfunc350();
    virtual void vfunc354();
    virtual void vfunc358();
    virtual void vfunc35C();
    virtual bool IsSlot216();
    virtual void vfunc364();
    virtual void vfunc368();
    virtual void vfunc36C();
    virtual void vfunc370();
    virtual void vfunc374();
    virtual void vfunc378();
    virtual void vfunc37C();
    virtual void vfunc380();
    virtual void vfunc384();
    virtual void vfunc388();
    virtual void vfunc38C();
    virtual void vfunc390();
    virtual void vfunc394();
    virtual void vfunc398();
    virtual void vfunc39C();
    virtual void vfunc3A0();
    virtual void vfunc3A4();
    virtual void vfunc3A8();
    virtual void vfunc3AC();
    virtual void vfunc3B0();
    virtual void vfunc3B4();
    virtual void vfunc3B8();
    virtual void vfunc3BC();
    virtual void vfunc3C0();
    virtual void vfunc3C4();
    virtual void vfunc3C8();
    virtual void vfunc3CC();
    virtual void vfunc3D0();
    virtual void vfunc3D4();
    virtual void vfunc3D8();
    virtual void vfunc3DC();
    virtual void vfunc3E0();
    virtual void vfunc3E4();
    virtual void vfunc3E8();
    virtual void vfunc3EC();
    virtual void vfunc3F0();
    virtual void vfunc3F4();
    virtual void vfunc3F8();
    virtual void vfunc3FC();
    virtual void vfunc400();
    virtual void vfunc404();
    virtual void vfunc408();
    virtual void vfunc40C();
    virtual void vfunc410();
    virtual void vfunc414();
    virtual void vfunc418();
    virtual void vfunc41C();
    virtual void vfunc420();
    virtual void vfunc424();
    virtual struct AlchemyItem* GetSlot266();

    int FUN_00931850();
};

struct ExtraFollower
{
    int unk00;
    int unk04;
    int unk08;
    struct FollowerNode* unk0C;
};

struct FollowerNode
{
    Actor** FUN_006815c0();
    FollowerNode* FUN_00726070();
};

struct FUN_00422700_shell
{
    ExtraFollower* FUN_00422700();
};

struct ExtraDataList;
ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR* ref);

struct TopicInfoArray
{
    unsigned int FUN_005be5c0(int a);
    Actor* FUN_00968670(unsigned int index);
};

struct ContNode;
ContNode* __fastcall FUN_00717e50(void* p);
unsigned int __fastcall FUN_0044ddc0(TESObjectREFR* ref);

struct PlayerStub
{
    bool FUN_0088b880(int a1, Actor* target, int a3, int a4, int a5);
};

float __cdecl FUN_009a64d0(Actor* a, Actor* b, int c);
bool IsTargetInCone(Actor* a, Actor* b, float* outDist);

extern int DAT_011e0e80;
extern int DAT_011f2250;
extern float DAT_01016970;
extern Actor* g_thePlayer;

// @fnv 0x009a60e0
Actor* FUN_009a60e0(Actor* actor, float maxDist)
{
    Actor* target7 = actor->GetSlot266() ? (Actor*)actor->GetSlot266()->FUN_004030b0() : 0;
    if (target7 && IsTargetInCone(actor, target7, 0) && FUN_009a64d0(actor, target7, 1) <= maxDist)
    {
        return target7;
    }
    if (target7)
    {
        return 0;
    }

    Actor* best3 = 0;
    float bestDist3 = DAT_01016970;
    Actor* actorAt4 = 0;
    Actor* cand7 = 0;
    for (unsigned int i = 0; i < ((TopicInfoArray*)FUN_00717e50(&DAT_011e0e80))->FUN_005be5c0(0); i++)
    {
        actorAt4 = ((TopicInfoArray*)FUN_00717e50(&DAT_011e0e80))->FUN_00968670(i);
        if (actorAt4 && actorAt4->IsValidTarget64())
        {
            cand7 = actorAt4;
        }
        else
        {
            cand7 = 0;
        }
        if (FUN_0044ddc0((TESObjectREFR*)&DAT_011f2250) == 4 && cand7 && cand7->IsSlot139(false))
        {
            continue;
        }
        if (cand7 && cand7 != actor && (!cand7->IsSlot139(false) || actor == g_thePlayer) && cand7->GetSlot116() &&
            FUN_009a64d0(actor, cand7, 0) <= maxDist)
        {
            float _dist = DAT_01016970;
            bool aOk = IsTargetInCone(actor, cand7, &_dist);
            if (aOk && _dist <= bestDist3)
            {
                best3 = cand7;
                bestDist3 = _dist;
            }
        }
        if (cand7)
        {
            ExtraFollower* extra_2 = ((FUN_00422700_shell*)FUN_005d43c0((TESObjectREFR*)cand7))->FUN_00422700();
            if (extra_2)
            {
                FollowerNode* nodeB = extra_2->unk0C;
                while (nodeB && *nodeB->FUN_006815c0())
                {
                    Actor* follower = *nodeB->FUN_006815c0();
                    if (follower && !follower->FUN_00931850() && follower != actor &&
                        (!cand7->IsSlot139(false) || actor == g_thePlayer) && follower->GetSlot116() &&
                        FUN_009a64d0(actor, follower, 0) <= maxDist)
                    {
                        float followerDist3 = DAT_01016970;
                        bool followerOk3 = IsTargetInCone(actor, follower, &followerDist3);
                        if (followerOk3 && followerDist3 <= bestDist3)
                        {
                            best3 = follower;
                            bestDist3 = followerDist3;
                        }
                    }
                    nodeB = nodeB->FUN_00726070();
                }
            }
        }
    }

    if (actor != g_thePlayer)
    {
        float playerDist2 = FUN_009a64d0(actor, g_thePlayer, 0);
        float playerLosTmp = DAT_01016970;
        bool playerOk4 = IsTargetInCone(actor, g_thePlayer, &playerLosTmp);
        if (playerDist2 <= maxDist && playerOk4 && playerLosTmp <= bestDist3)
        {
            best3 = g_thePlayer;
        }
    }

    if (best3 && actor->IsSlot216() && !((PlayerStub*)g_thePlayer)->FUN_0088b880(1, best3, 1, 0, 0))
    {
        best3 = 0;
    }
    return best3;
}

struct S_9a64d0_Pt
{
    float x;
    float y;
    float z;
    S_9a64d0_Pt operator-(const S_9a64d0_Pt& rhs) const;
    float Length() const;
};

struct S_9a64d0_Ref
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool IsActor();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual S_9a64d0_Pt GetBoundsMinimum();
    virtual S_9a64d0_Pt GetBoundsMaximum();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual S_9a64d0_Pt* GetPos();
    float GetDistance(S_9a64d0_Ref* other, bool a, bool b);
};

struct S_9a64d0_Actor : S_9a64d0_Ref
{
    bool FUN_005a2030() const;
};

struct S_9a64d0_Setting
{
    float* Float();
};
extern S_9a64d0_Setting DAT_011ce4a0;

float FUN_00408860(float f);
float FUN_009a6770(S_9a64d0_Ref* a, S_9a64d0_Ref* b);

// @fnv 0x009a64d0
float FUN_009a64d0(S_9a64d0_Ref* a, S_9a64d0_Ref* b, bool checkHeight)
{
    float adjust8;
    float dist3;
    if (!b)
        return 0.0f;
    dist3 = a->GetDistance(b, 0, 0);
    if (dist3 == 3.4028234663852886e+38)
        return dist3;
    if (a->IsActor() && b->IsActor())
    {
        S_9a64d0_Actor* pA3 = (S_9a64d0_Actor*)a;
        S_9a64d0_Actor* pB6 = (S_9a64d0_Actor*)b;
        if (pA3 && pB6)
        {
            bool kBoth = pA3->FUN_005a2030() && pB6->FUN_005a2030();
            S_9a64d0_Pt posA9 = *pA3->GetPos();
            S_9a64d0_Pt posB_2 = *pB6->GetPos();
            S_9a64d0_Pt ptA = posA9;
            S_9a64d0_Pt aPtB = posB_2;
            if (kBoth || (checkHeight && FUN_00408860(ptA.z - aPtB.z) >= *DAT_011ce4a0.Float()))
            {
                ptA.z = 0.0f;
                aPtB.z = 0.0f;
                float minATmp = pA3->GetBoundsMaximum().z + posA9.z;
                float maxA4 = pA3->GetBoundsMinimum().z + posA9.z;
                float _minB = pB6->GetBoundsMaximum().z + posB_2.z;
                float maxB3 = pB6->GetBoundsMinimum().z + posB_2.z;
                if ((minATmp <= _minB && minATmp >= maxB3) || (maxA4 <= _minB && maxA4 >= maxB3))
                {
                    S_9a64d0_Pt diff6 = ptA - aPtB;
                    float len3 = diff6.Length();
                    dist3 = len3;
                }
            }
        }
    }
    adjust8 = FUN_009a6770(a, b);
    return dist3 - adjust8;
}

struct S_009a6770_Pt
{
    float x;
    float y;
    float z;
};
struct S_009a6770_Ref
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual bool IsX();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual S_009a6770_Pt* GetPos(S_009a6770_Pt* out);
    float FUN_008be420();
    float GetScale();
};
// Sums a's Y position times its scale (or FUN_008be420 if IsX) with b's same value when b is non-null, returning the total.
// @fnv 0x009a6770
float __cdecl FUN_009a6770(S_009a6770_Ref* pRefA, S_009a6770_Ref* pRefB)
{
    float total2 = 0.0f;
    S_009a6770_Ref* r1;
    S_009a6770_Ref* r2;
    S_009a6770_Pt pt5;
    S_009a6770_Pt pt3;
    if (pRefA->IsX())
    {
        r1 = pRefA;
        total2 = r1->FUN_008be420();
    }
    else
    {
        total2 = pRefA->GetPos(&pt5)->y * pRefA->GetScale();
    }
    if (pRefB)
    {
        if (pRefB->IsX())
        {
            r2 = pRefB;
            total2 = r2->FUN_008be420() + total2;
        }
        else
        {
            total2 = pRefB->GetPos(&pt3)->y * pRefB->GetScale() + total2;
        }
    }
    return total2;
}

struct A6830Actor : A69C0Actor
{
    A69C0Weapon* GetEquippedWeapon();
};

float __cdecl FUN_009a6770(A6830Actor* pkActor, int iType);

// @fnv 0x009a6830
float __cdecl FUN_009a6830(A6830Actor* pkActor, int iType, float afModifier)
{
    float fBase2 = FUN_009a6770(pkActor, iType);
    if (afModifier == -1.0)
        afModifier = GetActorReach(pkActor, pkActor->GetEquippedWeapon());
    float fResult = afModifier * 0.5;
    fResult = fResult + fBase2;
    fResult = FUN_00404010(fResult, 0.0f);
    return fResult;
}

struct S_009a68b0_Pt
{
    float x, y, z;
    S_009a68b0_Pt()
    {}
    S_009a68b0_Pt(float a, float b, float c) : x(a), y(b), z(c)
    {}
    S_009a68b0_Pt FUN_00439ef0(S_009a68b0_Pt* other);
    S_009a68b0_Pt FUN_00439e90(S_009a68b0_Pt* other);
    S_009a68b0_Pt* FUN_00439180(float f);
    void FUN_004a0c10();
};

struct S_009a68b0_Z
{
    float FUN_008e26a0();
};

struct S_009a68b0_Obj
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual bool vfn64();
};

struct S_009a68b0_Ref : TESObjectREFR
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn93();
    virtual void vfn94();
    virtual void vfn95();
    virtual void vfn96();
    virtual void vfn97();
    virtual void vfn98();
    virtual void vfn99();
    virtual void vfn100();
    virtual void vfn101();
    virtual void vfn102();
    virtual void vfn103();
    virtual void vfn104();
    virtual void vfn105();
    virtual void vfn106();
    virtual void vfn107();
    virtual void vfn108();
    virtual void vfn109();
    virtual void vfn110();
    virtual void vfn111();
    virtual void vfn112();
    virtual void vfn113();
    virtual void vfn114();
    virtual void vfn115();
    virtual void vfn116();
    virtual void vfn117();
    virtual void vfn118();
    virtual void vfn119();
    virtual void vfn120();
    virtual void vfn121();
    virtual void vfn122();
    virtual void vfn123();
    virtual void vfn124();
    virtual void vfn125();
    virtual void vfn126();
    virtual void vfn127();
    virtual void vfn128();
    virtual void vfn129();
    virtual void vfn130();
    virtual void vfn131();
    virtual void vfn132();
    virtual void vfn133();
    virtual void vfn134();
    virtual void vfn135();
    virtual void vfn136();
    virtual void vfn137();
    virtual void vfn138();
    virtual void vfn139();
    virtual S_009a68b0_Z* vfn266();
};

extern S_009a68b0_Pt DAT_011f426c;
extern double DAT_01023128;
bool __cdecl AssignCombatPlanAngles(S_009a68b0_Obj* a, S_009a68b0_Ref* b);
float __cdecl FUN_009a6830(S_009a68b0_Ref* a, S_009a68b0_Obj* b, float c);
void __cdecl FUN_004169a0(float a, float* s, float* c);

// @fnv 0x009a68b0
S_009a68b0_Pt FUN_009a68b0(S_009a68b0_Ref* ref, S_009a68b0_Obj* obj, S_009a68b0_Pt* apPoint, float f)
{
    S_009a68b0_Pt dir3 = DAT_011f426c;
    S_009a68b0_Obj* target2 = obj->vfn64() ? obj : 0;
    S_009a68b0_Z* z2 = ref->vfn266();
    if (z2 && target2 && AssignCombatPlanAngles(target2, ref))
    {
        float angle = z2->FUN_008e26a0();
        FUN_004169a0(angle * DAT_01023128, &dir3.x, &dir3.y);
    }
    else
    {
        S_009a68b0_Pt diff = ((S_009a68b0_Pt*)ref->v125())->FUN_00439ef0(apPoint);
        diff.FUN_004a0c10();
    }
    dir3.FUN_00439180(FUN_009a6830(ref, obj, f));
    return apPoint->FUN_00439e90(&dir3);
}

struct ConePoint
{
    float x, y, z;
    ConePoint FUN_00439ef0(const ConePoint& kOther) const;
    float FUN_00457990() const;
};

struct ConeWeaponSkill
{
    int FUN_005f2420();
};
struct ConeWeapon
{
    ConeWeaponSkill* FUN_0048f7f0();
};
struct ConeProcess
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
    virtual void v125();
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
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual ConeWeapon* GetLoadedForm();
};

struct ConeRef
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

    virtual bool IsActor();
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
    virtual const ConePoint& GetPos();
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
    virtual bool IsDead(int i);
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
    virtual float GetCurrentTargetDistance(int i);

    ConeProcess* FUN_008d8520();
};

struct ConePlayer : ConeRef
{
    void* FUN_00950bb0(int i);
    void UpdateAim(int a1, void* pkNode, float* pfX, float* pfY, int a5, float m_fGridOriginX, float afWorldOriginY);
    int FUN_00963730();
};
extern ConePlayer* g_thePlayer_011dea3c;

struct ConeSetting
{
    float* FUN_00403e20();
};
extern ConeSetting g_s_011cfa58;
extern ConeSetting g_s_011cfda4;

float __cdecl FUN_004b1550(ConePoint* pkDir);
void* __cdecl FUN_004aae30(void* pkRoot, const char* pcName);
float __cdecl FUN_00408860(float f);
float __cdecl FUN_00408840(float f);
float __cdecl FUN_009a6a40(int iSkill);

static const char s_szProjectileNode[] = "ProjectileNode";
extern const char g_szConeEnd[] = "";

// Computes the angle between shooter and target, derives a cone threshold from skill or settings, and returns whether the target lies within it.
// @fnv 0x009a6ae0
bool __cdecl IsTargetInCone(ConeRef* pkShooter, ConeRef* pkTarget, float* pfAngleOut)
{
    bool bInConeX = false;
    int iSkillOut = 0x1a;
    if (pkShooter == g_thePlayer_011dea3c && pkShooter->FUN_008d8520() && pkShooter->FUN_008d8520()->GetLoadedForm() &&
        pkShooter->FUN_008d8520()->GetLoadedForm()->FUN_0048f7f0())
        iSkillOut = pkShooter->FUN_008d8520()->GetLoadedForm()->FUN_0048f7f0()->FUN_005f2420();
    ConePoint kDeltaA = pkTarget->GetPos().FUN_00439ef0(pkShooter->GetPos());
    float fHeadingLoc = FUN_004b1550(&kDeltaA);
    float fAimDirectionOffset = 0.0f;
    if (pkShooter == g_thePlayer_011dea3c)
    {
        float fX_2 = 0.0f;
        float fYA = 0.0f;
        void* pkNodeRes = FUN_004aae30(g_thePlayer_011dea3c->FUN_00950bb0(0), s_szProjectileNode);
        g_thePlayer_011dea3c->UpdateAim(0, pkNodeRes, &fX_2, &fYA, 0, 1.175494351e-38F, 1.175494351e-38F);
        if (g_thePlayer_011dea3c->FUN_00963730())
            fAimDirectionOffset = fX_2;
    }
    float fAngleA =
        FUN_00408860(pkShooter->GetCurrentTargetDistance(0) + fAimDirectionOffset - fHeadingLoc) * 57.2957763671875f;
    if (fAngleA > 180.0)
        fAngleA = FUN_00408840(fAngleA - 360.0);
    float fConeTmp = 0.0f;
    if (pkShooter == g_thePlayer_011dea3c)
        fConeTmp = FUN_009a6a40(iSkillOut);
    else
        fConeTmp = *g_s_011cfa58.FUN_00403e20();
    if (kDeltaA.FUN_00457990() < 128.0)
        fConeTmp = fConeTmp * 3.0;
    if (fAngleA <= fConeTmp)
    {
        bInConeX = true;
    }
    else if (pkTarget->IsActor())
    {
        ConeRef* pkActor = pkTarget;
        if (pkActor->IsDead(0))
        {
            fConeTmp = fConeTmp * *g_s_011cfda4.FUN_00403e20();
            if (fAngleA <= fConeTmp)
                bInConeX = true;
        }
    }
    if (pfAngleOut)
        *pfAngleOut = fAngleA;
    return bInConeX;
}

struct S_009a6d70_Point
{
    float x, y, z;
    S_009a6d70_Point()
    {}
    S_009a6d70_Point(const S_009a6d70_Point& o) : x(o.x), y(o.y), z(o.z)
    {}
};
struct S_009a6d70_Actor
{
    float GetAdjustedAngle();
    float FUN_00931d70();
};
S_009a6d70_Point FUN_009a88e0(S_009a6d70_Actor* actor, NiPoint3 target);
float FUN_004b1480(float angle);
float FUN_004b15e0(float from, float to, float* out);
float FUN_00408840(float value);
extern "C" double DAT_0101ff48;
extern "C" double DAT_01011588;

// @fnv 0x009a6d70
bool IsWithinAimLimits(S_009a6d70_Actor* actor, NiPoint3* target, float afMaxHeadingDiff, float afMaxPitchDiff)
{
    S_009a6d70_Point angles4 = FUN_009a88e0(actor, *target);
    if (afMaxHeadingDiff < DAT_0101ff48)
    {
        float heading5 = actor->GetAdjustedAngle();
        angles4.z = FUN_004b1480(angles4.z);
        float signZ5 = 0.0f;
        float diffZ = FUN_00408840(FUN_004b15e0(heading5, angles4.z, &signZ5));
        if (afMaxHeadingDiff * DAT_01011588 < diffZ)
            return false;
    }
    if (afMaxPitchDiff < DAT_0101ff48)
    {
        float pitch4 = actor->FUN_00931d70();
        angles4.x = FUN_004b1480(angles4.x);
        float signX3 = 0.0f;
        float diffX = FUN_00408840(FUN_004b15e0(pitch4, angles4.x, &signX3));
        if (afMaxPitchDiff * DAT_01011588 < diffX)
            return false;
    }
    return true;
}

struct S_009a7670_P3
{
    float x, y, z;
    S_009a7670_P3()
    {}
};
struct S_009a7670_Setting
{
    float* FUN_00403e20();
};
extern S_009a7670_Setting DAT_011cf95c;
extern S_009a7670_Setting DAT_011cfb78;
extern "C" double DAT_0101a6b0;
S_009a7670_P3 FUN_009a8f00(S_009a7670_P3 a, S_009a7670_P3 b, S_009a7670_P3 c, float r, float v, unsigned char flag);
bool FUN_009a6e90(void* a, FUN_009a7f00_obj* obj, float f, S_009a7670_P3 p, S_009a7670_P3 q, int zero, int* found,
                  float* dist);

// @fnv 0x009a7670
bool FUN_009a7670(void* a, int b, FUN_009a7f00_obj* obj, S_009a7670_P3 p1, S_009a7670_P3 p2, S_009a7670_P3 p3,
                  unsigned char* flag, S_009a7670_P3* out, float maxDist)
{
    if (!a || !b)
        return false;
    if (maxDist == DAT_0101a6b0)
        maxDist = *DAT_011cf95c.FUN_00403e20();
    float dist8 = 0.0f;
    int found = 0;
    float v = obj->FUN_00966980() * DAT_011f1c00;
    if (v == DAT_01012060)
    {
        S_009a7670_P3 hit = FUN_009a8f00(p1, p2, p3, obj->GetFloatAtOffset68(), v, *flag);
        bool ok = FUN_009a6e90(a, obj, 0, p1, hit, 0, &found, &dist8);
        if (ok && found != b && dist8 < maxDist)
            return false;
        *out = hit;
        return true;
    }
    unsigned char saved = *flag;
    for (unsigned int i = 0; i < 2; i++)
    {
        if (i == 1)
            *flag = *flag ? 0 : 1;
        float k;
        if (*flag)
            k = *DAT_011cfb78.FUN_00403e20();
        else
            k = 1.0f;
        float r2 = obj->GetFloatAtOffset68() * k;
        bool ok;
        S_009a7670_P3 point = FUN_009a8f00(p1, p2, p3, r2, v, *flag);
        ok = FUN_009a6e90(a, obj, r2, p1, point, 0, &found, &dist8);
        if (!ok || found == b || dist8 > maxDist)
        {
            *out = point;
            return true;
        }
    }
    *flag = saved;
    return false;
}

struct Vec3
{
    float x;
    float y;
    float z;
    Vec3 FUN_00439ef0(const Vec3& b) const;
    float FUN_00589850() const;
    float FUN_00457990() const;
};

struct GlobalSetting
{
    float* FUN_00403e20();
};
extern GlobalSetting g_011cfb78;

struct ShotActor
{
    float GetFloatAtOffset68();
    float FUN_00966980();
};

// @fnv 0x009a7e00
float __cdecl ComputeProjectileFlightTime(ShotActor* actor, Vec3 from, Vec3 to, bool flag, float speed)
{
    Vec3 vDelta = from.FUN_00439ef0(to);
    float fVel = speed;
    if (speed == DAT_01012060)
    {
        fVel = actor->GetFloatAtOffset68();
    }
    if (actor->FUN_00966980() != DAT_01012060)
    {
        if (flag && speed == DAT_01012060)
        {
            speed = speed * *g_011cfb78.FUN_00403e20();
        }
        float fAngleDifference = vDelta.z;
        float afGravity = vDelta.FUN_00589850();
        float m_fGlyphExtent =
            ComputeLaunchAngle(afGravity, fAngleDifference, speed, actor->FUN_00966980() * DAT_011f1c00, false);
        return FUN_009a7dd0(afGravity, m_fGlyphExtent, fVel);
    }
    return vDelta.FUN_00457990() / speed;
}

extern "C" double DAT_0101de30;
extern "C" double DAT_01011588;

struct FUN_009a7fa0_cls
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
    virtual bool v64();
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
    virtual NiPoint3* v118(NiPoint3* out);
    virtual NiPoint3* v119(NiPoint3* out);
    bool IsFlagged();
    float ScaleZero();
    float ScaleOne(int flag);
};

// Returns a scaled value from the object's scale methods when v64() is set, otherwise the z-difference between v119 and v118 times DAT_01011588.
// @fnv 0x009a7fa0
float __cdecl GetScaleOrHeightDelta(TESObjectREFR* apRefr, int aiFlag)
{
    float fBase;
    FUN_009a7fa0_cls* selfX;
    NiPoint3 vAbove;
    NiPoint3 kVBelow;
    float fValue8;
    float fScaled5;
    float fDeltaA;

    if (reinterpret_cast<FUN_009a7fa0_cls*>(apRefr)->v64())
    {
        selfX = reinterpret_cast<FUN_009a7fa0_cls*>(apRefr);
        if (selfX->IsFlagged() && (unsigned char)aiFlag == 0)
        {
            fValue8 = selfX->ScaleOne(0);
        }
        else
        {
            fValue8 = selfX->ScaleZero();
        }
        fBase = fValue8;
        fScaled5 = fBase * DAT_0101de30;
        return fScaled5;
    }

    fDeltaA = (reinterpret_cast<FUN_009a7fa0_cls*>(apRefr)->v119(&vAbove)->z -
               reinterpret_cast<FUN_009a7fa0_cls*>(apRefr)->v118(&kVBelow)->z) *
              DAT_01011588;
    return fDeltaA;
}

struct S_009a82b0_Point3
{
    float x;
    float y;
    float z;
    S_009a82b0_Point3();
};

struct S_009a82b0_Point2
{
    float x;
    float y;
    S_009a82b0_Point2();
    S_009a82b0_Point2(float ax, float ay);
    float Dot(const S_009a82b0_Point2& o) const;
    float Length() const;
};

struct S_009a82b0_Ref
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual bool IsActor();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual S_009a82b0_Point3* GetPos();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual void vfunc22C();
    virtual void vfunc230();
    virtual void vfunc234();
    virtual void vfunc238();
    virtual void vfunc23C();
    virtual void vfunc240();
    virtual void vfunc244();
    virtual void vfunc248();
    virtual void vfunc24C();
    virtual void vfunc250();
    virtual void vfunc254();
    virtual void vfunc258();
    virtual void vfunc25C();
    virtual void vfunc260();
    virtual void vfunc264();
    virtual void vfunc268();
    virtual void vfunc26C();
    virtual void vfunc270();
    virtual void vfunc274();
    virtual void vfunc278();
    virtual void vfunc27C();
    virtual void vfunc280();
    virtual void vfunc284();
    virtual void vfunc288();
    virtual void vfunc28C();
    virtual void vfunc290();
    virtual void vfunc294();
    virtual void vfunc298();
    virtual void vfunc29C();
    virtual void vfunc2A0();
    virtual void vfunc2A4();
    virtual void vfunc2A8();
    virtual void vfunc2AC();
    virtual void vfunc2B0();
    virtual void vfunc2B4();
    virtual void vfunc2B8();
    virtual float GetCurrentTargetDistance(int a);
    float FUN_00931d70() const;
};

void FUN_004169a0(float angle, float& s, float& c);
S_009a82b0_Point3 FUN_009a8050(S_009a82b0_Ref* apRef);
extern "C" double DAT_01030f38;

// Local names were chosen so the /Od stack slots land where the original has them.
// @fnv 0x009a82b0
S_009a82b0_Point3 GetAdjustedPosition(S_009a82b0_Ref* apRef)
{
    S_009a82b0_Point3 kPos = FUN_009a8050(apRef);
    if (apRef->IsActor())
    {
        S_009a82b0_Ref* pWho = apRef;
        S_009a82b0_Point3 kStart = *pWho->GetPos();
        float fFacing = pWho->GetCurrentTargetDistance(0);
        float fSinYaw = 0.0f;
        float fYawCos = 0.0f;
        FUN_004169a0(fFacing + DAT_01030f38, fSinYaw, fYawCos);
        S_009a82b0_Point2 kAim(fSinYaw, fYawCos);
        S_009a82b0_Point2 kDelta(kPos.x - kStart.x, kPos.y - kStart.y);
        float fProjectionAlongAim = kDelta.Dot(kAim);
        S_009a82b0_Point2 kProjected;
        kProjected.x = kAim.x * fProjectionAlongAim + kStart.x;
        kProjected.y = kAim.y * fProjectionAlongAim + kStart.y;
        float fLook = pWho->FUN_00931d70();
        float fLookSin = 0.0f;
        float fB = 0.0f;
        FUN_004169a0(fLook, fLookSin, fB);
        S_009a82b0_Point2 kToPoint(kPos.x - kProjected.x, kPos.y - kProjected.y);
        float fHoriz = kToPoint.Length();
        float fDZ = fHoriz * fLookSin / fB;
        kPos.x = kProjected.x;
        kPos.y = kProjected.y;
        kPos.z += fDZ;
    }
    return kPos;
}

struct S_009a8460_Actor
{
    virtual void unk_000();
    virtual void unk_001();
    virtual void unk_002();
    virtual void unk_003();
    virtual void unk_004();
    virtual void unk_005();
    virtual void unk_006();
    virtual void unk_007();
    virtual void unk_008();
    virtual void unk_009();
    virtual void unk_010();
    virtual void unk_011();
    virtual void unk_012();
    virtual void unk_013();
    virtual void unk_014();
    virtual void unk_015();
    virtual void unk_016();
    virtual void unk_017();
    virtual void unk_018();
    virtual void unk_019();
    virtual void unk_020();
    virtual void unk_021();
    virtual void unk_022();
    virtual void unk_023();
    virtual void unk_024();
    virtual void unk_025();
    virtual void unk_026();
    virtual void unk_027();
    virtual void unk_028();
    virtual void unk_029();
    virtual void unk_030();
    virtual void unk_031();
    virtual void unk_032();
    virtual void unk_033();
    virtual void unk_034();
    virtual void unk_035();
    virtual void unk_036();
    virtual void unk_037();
    virtual void unk_038();
    virtual void unk_039();
    virtual void unk_040();
    virtual void unk_041();
    virtual void unk_042();
    virtual void unk_043();
    virtual void unk_044();
    virtual void unk_045();
    virtual void unk_046();
    virtual void unk_047();
    virtual void unk_048();
    virtual void unk_049();
    virtual void unk_050();
    virtual void unk_051();
    virtual void unk_052();
    virtual void unk_053();
    virtual void unk_054();
    virtual void unk_055();
    virtual void unk_056();
    virtual void unk_057();
    virtual void unk_058();
    virtual void unk_059();
    virtual void unk_060();
    virtual void unk_061();
    virtual void unk_062();
    virtual void unk_063();
    virtual bool vfn_0100();
    virtual void unk_065();
    virtual void unk_066();
    virtual void unk_067();
    virtual void unk_068();
    virtual void unk_069();
    virtual void unk_070();
    virtual void unk_071();
    virtual void unk_072();
    virtual void unk_073();
    virtual void unk_074();
    virtual void unk_075();
    virtual void unk_076();
    virtual void unk_077();
    virtual void unk_078();
    virtual void unk_079();
    virtual void unk_080();
    virtual void unk_081();
    virtual void unk_082();
    virtual void unk_083();
    virtual void unk_084();
    virtual void unk_085();
    virtual void unk_086();
    virtual void unk_087();
    virtual void unk_088();
    virtual void unk_089();
    virtual void unk_090();
    virtual void unk_091();
    virtual void unk_092();
    virtual void unk_093();
    virtual void unk_094();
    virtual void unk_095();
    virtual void unk_096();
    virtual void unk_097();
    virtual void unk_098();
    virtual void unk_099();
    virtual void unk_100();
    virtual void unk_101();
    virtual void unk_102();
    virtual void unk_103();
    virtual void unk_104();
    virtual void unk_105();
    virtual void unk_106();
    virtual void unk_107();
    virtual void unk_108();
    virtual void unk_109();
    virtual void unk_110();
    virtual void unk_111();
    virtual void unk_112();
    virtual void unk_113();
    virtual void unk_114();
    virtual void unk_115();
    virtual void unk_116();
    virtual void unk_117();
    virtual NiPoint3* vfn_01d8(NiPoint3* p);
    virtual NiPoint3* vfn_01dc(NiPoint3* p);
    virtual void unk_120();
    virtual void unk_121();
    virtual void unk_122();
    virtual void unk_123();
    virtual void unk_124();
    virtual void unk_125();
    virtual void unk_126();
    virtual void unk_127();
    virtual void unk_128();
    virtual void unk_129();
    virtual void unk_130();
    virtual void unk_131();
    virtual void unk_132();
    virtual void unk_133();
    virtual void unk_134();
    virtual void unk_135();
    virtual void unk_136();
    virtual void unk_137();
    virtual void unk_138();
    virtual bool vfn_022c(int p);
    virtual bool vfn_0230();

    bool __thiscall FUN_004997b0();
    float __thiscall FUN_008854d0(int p);
    float __thiscall GetActorHeight();
    bool __thiscall FUN_00579670();
    float __thiscall GetScale();
};

// @fnv 0x009a8460
float __cdecl FUN_009a8460(S_009a8460_Actor* actor, int type, bool flag)
{
    float f;
    S_009a8460_Actor* act;
    bool b;

    if (actor->vfn_0100())
    {
        act = actor;
        b = act->FUN_004997b0() && !flag;
        f = b ? act->FUN_008854d0(0) : act->GetActorHeight();

        if (act->vfn_0230() || act->FUN_00579670() || act->vfn_022c(0))
        {
            return f * 0.1f;
        }

        switch (type)
        {
        case 2:
            return (float)(b ? f * 0.9f : f * 0.75f);
            break;
        case 1:
        case 3:
            return f * 0.5f;
            break;
        case 0:
            return f * 0.25f;
            break;
        default:
            break;
        }
    }
    else
    {
        NiPoint3 p2;
        NiPoint3 p1;
        return (actor->vfn_01dc(&p2)->z - actor->vfn_01d8(&p1)->z) * actor->GetScale() * 0.5f;
    }

    return 0.0f;
}

extern float DAT_011a5594;

struct NiVecOps
{
    void __thiscall FUN_00439ef0(NiPoint3* tmp, NiPoint3* src);
    float __thiscall FUN_004a7290();
    NiPoint3* __thiscall ApplyScaled(NiPoint3* out, float scale);
    NiPoint3* __thiscall FUN_00439e90(NiPoint3* tmp, NiPoint3* ret);
};

void __cdecl GetPitchYaw(NiPoint3* out, NiPoint3 a, NiPoint3 b);

// @fnv 0x009a8970
NiPoint3* __cdecl FUN_009a8970(NiPoint3* out, NiPoint3 a, NiPoint3 b, float afUnused, NiPoint3 c)
{
    NiPoint3 tmp;
    float t3;
    float s2;
    NiPoint3 r8;
    NiPoint3 r3;

    if (a.x == b.x && a.y == b.y)
    {
        GetPitchYaw(out, a, c);
        return out;
    }

    reinterpret_cast<NiVecOps*>(&c)->FUN_00439ef0(&tmp, &b);
    t3 = reinterpret_cast<NiVecOps*>(&tmp)->FUN_004a7290();

    if ((double)t3 == DAT_01012060)
    {
        GetPitchYaw(out, a, c);
        return out;
    }

    if (t3 < DAT_011a5594 * DAT_011a5594)
    {
        s2 = FUN_004579e0(t3);
        c = *reinterpret_cast<NiVecOps*>(&b)->FUN_00439e90(
            &r3, reinterpret_cast<NiVecOps*>(&tmp)->ApplyScaled(&r8, DAT_011a5594 / s2));
    }

    GetPitchYaw(out, a, c);
    return out;
}

struct TrajAux
{
    int GetPackageRefCount();
};
struct TrajRef
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
    virtual bool v64();
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
    virtual void v125();
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
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual TrajAux* v266();
};

struct TrajOut;
struct TrajVec
{
    float x;
    float y;
    float z;
};
struct TrajWeapon
{
    float FUN_00477900();
    float FUN_006a78f0();
};
struct TrajActor
{
    float FUN_00966980();
    bool FUN_009a7f80() const;
    float GetFloatAtOffset68();
    TrajWeapon* FUN_004fd3c0();
};

void __cdecl GetTargetLocationWithOffset(TrajVec* out, void* a3, int mode);
void __cdecl GetTriple12(TrajVec* out, void* a3);
void __cdecl FUN_009a8df0(TrajOut* out, TrajRef* target, TrajVec p, TrajVec q, void* a4, TrajActor* actor, float speed,
                          bool flag);

extern "C" double DAT_01012060;
extern "C" int DAT_011cebd4;
extern "C" int DAT_011cf270;
extern "C" int DAT_011ceb5c;

// Selects a trajectory mode from the target's auxiliary data and the actor's weapon/state, computes two vectors from a3, and delegates to FUN_009a8df0.
// @fnv 0x009a8bf0
TrajOut* __cdecl ComputeTrajectory(TrajOut* out, TrajRef* target, void* a3, void* a4, TrajActor* actor, float speed,
                                   bool flag)
{
    int mode = 1;
    if (target->v64())
    {
        TrajRef* obj5 = target;
        TrajAux* aux5 = obj5->v266();
        if (aux5 != 0)
        {
            mode = aux5->GetPackageRefCount();
        }
    }

    if (flag && actor->FUN_00966980() != DAT_01012060)
    {
        mode = 2;
    }
    else
    {
        bool f5;
        TrajWeapon* w2 = actor->FUN_004fd3c0();
        f5 = false;
        if (actor->FUN_009a7f80() || (double)actor->GetFloatAtOffset68() >
                                         *reinterpret_cast<SettingT<GameSettingCollection>*>(&DAT_011cebd4)->Float())
        {
            f5 = true;
        }
        if (w2 != 0)
        {
            if ((double)w2->FUN_00477900() >=
                *reinterpret_cast<SettingT<GameSettingCollection>*>(&DAT_011cf270)->Float())
            {
                if (!f5)
                {
                    if ((double)w2->FUN_006a78f0() >
                        *reinterpret_cast<SettingT<GameSettingCollection>*>(&DAT_011ceb5c)->Float())
                    {
                        mode = 4;
                    }
                }
            }
        }
    }

    TrajVec t3;
    GetTargetLocationWithOffset(&t3, a3, mode);
    TrajVec t2;
    GetTriple12(&t2, a3);
    FUN_009a8df0(out, target, t3, t2, a4, actor, speed, flag);
    return out;
}

namespace fnv_009a8d80 {
struct S_009a8d80_P3
{
    float x;
    float y;
    float z;
    S_009a8d80_P3()
    {}
    S_009a8d80_P3(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
    }
};
extern S_009a8d80_P3 DAT_011f426c;
struct S_009a8d80_Obj;
S_009a8d80_P3 __cdecl FUN_009a8df0(TESObjectREFR* a1, S_009a8d80_P3 a2, S_009a8d80_P3 a3, S_009a8d80_Obj* a4,
                                   BGSProjectile* a5, float a6, bool a7);
// Forwards the reference, the point dereferenced from a2, DAT_011f426c, a3, a4, a5 and a6 to FUN_009a8df0 and returns its result.
// @fnv 0x009a8d80
S_009a8d80_P3 __cdecl FUN_009a8d80(TESObjectREFR* a1, const S_009a8d80_P3* pPoint, S_009a8d80_Obj* a3,
                                   BGSProjectile* a4, float a5, bool a6)
{
    return FUN_009a8df0(a1, *pPoint, DAT_011f426c, a3, a4, a5, a6);
}
}  // namespace fnv_009a8d80

struct FUN_009a8df0_vec
{
    void FUN_006815c0();
    float x;
    float y;
    float z;
};

FUN_009a8df0_vec* __cdecl FUN_009a8050(FUN_009a8df0_vec* tmp, int a);
void __cdecl FUN_009a8f00(FUN_009a8df0_vec* out, FUN_009a8df0_vec c, FUN_009a8df0_vec b, FUN_009a8df0_vec a, float f1,
                          float f2, unsigned char flag);

// @fnv 0x009a8df0
FUN_009a8df0_vec* __cdecl FUN_009a8df0(FUN_009a8df0_vec* out, int a2, FUN_009a8df0_vec vecB, FUN_009a8df0_vec vecA,
                                       FUN_009a8df0_vec* p28, FUN_009a7f00_obj* obj, float a30, unsigned char a34)
{
    float f;
    FUN_009a8df0_vec L;

    if (obj->FUN_009a7f80())
    {
        *out = vecB;
        return out;
    }
    L.FUN_006815c0();
    if (p28 != 0)
    {
        L = *p28;
    }
    else
    {
        FUN_009a8df0_vec T;
        L = *FUN_009a8050(&T, a2);
    }
    f = obj->FUN_00966980() * DAT_011f1c00;
    if ((double)a30 == DAT_01012060)
    {
        a30 = obj->GetFloatAtOffset68();
    }
    FUN_009a8f00(out, L, vecB, vecA, a30, f, a34);
    return out;
}

struct AimPoint
{
    float x, y, z;
    AimPoint FUN_00439ef0(const AimPoint& kOther) const;
    AimPoint FUN_00439e90(const AimPoint& kOther) const;
    AimPoint ApplyScaled(float fScale) const;
    float FUN_00457990() const;
};

struct AimIntSetting
{
    int* FUN_0043d4d0();
};
extern AimIntSetting g_s_011cfc08;

float __cdecl ComputeLaunchAngle(float fDist, float m_fGlyphExtent, float fSpeed, float afGravity, bool bArc);
float __cdecl FUN_009a7dd0(float fDist, float fAngleDifference, float fSpeed);
float __cdecl FUN_0057dd70(float fAngleDifference);

// @fnv 0x009a8f00
AimPoint __cdecl FUN_009a8f00(AimPoint kTarget, AimPoint kStart, AimPoint kMotionVelocity, float fSpeed,
                              float afGravity, bool bArc)
{
    int iIterationsVal2 = *g_s_011cfc08.FUN_0043d4d0();
    if (kMotionVelocity.x == 0.0 && kMotionVelocity.y == 0.0 && kMotionVelocity.z == 0.0)
        iIterationsVal2 = 1;
    float kFTime = 0.0f;
    AimPoint kPos4 = kStart;
    if (afGravity == 0.0)
    {
        float fDist = 0.0f;
        for (int i = 0; i < iIterationsVal2; i++)
        {
            AimPoint kDiff = kPos4.FUN_00439ef0(kTarget);
            fDist = kDiff.FUN_00457990();
            if (fDist < 1.0 || fDist > 8192.0)
                break;
            kFTime = fDist / fSpeed;
            kPos4 = kStart.FUN_00439e90(kMotionVelocity.ApplyScaled(kFTime));
        }
    }
    else
    {
        float fHorizDistX = 0.0f;
        float kFHeight = 0.0f;
        float fAngleTmp = 0.0f;
        for (int j = 0; j < iIterationsVal2; j++)
        {
            AimPoint kDelta = kPos4.FUN_00439ef0(kTarget);
            kFHeight = kDelta.z;
            kDelta.z = 0.0f;
            fHorizDistX = kDelta.FUN_00457990();
            if (kFHeight > 8192.0 || fHorizDistX < 1.0 || fHorizDistX > 8192.0)
                break;
            fAngleTmp = ComputeLaunchAngle(fHorizDistX, kFHeight, fSpeed, afGravity, bArc);
            kFTime = FUN_009a7dd0(fHorizDistX, fAngleTmp, fSpeed);
            kPos4 = kStart.FUN_00439e90(kMotionVelocity.ApplyScaled(kFTime));
        }
        AimPoint kFlatVal2 = kPos4.FUN_00439ef0(kTarget);
        kFlatVal2.z = 0.0f;
        fHorizDistX = kFlatVal2.FUN_00457990();
        kPos4.z = FUN_0057dd70(fAngleTmp) * fHorizDistX + kTarget.z;
    }
    return kPos4;
}

struct S_009a9180_Weapon
{
    float FUN_009a9350();
    float FUN_00508050();
};

struct S_009a9180_Actor
{
    S_009a9180_Weapon* FUN_00980070();
    int GetFieldBC();
};

struct S_009a9180_Projectile : FUN_009a7f00_obj
{
    Standin77900* FUN_004fd3c0();
};

struct S_009a9180_Data
{
    float GetFloatAt120();
    float GetField124Float();
    bool IsFlag20Set();
    S_009a9180_Projectile* GetOrFallback(int key);
};

struct S_009a9180_Setting
{
    float* FUN_00403e20();
};

extern S_009a9180_Setting DAT_011ce87c;
extern S_009a9180_Setting DAT_011ceab0;

// @fnv 0x009a9180
void FUN_009a9180(S_009a9180_Actor* pActor, S_009a9180_Data* pData, float* pfMin, float* pfMax, float* pfDerived)
{
    *pfMin = 512.0f;
    *pfMax = 1024.0f;
    S_009a9180_Weapon* pWeapon = pActor->FUN_00980070();
    if (pData)
    {
        *pfMin = pData->GetFloatAt120();
        *pfMax = pData->GetField124Float();
        if (!pData->IsFlag20Set())
        {
            *pfMin = pWeapon->FUN_009a9350() * *pfMin;
            *pfMax = pWeapon->FUN_00508050() * *pfMax;
        }
        *pfDerived = *pfMax * *DAT_011ce87c.FUN_00403e20();
        S_009a9180_Projectile* pObj = pData->GetOrFallback(pActor->GetFieldBC());
        if (pObj)
        {
            float fValue = FUN_009a7f00(pObj, 0.0f);
            *pfMax = FUN_0040ebd0(*pfMax, fValue * *DAT_011ceab0.FUN_00403e20());
            *pfDerived = FUN_0040ebd0(*pfDerived, fValue);
            Standin77900* pProjectile = pObj->FUN_004fd3c0();
            if (pProjectile)
                *pfMin = FUN_00404010(*pfMin, pProjectile->FUN_00477900());
            *pfMin = FUN_0040ebd0(*pfMin, *pfMax - 256.0);
            *pfMin = FUN_00404010(*pfMin, 0.0f);
        }
    }
    else
    {
        *pfMin = pWeapon->FUN_009a9350() * *pfMin;
        *pfMax = pWeapon->FUN_00508050() * *pfMax;
        *pfDerived = *pfMax * *DAT_011ce87c.FUN_00403e20();
    }
}

struct DebugPoint
{
    float x;
    float y;
    float z;
    DebugPoint FUN_00439ef0(const DebugPoint& kPt) const;
    DebugPoint ApplyScaled(float fScale) const;
    DebugPoint FUN_00439e90(const DebugPoint& kPt) const;
};

class RgbaColor
{
  public:
    float r;
    float g;
    float b;
    float a;
    RgbaColor(float fR, float fG, float fB, float fA);
};

struct NiAVObject
{
    void FUN_00a5a040();
    void FUN_00440460(const DebugPoint& kPt);
};

class TES
{
  public:
    void FUN_00458e20(NiAVObject* pkObject, float fTime);
};
extern TES* g_TES;

class GlobalObject_0044f440
{
  public:
    float* Float();
};
extern GlobalObject_0044f440 g_011f1c24;

NiAVObject* __cdecl FUN_004b3890(const DebugPoint& kStart, const RgbaColor& kStartColor, const DebugPoint& kEnd,
                                 const RgbaColor& kEndColor, bool bArg);
NiAVObject* __cdecl CreateOctahedron(float fRadius, const RgbaColor& kColor, bool bArg);

// @fnv 0x009a9f20
void __cdecl DrawDebugLine(const DebugPoint& kStart, const DebugPoint& kEnd, int bScaled, float fScale,
                           const RgbaColor* pkLineColor, const RgbaColor* pkTipColor)
{
    RgbaColor aKTipColor = pkTipColor ? *pkTipColor : RgbaColor(1.0f, 0.0f, 0.0f, 1.0f);
    RgbaColor kLineColor6 = pkLineColor ? *pkLineColor : RgbaColor(1.0f, 1.0f, 0.0f, 1.0f);
    DebugPoint kMid = bScaled ? (kEnd.FUN_00439ef0(kStart)).ApplyScaled(fScale).FUN_00439e90(kStart) : kEnd;
    NiAVObject* pkLine_ = FUN_004b3890(kStart, kLineColor6, kMid, kLineColor6, true);
    g_TES->FUN_00458e20(pkLine_, *g_011f1c24.Float());
    if (bScaled)
    {
        NiAVObject* pkSphere4 = CreateOctahedron(5.0f, aKTipColor, true);
        pkSphere4->FUN_00a5a040();
        pkSphere4->FUN_00440460(kMid);
        g_TES->FUN_00458e20(pkSphere4, *g_011f1c24.Float());
        NiAVObject* pkTipLine = FUN_004b3890(kMid, aKTipColor, kEnd, aKTipColor, true);
        g_TES->FUN_00458e20(pkTipLine, *g_011f1c24.Float());
    }
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting595;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting604;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting605;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting606;

// Returns the float value of one of four runtime float settings, chosen by id in the range 0x5c-0x66; ids outside that range use the default setting.
// @fnv 0x009a6a40
float __cdecl FUN_009a6a40(int aiSettingId)
{
    if (aiSettingId >= 0x5c && aiSettingId <= 0x66)
    {
        switch (aiSettingId)
        {
        case 0x5c:
        case 0x5d:
            return *originalRuntimeFloatSetting605.Float();
            break;
        case 0x5e:
        case 0x5f:
        case 0x60:
            return *originalRuntimeFloatSetting604.Float();
            break;
        case 0x61:
            return *originalRuntimeFloatSetting606.Float();
            break;
        default:
            return *originalRuntimeFloatSetting595.Float();
        }
    }
    else
    {
        return *originalRuntimeFloatSetting595.Float();
    }
}

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3 __thiscall FUN_00439ef0(const Pt3& rhs);
};

struct CombatPlanningPosition
{
    Pt3 origin;
    unsigned int count;
};

struct Effect
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int GetType();
};

struct CombatPlan
{
    Effect* __thiscall FUN_004fd3e0();
    bool __thiscall FUN_00981940(int a);
    void __thiscall SetFieldE0(float f);
};

struct Ref;
struct Holder
{
    Ref** __thiscall FUN_006a7ad0(int i);
    unsigned int __thiscall FUN_0044ddc0();
};

struct Ref
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int v73();
    virtual int v74();
    virtual int v75();
    virtual int v76();
    virtual int v77();
    virtual int v78();
    virtual int v79();
    virtual int v80();
    virtual int v81();
    virtual int v82();
    virtual int v83();
    virtual int v84();
    virtual int v85();
    virtual int v86();
    virtual int v87();
    virtual int v88();
    virtual int v89();
    virtual int v90();
    virtual int v91();
    virtual int v92();
    virtual int v93();
    virtual int v94();
    virtual int v95();
    virtual int v96();
    virtual int v97();
    virtual int v98();
    virtual int v99();
    virtual int v100();
    virtual int v101();
    virtual int v102();
    virtual int v103();
    virtual int v104();
    virtual int v105();
    virtual int v106();
    virtual int v107();
    virtual int v108();
    virtual int v109();
    virtual int v110();
    virtual int v111();
    virtual int v112();
    virtual int v113();
    virtual int v114();
    virtual int v115();
    virtual int v116();
    virtual int v117();
    virtual int v118();
    virtual int v119();
    virtual int v120();
    virtual int v121();
    virtual int v122();
    virtual int v123();
    virtual int v124();
    virtual int v125();
    virtual int v126();
    virtual int v127();
    virtual int v128();
    virtual int v129();
    virtual int v130();
    virtual int v131();
    virtual int v132();
    virtual int v133();
    virtual int v134();
    virtual int v135();
    virtual int v136();
    virtual int v137();
    virtual int v138();
    virtual int v139();
    virtual int v140();
    virtual int v141();
    virtual int v142();
    virtual int v143();
    virtual int v144();
    virtual int v145();
    virtual int v146();
    virtual int v147();
    virtual int v148();
    virtual int v149();
    virtual int v150();
    virtual int v151();
    virtual int v152();
    virtual int v153();
    virtual int v154();
    virtual int v155();
    virtual int v156();
    virtual int v157();
    virtual int v158();
    virtual int v159();
    virtual int v160();
    virtual int v161();
    virtual int v162();
    virtual int v163();
    virtual int v164();
    virtual int v165();
    virtual int v166();
    virtual int v167();
    virtual int v168();
    virtual int v169();
    virtual int v170();
    virtual int v171();
    virtual int v172();
    virtual int v173();
    virtual int v174();
    virtual int v175();
    virtual int v176();
    virtual int v177();
    virtual int v178();
    virtual int v179();
    virtual int v180();
    virtual int v181();
    virtual int v182();
    virtual int v183();
    virtual int v184();
    virtual int v185();
    virtual int v186();
    virtual int v187();
    virtual int v188();
    virtual int v189();
    virtual int v190();
    virtual int v191();
    virtual int v192();
    virtual int v193();
    virtual int v194();
    virtual int v195();
    virtual int v196();
    virtual int v197();
    virtual int v198();
    virtual int v199();
    virtual int v200();
    virtual int v201();
    virtual int v202();
    virtual int v203();
    virtual int v204();
    virtual int v205();
    virtual int v206();
    virtual int v207();
    virtual int v208();
    virtual int v209();
    virtual int v210();
    virtual int v211();
    virtual int v212();
    virtual int v213();
    virtual int v214();
    virtual int v215();
    virtual int v216();
    virtual int v217();
    virtual int v218();
    virtual int v219();
    virtual int v220();
    virtual int v221();
    virtual int v222();
    virtual int v223();
    virtual int v224();
    virtual int v225();
    virtual int v226();
    virtual int v227();
    virtual int v228();
    virtual int v229();
    virtual int v230();
    virtual int v231();
    virtual int v232();
    virtual int v233();
    virtual int v234();
    virtual int v235();
    virtual int v236();
    virtual int v237();
    virtual int v238();
    virtual int v239();
    virtual int v240();
    virtual int v241();
    virtual int v242();
    virtual int v243();
    virtual int v244();
    virtual int v245();
    virtual int v246();
    virtual int v247();
    virtual int v248();
    virtual int v249();
    virtual int v250();
    virtual int v251();
    virtual int v252();
    virtual int v253();
    virtual int v254();
    virtual int v255();
    virtual int v256();
    virtual int v257();
    virtual int v258();
    virtual int v259();
    virtual int v260();
    virtual int v261();
    virtual int v262();
    virtual int v263();
    virtual int v264();
    virtual int v265();
    virtual CombatPlan* GetCombatPlan();
    Pt3* __thiscall FUN_00436aa0();
};

struct Mgr
{
    Holder* __thiscall FUN_009a4250(Ref* a);
};

struct Glob
{
    Mgr* __thiscall FUN_00441110();
};

struct FUN_006d5320
{
    CombatPlan* obj;
    Pt3 pos;
    float angle;
    char dir;
    unsigned char flag;
    FUN_006d5320();
};

void __cdecl FUN_00403d30(void* p, int v, unsigned int n);
extern Glob* DAT_011f1958;
unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
float __cdecl GetDirectionAngle(const Pt3& p);
long __cdecl ScaleByRatio(float a);
float __cdecl ScaleCharToFloat(char a);
unsigned char FUN_009a98a0(unsigned int a, unsigned char b);
int ExpandFlagBits(int flags, char index);

// @fnv 0x009a9a20
bool AssignCombatPlanAngles(Ref* apRef, Ref* apTargetRef)
{
    bool result;
    result = false;
    if (apRef == 0)
        return result;
    Holder* ptr = DAT_011f1958->FUN_00441110()->FUN_009a4250(apRef);
    if (!!ptr)
    {
        CombatPlanningPosition layout;
        layout.origin = *apRef->FUN_00436aa0();
        FUN_006d5320 holder[64];
        FUN_00403d30(holder, 0, 0x600);
        {
            layout.count = 0;
            {
                int kIter = 0;
                unsigned int flags = 0;
                unsigned int value;
                value = ptr->FUN_0044ddc0();
                value = FUN_0042f5a0(value, 0x40);
                for (unsigned int e = 0; e < value; e++)
                {
                    Ref* slot = *ptr->FUN_006a7ad0(e);
                    {
                        CombatPlan* m;
                        m = slot ? slot->GetCombatPlan() : 0;
                        if (m)
                        {
                            if ((m->FUN_00981940(7) || m->FUN_00981940(8)))
                            {
                                holder[layout.count].obj = m;
                                holder[layout.count].pos = *slot->FUN_00436aa0();
                                holder[layout.count].angle =
                                    57.2957763671875f *
                                    GetDirectionAngle(holder[layout.count].pos.FUN_00439ef0(layout.origin));
                                holder[layout.count].dir = (char)ScaleByRatio(holder[layout.count].angle);
                                if ((m->FUN_004fd3e0() != 0) && (1 == m->FUN_004fd3e0()->GetType()))
                                {
                                    holder[layout.count].flag = 1;
                                    kIter += 1;
                                }
                                layout.count += 1;
                                if (slot == apTargetRef)
                                    result = true;
                            }
                        }
                    }
                }
                if (layout.count)
                {
                    if (kIter)
                    {
                        for (unsigned int j = 0; j < layout.count; j++)
                        {
                            if (holder[j].flag)
                            {
                                char val = FUN_009a98a0(flags, holder[j].dir);
                                if (val != -1)
                                {
                                    flags = ExpandFlagBits(flags, val);
                                    float f;
                                    f = holder[j].angle;
                                    if (val != holder[j].dir)
                                        f = ScaleCharToFloat(val);
                                    holder[j].obj->SetFieldE0(f);
                                }
                            }
                        }
                    }
                    for (unsigned int k = 0; k < layout.count; k++)
                    {
                        if (0 == holder[k].flag)
                        {
                            char val = FUN_009a98a0(flags, holder[k].dir);
                            if (val != -1)
                            {
                                flags = ExpandFlagBits(flags, val);
                                float f;
                                f = holder[k].angle;
                                if (val != holder[k].dir)
                                    f = ScaleCharToFloat(val);
                                holder[k].obj->SetFieldE0(f);
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

S_009a82b0_Point3 FUN_009a8250(S_009a6d70_Actor* actor);
S_009a6d70_Point FUN_009a8970(FUN_009a8df0_vec a, S_009a82b0_Point3 b, float time, NiPoint3 target);
// Calls FUN_009a8970 with FUN_009a8050's output, FUN_009a8250(actor), zero time, and target.
// @fnv 0x009a88e0
S_009a6d70_Point FUN_009a88e0(S_009a6d70_Actor* actor, NiPoint3 target)
{
    FUN_009a8df0_vec direction;
    FUN_009a8050(&direction, (int)actor);
    float time = 0.0f;
    return FUN_009a8970(direction, FUN_009a8250(actor), time, target);
}

extern double DAT_0101ff58;
struct Point3A8AF0
{
    float x;
    float y;
    float z;
    Point3A8AF0(float fX, float fY, float m_fGlyphExtent);
    Point3A8AF0 operator-(const Point3A8AF0& kOther) const;
    float Length() const;
};
float __cdecl FUN_004b54c0(float fValue);
float __cdecl FUN_004b1550(Point3A8AF0* pkPt);

// Computes two angles from the point difference, adjusts each using the shown 2π bounds, and returns them in x and z.
// @fnv 0x009a8af0
Point3A8AF0 GetPitchYaw(Point3A8AF0 kFrom, Point3A8AF0 kTo)
{
    float fHeadingAngle;
    float fClampedPitch;
    Point3A8AF0 kPt = kTo - kFrom;
    float m_fGlyphExtent = kPt.z;
    float fLen = kPt.Length();
    float fAsin = FUN_004b54c0(m_fGlyphExtent / fLen);
    fClampedPitch = -fAsin;
    if (fClampedPitch <= DAT_0101ff58)
        fClampedPitch += 6.2831854820251465;
    else if (fClampedPitch > 3.1415927410125732)
        fClampedPitch -= 6.2831854820251465;
    fHeadingAngle = FUN_004b1550(&kPt);
    float fResultYaw = fHeadingAngle;
    if (fResultYaw <= DAT_0101ff58)
        fResultYaw += 6.2831854820251465;
    else if (fResultYaw > 3.1415927410125732)
        fResultYaw -= 6.2831854820251465;
    return Point3A8AF0(fClampedPitch, 0.0f, fResultYaw);
}

namespace s9a8050 {

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiAVObject
{
    NiPoint3* FUN_0045bb80();
};

struct Weapon
{
    bool FUN_004c0c30();
    int FUN_00446390();
};

struct Process
{
    Weapon* FUN_007031c0();
};

class NiNode
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
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
    virtual NiAVObject* GetObjectByBone(int iBone);
};

class Actor
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool IsActor();
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual int GetHeadBone();
    virtual void v1f0();
    virtual NiPoint3* GetPos();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual NiAVObject* GetHead();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
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
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual Process* GetCurrentProcess();

    Weapon* FUN_008a1710();
    NiNode* FUN_008d8520();
};

class PlayerCharacter : public Actor
{
  public:
    bool FUN_004eaf60();
    int FUN_00950b00(bool bFirstPerson);
};

extern PlayerCharacter* DAT_011dea3c;

float GetScaleOrHeightDelta(Actor* pkActor, int iUnk);

// Returns a head or bone position when available; otherwise adds a height delta to the reference position.
// @fnv 0x009a8050
NiPoint3 FUN_009a8050(Actor* pkRef)
{
    NiPoint3 kPos;
    if (pkRef->IsActor())
    {
        Actor* pkActor = pkRef;
        bool bIsPC = pkActor == DAT_011dea3c;
        Weapon* pkWeap = 0;
        Process* pkProc = pkActor->GetCurrentProcess();
        if (pkProc)
            pkWeap = pkProc->FUN_007031c0();
        else
            pkWeap = pkActor->FUN_008a1710();
        if (!pkWeap || pkWeap->FUN_004c0c30())
        {
            NiNode* pkRoot = pkActor->FUN_008d8520();
            if (pkActor && pkRoot &&
                (!pkWeap || pkWeap->FUN_00446390() == 0xa || pkWeap->FUN_00446390() == 0xb ||
                 pkWeap->FUN_00446390() == 0xd || pkWeap->FUN_00446390() == 0xc))
            {
                int iBone = bIsPC ? DAT_011dea3c->FUN_00950b00(DAT_011dea3c->FUN_004eaf60()) : pkActor->GetHeadBone();
                NiAVObject* pkBone = pkRoot->GetObjectByBone(iBone);
                if (pkBone)
                    return *pkBone->FUN_0045bb80();
            }
            else
            {
                NiAVObject* pkHead = pkActor->GetHead();
                if (pkHead)
                    return *pkHead->FUN_0045bb80();
            }
        }
    }
    kPos = *pkRef->GetPos();
    kPos.z += GetScaleOrHeightDelta(pkRef, 0);
    return kPos;
}

}
