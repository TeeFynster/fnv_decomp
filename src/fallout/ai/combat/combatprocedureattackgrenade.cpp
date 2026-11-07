#include "../../../../include/NiPoint3.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/Projectile.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/CombatProcedureAttackGrenade.h"
#include "../../../../include/IDebugText.h"
#include "../../../../include/InterfaceManager.h"
// LocalPoint: unit-local copy of the former shared stand-in Point. Same layout as NiPoint3 with the stand-in's own inline operators; with NiPoint3, WriteDebugText (0x009cb890) does not match.
class Scalar;
class Vector;

class LocalPoint
{
public:
    float x;
    float y;
    float z;

    __forceinline LocalPoint()
    {
    }
    __forceinline LocalPoint(float px, float py, float pz)
        : x(px), y(py), z(pz)
    {
    }

    float& operator()(int index);
    const float& operator()(int index) const;
    LocalPoint operator+(const LocalPoint& other) const;
    LocalPoint operator-(const LocalPoint& other) const;
    inline LocalPoint operator-() const
    {
        return LocalPoint(-x, -y, -z);
    }
    __forceinline LocalPoint operator*(float scalar) const
    {
        return LocalPoint(scalar * x, scalar * y, scalar * z);
    }
    __forceinline LocalPoint operator/(float scalar) const
    {
        float inverse = 1.0f / scalar;
        return LocalPoint(x * inverse, y * inverse, z * inverse);
    }
    __forceinline LocalPoint& operator+=(const LocalPoint& other)
    {
        x = (float)(other.x + x);
        y = (float)(other.y + y);
        z = (float)(other.z + z);
        return *this;
    }
    __forceinline LocalPoint& operator*=(float scalar)
    {
        x = scalar * x;
        y = scalar * y;
        z = scalar * z;
        return *this;
    }
    inline bool operator==(const LocalPoint& other) const
    {
        return other.x == x && other.y == y && other.z == z;
    }

    LocalPoint ApplyScaled(float scalar);
    LocalPoint Cross(const LocalPoint& other) const;
    float Dot(const LocalPoint& other) const;
    double DotProduct(const LocalPoint& other);
    float Length() const;
    float Distance(LocalPoint* other);
    float GetX();
    float GetY();

    bool HasEqualComponents(const LocalPoint& other) const;
    LocalPoint SubtractIntoVector(const LocalPoint& other);
    LocalPoint FUN_00439e90(const LocalPoint& other);
    void Unitize_004a0c10();
    char* GetViewerString_00a59af0(const char* text);
    float FUN_004a7290() const;
    float FUN_00435e00();
    float AStarSearch_EvaluateValue_006a7f50();

    float& at(int index);
    float at(int index) const;
    void add(const LocalPoint& a, const LocalPoint& b);
    void difference(const LocalPoint& a, const LocalPoint& b);
    void absolute();
    void scale(float scalar);

    void flip();
    void setZero4();
    void setSub4(const LocalPoint& a, const LocalPoint& b);
    void setAdd4(const LocalPoint& a, const LocalPoint& b);
    void setMul4(const Scalar& scalar, const LocalPoint& point);
    void addMul4(const Scalar& scalar, const LocalPoint& point);
    void setCross(const LocalPoint& a, const LocalPoint& b);
    Scalar dot3(const LocalPoint& point) const;
    Scalar lengthSquared3() const;
    Scalar length3() const;
    const Vector& pos() const;
    const Vector& dir() const;
};

namespace loader
{
    struct LocalPoint
    {
        float x;
        float y;
        float z;

        LocalPoint(float x, float y, float z);
    };
}
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/Setting.h"

// src/fallout/ai/combat/combatprocedureattackgrenade.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureattackgrenade.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x009cafc0
// src: XBOX_PDB 0x009cafc0
void CombatProcedureAttackGrenade::Shutdown_009cafc0()
{
    CombatProcedure::RunProcedure();
}

struct FUN_009cb440_shell
{
    void __thiscall CombatState_SetTargetFlushed(unsigned char b);
};

// @fnv 0x009cb440
// src: XBOX_PDB 0x009cb440
void __thiscall FUN_009cb440_shell::CombatState_SetTargetFlushed(unsigned char b)
{
    *reinterpret_cast<unsigned char*>(this + 0x73) = b;
}

void __cdecl Deallocate(void*);

struct FUN_009caeb0_shell
{
    void __thiscall UpdateFields_009cafa0();
    void* __thiscall FUN_009caeb0(unsigned int flags);
};

// Calls FUN_009cafa0, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009caeb0
void* __thiscall FUN_009caeb0_shell::FUN_009caeb0(unsigned int flags)
{
    UpdateFields_009cafa0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_010909bc;
struct FUN_009ca6c0_shell
{
    void SetVirtualTable_009ca6c0();
};
struct FUN_009cafa0_shell
{
    void UpdateFields_009cafa0();
};
// @fnv 0x009cafa0
// src: GUESS 0x009cafa0 (confidence: low)
void FUN_009cafa0_shell::UpdateFields_009cafa0()
{
    *reinterpret_cast<int**>(this) = &DAT_010909bc;
    reinterpret_cast<FUN_009ca6c0_shell*>(this)->SetVirtualTable_009ca6c0();
}

extern Setting originalRuntimeFloatSetting375;
struct IMH
{
    struct FUN_009cb440_shell* CombatController_GetCombatState();
};
struct Helper_caae0
{
    void __thiscall SetState();
};
struct FUN_009cb830_shell
{
    void __thiscall CombatProcedureAttackGrenade_FiredProjectile(Projectile* apProjectile);
};
// @fnv 0x009cb830
// src: XBOX_PDB 0x009cb830
void __thiscall FUN_009cb830_shell::CombatProcedureAttackGrenade_FiredProjectile(Projectile* apProjectile)
{
    if (*(bool*)((char*)this + 0x30))
    {
        apProjectile->Projectile_SetSpeedMult(*originalRuntimeFloatSetting375.Float());
    }
    *(bool*)((char*)this + 0x30) = 0;
    if (*(bool*)((char*)this + 0x14))
    {
        (*(IMH**)((char*)this + 4))->CombatController_GetCombatState()->CombatState_SetTargetFlushed(1);
        ((Helper_caae0*)this)->SetState();
    }
}

struct FUN_009a5eb0_shell
{
    void __thiscall FUN_009a5eb0(BGSSaveFormBuffer* p);
};
struct CombatProcedureSaveGameShell
{
    void __thiscall SaveGame(BGSSaveFormBuffer* p);
};
struct FUN_009cb9c0_shell
{
    void __thiscall CombatProcedureAttackGrenade_SaveGame(BGSSaveFormBuffer* p);
};
// @fnv 0x009cb9c0
// src: XBOX_PDB 0x009cb9c0
void __thiscall FUN_009cb9c0_shell::CombatProcedureAttackGrenade_SaveGame(BGSSaveFormBuffer* pBuffer)
{
    ((CombatProcedureSaveGameShell*)this)->SaveGame(pBuffer);
    pBuffer->SaveData((char*)this + 0x10, 4, 0);
    pBuffer->SaveData((char*)this + 0x14, 1, 0);
    pBuffer->SaveData((char*)this + 0x18, 0xc, 0);
    pBuffer->SaveData((char*)this + 0x24, 0xc, 0);
    pBuffer->SaveData((char*)this + 0x30, 1, 0);
    ((FUN_009a5eb0_shell*)((char*)this + 0x34))->FUN_009a5eb0(pBuffer);
}

struct CombatProcedure_LoadGame
{
    void __thiscall LoadGame(BGSLoadFormBuffer* p);
};
struct FUN_009cba50_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_aa;
    int m_ab;
    int m_ac;
    int m_ad;
    int m_ae;
    int m_af;
    int m_ag;
    int m_ah;
    int m_ai;
    int m_aj;
    int m_ak;
    int m_al;
    int m_am;
    int m_an;
    int m_ao;
    int m_ap;
    int m_aq;
    int m_ar;
    int m_as;
    int m_at;
    int m_au;
    int m_av;
    int m_aw;
    int m_ax;
    int m_ay;
    int m_az;
    void __thiscall CombatProcedureAttackGrenade_LoadGame(BGSLoadFormBuffer* buffer);
};
// @fnv 0x009cba50
// src: XBOX_PDB 0x009cba50
void __thiscall FUN_009cba50_shell::CombatProcedureAttackGrenade_LoadGame(BGSLoadFormBuffer* buffer)
{
    ((CombatProcedure_LoadGame*)this)->LoadGame(buffer);
    buffer->ReadTypedData((char*)this + 0x10, 4);
    buffer->ReadTypedData((char*)this + 0x14, 1);
    buffer->ReadTypedData((char*)this + 0x18, 0xc);
    buffer->ReadTypedData((char*)this + 0x24, 0xc);
    buffer->ReadTypedData((char*)this + 0x30, 1);
    ((TimeoutTimer*)((char*)this + 0x34))->LoadGame(buffer);
}

NiPoint3* __cdecl CombatUtilities_GetAttackerFiringLocation(NiPoint3* result, void* actor);
void __cdecl GetTargetLocationWithOffset(NiPoint3* result, void* target, int mode);
NiPoint3 __cdecl GetTriple12(void* target);
unsigned char __cdecl CombatUtilities_CheckProjectileArc_009a7670(void* actor, void* target, unsigned int flags, NiPoint3 origin, NiPoint3 direction,
                                   NiPoint3 offset, unsigned int mode, unsigned int category, float scale);

// @fnv 0x009a7580
// src: XBOX_PDB 0x009a7580
unsigned char __cdecl CombatUtilities_CheckProjectileArc(void* actor, void* target, unsigned int flags, NiPoint3* optionalOrigin,
                                   unsigned int mode, unsigned int category, float scale)
{
    if (!actor || !target)
        return 0;
    float offset[3];
    reinterpret_cast<NiPoint3*>(offset)->FUN_006815c0();
    if (optionalOrigin)
        reinterpret_cast<NiPoint3&>(offset) = *optionalOrigin;
    else
    {
        float temp[3];
        reinterpret_cast<NiPoint3&>(offset) = *CombatUtilities_GetAttackerFiringLocation(reinterpret_cast<NiPoint3*>(temp), actor);
    }
    float origin[3];
    GetTargetLocationWithOffset(reinterpret_cast<NiPoint3*>(origin), target, 2);
    NiPoint3 direction = GetTriple12(target);
    return CombatUtilities_CheckProjectileArc_009a7670(actor, target, flags, reinterpret_cast<NiPoint3&>(offset), reinterpret_cast<NiPoint3&>(origin), direction, mode, category, scale);
}



extern int DAT_010909bc;
extern NiPoint3 DAT_011f426c;

struct CombatBaseObj
{
    void* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    CombatBaseObj();
};

struct CombatMember34
{
    int m_00;
    void Init();
    ~CombatMember34();
};

struct FUN_009cadf0_cls : CombatBaseObj
{
    int m_10;
    unsigned char m_14;
    float m_18[3];
    float m_24[3];
    unsigned char m_30;
    CombatMember34 m_34;
    FUN_009cadf0_cls();
};

// Initialises the object: sets the vtable, zeroes m_10/m_14/m_30, copies DAT_011f426c into m_18 and m_24, and calls m_34.Init().
// @fnv 0x009cadf0
FUN_009cadf0_cls::FUN_009cadf0_cls()
{
    m_vptr = &DAT_010909bc;
    m_10 = 0;
    m_14 = 0;
    reinterpret_cast<NiPoint3&>(m_18) = DAT_011f426c;
    reinterpret_cast<NiPoint3&>(m_24) = DAT_011f426c;
    m_30 = 0;
    m_34.Init();
}

namespace fnv_009caee0 {
extern NiPoint3 DAT_011f426c;

class Base_b6365
{
  public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    Base_b6365();
    ~Base_b6365();
};

class Member_b6365
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    void Reset();
};

class FUN_009caee0 : public Base_b6365
{
  public:
    virtual ~FUN_009caee0();
    unsigned char m_14;
    float m_18[3];
    float m_24[3];
    unsigned char m_30;
    Member_b6365 m_34;

    FUN_009caee0(const NiPoint3* src, unsigned char flag);
};

// Initialises the object: stores a copy of src into m_18, sets m_24 from DAT_011f426c, m_14 to 1, m_30 to flag, and resets m_34.
// @fnv 0x009caee0
FUN_009caee0::FUN_009caee0(const NiPoint3* src, unsigned char flag) : Base_b6365()
{
    m_10 = 0;
    m_14 = 1;
    reinterpret_cast<NiPoint3&>(m_18) = *src;
    reinterpret_cast<NiPoint3&>(m_24) = DAT_011f426c;
    m_30 = flag;
    m_34.Reset();
}
}  // namespace fnv_009caee0

class B9CB380Form;
class B9CB380Mobile;

class B9CB380Process
{
  public:
    void SetTarget(B9CB380Form* pkForm);
    void CombatState_SetTargetFlushed(bool bFlag);
};

class B9CB380Actor
{
  public:
    B9CB380Mobile* GetMobile();
    B9CB380Process* GetProcess();
};

class B9CB380World
{
  public:
    bool IsThreatWithinLimits(B9CB380Mobile* pkMobile, B9CB380Form* pkForm, int iArg, float fArg);
};

class B9CB380Timer
{
  public:
    bool CombatTimer_IsSet();
    bool FUN_008d7f80();
    void FUN_008d7f40(float fTime);

    int unk00;
};

extern B9CB380World* g_pkB9CB380World;
extern Setting g_kB9CB380Setting;

class B9CB380Package
{
  public:
    int unk00;
    B9CB380Actor* m_pkActor;
    int unk08;
    int unk0C;
    int unk10;
    bool m_bFlag14;
    char unk15;
    short unk16;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    B9CB380Timer m_kTimer;

    void SetState();
    bool CombatProcedureAttackGrenade_CheckExplosion(B9CB380Form* pkForm, int iArg, float fArg);
};

// @fnv 0x009cb380
// src: XBOX_PDB 0x009cb380
bool B9CB380Package::CombatProcedureAttackGrenade_CheckExplosion(B9CB380Form* pkForm, int iArg, float fArg)
{
    B9CB380Mobile* pkMobile2 = m_pkActor->GetMobile();
    B9CB380Process* pkProcess = m_pkActor->GetProcess();
    if (!g_pkB9CB380World->IsThreatWithinLimits(pkMobile2, pkForm, iArg, fArg))
    {
        if (!m_kTimer.CombatTimer_IsSet())
            m_kTimer.FUN_008d7f40(*g_kB9CB380Setting.Float());
        else if (m_kTimer.FUN_008d7f80())
            pkProcess->SetTarget(pkForm);
        if (m_bFlag14)
        {
            pkProcess->CombatState_SetTargetFlushed(true);
            SetState();
        }
        return false;
    }
    return true;
}

namespace fnv_009cb6e0 {
extern const NiPoint3 NiPoint3_ZERO;

extern Setting originalRuntimeFloatSetting375;


NiPoint3 __cdecl ComputeTrajectory(Actor* actor, void* target, int unused, PathingRequest* req, float dist, bool flag);
NiPoint3 __cdecl TESObjectREFR_ForwardCall_009a8d80(Actor* actor, NiPoint3* point, int unused, PathingRequest* req, float dist, bool flag);

struct CombatProcedureShell
{
    int unk00;
    InterfaceManager* unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool b14;
    NiPoint3 pt18;
    int unk24;
    int unk28;
    int unk2C;
    bool b30;

    Actor* CombatProcedure_GetAttacker();
    void* GetTarget_00996e00();
    NiPoint3 GetPathingPoint();
};

// @fnv 0x009cb6e0
NiPoint3 CombatProcedureShell::GetPathingPoint()
{
    if (!b14 && !GetTarget_00996e00())
    {
        return NiPoint3_ZERO;
    }
    TESObjectREFR* ref = unk04->GetCurrentWeapon();
    PathingRequest* req = ref->GetOrFallback(CombatProcedure_GetAttacker());
    float dist = req->GetFloatAtOffset68() * (b30 ? *originalRuntimeFloatSetting375.Float() : 1.0f);
    NiPoint3 point;
    if (!b14)
    {
        point = ComputeTrajectory(CombatProcedure_GetAttacker(), GetTarget_00996e00(), 0, req, dist, b30);
    }
    else
    {
        point = TESObjectREFR_ForwardCall_009a8d80(CombatProcedure_GetAttacker(), &pt18, 0, req, dist, b30);
    }
    return point;
}
}  // namespace fnv_009cb6e0

struct Item
{
    void* Sound();
};
struct Manager
{
    Item* Select(void*);
};
struct Process
{
    void Set(unsigned char);
};
struct Owner
{
    Manager* ManagerGet();
    Process* ProcessGet();
};
struct Procedure
{
    int unk00;
    Owner* owner;
    int unk08, unk0c, unk10;
    unsigned char active;
    LocalPoint origin;
    LocalPoint destination;
    unsigned char category;
    void* ActorGet();
    TESObjectREFR* TargetGet();
    bool Validate(void*, LocalPoint*, float);
    void Reset();
    bool CombatProcedureAttackGrenade_GetTargetedPoint(LocalPoint* output, LocalPoint* input);
};
extern LocalPoint zeroPoint;
extern const float scaleValue;
unsigned char Arc(void*, TESObjectREFR*, Item*, LocalPoint, LocalPoint, LocalPoint, unsigned char*, LocalPoint*, float);
unsigned char Direct(void*, TESObjectREFR*, Item*, LocalPoint*, unsigned char*, LocalPoint*, float);
float Distance(Item*, LocalPoint, LocalPoint, unsigned char, float);
// @fnv 0x009cb460
// src: XBOX_PDB 0x009cb460
bool Procedure::CombatProcedureAttackGrenade_GetTargetedPoint(LocalPoint* output, LocalPoint* input)
{
    void* i;
    i = ActorGet();
    TESObjectREFR* targetVal;
    targetVal = TargetGet();
    Manager* sound;
    sound = owner->ManagerGet();
    Item* z;
    z = sound->Select(i);
    void* pForm;
    pForm = z->Sound();
    bool ptr;
    ptr = false;
    if (active)
    {
        if (Arc(i, targetVal, z, *input, origin, zeroPoint, &category, &destination, scaleValue))
        {
            *output = destination;
            ptr = true;
        }
    }
    else
    {
        if (Direct(ActorGet(), TargetGet(), sound->Select(i), input, &category, &destination, scaleValue))
        {
            *output = destination;
            ptr = true;
        }
    }
    if (ptr && pForm)
    {
        LocalPoint position7;
        if (active)
            position7 = origin;
        else
        {
            position7 = destination;
            position7.z = static_cast<const TESObjectREFR*>(targetVal)->GetPos()->z;
        }
        float distance7;
        distance7 = Distance(z, *input, position7, category, 0.0f);
        if (!Validate(pForm, &position7, distance7))
            ptr = false;
    }
    if (!ptr && active)
    {
        owner->ProcessGet()->Set(1);
        Reset();
    }
    return ptr;
}

namespace fnv_009cafe0 {

struct Obj70
{
    int GetSlotValue(int a);
};
struct ProcessObj
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual bool vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c(int a);
};
struct ActorObj
{
    bool Actor_IsAttacking();
    int GetAnimAction_008a7570();
    ProcessObj* FUN_008d8520();
    bool TryAttack(int a);
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual Obj70* vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* vfn_1f4();
};
struct SoundObj
{
    int s00;
};
struct MidObj
{
    SoundObj* BGSProjectile_GetExplosion();
};
struct Obj703
{
    MidObj* GetOrFallback(ActorObj* a);
};
struct Obj586
{
    bool GetHasBufferedDetection_0097ee90();
    bool CombatState_GetTargetSpaceDifferent();
    void FUN_00442a80(int a);
};
struct Sub04
{
    Obj586* CombatController_GetCombatState();
    Obj703* GetCurrentWeapon();
    bool FUN_00981970();
};
struct GlobalObj
{
    void CombatDialogueManager_StartDialogue(void* a, int b, int c, int d);
};
extern GlobalObj* DAT_011f1708;
struct Member34
{
    void TESWeightForm_InitializeDataComponent();
};
void __cdecl CombatUtilities_ComputeOptimalWeaponRanges(Sub04* a, Obj703* b, float* x, float* y, float* z);
unsigned char __cdecl CombatUtilities_CheckProjectileArc(ActorObj* a, ActorObj* b, MidObj* c, void* d, unsigned char* e, NiPoint3* f, float g);
bool __cdecl IsExplosionRadiusValid(SoundObj* a);

struct Package
{
    int unk00;
    Sub04* m_04;
    int unk08;
    int unk0c;
    int m_10;
    unsigned char m_14;
    unsigned char m_15;
    short m_16;
    NiPoint3 m_18;
    NiPoint3 m_24;
    unsigned char m_30;
    unsigned char m_31;
    unsigned char m_32;
    unsigned char m_33;
    Member34 m_34;
    ActorObj* CombatProcedure_GetAttacker();
    ActorObj* GetTarget_00996e00();
    void CombatProcedure_SetFailed(const char* msg);
    void ClearLookAtTarget_00996ea0();
    void SetLookAtPoint(NiPoint3* p, int a);
    NiPoint3* GetPathingPoint(NiPoint3* out);
    bool CombatProcedureAttackGrenade_CheckExplosion(SoundObj* s, NiPoint3* p, float f);
    void UpdateWeaponFire();
};

// @fnv 0x009cafe0
void Package::UpdateWeaponFire()
{
    ActorObj* actor2;
    actor2 = CombatProcedure_GetAttacker();
    ActorObj* i;
    i = GetTarget_00996e00();
    Obj586* n;
    n = m_04->CombatController_GetCombatState();
    Obj703* s;
    s = m_04->GetCurrentWeapon();
    Obj70* aPObj;
    aPObj = actor2->vfn_1e4();
    if (!s || !aPObj || !s->GetOrFallback(actor2))
    {
        CombatProcedure_SetFailed("Missing either weapon, animation, or weapon projectile");
        return;
    }
    if (actor2->Actor_IsAttacking())
    {
        m_10 = 1;
    }
    else if (actor2->GetAnimAction_008a7570() == -1)
    {
        m_10 = 0;
    }
    if (!m_14 && !m_10)
    {
        m_30 = 0;
    }
    if (!n->GetHasBufferedDetection_0097ee90() || n->CombatState_GetTargetSpaceDifferent())
    {
        if (m_10)
        {
            ClearLookAtTarget_00996ea0();
            m_10 = 0;
        }
        return;
    }
    DAT_011f1708->CombatDialogueManager_StartDialogue(m_04, 2, 0, 0);
    float AJ[3];
    m_24 = *GetPathingPoint(&reinterpret_cast<NiPoint3&>(AJ));
    float dir3[3];
    reinterpret_cast<NiPoint3&>(dir3).x = 0.0f;
    reinterpret_cast<NiPoint3&>(dir3).y = 0.0f;
    reinterpret_cast<NiPoint3&>(dir3).z = 0.0f;
    CombatUtilities_ComputeOptimalWeaponRanges(m_04, s, &reinterpret_cast<NiPoint3&>(dir3).x, &reinterpret_cast<NiPoint3&>(dir3).y, &reinterpret_cast<NiPoint3&>(dir3).z);
    float kIter[3];
    m_24.SubtractIntoVector(&reinterpret_cast<NiPoint3&>(kIter), actor2->vfn_1f4());
    if (reinterpret_cast<NiPoint3&>(kIter).GetSquaredXYLength() > reinterpret_cast<NiPoint3&>(dir3).z * reinterpret_cast<NiPoint3&>(dir3).z)
    {
        ClearLookAtTarget_00996ea0();
        m_10 = 0;
        return;
    }
    if (m_24.FUN_00439090((NiPoint3*)&DAT_011f426c))
    {
        SetLookAtPoint(&m_24, 4);
    }
    if (1 == m_10 && (actor2->GetAnimAction_008a7570() != 4 || aPObj->GetSlotValue(4) > 2))
    {
        return;
    }
    if (!actor2->FUN_008d8520()->vfn_3f8() || m_04->FUN_00981970())
    {
        return;
    }
    SoundObj* idx;
    idx = s->GetOrFallback(actor2)->BGSProjectile_GetExplosion();
    NiPoint3* AP;
    float CTmp[3];
    if (idx)
    {
        AP = m_14 ? &m_18 : i->vfn_1f4();
        reinterpret_cast<NiPoint3&>(CTmp) = *AP;
        if (!CombatProcedureAttackGrenade_CheckExplosion(idx, &reinterpret_cast<NiPoint3&>(CTmp), 0.0f))
        {
            return;
        }
    }
    MidObj* pForm;
    pForm = s->GetOrFallback(actor2);
    if (!m_14)
    {
        if (!CombatUtilities_CheckProjectileArc(actor2, i, pForm, 0, &m_30, &m_24, -1.0f))
        {
            return;
        }
    }
    if (idx)
    {
        n->FUN_00442a80(0);
        m_34.TESWeightForm_InitializeDataComponent();
    }
    actor2->FUN_008d8520()->vfn_43c(1);
    actor2->TryAttack(0x72);
    m_10 = 1;
    if (idx && IsExplosionRadiusValid(idx))
    {
        DAT_011f1708->CombatDialogueManager_StartDialogue(m_04, 2, 4, 1);
    }
}
}  // namespace fnv_009cafe0


struct CTSHelper
{
    float __thiscall GetElapsedTime();
};

struct Modifier
{
    bool __thiscall CombatTimer_IsSet();
    float __thiscall GetValue();
};

struct FUN_009cb890_shell
{
    void __thiscall WriteDebugText(IDebugText* debugText, int location, int justify);
};

// Writes debug lines for the state, targeted point, high-arc flag and blocked-timer values via debugText->Print.
// @fnv 0x009cb890
void FUN_009cb890_shell::WriteDebugText(IDebugText* debugText, int location, int justify)
{
    switch (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x10))
    {
    case 0:
        debugText->Print(static_cast<DEBUGTEXT_LOCATION>(location), static_cast<DEBUGTEXT_JUSTIFY>(justify), "IDLE");
        break;
    case 1:
        debugText->Print(static_cast<DEBUGTEXT_LOCATION>(location), static_cast<DEBUGTEXT_JUSTIFY>(justify), "ATTACKING");
        break;
    }

    debugText->Print(static_cast<DEBUGTEXT_LOCATION>(location), static_cast<DEBUGTEXT_JUSTIFY>(justify), "Targeted Point: %.02f, %.02f, %.02f",
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x24),
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x28),
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x2c));

    if (*reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x30))
    {
        debugText->Print(static_cast<DEBUGTEXT_LOCATION>(location), static_cast<DEBUGTEXT_JUSTIFY>(justify), "HIGH ARC");
    }

    if (reinterpret_cast<Modifier*>(reinterpret_cast<unsigned char*>(this) + 0x34)->CombatTimer_IsSet())
    {
        debugText->Print(static_cast<DEBUGTEXT_LOCATION>(location), static_cast<DEBUGTEXT_JUSTIFY>(justify), "Explosive Projectile Blocked Timer: %.02f/%.02f",
                         reinterpret_cast<CTSHelper*>(reinterpret_cast<unsigned char*>(this) + 0x34)->GetElapsedTime(),
                         reinterpret_cast<Modifier*>(reinterpret_cast<unsigned char*>(this) + 0x34)->GetValue());
    }
}
