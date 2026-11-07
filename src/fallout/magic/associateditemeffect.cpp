// src/fallout/magic/associateditemeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/associateditemeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/ActiveEffect.h"
#include "../../../include/AssociatedItemEffect.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESSaveLoadGame.h"

// Returns the ActiveEffect save size for apActor plus 4 bytes.
// @fnv 0x00806da0
unsigned short AssociatedItemEffect::GetSaveSize(Actor* apActor)
{
    unsigned short isize = 0;
    isize += ActiveEffect::GetSaveSize(apActor);
    isize += 4;
    return isize;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

// Loads the base effect and stores the saved form ID until InitLoadGame resolves it.
// @fnv 0x00806e30
void AssociatedItemEffect::LoadGame(Actor* apActor)
{
    unsigned int iformID;
    ActiveEffect::LoadGame(apActor);
    g_TESSaveLoadGame->FUN_00857aa0(&iformID, 4u);
    m_pAssociatedForm = reinterpret_cast<TESForm*>(iformID);
}

// Resolves the saved form ID after initializing the base effect.
// @fnv 0x00806e70
void AssociatedItemEffect::InitLoadGame(Actor* apActor)
{
    ActiveEffect::InitLoadGame(apActor);
    TESForm* form = m_pAssociatedForm;
    if (form)
        m_pAssociatedForm = TESForm::GetFormByID(reinterpret_cast<unsigned int>(form));
}

// @fnv 0x00806de0
void AssociatedItemEffect::SaveGame(Actor* apActor)
{
    ActiveEffect::SaveGame(apActor);
    unsigned int iformID = 0;
    if (m_pAssociatedForm)
        iformID = m_pAssociatedForm->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID(&iformID, 4u);
}

// Allocates a new effect from this object's caster, spell and effect item, copies its data, and returns it.
// @fnv 0x00806ca0
ActiveEffect* AssociatedItemEffect::Copy()
{
    AssociatedItemEffect* pEffect = new AssociatedItemEffect(m_pEffectInstance, pSpell, this->pEffect);
    CopyData(pEffect);
    return pEffect;
}

struct FUN_00806c20_helper2
{
    void* FUN_005f5f80();
};

struct FUN_00806c20_helper1
{
    FUN_00806c20_helper2* FUN_00825c00();
};

// Initializes the base effect and obtains the associated form from the effect item.
// @fnv 0x00806c20
AssociatedItemEffect::AssociatedItemEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect)
    : ActiveEffect(apCaster, apSpell, apEffect)
{
    FUN_00806c20_helper2* tmp = reinterpret_cast<FUN_00806c20_helper1*>(apEffect)->FUN_00825c00();
    m_pAssociatedForm = static_cast<TESForm*>(tmp->FUN_005f5f80());
}

extern "C" unsigned int DAT_011a0d1c;
extern "C" unsigned int DAT_011a0d60;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);

// Copies the base effect's data, then copies the associated form when the target has the correct type.
// @fnv 0x00806d50
void AssociatedItemEffect::CopyData(ActiveEffect* target)
{
    ActiveEffect::CopyData(target);
    AssociatedItemEffect* destination =
        static_cast<AssociatedItemEffect*>(FUN_00ec43fb(target, 0, &DAT_011a0d1c, &DAT_011a0d60, 0));
    if (destination)
        destination->m_pAssociatedForm = m_pAssociatedForm;
}
