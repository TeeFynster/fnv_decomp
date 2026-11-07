// fallout/ai/combatcontroller.cpp: CombatController, CombatPlanner and helpers (89 functions)

// Required by the shared Actor/PlayerCharacter declarations.
enum DIALOGUE_EMOTION;
enum SIT_SLEEP_STATE;

#include "../../../include/Actor.h"
#include "../../../include/ActorCombatGroup.h"
#include "../../../include/ActorMover.h"
#include "../../../include/AnimSequenceBase.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/BSAnimGroupSequence.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BSThread.h"
#include "../../../include/BaseFormComponent.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/CombatController.h"
#include "../../../include/CombatState.h"
#include "../../../include/CombatPlan.h"
#include "../../../include/CombatProcedure.h"
#include "../../../include/CombatPlanner.h"
#include "../../../include/Data.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/Setting.h"
#include "../../../include/TESNPC.h"
#include "../../../include/GameTimerRecord.h"
#include "../../../include/GridArray.h"
#include "../../../include/InventoryChanges.h"
#include "../../../include/InventoryStackRecord.h"
#include "../../../include/MobileObject.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}

inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}

__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}

__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}

inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../../include/NiPoint3.h"
#include "../../../include/TES.h"
#include "../../../include/TESActorBaseData.h"
#include "../../../include/TESContainer.h"
#include "../../../include/TESAnimGroup.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectWEAP.h"

#include "../../../include/NiTPointerMap.h"

// Operations not yet declared by the shared controller header retain their\n// original thiscall ABI through typed call targets.
extern "C" void* ControllerWeaponQuery();
typedef BSAudio* (__thiscall* ControllerWeaponQueryFn)(CombatController*, int);

extern "C" float ControllerPointY();
typedef float (__thiscall* ControllerPointYFn)(CombatController*, int);
// MSVC passes aggregate fastcall arguments on the stack. These free helpers\n// therefore retain ECX for the shared controller and the original stack layout.
template <class T> struct ControllerStackArg { T value; };

extern "C" void ControllerBaseCleanup();
typedef void (__thiscall* ControllerBaseCleanupFn)(CombatController*, int);
extern "C" void ControllerClearCover();
typedef void (__thiscall* ControllerClearCoverFn)(CombatController*);
struct UpdateAction;
extern "C" void ControllerInitFromArg();
typedef void (__thiscall* ControllerInitFromArgFn)(CombatController*, UpdateAction*);
extern "C" void ControllerRemoveTopic();
typedef void (__thiscall* ControllerRemoveTopicFn)(CombatController*);
extern "C" bool ControllerIgnoredActor();
typedef bool (__thiscall* ControllerIgnoredActorFn)(CombatController*, Actor*);
extern "C" void ControllerTargetChanged();
typedef void (__thiscall* ControllerTargetChangedFn)(CombatController*);
extern "C" void ControllerSetFirst();
typedef void (__thiscall* ControllerSetFirstFn)(CombatController*, bool);
extern "C" void ControllerSetSecond();
typedef void (__thiscall* ControllerSetSecondFn)(CombatController*, bool);
extern "C" void ControllerSetRegion();
typedef void (__thiscall* ControllerSetRegionFn)(CombatController*, void*);
extern "C" void ControllerLoadProcedure();
typedef void (__thiscall* ControllerLoadProcedureFn)(CombatController*, CombatProcedure**, BGSLoadFormBuffer*);
// This count writer is absent from BGSSaveGameBuffer.h. Its explicit thiscall
// signature keeps the original ABI without another buffer class definition.
extern "C" void SaveBufferElementCount();
typedef void (__thiscall* SaveBufferElementCountFn)(BGSSaveGameBuffer*, unsigned int);

// These two methods are absent from their shared headers as well.
extern "C" void SetPlayerCombatActor();
typedef void (__thiscall* SetPlayerCombatActorFn)(PlayerCharacter*, Actor*, int);
extern "C" float GetAnimGroupActionTime();
typedef float (__thiscall* GetAnimGroupActionTimeFn)(TESAnimGroup*, int);

// Actor operations not yet declared in the shared header. Keep their original
// thiscall signatures here without introducing another actor layout.
extern "C" void* ActorGetCombatPointer();
typedef void* (__thiscall* ActorPointerQueryFn)(Actor*);
extern "C" float ActorGetFirstCombatValue();
typedef float (__thiscall* ActorFloatQueryFn)(Actor*);
extern "C" unsigned char ActorGetCombatFlag();
typedef unsigned char (__thiscall* ActorByteQueryFn)(Actor*);
extern "C" void ActorSetCombatActive();
typedef void (__thiscall* ActorSetActiveFn)(Actor*, int, int, int);
extern "C" void ActorSetCombatFlag();
typedef void (__thiscall* ActorSetFlagFn)(Actor*, bool);

extern "C" bool ActorCheckCombat();
typedef bool (__thiscall* ActorCheckCombatFn)(Actor*, Actor*, int, int*, int);
extern "C" void ActorRefreshCombatPackage();
typedef void (__thiscall* ActorRefreshPackageFn)(Actor*);

extern "C" bool CombatAnimationState();
typedef bool (__thiscall* CombatAnimationStateFn)(AnimData*);
extern "C" bool ActorCombatState();
typedef bool (__thiscall* ActorCombatStateFn)(Actor*);
typedef void (__thiscall* ActorSetActiveBoolsFn)(Actor*, bool, int, bool);

extern "C" void ActorMoveCombatPoint();
typedef void (__thiscall* ActorMovePointFn)(Actor*, NiPoint3);
extern "C" bool ActorCanMoveCombatPoint();
typedef bool (__thiscall* ActorCanMovePointFn)(Actor*);
// The virtual at 0x4D8 writes a point into caller storage; Actor.h currently
// declares that slot as void Unk_136().
typedef void (__thiscall* ActorAimPointFn)(Actor*, void*, float);

extern "C" unsigned short ActorCombatAnimGroup();
typedef unsigned short (__thiscall* ActorCombatAnimGroupFn)(Actor*, unsigned int, int, bool, int);

// The legacy umbrella header also defines templates supplied by include/.
// Keep only the declarations needed here that have no shared equivalent.
class Point3Offset
{
public:
    NiPoint3 m_kOffset;
    NiPoint3* ProjectileLaunched(NiPoint3* pDest, NiPoint3* pSource);
};

enum ANIM_GROUP_ENUM;

// @fnv 0x00439e90
NiPoint3* Point3Offset::ProjectileLaunched(NiPoint3* pResult, NiPoint3* pSource)
{
    pResult->Set(m_kOffset.x + pSource->x, m_kOffset.y + pSource->y, m_kOffset.z + pSource->z);
    return pResult;
}

// @fnv 0x007031c0
// src: XBOX_PDB 0x007031c0
void* CombatController::GetCurrentWeapon()
{
    return reinterpret_cast<void*>(unkF0);
}

// @fnv 0x0097fb20
// src: XBOX_PDB 0x0097fb20
bool __fastcall CombatState_GetHasTarget360LineOfSight(CombatState* pThis)
{
    // The shared header does not yet expose the flag read by the game at +0x71.
    return *reinterpret_cast<const bool*>(reinterpret_cast<const char*>(pThis) + 0x71);
}

struct FUN_0097e310_shell
{
    int field_0x00;
    int field_0x04;
    int field_0x08;
    bool IsField8One();
};

// @fnv 0x0097e310
bool FUN_0097e310_shell::IsField8One()
{
    return field_0x08 == 1;
}

// @fnv 0x00980250
// src: XBOX_PDB 0x00980250
void CombatController::ClearProcedures()
{
    SetActionProcedure(0);
    SetMovementProcedure(0);
}

struct FUN_00980700_shell
{
    int __thiscall CombatPlannerData_GetLocation(int index);
};

// @fnv 0x00980700
// src: COMMUNITY 0x00980700
int __thiscall FUN_00980700_shell::CombatPlannerData_GetLocation(int index)
{
    return ((int*)this)[index + 2];
}

extern "C" void __cdecl Deallocate(void*);


// Frees the pointer stored at this+0x190+idx*4 and sets that slot to null.
// @fnv 0x00981340
void __fastcall FreeCombatStateSlot(CombatState* state, ControllerStackArg<int> index)
{
    void* p = *(void**)((char*)state + index.value * 4 + 0x190);
    Deallocate(p);
    *(void**)((char*)state + index.value * 4 + 0x190) = 0;
}

// @fnv 0x00981720
// src: XBOX_PDB 0x00981720
void CombatController::ClearLookAtTarget_00981720(unsigned char acIndex)
{
    m_aucStateByIndex[acIndex] = 0;
}

namespace fnv_0097d740 {
void Deallocate(void*);

// Calls FUN_0097d770, then deallocates this when bit 0 of flags is set, and returns this.
}  // namespace fnv_0097d740

// @fnv 0x0097d740
void* CombatController::FUN_0097d740(unsigned int flags)
{
    using namespace fnv_0097d740;
    FUN_0097d770();
    if (flags & 1)
        fnv_0097d740::Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
// Calls FUN_00997aa0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0097d960
void* __fastcall DestroyCombatState(CombatState* state, ControllerStackArg<unsigned int> flags)
{
    state->~CombatState();
    if (flags.value & 1)
        Deallocate(state);
    return state;
}

namespace fnv_0097d990 {

extern "C" void CombatStateInitAmmoState();
typedef void (__thiscall* CombatStateInitAmmoStateFn)(CombatState*);
}  // namespace fnv_0097d990

// @fnv 0x0097d990
// src: COMMUNITY 0x0097d990
void CombatController::FirstUpdate()
{
    using namespace fnv_0097d990;
    UpdateCurrentWeapon();
    reinterpret_cast<CombatStateInitAmmoStateFn>(CombatStateInitAmmoState)(m_pModifier);
    if (!static_cast<MobileObject*>(actor)->GetCurrentProcessLevel())
        CalculateAttackerInfo();
}

void __cdecl Deallocate(void*);

// Calls FUN_0097e3e0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0097e460
void* CombatPlanner::FUN_0097e460(unsigned int flags)
{
    this->CombatPlanner::~CombatPlanner();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void CombatStateNotifyReference();
typedef void (__thiscall* CombatStateNotifyReferenceFn)(CombatState*, void*, bool);

// @fnv 0x0097f7a0
// src: COMMUNITY 0x0097f7a0
void CombatController::ResetEmbeddedWeaponSwitchTimer(void* apArg, bool b)
{
    reinterpret_cast<CombatStateNotifyReferenceFn>(CombatStateNotifyReference)(m_pModifier, apArg, b);
}

// @fnv 0x0097fb60
unsigned int __fastcall GetControllerIdle(CombatController* controller)
{
    return reinterpret_cast<unsigned int>(controller->unkE8.value);
}

void __cdecl Deallocate(void*);
struct Owner
{
    void FUN_00993f70();
    void* ReleaseIfFlagged(unsigned int);
};
// @fnv 0x0097fc40
void* Owner::ReleaseIfFlagged(unsigned int flags)
{
    FUN_00993f70();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// @fnv 0x0097fd40
bool __fastcall CheckControllerActorFlags(const CombatController* controller)
{
    return ((TESActorBaseData*)controller)->GetFlag(3);
}

struct TESEffectShader;
extern "C" void CombatStateSetEffectShader();
typedef void (__thiscall* CombatStateSetEffectShaderFn)(CombatState*, TESEffectShader*);

// @fnv 0x0097fd60
void __fastcall SetControllerEffectShader(CombatController* controller, ControllerStackArg<TESEffectShader*> pShader)
{
    reinterpret_cast<CombatStateSetEffectShaderFn>(CombatStateSetEffectShader)(controller->m_pModifier, pShader.value);
}

struct FUN_00980720_shell
{
    void* __thiscall GetEntryAt(unsigned int index);
};

// @fnv 0x00980720
void* __thiscall FUN_00980720_shell::GetEntryAt(unsigned int index)
{
    return *(void**)((char*)this + 0x60 + index * 4);
}

struct FUN_00980740_shell
{
    void CombatPlannerData_ClearLocation(int index);
};

// Sets the two int fields at offsets 8 and 0x60 for the given index to zero.
// @fnv 0x00980740
// src: COMMUNITY 0x00980740
void __thiscall FUN_00980740_shell::CombatPlannerData_ClearLocation(int index)
{
    *(int*)((char*)this + index * 4 + 8) = 0;
    *(int*)((char*)this + index * 4 + 0x60) = 0;
}

// @fnv 0x009807d0
void CombatController::StopActorMoving()
{
    actor->StopMoving();
}

// @fnv 0x00981300
// src: XBOX_PDB 0x00981300
bool CombatController::TESPackage_GetPretendInCombat()
{
    return (packageFlags & 0x2000000) ? true : false;
}

// @fnv 0x00981320
bool __fastcall IsControllerFlag4Set(CombatController* controller)
{
    return *reinterpret_cast<unsigned short*>(&controller->specificFlags) & 0x4;
}

struct InnerObj
{
    bool CombatGroup_IsSearching();
};

// Returns the result of pAt80->FUN_0097ef30() when pAt80 is set, otherwise returns false.
// @fnv 0x00981420
bool __fastcall CheckControllerGroup(CombatController* controller)
{
    if (reinterpret_cast<InnerObj*>(controller->m_pCombatData))
        return reinterpret_cast<InnerObj*>(controller->m_pCombatData)->CombatGroup_IsSearching();
    return 0;
}

namespace fnv_00981900 {
extern "C" char CombatStateGetKey();
typedef char (__thiscall* CombatStateGetKeyFn)(CombatState*);

}  // namespace fnv_00981900

// @fnv 0x00981900
char CombatController::GetModifierKey(void)
{
    using namespace fnv_00981900;
    return reinterpret_cast<CombatStateGetKeyFn>(CombatStateGetKey)(m_pModifier);
}

extern int DAT_011f1420[];

// @fnv 0x00982070
// src: COMMUNITY 0x00982070
int __cdecl CombatPlan_GetCombatAction(int index)
{
    return DAT_011f1420[index];
}

namespace fnv_00982310 {

// Reverts the combat controller from the load buffer, then calls FUN_0097f390, UpdatePointer, FUN_0097d9d0 and UpdateActorValues.
}  // namespace fnv_00982310

// @fnv 0x00982310
// src: XBOX_PDB 0x00982310
void CombatController::FinishLoadGame_00982310(BGSLoadFormBuffer* apLoadGameBuffer)
{
    using namespace fnv_00982310;
    ((TESNPC*)this)->TESNPC::Revert(apLoadGameBuffer);
    this->UpdateCurrentWeapon();
    this->UpdatePointer();
    this->CalculateAttackerInfo();
    this->UpdateActorValues();
}

struct Calendar
{
    unsigned int GetDaysPassed();
};
struct TESWorldSpace;
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;
bool __fastcall CombatCoverMap_IsCurrentThreadWriting(unsigned int);
void __fastcall CombatCoverMap_UnlockForWrite(unsigned int);

// @fnv 0x00995830
// src: XBOX_PDB 0x00995830
void CombatPlanner::CleanUp_00995830()
{
    while (CombatCoverMap_IsCurrentThreadWriting(reinterpret_cast<Calendar*>(BGSSaveLoadGlobalDataWorldspacePtr)->GetDaysPassed()))
    {
        CombatCoverMap_UnlockForWrite(reinterpret_cast<Calendar*>(BGSSaveLoadGlobalDataWorldspacePtr)->GetDaysPassed());
    }
}

struct ActorValueOwner;
struct AlchemyItem;
struct BGSListForm;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct ExtraDataList;
struct ExtraLeveledItem;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryIterator;
struct NiAVObject;
struct NiColor;
struct IndexedPointerCollection;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESFile;
struct TESLevItem;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

typedef char _sizecheck_InventoryChanges[sizeof(InventoryChanges) == 20 ? 1 : -1];

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

struct BSSimpleListRef
{
    void* GetItem();
    int GetIndex();
};

// Returns the original container count for apObject plus the change-list index, treating an empty change entry as one item.
// @fnv 0x004c8f30
int InventoryChanges::GetObjectCount(int apObject)
{
    int icount = 0;
    TESContainer* porigContainer =
        GetOriginalContainer();
    icount = porigContainer ? porigContainer->GetObjectCount(reinterpret_cast<TESObject*>(apObject)) : 0;
    if (icount < 0)
        icount *= -1;
    InventoryStackRecord* pchange =
        GetOrCreateInventoryEntry(reinterpret_cast<TESBoundObject*>(apObject), true, 0);
    if (pchange)
    {
        if (icount == 0 && !reinterpret_cast<BSSimpleListRef*>(pchange)->GetItem())
            icount = 1;
        else
            icount += reinterpret_cast<BSSimpleListRef*>(pchange)->GetIndex();
    }
    return icount;
}

struct FUN_00666f00_shell
{
    bool CombatProcedure_GetFinished();
};

// @fnv 0x009804d0
// src: COMMUNITY 0x009804d0
bool CombatController::GetProcedureFinished()
{
    if (*((int*)this + 0x21) && ((FUN_00666f00_shell*)*((int*)this + 0x21))->CombatProcedure_GetFinished())
        return true;
    if (*((int*)this + 0x22) && ((FUN_00666f00_shell*)*((int*)this + 0x22))->CombatProcedure_GetFinished())
        return true;
    if (!*((int*)this + 0x21) && !*((int*)this + 0x22))
        return true;
    return false;
}

// Cover operations absent from the shared declarations keep their original ABI.
extern "C" void CombatStateCoverOperation();
extern "C" void CombatStateSecondaryCoverOperation();
typedef void (__thiscall* CombatStateCoverFn)(CombatState*, CombatCoverPointData*);

// @fnv 0x00980770
void __fastcall UpdateCombatStateCover(CombatState* state)
{
    reinterpret_cast<CombatStateCoverFn>(CombatStateCoverOperation)(state,
        *reinterpret_cast<CombatCoverPointData**>(reinterpret_cast<char*>(state) + 0xe4));
}

// @fnv 0x009807b0
void __fastcall UpdateCombatStateSecondaryCover(CombatState* state)
{
    reinterpret_cast<CombatStateCoverFn>(CombatStateSecondaryCoverOperation)(state,
        *reinterpret_cast<CombatCoverPointData**>(reinterpret_cast<char*>(state) + 0xe4));
}

// @fnv 0x00981970
char __fastcall HasControllerWeapon(CombatController* controller)
{
    return reinterpret_cast<ControllerWeaponQueryFn>(ControllerWeaponQuery)(controller, 5) != 0;
}

struct TESObjectWEAP;

// @fnv 0x0097f390
// src: COMMUNITY 0x0097f390
void CombatController::UpdateCurrentWeapon()
{
    BSAudio* tmp;
    (*reinterpret_cast<void**>(&unkF0)) = 0;
    tmp = reinterpret_cast<ControllerWeaponQueryFn>(ControllerWeaponQuery)(this, 5);
    if (tmp)
        (*reinterpret_cast<void**>(&unkF0)) = tmp->GetAudioBackendData();
    else
        (*reinterpret_cast<void**>(&unkF0)) = actor->GetActiveWeapon();
}

extern "C" void CombatStateSetAttackerInt();
typedef void (__thiscall* CombatStateSetAttackerIntFn)(CombatState*, int);

// Replaces _pF4 with the result of reinterpret_cast<ActorPointerQueryFn>(ActorGetCombatPointer)(_pBC); if the old value was non-null and differs, notifies _p9c and calls FUN_0097f200.
// @fnv 0x0097f3f0
void CombatController::UpdatePointer()
{
    void* pOld = (*reinterpret_cast<void**>(&unkF4));
    (*reinterpret_cast<void**>(&unkF4)) = reinterpret_cast<ActorPointerQueryFn>(ActorGetCombatPointer)(actor);
    if (pOld != 0 && pOld != (*reinterpret_cast<void**>(&unkF4)))
    {
        reinterpret_cast<CombatStateSetAttackerIntFn>(CombatStateSetAttackerInt)(m_pModifier, 1);
        ForcePlanUpdate();
    }
}

typedef int COMBAT_WEAPON_TYPE;

// Clears the current weapon pointer if the combat state's weapon lookup for its type no longer returns that same weapon.
// @fnv 0x0097f470
void CombatController::ValidateCurrentWeapon()
{
    if ((*reinterpret_cast<TESObjectWEAP**>(&unkF0)))
    {
        COMBAT_WEAPON_TYPE eWeaponType = (*reinterpret_cast<TESObjectWEAP**>(&unkF0))->TESObjectWEAP_GetCombatWeaponType();
        if (m_pModifier->GetCombatWeapon(eWeaponType) != (*reinterpret_cast<TESObjectWEAP**>(&unkF0)))
            (*reinterpret_cast<TESObjectWEAP**>(&unkF0)) = 0;
    }
}

extern "C" void CombatStateNotifyAction();
typedef void (__thiscall* CombatStateNotifyActionFn)(CombatState*);
struct Unk84976
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int);
};

// Clears bF9, calls FUN_0099a720 on p9c, and if p84 is non-null calls its v7 with a1.
// @fnv 0x0097f6d0
// src: XBOX_PDB 0x0097f6d0
void CombatController::Disarmed_0097f6d0(int a1)
{
    byteF9 = 0;
    reinterpret_cast<CombatStateNotifyActionFn>(CombatStateNotifyAction)(m_pModifier);
    if (reinterpret_cast<Unk84976*>(m_pkCurrentProcedure) != 0)
        reinterpret_cast<Unk84976*>(m_pkCurrentProcedure)->v7(a1);
}

void __fastcall CombatStateSetStampFromActor(CombatState*, ControllerStackArg<int>)
{}

// @fnv 0x0097f7d0
void __fastcall ForwardControllerStamp(CombatController* controller, ControllerStackArg<int> arg)
{
    CombatStateSetStampFromActor(controller->m_pModifier, arg);
}

extern "C" void CombatStateNotifyAmount();
typedef void (__thiscall* CombatStateNotifyAmountFn)(CombatState*, int, float);

// Forwards the two arguments to the inner object's FUN_0099a6b0 method through the stored pointer.
// @fnv 0x0097f7f0
void __fastcall ForwardControllerAmount(CombatController* controller, ControllerStackArg<int> a, ControllerStackArg<float> b)
{
    reinterpret_cast<CombatStateNotifyAmountFn>(CombatStateNotifyAmount)(controller->m_pModifier, a.value, b.value);
}

namespace fnv_0097f9c0 {
extern PlayerCharacter* pPlayer;

}  // namespace fnv_0097f9c0

// @fnv 0x0097f9c0
// src: XBOX_PDB 0x0097f9c0
void CombatController::RemoveTarget_0097f9c0(Actor* apActor)
{
    using namespace fnv_0097f9c0;
    if (apActor == pPlayer)
        reinterpret_cast<SetPlayerCombatActorFn>(SetPlayerCombatActor)(pPlayer, (::Actor*)m_pkAttacker, 0);
    if (reinterpret_cast<ActorCombatGroup*>(m_pCombatData) != 0)
        reinterpret_cast<ActorCombatGroup*>(m_pCombatData)->RemoveByTarget(apActor);
}

struct FUN_0097e310_holder
{
    bool IsField8One();
};

bool FUN_0097e310_holder::IsField8One()
{
    return false;
}

// Returns true if field_84 or field_88 is set and its IsField8One check returns true; otherwise false.
// @fnv 0x00980470
// src: COMMUNITY 0x00980470
bool CombatController::GetProcedureFailed()
{
    if (reinterpret_cast<FUN_0097e310_holder*>(m_pkCurrentProcedure) && reinterpret_cast<FUN_0097e310_holder*>(m_pkCurrentProcedure)->IsField8One())
        return true;
    if (reinterpret_cast<FUN_0097e310_holder*>(m_pkQueuedProcedure) && reinterpret_cast<FUN_0097e310_holder*>(m_pkQueuedProcedure)->IsField8One())
        return true;
    return false;
}

struct Helper009807f0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool Foo(int a, int b);
};

// Returns false if m_ptr is null, otherwise forwards a and b to m_ptr->Foo and returns its result.
// @fnv 0x009807f0
bool __fastcall CallControllerProcedure(CombatController* controller, ControllerStackArg<int> aiArg1, ControllerStackArg<int> aiArg2)
{
    if (!reinterpret_cast<Helper009807f0*>(controller->m_pkCurrentProcedure))
        return false;
    return reinterpret_cast<Helper009807f0*>(controller->m_pkCurrentProcedure)->Foo(aiArg1.value, aiArg2.value);
}

// If fieldD4 is set and fieldC7 differs from arg, stores arg in fieldC7 and calls FUN_009815f0 with fieldC8.
// @fnv 0x00981520
void CombatController::SetFieldC7(unsigned char ucValue)
{
    if (!byteD4)
        return;
    if (byteC7 != ucValue)
    {
        byteC7 = ucValue;
        CombatController_SetActualMoveMode(unkC8);
    }
}

namespace fnv_00981660 {

// Sets m_uiCombatState to 0 and calls FUN_009815f0 with the new state.
}  // namespace fnv_00981660

// @fnv 0x00981660
void CombatController::ResetCombatState()
{
    using namespace fnv_00981660;
    m_uiCombatState = 0;
    CombatController_SetActualMoveMode(m_uiCombatState);
}

namespace fnv_00981690 {

// Returns 1 unless apCombatProcedure equals the second stored procedure pointer, in which case it returns 0.
}  // namespace fnv_00981690

// @fnv 0x00981690
// src: XBOX_PDB 0x00981690
unsigned int CombatController::GetLookAtTargetIndex(CombatProcedure* apCombatProcedure)
{
    using namespace fnv_00981690;
    if (apCombatProcedure == m_pkCurrentProcedure)
        return 1;
    else
    {
        if (apCombatProcedure == m_pkQueuedProcedure)
            return 0;
    }
    return 1;
}

// Stores a look-at target point and a priority byte into the slot selected by acIndex.
// @fnv 0x009816d0
// src: XBOX_PDB 0x009816d0
void CombatController::SetLookAtTarget(unsigned char acIndex, const NiPoint3& arLookAtTarget, unsigned char acPriority)
{
    unk128[acIndex] = arLookAtTarget;
    m_aucStateByIndex[acIndex] = acPriority;
}


// Returns true when the inner object's FUN_0097ee90 check returns false.
// @fnv 0x009818b0
bool __fastcall CheckControllerState(CombatController* controller)
{
    return !controller->m_pModifier->GetHasBufferedDetection_0097ee90();
}

extern "C" void CombatStateSetByte();
typedef void (__thiscall* CombatStateSetByteFn)(CombatState*, unsigned char);

// Forwards the byte argument to the method on the object at m_0x9c.
// @fnv 0x009818e0
void __fastcall SetControllerStateByte(CombatController* controller, ControllerStackArg<unsigned char> aucValue)
{
    reinterpret_cast<CombatStateSetByteFn>(CombatStateSetByte)(controller->m_pModifier, aucValue.value);
}

// @fnv 0x00981990
// src: XBOX_PDB 0x00981990
bool CombatController::IsFleeing_00981990()
{
    return CombatController_CombatPlanContainsAction(0x15) || unk144 == 5;
}

extern "C" void CombatStateSetAttackerBool();
typedef void (__thiscall* CombatStateSetAttackerBoolFn)(CombatState*, bool);

// Forwards the boolean argument to the inner object's SetAttacker.
// @fnv 0x009819d0
void __fastcall SetControllerAttacker(CombatController* controller, ControllerStackArg<bool> a)
{
    reinterpret_cast<CombatStateSetAttackerBoolFn>(CombatStateSetAttackerBool)(controller->m_pModifier, a.value);
}

namespace fnv_009819f0 {

// Exe 0x009819f0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatcontrollerOffset08View
{
    unsigned int GetFlags();
};

struct FUN_006797c0_shell
{
    void TESPackage_SaveGame(void*);
};
struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer*);
};

}  // namespace fnv_009819f0

// @fnv 0x009819f0
// src: XBOX_PDB 0x009819f0
void CombatController::SaveGame_009819f0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    using namespace fnv_009819f0;
    ((FUN_006797c0_shell*)this)->TESPackage_SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SerializeFormData(m_pkAttacker, 0);
    apSaveGameBuffer->SerializeFormData(pTarget, 0);
    unsigned int icombatGroupID = static_cast<const GridArray*>(reinterpret_cast<GridArray*>(m_pCombatData))->GetCenterX();
    apSaveGameBuffer->SaveData((void*)&icombatGroupID, 4, 0);
    m_pModifier->SaveToStream(apSaveGameBuffer);
    CombatProcedure_SaveGame_(&pProc84, apSaveGameBuffer);
    CombatProcedure_SaveGame_(&pProc88, apSaveGameBuffer);
    {
        unsigned int uiProcedureCount = (fnv_009819f0::CombatcontrollerOffset08View*)(&unk8C) ? ((fnv_009819f0::CombatcontrollerOffset08View*)(&unk8C))->GetFlags() : 0;
        reinterpret_cast<SaveBufferElementCountFn>(SaveBufferElementCount)(apSaveGameBuffer, uiProcedureCount);
        for (unsigned int i = 0; i < uiProcedureCount; i++)
        {
            CombatProcedure** pbackgroundProcedure =
                (CombatProcedure**)&((BSSimpleArray<unsigned int, 2>*)(&unk8C))->GetAt(i);
            CombatProcedure_SaveGame_(pbackgroundProcedure, apSaveGameBuffer);
        }
    }
    bool bhasPlan = m_pCombatPlan;
    apSaveGameBuffer->SaveData((void*)&bhasPlan, 1, 0);
    if (bhasPlan)
        m_pCombatPlan->SaveToBuffer(apSaveGameBuffer);
    char cThreadID = (char)(m_pCombatThread ? m_pCombatThread->GetThreadID() : -1);
    apSaveGameBuffer->SaveData((void*)&cThreadID, 1, 0);
    apSaveGameBuffer->SaveData((void*)&ib0, 4, 0);
    ((FUN_009a5eb0_shell*)(&unkB4))->FUN_009a5eb0(apSaveGameBuffer);
    apSaveGameBuffer->SaveData((void*)&cc7, 1, 0);
    apSaveGameBuffer->SaveData((void*)&ic8, 4, 0);
    apSaveGameBuffer->SaveData((void*)&id8, 4, 0);
    apSaveGameBuffer->SaveData((void*)&idc, 4, 0);
    apSaveGameBuffer->SaveData((void*)&ce4, 1, 0);
    apSaveGameBuffer->SaveData((void*)&c125, 1, 0);
    apSaveGameBuffer->SaveData((void*)&c126, 1, 0);
    apSaveGameBuffer->SaveData((void*)&i144, 4, 0);
    apSaveGameBuffer->SaveData((void*)&i148, 4, 0);
    for (unsigned int i = 0; i < 2; i++)
    {
        apSaveGameBuffer->SaveData((void*)&unk128[i], 12, 0);
        apSaveGameBuffer->SaveData((void*)&m_aucStateByIndex[i], 1, 0);
    }
    apSaveGameBuffer->SaveData((void*)&c142, 1, 0);
    apSaveGameBuffer->SaveData((void*)&cc6, 1, 0);
    apSaveGameBuffer->SaveData((void*)&cc5, 1, 0);
}

namespace fnv_0097ef50 {

extern double _gModifierZero;

// @fnv 0x0097ef50
void __fastcall ResetControllerModifier(CombatController* controller)
{
    if (controller->m_fCombatModifier > _gModifierZero)
    {
        if (controller->m_pkAttacker->IsPathing())
        {
            controller->m_pkAttacker->Actor_UpdateActorMover(controller->m_fCombatModifier);
            controller->m_pkAttacker->Virtual_348(controller->m_fCombatModifier, 0);
        }
        controller->m_fCombatModifier = 0.0f;
    }
}
}  // namespace fnv_0097ef50

namespace fnv_0097f4d0 {

struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};

struct Class80
{
    void* SelectActor(void*);
};

}  // namespace fnv_0097f4d0

// @fnv 0x0097f4d0
// src: XBOX_PDB 0x0097f4d0
bool CombatController::StopCombat_0097f4d0(void* arg)
{
    using namespace fnv_0097f4d0;
    bool result = false;
    if (arg)
    {
        RemoveTarget_0097f9c0(arg);
        if (field_c0 == arg)
        {
            SetTarget_00980830(reinterpret_cast<Class80*>(m_pCombatData)->SelectActor(pActor));
            if (field_c0 == 0)
            {
                ((CombatController*)this)->ClearProcedures();
                DestroyOwnedObject();
                ((CombatController*)this)->ForcePlanUpdate();
            }
        }
    }
    else
    {
        result = true;
    }

    if (((Actor*)((TESAmmoInitCalls*)this)->GetFieldBC())->GetBlocked())
    {
        ((Actor*)((TESAmmoInitCalls*)this)->GetFieldBC())->CanStartCombat(false);
    }

    return result;
}

class TESObjectREFR;
class TESBoundObject;
namespace fnv_0097f820 {


// Forwards the activation to the combat state, then to each non-null combat procedure.
}  // namespace fnv_0097f820

// @fnv 0x0097f820
void CombatController::ProcessActivation(TESObjectREFR* apRef, TESBoundObject* apObject, int aiCount,
                                           bool abActivatedScriptOnly)
{
    using namespace fnv_0097f820;
    m_pModifier->ActivatedReference(reinterpret_cast<::TESObjectREFR*>(apRef), reinterpret_cast<::TESBoundObject*>(apObject), aiCount, abActivatedScriptOnly);
    if (m_pkCurrentProcedure)
    {
        m_pkCurrentProcedure->OnInventoryItemChanged((::TESObjectREFR*)apRef, (::TESBoundObject*)apObject, aiCount, abActivatedScriptOnly);
    }
    if (m_pkQueuedProcedure)
    {
        m_pkQueuedProcedure->OnInventoryItemChanged((::TESObjectREFR*)apRef, (::TESBoundObject*)apObject, aiCount, abActivatedScriptOnly);
    }
}

namespace fnv_0097f930 {
struct CombatManagerSaveLoad
{
    ActorCombatGroup* CombatManager_SplitPlayerCombatGroup(Actor*);
};

extern void* _g_thePlayer;
extern void* BGSSaveLoadGlobalDataWorldspacePtr;

}  // namespace fnv_0097f930

// @fnv 0x0097f930
// src: XBOX_PDB 0x0097f930
void CombatController::AddTarget_0097f930(Actor* apTarget, int iPriority, bool abHighPriority, float afDamageDone,
                                      float afDamageTaken)
{
    using namespace fnv_0097f930;
    if (!apTarget)
        return;

    if (apTarget == _g_thePlayer)
    {
        reinterpret_cast<SetPlayerCombatActorFn>(SetPlayerCombatActor)((PlayerCharacter*)_g_thePlayer, (::Actor*)m_pkAttacker, 1);
        if ((*reinterpret_cast<ActorCombatGroup**>(&m_pCombatData)) == (ActorCombatGroup*)((PlayerCharacter*)_g_thePlayer)->GetCombatGroup())
        {
            (*reinterpret_cast<ActorCombatGroup**>(&m_pCombatData)) = ((CombatManagerSaveLoad*)fnv_0097f930::BGSSaveLoadGlobalDataWorldspacePtr)->CombatManager_SplitPlayerCombatGroup(m_pkAttacker);
        }
    }

    (*reinterpret_cast<ActorCombatGroup**>(&m_pCombatData))->CombatGroup_AddTarget(apTarget);
}

namespace fnv_0097fb80 {
struct Owner
{
    ~Owner();
};

// Constructs a CombatPlanner, obtains an Owner via FUN_00994bd0(this, 1), then deletes it.
// @fnv 0x0097fb80
void __fastcall PlanControllerActions(CombatController* controller)
{
    CombatPlanner planner;
    Owner* ptr = (Owner*)planner.CreatePlan_0(controller, 1);
    delete ptr;
}
}  // namespace fnv_0097fb80

namespace fnv_0097feb0 {
class Animation;
struct FUN_00497280_shell
{
    unsigned int GetFieldAt124();
};

// @fnv 0x0097feb0
// src: XBOX_PDB 0x0097feb0
float CombatController_GetPowerAttackHitTime(Actor* apActor, ANIM_GROUP_ENUM aePowerAttack)
{
    unsigned short eanimGroup = apActor->GetAnimGroup(aePowerAttack, 0, false, 0);
    if (TESAnimGroup::IsValidAnimationGroup(eanimGroup))
    {
        Animation* panim = reinterpret_cast<Animation*>(apActor->GetAnimData());
        AnimSequenceBase* panimSeq;
        if (((NiTPointerMap<unsigned short, AnimSequenceBase*>*)((FUN_00497280_shell*)panim)->GetFieldAt124())
                ->GetAt(eanimGroup, panimSeq))
        {
            TESAnimGroup* panimGroup = panimSeq->GetSequenceAtIndex(-1)->GetAnimGroup();
            return reinterpret_cast<GetAnimGroupActionTimeFn>(GetAnimGroupActionTime)(panimGroup, 1) -
                   reinterpret_cast<GetAnimGroupActionTimeFn>(GetAnimGroupActionTime)(panimGroup, 0);
        }
    }
    return -1.0f;
}
}  // namespace fnv_0097feb0

namespace fnv_00980110 {

// Deletes the current action procedure, stores apActionProcedure, and calls Unk08 on it if non-null.
}  // namespace fnv_00980110

// @fnv 0x00980110
// src: XBOX_PDB 0x00980110
void CombatController::SetActionProcedure(CombatProcedure* apActionProcedure)
{
    using namespace fnv_00980110;
    if (m_pkCurrentProcedure)
    {
        m_pkCurrentProcedure->Unk0c();
        delete m_pkCurrentProcedure;
    }
    m_pkCurrentProcedure = apActionProcedure;
    if (m_pkCurrentProcedure)
    {
        m_pkCurrentProcedure->Unk08((::CombatController*)this);
    }
}

namespace fnv_009801b0 {

// Deletes the current procedure after calling Unk0c, stores apMovementProcedure, and calls Unk08 on it with this.
}  // namespace fnv_009801b0

// @fnv 0x009801b0
// src: XBOX_PDB 0x009801b0
void CombatController::SetMovementProcedure(CombatProcedure* apMovementProcedure)
{
    using namespace fnv_009801b0;
    if (m_pkQueuedProcedure)
    {
        m_pkQueuedProcedure->Unk0c();
        delete m_pkQueuedProcedure;
    }
    m_pkQueuedProcedure = apMovementProcedure;
    if (m_pkQueuedProcedure)
    {
        m_pkQueuedProcedure->Unk08((::CombatController*)this);
    }
}

namespace fnv_00980270 {
// Exe 0x00980270: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatcontrollerOffset08View
{
    unsigned int GetFlags();
};

struct LS3de0
{
    void UpdateEntryValue(unsigned int, unsigned int);
};

// Scans the procedure array at offset 0x8c for a matching type, removes and deletes it, then appends apBackgroundProcedure and calls its Unk08 with this.
}  // namespace fnv_00980270

// @fnv 0x00980270
// src: XBOX_PDB 0x00980270
void CombatController::AddBackgroundProcedure(CombatProcedure* apBackgroundProcedure)
{
    using namespace fnv_00980270;
    for (unsigned int i = 0; i < ((fnv_00980270::CombatcontrollerOffset08View*)((char*)this + 0x8c))->GetFlags(); ++i)
    {
        CombatProcedure* pbackgroundProcedure =
            (CombatProcedure*)((BSSimpleArray<void*, 1024>*)((char*)this + 0x8c))->GetAt(i);
        if (pbackgroundProcedure->GetType() == apBackgroundProcedure->GetType())
        {
            pbackgroundProcedure->Unk0c();
            delete pbackgroundProcedure;
            ((LS3de0*)((char*)this + 0x8c))->UpdateEntryValue(i, 1);
            break;
        }
    }

    ((BSSimpleArray<void*, 1024>*)((char*)this + 0x8c))->Add((void*&)apBackgroundProcedure);
    apBackgroundProcedure->Unk08((::CombatController*)this);
}

// Exe 0x00980360: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatcontrollerOffset08View
{
    unsigned int GetFlags();
};

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct Item
{
    virtual ~Item();
    virtual void v1();
    virtual void v2();
    virtual void Func_0c();
};

// Calls Func_0c on each item in targets, deletes it, then clears the array.
// @fnv 0x00980360
// src: COMMUNITY 0x00980360
void CombatController::ClearBackgroundProcedures()
{
    for (unsigned int i = 0; i < ((CombatcontrollerOffset08View*)&(*reinterpret_cast<BSSimpleArray<Item*, 1024>*>(&unk8C)))->GetFlags(); i++)
    {
        Item* item = (*reinterpret_cast<BSSimpleArray<Item*, 1024>*>(&unk8C)).GetAt(i);
        item->Func_0c();
        delete item;
    }
    ((GlobalObject_00869f00*)&(*reinterpret_cast<BSSimpleArray<Item*, 1024>*>(&unk8C)))->Clear(true);
}

namespace fnv_00980a30 {
struct C99
{
    void CombatState_ClearReferencePointer(int, int);
};

// Forwards arg to field_9c and both combat procedures, then calls FUN_0097f4d0 if field_c0 equals arg.
}  // namespace fnv_00980a30

// @fnv 0x00980a30
// src: COMMUNITY 0x00980a30
void CombatController::ClearReferencePointers(int arg)
{
    using namespace fnv_00980a30;
    if (reinterpret_cast<C99*>(field_9c))
        reinterpret_cast<C99*>(field_9c)->CombatState_ClearReferencePointer(arg, 0);

    if (m_pkCurrentProcedure)
        m_pkCurrentProcedure->Unk10(arg);

    if (m_pkQueuedProcedure)
        m_pkQueuedProcedure->Unk10(arg);

    if (reinterpret_cast<int>(field_c0) == arg)
        StopCombat_0097f4d0(reinterpret_cast<int>(field_c0));
}

class TESPackage;
namespace fnv_00981380 {

struct ExtraH
{
    void CombatController_ForceStopCombat();
};

struct FUN_0067a700_shell
{
    bool TESPackage_GetContinueDuringCombat();
};

struct FUN_0067a720_shell
{
    void SetFlag4000000(bool);
};

struct FUN_00898200_Owner
{
    void SetFlag2000000(bool);
};

struct AIProcess
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d0a();
    virtual void d0b();
    virtual void d0c();
    virtual void d0d();
    virtual void d0e();
    virtual void d0f();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d1a();
    virtual void d1b();
    virtual void d1c();
    virtual void d1d();
    virtual void d1e();
    virtual void d1f();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d2a();
    virtual void d2b();
    virtual void d2c();
    virtual bool MethodB4(TES*, TESPackage**);
};

}  // namespace fnv_00981380

// @fnv 0x00981380
// src: XBOX_PDB 0x00981380
void CombatController::FinishedPackageTask()
{
    using namespace fnv_00981380;
    bool bResult;
    if (((CombatController*)this)->TESPackage_GetPretendInCombat() || ((FUN_0067a700_shell*)this)->TESPackage_GetContinueDuringCombat())
    {
        ::TESPackage* package = 0;
        bResult = ((AIProcess*)reinterpret_cast<TES*>(pActor)->GetLogDate())->MethodB4(reinterpret_cast<TES*>(pActor), &package);
        if (bResult)
        {
            ((ExtraH*)this)->CombatController_ForceStopCombat();
        }
        else if (package)
        {
            ((ActorMover*)this)->SetupPackageTarget((::TESPackage*)package);
        }
        else
        {
            ((FUN_00898200_Owner*)this)->SetFlag2000000(false);
            ((FUN_0067a720_shell*)this)->SetFlag4000000(false);
        }
    }
}

namespace fnv_00981450 {

struct HA
{
    int GetAnimAction();
};

struct AIProcess
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual void d064();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual int vfunc_20c();
};

}  // namespace fnv_00981450

// @fnv 0x00981450
// src: COMMUNITY 0x00981450
bool CombatController::ShouldStopCombat()
{
    using namespace fnv_00981450;
    if (byte_125)
        return true;

    if (!field_c0 && !reinterpret_cast<PathingSolution*>(m_pCombatData)->GetVirtualNodeCount() && !((CombatController*)this)->TESPackage_GetPretendInCombat())
    {
        bool bResult = true;
        if (((HA*)reinterpret_cast<TES*>(pActor))->GetAnimAction() != -1)
        {
            bResult = false;
        }
        else if (((AIProcess*)reinterpret_cast<TES*>(pActor)->GetLogDate())->vfunc_20c())
        {
            bResult = false;
        }

        if (bResult)
            return true;
        else
        {
            byte_126 = true;
            return false;
        }
    }

    byte_126 = false;
    return false;
}

namespace fnv_00981570 {
extern unsigned int DAT_011a4884[];
extern const float DAT_01016088;
extern const float runtimeFloatSettingDefault375;

}  // namespace fnv_00981570

// @fnv 0x00981570
// src: XBOX_PDB 0x00981570
void CombatController::SetMoveMode(int aeCombatMoveMode)
{
    using namespace fnv_00981570;
    unsigned int imoveMode = DAT_011a4884[aeCombatMoveMode];
    floatD8 = 1.0f;
    floatDC = 1.0f;
    m_pkAttacker->SetWalkRunFlagDirty();

    switch (aeCombatMoveMode)
    {
    case 1:
        floatD8 = DAT_01016088;
        break;
    case 4:
        floatDC = runtimeFloatSettingDefault375;
        break;
    }

    CombatController_SetActualMoveMode(imoveMode);
}

namespace fnv_009948f0 {

struct Item
{
    BSThread* thread;
    char pad[8];
    int field_c;
};

struct FUN_009948f0_shell
{
    Item** data;
    unsigned int count;
    unsigned int field_8;
    GameTimerRecord* timer;

    void SaveToBuffer(BGSSaveFormBuffer* buffer);
};

// Saves the item count, each item's thread ID and field_c, field_8, and the timer's time to the buffer.
// @fnv 0x009948f0
void FUN_009948f0_shell::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    char m_cLastByteBeforePayloadItem;
    unsigned int i;

    buffer->SaveData((void*)&count, 4, 0);
    for (i = 0; i < count; ++i)
    {
        char cprocedureType;
        Item* item = data[i];
        cprocedureType = item->thread->GetThreadID();
        buffer->SaveData((void*)&cprocedureType, 1, 0);
        buffer->SaveData((void*)&item->field_c, 4, 0);
    }
    buffer->SaveData((void*)&field_8, 4, 0);
    m_cLastByteBeforePayloadItem = timer->GetTime();
    buffer->SaveData((void*)&m_cLastByteBeforePayloadItem, 1, 0);
}
}  // namespace fnv_009948f0

extern "C" void CombatStateNotifyTargetChanged();
typedef void (__thiscall* CombatStateNotifyTargetChangedFn)(CombatState*);
struct Vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};

// Calls FUN_0099a8d0 on the object at offset 0x9c, then invokes v9 on the objects at offsets 0x84 and 0x88 if they are non-null.
// @fnv 0x0097f8c0
void __fastcall NotifyControllerTargetChanged(CombatController* controller)
{
    reinterpret_cast<CombatStateNotifyTargetChangedFn>(CombatStateNotifyTargetChanged)(controller->m_pModifier);
    if (*(void**)((char*)controller + 0x84))
        ((Vtbl*)*(void**)((char*)controller + 0x84))->v9();
    if (*(void**)((char*)controller + 0x88))
        ((Vtbl*)*(void**)((char*)controller + 0x88))->v9();
}

namespace fnv_009805b0 {

struct FUN_00980700_shell
{
    int CombatPlannerData_GetLocation(int);
    void* GetEntryAt(unsigned int);
    void CombatPlannerData_ClearLocation(int);
};

extern "C" void CombatStateSetCoverValue();
typedef void (__thiscall* CombatStateSetCoverValueFn)(CombatState*, int);

extern "C" void CombatStateSetSecondaryCoverValue();
typedef void (__thiscall* CombatStateSetSecondaryCoverValueFn)(CombatState*, int);

extern "C" void CombatStateClearPointer();
typedef void (__thiscall* CombatStateClearPointerFn)(CombatState*);

extern "C" void CombatStateUpdateCover();
typedef void (__thiscall* CombatStateUpdateCoverFn)(CombatState*);

extern "C" void CombatStateSetAvoidanceValue();
typedef void (__thiscall* CombatStateSetAvoidanceValueFn)(CombatState*, int);

int __fastcall GetField18C(char*);
unsigned int __fastcall GetFieldValue(unsigned int*);

// @fnv 0x009805b0
void __fastcall RemoveControllerTopic(CombatController* controller)
{
    int topic =
        (*(BSAudio**)((char*)controller + 0xa0) != 0) ? (int)(*(BSAudio**)((char*)controller + 0xa0))->GetAudioBackendData() : -1;
    bool found = false;
    bool removed = false;

    if (topic != -1)
    {
        int scriptVar = (*(FUN_00980700_shell**)((char*)controller + 0xa4))->CombatPlannerData_GetLocation(topic);

        if (scriptVar != 0)
        {
            found = true;
            reinterpret_cast<CombatStateSetAvoidanceValueFn>(CombatStateSetAvoidanceValue)(controller->m_pModifier, scriptVar);

            void* data = (*(FUN_00980700_shell**)((char*)controller + 0xa4))->GetEntryAt(topic);

            if (data != 0)
            {
                removed = true;
                reinterpret_cast<CombatStateSetCoverValueFn>(CombatStateSetCoverValue)(controller->m_pModifier, (int)data);
            }

            (*(FUN_00980700_shell**)((char*)controller + 0xa4))->CombatPlannerData_ClearLocation(topic);
        }
        else
        {
            int timer = GetField18C((char*)(*(void**)((char*)controller + 0x9c)));

            if (timer != 0 && ((GameTimerRecord*)timer)->GetTime() == topic)
            {
                found = true;
            }

            unsigned int result = GetFieldValue((unsigned int*)(*(void**)((char*)controller + 0x9c)));

            if (result != 0 && *(unsigned int*)(result + 4) == (unsigned int)topic)
            {
                removed = true;
            }
        }
    }

    if (!found)
    {
        reinterpret_cast<CombatStateClearPointerFn>(CombatStateClearPointer)(controller->m_pModifier);
    }

    if (removed)
    {
        reinterpret_cast<CombatStateUpdateCoverFn>(CombatStateUpdateCover)(controller->m_pModifier);
    }
    else
    {
        reinterpret_cast<CombatStateSetSecondaryCoverValueFn>(CombatStateSetSecondaryCoverValue)(controller->m_pModifier, 0);
    }
}
}  // namespace fnv_009805b0

CombatProcedure* __cdecl CreateCombatProcedure(int);

// Reads a procedure type byte from the load buffer; if not 0xFF, looks up the procedure, assigns it, and calls its virtual load methods.
// @fnv 0x009823c0
void __fastcall LoadControllerProcedure(CombatController* controller, ControllerStackArg<CombatProcedure**> arpProcedure, ControllerStackArg<BGSLoadFormBuffer*> apLoadGameBuffer)
{
    char cprocedureType;
    cprocedureType = 0xff;
    apLoadGameBuffer.value->ReadTypedData((void*)&cprocedureType, (unsigned int)1);
    if (cprocedureType != -1)
    {
        *arpProcedure.value = CreateCombatProcedure(cprocedureType);
        (*arpProcedure.value)->Unk08((::CombatController*)controller);
        (*arpProcedure.value)->LoadGame(apLoadGameBuffer.value);
    }
}

struct SaveLoadStub
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
    bool GetInitingForms() const;
};
struct DataHandlerStub
{
    bool TESDataHandler_GetClearingData();
};
struct SaveLoadGameStub
{
    bool FUN_0047c850();
};
extern SaveLoadStub* g_BGSSaveLoadGame;
extern DataHandlerStub* g_dataHandler;
extern SaveLoadGameStub* g_TESSaveLoadGame;
extern int g_iCombatControllerCount;

// @fnv 0x0097d770
CombatController::~CombatController()
{
    byteF8 = true;
    if (g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading() && !g_BGSSaveLoadGame->GetInitingForms())
    {
        unk80 = 0;
    }
    if (!g_dataHandler->TESDataHandler_GetClearingData())
    {
        SetTarget_00980830(0);
        SetMovementProcedure(0);
        reinterpret_cast<Actor*>(GetFieldBC())->ClearLookAtTarget();
        reinterpret_cast<ActorSetActiveFn>(ActorSetCombatActive)(reinterpret_cast<Actor*>(GetFieldBC()), 0, 0, 0);
        SetActionProcedure(0);
    }
    ClearBackgroundProcedures();
    DestroyOwnedObject();
    if (unk80)
    {
        unk80->CombatGroup_RemoveMember(reinterpret_cast<CombatActor*>(actor));
    }
    delete unk9C;
    reinterpret_cast<ControllerBaseCleanupFn>(ControllerBaseCleanup)(this, 1);
    if (!g_TESSaveLoadGame->FUN_0047c850() && reinterpret_cast<Actor*>(GetFieldBC()) && reinterpret_cast<Actor*>(GetFieldBC())->GetBlocked())
    {
        reinterpret_cast<ActorSetFlagFn>(ActorSetCombatFlag)(reinterpret_cast<Actor*>(GetFieldBC()), false);
    }
    if (--g_iCombatControllerCount < 0)
    {
        g_iCombatControllerCount = 0;
    }
}

class Target0097d9d0
{
  public:
    bool Query005f0c80();
};

// Copies values from m_pSub into m_cc, m_d0, m_d4 and sets m_d5 to the inverse of the sub target's Query005f0c80 result.
// @fnv 0x0097d9d0
// src: COMMUNITY 0x0097d9d0
void CombatController::CalculateAttackerInfo()
{
    floatCC = reinterpret_cast<ActorFloatQueryFn>(ActorGetFirstCombatValue)(actor);
    floatD0 = actor->Actor_GetSneakHeight(0);
    (*reinterpret_cast<unsigned char*>(&byteD4)) = reinterpret_cast<ActorByteQueryFn>(ActorGetCombatFlag)(actor);
    (*reinterpret_cast<unsigned char*>(&byteD5)) = (unsigned char)(reinterpret_cast<Target0097d9d0*>(actor->FUN_004181e0())->Query005f0c80() ? 0 : 1);
}

struct Selection
{
    bool __thiscall Lookup();
};
struct Container
{
    Selection* __thiscall FUN_00497280(unsigned short handle, unsigned int* output);
};

// @fnv 0x0097f310
// src: COMMUNITY 0x0097f310
bool __cdecl CombatController_CheckHasEquip(Actor* pOwner, int value)
{
    bool result = false;
    unsigned short handle = reinterpret_cast<ActorCombatAnimGroupFn>(ActorCombatAnimGroup)(pOwner, 0x18, value, value == 0, 0);
    if (handle != 0)
    {
        Container* container = reinterpret_cast<Container*>(pOwner->GetAnimData());
        if (container != 0)
        {
            unsigned int output;
            if (container->FUN_00497280(handle, &output)->Lookup())
            {
                result = true;
            }
        }
    }
    return result;
}

extern "C" void CombatStateNotifyParameter();
typedef void (__thiscall* CombatStateNotifyParameterFn)(CombatState*, int);

struct FUN_0097f720_target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int);
};

// Forwards pParam to field_9c, then calls v8(pParam) on field_84 and field_88 when they are non-null.
// @fnv 0x0097f720
// src: COMMUNITY 0x0097f720
void CombatController::FiredProjectile(int pParam)
{
    reinterpret_cast<CombatStateNotifyParameterFn>(CombatStateNotifyParameter)(m_pModifier, pParam);

    if (reinterpret_cast<FUN_0097f720_target*>(m_pkCurrentProcedure) != 0)
        reinterpret_cast<FUN_0097f720_target*>(m_pkCurrentProcedure)->v8(pParam);

    if (reinterpret_cast<FUN_0097f720_target*>(m_pkQueuedProcedure) != 0)
        reinterpret_cast<FUN_0097f720_target*>(m_pkQueuedProcedure)->v8(pParam);
}

struct ControllerStateHandle { unsigned int value; };

// @fnv 0x0097fb40
ControllerStateHandle* __fastcall GetControllerStateHandle(CombatController* controller, ControllerStackArg<ControllerStateHandle*> result)
{
    *result.value = *reinterpret_cast<ControllerStateHandle*>(&controller->m_pModifier);
    return result.value;
}

class SpawnedObject;
class FUN_00980400_list
{
  public:
    unsigned int GetSize();
    SpawnedObject** GetAt(unsigned int index);
};
class SpawnedObject
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int v34();
};

// Scans the list for the first SpawnedObject whose v34() equals target and returns it, otherwise returns 0.
// @fnv 0x00980400
SpawnedObject* __fastcall FindControllerProcedure(CombatController* controller, ControllerStackArg<int> target)
{
    for (unsigned int i = 0; i < (*reinterpret_cast<FUN_00980400_list*>(&controller->unk8C)).GetSize(); i++)
    {
        SpawnedObject* obj = *(*reinterpret_cast<FUN_00980400_list*>(&controller->unk8C)).GetAt(i);
        if (obj->v34() == target.value)
        {
            return obj;
        }
    }
    return 0;
}

extern Setting gFloatSetting;
NiPoint3 GetRefPos(Actor* a);

// Picks the highest-weight point above minWeight and moves the actor there, otherwise moves it to its aim position or stops it.
// @fnv 0x00981740
void CombatController::UpdateMoveTarget()
{
    Actor* actor2 = reinterpret_cast<Actor*>(GetFieldBC());
    int bestIdx = -1;
    unsigned int best3 = 1;
    for (unsigned int i = 0; i < 2; i++)
    {
        if (m_aucStateByIndex[i] >= best3)
        {
            best3 = m_aucStateByIndex[i];
            bestIdx = i;
        }
    }
    if (bestIdx != -1 && best3 >= byte142 + 1)
    {
        reinterpret_cast<ActorMovePointFn>(ActorMoveCombatPoint)(actor2, reinterpret_cast<NiPoint3*>(unk128)[bestIdx]);
    }
    else if (*gFloatSetting.Float() > 0.0 && actor2->IsPathing() && reinterpret_cast<ActorCanMovePointFn>(ActorCanMoveCombatPoint)(actor2))
    {
        struct { float x, y, z; } aim;
        reinterpret_cast<ActorAimPointFn>((*reinterpret_cast<void***>(actor2))[0x136])(actor2, &aim, *gFloatSetting.Float());
        NiPoint3 pos4 = GetRefPos(actor2);
        aim.z += pos4.z - static_cast<const Actor*>(actor2)->GetPos()->z;
        reinterpret_cast<ActorMovePointFn>(ActorMoveCombatPoint)(actor2, *reinterpret_cast<NiPoint3*>(&aim));
    }
    else
    {
        actor2->ClearLookAtTarget();
    }
}

struct FUN_00982350_target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual void v14(void* pOwner);
};

struct FUN_00982350_sink
{
    void FUN_00865e50(char* pFlag, int a, int b);
};

// @fnv 0x00982350
// src: COMMUNITY 0x00982350
void CombatController::CombatProcedure_SaveGame_(CombatProcedure** pHolder, BGSSaveFormBuffer* pSink)
{
    char flag = (char)((*reinterpret_cast<FUN_00982350_target**>(pHolder)) != 0 ? (*reinterpret_cast<FUN_00982350_target**>(pHolder))->v13() : -1);
    reinterpret_cast<FUN_00982350_sink*>(pSink)->FUN_00865e50(&flag, 1, 0);
    if ((*reinterpret_cast<FUN_00982350_target**>(pHolder)) != 0)
    {
        (*reinterpret_cast<FUN_00982350_target**>(pHolder))->v14(pSink);
    }
}

// Combat controller update, reconstructed from the assigned image.
extern unsigned char DAT_011a4880;
struct UpdateAction
{
    virtual ~UpdateAction();
    virtual void Update();
    virtual void Slot08();
    virtual void Stop();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void Slot30();
    bool IsField8One();
    bool CombatProcedure_GetFinished();
};
struct UpdateProcess
{
    virtual void Slot000();
    virtual void Slot004();
    virtual void Slot008();
    virtual void Slot00c();
    virtual void Slot010();
    virtual void Slot014();
    virtual void Slot018();
    virtual void Slot01c();
    virtual void Slot020();
    virtual void Slot024();
    virtual void Slot028();
    virtual void Slot02c();
    virtual void Slot030();
    virtual void Slot034();
    virtual void Slot038();
    virtual void Slot03c();
    virtual void Slot040();
    virtual void Slot044();
    virtual void Slot048();
    virtual void Slot04c();
    virtual void Slot050();
    virtual void Slot054();
    virtual void Slot058();
    virtual void Slot05c();
    virtual void Slot060();
    virtual void Slot064();
    virtual void Slot068();
    virtual void Slot06c();
    virtual void Slot070();
    virtual void Slot074();
    virtual void Slot078();
    virtual void Slot07c();
    virtual void Slot080();
    virtual void Slot084();
    virtual void Slot088();
    virtual void Slot08c();
    virtual void Slot090();
    virtual void Slot094();
    virtual void Slot098();
    virtual void Slot09c();
    virtual void Slot0a0();
    virtual void Slot0a4();
    virtual void Slot0a8();
    virtual void Slot0ac();
    virtual void Slot0b0();
    virtual void Slot0b4();
    virtual void Slot0b8();
    virtual void Slot0bc();
    virtual void Slot0c0();
    virtual void Slot0c4();
    virtual void Slot0c8();
    virtual void Slot0cc();
    virtual void Slot0d0();
    virtual void Slot0d4();
    virtual void Slot0d8();
    virtual void Slot0dc();
    virtual void Slot0e0();
    virtual void Slot0e4();
    virtual void Slot0e8();
    virtual void Slot0ec();
    virtual void Slot0f0();
    virtual void Slot0f4();
    virtual void Slot0f8();
    virtual void Slot0fc();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10c();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11c();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12c();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13c();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14c();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15c();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16c();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17c();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18c();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19c();
    virtual void Slot1a0();
    virtual void Slot1a4();
    virtual void Slot1a8();
    virtual void Slot1ac();
    virtual void Slot1b0();
    virtual void Slot1b4();
    virtual void Slot1b8();
    virtual void Slot1bc();
    virtual void Slot1c0();
    virtual void Slot1c4();
    virtual void Slot1c8();
    virtual void Slot1cc();
    virtual void Slot1d0();
    virtual void Slot1d4();
    virtual void Slot1d8();
    virtual void Slot1dc();
    virtual void Slot1e0();
    virtual void Slot1e4();
    virtual void Slot1e8();
    virtual void Slot1ec();
    virtual void Slot1f0();
    virtual void Slot1f4();
    virtual void Slot1f8();
    virtual void Slot1fc();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20c();
    virtual void Slot210();
    virtual void Slot214();
    virtual void Slot218();
    virtual void Slot21c();
    virtual void Slot220();
    virtual void Slot224();
    virtual void Slot228();
    virtual void Slot22c();
    virtual void Slot230();
    virtual void Slot234();
    virtual void Slot238();
    virtual void Slot23c();
    virtual void Slot240();
    virtual void Slot244();
    virtual void Slot248();
    virtual void Slot24c();
    virtual void Slot250();
    virtual void Slot254();
    virtual void Slot258();
    virtual void Slot25c();
    virtual void Slot260();
    virtual void Slot264();
    virtual void Slot268();
    virtual void Slot26c();
    virtual void Slot270();
    virtual void Slot274();
    virtual void Slot278();
    virtual void Slot27c();
    virtual void Slot280();
    virtual void Slot284();
    virtual void Slot288();
    virtual void Slot28c();
    virtual void Slot290();
    virtual void Slot294();
    virtual void Slot298();
    virtual void Slot29c();
    virtual void Slot2a0();
    virtual void Slot2a4();
    virtual void Slot2a8();
    virtual void Slot2ac();
    virtual void Slot2b0();
    virtual void Slot2b4();
    virtual void Slot2b8();
    virtual void Slot2bc();
    virtual void Slot2c0();
    virtual void Slot2c4();
    virtual void Slot2c8();
    virtual void Slot2cc();
    virtual void Slot2d0();
    virtual void Slot2d4();
    virtual void Slot2d8();
    virtual void Slot2dc();
    virtual void Slot2e0();
    virtual void Slot2e4();
    virtual void Slot2e8();
    virtual void Slot2ec();
    virtual void Slot2f0();
    virtual void Slot2f4();
    virtual void Slot2f8();
    virtual void Slot2fc();
    virtual void Slot300();
    virtual void Slot304();
    virtual void Slot308();
    virtual void Slot30c();
    virtual void Slot310();
    virtual void Slot314();
    virtual void Slot318();
    virtual void Slot31c();
    virtual void Slot320();
    virtual void Slot324();
    virtual void Slot328();
    virtual void Slot32c();
    virtual void Slot330();
    virtual void Slot334();
    virtual void Slot338();
    virtual void Slot33c();
    virtual void Slot340();
    virtual void Slot344();
    virtual void Slot348();
    virtual void Slot34c();
    virtual void Slot350();
    virtual void Slot354();
    virtual void Slot358();
    virtual void Slot35c();
    virtual void Slot360();
    virtual void Slot364();
    virtual void Slot368();
    virtual void Slot36c();
    virtual void Slot370();
    virtual void Slot374();
    virtual void Slot378();
    virtual void Slot37c();
    virtual void Slot380();
    virtual void Slot384();
    virtual void Slot388();
    virtual void Slot38c();
    virtual void Slot390();
    virtual void Slot394();
    virtual void Slot398();
    virtual void Slot39c();
    virtual void Slot3a0();
    virtual void Slot3a4();
    virtual void Slot3a8();
    virtual void Slot3ac();
    virtual void Slot3b0();
    virtual void Slot3b4();
    virtual void Slot3b8();
    virtual void Slot3bc();
    virtual void Slot3c0();
    virtual void Slot3c4();
    virtual void Slot3c8();
    virtual void Slot3cc();
    virtual void Slot3d0();
    virtual void Slot3d4();
    virtual void Slot3d8();
    virtual void Slot3dc();
    virtual void Slot3e0();
    virtual void Slot3e4();
    virtual void Slot3e8();
    virtual void Slot3ec();
    virtual void Slot3f0();
    virtual void Slot3f4();
    virtual void Slot3f8();
    virtual void Slot3fc();
    virtual void Slot400();
    virtual void Slot404();
    virtual void Slot408();
    virtual void Slot40c();
    virtual void Slot410();
    virtual void Slot414();
    virtual void Slot418();
    virtual void Slot41c();
    virtual void Slot420();
    virtual void Slot424();
    virtual void Slot428();
    virtual void Slot42c();
    virtual void Slot430();
    virtual void Slot434();
    virtual void Slot438();
    virtual void Slot43c();
    virtual void Slot440();
    virtual void Slot444();
    virtual void Slot448();
    virtual void Slot44c();
    virtual void Slot450();
    virtual void Slot454();
    virtual void Slot458();
    virtual void Slot45c();
    virtual void Slot460();
    virtual void Slot464();
    virtual void Slot468();
    virtual void Slot46c();
    virtual void Slot470();
    virtual void Slot474();
    virtual void Slot478();
    virtual void Slot47c();
    virtual void Slot480();
    virtual void Slot484();
    virtual void Slot488();
    virtual void Slot48c();
    virtual void Slot490();
    virtual void Slot494();
    virtual void Slot498();
    virtual void Slot49c();
    virtual void Slot4a0();
    virtual void Slot4a4();
    virtual void Slot4a8();
    virtual void Slot4ac();
    virtual void Slot4b0();
    virtual void Slot4b4();
    virtual void Slot4b8();
    virtual void Slot4bc();
    virtual void Slot4c0();
    virtual void Slot4c4();
    virtual void Slot4c8();
    virtual void Slot4cc();
    virtual void Slot4d0();
    virtual void Slot4d4();
    virtual void Slot4d8();
    virtual void Slot4dc();
    virtual void Slot4e0();
    virtual void Slot4e4();
    virtual void Slot4e8();
    virtual void Slot4ec();
    virtual void Slot4f0();
    virtual void Slot4f4();
    virtual void Slot4f8();
    virtual void Slot4fc();
    virtual void Slot500();
    virtual void Slot504();
    virtual void Slot508();
    virtual void Slot50c();
    virtual void Slot510();
    virtual void Slot514();
    virtual void Slot518();
    virtual void Slot51c();
    virtual void Slot520();
    virtual void Slot524();
    virtual void Slot528();
    virtual void Slot52c();
    virtual void Slot530();
    virtual void Slot534();
    virtual void Slot538();
    virtual void Slot53c();
    virtual void Slot540();
    virtual void Slot544();
    virtual void Slot548();
    virtual void Slot54c();
    virtual void Slot550();
    virtual void Slot554();
    virtual void Slot558();
    virtual void Slot55c();
    virtual void Slot560();
    virtual void Slot564();
    virtual void Slot568();
    virtual void Slot56c();
    virtual void Slot570();
    virtual void Slot574();
    virtual void Slot578();
    virtual void Slot57c();
    virtual void Slot580();
    virtual void Slot584();
    virtual void Slot588();
    virtual void Slot58c();
    virtual void Slot590();
    virtual void Slot594();
    virtual void Slot598();
    virtual void Slot59c();
    virtual void Slot5a0();
    virtual void Slot5a4();
    virtual void Slot5a8();
    virtual void Slot5ac();
    virtual void Slot5b0();
    virtual void Slot5b4();
    virtual void Slot5b8();
    virtual void Slot5bc();
    virtual void Slot5c0();
    virtual void Slot5c4();
    virtual void Slot5c8();
    virtual void Slot5cc();
    virtual void Slot5d0();
    virtual void Slot5d4();
    virtual void Slot5d8();
    virtual void Slot5dc();
    virtual void Slot5e0();
    virtual void Slot5e4();
    virtual void Slot5e8();
    virtual void Slot5ec();
    virtual void Slot5f0();
    virtual void Slot5f4();
    virtual void Slot5f8();
    virtual void Slot5fc();
    virtual void Slot600();
    virtual void Slot604();
    virtual void Slot608();
    virtual void Slot60c();
    virtual int GetState();
};
struct DurationTracker
{
    unsigned int time;
    unsigned int duration;
    bool FUN_008d7f80();
    void FUN_008d7f40(float);
};
struct UpdatePlan
{
    bool CombatPlan_IsFinished();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void AdvanceActions(CombatController*);
};
struct UpdateGroup
{
    void CombatGroup_NotifyMemberPlanFinished(CombatController*, unsigned int);
    int SelectActor(void*);
};
// These state operations are not yet declared by CombatState.h.
extern "C" void CombatStateUpdate();
typedef void (__thiscall* CombatStateVoidFn)(CombatState*);
extern "C" bool CombatStateGetUpdateFlag();
typedef bool (__thiscall* CombatStateBoolFn)(CombatState*);
extern "C" void CombatStateUpdateStageHolders();
struct UpdateActionArray
{
    void* vtable;
    UpdateAction** data;
    unsigned int size;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    UpdateAction*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
    void BSSimpleArray_Actor_1024_RemoveFast(unsigned int, unsigned int);
};
struct UpdateClock
{
    void FUN_00483710();
};
extern UpdateClock DAT_011f15cc;
// Base constructor clears 2039 pointer-sized search buckets (0x1fdc bytes).
struct SearchNode;

// @fnv 0x0097da50
// src: COMMUNITY 0x0097da50
void CombatController::Update_0097da50()
{
    if (!DAT_011a4880)
        return;
    if (byte126)
        return;
    Actor* actor2 = reinterpret_cast<Actor*>(GetFieldBC());
    if (!actor2 || !reinterpret_cast<UpdateProcess*>(actor2->FUN_008d8520()))
        return;
    if (ShouldStopCombat())
    {
        actor2->Unk_10D(0);
        return;
    }
    // The actor currently being targeted.
    AnimData* current = actor2->GetAnimData();
    if (!actor2->GetNiNode() || !current)
        return;
    int state6 = reinterpret_cast<UpdateProcess*>(actor2->FUN_008d8520())->GetState();
    if (state6 != 0 && state6 != 2 && state6 != 1)
        return;
    if (actor2->GetSitSleepState())
        return;
    if (!byteE4)
    {
        FirstUpdate();
        byteE4 = 1;
    }
    if (actor2->GetIsDying())
        return;
    if (actor2->HasHealth(false))
    {
        actor2->Unk_10D(0);
        return;
    }
    UpdateCurrentWeapon();
    Actor* actor = reinterpret_cast<Actor*>(CombatController_GetTarget());
    if (actor && ((actor->HasHealth(false) && !actor->GetIsDying()) || actor->FUN_00440da0() || actor->FUN_00440d80()))
    {
        actor2->Unk_10D(actor);
        return;
    }
    short key = actor2->m_pBaseProcess->GetAnimAction();
    // Creature categories excluded from this update.
    bool creature = key == 8 || key == 10;
    if (creature || actor2->GetHasKnockedState() || actor2->GetIsParalyzed())
        return;
    reinterpret_cast<CombatStateVoidFn>(CombatStateUpdate)(m_pModifier);
    if (byte125)
        return;
    if (reinterpret_cast<CombatStateBoolFn>(CombatStateGetUpdateFlag)(m_pModifier))
        return;
    if (reinterpret_cast<CombatAnimationStateFn>(CombatAnimationState)(current))
        return;
    if (actor2->GetHasKnockedState())
        return;
    if (reinterpret_cast<ActorCombatStateFn>(ActorCombatState)(actor2))
        return;
    bool changed = false;
    if (GetProcedureFailed())
    {
        changed = true;
        if (reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure) && reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure)->IsField8One())
            reinterpret_cast<ControllerInitFromArgFn>(ControllerInitFromArg)(this, reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure));
        if (reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure) && reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure)->IsField8One())
            reinterpret_cast<ControllerInitFromArgFn>(ControllerInitFromArg)(this, reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure));
    }
    if (unkB4.FUN_008d7f80())
        changed = true;
    if (!changed && GetProcedureFinished() && (*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan)))
    {
        if ((*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan))->CombatPlan_IsFinished())
        {
            reinterpret_cast<UpdateGroup*>(m_pCombatData)->CombatGroup_NotifyMemberPlanFinished(this, (*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan))->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
            changed = true;
        }
        else
        {
            (*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan))->AdvanceActions(this);
        }
    }
    if (changed)
    {
        DestroyOwnedObject();
        ClearBackgroundProcedures();
        SetTarget_00980830(reinterpret_cast<void*>(reinterpret_cast<UpdateGroup*>(m_pCombatData)->SelectActor(this->actor)));
        if (reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure))
            reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure)->Slot2c();
        if (reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure))
            reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure)->Slot2c();
        DAT_011f15cc.FUN_00483710();
        CombatPlanner search;
        (*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan)) = (UpdatePlan*)search.CreatePlan_0(this, 0);
        unkAC = (*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan)) ? (*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan))->GetHavokWorldObjectCountInSceneGraph_0084e3a0() : 0;
        reinterpret_cast<ControllerRemoveTopicFn>(ControllerRemoveTopic)(this);
        search.CleanUp_00995830();
        unkA4 = 0;
        DAT_011f15cc.FUN_00483710();
        unkB4.FUN_008d7f40(1.0f);
        if ((*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan)))
        {
            (*reinterpret_cast<UpdatePlan**>(&m_pCombatPlan))->AdvanceActions(this);
        }
        else
        {
            ClearProcedures();
            m_pCombatThread = 0;
        }
        if (reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure))
            reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure)->Slot30();
        if (reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure))
            reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure)->Slot30();
        reinterpret_cast<CombatStateVoidFn>(CombatStateUpdateStageHolders)(m_pModifier);
        UpdateCurrentWeapon();
    }
    if (reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure))
        reinterpret_cast<UpdateAction*>(m_pkQueuedProcedure)->Update();
    if (reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure))
        reinterpret_cast<UpdateAction*>(m_pkCurrentProcedure)->Update();
    if (!actor2->Actor_IsInCombat())
        return;
    for (unsigned int i = 0; i < (*reinterpret_cast<UpdateActionArray*>(&unk8C)).FUN_0044ddc0(); ++i)
    {
        UpdateAction* item = (*reinterpret_cast<UpdateActionArray*>(&unk8C)).BSSimpleArray_NiAVObject_1024_GetAt(i);
        item->Update();
        if (item->CombatProcedure_GetFinished() || item->IsField8One())
        {
            if (item->IsField8One())
                reinterpret_cast<ControllerInitFromArgFn>(ControllerInitFromArg)(this, item);
            item->Stop();
            delete item;
            (*reinterpret_cast<UpdateActionArray*>(&unk8C)).BSSimpleArray_Actor_1024_RemoveFast(i, 1);
            --i;
        }
    }
    UpdateMoveTarget();
    bool finishedVal = false;
    reinterpret_cast<ActorSetActiveBoolsFn>(ActorSetCombatActive)(actor2, (*reinterpret_cast<signed char*>(&byteC6)) == 1, 0, finishedVal);
    unk144 = 0;
}

struct CSProcess
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual float GetAmount(Actor* apActor, Actor* apTarget);
};

struct CSTracker
{
    void Notify(Actor* apTarget, Actor* apActor);
};

// Initializes if needed, notifies pTracker, then if apActor is not self/target and has a process, adds its amount when CheckA succeeds and it is not ignored.
// @fnv 0x0097f580
void __fastcall NotifyControllerDamage(CombatController* controller, ControllerStackArg<Actor*> apActor, ControllerStackArg<int> aiUnused)
{
    if (!(*reinterpret_cast<bool*>(&controller->byteE4)))
    {
        controller->FirstUpdate();
        (*reinterpret_cast<bool*>(&controller->byteE4)) = true;
    }
    if (reinterpret_cast<CSTracker*>(controller->m_pCombatData))
    {
        reinterpret_cast<CSTracker*>(controller->m_pCombatData)->Notify(controller->actor, apActor.value);
    }
    if (apActor.value != reinterpret_cast<Actor*>(controller->CombatController_GetTarget()) && apActor.value != reinterpret_cast<Actor*>(controller->GetFieldBC()) && reinterpret_cast<CSProcess*>(apActor.value->FUN_008d8520()))
    {
        int iChance2 = 0;
        if (!reinterpret_cast<ControllerIgnoredActorFn>(ControllerIgnoredActor)(controller, apActor.value))
        {
            int iUnused = 0;
            int iOut2 = 0;
            if (reinterpret_cast<ActorCheckCombatFn>(ActorCheckCombat)(reinterpret_cast<Actor*>(controller->GetFieldBC()), apActor.value, 1, &iOut2, 0))
            {
                iChance2 = 100;
            }
            bool bHit3 = iChance2 > 0;
            if (bHit3)
            {
                int iAmount = (int)reinterpret_cast<CSProcess*>(apActor.value->FUN_008d8520())->GetAmount(apActor.value, controller->actor);
                controller->AddTarget_0097f930(apActor.value, iAmount, 0, 0.0f, 0.0f);
            }
        }
    }
}

struct OffsetVector
{
    float x;
    float y;
    float z;
    OffsetVector ApplyScaled(float) const;
};
extern OffsetVector DAT_011f426c;
struct OffsetBounds
{
    float FUN_005f3780(int);
    OffsetVector GetVec() const;
};
struct OffsetShape
{
    OffsetBounds* FUN_0048f7f0();
};
struct OffsetObject
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual OffsetShape* GetShape(int);
};
struct OffsetStatus
{
    bool Lookup();
};
struct OffsetAnimation
{
    OffsetStatus* FUN_00497280(unsigned short, OffsetObject**);
};

bool FUN_005f2670(unsigned short);
// Looks up the actor's slot id, and if valid, computes the shape's bounds extent scaled by the actor's value into output; returns whether it succeeded.
// @fnv 0x0097fd80
bool GetActorSlotExtent(Actor* actor, int slot, OffsetVector& output)
{
    bool result2 = false;
    if (!actor)
        return result2;
    output = DAT_011f426c;
    unsigned short id6 = actor->Actor_GetAnimGroup(slot, 0, 0, 0);
    if (FUN_005f2670(id6))
    {
        OffsetAnimation* anim = reinterpret_cast<OffsetAnimation*>(actor->GetAnimData());
        OffsetObject* object5;
        if (anim->FUN_00497280(id6, &object5)->Lookup())
        {
            OffsetBounds* bounds = object5->GetShape(-1)->FUN_0048f7f0();
            OffsetVector extent4 = bounds->GetVec().ApplyScaled(bounds->FUN_005f3780(2) - bounds->FUN_005f3780(0));
            output = extent4.ApplyScaled(actor->TESObjectREFR_GetScale_00567400());
            result2 = true;
        }
    }
    return result2;
}

// 0x005524B0 reads byte +0x8C of the options returned by 0x00980070; Setting only holds a value and key.
struct CombatOptionFlags
{
    char GetByteAtOffset8C();
};
float __cdecl CombatController_GetPowerAttackHitTime(Actor*, int);

// If the option is enabled, fills actorValues from actor values 0x5c-0x60 scaled by a factor and sets hasValues; always fills weights and sets bF9.
// @fnv 0x0097ff60
void CombatController::UpdateActorValues()
{
    bool enabled = reinterpret_cast<CombatOptionFlags*>(GetCurrentCombatStyle())->GetByteAtOffset8C() > 0.0;
    (*reinterpret_cast<bool*>(&byte124)) = false;
    for (int i = 0; i < 5; i++)
    {
        int value = i + 0x5c;
        float actorValue = reinterpret_cast<ControllerPointYFn>(ControllerPointY)(this, value);
        if (enabled && actorValue > 0.0)
        {
            reinterpret_cast<float*>(&unkFC)[i] = reinterpret_cast<Actor*>(GetFieldBC())->TESObjectREFR_GetScale_00567400() * actorValue;
            (*reinterpret_cast<bool*>(&byte124)) = true;
        }
        else
        {
            reinterpret_cast<float*>(&unkFC)[i] = 0.0f;
        }
        reinterpret_cast<float*>(&unk110)[i] = CombatController_GetPowerAttackHitTime(reinterpret_cast<Actor*>(GetFieldBC()), value);
    }
    byteF9 = true;
}

class OwnedObject
{
  public:
    ~OwnedObject();
};

// If owned is set, calls FUN_00980790, deletes owned and sets it to null.
// @fnv 0x00980550
void CombatController::DestroyOwnedObject()
{
    if ((*reinterpret_cast<OwnedObject**>(&m_pCombatPlan)))
    {
        reinterpret_cast<ControllerClearCoverFn>(ControllerClearCover)(this);
        delete (*reinterpret_cast<OwnedObject**>(&m_pCombatPlan));
        (*reinterpret_cast<OwnedObject**>(&m_pCombatPlan)) = 0;
    }
}

// FUN_00980790: forwards to a helper object held at offset 0x9c of this.

// @fnv 0x00980790
void __fastcall ClearControllerCover(CombatController* controller)
{
    UpdateCombatStateSecondaryCover(controller->m_pModifier);
}

struct Related80830
{
    void DecrementField4A(void*);
    void CombatGroup_IncrementAttackerCount(void*);
    int GetFieldD0();
    int GetResultForArg(void*);
};
extern "C" void CombatStateTargetChanged();
struct Registry80830
{
    void RemoveValueFromGroup(void*, int);
    void AddAttackerToTarget(void*, int);
};
struct World80830
{
    Registry80830* FUN_00441110();
};
struct Manager80830
{
    void CombatDialogueManager_StartDialogue(CombatController*, int, int, bool);
};
extern void* DAT_011f1708;
bool __cdecl Script_SetActionFlag(void*, void*, unsigned int);

// @fnv 0x00980830
// src: XBOX_PDB 0x00980830
void CombatController::SetTarget_00980830(void* target)
{
    if (target == (*reinterpret_cast<void**>(&pTarget)))
        return;
    if ((*reinterpret_cast<void**>(&pTarget)))
    {
        if (reinterpret_cast<Related80830*>(m_pCombatData))
            reinterpret_cast<Related80830*>(m_pCombatData)->DecrementField4A((*reinterpret_cast<void**>(&pTarget)));
        ((World80830*)BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00441110()->RemoveValueFromGroup((*reinterpret_cast<void**>(&pTarget)), reinterpret_cast<int>(GetFieldBC()));
    }
    void* previous = (*reinterpret_cast<void**>(&pTarget));
    (*reinterpret_cast<void**>(&pTarget)) = target;
    if (!byteF8 && !actor->HasHealth(false))
    {
        if (previous && !(*reinterpret_cast<void**>(&pTarget)))
        {
            if (!reinterpret_cast<Related80830*>(m_pCombatData)->GetFieldD0())
                ((Manager80830*)DAT_011f1708)->CombatDialogueManager_StartDialogue(this, 4, 6, false);
        }
        else if ((*reinterpret_cast<void**>(&pTarget)) && !previous)
        {
            if (reinterpret_cast<Related80830*>(m_pCombatData)->GetResultForArg(target) > 0)
            {
                Script_SetActionFlag((*reinterpret_cast<void**>(&pTarget)), actor->BSFile_GetDevice(), 0x8000);
                ((Manager80830*)DAT_011f1708)->CombatDialogueManager_StartDialogue(this, 4, 4, true);
            }
        }
    }
    if ((*reinterpret_cast<void**>(&pTarget)))
    {
        reinterpret_cast<Related80830*>(m_pCombatData)->CombatGroup_IncrementAttackerCount((*reinterpret_cast<void**>(&pTarget)));
        ((World80830*)BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00441110()->AddAttackerToTarget((*reinterpret_cast<void**>(&pTarget)), reinterpret_cast<int>(GetFieldBC()));
    }
    if (!byteF8)
    {
        if (!reinterpret_cast<CombatStateBoolFn>(CombatStateGetUpdateFlag)(m_pModifier) && !actor->FUN_00931850())
            reinterpret_cast<CombatStateVoidFn>(CombatStateTargetChanged)(m_pModifier);
        reinterpret_cast<ControllerTargetChangedFn>(ControllerTargetChanged)(this);
    }
}

struct Ref
{
    void* GetNext();
};
struct Cell
{
    bool IsInterior();
    void* World();
};

struct Location
{
    NiPoint3 pos;
    void* space;
    Location(NiPoint3 const&, void*);
};

struct TargetData
{
    int Kind();
};
struct Package
{
    void* GetRegion();
    unsigned Flags();
    TargetData* TargetInfo();
    Data* GetData();
    unsigned GetPackType();
    bool Special();
    bool HasTarget();
    unsigned RadiusFor(Ref*);
};
struct Process
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual Ref* Target(Ref*, int);
    virtual NiPoint3 Position(Ref*, int);
    virtual Cell* GetContainingCell(Ref*);
    virtual void* GetWorld(Ref*);
    virtual float Distance(Ref*);
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual Ref* Fallback();
};

extern "C" unsigned char* CombatStateTargetType();
typedef unsigned char* (__thiscall* CombatStateTargetTypeFn)(CombatState*);
extern "C" void CombatStateClearTarget();
typedef void (__thiscall* CombatStateClearTargetFn)(CombatState*);
extern "C" void CombatStateSetMode();
typedef void (__thiscall* CombatStateSetModeFn)(CombatState*, int);
extern "C" void CombatStateAssignReference();
typedef void (__thiscall* CombatStateAssignReferenceFn)(CombatState*, Ref*, int, float, float);
extern "C" void CombatStateSetLocation();
typedef void (__thiscall* CombatStateSetLocationFn)(CombatState*, Location*, int, float, float);
extern "C" void CombatStateSetOther();
typedef void (__thiscall* CombatStateSetOtherFn)(CombatState*, int, Ref*, void*);

extern Setting originalRuntimeFloatSetting415, originalRuntimeFloatSetting416, originalRuntimeFloatSetting417,
    originalRuntimeFloatSetting418, originalRuntimeFloatSetting419, originalRuntimeFloatSetting420,
    originalRuntimeFloatSetting421, originalRuntimeFloatSetting422;
float __cdecl BSMAX_00404010(float, float);

// Clears and reconfigures the target from the package's region, flags and target info, then computes target location or reference and finishes.
// @fnv 0x00980ae0
void CombatController::SetupPackageTarget(TESPackage* package)
{
    if (TESPackage_GetPretendInCombat() || TESPackage_GetContinueDuringCombat())
    {
        unsigned char* type = reinterpret_cast<CombatStateTargetTypeFn>(CombatStateTargetType)(m_pModifier);
        if (type && (*type == 1 || *type == 0))
            reinterpret_cast<CombatStateClearTargetFn>(CombatStateClearTarget)(m_pModifier);
        reinterpret_cast<CombatStateSetModeFn>(CombatStateSetMode)(m_pModifier, 2);
    }
    reinterpret_cast<ControllerSetFirstFn>(ControllerSetFirst)(this, false);
    reinterpret_cast<ControllerSetSecondFn>(ControllerSetSecond)(this, false);
    reinterpret_cast<ControllerSetRegionFn>(ControllerSetRegion)(this, 0);
    if (!reinterpret_cast<Package*>(package))
    {
        UpdatePointer();
        return;
    }
    reinterpret_cast<ControllerSetRegionFn>(ControllerSetRegion)(this, reinterpret_cast<Package*>(package)->GetRegion());
    unsigned flags = reinterpret_cast<Package*>(package)->Flags();
    if (flags & 0x6000000)
    {
        reinterpret_cast<ControllerSetFirstFn>(ControllerSetFirst)(this, (flags & 0x2000000) != 0);
        reinterpret_cast<ControllerSetSecondFn>(ControllerSetSecond)(this, (flags & 0x4000000) != 0);
        Process* process4 = reinterpret_cast<Process*>(actor->FUN_008d8520());
        bool useRef = true;
        if (reinterpret_cast<Package*>(package)->TargetInfo())
        {
            switch (reinterpret_cast<Package*>(package)->TargetInfo()->Kind())
            {
            case 1:
            case 2:
            case 3:
                useRef = false;
            }
        }
        Ref* ref5 = process4->Target(reinterpret_cast<Ref*>(actor), 0);
        float distance16 = process4->Distance(reinterpret_cast<Ref*>(actor));
        if (!ref5 || ref5 == reinterpret_cast<Ref*>(actor))
        {
            ref5 = process4->Fallback();
            if (!ref5 && reinterpret_cast<Package*>(package)->GetData() && reinterpret_cast<Package*>(package)->GetData()->Target())
            {
                ref5 = reinterpret_cast<Package*>(package)->GetData()->Target();
                distance16 = (float)reinterpret_cast<Package*>(package)->GetData()->Radius();
            }
        }
        switch (reinterpret_cast<Package*>(package)->GetPackType())
        {
        case 14: {
            if (reinterpret_cast<Package*>(package)->Special())
                useRef = true;
            ::Data* data = reinterpret_cast<Package*>(package)->GetData();
            float radius = reinterpret_cast<Package*>(package)->HasTarget() && reinterpret_cast<Package*>(package)->TargetInfo() ? (float)reinterpret_cast<Package*>(package)->RadiusFor(reinterpret_cast<Ref*>(actor))
                           : data                                        ? (float)data->Radius()
                                                                         : 30.0f;
            float nearDistance9 = radius * *originalRuntimeFloatSetting421.Float();
            nearDistance9 = BSMAX_00404010(nearDistance9, *originalRuntimeFloatSetting422.Float());
            if (useRef)
                reinterpret_cast<CombatStateAssignReferenceFn>(CombatStateAssignReference)(m_pModifier, ref5, 1, radius, nearDistance9);
            else
            {
                Cell* cellAB = process4->GetContainingCell(reinterpret_cast<Ref*>(actor));
                void* spaceA = 0;
                if (cellAB)
                    spaceA = cellAB->IsInterior() ? cellAB : cellAB->World();
                else
                    spaceA = process4->GetWorld(reinterpret_cast<Ref*>(actor));
                Location locationA(process4->Position(reinterpret_cast<Ref*>(actor), 1), spaceA);
                reinterpret_cast<CombatStateSetLocationFn>(CombatStateSetLocation)(m_pModifier, &locationA, 1, radius, nearDistance9);
            }
            break;
        }
        case 1:
        case 7: {
            bool teammate5 = actor->IsPlayerTeammate();
            float mult4 = teammate5 ? *originalRuntimeFloatSetting418.Float() : *originalRuntimeFloatSetting415.Float();
            float maxDistance =
                teammate5 ? *originalRuntimeFloatSetting419.Float() : *originalRuntimeFloatSetting416.Float();
            float offset2 =
                teammate5 ? *originalRuntimeFloatSetting420.Float() : *originalRuntimeFloatSetting417.Float();
            float radiusB4 = (float)reinterpret_cast<Package*>(package)->GetData()->Radius();
            float nearB2 = radiusB4 * mult4 + offset2;
            nearB2 = BSMAX_00404010(nearB2, maxDistance);
            if (useRef)
                reinterpret_cast<CombatStateAssignReferenceFn>(CombatStateAssignReference)(m_pModifier, ref5, 1, radiusB4, nearB2);
            else
            {
                Cell* cellB = process4->GetContainingCell(reinterpret_cast<Ref*>(actor));
                void* spaceB = 0;
                if (cellB)
                    spaceB = cellB->IsInterior() ? cellB : cellB->World();
                else
                    spaceB = process4->GetWorld(reinterpret_cast<Ref*>(actor));
                Location locationB(process4->Position(reinterpret_cast<Ref*>(actor), 1), spaceB);
                reinterpret_cast<CombatStateSetLocationFn>(CombatStateSetLocation)(m_pModifier, &locationB, 1, radiusB4, nearB2);
            }
            break;
        }
        case 0:
        case 17:
            reinterpret_cast<CombatStateSetOtherFn>(CombatStateSetOther)(m_pModifier, 2, ref5, ref5 ? ref5->GetNext() : 0);
            break;
        default: {
            if (useRef)
                reinterpret_cast<CombatStateAssignReferenceFn>(CombatStateAssignReference)(m_pModifier, ref5, 0, distance16, distance16);
            else
            {
                Cell* cellC5 = process4->GetContainingCell(reinterpret_cast<Ref*>(actor));
                void* spaceC6 = 0;
                if (cellC5)
                    spaceC6 = cellC5->IsInterior() ? cellC5 : cellC5->World();
                else
                    spaceC6 = process4->GetWorld(reinterpret_cast<Ref*>(actor));
                Location locationC(process4->Position(reinterpret_cast<Ref*>(actor), 1), spaceC6);
                reinterpret_cast<CombatStateSetLocationFn>(CombatStateSetLocation)(m_pModifier, &locationC, 0, distance16, distance16);
            }
            ForcePlanUpdate();
            reinterpret_cast<ActorRefreshPackageFn>(ActorRefreshCombatPackage)(actor);
            break;
        }
        }
    }
    UpdatePointer();
}

namespace fnv_00981d00 {

extern "C" void CombatStateLoadFromStream();
typedef void (__thiscall* CombatStateLoadFn)(CombatState*, BGSLoadFormBuffer*);
struct ProcedureStand;
struct ProcArrayStand
{
    int unk00, unk04, unk08, unk0C;
    void FUN_006f2290(unsigned int, bool);
    ProcedureStand*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
};
struct FUN_00993d60
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    FUN_00993d60(CombatController*);
    void ReadFromStream(BGSLoadFormBuffer*);
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct WorldStand
{
    void* FindByKey(unsigned int);
};
extern WorldStand* DAT_011f1958;
void* __cdecl CombatPlan_GetCombatAction(int);
struct TimerStand
{
    float unk00, unk04;
    void FUN_009a5f20(BGSLoadFormBuffer*);
};
struct PointStand
{
    float x, y, z;
};

// Deserializes combat state from the buffer: pointers, procedure arrays, optional plan, action, timer, and version-gated fields.
}  // namespace fnv_00981d00

// @fnv 0x00981d00
// src: XBOX_PDB 0x00981d00
void CombatController::LoadGame_00981d00(BGSLoadFormBuffer* buffer)
{
    using namespace fnv_00981d00;
    TESPackage::LoadGame(buffer);
    buffer->ReadFormIdentifier(&actor);
    buffer->ReadFormIdentifier(&unkC0);
    unsigned int group = 0;
    buffer->ReadTypedData((void*)&group, (unsigned int)4);
    (*reinterpret_cast<void**>(&m_pCombatData)) = DAT_011f1958->FindByKey(group);
    reinterpret_cast<CombatStateLoadFn>(CombatStateLoadFromStream)(m_pModifier, buffer);
    reinterpret_cast<ControllerLoadProcedureFn>(ControllerLoadProcedure)(this, &m_pkCurrentProcedure, buffer);
    reinterpret_cast<ControllerLoadProcedureFn>(ControllerLoadProcedure)(this, &m_pkQueuedProcedure, buffer);
    unsigned int count4 = buffer->ReadElementCount();
    (*reinterpret_cast<fnv_00981d00::ProcArrayStand*>(&unk8C)).FUN_006f2290(count4, true);
    for (unsigned int i3 = 0; i3 < count4; i3++)
    {
        ProcedureStand** proc = &(*reinterpret_cast<fnv_00981d00::ProcArrayStand*>(&unk8C)).BSSimpleArray_NiAVObject_1024_GetAt(i3);
        reinterpret_cast<ControllerLoadProcedureFn>(ControllerLoadProcedure)(this, reinterpret_cast<CombatProcedure**>(proc), buffer);
    }
    bool hasPlan = false;
    buffer->ReadTypedData((void*)&hasPlan, (unsigned int)1);
    if (hasPlan)
    {
        (*reinterpret_cast<fnv_00981d00::FUN_00993d60**>(&m_pCombatPlan)) = new FUN_00993d60(this);
        (*reinterpret_cast<fnv_00981d00::FUN_00993d60**>(&m_pCombatPlan))->ReadFromStream(buffer);
        (*reinterpret_cast<void**>(&unkAC)) = (*reinterpret_cast<fnv_00981d00::FUN_00993d60**>(&m_pCombatPlan))->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    }
    signed char action5 = -1;
    buffer->ReadTypedData((void*)&action5, (unsigned int)1);
    if (action5 != -1)
        (*reinterpret_cast<void**>(&m_pCombatThread)) = fnv_00981d00::CombatPlan_GetCombatAction(action5);
    buffer->ReadTypedData((void*)&unkB0, (unsigned int)4);
    (*reinterpret_cast<fnv_00981d00::TimerStand*>(&unkB4)).FUN_009a5f20(buffer);
    buffer->ReadTypedData((void*)&byteC7, (unsigned int)1);
    buffer->ReadTypedData((void*)&unkC8, (unsigned int)4);
    buffer->ReadTypedData((void*)&floatD8, (unsigned int)4);
    buffer->ReadTypedData((void*)&floatDC, (unsigned int)4);
    buffer->ReadTypedData((void*)&byteE4, (unsigned int)1);
    buffer->ReadTypedData((void*)&byte125, (unsigned int)1);
    buffer->ReadTypedData((void*)&byte126, (unsigned int)1);
    buffer->ReadTypedData((void*)&unk144, (unsigned int)4);
    buffer->ReadTypedData((void*)&unk148, (unsigned int)4);
    for (unsigned int j = 0; j < 2; j++)
    {
        buffer->ReadTypedData((void*)&unk128[j], (unsigned int)12);
        buffer->ReadTypedData((void*)&m_aucStateByIndex[j], (unsigned int)1);
    }
    buffer->ReadTypedData((void*)&byte142, (unsigned int)1);
    if (buffer->GetVersion() >= 10)
    {
        buffer->ReadTypedData((void*)&byteC6, (unsigned int)1);
        buffer->ReadTypedData((void*)&byteC5, (unsigned int)1);
    }
}

// Initializes the base and members, zeros field_2058, then passes this object's address to field_20c8.SetQuantity.
// @fnv 0x0097e330
CombatPlanner::CombatPlanner() : AStarSearch<CombatPlanNode*, CombatPlanLink*>(), field_2058(0), field_205c(), field_20b8(), field_20c8()
{
    field_20c8.SetQuantity((unsigned int)this);
}

// @fnv 0x0097e3e0
CombatPlanner::~CombatPlanner()
{
    CleanUp_00995830();
}

class C982080SaveGame;

TESForm* __cdecl C982080LookupForm(unsigned int auiFormId);

class C982080Revertable
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void Revert(C982080SaveGame* pkSaveGame);
};

class C982080NavMeshInfo : public C982080Revertable
{
};

class C982080NavMeshArray
{
  public:
    unsigned int GetSize();
    C982080NavMeshInfo*& GetAt(int iIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

extern "C" void CombatStateRevert();
typedef void (__thiscall* CombatStateRevertFn)(CombatState*, BGSLoadFormBuffer*);

class C982080Plan
{
  public:
    void Revert(C982080SaveGame* pkSaveGame);
};

class C982080Group
{
  public:
    bool IsMember(Actor* pkActor);
    bool AddMember(Actor* pkActor);
    void AddEffectToTarget(Actor* pkTarget);
    void SetTarget(Actor* pkTarget);
};

class C982080TargetMap
{
  public:
    void AddEffectToTarget(Actor* pkTarget, Actor* pkActor);
};

class C982080CombatManager
{
  public:
    C982080TargetMap* GetTargetMap();
    C982080Group* CreateGroup();
};

extern C982080CombatManager* g_pk982080CombatManager;

class C982080ControllerBase
{
  public:
    void Revert(C982080SaveGame* pkSaveGame);
};

// @fnv 0x00982080
// src: XBOX_PDB 0x00982080
void CombatController::InitLoadGame_00982080(BGSLoadFormBuffer* pkSaveGame)
{
    reinterpret_cast<C982080ControllerBase*>(this)->Revert(reinterpret_cast<C982080SaveGame*>(pkSaveGame));

    actor = actor ? dynamic_cast<Actor*>(C982080LookupForm((unsigned int)actor)) : 0;
    pTarget = pTarget ? dynamic_cast<Actor*>(C982080LookupForm((unsigned int)pTarget)) : 0;
    if (pTarget)
        g_pk982080CombatManager->GetTargetMap()->AddEffectToTarget(pTarget, actor);

    if (reinterpret_cast<C982080Revertable*>(m_pkCurrentProcedure))
        reinterpret_cast<C982080Revertable*>(m_pkCurrentProcedure)->Revert(reinterpret_cast<C982080SaveGame*>(pkSaveGame));
    if (reinterpret_cast<C982080Revertable*>(m_pkQueuedProcedure))
        reinterpret_cast<C982080Revertable*>(m_pkQueuedProcedure)->Revert(reinterpret_cast<C982080SaveGame*>(pkSaveGame));

    unsigned int uiNavMeshCount = (*reinterpret_cast<C982080NavMeshArray*>(&unk8C)).GetSize();
    for (unsigned int i = 0; i < uiNavMeshCount; i++)
    {
        C982080NavMeshInfo*& rpkInfo = (*reinterpret_cast<C982080NavMeshArray*>(&unk8C)).GetAt(i);
        rpkInfo->Revert(reinterpret_cast<C982080SaveGame*>(pkSaveGame));
    }

    reinterpret_cast<CombatStateRevertFn>(CombatStateRevert)(m_pModifier, pkSaveGame);
    if (reinterpret_cast<C982080Plan*>(m_pCombatPlan))
        reinterpret_cast<C982080Plan*>(m_pCombatPlan)->Revert(reinterpret_cast<C982080SaveGame*>(pkSaveGame));

    if ((*reinterpret_cast<C982080Group**>(&m_pCombatData)) && !(*reinterpret_cast<C982080Group**>(&m_pCombatData))->IsMember(actor) && !(*reinterpret_cast<C982080Group**>(&m_pCombatData))->AddMember(actor))
        (*reinterpret_cast<C982080Group**>(&m_pCombatData)) = 0;
    if (!(*reinterpret_cast<C982080Group**>(&m_pCombatData)))
    {
        (*reinterpret_cast<C982080Group**>(&m_pCombatData)) = g_pk982080CombatManager->CreateGroup();
        (*reinterpret_cast<C982080Group**>(&m_pCombatData))->AddMember(actor);
        if (pTarget)
        {
            (*reinterpret_cast<C982080Group**>(&m_pCombatData))->AddEffectToTarget(pTarget);
            (*reinterpret_cast<C982080Group**>(&m_pCombatData))->SetTarget(pTarget);
        }
    }
}

namespace fnv_00994bd0 {
struct Context;
struct Item
{
};
struct Owner
{
    Item* FUN_00726070();
    void* Modelloader_GetReferencedThis(Item*);
};
struct Node
{
    Owner** FUN_006815c0();
    Node* FUN_0062d990();
};
struct Goal
{
    virtual bool Test(Context*);
    virtual void End(void*, Context*);
    Node* GetOffsetC();
};
struct Entry
{
    void* unk00;
    void* unk04;
    Entry(void*);
    static void* operator new(unsigned, void*);
    static void operator delete(void*, void*);
};
struct Context
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void UpdateWorldState(void*);
    void ResetState(Context*);
    Item* GetCombatGoal(Item*);
    bool CombatWorldStateArray_IsTrue(void*);
    void AppendPair(Entry*, Context*);
};
struct Input
{
    void FUN_00994ef0(void*);
};
extern Goal* CombatGoal_GetGoal(unsigned);
extern bool IsValidCode(Item*);
extern "C" char DAT_010a2720;

// The shared planner has no BuildResultForInput declaration. Preserve its
// original thiscall ABI without another planner class definition.
extern "C" void* BuildPlannerResult();
typedef void* (__thiscall* BuildPlannerResultFn)(CombatPlanner*, Input*, Goal*, Context*, bool);

}  // namespace fnv_00994bd0

// @fnv 0x00994bd0
// src: COMMUNITY 0x00994bd0
Owner* CombatPlanner::CreatePlan_0(void* apInput, bool flag)
{
    using namespace fnv_00994bd0;
    field_2058 = (int)apInput;
    ((fnv_00994bd0::Input*)field_2058)->FUN_00994ef0((char*)this + 0x20c8);
    (*(fnv_00994bd0::Context*)&field_205c).UpdateWorldState((fnv_00994bd0::Input*)apInput);
    for (unsigned i8 = 0; i8 < 16; i8++)
    {
        fnv_00994bd0::Goal* goal = CombatGoal_GetGoal(i8);
        if (goal->Test(&(*(fnv_00994bd0::Context*)&field_205c)))
        {
            void* node2;
            fnv_00994bd0::Node* result3;
            fnv_00994bd0::Context ctx;
            ctx.ResetState(&(*(fnv_00994bd0::Context*)&field_205c));
            result3 = goal->GetOffsetC();
            while (result3 && *result3->FUN_006815c0())
            {
                fnv_00994bd0::Owner* owner = *result3->FUN_006815c0();
                fnv_00994bd0::Item* itemB = owner->FUN_00726070();
                if (IsValidCode(itemB))
                    itemB = ctx.GetCombatGoal(itemB);
                if (!ctx.CombatWorldStateArray_IsTrue(owner->Modelloader_GetReferencedThis(itemB)))
                {
                    ctx.AppendPair(
                        new (field_20b8.ScrapHeap_Allocate(8, *(unsigned*)&DAT_010a2720))
                            fnv_00994bd0::Entry(owner->Modelloader_GetReferencedThis(itemB)),
                        &ctx);
                }
                result3 = result3->FUN_0062d990();
            }
            node2 = reinterpret_cast<BuildPlannerResultFn>(BuildPlannerResult)(this, (fnv_00994bd0::Input*)apInput, goal, &ctx, flag);
            if (node2)
            {
                return (::Owner*)node2;
            }
            else
            {
                goal->End((fnv_00994bd0::Input*)apInput, &(*(fnv_00994bd0::Context*)&field_205c));
            }
        }
    }
    return 0;
}

