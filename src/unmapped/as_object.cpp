#include "../../include/AutoMemHelper.h"
#include "../../include/BGSLoadedReferenceCollection.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/MobileObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESFile.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/NavMeshCollection.h"
#include "../../include/NiPointer.h"

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class NavMesh;
struct S00561ef0
{
    bool TESObjectREFR_MoveToEditorLocation(TESObjectCELL*);
};
struct P01ObjA
{
    TESForm* GetNext();
};
struct FUN_00881d10
{
    void SetHoursPassed();
};
struct FUN_00452440_shell
{
    bool BGSPlaceableWater_IsAutomaticWater();
};
struct CellReferenceList
{
    bool FUN_008256d0();
    TESObjectREFR** FUN_006815c0();
    void FUN_0063f7b0();
    CellReferenceList* FUN_00726070();
    void RemoveMatchingItem(TESObjectREFR* const&);
};
struct CF845
{
    int flags;
    CF845(int);
    CF845(const CF845&);
};
struct Class_0084a700
{
    bool HasChangeForForm(TESObjectREFR*, CF845);
};
struct FUN_008d0370_shell
{
    bool FUN_008d0370(TESObjectREFR*);
};
int __fastcall GetReferenceFlags(void*);
void GarbageCollector_Add_TESObjectREFR(TESObjectREFR*);
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern FUN_008d0370_shell* g_TESSaveLoadGame;
extern BGSLoadedReferenceCollection* DAT_011c95c8;
extern TESObjectREFR* g_thePlayer;

// @fnv 0x005508b0
void TESObjectCELL::RemoveNonPersistentRefs()
{
    TESObjectLAND* pLand;
    {
        CellReferenceList* pPrevNode;
        NavMeshCollection* pNavMeshArray;
        CellRefLockEnter();
        *(unsigned short*)((char*)this + 0xa8) = 0;
        *(unsigned short*)((char*)this + 0xaa) = 0;
        {
            CellReferenceList* pNode;
            bool bOldAllow = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
            RemoveObstaclesAndDoors();
            pNode = (CellReferenceList*)GetRefList_009604f0();
            pPrevNode = 0;
            while (pNode && !pNode->FUN_008256d0())
            {
                TESObjectREFR* pRef = *pNode->FUN_006815c0();
                if (!pRef->GetReferencePersistence() &&
                    (!((TESForm*)pRef)->GetFile(-1) || ((TESForm*)pRef)->GetFile(-1)->IsMasterFile()))
                {
                    if (pPrevNode)
                    {
                        pPrevNode->RemoveMatchingItem(pRef);
                        pNode = pPrevNode->FUN_00726070();
                    }
                    else
                    {
                        pNode->FUN_0063f7b0();
                    }
                    DAT_011c95c8->RemoveReference_005270b0(pRef);
                    if (pRef->IsActor())
                    {
                        MobileObject* pActor = (MobileObject*)pRef;
                        if (pActor->GetCurrentProcessLevel() == 0)
                            ((FUN_00881d10*)pActor)->SetHoursPassed();
                    }
                    g_TESSaveLoadGame->FUN_008d0370(pRef);
                    g_BGSSaveLoadGame->FUN_00849730(pRef, 0);
                    bool bPrint = true;
                    if (g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading() &&
                        ((Class_0084a700*)g_BGSSaveLoadGame)->HasChangeForForm(pRef, CF845(8)) &&
                        ((S00561ef0*)pRef)->TESObjectREFR_MoveToEditorLocation(this))
                        bPrint = false;
                    if (((P01ObjA*)pRef)->GetNext() && ((P01ObjA*)pRef)->GetNext()->FNV_GetFormType() == 0x23)
                    {
                        FUN_00452440_shell* pBase = (FUN_00452440_shell*)((P01ObjA*)pRef)->GetNext();
                        if (pBase->BGSPlaceableWater_IsAutomaticWater())
                            RemoveAutoWaterReferenceFromReferencesCurrentWater(pRef);
                    }
                    if (bPrint && pRef != g_thePlayer)
                        GarbageCollector_Add_TESObjectREFR(pRef);
                }
                else
                {
                    pPrevNode = pNode;
                    pNode = pNode->FUN_00726070();
                }
            }
            g_BGSSaveLoadGame->SetThreadAllowChanges(bOldAllow);
        }
        CellRefLockLeave();
        pLand = GetLandscape();
        if (pLand)
        {
            TESFile* pFile = ((TESForm*)pLand)->GetFile(-1);
            if (!pFile || pFile->IsMasterFile())
            {
                SetLandscape(0);
                pLand = 0;
            }
        }
        pNavMeshArray = GetNavMeshArray();
        if (pNavMeshArray)
        {
            AutoMemHelper memHelper(
                0x2e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp", 0x2769);
            for (unsigned int i = 0; i < GetReferenceFlags(pNavMeshArray); i++)
            {
                TESFile* pNavFile = ((TESForm*)(NavMesh*)pNavMeshArray->GetNavMeshAt(i))->GetFile(-1);
                if (!pNavFile || pNavFile->IsMasterFile())
                {
                    NavMeshPtr apSearchNavMesh = pNavMeshArray->GetNavMeshAt(i);
                    g_BGSSaveLoadGame->FUN_00849730(apSearchNavMesh.AnimatingText_GetFullText(), 0);
                    pNavMeshArray->RemoveAndCollect(i);
                    i--;
                }
            }
        }
    }
    TESObjectCELL_SetHasTempData(false);
}
