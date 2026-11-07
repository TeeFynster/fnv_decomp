
// src/fallout/ai/middlehighprocess_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0091db40: the skeleton of src/fallout/ai/middlehighprocess.cpp
// with declarations corrected to what the original code does (middlehighprocess_decls.h: MiddleHighProcess += void FUN_0091db40(Actor* actor);; Actor.h: virtual void Unk_10D(void); -> virtual void Unk_10D(Actor* target);; TESObjectREFR.h: TESObjectREFR += float FUN_005723b0(TESObjectREFR* ref, int a, int b);). Move the function to its real unit once
// that unit declares it this way.

#include "../../../include/FurnitureMark.h"
#include "../../../include/MiddleHighProcess.h"
#include "middlehighprocess_decls_decl_middlehighprocess.h"
bool IsValidSandboxProcedure(int aiProcedure);

struct SettingFloat
{
    float* Float();
};
extern SettingFloat originalRuntimeFloatSetting236;
// @fnv 0x0091db40
// src: XBOX_PDB 0x0091db40
void MiddleHighProcess::ProcessCombat_0091db40(Actor* actor)
{
    int remaining = (int)*originalRuntimeFloatSetting236.Float();
    Actor* found = 0;
    found = dynamic_cast<Actor*>(pTarget);
    bool worked = false;
    if (!found || found->GetDisabled())
    {
        actor->Unk_10D(found);
        return;
    }
    if (found &&
        ((actor->GetParentCell() && actor->GetParentCell() == found->GetParentCell()) ||
         actor->TESObjectREFR::TESObjectREFR_GetDistanceFromReference(found, 0, 0) < 300.0) &&
        found->GetProcess() && found->GetProcess()->GetProcessLevel() == 1)
    {
        while (remaining)
        {
            if (actor->HasHealth(false))
                break;
            actor->Unk_10E();
            found = dynamic_cast<Actor*>(pTarget);
            if (found && !found->HasHealth(false) && found->GetProcess()->GetProcessLevel() == 1)
            {
                found->Unk_10E();
                worked = true;
            }
            remaining--;
        }
        if (worked)
        {
            if (found)
            {
                found->GetProcess()->ResetPackageState();
            }
            worked = false;
        }
    }
    else
    {
        static_cast<BaseProcess*>(this)->UpdateActorPackage(actor, true, 0x101, false);
    }
}
