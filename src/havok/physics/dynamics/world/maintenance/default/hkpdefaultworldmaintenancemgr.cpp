
// src/havok/physics/dynamics/world/maintenance/default/hkpdefaultworldmaintenancemgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/maintenance/default/hkpdefaultworldmaintenancemgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpEntity.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkStepInfo.h"

struct S_00d0b250_RefObj
{
    virtual ~S_00d0b250_RefObj();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d0b250_RefObj() : m_sReferenceCount(1)
    {}
};

struct FUN_00d0b250 : S_00d0b250_RefObj
{
    float m_kPointA;
    float m_kPointB;
    FUN_00d0b250();
    virtual ~FUN_00d0b250();
};

// Initializes the object's two float members to 33.0 and 63.0 and sets the base reference count to 1.
// @fnv 0x00d0b250
FUN_00d0b250::FUN_00d0b250() : m_kPointA(33.0f), m_kPointB(63.0f)
{}

struct S_00d0b230_Dst
{
    int unk00, unk04, unk08, unk0C, unk10;
    float unk14;
    float unk18;
};

struct S_00d0b230_Arg
{
    int unk00, unk04;
    S_00d0b230_Dst* unk08;
};

struct FUN_00d0b230_class
{
    int unk00, unk04;
    float unk08;
    void SetDstFields(S_00d0b230_Arg* a);
};

// @fnv 0x00d0b230
void FUN_00d0b230_class::SetDstFields(S_00d0b230_Arg* a)
{
    S_00d0b230_Dst* pDst = a->unk08;
    pDst->unk14 = unk08;
    pDst->unk18 = unk08;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
#include "../../../../../../../include/hkpSimulation.h"
#include "../../../../../../../include/hkpSimulationIsland.h"
extern DWORD DAT_0126835c;
extern const char str_010cd380[];
extern const char str_010cd378[];
extern const char str_010cd36c[];
extern const char str_01076f38[];
extern void __cdecl hkpWorldOperationUtil_splitSimulationIslands(void*);
struct TraceBuffer
{
    int unk00;
    unsigned char* current;
    int unk08;
    unsigned char* end;
};
struct TraceEntry16
{
    volatile unsigned int type;
    volatile unsigned int timestamp;
    unsigned int unk08;
    volatile unsigned int detail;
};
struct TraceEntry12
{
    volatile unsigned int type;
    volatile unsigned int timestamp;
    unsigned int unk08;
};
struct FUN_00d0b280_cls
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    void hkpDefaultWorldMaintenanceMgr_performMaintenance(float* first, float* second);
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(float* first, float* second);
};
// Writes trace entries, calls FUN_00cb6f30(first), and if *second >= unk0c calls FUN_00d0b3e0(first, second) between further trace entries.
// @fnv 0x00d0b280
// src: HAVOK_LIB 0x00d0b280
void FUN_00d0b280_cls::hkpDefaultWorldMaintenanceMgr_performMaintenance(float* first, float* second)
{
    TraceBuffer* buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    unsigned char* current = buffer->current;
    if (current < buffer->end)
    {
        volatile TraceEntry16* entry = (volatile TraceEntry16*)current;
        entry->type = (unsigned int)str_010cd380;
        entry->detail = (unsigned int)str_010cd378;
        _ReadWriteBarrier();
        volatile unsigned int timestamp = (unsigned int)__rdtsc();
        entry->timestamp = timestamp;
        current += 16;
        buffer->current = current;
    }
    hkpWorldOperationUtil_splitSimulationIslands(first);
    if (*second >= unk0c)
    {
        buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
        current = buffer->current;
        if (current < buffer->end)
        {
            volatile TraceEntry12* entry = (volatile TraceEntry12*)current;
            entry->type = (unsigned int)str_010cd36c;
            _ReadWriteBarrier();
            volatile unsigned int timestamp = (unsigned int)__rdtsc();
            entry->timestamp = timestamp;
            current += 12;
            buffer->current = current;
        }
        hkpDefaultWorldMaintenanceMgr_resetWorldTime(first, second);
    }
    buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    current = buffer->current;
    if (current < buffer->end)
    {
        volatile TraceEntry12* entry = (volatile TraceEntry12*)current;
        entry->type = (unsigned int)str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int timestamp = (unsigned int)__rdtsc();
        entry->timestamp = timestamp;
        current += 12;
        buffer->current = current;
    }
}

extern DWORD DAT_0126835c;
extern const char str_010cd380[];
extern const char str_010cd36c[];
extern const char str_01076f38[];

struct FUN_00d0b350_cls
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(float* first, float* second);
    void TraceConditionalCall(float* first, float* second);
};
// Writes a trace entry, calls FUN_00d0b3e0(first, second) if *second >= unk0c, then writes a closing trace entry.
// @fnv 0x00d0b350
void FUN_00d0b350_cls::TraceConditionalCall(float* first, float* second)
{
    TraceBuffer* buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    unsigned char* current = buffer->current;
    if (current < buffer->end)
    {
        volatile TraceEntry16* entry = (volatile TraceEntry16*)current;
        entry->type = (unsigned int)str_010cd380;
        entry->detail = (unsigned int)str_010cd36c;
        _ReadWriteBarrier();
        volatile unsigned int timestamp = (unsigned int)__rdtsc();
        entry->timestamp = timestamp;
        current += 16;
        buffer->current = current;
    }
    if (*second >= unk0c)
        hkpDefaultWorldMaintenanceMgr_resetWorldTime(first, second);
    buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    current = buffer->current;
    if (current < buffer->end)
    {
        volatile TraceEntry12* entry = (volatile TraceEntry12*)current;
        entry->type = (unsigned int)str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int timestamp = (unsigned int)__rdtsc();
        entry->timestamp = timestamp;
        current += 12;
        buffer->current = current;
    }
}

struct CollisionAgentContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    hkStepInfo m_pStepInfo;
};

// The shared world header leaves the step info at 0x1D0 in its padding.
static __forceinline hkStepInfo& WorldStepInfo(hkpWorld* world)
{
    return *reinterpret_cast<hkStepInfo*>(world->pad1C8 + 8);
}

void __cdecl ProcessBlocks(hkpSimulationIsland* island, float oldTime, float newTime, CollisionAgentContext* input);

struct TimeRebaser
{
    int unk00;
    int unk04;
    float m_newTime;
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(hkpWorld* world, hkStepInfo& stepInfo);
};

// @fnv 0x00d0b3e0
// src: HAVOK_LIB 0x00d0b3e0
void TimeRebaser::hkpDefaultWorldMaintenanceMgr_resetWorldTime(hkpWorld* world, hkStepInfo& stepInfo)
{
    float deltaTime = stepInfo.m_fEndTime - stepInfo.m_uiStartTime;
    hkStepInfo& si = WorldStepInfo(world);
    const TimeRebaser* owner = this;
    si.m_uiStartTime = owner->m_newTime;
    si.m_fEndTime = owner->m_newTime + deltaTime;
    si.m_fTimeStep = deltaTime;
    si.m_fInverseDeltaTime = 1.0f / si.m_fTimeStep;

    float shift = WorldStepInfo(world).m_uiStartTime - stepInfo.m_uiStartTime;
    hkpSimulation* pSimulation = world->m_pSimulation;
    pSimulation->m_fElapsedSimulationTime += shift;
    pSimulation->m_fSimulationTime = WorldStepInfo(world).m_uiStartTime;
    if (pSimulation->m_fFrameMarkerTime != -1.0f)
    {
        world->m_pSimulation->m_fFrameMarkerTime = (float)(world->m_pSimulation->m_fFrameMarkerTime + shift);
    }

    for (int iIsland = 0; iIsland < world->m_kActiveSimulationIslands.m_iElementCount; iIsland++)
    {
        hkpSimulationIsland* island = static_cast<hkpSimulationIsland*>(world->m_kActiveSimulationIslands.m_data[iIsland]);
        for (int iActor = 0; iActor < island->m_iActorEntryCount; iActor++)
        {
            island->m_kActorEntries[iActor]->m_pMotionState.m_kMotionState.m_kSweptTransform.m_vCenterOfMass0.w += shift;
        }
        ProcessBlocks(island, stepInfo.m_fEndTime, WorldStepInfo(world).m_fEndTime, static_cast<CollisionAgentContext*>(world->m_pCollisionInput));
    }

    world->m_pSimulation->shiftTime(shift);
    stepInfo = WorldStepInfo(world);
    static_cast<CollisionAgentContext*>(world->m_pCollisionInput)->m_pStepInfo = WorldStepInfo(world);
}
