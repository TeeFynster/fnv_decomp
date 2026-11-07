#include "../../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// Retain the original intrinsic lanes: byte-array lanes cause VC9 to add /GS cookies.
#define _INCLUDED_MM2
// Exe 0x00d0db40 FUN_00d0db40: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_add_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_sub_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 _A, LocalM128 _B, unsigned int _Imm8);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_movelh_ps(LocalM128 _A, LocalM128 _B);
extern "C" LocalM128 _mm_movehl_ps(LocalM128 _A, LocalM128 _B);

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/Pair.h"
#include "../../../../../../../include/QuantizedFloat8.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
// A unit-local view: the original has two differently shaped bodies for this member.
struct TimerCommand_ctsim : hkMonitorStream::TimerCommand { void setTime(); };
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/NiPoint3.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkContactPointMaterial.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../include/hkStringPtr.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpBroadPhaseHandle.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../../include/hkpConstraintOwner.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkpKeyframedRigidMotion.h"
#include "../../../../../../../include/hkpMaterial.h"
#include "../../../../../../../include/hkpMaxSizeMotion.h"
#include "../../../../../../../include/hkpMotion.h"
#include "../../../../../../../include/hkpRigidBody.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSimulation.h"
#include "../../../../../../../include/hkpSimulationIsland.h"
#include "../../../../../../../include/hkpTypedBroadPhaseHandle.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkpWorldCinfo.h"

// Keep the original inline implementations beside their shared declarations.
inline hkpCollisionDispatcher*hkpWorld::getCollisionDispatcher()const
{
;
return static_cast<hkpCollisionDispatcher*>(m_pDispatcher);
}
__forceinline void hkpWorld::lockCriticalOperations()
{
;
m_iCriticalOperationsLockCount++;
;
}
__forceinline void hkpWorld::unlockCriticalOperations()
{
;
m_iCriticalOperationsLockCount--;
;
}
__forceinline void hkpWorld::attemptToExecutePendingOperations(bool executeBodyOperations)
{
if(!m_iCriticalOperationsLockCount&&!m_bBlockExecutingPendingOperations)
{
if(m_iPendingOperationCount)
{
ExecutePendingOperations();
}
if(m_iPendingOperationQueueCount==1&&executeBodyOperations)
{
if(m_iQueuedOperationCount)
{
ExecutePendingOperationQueues();
}
}
}
}
__forceinline void hkpWorld::unlockAndAttemptToExecutePendingOperations()
{
unlockCriticalOperations();
attemptToExecutePendingOperations();
}

__forceinline hkpCollisionQualityInfo* hkpCollisionDispatcher::getCollisionQualityInfo(CollisionQualityIndex index)
{
    return &m_pCollisionQualityInfo[index];
}
inline const float& hkVector4::operator()(int index) const { return reinterpret_cast<const float*>(&m_vComponents)[index]; }
inline hkQuaternion::hkQuaternion() {}
inline QuantizedFloat8::QuantizedFloat8() {}
inline hkContactPointMaterial::hkContactPointMaterial() {}
template <typename TYPE>
inline void hkMemoryAllocator::_bufFree(void* p, int numElem) { bufFree(p, numElem * sizeof(TYPE)); }
inline void* hkpCollidable::getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_iOwnerOffset); }
// src/havok/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/dynamics/world/simulation/continuous/hkpcontinuoussimulation.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


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
void hkLs_toiActivateConstraintsLinkingActivatedEntities(S_00d0c6d0_EntryArray* aEntries, int* aIndex, S_00d0c6d0_ByteArray* table);
struct Base { void hkpSimulation_resetCollisionInformationForEntities(int*, int, int, unsigned int); };
struct Object : Base {
    void hkpContinuousSimulation_removeToiEventsOfEntities(int*, int);
    void hkpContinuousSimulation_removeToiEventsOfEntity(int);
    void ProcessEntries(int*, int, int, unsigned int);
};
extern int DAT_010cd45c;
struct Callback { virtual void Invoke(int value); };
struct Receiver {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Invoke(void* data, unsigned int size);
};
struct Manager { int unk00; int unk04; int unk08; int unk0c; int unk10; };
Manager* __cdecl hkMemoryRouter_getInstance();
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
void __cdecl InitAndDispatch();
struct S_00d0f2e0
{
    void* hkpSimulation_processAgentsOfEntities(void* a, void* b, void* c, void (__cdecl *pfnCallback)(), int iFlags);
    void* hkpContinuousSimulation_collideEntitiesNarrowPhaseContinuous(void* a, void* b, void* c);
};
struct World {
 hkStepInfo& time(){return *reinterpret_cast<hkStepInfo*>(reinterpret_cast<char*>(this)+80);}
};

struct Body { unsigned char& motion(){return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+232);} void* state(){return reinterpret_cast<char*>(this)+240;} };
void __cdecl hkSweptTransformUtil_backStepMotionState(float,void*);
void __cdecl hkRigidMotionUtilStep(hkStepInfo*,Body**,int,int);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(World*,Body**,int);
struct Controller {
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void process(Body**,int,hkpWorld*,int);
 int flags,kind,capacity,mode;float start,end;
 void hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(Body**,int,hkpWorld*,int);
 void hkpContinuousSimulation_collideEntitiesNarrowPhaseContinuous(Body**,int,World*);
 void ProcessBodies(Body**,int,hkpWorld*,int);
};
struct SpawnedObject
{
    unsigned int unkD4_dummy;
};
bool *__cdecl IsLessByUnkD4(bool *pbResult, SpawnedObject *pObjectA, SpawnedObject *pObjectB);
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

hkBool __cdecl CompareItemPriority(const Item* apItemA, const Item* apItemB);
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
int __cdecl hkLs_areVelocitiesOk(float scale, FUN_00d0bd30_p* pParams, float* pafValues, int aiCount, char** ppTable);
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
void UpdateIslandMotionStates(Island* island, ByteArray* flags, SolverInfo* info);
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
unsigned char* __cdecl CollectMatchingEntries(unsigned char* pResult, SrcA* pSrc, NiPoint3* pVec, int a4, NiPoint3* dst);
struct S_00d0d150_Vector4 {
    LocalM128 m_vComponents;
    void operator=(const S_00d0d150_Vector4& v) { m_vComponents = v.m_vComponents; }
};
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


struct S_00d0d150_Entity;
struct S_00d0d150_AgentNnEntry {
    int unk00;
    int unk04;
    void* m_pContactManager;
    signed char m_cAgentType;
    char unk0d;
    char unk0e;
    char unk0f;
    hkpCollidable* m_kCollidable[2];
};
struct S_00d0d150_Properties {
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    int unk08;
    int unk0c;
    int unk10;
    S_00d0d150_Properties() { m_fAccumulatedImpulse = 0.0f; m_fImpulseLimit = 0.0f; }
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
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
};
struct S_00d0d150_ProcessCdPoint {
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
    int m_usContactPointId;
    int unk24;
    int unk28;
    int unk2c;
};
struct S_00d0d150_ToiInfo {
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
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
    hkpWorld* m_pOwningWorld;
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
void hkVector4_setRotatedDir_ProcessEntries_00d0bf30(World_b2089* world, EntryList_b2089* pEntries);
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
void __cdecl ProcessCollisionEvent(void* context, CollisionEvent* event, float deltaTime, CollisionQueue* queue);
// expanded integer AABB into thread-stack local arrays, add them to the 3-axis sweep, then remove duplicate pairs.
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" void _mm_prefetch(char const* p, int hint);
extern unsigned long DAT_0126835c;
extern char DAT_010cc624[];
// "LtBroadPhase"
extern char DAT_010cd3e8[];
// "StGatherAabbs"
extern char DAT_010cc5fc[];
// "St3AxisSweep"
extern char DAT_010cc5f0[];
// "StRemoveDup"
extern char DAT_01076f38[];
// "lt"


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
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(s->m_end.val());
        h->m_commandAndMonitor = name;
        h->m_nameOfFirstSplit = firstSub;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}
static inline void TimerCommandD0Write(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage) {
        TimerCommand_ctsim* h = reinterpret_cast<TimerCommand_ctsim*>(s->m_end.val());
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}
static inline void* AllocateStackD0(int nbytes)
{
    Manager* mem = hkMemoryRouter_getInstance();
    void* p = (void*)mem->unk00;
    mem->unk00 += (nbytes + 127) & ~127;
    return p;
}
static inline void FreeStackD0(void* p)
{
    hkMemoryRouter_getInstance()->unk00 = (int)p;
}
void __stdcall UpdateBroadPhasePairs(CollidableD0** collidables, int numCollidables, hkpWorld* world, PairArrayD0& newPairs, PairArrayD0& delPairs);
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
struct RouterL {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HeapL* m_pStreamAllocator;
    HeapL& heap() { return *m_pStreamAllocator; }
};
RouterL* GetRouterL() throw();
void ReserveMoreL(HeapL& alloc, void* arr, int elemSize) throw();
template <typename T> inline void ConstructWithCopyL(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }
template <class T> struct ArrL {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ArrL() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~ArrL() { _clearAndDeallocate(GetRouterL()->heap()); }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void _clearAndDeallocate(HeapL& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
    }
    void _pushBack(HeapL& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ReserveMoreL(alloc, this, sizeof(T));
        ConstructWithCopyL<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(const T& t) { _pushBack(GetRouterL()->heap(), t); }
    T& operator[](int i) { return m_data[i]; }
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
    void Collect(ArrL<ItemPairL>* out) throw();
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
void CollectUnsaturatedObjects(SrcL* pSource, int level, float fValue, unsigned char** ppFlags, ArrL<ObjL*>* out);
void __stdcall nullsub_66(int, int, int);
void __stdcall nullsub_67(int a);
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
void PartitionMotionPairs(PairEntryArray* apEntryArray, int* apiFixedCount, int index);
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
// FUN_00d0ef40 v1 - Havok collide step: monitor ticks, reverse vcall loop, two ctx array loops
extern char DAT_010cc64c[];
// TtCollide
extern char DAT_010cc634[];
// TtIslandPostCollideCb
extern char DAT_010c41f8[];
// Et
extern int DAT_01269200;
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
    hkStepInfo m_50;
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
    void setTimes(float scale, const hkStepInfo& step) { m_10c = scale * step.m_fTimeStep; m_110 = (float)m_114 * step.m_fInverseDeltaTime; }
};

void __cdecl hkpWorldCallbackUtil_fireIslandPostCollideCallback(hkpWorld*, BodyL*, hkStepInfo*);
template<int Mode> static inline void TickWrite(const char* name, volatile unsigned int& t)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand) {
        TimerCommand_ctsim* h = reinterpret_cast<TimerCommand_ctsim*>(s->m_kRayEnd.val());
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        if (Mode == 1) _ReadBarrier();
        if (Mode == 2) _WriteBarrier();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void ReleaseCtx(hkpWorld* c)
{
    --c->m_iCriticalOperationsLockCount;
    if (c->m_iCriticalOperationsLockCount != 0) return;
    if (c->m_bBlockExecutingPendingOperations != 0) return;
    if (c->m_iPendingOperationCount) c->FUN_00c91120();
    if (c->m_iPendingOperationQueueCount != 1) return;
    if (c->m_iQueuedOperationCount) c->UpdateFields_00c91140();
}
struct ThisFull {
    int m_00; int m_04; int m_08;
    hkpWorld* m_0c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int m_28; int m_2c;
    Elem70* m_30; int m_34;
    void hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(void*, int, hkpWorld*, int);
    void hkpContinuousSimulation_collideIslandNarrowPhaseContinuous(BodyL*, void*);
};
union StepArg { hkStepInfo* step; volatile unsigned int tick; };
void __fastcall hkpContinuousSimulation_collideInternal(ThisFull* th, void* edx_unused, StepArg arg);
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
void __stdcall hkpContinuousSimulation_processAgentNnEntries(ThingX** apEntries, int aiCount, ThingP* apP, int aiValue, bool abAlt);
typedef unsigned long DWORD;
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
// hkMonitorStream TLS slot


static inline void S_00d0e210_Timer(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage) {
        TimerCommand_ctsim* h = reinterpret_cast<TimerCommand_ctsim*>(s->m_end.val());
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_time0 = *(volatile unsigned int*)&t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}


template <class T>
static __forceinline void S_00d0e210_Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void S_00d0e210_Array__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc) throw();

template <class T>
static __forceinline void S_00d0e210_Array_destroy(hkArrayBase<T>& self) throw()
{ S_00d0e210_Array__clearAndDeallocate(self, ((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap()); }

template <class T>
static __forceinline void S_00d0e210_Array__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc) throw()
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

struct S_00d0e210_Pair { int a; int b; };
struct S_00d0e210_ToiEvent {
    float m_uiCommandId;
    int unk04;
    int unk08;
    S_00d0e210_Entity* m_kActorEntries[2];
    hkpContactMgr* m_pContactManager;
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
    hkpWorld* m_pOwningWorld;
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


__forceinline void TimerCommand_ctsim::setTime()
{
    _ReadWriteBarrier();
    volatile unsigned int ticks = (unsigned int)__rdtsc();
    m_time0 = ticks;
}
extern DWORD g_D0FE00TlsIndex;
__forceinline hkMonitorStream& D0FE00GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D0FE00TlsIndex);
}
__forceinline void D0FE00TimerBegin(const char* name)
{
    hkMonitorStream& mStream = D0FE00GetMonitorStream();
    if (mStream.getEnd() < mStream.getCapacityMinus16()) {
        TimerCommand_ctsim* h = reinterpret_cast<TimerCommand_ctsim*>(mStream.m_end.val());
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}

void __cdecl hkpWorldCallbackUtil_firePostSimulationCallback(hkpWorld* world);
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
    hkpWorld* m_pOwningWorld;
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


inline hkMemoryRouter* Se4b0_router()
{
    return reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
}
template <typename T> inline void Se4b0_construct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++) p[i] = t;
}
template <class T>
static __forceinline void Se4b0_Arr__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc);

template <class T>
static __forceinline void Se4b0_Arr_AddBack(hkArrayBase<T>& self, const T& t);

template <class T>
static __forceinline void Se4b0_Arr__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, self.getCapacity() * sizeof(T));
    }

template <class T>
static __forceinline void Se4b0_Arr_AddBack(hkArrayBase<T>& self, const T& t)
{
        Manager* r = hkMemoryRouter_getInstance();
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream(reinterpret_cast<void*>(r->unk10), reinterpret_cast<NiPoint3*>((&self)), sizeof(T));
        Se4b0_construct<T>(self.m_data + self.m_iElementCount, 1, t);
        self.m_iElementCount++;
    }
inline void Se4b0_freeStack(void* p)
{
    hkMemoryRouter_getInstance()->unk00 = reinterpret_cast<int>(p);
}
template <class T> struct Se4b0_LocalArr : hkArrayBase<T> {
    T* m_pStackAllocation;
    Se4b0_LocalArr(int n)
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        Manager* m = hkMemoryRouter_getInstance();
        int p = m->unk00;
        m->unk00 = p + n * sizeof(T);
        this->m_data = reinterpret_cast<T*>(p);
        this->m_iCapacityState = 0x80000000 | 1000;
        m_pStackAllocation = reinterpret_cast<T*>(p);
    }
    void release()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        Se4b0_freeStack(m_pStackAllocation);
        this->_clearAndDeallocate(Se4b0_router()->heap());
    }
};
struct Se4b0_Body;
struct Se4b0_WorldView {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    hkStepInfo step;
};
inline hkStepInfo& Se4b0_step(World* w)
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
    Se4b0_States& states, hkArrayBase<Se4b0_Body*>* outBodies, hkArrayBase<ItemObj*>* outItems)
{
    if (level <= c->item->m_1c) {
        Se4b0_Body* other = c->getOther(body);
        if (other->motionType == 5) {
            Se4b0_Arr_AddBack((*(outItems)), c->item);
        } else if (states[other->storageIndex] != 16) {
            Se4b0_Arr_AddBack((*(outItems)), c->item);
            if (states[other->storageIndex] < 2) {
                Se4b0_Arr_AddBack(*outBodies, other);
                Se4b0_ensure(other, time, states);
                states[other->storageIndex] = 2;
            }
        }
    }
}
void hkLs_toiActivateEntitiesAndCheckConstraints(World* world, int level, float time, hkArrayBase<Se4b0_Body*>* bodies, Se4b0_States* states, hkArrayBase<Se4b0_Body*>* outBodies, hkArrayBase<ItemObj*>* outItems);
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
static __forceinline float& getSubStepTime(hkpWorld* ctx) {
    return ctx->m_fToiCollisionResponseRotateNormal;
}
static __forceinline hkStepInfo& getContextTimeStep(hkpWorld* ctx) {
    return *reinterpret_cast<hkStepInfo*>(reinterpret_cast<char*>(ctx) + 0x1d0);
}
static __forceinline void unlockContext(hkpWorld* ctx) {
    if (--ctx->m_iCriticalOperationsLockCount == 0 && !ctx->m_bBlockExecutingPendingOperations) {
        if (ctx->m_iPendingOperationCount)
            ctx->FUN_00c91120();
        if (ctx->m_iPendingOperationQueueCount == 1 && ctx->m_iQueuedOperationCount)
            ctx->UpdateFields_00c91140();
    }
}
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
    virtual void vfn17(hkpWorld* ctx, S_00d0d150_ToiEvent* ev, float fStepTime, float fSubStepTime);

    int unk04;
    int unk08;
    hkpWorld* m_iValueAtOffset0C;
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
    void hkpContinuousSimulation_handleSimpleToi(hkpWorld* ctx, S_00d0d150_ToiEvent* ev, float fStepTime, float fSubStepTime);
};
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

static inline hkMemoryRouter* S00d0d3f0_router() { return (hkMemoryRouter*)hkMemoryRouter_getInstance(); }
struct Region { unsigned unk00, unk04; unsigned data; };

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
void __stdcall hkpContinuousSimulation_collideEntitiesBroadPhaseContinuous(Source** sources, int count, hkpWorld* context, void* marker);
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
    S_00d0d150_Vector4 m_vContactPosition;
    S_00d0d150_Vector4 m_vSeparatingNormal;
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
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage) {
        TimerCommand_ctsim* h = reinterpret_cast<TimerCommand_ctsim*>(s->m_end.val());
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_time0 = ticks;
        s->m_end.m_storage = (char*)(h + 1);
    }
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
struct Heap {
    virtual void s00();virtual void s04();virtual void s08();virtual void s0c();
    virtual __declspec(nothrow) void freeBuffer(void*,int) throw();
    template<class T> inline void release(void* p,int n) {freeBuffer(p,n*sizeof(T));}
};
struct ArrayOps {
    static __declspec(nothrow) void __cdecl hkArrayUtil__reserve(Heap&,void*,int,int) throw();
    static __declspec(nothrow) void __cdecl ResizeAudioStream(Heap&,void*,int) throw();
    __forceinline static void GrowArray(Heap& a,void* p,int n) {ResizeAudioStream(a,p,n);}
};
template<class T> __forceinline void releaseArena(T* p) {hkMemoryRouter::get().a=p;}
template<class T> __forceinline T* allocateArena(int n) {hkMemoryRouter& router=hkMemoryRouter::get();char* p=static_cast<char*>(router.a);router.a=p+((n*sizeof(T)+127)&~127);return reinterpret_cast<T*>(p);}
struct SelectHeap {
    inline Heap& get(const void*) const {return *reinterpret_cast<Heap*>(hkMemoryRouter::getInstance().m_heap);}
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
    __forceinline void drop(Heap& a) {
        clear();
        if((flags&Borrowed)==0)a.release<T>(data,getCapacity());
        data=0;flags=Borrowed;
    }
    __forceinline void reserveWith(Heap& a,int n) {
        const int capacity=getCapacity();if(capacity<n) {int doubled=2*capacity;int requested=(n<doubled)?doubled:n;ArrayOps::hkArrayUtil__reserve(a,this,requested,sizeof(T));}
    }
    __forceinline void pushBackUnchecked(const T& value) {
        copyElements(data+size,1,value);++size;
    }
    __forceinline T* expandByUnchecked(int n) {int old=size;size=old+n;return data+old;}
    __forceinline void removeAt(int i) {--size;if(size!=i)copyOne(data+i,data+size);}
    __declspec(nothrow) void splice(Heap&,int,int,const T*,int);
    __declspec(noinline) __declspec(nothrow) void Search(Heap&,int,const T*,int) throw();
    __declspec(noinline) __declspec(nothrow) void CallWithFlag(Heap&,int,const T&) throw();

};
template<class T> __declspec(nothrow) void ListBase<T>::splice(Heap& a,int at,int erased,const T* source,int n) {
        int result=n+size-erased;
        int moving=size-at-erased;
        if(result>getCapacity())reserveWith(a,result);
        destroyRange(data+at,erased);
        memmove(data+at+n,data+at+erased,moving*sizeof(T));
        assignRange(data+at,n,source);
        size=result;
    }
template<class T> __declspec(noinline) __declspec(nothrow) void ListBase<T>::Search(Heap& a,int at,const T* source,int n) throw() {splice(a,at,0,source,n);}
template<class T> __declspec(noinline) __declspec(nothrow) void ListBase<T>::CallWithFlag(Heap& a,int at,const T& value) throw() {Search(a,at,&value,1);}
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
struct BackupTransform;
struct ConstraintQuery;
template<class T> struct UnsignedShortArray {T* m_pRayStart;T* m_kRayEnd;T* m_pTileTemplate;T* m_pValues;};
struct Resources {
    hkStepInfo* m_pStepInfo;
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
__declspec(nothrow) void hkpConstraintSolverSetup_oneStepIntegrate(const ResourceInfo&,const hkStepInfo&,const Accumulator*,DynamicNode* const*,int) throw();
__declspec(nothrow) void UpdateIslandMotionStates(SolverIsland*,StateTable&,Resources&) throw();
__declspec(nothrow) void PartitionMotionPairs(List<SchemaRecord>&,int&,int) throw();
__declspec(nothrow) void hkLs_toiActivateConstraintsLinkingActivatedEntities(List<SchemaRecord>&,int&,StateTable&) throw();
struct SweepView {hkVector4 center0,center1,rotation0,rotation1,localCenter;};

// 0x00cf1510 consumes the 64-byte Havok rotation/translation pose (hkTransform).
__declspec(nothrow) void hkSweptTransformUtil_lerp2(const SweepView&,float,hkTransform&) throw();
__forceinline void updateEntity(DynamicNode* node,float time) {
    hkMotionState* m=node->getMotion()->GetMotionState();
    hkSweptTransformUtil_lerp2(*reinterpret_cast<SweepView*>(&m->m_kSweptTransform.m_vCenterOfMass0),time,m->m_kMotionTransform);
}
__forceinline void restoreState(hkMotionState* m) {
    reinterpret_cast<hkRotation*>(m)->set(m->m_kSweptTransform.m_qRotation1);
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
struct SolveResourcesView { hkStepInfo* step; void* solver; void* query; void* accumulators; };

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
        int violated=hkLs_areVelocitiesOk(resources->step->m_fTimeStep,&record,velocities,n,&scene);
        if(violated<0) continue;
        if(!rejected) return BoolFlag(false);
        satisfied=false;
        
        if(rejected->GetLogicalSize()==rejected->getCapacity())
            ArrayOps::GrowArray(*reinterpret_cast<Heap*>(hkMemoryRouter::getInstance().m_heap),rejected,12);
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
int hkLs_localizedSolveToi(const Limits& limits,Resources& resources,PairEvent& event,ResourceManager& callbacks,Scene* world,List<DynamicNode*>& active,StateTable& states,float timeStep) throw();

template<class T> class SolField {
    T value;
public:
    __forceinline SolField() {}
    __forceinline SolField(T x) : value(x) {}
    __forceinline void operator=(T x) { value = x; }
    __forceinline T val() const { return value; }
    __forceinline operator T() const { return val(); }
    __forceinline T operator->() const { return value; }
};

static inline hkMemoryRouter* S00d0db40_router() { return (hkMemoryRouter*)hkMemoryRouter_getInstance(); }


struct S00d0db40_Input {
    SolField<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    mutable SolField<int> m_toiEnabled;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    mutable SolField<hkpCollisionQualityInfo*> m_quality;
};
struct S00d0db40_Island {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    int m_iActorEntryCount;
};
struct S00d0db40_AgentSrc;
struct S00d0db40_Entry {
    S_00d0d150_AgentNnEntry* m_pCollisionAgent;
    hkpCollidable* m_kCollidable;
};
template<class T>
struct SolArrayBase { // local form of hkArrayBase: 0x00d0db40 needs its empty base constructor and local helper split; shared initialization changes extent from 814 to 863 bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline SolArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~SolArrayBase() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline T* begin() { return m_data; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline void setSizeUnchecked(int n) { m_iElementCount = n; }
    __forceinline void clear() { m_iElementCount = 0; }
    __forceinline void deallocate(hkMemoryAllocator& heap) {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            heap.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
template<class T> struct SolArray : SolArrayBase<T> {
    __forceinline SolArray() : SolArrayBase<T>() {}
    __forceinline ~SolArray() { this->deallocate(S00d0db40_router()->heap()); }
};
typedef SolArray<S00d0db40_Entry> S00d0db40_EntryArray;
struct S00d0db40_AgentSrc {
    void CopyAndSortGeometryList(S00d0db40_EntryArray& out) const;
};
struct S00d0db40_Entity {
    int unk00, unk04, unk08, unk0c;
    S00d0db40_AgentSrc m_src;
    int unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4;
    unsigned short m_uiUniqueId;
    unsigned short unkaa;
    int unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8;
    S00d0db40_Island* m_pCurrentSimulationIsland;
    int unkd0;
    unsigned int m_iOwnerObjectOffset;
    __forceinline S00d0db40_Island* getIsland() const { return m_pCurrentSimulationIsland; }
    __forceinline S00d0db40_AgentSrc* linked() { return &m_src; }
    __forceinline unsigned int uid() const { return m_iOwnerObjectOffset; }
    void FUN_00c90510() const;
};
struct SolCollisionData;

struct S00d0db40_Pending {
    unsigned int LookupHashEntry(unsigned int key, unsigned int def) const;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocator* heap, unsigned int key, unsigned int value);
    __forceinline S00d0db40_Entity* get(unsigned int key, S00d0db40_Entity* def) const { return (S00d0db40_Entity*)LookupHashEntry(key, (unsigned int)def); }
    __forceinline int insert(unsigned int key, S00d0db40_Entity* value) { return hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(&S00d0db40_router()->heap(), key, (unsigned int)value); }
};
class SolVector {
    LocalM128 q;
public:
    __forceinline SolVector() {}
    __forceinline void operator=(const SolVector& v) { q = v.q; }
};

struct SolProcessPoint { SolVector position, normal; int contactId, unk24, unk28, unk2c; };
struct SolToi {
    SolVector position, normal;
    SolField<float> m_uiCommandId;
    SolField<float> velocity;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    S_00d0d150_Properties m_kProperties;
    int m_aiContactData[7];
    __forceinline SolToi() : m_uiCommandId(DAT_0104da48) {}
};
struct SolCollisionData {
    SolField<SolProcessPoint*> first;
    SolField<S00d0db40_Island*> owner;
    int unk08, unk0c;
    SolProcessPoint m_akContactPoints[256];
    SolToi m_fTimeOfImpact;
    __forceinline SolCollisionData(S00d0db40_Island* island) { owner = island; }
    __forceinline bool isEmpty() const { return first.val() == &m_akContactPoints[0]; }
    __forceinline bool hasToi() const { return m_fTimeOfImpact.m_uiCommandId != DAT_0104e138; }
};
struct S00d0db40_Output : SolCollisionData {
    SolField<void*> m_akContactRecords;
    __forceinline S00d0db40_Output(S00d0db40_Island* island) : SolCollisionData(island) {}
    __forceinline void reset() {
        first = m_akContactPoints;
        m_fTimeOfImpact.m_uiCommandId = DAT_0104da48;
        m_akContactRecords = 0;
    }
};
struct SolVisited : SolArray<hkBool> {
    hkBool* m_pStackAllocation;
    __forceinline SolVisited(int n) {
        m_data = (hkBool*)AllocateStackD0(n);
        m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = m_data;
    }
    __forceinline ~SolVisited() {
        if (m_pStackAllocation == m_data) clear();
        FreeStackD0(m_pStackAllocation);
    }
};
void __cdecl hkString_memSet(void* dst, int value, int size);

struct SolTimerRecord : TimerCommand_ctsim {
    __forceinline void stamp() {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_time0 = ticks;
    }
};
struct S00d0db40_Dyn {
    virtual void placeholder();
    int unk04, unk08;
    hkpWorld* m_pOwningWorld;
    void QueueToiEvent(const S00d0db40_Output&, const S_00d0d150_AgentNnEntry&);

    void hkpContinuousSimulation_collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(S00d0db40_Entity** entities, int numEntities, const S00d0db40_Input& input, S00d0db40_Pending& pending);
};
extern "C" void __cdecl hkAgentNnMachine_ProcessAgent(S_00d0d150_AgentNnEntry*, const S00d0db40_Input&, S00d0db40_Output&, hkpContactMgr*);
// @fnv 0x00d0db40
// src: HAVOK_LIB 0x00d0db40
void S00d0db40_Dyn::hkpContinuousSimulation_collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(S00d0db40_Entity** entities, int numEntities, const S00d0db40_Input& input, S00d0db40_Pending& pending)
{
    S00d0db40_Island* island = entities[0]->getIsland();
    int numBytes = island->m_iActorEntryCount;
    SolVisited visited(numBytes);
    visited.setSizeUnchecked(numBytes);
    hkString_memSet(visited.begin(), 0, numBytes);
    S00d0db40_Output output(island);
    {
        hkMonitorStream& stream = *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (stream.m_end.m_storage < stream.m_capacityMinus16.m_storage) {
            SolTimerRecord* record = reinterpret_cast<SolTimerRecord*>(stream.m_end.val());
            record->m_commandAndMonitor = "TtNarrowPhaseTOI";
            record->stamp();
            stream.m_end.m_storage = (char*)(record+1);
        }
    }
    for (int i = 0; i < numEntities; ++i) {
        S00d0db40_Entity* entity = entities[i];
        S00d0db40_AgentSrc* linked = entity->linked();
        visited[entity->m_uiUniqueId] = true;
        S00d0db40_EntryArray temporary;
        linked->CopyAndSortGeometryList(temporary);
        const S00d0db40_EntryArray& entries = temporary;
        for (int j = 0; j < entries.GetLogicalSize(); ++j) {
            const S00d0db40_Entry& pair = entries[j];
            S00d0db40_Entity* other = (S00d0db40_Entity*)pair.m_kCollidable->getOwner();
            if (other->getIsland() == island && visited[other->m_uiUniqueId]) continue;
            S_00d0d150_AgentNnEntry* agent = pair.m_pCollisionAgent;
            if (m_pOwningWorld->getCollisionDispatcher()->getCollisionQualityInfo(agent->m_cAgentType)->m_iQualityInfoValue10 && !m_pOwningWorld->getCollisionDispatcher()->getCollisionQualityInfo(agent->m_cAgentType)->m_bUseContinuousPhysics) {
                output.reset();
                input.m_quality = input.m_pCollisionDispatcher->getCollisionQualityInfo(agent->m_cAgentType);
                input.m_toiEnabled = input.m_quality->m_iQualityInfoValue10;
                hkAgentNnMachine_ProcessAgent(agent, input, output, (hkpContactMgr*)agent->m_pContactManager);
                if (DAT_01269200 == 1) goto done;
                if (!output.isEmpty()) {
                    hkpCollidable* a = agent->m_kCollidable[0];
                    hkpCollidable* b = agent->m_kCollidable[1];
                    typedef void (__thiscall *ProcessContact)(hkpContactMgr*, hkpCollidable*, hkpCollidable*, const S00d0db40_Input&, SolCollisionData&);
                    hkpContactMgr* mgr = static_cast<hkpContactMgr*>(agent->m_pContactManager);
                    (*reinterpret_cast<ProcessContact**>(mgr))[6](mgr, a, b, input, output);
                }
                if (output.hasToi()) QueueToiEvent(output, *agent);
            } else {
                unsigned int lookupId = entity->uid();
                if (!pending.get(lookupId, 0)) {
                    entity->FUN_00c90510();
                    unsigned int id = entity->uid();
                    pending.insert(id, entity);
                }
            }
        }
    }
done:
    {
        hkMonitorStream& stream = *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (stream.m_end.m_storage < stream.m_capacityMinus16.m_storage) {
            SolTimerRecord* record = reinterpret_cast<SolTimerRecord*>(stream.m_end.val());
            record->m_commandAndMonitor = DAT_010c41f8;
            record->stamp();
            stream.m_end.m_storage = (char*)(record+1);
        }
    }
}

namespace fnv_anon_00d0de70 {}
using namespace fnv_anon_00d0de70;
typedef float hkReal;
typedef char hkChar;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
#include "../../../../../../../include/hkResult.h"
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;template<typename TYPE>
__forceinline TYPE __cdecl hkSelectOther(TYPE a,TYPE pairA,TYPE pairB)
{
return(TYPE)(hkUlong(a)^ hkUlong(pairA)^ hkUlong(pairB));
}
class hkClass;
typedef int hkBool32;
class hkBoolH
{
public:
typedef char CompileTimeTrueType;
typedef int CompileTimeFalseType;inline hkBoolH(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};

extern "C"
{
extern const hkReal g_afRealLookupTable[256];
}


template<typename T>struct TypeSizeConstant{enum{val=sizeof(T)};};


class hkStatisticsCollector;
template<class TYPE>
class ReferenceCountedPointer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
TYPE*m_pRetainedObject;};struct hkPlacementNewArg;
inline void*operator new(hk_size_t,hkPlacementNewArg*p){return p;}
// hkTypeIsPod / hkTypeIsClass / IsPodType (include/hkTypeTraits.h), hkArrayBase / hkArray / hkArrayUtil
// (include/hkArray.h): this unit defines the bodies it uses.
template<typename T>
__forceinline void hkArrayUtil::construct(T*t,int n,hkTypeIsClass)
{
for(int i=0;i<n;++i)
{
::new(reinterpret_cast<hkPlacementNewArg*>(t+i))T;
}
}
template<typename T>
__forceinline void hkArrayUtil::destruct(T*t,int n,hkTypeIsClass)
{
for(int i=0;i<n;++i)
{
static_cast<T*>(t)[i].~T();
}
}
__forceinline hkMemoryAllocator&hkContainerHeapAllocator::get(const void*){return hkMemoryRouter::getInstance().heap();}
template<typename T>
__forceinline void hkArrayBase<T>::clear()
{
hkArrayUtil::destruct(m_data,m_iElementCount,typename IsPodType<T>::type());
m_iElementCount=0;
}
template<typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator&alloc)
{
clear();
if((m_iCapacityState&DONT_DEALLOCATE_FLAG)==0)
{
alloc._bufFree<T>(m_data,getCapacity());
}
m_data=0;
m_iCapacityState=DONT_DEALLOCATE_FLAG;
}
template<typename T>
__forceinline T&hkArrayBase<T>::_expandOne(hkMemoryAllocator&alloc)
{
if(m_iElementCount==getCapacity())
{
hkArrayUtil::_reserveMore(alloc,this,sizeof(T));
}
hkArrayUtil::construct(m_data+m_iElementCount,1,typename IsPodType<T>::type());
return m_data[m_iElementCount++];
}
template<typename T,typename Allocator>
__forceinline hkArray<T,Allocator>::~hkArray()
{ __if_exists(Allocator::destroy) { Allocator::destroy(*this); } __if_not_exists(Allocator::destroy) {
clearAndDeallocate();
} }
template<typename T>
class ResizableArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
enum
{
CAPACITY_MASK=hkUint16(0x3fff),
FLAG_MASK=hkUint16(0xC000),
DONT_DEALLOCATE_FLAG=hkUint16(0x8000),
LOCKED_FLAG=hkUint16(0x4000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
T*m_data;
hkUint16 m_iElementCount;
public:
ResizableArray(FinishingFlag f){}
};template<typename KEY>
struct KeyMarker
{inline static hkBool32 isValid(KEY key)
{
return key !=KEY(-1);
}
};
template<typename KEY,typename VAL=KEY,typename OPS=KeyMarker<KEY>>
class HashEntryTable
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
typedef class Dummy*Iterator;
HashEntryTable():m_kPrimitiveElement(0),m_iCapacityFlags(0),m_iPairCount(-1){}
~HashEntryTable();
Iterator GetFirstIterator()const;
VAL getValue(Iterator i)const;
Iterator getNext(Iterator i)const;
hkBoolH isValid(Iterator i)const;
hkBool32 insert(hkMemoryAllocator&alloc,KEY key,VAL val);VAL FindValueForKey(KEY key,VAL def)const;
void clear();
void ClearAndRelease(hkMemoryAllocator&a);
void reserve(hkMemoryAllocator&a,int numElements);
protected:
void ResizeStorage(hkMemoryAllocator&alloc,int capacity);
protected:
static inline hkBool32 isPower2(unsigned int v){return(v&(v-1))==0;}
Pair*m_kPrimitiveElement;
int m_iCapacityFlags;
int m_iPairCount;};
template<typename KEY,typename VAL=KEY,typename OPS=KeyMarker<KEY>,typename Allocator=hkContainerHeapAllocator>
class RouterAllocatedHashTable:public HashEntryTable<KEY,VAL,OPS>
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
RouterAllocatedHashTable(int nelem=0){reserve(nelem);}
~RouterAllocatedHashTable(){ClearAndRelease(Allocator().get(this));}
__forceinline hkBool32 insert(KEY key,VAL val){return HashEntryTable<KEY,VAL,OPS>::insert(Allocator().get(this),key,val);}
__forceinline void reserve(int numElements){return HashEntryTable<KEY,VAL,OPS>::reserve(Allocator().get(this),numElements);}
};
template<typename KEY,typename VAL,typename OPS>
inline typename HashEntryTable<KEY,VAL,OPS>::Iterator HashEntryTable<KEY,VAL,OPS>::GetFirstIterator()const
{
int i;
for(i=0;i<=m_iPairCount;++i)
{
if(OPS::isValid(m_kPrimitiveElement[i].a))
{
break;
}
}
return reinterpret_cast<Iterator>(hkUlong(i));}
template<typename KEY,typename VAL,typename OPS>
inline VAL HashEntryTable<KEY,VAL,OPS>::getValue(Iterator it)const
{
int i=static_cast<int>(reinterpret_cast<hkUlong>(it));
;
return m_kPrimitiveElement[i].b;
}
template<typename KEY,typename VAL,typename OPS>
inline typename HashEntryTable<KEY,VAL,OPS>::Iterator HashEntryTable<KEY,VAL,OPS>::getNext(Iterator it)const
{
int i=static_cast<int>(reinterpret_cast<hkUlong>(it));
for(i+=1;i<=m_iPairCount;++i)
{
if(OPS::isValid(m_kPrimitiveElement[i].a))
{
break;
}
}
return reinterpret_cast<Iterator>(hkUlong(i));}
template<typename KEY,typename VAL,typename OPS>
inline hkBoolH HashEntryTable<KEY,VAL,OPS>::isValid(Iterator it)const
{
int i=static_cast<int>(reinterpret_cast<hkUlong>(it));
;
return i<=m_iPairCount;
}
template<int N>
struct HkUlongType
{
typedef hkUlong Type;
};
template<typename K,typename V,typename Allocator=hkContainerHeapAllocator>
class PointerKeyIntegerMap
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
typedef typename HkUlongType<sizeof(K)>::Type Storage;
typedef typename RouterAllocatedHashTable<Storage,Storage>::Iterator Iterator;__forceinline hkBool32 insert(K key,V val)
{
return m_map.insert(Storage(key),Storage(val));
}
__forceinline V FindValueForKey(K key,V def)const
{
return(V)m_map.FindValueForKey(Storage(key),Storage(def));
}
Iterator GetFirstIterator()const
{
return m_map.GetFirstIterator();
}
V getValue(Iterator i)const
{
return(V)m_map.getValue(i);
}
Iterator getNext(Iterator i)const
{
return m_map.getNext(i);
}
hkBoolH isValid(Iterator i)const
{
return m_map.isValid(i);
}
void clear()
{
m_map.clear();
}
private:
void operator=(const PointerKeyIntegerMap<K,V>&map){}
public:
protected:
RouterAllocatedHashTable<Storage,Storage,KeyMarker<Storage>,Allocator>m_map;};
typedef LocalM128 hkQuadReal;class hkVector4H
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline const hkReal&operator()(int i)const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
class __declspec(align(16))hkRotationH:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};

inline const hkReal&hkVector4H::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
__forceinline hkReal hkSweptTransform::getInvDeltaTime()const
{
return m_vCenterOfMass1(3);
}
typedef hkUint16 hkContactPointId;


class hkAabb;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;


enum CollidableQuality
{
HK_COLLIDABLE_QUALITY_INVALID=-1,
HK_COLLIDABLE_QUALITY_FIXED=0,
HK_COLLIDABLE_QUALITY_KEYFRAMED,
HK_COLLIDABLE_QUALITY_DEBRIS,
HK_COLLIDABLE_QUALITY_DEBRIS_SIMPLE_TOI,
HK_COLLIDABLE_QUALITY_MOVING,
HK_COLLIDABLE_QUALITY_CRITICAL,
HK_COLLIDABLE_QUALITY_BULLET,
HK_COLLIDABLE_QUALITY_USER,
HK_COLLIDABLE_QUALITY_CHARACTER,
HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
HK_COLLIDABLE_QUALITY_MAX
};
struct hkAabbUint32;
struct NarrowPhaseAgentEntry;


inline hkpWorldObject*hkGetWorldObject(const hkpCollidable*collidable)
{
return reinterpret_cast<hkpWorldObject*>(const_cast<void*>(collidable->getOwner()));
}

class ContactImpulseInfo
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
inline ContactImpulseInfo();
inline void init();
public:
hkReal m_fAccumulatedImpulse;
hkReal m_fImpulseLimit;};
inline void ContactImpulseInfo::init()
{
m_fAccumulatedImpulse=0.0f;
m_fImpulseLimit=0.0f;
}
inline ContactImpulseInfo::ContactImpulseInfo()
{
init();
}
struct GenericConstraintAtomScheme
{};
class hkpConstraintOwner;
class hkpEntity;
class hkpSimulationIsland;
class hkMotionStateH
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkSweptTransform&getSweptTransform();
protected:
hkTransform m_kMotionTransform;
class hkSweptTransform m_kSweptTransform;
public:
hkVector4H m_kDeltaAngle;};hkSweptTransform&hkMotionStateH::getSweptTransform()
{
return m_kSweptTransform;
}

__forceinline hkpMotion::MotionType hkpMotion::getType() const { return static_cast<MotionType>(*reinterpret_cast<const hkUint8*>(&m_type)); }
__forceinline hkMotionStateH*hkpMotion::GetMotionState()
{
return reinterpret_cast<hkMotionStateH*>(&m_kMotionState);
}


class hkpEntityListener;
class hkpEntityActivationListener;
class hkpAction;
class hkSpuCollisionCallbackUtil;
class hkLocalFrame;
class hkpBreakableBody;
inline hkpSimulationIsland*hkpEntity::GetSimulationIsland()const
{
return m_pSimulationIsland;
}
inline hkBoolH hkpEntity::isFixed()const
{
return m_pMotionState.getType()==hkpMotion::MOTION_FIXED;
}
inline hkUint32 hkpEntity::GetUid()const
{
return m_uiUniqueId;
}

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
return *g_pMonitorStream.getData();
}
__forceinline char* hkMonitorStream::getStart() { return m_start.val(); }
__forceinline char* hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool hkMonitorStream::memoryAvailable() { return getEnd() < getCapacityMinus16(); }
__forceinline void hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
struct MonitorStreamOperationState
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}template<typename TYPE>static __forceinline void __cdecl checkMt(int id,const TYPE&object){}
public:
enum Mode
{
MODE_IDLE,
MODE_WRITE,
MODE_COMPARE
};};
extern hkMemoryAllocator::MemoryState g_eOutOfMemoryState;
__forceinline hkMemoryAllocator::MemoryState hkGetOutOfMemoryState()
{
return g_eOutOfMemoryState;
}
__forceinline bool hkMemoryStateIsOutOfMemory(int id)
{
bool lowOnMem=hkGetOutOfMemoryState()==hkMemoryAllocator::MEMORY_STATE_OUT_OF_MEMORY;
return lowOnMem;
}
struct GskAgentInput;

struct WorldOperationEntry;
#include "../../../../../../../include/hkpCollisionQualityInfo.h"
struct CollisionAgentContext;
class hkpCollisionAgent;
struct FourByteState
{
hkUchar m_ucAgentType;};

struct AgentProcessingInput
{};
struct AgentSubtypeMarker:public AgentProcessingInput
{};

struct NarrowPhaseAgentEntry:FourByteState
{
hkObjectIndex m_ausAgentData[2];
hkpContactMgr*m_pContactManager;
hkUchar m_cAgentType;
hkpLinkedCollidable*m_kCollidable[2];
inline hkpCollidable*getCollidableA(){return reinterpret_cast<hkpCollidable*>(m_kCollidable[0]);}
inline hkpCollidable*getCollidableB(){return reinterpret_cast<hkpCollidable*>(m_kCollidable[1]);}
};
extern "C"
{
void __cdecl ProcessGskAgentInput(NarrowPhaseAgentEntry*entry,const GskAgentInput&input,WorldOperationEntry&output,hkpContactMgr*mgr);}
__forceinline void* __cdecl hkStepInfo::operator new(size_t nbytes)
{
    return hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
}
class hkpCollisionFilter;
class hkpConvexListFilter;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;
hkPadSpu<const hkpCollisionFilter*>m_iFilter;
hkPadSpu<const hkpConvexListFilter*>m_pConvexListCollisionFilter;
mutable hkPadSpu<hkBool32>m_bCreatePredictiveAgents;
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4H m_kAabbMin;
hkVector4H m_kAabbMaximum;
hkVector4H m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};struct ContactPointWithId
{
hkContactPoint m_kPoint;
hkPadSpu<hkUint32>m_usContactPointId;};

class ConvexFeaturePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform&btoa);};
__declspec(align(16))class HeapContactFeatureCache:public ConvexFeaturePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
class PhysicsMaterial:public ContactImpulseInfo,public hkContactPointMaterial
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}public:
hkReal m_uiUserData;
typedef hkUint32 UserData;};
__declspec(align(16))class ContactDataPhysicsMaterial:public PhysicsMaterial
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}UserData m_aiContactData[7];};enum{HK_MAX_CONTACT_POINT=256};
struct CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
inline hkBoolH isEmpty()const;
public:
hkPadSpu<ContactPointWithId*>m_pAlignedPairData;
hkPadSpu<hkpConstraintOwner*>m_pConstraintOwner;
ContactPointWithId m_akContactPoints[HK_MAX_CONTACT_POINT];
struct CollisionCacheState
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionContactResults::CollisionCacheState));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
inline CollisionCacheState();
inline void flip();
public:
hkContactPoint m_vContactPoint;
hkPadSpu<hkReal>m_uiCommandId;
hkPadSpu<hkReal>m_fSeparation;
HeapContactFeatureCache m_kGskCache;
ContactDataPhysicsMaterial m_kProperties;
};
struct CollisionCacheState m_fTimeOfImpact;
inline CollisionContactResults(hkpConstraintOwner*owner);};inline hkBoolH CollisionContactResults::isEmpty()const
{
return m_pAlignedPairData==&m_akContactPoints[0];
}
CollisionContactResults::CollisionCacheState::CollisionCacheState():m_uiCommandId(3.40282e+38f)
{
}
CollisionContactResults::CollisionContactResults(hkpConstraintOwner*owner)
{
m_pConstraintOwner=owner;
}
struct WorldOperationEntry:public CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
inline WorldOperationEntry(hkpConstraintOwner*owner):CollisionContactResults(owner){}
inline void reset()
{
m_pAlignedPairData=&m_akContactPoints[0];
m_fTimeOfImpact.m_uiCommandId=3.40282e+38f;
m_akContactRecords=0;
}
public:
struct ContactPointAgentEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(WorldOperationEntry::ContactPointAgentEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ContactPointWithId*m_vContactPoint;
FourByteState*m_pAgentEntry;
void*m_pUserData;
};
struct ContactPointBuffer
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(WorldOperationEntry::ContactPointBuffer));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
void reset()
{
m_pFirstFreeContactPoint=&m_akContactRecords[0];
m_ppFirstFreeContactPointer=&m_apContactPointPointers[0];
}
ContactPointAgentEntry*m_pFirstFreeContactPoint;
ContactPointWithId**m_ppFirstFreeContactPointer;
ContactPointWithId*m_apContactPointPointers[HK_MAX_CONTACT_POINT];
ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
};
public:
hkPadSpu<ContactPointBuffer*>m_akContactRecords;};

class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;


class hkpSimulation;


class IncompleteClassType;
inline hkpRigidBody*hkpGetRigidBodyUnchecked(const hkpCollidable*collidable)
{
;
return static_cast<hkpRigidBody*>(hkGetWorldObject(collidable));
}
inline hkpMotion*hkpRigidBody::getRigidMotion()const
{
return const_cast<hkpMaxSizeMotion*>(&m_pMotionState);
}
__forceinline void hkpContactMgr::processContact(const hkpCollidable&a,const hkpCollidable&b,const GskAgentInput&input,CollisionContactResults&collisionData)
{
// The shared header omits virtual contact processing at vtable slot 6.
typedef void (__thiscall *ProcessContact)(hkpContactMgr*, const hkpCollidable&, const hkpCollidable&, const GskAgentInput&, CollisionContactResults&);
(*reinterpret_cast<ProcessContact**>(this))[6](this, a, b, input, collisionData);
}
namespace fnv_anon_00d0de70 {
struct SimulationIslandEntryRecord
{
NarrowPhaseAgentEntry*m_entry;
hkpSimulationIsland*m_pCurrentSimulationIsland;
};
}
class hkpContinuousSimulation:public hkpSimulation
{
public:
void collideEntitiesNeedingPsiCollisionDetectionNarrowPhase_toiOnly(const GskAgentInput&input,PointerKeyIntegerMap<hkUint32,hkpEntity*>&entitiesNeedingPsiCollisionDetection);
};
// @fnv 0x00d0de70
// src: HAVOK_LIB 0x00d0de70
void hkpContinuousSimulation::collideEntitiesNeedingPsiCollisionDetectionNarrowPhase_toiOnly(const GskAgentInput&input,PointerKeyIntegerMap<hkUint32,hkpEntity*>&entitiesNeedingPsiCollisionDetection)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.getEnd()<mStream.getCapacityMinus16()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "Recollide PSI";h->setTime();mStream.setEnd((char*)(h+1));}};
m_pOwningWorld->lockCriticalOperations();
PointerKeyIntegerMap<NarrowPhaseAgentEntry*,int>entriesToCollideMap;
hkArray<SimulationIslandEntryRecord>entriesToCollide;
{
PointerKeyIntegerMap<hkUint32,hkpEntity*>::Iterator it=entitiesNeedingPsiCollisionDetection.GetFirstIterator();
while(entitiesNeedingPsiCollisionDetection.isValid(it))
{
const hkpEntity*entity=entitiesNeedingPsiCollisionDetection.getValue(it);
MonitorStreamOperationState::checkMt(0xad000002,entity->GetUid());
MonitorStreamOperationState::checkMt(0xad000003,entity->m_usStorageIndex);
;
const hkArray<hkpLinkedCollidable::CollisionKeyEntry>&collisionEntries=entity->m_kCollidable.getCollisionEntriesDeterministicUnchecked();
const int numCollisionEntries=collisionEntries.m_iElementCount;
for(int e=0;e<numCollisionEntries;e++)
{
NarrowPhaseAgentEntry*entry=collisionEntries.m_data[e].m_pAgentEntry;
if(entriesToCollideMap.FindValueForKey(entry,0)==0)
{
const hkpCollisionQualityInfo*collisionQualityInfo=m_pOwningWorld->getCollisionDispatcher()->getCollisionQualityInfo(entry->m_cAgentType);
int isContinuous=collisionQualityInfo->m_iQualityInfoValue10;
hkBool isSimplified=collisionQualityInfo->m_bUseContinuousPhysics;
bool motionIsFrozen=static_cast<const hkpRigidBody*>(entity)->getRigidMotion()->GetMotionState()->getSweptTransform().getInvDeltaTime()==0.0f;
if(!isContinuous ||(isSimplified&&motionIsFrozen))
{
hkpSimulationIsland*island=entity->GetSimulationIsland();
if(entity->isFixed())
{
const hkpEntity*entityA=hkpGetRigidBodyUnchecked(entry->m_kCollidable[0]);
const hkpEntity*entityB=hkpGetRigidBodyUnchecked(entry->m_kCollidable[1]);
const hkpEntity*otherEntity=hkSelectOther(entity,entityA,entityB);
island=otherEntity->GetSimulationIsland();
;
}
entriesToCollideMap.insert(entry,0);
SimulationIslandEntryRecord*ei=&entriesToCollide.expandOne();
ei->m_entry=entry;
ei->m_pCurrentSimulationIsland=island;
}
}
}
entity->hkReferencedObject::removeReference();
it=entitiesNeedingPsiCollisionDetection.getNext(it);
}
}
entitiesNeedingPsiCollisionDetection.clear();
for(int i=0;i<entriesToCollide.GetLogicalSize();i++)
{
NarrowPhaseAgentEntry*entry=entriesToCollide[i].m_entry;
hkpSimulationIsland*island=entriesToCollide[i].m_pCurrentSimulationIsland;
;
WorldOperationEntry processOutput(island);
processOutput.reset();
const_cast<GskAgentInput&>(input).m_pCollisionQualityInfo=input.m_pCollisionDispatcher->getCollisionQualityInfo(entry->m_cAgentType);
const_cast<GskAgentInput&>(input).m_bCreatePredictiveAgents=input.m_pCollisionQualityInfo->m_iQualityInfoValue10;
ProcessGskAgentInput(entry,input,processOutput,entry->m_pContactManager);
if(hkMemoryStateIsOutOfMemory(0x1a))
{
break;
}
if(!processOutput.isEmpty())
{
hkpCollidable*collA=entry->getCollidableA();
hkpCollidable*collB=entry->getCollidableB();
entry->m_pContactManager->processContact(*collA,*collB,input,processOutput);
}
;
}
m_pOwningWorld->unlockAndAttemptToExecutePendingOperations();
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.getEnd()<mStream.getCapacityMinus16()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
