#include "../../../../include/CombatProcedureMove.h"
#include "../../../../include/CombatTargetTimestamp.h"
#include "../../../../include/CombatProcedureEngageTarget.h"
#include "../../../../include/CombatProcedureAttackRanged.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/Actor.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/GO.h"
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PathingAvoidNode.h"
#include "../../../../include/Setting.h"

// src/fallout/ai/combat/combatproceduremove.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatproceduremove.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x009d6b70
void* CombatProcedureMove::DestroyIfFlagged(unsigned int flags)
{
    FUN_009d6ba0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_009d7bd0_shell
{
    bool IsFlagSet(unsigned int flags);
};

// Tests whether the bit selected by flags is set in the 32-bit mask at offset 0x90 of this object.
// @fnv 0x009d7bd0
bool FUN_009d7bd0_shell::IsFlagSet(unsigned int flags)
{
    return ((1 << flags) & *(unsigned int*)((char*)this + 0x90)) ? true : false;
}

struct Holder
{
    void SetValue(float);
};
// @fnv 0x009d8410
void Holder::SetValue(float afValue)
{
    CombatTargetTimestamp t(afValue);
    *(int*)((char*)this + 0xC0) = *reinterpret_cast<int*>(&t.fTimeStamp);
}

extern float DAT_010162c0;
// @fnv 0x009d8440
// src: XBOX_PDB 0x009d8440
float CombatProcedureMove::GetHidingTime()
{
    switch (static_cast<int>(mode))
    {
    case 6:
    case 7:
        return DAT_010162c0;
    case 8:
        return 0.5f;
    default:
        return 1.0f;
    }
}

// If the reference stored at offset 0x38 matches apRef, clears it to null and logs that the targeted reference pointer was cleared.
// @fnv 0x009d8480
void CombatProcedureMove::ClearTargetRef(TESObjectREFR* apRef)
{
    if (reinterpret_cast<TESObjectREFR*>(target38) == apRef)
    {
        target38 = 0;
        Fail("Targeted reference pointer was cleared");
    }
}

struct FUN_009d6c80_shell
{
    void CombatState_UnreserveSecondaryCoverLocation();
};
struct IMH
{
    FUN_009d6c80_shell* CombatController_GetCombatState();
};
// If the bool at offset 0x54 is set, calls FUN_009d6c80 through the object at offset 4 and clears the flag.
// @fnv 0x009d84b0
// src: XBOX_PDB 0x009d84b0
void CombatProcedureMove::StartedPlanning()
{
    if (active54)
    {
        reinterpret_cast<IMH*>(m_pCombatController)->CombatController_GetCombatState()->CombatState_UnreserveSecondaryCoverLocation();
        active54 = 0;
    }
}

class Tile;
namespace fnv_009d84e0 {
struct IMH
{
    Tile* CombatController_GetCombatState();
};
struct FUN_009d7c20_shell
{
    void CombatState_ReserveSecondaryCoverLocation();
};
}  // namespace fnv_009d84e0

// @fnv 0x009d84e0
// src: XBOX_PDB 0x009d84e0
void CombatProcedureMove::FinishedPlanning()
{
    if (unk10 == 2 || unk10 == 3)
    {
        reinterpret_cast<fnv_009d84e0::FUN_009d7c20_shell*>(reinterpret_cast<fnv_009d84e0::IMH*>(m_pCombatController)->CombatController_GetCombatState())
            ->CombatState_ReserveSecondaryCoverLocation();
        active54 = true;
    }
}


struct TESAmmoInitCalls
{
    Actor* GetFieldBC();
};
struct MoveCompletionCheck
{
    bool IsComplete();
};
// @fnv 0x009d6c00
void CombatProcedureMove::UpdateCombatMovement()
{
    ::Actor* attacker = reinterpret_cast<TESAmmoInitCalls*>(m_pCombatController)->GetFieldBC();
    if (unk10 == 1 || unk10 == 2)
    {
        if (!reinterpret_cast<MoveCompletionCheck*>(this)->IsComplete())
            attacker->StopMoving();
    }
    else if (unk10 == 3)
        ((CombatProcedure*)this)->RunProcedure();
    reinterpret_cast<CombatProcedureEngageTarget*>(this)->ClearMoveMode();
    if (active54)
        reinterpret_cast<IMH*>(m_pCombatController)->CombatController_GetCombatState()->CombatState_UnreserveSecondaryCoverLocation();
}


// @fnv 0x009d8880
// src: XBOX_PDB 0x009d8880
void CombatProcedureMove::SaveGame_009d8880(BGSSaveFormBuffer* buffer)
{
    CombatProcedure::SaveGame(buffer);

    buffer->SaveData(&unk10, static_cast<unsigned short>(4), static_cast<unsigned short>(0));

    startTransform.BGSWorldLocation_SaveGame(buffer);
    currentTransform.BGSWorldLocation_SaveGame(buffer);

    buffer->SaveData(&rate, static_cast<unsigned short>(4), static_cast<unsigned short>(0));

    buffer->SerializeFormData(reinterpret_cast<void*>(target38), 0);

    buffer->SaveData(&mode, static_cast<unsigned short>(4), static_cast<unsigned short>(0));

    buffer->SaveData(&unk60, static_cast<unsigned short>(4), static_cast<unsigned short>(0));

    state64.SaveGame(buffer);
    pos40.SaveGame(buffer);
    state6C.SaveGame(buffer);
    state74.SaveGame(buffer);

    buffer->SaveData(&pos48, static_cast<unsigned short>(0x0C), static_cast<unsigned short>(0));

    buffer->SaveData(&active54, static_cast<unsigned short>(1), static_cast<unsigned short>(0));

    active5C = static_cast<const GO&>(state58).operator unsigned int();

    buffer->SaveData(&active5C, static_cast<unsigned short>(1), static_cast<unsigned short>(0));
}



// @fnv 0x009d89a0
// src: XBOX_PDB 0x009d89a0
void CombatProcedureMove::LoadGame_009d89a0(BGSLoadFormBuffer* buffer)
{
    CombatProcedure::LoadGame(buffer);

    buffer->ReadTypedData(static_cast<void*>(&unk10), 4u);

    startTransform.BGSLoadGameBuffer_LoadBGSWorldLocation(buffer);

    currentTransform.BGSLoadGameBuffer_LoadBGSWorldLocation(buffer);

    buffer->ReadTypedData(static_cast<void*>(&rate), 4u);

    buffer->ReadFormIdentifier(static_cast<void*>(&target38));

    buffer->ReadTypedData(static_cast<void*>(&mode), 4u);

    buffer->ReadTypedData(static_cast<void*>(&unk60), 4u);

    state64.LoadGame(buffer);

    pos40.LoadGame(buffer);

    state6C.LoadGame(buffer);

    if (buffer->GetVersion() >= 8)
    {
        state74.LoadGame(buffer);
    }

    buffer->ReadTypedData(static_cast<void*>(&pos48), 0xcu);

    buffer->ReadTypedData(static_cast<void*>(&active54), 1u);

    if (buffer->GetVersion() >= 0xc)
    {
        buffer->ReadTypedData(static_cast<void*>(&active5C), 1u);
    }
}

struct MoveInput
{
    CombatProcedureMove::Location* FUN_006815c0();
    unsigned int TESMain_GetThread();
    bool CombatLocation_GetFlag(int);
};
// @fnv 0x009d69f0
CombatProcedureMove::CombatProcedureMove(MoveInput* input, float speed, unsigned int flags)
    : unk10(0), startTransform(), currentTransform(), rate(speed), target38(0), mode(flags), pos40(), pos48(),
      active54(false), state58(0), active5C(false), unk60(-1), state64(), state6C(), state74()
{
    if (input)
    {
        startTransform = *input->FUN_006815c0();
        currentTransform = startTransform;
        target38 = input->TESMain_GetThread();
        if (input->CombatLocation_GetFlag(2))
            rate = -rate;
    }
}


// @fnv 0x009d6ba0
CombatProcedureMove::~CombatProcedureMove()
{}

struct TargetActor;
struct ActorVTable
{
    void* unk000;
    void* unk004;
    void* unk008;
    void* unk00c;
    void* unk010;
    void* unk014;
    void* unk018;
    void* unk01c;
    void* unk020;
    void* unk024;
    void* unk028;
    void* unk02c;
    void* unk030;
    void* unk034;
    void* unk038;
    void* unk03c;
    void* unk040;
    void* unk044;
    void* unk048;
    void* unk04c;
    void* unk050;
    void* unk054;
    void* unk058;
    void* unk05c;
    void* unk060;
    void* unk064;
    void* unk068;
    void* unk06c;
    void* unk070;
    void* unk074;
    void* unk078;
    void* unk07c;
    void* unk080;
    void* unk084;
    void* unk088;
    void* unk08c;
    void* unk090;
    void* unk094;
    void* unk098;
    void* unk09c;
    void* unk0a0;
    void* unk0a4;
    void* unk0a8;
    void* unk0ac;
    void* unk0b0;
    void* unk0b4;
    void* unk0b8;
    void* unk0bc;
    void* unk0c0;
    void* unk0c4;
    void* unk0c8;
    void* unk0cc;
    void* unk0d0;
    void* unk0d4;
    void* unk0d8;
    void* unk0dc;
    void* unk0e0;
    void* unk0e4;
    void* unk0e8;
    void* unk0ec;
    void* unk0f0;
    void* unk0f4;
    void* unk0f8;
    void* unk0fc;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10c;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11c;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12c;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13c;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14c;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15c;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16c;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17c;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18c;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19c;
    void* unk1a0;
    void* unk1a4;
    void* unk1a8;
    void* unk1ac;
    void* unk1b0;
    void* unk1b4;
    void* unk1b8;
    void* unk1bc;
    void* unk1c0;
    void* unk1c4;
    void* unk1c8;
    void* unk1cc;
    void* unk1d0;
    void* unk1d4;
    void* unk1d8;
    void* unk1dc;
    void* unk1e0;
    void* unk1e4;
    void* unk1e8;
    void* unk1ec;
    void* unk1f0;
    void*(__thiscall* get)(TargetActor*, TargetActor*, float);
};
struct TargetActor
{
    ActorVTable* vtable;
};
struct ResultValue
{
    void* BuildAvoidanceNodes();
    void* CombatGroup_CreateFlankingAvoidNodeArray();
    void* CombatGroup_CreateMovementAvoidNodeArray(void*);
};
struct ManagerValue
{
    ResultValue* FUN_00825c00(void*);
};
extern ManagerValue* DAT_011f1958;
extern const float DAT_01012054;
extern float CombatTimer_GetTimer();
struct OutputValue
{
    void Assign(void*);
    void* Modelloader_GetReferencedThis();
};
struct MemberValue
{
    void* FUN_006815c0(float, void*);
};
struct IMValue
{
    Holder* CombatController_GetCombatState();
    ResultValue* FUN_004fb070(TargetActor*, void*);
};
struct ModeValue
{
    char unk00;
    char unk01;
    char unk02;
    unsigned char enabled;
    int unk04;
};
extern ModeValue DAT_011a5650[];
// Calls the vtable getter on the holder, updates the target, and writes values to output depending on unk3c and DAT_011a5650[unk3c].enabled.
// @fnv 0x009d82e0
void CombatProcedureMove::UpdateOutput(OutputValue* output)
{
    TargetActor* holder = reinterpret_cast<TargetActor*>(reinterpret_cast<CombatProcedureEngageTarget*>(this)->CombatProcedure_GetAttacker());
    Holder* target = reinterpret_cast<IMValue*>(m_pCombatController)->CombatController_GetCombatState();
    output->Assign(
        DAT_011f1958->FUN_00825c00(holder->vtable->get(holder, holder, DAT_01012054))->BuildAvoidanceNodes());
    target->SetValue(CombatTimer_GetTimer());
    void* actor = 0;
    switch (static_cast<int>(mode))
    {
    case 4:
        output->Assign(reinterpret_cast<IMValue*>(m_pCombatController)->FUN_004fb070(holder, reinterpret_cast<MemberValue*>(&startTransform)->FUN_006815c0(0.0f, output->Modelloader_GetReferencedThis()))->CombatGroup_CreateFlankingAvoidNodeArray());
        break;
    case 0:
    case 1:
        actor = reinterpret_cast<CombatProcedureEngageTarget*>(this)->GetTarget_00996e00();
        break;
    }
    if (DAT_011a5650[mode].enabled)
    {
        output->Assign(
            reinterpret_cast<IMValue*>(m_pCombatController)->FUN_004fb070(holder, reinterpret_cast<MemberValue*>(&startTransform)->FUN_006815c0(0.0f, output->Modelloader_GetReferencedThis()))->CombatGroup_CreateMovementAvoidNodeArray(actor));
    }
}

typedef CombatProcedureMove::Location MoveLoc;

struct MoveVec
{
    float x, y, z;
    MoveVec();
    MoveVec operator-(const MoveVec&) const;
    MoveVec operator+(const MoveVec&) const;
    MoveVec& operator*=(float);
    float Length();
    bool operator==(const MoveVec&);
};
struct MoveTimer
{
    int x, y;
    void Set(float);
    bool Expired();
    float Time();
};
struct MoveSetting
{
    float* Float();
};
extern MoveSetting originalRuntimeFloatSetting461, originalRuntimeFloatSetting390, originalRuntimeFloatSetting389,
    originalRuntimeFloatSetting391, originalRuntimeFloatSetting460, g_011cfad4;
struct MoveRef
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual int Type();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual MoveVec* Position();

    void* Status();
    bool Busy();
    bool Failed();
    bool BuildingFailed();
    bool Disabled();
    bool Deleted();
    bool HasStopped();
    void Stop();
    int PathIndex();
    bool PathPoint(int, MoveVec*);
    MoveLoc Location();
    int Cell();
};
struct MoveRequest
{
    int value;
    MoveRequest(int);
    ~MoveRequest();
    void* Get();
};
struct MoveQuery
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    MoveQuery();
    ~MoveQuery();
};
struct MovePath
{
    int unk00, mode, unk08, unk0c, unk10;
    MoveLoc location;
    int unk24, unk28, unk2c, unk30, unk34, unk38;
    MoveVec start, end;
    int unk54, unk58, unk5c, unk60, unk64;
    int handle;
};
struct MoveTarget : MoveRef
{
    bool Ready();
    int Handle();
    MoveVec* Point();
    void Clear(int);
    MoveVec* LocationPoint();
};
struct MoveSmart
{
    MoveTarget* value;
    MoveTarget* Get();
    MoveSmart& operator=(int);
};
struct MoveStamp
{
    int value;
    float Time();
};
struct MoveManager
{
    void SetHandle(int);
    void SetPoint(MoveVec*);
    bool Start();
    MovePath* Path();
    MovePath* OtherPath();
    void Cancel(int);
    void ClearPath(int);
    void ClearOther(int);
    void Modes(unsigned);
    void ResetMode();
    void Destination(const MoveLoc&);
    void Update();
    bool Active();
    bool PathFailed();
    bool Allowed(unsigned);
    void Refresh();
    bool Check(MoveLoc*, MoveVec*, MoveRef*, int);
    bool Query(MoveQuery*, MoveVec*, int, float, void*);
    void Complete();
    void Finish(const MoveLoc&, int);
    MoveStamp Stamp();
};
struct MoveOwner
{
    MoveManager* Manager();
};
struct MoveProbe
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
    MoveProbe(const MoveLoc&);
    ~MoveProbe();
};
bool Probe(MoveProbe*, MoveVec*, int, int);
bool InRange(const MoveVec&, const MoveVec&, const MoveVec&, const MoveVec&);
void UpdateMove(MoveOwner*, MovePath*, MoveVec*, MoveVec*);
float MoveAmount(MoveRef*, int, int);
struct ByteAndFlagState
{
    char x, y;
    bool enabled;
    char z;
    int flags;
};
extern ByteAndFlagState MoveModes[];
extern bool DAT_011a5bfc;
// @fnv 0x009d6ca0
// src: XBOX_PDB 0x009d6ca0
void CombatProcedureMove::Update_009d6ca0()
{
    bool changed3;
    bool stop5;
    MoveRef* actorsB = Actor();
    void* actorStatus5 = actorsB->Status();
    MoveRef* other7 = Target();
    MoveManager* manager2 = reinterpret_cast<MoveOwner*>(m_pCombatController)->Manager();
    switch (unk10)
    {
    case 0:
        currentTransform = startTransform;
        unk10 = 1;
        if (!Begin())
            return;
        if (mode == 15)
            reinterpret_cast<MoveTimer*>(&state74)->Set(*originalRuntimeFloatSetting461.Float());
        break;
    case 1:
    case 2:
        if (reinterpret_cast<MoveSmart*>(&state58)->Get() && !actorsB->Busy())
        {
            MoveRef* ref = reinterpret_cast<MoveSmart*>(&state58)->Get();
            if (ref->Type() == 8)
            {
                MoveTarget* node = (MoveTarget*)ref;
                if (node->Ready())
                {
                    manager2->SetHandle(node->Handle());
                    MoveVec* point = node->Point();
                    manager2->SetPoint(point);
                    node->Clear(0);
                    if (point)
                    {
                        currentTransform.Set(*node->LocationPoint(), actorsB->Cell());
                        if (manager2->Start())
                        {
                            unk10 = 2;
                            active54 = true;
                            MoveVec pos;
                            UpdateMove(reinterpret_cast<MoveOwner*>(m_pCombatController), manager2->Path(), &pos, &(*reinterpret_cast<MoveVec*>(&pos48)));
                            reinterpret_cast<MoveVec*>(&pos48)->z += MoveAmount(actorsB, 2, 0);
                            reinterpret_cast<MoveTimer*>(&state6C)->Set(0.5f);
                        }
                        else
                        {
                            (*reinterpret_cast<MoveSmart*>(&state58)) = 0;
                            currentTransform = startTransform;
                            unk10 = 1;
                            Begin();
                            return;
                        }
                    }
                    else
                        currentTransform = startTransform;
                }
            }
            (*reinterpret_cast<MoveSmart*>(&state58)) = 0;
        }
        if (actorsB->Failed())
        {
            if (!actorsB->BuildingFailed())
            {
                if (unk10 == 2)
                {
                    MovePath* path = manager2->Path();
                    if (path)
                    {
                        manager2->Cancel(path->handle);
                        manager2->ClearPath(0);
                    }
                }
                else
                {
                    switch (mode)
                    {
                    case 0:
                    case 1:
                    case 7:
                    case 8:
                        manager2->Modes(1 << mode);
                        break;
                    case 3:
                        manager2->ResetMode();
                        break;
                    }
                    MovePath* path = manager2->OtherPath();
                    if (path && path->mode == mode)
                    {
                        manager2->Cancel(path->handle);
                        manager2->ClearOther(0);
                    }
                }
                manager2->Destination(currentTransform);
                manager2->Update();
                switch (mode)
                {
                case 1:
                    if (unk10 != 2 && *currentTransform.Point() == *startTransform.Point())
                        manager2->Destination(startTransform);
                    break;
                }
            }
            Fail(actorsB->BuildingFailed() ? "Pathing failed while moving to destination"
                                           : "Path Building failed to destination");
            return;
        }
        if (reinterpret_cast<MoveRef*>(target38) && (reinterpret_cast<MoveRef*>(target38)->Disabled() || reinterpret_cast<MoveRef*>(target38)->Deleted()))
        {
            Fail("Target ref is now disabled or deleted");
            return;
        }
        changed3 = false;
        if (reinterpret_cast<MoveRef*>(target38))
        {
            void* targetStatus8 = 0;
            if (reinterpret_cast<MoveRef*>(target38)->IsActor())
            {
                MoveRef* ref = reinterpret_cast<MoveRef*>(target38);
                targetStatus8 = ref->Status();
            }
            MoveLoc locationB = reinterpret_cast<MoveRef*>(target38)->Location();
            float distance8 = 0.0f;
            if (!actorStatus5 && !targetStatus8)
                distance8 = unk10 == 2
                                ? *originalRuntimeFloatSetting390.Float() * *originalRuntimeFloatSetting390.Float()
                                : *originalRuntimeFloatSetting389.Float() * *originalRuntimeFloatSetting389.Float();
            else
                distance8 = *originalRuntimeFloatSetting391.Float() * *originalRuntimeFloatSetting391.Float();
            if (distance8 < locationB.Distance(startTransform))
            {
                startTransform = locationB;
                changed3 = true;
            }
        }
        if (unk10 == 2 && reinterpret_cast<MoveTimer*>(&state6C)->Expired())
        {
            if (!changed3 && other7 && manager2->Active())
            {
                MovePath* path = manager2->Path();
                if (!path)
                    changed3 = true;
                else
                {
                    MoveLoc targetLoc = other7->Location();
                    MoveLoc actorLoc = actorsB->Location();
                    if (actorLoc.Distance(targetLoc) < 16777216.0)
                    {
                        if (!InRange(path->location.Position(), *other7->Position(), path->start, path->end))
                            changed3 = true;
                        else if (!manager2->Check(&path->location, currentTransform.Point(), other7, 0))
                            changed3 = true;
                    }
                }
            }
            reinterpret_cast<MoveTimer*>(&state6C)->Set(0.5f);
        }
        if (changed3)
        {
            if (unk10 == 2)
            {
                manager2->Complete();
                manager2->ClearPath(0);
                active54 = false;
            }
            currentTransform = startTransform;
            unk10 = 1;
            if (!Begin())
                return;
            return;
        }
        if (!DAT_011a5bfc && unk10 == 1 && !actorsB->Busy() && !actorStatus5 && MoveModes[mode].enabled &&
            manager2->Allowed(1))
        {
            float radius5 = 256.0f;
            int pathIndex9 = actorsB->PathIndex();
            if (unk60 == -1)
                radius5 = 512.0f;
            if (pathIndex9 != unk60 || reinterpret_cast<MoveTimer*>(&state64)->Expired())
            {
                unk60 = pathIndex9;
                reinterpret_cast<MoveTimer*>(&state64)->Set(2.0f);
                MoveRequest avoid7(0);
                bool initialized16 = false;
                MoveVec previous6_2 = *actorsB->Position();
                MoveVec point35;
                float lengthVal = 0.0f;
                bool done7 = false;
                while (!done7 && actorsB->PathPoint(pathIndex9 + 1, &point35))
                {
                    pathIndex9 = pathIndex9 + 1;
                    MoveVec delta8 = point35 - previous6_2;
                    float segment5 = delta8.Length();
                    if (lengthVal + segment5 > 1536.0)
                    {
                        delta8 *= float(1536.0 - lengthVal);
                        point35 = previous6_2 + delta8;
                        done7 = true;
                    }
                    lengthVal = lengthVal + segment5;
                    previous6_2 = point35;
                    if (!initialized16)
                        Avoid(&avoid7);
                    initialized16 = true;
                    MoveQuery query_2;
                    if (manager2->Query(&query_2, &point35, mode, radius5, avoid7.Get()))
                    {
                        active54 = true;
                        manager2->Refresh();
                        MoveVec pos;
                        UpdateMove(reinterpret_cast<MoveOwner*>(m_pCombatController), manager2->Path(), &pos, &(*reinterpret_cast<MoveVec*>(&pos48)));
                        reinterpret_cast<MoveVec*>(&pos48)->z += MoveAmount(actorsB, 2, 0);
                        unk10 = 2;
                        currentTransform.Set(pos, actorsB->Cell());
                        if (!Begin())
                            return;
                        reinterpret_cast<MoveTimer*>(&state6C)->Set(0.5f);
                        break;
                    }
                }
            }
        }
        stop5 = false;
        if (mode == 15 && reinterpret_cast<MoveTimer*>(&state74)->Expired())
        {
            MoveLoc loc = actorsB->Location();
            if (loc.Distance(startTransform) <
                *originalRuntimeFloatSetting460.Float() * *originalRuntimeFloatSetting460.Float())
            {
                MoveProbe request(startTransform);
                if (Probe(&request, loc.Point(), 0, 0))
                    stop5 = true;
            }
            reinterpret_cast<MoveTimer*>(&state74)->Set(*g_011cfad4.Float());
        }
        if (stop5)
            actorsB->Stop();
        if (stop5 || actorsB->HasStopped())
        {
            if (unk10 == 2)
            {
                unk10 = 3;
                reinterpret_cast<MoveTimer*>(&pos40)->Set(Duration());
                reinterpret_cast<MoveTimer*>(&state6C)->Set(0.25f);
                Look((*reinterpret_cast<MoveVec*>(&pos48)), 3);
                SetState(2);
            }
            else
            {
                manager2->Finish(startTransform, mode);
                Clear();
            }
            return;
        }
        break;
    case 3: {
        bool finished6 = false;
        MovePath* path2 = manager2->Path();
        if (reinterpret_cast<MoveTimer*>(&pos40)->Expired() || !path2)
            finished6 = true;
        else if (other7)
        {
            float deadline = float(reinterpret_cast<MoveTimer*>(&pos40)->Time() + 1.0);
            if (deadline < CombatTimer_GetTimer())
            {
                if (manager2->PathFailed())
                    finished6 = true;
                else if (deadline < manager2->Stamp().Time())
                    finished6 = true;
            }
            if (!finished6 && manager2->Active() && reinterpret_cast<MoveTimer*>(&state6C)->Expired())
            {
                if (!manager2->Check(&path2->location, currentTransform.Point(), other7, 1))
                    finished6 = true;
                reinterpret_cast<MoveTimer*>(&state6C)->Set(0.25f);
            }
        }
        if (finished6)
        {
            unk10 = 0;
            manager2->Complete();
            active54 = false;
            manager2->ClearPath(0);
            Reset();
        }
    }
    break;
    default:;
    }
}

extern NiPoint3 DAT_011f426c;
extern const float DAT_0103a1c4;
extern bool DAT_011a5bfc;
extern const double DAT_01012060;
struct Request052
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    Request052();
    ~Request052();
    void PathingRequest_SetCenterRadius(NiPoint3&, float);
    void SetUseSoft(int);
};
struct SpecialRequest052
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    SpecialRequest052();
    ~SpecialRequest052();
    void FUN_00705b10(int);
};
// Actor methods at 0x008b38d0 and 0x008b3820 are absent from the shared API; inherit its layout and virtual slots.
class CombatMovementRequestAccess : public Actor
{
public:
    void BuildPathingRequest(void*, NiPoint3*, void*, float, void*);
    void* Actor_GetCurrentPathingRequest();
};
struct LocationMember052
{
    NiPoint3* FUN_006815c0();
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void FUN_0098ddd0(NiPoint3*);
    int unk00, unk04, unk08, unk0c;
};
struct State052
{
    unsigned char type;
    unsigned char unk01, unk02, unk03;
    int unk04;
    LocationMember052 location;
};
struct Holder052
{
    State052* FUN_007058c0();
    bool FUN_00461580(int);
    float CombatState_GetLocationTargetDistance();
    bool IsFlagSet(int);
    void BuildCoveredMoveRequest(SpecialRequest052*);
};
struct Manager052
{
    Holder052* CombatController_GetCombatState();
    bool CombatController_CombatPlanContainsAction(int);
};
struct Location052
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
    Location052(const NiPoint3&, Actor*);
    ~Location052();
    bool FUN_006ded70(float);
};
struct Avoid052
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    static void* operator new(unsigned int);
    Avoid052();
    void AppendNode(const PathingAvoidNode&);
};
struct Output052
{
    Avoid052* Modelloader_GetReferencedThis();
    void Assign(Avoid052*);
};
extern Setting DAT_011cf120, DAT_011cf4e0;
struct Ref052
{
    int value;
    void FUN_0066b0d0(void*);
};
NiPoint3 __cdecl CombatUtilities_ComputeFaceTargetLocation(Actor*, Actor*, NiPoint3*, float);
bool __cdecl CombatUtilities_CalculateLOS(Actor*, Actor*, NiPoint3*, NiPoint3*, int, int);
extern const char DAT_01091c80[];
// @fnv 0x009d7d00
bool CombatProcedureMove::UpdateMovementRequest(Output052* output)
{
    float request;
    bool d;
    float g;
    ::Actor* a = reinterpret_cast<CombatProcedureEngageTarget*>(this)->CombatProcedure_GetAttacker();
    void* c = reinterpret_cast<CombatProcedureEngageTarget*>(this)->GetTarget_00996e00();
    Holder052* k = reinterpret_cast<Manager052*>(m_pCombatController)->CombatController_GetCombatState();
    int b = 3;
    NiPoint3 h = DAT_011f426c;
    g = 0.0f;
    switch (mode)
    {
    case 3:
        h = *static_cast<const ::Actor*>(a)->GetPos();
        g = DAT_0103a1c4;
        break;
    case 0:
        if (reinterpret_cast<Manager052*>(m_pCombatController)->CombatController_CombatPlanContainsAction(24))
            b = 4;
        break;
    }
    State052* i = k->FUN_007058c0();
    if (i && i->type == 1 && !k->FUN_00461580(256) && mode != 8 && i->location.GetHavokWorldObjectCountInSceneGraph_0084e3a0() == a->TESObjectREFR_GetSpace())
    {
        h = *i->location.FUN_006815c0();
        g = k->CombatState_GetLocationTargetDistance();
        NiPoint3 delta = h - *static_cast<const ::Actor*>(a)->GetPos();
        if (delta.FUN_004a7290() > g * g)
            g = 0.0f;
    }
    request = 0.0f;
    if (unk10 == 1)
        request = rate;
    if (mode == 1 && unk10 == 1 && reinterpret_cast<::Actor*>(target38))
    {
        NiPoint3 position = CombatUtilities_ComputeFaceTargetLocation(a, reinterpret_cast<::Actor*>(target38), reinterpret_cast<LocationMember052*>(&startTransform)->FUN_006815c0(), DAT_01012054);
        Location052 location(position, a);
        if (location.FUN_006ded70(a->FUN_008be1b0()) &&
            CombatUtilities_CalculateLOS(a, reinterpret_cast<::Actor*>(target38), &position, reinterpret_cast<LocationMember052*>(&startTransform)->FUN_006815c0(), 0, -1))
        {
            reinterpret_cast<LocationMember052*>(&currentTransform)->FUN_0098ddd0(&position);
            if (!output->Modelloader_GetReferencedThis())
                output->Assign(new Avoid052);
            output->Modelloader_GetReferencedThis()->AppendNode(
                PathingAvoidNode(*reinterpret_cast<const ::Actor*>(target38)->GetPos(), *DAT_011cf4e0.Setting_Float_00403e20(), *DAT_011cf120.Setting_Float_00403e20()));
        }
    }
    void* e = 0;
    Request052 j;
    SpecialRequest052 f;
    if (DAT_011a5bfc && (unsigned char)DAT_011a5650[mode].unk02 && k->IsFlagSet(1) && !a->FUN_00931850())
    {
        k->BuildCoveredMoveRequest(&f);
        f.FUN_00705b10(mode);
        e = &f;
    }
    else
        e = &j;
    d = false;
    if (request < 0.0)
    {
        request = -request;
        d = true;
    }
    static_cast<CombatMovementRequestAccess*>(a)->BuildPathingRequest(e, reinterpret_cast<LocationMember052*>(&currentTransform)->FUN_006815c0(), reinterpret_cast<LocationMember052*>(&currentTransform)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), request, output->Modelloader_GetReferencedThis());
    ((Request052*)e)->PathingRequest_SetCenterRadius(h, g);
    if (d)
        ((Request052*)e)->SetUseSoft(0);
    if (!a->SetPathingRequestAvoidNodes(e))
    {
        Fail(DAT_01091c80);
        return false;
    }
    unk60 = -1;
    reinterpret_cast<Ref052*>(&state58)->FUN_0066b0d0(static_cast<CombatMovementRequestAccess*>(a)->Actor_GetCurrentPathingRequest());
    reinterpret_cast<CombatProcedureEngageTarget*>(this)->SetMoveMode_00996e20(b);
    return true;
}

struct DebugPoint
{
    float x, y, z;
};
struct DebugReference
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual const char* GetDebugName();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
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
    virtual const DebugPoint& GetDebugPosition();
    DebugReference* TESObjectREFR_GetSpace();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    int GetFormEditorIDLength();
    const char* TESObjectREFR_GetFullName();
};
struct DebugOwner
{
    DebugReference* GetFieldBC();
};
struct DebugLocation
{
    DebugPoint& FUN_006815c0();
    DebugReference* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
struct DebugTimer
{
    float FUN_00435e00();
    float CombatTimer_GetTargetTime();
    bool CombatTimer_IsSet();
    float start, duration;
};
struct DebugDisplay
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void __cdecl Print(int, int, const char*, ...);
};
// Prints the move state, destination cell and position, target info and destination timer to the debug display at the given coordinates.
// @fnv 0x009d8520
void CombatProcedureMove::PrintDebugInfo(DebugDisplay* display, int x, int y)
{
    switch (unk10)
    {
    case 0:
        display->Print(x, y, "INITIALIZING");
        break;
    case 1:
        display->Print(x, y, "MOVING");
        break;
    case 2:
        display->Print(x, y, "MOVING_USING_COVER");
        display->Print(x, y, "Check Cover Timer: %.02f/%.02f", reinterpret_cast<DebugTimer*>(&state6C)->FUN_00435e00(), reinterpret_cast<DebugTimer*>(&state6C)->CombatTimer_GetTargetTime());
        break;
    case 3:
        display->Print(x, y, "HIDING_BEHIND_COVER");
        display->Print(x, y, "Hiding Timer: %.02f/%.02f", reinterpret_cast<DebugTimer*>(&pos40)->FUN_00435e00(), reinterpret_cast<DebugTimer*>(&pos40)->CombatTimer_GetTargetTime());
        display->Print(x, y, "Check Cover Timer: %.02f/%.02f", reinterpret_cast<DebugTimer*>(&state6C)->FUN_00435e00(), reinterpret_cast<DebugTimer*>(&state6C)->CombatTimer_GetTargetTime());
        break;
    }
    DebugPoint position = reinterpret_cast<DebugLocation*>(&startTransform)->FUN_006815c0();
    DebugReference* cell = reinterpret_cast<DebugLocation*>(&startTransform)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    if (cell && cell != reinterpret_cast<DebugOwner*>(m_pCombatController)->GetFieldBC()->TESObjectREFR_GetSpace())
        display->Print(x, y, "Destination: %s (%.02f,%.02f,%.02f)", cell->GetDebugName(), position.x, position.y,
                       position.z);
    else
        display->Print(x, y, "Destination: (%.02f,%.02f,%.02f)", position.x, position.y, position.z);
    if (reinterpret_cast<DebugReference*>(target38))
    {
        DebugPoint targetPosition = reinterpret_cast<DebugReference*>(target38)->GetDebugPosition();
        display->Print(x, y, "Target: '%s' (%08X) - Position: (%.02f,%.02f,%.02f)",
                       reinterpret_cast<DebugReference*>(target38)->GetFormEditorIDLength() ? reinterpret_cast<DebugReference*>(target38)->GetDebugName() : reinterpret_cast<DebugReference*>(target38)->TESObjectREFR_GetFullName(), reinterpret_cast<DebugReference*>(target38)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(),
                       targetPosition.x, targetPosition.y, targetPosition.z);
    }
    if (reinterpret_cast<DebugTimer*>(&state74)->CombatTimer_IsSet())
        display->Print(x, y, "Check Destination Timer: %.02f/%.02f", reinterpret_cast<DebugTimer*>(&state74)->FUN_00435e00(),
                       reinterpret_cast<DebugTimer*>(&state74)->CombatTimer_GetTargetTime());
}


namespace fnv_009d8ad0 {
using ::TESForm;
using ::TESObjectREFR;

extern "C" TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int formID);

// CombatProcedure vftable 0x01090874 slot 16 is 0x004534f0 (empty, ret 4); CombatProcedureMove overrides it with
// 0x009d8ad0, which first runs the base version. The shared CombatProcedure declares that slot as vf16().
struct CombatProcedureSlot16Base
{
    void FUN_004534f0(unsigned int);
};

struct CommandTarget
{
    unsigned int unk00;
    void FUN_0066b0d0(void* target);
};


}  // namespace fnv_009d8ad0

// Resolves the saved target form and restores the movement request when active5C is set.
// @fnv 0x009d8ad0

// src: XBOX_PDB 0x009d8ad0
void CombatProcedureMove::InitLoadGame_009d8ad0(unsigned int value)
{
    ::Actor* context = reinterpret_cast<CombatProcedureEngageTarget*>(this)->CombatProcedure_GetAttacker();

    reinterpret_cast<fnv_009d8ad0::CombatProcedureSlot16Base*>(this)->FUN_004534f0(value);

    target38 = (unsigned int)(target38 ? dynamic_cast<TESObjectREFR*>(fnv_009d8ad0::TESForm_GetFormByNumericID(target38)) : 0);

    if (active5C)
        reinterpret_cast<fnv_009d8ad0::CommandTarget*>(&state58)->FUN_0066b0d0(static_cast<CombatMovementRequestAccess*>(context)->Actor_GetCurrentPathingRequest());
}
