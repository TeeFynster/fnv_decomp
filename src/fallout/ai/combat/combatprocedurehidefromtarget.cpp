
// src/fallout/ai/combat/combatprocedurehidefromtarget.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedurehidefromtarget.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/CombatProcedureHideFromTarget.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/Setting.h"

// @fnv 0x009d60e0
// src: COMMUNITY 0x009d60e0
CombatProcedure::COMBAT_PROCEDURES CombatProcedureHideFromTarget::GetType_009d60e0()
{
    return HIDE_FROM_TARGET;
}

// @fnv 0x009d6120
CombatProcedureHideFromTarget::~CombatProcedureHideFromTarget()
{
}

// @fnv 0x009d6030
CombatProcedureHideFromTarget::CombatProcedureHideFromTarget(int aiValue, float afValue, bool abFlag1, bool abFlag2)
    : state(0), duration(afValue)
{
    m_38 = aiValue;
    keep = abFlag1;
    reset = abFlag2;
}

class Output
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void Printf(int x, int y, const char* fmt, ...);
    virtual void vf18();
};

// @fnv 0x009d6750
void CombatProcedureHideFromTarget::PrintState(Output* out, int x, int y)
{
    switch (m_uiContentCount)
    {
    case 0:
        out->Printf(x, y, "INITIALIZING");
        break;
    case 1:
        out->Printf(x, y, "MOVING_TO_COVER");
        break;
    case 2:
        out->Printf(x, y, "HIDING");
        out->Printf(x, y, "Hiding Timer: %.02f/%.02f", clock.FUN_00435e00(), clock.CombatTimer_GetTargetTime());
        break;
    }
}

struct FUN_009d6c80_shell
{
    FUN_009d6c80_shell* CombatController_GetCombatState();
};
struct FUN_0097fb60_shell
{
    unsigned int GetFieldAtE8();
};
unsigned int __fastcall GetFieldValue(void* object);
// Reads the hide target fields and restores the hiding handle from the trailing tag.
// @fnv 0x009d6900
void CombatProcedureHideFromTarget::LoadGame(BGSLoadFormBuffer* stream)
{
    CombatProcedure::LoadGame_00996ef0(stream);
    stream->LoadData(&state, 4);
    stream->LoadData(&duration, 4);
    clock.FUN_009a5f20(stream);
    stream->LoadData(&destination, 12);
    stream->LoadData(&rotation, 12);
    stream->LoadData(&keep, 1);
    stream->LoadData(&reset, 1);
    unsigned char tag = 0;
    stream->LoadData(&tag, 1);
    if (tag == 2)
    {
        m_38 = ((FUN_0097fb60_shell*)reinterpret_cast<FUN_009d6c80_shell*>(m_pCombatController)->CombatController_GetCombatState())->GetFieldAtE8();
    }
    else if (tag == 1)
    {
        m_38 = GetFieldValue(reinterpret_cast<FUN_009d6c80_shell*>(m_pCombatController)->CombatController_GetCombatState());
    }
}

struct Handle
{
    int GetFieldAtE8();
};

struct Owner04
{
    Handle* CombatController_GetCombatState();
};

// Serializes the procedure fields and writes a tag identifying the hiding handle.
// @fnv 0x009d6820
void CombatProcedureHideFromTarget::SaveGame(BGSSaveFormBuffer* apArchive)
{
    unsigned char tag;
    this->SaveToBuffer(apArchive);
    apArchive->FUN_00865e50(&state, 4, 0);
    apArchive->FUN_00865e50(&duration, 4, 0);
    clock.FUN_009a5eb0(apArchive);
    apArchive->FUN_00865e50(&destination, 12, 0);
    apArchive->FUN_00865e50(&rotation, 12, 0);
    apArchive->FUN_00865e50(&keep, 1, 0);
    apArchive->FUN_00865e50(&reset, 1, 0);
    tag = 0;
    if (unk38 != 0)
    {
        tag = (unk38 == reinterpret_cast<Owner04*>(m_pCombatController)->CombatController_GetCombatState()->GetFieldAtE8()) ? 2 : 1;
    }
    apArchive->FUN_00865e50(&tag, 1, 0);
}

struct WorldPos
{
    int a, b, c, d;
    double distance(const WorldPos&);
};
struct Request
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    Request();
    ~Request();
    void SetInitialPathHeading(float);
};
// Retained locally: include/ActorView.h lacks the bool path-build failure query at 0x008b3960.
// ActorView: unit-local view of Actor declaring its virtual slots by index (speed = slot 175) and the helper calls 0x009d6140 makes; not the shared Actor
struct ActorView
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual NiPoint3& position();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float speed(int);

    void* TESObjectREFR_GetWorldSpace();
    void* FUN_008d6f30();
    void setup(Request*, NiPoint3*, void*, void*, float, int);
    bool path(Request*);
    bool failed();
    bool failedMove();
    bool arrived();
    WorldPos world();
};
struct Hiding
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    bool active;
};
struct Cover
{
    unsigned char kind;
    int field4;
    WorldPos pos;
};
struct TimeValue
{
    int value;
    float elapsed();
};
struct StateStub
{
    bool find(Hiding*);
    void CombatState_ClearCoverLocation(int);
    Cover* cover();
    bool ready();
    void turn(bool);
    TimeValue timer();
};
struct OwnerStub
{
    ActorView* GetFieldBC();
    ActorView* target();
    StateStub* CombatController_GetCombatState();
};
float height(void*, int, int);
void location(OwnerStub*, Hiding*, NiPoint3*, NiPoint3*);
NiPoint3 angle(ActorView*, int);
float CombatTimer_GetTimer();
extern Setting originalRuntimeFloatSetting431;
// @fnv 0x009d6140
void CombatProcedureHideFromTarget::Update()
{
    ActorView* actor2 = reinterpret_cast<OwnerStub*>(m_pCombatController)->GetFieldBC();
    ActorView* enemy2 = reinterpret_cast<OwnerStub*>(m_pCombatController)->target();
    StateStub* target7 = reinterpret_cast<OwnerStub*>(m_pCombatController)->CombatController_GetCombatState();
    switch (state)
    {
    case 0: {
        bool found7 = target7->find(hiding);
        if (found7)
        {
            hiding->active = true;
            location(reinterpret_cast<OwnerStub*>(m_pCombatController), hiding, &destination, &rotation);
            rotation.z += height(enemy2 ? enemy2 : actor2, 2, 0);
        }
        else
        {
            destination = actor2->position();
            if (enemy2)
                rotation = angle(enemy2, 2);
        }
        NiPoint3 delta7 = actor2->position() - destination;
        if (found7 && static_cast<const NiPoint3&>(delta7).FUN_004a7290() > 625.0)
        {
            SetMoveMode_00996e20(3);
            Request request2;
            actor2->setup(&request2, &destination, actor2->FUN_008d6f30(), actor2->TESObjectREFR_GetWorldSpace(), 0.0f, 0);
            request2.SetInitialPathHeading(actor2->speed(0));
            if (!actor2->path(&request2))
            {
                CombatProcedure_SetFailed("Cannot setup path to hiding location");
                return;
            }
            state = 1;
        }
        else
        {
            clock.FUN_008d7f40(duration);
            if (enemy2)
                SetLookAtPoint(rotation, 3);
            SetMoveMode_00996e20(2);
            state = 2;
        }
        break;
    }
    case 1:
        SetMoveMode_00996e20(3);
        if (actor2->failed())
        {
            CombatProcedure_SetFailed(actor2->failedMove() ? "Pathing failed while moving to hiding location"
                                              : "Path Building failed to hiding location");
            return;
        }
        if (actor2->arrived())
        {
            clock.FUN_008d7f40(duration);
            SetLookAtPoint(rotation, 3);
            SetMoveMode_00996e20(2);
            state = 2;
        }
        break;
    case 2:
        if (clock.expired())
        {
            if (reset)
                target7->CombatState_ClearCoverLocation(0);
            SetState();
            return;
        }
        {
            bool shouldEnd3 = false;
            float time7 = clock.elapsed() + 1.0;
            if (time7 < CombatTimer_GetTimer())
                shouldEnd3 = true;
            if (shouldEnd3)
            {
                Cover* cover = target7->cover();
                if (cover && cover->kind == 1 && cover->pos.distance(actor2->world()) < 4096.0)
                    shouldEnd3 = false;
            }
            if (shouldEnd3)
            {
                if (target7->ready())
                {
                    if (!keep)
                    {
                        reinterpret_cast<OwnerStub*>(m_pCombatController)->CombatController_GetCombatState()->CombatState_ClearCoverLocation(1);
                        target7->turn(false);
                        SetState();
                        return;
                    }
                    if (enemy2)
                    {
                        WorldPos actorPosition = actor2->world();
                        WorldPos targetPosition = enemy2->world();
                        if (actorPosition.distance(targetPosition) <
                            *originalRuntimeFloatSetting431.Float() * *originalRuntimeFloatSetting431.Float())
                        {
                            reinterpret_cast<OwnerStub*>(m_pCombatController)->CombatController_GetCombatState()->CombatState_ClearCoverLocation(1);
                            target7->turn(false);
                            SetState();
                            return;
                        }
                    }
                }
                if (time7 < target7->timer().elapsed())
                {
                    reinterpret_cast<OwnerStub*>(m_pCombatController)->CombatController_GetCombatState()->CombatState_ClearCoverLocation(1);
                    target7->turn(false);
                    SetState();
                }
            }
        }
        break;
    }
}
