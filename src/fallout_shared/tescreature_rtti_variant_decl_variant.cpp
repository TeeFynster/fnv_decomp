#include "../../include/ActorValueOwner.h"
#include "../../include/BGSBodyPartData.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSTouchSpellForm.h"
#include "../../include/CombatProcedure.h"
#include "../../include/CreatureSounds.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimation.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESContainer.h"
#include "../../include/TESCreature.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelList.h"
#include "../../include/TESNPC.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSpellList.h"

#include <string.h>
// @fnv 0x005f9b90
bool TESCreature::FUN_005f9b90(TESForm* otherForm)
{
    TESCreature* other = dynamic_cast<TESCreature*>(otherForm);
    if (!other)
        return true;
    if (FUN_00485270(other))
        return true;
    if (memcmp(&dataPadding, other->GetOffset12C(), 4))
        return true;
    if (FUN_005f9ad0() != other->FUN_005f9ad0())
        return true;
    if (FUN_00821640() != other->FUN_00821640())
        return true;
    if (FUN_00567470() != other->FUN_00567470())
        return true;
    if (FUN_00821660() != other->FUN_00821660())
        return true;
    if (static_cast<const TESCreature*>(this)->GetBloodImpactMaterial() !=
        static_cast<const TESCreature*>(other)->GetBloodImpactMaterial())
        return true;
    if (static_cast<const TESCreature*>(this)->GetCombatStyle() !=
        static_cast<const TESCreature*>(other)->GetCombatStyle())
        return true;
    if (static_cast<const TESCreature*>(this)->GetBodyPartData() !=
        static_cast<const TESCreature*>(other)->GetBodyPartData())
        return true;
    if (FUN_009c0070() != other->FUN_009c0070())
        return true;
    if (FUN_00461580(0x100))
    {
        CreatureSounds* sounds = GetCreatureSounds();
        CreatureSounds* otherSounds5 = other->GetCreatureSounds();
        if (sounds)
        {
            if (!otherSounds5)
                return true;
            if (sounds->IsDifferentFrom(otherSounds5))
                return true;
        }
        else if (otherSounds5)
            return true;
    }
    else
    {
        if (GetSoundCreature() != other->GetSoundCreature())
            return true;
    }
    if (GetImpactDataSet() != other->GetImpactDataSet())
        return true;
    if (GetField158() != other->GetField158())
        return true;
    return false;
}
