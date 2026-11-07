#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMotionState.h"
#include "../../../../../../include/hkSphere.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpCdBodyPairCollector.h"
#include "../../../../../../include/hkpHeightFieldShape.h"
#include "../../../../../../include/hkpShape.h"

// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern char DAT_010ceaa8[];


BSAudio* hkMemoryRouter_getInstance();
struct SizeSource {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual int GetCount();
};
struct SourceRef {
    SizeSource* m_p;
};
struct FUN_00d32060_Class {
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_flag;
    hkArray<unsigned short> m_aiIndexedValues;

    FUN_00d32060_Class* Init(const SourceRef& src, int b, int c, int flag);
};
extern void __cdecl hkpHeightFieldAgent_staticGetClosestPoints(void*, void*, void*, void*);
void __stdcall hkpHeightFieldAgent_getClosestPoints(void* apArg1, void* apArg2, void* apArg3, void* apArg4);
typedef void (*S_00d321e0_Func)();
void hkpHeightFieldAgent_createHeightFieldAAgent();
void hkpHeightFieldAgent_staticGetPenetrations_UpdateState_00d32370();
void hkpHeightFieldAgent_staticGetClosestPoints_ProcessState_00d323b0();
void Hkpheightfieldagent_UpdateState_00d323f0();
void AllocateTargetObj();
void hkpHeightFieldAgent_staticGetPenetrations();
void hkpHeightFieldAgent_staticGetClosestPoints();
void hkpHeightFieldAgent_ProcessSphereQueries();
struct S_00d321e0_AgentFuncs {
    S_00d321e0_Func m_pCreateFunc;
    S_00d321e0_Func m_pQueryPenetrationsFunc;
    S_00d321e0_Func m_pGetPenetrationsFunc;
    S_00d321e0_Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d321e0_Dispatcher {
    void AppendRecordAndRegisterAgents(S_00d321e0_AgentFuncs& f, int typeA, int typeB);
};
void hkpHeightFieldAgent_registerAgent(S_00d321e0_Dispatcher* dispatcher);
extern float g_D323B0MaxDistance;
struct D323B0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D323B0CollectorBase() : m_fEarlyOutDistance(g_D323B0MaxDistance) {}
};
struct D323B0Collector : D323B0CollectorBase {
    int m_iData;

    D323B0Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};
void __cdecl hkpHeightFieldAgent_staticGetClosestPoints(int a, int b, int c, D323B0CollectorBase* collector);
void __cdecl hkpHeightFieldAgent_staticGetClosestPoints_ProcessState_00d323b0(int aiArg1, int aiArg2, int aiArg3, int aiData);
struct Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void invoke(unsigned short item, int value);
};
struct Owner {
    virtual void clear(unsigned int mode);
    int unk04;
    Handler* callback;
    unsigned short* indices;
    int count;
    void NotifyAndClear(int value);
};
extern "C" void __cdecl hkpHeightFieldAgent_ProcessSphereQueries(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
// Forwards all five arguments unchanged to FUN_00d31d30.
// @fnv 0x00d32030
// src: HAVOK_SRC 0x00d32030
extern "C" void __stdcall hkpHeightFieldAgent_linearCast(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4)
{
    hkpHeightFieldAgent_ProcessSphereQueries(arg0, arg1, arg2, arg3, arg4);
}
extern "C" void __cdecl hkpHeightFieldAgent_staticGetPenetrations(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d32150
// src: HAVOK_SRC 0x00d32150
extern "C" void __stdcall hkpHeightFieldAgent_getPenetrations(void* arg0, void* arg1, void* arg2, void* arg3)
{
    hkpHeightFieldAgent_staticGetPenetrations(arg0, arg1, arg2, arg3);
}
extern char DAT_010ce81c;
void __cdecl hkpHeightFieldAgent_staticGetPenetrations(int a1, int a2, int a3, void* a4);
struct FUN_00d32370_cls {
    void* vt;
    unsigned char flag;
    int d;
};
void __cdecl hkpHeightFieldAgent_staticGetPenetrations_UpdateState_00d32370(int aiArg1, int aiArg2, int aiArg3, int a4);
#include <xmmintrin.h>
#include "../../../../../../include/hkpCdPointCollector.h"
namespace N {
// Exe 0x00d319e0 FUN_00d319e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {float m128_f32[4];} __m128, LocalM128;
extern "C" {
LocalM128 _mm_add_ps(LocalM128,LocalM128); LocalM128 _mm_mul_ps(LocalM128,LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int); LocalM128 _mm_unpackhi_ps(LocalM128,LocalM128);
LocalM128 _mm_load_ss(const float*);
}
}
extern unsigned long DAT_0126835c;
extern const char DAT_010cea38[];
extern const char DAT_010cea7c[];
extern const char DAT_010cea6c[];
extern const char DAT_010cea60[];
extern const char DAT_010cea54[];
extern const char DAT_010cea48[];
extern const char DAT_01076f38[];
extern const char str_010cea1c[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
struct MonitorCommand {
    const char* name;
    unsigned int time;
    unsigned int timeHi;
    const char* subName;
};

__forceinline hkMonitorStream& hkMonitorStream::getInstance() {
        return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    }
// The original's timer helpers (expansions of Havok's timer macros), kept as members of a unit-local view so the
// inlined code keeps its shape.
struct StringCursor_hkpheightfieldagent_rtm_variant : hkMonitorStream
{
    void timerBegin(const char* name);
    void timerBegin(const char* name1, const char* name2);
    void timerEnd(const char* name);
    void timerSplit(const char* name);
};
__forceinline void StringCursor_hkpheightfieldagent_rtm_variant::timerBegin(const char* name1, const char* name2) {
        if (m_end.m_storage < m_capacityMinus16.m_storage) {
            MonitorCommand* cmd = (MonitorCommand*)m_end.m_storage;
            cmd->name = name1;
            cmd->subName = name2;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            cmd->time = ticks;
            m_end.m_storage = (char*)(cmd + 1);
        }
    }
__forceinline void StringCursor_hkpheightfieldagent_rtm_variant::timerSplit(const char* name) {
        if (m_end.m_storage < m_capacityMinus16.m_storage) {
            MonitorCommand* cmd = (MonitorCommand*)m_end.m_storage;
            cmd->name = name;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            cmd->time = ticks;
            m_end.m_storage = (char*)cmd + 12;
        }
    }
__forceinline void StringCursor_hkpheightfieldagent_rtm_variant::timerEnd(const char* name) { timerSplit(name); }

__forceinline void hkVector4::SetRotatedDirection(const hkTransform& a, const hkVector4& b) {
    N::LocalM128 y = N::_mm_shuffle_ps((*(N::LocalM128*)&b.m_vComponents), (*(N::LocalM128*)&b.m_vComponents), 0x55);
    N::LocalM128 x = N::_mm_shuffle_ps((*(N::LocalM128*)&b.m_vComponents), (*(N::LocalM128*)&b.m_vComponents), 0x00);
    N::LocalM128 z = N::_mm_shuffle_ps((*(N::LocalM128*)&b.m_vComponents), (*(N::LocalM128*)&b.m_vComponents), 0xaa);
    (*(N::LocalM128*)&m_vComponents) = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, (*(N::LocalM128*)&a.m_row1)), N::_mm_mul_ps(x, (*(N::LocalM128*)&a.m_row0))), N::_mm_mul_ps(z, (*(N::LocalM128*)&a.m_row2)));
}
__forceinline void hkVector4::SetTransformedPoint(const hkTransform& a, const hkVector4& b) {
    N::LocalM128 y = N::_mm_shuffle_ps((*(N::LocalM128*)&b.m_vComponents), (*(N::LocalM128*)&b.m_vComponents), 0x55);
    N::LocalM128 x = N::_mm_shuffle_ps((*(N::LocalM128*)&b.m_vComponents), (*(N::LocalM128*)&b.m_vComponents), 0x00);
    N::LocalM128 z = N::_mm_shuffle_ps((*(N::LocalM128*)&b.m_vComponents), (*(N::LocalM128*)&b.m_vComponents), 0xaa);
    (*(N::LocalM128*)&m_vComponents) = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, (*(N::LocalM128*)&a.m_row1)), N::_mm_mul_ps(x, (*(N::LocalM128*)&a.m_row0))), N::_mm_add_ps(N::_mm_mul_ps(z, (*(N::LocalM128*)&a.m_row2)), (*(N::LocalM128*)&a.m_row3)));
}
__forceinline void transformSphere(hkVector4& __restrict out, const hkTransform& __restrict a, const hkVector4& __restrict sphere) {
    N::LocalM128 y = N::_mm_shuffle_ps((*(N::LocalM128*)&sphere.m_vComponents), (*(N::LocalM128*)&sphere.m_vComponents), 0x55);
    N::LocalM128 x = N::_mm_shuffle_ps((*(N::LocalM128*)&sphere.m_vComponents), (*(N::LocalM128*)&sphere.m_vComponents), 0x00);
    N::LocalM128 z = N::_mm_shuffle_ps((*(N::LocalM128*)&sphere.m_vComponents), (*(N::LocalM128*)&sphere.m_vComponents), 0xaa);
    N::LocalM128 pos = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, (*(N::LocalM128*)&a.m_row1)), N::_mm_mul_ps(x, (*(N::LocalM128*)&a.m_row0))), N::_mm_add_ps(N::_mm_mul_ps(z, (*(N::LocalM128*)&a.m_row2)), (*(N::LocalM128*)&a.m_row3)));
    N::LocalM128 unpck = N::_mm_unpackhi_ps(pos, (*(N::LocalM128*)&sphere.m_vComponents));
    (*(N::LocalM128*)&out.m_vComponents) = N::_mm_shuffle_ps(pos, unpck, 0xc4);
}

__forceinline void transformSpheres(const hkTransform& tr, const hkSphere* src, int count, hkSphere* dst) {
    N::LocalM128 col0 = *(const N::LocalM128*)&tr.m_row0;
    N::LocalM128 col1 = *(const N::LocalM128*)&tr.m_row1;
    N::LocalM128 col2 = *(const N::LocalM128*)&tr.m_row2;
    N::LocalM128 translation = *(const N::LocalM128*)&tr.m_row3;
    int i = count - 1;
    do {
        hkVector4 value;
        N::LocalM128 sphere = *(const N::LocalM128*)&src[i].m_pos.m_vComponents;
        N::LocalM128 y = N::_mm_shuffle_ps(sphere, sphere, 0x55);
        N::LocalM128 x = N::_mm_shuffle_ps(sphere, sphere, 0x00);
        N::LocalM128 z = N::_mm_shuffle_ps(sphere, sphere, 0xaa);
        (*(N::LocalM128*)&value.m_vComponents) = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, col1), N::_mm_mul_ps(x, col0)), N::_mm_add_ps(N::_mm_mul_ps(z, col2), translation));
        (*(N::LocalM128*)&value.m_vComponents) = N::_mm_shuffle_ps((*(N::LocalM128*)&value.m_vComponents),N::_mm_unpackhi_ps((*(N::LocalM128*)&value.m_vComponents),(*(N::LocalM128*)&src[i].m_pos.m_vComponents)),0xc4);
        (*(N::LocalM128*)&dst[i].m_pos.m_vComponents) = (*(N::LocalM128*)&value.m_vComponents);
    } while (--i >= 0);
}

struct CollisionSphereData {
    __forceinline void setSpheres(const hkSphere* p){ m_kSpheres=p; }
    const hkSphere* m_kSpheres;
    int m_iSphereCount;
    float m_fScalar;
};

struct CollisionAgentContext {
    int unk00;
    int unk04;
    float m_fScalar;
};

struct ContactPointPair {
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
    ContactPointPair() {}
    __forceinline ContactPointPair(const hkpCdBody* a, const hkpCdBody* b) : m_pBodyA(a), m_pBodyB(b) {}
};
struct CollisionScratch { hkTransform transform; ContactPointPair contact; };

void __cdecl hkpHeightFieldAgent_staticGetPenetrations(int a1, int a2, int a3, void* a4);

// @fnv 0x00d319e0
// src: XBOX_PDB 0x00d319e0
void __cdecl hkpHeightFieldAgent_staticGetClosestPoints(int a, int b, int c, D323B0CollectorBase* collector)
{
    const hkpCdBody* bodyA = (const hkpCdBody*)a;
    const hkpCdBody* bodyB = (const hkpCdBody*)b;
    const CollisionAgentContext* input = (const CollisionAgentContext*)c;

    static_cast<StringCursor_hkpheightfieldagent_rtm_variant&>(hkMonitorStream::getInstance()).timerBegin(DAT_010cea38, DAT_010cea7c);

    const hkpShape* shapeA = bodyA->m_pCollisionShape;
    hkpHeightFieldShape* shapeB = (hkpHeightFieldShape*)bodyB->m_pCollisionShape;
    // SIMD scratch storage preserves the original frame: a local shared hkTransform
    // contains the SDK __m128 byte lanes and would introduce a VC9 /GS cookie.
    N::LocalM128 scratchStorage[sizeof(CollisionScratch) / sizeof(N::LocalM128)];
    CollisionScratch& scratch = *(CollisionScratch*)scratchStorage;
    scratch.transform.hkTransform_setMulInverseMul(bodyB->m_pMotionState, bodyA->m_pMotionState);

    // These sphere-representation virtual slots are absent from shared hkpShape.
    int count = ((int (__thiscall*)(const hkpShape*))(*(void***)shapeA)[11])(shapeA);

    BSAudio* q = hkMemoryRouter_getInstance();
    char* cur1 = (char*)*(int*)q;
    hkSphere* sphereBuffer = (hkSphere*)cur1;
    *(int*)q = (int)(cur1 + ((count * 16 + 127) & ~127));

    static_cast<StringCursor_hkpheightfieldagent_rtm_variant&>(hkMonitorStream::getInstance()).timerSplit(DAT_010cea6c);

    const hkSphere* spheres = ((const hkSphere* (__thiscall*)(const hkpShape*, hkSphere*))(*(void***)shapeA)[12])(shapeA, sphereBuffer);

    static_cast<StringCursor_hkpheightfieldagent_rtm_variant&>(hkMonitorStream::getInstance()).timerSplit(DAT_010cea60);

    transformSpheres(scratch.transform, spheres, count, sphereBuffer);

    static_cast<StringCursor_hkpheightfieldagent_rtm_variant&>(hkMonitorStream::getInstance()).timerSplit(DAT_010cea54);

    const CollisionAgentContext* __restrict in = input;
    BSAudio* bs2 = hkMemoryRouter_getInstance();
    char* cur2 = (char*)*(int*)bs2;
    hkSphere* hitResults = (hkSphere*)cur2;
    {
        CollisionSphereData shB;
        shB.m_kSpheres = sphereBuffer;
        *(int*)bs2 = (int)(cur2 + ((count * 16 + 127) & ~127));
        shB.m_iSphereCount = count;
        shB.m_fScalar = in->m_fScalar;
        shapeB->CollideSpheres(shB, hitResults);
    }

    static_cast<StringCursor_hkpheightfieldagent_rtm_variant&>(hkMonitorStream::getInstance()).timerSplit(DAT_010cea48);

    float tolerance = in->m_fScalar;
    const hkSphere* __restrict hitPtr = hitResults;
    const hkSphere* __restrict spherePtr = sphereBuffer;
    for (int i = count - 1; i >= 0; ++hitPtr, ++spherePtr, --i) {
        const hkSphere& __restrict hit = *hitPtr;
        if ((*(N::LocalM128*)&hit.m_pos.m_vComponents).m128_f32[3] <= tolerance) {
            ContactPointPair& point = scratch.contact;
            point.m_pBodyA = bodyA;
            point.m_pBodyB = bodyB;
            float distToPoint = -(*(N::LocalM128*)&spherePtr->m_pos.m_vComponents).m128_f32[3] - (*(N::LocalM128*)&hit.m_pos.m_vComponents).m128_f32[3];

            hkVector4 posInB;
            N::LocalM128 dist4 = N::_mm_load_ss(&distToPoint);
            dist4 = N::_mm_shuffle_ps(dist4,dist4,0);
            (*(N::LocalM128*)&posInB.m_vComponents) = N::_mm_add_ps(N::_mm_mul_ps(dist4, (*(N::LocalM128*)&hit.m_pos.m_vComponents)), (*(N::LocalM128*)&spherePtr->m_pos.m_vComponents));

            point.m_kPoint.m_vContactPosition.SetTransformedPoint(((const hkMotionState*)bodyB->m_pMotionState)->m_kMotionTransform, posInB);
            point.m_kPoint.m_vSeparatingNormal.SetRotatedDirection(((const hkMotionState*)bodyB->m_pMotionState)->m_kMotionTransform, *(const hkVector4*)&hit.m_pos);
            point.m_kPoint.m_vSeparatingNormal.w = (*(N::LocalM128*)&hit.m_pos.m_vComponents).m128_f32[3];

            ((hkpCdPointCollector*)collector)->AddCdPoint(point);
        }
    }

    *(int*)hkMemoryRouter_getInstance() = (int)hitResults;
    *(int*)hkMemoryRouter_getInstance() = (int)sphereBuffer;

    static_cast<StringCursor_hkpheightfieldagent_rtm_variant&>(hkMonitorStream::getInstance()).timerEnd(DAT_01076f38);
}

struct Scale {
    N::LocalM128 value;
    Scale(float f) { value = N::_mm_load_ss(&f); }
    __forceinline N::LocalM128 repeated() const { return N::_mm_shuffle_ps(value,value,0); }
};
static __forceinline void S_combine(hkVector4& out, const hkVector4& start, const hkVector4& direction, const Scale& amount) {
    (*(N::LocalM128*)&out.m_vComponents) = N::_mm_add_ps((*(N::LocalM128*)&start.m_vComponents), N::_mm_mul_ps(amount.repeated(), (*(N::LocalM128*)&direction.m_vComponents)));
}
static __forceinline void S_accumulate(hkVector4& out, const Scale& amount, const hkVector4& direction) {
    (*(N::LocalM128*)&out.m_vComponents) = N::_mm_add_ps((*(N::LocalM128*)&out.m_vComponents), N::_mm_mul_ps(amount.repeated(), (*(N::LocalM128*)&direction.m_vComponents)));
}
static __forceinline void S_rotate(hkVector4& out, const hkTransform& matrix, const hkVector4& input) {
    N::LocalM128 first = N::_mm_mul_ps((*(N::LocalM128*)&matrix.m_row0), N::_mm_shuffle_ps((*(N::LocalM128*)&input.m_vComponents),(*(N::LocalM128*)&input.m_vComponents),0));
    N::LocalM128 second = N::_mm_mul_ps((*(N::LocalM128*)&matrix.m_row1), N::_mm_shuffle_ps((*(N::LocalM128*)&input.m_vComponents),(*(N::LocalM128*)&input.m_vComponents),0x55));
    N::LocalM128 third = N::_mm_mul_ps((*(N::LocalM128*)&matrix.m_row2), N::_mm_shuffle_ps((*(N::LocalM128*)&input.m_vComponents),(*(N::LocalM128*)&input.m_vComponents),0xaa));
    (*(N::LocalM128*)&out.m_vComponents) = N::_mm_add_ps(N::_mm_add_ps(first, second), third);
}

struct S_00d32270_In;
struct S_00d32270_Target
{
    virtual void v00();
    virtual void v04(struct S_00d32270_In* in);
    float m_04;
};

struct S_00d32270_Q
{
    int unk00;
    int unk04;
    hkTransform* m_08;
};

struct S_00d32270_P
{
    hkVector4 v00;
    float f10;
};

struct S_00d32270_cls
{
    int unk00;
    float m_04;
    int unk08;
    int unk0c;
    hkVector4 m_10;
    float m_20;
    int unk24;
    int unk28;
    int unk2c;
    hkVector4 m_30;
    int m_40;
    S_00d32270_Target* m_44;
    void hkHeightFieldRayForwardingCollector_addRayHit(S_00d32270_Q* q, S_00d32270_P* p);
};

struct S_00d32270_In
{
    hkVector4 a;
    hkVector4 b;
    int m40;
    S_00d32270_Q* q;
    S_00d32270_In(int a, S_00d32270_Q* b) : m40(a), q(b) {}
};

static __forceinline float S_min(float a, float b) { return (b < a) ? b : a; }

// @fnv 0x00d32270
// src: XBOX_PDB 0x00d32270
void S_00d32270_cls::hkHeightFieldRayForwardingCollector_addRayHit(S_00d32270_Q* q, S_00d32270_P* p)
{
    __declspec(align(16)) S_00d32270_In in(m_40, q);
    float s = -m_20;
    float t = p->f10;
    S_combine(in.a, m_10, m_30, Scale(p->f10));
    S_rotate(in.b, *q->m_08, p->v00);
    S_accumulate(in.a, Scale(s), in.b);
    in.b.w = t;
    m_44->v04(&in);
    float o = m_44->m_04;
    m_04 = S_min(m_04, o);
}
