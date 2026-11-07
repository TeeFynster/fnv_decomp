#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpMultiRayShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpIterativeLinearCastAgent.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkRotation.h"
// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void hkpMultiRayConvexAgent_staticGetPenetrations(int a, int b, int c, int d);
struct FUN_00d37690_Class {
    void __thiscall ForwardToFunction(int a, int b, int c, int d);
};
void hkpMultiRayConvexAgent_createMultiRayConvexAgent(int a, int b, int c, int d);
void FUN_00d37780(int a, int b, int c, int d);
void Object_ProcessState_00d37860(int a, int b, int c, int d);
void Object_UpdateFields_00d378a0(int a, int b, int c, int d);
void hkpMultiRayConvexAgent_staticGetClosestPoints(int a, int b, int c, int d);
void Object_ProcessEntries_00daf8e0();
void Object_UpdateFields_00d3ac80();
struct FUN_00cfbbe0_Arg {
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    char f4;
    char f5;
};
struct FUN_00cfbbe0_Class {
    void __thiscall AppendRecordAndRegisterAgents(FUN_00cfbbe0_Arg* a, int b, int c);
};
void hkpMultiRayConvexAgent_registerAgent(int pClass);
struct Handler {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void process(unsigned short index, int argument);
};
struct Owner {
    virtual ~Owner();
    int unk04;
    Handler* handler;
    unsigned short* values;
    int count;
    void ProcessValuesAndDelete(int argument);
};
struct S_00d37860_Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    bool m_bHit;
    S_00d37860_Base() : m_bHit(false) {}
};
struct S_00d37860_Collector : S_00d37860_Base {
    int m_iFilter;
    S_00d37860_Collector(int filter) : m_iFilter(filter) {}
    virtual void f1();
};
void hkpMultiRayConvexAgent_staticGetPenetrations(void* b, void* a, void* c, S_00d37860_Collector* collector);
void Object_ProcessState_00d37860(void* a, void* b, void* c, int filter);
struct Payload { const char* name; float value; int id; };
extern float DAT_0104da48;
extern const char DAT_010ce7fc[];
void hkpMultiRayConvexAgent_staticGetClosestPoints(int, int, int, Payload*);
void Object_UpdateFields_00d378a0(int aiArg1, int aiArg2, int aiArg3, int aiId);
struct D376B0Allocator;
struct D376B0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D376B0Allocator* m_pStreamAllocator;

    D376B0Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" D376B0MemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(D376B0Allocator* alloc, void* array, int numElements, int sizeElem);
class D376B0ReferencedObject {
public:
    D376B0ReferencedObject() : m_sReferenceCount(1) {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
// hkInplaceArray<hkUint16, 4> without a destructor (Havok was built without EH).
struct D376B0IndexArray {
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned short m_kStorage[4];

    D376B0IndexArray() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000004) {}

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void SetSizeAndGrow(int n)
    {
        D376B0Allocator& alloc = hkMemoryRouter_getInstance().heap();
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(unsigned short));
        }
        m_iElementCount = n;
    }
};
class D376B0Filter : public D376B0ReferencedObject {
public:
    D376B0Filter(void* userData) : m_ulUserData(userData) {}

    void* m_ulUserData;
};
class FUN_00d376b0 : public D376B0Filter {
public:
    FUN_00d376b0(const hkpCdBody& shape, void* ReportDiagnostic, void* unused1, void* userData);
    virtual void unk00();

    D376B0IndexArray m_ppIndices;
};

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

typedef unsigned __w64 hk_size_t;
class hkClass;

inline hkTransform::hkTransform() {}
inline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x) {}
inline hkSimdReal::hkSimdReal(float x) { m_vValue = (_mm_load_ss)(&x); }
__forceinline __m128 hkSimdReal::broadcast() const { return (_mm_shuffle_ps)(m_vValue, m_vValue, 0); }
inline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getStart() { return m_start.val(); }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable() { return getEnd() < getCapacityMinus16(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
class hkStatisticsCollector;
#include "../../../../../../../include/hkArray.h"

typedef __m128 hkQuadReal;

typedef const hkVector4&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;
class hkMatrix3;
__forceinline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
extern const hkQuadReal DAT_010ec7f0;
hkQuadReal t=_t.broadcast();
hkQuadReal s=(_mm_sub_ps)(DAT_010ec7f0,t);
m_vComponents=(_mm_add_ps)(
(_mm_mul_ps)(s,v0.m_vComponents),
(_mm_mul_ps)(t,v1.m_vComponents));}
__forceinline void hkVector4::_setMul3(const hkRotation&a,const hkVector4&b)
{
const hkQuadReal b0=(_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=(_mm_mul_ps)(a.getColumn(0).m_vComponents,b0);
const hkQuadReal b1=(_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=(_mm_mul_ps)(a.getColumn(1).m_vComponents,b1);
const hkQuadReal b2=(_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=(_mm_mul_ps)(a.getColumn(2).m_vComponents,b2);
m_vComponents=(_mm_add_ps)((_mm_add_ps)(r0,r1),r2);}
__forceinline void hkVector4::_setRotatedDir(const hkRotation&r,const hkVector4&v)
{
_setMul3(r,v);
}
__forceinline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=(_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=(_mm_mul_ps)(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=(_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=(_mm_mul_ps)(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=(_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=(_mm_mul_ps)(r.getColumn(2).m_vComponents,b2);
m_vComponents=(_mm_add_ps)((_mm_add_ps)(r0,r1),(_mm_add_ps)(r2,t.getTranslation().m_vComponents));}
__forceinline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
__forceinline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline const hkVector4&hkRotation::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
__forceinline const hkVector4&hkTransform::getTranslation()const
{
return reinterpret_cast<const hkVector4&>(m_row3);
}
__forceinline const hkRotation&hkTransform::getRotation()const
{
return reinterpret_cast<const hkRotation&>(m_row0);
}

__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm {
rdtsc
mov dword ptr[ticks], eax
}
m_time0=ticks;
}
typedef hkUint16 hkContactPointId;
inline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline void hkContactPoint::setDistance(hkReal d)
{
m_vSeparatingNormal(3)=d;
}
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};

class hkAabb;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
__forceinline hkBool hkpShape::RayCast(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const
{
return IntersectRayWithShape(input,output);
}
struct RayCastHitResult
{
inline RayCastHitResult();
inline void reset();
hkVector4 m_vHitNormal;
hkReal m_fHitFraction;
int m_iExtraInfo;};
void RayCastHitResult::reset()
{
m_fHitFraction=1.0f;
m_iExtraInfo=-1;
}
RayCastHitResult::RayCastHitResult()
{
reset();
}
struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline ShapeRayCastOutput();
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};
void ShapeRayCastOutput::_reset()
{
m_uiShapeKeyIndex=0;
m_uiShapeKeys[0]=0xffffffff;
}
ShapeRayCastOutput::ShapeRayCastOutput()
{
_reset();
}
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
class hkpCollisionDispatcher;
class hkpConstraintOwner;
struct CollisionAgentContext;
struct GskAgentInput;
struct WorldOperationEntry;
struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};
class hkpCdBodyPairCollector;
class hkpContactMgr;
class hkpMultiRayConvexAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);

virtual void cleanup(hkpConstraintOwner&constraintOwner);
protected:
hkpMultiRayConvexAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createMultiRayConvexAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createConvexMultiRayAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
struct ContactPointIdEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpMultiRayConvexAgent::ContactPointIdEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkContactPointId m_usContactPointId;
};
hkInplaceArray<ContactPointIdEntry,4>m_kContactPointIds;
};

class hkpRayShapeCollectionFilter;
struct ShapeRayCastQuery
{
inline ShapeRayCastQuery();
hkVector4 m_vFrom;
hkVector4 m_vTo;
hkUint32 m_uiFilterInfo;
const hkpRayShapeCollectionFilter*m_pRayShapeCollectionFilter;};
inline ShapeRayCastQuery::ShapeRayCastQuery()
:m_uiFilterInfo(0),
m_pRayShapeCollectionFilter(0)
{
}
extern const char DAT_010ceda8[];
extern const char DAT_010c41f8[];

// @fnv 0x00d37280
// src: XBOX_PDB 0x00d37280
void __cdecl hkpMultiRayConvexAgent_staticGetClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor=DAT_010ceda8;h->setTime();mStream.setEnd((char*)(h+1));}};
const hkpMultiRayShape*msA=static_cast<const hkpMultiRayShape*>(bodyA.getShape());
const hkpConvexShape*convexB=static_cast<const hkpConvexShape*>(bodyB.getShape());
hkTransform bTa;bTa.SetMulInverse(bodyB.getTransform(),bodyA.getTransform());
const hkArray<hkpMultiRayShape::Ray>&RaysA=msA->getRays();
int nRays=RaysA.m_iElementCount;
const hkpMultiRayShape::Ray*rayA=RaysA.m_data;
ContactPointPair event(bodyA,bodyB);
ShapeRayCastQuery rayInput;
for(int i=0;i<nRays;i++)
{
ShapeRayCastOutput rayResults;
rayInput.m_vFrom._setTransformedPos(bTa,rayA->m_kRayStart);
rayInput.m_vTo._setTransformedPos(bTa,rayA->m_kRayEnd);
hkBool rayHit=convexB->RayCast(rayInput,rayResults);
if(rayHit)
{
const hkVector4&normal=rayResults.m_vHitNormal;
const hkReal dist=rayResults.m_fHitFraction;
hkVector4 hitpoint;hitpoint.setInterpolate4(rayInput.m_vFrom,rayInput.m_vTo,dist);
event.m_kPoint.getPosition()._setTransformedPos(bodyB.getTransform(),hitpoint);
event.m_kPoint.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(),normal);
event.m_kPoint.setDistance((dist-1.0f)*rayA->m_kRayStart(3)+msA->getRayPenetrationDistance());
collector.AddCdPoint(event);
}
rayA++;
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor=DAT_010c41f8;h->setTime();mStream.setEnd((char*)(h+1));}};
}
