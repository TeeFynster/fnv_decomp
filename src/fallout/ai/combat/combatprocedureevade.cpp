#include "../../../../include/CombatProcedure.h"
#include "../../../../include/CombatProcedureEvade.h"
#include "../../../../include/Actor.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/CombatProcedureEngageTarget.h"
#include "../../../../include/PathingLocation.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/PathingRequestFlee.h"
#include "../../../../include/BGSLoadFormBuffer.h"

// src/fallout/ai/combat/combatprocedureevade.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureevade.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_009d5ff0_shell : CombatProcedureEvade
{
    void CombatProcedureEvade_LoadGame(BGSLoadFormBuffer*);
};

// @fnv 0x009d5ff0
// src: XBOX_PDB 0x009d5ff0
void FUN_009d5ff0_shell::CombatProcedureEvade_LoadGame(BGSLoadFormBuffer* buffer)
{
    CombatProcedure::LoadGame(buffer);
    buffer->ReadTypedData((void*)((char*)this + 0x10), 4u);
    buffer->ReadTypedData((void*)((char*)this + 0x14), 4u);
}

struct FUN_009ca6c0_shell
{
    void SetVirtualTable_009ca6c0(void);
};
struct FUN_009d5b40_shell
{
    void UpdateFields_009d5b40(void);
};
extern int DAT_01091984;

// @fnv 0x009d5b40
// src: GUESS 0x009d5b40 (confidence: low)
void FUN_009d5b40_shell::UpdateFields_009d5b40(void)
{
    *reinterpret_cast<int**>(this) = &DAT_01091984;
    reinterpret_cast<FUN_009ca6c0_shell*>(this)->SetVirtualTable_009ca6c0();
}

struct FUN_009ca680
{
    virtual void Unk();
    int _pad1;
    int _pad2;
    int _pad3;
    FUN_009ca680();
};
struct FUN_009d5ad0 : FUN_009ca680
{
    int eState;
    int iLocation;
    FUN_009d5ad0(int aiLocation);
};
// Initializes the object's state to 0 and stores the given location value.
// @fnv 0x009d5ad0
FUN_009d5ad0::FUN_009d5ad0(int aiLocation)
{
    eState = 0;
    iLocation = aiLocation;
}

void __cdecl operator delete(void*);
struct FUN_009d5b10_shell : FUN_009d5b40_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x009d5b10
void* FUN_009d5b10_shell::DestroyIfFlagged(unsigned int flags)
{
    UpdateFields_009d5b40();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_009cc4d0_shell
{
    Actor* CombatProcedure_GetAttacker();
};
struct FUN_009d5b60_shell : CombatProcedureEvade
{
    void StopAndEngageTarget();
};
// Stops the actor's movement and then runs the engage-target combat procedure on this object.
// @fnv 0x009d5b60
void FUN_009d5b60_shell::StopAndEngageTarget()
{
    reinterpret_cast<FUN_009cc4d0_shell*>(this)->CombatProcedure_GetAttacker()->StopMoving();
    reinterpret_cast<CombatProcedureEngageTarget*>(this)->ClearMoveMode();
}

struct CombatProcedure_SaveHelper
{
    void SaveGame(BGSSaveFormBuffer*);
};
struct FUN_009d5fb0_shell : CombatProcedureEvade
{
    void SaveEvadeProcedure(BGSSaveFormBuffer*);
};
// Saves the base combat procedure, then writes the 4-byte values at offsets 0x10 and 0x14 into the save buffer.
// @fnv 0x009d5fb0
void FUN_009d5fb0_shell::SaveEvadeProcedure(BGSSaveFormBuffer* apSaveGameBuffer)
{
    ((CombatProcedure_SaveHelper*)this)->SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SaveData((void*)((char*)this + 0x10), 4, 0);
    apSaveGameBuffer->SaveData((void*)((char*)this + 0x14), 4, 0);
}

struct EvadeActorBaseData
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
    virtual bool CanSwim();
};
struct EvadeActorBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;

    EvadeActorBaseData data;
};
struct EvadeWorldLocation
{
    int unk00, unk04, unk08, unk0c;
};
struct EvadeActor
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
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
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const NiPoint3* GetPosition();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual bool IsCreature();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual float GetRadius(int);
    EvadeActorBase* FUN_004181e0();
    bool Actor_GetCurrentPathfindingGoal(NiPoint3*);
    bool Actor_SetPathfindingFlee(PathingRequest*);
    bool DidPathingFail();
    bool Actor_IsPathValid();
    bool FUN_008b3bb0();
    EvadeWorldLocation TESObjectREFR_GetWorldLocation();
};
struct EvadeController
{
    void CombatState_BoostConfidence(int);
    void ClearAndDeletePointer();
    void HandleMenuEvent(const EvadeWorldLocation*, int);
};
struct EvadeMovement
{
    int CombatGroup_CreateMovementAvoidNodeArray(EvadeActor*, NiPoint3*, float, int, int);
    int BuildAvoidNodes(EvadeActor*, int);
};
struct EvadeContext
{
    EvadeController* CombatController_GetCombatState();
    EvadeMovement* FUN_004fb070();
};
struct EvadeProcedure
{
    int unk00;
    EvadeContext* context;
    int unk08, unk0c, state, location;
    EvadeActor* CombatProcedure_GetAttacker();
    void SetMoveMode_00996e20(int);
    void CombatProcedure_SetFailed(const char*);
    void SetState();
    void UpdateFleeState();
};
struct EvadeManager
{
    void CombatDialogueManager_StartDialogue(EvadeContext*, int, int, int);
};
extern EvadeManager* DAT_011f1708;
struct EvadeSearchResult
{
    int BuildAvoidanceNodes();
};
struct EvadeSearch
{
    EvadeSearchResult* FUN_00825c00(NiPoint3*, EvadeActor*, float);
};
extern EvadeSearch* DAT_011f1958;
struct EvadeSetting
{
    float* Setting_Float_00403e20();
};
extern EvadeSetting DAT_011cea80;
extern float DAT_0101e704, DAT_01012054, DAT_01050b98;
extern const char DAT_01091a08[], DAT_010919e8[], DAT_010919c8[];

// @fnv 0x009d5b90
void EvadeProcedure::UpdateFleeState()
{
    EvadeActor* actor = CombatProcedure_GetAttacker();
    EvadeController* pController = context->CombatController_GetCombatState();
    switch (state)
    {
    case 0: {
        NiPoint3 actorPosition = *actor->GetPosition();
        PathingRequestFlee fleeRequest;
        fleeRequest.PathingRequest::InitFromActor(actor);
        fleeRequest.SetInitialPathHeading(actor->GetRadius(0));
        if (actor->IsCreature())
            fleeRequest.SetCantOpenDoors(actor->FUN_004181e0()->data.CanSwim());
        int destination = 0;
        switch (location)
        {
        case 14: {
            DAT_011f1708->CombatDialogueManager_StartDialogue(context, 2, 5, 1);
            fleeRequest.PathingRequestClosePoint_SetMinDistance(DAT_0101e704);
            NiPoint3 targetPosition;
            if (!actor->Actor_GetCurrentPathfindingGoal(&targetPosition))
                fleeRequest.PathingRequest_SetNoDestination();
            else
                fleeRequest.SetDestination(&PathingLocation(targetPosition, (TESObjectREFR*)actor));
            destination = DAT_011f1958->FUN_00825c00(&actorPosition, actor, DAT_01012054)->BuildAvoidanceNodes();
            destination = context->FUN_004fb070()->CombatGroup_CreateMovementAvoidNodeArray(actor, &actorPosition, DAT_01050b98, destination, 0);
            break;
        }
        case 10:
        case 12:
            fleeRequest.PathingRequestClosePoint_SetMinDistance(*DAT_011cea80.Setting_Float_00403e20());
            fleeRequest.PathingRequest_SetNoDestination();
            destination = context->FUN_004fb070()->BuildAvoidNodes(actor, 0);
            break;
        }
        fleeRequest.FUN_006d61e0(reinterpret_cast<PathingAvoidNodeArray*>(destination));
        fleeRequest.SetByteAtOffset9B(true);
        if (!actor->Actor_SetPathfindingFlee(&fleeRequest))
        {
            CombatProcedure_SetFailed(DAT_01091a08);
            break;
        }
        state = 1;
        SetMoveMode_00996e20(3);
        break;
    }
    case 1:
        if (actor->DidPathingFail())
        {
            if (!actor->Actor_IsPathValid())
            {
                switch (location)
                {
                case 12:
                    pController->CombatState_BoostConfidence(0);
                    break;
                }
            }
            pController->ClearAndDeletePointer();
            CombatProcedure_SetFailed(actor->Actor_IsPathValid() ? DAT_010919e8 : DAT_010919c8);
        }
        else if (actor->FUN_008b3bb0())
        {
            pController->HandleMenuEvent(&actor->TESObjectREFR_GetWorldLocation(), location);
            SetState();
        }
        break;
    }
}
