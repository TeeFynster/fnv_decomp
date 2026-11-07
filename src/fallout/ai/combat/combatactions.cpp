// fallout/ai/combat/combatactions.cpp: combat actions (83 functions)

#include "../../../../include/CombatWorldStateListNode.h"
#include "../../../../include/CombatAction.h"
#include "../../../../include/CombatState.h"
#include "../../../../include/Setting.h"
#include "../../../../include/CombatActionAcquireLineOfSight.h"
#include "../../../../include/CombatActionApproachTarget.h"
#include "../../../../include/CombatActionIgnoreBlockedTarget.h"
#include "../../../../include/CombatActionAttackRangedExplosive.h"
#include "../../../../include/CombatActionAttackRanged.h"
#include "../../../../include/CombatActionAttackRangedFromCover.h"
#include "../../../../include/CombatActionAttackRangedExplosiveFromCover.h"
#include "../../../../include/CombatActionAttackMelee.h"
#include "../../../../include/CombatActionAttackHandToHand.h"
#include "../../../../include/CombatActionAttackGrenade.h"
#include "../../../../include/CombatActionAttackGrenadeFlushTarget.h"
#include "../../../../include/CombatActionMove.h"
#include "../../../../include/CombatActionMoveAndAttackRanged.h"
#include "../../../../include/CombatActionMoveAndAttackRangedExplosive.h"
#include "../../../../include/CombatActionMoveAndAttackGrenade.h"
#include "../../../../include/CombatActionDrawWeapon.h"
#include "../../../../include/CombatActionSwitchWeapon.h"
#include "../../../../include/CombatActionAvoidThreat.h"
#include "../../../../include/CombatActionSearch.h"
#include "../../../../include/CombatActionInvestigate.h"
#include "../../../../include/CombatActionDodge.h"
#include "combatactions_packet.h"
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../../../include/Actor.h"
#include "../../../../include/BSFaceGenNiNode.h"
#include "../../../../include/CombatController.h"
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/Tile.h"
#include "../../../../include/CombatActionActivateCombatItem.h"
#include "../../../../include/CombatActionAttackGrenadeFromCover.h"
#include "../../../../include/CombatActionFlee.h"
#include "../../../../include/CombatActionHide.h"
#include "../../../../include/CombatActionMoveAndSwitchToMelee.h"
#include "../../../../include/CombatActionUseCombatItem.h"

// CombatActionFlee.h lacks the method at 0x0097cdb0, identified by this action's canonical vtable.

// CombatActionActivateCombatItem.h lacks the method at 0x0097cf10, identified by this action's canonical vtable.

// CombatActionUseCombatItem.h lacks the method at 0x0097d060, identified by this action's canonical vtable.

// CombatActionMoveAndSwitchToMelee.h lacks the method at 0x0097c090, identified by this action's canonical vtable.

// CombatActionAttackGrenadeFromCover.h lacks the method at 0x0097bab0, identified by this action's canonical vtable.

// CombatActionHide.h lacks the execute/debug methods at 0x0097d2d0/0x0097d370 (canonical vtable slots 1/4).

struct Sub;

// Declarations absent from CombatController.h; all layout comes from the shared class.
class CombatControllerAccess : public CombatController
{
public:
    void* GetCombatState();
    void* GetCombatState(int);
    void SetWeapon(int);
    void* GetCurrentProcedure();
    Sub* Get(int);
};
// Constructs a CombatActionIgnoreBlockedTarget by initializing the base CombatAction with the given action and calling AddEffect(6, 0).
// @fnv 0x0097cc80
CombatActionIgnoreBlockedTarget::CombatActionIgnoreBlockedTarget(COMBAT_ACTION action) : CombatAction(action)
{
    AddEffect(6, 0);
}
// Ensures the list at DAT_011f13d0[index] exists, then appends action to it.
// @fnv 0x0097ab30
void CombatActionAttackRangedExplosive::Execute(int index, CombatAction* action)
{
    if (!DAT_011f13d0[index])
    {
        DAT_011f13d0[index] = new BSSimpleList<CombatAction*>;
    }
    DAT_011f13d0[index]->AddTail(action);
}
// Forwards the state and value to Effects.AddSoundEntry.
// @fnv 0x0097adc0
void CombatAction::AddEffect(int state, int value)
{
    Effects.AddSoundEntry(state, value);
}
// Forwards the state and value arguments to AddSoundEntry on the member object.
// @fnv 0x0097ade0
void CombatAction::AddFirstSoundEntry(int state, int value)
{
    m_kFirstSoundEntryNode.AddSoundEntry(state, value);
}
// Forwards state and value to AddSoundEntry on the member object.
// @fnv 0x0097bc60
void CombatAction::AddSecondSoundEntry(int state, int value)
{
    m_kSecondSoundEntryNode.AddSoundEntry(state, value);
}
// @fnv 0x0097c070
void CombatAction::RemoveActionWorldStateByOwner(int state)
{
    m_kActionWorldStateNode.RemoveItemByOwner(state);
}
// @fnv 0x0097c240
void CombatAction::RemoveEffectByOwner(int state)
{
    Effects.RemoveItemByOwner(state);
}
// @fnv 0x0097c260
void CombatAction::RemoveFirstSoundEntryByOwner(int state)
{
    m_kFirstSoundEntryNode.RemoveItemByOwner(state);
}
// @fnv 0x0097ad10
CombatActionAttackRanged::CombatActionAttackRanged(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(3, 0);
    AddActionWorldState(5, 1);
    AddActionWorldState(6, 0);
    AddActionWorldState(11, 1);
    AddActionWorldState(10, 1);
    AddEffect(0, 1);
}
// @fnv 0x0097aeb0
CombatActionAttackRangedFromCover::CombatActionAttackRangedFromCover(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(18, 0);
    AddFirstSoundEntry(18, 17);
    AddFirstSoundEntry(4, 1);
    AddFirstSoundEntry(7, 0);
    AddActionWorldState(11, 1);
    AddActionWorldState(10, 1);
    AddActionWorldState(1, 2);
    AddEffect(0, 1);
}
// @fnv 0x0097b0b0
CombatActionAttackRangedExplosive::CombatActionAttackRangedExplosive(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(3, 0);
    AddFirstSoundEntry(8, 0);
    AddActionWorldState(5, 1);
    AddActionWorldState(6, 0);
    AddActionWorldState(11, 0);
    AddActionWorldState(10, 0);
    AddEffect(0, 1);
}
// @fnv 0x0097b280
CombatActionAttackRangedExplosiveFromCover::CombatActionAttackRangedExplosiveFromCover(COMBAT_ACTION action)
    : CombatAction(action)
{
    AddFirstSoundEntry(18, 0);
    AddFirstSoundEntry(18, 17);
    AddFirstSoundEntry(4, 1);
    AddFirstSoundEntry(8, 0);
    AddFirstSoundEntry(7, 0);
    AddActionWorldState(11, 0);
    AddActionWorldState(10, 0);
    AddActionWorldState(1, 2);
    AddEffect(0, 1);
}
// @fnv 0x0097b350
CombatActionAttackMelee::CombatActionAttackMelee(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(18, 17);
    AddFirstSoundEntry(3, 0);
    AddFirstSoundEntry(18, 18);
    AddActionWorldState(11, 2);
    AddActionWorldState(10, 2);
    AddActionWorldState(1, 1);
    AddEffect(0, 1);
}
// @fnv 0x0097b4e0
CombatActionAttackHandToHand::CombatActionAttackHandToHand(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(18, 17);
    AddFirstSoundEntry(3, 0);
    AddFirstSoundEntry(18, 18);
    AddActionWorldState(11, 6);
    AddActionWorldState(10, 6);
    AddActionWorldState(1, 1);
    AddEffect(0, 1);
}
// @fnv 0x0097b620
CombatActionAttackGrenade::CombatActionAttackGrenade(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(3, 0);
    AddFirstSoundEntry(8, 0);
    AddActionWorldState(5, 1);
    AddActionWorldState(11, 3);
    AddActionWorldState(10, 3);
    AddEffect(0, 1);
}
// @fnv 0x0097b7a0
CombatActionAttackGrenadeFlushTarget::CombatActionAttackGrenadeFlushTarget(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(8, 0);
    AddFirstSoundEntry(7, 0);
    AddActionWorldState(11, 3);
    AddActionWorldState(10, 3);
    AddEffect(9, 1);
}
// @fnv 0x0097b9e0
CombatActionAttackGrenadeFromCover::CombatActionAttackGrenadeFromCover(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(18, 0);
    AddFirstSoundEntry(18, 17);
    AddFirstSoundEntry(4, 1);
    AddFirstSoundEntry(8, 0);
    AddFirstSoundEntry(7, 0);
    AddActionWorldState(11, 3);
    AddActionWorldState(10, 3);
    AddActionWorldState(1, 2);
    AddEffect(0, 1);
}
// @fnv 0x0097bbd0
CombatActionMove::CombatActionMove(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(18, 17);
    AddActionWorldState(10, -65512);
    AddEffect(1, -1);
    AddSecondSoundEntry(6, 0);
}
// @fnv 0x0097bfe0
CombatActionMoveAndSwitchToMelee::CombatActionMoveAndSwitchToMelee(COMBAT_ACTION action) : CombatActionMove(action)
{
    RemoveActionWorldStateByOwner(10);
    AddFirstSoundEntry(12, 2);
    AddSecondSoundEntry(11, 2);
    AddSecondSoundEntry(10, 2);
}
// @fnv 0x0097c170
CombatActionMoveAndAttackRanged::CombatActionMoveAndAttackRanged(COMBAT_ACTION action)
    : CombatActionAttackRanged(action)
{
    RemoveFirstSoundEntryByOwner(3);
    RemoveFirstSoundEntryByOwner(18);
    RemoveActionWorldStateByOwner(1);
    RemoveActionWorldStateByOwner(6);
    RemoveActionWorldStateByOwner(5);
    RemoveEffectByOwner(0);
    AddFirstSoundEntry(18, 17);
    AddFirstSoundEntry(15, 0);
    AddEffect(1, -1);
    AddSecondSoundEntry(6, 0);
}
// @fnv 0x0097c3a0
CombatActionMoveAndAttackRangedExplosive::CombatActionMoveAndAttackRangedExplosive(COMBAT_ACTION action)
    : CombatActionAttackRangedExplosive(action)
{
    RemoveFirstSoundEntryByOwner(3);
    RemoveFirstSoundEntryByOwner(18);
    RemoveActionWorldStateByOwner(1);
    RemoveActionWorldStateByOwner(6);
    RemoveActionWorldStateByOwner(5);
    RemoveEffectByOwner(0);
    AddFirstSoundEntry(18, 17);
    AddFirstSoundEntry(15, 0);
    AddEffect(1, -1);
    AddSecondSoundEntry(6, 0);
}
// @fnv 0x0097c560
CombatActionMoveAndAttackGrenade::CombatActionMoveAndAttackGrenade(COMBAT_ACTION action)
    : CombatActionAttackGrenade(action)
{
    RemoveFirstSoundEntryByOwner(3);
    RemoveActionWorldStateByOwner(1);
    RemoveActionWorldStateByOwner(6);
    RemoveActionWorldStateByOwner(5);
    RemoveEffectByOwner(0);
    AddFirstSoundEntry(18, 17);
    AddFirstSoundEntry(15, 0);
    AddEffect(1, -1);
    AddSecondSoundEntry(6, 0);
}
// @fnv 0x0097c700
CombatActionDrawWeapon::CombatActionDrawWeapon(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(12, -1);
    AddFirstSoundEntry(10, 7);
    AddEffect(11, -1);
    AddEffect(10, -1);
}
// @fnv 0x0097c850
CombatActionSwitchWeapon::CombatActionSwitchWeapon(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(12, -1);
    AddEffect(11, -1);
    AddEffect(10, -1);
}
// @fnv 0x0097c9d0
CombatActionAvoidThreat::CombatActionAvoidThreat(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(18, 17);
    AddActionWorldState(1, 14);
    AddEffect(14, 0);
}
// @fnv 0x0097ca60
CombatActionSearch::CombatActionSearch(COMBAT_ACTION action) : CombatAction(action)
{
    AddFirstSoundEntry(18, 17);
    AddActionWorldState(10, -65512);
    AddEffect(3, 0);
}
// @fnv 0x0097cb70
CombatActionInvestigate::CombatActionInvestigate(COMBAT_ACTION action) : CombatAction(action)
{
    AddActionWorldState(10, -65512);
    AddActionWorldState(1, 15);
    AddEffect(3, 0);
}
// @fnv 0x0097cc00
CombatActionDodge::CombatActionDodge(COMBAT_ACTION action) : CombatAction(action)
{
    AddActionWorldState(1, 3);
    AddEffect(6, 0);
}

// @fnv 0x0097ae90
CombatActor* CombatController::GetFieldBC()
{
    return reinterpret_cast<CombatActor*>(m_pkAttacker);
}

// @fnv 0x0097d130
CombatActionApproachTarget::CombatActionApproachTarget(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    AddFirstSoundEntry(3, 0);
    AddActionWorldState(1, 0);
    AddEffect(6, 0);
    AddEffect(5, 1);
}

// @fnv 0x0097d1c0
CombatActionAcquireLineOfSight::CombatActionAcquireLineOfSight(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    AddFirstSoundEntry(3, 0);
    AddActionWorldState(1, 13);
    AddEffect(5, 1);
}

extern int DAT_0108cdd4;
// Constructs a CombatAction of the given type, then calls AddActionWorldState(1, 10) and AddEffect(0x11, -1).
// @fnv 0x0097d250
CombatActionHide::CombatActionHide(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    AddActionWorldState(1, 10);
    AddEffect(0x11, -1);
}

// Forwards aeState and aiValue to AddSoundEntry on the object at offset 0xc of this combat action.
// @fnv 0x00984390
void CombatAction::AddActionWorldState(int aeState, int aiValue)
{
    m_kActionWorldStateNode.AddSoundEntry(aeState, aiValue);
}

// Constructs a CombatAction with the given action type, then calls AddActionWorldState(1, 0xc) and AddEffect(0xf, 0).
// @fnv 0x0097cd30
CombatActionFlee::CombatActionFlee(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    AddActionWorldState(1, 0xc);
    AddEffect(0xf, 0);
}

// Constructs the combat action with aeType, then calls AddActionWorldState(1, -1) and AddEffect(13, -1).
// @fnv 0x0097ce90
CombatActionActivateCombatItem::CombatActionActivateCombatItem(COMBAT_ACTION aeType) : CombatAction(aeType)
{
    AddActionWorldState(1, -1);
    AddEffect(13, -1);
}

// @fnv 0x0097cfe0
CombatActionUseCombatItem::CombatActionUseCombatItem(CombatAction::COMBAT_ACTION aeType) : CombatAction(aeType)
{
    AddActionWorldState(0xd, -1);
    AddEffect(0x10, -1);
}

// @fnv 0x0097b050
unsigned int __fastcall GetFieldValue(unsigned int* pThis)
{
    return pThis[0x39];
}


// @fnv 0x0097d110
int __thiscall CombatState::GetAt(int index)
{
    return *(int*)((int)this + index * 4 + 0x1a4);
}

double __cdecl GetWeaponDPSDeficit(CombatController*, int);


// Returns the sum of FUN_00979e40(apCombatController, aiActionValue) and GetWeaponDPSDeficit(apCombatController, 1).
// @fnv 0x0097b070
// src: XBOX_PDB 0x0097b070
float CombatActionAttackRangedFromCover::GetCost_0097b070(CombatController* apCombatController, int aiActionValue)
{
    return GetCost_00979e40(apCombatController, aiActionValue) + GetWeaponDPSDeficit(apCombatController, 1);
}

namespace fnv_0097b240 {
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
}  // namespace fnv_0097b240

// @fnv 0x0097b240
// src: COMMUNITY 0x0097b240
float CombatActionAttackRangedExplosive::GetCost_0097b240(CombatController* apController, int v)
{
    return GetCost_00979e40(apController, v) + fnv_0097b240::GetWeaponDPSDeficit(apController, 0);
}

namespace fnv_0097b4a0 {
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
}  // namespace fnv_0097b4a0

// Returns the sum of FUN_00979e40(c, v) and fnv_0097b4a0::GetWeaponDPSDeficit(c, 2).
// @fnv 0x0097b4a0
// src: XBOX_PDB 0x0097b4a0
float CombatActionAttackMelee::GetCost_0097b4a0(CombatController* apController, int v)
{
    return GetCost_00979e40(apController, v) + fnv_0097b4a0::GetWeaponDPSDeficit(apController, 2);
}

namespace fnv_0097b5a0 {
extern float DAT_0108cb10;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
}  // namespace fnv_0097b5a0

// @fnv 0x0097b5a0
// src: XBOX_PDB 0x0097b5a0
float CombatActionAttackHandToHand::GetCost_0097b5a0(CombatController* c, int iValue)
{
    if (c->GetFieldBC() && reinterpret_cast<Actor*>(c->GetFieldBC())->IsPlayerTeammate() &&
        reinterpret_cast<Actor*>(c->GetFieldBC())->GetActiveWeapon())
        return fnv_0097b5a0::DAT_0108cb10;
    return GetCost_00979e40(c, iValue) + fnv_0097b5a0::GetWeaponDPSDeficit(c, 6);
}

// @fnv 0x0097b840
// src: XBOX_PDB 0x0097b840
bool CombatActionAttackGrenadeFlushTarget::CanExecute_0097b840(CombatController* apController, CombatWorldStateArray* w, int aiValue)
{
    if (!CanExecute(apController, w, aiValue))
        return false;
    return static_cast<Tile*>(static_cast<CombatControllerAccess*>(apController)->GetCombatState(0xb))->FindCombatLocation_0099ac20();
}

struct B006815c0
{
    void _ref_006815c0();
};

struct FUN_0097b940_shell
{
    void CombatLocation_GetPoint();
};

// @fnv 0x0097b940
// src: XBOX_PDB 0x0097b940
void FUN_0097b940_shell::CombatLocation_GetPoint()
{
    reinterpret_cast<B006815c0*>(this)->_ref_006815c0();
}


// @fnv 0x0097b960
unsigned char CombatState::GetByte76()
{
    return *(reinterpret_cast<unsigned char*>(this) + 0x76);
}

namespace fnv_0097b980 {
extern float DAT_0108cb10;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
}  // namespace fnv_0097b980

// @fnv 0x0097b980
// src: XBOX_PDB 0x0097b980
float CombatActionAttackGrenadeFlushTarget::GetCost_0097b980(CombatController* apCombatController, int v)
{
    float attack = fnv_0097b980::GetWeaponDPSDeficit(apCombatController, 3);
    if (attack >= fnv_0097b980::DAT_0108cb10)
        return fnv_0097b980::DAT_0108cb10;
    return GetCost_00979e40(apCombatController, v) + attack;
}

namespace fnv_0097bb90 {
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
}  // namespace fnv_0097bb90

// Returns the sum of FUN_00979e40(c, v) and fnv_0097bb90::GetWeaponDPSDeficit(c, 3).
// @fnv 0x0097bb90
// src: COMMUNITY 0x0097bb90
float CombatActionAttackGrenadeFromCover::CombatActionAttackGrenade_GetCost(CombatController* apCombatController, int v)
{
    return GetCost_00979e40(apCombatController, v) + fnv_0097bb90::GetWeaponDPSDeficit(apCombatController, 3);
}

bool __cdecl IsCombatActionValid(CombatController*, int);


// @fnv 0x0097bc80
// src: XBOX_PDB 0x0097bc80
bool CombatActionMove::CheckIdentical(CombatController* apCombatController, int aiActionValue)
{
    return IsCombatActionValid(apCombatController, aiActionValue);
}

namespace fnv_0097bca0 {
void __cdecl CombatActionMove_StartMovementProcedure(CombatController*, int);
}


// @fnv 0x0097bca0
// src: XBOX_PDB 0x0097bca0
void CombatActionMove::Execute_0097bca0(CombatController* apCombatController, int aiActionValue)
{
    fnv_0097bca0::CombatActionMove_StartMovementProcedure(apCombatController, aiActionValue);
}

struct Sub
{
    float CombatPlannerData_GetCombatLocationCost();
};
// @fnv 0x0097bcc0
// src: XBOX_PDB 0x0097bcc0
float CombatActionMove::GetCost_0097bcc0(CombatController* apController, int v)
{
    float cost = GetCost_00979e40(apController, v);
    cost += static_cast<CombatControllerAccess*>(apController)->Get(v)->CombatPlannerData_GetCombatLocationCost();
    return cost;
}

// 0x0097bd00 is bound as CombatLocations::FUN_0097bd00 by combatstate.cpp; it reads this+0xb8.
class CombatLocations
{
public:
    float CombatPlannerData_GetCombatLocationCost(unsigned int index);
};

// @fnv 0x0097bd00
// src: XBOX_PDB 0x0097bd00
float CombatLocations::CombatPlannerData_GetCombatLocationCost(unsigned int uiIndex)
{
    return reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb8)[uiIndex];
}


// @fnv 0x0097c150
TESObjectWEAP* CombatState::GetCombatWeapon(int uiIndex)
{
    return reinterpret_cast<TESObjectWEAP**>(reinterpret_cast<char*>(this) + 0xc)[uiIndex];
}


// @fnv 0x0097c470
void CombatActionMoveAndAttackRangedExplosive::FUN_0097c470()
{
    FUN_00979c80();
}

bool __cdecl CombatController_FindCombatLocation(CombatController*, CombatWorldStateArray*, int);
// @fnv 0x0097c490
// src: XBOX_PDB 0x0097c490
bool CombatActionMoveAndAttackRangedExplosive::CombatActionMove_CanExecute(CombatController* apController, CombatWorldStateArray* w, int aiValue)
{
    if (!CanExecute(apController, w, aiValue))
        return false;
    return CombatController_FindCombatLocation(apController, w, aiValue);
}

namespace fnv_0097c4d0 {
extern float DAT_0108cb10;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
}  // namespace fnv_0097c4d0

// Returns DAT_0108cb10 if fnv_0097c4d0::GetWeaponDPSDeficit(c, 0) is at least DAT_0108cb10, otherwise returns FUN_00979e40(c, v).
// @fnv 0x0097c4d0
// src: XBOX_PDB 0x0097c4d0
float CombatActionMoveAndAttackRangedExplosive::GetCost_0097c4d0(CombatController* c, int iValue)
{
    if (fnv_0097c4d0::GetWeaponDPSDeficit(c, 0) >= fnv_0097c4d0::DAT_0108cb10)
        return fnv_0097c4d0::DAT_0108cb10;
    return GetCost_00979e40(c, iValue);
}

extern const char* DAT_011a5700[];
int _sprintf_s(char*, unsigned int, const char*, ...);
// @fnv 0x0097c520
// src: XBOX_PDB 0x0097c520
void CombatActionMoveAndAttackRangedExplosive::CombatActionActivateCombatItem_GetDebugText(char* pcBuffer, unsigned int size, int v)
{
    _sprintf_s(pcBuffer, size, "%s: %s", GetCombatActionName(), DAT_011a5700[v & 0xffff]);
}

namespace fnv_0097c6b0 {
extern float DAT_0108cb10;
float __cdecl GetWeaponDPSDeficit(CombatController*, int);
}  // namespace fnv_0097c6b0

// Returns DAT_0108cb10 if fnv_0097c6b0::GetWeaponDPSDeficit(c, 3) reaches it, otherwise returns FUN_00979e40(c, v).
// @fnv 0x0097c6b0
// src: XBOX_PDB 0x0097c6b0
float CombatActionMoveAndAttackGrenade::GetCost_0097c6b0(CombatController* c, int v)
{
    if (fnv_0097c6b0::GetWeaponDPSDeficit(c, 3) >= fnv_0097c6b0::DAT_0108cb10)
        return fnv_0097c6b0::DAT_0108cb10;
    return GetCost_00979e40(c, v);
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
extern const char* DAT_0118a8a8[];


// Writes "%s: %s" into apDebugText using GetCombatActionName() and DAT_0118a8a8[aiActionValue].
// @fnv 0x0097c990
// src: XBOX_PDB 0x0097c990
void CombatActionDrawWeapon::GetDebugText_0097c990(char* apDebugText, unsigned int aiMaxLength, int aiActionValue)
{
    _sprintf_s(apDebugText, aiMaxLength, "%s: %s", GetCombatActionName(), DAT_0118a8a8[aiActionValue]);
}

namespace fnv_0097ccf0 {

}  // namespace fnv_0097ccf0

// @fnv 0x0097ccf0
// src: XBOX_PDB 0x0097ccf0
void CombatActionIgnoreBlockedTarget::Execute_0097ccf0(CombatController* apCombatController, int aiActionValue)
{
    static_cast<CombatState*>(static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState())->SetTargetBlocked(static_cast<unsigned char>(0));
}


// @fnv 0x0097cd10
void CombatState::SetTargetBlocked(unsigned char v)
{
    *(reinterpret_cast<unsigned char*>(this) + 0x72) = v;
}


// @fnv 0x0097cfc0
int CombatState::GetActionAtIndex(unsigned int uiIndex)
{
    return reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x190)[uiIndex];
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);


// Writes "<name>: <value>" into apDebugText using _sprintf_s, with the name from GetCombatActionName and aiActionValue.
// @fnv 0x0097d370
// src: XBOX_PDB 0x0097d370
void CombatActionHide::GetDebugText_0097d370(char* apDebugText, unsigned int aiMaxLength, int aiActionValue)
{
    _sprintf_s(apDebugText, aiMaxLength, "%s: %i", GetCombatActionName(), aiActionValue);
}

struct FUN_009d8b60
{
    FUN_009d8b60();
    char pad[0x40];
};
// Allocates a new FUN_009d8b60 and passes it to c->FUN_009801b0; v is unused.
// @fnv 0x0097caf0
// src: XBOX_PDB 0x0097caf0
void CombatActionSearch::Execute_0097caf0(CombatController* c, int aiValue)
{
    c->SetMovementProcedure(reinterpret_cast<CombatProcedure*>(new FUN_009d8b60));
}

namespace fnv_0097ae00 {


float __cdecl GetWeaponDPSDeficit(CombatController*, int);

extern float DAT_0108cb10;


}  // namespace fnv_0097ae00

// @fnv 0x0097ae00
// src: XBOX_PDB 0x0097ae00
float CombatActionAttackRanged::GetCost_0097ae00(CombatController* apCombatController, int aiActionValue)
{
    if (apCombatController->GetFieldBC() &&
        reinterpret_cast<Actor*>(apCombatController->GetFieldBC())->IsPlayerTeammate() &&
        reinterpret_cast<Actor*>(apCombatController->GetFieldBC())->ComputeFromNode("CombatStyleMelee") == 1.0)
    {
        return fnv_0097ae00::DAT_0108cb10;
    }
    return CombatAction::GetCost_00979e40(apCombatController, aiActionValue) +
           fnv_0097ae00::GetWeaponDPSDeficit(apCombatController, 1);
}

namespace fnv_0097af70 {

unsigned int __fastcall GetFieldValue(unsigned int*);

struct FUN_009d0890
{
    char pad[0x48];
    FUN_009d0890();
};

struct FUN_009d2440
{
    char pad[0x6c];
    FUN_009d2440(unsigned int);
};


}  // namespace fnv_0097af70

// Creates a FUN_009d0890 and a FUN_009d2440 from GetFieldValue of the controller's combat state, passing both to the controller's FUN_00980110 and FUN_009801b0.
// @fnv 0x0097af70
// src: XBOX_PDB 0x0097af70
void CombatActionAttackRangedFromCover::Execute_0097af70(CombatController* apCombatController, int aiActionValue)
{
    apCombatController->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097af70::FUN_009d0890()));
    apCombatController
        ->SetMovementProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097af70::FUN_009d2440(fnv_0097af70::GetFieldValue((unsigned int*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState()))));
}

namespace fnv_0097b170 {

struct FUN_009d0890
{
    char pad[0x48];
    FUN_009d0890();
};

struct FUN_009d3a00
{
    char pad[0x64];
    FUN_009d3a00();
};


}  // namespace fnv_0097b170

// Allocates a FUN_009d0890 and a FUN_009d3a00 and passes them to FUN_00980110 and FUN_009801b0 on the combat controller.
// @fnv 0x0097b170
// src: COMMUNITY 0x0097b170
void CombatActionAttackRangedExplosive::CombatActionAttackRanged_AddProcedureToController(CombatController* apCombatController, int aiActionValue)
{
    apCombatController->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097b170::FUN_009d0890()));
    apCombatController->SetMovementProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097b170::FUN_009d3a00()));
}

namespace fnv_0097b410 {

struct FUN_009cc0c0
{
    char pad[0x88];
    FUN_009cc0c0();
};


}  // namespace fnv_0097b410

// Allocates a FUN_009cc0c0 object and passes it to the combat controller's FUN_00980110 method.
// @fnv 0x0097b410
// src: COMMUNITY 0x0097b410
void CombatActionAttackMelee::AddProcedureToController(CombatController* apCombatController, int aiActionValue)
{
    apCombatController->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097b410::FUN_009cc0c0));
}

namespace fnv_0097b6d0 {

struct FUN_009cadf0
{
    char pad[0x3c];
    FUN_009cadf0();
};

struct FUN_009d3a00
{
    char pad[0x64];
    FUN_009d3a00();
};


}  // namespace fnv_0097b6d0

// Allocates a FUN_009cadf0 and a FUN_009d3a00 and passes each to the combat controller's FUN_00980110 and FUN_009801b0 methods.
// @fnv 0x0097b6d0
// src: XBOX_PDB 0x0097b6d0
void CombatActionAttackGrenade::Execute_0097b6d0(CombatController* apCombatController, int aiActionValue)
{
    apCombatController->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097b6d0::FUN_009cadf0()));
    apCombatController->SetMovementProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097b6d0::FUN_009d3a00()));
}

namespace fnv_0097b880 {
struct CombatAvoidanceSphere;

int __fastcall GetField18C(char*);

struct FUN_0097b940_shell
{
    int CombatLocation_GetPoint();
};


struct FUN_009caee0
{
    char pad[0x3c];
    FUN_009caee0(int, unsigned char);
};


}  // namespace fnv_0097b880

// @fnv 0x0097b880
// src: XBOX_PDB 0x0097b880
void CombatActionAttackGrenadeFlushTarget::Execute_0097b880(CombatController* apCombatController, int aiActionValue)
{
    CombatState* pcombatState = (CombatState*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState();
    fnv_0097b880::CombatAvoidanceSphere* pcombatLocation =
        (fnv_0097b880::CombatAvoidanceSphere*)fnv_0097b880::GetField18C((char*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState());
    apCombatController
        ->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097b880::FUN_009caee0(((fnv_0097b880::FUN_0097b940_shell*)pcombatLocation)->CombatLocation_GetPoint(),
                                             ((CombatState*)pcombatState)->GetByte76())));
}

namespace fnv_0097bab0 {

unsigned int __fastcall GetFieldValue(unsigned int*);

struct FUN_009cadf0
{
    char pad[0x3c];
    FUN_009cadf0();
};

struct FUN_009d2440
{
    char pad[0x6c];
    FUN_009d2440(unsigned int);
};


}  // namespace fnv_0097bab0

// @fnv 0x0097bab0
// src: XBOX_PDB 0x0097bab0
void CombatActionAttackGrenadeFromCover::Execute_0097bab0(CombatController* apCombatController, int aiActionValue)
{
    apCombatController->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097bab0::FUN_009cadf0()));
    apCombatController
        ->SetMovementProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097bab0::FUN_009d2440(fnv_0097bab0::GetFieldValue((unsigned int*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState()))));
}

namespace fnv_0097c090 {


struct FUN_009da720
{
    char pad[0x18];
    FUN_009da720(TESObjectWEAP*);
};


}  // namespace fnv_0097c090

// @fnv 0x0097c090
// src: XBOX_PDB 0x0097c090
void CombatActionMoveAndSwitchToMelee::Execute_0097c090(CombatController* apCombatController, int aiActionValue)
{
    Execute_0097bca0(apCombatController, aiActionValue);
    TESObjectWEAP* pweapon = ((CombatState*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState())->GetCombatWeapon(2);
    apCombatController->AddBackgroundProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097c090::FUN_009da720(pweapon)));
    static_cast<CombatControllerAccess*>(apCombatController)->SetWeapon((int)pweapon);
}

namespace fnv_0097c280 {

struct FUN_009d0890
{
    char pad[0x48];
    FUN_009d0890();
};

void __cdecl CombatActionMove_StartMovementProcedure(CombatController*, int);


}  // namespace fnv_0097c280

// Allocates a FUN_009d0890 object, passes it to the combat controller's FUN_00980110, then calls FUN_0097bed0 with the action value.
// @fnv 0x0097c280
// src: COMMUNITY 0x0097c280
void CombatActionMoveAndAttackRanged::AddProcedureToController_0097c280(CombatController* apCombatController, int aiActionValue)
{
    apCombatController->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097c280::FUN_009d0890));
    fnv_0097c280::CombatActionMove_StartMovementProcedure(apCombatController, aiActionValue);
}

namespace fnv_0097c310 {


float __cdecl GetWeaponDPSDeficit(CombatController*, int);

extern float DAT_0108cb10;


}  // namespace fnv_0097c310

// Returns DAT_0108cb10 when GetWeaponDPSDeficit reaches it or the actor is a teammate with CombatStyleMelee 1.0, otherwise FUN_00979e40's result.
// @fnv 0x0097c310
// src: XBOX_PDB 0x0097c310
float CombatActionMoveAndAttackRanged::GetCost_0097c310(CombatController* apCombatController, int aiActionValue)
{
    if (fnv_0097c310::GetWeaponDPSDeficit(apCombatController, 1) >= fnv_0097c310::DAT_0108cb10)
    {
        return fnv_0097c310::DAT_0108cb10;
    }
    if (apCombatController->GetFieldBC() &&
        reinterpret_cast<Actor*>(apCombatController->GetFieldBC())->IsPlayerTeammate() &&
        reinterpret_cast<Actor*>(apCombatController->GetFieldBC())->ComputeFromNode("CombatStyleMelee") == 1.0)
    {
        return fnv_0097c310::DAT_0108cb10;
    }
    return CombatAction::GetCost_00979e40(apCombatController, aiActionValue);
}

namespace fnv_0097c620 {

struct FUN_009cadf0
{
    char pad[0x3c];
    FUN_009cadf0();
};

void __cdecl CombatActionMove_StartMovementProcedure(CombatController*, int);


}  // namespace fnv_0097c620

// Allocates a FUN_009cadf0 object, passes it to FUN_00980110 on the controller, then calls FUN_0097bed0 with the action value.
// @fnv 0x0097c620
// src: XBOX_PDB 0x0097c620
void CombatActionMoveAndAttackGrenade::Execute_0097c620(CombatController* apCombatController, int aiActionValue)
{
    apCombatController->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097c620::FUN_009cadf0));
    fnv_0097c620::CombatActionMove_StartMovementProcedure(apCombatController, aiActionValue);
}

namespace fnv_0097c790 {


struct FUN_009da720
{
    char pad[0x18];
    FUN_009da720(TESObjectWEAP*);
};


}  // namespace fnv_0097c790

// @fnv 0x0097c790
// src: COMMUNITY 0x0097c790
void CombatActionDrawWeapon::AddProcedureToController_0097c790(CombatController* apCombatController, int aiActionValue)
{
    TESObjectWEAP* pweapon = 0;
    int ecombatWeaponType = aiActionValue;
    if (aiActionValue != 6)
    {
        pweapon = ((CombatState*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState())->GetCombatWeapon(ecombatWeaponType);
    }
    apCombatController->AddBackgroundProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097c790::FUN_009da720(pweapon)));
    static_cast<CombatControllerAccess*>(apCombatController)->SetWeapon((int)pweapon);
}

namespace fnv_0097c8e0 {

extern float DAT_0108cb10;

bool __fastcall TESObjectWEAP_IsMeleeWeapon(TESObjectWEAP*);


}  // namespace fnv_0097c8e0

// @fnv 0x0097c8e0
// src: XBOX_PDB 0x0097c8e0
float CombatActionSwitchWeapon::GetCost_0097c8e0(CombatController* apCombatController, int aiActionValue)
{
    if (apCombatController->GetFieldBC() &&
        reinterpret_cast<Actor*>(apCombatController->GetFieldBC())->IsPlayerTeammate() &&
        reinterpret_cast<Actor*>(apCombatController->GetFieldBC())->ComputeFromNode("CombatStyleMelee") == 1.0)
    {
        TESObjectWEAP* pweapon = 0;
        int ecombatWeaponType = aiActionValue;
        if (aiActionValue != 6)
        {
            pweapon = ((CombatState*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState())->GetCombatWeapon(ecombatWeaponType);
        }
        if (pweapon && !fnv_0097c8e0::TESObjectWEAP_IsMeleeWeapon(pweapon))
        {
            return fnv_0097c8e0::DAT_0108cb10;
        }
    }
    return CombatAction::GetCost_00979e40(apCombatController, aiActionValue);
}

namespace fnv_0097cdb0 {

extern Setting originalRuntimeFloatSetting432;

unsigned int __fastcall GetFieldValue(unsigned int*);

struct FUN_009d6030
{
    char pad[0x40];
    FUN_009d6030(unsigned int, float, bool, bool);
};


}  // namespace fnv_0097cdb0

// @fnv 0x0097cdb0
// src: XBOX_PDB 0x0097cdb0
void CombatActionFlee::Execute_0097cdb0(CombatController* apCombatController, int aiActionValue)
{
    ((BSFaceGenNiNode*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState())->SetApplyRotToParent(2);
    apCombatController
        ->SetMovementProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097cdb0::FUN_009d6030(fnv_0097cdb0::GetFieldValue((unsigned int*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState()),
                                             *fnv_0097cdb0::originalRuntimeFloatSetting432.Float(), true, true)));
}

class TESObjectREFR;
class TESBoundObject;
namespace fnv_0097cf10 {

struct CombatReferenceEntry
{
    TESObjectREFR* pRef;
    TESBoundObject* m_pBaseObject;
};


struct FUN_009ca5f0
{
    char pad[0x1c];
    FUN_009ca5f0(TESObjectREFR*, TESBoundObject*);
};


}  // namespace fnv_0097cf10

// @fnv 0x0097cf10
// src: XBOX_PDB 0x0097cf10
void CombatActionActivateCombatItem::Execute_0097cf10(CombatController* apCombatController, int aiActionValue)
{
    fnv_0097cf10::CombatReferenceEntry* pcombatItem =
        (fnv_0097cf10::CombatReferenceEntry*)((CombatState*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState())->GetActionAtIndex(static_cast<unsigned int>(aiActionValue - 17));
    if (pcombatItem)
    {
        apCombatController
            ->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097cf10::FUN_009ca5f0(pcombatItem->pRef, pcombatItem->m_pBaseObject)));
    }
}

class TESBoundObject;
namespace fnv_0097d060 {


struct FUN_009daa10
{
    char pad[0x18];
    FUN_009daa10(TESBoundObject*);
};


}  // namespace fnv_0097d060

// Looks up a TESBoundObject for the given action value minus 17 and, if found, passes a new FUN_009daa10 wrapping it to the combat controller.
// @fnv 0x0097d060
// src: XBOX_PDB 0x0097d060
void CombatActionUseCombatItem::Execute_0097d060(CombatController* apCombatController, int aiActionValue)
{
    ::TESBoundObject* pitem =
        (::TESBoundObject*)((CombatState*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState())->GetAt(aiActionValue - 17);
    if (pitem)
    {
        apCombatController->SetActionProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097d060::FUN_009daa10(pitem)));
    }
}

namespace fnv_0097d2d0 {

unsigned int __fastcall GetFieldValue(unsigned int*);

struct FUN_009d6030
{
    char pad[0x40];
    FUN_009d6030(unsigned int, float, int, int);
};


}  // namespace fnv_0097d2d0

// Allocates a FUN_009d6030 from the combat controller's combat state and aiActionValue, then passes it to FUN_009801b0.
// @fnv 0x0097d2d0
// src: XBOX_PDB 0x0097d2d0
void CombatActionHide::Execute_0097d2d0(CombatController* apCombatController, int aiActionValue)
{
    apCombatController
        ->SetMovementProcedure(reinterpret_cast<CombatProcedure*>(new fnv_0097d2d0::FUN_009d6030(
            fnv_0097d2d0::GetFieldValue((unsigned int*)static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState()), (float)aiActionValue, 0, 0)));
}

namespace fnv_0097bed0 {

struct AvoidSphere
{
    float GetRadius() const;
};

struct CombatAvoidanceSphere : AvoidSphere
{
    bool CombatLocation_GetFlag(int);
};

struct FUN_009d5ad0
{
    unsigned char data[0x18];
    FUN_009d5ad0(int);
};

struct FUN_009d69f0
{
    unsigned char data[0x7c];
    FUN_009d69f0(CombatAvoidanceSphere*, float, int);
};

int __fastcall GetField18C(char*);

// @fnv 0x0097bed0
// src: XBOX_PDB 0x0097bed0
void CombatActionMove_StartMovementProcedure(CombatController* apCombatController, int aiLocation)
{
    CombatProcedure* pmovementProcedure = 0;
    CombatAvoidanceSphere* pcombatLocation;

    pcombatLocation = reinterpret_cast<CombatAvoidanceSphere*>(
        GetField18C(reinterpret_cast<char*>(static_cast<CombatControllerAccess*>(apCombatController)->GetCombatState())));

    if (pcombatLocation->CombatLocation_GetFlag(1))
    {
        pmovementProcedure = reinterpret_cast<CombatProcedure*>(new FUN_009d5ad0(aiLocation));
    }
    else
    {
        pmovementProcedure = reinterpret_cast<CombatProcedure*>(
            new FUN_009d69f0(pcombatLocation, pcombatLocation->GetRadius(), aiLocation));
    }

    apCombatController->SetMovementProcedure(pmovementProcedure);
}
}  // namespace fnv_0097bed0

// FUN_0097be60 : thiscall, one stack argument, returns a byte-sized flag test.
//
// The original reads a 32-bit field at this+0x1C, masks it with the
// stack argument and returns the (non-zero) result of that test.
struct FUN_0097be60_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_1c;
    unsigned char CombatLocation_GetFlag(unsigned int aValue);
};

// @fnv 0x0097be60
// src: COMMUNITY 0x0097be60
unsigned char FUN_0097be60_cls::CombatLocation_GetFlag(unsigned int aValue)
{
    return (m_1c & aValue) != 0;
}

struct ActionDescriptor

{

    bool _Call_439090();
};

int __fastcall GetField18C(char*);

int __fastcall GetField38(char*);

unsigned int __fastcall TESMain_GetThread(void*);

// The procedure-specific accessors are not yet declared in the shared header.
class CombatProcedureAccess : public CombatProcedure
{
public:
    int GetSection();
    const char* GetEntryPoint();
    ActionDescriptor* CombatProcedureMove_GetDestinationPos(char*);
};

struct CombatLocationAccess
{
    int GetSection();
    bool CombatLocation_GetFlag(int);
    ActionDescriptor* CombatLocation_GetPoint(ActionDescriptor*);
};

// Checks the current form header and interface tile against the given section and action type, returning false on any mismatch.
// @fnv 0x0097bd20
bool __cdecl IsCombatActionValid(CombatController* controller, int iSection)

{

    CombatProcedure* piStack_c2;

    CombatLocationAccess* iStack_c;

    int iStack_8;

    CombatProcedureAccess* piStack4;

    CombatProcedureAccess* piStack_18;

    struct TargetTemp

    {

        int a;

        int b;

        int c;

    } auStack2;

    piStack_c2 = static_cast<CombatProcedure*>(static_cast<CombatControllerAccess*>(controller)->GetCurrentProcedure());

    if (piStack_c2 == 0)

        return false;

    iStack_c = (CombatLocationAccess*)GetField18C(

        (char*)static_cast<CombatControllerAccess*>(controller)->GetCombatState());

    if (iStack_c == 0 || iStack_c->GetSection() != iSection)

        return false;

    iStack_8 = piStack_c2->GetType();

    if (iStack_8 == 6)

    {

        piStack4 = static_cast<CombatProcedureAccess*>(piStack_c2);

        if (iStack_c->GetSection() != (int)piStack4->GetEntryPoint())

            return false;

        if (TESMain_GetThread(iStack_c) != 0)

        {

            if (TESMain_GetThread(iStack_c) != GetField38((char*)piStack4))

                return false;
        }

        else

        {

            if (iStack_c
                    ->CombatLocation_GetPoint(

                        piStack4->CombatProcedureMove_GetDestinationPos((char*)&auStack2))
                    ->_Call_439090())

                return false;
        }

        if (iStack_c->CombatLocation_GetFlag(1))

            return false;
    }

    else

    {

        if (iStack_8 == 4)

        {

            piStack_18 = static_cast<CombatProcedureAccess*>(piStack_c2);

            if (!iStack_c->CombatLocation_GetFlag(1))

                return false;

            if (iStack_c->GetSection() != piStack_18->GetSection())

                return false;
        }

        else

        {

            return false;
        }
    }

    return true;
}
