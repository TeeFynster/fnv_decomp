
// src/fallout/magic/turnundeadeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/turnundeadeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/hkVector4.h"

NiPoint3& __cdecl SetNiPoint3FromHkVector4(NiPoint3&, hkVector4 const&);
// Havok accessor bound to 0x004ae750 (bhkWorldObject in telekinesiseffect.cpp); ScriptLocals::GetLocalData is 0x00541c80.
struct HavokObjectAccessor
{
    void* GetHavokObject();
};
struct TurnUndeadEffect : HavokObjectAccessor
{
    void ApplyTurnUndeadEffect(MagicCaster* apCaster);
};
// Gets a Havok object and, if present, converts its hkVector4 at offset 0x30 into the caster's NiPoint3.
// @fnv 0x0082aa50
void TurnUndeadEffect::ApplyTurnUndeadEffect(MagicCaster* apCaster)
{
    void* bresult = GetHavokObject();
    if (bresult)
        SetNiPoint3FromHkVector4(*(NiPoint3*)apCaster, *(hkVector4 const*)((char*)bresult + 0x30));
}

extern unsigned int _data_011c16bc;
void* __cdecl operator new(unsigned int);


class FUN_0082b370 : public ActiveEffect
{
  public:
    bool m_bEffectFlag;

    FUN_0082b370(MagicCaster*, MagicItem*, EffectItem*);

    ActiveEffect* TurnUndeadEffect_Copy();
};

// @fnv 0x0082b3b0
// src: XBOX_PDB 0x0082b3b0
ActiveEffect* FUN_0082b370::TurnUndeadEffect_Copy()
{
    FUN_0082b370* presult = new FUN_0082b370(m_pEffectInstance, pSpell, pEffect);
    presult->m_bEffectFlag = m_bEffectFlag;
    CopyData(presult);
    return presult;
}

class Reference
{
  public:
    Actor* FUN_00822b40();
};
extern char _data_011a0ef8;
extern char _data_011a106c;
bool __cdecl MagicFormulas_CheckTargetLevelMagnitude(unsigned short value, float strength);
int __cdecl FUN_00ec43fb(Reference* reference, int flag, void* first, void* second, int extra);
class EffectEvaluator
{
  public:
    float GetFloatAtOffset1C();
    bool TurnUndeadEffect_CheckTarget(Reference* reference);
};
// @fnv 0x0082b460
// src: XBOX_PDB 0x0082b460
bool EffectEvaluator::TurnUndeadEffect_CheckTarget(Reference* reference)
{
    Actor* actor = reference ? reference->FUN_00822b40() : 0;
    if (actor != 0)
    {
        if (!actor->HasHealth(0) && !actor->GetIsDying())
        {
            if (MagicFormulas_CheckTargetLevelMagnitude(actor->GetLevel_0087f9f0(), GetFloatAtOffset1C()))
            {
                int result = FUN_00ec43fb(reference, 0, &_data_011a0ef8, &_data_011a106c, 0);
                if (result != 0)
                {
                }
                else if (actor->Actor_IsReanimated())
                    return true;
            }
        }
    }
rejected:
    return false;
}

struct O
{
    int FUN_00822b40();
    int FUN_00815410();
    void FUN_008d0600();
};

struct C
{
    int FUN_0059bb30();
    int FUN_0045cd60();
    void TurnUndeadEffect_Start();
};

struct D
{
    int FUN_0045cd60();
};

struct V
{
    virtual int v0();
};
// @fnv 0x0082b530
// src: XBOX_PDB 0x0082b530
void C::TurnUndeadEffect_Start()
{
    int b;
    int a;
    b = FUN_0059bb30() ? ((O*)FUN_0059bb30())->FUN_00822b40() : 0;
    a = FUN_0045cd60() ? ((O*)FUN_0045cd60())->FUN_00815410() : 0;
    if (b != 0 && a != 0 && (*(int(__thiscall**)(int))(*(int**)b + 266))(b) != 0)
    {
        ((O*)(*(int(__thiscall**)(int, int, int))(*(int**)b + 266))(b, a, 0))->FUN_008d0600();
        *(char*)((char*)this + 72) = 1;
    }
}

class B82B5E0Package;

class B82B5E0Process
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual void VFunc10C();
    virtual void VFunc110();
    virtual void VFunc114();
    virtual void VFunc118();
    virtual void VFunc11C();
    virtual void VFunc120();
    virtual void VFunc124();
    virtual void VFunc128();
    virtual void VFunc12C();
    virtual void VFunc130();
    virtual void VFunc134();
    virtual void VFunc138();
    virtual void VFunc13C();
    virtual void VFunc140();
    virtual void VFunc144();
    virtual void VFunc148();
    virtual void VFunc14C();
    virtual void VFunc150();
    virtual void VFunc154();
    virtual void VFunc158();
    virtual void VFunc15C();
    virtual void VFunc160();
    virtual void VFunc164();
    virtual void VFunc168();
    virtual void VFunc16C();
    virtual void VFunc170();
    virtual void VFunc174();
    virtual void VFunc178();
    virtual void VFunc17C();
    virtual void VFunc180();
    virtual void VFunc184();
    virtual void VFunc188();
    virtual void VFunc18C();
    virtual void VFunc190();
    virtual void VFunc194();
    virtual void VFunc198();
    virtual void VFunc19C();
    virtual void VFunc1A0();
    virtual void VFunc1A4();
    virtual void VFunc1A8();
    virtual void VFunc1AC();
    virtual void VFunc1B0();
    virtual void VFunc1B4();
    virtual void VFunc1B8();
    virtual void VFunc1BC();
    virtual void VFunc1C0();
    virtual void VFunc1C4();
    virtual void VFunc1C8();
    virtual void VFunc1CC();
    virtual void VFunc1D0();
    virtual void VFunc1D4();
    virtual void VFunc1D8();
    virtual void VFunc1DC();
    virtual void VFunc1E0();
    virtual void VFunc1E4();
    virtual void VFunc1E8();
    virtual void VFunc1EC();
    virtual void VFunc1F0();
    virtual void VFunc1F4();
    virtual void VFunc1F8();
    virtual void VFunc1FC();
    virtual void VFunc200();
    virtual void VFunc204();
    virtual void VFunc208();
    virtual void VFunc20C();
    virtual void VFunc210();
    virtual void VFunc214();
    virtual void VFunc218();
    virtual void VFunc21C();
    virtual void VFunc220();
    virtual void VFunc224();
    virtual void VFunc228();
    virtual void VFunc22C();
    virtual void VFunc230();
    virtual void VFunc234();
    virtual void VFunc238();
    virtual void VFunc23C();
    virtual void VFunc240();
    virtual void VFunc244();
    virtual void VFunc248();
    virtual void VFunc24C();
    virtual void VFunc250();
    virtual void VFunc254();
    virtual void VFunc258();
    virtual void VFunc25C();
    virtual void VFunc260();
    virtual void VFunc264();
    virtual void VFunc268();
    virtual void VFunc26C();
    virtual void VFunc270();
    virtual void VFunc274();
    virtual void VFunc278();
    virtual void VFunc27C();
    virtual void VFunc280();
    virtual void VFunc284();
    virtual void VFunc288();
    virtual void VFunc28C();
    virtual void VFunc290();
    virtual void VFunc294();
    virtual void VFunc298();
    virtual void VFunc29C();
    virtual void VFunc2A0();
    virtual void VFunc2A4();
    virtual void VFunc2A8();
    virtual void VFunc2AC();
    virtual void VFunc2B0();
    virtual void VFunc2B4();
    virtual void VFunc2B8();
    virtual void VFunc2BC();
    virtual void VFunc2C0();
    virtual void VFunc2C4();
    virtual void VFunc2C8();
    virtual void VFunc2CC();
    virtual void VFunc2D0();
    virtual void VFunc2D4();
    virtual void VFunc2D8();
    virtual void VFunc2DC();
    virtual void VFunc2E0();
    virtual void VFunc2E4();
    virtual void VFunc2E8();
    virtual void VFunc2EC();
    virtual void VFunc2F0();
    virtual void VFunc2F4();
    virtual void VFunc2F8();
    virtual void VFunc2FC();
    virtual void VFunc300();
    virtual void VFunc304();
    virtual void VFunc308();
    virtual void VFunc30C();
    virtual void VFunc310();
    virtual void VFunc314();
    virtual void VFunc318();
    virtual void VFunc31C();
    virtual void VFunc320();
    virtual void VFunc324();
    virtual void VFunc328();
    virtual void VFunc32C();
    virtual void VFunc330();
    virtual void VFunc334();
    virtual void VFunc338();
    virtual void StartPackage(Actor* pkActor, B82B5E0Package* pkPackage, bool bA, int iB, int iC, int iD, int iE,
                              int iF, int iG, int iH, int iI, bool bJ, int iK);
};


class B82B5E0ActorHandle
{
  public:
    Actor* Get();
};

class B82B5E0PackageHandle
{
  public:
    B82B5E0Package* Get();
};

class B82B5E0Request
{
  public:
    B82B5E0ActorHandle* GetActorHandle();
    B82B5E0PackageHandle* GetPackageHandle();
    void ApplyPackageToActor();

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
    bool m_bModifierActive;
};

// If the request is active, resolves the actor and package handles and, when the actor passes FUN_00493bb0, sets the package and starts it on the actor's process.
// @fnv 0x0082b5e0
void B82B5E0Request::ApplyPackageToActor()
{
    if (!m_bModifierActive)
        return;
    Actor* pkActor = GetActorHandle() ? GetActorHandle()->Get() : 0;
    B82B5E0Package* pkPackage3 = GetPackageHandle() ? GetPackageHandle()->Get() : 0;
    if (pkActor && pkActor->Actor_IsInCombat())
    {
        pkActor->Unk_10D(reinterpret_cast<Actor*>(pkPackage3));
        if (pkPackage3 && pkActor->GetProcess())
            reinterpret_cast<B82B5E0Process*>(pkActor->GetProcess())->StartPackage(pkActor, pkPackage3, true, 0, 0, 0, 0, 0, 0, 0, 0, true, 0);
    }
}
