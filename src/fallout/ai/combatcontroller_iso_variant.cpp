// src/fallout/ai/combatcontroller_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/combatcontroller.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "../../../include/ActorValueOwner.h"
#include "../../../include/Actor.h"
#include "../../../include/Creature.h"
#include "../../../include/MiddleHighProcess.h"

int __fastcall GetCurrentWeapon(int);

struct TESAmmoInitCalls
{
    unsigned int FUN_0097ae90();
};

struct FUN_0097fc70_shell
{
    int CombatController_GetAttackSkill();
};

// @fnv 0x0097fc70
// src: XBOX_PDB 0x0097fc70
int FUN_0097fc70_shell::CombatController_GetAttackSkill()
{
    int iresult = 0;
    Creature* pcreature;

    if (!((Actor*)((TESAmmoInitCalls*)this)->FUN_0097ae90())->IsCreature())
    {
        if (GetCurrentWeapon((int)this))
        {
            iresult = ((ActorValueOwner*)(((TESAmmoInitCalls*)this)->FUN_0097ae90() + 0xa4))
                          ->GetActorValueAsInteger(((MiddleHighProcess*)GetCurrentWeapon((int)this))->MiddleHighProcess::GetWeaponForm());
        }
        else
        {
            iresult =
                ((ActorValueOwner*)(((TESAmmoInitCalls*)this)->FUN_0097ae90() + 0xa4))->GetActorValueAsInteger(0x2d);
        }
    }
    else
    {
        pcreature = dynamic_cast<Creature*>((Actor*)((TESAmmoInitCalls*)this)->FUN_0097ae90());
        if (pcreature)
        {
            iresult = (int)pcreature->Creature_GetWeaponSkill();
        }
    }

    return iresult;
}
