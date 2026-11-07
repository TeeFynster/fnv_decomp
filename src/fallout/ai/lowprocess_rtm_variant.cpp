// src/fallout/ai/lowprocess_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/lowprocess.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

// Reuse the unit's process dependencies with the shared NPC hierarchy.
// include/TESFile.h needs the Windows types before layout_support.h stubs them.
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#include <windows.h>
#include "lowprocess_support.h"
#include "../../../include/TESForm.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESBoundObject.h"

#include "../../../include/ActiveEffect.h"
#include "../../../include/ActorMover.h"
#include "../../../include/BGSDehydrationStage.h"
#include "../../../include/BGSListForm.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/BGSPickupPutdownSounds.h"
#include "../../../include/CombatProcedure.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/ExtraLock.h"
#include "../../../include/HighProcess.h"
#include "../../../include/LowProcess.h"
#include "../../../include/TES.h"
#include "../../../include/TESFaction.h"
#include "../../../include/TESGlobal.h"
#include "../../../include/TESRecipe.h"
#include "../../../include/TESTopicInfo.h"
#include "../../../include/TESValueForm.h"
class TargetDoorController
{
  public:
    TESObjectREFR* pObject;
    TESBoundObject* pItem;
    bool bActivate;
    bool m_bUseSpecialAction;
    unsigned char layoutPaddingA[2];
    int iCount;
    float fDistance;
    float fValue;
    int eType;
    ~TargetDoorController();
};

extern TESValueForm DAT_011e0e80;
#include "../../../include/TESNPC.h"

namespace acquire907_rework {
using ::TESForm;
using ::TESObjectREFR;
using ::TESBoundObject;

class AcquireActorBaseView;

class Acq907
{
  public:
    TESObjectREFR* pObject;    // 0x00
    TESBoundObject* pItem;     // 0x04
    bool bActivate;            // 0x08
    bool m_bUseSpecialAction;  // 0x09
    unsigned short unk0A;
    int iA;     // 0x0c
    int iB;     // 0x10
    int iC;     // 0x14
    int eType;  // 0x18
    ~Acq907();
};

class List907
{
  public:
    Acq907* m_item;
    List907* m_pkNext;
    Acq907*& FUN_006815c0();
    List907* FUN_00726070();
    void FUN_00905820(Acq907*& item);
    void FUN_00470470();
};

class Shell8e
{
  public:
    bool TESPackage_SearchGetAllowBuying();
    bool IsFlag400Set();
    bool TESPackage_SearchGetAllowKilling();
};

class Act907
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual bool v21c();

    bool FUN_00566950();
    int Actor_GetGoldAmount();
    bool Actor_IsInCombat();
    float TESObjectREFR_GetDistanceFromReference(TESObjectREFR* ref, int a, int b);
    bool Actor_HasObjects(TESBoundObject* item, int a, int b, int c, int* out);
    TESForm* BGSSaveFormBuffer_GetForm();
};

class AcquireAIServiceQuery
{
  public:
    bool TESAIForm_SellBuysItem(TESBoundObject* item);
};

class AcquireActorBaseView
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    AcquireAIServiceQuery sub90;
};

// Actor-base view: 0x004181e0 binds Actor::GetActorBase; base + 0x90 queries TESAIForm services at 0x0047f600.
class AcquireActorReference
{
  public:
    AcquireActorBaseView* FUN_004181e0() const;
};

extern "C" TESBoundObject* DAT_011ca268;
int __cdecl TESValueForm_GetFormValue(TESBoundObject* item);

}

using namespace acquire907_rework;

// @fnv 0x00907d90
void LowProcess::ProcessAcquire(Actor* arg)
{
    List907* itF = reinterpret_cast<List907*>(&this->m_kDetectionDataList);
    Shell8e* pkg_h = (Shell8e*)static_cast<const LowProcess*>(this)->GetOneTimePackage();
    bool bA7 = pkg_h ? pkg_h->TESPackage_SearchGetAllowBuying() : false;
    bool bBI = pkg_h ? pkg_h->IsFlag400Set() : false;
    bool bCB = pkg_h ? pkg_h->TESPackage_SearchGetAllowKilling() : false;
    bool bDoneZ;

    while (itF != 0 && itF->FUN_006815c0())
    {
        Acq907* pNodeM = itF->FUN_006815c0();
        TESObjectREFR* pRefA = pNodeM->pObject;
        TESObjectREFR* pOther3 = 0;
        TESBoundObject* pItemR = pNodeM->pItem;
        Act907* actor_p;
        bool bValid7;

        actor_p = pRefA->IsActor() ? (Act907*)pRefA : 0;
        bDoneZ = false;
        bValid7 = true;
        if (actor_p)
        {
            if (actor_p->FUN_00566950())
                bValid7 = false;
        }

        if ((pRefA->GetOwner() && pRefA->GetOwner() != reinterpret_cast<Act907*>(arg)->BGSSaveFormBuffer_GetForm()) || pRefA->IsActor())
        {
            bool b313 = false;
            bool b32Ptr = false;
            int nG = TESValueForm_GetFormValue(pItemR);
            TESNPC* pNPCA = 0;

            if (!pRefA->HasHealth(false) && reinterpret_cast<Act907*>(arg)->Actor_GetGoldAmount() >= nG)
            {
                AcquireActorReference* pProjQ = 0;
                if (pRefA->IsCharacter())
                {
                    pProjQ = (AcquireActorReference*)pRefA;
                }
                else
                {
                    pNPCA = dynamic_cast<TESNPC*>(pRefA->GetOwner());
                    if (pNPCA)
                        pProjQ = (AcquireActorReference*)DAT_011e0e80.GetValueFromForm(pNPCA, false);
                }
                if (pProjQ && bA7 && pProjQ->FUN_004181e0()->sub90.TESAIForm_SellBuysItem(pItemR))
                {
                    if (!reinterpret_cast<Act907*>(arg)->Actor_IsInCombat())
                    {
                        pNodeM->eType = 2;
                        pNodeM->iB = (int)reinterpret_cast<Act907*>(arg)->TESObjectREFR_GetDistanceFromReference(pRefA, 0, 0);
                        bDoneZ = true;
                    }
                    else
                    {
                        bValid7 = false;
                    }
                }
            }

            if (!bDoneZ && !(actor_p && actor_p->FUN_00566950()))
            {
                if (!pRefA->IsActor())
                {
                    if (bBI)
                        b313 = true;
                }
                else if (pRefA->HasHealth(false))
                {
                    bValid7 = true;
                }
                else if (pRefA->IsCharacter())
                {
                    pOther3 = pRefA;
                    if (bBI)
                        b313 = true;
                    if (bCB)
                        b32Ptr = true;
                }

                if ((b313 || b32Ptr) && !(actor_p && actor_p->FUN_00566950()))
                {
                    if (!pRefA->IsActor())
                    {
                        if (pNodeM->eType == 1)
                        {
                            int x = 0;
                            pNodeM->eType = 4;
                            bool okD = reinterpret_cast<Act907*>(arg)->Actor_HasObjects(DAT_011ca268, 0, 1, 0, &x);
                            if (!okD && pRefA->GetLock())
                                bValid7 = false;
                        }
                        else
                        {
                            pNodeM->eType = 3;
                        }
                    }
                    else if (b313)
                    {
                        if (!reinterpret_cast<Act907*>(arg)->Actor_IsInCombat())
                        {
                            pNodeM->eType = 4;
                        }
                        else
                        {
                            bValid7 = false;
                        }
                    }
                    else if (b32Ptr)
                    {
                        if (!reinterpret_cast<Act907*>(arg)->Actor_IsInCombat() && !reinterpret_cast<Act907*>(arg)->FUN_00566950())
                        {
                            if (!actor_p || (actor_p && !actor_p->FUN_00566950()))
                                pNodeM->eType = 5;
                        }
                        else
                        {
                            bValid7 = false;
                        }
                    }
                    pNodeM->bActivate = b313;
                    pNodeM->m_bUseSpecialAction = b32Ptr;
                }
                else
                {
                    if (reinterpret_cast<Act907*>(arg)->v21c())
                    {
                        bValid7 = false;
                    }
                    else if (pRefA->IsActor() && !pRefA->IsCharacter() && pRefA->GetOwner() != reinterpret_cast<Act907*>(arg)->BGSSaveFormBuffer_GetForm() &&
                             !reinterpret_cast<Act907*>(arg)->FUN_00566950())
                    {
                        if (actor_p && !actor_p->FUN_00566950())
                        {
                            pNodeM->eType = 5;
                            bValid7 = true;
                        }
                    }
                    else
                    {
                        bValid7 = false;
                    }
                }
            }
        }
        else
        {
            pNodeM->iB = (int)reinterpret_cast<Act907*>(arg)->TESObjectREFR_GetDistanceFromReference(pRefA, 0, 0);
        }

        if (bValid7)
        {
            pNodeM->pObject->TESObjectREFR_SetTargeted(true);
            reinterpret_cast<List907&>(this->ReferenceListNode).FUN_00905820(pNodeM);
        }
        else
        {
            delete reinterpret_cast< ::TargetDoorController*>(pNodeM);
        }
        itF = itF->FUN_00726070();
    }
    reinterpret_cast<List907&>(this->m_kDetectionDataList).FUN_00470470();
}

