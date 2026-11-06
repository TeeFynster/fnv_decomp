#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/Actor.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/TelekinesisEffect.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/ValueModifierEffect.h"
#include "../../../include/GO.h"
#include "../../../include/MagicCaster.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiObject.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/Setting.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/bhkCollisionObject.h"
#include "../../../include/bhkWorldObject.h"
#include "../../../include/bhkFilter.h"

// src/fallout/magic/telekinesiseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/telekinesiseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// A trivial aggregate keeps the deletion flag on the stack while the effect
// pointer uses ECX, matching the original deleting-destructor ABI.
struct TelekinesisDeletionFlags
{
    unsigned int value;
};
void __cdecl _Deallocate(void*);

// @fnv 0x0082a510
void* __fastcall DestroyTelekinesisEffect(TelekinesisEffect* effect, TelekinesisDeletionFlags flags)
{
    effect->TelekinesisEffect::~TelekinesisEffect();
    if (flags.value & 1)
        _Deallocate(effect);
    return effect;
}

// @fnv 0x0082aab0
void PlayerCharacter::SetField644(float value)
{
    *(float*)((char*)this + 0x644) = value;
}

// The shared header has no declaration for this getter. Its sole ECX argument
// preserves the original parameterless member ABI without a player stand-in.
// @fnv 0x0082af40
float __fastcall GetTelekinesisStrength(PlayerCharacter* player)
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(player) + 0x644);
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

// Returns the effect's save size: base size from FUN_00802d90 plus 4, plus 8 more when the save version is at least 0x40.
// @fnv 0x0082b190
unsigned short __thiscall TelekinesisEffect::FUN_0082b190(Actor* apActor)
{
    unsigned short uiSaveSize = 0;
    uiSaveSize += FUN_00802d90(apActor);
    uiSaveSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x40)
    {
        uiSaveSize += 4;
        uiSaveSize += 4;
    }
    return uiSaveSize;
}


// @fnv 0x0082b290
void TelekinesisEffect::LoadFromSave(Actor* apActor)
{
    ValueModifierEffect::FUN_00802dd0(apActor);
    unsigned int irefID;
    g_TESSaveLoadGame->FUN_00857aa0(&irefID, 4u);
    unk58 = irefID;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x40)
    {
        g_TESSaveLoadGame->FUN_008579e0(&m_50, 4);
        g_TESSaveLoadGame->FUN_008579e0(&m_54, 4);
    }
}

void* __cdecl FUN_00703390();
// This base start helper has no shared declaration; its receiver uses ECX.
void __fastcall StartValueModifierEffect(ValueModifierEffect* effect);

// Calls FUN_0082c000, stores the result of FUN_00703390 at offset 0x58, calls StartTelekinesisEffect, and clears the byte at offset 0x5d.
// @fnv 0x0082a670
void __thiscall TelekinesisEffect::FUN_0082a670()
{
    StartValueModifierEffect(this);
    target = static_cast<TESObjectREFR*>(FUN_00703390());
    StartTelekinesisEffect();
    m_5d = 0;
}

struct Flt
{
    operator unsigned int();
};

// @fnv 0x0082aa90
MagicCaster* __thiscall PlayerCharacter::GetFloatAsUInt()
{
    return reinterpret_cast<MagicCaster*>(((Flt*)((char*)this + 0x634))->operator unsigned int());
}

void* __cdecl FUN_004b5a80(void const*);

struct FUN_0082aeb0_shell
{
    void* __thiscall FUN_0082aee0();
    void* __thiscall FUN_0082aeb0();
};

// Calls FUN_0082aee0 and passes its result to FUN_004b5a80, returning that value.
// @fnv 0x0082aeb0
void* __thiscall FUN_0082aeb0_shell::FUN_0082aeb0()
{
    void* result = FUN_0082aee0();
    return FUN_004b5a80(result);
}

// Destroys the GO and ValueModifierEffect subobjects without changing the vtable.
// @fnv 0x0082a540
TelekinesisEffect::~TelekinesisEffect()
{}

// This nullable reference-flags accessor binds to 0x004ae750; ScriptLocals::GetLocalData binds to 0x00541c80.
struct NullableReferenceFlagsAccessor
{
    void* __thiscall GetLocalData();
};
struct Calendar
{
    unsigned int __thiscall GetDaysPassed();
};
struct FUN_0082aee0_shell
{
    unsigned int __thiscall FUN_0082aee0();
};
// @fnv 0x0082aee0
unsigned int FUN_0082aee0_shell::FUN_0082aee0()
{
    Calendar* calendar = reinterpret_cast<Calendar*>((reinterpret_cast<NullableReferenceFlagsAccessor*>(this))->GetLocalData());
    return calendar ? calendar->GetDaysPassed() : 0;
}

// As above, retain the unsupported getter locally with its original ECX ABI.
// @fnv 0x0082af20
unsigned int __fastcall GetField63C(PlayerCharacter* player)
{
    return *(unsigned int*)((char*)player + 0x63c);
}

struct FUN_00974a50_shell
{
    void __thiscall FUN_00974a50(void* a, void* b);
};
extern int DAT_011e0e80;
// @fnv 0x0082af60
void __thiscall TelekinesisEffect::FUN_0082af60()
{
    FUN_0082afa0();
    ((FUN_00974a50_shell*)(&DAT_011e0e80))
        ->FUN_00974a50(target, GetEffectSetting()->GetEffectShader());
    ApplyEffect();
}

// Allocates and constructs a TelekinesisEffect from x, y and z.
// @fnv 0x0082b110
TelekinesisEffect* __cdecl CreateTelekinesisEffect(int x, int y, int z)
{
    return new TelekinesisEffect(x, y, z);
}

// @fnv 0x0082b200
void TelekinesisEffect::SaveLoad(Actor* apActor)
{
    unsigned int irefID;
    FUN_00802db0(apActor);
    irefID = 0;
    if (unk58)
        irefID = target->FUN_0084e3a0();
    g_TESSaveLoadGame->FUN_00857a10((int)&irefID, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x40)
    {
        g_TESSaveLoadGame->FUN_008579b0(&m_50, 4);
        g_TESSaveLoadGame->FUN_008579b0(&m_54, 4);
    }
}

TESForm* __cdecl GetFormByID(unsigned int id);

// @fnv 0x0082b300
void TelekinesisEffect::FUN_0082b300(Actor* apActor)
{
    ValueModifierEffect::FUN_0082cd10(apActor);
    TESObjectREFR* pRef = target;
    if (pRef)
        target = dynamic_cast<TESObjectREFR*>(GetFormByID(reinterpret_cast<unsigned int>(pRef)));
    if (target)
        StartTelekinesisEffect();
    m_5d = 1;
}

void* __cdecl operator new(unsigned int);

// @fnv 0x0082a5a0
ActiveEffect* TelekinesisEffect::CreateCopy()
{
    ActiveEffect* copy = new TelekinesisEffect(reinterpret_cast<int>(m_pEffectInstance),
                                              reinterpret_cast<int>(pSpell), reinterpret_cast<int>(pEffect));

    CopyData(copy);
    return copy;
}

struct SceneObject
{
};
bhkCollisionObject* __cdecl FUN_004b5260(SceneObject*);
void __cdecl FUN_00807ac0(bhkWorldObject*);
struct ReferenceForm
{
    int FUN_00401170();
};
struct TelekinesisReference
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
    virtual SceneObject* GetSceneObject();
    ReferenceForm* GetObjectReference();
};
struct ShaderDefinition
{
};
// This caster getter has no shared declaration; its receiver uses ECX.
MagicCaster* __fastcall GetTelekinesisCaster(ActiveEffect* effect);
struct TelekinesisConstraint
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    TelekinesisConstraint(TelekinesisReference*, bhkWorldObject*, unsigned int);
};
extern NiRTTI DAT_011f9140;
NiObject* __cdecl FUN_00653270(const NiRTTI*, SceneObject*);
struct CasterPosition
{
    void ApplyTurnUndeadEffect(NiPoint3*);
};
extern PlayerCharacter* g_thePlayer;
extern float DAT_01022958;
extern const float DAT_01012054;
struct ShaderEffect
{
    virtual ~ShaderEffect();
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
    virtual bool Start();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    static void* operator new(unsigned int);
    static void operator delete(void*);
    ShaderEffect(TelekinesisReference*, ShaderDefinition*, float);
};
struct EffectManager
{
    void FUN_00973fd0(ShaderEffect*);
};

// Validates the target's collision object, creates a TelekinesisConstraint, applies the telekinesis effect to the player, and starts the effect shader.
// @fnv 0x0082a6a0
void TelekinesisEffect::StartTelekinesisEffect()
{
    if (!target || !GetTelekinesisCaster(this))
    {
        Dispel(false);
        return;
    }
    switch (reinterpret_cast<ReferenceForm*>(target->GetObjectReference())->FUN_00401170())
    {
    case 27:
        Dispel(false);
        return;
    }
    SceneObject* h = reinterpret_cast<TelekinesisReference*>(target)->GetSceneObject();
    bhkCollisionObject* a = h ? FUN_004b5260(h) : 0;
    bhkWorldObject* i = a ? a->FUN_006fa820() : 0;
    if (i)
        FUN_00807ac0(i);
    if (!i || (i->FUN_0043b4f0().FUN_0043b4d0() != 4 && i->FUN_0043b4f0().FUN_0043b4d0() != 5))
    {
        Dispel(false);
        return;
    }
    void* p = i->FUN_004ae750();
    new TelekinesisConstraint(reinterpret_cast<TelekinesisReference*>(target), i, i->FUN_0043b4f0().value);
    NiObject* eb = FUN_00653270(&DAT_011f9140, h);
    if (eb)
        eb->FUN_00b4dec0(6);
    if (g_thePlayer->GetFloatAsUInt())
        g_thePlayer->FUN_00961280();
    if (!g_TESSaveLoadGame->FUN_0047c850())
        magnitude = DAT_01022958;
    g_thePlayer->FUN_0095f930(reinterpret_cast<TelekinesisReference*>(target), 3, magnitude);
    NiPoint3 s;
    NiPoint3 f;
    g_thePlayer->GetCameraPosAndDir(&s, &f, true);
    if (!g_TESSaveLoadGame->FUN_0047c850())
    {
        NiPoint3 casterPosition;
        ((CasterPosition*)g_thePlayer->GetFloatAsUInt())->ApplyTurnUndeadEffect(&casterPosition);
        NiPoint3 p = casterPosition - s;
        magnitude = f.Dot(p);
        g_thePlayer->SetField644(magnitude);
        f *= magnitude;
    }
    if (GetEffectSetting()->GetEffectShader())
    {
        ShaderEffect* shader = new ShaderEffect(reinterpret_cast<TelekinesisReference*>(target),
                                                reinterpret_cast<ShaderDefinition*>(GetEffectSetting()->GetEffectShader()),
                                                DAT_01012054);
        if (shader->Start())
            ((EffectManager*)&DAT_011e0e80)->FUN_00973fd0(shader);
        else
            delete shader;
    }
}

struct World
{
};
struct Cell
{
    World* FUN_004543c0();
};
struct Ref
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual Ref* GetReference();
    Cell* FUN_008d6f30();
};
struct Target
{
    void* FUN_0082aeb0();
};
// This reference lookup is absent from the shared player declaration too.
Ref* __fastcall FUN_0089f4e0(PlayerCharacter* player);
extern PlayerCharacter* DAT_011dea3c;
struct Input
{
    int FUN_00a24660(int, int);
};
struct OS
{
    Input* FUN_00877720();
};
extern OS* DAT_011dea0c;
extern Setting originalRuntimeFloatSetting1168;
extern Setting originalRuntimeFloatSetting1169;
extern Setting originalRuntimeFloatSetting1170;
extern Setting originalRuntimeFloatSetting1171;
extern Setting originalRuntimeFloatSetting1112;
extern Setting g_011d18fc;
// Advances the grab effect: checks the player's grab target and world, updates velocity/strength from input and settings, applies strength and charges cost.
// @fnv 0x0082aad0
void TelekinesisEffect::UpdateGrabEffect(float delta)
{
    ValueModifierEffect::Update(delta);
    Target* grab = reinterpret_cast<Target*>(DAT_011dea3c->GetFloatAsUInt());
    if (!grab->FUN_0082aeb0())
    {
        Dispel(false);
        return;
    }
    World* casterWorld = GetTelekinesisCaster(this) && FUN_0089f4e0(DAT_011dea3c)->FUN_008d6f30()
                             ? reinterpret_cast<Ref*>(GetTelekinesisCaster(this))->GetReference()->FUN_008d6f30()->FUN_004543c0()
                             : 0;
    World* playerWorld = FUN_0089f4e0(DAT_011dea3c) && FUN_0089f4e0(DAT_011dea3c)->FUN_008d6f30()
                             ? FUN_0089f4e0(DAT_011dea3c)->FUN_008d6f30()->FUN_004543c0()
                             : 0;
    if (!grab || target != reinterpret_cast<TESObjectREFR*>(FUN_0089f4e0(DAT_011dea3c)) || GetField63C(DAT_011dea3c) != 3 ||
        casterWorld != playerWorld)
    {
        Dispel(false);
        return;
    }
    if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(6, 0) && DAT_011dea0c->FUN_00877720()->FUN_00a24660(4, 0))
    {
        if (velocity >
            *originalRuntimeFloatSetting1168.FUN_00403e20() + *originalRuntimeFloatSetting1169.FUN_00403e20() * 0.1f)
            released = true;
        Dispel(false);
    }
    else if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(4, 0))
    {
        if (velocity < *originalRuntimeFloatSetting1168.FUN_00403e20())
            velocity = *originalRuntimeFloatSetting1168.FUN_00403e20();
        velocity += *originalRuntimeFloatSetting1169.FUN_00403e20() * delta;
        if (velocity > *originalRuntimeFloatSetting1170.FUN_00403e20())
            velocity = *originalRuntimeFloatSetting1170.FUN_00403e20();
    }
    else if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(6, 0))
    {
        if (velocity > -*originalRuntimeFloatSetting1168.FUN_00403e20())
            velocity = -*originalRuntimeFloatSetting1168.FUN_00403e20();
        velocity -= *originalRuntimeFloatSetting1169.FUN_00403e20() * delta;
        if (velocity < -*originalRuntimeFloatSetting1170.FUN_00403e20())
            velocity = -*originalRuntimeFloatSetting1170.FUN_00403e20();
    }
    else
        velocity = 0.0f;
    strength = GetTelekinesisStrength(DAT_011dea3c);
    strength += velocity * delta;
    if (strength < *originalRuntimeFloatSetting1171.FUN_00403e20())
        strength = *originalRuntimeFloatSetting1171.FUN_00403e20();
    if (strength > *originalRuntimeFloatSetting1112.FUN_00403e20() * GetFloatAtOffset1C() * *g_011d18fc.FUN_00403e20())
        strength = *originalRuntimeFloatSetting1112.FUN_00403e20() * GetFloatAtOffset1C() * *g_011d18fc.FUN_00403e20();
    DAT_011dea3c->SetField644(strength);
    if (!skipCost)
        DAT_011dea3c->FUN_00960520(delta);
    skipCost = false;
}

// GO has no shared declaration for this handle operation.
struct TelekinesisHandleOperations
{
    void Apply(int value);
};

// The novtable class needs its original vtable installed before the handle constructor.
extern void* TelekinesisEffectVtable[];

// Initializes the base, handle, vtable, and telekinesis state.
// @fnv 0x0082a460
TelekinesisEffect::TelekinesisEffect(int aiParam1, int aiParam2, int aiParam3)
    : ValueModifierEffect(reinterpret_cast<void*>(aiParam1), reinterpret_cast<void*>(aiParam2),
                          reinterpret_cast<void*>(aiParam3)),
      m_4c((*(void***)this = TelekinesisEffectVtable, 0))
{
    reinterpret_cast<TelekinesisHandleOperations*>(&m_4c)->Apply(0);
    m_50 = 0.0f;
    m_54 = 0.0f;
    m_58 = 0;
    m_5c = 0;
    m_5d = 0;
}
