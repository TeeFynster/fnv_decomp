// GSK closest-point implementation, compiled with VC9 RTM.
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpGskStatus.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4_S.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkpTriangleShape.h"

// The shared agent requires this complete cache type; include/ only forward-declares it.
class ConvexFeaturePairCache
{
public:
unsigned short m_kVertices[4];
unsigned char m_ucDimensionA;
unsigned char m_ucDimensionB;
unsigned char m_ucFeatureTypeA:4;
unsigned char m_ucFeatureTypeB:4;
void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform&btoa);
void InitForTriangle(const hkpConvexShape*shapeA,const hkpTriangleShape*shapeB,const hkTransform&btoa);
};
#include "../../../../../../../include/hkpGskBaseAgent.h"

#include <windows.h>

inline hkSimdReal::hkSimdReal() {}
inline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
static __forceinline hkSimdReal makeScalar(float x)
{
    hkSimdReal value;
    value.m_vValue = _mm_load_ss(&x);
    return value;
}
inline hkTransform::hkTransform() {}
inline const hkRotation& hkTransform::getRotation() const
{
    return reinterpret_cast<const hkRotation&>(m_row0);
}
inline const hkTransform& hkpCdBody::getTransform() const
{
    return *static_cast<const hkTransform*>(m_pMotionState);
}
inline const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}
inline hkpShapeType hkpShape::getType() const
{
    return static_cast<hkpShapeType>(*reinterpret_cast<const hkUint32*>(&m_type));
}
inline char* hkMonitorStream::getEnd() { return m_end.val(); }
inline char* hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
inline hkBool hkMonitorStream::memoryAvailable() { return getEnd() < getCapacityMinus16(); }
inline void hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
inline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern unsigned long g_pMonitorStream;
    return *static_cast<hkMonitorStream*>(TlsGetValue(g_pMonitorStream));
}
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}
// Use the virtual dispatch slots declared by the shared convex shape.
inline void hkpConvexShape::GetVerticesForIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* vertices) const
{
    GetVerticesFromIds(ids, numIds, vertices);
}
inline hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(
    hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
    hkVector4_S& contactPointWs, const hkTransform* thisObjTransform,
    const hkpConvexShape* collidingShape, const hkTransform* collidingTransform,
    hkVector4_S& separatingNormalInOut) const
{
    return static_cast<WeldResult>(WeldContactPoint(
        featurePoints, numFeaturePoints, reinterpret_cast<hkVector4&>(contactPointWs),
        thisObjTransform, collidingShape, collidingTransform,
        reinterpret_cast<hkVector4&>(separatingNormalInOut)));
}

typedef unsigned short hkUint16;
typedef int hkBool32;
typedef __m128 hkQuadReal;
typedef const hkSimdReal&hkSimdRealParameter;
inline hkVector4_S::operator hkQuadReal()const
{
return m_vComponents;
}
__forceinline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
__forceinline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4_S::addMul4(hkSimdRealParameter r,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
__forceinline void hkVector4_S::setAddMul4(const hkVector4_S&a,const hkVector4_S&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
__forceinline void hkVector4_S::_setRotatedInverseDir(const hkRotation&r,const hkVector4_S&b)
{
hkQuadReal c0=r.getColumn(0).m_vComponents;
hkQuadReal c1=r.getColumn(1).m_vComponents;
hkQuadReal c2=r.getColumn(2).m_vComponents;
{hkQuadReal _tmp,_ctmp;_tmp=_mm_unpacklo_ps(c0,c1);_ctmp=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,(((3)<<6)|((2)<<4)|((1)<<2)|((0))));c0=_mm_movelh_ps(_tmp,c2);c1=_mm_shuffle_ps(_mm_movehl_ps(c0,_tmp),c2,(((3)<<6)|((1)<<4)|((1)<<2)|((0))));c2=_ctmp;};
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(c0,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(c1,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(c2,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
__forceinline void hkVector4_S::_setTransformedPos(const hkTransform&t,const hkVector4_S&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.m_row3));}
__forceinline void hkVector4_S::_setTransformedInversePos(const hkTransform&a,const hkVector4_S&b)
{
hkVector4_S t0;t0.setSub4(b,reinterpret_cast<const hkVector4_S&>(a.m_row3));
_setRotatedInverseDir(a.getRotation(),t0);
}
__forceinline hkReal&hkVector4_S::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
__forceinline const hkVector4&hkRotation::getColumn(int x)const
{
return(&m_kColumn0)[x];
}

inline hkVector4& hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline void hkContactPoint::setSeparatingNormal(const hkVector4&normal,hkReal dist)
{
m_vSeparatingNormal=normal;
m_vSeparatingNormal.m_f[3]=dist;
}
class Vector4WithInt24W:public hkVector4_S {};

class hkpCollisionDispatcher;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;};
struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};

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
struct VectorPairResult
{
hkVector4_S m_kFirstVector;
hkVector4_S m_kClosestPointOnSecond;
hkPadSpu<hkReal>m_fValue;
};};
struct ShapePairDistanceData
{
hkVector4_S m_vPointOnShapeA;
hkVector4_S m_vPointOnShapeB;
hkPadSpu<hkReal>m_fClosestPointDistanceSquared;
};
struct GskAgentData:public ShapePairDistanceData
{
hkVector4_S m_kLeadingVector;
hkVector4_S m_kSecondVector;
};
class ConvexShapePairCache
{
public:

ConvexShapePairCache():m_uiCacheFlags(0){}
__forceinline void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const ConvexFeaturePairCache&cache);
hkpGskStatus GetClosestPoint(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform&aTb,hkVector4_S&separatingNormalOut);
void GetClosestPointBinB(const hkVector4_S&separatingNormal,ShapePairDistanceData&out);
__forceinline void checkForChangesAndUpdateCache(ConvexFeaturePairCache&cache)const;
void WriteContactFeatureCache(ConvexFeaturePairCache&cache)const;
protected:
__forceinline void setFeatureChange(int f){m_iFeatureChange=f;}
public:
hkPadSpu<int>m_ucDimensionA;
hkPadSpu<int>m_ucDimensionB;
hkPadSpu<int>m_ucFeatureTypeA;
hkPadSpu<int>m_ucFeatureTypeB;
hkPadSpu<hkUint32>m_uiCacheFlags;
hkPadSpu<int>m_iFeatureChange;
Vector4WithInt24W m_akPackedVerticesA[4];
hkVector4_S unk60;hkVector4_S unk70;hkVector4_S unk80;hkVector4_S unk90;
hkVector4_S m_akCachedVectors[4];
Vector4WithInt24W m_akPackedVerticesB[4];
hkVector4_S m_pSupport;
SegmentSegmentClosestPoint::VectorPairResult m_kVectorPairResult;
hkVector4_S m_pCachedPoint;
hkPadSpu<int>m_iCacheState;};
__forceinline void ConvexShapePairCache::init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const ConvexFeaturePairCache&cache)
{
m_ucDimensionA=cache.m_ucDimensionA;
m_ucDimensionB=cache.m_ucDimensionB;
m_ucFeatureTypeA=cache.m_ucFeatureTypeA;
m_ucFeatureTypeB=cache.m_ucFeatureTypeB;
setFeatureChange(0);
shapeA->GetVerticesForIds(&cache.m_kVertices[0],m_ucDimensionA,&m_akPackedVerticesA[0]);
shapeB->GetVerticesForIds(&cache.m_kVertices[m_ucDimensionA],m_ucDimensionB,&m_akPackedVerticesB[0]);}
__forceinline void ConvexShapePairCache::checkForChangesAndUpdateCache(ConvexFeaturePairCache&cache)const
{
if(!m_iFeatureChange)
{
return;
}
WriteContactFeatureCache(cache);
}
__forceinline hkBool __cdecl hkpGskBaseAgent::staticGetClosestPoint(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&aTb,const CollisionAgentContext&input,ConvexFeaturePairCache&cache,struct GskAgentData&output)
{
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(bodyA.getShape());
const hkpConvexShape*shapeB=static_cast<const hkpConvexShape*>(bodyB.getShape());
{
hkVector4_S separatingNormal;
ConvexShapePairCache gsk;
gsk.init(shapeA,shapeB,cache);
const hkpGskStatus gskStatus=gsk.GetClosestPoint(shapeA,shapeB,aTb,separatingNormal);
if(gskStatus==HK_GSK_OK)
{
gsk.GetClosestPointBinB(separatingNormal,output);
output.m_kSecondVector._setRotatedDir(bodyA.getTransform().getRotation(),output.m_vPointOnShapeA);
const hkReal dist=output.m_fClosestPointDistanceSquared-shapeA->getRadius()-shapeB->getRadius();
output.m_fClosestPointDistanceSquared=dist;
if(output.m_fClosestPointDistanceSquared<input.getTolerance())
{
output.m_vPointOnShapeB.addMul4(makeScalar(-shapeA->getRadius()),output.m_vPointOnShapeA);
hkVector4_S pointBinA;pointBinA.setAddMul4(output.m_vPointOnShapeB,output.m_vPointOnShapeA,makeScalar(-dist));
output.m_kLeadingVector._setTransformedInversePos(aTb,pointBinA);
if(shapeB->getType()==HK_SHAPE_TRIANGLE&&input.m_collisionQuality.val())
{
gsk.checkForChangesAndUpdateCache(cache);
hkVector4_S weldedNormal=output.m_kSecondVector;
hkpConvexShape::WeldResult weldResult=shapeB->weldContactPoint(&cache.m_kVertices[cache.m_ucDimensionA],cache.m_ucDimensionB,output.m_kLeadingVector,&bodyB.getTransform(),shapeA,&bodyA.getTransform(),weldedNormal);
if(weldResult==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
return false;
}
else if(weldResult==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
output.m_kSecondVector=weldedNormal;
}
}
return true;
}
}
}
return false;}
// @fnv 0x00dac450
void __cdecl hkpGskBaseAgent::m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "Gsk";h->setTime();mStream.setEnd((char*)(h+1));}};
GskAgentData output;
ConvexFeaturePairCache cache;
hkTransform aTb;
{
const hkpConvexShape*sA=static_cast<const hkpConvexShape*>(bodyA.getShape());
const hkpConvexShape*sB=static_cast<const hkpConvexShape*>(bodyB.getShape());
aTb.SetMulInverse(bodyA.getTransform(),bodyB.getTransform());
if(sB->getType()==HK_SHAPE_TRIANGLE)
{
cache.InitForTriangle(sA,static_cast<const hkpTriangleShape*>(sB),aTb);
}
else
{
cache.init(sA,sB,aTb);
}
}
if(staticGetClosestPoint(bodyA,bodyB,aTb,input,cache,output))
{
ContactPointPair event(bodyA,bodyB);
reinterpret_cast<hkVector4_S&>(event.m_kPoint.getPosition())._setTransformedPos(bodyB.getTransform(),output.m_kLeadingVector);
event.m_kPoint.setSeparatingNormal(reinterpret_cast<const hkVector4&>(output.m_kSecondVector),output.m_fClosestPointDistanceSquared);
collector.AddCdPoint(event);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
