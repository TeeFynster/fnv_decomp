
// src/fallout/ai/combat/combatprocedureusecombatitem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureusecombatitem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/CombatProcedureUseCombatItem.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/TESForm.h"

// @fnv 0x009daa50
CombatProcedure::COMBAT_PROCEDURES CombatProcedureUseCombatItem::GetProcedureType()
{
    return USE_COMBAT_ITEM;
}

extern void* DAT_0109214c;

// @fnv 0x009daa90
void CombatProcedureUseCombatItem::SetVtableAndInit()
{
    *reinterpret_cast<void**>(this) = &DAT_0109214c;
    CombatProcedure::~CombatProcedure();
}

// Calls SetVtableAndInit, deletes this when flags has bit 1 set, and returns this.
// @fnv 0x009daa60
void* CombatProcedureUseCombatItem::DestroyIfFlagged(unsigned int flags)
{
    SetVtableAndInit();
    if (flags & 1)
        operator delete(this);
    return this;
}

// Calls the base constructor, installs the vtable, stores apItem in pItem and clears the flag.
// @fnv 0x009daa10
CombatProcedureUseCombatItem::CombatProcedureUseCombatItem(TESBoundObject* apItem)
{
    pItem = apItem;
    m_bItemFlag = 0;
}

TESForm* __cdecl _ref_004839c0(unsigned int aiID);
// @fnv 0x009dac80
// src: XBOX_PDB 0x009dac80
void CombatProcedureUseCombatItem::LoadGame_009dac80(BGSLoadFormBuffer* apLoadGameBuffer)
{
    CombatProcedure::LoadGame(apLoadGameBuffer);
    pItem = dynamic_cast<TESBoundObject*>(_ref_004839c0(apLoadGameBuffer->ReadFormIdentifier()));
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_bItemFlag), 1u);
}

typedef void(__cdecl* FnPrint4)(void*, unsigned int, unsigned int, const char*);
typedef void(__cdecl* FnPrint6)(void*, unsigned int, unsigned int, const char*, const char*, unsigned int);

const char* __cdecl TESFullName_GetFullName(TESForm* p);

struct CombatItemDebugOutput
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void __cdecl v05(unsigned int a2, unsigned int a3, const char* fmt, ...);
};

// If the flag is set, prints "ANIMATING"; if pItem is set, prints the item's name (or a fallback) and its id via the object's print method.
// @fnv 0x009dabd0
void CombatProcedureUseCombatItem::PrintDebugInfo(CombatItemDebugOutput* pPrinter, unsigned int a2, unsigned int a3)
{
    if (this->m_bItemFlag)
    {
        pPrinter->v05(a2, a3, "ANIMATING");
    }
    if (this->pItem != 0)
    {
        pPrinter->v05(a2, a3, "Item: '%s' (%08X)",
                      (this->pItem->GetFormEditorIDLength() != 0) ? this->pItem->GetName() : TESFullName_GetFullName(this->pItem),
                      this->pItem->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    }
}

struct UCIWeapon : TESBoundObject
{
};
struct UCICombatProcess
{
    int FUN_0045cd60();
    void FindSpecialIdletoPlay(struct UCIActor* apActor, TESBoundObject* apItem, int aiUnk);
};
struct UCIAmmo
{
    bool Animation_SpecialIdleDonePlaying();
    bool HasIdleForm(int aiUnk);
};
struct UCIActor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual UCIAmmo* GetAmmo();
    UCICombatProcess* FUN_008d8520();
    void EquipItemWithCaster(UCIWeapon* apWeapon, int aiUnk, int aiFlag);
};
struct UCICombatState
{
    void CombatState_UsedCombatItem(TESBoundObject* apItem);
    void SetAttacker(int aiFlag);
};
struct UCIController
{
    UCICombatState* CombatController_GetCombatState();
};
void __cdecl FNV_Warning(const char* apFormat, ...);

// Checks the actor's combat process and ammo, then applies the combat item to the actor and combat state based on its form type.
// @fnv 0x009daab0
void CombatProcedureUseCombatItem::UpdateCombatItemUse()
{
    UCIActor* pActor2;
    UCICombatState* pState2;
    UCIAmmo* pAmmo;

    pActor2 = CombatProcedure_GetAttacker();
    pState2 = reinterpret_cast<UCIController*>(m_pCombatController)->CombatController_GetCombatState();
    if (!pActor2->FUN_008d8520()->FUN_0045cd60())
    {
        pAmmo = pActor2->GetAmmo();
        if (pAmmo && (!pAmmo->Animation_SpecialIdleDonePlaying() || pAmmo->HasIdleForm(0)))
            return;
        if (!m_bItemFlag)
        {
            UCICombatProcess* pProcess = pActor2->FUN_008d8520();
            pProcess->FindSpecialIdletoPlay(pActor2, pItem, 0);
            m_bItemFlag = true;
            return;
        }
    }

    pState2->CombatState_UsedCombatItem(pItem);
    switch (pItem->TESForm::FUN_00401170())
    {
    case 0x2f: {
        UCIWeapon* pWeapon = static_cast<UCIWeapon*>(pItem);
        pActor2->EquipItemWithCaster(pWeapon, 0, 1);
        pState2->SetAttacker(1);
        break;
    }
    default:
        FNV_Warning("COMBAT: Unhandled form type %s in CombatProcedureUseCombatItem::Update()", pItem->TESForm_GetFormTypeString());
    }
    SetState();
}
