#include "../../../include/SettingT.h"
// fallout/magic/limbconditioneffect.cpp: LimbConditionEffect, ValueModifierEffect (11 functions)

#include "../../../include/ActorValue.h"

#include "../../../include/LimbConditionEffect.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/GameSettingCollection.h"
#include "../../../include/TESSaveLoadGame.h"

bool g_bLimbConditionEffectInitialized;

// @fnv 0x005b9210
bool GetLimbConditionEffectInitialized()
{
    return g_bLimbConditionEffectInitialized;
}

// @fnv 0x0080f2b0
unsigned short __thiscall LimbConditionEffect::GetSaveSize(Actor* apActor)
{
    unsigned short isize = 0;
    isize += ValueModifierEffect::FUN_00802d90(apActor);
    isize += 4;
    return isize;
}

extern int DAT_0107a3fc;
extern "C" void ConstructValueModifierEffect();

// Constructs the value-modifier base, installs the game vtable and initializes the limb actor value.
// @fnv 0x0080f060
// src: EXE 0x0080f060
LimbConditionEffect* LimbConditionEffect::LimbConditionEffect_0080f060(void* a, void* b, void* c)
{
    typedef ValueModifierEffect* (__thiscall* BaseConstructor)(ValueModifierEffect*, void*, void*, void*);
    ((BaseConstructor)&ConstructValueModifierEffect)(this, a, b, c);
    *(void**)this = (void*)&DAT_0107a3fc;
    m_eModifiedActorValue = -1;
    return this;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x0080f2f0
void LimbConditionEffect::LoadGame(Actor* apActor)
{
    ValueModifierEffect::FUN_00802dd0(apActor);
    g_TESSaveLoadGame->ReadTypedData(&m_eModifiedActorValue, 4);
}

// @fnv 0x0080f320
void LimbConditionEffect::SaveGame(BGSSaveFormBuffer* apBuffer)
{
    ActiveEffect::SaveGame(apBuffer);
    apBuffer->SaveData(&m_eModifiedActorValue, 4, 0);
}

// Calls ActiveEffect::LoadGame, then for buffer version 8 or higher reads 4 bytes into the field at offset 0x4c.
// @fnv 0x0080f350
void __thiscall LimbConditionEffect::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    ActiveEffect::LoadGame(apBuffer);
    if (apBuffer->GetVersion() >= 8)
    {
        apBuffer->ReadTypedData(&m_eModifiedActorValue, 4u);
    }
}

// Copies the base value-modifier data from other, then, if other is a LimbConditionEffect, copies m_eModifiedActorValue into it.
// @fnv 0x0080f150
void __thiscall LimbConditionEffect::CopyData(ActiveEffect* other)
{
    ValueModifierEffect::CopyData(other);
    LimbConditionEffect* target = dynamic_cast<LimbConditionEffect*>(other);
    if (target)
        target->m_eModifiedActorValue = m_eModifiedActorValue;
}

namespace fnv_0082ba30 {
extern TESSaveLoadGame* g_TESSaveLoadGame;
}  // namespace fnv_0082ba30

// @fnv 0x0082ba30
// src: XBOX_PDB 0x0082ba30
void ValueModifierEffect::LimbConditionEffect_SaveGame(Actor* apActor)
{
    FUN_00802db0(apActor);
    fnv_0082ba30::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((int*)((char*)this + 0x4C), 4);
}

using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1213;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1214;
// @fnv 0x0080f220
void __thiscall LimbConditionEffect::ApplyActorValueModifier(Actor* apActor, float afModifier,
                                                           ActorValue::Index aeOverrideActorValue)
{
    if (m_eModifiedActorValue != ActorValue::ActorValue__Index_VALUE_NONE)
    {
        float fScaledMagnitude = afModifier * *originalRuntimeFloatSetting1213.Float();
        ValueModifierEffect::ApplyActorValueModifier(apActor, afModifier, (ActorValue::Index)m_eModifiedActorValue);
    }
    else
    {
        float fScaledMagnitude = afModifier * *originalRuntimeFloatSetting1214.Float();
        for (int i = ActorValue::ActorValue__Index_PERCEPTION_CONDITION; i < 32; ++i)
            ValueModifierEffect::ApplyActorValueModifier(apActor, fScaledMagnitude, (ActorValue::Index)i);
    }
}

// Allocates and constructs a limb-condition effect from three arguments.
// @fnv 0x0080f1a0
// src: COMMUNITY 0x0080f1a0
LimbConditionEffect* LimbConditionEffect_Create(void* ap1, void* ap2, void* ap3)
{
    return new LimbConditionEffect(ap1, ap2, ap3);
}

void* __cdecl operator new(unsigned int);
extern int _data_011c16bc;

// @fnv 0x0080f0a0
ActiveEffect* LimbConditionEffect::Copy()
{
    ActiveEffect* presult = new LimbConditionEffect(m_pEffectInstance, pSpell, pEffect);

    CopyData(presult);

    return presult;
}
