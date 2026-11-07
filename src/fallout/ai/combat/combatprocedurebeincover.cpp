#include "../../../../include/InterfaceManager.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BaseFormComponent.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/CombatProcedureBeInCover.h"
#include "../../../../include/CombatProcedureEngageTarget.h"
#include "../../../../include/TESCombatStyle.h"
#include "../../../../include/IDebugText.h"
#include "../../../../include/TESAttributes.h"

// src/fallout/ai/combat/combatprocedurebeincover.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedurebeincover.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];
// @fnv 0x009d2510
int CombatProcedureBeInCover::GetType()
{
    return 7;
}

void __cdecl operator delete(void*);

extern "C" float __cdecl RandomFloat(float, float);

// Returns a random float between the two floats stored at offsets 0x20 and 0x24 of this object.
// @fnv 0x009d32e0
float __fastcall GetCoverWaitTime(TESCombatStyle* apStyle)
{
    return RandomFloat(*(float*)&apStyle->m_kUnsignedIntArray16.data[2],
                       *(float*)&apStyle->m_kUnsignedIntArray16.data[3]);
}

float __cdecl RandomFloat(float, float);

// Returns a random float between the two float values stored at offsets 0x28 and 0x2c of this object.
// @fnv 0x009d3310
float __fastcall GetOutOfCoverWaitTime(TESCombatStyle* apStyle)
{
    return RandomFloat(*(float*)&apStyle->m_kUnsignedIntArray16.data[4],
                       *(float*)&apStyle->m_kUnsignedIntArray16.data[5]);
}

float __cdecl RandomFloat(float, float);

// Returns a random float between the combat style's two stored float fields.
// @fnv 0x009d3340
float __thiscall TESCombatStyle::GetRandomValue()
{
    return RandomFloat(*(float*)&m_kUnsignedIntArray16.data[6], *(float*)&m_kUnsignedIntArray16.data[7]);
}

// @fnv 0x009d2520: scalar deleting destructor emitted by the compiler.
// @fnv 0x009d2550
CombatProcedureBeInCover::~CombatProcedureBeInCover()
{}

struct TESAmmoInitCalls
{
    Actor* GetFieldBC();
};
// @fnv 0x009d2570
void CombatProcedureBeInCover::StopAttackerAndEngageTarget()
{
    Actor* actor = (((TESAmmoInitCalls*)m_pCombatController))->GetFieldBC();
    actor->StopMoving();
    ((CombatProcedureEngageTarget*)this)->ClearMoveMode();
    RunProcedure();
}

struct FUN_00980070_shell
{
    unsigned int GetCurrentCombatStyle();
};
struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float);
};
// @fnv 0x009d33e0
void CombatProcedureBeInCover::UpdateCombatProcedure(Projectile* apProjectile)
{
    switch (eState)
    {
    case 1:
        ((FUN_008d7f40_shell*)&m_waitTimer)
            ->FUN_008d7f40(GetCoverWaitTime((TESCombatStyle*)((FUN_00980070_shell*)(int)m_pCombatController)->GetCurrentCombatStyle()));
        break;
    case 2:
        ((CombatProcedureEngageTarget*)this)->CombatProcedure_GetAttacker()->StopMoving();
        RunProcedure();
        eState = COVER_STATE_FIRING_OUT_OF_COVER;
        ((FUN_008d7f40_shell*)&m_firingTimer)
            ->FUN_008d7f40(
                ((TESCombatStyle*)((FUN_00980070_shell*)(int)m_pCombatController)->GetCurrentCombatStyle())->GetRandomValue());
        break;
    }
}

enum DEBUGTEXT_LOCATION
{
    DEBUGTEXT_LOCATION_0
};

enum DEBUGTEXT_JUSTIFY
{
    DEBUGTEXT_JUSTIFY_0
};

extern const char $SG2706[];
extern const char str_01091084[];
extern const char str_0109135c[];
extern const char str_01091380[];
extern const char str_010913a4[];
extern const char str_010913c8[];
extern const char str_010913ec[];
extern const char str_010913fc[];
extern const char str_01091414[];
extern const char str_01091420[];
extern const char str_01091434[];
extern const char str_01091458[];
extern const char str_01091474[];
extern const char str_0109148c[];
extern const char str_01091498[];
extern const char str_010914b0[];

// Prints debug text describing the current cover state and its timers, positions and target-blocked status via pDebugText.
// @fnv 0x009d3470
void CombatProcedureBeInCover::DebugText(IDebugText* pDebugText, DEBUGTEXT_LOCATION aeLocation,
                                         DEBUGTEXT_JUSTIFY aeJustify)
{
    switch (eState)
    {
    case COVER_STATE_INITIALIZING:
        pDebugText->Print(aeLocation, aeJustify, $SG2706);
        break;

    case COVER_STATE_WAITING_BEHIND_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_010914b0);
        pDebugText->Print(aeLocation, aeJustify, str_01091498, m_waitTimer.GetElapsedTime(), m_waitTimer.GetValue());
        break;

    case COVER_STATE_MOVING_OUT:
        pDebugText->Print(aeLocation, aeJustify, str_0109148c);
        break;

    case COVER_STATE_WAITING_OUT_OF_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_01091474);
        pDebugText->Print(aeLocation, aeJustify, str_01091458, m_waitingOutTimer.GetElapsedTime(),
                          m_waitingOutTimer.GetValue());
        if (m_targetBlockedTimer.CombatTimer_IsSet())
        {
            pDebugText->Print(aeLocation, aeJustify, str_01091434, m_targetBlockedTimer.GetElapsedTime(),
                              m_targetBlockedTimer.GetValue());
        }
        break;

    case COVER_STATE_FIRING_OUT_OF_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_01091420);
        pDebugText->Print(aeLocation, aeJustify, str_01091084, m_firingTimer.GetElapsedTime(),
                          m_firingTimer.GetValue());
        break;

    case COVER_STATE_MOVING_IN:
        pDebugText->Print(aeLocation, aeJustify, str_01091414);
        break;

    case COVER_STATE_MOVING_IN_AND_ROTATE:
        pDebugText->Print(aeLocation, aeJustify, str_010913fc);
        break;

    case COVER_STATE_HOLDING_GROUND:
        pDebugText->Print(aeLocation, aeJustify, str_010913ec);
        pDebugText->Print(aeLocation, aeJustify, str_010913c8, m_holdingGroundTimer.GetElapsedTime(),
                          m_holdingGroundTimer.GetValue());
        break;
    }

    if (m_reevaluateTimer.CombatTimer_IsSet())
    {
        pDebugText->Print(aeLocation, aeJustify, str_010913a4, m_reevaluateTimer.GetElapsedTime(),
                          m_reevaluateTimer.GetValue());
    }

    pDebugText->Print(aeLocation, aeJustify, str_01091380, m_afFirstVector[0], m_afFirstVector[1], m_afFirstVector[2]);

    pDebugText->Print(aeLocation, aeJustify, str_0109135c, m_afSecondVector[0], m_afSecondVector[1],
                      m_afSecondVector[2]);
}

struct CoverVec3
{
    float x;
    float y;
    float z;
    CoverVec3();
};

struct CoverTimer
{
    unsigned int unk00;
    unsigned int unk04;
    CoverTimer();
};

// The shared class stores these vectors and timers as raw storage.
// Invoke their constructors explicitly to preserve the original initialization calls.
// @fnv 0x009d2440
CombatProcedureBeInCover::CombatProcedureBeInCover(void* pLoc) : eState(COVER_STATE_INITIALIZING), m_pCurrentCoverPoint(pLoc)
{
    ((CoverVec3*)m_afFirstVector)->CoverVec3::CoverVec3();
    ((CoverVec3*)m_afSecondVector)->CoverVec3::CoverVec3();
    ((CoverVec3*)_pad1)->CoverVec3::CoverVec3();
    ((CoverTimer*)&m_waitTimer)->CoverTimer::CoverTimer();
    ((CoverTimer*)&m_waitingOutTimer)->CoverTimer::CoverTimer();
    ((CoverTimer*)&m_firingTimer)->CoverTimer::CoverTimer();
    ((CoverTimer*)&m_reevaluateTimer)->CoverTimer::CoverTimer();
    ((CoverTimer*)&m_holdingGroundTimer)->CoverTimer::CoverTimer();
    ((CoverTimer*)&m_targetBlockedTimer)->CoverTimer::CoverTimer();
}

struct FUN_00586150_shell
{
    void* CombatController_GetCombatState();
};

struct FUN_0097fb60_shell
{
    int GetFieldAtE8();
};

struct FUN_00865e50_shell
{
    void FUN_00865e50(void* p, int size, int flags);
};

struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(void* a1);
};

// @fnv 0x009d3800
void CombatProcedureBeInCover::SaveGame(BGSSaveFormBuffer* a1)
{
    unsigned char flag;

    CombatProcedure::SaveGame(a1);
    flag = ((FUN_0097fb60_shell*)((FUN_00586150_shell*)((void*)m_pCombatController))->CombatController_GetCombatState())->GetFieldAtE8() ==
           (int)m_pCurrentCoverPoint;
    ((FUN_00865e50_shell*)a1)->FUN_00865e50(&eState, 4, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50(&flag, 1, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50(m_afFirstVector, 0xc, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50(m_afSecondVector, 0xc, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50(_pad1, 0xc, 0);
    ((FUN_009a5eb0_shell*)&m_waitTimer)->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)&m_waitingOutTimer)->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)&m_firingTimer)->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)&m_reevaluateTimer)->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)&m_holdingGroundTimer)->FUN_009a5eb0(a1);
    ((FUN_009a5eb0_shell*)&m_targetBlockedTimer)->FUN_009a5eb0(a1);
}

class Tile;


unsigned int __fastcall GetFieldValue(unsigned int* apData);
struct FUN_009a5f20_Timer
{
    char data[8];
    void FUN_009a5f20(BGSLoadFormBuffer* apBuffer);
};
// Loads state, cover location, three 3-float vectors and six timers from the form buffer, resolving the cover location via the interface manager.
// @fnv 0x009d38f0
void CombatProcedureBeInCover::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    CombatProcedure::LoadGame(apBuffer);
    bool bHasCover = false;
    apBuffer->LoadData(&eState, 4u);
    apBuffer->LoadData(&bHasCover, 1u);
    if (bHasCover)
        m_pCurrentCoverPoint = (void*)((FUN_0097fb60_shell*)(((InterfaceManager*)m_pCombatController))->CombatController_GetCombatState())->GetFieldAtE8();
    else
        m_pCurrentCoverPoint = (void*)GetFieldValue((unsigned int*)(((InterfaceManager*)m_pCombatController))->CombatController_GetCombatState());
    apBuffer->LoadData(m_afFirstVector, 0xcu);
    apBuffer->LoadData(m_afSecondVector, 0xcu);
    apBuffer->LoadData(_pad1, 0xcu);
    ((FUN_009a5f20_Timer*)&m_waitTimer)->FUN_009a5f20(apBuffer);
    ((FUN_009a5f20_Timer*)&m_waitingOutTimer)->FUN_009a5f20(apBuffer);
    ((FUN_009a5f20_Timer*)&m_firingTimer)->FUN_009a5f20(apBuffer);
    ((FUN_009a5f20_Timer*)&m_reevaluateTimer)->FUN_009a5f20(apBuffer);
    ((FUN_009a5f20_Timer*)&m_holdingGroundTimer)->FUN_009a5f20(apBuffer);
    ((FUN_009a5f20_Timer*)&m_targetBlockedTimer)->FUN_009a5f20(apBuffer);
}

struct CoverPoint
{
    float x, y, z;
    CoverPoint operator-(const CoverPoint&) const;
    float FUN_004a7290() const;
};
struct CoverClock
{
    int started;
    float duration;
    bool CombatTimer_IsSet();
    bool FUN_008d7f80();
    void FUN_008d7f40(float);
    float GetElapsedTime();
    float GetValue();
    float AStarSearch_EvaluateValue_006a7f50();
    void Reset();
};
struct CoverRequest
{
    virtual ~CoverRequest();
    CoverRequest();
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
};
struct CoverActor
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
    virtual CoverPoint GetAim();
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
    virtual const CoverPoint& GetPosition();

    void StopMoving();
    float Actor_GetSneakHeight(bool);
    float GetActorHeight() const;
    void* GetWorld();
    void* GetContainingCell();
    void SetupPath(CoverRequest&, const CoverPoint&, void*, void*, float, int);
    bool RequestPath(CoverRequest*);
    bool IsAttacking();
    float AttackTime();
    void UpdateAttackState();
    bool PathFailed();
    bool PathBuiltFailed();
    bool PathFinished();
};
struct CombatCoverPoint
{
    int unk00, unk04;
    CoverPoint position;
    CoverPoint direction;
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
    bool occupied;
    bool CanFire();
    bool CanRotate();
    void SetFlag(int);
};
struct CoverStamp
{
    int value;
    float GetElapsedTime();
    float AStarSearch_EvaluateValue_006a7f50();
};
struct CoverState
{
    bool Validate(CombatCoverPoint*);
    bool IsGroup();
    bool CheckPath(const CoverPoint&, const CoverPoint&, CoverActor*, int);
    CoverStamp GetStamp();
    void End(int);
    bool IsBlocked();
};
struct CoverGroup
{
    bool HasLOS(CoverActor*);
};
struct CoverManager
{
    CoverState* CombatController_GetCombatState();
    CoverGroup* GetGroup();
    bool CombatController_GetAttackerCanSneak();
    TESCombatStyle* GetCurrentCombatStyle();
};
struct CoverSetting
{
    float* Float();
};
extern CoverSetting originalRuntimeFloatSetting378, originalRuntimeFloatSetting379;
void ComputePositions(CoverManager*, CombatCoverPoint*, CoverPoint&, CoverPoint&);
// Calls used by the cover state machine that are not declared on the shared class yet.
struct CoverProcedureCalls
{
    void ClearLook();
    void LookAt(const CoverPoint&, unsigned char);
};
static const char kCoverLOS[] = "Target has LOS on Cover position";
// Validates the cover location, reevaluates paths/LOS, and advances the cover procedure state machine through movement, firing and holding phases.
// @fnv 0x009d25b0
void CombatProcedureBeInCover::UpdateCoverState()
{
    if (!(((CoverManager*)m_pCombatController))->CombatController_GetCombatState()->Validate(((CombatCoverPoint*)m_pCurrentCoverPoint)))
    {
        ((CombatProcedureEngageTarget*)this)->Fail("Cover Location no longer exists");
        return;
    }
    CoverActor* actor_ = (CoverActor*)((CombatProcedureEngageTarget*)this)->CombatProcedure_GetAttacker();
    CoverActor* targetTmp = (CoverActor*)((CombatProcedureEngageTarget*)this)->GetTarget();
    CoverState* combat7 = (((CoverManager*)m_pCombatController))->CombatController_GetCombatState();
    CoverGroup* group7 = (((CoverManager*)m_pCombatController))->GetGroup();
    bool evaluatedA = false;
    bool changedVal = false;
    bool canFire4 = ((CombatCoverPoint*)m_pCurrentCoverPoint)->CanFire();
    bool active8 = (((CoverManager*)m_pCombatController))->CombatController_GetAttackerCanSneak();
    if (!(*(CoverClock*)&m_reevaluateTimer).CombatTimer_IsSet())
        (*(CoverClock*)&m_reevaluateTimer).FUN_008d7f40(1.0f);
    else if ((*(CoverClock*)&m_reevaluateTimer).FUN_008d7f80())
    {
        (*(CoverClock*)&m_reevaluateTimer).FUN_008d7f40(1.0f);
        evaluatedA = true;
        if (eState != 0)
        {
            if (combat7->IsGroup())
            {
                bool reachable4 = combat7->CheckPath(((CombatCoverPoint*)m_pCurrentCoverPoint)->direction, (*(CoverPoint*)m_afFirstVector), targetTmp, 1);
                if (!reachable4 && eState != 7)
                {
                    actor_->StopMoving();
                    ((CoverProcedureCalls*)this)->ClearLook();
                    eState = COVER_STATE_HOLDING_GROUND;
                    (*(CoverClock*)&m_holdingGroundTimer).FUN_008d7f40(2.0f);
                    changedVal = true;
                }
            }
            else
            {
                CoverPoint coverPos9 = targetTmp->GetPosition();
                CoverPoint targetPos = ((CombatCoverPoint*)m_pCurrentCoverPoint)->position;
                CoverPoint delta = coverPos9 - targetPos;
                if (delta.FUN_004a7290() > 589824.0 && group7->HasLOS(targetTmp))
                    ((CombatCoverPoint*)m_pCurrentCoverPoint)->SetFlag(1);
            }
        }
    }
    switch (eState)
    {
    case 0: {
        ((CombatCoverPoint*)m_pCurrentCoverPoint)->occupied = false;
        ComputePositions((((CoverManager*)m_pCombatController)), ((CombatCoverPoint*)m_pCurrentCoverPoint), (*(CoverPoint*)m_afFirstVector), (*(CoverPoint*)m_afSecondVector));
        (*(CoverPoint*)_pad1) = (*(CoverPoint*)m_afSecondVector);
        float height = (((CoverManager*)m_pCombatController))->CombatController_GetAttackerCanSneak() ? actor_->Actor_GetSneakHeight(false) : actor_->GetActorHeight();
        (*(CoverPoint*)_pad1).z = height * 0.75 + (*(CoverPoint*)_pad1).z;
        CoverRequest request;
        actor_->SetupPath(request, (*(CoverPoint*)m_afFirstVector), actor_->GetContainingCell(), actor_->GetWorld(), 0.0f, 0);
        if (!actor_->RequestPath(&request))
        {
            ((CombatProcedureEngageTarget*)this)->Fail("Cannot setup path to Cover position");
            return;
        }
        eState = COVER_STATE_MOVING_IN_AND_ROTATE;
        if (((CombatCoverPoint*)m_pCurrentCoverPoint)->CanRotate())
            ((CoverProcedureCalls*)this)->LookAt((*(CoverPoint*)_pad1), 3);
        ((CombatProcedureEngageTarget*)this)->SetMoveMode_00996e20(3);
        break;
    }
    case 1: {
        if (!actor_->IsAttacking())
        {
            if (combat7->GetStamp().GetElapsedTime() > 0.5 &&
                actor_->AttackTime() < *originalRuntimeFloatSetting378.Float())
            {
                actor_->UpdateAttackState();
            }
            else if ((*(CoverClock*)&m_waitTimer).FUN_008d7f80())
            {
                CoverRequest request;
                actor_->SetupPath(request, (*(CoverPoint*)m_afSecondVector), actor_->GetContainingCell(), actor_->GetWorld(), 0.0f, 0);
                if (!actor_->RequestPath(&request))
                {
                    ((CombatProcedureEngageTarget*)this)->Fail("Cannot setup path to Fire position");
                    return;
                }
                if (((CombatCoverPoint*)m_pCurrentCoverPoint)->CanRotate())
                    ((CoverProcedureCalls*)this)->ClearLook();
                ((CoverProcedureCalls*)this)->LookAt(targetTmp->GetAim(), 1);
                eState = COVER_STATE_MOVING_OUT;
                ((CombatProcedureEngageTarget*)this)->SetMoveMode_00996e20(canFire4 && active8 ? 2 : 1);
            }
        }
        break;
    }
    case 2: {
        if (actor_->PathFailed())
        {
            ((CombatProcedureEngageTarget*)this)->Fail(actor_->PathBuiltFailed() ? "Pathing failed while moving out" : "Path Building failed to move out");
            return;
        }
        if (actor_->PathFinished())
        {
            eState = COVER_STATE_WAITING_OUT_OF_COVER;
            ((CoverProcedureCalls*)this)->ClearLook();
            (*(CoverClock*)&m_waitingOutTimer).FUN_008d7f40(GetOutOfCoverWaitTime((((CoverManager*)m_pCombatController))->GetCurrentCombatStyle()));
        }
        break;
    }
    case 3: {
        CoverStamp stamp = combat7->GetStamp();
        if (stamp.AStarSearch_EvaluateValue_006a7f50() > (*(CoverClock*)&m_waitTimer).AStarSearch_EvaluateValue_006a7f50())
        {
            eState = COVER_STATE_FIRING_OUT_OF_COVER;
            (*(CoverClock*)&m_firingTimer).FUN_008d7f40((((CoverManager*)m_pCombatController))->GetCurrentCombatStyle()->GetRandomValue());
            (*(CoverClock*)&m_targetBlockedTimer).Reset();
        }
        else if ((*(CoverClock*)&m_waitingOutTimer).FUN_008d7f80())
        {
            combat7->End(0);
            ((CombatProcedureEngageTarget*)this)->Fail("Waited out of cover without firing");
            return;
        }
        else if ((*(CoverClock*)&m_waitingOutTimer).GetElapsedTime() > 2.0 && !combat7->IsGroup() && group7->HasLOS(targetTmp))
        {
            combat7->End(0);
            ((CombatProcedureEngageTarget*)this)->Fail("Waited out of cover and group member has LOS on target");
            return;
        }
        if (combat7->IsBlocked())
        {
            if (!(*(CoverClock*)&m_targetBlockedTimer).CombatTimer_IsSet())
                (*(CoverClock*)&m_targetBlockedTimer).FUN_008d7f40(2.0f);
            else if ((*(CoverClock*)&m_targetBlockedTimer).FUN_008d7f80())
            {
                combat7->End(1);
                ((CombatProcedureEngageTarget*)this)->Fail("Waited out of cover but was blocked");
                return;
            }
        }
        break;
    }
    case 4: {
        float attackTime_ = actor_->AttackTime();
        if (attackTime_ < *originalRuntimeFloatSetting379.Float() || actor_->IsAttacking() || (*(CoverClock*)&m_firingTimer).FUN_008d7f80())
        {
            CoverRequest request;
            actor_->SetupPath(request, (*(CoverPoint*)m_afFirstVector), actor_->GetContainingCell(), actor_->GetWorld(), 0.0f, 0);
            if (!actor_->RequestPath(&request))
            {
                ((CombatProcedureEngageTarget*)this)->Fail("Cannot setup path to move back to Cover position");
                return;
            }
            ((CombatProcedureEngageTarget*)this)->SetMoveMode_00996e20(canFire4 && active8 ? 2 : 1);
            eState = COVER_STATE_MOVING_IN;
        }
        break;
    }
    case 5: {
        if (actor_->PathFailed())
        {
            ((CombatProcedureEngageTarget*)this)->Fail(actor_->PathBuiltFailed() ? "Pathing failed while moving in" : "Path Building failed to move in");
            return;
        }
        if (actor_->PathFinished())
        {
            eState = COVER_STATE_WAITING_BEHIND_COVER;
            ((CoverProcedureCalls*)this)->ClearLook();
            ((CombatProcedureEngageTarget*)this)->SetMoveMode_00996e20(2);
            (*(CoverClock*)&m_waitTimer).FUN_008d7f40(GetCoverWaitTime((((CoverManager*)m_pCombatController))->GetCurrentCombatStyle()));
        }
        else
        {
            float dist9 = (actor_->GetPosition() - (*(CoverPoint*)m_afFirstVector)).FUN_004a7290();
            if (dist9 < 1024.0)
            {
                eState = COVER_STATE_MOVING_IN_AND_ROTATE;
                if (((CombatCoverPoint*)m_pCurrentCoverPoint)->CanRotate())
                    ((CoverProcedureCalls*)this)->LookAt((*(CoverPoint*)_pad1), 3);
                ((CombatProcedureEngageTarget*)this)->SetMoveMode_00996e20(1);
            }
        }
        break;
    }
    case 6: {
        if (actor_->PathFailed())
        {
            ((CombatProcedureEngageTarget*)this)->Fail(actor_->PathBuiltFailed() ? "Pathing failed while moving in and rotating"
                                           : "Path Building failed to move in and rotate");
            return;
        }
        if (actor_->PathFinished())
        {
            eState = COVER_STATE_WAITING_BEHIND_COVER;
            ((CombatProcedureEngageTarget*)this)->SetMoveMode_00996e20(2);
            (*(CoverClock*)&m_waitTimer).FUN_008d7f40(GetCoverWaitTime((((CoverManager*)m_pCombatController))->GetCurrentCombatStyle()));
        }
        break;
    }
    case 7: {
        if (evaluatedA && !changedVal)
        {
            CoverRequest request;
            actor_->SetupPath(request, (*(CoverPoint*)m_afFirstVector), actor_->GetContainingCell(), actor_->GetWorld(), 0.0f, 0);
            if (!actor_->RequestPath(&request))
            {
                ((CombatProcedureEngageTarget*)this)->Fail("Cannot setup path to move back to Cover position");
                return;
            }
            ((CombatProcedureEngageTarget*)this)->SetMoveMode_00996e20(canFire4 && active8 ? 2 : 1);
            eState = COVER_STATE_MOVING_IN;
        }
        else if ((*(CoverClock*)&m_holdingGroundTimer).FUN_008d7f80())
        {
            combat7->End(0);
            ((CombatProcedureEngageTarget*)this)->Fail(kCoverLOS);
            return;
        }
        else if ((*(CoverClock*)&m_holdingGroundTimer).GetElapsedTime() > (*(CoverClock*)&m_holdingGroundTimer).GetValue() / 4.0)
        {
            CoverPoint delta = targetTmp->GetPosition();
            CoverPoint targetPos = actor_->GetPosition();
            CoverPoint actorPos6 = targetPos - delta;
            if (actorPos6.FUN_004a7290() < 262144.0)
            {
                combat7->End(0);
                ((CombatProcedureEngageTarget*)this)->Fail(kCoverLOS);
            }
        }
        break;
    }
    }
}
