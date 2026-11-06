// Keep this unit's original intrinsic representation: the CRT union also contains
// byte arrays, which make VC9 insert /GS checks into this function.
#define _INCLUDED_MM2
// Exe 0x00d3ebe0 m_pVirtualFunction2: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);

#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpCapsuleShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereCapsuleAgent.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkpSphereShape.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkThreadLocalData.h"

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

__forceinline hkVector4::hkVector4(LocalM128 value) : m_vComponents(value) {}
typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

typedef int hkBool32;





extern "C" {
extern LocalM128 _mm_sub_ss(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_mul_ss(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_rsqrt_ss(LocalM128 _A);
extern LocalM128 _mm_andnot_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_cmpeq_ss(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_set_ss(float _A);
extern LocalM128 _mm_setzero_ps(void);
extern LocalM128 _mm_load_ss(float const*_A);
}
typedef LocalM128 hkQuadReal;

typedef const hkVector4&hkVector4Parameter;

extern "C"{
double __cdecl fabs(double _X);
double __cdecl sqrt(double _X);__forceinline float fabsf(float _X)
{return((float)fabs((double)_X));}
__forceinline float sqrtf(float _X)
{return((float)sqrt((double)_X));}
}
namespace MathUtilities
{
__forceinline hkReal __cdecl sqrt(hkReal r){return::sqrtf(r);}
__forceinline hkReal __cdecl fabs(hkReal r){return::fabsf(r);}
}

__forceinline void hkVector4::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
__forceinline void setTransformedPos(hkVector4&out,const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
out.m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
__forceinline hkQuadReal dot3Quad(const hkVector4&v,const hkVector4&a)
{
hkQuadReal x2=_mm_mul_ps(v.m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);
}
__forceinline hkQuadReal lengthInverse3(const hkVector4&v)
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=dot3Quad(v,v);
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);
}
__forceinline void hkVector4::normalize3()
{
hkQuadReal lenInv=::lengthInverse3(*this);
lenInv=_mm_shuffle_ps(lenInv,lenInv,0);
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
__forceinline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
__forceinline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
__forceinline const hkVector4&hkRotation::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
__forceinline const hkVector4&hkTransform::getTranslation()const
{
return *reinterpret_cast<const hkVector4*>(&m_row3);
}
__forceinline const hkRotation&hkTransform::getRotation()const
{
return *reinterpret_cast<const hkRotation*>(&m_row0);
}
// The RTM transform copy loads each column as four scalar words.
__forceinline void copyVectorWords(hkQuadReal& dstVector,const hkVector4& srcVector)
{
unsigned int* dst=reinterpret_cast<unsigned int*>(&dstVector);
const unsigned int* src=reinterpret_cast<const unsigned int*>(&srcVector);
dst[0]=src[0];
dst[1]=src[1];
dst[2]=src[2];
dst[3]=src[3];
}
__forceinline hkTransform::hkTransform(const hkTransform&t)
{
hkQuadReal r0;copyVectorWords(r0,t.getRotation().getColumn(0));
hkQuadReal r1;copyVectorWords(r1,t.getRotation().getColumn(1));
hkQuadReal r2;copyVectorWords(r2,t.getRotation().getColumn(2));
hkQuadReal r3;copyVectorWords(r3,t.getRotation().getColumn(3));
m_row0=r0;
m_row1=r1;
m_row2=r2;
m_row3=r3;}


__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end=ptr; }
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
__forceinline const hkVector4&hkContactPoint::getNormal()const
{
return m_vSeparatingNormal;
}
__forceinline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
__forceinline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
__forceinline void hkContactPoint::setDistance(hkReal d)
{
m_vSeparatingNormal(3)=d;
}
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
class hkpCollisionDispatcher;
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
class hkpContactMgr;
struct WorldOperationEntry;
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





__forceinline const hkVector4*hkpCapsuleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}

namespace hkVector4Util_S
{
__forceinline void __cdecl calculatePerpendicularVector(const hkVector4&vectorIn,hkVector4&biVectorOut);
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}
__forceinline void __cdecl hkVector4Util_S::calculatePerpendicularVector(const hkVector4&vectorIn,hkVector4&biVectorOut)
{
int min=0;
int ok1=1;
int ok2=2;
hkReal a0=MathUtilities::fabs(vectorIn(0));
hkReal a1=MathUtilities::fabs(vectorIn(1));
hkReal a2=MathUtilities::fabs(vectorIn(2));
if(a1<a0)
{
ok1=0;
min=1;
a0=a1;
}
if(a2<a0)
{
ok2=min;
min=2;
}
biVectorOut.setZero4();
biVectorOut(ok1)=vectorIn(ok2);
biVectorOut(ok2)=-vectorIn(ok1);}
__forceinline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
setTransformedPos(vectorsOut[i],unaliased,vectorsIn[i]);
}while(--i>=0);}
class SegmentSegmentClosestPoint
{
public:
enum
{
CLSLS_POINTA_START=1,
CLSLS_POINTA_END=2,
CLSLS_POINTB_START=4,
CLSLS_POINTB_END=8
};
struct Vector4Wrapper
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(SegmentSegmentClosestPoint::Vector4Wrapper));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kClosestPoint;
};
static int __cdecl GetClosestPointOnLineSegment(hkVector4Parameter A,hkVector4Parameter B0,hkVector4Parameter B1,Vector4Wrapper&result);};
__forceinline hkpSphereCapsuleAgent::ClosestPointResult hkpSphereCapsuleAgent::getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
const hkpCapsuleShape*capsuleB=static_cast<const hkpCapsuleShape*>(bodyB.getShape());
const hkVector4&posA=bodyA.getTransform().getTranslation();
hkQuadReal capsBStorage[2];
hkVector4(&capsB)[2]=*reinterpret_cast<hkVector4(*)[2]>(capsBStorage);hkVector4Util_S::TransformPointArray(bodyB.getTransform(),capsuleB->GetIndexedVertices(),2,capsB);
hkQuadReal resultStorage;
SegmentSegmentClosestPoint::Vector4Wrapper&result=*reinterpret_cast<SegmentSegmentClosestPoint::Vector4Wrapper*>(&resultStorage);SegmentSegmentClosestPoint::GetClosestPointOnLineSegment(posA,capsB[0],capsB[1],result);
hkVector4 aMinusB(_mm_setzero_ps());aMinusB.setSub4(posA,result.m_kClosestPoint);
const hkReal radiusSum=sphereA->getRadius()+capsuleB->getRadius();
const hkReal refDist=radiusSum+input.getTolerance();
hkReal distSquared;
_mm_store_ss(&distSquared,dot3Quad(aMinusB,aMinusB));
if(distSquared>=refDist*refDist)
{
return ST_CP_MISS;
}
hkReal dist;
if(distSquared>0.0f)
{
dist=MathUtilities::sqrt(distSquared);
cpoint.getSeparatingNormal().m_vComponents=aMinusB.m_vComponents;
}
else
{
dist=0.0f;
hkVector4 edge(_mm_setzero_ps());edge.m_vComponents=_mm_sub_ps(capsBStorage[1],capsBStorage[0]);
hkVector4Util_S::calculatePerpendicularVector(edge,cpoint.getSeparatingNormal());
}
cpoint.getSeparatingNormal().normalize3();
hkQuadReal radiusMinusDist;
hkReal radiusDifference=capsuleB->getRadius()-dist;
radiusMinusDist=_mm_load_ss(&radiusDifference);
cpoint.getPosition().m_vComponents=_mm_add_ps(posA.m_vComponents,
_mm_mul_ps(_mm_shuffle_ps(radiusMinusDist,radiusMinusDist,0),cpoint.getNormal().m_vComponents));
cpoint.setDistance(dist-radiusSum);
return ST_CP_HIT;}
// @fnv 0x00d3ebe0
void __cdecl hkpSphereCapsuleAgent::m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.getEnd()<mStream.getCapacityMinus16()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "SphereCapsule";h->setTime();mStream.setEnd((char*)(h+1));}};
// Leave output vectors uninitialized without relying on out-of-line constructors.
hkQuadReal eventStorage[sizeof(ContactPointPair)/sizeof(hkQuadReal)];
ContactPointPair&event=*reinterpret_cast<ContactPointPair*>(eventStorage);
const hkpCdBody**bodyRefs=reinterpret_cast<const hkpCdBody**>(eventStorage+sizeof(hkContactPoint)/sizeof(hkQuadReal));
bodyRefs[0]=&bodyA;
bodyRefs[1]=&bodyB;
if(getClosestPointInl(bodyA,bodyB,input,event.m_kPoint))
{
collector.AddCdPoint(event);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.getEnd()<mStream.getCapacityMinus16()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
