#include "../../../../include/Pathing.h"
// fallout/ai/combat/combatprocedureattackmelee.cpp: CombatProcedureAttackMelee, This, MeleeProc, CombatAttackHelper and more (57 functions)

#include "../../../../include/Actor.h"
// CombatNode_combatprocedureattackmelee: local type (was include/CombatNode.h, which had no evidence of one real class); its methods are 0x00505c00 TESCombatStyle::GetPowerAttackF, 0x00505c20 TESCombatStyle::GetPowerAttackB, 0x005524b0 TESCombatStyle::GetPowerAttackChance, 0x006a9560 TESCombatStyle::GetPowerAttackL
class CombatNode_combatprocedureattackmelee
{
public:
    unsigned int FUN_00726070();
    signed char GetByteAtOffset8C();
    bool HasCombatFlag(int);
    signed char FUN_0073cb80();
    signed char TESCombatStyle_GetPowerAttackF();
    signed char GetByteAtOffset9A();
    signed char GetByteAtOffset9B();
    signed char FUN_009e8670();
};
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/AnimIdle.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BSAudio.h"
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
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/CombatProcedureAttackMelee.h"
#include "../../../../include/CombatTargetTimestamp.h"
#include "../../../../include/PathingLocation.h"
#include "../../../../include/MobileObject.h"
// LocalPoint3Ext: unit-local copy of the former shared stand-in NiPoint3_ext. Same layout as NiPoint3; with NiPoint3, 0x009cdf80 (the original calls the out-of-line NiPoint3() at 0x006815c0, which NiPoint3.h's __forceinline constructor inlines) does not match.
#include "../../../../include/NiPoint3.h"
class LocalPoint3Ext
{
  public:
    float x;
    float y;
    float z;

    typedef LocalPoint3Ext AimVector;

    __forceinline LocalPoint3Ext()
    {}
    LocalPoint3Ext(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    LocalPoint3Ext operator+(const LocalPoint3Ext& point) const
    {
        return LocalPoint3Ext(x + point.x, y + point.y, z + point.z);
    }
    LocalPoint3Ext operator-(const LocalPoint3Ext& point) const
    {
        return LocalPoint3Ext(x - point.x, y - point.y, z - point.z);
    }
    NiPoint3 operator-(const NiPoint3& point) const;
    float operator*(const LocalPoint3Ext& point) const
    {
        return x * point.x + y * point.y + z * point.z;
    }
    LocalPoint3Ext& operator*=(float scalar);
    LocalPoint3Ext& operator+=(const NiPoint3& point);
    friend LocalPoint3Ext operator*(float scalar, const LocalPoint3Ext& point)
    {
        return LocalPoint3Ext(scalar * point.x, scalar * point.y, scalar * point.z);
    }

    float Dot(const NiPoint3& point) const;
    float Dot(const LocalPoint3Ext& point) const;
    LocalPoint3Ext& Subtract(const LocalPoint3Ext& point);
    float GetLengthSquared();
    void ComputeMagnitude();
    float GetSquaredXYLength() const;
    float Length() const;

    AimVector SubtractIntoVector(const AimVector& point) const;
    LocalPoint3Ext SubtractIntoVector(const NiPoint3& point) const;
    NiPoint3* SubtractIntoVector(NiPoint3* output, const NiPoint3& point) const;
    AimVector FUN_00439e90(const AimVector& point) const;
    bool FUN_00439090(const AimVector& point) const;
    float FUN_00457990() const;
    void Unitize_004a0c10();
    void FUN_006815c0();
    float FUN_004a7290() const;
    float FUN_00457910();
    LocalPoint3Ext& ComputeValue_0063c8a0(const NiPoint3& point);
    NiPoint3 GetNegatedVector() const;
};
#include "../../../../include/NiPoint3.h"
#include "../../../../include/Setting.h"
#include "../../../../include/NiPoint3.h"

// Nonvirtual melee calls not yet declared by the shared Actor header.
struct ActorMeleeCalls : Actor
{
    void FUN_008b3a50();
    bool TryAttack(int);
    bool Actor_GetCurrentPathfindingGoal(void*);
    bool Actor_IsAttacking();
    float Actor_GetWidth();
    float Actor_GetLength();
};

// @fnv 0x008d7f80
bool TimeoutTimer::CheckTimer() const
{
    return Actor::GetActorScale() - m_fStartTime > m_fTimeout;
}

char __fastcall GetByteAtOffset70(char*);

// @fnv 0x0097f2d0
// src: XBOX_PDB 0x0097f2d0
char __fastcall CombatController_HasLineOfSight(char* this_)
{
    return GetByteAtOffset70(*(char**)(this_ + 0x9c));
}

struct FUN_009cef70_shell
{
    float __thiscall CombatController_GetPowerAttackRange(int index);
};

// @fnv 0x009cef70
// src: COMMUNITY 0x009cef70
float __thiscall FUN_009cef70_shell::CombatController_GetPowerAttackRange(int index)
{
    return ((float*)this)[index + 0x3f];
}

struct FUN_009cef90_shell
{
    float __thiscall CombatController_GetPowerAttackHitTime_009cef90(int index);
};

// @fnv 0x009cef90
// src: COMMUNITY 0x009cef90
float __thiscall FUN_009cef90_shell::CombatController_GetPowerAttackHitTime_009cef90(int index)
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x110 + index * 4);
}

struct FUN_009cf400_shell
{
    unsigned char __thiscall GetByteAtOffsetAD();
};

// @fnv 0x009cf400
unsigned char __thiscall FUN_009cf400_shell::GetByteAtOffsetAD()
{
    return ((unsigned char*)this)[0xad];
}

struct FUN_009cf6d0_shell
{
    void __thiscall CombatProcedureAttackMelee_SetCombatState(int arg);
};

// Stores the previous value at offset 0x14 into offset 0x18, then writes arg into offset 0x14.
// @fnv 0x009cf6d0
// src: XBOX_PDB 0x009cf6d0
void __thiscall FUN_009cf6d0_shell::CombatProcedureAttackMelee_SetCombatState(int arg)
{
    *(int*)((char*)this + 0x18) = *(int*)((char*)this + 0x14);
    *(int*)((char*)this + 0x14) = arg;
}

struct FUN_009cfc40_shell
{
    void __thiscall CombatMovementRestrictions_SetReset(int);
};

// @fnv 0x009cfc40
// src: XBOX_PDB 0x009cfc40
void __thiscall FUN_009cfc40_shell::CombatMovementRestrictions_SetReset(int)
{
    ((unsigned char*)this)[0] = 1;
}

extern Setting originalRuntimeFloatSetting592;
extern double g_d100;
struct Obj
{
    char InterfaceManager_IsDebugTextVisible();
    double GetE0();
    float GetFieldDC();
    float GetFieldE4Float();
    float GetFieldE8Float();
};
// @fnv 0x00644580
// src: XBOX_PDB 0x00644580
float CombatFormulas_ChooseBlock(Obj* p, int percent, int unused, bool abApplySetting, bool abUseAltValue)
{
    float fPercentScale;
    float fResult;
    fPercentScale = percent / g_d100;
    fResult = p->InterfaceManager_IsDebugTextVisible() + p->GetE0() + p->GetFieldDC() * fPercentScale;
    fResult = fResult * (abUseAltValue ? p->GetFieldE4Float() : p->GetFieldE8Float());
    return abApplySetting ? fResult
                          : fResult * *originalRuntimeFloatSetting592.Float() * (abUseAltValue ? 1.0f : 0.25f);
}

// @fnv 0x009cc220
CombatProcedureAttackMelee::~CombatProcedureAttackMelee()
{}

struct FUN_009cc4d0_shell : CombatProcedure
{
    Actor* CombatProcedure_GetAttacker();
    void RunCombatProcedure();
};
// Gets the attacker Actor, runs the base procedure, then calls two functions on the attacker with false.
// @fnv 0x009cc4d0
void FUN_009cc4d0_shell::RunCombatProcedure()
{
    Actor* pattacker = CombatProcedure_GetAttacker();
    RunProcedure();
    pattacker->StopMoving_008b3ab0();
    pattacker->Actor_SetBlock(false);
}

struct FUN_009cce70_shell : AnimIdle
{
    Actor* CombatProcedure_GetAttacker();
    void CombatProcedureAttackMelee_StartAttack(int attack, int arg2);
};
// @fnv 0x009cce70
// src: XBOX_PDB 0x009cce70
void FUN_009cce70_shell::CombatProcedureAttackMelee_StartAttack(int attack, int arg2)
{
    if (attack == 0xff || !GetSection())
        return;
    Actor* pattacker = CombatProcedure_GetAttacker();
    bool queued = ((ActorMeleeCalls*)pattacker)->TryAttack(attack);
    if (queued)
    {
        ((FUN_009cf6d0_shell*)this)->CombatProcedureAttackMelee_SetCombatState(0);
        ((int*)this)[7] = attack;
    }
}

namespace fnv_009cd3d0 {
struct FUN_009cd3d0_shell : AnimIdle
{
    void CombatProcedureAttackMelee_HandleHold();
};
// If GetSection() returns 2 and the timer at offset 0x20 has elapsed, calls FUN_009cf6d0 with 3.
// @fnv 0x009cd3d0
// src: COMMUNITY 0x009cd3d0
void FUN_009cd3d0_shell::CombatProcedureAttackMelee_HandleHold()
{
    if (GetSection() != 2)
        return;
    if (((TimeoutTimer*)((char*)this + 0x20))->CheckTimer())
        ((FUN_009cf6d0_shell*)this)->CombatProcedureAttackMelee_SetCombatState(3);
}
}  // namespace fnv_009cd3d0

struct FUN_009cd410_shell
{
    void SetMode(int);
    void CombatProcedureAttackMelee_StartEngage();
};
// @fnv 0x009cd410
// src: XBOX_PDB 0x009cd410
void FUN_009cd410_shell::CombatProcedureAttackMelee_StartEngage()
{
    SetMode(0);
}

struct FUN_009cdde0_shell
{
    bool HasNoFlag(unsigned short mask);
};
// Returns true when the 16-bit flags at offset 8 do not contain any bit of mask.
// @fnv 0x009cdde0
bool FUN_009cdde0_shell::HasNoFlag(unsigned short mask)
{
    return !(*(unsigned short*)((char*)this + 8) & mask) != 0;
}

extern double DAT_01011588;
struct FUN_009cde10_shell
{
    int GetAudioBackendData();
    int GetSection();
    ActorMeleeCalls* GetTarget_00996e00();
    void CombatProcedureAttackMelee_StartEngage();
    void EvaluateReaction();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    unsigned char CombatProcedureAttackMelee_OutsideAttackRange(float, float, int);
    void UpdateState();
    float GetModifierValue();
    void CombatProcedureAttackMelee_HandleIdle();
};
// @fnv 0x009cde10
// src: XBOX_PDB 0x009cde10
void FUN_009cde10_shell::CombatProcedureAttackMelee_HandleIdle()
{
    ActorMeleeCalls* ptarget;
    if (GetAudioBackendData() != 1)
        return;
    ptarget = GetTarget_00996e00();
    if (((TimeoutTimer*)((char*)this + 0x28))->CheckTimer())
    {
        CombatProcedureAttackMelee_StartEngage();
        return;
    }
    if (((CombatTargetTimestamp*)((char*)this + 0x28))->GetElapsedTime() > DAT_01011588)
    {
        float freach;
        float fdistance;
        fdistance = GetModifierValue();
        freach = CombatProcedureAttackMelee_GetCurrentAttackReach();
        if (CombatProcedureAttackMelee_OutsideAttackRange(fdistance, freach, 0))
        {
            CombatProcedureAttackMelee_StartEngage();
            return;
        }
    }
    if ((ptarget && ptarget->Actor_IsAttacking()) || *((unsigned char*)this + 0x50))
    {
        if (GetSection() == 2)
        {
            ((FUN_009cf6d0_shell*)this)->CombatProcedureAttackMelee_SetCombatState(3);
            UpdateState();
        }
        EvaluateReaction();
    }
}

struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float);
};
struct FUN_009ce190_shell
{
    void SetMoveMode_00996e20(int);
    void UpdateMeleeCombat();
    void SetMode(int);
    void CombatProcedureAttackMelee_StartAdvance();
};
// Calls SetMode(4), FUN_00996e20(3), FUN_008d7f40(3.0f) on the object at offset 0x28, then UpdateMeleeCombat.
// @fnv 0x009ce190
// src: XBOX_PDB 0x009ce190
void FUN_009ce190_shell::CombatProcedureAttackMelee_StartAdvance()
{
    SetMode(4);
    SetMoveMode_00996e20(3);
    ((FUN_008d7f40_shell*)((char*)this + 0x28))->FUN_008d7f40(3.0f);
    UpdateMeleeCombat();
}

extern double _gModifierZero;
int __fastcall GetCurrentWeapon(int);
float __cdecl GetActorReach(Actor*, int);
struct FUN_009ce560_shell
{
    Actor* CombatProcedure_GetAttacker();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
};
// Returns the cached modifier value, recomputing it from the attacker and the value at offset 4 when it is below _gModifierZero.
// @fnv 0x009ce560
// src: XBOX_PDB 0x009ce560
float FUN_009ce560_shell::CombatProcedureAttackMelee_GetCurrentAttackReach()
{
    Actor* pattacker = CombatProcedure_GetAttacker();
    if (((float*)this)[0x16] < _gModifierZero)
        ((float*)this)[0x16] = GetActorReach(pattacker, GetCurrentWeapon(((int*)this)[1]));
    return ((float*)this)[0x16];
}

struct FUN_009cefb0_shell
{
    char CombatController_ShouldInitPowerAttackDistances();
};
// @fnv 0x009cefb0
// src: COMMUNITY 0x009cefb0
char FUN_009cefb0_shell::CombatController_ShouldInitPowerAttackDistances()
{
    return *((char*)this + 0xf9);
}

struct Date
{
    ~Date();
};
struct FUN_009cf660_shell
{
    unsigned char IsTargetOutOfRange();
    void CombatProcedureAttackMelee_CheckResetMovementRestrictions();
    void SetMode(int mode);
};
// @fnv 0x009cf660
void FUN_009cf660_shell::SetMode(int mode)
{
    if (((int*)this)[4] != mode)
    {
        if (mode == 0 && ((int*)this)[4] == 4 && IsTargetOutOfRange())
            return;
        if (mode == 4 || ((int*)this)[4] == 4)
            ((Date*)((int*)this)[1])->Date::~Date();
        CombatProcedureAttackMelee_CheckResetMovementRestrictions();
    }
    ((int*)this)[4] = mode;
}

namespace fnv_009cfbd0 {
struct FUN_009cdde0_shell
{
    char HasNoFlag(unsigned short mask);
};
struct FUN_009cfbd0_shell
{
    char CombatProcedureAttackMelee_CheckDodge(unsigned short mask);
};
// Forwards the mask to the HasNoFlag method of the object at offset 0x64 and returns its result.
// @fnv 0x009cfbd0
// src: XBOX_PDB 0x009cfbd0
char FUN_009cfbd0_shell::CombatProcedureAttackMelee_CheckDodge(unsigned short mask)
{
    char result = 1;
    result = ((FUN_009cdde0_shell*)((char*)this + 0x64))->HasNoFlag(mask);
    return result;
}
}  // namespace fnv_009cfbd0

struct FUN_009cfc00_shell
{
    Actor* CombatProcedure_GetAttacker();
    void CombatProcedureAttackMelee_CheckResetMovementRestrictions();
};
// Gets the attacker via FUN_00996de0 and, if FUN_008b3bd0 returns false, calls FUN_009cfc40(1) on the object at this+0x64.
// @fnv 0x009cfc00
// src: XBOX_PDB 0x009cfc00
void FUN_009cfc00_shell::CombatProcedureAttackMelee_CheckResetMovementRestrictions()
{
    Actor* pattacker = CombatProcedure_GetAttacker();
    if (!pattacker->IsPathing())
        ((FUN_009cfc40_shell*)((char*)this + 0x64))->CombatMovementRestrictions_SetReset(1);
}

namespace fnv_009cfc60 {
struct FUN_009cfc60_shell
{
    Actor* CombatProcedure_GetAttacker();
    void StopIfSpeakerOutOfRange();
    void CombatProcedureAttackMelee_StopMoving();
};
// Gets an Actor via FUN_00996de0, calls FUN_008b3a50 and FUN_008b3ab0 on it, then calls StopIfSpeakerOutOfRange.
// @fnv 0x009cfc60
// src: XBOX_PDB 0x009cfc60
void FUN_009cfc60_shell::CombatProcedureAttackMelee_StopMoving()
{
    Actor* pattacker = CombatProcedure_GetAttacker();
    ((ActorMeleeCalls*)pattacker)->FUN_008b3a50();
    pattacker->StopMoving_008b3ab0();
    StopIfSpeakerOutOfRange();
}
}  // namespace fnv_009cfc60

extern double _gModifierZero;
float __cdecl CombatUtilities_GetDistanceBetweenFacingActors(Actor*, Actor*, int);
struct FUN_009cfd20_shell
{
    Actor* CombatProcedure_GetAttacker();
    Actor* GetTarget_00996e00();
    float GetModifierValue();
};
// @fnv 0x009cfd20
float FUN_009cfd20_shell::GetModifierValue()
{
    if (((float*)this)[0x17] < _gModifierZero)
        ((float*)this)[0x17] = CombatUtilities_GetDistanceBetweenFacingActors(CombatProcedure_GetAttacker(), GetTarget_00996e00(), 0);
    return ((float*)this)[0x17];
}

extern NiPoint3 _NiPoint3_ZERO;
struct FUN_00906f60
{
    FUN_00906f60();
    char d[16];
};
struct FUN_009cff10_shell
{
    bool a;
    bool b;
    int c;
    short d;
    bool e;
    bool f;
    bool g;
    bool h;
    NiPoint3 v;
    FUN_00906f60 m;
    FUN_009cff10_shell* Reset();
};
// Resets all flags, clears c and d, sets v to _NiPoint3_ZERO, constructs m, and returns this.
// @fnv 0x009cff10
FUN_009cff10_shell* FUN_009cff10_shell::Reset()
{
    a = false;
    b = false;
    c = 0;
    d = 0;
    e = false;
    f = false;
    g = false;
    h = false;
    // Preserve the original trivial vector copy through the shared POD point type.
    *(NiPoint3*)&v = *(const NiPoint3*)&_NiPoint3_ZERO;
    m.FUN_00906f60::FUN_00906f60();
    return this;
}

struct FUN_009d0530_shell
{
    void UpdateFlags(unsigned short mask, bool clear);
};
// Sets or clears the bits of mask in the 16-bit flags word at offset 8 of this object, depending on clear.
// @fnv 0x009d0530
void FUN_009d0530_shell::UpdateFlags(unsigned short mask, bool clear)
{
    clear ? ((unsigned short*)this)[4] &= ~mask : ((unsigned short*)this)[4] |= mask;
}

namespace fnv_009d0590 {

struct FUN_009d0590_shell
{
    bool CombatMovementRestrictions_IsLocationSafe(TESObjectREFR* ref, const NiPoint3* pt);
};
// @fnv 0x009d0590
// src: COMMUNITY 0x009d0590
bool FUN_009d0590_shell::CombatMovementRestrictions_IsLocationSafe(TESObjectREFR* ref, const NiPoint3* pt)
{
    PathingLocation loc(ref);
    return Pathing::FindPathingLocation(loc, *pt, 0, static_cast<void*>(0));
}
}  // namespace fnv_009d0590

namespace fnv_009d0610 {
struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};
extern Setting g_011cee60;
struct FUN_008d7f40_shell
{
    void __thiscall FUN_008d7f40(float);
};
struct FUN_009d0610_shell
{
    bool active;
    unsigned int elapsed;
    unsigned int __thiscall UpdateDirection(unsigned int, unsigned int);
    void CombatMovementRestrictions_Update(TESAmmoInitCalls* src);
};
// @fnv 0x009d0610
// src: XBOX_PDB 0x009d0610
void FUN_009d0610_shell::CombatMovementRestrictions_Update(TESAmmoInitCalls* pAmmoInitCalls)
{
    if (((TimeoutTimer*)((char*)this + 0x1c))->CheckTimer() || elapsed > 0)
        elapsed = UpdateDirection(pAmmoInitCalls->GetFieldBC(), elapsed) + elapsed;
    if (elapsed >= 4)
    {
        active = false;
        elapsed = 0;
        ((FUN_008d7f40_shell*)((char*)this + 0x1c))->FUN_008d7f40(*g_011cee60.Float());
    }
}
}  // namespace fnv_009d0610

namespace fnv_009d0690 {
struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer*);
};
}  // namespace fnv_009d0690
// @fnv 0x009d0690
void CombatProcedureAttackMelee::SaveGame(BGSSaveFormBuffer* buf)
{
    CombatProcedure::SaveGame(buf);
    buf->SaveData((char*)this + 0x10, 4, 0);
    buf->SaveData((char*)this + 0x14, 4, 0);
    buf->SaveData((char*)this + 0x18, 4, 0);
    buf->SaveData((char*)this + 0x1c, 4, 0);
    ((fnv_009d0690::FUN_009a5eb0_shell*)((char*)this + 0x20))->FUN_009a5eb0(buf);
    ((fnv_009d0690::FUN_009a5eb0_shell*)((char*)this + 0x28))->FUN_009a5eb0(buf);
    ((fnv_009d0690::FUN_009a5eb0_shell*)((char*)this + 0x30))->FUN_009a5eb0(buf);
    ((fnv_009d0690::FUN_009a5eb0_shell*)((char*)this + 0x38))->FUN_009a5eb0(buf);
    ((fnv_009d0690::FUN_009a5eb0_shell*)((char*)this + 0x40))->FUN_009a5eb0(buf);
    ((fnv_009d0690::FUN_009a5eb0_shell*)((char*)this + 0x48))->FUN_009a5eb0(buf);
    ((CombatTargetTimestamp*)((char*)this + 0x60))->SaveTimeStamp(buf);
    buf->SaveData((char*)this + 0x50, 1, 0);
    buf->SaveData((char*)this + 0x54, 4, 0);
}

namespace fnv_009d0790 {
struct FUN_009a5e_timer
{
    void LoadGame(BGSLoadFormBuffer*);
};
}  // namespace fnv_009d0790
// Loads the base form data, four 4-byte fields, six timers, a version-gated object, then a 1-byte and a 4-byte field from the buffer.
// @fnv 0x009d0790
void CombatProcedureAttackMelee::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    CombatProcedure::LoadGame(apBuffer);
    apBuffer->ReadTypedData((char*)this + 0x10, 4);
    apBuffer->ReadTypedData((char*)this + 0x14, 4);
    apBuffer->ReadTypedData((char*)this + 0x18, 4);
    apBuffer->ReadTypedData((char*)this + 0x1c, 4);
    ((fnv_009d0790::FUN_009a5e_timer*)((char*)this + 0x20))->LoadGame(apBuffer);
    ((fnv_009d0790::FUN_009a5e_timer*)((char*)this + 0x28))->LoadGame(apBuffer);
    ((fnv_009d0790::FUN_009a5e_timer*)((char*)this + 0x30))->LoadGame(apBuffer);
    ((fnv_009d0790::FUN_009a5e_timer*)((char*)this + 0x38))->LoadGame(apBuffer);
    ((fnv_009d0790::FUN_009a5e_timer*)((char*)this + 0x40))->LoadGame(apBuffer);
    ((fnv_009d0790::FUN_009a5e_timer*)((char*)this + 0x48))->LoadGame(apBuffer);
    if (apBuffer->GetVersion() >= 0x12)
        ((CombatTargetTimestamp*)((char*)this + 0x60))->LoadGame(apBuffer);
    apBuffer->ReadTypedData((char*)this + 0x50, 1);
    apBuffer->ReadTypedData((char*)this + 0x54, 4);
}

struct FUN_00996de0_Class
{
    unsigned int CombatProcedure_GetAttacker();
};
struct FUN_00980070_shell
{
    unsigned int GetCurrentCombatStyle();
};

struct FUN_009cefd0_shell
{
    int m_00;
    FUN_00980070_shell* m_04;
    char IsWithinThreshold(float a, float b, float c);
};

// Calls FUN_00996de0 and FUN_00980070, checks whether GetByteAtOffset8C returns at least 100, and returns 1 when a is not greater than b.
// @fnv 0x009cefd0
char FUN_009cefd0_shell::IsWithinThreshold(float afValue, float afLimit, float afUnused)
{
    char bResult = 0;
    unsigned int pTarget3 = ((FUN_00996de0_Class*)this)->CombatProcedure_GetAttacker();
    bool bFlag = ((CombatNode_combatprocedureattackmelee*)this->m_04->GetCurrentCombatStyle())->GetByteAtOffset8C() >= 100;
    float fElapsed3 = 0.0f;
    if (afValue <= afLimit + fElapsed3)
    {
        bResult = 1;
    }
    return bResult;
}

struct AnimDataV
{
    char Animation_FindSwitchKey();
    char Animation_FindNextNoteKey(int, int);
    int GetSlotValue();
};
// Retained: the shared GetAnimData() cannot reproduce this slot 0x1E4 call with an int argument.
struct ActorV
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual AnimDataV* GetAnimData(int);
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual bool V218();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual bool V230();
};
struct TESObjectWEAP;
struct FUN_0051f5f0_shell
{
    unsigned int GetByteAt11D();
};
struct FUN_00996e00_shell
{
    void* GetTarget_00996e00();
};
struct S009cefd0
{
    bool IsWithinThreshold(float, float, int);
};
struct S009ce870
{
    int CombatProcedureAttackMelee_SelectPowerAttack(float, float, bool, bool, int);
};
unsigned int __cdecl DialogueRandom();
bool CheckChanceSuccess(unsigned int, float, bool, bool, int);
extern Setting originalRuntimeFloatSetting597;
extern int DAT_011a8244;

// Chooses a melee attack id from distance, reach, power-attack and animation state, setting the power-attack and switch-attack flags.
// @fnv 0x009ccb20
int CombatProcedureAttackMelee::ChooseMeleeAttack(bool abMidAttack, float afDistance, float afReach, bool abTargetAttacking,
                                             bool abTargetPostAttack, bool abTargetRecoiling, bool* abDoPowerAttack,
                                             bool* abSwitchAttack)
{
    TESObjectWEAP* pweapon;
    bool bwithinNormalReach;
    ActorV* ptarget;
    int iAttack;
    ActorV* pattacker;

    pattacker = (ActorV*)((FUN_00996de0_Class*)this)->CombatProcedure_GetAttacker();
    ptarget = (ActorV*)((FUN_00996e00_shell*)this)->GetTarget_00996e00();
    *abSwitchAttack = false;
    iAttack = 0xff;
    pweapon = (TESObjectWEAP*)GetCurrentWeapon((int)m_pCombatController);
    if (!ptarget)
        return iAttack;
    if (pattacker->V218() && ((MobileObject*)pattacker)->IsSwimming_005a2030())
        *abDoPowerAttack = false;
    else
        *abDoPowerAttack = CheckChanceSuccess(((FUN_00980070_shell*)m_pCombatController)->GetCurrentCombatStyle(), ((Actor*)pattacker)->GetFatiguePercentage(),
                                              abTargetRecoiling, ptarget->V230(), 0);
    if ((int)((BSAudio*)this)->GetAudioBackendData() == 4)
    {
        afReach += *originalRuntimeFloatSetting597.Float();
        if (DialogueRandom() % 100 < 2)
            afReach += g_d100;
    }
    bwithinNormalReach = ((S009cefd0*)this)->IsWithinThreshold(afDistance, afReach, 0);
    if (!abMidAttack)
    {
        if (*abDoPowerAttack)
            iAttack = ((S009ce870*)this)->CombatProcedureAttackMelee_SelectPowerAttack(afDistance, afReach, abTargetAttacking, abTargetPostAttack, 0);
        if (iAttack == 0xff && bwithinNormalReach)
        {
            iAttack = pweapon ? ((FUN_0051f5f0_shell*)pweapon)->GetByteAt11D() : 0xff;
            if (iAttack == 0xff)
            {
                if (pattacker->GetAnimData(1)->Animation_FindNextNoteKey(DAT_011a8244, 0) == 'l')
                    iAttack = 0x1a;
                else
                    iAttack = 0x20;
            }
        }
    }
    else if (pattacker->GetAnimData(4)->GetSlotValue() == 3)
    {
        if (*abDoPowerAttack)
            iAttack = ((S009ce870*)this)->CombatProcedureAttackMelee_SelectPowerAttack(afDistance, afReach, abTargetAttacking, abTargetPostAttack, 0);
        if (iAttack == 0xff && bwithinNormalReach)
        {
            switch (((ActorV*)((FUN_00996de0_Class*)this)->CombatProcedure_GetAttacker())->GetAnimData(0)->Animation_FindSwitchKey())
            {
            case 0x33:
                iAttack = 0x26;
                break;
            case 0x34:
                iAttack = 0x2c;
                break;
            case 0x35:
                iAttack = 0x32;
                break;
            case 0x36:
                iAttack = 0x38;
                break;
            case 0x37:
                iAttack = 0x3e;
                break;
            case 0x38:
                iAttack = 0x44;
                break;
            case 0x6c:
                iAttack = 0x1a;
                break;
            default:
                if (pweapon && ((FUN_0051f5f0_shell*)pweapon)->GetByteAt11D() != 0xff)
                    iAttack = ((FUN_0051f5f0_shell*)pweapon)->GetByteAt11D();
                else
                    iAttack = 0x20;
                break;
            }
            *abSwitchAttack = true;
        }
    }
    return iAttack;
}

struct TargetInterface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(int arg);
};


// Forwards the argument to the movement controller virtual method at slot 0x0C.
// @fnv 0x008b3a20
void Actor::DispatchToTarget(int aiValue)
{
    ((TargetInterface*)m_pActorMover)->v0c(aiValue);
}

struct CombatProcBase
{
    CombatProcBase();
    virtual ~CombatProcBase();
    int unk04;
    int unk08;
    int unk0C;
};

struct CombatPoint2
{
    CombatPoint2();
    float x;
    float y;
};

struct CombatValue
{
    CombatValue();
    CombatValue(float f);
    int value;
};

struct CombatMeleeData
{
    CombatMeleeData();
    int unk00;
};

extern const float fCombatMaxValue;

struct FUN_009cc0c0 : CombatProcBase
{
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CombatPoint2 pt20;
    CombatPoint2 pt28;
    CombatPoint2 pt30;
    CombatPoint2 pt38;
    CombatPoint2 pt40;
    CombatPoint2 pt48;
    bool unk50;
    int unk54;
    float unk58;
    float unk5C;
    CombatValue val60;
    CombatMeleeData data64;
    FUN_009cc0c0();
    virtual ~FUN_009cc0c0();
};

// Initializes the combat procedure object's fields to defaults, sets the value to negative fCombatMaxValue, and stores it in val60.
// @fnv 0x009cc0c0
FUN_009cc0c0::FUN_009cc0c0()
{
    unk04 = 0;
    unk1C = 0xff;
    unk10 = 0;
    unk14 = 3;
    unk18 = 3;
    unk54 = 0x100;
    unk50 = false;
    unk58 = -1.0f;
    unk5C = -1.0f;
    CombatValue initial(-fCombatMaxValue);
    val60 = initial;
}

struct AnimData;
struct SubA4
{
    int FUN_0066ef20(int);
};
struct Proc
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
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual bool V254();
};

struct AnimData
{
    unsigned short Animation_GetGroup(int);
    int GetSlotValue(int);
    bool Animation_GroupLoaded(unsigned short);
};
struct Mid2
{
    float FUN_00435e00();
};
struct Mid1
{
    virtual void vdummy();
    Mid2* GetHandle();
};
struct Mid3
{
    float GetUnka4();
    float FUN_004565f0();
};
struct Obj04
{
    bool FUN_00981970();
    bool GetModifierKey();
    void* GetCurrentCombatStyle();
    int CombatController_GetAttackSkill();
    Mid1 CombatController_GetCombatState();
};
extern Setting DAT_011cea38;
extern ActorMeleeCalls* DAT_011dea3c;
struct GlobalObj
{
    void CombatDialogueManager_StartDialogue(void*, int, int, int);
};
extern GlobalObj* DAT_011f1708;
int __fastcall GetAnimAction_008a7570(void*);
bool __fastcall CombatController_HasLineOfSight(void*);
bool __fastcall IsWeaponDrawn(void*);
bool __fastcall TESObjectWEAP_IsRangedWeapon(void*);
Proc* __fastcall FUN_008d8520(void*);
int __fastcall GetCurrentWeapon(int);
bool __cdecl FUN_005f2540(int);
float __cdecl CalculateWeightedValue(int, int, int, bool, bool, bool, bool, bool);
float __cdecl CombatFormulas_ChooseBlock(void*, int, int, bool, bool);
float __cdecl BSMAX_00404010(float, float);
float __cdecl FUN_006465f0(float, float);
unsigned int __cdecl FUN_00487f50();
struct Sub20
{
    void FUN_008d7f40(float);
};
struct This
{
    int m_00;
    Obj04* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    Sub20 m_20;
    Actor* CombatProcedure_GetAttacker();
    ActorMeleeCalls* GetTarget_00996e00();
    int FUN_00825c00();
    float GetModifierValue();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    bool IsWithinThreshold(float, float, int);
    void CombatProcedureAttackMelee_SetCombatState(int);
    int TESMain_GetThread();
    void CombatProcedureAttackMelee_StartAttack(int, int);
    void CombatProcedureAttackMelee_MeleeDecision();
};
// @fnv 0x009cc510
// src: XBOX_PDB 0x009cc510
void This::CombatProcedureAttackMelee_MeleeDecision()
{
    float n44;
    float n45;
    float m2;
    void* m33;
    int m36;
    float m48;
    bool v29;
    bool v30;
    float v51;
    bool t5;
    bool t19;
    int t43;
    ActorMeleeCalls* t45;
    bool t57;
    bool s5;
    float s12;
    bool s20;
    int s23;
    bool s33;
    bool s44;
    AnimData* s56;
    bool r14;
    Actor* r23;
    bool r39;
    r23 = CombatProcedure_GetAttacker();
    t45 = GetTarget_00996e00();
    if (FUN_00825c00() != 3 || t45 == 0)
        return;
    if (m_04->FUN_00981970())
        return;
    m_1c = 0xff;
    s12 = GetModifierValue();
    v51 = CombatProcedureAttackMelee_GetCurrentAttackReach();
    s56 = r23->GetAnimData();
    t43 = GetAnimAction_008a7570(r23);
    s23 = GetAnimAction_008a7570(t45);
    t57 = FUN_005f2540(s56->Animation_GetGroup(4));
    t5 = s56->GetSlotValue(4) == 3;
    r39 = t43 == 4;
    t19 = t43 == 8 || t43 == 10;
    s33 = t45->Actor_IsAttacking();
    s20 = s23 == 4;
    s5 = s23 == 8 || s23 == 10;
    s44 = t45->Actor_IsInCombat();
    r14 = t45->GetBlocked();
    if (IsWithinThreshold(s12, v51, 0))
    {
        n44 = 0.0f;
        n44 = CalculateWeightedValue((int)m_04->GetCurrentCombatStyle(), m_04->CombatController_GetAttackSkill(), r23->GetActorValueAsInteger(11), s33,
                                     GetCurrentWeapon((int)m_04) == 0, s5, t45->GetHasKnockedState(), r14);
        if (m_04->CombatController_GetCombatState().GetHandle()->FUN_00435e00() > 5.0 && n44 != 0.0)
            n44 += 100.0;
        if (!s44 && t45 != DAT_011dea3c)
            n44 += 100.0;
        m2 = CombatFormulas_ChooseBlock(m_04->GetCurrentCombatStyle(), 50, 50, false, s33);
        v29 = t45->GetIsParalyzed() || t45->GetHasKnockedState() || t45->Actor_IsUnConscious() || t45->Actor_IsSleeping() || t45->Actor_IsRestrained();
        m33 = t45->Actor_GetCurrentWeapon();
        if (v29 || !IsWeaponDrawn(t45) || (m33 != 0 && TESObjectWEAP_IsRangedWeapon(m33)))
            m2 = 0.0f;
        v30 = (t57 && n44 > 0.0f) ? true : FUN_008d8520(CombatProcedure_GetAttacker())->V254();
        if (!v30 || !CombatController_HasLineOfSight(m_04))
        {
            n44 = 0.0f;
            if (!CombatController_HasLineOfSight(m_04))
                m2 = 0.0f;
        }
        if ((t57 && !t5) || TESMain_GetThread() == 4 || t19)
            m2 = 0.0f;
        if (!s56->Animation_GroupLoaded(0xaa))
            m2 = 0.0f;
        n45 = BSMAX_00404010((float)(100.0 - (n44 + m2)), *DAT_011cea38.Setting_Float_00403e20());
        if (t57 && !t5)
            n45 = 0.0f;
        if (m_18 == 2)
            n45 = 0.0f;
        m36 = (int)(n44 + m2 + n45);
        m48 = (float)(FUN_00487f50() % (unsigned int)(m36 > 0 ? m36 : 100));
        if (m48 < n44)
        {
            if (m_04->GetModifierKey())
            {
                r23->Actor_SetBlock(false);
                if (FUN_00825c00() == 1)
                    CombatProcedureAttackMelee_SetCombatState(3);
            }
            bool found = false;
            bool bp2 = false;
            int res = ((CombatProcedureAttackMelee*)this)->ChooseMeleeAttack(t57, s12, v51, s33, s20, s5, &found, &bp2);
            if (res != 0xff)
            {
                if (GetTarget_00996e00()->GetNiNode() != 0)
                {
                    if (found)
                    {
                        DAT_011f1708->CombatDialogueManager_StartDialogue(m_04, 2, 1, 0);
                    }
                    else
                    {
                        DAT_011f1708->CombatDialogueManager_StartDialogue(m_04, 2, 0, 0);
                    }
                    CombatProcedureAttackMelee_StartAttack(res, bp2);
                }
            }
        }
        else if (m2 > 0.0f && (n44 + m2) > m48)
        {
            r23->Actor_SetBlock(true);
            CombatProcedureAttackMelee_SetCombatState(1);
        }
        else
        {
            if (m_18 != 2)
            {
                CombatProcedureAttackMelee_SetCombatState(2);
                float f60 = FUN_006465f0(((Mid3*)m_04->GetCurrentCombatStyle())->FUN_004565f0(),
                                         ((Mid3*)m_04->GetCurrentCombatStyle())->GetUnka4());
                m_20.FUN_008d7f40(f60);
            }
        }
    }
}

namespace fnv_009cced0 {
struct FUN_009cced0_cls
{
    int m_00;
    int m_04;
    int FUN_00825c00();
    Actor* CombatProcedure_GetAttacker();
    void* GetTarget_00996e00();
    void CombatProcedureAttackMelee_SetCombatState(int arg);
    void CombatProcedureAttackMelee_MeleeDecision();
    void CombatProcedureAttackMelee_HandleAttack();
};

unsigned short __fastcall Animation_GetGroup(AnimDataV* p);
unsigned char __cdecl FUN_005f2540(int v);
unsigned char __cdecl TESAnimGroup_IsAttackSpinAction(unsigned int v);

// @fnv 0x009cced0
// src: COMMUNITY 0x009cced0
void FUN_009cced0_cls::CombatProcedureAttackMelee_HandleAttack()
{
    if (FUN_00825c00())
    {
        return;
    }
    Actor* a = CombatProcedure_GetAttacker();
    void* b = GetTarget_00996e00();
    unsigned char r_2 = FUN_005f2540(Animation_GetGroup(((ActorV*)a)->GetAnimData(4)));
    if (r_2)
    {
        if (((ActorV*)a)->GetAnimData(4)->GetSlotValue() == 3)
        {
            CombatProcedureAttackMelee_SetCombatState(3);
            CombatProcedureAttackMelee_MeleeDecision();
        }
        int pResult = GetCurrentWeapon(m_04);
        if (pResult != 0)
        {
            if (TESAnimGroup_IsAttackSpinAction(reinterpret_cast<FUN_0051f5f0_shell*>(pResult)->GetByteAt11D()))
            {
                reinterpret_cast<ActorMeleeCalls*>(a)->TryAttack(
                    reinterpret_cast<FUN_0051f5f0_shell*>(pResult)->GetByteAt11D());
            }
        }
    }
    else
    {
        CombatProcedureAttackMelee_SetCombatState(3);
    }
}
}  // namespace fnv_009cced0

struct AnimSequence
{
    int GetState();
};
struct AnimDataM
{
    AnimSequence* GetControllerSequence(int section);
};
struct TimerObj
{
    float GetValue(int index);
};
struct ProcessM
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual TimerObj* GetTimer();
};
struct MeleeTarget
{
    int GetAnimActionM();
};
struct MeleeProc
{
    int GetModeM();
    Actor* GetActorM();
    MeleeTarget* GetTargetM();
    void SetStateM(int state);
    void FinishM();
    void ContinueM();
    void CombatProcedureAttackMelee_HandleBlock();
};
extern double _gModifierZero;

// In mode 1, checks the actor's readiness, timer value and attack state, and either sets state 3, finishes, or continues the melee procedure.
// @fnv 0x009ccfb0
// src: COMMUNITY 0x009ccfb0
void MeleeProc::CombatProcedureAttackMelee_HandleBlock()
{
    if (GetModeM() != 1)
        return;
    Actor* actor = GetActorM();
    MeleeTarget* target8 = GetTargetM();
    if (!actor->GetBlocked())
        SetStateM(3);
    TimerObj* timer5 = ((ProcessM*)actor->GetProcess())->GetTimer();
    if (timer5)
    {
        bool bAttacking4 = false;
        if (((AnimDataM*)GetActorM()->GetAnimData()) && ((AnimDataM*)GetActorM()->GetAnimData())->GetControllerSequence(2) &&
            ((AnimDataM*)GetActorM()->GetAnimData())->GetControllerSequence(2)->GetState() != 1)
            bAttacking4 = true;
        float fTime = timer5->GetValue(0);
        if (fTime <= _gModifierZero && !bAttacking4)
        {
            actor->Actor_SetBlock(false);
            SetStateM(3);
        }
        else
        {
            bool bTargetAttack2 = target8 ? target8->GetAnimActionM() == 8 : 0;
            if (bTargetAttack2 && !bAttacking4)
            {
                actor->Actor_SetBlock(false);
                SetStateM(3);
                FinishM();
            }
            else if (!bAttacking4)
            {
                ContinueM();
            }
        }
    }
}

// Animation state accessor at 0x004301b0 used by the slot 0x1E4 int-argument call.
struct MeleeAnimationState
{
    unsigned short Animation_GetGroup();
};

struct Controller9cd430
{
    bool CombatController_HasLineOfSight();
    bool GetModifierKey();
};

extern Setting originalRuntimeFloatSetting593;

bool __cdecl IsTargetInCone(Actor*, void*, int);
bool __cdecl FUN_005f2670(unsigned int);

struct CombatProc9cd430
{
    int m_00;
    Controller9cd430* m_04;

    int Check44edb0();
    Actor* GetActor();
    void* GetTarget();
    float GetF1();
    float GetF2();
    bool Test9cefd0(float a, float b, int c);
    bool Test9cf030(float a, float b, int c);
    void Do9ce190();
    int Get825c00();
    void Do9cd150();
    bool Test9cfd70();
    void Do9cdf00();
    void Do9cd5e0();
    void CombatProcedureAttackMelee_HandleEngage();
};

// Chooses a combat action from range, controller state and target checks, calling Do9ce190, Do9cd150, Do9cdf00 or Do9cd5e0.
// @fnv 0x009cd430
// src: XBOX_PDB 0x009cd430
void CombatProc9cd430::CombatProcedureAttackMelee_HandleEngage()
{
    if (Check44edb0())
        return;
    Actor* actor = GetActor();
    void* target = GetTarget();
    float distance = GetF1();
    float reachDist = GetF2();
    float m_fGlyphExtent = 0.0f;
    float fImpulseRadiusSquared = 0.0f;
    bool inRange = Test9cefd0(distance, reachDist, 0);
    if (inRange && !m_04->CombatController_HasLineOfSight() && IsTargetInCone(actor, target, 0))
    {
        Do9ce190();
        return;
    }
    if (m_04->GetModifierKey() || Get825c00() == 1)
    {
        Do9cd150();
        return;
    }
    bool bInReach = false;
    if (Test9cf030(distance, reachDist, 0))
    {
        if (distance - reachDist > *originalRuntimeFloatSetting593.Float() || Test9cfd70())
        {
            Do9ce190();
        }
        else
        {
            Do9cdf00();
            return;
        }
    }
    else if (bInReach && distance < *originalRuntimeFloatSetting593.Float())
    {
        // The shared slot 0x1E4 has no argument; preserve this call's original int argument.
        bool ok = FUN_005f2670(((MeleeAnimationState* (__thiscall *)(Actor*, int))(*(void***)actor)[0x79])(actor, 4)->Animation_GetGroup());
        if (!ok)
            Do9cdf00();
    }
    else
    {
        Do9cd5e0();
    }
}

struct CombatAttackVT
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual int v07d();
};

struct CombatVec3
{
    float x;
    float y;
    float z;
};
void __cdecl CombatUtilities_ComputeFaceTargetLocation(CombatVec3* out, void* a, CombatAttackVT* b, int c, float f);

class CombatAttackHelper
{
  public:
    void* CombatProcedure_GetAttacker();
    CombatAttackVT* GetTarget_00996e00();
    void SetMoveMode_00996e20(int);
    void SetMode(int mode);
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    void CombatProcedureAttackMelee_MoveToFaceTargetLocation(CombatVec3* out);
    void UpdateCombatMovement();
    void CombatProcedureAttackMelee_StartClose();
};

// @fnv 0x009cdf00
// src: XBOX_PDB 0x009cdf00
void CombatAttackHelper::CombatProcedureAttackMelee_StartClose()
{
    void* a;
    CombatAttackVT* b;
    CombatVec3 out4;
    SetMode(3);
    a = CombatProcedure_GetAttacker();
    b = GetTarget_00996e00();
    SetMoveMode_00996e20(1);
    CombatUtilities_ComputeFaceTargetLocation(&out4, a, b, b->v07d(), CombatProcedureAttackMelee_GetCurrentAttackReach());
    CombatProcedureAttackMelee_MoveToFaceTargetLocation(&out4);
    UpdateCombatMovement();
}

struct AttackDirection
{
    int iDirection;
};
struct PowerAttackEntry
{
    int iAttackId;
};
void* __cdecl ourMemset(void*, int, unsigned int);
float __cdecl BSMAX_00404010(float, float);
unsigned int __cdecl FUN_00944460(unsigned int, unsigned int);
void __cdecl Warning_005b5e40(const char*, ...);
bool __cdecl CombatController_GetShowVerboseMessages();
void __cdecl Interface_PrintLine(const char*, ...);

extern double DAT_01012060;
extern double DAT_01012070;
extern double DAT_01090d68;
extern double DAT_01021798;
extern int DAT_011a5ac8[];

extern Setting DAT_011ceb98;

struct WeapObj
{
    float Projectile_GetDistanceMoved();
};



struct AttackData
{
    float GetFloatAtOffsetB0();
    bool HasCombatFlag(int);
    bool DispatchByType(int);
};

struct AttackInfo
{
    AttackInfo();
    char unk00[12];
};

struct CombatCtrl
{
    AttackData* GetCurrentCombatStyle();
    bool FUN_00981970();
    bool CombatController_ShouldInitPowerAttackDistances();
    void UpdateActorValues();
    bool FUN_008d8220();
    float CombatController_GetPowerAttackRange(int);
    float CombatController_GetPowerAttackHitTime_009cef90(int);
    bool CombatController_GetPowerAttackDelta(int, AttackInfo*);
};

struct ProcX
{
    int m_00;
    CombatCtrl* m_04;
    Actor* CombatProcedure_GetAttacker();
    bool IsWithinThreshold(float, float, int);
    float CombatProcedureAttackMelee_GetMovingTargetVelocity();
};

// Chooses a melee attack id from five candidates based on distance, reach, weapon speed and actor state, then logs the selection.
// @fnv 0x009ce870
// src: XBOX_PDB 0x009ce870
int S009ce870::CombatProcedureAttackMelee_SelectPowerAttack(float afDistance, float afReach, bool, bool, int)
{
    bool bSelected9 = false;
    bool unk3a5 = false;
    int iResult = 0xff;
    int iAttack5 = 0xff;
    int count = 0;
    bool abAllowedA[5];
    ourMemset(abAllowedA, 0, 5);
    Actor* pActorF = ((ProcX*)this)->CombatProcedure_GetAttacker();
    AttackData* pDataVal = ((ProcX*)this)->m_04->GetCurrentCombatStyle();
    if (((ProcX*)this)->m_04->FUN_00981970())
        return 0xff;
    if (!((ProcX*)this)->m_04->CombatController_ShouldInitPowerAttackDistances())
        ((ProcX*)this)->m_04->UpdateActorValues();
    bool bPower7 = ((ProcX*)this)->m_04->FUN_008d8220() && !((ProcX*)this)->IsWithinThreshold(afDistance, afReach, 0);
    float fMultX = bPower7 ? pDataVal->GetFloatAtOffsetB0() : 1.0f;
    WeapObj* pWeap4 = (WeapObj*)pActorF->GetAnimData();
    float fSpeed7 = pWeap4->Projectile_GetDistanceMoved();
    if (fSpeed7 <= DAT_01012060)
        fSpeed7 = 1.0f;
    float fRateB = ((ProcX*)this)->CombatProcedureAttackMelee_GetMovingTargetVelocity();
    float fReach5 = afReach * fMultX;
    bool bAny6 =
        pActorF->GetCurrentActorValue((ActorValue::Index)0x1d) > DAT_01012060 && pActorF->GetCurrentActorValue((ActorValue::Index)0x1e) > DAT_01012060;
    int aiAttacks[5];
    for (int i = 0; i < 5; i++)
    {
        float fMin = ((ProcX*)this)->m_04->CombatController_GetPowerAttackRange(i);
        if (fMin > DAT_01012070 && !bAny6)
            continue;
        float fScaledValue = BSMAX_00404010((float)(fMin * fMultX), fReach5);
        float fTime = ((ProcX*)this)->m_04->CombatController_GetPowerAttackHitTime_009cef90(i);
        if (fTime < DAT_01012060)
            continue;
        int aiSoundId = i + 0x5c;
        if (pDataVal->HasCombatFlag(1) && !pDataVal->DispatchByType(aiSoundId))
            continue;
        float fDistB = fTime * fRateB / fSpeed7 + afDistance;
        if (fDistB <= fScaledValue && (fMin <= fReach5 || fScaledValue * DAT_01090d68 < fDistB))
        {
            aiAttacks[count] = aiSoundId;
            count++;
            abAllowedA[i] = true;
        }
    }
    if (count == 0)
        return 0xff;
    for (int j = count; j < 5; j++)
        aiAttacks[j] = 0xff;
    if (count == 1)
    {
        iAttack5 = aiAttacks[0];
    }
    else if (count > 1 && bPower7 && !pDataVal->HasCombatFlag(1))
    {
        int r = FUN_00944460(0, count);
        iAttack5 = aiAttacks[r];
    }
    if (iAttack5 == 0xff)
    {
        if (!pDataVal->HasCombatFlag(1))
        {
            int k = 5;
            if (abAllowedA[2] && afDistance < *DAT_011ceb98.Setting_Float_00403e20())
            {
                k = 2;
            }
            else if (abAllowedA[1] && afDistance > afReach * DAT_01021798)
            {
                k = 1;
            }
            else
            {
                unsigned short usMove = (unsigned short)pActorF->GetActorStateFlags();
                if (abAllowedA[3] && (usMove & 4))
                {
                    k = 3;
                }
                else if (abAllowedA[4] && (usMove & 8))
                {
                    k = 4;
                }
                else if (abAllowedA[0])
                {
                    k = 0;
                }
            }
            if (k != 5)
                iAttack5 = DAT_011a5ac8[k];
        }
        if (iAttack5 == 0xff)
        {
            unsigned char aucWeightsA[5];
            for (unsigned int u = 0; u < 5; u++)
            {
                int aiSoundId = u + 0x5c;
                aucWeightsA[u] = pDataVal->DispatchByType(aiSoundId);
            }
            unsigned int uiTotal = 0;
            for (unsigned int u = 0; u < (unsigned int)count; u++)
                uiTotal += aucWeightsA[aiAttacks[u] - 0x5c];
            if (uiTotal > 0)
            {
                unsigned int uiAttackSelectionRoll = FUN_00944460(0, uiTotal);
                unsigned int uiAcc = 0;
                for (unsigned int u = 0; u < (unsigned int)count; u++)
                {
                    uiAcc += aucWeightsA[aiAttacks[u] - 0x5c];
                    if (uiAttackSelectionRoll <= uiAcc)
                    {
                        iAttack5 = aiAttacks[u];
                        break;
                    }
                }
            }
        }
    }
    AttackInfo info7;
    if (!((ProcX*)this)->m_04->CombatController_GetPowerAttackDelta(iAttack5, &info7))
        Warning_005b5e40("Melee Attacker %s (%0X) is using %d attack for power attack\n", pActorF->TESObjectREFR_GetFullName(),
                     pActorF->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), iAttack5);
    iResult = iAttack5;
    bSelected9 = true;
    if (CombatController_GetShowVerboseMessages() && bSelected9)
    {
        Interface_PrintLine("%.20s selects %s power attack!", pActorF->TESObjectREFR_GetFullName(),
                     iResult == 0x5c   ? "NORMAL"
                     : iResult == 0x5d ? "FORWARD"
                     : iResult == 0x5e ? "BACKWARD"
                     : iResult == 0x5f ? "LEFT"
                     : iResult == 0x60 ? "RIGHT"
                                       : "NO");
    }
    return iResult;
}

struct CombatContext
{
    CombatNode_combatprocedureattackmelee* GetCurrentCombatStyle();
};
extern double DAT_01012060;
struct MeleeProcedure
{
    int unk00;
    CombatContext* context;
    Actor* CombatProcedure_GetAttacker();
    bool IsActionAvailable(unsigned);
};
// Returns true if the combat node's value exceeds DAT_01012060 and, when flag 1 is set, the per-action check for action 92-96 is positive.
// @fnv 0x009cf420
bool MeleeProcedure::IsActionAvailable(unsigned action)
{
    Actor* actor = CombatProcedure_GetAttacker();
    bool result = false;
    if (context->GetCurrentCombatStyle()->GetByteAtOffset8C() > DAT_01012060)
    {
        result = true;
        if (context->GetCurrentCombatStyle()->HasCombatFlag(1))
        {
            switch (action)
            {
            case 92:
                result = context->GetCurrentCombatStyle()->FUN_0073cb80() > 0;
                break;
            case 93:
                result = context->GetCurrentCombatStyle()->TESCombatStyle_GetPowerAttackF() > 0;
                break;
            case 94:
                result = context->GetCurrentCombatStyle()->GetByteAtOffset9A() > 0;
                break;
            case 95:
                result = context->GetCurrentCombatStyle()->GetByteAtOffset9B() > 0;
                break;
            case 96:
                result = context->GetCurrentCombatStyle()->FUN_009e8670() > 0;
                break;
            }
        }
    }
    return result;
}

namespace CombatReaction {
struct Animation
{
};
extern Actor* DAT_011dea3c;
struct Config
{
    float GetField60Float();
    float FUN_00639b20();
    float FUN_0051b860();
    float FUN_009a7c40();
    float GetFloatAtOffset68();
    float GetFloatAt64();
    float FUN_006a78f0();
    float FUN_009b0bd0();
};
struct Owner
{
    Config* GetCurrentCombatStyle();
};
struct Timer
{
    int a, b;
    void FUN_008d7f40(float);
};
struct Options
{
    unsigned short FUN_004a8ae0();
};
extern Setting DAT_011ce380;
extern const double DAT_01012060, DAT_0104f2f0, DAT_01020758, DAT_01017a40;
extern const char DAT_01090cb8[], DAT_01090cb0[], DAT_01090ca4[], DAT_01090c9c[], DAT_01090c60[];
bool CombatUtilities_IsActorUsingRanged(Actor*);
float CombatFormulas_ChooseDodge(Config*, int, float, bool);
unsigned int FUN_00487f50();
unsigned short CombatFormulas_SelectDodgeDirection(Config*, bool, bool, float, float, bool, bool, unsigned short);
float FUN_006465f0(float, float);
int FUN_005f2440(unsigned short);
double BSMAX_00404010(float, float);
bool CombatController_GetShowVerboseMessages();
void Interface_PrintLine(const char*, ...);
struct Procedure
{
    int unk00;
    Owner* owner;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Timer reactionTimer, durationTimer;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    bool special;
    char unk51, unk52, unk53;
    int unk54, unk58, unk5c, unk60;
    Options options;
    Actor* CombatProcedure_GetAttacker();
    Actor* GetTarget_00996e00();
    int FUN_00825c00();
    float GetModifierValue();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    bool CombatProcedureAttackMelee_CheckDodge(int);
    void SetMode(int);
    int TESMain_GetThread();
    void CombatProcedureAttackMelee_StopMoving();
    void EvaluateReaction();
};
// @fnv 0x009cd5e0
void Procedure::EvaluateReaction()
{
    Actor* actor2 = CombatProcedure_GetAttacker();
    Actor* target = GetTarget_00996e00();
    if (!target)
        return;
    bool targetState3 = target->GetAnimAction_008a7570() == 2;
    bool targetCondition3 = CombatUtilities_IsActorUsingRanged(target);
    float chance =
        CombatFormulas_ChooseDodge(owner->GetCurrentCombatStyle(), (int)actor2->GetWalkSpeed(), actor2->GetFatigueRatio(), targetState3);
    if (chance < DAT_01012060)
        chance = 0.0f;
    if (special)
        chance += DAT_0104f2f0;
    if (FUN_00825c00() == 2)
        chance += DAT_01020758;
    if (target != DAT_011dea3c && !target->Actor_IsInCombat())
        chance -= DAT_01017a40;
    if (actor2->IsSwimming_005a2030())
        chance = 0.0f;
    float roll = (float)(FUN_00487f50() % 100);
    if (roll <= chance)
    {
        bool actorState = actor2->GetAnimAction_008a7570() == 2;
        float first2 = GetModifierValue();
        float second7 = CombatProcedureAttackMelee_GetCurrentAttackReach();
        unsigned short action = CombatFormulas_SelectDodgeDirection(owner->GetCurrentCombatStyle(), actorState, targetState3, first2, second7, special,
                                             targetCondition3, options.FUN_004a8ae0());
        if (action)
        {
            Animation* animation = (Animation*)CombatProcedure_GetAttacker()->GetAnimData();
            if (animation)
            {
                int state = 3;
                bool allowed = true;
                float duration3 = 0.0f;
                switch (action & 15)
                {
                case 4:
                    state = 5;
                    allowed = CombatProcedureAttackMelee_CheckDodge(4);
                    duration3 =
                        FUN_006465f0(owner->GetCurrentCombatStyle()->FUN_00639b20(), owner->GetCurrentCombatStyle()->GetField60Float());
                    break;
                case 8:
                    state = 6;
                    allowed = CombatProcedureAttackMelee_CheckDodge(8);
                    duration3 =
                        FUN_006465f0(owner->GetCurrentCombatStyle()->FUN_00639b20(), owner->GetCurrentCombatStyle()->GetField60Float());
                    break;
                case 2:
                    state = 4;
                    duration3 =
                        FUN_006465f0(owner->GetCurrentCombatStyle()->FUN_009a7c40(), owner->GetCurrentCombatStyle()->FUN_0051b860());
                    break;
                default:
                    duration3 = FUN_006465f0(owner->GetCurrentCombatStyle()->GetFloatAt64(),
                                             owner->GetCurrentCombatStyle()->GetFloatAtOffset68());
                    break;
                }
                if (FUN_005f2440(CombatProcedure_GetAttacker()->Actor_GetAnimGroup(state, 0, 0, 0)) == state)
                {
                    float current = actor2->Actor_GetAnimGroupDuration(state);
                    duration3 = BSMAX_00404010(current, duration3);
                    float amount_2 = 0.0f;
                    actor2->DispatchToTarget(targetState3 && amount_2 > *DAT_011ce380.Setting_Float_00403e20() ? action | 512
                                                                                                     : action | 256);
                    reactionTimer.FUN_008d7f40(duration3);
                    durationTimer.FUN_008d7f40(current);
                    SetMode(2);
                }
                else if (CombatController_GetShowVerboseMessages())
                    Interface_PrintLine(DAT_01090c60, actor2->TESObjectREFR_GetFullName(),
                                 action & 4   ? DAT_01090cb8
                                 : action & 8 ? DAT_01090cb0
                                 : action & 1 ? DAT_01090ca4
                                              : DAT_01090c9c);
            }
        }
    }
    else if (TESMain_GetThread() != 1)
    {
        float delay = FUN_006465f0(owner->GetCurrentCombatStyle()->FUN_009b0bd0(), owner->GetCurrentCombatStyle()->FUN_006a78f0());
        reactionTimer.FUN_008d7f40(delay);
        CombatProcedureAttackMelee_StopMoving();
        SetMode(1);
    }
}
}

struct Process98
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
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
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
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
    virtual void v12a();
    virtual void v12b();
    virtual void v12c();
    virtual void v12d();
    virtual void v12e();
    virtual void v12f();
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
    virtual void v13a();
    virtual void v13b();
    virtual void v13c();
    virtual void v13d();
    virtual void v13e();
    virtual void v13f();
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
    virtual void v14a();
    virtual void v14b();
    virtual void v14c();
    virtual void v14d();
    virtual void v14e();
    virtual void v14f();
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
    virtual void v15a();
    virtual void v15b();
    virtual void v15c();
    virtual void v15d();
    virtual void v15e();
    virtual void v15f();
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
    virtual void v16a();
    virtual void v16b();
    virtual void v16c();
    virtual void v16d();
    virtual void v16e();
    virtual void v16f();
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
    virtual void v17a();
    virtual void v17b();
    virtual void v17c();
    virtual void v17d();
    virtual void v17e();
    virtual void v17f();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual int State();
};
struct Context98
{
    bool FUN_009818b0();
};
struct Procedure98
{
    int unk00;
    Context98* context;
    Actor* GetTarget_00996e00();
    unsigned int FUN_00825c00();
    void CombatProcedureAttackMelee_HandleAttack();
    void CombatProcedureAttackMelee_HandleBlock();
    void CombatProcedureAttackMelee_HandleHold();
    void CombatProcedureAttackMelee_MeleeDecision();
    void UpdateState();
};
// Gets the actor and dispatches on FUN_00825c00(); in case 3 it checks the process state, context and actor test before calling FUN_009cc510().
// @fnv 0x009cf570
void Procedure98::UpdateState()
{
    Actor* actor = GetTarget_00996e00();
    switch (FUN_00825c00())
    {
    case 0:
        CombatProcedureAttackMelee_HandleAttack();
        break;
    case 1:
        CombatProcedureAttackMelee_HandleBlock();
        break;
    case 2:
        CombatProcedureAttackMelee_HandleHold();
        break;
    case 3: {
        int result = actor && actor->GetProcess() ? ((Process98*)actor->GetProcess())->State() : 0;
        if (!context->FUN_009818b0() && !result && (!actor || !actor->HasHealth(false)))
            CombatProcedureAttackMelee_MeleeDecision();
        break;
    }
    }
}

struct MeleeDebugTimer
{
    float started;
    float target;
    float FUN_00435e00();
    float CombatTimer_GetTargetTime();
    bool CombatTimer_IsSet();
};
struct MeleeDebugFlags
{
    unsigned short flags;
    unsigned short unknown;
    unsigned short FUN_004a8ae0();
    bool HasNoFlag(unsigned short);
    bool TESTextureList_GetTextureCount();
};
struct MeleeDebugOutput
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Print(int, int, const char*, ...);
};
void* FUN_00ec61c0(void*, int, unsigned);
int BSsprintf(char*, unsigned, const char*, ...);
int FUN_00406d30(char*, unsigned, const char*);
extern const char DAT_01011584[], DAT_01090e78[], DAT_01090e6c[], DAT_01090e64[], DAT_01090e5c[], DAT_01090e4c[],
    DAT_01090e40[], DAT_01090e30[];
extern const char DAT_01090cb8[], DAT_01090cb0[], DAT_01090e20[], DAT_01090e10[], DAT_01090e04[], DAT_01090df8[],
    DAT_01090dec[], DAT_01090dc8[], DAT_01090db8[], DAT_01090d8c[], DAT_01090d70[], DAT_01017b68[], DAT_01017b64[];
extern const char* DAT_011a5aa4[];
extern const char* DAT_011a5ab8[];
struct MeleeDebugProcedure
{
    int unk00, unk04, unk08, unk0C;
    int moveState;
    int attackState;
    int unk18;
    int action;
    MeleeDebugTimer attackTimer;
    MeleeDebugTimer moveTimer;
    int unk30, unk34, unk38, unk3C, unk40, unk44;
    MeleeDebugTimer delayTimer;
    int unk50, unk54, unk58, unk5C, unk60;
    MeleeDebugFlags stateFlags;
    Actor* CombatProcedure_GetAttacker();
    void PrintDebugInfo(MeleeDebugOutput*, int, int);
};
// Builds description strings from move, attack and delay timers and prints the procedure's move/attack state and flags via output->Print.
// @fnv 0x009cf700
void MeleeDebugProcedure::PrintDebugInfo(MeleeDebugOutput* output, int x, int y)
{
    Actor* actor = CombatProcedure_GetAttacker();
    short sMovementFlags = (short)actor->GetActorStateFlags();
    char description[100];
    description[0] = DAT_01011584[0];
    FUN_00ec61c0(description + 1, 0, 99);
    switch (moveState)
    {
    case 2:
        BSsprintf(description, 100, DAT_01090e4c,
                     sMovementFlags & 1   ? DAT_01090e78
                     : sMovementFlags & 2 ? DAT_01090e6c
                     : sMovementFlags & 4 ? DAT_01090e64
                     : sMovementFlags & 8 ? DAT_01090e5c
                                          : DAT_01011584,
                     moveTimer.FUN_00435e00(), moveTimer.CombatTimer_GetTargetTime());
        break;
    case 1:
        BSsprintf(description, 100, DAT_01090e40, moveTimer.FUN_00435e00(), moveTimer.CombatTimer_GetTargetTime());
        break;
    default:
        description[0] = 0;
        break;
    }
    output->Print(x, y, DAT_01090e30, DAT_011a5aa4[moveState], description);
    switch (attackState)
    {
    case 0:
        FUN_00406d30(description, 100,
                     action == 26   ? DAT_01090cb8
                     : action == 32 ? DAT_01090cb0
                     : action == 92 ? DAT_01090e20
                     : action == 93 ? DAT_01090e10
                     : action == 94 ? DAT_01090e04
                     : action == 95 ? DAT_01090df8
                     : action == 96 ? DAT_01090dec
                                    : DAT_01011584);
        break;
    case 2:
        BSsprintf(description, 100, DAT_01090e40, attackTimer.FUN_00435e00(), attackTimer.CombatTimer_GetTargetTime());
        break;
    default:
        description[0] = 0;
        break;
    }
    if (delayTimer.CombatTimer_IsSet())
        output->Print(x, y, DAT_01090dc8, delayTimer.FUN_00435e00(), delayTimer.CombatTimer_GetTargetTime());
    output->Print(x, y, DAT_01090db8, DAT_011a5ab8[attackState], description);
    if (stateFlags.FUN_004a8ae0() && !actor->IsPathing())
        output->Print(x, y, DAT_01090d8c, stateFlags.HasNoFlag(4) ? DAT_01017b68 : DAT_01017b64,
                      stateFlags.HasNoFlag(8) ? DAT_01017b68 : DAT_01017b64,
                      stateFlags.HasNoFlag(1) ? DAT_01017b68 : DAT_01017b64,
                      stateFlags.HasNoFlag(2) ? DAT_01017b68 : DAT_01017b64);
    if (stateFlags.TESTextureList_GetTextureCount())
        output->Print(x, y, DAT_01090d70);
}



class Position9CF
{
  public:
    const NiPoint3& GetPos();
};


extern Setting g_kTalkDistance9CF;

bool __cdecl IsMenuMode9CF();

class Dialogue9CF
{
  public:
    Actor* GetSpeaker();
    void Stop();
    void StopIfSpeakerOutOfRange();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    Position9CF m_kListener;
};

// @fnv 0x009cfc90
void Dialogue9CF::StopIfSpeakerOutOfRange()
{
    if (!IsMenuMode9CF())
    {
        Actor* pkSpeaker = GetSpeaker();
        NiPoint3 kDelta = m_kListener.GetPos() - *(const NiPoint3*)((const Actor*)pkSpeaker)->GetPos();
        if (kDelta.FUN_004a7290() >= *g_kTalkDistance9CF.Float() * *g_kTalkDistance9CF.Float())
            Stop();
    }
}

extern NiPoint3 kPt3Zero;
struct CombatProcStub
{
    Actor* GetTarget();
    Actor* GetActor();
    float GetRange();
    bool IsTargetOutOfRange();
};
// Checks the actor is alive, projects a point ahead of it along its heading, and returns whether the target is at least range*range away from that point.
// @fnv 0x009cfd70
bool CombatProcStub::IsTargetOutOfRange()
{
    NiPoint3 unusedPos8 = kPt3Zero;
    NiPoint3 heading = kPt3Zero;
    if (!GetActor() || !GetActor()->IsMoving_004938e0())
        return false;
    GetActor()->Unk_AB(*(NiPoint3*)&heading);
    heading.z = 0.0f;
    NiPoint3 aheadX = *(NiPoint3*)((const Actor*)GetActor())->GetPos() + heading;
    float aRange = GetRange();
    NiPoint3 diff4 = *(NiPoint3*)((const Actor*)GetTarget())->GetPos() - aheadX;
    float dist = diff4.Length();
    return dist >= aRange * aRange;
}

struct FUN_006815c0
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    FUN_006815c0();
    void FUN_004a0c90(float, int);
    NiPoint3 FUN_004b4500(const NiPoint3&) const;
};
struct Control057
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
    virtual bool Check(int);
};
extern Setting DAT_011cf968;
float __cdecl BSMIN(float, float);
struct State057
{
    bool active, initialized;
    int mode;
    short mask;
    bool left, right, forward, back;
    NiPoint3 position;
    int UpdateDirection(Actor* actor, unsigned direction);
    bool CombatMovementRestrictions_IsLocationSafe(Actor*, const NiPoint3&);
    void UpdateFlags(unsigned short, bool);
};
// Initializes direction flags from controls, updates position, and for the given direction tests a rotated offset point, storing the result via UpdateFlags.
// @fnv 0x009cff90
int State057::UpdateDirection(Actor* actor, unsigned direction)
{
    if (!initialized)
    {
        left = ((Control057*)actor->GetProcess())->Check(5);
        right = ((Control057*)actor->GetProcess())->Check(6);
        forward = ((Control057*)actor->GetProcess())->Check(3);
        back = ((Control057*)actor->GetProcess())->Check(4);
        initialized = true;
    }
    if (!active && actor->IsPathing())
        return 4;
    else if (!active && direction == 0)
    {
        NiPoint3 f = position.SubtractIntoVector(*(NiPoint3*)((const Actor*)actor)->GetPos());
        if (f.FUN_00457990() < *DAT_011cf968.Setting_Float_00403e20())
            return 4;
    }
    position = *(NiPoint3*)((const Actor*)actor)->GetPos();
    FUN_006815c0 a;
    // The shared slot 0x2BC takes bool; this original call has no argument and returns float.
    a.FUN_004a0c90(((float (__thiscall *)(Actor*))(*(void***)actor)[0xaf])(actor), 0);
    float b = ((ActorMeleeCalls*)actor)->Actor_GetWidth();
    if (b == 0.0)
        b = 32.0f;
    float e = ((ActorMeleeCalls*)actor)->Actor_GetLength();
    if (e == 0.0)
        e = b;
    unsigned c;
    float d = b / e;
    if (d > 0.5 && d < 2.0)
    {
        b = BSMAX_00404010(b, e);
        e = b;
    }
    b = BSMIN(b, 64.0f);
    e = BSMIN(e, 64.0f);
    c = actor->GetActorStateFlags();
    switch (direction)
    {
    case 0: {
        NiPoint3 g(0.0f, -e, 0.0f);
        if (c & 2)
            g.y -= e;
        g = a.FUN_004b4500(g).FUN_00439e90(position);
        UpdateFlags(2, back ? CombatMovementRestrictions_IsLocationSafe(actor, g) : false);
        break;
    }
    case 1: {
        NiPoint3 h(0.0f, e, 0.0f);
        if (c & 1)
            h.y += e;
        h = a.FUN_004b4500(h).FUN_00439e90(position);
        UpdateFlags(1, forward ? CombatMovementRestrictions_IsLocationSafe(actor, h) : false);
        break;
    }
    case 2: {
        NiPoint3 i(-b, 0.0f, 0.0f);
        if (c & 4)
            i.x -= b;
        i = a.FUN_004b4500(i).FUN_00439e90(position);
        UpdateFlags(4, left ? CombatMovementRestrictions_IsLocationSafe(actor, i) : false);
        break;
    }
    case 3: {
        NiPoint3 j(b, 0.0f, 0.0f);
        if (c & 8)
            j.x += b;
        j = a.FUN_004b4500(j).FUN_00439e90(position);
        UpdateFlags(8, right ? CombatMovementRestrictions_IsLocationSafe(actor, j) : false);
        break;
    }
    }
    return 1;
}

class GlobalObject_0045d260
{
  public:
    void FUN_00483710();
};
extern GlobalObject_0045d260 g_011f24e4;
extern Setting originalRuntimeFloatSetting594;
struct P12_9cc240
{
    float dst0, y, z;
};
struct Act9cc240
{
    bool DidPathingFail();
    bool Actor_IsPathValid();
    float TESObjectREFR_GetScale_00567400();
};
struct Tgt9cc240
{
    P12_9cc240* TESObjectREFR_GetWorldLocation(P12_9cc240* p);
};
struct Proc9cc240
{
    void CombatState_SetLocationUnreachable(int);
    void SetNodeBlockAndTimestamp(P12_9cc240*);
};
struct Own9cc240
{
    Proc9cc240* CombatController_GetCombatState();
};
struct Sub64_9cc240
{
    void CombatMovementRestrictions_Update(Own9cc240*);
};
struct Sub48_9cc240
{
    bool CombatTimer_IsSet();
    void FUN_008d7f40(float);
    bool FUN_008d7f80();
    void TESWeightForm_InitializeDataComponent();
};
P12_9cc240* GetTargetLocationWithOffset(P12_9cc240* r, Tgt9cc240* t, int n);
struct CPAM9cc240
{
    int m0;
    Own9cc240* m4;
    int m8, mc;
    int m10;
    int m14;
    char pad18[0x30];
    Sub48_9cc240 m48;
    char pad49[0x13];
    float m5c;
    int m60;
    Sub64_9cc240 m64;
    Act9cc240* CombatProcedure_GetAttacker();
    Tgt9cc240* GetTarget_00996e00();
    void UpdateState();
    void FUN_00483710();
    unsigned int TESMain_GetThread();
    void CombatProcedure_SetFailed(const char*);
    void CombatProcedureAttackMelee_HandleEngage();
    void UpdateDodge();
    void CombatProcedureAttackMelee_HandleIdle();
    void UpdateCombatMovement();
    void UpdateMeleeCombat();
    float GetModifierValue();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    void SetLookAtPoint(P12_9cc240*, int);
    void ClearLookAtTarget_00996ea0();
    void UpdateCombatState();
};
// @fnv 0x009cc240
void CPAM9cc240::UpdateCombatState()
{
    float _v;
    float a7;
    int h3;
    Act9cc240* dst0;
    P12_9cc240 j;
    P12_9cc240 dst2;
    dst0 = CombatProcedure_GetAttacker();
    Tgt9cc240* idxTmp;
    idxTmp = GetTarget_00996e00();
    m5c = -1.0f;
    g_011f24e4.FUN_00483710();
    m64.CombatMovementRestrictions_Update(m4);
    UpdateState();
    FUN_00483710();
    if (TESMain_GetThread() == 3 || TESMain_GetThread() == 4)
    {
        if (dst0->DidPathingFail() && !dst0->Actor_IsPathValid())
        {
            if (!m48.CombatTimer_IsSet())
            {
                m48.FUN_008d7f40(2.0f);
            }
            else if (m48.FUN_008d7f80())
            {
                m4->CombatController_GetCombatState()->CombatState_SetLocationUnreachable(2);
                m4->CombatController_GetCombatState()->SetNodeBlockAndTimestamp(idxTmp->TESObjectREFR_GetWorldLocation(&j));
                CombatProcedure_SetFailed("Could not reach target");
            }
        }
        else if (dst0->Actor_IsPathValid())
        {
            m48.TESWeightForm_InitializeDataComponent();
        }
    }
    else
    {
        m48.TESWeightForm_InitializeDataComponent();
    }
    switch (TESMain_GetThread())
    {
    case 0:
        CombatProcedureAttackMelee_HandleEngage();
        break;
    case 2:
        UpdateDodge();
        break;
    case 1:
        CombatProcedureAttackMelee_HandleIdle();
        break;
    case 3:
        UpdateCombatMovement();
        break;
    case 4:
        UpdateMeleeCombat();
        break;
    }
    bool bDone6;
    bDone6 = false;
    if (3 != m14)
    {
        bDone6 = true;
    }
    else if (m10 == 3)
    {
        bDone6 = true;
    }
    else
    {
        _v = GetModifierValue();
        a7 = CombatProcedureAttackMelee_GetCurrentAttackReach();
        if (_v - a7 < *originalRuntimeFloatSetting594.Float() * dst0->TESObjectREFR_GetScale_00567400() * 2.25)
            bDone6 = true;
    }
    if (bDone6)
    {
        GetTargetLocationWithOffset(&dst2, idxTmp, 2);
        SetLookAtPoint(&dst2, 4);
    }
    else
    {
        ClearLookAtTarget_00996ea0();
    }
    g_011f24e4.FUN_00483710();
}

struct Seq150
{
    int FUN_008041a0();
};
struct Anim150
{
    Seq150* Animation_GetCurrentSequence(int);
};
struct State150
{
    bool GetModifierKey();
    void FUN_009818e0(int);
};
unsigned int FUN_00487f50();
struct C150
{
    int pad;
    State150* m04;
    ActorMeleeCalls* CombatProcedure_GetAttacker();
    ActorMeleeCalls* GetTarget_00996e00();
    int FUN_00825c00();
    void CombatProcedureAttackMelee_SetCombatState(int);
    float GetModifierValue();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    void CombatProcedureAttackMelee_CheckStopBlocking();
};
// @fnv 0x009cd150
// src: COMMUNITY 0x009cd150
void C150::CombatProcedureAttackMelee_CheckStopBlocking()
{
    if (((Anim150*)CombatProcedure_GetAttacker()->GetAnimData()) && ((Anim150*)CombatProcedure_GetAttacker()->GetAnimData())->Animation_GetCurrentSequence(2) &&
        ((Anim150*)CombatProcedure_GetAttacker()->GetAnimData())->Animation_GetCurrentSequence(2)->FUN_008041a0() != 1)
        return;
    ActorMeleeCalls* actor2 = CombatProcedure_GetAttacker();
    ActorMeleeCalls* target7 = GetTarget_00996e00();
    if (m04->GetModifierKey() || FUN_00825c00() == 1)
    {
        if (!target7)
        {
            if (actor2->GetBlocked())
                actor2->Actor_SetBlock(false);
            m04->FUN_009818e0(0);
            if (FUN_00825c00() == 1)
                CombatProcedureAttackMelee_SetCombatState(3);
            return;
        }
        bool active = target7->Actor_IsAttacking();
        bool action = target7->GetAnimAction_008a7570() == 4;
        bool state2 = false;
        if (((State150*)target7->GetCombatController()))
            state2 = ((State150*)target7->GetCombatController())->GetModifierKey();
        float elapsedTmp = GetModifierValue();
        float limit = CombatProcedureAttackMelee_GetCurrentAttackReach();
        bool flag_ = false;
        bool blocked = target7->GetIsParalyzed() || target7->GetHasKnockedState() || target7->Actor_IsUnConscious() || target7->Actor_IsSleeping() ||
                       target7->Actor_IsRestrained();
        if (!(!(elapsedTmp > limit) && !blocked && !action && !state2 &&
              (FUN_00487f50() % 100 >= 5 || (active && !flag_)) && actor2->GetBlocked()))
        {
            if (actor2->GetBlocked())
                actor2->Actor_SetBlock(false);
            m04->FUN_009818e0(0);
            if (FUN_00825c00() == 1)
                CombatProcedureAttackMelee_SetCombatState(3);
        }
    }
}



struct CombatProcedure_shell : public FUN_009cde10_shell
{
    int unk00;
    void* m_04;

    int TESMain_GetThread();
    ActorMeleeCalls* CombatProcedure_GetAttacker();
    Actor* GetTarget_00996e00();
    void CombatProcedureAttackMelee_StartAdvance();
    void CombatProcedureAttackMelee_MoveToFaceTargetLocation(CombatVec3*);
    unsigned char IsWithinThreshold(float, float, int);
    void UpdateCombatMovement();
};

float __cdecl CombatUtilities_GetAttackerTargetExtentSum(ActorMeleeCalls*, Actor*);

// @fnv 0x009cdf80
void CombatProcedure_shell::UpdateCombatMovement()
{
    ActorMeleeCalls* actor;
    unsigned short wVal;
    float f0c;
    Actor* target8;
    CombatVec3 vec1c3;
    float fX;

    if (this->TESMain_GetThread() != 3)
    {
        return;
    }

    actor = this->CombatProcedure_GetAttacker();
    target8 = this->GetTarget_00996e00();
    f0c = this->GetModifierValue();
    fX = this->CombatProcedureAttackMelee_GetCurrentAttackReach();
    wVal = (unsigned short)actor->GetActorStateFlags();

    if (!actor->IsPathing())
    {
        this->CombatProcedureAttackMelee_StartEngage();
        return;
    }

    CombatUtilities_ComputeFaceTargetLocation(&vec1c3, actor, (CombatAttackVT*)target8, (int)&*(NiPoint3*)((const Actor*)target8)->GetPos(), this->CombatProcedureAttackMelee_GetCurrentAttackReach());

    if (f0c > *originalRuntimeFloatSetting593.Float() * 2)
    {
        if (!this->GetSection())
        {
            this->CombatProcedureAttackMelee_StartAdvance();
        }
        return;
    }

    if (this->CombatProcedureAttackMelee_OutsideAttackRange(f0c, fX, 0) && CombatController_HasLineOfSight(this->m_04))
    {
        unsigned char b_ = 0;
        LocalPoint3Ext pt9;
        if (actor->IsWaitingOnPath())
        {
            b_ = 1;
        }
        else if (actor->Actor_GetCurrentPathfindingGoal(&pt9))
        {
            float f38 = CombatUtilities_GetAttackerTargetExtentSum(actor, target8);
            float f5 = ((LocalPoint3Ext&)(pt9 - (const NiPoint3&)*(NiPoint3*)((const Actor*)target8)->GetPos())).Length() - f38;
            b_ = this->IsWithinThreshold(f5, fX, 0);
        }
        if (!b_)
        {
            this->CombatProcedureAttackMelee_MoveToFaceTargetLocation(&vec1c3);
        }
        return;
    }

    if (this->IsWithinThreshold(f0c, fX, 0))
    {
        if ((wVal & 2) && f0c < *originalRuntimeFloatSetting593.Float())
        {
            this->UpdateState();
        }
        else
        {
            this->CombatProcedureAttackMelee_StartEngage();
        }
    }
}

struct ZPoint
{
    float unk00, unk04, unk08;
    float NiPoint3_XYLength() const;
};
struct B006815c0
{
    float unk00, unk04, unk08;
    B006815c0();
    ZPoint SubtractIntoVector(const ZPoint&) const;
};
struct ZAnim
{
    char Animation_FindNextNoteKey();
};
struct ZProcess
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
    virtual bool Check();
};
// Retained: this slot 0x1E4 animation call passes three ints; the shared method has no parameters.
struct ZActor
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
    virtual ZAnim* Anim(int, int, int);
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const ZPoint& Pos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual bool Check();
    ZProcess* FUN_008d8520();
    bool IsWaitingOnPath();
    bool Actor_IsStoppingMovement();
    bool Actor_GetCurrentPathfindingGoal(B006815c0*);
    bool FUN_008b3bb0();
    bool GetBlocked();
    void Actor_SetBlock(bool);
};
void __cdecl CombatUtilities_ComputeFaceTargetLocation(ZPoint*, ZActor*, ZActor*, const ZPoint&, float);
float __cdecl CombatUtilities_GetAttackerTargetExtentSum(ZActor*, ZActor*);
bool __cdecl IsTargetInCone(ZActor*, ZActor*, int);
extern Setting g_011cf27c;
extern double DAT_01017a40;
struct ZMelee
{
    int unk00;
    char* unk04;
    int unk08, unk0C, unk10, unk14;
    int TESMain_GetThread();
    ZActor* CombatProcedure_GetAttacker();
    ZActor* GetTarget_00996e00();
    float GetModifierValue();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    bool IsTargetOutOfRange();
    bool CombatProcedureAttackMelee_OutsideAttackRange(float, float, int);
    bool IsWithinThreshold(float, float, int);
    void CombatProcedureAttackMelee_MoveToFaceTargetLocation(ZPoint*);
    void CombatProcedureAttackMelee_StartEngage();
    void CombatProcedureAttackMelee_StartClose();
    int FUN_00825c00();
    void CombatProcedureAttackMelee_StartAttack(int, int);
    void TryAttackTarget(float, float);
    void UpdateMeleeCombat();
};
// @fnv 0x009ce1d0
void ZMelee::UpdateMeleeCombat()
{
    if (TESMain_GetThread() != 4)
        return;
    ZActor* actor2 = CombatProcedure_GetAttacker();
    ZActor* target2 = GetTarget_00996e00();
    float distance3 = GetModifierValue();
    float kReach = CombatProcedureAttackMelee_GetCurrentAttackReach();
    bool mid4 = IsTargetOutOfRange();
    ZProcess* process2 = actor2->FUN_008d8520();
    if ((CombatProcedureAttackMelee_OutsideAttackRange(distance3, kReach, 0) && CombatController_HasLineOfSight((void*)unk04)) || !CombatController_HasLineOfSight((void*)unk04))
    {
        ZPoint point2;
        CombatUtilities_ComputeFaceTargetLocation(&point2, actor2, target2, target2->Pos(), CombatProcedureAttackMelee_GetCurrentAttackReach());
        bool ready3 = false;
        B006815c0 kPos;
        if (actor2->IsWaitingOnPath())
            ready3 = true;
        else if (!actor2->Actor_IsStoppingMovement() && actor2->Actor_GetCurrentPathfindingGoal(&kPos))
        {
            float _radius = CombatUtilities_GetAttackerTargetExtentSum(actor2, target2);
            float delta = kPos.SubtractIntoVector(target2->Pos()).NiPoint3_XYLength() - _radius;
            ready3 = IsWithinThreshold(delta, kReach, 0);
        }
        if (!ready3)
            CombatProcedureAttackMelee_MoveToFaceTargetLocation(&point2);
    }
    if (actor2->FUN_008b3bb0())
    {
        if (!mid4)
            CombatProcedureAttackMelee_StartEngage();
    }
    else if (actor2->GetBlocked())
        actor2->Actor_SetBlock(false);
    else if (IsWithinThreshold(distance3, kReach, 0) && CombatController_HasLineOfSight((void*)unk04))
    {
        if (mid4 && distance3 < *originalRuntimeFloatSetting593.Float() * 2.0f)
            CombatProcedureAttackMelee_StartClose();
        else
            CombatProcedureAttackMelee_StartEngage();
    }
    else if (FUN_00825c00() && IsWithinThreshold(distance3, kReach * 2.0f, 0) && CombatController_HasLineOfSight((void*)unk04) &&
             actor2->Check() && process2 && process2->Check())
    {
        if (IsTargetInCone(actor2, target2, 0))
        {
            int topicB = GetCurrentWeapon((int)unk04);
            if (DialogueRandom() % 100 < (int)(*g_011cf27c.Float() * DAT_01017a40))
            {
                int attackVal = 255;
                if (actor2->Anim(1, DAT_011a8244, 0)->Animation_FindNextNoteKey() == 108)
                    attackVal = 26;
                else
                    attackVal = 32;
                CombatProcedureAttackMelee_StartAttack(attackVal, 0);
            }
        }
    }
    else if (unk14)
        TryAttackTarget(distance3, kReach);
}

struct AnimData_9cf
{
    unsigned short Animation_GetGroup(int);
};

struct ActorProcess_9cf
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
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual void va4();
    virtual void va5();
    virtual void va6();
    virtual void va7();
    virtual void va8();
    virtual void va9();
    virtual void vaa();
    virtual void vab();
    virtual void vac();
    virtual void vad();
    virtual void vae();
    virtual void vaf();
    virtual void vb0();
    virtual void vb1();
    virtual void vb2();
    virtual void vb3();
    virtual void vb4();
    virtual void vb5();
    virtual void vb6();
    virtual void vb7();
    virtual void vb8();
    virtual void vb9();
    virtual void vba();
    virtual void vbb();
    virtual void vbc();
    virtual void vbd();
    virtual void vbe();
    virtual void vbf();
    virtual void vc0();
    virtual void vc1();
    virtual void vc2();
    virtual void vc3();
    virtual void vc4();
    virtual void vc5();
    virtual void vc6();
    virtual void vc7();
    virtual void vc8();
    virtual void vc9();
    virtual void vca();
    virtual void vcb();
    virtual void vcc();
    virtual void vcd();
    virtual void vce();
    virtual void vcf();
    virtual void vd0();
    virtual void vd1();
    virtual void vd2();
    virtual void vd3();
    virtual void vd4();
    virtual void vd5();
    virtual void vd6();
    virtual void vd7();
    virtual void vd8();
    virtual void vd9();
    virtual void vda();
    virtual void vdb();
    virtual void vdc();
    virtual void vdd();
    virtual void vde();
    virtual void vdf();
    virtual void ve0();
    virtual void ve1();
    virtual void ve2();
    virtual void ve3();
    virtual void ve4();
    virtual void ve5();
    virtual void ve6();
    virtual void ve7();
    virtual void ve8();
    virtual void ve9();
    virtual void vea();
    virtual void veb();
    virtual void vec();
    virtual void ved();
    virtual void vee();
    virtual void vef();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vfa();
    virtual void vfb();
    virtual void vfc();
    virtual void vfd();
    virtual bool V254();
};

struct Obj_9cf
{
    char GetByteAtOffsetAD();
};

struct Context_9cf
{
    bool FUN_008d8220();
    bool CombatController_HasLineOfSight();
    Obj_9cf* GetCurrentCombatStyle();
    int CombatController_GetAttackSkill();
    int GetCurrentWeapon();
};


struct CTSHelper
{
    int m_val;
    void* FUN_00435de0(float);
    float FUN_00435e00();
};

bool __cdecl IsTargetInCone(ActorMeleeCalls*, ActorMeleeCalls*, int);
bool __cdecl CombatUtilities_CalculateLOS(ActorMeleeCalls*, ActorMeleeCalls*, void*, void*, int, int);
float __cdecl CombatTimer_GetTimer();

struct FUN_009cf090_Class
{
    int unk00;
    Context_9cf* m_04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c;
    CTSHelper m_timer60;

    int FUN_00825c00();
    ActorMeleeCalls* CombatProcedure_GetAttacker();
    ActorMeleeCalls* GetTarget_00996e00();
    int CombatProcedureAttackMelee_SelectPowerAttack(float, float, bool, bool, int);
    bool IsActionAvailable(int);
    void CombatProcedureAttackMelee_StartAttack(int, int);
    void SetMode(int);

    void TryAttackTarget(float a1, float a2);
};

// @fnv 0x009cf090
void FUN_009cf090_Class::TryAttackTarget(float afArg1, float afArg2)
{
    ActorMeleeCalls* pkActorVal;
    bool bTargetRecoiling;
    {
        int iAttack4;
        bool bTargetAttacking4;
        int iAnimAction4;
        bool bTargetMidAttack3;
        bool bTargetPostAttack_2;
        bool bInAttackAnim5;
        ActorMeleeCalls* pkTarget5;
        int iRandA;
        float fPercent4;
        float aFMax;
        float fChanceTmp;
        CTSHelper helper_;

        if (this->FUN_00825c00() != 3)
        {
            return;
        }

        pkActorVal = this->CombatProcedure_GetAttacker();
        pkTarget5 = this->GetTarget_00996e00();
        if (!pkTarget5)
        {
            return;
        }

        if (this->m_timer60.FUN_00435e00() < 1.0)
        {
            return;
        }

        if (!this->m_04->FUN_008d8220())
        {
            return;
        }

        if (!((ActorProcess_9cf*)pkActorVal->FUN_008d8520())->V254())
        {
            return;
        }

        bInAttackAnim5 = (((AnimData_9cf*)pkActorVal->GetAnimData()) != 0) ? FUN_005f2670(((AnimData_9cf*)pkActorVal->GetAnimData())->Animation_GetGroup(4)) : false;
        if (bInAttackAnim5)
        {
            return;
        }

        if (pkActorVal->IsCharacter() && pkActorVal->IsSwimming_005a2030())
        {
            return;
        }

        if (!this->m_04->CombatController_HasLineOfSight())
        {
            return;
        }

        if (!IsTargetInCone(pkActorVal, pkTarget5, 0))
        {
            return;
        }

        iAnimAction4 = pkTarget5->GetAnimAction_008a7570();
        bTargetAttacking4 = pkTarget5->Actor_IsAttacking();
        bTargetMidAttack3 = (iAnimAction4 == 4);
        bTargetPostAttack_2 = (iAnimAction4 == 8 || iAnimAction4 == 10);
        bTargetRecoiling = pkTarget5->GetBlocked();

        iAttack4 = this->CombatProcedureAttackMelee_SelectPowerAttack(afArg1, afArg2, bTargetAttacking4, bTargetMidAttack3, 1);
        if (iAttack4 != 0xff)
        {
            if (this->IsActionAvailable(iAttack4))
            {
                iRandA = DialogueRandom() % 100;
                if (iRandA < this->m_04->GetCurrentCombatStyle()->GetByteAtOffsetAD())
                {
                    fChanceTmp = CalculateWeightedValue((int)this->m_04->GetCurrentCombatStyle(), this->m_04->CombatController_GetAttackSkill(),
                                                        pkActorVal->GetActorValueAsInteger(11), bTargetAttacking4,
                                                        !this->m_04->GetCurrentWeapon(), bTargetPostAttack_2,
                                                        pkTarget5->GetHasKnockedState(), bTargetRecoiling);

                    fPercent4 = CombatFormulas_ChooseBlock((Obj*)this->m_04->GetCurrentCombatStyle(), 50, 50, false, bTargetAttacking4);

                    aFMax = BSMAX_00404010(100.0 - (fChanceTmp + fPercent4), *DAT_011cea38.Setting_Float_00403e20());

                    if (fChanceTmp > fPercent4 && fChanceTmp > aFMax)
                    {
                        if (CombatUtilities_CalculateLOS(pkActorVal, pkTarget5, ((const Actor*)pkActorVal)->GetPos(), ((const Actor*)pkTarget5)->GetPos(), 0, 30))
                        {
                            this->CombatProcedureAttackMelee_StartAttack(iAttack4, 0);
                            this->SetMode(0);
                        }
                        else
                        {
                            helper_.FUN_00435de0(CombatTimer_GetTimer());
                            this->m_timer60 = helper_;
                        }
                    }
                }
            }
        }
    }
}

extern double g_d100;
struct Obj641
{
    float BGSProjectile_GetExplosionTimer();
    float GetField84Float();
    float FUN_0051b8e0();
    float Projectile_GetSpreadLooking();
    float GetFieldEC();
    signed char GetUnk7d();
    float Sky_GetCurrentWeatherPct();
    float TESObjectWEAP_GetSpeed();
    float FUN_006447f0();
};
// Computes a weighted value from object fields scaled by a percent ratio, applying optional additive and multiplicative modifiers.
// @fnv 0x00644680
float __cdecl CalculateWeightedValue(Obj641* object, int percent, int unused, bool useMult, bool useThird,
                                     bool useFirst, bool useSecond, bool useLast)
{
    float value;
    float ratio = (float)(percent / g_d100);
    float modifier1 = useFirst ? object->BGSProjectile_GetExplosionTimer() : 0.0f;
    float second = useSecond ? object->GetField84Float() : 0.0f;
    float third = useThird ? object->FUN_0051b8e0() : 0.0f;
    float weighted = object->Projectile_GetSpreadLooking() + object->GetFieldEC() * ratio;
    value = object->GetUnk7d() + modifier1 + second + third + weighted;
    value *= useMult ? object->Sky_GetCurrentWeatherPct() : object->TESObjectWEAP_GetSpeed();
    value *= useLast ? object->FUN_006447f0() : 1.0f;
    return value;
}

struct xCtx
{
    bool IsBusy();
};
struct xTimerC
{
    int m_ai[2];
    bool CheckTimer();
};
struct xOpts
{
    bool Allows(unsigned short us);
};
struct xMgr
{
    void Notify(xCtx* pCtx, int a, int b, int c);
};
extern Setting xS_eb98;
extern Setting xS_e380;
extern xMgr* xCombatMgr;
unsigned char xLogOn();
void xDebugLog(const char* fmt, ...);
unsigned int xRandom();

class xMelee
{
  public:
    int m_i0;
    xCtx* m_pCtx;
    int m_aiPad[8];
    xTimerC m_kReaction;
    xTimerC m_kDuration;
    int m_aiPad2[11];
    xOpts m_kOpts;
    int GetState();
    void Finish();
    void Advance();
    Actor* GetActor();
    Actor* GetTarget();
    void Prepare();
    void Prepare2();
    int GetSection();
    void SetStage(int i);
    void StartBlock();
    void Stop();
    float GetDistance();
    float GetLimit();
    bool TryMove(float a, float b, int c);
    void Strike();
    void UpdateDodge();
};

// Advances the dodge reaction timer, checks actor readiness and distance, and triggers a block, strike, or combat notification.
// @fnv 0x009cdb00
void xMelee::UpdateDodge()
{
    if (GetState() != 2)
        return;
    if (m_kReaction.CheckTimer())
    {
        Finish();
        Advance();
        return;
    }
    Actor* qfTOqo = GetActor();
    Actor* qpqRa = GetTarget();
    int qSVM = qfTOqo->GetActorStateFlags();
    if (!qfTOqo->IsMoving_004938e0())
    {
        Finish();
        return;
    }
    Prepare();
    Prepare2();
    int qsSDDgz = qpqRa ? qpqRa->GetAnimAction() : -1;
    if (qsSDDgz == 2 && GetSection() == 2)
    {
        SetStage(3);
        StartBlock();
    }
    if (!m_kOpts.Allows((unsigned short)qSVM))
    {
        Stop();
        if (xLogOn())
            xDebugLog("%.20s has run out of room to dodge.", qfTOqo->GetFullName());
        Finish();
        return;
    }
    float qrEZrs = GetDistance();
    float qdqWL = GetLimit();
    if ((qSVM & 4) || (qSVM & 8))
    {
        if (qrEZrs > qdqWL)
        {
            if (TryMove(qrEZrs, qdqWL, 0))
            {
                if (m_kDuration.CheckTimer())
                {
                    Stop();
                    Strike();
                    return;
                }
            }
            else
                qfTOqo->DispatchToTarget(qSVM | 1);
        }
        else if (qrEZrs < *xS_eb98.Float() && (qSVM & 1))
            qfTOqo->DispatchToTarget(qSVM & ~1);
    }
    else if (qSVM & 1)
    {
        if (qrEZrs <= *xS_eb98.Float() && m_kDuration.CheckTimer())
        {
            Stop();
            Finish();
            return;
        }
    }
    if (qsSDDgz == 2)
    {
        float qxQHW = (float)(xRandom() % 100);
        if ((qSVM & 0x100) && !m_pCtx->IsBusy() && qxQHW > *xS_e380.Float())
            qfTOqo->DispatchToTarget((qSVM | 0x200) & ~0x100);
    }
    else if (qSVM & 0x200)
        qfTOqo->DispatchToTarget((qSVM | 0x100) & ~0x200);
    xCombatMgr->Notify(m_pCtx, 2, 0, 0);
}

extern int DAT_011f426c;
extern int DAT_011f4270;
extern int DAT_011f4274;

struct FUN_009cfe90_Vector
{
    int x;
    int y;
    int z;
    float NiPoint3_XYLength();
};



// @fnv 0x009cfe90
// src: COMMUNITY 0x009cfe90
float ProcX::CombatProcedureAttackMelee_GetMovingTargetVelocity()
{
    FUN_009cfe90_Vector value;

    if (reinterpret_cast<CombatAttackHelper*>(this)->GetTarget_00996e00() == 0 ||
        !reinterpret_cast<Actor*>(reinterpret_cast<CombatAttackHelper*>(this)->GetTarget_00996e00())
             ->IsMoving_004938e0())
        return 0.0f;

    value.x = DAT_011f426c;
    value.y = DAT_011f4270;
    value.z = DAT_011f4274;

    reinterpret_cast<Actor*>(reinterpret_cast<CombatAttackHelper*>(this)->GetTarget_00996e00())
        ->Unk_AB(*(NiPoint3*)&value.x);

    return value.NiPoint3_XYLength();
}

namespace fnv_009ce5b0 {
struct Req
{
    int data[43];
    Req();
    ~Req();
};
struct Shape;
struct Avoid
{
    int data[6];
    static void* operator new(unsigned);
    static void operator delete(void*);
    Avoid();
    void AppendNode(Shape const&);
};
struct Ptr
{
    Avoid* p;
    Ptr(Avoid*);
    ~Ptr();
    Avoid* Modelloader_GetReferencedThis();
};
struct Shape
{
    int data[9];
    Shape(int, float, float);
};
extern "C" char DAT_011cf120;
extern "C" char DAT_011cf4e0;
struct Act
{
    float FUN_008be1b0();
    void PathToLocation(Req*, void const*, unsigned, unsigned, float, Avoid*);
    void SetPathingRequestAvoidNodes(Req*);
};
struct Targ : CombatAttackVT
{
    void* TESObjectREFR_GetWorldSpace();
    unsigned FUN_008d6f30();
};
struct Holder
{
    char* CombatController_GetCombatState();
};
unsigned char __cdecl CombatUtilities_CalculateLOS(Act*, Targ*, NiPoint3*, int, int, int);
float __cdecl CombatUtilities_ComputeFaceTargetDistance(Act*, Targ*, float);
struct C009ce5b0
{
    int pad;
    Holder* holder;
    Act* CombatProcedure_GetAttacker();
    Targ* GetTarget_00996e00();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    void CombatProcedureAttackMelee_MoveToFaceTargetLocation(NiPoint3* pos);
};
// Builds a request using an avoidance shape when both checks pass, otherwise builds one from target data.
// @fnv 0x009ce5b0
// src: XBOX_PDB 0x009ce5b0
void C009ce5b0::CombatProcedureAttackMelee_MoveToFaceTargetLocation(NiPoint3* apPosition)
{
    Act* actor2 = CombatProcedure_GetAttacker();
    Targ* target = GetTarget_00996e00();
    Req request;
    PathingLocation location(*(const NiPoint3*)apPosition, (void*)actor2);
    if (location.IsDistanceBelowThreshold(actor2->FUN_008be1b0()) &&
        CombatUtilities_CalculateLOS(actor2, target, apPosition, target->v07d(), 0, 30))
    {
        Ptr avoidX(new Avoid);
        avoidX.Modelloader_GetReferencedThis()->AppendNode(Shape(target->v07d(), *((Setting*)&DAT_011cf4e0)->Setting_Float_00403e20(),
                                                  *((Setting*)&DAT_011cf120)->Setting_Float_00403e20()));
        actor2->PathToLocation(&request, &location.FUN_005c3420(), (unsigned)location.FUN_006dd4f0(), (unsigned)location.FUN_00441110(), 5.0f,
                             avoidX.Modelloader_GetReferencedThis());
    }
    else
    {
        float distance = 10.0f;
        if ((unsigned char)GetByteAtOffset70(holder->CombatController_GetCombatState()))
            distance = CombatUtilities_ComputeFaceTargetDistance(actor2, target, CombatProcedureAttackMelee_GetCurrentAttackReach());
        actor2->PathToLocation(&request, (void*)target->v07d(), target->FUN_008d6f30(), (unsigned)target->TESObjectREFR_GetWorldSpace(),
                             distance, 0);
    }
    actor2->SetPathingRequestAvoidNodes(&request);
}
}  // namespace fnv_009ce5b0

struct FUN_00996de0_ClassQ
{
    Actor* CombatProcedure_GetAttacker();
};
struct FUN_00980070_shellQ
{
    unsigned int GetCurrentCombatStyle();
};

// Returns 1 if a is at least b, otherwise 0, ignoring the c parameter.
// @fnv 0x009cf030
// src: XBOX_PDB 0x009cf030
unsigned char FUN_009cde10_shell::CombatProcedureAttackMelee_OutsideAttackRange(float a, float b, int aiUnused)
{
    Actor* pTarget3;
    bool bFlag;
    float m_fPackageValue;
    unsigned char bResult = 0;

    pTarget3 = ((FUN_00996de0_ClassQ*)this)->CombatProcedure_GetAttacker();
    bFlag = ((CombatNode_combatprocedureattackmelee*)(*(FUN_00980070_shellQ**)((char*)this + 4))->GetCurrentCombatStyle())->GetByteAtOffset8C() >= 100;
    m_fPackageValue = 0.0f;
    if (a >= b + m_fPackageValue)
    {
        bResult = 1;
    }
    return bResult;
}
