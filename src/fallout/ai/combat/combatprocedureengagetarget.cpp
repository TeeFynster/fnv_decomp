#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/CombatProcedureEngageTarget.h"
#include "../../../../include/CombatTargetTimestamp.h"
#include "../../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
// PathRequest_combatprocedureengagetarget: local type (was include/PathRequest.h, which had no evidence of one real class); its methods are 0x0048d150 TESModel::GetTextureList, 0x006a9560 TESCombatStyle::GetPowerAttackL, 0x006e2980 PathingRequest::SetCenterRadius, 0x006e2b20 PathingRequest::SetActorLockData
class RawPoint;
class PathActor;

class PathRequest_combatprocedureengagetarget
{
public:
    unsigned int unk00[44];

    PathRequest_combatprocedureengagetarget();
    ~PathRequest_combatprocedureengagetarget();
    RawPoint* GetDirection(RawPoint* out);
    void SetDirection(RawPoint* dir, float dist);
    void Update(PathActor*);
    bool IsValid();
    float GetCenterRadius();
};
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/Vec4.h"

// src/fallout/ai/combat/combatprocedureengagetarget.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureengagetarget.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x009d3b50
void CombatProcedureEngageTarget::Unk0c()
{
    ResetCombatState();
    GetActor()->StopMoving();
    ((CombatProcedure*)this)->RunProcedure();
}

void __cdecl operator delete(void*);

// The compiler also supplies the scalar deleting destructor at 0x009d3b00.
// @fnv 0x009d3b30
CombatProcedureEngageTarget::~CombatProcedureEngageTarget()
{}

struct CoordinateTriple
{
    void BGSWorldLocation_SaveGame(void*);
};

// Retained: TimeoutTimer.h does not declare SaveGame (0x009a5eb0).
struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer*);
};

// @fnv 0x009d5880
void CombatProcedureEngageTarget::SaveGame(BGSSaveFormBuffer* buffer)
{
    CombatProcedure::SaveGame(buffer);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x14), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x18), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x1C), 4, 0);

    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x20)->FUN_009a5eb0(buffer);
    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x28)->FUN_009a5eb0(buffer);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x30), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x31), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x32), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34), 12, 0);

    reinterpret_cast<CoordinateTriple*>(reinterpret_cast<char*>(this) + 0x40)->BGSWorldLocation_SaveGame(buffer);
    reinterpret_cast<CoordinateTriple*>(reinterpret_cast<char*>(this) + 0x50)->BGSWorldLocation_SaveGame(buffer);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x33), 1, 0);

    reinterpret_cast<CombatTargetTimestamp*>(reinterpret_cast<char*>(this) + 0x60)->SaveTimeStamp(buffer);
}

namespace fnv_009d5990 {

struct FUN_00527ba0_Class
{
    void BGSLoadGameBuffer_LoadBGSWorldLocation(void* buffer);
};

extern float DAT_01022958;

}  // namespace fnv_009d5990

// Loads the combat procedure's fields from the buffer, reading a version-gated float and two sub-objects, with extra fields for versions 10 and 14.
// @fnv 0x009d5990
void CombatProcedureEngageTarget::LoadGame(BGSLoadFormBuffer* buffer)
{
    using namespace fnv_009d5990;
    CombatProcedure::LoadGame(buffer);

    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4u);
    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x14), 4u);
    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x18), 4u);

    if (buffer->GetVersion() >= 14)
    {
        buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x1c), 4u);
    }
    else
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1c) = DAT_01022958;
    }

    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x20)->LoadGame(buffer);
    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x28)->LoadGame(buffer);

    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x30), 1u);
    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x31), 1u);
    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x32), 1u);
    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34), 12u);

    reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x40)->BGSLoadGameBuffer_LoadBGSWorldLocation(buffer);
    reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x50)->BGSLoadGameBuffer_LoadBGSWorldLocation(buffer);

    if (buffer->GetVersion() >= 10)
    {
        buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x33), 1u);
        reinterpret_cast<CombatTargetTimestamp*>(reinterpret_cast<char*>(this) + 0x60)->LoadGame(buffer);
    }
}

namespace Engage {
extern const double DAT_01020998, DAT_01011588;
extern const float DAT_0101e57c;
extern bool DAT_011a5b70;
struct Timer
{
    float value;
    double FUN_00435e00();
};
struct Query
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Query();
    Vec4& FUN_006815c0();
    void* CombatLocation_GetPoint();
};
struct RequestA
{
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
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    RequestA();
    ~RequestA();
    void PathingRequestClosePoint_SetMinDistance(float);
    void SetMaxDistance_006e5ee0(float);
    void PathingRequestCoveredMove_SetAttackerHeight(float);
    void PathingRequestCoveredMove_SetAttackerSneakHeight(float);
};
struct Controller
{
    bool CombatState_FindOptimalLocation(float, float, float, float, Query*, bool);
    bool CombatState_CheckMovement_009a02a0(const Vec4&, bool, bool);
};
struct Context
{
    Controller* CombatController_GetCombatState();
};
// Retained: CombatProcedureEngageTarget.h lacks these fields and the pathing helper declarations.
struct Procedure
{
    int unk00;
    Context* context;
    int unk08, unk0c, unk10;
    float range, height, angle;
    int unk20, unk24, unk28, unk2c;
    char unk30, unk31, unk32;
    bool active;
    int unk34, unk38, unk3c;
    Vec4 point, target;
    Timer time;
    Actor* CombatProcedure_GetAttacker();
    Actor* GetTarget_00996e00();
    void SetMoveMode_00996e20(int);
    bool CheckAndApply(bool);
};
// @fnv 0x009d5000
bool Procedure::CheckAndApply(bool mode)
{
    if (time.FUN_00435e00() < DAT_01020998)
        return false;
    active = true;
    if (DAT_011a5b70)
    {
        Actor* actor = CombatProcedure_GetAttacker();
        Actor* targetActor3 = GetTarget_00996e00();
        RequestA request;
        actor->PathToLocation(&request, static_cast<const Actor*>(targetActor3)->GetPos(), actor->FUN_008d6f30(),
                              actor->TESObjectREFR_GetWorldSpace(DAT_0101e57c), false);
        request.PathingRequestClosePoint_SetMinDistance(range);
        request.SetMaxDistance_006e5ee0(height);
        request.PathingRequestCoveredMove_SetAttackerHeight(range * DAT_01011588);
        request.PathingRequestCoveredMove_SetAttackerSneakHeight(angle);
        if (!actor->SetPathingRequestAvoidNodes(&request))
            return false;
        target = targetActor3->TESObjectREFR_GetWorldLocation();
        SetMoveMode_00996e20(mode ? 3 : 1);
        active = false;
        return true;
    }
    else
    {
        Actor* actor2 = CombatProcedure_GetAttacker();
        Actor* targetActor2 = GetTarget_00996e00();
        Query query2;
        Controller* controller5 = context->CombatController_GetCombatState();
        if (!controller5->CombatState_FindOptimalLocation(range, height, range * DAT_01011588, angle, &query2, true))
            return false;
        if (!controller5->CombatState_CheckMovement_009a02a0(query2.FUN_006815c0(), true, false))
            return false;
        PathRequest_combatprocedureengagetarget request2;
        actor2->PathToLocation(&request2, query2.CombatLocation_GetPoint(), actor2->FUN_008d6f30(),
                               actor2->TESObjectREFR_GetWorldSpace(DAT_0101e57c), false);
        if (!actor2->SetPathingRequestAvoidNodes(&request2))
            return false;
        point = query2.FUN_006815c0();
        target = targetActor2->TESObjectREFR_GetWorldLocation();
        SetMoveMode_00996e20(mode ? 3 : 1);
        return true;
    }
}
}

namespace fnv_009d5410 {
static const char text_0[] = "INITIALIZING";
static const char text_1[] = "HOLDING";
static const char text_2[] = "Holding Timer: %.02f/%.02f";
static const char text_3[] = "CROUCHING";
static const char text_4[] = "Crouching Timer: %.02f/%.02f";
static const char text_5[] = "MOVING_OPTIMAL_CLOSE";
static const char text_6[] = "Range: %.2f - %.2f";
static const char text_7[] = "Target movement distance: %.2f/%.2f";
static const char text_8[] = "MOVING_OPTIMAL_FAR";
static const char text_9[] = "Range: %.2f - %.2f";
static const char text_10[] = "Target movement distance: %.2f/%.2f";
static const char text_11[] = "APPROACHING_TARGET";
static const char text_12[] = "DODGING FORWARD/BACKWARD";
static const char text_13[] = "DODGING LEFT/RIGHT";
static const char text_14[] = "Lost LOS.  Stop Moving Timer: %.02f/%.02f";
static const char text_15[] = "MOVING_TO_TARGET";
static const char text_16[] = "Optimal location pathing CheckMovement failed: %.02f/%.02f";
static const char text_17[] = "Optimal location pathing LOS check failed: %.02f/%.02f";
static const char text_18[] = "Optimal location path building failed: %.02f/%.02f";
/// Position + cell/world id at +0x0c (16 bytes); Distance at 0x00527a80 (FUN_00527a80_shell::DistanceTo in
// bgsworldlocation.cpp) returns FLT_MAX when the ids differ. Not the 12-byte shared NiPoint3.
struct WorldLocation
{
    float x, y, z;
    int world;
    float Distance(WorldLocation*);
};
struct Timer
{
    float start;
    float value;
    float Elapsed();
    float Value();
    bool Active();
    float Remaining();
};
struct Output
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void __cdecl Print(int, int, const char*, ...);
};
// Retained: CombatProcedureEngageTarget.h lacks this debug view and PrintDebugInfo.
struct Engage
{
    int unk00, unk04, unk08, unk0c;
    unsigned state;
    float range14, range18;
    int unk1c;
    Timer timer20, timer28;
    bool enabled;
    char unk31, unk32;
    signed char result;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    WorldLocation target;
    Timer timer60;
    Actor* GetRef();
    void PrintDebugInfo(Output* out, int a, int b);
};
// Prints state-specific debug text for the engage state, plus a timer-based message when timer60 has elapsed less than 5 seconds.
// @fnv 0x009d5410
void Engage::PrintDebugInfo(Output* pOutput, int a, int b)
{
    Actor* actor = GetRef();
    switch (state)
    {
    case 0:
        pOutput->Print(a, b, text_0);
        break;
    case 1:
        pOutput->Print(a, b, text_1);
        pOutput->Print(a, b, text_2, timer20.Elapsed(), timer20.Value());
        break;
    case 2:
        pOutput->Print(a, b, text_3);
        pOutput->Print(a, b, text_4, timer20.Elapsed(), timer20.Value());
        break;
    case 3:
        pOutput->Print(a, b, text_5);
        pOutput->Print(a, b, text_6, range14, range18);
        if (actor)
        {
            WorldLocation location = actor->TESObjectREFR_GetWorldLocation<WorldLocation>();
            pOutput->Print(a, b, text_7, location.Distance(&target), 200.0);
        }
        break;
    case 4:
        pOutput->Print(a, b, text_8);
        pOutput->Print(a, b, text_9, range14, range18);
        if (actor)
        {
            WorldLocation location = actor->TESObjectREFR_GetWorldLocation<WorldLocation>();
            pOutput->Print(a, b, text_10, location.Distance(&target), 200.0);
        }
        break;
    case 5:
        pOutput->Print(a, b, text_11);
        break;
    case 8:
        pOutput->Print(a, b, text_15);
        break;
    case 6:
        pOutput->Print(a, b, text_12);
        break;
    case 7:
        pOutput->Print(a, b, text_13);
        if (enabled && timer28.Active())
        {
            pOutput->Print(a, b, text_14, timer28.Elapsed(), timer28.Value());
        }
        break;
    }
    if (timer60.Elapsed() < 5.0)
    {
        if (result == -1)
        {
            pOutput->Print(a, b, text_16, timer60.Remaining(), 5.0);
        }
        else if (result == -2)
        {
            pOutput->Print(a, b, text_17, timer60.Remaining(), 5.0);
        }
        else
        {
            pOutput->Print(a, b, text_18, timer60.Remaining(), 5.0);
        }
    }
}
}  // namespace fnv_009d5410

class RawPoint
{
public:
    float x, y, z;
    void FUN_005c3420();
};

namespace fnv_009d3b80 {

struct Location
{
    RawPoint pos;
    void* cell;
    NiPoint3* GetPos();
    void* GetContainingCell();
    float GetDistSq(Location* other);
    void GetCoords(int* a, int* b);
    void SetPos(NiPoint3* p);
    void InitializeForCell(void* c);
};

struct Stamp
{
    float m_fTime;
    Stamp(float t);
    float Elapsed();
};

struct SearchRequest
{
    unsigned int unk00[8];
    SearchRequest();
    void* GetResult();
};

struct ProcessObj
{
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
    virtual void w032();
    virtual void w033();
    virtual void w034();
    virtual void w035();
    virtual void w036();
    virtual void w037();
    virtual void w038();
    virtual void w039();
    virtual void w03a();
    virtual void w03b();
    virtual void w03c();
    virtual void w03d();
    virtual void w03e();
    virtual void w03f();
    virtual void w040();
    virtual void w041();
    virtual void w042();
    virtual void w043();
    virtual void w044();
    virtual void w045();
    virtual void w046();
    virtual void w047();
    virtual void w048();
    virtual void w049();
    virtual void w04a();
    virtual void w04b();
    virtual void w04c();
    virtual void w04d();
    virtual void w04e();
    virtual void w04f();
    virtual void w050();
    virtual void w051();
    virtual void w052();
    virtual void w053();
    virtual void w054();
    virtual void w055();
    virtual void w056();
    virtual void w057();
    virtual void w058();
    virtual void w059();
    virtual void w05a();
    virtual void w05b();
    virtual void w05c();
    virtual void w05d();
    virtual void w05e();
    virtual void w05f();
    virtual void w060();
    virtual void w061();
    virtual void w062();
    virtual void w063();
    virtual void w064();
    virtual void w065();
    virtual void w066();
    virtual void w067();
    virtual void w068();
    virtual void w069();
    virtual void w06a();
    virtual void w06b();
    virtual void w06c();
    virtual void w06d();
    virtual void w06e();
    virtual void w06f();
    virtual void w070();
    virtual void w071();
    virtual void w072();
    virtual void w073();
    virtual void w074();
    virtual void w075();
    virtual void w076();
    virtual void w077();
    virtual void w078();
    virtual void w079();
    virtual void w07a();
    virtual void w07b();
    virtual void w07c();
    virtual void w07d();
    virtual void w07e();
    virtual void w07f();
    virtual void w080();
    virtual void w081();
    virtual void w082();
    virtual void w083();
    virtual void w084();
    virtual void w085();
    virtual void w086();
    virtual void w087();
    virtual void w088();
    virtual void w089();
    virtual void w08a();
    virtual void w08b();
    virtual void w08c();
    virtual void w08d();
    virtual void w08e();
    virtual void w08f();
    virtual void w090();
    virtual void w091();
    virtual void w092();
    virtual void w093();
    virtual void w094();
    virtual void w095();
    virtual void w096();
    virtual void w097();
    virtual void w098();
    virtual void w099();
    virtual void w09a();
    virtual void w09b();
    virtual void w09c();
    virtual void w09d();
    virtual void w09e();
    virtual void w09f();
    virtual void w0a0();
    virtual void w0a1();
    virtual void w0a2();
    virtual void w0a3();
    virtual void w0a4();
    virtual void w0a5();
    virtual void w0a6();
    virtual void w0a7();
    virtual void w0a8();
    virtual void w0a9();
    virtual void w0aa();
    virtual void w0ab();
    virtual void w0ac();
    virtual void w0ad();
    virtual void w0ae();
    virtual void w0af();
    virtual void w0b0();
    virtual void w0b1();
    virtual void w0b2();
    virtual void w0b3();
    virtual void w0b4();
    virtual void w0b5();
    virtual void w0b6();
    virtual void w0b7();
    virtual void w0b8();
    virtual void w0b9();
    virtual void w0ba();
    virtual void w0bb();
    virtual void w0bc();
    virtual void w0bd();
    virtual void w0be();
    virtual void w0bf();
    virtual void w0c0();
    virtual void w0c1();
    virtual void w0c2();
    virtual void w0c3();
    virtual void w0c4();
    virtual void w0c5();
    virtual void w0c6();
    virtual void w0c7();
    virtual void w0c8();
    virtual void w0c9();
    virtual void w0ca();
    virtual void w0cb();
    virtual void w0cc();
    virtual void w0cd();
    virtual void w0ce();
    virtual void w0cf();
    virtual void w0d0();
    virtual void w0d1();
    virtual void w0d2();
    virtual void w0d3();
    virtual void w0d4();
    virtual void w0d5();
    virtual void w0d6();
    virtual void w0d7();
    virtual void w0d8();
    virtual void w0d9();
    virtual void w0da();
    virtual void w0db();
    virtual void w0dc();
    virtual void w0dd();
    virtual void w0de();
    virtual void w0df();
    virtual void w0e0();
    virtual void w0e1();
    virtual void w0e2();
    virtual void w0e3();
    virtual void w0e4();
    virtual void w0e5();
    virtual void w0e6();
    virtual void w0e7();
    virtual void w0e8();
    virtual void w0e9();
    virtual void w0ea();
    virtual void w0eb();
    virtual void w0ec();
    virtual void w0ed();
    virtual void w0ee();
    virtual void w0ef();
    virtual void w0f0();
    virtual void w0f1();
    virtual void w0f2();
    virtual void w0f3();
    virtual void w0f4();
    virtual void w0f5();
    virtual void w0f6();
    virtual void w0f7();
    virtual void w0f8();
    virtual void w0f9();
    virtual void w0fa();
    virtual void w0fb();
    virtual void w0fc();
    virtual void w0fd();
    virtual void w0fe();
    virtual void w0ff();
    virtual void w100();
    virtual void w101();
    virtual bool CheckFlag(int flag);
};

// These pathing methods are not declared by Actor.h yet. The shared Actor supplies
// the complete object layout and virtual table; this helper adds declarations only.
struct ActorPathingAccess : Actor
{
    void BuildPathTo(PathRequest_combatprocedureengagetarget* req, NiPoint3* pos, void* cell, float radius, int flags);
    bool PathHasError();
    void StopPathAlt();
    bool GetFallbackPos(NiPoint3* out);
};

struct CombatCtrlObj
{
    bool GetAvoidPos(NiPoint3* out);
    Stamp GetLastSeen();
    bool CanReach(Location* loc, int a, int b);
    bool IsCovered();
    bool FindDodge(SearchRequest* req, int mode, int a, float dist, float maxDist);
    bool CanReachPos(NiPoint3* pos, void* cell, int a, int b);
    void OnPathFailed();
    void SetDestination(Location* loc);
};

struct CombatOwner
{
    CombatCtrlObj* GetCombatCtrl();
    bool HasTarget();
    void* GetGroup();
};

extern float DAT_01016248;
extern float DAT_0101e2bc;
extern double DAT_01011588;
extern double DAT_01091138;
extern float DAT_01012054;
extern double DAT_01012070;
extern float DAT_010162c0;
extern float DAT_01032adc;
extern float DAT_0101e704;
extern float DAT_0104e0e8;
extern float DAT_0101e57c;
extern double DAT_010231d8;
extern float DAT_0101622c;
extern float DAT_01050b98;
extern float DAT_010536b8;
extern float DAT_0101e6ec;
extern float DAT_0101712c;
extern double DAT_0108e058;
extern float DAT_01013ea4;

float __cdecl RandRange(float lo, float hi);
bool __cdecl RandChance(float p);
float __cdecl GetCurrentTime();
void __cdecl UpdateRanges(CombatOwner* owner, void* group, float* a, float* b, float* c);
bool __cdecl FindNavPos(int a, int b, NiPoint3* pos, NiPoint3* out);
bool __cdecl CheckLineOfFire(Actor* actor, Actor* target, NiPoint3* pos, NiPoint3* look, int a, int b);

// Retained: CombatProcedureEngageTarget.h lacks this layout and the engagement helper declarations.
class EngageProc
{
  public:
    void* vtbl;
    CombatOwner* m_pSharedOwner;
    int unk08;
    int unk0C;
    int m_iFadeIndex;
    float m_fMinRange;
    float m_fMaxRange;
    float m_fFarRange;
    TimeoutTimer m_timer20;
    TimeoutTimer m_timer28;
    bool m_bDodgeWait;
    bool m_bCovered;
    bool m_bDodging;
    signed char m_cFallback;
    NiPoint3 m_dodgePos;
    Location m_dest;
    Location m_lastTarget;
    Stamp m_stamp60;

    Actor* GetActor();
    Actor* GetTarget();
    void SetAvoid(NiPoint3* pos, bool b);
    void UpdatePlayerStatus(int mode);
    void StopMove();
    void Fail(const char* msg);
    bool TryAttack(bool b);
    bool IsAimingWeapon();
    void ResetState();
    void UpdateEngagement();
};

// @fnv 0x009d3b80
void EngageProc::UpdateEngagement()
{
    Actor* actorZ = GetActor();
    Actor* target = GetTarget();
    CombatCtrlObj* ctrlD = m_pSharedOwner->GetCombatCtrl();
    if (target == 0)
    {
        return;
    }
    NiPoint3 avoidPos2;
    if (ctrlD->GetAvoidPos(&avoidPos2))
    {
        SetAvoid(&avoidPos2, true);
    }
    if (!m_pSharedOwner->HasTarget())
    {
        m_iFadeIndex = 1;
        return;
    }
    float oldMinB = m_fMinRange;
    float oldMax = m_fMaxRange;
    UpdateRanges(m_pSharedOwner, m_pSharedOwner->GetGroup(), &m_fMinRange, &m_fMaxRange, &m_fFarRange);
    bool changed = false;
    if (oldMinB != m_fMinRange || oldMax != m_fMaxRange)
    {
        changed = true;
    }
    Location targetLocX;
    target->TESObjectREFR_GetWorldLocation(static_cast<void*>(&targetLocX));
    Location actorLocY;
    actorZ->TESObjectREFR_GetWorldLocation(static_cast<void*>(&actorLocY));
    float distSqD = actorLocY.GetDistSq(&targetLocX);
    bool tooFar4 = distSqD > m_fMaxRange * m_fMaxRange;
    bool tooClose4 = distSqD < m_fMinRange * m_fMinRange;
    bool veryFar5 = distSqD > m_fFarRange * m_fFarRange;

    switch (m_iFadeIndex)
    {
    case 0:
        m_timer20.Start(RandRange(DAT_0101e2bc, DAT_01016248));
        m_iFadeIndex = 1;
        break;
    case 1:
    case 2: {
        if (ctrlD->GetLastSeen().Elapsed() > DAT_01011588 && distSqD < DAT_01091138 &&
            ctrlD->CanReach(&targetLocX, 1, 0))
        {
            PathRequest_combatprocedureengagetarget req;
            static_cast<ActorPathingAccess*>(actorZ)->BuildPathTo(
                &req, targetLocX.GetPos(), targetLocX.GetContainingCell(), DAT_01012054, 0);
            if (actorZ->SetPathingRequestAvoidNodes(&req))
            {
                m_dest = targetLocX;
                UpdatePlayerStatus(1);
                m_iFadeIndex = 5;
                return;
            }
        }
        if (m_bCovered)
        {
            if (reinterpret_cast<CombatTargetTimestamp*>(&m_timer20)->ElapsedTime() < DAT_01011588)
            {
                if (!ctrlD->IsCovered())
                {
                    m_bDodging = true;
                    m_bCovered = false;
                }
            }
            else
            {
                m_bCovered = false;
            }
        }
        if (m_bDodging)
        {
            if (m_timer20.Expired() || reinterpret_cast<CombatTargetTimestamp*>(&m_timer20)->ElapsedTime() > DAT_01012070)
            {
                m_bCovered = false;
                m_bDodging = false;
                m_bDodgeWait = ctrlD->IsCovered();
                m_timer28.Reset();
                PathRequest_combatprocedureengagetarget req2;
                actorZ->PathToLocation(reinterpret_cast<PathingRequest*>(&req2), *reinterpret_cast<const NiPoint3*>(&m_dodgePos),
                                       actorZ->FUN_008d6f30(), reinterpret_cast<void*>(actorZ->TESObjectREFR_GetWorldSpace()),
                                       0.0f, 0);
                if (actorZ->SetPathingRequestAvoidNodes(&req2))
                {
                    UpdatePlayerStatus(1);
                    m_iFadeIndex = 7;
                    return;
                }
            }
        }
        if (tooFar4 || tooClose4)
        {
            float threshold = DAT_010162c0;
            if (tooFar4 && veryFar5)
            {
                threshold = DAT_0101e2bc;
            }
            if (m_timer20.Expired() || threshold < reinterpret_cast<CombatTargetTimestamp*>(&m_timer20)->ElapsedTime())
            {
                if (TryAttack(veryFar5))
                {
                    if (tooFar4)
                    {
                        m_iFadeIndex = 3;
                    }
                    else
                    {
                        m_iFadeIndex = 4;
                    }
                    return;
                }
                if (!veryFar5)
                {
                    SearchRequest search;
                    float dodgeDist = RandRange(DAT_0101e704, DAT_01032adc);
                    if (ctrlD->FindDodge(&search, tooFar4 ? 4 : 8, 0, dodgeDist, DAT_0104e0e8))
                    {
                        PathRequest_combatprocedureengagetarget req34;
                        actorZ->PathToLocation(
                            reinterpret_cast<PathingRequest*>(&req34), *reinterpret_cast<const NiPoint3*>(search.GetResult()),
                            actorZ->FUN_008d6f30(), reinterpret_cast<void*>(actorZ->TESObjectREFR_GetWorldSpace()), DAT_0101e57c, 0);
                        RawPoint dir;
                        req34.GetDirection(&dir)->FUN_005c3420();
                        req34.SetDirection(&dir, dodgeDist + DAT_010231d8);
                        if (!actorZ->SetPathingRequestAvoidNodes(&req34))
                        {
                            Fail("Cannot setup path to dodge location");
                            return;
                        }
                        UpdatePlayerStatus(1);
                        m_iFadeIndex = 6;
                        return;
                    }
                }
                else
                {
                    if (ctrlD->CanReach(&targetLocX, 1, 0))
                    {
                        PathRequest_combatprocedureengagetarget req4;
                        static_cast<ActorPathingAccess*>(actorZ)->BuildPathTo(
                            &req4, targetLocX.GetPos(), targetLocX.GetContainingCell(), DAT_0101e704, 0);
                        if (!actorZ->SetPathingRequestAvoidNodes(&req4))
                        {
                            Fail("Cannot setup path to target location");
                            return;
                        }
                        m_dest = targetLocX;
                        UpdatePlayerStatus(3);
                        m_iFadeIndex = 8;
                        return;
                    }
                    else
                    {
                        int coordX3 = 0;
                        int coordY = 0;
                        targetLocX.GetCoords(&coordX3, &coordY);
                        NiPoint3 navPos3;
                        if (FindNavPos(coordY, coordX3, targetLocX.GetPos(), &navPos3))
                        {
                            if (ctrlD->CanReachPos(&navPos3, targetLocX.GetContainingCell(), 1, 0))
                            {
                                PathRequest_combatprocedureengagetarget req5;
                                actorZ->PathToLocation(
                                    reinterpret_cast<PathingRequest*>(&req5), *reinterpret_cast<const NiPoint3*>(&navPos3),
                                    reinterpret_cast<void*>(coordX3), reinterpret_cast<void*>(coordY), DAT_0101e704, 0);
                                if (!actorZ->SetPathingRequestAvoidNodes(&req5))
                                {
                                    Fail("Cannot setup path to target location");
                                    return;
                                }
                                m_dest.SetPos(&navPos3);
                                m_dest.InitializeForCell(targetLocX.GetContainingCell());
                                UpdatePlayerStatus(3);
                                m_iFadeIndex = 8;
                                return;
                            }
                        }
                    }
                }
            }
        }
        if (m_timer20.Expired())
        {
            bool canDodge = true;
            if (!reinterpret_cast<ProcessObj*>(actorZ->FUN_008d8520())->CheckFlag(5) ||
                !reinterpret_cast<ProcessObj*>(actorZ->FUN_008d8520())->CheckFlag(6))
            {
                canDodge = false;
            }
            if (canDodge && !RandChance(DAT_0101622c))
            {
                float dist = 0.0f;
                m_bDodgeWait = ctrlD->IsCovered();
                if (m_bDodgeWait)
                {
                    dist = RandRange(DAT_0101e704, DAT_01050b98);
                }
                else
                {
                    dist = RandRange(DAT_0101e6ec, DAT_010536b8);
                }
                m_timer28.Reset();
                SearchRequest search2;
                if (ctrlD->FindDodge(&search2, 3, 0, dist, DAT_0104e0e8))
                {
                    PathRequest_combatprocedureengagetarget req62;
                    actorZ->PathToLocation(
                        reinterpret_cast<PathingRequest*>(&req62), *reinterpret_cast<const NiPoint3*>(search2.GetResult()),
                        actorZ->FUN_008d6f30(), reinterpret_cast<void*>(actorZ->TESObjectREFR_GetWorldSpace()), DAT_0101e57c, 0);
                    RawPoint dir2;
                    req62.GetDirection(&dir2)->FUN_005c3420();
                    req62.SetDirection(&dir2, dist + DAT_010231d8);
                    if (!actorZ->SetPathingRequestAvoidNodes(&req62))
                    {
                        Fail("Cannot setup path to dodge location");
                        return;
                    }
                    m_bCovered = true;
                    // Preserve the original trivial coordinate copy across NiPoint3's explicit assignment operator.
                    *reinterpret_cast<::NiPoint3*>(&m_dodgePos) = *reinterpret_cast<::NiPoint3*>(static_cast<const Actor*>(actorZ)->GetPos());
                    UpdatePlayerStatus(1);
                    m_iFadeIndex = 7;
                    return;
                }
            }
            if (IsAimingWeapon())
            {
                bool moving = actorZ->FUN_004997b0();
                if (moving)
                {
                    if (RandChance(DAT_01016248))
                    {
                        m_iFadeIndex = 2;
                    }
                    else
                    {
                        StopMove();
                        m_iFadeIndex = 1;
                    }
                }
                else
                {
                    UpdatePlayerStatus(2);
                    m_iFadeIndex = 2;
                }
            }
            else
            {
                m_iFadeIndex = 1;
            }
            m_timer20.Start(RandRange(DAT_010162c0, DAT_0101712c));
        }
    }
    break;
    case 6:
    case 7:
        m_bDodging = false;
        if (actorZ->DidPathingFail())
        {
            if (!static_cast<ActorPathingAccess*>(actorZ)->PathHasError())
            {
                ctrlD->OnPathFailed();
            }
            Fail(static_cast<ActorPathingAccess*>(actorZ)->PathHasError() ? "Pathing failed while dodging"
                                                                      : "Path Building failed to dodge");
            return;
        }
        if (m_iFadeIndex == 7)
        {
            if (!m_timer28.IsRunning())
            {
                if (m_bDodgeWait && !ctrlD->IsCovered())
                {
                    m_timer28.Start(DAT_01016248);
                }
            }
            else if (m_timer28.Expired())
            {
                actorZ->StopMoving();
                m_bDodgeWait = false;
                m_timer28.Reset();
            }
        }
        if (actorZ->FUN_008b3bb0())
        {
            if (IsAimingWeapon() && RandChance(DAT_01016248))
            {
                UpdatePlayerStatus(2);
                m_iFadeIndex = 2;
            }
            else
            {
                m_iFadeIndex = 1;
            }
            m_timer20.Start(RandRange(DAT_010162c0, DAT_0101712c));
        }
        break;
    case 3:
    case 4:
    case 5:
    case 8: {
        m_bDodging = false;
        bool done = false;
        bool fallback = false;
        if (actorZ->DidPathingFail())
        {
            if (!static_cast<ActorPathingAccess*>(actorZ)->PathHasError())
            {
                if (m_iFadeIndex == 4 || m_iFadeIndex == 3)
                {
                    m_stamp60 = GetCurrentTime();
                    done = true;
                }
                else
                {
                    ctrlD->SetDestination(&m_dest);
                    if (m_iFadeIndex == 8)
                    {
                        done = true;
                    }
                }
            }
            if (!done)
            {
                switch (m_iFadeIndex)
                {
                case 8:
                    Fail(static_cast<ActorPathingAccess*>(actorZ)->PathHasError() ? "Pathing failed while moving to target"
                                                : "Path Building failed to move to target");
                    break;
                case 5:
                    Fail(static_cast<ActorPathingAccess*>(actorZ)->PathHasError() ? "Pathing failed while approaching target"
                                                : "Path Building failed to approach target");
                    break;
                case 3:
                    Fail(static_cast<ActorPathingAccess*>(actorZ)->PathHasError() ? "Pathing failed while moving to optimal far location"
                                                : "Path Building failed to move to optimal far location");
                    break;
                case 4:
                    Fail(static_cast<ActorPathingAccess*>(actorZ)->PathHasError() ? "Pathing failed while moving to optimal close location"
                                                : "Path Building failed to move to optimal close location");
                    break;
                }
                return;
            }
        }
        if (!done)
        {
            switch (m_iFadeIndex)
            {
            case 8:
                if (ctrlD->IsCovered() && !veryFar5)
                {
                    done = true;
                }
                break;
            case 5:
                if (ctrlD->IsCovered())
                {
                    done = true;
                }
                break;
            case 3:
                if (distSqD < m_fMinRange * m_fMinRange)
                {
                    done = true;
                }
                break;
            }
        }
        if (m_iFadeIndex == 3 || m_iFadeIndex == 4)
        {
            if (!done && m_cFallback == 0 && !actorZ->IsWaitingOnPath())
            {
                m_cFallback = 1;
                NiPoint3 fallbackPos;
                if (static_cast<ActorPathingAccess*>(actorZ)->GetFallbackPos(&fallbackPos))
                {
                    if (!ctrlD->CanReachPos(&fallbackPos, actorLocY.GetContainingCell(), 0, 0))
                    {
                        m_cFallback = -1;
                    }
                    else if (!CheckLineOfFire(actorZ, target, &fallbackPos, static_cast<const Actor*>(target)->GetPos(), 0, -1))
                    {
                        m_cFallback = -2;
                    }
                    if (m_cFallback < 0)
                    {
                        done = true;
                        fallback = true;
                        m_stamp60 = GetCurrentTime();
                    }
                }
            }
            if (!done)
            {
                float moved = targetLocX.GetDistSq(&m_lastTarget);
                if ((changed || moved > DAT_0108e058) && TryAttack(veryFar5))
                {
                    return;
                }
            }
        }
        if (done)
        {
            if (fallback)
            {
                static_cast<ActorPathingAccess*>(actorZ)->StopPathAlt();
            }
            else
            {
                actorZ->StopMoving();
            }
        }
        if (actorZ->FUN_008b3bb0() || done)
        {
            if (IsAimingWeapon() && RandChance(DAT_01016248))
            {
                UpdatePlayerStatus(2);
                m_iFadeIndex = 2;
            }
            else
            {
                m_iFadeIndex = 1;
            }
            float delay = RandRange(DAT_010162c0, DAT_0101712c);
            if (changed)
            {
                delay = DAT_01013ea4;
            }
            m_timer20.Start(delay);
        }
    }
    break;
    }
}
}  // namespace fnv_009d3b80

struct FUN_009ca680
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    FUN_009ca680();
    ~FUN_009ca680();
};

// Retained: TimeoutTimer.h lacks the default constructor at 0x00906f60.
struct FUN_00906f60
{
    int a, b;
    FUN_00906f60();
};

struct FUN_0097ee20_shell
{
    int data[4];
    void BGSWorldLocation_BGSWorldLocation();
    FUN_0097ee20_shell()
    {
        BGSWorldLocation_BGSWorldLocation();
    }
};

struct FUN_00435de0_ctor
{
    int data[4];
    FUN_00435de0_ctor(float val);
};

struct NiPoint3_T
{
    float x, y, z;
};
extern NiPoint3_T DAT_011f426c;
extern float DAT_010914d0;

// Retained: CombatProcedureEngageTarget.h lacks the constructor and member layout.
struct FUN_009d3a00 : public FUN_009ca680
{
    int unk10;
    float f14, f18, f1c;
    FUN_00906f60 m20;
    FUN_00906f60 m28;
    bool b30, b31, b32, b33;
    NiPoint3_T pt34;
    FUN_0097ee20_shell m40;
    FUN_0097ee20_shell m50;
    FUN_00435de0_ctor m60;

    FUN_009d3a00();
};

// Constructor for FUN_009d3a00 that initializes base class, member fields, and sets m60 to negative DAT_010914d0.
// @fnv 0x009d3a00
FUN_009d3a00::FUN_009d3a00()
    : FUN_009ca680(), unk10(0), f14(0.0f), f18(0.0f), f1c(0.0f), m20(), m28(), b30(false), b31(false), b32(false),
      b33(true), pt34(DAT_011f426c), m40(), m50(), m60(-DAT_010914d0)
{}
