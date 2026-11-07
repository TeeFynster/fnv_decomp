#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpCapsuleShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereCapsuleAgent.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkpSphereShape.h"

#include <math.h>
#include <string.h>
#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier();
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
struct Arg2S { float unk00, unk04, f8; };
static __forceinline bool compareValue(float a,float b) { return b>=a; }
static __forceinline void perpendicular(hkVector4& dst, hkVector4& d) {
        int low=0, side=1; volatile int third=2; int pick;
        float best=fabsf(d.x), ay=fabsf(d.y), az=fabsf(d.z);
        if(ay<best) {side=0;low=1;best=ay;}
        if(az<best) pick=low; else pick=third;
        dst.m_vComponents=_mm_setzero_ps();
        dst(side)=d(pick);
        dst(pick)=-d(side);
}
static __forceinline float rootVal(float x){return sqrtf(x);}
static __forceinline void difference(hkVector4& dst, const hkVector4& a, const hkVector4& b){ dst.m_vComponents=_mm_sub_ps(*(__m128*)&a,*(__m128*)&b); }
// @fnv 0x00d3e530
// src: XBOX_PDB 0x00d3e530
int __cdecl hkpSphereCapsuleAgent_getClosestPoint(hkpCdBody* a0, hkpCdBody* a1, Arg2S* a2, hkContactPoint* out) {
    
    const hkVector4* qp = static_cast<const hkVector4*>(a0->m_pMotionState) + 3;
    const hkpCapsuleShape* bp = static_cast<const hkpCapsuleShape*>(a1->m_pCollisionShape);
    const hkpSphereShape* ap = static_cast<const hkpSphereShape*>(a0->m_pCollisionShape);
    hkVector4 vc0 = reinterpret_cast<const hkVector4*>(a1->m_pMotionState)[0];
    hkVector4 vc1 = reinterpret_cast<const hkVector4*>(a1->m_pMotionState)[1];
    hkVector4 vc2 = reinterpret_cast<const hkVector4*>(a1->m_pMotionState)[2];
    hkVector4 vc3 = reinterpret_cast<const hkVector4*>(a1->m_pMotionState)[3];
    __m128 c0 = *(__m128*)&vc0;
    __m128 c1 = *(__m128*)&vc1;
    __m128 c2 = *(__m128*)&vc2;
    __m128 c3 = *(__m128*)&vc3;
    const hkVector4* inp = &bp->m_kVertexA;
    hkVector4 t[2];
    for (int i = 1; i >= 0; i--) {
        __m128 v = _mm_load_ps((float*)&inp[i]);
        __m128 r = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1),
                                         _mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0)),
                              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2), c3));
        _mm_store_ps((float*)&t[i], r);
    }
    hkVector4 res;
    hkpCapsuleShape::GetClosestPointOnLineSegment(*qp, t[0], t[1], res);
    hkVector4 diff;
    _mm_store_ps((float*)&diff, _mm_sub_ps(_mm_load_ps((float*)qp), _mm_load_ps((float*)&res)));
    float sum1 = ap->m_fSphereRadius + bp->m_fSphereRadius;
    float S = a2->f8 + sum1;
    __m128 sq = _mm_mul_ps(_mm_load_ps((float*)&diff), _mm_load_ps((float*)&diff));
    __m128 s1 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 s2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s1);
    float lenSq;
    _mm_store_ss(&lenSq, s2);
if (compareValue(S*S,lenSq)) return 0;
    float D;
    if (lenSq > 0.0f) {
        D = sqrtf(lenSq);
        out->m_vSeparatingNormal.m_vComponents = *(__m128*)&diff;
    } else {
        D = 0.0f;
        hkVector4 d;
        difference(d,t[1],t[0]);
        perpendicular(out->m_vSeparatingNormal,d);
    }
    __m128 n = out->m_vSeparatingNormal.m_vComponents;
    __m128 nsq = _mm_mul_ps(n, n);
    __m128 nsum = _mm_add_ss(_mm_shuffle_ps(nsq, nsq, 0xaa), _mm_add_ss(_mm_shuffle_ps(nsq, nsq, 0x55), nsq));
    __m128 r = _mm_rsqrt_ss(nsum);
    __m128 factor = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r),
                               _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(nsum, r), r)));
    factor = _mm_andnot_ps(_mm_cmpeq_ss(nsum, _mm_set_ss(DAT_01011d78)), factor);
    __m128 fn = _mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), n);
    out->m_vSeparatingNormal.m_vComponents = fn;
    _ReadWriteBarrier();
    float t1 = bp->m_fSphereRadius - D;
    __m128 pos = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&t1), _mm_load_ss(&t1), 0), _mm_load_ps((float*)&out->m_vSeparatingNormal)), _mm_load_ps((float*)qp));
    _mm_store_ps((float*)&out->m_vContactPosition,pos);
    out->m_vSeparatingNormal.w = D - sum1;
    return 1;
}

typedef unsigned short hkUint16;
typedef int hkBool32;
#include "../../../../../../../include/hkResult.h"
typedef unsigned __w64 hk_size_t;
typedef __m128 hkQuadReal;
typedef const hkSimdReal& hkSimdRealParameter;
inline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
    unsigned int ticks;
    __asm { rdtsc
        mov dword ptr[ticks],eax }
    m_time0 = ticks;
}
inline hkSimdReal::hkSimdReal(const hkQuadReal& x) : m_vValue(x) {}
inline hkSimdReal::hkSimdReal(hkReal x) { m_vValue = _mm_load_ss(&x); }
inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline __m128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
__forceinline const __m128& hkSimdReal::getQuad() const { return m_vValue; }
__forceinline hkVector4::hkVector4(const hkVector4& v) { memcpy(this, &v, sizeof(*this)); }
namespace MathUtilities
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}
__forceinline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
__forceinline void hkVector4::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
__forceinline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
static __forceinline void setTransformedPos(hkVector4& out,const hkTransform&t,const hkVector4&b)
{

hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(t.m_row0,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(t.m_row1,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(t.m_row2,b2);
out.m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.m_row3));}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
hkSimdReal result; result.m_vValue=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum); return result;}
__forceinline hkSimdReal hkVector4::lengthSquared3()const
{
return this->dot3(*this);
}
static __forceinline hkSimdReal lengthInverse3(const hkVector4& v)
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=v.dot3(v).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
hkSimdReal result; result.m_vValue=_mm_andnot_ps(len2EqualsZero,refined); return result;}
__forceinline void hkVector4::normalize3()
{
hkQuadReal lenInv=lengthInverse3(*this).broadcast();
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

inline hkSimdReal::hkSimdReal() {}
inline const hkVector4& hkTransform::getTranslation() const { return reinterpret_cast<const hkVector4&>(m_row3); }
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0=reinterpret_cast<const hkVector4&>(t.m_row0);
    const hkVector4 r1=reinterpret_cast<const hkVector4&>(t.m_row1);
    const hkVector4 r2=reinterpret_cast<const hkVector4&>(t.m_row2);
    const hkVector4 r3=reinterpret_cast<const hkVector4&>(t.m_row3);
    m_row0=*reinterpret_cast<const __m128*>(&r0);
    m_row1=*reinterpret_cast<const __m128*>(&r1);
    m_row2=*reinterpret_cast<const __m128*>(&r2);
    m_row3=*reinterpret_cast<const __m128*>(&r3);
}
__forceinline const hkTransform& hkpCdBody::getTransform() const { return *static_cast<const hkTransform*>(m_pMotionState); }
__forceinline const hkpShape* hkpCdBody::getShape() const { return m_pCollisionShape; }
inline const hkVector4* hkpCapsuleShape::GetIndexedVertices() const { return &m_kVertexA; }
inline const hkVector4&hkContactPoint::getNormal()const
{
return m_vSeparatingNormal;
}
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
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;};
hkContactPointId hkpContactMgr::addContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)
{
return CreateContactPoint(a,b,input,output,contactCache,cp);
}
void hkpContactMgr::removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)
{
removeContactPointImpl(cpId,constraintOwner);
}
struct ContactPointWithId
{
hkContactPoint m_kPoint;
hkPadSpu<hkUint32>m_usContactPointId;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};enum{HK_MAX_CONTACT_POINT=256};
struct FourByteState;
struct CollisionContactResults
{
public:

public:
hkPadSpu<ContactPointWithId*>m_pAlignedPairData;
hkPadSpu<hkpConstraintOwner*>m_pConstraintOwner;};
struct WorldOperationEntry:public CollisionContactResults
{
public:
inline ContactPointWithId*reserveContactPoints(int numberOfPoints=1)
{
return m_pAlignedPairData;
}
inline void commitContactPoints(int numberOfPoints=1)
{
m_pAlignedPairData=m_pAlignedPairData+numberOfPoints;
;
}
inline void abortContactPoints(int numberOfPoints=1)
{
}
public:
struct ContactPointAgentEntry
{
__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ContactPointWithId*m_vContactPoint;
FourByteState*m_pAgentEntry;
void*m_pUserData;
};
struct ContactPointBuffer
{
__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
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
hkPadSpu<ContactPointBuffer*>m_akContactRecords;};namespace hkVector4Util_S
{
__forceinline void __cdecl calculatePerpendicularVector(const hkVector4&vectorIn,hkVector4&biVectorOut);
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}
inline void __cdecl hkVector4Util_S::calculatePerpendicularVector(const hkVector4&vectorIn,hkVector4&biVectorOut)
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
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
setTransformedPos(vectorsOut[i],unaliased,vectorsIn[i]);
}while(--i>=0);}
__forceinline hkpSphereCapsuleAgent::ClosestPointResult hkpSphereCapsuleAgent::getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
const hkpCapsuleShape*capsuleB=static_cast<const hkpCapsuleShape*>(bodyB.getShape());
const hkVector4&posA=bodyA.getTransform().getTranslation();
hkVector4 capsB[2];hkVector4Util_S::TransformPointArray(bodyB.getTransform(),capsuleB->GetIndexedVertices(),2,capsB);
hkVector4 result;hkpCapsuleShape::GetClosestPointOnLineSegment(posA,capsB[0],capsB[1],result);
hkVector4 aMinusB;aMinusB.setSub4(posA,result);
const hkReal radiusSum=sphereA->getRadius()+capsuleB->getRadius();
const hkReal refDist=radiusSum+input.getTolerance();
hkReal distSquared=aMinusB.lengthSquared3();
if(distSquared>=refDist*refDist)
{
return ST_CP_MISS;
}
hkReal dist;
if(distSquared>0.0f)
{
dist=MathUtilities::sqrt(distSquared);
cpoint.getSeparatingNormal()=aMinusB;
}
else
{
dist=0.0f;
hkVector4 edge;edge.setSub4(capsB[1],capsB[0]);
hkVector4Util_S::calculatePerpendicularVector(edge,cpoint.getSeparatingNormal());
}
cpoint.getSeparatingNormal().normalize3();
hkSimdReal radiusOffset;
float offset=capsuleB->getRadius()-dist; radiusOffset.m_vValue=_mm_load_ss(&offset);
cpoint.getPosition().setAddMul4(posA,cpoint.getNormal(),radiusOffset);
cpoint.setDistance(dist-radiusSum);
return ST_CP_HIT;}
// @fnv 0x00d3f080
void hkpSphereCapsuleAgent::ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result)
{
;
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.m_end.val()<mStream.m_capacityMinus16.val()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "SphereCapsule";h->setTime();mStream.setEnd((char*)(h+1));}};
ContactPointWithId*point=result.reserveContactPoints(1);
if(getClosestPointInl(bodyA,bodyB,input,point->m_kPoint))
{
if(m_usContactPointId==(0xffff))
{
m_usContactPointId=m_pContactManager->addContactPoint(bodyA,bodyB,input,result,0,point->m_kPoint);
}
if(m_usContactPointId !=(0xffff))
{
point->m_usContactPointId=m_usContactPointId;
result.commitContactPoints(1);
}
else
{
result.abortContactPoints(1);
}
}
else
{
result.abortContactPoints(1);
if(m_usContactPointId !=(0xffff))
{
m_pContactManager->removeContactPoint(m_usContactPointId,*result.m_pConstraintOwner.val());
m_usContactPointId=(0xffff);
}
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.m_end.val()<mStream.m_capacityMinus16.val()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
