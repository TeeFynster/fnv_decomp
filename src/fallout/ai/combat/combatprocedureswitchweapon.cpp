#include "../../../../include/CombatProcedureSwitchWeapon.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/CombatController.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectWEAP.h"

// src/fallout/ai/combat/combatprocedureswitchweapon.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureswitchweapon.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Actor/state helpers use their original one-register calling convention.
Actor* __fastcall GetCombatProcedureActor(CombatProcedure*);
void __fastcall SetCombatProcedureState(CombatProcedure*);

// @fnv 0x009da7a0
CombatProcedureSwitchWeapon::~CombatProcedureSwitchWeapon()
{
}

// Saves the base combat procedure, then writes pWeapon and the 1-byte field at offset 0x14 to the save buffer.
// @fnv 0x009da970
void CombatProcedureSwitchWeapon::SaveGame(BGSSaveFormBuffer* buffer)
{
    CombatProcedure::SaveGame(buffer);
    buffer->SerializeFormData(pWeapon, 0);
    buffer->SaveData(reinterpret_cast<char*>(this) + 0x14, 1, 0);
}

void __cdecl Deallocate(void*);
// Calls the destructor, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x009da770
void* CombatProcedureSwitchWeapon::DestroyIfFlagged(unsigned int flags)
{
    this->~CombatProcedureSwitchWeapon();
    if (flags & 1)
        Deallocate(this);
    return this;
}

TESForm* __cdecl _ref_004839c0(unsigned int);
// Loads the base combat procedure state, resolves the weapon form from the buffer, and reads one byte into the field at offset 0x14.
// @fnv 0x009da9b0
void CombatProcedureSwitchWeapon::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    CombatProcedure::LoadGame(apLoadGameBuffer);
    pWeapon = dynamic_cast<TESObjectWEAP*>(_ref_004839c0(((BGSLoadGameBuffer*)apLoadGameBuffer)->ReadFormIdentifier()));
    apLoadGameBuffer->ReadTypedData((char*)this + 0x14, 1u);
}

// Calls the base constructor, installs the vtable, stores apWeapon in pWeapon and clears the byte flag.
// @fnv 0x009da720
CombatProcedureSwitchWeapon::CombatProcedureSwitchWeapon(TESObjectWEAP* apWeapon)
{
    pWeapon = apWeapon;
    m_ucWeaponState = 0;
}

struct ExtraDataList;
struct InvEntry
{
    TESForm* FUN_0044ddc0();
    ExtraDataList* FUN_00726070();
};
bool __fastcall FUN_004c0bf0(TESForm*);
bool __fastcall FUN_006450c0(TESForm*);
// @fnv 0x009da7c0
void CombatProcedureSwitchWeapon::UpdateWeaponDraw()
{
    if (m_pCombatController->FUN_00981990())
    {
        SetCombatProcedureState(this);
        return;
    }
    Actor* actor = GetCombatProcedureActor(this);
    if (actor->FUN_008a7570() != -1)
        return;
    InvEntry* entry = reinterpret_cast<InvEntry*>(reinterpret_cast<BaseProcess*>(actor->FUN_008d8520())->GetActiveWeapon());
    TESForm* weap = entry ? entry->FUN_0044ddc0() : 0;
    if (!m_ucWeaponState && weap != pWeapon)
    {
        if (reinterpret_cast<BaseProcess*>(actor->FUN_008d8520())->IsAdditionalActorFlagSet())
        {
            actor->FUN_008a6840(false);
            return;
        }
        if (pWeapon)
        {
            int count = 1;
            if (FUN_004c0bf0(pWeapon))
                count = actor->FUN_00575610(pWeapon);
            actor->EquipItem(pWeapon, count, 0, true, false, true);
        }
        else
        {
            actor->UnequipItem(weap, entry->FUN_00726070(), false, false, false, true);
        }
        m_ucWeaponState = true;
    }
    else if (weap == pWeapon)
    {
        if (!reinterpret_cast<BaseProcess*>(actor->FUN_008d8520())->IsAdditionalActorFlagSet())
            actor->FUN_008a6840(true);
        if (!weap || FUN_006450c0(weap))
            m_pCombatController->UpdateActorValues();
        SetCombatProcedureState(this);
    }
}
