// src/fallout/magic/nighteyeeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/nighteyeeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NightEyeEffect.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESSaveLoadGame.h"

// @fnv 0x0080cea0
void NightEyeEffect::Update(float afSecondsElapsed)
{
    ValueModifierEffect::Update(afSecondsElapsed);
}

// @fnv 0x00825710
NightEyeEffect::NightEyeEffect(void* apArg1, void* apArg2, void* apArg3)
    : ValueModifierEffect(apArg1, apArg2, apArg3)
{}

struct PC7d;
extern PC7d* g_thePlayer;
void UpdateImageSpaceEffectFromPlayerState();

// The shared base does not declare this helper used by Start.
extern "C" void StartValueModifierEffect();

struct VirtualObj
{
    virtual void f0();
    virtual PC7d* f1();
};

// @fnv 0x00825810
void NightEyeEffect::Start()
{
    ActiveEffect_SetMagnitude(1.0f);
    ((void (__thiscall*)(ValueModifierEffect*))StartValueModifierEffect)(this);
    if (((VirtualObj*)ActiveEffect::FUN_0059bb30())->f1() == g_thePlayer)
        UpdateImageSpaceEffectFromPlayerState();
}

// @fnv 0x00825860
void NightEyeEffect::Finish()
{
    ApplyEffect();
    if (((VirtualObj*)ActiveEffect::FUN_0059bb30())->f1() == g_thePlayer)
        UpdateImageSpaceEffectFromPlayerState();
}

// Calls ActiveEffect::InitLoadGame for apActor, then refreshes the player's image-space effect.
// @fnv 0x00825920
void NightEyeEffect::InitLoadGame(Actor* apActor)
{
    ActiveEffect::InitLoadGame(apActor);
    if ((void*)apActor == (void*)g_thePlayer)
        UpdateImageSpaceEffectFromPlayerState();
}

namespace fnv_00825950 {
extern TESSaveLoadGame* g_TESSaveLoadGame;
}  // namespace fnv_00825950

// @fnv 0x00825950
void NightEyeEffect::Revert(Actor* apActor)
{
    ((TESForm*)this)->Revert(reinterpret_cast<unsigned int>(apActor));
    if (fnv_00825950::g_TESSaveLoadGame->TESSaveLoadGame_GetRevertBefore() && (void*)apActor == (void*)g_thePlayer)
        UpdateImageSpaceEffectFromPlayerState();
}

// @fnv 0x008258a0
// src: COMMUNITY 0x008258a0
NightEyeEffect* NightEyeEffect_Create(void* apArg0, void* apArg1, void* apArg2)
{
    return new NightEyeEffect(apArg0, apArg1, apArg2);
}

void* operator new(unsigned int size) throw();

// @fnv 0x00825760
ActiveEffect* NightEyeEffect::Copy()
{
    ActiveEffect* e = new NightEyeEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(e);
    return e;
}

struct FUN_00825990_ImageSpaceEffect
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C(int);
};

struct FUN_00825990_ImageSpaceManager
{
    FUN_00825990_ImageSpaceEffect* __thiscall GetEffect_004ebbc0(int);
};

struct FUN_00825990_PlayerBase
{
    virtual void vf00();
    virtual void vf04();
    virtual int vf08(int);
};

struct FUN_00825990_PlayerData
{
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    FUN_00825990_PlayerBase unkA4;
};

extern FUN_00825990_ImageSpaceManager* __cdecl BSShaderManager_GetImageSpaceManager();
extern float* __fastcall Setting_Float_00403e20(float*);
extern FUN_00825990_PlayerData* DAT_011dea3c;
extern float DAT_011d1668;
extern float DAT_011f947c;

// @fnv 0x00825990
void UpdateImageSpaceEffectFromPlayerState()
{
    FUN_00825990_ImageSpaceEffect* effect;

    {
        FUN_00825990_ImageSpaceManager* manager = BSShaderManager_GetImageSpaceManager();
        effect = manager->GetEffect_004ebbc0(3);
    }

    if (DAT_011dea3c->unkA4.vf08(0x32) > 0)
    {
        DAT_011f947c = *Setting_Float_00403e20(&DAT_011d1668);
        effect->vf2C(1);
    }
    else
    {
        DAT_011f947c = 0.0f;
        effect->vf2C(0);
    }
}
