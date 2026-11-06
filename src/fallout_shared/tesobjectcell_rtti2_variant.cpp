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
unsigned int FUN_0054f4c0();
NiAVObject* FUN_0054f4f0();

// 0x00452440 queries TESForm's 0x40000000 flag; TESForm.h lacks this out-of-line query.
struct FormCollisionQuery : TESForm
{
    bool FUN_00452440();
};
extern TESForm* DAT_011ca238;
extern TESForm* DAT_011ca230;

struct ControllerB54
{
    void FUN_00a59c60(NiUpdateData* pPoint);
};
struct NodeB54
{
    TESObjectREFR** FUN_006815c0();
    NodeB54* FUN_00726070();
};
class SceneB54;
struct ManagerB54
{
    bool FUN_00453490(SceneB54* pScene);
    void* FUN_00458be0(SceneB54* pScene, int i);
};
extern ManagerB54* DAT_011dea10;
struct SettingsB54
{
    bool FUN_0042ce10();
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
    void QueueReference(TESObjectREFR* pRef, void* p, int i);
};
extern LoaderB54* DAT_011c3b3c;
void __cdecl DoCheckScriptRunnerAndRun(TESObjectREFR* pRef, void* p);
void __cdecl MarkBaseExtraListScriptEvent(TESObjectREFR* pRef, void* p, int iFlags);

class SceneB54
{
  public:
    ControllerB54* GetOrCreateWidget();
    void FUN_0054c740(int a, int b);
    bool FUN_0054df30();
    void RecalcLeveledActorBases(bool b);
    void ProcessCellReferences();
    void FUN_00541ac0();
    void FUN_00541ae0();
    NodeB54* FUN_009604f0();
    void FUN_00548880(TESObjectREFR* pRef, int i);
    void FUN_005535f0();
    void SetState(int i);
    void FUN_0054bcf0(bool bArg);
};

// @fnv 0x0054bcf0
void SceneB54::FUN_0054bcf0(bool bArg)
{
    ControllerB54* pController2 = GetOrCreateWidget();
    FUN_0054c740(0, 0);
    bool bState5 = FUN_0054df30();
    RecalcLeveledActorBases(bState5);
    if (((ManagerB54*)DAT_011dea10)->FUN_00453490(this))
    {
        if (pController2)
        {
            // Constructor 0x0043d410 and update 0x00a59c60 identify NiUpdateData, not NiPoint3.
            NiUpdateData kPoint_(0.0f, 0, 0);
            pController2->FUN_00a59c60(&kPoint_);
        }
        ProcessCellReferences();
    }
    else
    {
        FUN_00541ac0();
        int iPass4;
        void* pCell9 = ((ManagerB54*)DAT_011dea10)->FUN_00458be0(this, 0);
        NodeB54* pNode5 = FUN_009604f0();
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
                    pNode5 = FUN_009604f0();
            }
            if (pRef)
            {
                bool bSpecial_2 = pRef->FUN_007af430() &&
                                  (pRef->FUN_007af430() == DAT_011ca238 || pRef->FUN_007af430() == DAT_011ca230);
                if (iPass4 == 0 && !bSpecial_2)
                    continue;
                if (iPass4 == 1 && bSpecial_2)
                    continue;
                iCountA++;
                if (!g_BGSSaveLoadGame->FUN_0042ce10())
                {
                    DoCheckScriptRunnerAndRun(pRef, pRef->FUN_005d43c0());
                    MarkBaseExtraListScriptEvent(pRef, pRef->FUN_005d43c0(), 0x1000);
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
                    ((LoaderB54*)DAT_011c3b3c)->QueueReference(pRef, pCell9, 0);
                    if (pRef->GetNiNode())
                    {
                        bool bProcess3 = true;
                        if (pRef->FUN_007af430()->FUN_00401170() == 0x23)
                        {
                            TESForm* pBase2 = pRef->FUN_007af430();
                            if (static_cast<FormCollisionQuery*>(pBase2)->FUN_00452440())
                                bProcess3 = false;
                        }
                        if (bProcess3)
                            FUN_00548880(pRef, 0);
                    }
                }
            }
        }
        FUN_00541ae0();
    }
    if (bArg)
        FUN_005535f0();
    SetState(6);
}
