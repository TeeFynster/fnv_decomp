
// src/fallout/magic/invisibilityeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/invisibilityeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/ExtraHealth.h"
#include "../../../include/HighProcess.h"
// The original constructor installs its vtable explicitly.
class __declspec(novtable) InvisibilityEffect;
#include "../../../include/InvisibilityEffect.h"
#include "../../../include/TESForm.h"
#include "../../../include/ValueModifierEffect.h"

extern int DAT_0107a21c;
void* __cdecl FormHeap_Allocate(unsigned int uiSize);
inline void* InvisibilityEffect::operator new(unsigned int uiSize)
{
    return FormHeap_Allocate(uiSize);
}
// Constructs the object by calling the ValueModifierEffect base constructor and installing the DAT_0107a21c vtable pointer.
// @fnv 0x0080e030
InvisibilityEffect::InvisibilityEffect(void* a, void* b, void* c) : ValueModifierEffect(a, b, c)
{
    *(int*)this = (int)&DAT_0107a21c;
}

extern float DAT_0107a214;
extern Actor* g_thePlayer;
bool __cdecl FUN_005b9b00(void);
// @fnv 0x0080e540
void __thiscall InvisibilityEffect::ApplyInvisibility(Actor* actor)
{
    FUN_0082cd10(actor);
    if (FUN_005b9b00() && actor == g_thePlayer)
    {
        actor->SetAlpha(1.0f);
        actor->Unk_E1(1, DAT_0107a214);
    }
    else
    {
        actor->UpdateActorPresentation();
    }
}

// @fnv 0x0080e5b0
void InvisibilityEffect::RevertInvisibility(Actor* apActor)
{
    reinterpret_cast<TESForm*>(this)->TESForm::Revert(reinterpret_cast<BGSLoadFormBuffer*>(apActor));
    if (FUN_005b9b00() && apActor == g_thePlayer)
        apActor->Unk_E1(1, 0.0f);
    else
        apActor->UpdateActorPresentation();
}


void* __cdecl FormHeap_Allocate(unsigned int uiSize);

// @fnv 0x0080e060
InvisibilityEffect* InvisibilityEffect::CreateEffect()
{
    InvisibilityEffect* pkEffect = new InvisibilityEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(pkEffect);
    return pkEffect;
}

struct Target
{
    Actor* FUN_00822b40();
};
struct Effect
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
    Target* FUN_0059bb30();
    void FUN_0082c000();
    void FUN_0080e110();
};
// @fnv 0x0080e110
void Effect::FUN_0080e110()
{
    Actor* actor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    FUN_0082c000();
    if (actor && actor->GetActorValue(static_cast<ActorValue::Index>(unk48)) > 0.0)
    {
        if (FUN_005b9b00() && actor == g_thePlayer)
        {
            actor->SetAlpha(1.0f);
            actor->Unk_E1(1, DAT_0107a214);
        }
        else
        {
            HighProcess* pHighProcess = dynamic_cast<HighProcess*>(actor->GetProcess());
            if (pHighProcess && static_cast<BaseProcess*>(pHighProcess)->GetCurrentFadeState() != 4)
                pHighProcess->FUN_008fe960(actor, 0, 0);
        }
    }
}

// Allocates and constructs an InvisibilityEffect from the three given arguments.
// @fnv 0x0080e4c0
void* __cdecl CreateExtraHealth(void* apArg1, void* apArg2, void* apArg3)
{
    return new InvisibilityEffect(apArg1, apArg2, apArg3);
}



struct MVHighProcess : HighProcess
{
    void SetContentCount(Actor* apActor, int aiUnk);
};

struct MVMagicTarget
{
    Actor* GetActor();
};

struct MVFullName
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int GetValue(float afValue);

    unsigned int GetLength();
};

struct MVEffectSetting
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    MVFullName kFullName;
};

struct MVActiveEffect
{
    virtual ~MVActiveEffect();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual bool IsValid();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;

    static void* __cdecl operator new(unsigned int auiSize);
    MVActiveEffect(Actor* apTarget, int aiValue);
};

struct MVProcessLists
{
    void FUN_00973fd0(MVActiveEffect* apEffect);
};

extern Actor* g_pMVPlayer;
extern MVProcessLists g_kMVProcessLists;
extern const float g_fMVEffectArg;
bool __cdecl FUN_005b9b00();
float __cdecl FUN_0040df50();
float __cdecl GetOriginalRuntimeFloatSetting9();
float __cdecl LinearInterpolate(float a1, float a2, float a3, float a4, float a5);

struct MVEffect
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int m_eAssociatedActorValue;

    void ApplyEffect();
    MVMagicTarget* GetTarget();
    MVEffectSetting* GetEffectSetting();
    void FUN_0080e230();
};

// @fnv 0x0080e230
void MVEffect::FUN_0080e230()
{
    ApplyEffect();
    Actor* pTarget = GetTarget() ? GetTarget()->GetActor() : 0;
    if (pTarget && pTarget->GetActorValue(static_cast<ActorValue::Index>(m_eAssociatedActorValue)) == 0.0)
    {
        if (FUN_005b9b00() && pTarget == g_pMVPlayer)
        {
            pTarget->Unk_E1(1, 0.0f);
        }
        else
        {
            HighProcess* pProcess = dynamic_cast<HighProcess*>(pTarget->GetCurrentProcess());
            if (pProcess && static_cast<BaseProcess*>(pProcess)->GetCurrentFadeState() != 4)
                static_cast<MVHighProcess*>(pProcess)->SetContentCount(pTarget, 0);
        }

        float m_fElapsedTime = 0.0f;
        if (m_fElapsedTime > 0.0)
        {
            if (FUN_005b9b00())
            {
                float fValue = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), FUN_0040df50(), 0.0f, 1.0f,
                                                 1.0f - m_fElapsedTime);
                pTarget->Unk_E1(1, fValue);
            }
            else
                pTarget->FUN_008c4640();
        }
        else
            pTarget->FUN_008c4640();

        MVActiveEffect* pEffect5 = 0;
        if (GetEffectSetting()->kFullName.GetLength() > 0)
            pEffect5 = new MVActiveEffect(pTarget, GetEffectSetting()->kFullName.GetValue(g_fMVEffectArg));
        if (pEffect5 && pEffect5->IsValid())
            g_kMVProcessLists.FUN_00973fd0(pEffect5);
        else
            delete pEffect5;
    }
}
