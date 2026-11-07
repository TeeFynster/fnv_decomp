
// src/fallout_shared/tesobjectcell_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x005571a0: the skeleton of src/fallout_shared/tesobjectcell.cpp
// with declarations corrected to what the original code does (tesobjectcell_packet.h: class TESForm; class NiNode; -> class TESForm { public: virtual void TESFormV00();; tesobjectcell_packet.h: class TESObjectREFR { public: static BGSEncounterZ -> class TESObjectREFR : public TESForm { public: sta; tesobjectcell_packet.h: T& GetItem(); BSSimpleList* GetNext();). Move the function to its real unit once
// that unit declares it this way.

#include "../../include/TES.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESObjectSTAT.h"
#include "../../include/TESObjectREFR.h"

#include "../../include/TESObjectCELL.h"

void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int TESTerrainLODManager_GetGrassNode();
NiAVObject* TESMain_GetWeatherRoot();

extern TES* g_TES;
struct ModelLoader
{
    void ModelLoader_QueueReference(TESObjectREFR*, void*, int);
};
extern ModelLoader* g_pModelLoader;
extern TESObjectSTAT* DAT_011ca238;
extern TESObjectSTAT* DAT_011ca230;
// @fnv 0x005571a0
// src: XBOX_PDB 0x005571a0
void TESObjectCELL::QueueReferences(bool active)
{
    CellRefLockEnter();
    void* list = g_TES->TES_GetCellPriority(this, 0);
    BSSimpleList<TESObjectREFR*>* terrain = reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(GetRefList_009604f0());
    while (terrain)
    {
        TESObjectREFR* reference = terrain->GetItem();
        if (reference && (reference->BGSSaveFormBuffer_GetForm() == DAT_011ca238 || reference->BGSSaveFormBuffer_GetForm() == DAT_011ca230))
        {
            if (!reference->GetNiNode() || reference->TESObjectREFR_HasTemp3D())
            {
                if (!reference->FUN_00440da0() && !reference->IsDeleted() && (!active || reference->TESObjectREFR_Is3DHighPriority()))
                    g_pModelLoader->ModelLoader_QueueReference(reference, list, 1);
            }
            else
            {
                if (reference->FUN_00440da0() || reference->IsDeleted())
                    reference->Set3D(0, true);
            }
        }
        terrain = terrain->GetNext();
    }
    terrain = reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(GetRefList_009604f0());
    while (terrain)
    {
        TESObjectREFR* other = terrain->GetItem();
        if (other && other->BGSSaveFormBuffer_GetForm() != DAT_011ca238 && other->BGSSaveFormBuffer_GetForm() != DAT_011ca230)
        {
            if (!other->GetNiNode() || other->TESObjectREFR_HasTemp3D())
            {
                if (!other->FUN_00440da0() && !other->IsDeleted() && (!active || other->TESObjectREFR_Is3DHighPriority()))
                    g_pModelLoader->ModelLoader_QueueReference(other, list, 1);
            }
            else
            {
                if (other->FUN_00440da0() || other->IsDeleted())
                    other->Set3D(0, false);
            }
        }
        terrain = terrain->GetNext();
    }
    CellRefLockLeave();
}
