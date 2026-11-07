
// src/fallout_shared/tesconditionfunctions_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0059c010: the skeleton of src/fallout_shared/tesconditionfunctions.cpp
// with declarations corrected to what the original code does (tesconditionfunctions_conditionfn_dep_layout_support.h: TESObjectCELL += void* FUN_00546c20();; tesconditionfunctions_conditionfn_dep_TESObjectREFR.h: TESObjectREFR += class TESWorldSpace* FUN_00575d70();). Move the function to its real unit once
// that unit declares it this way.

#include "../../include/Actor.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectCELL.h"
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
struct PlayerCharacterMovingStateView
{
    unsigned char padding[0x20c];
    unsigned char movingIntoNewSpace;
};
bool __cdecl GetEssentialConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);
bool __cdecl IsPlayerEnteringSpaceConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);
bool GetLastHitLocationConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);

extern __declspec(thread) bool g_bShowConditionDebug;
void __cdecl DebugLog(char const*, ...);
// @fnv 0x0059c010
// src: XBOX_PDB 0x0059c010
bool __cdecl Script_GetInZoneConditionFunction(TESObjectREFR* reference, void* parameter, void* unused, double& result)
{
    result = 0.0;
    void* zone = parameter;
    if (reference && zone)
    {
        void* found = 0;
        TESObjectCELL* cell = reference->GetParentCell();
        if (cell)
            found = cell->FUN_00546c20();
        if (!found)
        {
            TESWorldSpace* world = reference->TESObjectREFR_GetWorldSpace();
            if (world)
                found = world->GetFieldD0();
        }
        if (found == zone)
            result = 1.0;
    }
    if (g_bShowConditionDebug)
        DebugLog("GetInZone >> %0.2f", result);
    return true;
}
