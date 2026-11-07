#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// Keep the original intrinsic representation: the SDK union's byte arrays
// add /GS instrumentation with the original compiler.
#define _INCLUDED_MM2
// Exe 0x00d3b8e0 FUN_00d3b8e0: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef struct __declspec(intrin_type) __declspec(align(16)) { float x, y, z, w; } __m128, LocalM128;
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

#include <string.h>

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpCapsuleShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpIterativeLinearCastAgent.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"

// src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Callback
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void invoke(unsigned short, int);
};

struct FUN_00d3b3d0_Class
{
    virtual void release(int);
    int unk04;
    Callback* unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    void InvokeCallbacksAndRelease(int);
};

// Calls invoke on unk08 for each of the three IDs at unk0C unless it is 0xffff, then releases the object.
// @fnv 0x00d3b3d0
void FUN_00d3b3d0_Class::InvokeCallbacksAndRelease(int value)
{
    unsigned short* id = &unk0C;
    int iRemaining = 3;
    do
    {
        unsigned short usId = *id;
        if (usId != 0xffff)
            unk08->invoke(usId, value);
        ++id;
        --iRemaining;
    } while (iRemaining != 0);

    if (this != 0)
        release(1);
}

typedef void (__cdecl* HandlerFn)();

void __cdecl hkpCapsuleCapsuleAgent_createCapsuleCapsuleAgent();
void __cdecl hkpCapsuleCapsuleAgent_staticGetPenetrations();
void __cdecl UpdateFields_00d3bd80();
void __cdecl Object_ProcessEntries_00daf8e0();

struct HandlerSet {
    HandlerFn m_pfnFirst;
    HandlerFn m_pfnSecond;
    HandlerFn m_pfnThird;
    HandlerFn m_pfnFourth;
    char m_cFlagA;
    char m_cFlagB;
};

struct Registry {
    void AppendRecordAndRegisterAgents(HandlerSet* apHandlers, int aiFirst, int aiSecond);
};

// Fills a HandlerSet with four handler functions and zeroed flags, then registers it with the registry using 5 and 5.
// @fnv 0x00d3c010
void __cdecl RegisterHandlers(Registry* apRegistry)
{
    HandlerSet kHandlers;
    kHandlers.m_cFlagA = 0;
    kHandlers.m_cFlagB = 0;
    kHandlers.m_pfnFirst = hkpCapsuleCapsuleAgent_createCapsuleCapsuleAgent;
    kHandlers.m_pfnSecond = hkpCapsuleCapsuleAgent_staticGetPenetrations;
    kHandlers.m_pfnThird = UpdateFields_00d3bd80;
    kHandlers.m_pfnFourth = Object_ProcessEntries_00daf8e0;

    apRegistry->AppendRecordAndRegisterAgents(&kHandlers, 5, 5);
}

void __cdecl hkpCapsuleCapsuleAgent_staticGetPenetrations(const void* a, const void* b, const void* c, void* d);

struct D3B6D0Agent {
    virtual void ForwardToHandler(const void* a, const void* b, const void* c, void* d);
};

// @fnv 0x00d3b6d0
void D3B6D0Agent::ForwardToHandler(const void* apArg1, const void* apArg2, const void* apArg3, void* apArg4)
{
    hkpCapsuleCapsuleAgent_staticGetPenetrations(apArg1, apArg2, apArg3, apArg4);
}

struct MatrixVector { float x, y, z, w; };
struct __declspec(align(16)) MatrixRow { MatrixVector scalar; };
struct Mat44 { MatrixVector row0, row1, row2, row3; };
struct JointTransform {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float blend;
    float unk14;
    float unk18;
    float unk1C;
    float frameVectors[8];
};
struct TransformInput {
    JointTransform* bone;
    int unk04;
    const Mat44* matrix;
};
struct BlendParameter {
    float unk00;
    float unk04;
    float fraction;
};

void __cdecl hkCollideCapsuleUtilClostestPointCapsVsCaps(const void* a, float fraction, const void* b, float weightA, float weightB, int flags);

// Transforms each bone's two frameVectors by its matrix, then calls FUN_00cd6260 with the results, each bone's blend value and the parameter's fraction.
// @fnv 0x00d3b8e0
// src: XBOX_PDB 0x00d3b8e0
static __declspec(noinline) void __cdecl getClosestPointInternal_00d3b8e0(TransformInput* first, TransformInput* second, const BlendParameter* parameter, int flags)
{
    JointTransform* firstBone = first->bone;
    JointTransform* secondBone = second->bone;
    __declspec(align(16)) LocalM128 firstResult[2];
    MatrixRow a0;
    a0.scalar = first->matrix->row0;
    MatrixRow a1;
    a1.scalar = first->matrix->row1;
    MatrixRow a2;
    a2.scalar = first->matrix->row2;
    MatrixRow a3;
    a3.scalar = first->matrix->row3;

    for (int index = 1; index >= 0; --index) {
        LocalM128 v = _mm_load_ps(firstBone->frameVectors + index * 4);
        LocalM128 xy = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), *reinterpret_cast<LocalM128*>(&a1.scalar)),
                                _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), *reinterpret_cast<LocalM128*>(&a0.scalar)));
        LocalM128 zw = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), *reinterpret_cast<LocalM128*>(&a2.scalar)), *reinterpret_cast<LocalM128*>(&a3.scalar));
        firstResult[index] = _mm_add_ps(xy, zw);
    }

    __declspec(align(16)) LocalM128 secondResult[2];
    MatrixRow b0;
    b0.scalar = second->matrix->row0;
    MatrixRow b1;
    b1.scalar = second->matrix->row1;
    MatrixRow b2;
    b2.scalar = second->matrix->row2;
    MatrixRow b3;
    b3.scalar = second->matrix->row3;

    for (int index = 1; index >= 0; --index) {
        LocalM128 v = _mm_load_ps(secondBone->frameVectors + index * 4);
        LocalM128 xy = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), *reinterpret_cast<LocalM128*>(&b1.scalar)),
                                _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), *reinterpret_cast<LocalM128*>(&b0.scalar)));
        LocalM128 zw = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), *reinterpret_cast<LocalM128*>(&b2.scalar)), *reinterpret_cast<LocalM128*>(&b3.scalar));
        secondResult[index] = _mm_add_ps(xy, zw);
    }

    volatile float fraction = parameter->fraction;
    volatile float weightB = secondBone->blend;
    volatile float weightA = firstBone->blend;
    hkCollideCapsuleUtilClostestPointCapsVsCaps(firstResult, weightA, secondResult, weightB, fraction, flags);
}
TransformInput* volatile inputFirst;
TransformInput* volatile inputSecond;
const BlendParameter* volatile inputParameter;
volatile int inputFlags;
void invoke_transform() { getClosestPointInternal_00d3b8e0(inputFirst, inputSecond, inputParameter, inputFlags); }

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

#include "../../../../../../../include/hkResult.h"
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;


// The approved hkVector4 header predates lengthInverse3 and still leaves the
// empty constructor to each unit; the newer header supplies it inline.
__if_not_exists(hkVector4::lengthInverse3)
{
}

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }

typedef LocalM128 hkQuadReal;

typedef const hkVector4&hkVector4Parameter;

__forceinline const hkVector4& hkRotation::getColumn(int x) const
{
return (&m_kColumn0)[x];
}
static __forceinline void SetTransformedPos(hkVector4& out,const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
out.m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
__forceinline const hkVector4&hkTransform::getTranslation()const
{
return *reinterpret_cast<const hkVector4*>(&m_row3);
}
__forceinline const hkRotation&hkTransform::getRotation()const
{
return *reinterpret_cast<const hkRotation*>(&m_row0);
}
__forceinline hkTransform::hkTransform(const hkTransform&t)
{
// Preserve scalar row copies independently of hkVector4's copy constructor.
MatrixRow r0;
memcpy(&r0.scalar, &t.getRotation().getColumn(0), sizeof(MatrixVector));
MatrixRow r1;
memcpy(&r1.scalar, &t.getRotation().getColumn(1), sizeof(MatrixVector));
MatrixRow r2;
memcpy(&r2.scalar, &t.getRotation().getColumn(2), sizeof(MatrixVector));
MatrixRow r3;
memcpy(&r3.scalar, &t.getTranslation(), sizeof(MatrixVector));
m_row0=*reinterpret_cast<const LocalM128*>(&r0.scalar);
m_row1=*reinterpret_cast<const LocalM128*>(&r1.scalar);
m_row2=*reinterpret_cast<const LocalM128*>(&r2.scalar);
m_row3=*reinterpret_cast<const LocalM128*>(&r3.scalar);}

__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
typedef hkUint16 hkContactPointId;
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};

typedef hkUint32 hkpShapeKey;

__forceinline const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
__forceinline const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
struct WorldOperationEntry;
class hkpCollisionDispatcher;
class hkpConstraintOwner;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;};
class hkpCdBodyPairCollector;
struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};


class hkpCapsuleCapsuleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl UpdateFields_00d3bd80(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&info);
protected:
__forceinline hkpCapsuleCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createCapsuleCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
hkContactPointId m_usContactPointId[3];
};

__forceinline const hkVector4*hkpCapsuleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}
extern "C"
{
hkResult __cdecl FindCapsuleCapsuleContact(const hkVector4*capsA,hkReal capsARadius,const hkVector4*capsB,hkReal capsBRadius,hkReal collisionTolerance,hkContactPoint&pointOut);}
namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
SetTransformedPos(vectorsOut[i],unaliased,vectorsIn[i]);
}while(--i>=0);}
static __forceinline hkResult getClosestPointInternal(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint)
{
const hkpCapsuleShape*capsuleA=static_cast<const hkpCapsuleShape*>(bodyA.getShape());
const hkpCapsuleShape*capsuleB=static_cast<const hkpCapsuleShape*>(bodyB.getShape());
hkVector4 pA[2];hkVector4Util_S::TransformPointArray(bodyA.getTransform(),capsuleA->GetIndexedVertices(),2,pA);
hkVector4 pB[2];hkVector4Util_S::TransformPointArray(bodyB.getTransform(),capsuleB->GetIndexedVertices(),2,pB);
return FindCapsuleCapsuleContact(pA,capsuleA->getRadius(),pB,capsuleB->getRadius(),input.getTolerance(),cpoint);}
// @fnv 0x00d3bd80
// src: GUESS 0x00d3bd80 (confidence: low)
void __cdecl hkpCapsuleCapsuleAgent::UpdateFields_00d3bd80(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.getEnd()<mStream.getCapacityMinus16()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "CapsCaps";h->setTime();mStream.setEnd((char*)(h+1));}};
ContactPointPair event(bodyA,bodyB);
if(getClosestPointInternal(bodyA,bodyB,input,event.m_kPoint)==HK_SUCCESS)
{
collector.AddCdPoint(event);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.getEnd()<mStream.getCapacityMinus16()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}

class CapsulePointVector {
public:
    LocalM128 m_vComponents;
    __forceinline LocalM128 quadValue() const { return m_vComponents; }
    __forceinline const LocalM128& quadReference() const { return m_vComponents; }
    __forceinline void getQuad(LocalM128& out) const { out = m_vComponents; }
    __forceinline void setQuad(LocalM128 value) { m_vComponents = value; }
    __forceinline void setVector(const CapsulePointVector& value) { m_vComponents = value.m_vComponents; }

    float& operator()(int i) { return (&m_vComponents.x)[i]; }
    const float& operator()(int i) const { return (&m_vComponents.x)[i]; }
};

struct CapsulePointTransforms {
    static __forceinline void TransformPointArray(const hkTransform& t, const CapsulePointVector* vectorsIn, int numVectors, CapsulePointVector* vectorsOut, CapsulePointVector& scratch)
    {
        CapsulePointVector c0 = reinterpret_cast<const CapsulePointVector&>(t.m_row0);
        CapsulePointVector c1 = reinterpret_cast<const CapsulePointVector&>(t.m_row1);
        CapsulePointVector c2 = reinterpret_cast<const CapsulePointVector&>(t.m_row2);
        scratch = reinterpret_cast<const CapsulePointVector&>(t.m_row3);
        LocalM128 saved = _mm_load_ps((&scratch.m_vComponents.x));
        int i = numVectors - 1;
        do
        {
            const CapsulePointVector& b = vectorsIn[i];
            LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
            LocalM128 r0 = _mm_mul_ps(b0, c0.m_vComponents);
            LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
            LocalM128 r1 = _mm_mul_ps(b1, c1.m_vComponents);
            LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
            LocalM128 r2 = _mm_mul_ps(b2, c2.m_vComponents);
            vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, saved));
        } while (--i >= 0);
    }
    static __forceinline void transformPoints2(const hkTransform& t, const CapsulePointVector* vectorsIn, int numVectors, CapsulePointVector* vectorsOut)
    {
        vectorsOut[0] = reinterpret_cast<const CapsulePointVector&>(t.m_row0);
        LocalM128 saved = vectorsOut[0].m_vComponents;
        CapsulePointVector c1 = reinterpret_cast<const CapsulePointVector&>(t.m_row1);
        CapsulePointVector c2 = reinterpret_cast<const CapsulePointVector&>(t.m_row2);
        CapsulePointVector c3 = reinterpret_cast<const CapsulePointVector&>(t.m_row3);
        CapsulePointVector q1; q1.setQuad(_mm_load_ps((&c1.m_vComponents.x)));
        int i = numVectors - 1;
        do
        {
            const CapsulePointVector& b = vectorsIn[i];
            LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
            LocalM128 r0 = _mm_mul_ps(b0, saved);
            LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
            LocalM128 r1 = _mm_mul_ps(b1, q1.m_vComponents);
            LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
            LocalM128 r2 = _mm_mul_ps(b2, c2.m_vComponents);
            vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, c3.m_vComponents));
        } while (--i >= 0);
    }
};

extern "C" unsigned long DAT_0126835c;
extern "C" const char DAT_010d1074[];
extern "C" const char DAT_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

// hkMonitorStream::TimerCommand as one flat record: reaching m_commandAndMonitor through the Command base changes
// this part's schedule.
// src: HAVOK_SRC (member names)
struct TimerCommand_flat { const char* m_commandAndMonitor; unsigned int m_time0; unsigned int m_time1; };
// A unit-local view: this part of the unit reads the stream through TlsGetValue rather than hkThreadLocalData.
struct hkMonitorStream_tls : hkMonitorStream { static hkMonitorStream& getInstance(); };
__forceinline hkMonitorStream& hkMonitorStream_tls::getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0126835c); }

static const char s_kEndTimer[] = "Et";
static __forceinline void TimerMark(const char* name, volatile unsigned int& t)
{
    hkMonitorStream* s = &hkMonitorStream_tls::getInstance();
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        TimerCommand_flat* h = (TimerCommand_flat*)s->m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

extern "C" hkResult __cdecl hkCollideCapsuleUtilClostestPointCapsVsCaps(const CapsulePointVector* capsA, float capsARadius, const CapsulePointVector* capsB, float capsBRadius, float collisionTolerance, hkContactPoint& cpoint);

// Transforms two capsule endpoint pairs into world space, queries their contact point, and adds it to the collector on success.
// @fnv 0x00d3baf0
// src: HAVOK_SRC 0x00d3baf0
void __stdcall hkpCapsuleCapsuleAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, hkpCdPointCollector& collector)
{
    volatile unsigned int ticks;
    {
        hkMonitorStream* s = &hkMonitorStream_tls::getInstance();
        if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
        {
            TimerCommand_flat* h = (TimerCommand_flat*)s->m_end.m_storage;
            h->m_commandAndMonitor = "TtCapsCaps";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_time0 = ticks;
            s->m_end.m_storage = (char*)(h + 1);
        }
    }

    const hkpCapsuleShape* capsA = static_cast<const hkpCapsuleShape*>(bodyA.getShape());
    const hkpCapsuleShape* capsB = static_cast<const hkpCapsuleShape*>(bodyB.getShape());

    ContactPointPair event(bodyA, bodyB);
    CapsulePointVector capsAPoints[2];
    CapsulePointVector capsBPoints[2];
    CapsulePointTransforms::TransformPointArray(bodyA.getTransform(), (const CapsulePointVector*)capsA->GetIndexedVertices(), 2, &capsAPoints[0], capsBPoints[0]);

    CapsulePointTransforms::transformPoints2(bodyB.getTransform(), (const CapsulePointVector*)capsB->GetIndexedVertices(), 2, &capsBPoints[0]);

    hkResult result = hkCollideCapsuleUtilClostestPointCapsVsCaps(capsAPoints, capsA->getRadius(), capsBPoints, capsB->getRadius(), input.getTolerance(), event.m_kPoint);
    if (result == HK_SUCCESS)
    {
        collector.AddCdPoint(event);
    }

    {
        hkMonitorStream* s = &hkMonitorStream_tls::getInstance();
        if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
        {
            TimerCommand_flat* h = (TimerCommand_flat*)s->m_end.m_storage;
            h->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_time0 = ticks;
            s->m_end.m_storage = (char*)(h + 1);
        }
    }
}
