#include "../../../../include/SettingT.h"
// Avoid collision with the compiler-generated constructor closure in TESBoundObject.
#define __local_vftable_ctor_closure FNVLocalVftableCtorClosure
#include "../../../../include/NiNode.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BGSProjectile.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/AlchemyItem.h"
#include "../../../../include/CombatController.h"
#include "../../../../include/CombatPlan.h"
// CombatCoverPointData_combatutilities: local type (was include/CombatCoverPointData.h, which had no evidence of one real class); its methods are 0x005dc960 Main::GameOver, 0x0067fdb0 PackageSchedule::SetStartDayOfWeek, 0x009a2ea0 CombatCoverLocation::LoadGameBGS
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

class CombatCoverPointData_combatutilities
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;

    void Copy(void*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    bool IsHideCover();
    bool IsCrouchCover();
    bool IsStandCover();
    bool IsLedgeCover();
    bool IsValidCover();
    unsigned char GetCoverHeight();
    bool IsReserved();
    void SetReserved(bool);
    bool IsDirty();
    void SetDirty(bool);
    void* __vecDelDtor(unsigned int);
};
#include "../../../../include/ExtraFollower.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TES.h"
#include "../../../../include/TopicInfoArray.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiColorA.h"
#undef __local_vftable_ctor_closure

// Preserve the original trivial point ABI for the functions that pass points by value.
struct CombatPoint3
{
    float x, y, z;
};

// src/fallout/ai/combat/combatutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" float __cdecl NiCos(float);

// Returns a divided by the product of FUN_005b9e80(b) and c.
// @fnv 0x009a7dd0
// src: XBOX_PDB 0x009a7dd0
float __cdecl CombatUtilities_ComputeProjectileTime(float afNumerator, float afInput, float c)
{
    return afNumerator / (NiCos(afInput) * c);
}

extern int DAT_011a558c;

// @fnv 0x009a97b0
// src: COMMUNITY 0x009a97b0
char RotateSlot(char a1, char a2)
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

// @fnv 0x009a9f00
void __thiscall CombatPlan::SetFieldE0(float value)
{
    *(float*)((char*)this + 0xe0) = value;
}

// @fnv 0x009a7f80
// src: XBOX_PDB 0x009a7f80
bool BGSProjectile::GetHitScan() const
{
    return GetFlag(1);
}

extern "C" double _DAT_0103c348;

// @fnv 0x009a99d0
long __cdecl ScaleByRatio(float afValue)
{
    return (long)(afValue / _DAT_0103c348 * DAT_011a558c);
}

float __cdecl GetScaleOrHeightDelta(TESObjectREFR* a, int b);
// Returns the attacker's position with its z raised by the value from GetScaleOrHeightDelta(apAttacker, 0).
// @fnv 0x009a8250
// src: XBOX_PDB 0x009a8250
CombatPoint3 CombatUtilities_GetAttackerFiringLocationSimple(TESObjectREFR* apAttacker)
{
    CombatPoint3 shooterLocation;
    shooterLocation = *(CombatPoint3*)static_cast<const TESObjectREFR*>(apAttacker)->GetPos();
    shooterLocation.z += GetScaleOrHeightDelta(apAttacker, 0);
    return shooterLocation;
}

namespace fnv_009a8600 {
typedef int ACTOR_SEGMENT_INVIEW;
float __cdecl CombatUtilities_GetTargetFiringZOffset(TESObjectREFR*, ACTOR_SEGMENT_INVIEW, int);
// Returns the target position with its z raised by FUN_009a8460 for the given segment.
// @fnv 0x009a8600
CombatPoint3 __cdecl GetTargetLocationWithOffset(TESObjectREFR* apTarget, ACTOR_SEGMENT_INVIEW aeTargetSegmentInView)
{
    CombatPoint3 targetLocation;
    targetLocation = *(CombatPoint3*)apTarget->GetPos();
    targetLocation.z += CombatUtilities_GetTargetFiringZOffset(apTarget, aeTargetSegmentInView, 0);
    return targetLocation;
}
}  // namespace fnv_009a8600

namespace fnv_009a9370 {
void __cdecl CombatUtilities_CalculateCoverPositions_009a93a0(CombatController*, CombatPoint3*, CombatPoint3*, CombatPoint3*, CombatPoint3*);
// Calls FUN_009a93a0 with the combat controller and the two CombatPoint3 members at offsets 0x14 and 0x70 of the given object, plus the two passed points.
// @fnv 0x009a9370
// src: XBOX_PDB 0x009a9370
void __cdecl CombatUtilities_CalculateCoverPositions(CombatController* apCombatController, CombatCoverPointData_combatutilities* b, CombatPoint3* apPoint1,
                          CombatPoint3* apPoint2)
{
    CombatUtilities_CalculateCoverPositions_009a93a0(apCombatController, reinterpret_cast<CombatPoint3*>(&b->unk14),
                 reinterpret_cast<CombatPoint3*>(&b->unk70), apPoint1, apPoint2);
}
}  // namespace fnv_009a9370

struct GameSettingCollection;
using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting353;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting354;
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
        char r0 = RotateSlot(aiBit, -i);
        if (auiMask & (1 << r0))
            return 1;
        char r1 = RotateSlot(aiBit, i);
        if (auiMask & (1 << r1))
            return 1;
    }
    return 0;
}

extern int DAT_011a5590;
char RotateSlot(char a1, char a2);

// Sets bit index in flags, then for i from 1 to DAT_011a5590 sets the bits returned by FUN_009a97b0(index, -i) and FUN_009a97b0(index, i), returning flags.
// @fnv 0x009a9940
int ExpandFlagBits(int flags, char index)
{
    flags |= 1 << index;
    for (int i = 1; i <= DAT_011a5590; ++i)
    {
        char r2 = RotateSlot(index, -i);
        flags |= 1 << r2;
        char r1 = RotateSlot(index, i);
        flags |= 1 << r1;
    }
    return flags;
}

// @fnv 0x00966980
// src: XBOX_PDB 0x00966980
float __thiscall BGSProjectile::GetGravity_00966980()
{
    return ((BGSProjectile*)this)->GetFlag(0x20000) ? 1.0f : this->Data.afGravity;
}

struct A69C0Weapon
{
    float GetReachValue();
};

bool __fastcall A69C0IsMeleeWeapon(A69C0Weapon* pkWeapon);
float __cdecl CombatFormulas_CalcWeaponReach(float fValue);

// @fnv 0x009a69c0
float __cdecl GetActorReach(Actor* pkActor, A69C0Weapon* pkWeapon)
{
    float fScale = pkActor->TESObjectREFR_GetScale_00567400();
    if (!pkWeapon)
        return pkActor->GetUnarmedReach() * fScale;
    if (!A69C0IsMeleeWeapon(pkWeapon))
        return fScale * 128.0;
    return CombatFormulas_CalcWeaponReach(pkWeapon->GetReachValue()) * fScale;
}

float NiSqrt_004579e0(float);
float BSMAX_00404010(float, float);
float BSMIN(float, float);
float NiATan(float);
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
        float selected = NiSqrt_004579e0(discriminant);
        float angle = (squared - selected) / (distance * gravity);
        lower = (squared + selected) / (distance * gravity);
        float root;
        if (lowArc)
            root = BSMAX_00404010(angle, lower);
        else
            root = BSMIN(angle, lower);
        float upper = NiATan(root);
        return upper;
    }
    return runtimeInitializationFloat1935 * 0.25;
}

extern "C" double DAT_01012060;
extern "C" float DAT_011f1c00;
// Reads a base value; if not flagged, scales arg (or a queried value) squared by a queried value times a constant when above a threshold.
// @fnv 0x009a7f00
// src: XBOX_PDB 0x009a7f00
float __cdecl CombatUtilities_GetProjectileMaximumRange(BGSProjectile* obj, float arg)
{
    float a = obj->FUN_009a7c40();
    if (obj->GetHitScan())
        return a;
    float value = obj->GetGravity_00966980();
    if (value <= DAT_01012060)
        return a;
    value *= DAT_011f1c00;
    if (arg == DAT_01012060)
        arg = obj->GetFloatAtOffset68();
    return arg * arg / value;
}

unsigned char RotateSlot(unsigned char a1, unsigned char a2);
bool __cdecl IsBitSetOrNeighbor(unsigned int a, unsigned char b);

// @fnv 0x009a98a0
// src: COMMUNITY 0x009a98a0
unsigned char FindSlot_009a98a0(unsigned int a, unsigned char b)
{
    for (int i = 0; i < DAT_011a558c / 2; i++)
    {
        unsigned char x = RotateSlot(b, i);
        if (!IsBitSetOrNeighbor(a, x))
            return x;
        unsigned char y = RotateSlot(b, -i);
        if (!IsBitSetOrNeighbor(a, y))
            return y;
    }
    return 0xff;
}

struct FollowerNode
{
    Actor** FUN_006815c0();
    FollowerNode* FUN_00726070();
};

struct FUN_00422700_shell
{
    ExtraFollower* ExtraDataList_GetFollowerExtra();
};

struct ExtraDataList;
ExtraDataList* __fastcall BSFile_GetDevice(TESObjectREFR* ref);

struct ContNode;
ContNode* __fastcall FUN_00717e50(void* p);
unsigned int __fastcall FUN_0044ddc0(TESObjectREFR* ref);

float __cdecl CombatUtilities_GetDistanceBetweenFacingActors(Actor* a, Actor* b, int c);
bool IsTargetInCone(Actor* a, Actor* b, float* outDist);

extern int DAT_011e0e80;
extern int DAT_011f2250;
extern float DAT_01016970;
extern Actor* g_thePlayer;

// @fnv 0x009a60e0
// src: XBOX_PDB 0x009a60e0
Actor* CombatUtilities_GetFacingTarget(Actor* actor, float maxDist)
{
    Actor* target7 = actor->GetCombatController() ? (Actor*)((AlchemyItem*)actor->GetCombatController())->CombatController_GetTarget() : 0;
    if (target7 && IsTargetInCone(actor, target7, 0) && CombatUtilities_GetDistanceBetweenFacingActors(actor, target7, 1) <= maxDist)
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
    for (unsigned int i = 0; i < ((TopicInfoArray*)FUN_00717e50(&DAT_011e0e80))->ProcessArray_GetProcessLevelTail(0); i++)
    {
        actorAt4 = ((TopicInfoArray*)FUN_00717e50(&DAT_011e0e80))->ProcessArray_GetItem(i);
        if (actorAt4 && actorAt4->IsActor())
        {
            cand7 = actorAt4;
        }
        else
        {
            cand7 = 0;
        }
        if (FUN_0044ddc0((TESObjectREFR*)&DAT_011f2250) == 4 && cand7 && cand7->HasHealth(false))
        {
            continue;
        }
        if (cand7 && cand7 != actor && (!cand7->HasHealth(false) || actor == g_thePlayer) && cand7->GetNiNode() &&
            CombatUtilities_GetDistanceBetweenFacingActors(actor, cand7, 0) <= maxDist)
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
            ExtraFollower* extra_2 = ((FUN_00422700_shell*)BSFile_GetDevice((TESObjectREFR*)cand7))->ExtraDataList_GetFollowerExtra();
            if (extra_2)
            {
                FollowerNode* nodeB = (FollowerNode*)extra_2->list;
                while (nodeB && *nodeB->FUN_006815c0())
                {
                    Actor* follower = *nodeB->FUN_006815c0();
                    if (follower && !follower->FUN_00931850() && follower != actor &&
                        (!cand7->HasHealth(false) || actor == g_thePlayer) && follower->GetNiNode() &&
                        CombatUtilities_GetDistanceBetweenFacingActors(actor, follower, 0) <= maxDist)
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
        float playerDist2 = CombatUtilities_GetDistanceBetweenFacingActors(actor, g_thePlayer, 0);
        float playerLosTmp = DAT_01016970;
        bool playerOk4 = IsTargetInCone(actor, g_thePlayer, &playerLosTmp);
        if (playerDist2 <= maxDist && playerOk4 && playerLosTmp <= bestDist3)
        {
            best3 = g_thePlayer;
        }
    }

    if (best3 && actor->IsPlayerRef() && !((PlayerCharacter*)g_thePlayer)->Actor_LineOfSight(1, best3, 1, 0, 0))
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

struct S_9a64d0_Setting
{
    float* Float();
};
extern S_9a64d0_Setting DAT_011ce4a0;

float fabsf_00408860(float f);
float CombatUtilities_GetAttackerTargetExtentSum(Actor* a, Actor* b);

// @fnv 0x009a64d0
// src: XBOX_PDB 0x009a64d0
float CombatUtilities_GetDistanceBetweenFacingActors(Actor* a, Actor* b, bool checkHeight)
{
    float adjust8;
    float dist3;
    if (!b)
        return 0.0f;
    dist3 = a->GetDistanceToReference(b, 0, 0);
    if (dist3 == 3.4028234663852886e+38)
        return dist3;
    if (a->IsActor() && b->IsActor())
    {
        Actor* pA3 = (Actor*)a;
        Actor* pB6 = (Actor*)b;
        if (pA3 && pB6)
        {
            bool kBoth = pA3->IsSwimming_005a2030() && pB6->IsSwimming_005a2030();
            S_9a64d0_Pt posA9 = *(S_9a64d0_Pt*)static_cast<const TESObjectREFR*>(pA3)->GetPos();
            S_9a64d0_Pt posB_2 = *(S_9a64d0_Pt*)static_cast<const TESObjectREFR*>(pB6)->GetPos();
            S_9a64d0_Pt ptA = posA9;
            S_9a64d0_Pt aPtB = posB_2;
            if (kBoth || (checkHeight && fabsf_00408860(ptA.z - aPtB.z) >= *DAT_011ce4a0.Float()))
            {
                ptA.z = 0.0f;
                aPtB.z = 0.0f;
                float minATmp = pA3->GetMaximum().z + posA9.z;
                float maxA4 = pA3->GetMinimum().z + posA9.z;
                float _minB = pB6->GetMaximum().z + posB_2.z;
                float maxB3 = pB6->GetMinimum().z + posB_2.z;
                if ((minATmp <= _minB && minATmp >= maxB3) || (maxA4 <= _minB && maxA4 >= maxB3))
                {
                    S_9a64d0_Pt diff6 = ptA - aPtB;
                    float len3 = diff6.Length();
                    dist3 = len3;
                }
            }
        }
    }
    adjust8 = CombatUtilities_GetAttackerTargetExtentSum(a, b);
    return dist3 - adjust8;
}

struct S_009a6770_Pt
{
    float x;
    float y;
    float z;
};
// The shared Actor header does not yet declare this entry point.
extern "C" void Actor_GetForwardLength();

// Sums a's Y position times its scale (or FUN_008be420 if IsX) with b's same value when b is non-null, returning the total.
// @fnv 0x009a6770
// src: XBOX_PDB 0x009a6770
float __cdecl CombatUtilities_GetAttackerTargetExtentSum(Actor* pRefA, Actor* pRefB)
{
    float total2 = 0.0f;
    Actor* r1;
    Actor* r2;
    S_009a6770_Pt pt5;
    S_009a6770_Pt pt3;
    if (pRefA->IsActor())
    {
        r1 = pRefA;
        total2 = reinterpret_cast<float (__thiscall*)(Actor*)>(Actor_GetForwardLength)(r1);
    }
    else
    {
        total2 = reinterpret_cast<S_009a6770_Pt* (__thiscall*)(Actor*, S_009a6770_Pt*)>((*reinterpret_cast<void***>(pRefA))[0x1dc / 4])(pRefA, &pt5)->y * pRefA->TESObjectREFR_GetScale_00567400();
    }
    if (pRefB)
    {
        if (pRefB->IsActor())
        {
            r2 = pRefB;
            total2 = reinterpret_cast<float (__thiscall*)(Actor*)>(Actor_GetForwardLength)(r2) + total2;
        }
        else
        {
            total2 = reinterpret_cast<S_009a6770_Pt* (__thiscall*)(Actor*, S_009a6770_Pt*)>((*reinterpret_cast<void***>(pRefB))[0x1dc / 4])(pRefB, &pt3)->y * pRefB->TESObjectREFR_GetScale_00567400() + total2;
        }
    }
    return total2;
}

float __cdecl CombatUtilities_GetAttackerTargetExtentSum(Actor* pkActor, int iType);

// @fnv 0x009a6830
// src: XBOX_PDB 0x009a6830
float __cdecl CombatUtilities_ComputeFaceTargetDistance(Actor* pkActor, int iType, float afModifier)
{
    float fBase2 = CombatUtilities_GetAttackerTargetExtentSum(pkActor, iType);
    if (afModifier == -1.0)
        afModifier = GetActorReach(pkActor, (A69C0Weapon*)pkActor->GetEquippedWeapon());
    float fResult = afModifier * 0.5;
    fResult = fResult + fBase2;
    fResult = BSMAX_00404010(fResult, 0.0f);
    return fResult;
}

struct S_009a68b0_Pt
{
    float x, y, z;
    S_009a68b0_Pt()
    {}
    S_009a68b0_Pt(float a, float b, float c) : x(a), y(b), z(c)
    {}
    S_009a68b0_Pt SubtractIntoVector(S_009a68b0_Pt* other);
    S_009a68b0_Pt FUN_00439e90(S_009a68b0_Pt* other);
    S_009a68b0_Pt* ScaleComponents(float f);
    void Unitize_004a0c10();
};

struct S_009a68b0_Z
{
    float CombatController_GetCombatPosition();
};

extern S_009a68b0_Pt DAT_011f426c;
extern double DAT_01023128;
bool __cdecl AssignCombatPlanAngles(Actor* a, Actor* b);
float __cdecl CombatUtilities_ComputeFaceTargetDistance(Actor* a, Actor* b, float c);
void __cdecl NiSinCos_004169a0(float a, float* s, float* c);

// @fnv 0x009a68b0
// src: XBOX_PDB 0x009a68b0
S_009a68b0_Pt CombatUtilities_ComputeFaceTargetLocation(Actor* ref, Actor* obj, S_009a68b0_Pt* apPoint, float f)
{
    S_009a68b0_Pt dir3 = DAT_011f426c;
    Actor* target2 = obj->IsActor() ? obj : 0;
    S_009a68b0_Z* z2 = (S_009a68b0_Z*)ref->GetCombatController();
    if (z2 && target2 && AssignCombatPlanAngles(target2, ref))
    {
        float angle = z2->CombatController_GetCombatPosition();
        NiSinCos_004169a0(angle * DAT_01023128, &dir3.x, &dir3.y);
    }
    else
    {
        S_009a68b0_Pt diff = ((S_009a68b0_Pt*)static_cast<const TESObjectREFR*>((TESObjectREFR*)ref)->GetPos())->SubtractIntoVector(apPoint);
        diff.Unitize_004a0c10();
    }
    dir3.ScaleComponents(CombatUtilities_ComputeFaceTargetDistance(ref, obj, f));
    return apPoint->FUN_00439e90(&dir3);
}

struct ConePoint
{
    float x, y, z;
    ConePoint SubtractIntoVector(const ConePoint& kOther) const;
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

extern PlayerCharacter* g_thePlayer_011dea3c;

struct ConeSetting
{
    float* Setting_Float_00403e20();
};
extern ConeSetting g_s_011cfa58;
extern ConeSetting g_s_011cfda4;

float __cdecl FUN_004b1550(ConePoint* pkDir);
void* __cdecl BSUtilities_GetObjectByName(void* pkRoot, const char* pcName);
float __cdecl fabsf_00408860(float f);
float __cdecl FUN_00408840(float f);
float __cdecl GetCombatHitConesAngles(int iSkill);

static const char s_szProjectileNode[] = "ProjectileNode";
extern const char g_szConeEnd[] = "";

// Computes the angle between shooter and target, derives a cone threshold from skill or settings, and returns whether the target lies within it.
// @fnv 0x009a6ae0
bool __cdecl IsTargetInCone(Actor* pkShooter, Actor* pkTarget, float* pfAngleOut)
{
    bool bInConeX = false;
    int iSkillOut = 0x1a;
    if (pkShooter == (Actor*)g_thePlayer_011dea3c && pkShooter->FUN_008d8520() && ((ConeProcess*)pkShooter->FUN_008d8520())->GetLoadedForm() &&
        ((ConeProcess*)pkShooter->FUN_008d8520())->GetLoadedForm()->FUN_0048f7f0())
        iSkillOut = ((ConeProcess*)pkShooter->FUN_008d8520())->GetLoadedForm()->FUN_0048f7f0()->FUN_005f2420();
    ConePoint kDeltaA = ((ConePoint*)static_cast<const TESObjectREFR*>(pkTarget)->GetPos())->SubtractIntoVector(*(ConePoint*)static_cast<const TESObjectREFR*>(pkShooter)->GetPos());
    float fHeadingLoc = FUN_004b1550(&kDeltaA);
    float fAimDirectionOffset = 0.0f;
    if (pkShooter == (Actor*)g_thePlayer_011dea3c)
    {
        float fX_2 = 0.0f;
        float fYA = 0.0f;
        void* pkNodeRes = BSUtilities_GetObjectByName(g_thePlayer_011dea3c->PlayerCharacter_Get3D_00950bb0(0), s_szProjectileNode);
        g_thePlayer_011dea3c->UpdateAim(0, pkNodeRes, &fX_2, &fYA, 0, 1.175494351e-38F, 1.175494351e-38F);
        if (g_thePlayer_011dea3c->PlayerCharacter_GetAutoAimActor())
            fAimDirectionOffset = fX_2;
    }
    float fAngleA =
        fabsf_00408860(pkShooter->GetCurrentTargetDistance(0) + fAimDirectionOffset - fHeadingLoc) * 57.2957763671875f;
    if (fAngleA > 180.0)
        fAngleA = FUN_00408840(fAngleA - 360.0);
    float fConeTmp = 0.0f;
    if (pkShooter == (Actor*)g_thePlayer_011dea3c)
        fConeTmp = GetCombatHitConesAngles(iSkillOut);
    else
        fConeTmp = *g_s_011cfa58.Setting_Float_00403e20();
    if (kDeltaA.FUN_00457990() < 128.0)
        fConeTmp = fConeTmp * 3.0;
    if (fAngleA <= fConeTmp)
    {
        bInConeX = true;
    }
    else if (pkTarget->IsActor())
    {
        Actor* pkActor = pkTarget;
        if (pkActor->HasHealth(false))
        {
            fConeTmp = fConeTmp * *g_s_011cfda4.Setting_Float_00403e20();
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
S_009a6d70_Point CombatUtilities_GetAngleToProjectedPoint(Actor* actor, CombatPoint3 target);
float FUN_004b1480(float angle);
float GetAngleDelta(float from, float to, float* out);
float FUN_00408840(float value);
extern "C" double DAT_0101ff48;
extern "C" double DAT_01011588;

// @fnv 0x009a6d70
bool IsWithinAimLimits(Actor* actor, CombatPoint3* target, float afMaxHeadingDiff, float afMaxPitchDiff)
{
    S_009a6d70_Point angles4 = CombatUtilities_GetAngleToProjectedPoint(actor, *target);
    if (afMaxHeadingDiff < DAT_0101ff48)
    {
        float heading5 = actor->GetAdjustedAngle();
        angles4.z = FUN_004b1480(angles4.z);
        float signZ5 = 0.0f;
        float diffZ = FUN_00408840(GetAngleDelta(heading5, angles4.z, &signZ5));
        if (afMaxHeadingDiff * DAT_01011588 < diffZ)
            return false;
    }
    if (afMaxPitchDiff < DAT_0101ff48)
    {
        float pitch4 = actor->FUN_00931d70();
        angles4.x = FUN_004b1480(angles4.x);
        float signX3 = 0.0f;
        float diffX = FUN_00408840(GetAngleDelta(pitch4, angles4.x, &signX3));
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
    float* Setting_Float_00403e20();
};
extern S_009a7670_Setting DAT_011cf95c;
extern S_009a7670_Setting DAT_011cfb78;
extern "C" double DAT_0101a6b0;
S_009a7670_P3 CombatUtilities_GetProjectedPointForTarget(S_009a7670_P3 a, S_009a7670_P3 b, S_009a7670_P3 c, float r, float v, unsigned char flag);
bool CombatUtilities_CalculateProjectileLOS(void* a, BGSProjectile* obj, float f, S_009a7670_P3 p, S_009a7670_P3 q, int zero, int* found,
                  float* dist);

// @fnv 0x009a7670
// src: XBOX_PDB 0x009a7670
bool CombatUtilities_CheckProjectileArc_009a7670(void* a, int b, BGSProjectile* obj, S_009a7670_P3 p1, S_009a7670_P3 p2, S_009a7670_P3 p3,
                  unsigned char* flag, S_009a7670_P3* out, float maxDist)
{
    if (!a || !b)
        return false;
    if (maxDist == DAT_0101a6b0)
        maxDist = *DAT_011cf95c.Setting_Float_00403e20();
    float dist8 = 0.0f;
    int found = 0;
    float v = obj->GetGravity_00966980() * DAT_011f1c00;
    if (v == DAT_01012060)
    {
        S_009a7670_P3 hit = CombatUtilities_GetProjectedPointForTarget(p1, p2, p3, obj->GetFloatAtOffset68(), v, *flag);
        bool ok = CombatUtilities_CalculateProjectileLOS(a, obj, 0, p1, hit, 0, &found, &dist8);
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
            k = *DAT_011cfb78.Setting_Float_00403e20();
        else
            k = 1.0f;
        float r2 = obj->GetFloatAtOffset68() * k;
        bool ok;
        S_009a7670_P3 point = CombatUtilities_GetProjectedPointForTarget(p1, p2, p3, r2, v, *flag);
        ok = CombatUtilities_CalculateProjectileLOS(a, obj, r2, p1, point, 0, &found, &dist8);
        if (!ok || found == b || dist8 > maxDist)
        {
            *out = point;
            return true;
        }
    }
    *flag = saved;
    return false;
}

struct GlobalSetting
{
    float* Setting_Float_00403e20();
};
extern GlobalSetting g_011cfb78;

// @fnv 0x009a7e00
float __cdecl ComputeProjectileFlightTime(BGSProjectile* actor, NiPoint3 from, NiPoint3 to, bool flag, float speed)
{
    NiPoint3 vDelta = from.SubtractIntoVector(to);
    float fVel = speed;
    if (speed == DAT_01012060)
    {
        fVel = actor->GetFloatAtOffset68();
    }
    if (actor->GetGravity_00966980() != DAT_01012060)
    {
        if (flag && speed == DAT_01012060)
        {
            speed = speed * *g_011cfb78.Setting_Float_00403e20();
        }
        float fAngleDifference = vDelta.z;
        float afGravity = vDelta.NiPoint3_XYLength();
        float m_fGlyphExtent =
            ComputeLaunchAngle(afGravity, fAngleDifference, speed, actor->GetGravity_00966980() * DAT_011f1c00, false);
        return CombatUtilities_ComputeProjectileTime(afGravity, m_fGlyphExtent, fVel);
    }
    return vDelta.FUN_00457990() / speed;
}

extern "C" double DAT_0101de30;
extern "C" double DAT_01011588;

// Returns the scaled actor height, or the reference bounds height times DAT_01011588.
// @fnv 0x009a7fa0
float __cdecl GetScaleOrHeightDelta(TESObjectREFR* apRefr, int aiFlag)
{
    float fBase;
    Actor* selfX;
    CombatPoint3 vAbove;
    CombatPoint3 kVBelow;
    float fValue8;
    float fScaled5;
    float fDeltaA;

    if (reinterpret_cast<Actor*>(apRefr)->IsActor())
    {
        selfX = reinterpret_cast<Actor*>(apRefr);
        if (selfX->FUN_004997b0() && (unsigned char)aiFlag == 0)
        {
            fValue8 = selfX->Actor_GetSneakHeight(0);
        }
        else
        {
            fValue8 = selfX->GetActorHeight();
        }
        fBase = fValue8;
        fScaled5 = fBase * DAT_0101de30;
        return fScaled5;
    }

    // Preserve the explicit result-buffer ABI of the original bounds calls.
    fDeltaA = (reinterpret_cast<CombatPoint3* (__thiscall*)(Actor*, CombatPoint3*)>((*reinterpret_cast<void***>(reinterpret_cast<Actor*>(apRefr)))[0x1dc / 4])(reinterpret_cast<Actor*>(apRefr), &vAbove)->z -
               reinterpret_cast<CombatPoint3* (__thiscall*)(Actor*, CombatPoint3*)>((*reinterpret_cast<void***>(reinterpret_cast<Actor*>(apRefr)))[0x1d8 / 4])(reinterpret_cast<Actor*>(apRefr), &kVBelow)->z) *
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

void NiSinCos_004169a0(float angle, float& s, float& c);
S_009a82b0_Point3 CombatUtilities_GetAttackerFiringLocation(Actor* apRef);
extern "C" double DAT_01030f38;

// Local names were chosen so the /Od stack slots land where the original has them.
// @fnv 0x009a82b0
S_009a82b0_Point3 GetAdjustedPosition(Actor* apRef)
{
    S_009a82b0_Point3 kPos = CombatUtilities_GetAttackerFiringLocation(apRef);
    if (apRef->IsActor())
    {
        Actor* pWho = apRef;
        S_009a82b0_Point3 kStart = *(S_009a82b0_Point3*)static_cast<const TESObjectREFR*>(pWho)->GetPos();
        float fFacing = pWho->GetCurrentTargetDistance(0);
        float fSinYaw = 0.0f;
        float fYawCos = 0.0f;
        NiSinCos_004169a0(fFacing + DAT_01030f38, fSinYaw, fYawCos);
        S_009a82b0_Point2 kAim(fSinYaw, fYawCos);
        S_009a82b0_Point2 kDelta(kPos.x - kStart.x, kPos.y - kStart.y);
        float fProjectionAlongAim = kDelta.Dot(kAim);
        S_009a82b0_Point2 kProjected;
        kProjected.x = kAim.x * fProjectionAlongAim + kStart.x;
        kProjected.y = kAim.y * fProjectionAlongAim + kStart.y;
        float fLook = pWho->FUN_00931d70();
        float fLookSin = 0.0f;
        float fB = 0.0f;
        NiSinCos_004169a0(fLook, fLookSin, fB);
        S_009a82b0_Point2 kToPoint(kPos.x - kProjected.x, kPos.y - kProjected.y);
        float fHoriz = kToPoint.Length();
        float fDZ = fHoriz * fLookSin / fB;
        kPos.x = kProjected.x;
        kPos.y = kProjected.y;
        kPos.z += fDZ;
    }
    return kPos;
}

// @fnv 0x009a8460
// src: XBOX_PDB 0x009a8460
float __cdecl CombatUtilities_GetTargetFiringZOffset(Actor* actor, int type, bool flag)
{
    float f;
    Actor* act;
    bool b;

    if (actor->IsActor())
    {
        act = actor;
        b = act->FUN_004997b0() && !flag;
        f = b ? act->Actor_GetSneakHeight(0) : act->GetActorHeight();

        if (act->GetHasKnockedState() || act->Actor_IsSleeping() || act->HasHealth(false))
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
        CombatPoint3 p2;
        CombatPoint3 p1;
        return (reinterpret_cast<CombatPoint3* (__thiscall*)(Actor*, CombatPoint3*)>((*reinterpret_cast<void***>(actor))[0x1dc / 4])(actor, &p2)->z - reinterpret_cast<CombatPoint3* (__thiscall*)(Actor*, CombatPoint3*)>((*reinterpret_cast<void***>(actor))[0x1d8 / 4])(actor, &p1)->z) * actor->TESObjectREFR_GetScale_00567400() * 0.5f;
    }

    return 0.0f;
}

extern float DAT_011a5594;

struct NiVecOps
{
    void __thiscall SubtractIntoVector(CombatPoint3* tmp, CombatPoint3* src);
    float __thiscall FUN_004a7290();
    CombatPoint3* __thiscall ApplyScaled(CombatPoint3* out, float scale);
    CombatPoint3* __thiscall FUN_00439e90(CombatPoint3* tmp, CombatPoint3* ret);
};

void __cdecl GetPitchYaw(CombatPoint3* out, CombatPoint3 a, CombatPoint3 b);

// @fnv 0x009a8970
// src: XBOX_PDB 0x009a8970
CombatPoint3* __cdecl CombatUtilities_GetAngleToProjectedPoint_009a8970(CombatPoint3* out, CombatPoint3 a, CombatPoint3 b, float afUnused, CombatPoint3 c)
{
    CombatPoint3 tmp;
    float t3;
    float s2;
    CombatPoint3 r8;
    CombatPoint3 r3;

    if (a.x == b.x && a.y == b.y)
    {
        GetPitchYaw(out, a, c);
        return out;
    }

    reinterpret_cast<NiVecOps*>(&c)->SubtractIntoVector(&tmp, &b);
    t3 = reinterpret_cast<NiVecOps*>(&tmp)->FUN_004a7290();

    if ((double)t3 == DAT_01012060)
    {
        GetPitchYaw(out, a, c);
        return out;
    }

    if (t3 < DAT_011a5594 * DAT_011a5594)
    {
        s2 = NiSqrt_004579e0(t3);
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

struct TrajOut;
struct TrajVec
{
    float x;
    float y;
    float z;
};
// The shared projectile header does not yet declare its explosion accessor.
extern "C" void BGSProjectile_GetExplosion();

struct TrajWeapon
{
    float FUN_00477900();
    float FUN_006a78f0();
};

void __cdecl GetTargetLocationWithOffset(TrajVec* out, void* a3, int mode);
void __cdecl GetTriple12(TrajVec* out, void* a3);
void __cdecl BGSProjectile_UpdateState_009a8df0(TrajOut* out, Actor* target, TrajVec p, TrajVec q, void* a4, BGSProjectile* actor, float speed,
                          bool flag);

extern "C" double DAT_01012060;
extern "C" int DAT_011cebd4;
extern "C" int DAT_011cf270;
extern "C" int DAT_011ceb5c;

// Selects a trajectory mode from the target's auxiliary data and the actor's weapon/state, computes two vectors from a3, and delegates to FUN_009a8df0.
// @fnv 0x009a8bf0
TrajOut* __cdecl ComputeTrajectory(TrajOut* out, Actor* target, void* a3, void* a4, BGSProjectile* actor, float speed,
                                   bool flag)
{
    int mode = 1;
    if (target->IsActor())
    {
        Actor* obj5 = target;
        TrajAux* aux5 = (TrajAux*)obj5->GetCombatController();
        if (aux5 != 0)
        {
            mode = aux5->GetPackageRefCount();
        }
    }

    if (flag && actor->GetGravity_00966980() != DAT_01012060)
    {
        mode = 2;
    }
    else
    {
        bool f5;
        TrajWeapon* w2 = reinterpret_cast<TrajWeapon* (__thiscall*)(BGSProjectile*)>(BGSProjectile_GetExplosion)(actor);
        f5 = false;
        if (actor->GetHitScan() || (double)actor->GetFloatAtOffset68() >
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
    BGSProjectile_UpdateState_009a8df0(out, target, t3, t2, a4, actor, speed, flag);
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
S_009a8d80_P3 __cdecl BGSProjectile_UpdateState_009a8df0(TESObjectREFR* a1, S_009a8d80_P3 a2, S_009a8d80_P3 a3, S_009a8d80_Obj* a4,
                                   BGSProjectile* a5, float a6, bool a7);
// Forwards the reference, the point dereferenced from a2, DAT_011f426c, a3, a4, a5 and a6 to FUN_009a8df0 and returns its result.
// @fnv 0x009a8d80
// src: GUESS 0x009a8d80 (confidence: low)
S_009a8d80_P3 __cdecl TESObjectREFR_ForwardCall_009a8d80(TESObjectREFR* a1, const S_009a8d80_P3* pPoint, S_009a8d80_Obj* a3,
                                   BGSProjectile* a4, float a5, bool a6)
{
    return BGSProjectile_UpdateState_009a8df0(a1, *pPoint, DAT_011f426c, a3, a4, a5, a6);
}
}  // namespace fnv_009a8d80

struct FUN_009a8df0_vec
{
    void FUN_006815c0();
    float x;
    float y;
    float z;
};

FUN_009a8df0_vec* __cdecl CombatUtilities_GetAttackerFiringLocation(FUN_009a8df0_vec* tmp, int a);
void __cdecl CombatUtilities_GetProjectedPointForTarget(FUN_009a8df0_vec* out, FUN_009a8df0_vec c, FUN_009a8df0_vec b, FUN_009a8df0_vec a, float f1,
                          float f2, unsigned char flag);

// @fnv 0x009a8df0
// src: GUESS 0x009a8df0 (confidence: low)
FUN_009a8df0_vec* __cdecl BGSProjectile_UpdateState_009a8df0(FUN_009a8df0_vec* out, int a2, FUN_009a8df0_vec vecB, FUN_009a8df0_vec vecA,
                                       FUN_009a8df0_vec* p28, BGSProjectile* obj, float a30, unsigned char a34)
{
    float f;
    FUN_009a8df0_vec L;

    if (obj->GetHitScan())
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
        L = *CombatUtilities_GetAttackerFiringLocation(&T, a2);
    }
    f = obj->GetGravity_00966980() * DAT_011f1c00;
    if ((double)a30 == DAT_01012060)
    {
        a30 = obj->GetFloatAtOffset68();
    }
    CombatUtilities_GetProjectedPointForTarget(out, L, vecB, vecA, a30, f, a34);
    return out;
}

struct AimPoint
{
    float x, y, z;
    AimPoint SubtractIntoVector(const AimPoint& kOther) const;
    AimPoint FUN_00439e90(const AimPoint& kOther) const;
    AimPoint ApplyScaled(float fScale) const;
    float FUN_00457990() const;
};

struct AimIntSetting
{
    int* Setting_Int();
};
extern AimIntSetting g_s_011cfc08;

float __cdecl ComputeLaunchAngle(float fDist, float m_fGlyphExtent, float fSpeed, float afGravity, bool bArc);
float __cdecl CombatUtilities_ComputeProjectileTime(float fDist, float fAngleDifference, float fSpeed);
float __cdecl tan_0057dd70(float fAngleDifference);

// @fnv 0x009a8f00
// src: XBOX_PDB 0x009a8f00
AimPoint __cdecl CombatUtilities_GetProjectedPointForTarget(AimPoint kTarget, AimPoint kStart, AimPoint kMotionVelocity, float fSpeed,
                              float afGravity, bool bArc)
{
    int iIterationsVal2 = *g_s_011cfc08.Setting_Int();
    if (kMotionVelocity.x == 0.0 && kMotionVelocity.y == 0.0 && kMotionVelocity.z == 0.0)
        iIterationsVal2 = 1;
    float kFTime = 0.0f;
    AimPoint kPos4 = kStart;
    if (afGravity == 0.0)
    {
        float fDist = 0.0f;
        for (int i = 0; i < iIterationsVal2; i++)
        {
            AimPoint kDiff = kPos4.SubtractIntoVector(kTarget);
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
            AimPoint kDelta = kPos4.SubtractIntoVector(kTarget);
            kFHeight = kDelta.z;
            kDelta.z = 0.0f;
            fHorizDistX = kDelta.FUN_00457990();
            if (kFHeight > 8192.0 || fHorizDistX < 1.0 || fHorizDistX > 8192.0)
                break;
            fAngleTmp = ComputeLaunchAngle(fHorizDistX, kFHeight, fSpeed, afGravity, bArc);
            kFTime = CombatUtilities_ComputeProjectileTime(fHorizDistX, fAngleTmp, fSpeed);
            kPos4 = kStart.FUN_00439e90(kMotionVelocity.ApplyScaled(kFTime));
        }
        AimPoint kFlatVal2 = kPos4.SubtractIntoVector(kTarget);
        kFlatVal2.z = 0.0f;
        fHorizDistX = kFlatVal2.FUN_00457990();
        kPos4.z = tan_0057dd70(fAngleTmp) * fHorizDistX + kTarget.z;
    }
    return kPos4;
}

struct S_009a9180_Weapon
{
    float TESCombatStyle_GetWeaponMinRangeMult();
    float GetFieldAtOffset44();
};

struct S_009a9180_Data
{
    float GetFloatAt120();
    float GetField124Float();
    bool IsFlag20Set();
    BGSProjectile* GetOrFallback(int key);
};

struct S_009a9180_Setting
{
    float* Setting_Float_00403e20();
};

extern S_009a9180_Setting DAT_011ce87c;
extern S_009a9180_Setting DAT_011ceab0;

// @fnv 0x009a9180
// src: XBOX_PDB 0x009a9180
void CombatUtilities_ComputeOptimalWeaponRanges(Actor* pActor, S_009a9180_Data* pData, float* pfMin, float* pfMax, float* pfDerived)
{
    *pfMin = 512.0f;
    *pfMax = 1024.0f;
    S_009a9180_Weapon* pWeapon = (S_009a9180_Weapon*)pActor->GetCurrentCombatStyle();
    if (pData)
    {
        *pfMin = pData->GetFloatAt120();
        *pfMax = pData->GetField124Float();
        if (!pData->IsFlag20Set())
        {
            *pfMin = pWeapon->TESCombatStyle_GetWeaponMinRangeMult() * *pfMin;
            *pfMax = pWeapon->GetFieldAtOffset44() * *pfMax;
        }
        *pfDerived = *pfMax * *DAT_011ce87c.Setting_Float_00403e20();
        BGSProjectile* pObj = pData->GetOrFallback(pActor->GetFieldBC());
        if (pObj)
        {
            float fValue = CombatUtilities_GetProjectileMaximumRange(pObj, 0.0f);
            *pfMax = BSMIN(*pfMax, fValue * *DAT_011ceab0.Setting_Float_00403e20());
            *pfDerived = BSMIN(*pfDerived, fValue);
            Standin77900* pProjectile = reinterpret_cast<Standin77900* (__thiscall*)(BGSProjectile*)>(BGSProjectile_GetExplosion)(pObj);
            if (pProjectile)
                *pfMin = BSMAX_00404010(*pfMin, pProjectile->FUN_00477900());
            *pfMin = BSMIN(*pfMin, *pfMax - 256.0);
            *pfMin = BSMAX_00404010(*pfMin, 0.0f);
        }
    }
    else
    {
        *pfMin = pWeapon->TESCombatStyle_GetWeaponMinRangeMult() * *pfMin;
        *pfMax = pWeapon->GetFieldAtOffset44() * *pfMax;
        *pfDerived = *pfMax * *DAT_011ce87c.Setting_Float_00403e20();
    }
}

struct DebugPoint
{
    float x;
    float y;
    float z;
    DebugPoint SubtractIntoVector(const DebugPoint& kPt) const;
    DebugPoint ApplyScaled(float fScale) const;
    DebugPoint FUN_00439e90(const DebugPoint& kPt) const;
};

extern TES* g_TES;

class GlobalObject_0044f440
{
  public:
    float* Float();
};
extern GlobalObject_0044f440 g_011f1c24;

NiAVObject* __cdecl MakeLine(const DebugPoint& kStart, const NiColorA& kStartColor, const DebugPoint& kEnd,
                                 const NiColorA& kEndColor, bool bArg);
NiAVObject* __cdecl CreateOctahedron(float fRadius, const NiColorA& kColor, bool bArg);

// @fnv 0x009a9f20
void __cdecl DrawDebugLine(const DebugPoint& kStart, const DebugPoint& kEnd, int bScaled, float fScale,
                           const NiColorA* pkLineColor, const NiColorA* pkTipColor)
{
    NiColorA aKTipColor = pkTipColor ? *pkTipColor : NiColorA(1.0f, 0.0f, 0.0f, 1.0f);
    NiColorA kLineColor6 = pkLineColor ? *pkLineColor : NiColorA(1.0f, 1.0f, 0.0f, 1.0f);
    DebugPoint kMid = bScaled ? (kEnd.SubtractIntoVector(kStart)).ApplyScaled(fScale).FUN_00439e90(kStart) : kEnd;
    NiAVObject* pkLine_ = MakeLine(kStart, kLineColor6, kMid, kLineColor6, true);
    g_TES->FUN_00458e20(pkLine_, *g_011f1c24.Float());
    if (bScaled)
    {
        NiAVObject* pkSphere4 = CreateOctahedron(5.0f, aKTipColor, true);
        pkSphere4->UpdateProperties();
        pkSphere4->NiAVObject_SetTranslate(kMid);
        g_TES->FUN_00458e20(pkSphere4, *g_011f1c24.Float());
        NiAVObject* pkTipLine = MakeLine(kMid, aKTipColor, kEnd, aKTipColor, true);
        g_TES->FUN_00458e20(pkTipLine, *g_011f1c24.Float());
    }
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting595;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting604;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting605;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting606;

// Returns the float value of one of four runtime float settings, chosen by id in the range 0x5c-0x66; ids outside that range use the default setting.
// @fnv 0x009a6a40
// src: COMMUNITY 0x009a6a40
float __cdecl GetCombatHitConesAngles(int aiSettingId)
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

struct CombatPlanningPosition
{
    CombatPoint3 origin;
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

struct Holder
{
    Actor** __thiscall BSSimpleArray_NiAVObject_1024_GetAt(int i);
    unsigned int __thiscall FUN_0044ddc0();
};

struct Mgr
{
    Holder* __thiscall FUN_009a4250(Actor* a);
};

struct Glob
{
    Mgr* __thiscall FUN_00441110();
};

struct FUN_006d5320
{
    CombatPlan* obj;
    NiPoint3 pos;
    float angle;
    char dir;
    unsigned char flag;
    FUN_006d5320();
};

void __cdecl ourMemset(void* p, int v, unsigned int n);
extern Glob* DAT_011f1958;
unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
float __cdecl GetDirectionAngle(const NiPoint3& p);
long __cdecl ScaleByRatio(float a);
float __cdecl ScaleCharToFloat(char a);
unsigned char FindSlot_009a98a0(unsigned int a, unsigned char b);
int ExpandFlagBits(int flags, char index);

// @fnv 0x009a9a20
bool AssignCombatPlanAngles(Actor* apRef, Actor* apTargetRef)
{
    bool result;
    result = false;
    if (apRef == 0)
        return result;
    Holder* ptr = DAT_011f1958->FUN_00441110()->FUN_009a4250(apRef);
    if (!!ptr)
    {
        CombatPlanningPosition layout;
        layout.origin = *(CombatPoint3*)apRef->FUN_00436aa0();
        FUN_006d5320 holder[64];
        ourMemset(holder, 0, 0x600);
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
                    Actor* slot = *ptr->BSSimpleArray_NiAVObject_1024_GetAt(e);
                    {
                        CombatPlan* m;
                        m = slot ? (CombatPlan*)slot->GetCombatController() : 0;
                        if (m)
                        {
                            if ((m->CombatController_CombatPlanContainsAction(7) || m->CombatController_CombatPlanContainsAction(8)))
                            {
                                holder[layout.count].obj = m;
                                holder[layout.count].pos = *(NiPoint3*)slot->FUN_00436aa0();
                                holder[layout.count].angle =
                                    57.2957763671875f *
                                    GetDirectionAngle(holder[layout.count].pos.SubtractIntoVector(*(const NiPoint3*)&layout.origin));
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
                                char val = FindSlot_009a98a0(flags, holder[j].dir);
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
                            char val = FindSlot_009a98a0(flags, holder[k].dir);
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

S_009a82b0_Point3 CombatUtilities_GetAttackerFiringLocationSimple(Actor* actor);
S_009a6d70_Point CombatUtilities_GetAngleToProjectedPoint_009a8970(FUN_009a8df0_vec a, S_009a82b0_Point3 b, float time, CombatPoint3 target);
// Calls FUN_009a8970 with FUN_009a8050's output, FUN_009a8250(actor), zero time, and target.
// @fnv 0x009a88e0
// src: XBOX_PDB 0x009a88e0
S_009a6d70_Point CombatUtilities_GetAngleToProjectedPoint(Actor* actor, CombatPoint3 target)
{
    FUN_009a8df0_vec direction;
    CombatUtilities_GetAttackerFiringLocation(&direction, (int)actor);
    float time = 0.0f;
    return CombatUtilities_GetAngleToProjectedPoint_009a8970(direction, CombatUtilities_GetAttackerFiringLocationSimple(actor), time, target);
}

extern double DAT_0101ff58;
float __cdecl NiASin_004b54c0(float fValue);
float __cdecl FUN_004b1550(NiPoint3* pkPt);

// Computes two angles from the point difference, adjusts each using the shown 2π bounds, and returns them in x and z.
// @fnv 0x009a8af0
NiPoint3 GetPitchYaw(NiPoint3 kFrom, NiPoint3 kTo)
{
    float fHeadingAngle;
    float fClampedPitch;
    NiPoint3 kPt = kTo - kFrom;
    float m_fGlyphExtent = kPt.z;
    float fLen = kPt.FUN_00457910();
    float fAsin = NiASin_004b54c0(m_fGlyphExtent / fLen);
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
    return NiPoint3(fClampedPitch, 0.0f, fResultYaw);
}

namespace s9a8050 {

struct Weapon
{
    bool TESObjectWEAP_IsRangedWeapon();
    int FUN_00446390();
};

struct Process
{
    Weapon* GetCurrentWeapon();
};

extern PlayerCharacter* DAT_011dea3c;

float GetScaleOrHeightDelta(Actor* pkActor, int iUnk);

// Returns a head or bone position when available; otherwise adds a height delta to the reference position.
// @fnv 0x009a8050
// src: XBOX_PDB 0x009a8050
CombatPoint3 CombatUtilities_GetAttackerFiringLocation(Actor* pkRef)
{
    CombatPoint3 kPos;
    if (pkRef->IsActor())
    {
        Actor* pkActor = pkRef;
        bool bIsPC = pkActor == DAT_011dea3c;
        Weapon* pkWeap = 0;
        // The shared process accessor is nonvirtual; the original dispatches through slot 0x428.
        Process* pkProc = reinterpret_cast<Process* (__thiscall*)(Actor*)>((*reinterpret_cast<void***>(pkActor))[0x428 / 4])(pkActor);
        if (pkProc)
            pkWeap = pkProc->GetCurrentWeapon();
        else
            pkWeap = (Weapon*)pkActor->Actor_GetCurrentWeapon();
        if (!pkWeap || pkWeap->TESObjectWEAP_IsRangedWeapon())
        {
            NiNode* pkRoot = (NiNode*)pkActor->FUN_008d8520();
            if (pkActor && pkRoot &&
                (!pkWeap || pkWeap->FUN_00446390() == 0xa || pkWeap->FUN_00446390() == 0xb ||
                 pkWeap->FUN_00446390() == 0xd || pkWeap->FUN_00446390() == 0xc))
            {
                int iBone = bIsPC ? DAT_011dea3c->GetBiped(DAT_011dea3c->PlayerCharacter_Is3rdPerson()) : reinterpret_cast<int (__thiscall*)(Actor*)>((*reinterpret_cast<void***>(pkActor))[0x1EC / 4])(pkActor);
                // The shared bone lookup is nonvirtual; this call uses the original slot 0x190.
                NiAVObject* pkBone = reinterpret_cast<NiAVObject* (__thiscall*)(NiNode*, int)>(
                    (*reinterpret_cast<void***>(pkRoot))[100])(pkRoot, iBone);
                if (pkBone)
                    return *(const CombatPoint3*)&pkBone->NiAVObject_GetWorldTranslate();
            }
            else
            {
                NiAVObject* pkHead = reinterpret_cast<NiAVObject* (__thiscall*)(Actor*)>((*reinterpret_cast<void***>(pkActor))[0x20C / 4])(pkActor);
                if (pkHead)
                    return *(const CombatPoint3*)&pkHead->NiAVObject_GetWorldTranslate();
            }
        }
    }
    kPos = *(CombatPoint3*)static_cast<const TESObjectREFR*>(pkRef)->GetPos();
    kPos.z += GetScaleOrHeightDelta(pkRef, 0);
    return kPos;
}

}
