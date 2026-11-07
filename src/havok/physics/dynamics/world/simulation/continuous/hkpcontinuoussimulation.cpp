#include "../../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// Retain the unit's intrinsic type: the SDK's extra byte lanes change alias analysis.
#define _INCLUDED_MM2
// Exe 0x00d0c790 UpdateIslandMotionStates: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" void _ReadWriteBarrier(void);
#include <string.h>
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/NiPoint3.h"
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkSweptTransform.h"


inline void hkVector4::operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
inline hkVector4::hkVector4(const hkVector4& v) { m_vComponents = v.m_vComponents; }

// src/havok/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d0c6d0_Body {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    unsigned short m_a8;
};

struct S_00d0c6d0_Pair {
    int unk0;
    S_00d0c6d0_Body* m_apEntities[2];
};

struct S_00d0c6d0_Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_00d0c6d0_Pair* m_pair;
};

struct S_00d0c6d0_Entry {
    S_00d0c6d0_Obj* m_obj;
    int m_iWordAt04;
    int m_8;
};

struct S_00d0c6d0_EntryArray {
    S_00d0c6d0_Entry* m_data;
    int m_iElementCount;
};

struct S_00d0c6d0_ByteArray {
    unsigned char* m_data;
    int m_iElementCount;
};

// Scans entries from *idx onward and swaps each entry whose two pair bodies both map to byte 0x10 in table to the front, advancing *idx.
// @fnv 0x00d0c6d0
// src: HAVOK_LIB 0x00d0c6d0
void hkLs_toiActivateConstraintsLinkingActivatedEntities(S_00d0c6d0_EntryArray* aEntries, int* aIndex, S_00d0c6d0_ByteArray* table) {
    for (int i = *aIndex; i < aEntries->m_iElementCount; i++) {
        S_00d0c6d0_Body** b = aEntries->m_data[i].m_obj->m_pair->m_apEntities;
        if (table->m_data[b[0]->m_a8] == 0x10 && table->m_data[b[1]->m_a8] == 0x10) {
            int j = (*aIndex)++;
            S_00d0c6d0_Entry* data = aEntries->m_data;
            S_00d0c6d0_Entry tmp = data[j];
            data[j] = data[i];
            data[i] = tmp;
        }
    }
}

struct Base { void hkpSimulation_resetCollisionInformationForEntities(int*, int, int, unsigned int); };
struct Object : Base {
    void hkpContinuousSimulation_removeToiEventsOfEntities(int*, int);
    void hkpContinuousSimulation_removeToiEventsOfEntity(int);
    void ProcessEntries(int*, int, int, unsigned int);
};
// Calls FUN_00cfa430 with the arguments, then, when flags has bit 0 set, dispatches to FUN_00d0c290 for multiple entries or FUN_00d0c3e0 for a single entry.
// @fnv 0x00d0c970
void Object::ProcessEntries(int* entries, int count, int option, unsigned int flags) {
    hkpSimulation_resetCollisionInformationForEntities(entries, count, option, flags);
    if (flags & 1) {
        if (count != 1) hkpContinuousSimulation_removeToiEventsOfEntities(entries, count);
        else hkpContinuousSimulation_removeToiEventsOfEntity(*entries);
    }
}

extern int DAT_010cd45c;
struct Callback { virtual void Invoke(int value); };
struct Receiver {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Invoke(void* data, unsigned int size);
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FUN_00d0d0d0_cls {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    void* unk30;
    int unk34;
    int unk38;
    struct Subobject {
        int unk00; int unk04; int unk08;
        Callback* unk0c;
        void ProcessArgument(void* managerValue);
        void Object_DoNothing();
    } sub3c;
    void SetVtableAndProcessState_00cf86d0();
    void Destroy();
};
// @fnv 0x00d0d0d0
void FUN_00d0d0d0_cls::Destroy() {
    unk00 = (int)&DAT_010cd45c;
    if (sub3c.unk0c)
        sub3c.unk0c->Invoke(1);
    sub3c.ProcessArgument((void*)hkMemoryRouter_getInstance()->m_heap);
    sub3c.Object_DoNothing();
    hkMemoryRouter* manager = hkMemoryRouter_getInstance();
    Receiver* writer = (Receiver*)manager->m_heap;
    unk34 = 0;
    if ((unk38 & 0x80000000) != 0) goto skip_writer;
    writer->Invoke(unk30, (unk38 & 0x3fffffff) * 0x70);
skip_writer:
    unk30 = 0;
    unk38 = 0x80000000;
    SetVtableAndProcessState_00cf86d0();
}

void __cdecl InitAndDispatch();
struct S_00d0f2e0
{
    void* hkpSimulation_processAgentsOfEntities(void* a, void* b, void* c, void (__cdecl *pfnCallback)(), int iFlags);
    void* hkpContinuousSimulation_collideEntitiesNarrowPhaseContinuous(void* a, void* b, void* c);
};
// @fnv 0x00d0f2e0
// src: HAVOK_LIB 0x00d0f2e0
void* S_00d0f2e0::hkpContinuousSimulation_collideEntitiesNarrowPhaseContinuous(void* a, void* b, void* c)
{
    return hkpSimulation_processAgentsOfEntities(a, b, c, InitAndDispatch, 0);
}

struct TimeStep {float start,end,delta,inverse;};
struct World {
 TimeStep& time(){return *reinterpret_cast<TimeStep*>(reinterpret_cast<char*>(this)+80);}
};
struct Context {
 World*& world(){return *reinterpret_cast<World**>(reinterpret_cast<char*>(this)+120);}
 int& depth(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+148);}
 int& pending(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+140);}
 int& otherPending(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+144);}
 unsigned char& locked(){return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+156);}
 int& mode(){return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+164);}
 void FUN_00c91120();void UpdateFields_00c91140();
};
struct Body { unsigned char& motion(){return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+232);} void* state(){return reinterpret_cast<char*>(this)+240;} };
void __cdecl hkSweptTransformUtil_backStepMotionState(float,void*);
void __cdecl hkRigidMotionUtilStep(TimeStep*,Body**,int,int);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(World*,Body**,int);
struct Controller {
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void process(Body**,int,Context*,int);
 int flags,kind,capacity,mode;float start,end;
 void hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(Body**,int,Context*,int);
 void hkpContinuousSimulation_collideEntitiesNarrowPhaseContinuous(Body**,int,World*);
 void ProcessBodies(Body**,int,Context*,int);
};
// Runs the controller's update on bodies: sets a temporary time step, processes active bodies, applies optional passes, then restores the world time step.
// @fnv 0x00d0fed0
void Controller::ProcessBodies(Body** bodies,int count,Context* context,int flags) {
 ++context->depth();
 World* world=context->world();
 float begin=start,finish=end;
 __declspec(align(16)) TimeStep saved=world->time();
 TimeStep step;step.start=begin;step.end=finish;step.delta=finish-begin;step.inverse=step.delta==0?0.0f:1.0f/step.delta;
 world->time()=step;
 int active=flags&1;
 if(active) {
 for(int i=0;i<count;++i) if(bodies[i]->motion()!=5) hkSweptTransformUtil_backStepMotionState(start,bodies[i]->state());
 hkRigidMotionUtilStep(&step,bodies,count,224);
 hkpEntityAabbUtil_entityBatchRecalcAabb(context->world(),bodies,count);
 }
 process(bodies,count,context,1);
 if(flags&2)hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(bodies,count,context,0);
 if(flags&4)hkpContinuousSimulation_collideEntitiesNarrowPhaseContinuous(bodies,count,context->world());
 else if(active)process(bodies,count,context,2);
 if(--context->depth()==0&&!context->locked()) {
 if(context->pending())context->FUN_00c91120();
 if(context->mode()==1&&context->otherPending())context->UpdateFields_00c91140();
 }
 context->world()->time()=saved;
}

struct SpawnedObject
{
    unsigned int unkD4_dummy;
};

// @fnv 0x00d0bc60
bool *__cdecl IsLessByUnkD4(bool *pbResult, SpawnedObject *pObjectA, SpawnedObject *pObjectB)
{
    unsigned int uiValueA = *(unsigned int *)((char *)pObjectA + 0xd4);
    unsigned int uiValueB = *(unsigned int *)((char *)pObjectB + 0xd4);
    *pbResult = uiValueA < uiValueB;
    return pbResult;
}

struct Element {
    char pad[0xd4];
    unsigned int priority;
};

struct SubItem {
    char pad0[4];
    Element* volatile array[1];
    char pad1[0x12];
    unsigned char index;
};

struct Item {
    char pad[0x30];
    SubItem* volatile sub;
};

// Compares two items by their sub-item's current element priority, falling back to sub-item pointer order when priorities are equal.
// @fnv 0x00d0bc80
hkBool __cdecl CompareItemPriority(const Item* apItemA, const Item* apItemB) {
    SubItem* pSubA = apItemA->sub;
    SubItem* pSubB = apItemB->sub;
    if (pSubA->array[pSubA->index]->priority < pSubB->array[pSubB->index]->priority) {
        return true;
    }
    int iIndexB = pSubB->index;
    int iIndexA = pSubA->index;
    Element* pElemA = pSubA->array[iIndexA];
    Element* pElemB = pSubB->array[iIndexB];
    if (pElemA->priority == pElemB->priority) {
        return pSubA < pSubB;
    }
    return false;
}

struct D0BD00Entry {
    float m_uiCommandId;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct D0BD00Track {
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
    D0BD00Entry* m_entries;
    int m_iNumberOfEntries;
};

struct D0BD00Binding {
    int unk00;
    int unk04;
    D0BD00Track* m_pTrack;
};

struct D0BD00Controller {
    int unk00;
    int unk04;
    int unk08;
    D0BD00Binding* m_pBinding;

    void OffsetEntries(float offset);
};

// Adds offset to the first float of every entry in the track referenced by the controller's binding.
// @fnv 0x00d0bd00
void D0BD00Controller::OffsetEntries(float offset)
{
    D0BD00Track* track = m_pBinding->m_pTrack;
    for (int i = 0; i < track->m_iNumberOfEntries; i++)
        track->m_entries[i].m_uiCommandId = track->m_entries[i].m_uiCommandId + offset;
}

extern "C" double fabs(double);

struct FUN_00d0bd30_q {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    signed char m_1c;
};

struct FUN_00d0bd30_p {
    FUN_00d0bd30_q* m_00;
    int unk04;
    float m_08;
};

// Scans arr for the index whose fabs value times scale exceeds a threshold derived from p and tbl, returning that index or -1.
// @fnv 0x00d0bd30
// src: HAVOK_LIB 0x00d0bd30
int __cdecl hkLs_areVelocitiesOk(float scale, FUN_00d0bd30_p* pParams, float* pafValues, int aiCount, char** ppTable)
{
    FUN_00d0bd30_q* q = pParams->m_00;
    char* pRowBase = *ppTable + ((int)q->m_1c << 6);
    float best = *(float*)(pRowBase + 0x1c54) * pParams->m_08;
    int idx = -1;
    int i = 0;

    if (aiCount >= 4) {
        int iLimit = aiCount - 3;
        float* e = pafValues + 2;
        do {
            float v0 = (float)fabs(e[-2]) * scale;
            if (v0 > best) { best = v0; idx = i; }
            float v1 = (float)fabs(e[-1]) * scale;
            if (v1 > best) { best = v1; idx = i + 1; }
            float v2 = (float)fabs(e[0]) * scale;
            if (v2 > best) { best = v2; idx = i + 2; }
            float v3 = (float)fabs(e[1]) * scale;
            if (v3 > best) { best = v3; idx = i + 3; }
            e += 4;
            i += 4;
        } while (i < iLimit);
    }
    if (i < aiCount) {
        do {
            float v = (float)fabs(pafValues[i]) * scale;
            if (v > best) { best = v; idx = i; }
            ++i;
        } while (i < aiCount);
    }
    return idx;
}

// ---------------------------------------------------------------------------
// Stand-in types for the simulation object that owns the scope table.
//
//   this + 0x30 : ScopeEntry* m_30  - the table of 0x70-byte scope entries
//   this + 0x34 : int         m_34  - the number of live entries
//
// The scope table entry is 0x70 bytes wide; the copy performed when an entry
// is removed moves it in 8-byte chunks (14 of them), so the entry is viewed
// here as a run of ScopeChunk pairs.  The lookup key lives at +0x14.
// ---------------------------------------------------------------------------

struct ScopeChunk {
    unsigned int lo;
    unsigned int hi;
};

struct ScopeEntry {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_key14;
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
};

struct ScopeQuery {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

class FUN_00d0bfc0_cls {
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
    ScopeEntry* m_30;
    volatile int m_34;

    void RemoveMatchingEntries(ScopeQuery* q);
};

// Walk the scope table backwards; when the entry whose key matches the query
// is found it is dropped from the table and the last entry is moved into its
// slot (the table keeps its order otherwise).
// Scans the entry array backwards and removes every entry whose m_key14 equals q->m_08, compacting the array by moving the last entry into each removed slot.
// @fnv 0x00d0bfc0
void FUN_00d0bfc0_cls::RemoveMatchingEntries(ScopeQuery* pQuery) {
    int i = m_34 - 1;
    if (i < 0) {
        return;
    }
    do {
        if (m_30[i].m_key14 == pQuery->m_08) {
            --m_34;
            int n = m_34;
            if (n != i) {
                ScopeChunk* src = (ScopeChunk*)&m_30[n];
                ScopeChunk* dst = (ScopeChunk*)&m_30[i];
                for (int k = 0; k < 14; k++) {
                    dst[k] = src[k];
                }
            }
        }
        --i;
    } while (i >= 0);
}

struct SolverBody {
    hkVector4 m_unk00;
    hkVector4 m_unk10;
    hkVector4 m_unk20;
    hkVector4 m_unk30;
    hkVector4 m_unk40;
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

struct VelocityEntry {
    hkVector4 m_unk00;
    hkVector4 m_unk10;
};

struct Entity {
    int m_unk00;
    char m_auiShapeKeys[0xec];
    hkMotionState m_kMotionState;
};

struct EntityRaw {
    int m_unk00;
    int m_unk04[0x28];
    unsigned int m_solverIndex;
};

struct Island {
    int m_unk00[0x12];
    Entity** m_kActorEntries;
    int m_iActorEntryCount;
};

struct ByteArray {
    unsigned char* m_data;
};

struct SolverInfo {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    char* m_apEntities;
    int m_unk10;
    int m_unk14;
    char* m_velocities;
};

struct EntityB {
    char m_auiShapeKeys[0xa4];
    unsigned int m_solverIndex;
    char m_pAuxiliaryObject[0x108];
    hkVector4 m_unk1b0;
    hkVector4 m_unk1c0;
};

// @fnv 0x00d0c790
void UpdateIslandMotionStates(Island* island, ByteArray* flags, SolverInfo* info)
{
    for (int i = 0; i < island->m_iActorEntryCount; i++)
    {
        int f = flags->m_data[i];
        if (f == 1 || f == 2)
        {
            hkMotionState* ms = &island->m_kActorEntries[i]->m_kMotionState;
            reinterpret_cast<hkRotation*>(&ms->m_kMotionTransform)->hkRotation_set(ms->m_kSweptTransform.m_qRotation1);
            LocalM128 v = ms->m_kSweptTransform.m_vCenterOfMassLocal.m_vComponents;
            LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), ms->m_kMotionTransform.m_row1);
            LocalM128 r0 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), ms->m_kMotionTransform.m_row0);
            LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), ms->m_kMotionTransform.m_row2);
            ms->m_kMotionTransform.m_row3 = _mm_sub_ps(ms->m_kSweptTransform.m_vCenterOfMass1.m_vComponents, _mm_add_ps(_mm_add_ps(r1, r0), r2));
        }
        if (f == 8 || f == 2)
        {
            EntityB* e = (EntityB*)island->m_kActorEntries[i];
            unsigned int idx = e->m_solverIndex;
            // Keep the solver index load ahead of reads through the solver-info pointer.
            _ReadWriteBarrier();
            SolverBody* b = (SolverBody*)(info->m_apEntities + idx);
            b->m_kColumn0 = ((VelocityEntry*)info->m_velocities)[idx >> 7].m_unk10;
            e->m_unk1b0 = b->m_unk10;
            LocalM128 c0 = b->m_kColumn0.m_vComponents;
            LocalM128 c1 = b->m_kColumn1.m_vComponents;
            LocalM128 c2 = b->m_kColumn2.m_vComponents;
            LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
            LocalM128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
            c0 = _mm_movelh_ps(tmp, c2);
            c1 = _mm_movehl_ps(c0, tmp);
            c1 = _mm_shuffle_ps(c1, c2, 0xd4);
            c2 = ctmp;
            LocalM128 v = b->m_unk20.m_vComponents;
            LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1);
            LocalM128 r0 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), c0);
            LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2);
            e->m_unk1c0.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
        }
    }
}

struct ReportSink {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(const char* name, unsigned int value, int flag);
    virtual void v4();
    virtual void v5(int level, const char* name, void* base, unsigned int bytes, unsigned int data);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char m_10;
};

struct FilePool {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_getMemSize();
};

struct FUN_00d0c8d0_cls {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    void* m_30;
    unsigned int m_34;
    unsigned int m_38;
    FilePool m_3C;
    unsigned int m_48;

    void hkReferencedObject_calcContentStatistics(ReportSink* sink, void* data);
    void ReportMemoryUsage(ReportSink* a1, int a2);
};

unsigned int hkStatisticsCollector_getAllocatedSize(void* base, unsigned int bytes);
extern char DAT_01269514;

// @fnv 0x00d0c8d0
void FUN_00d0c8d0_cls::ReportMemoryUsage(ReportSink* pSink, int iUnused) {
    unsigned int flags = m_38;
    if ((flags & 0x80000000u) == 0 || pSink->m_10 != 0) {
        void* base = m_30;
        unsigned int count = flags & 0x3fffffff;
        unsigned int r = hkStatisticsCollector_getAllocatedSize(base, count * 0x70);
        pSink->v5(3, "toiEvents", m_30, m_34 * 0x70, r);
    }
    pSink->v3("toiResourceManager", m_48, 0);
    FilePool* pool = &m_3C;
    unsigned int id = pool->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_getMemSize();
    unsigned int r2 = hkStatisticsCollector_getAllocatedSize((void*)pool->m_00, id);
    pSink->v5(1, "entitiesNeedingPsiCollisionDetection", (void*)pool->m_00, id, r2);
    hkReferencedObject_calcContentStatistics(pSink, &DAT_01269514);
}

struct InfoBlock {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short m_06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char m_0a;
};

struct Child {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int v08();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    InfoBlock* m_28;
};

struct ItemObj {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Child* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char m_1c;
};

struct Entry {
    ItemObj* m_00;
    int m_04;
    int m_08;
};

struct FloatSrc {
    unsigned int unk00;
    unsigned int unk04;
    float m_08;
};

struct SrcA {
    FloatSrc* m_00;
    int m_04;
    unsigned int unk08;
    int m_0c;
};

struct HolderBase {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m_10;
};

void __cdecl ResizeAudioStream(void* alloc, NiPoint3* vec, unsigned int elemSize);
int __cdecl hkVector4_ProcessEntries_00d9f6f0(int a, int b, int c, int d, void* e);
int __cdecl hkLs_areVelocitiesOk(float f, Entry* entry, void* out, int a, int b);

// @fnv 0x00d0ceb0
unsigned char* __cdecl CollectMatchingEntries(unsigned char* pResult, SrcA* pSrc, NiPoint3* pVec, int a4, NiPoint3* dst)
{
    unsigned int auiBuffer[0x100];
    unsigned char result = 1;
    int i = 0;
    if (reinterpret_cast<int&>(pVec->y) > 0) {
        int iOffset = 0;
        do {
            Entry* e = (Entry*)((char*)reinterpret_cast<Entry*&>(pVec->x) + iOffset);
            if (e->m_00->m_1c == 5) {
                int r = hkVector4_ProcessEntries_00d9f6f0(pSrc->m_04, e->m_04, pSrc->m_0c, 0x100, auiBuffer);
                int ret = hkLs_areVelocitiesOk(pSrc->m_00->m_08, e, auiBuffer, r, a4);
                if (ret >= 0) {
                    if (dst == 0) {
                        *pResult = 0;
                        return pResult;
                    }
                    result = 0;
                    HolderBase* h = (HolderBase*)hkMemoryRouter_getInstance();
                    if (reinterpret_cast<int&>(dst->y) == (int)(reinterpret_cast<unsigned int&>(dst->z) & 0x3fffffff)) {
                        ResizeAudioStream(h->m_10, dst, 0xc);
                    }
                    Entry* pNewEntry = &reinterpret_cast<Entry*&>(dst->x)[reinterpret_cast<int&>(dst->y)];
                    reinterpret_cast<int&>(dst->y)++;
                    pNewEntry->m_00 = e->m_00;
                    if (e->m_00->m_0c->v08() == 0xb) {
                        Child* x = e->m_00->m_0c;
                        InfoBlock* y = x->m_28;
                        pNewEntry->m_04 = (int)((char*)y + 0x30 + (ret << 5));
                        pNewEntry->m_08 = (int)((char*)x->m_28 + 0x30 + (x->m_28->m_06 << 5) + (short)ret * x->m_28->m_0a);
                    } else {
                        pNewEntry->m_04 = 0;
                        pNewEntry->m_08 = 0;
                    }
                }
            }
            iOffset += 0xc;
            ++i;
        } while (i < reinterpret_cast<int&>(pVec->y));
    }
    *pResult = result;
    return pResult;
}

struct S_00d0d150_QualityInfo {
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
    char m_bUseContinuousPhysics;
    char unk35;
    char unk36;
    char unk37;
    int unk38;
    int unk3c;
};

struct S_00d0d150_Dispatcher {
    int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    int unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    int unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc;
    int unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c;
    int unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c;
    int unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc;
    int unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c;
    int unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c;
    int unk560, unk564, unk568, unk56c, unk570, unk574, unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c;
    int unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc;
    int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc;
    int unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c;
    int unk620, unk624, unk628, unk62c, unk630, unk634, unk638, unk63c;
    int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c;
    int unk660, unk664, unk668, unk66c, unk670, unk674, unk678, unk67c;
    int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c;
    int unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc;
    int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc;
    int unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc;
    int unk700, unk704, unk708, unk70c, unk710, unk714, unk718, unk71c;
    int unk720, unk724, unk728, unk72c, unk730, unk734, unk738, unk73c;
    int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c;
    int unk760, unk764, unk768, unk76c, unk770, unk774, unk778, unk77c;
    int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c;
    int unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc;
    int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc;
    int unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc;
    int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c;
    int unk820, unk824, unk828, unk82c, unk830, unk834, unk838, unk83c;
    int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c;
    int unk860, unk864, unk868, unk86c, unk870, unk874, unk878, unk87c;
    int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c;
    int unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc;
    int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc;
    int unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc;
    int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c;
    int unk920, unk924, unk928, unk92c, unk930, unk934, unk938, unk93c;
    int unk940, unk944, unk948, unk94c, unk950, unk954, unk958, unk95c;
    int unk960, unk964, unk968, unk96c, unk970, unk974, unk978, unk97c;
    int unk980, unk984, unk988, unk98c, unk990, unk994, unk998, unk99c;
    int unk9a0, unk9a4, unk9a8, unk9ac, unk9b0, unk9b4, unk9b8, unk9bc;
    int unk9c0, unk9c4, unk9c8, unk9cc, unk9d0, unk9d4, unk9d8, unk9dc;
    int unk9e0, unk9e4, unk9e8, unk9ec, unk9f0, unk9f4, unk9f8, unk9fc;
    int unka00, unka04, unka08, unka0c, unka10, unka14, unka18, unka1c;
    int unka20, unka24, unka28, unka2c, unka30, unka34, unka38, unka3c;
    int unka40, unka44, unka48, unka4c, unka50, unka54, unka58, unka5c;
    int unka60, unka64, unka68, unka6c, unka70, unka74, unka78, unka7c;
    int unka80, unka84, unka88, unka8c, unka90, unka94, unka98, unka9c;
    int unkaa0, unkaa4, unkaa8, unkaac, unkab0, unkab4, unkab8, unkabc;
    int unkac0, unkac4, unkac8, unkacc, unkad0, unkad4, unkad8, unkadc;
    int unkae0, unkae4, unkae8, unkaec, unkaf0, unkaf4, unkaf8, unkafc;
    int unkb00, unkb04, unkb08, unkb0c, unkb10, unkb14, unkb18, unkb1c;
    int unkb20, unkb24, unkb28, unkb2c, unkb30, unkb34, unkb38, unkb3c;
    int unkb40, unkb44, unkb48, unkb4c, unkb50, unkb54, unkb58, unkb5c;
    int unkb60, unkb64, unkb68, unkb6c, unkb70, unkb74, unkb78, unkb7c;
    int unkb80, unkb84, unkb88, unkb8c, unkb90, unkb94, unkb98, unkb9c;
    int unkba0, unkba4, unkba8, unkbac, unkbb0, unkbb4, unkbb8, unkbbc;
    int unkbc0, unkbc4, unkbc8, unkbcc, unkbd0, unkbd4, unkbd8, unkbdc;
    int unkbe0, unkbe4, unkbe8, unkbec, unkbf0, unkbf4, unkbf8, unkbfc;
    int unkc00, unkc04, unkc08, unkc0c, unkc10, unkc14, unkc18, unkc1c;
    int unkc20, unkc24, unkc28, unkc2c, unkc30, unkc34, unkc38, unkc3c;
    int unkc40, unkc44, unkc48, unkc4c, unkc50, unkc54, unkc58, unkc5c;
    int unkc60, unkc64, unkc68, unkc6c, unkc70, unkc74, unkc78, unkc7c;
    int unkc80, unkc84, unkc88, unkc8c, unkc90, unkc94, unkc98, unkc9c;
    int unkca0, unkca4, unkca8, unkcac, unkcb0, unkcb4, unkcb8, unkcbc;
    int unkcc0, unkcc4, unkcc8, unkccc, unkcd0, unkcd4, unkcd8, unkcdc;
    int unkce0, unkce4, unkce8, unkcec, unkcf0, unkcf4, unkcf8, unkcfc;
    int unkd00, unkd04, unkd08, unkd0c, unkd10, unkd14, unkd18, unkd1c;
    int unkd20, unkd24, unkd28, unkd2c, unkd30, unkd34, unkd38, unkd3c;
    int unkd40, unkd44, unkd48, unkd4c, unkd50, unkd54, unkd58, unkd5c;
    int unkd60, unkd64, unkd68, unkd6c, unkd70, unkd74, unkd78, unkd7c;
    int unkd80, unkd84, unkd88, unkd8c, unkd90, unkd94, unkd98, unkd9c;
    int unkda0, unkda4, unkda8, unkdac, unkdb0, unkdb4, unkdb8, unkdbc;
    int unkdc0, unkdc4, unkdc8, unkdcc, unkdd0, unkdd4, unkdd8, unkddc;
    int unkde0, unkde4, unkde8, unkdec, unkdf0, unkdf4, unkdf8, unkdfc;
    int unke00, unke04, unke08, unke0c, unke10, unke14, unke18, unke1c;
    int unke20, unke24, unke28, unke2c, unke30, unke34, unke38, unke3c;
    int unke40, unke44, unke48, unke4c, unke50, unke54, unke58, unke5c;
    int unke60, unke64, unke68, unke6c, unke70, unke74, unke78, unke7c;
    int unke80, unke84, unke88, unke8c, unke90, unke94, unke98, unke9c;
    int unkea0, unkea4, unkea8, unkeac, unkeb0, unkeb4, unkeb8, unkebc;
    int unkec0, unkec4, unkec8, unkecc, unked0, unked4, unked8, unkedc;
    int unkee0, unkee4, unkee8, unkeec, unkef0, unkef4, unkef8, unkefc;
    int unkf00, unkf04, unkf08, unkf0c, unkf10, unkf14, unkf18, unkf1c;
    int unkf20, unkf24, unkf28, unkf2c, unkf30, unkf34, unkf38, unkf3c;
    int unkf40, unkf44, unkf48, unkf4c, unkf50, unkf54, unkf58, unkf5c;
    int unkf60, unkf64, unkf68, unkf6c, unkf70, unkf74, unkf78, unkf7c;
    int unkf80, unkf84, unkf88, unkf8c, unkf90, unkf94, unkf98, unkf9c;
    int unkfa0, unkfa4, unkfa8, unkfac, unkfb0, unkfb4, unkfb8, unkfbc;
    int unkfc0, unkfc4, unkfc8, unkfcc, unkfd0, unkfd4, unkfd8, unkfdc;
    int unkfe0, unkfe4, unkfe8, unkfec, unkff0, unkff4, unkff8, unkffc;
    int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c;
    int unk1020, unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c;
    int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c;
    int unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c;
    int unk10a0, unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc;
    int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc;
    int unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc;
    int unk1100, unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c;
    int unk1120, unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c;
    int unk1140, unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c;
    int unk1160, unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c;
    int unk1180, unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c;
    int unk11a0, unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc;
    int unk11c0, unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc;
    int unk11e0, unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc;
    int unk1200, unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c;
    int unk1220, unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c;
    int unk1240, unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c;
    int unk1260, unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c;
    int unk1280, unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c;
    int unk12a0, unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc;
    int unk12c0, unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc;
    int unk12e0, unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc;
    int unk1300, unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c;
    int unk1320, unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c;
    int unk1340, unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c;
    int unk1360, unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c;
    int unk1380, unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c;
    int unk13a0, unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc;
    int unk13c0, unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc;
    int unk13e0, unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc;
    int unk1400, unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c;
    int unk1420, unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c;
    int unk1440, unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c;
    int unk1460, unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c;
    int unk1480, unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c;
    int unk14a0, unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc;
    int unk14c0, unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc;
    int unk14e0, unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc;
    int unk1500, unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c;
    int unk1520, unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c;
    int unk1540, unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c;
    int unk1560, unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c;
    int unk1580, unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c;
    int unk15a0, unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc;
    int unk15c0, unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc;
    int unk15e0, unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc;
    int unk1600, unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c;
    int unk1620, unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c;
    int unk1640, unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c;
    int unk1660, unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c;
    int unk1680, unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c;
    int unk16a0, unk16a4, unk16a8, unk16ac, unk16b0, unk16b4, unk16b8, unk16bc;
    int unk16c0, unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc;
    int unk16e0, unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc;
    int unk1700, unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c;
    int unk1720, unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c;
    int unk1740, unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c;
    int unk1760, unk1764, unk1768, unk176c, unk1770, unk1774, unk1778, unk177c;
    int unk1780, unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c;
    int unk17a0, unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc;
    int unk17c0, unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc;
    int unk17e0, unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc;
    int unk1800, unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c;
    int unk1820, unk1824, unk1828, unk182c, unk1830, unk1834, unk1838, unk183c;
    int unk1840, unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c;
    int unk1860, unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c;
    int unk1880, unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c;
    int unk18a0, unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc;
    int unk18c0, unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc;
    int unk18e0, unk18e4, unk18e8, unk18ec, unk18f0, unk18f4, unk18f8, unk18fc;
    int unk1900, unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c;
    int unk1920, unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c;
    int unk1940, unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c;
    int unk1960, unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c;
    int unk1980, unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c;
    int unk19a0, unk19a4, unk19a8, unk19ac, unk19b0, unk19b4, unk19b8, unk19bc;
    int unk19c0, unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc;
    int unk19e0, unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc;
    int unk1a00, unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c;
    int unk1a20, unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c;
    int unk1a40, unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c;
    int unk1a60, unk1a64, unk1a68, unk1a6c, unk1a70, unk1a74, unk1a78, unk1a7c;
    int unk1a80, unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c;
    int unk1aa0, unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc;
    int unk1ac0, unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc;
    int unk1ae0, unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc;
    int unk1b00, unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c;
    int unk1b20, unk1b24, unk1b28, unk1b2c, unk1b30, unk1b34, unk1b38, unk1b3c;
    int unk1b40, unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c;
    int unk1b60, unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c;
    int unk1b80, unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c;
    int unk1ba0, unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    int unk1bc0, unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc;
    int unk1be0, unk1be4, unk1be8, unk1bec, unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    S_00d0d150_QualityInfo m_pCollisionQualityInfo[8];
};

struct S_00d0d150_World {
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
    S_00d0d150_Dispatcher* m_pDispatcher;
};

struct S_00d0d150_Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset; }
};

struct S_00d0d150_Entity;

struct S_00d0d150_AgentNnEntry {
    int unk00;
    int unk04;
    void* m_pContactManager;
    signed char m_cAgentType;
    char unk0d;
    char unk0e;
    char unk0f;
    S_00d0d150_Collidable* m_kCollidable[2];
};

struct S_00d0d150_Properties {
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    int unk08;
    int unk0c;
    int unk10;
    S_00d0d150_Properties() { m_fAccumulatedImpulse = 0.0f; m_fImpulseLimit = 0.0f; }
    // A bulk event copy supplies every byte, including both impulse values.
    explicit S_00d0d150_Properties(int) {}
};

struct S_00d0d150_ToiEvent {
    float m_uiCommandId;
    float m_fSeparation;
    char m_cEventType;
    S_00d0d150_Entity* m_kActorEntries[2];
    void* m_pContactManager;
    S_00d0d150_Properties m_kProperties;
    int m_aiContactData[7];
    int unk48;
    int unk4c;
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    S_00d0d150_ToiEvent() {}
    // Preserve the original whole-event copy with the shared vector constructors.
    __forceinline S_00d0d150_ToiEvent(const S_00d0d150_ToiEvent& other)
        : m_kProperties(0) {
        memcpy(this, &other, sizeof(*this));
    }

};

struct S_00d0d150_ProcessCdPoint {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    int m_usContactPointId;
    int unk24;
    int unk28;
    int unk2c;
};

struct S_00d0d150_ToiInfo {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    float m_uiCommandId;
    float m_fSeparation;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00d0d150_Properties m_kProperties;
    int m_aiContactData[7];
};

struct S_00d0d150_CollisionOutput {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d0d150_ProcessCdPoint m_akContactPoints[256];
    S_00d0d150_ToiInfo m_fTimeOfImpact;
};

inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }

template <class T>
static __forceinline T* S_00d0d150_Array_expandByUnchecked(hkArrayBase<T>& self, int n);

template <class T>
static __forceinline T* S_00d0d150_Array_expandByUnchecked(hkArrayBase<T>& self, int n)
{
        int oldsize = self.m_iElementCount;
        self.m_iElementCount = oldsize + n;
        int numToConstruct = self.m_iElementCount - oldsize;
        T* p = self.m_data + oldsize;
        for (int i = 0; i < numToConstruct; ++i)
            new (p + i) T;
        return self.m_data + oldsize;
    }

struct S_00d0d150_ErrStream {
    int unk0;
    int unk4;
    int unk8;
    S_00d0d150_ErrStream(void* buf, int bufSize) throw();
    ~S_00d0d150_ErrStream() throw();
    S_00d0d150_ErrStream& operator<<(const char* s) throw();
};

struct S_00d0d150_Error {
    virtual void vfn0();
    virtual void vfn4();
    virtual void vfn8();
    virtual int message(int type, int id, const char* description, const char* file, int line) throw();
};

extern S_00d0d150_Error* DAT_01268360;

static __forceinline void S_00d0d150_memCpy4(void* dst, const void* src, int numWords)
{
    const int* s = static_cast<const int*>(src);
    int* d = static_cast<int*>(dst);
    for (int i = 0; i != numWords; i++)
        *(d++) = *(s++);
}

struct S_00d0d150 {
    int unk00;
    int unk04;
    int unk08;
    S_00d0d150_World* m_pOwningWorld;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    hkArrayBase<S_00d0d150_ToiEvent> m_kToiEventQueue;

    void QueueToiEvent(const S_00d0d150_CollisionOutput& result, const S_00d0d150_AgentNnEntry& entry) throw();
};

// @fnv 0x00d0d150
void S_00d0d150::QueueToiEvent(const S_00d0d150_CollisionOutput& result, const S_00d0d150_AgentNnEntry& entry) throw()
{
    if (m_kToiEventQueue.GetLogicalSize() == m_kToiEventQueue.getCapacity()) {
        // char assertBuf[512] in the Havok macro; ints here since the original has no /GS cookie
        __declspec(align(16)) unsigned int assertBuf[128];
        S_00d0d150_ErrStream ostr(assertBuf, sizeof(assertBuf));
        ostr << "Toi event queue full, consider using HK_COLLIDABLE_QUALITY_DEBRIS for some objects or increase hkpWorldCinfo::m_sizeOfToiEventQueue";
        DAT_01268360->message(1, 0xf0323454, reinterpret_cast<const char*>(assertBuf), ".\\World\\Simulation\\Continuous\\hkpContinuousSimulation.cpp", 1083);
        return;
    }

    S_00d0d150_ToiEvent& event = *S_00d0d150_Array_expandByUnchecked(m_kToiEventQueue, 1);

    event.m_uiCommandId = result.m_fTimeOfImpact.m_uiCommandId;
    event.m_cEventType = m_pOwningWorld->m_pDispatcher->m_pCollisionQualityInfo[entry.m_cAgentType].m_bUseContinuousPhysics;
    event.m_fSeparation = result.m_fTimeOfImpact.m_fSeparation;
    event.m_vContactPosition = result.m_fTimeOfImpact.m_vContactPosition;
    event.m_vSeparatingNormal = result.m_fTimeOfImpact.m_vSeparatingNormal;
    event.m_kActorEntries[0] = static_cast<S_00d0d150_Entity*>(entry.m_kCollidable[0]->getOwner());
    event.m_kActorEntries[1] = static_cast<S_00d0d150_Entity*>(entry.m_kCollidable[1]->getOwner());
    event.m_kProperties = result.m_fTimeOfImpact.m_kProperties;
    event.m_pContactManager = entry.m_pContactManager;
    S_00d0d150_memCpy4(event.m_aiContactData, result.m_fTimeOfImpact.m_aiContactData, sizeof(event.m_aiContactData) >> 2);
}

extern float DAT_0104da48;
extern double DAT_0104e138;
extern int DAT_01269200;

struct ThingVCallObject {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(int aiA, int aiB, void* apP, void* apS);
};

struct ThingX {
    int unk00;
    int unk04;
    ThingVCallObject* m_pObject;
    unsigned char m_bKind;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    int m_iA;
    int m_iB;
};

struct ThingEntry {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iValue;
};

struct ThingP {
    unsigned char* m_pTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iCached;

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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    ThingEntry* m_afEntries;
};

struct ThingBlock {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};

struct ThingHead {
    void* m_pSelf;
    int unk04;
    int unk08;
    int unk0c;
    int m_iSub;
    int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};

struct ThingFloatBlock {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    float m_fValue;
    int unk34; int unk38; int unk3c;
};

struct ThingFlagBlock {
    int m_iFlags;
    int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
};

struct ThingS {
    ThingHead m_pFirstNode;
    ThingBlock m_blk0040;
    ThingBlock m_blk0080;
    ThingBlock m_blk00C0;
    ThingBlock m_blk0100;
    ThingBlock m_blk0140;
    ThingBlock m_blk0180;
    ThingBlock m_blk01C0;
    ThingBlock m_blk0200;
    ThingBlock m_blk0240;
    ThingBlock m_blk0280;
    ThingBlock m_blk02C0;
    ThingBlock m_blk0300;
    ThingBlock m_blk0340;
    ThingBlock m_blk0380;
    ThingBlock m_blk03C0;
    ThingBlock m_blk0400;
    ThingBlock m_blk0440;
    ThingBlock m_blk0480;
    ThingBlock m_blk04C0;
    ThingBlock m_blk0500;
    ThingBlock m_blk0540;
    ThingBlock m_blk0580;
    ThingBlock m_blk05C0;
    ThingBlock m_blk0600;
    ThingBlock m_blk0640;
    ThingBlock m_blk0680;
    ThingBlock m_blk06C0;
    ThingBlock m_blk0700;
    ThingBlock m_blk0740;
    ThingBlock m_blk0780;
    ThingBlock m_blk07C0;
    ThingBlock m_blk0800;
    ThingBlock m_blk0840;
    ThingBlock m_blk0880;
    ThingBlock m_blk08C0;
    ThingBlock m_blk0900;
    ThingBlock m_blk0940;
    ThingBlock m_blk0980;
    ThingBlock m_blk09C0;
    ThingBlock m_blk0A00;
    ThingBlock m_blk0A40;
    ThingBlock m_blk0A80;
    ThingBlock m_blk0AC0;
    ThingBlock m_blk0B00;
    ThingBlock m_blk0B40;
    ThingBlock m_blk0B80;
    ThingBlock m_blk0BC0;
    ThingBlock m_blk0C00;
    ThingBlock m_blk0C40;
    ThingBlock m_blk0C80;
    ThingBlock m_blk0CC0;
    ThingBlock m_blk0D00;
    ThingBlock m_blk0D40;
    ThingBlock m_blk0D80;
    ThingBlock m_blk0DC0;
    ThingBlock m_blk0E00;
    ThingBlock m_blk0E40;
    ThingBlock m_blk0E80;
    ThingBlock m_blk0EC0;
    ThingBlock m_blk0F00;
    ThingBlock m_blk0F40;
    ThingBlock m_blk0F80;
    ThingBlock m_blk0FC0;
    ThingBlock m_blk1000;
    ThingBlock m_blk1040;
    ThingBlock m_blk1080;
    ThingBlock m_blk10C0;
    ThingBlock m_blk1100;
    ThingBlock m_blk1140;
    ThingBlock m_blk1180;
    ThingBlock m_blk11C0;
    ThingBlock m_blk1200;
    ThingBlock m_blk1240;
    ThingBlock m_blk1280;
    ThingBlock m_blk12C0;
    ThingBlock m_blk1300;
    ThingBlock m_blk1340;
    ThingBlock m_blk1380;
    ThingBlock m_blk13C0;
    ThingBlock m_blk1400;
    ThingBlock m_blk1440;
    ThingBlock m_blk1480;
    ThingBlock m_blk14C0;
    ThingBlock m_blk1500;
    ThingBlock m_blk1540;
    ThingBlock m_blk1580;
    ThingBlock m_blk15C0;
    ThingBlock m_blk1600;
    ThingBlock m_blk1640;
    ThingBlock m_blk1680;
    ThingBlock m_blk16C0;
    ThingBlock m_blk1700;
    ThingBlock m_blk1740;
    ThingBlock m_blk1780;
    ThingBlock m_blk17C0;
    ThingBlock m_blk1800;
    ThingBlock m_blk1840;
    ThingBlock m_blk1880;
    ThingBlock m_blk18C0;
    ThingBlock m_blk1900;
    ThingBlock m_blk1940;
    ThingBlock m_blk1980;
    ThingBlock m_blk19C0;
    ThingBlock m_blk1A00;
    ThingBlock m_blk1A40;
    ThingBlock m_blk1A80;
    ThingBlock m_blk1AC0;
    ThingBlock m_blk1B00;
    ThingBlock m_blk1B40;
    ThingBlock m_blk1B80;
    ThingBlock m_blk1BC0;
    ThingBlock m_blk1C00;
    ThingBlock m_blk1C40;
    ThingBlock m_blk1C80;
    ThingBlock m_blk1CC0;
    ThingBlock m_blk1D00;
    ThingBlock m_blk1D40;
    ThingBlock m_blk1D80;
    ThingBlock m_blk1DC0;
    ThingBlock m_blk1E00;
    ThingBlock m_blk1E40;
    ThingBlock m_blk1E80;
    ThingBlock m_blk1EC0;
    ThingBlock m_blk1F00;
    ThingBlock m_blk1F40;
    ThingBlock m_blk1F80;
    ThingBlock m_blk1FC0;
    ThingBlock m_blk2000;
    ThingBlock m_blk2040;
    ThingBlock m_blk2080;
    ThingBlock m_blk20C0;
    ThingBlock m_blk2100;
    ThingBlock m_blk2140;
    ThingBlock m_blk2180;
    ThingBlock m_blk21C0;
    ThingBlock m_blk2200;
    ThingBlock m_blk2240;
    ThingBlock m_blk2280;
    ThingBlock m_blk22C0;
    ThingBlock m_blk2300;
    ThingBlock m_blk2340;
    ThingBlock m_blk2380;
    ThingBlock m_blk23C0;
    ThingBlock m_blk2400;
    ThingBlock m_blk2440;
    ThingBlock m_blk2480;
    ThingBlock m_blk24C0;
    ThingBlock m_blk2500;
    ThingBlock m_blk2540;
    ThingBlock m_blk2580;
    ThingBlock m_blk25C0;
    ThingBlock m_blk2600;
    ThingBlock m_blk2640;
    ThingBlock m_blk2680;
    ThingBlock m_blk26C0;
    ThingBlock m_blk2700;
    ThingBlock m_blk2740;
    ThingBlock m_blk2780;
    ThingBlock m_blk27C0;
    ThingBlock m_blk2800;
    ThingBlock m_blk2840;
    ThingBlock m_blk2880;
    ThingBlock m_blk28C0;
    ThingBlock m_blk2900;
    ThingBlock m_blk2940;
    ThingBlock m_blk2980;
    ThingBlock m_blk29C0;
    ThingBlock m_blk2A00;
    ThingBlock m_blk2A40;
    ThingBlock m_blk2A80;
    ThingBlock m_blk2AC0;
    ThingBlock m_blk2B00;
    ThingBlock m_blk2B40;
    ThingBlock m_blk2B80;
    ThingBlock m_blk2BC0;
    ThingBlock m_blk2C00;
    ThingBlock m_blk2C40;
    ThingBlock m_blk2C80;
    ThingBlock m_blk2CC0;
    ThingBlock m_blk2D00;
    ThingBlock m_blk2D40;
    ThingBlock m_blk2D80;
    ThingBlock m_blk2DC0;
    ThingBlock m_blk2E00;
    ThingBlock m_blk2E40;
    ThingBlock m_blk2E80;
    ThingBlock m_blk2EC0;
    ThingBlock m_blk2F00;
    ThingBlock m_blk2F40;
    ThingBlock m_blk2F80;
    ThingBlock m_blk2FC0;
    ThingFloatBlock m_blk3000;
    ThingBlock m_blk3040;
    ThingFlagBlock m_blk3080;
};

struct FUN_00d0daa0_cls {
    int unk00;

    void QueueToiEvent(ThingS* apS, ThingX* apX);
    void InitAndDispatch(ThingX* apX, ThingP* apP, ThingS* apS);
};

void __cdecl hkAgentNnMachine_ProcessAgent(ThingX* apX, ThingP* apP, ThingS* apS, int aiValue);

// @fnv 0x00d0daa0
void FUN_00d0daa0_cls::InitAndDispatch(ThingX* apX, ThingP* apP, ThingS* apS)
{
    apS->m_blk3000.m_fValue = DAT_0104da48;
    apS->m_blk3080.m_iFlags = 0;
    apS->m_pFirstNode.m_pSelf = &apS->m_pFirstNode.m_iSub;
    unsigned char bKind = apX->m_bKind;
    apP->m_afEntries = (ThingEntry*)(apP->m_pTable + 0x1c20 + (((int)(char)bKind) << 6));
    apP->m_iCached = apP->m_afEntries->m_iValue;
    hkAgentNnMachine_ProcessAgent(apX, apP, apS, (int)apX->m_pObject);
    if (DAT_01269200 != 1) {
        if (apS->m_pFirstNode.m_pSelf != &apS->m_pFirstNode.m_iSub) {
            apX->m_pObject->v18(apX->m_iA, apX->m_iB, apP, apS);
        }
        if (apS->m_blk3000.m_fValue != DAT_0104e138) {
            QueueToiEvent(apS, apX);
        }
    }
}

// Stand-in for the object at ms+0x20; its member is the thiscall helper.
struct SlotObj_b2089
{
    void hkVector4_setRotatedDir(void* dst, void* src);
};

struct World_b2089
{
    int unk00;
    int unk04;
    int unk08;
    char* m_0c;     // +0x0c: base of per-entry records
    int unk10;
    int unk14;
    char* m_18;     // +0x18: vector table
};

struct EntryList_b2089
{
    void** m_pData; // +0x00
    int m_iArrayLength;   // +0x04
};

// @fnv 0x00d0bf30
// src: GUESS 0x00d0bf30 (confidence: low)
void hkVector4_setRotatedDir_ProcessEntries_00d0bf30(World_b2089* world, EntryList_b2089* pEntries)
{
    for (int i = 0; i < pEntries->m_iArrayLength; ++i)
    {
        char* e = (char*)pEntries->m_pData[i];
        char* ms = world->m_0c + *(unsigned int*)(e + 0xa4);

        *(LocalM128*)(ms + 0x10) = *(LocalM128*)(e + 0x1b0);

        __declspec(align(16)) unsigned int saved[4];
        unsigned int* src = (unsigned int*)(ms + 0x50);
        saved[0] = src[0];
        saved[1] = src[1];
        saved[2] = src[2];
        saved[3] = src[3];

        *(LocalM128*)(ms + 0x50) = *(LocalM128*)(world->m_18 + ((*(unsigned int*)(e + 0xa4) >> 7) * 32) + 0x10);

        SlotObj_b2089* slot = (SlotObj_b2089*)(ms + 0x20);
        slot->hkVector4_setRotatedDir(ms + 0x50, e + 0x1c0);

        *(LocalM128*)(ms + 0x50) = *(LocalM128*)saved;
    }
}

extern float DAT_010c7948[];
struct CollisionMotion {
    int unk00, unk04;
    unsigned char type;
};
struct CollisionBody {
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
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    CollisionMotion motion;
    hkBool hkpEntity_isFixedOrKeyframed();
};
struct CollisionManager {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int constraint;
};
struct CollisionProperties {
    float impulse, solverData;
    int unk08;
    unsigned char friction, restitution, maximumImpulse;
    unsigned char unk0f;
    int unk10;
};
struct CollisionEvent {
    float time, separatingVelocity;
    int flags;
    CollisionBody* bodyA;
    CollisionBody* bodyB;
    CollisionManager* manager;
    CollisionProperties properties;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c;
    hkVector4 position, normal;
};
struct CollisionParameters {
    float friction, restitution, maximumImpulse;
    float separatingVelocity, extraVelocity, deltaTime;
    bool limitBreached;
};
struct CollisionOutput {
    float impulse, velocityA, velocityB;
};
struct __declspec(align(16)) CollisionStateData {
    unsigned short type, count;
    int* constraint;
    CollisionProperties* properties;
    hkVector4* point;
};
struct CollisionQueue {
    CollisionBody** data;
    int size;
    int cap;
    __forceinline void add(CollisionBody* b) {
        CollisionBody** p = data + size;
        __assume(p != 0);
        *p = b;
        ++size;
    }
};
void __cdecl hkpCollision_ProcessBodyResponse(hkVector4*, float, CollisionParameters*, CollisionMotion*, CollisionMotion*, CollisionManager*, CollisionOutput*);
void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(void*, CollisionStateData*, int);
// @fnv 0x00d0c480
void __cdecl ProcessCollisionEvent(void* context, CollisionEvent* event, float deltaTime, CollisionQueue* queue)
{
    CollisionBody* bodyA = event->bodyA;
    CollisionBody* bodyB = event->bodyB;
    CollisionMotion* motionA = &bodyA->motion;
    CollisionMotion* motionB = &bodyB->motion;
    CollisionParameters params;
    params.separatingVelocity = event->separatingVelocity;
    params.extraVelocity = 0.1f;
    params.deltaTime = deltaTime;
    params.friction = DAT_010c7948[event->properties.friction];
    params.restitution = event->properties.restitution * (1.0 / 128.0);
    params.maximumImpulse = event->properties.maximumImpulse == 0 ? DAT_0104da48 : DAT_010c7948[event->properties.maximumImpulse];
    CollisionOutput result;
    hkpCollision_ProcessBodyResponse(&event->position, event->time, &params, motionA, motionB, event->manager, &result);
    if (params.limitBreached) {
        CollisionStateData callbackEvent;
        callbackEvent.type = 2;
        callbackEvent.count = 1;
        callbackEvent.point = &event->position;
        callbackEvent.constraint = &event->manager->constraint;
        callbackEvent.properties = &event->properties;
        hkpWorldCallbackUtil_fireContactImpulseLimitBreached(context, &callbackEvent, 1);
        return;
    }
    if (result.velocityA < 0.0f && result.velocityB < 0.0f) {
        if (bodyA->motion.type != 5 && bodyA->motion.type != 4) queue->add(bodyA);
        if (bodyB->motion.type != 5 && bodyB->motion.type != 4) queue->add(bodyB);
    } else if (result.velocityA < 0.0f && result.velocityB >= 0.0f) {
        if (bodyA->motion.type != 5 && bodyA->motion.type != 4) queue->add(bodyA);
        else queue->add(bodyB);
    } else if (result.velocityA >= 0.0f && result.velocityB < 0.0f) {
        if (bodyB->hkpEntity_isFixedOrKeyframed()) {
            queue->add(bodyA);
        } else {
            queue->add(bodyB);
        }
    } else {
        if (bodyA->motion.type != 5 && bodyA->motion.type != 4) {
            if (bodyB->motion.type == 5 || bodyB->motion.type == 4 || !(result.velocityB < result.velocityA)) {
                queue->add(bodyA);
                return;
            }
        }
        queue->add(bodyB);
    }
}

// expanded integer AABB into thread-stack local arrays, add them to the 3-axis sweep, then remove duplicate pairs.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" void _mm_prefetch(char const* p, int hint);

extern unsigned long DAT_0126835c;
extern char DAT_010cc624[];  // "LtBroadPhase"
extern char DAT_010cd3e8[];  // "StGatherAabbs"
extern char DAT_010cc5fc[];  // "St3AxisSweep"
extern char DAT_010cc5f0[];  // "StRemoveDup"
extern char DAT_01076f38[];  // "lt"

struct MonitorStreamD0 {
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_capacityEnd;
};
struct TimerCommandD0 {
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
};
struct TimerListCommandD0 {
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
    const char* m_firstSub;
};

struct BoundingVolumeDataD0 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_ucUnknownByte;
};
struct AabbUint32D0 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_expansionMaxXYZ;
};
struct CollidableD0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_kBroadPhaseHandle;
    int unk28;
    int unk2c;
    BoundingVolumeDataD0 m_kBoundingVolumeData;
};
struct PairArrayD0 {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct BroadPhaseD0 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual void UpdatePairs(int** handles, AabbUint32D0* aabbs, int numObjects, PairArrayD0& newPairs, PairArrayD0& delPairs);
    int unk04;
    int unk08;
    int unk0c;
    int m_pWorldLock;
    void lockImplementation();
    void unlockImplementation();
    void lock() { if (m_pWorldLock) lockImplementation(); }
    void unlock() { if (m_pWorldLock) unlockImplementation(); }
};
struct CollisionInputD0;
struct WorldD0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    BroadPhaseD0* m_pJobSemaphore;
    int unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    CollisionInputD0* m_pCollisionInput;
};
static inline void UncompressExpandedAabbD0(const BoundingVolumeDataD0& in, AabbUint32D0& out)
{
    int shift = in.m_ucExpansionShift;
    unsigned int m0 = in.m_kMinimumCorner[0] - (in.m_ucExpansionMin[0] << shift);
    unsigned int m1 = in.m_kMinimumCorner[1] - (in.m_ucExpansionMin[1] << shift);
    unsigned int m2 = in.m_kMinimumCorner[2] - (in.m_ucExpansionMin[2] << shift);
    out.m_kMinimumCorner[0] = m0;
    out.m_kMinimumCorner[1] = m1;
    out.m_kMinimumCorner[2] = m2;
    unsigned int x0 = in.m_kMaximumCorner[0] + (in.m_ucExpansionMax[0] << shift);
    unsigned int x1 = in.m_kMaximumCorner[1] + (in.m_ucExpansionMax[1] << shift);
    unsigned int x2 = in.m_kMaximumCorner[2] + (in.m_ucExpansionMax[2] << shift);
    out.m_kMaximumCorner[0] = x0;
    out.m_kMaximumCorner[1] = x1;
    out.m_kMaximumCorner[2] = x2;
}
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(CollisionInputD0* input, CollidableD0** collidables, int numCollidables);
void __cdecl hkpTypedBroadPhaseDispatcher_removeDuplicates(PairArrayD0& newPairs, PairArrayD0& delPairs);

static inline void TimerBeginListD0(const char* name, const char* firstSub)
{
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerListCommandD0* h = (TimerListCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        h->m_firstSub = firstSub;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void TimerCommandD0Write(const char* name)
{
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

static inline void* AllocateStackD0(int nbytes)
{
    hkMemoryRouter* mem = hkMemoryRouter_getInstance();
    void* p = mem->m_stack.m_next.m_storage;
    mem->m_stack.m_next.m_storage = static_cast<char*>(mem->m_stack.m_next.m_storage) + ((nbytes + 127) & ~127);
    return p;
}
static inline void FreeStackD0(void* p)
{
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage = p;
}
// Builds handles and uncompressed AABBs for each collidable, runs the broad-phase pair update under lock, then processes new and deleted pairs.
// @fnv 0x00d0c030
void __stdcall UpdateBroadPhasePairs(CollidableD0** collidables, int numCollidables, WorldD0* world,
    PairArrayD0& newPairs, PairArrayD0& delPairs)
{
    if (!numCollidables)
        return;
    TimerBeginListD0(DAT_010cc624, DAT_010cd3e8);

    AabbUint32D0* aabbs = (AabbUint32D0*)AllocateStackD0(numCollidables * sizeof(AabbUint32D0));
    int** handles = (int**)AllocateStackD0(numCollidables * sizeof(int*));

    {
        CollidableD0** pCollidableCursor = collidables;
        int** h = handles;
        AabbUint32D0* pAabbCursor = aabbs;
        for (int i = numCollidables - 1; i >= 0; i--)
        {
            CollidableD0* collidable = pCollidableCursor[0];
            if (i >= 4)
                _mm_prefetch((const char*)pCollidableCursor[4] + 16, 0);
            *h = &collidable->m_kBroadPhaseHandle;
            BoundingVolumeDataD0& rBoundingVolume = collidable->m_kBoundingVolumeData;
            if (rBoundingVolume.m_kMinimumCorner[0] > rBoundingVolume.m_kMaximumCorner[0])
                hkpEntityAabbUtil_entityBatchRecalcAabb(world->m_pCollisionInput, &collidable, 1);
            UncompressExpandedAabbD0(rBoundingVolume, *pAabbCursor);
            pCollidableCursor++;
            h++;
            pAabbCursor++;
        }
    }

    TimerCommandD0Write(DAT_010cc5fc);
    world->m_pJobSemaphore->lock();
    world->m_pJobSemaphore->UpdatePairs(handles, aabbs, numCollidables, newPairs, delPairs);
    world->m_pJobSemaphore->unlock();

    FreeStackD0(handles);
    FreeStackD0(aabbs);

    if (newPairs.m_iElementCount + delPairs.m_iElementCount > 0)
    {
        TimerCommandD0Write(DAT_010cc5f0);
        hkpTypedBroadPhaseDispatcher_removeDuplicates(newPairs, delPairs);
    }
    TimerCommandD0Write(DAT_01076f38);
}

// Havok-style query: collect candidate pairs from the source into a temporary array, skip entries
// below the level or already flagged (>= 8), mark unflagged owners once (callback), and append every
// accepted object to the output array.
struct HeapL {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
// The original array allocator accessor is nonthrowing; hkMemoryRouter::get has no such declaration.
hkMemoryRouter* GetMemoryRouter() throw();
void ReserveMoreL(HeapL& alloc, void* arr, int elemSize) throw();
template <typename T> inline void ConstructWithCopyL(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }

template <class T>
static __forceinline void ArrL_destroy(hkArrayBase<T>& self);

template <class T>
static __forceinline void ArrL__clearAndDeallocate(hkArrayBase<T>& self, HeapL& alloc);

template <class T>
static __forceinline void ArrL__pushBack(hkArrayBase<T>& self, HeapL& alloc, const T& t);

template <class T>
static __forceinline void ArrL_AddBack(hkArrayBase<T>& self, const T& t);

template <class T>
static __forceinline void ArrL_destroy(hkArrayBase<T>& self)
{ ArrL__clearAndDeallocate(self, reinterpret_cast<HeapL&>(GetMemoryRouter()->heap())); }

template <class T>
static __forceinline void ArrL__clearAndDeallocate(hkArrayBase<T>& self, HeapL& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, self.getCapacity() * sizeof(T));
    }

template <class T>
static __forceinline void ArrL__pushBack(hkArrayBase<T>& self, HeapL& alloc, const T& t)
{
        if (self.m_iElementCount == self.getCapacity())
            ReserveMoreL(alloc, (&self), sizeof(T));
        ConstructWithCopyL<T>(self.m_data + self.m_iElementCount, 1, t);
        self.m_iElementCount++;
    }

template <class T>
static __forceinline void ArrL_AddBack(hkArrayBase<T>& self, const T& t)
{ ArrL__pushBack(self, reinterpret_cast<HeapL&>(GetMemoryRouter()->heap()), t); }

struct ArrLPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { ArrL_destroy(self); }
};

struct ObjL {
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_iValueAtOffset04;
};
struct MotionL {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40;
};
struct OwnerL {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    unsigned short m_uiEdgeIndex;
    unsigned short m_aa;
    int m_ac, m_b0, m_b4, m_b8, m_bc, m_c0, m_c4, m_c8, m_cc, m_d0, m_d4, m_d8, m_dc, m_e0, m_e4;
    unsigned char m_type;
    unsigned char m_e9, m_ea, m_eb;
    int m_ec;
    MotionL m_pMotionState;
};
struct NodeL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    OwnerL* getOwner() { return (OwnerL*)((char*)this + m_iOwnerOffset); }
};
struct ItemPairL {
    ObjL* m_obj;
    NodeL* m_node;
};
struct ListL {
    void Collect(hkArray<ItemPairL, ArrLPolicy>* out) throw();
};
struct SrcL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ListL m_kNode;
};
void OnFirstVisitL(void* target, float fValue, void* arg) throw();

inline bool IsSaturatedL(OwnerL* owner, unsigned char** ppFlags)
{
    return owner->m_type != 5 && (*ppFlags)[owner->m_uiEdgeIndex] >= 8;
}
inline void VisitL(OwnerL* owner, unsigned char** ppFlags, float fValue)
{
    if (owner->m_type != 5)
    {
        if ((*ppFlags)[owner->m_uiEdgeIndex] == 0)
        {
            (*ppFlags)[owner->m_uiEdgeIndex] = 1;
            MotionL* motion = &owner->m_pMotionState;
            OnFirstVisitL(&motion->m_40, fValue, motion);
        }
    }
}

// Collects item pairs from src, skips those below level or with saturated owners, visits the rest and appends their objects to out.
// @fnv 0x00d0d2c0
void CollectUnsaturatedObjects(SrcL* pSource, int level, float fValue, unsigned char** ppFlags, hkArray<ObjL*, ArrLPolicy>* out)
{
    hkArray<ItemPairL, ArrLPolicy> itemPairs;
    pSource->m_kNode.Collect(&itemPairs);
    for (int i = 0; i < itemPairs.m_iElementCount; i++)
    {
        ItemPairL& it = itemPairs[i];
        if (level > it.m_obj->m_iValueAtOffset04)
            continue;
        OwnerL* owner = it.m_node->getOwner();
        if (IsSaturatedL(owner, ppFlags))
            continue;
        VisitL(owner, ppFlags, fValue);
        ArrL_AddBack((*(out)), it.m_obj);
    }
}

// Empty function body that takes three int arguments and does nothing.
// @fnv 0x00d0bc50
// src: COMMUNITY 0x00d0bc50
void __stdcall nullsub_66(int, int, int) {
}

// @fnv 0x00d0bcf0
// src: COMMUNITY 0x00d0bcf0
void __stdcall nullsub_67(int a)
{
}

struct MotionBody {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc;
    int unke0; int unke4;
    unsigned char m_type;
};
struct BodyPair {
    int unk0;
    MotionBody* m_apEntities[2];
};
struct PairOwner {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    BodyPair* m_pair;
};
struct PairEntry {
    PairOwner* m_pOwnerObject;
    int m_iWordAt04;
    int m_8;
};
struct PairEntryArray {
    PairEntry* m_data;
    int m_iElementCount;
};
template <class T> inline void SwapT(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
// Moves pairs whose bodies have type 4 or 5 to the front of the array, tracking the count in numFixed.
// @fnv 0x00d0be80
void PartitionMotionPairs(PairEntryArray* apEntryArray, int* apiFixedCount, int index)
{
    for (index = apEntryArray->m_iElementCount - index; index < apEntryArray->m_iElementCount; index++) {
        MotionBody** bodies = apEntryArray->m_data[index].m_pOwnerObject->m_pair->m_apEntities;
        if (bodies[0]->m_type == 5 || bodies[0]->m_type == 4 || bodies[1]->m_type == 5 || bodies[1]->m_type == 4) {
            int slot = *apiFixedCount;
            *apiFixedCount = slot + 1;
            SwapT(apEntryArray->m_data[slot], apEntryArray->m_data[index]);
        }
    }
}

extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
// FUN_00d0ef40 v1 - Havok collide step: monitor ticks, reverse vcall loop, two ctx array loops
extern char DAT_010cc64c[]; // TtCollide
extern char DAT_010cc634[]; // TtIslandPostCollideCb
extern char DAT_010c41f8[]; // Et
extern int DAT_01269200;

struct Param { int m_00; int m_04; float m_08; float m_0c;
    void set(const Param& o) { *this = o; } };
struct Sub78 {
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
    Param m_50;
};
struct BodyA {
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
    int m_cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned char m_e8; unsigned char m_e9; unsigned char m_ea; unsigned char m_eb;
    int unk0ec;
};
class VObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void vcall8(int, void*);
};
struct Elem70 {
    int m_00; int m_04; int m_08;
    BodyA* m_0c; BodyA* m_10; VObj* m_14;
    int m_18;
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
};
struct BodyL {
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
    void* m_48; int m_4c;
};
struct Arr28 { BodyL** m_data; int m_uiItemCount; };
struct Sub1E0 {
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
    float m_10c; float m_110; int m_114;
    void setTimes(float scale, const Param& step) { m_10c = scale * step.m_08; m_110 = (float)m_114 * step.m_0c; }
};
struct Ctx {
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
    Arr28 m_aiIndexedValues;
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
    Sub78* m_78;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int m_8c; int m_90; int m_94; int m_98;
    unsigned char m_9c; unsigned char m_9d; unsigned char m_9e; unsigned char m_9f;
    int m_a0; int m_a4;
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
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int m_198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    Param m_1d0;
    Sub1E0 m_1e0;
    int m_2f8; int m_2fc; float m_300;
    Sub1E0* solverInfo() { return &m_1e0; }
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
void __cdecl hkpWorldCallbackUtil_fireIslandPostCollideCallback(Ctx*, BodyL*, Param*);
template<int Mode> static inline void TickWrite(const char* name, volatile unsigned int& t)
{
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        if (Mode == 1) _ReadBarrier();
        if (Mode == 2) _WriteBarrier();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void ReleaseCtx(Ctx* c)
{
    --c->m_94;
    if (c->m_94 != 0) return;
    if (c->m_9c != 0) return;
    if (c->m_8c) c->FUN_00c91120();
    if (c->m_a4 != 1) return;
    if (c->m_90) c->UpdateFields_00c91140();
}
struct ThisFull {
    int m_00; int m_04; int m_08;
    Ctx* m_0c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int m_28; int m_2c;
    Elem70* m_30; int m_34;
    void hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(void*, int, Ctx*, int);
    void hkpContinuousSimulation_collideIslandNarrowPhaseContinuous(BodyL*, void*);
};

union StepArg { Param* step; volatile unsigned int tick; };
// Calls vcall8 on queued elements, stores the step parameters in the context, then loops items calling FUN_00d0d3f0, then FUN_00d0d8b0 and FUN_00d01650.
// @fnv 0x00d0ef40
// src: HAVOK_LIB 0x00d0ef40
void __fastcall hkpContinuousSimulation_collideInternal(ThisFull* th, void* edx_unused, StepArg arg)
{
    volatile unsigned int tA;
    TickWrite<0>(DAT_010cc64c, tA);
    if (th->m_28 != 0) {
        for (int i = th->m_34 - 1; i >= 0; --i) {
            Elem70* e = &th->m_30[i];
            BodyA* b = e->m_0c;
            int a1;
            if (b->m_e8 == 5) a1 = e->m_10->m_cc;
            else a1 = b->m_cc;
            _ReadWriteBarrier();
            e->m_14->vcall8(a1, &e->m_18);
        }
        th->m_34 = 0;
    }
    _ReadWriteBarrier();
    Param* p = arg.step;
    static_cast<volatile ThisFull*>(th)->m_0c->m_1d0.set(*p);
    th->m_0c->m_78->m_50.set(*p);
    { union SolverPointer { Ctx* c; Sub1E0* s; }; SolverPointer uSolverPtr; uSolverPtr.c = th->m_0c; double delta=uSolverPtr.c->m_300 * p->m_08; uSolverPtr.s = &uSolverPtr.c->m_1e0; uSolverPtr.s->m_10c = delta; uSolverPtr.s->m_110 = (float)uSolverPtr.s->m_114 * p->m_0c; }
    th->m_0c->m_94++;
    Arr28& arr = th->m_0c->m_aiIndexedValues;
    for (int i = 0; i < arr.m_uiItemCount; ++i) {
        BodyL* b = arr.m_data[i];
        th->hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(b->m_48, b->m_4c, th->m_0c, 0);
        if (DAT_01269200 == 1) { ReleaseCtx(th->m_0c); TickWrite<1>(DAT_010c41f8, arg.tick); return; }
    }
    ReleaseCtx(th->m_0c);
    th->m_0c->m_94++;
    Arr28& arr2 = th->m_0c->m_aiIndexedValues;
    for (int i = 0; i < arr2.m_uiItemCount; ++i) {
        BodyL* b = arr2.m_data[i];
        th->hkpContinuousSimulation_collideIslandNarrowPhaseContinuous(b, th->m_0c->m_78);
        if (DAT_01269200 == 1) { ReleaseCtx(th->m_0c); TickWrite<2>(DAT_010c41f8, arg.tick); return; }
        if (th->m_0c->m_198 != 0) {
            TickWrite<0>(DAT_010cc634, arg.tick);
            hkpWorldCallbackUtil_fireIslandPostCollideCallback(th->m_0c, b, p);
            TickWrite<0>(DAT_010c41f8, tA);
        }
    }
    ReleaseCtx(th->m_0c);
    TickWrite<0>(DAT_010c41f8, arg.tick);
}

struct Tmp {
    int unk00;
    int unk04;
    int unk08;
    void EnsureCapacity(void* a, int n);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* a, int id, int z);
    int FindSlot(void* o);
    void ProcessArgument(void* a);
    void Object_DoNothing();
};

struct IFace {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int v, void* p);
};

struct Obj {
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
};

struct D0C290Entry {
    int unk00;
    int unk04;
    int unk08;
    Obj* m_0c;
    Obj* m_10;
    IFace* m_14;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

class FUN_00d0c290_cls {
public:
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
    D0C290Entry* m_30;
    int m_34;
    void hkpContinuousSimulation_removeToiEventsOfEntities(int* ids, int n);
};

struct D0C290Pair { unsigned int lo, hi; };
template <int N>
static __forceinline void memCpyOneAlignedD0C2(void* dst, const void* src)
{
    int i = 0;
    do
    {
        ((D0C290Pair*)dst)[i] = ((const D0C290Pair*)src)[i];
    } while (++i < N / 8);
}

// @fnv 0x00d0c290
// src: HAVOK_LIB 0x00d0c290
void FUN_00d0c290_cls::hkpContinuousSimulation_removeToiEventsOfEntities(int* ids, int n) {
    FUN_00d0c290_cls* self = this;
    if (self->m_34 != 0) {
        Tmp t;
        t.unk00 = 0;
        t.unk04 = 0;
        t.unk08 = -1;
        hkMemoryRouter* pManager = hkMemoryRouter_getInstance();
        t.EnsureCapacity((void*)pManager->m_heap, n);
        for (int i = 0; i < n; ++i) {
            int id = ids[i];
            hkMemoryRouter* h = hkMemoryRouter_getInstance();
            t.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert((void*)h->m_heap, id, 0);
        }
        for (int k = 0; k < self->m_34; k++) {
            D0C290Entry& e = self->m_30[k];
            int lo = t.FindSlot(e.m_0c);
            int hi = t.FindSlot(e.m_10);
            if (lo > t.unk08 && hi > t.unk08) {
                continue;
            }
            int v;
            if (e.m_0c->unkE8 != 5) {
                v = e.m_0c->unkCC;
            } else {
                v = e.m_10->unkCC;
            }
            e.m_14->v08(v, &e.unk18);
            self->m_34--;
            if (self->m_34 != k) {
                memCpyOneAlignedD0C2<sizeof(D0C290Entry)>(&self->m_30[k], &self->m_30[self->m_34]);
            }
            k--;
        }
        hkMemoryRouter* h = hkMemoryRouter_getInstance();
        t.ProcessArgument((void*)h->m_heap);
        t.Object_DoNothing();
    }
}

namespace fnv_00d0c3e0 {
struct Tmp {
    int unk00;
    int unk04;
    int unk08;
    void EnsureCapacity(void* a, int n);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* a, int id, int z);
    int FindSlot(void* o);
    void ProcessArgument(void* a);
    void Object_DoNothing();
};

struct IFace {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int v, void* p);
};

struct Obj {
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
};

struct D0C290Entry {
    int unk00;
    int unk04;
    int unk08;
    Obj* m_0c;
    Obj* m_10;
    IFace* m_14;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

class D0C3E0Owner {
public:
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
    D0C290Entry* m_30;
    int m_34;
    void hkpContinuousSimulation_removeToiEventsOfEntity(void* obj);
};
struct D0C290Pair { unsigned int lo, hi; };
template <int N>
static __forceinline void memCpyOneAlignedD0C2(void* dst, const void* src)
{
    int i = 0;
    do
    {
        ((D0C290Pair*)dst)[i] = ((const D0C290Pair*)src)[i];
    } while (++i < N / 8);
}

// Removes every entry in m_30 whose m_0c or m_10 equals obj, calling m_14->v08 first and moving the last entry into the gap.
// @fnv 0x00d0c3e0
// src: HAVOK_LIB 0x00d0c3e0
void D0C3E0Owner::hkpContinuousSimulation_removeToiEventsOfEntity(void* obj)
{
    for (int k = 0; k < m_34; k++) {
        D0C290Entry& e = m_30[k];
        if ((void*)m_30[k].m_0c == obj || (void*)m_30[k].m_10 == obj) {
            int v;
            if (e.m_0c->unkE8 != 5) {
                v = e.m_0c->unkCC;
            } else {
                v = e.m_10->unkCC;
            }
            e.m_14->v08(v, &e.unk18);
            m_34--;
            if (m_34 != k) {
                memCpyOneAlignedD0C2<sizeof(D0C290Entry)>(&m_30[k], &m_30[m_34]);
            }
            k--;
        }
    }
}
}  // namespace fnv_00d0c3e0

extern const char str_010cd440[];
extern const char str_010c41f8[];

struct __declspec(align(16)) S00d0c9c0_Ctx {
    void* m_pData;
    int m_iValue;
    int unk08;
    int unk0c;
    ThingBlock m_kStorage[192];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301c;
    int unk3020;
    int unk3024;
    int unk3028;
    int unk302c;
    float m_fValue;
    int unk3034;
    int unk3038;
    int unk303c;
    int unk3040;
    int unk3044;
    int unk3048;
    int unk304c;
    float m_fCoefficientA;
    float m_fB;
    int unk3058;
    int unk305c;
    int unk3060;
    int unk3064;
    int unk3068;
    int unk306c;
    int unk3070;
    int unk3074;
    int unk3078;
    int unk307c;
    int m_iFlags;
    int unk3084;
    int unk3088;
    int unk308c;
};

// Iterates apEntries, builds a context struct, configures apP table offsets, calls FUN_00cfedd0, and invokes v18 on the object when m_pData changed.
// @fnv 0x00d0c9c0
// src: HAVOK_LIB 0x00d0c9c0
void __stdcall hkpContinuousSimulation_processAgentNnEntries(ThingX** apEntries, int aiCount, ThingP* apP, int aiValue, bool abAlt)
{
    TimerCommandD0Write(str_010cd440);
    for (int i = 0; i < aiCount; ++i) {
        S00d0c9c0_Ctx s;
        ThingX* x = apEntries[i];
        s.m_fCoefficientA = 0.0f;
        s.m_fB = 0.0f;
        s.m_fValue = DAT_0104da48;
        s.m_iValue = aiValue;
        s.m_pData = s.m_kStorage;
        s.m_iFlags = 0;
        unsigned char* table = apP->m_pTable;
        if (abAlt)
            apP->m_afEntries = (ThingEntry*)(table + 0x1de0);
        else
            apP->m_afEntries = (ThingEntry*)(table + (signed char)x->m_bKind * 0x40 + 0x1c20);
        apP->m_iCached = *(int*)(table + (signed char)x->m_bKind * 0x40 + 0x1c30);
        hkAgentNnMachine_ProcessAgent(x, apP, (ThingS*)&s, (int)x->m_pObject);
        if (s.m_pData != s.m_kStorage)
            x->m_pObject->v18(x->m_iA, x->m_iB, apP, &s);
    }
    TimerCommandD0Write(str_010c41f8);
}

typedef unsigned long DWORD;

// The original's timer helpers (expansions of Havok's timer macros), kept as members of a unit-local view so the
// inlined code keeps its shape.
struct ProfRec_hkpcontinuoussimulation : hkMonitorStream::TimerCommand
{
    void stamp();
};
__forceinline void ProfRec_hkpcontinuoussimulation::stamp() {
    DWORD value;
    __asm {
        rdtsc
        mov dword ptr[value], eax
    }
    m_time0=value;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

struct S_00d0e210_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d0e210_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d0e210_Timer(const char* name)
{
    S_00d0e210_MonitorStream* s = (S_00d0e210_MonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand) {
        S_00d0e210_TimerCommand* h = (S_00d0e210_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00d0e210_Heap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

template <class T>
static __forceinline void S_00d0e210_Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void S_00d0e210_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00d0e210_Heap& alloc) throw();

template <class T>
static __forceinline void S_00d0e210_Array_destroy(hkArrayBase<T>& self) throw()
{ S_00d0e210_Array__clearAndDeallocate(self, reinterpret_cast<S_00d0e210_Heap&>(hkMemoryRouter_getInstance()->heap())); }

template <class T>
static __forceinline void S_00d0e210_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00d0e210_Heap& alloc) throw()
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct S_00d0e210_ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { S_00d0e210_Array_destroy(self); }
};

template <typename T, int N>
struct S_00d0e210_Inplace : hkArray<T, S_00d0e210_ArrayPolicy> {
    T m_kStorage[N];
    S_00d0e210_Inplace() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};

struct S_00d0e210_Island;
struct S_00d0e210_Motion { int unk00; };
struct S_00d0e210_Entity {
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
    short unk28;
    unsigned char unk2A;
    unsigned char unk2B;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    S_00d0e210_Island* unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
    unsigned char unkE9;
    unsigned char unkEA;
    unsigned char unkEB;
    int unkEC;
    S_00d0e210_Motion unkF0;
};

typedef S_00d0e210_Inplace<S_00d0e210_Entity*, 2> S_00d0e210_PtrArray;
struct S_00d0e210_ToiEvent;

struct S_00d0e210_ContactMgr {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void removeToi(S_00d0e210_Island* island, int* props);
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void simulate(S_00d0e210_ToiEvent& event, float dt, S_00d0e210_PtrArray& entities);
};

struct S_00d0e210_Pair { int a; int b; };

struct S_00d0e210_ToiEvent {
    float m_uiCommandId;
    int unk04;
    int unk08;
    S_00d0e210_Entity* m_kActorEntries[2];
    S_00d0e210_ContactMgr* m_pContactManager;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    S_00d0e210_Island* island()
    {
        S_00d0e210_Entity* x = m_kActorEntries[0];
        if (x->unkE8 == 5)
            x = m_kActorEntries[1];
        return x->unkCC;
    }
    S_00d0e210_Island* islandOf()
    {
        if (m_kActorEntries[0]->unkE8 != 5)
            return m_kActorEntries[0]->unkCC;
        return m_kActorEntries[1]->unkCC;
    }
    void copyFrom(const S_00d0e210_ToiEvent& o)
    {
        const S_00d0e210_Pair* s = (const S_00d0e210_Pair*)&o;
        S_00d0e210_Pair* d = (S_00d0e210_Pair*)this;
        for (int i = 0; i != 14; i++)
            d[i] = s[i];
    }
};

struct S_00d0e210_ToiArray : hkArray<S_00d0e210_ToiEvent, S_00d0e210_ArrayPolicy> {
    void removeAt(int i) throw()
    {
        m_iElementCount--;
        if (m_iElementCount != i)
            m_data[i].copyFrom(m_data[m_iElementCount]);
    }
};

struct S_00d0e210_World {
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk98;
    unsigned char m_bBlockExecutingPendingOperations;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    int unkA0;
    int unkA4;
    void FUN_00c91120();
    void UpdateFields_00c91140();
    void lockCriticalOperations() throw() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations() throw()
    {
        if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount != 0)
                FUN_00c91120();
            if (unkA4 == 1 && m_iQueuedOperationCount != 0)
                UpdateFields_00c91140();
        }
    }
};

struct S_00d0e210_StepInfo {
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

void __cdecl UpdateRotationInterpolation(float time, S_00d0e210_Motion* motion) throw();
void __cdecl hkpWorldAgentUtil_invalidateTim(S_00d0e210_Entity* entity, int arg) throw();

struct S_00d0e210_Sim {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void activate(S_00d0e210_Entity** entities, int numEntities, int arg, int* out);
    int unk04;
    int unk08;
    S_00d0e210_World* m_pOwningWorld;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00d0e210_ToiArray m_kToiEventQueue;
    int unk3C;
    void hkpContinuousSimulation_handleSimpleToi(S_00d0e210_StepInfo* info, S_00d0e210_ToiEvent& event, int unused, float dt) throw();
};

// Locks the world, simulates the event via its contact manager, drops queued TOI events for its type-3 entities, then activates those entities.
// @fnv 0x00d0e210
// src: HAVOK_LIB 0x00d0e210
void S_00d0e210_Sim::hkpContinuousSimulation_handleSimpleToi(S_00d0e210_StepInfo* info, S_00d0e210_ToiEvent& event, int unused, float dt) throw()
{
    union { unsigned int tick; S_00d0e210_Entity** p; } sh;
    {
        S_00d0e210_MonitorStream* s = (S_00d0e210_MonitorStream*)TlsGetValue(DAT_0126835c);
        if (s->m_kRayEnd < s->m_pCurrentCommand) {
            S_00d0e210_TimerCommand* h = (S_00d0e210_TimerCommand*)s->m_kRayEnd;
            h->m_pCommandName = "TtSimpleTOI";
            _ReadWriteBarrier();
            *(volatile unsigned int*)&sh.tick = (unsigned int)__rdtsc();
            h->m_uiStartTicks = *(volatile unsigned int*)&sh.tick;
            s->m_kRayEnd = (char*)(h + 1);
        }
    }
    m_pOwningWorld->lockCriticalOperations();
    {
        S_00d0e210_PtrArray movedEntities;
        event.m_pContactManager->simulate(event, dt, movedEntities);
        S_00d0e210_PtrArray active;
        sh.p = event.m_kActorEntries;
        for (int i = 0; i < 2; i++, sh.p++) {
            S_00d0e210_Entity* e = *sh.p;
            if (e->unk2A == 3) {
                UpdateRotationInterpolation(event.m_uiCommandId, &e->unkF0);
                hkpWorldAgentUtil_invalidateTim(e, info->unk78);
                for (int j = m_kToiEventQueue.m_iElementCount - 1; j >= 0; j--) {
                    S_00d0e210_ToiEvent& te = m_kToiEventQueue[j];
                    if (te.m_kActorEntries[0] == e || te.m_kActorEntries[1] == e) {
                        te.m_pContactManager->removeToi(te.islandOf(), &te.unk18);
                        m_kToiEventQueue.removeAt(j);
                    }
                }
                ConstructWithCopyL(active.m_data + active.m_iElementCount, 1, e); ++active.m_iElementCount;
            }
        }
        event.m_pContactManager->removeToi(event.islandOf(), &event.unk18);
        if (active.m_iElementCount != 0)
            activate(active.m_data, active.m_iElementCount, info->unk78, &unk3C);
    }
    m_pOwningWorld->unlockCriticalOperations();
    S_00d0e210_Timer("Et");
}

struct D0FE00TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D0FE00MonitorStream {
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
};

extern DWORD g_D0FE00TlsIndex;

__forceinline D0FE00MonitorStream& D0FE00GetMonitorStream()
{
    return *(D0FE00MonitorStream*)TlsGetValue(g_D0FE00TlsIndex);
}

__forceinline void D0FE00TimerBegin(const char* name)
{
    D0FE00MonitorStream& mStream = D0FE00GetMonitorStream();
    if (mStream.memoryAvailable()) {
        D0FE00TimerCommand* h = (D0FE00TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime();
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D0FE00World {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int m_postSimulationCallbacks;
};

void __cdecl hkpWorldCallbackUtil_firePostSimulationCallback(D0FE00World* world);
extern int g_D0FE00SimulationState;
extern const char g_D0FE00TimerPostSimCb[];
extern const char g_D0FE00TimerEnd[];

struct D0FE00Simulation {
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void markEntities(int value, int* list);
    int unk04;
    int unk08;
    D0FE00World* m_pOwningWorld;
    int unk10;
    float m_fElapsedSimulationTime;
    int unk18;
    int unk1C;
    float m_frameMarkerTime;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int m_entitiesToActivate;
    int m_iActorEntryCount;

    int hkpContinuousSimulation_advanceTimeInternal();
    int hkpContinuousSimulation_advanceTime();
};

// Calls FUN_00d0ed10; once elapsed time reaches the frame marker time, marks entities, returns 3 if the state is 1, else fires post-simulation callbacks.
// @fnv 0x00d0fe00
// src: HAVOK_LIB 0x00d0fe00
int D0FE00Simulation::hkpContinuousSimulation_advanceTime()
{
    int result = hkpContinuousSimulation_advanceTimeInternal();
    if (m_fElapsedSimulationTime >= m_frameMarkerTime) {
        if (m_iActorEntryCount & 0x7fffffff)
            markEntities(m_pOwningWorld->unk078, &m_entitiesToActivate);
        if (g_D0FE00SimulationState == 1)
            return 3;
        if (m_pOwningWorld->m_postSimulationCallbacks) {
            D0FE00TimerBegin(g_D0FE00TimerPostSimCb);
            hkpWorldCallbackUtil_firePostSimulationCallback(m_pOwningWorld);
            D0FE00TimerBegin(g_D0FE00TimerEnd);
        }
    }
    return result;
}

namespace fnv_00d10730 {
struct D10730Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct FUN_00d10730 {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00d10730();
    virtual ~FUN_00d10730();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00d10730* b = static_cast<FUN_00d10730*>(p);
        reinterpret_cast<D10730Allocator&>(hkMemoryRouter_getInstance().heap()).ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00d10730
FUN_00d10730::FUN_00d10730()
{
}
}  // namespace fnv_00d10730

struct Se4b0_Heap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
inline Se4b0_Heap& Se4b0_heap()
{
    return reinterpret_cast<Se4b0_Heap&>(hkMemoryRouter_getInstance()->heap());
}
template <typename T> inline void Se4b0_construct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++) p[i] = t;
}
template <class T>
struct Se4b0_Arr { // local form of hkArrayBase: 0x00d0e4b0 needs the local base/helper form; the shared form changes instruction layout at +0x14d.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void _clearAndDeallocate(Se4b0_Heap& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
    }
    void AddBack(const T& t)
    {
        hkMemoryRouter* r = hkMemoryRouter_getInstance();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(reinterpret_cast<void*>(r->m_heap), reinterpret_cast<NiPoint3*>(this), sizeof(T));
        Se4b0_construct<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};
inline void Se4b0_freeStack(void* p)
{
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage = p;
}
template <class T> struct Se4b0_LocalArr : Se4b0_Arr<T> {
    T* m_pStackAllocation;
    Se4b0_LocalArr(int n)
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        hkMemoryRouter* m = hkMemoryRouter_getInstance();
        char* p = static_cast<char*>(m->m_stack.m_next.m_storage);
        m->m_stack.m_next.m_storage = p + n * sizeof(T);
        this->m_data = reinterpret_cast<T*>(p);
        this->m_iCapacityState = 0x80000000 | 1000;
        m_pStackAllocation = reinterpret_cast<T*>(p);
    }
    void release()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        Se4b0_freeStack(m_pStackAllocation);
        this->_clearAndDeallocate(Se4b0_heap());
    }
};
struct Se4b0_Body;
struct __declspec(align(16)) Se4b0_Step {
    float start, end, delta, inverse;
};
struct Se4b0_WorldView {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    Se4b0_Step step;
};
inline Se4b0_Step& Se4b0_step(World* w)
{
    return reinterpret_cast<Se4b0_WorldView*>(w)->step;
}
struct Se4b0_Constraint {
    ItemObj* item;
    unsigned int entityA;
    unsigned int entityB;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Se4b0_Body* getOther(Se4b0_Body* e)
    {
        return reinterpret_cast<Se4b0_Body*>(entityB ^ entityA ^ reinterpret_cast<unsigned int>(e));
    }
};
struct Se4b0_Instance {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    Se4b0_Constraint* internal;
};
struct Se4b0_Transform {
    float rotation00, rotation01, rotation02, rotation03;
    float rotation10, rotation11, rotation12, rotation13;
    float rotation20, rotation21, rotation22, rotation23;
    float positionX, positionY, positionZ, positionW;
};
struct Se4b0_MotionState {
    Se4b0_Transform transform;
    Se4b0_Transform swept;
};
void hkSweptTransformUtil_lerp2(const Se4b0_Transform& swept, float t, Se4b0_Transform& out);
void hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(void* arr, int lo, int hi, void* cmp);
struct Se4b0_Dispatcher {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual void s40(); virtual void s44();
    virtual void process(Se4b0_Body** bodies, int n, World* world, void* ctx, hkBool b);
};
struct Se4b0_Owner {
    int unk00, unk04;
    Se4b0_Dispatcher* dispatcher;
};
struct Se4b0_Body {
    int unk00, unk04;
    Se4b0_Owner* owner;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4;
    unsigned short storageIndex;
    unsigned short unkaa;
    Se4b0_Constraint* constraints;
    unsigned short numConstraints;
    unsigned short unkb2;
    Se4b0_Instance** slaves;
    int numSlaves;
    int unkbc, unkc0, unkc4, unkc8;
    void* context;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4;
    unsigned char motionType, unke9, unkea, unkeb;
    int unkec;
    Se4b0_MotionState motionState;
    Se4b0_Owner* getOwner() const { return owner; }
    void* getContext() const { return context; }
};
struct Se4b0_States {
    unsigned char* m_data;
    int m_iElementCount;
    unsigned char& operator[](int i) { return m_data[i]; }
};
inline void Se4b0_ensure(Se4b0_Body* body, float time, Se4b0_States& states)
{
    if (states[body->storageIndex] == 0) {
        states[body->storageIndex] = 1;
        Se4b0_MotionState* ms = &body->motionState;
        hkSweptTransformUtil_lerp2(ms->swept, time, ms->transform);
    }
}
__forceinline void Se4b0_visit(Se4b0_Body* body, Se4b0_Constraint* c, int level, float time,
    Se4b0_States& states, Se4b0_Arr<Se4b0_Body*>* outBodies, Se4b0_Arr<ItemObj*>* outItems)
{
    if (level <= c->item->m_1c) {
        Se4b0_Body* other = c->getOther(body);
        if (other->motionType == 5) {
            outItems->AddBack(c->item);
        } else if (states[other->storageIndex] != 16) {
            outItems->AddBack(c->item);
            if (states[other->storageIndex] < 2) {
                outBodies->AddBack(other);
                Se4b0_ensure(other, time, states);
                states[other->storageIndex] = 2;
            }
        }
    }
}

// @fnv 0x00d0e4b0
// src: HAVOK_LIB 0x00d0e4b0
void hkLs_toiActivateEntitiesAndCheckConstraints(World* world, int level, float time, Se4b0_Arr<Se4b0_Body*>* bodies,
    Se4b0_States* states, Se4b0_Arr<Se4b0_Body*>* outBodies, Se4b0_Arr<ItemObj*>* outItems)
{
    {
        Se4b0_LocalArr<Se4b0_Body*> island(1024);
        for (int i = 0; i < bodies->m_iElementCount; i++) {
            Se4b0_Body* body = bodies->m_data[i];
            Se4b0_ensure(body, time, *states);
            (*states)[body->storageIndex] = 8;
            CollectUnsaturatedObjects(reinterpret_cast<SrcL*>(body), level, time,
                reinterpret_cast<unsigned char**>(states), reinterpret_cast<hkArray<ObjL*, ArrLPolicy>*>(&island));
        }
        Se4b0_Step& step = Se4b0_step(world);
        Se4b0_Step saved = step;
        step.end = time;
        float delta = time - step.start;
        step.delta = delta;
        step.inverse = delta > 0.0f ? 1.0f / delta : 0.0f;
        Se4b0_Dispatcher* d = bodies->m_data[0]->owner->dispatcher;
        d->process(island.m_data, island.m_iElementCount, world, bodies->m_data[0]->getContext(), true);
        step = saved;
        island.release();
    }
    for (int i = 0; i < bodies->m_iElementCount; i++) {
        Se4b0_Body* body = bodies->m_data[i];
        (*states)[body->storageIndex] = 16;
        for (int j = 0; j < body->numConstraints; j++)
            Se4b0_visit(body, &body->constraints[j], level, time, *states, outBodies, outItems);
        int firstBody;
        (void)firstBody;
        int firstItem = outItems->m_iElementCount;
        firstBody = outBodies->m_iElementCount;
        for (int k = 0; k < body->numSlaves; k++)
            Se4b0_visit(body, body->slaves[k]->internal, level, time, *states, outBodies, outItems);
        int n = outItems->m_iElementCount - firstItem;
        if (n > 1)
            hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(outItems->m_data + firstItem, 0, n - 1, (void*)CompareItemPriority);
        n = outBodies->m_iElementCount - firstBody;
        if (n > 1)
            hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(outBodies->m_data + firstBody, 0, n - 1, (void*)IsLessByUnkD4);
    }
}

// Baseline from the attributed contributor draft dated 2026-10-28.
// Current-claim official checking is required; no padding instructions are inserted.
struct S_00d0d150_Entity {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac;
    int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    int unkd0;
    unsigned int m_uiUniqueId;
};

static __forceinline float& getSubStepTime(Context* ctx) {
    return reinterpret_cast<float&>(reinterpret_cast<Ctx*>(ctx)->unk0dc);
}

static __forceinline TimeStep& getContextTimeStep(Context* ctx) {
    return reinterpret_cast<TimeStep&>(reinterpret_cast<Ctx*>(ctx)->m_1d0);
}

static __forceinline void unlockContext(Context* ctx) {
    if (--ctx->depth() == 0 && !ctx->locked()) {
        if (ctx->pending())
            ctx->FUN_00c91120();
        if (ctx->mode() == 1 && ctx->otherPending())
            ctx->UpdateFields_00c91140();
    }
}

struct S00d0e9c0_StepInfo {
    TimeStep s;
    __forceinline S00d0e9c0_StepInfo(float start, float end) {
        s.start = start;
        s.end = end;
        s.delta = end - start;
        s.inverse = (s.delta == 0.0f) ? 0.0f : (1.0f / s.delta);
    }
};

struct S00d0e9c0_DwordPair { int a, b; };

static __forceinline void memCpyOneAligned112(void* dst, const void* src) {
    for (int i = 0; i < 14; i++) {
        static_cast<S00d0e9c0_DwordPair*>(dst)[i] = static_cast<const S00d0e9c0_DwordPair*>(src)[i];
    }
}

static __forceinline void removeToiEventAt(hkArrayBase<S_00d0d150_ToiEvent>& arr, int index) {
    arr.m_iElementCount--;
    if (arr.m_iElementCount != index) {
        memCpyOneAligned112(arr.m_data + index, arr.m_data + arr.m_iElementCount);
    }
}

struct S00d0e9c0_Key {
    unsigned int hi; unsigned int lo;
    __forceinline bool operator<(const S00d0e9c0_Key& o) const { return hi < o.hi || (hi == o.hi && lo < o.lo); }
};

struct S_00d0e9c0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17(Context* ctx, S_00d0d150_ToiEvent* ev, float fStepTime, float fSubStepTime);

    int unk04;
    int unk08;
    Context* m_iValueAtOffset0C;
    int unk10;
    float m_kRayStart;
    float m_kRayEnd;
    float m_stepTime;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    hkArrayBase<S_00d0d150_ToiEvent> m_kToiEventQueue;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int m_iToiEventCount;

    int hkpContinuousSimulation_handleAllToisTill(float arg1);
    hkBool hkpContinuousSimulation_fireEarliestToiCallbacksAndCheckEnabled(S_00d0d150_ToiEvent* ev, float* fSubStepTime);
    void hkpContinuousSimulation_handleSimpleToi(Context* ctx, S_00d0d150_ToiEvent* ev, float fStepTime, float fSubStepTime);
};

// Repeatedly picks the earliest queued TOI event, removes it, dispatches via vfn17 or FUN_00d0e210, and returns 0 when none is left or 3 when DAT_01269200 is 1.
// @fnv 0x00d0e9c0
// src: HAVOK_LIB 0x00d0e9c0
int S_00d0e9c0::hkpContinuousSimulation_handleAllToisTill(float minTime) {
    while (true) {
        struct Selection { union { int i; float end; } scan; float earliest; }; Selection sel;
        Context* ctx = this->m_iValueAtOffset0C;
        ctx->depth()++;

        int bestIdx;
        float subStepTime;
        sel.earliest = minTime;
        subStepTime = getSubStepTime(this->m_iValueAtOffset0C);
        bestIdx = -1;
        while (true) {
            for (sel.scan.i = 0; sel.scan.i < this->m_kToiEventQueue.m_iElementCount; sel.scan.i++) {
                S_00d0d150_ToiEvent& cand = this->m_kToiEventQueue.m_data[sel.scan.i];
                if (cand.m_uiCommandId < sel.earliest) {
                    bestIdx = sel.scan.i;
                    sel.earliest = cand.m_uiCommandId;
                } else if (cand.m_uiCommandId == sel.earliest && bestIdx != -1) {
                    S_00d0d150_ToiEvent& best = this->m_kToiEventQueue.m_data[bestIdx];
                    S00d0e9c0_Key candKey = { cand.m_kActorEntries[0]->m_uiUniqueId, cand.m_kActorEntries[1]->m_uiUniqueId };
                    S00d0e9c0_Key bestKey = { best.m_kActorEntries[0]->m_uiUniqueId, best.m_kActorEntries[1]->m_uiUniqueId };
                    if (candKey < bestKey) {
                        bestIdx = sel.scan.i;
                        sel.earliest = cand.m_uiCommandId;
                    }
                }
            }

            if (0 > bestIdx) {
                unlockContext(ctx);
                return 0;
            }

            S_00d0d150_ToiEvent* pEvent = &this->m_kToiEventQueue.m_data[bestIdx];
            if (this->hkpContinuousSimulation_fireEarliestToiCallbacksAndCheckEnabled(pEvent, &subStepTime)) {
                break;
            }
            removeToiEventAt(this->m_kToiEventQueue, bestIdx);
            sel.earliest = minTime;
            subStepTime = getSubStepTime(this->m_iValueAtOffset0C);
            bestIdx = -1;
        }

        S_00d0d150_ToiEvent event = this->m_kToiEventQueue.m_data[bestIdx];
        removeToiEventAt(this->m_kToiEventQueue, bestIdx);

        this->m_kRayStart = event.m_uiCommandId;
        sel.scan.end = this->m_kRayEnd;
        S00d0e9c0_StepInfo step(event.m_uiCommandId, sel.scan.end);
        getContextTimeStep(this->m_iValueAtOffset0C) = step.s;
        this->m_iValueAtOffset0C->world()->time() = step.s;

        if (event.m_cEventType == 0) {
            this->vfn17(this->m_iValueAtOffset0C, &event, this->m_stepTime, subStepTime);
        } else {
            this->hkpContinuousSimulation_handleSimpleToi(this->m_iValueAtOffset0C, &event, this->m_stepTime, subStepTime);
        }

        this->m_iToiEventCount++;
        if (DAT_01269200 == 1) {
            unlockContext(ctx);
            return 3;
        }

        unlockContext(ctx);
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _mm_prefetch(const char*, int);
extern unsigned long DAT_0126835c;
extern char DAT_010cc624[], DAT_010cd3e8[], DAT_010cc5fc[], DAT_010cc5f0[];
extern char DAT_010cd3d8[], DAT_010c41f8[], DAT_010cc5e4[], DAT_010cc5d8[], DAT_01076f38[];

struct ScratchSpan {
    unsigned* start;
    int count;
    unsigned capacity;
    unsigned* original;
};
void __cdecl hkpTypedBroadPhaseDispatcher_removeDuplicates(ScratchSpan*, ScratchSpan*);
struct RenderSink {
    void __thiscall DispatchPairs(unsigned*, int);
    void __thiscall hkpTypedBroadPhaseDispatcher_addPairs(unsigned*, int, void*);
};
struct Dispatcher {
    virtual void slot00(); virtual void slot04();
    virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1c();
    virtual void slot20(); virtual void slot24();
    virtual void slot28();
    virtual void Dispatch(unsigned**, unsigned*, int, ScratchSpan*, ScratchSpan*);
    unsigned unk04, unk08, unk0c;
    int enabled;
    void __thiscall hkpBroadPhase_lockImplementation();
    void __thiscall hkpBroadPhase_unlockImplementation();
};
struct Allocator {
    virtual void slot00(); virtual void slot04();
    virtual void slot08(); virtual void slot0c();
    virtual void Free(unsigned*, unsigned);
    virtual void slot14(); virtual void slot18();
    virtual void slot1c(); virtual void slot20();
    virtual bool Available(int);
};
struct S00d0d3f0_Router {
    int cur;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* alloc;
    Allocator& heap() { return *alloc; }
};
static inline S00d0d3f0_Router* S00d0d3f0_router() { return (S00d0d3f0_Router*)hkMemoryRouter_getInstance(); }
struct Region { unsigned unk00, unk04; unsigned data; };
struct RenderParams {
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    Dispatcher* dispatcher;
    unsigned unk05c;
    unsigned unk060;
    RenderSink* sink;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    World* texture;
    Region* region;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    unsigned unk320;
    unsigned unk324;
    unsigned unk328;
    unsigned unk32c;
    unsigned unk330;
    unsigned unk334;
    unsigned unk338;
    unsigned batchCount;
    void __thiscall EnterLock(unsigned);
    void __thiscall hkpWorld_unlockIslandForConstraintUpdate(unsigned);
};
struct CompressedBounds {
    unsigned minX, minY, minZ;
    unsigned char minMarginX, minMarginY, minMarginZ, shift;
    unsigned maxX, maxY, maxZ;
    unsigned char maxMarginX, maxMarginY, maxMarginZ, reserved;
};
struct Source {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    CompressedBounds bounds;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned handle;
};
struct TraceCmd {
    const char* name;
    unsigned time0;
    unsigned time1;
    const char* category;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        time0=ticks;
    }
};
struct TraceState {
    unsigned unk00;
    char* cursor;
    unsigned unk08;
    char* end;
};
static __forceinline void Trace(unsigned char* event, unsigned char* category=0)
{
    TraceState* state=(TraceState*)TlsGetValue(DAT_0126835c);
    char* cursor=state->cursor;
    if (cursor<state->end) {
        TraceCmd* h=(TraceCmd*)cursor;
        h->name=(const char*)event;
        if (category) h->category=(const char*)category;
        h->setTime();
        state->cursor=cursor+(category ? 16 : 12);
    }
}
// @fnv 0x00d0d3f0
// src: XBOX_PDB 0x00d0d3f0
void __stdcall hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(Source** sources, int count, RenderParams* context, void* marker)
{
    if (!count) return;
    Trace((unsigned char*)&DAT_010cc624,(unsigned char*)&DAT_010cd3e8);

    unsigned pieces=context->batchCount;
    ScratchSpan primary;
    primary.start=0;
    primary.count=0;
    primary.capacity=0x80000000u;
    hkMemoryRouter* cursor=hkMemoryRouter_getInstance();
    unsigned* primaryStorage=(unsigned*)cursor->m_stack.m_next.m_storage;
    cursor->m_stack.m_next.m_storage=reinterpret_cast<char*>(primaryStorage) + ((pieces*8+0x7f)&~0x7fu);
    primary.capacity=pieces|0x80000000u;
    primary.start=primaryStorage;
    primary.original=primaryStorage;

    ScratchSpan secondary;
    pieces=context->batchCount;
    secondary.start=0;
    secondary.count=0;
    secondary.capacity=0x80000000u;
    cursor=hkMemoryRouter_getInstance();
    unsigned* secondaryStorage=(unsigned*)cursor->m_stack.m_next.m_storage;
    cursor->m_stack.m_next.m_storage=reinterpret_cast<char*>(secondaryStorage) + ((pieces*8+0x7f)&~0x7fu);
    secondary.start=secondaryStorage;
    secondary.capacity=pieces|0x80000000u;
    secondary.original=secondaryStorage;

    cursor=hkMemoryRouter_getInstance();
    unsigned* bounds=(unsigned*)cursor->m_stack.m_next.m_storage;
    cursor->m_stack.m_next.m_storage=reinterpret_cast<char*>(bounds) + ((count*32+0x7f)&~0x7fu);
    cursor=hkMemoryRouter_getInstance();
    unsigned** rows=(unsigned**)cursor->m_stack.m_next.m_storage;
    cursor->m_stack.m_next.m_storage=reinterpret_cast<char*>(rows) + ((count*4+0x7f)&~0x7fu);

    Source** input=sources;
    int remaining=count-1;
    if (remaining>=0) {
        unsigned* box=bounds+2;
        unsigned** out=rows;
        do {
            Source* source=*input;
            if(remaining>=4) _mm_prefetch((const char*)&input[4]->unk10,0);
            *out=&source->unk24;
            CompressedBounds* packed=&source->bounds;
            if (packed->minX>packed->maxX)
                hkpEntityAabbUtil_entityBatchRecalcAabb(context->texture,(Body**)&source,1);
            unsigned shift=packed->shift;
            unsigned minX=packed->minX-(packed->minMarginX<<shift);
            unsigned minY=packed->minY-(packed->minMarginY<<shift);
            unsigned minZ=packed->minZ-(packed->minMarginZ<<shift);
            box[-2]=minX;
            box[-1]=minY;
            box[0]=minZ;
            unsigned maxX=packed->maxX+(packed->maxMarginX<<shift);
            unsigned maxY=packed->maxY+(packed->maxMarginY<<shift);
            unsigned maxZ=packed->maxZ+(packed->maxMarginZ<<shift);
            box[2]=maxX;
            box[3]=maxY;
            box[4]=maxZ;
            ++input;
            ++out;
            box+=8;
        } while (--remaining>=0);
    }
    Trace((unsigned char*)&DAT_010cc5fc);
    if (context->dispatcher->enabled) context->dispatcher->hkpBroadPhase_lockImplementation();
    context->dispatcher->Dispatch(rows,bounds,count,&primary,&secondary);
    if (context->dispatcher->enabled) context->dispatcher->hkpBroadPhase_unlockImplementation();
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage=rows;
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage=bounds;

    if (primary.count+secondary.count>0) {
        Trace((unsigned char*)&DAT_010cc5f0);
        hkpTypedBroadPhaseDispatcher_removeDuplicates(&primary,&secondary);
    }

    if (marker) {
        Trace((unsigned char*)&DAT_010cd3d8);
        volatile unsigned char* flag=(volatile unsigned char*)marker;
        while (*flag!=1 && *flag!=2) {}
        Trace((unsigned char*)&DAT_010c41f8);
    }
    if(primary.count+secondary.count>0) {
        Trace((unsigned char*)&DAT_010cc5e4);
        context->EnterLock(sources[0]->handle);
        context->sink->DispatchPairs(secondary.start,secondary.count);
        int pairs=primary.count;
        if(!S00d0d3f0_router()->heap().Available(pairs<<10)) {
            context->hkpWorld_unlockIslandForConstraintUpdate(sources[0]->handle);
        } else {
            Trace((unsigned char*)&DAT_010cc5d8);
            Region* region=context->region;
            context->sink->hkpTypedBroadPhaseDispatcher_addPairs(primary.start,primary.count,region ? &region->data : 0);
            context->hkpWorld_unlockIslandForConstraintUpdate(sources[0]->handle);
        }
    }
    Trace((unsigned char*)&DAT_01076f38);
    unsigned* secondaryOriginal=secondary.original;
    if (secondaryOriginal==secondary.start) secondary.count=0;
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage=secondaryOriginal;
    Allocator& secondaryAllocator=S00d0d3f0_router()->heap();
    secondary.count=0;
    if ((secondary.capacity&0x80000000u)==0)
        secondaryAllocator.Free(secondary.start,(secondary.capacity&0x3fffffffu)*8);
    secondary.start=0;
    secondary.capacity=0x80000000u;
    unsigned* primaryOriginal=primary.original;
    if (primaryOriginal==primary.start) primary.count=0;
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage=primaryOriginal;
    Allocator& primaryAllocator=S00d0d3f0_router()->heap();
    primary.count=0;
    if ((primary.capacity&0x80000000u)==0)
        primaryAllocator.Free(primary.start,(primary.capacity&0x3fffffffu)*8);
}

extern const char str_010cc54c[];
extern const char str_010c41f8[];
struct S00d0d8b0_Array {
    unsigned char** m_data;
    int m_iElementCount;
    int GetLogicalSize() const { return m_iElementCount; }
    unsigned char* operator[](int i) const { return m_data[i]; }
};
struct S00d0d8b0_Coll {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    int m_lastSize;
    S00d0d8b0_Array m_kSectors;
    int getSectorSize(int i) const { return (i + 1 == m_kSectors.GetLogicalSize()) ? m_lastSize : 0x200; }
};
struct S00d0d8b0_Props {
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    int unk08;
    int unk0c;
    int unk10;
};
struct S00d0d8b0_Toi {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    float m_uiCommandId;
    float m_fSeparation;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S00d0d8b0_Props m_kProperties;
    int m_aiContactData[7];
};
struct S00d0d8b0_Out {
    S_00d0d150_ProcessCdPoint* m_firstFree;
    S00d0d8b0_Coll* m_pOwnerObject;
    int unk08;
    int unk0c;
    S_00d0d150_ProcessCdPoint m_akContactPoints[256];
    S00d0d8b0_Toi m_fTimeOfImpact;
    void* m_potential;
    S00d0d8b0_Out(S00d0d8b0_Coll* owner) : m_pOwnerObject(owner) { m_fTimeOfImpact.m_uiCommandId = 3.40282e+38f; m_fTimeOfImpact.m_kProperties.m_fAccumulatedImpulse = 0.0f; m_fTimeOfImpact.m_kProperties.m_fImpulseLimit = 0.0f; }
    void reset() { m_firstFree = &m_akContactPoints[0]; m_fTimeOfImpact.m_uiCommandId = 3.40282e+38f; m_potential = 0; }
    bool hasToi() const { return m_fTimeOfImpact.m_uiCommandId != 3.40282e+38f; }
};
struct S00d0d8b0_Obj {
    void QueueToiEvent(S00d0d8b0_Out* out, ThingX* x);
    void hkpContinuousSimulation_collideIslandNarrowPhaseContinuous(S00d0d8b0_Coll* coll, ThingP* p);
};
static __forceinline void WriteClock(const char* name) {
    MonitorStreamD0* s = (MonitorStreamD0*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd) {
        TimerCommandD0* h = (TimerCommandD0*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_uiCommandId = ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
// @fnv 0x00d0d8b0
// src: XBOX_PDB 0x00d0d8b0
void S00d0d8b0_Obj::hkpContinuousSimulation_collideIslandNarrowPhaseContinuous(S00d0d8b0_Coll* coll, ThingP* p)
{
    unsigned char* end;
    WriteClock(str_010cc54c);
    S00d0d8b0_Out out(coll);
    for (int i = 0; i < coll->m_kSectors.GetLogicalSize(); ) {
        unsigned char* rec = coll->m_kSectors[i];
        i++;
        if (i == coll->m_kSectors.GetLogicalSize())
            end = rec + coll->m_lastSize;
        else
            end = rec + 0x200;
        while (rec < end) {
            ThingX* x = (ThingX*)rec;
            _mm_prefetch((const char*)x->m_pObject, 0);
            int kind = (signed char)x->m_bKind;
            int a = x->m_iA;
            int b = x->m_iB;
            _mm_prefetch((const char*)(rec + 0x80), 0);
            p->m_afEntries = (ThingEntry*)(p->m_pTable + kind * 64 + 0x1c20);
            p->m_iCached = p->m_afEntries->m_iValue;
            out.reset();
            hkAgentNnMachine_ProcessAgent(x, p, (ThingS*)&out, (int)x->m_pObject);
            if (DAT_01269200 == 1) {
                WriteClock(str_010c41f8);
                return;
            }
            if (out.m_firstFree != &out.m_akContactPoints[0])
                x->m_pObject->v18(a, b, p, &out);
            if (out.hasToi())
                QueueToiEvent(&out, x);
            rec += rec[3];
        }
    }
    WriteClock(str_010c41f8);
}

#include <string.h>

typedef unsigned int U32;
typedef unsigned char U8;
class BoolFlag {
    char value;
public:
    inline BoolFlag() {}
    inline BoolFlag(bool b) {value=static_cast<char>(b);}
    inline operator bool() const {return value!=0;}
    inline BoolFlag& operator=(bool b) {value=char(b);return *this;}
    inline BoolFlag operator==(bool b) const {return int(value)==int(b);}
    inline BoolFlag operator!=(bool b) const {return int(value)!=int(b);}
};
class Alloc {
public:
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual __declspec(nothrow) void freeBuffer(void*,int) throw();
    template<class T> inline void release(void* p,int n) {freeBuffer(p,n*sizeof(T));}
};
// This is the router's stack allocator subobject, not the containing hkMemoryRouter.
struct StackArena {
    char* top;
    int unk04,unk08;
    __forceinline void* take(int n) {char* p=top;top=p+n;return p;}
    __forceinline void put(void* p) {top=static_cast<char*>(p);}
};
inline StackArena& routerStack() {return reinterpret_cast<StackArena&>(hkMemoryRouter::getInstance().m_stack.m_next.m_storage);}
struct ArrayOps {
    static __declspec(nothrow) void __cdecl hkArrayUtil__reserve(Alloc&,void*,int,int) throw();
    static __declspec(nothrow) void __cdecl ResizeAudioStream(Alloc&,void*,int) throw();
    __forceinline static void GrowArray(Alloc& a,void* p,int n) {ResizeAudioStream(a,p,n);}
};
template<class T> __forceinline void releaseArena(T* p) {routerStack().put(p);}
template<class T> __forceinline T* allocateArena(int n) {return static_cast<T*>(routerStack().take((n*sizeof(T)+127)&~127));}
struct SelectHeap {
    inline Alloc& get(const void*) const {return reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap());}
};
template<class T> __forceinline void copyOne(T* dst,const T* src) {*reinterpret_cast<unsigned int*>(dst)=*reinterpret_cast<const unsigned int*>(src);}
struct ScalarTag {};
struct ObjectTag {};
template<class T> struct ElementTag {typedef ObjectTag type;};
template<class T> struct ElementTag<T*> {typedef ScalarTag type;};
template<class T> __forceinline void destroyElements(T*,int,ScalarTag) {}
template<class T> __forceinline void destroyElements(T* p,int n,ObjectTag) {for(int i=0;i<n;++i)p[i].~T();}
template<class T> __forceinline void copyElements(T* p,int n,const T& value) {for(int i=0;i<n;++i)p[i]=value;}
template<class T> __forceinline void destroyRange(T* p,int n) {destroyElements(p,n,typename ElementTag<T>::type());}
template<class T> __forceinline void assignRange(T* p,int n,const T* q) {for(int j=0;j<n;++j)p[j]=q[j];}
template<class T> class ListBase {
protected:
    T* data;
    int size;
    int flags;
protected:
    __forceinline __declspec(nothrow) ListBase(const ListBase&) throw() {}
    __forceinline ListBase& operator=(const ListBase&) {return *this;}
public:
    enum { SizeMask=0x3fffffff, Borrowed=int(0x80000000u), Signed=-1 };
    __forceinline __declspec(nothrow) ListBase() throw():data(0),size(0),flags(Borrowed) {}
    __forceinline __declspec(nothrow) ListBase(T* p,int n,int cap) throw():data(p),size(n),flags(cap|Borrowed) {}
    __forceinline int GetLogicalSize() const {return size;}
    __forceinline int getCapacity() const {return flags&SizeMask;}
    __forceinline bool isEmpty() const {return size==0;}
    __forceinline T* begin() {return data;}
    __forceinline const T* begin() const {return data;}
    __forceinline T& operator[](int i) {return data[i];}
    __forceinline const T& operator[](int i) const {return data[i];}
    __forceinline void clear() {destroyRange(data,size);size=0;}
    __forceinline void drop(Alloc& a) {
        clear();
        if((flags&Borrowed)==0)a.release<T>(data,getCapacity());
        data=0;flags=Borrowed;
    }
    __forceinline void reserveWith(Alloc& a,int n) {
        const int capacity=getCapacity();if(capacity<n) {int doubled=2*capacity;int requested=(n<doubled)?doubled:n;ArrayOps::hkArrayUtil__reserve(a,this,requested,sizeof(T));}
    }
    __forceinline void pushBackUnchecked(const T& value) {
        copyElements(data+size,1,value);++size;
    }
    __forceinline T* expandByUnchecked(int n) {int old=size;size=old+n;return data+old;}
    __forceinline void removeAt(int i) {--size;if(size!=i)copyOne(data+i,data+size);}
    __declspec(nothrow) void splice(Alloc&,int,int,const T*,int);
    __declspec(noinline) __declspec(nothrow) void Search(Alloc&,int,const T*,int) throw();
    __declspec(noinline) __declspec(nothrow) void CallWithFlag(Alloc&,int,const T&) throw();

};
template<class T> __declspec(nothrow) void ListBase<T>::splice(Alloc& a,int at,int erased,const T* source,int n) {
        int result=n+size-erased;
        int moving=size-at-erased;
        if(result>getCapacity())reserveWith(a,result);
        destroyRange(data+at,erased);
        memmove(data+at+n,data+at+erased,moving*sizeof(T));
        assignRange(data+at,n,source);
        size=result;
    }
template<class T> __declspec(noinline) __declspec(nothrow) void ListBase<T>::Search(Alloc& a,int at,const T* source,int n) throw() {splice(a,at,0,source,n);}
template<class T> __declspec(noinline) __declspec(nothrow) void ListBase<T>::CallWithFlag(Alloc& a,int at,const T& value) throw() {Search(a,at,&value,1);}
template<class T> class List : public ListBase<T> {
public:
    __forceinline __declspec(nothrow) List() throw() {}
    __forceinline __declspec(nothrow) List(T* p,int n,int cap) throw():ListBase<T>(p,n,cap) {}
    __forceinline __declspec(nothrow) ~List() throw() {ClearAndRelease();}
    __forceinline void ClearAndRelease() {this->drop(SelectHeap().get(this));}
    __forceinline void reserve(int n) {this->reserveWith(SelectHeap().get(this),n);}
    __forceinline void aiRecipeIndex(int i,const T& t) {this->CallWithFlag(SelectHeap().get(this),i,t);}
    __forceinline void aiRecipeIndex(int i,const T* p,int n) {this->Search(SelectHeap().get(this),i,p,n);}
};
template<class T,int N> class InlineList : public List<T> {
    T storage[N];
public:
    __forceinline __declspec(nothrow) InlineList(int n=0) throw():List<T>(storage,n,N) {}
    __forceinline __declspec(nothrow) ~InlineList() throw() {}
};
template<class T> class ArenaList : public List<T> {
    T* original;
public:
    __forceinline __declspec(nothrow) ArenaList(int n) throw() {
        this->data=allocateArena<T>(n);
        this->flags=n|ListBase<T>::Borrowed;
        original=this->data;
    }
    __forceinline BoolFlag wasReallocated() const {return original!=this->data;}
    __forceinline __declspec(nothrow) ~ArenaList() throw() {
        if(!wasReallocated())this->clear();
        releaseArena(original);
    }
};
struct DynamicNode;
struct SolverIsland {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44;
    List<DynamicNode*> entities;
    inline const List<DynamicNode*>& GetEntities() const {return entities;}
};
template<class E,class S> class StoredEnum {
    S storage;
public:
    inline StoredEnum() {}
    inline StoredEnum(E e):storage(S(e)) {}
    inline operator E() const {return E(storage);}
    inline void operator=(E e) {storage=S(e);}
    inline BoolFlag operator==(E e) const {return storage==S(e);}
    inline BoolFlag operator!=(E e) const {return storage!=S(e);}
};
struct Motion {
    enum MotionType { Invalid=0,Dynamic=1,Keyframed=4,Fixed=5,MOTION_KEYFRAMED=4 };
    int unk00,unk04;
    StoredEnum<MotionType,U8> type;
    U8 unk09,unk0a,unk0b;
    int unk0c;
    hkMotionState state;
    inline hkMotionState* GetMotionState() {return &state;}
    inline MotionType getType() const {return type;}
};
struct DynamicNode {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    U32 unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    U32 unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    U32 unk60,unk64,unk68,unk6c,unk70;
    const char* m_name;
    U32 unk78,unk7c;
    inline const char* getName() const {return m_name;}
    U32 unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4;
    unsigned short m_usStorageIndex,unkaa;
    U32 unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8;
    SolverIsland* island;
    U32 unkd0,unkd4,unkd8,unkdc;
    Motion movement;
    inline BoolFlag isFixed() const {return movement.type==Motion::Fixed;}
    inline BoolFlag isFixedOrKeyframed() const {return movement.type==Motion::Fixed || movement.type==Motion::Keyframed;}
    inline SolverIsland* GetSimulationIsland() const {return island;}
    inline Motion* getMotion() {return &movement;}
    inline Motion* getRigidMotion() {return &movement;}
};
struct ConstraintPair { int unk00;DynamicNode* bodies[2]; };
struct Constraint {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    ConstraintPair* pair;
    enum ConstraintPriority { PriorityZero=0,PriorityForced=5 };
    inline DynamicNode* getEntityA() const {return pair->bodies[0];}
    inline DynamicNode* getEntityB() const {return pair->bodies[1];}
};
struct Schema;
struct Accumulator;
struct SolverElement;
struct ResourceInfo;
struct TimeInterval;
struct BackupTransform;
struct ConstraintQuery;
template<class T> struct UnsignedShortArray {T* m_pRayStart;T* m_kRayEnd;T* m_pTileTemplate;T* m_pValues;};
struct Resources {
    TimeInterval* m_pStepInfo;
    ResourceInfo* m_pSolverInfo;
    ConstraintQuery* m_pConstraintQueryIn;
    Accumulator* m_pVelocityAccumulatorA;
    Accumulator* m_pVelocityAccumulatorB;
    Accumulator* m_pVelocityAccumulatorC;
    BackupTransform* m_pBodyABackup;
    BackupTransform* m_pBodyBBackup;
    UnsignedShortArray<Schema> m_akBufferStates[2];
    SolverElement* m_pBufferA;
    SolverElement* m_pBufferB;
    SolverElement* m_pBufferC;
    SolverElement* m_pBufferD;
};
struct SchemaRecord {Constraint* m_pHavokConstraint;Schema* m_pConstraintSchema;float m_fAllowedPenetrationDepth;};
struct CollisionInput {};
struct ProcessInput : CollisionInput {};
struct Scene {
    U32 unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    U32 unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    U32 unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    U32 unk60,unk64,unk68,unk6c,unk70,unk74;
    ProcessInput* input;
    inline ProcessInput* getCollisionInputRw() {return input;}
};

struct StateTable {
    unsigned char* data;
    int size;
    __forceinline unsigned char& operator[](int i) {return data[i];}
};
struct Limits {
    Constraint::ConstraintPriority priority;
    int entities,contacts,constraints,fullSteps,extraSteps;
};
struct PairEvent;
struct PairManager {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual void s10();virtual void s14();virtual void s18();virtual void s1c();
    virtual void s20();virtual void s24();virtual void s28();virtual void s2c();
    virtual void s30();virtual void s34();virtual void s38();virtual void s3c();
    virtual void s40();virtual void s44();
    virtual __declspec(nothrow) void confirm(PairEvent&,float,List<DynamicNode*>&) throw();
};
struct PairEvent {
    float time;
    int unk04,unk08;
    DynamicNode* bodies[2];
    PairManager* manager;
};
struct Violation { Constraint* constraint; const void* point; const void* properties; };
struct ResourceManager {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual __declspec(nothrow) int violations(List<Violation>&) throw();
    virtual __declspec(nothrow) int overflow() throw();
};

// hkTraceStream: the -Od lib shows hkToiPrintf at these sites; the SDK macro is if(0) hkTraceStream::GetMonitorStream().dontPrintf.
struct TraceStream {
    static TraceStream* s_instance;
    static inline TraceStream& GetMonitorStream() {return *s_instance;}
    void __cdecl dontPrintf(const char*,const char*,...);
};
__declspec(nothrow) void hkSweptTransformUtil_backStepMotionState(float,hkMotionState&) throw();
__declspec(nothrow) void hkSolveUpload() throw();
__declspec(nothrow) void hkpConstraintSolverResources_ProcessEntries_00d88670(Resources&,DynamicNode* const*,int) throw();
__declspec(nothrow) BoolFlag hkpConstraintSolverSetup_internalIsMemoryOkForNewAccumulators(Resources&,DynamicNode**,int) throw();
__declspec(nothrow) BoolFlag CheckTotalsWithinLimits(Resources&,Constraint**,int) throw();
__declspec(nothrow) void hkpConstraintSolverSetup_subSolve(Resources&,int) throw();
__declspec(nothrow) void hkpConstraintSolverSetup_internalAddJacobianSchemas(Resources&,Constraint**,int,List<SchemaRecord>&) throw();
__declspec(nothrow) void Object_ProcessEntries_00d0cb00(Resources&,ProcessInput&,List<SchemaRecord>&,int&,Constraint::ConstraintPriority,StateTable&,const List<DynamicNode*>&,List<DynamicNode*>&) throw();
__declspec(nothrow) void hkLs_toiActivateEntitiesAndCheckConstraints(ProcessInput&,Constraint::ConstraintPriority,float,const List<DynamicNode*>&,StateTable&,List<DynamicNode*>&,List<Constraint*>&) throw();
__declspec(nothrow) void hkLs_backstepAndFreezeEntireIsland(float,SolverIsland*,StateTable&,List<DynamicNode*>&) throw();
__declspec(nothrow) void hkpWorldAgentUtil_invalidateTim(DynamicNode*,const CollisionInput&) throw();
__declspec(nothrow) void hkVector4_setRotatedDir_ProcessEntries_00d0bf30(Resources&,const List<DynamicNode*>&) throw();
__declspec(nothrow) BoolFlag CollectMatchingEntries(Resources&,const List<SchemaRecord>&,ProcessInput&,List<Violation>*) throw();
__declspec(nothrow) void Object_UpdateFields_00d8aac0(const ResourceInfo&,Schema*,Accumulator*,SolverElement*) throw();
__declspec(nothrow) void hkpConstraintSolverSetup_oneStepIntegrate(const ResourceInfo&,const TimeInterval&,const Accumulator*,DynamicNode* const*,int) throw();
__declspec(nothrow) void UpdateIslandMotionStates(SolverIsland*,StateTable&,Resources&) throw();
__declspec(nothrow) void PartitionMotionPairs(List<SchemaRecord>&,int&,int) throw();
__declspec(nothrow) void hkLs_toiActivateConstraintsLinkingActivatedEntities(List<SchemaRecord>&,int&,StateTable&) throw();

// 0x00cf1510 interpolates a swept pose into hkMotionState::m_kMotionTransform (three rotation columns and translation).
__declspec(nothrow) void hkSweptTransformUtil_lerp2(const hkSweptTransform&,float,hkTransform&) throw();
__forceinline void updateEntity(DynamicNode* node,float time) {
    hkMotionState* m=node->getMotion()->GetMotionState();
    hkSweptTransformUtil_lerp2(m->m_kSweptTransform,time,m->m_kMotionTransform);
}
__forceinline void restoreState(hkMotionState* m) {
    reinterpret_cast<hkRotation*>(&m->m_kMotionTransform)->hkRotation_set(m->m_kSweptTransform.m_qRotation1);
    LocalM128 center=m->m_kSweptTransform.m_vCenterOfMassLocal.m_vComponents;
    LocalM128 y=_mm_mul_ps(_mm_shuffle_ps(center,center,0x55),m->m_kMotionTransform.m_row1);
    LocalM128 x=_mm_mul_ps(_mm_shuffle_ps(center,center,0),m->m_kMotionTransform.m_row0);
    LocalM128 z=_mm_mul_ps(_mm_shuffle_ps(center,center,0xaa),m->m_kMotionTransform.m_row2);
    m->m_kMotionTransform.m_row3=_mm_sub_ps(m->m_kSweptTransform.m_vCenterOfMass1.m_vComponents,_mm_add_ps(_mm_add_ps(y,x),z));
}
__declspec(noinline) __declspec(nothrow) void PartitionMotionPairs(List<SchemaRecord>& a,int& cursor,int n) throw() {
    for(int i=a.GetLogicalSize()-n;i<a.GetLogicalSize();++i) {
        Constraint* c=a[i].m_pHavokConstraint;
        if(c->getEntityA()->isFixedOrKeyframed() || c->getEntityB()->isFixedOrKeyframed()) {
            SchemaRecord tmp=a[cursor++];
            a[cursor-1]=a[i];a[i]=tmp;
        }
    }
}
// src: HAVOK_LIB 0x00d0c6d0
__declspec(noinline) __declspec(nothrow) void hkLs_toiActivateConstraintsLinkingActivatedEntities(List<SchemaRecord>& a,int& cursor,StateTable& state) throw() {
    for(int i=cursor;i<a.GetLogicalSize();++i) {
        Constraint* c=a[i].m_pHavokConstraint;
        if(state[c->getEntityA()->m_usStorageIndex]==16 && state[c->getEntityB()->m_usStorageIndex]==16) {
            SchemaRecord tmp=a[cursor++];a[cursor-1]=a[i];a[i]=tmp;
        }
    }
}
struct SolveStepData { int unk00,unk04; float delta; };
struct SolveResourcesView { SolveStepData* step; void* solver; void* query; void* accumulators; };
struct SolvePoint { hkVector4 position,normal; };
struct SolveAtoms {
    U32 unk00;
    unsigned short unk04,m_iElementCount;
    unsigned short unk08;
    U8 stride,unk0b;
    U32 unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    SolvePoint points[1];
};
struct SolveConstraintData {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c();
    virtual int GetType();
    U32 unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
    SolveAtoms* atoms;
};
struct SolveConstraint {
    U32 unk00,unk04,unk08;
    SolveConstraintData* data;
    U32 unk10,unk14,unk18;
    U8 priority;
};
struct SolveRecord { SolveConstraint* constraint; void* schema; float depth; };
struct SolveViolation { SolveConstraint* constraint; const SolvePoint* point; const void* properties; };
extern "C" __declspec(nothrow) int __cdecl hkVector4_ProcessEntries_00d9f6f0(void*,void*,void*,int,float*) throw();
extern "C" __declspec(nothrow) int __cdecl hkLs_areVelocitiesOk(float,SolveRecord*,float*,int,void*) throw();
__declspec(noinline) __declspec(nothrow) BoolFlag CollectMatchingEntries(Resources& originalResources,const List<SchemaRecord>& originalRecords,ProcessInput& scene,List<Violation>* originalViolations)
{
    void* world=&originalResources;
    void* matrices=const_cast<List<SchemaRecord>*>(&originalRecords);
    void* violations=originalViolations;
    SolveResourcesView* resources=reinterpret_cast<SolveResourcesView*>(world);
    ListBase<SolveRecord>* records=reinterpret_cast<ListBase<SolveRecord>*>(matrices);
    ListBase<SolveViolation>* rejected=reinterpret_cast<ListBase<SolveViolation>*>(violations);
    float velocities[256];
    bool satisfied=true;
    for(int i=0;i<records->GetLogicalSize();++i) {
        SolveRecord& record=records->begin()[i];
        if(record.constraint->priority!=5) continue;
        int n=hkVector4_ProcessEntries_00d9f6f0(resources->solver,record.schema,resources->accumulators,256,velocities);
        int violated=hkLs_areVelocitiesOk(resources->step->delta,&record,velocities,n,&scene);
        if(violated<0) continue;
        if(!rejected) return BoolFlag(false);
        satisfied=false;
        
        if(rejected->GetLogicalSize()==rejected->getCapacity())
            ArrayOps::GrowArray(reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap()),rejected,12);
        SolveViolation& entry=*rejected->expandByUnchecked(1);
        entry.constraint=record.constraint;
        if(record.constraint->data->GetType()==11) {
            SolveAtoms* atoms=record.constraint->data->atoms;
            entry.point=atoms->points+violated;
            entry.properties=reinterpret_cast<U8*>(atoms->points+atoms->m_iElementCount)+atoms->stride*static_cast<short>(violated);
        } else {
            entry.point=0;
            entry.properties=0;
        }
    }
    return BoolFlag(satisfied);
}

// @fnv 0x00d0f300
// src: XBOX_PDB 0x00d0f300
int hkLs_localizedSolveToi(const Limits& limits,Resources& resources,PairEvent& event,ResourceManager& callbacks,Scene* world,List<DynamicNode*>& active,StateTable& states,float timeStep) throw() {
    InlineList<SchemaRecord,64> records;
    int processed=0;
    SolverIsland* island;
    if(!event.bodies[0]->isFixed()) island=event.bodies[0]->GetSimulationIsland();
    else island=event.bodies[1]->GetSimulationIsland();
    ArenaList<DynamicNode*> touched(island->GetEntities().GetLogicalSize());
    if(!event.bodies[0]->isFixed()) {
        touched.pushBackUnchecked(event.bodies[0]);
        updateEntity(event.bodies[0],event.time);
        states[event.bodies[0]->m_usStorageIndex]=2;
    }
    if(!event.bodies[1]->isFixed()) {
        touched.pushBackUnchecked(event.bodies[1]);
        updateEntity(event.bodies[1],event.time);
        states[event.bodies[1]->m_usStorageIndex]=2;
    }
    InlineList<DynamicNode*,64> contacts;
    event.manager->confirm(event,timeStep,contacts);
    if(!contacts.GetLogicalSize()) {
        if(!event.bodies[0]->isFixed()) {
            DynamicNode* body0=event.bodies[0];
            hkMotionState* ms0=body0->getRigidMotion()->GetMotionState();
            restoreState(ms0);
        }
        if(!event.bodies[1]->isFixed()) {
            DynamicNode* body1=event.bodies[1];
            hkMotionState* ms1=body1->getRigidMotion()->GetMotionState();
            restoreState(ms1);
        }
        return 1;
    }
    DynamicNode* seeds[2];
    seeds[0]=contacts[0];
    seeds[1]=contacts.GetLogicalSize()>1?contacts[1]:0;
    if(0) TraceStream::GetMonitorStream().dontPrintf("sub.scr","SCR %f %s %s",event.time,event.bodies[0]->getName(),event.bodies[1]->getName());
    hkSolveUpload();

    hkpConstraintSolverResources_ProcessEntries_00d88670(resources,&touched[0],touched.GetLogicalSize());
    BoolFlag fresh=true;
    InlineList<DynamicNode*,64> moreTouched;
    InlineList<Constraint*,64> moreConstraints;
    for(int retries=limits.fullSteps;retries>0;--retries) {
        while(1) {
            moreConstraints.clear();
            moreTouched.clear();
            int checkpoint=processed;
            if(!fresh) {
                if(processed<records.GetLogicalSize()) {
                    contacts.clear();
                    Object_ProcessEntries_00d0cb00(resources,*world->input,records,checkpoint,limits.priority,states,touched,contacts);
                    if(!contacts.GetLogicalSize()) goto solveFull;
                } else goto solveFull;
            }
            hkLs_toiActivateEntitiesAndCheckConstraints(*world->getCollisionInputRw(),limits.priority,event.time,contacts,states,moreTouched,moreConstraints);
            fresh=false;
            int activeCount;
            if(!(hkpConstraintSolverSetup_internalIsMemoryOkForNewAccumulators(resources,moreTouched.begin(),moreTouched.GetLogicalSize()) &&
                CheckTotalsWithinLimits(resources,moreConstraints.begin(),moreConstraints.GetLogicalSize()) &&
                limits.constraints>=records.GetLogicalSize()+moreConstraints.GetLogicalSize() &&
                (activeCount=active.GetLogicalSize(),limits.entities>=activeCount+touched.GetLogicalSize()+moreTouched.GetLogicalSize()) &&
                limits.contacts>=activeCount+contacts.GetLogicalSize())) {
                if(0) TraceStream::GetMonitorStream().dontPrintf("sub-nomem","NO MEMORY");
                for(int i=0;i<contacts.GetLogicalSize();++i)states[contacts[i]->m_usStorageIndex]=8;

                for(int i=0;i<moreTouched.GetLogicalSize();++i)states[moreTouched[i]->m_usStorageIndex]=1;
                if(callbacks.overflow()==2) {
                    hkLs_backstepAndFreezeEntireIsland(event.time,island,states,active);
                    for(int i=0;i<active.GetLogicalSize();++i)hkpWorldAgentUtil_invalidateTim(active[i],*world->input);
                    active.clear();
                    return 0;
                }
                goto solveFull;
            }
            for(int i=0;i<contacts.GetLogicalSize();++i) if(0) TraceStream::GetMonitorStream().dontPrintf("sub-act","act ent:%s",contacts[i]->getName());
            hkpConstraintSolverResources_ProcessEntries_00d88670(resources,moreTouched.begin(),moreTouched.GetLogicalSize());

            hkpConstraintSolverSetup_internalAddJacobianSchemas(resources,moreConstraints.begin(),moreConstraints.GetLogicalSize(),records);
            processed=checkpoint;
            for(int i=0;i<touched.GetLogicalSize();++i) {
                if(states[touched[i]->m_usStorageIndex]==16)touched.removeAt(i--);
            }
            active.aiRecipeIndex(active.GetLogicalSize(),contacts.begin(),contacts.GetLogicalSize());
            touched.reserve(touched.GetLogicalSize()+moreTouched.GetLogicalSize());
            for(int i=0;i<moreTouched.GetLogicalSize();++i) {
                if(moreTouched[i]->getMotion()->getType()!=Motion::MOTION_KEYFRAMED)touched.pushBackUnchecked(moreTouched[i]);
            }
            PartitionMotionPairs(records,processed,moreConstraints.GetLogicalSize());
            hkLs_toiActivateConstraintsLinkingActivatedEntities(records,processed,states);
            hkpConstraintSolverSetup_subSolve(resources,1);
            if(0) TraceStream::GetMonitorStream().dontPrintf("sub.toi.inc","inc %d",int((reinterpret_cast<char*>(resources.m_akBufferStates[1].m_pTileTemplate)-reinterpret_cast<char*>(resources.m_akBufferStates[1].m_pRayStart))>>2));

            if(!moreConstraints.GetLogicalSize() && !moreTouched.GetLogicalSize())goto solveFull;
        }
solveFull:
        if(0) TraceStream::GetMonitorStream().dontPrintf("sub.toi.fulsol","c:%d a:%d t:%d",records.GetLogicalSize(),active.GetLogicalSize(),touched.GetLogicalSize());

        hkpConstraintSolverSetup_subSolve(resources,0);
    }
    UnsignedShortArray<Schema>& sc1=resources.m_akBufferStates[1];if(sc1.m_pRayStart!=sc1.m_pTileTemplate) {
        hkVector4_setRotatedDir_ProcessEntries_00d0bf30(resources,touched);
        BoolFlag satisfied=CollectMatchingEntries(resources,records,*world->input,0);
        if(!satisfied) {
            int tries=limits.extraSteps;
            UnsignedShortArray<Schema>& sc2=resources.m_akBufferStates[1];
            while(!satisfied && --tries>=0) {
                Object_UpdateFields_00d8aac0(*resources.m_pSolverInfo,sc2.m_pRayStart,resources.m_pVelocityAccumulatorA,resources.m_pBufferA);
                hkVector4_setRotatedDir_ProcessEntries_00d0bf30(resources,touched);
                satisfied=CollectMatchingEntries(resources,records,*world->input,0);
            }
        }
        if(!satisfied) {
            InlineList<Violation,32> violations;
            CollectMatchingEntries(resources,records,*world->input,&violations);
            if(callbacks.violations(violations)==2) {
                hkLs_backstepAndFreezeEntireIsland(event.time,island,states,active);
                for(int i=0;i<active.GetLogicalSize();++i)hkpWorldAgentUtil_invalidateTim(active[i],*world->input);
                active.clear();
                return 0;
            }
        }
    }
    if(!active.GetLogicalSize()) {
        active.aiRecipeIndex(0,seeds[0]);
        states[active[0]->m_usStorageIndex]=16;
        if(seeds[1]) {
            active.aiRecipeIndex(1,seeds[1]);
            states[active[1]->m_usStorageIndex]=16;
        }
    }
    for(int i=0;i<active.GetLogicalSize();++i) {
        hkMotionState* state=static_cast<DynamicNode*>(active[i])->getRigidMotion()->GetMotionState();
        hkSweptTransformUtil_backStepMotionState(event.time,*state);
    }
    hkpConstraintSolverSetup_oneStepIntegrate(*resources.m_pSolverInfo,*resources.m_pStepInfo,resources.m_pVelocityAccumulatorA,active.begin(),active.GetLogicalSize());
    UpdateIslandMotionStates(island,states,resources);
    for(int i=0;i<active.GetLogicalSize();++i)hkpWorldAgentUtil_invalidateTim(active[i],*world->getCollisionInputRw());
    if(0) TraceStream::GetMonitorStream().dontPrintf("sub.end","----");
    return 0;
}

namespace fnv_00d0d020 {
// FUN_00d0d020 - node-spawning constructor (thiscall, one Owner* argument).
//
// The class is a stand-in for the game's node-spawner:
//   +0x00 vptr (stored explicitly, NOT a real vptr - see below)
//   +0x10 a byte flag
//   +0x30 a {data, ?, capacity} holder, capacity has the top bit used as a flag
//   +0x3c a second {data, ?, capacity} holder
//   +0x48 the spawned node, +0x4c a counter
// The vtable pointer is modelled as a plain int member: the original stores
// 0x010cd45c with a plain `mov`, and a real vptr would drag in an EH frame
// (the base class has a non-trivial constructor) and a vtable whose bytes the
// checker would compare literally.
struct Allocator {
    virtual void v00();
    virtual void *Alloc(unsigned int bytes);
};

struct SpawnedNode {
    int unk00;
    unsigned short m_04;
    unsigned short unk06;
};

struct Owner {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int m_334;
};

extern int DAT_010cd45c;

hkMemoryRouter *__cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(Allocator *allocator, void *data, unsigned int capacity, unsigned int elemSize);

struct Stub_cf87c0 {
    void FUN_00cf87c0(Owner *a1);
};

struct Stub_cb1fe0 {
    void EnsureCapacity(void *a, int b);
};

struct Stub_d9fb90 {
    void *FUN_00d9fb90();
};

struct FUN_00d0d020_cls {
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char m_10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    void *m_30;
    int m_34;
    unsigned int m_38;
    void *m_3c;
    int m_40;
    unsigned int m_44;
    void *m_48;
    int m_4c;

    FUN_00d0d020_cls *InitializeFields_00d0d020(Owner *a1);
};

// @fnv 0x00d0d020
// src: GUESS 0x00d0d020 (confidence: low)
FUN_00d0d020_cls *FUN_00d0d020_cls::InitializeFields_00d0d020(Owner *apOwner) {
    // the base constructor (0x00cf87c0) takes the owner pointer as its argument
    ((Stub_cf87c0 *)this)->FUN_00cf87c0(apOwner);
    m_vptr = (int)&DAT_010cd45c;
    unsigned int zero = 0;
    // the two {data, ?, capacity} holders; the capacity's top bit is a flag
    unsigned int *arr = (unsigned int *)&m_30;
    arr[0] = zero;
    arr[1] = zero;
    arr[2] = 0x80000000u;
    unsigned int *arrB = (unsigned int *)&m_3c;
    arrB[0] = zero;
    arrB[1] = zero;
    arrB[2] = 0xffffffffu;
    hkMemoryRouter *h = hkMemoryRouter_getInstance();
    ((Stub_cb1fe0 *)&m_3c)->EnsureCapacity(h->m_heap, 0);
    m_10 = 1;
    hkMemoryRouter *h2 = hkMemoryRouter_getInstance();
    Allocator *al = reinterpret_cast<Allocator*>(h2->m_heap);
    SpawnedNode *node = (SpawnedNode *)al->Alloc(0x10);   // virtual call, vtable slot 1
    node->m_04 = 0x10;
    m_48 = ((Stub_d9fb90 *)node)->FUN_00d9fb90();
    m_4c = 0;
    int n = apOwner->m_334;
    hkMemoryRouter *h3 = hkMemoryRouter_getInstance();
    Allocator *al3 = reinterpret_cast<Allocator*>(h3->m_heap);
    int cap = (int)(arr[2] & 0x3fffffffu);
    if (cap < n) {
        // grow the array: the new capacity is max(needed, 2 * old)
        if (n < cap * 2) {
            n = cap * 2;
        }
        hkArrayUtil__reserve(al3, &m_30, n, 0x70);
    }
    return this;
}
}  // namespace fnv_00d0d020

template<class T> class ScanPointer {T p;public:__forceinline ScanPointer(){} __forceinline ScanPointer(T q):p(q){} __forceinline void operator=(T q){p=q;} __forceinline operator T()const{return p;} __forceinline T const& val()const{return p;}};
// Resolve an event and remove obsolete queued events.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern int DAT_01269200;
extern float DAT_0104f498;
extern float DAT_01016248;
extern char DAT_010cd540[];
extern char DAT_010cd534[];
extern char DAT_010cd520[];
extern char DAT_010cd514[];
extern char DAT_01076f38[];
void __cdecl hkString_memSet(void* p, int v, int n);
void __cdecl hkReferencedObject_addReferences(void* data, int size, int elem);
void __cdecl hkReferencedObject_removeReferences(void* data, int size, int elem);
typedef unsigned long DWORD;

struct ProfPairRec : ProfRec_hkpcontinuoussimulation {const char* m_subName;};
struct HeapObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct Node {
    int unk00; int unk04; int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
};
struct FlagIndex16 {
    unsigned short value;
    FlagIndex16(unsigned short v) : value(v) {}
    operator unsigned short() const { return value; }
};
struct FlagView {
    unsigned char* volatile data;
    const unsigned char& operator[](const FlagIndex16& index) const {
        return data[index];
    }
};
struct Owner {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    unsigned short m_uiEdgeIndex;
    unsigned short m_aa;
    int m_ac, m_b0, m_b4, m_b8, m_bc, m_c0, m_c4, m_c8;
    Island* m_cc;
    __forceinline Island* GetSimulationIsland() const { return m_cc; }
    __forceinline hkBool isFixed() const { return motion.type==5; }
    int m_d0, m_d4, m_d8, m_dc;
    CollisionMotion motion;
    int m_ec;
};
struct EventReleaseObj;
struct Entry70 {
    float time, separatingVelocity;
    int flags;
    Owner* bodies[2];
    EventReleaseObj* m_14;
    CollisionProperties properties;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    hkVector4 position, normal;
};
struct Arr70 {
    Entry70* m_data;
    int m_iElementCount;
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline Entry70& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int);
    int unk08; int unk0c; int unk10; int unk14;
    struct PhaseObj* m_phase;
    int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44;
};
struct PhaseObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int collide(void* a, void* b, void* q);
    virtual void v10();
    virtual void v14();
    virtual void v18(void* a, void* b, void* c);
};
struct CtrObj {
    int unk00; int unk04; int unk08;
    int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90;
    int m_ref94;
    int unk98;
    unsigned char m_9c;
    unsigned char unk9d; unsigned char unk9e; unsigned char unk9f;
    int unkA0;
    int m_a4;
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
struct Arg0 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74;
    void* m_78;
    __forceinline void* getInput() const { return m_78; }
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
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int m_1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int m_1e0;
    float hkpWorld_getCurrentPsiTime();
};
struct Elem {
    int unk00;
    int unk04;
    int m_08;
    void FUN_00c905b0();
};
struct PtrArr {
    Elem** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Elem* m_inline[64];
    __forceinline PtrArr() : m_data(m_inline),m_iElementCount(0),m_iCapacityState(0x80000040) {}
    __forceinline int GetLogicalSize() const {return m_iElementCount;}
    __forceinline Elem** begin() {return m_data;}
    __forceinline Elem*& operator[](int i) {return m_data[i];}
    __forceinline void clear() {m_iElementCount=0;}
    __forceinline void removeAt(int i) {--m_iElementCount;if(m_iElementCount!=i)m_data[i]=m_data[m_iElementCount];}
    __forceinline void dispose() {
        HeapObj* heap=(HeapObj*)hkMemoryRouter_getInstance()->m_heap;
        int cap=m_iCapacityState;
        m_iElementCount=0;
        if(cap>=0)heap->ReturnMemory(m_data,(cap&0x3fffffff)*4);
    }
};
struct EventReleaseObj {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void call20(Island* a, CollisionProperties* b);
};

struct BigObj {
    int unk00; int unk04; int unk08; int unk0c;
    hkVector4 m_v10;
    hkVector4 m_v20;
    int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; 
    float m_10c;
    float m_110;
    int m_114;
    int m_118;
    int m_11c;
    float m_120;
    int unk124, unk128, unk12c;
    void UpdateState_00d105b0(void* arg);
    void UpdateFields_00c90e60(float a, float b);
};
struct Times {
    float tA;
    float tB;
    float diff;
    float recip;
};
struct __declspec(align(16)) Obj2 {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; 
    void hkpConstraintQueryIn_set(void* big, float* tA, int v);
};
struct EventQuery {
    int mode;
    int budgetA,budgetB,budgetC;
    int limitA,limitB;
    int flagsA,flagsB;
    __forceinline EventQuery() {
        budgetA=1000;budgetB=1000;budgetC=1000;
        limitA=4;limitB=4;flagsA=0;flagsB=0;mode=3;
    }
};
struct SolverState {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct SolverFlagView {
    unsigned char* data;
    int debugSize;
    __forceinline SolverFlagView() {}
    __forceinline SolverFlagView(unsigned char* p,int) : data(p) {}
    __forceinline unsigned char* begin() { return data; }
    __forceinline unsigned char& operator[](int i) {return data[i];}
    __forceinline const unsigned char& operator[](int i) const {return data[i];}
};
struct ScopedFlags : SolverFlagView {
    __forceinline ScopedFlags(int n) {
        hkMemoryRouter* r=hkMemoryRouter_getInstance();
        unsigned char* p=(unsigned char*)r->m_stack.m_next.m_storage;
        r->m_stack.m_next.m_storage=p+((n+127)&~127);
        data=p;
    }
    __forceinline void dispose() {hkMemoryRouter_getInstance()->m_stack.m_next.m_storage=data;}
};
struct Self;

int __cdecl hkpConstraintSolverSetup_shutdownSolver(void* out);
int __cdecl InitializeConstraintSolverResources(float* f, BigObj* big, Obj2* o2, int a, int b, void* mid);
struct Self {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void notify(Elem**, int, void*, void*);
    int unk04; int unk08;
    CtrObj* m_ctr;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    Arr70 m_arr30;
    int pad7c; int pad80; int pad84; int pad88; int pad8c; int pad90; int pad94; int pad98; int pad9c; int pada0; int pada4; int pada8; int padac; int padb0; int padb4; int padb8; int padbc; int padc0; int padc4; int padc8; int padcc; int padd0; int padd4; int padd8; int paddc; int pade0; int pade4; int pade8; int padec; int padf0; int padf4; int padf8; int padfc; int pad100; int pad104; int pad108; int pad10c; int pad110; int pad114; int pad118; int pad11c; int pad120; int pad124; int pad128; int pad12c; int pad130; int pad134; int pad138; int pad13c; int pad140; int pad144; int pad148; int pad14c; int pad150; int pad154; int pad158; int pad15c; int pad160; int pad164; int pad168; int pad16c; int pad170; int pad174; int pad178; int pad17c; int pad180; int pad184; int pad188; int pad18c; int pad190; int pad194; int pad198; int pad19c; int pad1a0; int pad1a4; int pad1a8; int pad1ac; int pad1b0; int pad1b4;
    int m_1b8;
    int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0;
    void hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(Elem** data, int n, Arg0* a0, int z);
    __forceinline void process(Arg0*, Elem**, int, void*);
    __forceinline void release(Entry70&);
    __forceinline void scan(const Island*,const SolverFlagView&,Arr70&);
    void hkpContinuousSimulation_simulateToi(Arg0* a0, Entry70* pair, float fa, float fb);
};

static __forceinline void clockOne(const char* name) {
    hkMonitorStream& stream=*(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if(stream.m_end.m_storage<stream.m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* command=reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.m_end.m_storage);
        command->m_commandAndMonitor=name;
        static_cast<ProfRec_hkpcontinuoussimulation*>(command)->stamp();
        stream.m_end.m_storage=reinterpret_cast<char*>(command+1);
    }
}
static __forceinline void clockTwo(const char* name,const char* sub) {
    hkMonitorStream& stream=*(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if(stream.m_end.m_storage<stream.m_capacityMinus16.m_storage) {
        ProfPairRec* command=(ProfPairRec*)stream.m_end.m_storage;
        command->m_commandAndMonitor=name;command->m_subName=sub;
        static_cast<ProfRec_hkpcontinuoussimulation*>(command)->stamp();
        stream.m_end.m_storage=reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(command+1));
    }
}
static __forceinline void copyProbe(void* destination,const void* source) {
    unsigned i=0;
    do { static_cast<__int64*>(destination)[i]=static_cast<const __int64*>(source)[i]; } while(++i<14);
}
__forceinline void Arr70::removeAt(int index) {
    --m_iElementCount;
    if(m_iElementCount!=index)copyProbe(m_data+index,m_data+m_iElementCount);
}
__forceinline void Self::release(Entry70& event) {
    Island* island=!event.bodies[0]->isFixed()?event.bodies[0]->GetSimulationIsland():event.bodies[1]->GetSimulationIsland();
    event.m_14->call20(island,&event.properties);
}
__forceinline void Self::scan(const Island* island,const SolverFlagView& flags,Arr70& events) {
    ScanPointer<Entry70*> data;
    for(int i=events.GetLogicalSize()-1;i>=0;--i) {
        data=events.m_data;
        Entry70& event=((Entry70*)data)[i];
        if((event.bodies[0]->GetSimulationIsland()==island && flags[event.bodies[0]->m_uiEdgeIndex]==16) ||
           (event.bodies[1]->GetSimulationIsland()==island && flags[event.bodies[1]->m_uiEdgeIndex]==16)) {
            release(events[i]);
            --events.m_iElementCount;
            if(events.m_iElementCount!=i){data=events.m_data;copyProbe((Entry70*)data+i,(Entry70*)data+events.m_iElementCount);}
        }
    }
}
__forceinline void Self::process(Arg0* world,Elem** data,int count,void* input) {
    if(count) {
        hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(data,count,world,0);
        if(DAT_01269200!=1)notify(data,count,input,&m_arr30.unk0c);
    }
}
static __forceinline void prepareProbe(Arg0* world,const Entry70& event,float delta,Times& step,BigObj& solver,Obj2& input) {
    step.tA=event.time;
    step.tB=world->hkpWorld_getCurrentPsiTime();
    step.diff=step.tB-step.tA;
    step.recip=1.0f/step.diff;
    solver.UpdateState_00d105b0(&world->m_1e0);
    solver.m_114=1;
    solver.m_120=1.0f;
    solver.m_118=1;
    solver.m_120=1.0f;
    solver.m_10c=delta;
    solver.m_110=1.0f/delta;
    solver.m_v10.m_vComponents=_mm_setzero_ps();
    solver.m_v20.m_vComponents=_mm_setzero_ps();
    solver.UpdateFields_00c90e60(DAT_01016248,DAT_0104f498);
    input.hkpConstraintQueryIn_set(&solver,&step.tA,world->m_1b8);
}
int __cdecl hkLs_localizedSolveToi(const EventQuery&,SolverState&,Entry70&,PhaseObj&,Arg0*,PtrArr&,SolverFlagView&,float);

struct SolveConstraint;
struct SolveSchemaInfo {SolveConstraint* constraint;void* schema;float depth;};

void __cdecl reserveSolveArray(HeapObj&,void*,int,int);
template<class T> struct SolveArray {
    T* data;int size,capacity;
    __forceinline SolveArray():data(0),size(0),capacity(0x80000000){}
    __forceinline ~SolveArray(){if(capacity>=0)((HeapObj*)hkMemoryRouter_getInstance()->m_heap)->ReturnMemory(data,(capacity&0x3fffffff)*sizeof(T));}
    __forceinline int GetLogicalSize()const{return size;}
    __forceinline T* begin(){return data;}
    __forceinline T& operator[](int i){return data[i];}
    __forceinline const T& operator[](int i)const{return data[i];}
    __forceinline void clear(){size=0;}
    __forceinline void reserve(int n){if(n>(capacity&0x3fffffff))reserveSolveArray(*(HeapObj*)hkMemoryRouter_getInstance()->m_heap,this,n,sizeof(T));}
    __forceinline void pushBackUnchecked(const T& v){data[size++]=v;}
    __forceinline void AddBack(const T& v){reserve(size+1);pushBackUnchecked(v);}
    __forceinline void removeAt(int i){--size;if(size!=i)data[i]=data[size];}
    __forceinline void aiRecipeIndex(int i,const T* values,int count){reserve(size+count);for(int j=size-1;j>=i;--j)data[j+count]=data[j];for(int j=0;j<count;++j)data[i+j]=values[j];size+=count;}
    __forceinline void aiRecipeIndex(int i,const T& value){aiRecipeIndex(i,&value,1);}
};
template<class T,int N> struct SolveInlineArray:SolveArray<T> {
    T storage[N];
    __forceinline SolveInlineArray(){this->data=storage;this->capacity=N|0x80000000;}
};
template<class T> struct SolveLocalArray:SolveArray<T> {
    T* allocation;
    __forceinline SolveLocalArray(int n){hkMemoryRouter* r=hkMemoryRouter_getInstance();allocation=(T*)r->m_stack.m_next.m_storage;r->m_stack.m_next.m_storage=(void*)(static_cast<char*>(r->m_stack.m_next.m_storage)+((n*sizeof(T)+127)&~127));this->data=allocation;this->capacity=n|0x80000000;}
    __forceinline ~SolveLocalArray(){if(this->data==allocation)this->clear();hkMemoryRouter_getInstance()->m_stack.m_next.m_storage=allocation;}
};
struct SolveBufferState {void* begin;void* end;void* current;void* processed;};
struct SolveStateView {
    Times* step;BigObj* solver;Obj2* query;
    void* accumulators;void* accumulatorsEnd;void* accumulatorsCurrent;
    void* backups;void* backupsEnd;
    SolveBufferState schemas[2];
    void* temporaries;void* temporariesEnd;void* temporariesCurrent;void* temporariesProcessed;
};
struct SolveContact {
    virtual void f00();virtual void f04();virtual void f08();virtual void f0c();
    virtual void f10();virtual void f14();virtual void f18();virtual void f1c();
    virtual void f20();virtual void f24();virtual void f28();virtual void f2c();
    virtual void f30();virtual void f34();virtual void f38();virtual void f3c();
    virtual void f40();virtual void f44();
    virtual void solve(Entry70&,float,SolveArray<Owner*>&);
};
struct SolveControl {
    virtual void f00();virtual void f04();virtual void f08();virtual void f0c();
    virtual int GetViolations(SolveArray<SolveViolation>&);
    virtual int outOfMemory();
};
void __cdecl updateSolveTransform(Owner*,float);
void __cdecl projectSolveTransform(Owner*);
void __cdecl validateSolveConstraints(SolverState&,void*,SolveArray<SolveSchemaInfo>&,int&,int,SolverFlagView&,const SolveArray<Owner*>&,SolveArray<Owner*>&);
void __cdecl activateSolveEntities(void*,int,float,const SolveArray<Owner*>&,SolverFlagView&,SolveArray<Owner*>&,SolveArray<SolveConstraint*>&);
hkBool __cdecl canAddSolveBodies(SolverState&,Owner**,int);
hkBool __cdecl canAddSolveConstraints(SolverState&,SolveConstraint**,int);
void __cdecl addSolveAccumulators(SolverState&,Owner*const*,int);
void __cdecl addSolveSchemas(SolverState&,SolveConstraint**,int,SolveArray<SolveSchemaInfo>&);
void __cdecl freezeSolveIsland(float,Island*,SolverFlagView&,SolveArray<Owner*>&);
void __cdecl invalidateSolveBody(Owner*,void*);
void __cdecl activateSolveFixed(SolveArray<SolveSchemaInfo>&,int&,int);
void __cdecl activateSolveLinked(SolveArray<SolveSchemaInfo>&,int&,SolverFlagView&);
void __cdecl solveStep(SolverState&,int);
void __cdecl resetSolveAccumulators(SolverState&,const SolveArray<Owner*>&);
hkBool __cdecl validateCriticalSolve(SolverState&,const SolveArray<SolveSchemaInfo>&,void*,SolveArray<SolveViolation>*);
void __cdecl stepSolveJacobians(BigObj*,void*,void*,void*);
void __cdecl finishSolveStep(SolverState&);
void __cdecl backstepSolveBody(Owner*,float);
void __cdecl integrateSolveBodies(BigObj&,Times&,const void*,Owner*const*,int);
void __cdecl restoreSolveTransforms(Island*,SolverFlagView&,SolverState&);

// src: XBOX_PDB 0x00d0f300
__declspec(noinline) int __cdecl hkLs_localizedSolveToi(const EventQuery& query,SolverState& state,Entry70& event,PhaseObj& phase,Arg0* world,PtrArr& output,SolverFlagView& inputflags,float rotation)
{
    SolverFlagView flags(inputflags.begin(),0);
    SolveStateView& resources=(SolveStateView&)state;
    SolveArray<Owner*>& active=(SolveArray<Owner*>&)output;
    SolveControl& control=(SolveControl&)phase;
    SolveInlineArray<SolveSchemaInfo,64> constraints;
    int boundary=0;
    Island* island=!event.bodies[0]->isFixed()?event.bodies[0]->GetSimulationIsland():event.bodies[1]->GetSimulationIsland();
    SolveLocalArray<Owner*> touched(island->m_iActorEntryCount);
    if(!event.bodies[0]->isFixed()) {
        touched.pushBackUnchecked(event.bodies[0]);
        updateSolveTransform(event.bodies[0],event.time);
        flags[event.bodies[0]->m_uiEdgeIndex]=2;
    }
    if(!event.bodies[1]->isFixed()) {
        touched.pushBackUnchecked(event.bodies[1]);
        updateSolveTransform(event.bodies[1],event.time);
        flags[event.bodies[1]->m_uiEdgeIndex]=2;
    }
    SolveInlineArray<Owner*,64> pending;
    ((SolveContact*)event.m_14)->solve(event,rotation,pending);
    if(!pending.GetLogicalSize()) {
        if(!event.bodies[0]->isFixed())projectSolveTransform(event.bodies[0]);
        if(!event.bodies[1]->isFixed())projectSolveTransform(event.bodies[1]);
        return 1;
    }
    Owner* initialA=pending[0];
    Owner* initialB=pending.GetLogicalSize()>1?pending[1]:0;
    flags[initialA->m_uiEdgeIndex]=6;
    if(initialB)flags[initialB->m_uiEdgeIndex]=6;
    addSolveAccumulators(state,&touched[0],touched.GetLogicalSize());
    hkBool preset(true);
    SolveInlineArray<Owner*,64> additional;
    SolveInlineArray<SolveConstraint*,64> extraConstraints;
    for(int steps=query.limitA;steps>0;--steps) {
        for(;;) {
            extraConstraints.clear();additional.clear();
            int nextBoundary=boundary;
            if(!preset) {
                if(boundary<constraints.GetLogicalSize()) {
                    pending.clear();
                    validateSolveConstraints(state,world->getInput(),constraints,nextBoundary,query.mode,flags,touched,pending);
                    if(!pending.GetLogicalSize())break;
                }else break;
            }
            activateSolveEntities(world->getInput(),query.mode,event.time,pending,flags,additional,extraConstraints);
            preset=false;
            if(!canAddSolveBodies(state,additional.begin(),additional.GetLogicalSize()) ||
               !canAddSolveConstraints(state,extraConstraints.begin(),extraConstraints.GetLogicalSize()) ||
               query.budgetC<constraints.GetLogicalSize()+extraConstraints.GetLogicalSize() ||
               query.budgetA<active.GetLogicalSize()+touched.GetLogicalSize()+additional.GetLogicalSize() ||
               query.budgetB<active.GetLogicalSize()+pending.GetLogicalSize()) {
                for(int i=0;i<pending.GetLogicalSize();++i)flags[pending[i]->m_uiEdgeIndex]=8;
                for(int i=0;i<additional.GetLogicalSize();++i)flags[additional[i]->m_uiEdgeIndex]=1;
                int response=control.outOfMemory();
                if(response==2) {
                    freezeSolveIsland(event.time,island,flags,active);
                    for(int i=0;i<active.GetLogicalSize();++i)invalidateSolveBody(active[i],world->getInput());
                    active.clear();return 0;
                }
                break;
            }
            addSolveAccumulators(state,additional.begin(),additional.GetLogicalSize());
            addSolveSchemas(state,extraConstraints.begin(),extraConstraints.GetLogicalSize(),constraints);
            boundary=nextBoundary;
            for(int i=0;i<touched.GetLogicalSize();++i)if(flags[touched[i]->m_uiEdgeIndex]==16)touched.removeAt(i--);
            active.aiRecipeIndex(active.GetLogicalSize(),pending.begin(),pending.GetLogicalSize());
            touched.reserve(touched.GetLogicalSize()+additional.GetLogicalSize());
            for(int i=0;i<additional.GetLogicalSize();++i)if(additional[i]->motion.type!=4)touched.pushBackUnchecked(additional[i]);
            activateSolveFixed(constraints,boundary,extraConstraints.GetLogicalSize());
            activateSolveLinked(constraints,boundary,flags);
            solveStep(state,1);
            if(!extraConstraints.GetLogicalSize() && !additional.GetLogicalSize())break;
        }
        solveStep(state,0);
    }
    if(resources.schemas[1].begin!=resources.schemas[1].current) {
        resetSolveAccumulators(state,touched);
        hkBool satisfied=validateCriticalSolve(state,constraints,world->getInput(),0);
        if(!satisfied) {
            int retries=query.limitB;
            while(!satisfied && --retries>=0) {
                stepSolveJacobians(resources.solver,resources.schemas[1].begin,resources.accumulators,resources.temporaries);
                resetSolveAccumulators(state,touched);
                satisfied=validateCriticalSolve(state,constraints,world->getInput(),0);
            }
        }
        if(!satisfied) {
            SolveInlineArray<SolveViolation,32> violated;
            validateCriticalSolve(state,constraints,world->getInput(),&violated);
            int response=control.GetViolations(violated);
            if(response==2) {
                freezeSolveIsland(event.time,island,flags,active);
                for(int i=0;i<active.GetLogicalSize();++i)invalidateSolveBody(active[i],world->getInput());
                active.clear();return 0;
            }
        }
    }
    finishSolveStep(state);
    if(!active.GetLogicalSize()) {
        active.aiRecipeIndex(0,initialA);flags[active[0]->m_uiEdgeIndex]=16;
        if(initialB){active.aiRecipeIndex(1,initialB);flags[active[1]->m_uiEdgeIndex]=16;}
    }
    for(int i=0;i<active.GetLogicalSize();++i)backstepSolveBody(active[i],event.time);
    integrateSolveBodies(*resources.solver,*resources.step,resources.accumulators,active.begin(),active.GetLogicalSize());
    restoreSolveTransforms(island,flags,state);
    for(int i=0;i<active.GetLogicalSize();++i)invalidateSolveBody(active[i],world->getInput());
    return 0;
}

// @fnv 0x00d100a0
// src: XBOX_PDB 0x00d100a0
void Self::hkpContinuousSimulation_simulateToi(Arg0* world,Entry70* pair,float delta,float rotation) {
    Entry70& event=*pair;
    EventQuery query;
    if(m_arr30.m_phase->collide(&event,&m_arr30,&query)==1)return;
    ++m_ctr->m_ref94;
    PtrArr active;
    {
        Times step;
        BigObj solver;
        Obj2 input;
        prepareProbe(world,event,delta,step,solver,input);
        SolverState state;
        InitializeConstraintSolverResources(&step.tA,&solver,&input,query.flagsA,query.flagsB,&state);
        clockTwo(DAT_010cd540,DAT_010cd534);
        Island* island=!event.bodies[0]->isFixed()?event.bodies[0]->GetSimulationIsland():event.bodies[1]->GetSimulationIsland();
        int count=island->m_iActorEntryCount;
        ScopedFlags flags(count);
        hkString_memSet(flags.begin(),0,count);
        int result=hkLs_localizedSolveToi(query,state,event,*m_arr30.m_phase,world,active,flags,rotation);
        hkpConstraintSolverSetup_shutdownSolver(&state);
        release(event);
        if(result==0) {
            scan(island,flags,m_arr30);
            hkReferencedObject_addReferences(active.begin(),active.GetLogicalSize(),4);
        }else active.clear();
        flags.dispose();
    }
    m_arr30.m_phase->v18(&event,&m_arr30,&query);
    clockOne(DAT_010cd520);
    clockOne(DAT_010cd514);
    if(active.GetLogicalSize()) {
        for(int i=active.GetLogicalSize()-1;i>=0;--i) {
            Elem* entity=active[i];
            if(entity->m_08==0){active.removeAt(i);entity->FUN_00c905b0();}
        }
        process(world,active.begin(),active.GetLogicalSize(),world->getInput());
        hkReferencedObject_removeReferences(active.begin(),active.GetLogicalSize(),4);
    }
    CtrObj* c=m_ctr;
    if(--c->m_ref94==0 && !c->m_9c) {
        if(c->unk8c)c->FUN_00c91120();
        if(c->m_a4==1 && c->unk90)c->UpdateFields_00c91140();
    }
    clockOne(DAT_01076f38);
    hkMemoryRouter* router3=hkMemoryRouter_getInstance();
    HeapObj* heap=(HeapObj*)router3->m_heap;
    int cap=active.m_iCapacityState;
    active.m_iElementCount=0;
    if(!(cap&0x80000000))heap->ReturnMemory(active.m_data,(cap&0x3fffffff)*4);
}

extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
struct AdvanceSimulation;
struct Res { DWORD unk; };

struct hkTimeSection {
    volatile DWORD* tick;
    __forceinline hkTimeSection(const char* name, volatile DWORD& ticks) throw() : tick(&ticks) {
        hkMonitorStream* b = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (b->m_end.m_storage < b->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(b->m_end.m_storage);
            r->m_commandAndMonitor = name;
            _ReadWriteBarrier();
            *tick = (DWORD)__rdtsc();
            r->m_time0 = *tick;
            b->m_end.m_storage = reinterpret_cast<char*>(r + 1);
        }
    }
    __forceinline ~hkTimeSection() throw() {
        hkMonitorStream* b = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (b->m_end.m_storage < b->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(b->m_end.m_storage);
            r->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            *tick = (DWORD)__rdtsc();
            r->m_time0 = *tick;
            b->m_end.m_storage = reinterpret_cast<char*>(r + 1);
        }
    }
};
struct OuterTimeSection {
    bool ordered;
    volatile DWORD* tick;
    __forceinline OuterTimeSection(const char* name, volatile DWORD& ticks) throw() : ordered(false), tick(&ticks) {
        hkMonitorStream* b = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (b->m_end.m_storage < b->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(b->m_end.m_storage);
            r->m_commandAndMonitor = name;
            _ReadWriteBarrier();
            *tick = (DWORD)__rdtsc();
            r->m_time0 = *tick;
            b->m_end.m_storage = reinterpret_cast<char*>(r + 1);
        }
    }
    __forceinline ~OuterTimeSection() throw() {
        hkMonitorStream* b = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (b->m_end.m_storage < b->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(b->m_end.m_storage);
            r->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            *tick = (DWORD)__rdtsc();
            r->m_time0 = *tick;
            b->m_end.m_storage = reinterpret_cast<char*>(r + 1);
        }
        if (ordered) { _ReadWriteBarrier(); }
    }
};

struct AdvanceSimulation {
    DWORD unk00,unk04,unk08,unk0C,unk10;
    float m_f14;
    DWORD unk18,unk1C,unk20,unk24;
    Res* m_p28;
    DWORD unk2C,unk30;
    DWORD m_34;
    Res* hkpSimulation_reCollideAfterStepFailure() throw();
    float GetClampedSimulationTime() throw();
    Res* hkpContinuousSimulation_handleAllToisTill(float f) throw();
    Res* hkpContinuousSimulation_advanceTimeInternal();
};

// Under timers, calls FUN_00cf8820 if m_p28 is set, else FUN_00d0e9c0 when m_34 is set; returns the Res found, or clears m_p28 and returns null.
// @fnv 0x00d0ed10
// src: HAVOK_LIB 0x00d0ed10
Res* AdvanceSimulation::hkpContinuousSimulation_advanceTimeInternal()
{
    volatile DWORD ticks;
    union Value { float delta; volatile DWORD lastTick; };
    Value v;
    OuterTimeSection secPhysics("TtPhysics", ticks);
    if (m_p28) {
        hkTimeSection secCollide("TtreCollideAfterStepFailure", ticks);
        Res* q = hkpSimulation_reCollideAfterStepFailure();
        if (q) { secPhysics.ordered = true; return q; }
    }
    {
        v.delta = GetClampedSimulationTime();
        if (m_34) {
            hkTimeSection secTOI("TtTOIs", ticks);
            Res* p = hkpContinuousSimulation_handleAllToisTill(v.delta);
            if (p) {
                m_p28 = p;
                return p;
            }
        }
        m_p28 = 0;
        m_f14 = v.delta;
        secPhysics.tick = &v.lastTick;
        return 0;
    }

}

struct Holder_cls {
    unsigned char unk00[0x10];
    void* m_pAllocator;
};

struct Calc_cls {
    float Get();
};

struct ArrayRef_cls {
    int* m_pData;
    int m_iArrayLength;
    unsigned int m_iFlags;
};

struct Flags_cls {
    char* m_pBytes;
    unsigned char unk04[0xc];
    void* m_pHolder;
};

extern "C" void _ReadWriteBarrier(void);
extern "C" void __cdecl ResizeAudioStream(void* allocator, ArrayRef_cls* arr, int n);

// For each item of owner calls FUN_00cf1b10(a1), appends it to arr once, copies two 16-byte blocks, and sets sub+0x4c to a1 and sub+0x5c to 1/(Get()-a1).
// @fnv 0x00d0cde0
// src: XBOX_PDB 0x00d0cde0
void __cdecl hkLs_backstepAndFreezeEntireIsland(float a1, char* owner, Flags_cls* flags, ArrayRef_cls* arr)
{
    int i = 0;
    if (*(int*)(owner + 0x4c) <= 0) {
        return;
    }
    do {
        char* item = (char*)(*(int**)(owner + 0x48))[i];
        char* sub = item + 0xf0;
        hkSweptTransformUtil_backStepMotionState(a1, sub);
        if (flags->m_pBytes[i] != 0x10) {
            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            if (arr->m_iArrayLength == (int)(arr->m_iFlags & 0x3fffffff)) {
                ResizeAudioStream((void*)holder->m_heap, arr, 4);
            }
            int* slot = &arr->m_pData[arr->m_iArrayLength];
            int value = (int)item;
            _ReadWriteBarrier();
            *slot = value;
            arr->m_iArrayLength++;
            flags->m_pBytes[i] = 0x10;
        }
        *(LocalM128*)(sub + 0x40) = *(LocalM128*)(sub + 0x50);
        *(LocalM128*)(sub + 0x60) = *(LocalM128*)(sub + 0x70);
        *(volatile float*)(sub + 0x4c) = a1;
        float y = ((Calc_cls*)*(void**)(owner + 0x18))->Get();
        *(float*)(sub + 0x5c) = 1.0f / (y - a1);
        i++;
    } while (i < *(int*)(owner + 0x4c));
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
