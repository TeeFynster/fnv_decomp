
// src/fallout/ai/actor_magic_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESActorBase). The skeleton of src/fallout/ai/actor_magic.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../../include/HighProcess.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/TESActorBase.h"
#include "../../../include/TESCreature.h"
#include "../../../include/SettingT_GameSettingCollection_.h"

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting704;

struct ActorCreatureStandIn
{
    float FUN_0088b850();
// @fnv 0x008d4750
// src: COMMUNITY 0x008d4750
    float Creature_GetReach()
    {
        float j = 0.0f;
        TESCreature* p = dynamic_cast< ::TESCreature*>(((::Actor*)this)->GetActorBase());
        if (!p)
        {
            j = FUN_0088b850();
        }
        else
        {
            j = (float)p->ShadowSceneNode_GetDisableLightUpdate();
            if (p->GetCreatureType() == 7)
            {
                j *= originalRuntimeFloatSetting704.Float()->f;
            }
        }
        return j;
    }
};

float (ActorCreatureStandIn::*fnv_008d4750_entry)() = &ActorCreatureStandIn::Creature_GetReach;
