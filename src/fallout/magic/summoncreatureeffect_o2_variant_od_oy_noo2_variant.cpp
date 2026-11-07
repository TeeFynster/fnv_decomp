#define FNV64_HKVECTOR4_OWN_DEFAULT

#include "../../../include/MobileObject.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TES.h"
#include "../../../include/SummonCreatureEffect.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/TESForm.h"
#include "../../../include/bhkSphereShape.h"
#include "../../../include/hkBool.h"

// src/fallout/magic/summoncreatureeffect_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/summoncreatureeffect_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/summoncreatureeffect_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/summoncreatureeffect.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/summoncreatureeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/summoncreatureeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void __cdecl _Deallocate(void*);
struct FUN_00828da0_shell
{
    int __thiscall GetZero(int a, int b, int c);
};

#include "../../../include/hkVector4.h"


hkVector4& __cdecl NiPoint3ToHkVector4(hkVector4& kOut, const NiPoint3& kIn);




struct bhkWorld;

bhkWorld* __fastcall GetHavokWorld(TESObjectCELL* pkCell);

struct EffectTarget
{
    MobileObject* GetActor();
};


struct CollisionFilterInfo
{
    unsigned int m_uiFilterInfo;

    CollisionFilterInfo(int iLayer, int iSystemGroup, int iPart);
    operator unsigned int() const;
};

struct BoundingVolumeData
{
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_reserved;
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    void* m_pChildShapeAabbs;
    void* m_pChildShapeKeys;

    void Init();
};

struct __declspec(align(16)) Collidable
{
    unsigned int m_uiFilterInfo;
    void* m_pShape;
    void* m_pMotionState;
    void* m_parent;
    char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    unsigned int m_broadPhaseId;
    char m_cBroadPhaseType;
    char m_broadPhaseOwnerOffset;
    char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
    BoundingVolumeData m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;

    Collidable();
    ~Collidable();
};

struct ShapePhantom
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;

    ShapePhantom(const void* pkCollidable);
    ~ShapePhantom();
    void SetWorld(bhkWorld* pkWorld);
    void LinearCast(const hkVector4& kFrom, const void* pkInput, void* pkCastCollector, void* pkStartCollector);
    void Remove();
};

struct __declspec(align(16)) CdPointCollector
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

    CdPointCollector();
    ~CdPointCollector();
    hkBool HasHit();
};

struct __declspec(align(16)) LinearCastInput
{
    hkVector4 m_vTo;
    float m_fMaxExtraPenetration;
    float m_fStartPointTolerance;
    int unk18;
    int unk1c;

    LinearCastInput();
};

struct PickFilter
{
    unsigned int m_uiFilter;

    PickFilter(int iValue);
    void SetLayer(int iLayer);
};

struct RayCastOutput
{
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void* m_pRootCollidable;
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

    hkBool HasHit();
};

struct __declspec(align(16)) PickData
{
    hkVector4 m_kFrom;
    hkVector4 m_kTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    RayCastOutput m_kOutput;

    PickData();
    void SetFilter(PickFilter kFilter);
    void SetFrom(const NiPoint3& kFrom);
    void SetTo(const NiPoint3& kTo);
};

extern TES* g_TES;

struct SummonCreatureEffectHelper : SummonCreatureEffect
{
    EffectTarget* GetTarget();
    TESForm* GetBaseForm();
    bool SummonCreatureEffect_CheckSummonLocation(int iUnused, NiPoint3* pkPos);
};

// @fnv 0x00828f00
// src: XBOX_PDB 0x00828f00
bool SummonCreatureEffectHelper::SummonCreatureEffect_CheckSummonLocation(int iUnused, NiPoint3* pkPos)
{
    MobileObject* pkActor = GetTarget() ? GetTarget()->GetActor() : 0;
    TESBoundObject* pkBound = dynamic_cast<TESBoundObject*>(GetBaseForm());
    float fRadius = pkBound->GetBoundSize();
    if (64.0 > fRadius)
        fRadius = 64.0f;

    bhkSphereShape* pkShape = new bhkSphereShape(fRadius * 0.5, true);
    CollisionFilterInfo kFilter(0x26, 0, 0);
    Collidable kCollidable;
    kCollidable.m_uiFilterInfo = kFilter;
    kCollidable.m_pShape = pkShape->GetHavokShape();
    kCollidable.m_kBoundingVolumeData.Init();
    ShapePhantom kPhantom(&kCollidable);
    if (pkActor->GetParentCell())
        kPhantom.SetWorld(GetHavokWorld(pkActor->GetParentCell()));

    hkVector4 kFrom;
    CdPointCollector kStartCollector;
    CdPointCollector kCastCollector;
    LinearCastInput kInput;
    NiPoint3ToHkVector4(kFrom, *pkPos + NiPoint3(0.0f, 0.0f, fRadius * 0.5 + 10.0));
    NiPoint3ToHkVector4(kInput.m_vTo, *pkPos + NiPoint3(0.0f, 0.0f, fRadius * 0.5 + 10.0));
    kPhantom.LinearCast(kFrom, &kInput, &kCastCollector, &kStartCollector);
    if (kStartCollector.HasHit())
    {
        kPhantom.Remove();
        delete pkShape;
        return false;
    }

    kPhantom.Remove();
    delete pkShape;
    if (pkActor->GetRelevantWaterHeight() > static_cast<const MobileObject*>(pkActor)->GetPos()->z)
        return false;

    PickData kPick;
    PickFilter kPickFilter(0);
    kPickFilter.SetLayer(0x26);
    kPick.SetFilter(kPickFilter);
    NiPoint3 kStart = *static_cast<const MobileObject*>(pkActor)->GetPos();
    kStart.z += 64.0;
    NiPoint3 kEnd = *pkPos;
    kEnd.z += 64.0;
    kPick.SetFrom(kStart);
    kPick.SetTo(kEnd);
    g_TES->Pick(kPick);
    if (kPick.m_kOutput.HasHit())
        return false;

    return true;
}
