// src/fallout_shared/tesobjectcell_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectREFR). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../include/Actor.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESBoundObject.h"
#include "../../include/NiUpdateData.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int TESTerrainLODManager_GetGrassNode();
NiAVObject* TESMain_GetWeatherRoot();

// 0x00452440 queries TESForm's 0x40000000 flag; TESForm.h lacks this out-of-line query.
struct FormCollisionQuery : TESForm
{
    bool BGSPlaceableWater_IsAutomaticWater();
};
extern TESForm* DAT_011ca238;
extern TESForm* DAT_011ca230;

struct ControllerB54
{
    void NiAVObject_Update(NiUpdateData* pPoint);
};
struct NodeB54
{
    TESObjectREFR** FUN_006815c0();
    NodeB54* FUN_00726070();
};
class SceneB54;
struct ManagerB54
{
    bool TES_IsBuffered(SceneB54* pScene);
    void* TES_GetCellPriority(SceneB54* pScene, int i);
};
extern ManagerB54* DAT_011dea10;
struct SettingsB54
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
};
extern SettingsB54* g_BGSSaveLoadGame;
struct ModeB54
{
    bool FUN_0047c850();
};
extern ModeB54* DAT_011de45c;
struct ProcessListB54
{
    void FUN_0096f400(Actor* pActor);
};
extern ProcessListB54 DAT_011e0e80;
struct LoaderB54
{
    void ModelLoader_QueueReference(TESObjectREFR* pRef, void* p, int i);
};
extern LoaderB54* DAT_011c3b3c;
void __cdecl Script_InitActionList(TESObjectREFR* pRef, void* p);
void __cdecl Script_SetActionFlag(TESObjectREFR* pRef, void* p, int iFlags);

class SceneB54
{
  public:
    ControllerB54* GetOrCreateWidget();
    void RunScripts_0054c740(int a, int b);
    bool TESObjectCELL_HandleExpiredReferences();
    void RecalcLeveledActorBases(bool b);
    void ProcessCellReferences();
    void FUN_00541ac0();
    void TESObjectCELL_CellRefLockLeave();
    NodeB54* GetRefList_009604f0();
    void TESObjectCELL_AttachReference3D(TESObjectREFR* pRef, int i);
    void SetupMopp();
    void SetState(int i);
    void TESObjectCELL_AttachModels(bool bArg);
};

// @fnv 0x0054bcf0
// src: XBOX_PDB 0x0054bcf0
void SceneB54::TESObjectCELL_AttachModels(bool bArg)
{
    ControllerB54* pController2 = GetOrCreateWidget();
    RunScripts_0054c740(0, 0);
    bool bState5 = TESObjectCELL_HandleExpiredReferences();
    RecalcLeveledActorBases(bState5);
    if (((ManagerB54*)DAT_011dea10)->TES_IsBuffered(this))
    {
        if (pController2)
        {
            // Constructor 0x0043d410 and update 0x00a59c60 identify NiUpdateData, not NiPoint3.
            NiUpdateData kPoint_(0.0f, 0, 0);
            pController2->NiAVObject_Update(&kPoint_);
        }
        ProcessCellReferences();
    }
    else
    {
        FUN_00541ac0();
        int iPass4;
        void* pCell9 = ((ManagerB54*)DAT_011dea10)->TES_GetCellPriority(this, 0);
        NodeB54* pNode5 = GetRefList_009604f0();
        int iCountA = 0;
        iPass4 = 0;
        while (iPass4 < 2 && pNode5)
        {
            TESObjectREFR* pRef = *pNode5->FUN_006815c0();
            pNode5 = pNode5->FUN_00726070();
            if (!pNode5)
            {
                iPass4++;
                if (iPass4 < 2)
                    pNode5 = GetRefList_009604f0();
            }
            if (pRef)
            {
                bool bSpecial_2 = pRef->BGSSaveFormBuffer_GetForm() &&
                                  (pRef->BGSSaveFormBuffer_GetForm() == DAT_011ca238 || pRef->BGSSaveFormBuffer_GetForm() == DAT_011ca230);
                if (iPass4 == 0 && !bSpecial_2)
                    continue;
                if (iPass4 == 1 && bSpecial_2)
                    continue;
                iCountA++;
                if (!g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
                {
                    Script_InitActionList(pRef, pRef->BSFile_GetDevice());
                    Script_SetActionFlag(pRef, pRef->BSFile_GetDevice(), 0x1000);
                }
                bool bDisabled4 = false;
                bDisabled4 = pRef->FUN_00440da0();
                if (!bDisabled4 && !pRef->FUN_00440d80())
                {
                    if (pRef->IsActor() && (!DAT_011de45c->FUN_0047c850() || DAT_011de45c->FUN_0047c850()))
                    {
                        Actor* pActor7 = dynamic_cast<Actor*>(pRef);
                        if (pActor7)
                        {
                            pActor7->StartHighProcess();
                            ((ProcessListB54*)&DAT_011e0e80)->FUN_0096f400(pActor7);
                        }
                    }
                    else if (pRef->IsProjectile())
                    {
                        MobileObject* pTarget = static_cast<MobileObject*>(pRef);
                        pTarget->Unk_98();
                    }
                    ((LoaderB54*)DAT_011c3b3c)->ModelLoader_QueueReference(pRef, pCell9, 0);
                    if (pRef->GetNiNode())
                    {
                        bool bProcess3 = true;
                        if (pRef->BGSSaveFormBuffer_GetForm()->FUN_00401170() == 0x23)
                        {
                            TESForm* pBase2 = pRef->BGSSaveFormBuffer_GetForm();
                            if (static_cast<FormCollisionQuery*>(pBase2)->BGSPlaceableWater_IsAutomaticWater())
                                bProcess3 = false;
                        }
                        if (bProcess3)
                            TESObjectCELL_AttachReference3D(pRef, 0);
                    }
                }
            }
        }
        TESObjectCELL_CellRefLockLeave();
    }
    if (bArg)
        SetupMopp();
    SetState(6);
}
