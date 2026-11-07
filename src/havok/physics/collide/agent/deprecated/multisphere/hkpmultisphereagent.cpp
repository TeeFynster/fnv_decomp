// Keep the original intrinsic lane declaration: byte lanes in the CRT union
// would introduce /GS cookies into callers that did not have them in the game.
#define _INCLUDED_MM2
// Exe 0x00d443e0 FUN_00d443e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
// These bases are never instantiated directly in this unit.
class __declspec(novtable) hkBaseObject;
class __declspec(novtable) hkReferencedObject;
class __declspec(novtable) hkpCollisionAgent;
class __declspec(novtable) hkpCdBodyPairCollector;
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdBodyPairCollector.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipBodyCollector.h"
#include "../../../../../../../include/hkpMultiSphereShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereShape.h"
// Placement construction leaves the temporary sphere's lifetime explicit.
inline void* __cdecl operator new(size_t, void* storage) throw() { return storage; }
#include "../../../../../../../include/hkMemoryRouter.h"


inline hkRotation& hkTransform::getRotation() { return *(hkRotation*)&m_row0; }
inline const hkRotation& hkTransform::getRotation() const { return *(const hkRotation*)&m_row0; }
inline hkVector4& hkTransform::getTranslation() { return *(hkVector4*)&m_row3; }
inline const hkVector4& hkTransform::getTranslation() const { return *(const hkVector4*)&m_row3; }

inline hkpCdBody::hkpCdBody(const hkpCdBody* parent, const void* motion)
{
    m_parent = parent;
    m_pMotionState = motion;
}
inline const hkpShape* hkpCdBody::getShape() const { return m_pCollisionShape; }
inline const hkMotionState* hkpCdBody::GetMotionState() const
{
    return (const hkMotionState*)m_pMotionState;
}
inline const hkTransform& hkpCdBody::getTransform() const
{
    return *(const hkTransform*)m_pMotionState;
}
inline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key)
{
    m_pCollisionShape = shape;
    m_uiCollisionShapeKey = key;
}
inline float& hkVector4::operator()(int i) { return m_vComponents.m128_f32[i]; }
inline const float& hkVector4::operator()(int i) const { return m_vComponents.m128_f32[i]; }


inline hkpCollisionAgent::hkpCollisionAgent(hkpContactMgr* manager) : m_pContactManager(manager) {}
inline hkpCollisionAgent::~hkpCollisionAgent() throw() {}

class CollisionAgentContext;
class hkpCdPointCollector;

// The shared base stops before its collision-query slots. This extension
// supplies those declarations while reusing the checked base layout and vtable.
class CollisionQueryAgent : public hkpCollisionAgent
{
public:
    virtual void getClosestPoints(const hkpCdBody&, const hkpCdBody&,
                                  const CollisionAgentContext&, hkpCdBodyPairCollector&);
    virtual void getPenetrations(const hkpCdBody&, const hkpCdBody&,
                                 const CollisionAgentContext&, hkpCdBodyPairCollector&);
    virtual void linearCast(const hkpCdBody&, const hkpCdBody&, const CollisionAgentContext&,
                            hkpCdPointCollector&, hkpCdPointCollector*);
    virtual void processCollision(hkpCdBody*, int, int, int);
    virtual void cleanup(unsigned int);
};

inline unsigned char CollectorEarlyOut(const hkpCdBodyPairCollector& collector)
{
    // The early-out byte follows the collector's vptr in the game ABI.
    return *((const unsigned char*)&collector + sizeof(void*));
}
__forceinline hkpShapeType hkpShape::getType() const
{
    return *(const hkpShapeType*)&m_type;
}

// src/havok/physics/collide/agent/deprecated/multisphere/hkpmultisphereagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/multisphere/hkpmultisphereagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Entry
{
    int unk00;
    hkpCollisionAgent* listener;
};
struct Dispatcher
{
    virtual void Finish(unsigned int);
    int unk04;
    int unk08;
    Entry* entries;
    int count;
    void __thiscall NotifyAll(unsigned int);
};
// Calls Notify(value) on every entry's listener, then calls Finish(1).
// @fnv 0x00d443a0
void Dispatcher::NotifyAll(unsigned int value)
{
    for (int i = 0; i < count; ++i)
        static_cast<CollisionQueryAgent*>(entries[i].listener)->cleanup(value);
    Finish(1);
}

// The shared header has no radius constructor. Keep its out-of-line call here
// using the checked sphere layout and the original thiscall convention.
extern void ConstructSphereShape();
inline void InitSphereShape(hkpSphereShape* shape, float radius)
{
    typedef void (__thiscall* Constructor)(hkpSphereShape*, float);
    ((Constructor)ConstructSphereShape)(shape, radius);
}

class CollisionAgentContext;

struct CollisionAgentMapRecord
{
    unsigned int m_key;
    hkpCollisionAgent* m_pCollisionAgent;
};

class hkpMultiSphereAgent
{
  public:
    void* m_vtbl;
    int m_pad04;
    int m_pad08;
    CollisionAgentMapRecord* m_pAgents;
    int m_iElementCount;
    void GetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                         hkpCdBodyPairCollector& collector);
};

// For each stored sphere pair, transforms the sphere centre into world space, sets its radius and queries the agent's getPenetrations against bodyB.
// @fnv 0x00d444f0
void hkpMultiSphereAgent::GetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                          const CollisionAgentContext& input, hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());

    LocalM128 msStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    ::new (msStorage) hkMotionState(*bodyA.GetMotionState());
    hkMotionState& ms = *(hkMotionState*)msStorage;
    LocalM128 sphereShapeStorage[(sizeof(hkpSphereShape) + sizeof(LocalM128) - 1) / sizeof(LocalM128)];
    InitSphereShape((hkpSphereShape*)sphereShapeStorage, 0.0f);
    hkpSphereShape& sphereShape = *(hkpSphereShape*)sphereShapeStorage;
    hkpCdBody newOperandA(&bodyA, &ms);

    const CollisionAgentMapRecord* pair = m_pAgents;
    for (int i = m_iElementCount - 1; i >= 0; pair++, i--)
    {
        const hkVector4& b = msA->m_kSpheres[pair->m_key];
        const hkTransform& r = ms.m_kMotionTransform;
        LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        LocalM128 r0 = _mm_mul_ps(b0, r.m_row0);
        LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        LocalM128 r1 = _mm_mul_ps(b1, r.m_row1);
        LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        LocalM128 r2 = _mm_mul_ps(b2, r.m_row2);
        ms.m_kMotionTransform.m_row3 =
            _mm_add_ps(_mm_add_ps(_mm_add_ps(r1, r0), r2), bodyA.getTransform().m_row3);
        sphereShape.m_fSphereRadius = b(3);
        newOperandA.SetCollisionShapeAndKey(&sphereShape, i);
        static_cast<CollisionQueryAgent*>(pair->m_pCollisionAgent)->getPenetrations(newOperandA, bodyB, input, collector);
    }
}

struct S_00d44e20_Collector
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    float m_fHitDistance;
    int m_iFilter;
    S_00d44e20_Collector(int filter) : m_fHitDistance(3.40282e+38f), m_iFilter(filter)
    {}
};

void hkpMultiSphereAgent_staticGetClosestPoints(void* b, void* a, void* c, S_00d44e20_Collector* collector);

// Constructs a collector with the given filter and runs FUN_00d445e0 over b, a and c with it.
// @fnv 0x00d44e20
// src: GUESS 0x00d44e20 (confidence: low)
void Object_ProcessState_00d44e20(void* apFirst, void* apSecond, void* apThird, int filter)
{
    S_00d44e20_Collector collector(filter);
    hkpMultiSphereAgent_staticGetClosestPoints(apSecond, apFirst, apThird, &collector);
}

extern char DAT_010ce81c;

struct S_00d44f50
{
    void ProcessSpheres(void* a, void* b, void* c, hkpSymmetricAgentFlipBodyCollector* collector);
    void RunWithCollector(void* a, void* b, void* c, int value);
};

// Constructs a collector holding value and forwards it with the reordered arguments to ProcessSpheres.
// @fnv 0x00d44f50
void S_00d44f50::RunWithCollector(void* pFirst, void* pSecond, void* pThird, int value)
{
    void* collectorStorage[sizeof(hkpSymmetricAgentFlipBodyCollector) / sizeof(void*)];
    hkpSymmetricAgentFlipBodyCollector& collector = *(hkpSymmetricAgentFlipBodyCollector*)collectorStorage;
    collector.payload = (void*)value;
    collector.unk04[0] = 0;
    *(void**)&collector = &DAT_010ce81c;
    ProcessSpheres(pSecond, pFirst, pThird, &collector);
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;

struct FUN_00d44f90_Data
{
    unsigned int descriptor;
    float bound;
    unsigned int value;
};

struct FUN_00d44f90_Class
{
    void GetPenetrations(void* first, void* second, void* third, FUN_00d44f90_Data* data);
    void UpdateState_00d44f90(void* first, void* second, void* third, unsigned int value);
};

// Builds a data record from value, DAT_0104da48 and DAT_010ce7fc, then calls GetPenetrations with second, first and third.
// @fnv 0x00d44f90
// src: GUESS 0x00d44f90 (confidence: low)
void FUN_00d44f90_Class::UpdateState_00d44f90(void* first, void* second, void* third, unsigned int value)
{
    FUN_00d44f90_Data data;
    data.value = value;
    data.bound = DAT_0104da48;
    data.descriptor = (unsigned int)&DAT_010ce7fc;
    GetPenetrations(second, first, third, &data);
}

struct Allocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};


extern char DAT_010cf390[];

struct SpawnedObject
{
    void* m_vptr;
    unsigned short m_iElementCount;
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

    void Init(int a, int b, int c, int d);
};

hkMemoryRouter* hkMemoryRouter_getInstance();

// @fnv 0x00d44d00
// src: GUESS 0x00d44d00 (confidence: medium)
void* Object_AllocateStorage_00d44d00(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
    Allocator* pAllocator = reinterpret_cast<Allocator*>(pAllocHolder->m_heap);
    SpawnedObject* obj = (SpawnedObject*)pAllocator->Alloc(0x38);
    obj->m_iElementCount = 0x38;
    obj->Init(aiArg2, aiArg1, aiArg3, aiArg4);
    *(void* volatile*)obj = (void*)DAT_010cf390;
    return obj;
}

struct FnTable
{
    void (*m_fn00)();
    void (*m_fn04)();
    void (*m_fn08)();
    void (*m_fn0C)();
    unsigned char m_flag10;
    unsigned char m_flag11;
};

struct RegistryOwner
{
    void RegisterTable(FnTable* table, int a, int b);
};

void Object_AllocateStorage_00d44d00();
void Object_UpdateFields_00d44de0();
void Object_ProcessState_00d44e20();
void Object_ProcessNegatedMultiSphereInput();
void Object_AllocateStorage_00d44cc0();
void hkpCdBody_AllocateStorage_00d449f0();
void hkpMultiSphereAgent_staticGetClosestPoints();
void ProcessMultiSphereCollision();

// Fills a FnTable with four function pointers and two flags, registers it with (-1, 0x15), then fills it with another set and registers it with (0x15, -1).
// @fnv 0x00d44d50
void RegisterTwoTables(RegistryOwner* apOwner)
{
    FnTable table;
    table.m_fn00 = Object_AllocateStorage_00d44d00;
    table.m_fn04 = Object_UpdateFields_00d44de0;
    table.m_fn08 = Object_ProcessState_00d44e20;
    table.m_fn0C = Object_ProcessNegatedMultiSphereInput;
    table.m_flag10 = 1;
    table.m_flag11 = 1;
    apOwner->RegisterTable(&table, -1, 0x15);

    table.m_fn00 = Object_AllocateStorage_00d44cc0;
    table.m_fn04 = hkpCdBody_AllocateStorage_00d449f0;
    table.m_fn08 = hkpMultiSphereAgent_staticGetClosestPoints;
    table.m_fn0C = ProcessMultiSphereCollision;
    table.m_flag10 = 0;
    table.m_flag11 = 1;
    apOwner->RegisterTable(&table, 0x15, -1);
}

extern char DAT_010ce81c;


void __cdecl hkpCdBody_AllocateStorage_00d449f0(void* a, void* b, void* c, void* d);

// Builds a temporary object holding a4 and a cleared flag, then calls FUN_00d449f0 with a2, a1, a3 and that object.
// @fnv 0x00d44de0
// src: GUESS 0x00d44de0 (confidence: low)
void __cdecl Object_UpdateFields_00d44de0(void* apArg1, void* apArg2, void* apArg3, unsigned int a4)
{
    void* collectorStorage[sizeof(hkpSymmetricAgentFlipBodyCollector) / sizeof(void*)];
    hkpSymmetricAgentFlipBodyCollector& t = *(hkpSymmetricAgentFlipBodyCollector*)collectorStorage;
    t.payload = (void*)a4;
    t.unk04[0] = 0;
    *(void**)&t = &DAT_010ce81c;
    hkpCdBody_AllocateStorage_00d449f0(apArg2, apArg1, apArg3, &t);
}

namespace fnv_00d450f0 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
extern int DAT_0102e388;

struct FUN_00d450f0_cls
{
    int m_vptr00;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    FUN_00d450f0_cls* Destroy(unsigned char acFlags);
};

// Frees the object's data array through the audio allocator, resets its fields, and optionally frees the object itself when acFlags bit 0 is set.
// @fnv 0x00d450f0
FUN_00d450f0_cls* FUN_00d450f0_cls::Destroy(unsigned char acFlags)
{
    hkMemoryRouter* pAudioHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pAudioHolder->m_heap);
    unsigned int uCapBits = m_uCapBits;
    m_iArrayLength = 0;
    if ((uCapBits & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pData, (uCapBits & 0x3fffffff) * 8);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    m_vptr00 = (int)&DAT_0102e388;
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d450f0

class CollisionAgentContext
{
  public:
    hkpCollisionDispatcher* dispatcher;
};
// @fnv 0x00d447f0
void __cdecl ProcessMultiSphereCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                         const CollisionAgentContext& input, void* output, void* manager)
{
    const hkpMultiSphereShape* shape = (const hkpMultiSphereShape*)bodyA.getShape();
    LocalM128 motionStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    ::new (motionStorage) hkMotionState(*bodyA.GetMotionState());
    hkMotionState& motion = *(hkMotionState*)motionStorage;
    LocalM128 sphereStorage[(sizeof(hkpSphereShape) + sizeof(LocalM128) - 1) / sizeof(LocalM128)];
    InitSphereShape((hkpSphereShape*)sphereStorage, 0.0f);
    hkpSphereShape& sphere = *(hkpSphereShape*)sphereStorage;
    hkpCdBody childBody(&bodyA, &motion);
    int typeB = bodyB.getShape()->getType();
    int index = 0;
    if (index < shape->m_iSphereCount)
    {
        const hkVector4* vector = shape->m_kSpheres;
        do
        {
            LocalM128 point = vector->m_vComponents;
            LocalM128 rotatedPoint =
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(point, point, 0x55),
                                                 motion.m_kMotionTransform.m_row1),
                                      _mm_mul_ps(_mm_shuffle_ps(point, point, 0),
                                                 motion.m_kMotionTransform.m_row0)),
                           _mm_mul_ps(_mm_shuffle_ps(point, point, 0xaa),
                                      motion.m_kMotionTransform.m_row2));
            motion.m_kMotionTransform.m_row3 =
                _mm_add_ps(rotatedPoint, bodyA.getTransform().m_row3);
            sphere.m_fSphereRadius = vector->m_vComponents.m128_f32[3];
            childBody.SetCollisionShapeAndKey(&sphere, index);
            ((void (__cdecl*)(const hkpCdBody&, const hkpCdBody&, const CollisionAgentContext&, void*, void*))
                input.dispatcher->m_agent2Funcs[input.dispatcher->m_agent2TypeMap[sphere.getType()][typeB]].m_pLinearCastFunc)(childBody, bodyB, input,
                                                                                             output, manager);
            ++index;
            ++vector;
        } while (index < shape->m_iSphereCount);
    }
}

struct SphereChildEntry
{
    int key;
    hkpCollisionAgent* agent;
};
struct SphereDispatch
{
    int unk00, unk04, unk08;
    SphereChildEntry* entries;
    int count;
    void ProcessSpheres(const hkpCdBody&, const hkpCdBody&, const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
// @fnv 0x00d44900
void SphereDispatch::ProcessSpheres(const hkpCdBody& aBody, const hkpCdBody& aOtherBody,
                                    const CollisionAgentContext& input, hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* shape = (const hkpMultiSphereShape*)aBody.getShape();
    LocalM128 motionStateStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    ::new (motionStateStorage) hkMotionState(*aBody.GetMotionState());
    hkMotionState& motionState = *(hkMotionState*)motionStateStorage;
    LocalM128 sphereStorage[(sizeof(hkpSphereShape) + sizeof(LocalM128) - 1) / sizeof(LocalM128)];
    InitSphereShape((hkpSphereShape*)sphereStorage, 0.0f);
    hkpSphereShape& sphere = *(hkpSphereShape*)sphereStorage;
    hkpCdBody cdBodyProxy(&aBody, &motionState);
    SphereChildEntry* entry = entries;
    for (int remaining = count - 1; remaining >= 0; remaining--)
    {
        const hkVector4& point = shape->m_kSpheres[entry->key];
        LocalM128 value = point.m_vComponents;
        LocalM128 worldPoint = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(value, value, 0x55),
                                             motionState.m_kMotionTransform.m_row1),
                                  _mm_mul_ps(_mm_shuffle_ps(value, value, 0),
                                             motionState.m_kMotionTransform.m_row0)),
                       _mm_mul_ps(_mm_shuffle_ps(value, value, 0xaa),
                                  motionState.m_kMotionTransform.m_row2)),
            aBody.getTransform().m_row3);
        motionState.m_kMotionTransform.m_row3 = worldPoint;
        sphere.m_fSphereRadius = point.m_vComponents.m128_f32[3];
        cdBodyProxy.SetCollisionShapeAndKey(&sphere, remaining);
        static_cast<CollisionQueryAgent*>(entry->agent)->getClosestPoints(cdBodyProxy, aOtherBody, input, collector);
        if (CollectorEarlyOut(collector))
            break;
        entry++;
    }
}

// @fnv 0x00d44cc0
// src: GUESS 0x00d44cc0 (confidence: medium)
void Object_AllocateStorage_00d44cc0(int a1, int a2, int a3, int a4)
{
    hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
    SpawnedObject* obj = (SpawnedObject*)pAllocHolder->m_heap->blockAlloc(0x38);
    obj->m_iElementCount = 0x38;
    obj->Init(a1, a2, a3, a4);
}

extern "C" LocalM128 _mm_xor_ps(LocalM128 _A, LocalM128 _B);
extern "C" void* __cdecl memcpy(void* _Dst, const void* _Src, unsigned int _Size);

extern char DAT_010ce80c;
extern LocalM128 DAT_010c44d0;
extern float DAT_0104da48;

union __declspec(align(16)) S_00d45160_Vec
{
    LocalM128 m_vComponents;
    struct S_00d45160_Components
    {
        int x;
        int y;
        int z;
        int w;
    } m_auiHeaderValues;
};

struct __declspec(align(16)) S_00d45160_Input
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
    S_00d45160_Vec m_vec;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

struct __declspec(align(16)) S_00d45160_Collector
{
    void* m_vtbl;
    float m_fHitDistance;
    int unk08;
    int unk0c;
    S_00d45160_Vec m_vec;
    unsigned int m_key;
};

class S_00d45160_Owner
{
  public:
    void Spawn(unsigned int a2, unsigned int a1, S_00d45160_Input* input, S_00d45160_Collector* out,
               S_00d45160_Collector* opt);
    void SpawnWithCollectors(unsigned int a1, unsigned int a2, const S_00d45160_Input* a3, unsigned int a4,
                             unsigned int a5);
};

// @fnv 0x00d45160
void S_00d45160_Owner::SpawnWithCollectors(unsigned int a1, unsigned int a2, const S_00d45160_Input* pInput,
                                           unsigned int uiKey1, unsigned int uiKey2)
{
    S_00d45160_Collector collector1;
    S_00d45160_Collector collector2;
    collector1.m_fHitDistance = DAT_0104da48;
    S_00d45160_Input inputCopy = *pInput;
    memcpy(&collector1.m_vec, &pInput->m_vec, 16);
    inputCopy.m_vec.m_vComponents = _mm_xor_ps(pInput->m_vec.m_vComponents, DAT_010c44d0);
    collector1.m_key = uiKey1;
    collector1.m_vtbl = (void*)&DAT_010ce80c;
    if (uiKey2 != 0)
    {
        collector2.m_vtbl = (void*)&DAT_010ce80c;
        collector2.m_fHitDistance = DAT_0104da48;
        memcpy(&collector2.m_vec, &pInput->m_vec, 16);
        collector2.m_key = uiKey2;
        Spawn(a2, a1, &inputCopy, &collector1, &collector2);
    }
    else
    {
        Spawn(a2, a1, &inputCopy, &collector1, 0);
    }
}

extern "C" LocalM128 _mm_load_ps(const float*);
struct S00d44fd0_Base
{
    void hkpMultiSphereAgent_processCollision(int a, int b, int c, unsigned char* obj);
};

struct S00d44fd0_Agent : S00d44fd0_Base
{
    void ProcessEntries_00d44fd0(int a1, int a2, int a3, unsigned char* obj);
};
extern LocalM128 DAT_010c4c00;

struct S00d44fd0_Nib
{
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct S00d44fd0_Cache
{
    unsigned short v[4];
    unsigned char dimA;
    unsigned char dimB;
    unsigned char lo : 4;
    unsigned char hi : 4;
};

template <class T> inline void S00d44fd0_swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

inline hkSimdReal BroadcastW(const hkVector4& vector)
{
    hkSimdReal scalar = *(const hkSimdReal*)&vector;
    scalar.m_vValue = _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0xff);
    return scalar;
}
inline void hkVector4::addMul4(const hkSimdReal& scalar, const hkVector4& vector)
{
    m_vComponents = _mm_add_ps(_mm_mul_ps(scalar.m_vValue, vector.m_vComponents), m_vComponents);
}
inline void hkVector4::setNeg4(const hkVector4& vector)
{
    m_vComponents = _mm_xor_ps(vector.m_vComponents, DAT_010c4c00);
}

struct S00d44fd0_Vert
{
    hkVector4 pos;
    hkVector4 nrm;
    int u20;
    int u24;
    int u28;
    int u2c;
};

// Calls FUN_00d443e0, then for each new vertex adds nrm*nrm.w to pos and negates nrm; if obj+0x3030 changed, negates obj+0x3020 and swaps fields of obj+0x3040.
// @fnv 0x00d44fd0
// src: GUESS 0x00d44fd0 (confidence: low)
void S00d44fd0_Agent::ProcessEntries_00d44fd0(int a1, int a2, int a3, unsigned char* obj)
{
    float saved = *(float*)(obj + 0x3030);
    S00d44fd0_Vert* pVert = *(S00d44fd0_Vert**)obj;
    S00d44fd0_Base::hkpMultiSphereAgent_processCollision(a2, a1, a3, obj);
    for (; pVert < *(S00d44fd0_Vert**)obj; pVert++)
    {
        pVert->pos.addMul4(BroadcastW(pVert->nrm), pVert->nrm);
        pVert->nrm.setNeg4(pVert->nrm);
    }
    if (saved != *(float*)(obj + 0x3030))
    {
        hkVector4* v = (hkVector4*)(obj + 0x3020);
        LocalM128 n = _mm_load_ps((const float*)v);
        v->m_vComponents = _mm_xor_ps(n, DAT_010c4c00);
        S00d44fd0_Cache* c = (S00d44fd0_Cache*)(obj + 0x3040);
        unsigned char nlo = c->lo;
        c->lo = c->hi;
        c->hi = nlo;
        unsigned char uDimB = c->dimB;
        unsigned char uDimA = c->dimA;
        c->dimA = uDimB;
        c->dimB = uDimA;
        int idx = c->dimA + c->dimB - 1;
        unsigned short t = c->v[0];
        c->v[0] = c->v[idx];
        c->v[idx] = t;
        if ((c->dimB & c->dimA) == 2)
        {
            unsigned short t2 = c->v[1];
            c->v[1] = c->v[2];
            c->v[2] = t2;
        }
    }
}

class hkpCdPointCollector;
struct Q_KeyAgentPair
{
    unsigned int m_key;
    hkpCollisionAgent* m_pCollisionAgent;
};
class Q_MultiSphereAgent
{
  public:
    void* m_vtbl;
    int unk04;
    int unk08;
    Q_KeyAgentPair* m_pAgents;
    int m_iElementCount;
    void hkpMultiSphereAgent_linearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

// Iterates each sphere in the multi-sphere shape, transforms it into world space, and delegates a linear cast to the per-sphere collision agent.
// @fnv 0x00d446f0
// src: HAVOK_SRC 0x00d446f0
void Q_MultiSphereAgent::hkpMultiSphereAgent_linearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                      const CollisionAgentContext& input, hkpCdPointCollector& collector,
                                      hkpCdPointCollector* startCollector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());

    LocalM128 msStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    ::new (msStorage) hkMotionState(*bodyA.GetMotionState());
    hkMotionState& ms = *(hkMotionState*)msStorage;
    LocalM128 sphereShapeStorage[(sizeof(hkpSphereShape) + sizeof(LocalM128) - 1) / sizeof(LocalM128)];
    InitSphereShape((hkpSphereShape*)sphereShapeStorage, 0.0f);
    hkpSphereShape& sphereShape = *(hkpSphereShape*)sphereShapeStorage;
    hkpCdBody newOperandA(&bodyA, &ms);
    Q_KeyAgentPair* agents = m_pAgents;

    for (int i = m_iElementCount - 1; i >= 0; i--)
    {
        const hkVector4& b = msA->m_kSpheres[i];
        const hkRotation& r = ms.m_kMotionTransform.getRotation();
        LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        LocalM128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
        LocalM128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
        LocalM128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
        ms.m_kMotionTransform.getTranslation().m_vComponents =
            _mm_add_ps(_mm_add_ps(_mm_add_ps(r1, r0), r2), bodyA.getTransform().getTranslation().m_vComponents);
        sphereShape.m_fSphereRadius = b(3);
        newOperandA.SetCollisionShapeAndKey(&sphereShape, i);
        static_cast<CollisionQueryAgent*>(agents->m_pCollisionAgent)->linearCast(newOperandA, bodyB, input, collector, startCollector);
    }
}

extern float DAT_0104da48;

struct __declspec(align(16)) Key_d2e9
{
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union
    {
        LocalM128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9
{
    const char* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl ProcessMultiSphereCollision(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

// Copies input with its vector negated, builds a record from a4 (and a second from a5 if non-zero), and calls ProcessMultiSphereCollision(a1, a2, ...).
// @fnv 0x00d44e60
// src: GUESS 0x00d44e60 (confidence: medium)
void __cdecl Object_ProcessNegatedMultiSphereInput(int a2, int a1, const Input_d2e9* input, int a4, int a5)
{
    Input_d2e9 localInput = *input;
    localInput.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = a4;

    if (a5 != 0)
    {
        Record_d2e9 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = a5;
        ProcessMultiSphereCollision(a1, a2, &localInput, &rec, &rec2);
    }
    else
    {
        ProcessMultiSphereCollision(a1, a2, &localInput, &rec, 0);
    }
}

extern "C" void _ReadWriteBarrier();
struct S_00d44b00_A;
struct S_00d44b00_Elem
{
    int first;
    int second;
};
struct LocalHolder : hkMemoryRouter
{
    hkMemoryAllocator& heap()
    {
        return *(hkMemoryAllocator*)m_heap;
    }
};
struct S_00d44b00_Arr;
extern void hkArrayUtil__reserve(hkMemoryAllocator* a, S_00d44b00_Arr* arr, int n, int elemSize);
struct S_00d44b00_Arr
{
    S_00d44b00_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    void reserve(hkMemoryAllocator& a, int n)
    {
        int cap = m_cap & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            hkArrayUtil__reserve(&a, this, (n < cap2) ? cap2 : n, 8);
        }
    }
    S_00d44b00_Elem* expandByUnchecked(int n)
    {
        int oldSize = m_iElementCount;
        m_iElementCount = oldSize + n;
        return m_data + oldSize;
    }
};
struct S_00d44b00_A
{
    hkpCollisionDispatcher* disp;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int flag;
};
inline int GetNewAgent(const hkpCollisionDispatcher& dispatcher, const hkpCdBody& a, const hkpCdBody& b,
                       const S_00d44b00_A& env, void* mgr)
{
    const int typeA = *(const int*)&a.getShape()->m_type;
    const int typeB = *(const int*)&b.getShape()->m_type;
    int predictive = env.flag;
    int idx = (predictive ? dispatcher.m_agent3TypeMap : dispatcher.m_agent2TypeMap)[typeA][typeB];
    typedef int (__cdecl* CreateFunc)(const hkpCdBody&, const hkpCdBody&, const S_00d44b00_A&, void*);
    CreateFunc f = (CreateFunc)dispatcher.m_agent2Funcs[idx].m_pCreateFunc;
    return f(a, b, env, mgr);
}
struct S_00d44b00_Inplace : S_00d44b00_Arr
{
    S_00d44b00_Elem inline0, inline1, inline2, inline3;
    S_00d44b00_Inplace()
    {
        m_data = &inline0;
        m_iElementCount = 0;
        m_cap = 0x80000004;
    }
};
extern char DAT_010cf354;
struct FUN_00d44b00 : hkpCollisionAgent
{
    virtual ~FUN_00d44b00() throw();
    S_00d44b00_Inplace arr;
    FUN_00d44b00(const hkpCdBody& src, const hkpCdBody& pb, const S_00d44b00_A& a, void* c);
};
// Reserves n entries, then for each of mesh's n vectors builds a transformed body context and stores the agent from a.disp->getNewAgent with key i.
// @fnv 0x00d44b00
FUN_00d44b00::FUN_00d44b00(const hkpCdBody& src, const hkpCdBody& pb, const S_00d44b00_A& a, void* c)
    : hkpCollisionAgent((hkpContactMgr*)c)
{
    const hkpMultiSphereShape* mesh = (const hkpMultiSphereShape*)src.getShape();
    int n = mesh->m_iSphereCount;
    arr.reserve(((LocalHolder*)hkMemoryRouter_getInstance())->heap(), n);
    LocalM128 shapeStorage[(sizeof(hkpSphereShape) + sizeof(LocalM128) - 1) / sizeof(LocalM128)];
    InitSphereShape((hkpSphereShape*)shapeStorage, 0.0f);
    hkpSphereShape& shape = *(hkpSphereShape*)shapeStorage;
    LocalM128 triStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    ::new (triStorage) hkMotionState(*(const hkMotionState*)src.m_pMotionState);
    hkMotionState& tri = *(hkMotionState*)triStorage;
    hkpCdBody ctx(&src, &tri);
    const hkVector4* v = mesh->m_kSpheres;
    for (int i = 0; i < n; i++)
    {
        LocalM128 q = *(LocalM128*)v;
        const hkMotionState* xf = (const hkMotionState*)src.m_pMotionState;
        LocalM128 p = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(q, q, 0x55), *(LocalM128*)&tri.m_kMotionTransform.m_row1),
                              _mm_mul_ps(_mm_shuffle_ps(q, q, 0x00), *(LocalM128*)&tri.m_kMotionTransform.m_row0));
        p = _mm_add_ps(p, _mm_mul_ps(_mm_shuffle_ps(q, q, 0xaa), *(LocalM128*)&tri.m_kMotionTransform.m_row2));
        *(LocalM128*)&tri.m_kMotionTransform.m_row3 = _mm_add_ps(*(LocalM128*)&xf->m_kMotionTransform.m_row3, p);
        *(LocalM128*)&tri.m_kSweptTransform.m_vCenterOfMass0 = _mm_add_ps(*(LocalM128*)&xf->m_kSweptTransform.m_vCenterOfMass0, p);
        *(LocalM128*)&tri.m_kSweptTransform.m_vCenterOfMass1 = _mm_add_ps(*(LocalM128*)&xf->m_kSweptTransform.m_vCenterOfMass1, p);
        shape.m_fSphereRadius = v->w;
        ctx.SetCollisionShapeAndKey(&shape, i);
        {
            S_00d44b00_Elem& e = *arr.expandByUnchecked(1);
            e.second = GetNewAgent(*a.disp, ctx, pb, a, c);
            e.first = i;
        }
        v++;
    }
}

extern "C" void _mm_store_ps(float* _V, LocalM128 _A);

struct S00d443e0_S_Entry
{
    int off;
    hkpCollisionAgent* child;
};


struct S00d443e0_S_Owner
{
    int unk0;
    int unk4;
    int unk8;
    S00d443e0_S_Entry* arr;
    int count;
    void hkpMultiSphereAgent_processCollision(hkpCdBody* in, int a, int b, int d);
};

// Iterates entries in reverse, adds a rotation term to the input copy, and dispatches each child's v6 with a shared context.
// @fnv 0x00d443e0
// src: HAVOK_SRC 0x00d443e0
void S00d443e0_S_Owner::hkpMultiSphereAgent_processCollision(hkpCdBody* in, int a, int b, int d)
{
    const hkpMultiSphereShape* base = static_cast<const hkpMultiSphereShape*>(in->getShape());
    LocalM128 copyStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    ::new (copyStorage) hkMotionState(*in->GetMotionState());
    hkMotionState& copy = *(hkMotionState*)copyStorage;
    LocalM128 collStorage[(sizeof(hkpSphereShape) + sizeof(LocalM128) - 1) / sizeof(LocalM128)];
    InitSphereShape((hkpSphereShape*)collStorage, 0.0f);
    hkpSphereShape& coll = *(hkpSphereShape*)collStorage;
    hkpCdBody ctx(in, &copy);
    S00d443e0_S_Entry* e = arr;
    for (int i = count - 1; i >= 0; --i)
    {
        const hkVector4& v = base->m_kSpheres[e->off];
        LocalM128 c0 = _mm_load_ps(&copy.m_kMotionTransform.m_row0.m128_f32[0]);
        LocalM128 c1 = _mm_load_ps(&copy.m_kMotionTransform.m_row1.m128_f32[0]);
        LocalM128 c2 = _mm_load_ps(&copy.m_kMotionTransform.m_row2.m128_f32[0]);
        LocalM128 vq = _mm_load_ps(&v.x);
        LocalM128 rot = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(vq, vq, 0x55), c1), _mm_mul_ps(_mm_shuffle_ps(vq, vq, 0), c0)),
            _mm_mul_ps(_mm_shuffle_ps(vq, vq, 0xaa), c2));
        const hkMotionState* t = in->GetMotionState();
        _mm_store_ps(&copy.m_kMotionTransform.m_row3.m128_f32[0], _mm_add_ps(_mm_load_ps(&t->m_kMotionTransform.m_row3.m128_f32[0]), rot));
        _mm_store_ps(&copy.m_kSweptTransform.m_vCenterOfMass0.m_vComponents.m128_f32[0], _mm_add_ps(_mm_load_ps(&t->m_kSweptTransform.m_vCenterOfMass0.m_vComponents.m128_f32[0]), rot));
        _mm_store_ps(&copy.m_kSweptTransform.m_vCenterOfMass1.m_vComponents.m128_f32[0], _mm_add_ps(_mm_load_ps(&t->m_kSweptTransform.m_vCenterOfMass1.m_vComponents.m128_f32[0]), rot));
        coll.m_fSphereRadius = v.w;
        ctx.m_pCollisionShape = (const hkpShape*)&coll;
        ctx.m_uiCollisionShapeKey = i;
        static_cast<CollisionQueryAgent*>(e->child)->processCollision(&ctx, a, b, d);
        e++;
    }
}

class CollisionAgentContext;

typedef void(__cdecl* GetPenetrationsFunc)(const hkpCdBody& a, const hkpCdBody& b, const CollisionAgentContext& input,
                                           hkpCdBodyPairCollector& collector);



// Iterates over each sphere of a multi-sphere shape, transforms it into world space, and dispatches penetration queries against bodyB.
// @fnv 0x00d445e0
// src: XBOX_PDB 0x00d445e0
void hkpMultiSphereAgent_staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                  hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());

    LocalM128 msStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    ::new (msStorage) hkMotionState(*bodyA.GetMotionState());
    hkMotionState& ms = *(hkMotionState*)msStorage;
    LocalM128 sphereShapeStorage[(sizeof(hkpSphereShape) + sizeof(LocalM128) - 1) / sizeof(LocalM128)];
    InitSphereShape((hkpSphereShape*)sphereShapeStorage, 0.0f);
    hkpSphereShape& sphereShape = *(hkpSphereShape*)sphereShapeStorage;
    hkpCdBody newOperandA(&bodyA, &ms);

    int typeB = bodyB.getShape()->getType();
    for (int i = 0; i < msA->m_iSphereCount; i++)
    {
        const hkVector4& b = msA->m_kSpheres[i];
        const hkTransform& r = ms.m_kMotionTransform;
        LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        LocalM128 r0 = _mm_mul_ps(b0, r.m_row0);
        LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        LocalM128 r1 = _mm_mul_ps(b1, r.m_row1);
        LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        LocalM128 r2 = _mm_mul_ps(b2, r.m_row2);
        ms.m_kMotionTransform.m_row3 =
            _mm_add_ps(_mm_add_ps(_mm_add_ps(r1, r0), r2), bodyA.getTransform().m_row3);
        sphereShape.m_fSphereRadius = b(3);
        newOperandA.SetCollisionShapeAndKey(&sphereShape, i);
        GetPenetrationsFunc func =
            (GetPenetrationsFunc)input.dispatcher->m_agent2Funcs[input.dispatcher->m_agent2TypeMap[sphereShape.getType()][typeB]].m_pGetPenetrationsFunc;
        func(newOperandA, bodyB, input, collector);
    }
}

class CollisionAgentContext;

typedef void(__cdecl* GetPenetrationsFunc)(const hkpCdBody& a, const hkpCdBody& b, const CollisionAgentContext& input,
                                           hkpCdBodyPairCollector& collector);



// Iterates over each sphere in a multi-sphere shape, transforms it, and queries penetrations against bodyB via the dispatcher's per-type collision function.
// @fnv 0x00d449f0
// src: GUESS 0x00d449f0 (confidence: low)
void hkpCdBody_AllocateStorage_00d449f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                  hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.getShape());

    LocalM128 msStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    ::new (msStorage) hkMotionState(*bodyA.GetMotionState());
    hkMotionState& ms = *(hkMotionState*)msStorage;
    LocalM128 sphereShapeStorage[(sizeof(hkpSphereShape) + sizeof(LocalM128) - 1) / sizeof(LocalM128)];
    InitSphereShape((hkpSphereShape*)sphereShapeStorage, 0.0f);
    hkpSphereShape& sphereShape = *(hkpSphereShape*)sphereShapeStorage;
    hkpCdBody newOperandA(&bodyA, &ms);

    int typeB = bodyB.getShape()->getType();
    for (int i = 0; i < msA->m_iSphereCount; i++)
    {
        const hkVector4& b = msA->m_kSpheres[i];
        const hkTransform& r = ms.m_kMotionTransform;
        LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
        LocalM128 r0 = _mm_mul_ps(b0, r.m_row0);
        LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
        LocalM128 r1 = _mm_mul_ps(b1, r.m_row1);
        LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
        LocalM128 r2 = _mm_mul_ps(b2, r.m_row2);
        ms.m_kMotionTransform.m_row3 =
            _mm_add_ps(_mm_add_ps(_mm_add_ps(r1, r0), r2), bodyA.getTransform().m_row3);
        sphereShape.m_fSphereRadius = b(3);
        newOperandA.SetCollisionShapeAndKey(&sphereShape, i);
        GetPenetrationsFunc func =
            input.dispatcher->m_agent2Funcs[input.dispatcher->m_agent2TypeMap[sphereShape.getType()][typeB]].m_pQueryPenetrationsFunc;
        func(newOperandA, bodyB, input, collector);
        if (CollectorEarlyOut(collector))
        {
            break;
        }
    }
}
