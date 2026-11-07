
// src/fallout/ai/combat/combatprocedureattackranged.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureattackranged.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/CombatProcedureAttackRanged.h"
#include "../../../../include/TimeoutTimer.h"

// The shared timer has no elapsed-time accessor. A single ECX argument
// preserves the original no-argument member-call convention.
float __fastcall GetTimeoutTimerElapsed(TimeoutTimer* timer);

extern void* DAT_01090ed4;

// Methods not yet declared by the shared class keep their original ECX/stack ABI.
Actor* __fastcall GetRangedActor(CombatProcedureAttackRanged* self);
Actor* __fastcall GetRangedTarget(CombatProcedureAttackRanged* self);
void __fastcall ResetRangedTask(CombatProcedureAttackRanged* self);


// The base destructor is empty, but its out-of-line call is part of this unit.
void __fastcall DestroyRangedBase(CombatProcedure* self)
{}

// At /Od, an unused EDX parameter would still be spilled. Aggregate arguments
// stay on the stack, matching the missing member declarations' thiscall ABI.
struct RangedBoolArgument { bool value; };
struct RangedUIntArgument { unsigned int value; };
struct RangedIntArgument { int value; };

// @fnv 0x009d0980
void __fastcall DestroyRangedProcedure(CombatProcedureAttackRanged* self)
{
    *(void**)self = &DAT_01090ed4;
    DestroyRangedBase(self);
}

struct FUN_009d09f0_shell
{
    void __thiscall SetByteAtOffsetC6(char c);
};

// @fnv 0x009d09f0
void __thiscall FUN_009d09f0_shell::SetByteAtOffsetC6(char acValue)
{
    ((char*)this)[0xc6] = acValue;
}

struct FUN_009d0a10_shell
{
    void SetByteAt142(unsigned char value);
};

// @fnv 0x009d0a10
void FUN_009d0a10_shell::SetByteAt142(unsigned char value)
{
    *(unsigned char*)((char*)this + 0x142) = value;
}


// @fnv 0x009d1dc0
// src: XBOX_PDB 0x009d1dc0
void CombatProcedureAttackRanged::Disarmed_009d1dc0(Actor* apOpponent)
{
    CombatProcedure_SetFailed("Disarmed");
}

extern void _Deallocate(void* p);


// Calls FUN_009d0980 on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009d0950
void* __fastcall DeleteRangedProcedure(CombatProcedureAttackRanged* self, void*, unsigned int flags)
{
    DestroyRangedProcedure(self);
    if (flags & 1)
        _Deallocate(self);
    return self;
}

// @fnv 0x009d09a0
void __fastcall RunRangedProcedure(CombatProcedureAttackRanged* self)
{
    Actor* pattacker;
    pattacker = GetRangedActor(self);
    self->RunProcedure();
    ((FUN_009d0a10_shell*)self->m_pCombatController)->SetByteAt142(0);
    ResetRangedTask(self);
    ((FUN_009d09f0_shell*)self->m_pCombatController)->SetByteAtOffsetC6(-1);
}

// @fnv 0x009d2310
void CombatProcedureAttackRanged::SaveGame(BGSSaveFormBuffer* buffer)
{
    CombatProcedure::SaveGame(buffer);
    buffer->SaveData(&m_10, 4, 0);
    buffer->SaveData(&m_14, 12, 0);
    m_20.SaveGame(buffer);
    m_30.SaveGame(buffer);
    m_40.SaveGame(buffer);
    m_28.SaveGame(buffer);
    m_38.SaveGame(buffer);
}

// @fnv 0x009d23a0
void CombatProcedureAttackRanged::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    CombatProcedure::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)&m_10, 4u);
    apLoadGameBuffer->ReadTypedData((void*)&m_14, 0xcu);
    m_20.LoadGame(apLoadGameBuffer);
    m_30.LoadGame(apLoadGameBuffer);
    m_40.LoadGame(apLoadGameBuffer);
    m_28.LoadGame(apLoadGameBuffer);
    if (apLoadGameBuffer->GetVersion() >= 0xa)
        m_38.LoadGame(apLoadGameBuffer);
}

class D1C30Process
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
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void vfn288();
    virtual void vfn28C();
    virtual void vfn290();
    virtual void vfn294();
    virtual void vfn298();
    virtual void vfn29C();
    virtual void vfn2A0();
    virtual void vfn2A4();
    virtual void vfn2A8();
    virtual void vfn2AC();
    virtual void vfn2B0();
    virtual void vfn2B4();
    virtual void vfn2B8();
    virtual void vfn2BC();
    virtual void vfn2C0();
    virtual void vfn2C4();
    virtual void vfn2C8();
    virtual void vfn2CC();
    virtual void vfn2D0();
    virtual void vfn2D4();
    virtual void vfn2D8();
    virtual void vfn2DC();
    virtual void vfn2E0();
    virtual void vfn2E4();
    virtual void vfn2E8();
    virtual void vfn2EC();
    virtual void vfn2F0();
    virtual void vfn2F4();
    virtual void vfn2F8();
    virtual void vfn2FC();
    virtual void vfn300();
    virtual void vfn304();
    virtual void vfn308();
    virtual void vfn30C();
    virtual void vfn310();
    virtual void vfn314();
    virtual void vfn318();
    virtual void vfn31C();
    virtual void vfn320();
    virtual void vfn324();
    virtual void vfn328();
    virtual void vfn32C();
    virtual void vfn330();
    virtual void vfn334();
    virtual void vfn338();
    virtual void vfn33C();
    virtual void vfn340();
    virtual void vfn344();
    virtual void vfn348();
    virtual void vfn34C();
    virtual void vfn350();
    virtual void vfn354();
    virtual void vfn358();
    virtual void vfn35C();
    virtual void vfn360();
    virtual void vfn364();
    virtual void vfn368();
    virtual void vfn36C();
    virtual void vfn370();
    virtual void vfn374();
    virtual void vfn378();
    virtual void vfn37C();
    virtual void vfn380();
    virtual void vfn384();
    virtual void vfn388();
    virtual void vfn38C();
    virtual void vfn390();
    virtual void vfn394();
    virtual void vfn398();
    virtual void vfn39C();
    virtual void vfn3A0();
    virtual void vfn3A4();
    virtual void vfn3A8();
    virtual void vfn3AC();
    virtual void vfn3B0();
    virtual void vfn3B4();
    virtual void vfn3B8();
    virtual void vfn3BC();
    virtual void vfn3C0();
    virtual void vfn3C4();
    virtual void vfn3C8();
    virtual void vfn3CC();
    virtual void vfn3D0();
    virtual void vfn3D4();
    virtual void vfn3D8();
    virtual void vfn3DC();
    virtual void vfn3E0();
    virtual void vfn3E4();
    virtual void vfn3E8();
    virtual void vfn3EC();
    virtual void vfn3F0();
    virtual void vfn3F4();
    virtual void vfn3F8();
    virtual void vfn3FC();
    virtual void vfn400();
    virtual void vfn404();
    virtual void vfn408();
    virtual void vfn40C();
    virtual void vfn410();
    virtual void vfn414();
    virtual void vfn418();
    virtual void vfn41C();
    virtual void vfn420();
    virtual void vfn424();
    virtual void vfn428();
    virtual void vfn42C();
    virtual void vfn430();
    virtual void SetFlagA(int iValue);
    virtual void vfn438();
    virtual void vfn43C();
    virtual void vfn440();
    virtual void vfn444();
    virtual void vfn448();
    virtual void vfn44C();
    virtual void vfn450();
    virtual void vfn454();
    virtual void vfn458();
    virtual void vfn45C();
    virtual void vfn460();
    virtual void vfn464();
    virtual void vfn468();
    virtual void vfn46C();
    virtual void vfn470();
    virtual void vfn474();
    virtual void vfn478();
    virtual void vfn47C();
    virtual void vfn480();
    virtual void vfn484();
    virtual void vfn488();
    virtual void vfn48C();
    virtual void vfn490();
    virtual void vfn494();
    virtual void vfn498();
    virtual void vfn49C();
    virtual void vfn4A0();
    virtual void vfn4A4();
    virtual void vfn4A8();
    virtual void vfn4AC();
    virtual void vfn4B0();
    virtual void vfn4B4();
    virtual void vfn4B8();
    virtual void vfn4BC();
    virtual void vfn4C0();
    virtual void vfn4C4();
    virtual void vfn4C8();
    virtual void vfn4CC();
    virtual void vfn4D0();
    virtual void vfn4D4();
    virtual void vfn4D8();
    virtual void vfn4DC();
    virtual void vfn4E0();
    virtual void vfn4E4();
    virtual void vfn4E8();
    virtual void vfn4EC();
    virtual void vfn4F0();
    virtual void vfn4F4();
    virtual void vfn4F8();
    virtual void vfn4FC();
    virtual void vfn500();
    virtual void vfn504();
    virtual void vfn508();
    virtual void vfn50C();
    virtual void vfn510();
    virtual void vfn514();
    virtual void vfn518();
    virtual void vfn51C();
    virtual void vfn520();
    virtual void vfn524();
    virtual void vfn528();
    virtual void vfn52C();
    virtual void vfn530();
    virtual void vfn534();
    virtual void vfn538();
    virtual void vfn53C();
    virtual void vfn540();
    virtual void vfn544();
    virtual void vfn548();
    virtual void vfn54C();
    virtual void vfn550();
    virtual void vfn554();
    virtual void vfn558();
    virtual void vfn55C();
    virtual void vfn560();
    virtual void vfn564();
    virtual void vfn568();
    virtual void vfn56C();
    virtual void vfn570();
    virtual void vfn574();
    virtual void vfn578();
    virtual void vfn57C();
    virtual void vfn580();
    virtual void vfn584();
    virtual void vfn588();
    virtual void vfn58C();
    virtual void vfn590();
    virtual void vfn594();
    virtual void vfn598();
    virtual void vfn59C();
    virtual void vfn5A0();
    virtual void vfn5A4();
    virtual void vfn5A8();
    virtual void vfn5AC();
    virtual void vfn5B0();
    virtual void vfn5B4();
    virtual void vfn5B8();
    virtual void vfn5BC();
    virtual void vfn5C0();
    virtual void vfn5C4();
    virtual void vfn5C8();
    virtual void vfn5CC();
    virtual void vfn5D0();
    virtual void vfn5D4();
    virtual void vfn5D8();
    virtual void vfn5DC();
    virtual void vfn5E0();
    virtual void vfn5E4();
    virtual void vfn5E8();
    virtual void vfn5EC();
    virtual void vfn5F0();
    virtual void vfn5F4();
    virtual void vfn5F8();
    virtual void vfn5FC();
    virtual void vfn600();
    virtual void vfn604();
    virtual void vfn608();
    virtual void vfn60C();
    virtual void vfn610();
    virtual void vfn614();
    virtual void vfn618();
    virtual void vfn61C();
    virtual void vfn620();
    virtual void vfn624();
    virtual void vfn628();
    virtual void vfn62C();
    virtual void vfn630();
    virtual void vfn634();
    virtual void vfn638();
    virtual void vfn63C();
    virtual void vfn640();
    virtual void vfn644();
    virtual void vfn648();
    virtual void vfn64C();
    virtual void vfn650();
    virtual void vfn654();
    virtual void vfn658();
    virtual void vfn65C();
    virtual void vfn660();
    virtual void vfn664();
    virtual void vfn668();
    virtual void vfn66C();
    virtual void vfn670();
    virtual void vfn674();
    virtual void vfn678();
    virtual void vfn67C();
    virtual void vfn680();
    virtual void vfn684();
    virtual void vfn688();
    virtual void vfn68C();
    virtual void vfn690();
    virtual void vfn694();
    virtual void vfn698();
    virtual void vfn69C();
    virtual void vfn6A0();
    virtual void vfn6A4();
    virtual void vfn6A8();
    virtual void vfn6AC();
    virtual void vfn6B0();
    virtual void vfn6B4();
    virtual void vfn6B8();
    virtual void vfn6BC();
    virtual void vfn6C0();
    virtual void vfn6C4();
    virtual void vfn6C8();
    virtual void vfn6CC();
    virtual void vfn6D0();
    virtual void vfn6D4();
    virtual void vfn6D8();
    virtual void vfn6DC();
    virtual void SetFlagB(int iValue);
};


class D1C30Owner
{
  public:
    Actor* GetActor();
};


// @fnv 0x009d1c30
void __fastcall ResetRangedTask(CombatProcedureAttackRanged* self)
{
    Actor* pkActor = ((D1C30Owner*)self->m_pCombatController)->GetActor();
    ((D1C30Process*)pkActor->GetProcess())->SetFlagB(0);
    ((D1C30Process*)pkActor->GetProcess())->SetFlagA(0);
    self->m_28.Reset();
}

struct FUN_009d1d30_Vec3
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};


FUN_009d1d30_Vec3* __fastcall RangedTrajectory(CombatProcedureAttackRanged*, void*, FUN_009d1d30_Vec3*, unsigned int);
typedef FUN_009d1d30_Vec3* (__thiscall* RangedTrajectoryMethod)(CombatProcedureAttackRanged*, FUN_009d1d30_Vec3*, unsigned int);
#define RangedTrajectoryCall reinterpret_cast<RangedTrajectoryMethod>(RangedTrajectory)

// Writes m_14 to apDst when m_10 is 3, or recomputes m_14 via GetTrajectory for m_10 1 or 2, returning false otherwise.
// @fnv 0x009d1d30
struct RangedVectorArgument { FUN_009d1d30_Vec3* value; };
bool __fastcall GetRangedVector(CombatProcedureAttackRanged* self, RangedVectorArgument apDst, RangedUIntArgument auiArg)
{
    switch (static_cast<int>(self->m_10))
    {
    case 3:
        *apDst.value = (*(FUN_009d1d30_Vec3*)&self->m_14);
        return true;
    case 1:
    case 2: {
        FUN_009d1d30_Vec3 vecTmp;
        (*(FUN_009d1d30_Vec3*)&self->m_14) = *RangedTrajectoryCall(self, &vecTmp, auiArg.value);
        *apDst.value = (*(FUN_009d1d30_Vec3*)&self->m_14);
        return true;
    }
    default:
        return false;
    }
}

extern float DAT_0101e580;
extern double DAT_01023128;
extern char DAT_011f426c;


struct Sub14
{
    unsigned char HasEqualComponents(const void* p);
};

struct Target
{
    float GetTarget();
};

struct Holder04
{
    Target* GetCurrentWeapon();
};

float __cdecl BSMAX_00404010(float a, float b);
bool __cdecl IsWithinAimLimits(Actor* a, void* b, float f1, float f2);


// @fnv 0x009d1de0
bool __fastcall RangedCanShoot(CombatProcedureAttackRanged* self)
{
    if (((Sub14*)&self->m_14)->HasEqualComponents(&DAT_011f426c) != 0)
    {
        return false;
    }
    Actor* actor = GetRangedActor(self);
    Target* target = ((Holder04*)self->m_pCombatController)->GetCurrentWeapon();
    float f2 = BSMAX_00404010(target->GetTarget(), DAT_0101e580) * DAT_01023128;
    float fX = f2;
    bool r9 = IsWithinAimLimits(actor, &self->m_14, f2, fX);
    return r9;
}

struct RPoint
{
    float x, y, z;
    float Heading();
    RPoint operator-(const RPoint&) const;
    float FUN_004a7290() const;
    float FUN_00457990();
    bool Equal(const RPoint&);
    bool IsZero(const RPoint&);
};
struct RAngle
{
    float radians;
    float Heading();
};
struct RAnimation;
struct RActor;
struct RProcess
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual int AttackState();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual bool IsReady();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42c();
    virtual void slot430();
    virtual void slot434();
    virtual unsigned char AttackFlag(RActor*);
    virtual void SetAttackFlag(unsigned char);
};
struct RActor
{
    RProcess* FUN_008d8520();
    bool Actor_IsAttacking();
    unsigned char IsPathing();
    bool TryAttack(int);

    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual RAnimation* GetAnimation();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual RPoint* GetPosition();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual bool IsDead(int);
};
struct RGroup
{
    float EventTime(int);
};
struct RSequence
{
    RGroup* Group();
};
struct RSequenceBase
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual RSequence* GetControllerSequence(int);
};

struct RMap
{
    bool Lookup(unsigned short, RSequenceBase*&);
};
struct RAnimation
{
    unsigned short Animation_GetGroup(int);
    RMap* FUN_00497280();
    int SequenceState(int);
    signed char AnimType(int);
};
struct RProjectile
{
    float Radius();
};
struct RWeaponInfo
{
    RProjectile* Projectile();
};
struct RWeapon
{
    RWeaponInfo* WeaponInfo(RActor*);
    bool TESObjectWEAP_IsAutomaticWeapon();
    bool IsFlagSet();
    float GetTarget();
    float Range();
    unsigned int GetByteAt11D();
    float GetField174Float();
    float GetField178Float();
};
struct RTuning
{
    float TESCombatStyle_GetTargetingFOV();
    float GetFloatAtOffset50() const;
    float GetField54Float();
};
struct RState
{
    bool Active();
    bool GetHasBufferedDetection_0097ee90();
    RAngle AimDirection();
    void RefreshState();
    bool InCover();
    bool HasTarget();
    bool ValidPoint(RPoint*);
    void SetBlocked(int);
    unsigned char Blocked();
    void SetProjectile(RProjectile*);
};
struct RContext
{
    RState* State();
    RContext* Allies();
    RWeapon* Weapon();
    RTuning* Tuning();
    unsigned char Disabled();
    void SetClose(char);
    void SetAim(unsigned char);
    bool Friendly(RActor*);
};
struct RManager
{
    void Notify(RContext*, int, int, int);
};
struct RWorld
{
    bool ProjectileClear(RActor*, RProjectile*, RPoint*, float);
};
extern RManager* DAT_011f1708;
extern RWorld* BGSSaveLoadGlobalDataWorldspacePtr;
struct RSetting
{
    float* Float();
};
extern RSetting DAT_011ceef0, DAT_011cf21c, originalRuntimeFloatSetting387, originalRuntimeFloatSetting428,
    originalRuntimeFloatSetting358;
extern RPoint NiPoint3_ZERO;
extern float rangedMax;
bool __cdecl TargetCone(RActor*, RPoint*, float, float);
void __cdecl WeaponRanges(RContext*, RWeapon*, float*, float*, float*);
int __cdecl GetType(unsigned short);
float __cdecl DirectionLength(RPoint*);
bool __cdecl IsAttackAnim(unsigned short);
void __cdecl MuzzlePosition(RPoint*, RActor*);
bool __cdecl TraceShot(RActor*, RWeaponInfo*, float, RPoint, RPoint, RPoint*, RActor**, float*);
float __cdecl ShotTravel(RWeaponInfo*, RPoint, RPoint, int, float);
float __cdecl RandomFloat(float, float);
bool __cdecl ProjectileNeedsEvent(RProjectile*);
void __fastcall StartRangedAttack(CombatProcedureAttackRanged*, RangedBoolArgument);
void __fastcall RangedLook(CombatProcedureAttackRanged*, void*, const RPoint&, unsigned char);
void __fastcall RangedClearLook(CombatProcedureAttackRanged*);
typedef void (__thiscall* RangedStartMethod)(CombatProcedureAttackRanged*, bool);
typedef void (__thiscall* RangedLookMethod)(CombatProcedureAttackRanged*, const RPoint&, unsigned char);
#define RangedStartCall reinterpret_cast<RangedStartMethod>(StartRangedAttack)
#define RangedLookCall reinterpret_cast<RangedLookMethod>(RangedLook)

struct RHitPoint : RPoint
{
    RHitPoint();
};
// @fnv 0x009d0a30
void __fastcall UpdateRangedAttack(CombatProcedureAttackRanged* self)
{
    RActor* actor = (RActor*)GetRangedActor(self);
    RActor* target = (RActor*)GetRangedTarget(self);
    RState* combat2 = ((RContext*)self->m_pCombatController)->State();
    RContext* allies8 = ((RContext*)self->m_pCombatController)->Allies();
    unsigned int attack20 = 255;
    RWeapon* weapon0 = ((RContext*)self->m_pCombatController)->Weapon();
    RAnimation* animation0 = actor->GetAnimation();
    if (!weapon0 || !animation0 || !weapon0->WeaponInfo(actor))
    {
        self->CombatProcedure_SetFailed("Missing either weapon, animation, or weapon projectile");
        return;
    }
    float fov16 = ((RContext*)self->m_pCombatController)->Tuning()->TESCombatStyle_GetTargetingFOV();
    if (fov16 > 0.0 && target &&
        !TargetCone(actor, target->GetPosition(), float(fov16 * 0.01745329238474369), 6.2831854820251465f))
    {
        self->CombatProcedure_SetFailed("Target outside targeting FOV");
        return;
    }
    RWeaponInfo* info1 = weapon0->WeaponInfo(actor);
    bool automatic77 = weapon0->TESObjectWEAP_IsAutomaticWeapon();
    bool burstWeapon = automatic77 || weapon0->IsFlagSet();
    bool tooClose34 = false;
    RPoint destination;
    RangedTrajectoryCall(self, (FUN_009d1d30_Vec3*)&destination, 0);
    bool ready = actor->FUN_008d8520()->IsReady() || actor->Actor_IsAttacking();
    if (((RContext*)self->m_pCombatController)->Disabled())
        ready = false;
    if (self->m_10 != 0 && !ready)
    {
        ResetRangedTask(self);
        self->m_10 = 0;
    }
    if (ready)
    {
        float minRange6 = 0.0f;
        float idealRange = 0.0f;
        float maxRange = 0.0f;
        WeaponRanges(((RContext*)self->m_pCombatController), weapon0, &minRange6, &idealRange, &maxRange);
        RPoint targetPosition2 = destination;
        if (target)
            targetPosition2.z = target->GetPosition()->z;
        RPoint rangeDelta = targetPosition2 - *actor->GetPosition();
        float distance = rangeDelta.FUN_004a7290();
        if (distance > maxRange * maxRange)
            ready = false;
        if (distance < minRange6 * minRange6)
            tooClose34 = true;
    }
    if (combat2->Active())
        (*(RPoint*)&self->m_14) = destination;

    if (combat2->Active() && combat2->GetHasBufferedDetection_0097ee90() && ready)
    {
        switch (self->m_10)
        {
        case 1:
            if (burstWeapon)
            {
                if (!self->m_28.IsRunning() && combat2->AimDirection().Heading() != -rangedMax)
                {
                    float duration1 = *DAT_011ceef0.Float();
                    unsigned short group = animation0->Animation_GetGroup(4);
                    if (::GetType(group) == 80 || ::GetType(group) == 86)
                    {
                        RSequenceBase* sequence;
                        if (animation0->FUN_00497280()->Lookup(group, sequence))
                        {
                            RGroup* animGroup0 = sequence->GetControllerSequence(-1)->Group();
                            float start = animGroup0->EventTime(0);
                            float end = animGroup0->EventTime(1);
                            duration1 += end - start;
                        }
                    }
                    self->m_28.Start(duration1);
                }
                if (self->m_28.IsRunning() && self->m_28.Expired())
                {
                    ResetRangedTask(self);
                    self->m_30.Start(*DAT_011cf21c.Float());
                    self->m_10 = 2;
                }
            }
            break;
        case 2:
            if (self->m_30.Expired())
            {
                combat2->RefreshState();
                RangedStartCall(self, automatic77);
                self->m_10 = 1;
            }
            break;
        default:
            self->m_40.Reset();
            RangedStartCall(self, automatic77);
            self->m_10 = 1;
            break;
        }
    }
    else
    {
        switch (self->m_10)
        {
        case 1:
            RangedStartCall(self, automatic77);
            self->m_10 = 3;
            self->m_40.Start(2.0f);
            break;
        case 2:
            if (self->m_30.Expired())
            {
                RangedStartCall(self, automatic77);
                self->m_10 = 3;
                self->m_40.Start(2.0f);
            }
            break;
        case 3:
            if (self->m_40.Expired())
            {
                ResetRangedTask(self);
                self->m_10 = 0;
            }
            break;
        case 0:
            if (ready && !self->m_40.Expired())
            {
                RangedStartCall(self, automatic77);
                self->m_10 = 3;
            }
            break;
        }
    }
    if (target && combat2->GetHasBufferedDetection_0097ee90())
        DAT_011f1708->Notify(((RContext*)self->m_pCombatController), 2, 0, 0);
    bool close2 = false;
    if (target)
    {
        float nearRange = *originalRuntimeFloatSetting387.Float() * weapon0->Range();
        RPoint nearDelta20 = *actor->GetPosition() - *target->GetPosition();
        if (nearDelta20.FUN_004a7290() > nearRange * nearRange)
            close2 = true;
    }
    ((RContext*)self->m_pCombatController)->SetClose(close2);
    if (weapon0->GetTarget() > 0.0)
    {
        float angle = float(weapon0->GetTarget() * 0.01745329238474369);
        if (!actor->IsPathing())
            angle *= *originalRuntimeFloatSetting428.Float();
        if ((*(RPoint*)&self->m_14).Equal(NiPoint3_ZERO) && TargetCone(actor, &(*(RPoint*)&self->m_14), angle, rangedMax))
            ((RContext*)self->m_pCombatController)->SetAim(4);
        else
            ((RContext*)self->m_pCombatController)->SetAim(0);
    }
    if (self->m_10 == 0)
    {
        if (target && !combat2->InCover() && (combat2->Active() || (combat2->HasTarget() && combat2->GetHasBufferedDetection_0097ee90())))
        {
            if ((*(RPoint*)&self->m_14).Equal(NiPoint3_ZERO) || combat2->ValidPoint(&(*(RPoint*)&self->m_14)))
                RangedLookCall(self, (*(RPoint*)&self->m_14), 2);
            else
                RangedClearLook(self);
        }
        else
            RangedClearLook(self);
        return;
    }
    if ((*(RPoint*)&self->m_14).IsZero(NiPoint3_ZERO))
        (*(RPoint*)&self->m_14) = destination;
    if ((*(RPoint*)&self->m_14).Equal(NiPoint3_ZERO))
        RangedLookCall(self, (*(RPoint*)&self->m_14), 4);
    if (self->m_10 == 2)
        return;
    if (!RangedCanShoot(self) && !tooClose34)
        return;
    if (!self->m_38.Expired())
        return;
    bool fire24 = false;
    unsigned char attackFlag12 = 1;
    if (automatic77)
    {
        bool canAttack = true;
        attackFlag12 = actor->FUN_008d8520()->AttackFlag(actor);
        if (IsAttackAnim(animation0->Animation_GetGroup(4)))
        {
            int sequenceState = animation0->SequenceState(4);
            if (sequenceState < 1 || sequenceState >= 2)
                canAttack = false;
        }
        if (canAttack && attackFlag12)
            fire24 = true;
    }
    else
    {
        switch (actor->FUN_008d8520()->AttackState())
        {
        case 4:
            if (animation0->SequenceState(4) == 3)
                fire24 = true;
            break;
        case -1:
            fire24 = true;
            break;
        }
    }
    if (!fire24)
        return;

    RHitPoint hitPoint2;
    RActor* hit16 = 0;
    RActor* hitActor9 = 0;
    float fraction41 = 0.0f;
    RPoint muzzle23;
    MuzzlePosition(&muzzle23, actor);
    bool collision25 = TraceShot(actor, info1, 0.0f, muzzle23, destination, &hitPoint2, &hit16, &fraction41);
    if (collision25)
    {
        bool blockedShot = false;
        switch (self->m_10)
        {
        case 1:
            if (hit16 && hit16->IsActor())
            {
                hitActor9 = hit16;
                if (hitActor9 == (RActor*)GetRangedTarget(self) || allies8->Friendly(hitActor9))
                    blockedShot = true;
            }
            if (!blockedShot)
            {
                RProjectile* explosive = info1->Projectile();
                if (explosive)
                {
                    RPoint hitDelta0 = hitPoint2 - destination;
                    float hitDistance = hitDelta0.FUN_00457990();
                    if (hitDistance <= explosive->Radius())
                        blockedShot = true;
                }
            }
            break;
        case 3:
            if (!hit16 || !hit16->IsActor())
            {
                if (fraction41 > 0.5)
                    blockedShot = true;
            }
            else if (hit16 && hit16->IsActor() && !hit16->IsDead(0) && allies8->Friendly(hit16))
                blockedShot = true;
            if (!blockedShot)
            {
                self->m_10 = 0;
                ResetRangedTask(self);
                self->m_40.Reset();
                return;
            }
            break;
        }
        if (blockedShot)
            ((RContext*)self->m_pCombatController)->State()->SetBlocked(0);
        else
        {
            if (!((RContext*)self->m_pCombatController)->State()->Blocked())
                ((RContext*)self->m_pCombatController)->State()->SetBlocked(1);
            return;
        }
    }
    RProjectile* projectile = info1->Projectile();
    if (projectile)
    {
        RPoint impact = (*(RPoint*)&self->m_14);
        if (collision25)
            impact = hitPoint2;
        float travel = ShotTravel(info1, muzzle23, impact, 0, 0.0f);
        if (!BGSSaveLoadGlobalDataWorldspacePtr->ProjectileClear(actor, projectile, &impact, travel))
        {
            fire24 = false;
            if (!self->m_20.IsRunning())
                self->m_20.Start(*originalRuntimeFloatSetting358.Float());
            else if (self->m_20.Expired())
                ((RContext*)self->m_pCombatController)->State()->SetProjectile(projectile);
        }
        else
        {
            ((RContext*)self->m_pCombatController)->State()->SetProjectile(0);
            self->m_20.Reset();
        }
    }
    if (fire24)
    {
        switch (animation0->AnimType(0))
        {
        case 51:
            attack20 = 38;
            break;
        case 52:
            attack20 = 44;
            break;
        case 53:
            attack20 = 50;
            break;
        case 54:
            attack20 = 56;
            break;
        case 55:
            attack20 = 62;
            break;
        case 56:
            attack20 = 68;
            break;
        case 108:
            attack20 = 26;
            break;
        default:
            if (weapon0 && weapon0->GetByteAt11D() != 255)
                attack20 = weapon0->GetByteAt11D();
            else
                attack20 = 32;
            break;
        }
        actor->FUN_008d8520()->SetAttackFlag(attackFlag12);
        bool attacked = actor->TryAttack(attack20);
        if (attacked && !automatic77)
        {
            float minDelay = weapon0->GetField174Float() * ((RContext*)self->m_pCombatController)->Tuning()->GetFloatAtOffset50();
            float maxDelay = weapon0->GetField178Float() * ((RContext*)self->m_pCombatController)->Tuning()->GetField54Float();
            self->m_38.Start(RandomFloat(minDelay, maxDelay));
        }
        if (projectile && ProjectileNeedsEvent(projectile))
            DAT_011f1708->Notify(((RContext*)self->m_pCombatController), 2, 4, 1);
    }
}

class Process9D1
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
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void vfn288();
    virtual void vfn28C();
    virtual void vfn290();
    virtual void vfn294();
    virtual void vfn298();
    virtual void vfn29C();
    virtual void vfn2A0();
    virtual void vfn2A4();
    virtual void vfn2A8();
    virtual void vfn2AC();
    virtual void vfn2B0();
    virtual void vfn2B4();
    virtual void vfn2B8();
    virtual void vfn2BC();
    virtual void vfn2C0();
    virtual void vfn2C4();
    virtual void vfn2C8();
    virtual void vfn2CC();
    virtual void vfn2D0();
    virtual void vfn2D4();
    virtual void vfn2D8();
    virtual void vfn2DC();
    virtual void vfn2E0();
    virtual void vfn2E4();
    virtual void vfn2E8();
    virtual void vfn2EC();
    virtual void vfn2F0();
    virtual void vfn2F4();
    virtual void vfn2F8();
    virtual void vfn2FC();
    virtual void vfn300();
    virtual void vfn304();
    virtual void vfn308();
    virtual void vfn30C();
    virtual void vfn310();
    virtual void vfn314();
    virtual void vfn318();
    virtual void vfn31C();
    virtual void vfn320();
    virtual void vfn324();
    virtual void vfn328();
    virtual void vfn32C();
    virtual void vfn330();
    virtual void vfn334();
    virtual void vfn338();
    virtual void vfn33C();
    virtual void vfn340();
    virtual void vfn344();
    virtual void vfn348();
    virtual void vfn34C();
    virtual void vfn350();
    virtual void vfn354();
    virtual void vfn358();
    virtual void vfn35C();
    virtual void vfn360();
    virtual void vfn364();
    virtual void vfn368();
    virtual void vfn36C();
    virtual void vfn370();
    virtual void vfn374();
    virtual void vfn378();
    virtual void vfn37C();
    virtual void vfn380();
    virtual void vfn384();
    virtual void vfn388();
    virtual void vfn38C();
    virtual void vfn390();
    virtual void vfn394();
    virtual void vfn398();
    virtual void vfn39C();
    virtual void vfn3A0();
    virtual void vfn3A4();
    virtual void vfn3A8();
    virtual void vfn3AC();
    virtual void vfn3B0();
    virtual void vfn3B4();
    virtual void vfn3B8();
    virtual void vfn3BC();
    virtual void vfn3C0();
    virtual void vfn3C4();
    virtual void vfn3C8();
    virtual void vfn3CC();
    virtual void vfn3D0();
    virtual void vfn3D4();
    virtual void vfn3D8();
    virtual void vfn3DC();
    virtual void vfn3E0();
    virtual void vfn3E4();
    virtual void vfn3E8();
    virtual void vfn3EC();
    virtual void vfn3F0();
    virtual void vfn3F4();
    virtual void vfn3F8();
    virtual void vfn3FC();
    virtual void vfn400();
    virtual void vfn404();
    virtual void vfn408();
    virtual void vfn40C();
    virtual void vfn410();
    virtual void vfn414();
    virtual void vfn418();
    virtual void vfn41C();
    virtual void vfn420();
    virtual void vfn424();
    virtual void vfn428();
    virtual void vfn42C();
    virtual void vfn430();
    virtual void SetUpdateFlag(int iFlag);
    virtual void vfn438();
    virtual void vfn43C();
    virtual void vfn440();
    virtual void vfn444();
    virtual void vfn448();
    virtual void vfn44C();
    virtual void vfn450();
    virtual void vfn454();
    virtual void vfn458();
    virtual void vfn45C();
    virtual void vfn460();
    virtual void vfn464();
    virtual void vfn468();
    virtual void vfn46C();
    virtual void vfn470();
    virtual void vfn474();
    virtual void vfn478();
    virtual void vfn47C();
    virtual void vfn480();
    virtual void vfn484();
    virtual void vfn488();
    virtual void vfn48C();
    virtual void vfn490();
    virtual void vfn494();
    virtual void vfn498();
    virtual void vfn49C();
    virtual void vfn4A0();
    virtual void vfn4A4();
    virtual void vfn4A8();
    virtual void vfn4AC();
    virtual void vfn4B0();
    virtual void vfn4B4();
    virtual void vfn4B8();
    virtual void vfn4BC();
    virtual void vfn4C0();
    virtual void vfn4C4();
    virtual void vfn4C8();
    virtual void vfn4CC();
    virtual void vfn4D0();
    virtual void vfn4D4();
    virtual void vfn4D8();
    virtual void vfn4DC();
    virtual void vfn4E0();
    virtual void vfn4E4();
    virtual void vfn4E8();
    virtual void vfn4EC();
    virtual void vfn4F0();
    virtual void vfn4F4();
    virtual void vfn4F8();
    virtual void vfn4FC();
    virtual void vfn500();
    virtual void vfn504();
    virtual void vfn508();
    virtual void vfn50C();
    virtual void vfn510();
    virtual void vfn514();
    virtual void vfn518();
    virtual void vfn51C();
    virtual void vfn520();
    virtual void vfn524();
    virtual void vfn528();
    virtual void vfn52C();
    virtual void vfn530();
    virtual void vfn534();
    virtual void vfn538();
    virtual void vfn53C();
    virtual void vfn540();
    virtual void vfn544();
    virtual void vfn548();
    virtual void vfn54C();
    virtual void vfn550();
    virtual void vfn554();
    virtual void vfn558();
    virtual void vfn55C();
    virtual void vfn560();
    virtual void vfn564();
    virtual void vfn568();
    virtual void vfn56C();
    virtual void vfn570();
    virtual void vfn574();
    virtual void vfn578();
    virtual void vfn57C();
    virtual void vfn580();
    virtual void vfn584();
    virtual void vfn588();
    virtual void vfn58C();
    virtual void vfn590();
    virtual void vfn594();
    virtual void vfn598();
    virtual void vfn59C();
    virtual void vfn5A0();
    virtual void vfn5A4();
    virtual void vfn5A8();
    virtual void vfn5AC();
    virtual void vfn5B0();
    virtual void vfn5B4();
    virtual void vfn5B8();
    virtual void vfn5BC();
    virtual void vfn5C0();
    virtual void vfn5C4();
    virtual void vfn5C8();
    virtual void vfn5CC();
    virtual void vfn5D0();
    virtual void vfn5D4();
    virtual void vfn5D8();
    virtual void vfn5DC();
    virtual void vfn5E0();
    virtual void vfn5E4();
    virtual void vfn5E8();
    virtual void vfn5EC();
    virtual void vfn5F0();
    virtual void vfn5F4();
    virtual void vfn5F8();
    virtual void vfn5FC();
    virtual void vfn600();
    virtual void vfn604();
    virtual void vfn608();
    virtual void vfn60C();
    virtual void vfn610();
    virtual void vfn614();
    virtual void vfn618();
    virtual void vfn61C();
    virtual void vfn620();
    virtual void vfn624();
    virtual void vfn628();
    virtual void vfn62C();
    virtual void vfn630();
    virtual void vfn634();
    virtual void vfn638();
    virtual void vfn63C();
    virtual void vfn640();
    virtual void vfn644();
    virtual void vfn648();
    virtual void vfn64C();
    virtual void vfn650();
    virtual void vfn654();
    virtual void vfn658();
    virtual void vfn65C();
    virtual void vfn660();
    virtual void vfn664();
    virtual void vfn668();
    virtual void vfn66C();
    virtual void vfn670();
    virtual void vfn674();
    virtual void vfn678();
    virtual void vfn67C();
    virtual void vfn680();
    virtual void vfn684();
    virtual void vfn688();
    virtual void vfn68C();
    virtual void vfn690();
    virtual void vfn694();
    virtual void vfn698();
    virtual void vfn69C();
    virtual void vfn6A0();
    virtual void vfn6A4();
    virtual void vfn6A8();
    virtual void vfn6AC();
    virtual void vfn6B0();
    virtual void vfn6B4();
    virtual void vfn6B8();
    virtual void vfn6BC();
    virtual void vfn6C0();
    virtual void vfn6C4();
    virtual void vfn6C8();
    virtual void vfn6CC();
    virtual void vfn6D0();
    virtual void vfn6D4();
    virtual void vfn6D8();
    virtual void vfn6DC();
    virtual void SetActive(bool bActive);
};


class Mobile9D1
{
  public:
    Actor* GetActor();
};


// Sets the mobile actor's process active state, sets update flag 1, and resets the timer.
// @fnv 0x009d1bc0
void __fastcall StartRangedAttack(CombatProcedureAttackRanged* self, RangedBoolArgument bActive)
{
    Actor* pkActor = ((Mobile9D1*)self->m_pCombatController)->GetActor();
    ((Process9D1*)pkActor->GetProcess())->SetActive(bActive.value);
    ((Process9D1*)pkActor->GetProcess())->SetUpdateFlag(1);
    self->m_28.Reset();
}


// Initializes the base class, sets m_10 to 0, and copies a NiPoint3 from DAT_011f426c into m_14.
// @fnv 0x009d0890
CombatProcedureAttackRanged::CombatProcedureAttackRanged()
    : CombatProcedure(), m_10(0), m_14(*reinterpret_cast<const NiPoint3*>(&DAT_011f426c))
{}

struct RangedVec
{
    float x, y, z;
    bool FUN_00439090(const void*);
};
struct RangedActor
{
    float GetAdjustedAngle();
    unsigned char IsPathing();
};
struct RangedDisplay
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void __cdecl Print(int, int, const char*, ...);
};
struct RangedSetting
{
    float* Setting_Float_00403e20();
};
extern RangedSetting DAT_011cfb84;
void __cdecl CombatUtilities_GetAngleToProjectedPoint(RangedVec*, RangedActor*, RangedVec);
float __cdecl FUN_004b1480(float);
float __cdecl GetAngleDelta(float, float, float*);
float __cdecl FUN_00408840(float);
// Prints the ranged combat state, timer values, target location and weapon firing arc to the debug display.
// @fnv 0x009d1e80
struct RangedDisplayArgument { RangedDisplay* value; };
void __fastcall PrintRangedDebugInfo(CombatProcedureAttackRanged* self, RangedDisplayArgument display, RangedIntArgument iX, RangedIntArgument iY)
{
    RangedActor* actor = (RangedActor*)GetRangedActor(self);
    switch (self->m_10)
    {
    case 0:
        display.value->Print(iX.value, iY.value, "IDLE");
        break;
    case 1:
        display.value->Print(iX.value, iY.value, "FIRING");
        if (self->m_28.IsRunning())
            display.value->Print(iX.value, iY.value, "Firing Timer: %.02f/%.02f", GetTimeoutTimerElapsed(&self->m_28), self->m_28.CombatTimer_GetTargetTime());
        if (GetRangedTarget(self))
            display.value->Print(iX.value, iY.value, "Target location: %.02f, %.02f, %.02f", (*(RangedVec*)&self->m_14).x, (*(RangedVec*)&self->m_14).y, (*(RangedVec*)&self->m_14).z);
        if (!self->m_38.Expired())
            display.value->Print(iX.value, iY.value, "Firing Delay Timer: %.02f/%.02f", GetTimeoutTimerElapsed(&self->m_38), self->m_38.CombatTimer_GetTargetTime());
        break;
    case 2:
        display.value->Print(iX.value, iY.value, "COOLDOWN");
        display.value->Print(iX.value, iY.value, "Cooldown Timer: %.02f/%.02f", GetTimeoutTimerElapsed(&self->m_30), self->m_30.CombatTimer_GetTargetTime());
        break;
    case 3:
        display.value->Print(iX.value, iY.value, "SUPPRESSIVE_FIRE");
        display.value->Print(iX.value, iY.value, "Suppression location: %.02f, %.02f, %.02f", (*(RangedVec*)&self->m_14).x, (*(RangedVec*)&self->m_14).y, (*(RangedVec*)&self->m_14).z);
        display.value->Print(iX.value, iY.value, "Suppressive Fire Timer: %.02f/%.02f", GetTimeoutTimerElapsed(&self->m_40), self->m_40.CombatTimer_GetTargetTime());
        if (!self->m_38.Expired())
            display.value->Print(iX.value, iY.value, "Firing Delay Timer: %.02f/%.02f", GetTimeoutTimerElapsed(&self->m_38), self->m_38.CombatTimer_GetTargetTime());
        break;
    }
    if (self->m_20.IsRunning())
        display.value->Print(iX.value, iY.value, "Explosive Projectile Blocked Timer: %.02f/%.02f", GetTimeoutTimerElapsed(&self->m_20),
                       self->m_20.CombatTimer_GetTargetTime());
    Target* target = ((Holder04*)self->m_pCombatController)->GetCurrentWeapon();
    if ((*(RangedVec*)&self->m_14).FUN_00439090(&DAT_011f426c) && target && target->GetTarget() > 0.0)
    {
        RangedVec unused;
        CombatUtilities_GetAngleToProjectedPoint(&unused, actor, (*(RangedVec*)&self->m_14));
        float limit = actor->GetAdjustedAngle();
        unused.z = FUN_004b1480(unused.z);
        float arc = 0.0f;
        float heading = FUN_00408840(GetAngleDelta(limit, unused.z, &arc));
        float direction = target->GetTarget();
        if (!actor->IsPathing())
        {
            direction *= *DAT_011cfb84.Setting_Float_00403e20();
            display.value->Print(iX.value, iY.value, "Weapon firing arc: ( %.2f/%.2f ) degrees (Stationary)",
                           heading * 2.0 * 57.2957763671875, direction);
        }
        else
        {
            display.value->Print(iX.value, iY.value, "Weapon firing arc: ( %.2f/%.2f ) degrees (Moving)",
                           heading * 2.0 * 57.2957763671875, direction);
        }
    }
}

struct Target2
{
    int GetOrFallback(Actor* apActor);
};
struct Holder2
{
    Target2* GetCurrentWeapon();
};
void __cdecl ComputeTrajectory(FUN_009d1d30_Vec3* apOut, Actor* apA, Actor* apB, unsigned int auiArg, int aiVal,
                               float afVal, int aiFlag);
// Computes and returns a vector using ComputeTrajectory, or returns the vector at DAT_011f426c if FUN_00996e00 returns null.
// @fnv 0x009d1c90
FUN_009d1d30_Vec3 __fastcall GetRangedTrajectory(CombatProcedureAttackRanged* self, RangedUIntArgument auiArg)
{
    Actor* pActor2;
    FUN_009d1d30_Vec3 kResult3;
    Target2* pTarget;

    pActor2 = GetRangedTarget(self);
    if (!pActor2)
        return *(FUN_009d1d30_Vec3*)&DAT_011f426c;
    pTarget = ((Holder2*)self->m_pCombatController)->GetCurrentWeapon();
    ComputeTrajectory(&kResult3, GetRangedActor(self), pActor2, auiArg.value, pTarget->GetOrFallback(GetRangedActor(self)), 0.0f, 0);
    return kResult3;
}
