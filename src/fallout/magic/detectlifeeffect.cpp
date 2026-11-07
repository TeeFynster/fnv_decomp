
// src/fallout/magic/detectlifeeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/detectlifeeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/BSThread.h"
#include "../../../include/Setting.h"
#include "../../../include/DetectLifeEffect.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/ValueModifierEffect.h"

extern "C" unsigned char DAT_011dc034;

// @fnv 0x0080cec0
// src: XBOX_PDB 0x0080cec0
void __cdecl DetectLifeEffect_CheckPlayerRunningDetectLife()
{
    DAT_011dc034 = 0;
}

struct TESEffectShader;

extern TESEffectShader* DAT_011c3588;

// @fnv 0x0080d0d0
// src: XBOX_PDB 0x0080d0d0
TESEffectShader* __cdecl MagicSystem_GetDetectLifeShaderEffect()
{
    return DAT_011c3588;
}

// @fnv 0x0080cd90
DetectLifeEffect::~DetectLifeEffect()
{
}

struct PC7d;
extern PC7d* g_thePlayer;
struct RetObj
{
    virtual void f0();
    virtual PC7d* f1();
};

// @fnv 0x0080ce60
void DetectLifeEffect::Start()
{
    ValueModifierEffect::Start();
    if (((RetObj*)((BSThread*)this)->GetThreadID())->f1() == g_thePlayer)
        DetectLifeEffect_CheckPlayerRunningDetectLife();
}

// @fnv 0x0080d0e0
void DetectLifeEffect::Finish()
{
    ValueModifierEffect::ApplyEffect();
    if (((RetObj*)((BSThread*)this)->GetThreadID())->f1() == g_thePlayer)
        DetectLifeEffect_CheckPlayerRunningDetectLife();
}

void* operator new(unsigned int size) throw();

// @fnv 0x0080cdb0
ActiveEffect* DetectLifeEffect::Copy()
{
    ActiveEffect* e = new DetectLifeEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(e);
    return e;
}

#include "../../../include/NiMemObject.h"
struct FUN_0081f580 : public NiMemObject
{
    FUN_0081f580(Actor* pkRef, TESEffectShader* pkShader, float fTime);
    virtual ~FUN_0081f580();
    virtual void e01();
    virtual void e02();
    virtual void e03();
    virtual void e04();
    virtual void e05();
    virtual void e06();
    virtual void e07();
    virtual void e08();
    virtual void e09();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26();
    virtual void e27();
    virtual void e28();
    virtual void e29();
    virtual void e30();
    virtual void e31();
    virtual void e32();
    virtual void e33();
    virtual void e34();
    virtual void e35();
    virtual void e36();
    virtual void e37();
    virtual void e38();
    virtual void e39();
    virtual void e40();
    virtual void e41();
    virtual void e42();
    virtual void e43();
    virtual void e44();
    virtual void e45();
    virtual void e46();
    virtual void e47();
    virtual void e48();
    virtual bool IsValid();
    int unk04[26];
};
struct Mgr80c
{
    void ProcessLists_AddTempEffect(FUN_0081f580* pkEffect);
    void ProcessLists_FinishMagicShaderHitEffect(Actor* pkRef, TESEffectShader* pkShader);
};
TESEffectShader* __cdecl MagicSystem_GetDetectLifeShaderEffect();
extern Actor* DAT_011dea3c;
extern Setting DAT_011d15e0;
extern float DAT_01012054;
extern Mgr80c DAT_011e0e80;

// @fnv 0x0080ced0
bool __cdecl UpdateEffectShaderOnActor(Actor* pkRef, bool bStopEffect)
{
    TESEffectShader* pkShader2 = MagicSystem_GetDetectLifeShaderEffect();
    if (!pkShader2 || !pkRef || pkRef == DAT_011dea3c || !pkRef->MobileObject::FUN_008d8520())
        return false;
    float fZero = 0.0f;
    float fDistSq = fZero * *DAT_011d15e0.Setting_Float_00403e20();
    fDistSq *= fDistSq;
    NiPoint3 kPlayerPos9 = *static_cast<const Actor*>(DAT_011dea3c)->GetPos();
    if (static_cast<const NiPoint3&>(kPlayerPos9).SubtractIntoVector(*static_cast<const Actor*>(pkRef)->GetPos()).FUN_004a7290() < fDistSq && !pkRef->HasHealth(false) &&
        !pkRef->MobileObject::FUN_008d8520()->FUN_0045cd60() && !pkRef->FUN_00477ba0())
    {
        if (!bStopEffect)
        {
            FUN_0081f580* pkEffect = new FUN_0081f580(pkRef, pkShader2, DAT_01012054);
            if (pkEffect->IsValid())
                DAT_011e0e80.ProcessLists_AddTempEffect(pkEffect);
            else
                delete pkEffect;
        }
        return true;
    }
    else
    {
        if (bStopEffect)
            DAT_011e0e80.ProcessLists_FinishMagicShaderHitEffect(pkRef, pkShader2);
        return false;
    }
}
