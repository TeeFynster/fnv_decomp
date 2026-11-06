// src/fallout/magic/vampirismeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/vampirismeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/Character.h"
#include "../../../include/VampirismEffect.h"

void ActiveEffect::InitLoadGame(Actor* apActor)
{
    (void)apActor;
}

// Calls ActiveEffect::InitLoadGame with apActor, then dynamic_casts apActor to Character and discards the result.
// @fnv 0x0082d110
void VampirismEffect::InitLoadGame(Actor* apActor)
{
    ActiveEffect::InitLoadGame(apActor);
    Character* pcharacter = dynamic_cast<Character*>(apActor);
}

// @fnv 0x0082cfb0
ActiveEffect* VampirismEffect::Copy()
{
    VampirismEffect* spawned = new VampirismEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(spawned);
    return spawned;
}
