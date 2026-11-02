// fallout/ai/combat/combatprocedureattackmelee.cpp: CombatProcedureAttackMelee, This, MeleeProc, CombatAttackHelper and more (57 functions)

#include "combatprocedureattackmelee_timer.h"

// @fnv 0x008d7f80
bool TimeoutTimer::CheckTimer()
{
    return Actor::GetActorScale() - m_fStartTime > m_fTimeout;
}

char __fastcall GetByteAtOffset70(char*);

// @fnv 0x0097f2d0
char __fastcall FUN_0097f2d0(char* this_)
{
    return GetByteAtOffset70(*(char**)(this_ + 0x9c));
}

struct FUN_009cef70_shell
{
    float __thiscall FUN_009cef70(int index);
};

// @fnv 0x009cef70
float __thiscall FUN_009cef70_shell::FUN_009cef70(int index)
{
    return ((float*)this)[index + 0x3f];
}

struct FUN_009cef90_shell
{
    float __thiscall FUN_009cef90(int index);
};

// @fnv 0x009cef90
float __thiscall FUN_009cef90_shell::FUN_009cef90(int index)
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
    void __thiscall FUN_009cf6d0(int arg);
};

// Stores the previous value at offset 0x14 into offset 0x18, then writes arg into offset 0x14.
// @fnv 0x009cf6d0
void __thiscall FUN_009cf6d0_shell::FUN_009cf6d0(int arg)
{
    *(int*)((char*)this + 0x18) = *(int*)((char*)this + 0x14);
    *(int*)((char*)this + 0x14) = arg;
}

struct FUN_009cfc40_shell
{
    void __thiscall FUN_009cfc40(int);
};

// @fnv 0x009cfc40
void __thiscall FUN_009cfc40_shell::FUN_009cfc40(int)
{
    ((unsigned char*)this)[0] = 1;
}

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting592;
extern double g_d100;
struct Obj
{
    char FUN_00644640();
    double GetE0();
    float GetFieldDC();
    float GetFieldE4Float();
    float GetFieldE8Float();
};
// @fnv 0x00644580
float FUN_00644580(Obj* p, int percent, int unused, bool abApplySetting, bool abUseAltValue)
{
    float fPercentScale;
    float fResult;
    fPercentScale = percent / g_d100;
    fResult = p->FUN_00644640() + p->GetE0() + p->GetFieldDC() * fPercentScale;
    fResult = fResult * (abUseAltValue ? p->GetFieldE4Float() : p->GetFieldE8Float());
    return abApplySetting ? fResult
                          : fResult * *originalRuntimeFloatSetting592.Float() * (abUseAltValue ? 1.0f : 0.25f);
}

struct FUN_009cc220
{
    virtual ~FUN_009cc220();
};
void __cdecl _Deallocate(void*);
struct FUN_009cc1f0_shell
{
    void* DestroySelf(unsigned int flags);
};
// @fnv 0x009cc1f0
void* FUN_009cc1f0_shell::DestroySelf(unsigned int flags)
{
    ((FUN_009cc220*)this)->FUN_009cc220::~FUN_009cc220();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_009cc220 {
struct FUN_009ca6c0_shell
{
    virtual ~FUN_009ca6c0_shell();
};
struct FUN_009cc220 : FUN_009ca6c0_shell
{
    virtual ~FUN_009cc220();
};
// @fnv 0x009cc220
FUN_009cc220::~FUN_009cc220()
{}
}  // namespace fnv_009cc220

struct FUN_008b3ab0_shell
{
    void FUN_008b3ab0();
};
struct FUN_00894cc0_shell
{
    bool FUN_00894cc0(bool);
};
struct CombatProcedure
{
    void RunProcedure();
};
struct FUN_009cc4d0_shell : CombatProcedure
{
    Actor* FUN_00996de0();
    void RunCombatProcedure();
};
// Gets the attacker Actor, runs the base procedure, then calls two functions on the attacker with false.
// @fnv 0x009cc4d0
void FUN_009cc4d0_shell::RunCombatProcedure()
{
    Actor* pattacker = FUN_00996de0();
    RunProcedure();
    ((FUN_008b3ab0_shell*)pattacker)->FUN_008b3ab0();
    ((FUN_00894cc0_shell*)pattacker)->FUN_00894cc0(false);
}

struct AnimIdle
{
    int GetSection();
};
struct FUN_008935f0_shell
{
    bool TryAttack(int);
};
struct FUN_009cce70_shell : AnimIdle
{
    Actor* FUN_00996de0();
    void FUN_009cce70(int attack, int arg2);
};
// @fnv 0x009cce70
void FUN_009cce70_shell::FUN_009cce70(int attack, int arg2)
{
    if (attack == 0xff || !GetSection())
        return;
    Actor* pattacker = FUN_00996de0();
    bool queued = ((FUN_008935f0_shell*)pattacker)->TryAttack(attack);
    if (queued)
    {
        ((FUN_009cf6d0_shell*)this)->FUN_009cf6d0(0);
        ((int*)this)[7] = attack;
    }
}

namespace fnv_009cd3d0 {
struct AnimIdle
{
    int GetSection();
};
struct FUN_009cd3d0_shell : AnimIdle
{
    void FUN_009cd3d0();
};
// If GetSection() returns 2 and the timer at offset 0x20 has elapsed, calls FUN_009cf6d0 with 3.
// @fnv 0x009cd3d0
void FUN_009cd3d0_shell::FUN_009cd3d0()
{
    if (GetSection() != 2)
        return;
    if (((TimeoutTimer*)((char*)this + 0x20))->CheckTimer())
        ((FUN_009cf6d0_shell*)this)->FUN_009cf6d0(3);
}
}  // namespace fnv_009cd3d0

struct FUN_009cd410_shell
{
    void SetMode(int);
    void FUN_009cd410();
};
// @fnv 0x009cd410
void FUN_009cd410_shell::FUN_009cd410()
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

struct FUN_00894900_shell
{
    bool FUN_00894900();
};
struct CombatTargetTimestamp
{
    float GetElapsedTime();
};
extern double DAT_01011588;
struct FUN_009cde10_shell
{
    int GetAudioBackendData();
    int GetSection();
    FUN_00894900_shell* FUN_00996e00();
    void FUN_009cd410();
    void EvaluateReaction();
    float FUN_009ce560();
    unsigned char FUN_009cf030(float, float, int);
    void UpdateState();
    float GetModifierValue();
    void FUN_009cde10();
};
// @fnv 0x009cde10
void FUN_009cde10_shell::FUN_009cde10()
{
    FUN_00894900_shell* ptarget;
    if (GetAudioBackendData() != 1)
        return;
    ptarget = FUN_00996e00();
    if (((TimeoutTimer*)((char*)this + 0x28))->CheckTimer())
    {
        FUN_009cd410();
        return;
    }
    if (((CombatTargetTimestamp*)((char*)this + 0x28))->GetElapsedTime() > DAT_01011588)
    {
        float freach;
        float fdistance;
        fdistance = GetModifierValue();
        freach = FUN_009ce560();
        if (FUN_009cf030(fdistance, freach, 0))
        {
            FUN_009cd410();
            return;
        }
    }
    if ((ptarget && ptarget->FUN_00894900()) || *((unsigned char*)this + 0x50))
    {
        if (GetSection() == 2)
        {
            ((FUN_009cf6d0_shell*)this)->FUN_009cf6d0(3);
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
    void FUN_00996e20(int);
    void UpdateMeleeCombat();
    void SetMode(int);
    void FUN_009ce190();
};
// Calls SetMode(4), FUN_00996e20(3), FUN_008d7f40(3.0f) on the object at offset 0x28, then UpdateMeleeCombat.
// @fnv 0x009ce190
void FUN_009ce190_shell::FUN_009ce190()
{
    SetMode(4);
    FUN_00996e20(3);
    ((FUN_008d7f40_shell*)((char*)this + 0x28))->FUN_008d7f40(3.0f);
    UpdateMeleeCombat();
}

extern double _gModifierZero;
int __fastcall FUN_007031c0(int);
float __cdecl GetActorReach(Actor*, int);
struct FUN_009ce560_shell
{
    Actor* FUN_00996de0();
    float FUN_009ce560();
};
// Returns the cached modifier value, recomputing it from the attacker and the value at offset 4 when it is below _gModifierZero.
// @fnv 0x009ce560
float FUN_009ce560_shell::FUN_009ce560()
{
    Actor* pattacker = FUN_00996de0();
    if (((float*)this)[0x16] < _gModifierZero)
        ((float*)this)[0x16] = GetActorReach(pattacker, FUN_007031c0(((int*)this)[1]));
    return ((float*)this)[0x16];
}

struct FUN_009cefb0_shell
{
    char FUN_009cefb0();
};
// @fnv 0x009cefb0
char FUN_009cefb0_shell::FUN_009cefb0()
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
    void FUN_009cfc00();
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
        FUN_009cfc00();
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
    char FUN_009cfbd0(unsigned short mask);
};
// Forwards the mask to the HasNoFlag method of the object at offset 0x64 and returns its result.
// @fnv 0x009cfbd0
char FUN_009cfbd0_shell::FUN_009cfbd0(unsigned short mask)
{
    char result = 1;
    result = ((FUN_009cdde0_shell*)((char*)this + 0x64))->HasNoFlag(mask);
    return result;
}
}  // namespace fnv_009cfbd0

struct FUN_008b3bd0_shell
{
    unsigned char FUN_008b3bd0();
};
struct FUN_009cfc00_shell
{
    Actor* FUN_00996de0();
    void FUN_009cfc00();
};
// Gets the attacker via FUN_00996de0 and, if FUN_008b3bd0 returns false, calls FUN_009cfc40(1) on the object at this+0x64.
// @fnv 0x009cfc00
void FUN_009cfc00_shell::FUN_009cfc00()
{
    Actor* pattacker = FUN_00996de0();
    if (!((FUN_008b3bd0_shell*)pattacker)->FUN_008b3bd0())
        ((FUN_009cfc40_shell*)((char*)this + 0x64))->FUN_009cfc40(1);
}

namespace fnv_009cfc60 {
struct FUN_008b3a50_shell
{
    void FUN_008b3a50();
};
struct FUN_008b3ab0_shell
{
    void FUN_008b3ab0();
};
struct FUN_009cfc60_shell
{
    Actor* FUN_00996de0();
    void StopIfSpeakerOutOfRange();
    void FUN_009cfc60();
};
// Gets an Actor via FUN_00996de0, calls FUN_008b3a50 and FUN_008b3ab0 on it, then calls StopIfSpeakerOutOfRange.
// @fnv 0x009cfc60
void FUN_009cfc60_shell::FUN_009cfc60()
{
    Actor* pattacker = FUN_00996de0();
    ((FUN_008b3a50_shell*)pattacker)->FUN_008b3a50();
    ((FUN_008b3ab0_shell*)pattacker)->FUN_008b3ab0();
    StopIfSpeakerOutOfRange();
}
}  // namespace fnv_009cfc60

extern double _gModifierZero;
float __cdecl FUN_009a64d0(Actor*, Actor*, int);
struct FUN_009cfd20_shell
{
    Actor* FUN_00996de0();
    Actor* FUN_00996e00();
    float GetModifierValue();
};
// @fnv 0x009cfd20
float FUN_009cfd20_shell::GetModifierValue()
{
    if (((float*)this)[0x17] < _gModifierZero)
        ((float*)this)[0x17] = FUN_009a64d0(FUN_00996de0(), FUN_00996e00(), 0);
    return ((float*)this)[0x17];
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};
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
    v = _NiPoint3_ZERO;
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
struct TESObjectREFR;
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct PathingLocation
{
    int a, b, c, d, e, f, g, h, i, j;
    PathingLocation(TESObjectREFR*);
    ~PathingLocation();
};
struct Pathing
{
    static bool __cdecl FindPathingLocation(PathingLocation&, const NiPoint3&, PathingLocation*, void*);
};
struct FUN_009d0590_shell
{
    bool FUN_009d0590(TESObjectREFR* ref, const NiPoint3* pt);
};
// @fnv 0x009d0590
bool FUN_009d0590_shell::FUN_009d0590(TESObjectREFR* ref, const NiPoint3* pt)
{
    PathingLocation loc(ref);
    return Pathing::FindPathingLocation(loc, *pt, 0, 0);
}
}  // namespace fnv_009d0590

namespace fnv_009d0610 {
struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};
struct Setting_S
{
    float* Float();
};
extern Setting_S g_011cee60;
struct FUN_008d7f40_shell
{
    void __thiscall FUN_008d7f40(float);
};
struct FUN_009d0610_shell
{
    bool active;
    unsigned int elapsed;
    unsigned int __thiscall UpdateDirection(unsigned int, unsigned int);
    void FUN_009d0610(TESAmmoInitCalls* src);
};
// @fnv 0x009d0610
void FUN_009d0610_shell::FUN_009d0610(TESAmmoInitCalls* pAmmoInitCalls)
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
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer*);
};
struct CombatTargetTimestamp
{
    void SaveTimeStamp(BGSSaveFormBuffer*);
};
struct FUN_009d0690_shell
{
    void SaveGame(BGSSaveFormBuffer*);
    void FUN_009d0690(BGSSaveFormBuffer* buf);
};
// @fnv 0x009d0690
void FUN_009d0690_shell::FUN_009d0690(BGSSaveFormBuffer* buf)
{
    SaveGame(buf);
    buf->SaveData((char*)this + 0x10, 4, 0);
    buf->SaveData((char*)this + 0x14, 4, 0);
    buf->SaveData((char*)this + 0x18, 4, 0);
    buf->SaveData((char*)this + 0x1c, 4, 0);
    ((FUN_009a5eb0_shell*)((char*)this + 0x20))->FUN_009a5eb0(buf);
    ((FUN_009a5eb0_shell*)((char*)this + 0x28))->FUN_009a5eb0(buf);
    ((FUN_009a5eb0_shell*)((char*)this + 0x30))->FUN_009a5eb0(buf);
    ((FUN_009a5eb0_shell*)((char*)this + 0x38))->FUN_009a5eb0(buf);
    ((FUN_009a5eb0_shell*)((char*)this + 0x40))->FUN_009a5eb0(buf);
    ((FUN_009a5eb0_shell*)((char*)this + 0x48))->FUN_009a5eb0(buf);
    ((CombatTargetTimestamp*)((char*)this + 0x60))->SaveTimeStamp(buf);
    buf->SaveData((char*)this + 0x50, 1, 0);
    buf->SaveData((char*)this + 0x54, 4, 0);
}
}  // namespace fnv_009d0690

namespace fnv_009d0790 {
struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    void ReadTypedData(void*, unsigned int);
};
struct FUN_009a5e_timer
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct CombatTargetTimestamp
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct FUN_009d0790_shell
{
    void LoadGameBase(BGSLoadFormBuffer*);
    void FUN_009d0790(BGSLoadFormBuffer* buf);
};
// Loads the base form data, four 4-byte fields, six timers, a version-gated object, then a 1-byte and a 4-byte field from the buffer.
// @fnv 0x009d0790
void FUN_009d0790_shell::FUN_009d0790(BGSLoadFormBuffer* apBuffer)
{
    LoadGameBase(apBuffer);
    apBuffer->ReadTypedData((char*)this + 0x10, 4);
    apBuffer->ReadTypedData((char*)this + 0x14, 4);
    apBuffer->ReadTypedData((char*)this + 0x18, 4);
    apBuffer->ReadTypedData((char*)this + 0x1c, 4);
    ((FUN_009a5e_timer*)((char*)this + 0x20))->LoadGame(apBuffer);
    ((FUN_009a5e_timer*)((char*)this + 0x28))->LoadGame(apBuffer);
    ((FUN_009a5e_timer*)((char*)this + 0x30))->LoadGame(apBuffer);
    ((FUN_009a5e_timer*)((char*)this + 0x38))->LoadGame(apBuffer);
    ((FUN_009a5e_timer*)((char*)this + 0x40))->LoadGame(apBuffer);
    ((FUN_009a5e_timer*)((char*)this + 0x48))->LoadGame(apBuffer);
    if (apBuffer->GetVersion() >= 0x12)
        ((CombatTargetTimestamp*)((char*)this + 0x60))->LoadGame(apBuffer);
    apBuffer->ReadTypedData((char*)this + 0x50, 1);
    apBuffer->ReadTypedData((char*)this + 0x54, 4);
}
}  // namespace fnv_009d0790

struct FUN_00996de0_Class
{
    unsigned int FUN_00996de0();
};
struct FUN_00980070_shell
{
    unsigned int FUN_00980070();
};
struct FUN_005524b0_class
{
    char GetByteAtOffset8C();
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
    unsigned int pTarget3 = ((FUN_00996de0_Class*)this)->FUN_00996de0();
    bool bFlag = ((FUN_005524b0_class*)this->m_04->FUN_00980070())->GetByteAtOffset8C() >= 100;
    float fElapsed3 = 0.0f;
    if (afValue <= afLimit + fElapsed3)
    {
        bResult = 1;
    }
    return bResult;
}

struct AnimDataV
{
    char FUN_00495e40();
    char FUN_00495f50(int, int);
    int GetSlotValue();
};
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
struct MobileObject
{
    bool FUN_005a2030() const;
};
struct FatigueProxy
{
    float GetFatiguePercentage();
};
struct FUN_00996e00_shell
{
    void* FUN_00996e00();
};
struct S009cefd0
{
    bool IsWithinThreshold(float, float, int);
};
struct S009ce870
{
    int FUN_009ce870(float, float, bool, bool, int);
};
struct BSAudio
{
    void* GetAudioBackendData();
};
unsigned int __cdecl DialogueRandom();
bool CheckChanceSuccess(unsigned int, float, bool, bool, int);
extern Setting_S originalRuntimeFloatSetting597;
extern int DAT_011a8244;
struct CombatProcedureAttackMelee
{
    int m_00;
    FUN_00980070_shell* m_04;
    int FUN_009ccb20(bool abMidAttack, float afDistance, float afReach, bool abTargetAttacking, bool abTargetPostAttack,
                     bool abTargetRecoiling, bool* abDoPowerAttack, bool* abSwitchAttack);
};

// Chooses a melee attack id from distance, reach, power-attack and animation state, setting the power-attack and switch-attack flags.
// @fnv 0x009ccb20
int CombatProcedureAttackMelee::FUN_009ccb20(bool abMidAttack, float afDistance, float afReach, bool abTargetAttacking,
                                             bool abTargetPostAttack, bool abTargetRecoiling, bool* abDoPowerAttack,
                                             bool* abSwitchAttack)
{
    TESObjectWEAP* pweapon;
    bool bwithinNormalReach;
    ActorV* ptarget;
    int iAttack;
    ActorV* pattacker;

    pattacker = (ActorV*)((FUN_00996de0_Class*)this)->FUN_00996de0();
    ptarget = (ActorV*)((FUN_00996e00_shell*)this)->FUN_00996e00();
    *abSwitchAttack = false;
    iAttack = 0xff;
    pweapon = (TESObjectWEAP*)FUN_007031c0((int)m_04);
    if (!ptarget)
        return iAttack;
    if (pattacker->V218() && ((MobileObject*)pattacker)->FUN_005a2030())
        *abDoPowerAttack = false;
    else
        *abDoPowerAttack = CheckChanceSuccess(m_04->FUN_00980070(), ((FatigueProxy*)pattacker)->GetFatiguePercentage(),
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
            iAttack = ((S009ce870*)this)->FUN_009ce870(afDistance, afReach, abTargetAttacking, abTargetPostAttack, 0);
        if (iAttack == 0xff && bwithinNormalReach)
        {
            iAttack = pweapon ? ((FUN_0051f5f0_shell*)pweapon)->GetByteAt11D() : 0xff;
            if (iAttack == 0xff)
            {
                if (pattacker->GetAnimData(1)->FUN_00495f50(DAT_011a8244, 0) == 'l')
                    iAttack = 0x1a;
                else
                    iAttack = 0x20;
            }
        }
    }
    else if (pattacker->GetAnimData(4)->GetSlotValue() == 3)
    {
        if (*abDoPowerAttack)
            iAttack = ((S009ce870*)this)->FUN_009ce870(afDistance, afReach, abTargetAttacking, abTargetPostAttack, 0);
        if (iAttack == 0xff && bwithinNormalReach)
        {
            switch (((ActorV*)((FUN_00996de0_Class*)this)->FUN_00996de0())->GetAnimData(0)->FUN_00495e40())
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

struct FUN_008b3a20_shell
{
    int unk000, unk004, unk008, unk00C;
    int unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C;
    int unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C;
    int unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC;
    int unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC;
    int unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C;
    int unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C;
    int unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C;
    int unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C;
    TargetInterface* unk190;

    void DispatchToTarget(int arg);
};

// Forwards the argument to the virtual v0c method of the object stored at unk190.
// @fnv 0x008b3a20
void FUN_008b3a20_shell::DispatchToTarget(int aiValue)
{
    unk190->v0c(aiValue);
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
struct ActorA
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
    virtual AnimData* GetAnimData121();
    bool FUN_00894cc0(bool);
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    SubA4 m_a4;
};
struct ActorB
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
    virtual int V116();
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
    virtual bool V140();
    virtual bool V141();
    bool FUN_00894900();
    bool FUN_00493bb0();
    bool FUN_00894d60();
    void* FUN_008a1710();
    bool FUN_00437bd0();
    bool FUN_00579670();
    bool FUN_00437bf0();
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
    unsigned short FUN_004301b0(int);
    int GetSlotValue(int);
    bool FUN_00494710(unsigned short);
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
    void* FUN_00980070();
    int FUN_0097fc70();
    Mid1 FUN_00586150();
};
struct SettingObj
{
    float* FUN_00403e20();
};
extern SettingObj DAT_011cea38;
extern ActorB* DAT_011dea3c;
struct GlobalObj
{
    void FUN_00983970(void*, int, int, int);
};
extern GlobalObj* DAT_011f1708;
int __fastcall FUN_008a7570(void*);
bool __fastcall FUN_0097f2d0(void*);
bool __fastcall FUN_008a16d0(void*);
bool __fastcall FUN_004c0c30(void*);
Proc* __fastcall FUN_008d8520(void*);
int __fastcall FUN_007031c0(int);
bool __cdecl FUN_005f2540(int);
float __cdecl CalculateWeightedValue(int, int, int, bool, bool, bool, bool, bool);
float __cdecl FUN_00644580(void*, int, int, bool, bool);
float __cdecl FUN_00404010(float, float);
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
    ActorA* FUN_00996de0();
    ActorB* FUN_00996e00();
    int FUN_00825c00();
    float GetModifierValue();
    float FUN_009ce560();
    bool IsWithinThreshold(float, float, int);
    void FUN_009cf6d0(int);
    int FUN_0044edb0();
    int FUN_009ccb20(bool, float, float, bool, bool, bool, bool*, bool*);
    void FUN_009cce70(int, int);
    void FUN_009cc510();
};
// @fnv 0x009cc510
void This::FUN_009cc510()
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
    ActorB* t45;
    bool t57;
    bool s5;
    float s12;
    bool s20;
    int s23;
    bool s33;
    bool s44;
    AnimData* s56;
    bool r14;
    ActorA* r23;
    bool r39;
    r23 = FUN_00996de0();
    t45 = FUN_00996e00();
    if (FUN_00825c00() != 3 || t45 == 0)
        return;
    if (m_04->FUN_00981970())
        return;
    m_1c = 0xff;
    s12 = GetModifierValue();
    v51 = FUN_009ce560();
    s56 = r23->GetAnimData121();
    t43 = FUN_008a7570(r23);
    s23 = FUN_008a7570(t45);
    t57 = FUN_005f2540(s56->FUN_004301b0(4));
    t5 = s56->GetSlotValue(4) == 3;
    r39 = t43 == 4;
    t19 = t43 == 8 || t43 == 10;
    s33 = t45->FUN_00894900();
    s20 = s23 == 4;
    s5 = s23 == 8 || s23 == 10;
    s44 = t45->FUN_00493bb0();
    r14 = t45->FUN_00894d60();
    if (IsWithinThreshold(s12, v51, 0))
    {
        n44 = 0.0f;
        n44 = CalculateWeightedValue((int)m_04->FUN_00980070(), m_04->FUN_0097fc70(), r23->m_a4.FUN_0066ef20(11), s33,
                                     FUN_007031c0((int)m_04) == 0, s5, t45->V140(), r14);
        if (m_04->FUN_00586150().GetHandle()->FUN_00435e00() > 5.0 && n44 != 0.0)
            n44 += 100.0;
        if (!s44 && t45 != DAT_011dea3c)
            n44 += 100.0;
        m2 = FUN_00644580(m_04->FUN_00980070(), 50, 50, false, s33);
        v29 = t45->V141() || t45->V140() || t45->FUN_00437bd0() || t45->FUN_00579670() || t45->FUN_00437bf0();
        m33 = t45->FUN_008a1710();
        if (v29 || !FUN_008a16d0(t45) || (m33 != 0 && FUN_004c0c30(m33)))
            m2 = 0.0f;
        v30 = (t57 && n44 > 0.0f) ? true : FUN_008d8520(FUN_00996de0())->V254();
        if (!v30 || !FUN_0097f2d0(m_04))
        {
            n44 = 0.0f;
            if (!FUN_0097f2d0(m_04))
                m2 = 0.0f;
        }
        if ((t57 && !t5) || FUN_0044edb0() == 4 || t19)
            m2 = 0.0f;
        if (!s56->FUN_00494710(0xaa))
            m2 = 0.0f;
        n45 = FUN_00404010((float)(100.0 - (n44 + m2)), *DAT_011cea38.FUN_00403e20());
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
                r23->FUN_00894cc0(false);
                if (FUN_00825c00() == 1)
                    FUN_009cf6d0(3);
            }
            bool found = false;
            bool bp2 = false;
            int res = FUN_009ccb20(t57, s12, v51, s33, s20, s5, &found, &bp2);
            if (res != 0xff)
            {
                if (FUN_00996e00()->V116() != 0)
                {
                    if (found)
                    {
                        DAT_011f1708->FUN_00983970(m_04, 2, 1, 0);
                    }
                    else
                    {
                        DAT_011f1708->FUN_00983970(m_04, 2, 0, 0);
                    }
                    FUN_009cce70(res, bp2);
                }
            }
        }
        else if (m2 > 0.0f && (n44 + m2) > m48)
        {
            r23->FUN_00894cc0(true);
            FUN_009cf6d0(1);
        }
        else
        {
            if (m_18 != 2)
            {
                FUN_009cf6d0(2);
                float f60 = FUN_006465f0(((Mid3*)m_04->FUN_00980070())->FUN_004565f0(),
                                         ((Mid3*)m_04->FUN_00980070())->GetUnka4());
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
    Actor* FUN_00996de0();
    void* FUN_00996e00();
    void FUN_009cf6d0(int arg);
    void FUN_009cc510();
    void FUN_009cced0();
};

unsigned short __fastcall FUN_004301b0(AnimDataV* p);
unsigned char __cdecl FUN_005f2540(int v);
unsigned char __cdecl FUN_005f25d0(unsigned int v);

// @fnv 0x009cced0
void FUN_009cced0_cls::FUN_009cced0()
{
    if (FUN_00825c00())
    {
        return;
    }
    Actor* a = FUN_00996de0();
    void* b = FUN_00996e00();
    unsigned char r_2 = FUN_005f2540(FUN_004301b0(((ActorV*)a)->GetAnimData(4)));
    if (r_2)
    {
        if (((ActorV*)a)->GetAnimData(4)->GetSlotValue() == 3)
        {
            FUN_009cf6d0(3);
            FUN_009cc510();
        }
        int pResult = FUN_007031c0(m_04);
        if (pResult != 0)
        {
            if (FUN_005f25d0(reinterpret_cast<FUN_0051f5f0_shell*>(pResult)->GetByteAt11D()))
            {
                reinterpret_cast<FUN_008935f0_shell*>(a)->TryAttack(
                    reinterpret_cast<FUN_0051f5f0_shell*>(pResult)->GetByteAt11D());
            }
        }
    }
    else
    {
        FUN_009cf6d0(3);
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
struct MeleeActor
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
    virtual AnimDataM* GetAnimDataM();
    bool IsReady();
    bool SetFlag(bool b);
    ProcessM* GetProcessM();
};
struct MeleeTarget
{
    int GetAnimActionM();
};
struct MeleeProc
{
    int GetModeM();
    MeleeActor* GetActorM();
    MeleeTarget* GetTargetM();
    void SetStateM(int state);
    void FinishM();
    void ContinueM();
    void FUN_009ccfb0();
};
extern double _gModifierZero;

// In mode 1, checks the actor's readiness, timer value and attack state, and either sets state 3, finishes, or continues the melee procedure.
// @fnv 0x009ccfb0
void MeleeProc::FUN_009ccfb0()
{
    if (GetModeM() != 1)
        return;
    MeleeActor* actor = GetActorM();
    MeleeTarget* target8 = GetTargetM();
    if (!actor->IsReady())
        SetStateM(3);
    TimerObj* timer5 = actor->GetProcessM()->GetTimer();
    if (timer5)
    {
        bool bAttacking4 = false;
        if (GetActorM()->GetAnimDataM() && GetActorM()->GetAnimDataM()->GetControllerSequence(2) &&
            GetActorM()->GetAnimDataM()->GetControllerSequence(2)->GetState() != 1)
            bAttacking4 = true;
        float fTime = timer5->GetValue(0);
        if (fTime <= _gModifierZero && !bAttacking4)
        {
            actor->SetFlag(false);
            SetStateM(3);
        }
        else
        {
            bool bTargetAttack2 = target8 ? target8->GetAnimActionM() == 8 : 0;
            if (bTargetAttack2 && !bAttacking4)
            {
                actor->SetFlag(false);
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

struct AnimData9cd430
{
    unsigned short FUN_004301b0();
};

struct Actor9cd430
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
    virtual AnimData9cd430* GetAnimData(int);
};

struct Controller9cd430
{
    bool FUN_0097f2d0();
    bool GetModifierKey();
};

struct FloatSetting9cd430
{
    float* Float();
};
extern FloatSetting9cd430 originalRuntimeFloatSetting593;

bool __cdecl IsTargetInCone(Actor9cd430*, void*, int);
bool __cdecl FUN_005f2670(unsigned int);

struct CombatProc9cd430
{
    int m_00;
    Controller9cd430* m_04;

    int Check44edb0();
    Actor9cd430* GetActor();
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
    void FUN_009cd430();
};

// Chooses a combat action from range, controller state and target checks, calling Do9ce190, Do9cd150, Do9cdf00 or Do9cd5e0.
// @fnv 0x009cd430
void CombatProc9cd430::FUN_009cd430()
{
    if (Check44edb0())
        return;
    Actor9cd430* actor = GetActor();
    void* target = GetTarget();
    float distance = GetF1();
    float reachDist = GetF2();
    float m_fGlyphExtent = 0.0f;
    float fImpulseRadiusSquared = 0.0f;
    bool inRange = Test9cefd0(distance, reachDist, 0);
    if (inRange && !m_04->FUN_0097f2d0() && IsTargetInCone(actor, target, 0))
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
        bool ok = FUN_005f2670(actor->GetAnimData(4)->FUN_004301b0());
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
void __cdecl FUN_009a68b0(CombatVec3* out, void* a, CombatAttackVT* b, int c, float f);

class CombatAttackHelper
{
  public:
    void* FUN_00996de0();
    CombatAttackVT* FUN_00996e00();
    void FUN_00996e20(int);
    void SetMode(int mode);
    float FUN_009ce560();
    void FUN_009ce5b0(CombatVec3* out);
    void UpdateCombatMovement();
    void FUN_009cdf00();
};

// @fnv 0x009cdf00
void CombatAttackHelper::FUN_009cdf00()
{
    void* a;
    CombatAttackVT* b;
    CombatVec3 out4;
    SetMode(3);
    a = FUN_00996de0();
    b = FUN_00996e00();
    FUN_00996e20(1);
    FUN_009a68b0(&out4, a, b, b->v07d(), FUN_009ce560());
    FUN_009ce5b0(&out4);
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
void* __cdecl FUN_00403d30(void*, int, unsigned int);
float __cdecl FUN_00404010(float, float);
unsigned int __cdecl FUN_00944460(unsigned int, unsigned int);
void __cdecl FUN_005b5e40(const char*, ...);
bool __cdecl FUN_005b6f70();
void __cdecl FUN_00703c00(const char*, ...);

extern double DAT_01012060;
extern double DAT_01012070;
extern double DAT_01090d68;
extern double DAT_01021798;
extern int DAT_011a5ac8[];

struct SettingX
{
    float* FUN_00403e20();
};
extern SettingX DAT_011ceb98;

struct WeapObj
{
    float FUN_00508070();
};

struct AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int);
};

struct ActorX
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
    virtual WeapObj* GetLoadedForm();
    char pad04[0xa0];
    AVOwner avOwner;
    const char* FUN_0055d520();
    int FUN_0084e3a0();
    unsigned short GetVtbl20Result();
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
    AttackData* FUN_00980070();
    bool FUN_00981970();
    bool FUN_009cefb0();
    void UpdateActorValues();
    bool FUN_008d8220();
    float FUN_009cef70(int);
    float FUN_009cef90(int);
    bool FUN_009800e0(int, AttackInfo*);
};

struct ProcX
{
    int m_00;
    CombatCtrl* m_04;
    ActorX* FUN_00996de0();
    bool IsWithinThreshold(float, float, int);
    float FUN_009cfe90();
};

// Chooses a melee attack id from five candidates based on distance, reach, weapon speed and actor state, then logs the selection.
// @fnv 0x009ce870
int S009ce870::FUN_009ce870(float afDistance, float afReach, bool, bool, int)
{
    bool bSelected9 = false;
    bool unk3a5 = false;
    int iResult = 0xff;
    int iAttack5 = 0xff;
    int count = 0;
    bool abAllowedA[5];
    FUN_00403d30(abAllowedA, 0, 5);
    ActorX* pActorF = ((ProcX*)this)->FUN_00996de0();
    AttackData* pDataVal = ((ProcX*)this)->m_04->FUN_00980070();
    if (((ProcX*)this)->m_04->FUN_00981970())
        return 0xff;
    if (!((ProcX*)this)->m_04->FUN_009cefb0())
        ((ProcX*)this)->m_04->UpdateActorValues();
    bool bPower7 = ((ProcX*)this)->m_04->FUN_008d8220() && !((ProcX*)this)->IsWithinThreshold(afDistance, afReach, 0);
    float fMultX = bPower7 ? pDataVal->GetFloatAtOffsetB0() : 1.0f;
    WeapObj* pWeap4 = pActorF->GetLoadedForm();
    float fSpeed7 = pWeap4->FUN_00508070();
    if (fSpeed7 <= DAT_01012060)
        fSpeed7 = 1.0f;
    float fRateB = ((ProcX*)this)->FUN_009cfe90();
    float fReach5 = afReach * fMultX;
    bool bAny6 =
        pActorF->avOwner.GetActorValue(0x1d) > DAT_01012060 && pActorF->avOwner.GetActorValue(0x1e) > DAT_01012060;
    int aiAttacks[5];
    for (int i = 0; i < 5; i++)
    {
        float fMin = ((ProcX*)this)->m_04->FUN_009cef70(i);
        if (fMin > DAT_01012070 && !bAny6)
            continue;
        float fScaledValue = FUN_00404010((float)(fMin * fMultX), fReach5);
        float fTime = ((ProcX*)this)->m_04->FUN_009cef90(i);
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
            if (abAllowedA[2] && afDistance < *DAT_011ceb98.FUN_00403e20())
            {
                k = 2;
            }
            else if (abAllowedA[1] && afDistance > afReach * DAT_01021798)
            {
                k = 1;
            }
            else
            {
                unsigned short usMove = pActorF->GetVtbl20Result();
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
    if (!((ProcX*)this)->m_04->FUN_009800e0(iAttack5, &info7))
        FUN_005b5e40("Melee Attacker %s (%0X) is using %d attack for power attack\n", pActorF->FUN_0055d520(),
                     pActorF->FUN_0084e3a0(), iAttack5);
    iResult = iAttack5;
    bSelected9 = true;
    if (FUN_005b6f70() && bSelected9)
    {
        FUN_00703c00("%.20s selects %s power attack!", pActorF->FUN_0055d520(),
                     iResult == 0x5c   ? "NORMAL"
                     : iResult == 0x5d ? "FORWARD"
                     : iResult == 0x5e ? "BACKWARD"
                     : iResult == 0x5f ? "LEFT"
                     : iResult == 0x60 ? "RIGHT"
                                       : "NO");
    }
    return iResult;
}

struct CombatNode
{
    signed char GetByteAtOffset8C();
    bool HasCombatFlag(int);
    signed char FUN_0073cb80();
    signed char FUN_00505c00();
    signed char GetByteAtOffset9A();
    signed char GetByteAtOffset9B();
    signed char FUN_009e8670();
};
struct CombatContext
{
    CombatNode* FUN_00980070();
};
extern double DAT_01012060;
struct MeleeProcedure
{
    int unk00;
    CombatContext* context;
    Actor* FUN_00996de0();
    bool IsActionAvailable(unsigned);
};
// Returns true if the combat node's value exceeds DAT_01012060 and, when flag 1 is set, the per-action check for action 92-96 is positive.
// @fnv 0x009cf420
bool MeleeProcedure::IsActionAvailable(unsigned action)
{
    Actor* actor = FUN_00996de0();
    bool result = false;
    if (context->FUN_00980070()->GetByteAtOffset8C() > DAT_01012060)
    {
        result = true;
        if (context->FUN_00980070()->HasCombatFlag(1))
        {
            switch (action)
            {
            case 92:
                result = context->FUN_00980070()->FUN_0073cb80() > 0;
                break;
            case 93:
                result = context->FUN_00980070()->FUN_00505c00() > 0;
                break;
            case 94:
                result = context->FUN_00980070()->GetByteAtOffset9A() > 0;
                break;
            case 95:
                result = context->FUN_00980070()->GetByteAtOffset9B() > 0;
                break;
            case 96:
                result = context->FUN_00980070()->FUN_009e8670() > 0;
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
struct Actor
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
    virtual Animation* GetAnimation();
    int FUN_008a7570();
    float GetFatigueRatio();
    float FUN_00884dc0();
    bool FUN_00493bb0();
    bool FUN_005a2030();
    unsigned short FUN_00897910(int, int, int, int);
    float FUN_00897b50(int);
    void DispatchToTarget(int);
    const char* FUN_0055d520();
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
    Config* FUN_00980070();
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
struct Setting
{
    const float* FUN_00403e20();
};
extern Setting DAT_011ce380;
extern const double DAT_01012060, DAT_0104f2f0, DAT_01020758, DAT_01017a40;
extern const char DAT_01090cb8[], DAT_01090cb0[], DAT_01090ca4[], DAT_01090c9c[], DAT_01090c60[];
bool FUN_009a96c0(Actor*);
float FUN_00644990(Config*, int, float, bool);
unsigned int FUN_00487f50();
unsigned short FUN_00644a70(Config*, bool, bool, float, float, bool, bool, unsigned short);
float FUN_006465f0(float, float);
int FUN_005f2440(unsigned short);
double FUN_00404010(float, float);
bool FUN_005b6f70();
void FUN_00703c00(const char*, ...);
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
    Actor* FUN_00996de0();
    Actor* FUN_00996e00();
    int FUN_00825c00();
    float GetModifierValue();
    float FUN_009ce560();
    bool FUN_009cfbd0(int);
    void SetMode(int);
    int FUN_0044edb0();
    void FUN_009cfc60();
    void EvaluateReaction();
};
// @fnv 0x009cd5e0
void Procedure::EvaluateReaction()
{
    Actor* actor2 = FUN_00996de0();
    Actor* target = FUN_00996e00();
    if (!target)
        return;
    bool targetState3 = target->FUN_008a7570() == 2;
    bool targetCondition3 = FUN_009a96c0(target);
    float chance =
        FUN_00644990(owner->FUN_00980070(), (int)actor2->FUN_00884dc0(), actor2->GetFatigueRatio(), targetState3);
    if (chance < DAT_01012060)
        chance = 0.0f;
    if (special)
        chance += DAT_0104f2f0;
    if (FUN_00825c00() == 2)
        chance += DAT_01020758;
    if (target != DAT_011dea3c && !target->FUN_00493bb0())
        chance -= DAT_01017a40;
    if (actor2->FUN_005a2030())
        chance = 0.0f;
    float roll = (float)(FUN_00487f50() % 100);
    if (roll <= chance)
    {
        bool actorState = actor2->FUN_008a7570() == 2;
        float first2 = GetModifierValue();
        float second7 = FUN_009ce560();
        unsigned short action = FUN_00644a70(owner->FUN_00980070(), actorState, targetState3, first2, second7, special,
                                             targetCondition3, options.FUN_004a8ae0());
        if (action)
        {
            Animation* animation = FUN_00996de0()->GetAnimation();
            if (animation)
            {
                int state = 3;
                bool allowed = true;
                float duration3 = 0.0f;
                switch (action & 15)
                {
                case 4:
                    state = 5;
                    allowed = FUN_009cfbd0(4);
                    duration3 =
                        FUN_006465f0(owner->FUN_00980070()->FUN_00639b20(), owner->FUN_00980070()->GetField60Float());
                    break;
                case 8:
                    state = 6;
                    allowed = FUN_009cfbd0(8);
                    duration3 =
                        FUN_006465f0(owner->FUN_00980070()->FUN_00639b20(), owner->FUN_00980070()->GetField60Float());
                    break;
                case 2:
                    state = 4;
                    duration3 =
                        FUN_006465f0(owner->FUN_00980070()->FUN_009a7c40(), owner->FUN_00980070()->FUN_0051b860());
                    break;
                default:
                    duration3 = FUN_006465f0(owner->FUN_00980070()->GetFloatAt64(),
                                             owner->FUN_00980070()->GetFloatAtOffset68());
                    break;
                }
                if (FUN_005f2440(FUN_00996de0()->FUN_00897910(state, 0, 0, 0)) == state)
                {
                    float current = actor2->FUN_00897b50(state);
                    duration3 = FUN_00404010(current, duration3);
                    float amount_2 = 0.0f;
                    actor2->DispatchToTarget(targetState3 && amount_2 > *DAT_011ce380.FUN_00403e20() ? action | 512
                                                                                                     : action | 256);
                    reactionTimer.FUN_008d7f40(duration3);
                    durationTimer.FUN_008d7f40(current);
                    SetMode(2);
                }
                else if (FUN_005b6f70())
                    FUN_00703c00(DAT_01090c60, actor2->FUN_0055d520(),
                                 action & 4   ? DAT_01090cb8
                                 : action & 8 ? DAT_01090cb0
                                 : action & 1 ? DAT_01090ca4
                                              : DAT_01090c9c);
            }
        }
    }
    else if (FUN_0044edb0() != 1)
    {
        float delay = FUN_006465f0(owner->FUN_00980070()->FUN_009b0bd0(), owner->FUN_00980070()->FUN_006a78f0());
        reactionTimer.FUN_008d7f40(delay);
        FUN_009cfc60();
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
struct Actor98
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
    virtual bool Test(bool);
    Process98* GetProcess();
};
struct Context98
{
    bool FUN_009818b0();
};
struct Procedure98
{
    int unk00;
    Context98* context;
    Actor98* FUN_00996e00();
    unsigned int FUN_00825c00();
    void FUN_009cced0();
    void FUN_009ccfb0();
    void FUN_009cd3d0();
    void FUN_009cc510();
    void UpdateState();
};
// Gets the actor and dispatches on FUN_00825c00(); in case 3 it checks the process state, context and actor test before calling FUN_009cc510().
// @fnv 0x009cf570
void Procedure98::UpdateState()
{
    Actor98* actor = FUN_00996e00();
    switch (FUN_00825c00())
    {
    case 0:
        FUN_009cced0();
        break;
    case 1:
        FUN_009ccfb0();
        break;
    case 2:
        FUN_009cd3d0();
        break;
    case 3: {
        int result = actor && actor->GetProcess() ? actor->GetProcess()->State() : 0;
        if (!context->FUN_009818b0() && !result && (!actor || !actor->Test(false)))
            FUN_009cc510();
        break;
    }
    }
}

struct MeleeDebugActor
{
    short GetVtbl20Result();
    bool FUN_008b3bd0();
};
struct MeleeDebugTimer
{
    float started;
    float target;
    float FUN_00435e00();
    float FUN_006b9130();
    bool FUN_0097fa50();
};
struct MeleeDebugFlags
{
    unsigned short flags;
    unsigned short unknown;
    unsigned short FUN_004a8ae0();
    bool HasNoFlag(unsigned short);
    bool FUN_009373f0();
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
int FUN_00406d00(char*, unsigned, const char*, ...);
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
    MeleeDebugActor* FUN_00996de0();
    void PrintDebugInfo(MeleeDebugOutput*, int, int);
};
// Builds description strings from move, attack and delay timers and prints the procedure's move/attack state and flags via output->Print.
// @fnv 0x009cf700
void MeleeDebugProcedure::PrintDebugInfo(MeleeDebugOutput* output, int x, int y)
{
    MeleeDebugActor* actor = FUN_00996de0();
    short sMovementFlags = actor->GetVtbl20Result();
    char description[100];
    description[0] = DAT_01011584[0];
    FUN_00ec61c0(description + 1, 0, 99);
    switch (moveState)
    {
    case 2:
        FUN_00406d00(description, 100, DAT_01090e4c,
                     sMovementFlags & 1   ? DAT_01090e78
                     : sMovementFlags & 2 ? DAT_01090e6c
                     : sMovementFlags & 4 ? DAT_01090e64
                     : sMovementFlags & 8 ? DAT_01090e5c
                                          : DAT_01011584,
                     moveTimer.FUN_00435e00(), moveTimer.FUN_006b9130());
        break;
    case 1:
        FUN_00406d00(description, 100, DAT_01090e40, moveTimer.FUN_00435e00(), moveTimer.FUN_006b9130());
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
        FUN_00406d00(description, 100, DAT_01090e40, attackTimer.FUN_00435e00(), attackTimer.FUN_006b9130());
        break;
    default:
        description[0] = 0;
        break;
    }
    if (delayTimer.FUN_0097fa50())
        output->Print(x, y, DAT_01090dc8, delayTimer.FUN_00435e00(), delayTimer.FUN_006b9130());
    output->Print(x, y, DAT_01090db8, DAT_011a5ab8[attackState], description);
    if (stateFlags.FUN_004a8ae0() && !actor->FUN_008b3bd0())
        output->Print(x, y, DAT_01090d8c, stateFlags.HasNoFlag(4) ? DAT_01017b68 : DAT_01017b64,
                      stateFlags.HasNoFlag(8) ? DAT_01017b68 : DAT_01017b64,
                      stateFlags.HasNoFlag(1) ? DAT_01017b68 : DAT_01017b64,
                      stateFlags.HasNoFlag(2) ? DAT_01017b68 : DAT_01017b64);
    if (stateFlags.FUN_009373f0())
        output->Print(x, y, DAT_01090d70);
}

class Point9CF
{
  public:
    float x, y, z;

    Point9CF operator-(const Point9CF& pt) const;
    float Length() const;
};

class Actor9CF
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual const Point9CF& GetPos();
};

class Position9CF
{
  public:
    const Point9CF& GetPos();
};

class Setting9CF
{
  public:
    float* Float();
};

extern Setting9CF g_kTalkDistance9CF;

bool __cdecl IsMenuMode9CF();

class Dialogue9CF
{
  public:
    Actor9CF* GetSpeaker();
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
        Actor9CF* pkSpeaker = GetSpeaker();
        Point9CF kDelta = m_kListener.GetPos() - pkSpeaker->GetPos();
        if (kDelta.Length() >= *g_kTalkDistance9CF.Float() * *g_kTalkDistance9CF.Float())
            Stop();
    }
}

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3 operator+(const Pt3& o) const;
    Pt3 operator-(const Pt3& o) const;
    float Length() const;
};
extern Pt3 kPt3Zero;
struct CombatActor
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
    virtual Pt3* GetPos();
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
    virtual void GetCurrentTargetDistance(Pt3* out);
    bool IsAlive();
};
struct CombatProcStub
{
    CombatActor* GetTarget();
    CombatActor* GetActor();
    float GetRange();
    bool IsTargetOutOfRange();
};
// Checks the actor is alive, projects a point ahead of it along its heading, and returns whether the target is at least range*range away from that point.
// @fnv 0x009cfd70
bool CombatProcStub::IsTargetOutOfRange()
{
    Pt3 unusedPos8 = kPt3Zero;
    Pt3 heading = kPt3Zero;
    if (!GetActor() || !GetActor()->IsAlive())
        return false;
    GetActor()->GetCurrentTargetDistance(&heading);
    heading.z = 0.0f;
    Pt3 aheadX = *GetActor()->GetPos() + heading;
    float aRange = GetRange();
    Pt3 diff4 = *GetTarget()->GetPos() - aheadX;
    float dist = diff4.Length();
    return dist >= aRange * aRange;
}

struct FUN_00416870
{
    float x, y, z;
    FUN_00416870(float, float, float);
    FUN_00416870 FUN_00439ef0(const FUN_00416870&) const;
    FUN_00416870 FUN_00439e90(const FUN_00416870&) const;
    float FUN_00457990() const;
};
struct FUN_006815c0
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    FUN_006815c0();
    void FUN_004a0c90(float, int);
    FUN_00416870 FUN_004b4500(const FUN_00416870&) const;
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
struct Actor057
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
    virtual FUN_00416870& Position();
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
    virtual float Heading();
    Control057* FUN_008d8520();
    bool FUN_008b3bd0();
    float FUN_008be280();
    float FUN_008be350();
    unsigned GetVtbl20Result();
};
extern SettingX DAT_011cf968;
float __cdecl FUN_0040ebd0(float, float);
struct State057
{
    bool active, initialized;
    int mode;
    short mask;
    bool left, right, forward, back;
    FUN_00416870 position;
    int UpdateDirection(Actor057* actor, unsigned direction);
    bool FUN_009d0590(Actor057*, const FUN_00416870&);
    void UpdateFlags(unsigned short, bool);
};
// Initializes direction flags from controls, updates position, and for the given direction tests a rotated offset point, storing the result via UpdateFlags.
// @fnv 0x009cff90
int State057::UpdateDirection(Actor057* actor, unsigned direction)
{
    if (!initialized)
    {
        left = actor->FUN_008d8520()->Check(5);
        right = actor->FUN_008d8520()->Check(6);
        forward = actor->FUN_008d8520()->Check(3);
        back = actor->FUN_008d8520()->Check(4);
        initialized = true;
    }
    if (!active && actor->FUN_008b3bd0())
        return 4;
    else if (!active && direction == 0)
    {
        FUN_00416870 f = position.FUN_00439ef0(actor->Position());
        if (f.FUN_00457990() < *DAT_011cf968.FUN_00403e20())
            return 4;
    }
    position = actor->Position();
    FUN_006815c0 a;
    a.FUN_004a0c90(actor->Heading(), 0);
    float b = actor->FUN_008be280();
    if (b == 0.0)
        b = 32.0f;
    float e = actor->FUN_008be350();
    if (e == 0.0)
        e = b;
    unsigned c;
    float d = b / e;
    if (d > 0.5 && d < 2.0)
    {
        b = FUN_00404010(b, e);
        e = b;
    }
    b = FUN_0040ebd0(b, 64.0f);
    e = FUN_0040ebd0(e, 64.0f);
    c = actor->GetVtbl20Result();
    switch (direction)
    {
    case 0: {
        FUN_00416870 g(0.0f, -e, 0.0f);
        if (c & 2)
            g.y -= e;
        g = a.FUN_004b4500(g).FUN_00439e90(position);
        UpdateFlags(2, back ? FUN_009d0590(actor, g) : false);
        break;
    }
    case 1: {
        FUN_00416870 h(0.0f, e, 0.0f);
        if (c & 1)
            h.y += e;
        h = a.FUN_004b4500(h).FUN_00439e90(position);
        UpdateFlags(1, forward ? FUN_009d0590(actor, h) : false);
        break;
    }
    case 2: {
        FUN_00416870 i(-b, 0.0f, 0.0f);
        if (c & 4)
            i.x -= b;
        i = a.FUN_004b4500(i).FUN_00439e90(position);
        UpdateFlags(4, left ? FUN_009d0590(actor, i) : false);
        break;
    }
    case 3: {
        FUN_00416870 j(b, 0.0f, 0.0f);
        if (c & 8)
            j.x += b;
        j = a.FUN_004b4500(j).FUN_00439e90(position);
        UpdateFlags(8, right ? FUN_009d0590(actor, j) : false);
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
extern Setting_S originalRuntimeFloatSetting594;
struct P12_9cc240
{
    float dst0, y, z;
};
struct Act9cc240
{
    bool FUN_008b3b90();
    bool FUN_008b3960();
    float GetScale();
};
struct Tgt9cc240
{
    P12_9cc240* FUN_00575650(P12_9cc240* p);
};
struct Proc9cc240
{
    void FUN_009cc490(int);
    void SetNodeBlockAndTimestamp(P12_9cc240*);
};
struct Own9cc240
{
    Proc9cc240* FUN_00586150();
};
struct Sub64_9cc240
{
    void FUN_009d0610(Own9cc240*);
};
struct Sub48_9cc240
{
    bool FUN_0097fa50();
    void FUN_008d7f40(float);
    bool FUN_008d7f80();
    void FUN_00910b10();
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
    Act9cc240* FUN_00996de0();
    Tgt9cc240* FUN_00996e00();
    void UpdateState();
    void FUN_00483710();
    unsigned int FUN_0044edb0();
    void FUN_009caac0(const char*);
    void FUN_009cd430();
    void UpdateDodge();
    void FUN_009cde10();
    void UpdateCombatMovement();
    void UpdateMeleeCombat();
    float GetModifierValue();
    float FUN_009ce560();
    void SetLookAtPoint(P12_9cc240*, int);
    void FUN_00996ea0();
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
    dst0 = FUN_00996de0();
    Tgt9cc240* idxTmp;
    idxTmp = FUN_00996e00();
    m5c = -1.0f;
    g_011f24e4.FUN_00483710();
    m64.FUN_009d0610(m4);
    UpdateState();
    FUN_00483710();
    if (FUN_0044edb0() == 3 || FUN_0044edb0() == 4)
    {
        if (dst0->FUN_008b3b90() && !dst0->FUN_008b3960())
        {
            if (!m48.FUN_0097fa50())
            {
                m48.FUN_008d7f40(2.0f);
            }
            else if (m48.FUN_008d7f80())
            {
                m4->FUN_00586150()->FUN_009cc490(2);
                m4->FUN_00586150()->SetNodeBlockAndTimestamp(idxTmp->FUN_00575650(&j));
                FUN_009caac0("Could not reach target");
            }
        }
        else if (dst0->FUN_008b3960())
        {
            m48.FUN_00910b10();
        }
    }
    else
    {
        m48.FUN_00910b10();
    }
    switch (FUN_0044edb0())
    {
    case 0:
        FUN_009cd430();
        break;
    case 2:
        UpdateDodge();
        break;
    case 1:
        FUN_009cde10();
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
        a7 = FUN_009ce560();
        if (_v - a7 < *originalRuntimeFloatSetting594.Float() * dst0->GetScale() * 2.25)
            bDone6 = true;
    }
    if (bDone6)
    {
        GetTargetLocationWithOffset(&dst2, idxTmp, 2);
        SetLookAtPoint(&dst2, 4);
    }
    else
    {
        FUN_00996ea0();
    }
    g_011f24e4.FUN_00483710();
}

struct Seq150
{
    int FUN_008041a0();
};
struct Anim150
{
    Seq150* FUN_00491040(int);
};
struct State150
{
    bool GetModifierKey();
    void FUN_009818e0(int);
};
struct Actor150
{
    virtual void p00();
    virtual void p01();
    virtual void p02();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual Anim150* anim();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual bool V230();
    virtual bool check234();
    virtual void x00();
    virtual void x01();
    virtual void x02();
    virtual void x03();
    virtual void x04();
    virtual void x05();
    virtual void x06();
    virtual void x07();
    virtual void x08();
    virtual void x09();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual void x18();
    virtual void x19();
    virtual void x20();
    virtual void x21();
    virtual void x22();
    virtual void x23();
    virtual void x24();
    virtual void x25();
    virtual void x26();
    virtual void x27();
    virtual void x28();
    virtual void x29();
    virtual void x30();
    virtual void x31();
    virtual void x32();
    virtual void x33();
    virtual void x34();
    virtual void x35();
    virtual void x36();
    virtual void x37();
    virtual void x38();
    virtual void x39();
    virtual void x40();
    virtual void x41();
    virtual void x42();
    virtual void x43();
    virtual void x44();
    virtual void x45();
    virtual void x46();
    virtual void x47();
    virtual void x48();
    virtual void x49();
    virtual void x50();
    virtual void x51();
    virtual void x52();
    virtual void x53();
    virtual void x54();
    virtual void x55();
    virtual void x56();
    virtual void x57();
    virtual void x58();
    virtual void x59();
    virtual void x60();
    virtual void x61();
    virtual void x62();
    virtual void x63();
    virtual void x64();
    virtual void x65();
    virtual void x66();
    virtual void x67();
    virtual void x68();
    virtual void x69();
    virtual void x70();
    virtual void x71();
    virtual void x72();
    virtual void x73();
    virtual void x74();
    virtual void x75();
    virtual void x76();
    virtual void x77();
    virtual void x78();
    virtual void x79();
    virtual void x80();
    virtual void x81();
    virtual void x82();
    virtual void x83();
    virtual void x84();
    virtual void x85();
    virtual void x86();
    virtual void x87();
    virtual void x88();
    virtual void x89();
    virtual void x90();
    virtual void x91();
    virtual void x92();
    virtual void x93();
    virtual void x94();
    virtual void x95();
    virtual void x96();
    virtual void x97();
    virtual void x98();
    virtual void x99();
    virtual void x100();
    virtual void x101();
    virtual void x102();
    virtual void x103();
    virtual void x104();
    virtual void x105();
    virtual void x106();
    virtual void x107();
    virtual void x108();
    virtual void x109();
    virtual void x110();
    virtual void x111();
    virtual void x112();
    virtual void x113();
    virtual void x114();
    virtual void x115();
    virtual void x116();
    virtual void x117();
    virtual void x118();
    virtual void x119();
    virtual void x120();
    virtual void x121();
    virtual void x122();
    virtual void x123();
    virtual State150* state();
    bool FUN_00894d60();
    bool FUN_00894cc0(bool);
    bool FUN_00894900();
    int FUN_008a7570();
    unsigned char FUN_00437bd0();
    bool FUN_00579670();
    bool FUN_00437bf0();
};
unsigned int FUN_00487f50();
struct C150
{
    int pad;
    State150* m04;
    Actor150* FUN_00996de0();
    Actor150* FUN_00996e00();
    int FUN_00825c00();
    void FUN_009cf6d0(int);
    float GetModifierValue();
    float FUN_009ce560();
    void FUN_009cd150();
};
// @fnv 0x009cd150
void C150::FUN_009cd150()
{
    if (FUN_00996de0()->anim() && FUN_00996de0()->anim()->FUN_00491040(2) &&
        FUN_00996de0()->anim()->FUN_00491040(2)->FUN_008041a0() != 1)
        return;
    Actor150* actor2 = FUN_00996de0();
    Actor150* target7 = FUN_00996e00();
    if (m04->GetModifierKey() || FUN_00825c00() == 1)
    {
        if (!target7)
        {
            if (actor2->FUN_00894d60())
                actor2->FUN_00894cc0(false);
            m04->FUN_009818e0(0);
            if (FUN_00825c00() == 1)
                FUN_009cf6d0(3);
            return;
        }
        bool active = target7->FUN_00894900();
        bool action = target7->FUN_008a7570() == 4;
        bool state2 = false;
        if (target7->state())
            state2 = target7->state()->GetModifierKey();
        float elapsedTmp = GetModifierValue();
        float limit = FUN_009ce560();
        bool flag_ = false;
        bool blocked = target7->check234() || target7->V230() || target7->FUN_00437bd0() || target7->FUN_00579670() ||
                       target7->FUN_00437bf0();
        if (!(!(elapsedTmp > limit) && !blocked && !action && !state2 &&
              (FUN_00487f50() % 100 >= 5 || (active && !flag_)) && actor2->FUN_00894d60()))
        {
            if (actor2->FUN_00894d60())
                actor2->FUN_00894cc0(false);
            m04->FUN_009818e0(0);
            if (FUN_00825c00() == 1)
                FUN_009cf6d0(3);
        }
    }
}

struct ActorHelper
{
    unsigned short GetVtbl20Result();
    bool FUN_008b3bd0();
    bool FUN_008b3bf0();
    bool FUN_008b3840(void*);
};

struct NiPoint3_ext : public NiPoint3
{
    NiPoint3_ext();
    NiPoint3 operator-(const NiPoint3&) const;
    float Length() const;
};

struct CombatProcedure_shell : public FUN_009cde10_shell
{
    int unk00;
    void* m_04;

    int FUN_0044edb0();
    ActorHelper* FUN_00996de0();
    Actor057* FUN_00996e00();
    void FUN_009ce190();
    void FUN_009ce5b0(CombatVec3*);
    unsigned char IsWithinThreshold(float, float, int);
    void UpdateCombatMovement();
};

float __cdecl FUN_009a6770(ActorHelper*, Actor057*);

// @fnv 0x009cdf80
void CombatProcedure_shell::UpdateCombatMovement()
{
    ActorHelper* actor;
    unsigned short wVal;
    float f0c;
    Actor057* target8;
    CombatVec3 vec1c3;
    float fX;

    if (this->FUN_0044edb0() != 3)
    {
        return;
    }

    actor = this->FUN_00996de0();
    target8 = this->FUN_00996e00();
    f0c = this->GetModifierValue();
    fX = this->FUN_009ce560();
    wVal = actor->GetVtbl20Result();

    if (!actor->FUN_008b3bd0())
    {
        this->FUN_009cd410();
        return;
    }

    FUN_009a68b0(&vec1c3, actor, (CombatAttackVT*)target8, (int)&target8->Position(), this->FUN_009ce560());

    if (f0c > *originalRuntimeFloatSetting593.Float() * 2)
    {
        if (!this->GetSection())
        {
            this->FUN_009ce190();
        }
        return;
    }

    if (this->FUN_009cf030(f0c, fX, 0) && FUN_0097f2d0(this->m_04))
    {
        unsigned char b_ = 0;
        NiPoint3_ext pt9;
        if (actor->FUN_008b3bf0())
        {
            b_ = 1;
        }
        else if (actor->FUN_008b3840(&pt9))
        {
            float f38 = FUN_009a6770(actor, target8);
            float f5 = ((NiPoint3_ext&)(pt9 - (const NiPoint3&)target8->Position())).Length() - f38;
            b_ = this->IsWithinThreshold(f5, fX, 0);
        }
        if (!b_)
        {
            this->FUN_009ce5b0(&vec1c3);
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
            this->FUN_009cd410();
        }
    }
}

struct ZPoint
{
    float unk00, unk04, unk08;
    float FUN_00589850() const;
};
struct B006815c0
{
    float unk00, unk04, unk08;
    B006815c0();
    ZPoint FUN_00439ef0(const ZPoint&) const;
};
struct ZAnim
{
    char FUN_00495f50();
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
    bool FUN_008b3bf0();
    bool FUN_008b3c70();
    bool FUN_008b3840(B006815c0*);
    bool FUN_008b3bb0();
    bool FUN_00894d60();
    void FUN_00894cc0(bool);
};
void __cdecl FUN_009a68b0(ZPoint*, ZActor*, ZActor*, const ZPoint&, float);
float __cdecl FUN_009a6770(ZActor*, ZActor*);
bool __cdecl IsTargetInCone(ZActor*, ZActor*, int);
struct ZSetting
{
    float* Float();
};
extern ZSetting g_011cf27c;
extern double DAT_01017a40;
struct ZMelee
{
    int unk00;
    char* unk04;
    int unk08, unk0C, unk10, unk14;
    int FUN_0044edb0();
    ZActor* FUN_00996de0();
    ZActor* FUN_00996e00();
    float GetModifierValue();
    float FUN_009ce560();
    bool IsTargetOutOfRange();
    bool FUN_009cf030(float, float, int);
    bool IsWithinThreshold(float, float, int);
    void FUN_009ce5b0(ZPoint*);
    void FUN_009cd410();
    void FUN_009cdf00();
    int FUN_00825c00();
    void FUN_009cce70(int, int);
    void TryAttackTarget(float, float);
    void UpdateMeleeCombat();
};
// @fnv 0x009ce1d0
void ZMelee::UpdateMeleeCombat()
{
    if (FUN_0044edb0() != 4)
        return;
    ZActor* actor2 = FUN_00996de0();
    ZActor* target2 = FUN_00996e00();
    float distance3 = GetModifierValue();
    float kReach = FUN_009ce560();
    bool mid4 = IsTargetOutOfRange();
    ZProcess* process2 = actor2->FUN_008d8520();
    if ((FUN_009cf030(distance3, kReach, 0) && FUN_0097f2d0((void*)unk04)) || !FUN_0097f2d0((void*)unk04))
    {
        ZPoint point2;
        FUN_009a68b0(&point2, actor2, target2, target2->Pos(), FUN_009ce560());
        bool ready3 = false;
        B006815c0 kPos;
        if (actor2->FUN_008b3bf0())
            ready3 = true;
        else if (!actor2->FUN_008b3c70() && actor2->FUN_008b3840(&kPos))
        {
            float _radius = FUN_009a6770(actor2, target2);
            float delta = kPos.FUN_00439ef0(target2->Pos()).FUN_00589850() - _radius;
            ready3 = IsWithinThreshold(delta, kReach, 0);
        }
        if (!ready3)
            FUN_009ce5b0(&point2);
    }
    if (actor2->FUN_008b3bb0())
    {
        if (!mid4)
            FUN_009cd410();
    }
    else if (actor2->FUN_00894d60())
        actor2->FUN_00894cc0(false);
    else if (IsWithinThreshold(distance3, kReach, 0) && FUN_0097f2d0((void*)unk04))
    {
        if (mid4 && distance3 < *originalRuntimeFloatSetting593.Float() * 2.0f)
            FUN_009cdf00();
        else
            FUN_009cd410();
    }
    else if (FUN_00825c00() && IsWithinThreshold(distance3, kReach * 2.0f, 0) && FUN_0097f2d0((void*)unk04) &&
             actor2->Check() && process2 && process2->Check())
    {
        if (IsTargetInCone(actor2, target2, 0))
        {
            int topicB = FUN_007031c0((int)unk04);
            if (DialogueRandom() % 100 < (int)(*g_011cf27c.Float() * DAT_01017a40))
            {
                int attackVal = 255;
                if (actor2->Anim(1, DAT_011a8244, 0)->FUN_00495f50() == 108)
                    attackVal = 26;
                else
                    attackVal = 32;
                FUN_009cce70(attackVal, 0);
            }
        }
    }
    else if (unk14)
        TryAttackTarget(distance3, kReach);
}

struct AnimData_9cf
{
    unsigned short FUN_004301b0(int);
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
    bool FUN_0097f2d0();
    Obj_9cf* FUN_00980070();
    int FUN_0097fc70();
    int FUN_007031c0();
};

struct Actor_9cf
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
    virtual AnimData_9cf* v1e4();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void* v1f4();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual bool v218();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual void v8b();
    virtual bool v230();

    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0;
    SubA4 m_a4;

    ActorProcess_9cf* FUN_008d8520();
    bool FUN_005a2030();
    int FUN_008a7570();
    bool FUN_00894900();
    bool FUN_00894d60();
};

struct CTSHelper
{
    int m_val;
    void* FUN_00435de0(float);
    float FUN_00435e00();
};

bool __cdecl IsTargetInCone(Actor_9cf*, Actor_9cf*, int);
bool __cdecl FUN_009a7940(Actor_9cf*, Actor_9cf*, void*, void*, int, int);
float __cdecl FUN_00435dd0();

struct FUN_009cf090_Class
{
    int unk00;
    Context_9cf* m_04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c;
    CTSHelper m_timer60;

    int FUN_00825c00();
    Actor_9cf* FUN_00996de0();
    Actor_9cf* FUN_00996e00();
    int FUN_009ce870(float, float, bool, bool, int);
    bool IsActionAvailable(int);
    void FUN_009cce70(int, int);
    void SetMode(int);

    void TryAttackTarget(float a1, float a2);
};

// @fnv 0x009cf090
void FUN_009cf090_Class::TryAttackTarget(float afArg1, float afArg2)
{
    Actor_9cf* pkActorVal;
    bool bTargetRecoiling;
    {
        int iAttack4;
        bool bTargetAttacking4;
        int iAnimAction4;
        bool bTargetMidAttack3;
        bool bTargetPostAttack_2;
        bool bInAttackAnim5;
        Actor_9cf* pkTarget5;
        int iRandA;
        float fPercent4;
        float aFMax;
        float fChanceTmp;
        CTSHelper helper_;

        if (this->FUN_00825c00() != 3)
        {
            return;
        }

        pkActorVal = this->FUN_00996de0();
        pkTarget5 = this->FUN_00996e00();
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

        if (!pkActorVal->FUN_008d8520()->V254())
        {
            return;
        }

        bInAttackAnim5 = (pkActorVal->v1e4() != 0) ? FUN_005f2670(pkActorVal->v1e4()->FUN_004301b0(4)) : false;
        if (bInAttackAnim5)
        {
            return;
        }

        if (pkActorVal->v218() && pkActorVal->FUN_005a2030())
        {
            return;
        }

        if (!this->m_04->FUN_0097f2d0())
        {
            return;
        }

        if (!IsTargetInCone(pkActorVal, pkTarget5, 0))
        {
            return;
        }

        iAnimAction4 = pkTarget5->FUN_008a7570();
        bTargetAttacking4 = pkTarget5->FUN_00894900();
        bTargetMidAttack3 = (iAnimAction4 == 4);
        bTargetPostAttack_2 = (iAnimAction4 == 8 || iAnimAction4 == 10);
        bTargetRecoiling = pkTarget5->FUN_00894d60();

        iAttack4 = this->FUN_009ce870(afArg1, afArg2, bTargetAttacking4, bTargetMidAttack3, 1);
        if (iAttack4 != 0xff)
        {
            if (this->IsActionAvailable(iAttack4))
            {
                iRandA = DialogueRandom() % 100;
                if (iRandA < this->m_04->FUN_00980070()->GetByteAtOffsetAD())
                {
                    fChanceTmp = CalculateWeightedValue((int)this->m_04->FUN_00980070(), this->m_04->FUN_0097fc70(),
                                                        pkActorVal->m_a4.FUN_0066ef20(11), bTargetAttacking4,
                                                        !this->m_04->FUN_007031c0(), bTargetPostAttack_2,
                                                        pkTarget5->v230(), bTargetRecoiling);

                    fPercent4 = FUN_00644580((Obj*)this->m_04->FUN_00980070(), 50, 50, false, bTargetAttacking4);

                    aFMax = FUN_00404010(100.0 - (fChanceTmp + fPercent4), *DAT_011cea38.FUN_00403e20());

                    if (fChanceTmp > fPercent4 && fChanceTmp > aFMax)
                    {
                        if (FUN_009a7940(pkActorVal, pkTarget5, pkActorVal->v1f4(), pkTarget5->v1f4(), 0, 30))
                        {
                            this->FUN_009cce70(iAttack4, 0);
                            this->SetMode(0);
                        }
                        else
                        {
                            helper_.FUN_00435de0(FUN_00435dd0());
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
    float FUN_00644790();
    float GetField84Float();
    float FUN_0051b8e0();
    float FUN_004e4600();
    float GetFieldEC();
    signed char GetUnk7d();
    float FUN_006447d0();
    float FUN_004e4620();
    float FUN_006447f0();
};
// Computes a weighted value from object fields scaled by a percent ratio, applying optional additive and multiplicative modifiers.
// @fnv 0x00644680
float __cdecl CalculateWeightedValue(Obj641* object, int percent, int unused, bool useMult, bool useThird,
                                     bool useFirst, bool useSecond, bool useLast)
{
    float value;
    float ratio = (float)(percent / g_d100);
    float modifier1 = useFirst ? object->FUN_00644790() : 0.0f;
    float second = useSecond ? object->GetField84Float() : 0.0f;
    float third = useThird ? object->FUN_0051b8e0() : 0.0f;
    float weighted = object->FUN_004e4600() + object->GetFieldEC() * ratio;
    value = object->GetUnk7d() + modifier1 + second + third + weighted;
    value *= useMult ? object->FUN_006447d0() : object->FUN_004e4620();
    value *= useLast ? object->FUN_006447f0() : 1.0f;
    return value;
}

struct xActorM
{
    int GetFlags();
    bool IsReady();
    int GetAnimAction();
    const char* GetFullName();
    void SetFlags(int i);
};
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
struct xSetting
{
    float* Float();
};
extern xSetting xS_eb98;
extern xSetting xS_e380;
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
    xActorM* GetActor();
    xActorM* GetTarget();
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
    xActorM* qfTOqo = GetActor();
    xActorM* qpqRa = GetTarget();
    int qSVM = qfTOqo->GetFlags();
    if (!qfTOqo->IsReady())
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
                qfTOqo->SetFlags(qSVM | 1);
        }
        else if (qrEZrs < *xS_eb98.Float() && (qSVM & 1))
            qfTOqo->SetFlags(qSVM & ~1);
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
            qfTOqo->SetFlags((qSVM | 0x200) & ~0x100);
    }
    else if (qSVM & 0x200)
        qfTOqo->SetFlags((qSVM | 0x100) & ~0x200);
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
    float FUN_00589850();
};

struct FUN_009cfe90_TargetBase
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
    virtual void vf100();
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
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
};

struct FUN_009cfe90_Target : FUN_009cfe90_TargetBase
{
    bool FUN_004938e0();
    virtual void vf2ac(int* value);
};

// @fnv 0x009cfe90
float ProcX::FUN_009cfe90()
{
    FUN_009cfe90_Vector value;

    if (reinterpret_cast<CombatAttackHelper*>(this)->FUN_00996e00() == 0 ||
        !reinterpret_cast<FUN_009cfe90_Target*>(reinterpret_cast<CombatAttackHelper*>(this)->FUN_00996e00())
             ->FUN_004938e0())
        return 0.0f;

    value.x = DAT_011f426c;
    value.y = DAT_011f4270;
    value.z = DAT_011f4274;

    reinterpret_cast<FUN_009cfe90_Target*>(reinterpret_cast<CombatAttackHelper*>(this)->FUN_00996e00())
        ->vf2ac(&value.x);

    return value.FUN_00589850();
}

namespace fnv_009ce5b0 {
struct Req
{
    int data[43];
    Req();
    ~Req();
};
struct Vec
{
    float x, y, z;
};
struct Loc
{
    int data[10];
    Loc(Vec const&, void*);
    ~Loc();
    unsigned char FUN_006ded70(float);
    unsigned FUN_00441110();
    unsigned FUN_006dd4f0() const;
    Vec FUN_005c3420() const;
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
    Avoid* FUN_00559450();
};
struct Shape
{
    int data[9];
    Shape(int, float, float);
};
struct Settings
{
    float* FUN_00403e20();
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
    void* FUN_00575d70();
    unsigned FUN_008d6f30();
};
struct Holder
{
    char* FUN_00586150();
};
unsigned char __cdecl FUN_009a7940(Act*, Targ*, Vec*, int, int, int);
float __cdecl FUN_009a6830(Act*, Targ*, float);
struct C009ce5b0
{
    int pad;
    Holder* holder;
    Act* FUN_00996de0();
    Targ* FUN_00996e00();
    float FUN_009ce560();
    void FUN_009ce5b0(Vec* pos);
};
// Builds a request using an avoidance shape when both checks pass, otherwise builds one from target data.
// @fnv 0x009ce5b0
void C009ce5b0::FUN_009ce5b0(Vec* apPosition)
{
    Act* actor2 = FUN_00996de0();
    Targ* target = FUN_00996e00();
    Req request;
    Loc location(*apPosition, actor2);
    if (location.FUN_006ded70(actor2->FUN_008be1b0()) &&
        FUN_009a7940(actor2, target, apPosition, target->v07d(), 0, 30))
    {
        Ptr avoidX(new Avoid);
        avoidX.FUN_00559450()->AppendNode(Shape(target->v07d(), *((Settings*)&DAT_011cf4e0)->FUN_00403e20(),
                                                  *((Settings*)&DAT_011cf120)->FUN_00403e20()));
        actor2->PathToLocation(&request, &location.FUN_005c3420(), location.FUN_006dd4f0(), location.FUN_00441110(), 5.0f,
                             avoidX.FUN_00559450());
    }
    else
    {
        float distance = 10.0f;
        if ((unsigned char)GetByteAtOffset70(holder->FUN_00586150()))
            distance = FUN_009a6830(actor2, target, FUN_009ce560());
        actor2->PathToLocation(&request, (void*)target->v07d(), target->FUN_008d6f30(), (unsigned)target->FUN_00575d70(),
                             distance, 0);
    }
    actor2->SetPathingRequestAvoidNodes(&request);
}
}  // namespace fnv_009ce5b0

struct FUN_00996de0_ClassQ
{
    Actor* FUN_00996de0();
};
struct FUN_00980070_shellQ
{
    unsigned int FUN_00980070();
};
struct FUN_005524b0_classQ
{
    char GetByteAtOffset8C();
};

// Returns 1 if a is at least b, otherwise 0, ignoring the c parameter.
// @fnv 0x009cf030
unsigned char FUN_009cde10_shell::FUN_009cf030(float a, float b, int aiUnused)
{
    Actor* pTarget3;
    bool bFlag;
    float m_fPackageValue;
    unsigned char bResult = 0;

    pTarget3 = ((FUN_00996de0_ClassQ*)this)->FUN_00996de0();
    bFlag = ((FUN_005524b0_classQ*)(*(FUN_00980070_shellQ**)((char*)this + 4))->FUN_00980070())->GetByteAtOffset8C() >= 100;
    m_fPackageValue = 0.0f;
    if (a >= b + m_fPackageValue)
    {
        bResult = 1;
    }
    return bResult;
}
